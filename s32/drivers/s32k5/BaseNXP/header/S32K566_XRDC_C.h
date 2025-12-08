/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_XRDC_C.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_XRDC_C
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
#if !defined(S32K566_XRDC_C_H_)  /* Check if memory map has not been already included */
#define S32K566_XRDC_C_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XRDC_C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_C_Peripheral_Access_Layer XRDC_C Peripheral Access Layer
 * @{
 */

/** XRDC_C - Size of Registers Arrays */
#define XRDC_C_MDAC_COUNT                         1u
#define XRDC_C_MRC_COUNT                          1u
#define XRDC_C_DERRLOC_COUNT                      16u
#define XRDC_C_DERRW0_COUNT                       23u
#define XRDC_C_PDACN0_COUNT                       59u
#define XRDC_C_PDACN1_COUNT                       61u
#define XRDC_C_PDACN2_COUNT                       64u
#define XRDC_C_PDACN3_COUNT                       62u
#define XRDC_C_MRCN_COUNT                         1u
#define XRDC_C_MRCN_MRGDN_COUNT                   4u
#define XRDC_C_PDACN4_COUNT                       54u
#define XRDC_C_PDACN5_COUNT                       60u
#define XRDC_C_PDACN6_COUNT                       53u

/** XRDC_C - Register Layout Typedef */
typedef struct XRDC_C_Struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  __I  uint32_t HWCFG2;                            /**< Hardware Configuration 2, offset: 0xF8 */
  uint8_t RESERVED_1[4];
  __I  uint8_t MDACFG[XRDC_C_MDAC_COUNT];          /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
  uint8_t RESERVED_2[63];
  __I  uint8_t MRCFG[XRDC_C_MRC_COUNT];            /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
  uint8_t RESERVED_3[191];
  __I  uint32_t DERRLOC[XRDC_C_DERRLOC_COUNT];     /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[448];
  struct XRDC_C_DERRW0 {                           /* offset: 0x400, array step: 0x10 */
    __I  uint32_t DERR_W0;                           /**< Domain Error Word 0, array offset: 0x400, array step: 0x10, valid indices: [0, 16-22] */
    __I  uint32_t DERR_W1;                           /**< Domain Error Word 1, array offset: 0x404, array step: 0x10, valid indices: [0, 16-22] */
    uint8_t RESERVED_0[4];
    __IO uint32_t DERR_W3;                           /**< Domain Error Word 3, array offset: 0x40C, array step: 0x10, valid indices: [0, 16-22] */
  } DERRW0[XRDC_C_DERRW0_COUNT];
  uint8_t RESERVED_5[656];
  __IO uint32_t MDA_W0_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x800 */
  __IO uint32_t MDA_W1_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x804 */
  __IO uint32_t MDA_W2_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x808 */
  __IO uint32_t MDA_W3_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x80C */
  uint8_t RESERVED_6[2032];
  struct XRDC_C_PDACN0 {                           /* offset: 0x1000, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1000, array step: 0x8, valid indices: [58] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1004, array step: 0x8, valid indices: [58] */
  } PDACN0[XRDC_C_PDACN0_COUNT];
  uint8_t RESERVED_7[552];
  struct XRDC_C_PDACN1 {                           /* offset: 0x1400, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1400, array step: 0x8, valid indices: [0-32, 36-47, 50-57, 59-60] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1404, array step: 0x8, valid indices: [0-32, 36-47, 50-57, 59-60] */
  } PDACN1[XRDC_C_PDACN1_COUNT];
  uint8_t RESERVED_8[536];
  struct XRDC_C_PDACN2 {                           /* offset: 0x1800, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1800, array step: 0x8, valid indices: [35, 48-49, 63] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1804, array step: 0x8, valid indices: [35, 48-49, 63] */
  } PDACN2[XRDC_C_PDACN2_COUNT];
  uint8_t RESERVED_9[512];
  struct XRDC_C_PDACN3 {                           /* offset: 0x1C00, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1C00, array step: 0x8, valid indices: [3-35, 38-46, 49-50, 59-61] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1C04, array step: 0x8, valid indices: [3-35, 38-46, 49-50, 59-61] */
  } PDACN3[XRDC_C_PDACN3_COUNT];
  uint8_t RESERVED_10[528];
  struct XRDC_C_MRGDN {                            /* offset: 0x2000, array step: index*0x80, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W0;                      /**< Memory Region Descriptor Word 0, array offset: 0x2000, array step: index*0x80, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W1;                      /**< Memory Region Descriptor Word 1, array offset: 0x2004, array step: index*0x80, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W2;                      /**< Memory Region Descriptor Word 2, array offset: 0x2008, array step: index*0x80, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W3;                      /**< Memory Region Descriptor Word 3, array offset: 0x200C, array step: index*0x80, index2*0x20 */
    uint8_t RESERVED_0[16];
  } MRGDN[XRDC_C_MRCN_COUNT][XRDC_C_MRCN_MRGDN_COUNT];
  uint8_t RESERVED_11[8064];
  struct XRDC_C_PDACN4 {                           /* offset: 0x4000, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x4000, array step: 0x8, valid indices: [0, 36, 47-48, 51-53] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x4004, array step: 0x8, valid indices: [0, 36, 47-48, 51-53] */
  } PDACN4[XRDC_C_PDACN4_COUNT];
  uint8_t RESERVED_12[592];
  struct XRDC_C_PDACN5 {                           /* offset: 0x4400, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x4400, array step: 0x8, valid indices: [0-32, 35-44, 46, 58-59] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x4404, array step: 0x8, valid indices: [0-32, 35-44, 46, 58-59] */
  } PDACN5[XRDC_C_PDACN5_COUNT];
  uint8_t RESERVED_13[544];
  struct XRDC_C_PDACN6 {                           /* offset: 0x4800, array step: 0x8 */
    __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x4800, array step: 0x8, valid indices: [45, 49-52] */
    __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x4804, array step: 0x8, valid indices: [45, 49-52] */
  } PDACN6[XRDC_C_PDACN6_COUNT];
} XRDC_C_Type, *XRDC_C_MemMapPtr;

/** Number of instances of the XRDC_C module. */
#define XRDC_C_INSTANCE_COUNT                    (1u)

/* XRDC_C - Peripheral instance base addresses */
/** Peripheral XRDC_C base address */
#define IP_XRDC_C_BASE                           (0x40BB8000u)
/** Peripheral XRDC_C base pointer */
#define IP_XRDC_C                                ((XRDC_C_Type *)IP_XRDC_C_BASE)
/** Array initializer of XRDC_C peripheral base addresses */
#define IP_XRDC_C_BASE_ADDRS                     { IP_XRDC_C_BASE }
/** Array initializer of XRDC_C peripheral base pointers */
#define IP_XRDC_C_BASE_PTRS                      { IP_XRDC_C }

/* ----------------------------------------------------------------------------
   -- XRDC_C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_C_Register_Masks XRDC_C Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define XRDC_C_CR_GVLD_MASK                      (0x1U)
#define XRDC_C_CR_GVLD_SHIFT                     (0U)
#define XRDC_C_CR_GVLD_WIDTH                     (1U)
#define XRDC_C_CR_GVLD(x)                        (((uint32_t)(((uint32_t)(x)) << XRDC_C_CR_GVLD_SHIFT)) & XRDC_C_CR_GVLD_MASK)

#define XRDC_C_CR_HRL_MASK                       (0x1EU)
#define XRDC_C_CR_HRL_SHIFT                      (1U)
#define XRDC_C_CR_HRL_WIDTH                      (4U)
#define XRDC_C_CR_HRL(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_C_CR_HRL_SHIFT)) & XRDC_C_CR_HRL_MASK)

#define XRDC_C_CR_MRF_MASK                       (0x80U)
#define XRDC_C_CR_MRF_SHIFT                      (7U)
#define XRDC_C_CR_MRF_WIDTH                      (1U)
#define XRDC_C_CR_MRF(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_C_CR_MRF_SHIFT)) & XRDC_C_CR_MRF_MASK)

#define XRDC_C_CR_VAW_MASK                       (0x100U)
#define XRDC_C_CR_VAW_SHIFT                      (8U)
#define XRDC_C_CR_VAW_WIDTH                      (1U)
#define XRDC_C_CR_VAW(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_C_CR_VAW_SHIFT)) & XRDC_C_CR_VAW_MASK)

#define XRDC_C_CR_LK1_MASK                       (0x40000000U)
#define XRDC_C_CR_LK1_SHIFT                      (30U)
#define XRDC_C_CR_LK1_WIDTH                      (1U)
#define XRDC_C_CR_LK1(x)                         (((uint32_t)(((uint32_t)(x)) << XRDC_C_CR_LK1_SHIFT)) & XRDC_C_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define XRDC_C_HWCFG0_NDID_MASK                  (0xFFU)
#define XRDC_C_HWCFG0_NDID_SHIFT                 (0U)
#define XRDC_C_HWCFG0_NDID_WIDTH                 (8U)
#define XRDC_C_HWCFG0_NDID(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG0_NDID_SHIFT)) & XRDC_C_HWCFG0_NDID_MASK)

#define XRDC_C_HWCFG0_NMSTR_MASK                 (0xFF00U)
#define XRDC_C_HWCFG0_NMSTR_SHIFT                (8U)
#define XRDC_C_HWCFG0_NMSTR_WIDTH                (8U)
#define XRDC_C_HWCFG0_NMSTR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG0_NMSTR_SHIFT)) & XRDC_C_HWCFG0_NMSTR_MASK)

#define XRDC_C_HWCFG0_NMRC_MASK                  (0xFF0000U)
#define XRDC_C_HWCFG0_NMRC_SHIFT                 (16U)
#define XRDC_C_HWCFG0_NMRC_WIDTH                 (8U)
#define XRDC_C_HWCFG0_NMRC(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG0_NMRC_SHIFT)) & XRDC_C_HWCFG0_NMRC_MASK)

#define XRDC_C_HWCFG0_NPAC_MASK                  (0xF000000U)
#define XRDC_C_HWCFG0_NPAC_SHIFT                 (24U)
#define XRDC_C_HWCFG0_NPAC_WIDTH                 (4U)
#define XRDC_C_HWCFG0_NPAC(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG0_NPAC_SHIFT)) & XRDC_C_HWCFG0_NPAC_MASK)

#define XRDC_C_HWCFG0_MID_MASK                   (0xF0000000U)
#define XRDC_C_HWCFG0_MID_SHIFT                  (28U)
#define XRDC_C_HWCFG0_MID_WIDTH                  (4U)
#define XRDC_C_HWCFG0_MID(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG0_MID_SHIFT)) & XRDC_C_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define XRDC_C_HWCFG1_DID_MASK                   (0xFU)
#define XRDC_C_HWCFG1_DID_SHIFT                  (0U)
#define XRDC_C_HWCFG1_DID_WIDTH                  (4U)
#define XRDC_C_HWCFG1_DID(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG1_DID_SHIFT)) & XRDC_C_HWCFG1_DID_MASK)
/*! @} */

/*! @name HWCFG2 - Hardware Configuration 2 */
/*! @{ */

#define XRDC_C_HWCFG2_PIDP0_MASK                 (0x1U)
#define XRDC_C_HWCFG2_PIDP0_SHIFT                (0U)
#define XRDC_C_HWCFG2_PIDP0_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP0(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP0_SHIFT)) & XRDC_C_HWCFG2_PIDP0_MASK)

#define XRDC_C_HWCFG2_PIDP1_MASK                 (0x2U)
#define XRDC_C_HWCFG2_PIDP1_SHIFT                (1U)
#define XRDC_C_HWCFG2_PIDP1_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP1(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP1_SHIFT)) & XRDC_C_HWCFG2_PIDP1_MASK)

#define XRDC_C_HWCFG2_PIDP2_MASK                 (0x4U)
#define XRDC_C_HWCFG2_PIDP2_SHIFT                (2U)
#define XRDC_C_HWCFG2_PIDP2_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP2(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP2_SHIFT)) & XRDC_C_HWCFG2_PIDP2_MASK)

#define XRDC_C_HWCFG2_PIDP3_MASK                 (0x8U)
#define XRDC_C_HWCFG2_PIDP3_SHIFT                (3U)
#define XRDC_C_HWCFG2_PIDP3_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP3(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP3_SHIFT)) & XRDC_C_HWCFG2_PIDP3_MASK)

#define XRDC_C_HWCFG2_PIDP4_MASK                 (0x10U)
#define XRDC_C_HWCFG2_PIDP4_SHIFT                (4U)
#define XRDC_C_HWCFG2_PIDP4_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP4(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP4_SHIFT)) & XRDC_C_HWCFG2_PIDP4_MASK)

#define XRDC_C_HWCFG2_PIDP5_MASK                 (0x20U)
#define XRDC_C_HWCFG2_PIDP5_SHIFT                (5U)
#define XRDC_C_HWCFG2_PIDP5_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP5(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP5_SHIFT)) & XRDC_C_HWCFG2_PIDP5_MASK)

#define XRDC_C_HWCFG2_PIDP6_MASK                 (0x40U)
#define XRDC_C_HWCFG2_PIDP6_SHIFT                (6U)
#define XRDC_C_HWCFG2_PIDP6_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP6(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP6_SHIFT)) & XRDC_C_HWCFG2_PIDP6_MASK)

#define XRDC_C_HWCFG2_PIDP7_MASK                 (0x80U)
#define XRDC_C_HWCFG2_PIDP7_SHIFT                (7U)
#define XRDC_C_HWCFG2_PIDP7_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP7(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP7_SHIFT)) & XRDC_C_HWCFG2_PIDP7_MASK)

#define XRDC_C_HWCFG2_PIDP8_MASK                 (0x100U)
#define XRDC_C_HWCFG2_PIDP8_SHIFT                (8U)
#define XRDC_C_HWCFG2_PIDP8_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP8(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP8_SHIFT)) & XRDC_C_HWCFG2_PIDP8_MASK)

#define XRDC_C_HWCFG2_PIDP9_MASK                 (0x200U)
#define XRDC_C_HWCFG2_PIDP9_SHIFT                (9U)
#define XRDC_C_HWCFG2_PIDP9_WIDTH                (1U)
#define XRDC_C_HWCFG2_PIDP9(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP9_SHIFT)) & XRDC_C_HWCFG2_PIDP9_MASK)

#define XRDC_C_HWCFG2_PIDP10_MASK                (0x400U)
#define XRDC_C_HWCFG2_PIDP10_SHIFT               (10U)
#define XRDC_C_HWCFG2_PIDP10_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP10(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP10_SHIFT)) & XRDC_C_HWCFG2_PIDP10_MASK)

#define XRDC_C_HWCFG2_PIDP11_MASK                (0x800U)
#define XRDC_C_HWCFG2_PIDP11_SHIFT               (11U)
#define XRDC_C_HWCFG2_PIDP11_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP11(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP11_SHIFT)) & XRDC_C_HWCFG2_PIDP11_MASK)

#define XRDC_C_HWCFG2_PIDP12_MASK                (0x1000U)
#define XRDC_C_HWCFG2_PIDP12_SHIFT               (12U)
#define XRDC_C_HWCFG2_PIDP12_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP12(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP12_SHIFT)) & XRDC_C_HWCFG2_PIDP12_MASK)

#define XRDC_C_HWCFG2_PIDP13_MASK                (0x2000U)
#define XRDC_C_HWCFG2_PIDP13_SHIFT               (13U)
#define XRDC_C_HWCFG2_PIDP13_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP13(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP13_SHIFT)) & XRDC_C_HWCFG2_PIDP13_MASK)

#define XRDC_C_HWCFG2_PIDP14_MASK                (0x4000U)
#define XRDC_C_HWCFG2_PIDP14_SHIFT               (14U)
#define XRDC_C_HWCFG2_PIDP14_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP14(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP14_SHIFT)) & XRDC_C_HWCFG2_PIDP14_MASK)

#define XRDC_C_HWCFG2_PIDP15_MASK                (0x8000U)
#define XRDC_C_HWCFG2_PIDP15_SHIFT               (15U)
#define XRDC_C_HWCFG2_PIDP15_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP15(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP15_SHIFT)) & XRDC_C_HWCFG2_PIDP15_MASK)

#define XRDC_C_HWCFG2_PIDP16_MASK                (0x10000U)
#define XRDC_C_HWCFG2_PIDP16_SHIFT               (16U)
#define XRDC_C_HWCFG2_PIDP16_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP16(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP16_SHIFT)) & XRDC_C_HWCFG2_PIDP16_MASK)

#define XRDC_C_HWCFG2_PIDP17_MASK                (0x20000U)
#define XRDC_C_HWCFG2_PIDP17_SHIFT               (17U)
#define XRDC_C_HWCFG2_PIDP17_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP17(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP17_SHIFT)) & XRDC_C_HWCFG2_PIDP17_MASK)

#define XRDC_C_HWCFG2_PIDP18_MASK                (0x40000U)
#define XRDC_C_HWCFG2_PIDP18_SHIFT               (18U)
#define XRDC_C_HWCFG2_PIDP18_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP18(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP18_SHIFT)) & XRDC_C_HWCFG2_PIDP18_MASK)

#define XRDC_C_HWCFG2_PIDP19_MASK                (0x80000U)
#define XRDC_C_HWCFG2_PIDP19_SHIFT               (19U)
#define XRDC_C_HWCFG2_PIDP19_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP19(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP19_SHIFT)) & XRDC_C_HWCFG2_PIDP19_MASK)

#define XRDC_C_HWCFG2_PIDP20_MASK                (0x100000U)
#define XRDC_C_HWCFG2_PIDP20_SHIFT               (20U)
#define XRDC_C_HWCFG2_PIDP20_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP20(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP20_SHIFT)) & XRDC_C_HWCFG2_PIDP20_MASK)

#define XRDC_C_HWCFG2_PIDP21_MASK                (0x200000U)
#define XRDC_C_HWCFG2_PIDP21_SHIFT               (21U)
#define XRDC_C_HWCFG2_PIDP21_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP21(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP21_SHIFT)) & XRDC_C_HWCFG2_PIDP21_MASK)

#define XRDC_C_HWCFG2_PIDP22_MASK                (0x400000U)
#define XRDC_C_HWCFG2_PIDP22_SHIFT               (22U)
#define XRDC_C_HWCFG2_PIDP22_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP22(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP22_SHIFT)) & XRDC_C_HWCFG2_PIDP22_MASK)

#define XRDC_C_HWCFG2_PIDP23_MASK                (0x800000U)
#define XRDC_C_HWCFG2_PIDP23_SHIFT               (23U)
#define XRDC_C_HWCFG2_PIDP23_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP23(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP23_SHIFT)) & XRDC_C_HWCFG2_PIDP23_MASK)

#define XRDC_C_HWCFG2_PIDP24_MASK                (0x1000000U)
#define XRDC_C_HWCFG2_PIDP24_SHIFT               (24U)
#define XRDC_C_HWCFG2_PIDP24_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP24(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP24_SHIFT)) & XRDC_C_HWCFG2_PIDP24_MASK)

#define XRDC_C_HWCFG2_PIDP25_MASK                (0x2000000U)
#define XRDC_C_HWCFG2_PIDP25_SHIFT               (25U)
#define XRDC_C_HWCFG2_PIDP25_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP25(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP25_SHIFT)) & XRDC_C_HWCFG2_PIDP25_MASK)

#define XRDC_C_HWCFG2_PIDP26_MASK                (0x4000000U)
#define XRDC_C_HWCFG2_PIDP26_SHIFT               (26U)
#define XRDC_C_HWCFG2_PIDP26_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP26(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP26_SHIFT)) & XRDC_C_HWCFG2_PIDP26_MASK)

#define XRDC_C_HWCFG2_PIDP27_MASK                (0x8000000U)
#define XRDC_C_HWCFG2_PIDP27_SHIFT               (27U)
#define XRDC_C_HWCFG2_PIDP27_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP27(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP27_SHIFT)) & XRDC_C_HWCFG2_PIDP27_MASK)

#define XRDC_C_HWCFG2_PIDP28_MASK                (0x10000000U)
#define XRDC_C_HWCFG2_PIDP28_SHIFT               (28U)
#define XRDC_C_HWCFG2_PIDP28_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP28(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP28_SHIFT)) & XRDC_C_HWCFG2_PIDP28_MASK)

#define XRDC_C_HWCFG2_PIDP29_MASK                (0x20000000U)
#define XRDC_C_HWCFG2_PIDP29_SHIFT               (29U)
#define XRDC_C_HWCFG2_PIDP29_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP29(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP29_SHIFT)) & XRDC_C_HWCFG2_PIDP29_MASK)

#define XRDC_C_HWCFG2_PIDP30_MASK                (0x40000000U)
#define XRDC_C_HWCFG2_PIDP30_SHIFT               (30U)
#define XRDC_C_HWCFG2_PIDP30_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP30(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP30_SHIFT)) & XRDC_C_HWCFG2_PIDP30_MASK)

#define XRDC_C_HWCFG2_PIDP31_MASK                (0x80000000U)
#define XRDC_C_HWCFG2_PIDP31_SHIFT               (31U)
#define XRDC_C_HWCFG2_PIDP31_WIDTH               (1U)
#define XRDC_C_HWCFG2_PIDP31(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_HWCFG2_PIDP31_SHIFT)) & XRDC_C_HWCFG2_PIDP31_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define XRDC_C_MDACFG_NMDAR_MASK                 (0xFU)
#define XRDC_C_MDACFG_NMDAR_SHIFT                (0U)
#define XRDC_C_MDACFG_NMDAR_WIDTH                (4U)
#define XRDC_C_MDACFG_NMDAR(x)                   (((uint8_t)(((uint8_t)(x)) << XRDC_C_MDACFG_NMDAR_SHIFT)) & XRDC_C_MDACFG_NMDAR_MASK)

#define XRDC_C_MDACFG_NCM_MASK                   (0x80U)
#define XRDC_C_MDACFG_NCM_SHIFT                  (7U)
#define XRDC_C_MDACFG_NCM_WIDTH                  (1U)
#define XRDC_C_MDACFG_NCM(x)                     (((uint8_t)(((uint8_t)(x)) << XRDC_C_MDACFG_NCM_SHIFT)) & XRDC_C_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define XRDC_C_MRCFG_NMRGD_MASK                  (0x1FU)
#define XRDC_C_MRCFG_NMRGD_SHIFT                 (0U)
#define XRDC_C_MRCFG_NMRGD_WIDTH                 (5U)
#define XRDC_C_MRCFG_NMRGD(x)                    (((uint8_t)(((uint8_t)(x)) << XRDC_C_MRCFG_NMRGD_SHIFT)) & XRDC_C_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define XRDC_C_DERRLOC_MRCINST_MASK              (0xFFFFU)
#define XRDC_C_DERRLOC_MRCINST_SHIFT             (0U)
#define XRDC_C_DERRLOC_MRCINST_WIDTH             (16U)
#define XRDC_C_DERRLOC_MRCINST(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERRLOC_MRCINST_SHIFT)) & XRDC_C_DERRLOC_MRCINST_MASK)

#define XRDC_C_DERRLOC_PACINST_MASK              (0xFF0000U)
#define XRDC_C_DERRLOC_PACINST_SHIFT             (16U)
#define XRDC_C_DERRLOC_PACINST_WIDTH             (8U)
#define XRDC_C_DERRLOC_PACINST(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERRLOC_PACINST_SHIFT)) & XRDC_C_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W0 - Domain Error Word 0 */
/*! @{ */

#define XRDC_C_DERR_W0_EADDR_MASK                (0xFFFFFFFFU)
#define XRDC_C_DERR_W0_EADDR_SHIFT               (0U)
#define XRDC_C_DERR_W0_EADDR_WIDTH               (32U)
#define XRDC_C_DERR_W0_EADDR(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W0_EADDR_SHIFT)) & XRDC_C_DERR_W0_EADDR_MASK)
/*! @} */

/*! @name DERR_W1 - Domain Error Word 1 */
/*! @{ */

#define XRDC_C_DERR_W1_EDID_MASK                 (0xFU)
#define XRDC_C_DERR_W1_EDID_SHIFT                (0U)
#define XRDC_C_DERR_W1_EDID_WIDTH                (4U)
#define XRDC_C_DERR_W1_EDID(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W1_EDID_SHIFT)) & XRDC_C_DERR_W1_EDID_MASK)

#define XRDC_C_DERR_W1_EATR_MASK                 (0x700U)
#define XRDC_C_DERR_W1_EATR_SHIFT                (8U)
#define XRDC_C_DERR_W1_EATR_WIDTH                (3U)
#define XRDC_C_DERR_W1_EATR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W1_EATR_SHIFT)) & XRDC_C_DERR_W1_EATR_MASK)

#define XRDC_C_DERR_W1_ERW_MASK                  (0x800U)
#define XRDC_C_DERR_W1_ERW_SHIFT                 (11U)
#define XRDC_C_DERR_W1_ERW_WIDTH                 (1U)
#define XRDC_C_DERR_W1_ERW(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W1_ERW_SHIFT)) & XRDC_C_DERR_W1_ERW_MASK)

#define XRDC_C_DERR_W1_EPORT_MASK                (0x7000000U)
#define XRDC_C_DERR_W1_EPORT_SHIFT               (24U)
#define XRDC_C_DERR_W1_EPORT_WIDTH               (3U)
#define XRDC_C_DERR_W1_EPORT(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W1_EPORT_SHIFT)) & XRDC_C_DERR_W1_EPORT_MASK)

#define XRDC_C_DERR_W1_EST_MASK                  (0xC0000000U)
#define XRDC_C_DERR_W1_EST_SHIFT                 (30U)
#define XRDC_C_DERR_W1_EST_WIDTH                 (2U)
#define XRDC_C_DERR_W1_EST(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W1_EST_SHIFT)) & XRDC_C_DERR_W1_EST_MASK)
/*! @} */

/*! @name DERR_W3 - Domain Error Word 3 */
/*! @{ */

#define XRDC_C_DERR_W3_RECR_MASK                 (0xC0000000U)
#define XRDC_C_DERR_W3_RECR_SHIFT                (30U)
#define XRDC_C_DERR_W3_RECR_WIDTH                (2U)
#define XRDC_C_DERR_W3_RECR(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_DERR_W3_RECR_SHIFT)) & XRDC_C_DERR_W3_RECR_MASK)
/*! @} */

/*! @name MDA_W0_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_C_MDA_W0_0_DFMT1_DID_MASK           (0xFU)
#define XRDC_C_MDA_W0_0_DFMT1_DID_SHIFT          (0U)
#define XRDC_C_MDA_W0_0_DFMT1_DID_WIDTH          (4U)
#define XRDC_C_MDA_W0_0_DFMT1_DID(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_DID_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_DID_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_PA_MASK            (0x30U)
#define XRDC_C_MDA_W0_0_DFMT1_PA_SHIFT           (4U)
#define XRDC_C_MDA_W0_0_DFMT1_PA_WIDTH           (2U)
#define XRDC_C_MDA_W0_0_DFMT1_PA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_PA_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_PA_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_SA_MASK            (0xC0U)
#define XRDC_C_MDA_W0_0_DFMT1_SA_SHIFT           (6U)
#define XRDC_C_MDA_W0_0_DFMT1_SA_WIDTH           (2U)
#define XRDC_C_MDA_W0_0_DFMT1_SA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_SA_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_SA_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_DIDB_MASK          (0x100U)
#define XRDC_C_MDA_W0_0_DFMT1_DIDB_SHIFT         (8U)
#define XRDC_C_MDA_W0_0_DFMT1_DIDB_WIDTH         (1U)
#define XRDC_C_MDA_W0_0_DFMT1_DIDB(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_DIDB_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_DIDB_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_LPID_MASK          (0xF000000U)
#define XRDC_C_MDA_W0_0_DFMT1_LPID_SHIFT         (24U)
#define XRDC_C_MDA_W0_0_DFMT1_LPID_WIDTH         (4U)
#define XRDC_C_MDA_W0_0_DFMT1_LPID(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_LPID_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_LPID_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_LPE_MASK           (0x10000000U)
#define XRDC_C_MDA_W0_0_DFMT1_LPE_SHIFT          (28U)
#define XRDC_C_MDA_W0_0_DFMT1_LPE_WIDTH          (1U)
#define XRDC_C_MDA_W0_0_DFMT1_LPE(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_LPE_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_LPE_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_DFMT_MASK          (0x20000000U)
#define XRDC_C_MDA_W0_0_DFMT1_DFMT_SHIFT         (29U)
#define XRDC_C_MDA_W0_0_DFMT1_DFMT_WIDTH         (1U)
#define XRDC_C_MDA_W0_0_DFMT1_DFMT(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_DFMT_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_DFMT_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_LK1_MASK           (0x40000000U)
#define XRDC_C_MDA_W0_0_DFMT1_LK1_SHIFT          (30U)
#define XRDC_C_MDA_W0_0_DFMT1_LK1_WIDTH          (1U)
#define XRDC_C_MDA_W0_0_DFMT1_LK1(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_LK1_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_LK1_MASK)

#define XRDC_C_MDA_W0_0_DFMT1_VLD_MASK           (0x80000000U)
#define XRDC_C_MDA_W0_0_DFMT1_VLD_SHIFT          (31U)
#define XRDC_C_MDA_W0_0_DFMT1_VLD_WIDTH          (1U)
#define XRDC_C_MDA_W0_0_DFMT1_VLD(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W0_0_DFMT1_VLD_SHIFT)) & XRDC_C_MDA_W0_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_C_MDA_W1_0_DFMT1_DID_MASK           (0xFU)
#define XRDC_C_MDA_W1_0_DFMT1_DID_SHIFT          (0U)
#define XRDC_C_MDA_W1_0_DFMT1_DID_WIDTH          (4U)
#define XRDC_C_MDA_W1_0_DFMT1_DID(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_DID_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_DID_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_PA_MASK            (0x30U)
#define XRDC_C_MDA_W1_0_DFMT1_PA_SHIFT           (4U)
#define XRDC_C_MDA_W1_0_DFMT1_PA_WIDTH           (2U)
#define XRDC_C_MDA_W1_0_DFMT1_PA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_PA_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_PA_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_SA_MASK            (0xC0U)
#define XRDC_C_MDA_W1_0_DFMT1_SA_SHIFT           (6U)
#define XRDC_C_MDA_W1_0_DFMT1_SA_WIDTH           (2U)
#define XRDC_C_MDA_W1_0_DFMT1_SA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_SA_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_SA_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_DIDB_MASK          (0x100U)
#define XRDC_C_MDA_W1_0_DFMT1_DIDB_SHIFT         (8U)
#define XRDC_C_MDA_W1_0_DFMT1_DIDB_WIDTH         (1U)
#define XRDC_C_MDA_W1_0_DFMT1_DIDB(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_DIDB_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_DIDB_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_LPID_MASK          (0xF000000U)
#define XRDC_C_MDA_W1_0_DFMT1_LPID_SHIFT         (24U)
#define XRDC_C_MDA_W1_0_DFMT1_LPID_WIDTH         (4U)
#define XRDC_C_MDA_W1_0_DFMT1_LPID(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_LPID_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_LPID_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_LPE_MASK           (0x10000000U)
#define XRDC_C_MDA_W1_0_DFMT1_LPE_SHIFT          (28U)
#define XRDC_C_MDA_W1_0_DFMT1_LPE_WIDTH          (1U)
#define XRDC_C_MDA_W1_0_DFMT1_LPE(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_LPE_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_LPE_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_DFMT_MASK          (0x20000000U)
#define XRDC_C_MDA_W1_0_DFMT1_DFMT_SHIFT         (29U)
#define XRDC_C_MDA_W1_0_DFMT1_DFMT_WIDTH         (1U)
#define XRDC_C_MDA_W1_0_DFMT1_DFMT(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_DFMT_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_DFMT_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_LK1_MASK           (0x40000000U)
#define XRDC_C_MDA_W1_0_DFMT1_LK1_SHIFT          (30U)
#define XRDC_C_MDA_W1_0_DFMT1_LK1_WIDTH          (1U)
#define XRDC_C_MDA_W1_0_DFMT1_LK1(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_LK1_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_LK1_MASK)

#define XRDC_C_MDA_W1_0_DFMT1_VLD_MASK           (0x80000000U)
#define XRDC_C_MDA_W1_0_DFMT1_VLD_SHIFT          (31U)
#define XRDC_C_MDA_W1_0_DFMT1_VLD_WIDTH          (1U)
#define XRDC_C_MDA_W1_0_DFMT1_VLD(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W1_0_DFMT1_VLD_SHIFT)) & XRDC_C_MDA_W1_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_C_MDA_W2_0_DFMT1_DID_MASK           (0xFU)
#define XRDC_C_MDA_W2_0_DFMT1_DID_SHIFT          (0U)
#define XRDC_C_MDA_W2_0_DFMT1_DID_WIDTH          (4U)
#define XRDC_C_MDA_W2_0_DFMT1_DID(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_DID_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_DID_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_PA_MASK            (0x30U)
#define XRDC_C_MDA_W2_0_DFMT1_PA_SHIFT           (4U)
#define XRDC_C_MDA_W2_0_DFMT1_PA_WIDTH           (2U)
#define XRDC_C_MDA_W2_0_DFMT1_PA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_PA_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_PA_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_SA_MASK            (0xC0U)
#define XRDC_C_MDA_W2_0_DFMT1_SA_SHIFT           (6U)
#define XRDC_C_MDA_W2_0_DFMT1_SA_WIDTH           (2U)
#define XRDC_C_MDA_W2_0_DFMT1_SA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_SA_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_SA_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_DIDB_MASK          (0x100U)
#define XRDC_C_MDA_W2_0_DFMT1_DIDB_SHIFT         (8U)
#define XRDC_C_MDA_W2_0_DFMT1_DIDB_WIDTH         (1U)
#define XRDC_C_MDA_W2_0_DFMT1_DIDB(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_DIDB_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_DIDB_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_LPID_MASK          (0xF000000U)
#define XRDC_C_MDA_W2_0_DFMT1_LPID_SHIFT         (24U)
#define XRDC_C_MDA_W2_0_DFMT1_LPID_WIDTH         (4U)
#define XRDC_C_MDA_W2_0_DFMT1_LPID(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_LPID_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_LPID_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_LPE_MASK           (0x10000000U)
#define XRDC_C_MDA_W2_0_DFMT1_LPE_SHIFT          (28U)
#define XRDC_C_MDA_W2_0_DFMT1_LPE_WIDTH          (1U)
#define XRDC_C_MDA_W2_0_DFMT1_LPE(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_LPE_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_LPE_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_DFMT_MASK          (0x20000000U)
#define XRDC_C_MDA_W2_0_DFMT1_DFMT_SHIFT         (29U)
#define XRDC_C_MDA_W2_0_DFMT1_DFMT_WIDTH         (1U)
#define XRDC_C_MDA_W2_0_DFMT1_DFMT(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_DFMT_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_DFMT_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_LK1_MASK           (0x40000000U)
#define XRDC_C_MDA_W2_0_DFMT1_LK1_SHIFT          (30U)
#define XRDC_C_MDA_W2_0_DFMT1_LK1_WIDTH          (1U)
#define XRDC_C_MDA_W2_0_DFMT1_LK1(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_LK1_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_LK1_MASK)

#define XRDC_C_MDA_W2_0_DFMT1_VLD_MASK           (0x80000000U)
#define XRDC_C_MDA_W2_0_DFMT1_VLD_SHIFT          (31U)
#define XRDC_C_MDA_W2_0_DFMT1_VLD_WIDTH          (1U)
#define XRDC_C_MDA_W2_0_DFMT1_VLD(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W2_0_DFMT1_VLD_SHIFT)) & XRDC_C_MDA_W2_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_C_MDA_W3_0_DFMT1_DID_MASK           (0xFU)
#define XRDC_C_MDA_W3_0_DFMT1_DID_SHIFT          (0U)
#define XRDC_C_MDA_W3_0_DFMT1_DID_WIDTH          (4U)
#define XRDC_C_MDA_W3_0_DFMT1_DID(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_DID_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_DID_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_PA_MASK            (0x30U)
#define XRDC_C_MDA_W3_0_DFMT1_PA_SHIFT           (4U)
#define XRDC_C_MDA_W3_0_DFMT1_PA_WIDTH           (2U)
#define XRDC_C_MDA_W3_0_DFMT1_PA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_PA_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_PA_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_SA_MASK            (0xC0U)
#define XRDC_C_MDA_W3_0_DFMT1_SA_SHIFT           (6U)
#define XRDC_C_MDA_W3_0_DFMT1_SA_WIDTH           (2U)
#define XRDC_C_MDA_W3_0_DFMT1_SA(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_SA_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_SA_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_DIDB_MASK          (0x100U)
#define XRDC_C_MDA_W3_0_DFMT1_DIDB_SHIFT         (8U)
#define XRDC_C_MDA_W3_0_DFMT1_DIDB_WIDTH         (1U)
#define XRDC_C_MDA_W3_0_DFMT1_DIDB(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_DIDB_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_DIDB_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_LPID_MASK          (0xF000000U)
#define XRDC_C_MDA_W3_0_DFMT1_LPID_SHIFT         (24U)
#define XRDC_C_MDA_W3_0_DFMT1_LPID_WIDTH         (4U)
#define XRDC_C_MDA_W3_0_DFMT1_LPID(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_LPID_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_LPID_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_LPE_MASK           (0x10000000U)
#define XRDC_C_MDA_W3_0_DFMT1_LPE_SHIFT          (28U)
#define XRDC_C_MDA_W3_0_DFMT1_LPE_WIDTH          (1U)
#define XRDC_C_MDA_W3_0_DFMT1_LPE(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_LPE_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_LPE_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_DFMT_MASK          (0x20000000U)
#define XRDC_C_MDA_W3_0_DFMT1_DFMT_SHIFT         (29U)
#define XRDC_C_MDA_W3_0_DFMT1_DFMT_WIDTH         (1U)
#define XRDC_C_MDA_W3_0_DFMT1_DFMT(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_DFMT_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_DFMT_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_LK1_MASK           (0x40000000U)
#define XRDC_C_MDA_W3_0_DFMT1_LK1_SHIFT          (30U)
#define XRDC_C_MDA_W3_0_DFMT1_LK1_WIDTH          (1U)
#define XRDC_C_MDA_W3_0_DFMT1_LK1(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_LK1_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_LK1_MASK)

#define XRDC_C_MDA_W3_0_DFMT1_VLD_MASK           (0x80000000U)
#define XRDC_C_MDA_W3_0_DFMT1_VLD_SHIFT          (31U)
#define XRDC_C_MDA_W3_0_DFMT1_VLD_WIDTH          (1U)
#define XRDC_C_MDA_W3_0_DFMT1_VLD(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_MDA_W3_0_DFMT1_VLD_SHIFT)) & XRDC_C_MDA_W3_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name XRDC_MRGD_W0 - Memory Region Descriptor Word 0 */
/*! @{ */

#define XRDC_C_XRDC_MRGD_W0_SRTADDR_MASK         (0xFFFFFFE0U)
#define XRDC_C_XRDC_MRGD_W0_SRTADDR_SHIFT        (5U)
#define XRDC_C_XRDC_MRGD_W0_SRTADDR_WIDTH        (27U)
#define XRDC_C_XRDC_MRGD_W0_SRTADDR(x)           (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W0_SRTADDR_SHIFT)) & XRDC_C_XRDC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W1 - Memory Region Descriptor Word 1 */
/*! @{ */

#define XRDC_C_XRDC_MRGD_W1_ENDADDR_MASK         (0xFFFFFFE0U)
#define XRDC_C_XRDC_MRGD_W1_ENDADDR_SHIFT        (5U)
#define XRDC_C_XRDC_MRGD_W1_ENDADDR_WIDTH        (27U)
#define XRDC_C_XRDC_MRGD_W1_ENDADDR(x)           (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W1_ENDADDR_SHIFT)) & XRDC_C_XRDC_MRGD_W1_ENDADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W2 - Memory Region Descriptor Word 2 */
/*! @{ */

#define XRDC_C_XRDC_MRGD_W2_D0ACP_MASK           (0x7U)
#define XRDC_C_XRDC_MRGD_W2_D0ACP_SHIFT          (0U)
#define XRDC_C_XRDC_MRGD_W2_D0ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D0ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D0ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D0ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D1ACP_MASK           (0x38U)
#define XRDC_C_XRDC_MRGD_W2_D1ACP_SHIFT          (3U)
#define XRDC_C_XRDC_MRGD_W2_D1ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D1ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D1ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D1ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D2ACP_MASK           (0x1C0U)
#define XRDC_C_XRDC_MRGD_W2_D2ACP_SHIFT          (6U)
#define XRDC_C_XRDC_MRGD_W2_D2ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D2ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D2ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D2ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D3ACP_MASK           (0xE00U)
#define XRDC_C_XRDC_MRGD_W2_D3ACP_SHIFT          (9U)
#define XRDC_C_XRDC_MRGD_W2_D3ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D3ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D3ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D3ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D4ACP_MASK           (0x7000U)
#define XRDC_C_XRDC_MRGD_W2_D4ACP_SHIFT          (12U)
#define XRDC_C_XRDC_MRGD_W2_D4ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D4ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D4ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D4ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D5ACP_MASK           (0x38000U)
#define XRDC_C_XRDC_MRGD_W2_D5ACP_SHIFT          (15U)
#define XRDC_C_XRDC_MRGD_W2_D5ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D5ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D5ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D5ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D6ACP_MASK           (0x1C0000U)
#define XRDC_C_XRDC_MRGD_W2_D6ACP_SHIFT          (18U)
#define XRDC_C_XRDC_MRGD_W2_D6ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D6ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D6ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D6ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_D7ACP_MASK           (0xE00000U)
#define XRDC_C_XRDC_MRGD_W2_D7ACP_SHIFT          (21U)
#define XRDC_C_XRDC_MRGD_W2_D7ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W2_D7ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_D7ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W2_D7ACP_MASK)

#define XRDC_C_XRDC_MRGD_W2_SNUM_MASK            (0xF000000U)
#define XRDC_C_XRDC_MRGD_W2_SNUM_SHIFT           (24U)
#define XRDC_C_XRDC_MRGD_W2_SNUM_WIDTH           (4U)
#define XRDC_C_XRDC_MRGD_W2_SNUM(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_SNUM_SHIFT)) & XRDC_C_XRDC_MRGD_W2_SNUM_MASK)

#define XRDC_C_XRDC_MRGD_W2_SE_MASK              (0x40000000U)
#define XRDC_C_XRDC_MRGD_W2_SE_SHIFT             (30U)
#define XRDC_C_XRDC_MRGD_W2_SE_WIDTH             (1U)
#define XRDC_C_XRDC_MRGD_W2_SE(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W2_SE_SHIFT)) & XRDC_C_XRDC_MRGD_W2_SE_MASK)
/*! @} */

/*! @name XRDC_MRGD_W3 - Memory Region Descriptor Word 3 */
/*! @{ */

#define XRDC_C_XRDC_MRGD_W3_D8ACP_MASK           (0x7U)
#define XRDC_C_XRDC_MRGD_W3_D8ACP_SHIFT          (0U)
#define XRDC_C_XRDC_MRGD_W3_D8ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W3_D8ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D8ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D8ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D9ACP_MASK           (0x38U)
#define XRDC_C_XRDC_MRGD_W3_D9ACP_SHIFT          (3U)
#define XRDC_C_XRDC_MRGD_W3_D9ACP_WIDTH          (3U)
#define XRDC_C_XRDC_MRGD_W3_D9ACP(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D9ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D9ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D10ACP_MASK          (0x1C0U)
#define XRDC_C_XRDC_MRGD_W3_D10ACP_SHIFT         (6U)
#define XRDC_C_XRDC_MRGD_W3_D10ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D10ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D10ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D10ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D11ACP_MASK          (0xE00U)
#define XRDC_C_XRDC_MRGD_W3_D11ACP_SHIFT         (9U)
#define XRDC_C_XRDC_MRGD_W3_D11ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D11ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D11ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D11ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D12ACP_MASK          (0x7000U)
#define XRDC_C_XRDC_MRGD_W3_D12ACP_SHIFT         (12U)
#define XRDC_C_XRDC_MRGD_W3_D12ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D12ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D12ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D12ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D13ACP_MASK          (0x38000U)
#define XRDC_C_XRDC_MRGD_W3_D13ACP_SHIFT         (15U)
#define XRDC_C_XRDC_MRGD_W3_D13ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D13ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D13ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D13ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D14ACP_MASK          (0x1C0000U)
#define XRDC_C_XRDC_MRGD_W3_D14ACP_SHIFT         (18U)
#define XRDC_C_XRDC_MRGD_W3_D14ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D14ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D14ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D14ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_D15ACP_MASK          (0xE00000U)
#define XRDC_C_XRDC_MRGD_W3_D15ACP_SHIFT         (21U)
#define XRDC_C_XRDC_MRGD_W3_D15ACP_WIDTH         (3U)
#define XRDC_C_XRDC_MRGD_W3_D15ACP(x)            (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_D15ACP_SHIFT)) & XRDC_C_XRDC_MRGD_W3_D15ACP_MASK)

#define XRDC_C_XRDC_MRGD_W3_LK2_MASK             (0x60000000U)
#define XRDC_C_XRDC_MRGD_W3_LK2_SHIFT            (29U)
#define XRDC_C_XRDC_MRGD_W3_LK2_WIDTH            (2U)
#define XRDC_C_XRDC_MRGD_W3_LK2(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_LK2_SHIFT)) & XRDC_C_XRDC_MRGD_W3_LK2_MASK)

#define XRDC_C_XRDC_MRGD_W3_VLD_MASK             (0x80000000U)
#define XRDC_C_XRDC_MRGD_W3_VLD_SHIFT            (31U)
#define XRDC_C_XRDC_MRGD_W3_VLD_WIDTH            (1U)
#define XRDC_C_XRDC_MRGD_W3_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_C_XRDC_MRGD_W3_VLD_SHIFT)) & XRDC_C_XRDC_MRGD_W3_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_C_PDAC_W0_D0ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W0_D0ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W0_D0ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D0ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D0ACP_SHIFT)) & XRDC_C_PDAC_W0_D0ACP_MASK)

#define XRDC_C_PDAC_W0_D1ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W0_D1ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W0_D1ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D1ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D1ACP_SHIFT)) & XRDC_C_PDAC_W0_D1ACP_MASK)

#define XRDC_C_PDAC_W0_D2ACP_MASK                (0x1C0U)
#define XRDC_C_PDAC_W0_D2ACP_SHIFT               (6U)
#define XRDC_C_PDAC_W0_D2ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D2ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D2ACP_SHIFT)) & XRDC_C_PDAC_W0_D2ACP_MASK)

#define XRDC_C_PDAC_W0_D3ACP_MASK                (0xE00U)
#define XRDC_C_PDAC_W0_D3ACP_SHIFT               (9U)
#define XRDC_C_PDAC_W0_D3ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D3ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D3ACP_SHIFT)) & XRDC_C_PDAC_W0_D3ACP_MASK)

#define XRDC_C_PDAC_W0_D4ACP_MASK                (0x7000U)
#define XRDC_C_PDAC_W0_D4ACP_SHIFT               (12U)
#define XRDC_C_PDAC_W0_D4ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D4ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D4ACP_SHIFT)) & XRDC_C_PDAC_W0_D4ACP_MASK)

#define XRDC_C_PDAC_W0_D5ACP_MASK                (0x38000U)
#define XRDC_C_PDAC_W0_D5ACP_SHIFT               (15U)
#define XRDC_C_PDAC_W0_D5ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D5ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D5ACP_SHIFT)) & XRDC_C_PDAC_W0_D5ACP_MASK)

#define XRDC_C_PDAC_W0_D6ACP_MASK                (0x1C0000U)
#define XRDC_C_PDAC_W0_D6ACP_SHIFT               (18U)
#define XRDC_C_PDAC_W0_D6ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D6ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D6ACP_SHIFT)) & XRDC_C_PDAC_W0_D6ACP_MASK)

#define XRDC_C_PDAC_W0_D7ACP_MASK                (0xE00000U)
#define XRDC_C_PDAC_W0_D7ACP_SHIFT               (21U)
#define XRDC_C_PDAC_W0_D7ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W0_D7ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_D7ACP_SHIFT)) & XRDC_C_PDAC_W0_D7ACP_MASK)

#define XRDC_C_PDAC_W0_SNUM_MASK                 (0xF000000U)
#define XRDC_C_PDAC_W0_SNUM_SHIFT                (24U)
#define XRDC_C_PDAC_W0_SNUM_WIDTH                (4U)
#define XRDC_C_PDAC_W0_SNUM(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SNUM_SHIFT)) & XRDC_C_PDAC_W0_SNUM_MASK)

#define XRDC_C_PDAC_W0_SE_MASK                   (0x40000000U)
#define XRDC_C_PDAC_W0_SE_SHIFT                  (30U)
#define XRDC_C_PDAC_W0_SE_WIDTH                  (1U)
#define XRDC_C_PDAC_W0_SE(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W0_SE_SHIFT)) & XRDC_C_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_C_PDAC_W1_D8ACP_MASK                (0x7U)
#define XRDC_C_PDAC_W1_D8ACP_SHIFT               (0U)
#define XRDC_C_PDAC_W1_D8ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D8ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D8ACP_SHIFT)) & XRDC_C_PDAC_W1_D8ACP_MASK)

#define XRDC_C_PDAC_W1_D9ACP_MASK                (0x38U)
#define XRDC_C_PDAC_W1_D9ACP_SHIFT               (3U)
#define XRDC_C_PDAC_W1_D9ACP_WIDTH               (3U)
#define XRDC_C_PDAC_W1_D9ACP(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D9ACP_SHIFT)) & XRDC_C_PDAC_W1_D9ACP_MASK)

#define XRDC_C_PDAC_W1_D10ACP_MASK               (0x1C0U)
#define XRDC_C_PDAC_W1_D10ACP_SHIFT              (6U)
#define XRDC_C_PDAC_W1_D10ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D10ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D10ACP_SHIFT)) & XRDC_C_PDAC_W1_D10ACP_MASK)

#define XRDC_C_PDAC_W1_D11ACP_MASK               (0xE00U)
#define XRDC_C_PDAC_W1_D11ACP_SHIFT              (9U)
#define XRDC_C_PDAC_W1_D11ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D11ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D11ACP_SHIFT)) & XRDC_C_PDAC_W1_D11ACP_MASK)

#define XRDC_C_PDAC_W1_D12ACP_MASK               (0x7000U)
#define XRDC_C_PDAC_W1_D12ACP_SHIFT              (12U)
#define XRDC_C_PDAC_W1_D12ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D12ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D12ACP_SHIFT)) & XRDC_C_PDAC_W1_D12ACP_MASK)

#define XRDC_C_PDAC_W1_D13ACP_MASK               (0x38000U)
#define XRDC_C_PDAC_W1_D13ACP_SHIFT              (15U)
#define XRDC_C_PDAC_W1_D13ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D13ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D13ACP_SHIFT)) & XRDC_C_PDAC_W1_D13ACP_MASK)

#define XRDC_C_PDAC_W1_D14ACP_MASK               (0x1C0000U)
#define XRDC_C_PDAC_W1_D14ACP_SHIFT              (18U)
#define XRDC_C_PDAC_W1_D14ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D14ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D14ACP_SHIFT)) & XRDC_C_PDAC_W1_D14ACP_MASK)

#define XRDC_C_PDAC_W1_D15ACP_MASK               (0xE00000U)
#define XRDC_C_PDAC_W1_D15ACP_SHIFT              (21U)
#define XRDC_C_PDAC_W1_D15ACP_WIDTH              (3U)
#define XRDC_C_PDAC_W1_D15ACP(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_D15ACP_SHIFT)) & XRDC_C_PDAC_W1_D15ACP_MASK)

#define XRDC_C_PDAC_W1_LK2_MASK                  (0x60000000U)
#define XRDC_C_PDAC_W1_LK2_SHIFT                 (29U)
#define XRDC_C_PDAC_W1_LK2_WIDTH                 (2U)
#define XRDC_C_PDAC_W1_LK2(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_LK2_SHIFT)) & XRDC_C_PDAC_W1_LK2_MASK)

#define XRDC_C_PDAC_W1_VLD_MASK                  (0x80000000U)
#define XRDC_C_PDAC_W1_VLD_SHIFT                 (31U)
#define XRDC_C_PDAC_W1_VLD_WIDTH                 (1U)
#define XRDC_C_PDAC_W1_VLD(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_C_PDAC_W1_VLD_SHIFT)) & XRDC_C_PDAC_W1_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XRDC_C_Register_Masks */

/*!
 * @}
 */ /* end of group XRDC_C_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_XRDC_C_H_) */
