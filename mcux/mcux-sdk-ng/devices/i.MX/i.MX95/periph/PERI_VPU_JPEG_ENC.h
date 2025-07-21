/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b250106
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_JPEG_ENC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file VPU_JPEG_ENC.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for VPU_JPEG_ENC
 *
 * CMSIS Peripheral Access Layer for VPU_JPEG_ENC
 */

#if !defined(VPU_JPEG_ENC_H_)
#define VPU_JPEG_ENC_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- VPU_JPEG_ENC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_JPEG_ENC_Peripheral_Access_Layer VPU_JPEG_ENC Peripheral Access Layer
 * @{
 */

/** VPU_JPEG_ENC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __O  uint32_t MODE;                              /**< Mode Control, offset: 0x0 */
      __O  uint32_t CFG_MODE;                          /**< Configuration Mode, offset: 0x4 */
      __O  uint32_t QUALITY;                           /**< Quality Factor, offset: 0x8 */
           uint8_t RESERVED_0[4];
      __O  uint32_t RC_REGS_SEL;                       /**< Indirect Status Register Select, offset: 0x10 */
      __O  uint32_t LUMTH;                             /**< Luminance Threshold, offset: 0x14 */
      __O  uint32_t CHRTH;                             /**< Chrominance Threshold, offset: 0x18 */
           uint8_t RESERVED_1[36];
      __O  uint32_t NOMFRSIZE_LO;                      /**< Nominal Frame Size Low, offset: 0x40 */
      __O  uint32_t NOMFRSIZE_HI;                      /**< Nominal Frame Size High, offset: 0x44 */
      __O  uint32_t OFBSIZE_LO;                        /**< FIFO Buffer Size Low, offset: 0x48 */
      __O  uint32_t OFBSIZE_HI;                        /**< FIFO Buffer Size High, offset: 0x4C */
    } CONTROL;
    struct {                                         /* offset: 0x0 */
      __I  uint32_t STATUS_0;                          /**< Status 0, offset: 0x0 */
      __I  uint32_t STATUS_1;                          /**< Status 1, offset: 0x4 */
      __I  uint32_t STATUS_2;                          /**< Status 2, offset: 0x8 */
      __I  uint32_t STATUS_3;                          /**< Status 3, offset: 0xC */
      __I  uint32_t STATUS_4;                          /**< Status 4, offset: 0x10 */
      __I  uint32_t STATUS_5;                          /**< Status 5, offset: 0x14 */
      __I  uint32_t STATUS_6;                          /**< Status 6, offset: 0x18 */
      __I  uint32_t STATUS_7;                          /**< Status 7, offset: 0x1C */
      __I  uint32_t STATUS_8;                          /**< Status 8, offset: 0x20 */
      __I  uint32_t STATUS_9;                          /**< Status 9, offset: 0x24 */
      __I  uint32_t STATUS_10;                         /**< Status 10, offset: 0x28 */
      __I  uint32_t STATUS_11;                         /**< Status 11, offset: 0x2C */
      __I  uint32_t STATUS_12;                         /**< Status 12, offset: 0x30 */
      __I  uint32_t STATUS_13;                         /**< Status 13, offset: 0x34 */
      __I  uint32_t STATUS_14;                         /**< Status 14, offset: 0x38 */
      __I  uint32_t STATUS_15;                         /**< Status 15, offset: 0x3C */
      __I  uint32_t STATUS_16;                         /**< Status 16, offset: 0x40 */
      __I  uint32_t STATUS_17;                         /**< Status 17, offset: 0x44 */
      __I  uint32_t STATUS_18;                         /**< Status 18, offset: 0x48 */
      __I  uint32_t STATUS_19;                         /**< Status 19, offset: 0x4C */
    } STATUS;
  };
} VPU_JPEG_ENC_Type;

/* ----------------------------------------------------------------------------
   -- VPU_JPEG_ENC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_JPEG_ENC_Register_Masks VPU_JPEG_ENC Register Masks
 * @{
 */

/*! @name MODE - Mode Control */
/*! @{ */

#define VPU_JPEG_ENC_MODE_LP_MASK                (0x1U)
#define VPU_JPEG_ENC_MODE_LP_SHIFT               (0U)
/*! LP - Low Power
 *  0b0..No effect
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_LP(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_LP_SHIFT)) & VPU_JPEG_ENC_MODE_LP_MASK)

#define VPU_JPEG_ENC_MODE_SWR_MASK               (0x2U)
#define VPU_JPEG_ENC_MODE_SWR_SHIFT              (1U)
/*! SWR - Software Reset
 *  0b0..No effect
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_SWR(x)                 (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_SWR_SHIFT)) & VPU_JPEG_ENC_MODE_SWR_MASK)

#define VPU_JPEG_ENC_MODE_MS_MASK                (0x8U)
#define VPU_JPEG_ENC_MODE_MS_SHIFT               (3U)
/*! MS - Multi-Scan JPEG Encoding
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_MS(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_MS_SHIFT)) & VPU_JPEG_ENC_MODE_MS_MASK)

#define VPU_JPEG_ENC_MODE_EXTSEQ_MASK            (0x10U)
#define VPU_JPEG_ENC_MODE_EXTSEQ_SHIFT           (4U)
/*! EXTSEQ - Extended Sequential Operation Mode
 *  0b0..Baseline operation mode
 *  0b1..Extended sequential operation mode
 */
#define VPU_JPEG_ENC_MODE_EXTSEQ(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_EXTSEQ_SHIFT)) & VPU_JPEG_ENC_MODE_EXTSEQ_MASK)

#define VPU_JPEG_ENC_MODE_CONF_MASK              (0x20U)
#define VPU_JPEG_ENC_MODE_CONF_SHIFT             (5U)
/*! CONF - Configuration Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_CONF(x)                (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_CONF_SHIFT)) & VPU_JPEG_ENC_MODE_CONF_MASK)

#define VPU_JPEG_ENC_MODE_GO_MASK                (0x40U)
#define VPU_JPEG_ENC_MODE_GO_SHIFT               (6U)
/*! GO - Start Encoding
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_GO(x)                  (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_GO_SHIFT)) & VPU_JPEG_ENC_MODE_GO_MASK)

#define VPU_JPEG_ENC_MODE_AUTOCLR_CONF_MASK      (0x80U)
#define VPU_JPEG_ENC_MODE_AUTOCLR_CONF_SHIFT     (7U)
/*! AUTOCLR_CONF - Auto Clear Configuration
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_AUTOCLR_CONF(x)        (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_AUTOCLR_CONF_SHIFT)) & VPU_JPEG_ENC_MODE_AUTOCLR_CONF_MASK)

#define VPU_JPEG_ENC_MODE_AUTOCLR_GO_MASK        (0x100U)
#define VPU_JPEG_ENC_MODE_AUTOCLR_GO_SHIFT       (8U)
/*! AUTOCLR_GO - Auto Clear GO
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_MODE_AUTOCLR_GO(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_MODE_AUTOCLR_GO_SHIFT)) & VPU_JPEG_ENC_MODE_AUTOCLR_GO_MASK)
/*! @} */

/*! @name CFG_MODE - Configuration Mode */
/*! @{ */

#define VPU_JPEG_ENC_CFG_MODE_MSOF0_MASK         (0x1U)
#define VPU_JPEG_ENC_CFG_MODE_MSOF0_SHIFT        (0U)
/*! MSOF0 - Mask Sequence Of Frame 0
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MSOF0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MSOF0_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MSOF0_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MDRI_MASK          (0x2U)
#define VPU_JPEG_ENC_CFG_MODE_MDRI_SHIFT         (1U)
/*! MDRI - Mask Define Restart Interval
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MDRI(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MDRI_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MDRI_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MDQT_MASK          (0x4U)
#define VPU_JPEG_ENC_CFG_MODE_MDQT_SHIFT         (2U)
/*! MDQT - Mask Define Quantization Table
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MDQT(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MDQT_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MDQT_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MDHT_MASK          (0x8U)
#define VPU_JPEG_ENC_CFG_MODE_MDHT_SHIFT         (3U)
/*! MDHT - Mask Define Huffman Table
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MDHT(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MDHT_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MDHT_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MSOS_MASK          (0x10U)
#define VPU_JPEG_ENC_CFG_MODE_MSOS_SHIFT         (4U)
/*! MSOS - Mask Start Of Scan
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MSOS(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MSOS_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MSOS_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MDNL_MASK          (0x20U)
#define VPU_JPEG_ENC_CFG_MODE_MDNL_SHIFT         (5U)
/*! MDNL - Mask Define Number of Lines
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MDNL(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MDNL_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MDNL_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MAPP_MASK          (0x40U)
#define VPU_JPEG_ENC_CFG_MODE_MAPP_SHIFT         (6U)
/*! MAPP - Mask Application
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MAPP(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MAPP_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MAPP_MASK)

#define VPU_JPEG_ENC_CFG_MODE_MCOM_MASK          (0x80U)
#define VPU_JPEG_ENC_CFG_MODE_MCOM_SHIFT         (7U)
/*! MCOM - Mask Comment
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_MCOM(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_MCOM_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_MCOM_MASK)

#define VPU_JPEG_ENC_CFG_MODE_COMB_DQT_MASK      (0x100U)
#define VPU_JPEG_ENC_CFG_MODE_COMB_DQT_SHIFT     (8U)
/*! COMB_DQT - Combined Define Quantization Table
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_COMB_DQT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_COMB_DQT_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_COMB_DQT_MASK)

#define VPU_JPEG_ENC_CFG_MODE_COMB_DHT_MASK      (0x200U)
#define VPU_JPEG_ENC_CFG_MODE_COMB_DHT_SHIFT     (9U)
/*! COMB_DHT - Combined Define Huffman Table
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_COMB_DHT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_COMB_DHT_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_COMB_DHT_MASK)

#define VPU_JPEG_ENC_CFG_MODE_DICOM_MASK         (0x400U)
#define VPU_JPEG_ENC_CFG_MODE_DICOM_SHIFT        (10U)
/*! DICOM - DICOM
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_CFG_MODE_DICOM(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CFG_MODE_DICOM_SHIFT)) & VPU_JPEG_ENC_CFG_MODE_DICOM_MASK)
/*! @} */

/*! @name QUALITY - Quality Factor */
/*! @{ */

#define VPU_JPEG_ENC_QUALITY_QUALITY_MASK        (0x7FU)
#define VPU_JPEG_ENC_QUALITY_QUALITY_SHIFT       (0U)
/*! QUALITY - Quality Factor */
#define VPU_JPEG_ENC_QUALITY_QUALITY(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_QUALITY_QUALITY_SHIFT)) & VPU_JPEG_ENC_QUALITY_QUALITY_MASK)
/*! @} */

/*! @name RC_REGS_SEL - Indirect Status Register Select */
/*! @{ */

#define VPU_JPEG_ENC_RC_REGS_SEL_RC_REGS_SEL_MASK (0x3U)
#define VPU_JPEG_ENC_RC_REGS_SEL_RC_REGS_SEL_SHIFT (0U)
/*! RC_REGS_SEL - Rate-Control Register Set Select
 *  0b00..RC_REGS0: LUMTH; RC_REGS1: CHRTH.
 *  0b01..RC_REGS0: Bits [31:16] of register with total truncated bits of luminance blocks; RC_REGS1: Bits [15:0]
 *        of register with total truncated bits of luminance blocks.
 *  0b10..RC_REGS0: Bits [31:16] of register with total truncated bits of chrominance blocks; RC_REGS1: Bits
 *        [15:0] of register with total truncated bits of chrominance blocks.
 *  0b11..
 */
#define VPU_JPEG_ENC_RC_REGS_SEL_RC_REGS_SEL(x)  (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_RC_REGS_SEL_RC_REGS_SEL_SHIFT)) & VPU_JPEG_ENC_RC_REGS_SEL_RC_REGS_SEL_MASK)
/*! @} */

/*! @name LUMTH - Luminance Threshold */
/*! @{ */

#define VPU_JPEG_ENC_LUMTH_LUMTH_MASK            (0xFFFFU)
#define VPU_JPEG_ENC_LUMTH_LUMTH_SHIFT           (0U)
/*! LUMTH - Luminance Threshold */
#define VPU_JPEG_ENC_LUMTH_LUMTH(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_LUMTH_LUMTH_SHIFT)) & VPU_JPEG_ENC_LUMTH_LUMTH_MASK)
/*! @} */

/*! @name CHRTH - Chrominance Threshold */
/*! @{ */

#define VPU_JPEG_ENC_CHRTH_CHRTH_MASK            (0xFFFFU)
#define VPU_JPEG_ENC_CHRTH_CHRTH_SHIFT           (0U)
/*! CHRTH - Chrominance Threshold */
#define VPU_JPEG_ENC_CHRTH_CHRTH(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_CHRTH_CHRTH_SHIFT)) & VPU_JPEG_ENC_CHRTH_CHRTH_MASK)
/*! @} */

/*! @name NOMFRSIZE_LO - Nominal Frame Size Low */
/*! @{ */

#define VPU_JPEG_ENC_NOMFRSIZE_LO_NOMFRSIZE_LO_MASK (0xFFFFU)
#define VPU_JPEG_ENC_NOMFRSIZE_LO_NOMFRSIZE_LO_SHIFT (0U)
/*! NOMFRSIZE_LO - Nominal Frame Size Low */
#define VPU_JPEG_ENC_NOMFRSIZE_LO_NOMFRSIZE_LO(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_NOMFRSIZE_LO_NOMFRSIZE_LO_SHIFT)) & VPU_JPEG_ENC_NOMFRSIZE_LO_NOMFRSIZE_LO_MASK)
/*! @} */

/*! @name NOMFRSIZE_HI - Nominal Frame Size High */
/*! @{ */

#define VPU_JPEG_ENC_NOMFRSIZE_HI_NOMFRSIZE_HI_MASK (0xFFFFU)
#define VPU_JPEG_ENC_NOMFRSIZE_HI_NOMFRSIZE_HI_SHIFT (0U)
/*! NOMFRSIZE_HI - Nominal Frame Size High */
#define VPU_JPEG_ENC_NOMFRSIZE_HI_NOMFRSIZE_HI(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_NOMFRSIZE_HI_NOMFRSIZE_HI_SHIFT)) & VPU_JPEG_ENC_NOMFRSIZE_HI_NOMFRSIZE_HI_MASK)
/*! @} */

/*! @name OFBSIZE_LO - FIFO Buffer Size Low */
/*! @{ */

#define VPU_JPEG_ENC_OFBSIZE_LO_OFBSIZE_LO_MASK  (0xFFFFU)
#define VPU_JPEG_ENC_OFBSIZE_LO_OFBSIZE_LO_SHIFT (0U)
/*! OFBSIZE_LO - FIFO Buffer Size Low */
#define VPU_JPEG_ENC_OFBSIZE_LO_OFBSIZE_LO(x)    (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_OFBSIZE_LO_OFBSIZE_LO_SHIFT)) & VPU_JPEG_ENC_OFBSIZE_LO_OFBSIZE_LO_MASK)
/*! @} */

/*! @name OFBSIZE_HI - FIFO Buffer Size High */
/*! @{ */

#define VPU_JPEG_ENC_OFBSIZE_HI_OFBSIZE_HI_MASK  (0xFFFFU)
#define VPU_JPEG_ENC_OFBSIZE_HI_OFBSIZE_HI_SHIFT (0U)
/*! OFBSIZE_HI - FIFO Buffer Size High */
#define VPU_JPEG_ENC_OFBSIZE_HI_OFBSIZE_HI(x)    (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_OFBSIZE_HI_OFBSIZE_HI_SHIFT)) & VPU_JPEG_ENC_OFBSIZE_HI_OFBSIZE_HI_MASK)
/*! @} */

/*! @name STATUS_0 - Status 0 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_0_X_MASK             (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_0_X_SHIFT            (0U)
/*! X - Image width */
#define VPU_JPEG_ENC_STATUS_0_X(x)               (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_0_X_SHIFT)) & VPU_JPEG_ENC_STATUS_0_X_MASK)
/*! @} */

/*! @name STATUS_1 - Status 1 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_1_Y_MASK             (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_1_Y_SHIFT            (0U)
/*! Y - Image Height */
#define VPU_JPEG_ENC_STATUS_1_Y(x)               (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_1_Y_SHIFT)) & VPU_JPEG_ENC_STATUS_1_Y_MASK)
/*! @} */

/*! @name STATUS_2 - Status 2 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_2_HMCU_MASK          (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_2_HMCU_SHIFT         (0U)
/*! HMCU - Horizontal MCU */
#define VPU_JPEG_ENC_STATUS_2_HMCU(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_2_HMCU_SHIFT)) & VPU_JPEG_ENC_STATUS_2_HMCU_MASK)
/*! @} */

/*! @name STATUS_3 - Status 3 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_3_VMCU_MASK          (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_3_VMCU_SHIFT         (0U)
/*! VMCU - Vertical MCU */
#define VPU_JPEG_ENC_STATUS_3_VMCU(x)            (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_3_VMCU_SHIFT)) & VPU_JPEG_ENC_STATUS_3_VMCU_MASK)
/*! @} */

/*! @name STATUS_4 - Status 4 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_4_Tq0_MASK           (0x3U)
#define VPU_JPEG_ENC_STATUS_4_Tq0_SHIFT          (0U)
/*! Tq0 - Table Quantization 0 ID */
#define VPU_JPEG_ENC_STATUS_4_Tq0(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_4_Tq0_SHIFT)) & VPU_JPEG_ENC_STATUS_4_Tq0_MASK)

#define VPU_JPEG_ENC_STATUS_4_V0_MASK            (0x1CU)
#define VPU_JPEG_ENC_STATUS_4_V0_SHIFT           (2U)
/*! V0 - Vertical Sampling 0 */
#define VPU_JPEG_ENC_STATUS_4_V0(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_4_V0_SHIFT)) & VPU_JPEG_ENC_STATUS_4_V0_MASK)

#define VPU_JPEG_ENC_STATUS_4_H0_MASK            (0xE0U)
#define VPU_JPEG_ENC_STATUS_4_H0_SHIFT           (5U)
/*! H0 - Horizontal Sampling 0 */
#define VPU_JPEG_ENC_STATUS_4_H0(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_4_H0_SHIFT)) & VPU_JPEG_ENC_STATUS_4_H0_MASK)

#define VPU_JPEG_ENC_STATUS_4_C0_MASK            (0xFF00U)
#define VPU_JPEG_ENC_STATUS_4_C0_SHIFT           (8U)
/*! C0 - Component 0 ID */
#define VPU_JPEG_ENC_STATUS_4_C0(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_4_C0_SHIFT)) & VPU_JPEG_ENC_STATUS_4_C0_MASK)
/*! @} */

/*! @name STATUS_5 - Status 5 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_5_Tq1_MASK           (0x3U)
#define VPU_JPEG_ENC_STATUS_5_Tq1_SHIFT          (0U)
/*! Tq1 - Table Quantization 1 ID */
#define VPU_JPEG_ENC_STATUS_5_Tq1(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_5_Tq1_SHIFT)) & VPU_JPEG_ENC_STATUS_5_Tq1_MASK)

#define VPU_JPEG_ENC_STATUS_5_V1_MASK            (0x1CU)
#define VPU_JPEG_ENC_STATUS_5_V1_SHIFT           (2U)
/*! V1 - Vertical Sampling 1 */
#define VPU_JPEG_ENC_STATUS_5_V1(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_5_V1_SHIFT)) & VPU_JPEG_ENC_STATUS_5_V1_MASK)

#define VPU_JPEG_ENC_STATUS_5_H1_MASK            (0xE0U)
#define VPU_JPEG_ENC_STATUS_5_H1_SHIFT           (5U)
/*! H1 - Horizontal Sampling 1 */
#define VPU_JPEG_ENC_STATUS_5_H1(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_5_H1_SHIFT)) & VPU_JPEG_ENC_STATUS_5_H1_MASK)

#define VPU_JPEG_ENC_STATUS_5_C1_MASK            (0xFF00U)
#define VPU_JPEG_ENC_STATUS_5_C1_SHIFT           (8U)
/*! C1 - Component 1 ID */
#define VPU_JPEG_ENC_STATUS_5_C1(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_5_C1_SHIFT)) & VPU_JPEG_ENC_STATUS_5_C1_MASK)
/*! @} */

/*! @name STATUS_6 - Status 6 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_6_Tq2_MASK           (0x3U)
#define VPU_JPEG_ENC_STATUS_6_Tq2_SHIFT          (0U)
/*! Tq2 - Table Quantization 2 ID */
#define VPU_JPEG_ENC_STATUS_6_Tq2(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_6_Tq2_SHIFT)) & VPU_JPEG_ENC_STATUS_6_Tq2_MASK)

#define VPU_JPEG_ENC_STATUS_6_V2_MASK            (0x1CU)
#define VPU_JPEG_ENC_STATUS_6_V2_SHIFT           (2U)
/*! V2 - Vertical Sampling 2 */
#define VPU_JPEG_ENC_STATUS_6_V2(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_6_V2_SHIFT)) & VPU_JPEG_ENC_STATUS_6_V2_MASK)

#define VPU_JPEG_ENC_STATUS_6_H2_MASK            (0xE0U)
#define VPU_JPEG_ENC_STATUS_6_H2_SHIFT           (5U)
/*! H2 - Horizontal Sampling 2 ID */
#define VPU_JPEG_ENC_STATUS_6_H2(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_6_H2_SHIFT)) & VPU_JPEG_ENC_STATUS_6_H2_MASK)

#define VPU_JPEG_ENC_STATUS_6_C2_MASK            (0xFF00U)
#define VPU_JPEG_ENC_STATUS_6_C2_SHIFT           (8U)
/*! C2 - Component 2 */
#define VPU_JPEG_ENC_STATUS_6_C2(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_6_C2_SHIFT)) & VPU_JPEG_ENC_STATUS_6_C2_MASK)
/*! @} */

/*! @name STATUS_7 - Status 7 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_7_Tq3_MASK           (0x3U)
#define VPU_JPEG_ENC_STATUS_7_Tq3_SHIFT          (0U)
/*! Tq3 - Table Quantization 3 ID */
#define VPU_JPEG_ENC_STATUS_7_Tq3(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_7_Tq3_SHIFT)) & VPU_JPEG_ENC_STATUS_7_Tq3_MASK)

#define VPU_JPEG_ENC_STATUS_7_V3_MASK            (0x1CU)
#define VPU_JPEG_ENC_STATUS_7_V3_SHIFT           (2U)
/*! V3 - Vertical Sampling 3 */
#define VPU_JPEG_ENC_STATUS_7_V3(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_7_V3_SHIFT)) & VPU_JPEG_ENC_STATUS_7_V3_MASK)

#define VPU_JPEG_ENC_STATUS_7_H3_MASK            (0xE0U)
#define VPU_JPEG_ENC_STATUS_7_H3_SHIFT           (5U)
/*! H3 - Horizontal Sampling 3 */
#define VPU_JPEG_ENC_STATUS_7_H3(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_7_H3_SHIFT)) & VPU_JPEG_ENC_STATUS_7_H3_MASK)

#define VPU_JPEG_ENC_STATUS_7_C3_MASK            (0xFF00U)
#define VPU_JPEG_ENC_STATUS_7_C3_SHIFT           (8U)
/*! C3 - Component 3 ID */
#define VPU_JPEG_ENC_STATUS_7_C3(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_7_C3_SHIFT)) & VPU_JPEG_ENC_STATUS_7_C3_MASK)
/*! @} */

/*! @name STATUS_8 - Status 8 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_8_Nf_MASK            (0xFFU)
#define VPU_JPEG_ENC_STATUS_8_Nf_SHIFT           (0U)
/*! Nf - Number of Components in Frame */
#define VPU_JPEG_ENC_STATUS_8_Nf(x)              (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_8_Nf_SHIFT)) & VPU_JPEG_ENC_STATUS_8_Nf_MASK)

#define VPU_JPEG_ENC_STATUS_8_QUALITY_MASK       (0xFF00U)
#define VPU_JPEG_ENC_STATUS_8_QUALITY_SHIFT      (8U)
/*! QUALITY - Quality Factor */
#define VPU_JPEG_ENC_STATUS_8_QUALITY(x)         (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_8_QUALITY_SHIFT)) & VPU_JPEG_ENC_STATUS_8_QUALITY_MASK)
/*! @} */

/*! @name STATUS_9 - Status 9 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_9_DRI_MASK           (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_9_DRI_SHIFT          (0U)
/*! DRI - Define Restart Interval */
#define VPU_JPEG_ENC_STATUS_9_DRI(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_9_DRI_SHIFT)) & VPU_JPEG_ENC_STATUS_9_DRI_MASK)
/*! @} */

/*! @name STATUS_10 - Status 10 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_10_Ns_MASK           (0xFU)
#define VPU_JPEG_ENC_STATUS_10_Ns_SHIFT          (0U)
/*! Ns - Number of Components in Scan */
#define VPU_JPEG_ENC_STATUS_10_Ns(x)             (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_10_Ns_SHIFT)) & VPU_JPEG_ENC_STATUS_10_Ns_MASK)

#define VPU_JPEG_ENC_STATUS_10_NBMCU_MASK        (0xF0U)
#define VPU_JPEG_ENC_STATUS_10_NBMCU_SHIFT       (4U)
/*! NBMCU - Number of Data Unit per MCU */
#define VPU_JPEG_ENC_STATUS_10_NBMCU(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_10_NBMCU_SHIFT)) & VPU_JPEG_ENC_STATUS_10_NBMCU_MASK)

#define VPU_JPEG_ENC_STATUS_10_Vmax_MASK         (0xF00U)
#define VPU_JPEG_ENC_STATUS_10_Vmax_SHIFT        (8U)
/*! Vmax - Maximum Vertical Sampling */
#define VPU_JPEG_ENC_STATUS_10_Vmax(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_10_Vmax_SHIFT)) & VPU_JPEG_ENC_STATUS_10_Vmax_MASK)

#define VPU_JPEG_ENC_STATUS_10_Hmax_MASK         (0xF000U)
#define VPU_JPEG_ENC_STATUS_10_Hmax_SHIFT        (12U)
/*! Hmax - Maximum Horizontal Sampling */
#define VPU_JPEG_ENC_STATUS_10_Hmax(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_10_Hmax_SHIFT)) & VPU_JPEG_ENC_STATUS_10_Hmax_MASK)
/*! @} */

/*! @name STATUS_11 - Status 11 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_11_VHS0_MASK         (0xFU)
#define VPU_JPEG_ENC_STATUS_11_VHS0_SHIFT        (0U)
/*! VHS0 - VHS0 */
#define VPU_JPEG_ENC_STATUS_11_VHS0(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_11_VHS0_SHIFT)) & VPU_JPEG_ENC_STATUS_11_VHS0_MASK)

#define VPU_JPEG_ENC_STATUS_11_VHS1_MASK         (0xF0U)
#define VPU_JPEG_ENC_STATUS_11_VHS1_SHIFT        (4U)
/*! VHS1 - VHS1 */
#define VPU_JPEG_ENC_STATUS_11_VHS1(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_11_VHS1_SHIFT)) & VPU_JPEG_ENC_STATUS_11_VHS1_MASK)

#define VPU_JPEG_ENC_STATUS_11_VHS2_MASK         (0xF00U)
#define VPU_JPEG_ENC_STATUS_11_VHS2_SHIFT        (8U)
/*! VHS2 - VHS2 */
#define VPU_JPEG_ENC_STATUS_11_VHS2(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_11_VHS2_SHIFT)) & VPU_JPEG_ENC_STATUS_11_VHS2_MASK)

#define VPU_JPEG_ENC_STATUS_11_VHS3_MASK         (0xF000U)
#define VPU_JPEG_ENC_STATUS_11_VHS3_SHIFT        (12U)
/*! VHS3 - VHS3 */
#define VPU_JPEG_ENC_STATUS_11_VHS3(x)           (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_11_VHS3_SHIFT)) & VPU_JPEG_ENC_STATUS_11_VHS3_MASK)
/*! @} */

/*! @name STATUS_12 - Status 12 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_12_COM_E_MASK        (0x1U)
#define VPU_JPEG_ENC_STATUS_12_COM_E_SHIFT       (0U)
/*! COM_E - Comment Error
 *  0b0..No error is detected in COM segment.
 *  0b1..An error is detected in COM segment.
 */
#define VPU_JPEG_ENC_STATUS_12_COM_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_COM_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_COM_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_APPn_E_MASK       (0x2U)
#define VPU_JPEG_ENC_STATUS_12_APPn_E_SHIFT      (1U)
/*! APPn_E - Application n Error
 *  0b0..No error is detected in APPn segment.
 *  0b1..An error is detected in APPn segment.
 */
#define VPU_JPEG_ENC_STATUS_12_APPn_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_APPn_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_APPn_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_DRI_E_MASK        (0x4U)
#define VPU_JPEG_ENC_STATUS_12_DRI_E_SHIFT       (2U)
/*! DRI_E - Define Restart Interval Error
 *  0b0..No error is detected in DRI segment.
 *  0b1..An error is detected in DRI segment.
 */
#define VPU_JPEG_ENC_STATUS_12_DRI_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_DRI_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_DRI_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_DNL_E_MASK        (0x8U)
#define VPU_JPEG_ENC_STATUS_12_DNL_E_SHIFT       (3U)
/*! DNL_E - Define Number of Lines Error
 *  0b0..No error is detected in DNL segment.
 *  0b1..An error is detected in DNL segment.
 */
#define VPU_JPEG_ENC_STATUS_12_DNL_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_DNL_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_DNL_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_DHT_E_MASK        (0x10U)
#define VPU_JPEG_ENC_STATUS_12_DHT_E_SHIFT       (4U)
/*! DHT_E - Define Huffman Table Error
 *  0b0..No error is detected in DHT segment.
 *  0b1..An error is detected in DHT segment.
 */
#define VPU_JPEG_ENC_STATUS_12_DHT_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_DHT_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_DHT_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_DQT_E_MASK        (0x20U)
#define VPU_JPEG_ENC_STATUS_12_DQT_E_SHIFT       (5U)
/*! DQT_E - Define Quantization Table Error
 *  0b0..No error is detected in DQT segment.
 *  0b1..An error is detected in DQT segment.
 */
#define VPU_JPEG_ENC_STATUS_12_DQT_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_DQT_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_DQT_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_SOS_E_MASK        (0x40U)
#define VPU_JPEG_ENC_STATUS_12_SOS_E_SHIFT       (6U)
/*! SOS_E - Start Of Scan Error
 *  0b0..No error is detected in SOS segment.
 *  0b1..An error is detected in SOS segment.
 */
#define VPU_JPEG_ENC_STATUS_12_SOS_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_SOS_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_SOS_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_SOF_E_MASK        (0x80U)
#define VPU_JPEG_ENC_STATUS_12_SOF_E_SHIFT       (7U)
/*! SOF_E - Sequence Of Frame 0 Error
 *  0b0..No error is detected in Sequence Of Frame 0 segment.
 *  0b1..An error is detected in Sequence Of Frame 0 segment.
 */
#define VPU_JPEG_ENC_STATUS_12_SOF_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_SOF_E_SHIFT)) & VPU_JPEG_ENC_STATUS_12_SOF_E_MASK)

#define VPU_JPEG_ENC_STATUS_12_CONFIGERROR_MASK  (0x100U)
#define VPU_JPEG_ENC_STATUS_12_CONFIGERROR_SHIFT (8U)
/*! CONFIGERROR - Configuration Error
 *  0b0..No configuration error is detected.
 *  0b1..A configuration error is detected.
 */
#define VPU_JPEG_ENC_STATUS_12_CONFIGERROR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_CONFIGERROR_SHIFT)) & VPU_JPEG_ENC_STATUS_12_CONFIGERROR_MASK)

#define VPU_JPEG_ENC_STATUS_12_JPEGIN_RDY_MASK   (0x200U)
#define VPU_JPEG_ENC_STATUS_12_JPEGIN_RDY_SHIFT  (9U)
/*! JPEGIN_RDY - JPEG Input Ready
 *  0b0..New JPEG stream input data is not ready to transfer.
 *  0b1..New JPEG stream input data is ready to transfer.
 */
#define VPU_JPEG_ENC_STATUS_12_JPEGIN_RDY(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_JPEGIN_RDY_SHIFT)) & VPU_JPEG_ENC_STATUS_12_JPEGIN_RDY_MASK)

#define VPU_JPEG_ENC_STATUS_12_PIXELIN_RDY_MASK  (0x400U)
#define VPU_JPEG_ENC_STATUS_12_PIXELIN_RDY_SHIFT (10U)
/*! PIXELIN_RDY - Pixel Input Ready
 *  0b0..New pixel input data is not ready to transfer.
 *  0b1..New pixel input data is ready to transfer.
 */
#define VPU_JPEG_ENC_STATUS_12_PIXELIN_RDY(x)    (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_PIXELIN_RDY_SHIFT)) & VPU_JPEG_ENC_STATUS_12_PIXELIN_RDY_MASK)

#define VPU_JPEG_ENC_STATUS_12_SCANACTIVE_MASK   (0x800U)
#define VPU_JPEG_ENC_STATUS_12_SCANACTIVE_SHIFT  (11U)
/*! SCANACTIVE - Scan Active
 *  0b0..The core does not encode scan data.
 *  0b1..The core encodes scan data.
 */
#define VPU_JPEG_ENC_STATUS_12_SCANACTIVE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_12_SCANACTIVE_SHIFT)) & VPU_JPEG_ENC_STATUS_12_SCANACTIVE_MASK)
/*! @} */

/*! @name STATUS_13 - Status 13 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_13_CFG_MODE_MASK     (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_13_CFG_MODE_SHIFT    (0U)
/*! CFG_MODE - Configuration Mode */
#define VPU_JPEG_ENC_STATUS_13_CFG_MODE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_13_CFG_MODE_SHIFT)) & VPU_JPEG_ENC_STATUS_13_CFG_MODE_MASK)
/*! @} */

/*! @name STATUS_14 - Status 14 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_14_RC_REGS0_MASK     (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_14_RC_REGS0_SHIFT    (0U)
/*! RC_REGS0 - Rate Control Register Set 0 */
#define VPU_JPEG_ENC_STATUS_14_RC_REGS0(x)       (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_14_RC_REGS0_SHIFT)) & VPU_JPEG_ENC_STATUS_14_RC_REGS0_MASK)
/*! @} */

/*! @name STATUS_15 - Status 15 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_15_RC_REGS1_MASK     (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_15_RC_REGS1_SHIFT    (0U)
/*! RC_REGS1 - Rate Control Register Set 1 */
#define VPU_JPEG_ENC_STATUS_15_RC_REGS1(x)       (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_15_RC_REGS1_SHIFT)) & VPU_JPEG_ENC_STATUS_15_RC_REGS1_MASK)
/*! @} */

/*! @name STATUS_16 - Status 16 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_16_NOMFRSIZE_LO_MASK (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_16_NOMFRSIZE_LO_SHIFT (0U)
/*! NOMFRSIZE_LO - Nominal Frame Size Low */
#define VPU_JPEG_ENC_STATUS_16_NOMFRSIZE_LO(x)   (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_16_NOMFRSIZE_LO_SHIFT)) & VPU_JPEG_ENC_STATUS_16_NOMFRSIZE_LO_MASK)
/*! @} */

/*! @name STATUS_17 - Status 17 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_17_NOMFRSIZE_HI_MASK (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_17_NOMFRSIZE_HI_SHIFT (0U)
/*! NOMFRSIZE_HI - Nominal Frame Size High */
#define VPU_JPEG_ENC_STATUS_17_NOMFRSIZE_HI(x)   (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_17_NOMFRSIZE_HI_SHIFT)) & VPU_JPEG_ENC_STATUS_17_NOMFRSIZE_HI_MASK)
/*! @} */

/*! @name STATUS_18 - Status 18 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_18_OFBSIZE_LO_MASK   (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_18_OFBSIZE_LO_SHIFT  (0U)
/*! OFBSIZE_LO - FIFO Buffer Size Low */
#define VPU_JPEG_ENC_STATUS_18_OFBSIZE_LO(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_18_OFBSIZE_LO_SHIFT)) & VPU_JPEG_ENC_STATUS_18_OFBSIZE_LO_MASK)
/*! @} */

/*! @name STATUS_19 - Status 19 */
/*! @{ */

#define VPU_JPEG_ENC_STATUS_19_OFBSIZE_HI_MASK   (0xFFFFU)
#define VPU_JPEG_ENC_STATUS_19_OFBSIZE_HI_SHIFT  (0U)
/*! OFBSIZE_HI - FIFO Buffer Size High */
#define VPU_JPEG_ENC_STATUS_19_OFBSIZE_HI(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_STATUS_19_OFBSIZE_HI_SHIFT)) & VPU_JPEG_ENC_STATUS_19_OFBSIZE_HI_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_JPEG_ENC_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_JPEG_ENC_Peripheral_Access_Layer */


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


#endif  /* VPU_JPEG_ENC_H_ */

