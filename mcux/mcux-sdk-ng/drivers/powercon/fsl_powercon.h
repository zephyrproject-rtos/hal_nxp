/*
 * Copyright 2025-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_POWERCON_H
#define FSL_POWERCON_H

#include "fsl_common.h"

/*!
 * @addtogroup powercon
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief powercon driver version 2.0.0. */
#define FSL_POWERCON_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief Init-time SoC topology configuration for POWERCON.
 *
 * Routes root clocks and clock sources to their CMC handshake partners.
 * Written once at initialisation — do not change during standby or at runtime.
 * Use POWERCON_SetTopologyConfig() after the POWERCON function clock is enabled.
 */
typedef struct _powercon_topology_config
{
    uint32_t rcgcfgHskSel;   /*!< Root clock → CMC handshake partner selection (RCGCFG_HSK_SEL). */
    uint32_t csrccfgHskSel;  /*!< Clock source → CMC routing, word 0 (CSRCCFG_HSK_SEL). */
    uint32_t csrccfgHskSel1; /*!< Clock source → CMC routing, word 1 (CSRCCFG_HSK_SEL1). */
} powercon_topology_config_t;

/*!
 * @brief Per-mode standby state written to POWERCON_SOC_CTRL before WFI.
 *
 * Contains only the per-sleep-entry fields. HSK_SEL routing is init-time
 * topology; use powercon_topology_config_t and POWERCON_SetTopologyConfig() for that.
 * MUST be written before __WFI() and NOT while POWERCON_IsCmcSleepBusy() returns true.
 */
typedef struct _powercon_soc_standby_config
{
    uint32_t rcgcfgStby;  /*!< Root clock gating configuration applied during standby. */
    uint32_t csrccfgStby; /*!< Clock source selection active during standby. */
    uint32_t pmucfgStby;  /*!< Full PMU configuration word for standby state. */
    uint8_t  pmiccfgStby; /*!< PMIC mode code driven on PMIC_MODE pins during standby. */
} powercon_soc_standby_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Function Clock Control
 * @{
 */

/*!
 * @brief Enable the POWERCON_SOC_CTRL functional clock (FCEN).
 *
 * MUST be called before any other POWERCON_SOC_CTRL_Type register access.
 * After PoR wakeup (PoR resets POWERCON registers), this MUST be re-called
 * before restoring any other POWERCON state.
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 */
static inline void POWERCON_EnableFunctionClock(POWERCON_SOC_CTRL_Type *base)
{
    base->SOC_CTRL_STATUS |= POWERCON_SOC_CTRL_SOC_CTRL_STATUS_FCEN_MASK;
}

/*!
 * @brief Disable the POWERCON_SOC_CTRL functional clock (FCEN).
 *
 * Gates the functional clock. Subsequent accesses to POWERCON_SOC_CTRL_Type
 * registers will fail until POWERCON_EnableFunctionClock() is called again.
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 */
static inline void POWERCON_DisableFunctionClock(POWERCON_SOC_CTRL_Type *base)
{
    base->SOC_CTRL_STATUS &= ~POWERCON_SOC_CTRL_SOC_CTRL_STATUS_FCEN_MASK;
}

/*! @} */

/*!
 * @name CMC Active-Mode Control
 * @{
 */

/*!
 * @brief Assert SW_ALLOW_LP for explicit software-request low-power entry.
 *
 * Normal SDK POWER_Enter*() paths use __WFI() as the hardware trigger and do
 * not require this bit. Use this helper only for explicit software-request or
 * debug flows that intentionally drive CMC_CTRL.SW_ALLOW_LP.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_EnableSwAllowLowPower(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL |= POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_MASK;
}

/*!
 * @brief Deassert SW_ALLOW_LP after an explicit software-request flow.
 *
 * Normal SDK POWER_Enter*() WFI paths do not set this bit.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_DisableSwAllowLowPower(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL &= ~POWERCON_CMC_CTRL_CMC_CTRL_SW_ALLOW_LP_MASK;
}

/*!
 * @brief Enable wakeup for the specified IRQ sources (RMW-clear in IRQ_WAKEUP_MASK).
 *
 * Register polarity: 0 = wakeup enabled, 1 = masked.
 * For each word i, bits set in idMasks[i] are CLEARED in IRQ_WAKEUP_MASK[i].
 *
 * @param base    POWERCON_CMC_CTRL peripheral base address.
 * @param idMasks Pointer to 12 words where each bit identifies an IRQ to enable for wakeup.
 */
void POWERCON_EnableWakeupIRQ(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks);

/*!
 * @brief Disable wakeup for the specified IRQ sources (RMW-set in IRQ_WAKEUP_MASK).
 *
 * For each word i, bits set in idMasks[i] are SET in IRQ_WAKEUP_MASK[i].
 *
 * @param base    POWERCON_CMC_CTRL peripheral base address.
 * @param idMasks Pointer to 12 words where each bit identifies an IRQ to mask from wakeup.
 */
void POWERCON_DisableWakeupIRQ(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks);

/*!
 * @brief Enable wakeup for the specified DMA sources (RMW-clear in DMA_WAKEUP_MASK).
 *
 * Register polarity: 0 = wakeup enabled, 1 = masked.
 * For each word i, bits set in idMasks[i] are CLEARED in DMA_WAKEUP_MASK[i].
 *
 * @param base    POWERCON_CMC_CTRL peripheral base address.
 * @param idMasks Pointer to 2 words where each bit identifies a DMA channel to enable for wakeup.
 */
void POWERCON_EnableWakeupDMA(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks);

/*!
 * @brief Disable wakeup for the specified DMA sources (RMW-set in DMA_WAKEUP_MASK).
 *
 * For each word i, bits set in idMasks[i] are SET in DMA_WAKEUP_MASK[i].
 *
 * @param base    POWERCON_CMC_CTRL peripheral base address.
 * @param idMasks Pointer to 2 words where each bit identifies a DMA channel to mask from wakeup.
 */
void POWERCON_DisableWakeupDMA(POWERCON_CMC_CTRL_Type *base, const uint32_t *idMasks);

/*!
 * @brief Enable debugger-attach wakeup (NON_IRQ_CS.DBG_EN).
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_EnableDebugWakeup(POWERCON_CMC_CTRL_Type *base)
{
    base->NON_IRQ_CS |= POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_MASK;
}

/*!
 * @brief Disable debugger-attach wakeup (NON_IRQ_CS.DBG_EN).
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_DisableDebugWakeup(POWERCON_CMC_CTRL_Type *base)
{
    base->NON_IRQ_CS &= ~POWERCON_CMC_CTRL_NON_IRQ_CS_DBG_EN_MASK;
}

/*!
 * @brief Enable Non-IRQ Clock Source Stop Inhibit (CSSI).
 *
 * When enabled, CSSI prevents a non-IRQ clock source from stopping if still
 * in use during standby.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_EnableCssi(POWERCON_CMC_CTRL_Type *base)
{
    base->NON_IRQ_CS |= POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK;
}

/*!
 * @brief Bypass Non-IRQ Clock Source Stop Inhibit (CSSI).
 *
 * When bypassed, non-IRQ clock sources are not inhibited from stopping
 * during standby. Use only when the application manages clocks independently.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_DisableCssi(POWERCON_CMC_CTRL_Type *base)
{
    base->NON_IRQ_CS &= ~POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK;
}

/*!
 * @brief Lock CSSI control (write-once; survives until next reset).
 *
 * Sets CSSI_CTRL_LOCK. Once set, further CSSI enable/disable calls have no effect.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_LockCssiControl(POWERCON_CMC_CTRL_Type *base)
{
    base->NON_IRQ_CS |= POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_CTRL_LOCK_MASK;
}

/*!
 * @brief Return the CSSI allow-low-power status.
 *
 * Read-only hardware status. true means CSSI logic currently permits low-power entry.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 * @return true if CSSI_ALLOW_LP_STS is set.
 */
static inline bool POWERCON_GetCssiAllowLpStatus(POWERCON_CMC_CTRL_Type *base)
{
    return (0U != (base->NON_IRQ_CS & POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_ALLOW_LP_STS_MASK));
}

/*! @} */

/*!
 * @name CMC FSM Status
 * @{
 */

/*!
 * @brief Return true if the CMC sleep FSM is progressing.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 * @return true if CMC_SLEEP_BUSY is set.
 */
static inline bool POWERCON_IsCmcSleepBusy(POWERCON_CMC_CTRL_Type *base)
{
    return (0U != (base->CMC_STATUS & POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_BUSY_MASK));
}

/*!
 * @brief Return true if the CMC wakeup FSM is progressing.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 * @return true if CMC_WAKEUP_BUSY is set.
 */
static inline bool POWERCON_IsCmcWakeupBusy(POWERCON_CMC_CTRL_Type *base)
{
    return (0U != (base->CMC_STATUS & POWERCON_CMC_CTRL_CMC_STATUS_CMC_WAKEUP_BUSY_MASK));
}

/*!
 * @brief Return true if the CMC sleep FSM is idle.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 * @return true if CMC_SLEEP_IDLE is set.
 */
static inline bool POWERCON_IsCmcSleepIdle(POWERCON_CMC_CTRL_Type *base)
{
    return (0U != (base->CMC_STATUS & POWERCON_CMC_CTRL_CMC_STATUS_CMC_SLEEP_IDLE_MASK));
}

/*!
 * @brief Return the current CMC FSM state (0–5).
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 * @return FSM_STATE field value.
 */
static inline uint8_t POWERCON_GetCmcFsmState(POWERCON_CMC_CTRL_Type *base)
{
    return (uint8_t)((base->CMC_STATUS & POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_MASK) >>
                     POWERCON_CMC_CTRL_CMC_STATUS_FSM_STATE_SHIFT);
}

/*!
 * @brief Prevent the CMC FSM from advancing past the current step (debug only).
 *
 * Production code MUST NOT leave sleep hold enabled during normal standby.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_EnableSleepHold(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL |= POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK;
}

/*!
 * @brief Release the CMC FSM sleep hold (debug only).
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_DisableSleepHold(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL &= ~POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK;
}

/*!
 * @brief Cause CMC to behave as if in sleep without WFI (debug only).
 *
 * Production code MUST NOT leave pretend-sleep enabled during normal operation.
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_EnablePretendSleep(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL |= POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_MASK;
}

/*!
 * @brief Cancel pretend-sleep mode (debug only).
 *
 * @param base POWERCON_CMC_CTRL peripheral base address.
 */
static inline void POWERCON_DisablePretendSleep(POWERCON_CMC_CTRL_Type *base)
{
    base->CMC_CTRL &= ~POWERCON_CMC_CTRL_CMC_CTRL_PRETEND_SLEEP_MASK;
}

/*! @} */

/*!
 * @name CMC Step Count Mode
 * @{
 */

/*!
 * @brief Configure CMC step count mode for sleep and wakeup directions.
 *
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 * Bit n = 0: step n uses handshake mode. Bit n = 1: step n uses count mode.
 *
 * @param base                POWERCON_CMC_CTRL peripheral base address.
 * @param sleepCountModeMask  5-bit mask for sleep steps 0–4.
 * @param wakeupCountModeMask 5-bit mask for wakeup steps 0–4.
 */
static inline void POWERCON_SetCmcStepModeMask(POWERCON_CMC_CTRL_Type *base,
                                                uint8_t sleepCountModeMask,
                                                uint8_t wakeupCountModeMask)
{
    base->CMC_STEP_CNT_MODE =
        POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_SLEEP_COUNT_MODE(sleepCountModeMask) |
        POWERCON_CMC_CTRL_CMC_STEP_CNT_MODE_WAKEUP_COUNT_MODE(wakeupCountModeMask);
}

/*!
 * @brief Set the shared CMC step count value.
 *
 * Shared across all 5 sleep steps and all 5 wakeup steps in this CMC instance.
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 *
 * @param base       POWERCON_CMC_CTRL peripheral base address.
 * @param countValue 24-bit count value.
 */
static inline void POWERCON_SetCmcCountValue(POWERCON_CMC_CTRL_Type *base, uint32_t countValue)
{
    base->CMC_STEP_CNT = POWERCON_CMC_CTRL_CMC_STEP_CNT_COUNT(countValue);
}

/*! @} */

/*!
 * @name SOC Ctrl — Active Mode (P-Channel)
 * @{
 */

/*!
 * @brief Enable one root clock in active mode (RMW-clear one bit in RCGCFG_ACTIVE).
 *
 * RCGCFG_ACTIVE is active-low: bit=0 enables the clock, bit=1 disables it.
 * This function clears the bit for the given clockIndex, enabling that root clock.
 * Takes effect immediately — no P-Channel trigger required.
 *
 * @param base       POWERCON_SOC_CTRL peripheral base address.
 * @param clockIndex Bit index of the root clock to enable (0-based).
 */
static inline void POWERCON_EnableRootClockInActiveMode(POWERCON_SOC_CTRL_Type *base, uint8_t clockIndex)
{
    base->RCGCFG_ACTIVE &= ~(1UL << (uint32_t)clockIndex);
}

/*!
 * @brief Disable one root clock in active mode (RMW-set one bit in RCGCFG_ACTIVE).
 *
 * RCGCFG_ACTIVE is active-low: bit=1 disables the clock, bit=0 enables it.
 * This function sets the bit for the given clockIndex, disabling that root clock.
 * Takes effect immediately — no P-Channel trigger required.
 *
 * @param base       POWERCON_SOC_CTRL peripheral base address.
 * @param clockIndex Bit index of the root clock to disable (0-based).
 */
static inline void POWERCON_DisableRootClockInActiveMode(POWERCON_SOC_CTRL_Type *base, uint8_t clockIndex)
{
    base->RCGCFG_ACTIVE |= (1UL << (uint32_t)clockIndex);
}

/*!
 * @brief Enable one clock source in active mode (RMW-set one bit in CSRCCFG_ACTIVE).
 *
 * CSRCCFG_ACTIVE is active-high: bit=1 enables the clock source.
 * Staged — call POWERCON_TriggerSocUpdate() to apply.
 *
 * @param base          POWERCON_SOC_CTRL peripheral base address.
 * @param clockSourceId Bit index of the clock source to enable (0-based).
 */
static inline void POWERCON_EnableClockSourceInActiveMode(POWERCON_SOC_CTRL_Type *base, uint8_t clockSourceId)
{
    base->CSRCCFG_ACTIVE |= (1UL << (uint32_t)clockSourceId);
}

/*!
 * @brief Disable one clock source in active mode (RMW-clear one bit in CSRCCFG_ACTIVE).
 *
 * Staged — call POWERCON_TriggerSocUpdate() to apply.
 *
 * @param base          POWERCON_SOC_CTRL peripheral base address.
 * @param clockSourceId Bit index of the clock source to disable (0-based).
 */
static inline void POWERCON_DisableClockSourceInActiveMode(POWERCON_SOC_CTRL_Type *base, uint8_t clockSourceId)
{
    base->CSRCCFG_ACTIVE &= ~(1UL << (uint32_t)clockSourceId);
}

/*!
 * @brief Return true if the specified clock source is enabled in active mode.
 *
 * Reads CSRCCFG_ACTIVE and returns the bit for the given clockSourceId.
 *
 * @param base          POWERCON_SOC_CTRL peripheral base address.
 * @param clockSourceId Bit index of the clock source to query (0-based).
 * @return true if the clock source bit is set in CSRCCFG_ACTIVE.
 */
static inline bool POWERCON_IsClockSourceEnabledInActiveMode(POWERCON_SOC_CTRL_Type *base, uint8_t clockSourceId)
{
    return (bool)((base->CSRCCFG_ACTIVE >> (uint32_t)clockSourceId) & 1UL);
}

/*!
 * @brief Write PMUCFG_ACTIVE (PMU config word for active mode).
 *
 * Applied via PMU P-Channel handshake after POWERCON_TriggerSocUpdate().
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 * @param cfg  PMU configuration word.
 */
static inline void POWERCON_SetPmucfgActive(POWERCON_SOC_CTRL_Type *base, uint32_t cfg)
{
    base->PMUCFG_ACTIVE = cfg;
}

/*!
 * @brief Write PMICCFG_ACTIVE (2-bit PMIC mode for active mode).
 *
 * Drives PMIC_MODE[1:0] output pins immediately — no P-Channel trigger required.
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 * @param cfg  PMIC mode value (2-bit): 0 = no standby request; non-zero = standby request asserted.
 */
static inline void POWERCON_SetPmiccfgActive(POWERCON_SOC_CTRL_Type *base, uint8_t cfg)
{
    base->PMICCFG_ACTIVE = POWERCON_SOC_CTRL_PMICCFG_ACTIVE_PMIC_MODE(cfg);
}

/*!
 * @brief Trigger a P-Channel SOC update to apply staged CSRCCFG_ACTIVE and PMUCFG_ACTIVE changes.
 *
 * Sets P_TRG. HW sends PREQ to PMU; after acceptance HW auto-clears P_TRG and sets P_OVER.
 * SW MUST poll POWERCON_IsSocUpdateDone() before calling this function again.
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 */
static inline void POWERCON_TriggerSocUpdate(POWERCON_SOC_CTRL_Type *base)
{
    base->SOC_CTRL_STATUS |= POWERCON_SOC_CTRL_SOC_CTRL_STATUS_P_TRG_MASK;
}

/*!
 * @brief Return true when the previous P-Channel SOC update is complete.
 *
 * Checks P_OVER. SW MUST poll this before issuing a subsequent trigger.
 *
 * @param base POWERCON_SOC_CTRL peripheral base address.
 * @return true if P_OVER is set.
 */
static inline bool POWERCON_IsSocUpdateDone(POWERCON_SOC_CTRL_Type *base)
{
    return (0U != (base->SOC_CTRL_STATUS & POWERCON_SOC_CTRL_SOC_CTRL_STATUS_P_OVER_MASK));
}

/*! @} */

/*!
 * @name SOC Ctrl — Topology Configuration
 * @{
 */

/*!
 * @brief Write the init-time SoC topology configuration.
 *
 * Writes RCGCFG_HSK_SEL, CSRCCFG_HSK_SEL, and CSRCCFG_HSK_SEL1 to route
 * root clocks and clock sources to their CMC handshake partners.
 * Call once at initialisation after the POWERCON function clock is enabled.
 * Do NOT call during standby (while POWERCON_IsCmcSleepBusy() returns true).
 *
 * @param base   POWERCON_SOC_CTRL peripheral base address.
 * @param config Pointer to the topology configuration struct.
 */
void POWERCON_SetTopologyConfig(POWERCON_SOC_CTRL_Type *base,
                                const powercon_topology_config_t *config);

/*! @} */

/*!
 * @name SOC Ctrl — Standby Configuration
 * @{
 */

/*!
 * @brief Write the per-mode SOC standby configuration before WFI.
 *
 * Writes RCGCFG_STBY, CSRCCFG_STBY, PMUCFG_STBY, and PMICCFG_STBY — the
 * per-sleep-entry state POWERCON applies autonomously during the CMC/SSC
 * sleep sequence. HSK_SEL routing is not written here; use
 * POWERCON_SetTopologyConfig() at initialisation for that.
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 *
 * @param base   POWERCON_SOC_CTRL peripheral base address.
 * @param config Pointer to the standby configuration struct.
 */
void POWERCON_SetSocStandbyConfig(POWERCON_SOC_CTRL_Type *base,
                                  const powercon_soc_standby_config_t *config);

/*! @} */

/*!
 * @name System Sleep Controller (SSC) Step Mode
 * @{
 */

/*!
 * @brief Configure SSC step count mode for sleep and wakeup directions.
 *
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 * Bit n = 0: handshake mode. Bit n = 1: count mode.
 *
 * @param base                POWERCON_SYS_SLEEP_CTRL peripheral base address.
 * @param sleepCountModeMask  2-bit mask for SSC sleep steps 0–1.
 * @param wakeupCountModeMask 2-bit mask for SSC wakeup steps 0–1.
 */
static inline void POWERCON_SetSysSleepCtrlStepModeMask(POWERCON_SYS_SLEEP_CTRL_Type *base,
                                                         uint8_t sleepCountModeMask,
                                                         uint8_t wakeupCountModeMask)
{
    base->SYS_SLEEP_STEP_CNT_MODE =
        POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_SLEEP_COUNT_MODE(sleepCountModeMask) |
        POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_MODE_WAKEUP_COUNT_MODE(wakeupCountModeMask);
}

/*!
 * @brief Set the shared SSC step count value.
 *
 * Shared across all SSC sleep and wakeup steps.
 * MUST be called before __WFI(). Do NOT call while POWERCON_IsCmcSleepBusy() is true.
 *
 * @param base       POWERCON_SYS_SLEEP_CTRL peripheral base address.
 * @param countValue 24-bit count value.
 */
static inline void POWERCON_SetSysSleepCtrlCountValue(POWERCON_SYS_SLEEP_CTRL_Type *base, uint32_t countValue)
{
    base->SYS_SLEEP_STEP_CNT = POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_STEP_CNT_COUNT(countValue);
}

/*!
 * @brief Configure which CMC instances the SSC must wait for before proceeding (FORCE_SS).
 *
 * MUST be set before __WFI(). The SSC waits until all unmasked CMCs are in SLEEP_SYS
 * before proceeding with PMU/PMIC sequencing.
 *
 * @param base POWERCON_SYS_SLEEP_CTRL peripheral base address.
 * @param mask 3-bit mask: bit 0 = CMC0, bit 1 = CMC1, bit 2 = CMC2.
 */
static inline void POWERCON_SetForceStandbyMask(POWERCON_SYS_SLEEP_CTRL_Type *base, uint32_t mask)
{
    base->SYS_SLEEP_CTRL = (base->SYS_SLEEP_CTRL &
                             ~POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS_MASK) |
                            POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_FORCE_SS(mask);
}

/*!
 * @brief Configure the wakeup suppress mask (WKMASK_SS).
 *
 * When a CMC wakes up, this mask can suppress the wakeup signal to CMC0/CPU.
 *
 * @param base POWERCON_SYS_SLEEP_CTRL peripheral base address.
 * @param mask 3-bit mask: bit 0 = CMC0, bit 1 = CMC1, bit 2 = CMC2.
 */
static inline void POWERCON_SetWakeupStandbyMask(POWERCON_SYS_SLEEP_CTRL_Type *base, uint32_t mask)
{
    base->SYS_SLEEP_CTRL = (base->SYS_SLEEP_CTRL &
                             ~POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS_MASK) |
                            POWERCON_SYS_SLEEP_CTRL_SYS_SLEEP_CTRL_WKMASK_SS(mask);
}

/*! @} */

/*!
 * @name Global Control
 * @{
 */

/*!
 * @brief Set the XMC standby mask (which CMC instances participate in SSC).
 *
 * Controls bits 1–3 of XMC_STBY_MASK. Bit 0 (free-running clock) is NOT
 * controlled by this API. Reset state = 0x07 (all CMC excluded from SSC).
 * Call with mask=0x00 at init to allow all CMCs to participate in SSC;
 * if these bits remain set, SSC will never fire.
 *
 * Bit 0 of mask = CMC0 (register bit 1), bit 1 = CMC1 (bit 2), bit 2 = CMC2 (bit 3).
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 * @param mask 3-bit mask value (0x00 = all CMCs participate in SSC).
 */
static inline void POWERCON_SetXmcStandbyMask(POWERCON_GLOBAL_Type *base, uint32_t mask)
{
    uint32_t reg = base->POWERCON_GLOBAL_CTRL;
    reg &= ~(POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_MASK |
             POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_MASK |
             POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_MASK);
    if ((mask & 0x1U) != 0U)
    {
        reg |= POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK0_MASK;
    }
    if ((mask & 0x2U) != 0U)
    {
        reg |= POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK1_MASK;
    }
    if ((mask & 0x4U) != 0U)
    {
        reg |= POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_XMC_STBY_MASK2_MASK;
    }
    base->POWERCON_GLOBAL_CTRL = reg;
}

/*!
 * @brief Gate the POWERCON functional clock immediately on standby request.
 *
 * When enabled, the functional clock is gated immediately when standby is
 * requested (faster standby entry). When disabled, the clock runs until the
 * CMC FSM advances past step 1.
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 */
static inline void POWERCON_EnableFastClockOff(POWERCON_GLOBAL_Type *base)
{
    base->POWERCON_GLOBAL_CTRL |= POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_MASK;
}

/*!
 * @brief Allow the POWERCON functional clock to run until CMC FSM advances past step 1.
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 */
static inline void POWERCON_DisableFastClockOff(POWERCON_GLOBAL_Type *base)
{
    base->POWERCON_GLOBAL_CTRL &= ~POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_FCLK_OFF_MASK;
}

/*!
 * @brief Route an internal POWERCON signal to the observe pin (debug only).
 *
 * Production code MUST NOT rely on this function.
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 * @param sel  2-bit OBS_CTRL selector (0=CMC0, 1=CMC1, 2=CMC2).
 */
static inline void POWERCON_SetObserveMux(POWERCON_GLOBAL_Type *base, uint8_t sel)
{
    base->POWERCON_GLOBAL_CTRL = (base->POWERCON_GLOBAL_CTRL &
                                   ~POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL_MASK) |
                                  POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_OBS_CTRL(sel);
}

/*!
 * @brief Source debug wakeup from the global POWERCON path.
 *
 * Use when debug wakeup must span multiple CMC domains simultaneously.
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 */
static inline void POWERCON_EnableGlobalDebugWakeup(POWERCON_GLOBAL_Type *base)
{
    base->POWERCON_GLOBAL_CTRL |= POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_MASK;
}

/*!
 * @brief Source debug wakeup from the per-CMC path (hardware default after reset).
 *
 * @param base POWERCON_GLOBAL peripheral base address.
 */
static inline void POWERCON_EnablePerCmcDebugWakeup(POWERCON_GLOBAL_Type *base)
{
    base->POWERCON_GLOBAL_CTRL &= ~POWERCON_GLOBAL_POWERCON_GLOBAL_CTRL_DBGWK_SWITCH_MASK;
}

/*! @} */

/*!
 * @name GPR — Persistent Data Storage
 * @{
 */

/*!
 * @brief Write a warm GPR word.
 *
 * Warm GPRs survive warm reset. For index 0 (GPR_WARM_0), bits[20:0] are CCM
 * ACK masks reserved by hardware and are preserved automatically; only
 * bits[31:21] carry user data.
 *
 * @param base  POWERCON_SOC_CTRL peripheral base address.
 * @param index GPR index: 0 = GPR_WARM_0, 1–3 = GPR_WARM[0..2].
 * @param data  Value to write.
 */
static inline void POWERCON_SetWarmGPR(POWERCON_SOC_CTRL_Type *base, uint8_t index, uint32_t data)
{
    if (index == 0U)
    {
        /* bits[20:0] are CCM ACK masks managed by hardware; preserve them. */
        base->GPR_WARM_0 = (base->GPR_WARM_0 & 0x001FFFFFU) | (data & ~0x001FFFFFU);
    }
    else
    {
        base->GPR_WARM[index - 1U] = data;
    }
}

/*!
 * @brief Read a warm GPR word.
 *
 * For index 0, bits[20:0] contain CCM ACK masks — mask them off if only user
 * data (bits[31:21]) is needed.
 *
 * @param base  POWERCON_SOC_CTRL peripheral base address.
 * @param index GPR index: 0 = GPR_WARM_0, 1–3 = GPR_WARM[0..2].
 * @return GPR value.
 */
static inline uint32_t POWERCON_GetWarmGPR(POWERCON_SOC_CTRL_Type *base, uint8_t index)
{
    if (index == 0U)
    {
        return base->GPR_WARM_0;
    }
    else
    {
        return base->GPR_WARM[index - 1U];
    }
}

/*!
 * @brief Write a cold GPR word.
 *
 * Cold GPRs survive PoR. All 32 bits are user-accessible.
 *
 * @param base  POWERCON_SOC_CTRL peripheral base address.
 * @param index GPR index 0–3.
 * @param data  Value to write.
 */
static inline void POWERCON_SetColdGPR(POWERCON_SOC_CTRL_Type *base, uint8_t index, uint32_t data)
{
    base->GPR_COLD[index] = data;
}

/*!
 * @brief Read a cold GPR word.
 *
 * @param base  POWERCON_SOC_CTRL peripheral base address.
 * @param index GPR index 0–3.
 * @return GPR value.
 */
static inline uint32_t POWERCON_GetColdGPR(POWERCON_SOC_CTRL_Type *base, uint8_t index)
{
    return base->GPR_COLD[index];
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */

#endif /* FSL_POWERCON_H */
