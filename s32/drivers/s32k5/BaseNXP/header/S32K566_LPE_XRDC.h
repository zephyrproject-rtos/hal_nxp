/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_LPE_XRDC.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_LPE_XRDC
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
#if !defined(S32K566_LPE_XRDC_H_)  /* Check if memory map has not been already included */
#define S32K566_LPE_XRDC_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- LPE_XRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_XRDC_Peripheral_Access_Layer LPE_XRDC Peripheral Access Layer
 * @{
 */

/** LPE_XRDC - Size of Registers Arrays */
#define LPE_XRDC_MDAC_COUNT                       2u
#define LPE_XRDC_MRC_COUNT                        1u
#define LPE_XRDC_DERRLOC_COUNT                    16u
#define LPE_XRDC_DERRW0_COUNT                     19u
#define LPE_XRDC_PID_COUNT                        1u
#define LPE_XRDC_PDAC_SLOT_PDACN_COUNT            108u
#define LPE_XRDC_PDAC_SLOT_COUNT                  3u
#define LPE_XRDC_MRCN_COUNT                       1u
#define LPE_XRDC_MRCN_MRGDN_COUNT                 16u

/** LPE_XRDC - Register Layout Typedef */
typedef struct LPE_XRDC_Struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  __I  uint32_t HWCFG2;                            /**< Hardware Configuration 2, offset: 0xF8 */
  uint8_t RESERVED_1[4];
  __I  uint8_t MDACFG[LPE_XRDC_MDAC_COUNT];        /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
  uint8_t RESERVED_2[62];
  __I  uint8_t MRCFG[LPE_XRDC_MRC_COUNT];          /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
  uint8_t RESERVED_3[191];
  __I  uint32_t DERRLOC[LPE_XRDC_DERRLOC_COUNT];   /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[448];
  struct LPE_XRDC_DERRW0 {                         /* offset: 0x400, array step: 0x10 */
    __I  uint32_t DERR_W0;                           /**< Domain Error Word 0, array offset: 0x400, array step: 0x10, valid indices: [0, 16-18] */
    __I  uint32_t DERR_W1;                           /**< Domain Error Word 1, array offset: 0x404, array step: 0x10, valid indices: [0, 16-18] */
    uint8_t RESERVED_0[4];
    __IO uint32_t DERR_W3;                           /**< Domain Error Word 3, array offset: 0x40C, array step: 0x10, valid indices: [0, 16-18] */
  } DERRW0[LPE_XRDC_DERRW0_COUNT];
  uint8_t RESERVED_5[464];
  __IO uint32_t PID[LPE_XRDC_PID_COUNT];           /**< Process Identifier, array offset: 0x700, array step: 0x4 */
  uint8_t RESERVED_6[252];
  __IO uint32_t MDA_W0_0_DFMT0;                    /**< Master Domain Assignment, offset: 0x800 */
  __IO uint32_t MDA_W1_0_DFMT0;                    /**< Master Domain Assignment, offset: 0x804 */
  __IO uint32_t MDA_W2_0_DFMT0;                    /**< Master Domain Assignment, offset: 0x808 */
  __IO uint32_t MDA_W3_0_DFMT0;                    /**< Master Domain Assignment, offset: 0x80C */
  uint8_t RESERVED_7[16];
  __IO uint32_t MDA_W0_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x820 */
  uint8_t RESERVED_8[2012];
  struct LPE_XRDC_PDAC_SLOT {                      /* offset: 0x1000, array step: 0x400 */
    struct LPE_XRDC_PDAC_SLOT_PDACN {                /* offset: 0x1000, array step: index*0x400, index2*0x8 */
      __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1000, array step: index*0x400, index2*0x8, irregular array, not all indices are valid */
      __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1004, array step: index*0x400, index2*0x8, irregular array, not all indices are valid */
    } PDACN[LPE_XRDC_PDAC_SLOT_PDACN_COUNT];
    uint8_t RESERVED_0[160];
  } PDAC_SLOT[LPE_XRDC_PDAC_SLOT_COUNT];
  uint8_t RESERVED_9[1024];
  struct LPE_XRDC_MRGDN {                          /* offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W0;                      /**< Memory Region Descriptor Word 0, array offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W1;                      /**< Memory Region Descriptor Word 1, array offset: 0x2004, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W2;                      /**< Memory Region Descriptor Word 2, array offset: 0x2008, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W3;                      /**< Memory Region Descriptor Word 3, array offset: 0x200C, array step: index*0x200, index2*0x20 */
    uint8_t RESERVED_0[16];
  } MRGDN[LPE_XRDC_MRCN_COUNT][LPE_XRDC_MRCN_MRGDN_COUNT];
} LPE_XRDC_Type, *LPE_XRDC_MemMapPtr;

/** Number of instances of the LPE_XRDC module. */
#define LPE_XRDC_INSTANCE_COUNT                  (1u)

/* LPE_XRDC - Peripheral instance base addresses */
/** Peripheral LPE_XRDC base address */
#define IP_LPE_XRDC_BASE                         (0x4203C000u)
/** Peripheral LPE_XRDC base pointer */
#define IP_LPE_XRDC                              ((LPE_XRDC_Type *)IP_LPE_XRDC_BASE)
/** Array initializer of LPE_XRDC peripheral base addresses */
#define IP_LPE_XRDC_BASE_ADDRS                   { IP_LPE_XRDC_BASE }
/** Array initializer of LPE_XRDC peripheral base pointers */
#define IP_LPE_XRDC_BASE_PTRS                    { IP_LPE_XRDC }

/* ----------------------------------------------------------------------------
   -- LPE_XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPE_XRDC_Register_Masks LPE_XRDC Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define LPE_XRDC_CR_GVLD_MASK                    (0x1U)
#define LPE_XRDC_CR_GVLD_SHIFT                   (0U)
#define LPE_XRDC_CR_GVLD_WIDTH                   (1U)
#define LPE_XRDC_CR_GVLD(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_CR_GVLD_SHIFT)) & LPE_XRDC_CR_GVLD_MASK)

#define LPE_XRDC_CR_HRL_MASK                     (0x1EU)
#define LPE_XRDC_CR_HRL_SHIFT                    (1U)
#define LPE_XRDC_CR_HRL_WIDTH                    (4U)
#define LPE_XRDC_CR_HRL(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_CR_HRL_SHIFT)) & LPE_XRDC_CR_HRL_MASK)

#define LPE_XRDC_CR_MRF_MASK                     (0x80U)
#define LPE_XRDC_CR_MRF_SHIFT                    (7U)
#define LPE_XRDC_CR_MRF_WIDTH                    (1U)
#define LPE_XRDC_CR_MRF(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_CR_MRF_SHIFT)) & LPE_XRDC_CR_MRF_MASK)

#define LPE_XRDC_CR_VAW_MASK                     (0x100U)
#define LPE_XRDC_CR_VAW_SHIFT                    (8U)
#define LPE_XRDC_CR_VAW_WIDTH                    (1U)
#define LPE_XRDC_CR_VAW(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_CR_VAW_SHIFT)) & LPE_XRDC_CR_VAW_MASK)

#define LPE_XRDC_CR_LK1_MASK                     (0x40000000U)
#define LPE_XRDC_CR_LK1_SHIFT                    (30U)
#define LPE_XRDC_CR_LK1_WIDTH                    (1U)
#define LPE_XRDC_CR_LK1(x)                       (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_CR_LK1_SHIFT)) & LPE_XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define LPE_XRDC_HWCFG0_NDID_MASK                (0xFFU)
#define LPE_XRDC_HWCFG0_NDID_SHIFT               (0U)
#define LPE_XRDC_HWCFG0_NDID_WIDTH               (8U)
#define LPE_XRDC_HWCFG0_NDID(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG0_NDID_SHIFT)) & LPE_XRDC_HWCFG0_NDID_MASK)

#define LPE_XRDC_HWCFG0_NMSTR_MASK               (0xFF00U)
#define LPE_XRDC_HWCFG0_NMSTR_SHIFT              (8U)
#define LPE_XRDC_HWCFG0_NMSTR_WIDTH              (8U)
#define LPE_XRDC_HWCFG0_NMSTR(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG0_NMSTR_SHIFT)) & LPE_XRDC_HWCFG0_NMSTR_MASK)

#define LPE_XRDC_HWCFG0_NMRC_MASK                (0xFF0000U)
#define LPE_XRDC_HWCFG0_NMRC_SHIFT               (16U)
#define LPE_XRDC_HWCFG0_NMRC_WIDTH               (8U)
#define LPE_XRDC_HWCFG0_NMRC(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG0_NMRC_SHIFT)) & LPE_XRDC_HWCFG0_NMRC_MASK)

#define LPE_XRDC_HWCFG0_NPAC_MASK                (0xF000000U)
#define LPE_XRDC_HWCFG0_NPAC_SHIFT               (24U)
#define LPE_XRDC_HWCFG0_NPAC_WIDTH               (4U)
#define LPE_XRDC_HWCFG0_NPAC(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG0_NPAC_SHIFT)) & LPE_XRDC_HWCFG0_NPAC_MASK)

#define LPE_XRDC_HWCFG0_MID_MASK                 (0xF0000000U)
#define LPE_XRDC_HWCFG0_MID_SHIFT                (28U)
#define LPE_XRDC_HWCFG0_MID_WIDTH                (4U)
#define LPE_XRDC_HWCFG0_MID(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG0_MID_SHIFT)) & LPE_XRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define LPE_XRDC_HWCFG1_DID_MASK                 (0xFU)
#define LPE_XRDC_HWCFG1_DID_SHIFT                (0U)
#define LPE_XRDC_HWCFG1_DID_WIDTH                (4U)
#define LPE_XRDC_HWCFG1_DID(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG1_DID_SHIFT)) & LPE_XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name HWCFG2 - Hardware Configuration 2 */
/*! @{ */

#define LPE_XRDC_HWCFG2_PIDP0_MASK               (0x1U)
#define LPE_XRDC_HWCFG2_PIDP0_SHIFT              (0U)
#define LPE_XRDC_HWCFG2_PIDP0_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP0(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP0_SHIFT)) & LPE_XRDC_HWCFG2_PIDP0_MASK)

#define LPE_XRDC_HWCFG2_PIDP1_MASK               (0x2U)
#define LPE_XRDC_HWCFG2_PIDP1_SHIFT              (1U)
#define LPE_XRDC_HWCFG2_PIDP1_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP1(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP1_SHIFT)) & LPE_XRDC_HWCFG2_PIDP1_MASK)

#define LPE_XRDC_HWCFG2_PIDP2_MASK               (0x4U)
#define LPE_XRDC_HWCFG2_PIDP2_SHIFT              (2U)
#define LPE_XRDC_HWCFG2_PIDP2_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP2(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP2_SHIFT)) & LPE_XRDC_HWCFG2_PIDP2_MASK)

#define LPE_XRDC_HWCFG2_PIDP3_MASK               (0x8U)
#define LPE_XRDC_HWCFG2_PIDP3_SHIFT              (3U)
#define LPE_XRDC_HWCFG2_PIDP3_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP3(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP3_SHIFT)) & LPE_XRDC_HWCFG2_PIDP3_MASK)

#define LPE_XRDC_HWCFG2_PIDP4_MASK               (0x10U)
#define LPE_XRDC_HWCFG2_PIDP4_SHIFT              (4U)
#define LPE_XRDC_HWCFG2_PIDP4_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP4(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP4_SHIFT)) & LPE_XRDC_HWCFG2_PIDP4_MASK)

#define LPE_XRDC_HWCFG2_PIDP5_MASK               (0x20U)
#define LPE_XRDC_HWCFG2_PIDP5_SHIFT              (5U)
#define LPE_XRDC_HWCFG2_PIDP5_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP5(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP5_SHIFT)) & LPE_XRDC_HWCFG2_PIDP5_MASK)

#define LPE_XRDC_HWCFG2_PIDP6_MASK               (0x40U)
#define LPE_XRDC_HWCFG2_PIDP6_SHIFT              (6U)
#define LPE_XRDC_HWCFG2_PIDP6_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP6(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP6_SHIFT)) & LPE_XRDC_HWCFG2_PIDP6_MASK)

#define LPE_XRDC_HWCFG2_PIDP7_MASK               (0x80U)
#define LPE_XRDC_HWCFG2_PIDP7_SHIFT              (7U)
#define LPE_XRDC_HWCFG2_PIDP7_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP7(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP7_SHIFT)) & LPE_XRDC_HWCFG2_PIDP7_MASK)

#define LPE_XRDC_HWCFG2_PIDP8_MASK               (0x100U)
#define LPE_XRDC_HWCFG2_PIDP8_SHIFT              (8U)
#define LPE_XRDC_HWCFG2_PIDP8_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP8(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP8_SHIFT)) & LPE_XRDC_HWCFG2_PIDP8_MASK)

#define LPE_XRDC_HWCFG2_PIDP9_MASK               (0x200U)
#define LPE_XRDC_HWCFG2_PIDP9_SHIFT              (9U)
#define LPE_XRDC_HWCFG2_PIDP9_WIDTH              (1U)
#define LPE_XRDC_HWCFG2_PIDP9(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP9_SHIFT)) & LPE_XRDC_HWCFG2_PIDP9_MASK)

#define LPE_XRDC_HWCFG2_PIDP10_MASK              (0x400U)
#define LPE_XRDC_HWCFG2_PIDP10_SHIFT             (10U)
#define LPE_XRDC_HWCFG2_PIDP10_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP10(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP10_SHIFT)) & LPE_XRDC_HWCFG2_PIDP10_MASK)

#define LPE_XRDC_HWCFG2_PIDP11_MASK              (0x800U)
#define LPE_XRDC_HWCFG2_PIDP11_SHIFT             (11U)
#define LPE_XRDC_HWCFG2_PIDP11_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP11(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP11_SHIFT)) & LPE_XRDC_HWCFG2_PIDP11_MASK)

#define LPE_XRDC_HWCFG2_PIDP12_MASK              (0x1000U)
#define LPE_XRDC_HWCFG2_PIDP12_SHIFT             (12U)
#define LPE_XRDC_HWCFG2_PIDP12_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP12(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP12_SHIFT)) & LPE_XRDC_HWCFG2_PIDP12_MASK)

#define LPE_XRDC_HWCFG2_PIDP13_MASK              (0x2000U)
#define LPE_XRDC_HWCFG2_PIDP13_SHIFT             (13U)
#define LPE_XRDC_HWCFG2_PIDP13_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP13(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP13_SHIFT)) & LPE_XRDC_HWCFG2_PIDP13_MASK)

#define LPE_XRDC_HWCFG2_PIDP14_MASK              (0x4000U)
#define LPE_XRDC_HWCFG2_PIDP14_SHIFT             (14U)
#define LPE_XRDC_HWCFG2_PIDP14_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP14(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP14_SHIFT)) & LPE_XRDC_HWCFG2_PIDP14_MASK)

#define LPE_XRDC_HWCFG2_PIDP15_MASK              (0x8000U)
#define LPE_XRDC_HWCFG2_PIDP15_SHIFT             (15U)
#define LPE_XRDC_HWCFG2_PIDP15_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP15(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP15_SHIFT)) & LPE_XRDC_HWCFG2_PIDP15_MASK)

#define LPE_XRDC_HWCFG2_PIDP16_MASK              (0x10000U)
#define LPE_XRDC_HWCFG2_PIDP16_SHIFT             (16U)
#define LPE_XRDC_HWCFG2_PIDP16_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP16(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP16_SHIFT)) & LPE_XRDC_HWCFG2_PIDP16_MASK)

#define LPE_XRDC_HWCFG2_PIDP17_MASK              (0x20000U)
#define LPE_XRDC_HWCFG2_PIDP17_SHIFT             (17U)
#define LPE_XRDC_HWCFG2_PIDP17_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP17(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP17_SHIFT)) & LPE_XRDC_HWCFG2_PIDP17_MASK)

#define LPE_XRDC_HWCFG2_PIDP18_MASK              (0x40000U)
#define LPE_XRDC_HWCFG2_PIDP18_SHIFT             (18U)
#define LPE_XRDC_HWCFG2_PIDP18_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP18(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP18_SHIFT)) & LPE_XRDC_HWCFG2_PIDP18_MASK)

#define LPE_XRDC_HWCFG2_PIDP19_MASK              (0x80000U)
#define LPE_XRDC_HWCFG2_PIDP19_SHIFT             (19U)
#define LPE_XRDC_HWCFG2_PIDP19_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP19(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP19_SHIFT)) & LPE_XRDC_HWCFG2_PIDP19_MASK)

#define LPE_XRDC_HWCFG2_PIDP20_MASK              (0x100000U)
#define LPE_XRDC_HWCFG2_PIDP20_SHIFT             (20U)
#define LPE_XRDC_HWCFG2_PIDP20_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP20(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP20_SHIFT)) & LPE_XRDC_HWCFG2_PIDP20_MASK)

#define LPE_XRDC_HWCFG2_PIDP21_MASK              (0x200000U)
#define LPE_XRDC_HWCFG2_PIDP21_SHIFT             (21U)
#define LPE_XRDC_HWCFG2_PIDP21_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP21(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP21_SHIFT)) & LPE_XRDC_HWCFG2_PIDP21_MASK)

#define LPE_XRDC_HWCFG2_PIDP22_MASK              (0x400000U)
#define LPE_XRDC_HWCFG2_PIDP22_SHIFT             (22U)
#define LPE_XRDC_HWCFG2_PIDP22_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP22(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP22_SHIFT)) & LPE_XRDC_HWCFG2_PIDP22_MASK)

#define LPE_XRDC_HWCFG2_PIDP23_MASK              (0x800000U)
#define LPE_XRDC_HWCFG2_PIDP23_SHIFT             (23U)
#define LPE_XRDC_HWCFG2_PIDP23_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP23(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP23_SHIFT)) & LPE_XRDC_HWCFG2_PIDP23_MASK)

#define LPE_XRDC_HWCFG2_PIDP24_MASK              (0x1000000U)
#define LPE_XRDC_HWCFG2_PIDP24_SHIFT             (24U)
#define LPE_XRDC_HWCFG2_PIDP24_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP24(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP24_SHIFT)) & LPE_XRDC_HWCFG2_PIDP24_MASK)

#define LPE_XRDC_HWCFG2_PIDP25_MASK              (0x2000000U)
#define LPE_XRDC_HWCFG2_PIDP25_SHIFT             (25U)
#define LPE_XRDC_HWCFG2_PIDP25_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP25(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP25_SHIFT)) & LPE_XRDC_HWCFG2_PIDP25_MASK)

#define LPE_XRDC_HWCFG2_PIDP26_MASK              (0x4000000U)
#define LPE_XRDC_HWCFG2_PIDP26_SHIFT             (26U)
#define LPE_XRDC_HWCFG2_PIDP26_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP26(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP26_SHIFT)) & LPE_XRDC_HWCFG2_PIDP26_MASK)

#define LPE_XRDC_HWCFG2_PIDP27_MASK              (0x8000000U)
#define LPE_XRDC_HWCFG2_PIDP27_SHIFT             (27U)
#define LPE_XRDC_HWCFG2_PIDP27_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP27(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP27_SHIFT)) & LPE_XRDC_HWCFG2_PIDP27_MASK)

#define LPE_XRDC_HWCFG2_PIDP28_MASK              (0x10000000U)
#define LPE_XRDC_HWCFG2_PIDP28_SHIFT             (28U)
#define LPE_XRDC_HWCFG2_PIDP28_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP28(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP28_SHIFT)) & LPE_XRDC_HWCFG2_PIDP28_MASK)

#define LPE_XRDC_HWCFG2_PIDP29_MASK              (0x20000000U)
#define LPE_XRDC_HWCFG2_PIDP29_SHIFT             (29U)
#define LPE_XRDC_HWCFG2_PIDP29_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP29(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP29_SHIFT)) & LPE_XRDC_HWCFG2_PIDP29_MASK)

#define LPE_XRDC_HWCFG2_PIDP30_MASK              (0x40000000U)
#define LPE_XRDC_HWCFG2_PIDP30_SHIFT             (30U)
#define LPE_XRDC_HWCFG2_PIDP30_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP30(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP30_SHIFT)) & LPE_XRDC_HWCFG2_PIDP30_MASK)

#define LPE_XRDC_HWCFG2_PIDP31_MASK              (0x80000000U)
#define LPE_XRDC_HWCFG2_PIDP31_SHIFT             (31U)
#define LPE_XRDC_HWCFG2_PIDP31_WIDTH             (1U)
#define LPE_XRDC_HWCFG2_PIDP31(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_HWCFG2_PIDP31_SHIFT)) & LPE_XRDC_HWCFG2_PIDP31_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define LPE_XRDC_MDACFG_NMDAR_MASK               (0xFU)
#define LPE_XRDC_MDACFG_NMDAR_SHIFT              (0U)
#define LPE_XRDC_MDACFG_NMDAR_WIDTH              (4U)
#define LPE_XRDC_MDACFG_NMDAR(x)                 (((uint8_t)(((uint8_t)(x)) << LPE_XRDC_MDACFG_NMDAR_SHIFT)) & LPE_XRDC_MDACFG_NMDAR_MASK)

#define LPE_XRDC_MDACFG_NCM_MASK                 (0x80U)
#define LPE_XRDC_MDACFG_NCM_SHIFT                (7U)
#define LPE_XRDC_MDACFG_NCM_WIDTH                (1U)
#define LPE_XRDC_MDACFG_NCM(x)                   (((uint8_t)(((uint8_t)(x)) << LPE_XRDC_MDACFG_NCM_SHIFT)) & LPE_XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define LPE_XRDC_MRCFG_NMRGD_MASK                (0x1FU)
#define LPE_XRDC_MRCFG_NMRGD_SHIFT               (0U)
#define LPE_XRDC_MRCFG_NMRGD_WIDTH               (5U)
#define LPE_XRDC_MRCFG_NMRGD(x)                  (((uint8_t)(((uint8_t)(x)) << LPE_XRDC_MRCFG_NMRGD_SHIFT)) & LPE_XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define LPE_XRDC_DERRLOC_MRCINST_MASK            (0xFFFFU)
#define LPE_XRDC_DERRLOC_MRCINST_SHIFT           (0U)
#define LPE_XRDC_DERRLOC_MRCINST_WIDTH           (16U)
#define LPE_XRDC_DERRLOC_MRCINST(x)              (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERRLOC_MRCINST_SHIFT)) & LPE_XRDC_DERRLOC_MRCINST_MASK)

#define LPE_XRDC_DERRLOC_PACINST_MASK            (0xF0000U)
#define LPE_XRDC_DERRLOC_PACINST_SHIFT           (16U)
#define LPE_XRDC_DERRLOC_PACINST_WIDTH           (4U)
#define LPE_XRDC_DERRLOC_PACINST(x)              (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERRLOC_PACINST_SHIFT)) & LPE_XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W0 - Domain Error Word 0 */
/*! @{ */

#define LPE_XRDC_DERR_W0_EADDR_MASK              (0xFFFFFFFFU)
#define LPE_XRDC_DERR_W0_EADDR_SHIFT             (0U)
#define LPE_XRDC_DERR_W0_EADDR_WIDTH             (32U)
#define LPE_XRDC_DERR_W0_EADDR(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W0_EADDR_SHIFT)) & LPE_XRDC_DERR_W0_EADDR_MASK)
/*! @} */

/*! @name DERR_W1 - Domain Error Word 1 */
/*! @{ */

#define LPE_XRDC_DERR_W1_EDID_MASK               (0xFU)
#define LPE_XRDC_DERR_W1_EDID_SHIFT              (0U)
#define LPE_XRDC_DERR_W1_EDID_WIDTH              (4U)
#define LPE_XRDC_DERR_W1_EDID(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W1_EDID_SHIFT)) & LPE_XRDC_DERR_W1_EDID_MASK)

#define LPE_XRDC_DERR_W1_EATR_MASK               (0x700U)
#define LPE_XRDC_DERR_W1_EATR_SHIFT              (8U)
#define LPE_XRDC_DERR_W1_EATR_WIDTH              (3U)
#define LPE_XRDC_DERR_W1_EATR(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W1_EATR_SHIFT)) & LPE_XRDC_DERR_W1_EATR_MASK)

#define LPE_XRDC_DERR_W1_ERW_MASK                (0x800U)
#define LPE_XRDC_DERR_W1_ERW_SHIFT               (11U)
#define LPE_XRDC_DERR_W1_ERW_WIDTH               (1U)
#define LPE_XRDC_DERR_W1_ERW(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W1_ERW_SHIFT)) & LPE_XRDC_DERR_W1_ERW_MASK)

#define LPE_XRDC_DERR_W1_EPORT_MASK              (0x7000000U)
#define LPE_XRDC_DERR_W1_EPORT_SHIFT             (24U)
#define LPE_XRDC_DERR_W1_EPORT_WIDTH             (3U)
#define LPE_XRDC_DERR_W1_EPORT(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W1_EPORT_SHIFT)) & LPE_XRDC_DERR_W1_EPORT_MASK)

#define LPE_XRDC_DERR_W1_EST_MASK                (0xC0000000U)
#define LPE_XRDC_DERR_W1_EST_SHIFT               (30U)
#define LPE_XRDC_DERR_W1_EST_WIDTH               (2U)
#define LPE_XRDC_DERR_W1_EST(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W1_EST_SHIFT)) & LPE_XRDC_DERR_W1_EST_MASK)
/*! @} */

/*! @name DERR_W3 - Domain Error Word 3 */
/*! @{ */

#define LPE_XRDC_DERR_W3_RECR_MASK               (0xC0000000U)
#define LPE_XRDC_DERR_W3_RECR_SHIFT              (30U)
#define LPE_XRDC_DERR_W3_RECR_WIDTH              (2U)
#define LPE_XRDC_DERR_W3_RECR(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_DERR_W3_RECR_SHIFT)) & LPE_XRDC_DERR_W3_RECR_MASK)
/*! @} */

/*! @name PID - Process Identifier */
/*! @{ */

#define LPE_XRDC_PID_PID_MASK                    (0x3FU)
#define LPE_XRDC_PID_PID_SHIFT                   (0U)
#define LPE_XRDC_PID_PID_WIDTH                   (6U)
#define LPE_XRDC_PID_PID(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PID_PID_SHIFT)) & LPE_XRDC_PID_PID_MASK)

#define LPE_XRDC_PID_TSM_MASK                    (0x10000000U)
#define LPE_XRDC_PID_TSM_SHIFT                   (28U)
#define LPE_XRDC_PID_TSM_WIDTH                   (1U)
#define LPE_XRDC_PID_TSM(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PID_TSM_SHIFT)) & LPE_XRDC_PID_TSM_MASK)

#define LPE_XRDC_PID_LK2_MASK                    (0x60000000U)
#define LPE_XRDC_PID_LK2_SHIFT                   (29U)
#define LPE_XRDC_PID_LK2_WIDTH                   (2U)
#define LPE_XRDC_PID_LK2(x)                      (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PID_LK2_SHIFT)) & LPE_XRDC_PID_LK2_MASK)
/*! @} */

/*! @name MDA_W0_0_DFMT0 - Master Domain Assignment */
/*! @{ */

#define LPE_XRDC_MDA_W0_0_DFMT0_DID_MASK         (0xFU)
#define LPE_XRDC_MDA_W0_0_DFMT0_DID_SHIFT        (0U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DID_WIDTH        (4U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_DID_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_DID_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_DIDS_MASK        (0x30U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DIDS_SHIFT       (4U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DIDS_WIDTH       (2U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DIDS(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_DIDS_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_DIDS_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_PE_MASK          (0xC0U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PE_SHIFT         (6U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PE_WIDTH         (2U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_PE_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_PE_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_PIDM_MASK        (0x3F00U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PIDM_SHIFT       (8U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PIDM_WIDTH       (6U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PIDM(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_PIDM_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_PIDM_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_PID_MASK         (0x3F0000U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PID_SHIFT        (16U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PID_WIDTH        (6U)
#define LPE_XRDC_MDA_W0_0_DFMT0_PID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_PID_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_PID_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_DFMT_MASK        (0x20000000U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DFMT_SHIFT       (29U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DFMT_WIDTH       (1U)
#define LPE_XRDC_MDA_W0_0_DFMT0_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_DFMT_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_DFMT_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_LK1_MASK         (0x40000000U)
#define LPE_XRDC_MDA_W0_0_DFMT0_LK1_SHIFT        (30U)
#define LPE_XRDC_MDA_W0_0_DFMT0_LK1_WIDTH        (1U)
#define LPE_XRDC_MDA_W0_0_DFMT0_LK1(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_LK1_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_LK1_MASK)

#define LPE_XRDC_MDA_W0_0_DFMT0_VLD_MASK         (0x80000000U)
#define LPE_XRDC_MDA_W0_0_DFMT0_VLD_SHIFT        (31U)
#define LPE_XRDC_MDA_W0_0_DFMT0_VLD_WIDTH        (1U)
#define LPE_XRDC_MDA_W0_0_DFMT0_VLD(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_0_DFMT0_VLD_SHIFT)) & LPE_XRDC_MDA_W0_0_DFMT0_VLD_MASK)
/*! @} */

/*! @name MDA_W1_0_DFMT0 - Master Domain Assignment */
/*! @{ */

#define LPE_XRDC_MDA_W1_0_DFMT0_DID_MASK         (0xFU)
#define LPE_XRDC_MDA_W1_0_DFMT0_DID_SHIFT        (0U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DID_WIDTH        (4U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_DID_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_DID_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_DIDS_MASK        (0x30U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DIDS_SHIFT       (4U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DIDS_WIDTH       (2U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DIDS(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_DIDS_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_DIDS_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_PE_MASK          (0xC0U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PE_SHIFT         (6U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PE_WIDTH         (2U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_PE_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_PE_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_PIDM_MASK        (0x3F00U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PIDM_SHIFT       (8U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PIDM_WIDTH       (6U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PIDM(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_PIDM_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_PIDM_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_PID_MASK         (0x3F0000U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PID_SHIFT        (16U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PID_WIDTH        (6U)
#define LPE_XRDC_MDA_W1_0_DFMT0_PID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_PID_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_PID_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_DFMT_MASK        (0x20000000U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DFMT_SHIFT       (29U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DFMT_WIDTH       (1U)
#define LPE_XRDC_MDA_W1_0_DFMT0_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_DFMT_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_DFMT_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_LK1_MASK         (0x40000000U)
#define LPE_XRDC_MDA_W1_0_DFMT0_LK1_SHIFT        (30U)
#define LPE_XRDC_MDA_W1_0_DFMT0_LK1_WIDTH        (1U)
#define LPE_XRDC_MDA_W1_0_DFMT0_LK1(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_LK1_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_LK1_MASK)

#define LPE_XRDC_MDA_W1_0_DFMT0_VLD_MASK         (0x80000000U)
#define LPE_XRDC_MDA_W1_0_DFMT0_VLD_SHIFT        (31U)
#define LPE_XRDC_MDA_W1_0_DFMT0_VLD_WIDTH        (1U)
#define LPE_XRDC_MDA_W1_0_DFMT0_VLD(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W1_0_DFMT0_VLD_SHIFT)) & LPE_XRDC_MDA_W1_0_DFMT0_VLD_MASK)
/*! @} */

/*! @name MDA_W2_0_DFMT0 - Master Domain Assignment */
/*! @{ */

#define LPE_XRDC_MDA_W2_0_DFMT0_DID_MASK         (0xFU)
#define LPE_XRDC_MDA_W2_0_DFMT0_DID_SHIFT        (0U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DID_WIDTH        (4U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_DID_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_DID_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_DIDS_MASK        (0x30U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DIDS_SHIFT       (4U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DIDS_WIDTH       (2U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DIDS(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_DIDS_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_DIDS_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_PE_MASK          (0xC0U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PE_SHIFT         (6U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PE_WIDTH         (2U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_PE_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_PE_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_PIDM_MASK        (0x3F00U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PIDM_SHIFT       (8U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PIDM_WIDTH       (6U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PIDM(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_PIDM_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_PIDM_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_PID_MASK         (0x3F0000U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PID_SHIFT        (16U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PID_WIDTH        (6U)
#define LPE_XRDC_MDA_W2_0_DFMT0_PID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_PID_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_PID_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_DFMT_MASK        (0x20000000U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DFMT_SHIFT       (29U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DFMT_WIDTH       (1U)
#define LPE_XRDC_MDA_W2_0_DFMT0_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_DFMT_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_DFMT_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_LK1_MASK         (0x40000000U)
#define LPE_XRDC_MDA_W2_0_DFMT0_LK1_SHIFT        (30U)
#define LPE_XRDC_MDA_W2_0_DFMT0_LK1_WIDTH        (1U)
#define LPE_XRDC_MDA_W2_0_DFMT0_LK1(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_LK1_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_LK1_MASK)

#define LPE_XRDC_MDA_W2_0_DFMT0_VLD_MASK         (0x80000000U)
#define LPE_XRDC_MDA_W2_0_DFMT0_VLD_SHIFT        (31U)
#define LPE_XRDC_MDA_W2_0_DFMT0_VLD_WIDTH        (1U)
#define LPE_XRDC_MDA_W2_0_DFMT0_VLD(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W2_0_DFMT0_VLD_SHIFT)) & LPE_XRDC_MDA_W2_0_DFMT0_VLD_MASK)
/*! @} */

/*! @name MDA_W3_0_DFMT0 - Master Domain Assignment */
/*! @{ */

#define LPE_XRDC_MDA_W3_0_DFMT0_DID_MASK         (0xFU)
#define LPE_XRDC_MDA_W3_0_DFMT0_DID_SHIFT        (0U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DID_WIDTH        (4U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_DID_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_DID_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_DIDS_MASK        (0x30U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DIDS_SHIFT       (4U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DIDS_WIDTH       (2U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DIDS(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_DIDS_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_DIDS_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_PE_MASK          (0xC0U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PE_SHIFT         (6U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PE_WIDTH         (2U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PE(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_PE_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_PE_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_PIDM_MASK        (0x3F00U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PIDM_SHIFT       (8U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PIDM_WIDTH       (6U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PIDM(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_PIDM_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_PIDM_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_PID_MASK         (0x3F0000U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PID_SHIFT        (16U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PID_WIDTH        (6U)
#define LPE_XRDC_MDA_W3_0_DFMT0_PID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_PID_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_PID_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_DFMT_MASK        (0x20000000U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DFMT_SHIFT       (29U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DFMT_WIDTH       (1U)
#define LPE_XRDC_MDA_W3_0_DFMT0_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_DFMT_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_DFMT_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_LK1_MASK         (0x40000000U)
#define LPE_XRDC_MDA_W3_0_DFMT0_LK1_SHIFT        (30U)
#define LPE_XRDC_MDA_W3_0_DFMT0_LK1_WIDTH        (1U)
#define LPE_XRDC_MDA_W3_0_DFMT0_LK1(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_LK1_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_LK1_MASK)

#define LPE_XRDC_MDA_W3_0_DFMT0_VLD_MASK         (0x80000000U)
#define LPE_XRDC_MDA_W3_0_DFMT0_VLD_SHIFT        (31U)
#define LPE_XRDC_MDA_W3_0_DFMT0_VLD_WIDTH        (1U)
#define LPE_XRDC_MDA_W3_0_DFMT0_VLD(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W3_0_DFMT0_VLD_SHIFT)) & LPE_XRDC_MDA_W3_0_DFMT0_VLD_MASK)
/*! @} */

/*! @name MDA_W0_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define LPE_XRDC_MDA_W0_1_DFMT1_DID_MASK         (0xFU)
#define LPE_XRDC_MDA_W0_1_DFMT1_DID_SHIFT        (0U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DID_WIDTH        (4U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_DID_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_DID_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_PA_MASK          (0x30U)
#define LPE_XRDC_MDA_W0_1_DFMT1_PA_SHIFT         (4U)
#define LPE_XRDC_MDA_W0_1_DFMT1_PA_WIDTH         (2U)
#define LPE_XRDC_MDA_W0_1_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_PA_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_PA_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_SA_MASK          (0xC0U)
#define LPE_XRDC_MDA_W0_1_DFMT1_SA_SHIFT         (6U)
#define LPE_XRDC_MDA_W0_1_DFMT1_SA_WIDTH         (2U)
#define LPE_XRDC_MDA_W0_1_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_SA_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_SA_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_DIDB_MASK        (0x100U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT       (8U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DIDB_WIDTH       (1U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_DIDB_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_DFMT_MASK        (0x20000000U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT       (29U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DFMT_WIDTH       (1U)
#define LPE_XRDC_MDA_W0_1_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_DFMT_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_LK1_MASK         (0x40000000U)
#define LPE_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT        (30U)
#define LPE_XRDC_MDA_W0_1_DFMT1_LK1_WIDTH        (1U)
#define LPE_XRDC_MDA_W0_1_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_LK1_MASK)

#define LPE_XRDC_MDA_W0_1_DFMT1_VLD_MASK         (0x80000000U)
#define LPE_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT        (31U)
#define LPE_XRDC_MDA_W0_1_DFMT1_VLD_WIDTH        (1U)
#define LPE_XRDC_MDA_W0_1_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT)) & LPE_XRDC_MDA_W0_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define LPE_XRDC_PDAC_W0_D0ACP_MASK              (0x7U)
#define LPE_XRDC_PDAC_W0_D0ACP_SHIFT             (0U)
#define LPE_XRDC_PDAC_W0_D0ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D0ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D0ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D0ACP_MASK)

#define LPE_XRDC_PDAC_W0_D1ACP_MASK              (0x38U)
#define LPE_XRDC_PDAC_W0_D1ACP_SHIFT             (3U)
#define LPE_XRDC_PDAC_W0_D1ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D1ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D1ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D1ACP_MASK)

#define LPE_XRDC_PDAC_W0_D2ACP_MASK              (0x1C0U)
#define LPE_XRDC_PDAC_W0_D2ACP_SHIFT             (6U)
#define LPE_XRDC_PDAC_W0_D2ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D2ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D2ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D2ACP_MASK)

#define LPE_XRDC_PDAC_W0_D3ACP_MASK              (0xE00U)
#define LPE_XRDC_PDAC_W0_D3ACP_SHIFT             (9U)
#define LPE_XRDC_PDAC_W0_D3ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D3ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D3ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D3ACP_MASK)

#define LPE_XRDC_PDAC_W0_D4ACP_MASK              (0x7000U)
#define LPE_XRDC_PDAC_W0_D4ACP_SHIFT             (12U)
#define LPE_XRDC_PDAC_W0_D4ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D4ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D4ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D4ACP_MASK)

#define LPE_XRDC_PDAC_W0_D5ACP_MASK              (0x38000U)
#define LPE_XRDC_PDAC_W0_D5ACP_SHIFT             (15U)
#define LPE_XRDC_PDAC_W0_D5ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D5ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D5ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D5ACP_MASK)

#define LPE_XRDC_PDAC_W0_D6ACP_MASK              (0x1C0000U)
#define LPE_XRDC_PDAC_W0_D6ACP_SHIFT             (18U)
#define LPE_XRDC_PDAC_W0_D6ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D6ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D6ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D6ACP_MASK)

#define LPE_XRDC_PDAC_W0_D7ACP_MASK              (0xE00000U)
#define LPE_XRDC_PDAC_W0_D7ACP_SHIFT             (21U)
#define LPE_XRDC_PDAC_W0_D7ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W0_D7ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_D7ACP_SHIFT)) & LPE_XRDC_PDAC_W0_D7ACP_MASK)

#define LPE_XRDC_PDAC_W0_SNUM_MASK               (0xF000000U)
#define LPE_XRDC_PDAC_W0_SNUM_SHIFT              (24U)
#define LPE_XRDC_PDAC_W0_SNUM_WIDTH              (4U)
#define LPE_XRDC_PDAC_W0_SNUM(x)                 (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_SNUM_SHIFT)) & LPE_XRDC_PDAC_W0_SNUM_MASK)

#define LPE_XRDC_PDAC_W0_SE_MASK                 (0x40000000U)
#define LPE_XRDC_PDAC_W0_SE_SHIFT                (30U)
#define LPE_XRDC_PDAC_W0_SE_WIDTH                (1U)
#define LPE_XRDC_PDAC_W0_SE(x)                   (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W0_SE_SHIFT)) & LPE_XRDC_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define LPE_XRDC_PDAC_W1_D8ACP_MASK              (0x7U)
#define LPE_XRDC_PDAC_W1_D8ACP_SHIFT             (0U)
#define LPE_XRDC_PDAC_W1_D8ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W1_D8ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D8ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D8ACP_MASK)

#define LPE_XRDC_PDAC_W1_D9ACP_MASK              (0x38U)
#define LPE_XRDC_PDAC_W1_D9ACP_SHIFT             (3U)
#define LPE_XRDC_PDAC_W1_D9ACP_WIDTH             (3U)
#define LPE_XRDC_PDAC_W1_D9ACP(x)                (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D9ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D9ACP_MASK)

#define LPE_XRDC_PDAC_W1_D10ACP_MASK             (0x1C0U)
#define LPE_XRDC_PDAC_W1_D10ACP_SHIFT            (6U)
#define LPE_XRDC_PDAC_W1_D10ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D10ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D10ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D10ACP_MASK)

#define LPE_XRDC_PDAC_W1_D11ACP_MASK             (0xE00U)
#define LPE_XRDC_PDAC_W1_D11ACP_SHIFT            (9U)
#define LPE_XRDC_PDAC_W1_D11ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D11ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D11ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D11ACP_MASK)

#define LPE_XRDC_PDAC_W1_D12ACP_MASK             (0x7000U)
#define LPE_XRDC_PDAC_W1_D12ACP_SHIFT            (12U)
#define LPE_XRDC_PDAC_W1_D12ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D12ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D12ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D12ACP_MASK)

#define LPE_XRDC_PDAC_W1_D13ACP_MASK             (0x38000U)
#define LPE_XRDC_PDAC_W1_D13ACP_SHIFT            (15U)
#define LPE_XRDC_PDAC_W1_D13ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D13ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D13ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D13ACP_MASK)

#define LPE_XRDC_PDAC_W1_D14ACP_MASK             (0x1C0000U)
#define LPE_XRDC_PDAC_W1_D14ACP_SHIFT            (18U)
#define LPE_XRDC_PDAC_W1_D14ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D14ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D14ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D14ACP_MASK)

#define LPE_XRDC_PDAC_W1_D15ACP_MASK             (0xE00000U)
#define LPE_XRDC_PDAC_W1_D15ACP_SHIFT            (21U)
#define LPE_XRDC_PDAC_W1_D15ACP_WIDTH            (3U)
#define LPE_XRDC_PDAC_W1_D15ACP(x)               (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_D15ACP_SHIFT)) & LPE_XRDC_PDAC_W1_D15ACP_MASK)

#define LPE_XRDC_PDAC_W1_LK2_MASK                (0x60000000U)
#define LPE_XRDC_PDAC_W1_LK2_SHIFT               (29U)
#define LPE_XRDC_PDAC_W1_LK2_WIDTH               (2U)
#define LPE_XRDC_PDAC_W1_LK2(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_LK2_SHIFT)) & LPE_XRDC_PDAC_W1_LK2_MASK)

#define LPE_XRDC_PDAC_W1_VLD_MASK                (0x80000000U)
#define LPE_XRDC_PDAC_W1_VLD_SHIFT               (31U)
#define LPE_XRDC_PDAC_W1_VLD_WIDTH               (1U)
#define LPE_XRDC_PDAC_W1_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_PDAC_W1_VLD_SHIFT)) & LPE_XRDC_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name XRDC_MRGD_W0 - Memory Region Descriptor Word 0 */
/*! @{ */

#define LPE_XRDC_XRDC_MRGD_W0_SRTADDR_MASK       (0xFFFFFFE0U)
#define LPE_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT      (5U)
#define LPE_XRDC_XRDC_MRGD_W0_SRTADDR_WIDTH      (27U)
#define LPE_XRDC_XRDC_MRGD_W0_SRTADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT)) & LPE_XRDC_XRDC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W1 - Memory Region Descriptor Word 1 */
/*! @{ */

#define LPE_XRDC_XRDC_MRGD_W1_ENDADDR_MASK       (0xFFFFFFE0U)
#define LPE_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT      (5U)
#define LPE_XRDC_XRDC_MRGD_W1_ENDADDR_WIDTH      (27U)
#define LPE_XRDC_XRDC_MRGD_W1_ENDADDR(x)         (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT)) & LPE_XRDC_XRDC_MRGD_W1_ENDADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W2 - Memory Region Descriptor Word 2 */
/*! @{ */

#define LPE_XRDC_XRDC_MRGD_W2_D0ACP_MASK         (0x7U)
#define LPE_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT        (0U)
#define LPE_XRDC_XRDC_MRGD_W2_D0ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D0ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D0ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D1ACP_MASK         (0x38U)
#define LPE_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D1ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D1ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D1ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D2ACP_MASK         (0x1C0U)
#define LPE_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT        (6U)
#define LPE_XRDC_XRDC_MRGD_W2_D2ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D2ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D2ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D3ACP_MASK         (0xE00U)
#define LPE_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT        (9U)
#define LPE_XRDC_XRDC_MRGD_W2_D3ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D3ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D3ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D4ACP_MASK         (0x7000U)
#define LPE_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT        (12U)
#define LPE_XRDC_XRDC_MRGD_W2_D4ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D4ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D4ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D5ACP_MASK         (0x38000U)
#define LPE_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT        (15U)
#define LPE_XRDC_XRDC_MRGD_W2_D5ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D5ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D5ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D6ACP_MASK         (0x1C0000U)
#define LPE_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT        (18U)
#define LPE_XRDC_XRDC_MRGD_W2_D6ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D6ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D6ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_D7ACP_MASK         (0xE00000U)
#define LPE_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT        (21U)
#define LPE_XRDC_XRDC_MRGD_W2_D7ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W2_D7ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_D7ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_SNUM_MASK          (0xF000000U)
#define LPE_XRDC_XRDC_MRGD_W2_SNUM_SHIFT         (24U)
#define LPE_XRDC_XRDC_MRGD_W2_SNUM_WIDTH         (4U)
#define LPE_XRDC_XRDC_MRGD_W2_SNUM(x)            (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_SNUM_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_SNUM_MASK)

#define LPE_XRDC_XRDC_MRGD_W2_SE_MASK            (0x40000000U)
#define LPE_XRDC_XRDC_MRGD_W2_SE_SHIFT           (30U)
#define LPE_XRDC_XRDC_MRGD_W2_SE_WIDTH           (1U)
#define LPE_XRDC_XRDC_MRGD_W2_SE(x)              (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W2_SE_SHIFT)) & LPE_XRDC_XRDC_MRGD_W2_SE_MASK)
/*! @} */

/*! @name XRDC_MRGD_W3 - Memory Region Descriptor Word 3 */
/*! @{ */

#define LPE_XRDC_XRDC_MRGD_W3_D8ACP_MASK         (0x7U)
#define LPE_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT        (0U)
#define LPE_XRDC_XRDC_MRGD_W3_D8ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D8ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D8ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D9ACP_MASK         (0x38U)
#define LPE_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT        (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D9ACP_WIDTH        (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D9ACP(x)           (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D9ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D10ACP_MASK        (0x1C0U)
#define LPE_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT       (6U)
#define LPE_XRDC_XRDC_MRGD_W3_D10ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D10ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D10ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D11ACP_MASK        (0xE00U)
#define LPE_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT       (9U)
#define LPE_XRDC_XRDC_MRGD_W3_D11ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D11ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D11ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D12ACP_MASK        (0x7000U)
#define LPE_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT       (12U)
#define LPE_XRDC_XRDC_MRGD_W3_D12ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D12ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D12ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D13ACP_MASK        (0x38000U)
#define LPE_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT       (15U)
#define LPE_XRDC_XRDC_MRGD_W3_D13ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D13ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D13ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D14ACP_MASK        (0x1C0000U)
#define LPE_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT       (18U)
#define LPE_XRDC_XRDC_MRGD_W3_D14ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D14ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D14ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_D15ACP_MASK        (0xE00000U)
#define LPE_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT       (21U)
#define LPE_XRDC_XRDC_MRGD_W3_D15ACP_WIDTH       (3U)
#define LPE_XRDC_XRDC_MRGD_W3_D15ACP(x)          (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_D15ACP_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_LK2_MASK           (0x60000000U)
#define LPE_XRDC_XRDC_MRGD_W3_LK2_SHIFT          (29U)
#define LPE_XRDC_XRDC_MRGD_W3_LK2_WIDTH          (2U)
#define LPE_XRDC_XRDC_MRGD_W3_LK2(x)             (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_LK2_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_LK2_MASK)

#define LPE_XRDC_XRDC_MRGD_W3_VLD_MASK           (0x80000000U)
#define LPE_XRDC_XRDC_MRGD_W3_VLD_SHIFT          (31U)
#define LPE_XRDC_XRDC_MRGD_W3_VLD_WIDTH          (1U)
#define LPE_XRDC_XRDC_MRGD_W3_VLD(x)             (((uint32_t)(((uint32_t)(x)) << LPE_XRDC_XRDC_MRGD_W3_VLD_SHIFT)) & LPE_XRDC_XRDC_MRGD_W3_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group LPE_XRDC_Register_Masks */

/*!
 * @}
 */ /* end of group LPE_XRDC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_LPE_XRDC_H_) */
