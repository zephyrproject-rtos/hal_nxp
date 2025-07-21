/*
** ###################################################################
**     Processors:          KW47B42Z83AFTA_cm33_core0
**                          KW47B42Z83AFTA_cm33_core1
**                          KW47B42Z96AFTA_cm33_core0
**                          KW47B42Z96AFTA_cm33_core1
**                          KW47B42Z97AFTA_cm33_core0
**                          KW47B42Z97AFTA_cm33_core1
**                          KW47B42ZB2AFTA_cm33_core0
**                          KW47B42ZB2AFTA_cm33_core1
**                          KW47B42ZB3AFTA_cm33_core0
**                          KW47B42ZB3AFTA_cm33_core1
**                          KW47B42ZB6AFTA_cm33_core0
**                          KW47B42ZB6AFTA_cm33_core1
**                          KW47B42ZB7AFTA_cm33_core0
**                          KW47B42ZB7AFTA_cm33_core1
**                          KW47Z42082AFTA
**                          KW47Z42092AFTA
**                          KW47Z420B2AFTA
**                          KW47Z420B3AFTA
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MSCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MSCM.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MSCM
 *
 * CMSIS Peripheral Access Layer for MSCM
 */

#if !defined(PERI_MSCM_H_)
#define PERI_MSCM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_KW47B42Z83AFTA_cm33_core0))
#include "KW47B42Z83_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z83AFTA_cm33_core1))
#include "KW47B42Z83_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core0))
#include "KW47B42Z96_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z96AFTA_cm33_core1))
#include "KW47B42Z96_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core0))
#include "KW47B42Z97_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42Z97AFTA_cm33_core1))
#include "KW47B42Z97_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core0))
#include "KW47B42ZB2_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB2AFTA_cm33_core1))
#include "KW47B42ZB2_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core0))
#include "KW47B42ZB3_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB3AFTA_cm33_core1))
#include "KW47B42ZB3_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core0))
#include "KW47B42ZB6_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB6AFTA_cm33_core1))
#include "KW47B42ZB6_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core0))
#include "KW47B42ZB7_cm33_core0_COMMON.h"
#elif (defined(CPU_KW47B42ZB7AFTA_cm33_core1))
#include "KW47B42ZB7_cm33_core1_COMMON.h"
#elif (defined(CPU_KW47Z42082AFTA))
#include "KW47Z42082_COMMON.h"
#elif (defined(CPU_KW47Z42092AFTA))
#include "KW47Z42092_COMMON.h"
#elif (defined(CPU_KW47Z420B2AFTA))
#include "KW47Z420B2_COMMON.h"
#elif (defined(CPU_KW47Z420B3AFTA))
#include "KW47Z420B3_COMMON.h"
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
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Size of Registers Arrays */
#define MSCM_UID_COUNT                            4u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPXTYPE;                           /**< Processor X Type Register, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor X Number Register, offset: 0x4 */
  __I  uint32_t CPXMASTER;                         /**< Processor X Master Register, offset: 0x8 */
  __I  uint32_t CPXCOUNT;                          /**< Processor X Count Register, offset: 0xC */
  __I  uint32_t CPXCFG0;                           /**< Processor X Configuration Register 0, offset: 0x10 */
  __I  uint32_t CPXCFG1;                           /**< Processor X Configuration Register 1, offset: 0x14 */
  __I  uint32_t CPXCFG2;                           /**< Processor X Configuration Register 2, offset: 0x18 */
  __I  uint32_t CPXCFG3;                           /**< Processor X Configuration Register 3, offset: 0x1C */
  __I  uint32_t CP0TYPE;                           /**< Processor 0 Type Register, offset: 0x20 */
  __I  uint32_t CP0NUM;                            /**< Processor 0 Number Register, offset: 0x24 */
  __I  uint32_t CP0MASTER;                         /**< Processor 0 Master Register, offset: 0x28 */
  __I  uint32_t CP0COUNT;                          /**< Processor 0 Count Register, offset: 0x2C */
  __I  uint32_t CP0CFG0;                           /**< Processor 0 Configuration Register 0, offset: 0x30 */
  __I  uint32_t CP0CFG1;                           /**< Processor 0 Configuration Register 1, offset: 0x34 */
  __I  uint32_t CP0CFG2;                           /**< Processor 0 Configuration Register 2, offset: 0x38 */
  __I  uint32_t CP0CFG3;                           /**< Processor 0 Configuration Register 3, offset: 0x3C */
       uint8_t RESERVED_0[960];
  __I  uint32_t OCMDR0;                            /**< On-Chip Memory Descriptor Register, offset: 0x400 */
  __I  uint32_t OCMDR1;                            /**< On-Chip Memory Descriptor Register, offset: 0x404 */
  __I  uint32_t OCMDR2;                            /**< On-Chip Memory Descriptor Register, offset: 0x408 */
  __I  uint32_t OCMDR3;                            /**< On-Chip Memory Descriptor Register, offset: 0x40C */
  __I  uint32_t OCMDR4;                            /**< On-Chip Memory Descriptor Register, offset: 0x410 */
  __I  uint32_t OCMDR5;                            /**< On-Chip Memory Descriptor Register, offset: 0x414 */
  __I  uint32_t OCMDR6;                            /**< On-Chip Memory Descriptor Register, offset: 0x418 */
       uint8_t RESERVED_1[996];
  __IO uint32_t SECURE_IRQ;                        /**< Secure Interrupt Request, offset: 0x800 */
       uint8_t RESERVED_2[12];
  __I  uint32_t UID[MSCM_UID_COUNT];               /**< Unique ID 0..Unique ID 3, array offset: 0x810, array step: 0x4 */
  __I  uint32_t SID;                               /**< System ID, offset: 0x820 */
} MSCM_Type;

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/*! @name CPXTYPE - Processor X Type Register */
/*! @{ */

#define MSCM_CPXTYPE_RYPZ_MASK                   (0xFFU)
#define MSCM_CPXTYPE_RYPZ_SHIFT                  (0U)
/*! RYPZ - Processor x Revision */
#define MSCM_CPXTYPE_RYPZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXTYPE_RYPZ_SHIFT)) & MSCM_CPXTYPE_RYPZ_MASK)

#define MSCM_CPXTYPE_PERSONALITY_MASK            (0xFFFFFF00U)
#define MSCM_CPXTYPE_PERSONALITY_SHIFT           (8U)
/*! PERSONALITY - Processor x Personality */
#define MSCM_CPXTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPXTYPE_PERSONALITY_SHIFT)) & MSCM_CPXTYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPXNUM - Processor X Number Register */
/*! @{ */

#define MSCM_CPXNUM_CPN_MASK                     (0x1U)
#define MSCM_CPXNUM_CPN_SHIFT                    (0U)
/*! CPN - Processor x Number */
#define MSCM_CPXNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXNUM_CPN_SHIFT)) & MSCM_CPXNUM_CPN_MASK)
/*! @} */

/*! @name CPXMASTER - Processor X Master Register */
/*! @{ */

#define MSCM_CPXMASTER_PPMN_MASK                 (0x3FU)
#define MSCM_CPXMASTER_PPMN_SHIFT                (0U)
/*! PPMN - Processor x Physical Master Number */
#define MSCM_CPXMASTER_PPMN(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXMASTER_PPMN_SHIFT)) & MSCM_CPXMASTER_PPMN_MASK)
/*! @} */

/*! @name CPXCOUNT - Processor X Count Register */
/*! @{ */

#define MSCM_CPXCOUNT_PCNT_MASK                  (0x3U)
#define MSCM_CPXCOUNT_PCNT_SHIFT                 (0U)
/*! PCNT - Processor Count */
#define MSCM_CPXCOUNT_PCNT(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCOUNT_PCNT_SHIFT)) & MSCM_CPXCOUNT_PCNT_MASK)
/*! @} */

/*! @name CPXCFG0 - Processor X Configuration Register 0 */
/*! @{ */

#define MSCM_CPXCFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CPXCFG0_DCWY_SHIFT                  (0U)
/*! DCWY - Level 1 Data Cache Ways */
#define MSCM_CPXCFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCWY_SHIFT)) & MSCM_CPXCFG0_DCWY_MASK)

#define MSCM_CPXCFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CPXCFG0_DCSZ_SHIFT                  (8U)
/*! DCSZ - Level 1 Data Cache Size */
#define MSCM_CPXCFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCSZ_SHIFT)) & MSCM_CPXCFG0_DCSZ_MASK)

#define MSCM_CPXCFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG0_ICWY_SHIFT                  (16U)
/*! ICWY - Level 1 Instruction Cache Ways */
#define MSCM_CPXCFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICWY_SHIFT)) & MSCM_CPXCFG0_ICWY_MASK)

#define MSCM_CPXCFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG0_ICSZ_SHIFT                  (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CPXCFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICSZ_SHIFT)) & MSCM_CPXCFG0_ICSZ_MASK)
/*! @} */

/*! @name CPXCFG1 - Processor X Configuration Register 1 */
/*! @{ */

#define MSCM_CPXCFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG1_L2WY_SHIFT                  (16U)
/*! L2WY - Level 2 Instruction Cache Ways */
#define MSCM_CPXCFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2WY_SHIFT)) & MSCM_CPXCFG1_L2WY_MASK)

#define MSCM_CPXCFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG1_L2SZ_SHIFT                  (24U)
/*! L2SZ - Level 2 Instruction Cache Size */
#define MSCM_CPXCFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2SZ_SHIFT)) & MSCM_CPXCFG1_L2SZ_MASK)
/*! @} */

/*! @name CPXCFG2 - Processor X Configuration Register 2 */
/*! @{ */

#define MSCM_CPXCFG2_TMUSZ_MASK                  (0xFF00U)
#define MSCM_CPXCFG2_TMUSZ_SHIFT                 (8U)
/*! TMUSZ - Tightly-coupled Memory Upper Size */
#define MSCM_CPXCFG2_TMUSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_TMUSZ_SHIFT)) & MSCM_CPXCFG2_TMUSZ_MASK)

#define MSCM_CPXCFG2_TMLSZ_MASK                  (0xFF000000U)
#define MSCM_CPXCFG2_TMLSZ_SHIFT                 (24U)
/*! TMLSZ - Tightly-coupled Memory Lower Size */
#define MSCM_CPXCFG2_TMLSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_TMLSZ_SHIFT)) & MSCM_CPXCFG2_TMLSZ_MASK)
/*! @} */

/*! @name CPXCFG3 - Processor X Configuration Register 3 */
/*! @{ */

#define MSCM_CPXCFG3_FPU_MASK                    (0x1U)
#define MSCM_CPXCFG3_FPU_SHIFT                   (0U)
/*! FPU - Floating Point Unit
 *  0b0..FPU support is not included.
 *  0b1..FPU support is included.
 */
#define MSCM_CPXCFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_FPU_SHIFT)) & MSCM_CPXCFG3_FPU_MASK)

#define MSCM_CPXCFG3_SIMD_MASK                   (0x2U)
#define MSCM_CPXCFG3_SIMD_SHIFT                  (1U)
/*! SIMD - SIMD/NEON instruction support
 *  0b0..SIMD/NEON support is not included.
 *  0b1..SIMD/NEON support is included.
 */
#define MSCM_CPXCFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_SIMD_SHIFT)) & MSCM_CPXCFG3_SIMD_MASK)

#define MSCM_CPXCFG3_JAZ_MASK                    (0x4U)
#define MSCM_CPXCFG3_JAZ_SHIFT                   (2U)
/*! JAZ - Jazelle support
 *  0b0..Jazelle support is not included.
 *  0b1..Jazelle support is included.
 */
#define MSCM_CPXCFG3_JAZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_JAZ_SHIFT)) & MSCM_CPXCFG3_JAZ_MASK)

#define MSCM_CPXCFG3_MMU_MASK                    (0x8U)
#define MSCM_CPXCFG3_MMU_SHIFT                   (3U)
/*! MMU - Memory Management Unit
 *  0b0..MMU support is not included.
 *  0b1..MMU support is included.
 */
#define MSCM_CPXCFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_MMU_SHIFT)) & MSCM_CPXCFG3_MMU_MASK)

#define MSCM_CPXCFG3_TZ_MASK                     (0x10U)
#define MSCM_CPXCFG3_TZ_SHIFT                    (4U)
/*! TZ - Trust Zone
 *  0b0..Trust Zone support is not included.
 *  0b1..Trust Zone support is included.
 */
#define MSCM_CPXCFG3_TZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_TZ_SHIFT)) & MSCM_CPXCFG3_TZ_MASK)

#define MSCM_CPXCFG3_CMP_MASK                    (0x20U)
#define MSCM_CPXCFG3_CMP_SHIFT                   (5U)
/*! CMP - Core Memory Protection unit
 *  0b0..Core Memory Protection is not included.
 *  0b1..Core Memory Protection is included.
 */
#define MSCM_CPXCFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CMP_SHIFT)) & MSCM_CPXCFG3_CMP_MASK)

#define MSCM_CPXCFG3_BB_MASK                     (0x40U)
#define MSCM_CPXCFG3_BB_SHIFT                    (6U)
/*! BB - Bit Banding
 *  0b0..Bit Banding is not supported.
 *  0b1..Bit Banding is supported.
 */
#define MSCM_CPXCFG3_BB(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_BB_SHIFT)) & MSCM_CPXCFG3_BB_MASK)

#define MSCM_CPXCFG3_SBP_MASK                    (0x300U)
#define MSCM_CPXCFG3_SBP_SHIFT                   (8U)
/*! SBP - System Bus Ports */
#define MSCM_CPXCFG3_SBP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_SBP_SHIFT)) & MSCM_CPXCFG3_SBP_MASK)
/*! @} */

/*! @name CP0TYPE - Processor 0 Type Register */
/*! @{ */

#define MSCM_CP0TYPE_RYPZ_MASK                   (0xFFU)
#define MSCM_CP0TYPE_RYPZ_SHIFT                  (0U)
/*! RYPZ - Processor 0 Revision */
#define MSCM_CP0TYPE_RYPZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0TYPE_RYPZ_SHIFT)) & MSCM_CP0TYPE_RYPZ_MASK)

#define MSCM_CP0TYPE_PERSONALITY_MASK            (0xFFFFFF00U)
#define MSCM_CP0TYPE_PERSONALITY_SHIFT           (8U)
/*! PERSONALITY - Processor 0 Personality */
#define MSCM_CP0TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP0TYPE_PERSONALITY_SHIFT)) & MSCM_CP0TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP0NUM - Processor 0 Number Register */
/*! @{ */

#define MSCM_CP0NUM_CPN_MASK                     (0x1U)
#define MSCM_CP0NUM_CPN_SHIFT                    (0U)
/*! CPN - Processor 0 Number */
#define MSCM_CP0NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP0NUM_CPN_SHIFT)) & MSCM_CP0NUM_CPN_MASK)
/*! @} */

/*! @name CP0MASTER - Processor 0 Master Register */
/*! @{ */

#define MSCM_CP0MASTER_PPMN_MASK                 (0x3FU)
#define MSCM_CP0MASTER_PPMN_SHIFT                (0U)
/*! PPMN - Processor 0 Physical Master Number */
#define MSCM_CP0MASTER_PPMN(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0MASTER_PPMN_SHIFT)) & MSCM_CP0MASTER_PPMN_MASK)
/*! @} */

/*! @name CP0COUNT - Processor 0 Count Register */
/*! @{ */

#define MSCM_CP0COUNT_PCNT_MASK                  (0x3U)
#define MSCM_CP0COUNT_PCNT_SHIFT                 (0U)
/*! PCNT - Processor Count */
#define MSCM_CP0COUNT_PCNT(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CP0COUNT_PCNT_SHIFT)) & MSCM_CP0COUNT_PCNT_MASK)
/*! @} */

/*! @name CP0CFG0 - Processor 0 Configuration Register 0 */
/*! @{ */

#define MSCM_CP0CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP0CFG0_DCWY_SHIFT                  (0U)
/*! DCWY - Level 1 Data Cache Ways */
#define MSCM_CP0CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCWY_SHIFT)) & MSCM_CP0CFG0_DCWY_MASK)

#define MSCM_CP0CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP0CFG0_DCSZ_SHIFT                  (8U)
/*! DCSZ - Level 1 Data Cache Size */
#define MSCM_CP0CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCSZ_SHIFT)) & MSCM_CP0CFG0_DCSZ_MASK)

#define MSCM_CP0CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG0_ICWY_SHIFT                  (16U)
/*! ICWY - Level 1 Instruction Cache Ways */
#define MSCM_CP0CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICWY_SHIFT)) & MSCM_CP0CFG0_ICWY_MASK)

#define MSCM_CP0CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG0_ICSZ_SHIFT                  (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CP0CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICSZ_SHIFT)) & MSCM_CP0CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP0CFG1 - Processor 0 Configuration Register 1 */
/*! @{ */

#define MSCM_CP0CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG1_L2WY_SHIFT                  (16U)
/*! L2WY - Level 2 Instruction Cache Ways */
#define MSCM_CP0CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2WY_SHIFT)) & MSCM_CP0CFG1_L2WY_MASK)

#define MSCM_CP0CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG1_L2SZ_SHIFT                  (24U)
/*! L2SZ - Level 2 Instruction Cache Size */
#define MSCM_CP0CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2SZ_SHIFT)) & MSCM_CP0CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP0CFG2 - Processor 0 Configuration Register 2 */
/*! @{ */

#define MSCM_CP0CFG2_TMUSZ_MASK                  (0xFF00U)
#define MSCM_CP0CFG2_TMUSZ_SHIFT                 (8U)
/*! TMUSZ - Tightly-coupled Memory Upper Size */
#define MSCM_CP0CFG2_TMUSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_TMUSZ_SHIFT)) & MSCM_CP0CFG2_TMUSZ_MASK)

#define MSCM_CP0CFG2_TMLSZ_MASK                  (0xFF000000U)
#define MSCM_CP0CFG2_TMLSZ_SHIFT                 (24U)
/*! TMLSZ - Tightly-coupled Memory Lower Size */
#define MSCM_CP0CFG2_TMLSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_TMLSZ_SHIFT)) & MSCM_CP0CFG2_TMLSZ_MASK)
/*! @} */

/*! @name CP0CFG3 - Processor 0 Configuration Register 3 */
/*! @{ */

#define MSCM_CP0CFG3_FPU_MASK                    (0x1U)
#define MSCM_CP0CFG3_FPU_SHIFT                   (0U)
/*! FPU - Floating Point Unit
 *  0b0..FPU support is not included.
 *  0b1..FPU support is included.
 */
#define MSCM_CP0CFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_FPU_SHIFT)) & MSCM_CP0CFG3_FPU_MASK)

#define MSCM_CP0CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP0CFG3_SIMD_SHIFT                  (1U)
/*! SIMD - SIMD/NEON instruction support
 *  0b0..SIMD/NEON support is not included.
 *  0b1..SIMD/NEON support is included.
 */
#define MSCM_CP0CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_SIMD_SHIFT)) & MSCM_CP0CFG3_SIMD_MASK)

#define MSCM_CP0CFG3_JAZ_MASK                    (0x4U)
#define MSCM_CP0CFG3_JAZ_SHIFT                   (2U)
/*! JAZ - Jazelle support
 *  0b0..Jazelle support is not included.
 *  0b1..Jazelle support is included.
 */
#define MSCM_CP0CFG3_JAZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_JAZ_SHIFT)) & MSCM_CP0CFG3_JAZ_MASK)

#define MSCM_CP0CFG3_MMU_MASK                    (0x8U)
#define MSCM_CP0CFG3_MMU_SHIFT                   (3U)
/*! MMU - Memory Management Unit
 *  0b0..MMU support is not included.
 *  0b1..MMU support is included.
 */
#define MSCM_CP0CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_MMU_SHIFT)) & MSCM_CP0CFG3_MMU_MASK)

#define MSCM_CP0CFG3_TZ_MASK                     (0x10U)
#define MSCM_CP0CFG3_TZ_SHIFT                    (4U)
/*! TZ - Trust Zone
 *  0b0..Trust Zone support is not included.
 *  0b1..Trust Zone support is included.
 */
#define MSCM_CP0CFG3_TZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_TZ_SHIFT)) & MSCM_CP0CFG3_TZ_MASK)

#define MSCM_CP0CFG3_CMP_MASK                    (0x20U)
#define MSCM_CP0CFG3_CMP_SHIFT                   (5U)
/*! CMP - Core Memory Protection unit
 *  0b0..Core Memory Protection is not included.
 *  0b1..Core Memory Protection is included.
 */
#define MSCM_CP0CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_CMP_SHIFT)) & MSCM_CP0CFG3_CMP_MASK)

#define MSCM_CP0CFG3_BB_MASK                     (0x40U)
#define MSCM_CP0CFG3_BB_SHIFT                    (6U)
/*! BB - Bit Banding
 *  0b0..Bit Banding is not supported.
 *  0b1..Bit Banding is supported.
 */
#define MSCM_CP0CFG3_BB(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_BB_SHIFT)) & MSCM_CP0CFG3_BB_MASK)

#define MSCM_CP0CFG3_SBP_MASK                    (0x300U)
#define MSCM_CP0CFG3_SBP_SHIFT                   (8U)
/*! SBP - System Bus Ports */
#define MSCM_CP0CFG3_SBP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_SBP_SHIFT)) & MSCM_CP0CFG3_SBP_MASK)
/*! @} */

/*! @name OCMDR0 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR0_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR0_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR0_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMPU_SHIFT)) & MSCM_OCMDR0_OCMPU_MASK)

#define MSCM_OCMDR0_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR0_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR0_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMT_SHIFT)) & MSCM_OCMDR0_OCMT_MASK)

#define MSCM_OCMDR0_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR0_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR0_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMW_SHIFT)) & MSCM_OCMDR0_OCMW_MASK)

#define MSCM_OCMDR0_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR0_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR0_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMSZ_SHIFT)) & MSCM_OCMDR0_OCMSZ_MASK)

#define MSCM_OCMDR0_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR0_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR0_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMSZH_SHIFT)) & MSCM_OCMDR0_OCMSZH_MASK)

#define MSCM_OCMDR0_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR0_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR0_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_OCMECC_SHIFT)) & MSCM_OCMDR0_OCMECC_MASK)

#define MSCM_OCMDR0_V_MASK                       (0x80000000U)
#define MSCM_OCMDR0_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR0_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR0_V_SHIFT)) & MSCM_OCMDR0_V_MASK)
/*! @} */

/*! @name OCMDR1 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR1_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR1_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR1_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMPU_SHIFT)) & MSCM_OCMDR1_OCMPU_MASK)

#define MSCM_OCMDR1_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR1_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR1_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMT_SHIFT)) & MSCM_OCMDR1_OCMT_MASK)

#define MSCM_OCMDR1_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR1_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR1_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMW_SHIFT)) & MSCM_OCMDR1_OCMW_MASK)

#define MSCM_OCMDR1_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR1_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR1_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMSZ_SHIFT)) & MSCM_OCMDR1_OCMSZ_MASK)

#define MSCM_OCMDR1_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR1_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR1_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMSZH_SHIFT)) & MSCM_OCMDR1_OCMSZH_MASK)

#define MSCM_OCMDR1_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR1_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR1_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_OCMECC_SHIFT)) & MSCM_OCMDR1_OCMECC_MASK)

#define MSCM_OCMDR1_V_MASK                       (0x80000000U)
#define MSCM_OCMDR1_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR1_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR1_V_SHIFT)) & MSCM_OCMDR1_V_MASK)
/*! @} */

/*! @name OCMDR2 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR2_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR2_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR2_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMPU_SHIFT)) & MSCM_OCMDR2_OCMPU_MASK)

#define MSCM_OCMDR2_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR2_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR2_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMT_SHIFT)) & MSCM_OCMDR2_OCMT_MASK)

#define MSCM_OCMDR2_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR2_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR2_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMW_SHIFT)) & MSCM_OCMDR2_OCMW_MASK)

#define MSCM_OCMDR2_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR2_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR2_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMSZ_SHIFT)) & MSCM_OCMDR2_OCMSZ_MASK)

#define MSCM_OCMDR2_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR2_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR2_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMSZH_SHIFT)) & MSCM_OCMDR2_OCMSZH_MASK)

#define MSCM_OCMDR2_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR2_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR2_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_OCMECC_SHIFT)) & MSCM_OCMDR2_OCMECC_MASK)

#define MSCM_OCMDR2_V_MASK                       (0x80000000U)
#define MSCM_OCMDR2_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR2_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR2_V_SHIFT)) & MSCM_OCMDR2_V_MASK)
/*! @} */

/*! @name OCMDR3 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR3_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR3_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR3_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMPU_SHIFT)) & MSCM_OCMDR3_OCMPU_MASK)

#define MSCM_OCMDR3_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR3_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR3_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMT_SHIFT)) & MSCM_OCMDR3_OCMT_MASK)

#define MSCM_OCMDR3_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR3_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR3_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMW_SHIFT)) & MSCM_OCMDR3_OCMW_MASK)

#define MSCM_OCMDR3_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR3_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR3_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMSZ_SHIFT)) & MSCM_OCMDR3_OCMSZ_MASK)

#define MSCM_OCMDR3_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR3_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR3_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMSZH_SHIFT)) & MSCM_OCMDR3_OCMSZH_MASK)

#define MSCM_OCMDR3_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR3_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR3_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_OCMECC_SHIFT)) & MSCM_OCMDR3_OCMECC_MASK)

#define MSCM_OCMDR3_V_MASK                       (0x80000000U)
#define MSCM_OCMDR3_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR3_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR3_V_SHIFT)) & MSCM_OCMDR3_V_MASK)
/*! @} */

/*! @name OCMDR4 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR4_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR4_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR4_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMPU_SHIFT)) & MSCM_OCMDR4_OCMPU_MASK)

#define MSCM_OCMDR4_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR4_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR4_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMT_SHIFT)) & MSCM_OCMDR4_OCMT_MASK)

#define MSCM_OCMDR4_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR4_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR4_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMW_SHIFT)) & MSCM_OCMDR4_OCMW_MASK)

#define MSCM_OCMDR4_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR4_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR4_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMSZ_SHIFT)) & MSCM_OCMDR4_OCMSZ_MASK)

#define MSCM_OCMDR4_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR4_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR4_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMSZH_SHIFT)) & MSCM_OCMDR4_OCMSZH_MASK)

#define MSCM_OCMDR4_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR4_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR4_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_OCMECC_SHIFT)) & MSCM_OCMDR4_OCMECC_MASK)

#define MSCM_OCMDR4_V_MASK                       (0x80000000U)
#define MSCM_OCMDR4_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR4_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR4_V_SHIFT)) & MSCM_OCMDR4_V_MASK)
/*! @} */

/*! @name OCMDR5 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR5_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR5_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR5_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMPU_SHIFT)) & MSCM_OCMDR5_OCMPU_MASK)

#define MSCM_OCMDR5_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR5_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR5_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMT_SHIFT)) & MSCM_OCMDR5_OCMT_MASK)

#define MSCM_OCMDR5_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR5_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR5_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMW_SHIFT)) & MSCM_OCMDR5_OCMW_MASK)

#define MSCM_OCMDR5_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR5_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR5_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMSZ_SHIFT)) & MSCM_OCMDR5_OCMSZ_MASK)

#define MSCM_OCMDR5_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR5_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR5_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMSZH_SHIFT)) & MSCM_OCMDR5_OCMSZH_MASK)

#define MSCM_OCMDR5_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR5_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR5_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_OCMECC_SHIFT)) & MSCM_OCMDR5_OCMECC_MASK)

#define MSCM_OCMDR5_V_MASK                       (0x80000000U)
#define MSCM_OCMDR5_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR5_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR5_V_SHIFT)) & MSCM_OCMDR5_V_MASK)
/*! @} */

/*! @name OCMDR6 - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR6_OCMPU_MASK                   (0x1000U)
#define MSCM_OCMDR6_OCMPU_SHIFT                  (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR6_OCMPU(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMPU_SHIFT)) & MSCM_OCMDR6_OCMPU_MASK)

#define MSCM_OCMDR6_OCMT_MASK                    (0xE000U)
#define MSCM_OCMDR6_OCMT_SHIFT                   (13U)
/*! OCMT - OCMT
 *  0b000..OCMEMn is a System RAM.
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..OCMEMn is a ROM.
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..Reserved
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define MSCM_OCMDR6_OCMT(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMT_SHIFT)) & MSCM_OCMDR6_OCMT_MASK)

#define MSCM_OCMDR6_OCMW_MASK                    (0xE0000U)
#define MSCM_OCMDR6_OCMW_SHIFT                   (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR6_OCMW(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMW_SHIFT)) & MSCM_OCMDR6_OCMW_MASK)

#define MSCM_OCMDR6_OCMSZ_MASK                   (0xF000000U)
#define MSCM_OCMDR6_OCMSZ_SHIFT                  (24U)
/*! OCMSZ - OCMSZ
 *  0b0000..no OCMEMn
 *  0b0001..1KB OCMEMn
 *  0b0010..2KB OCMEMn
 *  0b0011..4KB OCMEMn
 *  0b0100..8KB OCMEMn
 *  0b0101..16KB OCMEMn
 *  0b0110..32KB OCMEMn
 *  0b0111..64KB OCMEMn
 *  0b1000..128KB OCMEMn
 *  0b1001..256KB OCMEMn
 *  0b1010..512KB OCMEMn
 *  0b1011..1MB OCMEMn
 *  0b1100..2MB OCMEMn
 *  0b1101..4MB OCMEMn
 *  0b1110..8MB OCMEMn
 *  0b1111..16MB OCMEMn
 */
#define MSCM_OCMDR6_OCMSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMSZ_SHIFT)) & MSCM_OCMDR6_OCMSZ_MASK)

#define MSCM_OCMDR6_OCMSZH_MASK                  (0x10000000U)
#define MSCM_OCMDR6_OCMSZH_SHIFT                 (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR6_OCMSZH(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMSZH_SHIFT)) & MSCM_OCMDR6_OCMSZH_MASK)

#define MSCM_OCMDR6_OCMECC_MASK                  (0x20000000U)
#define MSCM_OCMDR6_OCMECC_SHIFT                 (29U)
/*! OCMECC - OCMECC
 *  0b0..OCMEMn does not have ECC support.
 *  0b1..OCMEMn has ECC support.
 */
#define MSCM_OCMDR6_OCMECC(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_OCMECC_SHIFT)) & MSCM_OCMDR6_OCMECC_MASK)

#define MSCM_OCMDR6_V_MASK                       (0x80000000U)
#define MSCM_OCMDR6_V_SHIFT                      (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR6_V(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR6_V_SHIFT)) & MSCM_OCMDR6_V_MASK)
/*! @} */

/*! @name SECURE_IRQ - Secure Interrupt Request */
/*! @{ */

#define MSCM_SECURE_IRQ_SEC_IRQ_ARG_MASK         (0xFFFFFFFFU)
#define MSCM_SECURE_IRQ_SEC_IRQ_ARG_SHIFT        (0U)
/*! SEC_IRQ_ARG - Secure Interrupt Argument */
#define MSCM_SECURE_IRQ_SEC_IRQ_ARG(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_SECURE_IRQ_SEC_IRQ_ARG_SHIFT)) & MSCM_SECURE_IRQ_SEC_IRQ_ARG_MASK)
/*! @} */

/*! @name UID - Unique ID 0..Unique ID 3 */
/*! @{ */

#define MSCM_UID_UID0_MASK                       (0xFFFFFFFFU)
#define MSCM_UID_UID0_SHIFT                      (0U)
/*! UID0 - Unique ID 0 */
#define MSCM_UID_UID0(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_UID_UID0_SHIFT)) & MSCM_UID_UID0_MASK)

#define MSCM_UID_UID1_MASK                       (0xFFFFFFFFU)
#define MSCM_UID_UID1_SHIFT                      (0U)
/*! UID1 - Unique ID 1 */
#define MSCM_UID_UID1(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_UID_UID1_SHIFT)) & MSCM_UID_UID1_MASK)

#define MSCM_UID_UID2_MASK                       (0xFFFFFFFFU)
#define MSCM_UID_UID2_SHIFT                      (0U)
/*! UID2 - Unique ID 2 */
#define MSCM_UID_UID2(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_UID_UID2_SHIFT)) & MSCM_UID_UID2_MASK)

#define MSCM_UID_UID3_MASK                       (0xFFFFFFFFU)
#define MSCM_UID_UID3_SHIFT                      (0U)
/*! UID3 - Unique ID 3 */
#define MSCM_UID_UID3(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_UID_UID3_SHIFT)) & MSCM_UID_UID3_MASK)
/*! @} */

/*! @name SID - System ID */
/*! @{ */

#define MSCM_SID_QI_MASK                         (0x3U)
#define MSCM_SID_QI_SHIFT                        (0U)
/*! QI - Qual Info
 *  0b00..Reserved
 *  0b01..Industrial
 *  0b10..Reserved
 *  0b11..Auto
 */
#define MSCM_SID_QI(x)                           (((uint32_t)(((uint32_t)(x)) << MSCM_SID_QI_SHIFT)) & MSCM_SID_QI_MASK)

#define MSCM_SID_SIREV_MASK                      (0xCU)
#define MSCM_SID_SIREV_SHIFT                     (2U)
/*! SIREV - Silicon Revision
 *  0b00..Reserved
 *  0b01..2nd Major Spin
 *  0b10..1st Major Spin
 *  0b11..Initial mask set
 */
#define MSCM_SID_SIREV(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_SID_SIREV_SHIFT)) & MSCM_SID_SIREV_MASK)

#define MSCM_SID_PINID_MASK                      (0x70U)
#define MSCM_SID_PINID_SHIFT                     (4U)
/*! PINID - Pin Identification
 *  0b010..40HVQFN
 *  0b011..48HVQFN
 *  0b100..56HVQFN
 */
#define MSCM_SID_PINID(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_SID_PINID_SHIFT)) & MSCM_SID_PINID_MASK)

#define MSCM_SID_CMP_MASK                        (0x80U)
#define MSCM_SID_CMP_SHIFT                       (7U)
/*! CMP - CMP Presence
 *  0b0..No CMP
 *  0b1..CMP present
 */
#define MSCM_SID_CMP(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_SID_CMP_SHIFT)) & MSCM_SID_CMP_MASK)

#define MSCM_SID_FLXIO_MASK                      (0x100U)
#define MSCM_SID_FLXIO_SHIFT                     (8U)
/*! FLXIO - FlexIO Presence
 *  0b0..No FlexIO
 *  0b1..FlexIO present
 */
#define MSCM_SID_FLXIO(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_SID_FLXIO_SHIFT)) & MSCM_SID_FLXIO_MASK)

#define MSCM_SID_VREF_MASK                       (0x200U)
#define MSCM_SID_VREF_SHIFT                      (9U)
/*! VREF - VREF Presence
 *  0b0..No VREF
 *  0b1..VREF present
 */
#define MSCM_SID_VREF(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_SID_VREF_SHIFT)) & MSCM_SID_VREF_MASK)

#define MSCM_SID_I3C_MASK                        (0x400U)
#define MSCM_SID_I3C_SHIFT                       (10U)
/*! I3C - I3C Presence
 *  0b0..No I3C
 *  0b1..I3C present
 */
#define MSCM_SID_I3C(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_SID_I3C_SHIFT)) & MSCM_SID_I3C_MASK)

#define MSCM_SID_CAN_MASK                        (0x800U)
#define MSCM_SID_CAN_SHIFT                       (11U)
/*! CAN - CAN Presence
 *  0b0..No CAN
 *  0b1..CAN present
 */
#define MSCM_SID_CAN(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_SID_CAN_SHIFT)) & MSCM_SID_CAN_MASK)

#define MSCM_SID_SEC_MASK                        (0x1000U)
#define MSCM_SID_SEC_SHIFT                       (12U)
/*! SEC - Secure Enclave Presence
 *  0b0..No Secure Enclave
 *  0b1..Secure Enclave present
 */
#define MSCM_SID_SEC(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_SID_SEC_SHIFT)) & MSCM_SID_SEC_MASK)

#define MSCM_SID_RAMSZ_MASK                      (0xE000U)
#define MSCM_SID_RAMSZ_SHIFT                     (13U)
/*! RAMSZ - RAM Size
 *  0b000..96 KB
 *  0b111..128 KB
 */
#define MSCM_SID_RAMSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_SID_RAMSZ_SHIFT)) & MSCM_SID_RAMSZ_MASK)

#define MSCM_SID_FLSZ_MASK                       (0xF0000U)
#define MSCM_SID_FLSZ_SHIFT                      (16U)
/*! FLSZ - Flash Size
 *  0b1101..1 MB
 *  0b1111..512 KB
 */
#define MSCM_SID_FLSZ(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_SID_FLSZ_SHIFT)) & MSCM_SID_FLSZ_MASK)

#define MSCM_SID_BLEF_MASK                       (0xF00000U)
#define MSCM_SID_BLEF_SHIFT                      (20U)
/*! BLEF - Bluetooth LE Feature
 *  0b0000..No Bluetooth LE present
 *  0b0001..Bluetooth LE 5.1
 *  0b0010..Bluetooth LE 5.2
 *  0b0011..Bluetooth LE 5.3
 *  0b1111..Bluetooth LE Upgrade
 */
#define MSCM_SID_BLEF(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_SID_BLEF_SHIFT)) & MSCM_SID_BLEF_MASK)

#define MSCM_SID_RADIOF_MASK                     (0xF000000U)
#define MSCM_SID_RADIOF_SHIFT                    (24U)
/*! RADIOF - Radio Feature
 *  0b0000..802.15.4
 *  0b0001..Bluetooth LE
 *  0b0010..Bluetooth LE + 802.15.4
 */
#define MSCM_SID_RADIOF(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_SID_RADIOF_SHIFT)) & MSCM_SID_RADIOF_MASK)

#define MSCM_SID_FAMID_MASK                      (0xF0000000U)
#define MSCM_SID_FAMID_SHIFT                     (28U)
/*! FAMID - Family ID */
#define MSCM_SID_FAMID(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_SID_FAMID_SHIFT)) & MSCM_SID_FAMID_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MSCM_Register_Masks */


/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */


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


#endif  /* PERI_MSCM_H_ */

