/*
 * Copyright 2020 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_cmp.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dsc_cmp"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Get instance number for CMP module.
 *
 * @param base CMP peripheral base address
 */
static uint32_t CMP_GetInstance(CMP_Type *base);
/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to CMP bases for each instance. */
static CMP_Type *const s_cmpBases[] = CMP_BASE_PTRS;
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to CMP clocks for each instance. */
static const clock_ip_name_t s_cmpClocks[] = CMP_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
/*******************************************************************************
 * Codes
 ******************************************************************************/
static uint32_t CMP_GetInstance(CMP_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_cmpBases); instance++)
    {
        if (s_cmpBases[instance] == base)
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_cmpBases));

    return instance;
}

/*!
 * brief Initializes the CMP user configuration structure.
 *
 * This function initializes the user configuration structure to the default values.
 * It is corresponding to the continuous mode configurations.
 *
 * param psConfig pointer of cmp_config_t.
 */
void CMP_GetDefaultConfig(cmp_config_t *psConfig)
{
    assert(NULL != psConfig);

    /* Initializes the configure structure to zero. */
    (void)memset(psConfig, 0, sizeof(cmp_config_t));

    psConfig->eHysteresisLevel      = kCMP_HysteresisLevel0;
    psConfig->eComparasionSpeedMode = kCMP_ComparsionModeHighSpeed;

    psConfig->eWorkMode = kCMP_WorkModeWindowBypassAndNoExternalSample;

    /* DAC source from VIN1, output voltage is VIN1/256, DAC is disabled by default */
    psConfig->sDacConfig.eDACVrefSource            = kCMP_DACVrefSourceVin1;
    psConfig->sDacConfig.u8DACOutputVoltageDivider = 0;
    psConfig->sDacConfig.bEnableInternalDAC        = false;

    psConfig->bInvertComparatorOutputPolarity = false;

    psConfig->eFilterCount   = kCMP_FilterCountDisable;
    psConfig->u8FilterPeriod = 0U;

    psConfig->eOutputSource                         = kCMP_OutputSourceFromFilterCOUT;
    psConfig->bEnableOutputPin                      = true;
    psConfig->uDmaInterruptConfig.eInterruptRequest = kCMP_InterruptRequestDisabled;

    psConfig->bCMPEnable = false;
}

/*!
 * brief Initializes the CMP.
 *
 * This function initializes the CMP module. The operations included are as follows.
 * - Enabling the clock for CMP module.
 * - Configuring the comparator.
 *
 * param base   CMP peripheral base address.
 * param psConfig Pointer to the configuration structure.
 *
 */
void CMP_Init(CMP_Type *base, const cmp_config_t *psConfig)
{
    assert(psConfig != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_cmpClocks[CMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    /* configure the inputmux. */
    CMP_SetInputChannel(base, psConfig->ePlusInput, psConfig->eMinusInput);
    /* configure the internal DAC */
    CMP_SetDACConfig(base, &psConfig->sDacConfig);
    /* configure the invert polarity */
    CMP_EnableInvertOutput(base, psConfig->bInvertComparatorOutputPolarity);
    /* set comparator speed mode */
    CMP_SetComparasionSpeedMode(base, psConfig->eComparasionSpeedMode);
    /* set hysteresis level */
    CMP_SetHysteresisLevel(base, psConfig->eHysteresisLevel);

    if (psConfig->eWorkMode == kCMP_WorkModeWindowEnabledAndNoExternalSample)
    {
        CMP_EnableExternalSampleMode(base, false);
        /* config window */
#if  (defined (FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD) && FSL_FEATURE_CMP_HAS_COWZ_BIT_FIELD)
        CMP_SetWindowOutputMode(base, psConfig->eWindowOutputMode);
#endif
        CMP_EnableWindow(base, true);
        /* filter sample count and sample period */
        CMP_SetInternalFilterCount(base, psConfig->eFilterCount);
        CMP_SetInternalFilterPeriod(base, psConfig->u8FilterPeriod);
    }
    else if (psConfig->eWorkMode == kCMP_WorkModeWindowBypassAndExternalSample)
    {
        CMP_EnableWindow(base, false);
        CMP_EnableExternalSampleMode(base, true);
        CMP_SetExternalSampleCount(base, psConfig->eExternalSampleCount);
    }
    else
    {
        CMP_EnableWindow(base, false);
        CMP_EnableExternalSampleMode(base, false);
        CMP_SetInternalFilterCount(base, psConfig->eFilterCount);
        CMP_SetInternalFilterPeriod(base, psConfig->u8FilterPeriod);
    }

    /* configure the output */
    CMP_SelectOutputSource(base, psConfig->eOutputSource);
    CMP_EnableOuputPin(base, psConfig->bEnableOutputPin);
    /* enable the interrupt, since DMA request and interrupt request is in a union, so
     * DMA request can also be enabled with calling below function
     */
    CMP_EnableInterrupt(base, psConfig->uDmaInterruptConfig.eInterruptRequest);

    CMP_Enable(base, psConfig->bCMPEnable);
}

/*!
 * brief De-initializes the CMP module.
 *
 * This function de-initializes the CMP module. The operations included are as follows.
 * - Disabling the CMP module.
 * - Disabling the clock for CMP module.
 *
 * param base CMP peripheral base address.
 */
void CMP_Deinit(CMP_Type *base)
{
    /* Disable the CMP module. */
    CMP_Enable(base, false);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_cmpClocks[CMP_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Configures the internal DAC.
 *
 * param base   CMP peripheral base address.
 * param psConfig Pointer to the configuration structure.
 */
void CMP_SetDACConfig(CMP_Type *base, const cmp_dac_config_t *psConfig)
{
    assert(psConfig != NULL);

    CMP_SetDACOutputVoltage(base, psConfig->u8DACOutputVoltageDivider);
    CMP_SetDACReferenceVoltageSource(base, psConfig->eDACVrefSource);
    CMP_EnableInternalDAC(base, psConfig->bEnableInternalDAC);
}
