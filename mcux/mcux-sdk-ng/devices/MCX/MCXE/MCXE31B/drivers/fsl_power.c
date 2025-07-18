/*
 * Copyright 2025 NXP.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_power.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/
static power_pmc_callback_t s_powerPmcCallback;

/*!
 * brief Gets the POWER PMC version id.
 *
 * This function gets the PMC version id including whether the PMC supports last
 * mile regulator.
 *
 * param versionId         Pointer to pmc_version_id_t structure.
 */
void POWER_GetPMCVersionID(pmc_version_id_t *versionId)
{
    uint8_t major    = (uint8_t)(uint32_t)(PMC->VERID >> PMC_VERID_MAJOR_SHIFT);
    uint8_t minor    = (uint8_t)(uint32_t)((PMC->VERID >> PMC_VERID_MINOR_SHIFT) & 0xFFU);
    versionId->major = major;
    versionId->minor = minor;
    if ((PMC->VERID & PMC_VERID_LMFEAT_MASK) == 0x01)
    {
        versionId->supportLastMileRegulator = true;
    }
    else
    {
        versionId->supportLastMileRegulator = false;
    }
}

/*!
 * brief Request to enter standby mode.
 */
void POWER_EnterStandbyMode(void)
{
    MC_ME->MAIN_COREID = MC_ME_MAIN_COREID_CIDX(0U) | MC_ME_MAIN_COREID_PIDX(0U);

    MC_ME->MODE_CONF = MC_ME_MODE_CONF_STANDBY_MASK;
    MC_ME->MODE_UPD  = MC_ME_MODE_UPD_MODE_UPD_MASK;

    /*! Write the first key */
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0x5AF0U);
    /*! Write the inverted key */
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0xA50FU);

    __ASM volatile("wfi");
}

/*!
 * brief Request destructive or functional reset mode transition.
 *
 * param resetType Reset type, see ref mc_me_reset_type_t.
 */
void POWER_RequestResetMode(mc_me_reset_type_t resetType)
{
    MC_ME->MODE_CONF = (uint32_t)resetType;
    MC_ME->MODE_UPD  = MC_ME_MODE_UPD_MODE_UPD_MASK;

    /*! Write the first key */
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0x5AF0U);
    /*! Write the inverted key */
    MC_ME->CTL_KEY = MC_ME_CTL_KEY_KEY(0xA50FU);

    while (0U != (MC_ME->MODE_UPD & MC_ME_MODE_UPD_MODE_UPD_MASK))
    {
    }
}

/*!
 * brief Register POWER PMC callback function.
 *
 * param cb_func   callback function
 */
void PMC_RegisterCallBack(power_pmc_callback_t cb_func)
{
    s_powerPmcCallback = cb_func;
}

void PMC_DriverIRQHandler(void);
void PMC_DriverIRQHandler(void)
{
    uint32_t pmc_interrupt_flag = 0U;
    pmc_interrupt_flag          = POWER_GetPMCInterruptFlags();
    POWER_ClearPMCInterruptFlags(pmc_interrupt_flag);
    if (s_powerPmcCallback != NULL)
    {
        s_powerPmcCallback(pmc_interrupt_flag);
    }
    SDK_ISR_EXIT_BARRIER;
}