/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_REFORMATTER_H_
#define FSL_REFORMATTER_H_

#include "fsl_common.h"

/*!
 * @addtogroup reformatter
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @name Driver version */
/*! @{ */
#define FSL_REFORMATTER_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*! @} */

/*! @brief Raw data shift control. */
typedef enum _reformatter_mipi_csi_data_shift
{
    kREFORMATTER_ShiftLsb  = 0U, /*!< MIPI-CSI Raw data is shifted and sligned to LSB. */
    kREFORMATTER_ShiftNone = 1U  /*!< No data shift. */
} reformatter_mipi_csi_data_shift_t;

/*! @brief Virtual channel data fencing mask. */
enum _reformatter_stream_fence
{
    kREFORMATTER_FenceCh0 = (1U << 0U), /*!< Fence virtual channel 0 data stream. */
    kREFORMATTER_FenceCh1 = (1U << 1U), /*!< Fence virtual channel 1 data stream. */
    kREFORMATTER_FenceCh2 = (1U << 2U), /*!< Fence virtual channel 2 data stream. */
    kREFORMATTER_FenceCh3 = (1U << 3U), /*!< Fence virtual channel 3 data stream. */
};

/*!
 * @brief Pixel link signal configuration.
 */
typedef struct _reformatter_signal_config
{
    uint8_t enable : 1U; /*!< Enable pixel link signal. */
    uint8_t vsyncForceHigh : 1U; /*!< Force VSYNC to be 1. */
    uint8_t hsyncForceHigh : 1U; /*!< Force HSYNC to be 1. */
    uint8_t validForceHigh : 1U; /*!< Force valid to be 1.TODO */
    uint8_t syncInvert : 1U; /*!< Invert the polarity of the hsync/vsync signal. */
} reformatter_signal_config_t;

/*! @brief The line order when the MIPI-CSI pixel format is YUV420.
 * For legacy 8-bit, the UY/VY component is sent in odd/even line;
 * for 8-bit and 10-bit, the Y/UV component is sent in odd/even line.
 */
typedef enum _reformatter_yuv420_line_order
{
    kREFORMATTER_YUV420OddFirst = 0U, /*!< Odd line sent first. */
    kREFORMATTER_YUV420EvenFirst = 1U, /*!< Even line sent first. */
} reformatter_yuv420_line_order_t;

/*! @brief Mask of which data types to disable. */
enum _reformatter_type_disable
{
    kREFORMATTER_DisableYUV420_8Bit       = (1U << 0U), /*!< Disable YUV420 8Bit. */
    kREFORMATTER_DisableYUV420_10Bit      = (1U << 1U), /*!< Disable YUV420 10Bit. */
    kREFORMATTER_DisableYUV420_8BitLegacy = (1U << 2U), /*!< Disable Legacy YUV420 8Bit. */
    kREFORMATTER_DisableYUV420_8BitCS     = (1U << 4U), /*!< Disable YUV420 8BitCS. */
    kREFORMATTER_DisableYUV420_10BitCS    = (1U << 5U), /*!< Disable YUV420 10BitCS. */
    kREFORMATTER_DisableYUV422_8Bit       = (1U << 6U), /*!< Disable YUV422 8Bit. */
    kREFORMATTER_DisableYUV422_10Bit      = (1U << 7U), /*!< Disable YUV422 10Bit. */
    kREFORMATTER_DisableRGB444            = (1U << 8U), /*!< Disable RGB444. */
    kREFORMATTER_DisableRGB555            = (1U << 9U), /*!< Disable RGB555. */
    kREFORMATTER_DisableRGB565            = (1U << 10U), /*!< Disable RGB565. */
    kREFORMATTER_DisableRGB666            = (1U << 11U), /*!< Disable RGB666. */
    kREFORMATTER_DisableRGB888            = (1U << 12U), /*!< Disable RGB888. */
    kREFORMATTER_DisableRawEmbedded       = (1U << 14U), /*!< Disable Embedded Raw. */
    kREFORMATTER_DisableRaw24             = (1U << 15U), /*!< Disable Raw 24. */
    kREFORMATTER_DisableRaw6              = (1U << 16U), /*!< Disable Raw 6. */
    kREFORMATTER_DisableRaw7              = (1U << 17U), /*!< Disable Raw 7. */
    kREFORMATTER_DisableRaw8              = (1U << 18U), /*!< Disable Raw 8. */
    kREFORMATTER_DisableRaw10             = (1U << 19U), /*!< Disable Raw 10. */
    kREFORMATTER_DisableRaw12             = (1U << 20U), /*!< Disable Raw 12 . */
    kREFORMATTER_DisableRaw14             = (1U << 21U), /*!< Disable Raw 14 . */
    kREFORMATTER_DisableRaw16             = (1U << 22U), /*!< Disable Raw 16. */
    kREFORMATTER_DisableRaw20             = (1U << 23U), /*!< Disable Raw 20. */
};

/*! @brief Interlace mode mask for virtual channels when the data type is YUV420.
 * If set, the odd lines and even lines are sent in different frames(interlaced).
 */
enum _reformatter_yuv420_interlace
{
    kREFORMATTER_YUV420InterlaceCh0OddFirst  = (1U << 0U), /*!< Channel 0 interlaced mode enable, odd line sent first. */
    kREFORMATTER_YUV420InterlaceCh0EvenFirst = (1U << 0U) | (1U << 4U), /*!< Channel 0 interlaced mode enable, even line sent first. */
    kREFORMATTER_YUV420InterlaceCh1OddFirst  = (1U << 1U), /*!< Channel 1 interlaced mode enable, odd line sent first. */
    kREFORMATTER_YUV420InterlaceCh1EvenFirst = (1U << 1U) | (1U << 5U), /*!< Channel 1 interlaced mode enable, even line sent first. */
    kREFORMATTER_YUV420InterlaceCh2OddFirst  = (1U << 2U), /*!< Channel 2 interlaced mode enable, odd line sent first. */
    kREFORMATTER_YUV420InterlaceCh2EvenFirst = (1U << 2U) | (1U << 6U), /*!< Channel 2 interlaced mode enable, even line sent first. */
    kREFORMATTER_YUV420InterlaceCh3OddFirst  = (1U << 3U), /*!< Channel 3 interlaced mode enable, odd line sent first. */
    kREFORMATTER_YUV420InterlaceCh3EvenFirst = (1U << 3U) | (1U << 7U), /*!< Channel 3 interlaced mode enable, even line sent first. */
};

/*! @brief Interrupt and status. */
enum _reformatter_interrupt
{
    kREFORMATTER_InterruptIsiDataNotRGB888 = (1U << 0U), /*!< The data type of ISI to pixel link is not RGB888 interrupt. */
};

/*!
 * @brief REFORMATTER configuration.
 */
typedef struct _reformatter_config
{
    reformatter_mipi_csi_data_shift_t dataShift; /*!< Data shift control. */
    uint8_t streamFence; /*!< Mask of which data streams to fence, enable the fence to
                            prevent the data coming from MIPI for the corresponding VC to
                            get converted. @ref _reformatter_stream_fence. */
    reformatter_signal_config_t signalConfig; /*!< Pixel link signal configuration. */
    reformatter_yuv420_line_order_t yuv420LineOrder : 1U; /*!< YUV420 line order. */
    uint8_t yuv420Interlace; /*!< Interlace mode mask for virtual channels when the data type is YUV420,
                                @ref _reformatter_yuv420_interlace. */
    bool enableConversion; /*!< Enable pixel conversion from ISI to PDI. */
    uint8_t interupt; /*!< Interrupt enable mask. */
    uint32_t typeDisable; /*!< Mask of which data types to disable, @ref _reformatter_type_disable. */
} reformatter_config_t;

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @name Initialization and deinitialization
 * @{
 */

/*!
 * @brief Initializes the REFORMATTER.
 *
 * The default configuration can be got by calling REFORMATTER_GetDefaultConfig().
 *
 * @param base REFORMATTER peripheral base address.
 * @param config Pointer to REFORMATTER configuration structure.
 */
void REFORMATTER_Init(REFORMATTER_Type *base, const reformatter_config_t *config);

/*!
 * @brief Disables the REFORMATTER peripheral module.
 *
 * @param base REFORMATTER peripheral address.
 */
void REFORMATTER_Deinit(REFORMATTER_Type *base);

/*!
 * @brief Set default values to the REFORMATTER configuration structure.
 *
 * The default values are as follows.
 * @code
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
 * @endcode
 *
 * @param config REFORMATTER module configuration structure.
 */
void REFORMATTER_GetDefaultConfig(reformatter_config_t *config);

/*!
 * @brief Gets the fencing state of the virtual channels.
 *
 * @param base REFORMATTER peripheral address.
 * @return Mask of the virtual channel fencing state.
 */
static inline uint8_t REFORMATTER_GetVcFenceState(REFORMATTER_Type *base)
{
    return (uint8_t)base->STREAM_FENCING_STAT.RW;
}

/*! @} */

/*!
 * @name Interrupts
 * @{
 */

/*!
 * @brief Enables REFORMATTER interrupt requests.
 *
 * @param base REFORMATTER peripheral base address.
 * @param mask The interrupts to enable, pass in as OR'ed value of @ref _reformatter_interrupt.
 */
static inline void REFORMATTER_EnableInterrupts(REFORMATTER_Type *base, uint8_t mask)
{
    base->ISI2PL_IER |= mask;
}

/*!
 * @brief Disable REFORMATTER interrupt requests.
 *
 * @param base REFORMATTER peripheral base address.
 * @param mask The interrupts to disable, pass in as OR'ed value of @ref _reformatter_interrupt.
 */
static inline void REFORMATTER_DisableInterrupts(REFORMATTER_Type *base, uint8_t mask)
{
    base->ISI2PL_IER &= ~mask;
}

/*!
 * @brief Get and clear REFORMATTER interrupt status.
 *
 * @param base REFORMATTER peripheral base address.
 * @return The interrupt status.
 */
static inline uint8_t REFORMATTER_GetAndClearInterruptFlags(REFORMATTER_Type *base)
{
    uint8_t status = (uint8_t)(base->ISI2PL_ISTS);
    base->ISI2PL_ISTS = (uint32_t)status; /* Clear the interrupt flags by writing 1 to it. */
    return status;
}

/*! @} */

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* FSL_REFORMATTER_H_ */
