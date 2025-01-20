/*
 * Copyright 2020-2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_pwm.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_pwm"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get the instance from the base address
 *
 * @param base PWM peripheral base address
 *
 * @return The PWM module instance
 */
static uint32_t PWM_GetInstance(PWM_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to PWM bases for each instance. */
static PWM_Type *const s_pwmBases[] = PWM_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to PWM clocks for each PWM submodule. */
static const clock_ip_name_t s_pwmClocks[][FSL_FEATURE_PWM_SUBMODULE_COUNT] = PWM_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/

static uint32_t PWM_GetInstance(PWM_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_pwmBases); instance++)
    {
        if (s_pwmBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_pwmBases));

    return instance;
}

/*!
 * brief Initialization PWM module with provided structure @ref pwm_config_t.
 *
 * This function can initial one or more submodules of the PWM module.
 *
 * This examples shows how only initial submodule 0 without fault protection channel.
 * code
 *     pwm_config_t sPwmConfig = {0};
 *     pwm_sm_config_t sPwmSm0Config;
 *     sPwmConfig.psPwmSubmoduleConfig[0] = &sPwmSm0Config;
 *     PWM_GetSmDefaultConfig(&sPwmSm0Config);
 *     PWM_Init(PWM, sPwmConfig);
 * endcode
 *
 * note This API should be called at the beginning of the application using the PWM driver.
 *
 * param base        PWM peripheral base address.
 * param psConfig    Pointer to PWM module configure structure. See @ref pwm_config_t.
 */
void PWM_Init(PWM_Type *base, const pwm_config_t *psConfig)
{
    assert(NULL != psConfig);
    uint16_t u16EnableMask = 0u;

    for (uint16_t i = 0; i < (uint16_t)FSL_FEATURE_PWM_SUBMODULE_COUNT; i++)
    {
        if (psConfig->psPwmSubmoduleConfig[i] != NULL)
        {
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
            /* Enable the PWM submodule clock*/
            CLOCK_EnableClock(s_pwmClocks[PWM_GetInstance(base)][i]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
            PWM_SetupSMConfig(base, (pwm_sm_number_t)i, psConfig->psPwmSubmoduleConfig[i]);
            u16EnableMask |= (uint16_t)(psConfig->psPwmSubmoduleConfig[i]->enableRun) << (uint16_t)i;
        }
    }

    for (uint16_t i = 0; i < (uint16_t)FSL_FEATURE_PWM_FAULT_CH_COUNT; i++)
    {
        if (psConfig->psFaultProtectionConfig[i] != NULL)
        {
            PWM_SetupFaultProtectionConfig(base, (pwm_fault_protection_channel_t)i,
                                           psConfig->psFaultProtectionConfig[i]);
        }
    }
    if (u16EnableMask != 0U)
    {
        PWM_EnableCounters(base, u16EnableMask);
    }
}

/*!
 * brief De-initialization a PWM module.
 *
 * param base   PWM peripheral base address
 */
void PWM_Deinit(PWM_Type *base)
{
    /* Disable all submodule counter */
    PWM_DisableCounters(base, (uint16_t)kPWM_ALLSubModuleEnable);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    for (uint32_t i = 0U; i < (uint32_t)FSL_FEATURE_PWM_SUBMODULE_COUNT; i++)
    {
        /* Gate the PWM submodule clock*/
        CLOCK_DisableClock(s_pwmClocks[PWM_GetInstance(base)][i]);
    }
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Gets an default PWM submodule's configuration.
 *
 * This function fills in the submodule configure structure member, which can make submodule generate 50% duty cycle
 *  center-aligned PWM_A/B output.
 *
 * The default effective values are:
 * code
 *   psConfig->enableDebugMode = false;
 *   psConfig->enableWaitMode = false;
 *   psConfig->enableRun = false;
 *   psConfig->sCounterConfig.eCountClockSource = kPWM_ClockSrcBusClock;
 *   psConfig->sCounterConfig.eCountClockPrescale = kPWM_ClockPrescaleDivide1;
 *   psConfig->sCounterConfig.eCountInitSource = kPWM_InitOnLocalSync;
 *   psConfig->sReloadConfig.eReloadSignalSelect = kPWM_LocalReloadSignal;
 *   psConfig->sReloadConfig.eLoclReloadEffectTime = kPWM_TakeEffectAtReloadOportunity;
 *   psConfig->sReloadConfig.eLocalReloadOportunity = kPWM_LoadEveryOportunity;
 *   psConfig->sReloadConfig.bEnableFullCycleReloadOportunity = true;
 *   psConfig->sReloadConfig.bEnableHalfCycleReloadOportunity = false;
 *   psConfig->sValRegisterConfig.u16CounterInitialValue = 0xFF00U;
 *   psConfig->sValRegisterConfig.u16ValRegister0 = 0x0U;
 *   psConfig->sValRegisterConfig.u16ValRegister1 = 0x00FFU;
 *   psConfig->sValRegisterConfig.u16ValRegister2 = 0xFF80U;
 *   psConfig->sValRegisterConfig.u16ValRegister3 = 0x80U;
 *   psConfig->sValRegisterConfig.u16ValRegister4 = 0xFF80U;
 *   psConfig->sValRegisterConfig.u16ValRegister5 = 0x80U;
 *   psConfig->sForceConfig.eForceSignalSelect = kPWM_LocalSoftwareForce;
 *   psConfig->sForceConfig.eSoftOutputFor23 = kPWM_SoftwareOutputLow;
 *   psConfig->sForceConfig.eSoftOutputFor45 = kPWM_SoftwareOutputLow;
 *   psConfig->sForceConfig.eForceOutput23 = kPWM_GeneratedPwm;
 *   psConfig->sForceConfig.eForceOutput45 = kPWM_GeneratedPwm;
 *   psConfig->sDeadTimeConfig.eMode = kPWM_Independent;
 *   psConfig->sOutputConfig.ePwmXSignalSelect = kPWM_RawPwmX;
 *   psConfig->sOutputConfig.bEnablePwmxOutput = true;
 *   psConfig->sOutputConfig.bEnablePwmaOutput = true;
 *   psConfig->sOutputConfig.bEnablePwmbOutput = true;
 *   psConfig->sOutputConfig.ePwmxFaultState = kPWM_OutputLowOnFault;
 *   psConfig->sOutputConfig.ePwmaFaultState = kPWM_OutputLowOnFault;
 *   psConfig->sOutputConfig.ePwmbFaultState = kPWM_OutputLowOnFault;
 * endcode
 * param psConfig  Pointer to user's PWM submodule configure structure. See @ref pwm_sm_config_t.
 */
void PWM_GetSMDefaultConfig(pwm_sm_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    psConfig->enableDebugMode = false;
    psConfig->enableWaitMode  = false;
    psConfig->enableRun       = false;
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD)
    psConfig->eValCompareMode = kPWM_CompareOnEqual;
#endif
    psConfig->sCounterConfig.eCountClockSource    = kPWM_ClockSrcBusClock;
    psConfig->sCounterConfig.eCountClockPrescaler = kPWM_ClockPrescaleDivide1;
    psConfig->sCounterConfig.eCountInitSource     = kPWM_InitOnLocalSync;
    psConfig->sCounterConfig.bEnableForceInitial  = false;
#if (defined(FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER) && FSL_FEATURE_PWM_HAS_PHASEDLY_REGISTER)
    psConfig->sCounterConfig.u16PhaseDelayValue = 0x0U;
#endif
    psConfig->sReloadConfig.eReloadSignalSelect              = kPWM_LocalReloadSignal;
    psConfig->sReloadConfig.eLoclReloadEffectTime            = kPWM_TakeEffectAtReloadOportunity;
    psConfig->sReloadConfig.eLocalReloadOportunity           = kPWM_LoadEveryOportunity;
    psConfig->sReloadConfig.bEnableFullCycleReloadOportunity = true;
    psConfig->sReloadConfig.bEnableHalfCycleReloadOportunity = false;
    psConfig->sValRegisterConfig.u16CounterInitialValue      = 0xFF00U;
    psConfig->sValRegisterConfig.u16ValRegister0             = 0x0U;
    psConfig->sValRegisterConfig.u16ValRegister1             = 0x00FFU;
    psConfig->sValRegisterConfig.u16ValRegister2             = 0xFF80U;
    psConfig->sValRegisterConfig.u16ValRegister3             = 0x80U;
    psConfig->sValRegisterConfig.u16ValRegister4             = 0xFF80U;
    psConfig->sValRegisterConfig.u16ValRegister5             = 0x80U;

    psConfig->sForceConfig.bitPWM23OutputInitialVaule = 0U;
    psConfig->sForceConfig.bitPWM45OutputInitialVaule = 0U;
    psConfig->sForceConfig.bitPWMXOutputInitialVaule  = 0U;
    psConfig->sForceConfig.eForceSignalSelect         = kPWM_LocalSoftwareForce;
    psConfig->sForceConfig.eSoftOutputFor23           = kPWM_SoftwareOutputLow;
    psConfig->sForceConfig.eSoftOutputFor45           = kPWM_SoftwareOutputLow;
    psConfig->sForceConfig.eForceOutput23             = kPWM_GeneratedPwm;
    psConfig->sForceConfig.eForceOutput45             = kPWM_GeneratedPwm;

    psConfig->sDeadTimeConfig.eMode                             = kPWM_Independent;
    psConfig->sDeadTimeConfig.sDeadTimeValue0.bitsIntegerCycles = 0x0U;
    psConfig->sDeadTimeConfig.sDeadTimeValue1.bitsIntegerCycles = 0x0U;

#if (defined(FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT) && (FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT == 16U))
    psConfig->sDeadTimeConfig.sDeadTimeValue0.bitsFractionalCycles = 0x0U;
    psConfig->sDeadTimeConfig.sDeadTimeValue1.bitsFractionalCycles = 0x0U;
#endif

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
    psConfig->sFracDelayConfig.bitsFracValue1                      = 0x0U;
    psConfig->sFracDelayConfig.bitsFracValue2                      = 0x0U;
    psConfig->sFracDelayConfig.bitsFracValue3                      = 0x0U;
    psConfig->sFracDelayConfig.bitsFracValue4                      = 0x0U;
    psConfig->sFracDelayConfig.bitsFracValue5                      = 0x0U;
    psConfig->sFracDelayConfig.bEnableVal1FractionalDelay          = false;
    psConfig->sFracDelayConfig.bEnableVal23FractionalDelay         = false;
    psConfig->sFracDelayConfig.bEnableVal45FractionalDelay         = false;
#endif

    psConfig->sOutputConfig.bVal0TriggerEnable = false;
    psConfig->sOutputConfig.bVal1TriggerEnable = false;
    psConfig->sOutputConfig.bVal2TriggerEnable = false;
    psConfig->sOutputConfig.bVal3TriggerEnable = false;
    psConfig->sOutputConfig.bVal4TriggerEnable = false;
    psConfig->sOutputConfig.bVal5TriggerEnable = false;
#if (defined(FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD) && FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD)
    psConfig->sOutputConfig.bEnableTriggerPostScaler = false;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL) && FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL)
    psConfig->sOutputConfig.eMuxTrigger0 = kPWM_ActualCompareEvent;
    psConfig->sOutputConfig.eMuxTrigger1 = kPWM_ActualCompareEvent;
#endif
    psConfig->sOutputConfig.ePwmXSignalSelect = kPWM_RawPwmX;
    psConfig->sOutputConfig.bInvertPwmxOutput = false;
    psConfig->sOutputConfig.bInvertPwmaOutput = false;
    psConfig->sOutputConfig.bInvertPwmbOutput = false;
    psConfig->sOutputConfig.bMaskPwmxOutput   = false;
    psConfig->sOutputConfig.bMaskPwmaOutput   = false;
    psConfig->sOutputConfig.bMaskPwmbOutput   = false;
    psConfig->sOutputConfig.bEnablePwmxOutput = true;
    psConfig->sOutputConfig.bEnablePwmaOutput = true;
    psConfig->sOutputConfig.bEnablePwmbOutput = true;
    psConfig->sOutputConfig.ePwmxFaultState   = kPWM_OutputLowOnFault;
    psConfig->sOutputConfig.ePwmaFaultState   = kPWM_OutputLowOnFault;
    psConfig->sOutputConfig.ePwmbFaultState   = kPWM_OutputLowOnFault;

    for (uint32_t i = 0; i < 3U; i++)
    {
        psConfig->sInCaptureConfig[i].eInCaptureSource          = kPWM_RawInput;
        psConfig->sInCaptureConfig[i].eCircuit0CaptureEdge      = kPWM_Noedge;
        psConfig->sInCaptureConfig[i].eCircuit1CaptureEdge      = kPWM_Noedge;
        psConfig->sInCaptureConfig[i].bEnableOneShotCapture     = false;
        psConfig->sInCaptureConfig[i].bitsCaptureFifoWatermark  = 0x0U;
        psConfig->sInCaptureConfig[i].u8EdgeCounterCompareValue = 0x0U;

#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
        psConfig->sInCaptureConfig[i].u8FilterPeriod = 0x0U;
        psConfig->sInCaptureConfig[i].eFilterCount   = kPWM_InputCaptureFilterCount3Samples;
#endif /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */
    }

    psConfig->sPwmXFaultInputMapping.bFaultInput0Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput1Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput2Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput3Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput4Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput5Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput6Mapping = false;
    psConfig->sPwmXFaultInputMapping.bFaultInput7Mapping = false;

    psConfig->sPwmAFaultInputMapping.bFaultInput0Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput1Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput2Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput3Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput4Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput5Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput6Mapping = false;
    psConfig->sPwmAFaultInputMapping.bFaultInput7Mapping = false;

    psConfig->sPwmBFaultInputMapping.bFaultInput0Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput1Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput2Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput3Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput4Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput5Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput6Mapping = false;
    psConfig->sPwmBFaultInputMapping.bFaultInput7Mapping = false;

    psConfig->sDMAConfig.bEnableWriteValDMA      = false;
    psConfig->sDMAConfig.bEnableReadCaptureX0DMA = false;
    psConfig->sDMAConfig.bEnableReadCaptureX1DMA = false;
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER)
    psConfig->sDMAConfig.bEnableReadCaptureA0DMA = false;
    psConfig->sDMAConfig.bEnableReadCaptureA1DMA = false;
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER)
    psConfig->sDMAConfig.bEnableReadCaptureB0DMA = false;
    psConfig->sDMAConfig.bEnableReadCaptureB1DMA = false;
#endif
    psConfig->sDMAConfig.sCaptureDma.bEnableCaptureDMA = false;
    psConfig->sDMAConfig.sCaptureDma.eCaptureDMASource = kPWM_FIFOWatermarksORDma;
#if ((defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) && \
      FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD))
    psConfig->eStrBusClock = kPWM_StretchIPBusClockPrescaler1;
#endif

    psConfig->u16EnableInterruptMask = 0x0U;
}

/*!
 * brief Gets an default fault protection channel's configuration.
 *
 * The default effective values are:
 * code
 *   psConfig->sFaultInput[i].eFaultActiveLevel = kPWM_Logic0;
 *   psConfig->sFaultInput[i].bEnableAutoFaultClear = true;
 *   psConfig->sFaultInput[i].bEnableFaultFullCycleRecovery = true;
 * endcode
 * param psConfig  Pointer to fault protection configure structure. See @ref pwm_fault_protection_config_t.
 */
void PWM_GetFaultProtectionDefaultConfig(pwm_fault_protection_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(*psConfig));

    for (uint32_t i = 0; i < 4U; i++)
    {
        psConfig->sFaultInput[i].eFaultActiveLevel               = kPWM_Logic0;
        psConfig->sFaultInput[i].bEnableAutoFaultClear           = true;
        psConfig->sFaultInput[i].bEnableManualFaultClearSafeMode = false;
        psConfig->sFaultInput[i].bEnableFaultFullCycleRecovery   = true;
        psConfig->sFaultInput[i].bEnableFaultHalfCycleRecovery   = false;
#if (defined(FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER) && FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER)
        psConfig->sFaultInput[i].bEnableFaultNoCombinationalPath = true;
#endif
        psConfig->sFaultInput[i].bEnableFaultInterrupt = false;
    }

    psConfig->bEnableFaultGlitchStretch = false;
    psConfig->bitsFaultFilterCount      = 0x0U;
    psConfig->u8FaultFilterPeriod       = 0x0U;
}

/*!
 * brief Sets up the PWM submodule configure.
 *
 * param base         PWM peripheral base address.
 * param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig     Pointer to submodule configure structure, see @ref pwm_sm_config_t.
 */
void PWM_SetupSMConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Disable the submodule counter first */
    PWM_DisableCounters(base, (uint16_t)1U << (uint16_t)eSubModule);
    PWM_ClearPwmLdok(base, (uint16_t)1U << (uint16_t)eSubModule);
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_COMPMODE_BITFIELD)
    /* Only can be written one time after which it requires a reset to release the bit for writing again. */
    base->SM[eSubModule].CTRL =
        (base->SM[eSubModule].CTRL & ~(uint16_t)PWM_CTRL_COMPMODE_MASK) | PWM_CTRL_COMPMODE(psConfig->eValCompareMode);
#endif
    PWM_SetupCounterConfig(base, eSubModule, &psConfig->sCounterConfig);
    PWM_SetupReloadLogicConfig(base, eSubModule, &psConfig->sReloadConfig);
    PWM_SetupValRegisterConfig(base, eSubModule, &psConfig->sValRegisterConfig);
    PWM_SetupForceLogicConfig(base, eSubModule, &psConfig->sForceConfig);
#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
    PWM_SetupFractionalDelayConfig(base, eSubModule, &psConfig->sFracDelayConfig);
#endif
    PWM_SetupDeadtimeConfig(base, eSubModule, &psConfig->sDeadTimeConfig);
    PWM_SetupOutputConfig(base, eSubModule, &psConfig->sOutputConfig);
    PWM_SetupInputCaptureConfig(base, eSubModule, kPWM_InputCapturePwmX, &psConfig->sInCaptureConfig[0]);
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER)
    PWM_SetupInputCaptureConfig(base, eSubModule, kPWM_InputCapturePwmA, &psConfig->sInCaptureConfig[1]);
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER)
    PWM_SetupInputCaptureConfig(base, eSubModule, kPWM_InputCapturePwmB, &psConfig->sInCaptureConfig[2]);
#endif
    PWM_SetupSMFaultInputMapping(base, eSubModule, kPWM_PwmX, &psConfig->sPwmXFaultInputMapping);
    PWM_SetupSMFaultInputMapping(base, eSubModule, kPWM_PwmA, &psConfig->sPwmAFaultInputMapping);
    PWM_SetupSMFaultInputMapping(base, eSubModule, kPWM_PwmB, &psConfig->sPwmBFaultInputMapping);
    PWM_EnableSMInterrupts(base, eSubModule, psConfig->u16EnableInterruptMask);
    PWM_SetupDmaConfig(base, eSubModule, &psConfig->sDMAConfig);
    PWM_EnablePwmRunInDebug(base, eSubModule, psConfig->enableDebugMode);
    PWM_EnablePwmRunInWait(base, eSubModule, psConfig->enableWaitMode);

#if ((defined(FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD) && \
      FSL_FEATURE_PWM_MCTRL2_HAS_STRETCH_CNT_PRSC_BITFIELD))
    /* Set the PWM stretch IPBus clock count prescaler. */
    base->MCTRL2 |= PWM_MCTRL2_STRETCH_CNT_PRSC(&psConfig->eStrBusClock);
#endif

    /* Execute a software force initial when choose local software force signal */
    if (psConfig->sForceConfig.eForceSignalSelect == kPWM_LocalSoftwareForce)
    {
        PWM_SetSoftwareForce(base, eSubModule);
    }
    PWM_SetPwmLdok(base, (uint16_t)1U << (uint16_t)eSubModule);
}

/*!
 * brief Update PWM submodule compare value configuration according to the typical output mode.
 *
 * param psConfig             See @ref pwm_sm_config_t.
 * param eTypicalOutputMode   Typical PWM_A/B output mode. See @ref pwm_sm_typical_output_mode_t.
 * param u16PwmPeriod         PWM output period value in counter ticks. This value can be
 *                            got by (main counter clock in Hz) / (wanted PWM signal frequency in Hz).
 * param u16PwmAPulseWidth    PWM_A pulse width value in counter ticks. Can got by (wanted PWM duty Cycle) *
 *                            u16PwmPeriod.
 * param u16PwmBPulseWidth    PWM_B pulse width value in counter ticks. Can got by (wanted PWM duty Cycle) *
 *                            u16PwmPeriod.
 */
void PWM_GetValueConfig(pwm_sm_value_register_config_t *psConfig,
                        pwm_sm_typical_output_mode_t eTypicalOutputMode,
                        uint16_t u16PwmPeriod,
                        uint16_t u16PwmAPulseWidth,
                        uint16_t u16PwmBPulseWidth)
{
    switch (eTypicalOutputMode)
    {
        case kPWM_SignedCenterAligned:
            /* Indicates the start of the PWM period */
            psConfig->u16CounterInitialValue = ~(u16PwmPeriod / 2U) + 1U;
            /* Indicates the center value */
            psConfig->u16ValRegister0 = 0x0U;
            /* Indicates the end of the PWM period */
            /* The change during the end to start of the PWM period requires a count time */
            psConfig->u16ValRegister1 = (u16PwmPeriod / 2U) - 1U;
            /* Indicates the turn on of the PWM_A */
            psConfig->u16ValRegister2 = ~(u16PwmAPulseWidth / 2U) + 1U;
            /* Indicates the turn off of the PWM_A */
            psConfig->u16ValRegister3 = (u16PwmAPulseWidth / 2U);
            /* Indicates the turn on of the PWM_B */
            psConfig->u16ValRegister4 = ~(u16PwmBPulseWidth / 2U) + 1U;
            /* Indicates the turn off of the PWM_B */
            psConfig->u16ValRegister5 = (u16PwmBPulseWidth / 2U);
            break;
        case kPWM_CenterAligned:
            /* Indicates the start of the PWM period */
            psConfig->u16CounterInitialValue = 0U;
            /* Indicates the center value */
            psConfig->u16ValRegister0 = (u16PwmPeriod / 2U);
            /* Indicates the end of the PWM period */
            /* The change during the end to start of the PWM period requires a count time */
            psConfig->u16ValRegister1 = u16PwmPeriod - 1U;
            /* Indicates the turn on of the PWM_A */
            psConfig->u16ValRegister2 = ((u16PwmPeriod - u16PwmAPulseWidth) / 2U);
            /* Indicates the turn off of the PWM_A */
            psConfig->u16ValRegister3 = ((u16PwmPeriod + u16PwmAPulseWidth) / 2U);
            /* Indicates the turn on of the PWM_B */
            psConfig->u16ValRegister4 = ((u16PwmPeriod - u16PwmBPulseWidth) / 2U);
            /* Indicates the turn off of the PWM_B */
            psConfig->u16ValRegister5 = ((u16PwmPeriod + u16PwmBPulseWidth) / 2U);
            break;
        case kPWM_SignedEdgeAligned:
            /* Indicates the start of the PWM period */
            psConfig->u16CounterInitialValue = ~(u16PwmPeriod / 2U) + 1U;
            /* Indicates the center value */
            psConfig->u16ValRegister0 = 0x0U;
            /* Indicates the end of the PWM period */
            /* The change during the end to start of the PWM period requires a count time */
            psConfig->u16ValRegister1 = (u16PwmPeriod / 2U) - 1U;
            /* Indicates the turn on of the PWM_A */
            psConfig->u16ValRegister2 = ~(u16PwmPeriod / 2U) + 1U;
            /* Indicates the turn off of the PWM_A */
            psConfig->u16ValRegister3 = ~(u16PwmPeriod / 2U) + u16PwmAPulseWidth + 1U;
            /* Indicates the turn on of the PWM_B */
            psConfig->u16ValRegister4 = ~(u16PwmPeriod / 2U) + 1U;
            /* Indicates the turn off of the PWM_B */
            psConfig->u16ValRegister5 = ~(u16PwmPeriod / 2U) + u16PwmBPulseWidth + 1U;
            break;
        case kPWM_EdgeAligned:
            /* Indicates the start of the PWM period */
            psConfig->u16CounterInitialValue = 0U;
            /* Indicates the center value */
            psConfig->u16ValRegister0 = (u16PwmPeriod / 2U);
            /* Indicates the end of the PWM period */
            /* The change during the end to start of the PWM period requires a count time */
            psConfig->u16ValRegister1 = u16PwmPeriod - 1U;
            /* Indicates the turn on of the PWM_A */
            psConfig->u16ValRegister2 = 0U;
            /* Indicates the turn off of the PWM_A */
            psConfig->u16ValRegister3 = u16PwmAPulseWidth;
            /* Indicates the turn on of the PWM_B */
            psConfig->u16ValRegister4 = 0U;
            /* Indicates the turn off of the PWM_B */
            psConfig->u16ValRegister5 = u16PwmBPulseWidth;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }
}

/*!
 * brief Sets up the PWM submodule deadtime logic configure.
 *
 * param base          PWM peripheral base address.
 * param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig      Pointer to deadtime logic configure structure, see @ref pwm_sm_deadtime_logic_config_t.
 */
void PWM_SetupDeadtimeConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_deadtime_logic_config_t *psConfig)
{
    switch (psConfig->eMode)
    {
        case kPWM_Independent:
            base->SM[eSubModule].CTRL2 |= PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL &= ~(uint16_t)PWM_CTRL_DBLEN_MASK;
            break;
        case kPWM_IndependentWithDoubleSwitchPwm:
            base->SM[eSubModule].CTRL2 |= PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL |= PWM_CTRL_DBLEN_MASK;
            break;
#if (defined(FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD) && FSL_FEATURE_PWM_CTRL_HAS_SPLIT_BITFIELD)
        case kPWM_IndependentWithSplitDoubleSwitchPwm:
            base->SM[eSubModule].CTRL2 |= PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL |= PWM_CTRL_DBLEN_MASK | PWM_CTRL_SPLIT_MASK;
            break;
#endif
        case kPWM_ComplementaryWithPwmA:
            base->SM[eSubModule].CTRL2 &= ~(uint16_t)PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL &= ~(uint16_t)PWM_CTRL_DBLEN_MASK;
            base->MCTRL &= ~(((uint16_t)1U << (uint16_t)eSubModule) << PWM_MCTRL_IPOL_SHIFT);
            break;
        case kPWM_ComplementaryWithPwmB:
            base->SM[eSubModule].CTRL2 &= ~(uint16_t)PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL &= ~(uint16_t)PWM_CTRL_DBLEN_MASK;
            base->MCTRL |= (((uint16_t)1U << (uint16_t)eSubModule) << PWM_MCTRL_IPOL_SHIFT);
            break;
        case kPWM_ComplementaryWithDoubleSwitchPwm:
            base->SM[eSubModule].CTRL2 &= ~(uint16_t)PWM_CTRL2_INDEP_MASK;
            base->SM[eSubModule].CTRL |= PWM_CTRL_DBLEN_MASK;
            break;
        default:
            /* All the cases have been listed above, the default clause should not be reached. */
            assert(false);
            break;
    }

#if (defined(FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT) && (FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT == 11U))

    base->SM[eSubModule].DTCNT0 = psConfig->sDeadTimeValue0.bitsIntegerCycles;
    base->SM[eSubModule].DTCNT1 = psConfig->sDeadTimeValue1.bitsIntegerCycles;

#else

#if (defined(FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT) && (FSL_FEATURE_PWM_NUM_BITWIDTH_DTCNT == 16U))
    /* The DTCNT0/1 field is interpreted differently depending on whether or not the fractional delays are enabled. */
    if ((((base->SM[eSubModule].FRCTRL & PWM_FRCTRL_FRAC23_EN_MASK) != 0U) &&
         (((base->MCTRL & PWM_MCTRL_IPOL((uint16_t)1U << (uint16_t)eSubModule)) == 0U))) ||
        (((base->SM[eSubModule].FRCTRL & PWM_FRCTRL_FRAC45_EN_MASK) != 0U) &&
         (((base->MCTRL & PWM_MCTRL_IPOL((uint16_t)1U << (uint16_t)eSubModule)) != 0U))))
    {
        base->SM[eSubModule].DTCNT0 =
            (psConfig->sDeadTimeValue0.bitsIntegerCycles << 5U) | psConfig->sDeadTimeValue0.bitsFractionalCycles;
        base->SM[eSubModule].DTCNT1 =
            (psConfig->sDeadTimeValue1.bitsIntegerCycles << 5U) | psConfig->sDeadTimeValue1.bitsFractionalCycles;
    }
    else
    {
        base->SM[eSubModule].DTCNT0 = psConfig->sDeadTimeValue0.bitsIntegerCycles;
        base->SM[eSubModule].DTCNT1 = psConfig->sDeadTimeValue1.bitsIntegerCycles;
    }
#endif

#endif
}

#if (defined(FSL_FEATURE_PWM_HAS_FRACTIONAL) && FSL_FEATURE_PWM_HAS_FRACTIONAL)
/*!
 * brief Sets up the PWM submodule fractional delay logic configure.
 *
 * note The fractional delay logic can only be used when the IPBus clock is running at 100 MHz.
 *
 * param base         PWM peripheral base address.
 * param eSubModule   PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig     Pointer to fractional delay logic configure structure, see
 *                      @ref pwm_sm_fractional_delay_logic_config_t.
 */
void PWM_SetupFractionalDelayConfig(PWM_Type *base,
                                    pwm_sm_number_t eSubModule,
                                    const pwm_sm_fractional_delay_logic_config_t *psConfig)
{
    base->SM[eSubModule].FRACVAL1 = PWM_FRACVAL1_FRACVAL1(psConfig->bitsFracValue1);
    base->SM[eSubModule].FRACVAL2 = PWM_FRACVAL1_FRACVAL1(psConfig->bitsFracValue2);
    base->SM[eSubModule].FRACVAL3 = PWM_FRACVAL1_FRACVAL1(psConfig->bitsFracValue3);
    base->SM[eSubModule].FRACVAL4 = PWM_FRACVAL1_FRACVAL1(psConfig->bitsFracValue4);
    base->SM[eSubModule].FRACVAL5 = PWM_FRACVAL1_FRACVAL1(psConfig->bitsFracValue5);

    base->SM[eSubModule].FRCTRL =
        (uint16_t)(base->SM[eSubModule].FRCTRL &
                   ~(PWM_FRCTRL_FRAC45_EN_MASK | PWM_FRCTRL_FRAC23_EN_MASK | PWM_FRCTRL_FRAC1_EN_MASK)) |
        PWM_FRCTRL_FRAC45_EN(psConfig->bEnableVal45FractionalDelay) |
        PWM_FRCTRL_FRAC23_EN(psConfig->bEnableVal23FractionalDelay) |
        PWM_FRCTRL_FRAC1_EN(psConfig->bEnableVal1FractionalDelay);

#if defined(FSL_FEATURE_PWM_HAS_MICROEDGE) && FSL_FEATURE_PWM_HAS_MICROEDGE
    /* Power up fractional delay logic if anyone VAL fractional delay is enable */
    if (psConfig->bEnableVal45FractionalDelay || psConfig->bEnableVal23FractionalDelay ||
        psConfig->bEnableVal1FractionalDelay)
    {
        base->SM[eSubModule].FRCTRL |= PWM_FRCTRL_FRAC_PU_MASK;
        SDK_DelayAtLeastUs(25U, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
    }
    else
    {
        base->SM[eSubModule].FRCTRL &= ~(uint16_t)PWM_FRCTRL_FRAC_PU_MASK;
    }
#endif /* FSL_FEATURE_PWM_HAS_MICROEDGE */
}
#endif

/*!
 * brief Sets up the PWM submodule output logic configure.
 *
 * param base          PWM peripheral base address.
 * param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig      Pointer to output logic configure structure, see @ref pwm_sm_output_logic_config_t.
 */
void PWM_SetupOutputConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_output_logic_config_t *psConfig)
{
    uint16_t u16RegOuten = base->OUTEN;
    uint16_t u16RegMask  = base->MASK;

    u16RegOuten &= ~(PWM_OUTEN_PWMX_EN((uint16_t)1U << (uint16_t)eSubModule) |
                     PWM_OUTEN_PWMB_EN((uint16_t)1U << (uint16_t)eSubModule) |
                     PWM_OUTEN_PWMA_EN((uint16_t)1U << (uint16_t)eSubModule));
    u16RegMask &=
        ~(PWM_MASK_MASKX((uint16_t)1U << (uint16_t)eSubModule) | PWM_MASK_MASKB((uint16_t)1U << (uint16_t)eSubModule) |
          PWM_MASK_MASKA((uint16_t)1U << (uint16_t)eSubModule));

    u16RegOuten |= PWM_OUTEN_PWMX_EN((uint16_t)(psConfig->bEnablePwmxOutput) << (uint16_t)eSubModule) |
                   PWM_OUTEN_PWMA_EN((uint16_t)(psConfig->bEnablePwmaOutput) << (uint16_t)eSubModule) |
                   PWM_OUTEN_PWMB_EN((uint16_t)(psConfig->bEnablePwmbOutput) << (uint16_t)eSubModule);
    u16RegMask |= PWM_MASK_MASKX((uint16_t)(psConfig->bMaskPwmxOutput) << (uint16_t)eSubModule) |
                  PWM_MASK_MASKA((uint16_t)(psConfig->bMaskPwmaOutput) << (uint16_t)eSubModule) |
                  PWM_MASK_MASKB((uint16_t)(psConfig->bMaskPwmbOutput) << (uint16_t)eSubModule);

    base->SM[eSubModule].OCTRL =
        PWM_OCTRL_POLA(psConfig->bInvertPwmaOutput) | PWM_OCTRL_POLB(psConfig->bInvertPwmbOutput) |
        PWM_OCTRL_POLX(psConfig->bInvertPwmxOutput) | PWM_OCTRL_PWMAFS(psConfig->ePwmaFaultState) |
        PWM_OCTRL_PWMBFS(psConfig->ePwmbFaultState) | PWM_OCTRL_PWMXFS(psConfig->ePwmxFaultState);
#if (defined(FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD) && FSL_FEATURE_PWM_TCTRL_HAS_TRGFRQ_BITFIELD)
    base->SM[eSubModule].TCTRL = PWM_TCTRL_TRGFRQ(psConfig->bEnableTriggerPostScaler);
#endif
#if (defined(FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL) && FSL_FEATURE_PWM_HAS_MUX_TRIGGER_SOURCE_SEL)
    base->SM[eSubModule].TCTRL |= PWM_TCTRL_PWBOT1(psConfig->eMuxTrigger1) | PWM_TCTRL_PWAOT0(psConfig->eMuxTrigger0);
#endif
    base->SM[eSubModule].CTRL =
        (base->SM[eSubModule].CTRL & ~(uint16_t)(PWM_CTRL_DBLX_MASK)) | PWM_CTRL_DBLX(psConfig->ePwmXSignalSelect);

    base->OUTEN = u16RegOuten;
#if (defined(FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD) && FSL_FEATURE_PWM_MASK_HAS_UPDATE_MASK_BITFIELD)
    /* Update output mask bits with force command */
    base->MASK = u16RegMask | PWM_MASK_UPDATE_MASK((uint16_t)1U << (uint16_t)eSubModule);
#endif
}

/*!
 * brief Sets up the PWM submodule input capture configure.
 *
 * Each PWM submodule has 3 pins that can be configured for use as input capture pins. This function
 * sets up the capture parameters for each pin and enables the input capture operation.
 *
 * param base          PWM peripheral base address.
 * param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * param eInputPin     PWM submodule input capture pin number, see @ref pwm_sm_input_capture_pin_t.
 * param psConfig      Pointer to input capture configure structure, see @ref pwm_sm_input_capture_config_t.
 */
void PWM_SetupInputCaptureConfig(PWM_Type *base,
                                 pwm_sm_number_t eSubModule,
                                 pwm_sm_input_capture_pin_t eInputPin,
                                 const pwm_sm_input_capture_config_t *psConfig)
{
    uint16_t u16Reg;
    if (eInputPin == kPWM_InputCapturePwmX)
    {
        u16Reg = PWM_CAPTCTRLX_CFXWM(psConfig->bitsCaptureFifoWatermark) |
                 PWM_CAPTCTRLX_INP_SELX(psConfig->eInCaptureSource) |
                 PWM_CAPTCTRLX_EDGX1(psConfig->eCircuit1CaptureEdge) |
                 PWM_CAPTCTRLX_EDGX0(psConfig->eCircuit0CaptureEdge) |
                 PWM_CAPTCTRLX_ONESHOTX(psConfig->bEnableOneShotCapture);
        if (psConfig->eInCaptureSource == kPWM_InputEdgeCounter)
        {
            u16Reg |= PWM_CAPTCTRLX_EDGCNTX_EN_MASK;
        }
        if (psConfig->bEnableInputCapture)
        {
            u16Reg |= PWM_CAPTCTRLX_ARMX_MASK;
            /* Disable PWM_X output when PWM_X pin is being used for input capture. */
            base->OUTEN &= ~PWM_OUTEN_PWMX_EN((uint16_t)1U << (uint16_t)eSubModule);
        }
        base->SM[eSubModule].CAPTCOMPX = psConfig->u8EdgeCounterCompareValue;
        base->SM[eSubModule].CAPTCTRLX = u16Reg;
#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
        base->SM[eSubModule].CAPTFILTX = 0U; /* Clear the filter period first. */
        base->SM[eSubModule].CAPTFILTX = PWM_CAPTFILTX_CAPTX_FILT_PER(psConfig->u8FilterPeriod) |
                                         PWM_CAPTFILTX_CAPTX_FILT_CNT(psConfig->eFilterCount);
#endif /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */
    }
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER)
    else if (eInputPin == kPWM_InputCapturePwmA)
    {
        u16Reg = PWM_CAPTCTRLA_CFAWM(psConfig->bitsCaptureFifoWatermark) |
                 PWM_CAPTCTRLA_INP_SELA(psConfig->eInCaptureSource) |
                 PWM_CAPTCTRLA_EDGA1(psConfig->eCircuit1CaptureEdge) |
                 PWM_CAPTCTRLA_EDGA0(psConfig->eCircuit0CaptureEdge) |
                 PWM_CAPTCTRLA_ONESHOTA(psConfig->bEnableOneShotCapture);
        if (psConfig->eInCaptureSource == kPWM_InputEdgeCounter)
        {
            u16Reg |= PWM_CAPTCTRLA_EDGCNTA_EN_MASK;
        }
        if (psConfig->bEnableInputCapture)
        {
            u16Reg |= PWM_CAPTCTRLA_ARMA_MASK;
            /* Disable PWM_A output when PWM_A pin is being used for input capture. */
            base->OUTEN &= ~PWM_OUTEN_PWMA_EN((uint16_t)1U << (uint16_t)eSubModule);
        }
        base->SM[eSubModule].CAPTCOMPA = psConfig->u8EdgeCounterCompareValue;
        base->SM[eSubModule].CAPTCTRLA = u16Reg;
#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
        base->SM[eSubModule].CAPTFILTA = 0U; /* Clear the filter period first. */
        base->SM[eSubModule].CAPTFILTA = PWM_CAPTFILTA_CAPTA_FILT_PER(psConfig->u8FilterPeriod) |
                                         PWM_CAPTFILTA_CAPTA_FILT_CNT(psConfig->eFilterCount);
#endif /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */
    }
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER)
    else
    {
        u16Reg = PWM_CAPTCTRLB_CFBWM(psConfig->bitsCaptureFifoWatermark) |
                 PWM_CAPTCTRLB_INP_SELB(psConfig->eInCaptureSource) |
                 PWM_CAPTCTRLB_EDGB1(psConfig->eCircuit1CaptureEdge) |
                 PWM_CAPTCTRLB_EDGB0(psConfig->eCircuit0CaptureEdge) |
                 PWM_CAPTCTRLB_ONESHOTB(psConfig->bEnableOneShotCapture);
        if (psConfig->eInCaptureSource == kPWM_InputEdgeCounter)
        {
            u16Reg |= PWM_CAPTCTRLB_EDGCNTB_EN_MASK;
        }
        if (psConfig->bEnableInputCapture)
        {
            u16Reg |= PWM_CAPTCTRLB_ARMB_MASK;
            /* Disable PWM_B output when PWM_B pin is being used for input capture. */
            base->OUTEN &= ~PWM_OUTEN_PWMB_EN((uint16_t)1U << (uint16_t)eSubModule);
        }
        base->SM[eSubModule].CAPTCOMPB = psConfig->u8EdgeCounterCompareValue;
        base->SM[eSubModule].CAPTCTRLB = u16Reg;
#if (defined(FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER)
        base->SM[eSubModule].CAPTFILTB = 0U; /* Clear the filter period first. */
        base->SM[eSubModule].CAPTFILTB = PWM_CAPTFILTB_CAPTB_FILT_PER(psConfig->u8FilterPeriod) |
                                         PWM_CAPTFILTB_CAPTB_FILT_CNT(psConfig->eFilterCount);
#endif /* FSL_FEATURE_PWM_HAS_CAPTFILT_REGISTER */
    }
#endif
}

/*!
 * brief Sets up the PWM fault protection channel configure.
 *
 * param base                PWM peripheral base address.
 * param eFaultProtection    PWM fault protection channel number, see @ref pwm_fault_protection_channel_t.
 * param psConfig            Pointer to fault protection channel configure structure, see @ref
 * pwm_fault_protection_config_t.
 */
void PWM_SetupFaultProtectionConfig(PWM_Type *base,
                                    pwm_fault_protection_channel_t eFaultProtection,
                                    const pwm_fault_protection_config_t *psConfig)
{
    uint16_t u16RegsFctrl = 0;
    uint16_t u16RegsFSTS  = 0;
    for (uint16_t i = 0; i < 4U; i++)
    {
        u16RegsFctrl |= PWM_FCTRL_FLVL((uint16_t)psConfig->sFaultInput[i].eFaultActiveLevel << i) |
                        PWM_FCTRL_FAUTO((uint16_t)psConfig->sFaultInput[i].bEnableAutoFaultClear << i) |
                        PWM_FCTRL_FSAFE((uint16_t)psConfig->sFaultInput[i].bEnableManualFaultClearSafeMode << i) |
                        PWM_FCTRL_FSAFE((uint16_t)psConfig->sFaultInput[i].bEnableFaultInterrupt << i);

        u16RegsFSTS |= PWM_FSTS_FHALF((uint16_t)psConfig->sFaultInput[i].bEnableFaultHalfCycleRecovery << i) |
                       PWM_FSTS_FFULL((uint16_t)psConfig->sFaultInput[i].bEnableFaultFullCycleRecovery << i);
    }

    base->FAULT[eFaultProtection].FCTRL = u16RegsFctrl;
    base->FAULT[eFaultProtection].FSTS  = u16RegsFSTS;
#if (defined(FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER) && FSL_FEATURE_PWM_HAS_FCTRL2_REGISTER)
    base->FAULT[eFaultProtection].FCTRL2 =
        PWM_FCTRL2_NOCOMB(psConfig->sFaultInput[0].bEnableFaultNoCombinationalPath) |
        PWM_FCTRL2_NOCOMB((uint16_t)psConfig->sFaultInput[1].bEnableFaultNoCombinationalPath << (uint16_t)1U) |
        PWM_FCTRL2_NOCOMB((uint16_t)psConfig->sFaultInput[2].bEnableFaultNoCombinationalPath << (uint16_t)2U) |
        PWM_FCTRL2_NOCOMB((uint16_t)psConfig->sFaultInput[3].bEnableFaultNoCombinationalPath << (uint16_t)3U);
#endif

    base->FAULT[eFaultProtection].FFILT = PWM_FFILT_GSTR(psConfig->bEnableFaultGlitchStretch) |
                                          PWM_FFILT_GSTR(psConfig->bitsFaultFilterCount) |
                                          PWM_FFILT_GSTR(psConfig->u8FaultFilterPeriod);
}

/*!
 * brief Sets up the PWM submodule DMA configure.
 *
 * param base          PWM peripheral base address.
 * param eSubModule    PWM submodule number, see @ref pwm_sm_number_t.
 * param psConfig      Pointer to PWM submodule DMA configure, see @ref pwm_sm_dma_config_t.
 */
void PWM_SetupDmaConfig(PWM_Type *base, pwm_sm_number_t eSubModule, const pwm_sm_dma_config_t *psConfig)
{
    base->SM[eSubModule].DMAEN =
        PWM_DMAEN_VALDE(psConfig->bEnableWriteValDMA) |
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLA_REGISTER)
        PWM_DMAEN_CA1DE(psConfig->bEnableReadCaptureA1DMA) | PWM_DMAEN_CA0DE(psConfig->bEnableReadCaptureA0DMA) |
#endif
#if (defined(FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER) && FSL_FEATURE_PWM_HAS_CAPTCTRLB_REGISTER)
        PWM_DMAEN_CB1DE(psConfig->bEnableReadCaptureB1DMA) | PWM_DMAEN_CB0DE(psConfig->bEnableReadCaptureB0DMA) |
#endif
        PWM_DMAEN_CX1DE(psConfig->bEnableReadCaptureX1DMA) | PWM_DMAEN_CX0DE(psConfig->bEnableReadCaptureX0DMA);

    if (psConfig->sCaptureDma.bEnableCaptureDMA)
    {
        PWM_SetEnabledCaptureDmaSource(base, eSubModule, psConfig->sCaptureDma.eCaptureDMASource);
    }
}
