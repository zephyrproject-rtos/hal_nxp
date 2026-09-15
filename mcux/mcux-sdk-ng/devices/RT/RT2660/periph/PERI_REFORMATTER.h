/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for REFORMATTER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_REFORMATTER.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for REFORMATTER
 *
 * CMSIS Peripheral Access Layer for REFORMATTER
 */

#if !defined(PERI_REFORMATTER_H_)
#define PERI_REFORMATTER_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- REFORMATTER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REFORMATTER_Peripheral_Access_Layer REFORMATTER Peripheral Access Layer
 * @{
 */

/** REFORMATTER - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< MIPI CSI RAW Data Control Register, offset: 0x0 */
    __IO uint32_t SET;                               /**< MIPI CSI RAW Data Control Register, offset: 0x4 */
    __IO uint32_t CLR;                               /**< MIPI CSI RAW Data Control Register, offset: 0x8 */
    __IO uint32_t TOG;                               /**< MIPI CSI RAW Data Control Register, offset: 0xC */
  } MIPI_CSI_CTRL;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Control Fence VC Register, offset: 0x10 */
    __IO uint32_t SET;                               /**< Control Fence VC Register, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Control Fence VC Register, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Control Fence VC Register, offset: 0x1C */
  } STREAM_FENCING_CTRL;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< PLM Control register, offset: 0x20 */
    __IO uint32_t SET;                               /**< PLM Control register, offset: 0x24 */
    __IO uint32_t CLR;                               /**< PLM Control register, offset: 0x28 */
    __IO uint32_t TOG;                               /**< PLM Control register, offset: 0x2C */
  } PLM_CTRL;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< YUV420 Control, offset: 0x30 */
    __IO uint32_t SET;                               /**< YUV420 Control, offset: 0x34 */
    __IO uint32_t CLR;                               /**< YUV420 Control, offset: 0x38 */
    __IO uint32_t TOG;                               /**< YUV420 Control, offset: 0x3C */
  } YUV420_CTRL;
  struct {                                         /* offset: 0x40 */
    __I  uint32_t RW;                                /**< Stream Fencing Status register, offset: 0x40 */
    __I  uint32_t SET;                               /**< Stream Fencing Status register, offset: 0x44 */
    __I  uint32_t CLR;                               /**< Stream Fencing Status register, offset: 0x48 */
    __I  uint32_t TOG;                               /**< Stream Fencing Status register, offset: 0x4C */
  } STREAM_FENCING_STAT;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Datatype Disable Register, offset: 0x50 */
    __IO uint32_t SET;                               /**< Datatype Disable Register, offset: 0x54 */
    __IO uint32_t CLR;                               /**< Datatype Disable Register, offset: 0x58 */
    __IO uint32_t TOG;                               /**< Datatype Disable Register, offset: 0x5C */
  } CFG_DT_DISABLE;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< ISI Pixel Link to DCIF PDI Control Register, offset: 0x60 */
    __IO uint32_t SET;                               /**< ISI Pixel Link to DCIF PDI Control Register, offset: 0x64 */
    __IO uint32_t CLR;                               /**< ISI Pixel Link to DCIF PDI Control Register, offset: 0x68 */
    __IO uint32_t TOG;                               /**< ISI Pixel Link to DCIF PDI Control Register, offset: 0x6C */
  } PL_TO_PDI_CTRL;
  __IO uint32_t VC_INTERLACED;                     /**< VC Interlaced, offset: 0x70 */
  __IO uint32_t ISI2PL_IER;                        /**< ISI to Pixel Link Interrupt Enable, offset: 0x74 */
  __IO uint32_t ISI2PL_ISTS;                       /**< ISI to Pixel Link Interrupt Flag, offset: 0x78 */
} REFORMATTER_Type;

/* ----------------------------------------------------------------------------
   -- REFORMATTER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup REFORMATTER_Register_Masks REFORMATTER Register Masks
 * @{
 */

/*! @name MIPI_CSI_CTRL - MIPI CSI RAW Data Control Register */
/*! @{ */

#define REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT_MASK  (0x1U)
#define REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT_SHIFT (0U)
/*! NO_SHIFT - RAW Data Shift Control.
 *  0b0..RAW data is aligned wrt LSB from 16 bits except for RAW20 and RAW24 where data is aligned wrt LSB from 32 bits.
 *  0b1..No RAW Data is shifted and aligned to LSB
 */
#define REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT(x)    (((uint32_t)(((uint32_t)(x)) << REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT_SHIFT)) & REFORMATTER_MIPI_CSI_CTRL_NO_SHIFT_MASK)
/*! @} */

/*! @name STREAM_FENCING_CTRL - Control Fence VC Register */
/*! @{ */

#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC0_MASK (0x1U)
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC0_SHIFT (0U)
/*! FENCE_VC0 - Stream fencing VC0 */
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC0(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC0_SHIFT)) & REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC0_MASK)

#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC1_MASK (0x2U)
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC1_SHIFT (1U)
/*! FENCE_VC1 - Stream fencing VC1 */
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC1(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC1_SHIFT)) & REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC1_MASK)

#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC2_MASK (0x4U)
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC2_SHIFT (2U)
/*! FENCE_VC2 - Stream fencing VC2 */
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC2(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC2_SHIFT)) & REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC2_MASK)

#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC3_MASK (0x8U)
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC3_SHIFT (3U)
/*! FENCE_VC3 - Stream fencing VC3 */
#define REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC3(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC3_SHIFT)) & REFORMATTER_STREAM_FENCING_CTRL_FENCE_VC3_MASK)
/*! @} */

/*! @name PLM_CTRL - PLM Control register */
/*! @{ */

#define REFORMATTER_PLM_CTRL_ENABLE_MASK         (0x1U)
#define REFORMATTER_PLM_CTRL_ENABLE_SHIFT        (0U)
/*! ENABLE - Enable bit */
#define REFORMATTER_PLM_CTRL_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PLM_CTRL_ENABLE_SHIFT)) & REFORMATTER_PLM_CTRL_ENABLE_MASK)

#define REFORMATTER_PLM_CTRL_VSYNC_OVERRIDE_MASK (0x2U)
#define REFORMATTER_PLM_CTRL_VSYNC_OVERRIDE_SHIFT (1U)
/*! VSYNC_OVERRIDE - VSYNC override */
#define REFORMATTER_PLM_CTRL_VSYNC_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PLM_CTRL_VSYNC_OVERRIDE_SHIFT)) & REFORMATTER_PLM_CTRL_VSYNC_OVERRIDE_MASK)

#define REFORMATTER_PLM_CTRL_HSYNC_OVERRIDE_MASK (0x4U)
#define REFORMATTER_PLM_CTRL_HSYNC_OVERRIDE_SHIFT (2U)
/*! HSYNC_OVERRIDE - HSYNC override */
#define REFORMATTER_PLM_CTRL_HSYNC_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PLM_CTRL_HSYNC_OVERRIDE_SHIFT)) & REFORMATTER_PLM_CTRL_HSYNC_OVERRIDE_MASK)

#define REFORMATTER_PLM_CTRL_VALID_OVERRIDE_MASK (0x8U)
#define REFORMATTER_PLM_CTRL_VALID_OVERRIDE_SHIFT (3U)
/*! VALID_OVERRIDE - Valid override */
#define REFORMATTER_PLM_CTRL_VALID_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PLM_CTRL_VALID_OVERRIDE_SHIFT)) & REFORMATTER_PLM_CTRL_VALID_OVERRIDE_MASK)

#define REFORMATTER_PLM_CTRL_POLARITY_MASK       (0x10U)
#define REFORMATTER_PLM_CTRL_POLARITY_SHIFT      (4U)
/*! POLARITY - Polarity */
#define REFORMATTER_PLM_CTRL_POLARITY(x)         (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PLM_CTRL_POLARITY_SHIFT)) & REFORMATTER_PLM_CTRL_POLARITY_MASK)
/*! @} */

/*! @name YUV420_CTRL - YUV420 Control */
/*! @{ */

#define REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE_MASK (0x1U)
#define REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE_SHIFT (0U)
/*! FST_LN_DATA_TYPE - First line data type
 *  0b0..Odd value
 *  0b1..Even value
 */
#define REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE_SHIFT)) & REFORMATTER_YUV420_CTRL_FST_LN_DATA_TYPE_MASK)
/*! @} */

/*! @name STREAM_FENCING_STAT - Stream Fencing Status register */
/*! @{ */

#define REFORMATTER_STREAM_FENCING_STAT_VC0_FENCED_MASK (0x1U)
#define REFORMATTER_STREAM_FENCING_STAT_VC0_FENCED_SHIFT (0U)
/*! VC0_FENCED - VC0 Fenced */
#define REFORMATTER_STREAM_FENCING_STAT_VC0_FENCED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_STAT_VC0_FENCED_SHIFT)) & REFORMATTER_STREAM_FENCING_STAT_VC0_FENCED_MASK)

#define REFORMATTER_STREAM_FENCING_STAT_VC1_FENCED_MASK (0x2U)
#define REFORMATTER_STREAM_FENCING_STAT_VC1_FENCED_SHIFT (1U)
/*! VC1_FENCED - VC1 Fenced */
#define REFORMATTER_STREAM_FENCING_STAT_VC1_FENCED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_STAT_VC1_FENCED_SHIFT)) & REFORMATTER_STREAM_FENCING_STAT_VC1_FENCED_MASK)

#define REFORMATTER_STREAM_FENCING_STAT_VC2_FENCED_MASK (0x4U)
#define REFORMATTER_STREAM_FENCING_STAT_VC2_FENCED_SHIFT (2U)
/*! VC2_FENCED - VC2 Fenced */
#define REFORMATTER_STREAM_FENCING_STAT_VC2_FENCED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_STAT_VC2_FENCED_SHIFT)) & REFORMATTER_STREAM_FENCING_STAT_VC2_FENCED_MASK)

#define REFORMATTER_STREAM_FENCING_STAT_VC3_FENCED_MASK (0x8U)
#define REFORMATTER_STREAM_FENCING_STAT_VC3_FENCED_SHIFT (3U)
/*! VC3_FENCED - VC0 Fenced */
#define REFORMATTER_STREAM_FENCING_STAT_VC3_FENCED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_STREAM_FENCING_STAT_VC3_FENCED_SHIFT)) & REFORMATTER_STREAM_FENCING_STAT_VC3_FENCED_MASK)
/*! @} */

/*! @name CFG_DT_DISABLE - Datatype Disable Register */
/*! @{ */

#define REFORMATTER_CFG_DT_DISABLE_CFG_DT_DISABLE_MASK (0xFFFFFFFFU)
#define REFORMATTER_CFG_DT_DISABLE_CFG_DT_DISABLE_SHIFT (0U)
/*! CFG_DT_DISABLE - Data Type Disable
 *  0b00000000000000000000000000000000..YUV420_8BIT
 *  0b00000000000000000000000000000001..YUV420_10BIT
 *  0b00000000000000000000000000000100..LEGACY_YUV420_8BIT
 *  0b00000000000000000000000000001000..Reserved
 *  0b00000000000000000000000000010000..YUV420_8BIT_CS
 *  0b00000000000000000000000000100000..YUV420_10BIT_CS
 *  0b00000000000000000000000001000000..YUV422_8BIT
 *  0b00000000000000000000000010000000..YUV422_10BIT RGB Image Data Type
 *  0b00000000000000000000000100000000..RGB444
 *  0b00000000000000000000001000000000..RGB555
 *  0b00000000000000000000010000000000..RGB565
 *  0b00000000000000000000100000000000..RGB666
 *  0b00000000000000000001000000000000..RGB888
 *  0b00000000000000000010000000000000..Reserved
 *  0b00000000000000000100000000000000..EMBEDDED Raw Image Data Types
 *  0b00000000000000001000000000000000..RAW24
 *  0b00000000000000010000000000000000..RAW6
 *  0b00000000000000100000000000000000..RAW7
 *  0b00000000000001000000000000000000..RAW8
 *  0b00000000000010000000000000000000..RAW10
 *  0b00000000000100000000000000000000..RAW12
 *  0b00000000001000000000000000000000..RAW14
 *  0b00000000010000000000000000000000..RAW16
 *  0b00000000100000000000000000000000..RAW20
 *  0b00000001000000000000000000000000..User-defined 0
 *  0b00000010000000000000000000000000..User-defined 1
 *  0b00000100000000000000000000000000..User-defined 2
 *  0b00001000000000000000000000000000..User-defined 3
 *  0b00010000000000000000000000000000..User-defined 4
 *  0b00100000000000000000000000000000..User-defined 5
 *  0b01000000000000000000000000000000..User-defined 6
 *  0b10000000000000000000000000000000..User-defined 7
 */
#define REFORMATTER_CFG_DT_DISABLE_CFG_DT_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_CFG_DT_DISABLE_CFG_DT_DISABLE_SHIFT)) & REFORMATTER_CFG_DT_DISABLE_CFG_DT_DISABLE_MASK)
/*! @} */

/*! @name PL_TO_PDI_CTRL - ISI Pixel Link to DCIF PDI Control Register */
/*! @{ */

#define REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN_MASK (0x1U)
#define REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN_SHIFT (0U)
/*! PL_TO_PDI_EN - Pixel Link to PDI Enable
 *  0b0..Disables conversion
 *  0b1..Enables conversion
 */
#define REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN_SHIFT)) & REFORMATTER_PL_TO_PDI_CTRL_PL_TO_PDI_EN_MASK)
/*! @} */

/*! @name VC_INTERLACED - VC Interlaced */
/*! @{ */

#define REFORMATTER_VC_INTERLACED_VC0_INTERLACED_MASK (0x1U)
#define REFORMATTER_VC_INTERLACED_VC0_INTERLACED_SHIFT (0U)
/*! VC0_INTERLACED - VC0 Interlaced */
#define REFORMATTER_VC_INTERLACED_VC0_INTERLACED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC0_INTERLACED_SHIFT)) & REFORMATTER_VC_INTERLACED_VC0_INTERLACED_MASK)

#define REFORMATTER_VC_INTERLACED_VC1_INTERLACED_MASK (0x2U)
#define REFORMATTER_VC_INTERLACED_VC1_INTERLACED_SHIFT (1U)
/*! VC1_INTERLACED - VC1 Interlaced */
#define REFORMATTER_VC_INTERLACED_VC1_INTERLACED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC1_INTERLACED_SHIFT)) & REFORMATTER_VC_INTERLACED_VC1_INTERLACED_MASK)

#define REFORMATTER_VC_INTERLACED_VC2_INTERLACED_MASK (0x4U)
#define REFORMATTER_VC_INTERLACED_VC2_INTERLACED_SHIFT (2U)
/*! VC2_INTERLACED - VC2 Interlaced */
#define REFORMATTER_VC_INTERLACED_VC2_INTERLACED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC2_INTERLACED_SHIFT)) & REFORMATTER_VC_INTERLACED_VC2_INTERLACED_MASK)

#define REFORMATTER_VC_INTERLACED_VC3_INTERLACED_MASK (0x8U)
#define REFORMATTER_VC_INTERLACED_VC3_INTERLACED_SHIFT (3U)
/*! VC3_INTERLACED - VC3 Interlaced */
#define REFORMATTER_VC_INTERLACED_VC3_INTERLACED(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC3_INTERLACED_SHIFT)) & REFORMATTER_VC_INTERLACED_VC3_INTERLACED_MASK)

#define REFORMATTER_VC_INTERLACED_VC0_FIRST_FRAME_IS_EVEN_MASK (0x10U)
#define REFORMATTER_VC_INTERLACED_VC0_FIRST_FRAME_IS_EVEN_SHIFT (4U)
/*! VC0_FIRST_FRAME_IS_EVEN - VC0 First Frame is Even */
#define REFORMATTER_VC_INTERLACED_VC0_FIRST_FRAME_IS_EVEN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC0_FIRST_FRAME_IS_EVEN_SHIFT)) & REFORMATTER_VC_INTERLACED_VC0_FIRST_FRAME_IS_EVEN_MASK)

#define REFORMATTER_VC_INTERLACED_VC1_FIRST_FRAME_IS_EVEN_MASK (0x20U)
#define REFORMATTER_VC_INTERLACED_VC1_FIRST_FRAME_IS_EVEN_SHIFT (5U)
/*! VC1_FIRST_FRAME_IS_EVEN - VC1 First Frame is Even */
#define REFORMATTER_VC_INTERLACED_VC1_FIRST_FRAME_IS_EVEN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC1_FIRST_FRAME_IS_EVEN_SHIFT)) & REFORMATTER_VC_INTERLACED_VC1_FIRST_FRAME_IS_EVEN_MASK)

#define REFORMATTER_VC_INTERLACED_VC2_FIRST_FRAME_IS_EVEN_MASK (0x40U)
#define REFORMATTER_VC_INTERLACED_VC2_FIRST_FRAME_IS_EVEN_SHIFT (6U)
/*! VC2_FIRST_FRAME_IS_EVEN - VC2 First Frame is Even */
#define REFORMATTER_VC_INTERLACED_VC2_FIRST_FRAME_IS_EVEN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC2_FIRST_FRAME_IS_EVEN_SHIFT)) & REFORMATTER_VC_INTERLACED_VC2_FIRST_FRAME_IS_EVEN_MASK)

#define REFORMATTER_VC_INTERLACED_VC3_FIRST_FRAME_IS_EVEN_MASK (0x80U)
#define REFORMATTER_VC_INTERLACED_VC3_FIRST_FRAME_IS_EVEN_SHIFT (7U)
/*! VC3_FIRST_FRAME_IS_EVEN - VC3 First Frame is Even */
#define REFORMATTER_VC_INTERLACED_VC3_FIRST_FRAME_IS_EVEN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_VC_INTERLACED_VC3_FIRST_FRAME_IS_EVEN_SHIFT)) & REFORMATTER_VC_INTERLACED_VC3_FIRST_FRAME_IS_EVEN_MASK)
/*! @} */

/*! @name ISI2PL_IER - ISI to Pixel Link Interrupt Enable */
/*! @{ */

#define REFORMATTER_ISI2PL_IER_ISI_DT_NOT_RGB_ERR_EN_MASK (0x1U)
#define REFORMATTER_ISI2PL_IER_ISI_DT_NOT_RGB_ERR_EN_SHIFT (0U)
/*! ISI_DT_NOT_RGB_ERR_EN - ISI Data Type is not RGB888 Error enable */
#define REFORMATTER_ISI2PL_IER_ISI_DT_NOT_RGB_ERR_EN(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_ISI2PL_IER_ISI_DT_NOT_RGB_ERR_EN_SHIFT)) & REFORMATTER_ISI2PL_IER_ISI_DT_NOT_RGB_ERR_EN_MASK)
/*! @} */

/*! @name ISI2PL_ISTS - ISI to Pixel Link Interrupt Flag */
/*! @{ */

#define REFORMATTER_ISI2PL_ISTS_ISI_DT_NOT_RGB_STS_MASK (0x1U)
#define REFORMATTER_ISI2PL_ISTS_ISI_DT_NOT_RGB_STS_SHIFT (0U)
/*! ISI_DT_NOT_RGB_STS - ISI Data Type is not RGB888 Error status */
#define REFORMATTER_ISI2PL_ISTS_ISI_DT_NOT_RGB_STS(x) (((uint32_t)(((uint32_t)(x)) << REFORMATTER_ISI2PL_ISTS_ISI_DT_NOT_RGB_STS_SHIFT)) & REFORMATTER_ISI2PL_ISTS_ISI_DT_NOT_RGB_STS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group REFORMATTER_Register_Masks */


/*!
 * @}
 */ /* end of group REFORMATTER_Peripheral_Access_Layer */


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


#endif  /* PERI_REFORMATTER_H_ */

