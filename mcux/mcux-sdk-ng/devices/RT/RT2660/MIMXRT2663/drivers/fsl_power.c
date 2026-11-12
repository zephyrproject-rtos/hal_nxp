/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_power.h"
#include "fsl_modcon.h"
#include "fsl_clock.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power"
#endif

/* Number of 32-bit words covering all 384 NVIC IRQs and 64 DMA sources. */
#define POWER_IRQ_WAKEUP_MASK_COUNT 12U
#define POWER_DMA_WAKEUP_MASK_COUNT 2U
#define POWER_PDCON_DOMAIN_COUNT    6U /*!< RT2660 PDCON sleep-event flags cover domains 0..5. */

/*
 * Standby configuration constants.
 */
#define POWER_CSRCCFG_STBY_ALL_OFF (0x00000000u)       /*!< Turn off all clock sources in standby */
#define POWER_CSRCCFG_STBY_ALL_ON  ((1UL << 9U) - 1UL) /*!< Keep all clock sources enabled in standby */

/*
 * RCGCFG_STBY helper macro - builds the 8-bit root-clock enable word from
 * the individual bool fields in power_sleep_config_t / power_deep_sleep_config_t.
 * RCGCFG_STBY is active-high: bit=1 keeps the root clock enabled in standby.
 */
#define POWER_BUILD_RCGCFG_STBY(cfg)                                                                          \
    (((cfg)->enableComputeRootClock ? (1UL << 0U) : 0UL) | ((cfg)->enableMainRootClock ? (1UL << 1U) : 0UL) | \
     ((cfg)->enableWakeRootClock ? (1UL << 2U) : 0UL) | ((cfg)->enableCommRootClock ? (1UL << 3U) : 0UL) |    \
     ((cfg)->enableMediaRootClock ? (1UL << 4U) : 0UL) | ((cfg)->enableAudioRootClock ? (1UL << 5U) : 0UL) |  \
     ((cfg)->enableWake1MRootClock ? (1UL << 6U) : 0UL) | ((cfg)->enableWake2MRootClock ? (1UL << 7U) : 0UL))

/* CSRCCFG_STBY is active-high for standby source retention: bit=1 keeps the
 * corresponding clock source enabled in standby; bit=0 lets it turn off. */
#define POWER_BUILD_CSRCCFG_STBY(cfg)                                                           \
    (((cfg)->enableLdoa0V8ClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_LDOA_0V8) : 0UL) | \
     ((cfg)->enableFro192MClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_FRO192M) : 0UL) |  \
     ((cfg)->enableFro12MClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_FRO12M) : 0UL) |    \
     ((cfg)->enableMainPllClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_MAINPLL) : 0UL) |  \
     ((cfg)->enableCorePllClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_COREPLL) : 0UL) |  \
     ((cfg)->enableSysPllClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_SYSPLL) : 0UL) |    \
     ((cfg)->enableLdoq0V8ClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_LDOQ_0V8) : 0UL) | \
     ((cfg)->enableSxoscClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_SXOSC) : 0UL) |      \
     ((cfg)->enableFro12MLpClockSource ? (1UL << (uint32_t)kPOWER_ClockSource_FRO12M_LP) : 0UL))

/* RT2660 MEMCON layout constants. */
#define POWER_MEMCON_MAX_BLOCKS_PER_SLICE 12U /*!< Maximum blocks configurable per MEMCON slice */

/* PMUCFG.pmuMode bitfield values (RT2660 PMU mode encoding). */
#define POWER_PMU_MODE_LP  2U /*!< Low Power (ZBB, 0.8 V DCDC) */
#define POWER_PMU_MODE_RET 3U /*!< Retention (DCDC off) */
#define POWER_PMU_MODE_BB  4U /*!< Body Bias mode (Deep Power Down) */

/* PMUCFG LDO mode field encoding (shared by ldo0V8Mode, ldo1V8Mode, ldoVdda1V8Mode). */
#define POWER_LDO_MODE_LP 2U /*!< LDO Low Power mode */

/*
 * Body-bias FBB voltage codes.
 *
 * Primary source: OTP fuse ANA_CFG12 (FSB shadow word 50, RamAccessFSB=Public per
 * the RT2660 fusemap OTP_CONFIG_OCOTP_V2 sheet). Layout:
 *   [2:0]   PMU_OTP_WB_MODE_SEL_PRIMARY   (cached for future PMU driver use)
 *   [22:16] PMU_OTP_WB_NWELL_V_SEL_PRIMARY (7-bit) -> pmu_body_bias_config_t.nwellVolSel
 *   [30:24] PMU_OTP_WB_PWELL_V_SEL_PRIMARY (7-bit) -> pmu_body_bias_config_t.pwellVolSel
 *
 * Backup source: OTP fuse ANA_CFG13 (FSB shadow word 51). Same layout as CFG12 for
 * bits [2:0] / [22:16] / [30:24], plus a select bit at [31]:
 *   [31]    PMU_OTP_WB_TRIM_SEL
 * When TRIM_SEL=1, the BACKUP fields from CFG13 override the PRIMARY fields from
 * CFG12 (per field: BACKUP is used only if non-zero, otherwise fall back to PRIMARY).
 * This is the OTP-level hook for a re-trim after silicon characterization when the
 * PRIMARY word cannot be re-burned.
 *
 * Both reads run once inside POWER_SetPolicy() and cache into s_fbbTrim. FBB
 * transitions reuse the cache without re-reading the FSB.
 *
 * Fallback (blank fuse, FSB error, or selected field reads back as zero): the
 * verification-team reference codes below from rt2660_bodybias_configuration.drawio.
 * This keeps un-fused silicon and pre-characterization parts running through the FBB
 * flow instead of faulting into 0 mV body bias.
 */
#define POWER_BODYBIAS_FUSE_WORD_ANA_CFG12 (50U)
#define POWER_BODYBIAS_FUSE_WORD_ANA_CFG13 (51U)

/* CFG12 PRIMARY and CFG13 BACKUP share the same bit layout for the three trim fields. */
#define POWER_ANA_CFG_MODE_SEL_MASK     (0x00000007U) /* [2:0]   */
#define POWER_ANA_CFG_MODE_SEL_SHIFT    (0U)
#define POWER_ANA_CFG_NWELL_V_SEL_MASK  (0x007F0000U) /* [22:16] */
#define POWER_ANA_CFG_NWELL_V_SEL_SHIFT (16U)
#define POWER_ANA_CFG_PWELL_V_SEL_MASK  (0x7F000000U) /* [30:24] */
#define POWER_ANA_CFG_PWELL_V_SEL_SHIFT (24U)

/* CFG13-only select bit. */
#define POWER_ANA_CFG13_TRIM_SEL_MASK (0x80000000U) /* [31] */

#define POWER_BODYBIAS_FBB_NWELL_VOL_SEL (0x18U)    /* fallback: ~1200 mV per verification ref */
#define POWER_BODYBIAS_FBB_PWELL_VOL_SEL (0x24U)    /* fallback: ~1800 mV per verification ref */

/* POWERCON GPR_COLD_0 bit 0 is a force-alive override for MAIN-domain TCM.
 * 1 = keep the MAIN-domain TCM powered; 0 = allow the configured low-power
 * sequence to power the TCM down.  Clear before deep low-power entry so the
 * low-power sequence is not blocked by a stale retention override while keeping
 * all other cold-GPR application bits intact. */
#define POWER_GPR_COLD0_MAIN_TCM_FORCE_ALIVE_MASK (1UL << 0U)

/* Root clocks that must remain enabled during Power Down standby:
 * bit 7 = WAKE_2M, bit 6 = WAKE_1M, bit 2 = WAKE_SS, bit 1 = MAIN_SS.
 * MAIN_SS is intentionally kept on because wakeup from Power Down resets the
 * system and the reset flow reloads OTP trim values; OTP needs a MAIN clock. */
#define POWER_RCGCFG_STBY_POWERDOWN_REQUIRED                                                               \
    ((1UL << (uint32_t)kPOWER_RootClock_WAKE_SS_2MHz) | (1UL << (uint32_t)kPOWER_RootClock_WAKE_SS_1MHz) | \
     (1UL << (uint32_t)kPOWER_RootClock_WAKE_SS) | (1UL << (uint32_t)kPOWER_RootClock_MAIN_SS))

/* Root clocks required for Deep Sleep wakeup detection. */
#define POWER_RCGCFG_STBY_DEEPSLEEP_REQUIRED \
    ((1UL << (uint32_t)kPOWER_RootClock_WAKE_SS_2MHz) | (1UL << (uint32_t)kPOWER_RootClock_WAKE_SS_1MHz))

/* VDD_CORE set-point codes. These are DCDC VOUT_ADJ codes (VOUT = 0.225 V + N x 0.025 V,
 * with N=0 a special case = 0.8 V). In active run modes the voltage is applied through the
 * DCDC via PMU_ConfigDcdc(); PMUCFG_ACTIVE.coreLvl alone does not move the rail and is only
 * kept consistent with the applied VOUT_ADJ. In standby the same codes drive the PMU DAC.
 * POWER_PMUCFG_CORELEVEL_090V / _080V are declared in fsl_power.h (public) since they are also
 * part of power_ext_regulator_hooks_t::setCoreVoltage's documented contract. */
#define POWER_PMUCFG_CORELEVEL_065V 17U /*!< 0.65 V - Deep Sleep standby (0.225 + 17 x 0.025). */

/* Core-frequency classification thresholds (Hz) for POWER_GetCurrentRunMode(). Margins are
 * deliberate: Normal Run cannot always be divided to exactly 800 MHz (typically ~792 MHz),
 * and LP is ~600 MHz.  The public power_run_mode_t enum is defined in fsl_power.h. */
#define POWER_RUNMODE_HP_FREQ_THRESHOLD_HZ (900000000U) /*!< >= 900 MHz -> HP (~1 GHz). */
#define POWER_RUNMODE_NP_FREQ_THRESHOLD_HZ \
    (700000000U) /*!< >= 700 MHz -> Normal (~792/800 MHz); below -> LP (~600 MHz). */

/*
 * MEMCON slice indices for each power domain's TCM memories.
 * Derived from power_memory_t encoding: (slice << 8) | block.
 */
#define POWER_CPU_TCM_SLICES \
    {kPOWER_Mem_CpuICache, kPOWER_Mem_CpuDCacheData, kPOWER_Mem_CpuITCM, kPOWER_Mem_CpuDTCM, kPOWER_Mem_CpuDCacheTag}
#define POWER_NPU_TCM_SLICES   {kPOWER_Mem_NpuWeightCache, kPOWER_Mem_NpuResultBuffers}
#define POWER_COMM_TCM_SLICES  {kPOWER_Mem_CommShared, kPOWER_Mem_CommType2}
#define POWER_MEDIA_TCM_SLICES {kPOWER_Mem_MediaShared}

/* Slice 2 SRAM: OCRAM per-block plus LLC/Audio/WakeSram are 1-block writes issued via
 * POWER_SetMemBlockSleepMode() with the enum constant directly (no macro/array needed).
 * S2 B0 (kPOWER_Mem_ComputeSram01) is hardcoded to Retention in the driver — see
 * POWER_EnterDeepSleep(). */

/* All fsl_power-managed memcon-controllable blocks. Used by POWER_EnterSleep to write
 * MEM_SLPCFG=Active explicitly for state hygiene (Sleep does not physically transition
 * memories, but this clears stale Retention/PowerDown values left by a prior Deep-Sleep
 * or Power-Down entry). Keep this list in sync with the per-group macros above +
 * POWER_{CPU,NPU,COMM,MEDIA}_TCM_SLICES. */
#define POWER_ALL_MEMORY_SLICES                                                                                 \
    {kPOWER_Mem_WakeSram,       kPOWER_Mem_ComputeSram01,    kPOWER_Mem_ComputeSram23, kPOWER_Mem_ComputeSram4, \
     kPOWER_Mem_ComputeSram5,   kPOWER_Mem_ComputeSram6,     kPOWER_Mem_ComputeSram7,  kPOWER_Mem_ComputeSram8, \
     kPOWER_Mem_ComputeSram9,   kPOWER_Mem_LlcCacheBuffer,   kPOWER_Mem_Audio8Kb,      kPOWER_Mem_CpuICache,    \
     kPOWER_Mem_CpuDCacheData,  kPOWER_Mem_CpuITCM,          kPOWER_Mem_CpuDTCM,       kPOWER_Mem_CpuDCacheTag, \
     kPOWER_Mem_NpuWeightCache, kPOWER_Mem_NpuResultBuffers, kPOWER_Mem_MediaShared,   kPOWER_Mem_CommShared,   \
     kPOWER_Mem_CommType2}

/* PMU standby word for Power Down: pmuMode=RET, DCDC off, all LDOs off. */
#define POWER_PMU_STATE_PD_WORD                          \
    ((power_pmu_state_t){.dcdcMode       = 0U,           \
                         .ldo0V8Mode     = 2U,           \
                         .ldo1V8Mode     = 0U,           \
                         .ldoVdda1V8Mode = 0U,           \
                         .dcdcOffPmuRet  = 1U,           \
                         .coreLvl        = 0U,           \
                         .pmuMode        = POWER_PMU_MODE_RET}) \
        .word

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*
 * Driver-private SW wakeup state - one shadow mask per CMC wakeup register array.
 * Polarity: 0 = wakeup enabled, 1 = masked (matches hardware register polarity).
 * All sources start masked (all bits = 1) and are written to hardware inside
 * POWER_ApplyWakeupSources() before every POWER_Enter*() call.
 *
 * RT2660 CMC routing:
 *   s_irqWakeupMask[]      -> CMC0 IRQ_WAKEUP_MASK  (CPU / M85 core, any NVIC interrupt)
 *   s_mainDmaWakeupMask[]  -> CMC1 DMA_WAKEUP_MASK  (MAIN domain DMA wakeup source indices 0-63)
 *   s_wakeDmaWakeupMask[]  -> CMC2 DMA_WAKEUP_MASK  (WAKE domain DMA wakeup source indices 31-43)
 */
static uint32_t s_irqWakeupMask[POWER_IRQ_WAKEUP_MASK_COUNT];
static uint32_t s_mainDmaWakeupMask[POWER_DMA_WAKEUP_MASK_COUNT];
static uint32_t s_wakeDmaWakeupMask[POWER_DMA_WAKEUP_MASK_COUNT];

#if PMU_DRIVER_UPDATE_TRIM_VALUE
/*
 * Cached FBB trim values from OTP fuses ANA_CFG12 / ANA_CFG13. Loaded by
 * POWER_InitBodyBiasConfig() on the first POWER_SetPolicy() call. `s_fbbTrim` keeps the
 * three primitive fields (nwell / pwell / modeSel) mainly for diagnostics; the mode-run
 * paths consume the pre-built `s_fbbCfg` directly.
 *
 * Initialized to the reference fallback so any pre-POWER_SetPolicy() body-bias apply
 * (should not happen in normal flow) still uses safe values.
 */
static struct
{
    uint8_t nwell;   /*!< 7-bit N-well voltage selection code. */
    uint8_t pwell;   /*!< 7-bit P-well voltage selection code. */
    uint8_t modeSel; /*!< 3-bit PMU_OTP_WB_MODE_SEL from CFG12 or CFG13 (per TRIM_SEL). Not applied
                          to s_fbbCfg.mode: fsl_power's HP/NP run modes always request FBBFull. */
} s_fbbTrim = {
    .nwell   = POWER_BODYBIAS_FBB_NWELL_VOL_SEL,
    .pwell   = POWER_BODYBIAS_FBB_PWELL_VOL_SEL,
    .modeSel = 0U,
};
#endif /* PMU_DRIVER_UPDATE_TRIM_VALUE */

/*
 * Pre-built FBB body-bias config used by every POWER_Enter*Run() FBB apply. Populated
 * by POWER_InitBodyBiasConfig() (called from POWER_SetPolicy()) as:
 *   PMU_GetDefaultBodyBiasConfig(&s_fbbCfg);
 *   s_fbbCfg.mode        = kPMU_BodyBiasFBBFull;               // always
 *   s_fbbCfg.nwellVolSel = s_fbbTrim.nwell;                     // only if PMU_DRIVER_UPDATE_TRIM_VALUE
 *   s_fbbCfg.pwellVolSel = s_fbbTrim.pwell;                     // only if PMU_DRIVER_UPDATE_TRIM_VALUE
 *
 * `mode` is always FBBFull: which body-bias mode to request is a driver policy decision,
 * independent of whether the trim value is known. `nwellVolSel`/`pwellVolSel` are only
 * populated from the OTP fuse trim when PMU_DRIVER_UPDATE_TRIM_VALUE (fsl_pmu.h) is enabled.
 * That same macro also gates PMU_ConfigBodyBias() (fsl_pmu.c): disabled (default), it leaves
 * the NWELL_VOL/PWELL_VOL register bits untouched so ROM's own trim (once the fuses are
 * trimmed) is never clobbered by SW, and these two fields go unused; enabled, it writes them
 * like every other field. Both sides read the one macro so they can't drift out of sync.
 *
 * Zero-initialized here so a body-bias apply before POWER_SetPolicy() would come out as
 * pmu_body_bias_mode_t=kPMU_BodyBiasZBB (0) — the safe default that PMU_ApplyBodyBias
 * accepts without N-well/P-well OK gating. In normal flow, s_fbbCfg is always populated
 * before any FBB apply.
 */
static pmu_body_bias_config_t s_fbbCfg;

/* File-scope MEMCON slice base pointers. Shared by every helper that touches MEMCON
 * so the array is not redeclared on the stack of each callee. */
static MEMCON_SLICE_Type *const s_memconSliceBases[] = MEMCON_SLICE_BASE_PTRS;

/* Four RT2660 SW-controllable power domains (PD_CPU/NPU/COMM/MEDIA). */
static const uint8_t s_swPowerDomains[] = {
    (uint8_t)kPOWER_DomainCpu,
    (uint8_t)kPOWER_DomainNpu,
    (uint8_t)kPOWER_DomainComm,
    (uint8_t)kPOWER_DomainMedia,
};

/*
 * CSSI/ELS LP handshake bypass flag.
 *
 * Default: true (bypass enabled) - CSSI firmware is not yet available for early
 * bring-up.  Set to false via POWER_SetCssiLpHandshakeBypass() when CSSI firmware
 * is ready for production validation.
 *
 * TEST ONLY: this bypass MUST be disabled before production use.
 */
static bool s_cssiBypass = true;

/* Board-registered external-regulator hooks (NULL = use the on-chip DCDC/LDOs, the default).
 * fsl_power stores only the pointer; the board owns the pointed-to struct's lifetime. */
static const power_ext_regulator_hooks_t *s_extRegHooks = NULL;

/*******************************************************************************
 * Private helpers
 ******************************************************************************/

/*
 * Builds step-mode masks from a power_cmc_step_config_t and applies them to
 * the given CMC instance register block.
 */
static void POWER_ApplyCmcStepConfig(POWERCON_CMC_CTRL_Type *base, const power_cmc_step_config_t *cfg)
{
    /* Map the five CMC step fields to a pointer array for uniform iteration. */
    const power_step_config_t *steps[] = {
        &cfg->busMasterLpcg, &cfg->busSlaveLpcg, &cfg->rootClockGate, &cfg->clockSource, &cfg->powerDomain,
    };
    uint8_t sleepMask   = 0U;
    uint8_t wakeupMask  = 0U;
    uint32_t countValue = 0U;

    /* Build sleep and wakeup count-mode masks; capture the shared countValue. */
    for (uint8_t i = 0U; i < ARRAY_SIZE(steps); i++)
    {
        if (steps[i]->sleepMode == kPOWER_StepModeCount)
        {
            sleepMask |= (uint8_t)((1U << i) & 0xFFU);
            countValue = steps[i]->countValue;
        }
        if (steps[i]->wakeupMode == kPOWER_StepModeCount)
        {
            wakeupMask |= (uint8_t)((1U << i) & 0xFFU);
            countValue = steps[i]->countValue;
        }
    }

    /* Write mode mask; set count value only when at least one step uses count mode. */
    POWERCON_SetCmcStepModeMask(base, sleepMask, wakeupMask);
    if ((sleepMask | wakeupMask) != 0U)
    {
        POWERCON_SetCmcCountValue(base, countValue);
    }
}

/*!
 * brief Flushes the accumulated SW wakeup masks to the CMC0/1/2 hardware registers.
 *
 * Writes accumulated wakeup masks to the three CMC instances according to the
 * RT2660-specific CMC-to-domain routing:
 *   CMC0 <- s_irqWakeupMask     (CPU / M85 core, any NVIC interrupt)
 *   CMC1 <- s_mainDmaWakeupMask (MAIN domain DMA wakeup source indices 0-63)
 *   CMC2 <- s_wakeDmaWakeupMask (WAKE domain DMA wakeup source indices 31-43)
 *
 * Each CMC receives only its relevant wakeup type; the other register array is
 * written as all-masked so it cannot generate spurious wakeups.
 *
 * Called automatically before every POWER_Enter*() including Power Down (PD_WAKE
 * remains powered in Power Down, so the CMC2 DMA mask is always relevant).  Also
 * public so an application can apply the masks ahead of a bare __WFI() or inspect
 * the CMC registers; the function is idempotent.
 */
void POWER_ApplyWakeupSources(void)
{
    uint32_t allMasked[POWER_IRQ_WAKEUP_MASK_COUNT]; /* large enough for both arrays */
    uint32_t enableMask[POWER_IRQ_WAKEUP_MASK_COUNT];
    uint32_t i;

    /* CMC0: IRQ wakeup only. */
    for (i = 0U; i < POWER_IRQ_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i]  = 0xFFFFFFFFU;
        enableMask[i] = ~s_irqWakeupMask[i]; /* 1 = enable for wakeup */
    }
    POWERCON_DisableWakeupIRQ(SYSCON__POWERCON_CMC0_CTRL, allMasked);
    POWERCON_EnableWakeupIRQ(SYSCON__POWERCON_CMC0_CTRL, enableMask);
    /* CMC0 DMA - keep all-masked (no DMA wakeup sources on CPU domain). */
    for (i = 0U; i < POWER_DMA_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i] = 0xFFFFFFFFU;
    }
    POWERCON_DisableWakeupDMA(SYSCON__POWERCON_CMC0_CTRL, allMasked);

    /* CMC1: MAIN domain DMA wakeup only. */
    for (i = 0U; i < POWER_DMA_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i]  = 0xFFFFFFFFU;
        enableMask[i] = ~s_mainDmaWakeupMask[i];
    }
    POWERCON_DisableWakeupDMA(SYSCON__POWERCON_CMC1_CTRL, allMasked);
    POWERCON_EnableWakeupDMA(SYSCON__POWERCON_CMC1_CTRL, enableMask);
    /* CMC1 IRQ - keep all-masked. */
    for (i = 0U; i < POWER_IRQ_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i] = 0xFFFFFFFFU;
    }
    POWERCON_DisableWakeupIRQ(SYSCON__POWERCON_CMC1_CTRL, allMasked);

    /* CMC2: WAKE domain DMA wakeup only (PD_WAKE remains powered in Power Down). */
    for (i = 0U; i < POWER_DMA_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i]  = 0xFFFFFFFFU;
        enableMask[i] = ~s_wakeDmaWakeupMask[i];
    }
    POWERCON_DisableWakeupDMA(SYSCON__POWERCON_CMC2_CTRL, allMasked);
    POWERCON_EnableWakeupDMA(SYSCON__POWERCON_CMC2_CTRL, enableMask);
    /* CMC2 IRQ - keep all-masked. */
    for (i = 0U; i < POWER_IRQ_WAKEUP_MASK_COUNT; i++)
    {
        allMasked[i] = 0xFFFFFFFFU;
    }
    POWERCON_DisableWakeupIRQ(SYSCON__POWERCON_CMC2_CTRL, allMasked);
}

/*
 * Applies body bias ZBB (disables FBB/NBB before any standby entry).
 */
static void POWER_ApplyZeroBodyBias(void)
{
    pmu_body_bias_config_t bbCfg;
    PMU_GetDefaultBodyBiasConfig(&bbCfg);
    PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
    (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
}

/*
 * Establishes the FBBFull body-bias config used by every POWER_Enter*Run() FBB apply.
 * Called once from POWER_SetPolicy().
 *
 * `mode` is always set to FBBFull: which body-bias mode to request is a driver policy
 * decision, independent of whether the trim value is known.
 *
 * `nwellVolSel`/`pwellVolSel` are only overridden from the OTP fuse trim when
 * PMU_DRIVER_UPDATE_TRIM_VALUE (fsl_pmu.h) is enabled — the same macro that gates whether
 * PMU_ConfigBodyBias() (fsl_pmu.c) actually writes them to hardware, so this fuse read and
 * that hardware write can't drift out of sync. At its default (disabled, P-Well/N-Well
 * fuse not yet trimmed) this fuse-read block is skipped entirely and PMU_ConfigBodyBias()
 * leaves the NWELL_VOL/PWELL_VOL register bits at ROM's own trim.
 */
static void POWER_InitBodyBiasConfig(void)
{
    PMU_GetDefaultBodyBiasConfig(&s_fbbCfg);
    s_fbbCfg.mode = kPMU_BodyBiasFBBFull;

#if PMU_DRIVER_UPDATE_TRIM_VALUE
    /*
     * Reads OTP fuses ANA_CFG12 (PRIMARY) and ANA_CFG13 (BACKUP + TRIM_SEL) once via the
     * FSB shadow and caches the resolved Well-Bias trim codes in s_fbbTrim.
     *
     * Per-field selection order (independent for nwell / pwell / modeSel):
     *   1. If CFG13.TRIM_SEL == 1 and the BACKUP field is non-zero, use BACKUP.
     *   2. Otherwise, if the PRIMARY field is non-zero, use PRIMARY.
     *   3. Otherwise, leave s_fbbTrim at its initialized fallback (reference macros for
     *      nwell / pwell, zero for modeSel).
     *
     * Failure modes that leave s_fbbTrim at its initialized fallback (bring-up safety):
     *   - All fuses not yet valid (FSB_STATUS.VALL == 0) — skip both reads
     *   - FSB reports RD_ERR / RLD_ERR / FUSE_ERR / ADDR_ERR on the CFG12 read — skip both
     *   - FSB reports error on the CFG13 read only — CFG12 PRIMARY path still applies
     */
    const uint32_t errMask = FSB_FUSE_STAT_RD_ERR_MASK | FSB_FUSE_STAT_RLD_ERR_MASK | FSB_FUSE_STAT_FUSE_ERR_MASK |
                             FSB_FUSE_STAT_ADDR_ERR_MASK;

    /* Seed s_fbbCfg's well-voltage fields from the SW fallback so any early-return path
     * below leaves a valid config behind (overridden by the fuse read further down). */
    s_fbbCfg.nwellVolSel = s_fbbTrim.nwell;
    s_fbbCfg.pwellVolSel = s_fbbTrim.pwell;

    /* Skip the FSB access entirely if fuse shadow load has not completed;
     * s_fbbTrim / s_fbbCfg keep their initialized fallback values. */
    if ((MAIN__FSB->FSB_STATUS & FSB_FSB_STATUS_VALL_MASK) == 0U)
    {
        return;
    }

    /* Read PRIMARY (CFG12). Clear sticky FUSE_STAT bits, read, then check. */
    MAIN__FSB->FUSE_STAT = MAIN__FSB->FUSE_STAT;
    uint32_t primary     = MAIN__FSB->FUSE[POWER_BODYBIAS_FUSE_WORD_ANA_CFG12];
    if ((MAIN__FSB->FUSE_STAT & errMask) != 0U)
    {
        return;
    }

    uint8_t priNwell = (uint8_t)((primary & POWER_ANA_CFG_NWELL_V_SEL_MASK) >> POWER_ANA_CFG_NWELL_V_SEL_SHIFT);
    uint8_t priPwell = (uint8_t)((primary & POWER_ANA_CFG_PWELL_V_SEL_MASK) >> POWER_ANA_CFG_PWELL_V_SEL_SHIFT);
    uint8_t priMode  = (uint8_t)((primary & POWER_ANA_CFG_MODE_SEL_MASK) >> POWER_ANA_CFG_MODE_SEL_SHIFT);

    /* Read BACKUP (CFG13). If this read fails, keep PRIMARY-only path. */
    MAIN__FSB->FUSE_STAT = MAIN__FSB->FUSE_STAT;
    uint32_t backup      = MAIN__FSB->FUSE[POWER_BODYBIAS_FUSE_WORD_ANA_CFG13];
    bool backupValid     = ((MAIN__FSB->FUSE_STAT & errMask) == 0U);

    uint8_t bakNwell = 0U;
    uint8_t bakPwell = 0U;
    uint8_t bakMode  = 0U;
    bool useBackup   = false;
    if (backupValid)
    {
        useBackup = ((backup & POWER_ANA_CFG13_TRIM_SEL_MASK) != 0U);
        bakNwell  = (uint8_t)((backup & POWER_ANA_CFG_NWELL_V_SEL_MASK) >> POWER_ANA_CFG_NWELL_V_SEL_SHIFT);
        bakPwell  = (uint8_t)((backup & POWER_ANA_CFG_PWELL_V_SEL_MASK) >> POWER_ANA_CFG_PWELL_V_SEL_SHIFT);
        bakMode   = (uint8_t)((backup & POWER_ANA_CFG_MODE_SEL_MASK) >> POWER_ANA_CFG_MODE_SEL_SHIFT);
    }

    /* Per-field select: BACKUP if TRIM_SEL and BACKUP non-zero, else PRIMARY if non-zero,
     * else leave the initialized fallback (reference macros for nwell/pwell, 0 for mode). */
    uint8_t nwell = (useBackup && bakNwell != 0U) ? bakNwell : priNwell;
    uint8_t pwell = (useBackup && bakPwell != 0U) ? bakPwell : priPwell;
    uint8_t mode  = (useBackup && bakMode != 0U) ? bakMode : priMode;

    if (nwell != 0U)
    {
        s_fbbTrim.nwell = nwell;
    }
    if (pwell != 0U)
    {
        s_fbbTrim.pwell = pwell;
    }
    s_fbbTrim.modeSel = mode;

    /* Reflect the resolved trim into the pre-built FBB config so POWER_Enter*Run()
     * FBB paths can hand s_fbbCfg to PMU_ConfigBodyBias directly. */
    s_fbbCfg.nwellVolSel = s_fbbTrim.nwell;
    s_fbbCfg.pwellVolSel = s_fbbTrim.pwell;
#endif /* PMU_DRIVER_UPDATE_TRIM_VALUE */
}

/*
 * Clears PDCON sleep-event flags before entering a low-power mode so stale
 * PDSEF state from a previous transition cannot be mistaken for this entry.
 * RESETCON sticky reset status is intentionally left to the example/application.
 */
static void POWER_ClearPdsef(void)
{
    for (uint8_t domain = 0U; domain < POWER_PDCON_DOMAIN_COUNT; domain++)
    {
        (void)PDCON_GetAndClearEvent(SYSCON__PDCON, domain, true);
    }
}

/*
 * Allow the low-power sequence to power down MAIN-domain TCM by clearing the
 * GPR_COLD_0 force-alive override. Other GPR_COLD_0 bits are application owned
 * and must be preserved.
 */
static void POWER_ClearMainTcmForceAlive(void)
{
    uint32_t gprCold0 = POWERCON_GetColdGPR(SYSCON__POWERCON_SOC_CTRL, 0U);
    gprCold0 &= ~POWER_GPR_COLD0_MAIN_TCM_FORCE_ALIVE_MASK;
    POWERCON_SetColdGPR(SYSCON__POWERCON_SOC_CTRL, 0U, gprCold0);
}

/*
 * Switches every SW-controllable power domain from software to hardware trigger.
 * Used before every standby entry so CMC/SSC drives the standby sequence rather
 * than software.
 */
static inline void POWER_ForceAllDomainsToHwTrigger(void)
{
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_swPowerDomains); i++)
    {
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_swPowerDomains[i], false);
    }
}

/*
 * Configures MEMCON sleep-mode power state for a single memory identifier.
 * Convenience wrapper for the common 1-block case (OCRAM per-block, LLC, Audio, WakeSram)
 * that avoids the 1-element array boilerplate of POWER_SetMemSlicesSleepMode().
 */
static void POWER_SetMemBlockSleepMode(power_memory_t mem, memcon_power_mode_t mode)
{
    uint8_t sliceIdx = (uint8_t)((uint32_t)mem >> 8U);
    uint8_t blockIdx = (uint8_t)((uint32_t)mem & 0xFFU);
    MEMCON_SLICE_SetSleepBlockMode(s_memconSliceBases[sliceIdx], blockIdx, mode);
}

/*
 * Configures MEMCON sleep-mode power state for a list of memory identifiers that share
 * the same mode. Use POWER_SetMemBlockSleepMode() for the 1-block case.
 */
static void POWER_SetMemSlicesSleepMode(const power_memory_t *mems, uint32_t count, memcon_power_mode_t mode)
{
    for (uint32_t i = 0U; i < count; i++)
    {
        uint8_t sliceIdx = (uint8_t)((uint32_t)mems[i] >> 8U);
        uint8_t blockIdx = (uint8_t)((uint32_t)mems[i] & 0xFFU);
        MEMCON_SLICE_SetSleepBlockMode(s_memconSliceBases[sliceIdx], blockIdx, mode);
    }
}

/*
 * Standby/run-mode helpers used by every POWER_Enter*() path.
 */
/*!
 * brief Perform the CSSI/ELS LP handshake before standby entry.
 *
 * When bypass is disabled (production mode), this function:
 *   1. Sends an LP permission request to CSSI firmware via MU.
 *   2. Waits for CSSI firmware to respond allow/deny via MU reply.
 *   3. If allowed, asserts MAIN__MODCON ELS_LP_HDSK.ELS_LP_REQ to notify
 *      the ELS hardware block that LP entry is imminent.
 *
 * Communication with CSSI uses the Messaging Unit (MU).  The exact MU
 * message protocol will be defined when CSSI firmware is ready.
 *
 * Returns true if LP entry is allowed (or bypass is active),
 * false if CSSI denied the LP request.
 */
static bool POWER_RequestCssiLpEntry(void)
{
    if (s_cssiBypass)
    {
        /*
         * TEST ONLY: CSSI handshake bypassed.
         * CSSI firmware is not yet available for this bring-up phase.
         * Remove this bypass before production validation - call
         * POWER_SetCssiLpHandshakeBypass(false) when CSSI firmware is ready.
         */
        SYSCON__POWERCON_CMC0_CTRL->NON_IRQ_CS &= ~POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK;
        SYSCON__POWERCON_CMC1_CTRL->NON_IRQ_CS &= ~POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK;
        SYSCON__POWERCON_CMC2_CTRL->NON_IRQ_CS &= ~POWERCON_CMC_CTRL_NON_IRQ_CS_CSSI_EN_MASK;
        return true;
    }

    /*
     * Production path - CSSI firmware required.
     *
     * Step 1: Send LP request to CSSI via MU and wait for allow/deny response.
     *         Communication protocol (message codes and MU channel assignment)
     *         will be defined when CSSI firmware is available.
     *         TODO: implement MU send + receive when CSSI firmware is ready.
     *
     * Step 2: If CSSI allows LP entry, assert ELS_LP_REQ via MAIN__MODCON
     *         ELS_LP_HDSK register (IP[53].CFG[3], bit 16) to notify the ELS
     *         hardware block.  CSSI then asserts allow_lp to POWERCON.
     *
     * Step 3: If CSSI denies, return false - the caller must not issue WFI.
     */

    /* Placeholder: always allow until MU protocol is finalized. */
    /* TODO: replace with actual MU send/receive and MODCON write. */
    MAIN__MODCON->IP[53U].CFG[3U] |= MODCON_CFG_ELS_LP_REQ_MASK;

    return true; /* TODO: return false if CSSI MU response is deny. */
}

/*!
 * brief Apply the active-mode VDD_CORE level by programming the DCDC.
 *
 * The active-mode core voltage is owned by the DCDC BUCK_VDDCORE_VOUT_ADJ register, not by
 * PMUCFG_ACTIVE.coreLvl. Writing coreLvl alone does not move the rail; this function performs
 * the effective change via PMU_ConfigDcdc(). The run-mode DCDC config uses PWM mode with the
 * output-voltage monitor disabled (bring-up); the PWM loop compensation programmed at
 * POWER_SetPolicy() is left untouched. Callers order this relative to the clock callback:
 * raise voltage before speeding the core up, lower voltage only after the core is slowed.
 *
 * param voutAdj VOUT_ADJ code (POWER_PMUCFG_CORELEVEL_090V for HP, _080V for NP/LP).
 */
static void POWER_ApplyRunCoreVoltage(uint8_t voutAdj)
{
    if ((s_extRegHooks != NULL) && (s_extRegHooks->setCoreVoltage != NULL))
    {
        /* Board-registered external regulator (e.g. a PMIC) supplies VDD_CORE; the on-chip DCDC
         * is not touched. The hook returns status_t so an I2C (or other) failure is observable;
         * this function stays void (see REQ-002's noted limitation), so assert is the only
         * failure signal available here. */
        assert(s_extRegHooks->setCoreVoltage(voutAdj) == kStatus_Success);
    }
    else
    {
        pmu_dcdc_config_t dcdcConfig = {
            .mode                 = kPMU_DcdcModePWM,
            .voutAdj              = voutAdj,
            .voutFineAdj          = 0U,
            .ovlVthAdj            = 0U,
            .vsensorVoutAdjEn     = false,
            .bypassEn             = false,
            .ovlPdEn              = false,
            .sensorEnable         = false, /* DCDC output monitor off during bring-up ([hw-defer]). */
            .irqOnVmaxError       = false,
            .irqOnVminError       = false,
            .irqOnClkLost         = false,
            .irqOnUvlo            = false,
            .irqOnOclWarn         = false,
            .warmResetOnVmaxError = false,
            .warmResetOnVminError = false,
            .warmResetOnClkLost   = false,
            .warmResetOnUvlo      = false,
            .warmResetOnOclWarn   = false,
            .coldResetOnVmaxError = false,
            .coldResetOnVminError = false,
            .coldResetOnClkLost   = false,
            .coldResetOnUvlo      = false,
            .coldResetOnOclWarn   = false,
        };
        PMU_ConfigDcdc(SYSCON__PMU, &dcdcConfig);
    }
}

static status_t POWER_StandbyPrologue(void)
{
    if (!POWER_RequestCssiLpEntry())
    {
        return kStatus_Fail;
    }
    POWER_ClearPdsef();
    POWER_ClearMainTcmForceAlive();
    POWER_ApplyZeroBodyBias();
    return kStatus_Success;
}

static inline void POWER_ExecuteWfi(void)
{
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();
}

static inline void POWER_RestoreActiveXmcMask(void)
{
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x07U);
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);
}

static inline uint32_t POWER_BuildPmucfgStbyWord(uint32_t pmuMode,
                                                 pmu_dcdc_mode_t dcdcMode,
                                                 uint32_t coreLevel,
                                                 pmu_ldo_mode_t ldo0V8Mode,
                                                 pmu_ldo_mode_t ldo1V8Mode,
                                                 uint32_t ldoVdda1V8Mode,
                                                 bool hqref,
                                                 uint8_t sensorMask)
{
    power_pmu_state_t pmucfgStby = {0};
    pmucfgStby.pmuMode           = pmuMode;
    pmucfgStby.dcdcMode          = (dcdcMode == kPMU_DcdcModePWM) ? 1U : 0U;
    pmucfgStby.coreLvl           = coreLevel;
    pmucfgStby.ldo0V8Mode        = (uint32_t)ldo0V8Mode;
    pmucfgStby.ldo1V8Mode        = (uint32_t)ldo1V8Mode;
    pmucfgStby.ldoVdda1V8Mode    = ldoVdda1V8Mode;
    pmucfgStby.hqref             = hqref ? 1U : 0U;
    pmucfgStby.sensorTemp        = (sensorMask >> 0U) & 1U;
    pmucfgStby.sensor0V8         = (sensorMask >> 1U) & 1U;
    pmucfgStby.sensor1V8         = (sensorMask >> 2U) & 1U;
    pmucfgStby.sensorVdda        = (sensorMask >> 3U) & 1U;
    pmucfgStby.sensorCore        = (sensorMask >> 4U) & 1U;
    pmucfgStby.sensorPmu         = (sensorMask >> 5U) & 1U;
    return pmucfgStby.word;
}

static inline void POWER_ConfigureAllDomainSleepEvents(
    pdcon_event_t cpu, pdcon_event_t npu, pdcon_event_t comm, pdcon_event_t media, pdcon_event_t main)
{
    const pdcon_event_t events[] = {cpu, npu, comm, media};
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_swPowerDomains); i++)
    {
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_swPowerDomains[i], events[i]);
    }
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, main);
}

static inline void POWER_ApplyRunModePmuState(uint32_t pmuMode, uint32_t coreLvl)
{
    POWER_ApplyRunCoreVoltage((uint8_t)coreLvl);
    power_pmu_state_t pmuState;
    pmuState.word     = SYSCON__POWERCON_SOC_CTRL->PMUCFG_ACTIVE;
    pmuState.pmuMode  = pmuMode;
    pmuState.dcdcMode = 1U;
    pmuState.coreLvl  = coreLvl;
    POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
    POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
    while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
    {
    }
}

static inline void POWER_ApplyRunModeBodyBias(bool fbb)
{
    if (fbb)
    {
        PMU_ConfigBodyBias(SYSCON__PMU, &s_fbbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
    }
    else
    {
        POWER_ApplyZeroBodyBias();
    }
}

/*
 * Applies a single wakeup-source update to the SW shadow masks.
 *
 * Decodes the opaque power_wakeup_source_t encoding and applies enable / disable
 * to the correct CMC shadow array (IRQ / MAIN DMA / WAKE DMA). Inverted polarity:
 * enable = clear the bit; disable = set the bit (matches hardware register).
 *
 * bits[31:28] = 0x0 -> IRQ (CMC0),     index = bits[8:0] (0-383)
 * bits[31:28] = 0x1 -> MAIN DMA (CMC1), index = bits[5:0] (0-63)
 * bits[31:28] = 0x2 -> WAKE DMA (CMC2), index = bits[5:0] (0-63)
 */
static inline void POWER_UpdateWakeupMask(power_wakeup_source_t source, bool enable)
{
    uint32_t type      = ((uint32_t)source >> 28U) & 0xFU;
    uint32_t index     = (uint32_t)source & 0x1FFU;
    uint32_t *mask     = NULL;
    uint32_t wordCount = 0U;

    switch (type)
    {
        case 0x0U: /* IRQ -> CMC0 (9-bit index) */
            mask      = s_irqWakeupMask;
            wordCount = POWER_IRQ_WAKEUP_MASK_COUNT;
            break;
        case 0x1U: /* MAIN domain DMA -> CMC1 (6-bit index) */
            index     = (uint32_t)source & 0x3FU;
            mask      = s_mainDmaWakeupMask;
            wordCount = POWER_DMA_WAKEUP_MASK_COUNT;
            break;
        case 0x2U: /* WAKE domain DMA -> CMC2 (6-bit index) */
            index     = (uint32_t)source & 0x3FU;
            mask      = s_wakeDmaWakeupMask;
            wordCount = POWER_DMA_WAKEUP_MASK_COUNT;
            break;
        default:
            return; /* Unknown source type - no action. */
    }

    if (index >= (wordCount * 32U))
    {
        return;
    }

    uint32_t bit = 1UL << (index % 32U);
    if (enable)
    {
        mask[index / 32U] &= ~bit;
    }
    else
    {
        mask[index / 32U] |= bit;
    }
}

/*
 * Media MIPI CSI/DSI PHY 0.8 V supply, controlled by WAKE_MODCON MIPI_0V8_CFG
 * (PWR_EN bit 0: power switch; DATA_EN bit 1: data isolation).
 * The PHY must never be powered while PD_MEDIA is unpowered, and must be isolated
 * before the domain loses power.
 */
/*
 * Powers the WAKE_MIPI_0V8 PHY on or off with the correct isolation sequence.
 *   off: isolate first (DATA_EN=0), then drop PHY supply (PWR_EN=0).
 *   on : ensure fully isolated/off, raise PHY supply (PWR_EN=1), then de-isolate (DATA_EN=1).
 */
static inline void POWER_MediaMipiPhySetPower(bool on)
{
    uint32_t cfg = MODCON_GetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U);

    if (on)
    {
        cfg &= ~(MODCON_CFG_DATA_EN_MASK | MODCON_CFG_PWR_EN_MASK);
        MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
        cfg |= MODCON_CFG_PWR_EN_MASK;
        MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
        cfg |= MODCON_CFG_DATA_EN_MASK;
        MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
    }
    else
    {
        cfg &= ~MODCON_CFG_DATA_EN_MASK;
        MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
        cfg &= ~MODCON_CFG_PWR_EN_MASK;
        MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
    }
}

static inline void POWER_MediaMipiPhyPowerOff(void)
{
    POWER_MediaMipiPhySetPower(false);
}
static inline void POWER_MediaMipiPhyPowerOn(void)
{
    POWER_MediaMipiPhySetPower(true);
}

/*!
 * @brief Power down the VBAT retention SRAM (Deep Power Down 2, no retention).
 *
 * VBAT__SRAM CTRL PWR_MODE [5:2] must not step ACTIVE->SHUTDOWN directly - the RM
 * requires the INTERMEDIATE state in between - so step ACTIVE(6) -> INTERMEDIATE(2)
 * -> SHUTDOWN(0).  For Deep Power Down 1 (retain) the SRAM is left ACTIVE and held
 * by the always-on VBAT domain (VDD_PMU stays on), so this is not called.
 * [hw-defer] pending silicon confirmation of the VBAT SRAM power sequence.
 */
static void POWER_ShutdownVbatSram(void)
{
    uint32_t ctrl    = VBAT__SRAM->CTRL & ~(uint32_t)SRAM_CTRL_PWR_MODE_MASK;
    VBAT__SRAM->CTRL = ctrl | SRAM_CTRL_PWR_MODE(2U); /* INTERMEDIATE (INT) */
    VBAT__SRAM->CTRL = 0UL;                           /* SHUTDOWN (SD = 0)  */
}

/*******************************************************************************
 * Public API
 ******************************************************************************/

/*!
 * brief Fills power_policy_config_t with hardware reset defaults.
 *
 * All CMC and SSC steps set to Handshake mode; CSSI enabled and unlocked;
 * handshakeRouting set to NULL (POWER_SetPolicy will apply POR-default routing).
 */
void POWER_GetDefaultPolicyConfig(power_policy_config_t *config)
{
    assert(config != NULL);

    /* CMC/SSC step modes: hardware reset default is Handshake for all steps.
     * countValue reset = 0 (only relevant when mode = kPOWER_StepModeCount). */
    const power_step_config_t kStepDefault = {
        .sleepMode  = kPOWER_StepModeHandshake,
        .wakeupMode = kPOWER_StepModeHandshake,
        .countValue = 0U,
    };
    const power_cmc_step_config_t kCmcStepDefault = {
        .busMasterLpcg = kStepDefault,
        .busSlaveLpcg  = kStepDefault,
        .rootClockGate = kStepDefault,
        .clockSource   = kStepDefault,
        .powerDomain   = kStepDefault,
    };
    config->cmcCpu  = kCmcStepDefault;
    config->cmcMain = kCmcStepDefault;
    config->cmcWake = kCmcStepDefault;
    config->sscPmu  = kStepDefault;
    config->sscPmic = kStepDefault;

    /* handshakeRouting == NULL: POWER_SetPolicy will apply POR-default HSK_SEL and HSKCTRL. */
    config->handshakeRouting = NULL;
}

/*!
 * brief Fill power_handshake_routing_config_t with POR-default routing values.
 */
void POWER_GetDefaultHandshakeRoutingConfig(power_handshake_routing_config_t *config)
{
    assert(config != NULL);

    config->rcgcfgHskSel   = 0x77777777UL;
    config->csrccfgHskSel  = 0x77777777UL;
    config->csrccfgHskSel1 = 0x7UL;
    for (uint8_t i = 0U; i < 6U; i++)
    {
        config->domainHsk[i] = kPDCON_HandshakeAll;
    }
}

/*!
 * brief Apply or override the SoC handshake routing configuration.
 */
void POWER_SetHandshakeRouting(const power_handshake_routing_config_t *config)
{
    assert(config != NULL);

    powercon_topology_config_t pcTopo = {
        .rcgcfgHskSel   = config->rcgcfgHskSel,
        .csrccfgHskSel  = config->csrccfgHskSel,
        .csrccfgHskSel1 = config->csrccfgHskSel1,
    };
    POWERCON_SetTopologyConfig(SYSCON__POWERCON_SOC_CTRL, &pcTopo);

    for (uint8_t i = 0U; i < 6U; i++)
    {
        PDCON_SetHandshake(SYSCON__PDCON, i, config->domainHsk[i]);
    }
}

/*!
 * brief One-time hardware baseline setup: POWERCON/PDCON function clocks, body-bias trim,
 *       standby gating baseline, active-mode clock sources, NPU/Media/Comm domain power-up,
 *       and MEMCON slice init. Call once at boot, before POWER_SetPolicy(). Not safe to call
 *       more than once (re-runs the one-time PDCON/MEMCON bring-up).
 */
void POWER_Init(void)
{
    /* 1. Enable POWERCON function clock FIRST (must precede all POWERCON accesses). */
    POWERCON_EnableFunctionClock(SYSCON__POWERCON_SOC_CTRL);

    /* 2. Enable PDCON function clock. */
    PDCON_EnableFunctionClock(SYSCON__PDCON, true);

    /* Establish the FBBFull body-bias config once here; FBB apply paths read from s_fbbCfg.
     * The OTP trim override inside is gated by PMU_DRIVER_UPDATE_TRIM_VALUE (fsl_pmu.h). */
    POWER_InitBodyBiasConfig();

    /* 3. Standby gating baseline: XMC_STBY_MASK = 0x07 disables all CMC internal
     *    standby flows while active, so a bare application WFI stays a simple
     *    core WFI. Each POWER_Enter*() programs the mode-specific mask before
     *    its WFI. TRIGGER_SS is set explicitly on all CMCs (silicon default
     *    made deterministic); Sleep entry clears it on CMC0. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x07U);
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 4. Configure PDCON trigger mode for the four SW-controllable domains.
     *    Default: HW trigger enabled (CMC drives standby transitions).
     *             SW trigger disabled (enabled transiently in POWER_SetDomainRunMode). */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_swPowerDomains); i++)
    {
        PDCON_EnableDomainHwTrigger(SYSCON__PDCON, s_swPowerDomains[i], true);
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_swPowerDomains[i], false);
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_swPowerDomains[i], kPDCON_EventNoneOrActive);
    }
    /* PD_MAIN (domain 1) is not SW-triggerable and not in s_swPowerDomains, but it DOES have a
     * PDSLPCFG field. Its low-power event is driver-fixed: NoneOrActive everywhere except
     * Power Down / Deep Power Down (set to PowerOff in those entry paths). Establish the
     * active-mode default here. */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventNoneOrActive);

    /* 5. Enable active-mode clock sources. Moved here from POWER_EnterHpRun/NormalRun/LpRun
     *     (was duplicated identically in all three) -- those functions are voltage/frequency
     *     only now. */
    for (uint8_t i = 0U; i <= 8U; i++)
    {
        POWERCON_EnableClockSourceInActiveMode(SYSCON__POWERCON_SOC_CTRL, i);
    }

    /* 6. Bring the NPU/Media/Comm domains active, if not already (idempotent -- a domain
     *     already at kPDCON_EventNoneOrActive is not re-triggered). Moved here from
     *     POWER_EnterHpRun/NormalRun/LpRun for the same reason as step 9.
     *
     *     Must come BEFORE step 11 (MEMCON slice SW-trigger): each MEMCON slice's memory
     *     macros sit inside a specific power domain (S6/S7 -> NPU, S9 -> Media, S10/S11 ->
     *     Comm), so touching those slices' MDCTRL/RUNCFG or issuing a SWTRG before the
     *     hosting domain is active either wedges the MEMCON SWTRG self-clear busy-wait or
     *     leaves stale state that only surfaces later as a PDCON_SoftwareTrigger() hang on
     *     Deep Power Down entry/exit (no timeout in this build). */
    static const power_domain_t kActiveDomains[] = {kPOWER_DomainNpu, kPOWER_DomainMedia, kPOWER_DomainComm};
    for (uint8_t i = 0U; i < ARRAY_SIZE(kActiveDomains); i++)
    {
        if (PDCON_GetDomainState(SYSCON__PDCON, (uint8_t)kActiveDomains[i]) != kPDCON_EventNoneOrActive)
        {
            (void)POWER_SetDomainRunMode(kActiveDomains[i], kPDCON_EventNoneOrActive);
        }
    }

    /* 7. Enable MEMCON function clock; set all slices to HW-trigger mode with all
     *    blocks in NormalPower (Active) active state.  SLPCFG (standby registers)
     *    are NOT written here - they are configured only at standby entry.
     *    Order-dependent on step 10 (see step 10 comment). */
    MEMCON_GLOBAL_EnableFunctionClock(SYSCON__MEMCON_GLOBAL, true);
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_memconSliceBases); i++)
    {
        /* Write RUNCFG = Active for every block (hardware reset default made explicit;
         * hardware applies this on wakeup from standby - no SW restore needed). */
        MEMCON_SLICE_SetTriggerMode(s_memconSliceBases[i], kMEMCON_TriggerSoftware);
        for (uint8_t blk = 0U; blk < POWER_MEMCON_MAX_BLOCKS_PER_SLICE; blk++)
        {
            MEMCON_SLICE_SetActiveBlockMode(s_memconSliceBases[i], blk, kMEMCON_PowerModeActive);
        }
        MEMCON_SLICE_SoftwareTrigger(s_memconSliceBases[i]);
        /* HW-trigger mode: CMC/SSC drives standby transitions. */
        MEMCON_SLICE_SetTriggerMode(s_memconSliceBases[i], kMEMCON_TriggerHardware);
    }

    /* 8. Initialise SW wakeup state: mask all sources. */
    (void)memset(s_irqWakeupMask, 0xFF, sizeof(s_irqWakeupMask));
    (void)memset(s_mainDmaWakeupMask, 0xFF, sizeof(s_mainDmaWakeupMask));
    (void)memset(s_wakeDmaWakeupMask, 0xFF, sizeof(s_wakeDmaWakeupMask));
}

/*!
 * brief Applies the power management policy (active/low-power baseline, NPU/Media/Comm
 *       domain state, active-mode clock sources). Safe to call more than once.
 */
void POWER_SetPolicy(const power_policy_config_t *config)
{
    assert(config != NULL);

    /* 1. Apply SoC handshake routing (HSK_SEL routing and PDCON HSKCTRL).
     *    NULL -> apply POR-default values; non-NULL -> apply caller-supplied config. */
    if (config->handshakeRouting != NULL)
    {
        POWER_SetHandshakeRouting(config->handshakeRouting);
    }

    /* 2. Apply per-CMC step-mode configuration. */
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC0_CTRL, &config->cmcCpu);
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC1_CTRL, &config->cmcMain);
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC2_CTRL, &config->cmcWake);

    /* 3. Build SSC step-mode bitmasks. */
    uint8_t sscSleepMask                  = 0U;
    uint8_t sscWakeupMask                 = 0U;
    uint32_t sscCountValue                = 0U;
    const power_step_config_t *sscSteps[] = {&config->sscPmu, &config->sscPmic};
    for (uint8_t i = 0U; i < ARRAY_SIZE(sscSteps); i++)
    {
        if (sscSteps[i]->sleepMode == kPOWER_StepModeCount)
        {
            sscSleepMask |= (uint8_t)(1U << i);
            sscCountValue = sscSteps[i]->countValue;
        }
        if (sscSteps[i]->wakeupMode == kPOWER_StepModeCount)
        {
            sscWakeupMask |= (uint8_t)(1U << i);
            sscCountValue = sscSteps[i]->countValue;
        }
    }
    POWERCON_EnableSysSleepCtrlStepMode(SYSCON__POWERCON_SYS_SLEEP_CTRL, sscSleepMask, sscWakeupMask);

    if ((sscSleepMask | sscWakeupMask) != 0U)
    {
        /* In case of step-mode count being used, set the SSC count value. */
        POWERCON_SetSysSleepCtrlCountValue(SYSCON__POWERCON_SYS_SLEEP_CTRL, sscCountValue);
    }
}

void POWER_SetExtRegulatorHooks(const power_ext_regulator_hooks_t *hooks)
{
    s_extRegHooks = hooks;
}

/*!
 * brief Accumulates a wakeup source into SW state.
 *
 * Decodes the opaque power_wakeup_source_t encoding and clears the corresponding
 * bit (inverted polarity: clear = enable wakeup).
 */
void POWER_EnableWakeupSource(power_wakeup_source_t source)
{
    POWER_UpdateWakeupMask(source, true);
}

/*!
 * brief Removes a wakeup source from SW state.
 *
 * Sets the bit for the decoded source (inverted polarity: set = mask wakeup).
 */
void POWER_DisableWakeupSource(power_wakeup_source_t source)
{
    POWER_UpdateWakeupMask(source, false);
}

/*!
 * brief Masks all accumulated wakeup sources.
 *
 * Resets all three CMC shadow arrays to all-masked (0xFF = all sources masked).
 */
void POWER_ClearAllWakeupSources(void)
{
    (void)memset(s_irqWakeupMask, 0xFF, sizeof(s_irqWakeupMask));
    (void)memset(s_mainDmaWakeupMask, 0xFF, sizeof(s_mainDmaWakeupMask));
    (void)memset(s_wakeDmaWakeupMask, 0xFF, sizeof(s_wakeDmaWakeupMask));
}

/*!
 * brief Software-triggered power domain state change.
 */
status_t POWER_SetDomainRunMode(power_domain_t domain, pdcon_event_t event)
{
    status_t status;

    /* For PD_MEDIA, isolate and power off the MIPI PHY supply BEFORE the domain loses power. */
    if ((domain == kPOWER_DomainMedia) && (event == kPDCON_EventPowerOff))
    {
        POWER_MediaMipiPhyPowerOff();
    }

    /* SW trigger must be enabled before PDCON_SoftwareTrigger() will fire. */
    PDCON_EnableDomainSwTrigger(SYSCON__PDCON, (uint8_t)domain, true);

    status = PDCON_SetEventInActiveMode(SYSCON__PDCON, (uint8_t)domain, event);
    if (status != kStatus_Success)
    {
        /* Disable SW trigger before returning on error. */
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, (uint8_t)domain, false);
        return status;
    }

    status = PDCON_SoftwareTrigger(SYSCON__PDCON, (uint8_t)domain);

    /* Always disable SW trigger after attempt; HW trigger is the standby-safe default. */
    PDCON_EnableDomainSwTrigger(SYSCON__PDCON, (uint8_t)domain, false);

    /* For PD_MEDIA, restore the MIPI PHY supply AFTER the domain is powered on. */
    if ((domain == kPOWER_DomainMedia) && (event == kPDCON_EventNoneOrActive) && (status == kStatus_Success))
    {
        POWER_MediaMipiPhyPowerOn();
    }

    return status;
}

/*!
 * brief Set SRAM block active-mode power state and apply immediately.
 */
status_t POWER_SetMemoryRunMode(power_memory_t mem, memcon_power_mode_t mode)
{
    uint8_t sliceIdx = (uint8_t)((uint32_t)mem >> 8U);
    uint8_t blockIdx = (uint8_t)((uint32_t)mem & 0xFFU);

    /* Switch to SW trigger to apply the change immediately, then restore HW trigger
     * so CMC/SSC remains in control of standby transitions. */
    MEMCON_SLICE_SetTriggerMode(s_memconSliceBases[sliceIdx], kMEMCON_TriggerSoftware);
    MEMCON_SLICE_SetActiveBlockMode(s_memconSliceBases[sliceIdx], blockIdx, mode);
    MEMCON_SLICE_SoftwareTrigger(s_memconSliceBases[sliceIdx]);
    MEMCON_SLICE_SetTriggerMode(s_memconSliceBases[sliceIdx], kMEMCON_TriggerHardware);
    return kStatus_Success;
}

/*!
 * brief Enable a subsystem root clock during active mode.
 *
 * Clears the bit in RCGCFG_ACTIVE (active-low gate: 0b=enables, 1b=disables root clock).
 * Direct register write - no P-Channel trigger required.
 */
void POWER_EnableRunRootClock(power_root_clock_t ss)
{
    POWERCON_EnableRootClockInActiveMode(SYSCON__POWERCON_SOC_CTRL, (uint8_t)ss);
}

/*!
 * brief Disable a subsystem root clock during active mode.
 *
 * Sets the bit in RCGCFG_ACTIVE (active-low gate: 0b=enables, 1b=disables root clock).
 * Direct register write - no P-Channel trigger required.
 */
void POWER_DisableRunRootClock(power_root_clock_t ss)
{
    POWERCON_DisableRootClockInActiveMode(SYSCON__POWERCON_SOC_CTRL, (uint8_t)ss);
}

/*!
 * brief Enable a clock source during active mode via POWERCON P-Channel.
 *
 * Sets the bit in CSRCCFG_ACTIVE (1b=enables, 0b=disables clock source).
 * Requires POWERCON SOC P-Channel update (trigger + poll for completion).
 */
void POWER_EnableRunClockSource(power_clock_source_t src)
{
    POWERCON_EnableClockSourceInActiveMode(SYSCON__POWERCON_SOC_CTRL, (uint8_t)src);
    /* CSRCCFG_ACTIVE is staged; the P-Channel trigger commits it to the PMU. The same
       handshake re-applies the unchanged PMUCFG_ACTIVE, so PMU state is preserved. */
    POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
    while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
    {
    }
}

/*!
 * brief Disable a clock source during active mode via POWERCON P-Channel.
 *
 * Clears the bit in CSRCCFG_ACTIVE (1b=enables, 0b=disables clock source).
 * Caller MUST ensure no active consumer uses this source before calling.
 * Requires POWERCON SOC P-Channel update (trigger + poll for completion).
 */
void POWER_DisableRunClockSource(power_clock_source_t src)
{
    POWERCON_DisableClockSourceInActiveMode(SYSCON__POWERCON_SOC_CTRL, (uint8_t)src);
    /* CSRCCFG_ACTIVE is staged; the P-Channel trigger commits it to the PMU. The same
       handshake re-applies the unchanged PMUCFG_ACTIVE, so PMU state is preserved. */
    POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
    while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
    {
    }
}

void POWER_SetRunRegulatorsConfig(const power_run_regulators_config_t *config)
{
    assert(config != NULL);

    /* Configure each PMU regulator block via the PMU driver layer. */
    PMU_ConfigDcdc(SYSCON__PMU, &config->dcdc);
    PMU_ConfigLdoVdd0V8(SYSCON__PMU, &config->ldo0V8);
    PMU_ConfigLdoVdd1V8(SYSCON__PMU, &config->ldo1V8);
    PMU_ConfigLdoVdda1V8(SYSCON__PMU, &config->ldoVdda);
    PMU_ConfigVddPmu(SYSCON__PMU, &config->vddPmu);

    /* Assemble the PMUCFG_ACTIVE word: sensor enables, HQREF, mode selections, core level. */
    power_pmu_state_t pmucfgActive = {0};
    /* Voltage sensor enables: one bit per regulator rail. */
    pmucfgActive.sensorCore = config->dcdc.sensorEnable ? 1U : 0U;
    pmucfgActive.sensor0V8  = config->ldo0V8.sensorEnable ? 1U : 0U;
    pmucfgActive.sensor1V8  = config->ldo1V8.sensorEnable ? 1U : 0U;
    pmucfgActive.sensorVdda = config->ldoVdda.sensorEnable ? 1U : 0U;
    pmucfgActive.sensorPmu  = config->vddPmu.sensorEnable ? 1U : 0U;
    pmucfgActive.hqref      = 1U; /* High-quality reference always enabled in run modes. */
    /* DCDC operating mode: 1 = PWM, 0 = PFM. */
    pmucfgActive.dcdcMode = (config->dcdc.mode == kPMU_DcdcModePWM) ? 1U : 0U;
    /* LDO operating modes: HP=0, LP=1, bypass=2. */
    pmucfgActive.ldo0V8Mode     = (uint32_t)config->ldo0V8.mode;
    pmucfgActive.ldo1V8Mode     = (uint32_t)config->ldo1V8.mode;
    pmucfgActive.ldoVdda1V8Mode = (uint32_t)config->ldoVdda.mode;
    pmucfgActive.dcdcOffPmuRet  = 0U; /* Keep DCDC active during PMU retention. */
    pmucfgActive.coreLvl        = (uint32_t)config->dcdc.voutAdj & 0x1FU;
    /* Preserve current pmuMode (HP/LP run mode is not changed by this function). */
    {
        power_pmu_state_t curPmuState;
        curPmuState.word     = SYSCON__POWERCON_SOC_CTRL->PMUCFG_ACTIVE;
        pmucfgActive.pmuMode = curPmuState.pmuMode;
    }

    POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmucfgActive.word);
    POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
    while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
    {
    }
}

void POWER_EnableRunPmicStandbyRequest(bool enable)
{
    /* Assert or deassert the PMIC standby request in the active PMIC config register. */
    POWERCON_SetPmiccfgActive(SYSCON__POWERCON_SOC_CTRL, enable ? 1U : 0U);
}

/*!
 * brief Get the current active run mode (classified from the CPU core clock frequency).
 */
power_run_mode_t POWER_GetCurrentRunMode(void)
{
    uint32_t coreFreq = CLOCK_GetRootClockFreq(kCLOCK_Root_CMPT_cpu_clk);
    power_run_mode_t mode;

    if (coreFreq >= POWER_RUNMODE_HP_FREQ_THRESHOLD_HZ)
    {
        mode = kPOWER_RunModeHp;
    }
    else if (coreFreq >= POWER_RUNMODE_NP_FREQ_THRESHOLD_HZ)
    {
        mode = kPOWER_RunModeNormal;
    }
    else
    {
        mode = kPOWER_RunModeLp;
    }

    return mode;
}

/*!
 * brief Enters HP run mode (VDD_CORE=0.9 V, DCDC PWM, FBB).
 *
 * Determines ordering from the current run mode (detected via the CPU core frequency):
 * if currently LP (ZBB), voltage is raised first, then clockCb is called.
 * If currently FBB (HP/NP), an intermediate ZBB step is applied first (PMU spec §1.7),
 * then clockCb is called, then FBB is re-applied.
 *
 * VDD_CORE is an increase into HP, so the DCDC voltage is raised (PMU_ConfigDcdc) before the
 * clock callback speeds the core up, in both ordering branches.
 */
void POWER_EnterHpRun(power_clock_cb_t clockCb)
{
    bool fromLp = (POWER_GetCurrentRunMode() == kPOWER_RunModeLp);

    /* Increase into HP: raise the DCDC voltage before the core clock speeds up. */
    POWER_ApplyRunModePmuState(0U, POWER_PMUCFG_CORELEVEL_090V);

    /* Body bias: only switch when leaving LP (ZBB); HP/NP already share s_fbbCfg. */
    if (fromLp)
    {
        POWER_ApplyRunModeBodyBias(true);
    }

    if (clockCb != NULL)
    {
        clockCb();
    }
}

/*!
 * brief Enters Normal run mode (VDD_CORE=0.8 V, DCDC PWM, FBB).
 */
void POWER_EnterNormalRun(power_clock_cb_t clockCb)
{
    bool fromLp = (POWER_GetCurrentRunMode() == kPOWER_RunModeLp);

    if (fromLp)
    {
        /* LP -> NP: raise voltage (level unchanged, DCDC apply for consistency), switch to FBB,
         * then run clockCb. */
        POWER_ApplyRunModePmuState(0U, POWER_PMUCFG_CORELEVEL_080V);
        POWER_ApplyRunModeBodyBias(true);
        if (clockCb != NULL)
        {
            clockCb();
        }
    }
    else
    {
        /* HP/NP -> NP: body bias already FBB. Reduce clocks first, then lower voltage. */
        if (clockCb != NULL)
        {
            clockCb();
        }
        POWER_ApplyRunModePmuState(0U, POWER_PMUCFG_CORELEVEL_080V);
    }
}

/*!
 * brief Enters LP run mode (VDD_CORE=0.8 V, DCDC PWM, ZBB).
 */
void POWER_EnterLpRun(power_clock_cb_t clockCb)
{
    /* HP/NP -> LP: reduce clocks first, switch to ZBB, then lower voltage. */
    if (clockCb != NULL)
    {
        clockCb();
    }
    POWER_ApplyRunModeBodyBias(false);
    POWER_ApplyRunModePmuState(0U, POWER_PMUCFG_CORELEVEL_080V);
}

/*!
 * brief Unified run-mode entry: dispatches to POWER_EnterHpRun/NormalRun/LpRun.
 */
void POWER_EnterRunMode(power_run_mode_t runMode, power_clock_cb_t clockCb)
{
    switch (runMode)
    {
        case kPOWER_RunModeHp:
            POWER_EnterHpRun(clockCb);
            break;
        case kPOWER_RunModeNormal:
            POWER_EnterNormalRun(clockCb);
            break;
        case kPOWER_RunModeLp:
            POWER_EnterLpRun(clockCb);
            break;
        default:
            break;
    }
}

/*!
 * brief Set the CSSI/ELS LP handshake bypass flag.
 */
void POWER_SetCssiLpHandshakeBypass(bool bypass)
{
    s_cssiBypass = bypass;
}

/*!
 * brief Enters Sleep mode and returns on wakeup.
 */
status_t POWER_EnterSleep(const power_sleep_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_InvalidArgument;
    }

    /* 0. CSSI/ELS LP handshake - abort if CSSI denies LP entry. */
    if (!POWER_RequestCssiLpEntry())
    {
        return kStatus_Fail;
    }

    /* 1. Explicitly set every fsl_power-managed MEMCON block to Active for state hygiene.
     *
     *    Sleep does not physically transition the memories (SSC P-Channel is not triggered
     *    and the supply rails are unchanged), but MEMCON MEM_SLPCFG retains the value the
     *    previous Deep-Sleep / Power-Down entry wrote. Leaving those bits as Retention or
     *    PowerDown while resuming active operation makes the register state inconsistent
     *    with the physical memory state - a debugging trap. Writing Active here clears any
     *    stale entry-mode value from a previous cycle. */
    const power_memory_t allMems[] = POWER_ALL_MEMORY_SLICES;
    POWER_SetMemSlicesSleepMode(allMems, ARRAY_SIZE(allMems), kMEMCON_PowerModeActive);

    /* 2. Ensure all SW-controllable domains use HW trigger (CMC drives standby sequence). */
    POWER_ForceAllDomainsToHwTrigger();

    /* 3. Configure PDCON sleep events for each domain (PDSLPCFG standby registers). */
    POWER_ConfigureAllDomainSleepEvents(config->setCpuDomainEvent, config->setNpuDomainEvent,
                                        config->setCommDomainEvent, config->setMediaDomainEvent,
                                        kPDCON_EventNoneOrActive);

    /* 4. Build PMUCFG_STBY via helper. */
    uint32_t pmucfgStby = POWER_BuildPmucfgStbyWord(
        config->setPmuMode, config->setDcdcMode, config->setCoreLevel, config->setLdo0V8Mode, config->setLdo1V8Mode,
        config->setLdoVdda1V8Mode, config->enableHqref, config->enableSensors);

    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby  = POWER_BUILD_RCGCFG_STBY(config);
    socCfg.csrccfgStby = POWER_BUILD_CSRCCFG_STBY(config);
    socCfg.pmucfgStby  = pmucfgStby;
    socCfg.pmiccfgStby = 0U;
    POWERCON_SetSocStandbyConfig(SYSCON__POWERCON_SOC_CTRL, &socCfg);

    /* Sleep = CMC0-only internal standby flow, SSC not triggered:
     *  - XMC_STBY_MASK = 0x6: enable CMC0's flow, keep CMC1/CMC2 flows disabled.
     *  - CMC0 TRIGGER_SS = 0: CMC0's standby entry must not trigger the SSC. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x6U);
    POWERCON_DisableSystemSleepTrigger(SYSCON__POWERCON_CMC0_CTRL);

    /* 5. Apply accumulated wakeup sources. */
    POWER_ApplyWakeupSources();
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL |= (POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 6. Clear PDCON sleep event flags before arming WFI so stale flags cannot
     *    persist into the next LP entry, then arm and execute WFI. */
    POWER_ClearPdsef();
    //    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);
    POWER_ExecuteWfi();

    /* Restore the active-mode baseline so a later bare WFI stays a bare WFI. */
    POWER_RestoreActiveXmcMask();

    return kStatus_Success;
}

/*!
 * brief Enters Deep Sleep mode and returns on wakeup.
 */
status_t POWER_EnterDeepSleep(const power_deep_sleep_config_t *config)
{
    if (config == NULL)
    {
        return kStatus_InvalidArgument;
    }

    if (POWER_StandbyPrologue() != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* 1. Configure MEMCON SLPCFG.
     *
     *    Every fsl_power-managed memcon block is driven from `config`. Two blocks
     *    have hardware retention paths that make Active a valid choice in DS:
     *      - S0 B0 (WakeSram): WAKE_SS is always-on across Sleep/DS/PD, so Active
     *        is safe (and is the recommended default).
     *      - S2 B0 (OCRAM0 M0/1): first-class always-retained slot; Retention is
     *        the recommended default. Callers may set PowerDown, but this block
     *        holds the first 64 KB of OCRAM0 (commonly stack/heap) - the driver
     *        does not police the value.
     *    S2 B1-B7 and the other rows come from per-field config. */
    POWER_SetMemBlockSleepMode(kPOWER_Mem_WakeSram, config->setWakeSramMode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram01, config->setComputeSram01Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram23, config->setOcram0M23Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram4, config->setOcram0M4Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram5, config->setOcram0M5Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram6, config->setOcram1M0Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram7, config->setOcram1M1Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram8, config->setOcram2M0Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram9, config->setOcram2M1Mode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_LlcCacheBuffer, config->setLlcCacheMode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_Audio8Kb, config->setAudio8KbMode);
    /* Multi-block groups: one mode across every block in the group. */
    const power_memory_t cpuMems[]   = POWER_CPU_TCM_SLICES;
    const power_memory_t npuMems[]   = POWER_NPU_TCM_SLICES;
    const power_memory_t commMems[]  = POWER_COMM_TCM_SLICES;
    const power_memory_t mediaMems[] = POWER_MEDIA_TCM_SLICES;
    POWER_SetMemSlicesSleepMode(cpuMems, ARRAY_SIZE(cpuMems), config->setM85TcmMode);
    POWER_SetMemSlicesSleepMode(npuMems, ARRAY_SIZE(npuMems), config->setNpuTcmMode);
    POWER_SetMemSlicesSleepMode(commMems, ARRAY_SIZE(commMems), config->setCommTcmMode);
    POWER_SetMemSlicesSleepMode(mediaMems, ARRAY_SIZE(mediaMems), config->setMediaTcmMode);

    /* 2. Ensure HW trigger for all domains (CMC drives standby sequence). */
    POWER_ForceAllDomainsToHwTrigger();

    /* 3. Configure PDCON sleep events (PDSLPCFG standby registers only;
     *    PDRUNCFG active registers are NOT modified here). */
    POWER_ConfigureAllDomainSleepEvents(config->setCpuDomainEvent, config->setNpuDomainEvent,
                                        config->setCommDomainEvent, config->setMediaDomainEvent,
                                        kPDCON_EventNoneOrActive);

    /* 4. Build PMUCFG_STBY via helper. */
    uint32_t pmucfgStby = POWER_BuildPmucfgStbyWord(
        config->setPmuMode, config->setDcdcMode, config->setCoreLevel, config->setLdo0V8Mode, config->setLdo1V8Mode,
        config->setLdoVdda1V8Mode, config->enableHqref, config->enableSensors);

    /* 5. Configure SoC standby for Deep Sleep. */
    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby  = POWER_BUILD_RCGCFG_STBY(config) | POWER_RCGCFG_STBY_DEEPSLEEP_REQUIRED;
    socCfg.csrccfgStby = POWER_BUILD_CSRCCFG_STBY(config);
    socCfg.pmucfgStby  = pmucfgStby;
    socCfg.pmiccfgStby = 0U;
    if ((s_extRegHooks != NULL) && (s_extRegHooks->setStandbyTarget != NULL))
    {
        /* Board hook selects the external regulator's STANDBY profile via I2C
         * and reports the PMICCFG_STBY.PMIC_MODE code fsl_power forwards to hardware below. */
        if (s_extRegHooks->setStandbyTarget(kPOWER_DeepSleep, &socCfg.pmiccfgStby) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    }
    POWERCON_SetSocStandbyConfig(SYSCON__POWERCON_SOC_CTRL, &socCfg);
    /* Deep Sleep: enable all CMC internal standby flows (XMC_STBY_MASK = 0) and
     * have every CMC trigger the SSC (explicit; also repairs the CMC0 TRIGGER_SS
     * clear left by a previous POWER_EnterSleep). */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x00U);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC0_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC1_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC2_CTRL);

    /* 6. Apply accumulated wakeup sources. */
    POWER_ApplyWakeupSources();
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL |= (POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 6b. If PD_MEDIA will be powered off in standby, isolate and power off the MIPI PHY
     *     supply before WFI so it is never powered while the domain is unpowered. */
    bool restoreMediaMipiPhy = (config->setMediaDomainEvent == kPDCON_EventPowerOff);
    if (restoreMediaMipiPhy)
    {
        POWER_MediaMipiPhyPowerOff();
    }

    /* 7. Execute WFI. WFI is the hardware-triggered low-power entry request. */
    POWER_ExecuteWfi();

    /* 8. On return: hardware has already applied PDRUNCFG (PDCON active registers)
     *    and MEMCON RUNCFG.
     *    PLL clock outputs: hardware only re-enables the DIV4 output of MAINPLL
     *    and SYSPLL on wakeup.  All other outputs (DIV5/8/10/20, PFD0/1/2) remain
     *    gated.  The caller must re-enable any required non-DIV4 PLL outputs after
     *    this function returns.  COREPLL frequency is preserved without a reset;
     *    if the CPU was running from COREPLL before entry no clock restoration
     *    is needed for the core. */
    /* Restore the active-mode baseline so a later bare WFI stays a bare WFI. */
    POWER_RestoreActiveXmcMask();

    /* 8b. Deep Sleep wake resumes in place (no reset) and hardware restores PD_MEDIA,
     *     so restore the MIPI PHY supply if it was powered off on entry. */
    if (restoreMediaMipiPhy)
    {
        POWER_MediaMipiPhyPowerOn();
    }

    return kStatus_Success;
}

/*!
 * brief Enters Power Down mode.  Does not return; wakeup triggers PoR.
 */
status_t POWER_EnterPowerDown(const power_down_config_t *config)
{
    assert(config != NULL);

    if (POWER_StandbyPrologue() != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* 1. Configure MEMCON for Power Down.
     *
     *    In Power Down the DCDC that supplies VDD_CORE is off. Only two blocks
     *    have retention supplies that survive PD, both driven from `config`:
     *      - S0 B0 (WakeSram):    WAKE_SS is always-on so contents survive
     *                             regardless of the SLPCFG bit; caller selects
     *                             Retention or PowerDown (Active is not offered
     *                             as a valid caller choice - see the field
     *                             docstring in power_down_config_t).
     *      - S2 B0 (OCRAM0 M0/1): hardware retention supply routes the array to
     *                             an always-on rail when MEM_SLPCFG=Retention.
     *                             Select Retention to preserve contents across
     *                             the PoR wakeup boot; PowerDown to drop them.
     *    Every other memcon block loses its supply regardless of SLPCFG value,
     *    so those writes would be no-ops - not issued. */
    POWER_SetMemBlockSleepMode(kPOWER_Mem_WakeSram, config->setWakeSramMode);
    POWER_SetMemBlockSleepMode(kPOWER_Mem_ComputeSram01, config->setComputeSram01Mode);

    /* 2. Ensure HW trigger; configure all domains to power-off in standby. */
    POWER_ForceAllDomainsToHwTrigger();
    POWER_ConfigureAllDomainSleepEvents(kPDCON_EventPowerOff, kPDCON_EventPowerOff, kPDCON_EventPowerOff,
                                        kPDCON_EventPowerOff, kPDCON_EventPowerOff);

    /* 3. Configure SoC standby: retain the clocks required by the Power Down reset flow.
     * MAIN domain is powered off directly in Power Down, and CGU is inside MAIN domain,
     * so the driver does not need to micro-manage individual CGU clock-source state here.
     * Keeping all clock sources marked enabled reduces handshake latency during the reset,
     * OTP trim-load, and CGU restore sequence after wakeup. */
    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby  = POWER_RCGCFG_STBY_POWERDOWN_REQUIRED;
    socCfg.csrccfgStby = POWER_CSRCCFG_STBY_ALL_ON;
    socCfg.pmucfgStby  = POWER_PMU_STATE_PD_WORD;
    socCfg.pmiccfgStby = 0U;
    if ((s_extRegHooks != NULL) && (s_extRegHooks->setStandbyTarget != NULL))
    {
        /* Board hook selects the external regulator's STANDBY profile via I2C
         * (the same profile Deep Sleep selects — Power Down is distinguished from Deep Sleep by
         * the board's I2C enableMode rewrite inside the hook, not by the profile) and
         * reports the PMICCFG_STBY.PMIC_MODE code fsl_power forwards to hardware below. */
        if (s_extRegHooks->setStandbyTarget(kPOWER_PowerDown, &socCfg.pmiccfgStby) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    }
    POWERCON_SetSocStandbyConfig(SYSCON__POWERCON_SOC_CTRL, &socCfg);

    /* Power Down: enable all CMC internal standby flows (XMC_STBY_MASK = 0) and
     * have every CMC trigger the SSC (explicit; also repairs the CMC0 TRIGGER_SS
     * clear left by a previous POWER_EnterSleep). No restore - wakeup is PoR. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x00U);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC0_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC1_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC2_CTRL);

    /* 4. Apply wakeup sources: CMC0 IRQ, CMC1 MAIN DMA, CMC2 WAKE DMA. */
    POWER_ApplyWakeupSources();
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL |= (POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 4b. PD_MEDIA is powered off in Power Down: isolate and power off the MIPI PHY supply
     *     before WFI. No restore here - wakeup triggers PoR; the post-reset app re-runs the
     *     power-on sequence. */
    POWER_MediaMipiPhyPowerOff();

    /* 5. Execute WFI - wakeup triggers PoR; no return. */
    POWER_ExecuteWfi();

    while (true) /* Safety net - should never reach here. */
    {
    }
}

/*!
 * brief Enters Deep Power Down mode.
 */
status_t POWER_EnterDeepPowerDown(const power_deep_power_down_config_t *config)
{
    assert(config != NULL);

    if (POWER_StandbyPrologue() != kStatus_Success)
    {
        return kStatus_Fail;
    }

    /* 1. MEMCON: Deep Power Down removes VDD_PMU and every memcon-controlled memory
     *    array loses its supply, so MEM_SLPCFG bits have no effect on retention.
     *    No memcon writes are issued here - same reasoning as POWER_EnterPowerDown.
     *    VBAT SRAM lives in the always-on VBAT domain (not MEMCON) and follows
     *    retainVbatSram: DPD1 leaves it powered by VBAT; DPD2 shuts it down (ACT
     *    -> INT -> SD) before the PMIC removes VDD_PMU. */
    if (config->retainVbatSram == false)
    {
        POWER_ShutdownVbatSram();
    }

    /* 2. Ensure HW trigger; configure all domains to power-off in standby. */
    POWER_ForceAllDomainsToHwTrigger();
    POWER_ConfigureAllDomainSleepEvents(kPDCON_EventPowerOff, kPDCON_EventPowerOff, kPDCON_EventPowerOff,
                                        kPDCON_EventPowerOff, kPDCON_EventPowerOff);

    /* 3. Configure SoC standby: all off, PMU to BB mode. */
    power_pmu_state_t dpd_pmucfg = {0};
    dpd_pmucfg.dcdcOffPmuRet     = 1U;                /* DCDC off */
    dpd_pmucfg.pmuMode           = POWER_PMU_MODE_BB; /* BB */

    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby = 0x00U; /* All root clocks gated in DPD (RCGCFG_STBY active-high: 0=gated) */
    /* CSRCCFG_STBY controls main clock sources only (FRO192M, PLLs, SXOSC etc.).
     * XOSC_32K and FRO_32K are VBAT_AON-domain clocks - they remain alive in DPD
     * regardless of CSRCCFG_STBY. Main clock sources are turned off in DPD. */
    socCfg.csrccfgStby = POWER_CSRCCFG_STBY_ALL_OFF;
    socCfg.pmucfgStby  = dpd_pmucfg.word;
    socCfg.pmiccfgStby = 0U;
    if ((s_extRegHooks != NULL) && (s_extRegHooks->setStandbyTarget != NULL))
    {
        /* Board hook selects the external regulator's DPSTANDBY profile via I2C
         * - the one profile distinct from Deep Sleep/Power Down's STANDBY - and reports the
         * PMICCFG_STBY.PMIC_MODE code fsl_power forwards to hardware below. This call did not
         * exist before this change; POWER_EnterDeepPowerDown() had no external-regulator-related code, and
         * `socCfg.pmiccfgStby` was left uninitialized (a pre-existing bug, now fixed). */
        if (s_extRegHooks->setStandbyTarget(kPOWER_DeepPowerDown, &socCfg.pmiccfgStby) != kStatus_Success)
        {
            return kStatus_Fail;
        }
    }

    POWERCON_SetSocStandbyConfig(SYSCON__POWERCON_SOC_CTRL, &socCfg);

    /* 4. Apply wakeup sources (must be called even in DPD for IRQ masks). */
    POWER_ApplyWakeupSources();
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL |= (POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 4b. PD_MEDIA is powered off in Deep Power Down: isolate and power off the MIPI PHY
     *     supply before WFI. No restore - wakeup triggers PoR. */
    POWER_MediaMipiPhyPowerOff();

    /* 5. Deep Power Down: enable all CMC internal standby flows (XMC_STBY_MASK = 0)
     *    and have every CMC trigger the SSC (explicit; also repairs the CMC0
     *    TRIGGER_SS clear left by a previous POWER_EnterSleep). No restore -
     *    wakeup is PoR. Then execute WFI. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x00U);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC0_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC1_CTRL);
    POWERCON_EnableSystemSleepTrigger(SYSCON__POWERCON_CMC2_CTRL);
    POWER_ExecuteWfi();

    while (true) /* Should not reach here. */
    {
    }
}

/*!
 * brief Unified low-power entry: dispatches to POWER_EnterSleep/DeepSleep/PowerDown/DeepPowerDown.
 */
status_t POWER_EnterLowPowerMode(power_low_power_mode_t lowPowerMode, const void *lpModeConfig)
{
    if (lpModeConfig == NULL)
    {
        return kStatus_InvalidArgument;
    }

    switch (lowPowerMode)
    {
        case kPOWER_Sleep:
            return POWER_EnterSleep((const power_sleep_config_t *)lpModeConfig);
        case kPOWER_DeepSleep:
            return POWER_EnterDeepSleep((const power_deep_sleep_config_t *)lpModeConfig);
        case kPOWER_PowerDown:
            return POWER_EnterPowerDown((const power_down_config_t *)lpModeConfig);                /* does not return */
        case kPOWER_DeepPowerDown:
            return POWER_EnterDeepPowerDown((const power_deep_power_down_config_t *)lpModeConfig); /* does not return */
        default:
            return kStatus_InvalidArgument;
    }
}
