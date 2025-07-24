/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for BCH
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_BCH.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BCH
 *
 * CMSIS Peripheral Access Layer for BCH
 */

#if !defined(PERI_BCH_H_)
#define PERI_BCH_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- BCH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BCH_Peripheral_Access_Layer BCH Peripheral Access Layer
 * @{
 */

/** BCH - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Hardware BCH ECC Accelerator Control Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< Hardware BCH ECC Accelerator Control Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< Hardware BCH ECC Accelerator Control Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< Hardware BCH ECC Accelerator Control Register, offset: 0xC */
  __I  uint32_t STATUS0;                           /**< Hardware ECC Accelerator Status Register 0, offset: 0x10 */
       uint8_t RESERVED_0[12];
  __IO uint32_t MODE;                              /**< Hardware ECC Accelerator Mode Register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t ENCODEPTR;                         /**< Hardware BCH ECC Loopback Encode Buffer Register, offset: 0x30 */
       uint8_t RESERVED_2[12];
  __IO uint32_t DATAPTR;                           /**< Hardware BCH ECC Loopback Data Buffer Register, offset: 0x40 */
       uint8_t RESERVED_3[12];
  __IO uint32_t METAPTR;                           /**< Hardware BCH ECC Loopback Metadata Buffer Register, offset: 0x50 */
       uint8_t RESERVED_4[28];
  __IO uint32_t LAYOUTSELECT;                      /**< Hardware ECC Accelerator Layout Select Register, offset: 0x70 */
       uint8_t RESERVED_5[12];
  __IO uint32_t FLASH0LAYOUT0;                     /**< Hardware BCH ECC Flash 0 Layout 0 Register, offset: 0x80 */
       uint8_t RESERVED_6[12];
  __IO uint32_t FLASH0LAYOUT1;                     /**< Hardware BCH ECC Flash 0 Layout 1 Register, offset: 0x90 */
       uint8_t RESERVED_7[12];
  __IO uint32_t FLASH1LAYOUT0;                     /**< Hardware BCH ECC Flash 1 Layout 0 Register, offset: 0xA0 */
       uint8_t RESERVED_8[12];
  __IO uint32_t FLASH1LAYOUT1;                     /**< Hardware BCH ECC Flash 1 Layout 1 Register, offset: 0xB0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t FLASH2LAYOUT0;                     /**< Hardware BCH ECC Flash 2 Layout 0 Register, offset: 0xC0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t FLASH2LAYOUT1;                     /**< Hardware BCH ECC Flash 2 Layout 1 Register, offset: 0xD0 */
       uint8_t RESERVED_11[12];
  __IO uint32_t FLASH3LAYOUT0;                     /**< Hardware BCH ECC Flash 3 Layout 0 Register, offset: 0xE0 */
       uint8_t RESERVED_12[12];
  __IO uint32_t FLASH3LAYOUT1;                     /**< Hardware BCH ECC Flash 3 Layout 1 Register, offset: 0xF0 */
       uint8_t RESERVED_13[12];
  __IO uint32_t DEBUG0;                            /**< Hardware BCH ECC Debug Register0, offset: 0x100 */
  __IO uint32_t DEBUG0_SET;                        /**< Hardware BCH ECC Debug Register0, offset: 0x104 */
  __IO uint32_t DEBUG0_CLR;                        /**< Hardware BCH ECC Debug Register0, offset: 0x108 */
  __IO uint32_t DEBUG0_TOG;                        /**< Hardware BCH ECC Debug Register0, offset: 0x10C */
  __I  uint32_t DBGKESREAD;                        /**< KES Debug Read Register, offset: 0x110 */
       uint8_t RESERVED_14[12];
  __I  uint32_t DBGCSFEREAD;                       /**< Chien Search Debug Read Register, offset: 0x120 */
       uint8_t RESERVED_15[12];
  __I  uint32_t DBGSYNDGENREAD;                    /**< Syndrome Generator Debug Read Register, offset: 0x130 */
       uint8_t RESERVED_16[12];
  __I  uint32_t DBGAHBMREAD;                       /**< Bus Master and ECC Controller Debug Read Register, offset: 0x140 */
       uint8_t RESERVED_17[12];
  __I  uint32_t BLOCKNAME;                         /**< Block Name Register, offset: 0x150 */
       uint8_t RESERVED_18[12];
  __I  uint32_t VERSION;                           /**< BCH Version Register, offset: 0x160 */
       uint8_t RESERVED_19[12];
  __IO uint32_t DEBUG1;                            /**< Hardware BCH ECC Debug Register 1, offset: 0x170 */
} BCH_Type;

/* ----------------------------------------------------------------------------
   -- BCH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup BCH_Register_Masks BCH Register Masks
 * @{
 */

/*! @name CTRL - Hardware BCH ECC Accelerator Control Register */
/*! @{ */

#define BCH_CTRL_COMPLETE_IRQ_MASK               (0x1U)
#define BCH_CTRL_COMPLETE_IRQ_SHIFT              (0U)
#define BCH_CTRL_COMPLETE_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_COMPLETE_IRQ_SHIFT)) & BCH_CTRL_COMPLETE_IRQ_MASK)

#define BCH_CTRL_RSVD0_MASK                      (0x2U)
#define BCH_CTRL_RSVD0_SHIFT                     (1U)
/*! RSVD0 - This field is reserved. */
#define BCH_CTRL_RSVD0(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD0_SHIFT)) & BCH_CTRL_RSVD0_MASK)

#define BCH_CTRL_DEBUG_STALL_IRQ_MASK            (0x4U)
#define BCH_CTRL_DEBUG_STALL_IRQ_SHIFT           (2U)
#define BCH_CTRL_DEBUG_STALL_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_DEBUG_STALL_IRQ_SHIFT)) & BCH_CTRL_DEBUG_STALL_IRQ_MASK)

#define BCH_CTRL_BM_ERROR_IRQ_MASK               (0x8U)
#define BCH_CTRL_BM_ERROR_IRQ_SHIFT              (3U)
#define BCH_CTRL_BM_ERROR_IRQ(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_BM_ERROR_IRQ_SHIFT)) & BCH_CTRL_BM_ERROR_IRQ_MASK)

#define BCH_CTRL_RSVD1_MASK                      (0xF0U)
#define BCH_CTRL_RSVD1_SHIFT                     (4U)
/*! RSVD1 - This field is reserved. */
#define BCH_CTRL_RSVD1(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD1_SHIFT)) & BCH_CTRL_RSVD1_MASK)

#define BCH_CTRL_COMPLETE_IRQ_EN_MASK            (0x100U)
#define BCH_CTRL_COMPLETE_IRQ_EN_SHIFT           (8U)
#define BCH_CTRL_COMPLETE_IRQ_EN(x)              (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_COMPLETE_IRQ_EN_SHIFT)) & BCH_CTRL_COMPLETE_IRQ_EN_MASK)

#define BCH_CTRL_RSVD2_MASK                      (0x200U)
#define BCH_CTRL_RSVD2_SHIFT                     (9U)
/*! RSVD2 - This field is reserved. */
#define BCH_CTRL_RSVD2(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD2_SHIFT)) & BCH_CTRL_RSVD2_MASK)

#define BCH_CTRL_DEBUG_STALL_IRQ_EN_MASK         (0x400U)
#define BCH_CTRL_DEBUG_STALL_IRQ_EN_SHIFT        (10U)
#define BCH_CTRL_DEBUG_STALL_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_DEBUG_STALL_IRQ_EN_SHIFT)) & BCH_CTRL_DEBUG_STALL_IRQ_EN_MASK)

#define BCH_CTRL_RSVD3_MASK                      (0xF800U)
#define BCH_CTRL_RSVD3_SHIFT                     (11U)
/*! RSVD3 - This field is reserved. */
#define BCH_CTRL_RSVD3(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD3_SHIFT)) & BCH_CTRL_RSVD3_MASK)

#define BCH_CTRL_M2M_ENABLE_MASK                 (0x10000U)
#define BCH_CTRL_M2M_ENABLE_SHIFT                (16U)
#define BCH_CTRL_M2M_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_M2M_ENABLE_SHIFT)) & BCH_CTRL_M2M_ENABLE_MASK)

#define BCH_CTRL_M2M_ENCODE_MASK                 (0x20000U)
#define BCH_CTRL_M2M_ENCODE_SHIFT                (17U)
#define BCH_CTRL_M2M_ENCODE(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_M2M_ENCODE_SHIFT)) & BCH_CTRL_M2M_ENCODE_MASK)

#define BCH_CTRL_M2M_LAYOUT_MASK                 (0xC0000U)
#define BCH_CTRL_M2M_LAYOUT_SHIFT                (18U)
#define BCH_CTRL_M2M_LAYOUT(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_M2M_LAYOUT_SHIFT)) & BCH_CTRL_M2M_LAYOUT_MASK)

#define BCH_CTRL_RSVD4_MASK                      (0x300000U)
#define BCH_CTRL_RSVD4_SHIFT                     (20U)
/*! RSVD4 - This field is reserved. */
#define BCH_CTRL_RSVD4(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD4_SHIFT)) & BCH_CTRL_RSVD4_MASK)

#define BCH_CTRL_DEBUGSYNDROME_MASK              (0x400000U)
#define BCH_CTRL_DEBUGSYNDROME_SHIFT             (22U)
#define BCH_CTRL_DEBUGSYNDROME(x)                (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_DEBUGSYNDROME_SHIFT)) & BCH_CTRL_DEBUGSYNDROME_MASK)

#define BCH_CTRL_RSVD5_MASK                      (0x3F800000U)
#define BCH_CTRL_RSVD5_SHIFT                     (23U)
/*! RSVD5 - This field is reserved. */
#define BCH_CTRL_RSVD5(x)                        (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_RSVD5_SHIFT)) & BCH_CTRL_RSVD5_MASK)

#define BCH_CTRL_CLKGATE_MASK                    (0x40000000U)
#define BCH_CTRL_CLKGATE_SHIFT                   (30U)
/*! CLKGATE
 *  0b0..Allow BCH to operate normally.
 *  0b1..Do not clock BCH gates in order to minimize power consumption.
 */
#define BCH_CTRL_CLKGATE(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLKGATE_SHIFT)) & BCH_CTRL_CLKGATE_MASK)

#define BCH_CTRL_SFTRST_MASK                     (0x80000000U)
#define BCH_CTRL_SFTRST_SHIFT                    (31U)
/*! SFTRST
 *  0b0..Allow BCH to operate normally.
 *  0b1..Hold BCH in reset.
 */
#define BCH_CTRL_SFTRST(x)                       (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SFTRST_SHIFT)) & BCH_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - Hardware BCH ECC Accelerator Control Register */
/*! @{ */

#define BCH_CTRL_SET_COMPLETE_IRQ_MASK           (0x1U)
#define BCH_CTRL_SET_COMPLETE_IRQ_SHIFT          (0U)
#define BCH_CTRL_SET_COMPLETE_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_COMPLETE_IRQ_SHIFT)) & BCH_CTRL_SET_COMPLETE_IRQ_MASK)

#define BCH_CTRL_SET_RSVD0_MASK                  (0x2U)
#define BCH_CTRL_SET_RSVD0_SHIFT                 (1U)
/*! RSVD0 - This field is reserved. */
#define BCH_CTRL_SET_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD0_SHIFT)) & BCH_CTRL_SET_RSVD0_MASK)

#define BCH_CTRL_SET_DEBUG_STALL_IRQ_MASK        (0x4U)
#define BCH_CTRL_SET_DEBUG_STALL_IRQ_SHIFT       (2U)
#define BCH_CTRL_SET_DEBUG_STALL_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_DEBUG_STALL_IRQ_SHIFT)) & BCH_CTRL_SET_DEBUG_STALL_IRQ_MASK)

#define BCH_CTRL_SET_BM_ERROR_IRQ_MASK           (0x8U)
#define BCH_CTRL_SET_BM_ERROR_IRQ_SHIFT          (3U)
#define BCH_CTRL_SET_BM_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_BM_ERROR_IRQ_SHIFT)) & BCH_CTRL_SET_BM_ERROR_IRQ_MASK)

#define BCH_CTRL_SET_RSVD1_MASK                  (0xF0U)
#define BCH_CTRL_SET_RSVD1_SHIFT                 (4U)
/*! RSVD1 - This field is reserved. */
#define BCH_CTRL_SET_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD1_SHIFT)) & BCH_CTRL_SET_RSVD1_MASK)

#define BCH_CTRL_SET_COMPLETE_IRQ_EN_MASK        (0x100U)
#define BCH_CTRL_SET_COMPLETE_IRQ_EN_SHIFT       (8U)
#define BCH_CTRL_SET_COMPLETE_IRQ_EN(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_COMPLETE_IRQ_EN_SHIFT)) & BCH_CTRL_SET_COMPLETE_IRQ_EN_MASK)

#define BCH_CTRL_SET_RSVD2_MASK                  (0x200U)
#define BCH_CTRL_SET_RSVD2_SHIFT                 (9U)
/*! RSVD2 - This field is reserved. */
#define BCH_CTRL_SET_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD2_SHIFT)) & BCH_CTRL_SET_RSVD2_MASK)

#define BCH_CTRL_SET_DEBUG_STALL_IRQ_EN_MASK     (0x400U)
#define BCH_CTRL_SET_DEBUG_STALL_IRQ_EN_SHIFT    (10U)
#define BCH_CTRL_SET_DEBUG_STALL_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_DEBUG_STALL_IRQ_EN_SHIFT)) & BCH_CTRL_SET_DEBUG_STALL_IRQ_EN_MASK)

#define BCH_CTRL_SET_RSVD3_MASK                  (0xF800U)
#define BCH_CTRL_SET_RSVD3_SHIFT                 (11U)
/*! RSVD3 - This field is reserved. */
#define BCH_CTRL_SET_RSVD3(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD3_SHIFT)) & BCH_CTRL_SET_RSVD3_MASK)

#define BCH_CTRL_SET_M2M_ENABLE_MASK             (0x10000U)
#define BCH_CTRL_SET_M2M_ENABLE_SHIFT            (16U)
#define BCH_CTRL_SET_M2M_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_M2M_ENABLE_SHIFT)) & BCH_CTRL_SET_M2M_ENABLE_MASK)

#define BCH_CTRL_SET_M2M_ENCODE_MASK             (0x20000U)
#define BCH_CTRL_SET_M2M_ENCODE_SHIFT            (17U)
#define BCH_CTRL_SET_M2M_ENCODE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_M2M_ENCODE_SHIFT)) & BCH_CTRL_SET_M2M_ENCODE_MASK)

#define BCH_CTRL_SET_M2M_LAYOUT_MASK             (0xC0000U)
#define BCH_CTRL_SET_M2M_LAYOUT_SHIFT            (18U)
#define BCH_CTRL_SET_M2M_LAYOUT(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_M2M_LAYOUT_SHIFT)) & BCH_CTRL_SET_M2M_LAYOUT_MASK)

#define BCH_CTRL_SET_RSVD4_MASK                  (0x300000U)
#define BCH_CTRL_SET_RSVD4_SHIFT                 (20U)
/*! RSVD4 - This field is reserved. */
#define BCH_CTRL_SET_RSVD4(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD4_SHIFT)) & BCH_CTRL_SET_RSVD4_MASK)

#define BCH_CTRL_SET_DEBUGSYNDROME_MASK          (0x400000U)
#define BCH_CTRL_SET_DEBUGSYNDROME_SHIFT         (22U)
#define BCH_CTRL_SET_DEBUGSYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_DEBUGSYNDROME_SHIFT)) & BCH_CTRL_SET_DEBUGSYNDROME_MASK)

#define BCH_CTRL_SET_RSVD5_MASK                  (0x3F800000U)
#define BCH_CTRL_SET_RSVD5_SHIFT                 (23U)
/*! RSVD5 - This field is reserved. */
#define BCH_CTRL_SET_RSVD5(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_RSVD5_SHIFT)) & BCH_CTRL_SET_RSVD5_MASK)

#define BCH_CTRL_SET_CLKGATE_MASK                (0x40000000U)
#define BCH_CTRL_SET_CLKGATE_SHIFT               (30U)
/*! CLKGATE
 *  0b0..Allow BCH to operate normally.
 *  0b1..Do not clock BCH gates in order to minimize power consumption.
 */
#define BCH_CTRL_SET_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_CLKGATE_SHIFT)) & BCH_CTRL_SET_CLKGATE_MASK)

#define BCH_CTRL_SET_SFTRST_MASK                 (0x80000000U)
#define BCH_CTRL_SET_SFTRST_SHIFT                (31U)
/*! SFTRST
 *  0b0..Allow BCH to operate normally.
 *  0b1..Hold BCH in reset.
 */
#define BCH_CTRL_SET_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_SET_SFTRST_SHIFT)) & BCH_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - Hardware BCH ECC Accelerator Control Register */
/*! @{ */

#define BCH_CTRL_CLR_COMPLETE_IRQ_MASK           (0x1U)
#define BCH_CTRL_CLR_COMPLETE_IRQ_SHIFT          (0U)
#define BCH_CTRL_CLR_COMPLETE_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_COMPLETE_IRQ_SHIFT)) & BCH_CTRL_CLR_COMPLETE_IRQ_MASK)

#define BCH_CTRL_CLR_RSVD0_MASK                  (0x2U)
#define BCH_CTRL_CLR_RSVD0_SHIFT                 (1U)
/*! RSVD0 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD0_SHIFT)) & BCH_CTRL_CLR_RSVD0_MASK)

#define BCH_CTRL_CLR_DEBUG_STALL_IRQ_MASK        (0x4U)
#define BCH_CTRL_CLR_DEBUG_STALL_IRQ_SHIFT       (2U)
#define BCH_CTRL_CLR_DEBUG_STALL_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_DEBUG_STALL_IRQ_SHIFT)) & BCH_CTRL_CLR_DEBUG_STALL_IRQ_MASK)

#define BCH_CTRL_CLR_BM_ERROR_IRQ_MASK           (0x8U)
#define BCH_CTRL_CLR_BM_ERROR_IRQ_SHIFT          (3U)
#define BCH_CTRL_CLR_BM_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_BM_ERROR_IRQ_SHIFT)) & BCH_CTRL_CLR_BM_ERROR_IRQ_MASK)

#define BCH_CTRL_CLR_RSVD1_MASK                  (0xF0U)
#define BCH_CTRL_CLR_RSVD1_SHIFT                 (4U)
/*! RSVD1 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD1_SHIFT)) & BCH_CTRL_CLR_RSVD1_MASK)

#define BCH_CTRL_CLR_COMPLETE_IRQ_EN_MASK        (0x100U)
#define BCH_CTRL_CLR_COMPLETE_IRQ_EN_SHIFT       (8U)
#define BCH_CTRL_CLR_COMPLETE_IRQ_EN(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_COMPLETE_IRQ_EN_SHIFT)) & BCH_CTRL_CLR_COMPLETE_IRQ_EN_MASK)

#define BCH_CTRL_CLR_RSVD2_MASK                  (0x200U)
#define BCH_CTRL_CLR_RSVD2_SHIFT                 (9U)
/*! RSVD2 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD2_SHIFT)) & BCH_CTRL_CLR_RSVD2_MASK)

#define BCH_CTRL_CLR_DEBUG_STALL_IRQ_EN_MASK     (0x400U)
#define BCH_CTRL_CLR_DEBUG_STALL_IRQ_EN_SHIFT    (10U)
#define BCH_CTRL_CLR_DEBUG_STALL_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_DEBUG_STALL_IRQ_EN_SHIFT)) & BCH_CTRL_CLR_DEBUG_STALL_IRQ_EN_MASK)

#define BCH_CTRL_CLR_RSVD3_MASK                  (0xF800U)
#define BCH_CTRL_CLR_RSVD3_SHIFT                 (11U)
/*! RSVD3 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD3(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD3_SHIFT)) & BCH_CTRL_CLR_RSVD3_MASK)

#define BCH_CTRL_CLR_M2M_ENABLE_MASK             (0x10000U)
#define BCH_CTRL_CLR_M2M_ENABLE_SHIFT            (16U)
#define BCH_CTRL_CLR_M2M_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_M2M_ENABLE_SHIFT)) & BCH_CTRL_CLR_M2M_ENABLE_MASK)

#define BCH_CTRL_CLR_M2M_ENCODE_MASK             (0x20000U)
#define BCH_CTRL_CLR_M2M_ENCODE_SHIFT            (17U)
#define BCH_CTRL_CLR_M2M_ENCODE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_M2M_ENCODE_SHIFT)) & BCH_CTRL_CLR_M2M_ENCODE_MASK)

#define BCH_CTRL_CLR_M2M_LAYOUT_MASK             (0xC0000U)
#define BCH_CTRL_CLR_M2M_LAYOUT_SHIFT            (18U)
#define BCH_CTRL_CLR_M2M_LAYOUT(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_M2M_LAYOUT_SHIFT)) & BCH_CTRL_CLR_M2M_LAYOUT_MASK)

#define BCH_CTRL_CLR_RSVD4_MASK                  (0x300000U)
#define BCH_CTRL_CLR_RSVD4_SHIFT                 (20U)
/*! RSVD4 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD4(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD4_SHIFT)) & BCH_CTRL_CLR_RSVD4_MASK)

#define BCH_CTRL_CLR_DEBUGSYNDROME_MASK          (0x400000U)
#define BCH_CTRL_CLR_DEBUGSYNDROME_SHIFT         (22U)
#define BCH_CTRL_CLR_DEBUGSYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_DEBUGSYNDROME_SHIFT)) & BCH_CTRL_CLR_DEBUGSYNDROME_MASK)

#define BCH_CTRL_CLR_RSVD5_MASK                  (0x3F800000U)
#define BCH_CTRL_CLR_RSVD5_SHIFT                 (23U)
/*! RSVD5 - This field is reserved. */
#define BCH_CTRL_CLR_RSVD5(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_RSVD5_SHIFT)) & BCH_CTRL_CLR_RSVD5_MASK)

#define BCH_CTRL_CLR_CLKGATE_MASK                (0x40000000U)
#define BCH_CTRL_CLR_CLKGATE_SHIFT               (30U)
/*! CLKGATE
 *  0b0..Allow BCH to operate normally.
 *  0b1..Do not clock BCH gates in order to minimize power consumption.
 */
#define BCH_CTRL_CLR_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_CLKGATE_SHIFT)) & BCH_CTRL_CLR_CLKGATE_MASK)

#define BCH_CTRL_CLR_SFTRST_MASK                 (0x80000000U)
#define BCH_CTRL_CLR_SFTRST_SHIFT                (31U)
/*! SFTRST
 *  0b0..Allow BCH to operate normally.
 *  0b1..Hold BCH in reset.
 */
#define BCH_CTRL_CLR_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_CLR_SFTRST_SHIFT)) & BCH_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - Hardware BCH ECC Accelerator Control Register */
/*! @{ */

#define BCH_CTRL_TOG_COMPLETE_IRQ_MASK           (0x1U)
#define BCH_CTRL_TOG_COMPLETE_IRQ_SHIFT          (0U)
#define BCH_CTRL_TOG_COMPLETE_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_COMPLETE_IRQ_SHIFT)) & BCH_CTRL_TOG_COMPLETE_IRQ_MASK)

#define BCH_CTRL_TOG_RSVD0_MASK                  (0x2U)
#define BCH_CTRL_TOG_RSVD0_SHIFT                 (1U)
/*! RSVD0 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD0_SHIFT)) & BCH_CTRL_TOG_RSVD0_MASK)

#define BCH_CTRL_TOG_DEBUG_STALL_IRQ_MASK        (0x4U)
#define BCH_CTRL_TOG_DEBUG_STALL_IRQ_SHIFT       (2U)
#define BCH_CTRL_TOG_DEBUG_STALL_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_DEBUG_STALL_IRQ_SHIFT)) & BCH_CTRL_TOG_DEBUG_STALL_IRQ_MASK)

#define BCH_CTRL_TOG_BM_ERROR_IRQ_MASK           (0x8U)
#define BCH_CTRL_TOG_BM_ERROR_IRQ_SHIFT          (3U)
#define BCH_CTRL_TOG_BM_ERROR_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_BM_ERROR_IRQ_SHIFT)) & BCH_CTRL_TOG_BM_ERROR_IRQ_MASK)

#define BCH_CTRL_TOG_RSVD1_MASK                  (0xF0U)
#define BCH_CTRL_TOG_RSVD1_SHIFT                 (4U)
/*! RSVD1 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD1_SHIFT)) & BCH_CTRL_TOG_RSVD1_MASK)

#define BCH_CTRL_TOG_COMPLETE_IRQ_EN_MASK        (0x100U)
#define BCH_CTRL_TOG_COMPLETE_IRQ_EN_SHIFT       (8U)
#define BCH_CTRL_TOG_COMPLETE_IRQ_EN(x)          (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_COMPLETE_IRQ_EN_SHIFT)) & BCH_CTRL_TOG_COMPLETE_IRQ_EN_MASK)

#define BCH_CTRL_TOG_RSVD2_MASK                  (0x200U)
#define BCH_CTRL_TOG_RSVD2_SHIFT                 (9U)
/*! RSVD2 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD2_SHIFT)) & BCH_CTRL_TOG_RSVD2_MASK)

#define BCH_CTRL_TOG_DEBUG_STALL_IRQ_EN_MASK     (0x400U)
#define BCH_CTRL_TOG_DEBUG_STALL_IRQ_EN_SHIFT    (10U)
#define BCH_CTRL_TOG_DEBUG_STALL_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_DEBUG_STALL_IRQ_EN_SHIFT)) & BCH_CTRL_TOG_DEBUG_STALL_IRQ_EN_MASK)

#define BCH_CTRL_TOG_RSVD3_MASK                  (0xF800U)
#define BCH_CTRL_TOG_RSVD3_SHIFT                 (11U)
/*! RSVD3 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD3(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD3_SHIFT)) & BCH_CTRL_TOG_RSVD3_MASK)

#define BCH_CTRL_TOG_M2M_ENABLE_MASK             (0x10000U)
#define BCH_CTRL_TOG_M2M_ENABLE_SHIFT            (16U)
#define BCH_CTRL_TOG_M2M_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_M2M_ENABLE_SHIFT)) & BCH_CTRL_TOG_M2M_ENABLE_MASK)

#define BCH_CTRL_TOG_M2M_ENCODE_MASK             (0x20000U)
#define BCH_CTRL_TOG_M2M_ENCODE_SHIFT            (17U)
#define BCH_CTRL_TOG_M2M_ENCODE(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_M2M_ENCODE_SHIFT)) & BCH_CTRL_TOG_M2M_ENCODE_MASK)

#define BCH_CTRL_TOG_M2M_LAYOUT_MASK             (0xC0000U)
#define BCH_CTRL_TOG_M2M_LAYOUT_SHIFT            (18U)
#define BCH_CTRL_TOG_M2M_LAYOUT(x)               (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_M2M_LAYOUT_SHIFT)) & BCH_CTRL_TOG_M2M_LAYOUT_MASK)

#define BCH_CTRL_TOG_RSVD4_MASK                  (0x300000U)
#define BCH_CTRL_TOG_RSVD4_SHIFT                 (20U)
/*! RSVD4 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD4(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD4_SHIFT)) & BCH_CTRL_TOG_RSVD4_MASK)

#define BCH_CTRL_TOG_DEBUGSYNDROME_MASK          (0x400000U)
#define BCH_CTRL_TOG_DEBUGSYNDROME_SHIFT         (22U)
#define BCH_CTRL_TOG_DEBUGSYNDROME(x)            (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_DEBUGSYNDROME_SHIFT)) & BCH_CTRL_TOG_DEBUGSYNDROME_MASK)

#define BCH_CTRL_TOG_RSVD5_MASK                  (0x3F800000U)
#define BCH_CTRL_TOG_RSVD5_SHIFT                 (23U)
/*! RSVD5 - This field is reserved. */
#define BCH_CTRL_TOG_RSVD5(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_RSVD5_SHIFT)) & BCH_CTRL_TOG_RSVD5_MASK)

#define BCH_CTRL_TOG_CLKGATE_MASK                (0x40000000U)
#define BCH_CTRL_TOG_CLKGATE_SHIFT               (30U)
/*! CLKGATE
 *  0b0..Allow BCH to operate normally.
 *  0b1..Do not clock BCH gates in order to minimize power consumption.
 */
#define BCH_CTRL_TOG_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_CLKGATE_SHIFT)) & BCH_CTRL_TOG_CLKGATE_MASK)

#define BCH_CTRL_TOG_SFTRST_MASK                 (0x80000000U)
#define BCH_CTRL_TOG_SFTRST_SHIFT                (31U)
/*! SFTRST
 *  0b0..Allow BCH to operate normally.
 *  0b1..Hold BCH in reset.
 */
#define BCH_CTRL_TOG_SFTRST(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_CTRL_TOG_SFTRST_SHIFT)) & BCH_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STATUS0 - Hardware ECC Accelerator Status Register 0 */
/*! @{ */

#define BCH_STATUS0_RSVD0_MASK                   (0x3U)
#define BCH_STATUS0_RSVD0_SHIFT                  (0U)
/*! RSVD0 - This field is reserved. */
#define BCH_STATUS0_RSVD0(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_RSVD0_SHIFT)) & BCH_STATUS0_RSVD0_MASK)

#define BCH_STATUS0_UNCORRECTABLE_MASK           (0x4U)
#define BCH_STATUS0_UNCORRECTABLE_SHIFT          (2U)
#define BCH_STATUS0_UNCORRECTABLE(x)             (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_UNCORRECTABLE_SHIFT)) & BCH_STATUS0_UNCORRECTABLE_MASK)

#define BCH_STATUS0_CORRECTED_MASK               (0x8U)
#define BCH_STATUS0_CORRECTED_SHIFT              (3U)
#define BCH_STATUS0_CORRECTED(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CORRECTED_SHIFT)) & BCH_STATUS0_CORRECTED_MASK)

#define BCH_STATUS0_ALLONES_MASK                 (0x10U)
#define BCH_STATUS0_ALLONES_SHIFT                (4U)
#define BCH_STATUS0_ALLONES(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_ALLONES_SHIFT)) & BCH_STATUS0_ALLONES_MASK)

#define BCH_STATUS0_RSVD1_MASK                   (0xE0U)
#define BCH_STATUS0_RSVD1_SHIFT                  (5U)
/*! RSVD1 - This field is reserved. */
#define BCH_STATUS0_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_RSVD1_SHIFT)) & BCH_STATUS0_RSVD1_MASK)

#define BCH_STATUS0_STATUS_BLK0_MASK             (0xFF00U)
#define BCH_STATUS0_STATUS_BLK0_SHIFT            (8U)
/*! STATUS_BLK0
 *  0b00000000..No errors found on block.
 *  0b00000001..One error found on block.
 *  0b00000010..One errors found on block.
 *  0b00000011..One errors found on block.
 *  0b00000100..One errors found on block.
 *  0b11111110..Block exhibited uncorrectable errors.
 *  0b11111111..Page is erased.
 */
#define BCH_STATUS0_STATUS_BLK0(x)               (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_STATUS_BLK0_SHIFT)) & BCH_STATUS0_STATUS_BLK0_MASK)

#define BCH_STATUS0_COMPLETED_CE_MASK            (0xF0000U)
#define BCH_STATUS0_COMPLETED_CE_SHIFT           (16U)
#define BCH_STATUS0_COMPLETED_CE(x)              (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_COMPLETED_CE_SHIFT)) & BCH_STATUS0_COMPLETED_CE_MASK)

#define BCH_STATUS0_HANDLE_MASK                  (0xFFF00000U)
#define BCH_STATUS0_HANDLE_SHIFT                 (20U)
#define BCH_STATUS0_HANDLE(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_HANDLE_SHIFT)) & BCH_STATUS0_HANDLE_MASK)
/*! @} */

/*! @name MODE - Hardware ECC Accelerator Mode Register */
/*! @{ */

#define BCH_MODE_ERASE_THRESHOLD_MASK            (0xFFU)
#define BCH_MODE_ERASE_THRESHOLD_SHIFT           (0U)
#define BCH_MODE_ERASE_THRESHOLD(x)              (((uint32_t)(((uint32_t)(x)) << BCH_MODE_ERASE_THRESHOLD_SHIFT)) & BCH_MODE_ERASE_THRESHOLD_MASK)

#define BCH_MODE_RSVD_MASK                       (0xFFFFFF00U)
#define BCH_MODE_RSVD_SHIFT                      (8U)
/*! RSVD - This field is reserved. */
#define BCH_MODE_RSVD(x)                         (((uint32_t)(((uint32_t)(x)) << BCH_MODE_RSVD_SHIFT)) & BCH_MODE_RSVD_MASK)
/*! @} */

/*! @name ENCODEPTR - Hardware BCH ECC Loopback Encode Buffer Register */
/*! @{ */

#define BCH_ENCODEPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define BCH_ENCODEPTR_ADDR_SHIFT                 (0U)
#define BCH_ENCODEPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_ENCODEPTR_ADDR_SHIFT)) & BCH_ENCODEPTR_ADDR_MASK)
/*! @} */

/*! @name DATAPTR - Hardware BCH ECC Loopback Data Buffer Register */
/*! @{ */

#define BCH_DATAPTR_ADDR_MASK                    (0xFFFFFFFFU)
#define BCH_DATAPTR_ADDR_SHIFT                   (0U)
#define BCH_DATAPTR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_DATAPTR_ADDR_SHIFT)) & BCH_DATAPTR_ADDR_MASK)
/*! @} */

/*! @name METAPTR - Hardware BCH ECC Loopback Metadata Buffer Register */
/*! @{ */

#define BCH_METAPTR_ADDR_MASK                    (0xFFFFFFFFU)
#define BCH_METAPTR_ADDR_SHIFT                   (0U)
#define BCH_METAPTR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_METAPTR_ADDR_SHIFT)) & BCH_METAPTR_ADDR_MASK)
/*! @} */

/*! @name LAYOUTSELECT - Hardware ECC Accelerator Layout Select Register */
/*! @{ */

#define BCH_LAYOUTSELECT_CS0_SELECT_MASK         (0x3U)
#define BCH_LAYOUTSELECT_CS0_SELECT_SHIFT        (0U)
#define BCH_LAYOUTSELECT_CS0_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS0_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS0_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS1_SELECT_MASK         (0xCU)
#define BCH_LAYOUTSELECT_CS1_SELECT_SHIFT        (2U)
#define BCH_LAYOUTSELECT_CS1_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS1_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS1_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS2_SELECT_MASK         (0x30U)
#define BCH_LAYOUTSELECT_CS2_SELECT_SHIFT        (4U)
#define BCH_LAYOUTSELECT_CS2_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS2_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS2_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS3_SELECT_MASK         (0xC0U)
#define BCH_LAYOUTSELECT_CS3_SELECT_SHIFT        (6U)
#define BCH_LAYOUTSELECT_CS3_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS3_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS3_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS4_SELECT_MASK         (0x300U)
#define BCH_LAYOUTSELECT_CS4_SELECT_SHIFT        (8U)
#define BCH_LAYOUTSELECT_CS4_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS4_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS4_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS5_SELECT_MASK         (0xC00U)
#define BCH_LAYOUTSELECT_CS5_SELECT_SHIFT        (10U)
#define BCH_LAYOUTSELECT_CS5_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS5_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS5_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS6_SELECT_MASK         (0x3000U)
#define BCH_LAYOUTSELECT_CS6_SELECT_SHIFT        (12U)
#define BCH_LAYOUTSELECT_CS6_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS6_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS6_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS7_SELECT_MASK         (0xC000U)
#define BCH_LAYOUTSELECT_CS7_SELECT_SHIFT        (14U)
#define BCH_LAYOUTSELECT_CS7_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS7_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS7_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS8_SELECT_MASK         (0x30000U)
#define BCH_LAYOUTSELECT_CS8_SELECT_SHIFT        (16U)
#define BCH_LAYOUTSELECT_CS8_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS8_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS8_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS9_SELECT_MASK         (0xC0000U)
#define BCH_LAYOUTSELECT_CS9_SELECT_SHIFT        (18U)
#define BCH_LAYOUTSELECT_CS9_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS9_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS9_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS10_SELECT_MASK        (0x300000U)
#define BCH_LAYOUTSELECT_CS10_SELECT_SHIFT       (20U)
#define BCH_LAYOUTSELECT_CS10_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS10_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS10_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS11_SELECT_MASK        (0xC00000U)
#define BCH_LAYOUTSELECT_CS11_SELECT_SHIFT       (22U)
#define BCH_LAYOUTSELECT_CS11_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS11_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS11_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS12_SELECT_MASK        (0x3000000U)
#define BCH_LAYOUTSELECT_CS12_SELECT_SHIFT       (24U)
#define BCH_LAYOUTSELECT_CS12_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS12_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS12_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS13_SELECT_MASK        (0xC000000U)
#define BCH_LAYOUTSELECT_CS13_SELECT_SHIFT       (26U)
#define BCH_LAYOUTSELECT_CS13_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS13_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS13_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS14_SELECT_MASK        (0x30000000U)
#define BCH_LAYOUTSELECT_CS14_SELECT_SHIFT       (28U)
#define BCH_LAYOUTSELECT_CS14_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS14_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS14_SELECT_MASK)

#define BCH_LAYOUTSELECT_CS15_SELECT_MASK        (0xC0000000U)
#define BCH_LAYOUTSELECT_CS15_SELECT_SHIFT       (30U)
#define BCH_LAYOUTSELECT_CS15_SELECT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CS15_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CS15_SELECT_MASK)
/*! @} */

/*! @name FLASH0LAYOUT0 - Hardware BCH ECC Flash 0 Layout 0 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT0_DATA0_SIZE_MASK        (0x3FFU)
#define BCH_FLASH0LAYOUT0_DATA0_SIZE_SHIFT       (0U)
#define BCH_FLASH0LAYOUT0_DATA0_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_DATA0_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_DATA0_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH0LAYOUT0_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH0LAYOUT0_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT0_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT0_ECC0_MASK              (0xF800U)
#define BCH_FLASH0LAYOUT0_ECC0_SHIFT             (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT0_ECC0(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_ECC0_SHIFT)) & BCH_FLASH0LAYOUT0_ECC0_MASK)

#define BCH_FLASH0LAYOUT0_META_SIZE_MASK         (0xFF0000U)
#define BCH_FLASH0LAYOUT0_META_SIZE_SHIFT        (16U)
#define BCH_FLASH0LAYOUT0_META_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_META_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_META_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_NBLOCKS_MASK           (0xFF000000U)
#define BCH_FLASH0LAYOUT0_NBLOCKS_SHIFT          (24U)
#define BCH_FLASH0LAYOUT0_NBLOCKS(x)             (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_NBLOCKS_SHIFT)) & BCH_FLASH0LAYOUT0_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH0LAYOUT1 - Hardware BCH ECC Flash 0 Layout 1 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT1_DATAN_SIZE_MASK        (0x3FFU)
#define BCH_FLASH0LAYOUT1_DATAN_SIZE_SHIFT       (0U)
#define BCH_FLASH0LAYOUT1_DATAN_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_DATAN_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_DATAN_SIZE_MASK)

#define BCH_FLASH0LAYOUT1_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH0LAYOUT1_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH0LAYOUT1_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT1_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT1_ECCN_MASK              (0xF800U)
#define BCH_FLASH0LAYOUT1_ECCN_SHIFT             (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT1_ECCN(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_ECCN_SHIFT)) & BCH_FLASH0LAYOUT1_ECCN_MASK)

#define BCH_FLASH0LAYOUT1_PAGE_SIZE_MASK         (0xFFFF0000U)
#define BCH_FLASH0LAYOUT1_PAGE_SIZE_SHIFT        (16U)
#define BCH_FLASH0LAYOUT1_PAGE_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_PAGE_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH1LAYOUT0 - Hardware BCH ECC Flash 1 Layout 0 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT0_DATA0_SIZE_MASK        (0x3FFU)
#define BCH_FLASH1LAYOUT0_DATA0_SIZE_SHIFT       (0U)
#define BCH_FLASH1LAYOUT0_DATA0_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_DATA0_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_DATA0_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH1LAYOUT0_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH1LAYOUT0_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT0_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT0_ECC0_MASK              (0xF800U)
#define BCH_FLASH1LAYOUT0_ECC0_SHIFT             (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT0_ECC0(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_ECC0_SHIFT)) & BCH_FLASH1LAYOUT0_ECC0_MASK)

#define BCH_FLASH1LAYOUT0_META_SIZE_MASK         (0xFF0000U)
#define BCH_FLASH1LAYOUT0_META_SIZE_SHIFT        (16U)
#define BCH_FLASH1LAYOUT0_META_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_META_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_META_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_NBLOCKS_MASK           (0xFF000000U)
#define BCH_FLASH1LAYOUT0_NBLOCKS_SHIFT          (24U)
#define BCH_FLASH1LAYOUT0_NBLOCKS(x)             (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_NBLOCKS_SHIFT)) & BCH_FLASH1LAYOUT0_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH1LAYOUT1 - Hardware BCH ECC Flash 1 Layout 1 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT1_DATAN_SIZE_MASK        (0x3FFU)
#define BCH_FLASH1LAYOUT1_DATAN_SIZE_SHIFT       (0U)
#define BCH_FLASH1LAYOUT1_DATAN_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_DATAN_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_DATAN_SIZE_MASK)

#define BCH_FLASH1LAYOUT1_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH1LAYOUT1_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH1LAYOUT1_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT1_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT1_ECCN_MASK              (0xF800U)
#define BCH_FLASH1LAYOUT1_ECCN_SHIFT             (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT1_ECCN(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_ECCN_SHIFT)) & BCH_FLASH1LAYOUT1_ECCN_MASK)

#define BCH_FLASH1LAYOUT1_PAGE_SIZE_MASK         (0xFFFF0000U)
#define BCH_FLASH1LAYOUT1_PAGE_SIZE_SHIFT        (16U)
#define BCH_FLASH1LAYOUT1_PAGE_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_PAGE_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH2LAYOUT0 - Hardware BCH ECC Flash 2 Layout 0 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT0_DATA0_SIZE_MASK        (0x3FFU)
#define BCH_FLASH2LAYOUT0_DATA0_SIZE_SHIFT       (0U)
#define BCH_FLASH2LAYOUT0_DATA0_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_DATA0_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_DATA0_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH2LAYOUT0_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH2LAYOUT0_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT0_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT0_ECC0_MASK              (0xF800U)
#define BCH_FLASH2LAYOUT0_ECC0_SHIFT             (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT0_ECC0(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_ECC0_SHIFT)) & BCH_FLASH2LAYOUT0_ECC0_MASK)

#define BCH_FLASH2LAYOUT0_META_SIZE_MASK         (0xFF0000U)
#define BCH_FLASH2LAYOUT0_META_SIZE_SHIFT        (16U)
#define BCH_FLASH2LAYOUT0_META_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_META_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_META_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_NBLOCKS_MASK           (0xFF000000U)
#define BCH_FLASH2LAYOUT0_NBLOCKS_SHIFT          (24U)
#define BCH_FLASH2LAYOUT0_NBLOCKS(x)             (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_NBLOCKS_SHIFT)) & BCH_FLASH2LAYOUT0_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH2LAYOUT1 - Hardware BCH ECC Flash 2 Layout 1 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT1_DATAN_SIZE_MASK        (0x3FFU)
#define BCH_FLASH2LAYOUT1_DATAN_SIZE_SHIFT       (0U)
#define BCH_FLASH2LAYOUT1_DATAN_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_DATAN_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_DATAN_SIZE_MASK)

#define BCH_FLASH2LAYOUT1_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH2LAYOUT1_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH2LAYOUT1_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT1_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT1_ECCN_MASK              (0xF800U)
#define BCH_FLASH2LAYOUT1_ECCN_SHIFT             (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT1_ECCN(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_ECCN_SHIFT)) & BCH_FLASH2LAYOUT1_ECCN_MASK)

#define BCH_FLASH2LAYOUT1_PAGE_SIZE_MASK         (0xFFFF0000U)
#define BCH_FLASH2LAYOUT1_PAGE_SIZE_SHIFT        (16U)
#define BCH_FLASH2LAYOUT1_PAGE_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_PAGE_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH3LAYOUT0 - Hardware BCH ECC Flash 3 Layout 0 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT0_DATA0_SIZE_MASK        (0x3FFU)
#define BCH_FLASH3LAYOUT0_DATA0_SIZE_SHIFT       (0U)
#define BCH_FLASH3LAYOUT0_DATA0_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_DATA0_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_DATA0_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH3LAYOUT0_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH3LAYOUT0_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT0_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT0_ECC0_MASK              (0xF800U)
#define BCH_FLASH3LAYOUT0_ECC0_SHIFT             (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT0_ECC0(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_ECC0_SHIFT)) & BCH_FLASH3LAYOUT0_ECC0_MASK)

#define BCH_FLASH3LAYOUT0_META_SIZE_MASK         (0xFF0000U)
#define BCH_FLASH3LAYOUT0_META_SIZE_SHIFT        (16U)
#define BCH_FLASH3LAYOUT0_META_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_META_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_META_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_NBLOCKS_MASK           (0xFF000000U)
#define BCH_FLASH3LAYOUT0_NBLOCKS_SHIFT          (24U)
#define BCH_FLASH3LAYOUT0_NBLOCKS(x)             (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_NBLOCKS_SHIFT)) & BCH_FLASH3LAYOUT0_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH3LAYOUT1 - Hardware BCH ECC Flash 3 Layout 1 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT1_DATAN_SIZE_MASK        (0x3FFU)
#define BCH_FLASH3LAYOUT1_DATAN_SIZE_SHIFT       (0U)
#define BCH_FLASH3LAYOUT1_DATAN_SIZE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_DATAN_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_DATAN_SIZE_MASK)

#define BCH_FLASH3LAYOUT1_GF13_0_GF14_1_MASK     (0x400U)
#define BCH_FLASH3LAYOUT1_GF13_0_GF14_1_SHIFT    (10U)
#define BCH_FLASH3LAYOUT1_GF13_0_GF14_1(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT1_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT1_ECCN_MASK              (0xF800U)
#define BCH_FLASH3LAYOUT1_ECCN_SHIFT             (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT1_ECCN(x)                (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_ECCN_SHIFT)) & BCH_FLASH3LAYOUT1_ECCN_MASK)

#define BCH_FLASH3LAYOUT1_PAGE_SIZE_MASK         (0xFFFF0000U)
#define BCH_FLASH3LAYOUT1_PAGE_SIZE_SHIFT        (16U)
#define BCH_FLASH3LAYOUT1_PAGE_SIZE(x)           (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_PAGE_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_PAGE_SIZE_MASK)
/*! @} */

/*! @name DEBUG0 - Hardware BCH ECC Debug Register0 */
/*! @{ */

#define BCH_DEBUG0_DEBUG_REG_SELECT_MASK         (0x3FU)
#define BCH_DEBUG0_DEBUG_REG_SELECT_SHIFT        (0U)
#define BCH_DEBUG0_DEBUG_REG_SELECT(x)           (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_DEBUG_REG_SELECT_SHIFT)) & BCH_DEBUG0_DEBUG_REG_SELECT_MASK)

#define BCH_DEBUG0_RSVD0_MASK                    (0xC0U)
#define BCH_DEBUG0_RSVD0_SHIFT                   (6U)
/*! RSVD0 - This field is reserved. */
#define BCH_DEBUG0_RSVD0(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_RSVD0_SHIFT)) & BCH_DEBUG0_RSVD0_MASK)

#define BCH_DEBUG0_BM_KES_TEST_BYPASS_MASK       (0x100U)
#define BCH_DEBUG0_BM_KES_TEST_BYPASS_SHIFT      (8U)
/*! BM_KES_TEST_BYPASS
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_BM_KES_TEST_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_BM_KES_TEST_BYPASS_SHIFT)) & BCH_DEBUG0_BM_KES_TEST_BYPASS_MASK)

#define BCH_DEBUG0_KES_DEBUG_STALL_MASK          (0x200U)
#define BCH_DEBUG0_KES_DEBUG_STALL_SHIFT         (9U)
/*! KES_DEBUG_STALL
 *  0b0..KES FSM proceeds to next block supplied by bus master.
 *  0b1..KES FSM waits after current equations are solved and the search engine is started.
 */
#define BCH_DEBUG0_KES_DEBUG_STALL(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_STALL_SHIFT)) & BCH_DEBUG0_KES_DEBUG_STALL_MASK)

#define BCH_DEBUG0_KES_DEBUG_STEP_MASK           (0x400U)
#define BCH_DEBUG0_KES_DEBUG_STEP_SHIFT          (10U)
#define BCH_DEBUG0_KES_DEBUG_STEP(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_STEP_SHIFT)) & BCH_DEBUG0_KES_DEBUG_STEP_MASK)

#define BCH_DEBUG0_KES_STANDALONE_MASK           (0x800U)
#define BCH_DEBUG0_KES_STANDALONE_SHIFT          (11U)
/*! KES_STANDALONE
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_KES_STANDALONE(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_STANDALONE_SHIFT)) & BCH_DEBUG0_KES_STANDALONE_MASK)

#define BCH_DEBUG0_KES_DEBUG_KICK_MASK           (0x1000U)
#define BCH_DEBUG0_KES_DEBUG_KICK_SHIFT          (12U)
#define BCH_DEBUG0_KES_DEBUG_KICK(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_KICK_SHIFT)) & BCH_DEBUG0_KES_DEBUG_KICK_MASK)

#define BCH_DEBUG0_KES_DEBUG_MODE4K_MASK         (0x2000U)
#define BCH_DEBUG0_KES_DEBUG_MODE4K_SHIFT        (13U)
/*! KES_DEBUG_MODE4K
 *  0b1..Mode is set for 2K NAND pages.
 *  0b1..Mode is set for 4K NAND pages.
 */
#define BCH_DEBUG0_KES_DEBUG_MODE4K(x)           (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_MODE4K_SHIFT)) & BCH_DEBUG0_KES_DEBUG_MODE4K_MASK)

#define BCH_DEBUG0_KES_DEBUG_PAYLOAD_FLAG_MASK   (0x4000U)
#define BCH_DEBUG0_KES_DEBUG_PAYLOAD_FLAG_SHIFT  (14U)
/*! KES_DEBUG_PAYLOAD_FLAG
 *  0b1..Payload is set for 512 bytes data block.
 *  0b1..Payload is set for 65 or 19 bytes auxiliary block.
 */
#define BCH_DEBUG0_KES_DEBUG_PAYLOAD_FLAG(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_PAYLOAD_FLAG_SHIFT)) & BCH_DEBUG0_KES_DEBUG_PAYLOAD_FLAG_MASK)

#define BCH_DEBUG0_KES_DEBUG_SHIFT_SYND_MASK     (0x8000U)
#define BCH_DEBUG0_KES_DEBUG_SHIFT_SYND_SHIFT    (15U)
#define BCH_DEBUG0_KES_DEBUG_SHIFT_SYND(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_SHIFT_SYND_SHIFT)) & BCH_DEBUG0_KES_DEBUG_SHIFT_SYND_MASK)

#define BCH_DEBUG0_KES_DEBUG_SYNDROME_SYMBOL_MASK (0x1FF0000U)
#define BCH_DEBUG0_KES_DEBUG_SYNDROME_SYMBOL_SHIFT (16U)
/*! KES_DEBUG_SYNDROME_SYMBOL
 *  0b000000000..Bus master address generator for SYND_GEN writes operates normally.
 *  0b000000001..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_KES_DEBUG_SYNDROME_SYMBOL(x)  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_KES_DEBUG_SYNDROME_SYMBOL_SHIFT)) & BCH_DEBUG0_KES_DEBUG_SYNDROME_SYMBOL_MASK)

#define BCH_DEBUG0_RSVD1_MASK                    (0xFE000000U)
#define BCH_DEBUG0_RSVD1_SHIFT                   (25U)
/*! RSVD1 - This field is reserved. */
#define BCH_DEBUG0_RSVD1(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_RSVD1_SHIFT)) & BCH_DEBUG0_RSVD1_MASK)
/*! @} */

/*! @name DEBUG0_SET - Hardware BCH ECC Debug Register0 */
/*! @{ */

#define BCH_DEBUG0_SET_DEBUG_REG_SELECT_MASK     (0x3FU)
#define BCH_DEBUG0_SET_DEBUG_REG_SELECT_SHIFT    (0U)
#define BCH_DEBUG0_SET_DEBUG_REG_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_DEBUG_REG_SELECT_SHIFT)) & BCH_DEBUG0_SET_DEBUG_REG_SELECT_MASK)

#define BCH_DEBUG0_SET_RSVD0_MASK                (0xC0U)
#define BCH_DEBUG0_SET_RSVD0_SHIFT               (6U)
/*! RSVD0 - This field is reserved. */
#define BCH_DEBUG0_SET_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_RSVD0_SHIFT)) & BCH_DEBUG0_SET_RSVD0_MASK)

#define BCH_DEBUG0_SET_BM_KES_TEST_BYPASS_MASK   (0x100U)
#define BCH_DEBUG0_SET_BM_KES_TEST_BYPASS_SHIFT  (8U)
/*! BM_KES_TEST_BYPASS
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_SET_BM_KES_TEST_BYPASS(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_BM_KES_TEST_BYPASS_SHIFT)) & BCH_DEBUG0_SET_BM_KES_TEST_BYPASS_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_STALL_MASK      (0x200U)
#define BCH_DEBUG0_SET_KES_DEBUG_STALL_SHIFT     (9U)
/*! KES_DEBUG_STALL
 *  0b0..KES FSM proceeds to next block supplied by bus master.
 *  0b1..KES FSM waits after current equations are solved and the search engine is started.
 */
#define BCH_DEBUG0_SET_KES_DEBUG_STALL(x)        (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_STALL_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_STALL_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_STEP_MASK       (0x400U)
#define BCH_DEBUG0_SET_KES_DEBUG_STEP_SHIFT      (10U)
#define BCH_DEBUG0_SET_KES_DEBUG_STEP(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_STEP_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_STEP_MASK)

#define BCH_DEBUG0_SET_KES_STANDALONE_MASK       (0x800U)
#define BCH_DEBUG0_SET_KES_STANDALONE_SHIFT      (11U)
/*! KES_STANDALONE
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_SET_KES_STANDALONE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_STANDALONE_SHIFT)) & BCH_DEBUG0_SET_KES_STANDALONE_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_KICK_MASK       (0x1000U)
#define BCH_DEBUG0_SET_KES_DEBUG_KICK_SHIFT      (12U)
#define BCH_DEBUG0_SET_KES_DEBUG_KICK(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_KICK_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_KICK_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_MODE4K_MASK     (0x2000U)
#define BCH_DEBUG0_SET_KES_DEBUG_MODE4K_SHIFT    (13U)
/*! KES_DEBUG_MODE4K
 *  0b1..Mode is set for 2K NAND pages.
 *  0b1..Mode is set for 4K NAND pages.
 */
#define BCH_DEBUG0_SET_KES_DEBUG_MODE4K(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_MODE4K_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_MODE4K_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_PAYLOAD_FLAG_MASK (0x4000U)
#define BCH_DEBUG0_SET_KES_DEBUG_PAYLOAD_FLAG_SHIFT (14U)
/*! KES_DEBUG_PAYLOAD_FLAG
 *  0b1..Payload is set for 512 bytes data block.
 *  0b1..Payload is set for 65 or 19 bytes auxiliary block.
 */
#define BCH_DEBUG0_SET_KES_DEBUG_PAYLOAD_FLAG(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_PAYLOAD_FLAG_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_PAYLOAD_FLAG_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_SHIFT_SYND_MASK (0x8000U)
#define BCH_DEBUG0_SET_KES_DEBUG_SHIFT_SYND_SHIFT (15U)
#define BCH_DEBUG0_SET_KES_DEBUG_SHIFT_SYND(x)   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_SHIFT_SYND_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_SHIFT_SYND_MASK)

#define BCH_DEBUG0_SET_KES_DEBUG_SYNDROME_SYMBOL_MASK (0x1FF0000U)
#define BCH_DEBUG0_SET_KES_DEBUG_SYNDROME_SYMBOL_SHIFT (16U)
/*! KES_DEBUG_SYNDROME_SYMBOL
 *  0b000000000..Bus master address generator for SYND_GEN writes operates normally.
 *  0b000000001..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_SET_KES_DEBUG_SYNDROME_SYMBOL(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_KES_DEBUG_SYNDROME_SYMBOL_SHIFT)) & BCH_DEBUG0_SET_KES_DEBUG_SYNDROME_SYMBOL_MASK)

#define BCH_DEBUG0_SET_RSVD1_MASK                (0xFE000000U)
#define BCH_DEBUG0_SET_RSVD1_SHIFT               (25U)
/*! RSVD1 - This field is reserved. */
#define BCH_DEBUG0_SET_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_SET_RSVD1_SHIFT)) & BCH_DEBUG0_SET_RSVD1_MASK)
/*! @} */

/*! @name DEBUG0_CLR - Hardware BCH ECC Debug Register0 */
/*! @{ */

#define BCH_DEBUG0_CLR_DEBUG_REG_SELECT_MASK     (0x3FU)
#define BCH_DEBUG0_CLR_DEBUG_REG_SELECT_SHIFT    (0U)
#define BCH_DEBUG0_CLR_DEBUG_REG_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_DEBUG_REG_SELECT_SHIFT)) & BCH_DEBUG0_CLR_DEBUG_REG_SELECT_MASK)

#define BCH_DEBUG0_CLR_RSVD0_MASK                (0xC0U)
#define BCH_DEBUG0_CLR_RSVD0_SHIFT               (6U)
/*! RSVD0 - This field is reserved. */
#define BCH_DEBUG0_CLR_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_RSVD0_SHIFT)) & BCH_DEBUG0_CLR_RSVD0_MASK)

#define BCH_DEBUG0_CLR_BM_KES_TEST_BYPASS_MASK   (0x100U)
#define BCH_DEBUG0_CLR_BM_KES_TEST_BYPASS_SHIFT  (8U)
/*! BM_KES_TEST_BYPASS
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_CLR_BM_KES_TEST_BYPASS(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_BM_KES_TEST_BYPASS_SHIFT)) & BCH_DEBUG0_CLR_BM_KES_TEST_BYPASS_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_STALL_MASK      (0x200U)
#define BCH_DEBUG0_CLR_KES_DEBUG_STALL_SHIFT     (9U)
/*! KES_DEBUG_STALL
 *  0b0..KES FSM proceeds to next block supplied by bus master.
 *  0b1..KES FSM waits after current equations are solved and the search engine is started.
 */
#define BCH_DEBUG0_CLR_KES_DEBUG_STALL(x)        (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_STALL_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_STALL_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_STEP_MASK       (0x400U)
#define BCH_DEBUG0_CLR_KES_DEBUG_STEP_SHIFT      (10U)
#define BCH_DEBUG0_CLR_KES_DEBUG_STEP(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_STEP_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_STEP_MASK)

#define BCH_DEBUG0_CLR_KES_STANDALONE_MASK       (0x800U)
#define BCH_DEBUG0_CLR_KES_STANDALONE_SHIFT      (11U)
/*! KES_STANDALONE
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_CLR_KES_STANDALONE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_STANDALONE_SHIFT)) & BCH_DEBUG0_CLR_KES_STANDALONE_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_KICK_MASK       (0x1000U)
#define BCH_DEBUG0_CLR_KES_DEBUG_KICK_SHIFT      (12U)
#define BCH_DEBUG0_CLR_KES_DEBUG_KICK(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_KICK_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_KICK_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_MODE4K_MASK     (0x2000U)
#define BCH_DEBUG0_CLR_KES_DEBUG_MODE4K_SHIFT    (13U)
/*! KES_DEBUG_MODE4K
 *  0b1..Mode is set for 2K NAND pages.
 *  0b1..Mode is set for 4K NAND pages.
 */
#define BCH_DEBUG0_CLR_KES_DEBUG_MODE4K(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_MODE4K_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_MODE4K_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_PAYLOAD_FLAG_MASK (0x4000U)
#define BCH_DEBUG0_CLR_KES_DEBUG_PAYLOAD_FLAG_SHIFT (14U)
/*! KES_DEBUG_PAYLOAD_FLAG
 *  0b1..Payload is set for 512 bytes data block.
 *  0b1..Payload is set for 65 or 19 bytes auxiliary block.
 */
#define BCH_DEBUG0_CLR_KES_DEBUG_PAYLOAD_FLAG(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_PAYLOAD_FLAG_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_PAYLOAD_FLAG_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_SHIFT_SYND_MASK (0x8000U)
#define BCH_DEBUG0_CLR_KES_DEBUG_SHIFT_SYND_SHIFT (15U)
#define BCH_DEBUG0_CLR_KES_DEBUG_SHIFT_SYND(x)   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_SHIFT_SYND_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_SHIFT_SYND_MASK)

#define BCH_DEBUG0_CLR_KES_DEBUG_SYNDROME_SYMBOL_MASK (0x1FF0000U)
#define BCH_DEBUG0_CLR_KES_DEBUG_SYNDROME_SYMBOL_SHIFT (16U)
/*! KES_DEBUG_SYNDROME_SYMBOL
 *  0b000000000..Bus master address generator for SYND_GEN writes operates normally.
 *  0b000000001..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_CLR_KES_DEBUG_SYNDROME_SYMBOL(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_KES_DEBUG_SYNDROME_SYMBOL_SHIFT)) & BCH_DEBUG0_CLR_KES_DEBUG_SYNDROME_SYMBOL_MASK)

#define BCH_DEBUG0_CLR_RSVD1_MASK                (0xFE000000U)
#define BCH_DEBUG0_CLR_RSVD1_SHIFT               (25U)
/*! RSVD1 - This field is reserved. */
#define BCH_DEBUG0_CLR_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_CLR_RSVD1_SHIFT)) & BCH_DEBUG0_CLR_RSVD1_MASK)
/*! @} */

/*! @name DEBUG0_TOG - Hardware BCH ECC Debug Register0 */
/*! @{ */

#define BCH_DEBUG0_TOG_DEBUG_REG_SELECT_MASK     (0x3FU)
#define BCH_DEBUG0_TOG_DEBUG_REG_SELECT_SHIFT    (0U)
#define BCH_DEBUG0_TOG_DEBUG_REG_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_DEBUG_REG_SELECT_SHIFT)) & BCH_DEBUG0_TOG_DEBUG_REG_SELECT_MASK)

#define BCH_DEBUG0_TOG_RSVD0_MASK                (0xC0U)
#define BCH_DEBUG0_TOG_RSVD0_SHIFT               (6U)
/*! RSVD0 - This field is reserved. */
#define BCH_DEBUG0_TOG_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_RSVD0_SHIFT)) & BCH_DEBUG0_TOG_RSVD0_MASK)

#define BCH_DEBUG0_TOG_BM_KES_TEST_BYPASS_MASK   (0x100U)
#define BCH_DEBUG0_TOG_BM_KES_TEST_BYPASS_SHIFT  (8U)
/*! BM_KES_TEST_BYPASS
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_TOG_BM_KES_TEST_BYPASS(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_BM_KES_TEST_BYPASS_SHIFT)) & BCH_DEBUG0_TOG_BM_KES_TEST_BYPASS_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_STALL_MASK      (0x200U)
#define BCH_DEBUG0_TOG_KES_DEBUG_STALL_SHIFT     (9U)
/*! KES_DEBUG_STALL
 *  0b0..KES FSM proceeds to next block supplied by bus master.
 *  0b1..KES FSM waits after current equations are solved and the search engine is started.
 */
#define BCH_DEBUG0_TOG_KES_DEBUG_STALL(x)        (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_STALL_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_STALL_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_STEP_MASK       (0x400U)
#define BCH_DEBUG0_TOG_KES_DEBUG_STEP_SHIFT      (10U)
#define BCH_DEBUG0_TOG_KES_DEBUG_STEP(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_STEP_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_STEP_MASK)

#define BCH_DEBUG0_TOG_KES_STANDALONE_MASK       (0x800U)
#define BCH_DEBUG0_TOG_KES_STANDALONE_SHIFT      (11U)
/*! KES_STANDALONE
 *  0b0..Bus master address generator for SYND_GEN writes operates normally.
 *  0b1..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_TOG_KES_STANDALONE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_STANDALONE_SHIFT)) & BCH_DEBUG0_TOG_KES_STANDALONE_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_KICK_MASK       (0x1000U)
#define BCH_DEBUG0_TOG_KES_DEBUG_KICK_SHIFT      (12U)
#define BCH_DEBUG0_TOG_KES_DEBUG_KICK(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_KICK_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_KICK_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_MODE4K_MASK     (0x2000U)
#define BCH_DEBUG0_TOG_KES_DEBUG_MODE4K_SHIFT    (13U)
/*! KES_DEBUG_MODE4K
 *  0b1..Mode is set for 2K NAND pages.
 *  0b1..Mode is set for 4K NAND pages.
 */
#define BCH_DEBUG0_TOG_KES_DEBUG_MODE4K(x)       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_MODE4K_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_MODE4K_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_PAYLOAD_FLAG_MASK (0x4000U)
#define BCH_DEBUG0_TOG_KES_DEBUG_PAYLOAD_FLAG_SHIFT (14U)
/*! KES_DEBUG_PAYLOAD_FLAG
 *  0b1..Payload is set for 512 bytes data block.
 *  0b1..Payload is set for 65 or 19 bytes auxiliary block.
 */
#define BCH_DEBUG0_TOG_KES_DEBUG_PAYLOAD_FLAG(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_PAYLOAD_FLAG_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_PAYLOAD_FLAG_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_SHIFT_SYND_MASK (0x8000U)
#define BCH_DEBUG0_TOG_KES_DEBUG_SHIFT_SYND_SHIFT (15U)
#define BCH_DEBUG0_TOG_KES_DEBUG_SHIFT_SYND(x)   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_SHIFT_SYND_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_SHIFT_SYND_MASK)

#define BCH_DEBUG0_TOG_KES_DEBUG_SYNDROME_SYMBOL_MASK (0x1FF0000U)
#define BCH_DEBUG0_TOG_KES_DEBUG_SYNDROME_SYMBOL_SHIFT (16U)
/*! KES_DEBUG_SYNDROME_SYMBOL
 *  0b000000000..Bus master address generator for SYND_GEN writes operates normally.
 *  0b000000001..Bus master address generator always addresses last four bytes in Auxiliary block.
 */
#define BCH_DEBUG0_TOG_KES_DEBUG_SYNDROME_SYMBOL(x) (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_KES_DEBUG_SYNDROME_SYMBOL_SHIFT)) & BCH_DEBUG0_TOG_KES_DEBUG_SYNDROME_SYMBOL_MASK)

#define BCH_DEBUG0_TOG_RSVD1_MASK                (0xFE000000U)
#define BCH_DEBUG0_TOG_RSVD1_SHIFT               (25U)
/*! RSVD1 - This field is reserved. */
#define BCH_DEBUG0_TOG_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG0_TOG_RSVD1_SHIFT)) & BCH_DEBUG0_TOG_RSVD1_MASK)
/*! @} */

/*! @name DBGKESREAD - KES Debug Read Register */
/*! @{ */

#define BCH_DBGKESREAD_VALUES_MASK               (0xFFFFFFFFU)
#define BCH_DBGKESREAD_VALUES_SHIFT              (0U)
#define BCH_DBGKESREAD_VALUES(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_DBGKESREAD_VALUES_SHIFT)) & BCH_DBGKESREAD_VALUES_MASK)
/*! @} */

/*! @name DBGCSFEREAD - Chien Search Debug Read Register */
/*! @{ */

#define BCH_DBGCSFEREAD_VALUES_MASK              (0xFFFFFFFFU)
#define BCH_DBGCSFEREAD_VALUES_SHIFT             (0U)
#define BCH_DBGCSFEREAD_VALUES(x)                (((uint32_t)(((uint32_t)(x)) << BCH_DBGCSFEREAD_VALUES_SHIFT)) & BCH_DBGCSFEREAD_VALUES_MASK)
/*! @} */

/*! @name DBGSYNDGENREAD - Syndrome Generator Debug Read Register */
/*! @{ */

#define BCH_DBGSYNDGENREAD_VALUES_MASK           (0xFFFFFFFFU)
#define BCH_DBGSYNDGENREAD_VALUES_SHIFT          (0U)
#define BCH_DBGSYNDGENREAD_VALUES(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DBGSYNDGENREAD_VALUES_SHIFT)) & BCH_DBGSYNDGENREAD_VALUES_MASK)
/*! @} */

/*! @name DBGAHBMREAD - Bus Master and ECC Controller Debug Read Register */
/*! @{ */

#define BCH_DBGAHBMREAD_VALUES_MASK              (0xFFFFFFFFU)
#define BCH_DBGAHBMREAD_VALUES_SHIFT             (0U)
#define BCH_DBGAHBMREAD_VALUES(x)                (((uint32_t)(((uint32_t)(x)) << BCH_DBGAHBMREAD_VALUES_SHIFT)) & BCH_DBGAHBMREAD_VALUES_MASK)
/*! @} */

/*! @name BLOCKNAME - Block Name Register */
/*! @{ */

#define BCH_BLOCKNAME_NAME_MASK                  (0xFFFFFFFFU)
#define BCH_BLOCKNAME_NAME_SHIFT                 (0U)
#define BCH_BLOCKNAME_NAME(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_BLOCKNAME_NAME_SHIFT)) & BCH_BLOCKNAME_NAME_MASK)
/*! @} */

/*! @name VERSION - BCH Version Register */
/*! @{ */

#define BCH_VERSION_STEP_MASK                    (0xFFFFU)
#define BCH_VERSION_STEP_SHIFT                   (0U)
#define BCH_VERSION_STEP(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_STEP_SHIFT)) & BCH_VERSION_STEP_MASK)

#define BCH_VERSION_MINOR_MASK                   (0xFF0000U)
#define BCH_VERSION_MINOR_SHIFT                  (16U)
#define BCH_VERSION_MINOR(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_MINOR_SHIFT)) & BCH_VERSION_MINOR_MASK)

#define BCH_VERSION_MAJOR_MASK                   (0xFF000000U)
#define BCH_VERSION_MAJOR_SHIFT                  (24U)
#define BCH_VERSION_MAJOR(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_MAJOR_SHIFT)) & BCH_VERSION_MAJOR_MASK)
/*! @} */

/*! @name DEBUG1 - Hardware BCH ECC Debug Register 1 */
/*! @{ */

#define BCH_DEBUG1_ERASED_ZERO_COUNT_MASK        (0x1FFU)
#define BCH_DEBUG1_ERASED_ZERO_COUNT_SHIFT       (0U)
#define BCH_DEBUG1_ERASED_ZERO_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_ERASED_ZERO_COUNT_SHIFT)) & BCH_DEBUG1_ERASED_ZERO_COUNT_MASK)

#define BCH_DEBUG1_RSVD_MASK                     (0x7FFFFE00U)
#define BCH_DEBUG1_RSVD_SHIFT                    (9U)
/*! RSVD - This field is reserved. */
#define BCH_DEBUG1_RSVD(x)                       (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_RSVD_SHIFT)) & BCH_DEBUG1_RSVD_MASK)

#define BCH_DEBUG1_DEBUG1_PREERASECHK_MASK       (0x80000000U)
#define BCH_DEBUG1_DEBUG1_PREERASECHK_SHIFT      (31U)
/*! DEBUG1_PREERASECHK
 *  0b0..Turn off pre-erase check
 *  0b1..Turn on pre-erase check
 */
#define BCH_DEBUG1_DEBUG1_PREERASECHK(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_DEBUG1_PREERASECHK_SHIFT)) & BCH_DEBUG1_DEBUG1_PREERASECHK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group BCH_Register_Masks */


/*!
 * @}
 */ /* end of group BCH_Peripheral_Access_Layer */


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


#endif  /* PERI_BCH_H_ */

