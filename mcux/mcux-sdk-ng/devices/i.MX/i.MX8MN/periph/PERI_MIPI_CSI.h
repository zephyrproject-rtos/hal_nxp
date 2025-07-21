/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_CSI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_CSI.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_CSI
 *
 * CMSIS Peripheral Access Layer for MIPI_CSI
 */

#if !defined(PERI_MIPI_CSI_H_)
#define PERI_MIPI_CSI_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- MIPI_CSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_Peripheral_Access_Layer MIPI_CSI Peripheral Access Layer
 * @{
 */

/** MIPI_CSI - Size of Registers Arrays */
#define MIPI_CSI_ISP_CONFIGn_COUNT                4u
#define MIPI_CSI_SHADOW_CONFIGn_COUNT             4u
#define MIPI_CSI_FRAME_COUNTER_COUNT              4u
#define MIPI_CSI_LINE_INTERRUPT_RATIO_COUNT       4u

/** MIPI_CSI - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t CSIS_COMMON_CTRL;                  /**< CSIS Common Control Register, offset: 0x4 */
  __IO uint32_t CSIS_CLOCK_CTRL;                   /**< CSIS Clock Control Register, offset: 0x8 */
       uint8_t RESERVED_1[4];
  __IO uint32_t INTERRUPT_MASK_0;                  /**< Interrupt mask register 0, offset: 0x10 */
  __IO uint32_t INTERRUPT_SOURCE_0;                /**< Interrupt source register 0, offset: 0x14 */
  __IO uint32_t INTERRUPT_MASK_1;                  /**< Interrupt mask register 1, offset: 0x18 */
  __IO uint32_t INTERRUPT_SOURCE_1;                /**< Interrupt source register 1, offset: 0x1C */
  __IO uint32_t DPHY_STATUS;                       /**< D-PHY status register, offset: 0x20 */
  __IO uint32_t DPHY_COMMON_CTRL;                  /**< D-PHY common control register, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t DPHY_MASTER_SLAVE_CTRL_LOW;        /**< D-PHY Master and Slave Control register Low, offset: 0x30 */
  __IO uint32_t DPHY_MASTER_SLAVE_CTRL_HIGH;       /**< D-PHY Master and Slave Control register HIGH, offset: 0x34 */
  __IO uint32_t DPHY_SLAVE_CTRL_LOW;               /**< D-PHY Slave Control register Low, offset: 0x38 */
  __IO uint32_t DPHY_SLAVE_CTRL_HIGH;              /**< D-PHY Slave Control register HIGH, offset: 0x3C */
  struct {                                         /* offset: 0x40, array step: 0x10 */
    __IO uint32_t ISP_CONFIG;                        /**< ISP Configuration Register, array offset: 0x40, array step: 0x10 */
    __IO uint32_t ISP_RESOLUTION;                    /**< ISP Resolution Register, array offset: 0x44, array step: 0x10 */
    __IO uint32_t ISP_SYNC;                          /**< ISP SYNC Register, array offset: 0x48, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } ISP_CONFIGn[MIPI_CSI_ISP_CONFIGn_COUNT];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    __I  uint32_t SHADOW_CONFIG;                     /**< Shadow Configuration Register, array offset: 0x80, array step: 0x10 */
    __I  uint32_t SHADOW_RESOLUTION;                 /**< Shadow Resolution Register, array offset: 0x84, array step: 0x10 */
    __I  uint32_t SHADOW_SYNC;                       /**< Shadow SYNC Register, array offset: 0x88, array step: 0x10 */
         uint8_t RESERVED_0[4];
  } SHADOW_CONFIGn[MIPI_CSI_SHADOW_CONFIGn_COUNT];
       uint8_t RESERVED_3[64];
  __IO uint32_t FRAME_COUNTER[MIPI_CSI_FRAME_COUNTER_COUNT]; /**< Frame Counter, array offset: 0x100, array step: 0x4 */
  __IO uint32_t LINE_INTERRUPT_RATIO[MIPI_CSI_LINE_INTERRUPT_RATIO_COUNT]; /**< Line Interrupt Ratio, array offset: 0x110, array step: 0x4 */
} MIPI_CSI_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_CSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_Register_Masks MIPI_CSI Register Masks
 * @{
 */

/*! @name CSIS_COMMON_CTRL - CSIS Common Control Register */
/*! @{ */

#define MIPI_CSI_CSIS_COMMON_CTRL_CSI_EN_MASK    (0x1U)
#define MIPI_CSI_CSIS_COMMON_CTRL_CSI_EN_SHIFT   (0U)
/*! CSI_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_CSI_CSIS_COMMON_CTRL_CSI_EN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_COMMON_CTRL_CSI_EN_SHIFT)) & MIPI_CSI_CSIS_COMMON_CTRL_CSI_EN_MASK)

#define MIPI_CSI_CSIS_COMMON_CTRL_SW_RESET_MASK  (0x2U)
#define MIPI_CSI_CSIS_COMMON_CTRL_SW_RESET_SHIFT (1U)
/*! SW_RESET - Software reset
 *  0b0..Ready
 *  0b1..Reset
 */
#define MIPI_CSI_CSIS_COMMON_CTRL_SW_RESET(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_COMMON_CTRL_SW_RESET_SHIFT)) & MIPI_CSI_CSIS_COMMON_CTRL_SW_RESET_MASK)

#define MIPI_CSI_CSIS_COMMON_CTRL_LANE_NUMBER_MASK (0x300U)
#define MIPI_CSI_CSIS_COMMON_CTRL_LANE_NUMBER_SHIFT (8U)
/*! LANE_NUMBER
 *  0b00..1 data lane
 *  0b01..2 data lane
 *  0b10..3 data lane
 *  0b11..4 data lane
 */
#define MIPI_CSI_CSIS_COMMON_CTRL_LANE_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_COMMON_CTRL_LANE_NUMBER_SHIFT)) & MIPI_CSI_CSIS_COMMON_CTRL_LANE_NUMBER_MASK)

#define MIPI_CSI_CSIS_COMMON_CTRL_UPDATE_SHADOW_MASK (0xF0000U)
#define MIPI_CSI_CSIS_COMMON_CTRL_UPDATE_SHADOW_SHIFT (16U)
/*! UPDATE_SHADOW - Strobe of updating shadow registers */
#define MIPI_CSI_CSIS_COMMON_CTRL_UPDATE_SHADOW(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_COMMON_CTRL_UPDATE_SHADOW_SHIFT)) & MIPI_CSI_CSIS_COMMON_CTRL_UPDATE_SHADOW_MASK)
/*! @} */

/*! @name CSIS_CLOCK_CTRL - CSIS Clock Control Register */
/*! @{ */

#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_EN_MASK (0xF0U)
#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_EN_SHIFT (4U)
/*! CLKGATE_EN
 *  0b0000..Pixel clock is always alive
 *  0b0001..Pixel clock is alive during the interval of frame [7] CH3 [6] CH2 [5] CH1 [4] CH0 (Refer 2.9)
 */
#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_EN(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_EN_SHIFT)) & MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_EN_MASK)

#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_TRAIL_MASK (0xFFFF0000U)
#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_TRAIL_SHIFT (16U)
/*! CLKGATE_TRAIL - 0 ~ 15 (1~16 Trailing clocks) */
#define MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_TRAIL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_TRAIL_SHIFT)) & MIPI_CSI_CSIS_CLOCK_CTRL_CLKGATE_TRAIL_MASK)
/*! @} */

/*! @name INTERRUPT_MASK_0 - Interrupt mask register 0 */
/*! @{ */

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ID_MASK (0x1U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ID_SHIFT (0U)
/*! MSK_ERR_ID - Unknown ID error
 *  0b0..Disable (masked)
 *  0b1..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ID(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ID_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ID_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_CRC_MASK (0x2U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_CRC_SHIFT (1U)
/*! MSK_ERR_CRC - CRC error
 *  0b0..Disable (masked)
 *  0b1..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_CRC(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_CRC_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_CRC_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ECC_MASK (0x4U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ECC_SHIFT (2U)
/*! MSK_ERR_ECC - ECC error
 *  0b0..Disable (masked)
 *  0b1..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ECC(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ECC_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_ECC_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_WRONG_CFG_MASK (0x8U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_WRONG_CFG_SHIFT (3U)
/*! MSK_ERR_WRONG_CFG - Wrong configuration
 *  0b0..Disable (masked)
 *  0b1..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_WRONG_CFG(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_WRONG_CFG_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_WRONG_CFG_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_OVER_MASK (0x10U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_OVER_SHIFT (4U)
/*! MSK_ERR_OVER - Image FIFO overflow interrupt
 *  0b0..Disable (masked)
 *  0b1..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_OVER(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_OVER_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_OVER_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FE_MASK (0xF00U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FE_SHIFT (8U)
/*! MSK_ERR_LOST_FE - Lost of Frame End packet, [CH3,CH2,CH1,CH0]
 *  0b0000..Disable (masked)
 *  0b0001..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FE_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FE_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FS_MASK (0xF000U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FS_SHIFT (12U)
/*! MSK_ERR_LOST_FS - Lost of Frame Start packet, [CH3,CH2,CH1,CH0]
 *  0b0000..Disable (masked)
 *  0b0001..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FS_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_LOST_FS_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_SOT_HS_MASK (0xF0000U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_SOT_HS_SHIFT (16U)
/*! MSK_ERR_SOT_HS - Start of transmission error [Lane3, Lane2, Lane1, Lane0]
 *  0b0000..Disable (masked)
 *  0b0001..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_SOT_HS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_SOT_HS_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_ERR_SOT_HS_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMEEND_MASK (0xF00000U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMEEND_SHIFT (20U)
/*! MSK_FRAMEEND - FE packet is received, [CH3,CH2,CH1,CH0]
 *  0b0000..Disable (masked)
 *  0b0001..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMEEND(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMEEND_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMEEND_MASK)

#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMESTART_MASK (0xF000000U)
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMESTART_SHIFT (24U)
/*! MSK_FRAMESTART - FS packet is received, [CH3,CH2,CH1,CH0]
 *  0b0000..Disable (masked)
 *  0b0001..Enable (unmasked)
 */
#define MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMESTART(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMESTART_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_0_MSK_FRAMESTART_MASK)
/*! @} */

/*! @name INTERRUPT_SOURCE_0 - Interrupt source register 0 */
/*! @{ */

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ID_MASK  (0x1U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ID_SHIFT (0U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ID(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ID_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ID_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_CRC_MASK (0x2U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_CRC_SHIFT (1U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_CRC(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_CRC_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_CRC_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ECC_MASK (0x4U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ECC_SHIFT (2U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ECC(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ECC_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_ECC_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_WRONG_CFG_MASK (0x8U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_WRONG_CFG_SHIFT (3U)
/*! ERR_WRONG_CFG - Wrong configuration */
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_WRONG_CFG(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_WRONG_CFG_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_WRONG_CFG_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_OVER_MASK (0x10U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_OVER_SHIFT (4U)
/*! ERR_OVER - Overflow is caused in image FIFO. */
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_OVER(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_OVER_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_OVER_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FE_MASK (0xF00U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FE_SHIFT (8U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FE_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FE_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FS_MASK (0xF000U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FS_SHIFT (12U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FS_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_LOST_FS_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_SOT_HS_MASK (0xF0000U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_SOT_HS_SHIFT (16U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_ERR_SOT_HS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_ERR_SOT_HS_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_ERR_SOT_HS_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_END_MASK (0xF00000U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_END_SHIFT (20U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_END(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_END_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_END_MASK)

#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_START_MASK (0xF000000U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_START_SHIFT (24U)
#define MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_START(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_START_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_0_FRAME_START_MASK)
/*! @} */

/*! @name INTERRUPT_MASK_1 - Interrupt mask register 1 */
/*! @{ */

#define MIPI_CSI_INTERRUPT_MASK_1_MSK_LINE_END_MASK (0xFU)
#define MIPI_CSI_INTERRUPT_MASK_1_MSK_LINE_END_SHIFT (0U)
#define MIPI_CSI_INTERRUPT_MASK_1_MSK_LINE_END(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_MASK_1_MSK_LINE_END_SHIFT)) & MIPI_CSI_INTERRUPT_MASK_1_MSK_LINE_END_MASK)
/*! @} */

/*! @name INTERRUPT_SOURCE_1 - Interrupt source register 1 */
/*! @{ */

#define MIPI_CSI_INTERRUPT_SOURCE_1_LINE_END_MASK (0xFU)
#define MIPI_CSI_INTERRUPT_SOURCE_1_LINE_END_SHIFT (0U)
#define MIPI_CSI_INTERRUPT_SOURCE_1_LINE_END(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_INTERRUPT_SOURCE_1_LINE_END_SHIFT)) & MIPI_CSI_INTERRUPT_SOURCE_1_LINE_END_MASK)
/*! @} */

/*! @name DPHY_STATUS - D-PHY status register */
/*! @{ */

#define MIPI_CSI_DPHY_STATUS_STOPSTATECLK_MASK   (0x1U)
#define MIPI_CSI_DPHY_STATUS_STOPSTATECLK_SHIFT  (0U)
/*! STOPSTATECLK
 *  0b0..Not Stop state
 *  0b1..Stop state
 */
#define MIPI_CSI_DPHY_STATUS_STOPSTATECLK(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_STATUS_STOPSTATECLK_SHIFT)) & MIPI_CSI_DPHY_STATUS_STOPSTATECLK_MASK)

#define MIPI_CSI_DPHY_STATUS_ULPSCLK_MASK        (0x2U)
#define MIPI_CSI_DPHY_STATUS_ULPSCLK_SHIFT       (1U)
/*! ULPSCLK
 *  0b0..Not ULPS
 *  0b1..ULPS
 */
#define MIPI_CSI_DPHY_STATUS_ULPSCLK(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_STATUS_ULPSCLK_SHIFT)) & MIPI_CSI_DPHY_STATUS_ULPSCLK_MASK)

#define MIPI_CSI_DPHY_STATUS_STOPSTATEDAT_MASK   (0xF0U)
#define MIPI_CSI_DPHY_STATUS_STOPSTATEDAT_SHIFT  (4U)
/*! STOPSTATEDAT - Data lane [3:0] is in Stop State
 *  0b0000..Not Stop state
 *  0b0001..Stop state
 */
#define MIPI_CSI_DPHY_STATUS_STOPSTATEDAT(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_STATUS_STOPSTATEDAT_SHIFT)) & MIPI_CSI_DPHY_STATUS_STOPSTATEDAT_MASK)

#define MIPI_CSI_DPHY_STATUS_ULPSDAT_MASK        (0xF00U)
#define MIPI_CSI_DPHY_STATUS_ULPSDAT_SHIFT       (8U)
/*! ULPSDAT - Data lane [3:0] is in ULPS
 *  0b0000..Not ULPS
 *  0b0001..ULPS
 */
#define MIPI_CSI_DPHY_STATUS_ULPSDAT(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_STATUS_ULPSDAT_SHIFT)) & MIPI_CSI_DPHY_STATUS_ULPSDAT_MASK)
/*! @} */

/*! @name DPHY_COMMON_CTRL - D-PHY common control register */
/*! @{ */

#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_CLK_MASK (0x1U)
#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_CLK_SHIFT (0U)
/*! ENABLE_CLK
 *  0b0..Disable
 *  0b1..Enable
 */
#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_CLK(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_CLK_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_CLK_MASK)

#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_DAT_MASK (0x1EU)
#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_DAT_SHIFT (1U)
/*! ENABLE_DAT - D-PHY enable
 *  0b0000..Disable
 *  0b0001..Enable
 */
#define MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_DAT(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_DAT_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_ENABLE_DAT_MASK)

#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_DAT_MASK (0x20U)
#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_DAT_SHIFT (5U)
/*! S_DPDN_SWAP_DAT - Swapping Dp and Dn channel of data lanes.
 *  0b0..Default
 *  0b1..Swapped
 */
#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_DAT(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_DAT_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_DAT_MASK)

#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_CLK_MASK (0x40U)
#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_CLK_SHIFT (6U)
/*! S_DPDN_SWAP_CLK
 *  0b0..Default
 *  0b1..Swapped
 */
#define MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_CLK(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_CLK_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_S_DPDN_SWAP_CLK_MASK)

#define MIPI_CSI_DPHY_COMMON_CTRL_S_CLKSETTLECTL_MASK (0xC00000U)
#define MIPI_CSI_DPHY_COMMON_CTRL_S_CLKSETTLECTL_SHIFT (22U)
/*! S_CLKSETTLECTL - D-PHY control register for standard spec v0.9 of MIPI CSI2 */
#define MIPI_CSI_DPHY_COMMON_CTRL_S_CLKSETTLECTL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_S_CLKSETTLECTL_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_S_CLKSETTLECTL_MASK)

#define MIPI_CSI_DPHY_COMMON_CTRL_HSSETTLE_MASK  (0xFF000000U)
#define MIPI_CSI_DPHY_COMMON_CTRL_HSSETTLE_SHIFT (24U)
/*! HSSETTLE - HS-RX settle time control register. */
#define MIPI_CSI_DPHY_COMMON_CTRL_HSSETTLE(x)    (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_COMMON_CTRL_HSSETTLE_SHIFT)) & MIPI_CSI_DPHY_COMMON_CTRL_HSSETTLE_MASK)
/*! @} */

/*! @name DPHY_MASTER_SLAVE_CTRL_LOW - D-PHY Master and Slave Control register Low */
/*! @{ */

#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_LOW_B_DPHYCTRL_MASK (0xFFFFFFFFU)
#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_LOW_B_DPHYCTRL_SHIFT (0U)
/*! B_DPHYCTRL - D-PHY Master and Slave control register Low part */
#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_LOW_B_DPHYCTRL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_LOW_B_DPHYCTRL_SHIFT)) & MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_LOW_B_DPHYCTRL_MASK)
/*! @} */

/*! @name DPHY_MASTER_SLAVE_CTRL_HIGH - D-PHY Master and Slave Control register HIGH */
/*! @{ */

#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_HIGH_B_DPHYCTRL_MASK (0xFFFFFFFFU)
#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_HIGH_B_DPHYCTRL_SHIFT (0U)
/*! B_DPHYCTRL - D-PHY Master and Slave control register High part */
#define MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_HIGH_B_DPHYCTRL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_HIGH_B_DPHYCTRL_SHIFT)) & MIPI_CSI_DPHY_MASTER_SLAVE_CTRL_HIGH_B_DPHYCTRL_MASK)
/*! @} */

/*! @name DPHY_SLAVE_CTRL_LOW - D-PHY Slave Control register Low */
/*! @{ */

#define MIPI_CSI_DPHY_SLAVE_CTRL_LOW_S_DPHYCTRL_MASK (0xFFFFFFFFU)
#define MIPI_CSI_DPHY_SLAVE_CTRL_LOW_S_DPHYCTRL_SHIFT (0U)
/*! S_DPHYCTRL - D-PHY Slave control register Low part */
#define MIPI_CSI_DPHY_SLAVE_CTRL_LOW_S_DPHYCTRL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_SLAVE_CTRL_LOW_S_DPHYCTRL_SHIFT)) & MIPI_CSI_DPHY_SLAVE_CTRL_LOW_S_DPHYCTRL_MASK)
/*! @} */

/*! @name DPHY_SLAVE_CTRL_HIGH - D-PHY Slave Control register HIGH */
/*! @{ */

#define MIPI_CSI_DPHY_SLAVE_CTRL_HIGH_S_DPHYCTRL_MASK (0xFFFFFFFFU)
#define MIPI_CSI_DPHY_SLAVE_CTRL_HIGH_S_DPHYCTRL_SHIFT (0U)
/*! S_DPHYCTRL - D-PHY Slave control register High part */
#define MIPI_CSI_DPHY_SLAVE_CTRL_HIGH_S_DPHYCTRL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_DPHY_SLAVE_CTRL_HIGH_S_DPHYCTRL_SHIFT)) & MIPI_CSI_DPHY_SLAVE_CTRL_HIGH_S_DPHYCTRL_MASK)
/*! @} */

/*! @name ISP_CONFIG - ISP Configuration Register */
/*! @{ */

#define MIPI_CSI_ISP_CONFIG_DATAFORMAT_MASK      (0xFCU)
#define MIPI_CSI_ISP_CONFIG_DATAFORMAT_SHIFT     (2U)
/*! DATAFORMAT - Image Data Format */
#define MIPI_CSI_ISP_CONFIG_DATAFORMAT(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_CONFIG_DATAFORMAT_SHIFT)) & MIPI_CSI_ISP_CONFIG_DATAFORMAT_MASK)

#define MIPI_CSI_ISP_CONFIG_RGB_SWAP_MASK        (0x400U)
#define MIPI_CSI_ISP_CONFIG_RGB_SWAP_SHIFT       (10U)
/*! RGB_SWAP
 *  0b0..MSB is R and LSB is B
 *  0b1..MSB is B and LSB is R (swapped)
 */
#define MIPI_CSI_ISP_CONFIG_RGB_SWAP(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_CONFIG_RGB_SWAP_SHIFT)) & MIPI_CSI_ISP_CONFIG_RGB_SWAP_MASK)

#define MIPI_CSI_ISP_CONFIG_PARALLEL_MASK        (0x800U)
#define MIPI_CSI_ISP_CONFIG_PARALLEL_SHIFT       (11U)
/*! PARALLEL - Output bus width of CH0 is 32 bits.
 *  0b0..Normal output
 *  0b1..32bit data alignment
 */
#define MIPI_CSI_ISP_CONFIG_PARALLEL(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_CONFIG_PARALLEL_SHIFT)) & MIPI_CSI_ISP_CONFIG_PARALLEL_MASK)

#define MIPI_CSI_ISP_CONFIG_PIXEL_MODE_MASK      (0x3000U)
#define MIPI_CSI_ISP_CONFIG_PIXEL_MODE_SHIFT     (12U)
/*! PIXEL_MODE - Pixel mode selection, */
#define MIPI_CSI_ISP_CONFIG_PIXEL_MODE(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_CONFIG_PIXEL_MODE_SHIFT)) & MIPI_CSI_ISP_CONFIG_PIXEL_MODE_MASK)
/*! @} */

/* The count of MIPI_CSI_ISP_CONFIG */
#define MIPI_CSI_ISP_CONFIG_COUNT                (4U)

/*! @name ISP_RESOLUTION - ISP Resolution Register */
/*! @{ */

#define MIPI_CSI_ISP_RESOLUTION_HRESOL_MASK      (0xFFFFU)
#define MIPI_CSI_ISP_RESOLUTION_HRESOL_SHIFT     (0U)
/*! HRESOL - Horizontal Image resolution */
#define MIPI_CSI_ISP_RESOLUTION_HRESOL(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_RESOLUTION_HRESOL_SHIFT)) & MIPI_CSI_ISP_RESOLUTION_HRESOL_MASK)

#define MIPI_CSI_ISP_RESOLUTION_VRESOL_MASK      (0xFFFF0000U)
#define MIPI_CSI_ISP_RESOLUTION_VRESOL_SHIFT     (16U)
/*! VRESOL - Vertical Image resolution */
#define MIPI_CSI_ISP_RESOLUTION_VRESOL(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_RESOLUTION_VRESOL_SHIFT)) & MIPI_CSI_ISP_RESOLUTION_VRESOL_MASK)
/*! @} */

/* The count of MIPI_CSI_ISP_RESOLUTION */
#define MIPI_CSI_ISP_RESOLUTION_COUNT            (4U)

/*! @name ISP_SYNC - ISP SYNC Register */
/*! @{ */

#define MIPI_CSI_ISP_SYNC_HSYNC_LINTV_MASK       (0xFC0000U)
#define MIPI_CSI_ISP_SYNC_HSYNC_LINTV_SHIFT      (18U)
#define MIPI_CSI_ISP_SYNC_HSYNC_LINTV(x)         (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_ISP_SYNC_HSYNC_LINTV_SHIFT)) & MIPI_CSI_ISP_SYNC_HSYNC_LINTV_MASK)
/*! @} */

/* The count of MIPI_CSI_ISP_SYNC */
#define MIPI_CSI_ISP_SYNC_COUNT                  (4U)

/*! @name SHADOW_CONFIG - Shadow Configuration Register */
/*! @{ */

#define MIPI_CSI_SHADOW_CONFIG_VIRTUAL_CHANNEL_MASK (0x3U)
#define MIPI_CSI_SHADOW_CONFIG_VIRTUAL_CHANNEL_SHIFT (0U)
#define MIPI_CSI_SHADOW_CONFIG_VIRTUAL_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_CONFIG_VIRTUAL_CHANNEL_SHIFT)) & MIPI_CSI_SHADOW_CONFIG_VIRTUAL_CHANNEL_MASK)

#define MIPI_CSI_SHADOW_CONFIG_DATAFORMAT_MASK   (0xFCU)
#define MIPI_CSI_SHADOW_CONFIG_DATAFORMAT_SHIFT  (2U)
#define MIPI_CSI_SHADOW_CONFIG_DATAFORMAT(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_CONFIG_DATAFORMAT_SHIFT)) & MIPI_CSI_SHADOW_CONFIG_DATAFORMAT_MASK)

#define MIPI_CSI_SHADOW_CONFIG_RGB_SWAP_SDW_MASK (0x400U)
#define MIPI_CSI_SHADOW_CONFIG_RGB_SWAP_SDW_SHIFT (10U)
#define MIPI_CSI_SHADOW_CONFIG_RGB_SWAP_SDW(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_CONFIG_RGB_SWAP_SDW_SHIFT)) & MIPI_CSI_SHADOW_CONFIG_RGB_SWAP_SDW_MASK)

#define MIPI_CSI_SHADOW_CONFIG_PARALLEL_SDW_MASK (0x800U)
#define MIPI_CSI_SHADOW_CONFIG_PARALLEL_SDW_SHIFT (11U)
#define MIPI_CSI_SHADOW_CONFIG_PARALLEL_SDW(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_CONFIG_PARALLEL_SDW_SHIFT)) & MIPI_CSI_SHADOW_CONFIG_PARALLEL_SDW_MASK)

#define MIPI_CSI_SHADOW_CONFIG_PIXEL_MODE_MASK   (0x3000U)
#define MIPI_CSI_SHADOW_CONFIG_PIXEL_MODE_SHIFT  (12U)
#define MIPI_CSI_SHADOW_CONFIG_PIXEL_MODE(x)     (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_CONFIG_PIXEL_MODE_SHIFT)) & MIPI_CSI_SHADOW_CONFIG_PIXEL_MODE_MASK)
/*! @} */

/* The count of MIPI_CSI_SHADOW_CONFIG */
#define MIPI_CSI_SHADOW_CONFIG_COUNT             (4U)

/*! @name SHADOW_RESOLUTION - Shadow Resolution Register */
/*! @{ */

#define MIPI_CSI_SHADOW_RESOLUTION_HRESOL_SDW_MASK (0xFFFFU)
#define MIPI_CSI_SHADOW_RESOLUTION_HRESOL_SDW_SHIFT (0U)
#define MIPI_CSI_SHADOW_RESOLUTION_HRESOL_SDW(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_RESOLUTION_HRESOL_SDW_SHIFT)) & MIPI_CSI_SHADOW_RESOLUTION_HRESOL_SDW_MASK)

#define MIPI_CSI_SHADOW_RESOLUTION_VRESOL_SDW_MASK (0xFFFF0000U)
#define MIPI_CSI_SHADOW_RESOLUTION_VRESOL_SDW_SHIFT (16U)
#define MIPI_CSI_SHADOW_RESOLUTION_VRESOL_SDW(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_RESOLUTION_VRESOL_SDW_SHIFT)) & MIPI_CSI_SHADOW_RESOLUTION_VRESOL_SDW_MASK)
/*! @} */

/* The count of MIPI_CSI_SHADOW_RESOLUTION */
#define MIPI_CSI_SHADOW_RESOLUTION_COUNT         (4U)

/*! @name SHADOW_SYNC - Shadow SYNC Register */
/*! @{ */

#define MIPI_CSI_SHADOW_SYNC_HSYNC_LINTV_SDW_MASK (0xFC0000U)
#define MIPI_CSI_SHADOW_SYNC_HSYNC_LINTV_SDW_SHIFT (18U)
#define MIPI_CSI_SHADOW_SYNC_HSYNC_LINTV_SDW(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_SHADOW_SYNC_HSYNC_LINTV_SDW_SHIFT)) & MIPI_CSI_SHADOW_SYNC_HSYNC_LINTV_SDW_MASK)
/*! @} */

/* The count of MIPI_CSI_SHADOW_SYNC */
#define MIPI_CSI_SHADOW_SYNC_COUNT               (4U)

/*! @name FRAME_COUNTER - Frame Counter */
/*! @{ */

#define MIPI_CSI_FRAME_COUNTER_FRM_CNT_MASK      (0xFFFFFFFFU)
#define MIPI_CSI_FRAME_COUNTER_FRM_CNT_SHIFT     (0U)
#define MIPI_CSI_FRAME_COUNTER_FRM_CNT(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_FRAME_COUNTER_FRM_CNT_SHIFT)) & MIPI_CSI_FRAME_COUNTER_FRM_CNT_MASK)
/*! @} */

/*! @name LINE_INTERRUPT_RATIO - Line Interrupt Ratio */
/*! @{ */

#define MIPI_CSI_LINE_INTERRUPT_RATIO_LINE_INTR_MASK (0xFFFFFFFFU)
#define MIPI_CSI_LINE_INTERRUPT_RATIO_LINE_INTR_SHIFT (0U)
#define MIPI_CSI_LINE_INTERRUPT_RATIO_LINE_INTR(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_LINE_INTERRUPT_RATIO_LINE_INTR_SHIFT)) & MIPI_CSI_LINE_INTERRUPT_RATIO_LINE_INTR_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_CSI_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_CSI_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_CSI_H_ */

