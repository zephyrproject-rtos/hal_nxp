/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_DCIF_H_
#define FSL_DCIF_H_

#include "fsl_common.h"

#if (defined(FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET) && (0 != FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET))
#include "fsl_memory.h"
#endif

/*!
 * @addtogroup dcif
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
/*! @brief DCIF driver version */
#define FSL_DCIF_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

#if defined(FSL_FEATURE_DCIF_LAYER_COUNT) && (!defined(DCIF_LAYER_COUNT))
#define DCIF_LAYER_COUNT FSL_FEATURE_DCIF_LAYER_COUNT
#endif

#if defined(FSL_FEATURE_DCIF_LAYER_CSC_COUNT) && (!defined(DCIF_LAYER_CSC_COUNT))
#define DCIF_LAYER_CSC_COUNT FSL_FEATURE_DCIF_LAYER_CSC_COUNT
#endif

#if (defined(FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET) && (0 != FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET))
#define DCIF_ADDR_CPU_2_IP(addr) (MEMORY_ConvertMemoryMapAddress((uint32_t)(addr), kMEMORY_Local2DMA))
#else
#define DCIF_ADDR_CPU_2_IP(addr) (addr)
#endif /* FSL_FEATURE_MEMORY_HAS_ADDRESS_OFFSET */

/*! @brief DCIF FIFO empty interrupt. */
#define DCIF_MAKE_FIFO_EMPTY_INTERRUPT(layer) (1UL << ((uint32_t)(layer) + 24U))
/*! @brief DCIF DMA done interrupt. */
#define DCIF_MAKE_DMA_DONE_INTERRUPT(layer) (1UL << ((uint32_t)(layer) + 16U))
/*! @brief DCIF DMA error interrupt. */
#define DCIF_MAKE_DMA_ERROR_INTERRUPT(layer) (1UL << ((uint32_t)(layer) + 8U))


/*!
 * @brief DCIF signal polarity flags
 */
enum _dcif_polarity_flags
{
    kDCIF_VsyncActiveHigh          = 0U, /*!< VSYNC active high. */
    kDCIF_HsyncActiveHigh          = 0U, /*!< HSYNC active high. */
    kDCIF_DataEnableActiveHigh     = 0U, /*!< Data enable line active high. */
    kDCIF_DriveDataOnRisingClkEdge = 0U, /*!< Output data on rising clock edge, capture data
                                                 on falling clock edge. */
    kDCIF_DataActiveHigh = 0U,           /*!< Data active high. */

    kDCIF_VsyncActiveLow            = DCIF_DPI_CTRL_VSYNC_POL_MASK,   /*!< VSYNC active low. */
    kDCIF_HsyncActiveLow            = DCIF_DPI_CTRL_HSYNC_POL_MASK,   /*!< HSYNC active low. */
    kDCIF_DataEnableActiveLow       = DCIF_DPI_CTRL_DE_POL_MASK,      /*!< Data enable line active low. */
    kDCIF_DriveDataOnFallingClkEdge = DCIF_DPI_CTRL_PCLK_EDGE_MASK,   /*!< Output data on falling clock edge, capture
                                                                        data on rising clock edge. */
    kDCIF_DataActiveLow = DCIF_DPI_CTRL_DEF_BGND_EN_MASK,             /*!< Data active high. */
};

/*!
 * @brief The DCIF interrupts.
 */
enum _dcif_interrupt
{
    kDCIF_CrcErrorSaturationInterrupt   = DCIF_IE0_D1_CRC_ERR_SAT_EN(1),
    kDCIF_CrcErrorEnableInterrupt       = DCIF_IE0_D1_CRC_ERR_EN(1),
    kDCIF_HistogramMeasureDoneInterrupt = DCIF_IE0_D1_HIST_DONE_EN(1),
    kDCIF_FifoEmptyInterrupt            = DCIF_IE1_D1_FIFO_EMPTY_EN0(1), /*!< FIFO empty. */
    kDCIF_DmaDoneInterrupt              = DCIF_IE1_D1_DMA_DONE_EN0(1),   /*!< DMA done. */
    kDCIF_DmaErrorInterrupt             = DCIF_IE1_D1_DMA_ERR_EN0(1),  /*!< DMA error. */
    kDCIF_VerticalBlankingInterrupt     = (1U << 2U), /*!< Start of vertical blanking period. */
    kDCIF_OutputUnderrunInterrupt       = (1U << 1U), /*!< Output buffer underrun. */
    kDCIF_VsyncEdgeInterrupt            = (1U << 0U), /*!< Interrupt at VSYNC edge. */
};

/*! @brief The DCIF output line order. */
typedef enum _dcif_line_order
{
    kDCIF_LineOrderRGB = 0,         /*!< RGB */
    kDCIF_LineOrderRBG,             /*!< RBG */
    kDCIF_LineOrderGBR,             /*!< GBR */
    kDCIF_LineOrderGRB,             /*!< GRB */
    kDCIF_LineOrderBRG,             /*!< BRG */
    kDCIF_LineOrderBGR,             /*!< BGR */
    kDCIF_LineOrderRGB555,          /*!< RGB555 */
    kDCIF_LineOrderRGB565,          /*!< RGB565 */
} dcif_line_order_t;

/*!
 * @brief DCIF display configure structure.
 */
typedef struct _dcif_display_config
{
    uint16_t panelWidth;    /*!< Display panel width, pixels per line. */
    uint16_t panelHeight;   /*!< Display panel height, how many lines per panel. */
    uint8_t hsw;            /*!< HSYNC pulse width. */
    uint8_t hfp;            /*!< Horizontal front porch. */
    uint8_t hbp;            /*!< Horizontal back porch. */
    uint8_t vsw;            /*!< VSYNC pulse width. */
    uint8_t vfp;            /*!< Vrtical front porch. */
    uint8_t vbp;            /*!< Vertical back porch. */
    uint32_t polarityFlags; /*!< OR'ed value of @ref _dcif_polarity_flags, used to contol the signal polarity. */
    dcif_line_order_t lineOrder; /*!< Line order. */
} dcif_display_config_t;

/*! @brief DCIF color space conversion mode. */
typedef enum _dcif_csc_mode
{
    kDCIF_CscYUV2RGB = 0U,   /*!< YUV to RGB. */
    kDCIF_CscYCbCr2RGB,      /*!< YCbCr to RGB. */
} dcif_csc_mode_t;

/*! @brief DCIF pixel format. */
typedef enum _dcif_pixel_format
{
    kDCIF_PixelFormat1bpp      = DCIF_CTRLDESC0_L1_FORMAT(0U), /*!< 1bpp, only use for layer 0. */
    kDCIF_PixelFormat2bpp      = DCIF_CTRLDESC0_L1_FORMAT(1U), /*!< 2bpp, only use for layer 0. */
    kDCIF_PixelFormat4bpp      = DCIF_CTRLDESC0_L1_FORMAT(2U), /*!< 4bpp, only use for layer 0. */
    kDCIF_PixelFormat8bpp      = DCIF_CTRLDESC0_L1_FORMAT(3U), /*!< 8bpp, only use for layer 0. */
    kDCIF_PixelFormatRGB565    = DCIF_CTRLDESC0_L1_FORMAT(4U),   /*!< RGB565, two pixels use 32 bits. */
    kDCIF_PixelFormatARGB1555  = DCIF_CTRLDESC0_L1_FORMAT(5U),   /*!< ARGB1555, two pixels use 32 bits. */
    kDCIF_PixelFormatARGB4444  = DCIF_CTRLDESC0_L1_FORMAT(6U),   /*!< ARGB4444, two pixels use 32 bits. */
    kDCIF_PixelFormatYVYU = DCIF_CTRLDESC0_L1_FORMAT(7U) |
                               DCIF_CTRLDESC0_L1_YUV_FORMAT(0U), /*!< YVYU {Y2,V1,Y1,U1} */
    kDCIF_PixelFormatYUYV = DCIF_CTRLDESC0_L1_FORMAT(7U) |
                               DCIF_CTRLDESC0_L1_YUV_FORMAT(1U), /*!< YUYV {Y2,U1,Y1,V1} */
    kDCIF_PixelFormatVYUY =  DCIF_CTRLDESC0_L1_FORMAT(7U) |
                               DCIF_CTRLDESC0_L1_YUV_FORMAT(2U), /*!< VYUY {V1,Y2,U1,Y1} */
    kDCIF_PixelFormatUYVY = DCIF_CTRLDESC0_L1_FORMAT(7U) |
                               DCIF_CTRLDESC0_L1_YUV_FORMAT(3U), /*!< UYVY {U1,Y2,V1,Y1} */
    kDCIF_PixelFormatRGB888   = DCIF_CTRLDESC0_L1_FORMAT(8U),    /*!< RGB888 packed, one pixel uses 24 bits. */
    kDCIF_PixelFormatARGB8888 = DCIF_CTRLDESC0_L1_FORMAT(9U),    /*!< ARGB8888 unpacked, one pixel uses 32 bits. */
    kDCIF_PixelFormatABGR8888 = DCIF_CTRLDESC0_L1_FORMAT(10U),   /*!< ABGR8888 unpacked, one pixel uses 32 bits. */
} dcif_pixel_format_t;

/*! @brief DCIF source buffer configuration. */
typedef struct _dcif_buffer_config
{
    uint16_t strideBytes;
    dcif_pixel_format_t pixelFormat; /*!< Source buffer pixel format. */
    uint32_t globalAlpha;
} dcif_buffer_config_t;

#if 0
/*!
 * @brief DCIF PoterDuff alpha mode.
 */
typedef enum _dcif_pd_alpha_mode
{
    kDCIF_PD_AlphaStraight = 0, /*!< Straight mode. */
    kDCIF_PD_AlphaInversed = 1, /*!< Inversed mode. */
} dcif_pd_alpha_mode_t;
#endif

/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/*!
 * @name DCIF initialization and de-initialization
 * @{
 */

/*!
 * @brief Initializes the DCIF .
 *
 * This function ungates the DCIF  clock and release the peripheral reset.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Init(DCIF_Type *base);

/*!
 * @brief Deinitializes the DCIF peripheral.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Deinit(DCIF_Type *base);

/*!
 * @brief Reset the DCIF.
 *
 * @param base DCIF peripheral base address.
 */
void DCIF_Reset(DCIF_Type *base);

/*! @} */

/*!
 * @name Display
 * @{
 */

/*!
 * @brief Gets the DCIF display default configuration structure.
 *
 * This function sets the configuration structure to default values.
 * The default configuration is set to the following values.
 * @code
    config->panelWidth    = 0U;
    config->panelHeight   = 0U;
    config->hsw           = 3U;
    config->hfp           = 3U;
    config->hbp           = 3U;
    config->vsw           = 3U;
    config->vfp           = 3U;
    config->vbp           = 3U;
    config->polarityFlags = kDCIF_VsyncActiveHigh | kDCIF_HsyncActiveHigh | kDCIF_DataEnableActiveHigh |
                            kDCIF_DriveDataOnRisingClkEdge | kDCIF_DataActiveHigh;
    config->lineOrder       = kDCIF_LineOrderRGB;
    @endcode
 *
 * @param config Pointer to the DCIF configuration structure.
 */
void DCIF_DisplayGetDefaultConfig(dcif_display_config_t *config);

/*!
 * @brief Set the DCIF display configurations.
 *
 * @param base DCIF peripheral base address.
 * @param config Pointer to the DCIF configuration structure.
 */
void DCIF_SetDisplayConfig(DCIF_Type *base, const dcif_display_config_t *config);

/*!
 * @brief Enable or disable the display
 *
 * @param base DCIF peripheral base address.
 * @param enable Enable or disable.
 */
static inline void DCIF_EnableDisplay(DCIF_Type *base, bool enable)
{
    if (enable)
    {
        base->DISP_CTRL |= DCIF_DISP_CTRL_DISP_ON_MASK;
    }
    else
    {
        base->DISP_CTRL &= ~DCIF_DISP_CTRL_DISP_ON_MASK;
    }
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables DCIF interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
static inline void DCIF_EnableInterrupts(DCIF_Type *base, uint32_t mask)
{
    base->IE0_D2 |= mask;
}

/*!
 * @brief Disables DCIF interrupt requests.
 *
 * @param base DCIF peripheral base address.
 * @param domain CPU domain the interrupt signal routed to.
 * @param mask interrupt source, OR'ed value of _dcif_interrupt.
 */
static inline void DCIF_DisableInterrupts(DCIF_Type *base, uint8_t domain, uint32_t mask)
{
    if (domain == 0U)
        base->IE0_D1 &= ~mask;
    else
        base->IE0_D2 &= ~mask;
}

/*!
 * @brief Get DCIF interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @return Interrupt pending status, OR'ed value of _dcif_interrupt.
 */
static inline uint32_t DCIF_GetInterruptStatus(DCIF_Type *base)
{
    return base->IS0_D2;
}

/*!
 * @brief Clear DCIF interrupt peding status.
 *
 * @param base DCIF peripheral base address.
 * @param mask of the flags to clear, OR'ed value of _dcif_interrupt.
 */
static inline void DCIF_ClearInterruptStatus(DCIF_Type *base, uint32_t mask)
{
    base->IS0_D2 = mask;
}

/*! @} */


/*!
 * @name Layer operation
 * @{
 */

/*!
 * @brief Set the layer origin position.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 * @param posy Layer vertical position.
 * @param posx Layer horizontal position.
 *
 */
static inline void DCIF_SetLayerPosition(DCIF_Type *base, uint8_t layerIndex, uint16_t posy, uint16_t posx)
{
    if (layerIndex == 0)
    {
        base->CTRLDESC1_L0 =
            ((uint32_t)posx << DCIF_CTRLDESC1_L0_POSX_SHIFT) | ((uint32_t)posy << DCIF_CTRLDESC1_L0_POSY_SHIFT);
    }
    else
    {
        base->CTRLDESC1_L1 =
            ((uint32_t)posx << DCIF_CTRLDESC1_L1_POSX_SHIFT) | ((uint32_t)posy << DCIF_CTRLDESC1_L1_POSY_SHIFT);
    }
}

/*!
 * @brief Set the layer dimension.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 * @param width Layer width in pixel.
 * @param height Layer height.
 *
 */
static inline void DCIF_SetLayerSize(DCIF_Type *base, uint8_t layerIndex, uint16_t width, uint16_t height)
{
    if (layerIndex == 0)
    {
        base->CTRLDESC2_L0 =
            ((uint32_t)height << DCIF_CTRLDESC2_L0_HEIGHT_SHIFT) | ((uint32_t)width << DCIF_CTRLDESC2_L0_WIDTH_SHIFT);
    }
    else
    {
        base->CTRLDESC2_L1 =
            ((uint32_t)height << DCIF_CTRLDESC2_L1_HEIGHT_SHIFT) | ((uint32_t)width << DCIF_CTRLDESC2_L1_WIDTH_SHIFT);
    }
}

/*!
 * @brief Set the layer source buffer configuration.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 * @param config Pointer to the configuration.
 */
void DCIF_SetLayerBufferConfig(DCIF_Type *base, uint8_t layerIndex, const dcif_buffer_config_t *config);

/*!
 * @brief Set the layer source buffer address.
 *
 * This function is used for fast runtime source buffer change.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 * @param addr The new source buffer address passed to the layer, should be 16-bit aligned.
 */
static inline void DCIF_SetLayerBufferAddr(DCIF_Type *base, uint8_t layerIndex, uint32_t addr)
{
    if (layerIndex == 0)
    {
        base->CTRLDESC4_L0 = DCIF_CTRLDESC4_L0_ADDR(addr);
    }
    else
    {
        base->CTRLDESC4_L1 = DCIF_CTRLDESC4_L1_ADDR(addr);
    }
}

/*!
 * @brief Enable or disable the layer.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 * @param enable Pass in true to enable, false to disable.
 */

static inline void DCIF_EnableLayer(DCIF_Type *base, uint8_t layerIndex, bool enable)
{
    if (enable)
    {
        base->CTRLDESC0_L1 |= DCIF_CTRLDESC0_L1_EN_MASK;
    }
    else
    {
        base->CTRLDESC0_L1 &= ~DCIF_CTRLDESC0_L1_EN_MASK;
    }
}


/*!
 * @brief Trigger the layer configuration shadow load.
 *
 * The new layer configurations are written to the shadow registers first,
 * When all configurations written finished, call this function, then shadowed
 * control registers are updated to the active control registers on VSYNC of
 * next frame.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Layer layerIndex.
 */
static inline void DCIF_TriggerLayerShadowLoad(DCIF_Type *base, uint8_t layerIndex)
{
    if (layerIndex == 0)
    {
        base->CTRLDESC0_L0 |= DCIF_CTRLDESC0_L0_SHADOW_LOAD_EN_MASK;
    }
    else
    {
        base->CTRLDESC0_L1 |= DCIF_CTRLDESC0_L1_SHADOW_LOAD_EN_MASK;
    }
}

/*!
 * @brief Set the color space conversion mode.
 *
 * Supports YUV2RGB and YCbCr2RGB.
 *
 * @param base DCIF peripheral base address.
 * @param layerIndex Index of the layer.
 * @param mode The conversion mode.
 */
void DCIF_SetCscMode(DCIF_Type *base, dcif_csc_mode_t mode);

/*! @} */

#if defined(__cplusplus)
}
#endif /* __cplusplus */

/*! @} */

#endif /*FSL_DCIF_H_*/
