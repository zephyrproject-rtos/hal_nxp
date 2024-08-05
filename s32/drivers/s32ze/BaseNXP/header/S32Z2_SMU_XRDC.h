/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32Z2_SMU_XRDC.h
 * @version 2.3
 * @date 2024-05-03
 * @brief Peripheral Access Layer for S32Z2_SMU_XRDC
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
#if !defined(S32Z2_SMU_XRDC_H_)  /* Check if memory map has not been already included */
#define S32Z2_SMU_XRDC_H_

#include "S32Z2_COMMON.h"

/* ----------------------------------------------------------------------------
   -- SMU_XRDC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_XRDC_Peripheral_Access_Layer SMU_XRDC Peripheral Access Layer
 * @{
 */

/** SMU_XRDC - Size of Registers Arrays */
#define SMU_XRDC_MDAC_COUNT                       2u
#define SMU_XRDC_MRC_COUNT                        4u
#define SMU_XRDC_DERRLOC_COUNT                    16u
#define SMU_XRDC_DERRW0_COUNT                     18u
#define SMU_XRDC_PDAC_SLOT_PDACN_COUNT            113u
#define SMU_XRDC_PDAC_SLOT_COUNT                  2u
#define SMU_XRDC_MRCN_COUNT                       4u
#define SMU_XRDC_MRCN_MRGDN_COUNT                 16u

/** SMU_XRDC - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR;                                /**< Control, offset: 0x0 */
  uint8_t RESERVED_0[236];
  __I  uint32_t HWCFG0;                            /**< Hardware Configuration 0, offset: 0xF0 */
  __I  uint32_t HWCFG1;                            /**< Hardware Configuration 1, offset: 0xF4 */
  uint8_t RESERVED_1[8];
  __I  uint8_t MDACFG[SMU_XRDC_MDAC_COUNT];        /**< Master Domain Assignment Configuration, array offset: 0x100, array step: 0x1 */
  uint8_t RESERVED_2[62];
  __I  uint8_t MRCFG[SMU_XRDC_MRC_COUNT];          /**< Memory Region Configuration, array offset: 0x140, array step: 0x1 */
  uint8_t RESERVED_3[188];
  __I  uint32_t DERRLOC[SMU_XRDC_DERRLOC_COUNT];   /**< Domain Error Location, array offset: 0x200, array step: 0x4 */
  uint8_t RESERVED_4[448];
  struct SMU_XRDC_DERRW0 {                         /* offset: 0x400, array step: 0x10 */
    __I  uint32_t DERR_W0;                           /**< Domain Error Word 0, array offset: 0x400, array step: 0x10, valid indices: [0-3, 16-17] */
    __I  uint32_t DERR_W1;                           /**< Domain Error Word 1, array offset: 0x404, array step: 0x10, valid indices: [0-3, 16-17] */
    uint8_t RESERVED_0[4];
    __O  uint32_t DERR_W3;                           /**< Domain Error Word 3, array offset: 0x40C, array step: 0x10, valid indices: [0-3, 16-17] */
  } DERRW0[SMU_XRDC_DERRW0_COUNT];
  uint8_t RESERVED_5[736];
  __IO uint32_t MDA_W0_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x800 */
  __IO uint32_t MDA_W1_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x804 */
  __IO uint32_t MDA_W2_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x808 */
  __IO uint32_t MDA_W3_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x80C */
  __IO uint32_t MDA_W4_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x810 */
  __IO uint32_t MDA_W5_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x814 */
  __IO uint32_t MDA_W6_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x818 */
  __IO uint32_t MDA_W7_0_DFMT1;                    /**< Master Domain Assignment, offset: 0x81C */
  __IO uint32_t MDA_W0_1_DFMT1;                    /**< Master Domain Assignment, offset: 0x820 */
  uint8_t RESERVED_6[2012];
  struct SMU_XRDC_PDAC_SLOT {                      /* offset: 0x1000, array step: 0x400 */
    struct SMU_XRDC_PDAC_SLOT_PDACN {                /* offset: 0x1000, array step: index*0x400, index2*0x8 */
      __IO uint32_t PDAC_W0;                           /**< Peripheral Domain Access Control Word 0, array offset: 0x1000, array step: index*0x400, index2*0x8, valid indices: [0][0, 4-5, 8-9, 16-21, 24-25], [1][4, 12, 16, 24-27, 36, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112] */
      __IO uint32_t PDAC_W1;                           /**< Peripheral Domain Access Control Word 1, array offset: 0x1004, array step: index*0x400, index2*0x8, valid indices: [0][0, 4-5, 8-9, 16-21, 24-25], [1][4, 12, 16, 24-27, 36, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112] */
    } PDACN[SMU_XRDC_PDAC_SLOT_PDACN_COUNT];
    uint8_t RESERVED_0[120];
  } PDAC_SLOT[SMU_XRDC_PDAC_SLOT_COUNT];
  uint8_t RESERVED_7[2048];
  struct SMU_XRDC_MRGDN {                          /* offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W0;                      /**< Memory Region Descriptor Word 0, array offset: 0x2000, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W1;                      /**< Memory Region Descriptor Word 1, array offset: 0x2004, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W2;                      /**< Memory Region Descriptor Word 2, array offset: 0x2008, array step: index*0x200, index2*0x20 */
    __IO uint32_t XRDC_MRGD_W3;                      /**< Memory Region Descriptor Word 3, array offset: 0x200C, array step: index*0x200, index2*0x20 */
    uint8_t RESERVED_0[16];
  } MRGDN[SMU_XRDC_MRCN_COUNT][SMU_XRDC_MRCN_MRGDN_COUNT];
} SMU_XRDC_Type, *SMU_XRDC_MemMapPtr;

/** Number of instances of the SMU_XRDC module. */
#define SMU_XRDC_INSTANCE_COUNT                  (1u)

/* SMU_XRDC - Peripheral instance base addresses */
/** Peripheral SMU__XRDC base address */
#define IP_SMU__XRDC_BASE                        (0x45000000u)
/** Peripheral SMU__XRDC base pointer */
#define IP_SMU__XRDC                             ((SMU_XRDC_Type *)IP_SMU__XRDC_BASE)
/** Array initializer of SMU_XRDC peripheral base addresses */
#define IP_SMU_XRDC_BASE_ADDRS                   { IP_SMU__XRDC_BASE }
/** Array initializer of SMU_XRDC peripheral base pointers */
#define IP_SMU_XRDC_BASE_PTRS                    { IP_SMU__XRDC }

/* ----------------------------------------------------------------------------
   -- SMU_XRDC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SMU_XRDC_Register_Masks SMU_XRDC Register Masks
 * @{
 */

/*! @name CR - Control */
/*! @{ */

#define SMU_XRDC_CR_GVLD_MASK                    (0x1U)
#define SMU_XRDC_CR_GVLD_SHIFT                   (0U)
#define SMU_XRDC_CR_GVLD_WIDTH                   (1U)
#define SMU_XRDC_CR_GVLD(x)                      (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_CR_GVLD_SHIFT)) & SMU_XRDC_CR_GVLD_MASK)

#define SMU_XRDC_CR_HRL_MASK                     (0x1EU)
#define SMU_XRDC_CR_HRL_SHIFT                    (1U)
#define SMU_XRDC_CR_HRL_WIDTH                    (4U)
#define SMU_XRDC_CR_HRL(x)                       (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_CR_HRL_SHIFT)) & SMU_XRDC_CR_HRL_MASK)

#define SMU_XRDC_CR_MRF_MASK                     (0x80U)
#define SMU_XRDC_CR_MRF_SHIFT                    (7U)
#define SMU_XRDC_CR_MRF_WIDTH                    (1U)
#define SMU_XRDC_CR_MRF(x)                       (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_CR_MRF_SHIFT)) & SMU_XRDC_CR_MRF_MASK)

#define SMU_XRDC_CR_VAW_MASK                     (0x100U)
#define SMU_XRDC_CR_VAW_SHIFT                    (8U)
#define SMU_XRDC_CR_VAW_WIDTH                    (1U)
#define SMU_XRDC_CR_VAW(x)                       (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_CR_VAW_SHIFT)) & SMU_XRDC_CR_VAW_MASK)

#define SMU_XRDC_CR_LK1_MASK                     (0x40000000U)
#define SMU_XRDC_CR_LK1_SHIFT                    (30U)
#define SMU_XRDC_CR_LK1_WIDTH                    (1U)
#define SMU_XRDC_CR_LK1(x)                       (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_CR_LK1_SHIFT)) & SMU_XRDC_CR_LK1_MASK)
/*! @} */

/*! @name HWCFG0 - Hardware Configuration 0 */
/*! @{ */

#define SMU_XRDC_HWCFG0_NDID_MASK                (0xFFU)
#define SMU_XRDC_HWCFG0_NDID_SHIFT               (0U)
#define SMU_XRDC_HWCFG0_NDID_WIDTH               (8U)
#define SMU_XRDC_HWCFG0_NDID(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG0_NDID_SHIFT)) & SMU_XRDC_HWCFG0_NDID_MASK)

#define SMU_XRDC_HWCFG0_NMSTR_MASK               (0xFF00U)
#define SMU_XRDC_HWCFG0_NMSTR_SHIFT              (8U)
#define SMU_XRDC_HWCFG0_NMSTR_WIDTH              (8U)
#define SMU_XRDC_HWCFG0_NMSTR(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG0_NMSTR_SHIFT)) & SMU_XRDC_HWCFG0_NMSTR_MASK)

#define SMU_XRDC_HWCFG0_NMRC_MASK                (0xFF0000U)
#define SMU_XRDC_HWCFG0_NMRC_SHIFT               (16U)
#define SMU_XRDC_HWCFG0_NMRC_WIDTH               (8U)
#define SMU_XRDC_HWCFG0_NMRC(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG0_NMRC_SHIFT)) & SMU_XRDC_HWCFG0_NMRC_MASK)

#define SMU_XRDC_HWCFG0_NPAC_MASK                (0xF000000U)
#define SMU_XRDC_HWCFG0_NPAC_SHIFT               (24U)
#define SMU_XRDC_HWCFG0_NPAC_WIDTH               (4U)
#define SMU_XRDC_HWCFG0_NPAC(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG0_NPAC_SHIFT)) & SMU_XRDC_HWCFG0_NPAC_MASK)

#define SMU_XRDC_HWCFG0_MID_MASK                 (0xF0000000U)
#define SMU_XRDC_HWCFG0_MID_SHIFT                (28U)
#define SMU_XRDC_HWCFG0_MID_WIDTH                (4U)
#define SMU_XRDC_HWCFG0_MID(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG0_MID_SHIFT)) & SMU_XRDC_HWCFG0_MID_MASK)
/*! @} */

/*! @name HWCFG1 - Hardware Configuration 1 */
/*! @{ */

#define SMU_XRDC_HWCFG1_DID_MASK                 (0xFU)
#define SMU_XRDC_HWCFG1_DID_SHIFT                (0U)
#define SMU_XRDC_HWCFG1_DID_WIDTH                (4U)
#define SMU_XRDC_HWCFG1_DID(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_HWCFG1_DID_SHIFT)) & SMU_XRDC_HWCFG1_DID_MASK)
/*! @} */

/*! @name MDACFG - Master Domain Assignment Configuration */
/*! @{ */

#define SMU_XRDC_MDACFG_NMDAR_MASK               (0xFU)
#define SMU_XRDC_MDACFG_NMDAR_SHIFT              (0U)
#define SMU_XRDC_MDACFG_NMDAR_WIDTH              (4U)
#define SMU_XRDC_MDACFG_NMDAR(x)                 (((uint8_t)(((uint8_t)(x)) << SMU_XRDC_MDACFG_NMDAR_SHIFT)) & SMU_XRDC_MDACFG_NMDAR_MASK)

#define SMU_XRDC_MDACFG_NCM_MASK                 (0x80U)
#define SMU_XRDC_MDACFG_NCM_SHIFT                (7U)
#define SMU_XRDC_MDACFG_NCM_WIDTH                (1U)
#define SMU_XRDC_MDACFG_NCM(x)                   (((uint8_t)(((uint8_t)(x)) << SMU_XRDC_MDACFG_NCM_SHIFT)) & SMU_XRDC_MDACFG_NCM_MASK)
/*! @} */

/*! @name MRCFG - Memory Region Configuration */
/*! @{ */

#define SMU_XRDC_MRCFG_NMRGD_MASK                (0x1FU)
#define SMU_XRDC_MRCFG_NMRGD_SHIFT               (0U)
#define SMU_XRDC_MRCFG_NMRGD_WIDTH               (5U)
#define SMU_XRDC_MRCFG_NMRGD(x)                  (((uint8_t)(((uint8_t)(x)) << SMU_XRDC_MRCFG_NMRGD_SHIFT)) & SMU_XRDC_MRCFG_NMRGD_MASK)
/*! @} */

/*! @name DERRLOC - Domain Error Location */
/*! @{ */

#define SMU_XRDC_DERRLOC_MRCINST_MASK            (0xFFFFU)
#define SMU_XRDC_DERRLOC_MRCINST_SHIFT           (0U)
#define SMU_XRDC_DERRLOC_MRCINST_WIDTH           (16U)
#define SMU_XRDC_DERRLOC_MRCINST(x)              (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERRLOC_MRCINST_SHIFT)) & SMU_XRDC_DERRLOC_MRCINST_MASK)

#define SMU_XRDC_DERRLOC_PACINST_MASK            (0xF0000U)
#define SMU_XRDC_DERRLOC_PACINST_SHIFT           (16U)
#define SMU_XRDC_DERRLOC_PACINST_WIDTH           (4U)
#define SMU_XRDC_DERRLOC_PACINST(x)              (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERRLOC_PACINST_SHIFT)) & SMU_XRDC_DERRLOC_PACINST_MASK)
/*! @} */

/*! @name DERR_W0 - Domain Error Word 0 */
/*! @{ */

#define SMU_XRDC_DERR_W0_EADDR_MASK              (0xFFFFFFFFU)
#define SMU_XRDC_DERR_W0_EADDR_SHIFT             (0U)
#define SMU_XRDC_DERR_W0_EADDR_WIDTH             (32U)
#define SMU_XRDC_DERR_W0_EADDR(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W0_EADDR_SHIFT)) & SMU_XRDC_DERR_W0_EADDR_MASK)
/*! @} */

/*! @name DERR_W1 - Domain Error Word 1 */
/*! @{ */

#define SMU_XRDC_DERR_W1_EDID_MASK               (0xFU)
#define SMU_XRDC_DERR_W1_EDID_SHIFT              (0U)
#define SMU_XRDC_DERR_W1_EDID_WIDTH              (4U)
#define SMU_XRDC_DERR_W1_EDID(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W1_EDID_SHIFT)) & SMU_XRDC_DERR_W1_EDID_MASK)

#define SMU_XRDC_DERR_W1_EATR_MASK               (0x700U)
#define SMU_XRDC_DERR_W1_EATR_SHIFT              (8U)
#define SMU_XRDC_DERR_W1_EATR_WIDTH              (3U)
#define SMU_XRDC_DERR_W1_EATR(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W1_EATR_SHIFT)) & SMU_XRDC_DERR_W1_EATR_MASK)

#define SMU_XRDC_DERR_W1_ERW_MASK                (0x800U)
#define SMU_XRDC_DERR_W1_ERW_SHIFT               (11U)
#define SMU_XRDC_DERR_W1_ERW_WIDTH               (1U)
#define SMU_XRDC_DERR_W1_ERW(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W1_ERW_SHIFT)) & SMU_XRDC_DERR_W1_ERW_MASK)

#define SMU_XRDC_DERR_W1_EPORT_MASK              (0x7000000U)
#define SMU_XRDC_DERR_W1_EPORT_SHIFT             (24U)
#define SMU_XRDC_DERR_W1_EPORT_WIDTH             (3U)
#define SMU_XRDC_DERR_W1_EPORT(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W1_EPORT_SHIFT)) & SMU_XRDC_DERR_W1_EPORT_MASK)

#define SMU_XRDC_DERR_W1_EST_MASK                (0xC0000000U)
#define SMU_XRDC_DERR_W1_EST_SHIFT               (30U)
#define SMU_XRDC_DERR_W1_EST_WIDTH               (2U)
#define SMU_XRDC_DERR_W1_EST(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W1_EST_SHIFT)) & SMU_XRDC_DERR_W1_EST_MASK)
/*! @} */

/*! @name DERR_W3 - Domain Error Word 3 */
/*! @{ */

#define SMU_XRDC_DERR_W3_RECR_MASK               (0xC0000000U)
#define SMU_XRDC_DERR_W3_RECR_SHIFT              (30U)
#define SMU_XRDC_DERR_W3_RECR_WIDTH              (2U)
#define SMU_XRDC_DERR_W3_RECR(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_DERR_W3_RECR_SHIFT)) & SMU_XRDC_DERR_W3_RECR_MASK)
/*! @} */

/*! @name MDA_W0_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W0_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W0_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W0_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W0_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W0_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W0_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W0_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W0_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W0_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W0_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W0_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W0_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W0_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W0_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W0_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W1_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W1_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W1_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W1_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W1_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W1_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W1_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W1_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W1_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W1_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W1_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W1_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W1_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W1_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W1_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W1_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W1_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W2_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W2_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W2_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W2_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W2_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W2_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W2_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W2_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W2_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W2_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W2_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W2_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W2_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W2_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W2_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W2_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W2_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W3_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W3_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W3_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W3_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W3_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W3_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W3_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W3_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W3_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W3_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W3_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W3_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W3_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W3_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W3_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W3_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W3_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W4_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W4_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W4_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W4_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W4_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W4_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W4_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W4_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W4_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W4_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W4_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W4_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W4_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W4_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W4_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W4_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W4_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W5_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W5_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W5_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W5_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W5_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W5_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W5_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W5_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W5_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W5_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W5_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W5_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W5_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W5_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W5_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W5_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W5_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W6_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W6_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W6_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W6_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W6_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W6_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W6_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W6_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W6_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W6_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W6_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W6_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W6_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W6_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W6_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W6_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W6_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W7_0_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W7_0_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W7_0_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W7_0_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W7_0_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W7_0_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W7_0_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W7_0_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W7_0_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_LPID_MASK        (0xF000000U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPID_SHIFT       (24U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPID_WIDTH       (4U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPID(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_LPID_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_LPID_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_LPE_MASK         (0x10000000U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPE_SHIFT        (28U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPE_WIDTH        (1U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LPE(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_LPE_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_LPE_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W7_0_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W7_0_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W7_0_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W7_0_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W7_0_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W7_0_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W7_0_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W7_0_DFMT1_VLD_MASK)
/*! @} */

/*! @name MDA_W0_1_DFMT1 - Master Domain Assignment */
/*! @{ */

#define SMU_XRDC_MDA_W0_1_DFMT1_DID_MASK         (0xFU)
#define SMU_XRDC_MDA_W0_1_DFMT1_DID_SHIFT        (0U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DID_WIDTH        (4U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DID(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_DID_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_DID_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_PA_MASK          (0x30U)
#define SMU_XRDC_MDA_W0_1_DFMT1_PA_SHIFT         (4U)
#define SMU_XRDC_MDA_W0_1_DFMT1_PA_WIDTH         (2U)
#define SMU_XRDC_MDA_W0_1_DFMT1_PA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_PA_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_PA_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_SA_MASK          (0xC0U)
#define SMU_XRDC_MDA_W0_1_DFMT1_SA_SHIFT         (6U)
#define SMU_XRDC_MDA_W0_1_DFMT1_SA_WIDTH         (2U)
#define SMU_XRDC_MDA_W0_1_DFMT1_SA(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_SA_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_SA_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_DIDB_MASK        (0x100U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT       (8U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DIDB_WIDTH       (1U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DIDB(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_DIDB_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_DIDB_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_DFMT_MASK        (0x20000000U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT       (29U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DFMT_WIDTH       (1U)
#define SMU_XRDC_MDA_W0_1_DFMT1_DFMT(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_DFMT_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_DFMT_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_LK1_MASK         (0x40000000U)
#define SMU_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT        (30U)
#define SMU_XRDC_MDA_W0_1_DFMT1_LK1_WIDTH        (1U)
#define SMU_XRDC_MDA_W0_1_DFMT1_LK1(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_LK1_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_LK1_MASK)

#define SMU_XRDC_MDA_W0_1_DFMT1_VLD_MASK         (0x80000000U)
#define SMU_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT        (31U)
#define SMU_XRDC_MDA_W0_1_DFMT1_VLD_WIDTH        (1U)
#define SMU_XRDC_MDA_W0_1_DFMT1_VLD(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_MDA_W0_1_DFMT1_VLD_SHIFT)) & SMU_XRDC_MDA_W0_1_DFMT1_VLD_MASK)
/*! @} */

/*! @name PDAC_W0 - Peripheral Domain Access Control Word 0 */
/*! @{ */

#define SMU_XRDC_PDAC_W0_D0ACP_MASK              (0x7U)
#define SMU_XRDC_PDAC_W0_D0ACP_SHIFT             (0U)
#define SMU_XRDC_PDAC_W0_D0ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D0ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D0ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D0ACP_MASK)

#define SMU_XRDC_PDAC_W0_D1ACP_MASK              (0x38U)
#define SMU_XRDC_PDAC_W0_D1ACP_SHIFT             (3U)
#define SMU_XRDC_PDAC_W0_D1ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D1ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D1ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D1ACP_MASK)

#define SMU_XRDC_PDAC_W0_D2ACP_MASK              (0x1C0U)
#define SMU_XRDC_PDAC_W0_D2ACP_SHIFT             (6U)
#define SMU_XRDC_PDAC_W0_D2ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D2ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D2ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D2ACP_MASK)

#define SMU_XRDC_PDAC_W0_D3ACP_MASK              (0xE00U)
#define SMU_XRDC_PDAC_W0_D3ACP_SHIFT             (9U)
#define SMU_XRDC_PDAC_W0_D3ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D3ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D3ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D3ACP_MASK)

#define SMU_XRDC_PDAC_W0_D4ACP_MASK              (0x7000U)
#define SMU_XRDC_PDAC_W0_D4ACP_SHIFT             (12U)
#define SMU_XRDC_PDAC_W0_D4ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D4ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D4ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D4ACP_MASK)

#define SMU_XRDC_PDAC_W0_D5ACP_MASK              (0x38000U)
#define SMU_XRDC_PDAC_W0_D5ACP_SHIFT             (15U)
#define SMU_XRDC_PDAC_W0_D5ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D5ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D5ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D5ACP_MASK)

#define SMU_XRDC_PDAC_W0_D6ACP_MASK              (0x1C0000U)
#define SMU_XRDC_PDAC_W0_D6ACP_SHIFT             (18U)
#define SMU_XRDC_PDAC_W0_D6ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D6ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D6ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D6ACP_MASK)

#define SMU_XRDC_PDAC_W0_D7ACP_MASK              (0xE00000U)
#define SMU_XRDC_PDAC_W0_D7ACP_SHIFT             (21U)
#define SMU_XRDC_PDAC_W0_D7ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W0_D7ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_D7ACP_SHIFT)) & SMU_XRDC_PDAC_W0_D7ACP_MASK)

#define SMU_XRDC_PDAC_W0_SNUM_MASK               (0xF000000U)
#define SMU_XRDC_PDAC_W0_SNUM_SHIFT              (24U)
#define SMU_XRDC_PDAC_W0_SNUM_WIDTH              (4U)
#define SMU_XRDC_PDAC_W0_SNUM(x)                 (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_SNUM_SHIFT)) & SMU_XRDC_PDAC_W0_SNUM_MASK)

#define SMU_XRDC_PDAC_W0_SE_MASK                 (0x40000000U)
#define SMU_XRDC_PDAC_W0_SE_SHIFT                (30U)
#define SMU_XRDC_PDAC_W0_SE_WIDTH                (1U)
#define SMU_XRDC_PDAC_W0_SE(x)                   (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W0_SE_SHIFT)) & SMU_XRDC_PDAC_W0_SE_MASK)
/*! @} */

/*! @name PDAC_W1 - Peripheral Domain Access Control Word 1 */
/*! @{ */

#define SMU_XRDC_PDAC_W1_D8ACP_MASK              (0x7U)
#define SMU_XRDC_PDAC_W1_D8ACP_SHIFT             (0U)
#define SMU_XRDC_PDAC_W1_D8ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W1_D8ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D8ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D8ACP_MASK)

#define SMU_XRDC_PDAC_W1_D9ACP_MASK              (0x38U)
#define SMU_XRDC_PDAC_W1_D9ACP_SHIFT             (3U)
#define SMU_XRDC_PDAC_W1_D9ACP_WIDTH             (3U)
#define SMU_XRDC_PDAC_W1_D9ACP(x)                (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D9ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D9ACP_MASK)

#define SMU_XRDC_PDAC_W1_D10ACP_MASK             (0x1C0U)
#define SMU_XRDC_PDAC_W1_D10ACP_SHIFT            (6U)
#define SMU_XRDC_PDAC_W1_D10ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D10ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D10ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D10ACP_MASK)

#define SMU_XRDC_PDAC_W1_D11ACP_MASK             (0xE00U)
#define SMU_XRDC_PDAC_W1_D11ACP_SHIFT            (9U)
#define SMU_XRDC_PDAC_W1_D11ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D11ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D11ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D11ACP_MASK)

#define SMU_XRDC_PDAC_W1_D12ACP_MASK             (0x7000U)
#define SMU_XRDC_PDAC_W1_D12ACP_SHIFT            (12U)
#define SMU_XRDC_PDAC_W1_D12ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D12ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D12ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D12ACP_MASK)

#define SMU_XRDC_PDAC_W1_D13ACP_MASK             (0x38000U)
#define SMU_XRDC_PDAC_W1_D13ACP_SHIFT            (15U)
#define SMU_XRDC_PDAC_W1_D13ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D13ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D13ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D13ACP_MASK)

#define SMU_XRDC_PDAC_W1_D14ACP_MASK             (0x1C0000U)
#define SMU_XRDC_PDAC_W1_D14ACP_SHIFT            (18U)
#define SMU_XRDC_PDAC_W1_D14ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D14ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D14ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D14ACP_MASK)

#define SMU_XRDC_PDAC_W1_D15ACP_MASK             (0xE00000U)
#define SMU_XRDC_PDAC_W1_D15ACP_SHIFT            (21U)
#define SMU_XRDC_PDAC_W1_D15ACP_WIDTH            (3U)
#define SMU_XRDC_PDAC_W1_D15ACP(x)               (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_D15ACP_SHIFT)) & SMU_XRDC_PDAC_W1_D15ACP_MASK)

#define SMU_XRDC_PDAC_W1_LK2_MASK                (0x60000000U)
#define SMU_XRDC_PDAC_W1_LK2_SHIFT               (29U)
#define SMU_XRDC_PDAC_W1_LK2_WIDTH               (2U)
#define SMU_XRDC_PDAC_W1_LK2(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_LK2_SHIFT)) & SMU_XRDC_PDAC_W1_LK2_MASK)

#define SMU_XRDC_PDAC_W1_VLD_MASK                (0x80000000U)
#define SMU_XRDC_PDAC_W1_VLD_SHIFT               (31U)
#define SMU_XRDC_PDAC_W1_VLD_WIDTH               (1U)
#define SMU_XRDC_PDAC_W1_VLD(x)                  (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_PDAC_W1_VLD_SHIFT)) & SMU_XRDC_PDAC_W1_VLD_MASK)
/*! @} */

/*! @name XRDC_MRGD_W0 - Memory Region Descriptor Word 0 */
/*! @{ */

#define SMU_XRDC_XRDC_MRGD_W0_SRTADDR_MASK       (0xFFFFFFE0U)
#define SMU_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT      (5U)
#define SMU_XRDC_XRDC_MRGD_W0_SRTADDR_WIDTH      (27U)
#define SMU_XRDC_XRDC_MRGD_W0_SRTADDR(x)         (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W0_SRTADDR_SHIFT)) & SMU_XRDC_XRDC_MRGD_W0_SRTADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W1 - Memory Region Descriptor Word 1 */
/*! @{ */

#define SMU_XRDC_XRDC_MRGD_W1_ENDADDR_MASK       (0xFFFFFFE0U)
#define SMU_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT      (5U)
#define SMU_XRDC_XRDC_MRGD_W1_ENDADDR_WIDTH      (27U)
#define SMU_XRDC_XRDC_MRGD_W1_ENDADDR(x)         (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W1_ENDADDR_SHIFT)) & SMU_XRDC_XRDC_MRGD_W1_ENDADDR_MASK)
/*! @} */

/*! @name XRDC_MRGD_W2 - Memory Region Descriptor Word 2 */
/*! @{ */

#define SMU_XRDC_XRDC_MRGD_W2_D0ACP_MASK         (0x7U)
#define SMU_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT        (0U)
#define SMU_XRDC_XRDC_MRGD_W2_D0ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D0ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D0ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D0ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D1ACP_MASK         (0x38U)
#define SMU_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D1ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D1ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D1ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D1ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D2ACP_MASK         (0x1C0U)
#define SMU_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT        (6U)
#define SMU_XRDC_XRDC_MRGD_W2_D2ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D2ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D2ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D2ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D3ACP_MASK         (0xE00U)
#define SMU_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT        (9U)
#define SMU_XRDC_XRDC_MRGD_W2_D3ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D3ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D3ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D3ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D4ACP_MASK         (0x7000U)
#define SMU_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT        (12U)
#define SMU_XRDC_XRDC_MRGD_W2_D4ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D4ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D4ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D4ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D5ACP_MASK         (0x38000U)
#define SMU_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT        (15U)
#define SMU_XRDC_XRDC_MRGD_W2_D5ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D5ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D5ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D5ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D6ACP_MASK         (0x1C0000U)
#define SMU_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT        (18U)
#define SMU_XRDC_XRDC_MRGD_W2_D6ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D6ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D6ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D6ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_D7ACP_MASK         (0xE00000U)
#define SMU_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT        (21U)
#define SMU_XRDC_XRDC_MRGD_W2_D7ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W2_D7ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_D7ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_D7ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_SNUM_MASK          (0xF000000U)
#define SMU_XRDC_XRDC_MRGD_W2_SNUM_SHIFT         (24U)
#define SMU_XRDC_XRDC_MRGD_W2_SNUM_WIDTH         (4U)
#define SMU_XRDC_XRDC_MRGD_W2_SNUM(x)            (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_SNUM_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_SNUM_MASK)

#define SMU_XRDC_XRDC_MRGD_W2_SE_MASK            (0x40000000U)
#define SMU_XRDC_XRDC_MRGD_W2_SE_SHIFT           (30U)
#define SMU_XRDC_XRDC_MRGD_W2_SE_WIDTH           (1U)
#define SMU_XRDC_XRDC_MRGD_W2_SE(x)              (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W2_SE_SHIFT)) & SMU_XRDC_XRDC_MRGD_W2_SE_MASK)
/*! @} */

/*! @name XRDC_MRGD_W3 - Memory Region Descriptor Word 3 */
/*! @{ */

#define SMU_XRDC_XRDC_MRGD_W3_D8ACP_MASK         (0x7U)
#define SMU_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT        (0U)
#define SMU_XRDC_XRDC_MRGD_W3_D8ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D8ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D8ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D8ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D9ACP_MASK         (0x38U)
#define SMU_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT        (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D9ACP_WIDTH        (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D9ACP(x)           (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D9ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D9ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D10ACP_MASK        (0x1C0U)
#define SMU_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT       (6U)
#define SMU_XRDC_XRDC_MRGD_W3_D10ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D10ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D10ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D10ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D11ACP_MASK        (0xE00U)
#define SMU_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT       (9U)
#define SMU_XRDC_XRDC_MRGD_W3_D11ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D11ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D11ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D11ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D12ACP_MASK        (0x7000U)
#define SMU_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT       (12U)
#define SMU_XRDC_XRDC_MRGD_W3_D12ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D12ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D12ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D12ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D13ACP_MASK        (0x38000U)
#define SMU_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT       (15U)
#define SMU_XRDC_XRDC_MRGD_W3_D13ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D13ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D13ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D13ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D14ACP_MASK        (0x1C0000U)
#define SMU_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT       (18U)
#define SMU_XRDC_XRDC_MRGD_W3_D14ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D14ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D14ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D14ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_D15ACP_MASK        (0xE00000U)
#define SMU_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT       (21U)
#define SMU_XRDC_XRDC_MRGD_W3_D15ACP_WIDTH       (3U)
#define SMU_XRDC_XRDC_MRGD_W3_D15ACP(x)          (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_D15ACP_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_D15ACP_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_LK2_MASK           (0x60000000U)
#define SMU_XRDC_XRDC_MRGD_W3_LK2_SHIFT          (29U)
#define SMU_XRDC_XRDC_MRGD_W3_LK2_WIDTH          (2U)
#define SMU_XRDC_XRDC_MRGD_W3_LK2(x)             (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_LK2_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_LK2_MASK)

#define SMU_XRDC_XRDC_MRGD_W3_VLD_MASK           (0x80000000U)
#define SMU_XRDC_XRDC_MRGD_W3_VLD_SHIFT          (31U)
#define SMU_XRDC_XRDC_MRGD_W3_VLD_WIDTH          (1U)
#define SMU_XRDC_XRDC_MRGD_W3_VLD(x)             (((uint32_t)(((uint32_t)(x)) << SMU_XRDC_XRDC_MRGD_W3_VLD_SHIFT)) & SMU_XRDC_XRDC_MRGD_W3_VLD_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group SMU_XRDC_Register_Masks */

/*!
 * @}
 */ /* end of group SMU_XRDC_Peripheral_Access_Layer */

#endif  /* #if !defined(S32Z2_SMU_XRDC_H_) */
