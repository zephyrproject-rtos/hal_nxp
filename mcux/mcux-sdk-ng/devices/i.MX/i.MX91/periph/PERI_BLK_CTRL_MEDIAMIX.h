/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BLK_CTRL_MEDIAMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_BLK_CTRL_MEDIAMIX.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for BLK_CTRL_MEDIAMIX
 *
 * CMSIS Peripheral Access Layer for BLK_CTRL_MEDIAMIX
 */

#if !defined(PERI_BLK_CTRL_MEDIAMIX_H_)
#define PERI_BLK_CTRL_MEDIAMIX_H_                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
   -- BLK_CTRL_MEDIAMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_MEDIAMIX_Peripheral_Access_Layer BLK_CTRL_MEDIAMIX Peripheral Access Layer
 * @{
 */

/** BLK_CTRL_MEDIAMIX - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
           uint8_t RESERVED_0[12];
      __IO uint32_t LCDIFr;                            /**< QOS and cache of LCDIF, offset: 0xC, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'LCDIF' */
           uint8_t RESERVED_1[4];
      __IO uint32_t ISI0;                              /**< Cache of ISI, offset: 0x14 */
           uint8_t RESERVED_2[4];
      __IO uint32_t ISI1;                              /**< QoS of ISI, offset: 0x1C */
           uint8_t RESERVED_3[28];
      __I  uint32_t PIXEL_CTRL;                        /**< Read Pixel Control Register, offset: 0x3C */
           uint8_t RESERVED_4[32];
      __IO uint32_t DISPLAY_MUX;                       /**< Display Mux Control Register, offset: 0x60 */
           uint8_t RESERVED_5[12];
      __IO uint32_t IF_CTRL_REG;                       /**< Parallel Camera Interface Register, offset: 0x70 */
      __I  uint32_t INTERFACE_STATUS;                  /**< Interface Status Register, offset: 0x74 */
      __IO uint32_t INTERFACE_CTRL_REG;                /**< Interface Control Register, offset: 0x78 */
      __IO uint32_t INTERFACE_CTRL_REG1;               /**< Interface Control Register 1, offset: 0x7C */
    } BUS_CONTROL;
    struct {                                         /* offset: 0x0 */
      __IO uint32_t RESET;                             /**< RESET Control Register, offset: 0x0 */
      __IO uint32_t CLK;                               /**< CLK Control Register, offset: 0x4 */
    } CLK_RESETN;
  };
} BLK_CTRL_MEDIAMIX_Type;

/* ----------------------------------------------------------------------------
   -- BLK_CTRL_MEDIAMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BLK_CTRL_MEDIAMIX_Register_Masks BLK_CTRL_MEDIAMIX Register Masks
 * @{
 */

/*! @name LCDIF - QOS and cache of LCDIF */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_MASK     (0xFU)
#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_SHIFT    (0U)
/*! ARCACHE - ARCACHE value of LCDIF */
#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_SHIFT)) & BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_MASK)

#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_EN_MASK  (0x10U)
#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_EN_SHIFT (4U)
/*! ARCACHE_EN - ARCACHE enable of LCDIF
 *  0b0..Do not enable ARCACHE
 *  0b1..Enable ARCACHE
 */
#define BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_EN(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_LCDIF_ARCACHE_EN_MASK)

#define BLK_CTRL_MEDIAMIX_LCDIF_CFG_QOS_MASK     (0xF00U)
#define BLK_CTRL_MEDIAMIX_LCDIF_CFG_QOS_SHIFT    (8U)
/*! CFG_QOS - cfg_qos value of LCDIF */
#define BLK_CTRL_MEDIAMIX_LCDIF_CFG_QOS(x)       (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_LCDIF_CFG_QOS_SHIFT)) & BLK_CTRL_MEDIAMIX_LCDIF_CFG_QOS_MASK)

#define BLK_CTRL_MEDIAMIX_LCDIF_DEFAULT_QOS_MASK (0xF000U)
#define BLK_CTRL_MEDIAMIX_LCDIF_DEFAULT_QOS_SHIFT (12U)
/*! DEFAULT_QOS - Default QoS value of LCDIF */
#define BLK_CTRL_MEDIAMIX_LCDIF_DEFAULT_QOS(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_LCDIF_DEFAULT_QOS_SHIFT)) & BLK_CTRL_MEDIAMIX_LCDIF_DEFAULT_QOS_MASK)
/*! @} */

/*! @name ISI0 - Cache of ISI */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_MASK    (0xFU)
#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_SHIFT   (0U)
/*! ARCACHE_Y - ARCACHE_Y value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_MASK    (0xF0U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_SHIFT   (4U)
/*! AWCACHE_Y - AWCACHE_Y value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_MASK    (0xF00U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_SHIFT   (8U)
/*! AWCACHE_U - AWCACHE_U value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_MASK    (0xF000U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_SHIFT   (12U)
/*! AWCACHE_V - AWCACHE_V value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_EN_MASK (0x10000U)
#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_EN_SHIFT (16U)
/*! ARCACHE_Y_EN - ARCACHE_Y enable of ISI
 *  0b0..Do not enable ARCACHE_Y
 *  0b1..Enable ARCACHE_Y
 */
#define BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_ARCACHE_Y_EN_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_EN_MASK (0x20000U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_EN_SHIFT (17U)
/*! AWCACHE_Y_EN - AWCACHE_Y enable of ISI
 *  0b0..Do not enable AWCACHE_Y
 *  0b1..Enable AWCACHE_Y
 */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_Y_EN_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_EN_MASK (0x40000U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_EN_SHIFT (18U)
/*! AWCACHE_U_EN - AWCACHE_U enable of ISI
 *  0b0..Do not enable AWACHE_U
 *  0b1..Enable AWCACHE_U
 */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_U_EN_MASK)

#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_EN_MASK (0x80000U)
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_EN_SHIFT (19U)
/*! AWCACHE_V_EN - AWCACHE_V enable of ISI
 *  0b0..Do not enable AWCACHE_V
 *  0b1..Enable AWCACHE_V
 */
#define BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_EN(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI0_AWCACHE_V_EN_MASK)
/*! @} */

/*! @name ISI1 - QoS of ISI */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_W_MASK  (0xFU)
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_W_SHIFT (0U)
/*! CFG_QOS_Y_W - cfg_qos_y_w value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_W(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_W_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_W_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_W_MASK (0xF0U)
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_W_SHIFT (4U)
/*! DEFAULT_QOS_Y_W - Default QOS_Y_W value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_W(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_W_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_W_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_R_MASK  (0xF00U)
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_R_SHIFT (8U)
/*! CFG_QOS_Y_R - CFG_QOS_Y_R value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_R(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_R_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_Y_R_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_R_MASK (0xF000U)
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_R_SHIFT (12U)
/*! DEFAULT_QOS_Y_R - Default QOS_Y_R value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_R(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_R_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_Y_R_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_U_MASK    (0xF0000U)
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_U_SHIFT   (16U)
/*! CFG_QOS_U - cfg_qos_u value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_U(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_U_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_U_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_U_MASK (0xF00000U)
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_U_SHIFT (20U)
/*! DEFAULT_QOS_U - Default QoS value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_U(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_U_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_U_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_V_MASK    (0xF000000U)
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_V_SHIFT   (24U)
/*! CFG_QOS_V - CFG_QOS_V value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_V(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_V_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_CFG_QOS_V_MASK)

#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_V_MASK (0xF0000000U)
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_V_SHIFT (28U)
/*! DEFAULT_QOS_V - Default QOS_V value of ISI */
#define BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_V(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_V_SHIFT)) & BLK_CTRL_MEDIAMIX_ISI1_DEFAULT_QOS_V_MASK)
/*! @} */

/*! @name PIXEL_CTRL - Read Pixel Control Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_PIXEL_CTRL_PIXEL_CTRL_MASK (0xFFFU)
#define BLK_CTRL_MEDIAMIX_PIXEL_CTRL_PIXEL_CTRL_SHIFT (0U)
/*! PIXEL_CTRL - Read pixel control information status */
#define BLK_CTRL_MEDIAMIX_PIXEL_CTRL_PIXEL_CTRL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_PIXEL_CTRL_PIXEL_CTRL_SHIFT)) & BLK_CTRL_MEDIAMIX_PIXEL_CTRL_PIXEL_CTRL_MASK)
/*! @} */

/*! @name DISPLAY_MUX - Display Mux Control Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_DISPLAY_MUX_PARALLEL_DISP_FORMAT_MASK (0x700U)
#define BLK_CTRL_MEDIAMIX_DISPLAY_MUX_PARALLEL_DISP_FORMAT_SHIFT (8U)
/*! PARALLEL_DISP_FORMAT - Parallel display format configuration
 *  0b000..RGB888 -> RGB888
 *  0b001..RGB888 -> RGB666. Truncate the two least significant bits of each color component (pass through the 6
 *         most significant bits of each color component.)
 *  0b010..RGB565 -> RGB565
 *  0b011..RGB555 -> RGB555
 *  0b100..YUV -> YCbCr 24 bits
 *  0b101..YUV -> YUV444
 */
#define BLK_CTRL_MEDIAMIX_DISPLAY_MUX_PARALLEL_DISP_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_DISPLAY_MUX_PARALLEL_DISP_FORMAT_SHIFT)) & BLK_CTRL_MEDIAMIX_DISPLAY_MUX_PARALLEL_DISP_FORMAT_MASK)
/*! @} */

/*! @name IF_CTRL_REG - Parallel Camera Interface Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SEL_MASK (0x100U)
#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SEL_SHIFT (8U)
/*! DATA_TYPE_SEL - Pixel link data type select
 *  0b0..Reserved
 *  0b1..Pixel Link data type comes from IF_CTRL_REG DATA_TYPE[4:0]
 */
#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SEL_SHIFT)) & BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SEL_MASK)

#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_MASK (0x3E00U)
#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SHIFT (9U)
/*! DATA_TYPE - Date type to ISI control bus [11:7]
 *  0b00000..Null data
 *  0b00100..RGB format
 *  0b01000..YUV444 format
 *  0b10000..YYU420 type(a) odd line (not supported)
 *  0b10010..YYU420 type(a) even line (not supported)
 *  0b11000..YYU420 type(a) YYY odd line (not supported)
 *  0b11010..YYU420 type(b) UYVY even line (not supported)
 *  0b11100..RAW
 */
#define BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_SHIFT)) & BLK_CTRL_MEDIAMIX_IF_CTRL_REG_DATA_TYPE_MASK)
/*! @} */

/*! @name INTERFACE_STATUS - Interface Status Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_MASK (0x1U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_SHIFT (0U)
/*! FIELD_TOGGLE_STATUS - Field toggle status
 *  0b0..VSYNC field toggle mode disabled
 *  0b1..VSYNC field toggle mode enabled
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_FIELD_TOGGLE_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_FIELD_TOGGLE_STATUS_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_ECC_ERROR_STATUS_MASK (0x2U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_ECC_ERROR_STATUS_SHIFT (1U)
/*! ECC_ERROR_STATUS - ECC error status
 *  0b0..No ECC error detected
 *  0b1..ECC error detected
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_ECC_ERROR_STATUS(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_ECC_ERROR_STATUS_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_STATUS_ECC_ERROR_STATUS_MASK)
/*! @} */

/*! @name INTERFACE_CTRL_REG - Interface Control Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_CLK_POL_MASK (0x2U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_CLK_POL_SHIFT (1U)
/*! PIXEL_CLK_POL - Pixel clock polarity control
 *  0b0..Pixel clcok is not inverted.
 *  0b1..Pixel clock input is inverted.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_CLK_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_CLK_POL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_CLK_POL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_POL_MASK (0x4U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_POL_SHIFT (2U)
/*! HSYNC_POL - HSYNC polarity control
 *  0b0..HSYNC output to Pixel Link is not inverted.
 *  0b1..HSYNC output to Pixel Link is inverted.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_POL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_POL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_POL_MASK (0x8U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_POL_SHIFT (3U)
/*! VSYNC_POL - VSYNC polarity control
 *  0b0..VSYNC output to Pixel Link is not inverted.
 *  0b1..VSYNC output to Pixel Link is inverted.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_POL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_POL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_DE_POL_MASK (0x10U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_DE_POL_SHIFT (4U)
/*! DE_POL - DE polarity control
 *  0b0..DE output to Pixel Link is not inverted.
 *  0b1..DE output to Pixcel Link is inverted.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_DE_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_DE_POL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_DE_POL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_DATA_POL_MASK (0x20U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_DATA_POL_SHIFT (5U)
/*! PIXEL_DATA_POL - PIXEL_DATA polarity control
 *  0b0..PIXEL_DATA output to Pixel Link is not inverted.
 *  0b1..PIXEL_DATA output to Pixel Link is inverted.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_DATA_POL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_DATA_POL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_PIXEL_DATA_POL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_MASK (0x40U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_SHIFT (6U)
/*! CCIR_EXT_VSYNC_EN - External VSYNC enable */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EXT_VSYNC_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EN_MASK (0x80U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EN_SHIFT (7U)
/*! CCIR_EN - CCIR mode enable
 *  0b0..CCIR mode disable
 *  0b1..CCIR mode enable
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_MASK (0x100U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_SHIFT (8U)
/*! CCIR_VIDEO_MODE - CCIR video mode
 *  0b0..Progressive mode
 *  0b1..Interlace
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VIDEO_MODE_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_NTSC_EN_MASK (0x200U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_NTSC_EN_SHIFT (9U)
/*! CCIR_NTSC_EN - CCIR NTSC enable
 *  0b0..PAL
 *  0b1..NTSC
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_NTSC_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_NTSC_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_NTSC_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_MASK (0x400U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_SHIFT (10U)
/*! CCIR_VSYNC_RST_EN - CCIR_VSYNC_RESET_EN */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_VSYNC_RST_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_MASK (0x800U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_SHIFT (11U)
/*! CCIR_ECC_CORR_EN - CCIR error correction enable
 *  0b0..ECC error correction is disabled.
 *  0b1..ECC error correction is enabled.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_CCIR_ECC_CORR_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_MASK (0x1000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_SHIFT (12U)
/*! HSYNC_FORCE_EN - HSYNC force enable
 *  0b0..Do not override HSYNC.
 *  0b1..Override HSYNC.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_FORCE_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_MASK (0x2000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_SHIFT (13U)
/*! VSYNC_FORCE_EN - VSYNC force enable
 *  0b0..Do not override VSYNC.
 *  0b1..Override VSYNC.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_FORCE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VSYNC_FORCE_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_GCLK_MODE_EN_MASK (0x4000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_GCLK_MODE_EN_SHIFT (14U)
/*! GCLK_MODE_EN - Gate clock mode enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_GCLK_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_GCLK_MODE_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_GCLK_MODE_EN_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VALID_SEL_MASK (0x8000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VALID_SEL_SHIFT (15U)
/*! VALID_SEL - Data valid select
 *  0b0..HSYNC data valid.
 *  0b1..Data enable valid. Not supported.
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VALID_SEL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_VALID_SEL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_RAW_OUT_SEL_MASK (0x10000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_RAW_OUT_SEL_SHIFT (16U)
/*! RAW_OUT_SEL - RAW output select
 *  0b0..Right justified output
 *  0b1..Left justified to 14-bit output
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_RAW_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_RAW_OUT_SEL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_RAW_OUT_SEL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_MASK (0x20000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_SHIFT (17U)
/*! HSYNC_OUT_SEL - HSYNC output select
 *  0b0..HYSNC output level
 *  0b1..HYSNC output pulse
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_OUT_SEL(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_OUT_SEL_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_PULSE_MASK (0x380000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_PULSE_SHIFT (19U)
/*! HSYNC_PULSE - HSYNC_PULSE */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_PULSE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_PULSE_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_HSYNC_PULSE_MASK)

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_UV_SWAP_EN_MASK (0x400000U)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_UV_SWAP_EN_SHIFT (22U)
/*! UV_SWAP_EN - UV swap enable
 *  0b0..UV swap disable
 *  0b1..UV swap enable
 */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_UV_SWAP_EN(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_UV_SWAP_EN_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG_UV_SWAP_EN_MASK)
/*! @} */

/*! @name INTERFACE_CTRL_REG1 - Interface Control Register 1 */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG1_VSYNC_PULSE_MASK (0xFFFFU)
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG1_VSYNC_PULSE_SHIFT (0U)
/*! VSYNC_PULSE - VSYNC pulse width */
#define BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG1_VSYNC_PULSE(x) (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG1_VSYNC_PULSE_SHIFT)) & BLK_CTRL_MEDIAMIX_INTERFACE_CTRL_REG1_VSYNC_PULSE_MASK)
/*! @} */

/*! @name RESET - RESET Control Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_RESET_bus_apb_en_MASK  (0x1U)
#define BLK_CTRL_MEDIAMIX_RESET_bus_apb_en_SHIFT (0U)
/*! bus_apb_en - Bus apb_clk reset
 *  0b0..Reset bus apb_clk related logic
 *  0b1..Do not reset bus apb_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_bus_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_bus_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_bus_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_bus_blk_en_MASK  (0x2U)
#define BLK_CTRL_MEDIAMIX_RESET_bus_blk_en_SHIFT (1U)
/*! bus_blk_en - Bus axi_clk reset
 *  0b0..Reset bus axi_clk related logic
 *  0b1..Do not reset bus axi_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_bus_blk_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_bus_blk_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_bus_blk_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_isi_apb_en_MASK  (0x4U)
#define BLK_CTRL_MEDIAMIX_RESET_isi_apb_en_SHIFT (2U)
/*! isi_apb_en - ISI apb_clk reset
 *  0b0..Reset ISI apb_clk related logic
 *  0b1..Do not reset ISI apb_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_isi_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_isi_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_isi_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_isi_proc_en_MASK (0x8U)
#define BLK_CTRL_MEDIAMIX_RESET_isi_proc_en_SHIFT (3U)
/*! isi_proc_en - ISI axi_clk reset
 *  0b0..Reset ISI axi_clk related logic
 *  0b1..Do not reset ISI axi_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_isi_proc_en(x)   (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_isi_proc_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_isi_proc_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_lcdif_apb_en_MASK (0x10U)
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_apb_en_SHIFT (4U)
/*! lcdif_apb_en - LCDIF apb_clk reset
 *  0b0..Reset LCDIF apb_clk related logic
 *  0b1..Do not reset LCDIF apb_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_apb_en(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_lcdif_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_lcdif_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_lcdif_axi_en_MASK (0x20U)
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_axi_en_SHIFT (5U)
/*! lcdif_axi_en - LCDIF axi_clk reset
 *  0b0..Reset LCDIF axi_clk related logic
 *  0b1..Do not reset LCDIF axi_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_axi_en(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_lcdif_axi_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_lcdif_axi_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_lcdif_pix_en_MASK (0x40U)
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_pix_en_SHIFT (6U)
/*! lcdif_pix_en - LCDIF pix_clk reset
 *  0b0..Reset LCDIF pix_clk related logic
 *  0b1..Do not reset LCDIF pix_clk related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_lcdif_pix_en(x)  (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_lcdif_pix_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_lcdif_pix_en_MASK)

#define BLK_CTRL_MEDIAMIX_RESET_cam_clk_en_MASK  (0x400U)
#define BLK_CTRL_MEDIAMIX_RESET_cam_clk_en_SHIFT (10U)
/*! cam_clk_en - Camera clock reset
 *  0b0..Reset camera related logic
 *  0b1..Do not reset camera clock related logic
 */
#define BLK_CTRL_MEDIAMIX_RESET_cam_clk_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_RESET_cam_clk_en_SHIFT)) & BLK_CTRL_MEDIAMIX_RESET_cam_clk_en_MASK)
/*! @} */

/*! @name CLK - CLK Control Register */
/*! @{ */

#define BLK_CTRL_MEDIAMIX_CLK_bus_apb_en_MASK    (0x1U)
#define BLK_CTRL_MEDIAMIX_CLK_bus_apb_en_SHIFT   (0U)
/*! bus_apb_en - Bus apb_clk gate enable
 *  0b0..Do not gate bus apb_clk root
 *  0b1..Gate bus apb_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_bus_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_bus_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_bus_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_bus_blk_en_MASK    (0x2U)
#define BLK_CTRL_MEDIAMIX_CLK_bus_blk_en_SHIFT   (1U)
/*! bus_blk_en - Bus axi_clk gate enable
 *  0b0..Do not gate bus axi_clk root
 *  0b1..Gate bus axi_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_bus_blk_en(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_bus_blk_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_bus_blk_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_isi_apb_en_MASK    (0x4U)
#define BLK_CTRL_MEDIAMIX_CLK_isi_apb_en_SHIFT   (2U)
/*! isi_apb_en - ISI apb_clk gate enable
 *  0b0..Do not gate ISI apb_clk root
 *  0b1..Gate ISI apb_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_isi_apb_en(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_isi_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_isi_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_isi_proc_en_MASK   (0x8U)
#define BLK_CTRL_MEDIAMIX_CLK_isi_proc_en_SHIFT  (3U)
/*! isi_proc_en - ISI axi_clk gate enable
 *  0b0..Do not gate ISI axi_clk root
 *  0b1..Gate ISI axi_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_isi_proc_en(x)     (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_isi_proc_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_isi_proc_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_lcdif_apb_en_MASK  (0x10U)
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_apb_en_SHIFT (4U)
/*! lcdif_apb_en - LCDIF apb_clk gate enable
 *  0b0..Do not gate LCDIF apb_clk root
 *  0b1..Gate LCDIF apb_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_apb_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_lcdif_apb_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_lcdif_apb_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_lcdif_axi_en_MASK  (0x20U)
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_axi_en_SHIFT (5U)
/*! lcdif_axi_en - LCDIF axi_clk gate enable
 *  0b0..Do not gate LCDIF axi_clk root
 *  0b1..Gate LCDIF axi_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_axi_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_lcdif_axi_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_lcdif_axi_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_lcdif_pix_en_MASK  (0x40U)
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_pix_en_SHIFT (6U)
/*! lcdif_pix_en - LCDIF pix_clk gate enable
 *  0b0..Do not gate LCDIF pix_clk root
 *  0b1..Gate LCDIF pix_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_lcdif_pix_en(x)    (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_lcdif_pix_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_lcdif_pix_en_MASK)

#define BLK_CTRL_MEDIAMIX_CLK_cam_clk_en_MASK    (0x400U)
#define BLK_CTRL_MEDIAMIX_CLK_cam_clk_en_SHIFT   (10U)
/*! cam_clk_en - cam_clk gate enable
 *  0b0..Do not gate cam_clk root
 *  0b1..Gate cam_clk root
 */
#define BLK_CTRL_MEDIAMIX_CLK_cam_clk_en(x)      (((uint32_t)(((uint32_t)(x)) << BLK_CTRL_MEDIAMIX_CLK_cam_clk_en_SHIFT)) & BLK_CTRL_MEDIAMIX_CLK_cam_clk_en_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BLK_CTRL_MEDIAMIX_Register_Masks */


/*!
 * @}
 */ /* end of group BLK_CTRL_MEDIAMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_BLK_CTRL_MEDIAMIX_H_ */
