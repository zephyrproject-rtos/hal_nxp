/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @addtogroup BOD
 * @{
 */
#include "fsl_bod.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_bod"
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * brief Initializes the BOD with configuration.
 *
 * This function configures the BOD module with the user-defined settings.
 * param base BOD peripheral base address.
 * param config pointer to configuration structure
 */
void BOD_Init(SYSCON_Type *base, const bod_config_t *config)
{
    base->ANA_EN &= ~(SYSCON_ANA_EN_BOD_EN_MASK | SYSCON_ANA_EN_BOD_AMP_EN_MASK | SYSCON_ANA_EN_BOD_THR_MASK |
                      SYSCON_ANA_EN_BOD_THR_MASK);
    base->ANA_EN |= (SYSCON_ANA_EN_BOD_THR(config->int_thr) | SYSCON_ANA_EN_BOR_THR(config->reset_thr));
}
/*!
 * brief Enable the BOD module.
 *
 * This function enable the ACMP module.
 * param base BOD peripheral base address.
 * param mode  Specified the work mode to be enabled.The mode is a logical OR of
 * the enumeration members. see ref bod_mode_t
 */
void BOD_Enable(SYSCON_Type *base, uint8_t mode)
{
    volatile uint32_t delayX;
    uint32_t enReg  = 0;
    uint32_t ampReg = 0;
    if (mode & kBOD_InterruptEnable)
    {
        ampReg |= SYSCON_ANA_EN_BOD_AMP_EN_MASK;
        enReg |= SYSCON_ANA_EN_BOD_EN_MASK;
    }
    if (mode & kBOD_ResetEnable)
    {
        ampReg |= SYSCON_ANA_EN_BOR_AMP_EN_MASK;
        enReg |= SYSCON_ANA_EN_BOR_EN_MASK;
    }
    base->ANA_EN |= ampReg;
    /*100us delay for BOD_AMP stable*/
    for (delayX = 0; delayX < 800; delayX++)
    {
    }
    base->ANA_EN |= enReg;
}

/*!
 * brief Disable the BOD module.
 *
 * This function enable the BOD module.
 * param base BOD peripheral base address.
 * param mode  Specified the work mode to be disabled.The mode is a logical OR of
 * the enumeration members. see ref bod_mode_t
 */
void BOD_Disable(SYSCON_Type *base, uint8_t mode)
{
    uint32_t enReg = 0;
    if (mode & kBOD_InterruptEnable)
    {
        enReg |= SYSCON_ANA_EN_BOD_EN_MASK;
    }
    if (mode & kBOD_ResetEnable)
    {
        enReg |= SYSCON_ANA_EN_BOR_EN_MASK;
    }
    base->ANA_EN &= ~enReg;
}

/*!
 * brief Disable the BOD module
 *
 * This function disable the BOD module.
 * param base BOD peripheral base address.
 */
void BOD_Deinit(SYSCON_Type *base)
{
    base->ANA_EN &= ~(SYSCON_ANA_EN_BOD_EN_MASK | SYSCON_ANA_EN_BOR_EN_MASK);
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the BOD configuration structure to a default value. The default
 * values are:
 *   config->int_thr = kBOD_InterruptThreshold2;
 *   config->reset_thr = kBOD_ResetThreshold2;
 * param config Pointer to configuration structure.
 */
void BOD_GetDefaultConfig(bod_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->int_thr   = kBOD_InterruptThreshold2;
    config->reset_thr = kBOD_ResetThreshold2;
}
