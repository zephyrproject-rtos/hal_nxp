/*
 * Copyright 2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_pmc.h"

/*!
 * brief Configures the low-voltage detect setting.
 *
 * This function configures the low-voltage detect setting, including the trip
 * point voltage setting, enables or disables the interrupt, enables or disables the system reset.
 *
 * param base PMC peripheral base address.
 * param config  Low-voltage detect configuration structure.
 */
void PMC_ConfigureLowVoltDetect(PMC_Type *base, const pmc_low_volt_detect_config_t *config)
{
    uint32_t spmsc1 = base->SPMSC1;

    /* low voltage detect configuration */
    spmsc1 &= ~(PMC_SPMSC1_LVDSE_MASK | PMC_SPMSC1_LVDRE_MASK);
    spmsc1 |= ((uint32_t)config->enableStop << PMC_SPMSC1_LVDSE_SHIFT) |
              ((uint32_t)config->enableReset << PMC_SPMSC1_LVDRE_SHIFT);
    base->SPMSC1 = spmsc1;

    /* select detect voltage */
    base->SPMSC2 |= (base->SPMSC2 & (~PMC_SPMSC2_LVDV_MASK)) | ((uint32_t)config->voltSelect << PMC_SPMSC2_LVDV_SHIFT);
}

/*!
 * brief Configures the low-voltage warning setting.
 *
 * This function configures the low-voltage warning setting, including the trip
 * point voltage setting and enabling or disabling the interrupt.
 *
 * param base PMC peripheral base address.
 * param config  Low-voltage warning configuration structure.
 */
void PMC_ConfigureLowVoltWarning(PMC_Type *base, const pmc_low_volt_warning_config_t *config)
{
    base->SPMSC1 |= (base->SPMSC1 & (~PMC_SPMSC1_LVWIE_MASK)) |
                    ((uint32_t)config->enableInt << PMC_SPMSC1_LVWIE_SHIFT) | PMC_SPMSC1_LVWACK_MASK;

    /* select detect voltage */
    base->SPMSC2 |= (base->SPMSC2 & (~PMC_SPMSC2_LVWV_MASK)) | ((uint32_t)config->voltSelect << PMC_SPMSC2_LVWV_SHIFT);
}
