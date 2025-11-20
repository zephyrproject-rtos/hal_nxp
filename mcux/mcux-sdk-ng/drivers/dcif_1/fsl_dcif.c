/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "fsl_dcif.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/* Component ID definition, used by tools. */
#ifndef FSL_COMPONENT_ID
#define FSL_COMPONENT_ID "platform.drivers.dcif"
#endif

typedef union
{
    dcif_dbi_out_format_t _dcif_dbi_out_format;
    dcif_layer_alpha_blend_config_t _dcif_alpha_blend_config;
    dcif_dcs_pkt_config_t _dcif_dcs_pkt_config;
    uint32_t _u32;
} dcif_reg32_convert_t;

#define DCIF_LUT_MEM(base) \
    ((volatile uint32_t *)(((uint32_t)(base)) + (uint32_t)FSL_FEATURE_DCIF_CLUT_RAM_OFFSET))

#define DCIF_GAMMA_MEM(base) \
    ((volatile uint32_t *)(((uint32_t)(base)) + (uint32_t)FSL_FEATURE_DCIF_GAMMA_RAM_OFFSET))

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * brief Get the instance from the base address
 *
 * param base DCIF peripheral base address
 *
 * return The DCIF module instance
 */
static uint32_t DCIF_GetInstance(DCIF_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/*! brief Pointers to DCIF bases for each instance. */
static DCIF_Type *const s_dcifBases[] = DCIF_BASE_PTRS;

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! brief Pointers to DCIF clocks for each DCIF submodule. */
static const clock_ip_name_t s_dcifClocks[] = DCIF_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

#if defined(DCIF_RSTS)
/* Reset array */
static const reset_ip_name_t s_dcifResets[] = DCIF_RSTS;
#endif

/*!
 * brief The DBI bus width. Only low 8-bit of the bus data register is available during
 * read/write if the bus width is 8.
 */
static bool s_dbiWidth8bit[ARRAY_SIZE(s_dcifBases)];

/*******************************************************************************
 * Code
 ******************************************************************************/
static uint32_t DCIF_GetInstance(DCIF_Type *base)
{
    uint32_t instance;

    /* Find the instance index from base address mappings. */
    for (instance = 0; instance < ARRAY_SIZE(s_dcifBases); instance++)
    {
        if (MSDK_REG_SECURE_ADDR(s_dcifBases[instance]) == MSDK_REG_SECURE_ADDR(base))
        {
            break;
        }
    }

    assert(instance < ARRAY_SIZE(s_dcifBases));

    return instance;
}

/*!
 * brief Initialize the DCIF.
 *
 * This function initializes the DCIF to prepare it to work.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Init(DCIF_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_EnableClock(s_dcifClocks[DCIF_GetInstance(base)]);
#endif

#if defined(DCIF_RSTS)
    RESET_ReleasePeripheralReset(s_dcifResets[DCIF_GetInstance(base)]);
#endif

    DCIF_Reset(base);
}

/*!
 * brief De-initialize the DCIF.
 *
 * This function disables the DCIF peripheral clock.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Deinit(DCIF_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
    CLOCK_DisableClock(s_dcifClocks[DCIF_GetInstance(base)]);
#endif
}

/*!
 * brief Set the DCIF output configuration.
 *
 * Set the output configuration of frame size, output interface.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_SetOutputConfig(DCIF_Type *base, const dcif_output_config_t *config)
{
    assert(config != NULL);
    assert(config->width != 0U);
    assert(config->height != 0U);
    assert(config->width <= 0xFFFU);
    assert(config->height <= 0xFFFU);

    /* Set the DCIF output interface type. The output can only be enabled after the selected interface
       is configured. */
    base->DISP_CTRL = DCIF_DISP_CTRL_DISP_ON(0U) | DCIF_DISP_CTRL_DISP_IF_SEL((uint32_t)config->interface);

    /* Configure display size. */
    base->DISP_SIZE = DCIF_DISP_SIZE_DISP_WIDTH(config->width) | DCIF_DISP_SIZE_DISP_HEIGHT(config->height);
}

/*!
 * brief Reset the DCIF module.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Reset(DCIF_Type *base)
{
    base->DISP_CTRL |= DCIF_DISP_CTRL_AXI_RD_HOLD_MASK;

    while ((base->DISP_SR0 & DCIF_DISP_SR0_AXI_RD_BUSY_MASK) != 0U)
    {
        /* Wait for the AXI read busy bit to clear. */
    }

    /* Perform sw reset. */
    base->DISP_CTRL |= DCIF_DISP_CTRL_SW_RST_MASK;

    /* Wait for 4 slowest clock cycles. 2us which is 4 cycles of 2mHz clock is sufficient.
       in any circumstances. */
    SDK_DelayAtLeastUs(2, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);

    /* Clear sw reset. */
    base->DISP_CTRL &= ~DCIF_DISP_CTRL_SW_RST_MASK;
}

/*!
 * brief Configure the layer position.
 *
 * param base DCIF peripheral base address.
 * param layer Layer index.
 * param topLeftX The x value of thr top-left coordinate.
 * param topLeftY The y value of thr top-left coordinate.
 * param width The width of the layer.
 * param height The height of the layer.
 */
void DCIF_SetLayerPosition(DCIF_Type *base, uint8_t layer, uint16_t topLeftX, uint16_t topLeftY, uint16_t width, uint16_t height)
{
    assert(layer < DCIF_L_COUNT);
    assert(width <= 0xFFFU);
    assert(height <= 0xFFFU);

    /* Set the layer position. */
    base->L[layer].CTRLDESC_L[1] = DCIF_CTRLDESC_L_POSY_SIGN((topLeftY > 0) ? 0U : 1U) |
                                DCIF_CTRLDESC_L_POSY((topLeftY > 0) ? (uint16_t)topLeftY : (uint16_t)(-topLeftY)) |
                                DCIF_CTRLDESC_L_POSX_SIGN((topLeftX > 0) ? 0U : 1U) |
                                DCIF_CTRLDESC_L_POSX((topLeftX > 0) ? (uint16_t)topLeftX : (uint16_t)(-topLeftX));

    base->L[layer].CTRLDESC_L[2] = DCIF_CTRLDESC_L_WIDTH(width) |
                                    DCIF_CTRLDESC_L_HEIGHT(height);
}

/*!
 * brief Set the DCIF layer configuration.
 *
 * param base DCIF peripheral base address.
 * param layer Layer index.
 * param config Pointer to the configuration structure.
 * retval kStatus_Success Successfully get the configuration.
 * retval kStatus_InvalidArgument The blend mode not supported.
 */
status_t DCIF_SetLayerConfig(DCIF_Type *base, uint8_t layer, const dcif_layer_config_t *config)
{
    assert(layer < DCIF_L_COUNT);
    assert(config != NULL);

    /* Only the layer 0 and layer 1 support CSC for YUV format. */
    if ((((config->format & DCIF_CTRLDESC_L_FORMAT_MASK) == DCIF_CTRLDESC_L_FORMAT(7U)) ||
        ((config->format & DCIF_CTRLDESC_L_FORMAT_MASK) == DCIF_CTRLDESC_L_FORMAT(12U)) ||
        ((config->format & DCIF_CTRLDESC_L_FORMAT_MASK) == DCIF_CTRLDESC_L_FORMAT(13U))) &&
        (layer >= DCIF_CSC_COUNT))
    {
        return kStatus_InvalidArgument;
    }

    /* Set the layer position. */
    DCIF_SetLayerPosition(base, layer, config->topLeftX, config->topLeftY, config->width, config->height);

    /* Set the layer background color. */
    base->L[layer].CTRLDESC_L[6] = (uint32_t)config->background;

    /* Set the alpha blend configuration. */
    DCIF_SetLayerAlphaBlendConfig(base, layer, &(config->alphaBlendConfig));

    /* Set layer panic configuration. */
    base->L[layer].PANIC_THRES_L[0] = DCIF_PANIC_THRES_L_PANIC_THRES_LOW(config->panic.lowLevel) |
                                    DCIF_PANIC_THRES_L_PANIC_THRES_HIGH(config->panic.highLevel) |
                                    DCIF_PANIC_THRES_L_PANIC_REQ_EN(config->panic.enable ? 1U : 0U);

    /* Set the format, global alpha and blend mode. */
    base->L[layer].CTRLDESC_L[0] = DCIF_CTRLDESC_L_AB_MODE((uint32_t)config->alphaBlendMode) |
                                    DCIF_CTRLDESC_L_GLOBAL_ALPHA(config->globalAlpha) |
                                    DCIF_CTRLDESC_L_EN(config->enable ? 1U : 0U) |
                                    (uint32_t)config->format;

    return kStatus_Success;
}

/*!
 * brief Get the alpha blend configuration by porter duff blend mode.
 *
 * param mode The blend mode.
 * param config Pointer to the configuration.
 * retval kStatus_Success Successfully get the configuration.
 * retval kStatus_InvalidArgument The blend mode not supported.
 */
status_t DCIF_GetPorterDuffConfig(dcif_layer_porter_duff_blend_mode_t mode, dcif_layer_alpha_blend_config_t *config)
{
    status_t status;

    dcif_reg32_convert_t pid;

    static const uint32_t pdCtrl[] = {
        /* kDCIF_PorterDuffSrc */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorOne) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorZero),

        /* kDCIF_PorterDuffAtop */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorStraight) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorInversed),

        /* kDCIF_PorterDuffOver */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorOne) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorInversed),

        /* kDCIF_PorterDuffIn */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorStraight) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorZero),

        /* kDCIF_PorterDuffOut */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorInversed) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorZero),

        /* kDCIF_PorterDuffDst */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorZero) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorOne),

        /* kDCIF_PorterDuffDstAtop */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorInversed) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorStraight),

        /* kDCIF_PorterDuffDstOver */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorInversed) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorOne),

        /* kDCIF_PorterDuffDstIn */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorZero) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorStraight),

        /* kDCIF_PorterDuffDstOut */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorZero) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorInversed),

        /* kDCIF_PorterDuffPlus */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorOne) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorOne),

        /* kDCIF_PorterDuffXor */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorInversed) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorInversed),

        /* kDCIF_PorterDuffClear */
        DCIF_CTRLDESC_L_S0_S1_FACTOR_MODE(kDCIF_AlphaFactorZero) |
        DCIF_CTRLDESC_L_S1_S0_FACTOR_MODE(kDCIF_AlphaFactorZero),
    };

    if (mode >= kDCIF_PorterDuffMax)
    {
        status = kStatus_InvalidArgument;
    }
    else
    {
        pid._u32 = pdCtrl[(uint32_t)mode] |
                    DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA_MODE((uint32_t)kDCIF_AlphaLocal) |
                    DCIF_CTRLDESC_L_S1_GLOBAL_ALPHA_MODE((uint32_t)kDCIF_AlphaLocal) |
                    DCIF_CTRLDESC_L_S0_COLOR_MODE((uint32_t)kDCIF_AlphaColorWithAlpha) |
                    DCIF_CTRLDESC_L_S1_COLOR_MODE((uint32_t)kDCIF_AlphaColorWithAlpha) |
                    DCIF_CTRLDESC_L_S0_ALPHA_MODE((uint32_t)kDCIF_AlphaStraight) |
                    DCIF_CTRLDESC_L_S1_ALPHA_MODE((uint32_t)kDCIF_AlphaStraight) |
                    DCIF_CTRLDESC_L_S0_GLOBAL_ALPHA(0U);

        *config = pid._dcif_alpha_blend_config;

        status = kStatus_Success;
    }

    return status;
}

/*!
 * brief Set the DCIF layer alpha blend configuration.
 *
 * param base DCIF peripheral base address.
 * param layer Layer index.
 * param config Pointer to the configuration structure.
 */
void DCIF_SetLayerAlphaBlendConfig(DCIF_Type *base, uint8_t layer, const dcif_layer_alpha_blend_config_t *config)
{
    assert(layer < DCIF_L_COUNT);
    assert(config != NULL);

    dcif_reg32_convert_t pid;

    pid._dcif_alpha_blend_config = *config;
    base->L[layer].CTRLDESC_L[7] = pid._u32;
}

/*!
 * brief Set the gamma correction value to the gamma table.
 *
 * param base DCIF peripheral base address.
 * param mask The mask of red/green/blue table access, OR'd value of _dcif_gamma_access.
 * param startIndex Start index in the gamma table that the value will be set to.
 * param gamma The gamma values to set to the gamma table.
 * param gammaLen The length of the gamma table data.
 */
void DCIF_SetGammaData(DCIF_Type *base, uint32_t mask, uint8_t startIndex, const uint32_t *gamma, uint16_t gammaLen)
{
    assert((startIndex + gammaLen) <= FSL_FEATURE_DCIF_GAMMA_INDEX_MAX);

    base->GC_CTRL = (base->GC_CTRL & ~0xE0000000) | mask;
    for (uint8_t i = startIndex; i < (startIndex + gammaLen - 1U); i++)
    {
        (DCIF_GAMMA_MEM(base))[i] = gamma[i];
    }
}

/*!
 * brief Get the default configuration for CLUT.
 *
 * The default configuration value is:
 *
 * code
 * config->clutSelect[0] = kDCIF_Clut0;
 * config->clutSelect[1] = kDCIF_Clut1;
 * endcode
 *
 * param config Pointer to the DCIF CLUT configuration.
 */
void DCIF_ClutGetDefaultConfig(dcif_clut_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    /* CLUT0 for layer 0, CLUT1 for layer 1, access CLUT0 by APB. */
    config->clut0Layer = 0U;
    config->clut1Layer = 1U;
    config->clutAccess = kDCIF_Clut0;
}

/*!
 * brief Set the color look up table configuration.
 *
 * This function must be called before DCIF_SetLayerConfig if the input pixel
 * format is index.
 *
 * param base DCIF peripheral base address.
 * param config The CLUT configuration.
 */
void DCIF_ClutSetConfig(DCIF_Type *base, const dcif_clut_config_t *config)
{
    assert(base != NULL);

    base->CLUT_CTRL = DCIF_CLUT_CTRL_CLUT_SHADOW_LOAD_EN(1U) | DCIF_CLUT_CTRL_CLUT_MUX(config->clutAccess) |
            DCIF_CLUT_CTRL_CLUT0_SEL(config->clut0Layer) | DCIF_CLUT_CTRL_CLUT1_SEL(config->clut1Layer);
}

/*!
 * brief Set the CLUT value.
 *
 * param base DCIF peripheral base address.
 * param startIndex Start index in the CLUT that the value will be set to.
 * param clut The LUT values to set to the CLUT table.
 * param clutLen The length of the CLUT table data.
 */
void DCIF_ClutSetData(DCIF_Type *base, uint8_t startIndex, const uint32_t *clut, uint8_t clutLen)
{
    assert((startIndex + clutLen) <= FSL_FEATURE_DCIF_CLUT_INDEX_MAX);

    for (uint8_t i = startIndex; i < (startIndex + clutLen - 1U); i++)
    {
        (DCIF_LUT_MEM(base))[i] = clut[i];
    }
}

/*!
 * brief Set the color space conversion mode.
 *
 * Supports YUV2RGB and YCbCr2RGB. This must be called before DCIF_SetLayerConfig
 * if the layer pixel format is YUV.
 *
 * param base DCIF peripheral base address.
 * param layerIndex Index of the layer.
 * param mode The conversion mode.
 */
void DCIF_SetCscMode(DCIF_Type *base, uint8_t layerIndex, dcif_csc_mode_t mode)
{
    assert(layerIndex < DCIF_CSC_COUNT);

    base->CSC[layerIndex].CSC_CTRL = (uint32_t)mode;

    /*
     * The equations used for Colorspace conversion are:
     *
     * YUV/YCbCr -> RGB
     * R = A1(Y+D1) + A2(U+D2) + A3(V+D3) = Y + 0.000U + 1.140V = 1.164(Y-16) + 0.000(Cb-128) + 1.596(Cr-128)
     * G = B1(Y+D1) + B2(U+D2) + B3(V+D3) = Y - 0.394U - 0.581V = 1.164(Y-16) - 0.392(Cb-128) - 0.813(Cr-128)
     * B = C1(Y+D1) + C2(U+D2) + C3(V+D3) = Y + 2.032U + 0.000V = 1.164(Y-16) + 2.017(Cb-128) + 0.000(Cr-128)
     *
     */

    if (kDCIF_CscYUV2RGB == mode)
    {
        base->CSC[layerIndex].CSC_COEF[0] = DCIF_CSC_COEF_A1(0x100U) | DCIF_CSC_COEF_A2(0);
        base->CSC[layerIndex].CSC_COEF[1] = DCIF_CSC_COEF_A3(0x0123U) | DCIF_CSC_COEF_B1(0x100U);
        base->CSC[layerIndex].CSC_COEF[2] = DCIF_CSC_COEF_B2(0x079BU) | DCIF_CSC_COEF_B3(0x076BU);
        base->CSC[layerIndex].CSC_COEF[3] = DCIF_CSC_COEF_C1(0x100U) | DCIF_CSC_COEF_C2(0x0208U);
        base->CSC[layerIndex].CSC_COEF[4] = DCIF_CSC_COEF_C3(0) | DCIF_CSC_COEF_D1(0);
        base->CSC[layerIndex].CSC_COEF[5] = DCIF_CSC_COEF_D2(0) | DCIF_CSC_COEF_D3(0);
    }
    else if (kDCIF_CscYCbCr2RGB == mode)
    {
        base->CSC[layerIndex].CSC_COEF[0] = DCIF_CSC_COEF_A1(0x129U) | DCIF_CSC_COEF_A2(0);
        base->CSC[layerIndex].CSC_COEF[1] = DCIF_CSC_COEF_A3(0x198) | DCIF_CSC_COEF_B1(0x129U);
        base->CSC[layerIndex].CSC_COEF[2] = DCIF_CSC_COEF_B2(0x79C) | DCIF_CSC_COEF_B3(0x730U);
        base->CSC[layerIndex].CSC_COEF[3] = DCIF_CSC_COEF_C1(0x129U) | DCIF_CSC_COEF_C2(0x204);
        base->CSC[layerIndex].CSC_COEF[4] = DCIF_CSC_COEF_C3(0) | DCIF_CSC_COEF_D1(0x1EFU);
        base->CSC[layerIndex].CSC_COEF[5] = DCIF_CSC_COEF_D2(0x17FU) | DCIF_CSC_COEF_D3(0x17FU);
    }
}

/*!
 * brief Enables DCIF interrupt requests.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
void DCIF_EnableInterrupts(DCIF_Type *base, uint8_t domain, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IE0_D0 |= mask;
    }
    else
    {
        base->L[domain - 1U].D[0].IE_D |= mask;
    }
}

/*!
 * brief Disables DCIF interrupt requests.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
void DCIF_DisableInterrupts(DCIF_Type *base, uint8_t domain, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IE0_D0 &= ~mask;
    }
    else
    {
        base->L[domain - 1U].D[0].IE_D &= ~mask;
    }
}

/*!
 * brief Get DCIF interrupt peding status.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * return Interrupt pending status, OR'ed value of _dcif_interrupt.
 */
uint32_t DCIF_GetInterruptStatus(DCIF_Type *base, uint8_t domain)
{
    assert(domain <= DCIF_L_COUNT);

    if (domain == 0U)
    {
        return base->IS0_D0;
    }
    else
    {
        return base->L[domain - 1U].D[0].IS_D;
    }
}

/*!
 * brief Clear DCIF interrupt pending status.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask of the flags to clear, OR'ed value of _dcif_interrupt.
 */
void DCIF_ClearInterruptStatus(DCIF_Type *base, uint8_t domain, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IS0_D0 = mask;
    }
    else
    {
        base->L[domain - 1U].D[0].IS_D = mask;
    }
}

/*!
 * brief Enables DCIF layer interrupt requests.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask interrupt source, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_EnableLayerInterrupts(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);
    assert(layer < DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IE1_D0 |= mask << layer;
    }
    else
    {
        base->L[domain - 1U].D[1].IE_D |= mask << layer;
    }
}

/*!
 * brief Disables DCIF layer interrupt requests.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask interrupt source, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_DisableLayerInterrupts(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);
    assert(layer < DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IE1_D0 &= ~(mask << layer);
    }
    else
    {
        base->L[domain - 1U].D[1].IE_D &= ~(mask << layer);
    }
}

/*!
 * brief Get DCIF layer interrupt peding status.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * return Interrupt pending status, OR'ed value of _dcif_layer_interrupt.
 */
uint32_t DCIF_GetLayerInterruptStatus(DCIF_Type *base, uint8_t domain, uint8_t layer)
{
    assert(domain <= DCIF_L_COUNT);
    assert(layer < DCIF_L_COUNT);

    if (domain == 0U)
    {
        return (base->IS1_D0 >> layer) & 0x1010101U;
    }
    else
    {
        return (base->L[domain - 1U].D[1].IS_D >> layer) & 0x1010101U;
    }
}

/*!
 * brief Clear DCIF layer interrupt peding status.
 *
 * param base DCIF peripheral base address.
 * param domain CPU domain the interrupt signal routed to.
 * param mask of the flags to clear, OR'ed value of _dcif_layer_interrupt.
 */
void DCIF_ClearLayerInterruptStatus(DCIF_Type *base, uint8_t domain, uint8_t layer, uint32_t mask)
{
    assert(domain <= DCIF_L_COUNT);
    assert(layer < DCIF_L_COUNT);

    if (domain == 0U)
    {
        base->IS1_D0 = mask << layer;
    }
    else
    {
        base->L[domain - 1U].D[1].IS_D = mask << layer;
    }
}

/*!
 * brief Get the default configuration for DCIF PDI input.
 *
 * The default configuration value is:
 *
 * code
 * config->enable = false;
 * config->skipFirstFrame = false;
 * config->vsyncControl = false;
 * config->vsyncDelay_pclk = 0;
 * config->vsyncTimeout_hsync = 0;
 * config->polarityFlags = kDCIF_PdiVsyncActiveLow | kDCIF_PdiDriveDataOnFallingClkEdge;
 * config->format = kDCIF_PdiRGB888;
 * config->layer = kDCIF_PdiLayer0;
 * endcode
 *
 * param config Pointer to the DCIF PDI configuration.
 */
void DCIF_PdiGetDefaultConfig(dcif_pdi_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    config->polarityFlags = (uint32_t)(kDCIF_PdiVsyncActiveLow | kDCIF_PdiDriveDataOnFallingClkEdge);
}

/*!
 * brief Configure the DCIF PDI input.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_PdiSetConfig(DCIF_Type *base, const dcif_pdi_config_t *config)
{
    assert(NULL != config);
    assert(config->vsyncDelay_pclk < DCIF_PDI_CNT_PDI_P_CNT_MASK);
    assert(config->vsyncTimeout_hsync < DCIF_PDI_TO_CNT_PDI_TIMEOUT_CNT_MASK);

    base->PDI_CNT = config->vsyncDelay_pclk;
    base->PDI_TO_CNT = config->vsyncTimeout_hsync;
    base->PDI_CTRL = (uint32_t)config->polarityFlags | DCIF_PDI_CTRL_PDI_FETCH_OPT(config->skipFirstFrame ? 1U : 0U) |
        DCIF_PDI_CTRL_PDI_SEL((uint32_t)config->layer) | DCIF_PDI_CTRL_PDI_FORMAT((uint32_t)config->format) |
        DCIF_PDI_CTRL_PDI_SYNC_CTRL(config->vsyncControl ? 1U : 0U) |
        DCIF_PDI_CTRL_PDI_SHADOW_LOAD_EN(1U) | DCIF_PDI_CTRL_PDI_EN(config->enable ? 1U : 0U);
}

/*!
 * brief Get the default configuration for DCIF FBD input.
 *
 * The default configuration value is:
 *
 * code
 * config->enable = true;
 * config->format = kDCIF_FbdRGB8;
 * config->layer = kDCIF_FbdLayer0;
 * endcode
 *
 * param config Pointer to the DCIF PDI configuration.
 */
void DCIF_FbdGetDefaultConfig(dcif_fbd_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    config->enable = true;
    config->format = kDCIF_FbdRGB8;
}

/*!
 * brief Configure the DCIF FBD input.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_FbdSetConfig(DCIF_Type *base, const dcif_fbd_config_t *config)
{
    assert(NULL != config);

    base->FBD_CTRL = DCIF_FBD_CTRL_FBD_DATA_PATTERN((uint32_t)config->format) |
        DCIF_FBD_CTRL_FBD_SHADOW_LOAD_EN(1U) |
        DCIF_FBD_CTRL_FBD_SEL(config->enable ? 1U : 0U);
}

/*!
 * brief Get the default configuration for DPI interface.
 *
 * The default configuration value is:
 *
 * code
 * config->hsw = 0;
 * config->hfp = 0;
 * config->hbp = 0;
 * config->vsw = 0;
 * config->vfp = 0;
 * config->vbp = 0;
 * config->polarityFlags = kDCIF_DpiHsyncActiveLow | kDCIF_DpiVsyncActiveLow | kDCIF_DpiDriveDataOnFallingClkEdge;
 * config->format = kDCIF_DpiRGB565;
 * config->displayMode = kDCIF_DpiNormal;
 * config->frameFetch = kDCIF_DpiVfpBegin;
 * config->txFfifoFill = kDCIF_DpiVbpEnd;
 * config->enableBackground = true;
 * endcode
 *
 * param config Pointer to the DCIF DPI configuration.
 */
void DCIF_DpiGetDefaultConfig(dcif_dpi_config_t *config)
{
    assert(NULL != config);

    (void)memset(config, 0, sizeof(*config));

    config->polarityFlags = (uint32_t)(kDCIF_DpiHsyncActiveLow | kDCIF_DpiVsyncActiveLow | kDCIF_DpiDriveDataOnFallingClkEdge);
    config->format = kDCIF_DpiRGB565;
    config->frameFetch = kDCIF_DpiVfpBegin;
    config->txFifoFill = kDCIF_DpiVfpBegin;
    config->enableBackground = true;
}

/*!
 * brief Set the configuration for DCIF DPI interface.
 *
 * This function configures the DCIF DPI display.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_DpiSetConfig(DCIF_Type *base, const dcif_dpi_config_t *config)
{
    assert(NULL != config);

    /* Configure flag polarities, display mode, data format and FIFO options. */
    base->DPI_CTRL = (uint32_t)config->polarityFlags | DCIF_DPI_CTRL_DEF_BGND_EN(config->enableBackground ? 1U : 0U) |
        DCIF_DPI_CTRL_FETCH_OPT((uint32_t)config->frameFetch) | DCIF_DPI_CTRL_TXFIFO_FILL_OPT((uint32_t)config->txFifoFill) |
        DCIF_DPI_CTRL_DISP_MODE((uint32_t)config->displayMode) | DCIF_DPI_CTRL_DATA_PATTERN((uint32_t)config->format);

    /* Configure the horizontal and vertical sync parameters. */
    base->DPI_HSYN_PAR = (uint32_t)config->hfp | (uint32_t)config->hbp << 16U;
    base->DPI_VSYN_PAR = (uint32_t)config->vfp | (uint32_t)config->vbp << 16U;
    base->DPI_VSYN_HSYN_WIDTH = (uint32_t)config->hsw | (uint32_t)config->vsw << 16U;
}

/*!
 * brief Get the default configuration to initialize the DCIF DBI interface.
 *
 * The default configuration value is:
 *
 * code
 * config->format      = kDCIF_DbiOutD16RGB565;
 * config->type        = kDCIF_DbiTypeB;
 * config->signalFlags = kDCIF_DbiTeEnable;
 * config->rdHigh      = 0U;
 * config->rdLow       = 0U;
 * config->wrHigh      = 0U;
 * config->wrLow       = 0U;
 * config->csSetup     = 0U;
 * config->csHold      = 0U;
 * endcode
 *
 * param config Pointer to the DCIF DBI configuration.
 */
void DCIF_DbiGetDefaultConfig(dcif_dbi_config_t *config)
{
    (void)memset(config, 0, sizeof(*config));

    config->format = kDCIF_DbiOutD16RGB565;
    config->type = kDCIF_DbiTypeB;
    config->signalFlags = kDCIF_DbiTeEnable;
}

/*!
 * brief Set the configuration for DCIF DBI mode.
 *
 * This function configures the DCIF DBI display.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_DbiSetConfig(DCIF_Type *base, const dcif_dbi_config_t *config)
{
    assert(NULL != config);
    assert(config->rdHigh <= (DCIF_DBI_PAR0_REH_MASK >> DCIF_DBI_PAR0_REH_SHIFT));
    assert(config->rdLow <= (DCIF_DBI_PAR0_REL_MASK >> DCIF_DBI_PAR0_REL_SHIFT));
    assert(config->wrHigh <= (DCIF_DBI_PAR0_WEH_MASK >> DCIF_DBI_PAR0_WEH_SHIFT));
    assert(config->wrLow <= (DCIF_DBI_PAR0_WEL_MASK >> DCIF_DBI_PAR0_WEL_SHIFT));
    assert(config->csSetup <= (DCIF_DBI_PAR1_CES_MASK >> DCIF_DBI_PAR1_CES_SHIFT));
    assert(config->csHold <= (DCIF_DBI_PAR1_CEH_MASK >> DCIF_DBI_PAR1_CEH_SHIFT));

    /* Get the bus width from the output format, used for later read/write. */
    if (((uint8_t)config->format <= (uint8_t)kDCIF_DbiOutD8RGB888) &&
        (((uint8_t)config->format % 2U) == 0U) &&
        (config->format != kDCIF_DbiOutD16RGB666Option1))
    {
        s_dbiWidth8bit[DCIF_GetInstance(base)] = true;
    }
    else
    {
        s_dbiWidth8bit[DCIF_GetInstance(base)] = false;
    }

    base->DBI_CTRL = DCIF_DBI_CTRL_DBI_TYPE((uint32_t)config->type) |
        DCIF_DBI_CTRL_DBI_DATA_PATTERN((uint32_t)config->format) | (uint32_t)config->signalFlags;
    base->DBI_PAR0 = DCIF_DBI_PAR0_WEL(config->wrLow) | DCIF_DBI_PAR0_WEH(config->wrHigh) |
        DCIF_DBI_PAR0_REL(config->rdLow) | DCIF_DBI_PAR0_REH(config->rdHigh);
    base->DBI_PAR1 = DCIF_DBI_PAR1_CES(config->csSetup) | DCIF_DBI_PAR1_CEH(config->csHold);
}

/*!
 * brief Send command to DBI port.
 *
 * param base DCIF peripheral base address.
 * param cmd the DBI command to send.
 */
void DCIF_DbiWriteCommand(DCIF_Type *base, uint8_t cmd)
{
    uint32_t regVal = base->DBI_CTRL & ~(DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK | DCIF_DBI_CTRL_DBI_WDATA_MASK |
        DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK);
    base->DBI_CTRL = regVal | DCIF_DBI_CTRL_DBI_CMD_TYPE(kDCIF_DbiCmdWriteCommand) | DCIF_DBI_CTRL_DBI_WDATA(cmd);

    base->DBI_CTRL |= DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK;
}

/*!
 * brief Write parameter to DBI port.
 *
 * param base DCIF peripheral base address.
 * param width the DBI bus width.
 * param data pointer to data buffer.
 * param dataLen_Byte data buffer length in byte.
 */
void DCIF_DbiWriteParam(DCIF_Type *base, const uint8_t *data, uint32_t dataLen_Byte)
{
    assert(data != NULL);
    assert(dataLen_Byte > 0);

    uint16_t lastWord;
    uint32_t regVal = (base->DBI_CTRL & ~(DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK | DCIF_DBI_CTRL_DBI_WDATA_MASK |
        DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK)) | DCIF_DBI_CTRL_DBI_CMD_TYPE(kDCIF_DbiCmdWriteParam);

    if (s_dbiWidth8bit[DCIF_GetInstance(base)])
    {
        while (dataLen_Byte > 1U)
        {
            /* Send data. Save the last data to write with command type and trigger. */
            base->DBI_CTRL = regVal | DCIF_DBI_CTRL_DBI_WDATA(*data);
            data++;
            dataLen_Byte--;
        }
        lastWord = *data;
    }
    else
    {
        assert((dataLen_Byte % 2U) == 0U);
        dataLen_Byte /= 2U;

        /* Send data. Save the last data to write with command type and trigger. */
        while (dataLen_Byte > 1U)
        {
            base->DBI_CTRL = regVal | DCIF_DBI_CTRL_DBI_WDATA((uint16_t)data[0] | (uint16_t)data[1] << 8U);
            data = &data[2];
        }
        lastWord = (uint16_t)data[0] | (uint16_t)data[1] << 8U;
    }

    /* TODO Need to check whether the triger needs to be writen seperately. */
    base->DBI_CTRL = regVal | DCIF_DBI_CTRL_DBI_WDATA(lastWord) | DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK;
}

/*!
 * brief Read command followed by data to DBI port.
 *
 * param base DCIF peripheral base address.
 * param data pointer to data buffer.
 * param dataLen_Byte data buffer length in byte.
 * retval kStatus_Success Successfully received parameters.
 * retval kStatus_Timeout Timeout occurs while waiting completion.
 */
status_t DCIF_DbiReadParam(DCIF_Type *base, const uint8_t *data, uint32_t dataLen_Byte)
{
    assert(data != NULL);
    assert(dataLen_Byte > 0);

    uint32_t regVal = base->DBI_CTRL & ~(DCIF_DBI_CTRL_DBI_CMD_TYPE_MASK | DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK);
#if DCIF_DBI_CMD_TIMEOUT
    uint32_t waitTimes = DCIF_DBI_CMD_TIMEOUT;
#endif

    base->DBI_CTRL = regVal | DCIF_DBI_CTRL_DBI_CMD_TYPE(kDCIF_DbiCmdReadParam) | DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK;

    while ((base->DBI_CTRL & DCIF_DBI_CTRL_DBI_CMD_TRIG_MASK) != 0U)
    {
#if DCIF_DBI_CMD_TIMEOUT
        /* Wait for the command to be completed. */
        if ((--waitTimes) == 0U)
        {
            return kStatus_Timeout;
        }
#endif
    }

    uint8_t *dataLocal = (uint8_t *)data;

    if (s_dbiWidth8bit[DCIF_GetInstance(base)])
    {
        while (dataLen_Byte > 0U)
        {
            *dataLocal = (uint8_t)(base->DBI_SR >> 16U);
            dataLocal++;
            dataLen_Byte--;
        }
    }
    else
    {
        assert((dataLen_Byte % 2U) == 0U);

        uint16_t tmp;

        for (uint32_t i = 0; i < dataLen_Byte / 2U; i++)
        {
            tmp          = (uint16_t)(base->DBI_SR >> 16U);
            dataLocal[0] = (uint8_t)(tmp & 0xFFU);
            dataLocal[1] = (uint8_t)((tmp >> 8U) & 0xFFU);
            dataLocal    = &dataLocal[2];
        }
    }

    return kStatus_Success;
}

/*!
 * brief Set the configuration for DCIF DCS packet interface.
 *
 * This function configures the DCIF DCS packet interface.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the configuration structure.
 */
void DCIF_DcsPktSetConfig(DCIF_Type *base, const dcif_dcs_pkt_config_t *config)
{
    assert(NULL != config);
    assert((config->payloadByteCnt % 4U) == 0U);

    dcif_reg32_convert_t pid;
    pid._dcif_dcs_pkt_config = *config;

    base->TXPKTIF_CTRL = (pid._u32 & 0xFFFF) | (((pid._u32 >> 16U) + 1U) << 16U);
    base->TXPKTIF_THRES = (uint32_t)config->fifoSendLevel;
    base->TXPKTIF_TO_CNT = (uint32_t)config->timeout;
}

/*!
 * brief Select the update area and send the pixels using DCS packet interface.
 *
 * param base DCIF peripheral base address.
 * param startX X coordinate for start pixel.
 * param startY Y coordinate for start pixel.
 * param endX X coordinate for end pixel.
 * param endY Y coordinate for end pixel.
 */
void DCIF_DcsPktUpdateArea(DCIF_Type *base, uint16_t startX, uint16_t startY, uint16_t endX, uint16_t endY)
{
    assert(startX <= endX);
    assert(startY <= endY);

    base->TXPKTIF_PAR0 = DCIF_TXPKTIF_PAR0_SC(startX) | DCIF_TXPKTIF_PAR0_EC(endX);
    base->TXPKTIF_PAR1 = DCIF_TXPKTIF_PAR1_SP(startY) | DCIF_TXPKTIF_PAR1_EP(endY);

    base->TXPKTIF_CTRL = (base->TXPKTIF_CTRL & ~DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE_MASK) |
                         DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TYPE(kDCIF_DcsPktCmdSetColPageWritePixel);
    base->TXPKTIF_CTRL |= DCIF_TXPKTIF_CTRL_TXPKTIF_CMD_TRIG_MASK;
}
