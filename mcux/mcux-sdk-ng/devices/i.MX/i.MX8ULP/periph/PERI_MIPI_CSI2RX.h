/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
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
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_CSI2RX.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_CSI2RX
 *
 * CMSIS Peripheral Access Layer for MIPI_CSI2RX
 */

#if !defined(PERI_MIPI_CSI2RX_H_)
#define PERI_MIPI_CSI2RX_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
       uint8_t RESERVED_0[256];
  __IO uint32_t CSI2RX_CFG_NUM_LANES;              /**< Lane Configuration Register, offset: 0x100 */
  __IO uint32_t CSI2RX_CFG_DISABLE_DATA_LANES;     /**< Disable Data Lane Register, offset: 0x104 */
  __I  uint32_t CSI2RX_BIT_ERR;                    /**< ECC and CRC Error Status Register, offset: 0x108 */
  __I  uint32_t CSI2RX_IRQ_STATUS;                 /**< IRQ Status Register, offset: 0x10C */
  __IO uint32_t CSI2RX_IRQ_MASK;                   /**< IRQ Mask Setting Register, offset: 0x110 */
  __I  uint32_t CSI2RX_ULPS_STATUS;                /**< Ultra Low Power State (ULPS) Status Register, offset: 0x114 */
  __I  uint32_t CSI2RX_PPI_ERRSOT_HS;              /**< ERRSot HS Status Register, offset: 0x118 */
  __I  uint32_t CSI2RX_PPI_ERRSOTSYNC_HS;          /**< ErrSotSync HS Status Register, offset: 0x11C */
  __I  uint32_t CSI2RX_PPI_ERRESC;                 /**< ErrEsc Status Register, offset: 0x120 */
  __I  uint32_t CSI2RX_PPI_ERRSYNCESC;             /**< ErrSyncEsc Status Register, offset: 0x124 */
  __I  uint32_t CSI2RX_PPI_ERRCONTROL;             /**< ErrControl Status Register, offset: 0x128 */
  __IO uint32_t CSI2RX_CFG_DISABLE_PAYLOAD_0;      /**< Disable Payload 0 Register, offset: 0x12C */
  __IO uint32_t CSI2RX_CFG_DISABLE_PAYLOAD_1;      /**< Disable Payload 1 Register, offset: 0x130 */
} MIPI_CSI2RX_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_CSI2RX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI2RX_Register_Masks MIPI_CSI2RX Register Masks
 * @{
 */

/*! @name CSI2RX_CFG_NUM_LANES - Lane Configuration Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_CFG_NUM_LANES_MASK (0x3U)
#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT (0U)
/*! CFG_NUM_LANES - Sets the number of active lanes that are to be used for receiving data. */
#define MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_CFG_NUM_LANES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_CFG_NUM_LANES_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_NUM_LANES_CFG_NUM_LANES_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_DATA_LANES - Disable Data Lane Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_CFG_DISABLE_DATA_LANES_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_CFG_DISABLE_DATA_LANES_SHIFT (0U)
/*! CFG_DISABLE_DATA_LANES - Forces DPHY Enable_n signals to 1'b0 when register is set to 1.
 *  0b0000..Data Lane 0
 *  0b0001..Data Lane 1.
 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_CFG_DISABLE_DATA_LANES(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_CFG_DISABLE_DATA_LANES_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_DATA_LANES_CFG_DISABLE_DATA_LANES_MASK)
/*! @} */

/*! @name CSI2RX_BIT_ERR - ECC and CRC Error Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_BIT_ERR_BIT_ERR_MASK  (0x3FFU)
#define MIPI_CSI2RX_CSI2RX_BIT_ERR_BIT_ERR_SHIFT (0U)
/*! BIT_ERR - Captures the first Error event when either a one or two bit error occurs, with only
 *    the one bit error providing position information.
 */
#define MIPI_CSI2RX_CSI2RX_BIT_ERR_BIT_ERR(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_BIT_ERR_BIT_ERR_SHIFT)) & MIPI_CSI2RX_CSI2RX_BIT_ERR_BIT_ERR_MASK)
/*! @} */

/*! @name CSI2RX_IRQ_STATUS - IRQ Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_IRQ_STATUS_MASK (0x1FFU)
#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_IRQ_STATUS_SHIFT (0U)
/*! IRQ_STATUS - Status of IRQ. Rx Controller irq_out output is the result of anding these bits with
 *    IRQ_MASK and then ORing the individual resultant bits together. The status bits get cleared
 *    when read.
 */
#define MIPI_CSI2RX_CSI2RX_IRQ_STATUS_IRQ_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_IRQ_STATUS_IRQ_STATUS_SHIFT)) & MIPI_CSI2RX_CSI2RX_IRQ_STATUS_IRQ_STATUS_MASK)
/*! @} */

/*! @name CSI2RX_IRQ_MASK - IRQ Mask Setting Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_IRQ_MASK_MASK (0x1FFU)
#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_IRQ_MASK_SHIFT (0U)
/*! IRQ_MASK - This field shows the IRQ Mask setting. */
#define MIPI_CSI2RX_CSI2RX_IRQ_MASK_IRQ_MASK(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_IRQ_MASK_IRQ_MASK_SHIFT)) & MIPI_CSI2RX_CSI2RX_IRQ_MASK_IRQ_MASK_MASK)
/*! @} */

/*! @name CSI2RX_ULPS_STATUS - Ultra Low Power State (ULPS) Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_ULPS_STATUS_MASK (0x3FFU)
#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_ULPS_STATUS_SHIFT (0U)
#define MIPI_CSI2RX_CSI2RX_ULPS_STATUS_ULPS_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_ULPS_STATUS_ULPS_STATUS_SHIFT)) & MIPI_CSI2RX_CSI2RX_ULPS_STATUS_ULPS_STATUS_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSOT_HS - ERRSot HS Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_PPI_ERRSOT_HS_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_PPI_ERRSOT_HS_SHIFT (0U)
/*! PPI_ERRSOT_HS - This field indicates PPI ErrSotHS captured status from DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_PPI_ERRSOT_HS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_PPI_ERRSOT_HS_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSOT_HS_PPI_ERRSOT_HS_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSOTSYNC_HS - ErrSotSync HS Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_PPI_ERRSOTSYNC_HS_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_PPI_ERRSOTSYNC_HS_SHIFT (0U)
/*! PPI_ERRSOTSYNC_HS - This field indicates PPI ErrSotSync_HS captured status from DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_PPI_ERRSOTSYNC_HS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_PPI_ERRSOTSYNC_HS_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSOTSYNC_HS_PPI_ERRSOTSYNC_HS_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRESC - ErrEsc Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_PPI_ERRESC_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_PPI_ERRESC_SHIFT (0U)
/*! PPI_ERRESC - This field indicates PPI ErrEsc captured status from DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRESC_PPI_ERRESC(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRESC_PPI_ERRESC_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRESC_PPI_ERRESC_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRSYNCESC - ErrSyncEsc Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_PPI_ERRSYNCESC_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_PPI_ERRSYNCESC_SHIFT (0U)
/*! PPI_ERRSYNCESC - CSI2 RX DPHY PPI ErrSyncEsc captured status from the DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_PPI_ERRSYNCESC(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_PPI_ERRSYNCESC_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRSYNCESC_PPI_ERRSYNCESC_MASK)
/*! @} */

/*! @name CSI2RX_PPI_ERRCONTROL - ErrControl Status Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_PPI_ERRCONTROL_MASK (0xFU)
#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_PPI_ERRCONTROL_SHIFT (0U)
/*! PPI_ERRCONTROL - This field indicates PPI ErrControl captured status from DPHY. */
#define MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_PPI_ERRCONTROL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_PPI_ERRCONTROL_SHIFT)) & MIPI_CSI2RX_CSI2RX_PPI_ERRCONTROL_PPI_ERRCONTROL_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_PAYLOAD_0 - Disable Payload 0 Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_NULL_MASK (0x1U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_NULL_SHIFT (0U)
/*! DIS_PAYLOAD_NULL - Null */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_NULL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_NULL_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_NULL_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_BLANK_MASK (0x2U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_BLANK_SHIFT (1U)
/*! DIS_PAYLOAD_BLANK - Blank */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_BLANK(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_BLANK_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_BLANK_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_EMBEDDED_MASK (0x4U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_EMBEDDED_SHIFT (2U)
/*! DIS_PAYLOAD_EMBEDDED - Embedded */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_EMBEDDED(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_EMBEDDED_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_EMBEDDED_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV420_MASK (0x400U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV420_SHIFT (10U)
/*! DIS_PAYLOAD_YUV420 - Legacy YUV 420 8 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV420(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV420_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV420_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_8BIT_MASK (0x4000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_8BIT_SHIFT (14U)
/*! DIS_PAYLOAD_YUV422_8BIT - YUV422 8 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_8BIT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_8BIT_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_8BIT_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_10BIT_MASK (0x8000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_10BIT_SHIFT (15U)
/*! DIS_PAYLOAD_YUV422_10BIT - YUV422 10 bit */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_10BIT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_10BIT_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_YUV422_10BIT_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB444_MASK (0x10000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB444_SHIFT (16U)
/*! DIS_PAYLOAD_RGB444 - RGB444 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB444(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB444_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB444_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB555_MASK (0x20000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB555_SHIFT (17U)
/*! DIS_PAYLOAD_RGB555 - RGB555 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB555(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB555_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB555_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB565_MASK (0x40000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB565_SHIFT (18U)
/*! DIS_PAYLOAD_RGB565 - RGB565 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB565(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB565_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB565_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB666_MASK (0x80000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB666_SHIFT (19U)
/*! DIS_PAYLOAD_RGB666 - RGB666 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB666(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB666_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB666_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB888_MASK (0x100000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB888_SHIFT (20U)
/*! DIS_PAYLOAD_RGB888 - RGB888 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB888(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB888_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RGB888_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW6_MASK (0x1000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW6_SHIFT (24U)
/*! DIS_PAYLOAD_RAW6 - RAW6 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW6(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW6_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW6_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW8_MASK (0x4000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW8_SHIFT (26U)
/*! DIS_PAYLOAD_RAW8 - RAW8 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW8(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW8_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW8_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW10_MASK (0x8000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW10_SHIFT (27U)
/*! DIS_PAYLOAD_RAW10 - RAW10 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW10(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW10_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW10_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW12_MASK (0x10000000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW12_SHIFT (28U)
/*! DIS_PAYLOAD_RAW12 - RAW12 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW12(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW12_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_0_DIS_PAYLOAD_RAW12_MASK)
/*! @} */

/*! @name CSI2RX_CFG_DISABLE_PAYLOAD_1 - Disable Payload 1 Register */
/*! @{ */

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_30_MASK (0x1U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_30_SHIFT (0U)
/*! DIS_PAYLOAD_UDEF_30 - User defined type 0x30 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_30(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_30_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_30_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_31_MASK (0x2U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_31_SHIFT (1U)
/*! DIS_PAYLOAD_UDEF_31 - User defined type 0x31 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_31(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_31_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_31_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_32_MASK (0x4U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_32_SHIFT (2U)
/*! DIS_PAYLOAD_UDEF_32 - User defined type 0x32 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_32(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_32_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_32_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_33_MASK (0x8U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_33_SHIFT (3U)
/*! DIS_PAYLOAD_UDEF_33 - User defined type 0x33 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_33(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_33_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_33_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_34_MASK (0x10U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_34_SHIFT (4U)
/*! DIS_PAYLOAD_UDEF_34 - User defined type 0x34 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_34(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_34_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_34_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_35_MASK (0x20U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_35_SHIFT (5U)
/*! DIS_PAYLOAD_UDEF_35 - User defined type 0x35 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_35(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_35_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_35_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_36_MASK (0x40U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_36_SHIFT (6U)
/*! DIS_PAYLOAD_UDEF_36 - User defined type 0x36 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_36(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_36_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_36_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_37_MASK (0x80U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_37_SHIFT (7U)
/*! DIS_PAYLOAD_UDEF_37 - User defined type 0x37 */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_37(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_37_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UDEF_37_MASK)

#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UNSUPPORTED_MASK (0x10000U)
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UNSUPPORTED_SHIFT (16U)
/*! DIS_PAYLOAD_UNSUPPORTED - Unsupported Data Types */
#define MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UNSUPPORTED(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UNSUPPORTED_SHIFT)) & MIPI_CSI2RX_CSI2RX_CFG_DISABLE_PAYLOAD_1_DIS_PAYLOAD_UNSUPPORTED_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_MIPI_CSI2RX_H_ */

