/*
 * Copyright 2020-2021, 2023 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_qdc.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_qdc"
#endif

/* Code to detect interrupt flag definition overlap. */
#ifndef QDC_CTRL3_INT_EN
#define QDC_CTRL3_INT_EN 0U
#endif

#ifndef QDC_CTRL3_INT_FLAGS
#define QDC_CTRL3_INT_FLAGS 0U
#endif

#if (QDC_CTRL_INT_EN & QDC_CTRL2_INT_EN & QDC_CTRL3_INT_EN)
#error Interrupt enable bit overlap
#endif

#if (QDC_CTRL_INT_FLAGS & QDC_CTRL2_INT_FLAGS & QDC_CTRL3_INT_FLAGS)
#error Interrupt flag bit overlap
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for QDC module.
 *
 * @param base QDC peripheral base address
 */
static uint32_t QDC_GetInstance(QDC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to QDC bases for each instance. */
static QDC_Type *const s_qdcBases[] = QDC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to QDC clocks for each instance. */
static const clock_ip_name_t s_qdcClocks[] = QDC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t QDC_GetInstance(QDC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_qdcBases); instance++)
    {
        if (s_qdcBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_qdcBases));

    return instance;
}

/*
 * Initializes the QDC module.
 *
 * This function initializes the QDC by:
 * 1. Enable the IP bus clock (optional).
 * 2. Configure module based on the configuration structure.
 *
 * param base   QDC peripheral base address.
 * param psConfig Pointer to configuration structure.
 */
void QDC_Init(QDC_Type *base, const qdc_config_t *psConfig)
{
    assert(NULL != psConfig);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_qdcClocks[QDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* Compare value. */
    QDC_SetPositionCompareValue(base, psConfig->u32PositionCompareValue);
#if (defined(FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER) && FSL_FEATURE_QDC_HAS_LCOMP1_REGISTER)
    QDC_SetPositionCompare1Value(base, psConfig->u32PositionCompare1Value);
#endif /* FSL_FEATURE_QDC_HAS_UCOMP1_REGISTER */
    /* Counter value. */
    QDC_SetPositionCounterValue(base, psConfig->u32PositionCounterValue);

    /* Initial value. */
    QDC_SetInitialPositionValue(base, psConfig->u32PositionInitialValue);

    /* Modulus value. */
    QDC_SetPositionModulusValue(base, psConfig->u32PositionModulusValue);

    /* QDC_CTRL. */
    base->CTRL = QDC_CTRL_W1C_FLAGS |                              /* W1C flags. */
                 (uint16_t)psConfig->eHomeInitPosCounterMode |     /* HOME trigger. */
                 (uint16_t)psConfig->eIndexInitPosCounterMode |    /* INDEX trigger. */
                 QDC_CTRL_REV(psConfig->bEnableReverseDirection) | /* Reverse direction. */
                 QDC_CTRL_PH1(psConfig->eDecoderWorkMode) |        /* qdcoder work mode. */
                 QDC_CTRL_WDE(psConfig->bEnableWatchdog);          /* Enable watchdog. */

    /* Watchdog. */
    QDC_SetWatchdogTimeout(base, psConfig->u16WatchdogTimeoutValue);

    /* QDC_FILT. */
    base->FILT = QDC_FILT_FILT_CNT(psConfig->eFilterSampleCount) |
#if (defined(FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD) && FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD)
                 QDC_FILT_FILT_PRSC(psConfig->eFilterPrescaler) |
#endif /* FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD */
                 QDC_FILT_FILT_PER(psConfig->u8FilterSamplePeriod);
    /* QDC_CTRL2. */
    base->CTRL2 =
        QDC_CTRL2_W1C_FLAGS | /* W1C flags. */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_INITPOS_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_INITPOS_BIT_FIELD)
        QDC_CTRL2_INITPOS(psConfig->bEnableTriggerInitPositionCounter) | /* TRIGGER initializes position counter. */
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_INITPOS_BIT_FIELD */
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD)
        QDC_CTRL2_EMIP(psConfig->bEnableIndexInitPositionCounter) | /* INDEX initializes position counter. */
#endif                                                              /* FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD */
        QDC_CTRL2_OUTCTL(psConfig->eOutputPulseMode) |              /* Output Pulse. */
        QDC_CTRL2_REVMOD(psConfig->eRevolutionCountCondition) |     /* Revolution Count Condition. */
        QDC_CTRL2_MOD(psConfig->bEnableModuloCountMode) |           /* Enable Modulo Count Mode. */
        QDC_CTRL2_UPDPOS(psConfig->bEnableTriggerClearPositionRegisters) | /* TRIGGER clears position register. */
        QDC_CTRL2_UPDHLD(psConfig->bEnableTriggerHoldPositionRegisters);   /* TRIGGER loads position registers. */
#if (defined(FSL_FEATURE_QDC_HAS_CTRL3_REGISTER) && FSL_FEATURE_QDC_HAS_CTRL3_REGISTER)
    /* QDC_CTRL3. */
    base->CTRL3 = QDC_CTRL3_W1C_FLAGS |                                /* W1C flags. */
                  QDC_CTRL3_PMEN(psConfig->bEnablePeriodMeasurement) | /* Enable period measurement. */
                  QDC_CTRL3_PRSC(psConfig->ePrescaler);                /* Prescaler used by LASTEDGE and POSDPER. */
#endif                                                                 /* FSL_FEATURE_QDC_HAS_CTRL3_REGISTER */

    /* Enable interrupts. */
    QDC_EnableInterrupts(base, psConfig->u16EnabledInterruptsMask);
}

/*
 * De-initializes the QDC module.
 *
 * This function deinitializes the QDC by:
 * 1. Disables the IP bus clock (optional).
 *
 * param base QDC peripheral base address.
 */
void QDC_Deinit(QDC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_qdcClocks[QDC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * Gets an available pre-defined configuration.
 *
 * The default value are:
    psConfig->bEnableReverseDirection              = false;
    psConfig->eDecoderWorkMode                     = kQDC_DecoderQuadratureMode;
    psConfig->eHomeInitPosCounterMode              = kQDC_HomeInitPosCounterDisabled;
    psConfig->eIndexInitPosCounterMode             = kQDC_IndexInitPosCounterDisabled;
    psConfig->bEnableTriggerInitPositionCounter    = false;
    psConfig->bEnableTriggerClearPositionRegisters = false;
    psConfig->bEnableTriggerHoldPositionRegisters  = false;
    psConfig->bEnableWatchdog                      = false;
    psConfig->u16WatchdogTimeoutValue              = 0xFFFFU;
    psConfig->eFilterSampleCount                   = kQDC_Filter3Samples;
    psConfig->u8FilterSamplePeriod                 = 0U;
    psConfig->eOutputPulseMode                     = kQDC_OutputPulseOnCounterEqualCompare;
    psConfig->u32PositionCompareValue              = 0xFFFFFFFFU;
    psConfig->u32PositionCompare1Value             = 0xFFFFFFFFU;
    psConfig->eRevolutionCountCondition            = kQDC_RevolutionCountOnIndexPulse;
    psConfig->bEnableModuloCountMode               = false;
    psConfig->u32PositionModulusValue              = 0U;
    psConfig->u32PositionInitialValue              = 0U;
    psConfig->u32PositionCounterValue              = 0U;
    psConfig->bEnablePeriodMeasurement             = false;
    psConfig->ePrescaler                           = kQDC_Prescaler1;
    psConfig->u16EnabledInterruptsMask             = 0U;
 *
 */
void QDC_GetDefaultConfig(qdc_config_t *psConfig)
{
    assert(NULL != psConfig);

    psConfig->bEnableReverseDirection              = false;
    psConfig->eDecoderWorkMode                     = kQDC_DecoderQuadratureMode;
    psConfig->eHomeInitPosCounterMode              = kQDC_HomeInitPosCounterDisabled;
    psConfig->eIndexInitPosCounterMode             = kQDC_IndexInitPosCounterDisabled;
    psConfig->bEnableTriggerInitPositionCounter    = false;
    psConfig->bEnableTriggerClearPositionRegisters = false;
    psConfig->bEnableTriggerHoldPositionRegisters  = false;
#if (defined(FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD) && FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD)
    psConfig->bEnableIndexInitPositionCounter = false;
#endif /* FSL_FEATURE_QDC_CTRL2_HAS_EMIP_BIT_FIELD */
    psConfig->bEnableWatchdog         = false;
    psConfig->u16WatchdogTimeoutValue = 0xFFFFU;
    psConfig->eFilterSampleCount      = kQDC_Filter3Samples;
#if (defined(FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD) && FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD)
    psConfig->eFilterPrescaler = kQDC_FilterPrescaler1;
#endif /* FSL_FEATURE_QDC_FILT_HAS_FILT_PRSC_BIT_FIELD */
    psConfig->u8FilterSamplePeriod      = 0U;
    psConfig->eOutputPulseMode          = kQDC_OutputPulseOnCounterEqualCompare;
    psConfig->u32PositionCompareValue   = 0xFFFFFFFFU;
    psConfig->u32PositionCompare1Value  = 0xFFFFFFFFU;
    psConfig->eRevolutionCountCondition = kQDC_RevolutionCountOnIndexPulse;
    psConfig->bEnableModuloCountMode    = false;
    psConfig->u32PositionModulusValue   = 0U;
    psConfig->u32PositionInitialValue   = 0U;
    psConfig->u32PositionCounterValue   = 0U;
    psConfig->bEnablePeriodMeasurement  = false;
    psConfig->ePrescaler                = kQDC_Prescaler1;
    psConfig->u16EnabledInterruptsMask  = 0U;
}
