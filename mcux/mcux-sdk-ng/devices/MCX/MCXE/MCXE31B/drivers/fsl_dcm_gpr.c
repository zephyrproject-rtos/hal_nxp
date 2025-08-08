/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dcm_gpr.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dcm_gpr"
#endif

/*!
 * brief Configure the standby exit.
 *
 * param config The configuration of standby exit. ref standby_exit_config_t.
 */
void DCM_GPR_StandbyExitConfig(const standby_exit_config_t *config)
{
#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT != 0U)
    if (config->bypassSircTriming)
    {
        DCM_GPR->DCMRWF2 |= DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK;
    }
    else
    {
        DCM_GPR->DCMRWF2 &= ~DCM_GPR_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT_MASK;
    }
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_SIRC_TRIM_BYP_STDBY_EXT */

#if defined(FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT) && (FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT != 0U)
    if (config->bypassPmcTrimingAndRgmDcfLoading)
    {
        DCM_GPR->DCMRWF2 |= DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_MASK;
    }
    else
    {
        DCM_GPR->DCMRWF2 &= ~DCM_GPR_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT_MASK;
    }
#endif /* FSL_FEATURE_DCM_GPR_HAS_DCMRWF2_PMC_TRIM_RGM_DCF__BYP_STDBY_EXT */

    if (config->bypassFircTriming)
    {
        DCM_GPR->DCMRWF2 |= DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK;
    }
    else
    {
        DCM_GPR->DCMRWF2 &= ~DCM_GPR_DCMRWF2_FIRC_TRIM_BYP_STDBY_EXT_MASK;
    }

    if (config->enableFastStandbyExit)
    {
        DCM_GPR->DCMRWF5 = (uint32_t)((uintptr_t)config->fastStandbyExitBootAddress);
        DCM_GPR->DCMRWF5 |= DCM_GPR_DCMRWF5_BOOT_MODE_MASK;
    }
    else
    {
        DCM_GPR->DCMRWF5 &= ~DCM_GPR_DCMRWF5_BOOT_MODE_MASK;
    }
}
