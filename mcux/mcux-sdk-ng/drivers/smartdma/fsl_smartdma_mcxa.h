/*
 * Copyright 2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_SMARTDMA_MCXA_H_
#define FSL_SMARTDMA_MCXA_H_

#include "fsl_common.h"

/*!
 * @addtogroup smartdma_mcxn MCXN SMARTDMA Firmware
 * @ingroup smartdma
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @brief The firmware used for display. */
extern const uint8_t s_smartdmaDisplayFirmware[];

/*! @brief The s_smartdmaDisplayFirmware firmware memory address. */
#define SMARTDMA_DISPLAY_MEM_ADDR 0x04000000U

/*! @brief Size of s_smartdmaDisplayFirmware */
#define SMARTDMA_DISPLAY_FIRMWARE_SIZE (s_smartdmaDisplayFirmwareSize)

/*! @brief Size of s_smartdmaDisplayFirmware */
extern const uint32_t s_smartdmaDisplayFirmwareSize;

/*! @brief The firmware used for camera. */
extern const uint8_t s_smartdmaCameraFirmware[];

/*! @brief The s_smartdmaCameraFirmware firmware memory address. */
#define SMARTDMA_CAMERA_MEM_ADDR 0x04000000U

/*! @brief Size of s_smartdmacameraFirmware */
#define SMARTDMA_CAMERA_FIRMWARE_SIZE (s_smartdmaCameraFirmwareSize)

/*! @brief Size of s_smartdmacameraFirmware */
extern const uint32_t s_smartdmaCameraFirmwareSize;

/*! @brief The firmware used for keyscan. */
extern const uint8_t s_smartdmaKeyscanFirmware[];

/*! @brief The s_smartdmaKeyscanFirmware firmware memory address. */
#define SMARTDMA_KEYSCAN_MEM_ADDR 0x04000000U

/*! @brief Size of s_smartdmaKeyscanFirmware */
#define SMARTDMA_KEYSCAN_FIRMWARE_SIZE (s_smartdmaKeyscanFirmwareSize)

/*! @brief Size of s_smartdmaKeyscanFirmware */
extern const uint32_t s_smartdmaKeyscanFirmwareSize;

/*!
 * @brief The API index when using s_smartdmaDisplayFirmware.
 */
enum _smartdma_display_api
{
    kSMARTDMA_FlexIO_DMA = 0U,
};

/*!
 * @brief Parameter for FlexIO MCULCD
 */
typedef struct _smartdma_flexio_mculcd_param
{
    uint32_t *p_buffer;
    uint32_t buffersize;
    uint32_t *smartdma_stack;
} smartdma_flexio_mculcd_param_t;

/*!
 * @brief The API index when using s_smartdmaCameraFirmware
 */
enum _smartdma_camera_api
{
    kSMARTDMA_FlexIO_CameraWholeFrame = 0U, /*! Deprecated. Use kSMARTDMA_CameraWholeFrameQVGA instead. */
    kSMARTDMA_FlexIO_CameraDiv16Frame = 1U, /*! Deprecated. Use kSMARTDMA_CameraDiv16FrameQVGA instead. */
    /*! Save whole frame of QVGA(320x240) to buffer in each interrupt in RGB565 format. */
    kSMARTDMA_CameraWholeFrameQVGA = 0U,
    /*! Save 1/16 frame of QVGA(320x240) to buffer in each interrupt in RGB565 format,
  takes 16 interrupts to get the whole frame. */
    kSMARTDMA_CameraDiv16FrameQVGA = 1U,
    /*! Save whole frame of 480x320 to buffer in each interrupt in RGB565 format. */
    kSMARTDMA_CameraWholeFrame480_320 = 2U,
    /*! Save 1/4 frame of QVGA(320x240) to buffer in each interrupt in grayscale format,
     takes 4 interrupts to get the whole frame. */
    kSMARTDMA_CameraDiv4FrameQVGAGrayScale = 3U,
    /*! Save 1/16 frame of QVGA(320x240) to buffer in each interrupt in grayscale format,
  takes 16 interrupts to get the whole frame. */
    kSMARTDMA_CameraDiv16FrameQVGAGrayScale = 4U,
    /*! Save 1/16 frame of 384x384 to buffer in each interrupt in grayscale format,
  takes 16 interrupts to get the whole frame. */
    kSMARTDMA_CameraDiv16Frame384_384 = 5U,
    /*! Save whole frame of 320x480 to buffer in each interrupt in RGB565 format. */
    kSMARTDMA_CameraWholeFrame320_480 = 6U,
};

/*!
 * @brief The API index when using s_smartdmaKeyscanFirmware
 */
enum _smartdma_keyscan_api
{
    /*! Using SmartDma to control GPIO. */
    kSMARTDMA_Keyscan_4x4 = 0U,
};

/*!
 * @brief Parameter for camera
 */
typedef struct _smartdma_camera_param
{
    uint32_t *smartdma_stack; /*!< Stack used by SMARTDMA, shall be at least 64 bytes. */
    uint32_t *p_buffer;       /*!< Buffer to store the received camera data. */
    uint32_t *p_stripe_index; /*!< Pointer to stripe index. Used when only partial frame is received per interrupt. */
    uint32_t *p_buffer_ping_pong; /*!< Buffer to store the 2nd stripe of camera data. Used when only partial frame is
                                     received per interrupt. */
} smartdma_camera_param_t;

/*!
 * @brief Parameter for all supported APIs.
 */
typedef union
{
    smartdma_flexio_mculcd_param_t flexioMcuLcdParam;  /*!< Parameter for flexio MCULCD. */
    smartdma_camera_param_t cameraParam;               /*!< Parameter for camera. */
} smartdma_param_t;

/*!
 * @brief Parameter for keyscan 4x4
 */
typedef struct _smartdma_keyscan_4x4_param
{
    uint32_t *smartdma_stack;           /*!< Stack used by SMARTDMA, shall be at least 64 bytes. */
    uint32_t *p_gpio_reg;               /*!< Buffer to provide GPIO register for COL1, COL2, COL3, COL4, ROW1, ROW2, ROW3, ROW4. */
    uint32_t *p_keyvalue;               /*!< Buffer to store key value. */
    uint32_t *p_keycan_interval;        /*!< Delay how many system clock cycles. */
} smartdma_keyscan_4x4_param_t;

/*******************************************************************************
 * APIs
 ******************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if defined(__cplusplus)
}
#endif

/*! @} */

#endif /* FSL_SMARTDMA_MCXA_H_ */
