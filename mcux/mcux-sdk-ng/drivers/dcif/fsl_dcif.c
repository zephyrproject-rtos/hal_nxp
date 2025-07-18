/*
 * Copyright 2024 NXP
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

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*!
 * @brief Get instance number for DCIF module.
 *
 * @param base DCIF peripheral base address
 */
static uint32_t DCIF_GetInstance(const DCIF_Type *base);

/*!
 * @brief Reset register value to default status.
 *
 * @param base DCIF peripheral base address
 */
static void DCIF_ResetRegister(DCIF_Type *base);

/*******************************************************************************
 * Variables
 ******************************************************************************/

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL)
/*! @brief Pointers to DCIF clock for each instance. */
static const clock_ip_name_t s_dcifClocks[] = DCIF_CLOCKS;
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

/*******************************************************************************
 * Codes
 ******************************************************************************/
static uint32_t DCIF_GetInstance(const DCIF_Type *base)
{
    static DCIF_Type *const s_dcifBases[] = DCIF_BASE_PTRS;

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

static void DCIF_ResetRegister(DCIF_Type *base)
{
    base->DISP_PAR              = 0U;
    base->DISP_CTRL             = 0x80000000U;
    base->DISP_SIZE             = 0U;
    /* clear DATA_PATTERN, DISP_MODE, FETCH_OPT and polarityFlags*/
    base->DPI_CTRL              = 0U;
    base->DPI_HSYN_PAR          = 0x30003U;
    base->DPI_VSYN_PAR          = 0x30003U;
    base->DPI_VSYN_HSYN_WIDTH   = 0x30003U;
    base->IE0_D0                = 0U;
    base->IE0_D1                = 0U;
    base->IE0_D2                = 0U;
    base->IE1_D0                = 0U;
    base->IE1_D1                = 0U;
    base->IE1_D2                = 0U;
    /* Clear interrupt status. */
    base->IS0_D0                = 0xFFFFFFFFU;
    base->IS0_D1                = 0xFFFFFFFFU;
    base->IS0_D2                = 0xFFFFFFFFU;
    base->IS1_D0                = 0xFFFFFFFFU;
    base->IS1_D1                = 0xFFFFFFFFU;
    base->IS1_D2                = 0xFFFFFFFFU;

    base->CTRLDESC0_L1          = 0U;
    base->CTRLDESC1_L1          = 0U;
    base->CTRLDESC2_L1          = 0U;
    base->CTRLDESC3_L1          = 0U;
    base->CTRLDESC4_L1          = 0U;
    base->CTRLDESC5_L1          = 0U;
}

/*!
 * brief Initializes the DCIF.
 *
 * This function ungates the DCIF clock and release the peripheral reset.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Init(DCIF_Type *base)
{
#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && (0 != FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
    uint32_t instance = DCIF_GetInstance(base);
    /* Enable the clock. */
    CLOCK_EnableClock(s_dcifClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */

    DCIF_ResetRegister(base);

    /* Out of reset. */
    base->DISP_CTRL = 0U;
}

/*!
 * brief Deinitializes the DCIF peripheral.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Deinit(DCIF_Type *base)
{
    DCIF_ResetRegister(base);

#if !(defined(FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL) && (0 != FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL))
    uint32_t instance = DCIF_GetInstance(base);
    /* Disable the clock. */
    CLOCK_DisableClock(s_dcifClocks[instance]);
#endif /* FSL_SDK_DISABLE_DRIVER_CLOCK_CONTROL */
}

/*!
 * brief Reset the DCIF.
 *
 * param base DCIF peripheral base address.
 */
void DCIF_Reset(DCIF_Type *base)
{
    DCIF_ResetRegister(base);

    /* Release and ready to work. */
    base->DISP_CTRL = 0U;
}

/*!
 * brief Gets the DCIF display default configuration structure.
 *
 * param config Pointer to the DCIF configuration structure.
 */
void DCIF_DisplayGetDefaultConfig(dcif_display_config_t *config)
{
    assert(NULL != config);

    config->panelWidth    = 0U;
    config->panelHeight   = 0U;
    config->hsw           = 3U;
    config->hfp           = 3U;
    config->hbp           = 3U;
    config->vsw           = 3U;
    config->vfp           = 3U;
    config->vbp           = 3U;
    config->polarityFlags = (uint32_t)kDCIF_VsyncActiveHigh | (uint32_t)kDCIF_HsyncActiveHigh |
                            (uint32_t)kDCIF_DataEnableActiveHigh | (uint32_t)kDCIF_DriveDataOnRisingClkEdge |
                            (uint32_t)kDCIF_DataActiveHigh;
    config->lineOrder = kDCIF_LineOrderRGB;
}

/*!
 * brief Set the DCIF display configurations.
 *
 * param base DCIF peripheral base address.
 * param config Pointer to the DCIF configuration structure.
 */
void DCIF_SetDisplayConfig(DCIF_Type *base, const dcif_display_config_t *config)
{
    assert(NULL != config);

    /* Configure the parameters. */
    base->DISP_SIZE = ((uint32_t)config->panelWidth << DCIF_DISP_SIZE_DISP_WIDTH_SHIFT) |
                      ((uint32_t)config->panelHeight << DCIF_DISP_SIZE_DISP_HEIGHT_SHIFT);

    base->DPI_HSYN_PAR = ((uint32_t)config->hbp << DCIF_DPI_HSYN_PAR_BP_H_SHIFT) |
                      ((uint32_t)config->hfp << DCIF_DPI_HSYN_PAR_FP_H_SHIFT);

    base->DPI_VSYN_PAR = ((uint32_t)config->vbp << DCIF_DPI_VSYN_PAR_BP_V_SHIFT) |
                      ((uint32_t)config->vfp << DCIF_DPI_VSYN_PAR_FP_V_SHIFT);

    base->DPI_VSYN_HSYN_WIDTH = ((uint32_t)config->hsw << DCIF_DPI_VSYN_HSYN_WIDTH_PW_H_SHIFT) |
                            ((uint32_t)config->vsw << DCIF_DPI_VSYN_HSYN_WIDTH_PW_V_SHIFT);

    base->DPI_CTRL |= DCIF_DPI_CTRL_DATA_PATTERN((uint32_t)config->lineOrder);
    /* The polarityFlags should be set into DPI_CTRL*/
    base->DPI_CTRL |= (uint32_t)(config->polarityFlags);
}

/*!
 * brief Set the color space conversion mode.
 *
 * Supports YUV2RGB and YCbCr2RGB.
 *
 * param base DCIF peripheral base address.
 * param layerIndex Index of the layer.
 * param mode The conversion mode.
 */
void DCIF_SetCscMode(DCIF_Type *base, dcif_csc_mode_t mode)
{
    /*
     * The equations used for Colorspace conversion are:
     *
     * YUV/YCbCr -> RGB
     * R = A1(Y+D1) + A2(U+D2) + A3(V+D3)
     * G = B1(Y+D1) + B2(U+D2) + B3(V+D3)
     * B = C1(Y+D1) + C2(U+D2) + C3(V+D3)
     *
     */

    base->CSC_CTRL_L[0] &= ~(DCIF_CSC_CTRL_L_CSC_MODE_MASK | DCIF_CSC_CTRL_L_CSC_EN_MASK);
    if (kDCIF_CscYUV2RGB == mode || kDCIF_CscYCbCr2RGB == mode)
    {
        base->CSC_COEF0_L[0] = DCIF_CSC_COEF0_L_A1(0x0U)
                                            | DCIF_CSC_COEF0_L_A2(0x0U);
        base->CSC_COEF1_L[0] = DCIF_CSC_COEF1_L_A3(0x0U)
                                            | DCIF_CSC_COEF1_L_B1(0x0U);
        base->CSC_COEF2_L[0] = DCIF_CSC_COEF2_L_B2(0x0U)
                                            | DCIF_CSC_COEF2_L_B3(0x0U);
        base->CSC_COEF3_L[0] = DCIF_CSC_COEF3_L_C1(0x0U)
                                            | DCIF_CSC_COEF3_L_C2(0x0U);
        base->CSC_COEF4_L[0] = DCIF_CSC_COEF4_L_C3(0x0U)
                                            | DCIF_CSC_COEF4_L_D1(0x0U);
        base->CSC_COEF5_L[0] = DCIF_CSC_COEF5_L_D2(0x0U)
                                            | DCIF_CSC_COEF5_L_D3(0x0U);
    }
    else
    {
        base->CSC_COEF0_L[0] = 0x0U;
        base->CSC_COEF1_L[0] = 0x0U;
        base->CSC_COEF2_L[0] = 0x0U;
        base->CSC_COEF3_L[0] = 0x0U;
        base->CSC_COEF4_L[0] = 0x0U;
        base->CSC_COEF5_L[0] = 0x0U;
	base->CSC_CTRL_L[0] |= DCIF_CSC_CTRL_L_CSC_EN(0);
    }
    base->CSC_CTRL_L[0] |= DCIF_CSC_CTRL_L_CSC_MODE(mode);
}

/*!
 * brief Set the layer source buffer configuration.
 *
 * param base DCIF peripheral base address.
 * param layerIndex Index of the layer.
 * param config Pointer to the configuration.
 */
void DCIF_SetLayerBufferConfig(DCIF_Type *base, uint8_t layerIndex, const dcif_buffer_config_t *config)
{
    assert(NULL != config);
    uint32_t reg;
    base->CTRLDESC3_L1 = config->strideBytes;
    reg = base->CTRLDESC0_L1;
    reg = (reg & ~(DCIF_CTRLDESC0_L1_FORMAT_MASK | DCIF_CTRLDESC0_L1_YUV_FORMAT_MASK | DCIF_CTRLDESC0_L1_GLOBAL_ALPHA_MASK | DCIF_CTRLDESC0_L1_AB_MODE_MASK))
	    | (uint32_t)config->pixelFormat | DCIF_CTRLDESC0_L1_GLOBAL_ALPHA(config->globalAlpha) | DCIF_CTRLDESC0_L1_AB_MODE(1U);
    base->CTRLDESC0_L1 = reg;
}
