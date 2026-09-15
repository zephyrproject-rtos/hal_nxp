/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_resetcon.h"
#include "PERI_RESETCON.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.resetcon"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief Mask of every PD_RSTCTRL bit this driver may write (excluding MAGIC). */
#define RESETCON_PD_RSTCTRL_DOMAIN_MASK \
    (RESETCON_PD_RSTCTRL_PD_NPU_MASK | RESETCON_PD_RSTCTRL_PD_MEDIA_MASK | RESETCON_PD_RSTCTRL_PD_COMM_MASK)

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Configure RESETCON access control.
 *
 * @param base    RESETCON peripheral base.
 * @param config  Pointer to access-control configuration.
 */
void RESETCON_SetAccessControl(RESETCON_Type *base, const resetcon_access_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    base->ACCCTRL = RESETCON_ACCCTRL_DID(config->domainMask) |
                    RESETCON_ACCCTRL_UM(config->userMode ? 1U : 0U) |
                    RESETCON_ACCCTRL_NSM(config->nonSecure ? 1U : 0U) |
                    RESETCON_ACCCTRL_LOCK(config->lock ? 1U : 0U);
}

/*!
 * @brief Trigger a software-controlled power-domain reset.
 *
 * @param base   RESETCON peripheral base.
 * @param mask   OR'ed mask of ::_resetcon_pd_reset_ctrl.
 */
void RESETCON_TriggerPowerDomainReset(RESETCON_Type *base, uint32_t mask)
{
    assert(base != NULL);

    base->PD_RSTCTRL = RESETCON_PD_RSTCTRL_MAGIC(RESETCON_PD_RSTCTRL_MAGIC_VALUE) |
                       (mask & RESETCON_PD_RSTCTRL_DOMAIN_MASK);
}

/*!
 * @brief Set the maximum number of consecutive warm-reset sequences.
 *
 * @param base   RESETCON peripheral base.
 * @param value  12-bit timeout value.
 */
void RESETCON_SetResetTimeout(RESETCON_Type *base, uint16_t value)
{
    base->RTO = RESETCON_RTO_RTIMEOUT(value);
}

/*!
 * @brief Configure the RESET_b pin digital filter.
 *
 * @param base   RESETCON peripheral base.
 * @param value  16-bit cycle count; 0 disables the filter.
 */
void RESETCON_SetResetPinFilter(RESETCON_Type *base, uint16_t value)
{
    base->FILTER = RESETCON_FILTER_FTIME(value);
}

/*!
 * @brief Configure the POR_b pin digital filter.
 *
 * @param base   RESETCON peripheral base.
 * @param value  16-bit cycle count; 0 disables the filter.
 */
void RESETCON_SetPorPinFilter(RESETCON_Type *base, uint16_t value)
{
    base->PORPC = (base->PORPC & ~RESETCON_PORPC_PFT_MASK) | RESETCON_PORPC_PFT(value);
}

/*!
 * @brief Enable or disable POR_b pin triggering a PMU restart.
 *
 * @param base    RESETCON peripheral base.
 * @param enable  true: enable; false: disable.
 */
void RESETCON_EnablePorTriggerPmuRestart(RESETCON_Type *base, bool enable)
{
    if (enable)
    {
        base->PORPC |= RESETCON_PORPC_TPC_MASK;
    }
    else
    {
        base->PORPC &= ~RESETCON_PORPC_TPC_MASK;
    }
}

/*!
 * @brief Override the boot mode for the next warm-reset sequence.
 *
 * @param base    RESETCON peripheral base.
 * @param mode    Boot mode to force.
 * @param enable  true: enable override; false: disable override.
 */
void RESETCON_SetBootModeOverride(RESETCON_Type *base, resetcon_boot_mode_t mode, bool enable)
{
    base->MODECTRL = RESETCON_MODECTRL_MC((uint32_t)mode) | RESETCON_MODECTRL_ME(enable ? 1U : 0U);
}

/*!
 * @brief Configure the trigger mode for the JTAGC quick-response warm reset path.
 *
 * Read-modify-write on MISCCTRL.QRSP_EN; ACGOV and other bits are preserved.
 *
 * @param base  RESETCON peripheral base.
 * @param mode  Trigger mode applied to the quick-response source.
 */
void RESETCON_SetQuickResponseTriggerMode(RESETCON_Type *base, resetcon_trigger_mode_t mode)
{
    if (mode == kRESETCON_TriggerEdge)
    {
        base->MISCCTRL |= RESETCON_MISCCTRL_QRSP_EN_MASK;
    }
    else
    {
        base->MISCCTRL &= ~RESETCON_MISCCTRL_QRSP_EN_MASK;
    }
}

/*!
 * @brief Override automatic clock gating.
 *
 * @param base    RESETCON peripheral base.
 * @param enable  true: free-running clock; false: use auto clock gating.
 */
void RESETCON_OverrideAutoClockGating(RESETCON_Type *base, bool enable)
{
    if (enable)
    {
        base->MISCCTRL |= RESETCON_MISCCTRL_ACGOV_MASK;
    }
    else
    {
        base->MISCCTRL &= ~RESETCON_MISCCTRL_ACGOV_MASK;
    }
}
