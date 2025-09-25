/* Copyright 2021-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "ble_controller.h"
#include "fsl_device_registers.h"
#include "fsl_common.h"
#include "fsl_clock.h"
#include "fsl_power.h"
#include "fsl_system.h"
#include "event_manager.h"
#include "hci.h"
#include "ll_intf.h"
#include "hci_transport.h"
#include "ble_controller_lowlevel.h"
#include "os_wrapper.h"

#ifdef DUMP_HCI
#include "fsl_usart.h"
#endif /* DUMP_HCI */
#if defined(DEBUG_HCI)
#include "fsl_debug_console.h"
#endif

#ifdef DUMP_HCI
#define DUMP_UART       USART2
#define DUMP_UART_CLK   kFRO12M_to_FLEXCOMM2
#define DUMP_UART_RESET kFC2_RST_SHIFT_RSTn
#endif /* DUMP_HCI */

static blecHostHciRecvCallback_t blecHostHciRecvCallback = NULL;

/**
 * The maximum number of HCI commands coming from the host that are
 * buffered by the BLE controller. This is needed as the host stack
 * does not implement HCI flow control.
 */
#ifndef MAX_HCI_COMMANDS
#define MAX_HCI_COMMANDS 6
#endif /* MAX_HCI_COMMANDS */

DEF_HCI_CMD_BUFFER_MEM(cmdBufferPoolRaw, MAX_HCI_COMMANDS);

/* variables needed by applications*/
void (*pfBLE_SignalFromISR)(void) = NULL;

/* Prints are disabled unless DEBUG is enabled */
#ifdef DEBUG_HCI
#define debug_hci_printf PRINTF
#else
#define debug_hci_printf(...) \
    do                        \
    {                         \
    } while (0)
#endif /* DEBUG_HCI */

static void Mem_Copy_Per_Byte(uint8_t *dst, uint8_t *src, uint32_t size)
{
	for (uint32_t i = 0; i < size; i++)
	{
		dst[i] = src[i];
	}
}

#ifdef DEBUG_HCI
#define DEFERRED_PRINTF_BUFFER_SIZE_BITS 3
#define DEFERRED_PRINT_BUFFER_SIZE (1 << DEFERRED_PRINTF_BUFFER_SIZE_BITS)

#define MAX_LL_TO_H_HCI_PACKET_SIZE 256
typedef struct
{
    ble_buff_hdr_t ble_buff_hdr;
    uint8_t data[MAX_LL_TO_H_HCI_PACKET_SIZE];
} ble_ll_packet_buffer_t;

static ble_ll_packet_buffer_t s_deferredRingBuffer[DEFERRED_PRINT_BUFFER_SIZE];
static uint8_t s_readIdx;
static uint8_t s_writeIdx;
static uint16_t s_missedHciBuffers;

static void PrintHciLinkLayerToHost(const ble_buff_hdr_t *ptr_evnt_hdr, uint8_t deferred)
{
    debug_hci_printf("\t%s HCI L->H[%x %x %x]", deferred ? "D":"", ptr_evnt_hdr->data_size, ptr_evnt_hdr->buff_start, ptr_evnt_hdr->ble_hdr_flags);
    for (int i = 0; i < ptr_evnt_hdr->data_size; i++)
    {
        debug_hci_printf(" %x", ptr_evnt_hdr->buff_start[i]);
    }
    debug_hci_printf("\n");
}

static bool AddDeferredHciBuf(ble_buff_hdr_t *buf)
{
    if ((uint8_t)(s_writeIdx - s_readIdx) > (DEFERRED_PRINT_BUFFER_SIZE - 1))
    {
        return false;
    }

    if (buf->data_size > MAX_LL_TO_H_HCI_PACKET_SIZE)
    {
        return false;
    }

    ble_ll_packet_buffer_t *deferred_buffer_entry = &s_deferredRingBuffer[s_writeIdx & (DEFERRED_PRINT_BUFFER_SIZE - 1)];
    memcpy(&deferred_buffer_entry->ble_buff_hdr, buf, sizeof(buf[0]));
    /*
     * buff_start can be in ble shared memory which has special alignment requirements.
     * memcpy can cause an alignment fault
     */
    Mem_Copy_Per_Byte(deferred_buffer_entry->data, buf->buff_start, buf->data_size);
    deferred_buffer_entry->ble_buff_hdr.buff_start = deferred_buffer_entry->data;
    s_writeIdx++;
    return true;
}

static void PrintDeferredHciBufs()
{
    if (s_readIdx == s_writeIdx)
    {
        return;
    }

    if (s_missedHciBuffers > 0)
    {
        debug_hci_printf("D HCI L->H: Missed:%u\n", s_missedHciBuffers);
        s_missedHciBuffers = 0;
    }

    while (s_readIdx != s_writeIdx)
    {
        ble_ll_packet_buffer_t *deferred_buffer_entry = &s_deferredRingBuffer[s_readIdx & (DEFERRED_PRINT_BUFFER_SIZE - 1)];
        PrintHciLinkLayerToHost(&deferred_buffer_entry->ble_buff_hdr, 1);
        s_readIdx++;
    }
}

static inline uint8_t IsInterrupt()
{
    return __get_IPSR();
}
#endif

static void Hci_transport_send_packet(ble_buff_hdr_t *ptr_evnt_hdr)
{
#if (USE_HCI_TRANSPORT)
    if (hci_transport_initialized())
    {
        hci_transport_send_pckt(ptr_evnt_hdr);
        return;
    }
#endif

    if (ptr_evnt_hdr == NULL)
    {
        /* Called by HCI Reset. Perform reset sequence.
           Don't move this code above!: hci_transport_send_pckt needs to handle this condition.*/
#ifdef DEBUG_HCI
        PrintDeferredHciBufs(); /* make sure pending HCI buffers are printed out and freed*/
#endif
        debug_hci_printf("\n ptr_evnt_hdr == NULL. HCI Reset?\n");
        return;
    }

    if (blecHostHciRecvCallback == NULL)
    {
        return;
    }

    blec_hciPacketType_t packetType = kBLEC_HciCommandPacket;
    /* Calback coming from SNPS LL to send HCI packet to BLE host */

    /* Parse packet type */
    if (ptr_evnt_hdr->ble_hdr_flags == BLE_BUFF_HDR_EVNT_CMD_PCKT)
    {
        packetType = kBLEC_HciEventPacket;
        /* Is the received event a command_complete or command_status event? */
    }
    else if (ptr_evnt_hdr->ble_hdr_flags == BLE_BUFF_HDR_ACL_DATA_PCKT)
    {
        packetType = kBLEC_HciDataPacket;
    }
#if 0 /* Not enabled in SNPS LL for now*/
    else if(ptr_evnt_hdr->ble_hdr_flags == BLE_BUFF_HDR_ISO_DATA_PCKT_BIT0)
    {
        packetType = gHciSynchronousDataPacket_c;
    }
#endif
    else
    {
        debug_hci_printf("ERROR: unsupported hciPacketType_t %x\n", ptr_evnt_hdr->ble_hdr_flags);
        assert(FALSE);
        ll_intf_free_ll_pkt_hndlr(ptr_evnt_hdr);
        return;
    }

#ifdef DUMP_HCI
    USART_WriteBlocking(DUMP_UART, (uint8_t *)(&packetType), 1);
    USART_WriteBlocking(DUMP_UART, (uint8_t *)(ptr_evnt_hdr->buff_start), ptr_evnt_hdr->data_size);
#endif /* DUMP_HCI */

#ifdef DEBUG_HCI
    bool printingDeferred = false;
    if (IsInterrupt())
    {
        printingDeferred = AddDeferredHciBuf(ptr_evnt_hdr);
        if (!printingDeferred)
        {
            s_missedHciBuffers++;
        }
    }
    else
    {
        /* First print deferred logs, to guarantee right logging order. */
        PrintDeferredHciBufs();
        PrintHciLinkLayerToHost(ptr_evnt_hdr, 0);
    }
#endif

    blec_result_t result = blecHostHciRecvCallback(packetType, ptr_evnt_hdr->buff_start + ptr_evnt_hdr->data_offset,
                                        ptr_evnt_hdr->data_size);

    if (result != kBLEC_Success) {
        /* The host stack reports error kBLEC_InvalidParameter each time a malformed HCI event is received.
         * Invalid parameters may be the result of malformed air packets (e.g.  Sweyntooth).
         * Handle these errors gracefully. */
        if (result != kBLEC_InvalidParameter) {
#ifdef DEBUG_HCI
            debug_hci_printf("deferred buffer dump:\n");
            PrintDeferredHciBufs();
#endif
            assert_equal(kBLEC_Success, result);
        }
    }

    ll_intf_free_ll_pkt_hndlr(ptr_evnt_hdr);
}

blec_result_t BLEController_ProcessHciPacket(blec_hciPacketType_t packetType, void *pPacket, uint16_t packetSize)
{
    blec_result_t ret = kBLEC_Success;
#ifdef DEBUG_HCI
    PrintDeferredHciBufs();
#endif
    debug_hci_printf("\tHCI H->L[%x %x %x]", packetSize, pPacket, packetType);

    for (int i = 0; i < packetSize; i++)
    {
        debug_hci_printf(" %x", ((uint8_t *)pPacket)[i]);
    }
    debug_hci_printf("\n");

    /* It is advised in section 8.2.2.1 of SNPS SW UM to use event manager to send packets to LL */

    /*allocate hci message*/
    ble_buff_hdr_t *ptr_host_event = (ble_buff_hdr_t *)hci_alloc_msg();
    if (ptr_host_event == NULL)
    {
        debug_hci_printf("\tCould not allocate ble_buff_hdr_t\n");
        ret = kBLEC_OutOfMemory;
        assert(FALSE);
        goto func_exit;
    }

#ifdef DUMP_HCI
    USART_WriteBlocking(DUMP_UART, (uint8_t *)(&packetType), 1);
    USART_WriteBlocking(DUMP_UART, (uint8_t *)(pPacket), packetSize);
#endif /* DUMP_HCI */

    /*Packet Length*/
    ptr_host_event->data_size = packetSize;
    /*Packet Id*/
    if (packetType == kBLEC_HciCommandPacket)
    {
        /* pPacket might be allocated on the stack. Copy to static buffer */
        if (packetSize > MAX_HCI_CMD_PACKET_SIZE)
        {
            debug_hci_printf("ERROR: HCI packet too big\n");
            ret = kBLEC_InvalidParameter;
            assert(FALSE);
            goto func_exit_free_host_event;
        }

        uint8_t *cmdBuff = (uint8_t*)BLEController_AllocCmdBuffer();
        if (cmdBuff == NULL)
        {
            debug_hci_printf("Could not allocate Cmd Buffer\n");
            ret = kBLEC_OutOfMemory;
            assert(FALSE);
            goto func_exit_free_host_event;
        }

        (void)memcpy(cmdBuff, pPacket, packetSize);
        ptr_host_event->buff_start = cmdBuff;
        ptr_host_event->ble_hdr_flags = BLE_BUFF_HDR_EVNT_CMD_PCKT;

#ifdef DUMP_LTK
        uint8_t *data = (uint8_t *)pPacket;
        if (data[0] + (data[1] << 8) == 0x201A)
        {
            PRINTF("LTK: ");
            for (uint32_t i = 0; i < 16; i++)
            {
                PRINTF("%02x ", data[5 + i]);
            }
            PRINTF("\n");
        }
#endif /* DUMP_LTK */
    }
    else if (packetType == kBLEC_HciDataPacket)
    {
        /* For ACL data packets, data has to be copied to BLE data mem*/
        ptr_host_event->ble_hdr_flags = BLE_BUFF_HDR_ACL_DATA_PCKT;
        ptr_host_event->buff_start    = ll_intf_alloc_ll_pkt();
        if (ptr_host_event->buff_start == NULL)
        {
            debug_hci_printf("Could not allocate Cmd Buffer\n");
            ret = kBLEC_OutOfMemory;
            assert(FALSE);
            goto func_exit_free_host_event;
        }

        /*
         * buff_start can be in ble shared memory which has special alignment requirements.
         * memcpy can cause an alignment fault
         */
        Mem_Copy_Per_Byte(ptr_host_event->buff_start, (uint8_t*)pPacket, packetSize);
    }
    else
    {
        debug_hci_printf("ERROR: unsupported hciPacketType_t %x\n", packetType);
        ret = kBLEC_UnknownHCICommand;
        assert(FALSE);
        goto func_exit_free_host_event;
    }
    /*Post the message to be processed by the HCI layer*/
    ret = emngr_post_event(HCI_HANDLER, ptr_host_event);

    if (ret != 0)
    {
        if (ret == HANDLE_IS_FULL)
        {
            debug_hci_printf("ERROR: Handle is full\n");
            ret = kBLEC_Overflow;
            assert(FALSE);
        }
        else
        {
            ret = kBLEC_UnknownError;
            assert(FALSE);
        }

        goto func_exit_free_all;
    }

    goto func_exit;

func_exit_free_all:
    ll_intf_free_ll_pkt(ptr_host_event->buff_start);
func_exit_free_host_event:
    hci_free_msg(ptr_host_event);
func_exit:
    return ret;
}

void BLEController_EmngrHandleAllEvents(void)
{
#ifdef DEBUG_HCI
    PrintDeferredHciBufs();
#endif
    emngr_handle_all_events();
}

blec_result_t BLEController_Init(blecHostHciRecvCallback_t callback,
                                 int8_t requested_max_power_dBm,
                                 power_range_dbm_t *selected_power_range)
{
    debug_hci_printf("Controller_Init ...\n");
    ble_stat_t result = SUCCESS;
    blec_result_t ret = kBLEC_Success;
    const struct hci_dispatch_tbl *p_hci_dis_tbl = NULL;

    const int ll_irq_prio = NVIC_GetPriority(BLE_LL_IRQn);

    /* Make sure LL interrupt has the highest priority (only check enabled interrupts). This is a prerequisite of the system. */
    for (int irq = 0; irq <= WAKE_PAD_IRQn; irq++)
    {
        if(NVIC_GetEnableIRQ(irq) &&
                irq != BLE_LL_IRQn &&
                irq != BLE_SLP_TMR_IRQn)
        {
            if(NVIC_GetPriority(irq) <= ll_irq_prio)
            {
                debug_hci_printf("irq %d with priority %d must have lower priority than BLE_LL_IRQn irq prio %d\n", irq, NVIC_GetPriority(irq), ll_irq_prio);
                return kBLEC_ErrorLLIrqPriorityInit;
            }
        }
    }


    ret = BLEController_SetTaskStackSize(OS_WRAPPER_LL_THREAD_STACK_SIZE_BYTES, OS_WRAPPER_LL_HIGH_PRIO_THREAD_STACK_SIZE_BYTES);
    if (ret != kBLEC_Success)
    {
        debug_hci_printf("BLEController_SetTaskStackSize Error\n");
        return ret;
    }

    ret = BLEController_InitLowLevel(callback ? cmdBufferPoolRaw : NULL, HCI_CMD_BUF_BLOCK_SIZE, MAX_HCI_COMMANDS);
    if (ret != kBLEC_Success)
    {
        debug_hci_printf("BLEController_InitLowLevel Error\n");
        return ret;
    }

    hci_get_dis_tbl(&p_hci_dis_tbl);

    result = ll_intf_init(p_hci_dis_tbl);
    if (result != SUCCESS)
    {
        debug_hci_printf("ll_intf_init Error\n");
        return kBLEC_ErrorLLInit;
    }
    debug_hci_printf("ll_intf_init done.\n");

    result = ll_hci_init(Hci_transport_send_packet);
    if (result != SUCCESS)
    {
        debug_hci_printf("ll_hci_init Error\n");
        return kBLEC_ErrorLLHCIInit;
    }
    debug_hci_printf("ll_hci_init done\n");

    result = ll_intf_select_tx_power_table(BLEController_getTableIdx(requested_max_power_dBm));
    if (result != SUCCESS)
    {
        debug_hci_printf("ll_intf_select_tx_power_table Error\n");
        return kBLEC_ErrorSelectPowerTable;
    }

    BLEController_getPowerRange(selected_power_range);

    debug_hci_printf("ll_intf_select_tx_power_table done\n");

    result = ll_intf_config_ll_ctx_params(0, 1);
    if (result != SUCCESS)
    {
        debug_hci_printf("ll_intf_config_ll_ctx_params Error\n");
        return kBLEC_ErrorLLConfigCtx;
    }
    debug_hci_printf("ll_intf_config_ll_ctx_params done\n");

    /* select sleeptimer clock source type */
    uint16_t ptr_slp_clk_freq_value = 0;
    result                             = ll_intf_le_select_slp_clk_src((uint8_t)RTC_SLPTMR, &ptr_slp_clk_freq_value);
    if (result != SUCCESS)
    {
        debug_hci_printf("ll_intf_le_select_slp_clk_src Error\n");
        return kBLEC_ErrorLLSlpClkSrc;
    }

    debug_hci_printf("ll_intf_le_select_slp_clk_src done\n");

    blecHostHciRecvCallback = callback;

#ifdef DUMP_HCI
    usart_config_t userConfig;

    CLOCK_AttachClk(DUMP_UART_CLK);
    RESET_PeripheralReset(DUMP_UART_RESET);

    USART_GetDefaultConfig(&userConfig);
    userConfig.enableTx     = true;
    userConfig.enableRx     = true;
    userConfig.baudRate_Bps = 460800;

    USART_Init(DUMP_UART, &userConfig, 12000000u);
#endif
    return kBLEC_Success;
}
