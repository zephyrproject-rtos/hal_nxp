/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_powercon.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.powercon"
#endif

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * brief Enable wakeup for the specified IRQ sources (RMW-clear in IRQ_WAKEUP_MASK).
 *
 * Register polarity: 0 = wakeup enabled, 1 = masked.
 * For each word i, bits set in idMasks[i] are cleared in IRQ_WAKEUP_MASK[i].
 *
 * param base    POWERCON_CMC_CTRL peripheral base address.
 * param idMasks Pointer to 12 words where each bit identifies an IRQ to enable for wakeup.
 */
void POWERCON_EnableWakeupIRQ(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks)
{
    assert(base != NULL);
    assert(idMasks != NULL);

    for (uint8_t i = 0U; i < 12U; i++)
    {
        base->IRQ_WAKEUP_MASK[i] &= ~idMasks[i]; /* 0b = wakeup enabled */
    }
}

/*!
 * brief Disable wakeup for the specified IRQ sources (RMW-set in IRQ_WAKEUP_MASK).
 *
 * For each word i, bits set in idMasks[i] are set in IRQ_WAKEUP_MASK[i].
 *
 * param base    POWERCON_CMC_CTRL peripheral base address.
 * param idMasks Pointer to 12 words where each bit identifies an IRQ to mask from wakeup.
 */
void POWERCON_DisableWakeupIRQ(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks)
{
    assert(base != NULL);
    assert(idMasks != NULL);

    for (uint8_t i = 0U; i < 12U; i++)
    {
        base->IRQ_WAKEUP_MASK[i] |= idMasks[i]; /* 1b = wakeup masked */
    }
}

/*!
 * brief Enable wakeup for the specified DMA sources (RMW-clear in DMA_WAKEUP_MASK).
 *
 * Register polarity: 0 = wakeup enabled, 1 = masked.
 * For each word i, bits set in idMasks[i] are cleared in DMA_WAKEUP_MASK[i].
 *
 * param base    POWERCON_CMC_CTRL peripheral base address.
 * param idMasks Pointer to 2 words where each bit identifies a DMA channel to enable for wakeup.
 */
void POWERCON_EnableWakeupDMA(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks)
{
    assert(base != NULL);
    assert(idMasks != NULL);

    base->DMA_WAKEUP_MASK[0] &= ~idMasks[0];
    base->DMA_WAKEUP_MASK[1] &= ~idMasks[1];
}

/*!
 * brief Disable wakeup for the specified DMA sources (RMW-set in DMA_WAKEUP_MASK).
 *
 * For each word i, bits set in idMasks[i] are set in DMA_WAKEUP_MASK[i].
 *
 * param base    POWERCON_CMC_CTRL peripheral base address.
 * param idMasks Pointer to 2 words where each bit identifies a DMA channel to mask from wakeup.
 */
void POWERCON_DisableWakeupDMA(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks)
{
    assert(base != NULL);
    assert(idMasks != NULL);

    base->DMA_WAKEUP_MASK[0] |= idMasks[0];
    base->DMA_WAKEUP_MASK[1] |= idMasks[1];
}

/*!
 * brief Write the full SOC standby configuration before WFI.
 *
 * Configures the hardware handshake partners and target states that POWERCON
 * applies autonomously during the CMC/SSC sleep sequence.
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 *
 * param base   POWERCON_SOC_CTRL peripheral base address.
 * param config Pointer to the standby configuration struct.
 */
/*!
 * brief Write the init-time SoC topology configuration.
 *
 * Writes RCGCFG_HSK_SEL, CSRCCFG_HSK_SEL, and CSRCCFG_HSK_SEL1.
 *
 * param base   POWERCON_SOC_CTRL peripheral base address.
 * param config Pointer to the topology configuration struct.
 */
void POWERCON_SetTopologyConfig(POWERCON_SOC_CTRL_Type *base, const powercon_topology_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    base->RCGCFG_HSK_SEL   = config->rcgcfgHskSel;
    base->CSRCCFG_HSK_SEL  = config->csrccfgHskSel;
    base->CSRCCFG_HSK_SEL1 = config->csrccfgHskSel1;
}

/*!
 * brief Write the per-mode SOC standby configuration before WFI.
 *
 * Writes RCGCFG_STBY, CSRCCFG_STBY, PMUCFG_STBY, and PMICCFG_STBY.
 * HSK_SEL registers are not touched here — use POWERCON_SetTopologyConfig().
 *
 * param base   POWERCON_SOC_CTRL peripheral base address.
 * param config Pointer to the standby configuration struct.
 */
void POWERCON_SetSocStandbyConfig(POWERCON_SOC_CTRL_Type *base,
                                  const powercon_soc_standby_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    base->RCGCFG_STBY  = config->rcgcfgStby;
    base->CSRCCFG_STBY = config->csrccfgStby;
    base->PMUCFG_STBY  = config->pmucfgStby;
    base->PMICCFG_STBY = POWERCON_SOC_CTRL_PMICCFG_STBY_PMIC_MODE(config->pmiccfgStby);
}
