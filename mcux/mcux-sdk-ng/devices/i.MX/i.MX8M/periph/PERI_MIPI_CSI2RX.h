/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_CSI2RX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_CSI2RX.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_CSI2RX
 *
 * CMSIS Peripheral Access Layer for MIPI_CSI2RX
 */

#if !defined(PERI_MIPI_CSI2RX_H_)
#define PERI_MIPI_CSI2RX_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- MIPI_CSI2RX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI2RX_Peripheral_Access_Layer MIPI_CSI2RX Peripheral Access Layer
 * @{
 */

/** MIPI_CSI2RX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSI2RX_CFG_NUM_LANES;              /**< offset: 0x0 */
  __IO uint32_t CSI2RX_CFG_DISABLE_DATA_LANES;     /**< offset: 0x4 */
  __I  uint32_t CSI2RX_BIT_ERR;                    /**< offset: 0x8 */
  __I  uint32_t CSI2RX_IRQ_STATUS;                 /**< offset: 0xC */
  __IO uint32_t CSI2RX_IRQ_MASK;                   /**< offset: 0x10 */
  __I  uint32_t CSI2RX_ULPS_STATUS;                /**< offset: 0x14 */
  __I  uint32_t CSI2RX_PPI_ERRSOT_HS;              /**< offset: 0x18 */
  __I  uint32_t CSI2RX_PPI_ERRSOTSYNC_HS;          /**< offset: 0x1C */
  __I  uint32_t CSI2RX_PPI_ERRESC;                 /**< offset: 0x20 */
  __I  uint32_t CSI2RX_PPI_ERRSYNCESC;             /**< offset: 0x24 */
  __I  uint32_t CSI2RX_PPI_ERRCONTROL;             /**< offset: 0x28 */
  __IO uint32_t CSI2RX_CFG_DISABLE_PAYLOAD_0;      /**< offset: 0x2C */
  __IO uint32_t CSI2RX_CFG_DISABLE_PAYLOAD_1;      /**< offset: 0x30 */
} MIPI_CSI2RX_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_CSI2RX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI2RX_Register_Masks MIPI_CSI2RX Register Masks
 * @{
 */

/*! @name CSI2RX_CFG_NUM_LANES -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_csi2rx_cfg_num_lanes_MASK (0x3U)
#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_csi2rx_cfg_num_lanes_SHIFT (0U)
/*! csi2rx_cfg_num_lanes - Sets the number of active lanes that are to be used for receiving data.
 *  0b00..1 Lane
 *  0b01..2 Lane
 *  0b10..3 Lane
 *  0b11..4 Lane
 */
#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_csi2rx_cfg_num_lanes(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_csi2rx_cfg_num_lanes_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_csi2rx_cfg_num_lanes_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_DATA_LANES -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_csi2rx_cfg_disable_data_lanes_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_csi2rx_cfg_disable_data_lanes_SHIFT (0U)
/*! csi2rx_cfg_disable_data_lanes - Setting bits to a '1' value causes the DPHY Enable signal to deassert.
 *  0b0001..Data Lane 0
 *  0b0010..Data Lane 1
 *  0b0100..Data Lane 2
 *  0b1000..Data Lane 3
 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_csi2rx_cfg_disable_data_lanes(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_csi2rx_cfg_disable_data_lanes_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_csi2rx_cfg_disable_data_lanes_MASK)
/*! @} */

/*! @name CSI2RX_BIT_ERR -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_BIT_ERR_csi2rx_bit_err_MASK (0x3FFU)
#define MIPI_CSI2RX_CSI2RX_BIT_ERR_csi2rx_bit_err_SHIFT (0U)
/*! csi2rx_bit_err - BIT_ERR: CSI-2 RX Controller ECC and CRC error status. */
#define MIPI_CSI2RX_CSI2RX_BIT_ERR_csi2rx_bit_err(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_BIT_ERR_csi2rx_bit_err_SHIFT)) & MIPI_CSI2RX_CSI2RX_BIT_ERR_csi2rx_bit_err_MASK)
/*! @} */

/*! @name CSI2RX_IRQ_STATUS -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_csi2rx_irq_status_MASK (0x1FFU)
#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_csi2rx_irq_status_SHIFT (0U)
/*! csi2rx_irq_status - CSI2 RX IRQ status */
#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_csi2rx_irq_status(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_IRQ_STATUS_csi2rx_irq_status_SHIFT)) & MIPI_CSI2RX_CSI2RX_IRQ_STATUS_csi2rx_irq_status_MASK)
/*! @} */

/*! @name CSI2RX_IRQ_MASK -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_csi2rx_irq_mask_MASK (0x1FFU)
#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_csi2rx_irq_mask_SHIFT (0U)
/*! csi2rx_irq_mask - CSI2 RX IRQ Mask setting */
#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_csi2rx_irq_mask(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_IRQ_MASK_csi2rx_irq_mask_SHIFT)) & MIPI_CSI2RX_CSI2RX_IRQ_MASK_csi2rx_irq_mask_MASK)
/*! @} */

/*! @name CSI2RX_ULPS_STATUS -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_csi2rx_ulps_status_MASK (0x3FFU)
#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_csi2rx_ulps_status_SHIFT (0U)
/*! csi2rx_ulps_status - Status of RX DPHY ULPS state */
#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_csi2rx_ulps_status(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_ULPS_STATUS_csi2rx_ulps_status_SHIFT)) & MIPI_CSI2RX_CSI2RX_ULPS_STATUS_csi2rx_ulps_status_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSOT_HS -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_csi2rx_ppi_errsot_hs_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_csi2rx_ppi_errsot_hs_SHIFT (0U)
/*! csi2rx_ppi_errsot_hs - CSI2 RX DPHY PPI ErrSotHS captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_csi2rx_ppi_errsot_hs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_csi2rx_ppi_errsot_hs_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_csi2rx_ppi_errsot_hs_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSOTSYNC_HS -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_csi2rx_ppi_errsotsync_hs_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_csi2rx_ppi_errsotsync_hs_SHIFT (0U)
/*! csi2rx_ppi_errsotsync_hs - CSI2 RX DPHY PPI ErrSotSync_HS captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_csi2rx_ppi_errsotsync_hs(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_csi2rx_ppi_errsotsync_hs_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_csi2rx_ppi_errsotsync_hs_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRESC -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_csi2rx_ppi_erresc_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_csi2rx_ppi_erresc_SHIFT (0U)
/*! csi2rx_ppi_erresc - CSI2 RX DPHY PPI ErrEsc captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_csi2rx_ppi_erresc(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRESC_csi2rx_ppi_erresc_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRESC_csi2rx_ppi_erresc_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSYNCESC -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_csi2rx_ppi_errsyncesc_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_csi2rx_ppi_errsyncesc_SHIFT (0U)
/*! csi2rx_ppi_errsyncesc - CSI2 RX DPHY PPI ErrSyncEsc captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_csi2rx_ppi_errsyncesc(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_csi2rx_ppi_errsyncesc_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_csi2rx_ppi_errsyncesc_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRCONTROL -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_csi2rx_ppi_errcontrol_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_csi2rx_ppi_errcontrol_SHIFT (0U)
/*! csi2rx_ppi_errcontrol - CSI2 RX DPHY PPI ErrControl captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_csi2rx_ppi_errcontrol(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_csi2rx_ppi_errcontrol_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_csi2rx_ppi_errcontrol_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_PAYLOAD_0 -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_null_MASK (0x1U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_null_SHIFT (0U)
/*! csi2rx_cfg_disable_payload_null - Null */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_null(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_null_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_null_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_blank_MASK (0x2U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_blank_SHIFT (1U)
/*! csi2rx_cfg_disable_payload_blank - Blank */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_blank(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_blank_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_blank_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_embedded_MASK (0x4U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_embedded_SHIFT (2U)
/*! csi2rx_cfg_disable_payload_embedded - Embedded */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_embedded(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_embedded_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_embedded_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_legacy_yuv_8_MASK (0x400U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_legacy_yuv_8_SHIFT (10U)
/*! csi2rx_cfg_disable_payload_legacy_yuv_8 - Legacy YUV 420 8 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_legacy_yuv_8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_legacy_yuv_8_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_legacy_yuv_8_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_8_MASK (0x4000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_8_SHIFT (14U)
/*! csi2rx_cfg_disable_payload_yuv_8 - YUV422 8 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_8_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_8_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_10_MASK (0x8000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_10_SHIFT (15U)
/*! csi2rx_cfg_disable_payload_yuv_10 - YUV422 10 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_10(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_10_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_yuv_10_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb444_MASK (0x10000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb444_SHIFT (16U)
/*! csi2rx_cfg_disable_payload_rgb444 - RGB444 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb444(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb444_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb444_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb555_MASK (0x20000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb555_SHIFT (17U)
/*! csi2rx_cfg_disable_payload_rgb555 - RGB555 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb555(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb555_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb555_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb565_MASK (0x40000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb565_SHIFT (18U)
/*! csi2rx_cfg_disable_payload_rgb565 - RGB565 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb565(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb565_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb565_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb666_MASK (0x80000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb666_SHIFT (19U)
/*! csi2rx_cfg_disable_payload_rgb666 - RGB666 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb666(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb666_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb666_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb888_MASK (0x100000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb888_SHIFT (20U)
/*! csi2rx_cfg_disable_payload_rgb888 - RGB888 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb888(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb888_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_rgb888_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw6_MASK (0x1000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw6_SHIFT (24U)
/*! csi2rx_cfg_disable_payload_raw6 - RAW6 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw6(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw6_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw6_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw7_MASK (0x2000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw7_SHIFT (25U)
/*! csi2rx_cfg_disable_payload_raw7 - RAW7 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw7(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw7_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw7_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw8_MASK (0x4000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw8_SHIFT (26U)
/*! csi2rx_cfg_disable_payload_raw8 - RAW8 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw8_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw8_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw10_MASK (0x8000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw10_SHIFT (27U)
/*! csi2rx_cfg_disable_payload_raw10 - RAW10 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw10(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw10_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw10_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw12_MASK (0x10000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw12_SHIFT (28U)
/*! csi2rx_cfg_disable_payload_raw12 - RAW12 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw12(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw12_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw12_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw14_MASK (0x20000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw14_SHIFT (29U)
/*! csi2rx_cfg_disable_payload_raw14 - RAW14 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw14(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw14_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_csi2rx_cfg_disable_payload_raw14_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_PAYLOAD_1 -  */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_30_MASK (0x1U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_30_SHIFT (0U)
/*! csi2rx_cfg_disable_payload_udef_30 - User defined type 0x31 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_30(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_30_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_30_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_31_MASK (0x2U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_31_SHIFT (1U)
/*! csi2rx_cfg_disable_payload_udef_31 - User defined type 0x32 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_31(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_31_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_31_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_32_MASK (0x4U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_32_SHIFT (2U)
/*! csi2rx_cfg_disable_payload_udef_32 - User defined type 0x33 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_32(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_32_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_32_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_33_MASK (0x8U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_33_SHIFT (3U)
/*! csi2rx_cfg_disable_payload_udef_33 - User defined type 0x34 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_33(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_33_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_33_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_34_MASK (0x10U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_34_SHIFT (4U)
/*! csi2rx_cfg_disable_payload_udef_34 - User defined type 0x35 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_34(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_34_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_34_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_35_MASK (0x20U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_35_SHIFT (5U)
/*! csi2rx_cfg_disable_payload_udef_35 - User defined type 0x35 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_35(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_35_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_35_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_36_MASK (0x40U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_36_SHIFT (6U)
/*! csi2rx_cfg_disable_payload_udef_36 - User defined type 0x36 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_36(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_36_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_36_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_37_MASK (0x80U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_37_SHIFT (7U)
/*! csi2rx_cfg_disable_payload_udef_37 - User defined type 0x37 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_37(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_37_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_udef_37_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_unsupported_MASK (0x10000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_unsupported_SHIFT (16U)
/*! csi2rx_cfg_disable_payload_unsupported - Unsupported Data Types */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_unsupported(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_unsupported_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_csi2rx_cfg_disable_payload_unsupported_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_CSI2RX_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_CSI2RX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MIPI_CSI2RX_H_ */

