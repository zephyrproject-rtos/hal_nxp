/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_RTU_XRDC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_RTU_XRDC
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
#if !defined(S32Z2_RTU_XRDC_H_)  /* Check if memory map has not been already included */
#define S32Z2_RTU_XRDC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- RTU_XRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_XRDC_Peripheral_Access_Layer RTU_XRDC Peripheral Access Layer
 * @{
 */

/** RTU_XRDC - Size of Registers Arrays */
#define RTU_XRDC_MDAC_COUNT                       13u
#define RTU_XRDC_MRC_COUNT                        15u
#define RTU_XRDC_DERRLOC_COUNT                    16u
#define RTU_XRDC_DERRW0_COUNT                     19u
#define RTU_XRDC_PDAC_SLOT_PDACN_COUNT            43u
#define RTU_XRDC_PDAC_SLOT_COUNT                  3u
#define RTU_XRDC_MRCN_COUNT                       15u
#define RTU_XRDC_MRCN_MRGDN_COUNT                 16u

/** RTU_XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  uint8_t RESERVED_1[8];
  __I  uint8_t MDACFG[RTU_XRDC_MDAC_COUNT];        /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
  uint8_t RESERVED_2[51];
  __I  uint8_t MRCFG[RTU_XRDC_MRC_COUNT];          /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
  uint8_t RESERVED_3[177];
  __I  uint32_t DERRLOC[RTU_XRDC_DERRLOC_COUNT];   /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[448];
  struct RTU_XRDC_DERRW0 {                         /* offset: 0x400, array step: 0x10 */
    __I  uint32_t DERR_W0;                           /**< Domain Error Word 0, array offset: 0x400, array step: 0x10, valid indices: [0-14, 16-18] */
    __I  uint32_t DERR_W1;                           /**< Domain Error Word 1, array offset: 0x404, array step: 0x10, valid indices: [0-14, 16-18] */
    uint8_t RESERVED_0[4];
    __O  uint32_t DERR_W3;                           /**< Domain Error Word 3, array offset: 0x40C, array step: 0x10, valid indices: [0-14, 16-18] */
  } DERRW0[RTU_XRDC_DERRW0_COUNT];
  uint8_t RESERVED_5[720];
  __IO uint32_t MDA_W0_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x800 */
  uint8_t RESERVED_6[28];
  __IO uint32_t MDA_W0_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x820 */
  uint8_t RESERVED_7[28];
  __IO uint32_t MDA_W0_2_DFMT1;                    /**< Master Domain Assignment, offset: 0x840 */
  uint8_t RESERVED_8[28];
  __IO uint32_t MDA_W0_3_DFMT1;                    /**< Master Domain Assignment, offset: 0x860 */
  uint8_t RESERVED_9[28];
  __IO uint32_t MDA_W0_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x880 */
  __IO uint32_t MDA_W1_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x884 */
  __IO uint32_t MDA_W2_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x888 */
  __IO uint32_t MDA_W3_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x88C */
  __IO uint32_t MDA_W4_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x890 */
  __IO uint32_t MDA_W5_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x894 */
  __IO uint32_t MDA_W6_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x898 */
  __IO uint32_t MDA_W7_4_DFMT1;                    /**< Master Domain Assignment, offset: 0x89C */
  __IO uint32_t MDA_W0_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8A0 */
  __IO uint32_t MDA_W1_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8A4 */
  __IO uint32_t MDA_W2_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8A8 */
  __IO uint32_t MDA_W3_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8AC */
  __IO uint32_t MDA_W4_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8B0 */
  __IO uint32_t MDA_W5_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8B4 */
  __IO uint32_t MDA_W6_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8B8 */
  __IO uint32_t MDA_W7_5_DFMT1;                    /**< Master Domain Assignment, offset: 0x8BC */
  __IO uint32_t MDA_W0_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8C0 */
  __IO uint32_t MDA_W1_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8C4 */
  __IO uint32_t MDA_W2_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8C8 */
  __IO uint32_t MDA_W3_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8CC */
  __IO uint32_t MDA_W4_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8D0 */
  __IO uint32_t MDA_W5_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8D4 */
  __IO uint32_t MDA_W6_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8D8 */
  __IO uint32_t MDA_W7_6_DFMT1;                    /**< Master Domain Assignment, offset: 0x8DC */
  __IO uint32_t MDA_W0_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8E0 */
  __IO uint32_t MDA_W1_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8E4 */
  __IO uint32_t MDA_W2_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8E8 */
  __IO uint32_t MDA_W3_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8EC */
  __IO uint32_t MDA_W4_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8F0 */
  __IO uint32_t MDA_W5_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8F4 */
  __IO uint32_t MDA_W6_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8F8 */
  __IO uint32_t MDA_W7_7_DFMT1;                    /**< Master Domain Assignment, offset: 0x8FC */
  __IO uint32_t MDA_W0_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x900 */
  __IO uint32_t MDA_W1_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x904 */
  __IO uint32_t MDA_W2_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x908 */
  __IO uint32_t MDA_W3_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x90C */
  __IO uint32_t MDA_W4_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x910 */
  __IO uint32_t MDA_W5_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x914 */
  __IO uint32_t MDA_W6_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x918 */
  __IO uint32_t MDA_W7_8_DFMT1;                    /**< Master Domain Assignment, offset: 0x91C */
  __IO uint32_t MDA_W0_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x920 */
  __IO uint32_t MDA_W1_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x924 */
  __IO uint32_t MDA_W2_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x928 */
  __IO uint32_t MDA_W3_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x92C */
  __IO uint32_t MDA_W4_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x930 */
  __IO uint32_t MDA_W5_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x934 */
  __IO uint32_t MDA_W6_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x938 */
  __IO uint32_t MDA_W7_9_DFMT1;                    /**< Master Domain Assignment, offset: 0x93C */
  __IO uint32_t MDA_W0_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x940 */
  __IO uint32_t MDA_W1_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x944 */
  __IO uint32_t MDA_W2_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x948 */
  __IO uint32_t MDA_W3_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x94C */
  __IO uint32_t MDA_W4_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x950 */
  __IO uint32_t MDA_W5_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x954 */
  __IO uint32_t MDA_W6_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x958 */
  __IO uint32_t MDA_W7_10_DFMT1;                   /**< Master Domain Assignment, offset: 0x95C */
  __IO uint32_t MDA_W0_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x960 */
  __IO uint32_t MDA_W1_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x964 */
  __IO uint32_t MDA_W2_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x968 */
  __IO uint32_t MDA_W3_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x96C */
  __IO uint32_t MDA_W4_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x970 */
  __IO uint32_t MDA_W5_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x974 */
  __IO uint32_t MDA_W6_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x978 */
  __IO uint32_t MDA_W7_11_DFMT1;                   /**< Master Domain Assignment, offset: 0x97C */
  __IO uint32_t MDA_W0_12_DFMT1;                   /**< Master Domain Assignment, offset: 0x980 */
  uint8_t RESERVED_10[1660];
  struct RTU_XRDC_PDAC_SLOT {                      /* offset: 0x1000, array step: 0x400 */
    struct RTU_XRDC_PDAC_SLOT_PDACN {                /* offset: 0x1000, array step: index*0x400, index2*0x8 */
      __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1000, array step: index*0x400, index2*0x8, valid indices: [0][0-15, 18-29, 31-42], [1][0-8, 10-17, 21-24], [2][0-7, 9, 12-15, 18-29, 31-42] */
      __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1004, array step: index*0x400, index2*0x8, valid indices: [0][0-15, 18-29, 31-42], [1][0-8, 10-17, 21-24], [2][0-7, 9, 12-15, 18-29, 31-42] */
    } PDACN[RTU_XRDC_PDAC_SLOT_PDACN_COUNT];
    uint8_t RESERVED_0[680];
  } PDAC_SLOT[RTU_XRDC_PDAC_SLOT_COUNT];
  uint8_t RESERVED_11[1024];
  struct RTU_XRDC_MRGDN {                          /* offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W0;                      /**< Memory Region Descriptor Word 0, array offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W1;                      /**< Memory Region Descriptor Word 1, array offset: 0x2004, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W2;                      /**< Memory Region Descriptor Word 2, array offset: 0x2008, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W3;                      /**< Memory Region Descriptor Word 3, array offset: 0x200C, array step: index*0x200, index2*0x20 */
    uint8_t RESERVED_0[16];
  } MRGDN[RTU_XRDC_MRCN_COUNT][RTU_XRDC_MRCN_MRGDN_COUNT];
} RTU_XRDC_Type, *RTU_XRDC_MemMapPtr;

/** Number of instances of the RTU_XRDC module. */
#define RTU_XRDC_INSTANCE_COUNT                  (2u)

/* RTU_XRDC - Peripheral instance base addresses */
/** Peripheral RTU0__XRDC base address */
#define IP_RTU0__XRDC_BASE                       (0x76100000u)
/** Peripheral RTU0__XRDC base pointer */
#define IP_RTU0__XRDC                            ((RTU_XRDC_Type *)IP_RTU0__XRDC_BASE)
/** Peripheral RTU1__XRDC base address */
#define IP_RTU1__XRDC_BASE                       (0x76900000u)
/** Peripheral RTU1__XRDC base pointer */
#define IP_RTU1__XRDC                            ((RTU_XRDC_Type *)IP_RTU1__XRDC_BASE)
/** Array initializer of RTU_XRDC peripheral base addresses */
#define IP_RTU_XRDC_BASE_ADDRS                   { IP_RTU0__XRDC_BASE, IP_RTU1__XRDC_BASE }
/** Array initializer of RTU_XRDC peripheral base pointers */
#define IP_RTU_XRDC_BASE_PTRS                    { IP_RTU0__XRDC, IP_RTU1__XRDC }

/* ----------------------------------------------------------------------------
   -- RTU_XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTU_XRDC_Register_Masks RTU_XRDC Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define RTU_XRDC_CR_GVLD_MASK                    (0x1U)
#define RTU_XRDC_CR_GVLD_SHIFT                   (0U)
#define RTU_XRDC_CR_GVLD_WIDTH                   (1U)
#define RTU_XRDC_CR_GVLD(x)                      (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_CR_GVLD_SHIFT)) & RTU_XRDC_CR_GVLD_MASK)

#define RTU_XRDC_CR_HRL_MASK                     (0x1EU)
#define RTU_XRDC_CR_HRL_SHIFT                    (1U)
#define RTU_XRDC_CR_HRL_WIDTH                    (4U)
#define RTU_XRDC_CR_HRL(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_CR_HRL_SHIFT)) & RTU_XRDC_CR_HRL_MASK)

#define RTU_XRDC_CR_MRF_MASK                     (0x80U)
#define RTU_XRDC_CR_MRF_SHIFT                    (7U)
#define RTU_XRDC_CR_MRF_WIDTH                    (1U)
#define RTU_XRDC_CR_MRF(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_CR_MRF_SHIFT)) & RTU_XRDC_CR_MRF_MASK)

#define RTU_XRDC_CR_VAW_MASK                     (0x100U)
#define RTU_XRDC_CR_VAW_SHIFT                    (8U)
#define RTU_XRDC_CR_VAW_WIDTH                    (1U)
#define RTU_XRDC_CR_VAW(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_CR_VAW_SHIFT)) & RTU_XRDC_CR_VAW_MASK)

#define RTU_XRDC_CR_LK1_MASK                     (0x40000000U)
#define RTU_XRDC_CR_LK1_SHIFT                    (30U)
#define RTU_XRDC_CR_LK1_WIDTH                    (1U)
#define RTU_XRDC_CR_LK1(x)                       (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_CR_LK1_SHIFT)) & RTU_XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define RTU_XRDC_HWCFG0_NDID_MASK                (0xFFU)
#define RTU_XRDC_HWCFG0_NDID_SHIFT               (0U)
#define RTU_XRDC_HWCFG0_NDID_WIDTH               (8U)
#define RTU_XRDC_HWCFG0_NDID(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG0_NDID_SHIFT)) & RTU_XRDC_HWCFG0_NDID_MASK)

#define RTU_XRDC_HWCFG0_NMSTR_MASK               (0xFF00U)
#define RTU_XRDC_HWCFG0_NMSTR_SHIFT              (8U)
#define RTU_XRDC_HWCFG0_NMSTR_WIDTH              (8U)
#define RTU_XRDC_HWCFG0_NMSTR(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG0_NMSTR_SHIFT)) & RTU_XRDC_HWCFG0_NMSTR_MASK)

#define RTU_XRDC_HWCFG0_NMRC_MASK                (0xFF0000U)
#define RTU_XRDC_HWCFG0_NMRC_SHIFT               (16U)
#define RTU_XRDC_HWCFG0_NMRC_WIDTH               (8U)
#define RTU_XRDC_HWCFG0_NMRC(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG0_NMRC_SHIFT)) & RTU_XRDC_HWCFG0_NMRC_MASK)

#define RTU_XRDC_HWCFG0_NPAC_MASK                (0xF000000U)
#define RTU_XRDC_HWCFG0_NPAC_SHIFT               (24U)
#define RTU_XRDC_HWCFG0_NPAC_WIDTH               (4U)
#define RTU_XRDC_HWCFG0_NPAC(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG0_NPAC_SHIFT)) & RTU_XRDC_HWCFG0_NPAC_MASK)

#define RTU_XRDC_HWCFG0_MID_MASK                 (0xF0000000U)
#define RTU_XRDC_HWCFG0_MID_SHIFT                (28U)
#define RTU_XRDC_HWCFG0_MID_WIDTH                (4U)
#define RTU_XRDC_HWCFG0_MID(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG0_MID_SHIFT)) & RTU_XRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define RTU_XRDC_HWCFG1_DID_MASK                 (0xFU)
#define RTU_XRDC_HWCFG1_DID_SHIFT                (0U)
#define RTU_XRDC_HWCFG1_DID_WIDTH                (4U)
#define RTU_XRDC_HWCFG1_DID(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_HWCFG1_DID_SHIFT)) & RTU_XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define RTU_XRDC_MDACFG_NMDAR_MASK               (0xFU)
#define RTU_XRDC_MDACFG_NMDAR_SHIFT              (0U)
#define RTU_XRDC_MDACFG_NMDAR_WIDTH              (4U)
#define RTU_XRDC_MDACFG_NMDAR(x)                 (((uint8_t)(((uint8_t)(x)) << RTU_XRDC_MDACFG_NMDAR_SHIFT)) & RTU_XRDC_MDACFG_NMDAR_MASK)

#define RTU_XRDC_MDACFG_NCM_MASK                 (0x80U)
#define RTU_XRDC_MDACFG_NCM_SHIFT                (7U)
#define RTU_XRDC_MDACFG_NCM_WIDTH                (1U)
#define RTU_XRDC_MDACFG_NCM(x)                   (((uint8_t)(((uint8_t)(x)) << RTU_XRDC_MDACFG_NCM_SHIFT)) & RTU_XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define RTU_XRDC_MRCFG_NMRGD_MASK                (0x1FU)
#define RTU_XRDC_MRCFG_NMRGD_SHIFT               (0U)
#define RTU_XRDC_MRCFG_NMRGD_WIDTH               (5U)
#define RTU_XRDC_MRCFG_NMRGD(x)                  (((uint8_t)(((uint8_t)(x)) << RTU_XRDC_MRCFG_NMRGD_SHIFT)) & RTU_XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define RTU_XRDC_DERRLOC_MRCINST_MASK            (0xFFFFU)
#define RTU_XRDC_DERRLOC_MRCINST_SHIFT           (0U)
#define RTU_XRDC_DERRLOC_MRCINST_WIDTH           (16U)
#define RTU_XRDC_DERRLOC_MRCINST(x)              (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERRLOC_MRCINST_SHIFT)) & RTU_XRDC_DERRLOC_MRCINST_MASK)

#define RTU_XRDC_DERRLOC_PACINST_MASK            (0xF0000U)
#define RTU_XRDC_DERRLOC_PACINST_SHIFT           (16U)
#define RTU_XRDC_DERRLOC_PACINST_WIDTH           (4U)
#define RTU_XRDC_DERRLOC_PACINST(x)              (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERRLOC_PACINST_SHIFT)) & RTU_XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W0 - Domain Error Word 0 */
/*! @{ */

#define RTU_XRDC_DERR_W0_EADDR_MASK              (0xFFFFFFFFU)
#define RTU_XRDC_DERR_W0_EADDR_SHIFT             (0U)
#define RTU_XRDC_DERR_W0_EADDR_WIDTH             (32U)
#define RTU_XRDC_DERR_W0_EADDR(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W0_EADDR_SHIFT)) & RTU_XRDC_DERR_W0_EADDR_MASK)
/*! @} */

/*! @name DERR_W1 - Domain Error Word 1 */
/*! @{ */

#define RTU_XRDC_DERR_W1_EDID_MASK               (0xFU)
#define RTU_XRDC_DERR_W1_EDID_SHIFT              (0U)
#define RTU_XRDC_DERR_W1_EDID_WIDTH              (4U)
#define RTU_XRDC_DERR_W1_EDID(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W1_EDID_SHIFT)) & RTU_XRDC_DERR_W1_EDID_MASK)

#define RTU_XRDC_DERR_W1_EATR_MASK               (0x700U)
#define RTU_XRDC_DERR_W1_EATR_SHIFT              (8U)
#define RTU_XRDC_DERR_W1_EATR_WIDTH              (3U)
#define RTU_XRDC_DERR_W1_EATR(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W1_EATR_SHIFT)) & RTU_XRDC_DERR_W1_EATR_MASK)

#define RTU_XRDC_DERR_W1_ERW_MASK                (0x800U)
#define RTU_XRDC_DERR_W1_ERW_SHIFT               (11U)
#define RTU_XRDC_DERR_W1_ERW_WIDTH               (1U)
#define RTU_XRDC_DERR_W1_ERW(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W1_ERW_SHIFT)) & RTU_XRDC_DERR_W1_ERW_MASK)

#define RTU_XRDC_DERR_W1_EPORT_MASK              (0x7000000U)
#define RTU_XRDC_DERR_W1_EPORT_SHIFT             (24U)
#define RTU_XRDC_DERR_W1_EPORT_WIDTH             (3U)
#define RTU_XRDC_DERR_W1_EPORT(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W1_EPORT_SHIFT)) & RTU_XRDC_DERR_W1_EPORT_MASK)

#define RTU_XRDC_DERR_W1_EST_MASK                (0xC0000000U)
#define RTU_XRDC_DERR_W1_EST_SHIFT               (30U)
#define RTU_XRDC_DERR_W1_EST_WIDTH               (2U)
#define RTU_XRDC_DERR_W1_EST(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W1_EST_SHIFT)) & RTU_XRDC_DERR_W1_EST_MASK)
/*! @} */

/*! @name DERR_W3 - Domain Error Word 3 */
/*! @{ */

#define RTU_XRDC_DERR_W3_RECR_MASK               (0xC0000000U)
#define RTU_XRDC_DERR_W3_RECR_SHIFT              (30U)
#define RTU_XRDC_DERR_W3_RECR_WIDTH              (2U)
#define RTU_XRDC_DERR_W3_RECR(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_DERR_W3_RECR_SHIFT)) & RTU_XRDC_DERR_W3_RECR_MASK)
/*! @} */

/*! @name MDA_W0_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_0_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_0_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_0_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_0_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_0_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_0_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_0_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_0_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_0_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_0_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_0_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_0_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_1_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_1_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_1_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_1_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_1_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_1_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_1_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_1_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_1_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_1_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_1_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_1_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_1_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_1_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_2_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_2_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_2_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_2_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_2_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_2_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_2_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_2_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_2_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_2_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_2_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_2_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_2_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_2_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_2_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_2_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_2_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_2_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_2_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_3_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_3_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_3_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_3_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_3_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_3_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_3_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_3_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_3_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_3_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_3_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_3_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_3_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_3_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_3_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_3_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_3_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_3_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_3_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_4_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_4_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_4_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_4_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_4_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_4_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_4_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_4_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_4_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_4_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_4_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_4_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_4_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_4_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_4_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_4_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_4_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_5_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_5_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_5_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_5_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_5_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_5_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_5_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_5_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_5_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_5_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_5_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_5_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_5_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_5_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_5_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_5_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_5_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_6_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_6_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_6_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_6_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_6_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_6_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_6_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_6_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_6_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_6_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_6_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_6_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_6_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_6_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_6_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_6_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_6_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_7_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_7_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_7_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_7_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_7_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_7_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_7_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_7_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_7_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_7_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_7_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_7_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_7_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_7_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_7_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_7_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_7_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_8_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_8_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_8_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_8_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_8_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_8_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_8_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_8_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_8_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_8_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_8_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_8_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_8_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_8_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_8_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_8_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_8_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W0_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W0_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W0_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W0_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W0_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W0_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W0_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W0_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W0_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W1_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W1_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W1_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W1_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W1_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W1_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W1_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W1_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W1_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W2_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W2_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W2_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W2_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W2_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W2_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W2_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W2_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W2_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W3_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W3_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W3_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W3_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W3_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W3_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W3_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W3_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W3_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W4_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W4_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W4_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W4_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W4_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W4_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W4_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W4_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W4_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W5_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W5_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W5_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W5_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W5_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W5_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W5_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W5_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W5_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W6_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W6_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W6_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W6_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W6_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W6_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W6_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W6_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W6_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_9_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_9_DFMT1_DID_MASK         (0xFU)
#define RTU_XRDC_MDA_W7_9_DFMT1_DID_SHIFT        (0U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DID_WIDTH        (4U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_PA_MASK          (0x30U)
#define RTU_XRDC_MDA_W7_9_DFMT1_PA_SHIFT         (4U)
#define RTU_XRDC_MDA_W7_9_DFMT1_PA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_9_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_SA_MASK          (0xC0U)
#define RTU_XRDC_MDA_W7_9_DFMT1_SA_SHIFT         (6U)
#define RTU_XRDC_MDA_W7_9_DFMT1_SA_WIDTH         (2U)
#define RTU_XRDC_MDA_W7_9_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_DIDB_MASK        (0x100U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DIDB_SHIFT       (8U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DIDB_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_LPID_MASK        (0xF000000U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPID_SHIFT       (24U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_LPE_MASK         (0x10000000U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPE_SHIFT        (28U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPE_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_DFMT_MASK        (0x20000000U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DFMT_SHIFT       (29U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DFMT_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_9_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_LK1_MASK         (0x40000000U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LK1_SHIFT        (30U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LK1_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_9_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_9_DFMT1_VLD_MASK         (0x80000000U)
#define RTU_XRDC_MDA_W7_9_DFMT1_VLD_SHIFT        (31U)
#define RTU_XRDC_MDA_W7_9_DFMT1_VLD_WIDTH        (1U)
#define RTU_XRDC_MDA_W7_9_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_9_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_9_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W0_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W0_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W0_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W0_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W0_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W0_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W0_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W1_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W1_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W1_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W1_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W1_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W1_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W1_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W1_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W1_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W1_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W2_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W2_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W2_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W2_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W2_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W2_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W2_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W2_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W2_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W2_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W3_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W3_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W3_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W3_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W3_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W3_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W3_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W3_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W3_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W3_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W4_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W4_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W4_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W4_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W4_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W4_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W4_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W4_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W4_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W4_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W5_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W5_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W5_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W5_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W5_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W5_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W5_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W5_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W5_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W5_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W6_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W6_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W6_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W6_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W6_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W6_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W6_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W6_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W6_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W6_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_10_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_10_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W7_10_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W7_10_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W7_10_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W7_10_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W7_10_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W7_10_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W7_10_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W7_10_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_10_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_10_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W7_10_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W7_10_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_10_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_10_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_10_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W0_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W0_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W0_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W0_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W0_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W0_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W0_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W1_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W1_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W1_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W1_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W1_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W1_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W1_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W1_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W1_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W1_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W1_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W1_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W1_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W1_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W1_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W2_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W2_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W2_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W2_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W2_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W2_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W2_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W2_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W2_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W2_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W2_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W2_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W2_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W2_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W2_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W3_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W3_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W3_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W3_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W3_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W3_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W3_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W3_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W3_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W3_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W3_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W3_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W3_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W3_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W3_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W4_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W4_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W4_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W4_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W4_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W4_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W4_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W4_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W4_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W4_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W4_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W4_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W4_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W4_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W4_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W5_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W5_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W5_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W5_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W5_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W5_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W5_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W5_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W5_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W5_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W5_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W5_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W5_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W5_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W5_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W6_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W6_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W6_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W6_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W6_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W6_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W6_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W6_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W6_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W6_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W6_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W6_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W6_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W6_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W6_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_11_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W7_11_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W7_11_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W7_11_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W7_11_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W7_11_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W7_11_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W7_11_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W7_11_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_LPID_MASK       (0xF000000U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPID_SHIFT      (24U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPID_WIDTH      (4U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPID(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_LPID_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_LPID_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_LPE_MASK        (0x10000000U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPE_SHIFT       (28U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPE_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LPE(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_LPE_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_LPE_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W7_11_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_11_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W7_11_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W7_11_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W7_11_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W7_11_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W7_11_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W7_11_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_12_DFMT1 - Master Domain Assignment */
/*! @{ */

#define RTU_XRDC_MDA_W0_12_DFMT1_DID_MASK        (0xFU)
#define RTU_XRDC_MDA_W0_12_DFMT1_DID_SHIFT       (0U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DID_WIDTH       (4U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DID(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_DID_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_DID_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_PA_MASK         (0x30U)
#define RTU_XRDC_MDA_W0_12_DFMT1_PA_SHIFT        (4U)
#define RTU_XRDC_MDA_W0_12_DFMT1_PA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_12_DFMT1_PA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_PA_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_PA_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_SA_MASK         (0xC0U)
#define RTU_XRDC_MDA_W0_12_DFMT1_SA_SHIFT        (6U)
#define RTU_XRDC_MDA_W0_12_DFMT1_SA_WIDTH        (2U)
#define RTU_XRDC_MDA_W0_12_DFMT1_SA(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_SA_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_SA_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_DIDB_MASK       (0x100U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DIDB_SHIFT      (8U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DIDB_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DIDB(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_DIDB_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_DIDB_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_DFMT_MASK       (0x20000000U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DFMT_SHIFT      (29U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DFMT_WIDTH      (1U)
#define RTU_XRDC_MDA_W0_12_DFMT1_DFMT(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_DFMT_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_DFMT_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_LK1_MASK        (0x40000000U)
#define RTU_XRDC_MDA_W0_12_DFMT1_LK1_SHIFT       (30U)
#define RTU_XRDC_MDA_W0_12_DFMT1_LK1_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_12_DFMT1_LK1(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_LK1_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_LK1_MASK)

#define RTU_XRDC_MDA_W0_12_DFMT1_VLD_MASK        (0x80000000U)
#define RTU_XRDC_MDA_W0_12_DFMT1_VLD_SHIFT       (31U)
#define RTU_XRDC_MDA_W0_12_DFMT1_VLD_WIDTH       (1U)
#define RTU_XRDC_MDA_W0_12_DFMT1_VLD(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_MDA_W0_12_DFMT1_VLD_SHIFT)) & RTU_XRDC_MDA_W0_12_DFMT1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define RTU_XRDC_PDAC_W0_D0ACP_MASK              (0x7U)
#define RTU_XRDC_PDAC_W0_D0ACP_SHIFT             (0U)
#define RTU_XRDC_PDAC_W0_D0ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D0ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D0ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D0ACP_MASK)

#define RTU_XRDC_PDAC_W0_D1ACP_MASK              (0x38U)
#define RTU_XRDC_PDAC_W0_D1ACP_SHIFT             (3U)
#define RTU_XRDC_PDAC_W0_D1ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D1ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D1ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D1ACP_MASK)

#define RTU_XRDC_PDAC_W0_D2ACP_MASK              (0x1C0U)
#define RTU_XRDC_PDAC_W0_D2ACP_SHIFT             (6U)
#define RTU_XRDC_PDAC_W0_D2ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D2ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D2ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D2ACP_MASK)

#define RTU_XRDC_PDAC_W0_D3ACP_MASK              (0xE00U)
#define RTU_XRDC_PDAC_W0_D3ACP_SHIFT             (9U)
#define RTU_XRDC_PDAC_W0_D3ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D3ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D3ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D3ACP_MASK)

#define RTU_XRDC_PDAC_W0_D4ACP_MASK              (0x7000U)
#define RTU_XRDC_PDAC_W0_D4ACP_SHIFT             (12U)
#define RTU_XRDC_PDAC_W0_D4ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D4ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D4ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D4ACP_MASK)

#define RTU_XRDC_PDAC_W0_D5ACP_MASK              (0x38000U)
#define RTU_XRDC_PDAC_W0_D5ACP_SHIFT             (15U)
#define RTU_XRDC_PDAC_W0_D5ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D5ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D5ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D5ACP_MASK)

#define RTU_XRDC_PDAC_W0_D6ACP_MASK              (0x1C0000U)
#define RTU_XRDC_PDAC_W0_D6ACP_SHIFT             (18U)
#define RTU_XRDC_PDAC_W0_D6ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D6ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D6ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D6ACP_MASK)

#define RTU_XRDC_PDAC_W0_D7ACP_MASK              (0xE00000U)
#define RTU_XRDC_PDAC_W0_D7ACP_SHIFT             (21U)
#define RTU_XRDC_PDAC_W0_D7ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W0_D7ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_D7ACP_SHIFT)) & RTU_XRDC_PDAC_W0_D7ACP_MASK)

#define RTU_XRDC_PDAC_W0_SNUM_MASK               (0xF000000U)
#define RTU_XRDC_PDAC_W0_SNUM_SHIFT              (24U)
#define RTU_XRDC_PDAC_W0_SNUM_WIDTH              (4U)
#define RTU_XRDC_PDAC_W0_SNUM(x)                 (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_SNUM_SHIFT)) & RTU_XRDC_PDAC_W0_SNUM_MASK)

#define RTU_XRDC_PDAC_W0_SE_MASK                 (0x40000000U)
#define RTU_XRDC_PDAC_W0_SE_SHIFT                (30U)
#define RTU_XRDC_PDAC_W0_SE_WIDTH                (1U)
#define RTU_XRDC_PDAC_W0_SE(x)                   (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W0_SE_SHIFT)) & RTU_XRDC_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define RTU_XRDC_PDAC_W1_D8ACP_MASK              (0x7U)
#define RTU_XRDC_PDAC_W1_D8ACP_SHIFT             (0U)
#define RTU_XRDC_PDAC_W1_D8ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W1_D8ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D8ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D8ACP_MASK)

#define RTU_XRDC_PDAC_W1_D9ACP_MASK              (0x38U)
#define RTU_XRDC_PDAC_W1_D9ACP_SHIFT             (3U)
#define RTU_XRDC_PDAC_W1_D9ACP_WIDTH             (3U)
#define RTU_XRDC_PDAC_W1_D9ACP(x)                (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D9ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D9ACP_MASK)

#define RTU_XRDC_PDAC_W1_D10ACP_MASK             (0x1C0U)
#define RTU_XRDC_PDAC_W1_D10ACP_SHIFT            (6U)
#define RTU_XRDC_PDAC_W1_D10ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D10ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D10ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D10ACP_MASK)

#define RTU_XRDC_PDAC_W1_D11ACP_MASK             (0xE00U)
#define RTU_XRDC_PDAC_W1_D11ACP_SHIFT            (9U)
#define RTU_XRDC_PDAC_W1_D11ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D11ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D11ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D11ACP_MASK)

#define RTU_XRDC_PDAC_W1_D12ACP_MASK             (0x7000U)
#define RTU_XRDC_PDAC_W1_D12ACP_SHIFT            (12U)
#define RTU_XRDC_PDAC_W1_D12ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D12ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D12ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D12ACP_MASK)

#define RTU_XRDC_PDAC_W1_D13ACP_MASK             (0x38000U)
#define RTU_XRDC_PDAC_W1_D13ACP_SHIFT            (15U)
#define RTU_XRDC_PDAC_W1_D13ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D13ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D13ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D13ACP_MASK)

#define RTU_XRDC_PDAC_W1_D14ACP_MASK             (0x1C0000U)
#define RTU_XRDC_PDAC_W1_D14ACP_SHIFT            (18U)
#define RTU_XRDC_PDAC_W1_D14ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D14ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D14ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D14ACP_MASK)

#define RTU_XRDC_PDAC_W1_D15ACP_MASK             (0xE00000U)
#define RTU_XRDC_PDAC_W1_D15ACP_SHIFT            (21U)
#define RTU_XRDC_PDAC_W1_D15ACP_WIDTH            (3U)
#define RTU_XRDC_PDAC_W1_D15ACP(x)               (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_D15ACP_SHIFT)) & RTU_XRDC_PDAC_W1_D15ACP_MASK)

#define RTU_XRDC_PDAC_W1_LK2_MASK                (0x60000000U)
#define RTU_XRDC_PDAC_W1_LK2_SHIFT               (29U)
#define RTU_XRDC_PDAC_W1_LK2_WIDTH               (2U)
#define RTU_XRDC_PDAC_W1_LK2(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_LK2_SHIFT)) & RTU_XRDC_PDAC_W1_LK2_MASK)

#define RTU_XRDC_PDAC_W1_VLD_MASK                (0x80000000U)
#define RTU_XRDC_PDAC_W1_VLD_SHIFT               (31U)
#define RTU_XRDC_PDAC_W1_VLD_WIDTH               (1U)
#define RTU_XRDC_PDAC_W1_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_PDAC_W1_VLD_SHIFT)) & RTU_XRDC_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name XRDC_MRGD_W0 - Memory Region Descriptor Word 0 */
/*! @{ */

#define RTU_XRDC_XRDC_MRGD_W0_SRTADDR_MASK       (0xFFFFFFE0U)
#define RTU_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT      (5U)
#define RTU_XRDC_XRDC_MRGD_W0_SRTADDR_WIDTH      (27U)
#define RTU_XRDC_XRDC_MRGD_W0_SRTADDR(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT)) & RTU_XRDC_XRDC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W1 - Memory Region Descriptor Word 1 */
/*! @{ */

#define RTU_XRDC_XRDC_MRGD_W1_ENDADDR_MASK       (0xFFFFFFE0U)
#define RTU_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT      (5U)
#define RTU_XRDC_XRDC_MRGD_W1_ENDADDR_WIDTH      (27U)
#define RTU_XRDC_XRDC_MRGD_W1_ENDADDR(x)         (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT)) & RTU_XRDC_XRDC_MRGD_W1_ENDADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W2 - Memory Region Descriptor Word 2 */
/*! @{ */

#define RTU_XRDC_XRDC_MRGD_W2_D0ACP_MASK         (0x7U)
#define RTU_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT        (0U)
#define RTU_XRDC_XRDC_MRGD_W2_D0ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D0ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D0ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D1ACP_MASK         (0x38U)
#define RTU_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D1ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D1ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D1ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D2ACP_MASK         (0x1C0U)
#define RTU_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT        (6U)
#define RTU_XRDC_XRDC_MRGD_W2_D2ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D2ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D2ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D3ACP_MASK         (0xE00U)
#define RTU_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT        (9U)
#define RTU_XRDC_XRDC_MRGD_W2_D3ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D3ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D3ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D4ACP_MASK         (0x7000U)
#define RTU_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT        (12U)
#define RTU_XRDC_XRDC_MRGD_W2_D4ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D4ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D4ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D5ACP_MASK         (0x38000U)
#define RTU_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT        (15U)
#define RTU_XRDC_XRDC_MRGD_W2_D5ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D5ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D5ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D6ACP_MASK         (0x1C0000U)
#define RTU_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT        (18U)
#define RTU_XRDC_XRDC_MRGD_W2_D6ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D6ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D6ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_D7ACP_MASK         (0xE00000U)
#define RTU_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT        (21U)
#define RTU_XRDC_XRDC_MRGD_W2_D7ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W2_D7ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_D7ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_SNUM_MASK          (0xF000000U)
#define RTU_XRDC_XRDC_MRGD_W2_SNUM_SHIFT         (24U)
#define RTU_XRDC_XRDC_MRGD_W2_SNUM_WIDTH         (4U)
#define RTU_XRDC_XRDC_MRGD_W2_SNUM(x)            (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_SNUM_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_SNUM_MASK)

#define RTU_XRDC_XRDC_MRGD_W2_SE_MASK            (0x40000000U)
#define RTU_XRDC_XRDC_MRGD_W2_SE_SHIFT           (30U)
#define RTU_XRDC_XRDC_MRGD_W2_SE_WIDTH           (1U)
#define RTU_XRDC_XRDC_MRGD_W2_SE(x)              (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W2_SE_SHIFT)) & RTU_XRDC_XRDC_MRGD_W2_SE_MASK)
/*! @} */

/*! @name XRDC_MRGD_W3 - Memory Region Descriptor Word 3 */
/*! @{ */

#define RTU_XRDC_XRDC_MRGD_W3_D8ACP_MASK         (0x7U)
#define RTU_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT        (0U)
#define RTU_XRDC_XRDC_MRGD_W3_D8ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D8ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D8ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D9ACP_MASK         (0x38U)
#define RTU_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT        (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D9ACP_WIDTH        (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D9ACP(x)           (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D9ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D10ACP_MASK        (0x1C0U)
#define RTU_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT       (6U)
#define RTU_XRDC_XRDC_MRGD_W3_D10ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D10ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D10ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D11ACP_MASK        (0xE00U)
#define RTU_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT       (9U)
#define RTU_XRDC_XRDC_MRGD_W3_D11ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D11ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D11ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D12ACP_MASK        (0x7000U)
#define RTU_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT       (12U)
#define RTU_XRDC_XRDC_MRGD_W3_D12ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D12ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D12ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D13ACP_MASK        (0x38000U)
#define RTU_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT       (15U)
#define RTU_XRDC_XRDC_MRGD_W3_D13ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D13ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D13ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D14ACP_MASK        (0x1C0000U)
#define RTU_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT       (18U)
#define RTU_XRDC_XRDC_MRGD_W3_D14ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D14ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D14ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_D15ACP_MASK        (0xE00000U)
#define RTU_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT       (21U)
#define RTU_XRDC_XRDC_MRGD_W3_D15ACP_WIDTH       (3U)
#define RTU_XRDC_XRDC_MRGD_W3_D15ACP(x)          (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_D15ACP_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_LK2_MASK           (0x60000000U)
#define RTU_XRDC_XRDC_MRGD_W3_LK2_SHIFT          (29U)
#define RTU_XRDC_XRDC_MRGD_W3_LK2_WIDTH          (2U)
#define RTU_XRDC_XRDC_MRGD_W3_LK2(x)             (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_LK2_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_LK2_MASK)

#define RTU_XRDC_XRDC_MRGD_W3_VLD_MASK           (0x80000000U)
#define RTU_XRDC_XRDC_MRGD_W3_VLD_SHIFT          (31U)
#define RTU_XRDC_XRDC_MRGD_W3_VLD_WIDTH          (1U)
#define RTU_XRDC_XRDC_MRGD_W3_VLD(x)             (((uint32_t)(((uint32_t)(x)) << RTU_XRDC_XRDC_MRGD_W3_VLD_SHIFT)) & RTU_XRDC_XRDC_MRGD_W3_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group RTU_XRDC_Register_Masks */

/*!
 * @}
 */ /* end of group RTU_XRDC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_RTU_XRDC_H_) */
