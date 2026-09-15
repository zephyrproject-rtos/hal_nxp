/*
 * Copyright 2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_POWER_H
#define FSL_POWER_H

#include "fsl_common.h"
#include "fsl_pmu.h"
#include "fsl_pdcon.h"
#include "fsl_memcon.h"
#include "fsl_vbatcon.h"
#include "fsl_powercon.h"

/*! @brief When set, VDD_CORE is supplied by an external PF9453 PMIC (BUCK2) instead of the on-chip
 *  DCDC. This is a pure compile-time choice: with the macro set, all VDD_CORE handling is compiled to
 *  go through the PF9453; unset, the on-chip DCDC path is compiled and there is no fsl_pf9453
 *  dependency. There is no runtime enable flag. */
#ifndef MCUX_POWER_PF9453_SUPPLY
#define MCUX_POWER_PF9453_SUPPLY 0
#endif

/*!
 * @addtogroup power
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*@{*/
/*! @brief power driver version 2.0.0. */
#define FSL_POWER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!
 * @brief PMU analog state - word-sized bitfield union that overlays
 *        POWERCON_SOC_CTRL.PMUCFG_ACTIVE / PMUCFG_STBY.
 *
 * Write `.word` directly to the PMUCFG register via POWERCON P-Channel.
 */
typedef union _power_pmu_state
{
    struct
    {
        uint32_t sensorTemp : 1;     /*!< bit[0]      Temperature sensor enable */
        uint32_t sensor0V8 : 1;      /*!< bit[1]      VDD_0V8 sensor enable */
        uint32_t sensor1V8 : 1;      /*!< bit[2]      VDD_1V8 sensor enable */
        uint32_t sensorVdda : 1;     /*!< bit[3]      VDDA_1V8 sensor enable */
        uint32_t sensorCore : 1;     /*!< bit[4]      VDD_CORE sensor enable */
        uint32_t sensorPmu : 1;      /*!< bit[5]      VDD_PMU sensor enable */
        uint32_t hqref : 1;          /*!< bit[6]      High-quality reference enable */
        uint32_t dcdcMode : 1;       /*!< bit[7]      DCDC mode: 0=PFM, 1=PWM */
        uint32_t ldo0V8Mode : 2;     /*!< bits[9:8]   LDO_VDD_0V8:  0=off, 1=HP, 2=LP */
        uint32_t ldo1V8Mode : 2;     /*!< bits[11:10] LDO_VDD_1V8:  0=off, 1=HP, 2=LP */
        uint32_t ldoVdda1V8Mode : 2; /*!< bits[13:12] LDO_VDDA_1V8: 0=off, 1=HP, 2=LP, 3=ULP */
        uint32_t dcdcOffPmuRet : 1;  /*!< bit[14]     DCDC off when PMU_MODE=RET/BB */
        uint32_t coreLvl : 5;        /*!< bits[19:15] VDD_CORE DAC: 0x00=0.8 V (others TBD) */
        uint32_t pmuMode : 3;        /*!< bits[22:20] PMU mode: 0=HP, 1=HP-prog, 2=LP,
                                                       3=RET, 4=BB */
        uint32_t : 9;                /*!< bits[31:23] Reserved; write as zero */
    };
    uint32_t word;                   /*!< Raw 32-bit value; write directly to PMUCFG_ACTIVE / PMUCFG_STBY */
} power_pmu_state_t;

/*! @brief CMC/SSC step operating mode. */
typedef enum _power_step_mode
{
    kPOWER_StepModeHandshake = 0U, /*!< Wait for handshake ACK (hardware reset default) */
    kPOWER_StepModeCount     = 1U, /*!< Advance after a fixed count of POWERCON clocks */
} power_step_mode_t;

/*!
 * @brief Configuration for one CMC or SSC step (sleep and wakeup directions).
 *
 * `countValue` is used only when sleepMode or wakeupMode is kPOWER_StepModeCount.
 * All steps within the same CMC/SSC block share one COUNT register - if multiple
 * steps use count mode their countValue fields MUST be identical.
 */
typedef struct _power_step_config
{
    power_step_mode_t sleepMode;  /*!< Mode for the sleep (entry) direction */
    power_step_mode_t wakeupMode; /*!< Mode for the wakeup (exit) direction */
    uint32_t countValue;          /*!< POWERCON clock cycles; ignored for Handshake mode */
} power_step_config_t;

/*!
 * @brief Step configuration for one CMC instance (5 steps).
 *
 * Each CMC instance (CMC0, CMC1, CMC2) has its own step-mode mask and COUNT register.
 * Different CMC instances may require different step modes or count values.
 */
typedef struct _power_cmc_step_config
{
    power_step_config_t busMasterLpcg; /*!< STEP1: Bus master LPCG handshake/gate */
    power_step_config_t busSlaveLpcg;  /*!< STEP2: Bus slave LPCG handshake/gate */
    power_step_config_t rootClockGate; /*!< STEP3: SS root clock gate/ungate */
    power_step_config_t clockSource;   /*!< STEP4: Clock source via P-Channel */
    power_step_config_t powerDomain;   /*!< STEP5: Power domain control (PDCON) */
} power_cmc_step_config_t;

/*!
 * @brief Init-time SoC handshake routing configuration.
 *
 * Configures the routing of root clocks and clock sources to CMC handshake
 * partners (POWERCON HSK_SEL registers) and PDCON per-domain handshake masks.
 * Pass via @ref power_policy_config_t::handshakeRouting (or NULL for POR defaults),
 * or pass directly to POWER_SetHandshakeRouting() for post-init reconfiguration.
 */
typedef struct _power_handshake_routing_config
{
    uint32_t rcgcfgHskSel;               /*!< POWERCON RCGCFG_HSK_SEL: root clock -> CMC routing. */
    uint32_t csrccfgHskSel;              /*!< POWERCON CSRCCFG_HSK_SEL: clock source -> CMC routing, word 0. */
    uint32_t csrccfgHskSel1;             /*!< POWERCON CSRCCFG_HSK_SEL1: clock source -> CMC routing, word 1. */
    pdcon_handshake_mask_t domainHsk[6]; /*!< PDCON HSKCTRL per-domain handshake mask, indexed by domain (0-5). */
} power_handshake_routing_config_t;

#if MCUX_POWER_PF9453_SUPPLY
/*!
 * @brief External-supply (PF9453 PMIC) I2C access, handed to POWER_InitExtSupply() so fsl_power can drive
 *        VDD_CORE (BUCK2) directly. Present only when MCUX_POWER_PF9453_SUPPLY is set. These are
 *        runtime function-pointer data (the board's I2C transport), NOT a mode switch — the compile
 *        macro is the only switch. Signatures match the PF9453 driver's I2C callback contract.
 */
typedef struct _power_ext_supply_config
{
    status_t (*I2C_SendFunc)(uint8_t deviceAddress, uint32_t subAddress, uint8_t subAddressSize,
                             uint8_t *txBuff, uint8_t txBuffSize); /*!< I2C write callback (board). */
    status_t (*I2C_ReceiveFunc)(uint8_t deviceAddress, uint32_t subAddress, uint8_t subAddressSize,
                                uint8_t *rxBuff, uint8_t rxBuffSize); /*!< I2C read callback (board). */
    uint8_t slaveAddress; /*!< PF9453 7-bit I2C address (OTP-dependent; default 0x32). */
} power_ext_supply_config_t;
#endif /* MCUX_POWER_PF9453_SUPPLY */

/*! @brief Configuration passed to POWER_SetPolicy(). */
typedef struct _power_policy_config
{
    /* Per-CMC instance step configuration (RT2660-specific mapping) */
    power_cmc_step_config_t cmcCpu;  /*!< CMC0 - CPU / M85 core (COMPUTE_SS domain) */
    power_cmc_step_config_t cmcMain; /*!< CMC1 - MAIN domain (eDMA3 + eDMA5 DMA wakeup) */
    power_cmc_step_config_t cmcWake; /*!< CMC2 - WAKE domain (eDMA3 DMA wakeup) */

    /* SSC steps */
    power_step_config_t sscPmu;  /*!< SSC STEP1: PMU standby/exit via P-Channel */
    power_step_config_t sscPmic; /*!< SSC STEP2: PMIC standby/exit */

    /*!< Init-time SoC handshake routing (HSK_SEL routing and PDCON HSKCTRL).
     *   NULL = apply POR-default values (hardware reset defaults).
     *   Non-NULL = apply *handshakeRouting directly (skips internal default lookup). */
    const power_handshake_routing_config_t *handshakeRouting;
} power_policy_config_t;

/*!
 * @brief Encoded wakeup source for POWER_EnableWakeupSource() / POWER_DisableWakeupSource().
 *
 * Encoding: bits[31:28] = wakeup path; remaining bits = source index.
 *   0x0xxxxxxx : IRQ wakeup   -> CMC0 IRQ_WAKEUP_MASK  (NVIC index 0-383)
 *   0x1xxxxxxx : MAIN DMA     -> CMC1 DMA_WAKEUP_MASK  (RM wakeup source index 0-63)
 *   0x2xxxxxxx : WAKE DMA     -> CMC2 DMA_WAKEUP_MASK  (RM wakeup source index 31-43)
 *
 * DMA wakeup source index is the RM Chapter 4 peripheral index - NOT an eDMA channel number.
 * One peripheral maps to one index regardless of how many DMA request lines it uses.
 *
 * Use the named enum members for known peripherals.
 * Use the constructor macros (POWER_WAKEUP_IRQ / POWER_WAKEUP_MAIN_DMA /
 * POWER_WAKEUP_WAKE_DMA) when the source index is determined at run time.
 *
 * Wakeup sources are accumulated in SW state; POWERCON registers are written
 * inside POWER_Enter*() via the internal POWER_ApplyWakeupSources() call.
 *
 * Power-mode applicability (RT2660 domain power map):
 *   WAKE domain : Sleep, Deep Sleep, Power Down
 *   VBAT domain : Sleep, Deep Sleep, Power Down, Deep Power Down (DPD1)
 *   HSP  domain : Sleep, Deep Sleep - HSP is in PD_MAIN (on in Sleep and Deep Sleep,
 *                 off in Power Down and deeper). In Deep Sleep the functional clock is
 *                 gated, so an HSP wakeup source must use a clock-less event (e.g. the
 *                 LPUART RX active-edge, BAUD[RXEDGIE]); a clocked interrupt fires in
 *                 Sleep only.
 *   MAIN DMA (CMC1) : Sleep, Deep Sleep
 *   WAKE DMA (CMC2) : Sleep, Deep Sleep, Power Down
 */
typedef enum _power_wakeup_source
{
    /* ----------------------------------------------------------------
     * CMPT domain - CMC0 IRQ_WAKEUP_MASK (IRQn 0-24)
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_CmptCm85Cti      = CMPT_CM85_CTI_IRQn,       /*!< CMPT CM85 CTI (0) */
    kPOWER_WakeupIrq_CmptCm85EccError = CMPT_CM85_ECC_ERROR_IRQn, /*!< CMPT CM85 ECC error (3) */
    kPOWER_WakeupIrq_CmptCm85Mcm      = CMPT_CM85_MCM_IRQn,       /*!< CMPT CM85 MCM (6) */
    kPOWER_WakeupIrq_CmptTrdc         = CMPT_TRDC_IRQn,           /*!< CMPT TRDC (7) */
#if defined(MIMXRT2663_SERIES) || defined(MIMXRT2661_SERIES)
    kPOWER_WakeupIrq_CmptNpu          = CMPT_NPU_IRQn,            /*!< CMPT NPU (8) */
#endif
    kPOWER_WakeupIrq_CmptSramctl0     = CMPT_SRAMCTL_0_IRQn,      /*!< CMPT SRAMCTL0 (9) */
    kPOWER_WakeupIrq_CmptSramctl1     = CMPT_SRAMCTL_1_IRQn,      /*!< CMPT SRAMCTL1 (10) */
    kPOWER_WakeupIrq_CmptSramctl2     = CMPT_SRAMCTL_2_IRQn,      /*!< CMPT SRAMCTL2 (11) */
    kPOWER_WakeupIrq_CmptFreqme       = CMPT_FREQME_IRQn,         /*!< CMPT FREQME (16) */
    kPOWER_WakeupIrq_CmptLlc          = CMPT_LLC_IRQn,            /*!< CMPT LLC (20) */
    kPOWER_WakeupIrq_CmptDap          = CMPT_DAP_IRQn,            /*!< CMPT DAP (24) */

    /* ----------------------------------------------------------------
     * MAIN + SYSCON domain - CMC0 IRQ_WAKEUP_MASK (IRQn 25-96)
     * PD_MAIN powered in Sleep and Deep Sleep; off in Power Down and deeper.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_MainTrdc       = MAIN_TRDC_IRQn,          /*!< MAIN TRDC (25) */
    kPOWER_WakeupIrq_MainAhb2Axi    = MAIN_AHB2AXI_IRQn,       /*!< MAIN AHB2AXI bus error (26) */
    kPOWER_WakeupIrq_MainMmu        = MAIN_MMU_IRQn,           /*!< MAIN MMU (28) */
    kPOWER_WakeupIrq_MainEdma3Ch0   = MAIN_EDMA3_CH0_IRQn,     /*!< MAIN eDMA3 ch 0 IRQ (29) */
    kPOWER_WakeupIrq_MainEdma3Ch1   = MAIN_EDMA3_CH1_IRQn,     /*!< MAIN eDMA3 ch 1 IRQ (30) */
    kPOWER_WakeupIrq_MainEdma3Ch2   = MAIN_EDMA3_CH2_IRQn,     /*!< MAIN eDMA3 ch 2 IRQ (31) */
    kPOWER_WakeupIrq_MainEdma3Ch3   = MAIN_EDMA3_CH3_IRQn,     /*!< MAIN eDMA3 ch 3 IRQ (32) */
    kPOWER_WakeupIrq_MainEdma3Ch4   = MAIN_EDMA3_CH4_IRQn,     /*!< MAIN eDMA3 ch 4 IRQ (33) */
    kPOWER_WakeupIrq_MainEdma3Ch5   = MAIN_EDMA3_CH5_IRQn,     /*!< MAIN eDMA3 ch 5 IRQ (34) */
    kPOWER_WakeupIrq_MainEdma3Ch6   = MAIN_EDMA3_CH6_IRQn,     /*!< MAIN eDMA3 ch 6 IRQ (35) */
    kPOWER_WakeupIrq_MainEdma3Ch7   = MAIN_EDMA3_CH7_IRQn,     /*!< MAIN eDMA3 ch 7 IRQ (36) */
    kPOWER_WakeupIrq_MainEdma3Ch8   = MAIN_EDMA3_CH8_IRQn,     /*!< MAIN eDMA3 ch 8 IRQ (37) */
    kPOWER_WakeupIrq_MainEdma3Ch9   = MAIN_EDMA3_CH9_IRQn,     /*!< MAIN eDMA3 ch 9 IRQ (38) */
    kPOWER_WakeupIrq_MainEdma3Ch10  = MAIN_EDMA3_CH10_IRQn,    /*!< MAIN eDMA3 ch 10 IRQ (39) */
    kPOWER_WakeupIrq_MainEdma3Ch11  = MAIN_EDMA3_CH11_IRQn,    /*!< MAIN eDMA3 ch 11 IRQ (40) */
    kPOWER_WakeupIrq_MainEdma3Ch12  = MAIN_EDMA3_CH12_IRQn,    /*!< MAIN eDMA3 ch 12 IRQ (41) */
    kPOWER_WakeupIrq_MainEdma3Ch13  = MAIN_EDMA3_CH13_IRQn,    /*!< MAIN eDMA3 ch 13 IRQ (42) */
    kPOWER_WakeupIrq_MainEdma3Ch14  = MAIN_EDMA3_CH14_IRQn,    /*!< MAIN eDMA3 ch 14 IRQ (43) */
    kPOWER_WakeupIrq_MainEdma3Ch15  = MAIN_EDMA3_CH15_IRQn,    /*!< MAIN eDMA3 ch 15 IRQ (44) */
    kPOWER_WakeupIrq_MainEdma3Ch16  = MAIN_EDMA3_CH16_IRQn,    /*!< MAIN eDMA3 ch 16 IRQ (45) */
    kPOWER_WakeupIrq_MainEdma3Ch17  = MAIN_EDMA3_CH17_IRQn,    /*!< MAIN eDMA3 ch 17 IRQ (46) */
    kPOWER_WakeupIrq_MainEdma3Ch18  = MAIN_EDMA3_CH18_IRQn,    /*!< MAIN eDMA3 ch 18 IRQ (47) */
    kPOWER_WakeupIrq_MainEdma3Ch19  = MAIN_EDMA3_CH19_IRQn,    /*!< MAIN eDMA3 ch 19 IRQ (48) */
    kPOWER_WakeupIrq_MainEdma3Ch20  = MAIN_EDMA3_CH20_IRQn,    /*!< MAIN eDMA3 ch 20 IRQ (49) */
    kPOWER_WakeupIrq_MainEdma3Ch21  = MAIN_EDMA3_CH21_IRQn,    /*!< MAIN eDMA3 ch 21 IRQ (50) */
    kPOWER_WakeupIrq_MainEdma3Ch22  = MAIN_EDMA3_CH22_IRQn,    /*!< MAIN eDMA3 ch 22 IRQ (51) */
    kPOWER_WakeupIrq_MainEdma3Ch23  = MAIN_EDMA3_CH23_IRQn,    /*!< MAIN eDMA3 ch 23 IRQ (52) */
    kPOWER_WakeupIrq_MainEdma3Ch24  = MAIN_EDMA3_CH24_IRQn,    /*!< MAIN eDMA3 ch 24 IRQ (53) */
    kPOWER_WakeupIrq_MainEdma3Ch25  = MAIN_EDMA3_CH25_IRQn,    /*!< MAIN eDMA3 ch 25 IRQ (54) */
    kPOWER_WakeupIrq_MainEdma3Ch26  = MAIN_EDMA3_CH26_IRQn,    /*!< MAIN eDMA3 ch 26 IRQ (55) */
    kPOWER_WakeupIrq_MainEdma3Ch27  = MAIN_EDMA3_CH27_IRQn,    /*!< MAIN eDMA3 ch 27 IRQ (56) */
    kPOWER_WakeupIrq_MainEdma3Ch28  = MAIN_EDMA3_CH28_IRQn,    /*!< MAIN eDMA3 ch 28 IRQ (57) */
    kPOWER_WakeupIrq_MainEdma3Ch29  = MAIN_EDMA3_CH29_IRQn,    /*!< MAIN eDMA3 ch 29 IRQ (58) */
    kPOWER_WakeupIrq_MainEdma3Ch30  = MAIN_EDMA3_CH30_IRQn,    /*!< MAIN eDMA3 ch 30 IRQ (59) */
    kPOWER_WakeupIrq_MainEdma3Ch31  = MAIN_EDMA3_CH31_IRQn,    /*!< MAIN eDMA3 ch 31 IRQ (60) */
    kPOWER_WakeupIrq_MainEdma5Ch0   = MAIN_EDMA5_CH0_IRQn,     /*!< MAIN eDMA5 ch 0 IRQ (61) */
    kPOWER_WakeupIrq_MainEdma5Ch1   = MAIN_EDMA5_CH1_IRQn,     /*!< MAIN eDMA5 ch 1 IRQ (62) */
    kPOWER_WakeupIrq_MainEdma5Ch2   = MAIN_EDMA5_CH2_IRQn,     /*!< MAIN eDMA5 ch 2 IRQ (63) */
    kPOWER_WakeupIrq_MainEdma5Ch3   = MAIN_EDMA5_CH3_IRQn,     /*!< MAIN eDMA5 ch 3 IRQ (64) */
    kPOWER_WakeupIrq_MainEdma5Ch4   = MAIN_EDMA5_CH4_IRQn,     /*!< MAIN eDMA5 ch 4 IRQ (65) */
    kPOWER_WakeupIrq_MainEdma5Ch5   = MAIN_EDMA5_CH5_IRQn,     /*!< MAIN eDMA5 ch 5 IRQ (66) */
    kPOWER_WakeupIrq_MainEdma5Ch6   = MAIN_EDMA5_CH6_IRQn,     /*!< MAIN eDMA5 ch 6 IRQ (67) */
    kPOWER_WakeupIrq_MainEdma5Ch7   = MAIN_EDMA5_CH7_IRQn,     /*!< MAIN eDMA5 ch 7 IRQ (68) */
    kPOWER_WakeupIrq_MainEdma5Ch8   = MAIN_EDMA5_CH8_IRQn,     /*!< MAIN eDMA5 ch 8 IRQ (69) */
    kPOWER_WakeupIrq_MainEdma5Ch9   = MAIN_EDMA5_CH9_IRQn,     /*!< MAIN eDMA5 ch 9 IRQ (70) */
    kPOWER_WakeupIrq_MainEdma5Ch10  = MAIN_EDMA5_CH10_IRQn,    /*!< MAIN eDMA5 ch 10 IRQ (71) */
    kPOWER_WakeupIrq_MainEdma5Ch11  = MAIN_EDMA5_CH11_IRQn,    /*!< MAIN eDMA5 ch 11 IRQ (72) */
    kPOWER_WakeupIrq_MainEdma5Ch12  = MAIN_EDMA5_CH12_IRQn,    /*!< MAIN eDMA5 ch 12 IRQ (73) */
    kPOWER_WakeupIrq_MainEdma5Ch13  = MAIN_EDMA5_CH13_IRQn,    /*!< MAIN eDMA5 ch 13 IRQ (74) */
    kPOWER_WakeupIrq_MainEdma5Ch14  = MAIN_EDMA5_CH14_IRQn,    /*!< MAIN eDMA5 ch 14 IRQ (75) */
    kPOWER_WakeupIrq_MainEdma5Ch15  = MAIN_EDMA5_CH15_IRQn,    /*!< MAIN eDMA5 ch 15 IRQ (76) */
    kPOWER_WakeupIrq_MainFreqme     = MAIN_FREQME_IRQn,        /*!< MAIN FREQME (77) */
    kPOWER_WakeupIrq_HspStm         = HSP_STM_IRQn,            /*!< HSP STM (78) */
    kPOWER_WakeupIrq_MainXspi0      = MAIN_XSPI0_IRQn,         /*!< MAIN XSPI0 (82) */
    kPOWER_WakeupIrq_MainXspi1      = MAIN_XSPI1_IRQn,         /*!< MAIN XSPI1 (83) */
    kPOWER_WakeupIrq_SysconCguInt0  = SYSCON_CGU_INT0_IRQn,    /*!< SYSCON CGU Vdda0V8 (86) */
    kPOWER_WakeupIrq_SysconCguInt1  = SYSCON_CGU_INT1_IRQn,    /*!< SYSCON CGU AudioPLL (87) */
    kPOWER_WakeupIrq_SysconCguInt2  = SYSCON_CGU_INT2_IRQn,    /*!< SYSCON CGU VideoPLL (88) */
    kPOWER_WakeupIrq_MainCssi       = MAIN_CSSI_IRQn,          /*!< MAIN CSSI (89) */
    kPOWER_WakeupIrq_MainCssiMu0a   = MAIN_CSSI_SENTMU0A_IRQn, /*!< MAIN CSSI MU0A (90) */
    kPOWER_WakeupIrq_MainCssiMu1a   = MAIN_CSSI_SENTMU1A_IRQn, /*!< MAIN CSSI MU1A (91) */
    kPOWER_WakeupIrq_SysconPmuInt0  = SYSCON_PMU_INT0_IRQn,    /*!< SYSCON PMU sensor/monitor (93) */
    kPOWER_WakeupIrq_SysconPmuInt1  = SYSCON_PMU_INT1_IRQn,    /*!< SYSCON PMU body bias (94) */
    kPOWER_WakeupIrq_SysconResetcon = SYSCON_RESETCON_IRQn,    /*!< SYSCON RESETCON (95) */
    kPOWER_WakeupIrq_SysconFreqme   = SYSCON_FREQME_IRQn,      /*!< SYSCON FREQME (96) */

    /* ----------------------------------------------------------------
     * HSP domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 100-199)
     * HSP domain is powered off in Deep Sleep and deeper modes.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_HspXbar0Ch0      = HSP_XBAR0_CH0_IRQn,       /*!< HSP XBAR0 ch 0 (100) */
    kPOWER_WakeupIrq_HspXbar0Ch1      = HSP_XBAR0_CH1_IRQn,       /*!< HSP XBAR0 ch 1 (101) */
    kPOWER_WakeupIrq_HspXbar0Ch2      = HSP_XBAR0_CH2_IRQn,       /*!< HSP XBAR0 ch 2 (102) */
    kPOWER_WakeupIrq_HspXbar0Ch3      = HSP_XBAR0_CH3_IRQn,       /*!< HSP XBAR0 ch 3 (103) */
    kPOWER_WakeupIrq_HspXbar0Ch4      = HSP_XBAR0_CH4_IRQn,       /*!< HSP XBAR0 ch 4 (104) */
    kPOWER_WakeupIrq_HspXbar0Ch5      = HSP_XBAR0_CH5_IRQn,       /*!< HSP XBAR0 ch 5 (105) */
    kPOWER_WakeupIrq_HspXbar0Ch6      = HSP_XBAR0_CH6_IRQn,       /*!< HSP XBAR0 ch 6 (106) */
    kPOWER_WakeupIrq_HspXbar0Ch7      = HSP_XBAR0_CH7_IRQn,       /*!< HSP XBAR0 ch 7 (107) */
    kPOWER_WakeupIrq_HspAdc0          = HSP_ADC0_IRQn,            /*!< HSP ADC0 (112) */
    kPOWER_WakeupIrq_HspAdc1          = HSP_ADC1_IRQn,            /*!< HSP ADC1 (113) */
    kPOWER_WakeupIrq_HspDac           = HSP_DAC_IRQn,             /*!< HSP DAC (114) */
    kPOWER_WakeupIrq_HspLpit0         = HSP_LPIT0_IRQn,           /*!< HSP LPIT0 (115) */
    kPOWER_WakeupIrq_HspLpit1         = HSP_LPIT1_IRQn,           /*!< HSP LPIT1 (116) */
    kPOWER_WakeupIrq_HspEflexPwm0Ch0  = HSP_EFLEXPWM0_CH0_IRQn,   /*!< HSP EFLEXPWM0 ch 0 (117) */
    kPOWER_WakeupIrq_HspEflexPwm0Ch1  = HSP_EFLEXPWM0_CH1_IRQn,   /*!< HSP EFLEXPWM0 ch 1 (118) */
    kPOWER_WakeupIrq_HspEflexPwm0Ch2  = HSP_EFLEXPWM0_CH2_IRQn,   /*!< HSP EFLEXPWM0 ch 2 (119) */
    kPOWER_WakeupIrq_HspEflexPwm0Ch3  = HSP_EFLEXPWM0_CH3_IRQn,   /*!< HSP EFLEXPWM0 ch 3 (120) */
    kPOWER_WakeupIrq_HspEflexPwm0Err  = HSP_EFLEXPWM0_ERROR_IRQn, /*!< HSP EFLEXPWM0 fault (121) */
    kPOWER_WakeupIrq_HspEflexPwm1Ch0  = HSP_EFLEXPWM1_CH0_IRQn,   /*!< HSP EFLEXPWM1 ch 0 (122) */
    kPOWER_WakeupIrq_HspEflexPwm1Ch1  = HSP_EFLEXPWM1_CH1_IRQn,   /*!< HSP EFLEXPWM1 ch 1 (123) */
    kPOWER_WakeupIrq_HspEflexPwm1Ch2  = HSP_EFLEXPWM1_CH2_IRQn,   /*!< HSP EFLEXPWM1 ch 2 (124) */
    kPOWER_WakeupIrq_HspEflexPwm1Ch3  = HSP_EFLEXPWM1_CH3_IRQn,   /*!< HSP EFLEXPWM1 ch 3 (125) */
    kPOWER_WakeupIrq_HspEflexPwm1Err  = HSP_EFLEXPWM1_ERROR_IRQn, /*!< HSP EFLEXPWM1 fault (126) */
    kPOWER_WakeupIrq_HspEflexPwm2Ch0  = HSP_EFLEXPWM2_CH0_IRQn,   /*!< HSP EFLEXPWM2 ch 0 (127) */
    kPOWER_WakeupIrq_HspEflexPwm2Ch1  = HSP_EFLEXPWM2_CH1_IRQn,   /*!< HSP EFLEXPWM2 ch 1 (128) */
    kPOWER_WakeupIrq_HspEflexPwm2Ch2  = HSP_EFLEXPWM2_CH2_IRQn,   /*!< HSP EFLEXPWM2 ch 2 (129) */
    kPOWER_WakeupIrq_HspEflexPwm2Ch3  = HSP_EFLEXPWM2_CH3_IRQn,   /*!< HSP EFLEXPWM2 ch 3 (130) */
    kPOWER_WakeupIrq_HspEflexPwm2Err  = HSP_EFLEXPWM2_ERROR_IRQn, /*!< HSP EFLEXPWM2 fault (131) */
    kPOWER_WakeupIrq_HspEflexPwm3Ch0  = HSP_EFLEXPWM3_CH0_IRQn,   /*!< HSP EFLEXPWM3 ch 0 (132) */
    kPOWER_WakeupIrq_HspEflexPwm3Ch1  = HSP_EFLEXPWM3_CH1_IRQn,   /*!< HSP EFLEXPWM3 ch 1 (133) */
    kPOWER_WakeupIrq_HspEflexPwm3Ch2  = HSP_EFLEXPWM3_CH2_IRQn,   /*!< HSP EFLEXPWM3 ch 2 (134) */
    kPOWER_WakeupIrq_HspEflexPwm3Ch3  = HSP_EFLEXPWM3_CH3_IRQn,   /*!< HSP EFLEXPWM3 ch 3 (135) */
    kPOWER_WakeupIrq_HspEflexPwm3Err  = HSP_EFLEXPWM3_ERROR_IRQn, /*!< HSP EFLEXPWM3 fault (136) */
    kPOWER_WakeupIrq_HspQtpm0Ch0      = HSP_QTPM0_IRQn,           /*!< HSP QTPM0 (137) */
    kPOWER_WakeupIrq_HspQtpm0Ch1      = HSP_QTPM1_IRQn,           /*!< HSP QTPM1 (138) */
    kPOWER_WakeupIrq_HspQtpm0Ch2      = HSP_QTPM2_IRQn,           /*!< HSP QTPM2 (139) */
    kPOWER_WakeupIrq_HspQtpm0Ch3      = HSP_QTPM3_IRQn,           /*!< HSP QTPM3 (140) */
    kPOWER_WakeupIrq_HspQtmr0         = HSP_QTMR0_IRQn,           /*!< HSP QTMR0 (149) */
    kPOWER_WakeupIrq_HspQtmr1         = HSP_QTMR1_IRQn,           /*!< HSP QTMR1 (150) */
    kPOWER_WakeupIrq_HspQtmr2         = HSP_QTMR2_IRQn,           /*!< HSP QTMR2 (151) */
    kPOWER_WakeupIrq_HspQtmr3         = HSP_QTMR3_IRQn,           /*!< HSP QTMR3 (152) */
    kPOWER_WakeupIrq_HspEqdc0         = HSP_EQDC0_IRQn,           /*!< HSP EQDC0 (153) */
    kPOWER_WakeupIrq_HspEqdc1         = HSP_EQDC1_IRQn,           /*!< HSP EQDC1 (154) */
    kPOWER_WakeupIrq_HspEqdc2         = HSP_EQDC2_IRQn,           /*!< HSP EQDC2 (155) */
    kPOWER_WakeupIrq_HspEqdc3         = HSP_EQDC3_IRQn,           /*!< HSP EQDC3 (156) */
    kPOWER_WakeupIrq_HspSinc0Ch0      = HSP_SINC0_CH0_IRQn,       /*!< HSP SINC0 ch 0 (157) */
    kPOWER_WakeupIrq_HspSinc0Ch1      = HSP_SINC0_CH1_IRQn,       /*!< HSP SINC0 ch 1 (158) */
    kPOWER_WakeupIrq_HspSinc0Ch2      = HSP_SINC0_CH2_IRQn,       /*!< HSP SINC0 ch 2 (159) */
    kPOWER_WakeupIrq_HspSinc0Ch3      = HSP_SINC0_CH3_IRQn,       /*!< HSP SINC0 ch 3 (160) */
    kPOWER_WakeupIrq_HspSinc1Ch0      = HSP_SINC1_CH0_IRQn,       /*!< HSP SINC1 ch 0 (161) */
    kPOWER_WakeupIrq_HspSinc1Ch1      = HSP_SINC1_CH1_IRQn,       /*!< HSP SINC1 ch 1 (162) */
    kPOWER_WakeupIrq_HspSinc1Ch2      = HSP_SINC1_CH2_IRQn,       /*!< HSP SINC1 ch 2 (163) */
    kPOWER_WakeupIrq_HspSinc1Ch3      = HSP_SINC1_CH3_IRQn,       /*!< HSP SINC1 ch 3 (164) */
    kPOWER_WakeupIrq_HspFlexCan0      = HSP_FLEXCAN0_IRQn,        /*!< HSP FlexCAN0 (165) */
    kPOWER_WakeupIrq_HspFlexCan0Error = HSP_FLEXCAN0_ERROR_IRQn,  /*!< HSP FlexCAN0 error (166) */
    kPOWER_WakeupIrq_HspFlexCan1      = HSP_FLEXCAN1_IRQn,        /*!< HSP FlexCAN1 (167) */
    kPOWER_WakeupIrq_HspFlexCan1Error = HSP_FLEXCAN1_ERROR_IRQn,  /*!< HSP FlexCAN1 error (168) */
    kPOWER_WakeupIrq_HspFlexCan2      = HSP_FLEXCAN2_IRQn,        /*!< HSP FlexCAN2 (169) */
    kPOWER_WakeupIrq_HspFlexCan2Error = HSP_FLEXCAN2_ERROR_IRQn,  /*!< HSP FlexCAN2 error (170) */
    kPOWER_WakeupIrq_HspFlexIo0       = HSP_FLEXIO0_IRQn,         /*!< HSP FlexIO0 (171) */
    kPOWER_WakeupIrq_HspFlexIo1       = HSP_FLEXIO1_IRQn,         /*!< HSP FlexIO1 (172) */
    kPOWER_WakeupIrq_HspFlexIo2       = HSP_FLEXIO2_IRQn,         /*!< HSP FlexIO2 (173) */
    kPOWER_WakeupIrq_HspI3c           = HSP_I3C_IRQn,             /*!< HSP I3C (174) */
    kPOWER_WakeupIrq_HspLpi2c0        = HSP_LPI2C0_IRQn,          /*!< HSP LPI2C0 (175) */
    kPOWER_WakeupIrq_HspLpi2c1        = HSP_LPI2C1_IRQn,          /*!< HSP LPI2C1 (176) */
    kPOWER_WakeupIrq_HspLpspi0        = HSP_LPSPI0_IRQn,          /*!< HSP LPSPI0 (179) */
    kPOWER_WakeupIrq_HspLpspi1        = HSP_LPSPI1_IRQn,          /*!< HSP LPSPI1 (180) */
    kPOWER_WakeupIrq_HspLpspi2        = HSP_LPSPI2_IRQn,          /*!< HSP LPSPI2 (181) */
    kPOWER_WakeupIrq_HspLpspi3        = HSP_LPSPI3_IRQn,          /*!< HSP LPSPI3 (182) */
    kPOWER_WakeupIrq_HspLpspi4        = HSP_LPSPI4_IRQn,          /*!< HSP LPSPI4 (183) */
    kPOWER_WakeupIrq_HspLpuart0       = HSP_LPUART0_IRQn,         /*!< HSP LPUART0 (184) */
    kPOWER_WakeupIrq_HspLpuart1       = HSP_LPUART1_IRQn,         /*!< HSP LPUART1 (185) */
    kPOWER_WakeupIrq_HspLpuart2       = HSP_LPUART2_IRQn,         /*!< HSP LPUART2 (186) */
    kPOWER_WakeupIrq_HspLpuart3       = HSP_LPUART3_IRQn,         /*!< HSP LPUART3 (187) */
    kPOWER_WakeupIrq_HspLpuart4       = HSP_LPUART4_IRQn,         /*!< HSP LPUART4 (188) */
    kPOWER_WakeupIrq_HspLpuart5       = HSP_LPUART5_IRQn,         /*!< HSP LPUART5 (189) */
    kPOWER_WakeupIrq_HspGpio0Ch0      = HSP_GPIO0_CH0_IRQn,       /*!< HSP GPIO0 ch 0 (190) */
    kPOWER_WakeupIrq_HspGpio0Ch1      = HSP_GPIO0_CH1_IRQn,       /*!< HSP GPIO0 ch 1 (191) */
    kPOWER_WakeupIrq_HspGpio1Ch0      = HSP_GPIO1_CH0_IRQn,       /*!< HSP GPIO1 ch 0 (192) */
    kPOWER_WakeupIrq_HspGpio1Ch1      = HSP_GPIO1_CH1_IRQn,       /*!< HSP GPIO1 ch 1 (193) */
    kPOWER_WakeupIrq_HspGpio2Ch0      = HSP_GPIO2_CH0_IRQn,       /*!< HSP GPIO2 ch 0 (194) */
    kPOWER_WakeupIrq_HspGpio2Ch1      = HSP_GPIO2_CH1_IRQn,       /*!< HSP GPIO2 ch 1 (195) */
    kPOWER_WakeupIrq_HspGpio3Ch0      = HSP_GPIO3_CH0_IRQn,       /*!< HSP GPIO3 ch 0 (196) */
    kPOWER_WakeupIrq_HspGpio3Ch1      = HSP_GPIO3_CH1_IRQn,       /*!< HSP GPIO3 ch 1 (197) */
    kPOWER_WakeupIrq_HspGpio4Ch0      = HSP_GPIO4_CH0_IRQn,       /*!< HSP GPIO4 ch 0 (198) */
    kPOWER_WakeupIrq_HspGpio4Ch1      = HSP_GPIO4_CH1_IRQn,       /*!< HSP GPIO4 ch 1 (199) */

    /* ----------------------------------------------------------------
     * WAKE domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 205-245)
     * PD_WAKE stays powered through Sleep, Deep Sleep, and Power Down.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_WakeTrdc    = WAKE_TRDC_IRQn,     /*!< WAKE TRDC (205) */
    kPOWER_WakeupIrq_WakeXbarCh0 = WAKE_XBAR_CH0_IRQn, /*!< WAKE XBAR ch 0 (206) */
    kPOWER_WakeupIrq_WakeXbarCh1 = WAKE_XBAR_CH1_IRQn, /*!< WAKE XBAR ch 1 (207) */
    /* WAKE eDMA3 channel-completion IRQ wakeup (use DMA variant for request-level wakeup) */
    kPOWER_WakeupIrq_WakeEdma3Ch0      = WAKE_EDMA3_CH0_IRQn,       /*!< WAKE eDMA3 ch 0 IRQ (208) */
    kPOWER_WakeupIrq_WakeEdma3Ch1      = WAKE_EDMA3_CH1_IRQn,       /*!< WAKE eDMA3 ch 1 IRQ (209) */
    kPOWER_WakeupIrq_WakeEdma3Ch2      = WAKE_EDMA3_CH2_IRQn,       /*!< WAKE eDMA3 ch 2 IRQ (210) */
    kPOWER_WakeupIrq_WakeEdma3Ch3      = WAKE_EDMA3_CH3_IRQn,       /*!< WAKE eDMA3 ch 3 IRQ (211) */
    kPOWER_WakeupIrq_WakeEdma3Ch4      = WAKE_EDMA3_CH4_IRQn,       /*!< WAKE eDMA3 ch 4 IRQ (212) */
    kPOWER_WakeupIrq_WakeEdma3Ch5      = WAKE_EDMA3_CH5_IRQn,       /*!< WAKE eDMA3 ch 5 IRQ (213) */
    kPOWER_WakeupIrq_WakeEdma3Ch6      = WAKE_EDMA3_CH6_IRQn,       /*!< WAKE eDMA3 ch 6 IRQ (214) */
    kPOWER_WakeupIrq_WakeEdma3Ch7      = WAKE_EDMA3_CH7_IRQn,       /*!< WAKE eDMA3 ch 7 IRQ (215) */
    kPOWER_WakeupIrq_WakeAcmp0         = WAKE_ACMP0_IRQn,           /*!< WAKE CMP0 (216) */
    kPOWER_WakeupIrq_WakeAcmp1         = WAKE_ACMP1_IRQn,           /*!< WAKE CMP1 (217) */
    kPOWER_WakeupIrq_WakeAcmp2         = WAKE_ACMP2_IRQn,           /*!< WAKE CMP2 (218) */
    kPOWER_WakeupIrq_WakeAcmp3         = WAKE_ACMP3_IRQn,           /*!< WAKE CMP3 (219) */
    kPOWER_WakeupIrq_WakeEwm           = WAKE_EWM_IRQn,             /*!< WAKE EWM watchdog (220) */
    kPOWER_WakeupIrq_WakeFreqme        = WAKE_FREQME_IRQn,          /*!< WAKE FREQME (221) */
    kPOWER_WakeupIrq_WakeLptmr0        = WAKE_LPTMR0_IRQn,          /*!< WAKE LPTMR0 (222) */
    kPOWER_WakeupIrq_WakeLptmr1        = WAKE_LPTMR1_IRQn,          /*!< WAKE LPTMR1 (223) */
    kPOWER_WakeupIrq_WakeQtpmCh0       = WAKE_QTPM0_IRQn,           /*!< WAKE QTPM0 (224) */
    kPOWER_WakeupIrq_WakeQtpmCh1       = WAKE_QTPM1_IRQn,           /*!< WAKE QTPM1 (225) */
    kPOWER_WakeupIrq_WakeQtpmCh2       = WAKE_QTPM2_IRQn,           /*!< WAKE QTPM2 (226) */
    kPOWER_WakeupIrq_WakeQtpmCh3       = WAKE_QTPM3_IRQn,           /*!< WAKE QTPM3 (227) */
    kPOWER_WakeupIrq_WakeSwt0          = WAKE_SWT0_IRQn,            /*!< WAKE SWT0 (228) */
    kPOWER_WakeupIrq_WakeSwt1          = WAKE_SWT1_IRQn,            /*!< WAKE SWT1 (229) */
    kPOWER_WakeupIrq_WakeI3c           = WAKE_I3C_IRQn,             /*!< WAKE I3C (234) */
    kPOWER_WakeupIrq_WakeLpi2c0        = WAKE_LPI2C0_IRQn,          /*!< WAKE LPI2C0 (235) */
    kPOWER_WakeupIrq_WakeLpi2c1        = WAKE_LPI2C1_IRQn,          /*!< WAKE LPI2C1 (236) */
    kPOWER_WakeupIrq_WakeLpspi         = WAKE_LPSPI_IRQn,           /*!< WAKE LPSPI (237) */
    kPOWER_WakeupIrq_WakeLpuart0       = WAKE_LPUART0_IRQn,         /*!< WAKE LPUART0 (238) */
    kPOWER_WakeupIrq_WakeLpuart1       = WAKE_LPUART1_IRQn,         /*!< WAKE LPUART1 (239) */
    kPOWER_WakeupIrq_WakeGpioCh0       = WAKE_GPIO_CH0_IRQn,        /*!< WAKE GPIO ch 0 (240) */
    kPOWER_WakeupIrq_WakeGpioCh1       = WAKE_GPIO_CH1_IRQn,        /*!< WAKE GPIO ch 1 (241) */
    kPOWER_WakeupIrq_WakePdmEvent      = WAKE_PDM_EVENT_IRQn,       /*!< WAKE MICFIL FIFO event (242) */
    kPOWER_WakeupIrq_WakePdmError      = WAKE_PDM_ERROR_IRQn,       /*!< WAKE MICFIL error (243) */
    kPOWER_WakeupIrq_WakePdmHwvadEvent = WAKE_PDM_HWVAD_EVENT_IRQn, /*!< WAKE MICFIL HWVAD event (244) */
    kPOWER_WakeupIrq_WakePdmHwvadError = WAKE_PDM_HWVAD_ERROR_IRQn, /*!< WAKE MICFIL HWVAD error (245) */

    /* ----------------------------------------------------------------
     * VBAT domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 247-254)
     * PD_BAT/VBAT stays powered in all modes including Deep Power Down.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_VbatBbsmInt0 = VBAT_BBSM_INT0_IRQn, /*!< VBAT BBSM alarm 0 (247) */
    kPOWER_WakeupIrq_VbatTdet     = VBAT_TDET_IRQn,      /*!< VBAT tamper detect (249) */
    kPOWER_WakeupIrq_VbatLptmr    = VBAT_LPTMR_IRQn,     /*!< VBAT LPTMR (250) */
    kPOWER_WakeupIrq_VbatRtc      = VBAT_RTC_IRQn,       /*!< VBAT RTC (251) */
    kPOWER_WakeupIrq_VbatGpioCh0  = VBAT_GPIO_CH0_IRQn,  /*!< VBAT GPIO ch 0 / AON pad (252) */
    kPOWER_WakeupIrq_VbatGpioCh1  = VBAT_GPIO_CH1_IRQn,  /*!< VBAT GPIO ch 1 / AON pad (253) */
    kPOWER_WakeupIrq_VbatVbatcon  = VBAT_VBATCON_IRQn,   /*!< VBAT VBATCON (254) */

    /* ----------------------------------------------------------------
     * AUDIO domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 255-289)
     * Part of PD_MAIN; powered in Sleep and Deep Sleep.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_AudioTrdc     = AUDIO_TRDC_IRQn,      /*!< AUDIO TRDC (255) */
    kPOWER_WakeupIrq_AudioSai0     = AUDIO_SAI0_IRQn,      /*!< AUDIO SAI0 (256) */
    kPOWER_WakeupIrq_AudioSai1     = AUDIO_SAI1_IRQn,      /*!< AUDIO SAI1 (257) */
    kPOWER_WakeupIrq_AudioSai2     = AUDIO_SAI2_IRQn,      /*!< AUDIO SAI2 (258) */
    kPOWER_WakeupIrq_AudioPdmEvent = AUDIO_PDM_EVENT_IRQn, /*!< AUDIO MICFIL FIFO event (262) */
    kPOWER_WakeupIrq_AudioPdmError = AUDIO_PDM_ERROR_IRQn, /*!< AUDIO MICFIL error (263) */
    kPOWER_WakeupIrq_AudioSpdif    = AUDIO_SPDIF_IRQn,     /*!< AUDIO SPDIF (270) */
    kPOWER_WakeupIrq_AudioEdma3Ch0 = AUDIO_EDMA3_CH0_IRQn, /*!< AUDIO eDMA3 ch 0 IRQ (271) */
    kPOWER_WakeupIrq_AudioEdma3Ch1 = AUDIO_EDMA3_CH1_IRQn, /*!< AUDIO eDMA3 ch 1 IRQ (272) */
    kPOWER_WakeupIrq_AudioEdma3Ch2 = AUDIO_EDMA3_CH2_IRQn, /*!< AUDIO eDMA3 ch 2 IRQ (273) */
    kPOWER_WakeupIrq_AudioEdma3Ch3 = AUDIO_EDMA3_CH3_IRQn, /*!< AUDIO eDMA3 ch 3 IRQ (274) */
    kPOWER_WakeupIrq_AudioEdma3Ch4 = AUDIO_EDMA3_CH4_IRQn, /*!< AUDIO eDMA3 ch 4 IRQ (275) */
    kPOWER_WakeupIrq_AudioEdma3Ch5 = AUDIO_EDMA3_CH5_IRQn, /*!< AUDIO eDMA3 ch 5 IRQ (276) */
    kPOWER_WakeupIrq_AudioEdma3Ch6 = AUDIO_EDMA3_CH6_IRQn, /*!< AUDIO eDMA3 ch 6 IRQ (277) */
    kPOWER_WakeupIrq_AudioEdma3Ch7 = AUDIO_EDMA3_CH7_IRQn, /*!< AUDIO eDMA3 ch 7 IRQ (278) */
    kPOWER_WakeupIrq_AudioAsrc     = AUDIO_ASRC_IRQn,      /*!< AUDIO ASRC (288) */
    kPOWER_WakeupIrq_AudioFreqme   = AUDIO_FREQME_IRQn,    /*!< AUDIO FREQME (289) */

    /* ----------------------------------------------------------------
     * COMM domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 295-314)
     * PD_COMM powered in Sleep and Deep Sleep.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_CommTrdc         = COMM_TRDC_IRQn,          /*!< COMM TRDC (295) */
    kPOWER_WakeupIrq_CommEnetQos      = COMM_ENET_QOS_IRQn,      /*!< COMM ENET_QOS (296) */
    kPOWER_WakeupIrq_CommEnetQosTx    = COMM_ENET_QOS_TX_IRQn,   /*!< COMM ENET_QOS TX per-ch (297) */
    kPOWER_WakeupIrq_CommEnetQosRx    = COMM_ENET_QOS_RX_IRQn,   /*!< COMM ENET_QOS RX per-ch (298) */
    kPOWER_WakeupIrq_CommEnetTx       = COMM_ENET_TX_IRQn,       /*!< COMM ENET TX (299) */
    kPOWER_WakeupIrq_CommEnetRx       = COMM_ENET_RX_IRQn,       /*!< COMM ENET RX (300) */
    kPOWER_WakeupIrq_CommEnetOther    = COMM_ENET_OTHER_IRQn,    /*!< COMM ENET other (301) */
    kPOWER_WakeupIrq_CommEnet1588     = COMM_ENET_1588_IRQn,     /*!< COMM ENET 1588 timer (302) */
    kPOWER_WakeupIrq_CommFlexspiSlv   = COMM_FLEXSPI_SLV_IRQn,   /*!< COMM FlexSPI follower (303) */
    kPOWER_WakeupIrq_CommUsb0         = COMM_USB0_IRQn,          /*!< COMM USB0 (304) */
    kPOWER_WakeupIrq_CommUsbPhy       = COMM_USBPHY_IRQn,        /*!< COMM USBPHY (305) */
    kPOWER_WakeupIrq_CommUsb1         = COMM_USB1_IRQn,          /*!< COMM USB1 (306) */
    kPOWER_WakeupIrq_CommUsdhc0       = COMM_USDHC0_IRQn,        /*!< COMM uSDHC0 (307) */
    kPOWER_WakeupIrq_CommUsdhc1       = COMM_USDHC1_IRQn,        /*!< COMM uSDHC1 (308) */
    kPOWER_WakeupIrq_CommTenbaseTphy0 = COMM_TENBASET_PHY0_IRQn, /*!< COMM 10BASE-T PHY0 (310) */
    kPOWER_WakeupIrq_CommTenbaseTphy1 = COMM_TENBASET_PHY1_IRQn, /*!< COMM 10BASE-T PHY1 (312) */
    kPOWER_WakeupIrq_CommFreqme       = COMM_FREQME_IRQn,        /*!< COMM FREQME (314) */

    /* ----------------------------------------------------------------
     * MEDIA domain IRQ wakeup sources - CMC0 IRQ_WAKEUP_MASK (IRQn 315-333)
     * PD_MEDIA powered in Sleep and Deep Sleep.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupIrq_MediaTrdc        = MEDIA_TRDC_IRQn,        /*!< MEDIA TRDC (315) */
    kPOWER_WakeupIrq_MediaDcifCh0     = MEDIA_DCIF_CH0_IRQn,    /*!< MEDIA DCIF ch 0 (317) */
    kPOWER_WakeupIrq_MediaDcifCh1     = MEDIA_DCIF_CH1_IRQn,    /*!< MEDIA DCIF ch 1 (318) */
    kPOWER_WakeupIrq_MediaDcifCh2     = MEDIA_DCIF_CH2_IRQn,    /*!< MEDIA DCIF ch 2 (319) */
    kPOWER_WakeupIrq_MediaDcifCh3     = MEDIA_DCIF_CH3_IRQn,    /*!< MEDIA DCIF ch 3 (320) */
    kPOWER_WakeupIrq_MediaDcifCh4     = MEDIA_DCIF_CH4_IRQn,    /*!< MEDIA DCIF ch 4 (321) */
    kPOWER_WakeupIrq_MediaDcifCh5     = MEDIA_DCIF_CH5_IRQn,    /*!< MEDIA DCIF ch 5 (322) */
    kPOWER_WakeupIrq_MediaDcifCh6     = MEDIA_DCIF_CH6_IRQn,    /*!< MEDIA DCIF ch 6 (323) */
    kPOWER_WakeupIrq_MediaDcifCh7     = MEDIA_DCIF_CH7_IRQn,    /*!< MEDIA DCIF ch 7 (324) */
    kPOWER_WakeupIrq_MediaDcifCh8     = MEDIA_DCIF_CH8_IRQn,    /*!< MEDIA DCIF ch 8 (325) */
    kPOWER_WakeupIrq_MediaCsi         = MEDIA_CSI_IRQn,         /*!< MEDIA CSI (326) */
    kPOWER_WakeupIrq_MediaReformatter = MEDIA_REFORMATTER_IRQn, /*!< MEDIA Reformatter (327) */
    kPOWER_WakeupIrq_MediaIsi         = MEDIA_ISI_IRQn,         /*!< MEDIA ISI (328) */
    kPOWER_WakeupIrq_MediaTingpu      = MEDIA_TINGPU_IRQn,      /*!< MEDIA TinyGPU (329) */
    kPOWER_WakeupIrq_MediaJpegDec     = MEDIA_JPEGDEC_IRQn,     /*!< MEDIA JPEG decoder (330) */
    kPOWER_WakeupIrq_MediaMipiCsi     = MEDIA_MIPI_CSI_IRQn,    /*!< MEDIA MIPI CSI (331) */
    kPOWER_WakeupIrq_MediaMipiDsi     = MEDIA_MIPI_DSI_IRQn,    /*!< MEDIA MIPI DSI (332) */
    kPOWER_WakeupIrq_MediaFreqme      = MEDIA_FREQME_IRQn,      /*!< MEDIA FREQME (333) */

    /* ----------------------------------------------------------------
     * MAIN domain DMA wakeup sources - CMC1 DMA_WAKEUP_MASK
     * Triggered by a DMA transfer request (before the channel-completion IRQ).
     * Index = RM DMA wakeup source index (Chapter 4 Tables 16/17/18) - NOT an eDMA channel.
     * AUDIO_EDMA3 requests also route through CMC1 (indices 44-48).
     * Index 0-31 -> CMC1 DMA_WAKEUP_MASK_0; index 32-63 -> CMC1 DMA_WAKEUP_MASK_1.
     * ---------------------------------------------------------------- */
    /* Table 16 - MAIN_EDMA5 (HSP_ADC_0/1 and DAC) */
    kPOWER_WakeupMainDma_Adc0 = (0x10000000 | 0), /*!< HSP_ADC_0 FIFO0+1 (index 0) */
    kPOWER_WakeupMainDma_Adc1 = (0x10000000 | 1), /*!< HSP_ADC_1 FIFO0+1 (index 1) */
    kPOWER_WakeupMainDma_Dac  = (0x10000000 | 2), /*!< HSP_DAC (index 2) */
    /* Table 17 - MAIN_EDMA3 (HSP peripherals) */
    kPOWER_WakeupMainDma_Qtpm0   = (0x10000000 | 3),  /*!< HSP_QTPM_0 (index 3) */
    kPOWER_WakeupMainDma_FlexIo0 = (0x10000000 | 6),  /*!< HSP_FLEXIO_0 (index 6) */
    kPOWER_WakeupMainDma_FlexIo1 = (0x10000000 | 7),  /*!< HSP_FLEXIO_1 (index 7) */
    kPOWER_WakeupMainDma_FlexIo2 = (0x10000000 | 8),  /*!< HSP_FLEXIO_2 (index 8) */
    kPOWER_WakeupMainDma_Lpi2c0  = (0x10000000 | 9),  /*!< HSP_LPI2C_0 (index 9) */
    kPOWER_WakeupMainDma_Lpi2c1  = (0x10000000 | 10), /*!< HSP_LPI2C_1 (index 10) */
    kPOWER_WakeupMainDma_Lpspi0  = (0x10000000 | 13), /*!< HSP_LPSPI_0 (index 13) */
    kPOWER_WakeupMainDma_Lpspi1  = (0x10000000 | 14), /*!< HSP_LPSPI_1 (index 14) */
    kPOWER_WakeupMainDma_Lpspi2  = (0x10000000 | 15), /*!< HSP_LPSPI_2 (index 15) */
    kPOWER_WakeupMainDma_Lpspi3  = (0x10000000 | 16), /*!< HSP_LPSPI_3 (index 16) */
    kPOWER_WakeupMainDma_Lpspi4  = (0x10000000 | 17), /*!< HSP_LPSPI_4 (index 17) */
    kPOWER_WakeupMainDma_Lpuart0 = (0x10000000 | 18), /*!< HSP_LPUART_0 (index 18) */
    kPOWER_WakeupMainDma_Lpuart1 = (0x10000000 | 19), /*!< HSP_LPUART_1 (index 19) */
    kPOWER_WakeupMainDma_Lpuart2 = (0x10000000 | 20), /*!< HSP_LPUART_2 (index 20) */
    kPOWER_WakeupMainDma_Lpuart3 = (0x10000000 | 21), /*!< HSP_LPUART_3 (index 21) */
    kPOWER_WakeupMainDma_Lpuart4 = (0x10000000 | 22), /*!< HSP_LPUART_4 (index 22) */
    kPOWER_WakeupMainDma_Lpuart5 = (0x10000000 | 23), /*!< HSP_LPUART_5 (index 23) */
    kPOWER_WakeupMainDma_Gpio0   = (0x10000000 | 24), /*!< HSP_GPIO_0 (index 24) */
    kPOWER_WakeupMainDma_Gpio1   = (0x10000000 | 25), /*!< HSP_GPIO_1 (index 25) */
    kPOWER_WakeupMainDma_Gpio2   = (0x10000000 | 26), /*!< HSP_GPIO_2 (index 26) */
    kPOWER_WakeupMainDma_Gpio3   = (0x10000000 | 27), /*!< HSP_GPIO_3 (index 27) */
    kPOWER_WakeupMainDma_Gpio4   = (0x10000000 | 28), /*!< HSP_GPIO_4 (index 28) */
    /* Table 18 - AUDIO_EDMA3 (routes through CMC1) */
    kPOWER_WakeupMainDma_AudioMicfil = (0x10000000 | 44), /*!< AUDIO_MICFIL (index 44) */
    kPOWER_WakeupMainDma_AudioSai0   = (0x10000000 | 46), /*!< AUDIO_SAI_0 (index 46) */
    kPOWER_WakeupMainDma_AudioSai1   = (0x10000000 | 47), /*!< AUDIO_SAI_1 (index 47) */
    kPOWER_WakeupMainDma_AudioSai2   = (0x10000000 | 48), /*!< AUDIO_SAI_2 (index 48) */

    /* ----------------------------------------------------------------
     * WAKE domain DMA wakeup sources - CMC2 DMA_WAKEUP_MASK
     * Triggered by a DMA transfer request on WAKE_EDMA3 (before completion IRQ).
     * Index = RM DMA wakeup source index (Chapter 4 Table 19) - NOT an eDMA channel.
     * Index 31    -> CMC2 DMA_WAKEUP_MASK_0 bit 31.
     * Index 32-43 -> CMC2 DMA_WAKEUP_MASK_1 bits 0-11.
     * ---------------------------------------------------------------- */
    kPOWER_WakeupWakeDma_Lptmr0    = (0x20000000 | 31), /*!< WAKE_LPTMR_0 (index 31) */
    kPOWER_WakeupWakeDma_Lptmr1    = (0x20000000 | 32), /*!< WAKE_LPTMR_1 (index 32) */
    kPOWER_WakeupWakeDma_Qtpm      = (0x20000000 | 33), /*!< WAKE_QTPM (index 33) */
    kPOWER_WakeupWakeDma_Lpi2c0    = (0x20000000 | 34), /*!< WAKE_LPI2C_0 (index 34) */
    kPOWER_WakeupWakeDma_Lpi2c1    = (0x20000000 | 35), /*!< WAKE_LPI2C_1 (index 35) */
    kPOWER_WakeupWakeDma_Lpspi     = (0x20000000 | 36), /*!< WAKE_LPSPI (index 36) */
    kPOWER_WakeupWakeDma_Lpuart0   = (0x20000000 | 37), /*!< WAKE_LPUART_0 (index 37) */
    kPOWER_WakeupWakeDma_Lpuart1   = (0x20000000 | 38), /*!< WAKE_LPUART_1 (index 38) */
    kPOWER_WakeupWakeDma_Gpio      = (0x20000000 | 39), /*!< WAKE_GPIO (index 39) */
    kPOWER_WakeupWakeDma_Micfil    = (0x20000000 | 40), /*!< WAKE_MICFIL (index 40) */
    kPOWER_WakeupWakeDma_VbatLptmr = (0x20000000 | 42), /*!< VBAT_LPTMR (index 42) */
    kPOWER_WakeupWakeDma_VbatGpio  = (0x20000000 | 43), /*!< VBAT_GPIO (index 43) */
} power_wakeup_source_t;

/*!
 * @brief Run-mode regulator configuration bundle.
 */
typedef struct _power_run_regulators_config
{
    pmu_dcdc_config_t dcdc;
    pmu_ldo_vdd0v8_config_t ldo0V8;
    pmu_ldo_vdd1v8_config_t ldo1V8;
    pmu_ldo_vdda1v8_config_t ldoVdda;
    pmu_vdd_pmu_config_t vddPmu;
} power_run_regulators_config_t;

/*!
 * @brief RT2660 memory identifiers for MEMCON active-mode control.
 *
 * Encodes (sliceIndex << 8) | blockIndex.  Slice 0-11 map to
 * SYSCON__MEMCON_S0–S11.
 */
typedef enum _power_memory
{
    /* WAKE_SS */
    kPOWER_Mem_WakeSram        = (0U << 8U) | 0U, /*!< WAKE_SS SRAM (S0 B0) */
    kPOWER_Mem_WakeEdma3TcdRam = (1U << 8U) | 0U, /*!< WAKE eDMA3 TCD / MICFIL FIR (S1 B0) */

    /* COMPUTE_SS */
    kPOWER_Mem_ComputeSram01  = (2U << 8U) | 0U, /*!< SRAMCTL_0 Mem 0/1 (S2 B0) */
    kPOWER_Mem_ComputeSram23  = (2U << 8U) | 1U, /*!< SRAMCTL_0 Mem 2/3 (S2 B1) */
    kPOWER_Mem_ComputeSram4   = (2U << 8U) | 2U, /*!< SRAMCTL_0 Mem 4   (S2 B2) */
    kPOWER_Mem_ComputeSram5   = (2U << 8U) | 3U, /*!< SRAMCTL_0 Mem 5   (S2 B3) */
    kPOWER_Mem_ComputeSram6   = (2U << 8U) | 4U, /*!< SRAMCTL_1 Mem 0   (S2 B4) */
    kPOWER_Mem_ComputeSram7   = (2U << 8U) | 5U, /*!< SRAMCTL_1 Mem 1   (S2 B5) */
    kPOWER_Mem_ComputeSram8   = (2U << 8U) | 6U, /*!< SRAMCTL_2 Mem 0   (S2 B6) */
    kPOWER_Mem_ComputeSram9   = (2U << 8U) | 7U, /*!< SRAMCTL_2 Mem 1   (S2 B7) */
    kPOWER_Mem_LlcCacheBuffer = (2U << 8U) | 8U, /*!< LLC Cache buffer  (S2 B8) */
    /* S2 B9 - unused/reserved */
    kPOWER_Mem_Audio8Kb = (2U << 8U) | 10U, /*!< Audio SRAM 8KB    (S2 B10) */
    /* S2 B11 = PKC MEM, accessed via power_down_config_t.retainPkcMem only */

    /* M85 CPU (PD_CPU) */
    kPOWER_Mem_CpuICache     = (4U << 8U) | 0U, /*!< M85 I-Cache (S4 B0) */
    kPOWER_Mem_CpuDCacheData = (4U << 8U) | 1U, /*!< M85 D-Cache data (S4 B1) */
    kPOWER_Mem_CpuITCM       = (4U << 8U) | 2U, /*!< M85 ITCM (S4 B2) */
    kPOWER_Mem_CpuDTCM       = (4U << 8U) | 3U, /*!< M85 DTCM (S4 B3) */
    kPOWER_Mem_CpuDCacheTag  = (5U << 8U) | 0U, /*!< M85 D-Cache tag (S5 B0) */

    /* NPU (PD_NPU) */
    kPOWER_Mem_NpuWeightCache   = (6U << 8U) | 0U, /*!< NPU weight cache (S6 B0) */
    kPOWER_Mem_NpuResultBuffers = (7U << 8U) | 0U, /*!< NPU result buffers (S7 B0) */

    /* MEDIA_SS (PD_MEDIA) */
    kPOWER_Mem_MediaShared = (9U << 8U) | 0U, /*!< MEDIA_SS shared (S9 B0) */

    /* COMM_SS (PD_COMM) */
    kPOWER_Mem_CommShared = (10U << 8U) | 0U, /*!< COMM_SS ENET/ENET_QOS (S10 B0) */
    kPOWER_Mem_CommType2  = (11U << 8U) | 0U, /*!< COMM_SS uSDHC/USBHS/ENET (S11 B0) */
} power_memory_t;

/*!
 * @brief RT2660 subsystem root clock identifier.
 *
 * Each value is the bit index within POWERCON_SOC_CTRL.RCGCFG_ACTIVE.
 * Polarity: clearing a bit enables the root clock; setting it disables (gates) it.
 * Note: NPU has no separate RCGCFG_ACTIVE bit. The NPU lives inside the Compute
 * subsystem (CMPT_SS) and is gated by the COMPUTE_SS root clock (bit 0), shared
 * with CM85. Clock and power are not 1:1: bit 0 clocks both CM85 (PD_CPU) and
 * NPU (PD_NPU), which remain independent PDCON power domains.
 */
typedef enum _power_root_clock
{
    kPOWER_RootClock_COMPUTE_SS   = 0U, /*!< Compute subsystem (CMPT_SS): CM85 + NPU root clock - bit 0 */
    kPOWER_RootClock_MAIN_SS      = 1U, /*!< Main subsystem root clock - bit 1 */
    kPOWER_RootClock_WAKE_SS      = 2U, /*!< Wake subsystem root clock - bit 2 */
    kPOWER_RootClock_COMM_SS      = 3U, /*!< Communication subsystem root clock - bit 3 */
    kPOWER_RootClock_MEDIA_SS     = 4U, /*!< Media subsystem root clock - bit 4 */
    kPOWER_RootClock_AUDIO_SS     = 5U, /*!< Audio subsystem root clock - bit 5 */
    kPOWER_RootClock_WAKE_SS_1MHz = 6U, /*!< Wake subsystem 1 MHz root clock - bit 6 */
    kPOWER_RootClock_WAKE_SS_2MHz = 7U, /*!< Wake subsystem 2 MHz root clock - bit 7 */
} power_root_clock_t;

/*!
 * @brief RT2660 clock source identifier.
 *
 * Each value is the bit index within POWERCON_SOC_CTRL.CSRCCFG_ACTIVE.
 * Polarity: 0b = disable, 1b = enable (active-high, unlike RCGCFG_ACTIVE).
 * Modifying CSRCCFG_ACTIVE requires a P-Channel trigger (POWERCON_TriggerSocUpdate).
 */
typedef enum _power_clock_source
{
    kPOWER_ClockSource_LDOA_0V8  = 0U, /*!< LDOA 0.8 V supply enable - bit 0 */
    kPOWER_ClockSource_FRO192M   = 1U, /*!< Internal 192 MHz FRO - bit 1 */
    kPOWER_ClockSource_FRO12M    = 2U, /*!< Internal 12 MHz FRO - bit 2 */
    kPOWER_ClockSource_MAINPLL   = 3U, /*!< Main PLL - bit 3 */
    kPOWER_ClockSource_COREPLL   = 4U, /*!< Core PLL - bit 4 */
    kPOWER_ClockSource_SYSPLL    = 5U, /*!< System PLL - bit 5 */
    kPOWER_ClockSource_LDOQ_0V8  = 6U, /*!< LDOQ 0.8 V supply enable - bit 6 */
    kPOWER_ClockSource_SXOSC     = 7U, /*!< External crystal oscillator - bit 7 */
    kPOWER_ClockSource_FRO12M_LP = 8U, /*!< Low-power 12 MHz FRO (wake) - bit 8 */
} power_clock_source_t;

/*! @brief Callback type for run-mode clock frequency changes. */
typedef void (*power_clock_cb_t)(void);

/*!
 * @brief Active run mode, classified from the CPU core clock frequency.
 *
 * Returned by @ref POWER_GetCurrentRunMode.  The PMU pmuMode field cannot
 * distinguish HP from Normal run (both use pmuMode=0), so the run mode is
 * detected from the CGU MAIN root clock frequency instead.
 */
typedef enum _power_run_mode
{
    kPOWER_RunModeHp     = 0U, /*!< Over Drive Run    (~1 GHz,  FBB, 0.9 V). */
    kPOWER_RunModeNormal = 1U, /*!< Normal Drive Run  (~800 MHz, FBB, 0.8 V). */
    kPOWER_RunModeLp     = 2U, /*!< Low Performance Run (~600 MHz, ZBB, 0.8 V). */
} power_run_mode_t;

/*!
 * @brief RT2660 software-controllable power domain identifiers.
 *
 * These map directly to PDCON domain indices.  Only these four domains
 * are SW-triggerable on RT2660.
 */
typedef enum _power_domain
{
    kPOWER_DomainWake  = 0U, /*!< PD_WAKE - wake subsystem */
    kPOWER_DomainMain  = 1U, /*!< PD_MAIN - main subsystem */
    kPOWER_DomainCpu   = 2U, /*!< PD_CPU - M85 compute domain */
    kPOWER_DomainNpu   = 3U, /*!< PD_NPU - neural processing unit */
    kPOWER_DomainMedia = 4U, /*!< PD_MEDIA - media subsystem */
    kPOWER_DomainComm  = 5U, /*!< PD_COMM - communication subsystem */
} power_domain_t;

/*!
 * @brief Sleep config.
 *
 * Wakeup sources are configured separately via POWER_EnableWakeupSource().
 * PD_MAIN, PD_WAKE, PD_BAT always ON.  PMU stays in HP mode (same voltage as
 * the preceding run mode, FBB disabled for Sleep entry).
 *
 * Fields marked [EXPERIMENTAL] may be removed or renamed in a future release.
 */
typedef struct _power_sleep_config
{
    /* Power domain events (PDCON.PDSLPCFG).
     * RT2660 does not integrate PDCON domain retention (omitted for die size), so the only
     * valid values are kPDCON_EventNoneOrActive (On) and kPDCON_EventPowerOff.
     * kPDCON_EventRetention must not be used on RT2660. */
    pdcon_event_t setCpuDomainEvent;   /*!< PD_CPU:   On (NoneOrActive) or PowerOff */
    pdcon_event_t setNpuDomainEvent;   /*!< PD_NPU:   On (NoneOrActive) or PowerOff */
    pdcon_event_t setCommDomainEvent;  /*!< PD_COMM:  On (NoneOrActive) or PowerOff */
    pdcon_event_t setMediaDomainEvent; /*!< PD_MEDIA: On (NoneOrActive) or PowerOff */

    /* [EXPERIMENTAL] PMU analog state written to POWERCON_SOC_CTRL.PMUCFG_STBY.
     * In Sleep the SSC P-Channel is not triggered, so these do not cause actual
     * PMU analog transitions.  Defaults match the preceding PMUCFG_ACTIVE value. */
    uint8_t setPmuMode;           /*!< [EXPERIMENTAL] PMU mode bits[22:20]: 0=HP, 2=LP, 3=RET */
    pmu_dcdc_mode_t setDcdcMode;  /*!< [EXPERIMENTAL] DCDC mode bit[7] */
    uint8_t setCoreLevel;         /*!< [EXPERIMENTAL] VDD_CORE DAC code bits[19:15] */
    pmu_ldo_mode_t setLdo0V8Mode; /*!< [EXPERIMENTAL] LDO_VDD_0V8 bits[9:8] */
    pmu_ldo_mode_t setLdo1V8Mode; /*!< [EXPERIMENTAL] LDO_VDD_1V8 bits[11:10] */
    uint8_t setLdoVdda1V8Mode;    /*!< [EXPERIMENTAL] LDO_VDDA_1V8 bits[13:12]: 0=off, 1=HP, 2=LP, 3=ULP */
    bool enableHqref;             /*!< [EXPERIMENTAL] High-quality reference enable bit[6] */
    uint8_t enableSensors;        /*!< [EXPERIMENTAL] Sensor enable mask bits[5:0]:
                                    [0]=Temp, [1]=0V8, [2]=1V8, [3]=Vdda, [4]=Core, [5]=PMU */

    /* [EXPERIMENTAL] Clock source standby enable (POWERCON_SOC_CTRL.CSRCCFG_STBY).
     * true  = keep source enabled in standby (sets the corresponding bit).
     * false = allow source to turn off in standby (clears the corresponding bit).
     * Register polarity: bit=1 means source enabled in standby.
     * Default: all true (no gating). */
    bool enableLdoa0V8ClockSource;  /*!< [EXPERIMENTAL] LDOA 0V8 supply (bit 0) */
    bool enableFro192MClockSource;  /*!< [EXPERIMENTAL] FRO 192 MHz (bit 1) */
    bool enableFro12MClockSource;   /*!< [EXPERIMENTAL] FRO 12 MHz (bit 2) */
    bool enableMainPllClockSource;  /*!< [EXPERIMENTAL] Main PLL (bit 3) */
    bool enableCorePllClockSource;  /*!< [EXPERIMENTAL] Core PLL (bit 4) */
    bool enableSysPllClockSource;   /*!< [EXPERIMENTAL] System PLL (bit 5) */
    bool enableLdoq0V8ClockSource;  /*!< [EXPERIMENTAL] LDOQ 0V8 supply (bit 6) */
    bool enableSxoscClockSource;    /*!< [EXPERIMENTAL] SXOSC (bit 7) */
    bool enableFro12MLpClockSource; /*!< [EXPERIMENTAL] FRO 12 MHz LP (bit 8) */

    /* [EXPERIMENTAL] Root clock standby enable (POWERCON_SOC_CTRL.RCGCFG_STBY).
     * true  = keep root clock on in standby (sets  the corresponding bit).
     * false = gate root clock in standby    (clears the corresponding bit).
     * Register polarity: bit=1 means clock ENABLED (active-high).
     * Default for Sleep: all true (no root clock gating during shallow sleep). */
    bool enableComputeRootClock; /*!< [EXPERIMENTAL] COMPUTE_SS root clock (bit 0) */
    bool enableMainRootClock;    /*!< [EXPERIMENTAL] MAIN_SS root clock (bit 1) */
    bool enableWakeRootClock;    /*!< [EXPERIMENTAL] WAKE_SS root clock (bit 2) */
    bool enableCommRootClock;    /*!< [EXPERIMENTAL] COMM_SS root clock (bit 3) */
    bool enableMediaRootClock;   /*!< [EXPERIMENTAL] MEDIA_SS root clock (bit 4) */
    bool enableAudioRootClock;   /*!< [EXPERIMENTAL] AUDIO_SS root clock (bit 5) */
    bool enableWake1MRootClock;  /*!< [EXPERIMENTAL] WAKE_1M root clock (bit 6) */
    bool enableWake2MRootClock;  /*!< [EXPERIMENTAL] WAKE_2M root clock (bit 7) */

    /* [EXPERIMENTAL] Memory standby modes (MEMCON_SLICE.MEM_SLPCFG).
     * Active/Retention/PowerDown all valid in Sleep. */
    memcon_power_mode_t setWakeSramMode; /*!< [EXPERIMENTAL] Wake SRAM 8KB (S0 B0) */
    memcon_power_mode_t setOcramMode;    /*!< [EXPERIMENTAL] OCRAM0 64KB (S2 B0–B7); all blocks set together */
    memcon_power_mode_t setLlcCacheMode; /*!< [EXPERIMENTAL] LLC cache 8KB (S2 B8) */
    memcon_power_mode_t setAudio8KbMode; /*!< [EXPERIMENTAL] Audio SRAM 8KB (S2 B10) */
    memcon_power_mode_t setM85TcmMode;   /*!< [EXPERIMENTAL] M85 CPU TCM + cache (S4 B0–B3, S5 B0) */
    memcon_power_mode_t setNpuTcmMode;   /*!< [EXPERIMENTAL] NPU TCM (S6 B0, S7 B0) */
    memcon_power_mode_t setCommTcmMode;  /*!< [EXPERIMENTAL] COMM SRAM (S10 B0, S11 B0) */
    memcon_power_mode_t setMediaTcmMode; /*!< [EXPERIMENTAL] Media SRAM (S9 B0) */
} power_sleep_config_t;

/*!
 * @brief Deep Sleep config.
 *
 * PD_MAIN, PD_WAKE, PD_BAT always ON.
 * The SSC P-Channel IS triggered in Deep Sleep, so PMU analog fields cause
 * actual hardware state transitions.
 *
 * @note RT2660 does not integrate PDCON domain retention (omitted for die size).
 *       The SW-controllable domain events below are only ever On
 *       (kPDCON_EventNoneOrActive) or PowerOff (kPDCON_EventPowerOff); Deep Sleep
 *       power saving comes from PMU analog/clock state and from powering domains
 *       fully off, not from domain retention.
 *
 * Fields marked [EXPERIMENTAL] may be removed or renamed in a future release.
 *
 * @note Active mode (@ref kMEMCON_PowerModeNormal) is NOT valid for memory
 *       fields in Deep Sleep.  Only Retention and PowerDown are allowed.
 */
typedef struct _power_deep_sleep_config
{
    /* Power domain events (PDCON.PDSLPCFG).
     * RT2660 has no domain retention: use kPDCON_EventNoneOrActive (On) or
     * kPDCON_EventPowerOff only. */
    pdcon_event_t setCpuDomainEvent;   /*!< PD_CPU:   On (NoneOrActive) or PowerOff */
    pdcon_event_t setNpuDomainEvent;   /*!< PD_NPU:   On (NoneOrActive) or PowerOff */
    pdcon_event_t setCommDomainEvent;  /*!< PD_COMM:  On (NoneOrActive) or PowerOff */
    pdcon_event_t setMediaDomainEvent; /*!< PD_MEDIA: On (NoneOrActive) or PowerOff */

    /* [EXPERIMENTAL] PMU analog state (POWERCON_SOC_CTRL.PMUCFG_STBY).
     * SSC P-Channel IS triggered; these fields drive actual analog transitions. */
    uint8_t setPmuMode;           /*!< [EXPERIMENTAL] PMU mode bits[22:20]: 0=HP, 2=LP, 3=RET */
    pmu_dcdc_mode_t setDcdcMode;  /*!< [EXPERIMENTAL] DCDC mode bit[7] */
    uint8_t setCoreLevel;         /*!< [EXPERIMENTAL] VDD_CORE DAC code bits[19:15] */
    pmu_ldo_mode_t setLdo0V8Mode; /*!< [EXPERIMENTAL] LDO_VDD_0V8 bits[9:8] */
    pmu_ldo_mode_t setLdo1V8Mode; /*!< [EXPERIMENTAL] LDO_VDD_1V8 bits[11:10] */
    uint8_t setLdoVdda1V8Mode;    /*!< [EXPERIMENTAL] LDO_VDDA_1V8 bits[13:12]: 0=off, 1=HP, 2=LP, 3=ULP */
    bool enableHqref;             /*!< [EXPERIMENTAL] High-quality reference enable bit[6] */
    uint8_t enableSensors;        /*!< [EXPERIMENTAL] Sensor enable mask bits[5:0]:
                                    [0]=Temp, [1]=0V8, [2]=1V8, [3]=Vdda, [4]=Core, [5]=PMU */

    /* [EXPERIMENTAL] Clock source standby enable (POWERCON_SOC_CTRL.CSRCCFG_STBY).
     * true  = keep source enabled; false = allow source to turn off.
     * Register polarity: bit=1 means source enabled in standby.
     * Default: all false (all sources gated). */
    bool enableLdoa0V8ClockSource;  /*!< [EXPERIMENTAL] LDOA 0V8 supply (bit 0) */
    bool enableFro192MClockSource;  /*!< [EXPERIMENTAL] FRO 192 MHz (bit 1) */
    bool enableFro12MClockSource;   /*!< [EXPERIMENTAL] FRO 12 MHz (bit 2) */
    bool enableMainPllClockSource;  /*!< [EXPERIMENTAL] Main PLL (bit 3) */
    bool enableCorePllClockSource;  /*!< [EXPERIMENTAL] Core PLL (bit 4) */
    bool enableSysPllClockSource;   /*!< [EXPERIMENTAL] System PLL (bit 5) */
    bool enableLdoq0V8ClockSource;  /*!< [EXPERIMENTAL] LDOQ 0V8 supply (bit 6) */
    bool enableSxoscClockSource;    /*!< [EXPERIMENTAL] SXOSC (bit 7) */
    bool enableFro12MLpClockSource; /*!< [EXPERIMENTAL] FRO 12 MHz LP (bit 8) */

    /* [EXPERIMENTAL] Root clock standby enable (POWERCON_SOC_CTRL.RCGCFG_STBY).
     * true  = keep root clock on in standby (sets  the corresponding bit).
     * false = gate root clock in standby    (clears the corresponding bit).
     * Register polarity: bit=1 means clock ENABLED (active-high).
     * Default for Deep Sleep: only enableWake1MRootClock and enableWake2MRootClock are true; all others false
     * (POWERCON wakeup-detection logic requires the 1M/2M WAKE clocks to run). */
    bool enableComputeRootClock; /*!< [EXPERIMENTAL] COMPUTE_SS root clock (bit 0) */
    bool enableMainRootClock;    /*!< [EXPERIMENTAL] MAIN_SS root clock (bit 1) */
    bool enableWakeRootClock;    /*!< [EXPERIMENTAL] WAKE_SS root clock (bit 2) */
    bool enableCommRootClock;    /*!< [EXPERIMENTAL] COMM_SS root clock (bit 3) */
    bool enableMediaRootClock;   /*!< [EXPERIMENTAL] MEDIA_SS root clock (bit 4) */
    bool enableAudioRootClock;   /*!< [EXPERIMENTAL] AUDIO_SS root clock (bit 5) */
    bool enableWake1MRootClock;  /*!< [EXPERIMENTAL] WAKE_1M root clock (bit 6); keep true for wakeup logic */
    bool enableWake2MRootClock;  /*!< [EXPERIMENTAL] WAKE_2M root clock (bit 7); keep true for wakeup logic */

    /* [EXPERIMENTAL] Memory standby modes (MEMCON_SLICE.MEM_SLPCFG).
     * Active (kMEMCON_PowerModeNormal) is NOT valid in Deep Sleep. */
    memcon_power_mode_t setWakeSramMode; /*!< [EXPERIMENTAL] Wake SRAM 8KB (S0 B0) */
    memcon_power_mode_t setOcramMode;    /*!< [EXPERIMENTAL] OCRAM0 64KB (S2 B0–B7); all blocks set together */
    memcon_power_mode_t setLlcCacheMode; /*!< [EXPERIMENTAL] LLC cache 8KB (S2 B8) */
    memcon_power_mode_t setAudio8KbMode; /*!< [EXPERIMENTAL] Audio SRAM 8KB (S2 B10) */
    memcon_power_mode_t setM85TcmMode;   /*!< [EXPERIMENTAL] M85 CPU TCM + cache (S4 B0–B3, S5 B0) */
    memcon_power_mode_t setNpuTcmMode;   /*!< [EXPERIMENTAL] NPU TCM (S6 B0, S7 B0) */
    memcon_power_mode_t setCommTcmMode;  /*!< [EXPERIMENTAL] COMM SRAM (S10 B0, S11 B0) */
    memcon_power_mode_t setMediaTcmMode; /*!< [EXPERIMENTAL] Media SRAM (S9 B0) */
} power_deep_sleep_config_t;

/*!
 * @brief Power Down config.
 *
 * Domain events and PMU state are fixed (all SW-controllable domains power-off;
 * pmuMode=RET, DCDC off).
 *
 * Fields marked [EXPERIMENTAL] may be removed or renamed in a future release.
 *
 * @note POWER_EnterPowerDown() does NOT return.  Wakeup triggers a fast PoR.
 */
typedef struct _power_down_config
{
    uint32_t retainOcram0KB; /*!< OCRAM0 kilobytes to retain (0-64).  0 = no retention. */
    bool retainPkcMem;       /*!< Retain PKC MEM 4KB (S2 B11). */
    bool retainLlcCache;     /*!< [EXPERIMENTAL] Retain LLC cache 8KB (S2 B8). */
    bool retainAudio8Kb;     /*!< [EXPERIMENTAL] Retain Audio SRAM 8KB (S2 B10). */
} power_down_config_t;

/*!
 * @brief Deep Power Down config - covers both DPD1 and DPD2 variants.
 *
 * DPD1 (retainVbatSram=true):  VBAT_SS powered; 2 KB VBAT SRAM retained.
 * DPD2 (retainVbatSram=false): VBAT_SS off; PMIC_CTRL asserted (VDD_PMU removed).
 *
 * @note This function does NOT return.  Wakeup via PMIC restoring VDD_PMU.
 */
typedef struct _power_deep_power_down_config
{
    bool retainVbatSram; /*!< true=DPD1 (VBAT_SS powered, SRAM retained), false=DPD2 (PMIC_CTRL asserted). */
} power_deep_power_down_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialisation
 * @{
 */

/*!
 * @brief Fill power_policy_config_t with hardware reset defaults.
 *
 * All CMC and SSC steps set to Handshake mode; CSSI enabled and unlocked;
 * handshakeRouting set to NULL (POWER_SetPolicy will apply POR-default routing).
 *
 * @param config  Pointer to config struct to populate.  Must not be NULL.
 */
void POWER_GetDefaultPolicyConfig(power_policy_config_t *config);

/*!
 * @brief Applies the power management policy: active/low-power baseline for
 *        POWERCON, PDCON, and MEMCON, plus the NPU/Media/Comm domain and
 *        active-mode clock source state.
 *
 * Enables POWERCON, PDCON, and MEMCON function clocks; applies SoC handshake
 * routing (NULL = POR defaults, non-NULL = *config->handshakeRouting); configures
 * CMC/SSC step modes and CSSI; sets the standby-gating baseline (XMC_STBY_MASK);
 * initialises PDCON domain trigger config; enables active-mode clock sources 0-8;
 * brings the NPU/Media/Comm domains to kPDCON_EventNoneOrActive if not already
 * there (idempotent); initialises all MEMCON slices to their default active
 * states; initialises SW wakeup masks to all-masked.
 *
 * Safe to call more than once (e.g. to apply a different handshakeRouting later).
 * No ordering constraint relative to BOARD_InitBootClocks() -- the domain-enable
 * step runs before the MEMCON slice writes internally, so a MEMCON slice is
 * never touched before its hosting domain (NPU/Media/Comm) is powered active.
 *
 * @param config  Pointer to policy configuration. Must not be NULL.
 *                Call POWER_GetDefaultPolicyConfig() first to populate defaults,
 *                then adjust fields as needed before passing to this function.
 */
void POWER_SetPolicy(const power_policy_config_t *config);

#if MCUX_POWER_PF9453_SUPPLY
/*!
 * @brief Brings up the external PF9453 PMIC that supplies VDD_CORE (BUCK2). PMIC build only.
 *
 * Creates the internal PF9453 handle from the board-supplied I2C transport and performs a one-shot
 * BUCK2 bring-up (enable in ACTIVE/STANDBY, run 0.9 V, standby 0.65 V, DVS ramp), then arms the
 * internal ready flag so subsequent run-mode DVS / standby-target changes drive the PMIC.
 *
 * MUST be called before the board's boot-clock setup (which ramps the core to HP and needs BUCK2
 * already at 0.9 V) — i.e. as the first step of board bring-up, before the clock tree is programmed.
 * The I2C send/receive callbacks in @p config must be non-NULL (asserted).
 *
 * @param config  Pointer to the external-supply I2C transport config. Must not be NULL.
 */
void POWER_InitExtSupply(const power_ext_supply_config_t *config);
#endif

/*!
 * @brief Fill power_handshake_routing_config_t with POR-default routing values.
 *
 * All HSK_SEL fields are set to 0 (hardware reset default).
 * All domainHsk entries are set to 0 (no explicit handshake units).
 *
 * @param config  Pointer to config struct to populate.  Must not be NULL.
 */
void POWER_GetDefaultHandshakeRoutingConfig(power_handshake_routing_config_t *config);

/*!
 * @brief Apply the init-time SoC handshake routing configuration.
 *
 * Writes POWERCON HSK_SEL registers and PDCON HSKCTRL for all six domains.
 * Must be called after POWER_InitStepCtrl() and before the first standby entry.
 * Call with POR-default config (from POWER_GetDefaultHandshakeRoutingConfig()) for the
 * standard routing, or customize fields for non-default routing.
 *
 * @param config  Pointer to handshake routing config.  Must not be NULL.
 */
void POWER_SetHandshakeRouting(const power_handshake_routing_config_t *config);

/*! @} */

/*!
 * @name Wakeup Source Control
 * @{
 */

/*!
 * @brief Accumulates a wakeup source into the driver-private SW state.
 *
 * No register access; registers are written inside POWER_Enter*() via
 * POWER_ApplyWakeupSources().  State persists across Sleep/Deep Sleep entries.
 *
 * @param source  Encoded wakeup source.  Construct with @ref POWER_WAKEUP_IRQ,
 *                @ref POWER_WAKEUP_MAIN_DMA, or @ref POWER_WAKEUP_WAKE_DMA.
 */
void POWER_EnableWakeupSource(power_wakeup_source_t source);

/*!
 * @brief Removes a wakeup source from the driver-private SW state.
 *
 * @param source  Encoded wakeup source, same value as passed to
 *                @ref POWER_EnableWakeupSource.
 */
void POWER_DisableWakeupSource(power_wakeup_source_t source);

/*!
 * @brief Masks all accumulated wakeup sources (IRQ, DMA, debug).
 *
 * Call before re-configuring the wakeup source between consecutive standby entries.
 */
void POWER_ClearAllWakeupSources(void);

/*!
 * @brief Flushes the accumulated SW wakeup masks to the CMC0/1/2 hardware registers.
 *
 * Writes each driver-private shadow mask to the CMC that owns it on RT2660:
 *   - CMC0 IRQ_WAKEUP_MASK  <- IRQ wakeup shadow (CPU / M85 core)
 *   - CMC1 DMA_WAKEUP_MASK  <- MAIN-domain DMA wakeup shadow
 *   - CMC2 DMA_WAKEUP_MASK  <- WAKE-domain DMA wakeup shadow
 *
 * This is called automatically inside every POWER_Enter*() before WFI, so an
 * application that always enters low power through those APIs does not need to
 * call it.  It is exposed for callers that arm wakeup sources ahead of a bare
 * @c __WFI() outside the POWER_Enter*() paths, or that want the CMC mask
 * registers written immediately after POWER_EnableWakeupSource() /
 * POWER_DisableWakeupSource() (e.g. for inspection).  The function is idempotent
 * — it rewrites all CMC masks from the shadow arrays — so an extra call before a
 * POWER_Enter*() is harmless.
 */
void POWER_ApplyWakeupSources(void);

/*! @} */

/*!
 * @name Active Mode Control
 * @{
 */

/*!
 * @brief Software-triggered power domain state change during active operation.
 *
 * @param domain  Target power domain. See @ref power_domain_t.
 * @param event   Target event. See @ref pdcon_event_t. RT2660 does not integrate PDCON
 *                domain retention, so use kPDCON_EventNoneOrActive (On) or
 *                kPDCON_EventPowerOff only; kPDCON_EventRetention must not be used.
 * @retval kStatus_Success  Transition completed.
 */
status_t POWER_SetDomainRunMode(power_domain_t domain, pdcon_event_t event);

/*!
 * @brief Set SRAM block active-mode power state and apply immediately.
 *
 * @param mem   Memory identifier.  See @ref power_memory_t.
 * @param mode  Target power mode.  See @ref memcon_power_mode_t.
 * @retval kStatus_Success            Configuration applied.
 * @retval kStatus_InvalidArgument    Memory does not support SW trigger.
 */
status_t POWER_SetMemoryRunMode(power_memory_t mem, memcon_power_mode_t mode);

/*!
 * @brief Enable a subsystem root clock during active mode.
 *
 * RMW clears the corresponding bit in POWERCON_SOC_CTRL.RCGCFG_ACTIVE.
 * RCGCFG_ACTIVE uses active-low polarity: 0b=enables, 1b=disables.
 * Direct register write - no P-Channel trigger required.
 *
 * @param ss  Subsystem root clock identifier.
 */
void POWER_EnableRunRootClock(power_root_clock_t ss);

/*!
 * @brief Disable a subsystem root clock during active mode.
 *
 * RMW sets the corresponding bit in POWERCON_SOC_CTRL.RCGCFG_ACTIVE.
 * Caller MUST ensure no active consumer depends on this root clock.
 * Direct register write - no P-Channel trigger required.
 *
 * @param ss  Subsystem root clock identifier.
 */
void POWER_DisableRunRootClock(power_root_clock_t ss);

/*!
 * @brief Enable a clock source during active mode via POWERCON P-Channel.
 *
 * Sets the corresponding bit in CSRCCFG_ACTIVE (1b=enables, 0b=disables).
 * Read-modify-write, then trigger SOC P-Channel update and poll for completion.
 * Active-high polarity - opposite of RCGCFG_ACTIVE.
 *
 * @param src  Clock source bit index (@ref power_clock_source_t).
 */
void POWER_EnableRunClockSource(power_clock_source_t src);

/*!
 * @brief Disable a clock source during active mode via POWERCON P-Channel.
 *
 * Clears the corresponding bit in CSRCCFG_ACTIVE (1b=enables, 0b=disables).
 * Caller MUST ensure no active consumer uses this source.
 * Do NOT call while the CMC FSM is active.
 *
 * @param src  Clock source bit index (@ref power_clock_source_t).
 */
void POWER_DisableRunClockSource(power_clock_source_t src);

/*!
 * @brief Apply PMU regulator config and synchronize PMUCFG_ACTIVE through
 *        POWERCON P-channel handshake.
 */
void POWER_SetRunRegulatorsConfig(const power_run_regulators_config_t *config);

/*!
 * @brief Assert or deassert the PMIC standby request while the chip is in Run mode.
 *
 * Writes PMICCFG_ACTIVE: enable=true sets PMIC_MODE[1:0]=1 (standby request asserted);
 * enable=false clears the field (no standby request).
 * Takes effect immediately - no P-Channel trigger is required.
 *
 * @param enable  true = assert PMIC standby request; false = deassert.
 */
void POWER_EnableRunPmicStandbyRequest(bool enable);

/*!
 * @brief Switch to HP run mode (VDD_CORE=0.9 V, FBB, CM85 up to 1 GHz).
 *
 * Determines the current run mode from hardware body-bias state, applies the
 * correct voltage/clock ordering (raises voltage before calling @p clockCb when
 * coming from a lower-voltage mode), then applies HP regulator settings and FBB.
 *
 * @param clockCb  Callback invoked at the point in the sequence where CCM
 *                 frequencies should be changed to HP values.  May be NULL.
 */
void POWER_EnterHpRun(power_clock_cb_t clockCb);

/*!
 * @brief Switch to Normal run mode (VDD_CORE=0.8 V, FBB, CM85 up to 800 MHz).
 *
 * @param clockCb  Callback invoked at the point where CCM frequencies should
 *                 be changed to Normal run values.  May be NULL.
 */
void POWER_EnterNormalRun(power_clock_cb_t clockCb);

/*!
 * @brief Switch to LP run mode (VDD_CORE=0.8 V, ZBB, CM85 up to 600 MHz).
 *
 * @param clockCb  Callback invoked at the point where CCM frequencies should
 *                 be changed to LP values.  May be NULL.
 */
void POWER_EnterLpRun(power_clock_cb_t clockCb);

/*!
 * @brief Get the current active run mode.
 *
 * Classifies the run mode from the CPU core clock frequency
 * (`CLOCK_GetRootClockFreq(kCLOCK_Root_CGU_MAIN_ROOTCLK)`): >= 900 MHz -> HP,
 * >= 700 MHz -> Normal, otherwise -> LP.  Thresholds carry margin because
 * Normal Run is typically ~792 MHz rather than an exact 800 MHz.
 *
 * Reflects the instantaneous core frequency, so query it from a settled
 * operating point (not mid-transition, and not while the CPU is transiently
 * parked on a low-frequency source).
 *
 * @return The current @ref power_run_mode_t.
 */
power_run_mode_t POWER_GetCurrentRunMode(void);

/*! @} */

/*!
 * @name Standby Entry
 * @{
 */

/*!
 * @brief Configure whether the CSSI/ELS LP handshake is bypassed on standby entry.
 *
 * The full production handshake communicates with the CSSI (S110 / ELE) security
 * subsystem via MU before each low-power entry.  CSSI must grant permission before
 * the entry sequence proceeds; if CSSI denies, POWER_EnterSleep() and
 * POWER_EnterDeepSleep() return @ref kStatus_Fail.
 *
 * @warning TEST ONLY - bypass mode is the default (bypass=true) because CSSI
 *          firmware is not yet available for early bring-up testing.  Call
 *          POWER_SetCssiLpHandshakeBypass(false) before production validation
 *          once CSSI firmware is ready.  Do NOT ship products with bypass=true.
 *
 * Communication with CSSI uses the Messaging Unit (MU).  The full handshake
 * sequence will be added here when the CSSI firmware MU protocol is finalised.
 *
 * @param bypass  true  = skip CSSI handshake entirely (TEST ONLY, default).
 *                false = perform the full MU + MODCON handshake.
 */
void POWER_SetCssiLpHandshakeBypass(bool bypass);

/*!
 * @brief Enter Sleep mode; returns after wakeup.
 *
 * @note PLL clock outputs: if MAINPLL or SYSPLL was kept enabled in standby
 *       (config->enableMainPllClockSource / config->enableSysPllClockSource = true), only the DIV4 output of each
 *       PLL is automatically re-enabled by hardware on wakeup.  All other outputs
 *       (DIV5, DIV8, DIV10, DIV20, PFD0/1/2) remain gated.  The caller must
 *       re-enable any required non-DIV4 PLL outputs after this function returns.
 *
 * @param config  Pointer to sleep configuration.
 * @retval kStatus_Success         Wakeup occurred normally.
 * @retval kStatus_InvalidArgument config is NULL.
 * @retval kStatus_Fail            CSSI denied LP entry (bypass=false only).
 */
status_t POWER_EnterSleep(const power_sleep_config_t *config);

/*!
 * @brief Enter Deep Sleep mode; returns after wakeup (~150 µs restore).
 *
 * WAKE-domain LPUART clocks are gated during Deep Sleep.  If a WAKE-domain
 * LPUART is active, the caller must stop transmitting and deinitialize the
 * peripheral before entry, and reinitialize it after return.
 *
 * @pre The M85 CPU core clock (SYSCON CCM root clock 1) must be sourced from
 *      COREPLL before calling this function.  MAINPLL and SYSPLL are typically
 *      gated during Deep Sleep standby; running the CPU from a MAINPLL/SYSPLL-
 *      derived clock at WFI will cause the CPU to stall when those PLLs are
 *      gated by POWERCON.  COREPLL frequency is preserved across Deep Sleep
 *      without a reset, so no CPU clock restoration is needed after return.
 *
 * @note PLL clock outputs: on wakeup from Deep Sleep, only the DIV4 output of
 *       MAINPLL and SYSPLL is automatically re-enabled by hardware.  All other
 *       outputs (DIV5, DIV8, DIV10, DIV20, PFD0/1/2) remain gated.  The caller
 *       must re-enable any required non-DIV4 PLL outputs after this function
 *       returns before using peripherals that depend on them.
 *
 * @note This function returns only when M85 TCM and stack memory were retained
 *       (setM85TcmMode = kMEMCON_PowerModeRetention).  If TCM was powered off the
 *       wakeup path is a PoR reboot and this function never returns.
 *
 * @param config  Pointer to deep sleep configuration.
 * @retval kStatus_Success         Wakeup occurred normally.
 * @retval kStatus_InvalidArgument config is NULL.
 * @retval kStatus_Fail            CSSI denied LP entry (bypass=false only).
 */
status_t POWER_EnterDeepSleep(const power_deep_sleep_config_t *config);

/*!
 * @brief Enter Power Down mode.
 *
 * On successful entry the CPU does not return: wakeup triggers a fast PoR.
 * Returns @ref kStatus_Fail before executing WFI if the CSSI/ELS LP handshake
 * denies entry (only possible when bypass is disabled via
 * @ref POWER_SetCssiLpHandshakeBypass). In the default (bypass=true) state
 * this function always proceeds to WFI.
 *
 * @param config  Pointer to power down configuration.  Must not be NULL.
 * @retval kStatus_Fail  CSSI denied LP entry (bypass=false only).
 */
status_t POWER_EnterPowerDown(const power_down_config_t *config);

/*!
 * @brief Enter Deep Power Down mode.
 *
 * On successful entry the CPU does not return: wakeup via PMIC restoring
 * VDD_PMU triggers a PoR.  Configure VBATCON wakeup latches directly before
 * calling this function.
 * Returns @ref kStatus_Fail before executing WFI if the CSSI/ELS LP handshake
 * denies entry (only possible when bypass is disabled via
 * @ref POWER_SetCssiLpHandshakeBypass).
 *
 * @param config  Pointer to deep power down configuration.  Must not be NULL.
 * @retval kStatus_Fail  CSSI denied LP entry (bypass=false only).
 */
status_t POWER_EnterDeepPowerDown(const power_deep_power_down_config_t *config);

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* FSL_POWER_H */
