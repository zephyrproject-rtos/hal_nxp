/*
 * Copyright 2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_eqdc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_eqdc"
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
static const clock_ip_name_t s_eqdcClocks[] = QDC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t EQDC_GetInstance(EQDC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_eqdcBases); instance++)
    {
        if (s_eqdcBases[instance] == base)
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
    assert(NULL != psConfig);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_eqdcClocks[EQDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Initialize Double-set registers */
    EQDC_ClearBufferedRegisterLoadUpdateMode(base);
    EQDC_ClearEqdcLdok(base);

    /* Compare value. */
    EQDC_SetPositionCompare0Value(base, psConfig->u32PositionCompareValue[0]);
    EQDC_SetPositionCompare1Value(base, psConfig->u32PositionCompareValue[1]);
    EQDC_SetPositionCompare2Value(base, psConfig->u32PositionCompareValue[2]);
    EQDC_SetPositionCompare3Value(base, psConfig->u32PositionCompareValue[3]);

    /* Counter value. */
    EQDC_SetPositionCounterValue(base, psConfig->u32PositionCounterValue);

    /* Initial value. */
    EQDC_SetInitialPositionValue(base, psConfig->u32PositionInitialValue);

    /* Modulus value. */
    EQDC_SetPositionModulusValue(base, psConfig->u32PositionModulusValue);

    EQDC_SetEqdcLdok(base);
    while (0U != EQDC_GetEqdcLdok(base))
    {
    }

    /* Watchdog. */
    EQDC_SetWatchdogTimeout(base, psConfig->u16WatchdogTimeoutValue);

    /* EQDC_IMR. */
    base->IMR = EQDC_IMR_FPHA(psConfig->bFilterPhaseA) | EQDC_IMR_FPHB(psConfig->bFilterPhaseB) |
                EQDC_IMR_FIND_PRE(psConfig->bFilterIndPre) | EQDC_IMR_FHOM_ENA(psConfig->bFilterHomEna);

    /* EQDC_FILT. */
    base->FILT = EQDC_FILT_PRSC(psConfig->ePrescaler) | /* Prescaler used by LASTEDGE and POSDPER. */
                 EQDC_FILT_FILT_CS(psConfig->bFilterClockSourceselection) |
                 EQDC_FILT_FILT_CNT(psConfig->eFilterSampleCount) | EQDC_FILT_FILT_PER(psConfig->u8FilterSamplePeriod);

    /* EQDC_CTRL. */
    base->CTRL = EQDC_CTRL_W1C_FLAGS |                                /* W1C flags. */
                 (uint16_t)psConfig->eHomeEnableInitPosCounterMode |  /* HOME Enable trigger. */
                 (uint16_t)psConfig->eIndexPresetInitPosCounterMode | /* INDEX Preset trigger. */
                 EQDC_CTRL_REV(psConfig->bEnableReverseDirection) |   /* Reverse direction. */
                 EQDC_CTRL_WDE(psConfig->bEnableWatchdog) |           /* Enable watchdog. */
                 EQDC_CTRL_DMAEN(psConfig->bEnableDma);               /* Enable Dma. */

    /* Set mode of count. */
    EQDC_SetCountMode(base, psConfig->eCountMode); /* eqdcoder count mode. */

    /* EQDC_CTRL2. */
    base->CTRL2 =
        EQDC_CTRL2_ONCE(psConfig->bCountOnce) |
        EQDC_CTRL2_INITPOS(psConfig->bEnableTriggerInitPositionCounter) | /* TRIGGER initializes position counter. */
        EQDC_CTRL2_PMEN(psConfig->bEnablePeriodMeasurement) |             /* Enable period measurement. */
        EQDC_CTRL2_OUTCTL(psConfig->eOutputPulseMode) |                   /* Output pulse. */
        EQDC_CTRL2_REVMOD(psConfig->eRevolutionCountCondition) |          /* Revolution count condition. */
        EQDC_CTRL2_LDMOD(psConfig->bBufferedRegisterLoadMode) | /* Buffered register load (Update) mode select. */
        EQDC_CTRL2_UPDPOS(psConfig->bEnableTriggerClearPositionRegisters) | /* TRIGGER clears position register. */
        EQDC_CTRL2_UPDHLD(psConfig->bEnableTriggerHoldPositionRegisters);   /* TRIGGER loads position registers. */

    /* Set mode of operation. */
    EQDC_SetOperateMode(base, psConfig->eOperateMode); /* eqdcoder work mode. */

    /* Enable interrupts. */
    EQDC_EnableInterrupts(base, psConfig->u16EnabledInterruptsMask);
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
 *    psConfig->bEnableReverseDirection              = false;
 *    psConfig->bCountOnce                           = false;
 *    psConfig->eOperateMode                         = kEQDC_QuadratureDecodeOperationMode;
 *    psConfig->eCountMode                           = kEQDC_QuadratureX4;
 *    psConfig->eHomeEnableInitPosCounterMode        = kEQDC_HomeInitPosCounterDisabled;
 *    psConfig->eIndexPresetInitPosCounterMode       = kEQDC_IndexInitPosCounterDisabled;
 *    psConfig->bEnableDma                           = false;
 *    psConfig->bBufferedRegisterLoadMode            = false;
 *    psConfig->bEnableTriggerInitPositionCounter    = false;
 *    psConfig->bEnableTriggerClearPositionRegisters = false;
 *    psConfig->bEnableTriggerHoldPositionRegisters  = false;
 *    psConfig->bEnableWatchdog                      = false;
 *    psConfig->u16WatchdogTimeoutValue              = 0xFFFFU;
 *    psConfig->bFilterPhaseA                        = 0U;
 *    psConfig->bFilterPhaseB                        = 0U;
 *    psConfig->bFilterIndPre                        = 0U;
 *    psConfig->bFilterHomEna                        = 0U;
 *    psConfig->bFilterClockSourceselection          = false;
 *    psConfig->eFilterSampleCount                   = kEQDC_Filter3Samples;
 *    psConfig->u8FilterSamplePeriod                 = 0U;
 *    psConfig->eOutputPulseMode                     = kEQDC_OutputPulseOnCounterEqualCompare;
 *    psConfig->u32PositionCompareValue[0]  		 = 0xFFFFFFFFU;
 *    psConfig->u32PositionCompareValue[1]           = 0xFFFFFFFFU;
 *    psConfig->u32PositionCompareValue[2]           = 0xFFFFFFFFU;
 *    psConfig->u32PositionCompareValue[3]           = 0xFFFFFFFFU;
 *    psConfig->eRevolutionCountCondition            = kEQDC_RevolutionCountOnIndexPulse;
 *    psConfig->bEnableModuloCountMode               = false;
 *    psConfig->u32PositionModulusValue              = 0U;
 *    psConfig->u32PositionInitialValue              = 0U;
 *    psConfig->u32PositionCounterValue              = 0U;
 *    psConfig->bEnablePeriodMeasurement             = false;
 *    psConfig->ePrescaler                           = kEQDC_Prescaler1;
 *    psConfig->u16EnabledInterruptsMask             = 0U;
 *
 * param psConfig Pointer to configuration structure.
 */
void EQDC_GetDefaultConfig(eqdc_config_t *psConfig)
{
    assert(NULL != psConfig);

    psConfig->bEnableReverseDirection              = false;
    psConfig->bCountOnce                           = false;
    psConfig->eOperateMode                         = kEQDC_QuadratureDecodeOperationMode; /*!< Decode Mode. */
    psConfig->eCountMode                           = kEQDC_QuadratureX4;
    psConfig->eHomeEnableInitPosCounterMode        = kEQDC_HomeInitPosCounterDisabled;
    psConfig->eIndexPresetInitPosCounterMode       = kEQDC_IndexInitPosCounterDisabled;
    psConfig->bEnableDma                           = false;
    psConfig->bBufferedRegisterLoadMode            = false;
    psConfig->bEnableTriggerInitPositionCounter    = false;
    psConfig->bEnableTriggerClearPositionRegisters = false;
    psConfig->bEnableTriggerHoldPositionRegisters  = false;
    psConfig->bEnableWatchdog                      = false;
    psConfig->u16WatchdogTimeoutValue              = 0xFFFFU;
    psConfig->bFilterPhaseA                        = false;
    psConfig->bFilterPhaseB                        = false;
    psConfig->bFilterIndPre                        = false;
    psConfig->bFilterHomEna                        = false;
    psConfig->bFilterClockSourceselection          = false;
    psConfig->eFilterSampleCount                   = kEQDC_Filter3Samples;
    psConfig->u8FilterSamplePeriod                 = 0U;
    psConfig->eOutputPulseMode                     = kEQDC_OutputPulseOnCounterEqualCompare;
    psConfig->u32PositionCompareValue[0]           = 0xFFFFFFFFU;
    psConfig->u32PositionCompareValue[1]           = 0xFFFFFFFFU;
    psConfig->u32PositionCompareValue[2]           = 0xFFFFFFFFU;
    psConfig->u32PositionCompareValue[3]           = 0xFFFFFFFFU;
    psConfig->eRevolutionCountCondition            = kEQDC_RevolutionCountOnIndexPulse;
    psConfig->bEnableModuloCountMode               = false;
    psConfig->u32PositionModulusValue              = 0U;
    psConfig->u32PositionInitialValue              = 0U;
    psConfig->u32PositionCounterValue              = 0U;
    psConfig->bEnablePeriodMeasurement             = false;
    psConfig->ePrescaler                           = kEQDC_Prescaler1;
    psConfig->u16EnabledInterruptsMask             = 0U;
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
void EQDC_SetOperateMode(EQDC_Type *base, eqdc_operate_mode_t eOperateMode)
{
    switch (eOperateMode)
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
