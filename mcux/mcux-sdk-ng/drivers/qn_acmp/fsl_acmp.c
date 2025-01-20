/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @addtogroup ACMP
 * @{
 */
#include "fsl_acmp.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_acmp"
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
 * brief Initializes the ACMP with configuration.
 *
 * This function configures the ACMP module with the user-defined settings.
 * param base ACMP peripheral base address.
 * param config pointer to configuration structure
 */
void ACMP_Init(SYSCON_Type *base, const acmp_config_t *config)
{
    uint32_t mask = 0;
    uint32_t reg  = 0;

    if (config->ch == kACMP_Channel0)
    {
        mask = SYSCON_ANA_EN_ACMP_VREF_SEL_MASK | SYSCON_ANA_EN_ACMP0_REF_MASK | SYSCON_ANA_EN_ACMP0_EDGE_SEL_MASK |
               SYSCON_ANA_EN_ACMP0_HYST_EN_MASK;
        if (config->refSrc != kACMP_ReferenceSourceExternalReferenceVoltage)
        {
            reg |= SYSCON_ANA_EN_ACMP_VREF_SEL(config->refSrc) | SYSCON_ANA_EN_ACMP0_REF(config->refDiv);
        }
        reg |= SYSCON_ANA_EN_ACMP0_EDGE_SEL(config->trigerEdge) | SYSCON_ANA_EN_ACMP0_HYST_EN(config->hystEn);
        base->ANA_EN &= ~mask;
        base->ANA_EN |= reg;
    }
    else
    {
        mask = SYSCON_ANA_EN_ACMP_VREF_SEL_MASK | SYSCON_ANA_EN_ACMP1_REF_MASK | SYSCON_ANA_EN_ACMP1_EDGE_SEL_MASK |
               SYSCON_ANA_EN_ACMP1_HYST_EN_MASK;
        if (config->refSrc != kACMP_ReferenceSourceExternalReferenceVoltage)
        {
            reg |= SYSCON_ANA_EN_ACMP_VREF_SEL(config->refSrc) | SYSCON_ANA_EN_ACMP1_REF(config->refDiv);
        }
        reg |= SYSCON_ANA_EN_ACMP1_EDGE_SEL(config->trigerEdge) | SYSCON_ANA_EN_ACMP1_HYST_EN(config->hystEn);
        base->ANA_EN &= ~mask;
        base->ANA_EN |= reg;
    }
}

/*!
 * brief Enable the ACMP module.
 *
 * This function enable the ACMP module.
 * param base ACMP peripheral base address.
 * param ch  Specified the channel to be enabled
 */
void ACMP_Enable(SYSCON_Type *base, acmp_channel_t ch)
{
    if (ch == kACMP_Channel0)
    {
        base->ANA_EN |= SYSCON_ANA_EN_ACMP0_EN_MASK;
    }
    else
    {
        base->ANA_EN |= SYSCON_ANA_EN_ACMP1_EN_MASK;
    }
}

/*!
 * brief Disable the ACMP module.
 *
 * This function disable the ACMP module.
 * param base ACMP peripheral base address.
 * param ch  Specified the channel to be disabled
 */
void ACMP_Disable(SYSCON_Type *base, acmp_channel_t ch)
{
    if (ch == kACMP_Channel0)
    {
        base->ANA_EN &= ~SYSCON_ANA_EN_ACMP0_EN_MASK;
    }
    else
    {
        base->ANA_EN &= ~SYSCON_ANA_EN_ACMP1_EN_MASK;
    }
}

/*!
 * brief Enables the ACMP interrupt.
 *
 * This function enables the ACMP interrupt.
 *
 * param base ACMP peripheral base address.
 * param ch  Specified the channel.
 */
void ACMP_EnableInterrupts(SYSCON_Type *base, acmp_channel_t ch)
{
    if (ch == kACMP_Channel0)
    {
        base->ANA_EN |= SYSCON_ANA_EN_ACMP0_INTEN_MASK;
    }
    else
    {
        base->ANA_EN |= SYSCON_ANA_EN_ACMP1_INTEN_MASK;
    }
}

/*!
 * brief Disables the ACMP interrupt.
 *
 * This function disables the ACMP interrupt.
 *
 * param base ACMP peripheral base address.
 * param ch  Specified the channel
 */
void ACMP_DisableInterrupts(SYSCON_Type *base, acmp_channel_t ch)
{
    if (ch == kACMP_Channel0)
    {
        base->ANA_EN &= ~SYSCON_ANA_EN_ACMP0_INTEN_MASK;
    }
    else
    {
        base->ANA_EN &= ~SYSCON_ANA_EN_ACMP1_INTEN_MASK;
    }
}

/*!
 * brief Get the ACMP value
 *
 * This function get ACMP output value.
 *
 * param base ACMP peripheral base address.
 * param ch  Specified the channel
 * return acmp value
 */
uint8_t ACMP_GetValue(SYSCON_Type *base, acmp_channel_t ch)
{
    if (ch == kACMP_Channel0)
    {
        return (base->ANA_EN & SYSCON_ANA_EN_ACMP0_OUT_MASK) >> SYSCON_ANA_EN_ACMP0_OUT_SHIFT;
    }
    else
    {
        return (base->ANA_EN & SYSCON_ANA_EN_ACMP1_OUT_MASK) >> SYSCON_ANA_EN_ACMP1_OUT_SHIFT;
    }
}

/*!
 * brief Gets the default configuration structure.
 *
 * This function initializes the ACMP configuration structure to a default value. The default
 * values are:
 *   config->ch = kACMP_Channel0;
 *   config->refSrc = kACMP_ReferenceSourceExternalReferenceVoltage;
 *   config->hystEn = kACMP_HysteresisDisable;
 *   config->trigerEdge = kACMP_TrigerRising;
 *   config->refDiv = kACMP_ReferenceVoltageDivider1;
 * param config Pointer to configuration structure.
 */
void ACMP_GetDefaultConfig(acmp_config_t *config)
{
    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    config->ch         = kACMP_Channel0;
    config->refSrc     = kACMP_ReferenceSourceExternalReferenceVoltage;
    config->hystEn     = kACMP_HysteresisDisable;
    config->trigerEdge = kACMP_TrigerRising;
    config->refDiv     = kACMP_ReferenceVoltageDivider1;
}
