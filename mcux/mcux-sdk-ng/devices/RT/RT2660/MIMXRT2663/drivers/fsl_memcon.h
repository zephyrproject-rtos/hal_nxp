/*
 * Copyright 2026 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _FSL_MEMCON_H_
#define _FSL_MEMCON_H_

#include "fsl_common.h"

/*!
 * @addtogroup memcon
 * @{
 */

/*! @file */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief MEMCON driver version 1.0.0. */
#define FSL_MEMCON_DRIVER_VERSION (MAKE_VERSION(1, 0, 0))
/*! @} */

/*! @brief Maximum number of memory blocks addressable per MEMCON slice (B0..B11). */
#define MEMCON_BLOCK_COUNT_PER_SLICE (12U)

/*! @brief Number of blocks held in the *_CFG0 register (B0..B7). */
#define MEMCON_BLOCKS_IN_CFG0 (8U)

/*! @brief 2-bit power-mode field width inside a 4-bit nibble per block. */
#define MEMCON_BLOCK_FIELD_MASK  (0x3U)
/*! @brief Distance (in bits) between two consecutive block fields. */
#define MEMCON_BLOCK_FIELD_STRIDE (4U)

/*! @brief Exclusive upper bound for SLICE ACCCTRL.DID mask values (4-bit field, 0..15). */
#define MEMCON_SLICE_DID_LIMIT (16U)

/*!
 * @brief Per-block memory power mode shared by MEM_SLPCFGn and MEM_RUNCFGn.
 *
 * Hardware only supports the transitions Active <-> Retention and
 * Active <-> Power-down. Going directly between Retention and Power-down is
 * not supported.
 */
typedef enum _memcon_power_mode
{
    kMEMCON_PowerModeActive    = 0U, /*!< Active mode (full power). */
    kMEMCON_PowerModeRetention = 1U, /*!< Retention mode (data preserved). */
    kMEMCON_PowerModePowerDown = 2U, /*!< Power-down mode (data lost). */
} memcon_power_mode_t;

/*!
 * @brief Slice trigger-mode selection (MDCTRL[TRGMODE]).
 */
typedef enum _memcon_trigger_mode
{
    kMEMCON_TriggerHardware = 1U, /*!< Hardware (PDCON) only. */
    kMEMCON_TriggerSoftware = 2U, /*!< Software only. */
    kMEMCON_TriggerBoth     = 3U, /*!< Hardware + software. */
} memcon_trigger_mode_t;

/*!
 * @brief Access-control configuration for either the GLOBAL or SLICE block.
 *
 * The GLOBAL ACCCTRL has a 16-bit DID; the SLICE ACCCTRL has a 4-bit DID.
 * Bits beyond each register's width are ignored automatically.
 */
typedef struct _memcon_access_config
{
    uint16_t domainMask; /*!< Domain-ID mask (1 bit per domain). */
    bool     userMode;   /*!< true: allow user-mode writes. */
    bool     nonSecure;  /*!< true: allow non-secure writes. */
    bool     lock;       /*!< true: lock ACCCTRL until next reset. */
} memcon_access_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/* =========================================================================
 * MEMCON_GLOBAL APIs
 * ========================================================================= */

/*!
 * @name MEMCON global block
 * @{
 */

/*!
 * @brief Read the GLOBAL VERID register.
 *
 * @param base  MEMCON_GLOBAL peripheral base.
 * @return Raw VERID value.
 */
static inline uint32_t MEMCON_GLOBAL_GetVersion(MEMCON_GLOBAL_Type *base)
{
    return base->VERID;
}

/*!
 * @brief Configure GLOBAL access control (ACCCTRL).
 *
 * @param base    MEMCON_GLOBAL peripheral base.
 * @param config  Pointer to access-control configuration; must not be NULL.
 */
void MEMCON_GLOBAL_SetAccessControl(MEMCON_GLOBAL_Type *base, const memcon_access_config_t *config);

/*!
 * @brief Read the raw GLOBAL ACCCTRL register.
 *
 * @param base  MEMCON_GLOBAL peripheral base.
 * @return Raw ACCCTRL value.
 */
static inline uint32_t MEMCON_GLOBAL_GetAccessControl(MEMCON_GLOBAL_Type *base)
{
    return base->ACCCTRL;
}

/*!
 * @brief Enable or disable the MEMCON function clock gate (FCEN).
 *
 * SW must only configure to disabled when no work is active in PDCON / MEMCON.
 * Warm reset always enables the clock.
 *
 * @param base    MEMCON_GLOBAL peripheral base.
 * @param enable  true: enable; false: gate the function clock.
 */
void MEMCON_GLOBAL_EnableFunctionClock(MEMCON_GLOBAL_Type *base, bool enable);

/*!
 * @brief Check whether the GLOBAL function clock is enabled.
 *
 * @param base  MEMCON_GLOBAL peripheral base.
 * @return  true if FCEN is set, false otherwise.
 */
static inline bool MEMCON_GLOBAL_IsFunctionClockEnabled(MEMCON_GLOBAL_Type *base)
{
    return (base->FCEN & MEMCON_GLOBAL_FCEN_FCEN_MASK) != 0U;
}

/*! @} */

/* =========================================================================
 * MEMCON_SLICE APIs
 * ========================================================================= */

/*!
 * @name MEMCON slice block
 * @{
 */

/*!
 * @brief Read the SLICE VERID register.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @return Raw VERID value.
 */
static inline uint32_t MEMCON_SLICE_GetVersion(MEMCON_SLICE_Type *base)
{
    return base->VERID;
}

/*!
 * @brief Configure SLICE access control (ACCCTRL).
 *
 * Only the lower 4 bits of @p config->domainMask are written to DID.
 *
 * @param base    MEMCON_SLICE peripheral base.
 * @param config  Pointer to access-control configuration; must not be NULL.
 */
void MEMCON_SLICE_SetAccessControl(MEMCON_SLICE_Type *base, const memcon_access_config_t *config);

/*!
 * @brief Read the raw SLICE ACCCTRL register.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @return Raw ACCCTRL value.
 */
static inline uint32_t MEMCON_SLICE_GetAccessControl(MEMCON_SLICE_Type *base)
{
    return base->ACCCTRL;
}

/*!
 * @brief Set the slice trigger mode (MDCTRL[TRGMODE]).
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param mode  See ::memcon_trigger_mode_t.
 */
void MEMCON_SLICE_SetTriggerMode(MEMCON_SLICE_Type *base, memcon_trigger_mode_t mode);

/*!
 * @brief Get the current trigger mode.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @return  Current trigger mode.
 */
static inline memcon_trigger_mode_t MEMCON_SLICE_GetTriggerMode(MEMCON_SLICE_Type *base)
{
    return (memcon_trigger_mode_t)(uint32_t)((base->MDCTRL & MEMCON_SLICE_MDCTRL_TRGMODE_MASK) >>
                                             MEMCON_SLICE_MDCTRL_TRGMODE_SHIFT);
}

/*!
 * @brief Issue a software trigger (MDCTRL[SWTRG]) and wait until hardware clears it.
 *
 * The trigger updates the memory power state to match MEM_RUNCFG0/1.
 * Only valid when the trigger mode is Software or Hardware+Software.
 *
 * @param base  MEMCON_SLICE peripheral base.
 */
void MEMCON_SLICE_SoftwareTrigger(MEMCON_SLICE_Type *base);

/*!
 * @brief Check whether a previously-issued software trigger is still in progress.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @return  true while SWTRG is still asserted, false once the update has completed.
 */
static inline bool MEMCON_SLICE_IsSoftwareTriggerBusy(MEMCON_SLICE_Type *base)
{
    return (base->MDCTRL & MEMCON_SLICE_MDCTRL_SWTRG_MASK) != 0U;
}

/*! @} */

/*!
 * @name Per-block power mode
 * @{
 */

/*!
 * @brief Set the low-power configuration of a single block (MEM_SLPCFGn[LPC_Bx]).
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index 0..MEMCON_BLOCK_COUNT_PER_SLICE-1.
 * @param mode       Desired low-power mode.
 */
void MEMCON_SLICE_SetSleepBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx, memcon_power_mode_t mode);

/*!
 * @brief Get the low-power configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index 0..MEMCON_BLOCK_COUNT_PER_SLICE-1.
 * @return  Programmed low-power mode for the block.
 */
memcon_power_mode_t MEMCON_SLICE_GetSleepBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx);

/*!
 * @brief Set the active configuration of a single block (MEM_RUNCFGn[HPC_Bx]).
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index 0..MEMCON_BLOCK_COUNT_PER_SLICE-1.
 * @param mode       Desired active-mode setting.
 */
void MEMCON_SLICE_SetActiveBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx, memcon_power_mode_t mode);

/*!
 * @brief Get the active configuration of a single block.
 *
 * @param base       MEMCON_SLICE peripheral base.
 * @param blockIdx   Block index 0..MEMCON_BLOCK_COUNT_PER_SLICE-1.
 * @return  Programmed active mode for the block.
 */
memcon_power_mode_t MEMCON_SLICE_GetActiveBlockMode(MEMCON_SLICE_Type *base, uint8_t blockIdx);

/*! @} */

/*!
 * @name Bulk per-slice configuration
 * @{
 */

/*!
 * @brief Bulk-write the SLICE low-power power-mode registers.
 *
 * The two register values are written verbatim - callers should pre-pack the
 * desired LPC_Bx fields. Bits in @p cfg1 are ignored on slices that do not
 * implement MEM_SLPCFG1.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param cfg0  Value for MEM_SLPCFG0 (blocks 0..7).
 * @param cfg1  Value for MEM_SLPCFG1 (blocks 8..11), 0 if unused.
 */
static inline void MEMCON_SLICE_SetSleepConfig(MEMCON_SLICE_Type *base, uint32_t cfg0, uint32_t cfg1)
{
    base->MEM_SLPCFG0 = cfg0;
    base->MEM_SLPCFG1 = cfg1;
}

/*!
 * @brief Bulk-write the SLICE active power-mode registers.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param cfg0  Value for MEM_RUNCFG0 (blocks 0..7).
 * @param cfg1  Value for MEM_RUNCFG1 (blocks 8..11), 0 if unused.
 */
static inline void MEMCON_SLICE_SetActiveConfig(MEMCON_SLICE_Type *base, uint32_t cfg0, uint32_t cfg1)
{
    base->MEM_RUNCFG0 = cfg0;
    base->MEM_RUNCFG1 = cfg1;
}

/*!
 * @brief Read the SLICE low-power register pair.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param cfg0  Out: raw MEM_SLPCFG0; may be NULL.
 * @param cfg1  Out: raw MEM_SLPCFG1; may be NULL.
 */
static inline void MEMCON_SLICE_GetSleepConfig(MEMCON_SLICE_Type *base, uint32_t *cfg0, uint32_t *cfg1)
{
    if (cfg0 != NULL)
    {
        *cfg0 = base->MEM_SLPCFG0;
    }
    if (cfg1 != NULL)
    {
        *cfg1 = base->MEM_SLPCFG1;
    }
}

/*!
 * @brief Read the SLICE active register pair.
 *
 * @param base  MEMCON_SLICE peripheral base.
 * @param cfg0  Out: raw MEM_RUNCFG0; may be NULL.
 * @param cfg1  Out: raw MEM_RUNCFG1; may be NULL.
 */
static inline void MEMCON_SLICE_GetActiveConfig(MEMCON_SLICE_Type *base, uint32_t *cfg0, uint32_t *cfg1)
{
    if (cfg0 != NULL)
    {
        *cfg0 = base->MEM_RUNCFG0;
    }
    if (cfg1 != NULL)
    {
        *cfg1 = base->MEM_RUNCFG1;
    }
}

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /* _FSL_MEMCON_H_ */
