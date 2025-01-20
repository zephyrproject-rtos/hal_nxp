/*
 * Copyright 2020,2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qsci.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qsci"
#endif

#if defined(QSCI_CTRL3_SBRH_MASK)
#define QSCI_SBR_MAX 0x3FFFFUL /* SBR << 3U + FRAC_SBR */
#else
#define QSCI_SBR_MAX 0xFFFFUL /* SBR << 3U + FRAC_SBR */
#endif

/* QSCI transfer state. */
enum
{
    kQSCI_TxIdle,         /*!< TX idle. */
    kQSCI_TxBusy,         /*!< TX busy. */
    kQSCI_RxIdle,         /*!< RX idle. */
    kQSCI_RxBusy,         /*!< RX busy. */
    kQSCI_RxFramingError, /*!< Rx framing error */
    kQSCI_RxParityError   /*!< Rx parity error */
};

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Writes to TX register using non-blocking method.
 *
 * This function writes data to the TX register directly, upper layer must make
 * sure the TX register is empty or TX FIFO has room before calling this function.
 *
 * @note This function does not check whether all the data has been sent out to bus,
 * so before disabling TX, check kQSCI_TxIdleFlag to ensure the TX is finished.
 *
 * @param base QSCI peripheral base address.
 * @param pu8Data Start address of the data to write.
 * @param u32Length Size of the buffer to be sent.
 */
static void QSCI_WriteNonBlocking(QSCI_Type *base, const uint8_t *pu8Data, uint32_t u32Length);

/*!
 * @brief Reads RX register using non-blocking method.
 *
 * This function reads data from the RX register directly, upper layer must make
 * sure the RX register is full or RX FIFO has data before calling this function.
 *
 * @param base QSCI peripheral base address.
 * @param ou8Data Start address of the buffer to store the received data.
 * @param u32Length Size of the buffer.
 */
static void QSCI_ReadNonBlocking(QSCI_Type *base, uint8_t *pu8Data, uint32_t u32Length);

/*!
 * @brief Calculates baud rate divider.
 *
 * @param u32BaudRateBps QSCI baud rate.
 * @param u32SrcClockHz QSCI clock frequency.
 * @return baud rate divider.
 */
static uint32_t QSCI_CalculateBaudrateConfig(uint32_t u32BaudRateBps, uint32_t u32SrcClockHz);

/*!
 * @brief Sets baud rate divider configuration.
 *
 * @param base QSCI peripheral base address.
 * @param u32Divider baud rate divider.
 */
static void QSCI_ConfigBaudRate(QSCI_Type *base, uint32_t u32Divider);

/*!
 * @brief Checks if the ring buffer is full.
 *
 * @param psHandle QSCI handle pointer.
 * @return True is full, false is not full.
 */
static bool QSCI_TransferIsRxRingBufferFull(qsci_transfer_handle_t *psHandle);

/*!
 * brief QSCI IRQ handle function.
 *
 * This function handles the QSCI transmit and receive IRQ request.
 *
 * param base QSCI peripheral base address.
 * param psHandle QSCI handle pointer.
 */
void QSCI_TransferHandleIRQ(void *handle);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/* Array of QSCI peripheral base address. */
static const QSCI_Type *s_pfQsciBases[] = QSCI_BASE_PTRS;

/*! @brief Pointers to qsci IRQ number for each instance. */
static IRQn_Type const s_eQsciRXIRQs[]    = QSCI_RX_IRQS;
static IRQn_Type const s_eQsciRXErrIRQs[] = QSCI_RX_ERR_IRQS;
static IRQn_Type const s_eQsciTXIRQs[]    = QSCI_TX_IRQS;
#if defined(QSCI_TRIDLE_IRQS)
IRQn_Type const s_eQsciTXIdleIRQs[] = QSCI_TRIDLE_IRQS;
#elif defined(QSCI_TIDLE_IRQS)
IRQn_Type const s_eQsciTXIdleIRQs[] = QSCI_TIDLE_IRQS;
#endif
/* Array of QSCI handle. */
void *s_psQsciHandles[ARRAY_SIZE(s_pfQsciBases)];
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/* Array of QSCI clock name. */
static const clock_ip_name_t s_eQsciClocks[] = QSCI_CLOCKS;
#endif
/* QSCI ISR for transactional APIs. */
qsci_isr_t s_pfQsciIsr;

/*******************************************************************************
 * Code
 ******************************************************************************/
/* ============================================= Functional Group APIs ============================================== */
/*!
 * brief Sets the QSCI configuration structure to default values.
 *
 * The purpose of this API is to initialize the configuration structure to default value for @ref QSCI_Init to use.
 * Use the unchanged structure in @ref QSCI_Init or modify the structure before calling @ref QSCI_Init.
 * This is an example:
 * code
 *   qsci_config_t sConfig;
 *   QSCI_GetDefaultConfig(&sConfig, 115200, 12000000U);
 *   QSCI_Init(QSCI0, &config);
 * endcode
 *
 * param psConfig Pointer to configuration structure.
 * param u32BaudRateBps Baudrate setting.
 * param u32SrcClockHz The clock source frequency for QSCI module.
 */
void QSCI_GetDefaultConfig(qsci_config_t *psConfig, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->eTransferMode     = kQSCI_Normal;
    psConfig->bStopInWaitEnable = false;
    psConfig->eDataBitMode      = kQSCI_Data8Bit;
    psConfig->eWakeupMode       = kQSCI_WakeupOnIdleLine;
    psConfig->ePolarityMode     = kQSCI_PolarityNormal;
    psConfig->eParityMode       = kQSCI_ParityDisabled;
    psConfig->bEnableStopHold   = false;
    psConfig->bEnableTx         = false;
    psConfig->bEnableRx         = false;

    psConfig->bEnableFifo  = true;
    psConfig->bEnableTxDMA = false;
    psConfig->bEnableRxDMA = false;

    psConfig->eTxFifoWatermark = kQSCI_TxWater3Word;
    psConfig->eRxFifoWatermark = kQSCI_RxWater1Word;
    psConfig->u32BaudRateBps   = u32BaudRateBps;
    psConfig->u32SrcClockHz    = u32SrcClockHz;
    psConfig->u8Interrupts     = 0U;
}

/*!
 * brief Initializes the QSCI instance with a user configuration structure.
 *
 * This function configures the QSCI module with the customed settings. User can configure the configuration structure
 * manually or get the default configuration by using the @ref QSCI_GetDefaultConfig function.
 * The example below shows how to use this API to configure QSCI.
 * code
 *   qsci_config_t sConfig;
 *   QSCI_GetDefaultConfig(&sConfig, 115200, 12000000U);
 *   QSCI_Init(QSCI0, &config);
 * endcode
 *
 * param base QSCI peripheral base address.
 * param psConfig Pointer to the user-defined configuration structure.
 * retval kStatus_QSCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * retval kStatus_Success Set baudrate succeeded.
 */
status_t QSCI_Init(QSCI_Type *base, qsci_config_t *psConfig)
{
    assert(NULL != psConfig);
    assert(0U != psConfig->u32BaudRateBps);
    assert(0U != psConfig->u32SrcClockHz);

    QSCI_Reset(base);

    uint32_t u32Div = QSCI_CalculateBaudrateConfig(psConfig->u32BaudRateBps, psConfig->u32SrcClockHz);

    if (u32Div != 0U)
    {
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
        /* Only enable qsci clock if baudrate is within accuracy. */
        CLOCK_EnableClock(s_eQsciClocks[QSCI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
        QSCI_ConfigBaudRate(base, u32Div);
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3% */
        return kStatus_QSCI_BaudrateNotSupport;
    }

    QSCI_SetTransferMode(base, psConfig->eTransferMode);
    QSCI_EnableStopInWait(base, psConfig->bStopInWaitEnable);
    QSCI_Enable9bitMode(base, (psConfig->eDataBitMode == kQSCI_Data9Bit));
    QSCI_SetWakeupMode(base, psConfig->eWakeupMode);
    QSCI_SetPolarityMode(base, psConfig->ePolarityMode);
    QSCI_SetParityMode(base, psConfig->eParityMode);
    QSCI_SetTxWaterMark(base, psConfig->eTxFifoWatermark);
    QSCI_SetRxWaterMark(base, psConfig->eRxFifoWatermark);
    QSCI_EnableFifo(base, psConfig->bEnableFifo);
    QSCI_EnableTxDMA(base, psConfig->bEnableTxDMA);
    QSCI_EnableRxDMA(base, psConfig->bEnableRxDMA);
    QSCI_EnableStopHold(base, psConfig->bEnableStopHold);
    QSCI_EnableInterrupts(base, psConfig->u8Interrupts);

    if (psConfig->bEnableTx)
    {
        QSCI_EnableTx(base, true);
    }
    if (psConfig->bEnableRx)
    {
        QSCI_EnableRx(base, true);
    }

    return kStatus_Success;
}

/*!
 * brief Deinitializes a QSCI instance.
 *
 * This function waits for transmiting complete, then disables TX and RX.
 *
 * param base QSCI peripheral base address.
 */
void QSCI_Deinit(QSCI_Type *base)
{
    if (0U != (base->CTRL1 & QSCI_CTRL1_TE_MASK))
    {
        if (0U != (base->CTRL2 & QSCI_CTRL2_FIFO_EN_MASK))
        {
#if QSCI_RETRY_TIMES
            uint32_t u32WaitTimes = QSCI_RETRY_TIMES;
            while ((0U != (base->CTRL2 & QSCI_CTRL2_TFCNT_MASK)) && (0U != --u32WaitTimes))
            {
            }
            if (0U == u32WaitTimes)
            {
                return kStatus_QSCI_Timeout;
            }
#else
            /* wait data in FIFO shift out */
            while (0U != (base->CTRL2 & QSCI_CTRL2_TFCNT_MASK))
            {
            }
#endif
        }
#if QSCI_RETRY_TIMES
        u32WaitTimes = QSCI_RETRY_TIMES;
        while ((0U == (base->STAT & QSCI_STAT_TIDLE_MASK)) && (0U != --u32WaitTimes))
        {
        }
        if (0U == u32WaitTimes)
        {
            return kStatus_QSCI_Timeout;
        }
#else
        /* wait last byte to shift out at TxD */
        while (0U == (base->STAT & QSCI_STAT_TIDLE_MASK))
        {
        }
#endif
    }

    /* Disable the module. */
    QSCI_Reset(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_eQsciClocks[QSCI_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Clears QSCI status flags.
 *
 * This function clears QSCI status flags. Members in kQSCI_Group0Flags can't be cleared by this function, they are
 * cleared or set by hardware.
 *
 * param base QSCI peripheral base address.
 * param u16StatusFlags The status flag mask, can be a single flag or several flags in #_qsci_status_flags combined by
 * OR.
 */
void QSCI_ClearStatusFlags(QSCI_Type *base, uint16_t u16StatusFlags)
{
    /*
     * 1. kQSCI_Group0Flags can't be cleared by this function, they are handled by HW
     * 2. All kQSCI_Group1Flags will be cleared if any kQSCI_Group1Flags or kQSCI_Group2Flags in the mask
     * 3. kQSCI_Group2Flags can be cleared individually
     */
    uint16_t group12 = (uint16_t)kQSCI_Group1Flags | (uint16_t)kQSCI_Group2Flags;
    if (0U != (u16StatusFlags & group12))
    {
        uint16_t reg = base->STAT;
        reg &= ~((uint16_t)kQSCI_Group2Flags);
        reg |= (u16StatusFlags & ((uint16_t)kQSCI_Group2Flags));
        base->STAT = reg;
        if (0U != (u16StatusFlags & (uint16_t)kQSCI_RxIdleLineFlag))
        {
            (void)base->DATA;
        }
    }
}

/*!
 * brief Enables QSCI interrupts according to the provided mask.
 *
 * This function enables the QSCI interrupts according to the provided mask. The mask is a logical OR of enumeration
 * members in #_qsci_interrupt_enable.
 *
 * param base QSCI peripheral base address.
 * param u8Interrupts The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable
 * combined by OR.
 */
void QSCI_EnableInterrupts(QSCI_Type *base, uint8_t u8Interrupts)
{
    u8Interrupts &= (uint8_t)kQSCI_AllInterruptEnable;

    /* The interrupt mask is combined by control bits from
     * several register: (CTRL1 | (CTRL2 >> 2U)) */

    base->CTRL1 |= ((uint16_t)u8Interrupts & 0xF0U);
    base->CTRL2 |= (((uint16_t)u8Interrupts & 0xFU) << 2U);
}

/*!
 * brief Disables QSCI interrupts according to the provided mask.
 *
 * This function disables the QSCI interrupts according to the provided mask. The mask is a logical OR of enumeration
 * members in #_qsci_interrupt_enable.
 *
 * param base QSCI peripheral base address.
 * param u8Interrupts The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable
 * combined by OR.
 */
void QSCI_DisableInterrupts(QSCI_Type *base, uint8_t u8Interrupts)
{
    u8Interrupts &= (uint8_t)kQSCI_AllInterruptEnable;

    /* The interrupt mask is combined by control bits from
     * several register: (CTRL1 | (CTRL2 >> 2U)) */

    base->CTRL1 &= ~((uint16_t)u8Interrupts & 0xF0U);
    base->CTRL2 &= ~(((uint16_t)u8Interrupts & 0xFU) << 2U);
}

/*!
 * brief Gets the enabled QSCI interrupts.
 *
 * This function gets the enabled QSCI interrupts. The enabled interrupts are returned as the logical OR value of the
 * enumerators #_qsci_interrupt_enable.
 *
 * param base QSCI peripheral base address.
 * return The interrupt source mask, can be a single source or several sources in #_qsci_interrupt_enable combined
 * by OR.
 */
uint8_t QSCI_GetEnabledInterrupts(QSCI_Type *base)
{
    uint16_t u16Interrupts;

    u16Interrupts = base->CTRL1 & 0x00F0U;
    u16Interrupts |= ((base->CTRL2) >> 2U) & 0x000FU;

    u16Interrupts &= (uint16_t)kQSCI_AllInterruptEnable;

    return (uint8_t)u16Interrupts;
}

/*!
 * brief Sets the QSCI instance baud rate.
 *
 * This function configures the QSCI module baud rate. This function can be used to update QSCI module baud rate after
 * the QSCI module is initialized by the @ref QSCI_Init.
 *
 * param base QSCI peripheral base address.
 * param u32BaudRateBps QSCI baudrate to be set.
 * param uint32_t u32SrcClockHz QSCI clock source frequency in Hz.
 * retval kStatus_QSCI_BaudrateNotSupport Baudrate is not supported in the current clock source.
 * retval kStatus_Success Set baudrate succeeded.
 */
status_t QSCI_SetBaudRate(QSCI_Type *base, uint32_t u32BaudRateBps, uint32_t u32SrcClockHz)
{
    status_t status = kStatus_Success;

    uint32_t u32Div = QSCI_CalculateBaudrateConfig(u32BaudRateBps, u32SrcClockHz);

    if (u32Div != 0U)
    {
        QSCI_ConfigBaudRate(base, u32Div);
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3% */
        status = kStatus_QSCI_BaudrateNotSupport;
    }

    return status;
}

/*!
 * brief Writes TX register using a blocking method.
 *
 * This function polls the TX register, waits TX register to be empty or TX FIFO
 * have room then writes data to the TX buffer.
 *
 * param base QSCI peripheral base address.
 * param pu8Data Start address of the data to write.
 * param u32Length Size of the data to write.
 */
void QSCI_WriteBlocking(QSCI_Type *base, const uint8_t *pu8Data, uint32_t u32Length)
{
    while (0U != u32Length--)
    {
#if QSCI_RETRY_TIMES
        uint32_t u32WaitTimes = QSCI_RETRY_TIMES;
        while ((0U == (base->STAT & QSCI_STAT_TDRE_MASK)) && (0U != --u32WaitTimes))
        {
        }
        if (0U == u32WaitTimes)
        {
            return kStatus_QSCI_Timeout;
        }
#else
        while (0U == (base->STAT & QSCI_STAT_TDRE_MASK))
        {
        }
#endif
        base->DATA = *pu8Data++;
    }
#if QSCI_RETRY_TIMES
    u32WaitTimes = QSCI_RETRY_TIMES;
    while ((0U == (base->STAT & QSCI_STAT_TIDLE_MASK)) && (0U != --u32WaitTimes))
    {
    }
    if (0U == u32WaitTimes)
    {
        return kStatus_QSCI_Timeout;
    }
#else
    /* Ensure all the data in the transmit buffer are sent out to bus. */
    while (0U == (base->STAT & QSCI_STAT_TIDLE_MASK))
    {
    }
#endif
}

/*!
 * brief Reads RX data register using a blocking method.
 *
 * This function polls the RX register, waits RX register to be full or RX FIFO
 * have pu8Data, then reads data from the RX register.
 *
 * param base QSCI peripheral base address.
 * param pu8Data Start address of the buffer to store the received data.
 * param u32Length Size of the buffer.
 * retval kStatus_Fail Receiver error occurred while receiving data.
 * retval kStatus_QSCI_RxHardwareOverrun Receiver overrun occurred while receiving data
 * retval kStatus_QSCI_NoiseError Noise error occurred while receiving data
 * retval kStatus_QSCI_FramingError error occurred while receiving data
 * retval kStatus_QSCI_ParityError Parity error occurred while receiving data
 * retval kStatus_Success Successfully received all data.
 */
status_t QSCI_ReadBlocking(QSCI_Type *base, uint8_t *pu8Data, uint32_t u32Length)
{
    assert(pu8Data != NULL);

    status_t status = kStatus_Success;
    uint16_t statusFlag;

    while ((u32Length--) != 0U)
    {
        while (((base->STAT & QSCI_STAT_RDRF_MASK) == 0U) && ((base->CTRL2 & QSCI_CTRL2_RFCNT_MASK) == 0U))
        {
            statusFlag = QSCI_GetStatusFlags(base);

            if (0U != (statusFlag & (uint16_t)kQSCI_Group1Flags))
            {
                QSCI_ClearStatusFlags(base, statusFlag);
                if (0U != (statusFlag & (uint16_t)kQSCI_RxOverrunFlag))
                {
                    status = kStatus_QSCI_RxHardwareOverrun;
                    /* Other error flags(FE, NF, and PF) are prevented from setting once OR is set, no need to check
                     * other error flags*/
                    break;
                }

                if (0U != (statusFlag & (uint16_t)kQSCI_RxParityErrorFlag))
                {
                    status = kStatus_QSCI_ParityError;
                }

                if (0U != (statusFlag & (uint16_t)kQSCI_RxFrameErrorFlag))
                {
                    status = kStatus_QSCI_FramingError;
                }

                if (0U != (statusFlag & (uint16_t)kQSCI_RxNoiseFlag))
                {
                    status = kStatus_QSCI_NoiseError;
                }

                break;
            }
        }
        if (kStatus_Success == status)
        {
            *pu8Data++ = (uint8_t)base->DATA;
        }
        else
        {
            break;
        }
    }

    return status;
}

/* ============================================ Transactional Group APIs ============================================ */
/*!
 * brief Initializes the QSCI handle.
 *
 * This function initializes the QSCI handle which can be used for other QSCI
 * transactional APIs. Usually, for a specified QSCI instance,
 * call this API once to get the initialized handle.
 *
 * param base QSCI peripheral base address.
 * param psHandle QSCI handle pointer.
 * param pfCallback The callback function.
 * param pUserData The parameter of the callback function.
 */
void QSCI_TransferCreateHandle(QSCI_Type *base,
                               qsci_transfer_handle_t *psHandle,
                               qsci_transfer_callback_t pfCallback,
                               void *pUserData)
{
    assert(NULL != psHandle);

    uint16_t instance;

    /* Zero the handle. */
    (void)memset((void *)psHandle, 0, sizeof(*psHandle));

    /* Set the TX/RX state. */
    psHandle->u8RxState = (uint8_t)kQSCI_RxIdle;
    psHandle->u8TxState = (uint8_t)kQSCI_TxIdle;

    /* Set the callback and user data and base pointer. */
    psHandle->pfCallback = pfCallback;
    psHandle->pUserData  = pUserData;
    psHandle->base       = base;

    /* Get instance from peripheral base address. */
    instance = QSCI_GetInstance(base);

    s_pfQsciIsr = QSCI_TransferHandleIRQ;

    /* Save the handle in global variables to support the double weak mechanism. */
    s_psQsciHandles[instance] = (void *)psHandle;

    /* Enable global IRQs. */
    (void)EnableIRQ(s_eQsciRXIRQs[instance]);
    (void)EnableIRQ(s_eQsciRXErrIRQs[instance]);
    (void)EnableIRQ(s_eQsciTXIRQs[instance]);
    (void)EnableIRQ(s_eQsciTXIdleIRQs[instance]);
}

/*!
 * brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific QSCI handle.
 *
 * When the RX ring buffer is used, data received are stored into the ring buffer even when the
 * user doesn't call the QSCI_TransferReceiveNonBlocking() API. If data is already received
 * in the ring buffer, the user can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if u16RxRingBufferSize is 32, only 31 bytes are used for saving data.
 *
 * param psHandle QSCI handle pointer.
 * param pu8RxRingBuffer Start address of the ring buffer for background receiving. Pass NULL to disable the ring
 * buffer. param u16RxRingBufferSize Size of the ring buffer.
 */
void QSCI_TransferStartRingBuffer(qsci_transfer_handle_t *psHandle,
                                  uint8_t *pu8RxRingBuffer,
                                  uint16_t u16RxRingBufferSize)
{
    assert(NULL != psHandle);
    assert(NULL != pu8RxRingBuffer);

    /* Setup the ringbuffer address */
    psHandle->pu8RxRingBuffer     = pu8RxRingBuffer;
    psHandle->u16RxRingBufferSize = u16RxRingBufferSize;
    psHandle->u16RxRingBufferHead = 0U;
    psHandle->u16RxRingBufferTail = 0U;

    /* Enable rx. */
    QSCI_EnableRx(psHandle->base, true);

    /* Enable the interrupt to accept the data when user need the ring buffer. */
    QSCI_EnableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
}

/*!
 * brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * param psHandle QSCI handle pointer.
 */
void QSCI_TransferStopRingBuffer(qsci_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    if (psHandle->u8RxState == (uint8_t)kQSCI_RxIdle)
    {
        QSCI_DisableInterrupts(psHandle->base,
                               (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
    }

    psHandle->pu8RxRingBuffer     = NULL;
    psHandle->u16RxRingBufferSize = 0U;
    psHandle->u16RxRingBufferHead = 0U;
    psHandle->u16RxRingBufferTail = 0U;
}

/*!
 * brief Get the ring buffer valid data length.
 *
 * param psHandle QSCI handle pointer.
 * return Valid data length in ring buffer.
 */
uint16_t QSCI_TransferGetRxRingBufferLength(qsci_transfer_handle_t *psHandle)
{
    uint16_t u16Size;
    uint16_t u16RxRingBufferHead, u16RxRingBufferTail;

    assert(NULL != psHandle);

    u16RxRingBufferHead = psHandle->u16RxRingBufferHead;
    u16RxRingBufferTail = psHandle->u16RxRingBufferTail;

    if (u16RxRingBufferTail > u16RxRingBufferHead)
    {
        u16Size = (uint16_t)u16RxRingBufferHead + psHandle->u16RxRingBufferSize - (uint16_t)u16RxRingBufferTail;
    }
    else
    {
        u16Size = (uint16_t)u16RxRingBufferHead - (uint16_t)u16RxRingBufferTail;
    }

    return u16Size;
}

/*!
 * brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function, which
 * returns directly without waiting for all data to be written to the TX register. When
 * all data is sent out, the QSCI driver calls the callback function and passes the
 * kStatus_QSCI_TxIdle as status parameter.
 *
 * param psHandle QSCI handle pointer.
 * param psTransfer QSCI transfer structure. See #qsci_transfer_t.
 * retval kStatus_Success Successfully start the data transmission.
 * retval kStatus_QSCI_TxBusy Previous transmission still not finished; data not all written to TX register yet.
 */
status_t QSCI_TransferSendNonBlocking(qsci_transfer_handle_t *psHandle, qsci_transfer_t *psTransfer)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);
    assert(0U != psTransfer->u32DataSize);
    assert(NULL != psTransfer->pu8Data);

    status_t status;

    /* Return error if current TX busy. */
    if ((uint8_t)kQSCI_TxBusy == psHandle->u8TxState)
    {
        status = kStatus_QSCI_TxBusy;
    }
    else
    {
        psHandle->pu8TxData          = psTransfer->pu8Data;
        psHandle->u32TxRemainingSize = psTransfer->u32DataSize;
        psHandle->u32TxDataSize      = psTransfer->u32DataSize;
        psHandle->u8TxState          = (uint8_t)kQSCI_TxBusy;

        /* Enable tx. */
        QSCI_EnableTx(psHandle->base, true);

        /* Enable transmitter interrupt. */
        QSCI_EnableInterrupts(psHandle->base, (uint8_t)kQSCI_TxEmptyInterruptEnable);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt-driven data sending. The user can get the remainBytes to find out
 * how many bytes are not sent out.
 *
 * param psHandle QSCI handle pointer.
 */
void QSCI_TransferAbortSend(qsci_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    QSCI_DisableInterrupts(psHandle->base,
                           (uint8_t)kQSCI_TxEmptyInterruptEnable | (uint8_t)kQSCI_TxIdleInterruptEnable);

    psHandle->u32TxRemainingSize = 0U;
    psHandle->u8TxState          = (uint8_t)kQSCI_TxIdle;

    /* Disable tx. */
    QSCI_EnableTx(psHandle->base, false);
}

/*!
 * brief Gets the number of bytes sent out to bus.
 *
 * This function gets the number of bytes sent out to bus by using the interrupt method.
 *
 * param psHandle QSCI handle pointer.
 * param pu32Count Send bytes count.
 * retval kStatus_NoTransferInProgress No send in progress.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t QSCI_TransferGetSendCount(qsci_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_TxIdle == psHandle->u8TxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *pu32Count = psHandle->u32TxDataSize - psHandle->u32TxRemainingSize;

    return kStatus_Success;
}

/*!
 * brief Receives a buffer of data using an interrupt method.
 *
 * This function receives data using an interrupt method. This is a non-blocking function, which
 *  returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in the ring buffer is copied and
 * the parameter pu32ReceivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in the ring buffer is not enough to read, the receive
 * request is saved by the QSCI driver. When the new data arrives, the receive request
 * is serviced first. When all data is received, the QSCI driver notifies the upper layer
 * through a callback function and passes the status parameter kStatus_QSCI_RxIdle.
 * For example, the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer.
 * The 5 bytes are copied to the psTransfer->pu8Data and this function returns with the
 * parameter pu32ReceivedBytes set to 5. For the left 5 bytes, newly arrived data is
 * saved from the psTransfer->pu8Data[5]. When 5 bytes are received, the QSCI driver notifies the upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to the psTransfer->pu8Data. When all data is received, the upper layer is notified.
 *
 * param psHandle QSCI handle pointer.
 * param psTransfer QSCI transfer structure, see #qsci_transfer_t.
 * param pu32ReceivedBytes Bytes received from the ring buffer directly.
 * retval kStatus_Success Successfully queue the transfer into transmit queue.
 * retval #kStatus_QSCI_RxBusy Previous receive request is not finished.
 */
status_t QSCI_TransferReceiveNonBlocking(qsci_transfer_handle_t *psHandle,
                                         qsci_transfer_t *psTransfer,
                                         uint32_t *pu32ReceivedBytes)
{
    assert(NULL != psHandle);
    assert(NULL != psTransfer);
    assert(NULL != psTransfer->pu8Data);
    assert(0U != psTransfer->u32DataSize);

    uint32_t i;
    status_t status;
    /* How many bytes to copy from ring buffer to user memory. */
    uint32_t u32BytesToCopy = 0U;
    /* How many bytes to receive. */
    uint32_t u32BytesToReceive;
    /* How many bytes currently have received. */
    uint32_t u32BytesCurrentReceived;
    /* Enable rx. */
    QSCI_EnableRx(psHandle->base, true);

    /* How to get data:
       1. If RX ring buffer is not enabled, then save psTransfer->pu8Data and psTransfer->u32DataSize
          to qsci handle, enable interrupt to store received data to psTransfer->pu8Data. When
          all data received, trigger callback.
       2. If RX ring buffer is enabled and not empty, get data from ring buffer first.
          If there are enough data in ring buffer, copy them to psTransfer->pu8Data and return.
          If there are not enough data in ring buffer, copy all of them to psTransfer->pu8Data,
          save the psTransfer->pu8Data remained empty space to qsci handle, receive data
          to this empty space and trigger callback when finished. */

    if ((uint8_t)kQSCI_RxBusy == psHandle->u8RxState)
    {
        status = kStatus_QSCI_RxBusy;
    }
    else
    {
        u32BytesToReceive       = psTransfer->u32DataSize;
        u32BytesCurrentReceived = 0U;

        /* If RX ring buffer is used. */
        if (psHandle->pu8RxRingBuffer != NULL)
        {
            /* Disable QSCI RX IRQ, protect ring buffer. */
            QSCI_DisableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable);

            /* How many bytes in RX ring buffer currently. */
            u32BytesToCopy = QSCI_TransferGetRxRingBufferLength(psHandle);

            if (u32BytesToCopy != 0U)
            {
                u32BytesToCopy = MIN(u32BytesToReceive, u32BytesToCopy);

                u32BytesToReceive -= u32BytesToCopy;

                /* Copy data from ring buffer to user memory. */
                for (i = 0U; i < u32BytesToCopy; i++)
                {
                    psTransfer->pu8Data[u32BytesCurrentReceived++] =
                        psHandle->pu8RxRingBuffer[psHandle->u16RxRingBufferTail];

                    /* Wrap to 0. Not use modulo (%) because it might be large and slow. */
                    if ((psHandle->u16RxRingBufferTail + (uint16_t)1U) == psHandle->u16RxRingBufferSize)
                    {
                        psHandle->u16RxRingBufferTail = 0U;
                    }
                    else
                    {
                        psHandle->u16RxRingBufferTail++;
                    }
                }
            }

            /* If ring buffer does not have enough data, still need to read more data. */
            if (u32BytesToReceive != 0U)
            {
                /* No data in ring buffer, save the request to QSCI handle. */
                psHandle->pu8RxData          = psTransfer->pu8Data + u32BytesCurrentReceived;
                psHandle->u32RxRemainingSize = u32BytesToReceive;
                psHandle->u32RxDataSize      = u32BytesToReceive;
                psHandle->u8RxState          = (uint8_t)kQSCI_RxBusy;
            }

            /* Enable QSCI RX IRQ if previously enabled. */
            QSCI_EnableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable);

            /* Call user callback since all data are received. */
            if (0U == u32BytesToReceive)
            {
                psHandle->busStatus = kStatus_QSCI_RxIdle;
                if (psHandle->pfCallback != NULL)
                {
                    psHandle->pfCallback(psHandle);
                }
            }
        }
        /* Ring buffer not used. */
        else
        {
            psHandle->pu8RxData          = psTransfer->pu8Data + u32BytesCurrentReceived;
            psHandle->u32RxRemainingSize = u32BytesToReceive;
            psHandle->u32RxDataSize      = u32BytesToReceive;
            psHandle->u8RxState          = (uint8_t)kQSCI_RxBusy;

            /* Enable RX/Rx overrun/framing error/idle line interrupt. */
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
            QSCI_EnableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable |
                                                      (uint8_t)kQSCI_RxErrorInterruptEnable |
                                                      (uint8_t)kQSCI_RxIdleLineInterruptEnable);
#else
            QSCI_EnableInterrupts(psHandle->base,
                                  (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
#endif
        }

        /* Return how many bytes have read. */
        if (pu32ReceivedBytes != NULL)
        {
            *pu32ReceivedBytes = u32BytesCurrentReceived;
        }

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Aborts the interrupt-driven data receiving.
 *
 * This function aborts the interrupt-driven data receiving. The user can get the remainBytes to know
 * how many bytes are not received yet.
 *
 * param psHandle QSCI handle pointer.
 */
void QSCI_TransferAbortReceive(qsci_transfer_handle_t *psHandle)
{
    assert(NULL != psHandle);

    /* Only abort the receive to psHandle->pu8RxData, the RX ring buffer is still working. */
    if (NULL == psHandle->pu8RxRingBuffer)
    {
        /* Disable RX interrupt. */
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
        QSCI_DisableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable |
                                                   (uint8_t)kQSCI_RxErrorInterruptEnable |
                                                   (uint8_t)kQSCI_RxIdleLineInterruptEnable);
#else
        QSCI_DisableInterrupts(psHandle->base,
                               (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
#endif
    }

    psHandle->u32RxRemainingSize = 0U;
    psHandle->u8RxState          = (uint8_t)kQSCI_RxIdle;

    /* Disable rx. */
    QSCI_EnableRx(psHandle->base, false);
}

/*!
 * brief Gets the number of bytes that have been received.
 *
 * This function gets the number of bytes that have been received.
 *
 * param handle QSCI handle pointer.
 * param pu32Count Receive bytes count.
 * retval kStatus_NoTransferInProgress No receive in progress.
 * retval kStatus_InvalidArgument Parameter is invalid.
 * retval kStatus_Success Get successfully through the parameter \p count;
 */
status_t QSCI_TransferGetReceivedCount(qsci_transfer_handle_t *psHandle, uint32_t *pu32Count)
{
    assert(NULL != psHandle);
    assert(NULL != pu32Count);

    if ((uint8_t)kQSCI_RxIdle == psHandle->u8RxState)
    {
        return kStatus_NoTransferInProgress;
    }

    if (NULL == pu32Count)
    {
        return kStatus_InvalidArgument;
    }

    *pu32Count = psHandle->u32RxDataSize - psHandle->u32RxRemainingSize;

    return kStatus_Success;
}

/* =============================================== Internal Functions =============================================== */

static uint32_t QSCI_CalculateBaudrateConfig(uint32_t u32BaudRateBps, uint32_t u32SrcClockHz)
{
    assert(0U != u32BaudRateBps);
    uint32_t u32Div;
    uint32_t u32BaudDiff;
    /* Calculate baudrate divider, the formula is u32BaudRateBps * 2U = src/(SBR << 3U + frac)
       divider = (SBR << 3U + frac) */
    u32Div = u32SrcClockHz / (u32BaudRateBps * 2U);
    /* Calculate baudrate error */
    u32BaudDiff = u32SrcClockHz / (u32Div * 2U) - u32BaudRateBps;
    /* Check to see if actual baud rate is within 3% of desired baud rate
     * based on the best calculate divider value */
    if ((u32Div <= QSCI_SBR_MAX) && (u32BaudDiff < (uint32_t)((u32BaudRateBps / 100U) * 3U)))
    {
        return u32Div;
    }
    else
    {
        /* Unacceptable baud rate difference of more than 3% */
        return 0U;
    }
}

static void QSCI_ConfigBaudRate(QSCI_Type *base, uint32_t u32Divider)
{
    uint16_t ctrl1 = base->CTRL1;
    /* If tx is enabled, wait until transmitter is idle. */
    if (0U != (base->CTRL1 & QSCI_CTRL1_TE_MASK))
    {
        if (0U != (base->CTRL2 & QSCI_CTRL2_FIFO_EN_MASK))
        {
#if QSCI_RETRY_TIMES
            uint32_t u32WaitTimes = QSCI_RETRY_TIMES;
            while ((0U != (base->CTRL2 & QSCI_CTRL2_TFCNT_MASK)) && (0U != --u32WaitTimes))
            {
            }
            if (0U == u32WaitTimes)
            {
                return kStatus_QSCI_Timeout;
            }
#else
            /* wait data in FIFO shift out */
            while (0U != (base->CTRL2 & QSCI_CTRL2_TFCNT_MASK))
            {
            }
#endif
        }
#if QSCI_RETRY_TIMES
        u32WaitTimes = QSCI_RETRY_TIMES;
        while ((0U == (base->STAT & QSCI_STAT_TIDLE_MASK)) && (0U != --u32WaitTimes))
        {
        }
        if (0U == u32WaitTimes)
        {
            return kStatus_QSCI_Timeout;
        }
#else
        /* wait last byte to shift out at TxD */
        while (0U == (base->STAT & QSCI_STAT_TIDLE_MASK))
        {
        }
#endif
    }
    /* Hold QSCI in standby state during configuration */
    base->CTRL1 |= QSCI_CTRL1_RWU_MASK;
    base->CTRL1 &= ~(QSCI_CTRL1_TE_MASK | QSCI_CTRL1_RE_MASK);

    /* Configure baud rate */
    base->RATE = (uint16_t)u32Divider;
#if defined(QSCI_CTRL3_SBRH_MASK)
    base->CTRL3 = QSCI_CTRL3_SBRH(u32Divider >> 16U);
#endif

    /* Re-enable transmitter and receiver */
    base->CTRL1 = ctrl1;
}

static void QSCI_WriteNonBlocking(QSCI_Type *base, const uint8_t *pu8Data, uint32_t u32Length)
{
    uint32_t i;

    /* The Non Blocking write data API assume user have ensured there is enough space in
    peripheral to write. */
    for (i = 0U; i < u32Length; i++)
    {
        base->DATA = pu8Data[i];
    }
}

static void QSCI_ReadNonBlocking(QSCI_Type *base, uint8_t *pu8Data, uint32_t u32Length)
{
    assert(NULL != pu8Data);

    uint32_t i;

    /* The Non Blocking read data API assume user have ensured there is enough data in
    peripheral to read. */
    for (i = 0U; i < u32Length; i++)
    {
        pu8Data[i] = (uint8_t)base->DATA;
    }
}

static bool QSCI_TransferIsRxRingBufferFull(qsci_transfer_handle_t *psHandle)
{
    bool full = false;
    assert(NULL != psHandle);

    if (QSCI_TransferGetRxRingBufferLength(psHandle) == (psHandle->u16RxRingBufferSize - 1U))
    {
        full = true;
    }

    return full;
}

/*!
 * brief Get the QSCI instance from peripheral base address.
 *
 * param base QSCI peripheral base address.
 * return QSCI instance.
 */
uint16_t QSCI_GetInstance(QSCI_Type *base)
{
    uint16_t instance;
    uint16_t qsciArrayCount = ((uint16_t)sizeof(s_pfQsciBases) / (uint16_t)sizeof(s_pfQsciBases[0]));

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < qsciArrayCount; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_pfQsciBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < qsciArrayCount);

    return instance;
}

void QSCI_TransferHandleIRQ(void *handle)
{
    assert(NULL != handle);

    qsci_transfer_handle_t *psHandle = (qsci_transfer_handle_t *)handle;
    QSCI_Type *base                  = psHandle->base;
    uint8_t u8Tmpdata;
    uint8_t u8TempCount;
    uint16_t count;
    uint16_t status = QSCI_GetStatusFlags(base);

    /* If RX framing error */
    if (((uint16_t)kQSCI_RxFrameErrorFlag & status) != 0U)
    {
        /* read the STAT & DATA register and then write STAT to clear the flag */
        volatile uint16_t tmp = base->DATA;
        QSCI_ClearStatusFlags(base, (uint16_t)kQSCI_RxFrameErrorFlag);

        psHandle->u8RxState          = (uint8_t)kQSCI_RxFramingError;
        psHandle->u32RxRemainingSize = 0U;
        psHandle->busStatus          = kStatus_QSCI_FramingError;
        /* Trigger callback. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle);
        }
    }

    /* If RX parity error */
    if (((uint16_t)kQSCI_RxParityErrorFlag & status) != 0U)
    {
        /* read the STAT & DATA register and then write STAT to clear the flag */
        volatile uint16_t tmp = base->DATA;
        QSCI_ClearStatusFlags(base, (uint16_t)kQSCI_RxParityErrorFlag);

        psHandle->u8RxState          = (uint8_t)kQSCI_RxParityError;
        psHandle->u32RxRemainingSize = 0U;
        psHandle->busStatus          = kStatus_QSCI_ParityError;
        /* Trigger callback. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle);
        }
    }

    /* If RX overrun. */
    if (((uint16_t)kQSCI_RxOverrunFlag & status) != 0U)
    {
        /* read the STAT & DATA register and then write STAT to clear the flag */
        volatile uint16_t tmp = base->DATA;
        QSCI_ClearStatusFlags(base, (uint16_t)kQSCI_RxOverrunFlag);
        psHandle->busStatus = kStatus_QSCI_RxHardwareOverrun;
        /* Trigger callback. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle);
        }
    }

    /* If RX Noise detected. */
    if (((uint16_t)kQSCI_RxNoiseFlag & status) != 0U)
    {
        /* read the STAT & DATA register and then write STAT to clear the flag */
        volatile uint16_t tmp = base->DATA;
        QSCI_ClearStatusFlags(base, (uint16_t)kQSCI_RxNoiseFlag);
        psHandle->busStatus = kStatus_QSCI_NoiseError;
        /* Trigger callback. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle);
        }
    }
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
    /* If IDLE line was detected. */
    if ((((uint16_t)kQSCI_RxIdleLineFlag & status) != 0U) && ((QSCI_CTRL2_RIIE_MASK & base->CTRL2) != 0U))
    {
        /* If still some data in the FIFO, read out these data to user data buffer. */
        count = (uint8_t)((base->CTRL2 & QSCI_CTRL2_RFCNT_MASK) >> QSCI_CTRL2_RFCNT_SHIFT);

        if (0U == count)
        {
            /* Maybe FIFO is disabled, check again */
            if ((base->STAT & QSCI_STAT_RDRF_MASK) != 0U)
            {
                count = 1U;
            }
        }

        /* If psHandle->u32RxRemainingSize is not 0, first save data to psHandle->pu8RxData. */
        while ((count != 0U) && (psHandle->u32RxRemainingSize != 0U))
        {
            u8TempCount = (uint8_t)MIN(psHandle->u32RxRemainingSize, (uint32_t)count);

            /* Using non block API to read the data from the registers. */
            QSCI_ReadNonBlocking(base, psHandle->pu8RxData, u8TempCount);
            psHandle->pu8RxData += u8TempCount;
            psHandle->u32RxRemainingSize -= u8TempCount;
            count -= u8TempCount;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (0U == psHandle->u32RxRemainingSize)
            {
                psHandle->u8RxState = (uint8_t)kQSCI_RxIdle;

                /* Disable RX received full and error interrupt */
                QSCI_DisableInterrupts(base,
                                       (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
                psHandle->busStatus = kStatus_QSCI_RxIdle;
                if (psHandle->pfCallback != NULL)
                {
                    psHandle->pfCallback(psHandle);
                }
            }
        }

        /* To clear IDLE flag, read QSCI status STAT with IDLE set and then read DATA.*/
        while ((QSCI_STAT_RIDLE_MASK & base->STAT) != 0U)
        {
            (void)base->DATA;
        }

        /* If u32RxRemainingSize is 0, disable idle line interrupt.*/
        if (0U == (psHandle->u32RxRemainingSize))
        {
            QSCI_DisableInterrupts(base, (uint8_t)kQSCI_RxIdleLineInterruptEnable);
        }

        psHandle->busStatus = kStatus_QSCI_IdleLineDetected;
        /* If callback is not NULL and u32RxRemainingSize is not 0. */
        if ((psHandle->pfCallback != NULL) && (psHandle->u32RxRemainingSize != 0U))
        {
            psHandle->pfCallback(psHandle);
        }
    }
#endif

    /* Receive data register full */
    if ((((uint16_t)kQSCI_RxDataRegFullFlag & status) != 0U) && ((QSCI_CTRL1_RFIE_MASK & base->CTRL1) != 0U))
    {
        count = (base->CTRL2 & QSCI_CTRL2_RFCNT_MASK) >> QSCI_CTRL2_RFCNT_SHIFT;

        if (0U == count)
        {
            /* Maybe FIFO is disabled, check again */
            if ((base->STAT & QSCI_STAT_RDRF_MASK) != 0U)
            {
                count = 1U;
            }
        }

        /* If psHandle->u32RxRemainingSize is not 0, first save data to psHandle->pu8RxData. */
        while ((count != 0U) && (psHandle->u32RxRemainingSize != 0U))
        {
            u8TempCount = (uint8_t)MIN(psHandle->u32RxRemainingSize, (uint32_t)count);

            /* Using non block API to read the data from the registers. */
            QSCI_ReadNonBlocking(base, psHandle->pu8RxData, u8TempCount);
            psHandle->pu8RxData += u8TempCount;
            psHandle->u32RxRemainingSize -= u8TempCount;
            count -= u8TempCount;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (0U == psHandle->u32RxRemainingSize)
            {
                psHandle->u8RxState = (uint8_t)kQSCI_RxIdle;
                psHandle->busStatus = kStatus_QSCI_RxIdle;

                if (psHandle->pfCallback != NULL)
                {
                    psHandle->pfCallback(psHandle);
                }
            }
        }

        /* If use RX ring buffer, receive data to ring buffer. */
        if (psHandle->pu8RxRingBuffer != NULL)
        {
            while (0U != count--)
            {
                /* If RX ring buffer is full, trigger callback to notify over run. */
                if (QSCI_TransferIsRxRingBufferFull(psHandle))
                {
                    psHandle->busStatus = kStatus_QSCI_RxRingBufferOverrun;
                    if (psHandle->pfCallback != NULL)
                    {
                        psHandle->pfCallback(psHandle);
                    }
                }

                /* If ring buffer is still full after callback function, the oldest data is overridden. */
                if (QSCI_TransferIsRxRingBufferFull(psHandle))
                {
                    /* Increase psHandle->u16RxRingBufferTail to make room for new data. */
                    if ((uint32_t)psHandle->u16RxRingBufferTail + 1U == psHandle->u16RxRingBufferSize)
                    {
                        psHandle->u16RxRingBufferTail = 0U;
                    }
                    else
                    {
                        psHandle->u16RxRingBufferTail++;
                    }
                }

                /* Read data. */
                u8Tmpdata                                                = (uint8_t)base->DATA;
                psHandle->pu8RxRingBuffer[psHandle->u16RxRingBufferHead] = u8Tmpdata;

                /* Increase psHandle->u16RxRingBufferHead. */
                if ((uint32_t)psHandle->u16RxRingBufferHead + 1U == psHandle->u16RxRingBufferSize)
                {
                    psHandle->u16RxRingBufferHead = 0U;
                }
                else
                {
                    psHandle->u16RxRingBufferHead++;
                }
            }
        }
        else if (0U == psHandle->u32RxRemainingSize)
        {
            /* Disable RX interrupt. */
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
            QSCI_DisableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable |
                                                       (uint8_t)kQSCI_RxErrorInterruptEnable |
                                                       (uint8_t)kQSCI_RxIdleLineInterruptEnable);
#else
            QSCI_DisableInterrupts(psHandle->base,
                                   (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
#endif
        }
        else
        {
        }
    }

    /* If framing error or parity error happened, stop the RX interrupt when use no ring buffer */
    if (((psHandle->u8RxState == (uint8_t)kQSCI_RxFramingError) ||
         (psHandle->u8RxState == (uint8_t)kQSCI_RxParityError)) &&
        (NULL == psHandle->pu8RxRingBuffer))
    {
        /* Disable RX interrupt. */
#if defined(FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT) && FSL_FEATURE_QSCI_HAS_RX_IDLE_INTERRUPT
        QSCI_DisableInterrupts(psHandle->base, (uint8_t)kQSCI_RxFullInterruptEnable |
                                                   (uint8_t)kQSCI_RxErrorInterruptEnable |
                                                   (uint8_t)kQSCI_RxIdleLineInterruptEnable);
#else
        QSCI_DisableInterrupts(psHandle->base,
                               (uint8_t)kQSCI_RxFullInterruptEnable | (uint8_t)kQSCI_RxErrorInterruptEnable);
#endif
    }

    /* Send data register empty and the interrupt is enabled. */
    if ((((uint16_t)kQSCI_TxDataRegEmptyFlag & status) != 0U) && ((base->CTRL1 & QSCI_CTRL1_TEIE_MASK) != 0U))
    {
        /* Get the bytes that available at this moment. */
        if (0U != (base->CTRL2 & QSCI_CTRL2_FIFO_EN_MASK))
        {
            count = (base->CTRL2 & QSCI_CTRL2_TFCNT_MASK) >> QSCI_CTRL2_TFCNT_SHIFT;
            count = (uint8_t)FSL_FEATURE_QSCI_FIFO_SIZEn(base) - count;
        }
        else
        {
            count = 1U;
        }

        while ((count != 0U) && (psHandle->u32TxRemainingSize != 0U))
        {
            u8TempCount = (uint8_t)MIN(psHandle->u32TxRemainingSize, (uint32_t)count);

            /* Using non block API to write the data to the registers. */
            QSCI_WriteNonBlocking(base, psHandle->pu8TxData, u8TempCount);
            psHandle->pu8TxData += u8TempCount;
            psHandle->u32TxRemainingSize -= u8TempCount;
            count -= u8TempCount;

            /* If all the data are written to data register, TX finished. */
            if (0U == psHandle->u32TxRemainingSize)
            {
                psHandle->u8TxState = (uint8_t)kQSCI_TxIdle;
                QSCI_DisableInterrupts(base, (uint8_t)kQSCI_TxEmptyInterruptEnable);
                QSCI_EnableInterrupts(base, (uint8_t)kQSCI_TxIdleInterruptEnable);
            }
        }
    }

    /* Transmission complete and the interrupt is enabled. */
    if ((0U != ((uint16_t)kQSCI_TxIdleFlag & status)) && (0U != (base->CTRL1 & QSCI_CTRL1_TIIE_MASK)) &&
        (psHandle->u8TxState == (uint8_t)kQSCI_TxIdle))
    {
        /* Disable transmission complete interrupt. */
        QSCI_DisableInterrupts(base, (uint8_t)kQSCI_TxIdleInterruptEnable);
        psHandle->busStatus = kStatus_QSCI_TxIdle;
        /* Trigger callback. */
        if (psHandle->pfCallback != NULL)
        {
            psHandle->pfCallback(psHandle);
        }
    }
}

#if defined(QSCI0)
void QSCI0_RERR_DriverIRQHandler(void);
void QSCI0_RERR_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[0]);
}
void QSCI0_RCV_DriverIRQHandler(void);
void QSCI0_RCV_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[0]);
}
#if defined(QSCI_TRIDLE_IRQS)
void QSCI0_TRIDLE_DriverIRQHandler(void);
void QSCI0_TRIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[0]);
}
#elif defined(QSCI_TIDLE_IRQS)
void QSCI0_TIDLE_DriverIRQHandler(void);
void QSCI0_TIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[0]);
}
#endif
void QSCI0_TDRE_DriverIRQHandler(void);
void QSCI0_TDRE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[0]);
}
#endif /*defined(QSCI0)*/

#if defined(QSCI1)
void QSCI1_RERR_DriverIRQHandler(void);
void QSCI1_RERR_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[1]);
}
void QSCI1_RCV_DriverIRQHandler(void);
void QSCI1_RCV_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[1]);
}
#if defined(QSCI_TRIDLE_IRQS)
void QSCI1_TRIDLE_DriverIRQHandler(void);
void QSCI1_TRIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[1]);
}
#elif defined(QSCI_TIDLE_IRQS)
void QSCI1_TIDLE_DriverIRQHandler(void);
void QSCI1_TIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[1]);
}
#endif
void QSCI1_TDRE_DriverIRQHandler(void);
void QSCI1_TDRE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[1]);
}
#endif /*defined(QSCI1)*/

#if defined(QSCI2)
void QSCI2_RERR_DriverIRQHandler(void);
void QSCI2_RERR_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[2]);
}
void QSCI2_RCV_DriverIRQHandler(void);
void QSCI2_RCV_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[2]);
}
#if defined(QSCI_TRIDLE_IRQS)
void QSCI2_TRIDLE_DriverIRQHandler(void);
void QSCI2_TRIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[2]);
}
#elif defined(QSCI_TIDLE_IRQS)
void QSCI2_TIDLE_DriverIRQHandler(void);
void QSCI2_TIDLE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[2]);
}
#endif
void QSCI2_TDRE_DriverIRQHandler(void);
void QSCI2_TDRE_DriverIRQHandler(void)
{
    s_pfQsciIsr(s_psQsciHandles[2]);
}
#endif /*defined(QSCI2)*/
