/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_flexio_t-format.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_t_format"
#endif

/*<! @brief a-format transfer state. */
enum _flexio_t_format_transfer_states
{
    kFLEXIO_T_FORMAT_TxIdle, /* TX idle. */
    kFLEXIO_T_FORMAT_TxBusy, /* TX busy. */
    kFLEXIO_T_FORMAT_RxIdle, /* RX idle. */
    kFLEXIO_T_FORMAT_RxBusy  /* RX busy. */
};

void FLEXIO_T_Format_TransferHandleIRQ(void *type, void *handle);
/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Codes
 ******************************************************************************/

static uint32_t FLEXIO_T_Format_GetInstance(FLEXIO_T_FORMAT_Type *base)
{
    return FLEXIO_GetInstance(base->flexioBase);
}

static status_t FLEXIO_T_Format_CheckBaudRate(uint32_t baudRate_Bps, uint32_t srcClock_Hz, uint16_t timerDiv)
{
    uint32_t calculatedBaud, diff;

    calculatedBaud = srcClock_Hz / (((uint32_t)timerDiv + 1U) * 2U);
    diff = calculatedBaud - baudRate_Bps;
    if (diff > ((baudRate_Bps / 100U) * 3U))  /* 3% */
    {
        return kStatus_FLEXIO_T_FORMAT_BaudrateNotSupport;
    }
    return kStatus_Success;
}

/*!
 * @brief The value of the Timer Compare register is calculated
 *         based on FlexIO's clock
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure
 * @param srcClock_Hz The clock frequency of FlexIO
 * @return The value of the Timer Compare register
 */
static uint16_t FLEXIO_T_FORMAT_GetTimerCompare(FLEXIO_T_FORMAT_Type *base, uint32_t srcClock_Hz)
{
    uint16_t timerCmp = 0;

    base->timerDiv    = srcClock_Hz / 2500000;
    timerCmp = base->timerDiv / 2U - 1U;
    if ((timerCmp > 0xFFU) || (FLEXIO_T_Format_CheckBaudRate(2500000, srcClock_Hz, timerCmp) != kStatus_Success))
    {
        return 0xFFFFU;
    }
    timerCmp = T_FORMAT_TIMER_COMPARE_VALUE(timerCmp);
    base->TxDR_Offset = srcClock_Hz / 2000000;  /* 0.5us */

    return timerCmp;
}

/*!
 * @brief The duration of the high level of the RS485 DR Pin is set
 *        according to the number of frames
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure
 * @param nFrames The number of frames (Each 8bit of data is one frame)
 */
void FLEXIO_T_Format_Config_DR_length(FLEXIO_T_FORMAT_Type *base, uint32_t nFrames)
{
    uint16_t timerCmp = 0;

    timerCmp = (uint16_t)(T_FORMAT_BITS_PER_FRAME_WHOLE * nFrames * base->timerDiv +
                           base->TxDR_Offset) - 1;
    base->flexioBase->TIMCMP[base->timerIndex[T_FORMAT_TIMER_DR_INDEX]] = FLEXIO_TIMCMP_CMP(timerCmp);
}

/*!
 * @brief Get the length of received data in RX ring buffer.
 *
 * @param handle FLEXIO T-format handle pointer.
 * @return Length of received data in RX ring buffer.
 */
static size_t FLEXIO_T_Format_TransferGetRxRingBufferLength(flexio_t_format_handle_t *handle)
{
    size_t size;
    uint16_t rxRingBufferHead = handle->rxRingBufferHead;
    uint16_t rxRingBufferTail = handle->rxRingBufferTail;

    if (rxRingBufferTail > rxRingBufferHead)
    {
        size = (size_t)rxRingBufferHead + handle->rxRingBufferSize - (size_t)rxRingBufferTail;
    }
    else
    {
        size = (size_t)rxRingBufferHead - (size_t)rxRingBufferTail;
    }

    return size;
}

/*!
 * @brief Check whether the RX ring buffer is full.
 *
 * @param handle FLEXIO T-format handle pointer.
 * @retval true  RX ring buffer is full.
 * @retval false RX ring buffer is not full.
 */
static bool FLEXIO_T_Format_TransferIsRxRingBufferFull(flexio_t_format_handle_t *handle)
{
    bool full;

    if (FLEXIO_T_Format_TransferGetRxRingBufferLength(handle) == (handle->rxRingBufferSize - 1U))
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
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO T-Format
 * hardware, and configures the FlexIO T-Format with FlexIO T-Format configuration.
 * The configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_T_FORMAT_GetDefaultConfig().
 *
 * Example
 * @code
 *    FLEXIO_T_FORMAT_Type base = {
 *    .flexioBase = FLEXIO,
 *    .TxPinIndex = 0,
 *    .RxPinIndex = 1,
 *    .shifterIndex = {0,1},
 *    .timerIndex = {0,1}
 *    };
 *    flexio_t_format_config_t config = {
 *    .enableInDoze = false,
 *    .enableInDebug = true,
 *    .enableFastAccess = false,
 *    .baudRate_bps = 2500000
 *    };
 *    FLEXIO_T_Format_Init(&base, &config);
 * @endcode
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param userConfig Pointer to the flexio_t_format_config_t structure.
 * @retval kStatus_Success Configuration success.
 */
status_t FLEXIO_T_Format_Init(FLEXIO_T_FORMAT_Type *base, flexio_t_format_config_t *userConfig, uint32_t srcClock_Hz)
{
    assert((base != NULL) && (userConfig != NULL));

    flexio_shifter_config_t shifterConfig;
    flexio_timer_config_t timerConfig;
    uint32_t ctrlReg  = 0;
    uint16_t timerCmp = 0;
    status_t result = kStatus_Success;

    /* Clear the shifterConfig & timerConfig struct. */
    (void)memset(&shifterConfig, 0, sizeof(shifterConfig));
    (void)memset(&timerConfig, 0, sizeof(timerConfig));

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate flexio clock. */
    CLOCK_EnableClock(s_flexioClocks[FLEXIO_T_Format_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure FLEXIO T_FORMAT */
    ctrlReg = base->flexioBase->CTRL;
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    ctrlReg &= ~(FLEXIO_CTRL_DOZEN_MASK | FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#else
    ctrlReg &= ~(FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#endif
    ctrlReg |= (FLEXIO_CTRL_DBGE(userConfig->enableInDebug) | FLEXIO_CTRL_FASTACC(userConfig->enableFastAccess) |
                FLEXIO_CTRL_FLEXEN(userConfig->enableT_Format));
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    if (!userConfig->enableInDoze)
    {
        ctrlReg |= FLEXIO_CTRL_DOZEN_MASK;
    }
#endif

    base->flexioBase->CTRL = ctrlReg;

    /* Do hardware configuration. */
    /* 1. Configure the shifter 0 for tx. */
    shifterConfig.timerSelect   = base->timerIndex[T_FORMAT_TIMER_TX_INDEX];
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutput;
    shifterConfig.pinSelect     = base->TxPinIndex;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeTransmit;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitHigh;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitLow;

    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterIndex[0], &shifterConfig);

    /*2. Configure the timer 0 for tx. */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(base->shifterIndex[0]);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinSelect       = base->TxPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerDisable;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitEnabled;

    if (userConfig->userMode == kFLEXIO_T_FORMAT_USERMODE_SYNC)
    {
        /*Configure the timer is triggered by FlexIO trigger signal. */
        timerConfig.triggerSelect   = base->triggerIn;
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceExternal;
    }

    timerCmp = FLEXIO_T_FORMAT_GetTimerCompare(base, srcClock_Hz);
    if (timerCmp == 0xFFFFU)
    {
        /* Check whether the configuared baudrate is within allowed range. */
        return kStatus_FLEXIO_T_FORMAT_BaudrateNotSupport;
    }
    timerConfig.timerCompare = timerCmp;

    FLEXIO_SetTimerConfig(base->flexioBase, base->timerIndex[T_FORMAT_TIMER_TX_INDEX], &timerConfig);

    /* 3. Configure the shifter 1 for rx. */
    shifterConfig.timerSelect   = base->timerIndex[T_FORMAT_TIMER_RX_INDEX];
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnNegitive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutputDisabled;
    shifterConfig.pinSelect     = base->RxPinIndex;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeReceive;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitHigh;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitLow;

    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterIndex[1], &shifterConfig);

    /* 4. Configure the timer 1 for rx. */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_PININPUT(base->RxPinIndex);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceExternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinSelect       = base->RxPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveLow;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetOnTimerPinRisingEdge;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnPinRisingEdge;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerDisable;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitEnabled;
    timerConfig.timerCompare    = timerCmp;

    FLEXIO_SetTimerConfig(base->flexioBase, base->timerIndex[T_FORMAT_TIMER_RX_INDEX], &timerConfig);

    /*5. Configure the timer 2 for DR */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(base->timerIndex[T_FORMAT_TIMER_TX_INDEX]);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutput;
    timerConfig.pinSelect       = base->DRPinIndex;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeSingle16Bit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;

    /* Calculate the DR signal length.
     * Because the number of the bytes is one for the request on sync mode,
     * the default DR signal length is for one byte transmitting.
     */

    timerCmp = (uint16_t)(T_FORMAT_BITS_PER_FRAME_WHOLE * base->timerDiv) - 1;
    timerConfig.timerCompare = timerCmp;

    FLEXIO_SetTimerConfig(base->flexioBase, base->timerIndex[T_FORMAT_TIMER_DR_INDEX], &timerConfig);
    return result;
}

/*!
 * @brief Resets the FlexIO T-Format shifter and timer config.
 *
 * note After calling this API, call the FLEXIO_T_Format_Init to use the FlexIO T_format module.
 *
 * @param base Pointer to FLEXIO_T_FORMAT_Type structure
 */
void FLEXIO_T_Format_Deinit(FLEXIO_T_FORMAT_Type *base)
{
    base->flexioBase->SHIFTCFG[base->shifterIndex[0]] = 0;
    base->flexioBase->SHIFTCTL[base->shifterIndex[0]] = 0;
    base->flexioBase->SHIFTCFG[base->shifterIndex[1]] = 0;
    base->flexioBase->SHIFTCTL[base->shifterIndex[1]] = 0;
    for (int i = 0; i <= T_FORMAT_TIMER_DR_INDEX; i++)
    {
        base->flexioBase->TIMCFG[base->timerIndex[i]]     = 0;
        base->flexioBase->TIMCMP[base->timerIndex[i]]     = 0;
        base->flexioBase->TIMCTL[base->timerIndex[i]]     = 0;
    }
    /* Clear the shifter flag. */
    base->flexioBase->SHIFTSTAT = (1UL << base->shifterIndex[0]);
    base->flexioBase->SHIFTSTAT = (1UL << base->shifterIndex[1]);
    /* Clear the timer flag. */
    for (int i = 0; i <= T_FORMAT_TIMER_DR_INDEX; i++)
    {
        base->flexioBase->TIMSTAT = (1UL << base->timerIndex[i]);
    }
}

/*!
 * @brief Gets the default configuration to configure the FlexIO T-format. The configuration
 * can be used directly for calling the FLEXIO_T_Format_Init().
 * Example:
 * @code
 *    flexio_t_format_config_t config;
 *    FLEXIO_T_Format_GetDefaultConfig(&userConfig);
 * @endcode
 * @param userConfig Pointer to the flexio_t_format_config_t structure.
 */
void FLEXIO_T_Format_GetDefaultConfig(flexio_t_format_config_t *userConfig)
{
    /* Initializes the configure structure to zero. */
    (void)memset(userConfig, 0, sizeof(*userConfig));

    userConfig->enableT_Format   = true;
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    userConfig->enableInDoze     = false;
#endif
    userConfig->enableInDebug    = true;
    userConfig->enableFastAccess = false;
    /* Default running mode USERMODE_ONESHOT*/
    userConfig->userMode         = kFLEXIO_T_FORMAT_USERMODE_ONESHOT;
}

/*!
 * @brief Enables the FlexIO T-format interrupt.
 *
 * This function enables the FlexIO T-format interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_T_Format_EnableInterrupts(FLEXIO_T_FORMAT_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable) != 0U)
    {
        FLEXIO_EnableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterIndex[0]);
    }
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable) != 0U)
    {
        FLEXIO_EnableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterIndex[1]);
    }
}

/*!
 * @brief Disables the FlexIO T-format interrupt.
 *
 * This function disables the FlexIO T-format interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Interrupt source.
 */
void FLEXIO_T_Format_DisableInterrupts(FLEXIO_T_FORMAT_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable) != 0U)
    {
        FLEXIO_DisableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterIndex[0]);
    }
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable) != 0U)
    {
        FLEXIO_DisableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterIndex[1]);
    }
}

/*!
 * @brief Gets the FlexIO T-format status flags.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @return FlexIO T-format status flags.
 */
uint32_t FLEXIO_T_Format_GetStatusFlags(FLEXIO_T_FORMAT_Type *base)
{
    uint32_t status = 0U;
    status =
        ((FLEXIO_GetShifterStatusFlags(base->flexioBase) & (1UL << base->shifterIndex[0])) >> base->shifterIndex[0]);
    status |=
        (((FLEXIO_GetShifterStatusFlags(base->flexioBase) & (1UL << base->shifterIndex[1])) >> (base->shifterIndex[1]))
         << 1U);
    status |=
        (((FLEXIO_GetShifterErrorFlags(base->flexioBase) & (1UL << base->shifterIndex[1])) >> (base->shifterIndex[1]))
         << 2U);
    return status;
}

/*!
 * @brief Clears the FlexIO T-format status flags.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param mask Status flag.
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_T_FORMAT_TxDataRegEmptyFlag
 *          arg kFLEXIO_T_FORMAT_RxDataRegFullFlag
 *          arg kFLEXIO_T_FORMAT_RxOverRunFlag
 */
void FLEXIO_T_Format_ClearStatusFlags(FLEXIO_T_FORMAT_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyFlag) != 0U)
    {
        FLEXIO_ClearShifterStatusFlags(base->flexioBase, 1UL << base->shifterIndex[0]);
    }
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullFlag) != 0U)
    {
        FLEXIO_ClearShifterStatusFlags(base->flexioBase, 1UL << base->shifterIndex[1]);
    }
    if ((mask & (uint32_t)kFLEXIO_T_FORMAT_RxOverRunFlag) != 0U)
    {
        FLEXIO_ClearShifterErrorFlags(base->flexioBase, 1UL << base->shifterIndex[1]);
    }
}

/*!
 * @brief Sends a buffer of data bytes.
 *
 * note This function blocks using the polling method until all bytes have been sent.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param txData The data bytes to send.
 * @param txSize The number of data bytes to send.
 * @retval kStatus_FLEXIO_T_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully wrote all data.
 */
status_t FLEXIO_T_Format_WriteBlocking(FLEXIO_T_FORMAT_Type *base, const uint8_t *txData, size_t txSize)
{
    assert(txData != NULL);
    assert(txSize != 0U);
#if T_FORMAT_RETRY_TIMES
    uint32_t waitTimes = T_FORMAT_RETRY_TIMES;
#endif

    while (0U != txSize--)
    {
        /* Wait until data transfer complete. */
        while ((0U == (FLEXIO_GetShifterStatusFlags(base->flexioBase) & (1UL << base->shifterIndex[0])))
#if T_FORMAT_RETRY_TIMES
               && (0U != --waitTimes)
#endif
	       );
#if T_FORMAT_RETRY_TIMES
        if (0U == waitTimes)
        {
            return kStatus_FLEXIO_T_FORMAT_Timeout;
        }
#endif

        base->flexioBase->SHIFTBUF[base->shifterIndex[0]] = *txData;
        txData++;
    }
    return kStatus_Success;
}

/*!
 * @brief Receives a buffer of bytes.
 *
 * note This function blocks using the polling method until all bytes have been received.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of data bytes to be received.
 * @retval kStatus_FLEXIO_T_FORMAT_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_T_Format_ReadBlocking(FLEXIO_T_FORMAT_Type *base, uint8_t *rxData, size_t rxSize)
{
    assert(rxData != NULL);
    assert(rxSize != 0U);
#if T_FORMAT_RETRY_TIMES
    uint32_t waitTimes = T_FORMAT_RETRY_TIMES;
#endif

    while (0U != rxSize--)
    {
        /* Wait until data transfer complete. */
        while ((0U == (FLEXIO_T_Format_GetStatusFlags(base) & (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullFlag))
#if T_FORMAT_RETRY_TIMES
               && (0U != --waitTimes)
#endif
              );
#if T_FORMAT_RETRY_TIMES
        if (0U == waitTimes)
        {
            return kStatus_FLEXIO_T_FORMAT_Timeout;
        }
#endif

        *rxData = (uint8_t)(base->flexioBase->SHIFTBUFBYS[base->shifterIndex[1]]);
        rxData++;
    }

    return kStatus_Success;
}

/*!
 * @brief Initializes the T-format handle.
 *
 * This function initializes the FlexIO T-format handle, which can be used for other FlexIO
 * T-format transactional APIs. Call this API once to get the initialized handle.
 *
 * The T-format driver supports the "background" receiving, which means that users can set up
 * a RX ring buffer optionally. Data received is stored into the ring buffer even when
 * the user doesn't call the FLEXIO_T_Format_TransferReceiveNonBlocking() API. If there is already
 * data received in the ring buffer, users can get the received data from the ring buffer
 * directly. The ring buffer is disabled if passing NULL as p ringBuffer.
 *
 * @param base to FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param callback The callback function.
 * @param userData The parameter of the callback function.
 * @retval kStatus_Success Successfully create the handle.
 * @retval kStatus_OutOfRange The FlexIO type/handle/ISR table out of range.
 */
status_t FLEXIO_T_Format_TransferCreateHandle(FLEXIO_T_FORMAT_Type *base,
                                              flexio_t_format_handle_t *handle,
                                              flexio_t_format_transfer_callback_t callback,
                                              void *userData)
{
    assert(handle != NULL);

#if defined(FLEXIO_IRQS)
    IRQn_Type flexio_irqs[] = FLEXIO_IRQS;

    /* Zero the handle. */
    (void)memset(handle, 0, sizeof(*handle));

    /* Set the TX/RX state. */
    handle->rxState = (uint8_t)kFLEXIO_T_FORMAT_RxIdle;
    handle->txState = (uint8_t)kFLEXIO_T_FORMAT_TxIdle;

    /* Set the callback and user data. */
    handle->callback = callback;
    handle->userData = userData;

    base->hanlde = handle;

    /* Enable interrupt in NVIC. */
    (void)EnableIRQ(flexio_irqs[FLEXIO_T_Format_GetInstance(base)]);

    /* Save the context in global variables to support the double weak mechanism. */
    return FLEXIO_RegisterHandleIRQ(base, handle, FLEXIO_T_Format_TransferHandleIRQ);
#else
    return kStatus_Fail;
#endif
}

/*!
 * @brief Sets up the RX ring buffer.
 *
 * This function sets up the RX ring buffer to a specific T-format handle.
 *
 * When the RX ring buffer is used, data received is stored into the ring buffer even when
 * the user doesn't call the T_Format_ReceiveNonBlocking() API. If there is already data received
 * in the ring buffer, users can get the received data from the ring buffer directly.
 *
 * note When using the RX ring buffer, one byte is reserved for internal use. In other
 * words, if p ringBufferSize is 32, only 31 bytes are used for saving data.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param ringBuffer Start address of ring buffer for background receiving. Pass NULL to disable the ring buffer.
 * @param ringBufferSize Size of the ring buffer.
 */
void FLEXIO_T_Format_TransferStartRingBuffer(FLEXIO_T_FORMAT_Type *base,
                                             flexio_t_format_handle_t *handle,
                                             uint8_t *ringBuffer,
                                             size_t ringBufferSize)
{
    assert(handle != NULL);

    /* Setup the ringbuffer address */
    if (ringBuffer != NULL)
    {
        handle->rxRingBuffer     = ringBuffer;
        handle->rxRingBufferSize = ringBufferSize;
        handle->rxRingBufferHead = 0U;
        handle->rxRingBufferTail = 0U;

        /* Enable the interrupt to accept the data when user need the ring buffer. */
        FLEXIO_T_Format_EnableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);
    }
}

/*!
 * @brief Aborts the background transfer and uninstalls the ring buffer.
 *
 * This function aborts the background transfer and uninstalls the ring buffer.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferStopRingBuffer(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle)
{
    assert(handle != NULL);

    if (handle->rxState == (uint8_t)kFLEXIO_T_FORMAT_RxIdle)
    {
        FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);
    }

    handle->rxRingBuffer     = NULL;
    handle->rxRingBufferSize = 0U;
    handle->rxRingBufferHead = 0U;
    handle->rxRingBufferTail = 0U;
}

/*!
 * @brief Transmits a buffer of data using the interrupt method.
 *
 * This function sends data using an interrupt method. This is a non-blocking function,
 * which returns directly without waiting for all data to be written to the TX register. When
 * all data is written to the TX register in ISR, the FlexIO T-format driver calls the callback
 * function and passes the ref kStatus_FLEXIO_T_FORMAT_TxIdle as status parameter.
 *
 * note The kStatus_FLEXIO_T_FORMAT_TxIdle is passed to the upper layer when all data is written
 * to the TX register. However, it does not ensure that all data is sent out.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param xfer FlexIO T-format transfer structure. See #flexio_t_format_transfer_t.
 * @retval kStatus_Success Successfully starts the data transmission.
 * @retval kStatus_T_FORMAT_TxBusy Previous transmission still not finished, data not written to the TX register.
 */
status_t FLEXIO_T_Format_TransferSendNonBlocking(FLEXIO_T_FORMAT_Type *base,
                                                 flexio_t_format_handle_t *handle,
                                                 flexio_t_format_transfer_t *xfer)
{
    status_t status;

    /* Return error if xfer invalid. */
    if ((0U == xfer->dataSize) || (NULL == xfer->txData))
    {
        return kStatus_InvalidArgument;
    }

    /* Return error if current TX busy. */
    if ((uint8_t)kFLEXIO_T_FORMAT_TxBusy == handle->txState)
    {
        status = kStatus_FLEXIO_T_FORMAT_TxBusy;
    }
    else
    {
        handle->txData        = xfer->txData;
        handle->txDataSize    = xfer->dataSize;
        handle->txDataSizeAll = xfer->dataSize;
        handle->txState       = (uint8_t)kFLEXIO_T_FORMAT_TxBusy;

        /* Enable transmiter interrupt. */
        FLEXIO_T_Format_EnableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable);

        status = kStatus_Success;
    }

    return status;
}

/*!
 * @brief Aborts the interrupt-driven data transmit.
 *
 * This function aborts the interrupt-driven data sending. Get the remainHalfwords to find out
 * how many half-words are still not sent out.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferAbortSend(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle)
{
    /* Disable the transmitter and disable the interrupt. */
    FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable);

    handle->txDataSize = 0U;
    handle->txState    = (uint8_t)kFLEXIO_T_FORMAT_TxIdle;
}

/*!
 * @brief Gets the number of bytes sent.
 *
 * This function gets the number of bytes sent driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param count Number of bytes sent so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_T_Format_TransferGetSendCount(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle, size_t *count)
{
    assert(handle != NULL);
    assert(count != NULL);

    if ((uint8_t)kFLEXIO_T_FORMAT_TxIdle == handle->txState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->txDataSizeAll - handle->txDataSize;

    return kStatus_Success;
}

/*!
 * @brief Receives a buffer of data using the interrupt method.
 *
 * This function receives data using the interrupt method. This is a non-blocking function,
 * which returns without waiting for all data to be received.
 * If the RX ring buffer is used and not empty, the data in ring buffer is copied and
 * the parameter p receivedBytes shows how many bytes are copied from the ring buffer.
 * After copying, if the data in ring buffer is not enough to read, the receive
 * request is saved by the T-format driver. When new data arrives, the receive request
 * is serviced first. When all data is received, the T-format driver notifies the upper layer
 * through a callback function and passes the status parameter ref kStatus_T_FORMAT_RxIdle.
 * For example, if the upper layer needs 10 bytes but there are only 5 bytes in the ring buffer,
 * the 5 bytes are copied to xfer->data. This function returns with the
 * parameter p receivedBytes set to 5. For the last 5 bytes, newly arrived data is
 * saved from the xfer->data[5]. When 5 bytes are received, the T-format driver notifies upper layer.
 * If the RX ring buffer is not enabled, this function enables the RX and RX interrupt
 * to receive data to xfer->data. When all data is received, the upper layer is notified.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param xfer T-format transfer structure. See #flexio_t_format_transfer_t.
 * @param receivedBytes bytes received from the ring buffer directly.
 * @retval kStatus_Success Successfully queue the transfer into the transmit queue.
 * @retval kStatus_FLEXIO_T_FORMAT_RxBusy Previous receive request is not finished.
 */
status_t FLEXIO_T_Format_TransferReceiveNonBlocking(FLEXIO_T_FORMAT_Type *base,
                                                    flexio_t_format_handle_t *handle,
                                                    flexio_t_format_transfer_t *xfer,
                                                    size_t *receivedBytes)
{
    uint32_t i;
    status_t status;
    /* How many bytes to copy from ring buffer to user memory. */
    size_t bytesToCopy = 0U;
    /* How many bytes to receive. */
    size_t bytesToReceive;
    /* How many bytes currently have received. */
    size_t bytesCurrentReceived;

    /* Return error if xfer invalid. */
    if ((0U == xfer->dataSize) || (NULL == xfer->rxData))
    {
        return kStatus_InvalidArgument;
    }

    /* How to get data:
       1. If RX ring buffer is not enabled, then save xfer->data and xfer->dataSize
          to T-format handle, enable interrupt to store received data to xfer->data.
          When all data received, trigger callback.
       2. If RX ring buffer is enabled and not empty, get data from ring buffer first.
          If there are enough data in ring buffer, copy them to xfer->data and return.
          If there are not enough data in ring buffer, copy all of them to xfer->data,
          save the xfer->data remained empty space to T-format handle, receive data
          to this empty space and trigger callback when finished. */

    if ((uint8_t)kFLEXIO_T_FORMAT_RxBusy == handle->rxState)
    {
        status = kStatus_FLEXIO_T_FORMAT_RxBusy;
    }
    else
    {
        bytesToReceive       = xfer->dataSize;
        bytesCurrentReceived = 0U;

        /* If RX ring buffer is used. */
        if (handle->rxRingBuffer != NULL)
        {
            /* Disable FLEXIO_T_Format RX IRQ, protect ring buffer. */
            FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);

            /* How many bytes in RX ring buffer currently. */
            bytesToCopy = FLEXIO_T_Format_TransferGetRxRingBufferLength(handle);

            if (bytesToCopy != 0U)
            {
                bytesToCopy = MIN(bytesToReceive, bytesToCopy);

                bytesToReceive -= bytesToCopy;

                /* Copy data from ring buffer to user memory. */
                for (i = 0U; i < bytesToCopy; i++)
                {
                    xfer->rxData[bytesCurrentReceived++] = handle->rxRingBuffer[handle->rxRingBufferTail];

                    /* Wrap to 0. Not use modulo (%) because it might be large and slow. */
                    if ((uint32_t)handle->rxRingBufferTail + 1U == handle->rxRingBufferSize)
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
                /* No data in ring buffer, save the request to T-format handle. */
                handle->rxData        = xfer->rxData + bytesCurrentReceived;
                handle->rxDataSize    = bytesToReceive;
                handle->rxDataSizeAll = xfer->dataSize;
                handle->rxState       = (uint8_t)kFLEXIO_T_FORMAT_RxBusy;
            }

            /* Enable FLEXIO_T_FORMAT RX IRQ if previously enabled. */
            FLEXIO_T_Format_EnableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);

            /* Call user callback since all data are received. */
            if (0U == bytesToReceive)
            {
                if (handle->callback != NULL)
                {
                    handle->callback(base, handle, kStatus_FLEXIO_T_FORMAT_RxIdle, handle->userData);
                }
            }
        }
        /* Ring buffer not used. */
        else
        {
            handle->rxData        = xfer->rxData + bytesCurrentReceived;
            handle->rxDataSize    = bytesToReceive;
            handle->rxDataSizeAll = bytesToReceive;
            handle->rxState       = (uint8_t)kFLEXIO_T_FORMAT_RxBusy;

            /* Enable RX interrupt. */
            FLEXIO_T_Format_EnableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);
        }

        /* Return the how many bytes have read. */
        if (receivedBytes != NULL)
        {
            *receivedBytes = bytesCurrentReceived;
        }

        status = kStatus_Success;
    }

    return status;
}

/*!
 * @brief Aborts the receive data which was using IRQ.
 *
 * This function aborts the receive data which was using IRQ.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferAbortReceive(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle)
{
    /* Only abort the receive to handle->rxData, the RX ring buffer is still working. */
    if (NULL == handle->rxRingBuffer)
    {
        /* Disable RX interrupt. */
        FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);
    }

    handle->rxDataSize = 0U;
    handle->rxState    = (uint8_t)kFLEXIO_T_FORMAT_RxIdle;
}

/*!
 * @brief Gets the number of bytes received.
 *
 * This function gets the number of bytes received driven by interrupt.
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 * @param count Number of bytes received so far by the non-blocking transaction.
 * @retval kStatus_NoTransferInProgress transfer has finished or no transfer in progress.
 * @retval kStatus_Success Successfully return the count.
 */
status_t FLEXIO_T_Format_TransferGetReceiveCount(FLEXIO_T_FORMAT_Type *base, flexio_t_format_handle_t *handle, size_t *count)
{
    assert(handle != NULL);
    assert(count != NULL);

    if ((uint8_t)kFLEXIO_T_FORMAT_RxIdle == handle->rxState)
    {
        return kStatus_NoTransferInProgress;
    }

    *count = handle->rxDataSizeAll - handle->rxDataSize;

    return kStatus_Success;
}

/*!
 * @brief FlexIO T-format IRQ handler function.
 *
 * This function processes the FlexIO T-format transmit and receives the IRQ request.
 *
 * @param type Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param handle Pointer to the flexio_t_format_handle_t structure to store the transfer state.
 */
void FLEXIO_T_Format_TransferHandleIRQ(void *type, void *userHandle)
{
    uint8_t count                    = 1;
    FLEXIO_T_FORMAT_Type *base       = (FLEXIO_T_FORMAT_Type *)type;
    flexio_t_format_handle_t *handle = (flexio_t_format_handle_t *)userHandle;
    uint16_t rxRingBufferHead;

    /* Read the status back. */
    uint32_t status     = FLEXIO_T_Format_GetStatusFlags(base);

    /* If RX overrun. */
    if (((uint32_t)kFLEXIO_T_FORMAT_RxOverRunFlag & status) != 0U)
    {
        /* Clear Overrun flag. */
        FLEXIO_T_Format_ClearStatusFlags(base, (uint32_t)kFLEXIO_T_FORMAT_RxOverRunFlag);

        /* Trigger callback. */
        if (handle->callback != NULL)
        {
            handle->callback(base, handle, kStatus_FLEXIO_T_FORMAT_RxHardwareOverrun, handle->userData);
        }
    }

    /* Receive data register full */
    if ((((uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullFlag & status) != 0U) &&
        ((base->flexioBase->SHIFTSIEN & (1UL << base->shifterIndex[1])) != 0U))
    {
        /* If handle->rxDataSize is not 0, first save data to handle->rxData. */
        if (handle->rxDataSize != 0U)
        {
            /* Using non block API to read the data from the registers. */
            FLEXIO_T_Format_ReadByte(base, handle->rxData);
            handle->rxDataSize--;
            handle->rxData++;
            count--;

            /* If all the data required for upper layer is ready, trigger callback. */
            if (0U == handle->rxDataSize)
            {
                handle->rxState = (uint8_t)kFLEXIO_T_FORMAT_RxIdle;

                if (handle->callback != NULL)
                {
                    handle->callback(base, handle, kStatus_FLEXIO_T_FORMAT_RxIdle, handle->userData);
                }
            }
        }

        if (handle->rxRingBuffer != NULL)
        {
            if (count != 0U)
            {
                /* If RX ring buffer is full, trigger callback to notify over run. */
                if (FLEXIO_T_Format_TransferIsRxRingBufferFull(handle))
                {
                    if (handle->callback != NULL)
                    {
                        handle->callback(base, handle, kStatus_FLEXIO_T_FORMAT_RxRingBufferOverrun, handle->userData);
                    }
                }

                /* If ring buffer is still full after callback function, the oldest data is overridden. */
                if (FLEXIO_T_Format_TransferIsRxRingBufferFull(handle))
                {
                    /* Increase handle->rxRingBufferTail to make room for new data. */
                    if ((uint32_t)handle->rxRingBufferTail + 1U == handle->rxRingBufferSize)
                    {
                        handle->rxRingBufferTail = 0U;
                    }
                    else
                    {
                        handle->rxRingBufferTail++;
                    }
                }

                /* Read data. */
                rxRingBufferHead = handle->rxRingBufferHead;
                handle->rxRingBuffer[rxRingBufferHead] =
                    (uint16_t)(base->flexioBase->SHIFTBUFBYS[base->shifterIndex[1]]);

                /* Increase handle->rxRingBufferHead. */
                if ((uint32_t)handle->rxRingBufferHead + 1U == handle->rxRingBufferSize)
                {
                    handle->rxRingBufferHead = 0U;
                }
                else
                {
                    handle->rxRingBufferHead++;
                }
            }
        }
        /* If no receive requst pending, stop RX interrupt. */
        else if (0U == handle->rxDataSize)
        {
            FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_RxDataRegFullInterruptEnable);
        }
    }

    /* Send data register empty and the interrupt is enabled. */
    if ((((uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyFlag & status) != 0U) &&
        ((base->flexioBase->SHIFTSIEN & (1UL << base->shifterIndex[0])) != 0U))
    {
        if (handle->txDataSize != 0U)
        {
            /* Using non block API to write the data to the registers. */
            FLEXIO_T_Format_WriteByte(base, handle->txData);
            handle->txData++;
            handle->txDataSize--;

            /* If all the data are written to data register, TX finished. */
            if (0U == handle->txDataSize)
            {
                handle->txState = (uint8_t)kFLEXIO_T_FORMAT_TxIdle;

                /* Disable TX register empty interrupt. */
                FLEXIO_T_Format_DisableInterrupts(base, (uint32_t)kFLEXIO_T_FORMAT_TxDataRegEmptyInterruptEnable);

                /* Trigger callback. */
                if (handle->callback != NULL)
                {
                    handle->callback(base, handle, kStatus_FLEXIO_T_FORMAT_TxIdle, handle->userData);
                }
            }
        }
    }
}

/*!
 * @brief FlexIO T-format IRQ handler function.
 *
 *
 * @param base Pointer to the FLEXIO_T_FORMAT_Type structure.
 * @param cf Sets commands to be sent in synchronous mode.
 * @return kStatus_Success
 */
status_t FLEXIO_T_Format_SendSyncReq(FLEXIO_T_FORMAT_Type *base, const uint8_t cf)
{
    FLEXIO_T_Format_Config_DR_length(base, 1);
    base->flexioBase->SHIFTBUF[base->shifterIndex[0]] = cf;
    return kStatus_Success;
}

