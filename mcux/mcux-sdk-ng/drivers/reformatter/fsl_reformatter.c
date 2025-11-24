/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_reformatter.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.reformatter"
#endif

typedef union
{
    reformatter_signal_config_t _signal_config;
    uint32_t _u32;
} reformat_reg32_convert_t;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to MIPI DSI clocks for each instance. */
static const clock_ip_name_t s_reformatterClocks[] = REFORMATTER_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Codes
 ******************************************************************************/
/*!
 * brief Initializes the REFORMATTER.
 *
 * The default configuration can be got by calling REFORMATTER_GetDefaultConfig().
 *
 * param base REFORMATTER peripheral base address.
 * param config Pointer to REFORMATTER configuration structure.
 */
void REFORMATTER_Init(REFORMATTER_Type *base, const reformatter_config_t *config)
{
    assert(NULL != config);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* Open clock gate. */
    CLOCK_EnableClock(s_reformatterClocks[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    reformat_reg32_convert_t pid;

    pid._signal_config = config->signalConfig;
    base->PLM_CTRL.RW = pid._u32;

    base->MIPI_CSI_CTRL.RW = REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT((uint32_t)config->dataShift);
    base->STREAM_FENCING_CTRL.RW = (uint32_t)config->streamFence;
    base->YUV420_CTRL.RW = REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE((uint32_t)config->yuv420LineOrder);
    base->CFG_DT_DISABLE.RW = config->typeDisable;
    base->PL_TO_PDI_CTRL.RW = REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN(config->enableConversion ? 1U : 0U);
    base->VC_INTERLACED = (uint32_t)config->yuv420Interlace;
    base->ISI2PL_IER = (uint32_t)config->interupt;
}

/*!
 * brief Disables the REFORMATTER peripheral module.
 *
 * param base REFORMATTER peripheral address.
 */
void REFORMATTER_Deinit(REFORMATTER_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    /* gate clock */
    CLOCK_DisableClock(s_reformatterClocks[0]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Set default values to the REFORMATTER configuration structure.
 *
 * The default values are as follows.
 * code
    config->dataShift = kREFORMATTER_ShiftLsb;
    config->streamFence = 0U;
    config->signalConfig.enable = true;
    config->signalConfig.vsyncForceHigh = false;
    config->signalConfig.hsyncForceHigh = false;
    config->signalConfig.validForceHigh = false;
    config->signalConfig.syncInvert = false;
    config->yuv420LineOrder = kREFORMATTER_YUV420OddFirst;
    config->yuv420Interlace = 0U;
    config->enableConversion = true;
    config->interupt = kREFORMATTER_InterruptIsiDataNotRGB888;
    config->typeDisable = 0U;
 * endcode
 *
 * param config REFORMATTER module configuration structure.
 */
void REFORMATTER_GetDefaultConfig(reformatter_config_t *config)
{
    assert(NULL != config);

    /* Initializes the configure structure to zero. */
    (void)memset(config, 0, sizeof(*config));

    /* Fill default configuration */
    config->dataShift = kREFORMATTER_ShiftLsb;
    config->streamFence = 0U;
    config->signalConfig.enable = true;
    config->signalConfig.vsyncForceHigh = false;
    config->signalConfig.hsyncForceHigh = false;
    config->signalConfig.validForceHigh = false;
    config->signalConfig.syncInvert = false;
    config->yuv420LineOrder = kREFORMATTER_YUV420OddFirst;
    config->yuv420Interlace = 0U;
    config->enableConversion = true;
    config->interupt = kREFORMATTER_InterruptIsiDataNotRGB888;
    config->typeDisable = 0U;
}
