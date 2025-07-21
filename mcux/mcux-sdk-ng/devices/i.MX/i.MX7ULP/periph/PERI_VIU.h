/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VIU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VIU.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VIU
 *
 * CMSIS Peripheral Access Layer for VIU
 */

#if !defined(PERI_VIU_H_)
#define PERI_VIU_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- VIU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIU_Peripheral_Access_Layer VIU Peripheral Access Layer
 * @{
 */

/** VIU - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCR;                               /**< Status And Configuration Register, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DINVSZ;                            /**< Detected Input Video Pixel and Line Counts, offset: 0x8 */
  __IO uint32_t DINVFL;                            /**< Detected Input Video Frame Length, offset: 0xC */
       uint8_t RESERVED_1[4];
  __IO uint32_t DMA_ADDR;                          /**< Base Address Of Every Field/Frame Of Picture In Memory, offset: 0x14 */
  __IO uint32_t DMA_INC;                           /**< Horizontal DMA Increment, offset: 0x18 */
  __IO uint32_t INVSZ;                             /**< Input Video Pixel and Line Count, offset: 0x1C */
  __IO uint32_t HPRALRM;                           /**< High Priority Bus Request Alarm, offset: 0x20 */
  __IO uint32_t ALPHA;                             /**< Programable Alpha Value, offset: 0x24 */
  __IO uint32_t HFACTOR;                           /**< Scaling Factor In Horizontal Direction, offset: 0x28 */
  __IO uint32_t VFACTOR;                           /**< Down Scaling Factor In Vertical Direction, offset: 0x2C */
  __IO uint32_t VID_SIZE;                          /**< Scaling Destination Pixel and Line Count, offset: 0x30 */
  __IO uint32_t LUT_ADDR;                          /**< B/C Adjust Look-up-table Current Address, offset: 0x34 */
  __IO uint32_t LUT_DATA;                          /**< B/C Adjust Look-up-table Data Entry, offset: 0x38 */
  __IO uint32_t EXT_CONFIG;                        /**< Extended Configuration Register, offset: 0x3C */
       uint8_t RESERVED_2[12];
  __IO uint32_t ACT_ORG;                           /**< Active Image Origin, offset: 0x4C */
  __IO uint32_t ACT_SIZE;                          /**< Active Image Size, offset: 0x50 */
} VIU_Type;

/* ----------------------------------------------------------------------------
   -- VIU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VIU_Register_Masks VIU Register Masks
 * @{
 */

/*! @name SCR - Status And Configuration Register */
/*! @{ */

#define VIU_SCR_SOFT_RESET_MASK                  (0x1U)
#define VIU_SCR_SOFT_RESET_SHIFT                 (0U)
/*! SOFT_RESET - SOFT_RESET */
#define VIU_SCR_SOFT_RESET(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_SCR_SOFT_RESET_SHIFT)) & VIU_SCR_SOFT_RESET_MASK)

#define VIU_SCR_FORMAT_CTRL_MASK                 (0xEU)
#define VIU_SCR_FORMAT_CTRL_SHIFT                (1U)
/*! FORMAT_CTRL - FORMAT_CTRL */
#define VIU_SCR_FORMAT_CTRL(x)                   (((uint32_t)(((uint32_t)(x)) << VIU_SCR_FORMAT_CTRL_SHIFT)) & VIU_SCR_FORMAT_CTRL_MASK)

#define VIU_SCR_ERROR_CODE_MASK                  (0xF0U)
#define VIU_SCR_ERROR_CODE_SHIFT                 (4U)
/*! ERROR_CODE - ERROR_CODE
 *  0b0000..No error
 *  0b0001..DMA arm command given during vertical active, DMA_ACT does not accept the value on IPS bus.
 *  0b0010..DMA arm command given during vertical blanking when DMA_ACT is set.
 *  0b0100..Line too long
 *  0b0101..Too many lines in a field/frame
 *  0b0110..Line too short
 *  0b0111..Not enough lines in a field/frame
 *  0b1000..FIFO overflow
 *  0b1001..FIFO underflow
 *  0b1010..One bit ECC error
 *  0b1011..Two or more bits ECC error
 */
#define VIU_SCR_ERROR_CODE(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_SCR_ERROR_CODE_SHIFT)) & VIU_SCR_ERROR_CODE_MASK)

#define VIU_SCR_FIELD_EN_MASK                    (0x100U)
#define VIU_SCR_FIELD_EN_SHIFT                   (8U)
/*! FIELD_EN - FIELD_EN */
#define VIU_SCR_FIELD_EN(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_FIELD_EN_SHIFT)) & VIU_SCR_FIELD_EN_MASK)

#define VIU_SCR_VSYNC_EN_MASK                    (0x200U)
#define VIU_SCR_VSYNC_EN_SHIFT                   (9U)
/*! VSYNC_EN - VSYNC_EN */
#define VIU_SCR_VSYNC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_VSYNC_EN_SHIFT)) & VIU_SCR_VSYNC_EN_MASK)

#define VIU_SCR_HSYNC_EN_MASK                    (0x400U)
#define VIU_SCR_HSYNC_EN_SHIFT                   (10U)
/*! HSYNC_EN - HSYNC_EN */
#define VIU_SCR_HSYNC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_HSYNC_EN_SHIFT)) & VIU_SCR_HSYNC_EN_MASK)

#define VIU_SCR_VSTART_EN_MASK                   (0x800U)
#define VIU_SCR_VSTART_EN_SHIFT                  (11U)
/*! VSTART_EN - VSTART_EN */
#define VIU_SCR_VSTART_EN(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_VSTART_EN_SHIFT)) & VIU_SCR_VSTART_EN_MASK)

#define VIU_SCR_DMA_END_EN_MASK                  (0x1000U)
#define VIU_SCR_DMA_END_EN_SHIFT                 (12U)
/*! DMA_END_EN - DMA_END_EN */
#define VIU_SCR_DMA_END_EN(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_SCR_DMA_END_EN_SHIFT)) & VIU_SCR_DMA_END_EN_MASK)

#define VIU_SCR_ERROR_EN_MASK                    (0x2000U)
#define VIU_SCR_ERROR_EN_SHIFT                   (13U)
/*! ERROR_EN - ERROR_EN */
#define VIU_SCR_ERROR_EN(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_ERROR_EN_SHIFT)) & VIU_SCR_ERROR_EN_MASK)

#define VIU_SCR_ECC_EN_MASK                      (0x4000U)
#define VIU_SCR_ECC_EN_SHIFT                     (14U)
/*! ECC_EN - ECC_EN */
#define VIU_SCR_ECC_EN(x)                        (((uint32_t)(((uint32_t)(x)) << VIU_SCR_ECC_EN_SHIFT)) & VIU_SCR_ECC_EN_MASK)

#define VIU_SCR_FIELD_IRQ_MASK                   (0x10000U)
#define VIU_SCR_FIELD_IRQ_SHIFT                  (16U)
/*! FIELD_IRQ - FIELD_IRQ */
#define VIU_SCR_FIELD_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_FIELD_IRQ_SHIFT)) & VIU_SCR_FIELD_IRQ_MASK)

#define VIU_SCR_VSYNC_IRQ_MASK                   (0x20000U)
#define VIU_SCR_VSYNC_IRQ_SHIFT                  (17U)
/*! VSYNC_IRQ - VSYNC_IRQ */
#define VIU_SCR_VSYNC_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_VSYNC_IRQ_SHIFT)) & VIU_SCR_VSYNC_IRQ_MASK)

#define VIU_SCR_HSYNC_IRQ_MASK                   (0x40000U)
#define VIU_SCR_HSYNC_IRQ_SHIFT                  (18U)
/*! HSYNC_IRQ - HSYNC_IRQ */
#define VIU_SCR_HSYNC_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_HSYNC_IRQ_SHIFT)) & VIU_SCR_HSYNC_IRQ_MASK)

#define VIU_SCR_VSTART_IRQ_MASK                  (0x80000U)
#define VIU_SCR_VSTART_IRQ_SHIFT                 (19U)
/*! VSTART_IRQ - VSTART_IRQ */
#define VIU_SCR_VSTART_IRQ(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_SCR_VSTART_IRQ_SHIFT)) & VIU_SCR_VSTART_IRQ_MASK)

#define VIU_SCR_DMA_END_IRQ_MASK                 (0x100000U)
#define VIU_SCR_DMA_END_IRQ_SHIFT                (20U)
/*! DMA_END_IRQ - DMA_END_IRQ */
#define VIU_SCR_DMA_END_IRQ(x)                   (((uint32_t)(((uint32_t)(x)) << VIU_SCR_DMA_END_IRQ_SHIFT)) & VIU_SCR_DMA_END_IRQ_MASK)

#define VIU_SCR_ERROR_IRQ_MASK                   (0x200000U)
#define VIU_SCR_ERROR_IRQ_SHIFT                  (21U)
/*! ERROR_IRQ - ERROR_IRQ */
#define VIU_SCR_ERROR_IRQ(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_ERROR_IRQ_SHIFT)) & VIU_SCR_ERROR_IRQ_MASK)

#define VIU_SCR_MODE444_MASK                     (0x800000U)
#define VIU_SCR_MODE444_SHIFT                    (23U)
/*! MODE444 - MODE444 */
#define VIU_SCR_MODE444(x)                       (((uint32_t)(((uint32_t)(x)) << VIU_SCR_MODE444_SHIFT)) & VIU_SCR_MODE444_MASK)

#define VIU_SCR_BC_EN_MASK                       (0x1000000U)
#define VIU_SCR_BC_EN_SHIFT                      (24U)
/*! BC_EN - BC_EN */
#define VIU_SCR_BC_EN(x)                         (((uint32_t)(((uint32_t)(x)) << VIU_SCR_BC_EN_SHIFT)) & VIU_SCR_BC_EN_MASK)

#define VIU_SCR_YUV2RGB_EN_MASK                  (0x2000000U)
#define VIU_SCR_YUV2RGB_EN_SHIFT                 (25U)
/*! YUV2RGB_EN - YUV2RGB_EN */
#define VIU_SCR_YUV2RGB_EN(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_SCR_YUV2RGB_EN_SHIFT)) & VIU_SCR_YUV2RGB_EN_MASK)

#define VIU_SCR_SCALER_EN_MASK                   (0x4000000U)
#define VIU_SCR_SCALER_EN_SHIFT                  (26U)
/*! SCALER_EN - SCALER_EN */
#define VIU_SCR_SCALER_EN(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_SCALER_EN_SHIFT)) & VIU_SCR_SCALER_EN_MASK)

#define VIU_SCR_DMA_ACT_MASK                     (0x8000000U)
#define VIU_SCR_DMA_ACT_SHIFT                    (27U)
/*! DMA_ACT - DMA_ACT */
#define VIU_SCR_DMA_ACT(x)                       (((uint32_t)(((uint32_t)(x)) << VIU_SCR_DMA_ACT_SHIFT)) & VIU_SCR_DMA_ACT_MASK)

#define VIU_SCR_FIELD_NO_MASK                    (0x10000000U)
#define VIU_SCR_FIELD_NO_SHIFT                   (28U)
/*! FIELD_NO - FIELD_NO */
#define VIU_SCR_FIELD_NO(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_FIELD_NO_SHIFT)) & VIU_SCR_FIELD_NO_MASK)

#define VIU_SCR_DITHER_ON_MASK                   (0x20000000U)
#define VIU_SCR_DITHER_ON_SHIFT                  (29U)
/*! DITHER_ON - DITHER_ON */
#define VIU_SCR_DITHER_ON(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_DITHER_ON_SHIFT)) & VIU_SCR_DITHER_ON_MASK)

#define VIU_SCR_ROUND_ON_MASK                    (0x40000000U)
#define VIU_SCR_ROUND_ON_SHIFT                   (30U)
/*! ROUND_ON - ROUND_ON */
#define VIU_SCR_ROUND_ON(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_SCR_ROUND_ON_SHIFT)) & VIU_SCR_ROUND_ON_MASK)

#define VIU_SCR_MODE32BIT_MASK                   (0x80000000U)
#define VIU_SCR_MODE32BIT_SHIFT                  (31U)
/*! MODE32BIT - MODE32BIT
 *  0b0..16-bit RGB or YUV 4:2:2 output
 *  0b1..32-bit RGB or YUV 4:4:4 output. DITHER_ON and ROUND_ON are ignored if output is 32-bit RGB.
 */
#define VIU_SCR_MODE32BIT(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_SCR_MODE32BIT_SHIFT)) & VIU_SCR_MODE32BIT_MASK)
/*! @} */

/*! @name DINVSZ - Detected Input Video Pixel and Line Counts */
/*! @{ */

#define VIU_DINVSZ_DETECTED_PIXELC_MASK          (0xFFFFU)
#define VIU_DINVSZ_DETECTED_PIXELC_SHIFT         (0U)
/*! DETECTED_PIXELC - DETECTED_PIXELC */
#define VIU_DINVSZ_DETECTED_PIXELC(x)            (((uint32_t)(((uint32_t)(x)) << VIU_DINVSZ_DETECTED_PIXELC_SHIFT)) & VIU_DINVSZ_DETECTED_PIXELC_MASK)

#define VIU_DINVSZ_DETECTED_LINEC_MASK           (0xFFFF0000U)
#define VIU_DINVSZ_DETECTED_LINEC_SHIFT          (16U)
/*! DETECTED_LINEC - DETECTED_LINEC */
#define VIU_DINVSZ_DETECTED_LINEC(x)             (((uint32_t)(((uint32_t)(x)) << VIU_DINVSZ_DETECTED_LINEC_SHIFT)) & VIU_DINVSZ_DETECTED_LINEC_MASK)
/*! @} */

/*! @name DINVFL - Detected Input Video Frame Length */
/*! @{ */

#define VIU_DINVFL_DETECTED_FRAME_WIDTH_MASK     (0xFFFFU)
#define VIU_DINVFL_DETECTED_FRAME_WIDTH_SHIFT    (0U)
/*! DETECTED_FRAME_WIDTH - DETECTED_FRAME_WIDTH */
#define VIU_DINVFL_DETECTED_FRAME_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << VIU_DINVFL_DETECTED_FRAME_WIDTH_SHIFT)) & VIU_DINVFL_DETECTED_FRAME_WIDTH_MASK)

#define VIU_DINVFL_DETECTED_FRAME_HEIGHT_MASK    (0xFFFF0000U)
#define VIU_DINVFL_DETECTED_FRAME_HEIGHT_SHIFT   (16U)
/*! DETECTED_FRAME_HEIGHT - DETECTED_FRAME_HEIGHT */
#define VIU_DINVFL_DETECTED_FRAME_HEIGHT(x)      (((uint32_t)(((uint32_t)(x)) << VIU_DINVFL_DETECTED_FRAME_HEIGHT_SHIFT)) & VIU_DINVFL_DETECTED_FRAME_HEIGHT_MASK)
/*! @} */

/*! @name DMA_ADDR - Base Address Of Every Field/Frame Of Picture In Memory */
/*! @{ */

#define VIU_DMA_ADDR_ADDR_MASK                   (0xFFFFFFF8U)
#define VIU_DMA_ADDR_ADDR_SHIFT                  (3U)
/*! ADDR - ADDR */
#define VIU_DMA_ADDR_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_DMA_ADDR_ADDR_SHIFT)) & VIU_DMA_ADDR_ADDR_MASK)
/*! @} */

/*! @name DMA_INC - Horizontal DMA Increment */
/*! @{ */

#define VIU_DMA_INC_INC_MASK                     (0xFFF8U)
#define VIU_DMA_INC_INC_SHIFT                    (3U)
/*! INC - INC */
#define VIU_DMA_INC_INC(x)                       (((uint32_t)(((uint32_t)(x)) << VIU_DMA_INC_INC_SHIFT)) & VIU_DMA_INC_INC_MASK)
/*! @} */

/*! @name INVSZ - Input Video Pixel and Line Count */
/*! @{ */

#define VIU_INVSZ_PIXELC_MASK                    (0xFFFFU)
#define VIU_INVSZ_PIXELC_SHIFT                   (0U)
/*! PIXELC - PIXELC */
#define VIU_INVSZ_PIXELC(x)                      (((uint32_t)(((uint32_t)(x)) << VIU_INVSZ_PIXELC_SHIFT)) & VIU_INVSZ_PIXELC_MASK)

#define VIU_INVSZ_LINEC_MASK                     (0xFFFF0000U)
#define VIU_INVSZ_LINEC_SHIFT                    (16U)
/*! LINEC - LINEC */
#define VIU_INVSZ_LINEC(x)                       (((uint32_t)(((uint32_t)(x)) << VIU_INVSZ_LINEC_SHIFT)) & VIU_INVSZ_LINEC_MASK)
/*! @} */

/*! @name HPRALRM - High Priority Bus Request Alarm */
/*! @{ */

#define VIU_HPRALRM_ALARM_MASK                   (0xFFFFU)
#define VIU_HPRALRM_ALARM_SHIFT                  (0U)
/*! ALARM - ALARM */
#define VIU_HPRALRM_ALARM(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_HPRALRM_ALARM_SHIFT)) & VIU_HPRALRM_ALARM_MASK)
/*! @} */

/*! @name ALPHA - Programable Alpha Value */
/*! @{ */

#define VIU_ALPHA_ALPHA_MASK                     (0xFFU)
#define VIU_ALPHA_ALPHA_SHIFT                    (0U)
/*! ALPHA - ALPHA */
#define VIU_ALPHA_ALPHA(x)                       (((uint32_t)(((uint32_t)(x)) << VIU_ALPHA_ALPHA_SHIFT)) & VIU_ALPHA_ALPHA_MASK)
/*! @} */

/*! @name HFACTOR - Scaling Factor In Horizontal Direction */
/*! @{ */

#define VIU_HFACTOR_FACTOR_MASK                  (0x7FFU)
#define VIU_HFACTOR_FACTOR_SHIFT                 (0U)
/*! FACTOR - FACTOR */
#define VIU_HFACTOR_FACTOR(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_HFACTOR_FACTOR_SHIFT)) & VIU_HFACTOR_FACTOR_MASK)
/*! @} */

/*! @name VFACTOR - Down Scaling Factor In Vertical Direction */
/*! @{ */

#define VIU_VFACTOR_FACTOR_MASK                  (0x7FFU)
#define VIU_VFACTOR_FACTOR_SHIFT                 (0U)
/*! FACTOR - FACTOR */
#define VIU_VFACTOR_FACTOR(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_VFACTOR_FACTOR_SHIFT)) & VIU_VFACTOR_FACTOR_MASK)
/*! @} */

/*! @name VID_SIZE - Scaling Destination Pixel and Line Count */
/*! @{ */

#define VIU_VID_SIZE_PIXELC_MASK                 (0xFFFFU)
#define VIU_VID_SIZE_PIXELC_SHIFT                (0U)
/*! PIXELC - PIXELC */
#define VIU_VID_SIZE_PIXELC(x)                   (((uint32_t)(((uint32_t)(x)) << VIU_VID_SIZE_PIXELC_SHIFT)) & VIU_VID_SIZE_PIXELC_MASK)

#define VIU_VID_SIZE_LINEC_MASK                  (0xFFFF0000U)
#define VIU_VID_SIZE_LINEC_SHIFT                 (16U)
/*! LINEC - LINEC */
#define VIU_VID_SIZE_LINEC(x)                    (((uint32_t)(((uint32_t)(x)) << VIU_VID_SIZE_LINEC_SHIFT)) & VIU_VID_SIZE_LINEC_MASK)
/*! @} */

/*! @name LUT_ADDR - B/C Adjust Look-up-table Current Address */
/*! @{ */

#define VIU_LUT_ADDR_ADDR_MASK                   (0x3FCU)
#define VIU_LUT_ADDR_ADDR_SHIFT                  (2U)
/*! ADDR - ADDR */
#define VIU_LUT_ADDR_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_LUT_ADDR_ADDR_SHIFT)) & VIU_LUT_ADDR_ADDR_MASK)
/*! @} */

/*! @name LUT_DATA - B/C Adjust Look-up-table Data Entry */
/*! @{ */

#define VIU_LUT_DATA_DATA_MASK                   (0xFFFFFFFFU)
#define VIU_LUT_DATA_DATA_SHIFT                  (0U)
/*! DATA - DATA */
#define VIU_LUT_DATA_DATA(x)                     (((uint32_t)(((uint32_t)(x)) << VIU_LUT_DATA_DATA_SHIFT)) & VIU_LUT_DATA_DATA_MASK)
/*! @} */

/*! @name EXT_CONFIG - Extended Configuration Register */
/*! @{ */

#define VIU_EXT_CONFIG_HMIRROR_EN_MASK           (0x1U)
#define VIU_EXT_CONFIG_HMIRROR_EN_SHIFT          (0U)
/*! HMIRROR_EN - HMIRROR_EN */
#define VIU_EXT_CONFIG_HMIRROR_EN(x)             (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_HMIRROR_EN_SHIFT)) & VIU_EXT_CONFIG_HMIRROR_EN_MASK)

#define VIU_EXT_CONFIG_DE_POL_MASK               (0x2U)
#define VIU_EXT_CONFIG_DE_POL_SHIFT              (1U)
/*! DE_POL - DE_POL
 *  0b0..Active high
 *  0b1..Active low
 */
#define VIU_EXT_CONFIG_DE_POL(x)                 (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_DE_POL_SHIFT)) & VIU_EXT_CONFIG_DE_POL_MASK)

#define VIU_EXT_CONFIG_HSYNC_POL_MASK            (0x4U)
#define VIU_EXT_CONFIG_HSYNC_POL_SHIFT           (2U)
/*! HSYNC_POL - HSYNC_POL
 *  0b0..Active high
 *  0b1..Active low
 */
#define VIU_EXT_CONFIG_HSYNC_POL(x)              (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_HSYNC_POL_SHIFT)) & VIU_EXT_CONFIG_HSYNC_POL_MASK)

#define VIU_EXT_CONFIG_VSYNC_POL_MASK            (0x8U)
#define VIU_EXT_CONFIG_VSYNC_POL_SHIFT           (3U)
/*! VSYNC_POL - VSYNC_POL
 *  0b0..Active high
 *  0b1..Active low
 */
#define VIU_EXT_CONFIG_VSYNC_POL(x)              (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_VSYNC_POL_SHIFT)) & VIU_EXT_CONFIG_VSYNC_POL_MASK)

#define VIU_EXT_CONFIG_PCLK_POL_MASK             (0x10U)
#define VIU_EXT_CONFIG_PCLK_POL_SHIFT            (4U)
/*! PCLK_POL - PCLK_POL
 *  0b0..Active high
 *  0b1..Active low
 */
#define VIU_EXT_CONFIG_PCLK_POL(x)               (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_PCLK_POL_SHIFT)) & VIU_EXT_CONFIG_PCLK_POL_MASK)

#define VIU_EXT_CONFIG_INP_FORMAT_MASK           (0xE0U)
#define VIU_EXT_CONFIG_INP_FORMAT_SHIFT          (5U)
/*! INP_FORMAT - INP_FORMAT
 *  0b000..10/8bit ITU stream
 *  0b001..24bit parallel YUV. Normally it is YUV444
 *  0b010..8bit mono input. It is luminance Y.
 *  0b011..Reserved
 *  0b100..24bit parallel RGB. It is RGB888
 *  0b101..8bit serial RGB. It is RGB888 serial
 *  0b110..18bit parallel RGB. It is RGB666
 *  0b111..16bit parallel RGB. It is RGB565
 */
#define VIU_EXT_CONFIG_INP_FORMAT(x)             (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_INP_FORMAT_SHIFT)) & VIU_EXT_CONFIG_INP_FORMAT_MASK)

#define VIU_EXT_CONFIG_DE_VALID_MASK             (0x100U)
#define VIU_EXT_CONFIG_DE_VALID_SHIFT            (8U)
/*! DE_VALID - DE_VALID
 *  0b0..DE is invalid
 *  0b1..DE is valid
 */
#define VIU_EXT_CONFIG_DE_VALID(x)               (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_DE_VALID_SHIFT)) & VIU_EXT_CONFIG_DE_VALID_MASK)

#define VIU_EXT_CONFIG_RGB2YUV_EN_MASK           (0x200U)
#define VIU_EXT_CONFIG_RGB2YUV_EN_SHIFT          (9U)
/*! RGB2YUV_EN - RGB2YUV_EN */
#define VIU_EXT_CONFIG_RGB2YUV_EN(x)             (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_RGB2YUV_EN_SHIFT)) & VIU_EXT_CONFIG_RGB2YUV_EN_MASK)

#define VIU_EXT_CONFIG_LENDIAN_MASK              (0x800U)
#define VIU_EXT_CONFIG_LENDIAN_SHIFT             (11U)
/*! LENDIAN - LENDIAN
 *  0b0..Big endian
 *  0b1..Little endian
 */
#define VIU_EXT_CONFIG_LENDIAN(x)                (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_LENDIAN_SHIFT)) & VIU_EXT_CONFIG_LENDIAN_MASK)

#define VIU_EXT_CONFIG_CS_EN_MASK                (0x1000U)
#define VIU_EXT_CONFIG_CS_EN_SHIFT               (12U)
/*! CS_EN - CS_EN
 *  0b0..Chroma swap is disabled.
 *  0b1..Chroma swap is enabled.
 */
#define VIU_EXT_CONFIG_CS_EN(x)                  (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_CS_EN_SHIFT)) & VIU_EXT_CONFIG_CS_EN_MASK)

#define VIU_EXT_CONFIG_MODE_8BIT_MASK            (0x2000U)
#define VIU_EXT_CONFIG_MODE_8BIT_SHIFT           (13U)
/*! MODE_8BIT - 8 bit mode output format selector
 *  0b0..8-bit output mode is not selected
 *  0b1..8-bit output mode is selected
 */
#define VIU_EXT_CONFIG_MODE_8BIT(x)              (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_MODE_8BIT_SHIFT)) & VIU_EXT_CONFIG_MODE_8BIT_MASK)

#define VIU_EXT_CONFIG_MONO_LSB_MASK             (0x4000U)
#define VIU_EXT_CONFIG_MONO_LSB_SHIFT            (14U)
/*! MONO_LSB - Data location selector on input data bus.
 *  0b0..8-bit MONO data is on LSB of input bus
 *  0b1..8-bit MONO data is on MSB of input bus
 */
#define VIU_EXT_CONFIG_MONO_LSB(x)               (((uint32_t)(((uint32_t)(x)) << VIU_EXT_CONFIG_MONO_LSB_SHIFT)) & VIU_EXT_CONFIG_MONO_LSB_MASK)
/*! @} */

/*! @name ACT_ORG - Active Image Origin */
/*! @{ */

#define VIU_ACT_ORG_ACT_ORG_X_MASK               (0xFFFFU)
#define VIU_ACT_ORG_ACT_ORG_X_SHIFT              (0U)
/*! ACT_ORG_X - ACT_ORG_X */
#define VIU_ACT_ORG_ACT_ORG_X(x)                 (((uint32_t)(((uint32_t)(x)) << VIU_ACT_ORG_ACT_ORG_X_SHIFT)) & VIU_ACT_ORG_ACT_ORG_X_MASK)

#define VIU_ACT_ORG_ACT_ORG_Y_MASK               (0xFFFF0000U)
#define VIU_ACT_ORG_ACT_ORG_Y_SHIFT              (16U)
/*! ACT_ORG_Y - ACT_ORG_Y */
#define VIU_ACT_ORG_ACT_ORG_Y(x)                 (((uint32_t)(((uint32_t)(x)) << VIU_ACT_ORG_ACT_ORG_Y_SHIFT)) & VIU_ACT_ORG_ACT_ORG_Y_MASK)
/*! @} */

/*! @name ACT_SIZE - Active Image Size */
/*! @{ */

#define VIU_ACT_SIZE_ACT_IMG_WIDTH_MASK          (0xFFFFU)
#define VIU_ACT_SIZE_ACT_IMG_WIDTH_SHIFT         (0U)
/*! ACT_IMG_WIDTH - ACT_IMG_WIDTH */
#define VIU_ACT_SIZE_ACT_IMG_WIDTH(x)            (((uint32_t)(((uint32_t)(x)) << VIU_ACT_SIZE_ACT_IMG_WIDTH_SHIFT)) & VIU_ACT_SIZE_ACT_IMG_WIDTH_MASK)

#define VIU_ACT_SIZE_ACT_IMG_HEIGHT_MASK         (0xFFFF0000U)
#define VIU_ACT_SIZE_ACT_IMG_HEIGHT_SHIFT        (16U)
/*! ACT_IMG_HEIGHT - ACT_IMG_HEIGHT */
#define VIU_ACT_SIZE_ACT_IMG_HEIGHT(x)           (((uint32_t)(((uint32_t)(x)) << VIU_ACT_SIZE_ACT_IMG_HEIGHT_SHIFT)) & VIU_ACT_SIZE_ACT_IMG_HEIGHT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VIU_Register_Masks */


/*!
 * @}
 */ /* end of group VIU_Peripheral_Access_Layer */


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


#endif  /* PERI_VIU_H_ */

