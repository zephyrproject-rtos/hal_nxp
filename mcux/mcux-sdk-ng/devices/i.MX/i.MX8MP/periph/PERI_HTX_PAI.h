/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HTX_PAI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HTX_PAI.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HTX_PAI
 *
 * CMSIS Peripheral Access Layer for HTX_PAI
 */

#if !defined(PERI_HTX_PAI_H_)
#define PERI_HTX_PAI_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- HTX_PAI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HTX_PAI_Peripheral_Access_Layer HTX_PAI Peripheral Access Layer
 * @{
 */

/** HTX_PAI - Register Layout Typedef */
typedef struct {
  __IO uint32_t HTX_PAI_CTRL;                      /**< HTX PAI Control, offset: 0x0 */
  __IO uint32_t HTX_PAI_CTRL_EXT;                  /**< HTX PAI Control Extended, offset: 0x4 */
  __IO uint32_t HTX_PAI_FIELD_CTRL;                /**< HTX PAI Field Control, offset: 0x8 */
  __I  uint32_t HTX_PAI_STAT;                      /**< HTX PAI Status, offset: 0xC */
  __IO uint32_t HTX_PAI_IRQ_NOMASK;                /**< HTX PAI Nonmasked Interrupt Flags, offset: 0x10 */
  __IO uint32_t HTX_PAI_IRQ_MASKED;                /**< HTX PAI Masked Interrupt Flags, offset: 0x14 */
  __IO uint32_t HTX_PAI_IRQ_MASK;                  /**< HTX PAI IRQ Masks, offset: 0x18 */
} HTX_PAI_Type;

/* ----------------------------------------------------------------------------
   -- HTX_PAI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HTX_PAI_Register_Masks HTX_PAI Register Masks
 * @{
 */

/*! @name HTX_PAI_CTRL - HTX PAI Control */
/*! @{ */

#define HTX_PAI_HTX_PAI_CTRL_ENABLE_MASK         (0x1U)
#define HTX_PAI_HTX_PAI_CTRL_ENABLE_SHIFT        (0U)
/*! ENABLE - HTX PAI Enable */
#define HTX_PAI_HTX_PAI_CTRL_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_ENABLE_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_ENABLE_MASK)
/*! @} */

/*! @name HTX_PAI_CTRL_EXT - HTX PAI Control Extended */
/*! @{ */

#define HTX_PAI_HTX_PAI_CTRL_EXT_SOURCE_MASK     (0x1U)
#define HTX_PAI_HTX_PAI_CTRL_EXT_SOURCE_SHIFT    (0U)
/*! SOURCE - HTX PAI Source Select
 *  0b0..Normal operation. Data input from the audio subsystem.
 *  0b1..Low latency bypass mode. Data input from RASFD.
 */
#define HTX_PAI_HTX_PAI_CTRL_EXT_SOURCE(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_EXT_SOURCE_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_EXT_SOURCE_MASK)

#define HTX_PAI_HTX_PAI_CTRL_EXT_NUM_CH_MASK     (0x700U)
#define HTX_PAI_HTX_PAI_CTRL_EXT_NUM_CH_SHIFT    (8U)
/*! NUM_CH - Number of Channels Per Packet
 *  0b000..There is 1 channel per packet.
 *  0b001..There are 2 channels per packet.
 *  0b010..There are 3 channels per packet.
 *  0b011..There are 4 channels per packet.
 *  0b100..There are 5 channels per packet.
 *  0b101..There are 6 channels per packet.
 *  0b110..There are 7 channels per packet.
 *  0b111..There are 8 channels per packet.
 */
#define HTX_PAI_HTX_PAI_CTRL_EXT_NUM_CH(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_EXT_NUM_CH_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_EXT_NUM_CH_MASK)

#define HTX_PAI_HTX_PAI_CTRL_EXT_B_EXT_MASK      (0x800U)
#define HTX_PAI_HTX_PAI_CTRL_EXT_B_EXT_SHIFT     (11U)
/*! B_EXT - B-Field Extension
 *  0b0..Use default B-Preamble timing (from selected input source).
 *  0b1..Extend B-Preamble timing to ensure it is set for at least 2 cycles.
 */
#define HTX_PAI_HTX_PAI_CTRL_EXT_B_EXT(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_EXT_B_EXT_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_EXT_B_EXT_MASK)

#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_LOW_MASK   (0xFF0000U)
#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_LOW_SHIFT  (16U)
/*! WTMK_LOW - HTX PAI Watermark Low */
#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_LOW(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_LOW_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_LOW_MASK)

#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_HIGH_MASK  (0xFF000000U)
#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_HIGH_SHIFT (24U)
/*! WTMK_HIGH - HTX PAI Watermark High */
#define HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_HIGH(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_HIGH_SHIFT)) & HTX_PAI_HTX_PAI_CTRL_EXT_WTMK_HIGH_MASK)
/*! @} */

/*! @name HTX_PAI_FIELD_CTRL - HTX PAI Field Control */
/*! @{ */

#define HTX_PAI_HTX_PAI_FIELD_CTRL_P_SEL_MASK    (0x1FU)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_P_SEL_SHIFT   (0U)
/*! P_SEL - IEC60958 P Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_P_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_P_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_P_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_C_SEL_MASK    (0x3E0U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_C_SEL_SHIFT   (5U)
/*! C_SEL - IEC60958 C Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_C_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_C_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_C_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_U_SEL_MASK    (0x7C00U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_U_SEL_SHIFT   (10U)
/*! U_SEL - IEC60958 U Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_U_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_U_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_U_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_V_SEL_MASK    (0xF8000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_V_SEL_SHIFT   (15U)
/*! V_SEL - IEC60958 V Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_V_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_V_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_V_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_D_SEL_MASK    (0xF00000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_D_SEL_SHIFT   (20U)
/*! D_SEL - IEC60958 Data Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_D_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_D_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_D_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_PRE_SEL_MASK  (0x1F000000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_PRE_SEL_SHIFT (24U)
/*! PRE_SEL - IEC60958 Preamble Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_PRE_SEL(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_PRE_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_PRE_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_END_SEL_MASK  (0x20000000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_END_SEL_SHIFT (29U)
/*! END_SEL - Endianness Select */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_END_SEL(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_END_SEL_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_END_SEL_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_PARITY_EN_MASK (0x40000000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_PARITY_EN_SHIFT (30U)
/*! PARITY_EN - Parity Enable */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_PARITY_EN(x)  (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_PARITY_EN_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_PARITY_EN_MASK)

#define HTX_PAI_HTX_PAI_FIELD_CTRL_B_FILT_MASK   (0x80000000U)
#define HTX_PAI_HTX_PAI_FIELD_CTRL_B_FILT_SHIFT  (31U)
/*! B_FILT - B-Detect Filter */
#define HTX_PAI_HTX_PAI_FIELD_CTRL_B_FILT(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_FIELD_CTRL_B_FILT_SHIFT)) & HTX_PAI_HTX_PAI_FIELD_CTRL_B_FILT_MASK)
/*! @} */

/*! @name HTX_PAI_STAT - HTX PAI Status */
/*! @{ */

#define HTX_PAI_HTX_PAI_STAT_WM_LOW_MASK         (0x1U)
#define HTX_PAI_HTX_PAI_STAT_WM_LOW_SHIFT        (0U)
/*! WM_LOW - Watermark Low Flag */
#define HTX_PAI_HTX_PAI_STAT_WM_LOW(x)           (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_STAT_WM_LOW_SHIFT)) & HTX_PAI_HTX_PAI_STAT_WM_LOW_MASK)

#define HTX_PAI_HTX_PAI_STAT_WM_HIGH_MASK        (0x2U)
#define HTX_PAI_HTX_PAI_STAT_WM_HIGH_SHIFT       (1U)
/*! WM_HIGH - Watermark High Flag */
#define HTX_PAI_HTX_PAI_STAT_WM_HIGH(x)          (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_STAT_WM_HIGH_SHIFT)) & HTX_PAI_HTX_PAI_STAT_WM_HIGH_MASK)
/*! @} */

/*! @name HTX_PAI_IRQ_NOMASK - HTX PAI Nonmasked Interrupt Flags */
/*! @{ */

#define HTX_PAI_HTX_PAI_IRQ_NOMASK_OVF_MASK      (0x1U)
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_OVF_SHIFT     (0U)
/*! OVF - HTX PAI Buffer Overflow */
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_OVF(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_NOMASK_OVF_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_NOMASK_OVF_MASK)

#define HTX_PAI_HTX_PAI_IRQ_NOMASK_UND_MASK      (0x2U)
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_UND_SHIFT     (1U)
/*! UND - HTX PAI Buffer Underflow */
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_UND(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_NOMASK_UND_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_NOMASK_UND_MASK)

#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_LOW_IRQ_MASK (0x4U)
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_LOW_IRQ_SHIFT (2U)
/*! WM_LOW_IRQ - Watermark Low IRQ */
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_LOW_IRQ(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_LOW_IRQ_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_LOW_IRQ_MASK)

#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_HIGH_IRQ_MASK (0x8U)
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_HIGH_IRQ_SHIFT (3U)
/*! WM_HIGH_IRQ - Watermark High IRQ */
#define HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_HIGH_IRQ(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_HIGH_IRQ_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_NOMASK_WM_HIGH_IRQ_MASK)
/*! @} */

/*! @name HTX_PAI_IRQ_MASKED - HTX PAI Masked Interrupt Flags */
/*! @{ */

#define HTX_PAI_HTX_PAI_IRQ_MASKED_OVF_MASK      (0x1U)
#define HTX_PAI_HTX_PAI_IRQ_MASKED_OVF_SHIFT     (0U)
/*! OVF - HTX PAI Buffer Overflow */
#define HTX_PAI_HTX_PAI_IRQ_MASKED_OVF(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASKED_OVF_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASKED_OVF_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASKED_UND_MASK      (0x2U)
#define HTX_PAI_HTX_PAI_IRQ_MASKED_UND_SHIFT     (1U)
/*! UND - HTX PAI Buffer Underflow */
#define HTX_PAI_HTX_PAI_IRQ_MASKED_UND(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASKED_UND_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASKED_UND_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_LOW_IRQ_MASK (0x4U)
#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_LOW_IRQ_SHIFT (2U)
/*! WM_LOW_IRQ - Watermark Low IRQ Masked */
#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_LOW_IRQ(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASKED_WM_LOW_IRQ_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASKED_WM_LOW_IRQ_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_HIGH_IRQ_MASK (0x8U)
#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_HIGH_IRQ_SHIFT (3U)
/*! WM_HIGH_IRQ - Watermark High IRQ Masked */
#define HTX_PAI_HTX_PAI_IRQ_MASKED_WM_HIGH_IRQ(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASKED_WM_HIGH_IRQ_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASKED_WM_HIGH_IRQ_MASK)
/*! @} */

/*! @name HTX_PAI_IRQ_MASK - HTX PAI IRQ Masks */
/*! @{ */

#define HTX_PAI_HTX_PAI_IRQ_MASK_OVF_MASK_MASK   (0x1U)
#define HTX_PAI_HTX_PAI_IRQ_MASK_OVF_MASK_SHIFT  (0U)
/*! OVF_MASK - HTX PAI Buffer Overflow Mask */
#define HTX_PAI_HTX_PAI_IRQ_MASK_OVF_MASK(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASK_OVF_MASK_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASK_OVF_MASK_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASK_UND_MASK_MASK   (0x2U)
#define HTX_PAI_HTX_PAI_IRQ_MASK_UND_MASK_SHIFT  (1U)
/*! UND_MASK - HTX PAI Buffer Underflow Mask */
#define HTX_PAI_HTX_PAI_IRQ_MASK_UND_MASK(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASK_UND_MASK_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASK_UND_MASK_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_LOW_IRQ_MASK_MASK (0x4U)
#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_LOW_IRQ_MASK_SHIFT (2U)
/*! WM_LOW_IRQ_MASK - Watermark Low IRQ Mask */
#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_LOW_IRQ_MASK(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASK_WM_LOW_IRQ_MASK_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASK_WM_LOW_IRQ_MASK_MASK)

#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_HIGH_IRQ_MASK_MASK (0x8U)
#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_HIGH_IRQ_MASK_SHIFT (3U)
/*! WM_HIGH_IRQ_MASK - Watermark High IRQ Mask */
#define HTX_PAI_HTX_PAI_IRQ_MASK_WM_HIGH_IRQ_MASK(x) (((uint32_t)(((uint32_t)(x)) << HTX_PAI_HTX_PAI_IRQ_MASK_WM_HIGH_IRQ_MASK_SHIFT)) & HTX_PAI_HTX_PAI_IRQ_MASK_WM_HIGH_IRQ_MASK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HTX_PAI_Register_Masks */


/*!
 * @}
 */ /* end of group HTX_PAI_Peripheral_Access_Layer */


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


#endif  /* PERI_HTX_PAI_H_ */

