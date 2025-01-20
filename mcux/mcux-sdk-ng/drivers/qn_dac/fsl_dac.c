/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @addtogroup DAC
 * @{
 */
#include "fsl_dac.h"
#include "fsl_clock.h"
#include "fsl_reset.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.qn_dac"
#endif

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
/*!
 * @brief Gets the instance from the base address to be used to gate or ungate the module clock
 *
 * @param base DAC peripheral base address
 *
 * @return The DAC instance
 */
static uint32_t DAC_GetInstance(DAC_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! @brief Pointers to DAC bases for each instance. */
static DAC_Type *const s_dacBases[] = DAC_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to DAC clocks for each instance. */
static const clock_ip_name_t s_dacClocks[] = DAC_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
/*! @brief Pointers to DAC resets for each instance. */
static const reset_ip_name_t s_dacResets[] = DAC_RSTS_N;
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t DAC_GetInstance(DAC_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < FSL_FEATURE_SOC_DAC_COUNT; instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_dacBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < FSL_FEATURE_SOC_DAC_COUNT);

    return instance;
}
/*!
 * brief Initializes the DAC with configuration.
 *
 * param base DAC peripheral base address.
 * param config pointer to configuration structure
 * return none
 */
void DAC_Init(DAC_Type *base, const dac_config_t *config)
{
    assert(config != NULL);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Enable the clock. */
    CLOCK_EnableClock(s_dacClocks[DAC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if !(defined(FSL_SDK_DISABLE_DRIVER_RESET_CONTROL) && FSL_SDK_DISABLE_DRIVER_RESET_CONTROL)
    /* Reset the module. */
    RESET_PeripheralReset(s_dacResets[DAC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_RESET_CONTROL */

    /*Analog configuration*/
    base->ANA_CFG = DAC_ANA_CFG_DAC_AMP(config->ana_cfg.amp) | DAC_ANA_CFG_FILTER_BW(config->ana_cfg.filter_bandwidth) |
                    DAC_ANA_CFG_FILTER_150K_EN(config->ana_cfg.filter_150k_en) | DAC_ANA_CFG_VCM(config->ana_cfg.vcm);

    base->SIN_CFG0 = DAC_SIN_CFG0_SIN_FREQ(config->sin_cfg.freq) | DAC_SIN_CFG0_SIN_AMP(config->sin_cfg.amp);

    base->SIN_CFG1 = DAC_SIN_CFG1_SIN_DC(config->sin_cfg.dc_offset);

    base->GAIN_CTRL = DAC_GAIN_CTRL_GAIN_CTRL(config->gain_ctrl);

    /*Dac ctrl*/
    base->CTRL = DAC_CTRL_SIN_EN(config->sin_cfg.en) | DAC_CTRL_MOD_EN(config->mod_cfg.en) |
                 DAC_CTRL_MOD_WD(config->mod_cfg.out_wd) | DAC_CTRL_SMPL_RATE(config->mod_cfg.smpl_rate) |
                 DAC_CTRL_SGN_INV(config->sign_inv) | DAC_CTRL_BUF_IN_ALGN(config->output) |
                 DAC_CTRL_BUF_OUT_ALGN(config->input) | DAC_CTRL_TRG_MODE(config->trg_cfg.mode) |
                 DAC_CTRL_TRG_EDGE(config->trg_cfg.edge) | DAC_CTRL_TRG_SEL(config->trg_cfg.src) |
                 DAC_CTRL_CLK_DIV(config->clk_div) | DAC_CTRL_CLK_INV(config->clk_inv);
}

/*!
 * brief  Sets the DAC configuration structure to default values.
 * code
    config->ana_cfg.amp = kDAC_Amplitude100pct;
    config->ana_cfg.filter_bandwidth = kDAC_FilterBandwidth56FF;
    config->ana_cfg.filter_150k_en = kDAC_Filter150kEnable150Khz;
    config->ana_cfg.vcm    = kDAC_VoltageCommonMode1500mv;
    config->sin_cfg.en = kDAC_SinWaveDisable;
    config->mod_cfg.en = kDAC_ModulatorDisable;
    config->mod_cfg.out_wd = kDAC_ModulatorWidth1bit;
    config->mod_cfg.smpl_rate = kDAC_SampleRate8;
    config->sign_inv = 0;
    config->output = kDAC_BufferOutAlignRight;
    config->input = kDAC_BufferInAlignRight;
    config->trg_cfg.mode = kDAC_TriggerModeSingleMode;
    config->trg_cfg.edge = kDAC_TriggerEdgeSelectPositiveEdge;
    config->trg_cfg.src = kDAC_TriggerSelectSoftware;
    config->clk_div = apb_clk / 1000000 / 2 - 1;
    config->clk_inv = 0;
    config->sin_cfg.freq = 0;
    config->sin_cfg.amp = 0;
    config->sin_cfg.dc_offset = 0;

    config->gain_ctrl = 0x10;
 * endcode
 * param config pointer to DAC config structure
 */
void DAC_GetDefaultConfig(dac_config_t *config)
{
    assert(config != NULL);

    /* Initializes the configure structure to zero. */
    memset(config, 0, sizeof(*config));

    uint32_t apb_clk = CLOCK_GetFreq(kCLOCK_ApbClk);

    config->ana_cfg.amp              = kDAC_Amplitude100pct;
    config->ana_cfg.filter_bandwidth = kDAC_FilterBandwidth56FF;
    config->ana_cfg.filter_150k_en   = kDAC_Filter150kEnable150Khz;
    config->ana_cfg.vcm              = kDAC_VoltageCommonMode1500mv;

    config->sin_cfg.en        = kDAC_SinWaveDisable;
    config->mod_cfg.en        = kDAC_ModulatorDisable;
    config->mod_cfg.out_wd    = kDAC_ModulatorWidth1bit;
    config->mod_cfg.smpl_rate = kDAC_SampleRate8;
    config->sign_inv          = 0;
    config->output            = kDAC_BufferOutAlignRight;
    config->input             = kDAC_BufferInAlignRight;
    config->trg_cfg.mode      = kDAC_TriggerModeSingleMode;
    config->trg_cfg.edge      = kDAC_TriggerEdgeSelectPositiveEdge;
    config->trg_cfg.src       = kDAC_TriggerSelectSoftware;
    config->clk_div           = apb_clk / 1000000 / 2 - 1;
    config->clk_inv           = 0;

    config->sin_cfg.freq      = 0;
    config->sin_cfg.amp       = 0;
    config->sin_cfg.dc_offset = 0;

    config->gain_ctrl = 0x10;
}

/*!
 * brief De-initialize the DAC peripheral
 *
 * param base DAC peripheral base address.
 * return none
 */
void DAC_Deinit(DAC_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Disable the clock. */
    CLOCK_DisableClock(s_dacClocks[DAC_GetInstance(base)]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}
