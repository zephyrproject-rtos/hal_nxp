/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K358_MSCM.h
 * @version 1.1
 * @date 2022-10-01
 * @brief Peripheral Access Layer for S32K358_MSCM
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
#if !defined(S32K358_MSCM_H_)  /* Check if memory map has not been already included */
#define S32K358_MSCM_H_

#include "S32K358_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Size of Registers Arrays */
#define MSCM_IRSPRC_COUNT                         240u

/** MSCM - Register Layout Typedef */
typedef struct {
  __I  uint32_t CPXTYPE;                           /**< Processor X Type, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor X Number, offset: 0x4 */
  __I  uint32_t CPXREV;                            /**< Processor X Revision, offset: 0x8 */
  __I  uint32_t CPXCFG0;                           /**< Processor X Configuration 0, offset: 0xC */
  __I  uint32_t CPXCFG1;                           /**< Processor X Configuration 1, offset: 0x10 */
  __I  uint32_t CPXCFG2;                           /**< Processor X Configuration 2, offset: 0x14 */
  __I  uint32_t CPXCFG3;                           /**< Processor x Configuration 3, offset: 0x18 */
  uint8_t RESERVED_0[4];
  __I  uint32_t CP0TYPE;                           /**< Processor 0 Type, offset: 0x20 */
  __I  uint32_t CP0NUM;                            /**< Processor 0 Number, offset: 0x24 */
  __I  uint32_t CP0REV;                            /**< Processor 0 Count, offset: 0x28 */
  __I  uint32_t CP0CFG0;                           /**< Processor 0 Configuration 0, offset: 0x2C */
  __I  uint32_t CP0CFG1;                           /**< Processor 0 Configuration 1, offset: 0x30 */
  __I  uint32_t CP0CFG2;                           /**< Processor 0 Configuration 2, offset: 0x34 */
  __I  uint32_t CP0CFG3;                           /**< Processor 0 Configuration 3, offset: 0x38 */
  uint8_t RESERVED_1[4];
  __I  uint32_t CP1TYPE;                           /**< Processor 1 Type, offset: 0x40 */
  __I  uint32_t CP1NUM;                            /**< Processor 1 Number, offset: 0x44 */
  __I  uint32_t CP1REV;                            /**< Processor 1 Count, offset: 0x48 */
  __I  uint32_t CP1CFG0;                           /**< Processor 1 Configuration 0, offset: 0x4C */
  __I  uint32_t CP1CFG1;                           /**< Processor 1 Configuration 1, offset: 0x50 */
  __I  uint32_t CP1CFG2;                           /**< Processor 1 Configuration 2, offset: 0x54 */
  __I  uint32_t CP1CFG3;                           /**< Processor 1 Configuration 3, offset: 0x58 */
  uint8_t RESERVED_2[4];
  __I  uint32_t CP2TYPE;                           /**< Processor 2 Type, offset: 0x60 */
  __I  uint32_t CP2NUM;                            /**< Processor 2 Number, offset: 0x64 */
  __I  uint32_t CP2REV;                            /**< Processor 2 Count, offset: 0x68 */
  __I  uint32_t CP2CFG0;                           /**< Processor 2 Configuration 0, offset: 0x6C */
  __I  uint32_t CP2CFG1;                           /**< Processor 2 Configuration 1, offset: 0x70 */
  __I  uint32_t CP2CFG2;                           /**< Processor 2 Configuration 2, offset: 0x74 */
  __I  uint32_t CP2CFG3;                           /**< Processor 2 Configuration 3, offset: 0x78 */
  uint8_t RESERVED_3[388];
  __IO uint32_t IRCP0ISR0;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x200 */
  __O  uint32_t IRCP0IGR0;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x204 */
  __IO uint32_t IRCP0ISR1;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x208 */
  __O  uint32_t IRCP0IGR1;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x20C */
  __IO uint32_t IRCP0ISR2;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x210 */
  __O  uint32_t IRCP0IGR2;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x214 */
  __IO uint32_t IRCP0ISR3;                         /**< Interrupt Router CP0 Interrupt Status, offset: 0x218 */
  __O  uint32_t IRCP0IGR3;                         /**< Interrupt Router CP0 Interrupt Generation, offset: 0x21C */
  __IO uint32_t IRCP1ISR0;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x220 */
  __O  uint32_t IRCP1IGR0;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x224 */
  __IO uint32_t IRCP1ISR1;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x228 */
  __O  uint32_t IRCP1IGR1;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x22C */
  __IO uint32_t IRCP1ISR2;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x230 */
  __O  uint32_t IRCP1IGR2;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x234 */
  __IO uint32_t IRCP1ISR3;                         /**< Interrupt Router CP1 Interrupt Status, offset: 0x238 */
  __O  uint32_t IRCP1IGR3;                         /**< Interrupt Router CP1 Interrupt Generation, offset: 0x23C */
  __IO uint32_t IRCP2ISR0;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x240 */
  __O  uint32_t IRCP2IGR0;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x244 */
  __IO uint32_t IRCP2ISR1;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x248 */
  __O  uint32_t IRCP2IGR1;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x24C */
  __IO uint32_t IRCP2ISR2;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x250 */
  __O  uint32_t IRCP2IGR2;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x254 */
  __IO uint32_t IRCP2ISR3;                         /**< Interrupt Router CP2 Interrupt Status, offset: 0x258 */
  __O  uint32_t IRCP2IGR3;                         /**< Interrupt Router CP2 Interrupt Generation, offset: 0x25C */
  uint8_t RESERVED_4[416];
  __IO uint32_t IRCPCFG;                           /**< Interrupt Router Configuration, offset: 0x400 */
  uint8_t RESERVED_5[252];
  __IO uint32_t XN_CTRL;                           /**< Memory Execution Control, offset: 0x500 */
  uint8_t RESERVED_6[252];
  __IO uint32_t ENEDC;                             /**< Enable Interconnect Error Detection, offset: 0x600 */
  __IO uint32_t ENEDC1;                            /**< Enable Interconnect Error Detection, offset: 0x604 */
  uint8_t RESERVED_7[248];
  __IO uint32_t IAHBCFGREG;                        /**< AHB Gasket Configuration, offset: 0x700 */
  uint8_t RESERVED_8[380];
  __IO uint16_t IRSPRC[MSCM_IRSPRC_COUNT];         /**< Interrupt Router Shared Peripheral Routing Control, array offset: 0x880, array step: 0x2 */
} MSCM_Type, *MSCM_MemMapPtr;

/** Number of instances of the MSCM module. */
#define MSCM_INSTANCE_COUNT                      (1u)

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define IP_MSCM_BASE                             (0x40260000u)
/** Peripheral MSCM base pointer */
#define IP_MSCM                                  ((MSCM_Type *)IP_MSCM_BASE)
/** Array initializer of MSCM peripheral base addresses */
#define IP_MSCM_BASE_ADDRS                       { IP_MSCM_BASE }
/** Array initializer of MSCM peripheral base pointers */
#define IP_MSCM_BASE_PTRS                        { IP_MSCM }

/* ----------------------------------------------------------------------------
   -- MSCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Register_Masks MSCM Register Masks
 * @{
 */

/*! @name CPXTYPE - Processor X Type */
/*! @{ */

#define MSCM_CPXTYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CPXTYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CPXTYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CPXTYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPXTYPE_PERSONALITY_SHIFT)) & MSCM_CPXTYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPXNUM - Processor X Number */
/*! @{ */

#define MSCM_CPXNUM_CPN_MASK                     (0x7U)
#define MSCM_CPXNUM_CPN_SHIFT                    (0U)
#define MSCM_CPXNUM_CPN_WIDTH                    (3U)
#define MSCM_CPXNUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CPXNUM_CPN_SHIFT)) & MSCM_CPXNUM_CPN_MASK)
/*! @} */

/*! @name CPXREV - Processor X Revision */
/*! @{ */

#define MSCM_CPXREV_RYPZ_MASK                    (0xFFU)
#define MSCM_CPXREV_RYPZ_SHIFT                   (0U)
#define MSCM_CPXREV_RYPZ_WIDTH                   (8U)
#define MSCM_CPXREV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXREV_RYPZ_SHIFT)) & MSCM_CPXREV_RYPZ_MASK)
/*! @} */

/*! @name CPXCFG0 - Processor X Configuration 0 */
/*! @{ */

#define MSCM_CPXCFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CPXCFG0_DCWY_SHIFT                  (0U)
#define MSCM_CPXCFG0_DCWY_WIDTH                  (8U)
#define MSCM_CPXCFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCWY_SHIFT)) & MSCM_CPXCFG0_DCWY_MASK)

#define MSCM_CPXCFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CPXCFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CPXCFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CPXCFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_DCSZ_SHIFT)) & MSCM_CPXCFG0_DCSZ_MASK)

#define MSCM_CPXCFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG0_ICWY_SHIFT                  (16U)
#define MSCM_CPXCFG0_ICWY_WIDTH                  (8U)
#define MSCM_CPXCFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICWY_SHIFT)) & MSCM_CPXCFG0_ICWY_MASK)

#define MSCM_CPXCFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CPXCFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CPXCFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG0_ICSZ_SHIFT)) & MSCM_CPXCFG0_ICSZ_MASK)
/*! @} */

/*! @name CPXCFG1 - Processor X Configuration 1 */
/*! @{ */

#define MSCM_CPXCFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CPXCFG1_L2WY_SHIFT                  (16U)
#define MSCM_CPXCFG1_L2WY_WIDTH                  (8U)
#define MSCM_CPXCFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2WY_SHIFT)) & MSCM_CPXCFG1_L2WY_MASK)

#define MSCM_CPXCFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CPXCFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CPXCFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CPXCFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG1_L2SZ_SHIFT)) & MSCM_CPXCFG1_L2SZ_MASK)
/*! @} */

/*! @name CPXCFG2 - Processor X Configuration 2 */
/*! @{ */

#define MSCM_CPXCFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CPXCFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CPXCFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CPXCFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_ITCMSZ_SHIFT)) & MSCM_CPXCFG2_ITCMSZ_MASK)

#define MSCM_CPXCFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CPXCFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CPXCFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CPXCFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG2_DTCMSZ_SHIFT)) & MSCM_CPXCFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CPXCFG3 - Processor x Configuration 3 */
/*! @{ */

#define MSCM_CPXCFG3_FPU_MASK                    (0x1U)
#define MSCM_CPXCFG3_FPU_SHIFT                   (0U)
#define MSCM_CPXCFG3_FPU_WIDTH                   (1U)
#define MSCM_CPXCFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_FPU_SHIFT)) & MSCM_CPXCFG3_FPU_MASK)

#define MSCM_CPXCFG3_SIMD_MASK                   (0x2U)
#define MSCM_CPXCFG3_SIMD_SHIFT                  (1U)
#define MSCM_CPXCFG3_SIMD_WIDTH                  (1U)
#define MSCM_CPXCFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_SIMD_SHIFT)) & MSCM_CPXCFG3_SIMD_MASK)

#define MSCM_CPXCFG3_MMU_MASK                    (0x4U)
#define MSCM_CPXCFG3_MMU_SHIFT                   (2U)
#define MSCM_CPXCFG3_MMU_WIDTH                   (1U)
#define MSCM_CPXCFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_MMU_SHIFT)) & MSCM_CPXCFG3_MMU_MASK)

#define MSCM_CPXCFG3_CMP_MASK                    (0x8U)
#define MSCM_CPXCFG3_CMP_SHIFT                   (3U)
#define MSCM_CPXCFG3_CMP_WIDTH                   (1U)
#define MSCM_CPXCFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CMP_SHIFT)) & MSCM_CPXCFG3_CMP_MASK)

#define MSCM_CPXCFG3_CPY_MASK                    (0x10U)
#define MSCM_CPXCFG3_CPY_SHIFT                   (4U)
#define MSCM_CPXCFG3_CPY_WIDTH                   (1U)
#define MSCM_CPXCFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CPXCFG3_CPY_SHIFT)) & MSCM_CPXCFG3_CPY_MASK)
/*! @} */

/*! @name CP0TYPE - Processor 0 Type */
/*! @{ */

#define MSCM_CP0TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP0TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP0TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP0TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP0TYPE_PERSONALITY_SHIFT)) & MSCM_CP0TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP0NUM - Processor 0 Number */
/*! @{ */

#define MSCM_CP0NUM_CPN_MASK                     (0x3U)
#define MSCM_CP0NUM_CPN_SHIFT                    (0U)
#define MSCM_CP0NUM_CPN_WIDTH                    (2U)
#define MSCM_CP0NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP0NUM_CPN_SHIFT)) & MSCM_CP0NUM_CPN_MASK)
/*! @} */

/*! @name CP0REV - Processor 0 Count */
/*! @{ */

#define MSCM_CP0REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP0REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP0REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP0REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0REV_RYPZ_SHIFT)) & MSCM_CP0REV_RYPZ_MASK)
/*! @} */

/*! @name CP0CFG0 - Processor 0 Configuration 0 */
/*! @{ */

#define MSCM_CP0CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP0CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP0CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP0CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCWY_SHIFT)) & MSCM_CP0CFG0_DCWY_MASK)

#define MSCM_CP0CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP0CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP0CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP0CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_DCSZ_SHIFT)) & MSCM_CP0CFG0_DCSZ_MASK)

#define MSCM_CP0CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP0CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP0CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICWY_SHIFT)) & MSCM_CP0CFG0_ICWY_MASK)

#define MSCM_CP0CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP0CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP0CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG0_ICSZ_SHIFT)) & MSCM_CP0CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP0CFG1 - Processor 0 Configuration 1 */
/*! @{ */

#define MSCM_CP0CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP0CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP0CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP0CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2WY_SHIFT)) & MSCM_CP0CFG1_L2WY_MASK)

#define MSCM_CP0CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP0CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP0CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP0CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG1_L2SZ_SHIFT)) & MSCM_CP0CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP0CFG2 - Processor 0 Configuration 2 */
/*! @{ */

#define MSCM_CP0CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP0CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP0CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP0CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_ITCMSZ_SHIFT)) & MSCM_CP0CFG2_ITCMSZ_MASK)

#define MSCM_CP0CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP0CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP0CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP0CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG2_DTCMSZ_SHIFT)) & MSCM_CP0CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP0CFG3 - Processor 0 Configuration 3 */
/*! @{ */

#define MSCM_CP0CFG3_FPU_MASK                    (0x1U)
#define MSCM_CP0CFG3_FPU_SHIFT                   (0U)
#define MSCM_CP0CFG3_FPU_WIDTH                   (1U)
#define MSCM_CP0CFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_FPU_SHIFT)) & MSCM_CP0CFG3_FPU_MASK)

#define MSCM_CP0CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP0CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP0CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP0CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_SIMD_SHIFT)) & MSCM_CP0CFG3_SIMD_MASK)

#define MSCM_CP0CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP0CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP0CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP0CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_MMU_SHIFT)) & MSCM_CP0CFG3_MMU_MASK)

#define MSCM_CP0CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP0CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP0CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP0CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_CMP_SHIFT)) & MSCM_CP0CFG3_CMP_MASK)

#define MSCM_CP0CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP0CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP0CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP0CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP0CFG3_CPY_SHIFT)) & MSCM_CP0CFG3_CPY_MASK)
/*! @} */

/*! @name CP1TYPE - Processor 1 Type */
/*! @{ */

#define MSCM_CP1TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP1TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP1TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP1TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP1TYPE_PERSONALITY_SHIFT)) & MSCM_CP1TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP1NUM - Processor 1 Number */
/*! @{ */

#define MSCM_CP1NUM_CPN_MASK                     (0x3U)
#define MSCM_CP1NUM_CPN_SHIFT                    (0U)
#define MSCM_CP1NUM_CPN_WIDTH                    (2U)
#define MSCM_CP1NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP1NUM_CPN_SHIFT)) & MSCM_CP1NUM_CPN_MASK)
/*! @} */

/*! @name CP1REV - Processor 1 Count */
/*! @{ */

#define MSCM_CP1REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP1REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP1REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP1REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1REV_RYPZ_SHIFT)) & MSCM_CP1REV_RYPZ_MASK)
/*! @} */

/*! @name CP1CFG0 - Processor 1 Configuration 0 */
/*! @{ */

#define MSCM_CP1CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP1CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP1CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP1CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_DCWY_SHIFT)) & MSCM_CP1CFG0_DCWY_MASK)

#define MSCM_CP1CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP1CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP1CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP1CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_DCSZ_SHIFT)) & MSCM_CP1CFG0_DCSZ_MASK)

#define MSCM_CP1CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP1CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP1CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP1CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_ICWY_SHIFT)) & MSCM_CP1CFG0_ICWY_MASK)

#define MSCM_CP1CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP1CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP1CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP1CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG0_ICSZ_SHIFT)) & MSCM_CP1CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP1CFG1 - Processor 1 Configuration 1 */
/*! @{ */

#define MSCM_CP1CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP1CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP1CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP1CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG1_L2WY_SHIFT)) & MSCM_CP1CFG1_L2WY_MASK)

#define MSCM_CP1CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP1CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP1CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP1CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG1_L2SZ_SHIFT)) & MSCM_CP1CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP1CFG2 - Processor 1 Configuration 2 */
/*! @{ */

#define MSCM_CP1CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP1CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP1CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP1CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG2_ITCMSZ_SHIFT)) & MSCM_CP1CFG2_ITCMSZ_MASK)

#define MSCM_CP1CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP1CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP1CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP1CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG2_DTCMSZ_SHIFT)) & MSCM_CP1CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP1CFG3 - Processor 1 Configuration 3 */
/*! @{ */

#define MSCM_CP1CFG3_FPU_MASK                    (0x1U)
#define MSCM_CP1CFG3_FPU_SHIFT                   (0U)
#define MSCM_CP1CFG3_FPU_WIDTH                   (1U)
#define MSCM_CP1CFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_FPU_SHIFT)) & MSCM_CP1CFG3_FPU_MASK)

#define MSCM_CP1CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP1CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP1CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP1CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_SIMD_SHIFT)) & MSCM_CP1CFG3_SIMD_MASK)

#define MSCM_CP1CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP1CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP1CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP1CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_MMU_SHIFT)) & MSCM_CP1CFG3_MMU_MASK)

#define MSCM_CP1CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP1CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP1CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP1CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_CMP_SHIFT)) & MSCM_CP1CFG3_CMP_MASK)

#define MSCM_CP1CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP1CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP1CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP1CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP1CFG3_CPY_SHIFT)) & MSCM_CP1CFG3_CPY_MASK)
/*! @} */

/*! @name CP2TYPE - Processor 2 Type */
/*! @{ */

#define MSCM_CP2TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP2TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP2TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP2TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP2TYPE_PERSONALITY_SHIFT)) & MSCM_CP2TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP2NUM - Processor 2 Number */
/*! @{ */

#define MSCM_CP2NUM_CPN_MASK                     (0x3U)
#define MSCM_CP2NUM_CPN_SHIFT                    (0U)
#define MSCM_CP2NUM_CPN_WIDTH                    (2U)
#define MSCM_CP2NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP2NUM_CPN_SHIFT)) & MSCM_CP2NUM_CPN_MASK)
/*! @} */

/*! @name CP2REV - Processor 2 Count */
/*! @{ */

#define MSCM_CP2REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP2REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP2REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP2REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2REV_RYPZ_SHIFT)) & MSCM_CP2REV_RYPZ_MASK)
/*! @} */

/*! @name CP2CFG0 - Processor 2 Configuration 0 */
/*! @{ */

#define MSCM_CP2CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP2CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP2CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP2CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_DCWY_SHIFT)) & MSCM_CP2CFG0_DCWY_MASK)

#define MSCM_CP2CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP2CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP2CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP2CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_DCSZ_SHIFT)) & MSCM_CP2CFG0_DCSZ_MASK)

#define MSCM_CP2CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP2CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP2CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP2CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_ICWY_SHIFT)) & MSCM_CP2CFG0_ICWY_MASK)

#define MSCM_CP2CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP2CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP2CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP2CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG0_ICSZ_SHIFT)) & MSCM_CP2CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP2CFG1 - Processor 2 Configuration 1 */
/*! @{ */

#define MSCM_CP2CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP2CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP2CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP2CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG1_L2WY_SHIFT)) & MSCM_CP2CFG1_L2WY_MASK)

#define MSCM_CP2CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP2CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP2CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP2CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG1_L2SZ_SHIFT)) & MSCM_CP2CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP2CFG2 - Processor 2 Configuration 2 */
/*! @{ */

#define MSCM_CP2CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP2CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP2CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP2CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG2_ITCMSZ_SHIFT)) & MSCM_CP2CFG2_ITCMSZ_MASK)

#define MSCM_CP2CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP2CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP2CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP2CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG2_DTCMSZ_SHIFT)) & MSCM_CP2CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP2CFG3 - Processor 2 Configuration 3 */
/*! @{ */

#define MSCM_CP2CFG3_FPU_MASK                    (0x1U)
#define MSCM_CP2CFG3_FPU_SHIFT                   (0U)
#define MSCM_CP2CFG3_FPU_WIDTH                   (1U)
#define MSCM_CP2CFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_FPU_SHIFT)) & MSCM_CP2CFG3_FPU_MASK)

#define MSCM_CP2CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP2CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP2CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP2CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_SIMD_SHIFT)) & MSCM_CP2CFG3_SIMD_MASK)

#define MSCM_CP2CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP2CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP2CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP2CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_MMU_SHIFT)) & MSCM_CP2CFG3_MMU_MASK)

#define MSCM_CP2CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP2CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP2CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP2CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_CMP_SHIFT)) & MSCM_CP2CFG3_CMP_MASK)

#define MSCM_CP2CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP2CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP2CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP2CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP2CFG3_CPY_SHIFT)) & MSCM_CP2CFG3_CPY_MASK)
/*! @} */

/*! @name IRCP0ISR0 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP0_INT_SHIFT)) & MSCM_IRCP0ISR0_CP0_INT_MASK)

#define MSCM_IRCP0ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP1_INT_SHIFT)) & MSCM_IRCP0ISR0_CP1_INT_MASK)

#define MSCM_IRCP0ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR0_CP2_INT_SHIFT)) & MSCM_IRCP0ISR0_CP2_INT_MASK)
/*! @} */

/*! @name IRCP0IGR0 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR0_INT_EN_SHIFT)) & MSCM_IRCP0IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR1 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP0_INT_SHIFT)) & MSCM_IRCP0ISR1_CP0_INT_MASK)

#define MSCM_IRCP0ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP1_INT_SHIFT)) & MSCM_IRCP0ISR1_CP1_INT_MASK)

#define MSCM_IRCP0ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR1_CP2_INT_SHIFT)) & MSCM_IRCP0ISR1_CP2_INT_MASK)
/*! @} */

/*! @name IRCP0IGR1 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR1_INT_EN_SHIFT)) & MSCM_IRCP0IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR2 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP0_INT_SHIFT)) & MSCM_IRCP0ISR2_CP0_INT_MASK)

#define MSCM_IRCP0ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP1_INT_SHIFT)) & MSCM_IRCP0ISR2_CP1_INT_MASK)

#define MSCM_IRCP0ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR2_CP2_INT_SHIFT)) & MSCM_IRCP0ISR2_CP2_INT_MASK)
/*! @} */

/*! @name IRCP0IGR2 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR2_INT_EN_SHIFT)) & MSCM_IRCP0IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP0ISR3 - Interrupt Router CP0 Interrupt Status */
/*! @{ */

#define MSCM_IRCP0ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP0ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP0ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP0_INT_SHIFT)) & MSCM_IRCP0ISR3_CP0_INT_MASK)

#define MSCM_IRCP0ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP0ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP0ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP1_INT_SHIFT)) & MSCM_IRCP0ISR3_CP1_INT_MASK)

#define MSCM_IRCP0ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP0ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP0ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP0ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0ISR3_CP2_INT_SHIFT)) & MSCM_IRCP0ISR3_CP2_INT_MASK)
/*! @} */

/*! @name IRCP0IGR3 - Interrupt Router CP0 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP0IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP0IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP0IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP0IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP0IGR3_INT_EN_SHIFT)) & MSCM_IRCP0IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR0 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP0_INT_SHIFT)) & MSCM_IRCP1ISR0_CP0_INT_MASK)

#define MSCM_IRCP1ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP1_INT_SHIFT)) & MSCM_IRCP1ISR0_CP1_INT_MASK)

#define MSCM_IRCP1ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR0_CP2_INT_SHIFT)) & MSCM_IRCP1ISR0_CP2_INT_MASK)
/*! @} */

/*! @name IRCP1IGR0 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR0_INT_EN_SHIFT)) & MSCM_IRCP1IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR1 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP0_INT_SHIFT)) & MSCM_IRCP1ISR1_CP0_INT_MASK)

#define MSCM_IRCP1ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP1_INT_SHIFT)) & MSCM_IRCP1ISR1_CP1_INT_MASK)

#define MSCM_IRCP1ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR1_CP2_INT_SHIFT)) & MSCM_IRCP1ISR1_CP2_INT_MASK)
/*! @} */

/*! @name IRCP1IGR1 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR1_INT_EN_SHIFT)) & MSCM_IRCP1IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR2 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP0_INT_SHIFT)) & MSCM_IRCP1ISR2_CP0_INT_MASK)

#define MSCM_IRCP1ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP1_INT_SHIFT)) & MSCM_IRCP1ISR2_CP1_INT_MASK)

#define MSCM_IRCP1ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR2_CP2_INT_SHIFT)) & MSCM_IRCP1ISR2_CP2_INT_MASK)
/*! @} */

/*! @name IRCP1IGR2 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR2_INT_EN_SHIFT)) & MSCM_IRCP1IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP1ISR3 - Interrupt Router CP1 Interrupt Status */
/*! @{ */

#define MSCM_IRCP1ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP1ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP1ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP0_INT_SHIFT)) & MSCM_IRCP1ISR3_CP0_INT_MASK)

#define MSCM_IRCP1ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP1ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP1ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP1_INT_SHIFT)) & MSCM_IRCP1ISR3_CP1_INT_MASK)

#define MSCM_IRCP1ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP1ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP1ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP1ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1ISR3_CP2_INT_SHIFT)) & MSCM_IRCP1ISR3_CP2_INT_MASK)
/*! @} */

/*! @name IRCP1IGR3 - Interrupt Router CP1 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP1IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP1IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP1IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP1IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP1IGR3_INT_EN_SHIFT)) & MSCM_IRCP1IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR0 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR0_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR0_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR0_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP0_INT_SHIFT)) & MSCM_IRCP2ISR0_CP0_INT_MASK)

#define MSCM_IRCP2ISR0_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR0_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR0_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP1_INT_SHIFT)) & MSCM_IRCP2ISR0_CP1_INT_MASK)

#define MSCM_IRCP2ISR0_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR0_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR0_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR0_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR0_CP2_INT_SHIFT)) & MSCM_IRCP2ISR0_CP2_INT_MASK)
/*! @} */

/*! @name IRCP2IGR0 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR0_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR0_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR0_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR0_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR0_INT_EN_SHIFT)) & MSCM_IRCP2IGR0_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR1 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR1_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR1_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR1_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP0_INT_SHIFT)) & MSCM_IRCP2ISR1_CP0_INT_MASK)

#define MSCM_IRCP2ISR1_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR1_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR1_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP1_INT_SHIFT)) & MSCM_IRCP2ISR1_CP1_INT_MASK)

#define MSCM_IRCP2ISR1_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR1_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR1_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR1_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR1_CP2_INT_SHIFT)) & MSCM_IRCP2ISR1_CP2_INT_MASK)
/*! @} */

/*! @name IRCP2IGR1 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR1_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR1_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR1_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR1_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR1_INT_EN_SHIFT)) & MSCM_IRCP2IGR1_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR2 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR2_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR2_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR2_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP0_INT_SHIFT)) & MSCM_IRCP2ISR2_CP0_INT_MASK)

#define MSCM_IRCP2ISR2_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR2_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR2_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP1_INT_SHIFT)) & MSCM_IRCP2ISR2_CP1_INT_MASK)

#define MSCM_IRCP2ISR2_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR2_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR2_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR2_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR2_CP2_INT_SHIFT)) & MSCM_IRCP2ISR2_CP2_INT_MASK)
/*! @} */

/*! @name IRCP2IGR2 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR2_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR2_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR2_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR2_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR2_INT_EN_SHIFT)) & MSCM_IRCP2IGR2_INT_EN_MASK)
/*! @} */

/*! @name IRCP2ISR3 - Interrupt Router CP2 Interrupt Status */
/*! @{ */

#define MSCM_IRCP2ISR3_CP0_INT_MASK              (0x1U)
#define MSCM_IRCP2ISR3_CP0_INT_SHIFT             (0U)
#define MSCM_IRCP2ISR3_CP0_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP0_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP0_INT_SHIFT)) & MSCM_IRCP2ISR3_CP0_INT_MASK)

#define MSCM_IRCP2ISR3_CP1_INT_MASK              (0x2U)
#define MSCM_IRCP2ISR3_CP1_INT_SHIFT             (1U)
#define MSCM_IRCP2ISR3_CP1_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP1_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP1_INT_SHIFT)) & MSCM_IRCP2ISR3_CP1_INT_MASK)

#define MSCM_IRCP2ISR3_CP2_INT_MASK              (0x4U)
#define MSCM_IRCP2ISR3_CP2_INT_SHIFT             (2U)
#define MSCM_IRCP2ISR3_CP2_INT_WIDTH             (1U)
#define MSCM_IRCP2ISR3_CP2_INT(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2ISR3_CP2_INT_SHIFT)) & MSCM_IRCP2ISR3_CP2_INT_MASK)
/*! @} */

/*! @name IRCP2IGR3 - Interrupt Router CP2 Interrupt Generation */
/*! @{ */

#define MSCM_IRCP2IGR3_INT_EN_MASK               (0x1U)
#define MSCM_IRCP2IGR3_INT_EN_SHIFT              (0U)
#define MSCM_IRCP2IGR3_INT_EN_WIDTH              (1U)
#define MSCM_IRCP2IGR3_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_IRCP2IGR3_INT_EN_SHIFT)) & MSCM_IRCP2IGR3_INT_EN_MASK)
/*! @} */

/*! @name IRCPCFG - Interrupt Router Configuration */
/*! @{ */

#define MSCM_IRCPCFG_CP0_TR_MASK                 (0x1U)
#define MSCM_IRCPCFG_CP0_TR_SHIFT                (0U)
#define MSCM_IRCPCFG_CP0_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP0_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP0_TR_SHIFT)) & MSCM_IRCPCFG_CP0_TR_MASK)

#define MSCM_IRCPCFG_CP1_TR_MASK                 (0x2U)
#define MSCM_IRCPCFG_CP1_TR_SHIFT                (1U)
#define MSCM_IRCPCFG_CP1_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP1_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP1_TR_SHIFT)) & MSCM_IRCPCFG_CP1_TR_MASK)

#define MSCM_IRCPCFG_CP2_TR_MASK                 (0x4U)
#define MSCM_IRCPCFG_CP2_TR_SHIFT                (2U)
#define MSCM_IRCPCFG_CP2_TR_WIDTH                (1U)
#define MSCM_IRCPCFG_CP2_TR(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_CP2_TR_SHIFT)) & MSCM_IRCPCFG_CP2_TR_MASK)

#define MSCM_IRCPCFG_LOCK_MASK                   (0x80000000U)
#define MSCM_IRCPCFG_LOCK_SHIFT                  (31U)
#define MSCM_IRCPCFG_LOCK_WIDTH                  (1U)
#define MSCM_IRCPCFG_LOCK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_IRCPCFG_LOCK_SHIFT)) & MSCM_IRCPCFG_LOCK_MASK)
/*! @} */

/*! @name XN_CTRL - Memory Execution Control */
/*! @{ */

#define MSCM_XN_CTRL_PRAM0_MASK                  (0x1U)
#define MSCM_XN_CTRL_PRAM0_SHIFT                 (0U)
#define MSCM_XN_CTRL_PRAM0_WIDTH                 (1U)
#define MSCM_XN_CTRL_PRAM0(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_PRAM0_SHIFT)) & MSCM_XN_CTRL_PRAM0_MASK)

#define MSCM_XN_CTRL_PRAM_1_MASK                 (0x2U)
#define MSCM_XN_CTRL_PRAM_1_SHIFT                (1U)
#define MSCM_XN_CTRL_PRAM_1_WIDTH                (1U)
#define MSCM_XN_CTRL_PRAM_1(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_PRAM_1_SHIFT)) & MSCM_XN_CTRL_PRAM_1_MASK)

#define MSCM_XN_CTRL_PRAM_2_MASK                 (0x4U)
#define MSCM_XN_CTRL_PRAM_2_SHIFT                (2U)
#define MSCM_XN_CTRL_PRAM_2_WIDTH                (1U)
#define MSCM_XN_CTRL_PRAM_2(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_PRAM_2_SHIFT)) & MSCM_XN_CTRL_PRAM_2_MASK)

#define MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC_MASK    (0x100U)
#define MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC_SHIFT   (8U)
#define MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC_WIDTH   (1U)
#define MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_0_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC_MASK    (0x200U)
#define MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC_SHIFT   (9U)
#define MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC_WIDTH   (1U)
#define MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_1_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC_MASK    (0x400U)
#define MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC_SHIFT   (10U)
#define MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC_WIDTH   (1U)
#define MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_2_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_0_ITCM_MASK             (0x1000U)
#define MSCM_XN_CTRL_CM7_0_ITCM_SHIFT            (12U)
#define MSCM_XN_CTRL_CM7_0_ITCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_0_ITCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_0_ITCM_SHIFT)) & MSCM_XN_CTRL_CM7_0_ITCM_MASK)

#define MSCM_XN_CTRL_CM7_1_ITCM_MASK             (0x2000U)
#define MSCM_XN_CTRL_CM7_1_ITCM_SHIFT            (13U)
#define MSCM_XN_CTRL_CM7_1_ITCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_1_ITCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_1_ITCM_SHIFT)) & MSCM_XN_CTRL_CM7_1_ITCM_MASK)

#define MSCM_XN_CTRL_CM7_2_ITCM_MASK             (0x4000U)
#define MSCM_XN_CTRL_CM7_2_ITCM_SHIFT            (14U)
#define MSCM_XN_CTRL_CM7_2_ITCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_2_ITCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_2_ITCM_SHIFT)) & MSCM_XN_CTRL_CM7_2_ITCM_MASK)

#define MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC_MASK (0x10000U)
#define MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC_SHIFT (16U)
#define MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_0_DIS_D0_D1TCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC_MASK (0x20000U)
#define MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC_SHIFT (17U)
#define MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_1_DIS_D0_D1TCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC_MASK (0x40000U)
#define MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC_SHIFT (18U)
#define MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC(x)  (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC_SHIFT)) & MSCM_XN_CTRL_CM7_2_DIS_D0_D1TCM_EXEC_MASK)

#define MSCM_XN_CTRL_CM7_0_DTCM_MASK             (0x100000U)
#define MSCM_XN_CTRL_CM7_0_DTCM_SHIFT            (20U)
#define MSCM_XN_CTRL_CM7_0_DTCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_0_DTCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_0_DTCM_SHIFT)) & MSCM_XN_CTRL_CM7_0_DTCM_MASK)

#define MSCM_XN_CTRL_CM7_1_DTCM_MASK             (0x200000U)
#define MSCM_XN_CTRL_CM7_1_DTCM_SHIFT            (21U)
#define MSCM_XN_CTRL_CM7_1_DTCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_1_DTCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_1_DTCM_SHIFT)) & MSCM_XN_CTRL_CM7_1_DTCM_MASK)

#define MSCM_XN_CTRL_CM7_2_DTCM_MASK             (0x400000U)
#define MSCM_XN_CTRL_CM7_2_DTCM_SHIFT            (22U)
#define MSCM_XN_CTRL_CM7_2_DTCM_WIDTH            (1U)
#define MSCM_XN_CTRL_CM7_2_DTCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_CM7_2_DTCM_SHIFT)) & MSCM_XN_CTRL_CM7_2_DTCM_MASK)

#define MSCM_XN_CTRL_SLK_MASK                    (0x40000000U)
#define MSCM_XN_CTRL_SLK_SHIFT                   (30U)
#define MSCM_XN_CTRL_SLK_WIDTH                   (1U)
#define MSCM_XN_CTRL_SLK(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_SLK_SHIFT)) & MSCM_XN_CTRL_SLK_MASK)

#define MSCM_XN_CTRL_HLK_MASK                    (0x80000000U)
#define MSCM_XN_CTRL_HLK_SHIFT                   (31U)
#define MSCM_XN_CTRL_HLK_WIDTH                   (1U)
#define MSCM_XN_CTRL_HLK(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL_HLK_SHIFT)) & MSCM_XN_CTRL_HLK_MASK)
/*! @} */

/*! @name ENEDC - Enable Interconnect Error Detection */
/*! @{ */

#define MSCM_ENEDC_CM7_0_AHBM_MASK               (0x1U)
#define MSCM_ENEDC_CM7_0_AHBM_SHIFT              (0U)
#define MSCM_ENEDC_CM7_0_AHBM_WIDTH              (1U)
#define MSCM_ENEDC_CM7_0_AHBM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_0_AHBM_SHIFT)) & MSCM_ENEDC_CM7_0_AHBM_MASK)

#define MSCM_ENEDC_CM7_0_AHBP_MASK               (0x2U)
#define MSCM_ENEDC_CM7_0_AHBP_SHIFT              (1U)
#define MSCM_ENEDC_CM7_0_AHBP_WIDTH              (1U)
#define MSCM_ENEDC_CM7_0_AHBP(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_0_AHBP_SHIFT)) & MSCM_ENEDC_CM7_0_AHBP_MASK)

#define MSCM_ENEDC_EDMA_MASK                     (0x4U)
#define MSCM_ENEDC_EDMA_SHIFT                    (2U)
#define MSCM_ENEDC_EDMA_WIDTH                    (1U)
#define MSCM_ENEDC_EDMA(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_EDMA_SHIFT)) & MSCM_ENEDC_EDMA_MASK)

#define MSCM_ENEDC_HSE_MASK                      (0x10U)
#define MSCM_ENEDC_HSE_SHIFT                     (4U)
#define MSCM_ENEDC_HSE_WIDTH                     (1U)
#define MSCM_ENEDC_HSE(x)                        (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_HSE_SHIFT)) & MSCM_ENEDC_HSE_MASK)

#define MSCM_ENEDC_ENET_MASK                     (0x20U)
#define MSCM_ENEDC_ENET_SHIFT                    (5U)
#define MSCM_ENEDC_ENET_WIDTH                    (1U)
#define MSCM_ENEDC_ENET(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ENET_SHIFT)) & MSCM_ENEDC_ENET_MASK)

#define MSCM_ENEDC_CM7_1_AHBM_MASK               (0x40U)
#define MSCM_ENEDC_CM7_1_AHBM_SHIFT              (6U)
#define MSCM_ENEDC_CM7_1_AHBM_WIDTH              (1U)
#define MSCM_ENEDC_CM7_1_AHBM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_1_AHBM_SHIFT)) & MSCM_ENEDC_CM7_1_AHBM_MASK)

#define MSCM_ENEDC_CM7_1_AHBP_MASK               (0x80U)
#define MSCM_ENEDC_CM7_1_AHBP_SHIFT              (7U)
#define MSCM_ENEDC_CM7_1_AHBP_WIDTH              (1U)
#define MSCM_ENEDC_CM7_1_AHBP(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_1_AHBP_SHIFT)) & MSCM_ENEDC_CM7_1_AHBP_MASK)

#define MSCM_ENEDC_ADD_PF0_MASK                  (0x200U)
#define MSCM_ENEDC_ADD_PF0_SHIFT                 (9U)
#define MSCM_ENEDC_ADD_PF0_WIDTH                 (1U)
#define MSCM_ENEDC_ADD_PF0(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_PF0_SHIFT)) & MSCM_ENEDC_ADD_PF0_MASK)

#define MSCM_ENEDC_ADD_PF1_MASK                  (0x400U)
#define MSCM_ENEDC_ADD_PF1_SHIFT                 (10U)
#define MSCM_ENEDC_ADD_PF1_WIDTH                 (1U)
#define MSCM_ENEDC_ADD_PF1(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_PF1_SHIFT)) & MSCM_ENEDC_ADD_PF1_MASK)

#define MSCM_ENEDC_ADD_PF2_MASK                  (0x800U)
#define MSCM_ENEDC_ADD_PF2_SHIFT                 (11U)
#define MSCM_ENEDC_ADD_PF2_WIDTH                 (1U)
#define MSCM_ENEDC_ADD_PF2(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_PF2_SHIFT)) & MSCM_ENEDC_ADD_PF2_MASK)

#define MSCM_ENEDC_PRAM0_MASK                    (0x1000U)
#define MSCM_ENEDC_PRAM0_SHIFT                   (12U)
#define MSCM_ENEDC_PRAM0_WIDTH                   (1U)
#define MSCM_ENEDC_PRAM0(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PRAM0_SHIFT)) & MSCM_ENEDC_PRAM0_MASK)

#define MSCM_ENEDC_ADD_PRAM0_MASK                (0x2000U)
#define MSCM_ENEDC_ADD_PRAM0_SHIFT               (13U)
#define MSCM_ENEDC_ADD_PRAM0_WIDTH               (1U)
#define MSCM_ENEDC_ADD_PRAM0(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_PRAM0_SHIFT)) & MSCM_ENEDC_ADD_PRAM0_MASK)

#define MSCM_ENEDC_PRAM1_MASK                    (0x4000U)
#define MSCM_ENEDC_PRAM1_SHIFT                   (14U)
#define MSCM_ENEDC_PRAM1_WIDTH                   (1U)
#define MSCM_ENEDC_PRAM1(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PRAM1_SHIFT)) & MSCM_ENEDC_PRAM1_MASK)

#define MSCM_ENEDC_ADD_PRAM1_MASK                (0x8000U)
#define MSCM_ENEDC_ADD_PRAM1_SHIFT               (15U)
#define MSCM_ENEDC_ADD_PRAM1_WIDTH               (1U)
#define MSCM_ENEDC_ADD_PRAM1(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_PRAM1_SHIFT)) & MSCM_ENEDC_ADD_PRAM1_MASK)

#define MSCM_ENEDC_ADD_TCM_BACKDOOR_MASK         (0x20000U)
#define MSCM_ENEDC_ADD_TCM_BACKDOOR_SHIFT        (17U)
#define MSCM_ENEDC_ADD_TCM_BACKDOOR_WIDTH        (1U)
#define MSCM_ENEDC_ADD_TCM_BACKDOOR(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_TCM_BACKDOOR_SHIFT)) & MSCM_ENEDC_ADD_TCM_BACKDOOR_MASK)

#define MSCM_ENEDC_QSPI_MASK                     (0x40000U)
#define MSCM_ENEDC_QSPI_SHIFT                    (18U)
#define MSCM_ENEDC_QSPI_WIDTH                    (1U)
#define MSCM_ENEDC_QSPI(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_QSPI_SHIFT)) & MSCM_ENEDC_QSPI_MASK)

#define MSCM_ENEDC_ADD_QSPI_MASK                 (0x80000U)
#define MSCM_ENEDC_ADD_QSPI_SHIFT                (19U)
#define MSCM_ENEDC_ADD_QSPI_WIDTH                (1U)
#define MSCM_ENEDC_ADD_QSPI(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_QSPI_SHIFT)) & MSCM_ENEDC_ADD_QSPI_MASK)

#define MSCM_ENEDC_AIPS0_MASK                    (0x100000U)
#define MSCM_ENEDC_AIPS0_SHIFT                   (20U)
#define MSCM_ENEDC_AIPS0_WIDTH                   (1U)
#define MSCM_ENEDC_AIPS0(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AIPS0_SHIFT)) & MSCM_ENEDC_AIPS0_MASK)

#define MSCM_ENEDC_ADD_AIPS0_MASK                (0x200000U)
#define MSCM_ENEDC_ADD_AIPS0_SHIFT               (21U)
#define MSCM_ENEDC_ADD_AIPS0_WIDTH               (1U)
#define MSCM_ENEDC_ADD_AIPS0(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_AIPS0_SHIFT)) & MSCM_ENEDC_ADD_AIPS0_MASK)

#define MSCM_ENEDC_AIPS1_MASK                    (0x400000U)
#define MSCM_ENEDC_AIPS1_SHIFT                   (22U)
#define MSCM_ENEDC_AIPS1_WIDTH                   (1U)
#define MSCM_ENEDC_AIPS1(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AIPS1_SHIFT)) & MSCM_ENEDC_AIPS1_MASK)

#define MSCM_ENEDC_ADD_AIPS1_MASK                (0x800000U)
#define MSCM_ENEDC_ADD_AIPS1_SHIFT               (23U)
#define MSCM_ENEDC_ADD_AIPS1_WIDTH               (1U)
#define MSCM_ENEDC_ADD_AIPS1(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_AIPS1_SHIFT)) & MSCM_ENEDC_ADD_AIPS1_MASK)

#define MSCM_ENEDC_AIPS2_MASK                    (0x1000000U)
#define MSCM_ENEDC_AIPS2_SHIFT                   (24U)
#define MSCM_ENEDC_AIPS2_WIDTH                   (1U)
#define MSCM_ENEDC_AIPS2(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AIPS2_SHIFT)) & MSCM_ENEDC_AIPS2_MASK)

#define MSCM_ENEDC_ADD_AIPS2_MASK                (0x2000000U)
#define MSCM_ENEDC_ADD_AIPS2_SHIFT               (25U)
#define MSCM_ENEDC_ADD_AIPS2_WIDTH               (1U)
#define MSCM_ENEDC_ADD_AIPS2(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_AIPS2_SHIFT)) & MSCM_ENEDC_ADD_AIPS2_MASK)

#define MSCM_ENEDC_CM7_0_TCM_MASK                (0x4000000U)
#define MSCM_ENEDC_CM7_0_TCM_SHIFT               (26U)
#define MSCM_ENEDC_CM7_0_TCM_WIDTH               (1U)
#define MSCM_ENEDC_CM7_0_TCM(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_0_TCM_SHIFT)) & MSCM_ENEDC_CM7_0_TCM_MASK)

#define MSCM_ENEDC_ADD_CM7_0_TCM_MASK            (0x8000000U)
#define MSCM_ENEDC_ADD_CM7_0_TCM_SHIFT           (27U)
#define MSCM_ENEDC_ADD_CM7_0_TCM_WIDTH           (1U)
#define MSCM_ENEDC_ADD_CM7_0_TCM(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_CM7_0_TCM_SHIFT)) & MSCM_ENEDC_ADD_CM7_0_TCM_MASK)

#define MSCM_ENEDC_CM7_1_TCM_MASK                (0x10000000U)
#define MSCM_ENEDC_CM7_1_TCM_SHIFT               (28U)
#define MSCM_ENEDC_CM7_1_TCM_WIDTH               (1U)
#define MSCM_ENEDC_CM7_1_TCM(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_CM7_1_TCM_SHIFT)) & MSCM_ENEDC_CM7_1_TCM_MASK)

#define MSCM_ENEDC_ADD_CM7_1_TCM_MASK            (0x20000000U)
#define MSCM_ENEDC_ADD_CM7_1_TCM_SHIFT           (29U)
#define MSCM_ENEDC_ADD_CM7_1_TCM_WIDTH           (1U)
#define MSCM_ENEDC_ADD_CM7_1_TCM(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_ADD_CM7_1_TCM_SHIFT)) & MSCM_ENEDC_ADD_CM7_1_TCM_MASK)
/*! @} */

/*! @name ENEDC1 - Enable Interconnect Error Detection */
/*! @{ */

#define MSCM_ENEDC1_CM7_2_AHBM_MASK              (0x4U)
#define MSCM_ENEDC1_CM7_2_AHBM_SHIFT             (2U)
#define MSCM_ENEDC1_CM7_2_AHBM_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_2_AHBM(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_2_AHBM_SHIFT)) & MSCM_ENEDC1_CM7_2_AHBM_MASK)

#define MSCM_ENEDC1_CM7_2_AHBP_MASK              (0x8U)
#define MSCM_ENEDC1_CM7_2_AHBP_SHIFT             (3U)
#define MSCM_ENEDC1_CM7_2_AHBP_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_2_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_2_AHBP_SHIFT)) & MSCM_ENEDC1_CM7_2_AHBP_MASK)

#define MSCM_ENEDC1_PFLASH_3_MASK                (0x10U)
#define MSCM_ENEDC1_PFLASH_3_SHIFT               (4U)
#define MSCM_ENEDC1_PFLASH_3_WIDTH               (1U)
#define MSCM_ENEDC1_PFLASH_3(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PFLASH_3_SHIFT)) & MSCM_ENEDC1_PFLASH_3_MASK)

#define MSCM_ENEDC1_EDMA_S0_MASK                 (0x20U)
#define MSCM_ENEDC1_EDMA_S0_SHIFT                (5U)
#define MSCM_ENEDC1_EDMA_S0_WIDTH                (1U)
#define MSCM_ENEDC1_EDMA_S0(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_EDMA_S0_SHIFT)) & MSCM_ENEDC1_EDMA_S0_MASK)

#define MSCM_ENEDC1_EDMA_S1_MASK                 (0x40U)
#define MSCM_ENEDC1_EDMA_S1_SHIFT                (6U)
#define MSCM_ENEDC1_EDMA_S1_WIDTH                (1U)
#define MSCM_ENEDC1_EDMA_S1(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_EDMA_S1_SHIFT)) & MSCM_ENEDC1_EDMA_S1_MASK)

#define MSCM_ENEDC1_EN_PRAM2_MASK                (0x400U)
#define MSCM_ENEDC1_EN_PRAM2_SHIFT               (10U)
#define MSCM_ENEDC1_EN_PRAM2_WIDTH               (1U)
#define MSCM_ENEDC1_EN_PRAM2(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_EN_PRAM2_SHIFT)) & MSCM_ENEDC1_EN_PRAM2_MASK)

#define MSCM_ENEDC1_ADD_EN_PRAM2_MASK            (0x800U)
#define MSCM_ENEDC1_ADD_EN_PRAM2_SHIFT           (11U)
#define MSCM_ENEDC1_ADD_EN_PRAM2_WIDTH           (1U)
#define MSCM_ENEDC1_ADD_EN_PRAM2(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_ADD_EN_PRAM2_SHIFT)) & MSCM_ENEDC1_ADD_EN_PRAM2_MASK)

#define MSCM_ENEDC1_CM7_2_TCM_MASK               (0x4000U)
#define MSCM_ENEDC1_CM7_2_TCM_SHIFT              (14U)
#define MSCM_ENEDC1_CM7_2_TCM_WIDTH              (1U)
#define MSCM_ENEDC1_CM7_2_TCM(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_2_TCM_SHIFT)) & MSCM_ENEDC1_CM7_2_TCM_MASK)

#define MSCM_ENEDC1_ADD_CM7_2_TCM_MASK           (0x8000U)
#define MSCM_ENEDC1_ADD_CM7_2_TCM_SHIFT          (15U)
#define MSCM_ENEDC1_ADD_CM7_2_TCM_WIDTH          (1U)
#define MSCM_ENEDC1_ADD_CM7_2_TCM(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_ADD_CM7_2_TCM_SHIFT)) & MSCM_ENEDC1_ADD_CM7_2_TCM_MASK)

#define MSCM_ENEDC1_USDHC_MASK                   (0x10000U)
#define MSCM_ENEDC1_USDHC_SHIFT                  (16U)
#define MSCM_ENEDC1_USDHC_WIDTH                  (1U)
#define MSCM_ENEDC1_USDHC(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_USDHC_SHIFT)) & MSCM_ENEDC1_USDHC_MASK)
/*! @} */

/*! @name IAHBCFGREG - AHB Gasket Configuration */
/*! @{ */

#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_MASK     (0x1U)
#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_SHIFT    (0U)
#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_WIDTH    (1U)
#define MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_EMAC_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_MASK (0x2U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_SHIFT (1U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_DMA_AXBS_S0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_MASK (0x4U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_SHIFT (2U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_DMA_AXBS_S1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_MASK      (0x8U)
#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_SHIFT     (3U)
#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_WIDTH     (1U)
#define MSCM_IAHBCFGREG_HSE_DIS_WR_OPT(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_HSE_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_MASK      (0x10U)
#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_SHIFT     (4U)
#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_WIDTH     (1U)
#define MSCM_IAHBCFGREG_TCM_DIS_WR_OPT(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_TCM_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_MASK     (0x20U)
#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_SHIFT    (5U)
#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_WIDTH    (1U)
#define MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_QSPI_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT_MASK (0x40U)
#define MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT_SHIFT (6U)
#define MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_CM7_0_AHBS_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT_MASK (0x80U)
#define MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT_SHIFT (7U)
#define MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_CM7_1_AHBS_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT_MASK (0x100U)
#define MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT_SHIFT (8U)
#define MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT(x) (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_CM7_2_AHBS_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_MASK    (0x200U)
#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_SHIFT   (9U)
#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_AIPS1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_MASK    (0x400U)
#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_SHIFT   (10U)
#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_AIPS2_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT_MASK    (0x800U)
#define MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT_SHIFT   (11U)
#define MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_AIPS0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT_MASK    (0x1000U)
#define MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT_SHIFT   (12U)
#define MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_USDHC_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT_MASK    (0x2000U)
#define MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT_SHIFT   (13U)
#define MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_PRAM0_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT_MASK    (0x4000U)
#define MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT_SHIFT   (14U)
#define MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_PRAM1_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT_MASK (0x8000U)
#define MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT_SHIFT (15U)
#define MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT_WIDTH (1U)
#define MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT(x)   (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_TCM_PRAM_DIS_WR_OPT_MASK)

#define MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT_MASK    (0x10000U)
#define MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT_SHIFT   (16U)
#define MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT_WIDTH   (1U)
#define MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT(x)      (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT_SHIFT)) & MSCM_IAHBCFGREG_PRAM2_DIS_WR_OPT_MASK)
/*! @} */

/*! @name IRSPRC - Interrupt Router Shared Peripheral Routing Control */
/*! @{ */

#define MSCM_IRSPRC_M7_0_MASK                    (0x1U)
#define MSCM_IRSPRC_M7_0_SHIFT                   (0U)
#define MSCM_IRSPRC_M7_0_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_0(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_0_SHIFT)) & MSCM_IRSPRC_M7_0_MASK)

#define MSCM_IRSPRC_M7_1_MASK                    (0x2U)
#define MSCM_IRSPRC_M7_1_SHIFT                   (1U)
#define MSCM_IRSPRC_M7_1_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_1(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_1_SHIFT)) & MSCM_IRSPRC_M7_1_MASK)

#define MSCM_IRSPRC_M7_2_MASK                    (0x4U)
#define MSCM_IRSPRC_M7_2_SHIFT                   (2U)
#define MSCM_IRSPRC_M7_2_WIDTH                   (1U)
#define MSCM_IRSPRC_M7_2(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_M7_2_SHIFT)) & MSCM_IRSPRC_M7_2_MASK)

#define MSCM_IRSPRC_LOCK_MASK                    (0x8000U)
#define MSCM_IRSPRC_LOCK_SHIFT                   (15U)
#define MSCM_IRSPRC_LOCK_WIDTH                   (1U)
#define MSCM_IRSPRC_LOCK(x)                      (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_LOCK_SHIFT)) & MSCM_IRSPRC_LOCK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MSCM_Register_Masks */

/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K358_MSCM_H_) */
