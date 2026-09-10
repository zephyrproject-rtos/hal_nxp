/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_power.h"
#include "fsl_modcon.h"
#include "fsl_clock.h"
#if MCUX_POWER_PF9453_SUPPLY
#include "fsl_pf9453.h" /* External VDD_CORE supply (Option D). fsl_power never includes fsl_lpi2c. */
#endif

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.power"
#endif

#if MCUX_POWER_PF9453_SUPPLY
/* PF9453 BUCK2 (VDD_CORE) millivolt set-points, mapped from the DCDC VOUT_ADJ codes below. */
#define POWER_PF9453_BUCK2_RUN_HP_MV  (900U) /*!< HP run: 0.9 V. */
#define POWER_PF9453_BUCK2_RUN_LP_MV  (800U) /*!< NP / LP run: 0.8 V. */
#define POWER_PF9453_BUCK2_STANDBY_MV (650U) /*!< Deep-sleep standby: 0.65 V (matches SoC DAC). */
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
#define POWER_MEMCON_MAX_BLOCKS_PER_SLICE     12U /*!< Maximum blocks configurable per MEMCON slice */
#define POWER_MEMCON_OCRAM0_SLICE_IDX         2U  /*!< OCRAM0 resides in MEMCON slice 2 */
#define POWER_MEMCON_OCRAM0_DS_BLOCK_COUNT    9U  /*!< OCRAM0 blocks configured for Deep Sleep retention */
#define POWER_MEMCON_OCRAM0_MAX_RETAIN_BLOCKS 8U  /*!< Max blocks for PD retention (64 KB / 8 KB each) */
#define POWER_MEMCON_OCRAM0_PKC_BLOCK_IDX     11U /*!< PKC RAM block index within OCRAM0 slice */
#define POWER_MEMCON_OCRAM0_LLC_BLOCK_IDX     8U  /*!< LLC cache block index within OCRAM0 slice (S2 B8) */
#define POWER_MEMCON_AUDIO8KB_BLOCK_IDX       10U /*!< Audio SRAM 8KB block index within OCRAM0 slice (S2 B10) */

/* PMUCFG.pmuMode bitfield values (RT2660 PMU mode encoding). */
#define POWER_PMU_MODE_LP  2U /*!< Low Power (ZBB, 0.8 V DCDC) */
#define POWER_PMU_MODE_RET 3U /*!< Retention (DCDC off) */
#define POWER_PMU_MODE_BB  4U /*!< Body Bias mode (Deep Power Down) */

/* PMUCFG LDO mode field encoding (shared by ldo0V8Mode, ldo1V8Mode, ldoVdda1V8Mode). */
#define POWER_LDO_MODE_LP 2U /*!< LDO Low Power mode */

/*
 * Body-bias reference values from the verification-team sequence
 * (rt2660_bodybias_configuration.drawio).
 *
 * IMPORTANT: these are temporary reference trim values until OTP/PMU
 * characterization data is available through the production trim flow.
 * fsl_power only uses ZBB and full FBB (N-well + P-well); it does not use
 * P-well-only, N-well-only, Hi-Z, standby, or VDD-tracking body-bias modes.
 */
#define POWER_BODYBIAS_FBB_NWELL_VOL_SEL (0x18U) // 1200mV
#define POWER_BODYBIAS_FBB_PWELL_VOL_SEL (0x24U) // 1800mV

/* OCRAM0 block granularity used for retention sizing. */
#define POWER_OCRAM0_BLOCK_SIZE_KB 8U /*!< Each MEMCON OCRAM0 block covers 8 KB */

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
 * kept consistent with the applied VOUT_ADJ. In standby the same codes drive the PMU DAC. */
#define POWER_PMUCFG_CORELEVEL_090V 0x1BU /*!< 0.9 V (VOUT_ADJ=27) - HP run mode. */
#define POWER_PMUCFG_CORELEVEL_080V 0U    /*!< 0.8 V (VOUT_ADJ=0) - NP / LP run mode. */
#define POWER_PMUCFG_CORELEVEL_065V 17U   /*!< 0.65 V - Deep Sleep standby (0.225 + 17 x 0.025). */

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

/* Four RT2660 SW-controllable power domains (PD_CPU/NPU/COMM/MEDIA). */
static const uint8_t s_powerDomains[] = {
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

#if MCUX_POWER_PF9453_SUPPLY
/* Internal PF9453 handle, created in POWER_InitExtSupply() from the board-supplied I2C transport. In
 * Option D fsl_power owns the PMIC and drives BUCK2 (VDD_CORE) directly at the run-mode/standby points. */
static pf9453_handle_t s_pmic;
/* Set by POWER_InitExtSupply(). Until then the PMIC handle/transport is not ready, so the run-mode and
 * standby paths skip the BUCK2 write (a run-mode DVS legitimately runs during boot-clock setup, before
 * POWER_InitExtSupply, when the board is ordered per the reference; the PMIC keeps its power-on voltage). */
static bool s_pmicReady = false;
#endif

/*******************************************************************************
 * Private helpers
 ******************************************************************************/

static void POWER_SetBodyBiasFbbFullConfig(pmu_body_bias_config_t *config);

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
static void POWER_ApplyZbb(void)
{
    pmu_body_bias_config_t bbCfg;
    PMU_GetDefaultBodyBiasConfig(&bbCfg);
    PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
    (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
}

/* Full FBB used by fsl_power: N-well + P-well only. */
static void POWER_SetBodyBiasFbbFullConfig(pmu_body_bias_config_t *config)
{
    assert(config != NULL);

    PMU_GetDefaultBodyBiasConfig(config);
    config->mode        = kPMU_BodyBiasFBBFull;
    config->nwellVolSel = POWER_BODYBIAS_FBB_NWELL_VOL_SEL;
    config->pwellVolSel = POWER_BODYBIAS_FBB_PWELL_VOL_SEL;
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
 * Configures MEMCON sleep-mode power state for a list of memory identifiers.
 */
static void POWER_SetMemSlicesSleepMode(memcon_power_mode_t mode, const power_memory_t *mems, uint32_t count)
{
    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;
    for (uint32_t i = 0U; i < count; i++)
    {
        uint8_t sliceIdx = (uint8_t)((uint32_t)mems[i] >> 8U);
        uint8_t blockIdx = (uint8_t)((uint32_t)mems[i] & 0xFFU);
        MEMCON_SLICE_SetSleepBlockMode(sliceBases[sliceIdx], blockIdx, mode);
    }
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
 * brief Applies the power management policy (active/low-power baseline, NPU/Media/Comm
 *       domain state, active-mode clock sources). Safe to call more than once.
 */
void POWER_SetPolicy(const power_policy_config_t *config)
{
    assert(config != NULL);

    /* 1. Enable POWERCON function clock FIRST (must precede all POWERCON accesses). */
    POWERCON_EnableFunctionClock(SYSCON__POWERCON_SOC_CTRL);

    /* 2. Enable PDCON function clock. */
    PDCON_EnableFunctionClock(SYSCON__PDCON, true);

    /* 3. Apply SoC handshake routing (HSK_SEL routing and PDCON HSKCTRL).
     *    NULL -> apply POR-default values; non-NULL -> apply caller-supplied config. */
    if (config->handshakeRouting != NULL)
    {
        POWER_SetHandshakeRouting(config->handshakeRouting);
    }

    /* 4. Apply per-CMC step-mode configuration. */
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC0_CTRL, &config->cmcCpu);
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC1_CTRL, &config->cmcMain);
    POWER_ApplyCmcStepConfig(SYSCON__POWERCON_CMC2_CTRL, &config->cmcWake);

    /* 6. Build SSC step-mode bitmasks. */
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

    /* 7. Standby gating baseline: XMC_STBY_MASK = 0x07 disables all CMC internal
     *    standby flows while active, so a bare application WFI stays a simple
     *    core WFI. Each POWER_Enter*() programs the mode-specific mask before
     *    its WFI. TRIGGER_SS is set explicitly on all CMCs (silicon default
     *    made deterministic); Sleep entry clears it on CMC0. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x07U);
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

    /* 8. Configure PDCON trigger mode for the four SW-controllable domains.
     *    Default: HW trigger enabled (CMC drives standby transitions).
     *             SW trigger disabled (enabled transiently in POWER_SetDomainRunMode). */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        PDCON_EnableDomainHwTrigger(SYSCON__PDCON, s_powerDomains[i], true);
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_powerDomains[i], false);
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_powerDomains[i], kPDCON_EventNoneOrActive);
    }
    /* PD_MAIN (domain 1) is not SW-triggerable and not in s_powerDomains, but it DOES have a
     * PDSLPCFG field. Its low-power event is driver-fixed: NoneOrActive everywhere except
     * Power Down / Deep Power Down (set to PowerOff in those entry paths). Establish the
     * active-mode default here. */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventNoneOrActive);

    /* 9. Enable active-mode clock sources. Moved here from POWER_EnterHpRun/NormalRun/LpRun
     *     (was duplicated identically in all three) -- those functions are voltage/frequency
     *     only now. */
    for (uint8_t i = 0U; i <= 8U; i++)
    {
        POWERCON_EnableClockSourceInActiveMode(SYSCON__POWERCON_SOC_CTRL, i);
    }

    /* 10. Bring the NPU/Media/Comm domains active, if not already (idempotent -- a domain
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

    /* 11. Enable MEMCON function clock; set all slices to HW-trigger mode with all
     *    blocks in NormalPower (Active) active state.  SLPCFG (standby registers)
     *    are NOT written here - they are configured only at standby entry.
     *    Order-dependent on step 10 (see step 10 comment). */
    MEMCON_GLOBAL_EnableFunctionClock(SYSCON__MEMCON_GLOBAL, true);
    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;
    for (uint32_t i = 0U; i < ARRAY_SIZE(sliceBases); i++)
    {
        /* Write RUNCFG = Active for every block (hardware reset default made explicit;
         * hardware applies this on wakeup from standby - no SW restore needed). */
        MEMCON_SLICE_SetTriggerMode(sliceBases[i], kMEMCON_TriggerSoftware);
        for (uint8_t blk = 0U; blk < POWER_MEMCON_MAX_BLOCKS_PER_SLICE; blk++)
        {
            MEMCON_SLICE_SetActiveBlockMode(sliceBases[i], blk, kMEMCON_PowerModeActive);
        }
        MEMCON_SLICE_SoftwareTrigger(sliceBases[i]);
        /* HW-trigger mode: CMC/SSC drives standby transitions. */
        MEMCON_SLICE_SetTriggerMode(sliceBases[i], kMEMCON_TriggerHardware);
    }

    /* 12. Initialise SW wakeup state: mask all sources. */
    (void)memset(s_irqWakeupMask, 0xFF, sizeof(s_irqWakeupMask));
    (void)memset(s_mainDmaWakeupMask, 0xFF, sizeof(s_mainDmaWakeupMask));
    (void)memset(s_wakeDmaWakeupMask, 0xFF, sizeof(s_wakeDmaWakeupMask));
}

#if MCUX_POWER_PF9453_SUPPLY
void POWER_InitExtSupply(const power_ext_supply_config_t *config)
{
    assert(config != NULL);
    assert(config->I2C_SendFunc != NULL);
    assert(config->I2C_ReceiveFunc != NULL);

    pf9453_config_t pmicConfig;
    pf9453_buck2_config_t buck2Config;

    /* Create the PMIC handle from the board-supplied I2C transport. */
    pmicConfig.I2C_SendFunc    = config->I2C_SendFunc;
    pmicConfig.I2C_ReceiveFunc = config->I2C_ReceiveFunc;
    pmicConfig.slaveAddress    = config->slaveAddress;
    PF9453_CreateHandle(&s_pmic, &pmicConfig);

    /* One-shot BUCK2 bring-up: enable in ACTIVE/STANDBY, initial run voltage (HP 0.9 V so the boot
     * ramp to HP has adequate VDD_CORE), standby voltage, DVS ramp. Run-mode DVS and standby-target
     * changes are then handled at the transition points. */
    buck2Config.runMillivolt     = POWER_PF9453_BUCK2_RUN_HP_MV;
    buck2Config.standbyMillivolt = POWER_PF9453_BUCK2_STANDBY_MV;
    buck2Config.enableMode       = kPF9453_EnableOnActiveStandby; /* B2_ENMODE = 10. */
    buck2Config.forcePwm         = false;
    buck2Config.activeDischarge  = false;
    buck2Config.dvsRamp          = kPF9453_Buck2Ramp_25mVPer2us; /* reset default. */
    (void)PF9453_ConfigBuck2(&s_pmic, &buck2Config);

    /* Arm the ready flag: subsequent run-mode DVS / standby-target changes now drive the PMIC. */
    s_pmicReady = true;
}
#endif /* MCUX_POWER_PF9453_SUPPLY */

/*!
 * brief Accumulates a wakeup source into SW state.
 *
 * Decodes the opaque power_wakeup_source_t encoding:
 *   bits[31:28] = 0x0 -> IRQ (CMC0),  index = bits[8:0]  (0-383)
 *   bits[31:28] = 0x1 -> MAIN DMA (CMC1), index = bits[5:0]  (0-63)
 *   bits[31:28] = 0x2 -> WAKE DMA (CMC2), index = bits[5:0]  (0-63)
 *
 * Inverted polarity: clear the bit to enable wakeup (matches hardware register).
 */
void POWER_EnableWakeupSource(power_wakeup_source_t source)
{
    uint32_t type  = (source >> 28U) & 0xFU;
    uint32_t index = source & 0x1FFU; /* 9-bit max for IRQ index */

    switch (type)
    {
        case 0x0U: /* IRQ -> CMC0 */
            if (index < ((uint32_t)POWER_IRQ_WAKEUP_MASK_COUNT * 32U))
            {
                s_irqWakeupMask[index / 32U] &= ~(1UL << (index % 32U));
            }
            break;
        case 0x1U:                  /* MAIN domain DMA -> CMC1 */
            index = source & 0x3FU; /* 6-bit DMA index */
            if (index < ((uint32_t)POWER_DMA_WAKEUP_MASK_COUNT * 32U))
            {
                s_mainDmaWakeupMask[index / 32U] &= ~(1UL << (index % 32U));
            }
            break;
        case 0x2U: /* WAKE domain DMA -> CMC2 */
            index = source & 0x3FU;
            if (index < ((uint32_t)POWER_DMA_WAKEUP_MASK_COUNT * 32U))
            {
                s_wakeDmaWakeupMask[index / 32U] &= ~(1UL << (index % 32U));
            }
            break;
        default:
            /* Unknown source type - no action. */
            break;
    }
}

/*!
 * brief Removes a wakeup source from SW state.
 *
 * Same opaque encoding as POWER_EnableWakeupSource.
 * Sets the bit to mask the source (inverted polarity).
 */
void POWER_DisableWakeupSource(power_wakeup_source_t source)
{
    uint32_t type  = (source >> 28U) & 0xFU;
    uint32_t index = source & 0x1FFU;

    switch (type)
    {
        case 0x0U: /* IRQ -> CMC0 */
            if (index < ((uint32_t)POWER_IRQ_WAKEUP_MASK_COUNT * 32U))
            {
                s_irqWakeupMask[index / 32U] |= (1UL << (index % 32U));
            }
            break;
        case 0x1U: /* MAIN domain DMA -> CMC1 */
            index = source & 0x3FU;
            if (index < ((uint32_t)POWER_DMA_WAKEUP_MASK_COUNT * 32U))
            {
                s_mainDmaWakeupMask[index / 32U] |= (1UL << (index % 32U));
            }
            break;
        case 0x2U: /* WAKE domain DMA -> CMC2 */
            index = source & 0x3FU;
            if (index < ((uint32_t)POWER_DMA_WAKEUP_MASK_COUNT * 32U))
            {
                s_wakeDmaWakeupMask[index / 32U] |= (1UL << (index % 32U));
            }
            break;
        default:
            /* Unknown source type - no action. */
            break;
    }
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

/*
 * Media MIPI CSI/DSI PHY 0.8 V supply, controlled by WAKE_MODCON MIPI_0V8_CFG
 * (PWR_EN bit 0: power switch; DATA_EN bit 1: data isolation).
 * The PHY must never be powered while PD_MEDIA is unpowered, and must be isolated
 * before the domain loses power.
 */
static void POWER_MediaMipiPhyPowerOff(void)
{
    uint32_t cfg = MODCON_GetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U);

    /* Isolate first (DATA_EN=0), then switch the PHY supply off (PWR_EN=0). */
    cfg &= ~MODCON_CFG_DATA_EN_MASK;
    MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
    cfg &= ~MODCON_CFG_PWR_EN_MASK;
    MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
}

static void POWER_MediaMipiPhyPowerOn(void)
{
    uint32_t cfg = MODCON_GetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U);

    /* Ensure isolated/off, switch the PHY supply on (PWR_EN=1), then de-isolate (DATA_EN=1). */
    cfg &= ~(MODCON_CFG_DATA_EN_MASK | MODCON_CFG_PWR_EN_MASK);
    MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
    cfg |= MODCON_CFG_PWR_EN_MASK;
    MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
    cfg |= MODCON_CFG_DATA_EN_MASK;
    MODCON_SetCFG((uint32_t)kModCon_WAKE_MIPI_0V8, 0U, cfg);
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
    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;
    uint8_t sliceIdx                      = (uint8_t)((uint32_t)mem >> 8U);
    uint8_t blockIdx                      = (uint8_t)((uint32_t)mem & 0xFFU);

    /* Switch to SW trigger to apply the change immediately, then restore HW trigger
     * so CMC/SSC remains in control of standby transitions. */
    MEMCON_SLICE_SetTriggerMode(sliceBases[sliceIdx], kMEMCON_TriggerSoftware);
    MEMCON_SLICE_SetActiveBlockMode(sliceBases[sliceIdx], blockIdx, mode);
    MEMCON_SLICE_SoftwareTrigger(sliceBases[sliceIdx]);
    MEMCON_SLICE_SetTriggerMode(sliceBases[sliceIdx], kMEMCON_TriggerHardware);
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
#if MCUX_POWER_PF9453_SUPPLY
    /* PMIC path: VDD_CORE is BUCK2. Map the VOUT_ADJ code to millivolts and DVS BUCK2 directly.
     * PF9453_SetBuck2RunVoltage re-issues the regulator unlock and RMW-writes BUCK2OUT internally.
     * The on-chip DCDC is not touched (its VOUT_ADJ path is compiled out below).
     * Skip until POWER_InitExtSupply has created the handle: the boot-clock setup may call a run-mode
     * DVS before the PMIC transport is up, and the PF9453 already holds its power-on voltage then. */
    if (s_pmicReady)
    {
        uint16_t millivolt =
            (voutAdj == POWER_PMUCFG_CORELEVEL_090V) ? POWER_PF9453_BUCK2_RUN_HP_MV : POWER_PF9453_BUCK2_RUN_LP_MV;
        (void)PF9453_SetBuck2RunVoltage(&s_pmic, millivolt);
    }
#else
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
#endif /* MCUX_POWER_PF9453_SUPPLY */
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
    pmu_body_bias_config_t bbCfg;
    power_pmu_state_t pmuState;

    /* Read-modify-write: preserve all fields except the three that change per run mode. */
    pmuState.word     = SYSCON__POWERCON_SOC_CTRL->PMUCFG_ACTIVE;
    pmuState.pmuMode  = 0U; /* HP */
    pmuState.dcdcMode = 1U; /* PWM */
    pmuState.coreLvl  = POWER_PMUCFG_CORELEVEL_090V;

    if (POWER_GetCurrentRunMode() == kPOWER_RunModeLp) /* LP (ZBB) -> HP */
    {
        /* LP -> HP: raise voltage first (DCDC + consistent coreLvl), then switch clocks. */
        POWER_ApplyRunCoreVoltage(POWER_PMUCFG_CORELEVEL_090V);
        POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
        POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
        while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
        {
        }
        POWER_SetBodyBiasFbbFullConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
        if (clockCb != NULL)
        {
            clockCb();
        }
    }
    else
    {
        /* HP/NP -> HP: must transition through ZBB before switching FBB target. */
        PMU_GetDefaultBodyBiasConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
        /* Increase into HP: raise the DCDC voltage before the core clock speeds up. */
        POWER_ApplyRunCoreVoltage(POWER_PMUCFG_CORELEVEL_090V);
        POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
        POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
        while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
        {
        }
        if (clockCb != NULL)
        {
            clockCb();
        }
        POWER_SetBodyBiasFbbFullConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
    }
}

/*!
 * brief Enters Normal run mode (VDD_CORE=0.8 V, DCDC PWM, FBB).
 */
void POWER_EnterNormalRun(power_clock_cb_t clockCb)
{
    pmu_body_bias_config_t bbCfg;
    power_pmu_state_t pmuState;

    /* Read-modify-write: preserve all fields except the three that change per run mode. */
    pmuState.word     = SYSCON__POWERCON_SOC_CTRL->PMUCFG_ACTIVE;
    pmuState.pmuMode  = 0U; /* HP/NP share the same pmuMode=0 */
    pmuState.dcdcMode = 1U; /* PWM */
    pmuState.coreLvl  = POWER_PMUCFG_CORELEVEL_080V;

    if (POWER_GetCurrentRunMode() == kPOWER_RunModeLp) /* LP (ZBB) -> NP */
    {
        /* LP -> NP: VDD_CORE is unchanged (both 0.8 V); apply the DCDC level for
         * consistency, then switch body bias and clocks. */
        POWER_ApplyRunCoreVoltage(POWER_PMUCFG_CORELEVEL_080V);
        POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
        POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
        while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
        {
        }
        POWER_SetBodyBiasFbbFullConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
        if (clockCb != NULL)
        {
            clockCb();
        }
    }
    else
    {
        /* HP/NP -> NP: must transition through ZBB before switching FBB target. */
        PMU_GetDefaultBodyBiasConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
        /* Decrease from HP (0.9 V) into NP (0.8 V): reduce the core clock first, then
         * lower the DCDC voltage. Applying 0.8 V while still at HP frequency would
         * undervolt the core. */
        if (clockCb != NULL)
        {
            clockCb();
        }
        POWER_ApplyRunCoreVoltage(POWER_PMUCFG_CORELEVEL_080V);
        POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
        POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
        while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
        {
        }
        /* Switch body bias to FBB after clocks are settled at the new voltage. */
        POWER_SetBodyBiasFbbFullConfig(&bbCfg);
        PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
        (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
    }
}

/*!
 * brief Enters LP run mode (VDD_CORE=0.8 V, DCDC PWM, ZBB).
 */
void POWER_EnterLpRun(power_clock_cb_t clockCb)
{
    pmu_body_bias_config_t bbCfg;
    power_pmu_state_t pmuState;

    /* Read-modify-write: preserve all fields except the three that change per run mode. */
    pmuState.word     = SYSCON__POWERCON_SOC_CTRL->PMUCFG_ACTIVE;
    pmuState.pmuMode  = 0U; /* LP (ZBB standby path) */
    pmuState.dcdcMode = 1U; /* PWM (V0.9: all active run modes use PWM; PFM is a DS2/DS3-only standby choice) */
    pmuState.coreLvl  = POWER_PMUCFG_CORELEVEL_080V;

    PMU_GetDefaultBodyBiasConfig(&bbCfg);

    /* HP/NP -> LP: reduce clocks first, then lower voltage. */
    if (clockCb != NULL)
    {
        clockCb();
    }
    PMU_GetDefaultBodyBiasConfig(&bbCfg);
    PMU_ConfigBodyBias(SYSCON__PMU, &bbCfg);
    (void)PMU_ApplyBodyBiasBlocking(SYSCON__PMU);
    /* Clocks are already reduced, so it is safe to lower the DCDC voltage (0.8 V). From HP
     * this is a decrease; from NP the level is unchanged. */
    POWER_ApplyRunCoreVoltage(POWER_PMUCFG_CORELEVEL_080V);
    POWERCON_SetPmucfgActive(SYSCON__POWERCON_SOC_CTRL, pmuState.word);
    POWERCON_TriggerSocUpdate(SYSCON__POWERCON_SOC_CTRL);
    while (!POWERCON_IsSocUpdateDone(SYSCON__POWERCON_SOC_CTRL))
    {
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

    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;

    /* 1. Configure MEMCON SLPCFG from config memory fields. */
    /* Slice 0: Wake SRAM (B0). */
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[0U], 0U, config->setWakeSramMode);
    /* Slice 2: OCRAM0 (B0-B7), LLC cache (B8), Audio 8KB (B10). */
    for (uint8_t blk = 0U; blk < POWER_MEMCON_OCRAM0_MAX_RETAIN_BLOCKS; blk++)
    {
        MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], blk, config->setOcramMode);
    }
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], POWER_MEMCON_OCRAM0_LLC_BLOCK_IDX,
                                   config->setLlcCacheMode);
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], POWER_MEMCON_AUDIO8KB_BLOCK_IDX,
                                   config->setAudio8KbMode);
    /* TCM slices from config. */
    const power_memory_t cpuMems[]   = POWER_CPU_TCM_SLICES;
    const power_memory_t npuMems[]   = POWER_NPU_TCM_SLICES;
    const power_memory_t commMems[]  = POWER_COMM_TCM_SLICES;
    const power_memory_t mediaMems[] = POWER_MEDIA_TCM_SLICES;
    POWER_SetMemSlicesSleepMode(config->setM85TcmMode, cpuMems, ARRAY_SIZE(cpuMems));
    POWER_SetMemSlicesSleepMode(config->setNpuTcmMode, npuMems, ARRAY_SIZE(npuMems));
    POWER_SetMemSlicesSleepMode(config->setCommTcmMode, commMems, ARRAY_SIZE(commMems));
    POWER_SetMemSlicesSleepMode(config->setMediaTcmMode, mediaMems, ARRAY_SIZE(mediaMems));

    /* 2. Ensure all SW-controllable domains use HW trigger (CMC drives standby sequence). */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_powerDomains[i], false);
    }

    /* 3. Configure PDCON sleep events for each domain (PDSLPCFG standby registers). */
    const pdcon_event_t domainEvents[] = {config->setCpuDomainEvent, config->setNpuDomainEvent,
                                          config->setCommDomainEvent, config->setMediaDomainEvent};
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_powerDomains[i], domainEvents[i]);
    }
    /* PD_MAIN: fixed NoneOrActive in Sleep (only PD/DPD power it off). */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventNoneOrActive);

    /* 4. Build PMUCFG_STBY and CSRCCFG_STBY from config fields. */
    power_pmu_state_t pmucfgStby = {0};
    pmucfgStby.pmuMode           = config->setPmuMode;
    pmucfgStby.dcdcMode          = (config->setDcdcMode == kPMU_DcdcModePWM) ? 1U : 0U;
    pmucfgStby.coreLvl           = config->setCoreLevel;
    pmucfgStby.ldo0V8Mode        = (uint32_t)config->setLdo0V8Mode;
    pmucfgStby.ldo1V8Mode        = (uint32_t)config->setLdo1V8Mode;
    pmucfgStby.ldoVdda1V8Mode    = config->setLdoVdda1V8Mode;
    pmucfgStby.hqref             = config->enableHqref ? 1U : 0U;
    pmucfgStby.sensorTemp        = (config->enableSensors >> 0U) & 1U;
    pmucfgStby.sensor0V8         = (config->enableSensors >> 1U) & 1U;
    pmucfgStby.sensor1V8         = (config->enableSensors >> 2U) & 1U;
    pmucfgStby.sensorVdda        = (config->enableSensors >> 3U) & 1U;
    pmucfgStby.sensorCore        = (config->enableSensors >> 4U) & 1U;
    pmucfgStby.sensorPmu         = (config->enableSensors >> 5U) & 1U;

    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby  = POWER_BUILD_RCGCFG_STBY(config);
    socCfg.csrccfgStby = POWER_BUILD_CSRCCFG_STBY(config);
    socCfg.pmucfgStby  = pmucfgStby.word;
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

    /* 6. Execute WFI. WFI is the hardware-triggered low-power entry request. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;

    /* 7. Clear PDCON sleep event flags (W1C).
     *    Prevents stale flags from persisting into the next LP entry. */
    POWER_ClearPdsef();
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);
    __DSB();
    __WFI();
    __ISB();

    /* Restore the active-mode baseline so a later bare WFI stays a bare WFI. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x07U);

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

    /* 0. CSSI/ELS LP handshake - abort if CSSI denies LP entry. */
    if (!POWER_RequestCssiLpEntry())
    {
        return kStatus_Fail;
    }

    POWER_ClearPdsef();
    POWER_ClearMainTcmForceAlive();
    POWER_ApplyZbb();

    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;

    /* 1. Configure MEMCON SLPCFG from config memory fields. */
    /* Slice 0: Wake SRAM (B0). */
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[0U], 0U, config->setWakeSramMode);
    /* Slice 2: OCRAM0 (B0-B7), LLC cache (B8), Audio 8KB (B10). */
    for (uint8_t blk = 0U; blk < POWER_MEMCON_OCRAM0_MAX_RETAIN_BLOCKS; blk++)
    {
        MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], blk, config->setOcramMode);
    }
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], POWER_MEMCON_OCRAM0_LLC_BLOCK_IDX,
                                   config->setLlcCacheMode);
    MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], POWER_MEMCON_AUDIO8KB_BLOCK_IDX,
                                   config->setAudio8KbMode);
    /* TCM slices from config. */
    const power_memory_t cpuMems[]   = POWER_CPU_TCM_SLICES;
    const power_memory_t npuMems[]   = POWER_NPU_TCM_SLICES;
    const power_memory_t commMems[]  = POWER_COMM_TCM_SLICES;
    const power_memory_t mediaMems[] = POWER_MEDIA_TCM_SLICES;
    POWER_SetMemSlicesSleepMode(config->setM85TcmMode, cpuMems, ARRAY_SIZE(cpuMems));
    POWER_SetMemSlicesSleepMode(config->setNpuTcmMode, npuMems, ARRAY_SIZE(npuMems));
    POWER_SetMemSlicesSleepMode(config->setCommTcmMode, commMems, ARRAY_SIZE(commMems));
    POWER_SetMemSlicesSleepMode(config->setMediaTcmMode, mediaMems, ARRAY_SIZE(mediaMems));

    /* 2. Ensure HW trigger for all domains (CMC drives standby sequence). */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_powerDomains[i], false);
    }

    /* 3. Configure PDCON sleep events (PDSLPCFG standby registers only;
     *    PDRUNCFG active registers are NOT modified here). */
    const pdcon_event_t domainEvents[] = {config->setCpuDomainEvent, config->setNpuDomainEvent,
                                          config->setCommDomainEvent, config->setMediaDomainEvent};
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_powerDomains[i], domainEvents[i]);
    }
    /* PD_MAIN: fixed NoneOrActive in Deep Sleep (only PD/DPD power it off). */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventNoneOrActive);

    /* 4. Build PMUCFG_STBY and CSRCCFG_STBY from config fields. */
    power_pmu_state_t pmucfgStby = {0};
    pmucfgStby.pmuMode           = config->setPmuMode;
    pmucfgStby.dcdcMode          = (config->setDcdcMode == kPMU_DcdcModePWM) ? 1U : 0U;
    pmucfgStby.coreLvl           = config->setCoreLevel;
    pmucfgStby.ldo0V8Mode        = (uint32_t)config->setLdo0V8Mode;
    pmucfgStby.ldo1V8Mode        = (uint32_t)config->setLdo1V8Mode;
    pmucfgStby.ldoVdda1V8Mode    = config->setLdoVdda1V8Mode;
    pmucfgStby.hqref             = config->enableHqref ? 1U : 0U;
    pmucfgStby.sensorTemp        = (config->enableSensors >> 0U) & 1U;
    pmucfgStby.sensor0V8         = (config->enableSensors >> 1U) & 1U;
    pmucfgStby.sensor1V8         = (config->enableSensors >> 2U) & 1U;
    pmucfgStby.sensorVdda        = (config->enableSensors >> 3U) & 1U;
    pmucfgStby.sensorCore        = (config->enableSensors >> 4U) & 1U;
    pmucfgStby.sensorPmu         = (config->enableSensors >> 5U) & 1U;

    /* 5. Configure SoC standby for Deep Sleep. */
    powercon_soc_standby_config_t socCfg;
    socCfg.rcgcfgStby  = POWER_BUILD_RCGCFG_STBY(config) | POWER_RCGCFG_STBY_DEEPSLEEP_REQUIRED;
    socCfg.csrccfgStby = POWER_BUILD_CSRCCFG_STBY(config);
    socCfg.pmucfgStby  = pmucfgStby.word;
    socCfg.pmiccfgStby = 0U;
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

#if MCUX_POWER_PF9453_SUPPLY
    /* 6c. Select the PMIC STANDBY (not DPSTANDBY) target so BUCK2 stays on and drops to its standby
     *     voltage when POWERCON's sscPmic step asserts PMIC_STBY_REQ. Enable-mode and standby voltage
     *     were already programmed by POWER_InitExtSupply (skip if the PMIC transport is not up). */
    if (s_pmicReady)
    {
        (void)PF9453_SetStandbyTarget(&s_pmic, kPF9453_StandbySbyt);
    }
#endif

    /* 7. Execute WFI. WFI is the hardware-triggered low-power entry request. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

    /* 8. On return: hardware has already applied PDRUNCFG (PDCON active registers)
     *    and MEMCON RUNCFG.
     *    PLL clock outputs: hardware only re-enables the DIV4 output of MAINPLL
     *    and SYSPLL on wakeup.  All other outputs (DIV5/8/10/20, PFD0/1/2) remain
     *    gated.  The caller must re-enable any required non-DIV4 PLL outputs after
     *    this function returns.  COREPLL frequency is preserved without a reset;
     *    if the CPU was running from COREPLL before entry no clock restoration
     *    is needed for the core. */
    /* Restore the active-mode baseline so a later bare WFI stays a bare WFI. */
    POWERCON_SetXmcStandbyMask(SYSCON__POWERCON_GLOBAL, 0x07U);
    SYSCON__POWERCON_CMC0_CTRL->CMC_CTRL &= ~(POWERCON_CMC_CTRL_CMC_CTRL_SLEEP_HOLD_EN_MASK);

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

    /* 0. CSSI/ELS LP handshake - must consent before powering off. */
    if (!POWER_RequestCssiLpEntry())
    {
        return kStatus_Fail;
    }

    POWER_ClearPdsef();
    POWER_ClearMainTcmForceAlive();
    POWER_ApplyZbb();

    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;

    /* 1. Configure MEMCON for OCRAM0/PKC retention per RM Table 793.
     *    OCRAM0 = SRAMCTL_0 (Slice 2, Blocks 0-3) + SRAMCTL_1 (Slice 2, B4-5)
     *           + SRAMCTL_2 (Slice 2, B6-7).  Total: 8 blocks = 64 KB max.
     *    retainOcram0KB selects how many 8 KB blocks to retain (0-64 in 8 KB units).
     *    PKC RAM = Slice 2, Block 11 (RM Table 793: ELE PKC RAM). */
    /* Round up retainOcram0KB to 8 KB blocks, clamped to 8 blocks max before cast. */
    uint32_t retainBlocksRaw =
        (config->retainOcram0KB + (POWER_OCRAM0_BLOCK_SIZE_KB - 1U)) / POWER_OCRAM0_BLOCK_SIZE_KB;
    uint8_t retainBlocks = (retainBlocksRaw > POWER_MEMCON_OCRAM0_MAX_RETAIN_BLOCKS) ?
                               (uint8_t)POWER_MEMCON_OCRAM0_MAX_RETAIN_BLOCKS :
                               (uint8_t)retainBlocksRaw;
    for (uint8_t blk = 0U; blk < POWER_MEMCON_MAX_BLOCKS_PER_SLICE; blk++)
    {
        memcon_power_mode_t mode;
        if (blk < retainBlocks)
        {
            mode = kMEMCON_PowerModeRetention; /* OCRAM0 retention */
        }
        else if ((blk == POWER_MEMCON_OCRAM0_LLC_BLOCK_IDX) && config->retainLlcCache)
        {
            mode = kMEMCON_PowerModeRetention; /* LLC cache retention */
        }
        else if ((blk == POWER_MEMCON_AUDIO8KB_BLOCK_IDX) && config->retainAudio8Kb)
        {
            mode = kMEMCON_PowerModeRetention; /* Audio SRAM 8KB retention */
        }
        else if ((blk == POWER_MEMCON_OCRAM0_PKC_BLOCK_IDX) && config->retainPkcMem)
        {
            mode = kMEMCON_PowerModeRetention; /* PKC RAM retention */
        }
        else
        {
            mode = kMEMCON_PowerModePowerDown;
        }
        MEMCON_SLICE_SetSleepBlockMode(sliceBases[POWER_MEMCON_OCRAM0_SLICE_IDX], blk, mode);
    }

    /* All other SRAM slices: power-off in Power Down. */
    for (uint32_t s = 0U; s < ARRAY_SIZE(sliceBases); s++)
    {
        if (s == POWER_MEMCON_OCRAM0_SLICE_IDX)
        {
            continue;
        } /* slice handled above */
        for (uint8_t blk = 0U; blk < POWER_MEMCON_MAX_BLOCKS_PER_SLICE; blk++)
        {
            MEMCON_SLICE_SetSleepBlockMode(sliceBases[s], blk, kMEMCON_PowerModePowerDown);
        }
    }

    /* 2. Ensure HW trigger; configure all domains to power-off in standby. */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_powerDomains[i], false);
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_powerDomains[i], kPDCON_EventPowerOff);
    }
    /* PD_MAIN (fixed): powered off in Power Down via its PDSLPCFG event. */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventPowerOff);


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

#if MCUX_POWER_PF9453_SUPPLY
    /* 4c. Select the PMIC DPSTANDBY target so BUCK2 turns OFF when POWERCON's sscPmic step asserts
     *     PMIC_STBY_REQ (Power Down wakeup is a PoR; the PF9453 stays alive on VSYS). Skip if the PMIC
     *     transport is not up (POWER_InitExtSupply not called). */
    if (s_pmicReady)
    {
        (void)PF9453_SetStandbyTarget(&s_pmic, kPF9453_StandbyDeepStby);
    }
#endif

    /* 5. Execute WFI - wakeup triggers PoR; no return. */
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

    while (true) /* Safety net - should never reach here. */
    {
    }
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
   uint32_t ctrl = VBAT__SRAM->CTRL & ~(uint32_t)SRAM_CTRL_PWR_MODE_MASK;
   VBAT__SRAM->CTRL = ctrl | SRAM_CTRL_PWR_MODE(2U); /* INTERMEDIATE (INT) */
   VBAT__SRAM->CTRL = 0UL;                          /* SHUTDOWN (SD = 0)  */
}

/*!
 * brief Enters Deep Power Down mode.
 */
status_t POWER_EnterDeepPowerDown(const power_deep_power_down_config_t *config)
{
    assert(config != NULL);

    /* 0. CSSI/ELS LP handshake - must consent before powering off. */
    if (!POWER_RequestCssiLpEntry())
    {
        return kStatus_Fail;
    }

    POWER_ClearPdsef();
    POWER_ClearMainTcmForceAlive();
    POWER_ApplyZbb();

    MEMCON_SLICE_Type *const sliceBases[] = MEMCON_SLICE_BASE_PTRS;

    /* 1. Configure MEMCON: VBAT SRAM follows retainVbatSram. */
    /* VBAT SRAM is in the VBAT domain (not controlled by MEMCON_SLICE here).
     * For MEMCON slices under VDD_MAIN: power down all. */
    for (uint32_t s = 0U; s < ARRAY_SIZE(sliceBases); s++)
    {
        for (uint8_t blk = 0U; blk < POWER_MEMCON_MAX_BLOCKS_PER_SLICE; blk++)
        {
            MEMCON_SLICE_SetSleepBlockMode(sliceBases[s], blk, kMEMCON_PowerModePowerDown);
        }
    }
    /* VBAT retention SRAM: DPD1 (retainVbatSram) leaves it ACTIVE - the always-on
     * VBAT domain holds the contents while VDD_PMU stays on.  DPD2 does not retain,
     * so power the SRAM down (ACT -> INT -> SD) before the PMIC removes VDD_PMU. */
    if (config->retainVbatSram == false)
    {
        POWER_ShutdownVbatSram();
    }

    /* 2. Ensure HW trigger; configure all domains to power-off in standby. */
    for (uint32_t i = 0U; i < ARRAY_SIZE(s_powerDomains); i++)
    {
        PDCON_EnableDomainSwTrigger(SYSCON__PDCON, s_powerDomains[i], false);
        (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, s_powerDomains[i], kPDCON_EventPowerOff);
    }
    /* PD_MAIN (fixed): powered off in Deep Power Down via its PDSLPCFG event. */
    (void)PDCON_SetEventInLowPowerModes(SYSCON__PDCON, kPOWER_DomainMain, kPDCON_EventPowerOff);

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
    SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk;
    __DSB();
    __WFI();
    __ISB();

    while (true) /* Should not reach here. */
    {
    }
}
