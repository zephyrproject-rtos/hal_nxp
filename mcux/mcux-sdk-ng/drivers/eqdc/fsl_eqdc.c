/*
 * Copyright 2022, 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_eqdc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.eqdc"
#endif

#if defined(EQDC_RSTS)
#define EQDC_RESETS_ARRAY EQDC_RSTS
#endif
/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for EQDC module.
 *
 * @param base EQDC peripheral base address
 */
static uint32_t EQDC_GetInstance(EQDC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to EQDC bases for each instance. */
static EQDC_Type *const s_eqdcBases[] = EQDC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to EQDC clocks for each instance. */
#if defined(QDC_CLOCKS)
static const clock_ip_name_t s_eqdcClocks[] = QDC_CLOCKS;
#elif defined(ENC_CLOCKS)
static const clock_ip_name_t s_eqdcClocks[] = ENC_CLOCKS;
#endif
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(EQDC_RESETS_ARRAY)
/* Reset array */
static const reset_ip_name_t s_eqdcResets[] = EQDC_RESETS_ARRAY;
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t EQDC_GetInstance(EQDC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_eqdcBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_eqdcBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_eqdcBases));

    return instance;
}

/*
 * Initializes the EQDC module.
 *
 * This function initializes the EQDC by enabling the IP bus clock (optional).
 *
 * param base   EQDC peripheral base address.
 * param psConfig Pointer to configuration structure.
 */
void EQDC_Init(EQDC_Type *base, const eqdc_config_t *psConfig)
{
    uint16_t imrTemp;
    uint16_t filtTemp;
    uint16_t ctrlTemp;
    uint16_t ctrl2Temp;

    assert(NULL != psConfig);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_eqdcClocks[EQDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(EQDC_RESETS_ARRAY)
    RESET_ReleasePeripheralReset(s_eqdcResets[EQDC_GetInstance(base)]);
#endif

    /* Initialize Double-set registers */
    EQDC_ClearBufferedRegisterLoadUpdateMode(base);
    EQDC_ClearEqdcLdok(base);
    
    /* Counter value. */
    EQDC_SetPositionCounterValue(base, psConfig->positionCounterValue);

    /* Initial value. */
    EQDC_SetInitialPositionValue(base, psConfig->positionInitialValue);

    /* Modulus value. */
    EQDC_SetPositionModulusValue(base, psConfig->positionModulusValue);

    /* Compare value. */
    EQDC_SetPositionCompare0Value(base, psConfig->positionCompareValue[0]);
    EQDC_SetPositionCompare1Value(base, psConfig->positionCompareValue[1]);
    EQDC_SetPositionCompare2Value(base, psConfig->positionCompareValue[2]);
    EQDC_SetPositionCompare3Value(base, psConfig->positionCompareValue[3]);

    EQDC_SetEqdcLdok(base);
    while (EQDC_GetEqdcLdok(base) != 0U)
    {
    }

    /* Watchdog. */
    EQDC_SetWatchdogTimeout(base, psConfig->watchdogTimeoutValue);

    /* Clear EQDC_REV */
    base->REV = 0U;

    /* EQDC_IMR. */
    imrTemp = base->IMR;

    imrTemp = (psConfig->filterPhaseA) ? (imrTemp | (uint16_t)EQDC_IMR_FPHA_MASK) :
                                         (imrTemp & (uint16_t)(~EQDC_IMR_FPHA_MASK));

    imrTemp = (psConfig->filterPhaseB) ? (imrTemp | (uint16_t)EQDC_IMR_FPHB_MASK) :
                                         (imrTemp & (uint16_t)(~EQDC_IMR_FPHB_MASK));

    imrTemp = (psConfig->filterIndPre) ? (imrTemp | (uint16_t)EQDC_IMR_FIND_PRE_MASK) :
                                         (imrTemp & (uint16_t)(~EQDC_IMR_FIND_PRE_MASK));

    imrTemp = (psConfig->filterHomEna) ? (imrTemp | (uint16_t)EQDC_IMR_FHOM_ENA_MASK) :
                                         (imrTemp & (uint16_t)(~EQDC_IMR_FHOM_ENA_MASK));

    base->IMR = imrTemp;

    /* EQDC_FILT. */
    filtTemp = base->FILT;

    /* Prescaler used by LASTEDGE and POSDPER. */
    filtTemp = (filtTemp & (uint16_t)(~EQDC_FILT_PRSC_MASK)) | EQDC_FILT_PRSC(psConfig->prescaler);

    filtTemp = (psConfig->filterClockSourceselection) ? (filtTemp | (uint16_t)EQDC_FILT_FILT_CS_MASK) :
                                                        (filtTemp & (uint16_t)(~EQDC_FILT_FILT_CS_MASK));

    filtTemp = (filtTemp & (uint16_t)(~EQDC_FILT_FILT_CNT_MASK)) | EQDC_FILT_FILT_CNT(psConfig->filterSampleCount);

    filtTemp = (filtTemp & (uint16_t)(~EQDC_FILT_FILT_PER_MASK)) | EQDC_FILT_FILT_PER(psConfig->filterSamplePeriod);

    base->FILT = filtTemp;

    /* EQDC_CTRL. */
    ctrlTemp = base->CTRL;

    /* HOME Enable trigger. */
    ctrlTemp = (ctrlTemp & (uint16_t)(~(EQDC_CTRL_HIP_MASK | EQDC_CTRL_HNE_MASK))) |
               (uint16_t)psConfig->homeEnableInitPosCounterMode;

    /* INDEX Preset trigger. */
    ctrlTemp = (ctrlTemp & (uint16_t)(~(EQDC_CTRL_XIP_MASK | EQDC_CTRL_XNE_MASK))) |
               (uint16_t)psConfig->indexPresetInitPosCounterMode;

    /* Reverse direction. */
    ctrlTemp = (psConfig->enableReverseDirection) ? (ctrlTemp | (uint16_t)EQDC_CTRL_REV_MASK) :
                                                    (ctrlTemp & (uint16_t)(~EQDC_CTRL_REV_MASK));

    /* Enable watchdog. */
    ctrlTemp = (psConfig->enableWatchdog) ? (ctrlTemp | (uint16_t)EQDC_CTRL_WDE_MASK) :
                                            (ctrlTemp & (uint16_t)(~EQDC_CTRL_WDE_MASK));

    /* Enable Dma. */
    ctrlTemp = (psConfig->enableDma) ? (ctrlTemp | (uint16_t)EQDC_CTRL_DMAEN_MASK) :
                                       (ctrlTemp & (uint16_t)(~EQDC_CTRL_DMAEN_MASK));

    /* W1C flags. */
    ctrlTemp |= (uint16_t)EQDC_CTRL_W1C_FLAGS;

    base->CTRL = ctrlTemp;

    /* EQDC_CTRL2. */
    ctrl2Temp = base->CTRL2;

    /* Set eqdc count mode. */
    ctrl2Temp = (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_CMODE_MASK)) | EQDC_CTRL2_CMODE(psConfig->countMode);

    /* Set eqdc modulo loop or one shot counting mode. */
    ctrl2Temp = (psConfig->countOnce) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_ONCE_MASK) :
                                        (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_ONCE_MASK));

    /* TRIGGER initializes position counter. */
    ctrl2Temp = (psConfig->enableTriggerInitPositionCounter) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_INITPOS_MASK) :
                                                               (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_INITPOS_MASK));

#if (defined(FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD) && FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD)
    /* Index Event Edge Mark initializes position counter. */
    ctrl2Temp = (psConfig->enableIndexInitPositionCounter) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_EMIP_MASK) :
                                                             (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_EMIP_MASK));
#endif /* FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD */

    /* Enable period measurement. */
    ctrl2Temp = (psConfig->enablePeriodMeasurement) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_PMEN_MASK) :
                                                      (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_PMEN_MASK));

    /* Output pulse. */
    ctrl2Temp = (psConfig->outputPulseMode) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_OUTCTL_MASK) :
                                              (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_OUTCTL_MASK));

    /* Revolution count condition. */
    ctrl2Temp = (psConfig->revolutionCountCondition) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_REVMOD_MASK) :
                                                       (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_REVMOD_MASK));

    /* Buffered register load (Update) mode select. */
    ctrl2Temp = (psConfig->bufferedRegisterLoadMode) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_LDMOD_MASK) :
                                                       (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_LDMOD_MASK));

    /* TRIGGER clears position register. */
    ctrl2Temp = (psConfig->enableTriggerClearPositionRegisters) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_UPDPOS_MASK) :
                                                                  (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_UPDPOS_MASK));

    /* TRIGGER loads position registers. */
    ctrl2Temp = (psConfig->enableTriggerHoldPositionRegisters) ? (ctrl2Temp | (uint16_t)EQDC_CTRL2_UPDHLD_MASK) :
                                                                  (ctrl2Temp & (uint16_t)(~EQDC_CTRL2_UPDHLD_MASK));

    base->CTRL2 = ctrl2Temp;

    /* Set mode of operation. */
    EQDC_SetOperateMode(base, psConfig->operateMode); /* eqdcoder work mode. */

    /* Enable interrupts. */
    EQDC_EnableInterrupts(base, psConfig->enabledInterruptsMask);
}

/*
 * De-initializes the EQDC module.
 *
 * This function deinitializes the EQDC by:
 * 1. Disables the IP bus clock (optional).
 *
 * param base EQDC peripheral base address.
 */
void EQDC_Deinit(EQDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_eqdcClocks[EQDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * Gets an available pre-defined configuration.
 *
 * The default value are:
 *    psConfig->enableReverseDirection              = false;
 *    psConfig->countOnce                           = false;
 *    psConfig->operateMode                         = kEQDC_QuadratureDecodeOperationMode;
 *    psConfig->countMode                           = kEQDC_QuadratureX4;
 *    psConfig->homeEnableInitPosCounterMode        = kEQDC_HomeInitPosCounterDisabled;
 *    psConfig->indexPresetInitPosCounterMode       = kEQDC_IndexInitPosCounterDisabled;
 *    psConfig->enableIndexInitPositionCounter      = false;
 *    psConfig->enableDma                           = false;
 *    psConfig->bufferedRegisterLoadMode            = false;
 *    psConfig->enableTriggerInitPositionCounter    = false;
 *    psConfig->enableTriggerClearPositionRegisters = false;
 *    psConfig->enableTriggerHoldPositionRegisters  = false;
 *    psConfig->enableWatchdog                      = false;
 *    psConfig->watchdogTimeoutValue                = 0xFFFFU;
 *    psConfig->filterPhaseA                        = 0U;
 *    psConfig->filterPhaseB                        = 0U;
 *    psConfig->filterIndPre                        = 0U;
 *    psConfig->filterHomEna                        = 0U;
 *    psConfig->filterClockSourceselection          = false;
 *    psConfig->filterSampleCount                   = kEQDC_Filter3Samples;
 *    psConfig->filterSamplePeriod                  = 0U;
 *    psConfig->outputPulseMode                     = kEQDC_OutputPulseOnCounterEqualCompare;
 *    psConfig->positionCompareValue[0]  	    = 0xFFFFFFFFU;
 *    psConfig->positionCompareValue[1]             = 0xFFFFFFFFU;
 *    psConfig->positionCompareValue[2]             = 0xFFFFFFFFU;
 *    psConfig->positionCompareValue[3]             = 0xFFFFFFFFU;
 *    psConfig->revolutionCountCondition            = kEQDC_RevolutionCountOnIndexPulse;
 *    psConfig->positionModulusValue                = 0U;
 *    psConfig->positionInitialValue                = 0U;
 *    psConfig->positionCounterValue                = 0U;
 *    psConfig->enablePeriodMeasurement             = false;
 *    psConfig->prescaler                           = kEQDC_Prescaler1;
 *    psConfig->enabledInterruptsMask               = 0U;
 *
 * param psConfig Pointer to configuration structure.
 */
void EQDC_GetDefaultConfig(eqdc_config_t *psConfig)
{
    assert(NULL != psConfig);

    psConfig->enableReverseDirection              = false;
    psConfig->countOnce                           = false;
    psConfig->operateMode                         = kEQDC_QuadratureDecodeOperationMode; /*!< Decode Mode. */
    psConfig->countMode                           = kEQDC_QuadratureX4;
    psConfig->homeEnableInitPosCounterMode        = kEQDC_HomeInitPosCounterDisabled;
    psConfig->indexPresetInitPosCounterMode       = kEQDC_IndexInitPosCounterDisabled;
#if (defined(FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD) && FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD)
    psConfig->enableIndexInitPositionCounter      = false;
#endif /* FSL_FEATURE_EQDC_CTRL2_HAS_EMIP_BIT_FIELD */
    psConfig->enableDma                           = false;
    psConfig->bufferedRegisterLoadMode            = false;
    psConfig->enableTriggerInitPositionCounter    = false;
    psConfig->enableTriggerClearPositionRegisters = false;
    psConfig->enableTriggerHoldPositionRegisters  = false;
    psConfig->enableWatchdog                      = false;
    psConfig->watchdogTimeoutValue                = 0xFFFFU;
    psConfig->filterPhaseA                        = 0U;
    psConfig->filterPhaseB                        = 0U;
    psConfig->filterIndPre                        = 0U;
    psConfig->filterHomEna                        = 0U;
    psConfig->filterClockSourceselection          = false;
    psConfig->filterSampleCount                   = kEQDC_Filter3Samples;
    psConfig->filterSamplePeriod                  = 0U;
    psConfig->outputPulseMode                     = kEQDC_OutputPulseOnCounterEqualCompare;
    psConfig->positionCompareValue[0]             = 0xFFFFFFFFU;
    psConfig->positionCompareValue[1]             = 0xFFFFFFFFU;
    psConfig->positionCompareValue[2]             = 0xFFFFFFFFU;
    psConfig->positionCompareValue[3]             = 0xFFFFFFFFU;
    psConfig->revolutionCountCondition            = kEQDC_RevolutionCountOnIndexPulse;
    psConfig->positionModulusValue                = 0U;
    psConfig->positionInitialValue                = 0U;
    psConfig->positionCounterValue                = 0U;
    psConfig->enablePeriodMeasurement             = false;
    psConfig->prescaler                           = kEQDC_Prescaler1;
    psConfig->enabledInterruptsMask               = 0U;
}

/*
 * Initializes the mode of operation.
 *
 * The Quadrature Decoder operates in following 4 operation modes:
 *   1.Quadrature Decode(QDC) Operation Mode (CTRL[PH1] = 0,CTRL2[OPMODE] = 0)
 *   2.Quadrature Count(QCT) Operation Mode (CTRL[PH1] = 0,CTRL2[OPMODE] = 1)
 *   3.Single Phase Decode(PH1DC) Operation Mode (CTRL[PH1] = 1,CTRL2[OPMODE] = 0)
 *   4.Single Phase Count(PH1CT) Operation Mode (CTRL[PH1] = 1,CTRL2[OPMODE] = 1)
 *
 * param base   EQDC peripheral base address.
 * param psConfig Pointer to configuration structure.
 */
void EQDC_SetOperateMode(EQDC_Type *base, eqdc_operate_mode_t operateMode)
{
    switch (operateMode)
    {
        case kEQDC_QuadratureDecodeOperationMode:
            base->CTRL &= ~EQDC_CTRL_PH1_MASK;
            base->CTRL2 &= ~EQDC_CTRL2_OPMODE_MASK;
            break;

        case kEQDC_QuadratureCountOperationMode:
            base->CTRL &= ~EQDC_CTRL_PH1_MASK;
            base->CTRL2 |= EQDC_CTRL2_OPMODE_MASK;
            break;

        case kEQDC_SinglePhaseDecodeOperationMode:
            base->CTRL |= EQDC_CTRL_PH1_MASK;
            base->CTRL2 &= ~EQDC_CTRL2_OPMODE_MASK;
            break;

        case kEQDC_SinglePhaseCountOperationMode:
            base->CTRL |= EQDC_CTRL_PH1_MASK;
            base->CTRL2 |= EQDC_CTRL2_OPMODE_MASK;
            break;

        default:
            assert(false);
            break;
    }
}