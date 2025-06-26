/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_XRDC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_XRDC
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
#if !defined(S32Z2_XRDC_H_)  /* Check if memory map has not been already included */
#define S32Z2_XRDC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- XRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_Peripheral_Access_Layer XRDC Peripheral Access Layer
 * @{
 */

/** XRDC - Size of Registers Arrays */
#define XRDC_MDAC_COUNT                           5u
#define XRDC_MRC_COUNT                            3u
#define XRDC_DERRLOC_COUNT                        16u
#define XRDC_DERRW0_COUNT                         20u
#define XRDC_PDAC_SLOT_PDACN_COUNT                127u
#define XRDC_PDAC_SLOT_COUNT                      4u
#define XRDC_MRCN_COUNT                           3u
#define XRDC_MRCN_MRGDN_COUNT                     16u

/** XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  uint8_t RESERVED_1[8];
  __I  uint8_t MDACFG[XRDC_MDAC_COUNT];            /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1, irregular array, not all indices are valid */
  uint8_t RESERVED_2[59];
  __I  uint8_t MRCFG[XRDC_MRC_COUNT];              /**< Memory Region Configuration, array offset: 0x140, array step: 0x1, irregular array, not all indices are valid */
  uint8_t RESERVED_3[189];
  __I  uint32_t DERRLOC[XRDC_DERRLOC_COUNT];       /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[448];
  struct XRDC_DERRW0 {                             /* offset: 0x400, array step: 0x10 */
    __I  uint32_t DERR_W0;                           /**< Domain Error Word 0, array offset: 0x400, array step: 0x10, irregular array, not all indices are valid */
    __I  uint32_t DERR_W1;                           /**< Domain Error Word 1, array offset: 0x404, array step: 0x10, irregular array, not all indices are valid */
    uint8_t RESERVED_0[4];
    __O  uint32_t DERR_W3;                           /**< Domain Error Word 3, array offset: 0x40C, array step: 0x10, irregular array, not all indices are valid */
  } DERRW0[XRDC_DERRW0_COUNT];
  uint8_t RESERVED_5[704];
  __IO uint32_t MDA_W0_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x800, available only on: CE_XRDC, XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_4, XRDC_5 (missing on XRDC_3B) */
  __IO uint32_t MDA_W1_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x804, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W2_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x808, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W3_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x80C, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W4_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x810, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W5_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x814, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W6_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x818, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W7_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x81C, available only on: CE_XRDC (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W0_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x820, available only on: CE_XRDC, XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_4, XRDC_5 (missing on XRDC_3B) */
  __IO uint32_t MDA_W1_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x824, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W2_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x828, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W3_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x82C, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W4_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x830, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W5_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x834, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W6_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x838, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W7_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x83C, available only on: XRDC_1, XRDC_3A (missing on CE_XRDC, XRDC_0, XRDC_2, XRDC_3B, XRDC_4, XRDC_5) */
  __IO uint32_t MDA_W0_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x840, available only on: CE_XRDC, XRDC_0, XRDC_1, XRDC_2, XRDC_3A, XRDC_4, XRDC_5 (missing on XRDC_3B) */
  __IO uint32_t MDA_W1_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x844, available only on: CE_XRDC, XRDC_0, XRDC_3A, XRDC_4 (missing on XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W2_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x848, available only on: CE_XRDC, XRDC_0, XRDC_3A, XRDC_4 (missing on XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W3_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x84C, available only on: CE_XRDC, XRDC_0, XRDC_3A, XRDC_4 (missing on XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W4_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x850, available only on: CE_XRDC, XRDC_3A, XRDC_4 (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W5_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x854, available only on: CE_XRDC, XRDC_3A, XRDC_4 (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W6_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x858, available only on: CE_XRDC, XRDC_3A, XRDC_4 (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W7_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x85C, available only on: CE_XRDC, XRDC_3A, XRDC_4 (missing on XRDC_0, XRDC_1, XRDC_2, XRDC_3B, XRDC_5) */
  __IO uint32_t MDA_W0_3_DFMT1;                    /**< Master Domain Assignment, offset: 0x860, available only on: XRDC_0, XRDC_1 (missing on CE_XRDC, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  uint8_t RESERVED_6[28];
  __IO uint32_t MDA_W0_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x880, available only on: XRDC_0, XRDC_1 (missing on CE_XRDC, XRDC_2, XRDC_3A, XRDC_3B, XRDC_4, XRDC_5) */
  uint8_t RESERVED_7[1916];
  struct XRDC_PDAC_SLOT {                          /* offset: 0x1000, array step: 0x400 */
    struct XRDC_PDAC_SLOT_PDACN {                    /* offset: 0x1000, array step: index*0x400, index2*0x8 */
      __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1000, array step: index*0x400, index2*0x8, irregular array, not all indices are valid */
      __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1004, array step: index*0x400, index2*0x8, irregular array, not all indices are valid */
    } PDACN[XRDC_PDAC_SLOT_PDACN_COUNT];
    uint8_t RESERVED_0[8];
  } PDAC_SLOT[XRDC_PDAC_SLOT_COUNT];
  struct XRDC_MRGDN {                              /* offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W0;                      /**< Memory Region Descriptor Word 0, array offset: 0x2000, array step: index*0x200, index2*0x20, irregular array, not all indices are valid */
    __IO uint32_t XRDC_MRGD_W1;                      /**< Memory Region Descriptor Word 1, array offset: 0x2004, array step: index*0x200, index2*0x20, irregular array, not all indices are valid */
    __IO uint32_t XRDC_MRGD_W2;                      /**< Memory Region Descriptor Word 2, array offset: 0x2008, array step: index*0x200, index2*0x20, irregular array, not all indices are valid */
    __IO uint32_t XRDC_MRGD_W3;                      /**< Memory Region Descriptor Word 3, array offset: 0x200C, array step: index*0x200, index2*0x20, irregular array, not all indices are valid */
    uint8_t RESERVED_0[16];
  } MRGDN[XRDC_MRCN_COUNT][XRDC_MRCN_MRGDN_COUNT];
} XRDC_Type, *XRDC_MemMapPtr;

/** Number of instances of the XRDC module. */
#define XRDC_INSTANCE_COUNT                      (8u)

/* XRDC - Peripheral instance base addresses */
/** Peripheral CE_XRDC base address */
#define IP_CE_XRDC_BASE                          (0x44800000u)
/** Peripheral CE_XRDC base pointer */
#define IP_CE_XRDC                               ((XRDC_Type *)IP_CE_XRDC_BASE)
/** Peripheral XRDC_0 base address */
#define IP_XRDC_0_BASE                           (0x40000000u)
/** Peripheral XRDC_0 base pointer */
#define IP_XRDC_0                                ((XRDC_Type *)IP_XRDC_0_BASE)
/** Peripheral XRDC_1 base address */
#define IP_XRDC_1_BASE                           (0x40800000u)
/** Peripheral XRDC_1 base pointer */
#define IP_XRDC_1                                ((XRDC_Type *)IP_XRDC_1_BASE)
/** Peripheral XRDC_2 base address */
#define IP_XRDC_2_BASE                           (0x41000000u)
/** Peripheral XRDC_2 base pointer */
#define IP_XRDC_2                                ((XRDC_Type *)IP_XRDC_2_BASE)
/** Peripheral XRDC_3A base address */
#define IP_XRDC_3A_BASE                          (0x41800000u)
/** Peripheral XRDC_3A base pointer */
#define IP_XRDC_3A                               ((XRDC_Type *)IP_XRDC_3A_BASE)
/** Peripheral XRDC_3B base address */
#define IP_XRDC_3B_BASE                          (0x419D0000u)
/** Peripheral XRDC_3B base pointer */
#define IP_XRDC_3B                               ((XRDC_Type *)IP_XRDC_3B_BASE)
/** Peripheral XRDC_4 base address */
#define IP_XRDC_4_BASE                           (0x42000000u)
/** Peripheral XRDC_4 base pointer */
#define IP_XRDC_4                                ((XRDC_Type *)IP_XRDC_4_BASE)
/** Peripheral XRDC_5 base address */
#define IP_XRDC_5_BASE                           (0x42800000u)
/** Peripheral XRDC_5 base pointer */
#define IP_XRDC_5                                ((XRDC_Type *)IP_XRDC_5_BASE)
/** Array initializer of XRDC peripheral base addresses */
#define IP_XRDC_BASE_ADDRS                       { IP_CE_XRDC_BASE, IP_XRDC_0_BASE, IP_XRDC_1_BASE, IP_XRDC_2_BASE, IP_XRDC_3A_BASE, IP_XRDC_3B_BASE, IP_XRDC_4_BASE, IP_XRDC_5_BASE }
/** Array initializer of XRDC peripheral base pointers */
#define IP_XRDC_BASE_PTRS                        { IP_CE_XRDC, IP_XRDC_0, IP_XRDC_1, IP_XRDC_2, IP_XRDC_3A, IP_XRDC_3B, IP_XRDC_4, IP_XRDC_5 }

/* ----------------------------------------------------------------------------
   -- XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XRDC_Register_Masks XRDC Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define XRDC_CR_GVLD_MASK                        (0x1U)
#define XRDC_CR_GVLD_SHIFT                       (0U)
#define XRDC_CR_GVLD_WIDTH                       (1U)
#define XRDC_CR_GVLD(x)                          (((uint32_t)(((uint32_t)(x)) << XRDC_CR_GVLD_SHIFT)) & XRDC_CR_GVLD_MASK)

#define XRDC_CR_HRL_MASK                         (0x1EU)
#define XRDC_CR_HRL_SHIFT                        (1U)
#define XRDC_CR_HRL_WIDTH                        (4U)
#define XRDC_CR_HRL(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_HRL_SHIFT)) & XRDC_CR_HRL_MASK)

#define XRDC_CR_MRF_MASK                         (0x80U)
#define XRDC_CR_MRF_SHIFT                        (7U)
#define XRDC_CR_MRF_WIDTH                        (1U)
#define XRDC_CR_MRF(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_MRF_SHIFT)) & XRDC_CR_MRF_MASK)

#define XRDC_CR_VAW_MASK                         (0x100U)
#define XRDC_CR_VAW_SHIFT                        (8U)
#define XRDC_CR_VAW_WIDTH                        (1U)
#define XRDC_CR_VAW(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_VAW_SHIFT)) & XRDC_CR_VAW_MASK)

#define XRDC_CR_LK1_MASK                         (0x40000000U)
#define XRDC_CR_LK1_SHIFT                        (30U)
#define XRDC_CR_LK1_WIDTH                        (1U)
#define XRDC_CR_LK1(x)                           (((uint32_t)(((uint32_t)(x)) << XRDC_CR_LK1_SHIFT)) & XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define XRDC_HWCFG0_NDID_MASK                    (0xFFU)
#define XRDC_HWCFG0_NDID_SHIFT                   (0U)
#define XRDC_HWCFG0_NDID_WIDTH                   (8U)
#define XRDC_HWCFG0_NDID(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NDID_SHIFT)) & XRDC_HWCFG0_NDID_MASK)

#define XRDC_HWCFG0_NMSTR_MASK                   (0xFF00U)
#define XRDC_HWCFG0_NMSTR_SHIFT                  (8U)
#define XRDC_HWCFG0_NMSTR_WIDTH                  (8U)
#define XRDC_HWCFG0_NMSTR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMSTR_SHIFT)) & XRDC_HWCFG0_NMSTR_MASK)

#define XRDC_HWCFG0_NMRC_MASK                    (0xFF0000U)
#define XRDC_HWCFG0_NMRC_SHIFT                   (16U)
#define XRDC_HWCFG0_NMRC_WIDTH                   (8U)
#define XRDC_HWCFG0_NMRC(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NMRC_SHIFT)) & XRDC_HWCFG0_NMRC_MASK)

#define XRDC_HWCFG0_NPAC_MASK                    (0xF000000U)
#define XRDC_HWCFG0_NPAC_SHIFT                   (24U)
#define XRDC_HWCFG0_NPAC_WIDTH                   (4U)
#define XRDC_HWCFG0_NPAC(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_NPAC_SHIFT)) & XRDC_HWCFG0_NPAC_MASK)

#define XRDC_HWCFG0_MID_MASK                     (0xF0000000U)
#define XRDC_HWCFG0_MID_SHIFT                    (28U)
#define XRDC_HWCFG0_MID_WIDTH                    (4U)
#define XRDC_HWCFG0_MID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG0_MID_SHIFT)) & XRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define XRDC_HWCFG1_DID_MASK                     (0xFU)
#define XRDC_HWCFG1_DID_SHIFT                    (0U)
#define XRDC_HWCFG1_DID_WIDTH                    (4U)
#define XRDC_HWCFG1_DID(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_HWCFG1_DID_SHIFT)) & XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define XRDC_MDACFG_NMDAR_MASK                   (0xFU)
#define XRDC_MDACFG_NMDAR_SHIFT                  (0U)
#define XRDC_MDACFG_NMDAR_WIDTH                  (4U)
#define XRDC_MDACFG_NMDAR(x)                     (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NMDAR_SHIFT)) & XRDC_MDACFG_NMDAR_MASK)

#define XRDC_MDACFG_NCM_MASK                     (0x80U)
#define XRDC_MDACFG_NCM_SHIFT                    (7U)
#define XRDC_MDACFG_NCM_WIDTH                    (1U)
#define XRDC_MDACFG_NCM(x)                       (((uint8_t)(((uint8_t)(x)) << XRDC_MDACFG_NCM_SHIFT)) & XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define XRDC_MRCFG_NMRGD_MASK                    (0x1FU)
#define XRDC_MRCFG_NMRGD_SHIFT                   (0U)
#define XRDC_MRCFG_NMRGD_WIDTH                   (5U)
#define XRDC_MRCFG_NMRGD(x)                      (((uint8_t)(((uint8_t)(x)) << XRDC_MRCFG_NMRGD_SHIFT)) & XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define XRDC_DERRLOC_MRCINST_MASK                (0xFFFFU)
#define XRDC_DERRLOC_MRCINST_SHIFT               (0U)
#define XRDC_DERRLOC_MRCINST_WIDTH               (16U)
#define XRDC_DERRLOC_MRCINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_MRCINST_SHIFT)) & XRDC_DERRLOC_MRCINST_MASK)

#define XRDC_DERRLOC_PACINST_MASK                (0xF0000U)
#define XRDC_DERRLOC_PACINST_SHIFT               (16U)
#define XRDC_DERRLOC_PACINST_WIDTH               (4U)
#define XRDC_DERRLOC_PACINST(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_DERRLOC_PACINST_SHIFT)) & XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W0 - Domain Error Word 0 */
/*! @{ */

#define XRDC_DERR_W0_EADDR_MASK                  (0xFFFFFFFFU)
#define XRDC_DERR_W0_EADDR_SHIFT                 (0U)
#define XRDC_DERR_W0_EADDR_WIDTH                 (32U)
#define XRDC_DERR_W0_EADDR(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W0_EADDR_SHIFT)) & XRDC_DERR_W0_EADDR_MASK)
/*! @} */

/*! @name DERR_W1 - Domain Error Word 1 */
/*! @{ */

#define XRDC_DERR_W1_EDID_MASK                   (0xFU)
#define XRDC_DERR_W1_EDID_SHIFT                  (0U)
#define XRDC_DERR_W1_EDID_WIDTH                  (4U)
#define XRDC_DERR_W1_EDID(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W1_EDID_SHIFT)) & XRDC_DERR_W1_EDID_MASK)

#define XRDC_DERR_W1_EATR_MASK                   (0x700U)
#define XRDC_DERR_W1_EATR_SHIFT                  (8U)
#define XRDC_DERR_W1_EATR_WIDTH                  (3U)
#define XRDC_DERR_W1_EATR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W1_EATR_SHIFT)) & XRDC_DERR_W1_EATR_MASK)

#define XRDC_DERR_W1_ERW_MASK                    (0x800U)
#define XRDC_DERR_W1_ERW_SHIFT                   (11U)
#define XRDC_DERR_W1_ERW_WIDTH                   (1U)
#define XRDC_DERR_W1_ERW(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W1_ERW_SHIFT)) & XRDC_DERR_W1_ERW_MASK)

#define XRDC_DERR_W1_EPORT_MASK                  (0x7000000U)
#define XRDC_DERR_W1_EPORT_SHIFT                 (24U)
#define XRDC_DERR_W1_EPORT_WIDTH                 (3U)
#define XRDC_DERR_W1_EPORT(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W1_EPORT_SHIFT)) & XRDC_DERR_W1_EPORT_MASK)

#define XRDC_DERR_W1_EST_MASK                    (0xC0000000U)
#define XRDC_DERR_W1_EST_SHIFT                   (30U)
#define XRDC_DERR_W1_EST_WIDTH                   (2U)
#define XRDC_DERR_W1_EST(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W1_EST_SHIFT)) & XRDC_DERR_W1_EST_MASK)
/*! @} */

/*! @name DERR_W3 - Domain Error Word 3 */
/*! @{ */

#define XRDC_DERR_W3_RECR_MASK                   (0xC0000000U)
#define XRDC_DERR_W3_RECR_SHIFT                  (30U)
#define XRDC_DERR_W3_RECR_WIDTH                  (2U)
#define XRDC_DERR_W3_RECR(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_DERR_W3_RECR_SHIFT)) & XRDC_DERR_W3_RECR_MASK)
/*! @} */

/*! @name MDA_W0_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W0_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W0_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W0_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W0_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W0_0_DFMT1_DID_MASK)

#define XRDC_MDA_W0_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W0_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W0_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W0_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W0_0_DFMT1_PA_MASK)

#define XRDC_MDA_W0_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W0_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W0_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W0_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W0_0_DFMT1_SA_MASK)

#define XRDC_MDA_W0_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W0_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W0_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W0_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W0_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W0_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W0_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W0_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W0_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W0_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W0_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W0_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W0_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W0_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W0_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W0_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W0_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W0_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W0_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W0_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W0_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W0_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W0_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W0_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W0_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W0_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W0_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W0_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W1_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W1_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W1_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W1_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W1_0_DFMT1_DID_MASK)

#define XRDC_MDA_W1_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W1_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W1_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W1_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W1_0_DFMT1_PA_MASK)

#define XRDC_MDA_W1_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W1_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W1_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W1_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W1_0_DFMT1_SA_MASK)

#define XRDC_MDA_W1_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W1_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W1_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W1_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W1_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W1_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W1_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W1_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W1_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W1_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W1_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W1_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W1_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W1_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W1_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W1_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W1_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W1_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W1_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W1_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W1_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W1_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W1_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W1_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W1_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W1_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W1_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W1_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W1_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W1_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W2_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W2_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W2_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W2_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W2_0_DFMT1_DID_MASK)

#define XRDC_MDA_W2_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W2_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W2_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W2_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W2_0_DFMT1_PA_MASK)

#define XRDC_MDA_W2_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W2_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W2_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W2_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W2_0_DFMT1_SA_MASK)

#define XRDC_MDA_W2_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W2_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W2_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W2_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W2_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W2_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W2_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W2_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W2_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W2_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W2_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W2_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W2_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W2_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W2_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W2_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W2_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W2_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W2_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W2_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W2_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W2_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W2_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W2_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W2_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W2_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W2_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W2_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W2_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W2_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W3_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W3_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W3_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W3_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W3_0_DFMT1_DID_MASK)

#define XRDC_MDA_W3_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W3_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W3_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W3_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W3_0_DFMT1_PA_MASK)

#define XRDC_MDA_W3_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W3_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W3_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W3_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W3_0_DFMT1_SA_MASK)

#define XRDC_MDA_W3_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W3_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W3_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W3_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W3_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W3_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W3_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W3_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W3_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W3_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W3_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W3_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W3_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W3_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W3_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W3_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W3_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W3_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W3_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W3_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W3_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W3_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W3_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W3_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W3_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W3_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W3_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W3_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W3_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W3_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W4_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W4_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W4_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W4_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W4_0_DFMT1_DID_MASK)

#define XRDC_MDA_W4_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W4_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W4_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W4_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W4_0_DFMT1_PA_MASK)

#define XRDC_MDA_W4_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W4_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W4_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W4_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W4_0_DFMT1_SA_MASK)

#define XRDC_MDA_W4_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W4_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W4_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W4_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W4_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W4_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W4_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W4_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W4_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W4_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W4_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W4_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W4_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W4_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W4_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W4_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W4_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W4_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W4_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W4_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W4_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W4_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W4_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W4_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W4_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W4_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W4_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W4_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W4_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W4_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W5_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W5_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W5_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W5_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W5_0_DFMT1_DID_MASK)

#define XRDC_MDA_W5_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W5_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W5_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W5_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W5_0_DFMT1_PA_MASK)

#define XRDC_MDA_W5_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W5_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W5_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W5_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W5_0_DFMT1_SA_MASK)

#define XRDC_MDA_W5_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W5_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W5_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W5_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W5_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W5_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W5_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W5_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W5_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W5_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W5_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W5_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W5_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W5_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W5_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W5_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W5_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W5_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W5_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W5_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W5_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W5_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W5_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W5_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W5_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W5_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W5_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W5_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W5_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W5_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W6_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W6_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W6_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W6_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W6_0_DFMT1_DID_MASK)

#define XRDC_MDA_W6_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W6_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W6_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W6_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W6_0_DFMT1_PA_MASK)

#define XRDC_MDA_W6_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W6_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W6_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W6_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W6_0_DFMT1_SA_MASK)

#define XRDC_MDA_W6_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W6_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W6_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W6_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W6_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W6_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W6_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W6_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W6_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W6_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W6_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W6_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W6_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W6_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W6_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W6_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W6_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W6_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W6_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W6_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W6_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W6_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W6_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W6_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W6_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W6_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W6_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W6_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W6_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W6_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W7_0_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W7_0_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W7_0_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W7_0_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_DID_SHIFT)) & XRDC_MDA_W7_0_DFMT1_DID_MASK)

#define XRDC_MDA_W7_0_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W7_0_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W7_0_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W7_0_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_PA_SHIFT)) & XRDC_MDA_W7_0_DFMT1_PA_MASK)

#define XRDC_MDA_W7_0_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W7_0_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W7_0_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W7_0_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_SA_SHIFT)) & XRDC_MDA_W7_0_DFMT1_SA_MASK)

#define XRDC_MDA_W7_0_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W7_0_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W7_0_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W7_0_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W7_0_DFMT1_DIDB_MASK)

#define XRDC_MDA_W7_0_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W7_0_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W7_0_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W7_0_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_LPID_SHIFT)) & XRDC_MDA_W7_0_DFMT1_LPID_MASK)

#define XRDC_MDA_W7_0_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W7_0_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W7_0_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W7_0_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_LPE_SHIFT)) & XRDC_MDA_W7_0_DFMT1_LPE_MASK)

#define XRDC_MDA_W7_0_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W7_0_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W7_0_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W7_0_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W7_0_DFMT1_DFMT_MASK)

#define XRDC_MDA_W7_0_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W7_0_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W7_0_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W7_0_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_LK1_SHIFT)) & XRDC_MDA_W7_0_DFMT1_LK1_MASK)

#define XRDC_MDA_W7_0_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W7_0_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W7_0_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W7_0_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_0_DFMT1_VLD_SHIFT)) & XRDC_MDA_W7_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W0_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W0_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W0_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W0_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W0_1_DFMT1_DID_MASK)

#define XRDC_MDA_W0_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W0_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W0_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W0_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W0_1_DFMT1_PA_MASK)

#define XRDC_MDA_W0_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W0_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W0_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W0_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W0_1_DFMT1_SA_MASK)

#define XRDC_MDA_W0_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W0_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W0_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W0_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W0_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W0_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W0_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W0_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W0_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W0_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W0_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W0_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W0_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W0_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W0_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W0_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W0_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W0_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W0_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W0_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W0_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W0_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W0_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W0_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W0_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W0_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W0_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W0_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W1_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W1_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W1_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W1_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W1_1_DFMT1_DID_MASK)

#define XRDC_MDA_W1_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W1_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W1_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W1_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W1_1_DFMT1_PA_MASK)

#define XRDC_MDA_W1_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W1_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W1_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W1_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W1_1_DFMT1_SA_MASK)

#define XRDC_MDA_W1_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W1_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W1_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W1_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W1_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W1_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W1_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W1_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W1_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W1_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W1_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W1_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W1_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W1_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W1_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W1_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W1_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W1_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W1_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W1_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W1_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W1_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W1_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W1_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W1_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W1_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W1_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W1_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W1_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W1_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W2_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W2_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W2_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W2_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W2_1_DFMT1_DID_MASK)

#define XRDC_MDA_W2_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W2_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W2_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W2_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W2_1_DFMT1_PA_MASK)

#define XRDC_MDA_W2_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W2_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W2_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W2_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W2_1_DFMT1_SA_MASK)

#define XRDC_MDA_W2_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W2_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W2_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W2_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W2_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W2_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W2_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W2_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W2_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W2_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W2_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W2_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W2_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W2_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W2_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W2_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W2_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W2_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W2_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W2_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W2_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W2_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W2_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W2_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W2_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W2_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W2_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W2_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W2_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W2_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W3_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W3_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W3_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W3_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W3_1_DFMT1_DID_MASK)

#define XRDC_MDA_W3_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W3_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W3_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W3_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W3_1_DFMT1_PA_MASK)

#define XRDC_MDA_W3_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W3_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W3_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W3_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W3_1_DFMT1_SA_MASK)

#define XRDC_MDA_W3_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W3_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W3_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W3_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W3_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W3_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W3_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W3_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W3_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W3_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W3_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W3_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W3_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W3_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W3_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W3_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W3_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W3_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W3_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W3_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W3_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W3_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W3_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W3_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W3_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W3_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W3_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W3_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W3_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W3_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W4_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W4_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W4_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W4_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W4_1_DFMT1_DID_MASK)

#define XRDC_MDA_W4_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W4_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W4_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W4_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W4_1_DFMT1_PA_MASK)

#define XRDC_MDA_W4_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W4_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W4_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W4_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W4_1_DFMT1_SA_MASK)

#define XRDC_MDA_W4_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W4_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W4_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W4_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W4_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W4_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W4_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W4_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W4_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W4_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W4_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W4_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W4_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W4_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W4_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W4_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W4_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W4_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W4_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W4_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W4_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W4_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W4_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W4_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W4_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W4_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W4_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W4_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W4_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W4_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W5_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W5_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W5_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W5_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W5_1_DFMT1_DID_MASK)

#define XRDC_MDA_W5_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W5_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W5_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W5_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W5_1_DFMT1_PA_MASK)

#define XRDC_MDA_W5_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W5_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W5_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W5_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W5_1_DFMT1_SA_MASK)

#define XRDC_MDA_W5_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W5_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W5_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W5_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W5_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W5_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W5_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W5_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W5_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W5_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W5_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W5_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W5_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W5_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W5_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W5_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W5_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W5_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W5_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W5_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W5_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W5_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W5_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W5_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W5_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W5_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W5_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W5_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W5_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W5_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W6_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W6_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W6_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W6_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W6_1_DFMT1_DID_MASK)

#define XRDC_MDA_W6_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W6_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W6_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W6_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W6_1_DFMT1_PA_MASK)

#define XRDC_MDA_W6_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W6_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W6_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W6_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W6_1_DFMT1_SA_MASK)

#define XRDC_MDA_W6_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W6_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W6_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W6_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W6_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W6_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W6_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W6_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W6_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W6_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W6_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W6_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W6_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W6_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W6_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W6_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W6_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W6_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W6_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W6_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W6_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W6_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W6_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W6_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W6_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W6_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W6_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W6_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W6_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W6_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W7_1_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W7_1_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W7_1_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W7_1_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_DID_SHIFT)) & XRDC_MDA_W7_1_DFMT1_DID_MASK)

#define XRDC_MDA_W7_1_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W7_1_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W7_1_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W7_1_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_PA_SHIFT)) & XRDC_MDA_W7_1_DFMT1_PA_MASK)

#define XRDC_MDA_W7_1_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W7_1_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W7_1_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W7_1_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_SA_SHIFT)) & XRDC_MDA_W7_1_DFMT1_SA_MASK)

#define XRDC_MDA_W7_1_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W7_1_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W7_1_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W7_1_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W7_1_DFMT1_DIDB_MASK)

#define XRDC_MDA_W7_1_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W7_1_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W7_1_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W7_1_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_LPID_SHIFT)) & XRDC_MDA_W7_1_DFMT1_LPID_MASK)

#define XRDC_MDA_W7_1_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W7_1_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W7_1_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W7_1_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_LPE_SHIFT)) & XRDC_MDA_W7_1_DFMT1_LPE_MASK)

#define XRDC_MDA_W7_1_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W7_1_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W7_1_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W7_1_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W7_1_DFMT1_DFMT_MASK)

#define XRDC_MDA_W7_1_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W7_1_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W7_1_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W7_1_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_LK1_SHIFT)) & XRDC_MDA_W7_1_DFMT1_LK1_MASK)

#define XRDC_MDA_W7_1_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W7_1_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W7_1_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W7_1_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_1_DFMT1_VLD_SHIFT)) & XRDC_MDA_W7_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W0_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W0_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W0_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W0_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W0_2_DFMT1_DID_MASK)

#define XRDC_MDA_W0_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W0_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W0_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W0_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W0_2_DFMT1_PA_MASK)

#define XRDC_MDA_W0_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W0_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W0_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W0_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W0_2_DFMT1_SA_MASK)

#define XRDC_MDA_W0_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W0_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W0_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W0_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W0_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W0_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W0_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W0_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W0_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W0_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W0_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W0_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W0_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W0_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W0_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W0_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W0_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W0_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W0_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W0_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W0_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W0_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W0_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W0_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W0_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W0_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W0_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W0_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W0_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W0_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W1_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W1_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W1_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W1_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W1_2_DFMT1_DID_MASK)

#define XRDC_MDA_W1_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W1_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W1_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W1_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W1_2_DFMT1_PA_MASK)

#define XRDC_MDA_W1_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W1_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W1_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W1_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W1_2_DFMT1_SA_MASK)

#define XRDC_MDA_W1_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W1_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W1_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W1_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W1_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W1_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W1_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W1_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W1_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W1_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W1_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W1_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W1_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W1_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W1_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W1_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W1_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W1_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W1_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W1_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W1_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W1_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W1_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W1_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W1_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W1_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W1_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W1_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W1_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W1_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W1_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W2_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W2_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W2_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W2_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W2_2_DFMT1_DID_MASK)

#define XRDC_MDA_W2_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W2_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W2_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W2_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W2_2_DFMT1_PA_MASK)

#define XRDC_MDA_W2_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W2_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W2_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W2_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W2_2_DFMT1_SA_MASK)

#define XRDC_MDA_W2_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W2_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W2_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W2_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W2_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W2_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W2_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W2_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W2_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W2_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W2_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W2_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W2_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W2_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W2_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W2_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W2_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W2_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W2_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W2_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W2_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W2_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W2_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W2_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W2_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W2_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W2_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W2_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W2_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W2_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W2_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W3_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W3_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W3_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W3_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W3_2_DFMT1_DID_MASK)

#define XRDC_MDA_W3_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W3_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W3_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W3_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W3_2_DFMT1_PA_MASK)

#define XRDC_MDA_W3_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W3_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W3_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W3_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W3_2_DFMT1_SA_MASK)

#define XRDC_MDA_W3_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W3_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W3_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W3_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W3_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W3_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W3_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W3_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W3_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W3_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W3_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W3_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W3_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W3_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W3_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W3_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W3_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W3_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W3_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W3_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W3_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W3_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W3_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W3_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W3_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W3_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W3_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W3_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W3_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W3_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W3_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W4_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W4_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W4_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W4_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W4_2_DFMT1_DID_MASK)

#define XRDC_MDA_W4_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W4_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W4_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W4_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W4_2_DFMT1_PA_MASK)

#define XRDC_MDA_W4_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W4_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W4_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W4_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W4_2_DFMT1_SA_MASK)

#define XRDC_MDA_W4_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W4_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W4_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W4_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W4_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W4_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W4_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W4_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W4_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W4_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W4_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W4_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W4_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W4_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W4_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W4_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W4_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W4_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W4_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W4_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W4_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W4_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W4_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W4_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W4_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W4_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W4_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W4_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W4_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W4_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W4_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W5_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W5_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W5_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W5_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W5_2_DFMT1_DID_MASK)

#define XRDC_MDA_W5_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W5_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W5_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W5_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W5_2_DFMT1_PA_MASK)

#define XRDC_MDA_W5_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W5_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W5_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W5_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W5_2_DFMT1_SA_MASK)

#define XRDC_MDA_W5_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W5_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W5_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W5_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W5_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W5_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W5_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W5_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W5_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W5_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W5_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W5_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W5_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W5_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W5_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W5_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W5_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W5_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W5_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W5_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W5_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W5_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W5_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W5_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W5_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W5_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W5_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W5_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W5_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W5_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W5_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W6_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W6_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W6_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W6_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W6_2_DFMT1_DID_MASK)

#define XRDC_MDA_W6_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W6_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W6_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W6_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W6_2_DFMT1_PA_MASK)

#define XRDC_MDA_W6_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W6_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W6_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W6_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W6_2_DFMT1_SA_MASK)

#define XRDC_MDA_W6_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W6_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W6_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W6_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W6_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W6_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W6_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W6_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W6_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W6_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W6_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W6_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W6_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W6_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W6_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W6_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W6_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W6_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W6_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W6_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W6_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W6_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W6_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W6_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W6_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W6_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W6_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W6_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W6_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W6_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W6_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W7_2_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W7_2_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W7_2_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W7_2_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_DID_SHIFT)) & XRDC_MDA_W7_2_DFMT1_DID_MASK)

#define XRDC_MDA_W7_2_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W7_2_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W7_2_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W7_2_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_PA_SHIFT)) & XRDC_MDA_W7_2_DFMT1_PA_MASK)

#define XRDC_MDA_W7_2_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W7_2_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W7_2_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W7_2_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_SA_SHIFT)) & XRDC_MDA_W7_2_DFMT1_SA_MASK)

#define XRDC_MDA_W7_2_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W7_2_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W7_2_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W7_2_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W7_2_DFMT1_DIDB_MASK)

#define XRDC_MDA_W7_2_DFMT1_LPID_MASK            (0xF000000U)
#define XRDC_MDA_W7_2_DFMT1_LPID_SHIFT           (24U)
#define XRDC_MDA_W7_2_DFMT1_LPID_WIDTH           (4U)
#define XRDC_MDA_W7_2_DFMT1_LPID(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_LPID_SHIFT)) & XRDC_MDA_W7_2_DFMT1_LPID_MASK)

#define XRDC_MDA_W7_2_DFMT1_LPE_MASK             (0x10000000U)
#define XRDC_MDA_W7_2_DFMT1_LPE_SHIFT            (28U)
#define XRDC_MDA_W7_2_DFMT1_LPE_WIDTH            (1U)
#define XRDC_MDA_W7_2_DFMT1_LPE(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_LPE_SHIFT)) & XRDC_MDA_W7_2_DFMT1_LPE_MASK)

#define XRDC_MDA_W7_2_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W7_2_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W7_2_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W7_2_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W7_2_DFMT1_DFMT_MASK)

#define XRDC_MDA_W7_2_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W7_2_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W7_2_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W7_2_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_LK1_SHIFT)) & XRDC_MDA_W7_2_DFMT1_LK1_MASK)

#define XRDC_MDA_W7_2_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W7_2_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W7_2_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W7_2_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W7_2_DFMT1_VLD_SHIFT)) & XRDC_MDA_W7_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_3_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W0_3_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W0_3_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W0_3_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W0_3_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_DID_SHIFT)) & XRDC_MDA_W0_3_DFMT1_DID_MASK)

#define XRDC_MDA_W0_3_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W0_3_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W0_3_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W0_3_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_PA_SHIFT)) & XRDC_MDA_W0_3_DFMT1_PA_MASK)

#define XRDC_MDA_W0_3_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W0_3_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W0_3_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W0_3_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_SA_SHIFT)) & XRDC_MDA_W0_3_DFMT1_SA_MASK)

#define XRDC_MDA_W0_3_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W0_3_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W0_3_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W0_3_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W0_3_DFMT1_DIDB_MASK)

#define XRDC_MDA_W0_3_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W0_3_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W0_3_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W0_3_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W0_3_DFMT1_DFMT_MASK)

#define XRDC_MDA_W0_3_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W0_3_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W0_3_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W0_3_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_LK1_SHIFT)) & XRDC_MDA_W0_3_DFMT1_LK1_MASK)

#define XRDC_MDA_W0_3_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W0_3_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W0_3_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W0_3_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_3_DFMT1_VLD_SHIFT)) & XRDC_MDA_W0_3_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define XRDC_MDA_W0_4_DFMT1_DID_MASK             (0xFU)
#define XRDC_MDA_W0_4_DFMT1_DID_SHIFT            (0U)
#define XRDC_MDA_W0_4_DFMT1_DID_WIDTH            (4U)
#define XRDC_MDA_W0_4_DFMT1_DID(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_DID_SHIFT)) & XRDC_MDA_W0_4_DFMT1_DID_MASK)

#define XRDC_MDA_W0_4_DFMT1_PA_MASK              (0x30U)
#define XRDC_MDA_W0_4_DFMT1_PA_SHIFT             (4U)
#define XRDC_MDA_W0_4_DFMT1_PA_WIDTH             (2U)
#define XRDC_MDA_W0_4_DFMT1_PA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_PA_SHIFT)) & XRDC_MDA_W0_4_DFMT1_PA_MASK)

#define XRDC_MDA_W0_4_DFMT1_SA_MASK              (0xC0U)
#define XRDC_MDA_W0_4_DFMT1_SA_SHIFT             (6U)
#define XRDC_MDA_W0_4_DFMT1_SA_WIDTH             (2U)
#define XRDC_MDA_W0_4_DFMT1_SA(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_SA_SHIFT)) & XRDC_MDA_W0_4_DFMT1_SA_MASK)

#define XRDC_MDA_W0_4_DFMT1_DIDB_MASK            (0x100U)
#define XRDC_MDA_W0_4_DFMT1_DIDB_SHIFT           (8U)
#define XRDC_MDA_W0_4_DFMT1_DIDB_WIDTH           (1U)
#define XRDC_MDA_W0_4_DFMT1_DIDB(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_DIDB_SHIFT)) & XRDC_MDA_W0_4_DFMT1_DIDB_MASK)

#define XRDC_MDA_W0_4_DFMT1_DFMT_MASK            (0x20000000U)
#define XRDC_MDA_W0_4_DFMT1_DFMT_SHIFT           (29U)
#define XRDC_MDA_W0_4_DFMT1_DFMT_WIDTH           (1U)
#define XRDC_MDA_W0_4_DFMT1_DFMT(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_DFMT_SHIFT)) & XRDC_MDA_W0_4_DFMT1_DFMT_MASK)

#define XRDC_MDA_W0_4_DFMT1_LK1_MASK             (0x40000000U)
#define XRDC_MDA_W0_4_DFMT1_LK1_SHIFT            (30U)
#define XRDC_MDA_W0_4_DFMT1_LK1_WIDTH            (1U)
#define XRDC_MDA_W0_4_DFMT1_LK1(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_LK1_SHIFT)) & XRDC_MDA_W0_4_DFMT1_LK1_MASK)

#define XRDC_MDA_W0_4_DFMT1_VLD_MASK             (0x80000000U)
#define XRDC_MDA_W0_4_DFMT1_VLD_SHIFT            (31U)
#define XRDC_MDA_W0_4_DFMT1_VLD_WIDTH            (1U)
#define XRDC_MDA_W0_4_DFMT1_VLD(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_MDA_W0_4_DFMT1_VLD_SHIFT)) & XRDC_MDA_W0_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define XRDC_PDAC_W0_D0ACP_MASK                  (0x7U)
#define XRDC_PDAC_W0_D0ACP_SHIFT                 (0U)
#define XRDC_PDAC_W0_D0ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D0ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D0ACP_SHIFT)) & XRDC_PDAC_W0_D0ACP_MASK)

#define XRDC_PDAC_W0_D1ACP_MASK                  (0x38U)
#define XRDC_PDAC_W0_D1ACP_SHIFT                 (3U)
#define XRDC_PDAC_W0_D1ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D1ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D1ACP_SHIFT)) & XRDC_PDAC_W0_D1ACP_MASK)

#define XRDC_PDAC_W0_D2ACP_MASK                  (0x1C0U)
#define XRDC_PDAC_W0_D2ACP_SHIFT                 (6U)
#define XRDC_PDAC_W0_D2ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D2ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D2ACP_SHIFT)) & XRDC_PDAC_W0_D2ACP_MASK)

#define XRDC_PDAC_W0_D3ACP_MASK                  (0xE00U)
#define XRDC_PDAC_W0_D3ACP_SHIFT                 (9U)
#define XRDC_PDAC_W0_D3ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D3ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D3ACP_SHIFT)) & XRDC_PDAC_W0_D3ACP_MASK)

#define XRDC_PDAC_W0_D4ACP_MASK                  (0x7000U)
#define XRDC_PDAC_W0_D4ACP_SHIFT                 (12U)
#define XRDC_PDAC_W0_D4ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D4ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D4ACP_SHIFT)) & XRDC_PDAC_W0_D4ACP_MASK)

#define XRDC_PDAC_W0_D5ACP_MASK                  (0x38000U)
#define XRDC_PDAC_W0_D5ACP_SHIFT                 (15U)
#define XRDC_PDAC_W0_D5ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D5ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D5ACP_SHIFT)) & XRDC_PDAC_W0_D5ACP_MASK)

#define XRDC_PDAC_W0_D6ACP_MASK                  (0x1C0000U)
#define XRDC_PDAC_W0_D6ACP_SHIFT                 (18U)
#define XRDC_PDAC_W0_D6ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D6ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D6ACP_SHIFT)) & XRDC_PDAC_W0_D6ACP_MASK)

#define XRDC_PDAC_W0_D7ACP_MASK                  (0xE00000U)
#define XRDC_PDAC_W0_D7ACP_SHIFT                 (21U)
#define XRDC_PDAC_W0_D7ACP_WIDTH                 (3U)
#define XRDC_PDAC_W0_D7ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_D7ACP_SHIFT)) & XRDC_PDAC_W0_D7ACP_MASK)

#define XRDC_PDAC_W0_SNUM_MASK                   (0xF000000U)
#define XRDC_PDAC_W0_SNUM_SHIFT                  (24U)
#define XRDC_PDAC_W0_SNUM_WIDTH                  (4U)
#define XRDC_PDAC_W0_SNUM(x)                     (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_SNUM_SHIFT)) & XRDC_PDAC_W0_SNUM_MASK)

#define XRDC_PDAC_W0_SE_MASK                     (0x40000000U)
#define XRDC_PDAC_W0_SE_SHIFT                    (30U)
#define XRDC_PDAC_W0_SE_WIDTH                    (1U)
#define XRDC_PDAC_W0_SE(x)                       (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W0_SE_SHIFT)) & XRDC_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define XRDC_PDAC_W1_D8ACP_MASK                  (0x7U)
#define XRDC_PDAC_W1_D8ACP_SHIFT                 (0U)
#define XRDC_PDAC_W1_D8ACP_WIDTH                 (3U)
#define XRDC_PDAC_W1_D8ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D8ACP_SHIFT)) & XRDC_PDAC_W1_D8ACP_MASK)

#define XRDC_PDAC_W1_D9ACP_MASK                  (0x38U)
#define XRDC_PDAC_W1_D9ACP_SHIFT                 (3U)
#define XRDC_PDAC_W1_D9ACP_WIDTH                 (3U)
#define XRDC_PDAC_W1_D9ACP(x)                    (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D9ACP_SHIFT)) & XRDC_PDAC_W1_D9ACP_MASK)

#define XRDC_PDAC_W1_D10ACP_MASK                 (0x1C0U)
#define XRDC_PDAC_W1_D10ACP_SHIFT                (6U)
#define XRDC_PDAC_W1_D10ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D10ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D10ACP_SHIFT)) & XRDC_PDAC_W1_D10ACP_MASK)

#define XRDC_PDAC_W1_D11ACP_MASK                 (0xE00U)
#define XRDC_PDAC_W1_D11ACP_SHIFT                (9U)
#define XRDC_PDAC_W1_D11ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D11ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D11ACP_SHIFT)) & XRDC_PDAC_W1_D11ACP_MASK)

#define XRDC_PDAC_W1_D12ACP_MASK                 (0x7000U)
#define XRDC_PDAC_W1_D12ACP_SHIFT                (12U)
#define XRDC_PDAC_W1_D12ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D12ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D12ACP_SHIFT)) & XRDC_PDAC_W1_D12ACP_MASK)

#define XRDC_PDAC_W1_D13ACP_MASK                 (0x38000U)
#define XRDC_PDAC_W1_D13ACP_SHIFT                (15U)
#define XRDC_PDAC_W1_D13ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D13ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D13ACP_SHIFT)) & XRDC_PDAC_W1_D13ACP_MASK)

#define XRDC_PDAC_W1_D14ACP_MASK                 (0x1C0000U)
#define XRDC_PDAC_W1_D14ACP_SHIFT                (18U)
#define XRDC_PDAC_W1_D14ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D14ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D14ACP_SHIFT)) & XRDC_PDAC_W1_D14ACP_MASK)

#define XRDC_PDAC_W1_D15ACP_MASK                 (0xE00000U)
#define XRDC_PDAC_W1_D15ACP_SHIFT                (21U)
#define XRDC_PDAC_W1_D15ACP_WIDTH                (3U)
#define XRDC_PDAC_W1_D15ACP(x)                   (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_D15ACP_SHIFT)) & XRDC_PDAC_W1_D15ACP_MASK)

#define XRDC_PDAC_W1_LK2_MASK                    (0x60000000U)
#define XRDC_PDAC_W1_LK2_SHIFT                   (29U)
#define XRDC_PDAC_W1_LK2_WIDTH                   (2U)
#define XRDC_PDAC_W1_LK2(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_LK2_SHIFT)) & XRDC_PDAC_W1_LK2_MASK)

#define XRDC_PDAC_W1_VLD_MASK                    (0x80000000U)
#define XRDC_PDAC_W1_VLD_SHIFT                   (31U)
#define XRDC_PDAC_W1_VLD_WIDTH                   (1U)
#define XRDC_PDAC_W1_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << XRDC_PDAC_W1_VLD_SHIFT)) & XRDC_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name XRDC_MRGD_W0 - Memory Region Descriptor Word 0 */
/*! @{ */

#define XRDC_XRDC_MRGD_W0_SRTADDR_MASK           (0xFFFFFFE0U)
#define XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT          (5U)
#define XRDC_XRDC_MRGD_W0_SRTADDR_WIDTH          (27U)
#define XRDC_XRDC_MRGD_W0_SRTADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT)) & XRDC_XRDC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W1 - Memory Region Descriptor Word 1 */
/*! @{ */

#define XRDC_XRDC_MRGD_W1_ENDADDR_MASK           (0xFFFFFFE0U)
#define XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT          (5U)
#define XRDC_XRDC_MRGD_W1_ENDADDR_WIDTH          (27U)
#define XRDC_XRDC_MRGD_W1_ENDADDR(x)             (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT)) & XRDC_XRDC_MRGD_W1_ENDADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W2 - Memory Region Descriptor Word 2 */
/*! @{ */

#define XRDC_XRDC_MRGD_W2_D0ACP_MASK             (0x7U)
#define XRDC_XRDC_MRGD_W2_D0ACP_SHIFT            (0U)
#define XRDC_XRDC_MRGD_W2_D0ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D0ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D0ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D0ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D1ACP_MASK             (0x38U)
#define XRDC_XRDC_MRGD_W2_D1ACP_SHIFT            (3U)
#define XRDC_XRDC_MRGD_W2_D1ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D1ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D1ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D1ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D2ACP_MASK             (0x1C0U)
#define XRDC_XRDC_MRGD_W2_D2ACP_SHIFT            (6U)
#define XRDC_XRDC_MRGD_W2_D2ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D2ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D2ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D2ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D3ACP_MASK             (0xE00U)
#define XRDC_XRDC_MRGD_W2_D3ACP_SHIFT            (9U)
#define XRDC_XRDC_MRGD_W2_D3ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D3ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D3ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D3ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D4ACP_MASK             (0x7000U)
#define XRDC_XRDC_MRGD_W2_D4ACP_SHIFT            (12U)
#define XRDC_XRDC_MRGD_W2_D4ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D4ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D4ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D4ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D5ACP_MASK             (0x38000U)
#define XRDC_XRDC_MRGD_W2_D5ACP_SHIFT            (15U)
#define XRDC_XRDC_MRGD_W2_D5ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D5ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D5ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D5ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D6ACP_MASK             (0x1C0000U)
#define XRDC_XRDC_MRGD_W2_D6ACP_SHIFT            (18U)
#define XRDC_XRDC_MRGD_W2_D6ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D6ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D6ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D6ACP_MASK)

#define XRDC_XRDC_MRGD_W2_D7ACP_MASK             (0xE00000U)
#define XRDC_XRDC_MRGD_W2_D7ACP_SHIFT            (21U)
#define XRDC_XRDC_MRGD_W2_D7ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W2_D7ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_D7ACP_SHIFT)) & XRDC_XRDC_MRGD_W2_D7ACP_MASK)

#define XRDC_XRDC_MRGD_W2_SNUM_MASK              (0xF000000U)
#define XRDC_XRDC_MRGD_W2_SNUM_SHIFT             (24U)
#define XRDC_XRDC_MRGD_W2_SNUM_WIDTH             (4U)
#define XRDC_XRDC_MRGD_W2_SNUM(x)                (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_SNUM_SHIFT)) & XRDC_XRDC_MRGD_W2_SNUM_MASK)

#define XRDC_XRDC_MRGD_W2_SE_MASK                (0x40000000U)
#define XRDC_XRDC_MRGD_W2_SE_SHIFT               (30U)
#define XRDC_XRDC_MRGD_W2_SE_WIDTH               (1U)
#define XRDC_XRDC_MRGD_W2_SE(x)                  (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W2_SE_SHIFT)) & XRDC_XRDC_MRGD_W2_SE_MASK)
/*! @} */

/*! @name XRDC_MRGD_W3 - Memory Region Descriptor Word 3 */
/*! @{ */

#define XRDC_XRDC_MRGD_W3_D8ACP_MASK             (0x7U)
#define XRDC_XRDC_MRGD_W3_D8ACP_SHIFT            (0U)
#define XRDC_XRDC_MRGD_W3_D8ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W3_D8ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D8ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D8ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D9ACP_MASK             (0x38U)
#define XRDC_XRDC_MRGD_W3_D9ACP_SHIFT            (3U)
#define XRDC_XRDC_MRGD_W3_D9ACP_WIDTH            (3U)
#define XRDC_XRDC_MRGD_W3_D9ACP(x)               (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D9ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D9ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D10ACP_MASK            (0x1C0U)
#define XRDC_XRDC_MRGD_W3_D10ACP_SHIFT           (6U)
#define XRDC_XRDC_MRGD_W3_D10ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D10ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D10ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D10ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D11ACP_MASK            (0xE00U)
#define XRDC_XRDC_MRGD_W3_D11ACP_SHIFT           (9U)
#define XRDC_XRDC_MRGD_W3_D11ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D11ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D11ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D11ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D12ACP_MASK            (0x7000U)
#define XRDC_XRDC_MRGD_W3_D12ACP_SHIFT           (12U)
#define XRDC_XRDC_MRGD_W3_D12ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D12ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D12ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D12ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D13ACP_MASK            (0x38000U)
#define XRDC_XRDC_MRGD_W3_D13ACP_SHIFT           (15U)
#define XRDC_XRDC_MRGD_W3_D13ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D13ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D13ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D13ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D14ACP_MASK            (0x1C0000U)
#define XRDC_XRDC_MRGD_W3_D14ACP_SHIFT           (18U)
#define XRDC_XRDC_MRGD_W3_D14ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D14ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D14ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D14ACP_MASK)

#define XRDC_XRDC_MRGD_W3_D15ACP_MASK            (0xE00000U)
#define XRDC_XRDC_MRGD_W3_D15ACP_SHIFT           (21U)
#define XRDC_XRDC_MRGD_W3_D15ACP_WIDTH           (3U)
#define XRDC_XRDC_MRGD_W3_D15ACP(x)              (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_D15ACP_SHIFT)) & XRDC_XRDC_MRGD_W3_D15ACP_MASK)

#define XRDC_XRDC_MRGD_W3_LK2_MASK               (0x60000000U)
#define XRDC_XRDC_MRGD_W3_LK2_SHIFT              (29U)
#define XRDC_XRDC_MRGD_W3_LK2_WIDTH              (2U)
#define XRDC_XRDC_MRGD_W3_LK2(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_LK2_SHIFT)) & XRDC_XRDC_MRGD_W3_LK2_MASK)

#define XRDC_XRDC_MRGD_W3_VLD_MASK               (0x80000000U)
#define XRDC_XRDC_MRGD_W3_VLD_SHIFT              (31U)
#define XRDC_XRDC_MRGD_W3_VLD_WIDTH              (1U)
#define XRDC_XRDC_MRGD_W3_VLD(x)                 (((uint32_t)(((uint32_t)(x)) << XRDC_XRDC_MRGD_W3_VLD_SHIFT)) & XRDC_XRDC_MRGD_W3_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group XRDC_Register_Masks */

/*!
 * @}
 */ /* end of group XRDC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_XRDC_H_) */
