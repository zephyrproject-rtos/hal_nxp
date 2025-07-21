/*
** ###################################################################
**     Processors:          MCXE246VLH
**                          MCXE246VLL
**                          MCXE246VLQ
**
**     Version:             rev. 1.0, 2025-02-21
**     Build:               b250424
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
**     - rev. 1.0 (2025-02-21)
**         Generated based on Rev1 Draft RM..
**
** ###################################################################
*/

/*!
 * @file PERI_MSCM.h
 * @version 1.0
 * @date 2025-02-21
 * @brief CMSIS Peripheral Access Layer for MSCM
 *
 * CMSIS Peripheral Access Layer for MSCM
 */

#if !defined(PERI_MSCM_H_)
#define PERI_MSCM_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE246VLH) || defined(CPU_MCXE246VLL) || defined(CPU_MCXE246VLQ))
#include "MCXE246_COMMON.h"
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
#define MSCM_CP_COUNT                             1u
#define MSCM_OCMDR_COUNT                          3u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPxTYPE;                           /**< Processor X Type Register, offset: 0x0 */
  __I  uint32_t CPxNUM;                            /**< Processor X Number Register, offset: 0x4 */
  __I  uint32_t CPxMASTER;                         /**< Processor X Master Register, offset: 0x8 */
  __I  uint32_t CPxCOUNT;                          /**< Processor X Count Register, offset: 0xC */
  __I  uint32_t CPxCFG0;                           /**< Processor X Configuration Register 0, offset: 0x10 */
  __I  uint32_t CPxCFG1;                           /**< Processor X Configuration Register 1, offset: 0x14 */
  __I  uint32_t CPxCFG2;                           /**< Processor X Configuration Register 2, offset: 0x18 */
  __I  uint32_t CPxCFG3;                           /**< Processor X Configuration Register 3, offset: 0x1C */
  struct {                                         /* offset: 0x20, array step: 0x20 */
    __I  uint32_t TYPE;                              /**< Processor 0 Type Register, array offset: 0x20, array step: 0x20 */
    __I  uint32_t NUM;                               /**< Processor 0 Number Register, array offset: 0x24, array step: 0x20 */
    __I  uint32_t MASTER;                            /**< Processor 0 Master Register, array offset: 0x28, array step: 0x20 */
    __I  uint32_t COUNT;                             /**< Processor 0 Count Register, array offset: 0x2C, array step: 0x20 */
    __I  uint32_t CFG0;                              /**< Processor 0 Configuration Register 0, array offset: 0x30, array step: 0x20 */
    __I  uint32_t CFG1;                              /**< Processor 0 Configuration Register 1, array offset: 0x34, array step: 0x20 */
    __I  uint32_t CFG2;                              /**< Processor 0 Configuration Register 2, array offset: 0x38, array step: 0x20 */
    __I  uint32_t CFG3;                              /**< Processor 0 Configuration Register 3, array offset: 0x3C, array step: 0x20 */
  } CP[MSCM_CP_COUNT];
       uint8_t RESERVED_0[960];
  __IO uint32_t OCMDR[MSCM_OCMDR_COUNT];           /**< On-Chip Memory Descriptor Register, array offset: 0x400, array step: 0x4 */
} MSCM_Type;

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/*! @name CPxTYPE - Processor X Type Register */
/*! @{ */

#define MSCM_CPxTYPE_RYPZ_MASK                   (0xFFU)
#define MSCM_CPxTYPE_RYPZ_SHIFT                  (0U)
/*! RYPZ - Processor x Revision */
#define MSCM_CPxTYPE_RYPZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxTYPE_RYPZ_SHIFT)) & MSCM_CPxTYPE_RYPZ_MASK)

#define MSCM_CPxTYPE_PERSONALITY_MASK            (0xFFFFFF00U)
#define MSCM_CPxTYPE_PERSONALITY_SHIFT           (8U)
/*! PERSONALITY - Processor x Personality */
#define MSCM_CPxTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPxTYPE_PERSONALITY_SHIFT)) & MSCM_CPxTYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPxNUM - Processor X Number Register */
/*! @{ */

#define MSCM_CPxNUM_CPN_MASK                     (0x1U)
#define MSCM_CPxNUM_CPN_SHIFT                    (0U)
/*! CPN - Processor x Number */
#define MSCM_CPxNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPxNUM_CPN_SHIFT)) & MSCM_CPxNUM_CPN_MASK)
/*! @} */

/*! @name CPxMASTER - Processor X Master Register */
/*! @{ */

#define MSCM_CPxMASTER_PPMN_MASK                 (0x3FU)
#define MSCM_CPxMASTER_PPMN_SHIFT                (0U)
/*! PPMN - Processor x Physical Master Number */
#define MSCM_CPxMASTER_PPMN(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPxMASTER_PPMN_SHIFT)) & MSCM_CPxMASTER_PPMN_MASK)
/*! @} */

/*! @name CPxCOUNT - Processor X Count Register */
/*! @{ */

#define MSCM_CPxCOUNT_PCNT_MASK                  (0x3U)
#define MSCM_CPxCOUNT_PCNT_SHIFT                 (0U)
/*! PCNT - Processor Count */
#define MSCM_CPxCOUNT_PCNT(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCOUNT_PCNT_SHIFT)) & MSCM_CPxCOUNT_PCNT_MASK)
/*! @} */

/*! @name CPxCFG0 - Processor X Configuration Register 0 */
/*! @{ */

#define MSCM_CPxCFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CPxCFG0_DCWY_SHIFT                  (0U)
/*! DCWY - Level 1 Data Cache Ways */
#define MSCM_CPxCFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG0_DCWY_SHIFT)) & MSCM_CPxCFG0_DCWY_MASK)

#define MSCM_CPxCFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CPxCFG0_DCSZ_SHIFT                  (8U)
/*! DCSZ - Level 1 Data Cache Size */
#define MSCM_CPxCFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG0_DCSZ_SHIFT)) & MSCM_CPxCFG0_DCSZ_MASK)

#define MSCM_CPxCFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CPxCFG0_ICWY_SHIFT                  (16U)
/*! ICWY - Level 1 Instruction Cache Ways */
#define MSCM_CPxCFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG0_ICWY_SHIFT)) & MSCM_CPxCFG0_ICWY_MASK)

#define MSCM_CPxCFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CPxCFG0_ICSZ_SHIFT                  (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CPxCFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG0_ICSZ_SHIFT)) & MSCM_CPxCFG0_ICSZ_MASK)
/*! @} */

/*! @name CPxCFG1 - Processor X Configuration Register 1 */
/*! @{ */

#define MSCM_CPxCFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CPxCFG1_L2WY_SHIFT                  (16U)
/*! L2WY - Level 2 Instruction Cache Ways */
#define MSCM_CPxCFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG1_L2WY_SHIFT)) & MSCM_CPxCFG1_L2WY_MASK)

#define MSCM_CPxCFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CPxCFG1_L2SZ_SHIFT                  (24U)
/*! L2SZ - Level 2 Instruction Cache Size */
#define MSCM_CPxCFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG1_L2SZ_SHIFT)) & MSCM_CPxCFG1_L2SZ_MASK)
/*! @} */

/*! @name CPxCFG2 - Processor X Configuration Register 2 */
/*! @{ */

#define MSCM_CPxCFG2_TMUSZ_MASK                  (0xFF00U)
#define MSCM_CPxCFG2_TMUSZ_SHIFT                 (8U)
/*! TMUSZ - Tightly-coupled Memory Upper Size */
#define MSCM_CPxCFG2_TMUSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG2_TMUSZ_SHIFT)) & MSCM_CPxCFG2_TMUSZ_MASK)

#define MSCM_CPxCFG2_TMLSZ_MASK                  (0xFF000000U)
#define MSCM_CPxCFG2_TMLSZ_SHIFT                 (24U)
/*! TMLSZ - Tightly-coupled Memory Lower Size */
#define MSCM_CPxCFG2_TMLSZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG2_TMLSZ_SHIFT)) & MSCM_CPxCFG2_TMLSZ_MASK)
/*! @} */

/*! @name CPxCFG3 - Processor X Configuration Register 3 */
/*! @{ */

#define MSCM_CPxCFG3_FPU_MASK                    (0x1U)
#define MSCM_CPxCFG3_FPU_SHIFT                   (0U)
/*! FPU - Floating Point Unit
 *  0b0..FPU support is not included.
 *  0b1..FPU support is included.
 */
#define MSCM_CPxCFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_FPU_SHIFT)) & MSCM_CPxCFG3_FPU_MASK)

#define MSCM_CPxCFG3_SIMD_MASK                   (0x2U)
#define MSCM_CPxCFG3_SIMD_SHIFT                  (1U)
/*! SIMD - SIMD/NEON instruction support
 *  0b0..SIMD/NEON support is not included.
 *  0b1..SIMD/NEON support is included.
 */
#define MSCM_CPxCFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_SIMD_SHIFT)) & MSCM_CPxCFG3_SIMD_MASK)

#define MSCM_CPxCFG3_JAZ_MASK                    (0x4U)
#define MSCM_CPxCFG3_JAZ_SHIFT                   (2U)
/*! JAZ - Jazelle support
 *  0b0..Jazelle support is not included.
 *  0b1..Jazelle support is included.
 */
#define MSCM_CPxCFG3_JAZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_JAZ_SHIFT)) & MSCM_CPxCFG3_JAZ_MASK)

#define MSCM_CPxCFG3_MMU_MASK                    (0x8U)
#define MSCM_CPxCFG3_MMU_SHIFT                   (3U)
/*! MMU - Memory Management Unit
 *  0b0..MMU support is not included.
 *  0b1..MMU support is included.
 */
#define MSCM_CPxCFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_MMU_SHIFT)) & MSCM_CPxCFG3_MMU_MASK)

#define MSCM_CPxCFG3_TZ_MASK                     (0x10U)
#define MSCM_CPxCFG3_TZ_SHIFT                    (4U)
/*! TZ - Trust Zone
 *  0b0..Trust Zone support is not included.
 *  0b1..Trust Zone support is included.
 */
#define MSCM_CPxCFG3_TZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_TZ_SHIFT)) & MSCM_CPxCFG3_TZ_MASK)

#define MSCM_CPxCFG3_CMP_MASK                    (0x20U)
#define MSCM_CPxCFG3_CMP_SHIFT                   (5U)
/*! CMP - Core Memory Protection unit
 *  0b0..Core Memory Protection is not included.
 *  0b1..Core Memory Protection is included.
 */
#define MSCM_CPxCFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_CMP_SHIFT)) & MSCM_CPxCFG3_CMP_MASK)

#define MSCM_CPxCFG3_BB_MASK                     (0x40U)
#define MSCM_CPxCFG3_BB_SHIFT                    (6U)
/*! BB - Bit Banding
 *  0b0..Bit Banding is not supported.
 *  0b1..Bit Banding is supported.
 */
#define MSCM_CPxCFG3_BB(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_BB_SHIFT)) & MSCM_CPxCFG3_BB_MASK)

#define MSCM_CPxCFG3_SBP_MASK                    (0x300U)
#define MSCM_CPxCFG3_SBP_SHIFT                   (8U)
/*! SBP - System Bus Ports */
#define MSCM_CPxCFG3_SBP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPxCFG3_SBP_SHIFT)) & MSCM_CPxCFG3_SBP_MASK)
/*! @} */

/*! @name TYPE - Processor 0 Type Register */
/*! @{ */

#define MSCM_TYPE_RYPZ_MASK                      (0xFFU)
#define MSCM_TYPE_RYPZ_SHIFT                     (0U)
/*! RYPZ - Processor 0 Revision */
#define MSCM_TYPE_RYPZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_TYPE_RYPZ_SHIFT)) & MSCM_TYPE_RYPZ_MASK)

#define MSCM_TYPE_PERSONALITY_MASK               (0xFFFFFF00U)
#define MSCM_TYPE_PERSONALITY_SHIFT              (8U)
/*! PERSONALITY - Processor 0 Personality */
#define MSCM_TYPE_PERSONALITY(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_TYPE_PERSONALITY_SHIFT)) & MSCM_TYPE_PERSONALITY_MASK)
/*! @} */

/* The count of MSCM_TYPE */
#define MSCM_TYPE_COUNT                          (1U)

/*! @name NUM - Processor 0 Number Register */
/*! @{ */

#define MSCM_NUM_CPN_MASK                        (0x1U)
#define MSCM_NUM_CPN_SHIFT                       (0U)
/*! CPN - Processor 0 Number */
#define MSCM_NUM_CPN(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_NUM_CPN_SHIFT)) & MSCM_NUM_CPN_MASK)
/*! @} */

/* The count of MSCM_NUM */
#define MSCM_NUM_COUNT                           (1U)

/*! @name MASTER - Processor 0 Master Register */
/*! @{ */

#define MSCM_MASTER_PPMN_MASK                    (0x3FU)
#define MSCM_MASTER_PPMN_SHIFT                   (0U)
/*! PPMN - Processor 0 Physical Master Number */
#define MSCM_MASTER_PPMN(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_MASTER_PPMN_SHIFT)) & MSCM_MASTER_PPMN_MASK)
/*! @} */

/* The count of MSCM_MASTER */
#define MSCM_MASTER_COUNT                        (1U)

/*! @name COUNT - Processor 0 Count Register */
/*! @{ */

#define MSCM_COUNT_PCNT_MASK                     (0x3U)
#define MSCM_COUNT_PCNT_SHIFT                    (0U)
/*! PCNT - Processor Count */
#define MSCM_COUNT_PCNT(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_COUNT_PCNT_SHIFT)) & MSCM_COUNT_PCNT_MASK)
/*! @} */

/* The count of MSCM_COUNT */
#define MSCM_COUNT_COUNT                         (1U)

/*! @name CFG0 - Processor 0 Configuration Register 0 */
/*! @{ */

#define MSCM_CFG0_DCWY_MASK                      (0xFFU)
#define MSCM_CFG0_DCWY_SHIFT                     (0U)
/*! DCWY - Level 1 Data Cache Ways */
#define MSCM_CFG0_DCWY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_DCWY_SHIFT)) & MSCM_CFG0_DCWY_MASK)

#define MSCM_CFG0_DCSZ_MASK                      (0xFF00U)
#define MSCM_CFG0_DCSZ_SHIFT                     (8U)
/*! DCSZ - Level 1 Data Cache Size */
#define MSCM_CFG0_DCSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_DCSZ_SHIFT)) & MSCM_CFG0_DCSZ_MASK)

#define MSCM_CFG0_ICWY_MASK                      (0xFF0000U)
#define MSCM_CFG0_ICWY_SHIFT                     (16U)
/*! ICWY - Level 1 Instruction Cache Ways */
#define MSCM_CFG0_ICWY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_ICWY_SHIFT)) & MSCM_CFG0_ICWY_MASK)

#define MSCM_CFG0_ICSZ_MASK                      (0xFF000000U)
#define MSCM_CFG0_ICSZ_SHIFT                     (24U)
/*! ICSZ - Level 1 Instruction Cache Size */
#define MSCM_CFG0_ICSZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG0_ICSZ_SHIFT)) & MSCM_CFG0_ICSZ_MASK)
/*! @} */

/* The count of MSCM_CFG0 */
#define MSCM_CFG0_COUNT                          (1U)

/*! @name CFG1 - Processor 0 Configuration Register 1 */
/*! @{ */

#define MSCM_CFG1_L2WY_MASK                      (0xFF0000U)
#define MSCM_CFG1_L2WY_SHIFT                     (16U)
/*! L2WY - Level 2 Instruction Cache Ways */
#define MSCM_CFG1_L2WY(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG1_L2WY_SHIFT)) & MSCM_CFG1_L2WY_MASK)

#define MSCM_CFG1_L2SZ_MASK                      (0xFF000000U)
#define MSCM_CFG1_L2SZ_SHIFT                     (24U)
/*! L2SZ - Level 2 Instruction Cache Size */
#define MSCM_CFG1_L2SZ(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG1_L2SZ_SHIFT)) & MSCM_CFG1_L2SZ_MASK)
/*! @} */

/* The count of MSCM_CFG1 */
#define MSCM_CFG1_COUNT                          (1U)

/*! @name CFG2 - Processor 0 Configuration Register 2 */
/*! @{ */

#define MSCM_CFG2_TMUSZ_MASK                     (0xFF00U)
#define MSCM_CFG2_TMUSZ_SHIFT                    (8U)
/*! TMUSZ - Tightly-coupled Memory Upper Size */
#define MSCM_CFG2_TMUSZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CFG2_TMUSZ_SHIFT)) & MSCM_CFG2_TMUSZ_MASK)

#define MSCM_CFG2_TMLSZ_MASK                     (0xFF000000U)
#define MSCM_CFG2_TMLSZ_SHIFT                    (24U)
/*! TMLSZ - Tightly-coupled Memory Lower Size */
#define MSCM_CFG2_TMLSZ(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CFG2_TMLSZ_SHIFT)) & MSCM_CFG2_TMLSZ_MASK)
/*! @} */

/* The count of MSCM_CFG2 */
#define MSCM_CFG2_COUNT                          (1U)

/*! @name CFG3 - Processor 0 Configuration Register 3 */
/*! @{ */

#define MSCM_CFG3_FPU_MASK                       (0x1U)
#define MSCM_CFG3_FPU_SHIFT                      (0U)
/*! FPU - Floating Point Unit
 *  0b0..FPU support is not included.
 *  0b1..FPU support is included.
 */
#define MSCM_CFG3_FPU(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_FPU_SHIFT)) & MSCM_CFG3_FPU_MASK)

#define MSCM_CFG3_SIMD_MASK                      (0x2U)
#define MSCM_CFG3_SIMD_SHIFT                     (1U)
/*! SIMD - SIMD/NEON instruction support
 *  0b0..SIMD/NEON support is not included.
 *  0b1..SIMD/NEON support is included.
 */
#define MSCM_CFG3_SIMD(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_SIMD_SHIFT)) & MSCM_CFG3_SIMD_MASK)

#define MSCM_CFG3_JAZ_MASK                       (0x4U)
#define MSCM_CFG3_JAZ_SHIFT                      (2U)
/*! JAZ - Jazelle support
 *  0b0..Jazelle support is not included.
 *  0b1..Jazelle support is included.
 */
#define MSCM_CFG3_JAZ(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_JAZ_SHIFT)) & MSCM_CFG3_JAZ_MASK)

#define MSCM_CFG3_MMU_MASK                       (0x8U)
#define MSCM_CFG3_MMU_SHIFT                      (3U)
/*! MMU - Memory Management Unit
 *  0b0..MMU support is not included.
 *  0b1..MMU support is included.
 */
#define MSCM_CFG3_MMU(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_MMU_SHIFT)) & MSCM_CFG3_MMU_MASK)

#define MSCM_CFG3_TZ_MASK                        (0x10U)
#define MSCM_CFG3_TZ_SHIFT                       (4U)
/*! TZ - Trust Zone
 *  0b0..Trust Zone support is not included.
 *  0b1..Trust Zone support is included.
 */
#define MSCM_CFG3_TZ(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_TZ_SHIFT)) & MSCM_CFG3_TZ_MASK)

#define MSCM_CFG3_CMP_MASK                       (0x20U)
#define MSCM_CFG3_CMP_SHIFT                      (5U)
/*! CMP - Core Memory Protection unit
 *  0b0..Core Memory Protection is not included.
 *  0b1..Core Memory Protection is included.
 */
#define MSCM_CFG3_CMP(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_CMP_SHIFT)) & MSCM_CFG3_CMP_MASK)

#define MSCM_CFG3_BB_MASK                        (0x40U)
#define MSCM_CFG3_BB_SHIFT                       (6U)
/*! BB - Bit Banding
 *  0b0..Bit Banding is not supported.
 *  0b1..Bit Banding is supported.
 */
#define MSCM_CFG3_BB(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_BB_SHIFT)) & MSCM_CFG3_BB_MASK)

#define MSCM_CFG3_SBP_MASK                       (0x300U)
#define MSCM_CFG3_SBP_SHIFT                      (8U)
/*! SBP - System Bus Ports */
#define MSCM_CFG3_SBP(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_CFG3_SBP_SHIFT)) & MSCM_CFG3_SBP_MASK)
/*! @} */

/* The count of MSCM_CFG3 */
#define MSCM_CFG3_COUNT                          (1U)

/*! @name OCMDR - On-Chip Memory Descriptor Register */
/*! @{ */

#define MSCM_OCMDR_OCM1_MASK                     (0x30U)
#define MSCM_OCMDR_OCM1_SHIFT                    (4U)
/*! OCM1 - OCMEM Control Field 1 */
#define MSCM_OCMDR_OCM1(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCM1_SHIFT)) & MSCM_OCMDR_OCM1_MASK)

#define MSCM_OCMDR_OCMPU_MASK                    (0x1000U)
#define MSCM_OCMDR_OCMPU_SHIFT                   (12U)
/*! OCMPU - OCMPU */
#define MSCM_OCMDR_OCMPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCMPU_SHIFT)) & MSCM_OCMDR_OCMPU_MASK)

#define MSCM_OCMDR_OCMT_MASK                     (0xE000U)
#define MSCM_OCMDR_OCMT_SHIFT                    (13U)
/*! OCMT - OCMT
 *  0b000..Reserved
 *  0b001..Reserved
 *  0b010..Reserved
 *  0b011..Reserved
 *  0b100..OCMEMn is a Program Flash.
 *  0b101..OCMEMn is a Data Flash.
 *  0b110..OCMEMn is an EEE.
 *  0b111..Reserved
 */
#define MSCM_OCMDR_OCMT(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCMT_SHIFT)) & MSCM_OCMDR_OCMT_MASK)

#define MSCM_OCMDR_RO_MASK                       (0x10000U)
#define MSCM_OCMDR_RO_SHIFT                      (16U)
/*! RO - RO
 *  0b0..Writes to the OCMDRn[11:0] are allowed
 *  0b1..Writes to the OCMDRn[11:0] are ignored
 */
#define MSCM_OCMDR_RO(x)                         (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_RO_SHIFT)) & MSCM_OCMDR_RO_MASK)

#define MSCM_OCMDR_OCMW_MASK                     (0xE0000U)
#define MSCM_OCMDR_OCMW_SHIFT                    (17U)
/*! OCMW - OCMW
 *  0b000-0b001..Reserved
 *  0b010..OCMEMn 32-bits wide
 *  0b011..OCMEMn 64-bits wide
 *  0b100..OCMEMn 128-bits wide
 *  0b101..OCMEMn 256-bits wide
 *  0b110-0b111..Reserved
 */
#define MSCM_OCMDR_OCMW(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCMW_SHIFT)) & MSCM_OCMDR_OCMW_MASK)

#define MSCM_OCMDR_OCMSZ_MASK                    (0xF000000U)
#define MSCM_OCMDR_OCMSZ_SHIFT                   (24U)
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
#define MSCM_OCMDR_OCMSZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCMSZ_SHIFT)) & MSCM_OCMDR_OCMSZ_MASK)

#define MSCM_OCMDR_OCMSZH_MASK                   (0x10000000U)
#define MSCM_OCMDR_OCMSZH_SHIFT                  (28U)
/*! OCMSZH - OCMSZH
 *  0b0..OCMEMn is a power-of-2 capacity.
 *  0b1..OCMEMn is not a power-of-2, with a capacity is 0.75 * OCMSZ.
 */
#define MSCM_OCMDR_OCMSZH(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_OCMSZH_SHIFT)) & MSCM_OCMDR_OCMSZH_MASK)

#define MSCM_OCMDR_V_MASK                        (0x80000000U)
#define MSCM_OCMDR_V_SHIFT                       (31U)
/*! V - V
 *  0b0..OCMEMn is not present.
 *  0b1..OCMEMn is present.
 */
#define MSCM_OCMDR_V(x)                          (((uint32_t)(((uint32_t)(x)) << MSCM_OCMDR_V_SHIFT)) & MSCM_OCMDR_V_MASK)
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

