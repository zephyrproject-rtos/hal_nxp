/* -------------------------------------------------------------------------- */
/*                      Copyright 2021-2023, 2025-2026 NXP                    */
/*                    SPDX-License-Identifier: BSD-3-Clause                   */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */

#include <stdint.h>
#include <assert.h>

#include "fsl_adapter_rpmsg.h"
#include "fwk_config.h"
#include "fwk_platform_definitions.h"
#include "fwk_platform.h"
#include "fwk_platform_ble.h"
#include "fwk_platform_ics.h"
#include "fwk_debug.h"

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
#include "fwk_workq.h"
#include "fsl_os_abstraction.h"
#endif

#ifdef SERIAL_BTSNOOP
#include "sbtsnoop.h"
#endif

/* -------------------------------------------------------------------------- */
/*                               Private macros                               */
/* -------------------------------------------------------------------------- */
#ifndef PLATFORM_BLE_HCI_TIMEOUT_MS
#define PLATFORM_BLE_HCI_TIMEOUT_MS 200U
#endif

#define HCI_EVENT_PACKET_TYPE (0x04U)
#define HCI_VENDOR_EVENT_CODE (0xFFU)

/* Check if __st is negative,  if true, apply 4 bits shift and add new __error_code,
    assert in debug and break
   Shall be called in a do while(0) bracket */
#define CHECK_AND_RAISE_ERROR(__st, __error_code)                                                  \
    {                                                                                              \
        if ((__st) < 0)                                                                            \
        {                                                                                          \
            assert(false);                                                                         \
            (__st) = -(int)((uint32_t)(((uint32_t)(-(__st)) << 4) | (uint32_t)(-(__error_code)))); \
            break;                                                                                 \
        }                                                                                          \
    }

/* Raise error with status update , shift previous status by 4 bits and OR with new error code.
 * the returned status will be negative */
#define RAISE_ERROR(__st, __error_code) -(int)((uint32_t)(((uint32_t)(__st) << 4) | (uint32_t)(__error_code)));

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
#ifndef PLATFORM_HCI_RX_QUEUE_SIZE
#define PLATFORM_HCI_RX_QUEUE_SIZE 10
#endif
#endif

/* -------------------------------------------------------------------------- */
/*                          Private type definitions                          */
/* -------------------------------------------------------------------------- */
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
typedef struct
{
    uint32_t len;
    uint8_t *data;
} hci_rx_data_t;
#endif

/* -------------------------------------------------------------------------- */
/*                               Private Memory                               */
/* -------------------------------------------------------------------------- */
/* HCI logging callback - registered by upper layers (DBG module or application) */
static platform_hci_log_cb_t platform_hci_log_cb = NULL;

/* -------------------------------------------------------------------------- */
/*                             Private prototypes                             */
/* -------------------------------------------------------------------------- */

/*!
 * \brief Init HCI link with BLE controller
 *
 */
static int PLATFORM_InitHciLink(void);

/*!
 * \brief RPMSG Rx callback used to receive HCI messages from Controller
 *
 * \param[in] param Usually NULL
 * \param[in] data pointer to data buffer
 * \param[in] len size of the data
 * \return hal_rpmsg_return_status_t tells RPMSG to free or hold the buffer
 */
static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len);

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
/*!
 * \brief Processes the HCI received data from the workqueue
 *
 * \param[in] work pointer to the work item
 */
static void PLATFORM_HciRxWorkHandler(fwk_work_t *work);
#endif

/* -------------------------------------------------------------------------- */
/*                         Private memory declarations                        */
/* -------------------------------------------------------------------------- */
/* Define hci rpmsg handle*/
static RPMSG_HANDLE_DEFINE(hciRpmsgHandle);

/*hci rpmsg configuration*/
static const hal_rpmsg_config_t hciRpmsgConfig = {
    .local_addr  = 40,
    .remote_addr = 30,
    .callback    = PLATFORM_HciRpmsgRxCallback,
};

static void (*hci_rx_callback)(uint8_t packetType, uint8_t *data, uint16_t len);

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
static OSA_MSGQ_HANDLE_DEFINE(hciMsgQueue, PLATFORM_HCI_RX_QUEUE_SIZE, sizeof(hci_rx_data_t));
static fwk_work_t hci_work = {.handler = PLATFORM_HciRxWorkHandler};
#endif

/* -------------------------------------------------------------------------- */
/*                              Public functions                              */
/* -------------------------------------------------------------------------- */

int PLATFORM_InitBle(void)
{
    static bool initialized = false;
    int         status      = 0;

    do
    {
        if (initialized == true)
        {
            status = 1;
            break;
        }

        /* When waking up from deep power down mode (following Deep power down reset), it is necessary to release IO
         * isolation. this is usually done in Low power initialization but it is necessary also
         * to be done if the Application does not support low power */
        (void)PLATFORM_ClearIoIsolationFromLowPower();

        /* Init NBU domain and configure RFMC module
         * CM3 is still in reset and will be released by MCMGR_StartCore during RPMSG init */
        status = PLATFORM_InitNbu();
        CHECK_AND_RAISE_ERROR(status, -2);

        /* Init of the multicore*/
        status = PLATFORM_InitMulticore();
        CHECK_AND_RAISE_ERROR(status, -3);

        /* Init HCI link with NBU */
        status = PLATFORM_InitHciLink();
        CHECK_AND_RAISE_ERROR(status, -4);

        /* Initialize PLatform Service intercore channel
         *  Used to retrieve NBU version information but not restricted to this sole use.
         */
        status = PLATFORM_FwkSrvInit();
        CHECK_AND_RAISE_ERROR(status, -5);

#if defined(gPlatformSetSfcConfigAtInit_d) && (gPlatformSetSfcConfigAtInit_d > 0)
        /* Send the SFC config if the application is not using the default values */
        status = PLATFORM_InitSfc();
        CHECK_AND_RAISE_ERROR(status, -8);
#endif

        /* Send chip revision (A0 or A1) to NBU */
        status = PLATFORM_SendChipRevision();
        CHECK_AND_RAISE_ERROR(status, -6);

#if defined gPlatformHasIntercoreCommonTimestamp_d && (gPlatformHasIntercoreCommonTimestamp_d > 0)
        status = PLATFORM_SetNbuSharedCtxAddress();
        CHECK_AND_RAISE_ERROR(status, -7);
#endif

#if defined(gPlatformSetWakeUpDelayAtInit_d) && (gPlatformSetWakeUpDelayAtInit_d > 0)
        /* Send the wake up delay to the NBU if the application is not using the default value */
        status = PLATFORM_InitWakeUpDelay();
        CHECK_AND_RAISE_ERROR(status, -9);
#endif

#if defined(gPlatformUseHwParameter_d) && (gPlatformUseHwParameter_d > 0)
        /* Update 32MHz trim value with the one stored in HW parameters */
        PLATFORM_LoadHwParams();
#endif

#if defined(gPlatformSetBleMaxTxPowerAtInit_d) && (gPlatformSetBleMaxTxPowerAtInit_d > 0)
        PLATFORM_SetBleMaxTxPower((int8_t)gAppMaxTxPowerDbm_c);
#endif

        /* Initialize log handle for second core */
        BOARD_DBGCONFIGINITNBU(TRUE);
        // DBG_LOG_DUMP();

        initialized = true;
    } while (false);

    /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
    if ((status < 0) && (pfPlatformErrorCallback != NULL))
    {
        pfPlatformErrorCallback(PLATFORM_INIT_BLE_ID, status);
    }

    return status;
}

int PLATFORM_StartHci(void)
{
    /* Not implemented on this platform */
    return 0;
}

int PLATFORM_SetHciRxCallback(void (*callback)(uint8_t packetType, uint8_t *data, uint16_t len))
{
    /* Assign value to global hci_rx_callback function pointer */
    hci_rx_callback = callback;
    return 0;
}

int PLATFORM_SendHciMessage(uint8_t *msg, uint32_t len)
{
    int status = 0;
    do
    {
        /* Wake up controller before sending the message */
        PLATFORM_RemoteActiveReq();

        /* Send HCI Packet through RPMSG channel */
        status = (int)HAL_RpmsgSendTimeout(hciRpmsgHandle, msg, len, PLATFORM_BLE_HCI_TIMEOUT_MS);
        if (status != 0)
        {
            status = RAISE_ERROR(status, 1);
            break;
        }

#ifdef SERIAL_BTSNOOP
        if (len >= 2U)
        {
            /* HCI message must have a length greater or equal to 2 to be valid */
            uint16_t lg = (uint16_t)len - 1U;
            sbtsnoop_write_hci_pkt(msg[0U], 0U, &msg[1], lg);
        }
#endif
        /* Log HCI TX packet if callback registered */
        if ((platform_hci_log_cb != NULL) && (len > 1U))
        {
            platform_hci_log_cb(msg[0], &msg[1], (uint16_t)(len - 1U), false);
        }
    } while (false);

    /* Release wake up request */
    PLATFORM_RemoteActiveRel();

    /* Error callback set by PLATFORM_RegisterBleErrorCallback() */
    if ((status != 0) && (pfPlatformErrorCallback != NULL))
    {
        pfPlatformErrorCallback(PLATFORM_SEND_HCI_MESSAGE_ID, status);
    }

    return status;
}

int PLATFORM_SendHciMessageAlt(uint8_t packetType, uint8_t *msg, uint32_t len)
{
    /* not implemented */
    assert(false);
    return -1;
}

int PLATFORM_SendHciVendorEvent(uint8_t *data, uint32_t len)
{
    int ret = 0;

    /* len shall be strictly positive as message shall not be empty */
    assert((data != NULL) && (len > 0U) && (len <= (uint16_t)UINT16_MAX));
    do
    {
        if ((data == NULL) || (len == 0U) || (len > (uint16_t)UINT16_MAX))
        {
            ret = -1;
            break;
        }

        if ((data[0] != HCI_VENDOR_EVENT_CODE) || (hci_rx_callback == NULL))
        {
            ret = -2;
            break;
        }

        hci_rx_callback(HCI_EVENT_PACKET_TYPE, &data[0], (uint16_t)len);
#ifdef SERIAL_BTSNOOP
        sbtsnoop_write_hci_pkt(HCI_EVENT_PACKET_TYPE, 1U, &data[0], (uint16_t)len);
#endif
        /* Log HCI vendor event if callback registered */
        if (platform_hci_log_cb != NULL)
        {
            platform_hci_log_cb(HCI_EVENT_PACKET_TYPE, data, (uint16_t)len, true);
        }
    } while (false);

    return ret;
}

void PLATFORM_RegisterHciLogCallback(platform_hci_log_cb_t cb)
{
    /* Register HCI logging callback - called by DBG module or application */
    platform_hci_log_cb = cb;
}

/* -------------------------------------------------------------------------- */
/*                              Private functions                             */
/* -------------------------------------------------------------------------- */
/*!
 * \brief Initialize HCI RPMSG interface .
 *
 * \return status of the operation, hal_rpmsg_status_t.
 *
 */
static int PLATFORM_InitHciLink(void)
{
    int                status = 0;
    hal_rpmsg_config_t hci_rpmsg_config;
    hal_rpmsg_status_t hci_rpmsg_status;

    hci_rpmsg_config = hciRpmsgConfig;

    do
    {
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
        osa_status_t osa_status;
        status = WORKQ_InitSysWorkQ();
        if (status < 0)
        {
            assert(false);
            break;
        }

        /* We are using the OS message queue since it allows to allocate the memory safely (statically or during init)
         * and then copy hci_rx_data content in ISR context without allocating memory dynamically
         * This works with the workqueue only if we don't block when calling OSA_MsgQGet() */
        osa_status = OSA_MsgQCreate(hciMsgQueue, PLATFORM_HCI_RX_QUEUE_SIZE, sizeof(hci_rx_data_t));
        if (osa_status != KOSA_StatusSuccess)
        {
            assert(false);
            status = RAISE_ERROR(osa_status, 3);
            break;
        }
#endif

        hci_rpmsg_status = HAL_RpmsgInit((hal_rpmsg_handle_t)hciRpmsgHandle, &hci_rpmsg_config);
        if (hci_rpmsg_status != kStatus_HAL_RpmsgSuccess)
        {
            assert(false);
            status = RAISE_ERROR(hci_rpmsg_status, 1);
            break;
        }

    } while (false);

    return status;
}

static hal_rpmsg_return_status_t PLATFORM_HciRpmsgRxCallback(void *param, uint8_t *data, uint32_t len)
{
    hal_rpmsg_return_status_t ret = kStatus_HAL_RL_RELEASE;
    (void)param;

    do
    {
        /* len shall be strictly positive as message shall not be empty */
        if ((len < 2U) || (len > (uint32_t)UINT16_MAX))
        {
            assert(false);
            break;
        }

        if (hci_rx_callback == NULL)
        {
            /* no use queueing if callback is not set, and we can't process the message synchronously either */
            break;
        }
#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
        hci_rx_data_t hci_rx_data = {.len = len, .data = data};

        /* Submit to workqueue first, to make sure no errors occur, we push the message to the queue after.
         * If pushing to the queue fails, the work will be executed but won't do anything, so this is safe.
         * Since we are in ISR context, the workqueue thread can't execute until we exit from ISR, so this is safe
         * to do before pushing to the message queue. */
        if (WORKQ_Submit(&hci_work) < 0)
        {
            assert(false);
        }
        else
        {
            osa_status_t status = OSA_MsgQPut(hciMsgQueue, (void *)&hci_rx_data);
            if (status == KOSA_StatusSuccess)
            {
                /* Submission to workqueue and message queue succeeded, hold the rpmsg buffer in shared memory */
                ret = kStatus_HAL_RL_HOLD;
            }
            else
            {
                assert(false);
            }
        }
#else
        PLATFORM_RemoteActiveReq();
        hci_rx_callback(data[0], &data[1], (uint16_t)(len - 1U));

#ifdef SERIAL_BTSNOOP
        sbtsnoop_write_hci_pkt(data[0U], 1U, &data[1], (uint16_t)(len - 1U));
#endif
        /* Log HCI RX packet if callback registered */
        if (platform_hci_log_cb != NULL)
        {
            platform_hci_log_cb(data[0], &data[1], (uint16_t)(len - 1U), true);
        }
        PLATFORM_RemoteActiveRel();
#endif

    } while (false);
    return ret;
}

#if defined(gPlatformHciUseWorkqueueRxProcessing_d) && (gPlatformHciUseWorkqueueRxProcessing_d > 0)
static void PLATFORM_HciRxWorkHandler(fwk_work_t *work)
{
    hci_rx_data_t hci_rx_data;
    osa_status_t  status;
    (void)work;

    /* Check if there is any message in the queue
     * Important: do not set a blocking time to prevent blocking the system workqueue */

    assert(hci_rx_callback != NULL); /* cannot happen since callback is checked before queuing */

    status = OSA_MsgQGet(hciMsgQueue, (void *)&hci_rx_data, 0UL);
    PLATFORM_RemoteActiveReq();

    while (status == KOSA_StatusSuccess)
    {
        /* The message length must be greater than 2, otherwise it's invalid */
        if ((hci_rx_data.data != NULL) && (hci_rx_data.len >= 2U) && (hci_rx_data.len <= (uint32_t)UINT16_MAX))
        {
            hci_rx_callback(hci_rx_data.data[0], &hci_rx_data.data[1], (uint16_t)(hci_rx_data.len - 1U));

#ifdef SERIAL_BTSNOOP
            sbtsnoop_write_hci_pkt(hci_rx_data.data[0U], 1U, &hci_rx_data.data[1], (uint16_t)(hci_rx_data.len - 1U));
#endif
            /* Log HCI RX packet if callback registered */
            if (platform_hci_log_cb != NULL)
            {
                platform_hci_log_cb(hci_rx_data.data[0], &hci_rx_data.data[1], (uint16_t)(hci_rx_data.len - 1U), true);
            }
            /* Release the buffer from shared memory */
            (void)HAL_RpmsgFreeRxBuffer(hciRpmsgHandle, hci_rx_data.data);
        }

        /* Continue until the queue is empty */
        status = OSA_MsgQGet(hciMsgQueue, (void *)&hci_rx_data, 0);
    }

    PLATFORM_RemoteActiveRel();
}
#endif
