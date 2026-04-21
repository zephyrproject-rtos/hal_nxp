/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K39_ETPU.h
 * @version 1.7
 * @date 2022-11-18
 * @brief Peripheral Access Layer for S32K39_ETPU
 *
 * This file contains register definitions and macros for easy access to their
 * bit fields.
 *
 * This file assumes LITTLE endian system.
 */

/**
* @page misra_violations MISRA-C:2012 violations
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.3, local typedef not referenced
* The SoC header defines typedef for all modules.
*
* @section [global]
* Violates MISRA 2012 Advisory Rule 2.5, local macro not referenced
* The SoC header defines macros for all modules and registers.
*
* @section [global]
* Violates MISRA 2012 Advisory Directive 4.9, Function-like macro
* These are generated macros used for accessing the bit-fields from registers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.1, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.2, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.4, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 5.5, identifier clash
* The supported compilers use more than 31 significant characters for identifiers.
*
* @section [global]
* Violates MISRA 2012 Required Rule 21.1, defined macro '__I' is reserved to the compiler
* This type qualifier is needed to ensure correct I/O access and addressing.
*/

/* Prevention from multiple including the same memory map */
#if !defined(S32K39_ETPU_H_)  /* Check if memory map has not been already included */
#define S32K39_ETPU_H_

#include "S32K39_COMMON.h"

/* ----------------------------------------------------------------------------
   -- ETPU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETPU_Peripheral_Access_Layer ETPU Peripheral Access Layer
 * @{
 */

/** ETPU - Size of Registers Arrays */
#define ETPU_CCR_ENG1_COUNT                       32u
#define ETPU_CCR_ENG2_COUNT                       32u

/** ETPU - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< eTPU Module Configuration Register, offset: 0x0 */
  __IO uint32_t CDCR;                              /**< eTPU Coherent Dual-Parameter Controller Register, offset: 0x4 */
  uint8_t RESERVED_0[4];
  __IO uint32_t MISCCMPR;                          /**< eTPU MISC Compare Register, offset: 0xC */
  __IO uint32_t SCMOFFDATAR;                       /**< eTPU SCM Off-range Data Register, offset: 0x10 */
  __IO uint32_t ECR_ENG1;                          /**< eTPU Engine 1 Configuration Register, offset: 0x14 */
  __IO uint32_t ECR_ENG2;                          /**< eTPU Engine 2 Configuration Register, offset: 0x18 */
  uint8_t RESERVED_1[4];
  __IO uint32_t TBCR_ENG1;                         /**< eTPU Engine 1 Time Base Configuration Register, offset: 0x20 */
  __I  uint32_t TB1R_ENG1;                         /**< eTPU Engine 1 Time Base 1 (TCR1) Visibility Register, offset: 0x24 */
  __I  uint32_t TB2R_ENG1;                         /**< eTPU Engine 1 Time Base 2 (TCR2) Visibility Register, offset: 0x28 */
  __IO uint32_t STAC_ENG1;                         /**< eTPU Engine 1 STAC Configuration Register, offset: 0x2C */
  uint8_t RESERVED_2[16];
  __IO uint32_t TBCR_ENG2;                         /**< eTPU Engine 2 Time Base Configuration Register, offset: 0x40 */
  __I  uint32_t TB1R_ENG2;                         /**< eTPU Engine 2 Time Base 1 (TCR1) Visibility Register, offset: 0x44 */
  __I  uint32_t TB2R_ENG2;                         /**< eTPU Engine 2 Time Base 2 (TCR2) Visibility Register, offset: 0x48 */
  __IO uint32_t STAC_ENG2;                         /**< eTPU Engine 2 STAC Configuration Register, offset: 0x4C */
  uint8_t RESERVED_3[16];
  __IO uint32_t WDTR_ENG1;                         /**< eTPU Watchdog Timer Register for Engine 1, offset: 0x60 */
  uint8_t RESERVED_4[4];
  __IO uint32_t IDLER_ENG1;                        /**< eTPU Idle Register for Engine 1, offset: 0x68 */
  uint8_t RESERVED_5[4];
  __IO uint32_t WDTR_ENG2;                         /**< eTPU Watchdog Timer Register for Engine 2, offset: 0x70 */
  uint8_t RESERVED_6[4];
  __IO uint32_t IDLER_ENG2;                        /**< eTPU Idle Register for Engine 2, offset: 0x78 */
  uint8_t RESERVED_7[132];
  __IO uint32_t MECR;                              /**< eTPU Memory Error Control Register, offset: 0x100 */
  __IO uint32_t DEIAR;                             /**< eTPU Data Error Injection Address Register, offset: 0x104 */
  __IO uint32_t DEIDPR;                            /**< eTPU Data Error Injection Data Pattern Register, offset: 0x108 */
  __IO uint32_t DEIPPR;                            /**< eTPU Data Error Injection Parity Pattern Register, offset: 0x10C */
  __I  uint32_t DERAR;                             /**< eTPU Data Error Report Address Register, offset: 0x110 */
  __I  uint32_t DERDR;                             /**< eTPU Data Error Report Data Register, offset: 0x114 */
  __I  uint32_t DERSR;                             /**< eTPU Data Error Report Syndrome Register, offset: 0x118 */
  uint8_t RESERVED_8[4];
  __IO uint32_t MESR;                              /**< eTPU Memory Error Status Register, offset: 0x120 */
  __IO uint32_t CEIAR;                             /**< eTPU Code Error Injection Address Register, offset: 0x124 */
  __IO uint32_t CEIDPR;                            /**< eTPU Code Error Injection Data Pattern Register, offset: 0x128 */
  __IO uint32_t CEIPPR;                            /**< eTPU Code Error Injection Parity Pattern Register, offset: 0x12C */
  __I  uint32_t CERAR;                             /**< eTPU Code Error Report Address Register, offset: 0x130 */
  __I  uint32_t CERDR;                             /**< eTPU Code Error Report Data Register, offset: 0x134 */
  __I  uint32_t CERSR;                             /**< eTPU Code Error Report Syndrome Register, offset: 0x138 */
  __IO uint32_t CEFR;                              /**< eTPU Code Error Fix Register, offset: 0x13C */
  uint8_t RESERVED_9[192];
  __IO uint32_t CISR_ENG1;                         /**< eTPU Channel Interrupt Status Register for Engine 1, offset: 0x200 */
  __IO uint32_t CISR_ENG2;                         /**< eTPU Channel Interrupt Status Register for Engine 2, offset: 0x204 */
  uint8_t RESERVED_10[8];
  __IO uint32_t CDTRSR_ENG1;                       /**< eTPU Channel Data Transfer Request Status Register for Engine 1, offset: 0x210 */
  __IO uint32_t CDTRSR_ENG2;                       /**< eTPU Channel Data Transfer Request Status Register for Engine 2, offset: 0x214 */
  uint8_t RESERVED_11[8];
  __IO uint32_t CIOSR_ENG1;                        /**< eTPU Channel Interrupt Overflow Status Register for Engine 1, offset: 0x220 */
  __IO uint32_t CIOSR_ENG2;                        /**< eTPU Channel Interrupt Overflow Status Register for Engine 2, offset: 0x224 */
  uint8_t RESERVED_12[8];
  __IO uint32_t CDTROSR_ENG1;                      /**< eTPU Channel Data Transfer Request Overflow Status Register for Engine 1, offset: 0x230 */
  __IO uint32_t CDTROSR_ENG2;                      /**< eTPU Channel Data Transfer Request Overflow Status Register for Engine 2, offset: 0x234 */
  uint8_t RESERVED_13[8];
  __IO uint32_t CIER_ENG1;                         /**< eTPU Channel Interrupt Enable Register for Engine 1, offset: 0x240 */
  __IO uint32_t CIER_ENG2;                         /**< eTPU Channel Interrupt Enable Register for Engine 2, offset: 0x244 */
  uint8_t RESERVED_14[8];
  __IO uint32_t CDTRER_ENG1;                       /**< eTPU Channel Data Transfer Request Enable Register for Engine 1, offset: 0x250 */
  __IO uint32_t CDTRER_ENG2;                       /**< eTPU Channel Data Transfer Request Enable Register for Engine 2, offset: 0x254 */
  uint8_t RESERVED_15[8];
  __IO uint32_t WDSR_ENG1;                         /**< eTPU Watchdog Status Register for Engine 1, offset: 0x260 */
  __IO uint32_t WDSR_ENG2;                         /**< eTPU Watchdog Status Register for Engine 2, offset: 0x264 */
  uint8_t RESERVED_16[24];
  __I  uint32_t CPSSR_ENG1;                        /**< eTPU Channel Pending Service Status Register for Engine 1, offset: 0x280 */
  __I  uint32_t CPSSR_ENG2;                        /**< eTPU Channel Pending Service Status Register for Engine 2, offset: 0x284 */
  uint8_t RESERVED_17[8];
  __I  uint32_t CSSR_ENG1;                         /**< eTPU Channel Service Status Register for Engine 1, offset: 0x290 */
  __I  uint32_t CSSR_ENG2;                         /**< eTPU Channel Service Status Register for Engine 2, offset: 0x294 */
  uint8_t RESERVED_18[360];
  struct {                                         /* offset: 0x400, array step: 0x10 */
    __IO uint32_t CCR_ENG1;                          /**< eTPU Channel n Configuration Register for Engine 1, array offset: 0x400, array step: 0x10 */
    __IO uint32_t CSCR_ENG1;                         /**< eTPU Channel n Status Control Register for Engine 1, array offset: 0x404, array step: 0x10 */
    __IO uint32_t CHSRR_ENG1;                        /**< eTPU Channel n Host Service Request Register for Engine 1, array offset: 0x408, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CCR_ENG1[ETPU_CCR_ENG1_COUNT];
  uint8_t RESERVED_19[512];
  struct {                                         /* offset: 0x800, array step: 0x10 */
    __IO uint32_t CCR_ENG2;                          /**< eTPU Channel n Configuration Register for Engine 2, array offset: 0x800, array step: 0x10 */
    __IO uint32_t CSCR_ENG2;                         /**< eTPU Channel n Status Control Register for Engine 2, array offset: 0x804, array step: 0x10 */
    __IO uint32_t CHSRR_ENG2;                        /**< eTPU Channel n Host Service Request Register for Engine 2, array offset: 0x808, array step: 0x10 */
    uint8_t RESERVED_0[4];
  } CCR_ENG2[ETPU_CCR_ENG2_COUNT];
} ETPU_Type, *ETPU_MemMapPtr;

/** Number of instances of the ETPU module. */
#define ETPU_INSTANCE_COUNT                      (6u)

/* ETPU - Peripheral instance base addresses */
/** Peripheral ETPU_0 base address */
#define IP_ETPU_0_BASE                           (0x40680000u)
/** Peripheral ETPU_0 base pointer */
#define IP_ETPU_0                                ((ETPU_Type *)IP_ETPU_0_BASE)
/** Peripheral ETPU_1 base address */
#define IP_ETPU_1_BASE                           (0x40680000u)
/** Peripheral ETPU_1 base pointer */
#define IP_ETPU_1                                ((ETPU_Type *)IP_ETPU_1_BASE)
/** Peripheral ETPU_2 base address */
#define IP_ETPU_2_BASE                           (0x40680000u)
/** Peripheral ETPU_2 base pointer */
#define IP_ETPU_2                                ((ETPU_Type *)IP_ETPU_2_BASE)
/** Peripheral ETPU_3 base address */
#define IP_ETPU_3_BASE                           (0x40680000u)
/** Peripheral ETPU_3 base pointer */
#define IP_ETPU_3                                ((ETPU_Type *)IP_ETPU_3_BASE)
/** Peripheral ETPU_4 base address */
#define IP_ETPU_4_BASE                           (0x40680000u)
/** Peripheral ETPU_4 base pointer */
#define IP_ETPU_4                                ((ETPU_Type *)IP_ETPU_4_BASE)
/** Peripheral ETPU_6 base address */
#define IP_ETPU_6_BASE                           (0x40680000u)
/** Peripheral ETPU_6 base pointer */
#define IP_ETPU_6                                ((ETPU_Type *)IP_ETPU_6_BASE)
/** Array initializer of ETPU peripheral base addresses */
#define IP_ETPU_BASE_ADDRS                       { IP_ETPU_0_BASE, IP_ETPU_1_BASE, IP_ETPU_2_BASE, IP_ETPU_3_BASE, IP_ETPU_4_BASE, IP_ETPU_6_BASE }
/** Array initializer of ETPU peripheral base pointers */
#define IP_ETPU_BASE_PTRS                        { IP_ETPU_0, IP_ETPU_1, IP_ETPU_2, IP_ETPU_3, IP_ETPU_4, IP_ETPU_6 }

/* ----------------------------------------------------------------------------
   -- ETPU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ETPU_Register_Masks ETPU Register Masks
 * @{
 */

/*! @name MCR - eTPU Module Configuration Register */
/*! @{ */

#define ETPU_MCR_GTBE_MASK                       (0x1U)
#define ETPU_MCR_GTBE_SHIFT                      (0U)
#define ETPU_MCR_GTBE_WIDTH                      (1U)
#define ETPU_MCR_GTBE(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_GTBE_SHIFT)) & ETPU_MCR_GTBE_MASK)

#define ETPU_MCR_VIS_MASK                        (0x40U)
#define ETPU_MCR_VIS_SHIFT                       (6U)
#define ETPU_MCR_VIS_WIDTH                       (1U)
#define ETPU_MCR_VIS(x)                          (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_VIS_SHIFT)) & ETPU_MCR_VIS_MASK)

#define ETPU_MCR_SCMERR_MASK                     (0x100U)
#define ETPU_MCR_SCMERR_SHIFT                    (8U)
#define ETPU_MCR_SCMERR_WIDTH                    (1U)
#define ETPU_MCR_SCMERR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SCMERR_SHIFT)) & ETPU_MCR_SCMERR_MASK)

#define ETPU_MCR_SCMMISEN_MASK                   (0x200U)
#define ETPU_MCR_SCMMISEN_SHIFT                  (9U)
#define ETPU_MCR_SCMMISEN_WIDTH                  (1U)
#define ETPU_MCR_SCMMISEN(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SCMMISEN_SHIFT)) & ETPU_MCR_SCMMISEN_MASK)

#define ETPU_MCR_SCMMISF_MASK                    (0x400U)
#define ETPU_MCR_SCMMISF_SHIFT                   (10U)
#define ETPU_MCR_SCMMISF_WIDTH                   (1U)
#define ETPU_MCR_SCMMISF(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SCMMISF_SHIFT)) & ETPU_MCR_SCMMISF_MASK)

#define ETPU_MCR_SCMMISC_MASK                    (0x800U)
#define ETPU_MCR_SCMMISC_SHIFT                   (11U)
#define ETPU_MCR_SCMMISC_WIDTH                   (1U)
#define ETPU_MCR_SCMMISC(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SCMMISC_SHIFT)) & ETPU_MCR_SCMMISC_MASK)

#define ETPU_MCR_SCMSIZE_MASK                    (0x1F0000U)
#define ETPU_MCR_SCMSIZE_SHIFT                   (16U)
#define ETPU_MCR_SCMSIZE_WIDTH                   (5U)
#define ETPU_MCR_SCMSIZE(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SCMSIZE_SHIFT)) & ETPU_MCR_SCMSIZE_MASK)

#define ETPU_MCR_SSAERR_MASK                     (0x800000U)
#define ETPU_MCR_SSAERR_SHIFT                    (23U)
#define ETPU_MCR_SSAERR_WIDTH                    (1U)
#define ETPU_MCR_SSAERR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SSAERR_SHIFT)) & ETPU_MCR_SSAERR_MASK)

#define ETPU_MCR_ILF2_MASK                       (0x1000000U)
#define ETPU_MCR_ILF2_SHIFT                      (24U)
#define ETPU_MCR_ILF2_WIDTH                      (1U)
#define ETPU_MCR_ILF2(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_ILF2_SHIFT)) & ETPU_MCR_ILF2_MASK)

#define ETPU_MCR_ILF1_MASK                       (0x2000000U)
#define ETPU_MCR_ILF1_SHIFT                      (25U)
#define ETPU_MCR_ILF1_WIDTH                      (1U)
#define ETPU_MCR_ILF1(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_ILF1_SHIFT)) & ETPU_MCR_ILF1_MASK)

#define ETPU_MCR_MGE2_MASK                       (0x4000000U)
#define ETPU_MCR_MGE2_SHIFT                      (26U)
#define ETPU_MCR_MGE2_WIDTH                      (1U)
#define ETPU_MCR_MGE2(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_MGE2_SHIFT)) & ETPU_MCR_MGE2_MASK)

#define ETPU_MCR_MGE1_MASK                       (0x8000000U)
#define ETPU_MCR_MGE1_SHIFT                      (27U)
#define ETPU_MCR_MGE1_WIDTH                      (1U)
#define ETPU_MCR_MGE1(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_MGE1_SHIFT)) & ETPU_MCR_MGE1_MASK)

#define ETPU_MCR_WDTO2_MASK                      (0x10000000U)
#define ETPU_MCR_WDTO2_SHIFT                     (28U)
#define ETPU_MCR_WDTO2_WIDTH                     (1U)
#define ETPU_MCR_WDTO2(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_WDTO2_SHIFT)) & ETPU_MCR_WDTO2_MASK)

#define ETPU_MCR_WDTO1_MASK                      (0x20000000U)
#define ETPU_MCR_WDTO1_SHIFT                     (29U)
#define ETPU_MCR_WDTO1_WIDTH                     (1U)
#define ETPU_MCR_WDTO1(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_WDTO1_SHIFT)) & ETPU_MCR_WDTO1_MASK)

#define ETPU_MCR_SDMERR_MASK                     (0x40000000U)
#define ETPU_MCR_SDMERR_SHIFT                    (30U)
#define ETPU_MCR_SDMERR_WIDTH                    (1U)
#define ETPU_MCR_SDMERR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_SDMERR_SHIFT)) & ETPU_MCR_SDMERR_MASK)

#define ETPU_MCR_GEC_MASK                        (0x80000000U)
#define ETPU_MCR_GEC_SHIFT                       (31U)
#define ETPU_MCR_GEC_WIDTH                       (1U)
#define ETPU_MCR_GEC(x)                          (((uint32_t)(((uint32_t)(x)) << ETPU_MCR_GEC_SHIFT)) & ETPU_MCR_GEC_MASK)
/*! @} */

/*! @name CDCR - eTPU Coherent Dual-Parameter Controller Register */
/*! @{ */

#define ETPU_CDCR_PARM1_MASK                     (0x7FU)
#define ETPU_CDCR_PARM1_SHIFT                    (0U)
#define ETPU_CDCR_PARM1_WIDTH                    (7U)
#define ETPU_CDCR_PARM1(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_PARM1_SHIFT)) & ETPU_CDCR_PARM1_MASK)

#define ETPU_CDCR_WR_MASK                        (0x80U)
#define ETPU_CDCR_WR_SHIFT                       (7U)
#define ETPU_CDCR_WR_WIDTH                       (1U)
#define ETPU_CDCR_WR(x)                          (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_WR_SHIFT)) & ETPU_CDCR_WR_MASK)

#define ETPU_CDCR_PARM0_MASK                     (0x7F00U)
#define ETPU_CDCR_PARM0_SHIFT                    (8U)
#define ETPU_CDCR_PARM0_WIDTH                    (7U)
#define ETPU_CDCR_PARM0(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_PARM0_SHIFT)) & ETPU_CDCR_PARM0_MASK)

#define ETPU_CDCR_PWIDTH_MASK                    (0x8000U)
#define ETPU_CDCR_PWIDTH_SHIFT                   (15U)
#define ETPU_CDCR_PWIDTH_WIDTH                   (1U)
#define ETPU_CDCR_PWIDTH(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_PWIDTH_SHIFT)) & ETPU_CDCR_PWIDTH_MASK)

#define ETPU_CDCR_PBBASE_MASK                    (0x3FF0000U)
#define ETPU_CDCR_PBBASE_SHIFT                   (16U)
#define ETPU_CDCR_PBBASE_WIDTH                   (10U)
#define ETPU_CDCR_PBBASE(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_PBBASE_SHIFT)) & ETPU_CDCR_PBBASE_MASK)

#define ETPU_CDCR_CTBASE_MASK                    (0x7C000000U)
#define ETPU_CDCR_CTBASE_SHIFT                   (26U)
#define ETPU_CDCR_CTBASE_WIDTH                   (5U)
#define ETPU_CDCR_CTBASE(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_CTBASE_SHIFT)) & ETPU_CDCR_CTBASE_MASK)

#define ETPU_CDCR_STS_MASK                       (0x80000000U)
#define ETPU_CDCR_STS_SHIFT                      (31U)
#define ETPU_CDCR_STS_WIDTH                      (1U)
#define ETPU_CDCR_STS(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_CDCR_STS_SHIFT)) & ETPU_CDCR_STS_MASK)
/*! @} */

/*! @name MISCCMPR - eTPU MISC Compare Register */
/*! @{ */

#define ETPU_MISCCMPR_ETPUMISCCMP_MASK           (0xFFFFFFFFU)
#define ETPU_MISCCMPR_ETPUMISCCMP_SHIFT          (0U)
#define ETPU_MISCCMPR_ETPUMISCCMP_WIDTH          (32U)
#define ETPU_MISCCMPR_ETPUMISCCMP(x)             (((uint32_t)(((uint32_t)(x)) << ETPU_MISCCMPR_ETPUMISCCMP_SHIFT)) & ETPU_MISCCMPR_ETPUMISCCMP_MASK)
/*! @} */

/*! @name SCMOFFDATAR - eTPU SCM Off-range Data Register */
/*! @{ */

#define ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR_MASK    (0xFFFFFFFFU)
#define ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR_SHIFT   (0U)
#define ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR_WIDTH   (32U)
#define ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR(x)      (((uint32_t)(((uint32_t)(x)) << ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR_SHIFT)) & ETPU_SCMOFFDATAR_ETPUSCMOFFDATAR_MASK)
/*! @} */

/*! @name ECR_ENG1 - eTPU Engine 1 Configuration Register */
/*! @{ */

#define ETPU_ECR_ENG1_ETB_MASK                   (0x1FU)
#define ETPU_ECR_ENG1_ETB_SHIFT                  (0U)
#define ETPU_ECR_ENG1_ETB_WIDTH                  (5U)
#define ETPU_ECR_ENG1_ETB(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_ETB_SHIFT)) & ETPU_ECR_ENG1_ETB_MASK)

#define ETPU_ECR_ENG1_SPPDIS_MASK                (0x80U)
#define ETPU_ECR_ENG1_SPPDIS_SHIFT               (7U)
#define ETPU_ECR_ENG1_SPPDIS_WIDTH               (1U)
#define ETPU_ECR_ENG1_SPPDIS(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_SPPDIS_SHIFT)) & ETPU_ECR_ENG1_SPPDIS_MASK)

#define ETPU_ECR_ENG1_ERBA_MASK                  (0x1F00U)
#define ETPU_ECR_ENG1_ERBA_SHIFT                 (8U)
#define ETPU_ECR_ENG1_ERBA_WIDTH                 (5U)
#define ETPU_ECR_ENG1_ERBA(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_ERBA_SHIFT)) & ETPU_ECR_ENG1_ERBA_MASK)

#define ETPU_ECR_ENG1_CDFC_MASK                  (0xC000U)
#define ETPU_ECR_ENG1_CDFC_SHIFT                 (14U)
#define ETPU_ECR_ENG1_CDFC_WIDTH                 (2U)
#define ETPU_ECR_ENG1_CDFC(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_CDFC_SHIFT)) & ETPU_ECR_ENG1_CDFC_MASK)

#define ETPU_ECR_ENG1_FPSCK_MASK                 (0x70000U)
#define ETPU_ECR_ENG1_FPSCK_SHIFT                (16U)
#define ETPU_ECR_ENG1_FPSCK_WIDTH                (3U)
#define ETPU_ECR_ENG1_FPSCK(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_FPSCK_SHIFT)) & ETPU_ECR_ENG1_FPSCK_MASK)

#define ETPU_ECR_ENG1_FCSS_MASK                  (0x80000U)
#define ETPU_ECR_ENG1_FCSS_SHIFT                 (19U)
#define ETPU_ECR_ENG1_FCSS_WIDTH                 (1U)
#define ETPU_ECR_ENG1_FCSS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_FCSS_SHIFT)) & ETPU_ECR_ENG1_FCSS_MASK)

#define ETPU_ECR_ENG1_HLTF_MASK                  (0x800000U)
#define ETPU_ECR_ENG1_HLTF_SHIFT                 (23U)
#define ETPU_ECR_ENG1_HLTF_WIDTH                 (1U)
#define ETPU_ECR_ENG1_HLTF(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_HLTF_SHIFT)) & ETPU_ECR_ENG1_HLTF_MASK)

#define ETPU_ECR_ENG1_STF_MASK                   (0x10000000U)
#define ETPU_ECR_ENG1_STF_SHIFT                  (28U)
#define ETPU_ECR_ENG1_STF_WIDTH                  (1U)
#define ETPU_ECR_ENG1_STF(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_STF_SHIFT)) & ETPU_ECR_ENG1_STF_MASK)

#define ETPU_ECR_ENG1_MDIS_MASK                  (0x40000000U)
#define ETPU_ECR_ENG1_MDIS_SHIFT                 (30U)
#define ETPU_ECR_ENG1_MDIS_WIDTH                 (1U)
#define ETPU_ECR_ENG1_MDIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_MDIS_SHIFT)) & ETPU_ECR_ENG1_MDIS_MASK)

#define ETPU_ECR_ENG1_FEND_MASK                  (0x80000000U)
#define ETPU_ECR_ENG1_FEND_SHIFT                 (31U)
#define ETPU_ECR_ENG1_FEND_WIDTH                 (1U)
#define ETPU_ECR_ENG1_FEND(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG1_FEND_SHIFT)) & ETPU_ECR_ENG1_FEND_MASK)
/*! @} */

/*! @name ECR_ENG2 - eTPU Engine 2 Configuration Register */
/*! @{ */

#define ETPU_ECR_ENG2_ETB_MASK                   (0x1FU)
#define ETPU_ECR_ENG2_ETB_SHIFT                  (0U)
#define ETPU_ECR_ENG2_ETB_WIDTH                  (5U)
#define ETPU_ECR_ENG2_ETB(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_ETB_SHIFT)) & ETPU_ECR_ENG2_ETB_MASK)

#define ETPU_ECR_ENG2_SPPDIS_MASK                (0x80U)
#define ETPU_ECR_ENG2_SPPDIS_SHIFT               (7U)
#define ETPU_ECR_ENG2_SPPDIS_WIDTH               (1U)
#define ETPU_ECR_ENG2_SPPDIS(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_SPPDIS_SHIFT)) & ETPU_ECR_ENG2_SPPDIS_MASK)

#define ETPU_ECR_ENG2_ERBA_MASK                  (0x1F00U)
#define ETPU_ECR_ENG2_ERBA_SHIFT                 (8U)
#define ETPU_ECR_ENG2_ERBA_WIDTH                 (5U)
#define ETPU_ECR_ENG2_ERBA(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_ERBA_SHIFT)) & ETPU_ECR_ENG2_ERBA_MASK)

#define ETPU_ECR_ENG2_CDFC_MASK                  (0xC000U)
#define ETPU_ECR_ENG2_CDFC_SHIFT                 (14U)
#define ETPU_ECR_ENG2_CDFC_WIDTH                 (2U)
#define ETPU_ECR_ENG2_CDFC(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_CDFC_SHIFT)) & ETPU_ECR_ENG2_CDFC_MASK)

#define ETPU_ECR_ENG2_FPSCK_MASK                 (0x70000U)
#define ETPU_ECR_ENG2_FPSCK_SHIFT                (16U)
#define ETPU_ECR_ENG2_FPSCK_WIDTH                (3U)
#define ETPU_ECR_ENG2_FPSCK(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_FPSCK_SHIFT)) & ETPU_ECR_ENG2_FPSCK_MASK)

#define ETPU_ECR_ENG2_FCSS_MASK                  (0x80000U)
#define ETPU_ECR_ENG2_FCSS_SHIFT                 (19U)
#define ETPU_ECR_ENG2_FCSS_WIDTH                 (1U)
#define ETPU_ECR_ENG2_FCSS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_FCSS_SHIFT)) & ETPU_ECR_ENG2_FCSS_MASK)

#define ETPU_ECR_ENG2_HLTF_MASK                  (0x800000U)
#define ETPU_ECR_ENG2_HLTF_SHIFT                 (23U)
#define ETPU_ECR_ENG2_HLTF_WIDTH                 (1U)
#define ETPU_ECR_ENG2_HLTF(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_HLTF_SHIFT)) & ETPU_ECR_ENG2_HLTF_MASK)

#define ETPU_ECR_ENG2_STF_MASK                   (0x10000000U)
#define ETPU_ECR_ENG2_STF_SHIFT                  (28U)
#define ETPU_ECR_ENG2_STF_WIDTH                  (1U)
#define ETPU_ECR_ENG2_STF(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_STF_SHIFT)) & ETPU_ECR_ENG2_STF_MASK)

#define ETPU_ECR_ENG2_MDIS_MASK                  (0x40000000U)
#define ETPU_ECR_ENG2_MDIS_SHIFT                 (30U)
#define ETPU_ECR_ENG2_MDIS_WIDTH                 (1U)
#define ETPU_ECR_ENG2_MDIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_MDIS_SHIFT)) & ETPU_ECR_ENG2_MDIS_MASK)

#define ETPU_ECR_ENG2_FEND_MASK                  (0x80000000U)
#define ETPU_ECR_ENG2_FEND_SHIFT                 (31U)
#define ETPU_ECR_ENG2_FEND_WIDTH                 (1U)
#define ETPU_ECR_ENG2_FEND(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_ECR_ENG2_FEND_SHIFT)) & ETPU_ECR_ENG2_FEND_MASK)
/*! @} */

/*! @name TBCR_ENG1 - eTPU Engine 1 Time Base Configuration Register */
/*! @{ */

#define ETPU_TBCR_ENG1_TCR1P_MASK                (0xFFU)
#define ETPU_TBCR_ENG1_TCR1P_SHIFT               (0U)
#define ETPU_TBCR_ENG1_TCR1P_WIDTH               (8U)
#define ETPU_TBCR_ENG1_TCR1P(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCR1P_SHIFT)) & ETPU_TBCR_ENG1_TCR1P_MASK)

#define ETPU_TBCR_ENG1_TCR1CS_MASK               (0x2000U)
#define ETPU_TBCR_ENG1_TCR1CS_SHIFT              (13U)
#define ETPU_TBCR_ENG1_TCR1CS_WIDTH              (1U)
#define ETPU_TBCR_ENG1_TCR1CS(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCR1CS_SHIFT)) & ETPU_TBCR_ENG1_TCR1CS_MASK)

#define ETPU_TBCR_ENG1_TCR1CTL_MASK              (0xC000U)
#define ETPU_TBCR_ENG1_TCR1CTL_SHIFT             (14U)
#define ETPU_TBCR_ENG1_TCR1CTL_WIDTH             (2U)
#define ETPU_TBCR_ENG1_TCR1CTL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCR1CTL_SHIFT)) & ETPU_TBCR_ENG1_TCR1CTL_MASK)

#define ETPU_TBCR_ENG1_TCR2P_MASK                (0x3F0000U)
#define ETPU_TBCR_ENG1_TCR2P_SHIFT               (16U)
#define ETPU_TBCR_ENG1_TCR2P_WIDTH               (6U)
#define ETPU_TBCR_ENG1_TCR2P(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCR2P_SHIFT)) & ETPU_TBCR_ENG1_TCR2P_MASK)

#define ETPU_TBCR_ENG1_ATGC_MASK                 (0x1000000U)
#define ETPU_TBCR_ENG1_ATGC_SHIFT                (24U)
#define ETPU_TBCR_ENG1_ATGC_WIDTH                (1U)
#define ETPU_TBCR_ENG1_ATGC(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_ATGC_SHIFT)) & ETPU_TBCR_ENG1_ATGC_MASK)

#define ETPU_TBCR_ENG1_AM_MASK                   (0x6000000U)
#define ETPU_TBCR_ENG1_AM_SHIFT                  (25U)
#define ETPU_TBCR_ENG1_AM_WIDTH                  (2U)
#define ETPU_TBCR_ENG1_AM(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_AM_SHIFT)) & ETPU_TBCR_ENG1_AM_MASK)

#define ETPU_TBCR_ENG1_TCRCF_MASK                (0x18000000U)
#define ETPU_TBCR_ENG1_TCRCF_SHIFT               (27U)
#define ETPU_TBCR_ENG1_TCRCF_WIDTH               (2U)
#define ETPU_TBCR_ENG1_TCRCF(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCRCF_SHIFT)) & ETPU_TBCR_ENG1_TCRCF_MASK)

#define ETPU_TBCR_ENG1_TCR2CTL_MASK              (0xE0000000U)
#define ETPU_TBCR_ENG1_TCR2CTL_SHIFT             (29U)
#define ETPU_TBCR_ENG1_TCR2CTL_WIDTH             (3U)
#define ETPU_TBCR_ENG1_TCR2CTL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG1_TCR2CTL_SHIFT)) & ETPU_TBCR_ENG1_TCR2CTL_MASK)
/*! @} */

/*! @name TB1R_ENG1 - eTPU Engine 1 Time Base 1 (TCR1) Visibility Register */
/*! @{ */

#define ETPU_TB1R_ENG1_TCR1_MASK                 (0xFFFFFFU)
#define ETPU_TB1R_ENG1_TCR1_SHIFT                (0U)
#define ETPU_TB1R_ENG1_TCR1_WIDTH                (24U)
#define ETPU_TB1R_ENG1_TCR1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TB1R_ENG1_TCR1_SHIFT)) & ETPU_TB1R_ENG1_TCR1_MASK)
/*! @} */

/*! @name TB2R_ENG1 - eTPU Engine 1 Time Base 2 (TCR2) Visibility Register */
/*! @{ */

#define ETPU_TB2R_ENG1_TCR2_MASK                 (0xFFFFFFU)
#define ETPU_TB2R_ENG1_TCR2_SHIFT                (0U)
#define ETPU_TB2R_ENG1_TCR2_WIDTH                (24U)
#define ETPU_TB2R_ENG1_TCR2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TB2R_ENG1_TCR2_SHIFT)) & ETPU_TB2R_ENG1_TCR2_MASK)
/*! @} */

/*! @name STAC_ENG1 - eTPU Engine 1 STAC Configuration Register */
/*! @{ */

#define ETPU_STAC_ENG1_SRV2_MASK                 (0xFU)
#define ETPU_STAC_ENG1_SRV2_SHIFT                (0U)
#define ETPU_STAC_ENG1_SRV2_WIDTH                (4U)
#define ETPU_STAC_ENG1_SRV2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_SRV2_SHIFT)) & ETPU_STAC_ENG1_SRV2_MASK)

#define ETPU_STAC_ENG1_SERVER_ID2_MASK           (0xF00U)
#define ETPU_STAC_ENG1_SERVER_ID2_SHIFT          (8U)
#define ETPU_STAC_ENG1_SERVER_ID2_WIDTH          (4U)
#define ETPU_STAC_ENG1_SERVER_ID2(x)             (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_SERVER_ID2_SHIFT)) & ETPU_STAC_ENG1_SERVER_ID2_MASK)

#define ETPU_STAC_ENG1_RSC2_MASK                 (0x4000U)
#define ETPU_STAC_ENG1_RSC2_SHIFT                (14U)
#define ETPU_STAC_ENG1_RSC2_WIDTH                (1U)
#define ETPU_STAC_ENG1_RSC2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_RSC2_SHIFT)) & ETPU_STAC_ENG1_RSC2_MASK)

#define ETPU_STAC_ENG1_REN2_MASK                 (0x8000U)
#define ETPU_STAC_ENG1_REN2_SHIFT                (15U)
#define ETPU_STAC_ENG1_REN2_WIDTH                (1U)
#define ETPU_STAC_ENG1_REN2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_REN2_SHIFT)) & ETPU_STAC_ENG1_REN2_MASK)

#define ETPU_STAC_ENG1_SRV1_MASK                 (0xF0000U)
#define ETPU_STAC_ENG1_SRV1_SHIFT                (16U)
#define ETPU_STAC_ENG1_SRV1_WIDTH                (4U)
#define ETPU_STAC_ENG1_SRV1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_SRV1_SHIFT)) & ETPU_STAC_ENG1_SRV1_MASK)

#define ETPU_STAC_ENG1_SERVER_ID1_MASK           (0xF000000U)
#define ETPU_STAC_ENG1_SERVER_ID1_SHIFT          (24U)
#define ETPU_STAC_ENG1_SERVER_ID1_WIDTH          (4U)
#define ETPU_STAC_ENG1_SERVER_ID1(x)             (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_SERVER_ID1_SHIFT)) & ETPU_STAC_ENG1_SERVER_ID1_MASK)

#define ETPU_STAC_ENG1_RSC1_MASK                 (0x40000000U)
#define ETPU_STAC_ENG1_RSC1_SHIFT                (30U)
#define ETPU_STAC_ENG1_RSC1_WIDTH                (1U)
#define ETPU_STAC_ENG1_RSC1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_RSC1_SHIFT)) & ETPU_STAC_ENG1_RSC1_MASK)

#define ETPU_STAC_ENG1_REN1_MASK                 (0x80000000U)
#define ETPU_STAC_ENG1_REN1_SHIFT                (31U)
#define ETPU_STAC_ENG1_REN1_WIDTH                (1U)
#define ETPU_STAC_ENG1_REN1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG1_REN1_SHIFT)) & ETPU_STAC_ENG1_REN1_MASK)
/*! @} */

/*! @name TBCR_ENG2 - eTPU Engine 2 Time Base Configuration Register */
/*! @{ */

#define ETPU_TBCR_ENG2_TCR1P_MASK                (0xFFU)
#define ETPU_TBCR_ENG2_TCR1P_SHIFT               (0U)
#define ETPU_TBCR_ENG2_TCR1P_WIDTH               (8U)
#define ETPU_TBCR_ENG2_TCR1P(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCR1P_SHIFT)) & ETPU_TBCR_ENG2_TCR1P_MASK)

#define ETPU_TBCR_ENG2_TCR1CS_MASK               (0x2000U)
#define ETPU_TBCR_ENG2_TCR1CS_SHIFT              (13U)
#define ETPU_TBCR_ENG2_TCR1CS_WIDTH              (1U)
#define ETPU_TBCR_ENG2_TCR1CS(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCR1CS_SHIFT)) & ETPU_TBCR_ENG2_TCR1CS_MASK)

#define ETPU_TBCR_ENG2_TCR1CTL_MASK              (0xC000U)
#define ETPU_TBCR_ENG2_TCR1CTL_SHIFT             (14U)
#define ETPU_TBCR_ENG2_TCR1CTL_WIDTH             (2U)
#define ETPU_TBCR_ENG2_TCR1CTL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCR1CTL_SHIFT)) & ETPU_TBCR_ENG2_TCR1CTL_MASK)

#define ETPU_TBCR_ENG2_TCR2P_MASK                (0x3F0000U)
#define ETPU_TBCR_ENG2_TCR2P_SHIFT               (16U)
#define ETPU_TBCR_ENG2_TCR2P_WIDTH               (6U)
#define ETPU_TBCR_ENG2_TCR2P(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCR2P_SHIFT)) & ETPU_TBCR_ENG2_TCR2P_MASK)

#define ETPU_TBCR_ENG2_ATGC_MASK                 (0x1000000U)
#define ETPU_TBCR_ENG2_ATGC_SHIFT                (24U)
#define ETPU_TBCR_ENG2_ATGC_WIDTH                (1U)
#define ETPU_TBCR_ENG2_ATGC(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_ATGC_SHIFT)) & ETPU_TBCR_ENG2_ATGC_MASK)

#define ETPU_TBCR_ENG2_AM_MASK                   (0x6000000U)
#define ETPU_TBCR_ENG2_AM_SHIFT                  (25U)
#define ETPU_TBCR_ENG2_AM_WIDTH                  (2U)
#define ETPU_TBCR_ENG2_AM(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_AM_SHIFT)) & ETPU_TBCR_ENG2_AM_MASK)

#define ETPU_TBCR_ENG2_TCRCF_MASK                (0x18000000U)
#define ETPU_TBCR_ENG2_TCRCF_SHIFT               (27U)
#define ETPU_TBCR_ENG2_TCRCF_WIDTH               (2U)
#define ETPU_TBCR_ENG2_TCRCF(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCRCF_SHIFT)) & ETPU_TBCR_ENG2_TCRCF_MASK)

#define ETPU_TBCR_ENG2_TCR2CTL_MASK              (0xE0000000U)
#define ETPU_TBCR_ENG2_TCR2CTL_SHIFT             (29U)
#define ETPU_TBCR_ENG2_TCR2CTL_WIDTH             (3U)
#define ETPU_TBCR_ENG2_TCR2CTL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_TBCR_ENG2_TCR2CTL_SHIFT)) & ETPU_TBCR_ENG2_TCR2CTL_MASK)
/*! @} */

/*! @name TB1R_ENG2 - eTPU Engine 2 Time Base 1 (TCR1) Visibility Register */
/*! @{ */

#define ETPU_TB1R_ENG2_TCR1_MASK                 (0xFFFFFFU)
#define ETPU_TB1R_ENG2_TCR1_SHIFT                (0U)
#define ETPU_TB1R_ENG2_TCR1_WIDTH                (24U)
#define ETPU_TB1R_ENG2_TCR1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TB1R_ENG2_TCR1_SHIFT)) & ETPU_TB1R_ENG2_TCR1_MASK)
/*! @} */

/*! @name TB2R_ENG2 - eTPU Engine 2 Time Base 2 (TCR2) Visibility Register */
/*! @{ */

#define ETPU_TB2R_ENG2_TCR2_MASK                 (0xFFFFFFU)
#define ETPU_TB2R_ENG2_TCR2_SHIFT                (0U)
#define ETPU_TB2R_ENG2_TCR2_WIDTH                (24U)
#define ETPU_TB2R_ENG2_TCR2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_TB2R_ENG2_TCR2_SHIFT)) & ETPU_TB2R_ENG2_TCR2_MASK)
/*! @} */

/*! @name STAC_ENG2 - eTPU Engine 2 STAC Configuration Register */
/*! @{ */

#define ETPU_STAC_ENG2_SRV2_MASK                 (0xFU)
#define ETPU_STAC_ENG2_SRV2_SHIFT                (0U)
#define ETPU_STAC_ENG2_SRV2_WIDTH                (4U)
#define ETPU_STAC_ENG2_SRV2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_SRV2_SHIFT)) & ETPU_STAC_ENG2_SRV2_MASK)

#define ETPU_STAC_ENG2_SERVER_ID2_MASK           (0xF00U)
#define ETPU_STAC_ENG2_SERVER_ID2_SHIFT          (8U)
#define ETPU_STAC_ENG2_SERVER_ID2_WIDTH          (4U)
#define ETPU_STAC_ENG2_SERVER_ID2(x)             (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_SERVER_ID2_SHIFT)) & ETPU_STAC_ENG2_SERVER_ID2_MASK)

#define ETPU_STAC_ENG2_RSC2_MASK                 (0x4000U)
#define ETPU_STAC_ENG2_RSC2_SHIFT                (14U)
#define ETPU_STAC_ENG2_RSC2_WIDTH                (1U)
#define ETPU_STAC_ENG2_RSC2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_RSC2_SHIFT)) & ETPU_STAC_ENG2_RSC2_MASK)

#define ETPU_STAC_ENG2_REN2_MASK                 (0x8000U)
#define ETPU_STAC_ENG2_REN2_SHIFT                (15U)
#define ETPU_STAC_ENG2_REN2_WIDTH                (1U)
#define ETPU_STAC_ENG2_REN2(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_REN2_SHIFT)) & ETPU_STAC_ENG2_REN2_MASK)

#define ETPU_STAC_ENG2_SRV1_MASK                 (0xF0000U)
#define ETPU_STAC_ENG2_SRV1_SHIFT                (16U)
#define ETPU_STAC_ENG2_SRV1_WIDTH                (4U)
#define ETPU_STAC_ENG2_SRV1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_SRV1_SHIFT)) & ETPU_STAC_ENG2_SRV1_MASK)

#define ETPU_STAC_ENG2_SERVER_ID1_MASK           (0xF000000U)
#define ETPU_STAC_ENG2_SERVER_ID1_SHIFT          (24U)
#define ETPU_STAC_ENG2_SERVER_ID1_WIDTH          (4U)
#define ETPU_STAC_ENG2_SERVER_ID1(x)             (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_SERVER_ID1_SHIFT)) & ETPU_STAC_ENG2_SERVER_ID1_MASK)

#define ETPU_STAC_ENG2_RSC1_MASK                 (0x40000000U)
#define ETPU_STAC_ENG2_RSC1_SHIFT                (30U)
#define ETPU_STAC_ENG2_RSC1_WIDTH                (1U)
#define ETPU_STAC_ENG2_RSC1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_RSC1_SHIFT)) & ETPU_STAC_ENG2_RSC1_MASK)

#define ETPU_STAC_ENG2_REN1_MASK                 (0x80000000U)
#define ETPU_STAC_ENG2_REN1_SHIFT                (31U)
#define ETPU_STAC_ENG2_REN1_WIDTH                (1U)
#define ETPU_STAC_ENG2_REN1(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_STAC_ENG2_REN1_SHIFT)) & ETPU_STAC_ENG2_REN1_MASK)
/*! @} */

/*! @name WDTR_ENG1 - eTPU Watchdog Timer Register for Engine 1 */
/*! @{ */

#define ETPU_WDTR_ENG1_WDCNT_MASK                (0xFFFFU)
#define ETPU_WDTR_ENG1_WDCNT_SHIFT               (0U)
#define ETPU_WDTR_ENG1_WDCNT_WIDTH               (16U)
#define ETPU_WDTR_ENG1_WDCNT(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG1_WDCNT_SHIFT)) & ETPU_WDTR_ENG1_WDCNT_MASK)

#define ETPU_WDTR_ENG1_WMO_MASK                  (0x10000000U)
#define ETPU_WDTR_ENG1_WMO_SHIFT                 (28U)
#define ETPU_WDTR_ENG1_WMO_WIDTH                 (1U)
#define ETPU_WDTR_ENG1_WMO(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG1_WMO_SHIFT)) & ETPU_WDTR_ENG1_WMO_MASK)

#define ETPU_WDTR_ENG1_WDM_MASK                  (0xC0000000U)
#define ETPU_WDTR_ENG1_WDM_SHIFT                 (30U)
#define ETPU_WDTR_ENG1_WDM_WIDTH                 (2U)
#define ETPU_WDTR_ENG1_WDM(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG1_WDM_SHIFT)) & ETPU_WDTR_ENG1_WDM_MASK)
/*! @} */

/*! @name IDLER_ENG1 - eTPU Idle Register for Engine 1 */
/*! @{ */

#define ETPU_IDLER_ENG1_ICLR_MASK                (0x1U)
#define ETPU_IDLER_ENG1_ICLR_SHIFT               (0U)
#define ETPU_IDLER_ENG1_ICLR_WIDTH               (1U)
#define ETPU_IDLER_ENG1_ICLR(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_IDLER_ENG1_ICLR_SHIFT)) & ETPU_IDLER_ENG1_ICLR_MASK)

#define ETPU_IDLER_ENG1_IDLE_CNT_MASK            (0xFFFFFFFEU)
#define ETPU_IDLER_ENG1_IDLE_CNT_SHIFT           (1U)
#define ETPU_IDLER_ENG1_IDLE_CNT_WIDTH           (31U)
#define ETPU_IDLER_ENG1_IDLE_CNT(x)              (((uint32_t)(((uint32_t)(x)) << ETPU_IDLER_ENG1_IDLE_CNT_SHIFT)) & ETPU_IDLER_ENG1_IDLE_CNT_MASK)
/*! @} */

/*! @name WDTR_ENG2 - eTPU Watchdog Timer Register for Engine 2 */
/*! @{ */

#define ETPU_WDTR_ENG2_WDCNT_MASK                (0xFFFFU)
#define ETPU_WDTR_ENG2_WDCNT_SHIFT               (0U)
#define ETPU_WDTR_ENG2_WDCNT_WIDTH               (16U)
#define ETPU_WDTR_ENG2_WDCNT(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG2_WDCNT_SHIFT)) & ETPU_WDTR_ENG2_WDCNT_MASK)

#define ETPU_WDTR_ENG2_WMO_MASK                  (0x10000000U)
#define ETPU_WDTR_ENG2_WMO_SHIFT                 (28U)
#define ETPU_WDTR_ENG2_WMO_WIDTH                 (1U)
#define ETPU_WDTR_ENG2_WMO(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG2_WMO_SHIFT)) & ETPU_WDTR_ENG2_WMO_MASK)

#define ETPU_WDTR_ENG2_WDM_MASK                  (0xC0000000U)
#define ETPU_WDTR_ENG2_WDM_SHIFT                 (30U)
#define ETPU_WDTR_ENG2_WDM_WIDTH                 (2U)
#define ETPU_WDTR_ENG2_WDM(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_WDTR_ENG2_WDM_SHIFT)) & ETPU_WDTR_ENG2_WDM_MASK)
/*! @} */

/*! @name IDLER_ENG2 - eTPU Idle Register for Engine 2 */
/*! @{ */

#define ETPU_IDLER_ENG2_ICLR_MASK                (0x1U)
#define ETPU_IDLER_ENG2_ICLR_SHIFT               (0U)
#define ETPU_IDLER_ENG2_ICLR_WIDTH               (1U)
#define ETPU_IDLER_ENG2_ICLR(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_IDLER_ENG2_ICLR_SHIFT)) & ETPU_IDLER_ENG2_ICLR_MASK)

#define ETPU_IDLER_ENG2_IDLE_CNT_MASK            (0xFFFFFFFEU)
#define ETPU_IDLER_ENG2_IDLE_CNT_SHIFT           (1U)
#define ETPU_IDLER_ENG2_IDLE_CNT_WIDTH           (31U)
#define ETPU_IDLER_ENG2_IDLE_CNT(x)              (((uint32_t)(((uint32_t)(x)) << ETPU_IDLER_ENG2_IDLE_CNT_SHIFT)) & ETPU_IDLER_ENG2_IDLE_CNT_MASK)
/*! @} */

/*! @name MECR - eTPU Memory Error Control Register */
/*! @{ */

#define ETPU_MECR_CEDD_MASK                      (0x1U)
#define ETPU_MECR_CEDD_SHIFT                     (0U)
#define ETPU_MECR_CEDD_WIDTH                     (1U)
#define ETPU_MECR_CEDD(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_CEDD_SHIFT)) & ETPU_MECR_CEDD_MASK)

#define ETPU_MECR_CRDIS_MASK                     (0x2U)
#define ETPU_MECR_CRDIS_SHIFT                    (1U)
#define ETPU_MECR_CRDIS_WIDTH                    (1U)
#define ETPU_MECR_CRDIS(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_CRDIS_SHIFT)) & ETPU_MECR_CRDIS_MASK)

#define ETPU_MECR_CTEND_MASK                     (0x4U)
#define ETPU_MECR_CTEND_SHIFT                    (2U)
#define ETPU_MECR_CTEND_WIDTH                    (1U)
#define ETPU_MECR_CTEND(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_CTEND_SHIFT)) & ETPU_MECR_CTEND_MASK)

#define ETPU_MECR_CEIE_MASK                      (0x80U)
#define ETPU_MECR_CEIE_SHIFT                     (7U)
#define ETPU_MECR_CEIE_WIDTH                     (1U)
#define ETPU_MECR_CEIE(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_CEIE_SHIFT)) & ETPU_MECR_CEIE_MASK)

#define ETPU_MECR_DEDD_MASK                      (0x100U)
#define ETPU_MECR_DEDD_SHIFT                     (8U)
#define ETPU_MECR_DEDD_WIDTH                     (1U)
#define ETPU_MECR_DEDD(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_DEDD_SHIFT)) & ETPU_MECR_DEDD_MASK)

#define ETPU_MECR_DRDIS_MASK                     (0x200U)
#define ETPU_MECR_DRDIS_SHIFT                    (9U)
#define ETPU_MECR_DRDIS_WIDTH                    (1U)
#define ETPU_MECR_DRDIS(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_DRDIS_SHIFT)) & ETPU_MECR_DRDIS_MASK)

#define ETPU_MECR_DTEND_MASK                     (0x400U)
#define ETPU_MECR_DTEND_SHIFT                    (10U)
#define ETPU_MECR_DTEND_WIDTH                    (1U)
#define ETPU_MECR_DTEND(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_DTEND_SHIFT)) & ETPU_MECR_DTEND_MASK)

#define ETPU_MECR_MDEIE_MASK                     (0x4000U)
#define ETPU_MECR_MDEIE_SHIFT                    (14U)
#define ETPU_MECR_MDEIE_WIDTH                    (1U)
#define ETPU_MECR_MDEIE(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_MDEIE_SHIFT)) & ETPU_MECR_MDEIE_MASK)

#define ETPU_MECR_HDEIE_MASK                     (0x8000U)
#define ETPU_MECR_HDEIE_SHIFT                    (15U)
#define ETPU_MECR_HDEIE_WIDTH                    (1U)
#define ETPU_MECR_HDEIE(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_HDEIE_SHIFT)) & ETPU_MECR_HDEIE_MASK)

#define ETPU_MECR_MECIE_MASK                     (0x10000U)
#define ETPU_MECR_MECIE_SHIFT                    (16U)
#define ETPU_MECR_MECIE_WIDTH                    (1U)
#define ETPU_MECR_MECIE(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_MECIE_SHIFT)) & ETPU_MECR_MECIE_MASK)

#define ETPU_MECR_FME_MASK                       (0x80000000U)
#define ETPU_MECR_FME_SHIFT                      (31U)
#define ETPU_MECR_FME_WIDTH                      (1U)
#define ETPU_MECR_FME(x)                         (((uint32_t)(((uint32_t)(x)) << ETPU_MECR_FME_SHIFT)) & ETPU_MECR_FME_MASK)
/*! @} */

/*! @name DEIAR - eTPU Data Error Injection Address Register */
/*! @{ */

#define ETPU_DEIAR_INJ_ADDR_MASK                 (0x3FFCU)
#define ETPU_DEIAR_INJ_ADDR_SHIFT                (2U)
#define ETPU_DEIAR_INJ_ADDR_WIDTH                (12U)
#define ETPU_DEIAR_INJ_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_DEIAR_INJ_ADDR_SHIFT)) & ETPU_DEIAR_INJ_ADDR_MASK)
/*! @} */

/*! @name DEIDPR - eTPU Data Error Injection Data Pattern Register */
/*! @{ */

#define ETPU_DEIDPR_DFLIP_MASK                   (0xFFFFFFFFU)
#define ETPU_DEIDPR_DFLIP_SHIFT                  (0U)
#define ETPU_DEIDPR_DFLIP_WIDTH                  (32U)
#define ETPU_DEIDPR_DFLIP(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_DEIDPR_DFLIP_SHIFT)) & ETPU_DEIDPR_DFLIP_MASK)
/*! @} */

/*! @name DEIPPR - eTPU Data Error Injection Parity Pattern Register */
/*! @{ */

#define ETPU_DEIPPR_PFLIP_4_0_MASK               (0x1FU)
#define ETPU_DEIPPR_PFLIP_4_0_SHIFT              (0U)
#define ETPU_DEIPPR_PFLIP_4_0_WIDTH              (5U)
#define ETPU_DEIPPR_PFLIP_4_0(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_DEIPPR_PFLIP_4_0_SHIFT)) & ETPU_DEIPPR_PFLIP_4_0_MASK)

#define ETPU_DEIPPR_PFLIP_9_5_MASK               (0x1F00U)
#define ETPU_DEIPPR_PFLIP_9_5_SHIFT              (8U)
#define ETPU_DEIPPR_PFLIP_9_5_WIDTH              (5U)
#define ETPU_DEIPPR_PFLIP_9_5(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_DEIPPR_PFLIP_9_5_SHIFT)) & ETPU_DEIPPR_PFLIP_9_5_MASK)

#define ETPU_DEIPPR_PFLIP_14_10_MASK             (0x1F0000U)
#define ETPU_DEIPPR_PFLIP_14_10_SHIFT            (16U)
#define ETPU_DEIPPR_PFLIP_14_10_WIDTH            (5U)
#define ETPU_DEIPPR_PFLIP_14_10(x)               (((uint32_t)(((uint32_t)(x)) << ETPU_DEIPPR_PFLIP_14_10_SHIFT)) & ETPU_DEIPPR_PFLIP_14_10_MASK)

#define ETPU_DEIPPR_PFLIP_19_15_MASK             (0x1F000000U)
#define ETPU_DEIPPR_PFLIP_19_15_SHIFT            (24U)
#define ETPU_DEIPPR_PFLIP_19_15_WIDTH            (5U)
#define ETPU_DEIPPR_PFLIP_19_15(x)               (((uint32_t)(((uint32_t)(x)) << ETPU_DEIPPR_PFLIP_19_15_SHIFT)) & ETPU_DEIPPR_PFLIP_19_15_MASK)
/*! @} */

/*! @name DERAR - eTPU Data Error Report Address Register */
/*! @{ */

#define ETPU_DERAR_ERR_ADDR_MASK                 (0x3FFCU)
#define ETPU_DERAR_ERR_ADDR_SHIFT                (2U)
#define ETPU_DERAR_ERR_ADDR_WIDTH                (12U)
#define ETPU_DERAR_ERR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_DERAR_ERR_ADDR_SHIFT)) & ETPU_DERAR_ERR_ADDR_MASK)

#define ETPU_DERAR_ERR_CHANNEL_MASK              (0x1F000000U)
#define ETPU_DERAR_ERR_CHANNEL_SHIFT             (24U)
#define ETPU_DERAR_ERR_CHANNEL_WIDTH             (5U)
#define ETPU_DERAR_ERR_CHANNEL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_DERAR_ERR_CHANNEL_SHIFT)) & ETPU_DERAR_ERR_CHANNEL_MASK)

#define ETPU_DERAR_ERR_ACC_MASK                  (0xC0000000U)
#define ETPU_DERAR_ERR_ACC_SHIFT                 (30U)
#define ETPU_DERAR_ERR_ACC_WIDTH                 (2U)
#define ETPU_DERAR_ERR_ACC(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_DERAR_ERR_ACC_SHIFT)) & ETPU_DERAR_ERR_ACC_MASK)
/*! @} */

/*! @name DERDR - eTPU Data Error Report Data Register */
/*! @{ */

#define ETPU_DERDR_DATA_MASK                     (0xFFFFFFFFU)
#define ETPU_DERDR_DATA_SHIFT                    (0U)
#define ETPU_DERDR_DATA_WIDTH                    (32U)
#define ETPU_DERDR_DATA(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_DERDR_DATA_SHIFT)) & ETPU_DERDR_DATA_MASK)
/*! @} */

/*! @name DERSR - eTPU Data Error Report Syndrome Register */
/*! @{ */

#define ETPU_DERSR_SYND0_MASK                    (0x1FU)
#define ETPU_DERSR_SYND0_SHIFT                   (0U)
#define ETPU_DERSR_SYND0_WIDTH                   (5U)
#define ETPU_DERSR_SYND0(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_SYND0_SHIFT)) & ETPU_DERSR_SYND0_MASK)

#define ETPU_DERSR_BE0_MASK                      (0x80U)
#define ETPU_DERSR_BE0_SHIFT                     (7U)
#define ETPU_DERSR_BE0_WIDTH                     (1U)
#define ETPU_DERSR_BE0(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_BE0_SHIFT)) & ETPU_DERSR_BE0_MASK)

#define ETPU_DERSR_SYND1_MASK                    (0x1F00U)
#define ETPU_DERSR_SYND1_SHIFT                   (8U)
#define ETPU_DERSR_SYND1_WIDTH                   (5U)
#define ETPU_DERSR_SYND1(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_SYND1_SHIFT)) & ETPU_DERSR_SYND1_MASK)

#define ETPU_DERSR_BE1_MASK                      (0x8000U)
#define ETPU_DERSR_BE1_SHIFT                     (15U)
#define ETPU_DERSR_BE1_WIDTH                     (1U)
#define ETPU_DERSR_BE1(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_BE1_SHIFT)) & ETPU_DERSR_BE1_MASK)

#define ETPU_DERSR_SYND2_MASK                    (0x1F0000U)
#define ETPU_DERSR_SYND2_SHIFT                   (16U)
#define ETPU_DERSR_SYND2_WIDTH                   (5U)
#define ETPU_DERSR_SYND2(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_SYND2_SHIFT)) & ETPU_DERSR_SYND2_MASK)

#define ETPU_DERSR_BE2_MASK                      (0x800000U)
#define ETPU_DERSR_BE2_SHIFT                     (23U)
#define ETPU_DERSR_BE2_WIDTH                     (1U)
#define ETPU_DERSR_BE2(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_BE2_SHIFT)) & ETPU_DERSR_BE2_MASK)

#define ETPU_DERSR_SYND3_MASK                    (0x1F000000U)
#define ETPU_DERSR_SYND3_SHIFT                   (24U)
#define ETPU_DERSR_SYND3_WIDTH                   (5U)
#define ETPU_DERSR_SYND3(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_SYND3_SHIFT)) & ETPU_DERSR_SYND3_MASK)

#define ETPU_DERSR_BE3_MASK                      (0x80000000U)
#define ETPU_DERSR_BE3_SHIFT                     (31U)
#define ETPU_DERSR_BE3_WIDTH                     (1U)
#define ETPU_DERSR_BE3(x)                        (((uint32_t)(((uint32_t)(x)) << ETPU_DERSR_BE3_SHIFT)) & ETPU_DERSR_BE3_MASK)
/*! @} */

/*! @name MESR - eTPU Memory Error Status Register */
/*! @{ */

#define ETPU_MESR_CNCOVR_MASK                    (0x1U)
#define ETPU_MESR_CNCOVR_SHIFT                   (0U)
#define ETPU_MESR_CNCOVR_WIDTH                   (1U)
#define ETPU_MESR_CNCOVR(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_CNCOVR_SHIFT)) & ETPU_MESR_CNCOVR_MASK)

#define ETPU_MESR_CNCERR_MASK                    (0x80U)
#define ETPU_MESR_CNCERR_SHIFT                   (7U)
#define ETPU_MESR_CNCERR_WIDTH                   (1U)
#define ETPU_MESR_CNCERR(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_CNCERR_SHIFT)) & ETPU_MESR_CNCERR_MASK)

#define ETPU_MESR_DNCOVR_MASK                    (0x100U)
#define ETPU_MESR_DNCOVR_SHIFT                   (8U)
#define ETPU_MESR_DNCOVR_WIDTH                   (1U)
#define ETPU_MESR_DNCOVR(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_DNCOVR_SHIFT)) & ETPU_MESR_DNCOVR_MASK)

#define ETPU_MESR_DNCERR_MASK                    (0x8000U)
#define ETPU_MESR_DNCERR_SHIFT                   (15U)
#define ETPU_MESR_DNCERR_WIDTH                   (1U)
#define ETPU_MESR_DNCERR(x)                      (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_DNCERR_SHIFT)) & ETPU_MESR_DNCERR_MASK)

#define ETPU_MESR_CCOVR_MASK                     (0x10000U)
#define ETPU_MESR_CCOVR_SHIFT                    (16U)
#define ETPU_MESR_CCOVR_WIDTH                    (1U)
#define ETPU_MESR_CCOVR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_CCOVR_SHIFT)) & ETPU_MESR_CCOVR_MASK)

#define ETPU_MESR_CCERR_MASK                     (0x800000U)
#define ETPU_MESR_CCERR_SHIFT                    (23U)
#define ETPU_MESR_CCERR_WIDTH                    (1U)
#define ETPU_MESR_CCERR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_CCERR_SHIFT)) & ETPU_MESR_CCERR_MASK)

#define ETPU_MESR_DCOVR_MASK                     (0x1000000U)
#define ETPU_MESR_DCOVR_SHIFT                    (24U)
#define ETPU_MESR_DCOVR_WIDTH                    (1U)
#define ETPU_MESR_DCOVR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_DCOVR_SHIFT)) & ETPU_MESR_DCOVR_MASK)

#define ETPU_MESR_DCERR_MASK                     (0x80000000U)
#define ETPU_MESR_DCERR_SHIFT                    (31U)
#define ETPU_MESR_DCERR_WIDTH                    (1U)
#define ETPU_MESR_DCERR(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_MESR_DCERR_SHIFT)) & ETPU_MESR_DCERR_MASK)
/*! @} */

/*! @name CEIAR - eTPU Code Error Injection Address Register */
/*! @{ */

#define ETPU_CEIAR_INJ_ADDR_MASK                 (0xFFFCU)
#define ETPU_CEIAR_INJ_ADDR_SHIFT                (2U)
#define ETPU_CEIAR_INJ_ADDR_WIDTH                (14U)
#define ETPU_CEIAR_INJ_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CEIAR_INJ_ADDR_SHIFT)) & ETPU_CEIAR_INJ_ADDR_MASK)
/*! @} */

/*! @name CEIDPR - eTPU Code Error Injection Data Pattern Register */
/*! @{ */

#define ETPU_CEIDPR_DFLIP_MASK                   (0xFFFFFFFFU)
#define ETPU_CEIDPR_DFLIP_SHIFT                  (0U)
#define ETPU_CEIDPR_DFLIP_WIDTH                  (32U)
#define ETPU_CEIDPR_DFLIP(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CEIDPR_DFLIP_SHIFT)) & ETPU_CEIDPR_DFLIP_MASK)
/*! @} */

/*! @name CEIPPR - eTPU Code Error Injection Parity Pattern Register */
/*! @{ */

#define ETPU_CEIPPR_PFLIP_MASK                   (0x7FU)
#define ETPU_CEIPPR_PFLIP_SHIFT                  (0U)
#define ETPU_CEIPPR_PFLIP_WIDTH                  (7U)
#define ETPU_CEIPPR_PFLIP(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CEIPPR_PFLIP_SHIFT)) & ETPU_CEIPPR_PFLIP_MASK)
/*! @} */

/*! @name CERAR - eTPU Code Error Report Address Register */
/*! @{ */

#define ETPU_CERAR_ERR_ADDR_MASK                 (0xFFFCU)
#define ETPU_CERAR_ERR_ADDR_SHIFT                (2U)
#define ETPU_CERAR_ERR_ADDR_WIDTH                (14U)
#define ETPU_CERAR_ERR_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CERAR_ERR_ADDR_SHIFT)) & ETPU_CERAR_ERR_ADDR_MASK)

#define ETPU_CERAR_ERR_CHANNEL_MASK              (0x1F000000U)
#define ETPU_CERAR_ERR_CHANNEL_SHIFT             (24U)
#define ETPU_CERAR_ERR_CHANNEL_WIDTH             (5U)
#define ETPU_CERAR_ERR_CHANNEL(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_CERAR_ERR_CHANNEL_SHIFT)) & ETPU_CERAR_ERR_CHANNEL_MASK)

#define ETPU_CERAR_ERR_ACC_MASK                  (0xC0000000U)
#define ETPU_CERAR_ERR_ACC_SHIFT                 (30U)
#define ETPU_CERAR_ERR_ACC_WIDTH                 (2U)
#define ETPU_CERAR_ERR_ACC(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CERAR_ERR_ACC_SHIFT)) & ETPU_CERAR_ERR_ACC_MASK)
/*! @} */

/*! @name CERDR - eTPU Code Error Report Data Register */
/*! @{ */

#define ETPU_CERDR_CODE_MASK                     (0xFFFFFFFFU)
#define ETPU_CERDR_CODE_SHIFT                    (0U)
#define ETPU_CERDR_CODE_WIDTH                    (32U)
#define ETPU_CERDR_CODE(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_CERDR_CODE_SHIFT)) & ETPU_CERDR_CODE_MASK)
/*! @} */

/*! @name CERSR - eTPU Code Error Report Syndrome Register */
/*! @{ */

#define ETPU_CERSR_SYND_MASK                     (0x7FU)
#define ETPU_CERSR_SYND_SHIFT                    (0U)
#define ETPU_CERSR_SYND_WIDTH                    (7U)
#define ETPU_CERSR_SYND(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_CERSR_SYND_SHIFT)) & ETPU_CERSR_SYND_MASK)
/*! @} */

/*! @name CEFR - eTPU Code Error Fix Register */
/*! @{ */

#define ETPU_CEFR_CFIX_ADDR_MASK                 (0xFFFCU)
#define ETPU_CEFR_CFIX_ADDR_SHIFT                (2U)
#define ETPU_CEFR_CFIX_ADDR_WIDTH                (14U)
#define ETPU_CEFR_CFIX_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CEFR_CFIX_ADDR_SHIFT)) & ETPU_CEFR_CFIX_ADDR_MASK)

#define ETPU_CEFR_CFIXM_MASK                     (0xC0000000U)
#define ETPU_CEFR_CFIXM_SHIFT                    (30U)
#define ETPU_CEFR_CFIXM_WIDTH                    (2U)
#define ETPU_CEFR_CFIXM(x)                       (((uint32_t)(((uint32_t)(x)) << ETPU_CEFR_CFIXM_SHIFT)) & ETPU_CEFR_CFIXM_MASK)
/*! @} */

/*! @name CISR_ENG1 - eTPU Channel Interrupt Status Register for Engine 1 */
/*! @{ */

#define ETPU_CISR_ENG1_CISn_MASK                 (0xFFFFFFFFU)
#define ETPU_CISR_ENG1_CISn_SHIFT                (0U)
#define ETPU_CISR_ENG1_CISn_WIDTH                (32U)
#define ETPU_CISR_ENG1_CISn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CISR_ENG1_CISn_SHIFT)) & ETPU_CISR_ENG1_CISn_MASK)
/*! @} */

/*! @name CISR_ENG2 - eTPU Channel Interrupt Status Register for Engine 2 */
/*! @{ */

#define ETPU_CISR_ENG2_CISn_MASK                 (0xFFFFFFFFU)
#define ETPU_CISR_ENG2_CISn_SHIFT                (0U)
#define ETPU_CISR_ENG2_CISn_WIDTH                (32U)
#define ETPU_CISR_ENG2_CISn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CISR_ENG2_CISn_SHIFT)) & ETPU_CISR_ENG2_CISn_MASK)
/*! @} */

/*! @name CDTRSR_ENG1 - eTPU Channel Data Transfer Request Status Register for Engine 1 */
/*! @{ */

#define ETPU_CDTRSR_ENG1_DTRSn_MASK              (0xFFFFFFFFU)
#define ETPU_CDTRSR_ENG1_DTRSn_SHIFT             (0U)
#define ETPU_CDTRSR_ENG1_DTRSn_WIDTH             (32U)
#define ETPU_CDTRSR_ENG1_DTRSn(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_CDTRSR_ENG1_DTRSn_SHIFT)) & ETPU_CDTRSR_ENG1_DTRSn_MASK)
/*! @} */

/*! @name CDTRSR_ENG2 - eTPU Channel Data Transfer Request Status Register for Engine 2 */
/*! @{ */

#define ETPU_CDTRSR_ENG2_DTRSn_MASK              (0xFFFFFFFFU)
#define ETPU_CDTRSR_ENG2_DTRSn_SHIFT             (0U)
#define ETPU_CDTRSR_ENG2_DTRSn_WIDTH             (32U)
#define ETPU_CDTRSR_ENG2_DTRSn(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_CDTRSR_ENG2_DTRSn_SHIFT)) & ETPU_CDTRSR_ENG2_DTRSn_MASK)
/*! @} */

/*! @name CIOSR_ENG1 - eTPU Channel Interrupt Overflow Status Register for Engine 1 */
/*! @{ */

#define ETPU_CIOSR_ENG1_CIOSn_MASK               (0xFFFFFFFFU)
#define ETPU_CIOSR_ENG1_CIOSn_SHIFT              (0U)
#define ETPU_CIOSR_ENG1_CIOSn_WIDTH              (32U)
#define ETPU_CIOSR_ENG1_CIOSn(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_CIOSR_ENG1_CIOSn_SHIFT)) & ETPU_CIOSR_ENG1_CIOSn_MASK)
/*! @} */

/*! @name CIOSR_ENG2 - eTPU Channel Interrupt Overflow Status Register for Engine 2 */
/*! @{ */

#define ETPU_CIOSR_ENG2_CIOSn_MASK               (0xFFFFFFFFU)
#define ETPU_CIOSR_ENG2_CIOSn_SHIFT              (0U)
#define ETPU_CIOSR_ENG2_CIOSn_WIDTH              (32U)
#define ETPU_CIOSR_ENG2_CIOSn(x)                 (((uint32_t)(((uint32_t)(x)) << ETPU_CIOSR_ENG2_CIOSn_SHIFT)) & ETPU_CIOSR_ENG2_CIOSn_MASK)
/*! @} */

/*! @name CDTROSR_ENG1 - eTPU Channel Data Transfer Request Overflow Status Register for Engine 1 */
/*! @{ */

#define ETPU_CDTROSR_ENG1_DTROSn_MASK            (0xFFFFFFFFU)
#define ETPU_CDTROSR_ENG1_DTROSn_SHIFT           (0U)
#define ETPU_CDTROSR_ENG1_DTROSn_WIDTH           (32U)
#define ETPU_CDTROSR_ENG1_DTROSn(x)              (((uint32_t)(((uint32_t)(x)) << ETPU_CDTROSR_ENG1_DTROSn_SHIFT)) & ETPU_CDTROSR_ENG1_DTROSn_MASK)
/*! @} */

/*! @name CDTROSR_ENG2 - eTPU Channel Data Transfer Request Overflow Status Register for Engine 2 */
/*! @{ */

#define ETPU_CDTROSR_ENG2_DTROSn_MASK            (0xFFFFFFFFU)
#define ETPU_CDTROSR_ENG2_DTROSn_SHIFT           (0U)
#define ETPU_CDTROSR_ENG2_DTROSn_WIDTH           (32U)
#define ETPU_CDTROSR_ENG2_DTROSn(x)              (((uint32_t)(((uint32_t)(x)) << ETPU_CDTROSR_ENG2_DTROSn_SHIFT)) & ETPU_CDTROSR_ENG2_DTROSn_MASK)
/*! @} */

/*! @name CIER_ENG1 - eTPU Channel Interrupt Enable Register for Engine 1 */
/*! @{ */

#define ETPU_CIER_ENG1_CIEn_MASK                 (0xFFFFFFFFU)
#define ETPU_CIER_ENG1_CIEn_SHIFT                (0U)
#define ETPU_CIER_ENG1_CIEn_WIDTH                (32U)
#define ETPU_CIER_ENG1_CIEn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CIER_ENG1_CIEn_SHIFT)) & ETPU_CIER_ENG1_CIEn_MASK)
/*! @} */

/*! @name CIER_ENG2 - eTPU Channel Interrupt Enable Register for Engine 2 */
/*! @{ */

#define ETPU_CIER_ENG2_CIEn_MASK                 (0xFFFFFFFFU)
#define ETPU_CIER_ENG2_CIEn_SHIFT                (0U)
#define ETPU_CIER_ENG2_CIEn_WIDTH                (32U)
#define ETPU_CIER_ENG2_CIEn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CIER_ENG2_CIEn_SHIFT)) & ETPU_CIER_ENG2_CIEn_MASK)
/*! @} */

/*! @name CDTRER_ENG1 - eTPU Channel Data Transfer Request Enable Register for Engine 1 */
/*! @{ */

#define ETPU_CDTRER_ENG1_DTREn_MASK              (0xFFFFFFFFU)
#define ETPU_CDTRER_ENG1_DTREn_SHIFT             (0U)
#define ETPU_CDTRER_ENG1_DTREn_WIDTH             (32U)
#define ETPU_CDTRER_ENG1_DTREn(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_CDTRER_ENG1_DTREn_SHIFT)) & ETPU_CDTRER_ENG1_DTREn_MASK)
/*! @} */

/*! @name CDTRER_ENG2 - eTPU Channel Data Transfer Request Enable Register for Engine 2 */
/*! @{ */

#define ETPU_CDTRER_ENG2_DTREn_MASK              (0xFFFFFFFFU)
#define ETPU_CDTRER_ENG2_DTREn_SHIFT             (0U)
#define ETPU_CDTRER_ENG2_DTREn_WIDTH             (32U)
#define ETPU_CDTRER_ENG2_DTREn(x)                (((uint32_t)(((uint32_t)(x)) << ETPU_CDTRER_ENG2_DTREn_SHIFT)) & ETPU_CDTRER_ENG2_DTREn_MASK)
/*! @} */

/*! @name WDSR_ENG1 - eTPU Watchdog Status Register for Engine 1 */
/*! @{ */

#define ETPU_WDSR_ENG1_WDSn_MASK                 (0xFFFFFFFFU)
#define ETPU_WDSR_ENG1_WDSn_SHIFT                (0U)
#define ETPU_WDSR_ENG1_WDSn_WIDTH                (32U)
#define ETPU_WDSR_ENG1_WDSn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_WDSR_ENG1_WDSn_SHIFT)) & ETPU_WDSR_ENG1_WDSn_MASK)
/*! @} */

/*! @name WDSR_ENG2 - eTPU Watchdog Status Register for Engine 2 */
/*! @{ */

#define ETPU_WDSR_ENG2_WDSn_MASK                 (0xFFFFFFFFU)
#define ETPU_WDSR_ENG2_WDSn_SHIFT                (0U)
#define ETPU_WDSR_ENG2_WDSn_WIDTH                (32U)
#define ETPU_WDSR_ENG2_WDSn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_WDSR_ENG2_WDSn_SHIFT)) & ETPU_WDSR_ENG2_WDSn_MASK)
/*! @} */

/*! @name CPSSR_ENG1 - eTPU Channel Pending Service Status Register for Engine 1 */
/*! @{ */

#define ETPU_CPSSR_ENG1_SRn_MASK                 (0xFFFFFFFFU)
#define ETPU_CPSSR_ENG1_SRn_SHIFT                (0U)
#define ETPU_CPSSR_ENG1_SRn_WIDTH                (32U)
#define ETPU_CPSSR_ENG1_SRn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CPSSR_ENG1_SRn_SHIFT)) & ETPU_CPSSR_ENG1_SRn_MASK)
/*! @} */

/*! @name CPSSR_ENG2 - eTPU Channel Pending Service Status Register for Engine 2 */
/*! @{ */

#define ETPU_CPSSR_ENG2_SRn_MASK                 (0xFFFFFFFFU)
#define ETPU_CPSSR_ENG2_SRn_SHIFT                (0U)
#define ETPU_CPSSR_ENG2_SRn_WIDTH                (32U)
#define ETPU_CPSSR_ENG2_SRn(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CPSSR_ENG2_SRn_SHIFT)) & ETPU_CPSSR_ENG2_SRn_MASK)
/*! @} */

/*! @name CSSR_ENG1 - eTPU Channel Service Status Register for Engine 1 */
/*! @{ */

#define ETPU_CSSR_ENG1_SSn_MASK                  (0xFFFFFFFFU)
#define ETPU_CSSR_ENG1_SSn_SHIFT                 (0U)
#define ETPU_CSSR_ENG1_SSn_WIDTH                 (32U)
#define ETPU_CSSR_ENG1_SSn(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSSR_ENG1_SSn_SHIFT)) & ETPU_CSSR_ENG1_SSn_MASK)
/*! @} */

/*! @name CSSR_ENG2 - eTPU Channel Service Status Register for Engine 2 */
/*! @{ */

#define ETPU_CSSR_ENG2_SSn_MASK                  (0xFFFFFFFFU)
#define ETPU_CSSR_ENG2_SSn_SHIFT                 (0U)
#define ETPU_CSSR_ENG2_SSn_WIDTH                 (32U)
#define ETPU_CSSR_ENG2_SSn(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSSR_ENG2_SSn_SHIFT)) & ETPU_CSSR_ENG2_SSn_MASK)
/*! @} */

/*! @name CCR_ENG1 - eTPU Channel n Configuration Register for Engine 1 */
/*! @{ */

#define ETPU_CCR_ENG1_CPBA_MASK                  (0x7FFU)
#define ETPU_CCR_ENG1_CPBA_SHIFT                 (0U)
#define ETPU_CCR_ENG1_CPBA_WIDTH                 (11U)
#define ETPU_CCR_ENG1_CPBA(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_CPBA_SHIFT)) & ETPU_CCR_ENG1_CPBA_MASK)

#define ETPU_CCR_ENG1_OPOL_MASK                  (0x4000U)
#define ETPU_CCR_ENG1_OPOL_SHIFT                 (14U)
#define ETPU_CCR_ENG1_OPOL_WIDTH                 (1U)
#define ETPU_CCR_ENG1_OPOL(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_OPOL_SHIFT)) & ETPU_CCR_ENG1_OPOL_MASK)

#define ETPU_CCR_ENG1_ODIS_MASK                  (0x8000U)
#define ETPU_CCR_ENG1_ODIS_SHIFT                 (15U)
#define ETPU_CCR_ENG1_ODIS_WIDTH                 (1U)
#define ETPU_CCR_ENG1_ODIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_ODIS_SHIFT)) & ETPU_CCR_ENG1_ODIS_MASK)

#define ETPU_CCR_ENG1_CFS_MASK                   (0x1F0000U)
#define ETPU_CCR_ENG1_CFS_SHIFT                  (16U)
#define ETPU_CCR_ENG1_CFS_WIDTH                  (5U)
#define ETPU_CCR_ENG1_CFS(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_CFS_SHIFT)) & ETPU_CCR_ENG1_CFS_MASK)

#define ETPU_CCR_ENG1_ETCS_MASK                  (0x1000000U)
#define ETPU_CCR_ENG1_ETCS_SHIFT                 (24U)
#define ETPU_CCR_ENG1_ETCS_WIDTH                 (1U)
#define ETPU_CCR_ENG1_ETCS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_ETCS_SHIFT)) & ETPU_CCR_ENG1_ETCS_MASK)

#define ETPU_CCR_ENG1_ETPD_MASK                  (0x2000000U)
#define ETPU_CCR_ENG1_ETPD_SHIFT                 (25U)
#define ETPU_CCR_ENG1_ETPD_WIDTH                 (1U)
#define ETPU_CCR_ENG1_ETPD(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_ETPD_SHIFT)) & ETPU_CCR_ENG1_ETPD_MASK)

#define ETPU_CCR_ENG1_SSMAE_MASK                 (0x4000000U)
#define ETPU_CCR_ENG1_SSMAE_SHIFT                (26U)
#define ETPU_CCR_ENG1_SSMAE_WIDTH                (1U)
#define ETPU_CCR_ENG1_SSMAE(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_SSMAE_SHIFT)) & ETPU_CCR_ENG1_SSMAE_MASK)

#define ETPU_CCR_ENG1_T4DIS_MASK                 (0x8000000U)
#define ETPU_CCR_ENG1_T4DIS_SHIFT                (27U)
#define ETPU_CCR_ENG1_T4DIS_WIDTH                (1U)
#define ETPU_CCR_ENG1_T4DIS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_T4DIS_SHIFT)) & ETPU_CCR_ENG1_T4DIS_MASK)

#define ETPU_CCR_ENG1_CPR_MASK                   (0x30000000U)
#define ETPU_CCR_ENG1_CPR_SHIFT                  (28U)
#define ETPU_CCR_ENG1_CPR_WIDTH                  (2U)
#define ETPU_CCR_ENG1_CPR(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_CPR_SHIFT)) & ETPU_CCR_ENG1_CPR_MASK)

#define ETPU_CCR_ENG1_DTRE_MASK                  (0x40000000U)
#define ETPU_CCR_ENG1_DTRE_SHIFT                 (30U)
#define ETPU_CCR_ENG1_DTRE_WIDTH                 (1U)
#define ETPU_CCR_ENG1_DTRE(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_DTRE_SHIFT)) & ETPU_CCR_ENG1_DTRE_MASK)

#define ETPU_CCR_ENG1_CIE_MASK                   (0x80000000U)
#define ETPU_CCR_ENG1_CIE_SHIFT                  (31U)
#define ETPU_CCR_ENG1_CIE_WIDTH                  (1U)
#define ETPU_CCR_ENG1_CIE(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG1_CIE_SHIFT)) & ETPU_CCR_ENG1_CIE_MASK)
/*! @} */

/*! @name CSCR_ENG1 - eTPU Channel n Status Control Register for Engine 1 */
/*! @{ */

#define ETPU_CSCR_ENG1_FM_MASK                   (0x3U)
#define ETPU_CSCR_ENG1_FM_SHIFT                  (0U)
#define ETPU_CSCR_ENG1_FM_WIDTH                  (2U)
#define ETPU_CSCR_ENG1_FM(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_FM_SHIFT)) & ETPU_CSCR_ENG1_FM_MASK)

#define ETPU_CSCR_ENG1_OBE_MASK                  (0x2000U)
#define ETPU_CSCR_ENG1_OBE_SHIFT                 (13U)
#define ETPU_CSCR_ENG1_OBE_WIDTH                 (1U)
#define ETPU_CSCR_ENG1_OBE(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_OBE_SHIFT)) & ETPU_CSCR_ENG1_OBE_MASK)

#define ETPU_CSCR_ENG1_OPS_MASK                  (0x4000U)
#define ETPU_CSCR_ENG1_OPS_SHIFT                 (14U)
#define ETPU_CSCR_ENG1_OPS_WIDTH                 (1U)
#define ETPU_CSCR_ENG1_OPS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_OPS_SHIFT)) & ETPU_CSCR_ENG1_OPS_MASK)

#define ETPU_CSCR_ENG1_IPS_MASK                  (0x8000U)
#define ETPU_CSCR_ENG1_IPS_SHIFT                 (15U)
#define ETPU_CSCR_ENG1_IPS_WIDTH                 (1U)
#define ETPU_CSCR_ENG1_IPS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_IPS_SHIFT)) & ETPU_CSCR_ENG1_IPS_MASK)

#define ETPU_CSCR_ENG1_DTROS_MASK                (0x400000U)
#define ETPU_CSCR_ENG1_DTROS_SHIFT               (22U)
#define ETPU_CSCR_ENG1_DTROS_WIDTH               (1U)
#define ETPU_CSCR_ENG1_DTROS(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_DTROS_SHIFT)) & ETPU_CSCR_ENG1_DTROS_MASK)

#define ETPU_CSCR_ENG1_DTRS_MASK                 (0x800000U)
#define ETPU_CSCR_ENG1_DTRS_SHIFT                (23U)
#define ETPU_CSCR_ENG1_DTRS_WIDTH                (1U)
#define ETPU_CSCR_ENG1_DTRS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_DTRS_SHIFT)) & ETPU_CSCR_ENG1_DTRS_MASK)

#define ETPU_CSCR_ENG1_CIOS_MASK                 (0x40000000U)
#define ETPU_CSCR_ENG1_CIOS_SHIFT                (30U)
#define ETPU_CSCR_ENG1_CIOS_WIDTH                (1U)
#define ETPU_CSCR_ENG1_CIOS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_CIOS_SHIFT)) & ETPU_CSCR_ENG1_CIOS_MASK)

#define ETPU_CSCR_ENG1_CIS_MASK                  (0x80000000U)
#define ETPU_CSCR_ENG1_CIS_SHIFT                 (31U)
#define ETPU_CSCR_ENG1_CIS_WIDTH                 (1U)
#define ETPU_CSCR_ENG1_CIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG1_CIS_SHIFT)) & ETPU_CSCR_ENG1_CIS_MASK)
/*! @} */

/*! @name CHSRR_ENG1 - eTPU Channel n Host Service Request Register for Engine 1 */
/*! @{ */

#define ETPU_CHSRR_ENG1_HSR_MASK                 (0x7U)
#define ETPU_CHSRR_ENG1_HSR_SHIFT                (0U)
#define ETPU_CHSRR_ENG1_HSR_WIDTH                (3U)
#define ETPU_CHSRR_ENG1_HSR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CHSRR_ENG1_HSR_SHIFT)) & ETPU_CHSRR_ENG1_HSR_MASK)
/*! @} */

/*! @name CCR_ENG2 - eTPU Channel n Configuration Register for Engine 2 */
/*! @{ */

#define ETPU_CCR_ENG2_CPBA_MASK                  (0x7FFU)
#define ETPU_CCR_ENG2_CPBA_SHIFT                 (0U)
#define ETPU_CCR_ENG2_CPBA_WIDTH                 (11U)
#define ETPU_CCR_ENG2_CPBA(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_CPBA_SHIFT)) & ETPU_CCR_ENG2_CPBA_MASK)

#define ETPU_CCR_ENG2_OPOL_MASK                  (0x4000U)
#define ETPU_CCR_ENG2_OPOL_SHIFT                 (14U)
#define ETPU_CCR_ENG2_OPOL_WIDTH                 (1U)
#define ETPU_CCR_ENG2_OPOL(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_OPOL_SHIFT)) & ETPU_CCR_ENG2_OPOL_MASK)

#define ETPU_CCR_ENG2_ODIS_MASK                  (0x8000U)
#define ETPU_CCR_ENG2_ODIS_SHIFT                 (15U)
#define ETPU_CCR_ENG2_ODIS_WIDTH                 (1U)
#define ETPU_CCR_ENG2_ODIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_ODIS_SHIFT)) & ETPU_CCR_ENG2_ODIS_MASK)

#define ETPU_CCR_ENG2_CFS_MASK                   (0x1F0000U)
#define ETPU_CCR_ENG2_CFS_SHIFT                  (16U)
#define ETPU_CCR_ENG2_CFS_WIDTH                  (5U)
#define ETPU_CCR_ENG2_CFS(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_CFS_SHIFT)) & ETPU_CCR_ENG2_CFS_MASK)

#define ETPU_CCR_ENG2_ETCS_MASK                  (0x1000000U)
#define ETPU_CCR_ENG2_ETCS_SHIFT                 (24U)
#define ETPU_CCR_ENG2_ETCS_WIDTH                 (1U)
#define ETPU_CCR_ENG2_ETCS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_ETCS_SHIFT)) & ETPU_CCR_ENG2_ETCS_MASK)

#define ETPU_CCR_ENG2_ETPD_MASK                  (0x2000000U)
#define ETPU_CCR_ENG2_ETPD_SHIFT                 (25U)
#define ETPU_CCR_ENG2_ETPD_WIDTH                 (1U)
#define ETPU_CCR_ENG2_ETPD(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_ETPD_SHIFT)) & ETPU_CCR_ENG2_ETPD_MASK)

#define ETPU_CCR_ENG2_SSMAE_MASK                 (0x4000000U)
#define ETPU_CCR_ENG2_SSMAE_SHIFT                (26U)
#define ETPU_CCR_ENG2_SSMAE_WIDTH                (1U)
#define ETPU_CCR_ENG2_SSMAE(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_SSMAE_SHIFT)) & ETPU_CCR_ENG2_SSMAE_MASK)

#define ETPU_CCR_ENG2_T4DIS_MASK                 (0x8000000U)
#define ETPU_CCR_ENG2_T4DIS_SHIFT                (27U)
#define ETPU_CCR_ENG2_T4DIS_WIDTH                (1U)
#define ETPU_CCR_ENG2_T4DIS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_T4DIS_SHIFT)) & ETPU_CCR_ENG2_T4DIS_MASK)

#define ETPU_CCR_ENG2_CPR_MASK                   (0x30000000U)
#define ETPU_CCR_ENG2_CPR_SHIFT                  (28U)
#define ETPU_CCR_ENG2_CPR_WIDTH                  (2U)
#define ETPU_CCR_ENG2_CPR(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_CPR_SHIFT)) & ETPU_CCR_ENG2_CPR_MASK)

#define ETPU_CCR_ENG2_DTRE_MASK                  (0x40000000U)
#define ETPU_CCR_ENG2_DTRE_SHIFT                 (30U)
#define ETPU_CCR_ENG2_DTRE_WIDTH                 (1U)
#define ETPU_CCR_ENG2_DTRE(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_DTRE_SHIFT)) & ETPU_CCR_ENG2_DTRE_MASK)

#define ETPU_CCR_ENG2_CIE_MASK                   (0x80000000U)
#define ETPU_CCR_ENG2_CIE_SHIFT                  (31U)
#define ETPU_CCR_ENG2_CIE_WIDTH                  (1U)
#define ETPU_CCR_ENG2_CIE(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CCR_ENG2_CIE_SHIFT)) & ETPU_CCR_ENG2_CIE_MASK)
/*! @} */

/*! @name CSCR_ENG2 - eTPU Channel n Status Control Register for Engine 2 */
/*! @{ */

#define ETPU_CSCR_ENG2_FM_MASK                   (0x3U)
#define ETPU_CSCR_ENG2_FM_SHIFT                  (0U)
#define ETPU_CSCR_ENG2_FM_WIDTH                  (2U)
#define ETPU_CSCR_ENG2_FM(x)                     (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_FM_SHIFT)) & ETPU_CSCR_ENG2_FM_MASK)

#define ETPU_CSCR_ENG2_OBE_MASK                  (0x2000U)
#define ETPU_CSCR_ENG2_OBE_SHIFT                 (13U)
#define ETPU_CSCR_ENG2_OBE_WIDTH                 (1U)
#define ETPU_CSCR_ENG2_OBE(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_OBE_SHIFT)) & ETPU_CSCR_ENG2_OBE_MASK)

#define ETPU_CSCR_ENG2_OPS_MASK                  (0x4000U)
#define ETPU_CSCR_ENG2_OPS_SHIFT                 (14U)
#define ETPU_CSCR_ENG2_OPS_WIDTH                 (1U)
#define ETPU_CSCR_ENG2_OPS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_OPS_SHIFT)) & ETPU_CSCR_ENG2_OPS_MASK)

#define ETPU_CSCR_ENG2_IPS_MASK                  (0x8000U)
#define ETPU_CSCR_ENG2_IPS_SHIFT                 (15U)
#define ETPU_CSCR_ENG2_IPS_WIDTH                 (1U)
#define ETPU_CSCR_ENG2_IPS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_IPS_SHIFT)) & ETPU_CSCR_ENG2_IPS_MASK)

#define ETPU_CSCR_ENG2_DTROS_MASK                (0x400000U)
#define ETPU_CSCR_ENG2_DTROS_SHIFT               (22U)
#define ETPU_CSCR_ENG2_DTROS_WIDTH               (1U)
#define ETPU_CSCR_ENG2_DTROS(x)                  (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_DTROS_SHIFT)) & ETPU_CSCR_ENG2_DTROS_MASK)

#define ETPU_CSCR_ENG2_DTRS_MASK                 (0x800000U)
#define ETPU_CSCR_ENG2_DTRS_SHIFT                (23U)
#define ETPU_CSCR_ENG2_DTRS_WIDTH                (1U)
#define ETPU_CSCR_ENG2_DTRS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_DTRS_SHIFT)) & ETPU_CSCR_ENG2_DTRS_MASK)

#define ETPU_CSCR_ENG2_CIOS_MASK                 (0x40000000U)
#define ETPU_CSCR_ENG2_CIOS_SHIFT                (30U)
#define ETPU_CSCR_ENG2_CIOS_WIDTH                (1U)
#define ETPU_CSCR_ENG2_CIOS(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_CIOS_SHIFT)) & ETPU_CSCR_ENG2_CIOS_MASK)

#define ETPU_CSCR_ENG2_CIS_MASK                  (0x80000000U)
#define ETPU_CSCR_ENG2_CIS_SHIFT                 (31U)
#define ETPU_CSCR_ENG2_CIS_WIDTH                 (1U)
#define ETPU_CSCR_ENG2_CIS(x)                    (((uint32_t)(((uint32_t)(x)) << ETPU_CSCR_ENG2_CIS_SHIFT)) & ETPU_CSCR_ENG2_CIS_MASK)
/*! @} */

/*! @name CHSRR_ENG2 - eTPU Channel n Host Service Request Register for Engine 2 */
/*! @{ */

#define ETPU_CHSRR_ENG2_HSR_MASK                 (0x7U)
#define ETPU_CHSRR_ENG2_HSR_SHIFT                (0U)
#define ETPU_CHSRR_ENG2_HSR_WIDTH                (3U)
#define ETPU_CHSRR_ENG2_HSR(x)                   (((uint32_t)(((uint32_t)(x)) << ETPU_CHSRR_ENG2_HSR_SHIFT)) & ETPU_CHSRR_ENG2_HSR_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group ETPU_Register_Masks */

/*!
 * @}
 */ /* end of group ETPU_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K39_ETPU_H_) */
