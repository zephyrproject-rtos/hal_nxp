/*
 * Copyright  2017-2021 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_usart.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.vusart"
#endif

enum
{
    kUSART_TxIdle, /* TX idle. */
    kUSART_TxBusy, /* TX busy. */
    kUSART_RxIdle, /* RX idle. */
    kUSART_RxBusy  /* RX busy. */
};

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Array of USART handle. */
static usart_handle_t *s_usartHandle[FSL_FEATURE_SOC_USART_COUNT];

/*! @brief IRQ name array */
static const IRQn_Type s_usartIRQ[] = USART_IRQS;

/*! @brief Array to map USART instance number to base address. */
static const uint32_t s_usartBaseAddrs[FSL_FEATURE_SOC_USART_COUNT] = USART_BASE_ADDRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* @brief Array to map USART instance number to CLOCK names */
static const clock_ip_name_t s_usartClock[] = USART_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_FEATURE_USART_HAS_NO_RESET) && FSL_FEATURE_USART_HAS_NO_RESET)
/* Reset the USART module */
static const reset_ip_name_t s_usartResets[] = USART_RSTS;
#endif

/* Typedef for interrupt handler. */
typedef void (*usart_isr_t)(USART_Type *base, usart_handle_t *handle);

/* USART ISR for transactional APIs. */
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
static usart_isr_t s_usartIsr = (usart_isr_t)DefaultISR;
#else
static usart_isr_t s_usartIsr;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Get the index corresponding to the USART */
/*! brief Returns instance number for USART peripheral base address. */
uint32_t USART_GetInstance(USART_Type *base)
{
    uint32_t i;

    for (i = 0; i < (uint32_t)FSL_FEATURE_SOC_USART_COUNT; i++)
    {
        if (MSDK_REG_SECURE_ADDR((uint32_t)base) == MSDK_REG_SECURE_ADDR(s_usartBaseAddrs[i]))
        {
            break;
        }
    }

    assert(i < FSL_FEATURE_SOC_USART_COUNT);
    return i;
}
/* Write one byte to TX register. */
/*!
 * brief Writes to the FIFO TXDATUSART register or TXDAT  register.
 *
 * This function will writes data to the txFIFO register or TXDAT automatly, which depend
 * on if the system FIFO is enabled.The upper layer must ensure
 * that txFIFO has space for data to write before calling this function.
 *
 * param base USART peripheral base address.
 * param data The byte to write.
 */
void USART_WriteByte(USART_Type *base, uint8_t data)
{
    uint32_t instance = USART_GetInstance(base);
    if (USART_IsTxFifoEnable(base))
    {
        VFIFO->USART[instance].TXDATUSART = data;
    }
    else
    {
        base->TXDAT = data;
    }
}

/* Read one byte from RX register. */
/*!
 * brief Reads the FIFO RXDATUSART register or RXDAT directly.
 *
 * This function reads data from the FIFO RXDATUSART register or RXDAT automatly. which depend
 * on if the system FIFO is enabled for USART. The upper layer must
 * ensure that the rxFIFO is not empty before calling this function.
 *
 * param base USART peripheral base address.
 * return The byte read from USART data register.
 */
uint8_t USART_ReadByte(USART_Type *base)
{
    uint32_t instance = USART_GetInstance(base);
    return ((USART_IsRxFifoEnable(base)) ? (uint8_t)(VFIFO->USART[instance].RXDATUSART) :
                                           (uint8_t)(base->RXDAT & 0x000000FFU));
}

/* Get system FIFO USART status flags. */
/*!
 * brief Get system FIFO status flags for USART.
 *
 * This function get all system FIFO status flags for USART, the flags are returned as the logical
 * OR value of the enumerators ref _usart_fifo_flags. To check a specific status,
 * compare the return value with enumerators in ref _usart_fifo_flags.
 * For example, to check whether the TX FIFO is empty:
 * code
 *     if (kUSART_TxFifoEmptyFlag & USART_GetFifoStatusFlags(USART1))
 *     {
 *         ...
 *     }
 * endcode
 *
 * param base USART peripheral base address.
 * return USART status flags which are ORed by the enumerators in the _usart_fifo_flags.
 */
uint32_t USART_GetFifoStatusFlags(USART_Type *base)
{
    uint32_t instance = USART_GetInstance(base);
    return (VFIFO->USART[instance].STATUSART);
}

/* Clear system FIFO USART status flag. */
/*!
 * brief Clear FIFO status flag for USART.
 *
 * This function clear supported USART status flags
 * Flags that can be cleared or set are:
 *      kUSART_FifoBusErrorFlag
 * For example:
 * code
 *     USART_ClearFifoStatusFlags(USART0, kUSART_FifoBusErrorFlag)
 * endcode
 *
 * param base USART peripheral base address.
 * param mask status flags to be cleared.
 */
void USART_ClearFifoStatusFlags(USART_Type *base, uint32_t mask)
{
    uint32_t instance = USART_GetInstance(base);
    VFIFO->USART[instance].STATUSART |= mask;
}

/* Enable system FIFO interrupts for USART. */
/*!
 * brief Enables FIFO interrupts for USART according to the provided mask.
 *
 * This function enables the USART FIFO interrupts according to the provided mask. The mask
 * is a logical OR of enumeration members. See ref _usart_interrupt_enable.
 * For example, to enable TX threshold interrupt and RX threshold interrupt:
 * code
 *     USART_EnableInterrupts(USART0, kUSART_RxFifoThresholdInterruptEnable | kUSART_RxFifoThresholdInterruptEnable);
 * endcode
 *
 * param base USART peripheral base address.
 * param mask The interrupts to enable. Logical OR of ref _usart_interrupt_enable.
 */
void USART_EnableFifoInterrupts(USART_Type *base, uint32_t mask)
{
    uint32_t instance = USART_GetInstance(base);
    VFIFO->USART[instance].CTLSETUSART |= mask;
}

/* Disable FIFO interrupts for USART. */
/*!
 * brief Disables FIFO interrupts for USART according to a provided mask.
 *
 * This function disables the USART FIFO interrupts according to a provided mask. The mask
 * is a logical OR of enumeration members. See ref _usart_interrupt_enable.
 * This example shows how to disable the TX threshold interrupt and RX threshold interrupt:
 * code
 *     USART_DisableInterrupts(USART1, kUSART_RxFifoThresholdInterruptEnable | kUSART_RxFifoThresholdInterruptEnable);
 * endcode
 *
 * param base USART peripheral base address.
 * param mask The interrupts to disable. Logical OR of ref _usart_fifo_interrupt_enable.
 */
void USART_DisableFifoInterrupts(USART_Type *base, uint32_t mask)
{
    uint32_t instance = USART_GetInstance(base);
    VFIFO->USART[instance].CTLCLRUSART |= mask;
}

/* Get enabled interrupt of FIFO for USART. */
/*!
 * brief Returns enabled USART FIFO interrupts.
 *
 * This function returns the enabled USART FIFO interrupts.
 *
 * param base USART peripheral base address.
 */
uint32_t USART_GetEnabledFifoInterrupts(USART_Type *base)
{
    uint32_t instance = USART_GetInstance(base);
    return (VFIFO->USART[instance].CTLSETUSART);
}

/* Flush the FIFO for USART transfer. */
/*!
 * brief Flush the FIFO buffer.
 *
 * This function will Flush tHE fifo buffer.
 *
 * param base USART peripheral base address.
 * param direction the fifo direction need to flushed, Tx FIFO or Rx FIFO.
 */
void USART_FifoFlush(USART_Type *base, uint32_t direction)
{
    uint32_t instance = USART_GetInstance(base);

    if (((uint32_t)kUSART_FifoTx & direction) != 0U)
    {
        VFIFO->USART[instance].CTLSETUSART |= VFIFO_USART_CTLSETUSART_TXFLUSH_MASK;
        VFIFO->USART[instance].CTLCLRUSART |= VFIFO_USART_CTLCLRUSART_TXFLUSHCLR_MASK;
    }

    if (((uint32_t)kUSART_FifoRx & direction) != 0U)
    {
        VFIFO->USART[instance].CTLSETUSART |= VFIFO_USART_CTLSETUSART_RXFLUSH_MASK;
        VFIFO->USART[instance].CTLCLRUSART |= VFIFO_USART_CTLCLRUSART_RXFLUSHCLR_MASK;
    }
}

/* Enable USART FIFO function. */
/*!
 * brief Enable FIFO.
 *
 * This function will configure the FIFOs according to the config struct.
 *
 * param base USART peripheral base address.
 * param config Pointer to user-defined configuration structure.
 */
void USART_EnableFifo(USART_Type *base, const usart_fifo_config_t *config)
{
    uint32_t instance = 0U;

    instance = USART_GetInstance(base);

/* Enable the system FIFO clock. */
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(kCLOCK_Fifo);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Enable the TX/RX FIFO mode. */
    switch (instance)
    {
        case 0:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U0TXFIFOEN_MASK | SYSCON_FIFOCTRL_U0RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_U0TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_U0RXFIFOEN(config->enableRxFifo);
            break;
        case 1:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U1TXFIFOEN_MASK | SYSCON_FIFOCTRL_U1RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_U1TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_U1RXFIFOEN(config->enableRxFifo);
            break;
        case 2:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U2TXFIFOEN_MASK | SYSCON_FIFOCTRL_U2RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_U2TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_U2RXFIFOEN(config->enableRxFifo);
            break;
        case 3:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U3TXFIFOEN_MASK | SYSCON_FIFOCTRL_U3RXFIFOEN_MASK);
            SYSCON->FIFOCTRL |=
                SYSCON_FIFOCTRL_U3TXFIFOEN(config->enableTxFifo) | SYSCON_FIFOCTRL_U3RXFIFOEN(config->enableRxFifo);
            break;
        default:
            assert(false);
            break;
    }
    /* Pause the USART FIFO for setting. */
    while (!((0U != (VFIFO->FIFOCTLUSART & VFIFO_FIFOCTLUSART_RXPAUSED_MASK)) &&
             (0U != (VFIFO->FIFOCTLUSART & VFIFO_FIFOCTLUSART_TXPAUSED_MASK))))
    {
        VFIFO->FIFOCTLUSART |= (VFIFO_FIFOCTLUSART_RXPAUSE_MASK | VFIFO_FIFOCTLUSART_TXPAUSE_MASK);
    }
    /* Flush the  TX and RX FIFO buffer. */
    USART_FifoFlush(base, (uint32_t)kUSART_FifoTx | (uint32_t)kUSART_FifoRx);
    /* Set the TX and RX FIFO size. */
    VFIFO->FIFOCFGUSART[instance] =
        VFIFO_FIFOCFGUSART_RXSIZE(config->rxFifoSize) | VFIFO_FIFOCFGUSART_TXSIZE(config->txFifoSize);
    /* Set the TX and RX FIFO threshold size. */
    VFIFO->USART[instance].CFGUSART &= ~(VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK | VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK);
    VFIFO->USART[instance].CFGUSART |= VFIFO_USART_CFGUSART_RXTHRESHOLD(config->rxFifoThreshold) |
                                       VFIFO_USART_CFGUSART_TXTHRESHOLD(config->txFifoThreshold);
    /* Update all the TX and RX fifo size. */
    VFIFO->FIFOUPDATEUSART |=
        VFIFO_FIFOUPDATEUSART_USART0RXUPDATESIZE_MASK | VFIFO_FIFOUPDATEUSART_USART1RXUPDATESIZE_MASK |
        VFIFO_FIFOUPDATEUSART_USART2RXUPDATESIZE_MASK | VFIFO_FIFOUPDATEUSART_USART3RXUPDATESIZE_MASK |
        VFIFO_FIFOUPDATEUSART_USART0TXUPDATESIZE_MASK | VFIFO_FIFOUPDATEUSART_USART1TXUPDATESIZE_MASK |
        VFIFO_FIFOUPDATEUSART_USART2TXUPDATESIZE_MASK | VFIFO_FIFOUPDATEUSART_USART3TXUPDATESIZE_MASK;
    /* Unpause the system FIFO for transfer. */
    VFIFO->FIFOCTLUSART &= ~(VFIFO_FIFOCTLUSART_RXPAUSE_MASK | VFIFO_FIFOCTLUSART_TXPAUSE_MASK);
}

/*!
 * brief Disable FIFO.
 *
 * This function will disable the FIFO.
 *
 * param base USART peripheral base address.
 */
void USART_DisableFifo(USART_Type *base)
{
    assert(NULL != base);
    uint32_t instance = 0U;

    instance = USART_GetInstance(base);

    /* Pause the USART FIFO for setting. */
    while (!((0U != (VFIFO->FIFOCTLUSART & VFIFO_FIFOCTLUSART_RXPAUSED_MASK)) &&
             (0U != (VFIFO->FIFOCTLUSART & VFIFO_FIFOCTLUSART_TXPAUSED_MASK))))
    {
        VFIFO->FIFOCTLUSART |= (VFIFO_FIFOCTLUSART_RXPAUSE_MASK | VFIFO_FIFOCTLUSART_TXPAUSE_MASK);
    }
    /* Flush the  TX and RX FIFO buffer. */
    USART_FifoFlush(base, (uint32_t)kUSART_FifoTx | (uint32_t)kUSART_FifoRx);
    /* Set the TX and RX FIFO size. */
    VFIFO->FIFOCFGUSART[instance] = VFIFO_FIFOCFGUSART_RXSIZE(0U) | VFIFO_FIFOCFGUSART_TXSIZE(0U);
    /* Set the TX and RX FIFO threshold size. */
    VFIFO->USART[instance].CFGUSART &= ~(VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK | VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK);
    /* Disable all FIFO interrupts. */
    USART_DisableFifoInterrupts(base, (uint32_t)kUSART_FifoAllinterruptEnable);
    /* Clear all FIFO status flags, only receive timeout and bus error flag can be cleared. */
    USART_ClearFifoStatusFlags(base, (uint32_t)kUSART_RxFifoTimeOutFlag | (uint32_t)kUSART_FifoBusErrorFlag);

    /* Unpause the system FIFO for transfer. */
    VFIFO->FIFOCTLUSART &= ~(VFIFO_FIFOCTLUSART_RXPAUSE_MASK | VFIFO_FIFOCTLUSART_TXPAUSE_MASK);

    /* Disable the TX/RX FIFO mode. */
    switch (instance)
    {
        case 0:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U0TXFIFOEN_MASK | SYSCON_FIFOCTRL_U0RXFIFOEN_MASK);
            break;
        case 1:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U1TXFIFOEN_MASK | SYSCON_FIFOCTRL_U1RXFIFOEN_MASK);
            break;
        case 2:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U2TXFIFOEN_MASK | SYSCON_FIFOCTRL_U2RXFIFOEN_MASK);
            break;
        case 3:
            SYSCON->FIFOCTRL &= ~(SYSCON_FIFOCTRL_U3TXFIFOEN_MASK | SYSCON_FIFOCTRL_U3RXFIFOEN_MASK);
            break;
        default:
            assert(false);
            break;
    }
}

/* Check if TX FIFO enabled. */
/*!
 * brief Is TX FIFO enabled.
 *
 * This function will return status if the transmit fifo is enabled. true for enabled and false for not enabled.
 *
 * param base USART peripheral base address.
 * param direction the fifo direction need to be check, Tx FIFO or Rx FIFO.
 * return true for enabled and false for not enabled.
 */
bool USART_IsTxFifoEnable(USART_Type *base)
{
    uint32_t instance = USART_GetInstance(base);
    uint32_t fifosize = VFIFO->FIFOCFGUSART[instance];
    bool status       = false;

    /* Check if system FIFO control TX is enabled. */
    switch (instance)
    {
        case 0:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U0TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 1:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U1TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 2:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U2TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 3:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U3TXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        default:
            assert(false);
            break;
    }

    if (true != status)
    {
        return status;
    }
    /* Check if TX FIFO size is available. */
    return ((fifosize & VFIFO_FIFOCFGUSART_TXSIZE_MASK) != 0U) ? (true) : (false);
}

/* Check if RX FIFO enabled. */
/*!
 * brief Is RX FIFO enabled.
 *
 * This function will return status if the receive fifo is enabled. true for enabled and false for not enabled.
 *
 * param base USART peripheral base address.
 * param direction the fifo direction need to be check, Tx FIFO or Rx FIFK.
 * return true for enabled and false for not enabled.
 */
bool USART_IsRxFifoEnable(USART_Type *base)
{
    uint32_t instance = USART_GetInstance(base);
    uint32_t fifosize = VFIFO->FIFOCFGUSART[instance];
    bool status       = false;

    /* Check if system FIFO control RX is enabled. */
    switch (instance)
    {
        case 0:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U0RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 1:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U1RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 2:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U2RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        case 3:
            if ((SYSCON->FIFOCTRL & SYSCON_FIFOCTRL_U3RXFIFOEN_MASK) != 0U)
            {
                status = true;
            }
            break;
        default:
            assert(false);
            break;
    }

    if (true != status)
    {
        return status;
    }

    /* Check if RX FIFO size is available. */
    return ((fifosize & VFIFO_FIFOCFGUSART_RXSIZE_MASK) != 0U) ? (true) : (false);
}

/*!
 * brief Get the length of received data in RX ring buffer.
 *
 * param handle USART handle pointer.
 * return Length of received data in RX ring buffer.
 */
size_t USART_TransferGetRxRingBufferLength(usart_handle_t *handle)
{
    size_t size = 0U;

    /* Check arguments */
    assert(NULL != handle);
    uint16_t tmprxRingBufferHead = handle->rxRingBufferHead;
    uint16_t tmprxRingBufferTail = handle->rxRingBufferTail;

    if (tmprxRingBufferTail > tmprxRingBufferHead)
    {
        size = (size_t)tmprxRingBufferHead + handle->rxRingBufferSize - (size_t)tmprxRingBufferTail;
    }
    else
    {
        size = (size_t)tmprxRingBufferHead - (size_t)tmprxRingBufferTail;
    }
    return size;
}

static bool USART_TransferIsRxRingBufferFull(usart_handle_t *handle)
{
    bool full = false;

    /* Check arguments */
    assert(NULL != handle);

    if (USART_TransferGetRxRingBufferLength(handle) == (handle->rxRingBufferSize - 1U))
    {
        full = true;
    }
    else
    {
        full = false;
    }
    return full;
}

/*!
 * brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific USART handle.
 *
 * When the RX ring buffer is used, data received are stored into the ring buffer even when the
 * user doesn't call the USART_TransferReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, then only 31 bytes are used for saving data.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param ringBuffer Start address of the ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * param ringBufferSize size of the ring buffer.
 */
void USART_TransferStartRingBuffer(USART_Type *base, usart_handle_t *handle, uint8_t *ringBuffer, size_t ringBufferSize)
{
    /* Check arguments */
    assert(NULL != base);
    assert(NULL != handle);
    assert(NULL != ringBuffer);

    /* Setup the ringbuffer address */
    handle->rxRingBuffer     = ringBuffer;
    handle->rxRingBufferSize = ringBufferSize;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;

    /* Ring buffer is ready we can start receiving data */
    if (handle->isRxFifoEnabled)
    {
        /* Start RX threshold interrupt for ring buffer to receive data. */
        USART_EnableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
    }
    else
    {
        /* Start receive data read interrupt and reveive overrun interrupt. */
        USART_EnableInterrupts(
            base, (uint32_t)kUSART_RxReadyInterruptEnable | (uint32_t)kUSART_HardwareOverRunInterruptEnable);
    }
}

/*!
 * brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 */
void USART_TransferStopRingBuffer(USART_Type *base, usart_handle_t *handle)
{
    /* Check arguments */
    assert(NULL != base);
    assert(NULL != handle);

    /* If USART is in idle state, dsiable the interrupts for ring buffer. */
    if (handle->rxState == (uint8_t)kUSART_RxIdle)
    {
        if (handle->isRxFifoEnabled)
        {
            /* Disable FIFO RX threshold interrupt. */
            USART_DisableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
        }
        else
        {
            USART_DisableInterrupts(
                base, (uint32_t)kUSART_RxReadyInterruptEnable | (uint32_t)kUSART_HardwareOverRunInterruptEnable);
        }
    }
    handle->rxRingBuffer     = NULL;
    handle->rxRingBufferSize = 0U;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;
}

/*!
 * brief Initializes a USART instance with user configuration structure and peripheral clock.
 *
 * This function configures the USART module with the user-defined settings. The user can configure the configuration
 * structure and also get the default configuration by using the USART_GetDefaultConfig() function.
 * Example below shows how to use this API to configure USART.
 * code
 *  usart_config_t usartConfig;
 *  usartConfig.baudRate_Bps = 115200U;
 *  usartConfig.parityMode = kUSART_ParityDisabled;
 *  usartConfig.stopBitCount = kUSART_OneStopBit;
 *  USART_Init(USART1, &usartConfig, 20000000U);
 * endcode
 *
 * param base USART peripheral base address.
 * param config Pointer to user-defined configuration structure.
 * param srcClock_Hz USART clock source frequency in HZ.
 * retval kStatus_USART_BaudrateNotSupport Baudrate is not support in current clock source.
 * retval kStatus_InvalidArgument USART base address is not valid
 * retval kStatus_Success Status USART initialize succeed
 */
status_t USART_Init(USART_Type *base, const usart_config_t *config, uint32_t srcClock_Hz)
{
    status_t result = kStatus_Success;

    /* Check arguments */
    assert(!((NULL == base) || (NULL == config) || (0U == srcClock_Hz)));
    if ((NULL == base) || (NULL == config) || (0U == srcClock_Hz))
    {
        return kStatus_InvalidArgument;
    }

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable usart clock and FRG clock */
    CLOCK_EnableClock(s_usartClock[USART_GetInstance(base)]);

#if !(defined(FSL_FEATURE_USART_HAS_NO_RESET) && FSL_FEATURE_USART_HAS_NO_RESET)
    /* Reset the USART module */
    RESET_PeripheralReset(s_usartResets[USART_GetInstance(base)]);
#endif

    CLOCK_EnableClock(kCLOCK_Frg);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Setup configuration and enable USART to configure other register. */
    base->CFG = USART_CFG_PARITYSEL(config->parityMode) | USART_CFG_STOPLEN(config->stopBitCount) |
                USART_CFG_DATALEN(config->bitCountPerChar) | USART_CFG_LOOP(config->loopback) |
                USART_CFG_SYNCEN((uint32_t)config->syncMode >> 1U) | USART_CFG_SYNCMST((uint8_t)config->syncMode) |
                USART_CFG_CLKPOL(config->clockPolarity) | USART_CFG_CTSEN(config->enableHardwareFlowControl) |
                USART_CFG_ENABLE_MASK;

    /* Setup baudrate */
    result = USART_SetBaudRate(base, config->baudRate_Bps, srcClock_Hz);
    if (kStatus_Success != result)
    {
        return result;
    }

    /* Setting continuous Clock configuration. used for synchronous mode. */
    USART_EnableContinuousSCLK(base, config->enableContinuousSCLK);

    /* Check if FIFO is enabled from extern configuration. */
    if ((config->fifoConfig.enableTxFifo) || (config->fifoConfig.enableRxFifo))
    {
        USART_EnableFifo(base, &config->fifoConfig);
    }
    /* Setup the USART transmit and receive. */
    USART_EnableTx(base, config->enableTx);
    USART_EnableRx(base, config->enableRx);

    return kStatus_Success;
}

/*!
 * brief Deinitializes a USART instance.
 *
 * This function waits for TX complete, disables USART and FIFO if used, and disables the USART clock and FIFO clock if
 * used.
 *
 * param base USART peripheral base address.
 */
void USART_Deinit(USART_Type *base)
{
    /* Check arguments */
    assert(NULL != base);
    /* Wait for data transmit complete. */
    while (0U == (base->STAT & USART_STAT_TXIDLE_MASK))
    {
    }
    if ((USART_IsTxFifoEnable(base)) || (USART_IsRxFifoEnable(base)))
    {
        USART_DisableFifo(base);
    }
    /* Disable the USART module. */
    base->CFG &= ~(USART_CFG_ENABLE_MASK);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_usartClock[USART_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the USART configuration structure to a default value. The default
 * values are:
 *   usartConfig->baudRate_Bps = 115200U;
 *   usartConfig->parityMode = kUSART_ParityDisabled;
 *   usartConfig->stopBitCount = kUSART_OneStopBit;
 *   usartConfig->bitCountPerChar = kUSART_8BitsPerChar;
 *   usartConfig->loopback = false;
 *   usartConfig->enableTx = false;
 *   usartConfig->enableRx = false;
 *   ...
 * param config Pointer to configuration structure.
 */
void USART_GetDefaultConfig(usart_config_t *config)
{
    /* Check arguments */
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* Set always all members ! */
    config->baudRate_Bps               = 115200U;
    config->parityMode                 = kUSART_ParityDisabled;
    config->stopBitCount               = kUSART_OneStopBit;
    config->bitCountPerChar            = kUSART_8BitsPerChar;
    config->loopback                   = false;
    config->enableRx                   = false;
    config->enableTx                   = false;
    config->fifoConfig.enableTxFifo    = false;
    config->fifoConfig.enableRxFifo    = false;
    config->fifoConfig.rxFifoSize      = 16U;
    config->fifoConfig.txFifoSize      = 16U;
    config->fifoConfig.txFifoThreshold = 0U;
    config->fifoConfig.rxFifoThreshold = 0U;
    config->syncMode                   = kUSART_SyncModeDisabled;
    config->enableContinuousSCLK       = false;
    config->clockPolarity              = kUSART_RxSampleOnFallingEdge;
    config->enableHardwareFlowControl  = false;
}

/*!
 * brief Sets the USART instance baud rate.
 *
 * This function configures the USART module baud rate. This function is used to update
 * the USART module baud rate after the USART module is initialized by the USART_Init.
 * code
 *  USART_SetBaudRate(USART1, 115200U, 20000000U);
 * endcode
 *
 * param base USART peripheral base address.
 * param baudrate_Bps USART baudrate to be set.
 * param srcClock_Hz USART clock source frequency in HZ.
 * retval kStatus_USART_BaudrateNotSupport Baudrate is not support in current clock source.
 * retval kStatus_Success Set baudrate succeed.
 * retval kStatus_InvalidArgument One or more arguments are invalid.
 */
status_t USART_SetBaudRate(USART_Type *base, uint32_t baudrate_Bps, uint32_t srcClock_Hz)
{
    uint32_t best_diff = (uint32_t)-1, best_osrval = 0xf, best_brgval = (uint32_t)-1;
    uint32_t osrval, brgval, diff, baudrate;

    /* check arguments */
    assert(!((NULL == base) || (0U == baudrate_Bps) || (0U == srcClock_Hz)));
    if ((NULL == base) || (0U == baudrate_Bps) || (0U == srcClock_Hz))
    {
        return kStatus_InvalidArgument;
    }

    /* If synchronous master mode is enabled, only configure the BRG value. */
    if ((base->CFG & USART_CFG_SYNCEN_MASK) != 0U)
    {
        if ((base->CFG & USART_CFG_SYNCMST_MASK) != 0U)
        {
            brgval    = srcClock_Hz / baudrate_Bps;
            base->BRG = brgval - 1U;
        }
    }
    else
    {
        /*
         * Smaller values of OSR can make the sampling position within a data bit less accurate and may
         * potentially cause more noise errors or incorrect data.
         */
        for (osrval = best_osrval; osrval >= 8U; osrval--)
        {
            brgval = (srcClock_Hz / ((osrval + 1U) * baudrate_Bps)) - 1U;
            if (brgval > 0xFFFFU)
            {
                continue;
            }
            baudrate = srcClock_Hz / ((osrval + 1U) * (brgval + 1U));
            diff     = (baudrate_Bps < baudrate) ? (baudrate - baudrate_Bps) : (baudrate_Bps - baudrate);
            if (diff < best_diff)
            {
                best_diff   = diff;
                best_osrval = osrval;
                best_brgval = brgval;
            }
        }

        /* Check to see if actual baud rate is within 3% of desired baud rate
         * based on the best calculated OSR and BRG value */
        baudrate = srcClock_Hz / ((best_osrval + 1U) * (best_brgval + 1U));
        diff     = (baudrate_Bps < baudrate) ? (baudrate - baudrate_Bps) : (baudrate_Bps - baudrate);
        if (diff > ((baudrate_Bps / 100U) * 3U))
        {
            return kStatus_USART_BaudrateNotSupport;
        }

        /* value over range */
        if (best_brgval > 0xFFFFU)
        {
            return kStatus_USART_BaudrateNotSupport;
        }

        base->OSR = best_osrval;
        base->BRG = best_brgval;
    }

    return kStatus_Success;
}

/*!
 * brief Writes to the TX register using a blocking method.
 *
 * This function polls the TX register, waits for the TX register to be empty or for the TX FIFO
 * to have room and writes data to the TX buffer.
 *
 * param base USART peripheral base address.
 * param data Start address of the data to write.
 * param length Size of the data to write.
 * retval kStatus_USART_Timeout Transmission timed out and was aborted.
 * retval kStatus_InvalidArgument Invalid argument.
 * retval kStatus_Success Successfully wrote all data.
 */
status_t USART_WriteBlocking(USART_Type *base, const uint8_t *data, size_t length)
{
    uint32_t instance = 0U;
    /* Check arguments */
    assert(!((NULL == base) || (NULL == data)));
    if ((NULL == base) || (NULL == data))
    {
        return kStatus_InvalidArgument;
    }
#if UART_RETRY_TIMES
    uint32_t waitTimes;
#endif

    instance = USART_GetInstance(base);

    for (; length > 0U; length--)
    {
        if (USART_IsTxFifoEnable(base))
        {
            /* Loop until TX FIFO is empty for new data */
#if UART_RETRY_TIMES
            waitTimes = UART_RETRY_TIMES;
            while ((0U == (VFIFO->USART[instance].STATUSART & VFIFO_USART_STATUSART_TXEMPTY_MASK)) &&
                   (0U != --waitTimes))
#else
            while (0U == (VFIFO->USART[instance].STATUSART & VFIFO_USART_STATUSART_TXEMPTY_MASK))
#endif
            {
            }
#if UART_RETRY_TIMES
            if (0U == waitTimes)
            {
                return kStatus_USART_Timeout;
            }
#endif
            VFIFO->USART[instance].TXDATUSART = *data;
        }
        else
        {
            /* Wait for TX is ready to transmit new data. */
#if UART_RETRY_TIMES
            waitTimes = UART_RETRY_TIMES;
            while ((0U == (base->STAT & USART_STAT_TXRDY_MASK)) && (0U != --waitTimes))
#else
            while (0U == (base->STAT & USART_STAT_TXRDY_MASK))
#endif
            {
            }
#if UART_RETRY_TIMES
            if (0U == waitTimes)
            {
                return kStatus_USART_Timeout;
            }
#endif
            base->TXDAT = *data;
        }
        data++;
    }
    /* Wait to finish transfer */
#if UART_RETRY_TIMES
    waitTimes = UART_RETRY_TIMES;
    while ((0U == (base->STAT & USART_STAT_TXIDLE_MASK)) && (0U != --waitTimes))
#else
    while (0U == (base->STAT & USART_STAT_TXIDLE_MASK))
#endif
    {
    }
#if UART_RETRY_TIMES
    if (0U == waitTimes)
    {
        return kStatus_USART_Timeout;
    }
#endif
    return kStatus_Success;
}

/*!
 * brief Read RX data register using a blocking method.
 *
 * This function polls the RX register, waits for the RX register to be full or for RX FIFO to
 * have data and read data from the TX register.
 *
 * param base USART peripheral base address.
 * param data Start address of the buffer to store the received data.
 * param length Size of the buffer.
 * retval kStatus_USART_FramingError Receiver overrun happened while receiving data.
 * retval kStatus_USART_ParityError Noise error happened while receiving data.
 * retval kStatus_USART_NoiseError Framing error happened while receiving data.
 * retval kStatus_USART_RxError Overflow or underflow rxFIFO happened.
 * retval kStatus_USART_Timeout Transmission timed out and was aborted.
 * retval kStatus_Success Successfully received all data.
 */
status_t USART_ReadBlocking(USART_Type *base, uint8_t *data, size_t length)
{
    uint32_t statusFlag;
    status_t status   = kStatus_Success;
    uint32_t instance = 0U;
#if UART_RETRY_TIMES
    uint32_t waitTimes;
#endif

    /* Check arguments */
    assert(!((NULL == base) || (NULL == data)));
    if ((NULL == base) || (NULL == data))
    {
        return kStatus_InvalidArgument;
    }

    instance = USART_GetInstance(base);

    for (; length > 0U; length--)
    {
        if (USART_IsRxFifoEnable(base))
        {
            /* Wait for RX FIFO is not empty. */
#if UART_RETRY_TIMES
            waitTimes = UART_RETRY_TIMES;
            while (((VFIFO->USART[instance].STATUSART & VFIFO_USART_STATUSART_RXEMPTY_MASK) != 0U) &&
                   (--waitTimes != 0U))
#else
            while ((VFIFO->USART[instance].STATUSART & VFIFO_USART_STATUSART_RXEMPTY_MASK) != 0U)
#endif
            {
            }
#if UART_RETRY_TIMES
            if (waitTimes == 0U)
            {
                status = kStatus_USART_Timeout;
                break;
            }
#endif
            /* Check USART status */
            statusFlag = VFIFO->USART[instance].STATUSART;
            if ((statusFlag & VFIFO_USART_STATUSART_BUSERR_MASK) != 0U)
            {
                USART_ClearFifoStatusFlags(base, VFIFO_USART_STATUSART_BUSERR_MASK);
                status = kStatus_USART_FifoBusError;
                break;
            }
            /* Check received data status */
            statusFlag = VFIFO->USART[instance].RXDATSTATUSART;
            if ((statusFlag & VFIFO_USART_RXDATSTATUSART_PARITYERR_MASK) != 0U)
            {
                status = kStatus_USART_ParityError;
            }
            if ((statusFlag & VFIFO_USART_RXDATSTATUSART_FRAMERR_MASK) != 0U)
            {
                status = kStatus_USART_FramingError;
            }
            if ((statusFlag & VFIFO_USART_RXDATSTATUSART_RXNOISE_MASK) != 0U)
            {
                status = kStatus_USART_NoiseError;
            }

            if (kStatus_Success == status)
            {
                *data = (uint8_t)(statusFlag & VFIFO_USART_RXDATSTATUSART_RXDAT_MASK);
            }
            else
            {
                break;
            }
        }
        else
        {
            /* loop until receive is ready to read */
            while ((base->STAT & USART_STAT_RXRDY_MASK) == 0U)
            {
            }

            /* Check receive statusFlag */
            statusFlag = base->STAT;
            /* Clear all error status flags */
            base->STAT |= statusFlag;

            if ((statusFlag & USART_STAT_OVERRUNINT_MASK) != 0U)
            {
                status = kStatus_USART_HardwareOverrun;
                break;
            }
            if ((statusFlag & USART_STAT_FRAMERRINT_MASK) != 0U)
            {
                status = kStatus_USART_FramingError;
            }
            if ((statusFlag & USART_STAT_PARITYERRINT_MASK) != 0U)
            {
                status = kStatus_USART_ParityError;
            }
            if ((statusFlag & USART_STAT_RXNOISEINT_MASK) != 0U)
            {
                status = kStatus_USART_NoiseError;
            }
            if (kStatus_Success == status)
            {
                *data = (uint8_t)base->RXDAT;
            }
            else
            {
                break;
            }
        }
        data++;
    }
    return status;
}

/*!
 * brief Initializes the USART handle.
 *
 * This function initializes the USART handle which can be used for other USART
 * transactional APIs. Usually, for a specified USART instance,
 * call this API once to get the initialized handle.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param callback The callback function.
 * param userData The parameter of the callback function.
 */
status_t USART_TransferCreateHandle(USART_Type *base,
                                    usart_handle_t *handle,
                                    usart_transfer_callback_t callback,
                                    void *userData)
{
    uint32_t instance = 0;

    /* Check 'base' */
    assert(!((NULL == base) || (NULL == handle)));
    if ((NULL == base) || (NULL == handle))
    {
        return kStatus_InvalidArgument;
    }

    instance = USART_GetInstance(base);

    (void)memset(handle, 0, sizeof(*handle));
    /* Set the TX/RX state. */
    handle->rxState = (uint8_t)kUSART_RxIdle;
    handle->txState = (uint8_t)kUSART_TxIdle;
    /* Set the callback and user data. */
    handle->callback = callback;
    handle->userData = userData;
    /* Check if TX/RX FIFO are enabled. */
    handle->isTxFifoEnabled = USART_IsTxFifoEnable(base);
    handle->isRxFifoEnabled = USART_IsRxFifoEnable(base);
    if ((handle->isTxFifoEnabled) || (handle->isRxFifoEnabled))
    {
        handle->rxFifoThreshold = (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK) >>
                                            VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT);
        handle->txFifoThreshold = (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK) >>
                                            VFIFO_USART_CFGUSART_TXTHRESHOLD_SHIFT);
    }
    /* Store the handle data to global variables. */
    s_usartHandle[instance] = handle;
    /* Mapping the interrupt function. */
    s_usartIsr = USART_TransferHandleIRQ;

    /* Enable interrupt in NVIC. */
    (void)EnableIRQ(s_usartIRQ[instance]);

    return kStatus_Success;
}

/*!
 * brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data to be written to the TX register. When
 * all data is written to the TX register in the IRQ handler, the USART driver calls the callback
 * function and passes the ref kStatus_USART_TxIdle as status parameter.
 *
 * note The kStatus_USART_TxIdle is passed to the upper layer when all data is written
 * to the TX register. However it does not ensure that all data are sent out. Before disabling the TX,
 * check the kUSART_TransmissionCompleteFlag to ensure that the TX is finished.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param xfer USART transfer structure. See  #usart_transfer_t.
 * retval kStatus_Success Successfully start the data transmission.
 * retval kStatus_USART_TxBusy Previous transmission still not finished, data not all written to TX register yet.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t USART_TransferSendNonBlocking(USART_Type *base, usart_handle_t *handle, usart_transfer_t *xfer)
{
    /* Check arguments */
    assert(!((NULL == base) || (NULL == handle) || (NULL == xfer)));
    if ((NULL == base) || (NULL == handle) || (NULL == xfer))
    {
        return kStatus_InvalidArgument;
    }
    /* Check xfer members */
    assert(!((0U == xfer->dataSize) || (NULL == xfer->txData)));
    if ((0U == xfer->dataSize) || (NULL == xfer->txData))
    {
        return kStatus_InvalidArgument;
    }
    uint32_t instance = USART_GetInstance(base);

    /* Return error if current TX busy. */
    if ((uint8_t)kUSART_TxBusy == handle->txState)
    {
        return kStatus_USART_TxBusy;
    }
    else
    {
        handle->txData        = xfer->txData;
        handle->txDataSize    = xfer->dataSize;
        handle->txDataSizeAll = xfer->dataSize;
        handle->txState       = (uint8_t)kUSART_TxBusy;
        /* Check if TX/RX FIFO are enabled. */
        handle->isTxFifoEnabled = USART_IsTxFifoEnable(base);
        handle->isRxFifoEnabled = USART_IsRxFifoEnable(base);
        if ((handle->isTxFifoEnabled) || (handle->isRxFifoEnabled))
        {
            handle->rxFifoThreshold =
                (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK) >>
                          VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT);
            handle->txFifoThreshold =
                (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK) >>
                          VFIFO_USART_CFGUSART_TXTHRESHOLD_SHIFT);
        }
        /* Enable transmiter interrupt. */
        if (handle->isTxFifoEnabled)
        {
            /* Start system fifo usart tx threshold interrupt. */
            USART_EnableFifoInterrupts(base, (uint8_t)kUSART_TxFifoThresholdInterruptEnable);
        }
        else
        {
            USART_EnableInterrupts(base, (uint8_t)kUSART_TxReadyInterruptEnable);
            /* Clear transmit disable bit. */
            base->CTL &= ~USART_CTL_TXDIS_MASK;
        }
    }
    return kStatus_Success;
}

/*!
 * brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt driven data sending. The user can get the remainBtyes to find out
 * how many bytes are still not sent out.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 */
void USART_TransferAbortSend(USART_Type *base, usart_handle_t *handle)
{
    assert(NULL != handle);

    /* Disable interrupts */
    if (handle->isTxFifoEnabled)
    {
        /* Disable system fifo usart tx threshold interrupt. */
        USART_DisableFifoInterrupts(base, (uint8_t)kUSART_TxFifoThresholdInterruptEnable);
    }
    else
    {
        USART_DisableInterrupts(base, (uint8_t)kUSART_TxReadyInterruptEnable);
    }
    /* Disable transmit after data being transmitted. */
    USART_EnableTx(base, false);

    handle->txDataSize = 0;
    handle->txState    = (uint8_t)kUSART_TxIdle;
}

/*!
 * brief Get the number of bytes that have been sent out to bus.
 *
 * This function gets the number of bytes that have been sent out to bus by interrupt method.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t USART_TransferGetSendCount(USART_Type *base, usart_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != count);

    uint32_t instance = USART_GetInstance(base);

    if ((uint8_t)kUSART_TxIdle == handle->txState)
    {
        return kStatus_NoTransferInProgress;
    }
    if (USART_IsTxFifoEnable(base))
    {
        *count = handle->txDataSizeAll - handle->txDataSize -
                 ((VFIFO->USART[instance].STATUSART & VFIFO_USART_STATUSART_TXCOUNT_MASK) >>
                  VFIFO_USART_STATUSART_TXCOUNT_SHIFT);
    }
    else
    {
        if ((base->STAT & (uint32_t)kUSART_TxReady) != 0U)
        {
            *count = handle->txDataSizeAll - handle->txDataSize;
        }
        else
        {
            *count = handle->txDataSizeAll - handle->txDataSize - 1U;
        }
    }

    return kStatus_Success;
}

/*!
 * brief Receives a buffer of data using an interrupt method.
 *
 * This function receives data using an interrupt method. This is a non-blocking function, which
 *  returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in the ring buffer is copied and
 * the parameter p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in the ring buffer is not enough to read, the receive
 * request is saved by the USART driver. When the new data arrives, the receive request
 * is serviced first. When all data is received, the USART driver notifies the upper layer
 * through a callback function and passes the status parameter ref kStatus_USART_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer.
 * The 5 bytes are copied to the xfer->data and this function returns with the
 * parameter p receivedBytes set to 5. For the left 5 bytes, newly arrived data is
 * saved from the xfer->data[5]. When 5 bytes are received, the USART driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to the xfer->data. When all data is received, the upper layer is notified.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param xfer USART transfer structure, see #usart_transfer_t.
 * param receivedBytes Bytes received from the ring buffer directly.
 * retval kStatus_Success Successfully queue the transfer into transmit queue.
 * retval kStatus_USART_RxBusy Previous receive request is not finished.
 * retval kStatus_InvalidArgument Invalid argument.
 */
status_t USART_TransferReceiveNonBlocking(USART_Type *base,
                                          usart_handle_t *handle,
                                          usart_transfer_t *xfer,
                                          size_t *receivedBytes)
{
    uint32_t i;
    /* How many bytes to copy from ring buffer to user memory. */
    size_t bytesToCopy = 0U;
    /* How many bytes to receive. */
    size_t bytesToReceive;
    /* How many bytes currently have received. */
    size_t bytesCurrentReceived;
    uint32_t instance = USART_GetInstance(base);

    /* Check arguments */
    assert(!((NULL == base) || (NULL == handle) || (NULL == xfer)));
    if ((NULL == base) || (NULL == handle) || (NULL == xfer))
    {
        return kStatus_InvalidArgument;
    }
    /* Check xfer members */
    assert(!((0U == xfer->dataSize) || (NULL == xfer->rxData)));
    if ((0U == xfer->dataSize) || (NULL == xfer->rxData))
    {
        return kStatus_InvalidArgument;
    }

    /* How to get data:
       1. If RX ring buffer is not enabled, then save xfer->data and xfer->dataSize
          to uart handle, enable interrupt to store received data to xfer->data. When
          all data received, trigger callback.
       2. If RX ring buffer is enabled and not empty, get data from ring buffer first.
          If there are enough data in ring buffer, copy them to xfer->data and return.
          If there are not enough data in ring buffer, copy all of them to xfer->data,
          save the xfer->data remained empty space to uart handle, receive data
          to this empty space and trigger callback when finished. */
    if ((uint8_t)kUSART_RxBusy == handle->rxState)
    {
        return kStatus_USART_RxBusy;
    }
    else
    {
        /* Check if TX/RX FIFO are enabled. */
        handle->isTxFifoEnabled = USART_IsTxFifoEnable(base);
        handle->isRxFifoEnabled = USART_IsRxFifoEnable(base);
        if ((handle->isTxFifoEnabled) || (handle->isRxFifoEnabled))
        {
            handle->rxFifoThreshold =
                (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK) >>
                          VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT);
            handle->txFifoThreshold =
                (uint8_t)((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_TXTHRESHOLD_MASK) >>
                          VFIFO_USART_CFGUSART_TXTHRESHOLD_SHIFT);
        }

        bytesToReceive       = xfer->dataSize;
        bytesCurrentReceived = 0U;
        /* If RX ring buffer is used. */
        if (handle->rxRingBuffer != NULL)
        {
            /* Disable USART receive IRQ, protect ring buffer. */
            if (handle->isRxFifoEnabled)
            {
                /* Disable system fifo usart rx threshold interrupt. */
                USART_DisableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
            }
            else
            {
                USART_DisableInterrupts(base, (uint32_t)kUSART_RxReadyInterruptEnable);
            }
            /* How many bytes in RX ring buffer currently. */
            bytesToCopy = USART_TransferGetRxRingBufferLength(handle);
            if (bytesToCopy != 0U)
            {
                bytesToCopy = MIN(bytesToReceive, bytesToCopy);
                bytesToReceive -= bytesToCopy;
                /* Copy data from ring buffer to user memory. */
                for (i = 0U; i < bytesToCopy; i++)
                {
                    xfer->rxData[bytesCurrentReceived++] = handle->rxRingBuffer[handle->rxRingBufferTail];
                    /* Wrap to 0. Not use modulo (%) because it might be large and slow. */
                    if (handle->rxRingBufferTail + 1U == (uint16_t)handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }
            }
            /* If ring buffer does not have enough data, still need to read more data. */
            if (bytesToReceive != 0U)
            {
                /* No data in ring buffer, save the request to UART handle. */
                handle->rxData        = xfer->rxData + bytesCurrentReceived;
                handle->rxDataSize    = bytesToReceive;
                handle->rxDataSizeAll = xfer->dataSize;
                handle->rxState       = (uint8_t)kUSART_RxBusy;
            }
            /* Enable USART receive interrupt for next transfer. */
            if (handle->isRxFifoEnabled)
            {
                /* Enable system fifo usart rx threshold interrupt. */
                USART_EnableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
            }
            else
            {
                USART_EnableInterrupts(base, (uint32_t)kUSART_RxReadyInterruptEnable);
            }
            /* Call user callback since all data are received. */
            if (0U == bytesToReceive)
            {
                if (handle->callback != NULL)
                {
                    handle->callback(base, handle, kStatus_USART_RxIdle, handle->userData);
                }
            }
        }
        /* Ring buffer not used. */
        else
        {
            handle->rxData        = xfer->rxData + bytesCurrentReceived;
            handle->rxDataSize    = bytesToReceive;
            handle->rxDataSizeAll = bytesToReceive;
            handle->rxState       = (uint8_t)kUSART_RxBusy;

            /* Enable RX interrupt. */
            if (handle->isRxFifoEnabled)
            {
                USART_EnableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
            }
            else
            {
                USART_EnableInterrupts(
                    base, (uint32_t)kUSART_RxReadyInterruptEnable | (uint32_t)kUSART_HardwareOverRunInterruptEnable);
            }
        }
        /* Return the how many bytes have read. */
        if (receivedBytes != NULL)
        {
            *receivedBytes = bytesCurrentReceived;
        }
    }
    return kStatus_Success;
}

/*!
 * brief Aborts the interrupt-driven data receiving.
 *
 * This function aborts the interrupt-driven data receiving. The user can get the remainBytes to find out
 * how many bytes not received yet.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 */
void USART_TransferAbortReceive(USART_Type *base, usart_handle_t *handle)
{
    assert(NULL != handle);

    /* Only abort the receive to handle->rxData, the RX ring buffer is still working. */
    if (handle->rxRingBuffer == NULL)
    {
        /* Disable interrupts */
        if (handle->isRxFifoEnabled)
        {
            USART_DisableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
        }
        else
        {
            USART_DisableInterrupts(
                base, (uint32_t)kUSART_RxReadyInterruptEnable | (uint32_t)kUSART_HardwareOverRunInterruptEnable);
        }
    }

    handle->rxDataSize = 0U;
    handle->rxState    = (uint8_t)kUSART_RxIdle;
}

/*!
 * brief Get the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 * param count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t USART_TransferGetReceiveCount(USART_Type *base, usart_handle_t *handle, uint32_t *count)
{
    assert(NULL != handle);
    assert(NULL != count);

    if ((uint8_t)kUSART_RxIdle == handle->rxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->rxDataSizeAll - handle->rxDataSize;

    return kStatus_Success;
}

/*!
 * brief USART IRQ handle function.
 *
 * This function handles the USART transmit and receive IRQ request.
 *
 * param base USART peripheral base address.
 * param handle USART handle pointer.
 */
void USART_TransferHandleIRQ(USART_Type *base, usart_handle_t *handle)
{
    /* Check arguments */
    assert((NULL != base) && (NULL != handle));

    bool receiveEnabled = (handle->rxDataSize != 0U) || (handle->rxRingBuffer != NULL);
    bool sendEnabled    = (handle->txDataSize != 0U);
    uint32_t instance   = USART_GetInstance(base);
    uint8_t tmpdata;
    uint32_t tmpsize;

    /* If RX overrun. */
    if ((base->STAT & USART_STAT_OVERRUNINT_MASK) != 0U)
    {
        /* Clear rx error state. */
        base->STAT |= USART_STAT_OVERRUNINT_MASK;
        /* Trigger callback. */
        if (handle->callback != NULL)
        {
            handle->callback(base, handle, kStatus_USART_RxError, handle->userData);
        }
    }

    /* Receive data */
    if ((receiveEnabled) && ((handle->isRxFifoEnabled) ?
                                 ((VFIFO->USART[instance].INTSTATUSART & VFIFO_USART_INTSTATUSART_RXTH_MASK) != 0U) :
                                 ((base->STAT & USART_STAT_RXRDY_MASK) != 0U)))
    {
        /* Receive to app bufffer if app buffer is present */
        if ((handle->rxDataSize) != 0U)
        {
            if (handle->isRxFifoEnabled)
            {
                uint8_t dataToReceive = handle->rxFifoThreshold + 1U;
                do
                {
                    tmpdata         = (uint8_t)VFIFO->USART[instance].RXDATUSART;
                    *handle->rxData = tmpdata;
                    handle->rxDataSize--;
                    handle->rxData++;
                } while ((--dataToReceive != 0U) && (handle->rxDataSize != 0U));
            }
            else
            {
                tmpdata         = (uint8_t)base->RXDAT;
                *handle->rxData = tmpdata;
                handle->rxDataSize--;
                handle->rxData++;
            }

            if (handle->rxDataSize == 0U)
            {
                if (handle->rxRingBuffer == NULL)
                {
                    /* If system FIFO enabled. */
                    if (handle->isRxFifoEnabled)
                    {
                        /* Disable system fifo usart rx threshold interrupt. */
                        USART_DisableFifoInterrupts(base, (uint32_t)kUSART_RxFifoThresholdInterruptEnable);
                    }
                    else
                    {
                        USART_DisableInterrupts(base, (uint32_t)kUSART_RxReadyInterruptEnable |
                                                          (uint32_t)kUSART_HardwareOverRunInterruptEnable);
                    }
                }
                handle->rxState = (uint8_t)kUSART_RxIdle;
                if (handle->callback != NULL)
                {
                    handle->callback(base, handle, kStatus_USART_RxIdle, handle->userData);
                }
            }
        }
        /* Otherwise receive to ring buffer if ring buffer is present */
        else
        {
            if (handle->rxRingBuffer != NULL)
            {
                uint8_t count = (handle->isRxFifoEnabled) ? (handle->rxFifoThreshold + 1U) : (1U);
                /* If RX ring buffer is full, trigger callback to notify over run. */
                while (0U != count--)
                {
                    if (USART_TransferIsRxRingBufferFull(handle))
                    {
                        if (handle->callback != NULL)
                        {
                            handle->callback(base, handle, kStatus_USART_RxRingBufferOverrun, handle->userData);
                        }
                    }
                    /* If ring buffer is still full after callback function, the oldest data is overridden. */
                    if (USART_TransferIsRxRingBufferFull(handle))
                    {
                        /* Increase handle->rxRingBufferTail to make room for new data. */
                        if (handle->rxRingBufferTail + 1U == (uint16_t)handle->rxRingBufferSize)
                        {
                            handle->rxRingBufferTail = 0U;
                        }
                        else
                        {
                            handle->rxRingBufferTail++;
                        }
                    }
                    /* Read data. */
                    if (handle->isRxFifoEnabled)
                    {
                        tmpdata                                        = (uint8_t)VFIFO->USART[instance].RXDATUSART;
                        handle->rxRingBuffer[handle->rxRingBufferHead] = tmpdata;
                    }
                    else
                    {
                        tmpdata                                        = (uint8_t)base->RXDAT;
                        handle->rxRingBuffer[handle->rxRingBufferHead] = tmpdata;
                    }
                    /* Increase handle->rxRingBufferHead. */
                    if (handle->rxRingBufferHead + 1U == (uint16_t)handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferHead = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferHead++;
                    }
                }
            }
        }
    }
    /* Send data */
    if (sendEnabled && ((handle->isTxFifoEnabled) ?
                            (0U != (VFIFO->USART[instance].INTSTATUSART & VFIFO_USART_INTSTATUSART_TXTH_MASK)) :
                            (0U != (base->STAT & USART_STAT_TXRDY_MASK))))
    {
        /* Send data. */
        if (handle->isTxFifoEnabled)
        {
            uint8_t dataToSend = (handle->txFifoThreshold != 0U) ? (handle->txFifoThreshold) : (1U);
            do
            {
                VFIFO->USART[instance].TXDATUSART = *handle->txData;
                handle->txDataSize--;
                handle->txData++;
                sendEnabled = (handle->txDataSize != 0U);
            } while ((--dataToSend != 0U) && (sendEnabled));
        }
        else
        {
            base->TXDAT = *handle->txData;
            handle->txDataSize--;
            handle->txData++;
            sendEnabled = (handle->txDataSize != 0U);
        }

        if (!sendEnabled)
        {
            /* Disable interrupts */
            if (handle->isTxFifoEnabled)
            {
                USART_DisableFifoInterrupts(base, (uint32_t)kUSART_TxFifoThresholdInterruptEnable);
            }
            else
            {
                USART_DisableInterrupts(base, (uint32_t)kUSART_TxReadyInterruptEnable);
            }
            USART_EnableInterrupts(base, (uint32_t)kUSART_TxIdleInterruptEnable);
        }
    }

    /* Trigger call back when no data waiting to be sent */
    if ((0U != (base->INTSTAT & USART_INTSTAT_TXIDLE_MASK)) && (0U != (base->INTENSET & USART_INTENSET_TXIDLEEN_MASK)))
    {
        /* Set txState to idle only when all data has been sent out to bus. */
        handle->txState = (uint8_t)kUSART_TxIdle;
        USART_DisableInterrupts(base, (uint32_t)kUSART_TxIdleInterruptEnable);
        if (handle->callback != NULL)
        {
            handle->callback(base, handle, kStatus_USART_TxIdle, handle->userData);
        }
    }

    /* Ring buffer is not used */
    if ((NULL == handle->rxRingBuffer) && (handle->isRxFifoEnabled))
    {
        tmpsize = (uint32_t)(handle->rxDataSize);
        /* Restore if rx transfer ends and rxLevel is different from default value */
        if ((tmpsize == 0U) && (((VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK) >>
                                 VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT) != handle->rxFifoThreshold))
        {
            VFIFO->USART[instance].CFGUSART =
                ((VFIFO->USART[instance].CFGUSART & (~VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK)) |
                 VFIFO_USART_CFGUSART_RXTHRESHOLD(handle->rxFifoThreshold));
        }
        /* Decrease level if rx transfer is bellow */
        if ((tmpsize != 0U) && (tmpsize <= (VFIFO->USART[instance].CFGUSART & VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK) >>
                                VFIFO_USART_CFGUSART_RXTHRESHOLD_SHIFT))
        {
            VFIFO->USART[instance].CFGUSART =
                ((VFIFO->USART[instance].CFGUSART & (~VFIFO_USART_CFGUSART_RXTHRESHOLD_MASK)) |
                 VFIFO_USART_CFGUSART_RXTHRESHOLD(tmpsize - 1U));
        }
    }
}

#if defined(USART0)
void USART0_DriverIRQHandler(void);
void USART0_DriverIRQHandler(void)
{
    s_usartIsr(USART0, s_usartHandle[0]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(USART1)
void USART1_DriverIRQHandler(void);
void USART1_DriverIRQHandler(void)
{
    s_usartIsr(USART1, s_usartHandle[1]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(USART2)
void USART2_DriverIRQHandler(void);
void USART2_DriverIRQHandler(void)
{
    s_usartIsr(USART2, s_usartHandle[2]);
    SDK_ISR_EXIT_BARRIER;
}
#endif

#if defined(USART3)
void USART3_DriverIRQHandler(void);
void USART3_DriverIRQHandler(void)
{
    s_usartIsr(USART3, s_usartHandle[3]);
    SDK_ISR_EXIT_BARRIER;
}
#endif
