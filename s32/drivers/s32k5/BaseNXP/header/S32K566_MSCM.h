/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_MSCM.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_MSCM
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
#if !defined(S32K566_MSCM_H_)  /* Check if memory map has not been already included */
#define S32K566_MSCM_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- MSCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MSCM_Peripheral_Access_Layer MSCM Peripheral Access Layer
 * @{
 */

/** MSCM - Size of Registers Arrays */
#define MSCM_IRSPRC_CM_DSPV_COUNT                 240u
#define MSCM_IRSPRC_CPE_COUNT                     329u

/** MSCM - Register Layout Typedef */
typedef struct MSCM_Struct {
  __I  uint32_t CPXTYPE;                           /**< Processor X Type, offset: 0x0 */
  __I  uint32_t CPXNUM;                            /**< Processor X Number, offset: 0x4 */
  __I  uint32_t CPXREV;                            /**< Processor X Revision, offset: 0x8 */
  __I  uint32_t CPXCFG0;                           /**< Processor X Configuration 0, offset: 0xC */
  __I  uint32_t CPXCFG1;                           /**< Processor X Configuration 1, offset: 0x10 */
  __I  uint32_t CPXCFG2;                           /**< Processor X Configuration 2, offset: 0x14 */
  __I  uint32_t CPXCFG3;                           /**< Processor X Configuration 3, offset: 0x18 */
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
  uint8_t RESERVED_3[4];
  __I  uint32_t CP3TYPE;                           /**< Processor 3 Type, offset: 0x80 */
  __I  uint32_t CP3NUM;                            /**< Processor 3 Number, offset: 0x84 */
  __I  uint32_t CP3REV;                            /**< Processor 3 Count, offset: 0x88 */
  __I  uint32_t CP3CFG0;                           /**< Processor 3 Configuration 0, offset: 0x8C */
  __I  uint32_t CP3CFG1;                           /**< Processor 3 Configuration 1, offset: 0x90 */
  __I  uint32_t CP3CFG2;                           /**< Processor 3 Configuration 2, offset: 0x94 */
  __I  uint32_t CP3CFG3;                           /**< Processor 3 Configuration 3, offset: 0x98 */
  uint8_t RESERVED_4[4];
  __I  uint32_t LPE_CORE_TYPE;                     /**< LPE Core Type, offset: 0xA0 */
  __I  uint32_t LPE_CORE_NUM;                      /**< LPE Core Number, offset: 0xA4 */
  __I  uint32_t LPE_CORE_REV;                      /**< LPE Core Count, offset: 0xA8 */
  __I  uint32_t LPE_CORE_CFG0;                     /**< LPE Core Configuration 0, offset: 0xAC */
  __I  uint32_t LPE_CORE_CFG1;                     /**< LPE Core Configuration 1, offset: 0xB0 */
  __I  uint32_t LPE_CORE_CFG2;                     /**< LPE Core Configuration 2, offset: 0xB4 */
  __I  uint32_t LPE_CORE_CFG3;                     /**< LPE Core Configuration 3, offset: 0xB8 */
  uint8_t RESERVED_5[4];
  __I  uint32_t DSPV_TYPE;                         /**< DSPV Type, offset: 0xC0 */
  __I  uint32_t DSPV_NUM;                          /**< DSPV Number, offset: 0xC4 */
  __I  uint32_t DSPV_REV;                          /**< DSPV Count, offset: 0xC8 */
  __I  uint32_t DSPV_CFG0;                         /**< DSPV Configuration 0, offset: 0xCC */
  __I  uint32_t DSPV_CFG1;                         /**< DSPV Configuration 1, offset: 0xD0 */
  __I  uint32_t DSPV_CFG2;                         /**< DSPV Configuration 2, offset: 0xD4 */
  __I  uint32_t DSPV_CFG3;                         /**< DSPV Configuration 3, offset: 0xD8 */
  uint8_t RESERVED_6[4];
  __I  uint32_t CPE_CORE_TYPE;                     /**< CPE Core Type, offset: 0xE0 */
  __I  uint32_t CPE_CORE_NUM;                      /**< CPE Core Number, offset: 0xE4 */
  __I  uint32_t CPE_CORE_REV;                      /**< CPE Core Count, offset: 0xE8 */
  __I  uint32_t CPE_CORE_CFG0;                     /**< CPE Core Configuration 0, offset: 0xEC */
  __I  uint32_t CPE_CORE_CFG1;                     /**< CPE Core Configuration 1, offset: 0xF0 */
  __I  uint32_t CPE_CORE_CFG2;                     /**< CPE Core Configuration 2, offset: 0xF4 */
  __I  uint32_t CPE_CORE_CFG3;                     /**< CPE Core Configuration 3, offset: 0xF8 */
  uint8_t RESERVED_7[1028];
  __IO uint32_t XN_CTRL0;                          /**< Memory Execution Control 0, offset: 0x500 */
  __IO uint32_t XN_CTRL1;                          /**< Memory Execution Control 1, offset: 0x504 */
  uint8_t RESERVED_8[8];
  __IO uint32_t PLAT_NMI_CONTROL;                  /**< Platform NMI Control, offset: 0x510 */
  __IO uint32_t LPE_NMI_CONTROL;                   /**< LPE NMI Control, offset: 0x514 */
  __IO uint32_t CPE_NMI_CONTROL;                   /**< CPE NMI Control, offset: 0x518 */
  uint8_t RESERVED_9[228];
  __IO uint32_t ENEDC;                             /**< Enable Interconnect Error Detection, offset: 0x600 */
  __IO uint32_t ENEDC1;                            /**< Enable Interconnect Error Detection, offset: 0x604 */
  uint8_t RESERVED_10[248];
  __IO uint32_t IAHBCFGREG;                        /**< AHB Gasket Configuration, offset: 0x700 */
  uint8_t RESERVED_11[380];
  __IO uint16_t IRSPRC_CM_DSPV[MSCM_IRSPRC_CM_DSPV_COUNT]; /**< Interrupt Router Shared Peripheral Control for the Cortex-M7, Cortex-M4, and DSPV Cores, array offset: 0x880, array step: 0x2 */
  __IO uint16_t IRSPRC_CPE[MSCM_IRSPRC_CPE_COUNT]; /**< Interrupt Router Shared Peripheral Routing Control for CPE Cores, array offset: 0xA60, array step: 0x2 */
} MSCM_Type, *MSCM_MemMapPtr;

/** Number of instances of the MSCM module. */
#define MSCM_INSTANCE_COUNT                      (1u)

/* MSCM - Peripheral instance base addresses */
/** Peripheral MSCM base address */
#define IP_MSCM_BASE                             (0x40494000u)
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

/*! @name CPXCFG3 - Processor X Configuration 3 */
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

/*! @name CP3TYPE - Processor 3 Type */
/*! @{ */

#define MSCM_CP3TYPE_PERSONALITY_MASK            (0xFFFFFFFFU)
#define MSCM_CP3TYPE_PERSONALITY_SHIFT           (0U)
#define MSCM_CP3TYPE_PERSONALITY_WIDTH           (32U)
#define MSCM_CP3TYPE_PERSONALITY(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CP3TYPE_PERSONALITY_SHIFT)) & MSCM_CP3TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CP3NUM - Processor 3 Number */
/*! @{ */

#define MSCM_CP3NUM_CPN_MASK                     (0x3U)
#define MSCM_CP3NUM_CPN_SHIFT                    (0U)
#define MSCM_CP3NUM_CPN_WIDTH                    (2U)
#define MSCM_CP3NUM_CPN(x)                       (((uint32_t)(((uint32_t)(x)) << MSCM_CP3NUM_CPN_SHIFT)) & MSCM_CP3NUM_CPN_MASK)
/*! @} */

/*! @name CP3REV - Processor 3 Count */
/*! @{ */

#define MSCM_CP3REV_RYPZ_MASK                    (0xFFU)
#define MSCM_CP3REV_RYPZ_SHIFT                   (0U)
#define MSCM_CP3REV_RYPZ_WIDTH                   (8U)
#define MSCM_CP3REV_RYPZ(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP3REV_RYPZ_SHIFT)) & MSCM_CP3REV_RYPZ_MASK)
/*! @} */

/*! @name CP3CFG0 - Processor 3 Configuration 0 */
/*! @{ */

#define MSCM_CP3CFG0_DCWY_MASK                   (0xFFU)
#define MSCM_CP3CFG0_DCWY_SHIFT                  (0U)
#define MSCM_CP3CFG0_DCWY_WIDTH                  (8U)
#define MSCM_CP3CFG0_DCWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG0_DCWY_SHIFT)) & MSCM_CP3CFG0_DCWY_MASK)

#define MSCM_CP3CFG0_DCSZ_MASK                   (0xFF00U)
#define MSCM_CP3CFG0_DCSZ_SHIFT                  (8U)
#define MSCM_CP3CFG0_DCSZ_WIDTH                  (8U)
#define MSCM_CP3CFG0_DCSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG0_DCSZ_SHIFT)) & MSCM_CP3CFG0_DCSZ_MASK)

#define MSCM_CP3CFG0_ICWY_MASK                   (0xFF0000U)
#define MSCM_CP3CFG0_ICWY_SHIFT                  (16U)
#define MSCM_CP3CFG0_ICWY_WIDTH                  (8U)
#define MSCM_CP3CFG0_ICWY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG0_ICWY_SHIFT)) & MSCM_CP3CFG0_ICWY_MASK)

#define MSCM_CP3CFG0_ICSZ_MASK                   (0xFF000000U)
#define MSCM_CP3CFG0_ICSZ_SHIFT                  (24U)
#define MSCM_CP3CFG0_ICSZ_WIDTH                  (8U)
#define MSCM_CP3CFG0_ICSZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG0_ICSZ_SHIFT)) & MSCM_CP3CFG0_ICSZ_MASK)
/*! @} */

/*! @name CP3CFG1 - Processor 3 Configuration 1 */
/*! @{ */

#define MSCM_CP3CFG1_L2WY_MASK                   (0xFF0000U)
#define MSCM_CP3CFG1_L2WY_SHIFT                  (16U)
#define MSCM_CP3CFG1_L2WY_WIDTH                  (8U)
#define MSCM_CP3CFG1_L2WY(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG1_L2WY_SHIFT)) & MSCM_CP3CFG1_L2WY_MASK)

#define MSCM_CP3CFG1_L2SZ_MASK                   (0xFF000000U)
#define MSCM_CP3CFG1_L2SZ_SHIFT                  (24U)
#define MSCM_CP3CFG1_L2SZ_WIDTH                  (8U)
#define MSCM_CP3CFG1_L2SZ(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG1_L2SZ_SHIFT)) & MSCM_CP3CFG1_L2SZ_MASK)
/*! @} */

/*! @name CP3CFG2 - Processor 3 Configuration 2 */
/*! @{ */

#define MSCM_CP3CFG2_ITCMSZ_MASK                 (0xFF0000U)
#define MSCM_CP3CFG2_ITCMSZ_SHIFT                (16U)
#define MSCM_CP3CFG2_ITCMSZ_WIDTH                (8U)
#define MSCM_CP3CFG2_ITCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG2_ITCMSZ_SHIFT)) & MSCM_CP3CFG2_ITCMSZ_MASK)

#define MSCM_CP3CFG2_DTCMSZ_MASK                 (0xFF000000U)
#define MSCM_CP3CFG2_DTCMSZ_SHIFT                (24U)
#define MSCM_CP3CFG2_DTCMSZ_WIDTH                (8U)
#define MSCM_CP3CFG2_DTCMSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG2_DTCMSZ_SHIFT)) & MSCM_CP3CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CP3CFG3 - Processor 3 Configuration 3 */
/*! @{ */

#define MSCM_CP3CFG3_FPU_MASK                    (0x1U)
#define MSCM_CP3CFG3_FPU_SHIFT                   (0U)
#define MSCM_CP3CFG3_FPU_WIDTH                   (1U)
#define MSCM_CP3CFG3_FPU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG3_FPU_SHIFT)) & MSCM_CP3CFG3_FPU_MASK)

#define MSCM_CP3CFG3_SIMD_MASK                   (0x2U)
#define MSCM_CP3CFG3_SIMD_SHIFT                  (1U)
#define MSCM_CP3CFG3_SIMD_WIDTH                  (1U)
#define MSCM_CP3CFG3_SIMD(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG3_SIMD_SHIFT)) & MSCM_CP3CFG3_SIMD_MASK)

#define MSCM_CP3CFG3_MMU_MASK                    (0x4U)
#define MSCM_CP3CFG3_MMU_SHIFT                   (2U)
#define MSCM_CP3CFG3_MMU_WIDTH                   (1U)
#define MSCM_CP3CFG3_MMU(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG3_MMU_SHIFT)) & MSCM_CP3CFG3_MMU_MASK)

#define MSCM_CP3CFG3_CMP_MASK                    (0x8U)
#define MSCM_CP3CFG3_CMP_SHIFT                   (3U)
#define MSCM_CP3CFG3_CMP_WIDTH                   (1U)
#define MSCM_CP3CFG3_CMP(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG3_CMP_SHIFT)) & MSCM_CP3CFG3_CMP_MASK)

#define MSCM_CP3CFG3_CPY_MASK                    (0x10U)
#define MSCM_CP3CFG3_CPY_SHIFT                   (4U)
#define MSCM_CP3CFG3_CPY_WIDTH                   (1U)
#define MSCM_CP3CFG3_CPY(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_CP3CFG3_CPY_SHIFT)) & MSCM_CP3CFG3_CPY_MASK)
/*! @} */

/*! @name LPE_CORE_TYPE - LPE Core Type */
/*! @{ */

#define MSCM_LPE_CORE_TYPE_PERSONALITY_MASK      (0xFFFFFFFFU)
#define MSCM_LPE_CORE_TYPE_PERSONALITY_SHIFT     (0U)
#define MSCM_LPE_CORE_TYPE_PERSONALITY_WIDTH     (32U)
#define MSCM_LPE_CORE_TYPE_PERSONALITY(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_TYPE_PERSONALITY_SHIFT)) & MSCM_LPE_CORE_TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name LPE_CORE_NUM - LPE Core Number */
/*! @{ */

#define MSCM_LPE_CORE_NUM_CPN_MASK               (0x3U)
#define MSCM_LPE_CORE_NUM_CPN_SHIFT              (0U)
#define MSCM_LPE_CORE_NUM_CPN_WIDTH              (2U)
#define MSCM_LPE_CORE_NUM_CPN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_NUM_CPN_SHIFT)) & MSCM_LPE_CORE_NUM_CPN_MASK)
/*! @} */

/*! @name LPE_CORE_REV - LPE Core Count */
/*! @{ */

#define MSCM_LPE_CORE_REV_RYPZ_MASK              (0xFFU)
#define MSCM_LPE_CORE_REV_RYPZ_SHIFT             (0U)
#define MSCM_LPE_CORE_REV_RYPZ_WIDTH             (8U)
#define MSCM_LPE_CORE_REV_RYPZ(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_REV_RYPZ_SHIFT)) & MSCM_LPE_CORE_REV_RYPZ_MASK)
/*! @} */

/*! @name LPE_CORE_CFG0 - LPE Core Configuration 0 */
/*! @{ */

#define MSCM_LPE_CORE_CFG0_DCWY_MASK             (0xFFU)
#define MSCM_LPE_CORE_CFG0_DCWY_SHIFT            (0U)
#define MSCM_LPE_CORE_CFG0_DCWY_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG0_DCWY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG0_DCWY_SHIFT)) & MSCM_LPE_CORE_CFG0_DCWY_MASK)

#define MSCM_LPE_CORE_CFG0_DCSZ_MASK             (0xFF00U)
#define MSCM_LPE_CORE_CFG0_DCSZ_SHIFT            (8U)
#define MSCM_LPE_CORE_CFG0_DCSZ_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG0_DCSZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG0_DCSZ_SHIFT)) & MSCM_LPE_CORE_CFG0_DCSZ_MASK)

#define MSCM_LPE_CORE_CFG0_ICWY_MASK             (0xFF0000U)
#define MSCM_LPE_CORE_CFG0_ICWY_SHIFT            (16U)
#define MSCM_LPE_CORE_CFG0_ICWY_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG0_ICWY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG0_ICWY_SHIFT)) & MSCM_LPE_CORE_CFG0_ICWY_MASK)

#define MSCM_LPE_CORE_CFG0_ICSZ_MASK             (0xFF000000U)
#define MSCM_LPE_CORE_CFG0_ICSZ_SHIFT            (24U)
#define MSCM_LPE_CORE_CFG0_ICSZ_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG0_ICSZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG0_ICSZ_SHIFT)) & MSCM_LPE_CORE_CFG0_ICSZ_MASK)
/*! @} */

/*! @name LPE_CORE_CFG1 - LPE Core Configuration 1 */
/*! @{ */

#define MSCM_LPE_CORE_CFG1_L2WY_MASK             (0xFF0000U)
#define MSCM_LPE_CORE_CFG1_L2WY_SHIFT            (16U)
#define MSCM_LPE_CORE_CFG1_L2WY_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG1_L2WY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG1_L2WY_SHIFT)) & MSCM_LPE_CORE_CFG1_L2WY_MASK)

#define MSCM_LPE_CORE_CFG1_L2SZ_MASK             (0xFF000000U)
#define MSCM_LPE_CORE_CFG1_L2SZ_SHIFT            (24U)
#define MSCM_LPE_CORE_CFG1_L2SZ_WIDTH            (8U)
#define MSCM_LPE_CORE_CFG1_L2SZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG1_L2SZ_SHIFT)) & MSCM_LPE_CORE_CFG1_L2SZ_MASK)
/*! @} */

/*! @name LPE_CORE_CFG2 - LPE Core Configuration 2 */
/*! @{ */

#define MSCM_LPE_CORE_CFG2_ITCMSZ_MASK           (0xFF0000U)
#define MSCM_LPE_CORE_CFG2_ITCMSZ_SHIFT          (16U)
#define MSCM_LPE_CORE_CFG2_ITCMSZ_WIDTH          (8U)
#define MSCM_LPE_CORE_CFG2_ITCMSZ(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG2_ITCMSZ_SHIFT)) & MSCM_LPE_CORE_CFG2_ITCMSZ_MASK)

#define MSCM_LPE_CORE_CFG2_DTCMSZ_MASK           (0xFF000000U)
#define MSCM_LPE_CORE_CFG2_DTCMSZ_SHIFT          (24U)
#define MSCM_LPE_CORE_CFG2_DTCMSZ_WIDTH          (8U)
#define MSCM_LPE_CORE_CFG2_DTCMSZ(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG2_DTCMSZ_SHIFT)) & MSCM_LPE_CORE_CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name LPE_CORE_CFG3 - LPE Core Configuration 3 */
/*! @{ */

#define MSCM_LPE_CORE_CFG3_FPU_MASK              (0x1U)
#define MSCM_LPE_CORE_CFG3_FPU_SHIFT             (0U)
#define MSCM_LPE_CORE_CFG3_FPU_WIDTH             (1U)
#define MSCM_LPE_CORE_CFG3_FPU(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG3_FPU_SHIFT)) & MSCM_LPE_CORE_CFG3_FPU_MASK)

#define MSCM_LPE_CORE_CFG3_SIMD_MASK             (0x2U)
#define MSCM_LPE_CORE_CFG3_SIMD_SHIFT            (1U)
#define MSCM_LPE_CORE_CFG3_SIMD_WIDTH            (1U)
#define MSCM_LPE_CORE_CFG3_SIMD(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG3_SIMD_SHIFT)) & MSCM_LPE_CORE_CFG3_SIMD_MASK)

#define MSCM_LPE_CORE_CFG3_MMU_MASK              (0x4U)
#define MSCM_LPE_CORE_CFG3_MMU_SHIFT             (2U)
#define MSCM_LPE_CORE_CFG3_MMU_WIDTH             (1U)
#define MSCM_LPE_CORE_CFG3_MMU(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG3_MMU_SHIFT)) & MSCM_LPE_CORE_CFG3_MMU_MASK)

#define MSCM_LPE_CORE_CFG3_CMP_MASK              (0x8U)
#define MSCM_LPE_CORE_CFG3_CMP_SHIFT             (3U)
#define MSCM_LPE_CORE_CFG3_CMP_WIDTH             (1U)
#define MSCM_LPE_CORE_CFG3_CMP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG3_CMP_SHIFT)) & MSCM_LPE_CORE_CFG3_CMP_MASK)

#define MSCM_LPE_CORE_CFG3_CPY_MASK              (0x10U)
#define MSCM_LPE_CORE_CFG3_CPY_SHIFT             (4U)
#define MSCM_LPE_CORE_CFG3_CPY_WIDTH             (1U)
#define MSCM_LPE_CORE_CFG3_CPY(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_CORE_CFG3_CPY_SHIFT)) & MSCM_LPE_CORE_CFG3_CPY_MASK)
/*! @} */

/*! @name DSPV_TYPE - DSPV Type */
/*! @{ */

#define MSCM_DSPV_TYPE_PERSONALITY_MASK          (0xFFFFFFFFU)
#define MSCM_DSPV_TYPE_PERSONALITY_SHIFT         (0U)
#define MSCM_DSPV_TYPE_PERSONALITY_WIDTH         (32U)
#define MSCM_DSPV_TYPE_PERSONALITY(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_TYPE_PERSONALITY_SHIFT)) & MSCM_DSPV_TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name DSPV_NUM - DSPV Number */
/*! @{ */

#define MSCM_DSPV_NUM_CPN_MASK                   (0x3U)
#define MSCM_DSPV_NUM_CPN_SHIFT                  (0U)
#define MSCM_DSPV_NUM_CPN_WIDTH                  (2U)
#define MSCM_DSPV_NUM_CPN(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_NUM_CPN_SHIFT)) & MSCM_DSPV_NUM_CPN_MASK)
/*! @} */

/*! @name DSPV_REV - DSPV Count */
/*! @{ */

#define MSCM_DSPV_REV_RYPZ_MASK                  (0xFFU)
#define MSCM_DSPV_REV_RYPZ_SHIFT                 (0U)
#define MSCM_DSPV_REV_RYPZ_WIDTH                 (8U)
#define MSCM_DSPV_REV_RYPZ(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_REV_RYPZ_SHIFT)) & MSCM_DSPV_REV_RYPZ_MASK)
/*! @} */

/*! @name DSPV_CFG0 - DSPV Configuration 0 */
/*! @{ */

#define MSCM_DSPV_CFG0_DCWY_MASK                 (0xFFU)
#define MSCM_DSPV_CFG0_DCWY_SHIFT                (0U)
#define MSCM_DSPV_CFG0_DCWY_WIDTH                (8U)
#define MSCM_DSPV_CFG0_DCWY(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG0_DCWY_SHIFT)) & MSCM_DSPV_CFG0_DCWY_MASK)

#define MSCM_DSPV_CFG0_DCSZ_MASK                 (0xFF00U)
#define MSCM_DSPV_CFG0_DCSZ_SHIFT                (8U)
#define MSCM_DSPV_CFG0_DCSZ_WIDTH                (8U)
#define MSCM_DSPV_CFG0_DCSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG0_DCSZ_SHIFT)) & MSCM_DSPV_CFG0_DCSZ_MASK)

#define MSCM_DSPV_CFG0_ICWY_MASK                 (0xFF0000U)
#define MSCM_DSPV_CFG0_ICWY_SHIFT                (16U)
#define MSCM_DSPV_CFG0_ICWY_WIDTH                (8U)
#define MSCM_DSPV_CFG0_ICWY(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG0_ICWY_SHIFT)) & MSCM_DSPV_CFG0_ICWY_MASK)

#define MSCM_DSPV_CFG0_ICSZ_MASK                 (0xFF000000U)
#define MSCM_DSPV_CFG0_ICSZ_SHIFT                (24U)
#define MSCM_DSPV_CFG0_ICSZ_WIDTH                (8U)
#define MSCM_DSPV_CFG0_ICSZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG0_ICSZ_SHIFT)) & MSCM_DSPV_CFG0_ICSZ_MASK)
/*! @} */

/*! @name DSPV_CFG1 - DSPV Configuration 1 */
/*! @{ */

#define MSCM_DSPV_CFG1_L2WY_MASK                 (0xFF0000U)
#define MSCM_DSPV_CFG1_L2WY_SHIFT                (16U)
#define MSCM_DSPV_CFG1_L2WY_WIDTH                (8U)
#define MSCM_DSPV_CFG1_L2WY(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG1_L2WY_SHIFT)) & MSCM_DSPV_CFG1_L2WY_MASK)

#define MSCM_DSPV_CFG1_L2SZ_MASK                 (0xFF000000U)
#define MSCM_DSPV_CFG1_L2SZ_SHIFT                (24U)
#define MSCM_DSPV_CFG1_L2SZ_WIDTH                (8U)
#define MSCM_DSPV_CFG1_L2SZ(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG1_L2SZ_SHIFT)) & MSCM_DSPV_CFG1_L2SZ_MASK)
/*! @} */

/*! @name DSPV_CFG2 - DSPV Configuration 2 */
/*! @{ */

#define MSCM_DSPV_CFG2_ITCMSZ_MASK               (0xFF0000U)
#define MSCM_DSPV_CFG2_ITCMSZ_SHIFT              (16U)
#define MSCM_DSPV_CFG2_ITCMSZ_WIDTH              (8U)
#define MSCM_DSPV_CFG2_ITCMSZ(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG2_ITCMSZ_SHIFT)) & MSCM_DSPV_CFG2_ITCMSZ_MASK)

#define MSCM_DSPV_CFG2_DTCMSZ_MASK               (0xFF000000U)
#define MSCM_DSPV_CFG2_DTCMSZ_SHIFT              (24U)
#define MSCM_DSPV_CFG2_DTCMSZ_WIDTH              (8U)
#define MSCM_DSPV_CFG2_DTCMSZ(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG2_DTCMSZ_SHIFT)) & MSCM_DSPV_CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name DSPV_CFG3 - DSPV Configuration 3 */
/*! @{ */

#define MSCM_DSPV_CFG3_FPU_MASK                  (0x1U)
#define MSCM_DSPV_CFG3_FPU_SHIFT                 (0U)
#define MSCM_DSPV_CFG3_FPU_WIDTH                 (1U)
#define MSCM_DSPV_CFG3_FPU(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG3_FPU_SHIFT)) & MSCM_DSPV_CFG3_FPU_MASK)

#define MSCM_DSPV_CFG3_SIMD_MASK                 (0x2U)
#define MSCM_DSPV_CFG3_SIMD_SHIFT                (1U)
#define MSCM_DSPV_CFG3_SIMD_WIDTH                (1U)
#define MSCM_DSPV_CFG3_SIMD(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG3_SIMD_SHIFT)) & MSCM_DSPV_CFG3_SIMD_MASK)

#define MSCM_DSPV_CFG3_MMU_MASK                  (0x4U)
#define MSCM_DSPV_CFG3_MMU_SHIFT                 (2U)
#define MSCM_DSPV_CFG3_MMU_WIDTH                 (1U)
#define MSCM_DSPV_CFG3_MMU(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG3_MMU_SHIFT)) & MSCM_DSPV_CFG3_MMU_MASK)

#define MSCM_DSPV_CFG3_CMP_MASK                  (0x8U)
#define MSCM_DSPV_CFG3_CMP_SHIFT                 (3U)
#define MSCM_DSPV_CFG3_CMP_WIDTH                 (1U)
#define MSCM_DSPV_CFG3_CMP(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG3_CMP_SHIFT)) & MSCM_DSPV_CFG3_CMP_MASK)

#define MSCM_DSPV_CFG3_CPY_MASK                  (0x10U)
#define MSCM_DSPV_CFG3_CPY_SHIFT                 (4U)
#define MSCM_DSPV_CFG3_CPY_WIDTH                 (1U)
#define MSCM_DSPV_CFG3_CPY(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_DSPV_CFG3_CPY_SHIFT)) & MSCM_DSPV_CFG3_CPY_MASK)
/*! @} */

/*! @name CPE_CORE_TYPE - CPE Core Type */
/*! @{ */

#define MSCM_CPE_CORE_TYPE_PERSONALITY_MASK      (0xFFFFFFFFU)
#define MSCM_CPE_CORE_TYPE_PERSONALITY_SHIFT     (0U)
#define MSCM_CPE_CORE_TYPE_PERSONALITY_WIDTH     (32U)
#define MSCM_CPE_CORE_TYPE_PERSONALITY(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_TYPE_PERSONALITY_SHIFT)) & MSCM_CPE_CORE_TYPE_PERSONALITY_MASK)
/*! @} */

/*! @name CPE_CORE_NUM - CPE Core Number */
/*! @{ */

#define MSCM_CPE_CORE_NUM_CPN_MASK               (0x3U)
#define MSCM_CPE_CORE_NUM_CPN_SHIFT              (0U)
#define MSCM_CPE_CORE_NUM_CPN_WIDTH              (2U)
#define MSCM_CPE_CORE_NUM_CPN(x)                 (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_NUM_CPN_SHIFT)) & MSCM_CPE_CORE_NUM_CPN_MASK)
/*! @} */

/*! @name CPE_CORE_REV - CPE Core Count */
/*! @{ */

#define MSCM_CPE_CORE_REV_RYPZ_MASK              (0xFFU)
#define MSCM_CPE_CORE_REV_RYPZ_SHIFT             (0U)
#define MSCM_CPE_CORE_REV_RYPZ_WIDTH             (8U)
#define MSCM_CPE_CORE_REV_RYPZ(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_REV_RYPZ_SHIFT)) & MSCM_CPE_CORE_REV_RYPZ_MASK)
/*! @} */

/*! @name CPE_CORE_CFG0 - CPE Core Configuration 0 */
/*! @{ */

#define MSCM_CPE_CORE_CFG0_DCWY_MASK             (0xFFU)
#define MSCM_CPE_CORE_CFG0_DCWY_SHIFT            (0U)
#define MSCM_CPE_CORE_CFG0_DCWY_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG0_DCWY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG0_DCWY_SHIFT)) & MSCM_CPE_CORE_CFG0_DCWY_MASK)

#define MSCM_CPE_CORE_CFG0_DCSZ_MASK             (0xFF00U)
#define MSCM_CPE_CORE_CFG0_DCSZ_SHIFT            (8U)
#define MSCM_CPE_CORE_CFG0_DCSZ_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG0_DCSZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG0_DCSZ_SHIFT)) & MSCM_CPE_CORE_CFG0_DCSZ_MASK)

#define MSCM_CPE_CORE_CFG0_ICWY_MASK             (0xFF0000U)
#define MSCM_CPE_CORE_CFG0_ICWY_SHIFT            (16U)
#define MSCM_CPE_CORE_CFG0_ICWY_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG0_ICWY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG0_ICWY_SHIFT)) & MSCM_CPE_CORE_CFG0_ICWY_MASK)

#define MSCM_CPE_CORE_CFG0_ICSZ_MASK             (0xFF000000U)
#define MSCM_CPE_CORE_CFG0_ICSZ_SHIFT            (24U)
#define MSCM_CPE_CORE_CFG0_ICSZ_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG0_ICSZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG0_ICSZ_SHIFT)) & MSCM_CPE_CORE_CFG0_ICSZ_MASK)
/*! @} */

/*! @name CPE_CORE_CFG1 - CPE Core Configuration 1 */
/*! @{ */

#define MSCM_CPE_CORE_CFG1_L2WY_MASK             (0xFF0000U)
#define MSCM_CPE_CORE_CFG1_L2WY_SHIFT            (16U)
#define MSCM_CPE_CORE_CFG1_L2WY_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG1_L2WY(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG1_L2WY_SHIFT)) & MSCM_CPE_CORE_CFG1_L2WY_MASK)

#define MSCM_CPE_CORE_CFG1_L2SZ_MASK             (0xFF000000U)
#define MSCM_CPE_CORE_CFG1_L2SZ_SHIFT            (24U)
#define MSCM_CPE_CORE_CFG1_L2SZ_WIDTH            (8U)
#define MSCM_CPE_CORE_CFG1_L2SZ(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG1_L2SZ_SHIFT)) & MSCM_CPE_CORE_CFG1_L2SZ_MASK)
/*! @} */

/*! @name CPE_CORE_CFG2 - CPE Core Configuration 2 */
/*! @{ */

#define MSCM_CPE_CORE_CFG2_ITCMSZ_MASK           (0xFF0000U)
#define MSCM_CPE_CORE_CFG2_ITCMSZ_SHIFT          (16U)
#define MSCM_CPE_CORE_CFG2_ITCMSZ_WIDTH          (8U)
#define MSCM_CPE_CORE_CFG2_ITCMSZ(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG2_ITCMSZ_SHIFT)) & MSCM_CPE_CORE_CFG2_ITCMSZ_MASK)

#define MSCM_CPE_CORE_CFG2_DTCMSZ_MASK           (0xFF000000U)
#define MSCM_CPE_CORE_CFG2_DTCMSZ_SHIFT          (24U)
#define MSCM_CPE_CORE_CFG2_DTCMSZ_WIDTH          (8U)
#define MSCM_CPE_CORE_CFG2_DTCMSZ(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG2_DTCMSZ_SHIFT)) & MSCM_CPE_CORE_CFG2_DTCMSZ_MASK)
/*! @} */

/*! @name CPE_CORE_CFG3 - CPE Core Configuration 3 */
/*! @{ */

#define MSCM_CPE_CORE_CFG3_FPU_MASK              (0x1U)
#define MSCM_CPE_CORE_CFG3_FPU_SHIFT             (0U)
#define MSCM_CPE_CORE_CFG3_FPU_WIDTH             (1U)
#define MSCM_CPE_CORE_CFG3_FPU(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG3_FPU_SHIFT)) & MSCM_CPE_CORE_CFG3_FPU_MASK)

#define MSCM_CPE_CORE_CFG3_SIMD_MASK             (0x2U)
#define MSCM_CPE_CORE_CFG3_SIMD_SHIFT            (1U)
#define MSCM_CPE_CORE_CFG3_SIMD_WIDTH            (1U)
#define MSCM_CPE_CORE_CFG3_SIMD(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG3_SIMD_SHIFT)) & MSCM_CPE_CORE_CFG3_SIMD_MASK)

#define MSCM_CPE_CORE_CFG3_MMU_MASK              (0x4U)
#define MSCM_CPE_CORE_CFG3_MMU_SHIFT             (2U)
#define MSCM_CPE_CORE_CFG3_MMU_WIDTH             (1U)
#define MSCM_CPE_CORE_CFG3_MMU(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG3_MMU_SHIFT)) & MSCM_CPE_CORE_CFG3_MMU_MASK)

#define MSCM_CPE_CORE_CFG3_CMP_MASK              (0x8U)
#define MSCM_CPE_CORE_CFG3_CMP_SHIFT             (3U)
#define MSCM_CPE_CORE_CFG3_CMP_WIDTH             (1U)
#define MSCM_CPE_CORE_CFG3_CMP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG3_CMP_SHIFT)) & MSCM_CPE_CORE_CFG3_CMP_MASK)

#define MSCM_CPE_CORE_CFG3_CPY_MASK              (0x10U)
#define MSCM_CPE_CORE_CFG3_CPY_SHIFT             (4U)
#define MSCM_CPE_CORE_CFG3_CPY_WIDTH             (1U)
#define MSCM_CPE_CORE_CFG3_CPY(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_CORE_CFG3_CPY_SHIFT)) & MSCM_CPE_CORE_CFG3_CPY_MASK)
/*! @} */

/*! @name XN_CTRL0 - Memory Execution Control 0 */
/*! @{ */

#define MSCM_XN_CTRL0_SRAM0_MASK                 (0x1U)
#define MSCM_XN_CTRL0_SRAM0_SHIFT                (0U)
#define MSCM_XN_CTRL0_SRAM0_WIDTH                (1U)
#define MSCM_XN_CTRL0_SRAM0(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_SRAM0_SHIFT)) & MSCM_XN_CTRL0_SRAM0_MASK)

#define MSCM_XN_CTRL0_SRAM1_MASK                 (0x2U)
#define MSCM_XN_CTRL0_SRAM1_SHIFT                (1U)
#define MSCM_XN_CTRL0_SRAM1_WIDTH                (1U)
#define MSCM_XN_CTRL0_SRAM1(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_SRAM1_SHIFT)) & MSCM_XN_CTRL0_SRAM1_MASK)

#define MSCM_XN_CTRL0_SRAM_2_MASK                (0x4U)
#define MSCM_XN_CTRL0_SRAM_2_SHIFT               (2U)
#define MSCM_XN_CTRL0_SRAM_2_WIDTH               (1U)
#define MSCM_XN_CTRL0_SRAM_2(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_SRAM_2_SHIFT)) & MSCM_XN_CTRL0_SRAM_2_MASK)

#define MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC_MASK  (0x10U)
#define MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC_SHIFT (4U)
#define MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE_0_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC_MASK  (0x20U)
#define MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC_SHIFT (5U)
#define MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE_1_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC_MASK  (0x40U)
#define MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC_SHIFT (6U)
#define MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE_2_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC_MASK  (0x80U)
#define MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC_SHIFT (7U)
#define MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE_3_DIS_ITCM_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC_MASK  (0x100U)
#define MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC_SHIFT (8U)
#define MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE0_D0TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC_MASK  (0x200U)
#define MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC_SHIFT (9U)
#define MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE1_D0TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC_MASK  (0x400U)
#define MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC_SHIFT (10U)
#define MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE2_D0TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC_MASK  (0x800U)
#define MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC_SHIFT (11U)
#define MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE3_D0TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC_MASK  (0x1000U)
#define MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC_SHIFT (12U)
#define MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE0_D1TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC_MASK  (0x2000U)
#define MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC_SHIFT (13U)
#define MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE1_D1TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC_MASK  (0x4000U)
#define MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC_SHIFT (14U)
#define MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE2_D1TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC_MASK  (0x8000U)
#define MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC_SHIFT (15U)
#define MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC(x)    (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC_SHIFT)) & MSCM_XN_CTRL0_CORE3_D1TCM_DIS_EXEC_MASK)

#define MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS_MASK (0x10000U)
#define MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS_SHIFT (16U)
#define MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE0_ITCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS_MASK (0x20000U)
#define MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS_SHIFT (17U)
#define MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE1_ITCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS_MASK (0x40000U)
#define MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS_SHIFT (18U)
#define MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE2_ITCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS_MASK (0x80000U)
#define MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS_SHIFT (19U)
#define MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE3_ITCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS_MASK (0x100000U)
#define MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS_SHIFT (20U)
#define MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE0_DTCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS_MASK (0x200000U)
#define MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS_SHIFT (21U)
#define MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE1_DTCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS_MASK (0x400000U)
#define MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS_SHIFT (22U)
#define MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE2_DTCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS_MASK (0x800000U)
#define MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS_SHIFT (23U)
#define MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS_WIDTH (1U)
#define MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS(x) (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS_SHIFT)) & MSCM_XN_CTRL0_CORE3_DTCM_BACKDOOR_ACCESS_MASK)

#define MSCM_XN_CTRL0_NEUTRON_ITCM_MASK          (0x1000000U)
#define MSCM_XN_CTRL0_NEUTRON_ITCM_SHIFT         (24U)
#define MSCM_XN_CTRL0_NEUTRON_ITCM_WIDTH         (1U)
#define MSCM_XN_CTRL0_NEUTRON_ITCM(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_NEUTRON_ITCM_SHIFT)) & MSCM_XN_CTRL0_NEUTRON_ITCM_MASK)

#define MSCM_XN_CTRL0_NEUTRON_DTCM_MASK          (0x2000000U)
#define MSCM_XN_CTRL0_NEUTRON_DTCM_SHIFT         (25U)
#define MSCM_XN_CTRL0_NEUTRON_DTCM_WIDTH         (1U)
#define MSCM_XN_CTRL0_NEUTRON_DTCM(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_NEUTRON_DTCM_SHIFT)) & MSCM_XN_CTRL0_NEUTRON_DTCM_MASK)

#define MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM_MASK     (0x4000000U)
#define MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM_SHIFT    (26U)
#define MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM_WIDTH    (1U)
#define MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM_SHIFT)) & MSCM_XN_CTRL0_NEUTRON_TCM_HDRAM_MASK)

#define MSCM_XN_CTRL0_DSPV_SRAM0_MASK            (0x8000000U)
#define MSCM_XN_CTRL0_DSPV_SRAM0_SHIFT           (27U)
#define MSCM_XN_CTRL0_DSPV_SRAM0_WIDTH           (1U)
#define MSCM_XN_CTRL0_DSPV_SRAM0(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_DSPV_SRAM0_SHIFT)) & MSCM_XN_CTRL0_DSPV_SRAM0_MASK)

#define MSCM_XN_CTRL0_DSPV_SRAM1_MASK            (0x10000000U)
#define MSCM_XN_CTRL0_DSPV_SRAM1_SHIFT           (28U)
#define MSCM_XN_CTRL0_DSPV_SRAM1_WIDTH           (1U)
#define MSCM_XN_CTRL0_DSPV_SRAM1(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_DSPV_SRAM1_SHIFT)) & MSCM_XN_CTRL0_DSPV_SRAM1_MASK)

#define MSCM_XN_CTRL0_DSPV_SRAM2_MASK            (0x20000000U)
#define MSCM_XN_CTRL0_DSPV_SRAM2_SHIFT           (29U)
#define MSCM_XN_CTRL0_DSPV_SRAM2_WIDTH           (1U)
#define MSCM_XN_CTRL0_DSPV_SRAM2(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_DSPV_SRAM2_SHIFT)) & MSCM_XN_CTRL0_DSPV_SRAM2_MASK)

#define MSCM_XN_CTRL0_SLK_MASK                   (0x40000000U)
#define MSCM_XN_CTRL0_SLK_SHIFT                  (30U)
#define MSCM_XN_CTRL0_SLK_WIDTH                  (1U)
#define MSCM_XN_CTRL0_SLK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_SLK_SHIFT)) & MSCM_XN_CTRL0_SLK_MASK)

#define MSCM_XN_CTRL0_HLK_MASK                   (0x80000000U)
#define MSCM_XN_CTRL0_HLK_SHIFT                  (31U)
#define MSCM_XN_CTRL0_HLK_WIDTH                  (1U)
#define MSCM_XN_CTRL0_HLK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL0_HLK_SHIFT)) & MSCM_XN_CTRL0_HLK_MASK)
/*! @} */

/*! @name XN_CTRL1 - Memory Execution Control 1 */
/*! @{ */

#define MSCM_XN_CTRL1_LPE_CODE_SRAM_MASK         (0x1U)
#define MSCM_XN_CTRL1_LPE_CODE_SRAM_SHIFT        (0U)
#define MSCM_XN_CTRL1_LPE_CODE_SRAM_WIDTH        (1U)
#define MSCM_XN_CTRL1_LPE_CODE_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_LPE_CODE_SRAM_SHIFT)) & MSCM_XN_CTRL1_LPE_CODE_SRAM_MASK)

#define MSCM_XN_CTRL1_LPE_DATA_SRAM_MASK         (0x2U)
#define MSCM_XN_CTRL1_LPE_DATA_SRAM_SHIFT        (1U)
#define MSCM_XN_CTRL1_LPE_DATA_SRAM_WIDTH        (1U)
#define MSCM_XN_CTRL1_LPE_DATA_SRAM(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_LPE_DATA_SRAM_SHIFT)) & MSCM_XN_CTRL1_LPE_DATA_SRAM_MASK)

#define MSCM_XN_CTRL1_CPE_SRAM0_MASK             (0x4U)
#define MSCM_XN_CTRL1_CPE_SRAM0_SHIFT            (2U)
#define MSCM_XN_CTRL1_CPE_SRAM0_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_SRAM0(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_SRAM0_SHIFT)) & MSCM_XN_CTRL1_CPE_SRAM0_MASK)

#define MSCM_XN_CTRL1_CPE_SRAM1_MASK             (0x8U)
#define MSCM_XN_CTRL1_CPE_SRAM1_SHIFT            (3U)
#define MSCM_XN_CTRL1_CPE_SRAM1_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_SRAM1(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_SRAM1_SHIFT)) & MSCM_XN_CTRL1_CPE_SRAM1_MASK)

#define MSCM_XN_CTRL1_CPE_SRAM2_MASK             (0x10U)
#define MSCM_XN_CTRL1_CPE_SRAM2_SHIFT            (4U)
#define MSCM_XN_CTRL1_CPE_SRAM2_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_SRAM2(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_SRAM2_SHIFT)) & MSCM_XN_CTRL1_CPE_SRAM2_MASK)

#define MSCM_XN_CTRL1_CPE_SRAM3_MASK             (0x20U)
#define MSCM_XN_CTRL1_CPE_SRAM3_SHIFT            (5U)
#define MSCM_XN_CTRL1_CPE_SRAM3_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_SRAM3(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_SRAM3_SHIFT)) & MSCM_XN_CTRL1_CPE_SRAM3_MASK)

#define MSCM_XN_CTRL1_CPE_A0TCM_MASK             (0x40U)
#define MSCM_XN_CTRL1_CPE_A0TCM_SHIFT            (6U)
#define MSCM_XN_CTRL1_CPE_A0TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_A0TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_A0TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_A0TCM_MASK)

#define MSCM_XN_CTRL1_CPE_B0TCM_MASK             (0x80U)
#define MSCM_XN_CTRL1_CPE_B0TCM_SHIFT            (7U)
#define MSCM_XN_CTRL1_CPE_B0TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_B0TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_B0TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_B0TCM_MASK)

#define MSCM_XN_CTRL1_CPE_C0TCM_MASK             (0x100U)
#define MSCM_XN_CTRL1_CPE_C0TCM_SHIFT            (8U)
#define MSCM_XN_CTRL1_CPE_C0TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_C0TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_C0TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_C0TCM_MASK)

#define MSCM_XN_CTRL1_CPE_A1TCM_MASK             (0x200U)
#define MSCM_XN_CTRL1_CPE_A1TCM_SHIFT            (9U)
#define MSCM_XN_CTRL1_CPE_A1TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_A1TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_A1TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_A1TCM_MASK)

#define MSCM_XN_CTRL1_CPE_B1TCM_MASK             (0x400U)
#define MSCM_XN_CTRL1_CPE_B1TCM_SHIFT            (10U)
#define MSCM_XN_CTRL1_CPE_B1TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_B1TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_B1TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_B1TCM_MASK)

#define MSCM_XN_CTRL1_CPE_C1TCM_MASK             (0x800U)
#define MSCM_XN_CTRL1_CPE_C1TCM_SHIFT            (11U)
#define MSCM_XN_CTRL1_CPE_C1TCM_WIDTH            (1U)
#define MSCM_XN_CTRL1_CPE_C1TCM(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_C1TCM_SHIFT)) & MSCM_XN_CTRL1_CPE_C1TCM_MASK)

#define MSCM_XN_CTRL1_CPE_LLC0_MASK              (0x1000U)
#define MSCM_XN_CTRL1_CPE_LLC0_SHIFT             (12U)
#define MSCM_XN_CTRL1_CPE_LLC0_WIDTH             (1U)
#define MSCM_XN_CTRL1_CPE_LLC0(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_LLC0_SHIFT)) & MSCM_XN_CTRL1_CPE_LLC0_MASK)

#define MSCM_XN_CTRL1_CPE_LLC1_MASK              (0x2000U)
#define MSCM_XN_CTRL1_CPE_LLC1_SHIFT             (13U)
#define MSCM_XN_CTRL1_CPE_LLC1_WIDTH             (1U)
#define MSCM_XN_CTRL1_CPE_LLC1(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_CPE_LLC1_SHIFT)) & MSCM_XN_CTRL1_CPE_LLC1_MASK)

#define MSCM_XN_CTRL1_SLK_MASK                   (0x40000000U)
#define MSCM_XN_CTRL1_SLK_SHIFT                  (30U)
#define MSCM_XN_CTRL1_SLK_WIDTH                  (1U)
#define MSCM_XN_CTRL1_SLK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_SLK_SHIFT)) & MSCM_XN_CTRL1_SLK_MASK)

#define MSCM_XN_CTRL1_HLK_MASK                   (0x80000000U)
#define MSCM_XN_CTRL1_HLK_SHIFT                  (31U)
#define MSCM_XN_CTRL1_HLK_WIDTH                  (1U)
#define MSCM_XN_CTRL1_HLK(x)                     (((uint32_t)(((uint32_t)(x)) << MSCM_XN_CTRL1_HLK_SHIFT)) & MSCM_XN_CTRL1_HLK_MASK)
/*! @} */

/*! @name PLAT_NMI_CONTROL - Platform NMI Control */
/*! @{ */

#define MSCM_PLAT_NMI_CONTROL_PLT_C0_MASK        (0x1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C0_SHIFT       (0U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C0_WIDTH       (1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C0(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_PLT_C0_SHIFT)) & MSCM_PLAT_NMI_CONTROL_PLT_C0_MASK)

#define MSCM_PLAT_NMI_CONTROL_PLT_C1_MASK        (0x2U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C1_SHIFT       (1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C1_WIDTH       (1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C1(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_PLT_C1_SHIFT)) & MSCM_PLAT_NMI_CONTROL_PLT_C1_MASK)

#define MSCM_PLAT_NMI_CONTROL_PLT_C2_MASK        (0x4U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C2_SHIFT       (2U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C2_WIDTH       (1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C2(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_PLT_C2_SHIFT)) & MSCM_PLAT_NMI_CONTROL_PLT_C2_MASK)

#define MSCM_PLAT_NMI_CONTROL_PLT_C3_MASK        (0x8U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C3_SHIFT       (3U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C3_WIDTH       (1U)
#define MSCM_PLAT_NMI_CONTROL_PLT_C3(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_PLT_C3_SHIFT)) & MSCM_PLAT_NMI_CONTROL_PLT_C3_MASK)

#define MSCM_PLAT_NMI_CONTROL_SLK_MASK           (0x40000000U)
#define MSCM_PLAT_NMI_CONTROL_SLK_SHIFT          (30U)
#define MSCM_PLAT_NMI_CONTROL_SLK_WIDTH          (1U)
#define MSCM_PLAT_NMI_CONTROL_SLK(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_SLK_SHIFT)) & MSCM_PLAT_NMI_CONTROL_SLK_MASK)

#define MSCM_PLAT_NMI_CONTROL_HLK_MASK           (0x80000000U)
#define MSCM_PLAT_NMI_CONTROL_HLK_SHIFT          (31U)
#define MSCM_PLAT_NMI_CONTROL_HLK_WIDTH          (1U)
#define MSCM_PLAT_NMI_CONTROL_HLK(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_PLAT_NMI_CONTROL_HLK_SHIFT)) & MSCM_PLAT_NMI_CONTROL_HLK_MASK)
/*! @} */

/*! @name LPE_NMI_CONTROL - LPE NMI Control */
/*! @{ */

#define MSCM_LPE_NMI_CONTROL_LPE_C0_MASK         (0x1U)
#define MSCM_LPE_NMI_CONTROL_LPE_C0_SHIFT        (0U)
#define MSCM_LPE_NMI_CONTROL_LPE_C0_WIDTH        (1U)
#define MSCM_LPE_NMI_CONTROL_LPE_C0(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_NMI_CONTROL_LPE_C0_SHIFT)) & MSCM_LPE_NMI_CONTROL_LPE_C0_MASK)

#define MSCM_LPE_NMI_CONTROL_SLK_MASK            (0x40000000U)
#define MSCM_LPE_NMI_CONTROL_SLK_SHIFT           (30U)
#define MSCM_LPE_NMI_CONTROL_SLK_WIDTH           (1U)
#define MSCM_LPE_NMI_CONTROL_SLK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_NMI_CONTROL_SLK_SHIFT)) & MSCM_LPE_NMI_CONTROL_SLK_MASK)

#define MSCM_LPE_NMI_CONTROL_HLK_MASK            (0x80000000U)
#define MSCM_LPE_NMI_CONTROL_HLK_SHIFT           (31U)
#define MSCM_LPE_NMI_CONTROL_HLK_WIDTH           (1U)
#define MSCM_LPE_NMI_CONTROL_HLK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_LPE_NMI_CONTROL_HLK_SHIFT)) & MSCM_LPE_NMI_CONTROL_HLK_MASK)
/*! @} */

/*! @name CPE_NMI_CONTROL - CPE NMI Control */
/*! @{ */

#define MSCM_CPE_NMI_CONTROL_CPE_C0_MASK         (0x1U)
#define MSCM_CPE_NMI_CONTROL_CPE_C0_SHIFT        (0U)
#define MSCM_CPE_NMI_CONTROL_CPE_C0_WIDTH        (1U)
#define MSCM_CPE_NMI_CONTROL_CPE_C0(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_NMI_CONTROL_CPE_C0_SHIFT)) & MSCM_CPE_NMI_CONTROL_CPE_C0_MASK)

#define MSCM_CPE_NMI_CONTROL_CPE_C1_MASK         (0x2U)
#define MSCM_CPE_NMI_CONTROL_CPE_C1_SHIFT        (1U)
#define MSCM_CPE_NMI_CONTROL_CPE_C1_WIDTH        (1U)
#define MSCM_CPE_NMI_CONTROL_CPE_C1(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_NMI_CONTROL_CPE_C1_SHIFT)) & MSCM_CPE_NMI_CONTROL_CPE_C1_MASK)

#define MSCM_CPE_NMI_CONTROL_SLK_MASK            (0x40000000U)
#define MSCM_CPE_NMI_CONTROL_SLK_SHIFT           (30U)
#define MSCM_CPE_NMI_CONTROL_SLK_WIDTH           (1U)
#define MSCM_CPE_NMI_CONTROL_SLK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_NMI_CONTROL_SLK_SHIFT)) & MSCM_CPE_NMI_CONTROL_SLK_MASK)

#define MSCM_CPE_NMI_CONTROL_HLK_MASK            (0x80000000U)
#define MSCM_CPE_NMI_CONTROL_HLK_SHIFT           (31U)
#define MSCM_CPE_NMI_CONTROL_HLK_WIDTH           (1U)
#define MSCM_CPE_NMI_CONTROL_HLK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_CPE_NMI_CONTROL_HLK_SHIFT)) & MSCM_CPE_NMI_CONTROL_HLK_MASK)
/*! @} */

/*! @name ENEDC - Enable Interconnect Error Detection */
/*! @{ */

#define MSCM_ENEDC_PBR1_DATA_CHK_MASK            (0x1U)
#define MSCM_ENEDC_PBR1_DATA_CHK_SHIFT           (0U)
#define MSCM_ENEDC_PBR1_DATA_CHK_WIDTH           (1U)
#define MSCM_ENEDC_PBR1_DATA_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR1_DATA_CHK_SHIFT)) & MSCM_ENEDC_PBR1_DATA_CHK_MASK)

#define MSCM_ENEDC_PBR1_ADD_CHK_MASK             (0x2U)
#define MSCM_ENEDC_PBR1_ADD_CHK_SHIFT            (1U)
#define MSCM_ENEDC_PBR1_ADD_CHK_WIDTH            (1U)
#define MSCM_ENEDC_PBR1_ADD_CHK(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR1_ADD_CHK_SHIFT)) & MSCM_ENEDC_PBR1_ADD_CHK_MASK)

#define MSCM_ENEDC_PBR2_DATA_CHK_MASK            (0x4U)
#define MSCM_ENEDC_PBR2_DATA_CHK_SHIFT           (2U)
#define MSCM_ENEDC_PBR2_DATA_CHK_WIDTH           (1U)
#define MSCM_ENEDC_PBR2_DATA_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR2_DATA_CHK_SHIFT)) & MSCM_ENEDC_PBR2_DATA_CHK_MASK)

#define MSCM_ENEDC_PBR2_ADD_CHK_MASK             (0x8U)
#define MSCM_ENEDC_PBR2_ADD_CHK_SHIFT            (3U)
#define MSCM_ENEDC_PBR2_ADD_CHK_WIDTH            (1U)
#define MSCM_ENEDC_PBR2_ADD_CHK(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR2_ADD_CHK_SHIFT)) & MSCM_ENEDC_PBR2_ADD_CHK_MASK)

#define MSCM_ENEDC_PBR3_DATA_CHK_MASK            (0x10U)
#define MSCM_ENEDC_PBR3_DATA_CHK_SHIFT           (4U)
#define MSCM_ENEDC_PBR3_DATA_CHK_WIDTH           (1U)
#define MSCM_ENEDC_PBR3_DATA_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR3_DATA_CHK_SHIFT)) & MSCM_ENEDC_PBR3_DATA_CHK_MASK)

#define MSCM_ENEDC_PBR3_ADD_CHK_MASK             (0x20U)
#define MSCM_ENEDC_PBR3_ADD_CHK_SHIFT            (5U)
#define MSCM_ENEDC_PBR3_ADD_CHK_WIDTH            (1U)
#define MSCM_ENEDC_PBR3_ADD_CHK(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR3_ADD_CHK_SHIFT)) & MSCM_ENEDC_PBR3_ADD_CHK_MASK)

#define MSCM_ENEDC_PBR4_DATA_CHK_MASK            (0x40U)
#define MSCM_ENEDC_PBR4_DATA_CHK_SHIFT           (6U)
#define MSCM_ENEDC_PBR4_DATA_CHK_WIDTH           (1U)
#define MSCM_ENEDC_PBR4_DATA_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR4_DATA_CHK_SHIFT)) & MSCM_ENEDC_PBR4_DATA_CHK_MASK)

#define MSCM_ENEDC_PBR4_ADD_CHK_MASK             (0x80U)
#define MSCM_ENEDC_PBR4_ADD_CHK_SHIFT            (7U)
#define MSCM_ENEDC_PBR4_ADD_CHK_WIDTH            (1U)
#define MSCM_ENEDC_PBR4_ADD_CHK(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR4_ADD_CHK_SHIFT)) & MSCM_ENEDC_PBR4_ADD_CHK_MASK)

#define MSCM_ENEDC_PBR5_DATA_CHK_MASK            (0x100U)
#define MSCM_ENEDC_PBR5_DATA_CHK_SHIFT           (8U)
#define MSCM_ENEDC_PBR5_DATA_CHK_WIDTH           (1U)
#define MSCM_ENEDC_PBR5_DATA_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR5_DATA_CHK_SHIFT)) & MSCM_ENEDC_PBR5_DATA_CHK_MASK)

#define MSCM_ENEDC_PBR5_ADD_CHK_MASK             (0x200U)
#define MSCM_ENEDC_PBR5_ADD_CHK_SHIFT            (9U)
#define MSCM_ENEDC_PBR5_ADD_CHK_WIDTH            (1U)
#define MSCM_ENEDC_PBR5_ADD_CHK(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_PBR5_ADD_CHK_SHIFT)) & MSCM_ENEDC_PBR5_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_AUX0_ADD_CHK_MASK        (0x400U)
#define MSCM_ENEDC_AXBS_AUX0_ADD_CHK_SHIFT       (10U)
#define MSCM_ENEDC_AXBS_AUX0_ADD_CHK_WIDTH       (1U)
#define MSCM_ENEDC_AXBS_AUX0_ADD_CHK(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_AUX0_ADD_CHK_SHIFT)) & MSCM_ENEDC_AXBS_AUX0_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_AUX0_WR_CHK_MASK         (0x800U)
#define MSCM_ENEDC_AXBS_AUX0_WR_CHK_SHIFT        (11U)
#define MSCM_ENEDC_AXBS_AUX0_WR_CHK_WIDTH        (1U)
#define MSCM_ENEDC_AXBS_AUX0_WR_CHK(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_AUX0_WR_CHK_SHIFT)) & MSCM_ENEDC_AXBS_AUX0_WR_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE0_ADD_CHK_MASK       (0x1000U)
#define MSCM_ENEDC_AXBS_CORE0_ADD_CHK_SHIFT      (12U)
#define MSCM_ENEDC_AXBS_CORE0_ADD_CHK_WIDTH      (1U)
#define MSCM_ENEDC_AXBS_CORE0_ADD_CHK(x)         (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE0_ADD_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE0_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE0_WR_CHK_MASK        (0x2000U)
#define MSCM_ENEDC_AXBS_CORE0_WR_CHK_SHIFT       (13U)
#define MSCM_ENEDC_AXBS_CORE0_WR_CHK_WIDTH       (1U)
#define MSCM_ENEDC_AXBS_CORE0_WR_CHK(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE0_WR_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE0_WR_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE1_ADD_CHK_MASK       (0x4000U)
#define MSCM_ENEDC_AXBS_CORE1_ADD_CHK_SHIFT      (14U)
#define MSCM_ENEDC_AXBS_CORE1_ADD_CHK_WIDTH      (1U)
#define MSCM_ENEDC_AXBS_CORE1_ADD_CHK(x)         (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE1_ADD_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE1_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE1_WR_CHK_MASK        (0x8000U)
#define MSCM_ENEDC_AXBS_CORE1_WR_CHK_SHIFT       (15U)
#define MSCM_ENEDC_AXBS_CORE1_WR_CHK_WIDTH       (1U)
#define MSCM_ENEDC_AXBS_CORE1_WR_CHK(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE1_WR_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE1_WR_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE2_ADD_CHK_MASK       (0x10000U)
#define MSCM_ENEDC_AXBS_CORE2_ADD_CHK_SHIFT      (16U)
#define MSCM_ENEDC_AXBS_CORE2_ADD_CHK_WIDTH      (1U)
#define MSCM_ENEDC_AXBS_CORE2_ADD_CHK(x)         (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE2_ADD_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE2_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE2_WR_CHK_MASK        (0x20000U)
#define MSCM_ENEDC_AXBS_CORE2_WR_CHK_SHIFT       (17U)
#define MSCM_ENEDC_AXBS_CORE2_WR_CHK_WIDTH       (1U)
#define MSCM_ENEDC_AXBS_CORE2_WR_CHK(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE2_WR_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE2_WR_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE3_ADD_CHK_MASK       (0x40000U)
#define MSCM_ENEDC_AXBS_CORE3_ADD_CHK_SHIFT      (18U)
#define MSCM_ENEDC_AXBS_CORE3_ADD_CHK_WIDTH      (1U)
#define MSCM_ENEDC_AXBS_CORE3_ADD_CHK(x)         (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE3_ADD_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE3_ADD_CHK_MASK)

#define MSCM_ENEDC_AXBS_CORE3_WR_CHK_MASK        (0x80000U)
#define MSCM_ENEDC_AXBS_CORE3_WR_CHK_SHIFT       (19U)
#define MSCM_ENEDC_AXBS_CORE3_WR_CHK_WIDTH       (1U)
#define MSCM_ENEDC_AXBS_CORE3_WR_CHK(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_AXBS_CORE3_WR_CHK_SHIFT)) & MSCM_ENEDC_AXBS_CORE3_WR_CHK_MASK)

#define MSCM_ENEDC_DSPV_SLV_ADD_CHK_MASK         (0x100000U)
#define MSCM_ENEDC_DSPV_SLV_ADD_CHK_SHIFT        (20U)
#define MSCM_ENEDC_DSPV_SLV_ADD_CHK_WIDTH        (1U)
#define MSCM_ENEDC_DSPV_SLV_ADD_CHK(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_DSPV_SLV_ADD_CHK_SHIFT)) & MSCM_ENEDC_DSPV_SLV_ADD_CHK_MASK)

#define MSCM_ENEDC_DSPV_SLV_WR_CHK_MASK          (0x200000U)
#define MSCM_ENEDC_DSPV_SLV_WR_CHK_SHIFT         (21U)
#define MSCM_ENEDC_DSPV_SLV_WR_CHK_WIDTH         (1U)
#define MSCM_ENEDC_DSPV_SLV_WR_CHK(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_DSPV_SLV_WR_CHK_SHIFT)) & MSCM_ENEDC_DSPV_SLV_WR_CHK_MASK)

#define MSCM_ENEDC_LPE_SLV_ADD_CHK_MASK          (0x400000U)
#define MSCM_ENEDC_LPE_SLV_ADD_CHK_SHIFT         (22U)
#define MSCM_ENEDC_LPE_SLV_ADD_CHK_WIDTH         (1U)
#define MSCM_ENEDC_LPE_SLV_ADD_CHK(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_SLV_ADD_CHK_SHIFT)) & MSCM_ENEDC_LPE_SLV_ADD_CHK_MASK)

#define MSCM_ENEDC_LPE_SLV_WR_CHK_MASK           (0x800000U)
#define MSCM_ENEDC_LPE_SLV_WR_CHK_SHIFT          (23U)
#define MSCM_ENEDC_LPE_SLV_WR_CHK_WIDTH          (1U)
#define MSCM_ENEDC_LPE_SLV_WR_CHK(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_SLV_WR_CHK_SHIFT)) & MSCM_ENEDC_LPE_SLV_WR_CHK_MASK)

#define MSCM_ENEDC_LPE_S1_ADD_CHK_MASK           (0x1000000U)
#define MSCM_ENEDC_LPE_S1_ADD_CHK_SHIFT          (24U)
#define MSCM_ENEDC_LPE_S1_ADD_CHK_WIDTH          (1U)
#define MSCM_ENEDC_LPE_S1_ADD_CHK(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_S1_ADD_CHK_SHIFT)) & MSCM_ENEDC_LPE_S1_ADD_CHK_MASK)

#define MSCM_ENEDC_LPE_S1_WR_CHK_MASK            (0x2000000U)
#define MSCM_ENEDC_LPE_S1_WR_CHK_SHIFT           (25U)
#define MSCM_ENEDC_LPE_S1_WR_CHK_WIDTH           (1U)
#define MSCM_ENEDC_LPE_S1_WR_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_S1_WR_CHK_SHIFT)) & MSCM_ENEDC_LPE_S1_WR_CHK_MASK)

#define MSCM_ENEDC_LPE_S0_ADD_CHK_MASK           (0x4000000U)
#define MSCM_ENEDC_LPE_S0_ADD_CHK_SHIFT          (26U)
#define MSCM_ENEDC_LPE_S0_ADD_CHK_WIDTH          (1U)
#define MSCM_ENEDC_LPE_S0_ADD_CHK(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_S0_ADD_CHK_SHIFT)) & MSCM_ENEDC_LPE_S0_ADD_CHK_MASK)

#define MSCM_ENEDC_LPE_S0_WR_CHK_MASK            (0x8000000U)
#define MSCM_ENEDC_LPE_S0_WR_CHK_SHIFT           (27U)
#define MSCM_ENEDC_LPE_S0_WR_CHK_WIDTH           (1U)
#define MSCM_ENEDC_LPE_S0_WR_CHK(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LPE_S0_WR_CHK_SHIFT)) & MSCM_ENEDC_LPE_S0_WR_CHK_MASK)

#define MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK_MASK      (0x10000000U)
#define MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK_SHIFT     (28U)
#define MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK_WIDTH     (1U)
#define MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK(x)        (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK_SHIFT)) & MSCM_ENEDC_LMEM_BKD_S2_ADD_CHK_MASK)

#define MSCM_ENEDC_LMEM_BKD_S2_WR_CHK_MASK       (0x20000000U)
#define MSCM_ENEDC_LMEM_BKD_S2_WR_CHK_SHIFT      (29U)
#define MSCM_ENEDC_LMEM_BKD_S2_WR_CHK_WIDTH      (1U)
#define MSCM_ENEDC_LMEM_BKD_S2_WR_CHK(x)         (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC_LMEM_BKD_S2_WR_CHK_SHIFT)) & MSCM_ENEDC_LMEM_BKD_S2_WR_CHK_MASK)
/*! @} */

/*! @name ENEDC1 - Enable Interconnect Error Detection */
/*! @{ */

#define MSCM_ENEDC1_CM7_0_AHBP_MASK              (0x1U)
#define MSCM_ENEDC1_CM7_0_AHBP_SHIFT             (0U)
#define MSCM_ENEDC1_CM7_0_AHBP_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_0_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_0_AHBP_SHIFT)) & MSCM_ENEDC1_CM7_0_AHBP_MASK)

#define MSCM_ENEDC1_CM7_1_AHBP_MASK              (0x2U)
#define MSCM_ENEDC1_CM7_1_AHBP_SHIFT             (1U)
#define MSCM_ENEDC1_CM7_1_AHBP_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_1_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_1_AHBP_SHIFT)) & MSCM_ENEDC1_CM7_1_AHBP_MASK)

#define MSCM_ENEDC1_CM7_2_AHBP_MASK              (0x4U)
#define MSCM_ENEDC1_CM7_2_AHBP_SHIFT             (2U)
#define MSCM_ENEDC1_CM7_2_AHBP_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_2_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_2_AHBP_SHIFT)) & MSCM_ENEDC1_CM7_2_AHBP_MASK)

#define MSCM_ENEDC1_CM7_3_AHBP_MASK              (0x8U)
#define MSCM_ENEDC1_CM7_3_AHBP_SHIFT             (3U)
#define MSCM_ENEDC1_CM7_3_AHBP_WIDTH             (1U)
#define MSCM_ENEDC1_CM7_3_AHBP(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_CM7_3_AHBP_SHIFT)) & MSCM_ENEDC1_CM7_3_AHBP_MASK)

#define MSCM_ENEDC1_ACE_M0_MASK                  (0x10U)
#define MSCM_ENEDC1_ACE_M0_SHIFT                 (4U)
#define MSCM_ENEDC1_ACE_M0_WIDTH                 (1U)
#define MSCM_ENEDC1_ACE_M0(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_ACE_M0_SHIFT)) & MSCM_ENEDC1_ACE_M0_MASK)

#define MSCM_ENEDC1_ACE_M1_MASK                  (0x20U)
#define MSCM_ENEDC1_ACE_M1_SHIFT                 (5U)
#define MSCM_ENEDC1_ACE_M1_WIDTH                 (1U)
#define MSCM_ENEDC1_ACE_M1(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_ACE_M1_SHIFT)) & MSCM_ENEDC1_ACE_M1_MASK)

#define MSCM_ENEDC1_AXI_ACC_PORT_MASK            (0x40U)
#define MSCM_ENEDC1_AXI_ACC_PORT_SHIFT           (6U)
#define MSCM_ENEDC1_AXI_ACC_PORT_WIDTH           (1U)
#define MSCM_ENEDC1_AXI_ACC_PORT(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_AXI_ACC_PORT_SHIFT)) & MSCM_ENEDC1_AXI_ACC_PORT_MASK)

#define MSCM_ENEDC1_HSE2_MASK                    (0x80U)
#define MSCM_ENEDC1_HSE2_SHIFT                   (7U)
#define MSCM_ENEDC1_HSE2_WIDTH                   (1U)
#define MSCM_ENEDC1_HSE2(x)                      (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_HSE2_SHIFT)) & MSCM_ENEDC1_HSE2_MASK)

#define MSCM_ENEDC1_DSPV_MASTER_MASK             (0x100U)
#define MSCM_ENEDC1_DSPV_MASTER_SHIFT            (8U)
#define MSCM_ENEDC1_DSPV_MASTER_WIDTH            (1U)
#define MSCM_ENEDC1_DSPV_MASTER(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_DSPV_MASTER_SHIFT)) & MSCM_ENEDC1_DSPV_MASTER_MASK)

#define MSCM_ENEDC1_TCM_AXBS_MASK                (0x200U)
#define MSCM_ENEDC1_TCM_AXBS_SHIFT               (9U)
#define MSCM_ENEDC1_TCM_AXBS_WIDTH               (1U)
#define MSCM_ENEDC1_TCM_AXBS(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_TCM_AXBS_SHIFT)) & MSCM_ENEDC1_TCM_AXBS_MASK)

#define MSCM_ENEDC1_LPE_MASTER_MASK              (0x400U)
#define MSCM_ENEDC1_LPE_MASTER_SHIFT             (10U)
#define MSCM_ENEDC1_LPE_MASTER_WIDTH             (1U)
#define MSCM_ENEDC1_LPE_MASTER(x)                (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_LPE_MASTER_SHIFT)) & MSCM_ENEDC1_LPE_MASTER_MASK)

#define MSCM_ENEDC1_LPE_M0_MASK                  (0x800U)
#define MSCM_ENEDC1_LPE_M0_SHIFT                 (11U)
#define MSCM_ENEDC1_LPE_M0_WIDTH                 (1U)
#define MSCM_ENEDC1_LPE_M0(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_LPE_M0_SHIFT)) & MSCM_ENEDC1_LPE_M0_MASK)

#define MSCM_ENEDC1_LMEM_C_MASK                  (0x1000U)
#define MSCM_ENEDC1_LMEM_C_SHIFT                 (12U)
#define MSCM_ENEDC1_LMEM_C_WIDTH                 (1U)
#define MSCM_ENEDC1_LMEM_C(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_LMEM_C_SHIFT)) & MSCM_ENEDC1_LMEM_C_MASK)

#define MSCM_ENEDC1_LMEM_S_MASK                  (0x2000U)
#define MSCM_ENEDC1_LMEM_S_SHIFT                 (13U)
#define MSCM_ENEDC1_LMEM_S_WIDTH                 (1U)
#define MSCM_ENEDC1_LMEM_S(x)                    (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_LMEM_S_SHIFT)) & MSCM_ENEDC1_LMEM_S_MASK)

#define MSCM_ENEDC1_LPE_DMA_MASK                 (0x4000U)
#define MSCM_ENEDC1_LPE_DMA_SHIFT                (14U)
#define MSCM_ENEDC1_LPE_DMA_WIDTH                (1U)
#define MSCM_ENEDC1_LPE_DMA(x)                   (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_LPE_DMA_SHIFT)) & MSCM_ENEDC1_LPE_DMA_MASK)

#define MSCM_ENEDC1_PERIPH_AXBS_MASK             (0x8000U)
#define MSCM_ENEDC1_PERIPH_AXBS_SHIFT            (15U)
#define MSCM_ENEDC1_PERIPH_AXBS_WIDTH            (1U)
#define MSCM_ENEDC1_PERIPH_AXBS(x)               (((uint32_t)(((uint32_t)(x)) << MSCM_ENEDC1_PERIPH_AXBS_SHIFT)) & MSCM_ENEDC1_PERIPH_AXBS_MASK)
/*! @} */

/*! @name IAHBCFGREG - AHB Gasket Configuration */
/*! @{ */

#define MSCM_IAHBCFGREG_CM7_0_AHBP_MASK          (0x1U)
#define MSCM_IAHBCFGREG_CM7_0_AHBP_SHIFT         (0U)
#define MSCM_IAHBCFGREG_CM7_0_AHBP_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CM7_0_AHBP(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_0_AHBP_SHIFT)) & MSCM_IAHBCFGREG_CM7_0_AHBP_MASK)

#define MSCM_IAHBCFGREG_CM7_1_AHBP_MASK          (0x2U)
#define MSCM_IAHBCFGREG_CM7_1_AHBP_SHIFT         (1U)
#define MSCM_IAHBCFGREG_CM7_1_AHBP_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CM7_1_AHBP(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_1_AHBP_SHIFT)) & MSCM_IAHBCFGREG_CM7_1_AHBP_MASK)

#define MSCM_IAHBCFGREG_CM7_2_AHBP_MASK          (0x4U)
#define MSCM_IAHBCFGREG_CM7_2_AHBP_SHIFT         (2U)
#define MSCM_IAHBCFGREG_CM7_2_AHBP_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CM7_2_AHBP(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_2_AHBP_SHIFT)) & MSCM_IAHBCFGREG_CM7_2_AHBP_MASK)

#define MSCM_IAHBCFGREG_CM7_3_AHBP_MASK          (0x8U)
#define MSCM_IAHBCFGREG_CM7_3_AHBP_SHIFT         (3U)
#define MSCM_IAHBCFGREG_CM7_3_AHBP_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CM7_3_AHBP(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CM7_3_AHBP_SHIFT)) & MSCM_IAHBCFGREG_CM7_3_AHBP_MASK)

#define MSCM_IAHBCFGREG_PBR1_DIS_OPT_MASK        (0x10U)
#define MSCM_IAHBCFGREG_PBR1_DIS_OPT_SHIFT       (4U)
#define MSCM_IAHBCFGREG_PBR1_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_PBR1_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PBR1_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_PBR1_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_PBR2_DIS_OPT_MASK        (0x20U)
#define MSCM_IAHBCFGREG_PBR2_DIS_OPT_SHIFT       (5U)
#define MSCM_IAHBCFGREG_PBR2_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_PBR2_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PBR2_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_PBR2_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_PBR3_DIS_OPT_MASK        (0x40U)
#define MSCM_IAHBCFGREG_PBR3_DIS_OPT_SHIFT       (6U)
#define MSCM_IAHBCFGREG_PBR3_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_PBR3_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PBR3_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_PBR3_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_PBR4_DIS_OPT_MASK        (0x80U)
#define MSCM_IAHBCFGREG_PBR4_DIS_OPT_SHIFT       (7U)
#define MSCM_IAHBCFGREG_PBR4_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_PBR4_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PBR4_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_PBR4_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_PBR5_DIS_OPT_MASK        (0x100U)
#define MSCM_IAHBCFGREG_PBR5_DIS_OPT_SHIFT       (8U)
#define MSCM_IAHBCFGREG_PBR5_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_PBR5_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PBR5_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_PBR5_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0_MASK (0x200U)
#define MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0_SHIFT (9U)
#define MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0_WIDTH (1U)
#define MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0(x)   (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0_SHIFT)) & MSCM_IAHBCFGREG_PERIPH_TO_AXBS_AUX0_MASK)

#define MSCM_IAHBCFGREG_CORE0_AHBS_MASK          (0x400U)
#define MSCM_IAHBCFGREG_CORE0_AHBS_SHIFT         (10U)
#define MSCM_IAHBCFGREG_CORE0_AHBS_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CORE0_AHBS(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CORE0_AHBS_SHIFT)) & MSCM_IAHBCFGREG_CORE0_AHBS_MASK)

#define MSCM_IAHBCFGREG_CORE1_AHBS_MASK          (0x800U)
#define MSCM_IAHBCFGREG_CORE1_AHBS_SHIFT         (11U)
#define MSCM_IAHBCFGREG_CORE1_AHBS_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CORE1_AHBS(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CORE1_AHBS_SHIFT)) & MSCM_IAHBCFGREG_CORE1_AHBS_MASK)

#define MSCM_IAHBCFGREG_CORE2_AHBS_MASK          (0x1000U)
#define MSCM_IAHBCFGREG_CORE2_AHBS_SHIFT         (12U)
#define MSCM_IAHBCFGREG_CORE2_AHBS_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CORE2_AHBS(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CORE2_AHBS_SHIFT)) & MSCM_IAHBCFGREG_CORE2_AHBS_MASK)

#define MSCM_IAHBCFGREG_CORE3_AHBS_MASK          (0x2000U)
#define MSCM_IAHBCFGREG_CORE3_AHBS_SHIFT         (13U)
#define MSCM_IAHBCFGREG_CORE3_AHBS_WIDTH         (1U)
#define MSCM_IAHBCFGREG_CORE3_AHBS(x)            (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_CORE3_AHBS_SHIFT)) & MSCM_IAHBCFGREG_CORE3_AHBS_MASK)

#define MSCM_IAHBCFGREG_NIC_TO_PER_XBAR_MASK     (0x4000U)
#define MSCM_IAHBCFGREG_NIC_TO_PER_XBAR_SHIFT    (14U)
#define MSCM_IAHBCFGREG_NIC_TO_PER_XBAR_WIDTH    (1U)
#define MSCM_IAHBCFGREG_NIC_TO_PER_XBAR(x)       (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_NIC_TO_PER_XBAR_SHIFT)) & MSCM_IAHBCFGREG_NIC_TO_PER_XBAR_MASK)

#define MSCM_IAHBCFGREG_XSPI_DIS_OPT_MASK        (0x8000U)
#define MSCM_IAHBCFGREG_XSPI_DIS_OPT_SHIFT       (15U)
#define MSCM_IAHBCFGREG_XSPI_DIS_OPT_WIDTH       (1U)
#define MSCM_IAHBCFGREG_XSPI_DIS_OPT(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_XSPI_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_XSPI_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_LPE_DIS_OPT_MASK         (0x10000U)
#define MSCM_IAHBCFGREG_LPE_DIS_OPT_SHIFT        (16U)
#define MSCM_IAHBCFGREG_LPE_DIS_OPT_WIDTH        (1U)
#define MSCM_IAHBCFGREG_LPE_DIS_OPT(x)           (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_LPE_DIS_OPT_SHIFT)) & MSCM_IAHBCFGREG_LPE_DIS_OPT_MASK)

#define MSCM_IAHBCFGREG_DSPV_MSTR_MASK           (0x20000U)
#define MSCM_IAHBCFGREG_DSPV_MSTR_SHIFT          (17U)
#define MSCM_IAHBCFGREG_DSPV_MSTR_WIDTH          (1U)
#define MSCM_IAHBCFGREG_DSPV_MSTR(x)             (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DSPV_MSTR_SHIFT)) & MSCM_IAHBCFGREG_DSPV_MSTR_MASK)

#define MSCM_IAHBCFGREG_DSPV_SLV_MASK            (0x40000U)
#define MSCM_IAHBCFGREG_DSPV_SLV_SHIFT           (18U)
#define MSCM_IAHBCFGREG_DSPV_SLV_WIDTH           (1U)
#define MSCM_IAHBCFGREG_DSPV_SLV(x)              (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_DSPV_SLV_SHIFT)) & MSCM_IAHBCFGREG_DSPV_SLV_MASK)

#define MSCM_IAHBCFGREG_HSE2_MASK                (0x80000U)
#define MSCM_IAHBCFGREG_HSE2_SHIFT               (19U)
#define MSCM_IAHBCFGREG_HSE2_WIDTH               (1U)
#define MSCM_IAHBCFGREG_HSE2(x)                  (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_HSE2_SHIFT)) & MSCM_IAHBCFGREG_HSE2_MASK)

#define MSCM_IAHBCFGREG_ACE_ACCEL_M0_MASK        (0x100000U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M0_SHIFT       (20U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M0_WIDTH       (1U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M0(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_ACE_ACCEL_M0_SHIFT)) & MSCM_IAHBCFGREG_ACE_ACCEL_M0_MASK)

#define MSCM_IAHBCFGREG_ACE_ACCEL_M1_MASK        (0x200000U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M1_SHIFT       (21U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M1_WIDTH       (1U)
#define MSCM_IAHBCFGREG_ACE_ACCEL_M1(x)          (((uint32_t)(((uint32_t)(x)) << MSCM_IAHBCFGREG_ACE_ACCEL_M1_SHIFT)) & MSCM_IAHBCFGREG_ACE_ACCEL_M1_MASK)
/*! @} */

/*! @name IRSPRC_CM_DSPV - Interrupt Router Shared Peripheral Control for the Cortex-M7, Cortex-M4, and DSPV Cores */
/*! @{ */

#define MSCM_IRSPRC_CM_DSPV_M7_0_MASK            (0x1U)
#define MSCM_IRSPRC_CM_DSPV_M7_0_SHIFT           (0U)
#define MSCM_IRSPRC_CM_DSPV_M7_0_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_M7_0(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_M7_0_SHIFT)) & MSCM_IRSPRC_CM_DSPV_M7_0_MASK)

#define MSCM_IRSPRC_CM_DSPV_M7_1_MASK            (0x2U)
#define MSCM_IRSPRC_CM_DSPV_M7_1_SHIFT           (1U)
#define MSCM_IRSPRC_CM_DSPV_M7_1_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_M7_1(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_M7_1_SHIFT)) & MSCM_IRSPRC_CM_DSPV_M7_1_MASK)

#define MSCM_IRSPRC_CM_DSPV_M7_2_MASK            (0x4U)
#define MSCM_IRSPRC_CM_DSPV_M7_2_SHIFT           (2U)
#define MSCM_IRSPRC_CM_DSPV_M7_2_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_M7_2(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_M7_2_SHIFT)) & MSCM_IRSPRC_CM_DSPV_M7_2_MASK)

#define MSCM_IRSPRC_CM_DSPV_M7_3_MASK            (0x8U)
#define MSCM_IRSPRC_CM_DSPV_M7_3_SHIFT           (3U)
#define MSCM_IRSPRC_CM_DSPV_M7_3_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_M7_3(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_M7_3_SHIFT)) & MSCM_IRSPRC_CM_DSPV_M7_3_MASK)

#define MSCM_IRSPRC_CM_DSPV_LPE_CORE_MASK        (0x10U)
#define MSCM_IRSPRC_CM_DSPV_LPE_CORE_SHIFT       (4U)
#define MSCM_IRSPRC_CM_DSPV_LPE_CORE_WIDTH       (1U)
#define MSCM_IRSPRC_CM_DSPV_LPE_CORE(x)          (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_LPE_CORE_SHIFT)) & MSCM_IRSPRC_CM_DSPV_LPE_CORE_MASK)

#define MSCM_IRSPRC_CM_DSPV_DSPV_MASK            (0x20U)
#define MSCM_IRSPRC_CM_DSPV_DSPV_SHIFT           (5U)
#define MSCM_IRSPRC_CM_DSPV_DSPV_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_DSPV(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_DSPV_SHIFT)) & MSCM_IRSPRC_CM_DSPV_DSPV_MASK)

#define MSCM_IRSPRC_CM_DSPV_LOCK_MASK            (0x8000U)
#define MSCM_IRSPRC_CM_DSPV_LOCK_SHIFT           (15U)
#define MSCM_IRSPRC_CM_DSPV_LOCK_WIDTH           (1U)
#define MSCM_IRSPRC_CM_DSPV_LOCK(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CM_DSPV_LOCK_SHIFT)) & MSCM_IRSPRC_CM_DSPV_LOCK_MASK)
/*! @} */

/*! @name IRSPRC_CPE - Interrupt Router Shared Peripheral Routing Control for CPE Cores */
/*! @{ */

#define MSCM_IRSPRC_CPE_CPE_CORE_MASK            (0x1U)
#define MSCM_IRSPRC_CPE_CPE_CORE_SHIFT           (0U)
#define MSCM_IRSPRC_CPE_CPE_CORE_WIDTH           (1U)
#define MSCM_IRSPRC_CPE_CPE_CORE(x)              (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CPE_CPE_CORE_SHIFT)) & MSCM_IRSPRC_CPE_CPE_CORE_MASK)

#define MSCM_IRSPRC_CPE_LOCK_MASK                (0x8000U)
#define MSCM_IRSPRC_CPE_LOCK_SHIFT               (15U)
#define MSCM_IRSPRC_CPE_LOCK_WIDTH               (1U)
#define MSCM_IRSPRC_CPE_LOCK(x)                  (((uint16_t)(((uint16_t)(x)) << MSCM_IRSPRC_CPE_LOCK_SHIFT)) & MSCM_IRSPRC_CPE_LOCK_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group MSCM_Register_Masks */

/*!
 * @}
 */ /* end of group MSCM_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_MSCM_H_) */
