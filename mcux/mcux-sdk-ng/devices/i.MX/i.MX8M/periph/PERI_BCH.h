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
 * @file PERI_BCH.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for BCH
 *
 * CMSIS Peripheral Access Layer for BCH
 */

#if !defined(PERI_BCH_H_)
#define PERI_BCH_H_                              /**< Symbol preventing repeated inclusion */

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
  __I  uint32_t STATUS0_SET;                       /**< Hardware ECC Accelerator Status Register 0, offset: 0x14 */
  __I  uint32_t STATUS0_CLR;                       /**< Hardware ECC Accelerator Status Register 0, offset: 0x18 */
  __I  uint32_t STATUS0_TOG;                       /**< Hardware ECC Accelerator Status Register 0, offset: 0x1C */
  __IO uint32_t MODE;                              /**< Hardware ECC Accelerator Mode Register, offset: 0x20 */
  __IO uint32_t MODE_SET;                          /**< Hardware ECC Accelerator Mode Register, offset: 0x24 */
  __IO uint32_t MODE_CLR;                          /**< Hardware ECC Accelerator Mode Register, offset: 0x28 */
  __IO uint32_t MODE_TOG;                          /**< Hardware ECC Accelerator Mode Register, offset: 0x2C */
  __IO uint32_t ENCODEPTR;                         /**< Hardware BCH ECC Loopback Encode Buffer Register, offset: 0x30 */
  __IO uint32_t ENCODEPTR_SET;                     /**< Hardware BCH ECC Loopback Encode Buffer Register, offset: 0x34 */
  __IO uint32_t ENCODEPTR_CLR;                     /**< Hardware BCH ECC Loopback Encode Buffer Register, offset: 0x38 */
  __IO uint32_t ENCODEPTR_TOG;                     /**< Hardware BCH ECC Loopback Encode Buffer Register, offset: 0x3C */
  __IO uint32_t DATAPTR;                           /**< Hardware BCH ECC Loopback Data Buffer Register, offset: 0x40 */
  __IO uint32_t DATAPTR_SET;                       /**< Hardware BCH ECC Loopback Data Buffer Register, offset: 0x44 */
  __IO uint32_t DATAPTR_CLR;                       /**< Hardware BCH ECC Loopback Data Buffer Register, offset: 0x48 */
  __IO uint32_t DATAPTR_TOG;                       /**< Hardware BCH ECC Loopback Data Buffer Register, offset: 0x4C */
  __IO uint32_t METAPTR;                           /**< Hardware BCH ECC Loopback Metadata Buffer Register, offset: 0x50 */
  __IO uint32_t METAPTR_SET;                       /**< Hardware BCH ECC Loopback Metadata Buffer Register, offset: 0x54 */
  __IO uint32_t METAPTR_CLR;                       /**< Hardware BCH ECC Loopback Metadata Buffer Register, offset: 0x58 */
  __IO uint32_t METAPTR_TOG;                       /**< Hardware BCH ECC Loopback Metadata Buffer Register, offset: 0x5C */
       uint8_t RESERVED_0[16];
  __IO uint32_t LAYOUTSELECT;                      /**< Hardware ECC Accelerator Layout Select Register, offset: 0x70 */
  __IO uint32_t LAYOUTSELECT_SET;                  /**< Hardware ECC Accelerator Layout Select Register, offset: 0x74 */
  __IO uint32_t LAYOUTSELECT_CLR;                  /**< Hardware ECC Accelerator Layout Select Register, offset: 0x78 */
  __IO uint32_t LAYOUTSELECT_TOG;                  /**< Hardware ECC Accelerator Layout Select Register, offset: 0x7C */
  __IO uint32_t FLASH0LAYOUT0;                     /**< Hardware BCH ECC Flash 0 Layout 0 Register, offset: 0x80 */
  __IO uint32_t FLASH0LAYOUT0_SET;                 /**< Hardware BCH ECC Flash 0 Layout 0 Register, offset: 0x84 */
  __IO uint32_t FLASH0LAYOUT0_CLR;                 /**< Hardware BCH ECC Flash 0 Layout 0 Register, offset: 0x88 */
  __IO uint32_t FLASH0LAYOUT0_TOG;                 /**< Hardware BCH ECC Flash 0 Layout 0 Register, offset: 0x8C */
  __IO uint32_t FLASH0LAYOUT1;                     /**< Hardware BCH ECC Flash 0 Layout 1 Register, offset: 0x90 */
  __IO uint32_t FLASH0LAYOUT1_SET;                 /**< Hardware BCH ECC Flash 0 Layout 1 Register, offset: 0x94 */
  __IO uint32_t FLASH0LAYOUT1_CLR;                 /**< Hardware BCH ECC Flash 0 Layout 1 Register, offset: 0x98 */
  __IO uint32_t FLASH0LAYOUT1_TOG;                 /**< Hardware BCH ECC Flash 0 Layout 1 Register, offset: 0x9C */
  __IO uint32_t FLASH1LAYOUT0;                     /**< Hardware BCH ECC Flash 1 Layout 0 Register, offset: 0xA0 */
  __IO uint32_t FLASH1LAYOUT0_SET;                 /**< Hardware BCH ECC Flash 1 Layout 0 Register, offset: 0xA4 */
  __IO uint32_t FLASH1LAYOUT0_CLR;                 /**< Hardware BCH ECC Flash 1 Layout 0 Register, offset: 0xA8 */
  __IO uint32_t FLASH1LAYOUT0_TOG;                 /**< Hardware BCH ECC Flash 1 Layout 0 Register, offset: 0xAC */
  __IO uint32_t FLASH1LAYOUT1;                     /**< Hardware BCH ECC Flash 1 Layout 1 Register, offset: 0xB0 */
  __IO uint32_t FLASH1LAYOUT1_SET;                 /**< Hardware BCH ECC Flash 1 Layout 1 Register, offset: 0xB4 */
  __IO uint32_t FLASH1LAYOUT1_CLR;                 /**< Hardware BCH ECC Flash 1 Layout 1 Register, offset: 0xB8 */
  __IO uint32_t FLASH1LAYOUT1_TOG;                 /**< Hardware BCH ECC Flash 1 Layout 1 Register, offset: 0xBC */
  __IO uint32_t FLASH2LAYOUT0;                     /**< Hardware BCH ECC Flash 2 Layout 0 Register, offset: 0xC0 */
  __IO uint32_t FLASH2LAYOUT0_SET;                 /**< Hardware BCH ECC Flash 2 Layout 0 Register, offset: 0xC4 */
  __IO uint32_t FLASH2LAYOUT0_CLR;                 /**< Hardware BCH ECC Flash 2 Layout 0 Register, offset: 0xC8 */
  __IO uint32_t FLASH2LAYOUT0_TOG;                 /**< Hardware BCH ECC Flash 2 Layout 0 Register, offset: 0xCC */
  __IO uint32_t FLASH2LAYOUT1;                     /**< Hardware BCH ECC Flash 2 Layout 1 Register, offset: 0xD0 */
  __IO uint32_t FLASH2LAYOUT1_SET;                 /**< Hardware BCH ECC Flash 2 Layout 1 Register, offset: 0xD4 */
  __IO uint32_t FLASH2LAYOUT1_CLR;                 /**< Hardware BCH ECC Flash 2 Layout 1 Register, offset: 0xD8 */
  __IO uint32_t FLASH2LAYOUT1_TOG;                 /**< Hardware BCH ECC Flash 2 Layout 1 Register, offset: 0xDC */
  __IO uint32_t FLASH3LAYOUT0;                     /**< Hardware BCH ECC Flash 3 Layout 0 Register, offset: 0xE0 */
  __IO uint32_t FLASH3LAYOUT0_SET;                 /**< Hardware BCH ECC Flash 3 Layout 0 Register, offset: 0xE4 */
  __IO uint32_t FLASH3LAYOUT0_CLR;                 /**< Hardware BCH ECC Flash 3 Layout 0 Register, offset: 0xE8 */
  __IO uint32_t FLASH3LAYOUT0_TOG;                 /**< Hardware BCH ECC Flash 3 Layout 0 Register, offset: 0xEC */
  __IO uint32_t FLASH3LAYOUT1;                     /**< Hardware BCH ECC Flash 3 Layout 1 Register, offset: 0xF0 */
  __IO uint32_t FLASH3LAYOUT1_SET;                 /**< Hardware BCH ECC Flash 3 Layout 1 Register, offset: 0xF4 */
  __IO uint32_t FLASH3LAYOUT1_CLR;                 /**< Hardware BCH ECC Flash 3 Layout 1 Register, offset: 0xF8 */
  __IO uint32_t FLASH3LAYOUT1_TOG;                 /**< Hardware BCH ECC Flash 3 Layout 1 Register, offset: 0xFC */
  __IO uint32_t DEBUG0;                            /**< Hardware BCH ECC Debug Register0, offset: 0x100 */
  __IO uint32_t DEBUG0_SET;                        /**< Hardware BCH ECC Debug Register0, offset: 0x104 */
  __IO uint32_t DEBUG0_CLR;                        /**< Hardware BCH ECC Debug Register0, offset: 0x108 */
  __IO uint32_t DEBUG0_TOG;                        /**< Hardware BCH ECC Debug Register0, offset: 0x10C */
  __I  uint32_t DBGKESREAD;                        /**< KES Debug Read Register, offset: 0x110 */
  __I  uint32_t DBGKESREAD_SET;                    /**< KES Debug Read Register, offset: 0x114 */
  __I  uint32_t DBGKESREAD_CLR;                    /**< KES Debug Read Register, offset: 0x118 */
  __I  uint32_t DBGKESREAD_TOG;                    /**< KES Debug Read Register, offset: 0x11C */
  __I  uint32_t DBGCSFEREAD;                       /**< Chien Search Debug Read Register, offset: 0x120 */
  __I  uint32_t DBGCSFEREAD_SET;                   /**< Chien Search Debug Read Register, offset: 0x124 */
  __I  uint32_t DBGCSFEREAD_CLR;                   /**< Chien Search Debug Read Register, offset: 0x128 */
  __I  uint32_t DBGCSFEREAD_TOG;                   /**< Chien Search Debug Read Register, offset: 0x12C */
  __I  uint32_t DBGSYNDGENREAD;                    /**< Syndrome Generator Debug Read Register, offset: 0x130 */
  __I  uint32_t DBGSYNDGENREAD_SET;                /**< Syndrome Generator Debug Read Register, offset: 0x134 */
  __I  uint32_t DBGSYNDGENREAD_CLR;                /**< Syndrome Generator Debug Read Register, offset: 0x138 */
  __I  uint32_t DBGSYNDGENREAD_TOG;                /**< Syndrome Generator Debug Read Register, offset: 0x13C */
  __I  uint32_t DBGAHBMREAD;                       /**< Bus Master and ECC Controller Debug Read Register, offset: 0x140 */
  __I  uint32_t DBGAHBMREAD_SET;                   /**< Bus Master and ECC Controller Debug Read Register, offset: 0x144 */
  __I  uint32_t DBGAHBMREAD_CLR;                   /**< Bus Master and ECC Controller Debug Read Register, offset: 0x148 */
  __I  uint32_t DBGAHBMREAD_TOG;                   /**< Bus Master and ECC Controller Debug Read Register, offset: 0x14C */
  __I  uint32_t BLOCKNAME;                         /**< Block Name Register, offset: 0x150 */
  __I  uint32_t BLOCKNAME_SET;                     /**< Block Name Register, offset: 0x154 */
  __I  uint32_t BLOCKNAME_CLR;                     /**< Block Name Register, offset: 0x158 */
  __I  uint32_t BLOCKNAME_TOG;                     /**< Block Name Register, offset: 0x15C */
  __I  uint32_t VERSION;                           /**< BCH Version Register, offset: 0x160 */
  __I  uint32_t VERSION_SET;                       /**< BCH Version Register, offset: 0x164 */
  __I  uint32_t VERSION_CLR;                       /**< BCH Version Register, offset: 0x168 */
  __I  uint32_t VERSION_TOG;                       /**< BCH Version Register, offset: 0x16C */
  __IO uint32_t DEBUG1;                            /**< Hardware BCH ECC Debug Register 1, offset: 0x170 */
  __IO uint32_t DEBUG1_SET;                        /**< Hardware BCH ECC Debug Register 1, offset: 0x174 */
  __IO uint32_t DEBUG1_CLR;                        /**< Hardware BCH ECC Debug Register 1, offset: 0x178 */
  __IO uint32_t DEBUG1_TOG;                        /**< Hardware BCH ECC Debug Register 1, offset: 0x17C */
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

/*! @name STATUS0_SET - Hardware ECC Accelerator Status Register 0 */
/*! @{ */

#define BCH_STATUS0_SET_RSVD0_MASK               (0x3U)
#define BCH_STATUS0_SET_RSVD0_SHIFT              (0U)
/*! RSVD0 - This field is reserved. */
#define BCH_STATUS0_SET_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_RSVD0_SHIFT)) & BCH_STATUS0_SET_RSVD0_MASK)

#define BCH_STATUS0_SET_UNCORRECTABLE_MASK       (0x4U)
#define BCH_STATUS0_SET_UNCORRECTABLE_SHIFT      (2U)
#define BCH_STATUS0_SET_UNCORRECTABLE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_UNCORRECTABLE_SHIFT)) & BCH_STATUS0_SET_UNCORRECTABLE_MASK)

#define BCH_STATUS0_SET_CORRECTED_MASK           (0x8U)
#define BCH_STATUS0_SET_CORRECTED_SHIFT          (3U)
#define BCH_STATUS0_SET_CORRECTED(x)             (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_CORRECTED_SHIFT)) & BCH_STATUS0_SET_CORRECTED_MASK)

#define BCH_STATUS0_SET_ALLONES_MASK             (0x10U)
#define BCH_STATUS0_SET_ALLONES_SHIFT            (4U)
#define BCH_STATUS0_SET_ALLONES(x)               (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_ALLONES_SHIFT)) & BCH_STATUS0_SET_ALLONES_MASK)

#define BCH_STATUS0_SET_RSVD1_MASK               (0xE0U)
#define BCH_STATUS0_SET_RSVD1_SHIFT              (5U)
/*! RSVD1 - This field is reserved. */
#define BCH_STATUS0_SET_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_RSVD1_SHIFT)) & BCH_STATUS0_SET_RSVD1_MASK)

#define BCH_STATUS0_SET_STATUS_BLK0_MASK         (0xFF00U)
#define BCH_STATUS0_SET_STATUS_BLK0_SHIFT        (8U)
/*! STATUS_BLK0
 *  0b00000000..No errors found on block.
 *  0b00000001..One error found on block.
 *  0b00000010..One errors found on block.
 *  0b00000011..One errors found on block.
 *  0b00000100..One errors found on block.
 *  0b11111110..Block exhibited uncorrectable errors.
 *  0b11111111..Page is erased.
 */
#define BCH_STATUS0_SET_STATUS_BLK0(x)           (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_STATUS_BLK0_SHIFT)) & BCH_STATUS0_SET_STATUS_BLK0_MASK)

#define BCH_STATUS0_SET_COMPLETED_CE_MASK        (0xF0000U)
#define BCH_STATUS0_SET_COMPLETED_CE_SHIFT       (16U)
#define BCH_STATUS0_SET_COMPLETED_CE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_COMPLETED_CE_SHIFT)) & BCH_STATUS0_SET_COMPLETED_CE_MASK)

#define BCH_STATUS0_SET_HANDLE_MASK              (0xFFF00000U)
#define BCH_STATUS0_SET_HANDLE_SHIFT             (20U)
#define BCH_STATUS0_SET_HANDLE(x)                (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_SET_HANDLE_SHIFT)) & BCH_STATUS0_SET_HANDLE_MASK)
/*! @} */

/*! @name STATUS0_CLR - Hardware ECC Accelerator Status Register 0 */
/*! @{ */

#define BCH_STATUS0_CLR_RSVD0_MASK               (0x3U)
#define BCH_STATUS0_CLR_RSVD0_SHIFT              (0U)
/*! RSVD0 - This field is reserved. */
#define BCH_STATUS0_CLR_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_RSVD0_SHIFT)) & BCH_STATUS0_CLR_RSVD0_MASK)

#define BCH_STATUS0_CLR_UNCORRECTABLE_MASK       (0x4U)
#define BCH_STATUS0_CLR_UNCORRECTABLE_SHIFT      (2U)
#define BCH_STATUS0_CLR_UNCORRECTABLE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_UNCORRECTABLE_SHIFT)) & BCH_STATUS0_CLR_UNCORRECTABLE_MASK)

#define BCH_STATUS0_CLR_CORRECTED_MASK           (0x8U)
#define BCH_STATUS0_CLR_CORRECTED_SHIFT          (3U)
#define BCH_STATUS0_CLR_CORRECTED(x)             (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_CORRECTED_SHIFT)) & BCH_STATUS0_CLR_CORRECTED_MASK)

#define BCH_STATUS0_CLR_ALLONES_MASK             (0x10U)
#define BCH_STATUS0_CLR_ALLONES_SHIFT            (4U)
#define BCH_STATUS0_CLR_ALLONES(x)               (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_ALLONES_SHIFT)) & BCH_STATUS0_CLR_ALLONES_MASK)

#define BCH_STATUS0_CLR_RSVD1_MASK               (0xE0U)
#define BCH_STATUS0_CLR_RSVD1_SHIFT              (5U)
/*! RSVD1 - This field is reserved. */
#define BCH_STATUS0_CLR_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_RSVD1_SHIFT)) & BCH_STATUS0_CLR_RSVD1_MASK)

#define BCH_STATUS0_CLR_STATUS_BLK0_MASK         (0xFF00U)
#define BCH_STATUS0_CLR_STATUS_BLK0_SHIFT        (8U)
/*! STATUS_BLK0
 *  0b00000000..No errors found on block.
 *  0b00000001..One error found on block.
 *  0b00000010..One errors found on block.
 *  0b00000011..One errors found on block.
 *  0b00000100..One errors found on block.
 *  0b11111110..Block exhibited uncorrectable errors.
 *  0b11111111..Page is erased.
 */
#define BCH_STATUS0_CLR_STATUS_BLK0(x)           (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_STATUS_BLK0_SHIFT)) & BCH_STATUS0_CLR_STATUS_BLK0_MASK)

#define BCH_STATUS0_CLR_COMPLETED_CE_MASK        (0xF0000U)
#define BCH_STATUS0_CLR_COMPLETED_CE_SHIFT       (16U)
#define BCH_STATUS0_CLR_COMPLETED_CE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_COMPLETED_CE_SHIFT)) & BCH_STATUS0_CLR_COMPLETED_CE_MASK)

#define BCH_STATUS0_CLR_HANDLE_MASK              (0xFFF00000U)
#define BCH_STATUS0_CLR_HANDLE_SHIFT             (20U)
#define BCH_STATUS0_CLR_HANDLE(x)                (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_CLR_HANDLE_SHIFT)) & BCH_STATUS0_CLR_HANDLE_MASK)
/*! @} */

/*! @name STATUS0_TOG - Hardware ECC Accelerator Status Register 0 */
/*! @{ */

#define BCH_STATUS0_TOG_RSVD0_MASK               (0x3U)
#define BCH_STATUS0_TOG_RSVD0_SHIFT              (0U)
/*! RSVD0 - This field is reserved. */
#define BCH_STATUS0_TOG_RSVD0(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_RSVD0_SHIFT)) & BCH_STATUS0_TOG_RSVD0_MASK)

#define BCH_STATUS0_TOG_UNCORRECTABLE_MASK       (0x4U)
#define BCH_STATUS0_TOG_UNCORRECTABLE_SHIFT      (2U)
#define BCH_STATUS0_TOG_UNCORRECTABLE(x)         (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_UNCORRECTABLE_SHIFT)) & BCH_STATUS0_TOG_UNCORRECTABLE_MASK)

#define BCH_STATUS0_TOG_CORRECTED_MASK           (0x8U)
#define BCH_STATUS0_TOG_CORRECTED_SHIFT          (3U)
#define BCH_STATUS0_TOG_CORRECTED(x)             (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_CORRECTED_SHIFT)) & BCH_STATUS0_TOG_CORRECTED_MASK)

#define BCH_STATUS0_TOG_ALLONES_MASK             (0x10U)
#define BCH_STATUS0_TOG_ALLONES_SHIFT            (4U)
#define BCH_STATUS0_TOG_ALLONES(x)               (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_ALLONES_SHIFT)) & BCH_STATUS0_TOG_ALLONES_MASK)

#define BCH_STATUS0_TOG_RSVD1_MASK               (0xE0U)
#define BCH_STATUS0_TOG_RSVD1_SHIFT              (5U)
/*! RSVD1 - This field is reserved. */
#define BCH_STATUS0_TOG_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_RSVD1_SHIFT)) & BCH_STATUS0_TOG_RSVD1_MASK)

#define BCH_STATUS0_TOG_STATUS_BLK0_MASK         (0xFF00U)
#define BCH_STATUS0_TOG_STATUS_BLK0_SHIFT        (8U)
/*! STATUS_BLK0
 *  0b00000000..No errors found on block.
 *  0b00000001..One error found on block.
 *  0b00000010..One errors found on block.
 *  0b00000011..One errors found on block.
 *  0b00000100..One errors found on block.
 *  0b11111110..Block exhibited uncorrectable errors.
 *  0b11111111..Page is erased.
 */
#define BCH_STATUS0_TOG_STATUS_BLK0(x)           (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_STATUS_BLK0_SHIFT)) & BCH_STATUS0_TOG_STATUS_BLK0_MASK)

#define BCH_STATUS0_TOG_COMPLETED_CE_MASK        (0xF0000U)
#define BCH_STATUS0_TOG_COMPLETED_CE_SHIFT       (16U)
#define BCH_STATUS0_TOG_COMPLETED_CE(x)          (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_COMPLETED_CE_SHIFT)) & BCH_STATUS0_TOG_COMPLETED_CE_MASK)

#define BCH_STATUS0_TOG_HANDLE_MASK              (0xFFF00000U)
#define BCH_STATUS0_TOG_HANDLE_SHIFT             (20U)
#define BCH_STATUS0_TOG_HANDLE(x)                (((uint32_t)(((uint32_t)(x)) << BCH_STATUS0_TOG_HANDLE_SHIFT)) & BCH_STATUS0_TOG_HANDLE_MASK)
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

/*! @name MODE_SET - Hardware ECC Accelerator Mode Register */
/*! @{ */

#define BCH_MODE_SET_ERASE_THRESHOLD_MASK        (0xFFU)
#define BCH_MODE_SET_ERASE_THRESHOLD_SHIFT       (0U)
#define BCH_MODE_SET_ERASE_THRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << BCH_MODE_SET_ERASE_THRESHOLD_SHIFT)) & BCH_MODE_SET_ERASE_THRESHOLD_MASK)

#define BCH_MODE_SET_RSVD_MASK                   (0xFFFFFF00U)
#define BCH_MODE_SET_RSVD_SHIFT                  (8U)
/*! RSVD - This field is reserved. */
#define BCH_MODE_SET_RSVD(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_MODE_SET_RSVD_SHIFT)) & BCH_MODE_SET_RSVD_MASK)
/*! @} */

/*! @name MODE_CLR - Hardware ECC Accelerator Mode Register */
/*! @{ */

#define BCH_MODE_CLR_ERASE_THRESHOLD_MASK        (0xFFU)
#define BCH_MODE_CLR_ERASE_THRESHOLD_SHIFT       (0U)
#define BCH_MODE_CLR_ERASE_THRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << BCH_MODE_CLR_ERASE_THRESHOLD_SHIFT)) & BCH_MODE_CLR_ERASE_THRESHOLD_MASK)

#define BCH_MODE_CLR_RSVD_MASK                   (0xFFFFFF00U)
#define BCH_MODE_CLR_RSVD_SHIFT                  (8U)
/*! RSVD - This field is reserved. */
#define BCH_MODE_CLR_RSVD(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_MODE_CLR_RSVD_SHIFT)) & BCH_MODE_CLR_RSVD_MASK)
/*! @} */

/*! @name MODE_TOG - Hardware ECC Accelerator Mode Register */
/*! @{ */

#define BCH_MODE_TOG_ERASE_THRESHOLD_MASK        (0xFFU)
#define BCH_MODE_TOG_ERASE_THRESHOLD_SHIFT       (0U)
#define BCH_MODE_TOG_ERASE_THRESHOLD(x)          (((uint32_t)(((uint32_t)(x)) << BCH_MODE_TOG_ERASE_THRESHOLD_SHIFT)) & BCH_MODE_TOG_ERASE_THRESHOLD_MASK)

#define BCH_MODE_TOG_RSVD_MASK                   (0xFFFFFF00U)
#define BCH_MODE_TOG_RSVD_SHIFT                  (8U)
/*! RSVD - This field is reserved. */
#define BCH_MODE_TOG_RSVD(x)                     (((uint32_t)(((uint32_t)(x)) << BCH_MODE_TOG_RSVD_SHIFT)) & BCH_MODE_TOG_RSVD_MASK)
/*! @} */

/*! @name ENCODEPTR - Hardware BCH ECC Loopback Encode Buffer Register */
/*! @{ */

#define BCH_ENCODEPTR_ADDR_MASK                  (0xFFFFFFFFU)
#define BCH_ENCODEPTR_ADDR_SHIFT                 (0U)
#define BCH_ENCODEPTR_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_ENCODEPTR_ADDR_SHIFT)) & BCH_ENCODEPTR_ADDR_MASK)
/*! @} */

/*! @name ENCODEPTR_SET - Hardware BCH ECC Loopback Encode Buffer Register */
/*! @{ */

#define BCH_ENCODEPTR_SET_ADDR_MASK              (0xFFFFFFFFU)
#define BCH_ENCODEPTR_SET_ADDR_SHIFT             (0U)
#define BCH_ENCODEPTR_SET_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << BCH_ENCODEPTR_SET_ADDR_SHIFT)) & BCH_ENCODEPTR_SET_ADDR_MASK)
/*! @} */

/*! @name ENCODEPTR_CLR - Hardware BCH ECC Loopback Encode Buffer Register */
/*! @{ */

#define BCH_ENCODEPTR_CLR_ADDR_MASK              (0xFFFFFFFFU)
#define BCH_ENCODEPTR_CLR_ADDR_SHIFT             (0U)
#define BCH_ENCODEPTR_CLR_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << BCH_ENCODEPTR_CLR_ADDR_SHIFT)) & BCH_ENCODEPTR_CLR_ADDR_MASK)
/*! @} */

/*! @name ENCODEPTR_TOG - Hardware BCH ECC Loopback Encode Buffer Register */
/*! @{ */

#define BCH_ENCODEPTR_TOG_ADDR_MASK              (0xFFFFFFFFU)
#define BCH_ENCODEPTR_TOG_ADDR_SHIFT             (0U)
#define BCH_ENCODEPTR_TOG_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << BCH_ENCODEPTR_TOG_ADDR_SHIFT)) & BCH_ENCODEPTR_TOG_ADDR_MASK)
/*! @} */

/*! @name DATAPTR - Hardware BCH ECC Loopback Data Buffer Register */
/*! @{ */

#define BCH_DATAPTR_ADDR_MASK                    (0xFFFFFFFFU)
#define BCH_DATAPTR_ADDR_SHIFT                   (0U)
#define BCH_DATAPTR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_DATAPTR_ADDR_SHIFT)) & BCH_DATAPTR_ADDR_MASK)
/*! @} */

/*! @name DATAPTR_SET - Hardware BCH ECC Loopback Data Buffer Register */
/*! @{ */

#define BCH_DATAPTR_SET_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_DATAPTR_SET_ADDR_SHIFT               (0U)
#define BCH_DATAPTR_SET_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DATAPTR_SET_ADDR_SHIFT)) & BCH_DATAPTR_SET_ADDR_MASK)
/*! @} */

/*! @name DATAPTR_CLR - Hardware BCH ECC Loopback Data Buffer Register */
/*! @{ */

#define BCH_DATAPTR_CLR_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_DATAPTR_CLR_ADDR_SHIFT               (0U)
#define BCH_DATAPTR_CLR_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DATAPTR_CLR_ADDR_SHIFT)) & BCH_DATAPTR_CLR_ADDR_MASK)
/*! @} */

/*! @name DATAPTR_TOG - Hardware BCH ECC Loopback Data Buffer Register */
/*! @{ */

#define BCH_DATAPTR_TOG_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_DATAPTR_TOG_ADDR_SHIFT               (0U)
#define BCH_DATAPTR_TOG_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_DATAPTR_TOG_ADDR_SHIFT)) & BCH_DATAPTR_TOG_ADDR_MASK)
/*! @} */

/*! @name METAPTR - Hardware BCH ECC Loopback Metadata Buffer Register */
/*! @{ */

#define BCH_METAPTR_ADDR_MASK                    (0xFFFFFFFFU)
#define BCH_METAPTR_ADDR_SHIFT                   (0U)
#define BCH_METAPTR_ADDR(x)                      (((uint32_t)(((uint32_t)(x)) << BCH_METAPTR_ADDR_SHIFT)) & BCH_METAPTR_ADDR_MASK)
/*! @} */

/*! @name METAPTR_SET - Hardware BCH ECC Loopback Metadata Buffer Register */
/*! @{ */

#define BCH_METAPTR_SET_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_METAPTR_SET_ADDR_SHIFT               (0U)
#define BCH_METAPTR_SET_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_METAPTR_SET_ADDR_SHIFT)) & BCH_METAPTR_SET_ADDR_MASK)
/*! @} */

/*! @name METAPTR_CLR - Hardware BCH ECC Loopback Metadata Buffer Register */
/*! @{ */

#define BCH_METAPTR_CLR_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_METAPTR_CLR_ADDR_SHIFT               (0U)
#define BCH_METAPTR_CLR_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_METAPTR_CLR_ADDR_SHIFT)) & BCH_METAPTR_CLR_ADDR_MASK)
/*! @} */

/*! @name METAPTR_TOG - Hardware BCH ECC Loopback Metadata Buffer Register */
/*! @{ */

#define BCH_METAPTR_TOG_ADDR_MASK                (0xFFFFFFFFU)
#define BCH_METAPTR_TOG_ADDR_SHIFT               (0U)
#define BCH_METAPTR_TOG_ADDR(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_METAPTR_TOG_ADDR_SHIFT)) & BCH_METAPTR_TOG_ADDR_MASK)
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

/*! @name LAYOUTSELECT_SET - Hardware ECC Accelerator Layout Select Register */
/*! @{ */

#define BCH_LAYOUTSELECT_SET_CS0_SELECT_MASK     (0x3U)
#define BCH_LAYOUTSELECT_SET_CS0_SELECT_SHIFT    (0U)
#define BCH_LAYOUTSELECT_SET_CS0_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS0_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS0_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS1_SELECT_MASK     (0xCU)
#define BCH_LAYOUTSELECT_SET_CS1_SELECT_SHIFT    (2U)
#define BCH_LAYOUTSELECT_SET_CS1_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS1_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS1_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS2_SELECT_MASK     (0x30U)
#define BCH_LAYOUTSELECT_SET_CS2_SELECT_SHIFT    (4U)
#define BCH_LAYOUTSELECT_SET_CS2_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS2_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS2_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS3_SELECT_MASK     (0xC0U)
#define BCH_LAYOUTSELECT_SET_CS3_SELECT_SHIFT    (6U)
#define BCH_LAYOUTSELECT_SET_CS3_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS3_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS3_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS4_SELECT_MASK     (0x300U)
#define BCH_LAYOUTSELECT_SET_CS4_SELECT_SHIFT    (8U)
#define BCH_LAYOUTSELECT_SET_CS4_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS4_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS4_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS5_SELECT_MASK     (0xC00U)
#define BCH_LAYOUTSELECT_SET_CS5_SELECT_SHIFT    (10U)
#define BCH_LAYOUTSELECT_SET_CS5_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS5_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS5_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS6_SELECT_MASK     (0x3000U)
#define BCH_LAYOUTSELECT_SET_CS6_SELECT_SHIFT    (12U)
#define BCH_LAYOUTSELECT_SET_CS6_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS6_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS6_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS7_SELECT_MASK     (0xC000U)
#define BCH_LAYOUTSELECT_SET_CS7_SELECT_SHIFT    (14U)
#define BCH_LAYOUTSELECT_SET_CS7_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS7_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS7_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS8_SELECT_MASK     (0x30000U)
#define BCH_LAYOUTSELECT_SET_CS8_SELECT_SHIFT    (16U)
#define BCH_LAYOUTSELECT_SET_CS8_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS8_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS8_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS9_SELECT_MASK     (0xC0000U)
#define BCH_LAYOUTSELECT_SET_CS9_SELECT_SHIFT    (18U)
#define BCH_LAYOUTSELECT_SET_CS9_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS9_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS9_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS10_SELECT_MASK    (0x300000U)
#define BCH_LAYOUTSELECT_SET_CS10_SELECT_SHIFT   (20U)
#define BCH_LAYOUTSELECT_SET_CS10_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS10_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS10_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS11_SELECT_MASK    (0xC00000U)
#define BCH_LAYOUTSELECT_SET_CS11_SELECT_SHIFT   (22U)
#define BCH_LAYOUTSELECT_SET_CS11_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS11_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS11_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS12_SELECT_MASK    (0x3000000U)
#define BCH_LAYOUTSELECT_SET_CS12_SELECT_SHIFT   (24U)
#define BCH_LAYOUTSELECT_SET_CS12_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS12_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS12_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS13_SELECT_MASK    (0xC000000U)
#define BCH_LAYOUTSELECT_SET_CS13_SELECT_SHIFT   (26U)
#define BCH_LAYOUTSELECT_SET_CS13_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS13_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS13_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS14_SELECT_MASK    (0x30000000U)
#define BCH_LAYOUTSELECT_SET_CS14_SELECT_SHIFT   (28U)
#define BCH_LAYOUTSELECT_SET_CS14_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS14_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS14_SELECT_MASK)

#define BCH_LAYOUTSELECT_SET_CS15_SELECT_MASK    (0xC0000000U)
#define BCH_LAYOUTSELECT_SET_CS15_SELECT_SHIFT   (30U)
#define BCH_LAYOUTSELECT_SET_CS15_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_SET_CS15_SELECT_SHIFT)) & BCH_LAYOUTSELECT_SET_CS15_SELECT_MASK)
/*! @} */

/*! @name LAYOUTSELECT_CLR - Hardware ECC Accelerator Layout Select Register */
/*! @{ */

#define BCH_LAYOUTSELECT_CLR_CS0_SELECT_MASK     (0x3U)
#define BCH_LAYOUTSELECT_CLR_CS0_SELECT_SHIFT    (0U)
#define BCH_LAYOUTSELECT_CLR_CS0_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS0_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS0_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS1_SELECT_MASK     (0xCU)
#define BCH_LAYOUTSELECT_CLR_CS1_SELECT_SHIFT    (2U)
#define BCH_LAYOUTSELECT_CLR_CS1_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS1_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS1_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS2_SELECT_MASK     (0x30U)
#define BCH_LAYOUTSELECT_CLR_CS2_SELECT_SHIFT    (4U)
#define BCH_LAYOUTSELECT_CLR_CS2_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS2_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS2_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS3_SELECT_MASK     (0xC0U)
#define BCH_LAYOUTSELECT_CLR_CS3_SELECT_SHIFT    (6U)
#define BCH_LAYOUTSELECT_CLR_CS3_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS3_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS3_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS4_SELECT_MASK     (0x300U)
#define BCH_LAYOUTSELECT_CLR_CS4_SELECT_SHIFT    (8U)
#define BCH_LAYOUTSELECT_CLR_CS4_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS4_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS4_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS5_SELECT_MASK     (0xC00U)
#define BCH_LAYOUTSELECT_CLR_CS5_SELECT_SHIFT    (10U)
#define BCH_LAYOUTSELECT_CLR_CS5_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS5_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS5_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS6_SELECT_MASK     (0x3000U)
#define BCH_LAYOUTSELECT_CLR_CS6_SELECT_SHIFT    (12U)
#define BCH_LAYOUTSELECT_CLR_CS6_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS6_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS6_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS7_SELECT_MASK     (0xC000U)
#define BCH_LAYOUTSELECT_CLR_CS7_SELECT_SHIFT    (14U)
#define BCH_LAYOUTSELECT_CLR_CS7_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS7_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS7_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS8_SELECT_MASK     (0x30000U)
#define BCH_LAYOUTSELECT_CLR_CS8_SELECT_SHIFT    (16U)
#define BCH_LAYOUTSELECT_CLR_CS8_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS8_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS8_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS9_SELECT_MASK     (0xC0000U)
#define BCH_LAYOUTSELECT_CLR_CS9_SELECT_SHIFT    (18U)
#define BCH_LAYOUTSELECT_CLR_CS9_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS9_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS9_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS10_SELECT_MASK    (0x300000U)
#define BCH_LAYOUTSELECT_CLR_CS10_SELECT_SHIFT   (20U)
#define BCH_LAYOUTSELECT_CLR_CS10_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS10_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS10_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS11_SELECT_MASK    (0xC00000U)
#define BCH_LAYOUTSELECT_CLR_CS11_SELECT_SHIFT   (22U)
#define BCH_LAYOUTSELECT_CLR_CS11_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS11_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS11_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS12_SELECT_MASK    (0x3000000U)
#define BCH_LAYOUTSELECT_CLR_CS12_SELECT_SHIFT   (24U)
#define BCH_LAYOUTSELECT_CLR_CS12_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS12_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS12_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS13_SELECT_MASK    (0xC000000U)
#define BCH_LAYOUTSELECT_CLR_CS13_SELECT_SHIFT   (26U)
#define BCH_LAYOUTSELECT_CLR_CS13_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS13_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS13_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS14_SELECT_MASK    (0x30000000U)
#define BCH_LAYOUTSELECT_CLR_CS14_SELECT_SHIFT   (28U)
#define BCH_LAYOUTSELECT_CLR_CS14_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS14_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS14_SELECT_MASK)

#define BCH_LAYOUTSELECT_CLR_CS15_SELECT_MASK    (0xC0000000U)
#define BCH_LAYOUTSELECT_CLR_CS15_SELECT_SHIFT   (30U)
#define BCH_LAYOUTSELECT_CLR_CS15_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_CLR_CS15_SELECT_SHIFT)) & BCH_LAYOUTSELECT_CLR_CS15_SELECT_MASK)
/*! @} */

/*! @name LAYOUTSELECT_TOG - Hardware ECC Accelerator Layout Select Register */
/*! @{ */

#define BCH_LAYOUTSELECT_TOG_CS0_SELECT_MASK     (0x3U)
#define BCH_LAYOUTSELECT_TOG_CS0_SELECT_SHIFT    (0U)
#define BCH_LAYOUTSELECT_TOG_CS0_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS0_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS0_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS1_SELECT_MASK     (0xCU)
#define BCH_LAYOUTSELECT_TOG_CS1_SELECT_SHIFT    (2U)
#define BCH_LAYOUTSELECT_TOG_CS1_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS1_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS1_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS2_SELECT_MASK     (0x30U)
#define BCH_LAYOUTSELECT_TOG_CS2_SELECT_SHIFT    (4U)
#define BCH_LAYOUTSELECT_TOG_CS2_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS2_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS2_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS3_SELECT_MASK     (0xC0U)
#define BCH_LAYOUTSELECT_TOG_CS3_SELECT_SHIFT    (6U)
#define BCH_LAYOUTSELECT_TOG_CS3_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS3_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS3_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS4_SELECT_MASK     (0x300U)
#define BCH_LAYOUTSELECT_TOG_CS4_SELECT_SHIFT    (8U)
#define BCH_LAYOUTSELECT_TOG_CS4_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS4_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS4_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS5_SELECT_MASK     (0xC00U)
#define BCH_LAYOUTSELECT_TOG_CS5_SELECT_SHIFT    (10U)
#define BCH_LAYOUTSELECT_TOG_CS5_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS5_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS5_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS6_SELECT_MASK     (0x3000U)
#define BCH_LAYOUTSELECT_TOG_CS6_SELECT_SHIFT    (12U)
#define BCH_LAYOUTSELECT_TOG_CS6_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS6_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS6_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS7_SELECT_MASK     (0xC000U)
#define BCH_LAYOUTSELECT_TOG_CS7_SELECT_SHIFT    (14U)
#define BCH_LAYOUTSELECT_TOG_CS7_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS7_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS7_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS8_SELECT_MASK     (0x30000U)
#define BCH_LAYOUTSELECT_TOG_CS8_SELECT_SHIFT    (16U)
#define BCH_LAYOUTSELECT_TOG_CS8_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS8_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS8_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS9_SELECT_MASK     (0xC0000U)
#define BCH_LAYOUTSELECT_TOG_CS9_SELECT_SHIFT    (18U)
#define BCH_LAYOUTSELECT_TOG_CS9_SELECT(x)       (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS9_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS9_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS10_SELECT_MASK    (0x300000U)
#define BCH_LAYOUTSELECT_TOG_CS10_SELECT_SHIFT   (20U)
#define BCH_LAYOUTSELECT_TOG_CS10_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS10_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS10_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS11_SELECT_MASK    (0xC00000U)
#define BCH_LAYOUTSELECT_TOG_CS11_SELECT_SHIFT   (22U)
#define BCH_LAYOUTSELECT_TOG_CS11_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS11_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS11_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS12_SELECT_MASK    (0x3000000U)
#define BCH_LAYOUTSELECT_TOG_CS12_SELECT_SHIFT   (24U)
#define BCH_LAYOUTSELECT_TOG_CS12_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS12_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS12_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS13_SELECT_MASK    (0xC000000U)
#define BCH_LAYOUTSELECT_TOG_CS13_SELECT_SHIFT   (26U)
#define BCH_LAYOUTSELECT_TOG_CS13_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS13_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS13_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS14_SELECT_MASK    (0x30000000U)
#define BCH_LAYOUTSELECT_TOG_CS14_SELECT_SHIFT   (28U)
#define BCH_LAYOUTSELECT_TOG_CS14_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS14_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS14_SELECT_MASK)

#define BCH_LAYOUTSELECT_TOG_CS15_SELECT_MASK    (0xC0000000U)
#define BCH_LAYOUTSELECT_TOG_CS15_SELECT_SHIFT   (30U)
#define BCH_LAYOUTSELECT_TOG_CS15_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_LAYOUTSELECT_TOG_CS15_SELECT_SHIFT)) & BCH_LAYOUTSELECT_TOG_CS15_SELECT_MASK)
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

/*! @name FLASH0LAYOUT0_SET - Hardware BCH ECC Flash 0 Layout 0 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT0_SET_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT0_SET_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT0_SET_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_SET_DATA0_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_SET_DATA0_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT0_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT0_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT0_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT0_SET_ECC0_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT0_SET_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT0_SET_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_SET_ECC0_SHIFT)) & BCH_FLASH0LAYOUT0_SET_ECC0_MASK)

#define BCH_FLASH0LAYOUT0_SET_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH0LAYOUT0_SET_META_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT0_SET_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_SET_META_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_SET_META_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_SET_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH0LAYOUT0_SET_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH0LAYOUT0_SET_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_SET_NBLOCKS_SHIFT)) & BCH_FLASH0LAYOUT0_SET_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH0LAYOUT0_CLR - Hardware BCH ECC Flash 0 Layout 0 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT0_CLR_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT0_CLR_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT0_CLR_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_CLR_DATA0_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_CLR_DATA0_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT0_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT0_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT0_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT0_CLR_ECC0_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT0_CLR_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT0_CLR_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_CLR_ECC0_SHIFT)) & BCH_FLASH0LAYOUT0_CLR_ECC0_MASK)

#define BCH_FLASH0LAYOUT0_CLR_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH0LAYOUT0_CLR_META_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT0_CLR_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_CLR_META_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_CLR_META_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_CLR_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH0LAYOUT0_CLR_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH0LAYOUT0_CLR_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_CLR_NBLOCKS_SHIFT)) & BCH_FLASH0LAYOUT0_CLR_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH0LAYOUT0_TOG - Hardware BCH ECC Flash 0 Layout 0 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT0_TOG_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT0_TOG_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT0_TOG_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_TOG_DATA0_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_TOG_DATA0_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT0_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT0_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT0_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT0_TOG_ECC0_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT0_TOG_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT0_TOG_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_TOG_ECC0_SHIFT)) & BCH_FLASH0LAYOUT0_TOG_ECC0_MASK)

#define BCH_FLASH0LAYOUT0_TOG_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH0LAYOUT0_TOG_META_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT0_TOG_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_TOG_META_SIZE_SHIFT)) & BCH_FLASH0LAYOUT0_TOG_META_SIZE_MASK)

#define BCH_FLASH0LAYOUT0_TOG_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH0LAYOUT0_TOG_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH0LAYOUT0_TOG_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT0_TOG_NBLOCKS_SHIFT)) & BCH_FLASH0LAYOUT0_TOG_NBLOCKS_MASK)
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

/*! @name FLASH0LAYOUT1_SET - Hardware BCH ECC Flash 0 Layout 1 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT1_SET_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT1_SET_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT1_SET_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_SET_DATAN_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_SET_DATAN_SIZE_MASK)

#define BCH_FLASH0LAYOUT1_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT1_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT1_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT1_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT1_SET_ECCN_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT1_SET_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT1_SET_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_SET_ECCN_SHIFT)) & BCH_FLASH0LAYOUT1_SET_ECCN_MASK)

#define BCH_FLASH0LAYOUT1_SET_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH0LAYOUT1_SET_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT1_SET_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_SET_PAGE_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_SET_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH0LAYOUT1_CLR - Hardware BCH ECC Flash 0 Layout 1 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT1_CLR_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT1_CLR_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT1_CLR_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_CLR_DATAN_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_CLR_DATAN_SIZE_MASK)

#define BCH_FLASH0LAYOUT1_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT1_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT1_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT1_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT1_CLR_ECCN_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT1_CLR_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT1_CLR_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_CLR_ECCN_SHIFT)) & BCH_FLASH0LAYOUT1_CLR_ECCN_MASK)

#define BCH_FLASH0LAYOUT1_CLR_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH0LAYOUT1_CLR_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT1_CLR_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_CLR_PAGE_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_CLR_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH0LAYOUT1_TOG - Hardware BCH ECC Flash 0 Layout 1 Register */
/*! @{ */

#define BCH_FLASH0LAYOUT1_TOG_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH0LAYOUT1_TOG_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH0LAYOUT1_TOG_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_TOG_DATAN_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_TOG_DATAN_SIZE_MASK)

#define BCH_FLASH0LAYOUT1_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH0LAYOUT1_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH0LAYOUT1_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH0LAYOUT1_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH0LAYOUT1_TOG_ECCN_MASK          (0xF800U)
#define BCH_FLASH0LAYOUT1_TOG_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH0LAYOUT1_TOG_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_TOG_ECCN_SHIFT)) & BCH_FLASH0LAYOUT1_TOG_ECCN_MASK)

#define BCH_FLASH0LAYOUT1_TOG_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH0LAYOUT1_TOG_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH0LAYOUT1_TOG_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH0LAYOUT1_TOG_PAGE_SIZE_SHIFT)) & BCH_FLASH0LAYOUT1_TOG_PAGE_SIZE_MASK)
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

/*! @name FLASH1LAYOUT0_SET - Hardware BCH ECC Flash 1 Layout 0 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT0_SET_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT0_SET_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT0_SET_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_SET_DATA0_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_SET_DATA0_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT0_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT0_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT0_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT0_SET_ECC0_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT0_SET_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT0_SET_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_SET_ECC0_SHIFT)) & BCH_FLASH1LAYOUT0_SET_ECC0_MASK)

#define BCH_FLASH1LAYOUT0_SET_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH1LAYOUT0_SET_META_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT0_SET_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_SET_META_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_SET_META_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_SET_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH1LAYOUT0_SET_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH1LAYOUT0_SET_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_SET_NBLOCKS_SHIFT)) & BCH_FLASH1LAYOUT0_SET_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH1LAYOUT0_CLR - Hardware BCH ECC Flash 1 Layout 0 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT0_CLR_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT0_CLR_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT0_CLR_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_CLR_DATA0_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_CLR_DATA0_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT0_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT0_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT0_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT0_CLR_ECC0_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT0_CLR_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT0_CLR_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_CLR_ECC0_SHIFT)) & BCH_FLASH1LAYOUT0_CLR_ECC0_MASK)

#define BCH_FLASH1LAYOUT0_CLR_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH1LAYOUT0_CLR_META_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT0_CLR_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_CLR_META_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_CLR_META_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_CLR_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH1LAYOUT0_CLR_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH1LAYOUT0_CLR_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_CLR_NBLOCKS_SHIFT)) & BCH_FLASH1LAYOUT0_CLR_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH1LAYOUT0_TOG - Hardware BCH ECC Flash 1 Layout 0 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT0_TOG_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT0_TOG_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT0_TOG_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_TOG_DATA0_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_TOG_DATA0_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT0_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT0_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT0_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT0_TOG_ECC0_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT0_TOG_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT0_TOG_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_TOG_ECC0_SHIFT)) & BCH_FLASH1LAYOUT0_TOG_ECC0_MASK)

#define BCH_FLASH1LAYOUT0_TOG_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH1LAYOUT0_TOG_META_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT0_TOG_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_TOG_META_SIZE_SHIFT)) & BCH_FLASH1LAYOUT0_TOG_META_SIZE_MASK)

#define BCH_FLASH1LAYOUT0_TOG_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH1LAYOUT0_TOG_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH1LAYOUT0_TOG_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT0_TOG_NBLOCKS_SHIFT)) & BCH_FLASH1LAYOUT0_TOG_NBLOCKS_MASK)
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

/*! @name FLASH1LAYOUT1_SET - Hardware BCH ECC Flash 1 Layout 1 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT1_SET_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT1_SET_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT1_SET_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_SET_DATAN_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_SET_DATAN_SIZE_MASK)

#define BCH_FLASH1LAYOUT1_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT1_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT1_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT1_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT1_SET_ECCN_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT1_SET_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT1_SET_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_SET_ECCN_SHIFT)) & BCH_FLASH1LAYOUT1_SET_ECCN_MASK)

#define BCH_FLASH1LAYOUT1_SET_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH1LAYOUT1_SET_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT1_SET_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_SET_PAGE_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_SET_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH1LAYOUT1_CLR - Hardware BCH ECC Flash 1 Layout 1 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT1_CLR_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT1_CLR_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT1_CLR_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_CLR_DATAN_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_CLR_DATAN_SIZE_MASK)

#define BCH_FLASH1LAYOUT1_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT1_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT1_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT1_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT1_CLR_ECCN_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT1_CLR_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT1_CLR_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_CLR_ECCN_SHIFT)) & BCH_FLASH1LAYOUT1_CLR_ECCN_MASK)

#define BCH_FLASH1LAYOUT1_CLR_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH1LAYOUT1_CLR_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT1_CLR_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_CLR_PAGE_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_CLR_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH1LAYOUT1_TOG - Hardware BCH ECC Flash 1 Layout 1 Register */
/*! @{ */

#define BCH_FLASH1LAYOUT1_TOG_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH1LAYOUT1_TOG_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH1LAYOUT1_TOG_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_TOG_DATAN_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_TOG_DATAN_SIZE_MASK)

#define BCH_FLASH1LAYOUT1_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH1LAYOUT1_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH1LAYOUT1_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH1LAYOUT1_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH1LAYOUT1_TOG_ECCN_MASK          (0xF800U)
#define BCH_FLASH1LAYOUT1_TOG_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH1LAYOUT1_TOG_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_TOG_ECCN_SHIFT)) & BCH_FLASH1LAYOUT1_TOG_ECCN_MASK)

#define BCH_FLASH1LAYOUT1_TOG_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH1LAYOUT1_TOG_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH1LAYOUT1_TOG_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH1LAYOUT1_TOG_PAGE_SIZE_SHIFT)) & BCH_FLASH1LAYOUT1_TOG_PAGE_SIZE_MASK)
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

/*! @name FLASH2LAYOUT0_SET - Hardware BCH ECC Flash 2 Layout 0 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT0_SET_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT0_SET_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT0_SET_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_SET_DATA0_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_SET_DATA0_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT0_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT0_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT0_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT0_SET_ECC0_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT0_SET_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT0_SET_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_SET_ECC0_SHIFT)) & BCH_FLASH2LAYOUT0_SET_ECC0_MASK)

#define BCH_FLASH2LAYOUT0_SET_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH2LAYOUT0_SET_META_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT0_SET_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_SET_META_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_SET_META_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_SET_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH2LAYOUT0_SET_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH2LAYOUT0_SET_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_SET_NBLOCKS_SHIFT)) & BCH_FLASH2LAYOUT0_SET_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH2LAYOUT0_CLR - Hardware BCH ECC Flash 2 Layout 0 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT0_CLR_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT0_CLR_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT0_CLR_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_CLR_DATA0_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_CLR_DATA0_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT0_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT0_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT0_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT0_CLR_ECC0_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT0_CLR_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT0_CLR_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_CLR_ECC0_SHIFT)) & BCH_FLASH2LAYOUT0_CLR_ECC0_MASK)

#define BCH_FLASH2LAYOUT0_CLR_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH2LAYOUT0_CLR_META_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT0_CLR_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_CLR_META_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_CLR_META_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_CLR_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH2LAYOUT0_CLR_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH2LAYOUT0_CLR_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_CLR_NBLOCKS_SHIFT)) & BCH_FLASH2LAYOUT0_CLR_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH2LAYOUT0_TOG - Hardware BCH ECC Flash 2 Layout 0 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT0_TOG_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT0_TOG_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT0_TOG_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_TOG_DATA0_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_TOG_DATA0_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT0_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT0_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT0_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT0_TOG_ECC0_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT0_TOG_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT0_TOG_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_TOG_ECC0_SHIFT)) & BCH_FLASH2LAYOUT0_TOG_ECC0_MASK)

#define BCH_FLASH2LAYOUT0_TOG_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH2LAYOUT0_TOG_META_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT0_TOG_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_TOG_META_SIZE_SHIFT)) & BCH_FLASH2LAYOUT0_TOG_META_SIZE_MASK)

#define BCH_FLASH2LAYOUT0_TOG_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH2LAYOUT0_TOG_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH2LAYOUT0_TOG_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT0_TOG_NBLOCKS_SHIFT)) & BCH_FLASH2LAYOUT0_TOG_NBLOCKS_MASK)
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

/*! @name FLASH2LAYOUT1_SET - Hardware BCH ECC Flash 2 Layout 1 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT1_SET_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT1_SET_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT1_SET_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_SET_DATAN_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_SET_DATAN_SIZE_MASK)

#define BCH_FLASH2LAYOUT1_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT1_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT1_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT1_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT1_SET_ECCN_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT1_SET_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT1_SET_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_SET_ECCN_SHIFT)) & BCH_FLASH2LAYOUT1_SET_ECCN_MASK)

#define BCH_FLASH2LAYOUT1_SET_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH2LAYOUT1_SET_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT1_SET_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_SET_PAGE_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_SET_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH2LAYOUT1_CLR - Hardware BCH ECC Flash 2 Layout 1 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT1_CLR_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT1_CLR_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT1_CLR_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_CLR_DATAN_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_CLR_DATAN_SIZE_MASK)

#define BCH_FLASH2LAYOUT1_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT1_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT1_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT1_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT1_CLR_ECCN_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT1_CLR_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT1_CLR_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_CLR_ECCN_SHIFT)) & BCH_FLASH2LAYOUT1_CLR_ECCN_MASK)

#define BCH_FLASH2LAYOUT1_CLR_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH2LAYOUT1_CLR_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT1_CLR_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_CLR_PAGE_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_CLR_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH2LAYOUT1_TOG - Hardware BCH ECC Flash 2 Layout 1 Register */
/*! @{ */

#define BCH_FLASH2LAYOUT1_TOG_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH2LAYOUT1_TOG_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH2LAYOUT1_TOG_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_TOG_DATAN_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_TOG_DATAN_SIZE_MASK)

#define BCH_FLASH2LAYOUT1_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH2LAYOUT1_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH2LAYOUT1_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH2LAYOUT1_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH2LAYOUT1_TOG_ECCN_MASK          (0xF800U)
#define BCH_FLASH2LAYOUT1_TOG_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH2LAYOUT1_TOG_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_TOG_ECCN_SHIFT)) & BCH_FLASH2LAYOUT1_TOG_ECCN_MASK)

#define BCH_FLASH2LAYOUT1_TOG_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH2LAYOUT1_TOG_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH2LAYOUT1_TOG_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH2LAYOUT1_TOG_PAGE_SIZE_SHIFT)) & BCH_FLASH2LAYOUT1_TOG_PAGE_SIZE_MASK)
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

/*! @name FLASH3LAYOUT0_SET - Hardware BCH ECC Flash 3 Layout 0 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT0_SET_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT0_SET_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT0_SET_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_SET_DATA0_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_SET_DATA0_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT0_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT0_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT0_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT0_SET_ECC0_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT0_SET_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT0_SET_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_SET_ECC0_SHIFT)) & BCH_FLASH3LAYOUT0_SET_ECC0_MASK)

#define BCH_FLASH3LAYOUT0_SET_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH3LAYOUT0_SET_META_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT0_SET_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_SET_META_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_SET_META_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_SET_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH3LAYOUT0_SET_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH3LAYOUT0_SET_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_SET_NBLOCKS_SHIFT)) & BCH_FLASH3LAYOUT0_SET_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH3LAYOUT0_CLR - Hardware BCH ECC Flash 3 Layout 0 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT0_CLR_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT0_CLR_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT0_CLR_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_CLR_DATA0_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_CLR_DATA0_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT0_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT0_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT0_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT0_CLR_ECC0_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT0_CLR_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT0_CLR_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_CLR_ECC0_SHIFT)) & BCH_FLASH3LAYOUT0_CLR_ECC0_MASK)

#define BCH_FLASH3LAYOUT0_CLR_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH3LAYOUT0_CLR_META_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT0_CLR_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_CLR_META_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_CLR_META_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_CLR_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH3LAYOUT0_CLR_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH3LAYOUT0_CLR_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_CLR_NBLOCKS_SHIFT)) & BCH_FLASH3LAYOUT0_CLR_NBLOCKS_MASK)
/*! @} */

/*! @name FLASH3LAYOUT0_TOG - Hardware BCH ECC Flash 3 Layout 0 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT0_TOG_DATA0_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT0_TOG_DATA0_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT0_TOG_DATA0_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_TOG_DATA0_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_TOG_DATA0_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT0_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT0_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT0_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT0_TOG_ECC0_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT0_TOG_ECC0_SHIFT         (11U)
/*! ECC0
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT0_TOG_ECC0(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_TOG_ECC0_SHIFT)) & BCH_FLASH3LAYOUT0_TOG_ECC0_MASK)

#define BCH_FLASH3LAYOUT0_TOG_META_SIZE_MASK     (0xFF0000U)
#define BCH_FLASH3LAYOUT0_TOG_META_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT0_TOG_META_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_TOG_META_SIZE_SHIFT)) & BCH_FLASH3LAYOUT0_TOG_META_SIZE_MASK)

#define BCH_FLASH3LAYOUT0_TOG_NBLOCKS_MASK       (0xFF000000U)
#define BCH_FLASH3LAYOUT0_TOG_NBLOCKS_SHIFT      (24U)
#define BCH_FLASH3LAYOUT0_TOG_NBLOCKS(x)         (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT0_TOG_NBLOCKS_SHIFT)) & BCH_FLASH3LAYOUT0_TOG_NBLOCKS_MASK)
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

/*! @name FLASH3LAYOUT1_SET - Hardware BCH ECC Flash 3 Layout 1 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT1_SET_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT1_SET_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT1_SET_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_SET_DATAN_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_SET_DATAN_SIZE_MASK)

#define BCH_FLASH3LAYOUT1_SET_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT1_SET_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT1_SET_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_SET_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT1_SET_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT1_SET_ECCN_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT1_SET_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT1_SET_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_SET_ECCN_SHIFT)) & BCH_FLASH3LAYOUT1_SET_ECCN_MASK)

#define BCH_FLASH3LAYOUT1_SET_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH3LAYOUT1_SET_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT1_SET_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_SET_PAGE_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_SET_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH3LAYOUT1_CLR - Hardware BCH ECC Flash 3 Layout 1 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT1_CLR_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT1_CLR_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT1_CLR_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_CLR_DATAN_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_CLR_DATAN_SIZE_MASK)

#define BCH_FLASH3LAYOUT1_CLR_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT1_CLR_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT1_CLR_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_CLR_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT1_CLR_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT1_CLR_ECCN_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT1_CLR_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT1_CLR_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_CLR_ECCN_SHIFT)) & BCH_FLASH3LAYOUT1_CLR_ECCN_MASK)

#define BCH_FLASH3LAYOUT1_CLR_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH3LAYOUT1_CLR_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT1_CLR_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_CLR_PAGE_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_CLR_PAGE_SIZE_MASK)
/*! @} */

/*! @name FLASH3LAYOUT1_TOG - Hardware BCH ECC Flash 3 Layout 1 Register */
/*! @{ */

#define BCH_FLASH3LAYOUT1_TOG_DATAN_SIZE_MASK    (0x3FFU)
#define BCH_FLASH3LAYOUT1_TOG_DATAN_SIZE_SHIFT   (0U)
#define BCH_FLASH3LAYOUT1_TOG_DATAN_SIZE(x)      (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_TOG_DATAN_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_TOG_DATAN_SIZE_MASK)

#define BCH_FLASH3LAYOUT1_TOG_GF13_0_GF14_1_MASK (0x400U)
#define BCH_FLASH3LAYOUT1_TOG_GF13_0_GF14_1_SHIFT (10U)
#define BCH_FLASH3LAYOUT1_TOG_GF13_0_GF14_1(x)   (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_TOG_GF13_0_GF14_1_SHIFT)) & BCH_FLASH3LAYOUT1_TOG_GF13_0_GF14_1_MASK)

#define BCH_FLASH3LAYOUT1_TOG_ECCN_MASK          (0xF800U)
#define BCH_FLASH3LAYOUT1_TOG_ECCN_SHIFT         (11U)
/*! ECCN
 *  0b00000..No ECC to be performed
 *  0b00001..ECC 2 to be performed
 *  0b00010..ECC 4 to be performed
 *  0b11110..ECC 60 to be performed
 *  0b11111..ECC 62 to be performed
 */
#define BCH_FLASH3LAYOUT1_TOG_ECCN(x)            (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_TOG_ECCN_SHIFT)) & BCH_FLASH3LAYOUT1_TOG_ECCN_MASK)

#define BCH_FLASH3LAYOUT1_TOG_PAGE_SIZE_MASK     (0xFFFF0000U)
#define BCH_FLASH3LAYOUT1_TOG_PAGE_SIZE_SHIFT    (16U)
#define BCH_FLASH3LAYOUT1_TOG_PAGE_SIZE(x)       (((uint32_t)(((uint32_t)(x)) << BCH_FLASH3LAYOUT1_TOG_PAGE_SIZE_SHIFT)) & BCH_FLASH3LAYOUT1_TOG_PAGE_SIZE_MASK)
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

/*! @name DBGKESREAD_SET - KES Debug Read Register */
/*! @{ */

#define BCH_DBGKESREAD_SET_VALUES_MASK           (0xFFFFFFFFU)
#define BCH_DBGKESREAD_SET_VALUES_SHIFT          (0U)
#define BCH_DBGKESREAD_SET_VALUES(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DBGKESREAD_SET_VALUES_SHIFT)) & BCH_DBGKESREAD_SET_VALUES_MASK)
/*! @} */

/*! @name DBGKESREAD_CLR - KES Debug Read Register */
/*! @{ */

#define BCH_DBGKESREAD_CLR_VALUES_MASK           (0xFFFFFFFFU)
#define BCH_DBGKESREAD_CLR_VALUES_SHIFT          (0U)
#define BCH_DBGKESREAD_CLR_VALUES(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DBGKESREAD_CLR_VALUES_SHIFT)) & BCH_DBGKESREAD_CLR_VALUES_MASK)
/*! @} */

/*! @name DBGKESREAD_TOG - KES Debug Read Register */
/*! @{ */

#define BCH_DBGKESREAD_TOG_VALUES_MASK           (0xFFFFFFFFU)
#define BCH_DBGKESREAD_TOG_VALUES_SHIFT          (0U)
#define BCH_DBGKESREAD_TOG_VALUES(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DBGKESREAD_TOG_VALUES_SHIFT)) & BCH_DBGKESREAD_TOG_VALUES_MASK)
/*! @} */

/*! @name DBGCSFEREAD - Chien Search Debug Read Register */
/*! @{ */

#define BCH_DBGCSFEREAD_VALUES_MASK              (0xFFFFFFFFU)
#define BCH_DBGCSFEREAD_VALUES_SHIFT             (0U)
#define BCH_DBGCSFEREAD_VALUES(x)                (((uint32_t)(((uint32_t)(x)) << BCH_DBGCSFEREAD_VALUES_SHIFT)) & BCH_DBGCSFEREAD_VALUES_MASK)
/*! @} */

/*! @name DBGCSFEREAD_SET - Chien Search Debug Read Register */
/*! @{ */

#define BCH_DBGCSFEREAD_SET_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGCSFEREAD_SET_VALUES_SHIFT         (0U)
#define BCH_DBGCSFEREAD_SET_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGCSFEREAD_SET_VALUES_SHIFT)) & BCH_DBGCSFEREAD_SET_VALUES_MASK)
/*! @} */

/*! @name DBGCSFEREAD_CLR - Chien Search Debug Read Register */
/*! @{ */

#define BCH_DBGCSFEREAD_CLR_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGCSFEREAD_CLR_VALUES_SHIFT         (0U)
#define BCH_DBGCSFEREAD_CLR_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGCSFEREAD_CLR_VALUES_SHIFT)) & BCH_DBGCSFEREAD_CLR_VALUES_MASK)
/*! @} */

/*! @name DBGCSFEREAD_TOG - Chien Search Debug Read Register */
/*! @{ */

#define BCH_DBGCSFEREAD_TOG_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGCSFEREAD_TOG_VALUES_SHIFT         (0U)
#define BCH_DBGCSFEREAD_TOG_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGCSFEREAD_TOG_VALUES_SHIFT)) & BCH_DBGCSFEREAD_TOG_VALUES_MASK)
/*! @} */

/*! @name DBGSYNDGENREAD - Syndrome Generator Debug Read Register */
/*! @{ */

#define BCH_DBGSYNDGENREAD_VALUES_MASK           (0xFFFFFFFFU)
#define BCH_DBGSYNDGENREAD_VALUES_SHIFT          (0U)
#define BCH_DBGSYNDGENREAD_VALUES(x)             (((uint32_t)(((uint32_t)(x)) << BCH_DBGSYNDGENREAD_VALUES_SHIFT)) & BCH_DBGSYNDGENREAD_VALUES_MASK)
/*! @} */

/*! @name DBGSYNDGENREAD_SET - Syndrome Generator Debug Read Register */
/*! @{ */

#define BCH_DBGSYNDGENREAD_SET_VALUES_MASK       (0xFFFFFFFFU)
#define BCH_DBGSYNDGENREAD_SET_VALUES_SHIFT      (0U)
#define BCH_DBGSYNDGENREAD_SET_VALUES(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DBGSYNDGENREAD_SET_VALUES_SHIFT)) & BCH_DBGSYNDGENREAD_SET_VALUES_MASK)
/*! @} */

/*! @name DBGSYNDGENREAD_CLR - Syndrome Generator Debug Read Register */
/*! @{ */

#define BCH_DBGSYNDGENREAD_CLR_VALUES_MASK       (0xFFFFFFFFU)
#define BCH_DBGSYNDGENREAD_CLR_VALUES_SHIFT      (0U)
#define BCH_DBGSYNDGENREAD_CLR_VALUES(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DBGSYNDGENREAD_CLR_VALUES_SHIFT)) & BCH_DBGSYNDGENREAD_CLR_VALUES_MASK)
/*! @} */

/*! @name DBGSYNDGENREAD_TOG - Syndrome Generator Debug Read Register */
/*! @{ */

#define BCH_DBGSYNDGENREAD_TOG_VALUES_MASK       (0xFFFFFFFFU)
#define BCH_DBGSYNDGENREAD_TOG_VALUES_SHIFT      (0U)
#define BCH_DBGSYNDGENREAD_TOG_VALUES(x)         (((uint32_t)(((uint32_t)(x)) << BCH_DBGSYNDGENREAD_TOG_VALUES_SHIFT)) & BCH_DBGSYNDGENREAD_TOG_VALUES_MASK)
/*! @} */

/*! @name DBGAHBMREAD - Bus Master and ECC Controller Debug Read Register */
/*! @{ */

#define BCH_DBGAHBMREAD_VALUES_MASK              (0xFFFFFFFFU)
#define BCH_DBGAHBMREAD_VALUES_SHIFT             (0U)
#define BCH_DBGAHBMREAD_VALUES(x)                (((uint32_t)(((uint32_t)(x)) << BCH_DBGAHBMREAD_VALUES_SHIFT)) & BCH_DBGAHBMREAD_VALUES_MASK)
/*! @} */

/*! @name DBGAHBMREAD_SET - Bus Master and ECC Controller Debug Read Register */
/*! @{ */

#define BCH_DBGAHBMREAD_SET_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGAHBMREAD_SET_VALUES_SHIFT         (0U)
#define BCH_DBGAHBMREAD_SET_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGAHBMREAD_SET_VALUES_SHIFT)) & BCH_DBGAHBMREAD_SET_VALUES_MASK)
/*! @} */

/*! @name DBGAHBMREAD_CLR - Bus Master and ECC Controller Debug Read Register */
/*! @{ */

#define BCH_DBGAHBMREAD_CLR_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGAHBMREAD_CLR_VALUES_SHIFT         (0U)
#define BCH_DBGAHBMREAD_CLR_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGAHBMREAD_CLR_VALUES_SHIFT)) & BCH_DBGAHBMREAD_CLR_VALUES_MASK)
/*! @} */

/*! @name DBGAHBMREAD_TOG - Bus Master and ECC Controller Debug Read Register */
/*! @{ */

#define BCH_DBGAHBMREAD_TOG_VALUES_MASK          (0xFFFFFFFFU)
#define BCH_DBGAHBMREAD_TOG_VALUES_SHIFT         (0U)
#define BCH_DBGAHBMREAD_TOG_VALUES(x)            (((uint32_t)(((uint32_t)(x)) << BCH_DBGAHBMREAD_TOG_VALUES_SHIFT)) & BCH_DBGAHBMREAD_TOG_VALUES_MASK)
/*! @} */

/*! @name BLOCKNAME - Block Name Register */
/*! @{ */

#define BCH_BLOCKNAME_NAME_MASK                  (0xFFFFFFFFU)
#define BCH_BLOCKNAME_NAME_SHIFT                 (0U)
#define BCH_BLOCKNAME_NAME(x)                    (((uint32_t)(((uint32_t)(x)) << BCH_BLOCKNAME_NAME_SHIFT)) & BCH_BLOCKNAME_NAME_MASK)
/*! @} */

/*! @name BLOCKNAME_SET - Block Name Register */
/*! @{ */

#define BCH_BLOCKNAME_SET_NAME_MASK              (0xFFFFFFFFU)
#define BCH_BLOCKNAME_SET_NAME_SHIFT             (0U)
#define BCH_BLOCKNAME_SET_NAME(x)                (((uint32_t)(((uint32_t)(x)) << BCH_BLOCKNAME_SET_NAME_SHIFT)) & BCH_BLOCKNAME_SET_NAME_MASK)
/*! @} */

/*! @name BLOCKNAME_CLR - Block Name Register */
/*! @{ */

#define BCH_BLOCKNAME_CLR_NAME_MASK              (0xFFFFFFFFU)
#define BCH_BLOCKNAME_CLR_NAME_SHIFT             (0U)
#define BCH_BLOCKNAME_CLR_NAME(x)                (((uint32_t)(((uint32_t)(x)) << BCH_BLOCKNAME_CLR_NAME_SHIFT)) & BCH_BLOCKNAME_CLR_NAME_MASK)
/*! @} */

/*! @name BLOCKNAME_TOG - Block Name Register */
/*! @{ */

#define BCH_BLOCKNAME_TOG_NAME_MASK              (0xFFFFFFFFU)
#define BCH_BLOCKNAME_TOG_NAME_SHIFT             (0U)
#define BCH_BLOCKNAME_TOG_NAME(x)                (((uint32_t)(((uint32_t)(x)) << BCH_BLOCKNAME_TOG_NAME_SHIFT)) & BCH_BLOCKNAME_TOG_NAME_MASK)
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

/*! @name VERSION_SET - BCH Version Register */
/*! @{ */

#define BCH_VERSION_SET_STEP_MASK                (0xFFFFU)
#define BCH_VERSION_SET_STEP_SHIFT               (0U)
#define BCH_VERSION_SET_STEP(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_SET_STEP_SHIFT)) & BCH_VERSION_SET_STEP_MASK)

#define BCH_VERSION_SET_MINOR_MASK               (0xFF0000U)
#define BCH_VERSION_SET_MINOR_SHIFT              (16U)
#define BCH_VERSION_SET_MINOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_SET_MINOR_SHIFT)) & BCH_VERSION_SET_MINOR_MASK)

#define BCH_VERSION_SET_MAJOR_MASK               (0xFF000000U)
#define BCH_VERSION_SET_MAJOR_SHIFT              (24U)
#define BCH_VERSION_SET_MAJOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_SET_MAJOR_SHIFT)) & BCH_VERSION_SET_MAJOR_MASK)
/*! @} */

/*! @name VERSION_CLR - BCH Version Register */
/*! @{ */

#define BCH_VERSION_CLR_STEP_MASK                (0xFFFFU)
#define BCH_VERSION_CLR_STEP_SHIFT               (0U)
#define BCH_VERSION_CLR_STEP(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_CLR_STEP_SHIFT)) & BCH_VERSION_CLR_STEP_MASK)

#define BCH_VERSION_CLR_MINOR_MASK               (0xFF0000U)
#define BCH_VERSION_CLR_MINOR_SHIFT              (16U)
#define BCH_VERSION_CLR_MINOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_CLR_MINOR_SHIFT)) & BCH_VERSION_CLR_MINOR_MASK)

#define BCH_VERSION_CLR_MAJOR_MASK               (0xFF000000U)
#define BCH_VERSION_CLR_MAJOR_SHIFT              (24U)
#define BCH_VERSION_CLR_MAJOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_CLR_MAJOR_SHIFT)) & BCH_VERSION_CLR_MAJOR_MASK)
/*! @} */

/*! @name VERSION_TOG - BCH Version Register */
/*! @{ */

#define BCH_VERSION_TOG_STEP_MASK                (0xFFFFU)
#define BCH_VERSION_TOG_STEP_SHIFT               (0U)
#define BCH_VERSION_TOG_STEP(x)                  (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_TOG_STEP_SHIFT)) & BCH_VERSION_TOG_STEP_MASK)

#define BCH_VERSION_TOG_MINOR_MASK               (0xFF0000U)
#define BCH_VERSION_TOG_MINOR_SHIFT              (16U)
#define BCH_VERSION_TOG_MINOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_TOG_MINOR_SHIFT)) & BCH_VERSION_TOG_MINOR_MASK)

#define BCH_VERSION_TOG_MAJOR_MASK               (0xFF000000U)
#define BCH_VERSION_TOG_MAJOR_SHIFT              (24U)
#define BCH_VERSION_TOG_MAJOR(x)                 (((uint32_t)(((uint32_t)(x)) << BCH_VERSION_TOG_MAJOR_SHIFT)) & BCH_VERSION_TOG_MAJOR_MASK)
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

/*! @name DEBUG1_SET - Hardware BCH ECC Debug Register 1 */
/*! @{ */

#define BCH_DEBUG1_SET_ERASED_ZERO_COUNT_MASK    (0x1FFU)
#define BCH_DEBUG1_SET_ERASED_ZERO_COUNT_SHIFT   (0U)
#define BCH_DEBUG1_SET_ERASED_ZERO_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_SET_ERASED_ZERO_COUNT_SHIFT)) & BCH_DEBUG1_SET_ERASED_ZERO_COUNT_MASK)

#define BCH_DEBUG1_SET_RSVD_MASK                 (0x7FFFFE00U)
#define BCH_DEBUG1_SET_RSVD_SHIFT                (9U)
/*! RSVD - This field is reserved. */
#define BCH_DEBUG1_SET_RSVD(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_SET_RSVD_SHIFT)) & BCH_DEBUG1_SET_RSVD_MASK)

#define BCH_DEBUG1_SET_DEBUG1_PREERASECHK_MASK   (0x80000000U)
#define BCH_DEBUG1_SET_DEBUG1_PREERASECHK_SHIFT  (31U)
/*! DEBUG1_PREERASECHK
 *  0b0..Turn off pre-erase check
 *  0b1..Turn on pre-erase check
 */
#define BCH_DEBUG1_SET_DEBUG1_PREERASECHK(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_SET_DEBUG1_PREERASECHK_SHIFT)) & BCH_DEBUG1_SET_DEBUG1_PREERASECHK_MASK)
/*! @} */

/*! @name DEBUG1_CLR - Hardware BCH ECC Debug Register 1 */
/*! @{ */

#define BCH_DEBUG1_CLR_ERASED_ZERO_COUNT_MASK    (0x1FFU)
#define BCH_DEBUG1_CLR_ERASED_ZERO_COUNT_SHIFT   (0U)
#define BCH_DEBUG1_CLR_ERASED_ZERO_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_CLR_ERASED_ZERO_COUNT_SHIFT)) & BCH_DEBUG1_CLR_ERASED_ZERO_COUNT_MASK)

#define BCH_DEBUG1_CLR_RSVD_MASK                 (0x7FFFFE00U)
#define BCH_DEBUG1_CLR_RSVD_SHIFT                (9U)
/*! RSVD - This field is reserved. */
#define BCH_DEBUG1_CLR_RSVD(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_CLR_RSVD_SHIFT)) & BCH_DEBUG1_CLR_RSVD_MASK)

#define BCH_DEBUG1_CLR_DEBUG1_PREERASECHK_MASK   (0x80000000U)
#define BCH_DEBUG1_CLR_DEBUG1_PREERASECHK_SHIFT  (31U)
/*! DEBUG1_PREERASECHK
 *  0b0..Turn off pre-erase check
 *  0b1..Turn on pre-erase check
 */
#define BCH_DEBUG1_CLR_DEBUG1_PREERASECHK(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_CLR_DEBUG1_PREERASECHK_SHIFT)) & BCH_DEBUG1_CLR_DEBUG1_PREERASECHK_MASK)
/*! @} */

/*! @name DEBUG1_TOG - Hardware BCH ECC Debug Register 1 */
/*! @{ */

#define BCH_DEBUG1_TOG_ERASED_ZERO_COUNT_MASK    (0x1FFU)
#define BCH_DEBUG1_TOG_ERASED_ZERO_COUNT_SHIFT   (0U)
#define BCH_DEBUG1_TOG_ERASED_ZERO_COUNT(x)      (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_TOG_ERASED_ZERO_COUNT_SHIFT)) & BCH_DEBUG1_TOG_ERASED_ZERO_COUNT_MASK)

#define BCH_DEBUG1_TOG_RSVD_MASK                 (0x7FFFFE00U)
#define BCH_DEBUG1_TOG_RSVD_SHIFT                (9U)
/*! RSVD - This field is reserved. */
#define BCH_DEBUG1_TOG_RSVD(x)                   (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_TOG_RSVD_SHIFT)) & BCH_DEBUG1_TOG_RSVD_MASK)

#define BCH_DEBUG1_TOG_DEBUG1_PREERASECHK_MASK   (0x80000000U)
#define BCH_DEBUG1_TOG_DEBUG1_PREERASECHK_SHIFT  (31U)
/*! DEBUG1_PREERASECHK
 *  0b0..Turn off pre-erase check
 *  0b1..Turn on pre-erase check
 */
#define BCH_DEBUG1_TOG_DEBUG1_PREERASECHK(x)     (((uint32_t)(((uint32_t)(x)) << BCH_DEBUG1_TOG_DEBUG1_PREERASECHK_SHIFT)) & BCH_DEBUG1_TOG_DEBUG1_PREERASECHK_MASK)
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

