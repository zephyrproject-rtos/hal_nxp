/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef FSL_CAMERA_CSR_H_
#define FSL_CAMERA_CSR_H_

#include "fsl_common.h"
#include "fsl_dwc_mipi_csi2rx.h"

/*!
 * @addtogroup camera_csr
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*! @brief CAMERA CSR configuration. */
typedef struct _camera_csr_pixel_formatting_config
{
    bool  enablePixelDataRoute;              /*!< whether enable pixel data route to a new channel. */
    bool  enableNonPixelDataRoute;           /*!< whether enable non-pixel data route to a new channel. */
    bool  enableRAW32;                       /*!< whether enable RAW32 mode for specific channel which up to 4 pixels per clock cycle can be transported. */
    csi2rx_payload_t PixelDataType;          /*!< transport pixel data type. */
    uint32_t NonPixelDataType;               /*!< transport non-pixel data type. */
    uint8_t  PixelDataNewVc;                 /*!< new virtual channel on which the pixel data are transported. */
    uint8_t  NonPixelDataNewVc;              /*!< new virtual channel on which the non pixel data are transported. */
    uint32_t mipiVc;                         /*!< virtual channel from csi host idi interface. */
    uint8_t  csiinterface;                   /*!< csi ininterface number */
}camera_csr_pixel_formatting_config_t;

typedef struct pixel_link_transfer_pixel_data
{
    csi2rx_payload_t     datatype;  /* pixel data type */
    uint8_t              index;     /* pixel link module data index */
} pixel_link_transfer_pixel_data_t;

/*! @name Driver version */
/*@{*/
/*! @brief Camera Csr driver version. */
#define FSL_Camera_Csr_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*******************************************************************************
 * API
 ******************************************************************************/
#if defined(__cplusplus)
extern "C" {
#endif
/*!
 * @brief Get CAMERA CSR Pixel Data type index.
 * This function get pinxe index by data type.
 *
 * @param camera_csr BLK_CTRL_CAMERAMIX module periperal address.
 */
uint32_t CAMERACSR_GetPixelDataIndex(csi2rx_payload_t datatype);

/*!
 * @brief introduce function CAMERACSR_PixelFormatting.
 * This function control the data process channel from CSI host to ISI pixel link module.
 *
 * @param camera_csr BLK_CTRL_CAMERAMIX module periperal address.
 * @param config pixel link module camera_csr formatting configuration structure.
 */
void CAMERACSR_PixelFormatting(BLK_CTRL_CAMERAMIX_Type *camera_csr, camera_csr_pixel_formatting_config_t *config);

#if defined(__cplusplus)
}
#endif

/*!
 *@}
 */

#endif /* _FSL_MIPI_CSI2RX_H_ */