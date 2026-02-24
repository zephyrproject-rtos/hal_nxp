/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_flexio_biss.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.flexio_biss"
#endif

#define BISS_SHIFTER_MASK      0x3F
#define BISS_TIMER_MASK        0x03

/* 10MHz */
#define BISS_MA_CLK_FREQ       10000000
/* (LAT + ACK + STR + CDS) */
#define BISS_DEFAULT_HEAD_LEN  4
#define BISS_DEFAULT_MT_LEN    12
#define BISS_DEFAULT_ST_LEN    16
#define BISS_DEFAULT_WR_ER_LEN 2
#define BISS_DEFAULT_CRC_LEN   6
#define BISS_DEFAULT_STP_LEN   1
#define BISS_DEFAULT_CDM_LEN   4

#define BISS_DEFAULT_DATA_LEN  (BISS_DEFAULT_MT_LEN + BISS_DEFAULT_ST_LEN + BISS_DEFAULT_WR_ER_LEN)
#define BISS_DEFAULT_TOTAL_LEN (BISS_DEFAULT_HEAD_LEN + BISS_DEFAULT_DATA_LEN + BISS_DEFAULT_CRC_LEN + BISS_DEFAULT_STP_LEN)
#define BISS_DEFAULT_WHOLE_LEN (BISS_DEFAULT_TOTAL_LEN + BISS_DEFAULT_CDM_LEN)

#define BISS_DATA_LEN(frame)   ((frame)->mtBits + (frame)->stBits + (frame)->erWrBits)
#define BISS_TOTAL_LEN(frame)  ((frame)->headBits + (frame)->dataBits + (frame)->crcBits + (frame)->stopBits)
#define BISS_WHOLE_LEN(frame)  (BISS_TOTAL_LEN(frame) + (frame)->cdmBits)

#define CDM_VALUE_H(frame) ((uint64_t)0xAAAAAAAAAAAAAAAA | ((uint64_t)0xFFFFFFFFFFFFFFFF << (((frame)->totalBits * 2) % 64)))
#define CDM_VALUE_L(frame) (CDM_VALUE_H(frame) & (~((uint64_t)BISS_FRAME_MASK((frame)->cdmBits * 2) << (((frame)->totalBits * 2) % 64))))

/*! @brief Calculate the value of the FlexIO timer compare register. */
#define BISS_TIMER_COMPARE_VALUE(cmp) (((64 * 2U - 1U) << 8U) | cmp)
/*! @brief FlexIO BiSS clock divider calculation */
#define FLEXIO_BISS_CLOCK_DIVIDER(flexioClockFreq, biss_clk) (((flexioClockFreq) / (biss_clk) / 2U) - 1U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Calculates the number of the clock and the value of CDM
 *
 * @note The return value of this function is used to pass to the
 * FLEXIO_BISS_GenClock function.
 *
 * @param frame Pointer to the flexio_biss_frame_t structure.
 * @param cdmIsHigh The CDM field is high or low level.
 * @return An unsigned 64-bit value including the clock and the CDM
 */
uint64_t FLEXIO_BISS_CalClockValue(flexio_biss_frame_t *frame, bool cdmIsHigh)
{
    return cdmIsHigh ? CDM_VALUE_H(frame) : CDM_VALUE_L(frame);
}

static uint32_t FLEXIO_BISS_GetInstance(FLEXIO_BISS_Type *base)
{
    return FLEXIO_GetInstance(base->flexioBase);
}

static void FLEXIO_BISS_FrameInit(flexio_biss_frame_t *frame)
{
    frame->headBits  = BISS_DEFAULT_HEAD_LEN;
    frame->mtBits    = BISS_DEFAULT_MT_LEN;
    frame->stBits    = BISS_DEFAULT_ST_LEN;
    frame->erWrBits  = BISS_DEFAULT_WR_ER_LEN;
    frame->crcBits   = BISS_DEFAULT_CRC_LEN;
    frame->stopBits  = BISS_DEFAULT_STP_LEN;
    frame->cdmBits   = BISS_DEFAULT_CDM_LEN;
    frame->dataBits  = BISS_DEFAULT_DATA_LEN;
    frame->totalBits = BISS_DEFAULT_TOTAL_LEN;
    frame->wholeBits = BISS_DEFAULT_WHOLE_LEN;
}

static status_t FLEXIO_BISS_CheckBaudRate(uint32_t baudRate_Bps, uint32_t srcClock_Hz, uint16_t timerDiv)
{
    uint32_t calculatedBaud, diff;

    calculatedBaud = srcClock_Hz / (((uint32_t)timerDiv + 1U) * 2U);
    diff = calculatedBaud - baudRate_Bps;
    if (diff > ((baudRate_Bps / 100U) * 3U))  /* 3% */
    {
        return kStatus_Fail;
    }
    return kStatus_Success;
}

/*!
 * @brief The value of the Timer Compare register is calculated
 *         based on FlexIO's clock
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure
 * @param bissClock_Hz The clock frequency of the BiSS
 * @param srcClock_Hz The clock frequency of FlexIO
 * @return The value of the Timer Compare register
 */
static uint16_t FLEXIO_BISS_GetTimerCompare(FLEXIO_BISS_Type *base, uint32_t bissClock_Hz, uint32_t srcClock_Hz)
{
    uint16_t timerCmp = 0;
    uint16_t timerDiv;

    timerDiv = srcClock_Hz / bissClock_Hz;
    timerCmp = timerDiv / 2U - 1U;
    if ((timerCmp > 0xFFU) || (FLEXIO_BISS_CheckBaudRate(bissClock_Hz, srcClock_Hz, timerCmp) != kStatus_Success))
    {
        return 0xFFFFU;
    }
    timerCmp = BISS_TIMER_COMPARE_VALUE(timerCmp);

    return timerCmp;
}

/*!
 * @brief Ungates the FlexIO clock, resets the FlexIO module, configures the FlexIO BiSS
 * hardware, and configures the FlexIO BiSS with FlexIO BiSS configuration.
 * The configuration structure can be filled by the user, or be set with default values
 * by the FLEXIO_BISS_MasterGetDefaultConfig().
 *
 * Example
 * @code
 *    flexio_biss_frame_t frame_g;
 *    FLEXIO_BISS_Type base = {
 *      .flexioBase       = FLEXIO1,
 *      .frame            = &frame_g,
 *      .dataPin          = 0,
 *      .clockPin         = 2,
 *      .shifterBaseIndex = 0,
 *      .shifterCount     = BISS_SHIFTER_NUM,
 *      .timerBaseIndex   = 0,
 *      .timerCount       = BISS_TIMER_NUM
 *    };
 *    flexio_biss_config_t config = {
 *      .enableBiSS       = true,
 *      .enableInDoze     = false,
 *      .enableInDebug    = true,
 *      .enableFastAccess = false,
 *      .baudRate_bps     = 10000000,
 *      .userMode         = kFLEXIO_BISS_USERMODE_ONESHOT
 *    };
 *    FLEXIO_BISS_MasterInit(&base, &config, 80000000);
 * @endcode
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param masterConfig Pointer to the flexio_biss_config_t structure.
 * @param srcClock_Hz The FlexIO root clock frequency in Hz.
 * @retval kStatus_Success Configuration success.
 */
status_t FLEXIO_BISS_MasterInit(FLEXIO_BISS_Type *base, 
                                const flexio_biss_config_t *masterConfig, 
                                uint32_t srcClock_Hz)
{
    assert((base != NULL) && (masterConfig != NULL));

    flexio_shifter_config_t shifterConfig;
    flexio_timer_config_t timerConfig;
    uint32_t ctrlReg  = 0;
    uint16_t timerCmp = 0;

    /* Clear the shifterConfig & timerConfig struct. */
    (void)memset(&shifterConfig, 0, sizeof(shifterConfig));
    (void)memset(&timerConfig, 0, sizeof(timerConfig));

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Ungate flexio clock. */
    CLOCK_EnableClock(s_flexioClocks[FLEXIO_BISS_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Configure FLEXIO BiSS */
    ctrlReg = base->flexioBase->CTRL;
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    ctrlReg &= ~(FLEXIO_CTRL_DOZEN_MASK | FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#else
    ctrlReg &= ~(FLEXIO_CTRL_DBGE_MASK | FLEXIO_CTRL_FASTACC_MASK | FLEXIO_CTRL_FLEXEN_MASK);
#endif
    ctrlReg |= (FLEXIO_CTRL_DBGE(masterConfig->enableInDebug ? 1U : 0U) | FLEXIO_CTRL_FASTACC(masterConfig->enableFastAccess ? 1U : 0U) |
                FLEXIO_CTRL_FLEXEN(masterConfig->enableBiSS ? 1U : 0U));
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    if (!masterConfig->enableInDoze)
    {
        ctrlReg |= FLEXIO_CTRL_DOZEN_MASK;
    }
#endif

    base->flexioBase->CTRL = ctrlReg;

    /* Do hardware configuration. */
    if (base->frame != NULL)
    {
        FLEXIO_BISS_FrameInit(base->frame);
    }
    else
    {
        return kStatus_InvalidArgument;
    }

    /* 1. SLO: Configure the Shifter0&1 used to receive the data */
    shifterConfig.timerSelect   = base->timerBaseIndex + 1;
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutputDisabled;
    shifterConfig.pinSelect     = base->dataPin;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeReceive;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitDisable;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnEnable;
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex + 1, &shifterConfig);

    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromNextShifterOutput;
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex, &shifterConfig);

    /* 2. SLO: Configure the Timer1 for the Shifter0&1 */
    timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_TIMn(base->timerBaseIndex);
    timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
    timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinSelect       = base->dataPin;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnPreTimerDisable;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnPrevTimerEnable;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitDisabled;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitDisabled;

    /* Calculate the timer compare register for desired clock frequency */
    timerCmp = FLEXIO_BISS_GetTimerCompare(base, masterConfig->baudRate_bps, srcClock_Hz);
    if (timerCmp == 0xFFFFU)
    {
        return kStatus_InvalidArgument;
    }
    timerConfig.timerCompare = timerCmp;
    FLEXIO_SetTimerConfig(base->flexioBase, base->timerBaseIndex + 1, &timerConfig);

    /* 3. Configure the Shifter2&3&4&5 used to trigger the Timer0 */
    (void)memset(&shifterConfig, 0, sizeof(shifterConfig));

    shifterConfig.timerSelect   = base->timerBaseIndex;
    shifterConfig.timerPolarity = kFLEXIO_ShifterTimerPolarityOnPositive;
    shifterConfig.pinConfig     = kFLEXIO_PinConfigBidirectionOutputData;
    shifterConfig.pinSelect     = base->clockPin;
    shifterConfig.pinPolarity   = kFLEXIO_PinActiveHigh;
    shifterConfig.shifterMode   = kFLEXIO_ShifterModeTransmit;
    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromNextShifterOutput;
    shifterConfig.shifterStop   = kFLEXIO_ShifterStopBitDisable;
    shifterConfig.shifterStart  = kFLEXIO_ShifterStartBitDisabledLoadDataOnEnable;
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex + 2, &shifterConfig);
    base->flexioBase->SHIFTCTL[base->shifterBaseIndex + 2] |= FLEXIO_SHIFTCTL_PINCFG(kFLEXIO_PinConfigOutput);

    shifterConfig.pinConfig     = kFLEXIO_PinConfigOutputDisabled;
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex + 3, &shifterConfig);
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex + 4, &shifterConfig);

    shifterConfig.inputSource   = kFLEXIO_ShifterInputFromPin;
    FLEXIO_SetShifterConfig(base->flexioBase, base->shifterBaseIndex + 5, &shifterConfig);

    /* 4. MAI: Configure the Timer0 for the Shifter2&3&4 */
    memset(&timerConfig, 0, sizeof(timerConfig));

    if (masterConfig->userMode == kFLEXIO_BISS_USERMODE_ONESHOT)
    {
        timerConfig.triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(base->shifterBaseIndex + 5);
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    }
    else
    {
        timerConfig.triggerSelect   = base->triggerIn;
        timerConfig.triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        timerConfig.triggerSource   = kFLEXIO_TimerTriggerSourceExternal;
    }
    timerConfig.pinConfig       = kFLEXIO_PinConfigOutputDisabled;
    timerConfig.pinSelect       = base->clockPin;
    timerConfig.pinPolarity     = kFLEXIO_PinActiveHigh;
    timerConfig.timerMode       = kFLEXIO_TimerModeDual8BitBaudBit;
    timerConfig.timerOutput     = kFLEXIO_TimerOutputOneNotAffectedByReset;
    timerConfig.timerDecrement  = kFLEXIO_TimerDecSrcOnFlexIOClockShiftTimerOutput;
    timerConfig.timerReset      = kFLEXIO_TimerResetNever;
    timerConfig.timerDisable    = kFLEXIO_TimerDisableOnTimerCompare;
    timerConfig.timerEnable     = kFLEXIO_TimerEnableOnTriggerHigh;
    timerConfig.timerStop       = kFLEXIO_TimerStopBitEnableOnTimerCompare;
    timerConfig.timerStart      = kFLEXIO_TimerStartBitEnabled;

    base->clockDivider          = FLEXIO_BISS_CLOCK_DIVIDER(srcClock_Hz / 2, masterConfig->baudRate_bps);
    timerConfig.timerCompare    = (((BISS_DEFAULT_WHOLE_LEN * 2 * 2) - 1) << 8U) | base->clockDivider;

    FLEXIO_SetTimerConfig(base->flexioBase, base->timerBaseIndex, &timerConfig);

    return kStatus_Success;
}

/*!
 * @brief Updates the number of BiSS clocks to the FlexIO Timer register.
 *
 * note After the BiSS frame length has been updated, this function is called.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 */
void FLEXIO_BISS_UpdateClockTimer(FLEXIO_BISS_Type *base)
{
    uint32_t timerCompare = (((base->frame->wholeBits * 2 * 2) - 1) << 8U) | base->clockDivider;
    base->flexioBase->TIMCMP[base->timerBaseIndex] = timerCompare;
}

/*!
 * @brief Updates the trigger mode for FlexIO BiSS receiving data.
 *
 * note After calling the FLEXIO_BISS_MasterInit function, this function is called.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 * @param mode Oneshot or Sync(Other IP triggers) mode
 */
void FLEXIO_BISS_UpdateTriggerMode(FLEXIO_BISS_Type *base, flexio_biss_user_modes_t mode)
{
    uint32_t triggerSelect;
    flexio_timer_trigger_polarity_t triggerPolarity;
    flexio_timer_trigger_source_t triggerSource;
    uint32_t timctl_mask = ~(FLEXIO_TIMCTL_TRGSEL_MASK | FLEXIO_TIMCTL_TRGPOL_MASK | FLEXIO_TIMCTL_TRGSRC_MASK);
    uint32_t timctl_temp = base->flexioBase->TIMCTL[base->timerBaseIndex] & timctl_mask;

    if (mode == kFLEXIO_BISS_USERMODE_ONESHOT)
    {
        triggerSelect   = FLEXIO_TIMER_TRIGGER_SEL_SHIFTnSTAT(base->shifterBaseIndex + 5);
        triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveLow;
        triggerSource   = kFLEXIO_TimerTriggerSourceInternal;
    }
    else
    {
        triggerSelect   = base->triggerIn;
        triggerPolarity = kFLEXIO_TimerTriggerPolarityActiveHigh;
        triggerSource   = kFLEXIO_TimerTriggerSourceExternal;
    }

    base->flexioBase->TIMCTL[base->timerBaseIndex] = timctl_temp | FLEXIO_TIMCTL_TRGSEL(triggerSelect) |
                                                     FLEXIO_TIMCTL_TRGPOL(triggerPolarity) |
                                                     FLEXIO_TIMCTL_TRGSRC(triggerSource);
}

/*!
 * @brief Resets the FlexIO BiSS shifter and timer config.
 *
 * note After calling this API, call the FLEXIO_BISS_MasterInit to use the FlexIO BiSS module.
 *
 * @param base Pointer to FLEXIO_BISS_Type structure
 */
void FLEXIO_BISS_MasterDeinit(FLEXIO_BISS_Type *base)
{
    assert(base != NULL);
    uint8_t index;
    
    if (base->flexioBase != NULL)
    {
        /* Disable shifter and timer */
        for (index = base->shifterBaseIndex; index < base->shifterBaseIndex + BISS_SHIFTER_NUM; index++)
        {
            base->flexioBase->SHIFTCFG[index] = 0U;
            base->flexioBase->SHIFTCTL[index] = 0U;
        }
        FLEXIO_ClearShifterStatusFlags(base->flexioBase, BISS_SHIFTER_MASK << base->shifterBaseIndex);
        FLEXIO_ClearShifterErrorFlags(base->flexioBase, BISS_SHIFTER_MASK << base->shifterBaseIndex);

        for (index = base->timerBaseIndex; index < base->timerBaseIndex + BISS_TIMER_NUM; index++)
        {
            base->flexioBase->TIMCFG[index] = 0U;
            base->flexioBase->TIMCTL[index] = 0U;
            base->flexioBase->TIMCMP[index] = 0U;
        }
        FLEXIO_ClearTimerStatusFlags(base->flexioBase, BISS_TIMER_MASK << base->timerBaseIndex);
    }
}

/*!
 * @brief Gets the default configuration to configure the FlexIO BiSS. The
 * configuration can be used directly for calling the FLEXIO_BISS_MasterInit().
 * Example:
 * @code
 *    flexio_biss_config_t config;
 *    FLEXIO_BISS_MasterGetDefaultConfig(&userConfig);
 * @endcode
 * param userConfig Pointer to the flexio_biss_config_t structure.
 */
void FLEXIO_BISS_MasterGetDefaultConfig(flexio_biss_config_t *masterConfig)
{
    assert(masterConfig != NULL);
    /* Initializes the configure structure to zero. */
    (void)memset(masterConfig, 0, sizeof(*masterConfig));
    
    masterConfig->enableBiSS       = true;
#if !(defined(FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT) && (FSL_FEATURE_FLEXIO_HAS_DOZE_MODE_SUPPORT == 0))
    masterConfig->enableInDoze     = false;
#endif
    masterConfig->enableInDebug    = true;
    masterConfig->enableFastAccess = false;
    masterConfig->baudRate_bps     = BISS_MA_CLK_FREQ;
    masterConfig->userMode         = kFLEXIO_BISS_USERMODE_ONESHOT;
}

/*!
 * @brief Enables the FlexIO BiSS interrupt.
 *
 * This function enables the FlexIO BiSS interrupt.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 */
void FLEXIO_BISS_EnableInterrupts(FLEXIO_BISS_Type *base)
{
    assert(base != NULL);

    FLEXIO_EnableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterBaseIndex);
}

/*!
 * @brief Disables the FlexIO BiSS interrupt.
 *
 * This function disables the FlexIO BiSS interrupt.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 */
void FLEXIO_BISS_DisableInterrupts(FLEXIO_BISS_Type *base)
{
    assert(base != NULL);
    
    FLEXIO_DisableShifterStatusInterrupts(base->flexioBase, 1UL << base->shifterBaseIndex);
}

/*!
 * @brief Gets the FlexIO BiSS status flags.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @return FlexIO BiSS status flags.
 */
uint32_t FLEXIO_BISS_GetStatusFlags(FLEXIO_BISS_Type *base)
{
    uint32_t status = 0U;
    status = (((FLEXIO_GetShifterStatusFlags(base->flexioBase) >> base->shifterBaseIndex) & 3UL) == 3 ? 1 : 0);
    status |= ((((FLEXIO_GetShifterErrorFlags(base->flexioBase) >> base->shifterBaseIndex) & 3UL) == 0 ? 0 : 1) << 1U);
    return status;
}

/*!
 * @brief Clears the FlexIO BiSS status flags.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param mask Status flag.
 *      The parameter can be any combination of the following values:
 *          arg kFLEXIO_BISS_RxDataRegFullFlag
 *          arg kFLEXIO_BISS_RxOverRunFlag
 */
void FLEXIO_BISS_ClearStatusFlags(FLEXIO_BISS_Type *base, uint32_t mask)
{
    if ((mask & (uint32_t)kFLEXIO_BISS_RxDataRegFullFlag) != 0U)
    {
        FLEXIO_ClearShifterStatusFlags(base->flexioBase, 3UL << base->shifterBaseIndex);
    }
    if ((mask & (uint32_t)kFLEXIO_BISS_RxOverRunFlag) != 0U)
    {
        FLEXIO_ClearShifterErrorFlags(base->flexioBase, 3UL << base->shifterBaseIndex);
    }
}

/*!
 * @brief Receives the buffer of one frame.
 *
 * note This function blocks using the polling method until one frame have been received.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of 32-bit buffer to be received.
 * @retval kStatus_Timeout Transmission timed out and was aborted.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_BISS_ReadBlocking(FLEXIO_BISS_Type *base, uint32_t *rxData, uint8_t rxSize)
{
    assert(base != NULL);
    assert(rxData != NULL);
    assert(rxSize >= BISS_FRAME_BUFFER_NUM);
#if BISS_RETRY_TIMES
    uint32_t waitTimes = BISS_RETRY_TIMES;
#endif

    /* Wait until data transfer complete. */
    while ((0U == (FLEXIO_BISS_GetStatusFlags(base) & (uint32_t)kFLEXIO_BISS_RxDataRegFullFlag))
#if BISS_RETRY_TIMES
           && (0U != --waitTimes)
#endif
          );
#if BISS_RETRY_TIMES
    if (0U == waitTimes)
    {
        return kStatus_Timeout;
    }
#endif

    for (int index = base->shifterBaseIndex + BISS_FRAME_BUFFER_NUM - 1; index >= base->shifterBaseIndex; index--)
    {
        *rxData = base->flexioBase->SHIFTBUFBIS[index];
        rxData++;
    }

    return kStatus_Success;
}

/*!
 * @brief Receives the buffer of one frame.
 *
 * note This function receives one frame in the nonblocking way.
 *
 * @param base Pointer to the FLEXIO_BISS_Type structure.
 * @param rxData The buffer to store the received bytes.
 * @param rxSize The number of 32-bit buffer to be received.
 * @retval kStatus_Fail The length of the receive buffer is less than the minimum value.
 * @retval kStatus_Success Successfully received all data.
 */
status_t FLEXIO_BISS_ReadNonBlocking(FLEXIO_BISS_Type *base, uint32_t *rxData, uint8_t rxSize)
{
    if (rxSize < BISS_FRAME_BUFFER_NUM)
    {
        return kStatus_Fail;
    }

    for (int index = base->shifterBaseIndex + BISS_FRAME_BUFFER_NUM - 1; index >= base->shifterBaseIndex; index--)
    {
        *rxData = base->flexioBase->SHIFTBUFBIS[index];
        rxData++;
    }

    return kStatus_Success;
}

/*!
 * @brief Updates the bit number of the corresponding field
 *
 * @param frame Pointer to the flexio_biss_frame_t structure.
 * @param field Specifies the BiSS field
 * @param bits Sets the new bit number to the corresponding field
 * @retval kStatus_Success Successfully updated the bit number
 * @retval kStatus_OutOfRange The update is failed
 */
status_t FLEXIO_BISS_UpdateFieldBit(flexio_biss_frame_t *frame, flexio_biss_frame_field_t field, uint8_t bits)
{
    switch (field)
    {
    case kFLEXIO_BISS_FIELD_HD:
        frame->headBits = bits;
        goto total;

    case kFLEXIO_BISS_FIELD_MT:
        frame->mtBits = bits;
        goto data;

    case kFLEXIO_BISS_FIELD_ST:
        frame->stBits = bits;
        goto data;

    case kFLEXIO_BISS_FIELD_CRC:
        frame->crcBits = bits;
        goto total;

    case kFLEXIO_BISS_FIELD_CDM:
        frame->cdmBits = bits;
        goto whole;

    default:
        return kStatus_Success;
    }
data:
    frame->dataBits  = BISS_DATA_LEN(frame);
total:
    frame->totalBits = BISS_TOTAL_LEN(frame);
whole:
    frame->wholeBits = BISS_WHOLE_LEN(frame);

    if (frame->wholeBits > 64)
    {
        return kStatus_OutOfRange;
    }
    return kStatus_Success;
}

/*!
 * @brief Calculates the bit number of the header in one frame
 *
 * @param data The data receiced from the BiSS encoder
 * @return The bit number of the header in one frame
 */
uint8_t FLEXIO_BISS_CalFrameHeadLen(uint64_t *data)
{
    uint64_t frame = *data;
    uint64_t mask = 0x8000000000000000;
    uint8_t flag = 0;
    uint8_t headBits = 0;

    for (int i = 0; i < 64; i++)
    {
        if (frame & (mask >> i))
        {
            if (flag == 0)
            {
                flag = 1;
            }
            if (flag == 1)
            {
                headBits++;
            }
            if (flag == 2)
            {
                break;
            }
        }
        else
        {
            if (flag == 1)
            {
                flag = 2;
            }
            if (flag == 2)
            {
                headBits++;
            }
        }
    }
    return headBits + 2;
}

