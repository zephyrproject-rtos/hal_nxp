/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_memcon.h"
#include "PERI_MEMCON_GLOBAL.h"
#include "PERI_MEMCON_SLICE.h"

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.memcon"
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
 * @brief Compute the bit position of a block's 2-bit power-mode field within its register.
 *
 * Block n occupies bits [(n%8)*4 + 1 : (n%8)*4] of the relevant *_CFG0/1 register.
 *
 * @param blockIdx  Block index 0..MEMCON_BLOCK_COUNT_PER_SLICE-1.
 * @return  Bit position (0..28) of the block's field within the register.
 */
static inline uint32_t MEMCON_GetBlockBitPos(uint8_t blockIdx)
{
    return (uint32_t)(blockIdx % MEMCON_BLOCKS_IN_CFG0) * MEMCON_BLOCK_FIELD_STRIDE;
}

/*!
 * @brief Configure GLOBAL access control.
 *
 * @param base    MEMCON_GLOBAL peripheral base.
 * @param config  Pointer to access-control configuration.
 */
void MEMCON_GLOBAL_SetAccessControl(MEMCON_GLOBAL_Type *base, const memcon_access_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);

    base->ACCCTRL = MEMCON_GLOBAL_ACCCTRL_DID(config->domainMask) |
                    MEMCON_GLOBAL_ACCCTRL_UM(config->userMode ? 1U : 0U) |
                    MEMCON_GLOBAL_ACCCTRL_NSM(config->nonSecure ? 1U : 0U) |
                    MEMCON_GLOBAL_ACCCTRL_LOCK(config->lock ? 1U : 0U);
}

/*!
 * @brief Enable or disable the MEMCON function clock gate.
 *
 * @param base    MEMCON_GLOBAL peripheral base.
 * @param enable  true: enable; false: disable.
 */
void MEMCON_GLOBAL_EnableFunctionClock(MEMCON_GLOBAL_Type *base, bool enable)
{
    if (enable)
    {
        base->FCEN |= MEMCON_GLOBAL_FCEN_FCEN_MASK;
    }
    else
    {
        base->FCEN &= ~MEMCON_GLOBAL_FCEN_FCEN_MASK;
    }
}

/*!
 * @brief Configure SLICE access control.
 *
 * @param base    MEMCON_SLICE peripheral base.
 * @param config  Pointer to access-control configuration.
 */
void MEMCON_SLICE_SetAccessControl(MEMCON_SLICE_Type *base, const memcon_access_config_t *config)
{
    assert(base != NULL);
    assert(config != NULL);
    /* SLICE.ACCCTRL.DID is 4-bit; the shared struct's uint16_t is sized for GLOBAL. */
    assert(config->domainMask < MEMCON_SLICE_DID_LIMIT);

    base->ACCCTRL = MEMCON_SLICE_ACCCTRL_DID(config->domainMask) |
                    MEMCON_SLICE_ACCCTRL_UM(config->userMode ? 1U : 0U) |
                    MEMCON_SLICE_ACCCTRL_NSM(config->nonSecure ? 1U : 0U) |
                    MEMCON_SLICE_ACCCTRL_LOCK(config->lock ? 1U : 0U);
}

/*!
 * @brief Set the slice trigger mode.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param mode  Trigger mode.
 */
void MEMCON_SLICE_SetTriggerMode(MEMCON_SLICE_Type *base, memcon_trigger_mode_t mode)
{
    base->MDCTRL = (base->MDCTRL & ~MEMCON_SLICE_MDCTRL_TRGMODE_MASK) |
                   MEMCON_SLICE_MDCTRL_TRGMODE((uint32_t)mode);
}

/*!
 * @brief Issue a software trigger and wait until hardware clears it.
 *
 * @param base  MEMCON_SLICE peripheral base.
 */
void MEMCON_SLICE_SoftwareTrigger(MEMCON_SLICE_Type *base)
{
    /* Software must ensure SWTRG is 0 before re-asserting it (RM 114.7.3.4). */
    while ((base->MDCTRL & MEMCON_SLICE_MDCTRL_SWTRG_MASK) != 0U)
    {
    }

    base->MDCTRL |= MEMCON_SLICE_MDCTRL_SWTRG_MASK;

    /* SWTRG is self-cleared once the memory power update has completed. */
    while ((base->MDCTRL & MEMCON_SLICE_MDCTRL_SWTRG_MASK) != 0U)
    {
    }
}

/*!
 * @brief Set the low-power configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index.
 * @param mode       Desired low-power mode.
 */
void MEMCON_SLICE_SetSleepBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx, memcon_power_mode_t mode)
{
    assert(blockIdx < MEMCON_BLOCK_COUNT_PER_SLICE);

    uint32_t bitPos = MEMCON_GetBlockBitPos(blockIdx);
    uint32_t fmask  = (uint32_t)MEMCON_BLOCK_FIELD_MASK << bitPos;
    uint32_t fval   = ((uint32_t)mode & MEMCON_BLOCK_FIELD_MASK) << bitPos;

    if (blockIdx < MEMCON_BLOCKS_IN_CFG0)
    {
        base->MEM_SLPCFG0 = (base->MEM_SLPCFG0 & ~fmask) | fval;
    }
    else
    {
        base->MEM_SLPCFG1 = (base->MEM_SLPCFG1 & ~fmask) | fval;
    }
}

/*!
 * @brief Get the low-power configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index.
 * @return  Programmed low-power mode for the block.
 */
memcon_power_mode_t MEMCON_SLICE_GetSleepBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx)
{
    assert(blockIdx < MEMCON_BLOCK_COUNT_PER_SLICE);

    uint32_t bitPos = MEMCON_GetBlockBitPos(blockIdx);
    uint32_t reg    = (blockIdx < MEMCON_BLOCKS_IN_CFG0) ? base->MEM_SLPCFG0 : base->MEM_SLPCFG1;

    return (memcon_power_mode_t)((reg >> bitPos) & MEMCON_BLOCK_FIELD_MASK);
}

/*!
 * @brief Set the active configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index.
 * @param mode       Desired active mode.
 */
void MEMCON_SLICE_SetActiveBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx, memcon_power_mode_t mode)
{
    assert(blockIdx < MEMCON_BLOCK_COUNT_PER_SLICE);

    uint32_t bitPos = MEMCON_GetBlockBitPos(blockIdx);
    uint32_t fmask  = (uint32_t)MEMCON_BLOCK_FIELD_MASK << bitPos;
    uint32_t fval   = ((uint32_t)mode & MEMCON_BLOCK_FIELD_MASK) << bitPos;

    if (blockIdx < MEMCON_BLOCKS_IN_CFG0)
    {
        base->MEM_RUNCFG0 = (base->MEM_RUNCFG0 & ~fmask) | fval;
    }
    else
    {
        base->MEM_RUNCFG1 = (base->MEM_RUNCFG1 & ~fmask) | fval;
    }
}

/*!
 * @brief Get the active configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index.
 * @return  Programmed active mode for the block.
 */
memcon_power_mode_t MEMCON_SLICE_GetActiveBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx)
{
    assert(blockIdx < MEMCON_BLOCK_COUNT_PER_SLICE);

    uint32_t bitPos = MEMCON_GetBlockBitPos(blockIdx);
    uint32_t reg    = (blockIdx < MEMCON_BLOCKS_IN_CFG0) ? base->MEM_RUNCFG0 : base->MEM_RUNCFG1;

    return (memcon_power_mode_t)((reg >> bitPos) & MEMCON_BLOCK_FIELD_MASK);
}
