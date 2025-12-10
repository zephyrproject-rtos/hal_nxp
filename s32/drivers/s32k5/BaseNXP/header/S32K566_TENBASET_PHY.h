/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_TENBASET_PHY.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_TENBASET_PHY
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
#if !defined(S32K566_TENBASET_PHY_H_)  /* Check if memory map has not been already included */
#define S32K566_TENBASET_PHY_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- TENBASET_PHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TENBASET_PHY_Peripheral_Access_Layer TENBASET_PHY Peripheral Access Layer
 * @{
 */

/** TENBASET_PHY - Register Layout Typedef */
typedef struct TENBASET_PHY_Struct {
  __IO uint16_t PHYCTRL;                           /**< PHY control, offset: 0x0 */
  __I  uint16_t PHYSTAT;                           /**< PHY status, offset: 0x2 */
  __I  uint16_t PHYID0;                            /**< PHY Identifier0, offset: 0x4 */
  __I  uint16_t PHYID1;                            /**< PHY Identifier1, offset: 0x6 */
  uint8_t RESERVED_0[131100];
  __I  uint16_t BASE1EXT;                          /**< PHY BASE-T1 Extended, offset: 0x20024 */
  uint8_t RESERVED_1[4162];
  __I  uint16_t PMAPMDCTRL;                        /**< PMA/PMD Control, offset: 0x21068 */
  uint8_t RESERVED_2[392];
  __IO uint16_t PMACTRL;                           /**< PMA CTRL, offset: 0x211F2 */
  __I  uint16_t PMASTAT;                           /**< PMA Status, offset: 0x211F4 */
  __IO uint16_t PMATM;                             /**< PMA Test Mode, offset: 0x211F6 */
  uint8_t RESERVED_3[262126];
  __IO uint16_t PCSCTRL;                           /**< PCS Control, offset: 0x611E6 */
  __I  uint16_t PCSSTAT;                           /**< PCS Status, offset: 0x611E8 */
  __I  uint16_t PCSDIAG1;                          /**< PCS Remote Jabber Counter, offset: 0x611EA */
  __I  uint16_t PCSDIAG2;                          /**< PCS Physical Collisions Counter, offset: 0x611EC */
  uint8_t RESERVED_4[3611154];
  __IO uint16_t MODECTRL;                          /**< MODE Control, offset: 0x3D2C00 */
  __IO uint16_t MODECFG;                           /**< Mode Configuration, offset: 0x3D2C02 */
  __I  uint16_t MODESTAT;                          /**< Mode Status, offset: 0x3D2C04 */
  uint8_t RESERVED_5[26];
  __IO uint16_t WKCTRL;                            /**< Wake Control, offset: 0x3D2C20 */
  __IO uint16_t WKCFG;                             /**< Wake Configuration, offset: 0x3D2C22 */
  uint8_t RESERVED_6[2];
  __IO uint16_t WUPCTRL;                           /**< Wake Control, offset: 0x3D2C26 */
  __IO uint16_t WUPCFG;                            /**< Wakeup Confguration, offset: 0x3D2C28 */
  __I  uint16_t WUPSTAT;                           /**< Wakeup Status, offset: 0x3D2C2A */
  uint8_t RESERVED_7[20];
  __IO uint16_t SMIDATA;                           /**< SMI Frame DATA, offset: 0x3D2C40 */
  __IO uint16_t SMICTRL;                           /**< SMI Control, offset: 0x3D2C42 */
  __IO uint16_t SMICFG;                            /**< SMI Configuration, offset: 0x3D2C44 */
  __I  uint16_t SMISTAT;                           /**< SMI Status, offset: 0x3D2C46 */
  uint8_t RESERVED_8[24];
  __IO uint16_t INTENCAPT1;                        /**< Interrupt Capture1, offset: 0x3D2C60 */
  __IO uint16_t INTENSET1;                         /**< Interrupt Enable Set1, offset: 0x3D2C62 */
  __IO uint16_t INTENCLR1;                         /**< Interrupt Enable Clear1, offset: 0x3D2C64 */
  __I  uint16_t INTSTAT1;                          /**< Interrupt Status1, offset: 0x3D2C66 */
  uint8_t RESERVED_9[8];
  __IO uint16_t INTENCAPT2;                        /**< Interrupt Capture2, offset: 0x3D2C70 */
  __IO uint16_t INTENSET2;                         /**< Interrupt Enable Set1, offset: 0x3D2C72 */
  __IO uint16_t INTENCLR2;                         /**< Interrupt Enable Clear2, offset: 0x3D2C74 */
  __I  uint16_t INTSTAT2;                          /**< Interrupt Status2, offset: 0x3D2C76 */
  uint8_t RESERVED_10[42];
  __IO uint16_t PLCADIAG2;                         /**< PLCA NXP prop diagnostics, offset: 0x3D2CA2 */
  __IO uint16_t PLCADIAG3;                         /**< PLCA Beacon Counter Diagnostics, offset: 0x3D2CA4 */
  __IO uint16_t PLCADIAG4;                         /**< PLCA TO Counter Diagnostics, offset: 0x3D2CA6 */
  __IO uint16_t TXCDIAG;                           /**< Transceiver Diagnostics, offset: 0x3D2CA8 */
  uint8_t RESERVED_11[6];
  __IO uint16_t MSKPLCADIAG1;                      /**< Mask Control PLCADIAG1 Flag, offset: 0x3D2CB0 */
  __IO uint16_t MSKPLCADIAG2;                      /**< Mask Control PLCADIAG2 Flags, offset: 0x3D2CB2 */
  __IO uint16_t MSKTXCDIAG;                        /**< Mask Control TXCDIAG Flag, offset: 0x3D2CB4 */
  uint8_t RESERVED_12[42];
  __IO uint16_t ACCESSCTRL;                        /**< Global Access Control, offset: 0x3D2CE0 */
  __IO uint16_t DBGCTRL;                           /**< Debug Control, offset: 0x3D2CE2 */
  uint8_t RESERVED_13[26];
  __I  uint16_t VERSION;                           /**< Version Information, offset: 0x3D2CFE */
  uint8_t RESERVED_14[157440];
  __I  uint16_t PLCAIDVER;                         /**< PLCA Identification and Version, offset: 0x3F9400 */
  __IO uint16_t PLCACTRL0;                         /**< PLCA Control0, offset: 0x3F9402 */
  __IO uint16_t PLCACTRL1;                         /**< PLCA Control1, offset: 0x3F9404 */
  __I  uint16_t PLCASTAT;                          /**< PLCA Status, offset: 0x3F9406 */
  __IO uint16_t PLCATOTMR;                         /**< PLCA Transmit Opportunity Timer, offset: 0x3F9408 */
  __IO uint16_t PLCABURST;                         /**< PLCA Burst Mode Configuration, offset: 0x3F940A */
  __IO uint16_t PLCADIAG1;                         /**< PLCA TC14 Adv diagnostics, offset: 0x3F940C */
} TENBASET_PHY_Type, *TENBASET_PHY_MemMapPtr;

/** Number of instances of the TENBASET_PHY module. */
#define TENBASET_PHY_INSTANCE_COUNT              (4u)

/* TENBASET_PHY - Peripheral instance base addresses */
/** Peripheral TENBASET_PHY_0 base address */
#define IP_TENBASET_PHY_0_BASE                   (0x400B8000u)
/** Peripheral TENBASET_PHY_0 base pointer */
#define IP_TENBASET_PHY_0                        ((TENBASET_PHY_Type *)IP_TENBASET_PHY_0_BASE)
/** Peripheral TENBASET_PHY_1 base address */
#define IP_TENBASET_PHY_1_BASE                   (0x400BC000u)
/** Peripheral TENBASET_PHY_1 base pointer */
#define IP_TENBASET_PHY_1                        ((TENBASET_PHY_Type *)IP_TENBASET_PHY_1_BASE)
/** Peripheral TENBASET_PHY_2 base address */
#define IP_TENBASET_PHY_2_BASE                   (0x400C0000u)
/** Peripheral TENBASET_PHY_2 base pointer */
#define IP_TENBASET_PHY_2                        ((TENBASET_PHY_Type *)IP_TENBASET_PHY_2_BASE)
/** Peripheral TENBASET_PHY_3 base address */
#define IP_TENBASET_PHY_3_BASE                   (0x400C4000u)
/** Peripheral TENBASET_PHY_3 base pointer */
#define IP_TENBASET_PHY_3                        ((TENBASET_PHY_Type *)IP_TENBASET_PHY_3_BASE)
/** Array initializer of TENBASET_PHY peripheral base addresses */
#define IP_TENBASET_PHY_BASE_ADDRS               { IP_TENBASET_PHY_0_BASE, IP_TENBASET_PHY_1_BASE, IP_TENBASET_PHY_2_BASE, IP_TENBASET_PHY_3_BASE }
/** Array initializer of TENBASET_PHY peripheral base pointers */
#define IP_TENBASET_PHY_BASE_PTRS                { IP_TENBASET_PHY_0, IP_TENBASET_PHY_1, IP_TENBASET_PHY_2, IP_TENBASET_PHY_3 }

/* ----------------------------------------------------------------------------
   -- TENBASET_PHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TENBASET_PHY_Register_Masks TENBASET_PHY Register Masks
 * @{
 */

/*! @name PHYCTRL - PHY control */
/*! @{ */

#define TENBASET_PHY_PHYCTRL_SPD1_MASK           (0x40U)
#define TENBASET_PHY_PHYCTRL_SPD1_SHIFT          (6U)
#define TENBASET_PHY_PHYCTRL_SPD1_WIDTH          (1U)
#define TENBASET_PHY_PHYCTRL_SPD1(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_SPD1_SHIFT)) & TENBASET_PHY_PHYCTRL_SPD1_MASK)

#define TENBASET_PHY_PHYCTRL_CTEST_MASK          (0x80U)
#define TENBASET_PHY_PHYCTRL_CTEST_SHIFT         (7U)
#define TENBASET_PHY_PHYCTRL_CTEST_WIDTH         (1U)
#define TENBASET_PHY_PHYCTRL_CTEST(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_CTEST_SHIFT)) & TENBASET_PHY_PHYCTRL_CTEST_MASK)

#define TENBASET_PHY_PHYCTRL_DUPLX_MASK          (0x100U)
#define TENBASET_PHY_PHYCTRL_DUPLX_SHIFT         (8U)
#define TENBASET_PHY_PHYCTRL_DUPLX_WIDTH         (1U)
#define TENBASET_PHY_PHYCTRL_DUPLX(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_DUPLX_SHIFT)) & TENBASET_PHY_PHYCTRL_DUPLX_MASK)

#define TENBASET_PHY_PHYCTRL_SPD0_MASK           (0x2000U)
#define TENBASET_PHY_PHYCTRL_SPD0_SHIFT          (13U)
#define TENBASET_PHY_PHYCTRL_SPD0_WIDTH          (1U)
#define TENBASET_PHY_PHYCTRL_SPD0(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_SPD0_SHIFT)) & TENBASET_PHY_PHYCTRL_SPD0_MASK)

#define TENBASET_PHY_PHYCTRL_RESET_MASK          (0x8000U)
#define TENBASET_PHY_PHYCTRL_RESET_SHIFT         (15U)
#define TENBASET_PHY_PHYCTRL_RESET_WIDTH         (1U)
#define TENBASET_PHY_PHYCTRL_RESET(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYCTRL_RESET_SHIFT)) & TENBASET_PHY_PHYCTRL_RESET_MASK)
/*! @} */

/*! @name PHYSTAT - PHY status */
/*! @{ */

#define TENBASET_PHY_PHYSTAT_LJAB_MASK           (0x2U)
#define TENBASET_PHY_PHYSTAT_LJAB_SHIFT          (1U)
#define TENBASET_PHY_PHYSTAT_LJAB_WIDTH          (1U)
#define TENBASET_PHY_PHYSTAT_LJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYSTAT_LJAB_SHIFT)) & TENBASET_PHY_PHYSTAT_LJAB_MASK)

#define TENBASET_PHY_PHYSTAT_RJAB_MASK           (0x10U)
#define TENBASET_PHY_PHYSTAT_RJAB_SHIFT          (4U)
#define TENBASET_PHY_PHYSTAT_RJAB_WIDTH          (1U)
#define TENBASET_PHY_PHYSTAT_RJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYSTAT_RJAB_SHIFT)) & TENBASET_PHY_PHYSTAT_RJAB_MASK)
/*! @} */

/*! @name PHYID0 - PHY Identifier0 */
/*! @{ */

#define TENBASET_PHY_PHYID0_OUI_03_18_MASK       (0xFFFFU)
#define TENBASET_PHY_PHYID0_OUI_03_18_SHIFT      (0U)
#define TENBASET_PHY_PHYID0_OUI_03_18_WIDTH      (16U)
#define TENBASET_PHY_PHYID0_OUI_03_18(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID0_OUI_03_18_SHIFT)) & TENBASET_PHY_PHYID0_OUI_03_18_MASK)
/*! @} */

/*! @name PHYID1 - PHY Identifier1 */
/*! @{ */

#define TENBASET_PHY_PHYID1_ICREVISION_MASK      (0xFU)
#define TENBASET_PHY_PHYID1_ICREVISION_SHIFT     (0U)
#define TENBASET_PHY_PHYID1_ICREVISION_WIDTH     (4U)
#define TENBASET_PHY_PHYID1_ICREVISION(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_ICREVISION_SHIFT)) & TENBASET_PHY_PHYID1_ICREVISION_MASK)

#define TENBASET_PHY_PHYID1_ICMODEL_MASK         (0x3F0U)
#define TENBASET_PHY_PHYID1_ICMODEL_SHIFT        (4U)
#define TENBASET_PHY_PHYID1_ICMODEL_WIDTH        (6U)
#define TENBASET_PHY_PHYID1_ICMODEL(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_ICMODEL_SHIFT)) & TENBASET_PHY_PHYID1_ICMODEL_MASK)

#define TENBASET_PHY_PHYID1_OUI_19_24_MASK       (0xFC00U)
#define TENBASET_PHY_PHYID1_OUI_19_24_SHIFT      (10U)
#define TENBASET_PHY_PHYID1_OUI_19_24_WIDTH      (6U)
#define TENBASET_PHY_PHYID1_OUI_19_24(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PHYID1_OUI_19_24_SHIFT)) & TENBASET_PHY_PHYID1_OUI_19_24_MASK)
/*! @} */

/*! @name BASE1EXT - PHY BASE-T1 Extended */
/*! @{ */

#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_MASK (0xFFFFU)
#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_SHIFT (0U)
#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_WIDTH (16U)
#define TENBASET_PHY_BASE1EXT_BASET1EXT_BIT(x)   (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_SHIFT)) & TENBASET_PHY_BASE1EXT_BASET1EXT_BIT_MASK)
/*! @} */

/*! @name PMAPMDCTRL - PMA/PMD Control */
/*! @{ */

#define TENBASET_PHY_PMAPMDCTRL_TYPE_MASK        (0xFU)
#define TENBASET_PHY_PMAPMDCTRL_TYPE_SHIFT       (0U)
#define TENBASET_PHY_PMAPMDCTRL_TYPE_WIDTH       (4U)
#define TENBASET_PHY_PMAPMDCTRL_TYPE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMAPMDCTRL_TYPE_SHIFT)) & TENBASET_PHY_PMAPMDCTRL_TYPE_MASK)
/*! @} */

/*! @name PMACTRL - PMA CTRL */
/*! @{ */

#define TENBASET_PHY_PMACTRL_LOOP_MASK           (0x1U)
#define TENBASET_PHY_PMACTRL_LOOP_SHIFT          (0U)
#define TENBASET_PHY_PMACTRL_LOOP_WIDTH          (1U)
#define TENBASET_PHY_PMACTRL_LOOP(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_LOOP_SHIFT)) & TENBASET_PHY_PMACTRL_LOOP_MASK)

#define TENBASET_PHY_PMACTRL_MULT_MASK           (0x400U)
#define TENBASET_PHY_PMACTRL_MULT_SHIFT          (10U)
#define TENBASET_PHY_PMACTRL_MULT_WIDTH          (1U)
#define TENBASET_PHY_PMACTRL_MULT(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_MULT_SHIFT)) & TENBASET_PHY_PMACTRL_MULT_MASK)

#define TENBASET_PHY_PMACTRL_TXDIS_MASK          (0x4000U)
#define TENBASET_PHY_PMACTRL_TXDIS_SHIFT         (14U)
#define TENBASET_PHY_PMACTRL_TXDIS_WIDTH         (1U)
#define TENBASET_PHY_PMACTRL_TXDIS(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_TXDIS_SHIFT)) & TENBASET_PHY_PMACTRL_TXDIS_MASK)

#define TENBASET_PHY_PMACTRL_RST_MASK            (0x8000U)
#define TENBASET_PHY_PMACTRL_RST_SHIFT           (15U)
#define TENBASET_PHY_PMACTRL_RST_WIDTH           (1U)
#define TENBASET_PHY_PMACTRL_RST(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMACTRL_RST_SHIFT)) & TENBASET_PHY_PMACTRL_RST_MASK)
/*! @} */

/*! @name PMASTAT - PMA Status */
/*! @{ */

#define TENBASET_PHY_PMASTAT_RJAB_MASK           (0x2U)
#define TENBASET_PHY_PMASTAT_RJAB_SHIFT          (1U)
#define TENBASET_PHY_PMASTAT_RJAB_WIDTH          (1U)
#define TENBASET_PHY_PMASTAT_RJAB(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_RJAB_SHIFT)) & TENBASET_PHY_PMASTAT_RJAB_MASK)

#define TENBASET_PHY_PMASTAT_RFLTA_MASK          (0x200U)
#define TENBASET_PHY_PMASTAT_RFLTA_SHIFT         (9U)
#define TENBASET_PHY_PMASTAT_RFLTA_WIDTH         (1U)
#define TENBASET_PHY_PMASTAT_RFLTA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_RFLTA_SHIFT)) & TENBASET_PHY_PMASTAT_RFLTA_MASK)

#define TENBASET_PHY_PMASTAT_MULTA_MASK          (0x400U)
#define TENBASET_PHY_PMASTAT_MULTA_SHIFT         (10U)
#define TENBASET_PHY_PMASTAT_MULTA_WIDTH         (1U)
#define TENBASET_PHY_PMASTAT_MULTA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_MULTA_SHIFT)) & TENBASET_PHY_PMASTAT_MULTA_MASK)

#define TENBASET_PHY_PMASTAT_LPWA_MASK           (0x800U)
#define TENBASET_PHY_PMASTAT_LPWA_SHIFT          (11U)
#define TENBASET_PHY_PMASTAT_LPWA_WIDTH          (1U)
#define TENBASET_PHY_PMASTAT_LPWA(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_LPWA_SHIFT)) & TENBASET_PHY_PMASTAT_LPWA_MASK)

#define TENBASET_PHY_PMASTAT_LOOPA_MASK          (0x2000U)
#define TENBASET_PHY_PMASTAT_LOOPA_SHIFT         (13U)
#define TENBASET_PHY_PMASTAT_LOOPA_WIDTH         (1U)
#define TENBASET_PHY_PMASTAT_LOOPA(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMASTAT_LOOPA_SHIFT)) & TENBASET_PHY_PMASTAT_LOOPA_MASK)
/*! @} */

/*! @name PMATM - PMA Test Mode */
/*! @{ */

#define TENBASET_PHY_PMATM_PATTERN_MASK          (0xE000U)
#define TENBASET_PHY_PMATM_PATTERN_SHIFT         (13U)
#define TENBASET_PHY_PMATM_PATTERN_WIDTH         (3U)
#define TENBASET_PHY_PMATM_PATTERN(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PMATM_PATTERN_SHIFT)) & TENBASET_PHY_PMATM_PATTERN_MASK)
/*! @} */

/*! @name PCSCTRL - PCS Control */
/*! @{ */

#define TENBASET_PHY_PCSCTRL_DUPLX_MASK          (0x100U)
#define TENBASET_PHY_PCSCTRL_DUPLX_SHIFT         (8U)
#define TENBASET_PHY_PCSCTRL_DUPLX_WIDTH         (1U)
#define TENBASET_PHY_PCSCTRL_DUPLX(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_DUPLX_SHIFT)) & TENBASET_PHY_PCSCTRL_DUPLX_MASK)

#define TENBASET_PHY_PCSCTRL_LOOP_MASK           (0x4000U)
#define TENBASET_PHY_PCSCTRL_LOOP_SHIFT          (14U)
#define TENBASET_PHY_PCSCTRL_LOOP_WIDTH          (1U)
#define TENBASET_PHY_PCSCTRL_LOOP(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_LOOP_SHIFT)) & TENBASET_PHY_PCSCTRL_LOOP_MASK)

#define TENBASET_PHY_PCSCTRL_RST_MASK            (0x8000U)
#define TENBASET_PHY_PCSCTRL_RST_SHIFT           (15U)
#define TENBASET_PHY_PCSCTRL_RST_WIDTH           (1U)
#define TENBASET_PHY_PCSCTRL_RST(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSCTRL_RST_SHIFT)) & TENBASET_PHY_PCSCTRL_RST_MASK)
/*! @} */

/*! @name PCSSTAT - PCS Status */
/*! @{ */

#define TENBASET_PHY_PCSSTAT_JAB_MASK            (0x80U)
#define TENBASET_PHY_PCSSTAT_JAB_SHIFT           (7U)
#define TENBASET_PHY_PCSSTAT_JAB_WIDTH           (1U)
#define TENBASET_PHY_PCSSTAT_JAB(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSSTAT_JAB_SHIFT)) & TENBASET_PHY_PCSSTAT_JAB_MASK)
/*! @} */

/*! @name PCSDIAG1 - PCS Remote Jabber Counter */
/*! @{ */

#define TENBASET_PHY_PCSDIAG1_REMJABCNT_MASK     (0xFFFFU)
#define TENBASET_PHY_PCSDIAG1_REMJABCNT_SHIFT    (0U)
#define TENBASET_PHY_PCSDIAG1_REMJABCNT_WIDTH    (16U)
#define TENBASET_PHY_PCSDIAG1_REMJABCNT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSDIAG1_REMJABCNT_SHIFT)) & TENBASET_PHY_PCSDIAG1_REMJABCNT_MASK)
/*! @} */

/*! @name PCSDIAG2 - PCS Physical Collisions Counter */
/*! @{ */

#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT_MASK     (0xFFFFU)
#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT_SHIFT    (0U)
#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT_WIDTH    (16U)
#define TENBASET_PHY_PCSDIAG2_PHYCOLCNT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PCSDIAG2_PHYCOLCNT_SHIFT)) & TENBASET_PHY_PCSDIAG2_PHYCOLCNT_MASK)
/*! @} */

/*! @name MODECTRL - MODE Control */
/*! @{ */

#define TENBASET_PHY_MODECTRL_CMD_MASK           (0x7U)
#define TENBASET_PHY_MODECTRL_CMD_SHIFT          (0U)
#define TENBASET_PHY_MODECTRL_CMD_WIDTH          (3U)
#define TENBASET_PHY_MODECTRL_CMD(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECTRL_CMD_SHIFT)) & TENBASET_PHY_MODECTRL_CMD_MASK)
/*! @} */

/*! @name MODECFG - Mode Configuration */
/*! @{ */

#define TENBASET_PHY_MODECFG_LCLWKENA_MASK       (0x1U)
#define TENBASET_PHY_MODECFG_LCLWKENA_SHIFT      (0U)
#define TENBASET_PHY_MODECFG_LCLWKENA_WIDTH      (1U)
#define TENBASET_PHY_MODECFG_LCLWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_LCLWKENA_SHIFT)) & TENBASET_PHY_MODECFG_LCLWKENA_MASK)

#define TENBASET_PHY_MODECFG_REMWKENA_MASK       (0x2U)
#define TENBASET_PHY_MODECFG_REMWKENA_SHIFT      (1U)
#define TENBASET_PHY_MODECFG_REMWKENA_WIDTH      (1U)
#define TENBASET_PHY_MODECFG_REMWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_REMWKENA_SHIFT)) & TENBASET_PHY_MODECFG_REMWKENA_MASK)

#define TENBASET_PHY_MODECFG_SSPWKENA_MASK       (0x4U)
#define TENBASET_PHY_MODECFG_SSPWKENA_SHIFT      (2U)
#define TENBASET_PHY_MODECFG_SSPWKENA_WIDTH      (1U)
#define TENBASET_PHY_MODECFG_SSPWKENA(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODECFG_SSPWKENA_SHIFT)) & TENBASET_PHY_MODECFG_SSPWKENA_MASK)
/*! @} */

/*! @name MODESTAT - Mode Status */
/*! @{ */

#define TENBASET_PHY_MODESTAT_STAT_MASK          (0xFU)
#define TENBASET_PHY_MODESTAT_STAT_SHIFT         (0U)
#define TENBASET_PHY_MODESTAT_STAT_WIDTH         (4U)
#define TENBASET_PHY_MODESTAT_STAT(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODESTAT_STAT_SHIFT)) & TENBASET_PHY_MODESTAT_STAT_MASK)

#define TENBASET_PHY_MODESTAT_SILENTTO_MASK      (0x10U)
#define TENBASET_PHY_MODESTAT_SILENTTO_SHIFT     (4U)
#define TENBASET_PHY_MODESTAT_SILENTTO_WIDTH     (1U)
#define TENBASET_PHY_MODESTAT_SILENTTO(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MODESTAT_SILENTTO_SHIFT)) & TENBASET_PHY_MODESTAT_SILENTTO_MASK)
/*! @} */

/*! @name WKCTRL - Wake Control */
/*! @{ */

#define TENBASET_PHY_WKCTRL_REMWKFDW_MASK        (0x1U)
#define TENBASET_PHY_WKCTRL_REMWKFDW_SHIFT       (0U)
#define TENBASET_PHY_WKCTRL_REMWKFDW_WIDTH       (1U)
#define TENBASET_PHY_WKCTRL_REMWKFDW(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WKCTRL_REMWKFDW_SHIFT)) & TENBASET_PHY_WKCTRL_REMWKFDW_MASK)
/*! @} */

/*! @name WKCFG - Wake Configuration */
/*! @{ */

#define TENBASET_PHY_WKCFG_REMKWKFDW_MASK        (0x1U)
#define TENBASET_PHY_WKCFG_REMKWKFDW_SHIFT       (0U)
#define TENBASET_PHY_WKCFG_REMKWKFDW_WIDTH       (1U)
#define TENBASET_PHY_WKCFG_REMKWKFDW(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WKCFG_REMKWKFDW_SHIFT)) & TENBASET_PHY_WKCFG_REMKWKFDW_MASK)
/*! @} */

/*! @name WUPCTRL - Wake Control */
/*! @{ */

#define TENBASET_PHY_WUPCTRL_WUPCMD_MASK         (0x1U)
#define TENBASET_PHY_WUPCTRL_WUPCMD_SHIFT        (0U)
#define TENBASET_PHY_WUPCTRL_WUPCMD_WIDTH        (1U)
#define TENBASET_PHY_WUPCTRL_WUPCMD(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCTRL_WUPCMD_SHIFT)) & TENBASET_PHY_WUPCTRL_WUPCMD_MASK)

#define TENBASET_PHY_WUPCTRL_ABORTCMD_MASK       (0x2U)
#define TENBASET_PHY_WUPCTRL_ABORTCMD_SHIFT      (1U)
#define TENBASET_PHY_WUPCTRL_ABORTCMD_WIDTH      (1U)
#define TENBASET_PHY_WUPCTRL_ABORTCMD(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCTRL_ABORTCMD_SHIFT)) & TENBASET_PHY_WUPCTRL_ABORTCMD_MASK)
/*! @} */

/*! @name WUPCFG - Wakeup Confguration */
/*! @{ */

#define TENBASET_PHY_WUPCFG_LCLWKWUP_MASK        (0x1U)
#define TENBASET_PHY_WUPCFG_LCLWKWUP_SHIFT       (0U)
#define TENBASET_PHY_WUPCFG_LCLWKWUP_WIDTH       (1U)
#define TENBASET_PHY_WUPCFG_LCLWKWUP(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCFG_LCLWKWUP_SHIFT)) & TENBASET_PHY_WUPCFG_LCLWKWUP_MASK)

#define TENBASET_PHY_WUPCFG_WUPTIMEOUT_MASK      (0xFF00U)
#define TENBASET_PHY_WUPCFG_WUPTIMEOUT_SHIFT     (8U)
#define TENBASET_PHY_WUPCFG_WUPTIMEOUT_WIDTH     (8U)
#define TENBASET_PHY_WUPCFG_WUPTIMEOUT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPCFG_WUPTIMEOUT_SHIFT)) & TENBASET_PHY_WUPCFG_WUPTIMEOUT_MASK)
/*! @} */

/*! @name WUPSTAT - Wakeup Status */
/*! @{ */

#define TENBASET_PHY_WUPSTAT_STAT_MASK           (0x3U)
#define TENBASET_PHY_WUPSTAT_STAT_SHIFT          (0U)
#define TENBASET_PHY_WUPSTAT_STAT_WIDTH          (2U)
#define TENBASET_PHY_WUPSTAT_STAT(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPSTAT_STAT_SHIFT)) & TENBASET_PHY_WUPSTAT_STAT_MASK)

#define TENBASET_PHY_WUPSTAT_ERRCODE_MASK        (0x1CU)
#define TENBASET_PHY_WUPSTAT_ERRCODE_SHIFT       (2U)
#define TENBASET_PHY_WUPSTAT_ERRCODE_WIDTH       (3U)
#define TENBASET_PHY_WUPSTAT_ERRCODE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_WUPSTAT_ERRCODE_SHIFT)) & TENBASET_PHY_WUPSTAT_ERRCODE_MASK)
/*! @} */

/*! @name SMIDATA - SMI Frame DATA */
/*! @{ */

#define TENBASET_PHY_SMIDATA_DATA_MASK           (0xFFFFU)
#define TENBASET_PHY_SMIDATA_DATA_SHIFT          (0U)
#define TENBASET_PHY_SMIDATA_DATA_WIDTH          (16U)
#define TENBASET_PHY_SMIDATA_DATA(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMIDATA_DATA_SHIFT)) & TENBASET_PHY_SMIDATA_DATA_MASK)
/*! @} */

/*! @name SMICTRL - SMI Control */
/*! @{ */

#define TENBASET_PHY_SMICTRL_TA_MASK             (0x3U)
#define TENBASET_PHY_SMICTRL_TA_SHIFT            (0U)
#define TENBASET_PHY_SMICTRL_TA_WIDTH            (2U)
#define TENBASET_PHY_SMICTRL_TA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_TA_SHIFT)) & TENBASET_PHY_SMICTRL_TA_MASK)

#define TENBASET_PHY_SMICTRL_RA_MASK             (0x7CU)
#define TENBASET_PHY_SMICTRL_RA_SHIFT            (2U)
#define TENBASET_PHY_SMICTRL_RA_WIDTH            (5U)
#define TENBASET_PHY_SMICTRL_RA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_RA_SHIFT)) & TENBASET_PHY_SMICTRL_RA_MASK)

#define TENBASET_PHY_SMICTRL_PA_MASK             (0xF80U)
#define TENBASET_PHY_SMICTRL_PA_SHIFT            (7U)
#define TENBASET_PHY_SMICTRL_PA_WIDTH            (5U)
#define TENBASET_PHY_SMICTRL_PA(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_PA_SHIFT)) & TENBASET_PHY_SMICTRL_PA_MASK)

#define TENBASET_PHY_SMICTRL_OP_MASK             (0x3000U)
#define TENBASET_PHY_SMICTRL_OP_SHIFT            (12U)
#define TENBASET_PHY_SMICTRL_OP_WIDTH            (2U)
#define TENBASET_PHY_SMICTRL_OP(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_OP_SHIFT)) & TENBASET_PHY_SMICTRL_OP_MASK)

#define TENBASET_PHY_SMICTRL_ST_MASK             (0xC000U)
#define TENBASET_PHY_SMICTRL_ST_SHIFT            (14U)
#define TENBASET_PHY_SMICTRL_ST_WIDTH            (2U)
#define TENBASET_PHY_SMICTRL_ST(x)               (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICTRL_ST_SHIFT)) & TENBASET_PHY_SMICTRL_ST_MASK)
/*! @} */

/*! @name SMICFG - SMI Configuration */
/*! @{ */

#define TENBASET_PHY_SMICFG_SPEED_MASK           (0x7EU)
#define TENBASET_PHY_SMICFG_SPEED_SHIFT          (1U)
#define TENBASET_PHY_SMICFG_SPEED_WIDTH          (6U)
#define TENBASET_PHY_SMICFG_SPEED(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_SPEED_SHIFT)) & TENBASET_PHY_SMICFG_SPEED_MASK)

#define TENBASET_PHY_SMICFG_DISPRE_MASK          (0x80U)
#define TENBASET_PHY_SMICFG_DISPRE_SHIFT         (7U)
#define TENBASET_PHY_SMICFG_DISPRE_WIDTH         (1U)
#define TENBASET_PHY_SMICFG_DISPRE(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_DISPRE_SHIFT)) & TENBASET_PHY_SMICFG_DISPRE_MASK)

#define TENBASET_PHY_SMICFG_HOLD_MASK            (0x700U)
#define TENBASET_PHY_SMICFG_HOLD_SHIFT           (8U)
#define TENBASET_PHY_SMICFG_HOLD_WIDTH           (3U)
#define TENBASET_PHY_SMICFG_HOLD(x)              (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMICFG_HOLD_SHIFT)) & TENBASET_PHY_SMICFG_HOLD_MASK)
/*! @} */

/*! @name SMISTAT - SMI Status */
/*! @{ */

#define TENBASET_PHY_SMISTAT_READY_MASK          (0x1U)
#define TENBASET_PHY_SMISTAT_READY_SHIFT         (0U)
#define TENBASET_PHY_SMISTAT_READY_WIDTH         (1U)
#define TENBASET_PHY_SMISTAT_READY(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMISTAT_READY_SHIFT)) & TENBASET_PHY_SMISTAT_READY_MASK)

#define TENBASET_PHY_SMISTAT_ERRCODE_MASK        (0xEU)
#define TENBASET_PHY_SMISTAT_ERRCODE_SHIFT       (1U)
#define TENBASET_PHY_SMISTAT_ERRCODE_WIDTH       (3U)
#define TENBASET_PHY_SMISTAT_ERRCODE(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_SMISTAT_ERRCODE_SHIFT)) & TENBASET_PHY_SMISTAT_ERRCODE_MASK)
/*! @} */

/*! @name INTENCAPT1 - Interrupt Capture1 */
/*! @{ */

#define TENBASET_PHY_INTENCAPT1_PHYSCOL_MASK     (0x1U)
#define TENBASET_PHY_INTENCAPT1_PHYSCOL_SHIFT    (0U)
#define TENBASET_PHY_INTENCAPT1_PHYSCOL_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT1_PHYSCOL(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCAPT1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCAREC_MASK     (0x2U)
#define TENBASET_PHY_INTENCAPT1_PLCAREC_SHIFT    (1U)
#define TENBASET_PHY_INTENCAPT1_PLCAREC_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT1_PLCAREC(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCAREC_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCASTAT_MASK    (0x4U)
#define TENBASET_PHY_INTENCAPT1_PLCASTAT_SHIFT   (2U)
#define TENBASET_PHY_INTENCAPT1_PLCASTAT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT1_PLCASTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCAPT1_MODESTAT_MASK    (0x8U)
#define TENBASET_PHY_INTENCAPT1_MODESTAT_SHIFT   (3U)
#define TENBASET_PHY_INTENCAPT1_MODESTAT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT1_MODESTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCAPT1_MODESTAT_MASK)

#define TENBASET_PHY_INTENCAPT1_INVLDAPB_MASK    (0x10U)
#define TENBASET_PHY_INTENCAPT1_INVLDAPB_SHIFT   (4U)
#define TENBASET_PHY_INTENCAPT1_INVLDAPB_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT1_INVLDAPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCAPT1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCAPT1_LOCJAB_MASK      (0x20U)
#define TENBASET_PHY_INTENCAPT1_LOCJAB_SHIFT     (5U)
#define TENBASET_PHY_INTENCAPT1_LOCJAB_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT1_LOCJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCAPT1_LOCJAB_MASK)

#define TENBASET_PHY_INTENCAPT1_REMJAB_MASK      (0x40U)
#define TENBASET_PHY_INTENCAPT1_REMJAB_SHIFT     (6U)
#define TENBASET_PHY_INTENCAPT1_REMJAB_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT1_REMJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_REMJAB_SHIFT)) & TENBASET_PHY_INTENCAPT1_REMJAB_MASK)

#define TENBASET_PHY_INTENCAPT1_PINFAULT_MASK    (0x80U)
#define TENBASET_PHY_INTENCAPT1_PINFAULT_SHIFT   (7U)
#define TENBASET_PHY_INTENCAPT1_PINFAULT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT1_PINFAULT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCAPT1_PINFAULT_MASK)

#define TENBASET_PHY_INTENCAPT1_PLCADIAG_MASK    (0x100U)
#define TENBASET_PHY_INTENCAPT1_PLCADIAG_SHIFT   (8U)
#define TENBASET_PHY_INTENCAPT1_PLCADIAG_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT1_PLCADIAG(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCAPT1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCAPT1_SMIACCESS_MASK   (0x200U)
#define TENBASET_PHY_INTENCAPT1_SMIACCESS_SHIFT  (9U)
#define TENBASET_PHY_INTENCAPT1_SMIACCESS_WIDTH  (1U)
#define TENBASET_PHY_INTENCAPT1_SMIACCESS(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCAPT1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCAPT1_LCLWK_MASK       (0x400U)
#define TENBASET_PHY_INTENCAPT1_LCLWK_SHIFT      (10U)
#define TENBASET_PHY_INTENCAPT1_LCLWK_WIDTH      (1U)
#define TENBASET_PHY_INTENCAPT1_LCLWK(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_LCLWK_SHIFT)) & TENBASET_PHY_INTENCAPT1_LCLWK_MASK)

#define TENBASET_PHY_INTENCAPT1_SSPDET_MASK      (0x800U)
#define TENBASET_PHY_INTENCAPT1_SSPDET_SHIFT     (11U)
#define TENBASET_PHY_INTENCAPT1_SSPDET_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT1_SSPDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_SSPDET_SHIFT)) & TENBASET_PHY_INTENCAPT1_SSPDET_MASK)

#define TENBASET_PHY_INTENCAPT1_WUTDET_MASK      (0x1000U)
#define TENBASET_PHY_INTENCAPT1_WUTDET_SHIFT     (12U)
#define TENBASET_PHY_INTENCAPT1_WUTDET_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT1_WUTDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_WUTDET_SHIFT)) & TENBASET_PHY_INTENCAPT1_WUTDET_MASK)

#define TENBASET_PHY_INTENCAPT1_WUPDONE_MASK     (0x2000U)
#define TENBASET_PHY_INTENCAPT1_WUPDONE_SHIFT    (13U)
#define TENBASET_PHY_INTENCAPT1_WUPDONE_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT1_WUPDONE(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCAPT1_WUPDONE_MASK)

#define TENBASET_PHY_INTENCAPT1_APBPARITY_MASK   (0x4000U)
#define TENBASET_PHY_INTENCAPT1_APBPARITY_SHIFT  (14U)
#define TENBASET_PHY_INTENCAPT1_APBPARITY_WIDTH  (1U)
#define TENBASET_PHY_INTENCAPT1_APBPARITY(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCAPT1_APBPARITY_MASK)
/*! @} */

/*! @name INTENSET1 - Interrupt Enable Set1 */
/*! @{ */

#define TENBASET_PHY_INTENSET1_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENSET1_PHYSCOL_SHIFT     (0U)
#define TENBASET_PHY_INTENSET1_PHYSCOL_WIDTH     (1U)
#define TENBASET_PHY_INTENSET1_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENSET1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENSET1_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENSET1_PLCAREC_SHIFT     (1U)
#define TENBASET_PHY_INTENSET1_PLCAREC_WIDTH     (1U)
#define TENBASET_PHY_INTENSET1_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENSET1_PLCAREC_MASK)

#define TENBASET_PHY_INTENSET1_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENSET1_PLCASTAT_SHIFT    (2U)
#define TENBASET_PHY_INTENSET1_PLCASTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET1_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENSET1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENSET1_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENSET1_MODESTAT_SHIFT    (3U)
#define TENBASET_PHY_INTENSET1_MODESTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET1_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENSET1_MODESTAT_MASK)

#define TENBASET_PHY_INTENSET1_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENSET1_INVLDAPB_SHIFT    (4U)
#define TENBASET_PHY_INTENSET1_INVLDAPB_WIDTH    (1U)
#define TENBASET_PHY_INTENSET1_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENSET1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENSET1_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENSET1_LOCJAB_SHIFT      (5U)
#define TENBASET_PHY_INTENSET1_LOCJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENSET1_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENSET1_LOCJAB_MASK)

#define TENBASET_PHY_INTENSET1_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENSET1_REMJAB_SHIFT      (6U)
#define TENBASET_PHY_INTENSET1_REMJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENSET1_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_REMJAB_SHIFT)) & TENBASET_PHY_INTENSET1_REMJAB_MASK)

#define TENBASET_PHY_INTENSET1_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENSET1_PINFAULT_SHIFT    (7U)
#define TENBASET_PHY_INTENSET1_PINFAULT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET1_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENSET1_PINFAULT_MASK)

#define TENBASET_PHY_INTENSET1_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENSET1_PLCADIAG_SHIFT    (8U)
#define TENBASET_PHY_INTENSET1_PLCADIAG_WIDTH    (1U)
#define TENBASET_PHY_INTENSET1_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENSET1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENSET1_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENSET1_SMIACCESS_SHIFT   (9U)
#define TENBASET_PHY_INTENSET1_SMIACCESS_WIDTH   (1U)
#define TENBASET_PHY_INTENSET1_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENSET1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENSET1_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENSET1_LCLWK_SHIFT       (10U)
#define TENBASET_PHY_INTENSET1_LCLWK_WIDTH       (1U)
#define TENBASET_PHY_INTENSET1_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_LCLWK_SHIFT)) & TENBASET_PHY_INTENSET1_LCLWK_MASK)

#define TENBASET_PHY_INTENSET1_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENSET1_SSPDET_SHIFT      (11U)
#define TENBASET_PHY_INTENSET1_SSPDET_WIDTH      (1U)
#define TENBASET_PHY_INTENSET1_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_SSPDET_SHIFT)) & TENBASET_PHY_INTENSET1_SSPDET_MASK)

#define TENBASET_PHY_INTENSET1_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENSET1_WUTDET_SHIFT      (12U)
#define TENBASET_PHY_INTENSET1_WUTDET_WIDTH      (1U)
#define TENBASET_PHY_INTENSET1_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_WUTDET_SHIFT)) & TENBASET_PHY_INTENSET1_WUTDET_MASK)

#define TENBASET_PHY_INTENSET1_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENSET1_WUPDONE_SHIFT     (13U)
#define TENBASET_PHY_INTENSET1_WUPDONE_WIDTH     (1U)
#define TENBASET_PHY_INTENSET1_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENSET1_WUPDONE_MASK)

#define TENBASET_PHY_INTENSET1_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENSET1_APBPARITY_SHIFT   (14U)
#define TENBASET_PHY_INTENSET1_APBPARITY_WIDTH   (1U)
#define TENBASET_PHY_INTENSET1_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENSET1_APBPARITY_MASK)
/*! @} */

/*! @name INTENCLR1 - Interrupt Enable Clear1 */
/*! @{ */

#define TENBASET_PHY_INTENCLR1_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENCLR1_PHYSCOL_SHIFT     (0U)
#define TENBASET_PHY_INTENCLR1_PHYSCOL_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR1_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCLR1_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCLR1_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENCLR1_PLCAREC_SHIFT     (1U)
#define TENBASET_PHY_INTENCLR1_PLCAREC_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR1_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCAREC_MASK)

#define TENBASET_PHY_INTENCLR1_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENCLR1_PLCASTAT_SHIFT    (2U)
#define TENBASET_PHY_INTENCLR1_PLCASTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR1_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCLR1_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENCLR1_MODESTAT_SHIFT    (3U)
#define TENBASET_PHY_INTENCLR1_MODESTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR1_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCLR1_MODESTAT_MASK)

#define TENBASET_PHY_INTENCLR1_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENCLR1_INVLDAPB_SHIFT    (4U)
#define TENBASET_PHY_INTENCLR1_INVLDAPB_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR1_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCLR1_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCLR1_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENCLR1_LOCJAB_SHIFT      (5U)
#define TENBASET_PHY_INTENCLR1_LOCJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR1_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCLR1_LOCJAB_MASK)

#define TENBASET_PHY_INTENCLR1_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENCLR1_REMJAB_SHIFT      (6U)
#define TENBASET_PHY_INTENCLR1_REMJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR1_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_REMJAB_SHIFT)) & TENBASET_PHY_INTENCLR1_REMJAB_MASK)

#define TENBASET_PHY_INTENCLR1_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENCLR1_PINFAULT_SHIFT    (7U)
#define TENBASET_PHY_INTENCLR1_PINFAULT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR1_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCLR1_PINFAULT_MASK)

#define TENBASET_PHY_INTENCLR1_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENCLR1_PLCADIAG_SHIFT    (8U)
#define TENBASET_PHY_INTENCLR1_PLCADIAG_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR1_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCLR1_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCLR1_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENCLR1_SMIACCESS_SHIFT   (9U)
#define TENBASET_PHY_INTENCLR1_SMIACCESS_WIDTH   (1U)
#define TENBASET_PHY_INTENCLR1_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCLR1_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCLR1_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENCLR1_LCLWK_SHIFT       (10U)
#define TENBASET_PHY_INTENCLR1_LCLWK_WIDTH       (1U)
#define TENBASET_PHY_INTENCLR1_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_LCLWK_SHIFT)) & TENBASET_PHY_INTENCLR1_LCLWK_MASK)

#define TENBASET_PHY_INTENCLR1_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENCLR1_SSPDET_SHIFT      (11U)
#define TENBASET_PHY_INTENCLR1_SSPDET_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR1_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_SSPDET_SHIFT)) & TENBASET_PHY_INTENCLR1_SSPDET_MASK)

#define TENBASET_PHY_INTENCLR1_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENCLR1_WUTDET_SHIFT      (12U)
#define TENBASET_PHY_INTENCLR1_WUTDET_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR1_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_WUTDET_SHIFT)) & TENBASET_PHY_INTENCLR1_WUTDET_MASK)

#define TENBASET_PHY_INTENCLR1_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENCLR1_WUPDONE_SHIFT     (13U)
#define TENBASET_PHY_INTENCLR1_WUPDONE_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR1_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCLR1_WUPDONE_MASK)

#define TENBASET_PHY_INTENCLR1_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENCLR1_APBPARITY_SHIFT   (14U)
#define TENBASET_PHY_INTENCLR1_APBPARITY_WIDTH   (1U)
#define TENBASET_PHY_INTENCLR1_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR1_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCLR1_APBPARITY_MASK)
/*! @} */

/*! @name INTSTAT1 - Interrupt Status1 */
/*! @{ */

#define TENBASET_PHY_INTSTAT1_PHYSCOL_MASK       (0x1U)
#define TENBASET_PHY_INTSTAT1_PHYSCOL_SHIFT      (0U)
#define TENBASET_PHY_INTSTAT1_PHYSCOL_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT1_PHYSCOL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PHYSCOL_SHIFT)) & TENBASET_PHY_INTSTAT1_PHYSCOL_MASK)

#define TENBASET_PHY_INTSTAT1_PLCAREC_MASK       (0x2U)
#define TENBASET_PHY_INTSTAT1_PLCAREC_SHIFT      (1U)
#define TENBASET_PHY_INTSTAT1_PLCAREC_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT1_PLCAREC(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCAREC_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCAREC_MASK)

#define TENBASET_PHY_INTSTAT1_PLCASTAT_MASK      (0x4U)
#define TENBASET_PHY_INTSTAT1_PLCASTAT_SHIFT     (2U)
#define TENBASET_PHY_INTSTAT1_PLCASTAT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT1_PLCASTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCASTAT_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCASTAT_MASK)

#define TENBASET_PHY_INTSTAT1_MODESTAT_MASK      (0x8U)
#define TENBASET_PHY_INTSTAT1_MODESTAT_SHIFT     (3U)
#define TENBASET_PHY_INTSTAT1_MODESTAT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT1_MODESTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_MODESTAT_SHIFT)) & TENBASET_PHY_INTSTAT1_MODESTAT_MASK)

#define TENBASET_PHY_INTSTAT1_INVLDAPB_MASK      (0x10U)
#define TENBASET_PHY_INTSTAT1_INVLDAPB_SHIFT     (4U)
#define TENBASET_PHY_INTSTAT1_INVLDAPB_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT1_INVLDAPB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_INVLDAPB_SHIFT)) & TENBASET_PHY_INTSTAT1_INVLDAPB_MASK)

#define TENBASET_PHY_INTSTAT1_LOCJAB_MASK        (0x20U)
#define TENBASET_PHY_INTSTAT1_LOCJAB_SHIFT       (5U)
#define TENBASET_PHY_INTSTAT1_LOCJAB_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT1_LOCJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_LOCJAB_SHIFT)) & TENBASET_PHY_INTSTAT1_LOCJAB_MASK)

#define TENBASET_PHY_INTSTAT1_REMJAB_MASK        (0x40U)
#define TENBASET_PHY_INTSTAT1_REMJAB_SHIFT       (6U)
#define TENBASET_PHY_INTSTAT1_REMJAB_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT1_REMJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_REMJAB_SHIFT)) & TENBASET_PHY_INTSTAT1_REMJAB_MASK)

#define TENBASET_PHY_INTSTAT1_PINFAULT_MASK      (0x80U)
#define TENBASET_PHY_INTSTAT1_PINFAULT_SHIFT     (7U)
#define TENBASET_PHY_INTSTAT1_PINFAULT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT1_PINFAULT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PINFAULT_SHIFT)) & TENBASET_PHY_INTSTAT1_PINFAULT_MASK)

#define TENBASET_PHY_INTSTAT1_PLCADIAG_MASK      (0x100U)
#define TENBASET_PHY_INTSTAT1_PLCADIAG_SHIFT     (8U)
#define TENBASET_PHY_INTSTAT1_PLCADIAG_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT1_PLCADIAG(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_PLCADIAG_SHIFT)) & TENBASET_PHY_INTSTAT1_PLCADIAG_MASK)

#define TENBASET_PHY_INTSTAT1_SMIACCESS_MASK     (0x200U)
#define TENBASET_PHY_INTSTAT1_SMIACCESS_SHIFT    (9U)
#define TENBASET_PHY_INTSTAT1_SMIACCESS_WIDTH    (1U)
#define TENBASET_PHY_INTSTAT1_SMIACCESS(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_SMIACCESS_SHIFT)) & TENBASET_PHY_INTSTAT1_SMIACCESS_MASK)

#define TENBASET_PHY_INTSTAT1_LCLWK_MASK         (0x400U)
#define TENBASET_PHY_INTSTAT1_LCLWK_SHIFT        (10U)
#define TENBASET_PHY_INTSTAT1_LCLWK_WIDTH        (1U)
#define TENBASET_PHY_INTSTAT1_LCLWK(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_LCLWK_SHIFT)) & TENBASET_PHY_INTSTAT1_LCLWK_MASK)

#define TENBASET_PHY_INTSTAT1_SSPDET_MASK        (0x800U)
#define TENBASET_PHY_INTSTAT1_SSPDET_SHIFT       (11U)
#define TENBASET_PHY_INTSTAT1_SSPDET_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT1_SSPDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_SSPDET_SHIFT)) & TENBASET_PHY_INTSTAT1_SSPDET_MASK)

#define TENBASET_PHY_INTSTAT1_WUTDET_MASK        (0x1000U)
#define TENBASET_PHY_INTSTAT1_WUTDET_SHIFT       (12U)
#define TENBASET_PHY_INTSTAT1_WUTDET_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT1_WUTDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_WUTDET_SHIFT)) & TENBASET_PHY_INTSTAT1_WUTDET_MASK)

#define TENBASET_PHY_INTSTAT1_WUPDONE_MASK       (0x2000U)
#define TENBASET_PHY_INTSTAT1_WUPDONE_SHIFT      (13U)
#define TENBASET_PHY_INTSTAT1_WUPDONE_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT1_WUPDONE(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_WUPDONE_SHIFT)) & TENBASET_PHY_INTSTAT1_WUPDONE_MASK)

#define TENBASET_PHY_INTSTAT1_APBPARITY_MASK     (0x4000U)
#define TENBASET_PHY_INTSTAT1_APBPARITY_SHIFT    (14U)
#define TENBASET_PHY_INTSTAT1_APBPARITY_WIDTH    (1U)
#define TENBASET_PHY_INTSTAT1_APBPARITY(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT1_APBPARITY_SHIFT)) & TENBASET_PHY_INTSTAT1_APBPARITY_MASK)
/*! @} */

/*! @name INTENCAPT2 - Interrupt Capture2 */
/*! @{ */

#define TENBASET_PHY_INTENCAPT2_PHYSCOL_MASK     (0x1U)
#define TENBASET_PHY_INTENCAPT2_PHYSCOL_SHIFT    (0U)
#define TENBASET_PHY_INTENCAPT2_PHYSCOL_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT2_PHYSCOL(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCAPT2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCAREC_MASK     (0x2U)
#define TENBASET_PHY_INTENCAPT2_PLCAREC_SHIFT    (1U)
#define TENBASET_PHY_INTENCAPT2_PLCAREC_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT2_PLCAREC(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCAREC_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCASTAT_MASK    (0x4U)
#define TENBASET_PHY_INTENCAPT2_PLCASTAT_SHIFT   (2U)
#define TENBASET_PHY_INTENCAPT2_PLCASTAT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT2_PLCASTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCAPT2_MODESTAT_MASK    (0x8U)
#define TENBASET_PHY_INTENCAPT2_MODESTAT_SHIFT   (3U)
#define TENBASET_PHY_INTENCAPT2_MODESTAT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT2_MODESTAT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCAPT2_MODESTAT_MASK)

#define TENBASET_PHY_INTENCAPT2_INVLDAPB_MASK    (0x10U)
#define TENBASET_PHY_INTENCAPT2_INVLDAPB_SHIFT   (4U)
#define TENBASET_PHY_INTENCAPT2_INVLDAPB_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT2_INVLDAPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCAPT2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCAPT2_LOCJAB_MASK      (0x20U)
#define TENBASET_PHY_INTENCAPT2_LOCJAB_SHIFT     (5U)
#define TENBASET_PHY_INTENCAPT2_LOCJAB_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT2_LOCJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCAPT2_LOCJAB_MASK)

#define TENBASET_PHY_INTENCAPT2_REMJAB_MASK      (0x40U)
#define TENBASET_PHY_INTENCAPT2_REMJAB_SHIFT     (6U)
#define TENBASET_PHY_INTENCAPT2_REMJAB_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT2_REMJAB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_REMJAB_SHIFT)) & TENBASET_PHY_INTENCAPT2_REMJAB_MASK)

#define TENBASET_PHY_INTENCAPT2_PINFAULT_MASK    (0x80U)
#define TENBASET_PHY_INTENCAPT2_PINFAULT_SHIFT   (7U)
#define TENBASET_PHY_INTENCAPT2_PINFAULT_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT2_PINFAULT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCAPT2_PINFAULT_MASK)

#define TENBASET_PHY_INTENCAPT2_PLCADIAG_MASK    (0x100U)
#define TENBASET_PHY_INTENCAPT2_PLCADIAG_SHIFT   (8U)
#define TENBASET_PHY_INTENCAPT2_PLCADIAG_WIDTH   (1U)
#define TENBASET_PHY_INTENCAPT2_PLCADIAG(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCAPT2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCAPT2_SMIACCESS_MASK   (0x200U)
#define TENBASET_PHY_INTENCAPT2_SMIACCESS_SHIFT  (9U)
#define TENBASET_PHY_INTENCAPT2_SMIACCESS_WIDTH  (1U)
#define TENBASET_PHY_INTENCAPT2_SMIACCESS(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCAPT2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCAPT2_LCLWK_MASK       (0x400U)
#define TENBASET_PHY_INTENCAPT2_LCLWK_SHIFT      (10U)
#define TENBASET_PHY_INTENCAPT2_LCLWK_WIDTH      (1U)
#define TENBASET_PHY_INTENCAPT2_LCLWK(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_LCLWK_SHIFT)) & TENBASET_PHY_INTENCAPT2_LCLWK_MASK)

#define TENBASET_PHY_INTENCAPT2_SSPDET_MASK      (0x800U)
#define TENBASET_PHY_INTENCAPT2_SSPDET_SHIFT     (11U)
#define TENBASET_PHY_INTENCAPT2_SSPDET_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT2_SSPDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_SSPDET_SHIFT)) & TENBASET_PHY_INTENCAPT2_SSPDET_MASK)

#define TENBASET_PHY_INTENCAPT2_WUTDET_MASK      (0x1000U)
#define TENBASET_PHY_INTENCAPT2_WUTDET_SHIFT     (12U)
#define TENBASET_PHY_INTENCAPT2_WUTDET_WIDTH     (1U)
#define TENBASET_PHY_INTENCAPT2_WUTDET(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_WUTDET_SHIFT)) & TENBASET_PHY_INTENCAPT2_WUTDET_MASK)

#define TENBASET_PHY_INTENCAPT2_WUPDONE_MASK     (0x2000U)
#define TENBASET_PHY_INTENCAPT2_WUPDONE_SHIFT    (13U)
#define TENBASET_PHY_INTENCAPT2_WUPDONE_WIDTH    (1U)
#define TENBASET_PHY_INTENCAPT2_WUPDONE(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCAPT2_WUPDONE_MASK)

#define TENBASET_PHY_INTENCAPT2_APBPARITY_MASK   (0x4000U)
#define TENBASET_PHY_INTENCAPT2_APBPARITY_SHIFT  (14U)
#define TENBASET_PHY_INTENCAPT2_APBPARITY_WIDTH  (1U)
#define TENBASET_PHY_INTENCAPT2_APBPARITY(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCAPT2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCAPT2_APBPARITY_MASK)
/*! @} */

/*! @name INTENSET2 - Interrupt Enable Set1 */
/*! @{ */

#define TENBASET_PHY_INTENSET2_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENSET2_PHYSCOL_SHIFT     (0U)
#define TENBASET_PHY_INTENSET2_PHYSCOL_WIDTH     (1U)
#define TENBASET_PHY_INTENSET2_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENSET2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENSET2_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENSET2_PLCAREC_SHIFT     (1U)
#define TENBASET_PHY_INTENSET2_PLCAREC_WIDTH     (1U)
#define TENBASET_PHY_INTENSET2_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENSET2_PLCAREC_MASK)

#define TENBASET_PHY_INTENSET2_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENSET2_PLCASTAT_SHIFT    (2U)
#define TENBASET_PHY_INTENSET2_PLCASTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET2_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENSET2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENSET2_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENSET2_MODESTAT_SHIFT    (3U)
#define TENBASET_PHY_INTENSET2_MODESTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET2_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENSET2_MODESTAT_MASK)

#define TENBASET_PHY_INTENSET2_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENSET2_INVLDAPB_SHIFT    (4U)
#define TENBASET_PHY_INTENSET2_INVLDAPB_WIDTH    (1U)
#define TENBASET_PHY_INTENSET2_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENSET2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENSET2_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENSET2_LOCJAB_SHIFT      (5U)
#define TENBASET_PHY_INTENSET2_LOCJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENSET2_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENSET2_LOCJAB_MASK)

#define TENBASET_PHY_INTENSET2_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENSET2_REMJAB_SHIFT      (6U)
#define TENBASET_PHY_INTENSET2_REMJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENSET2_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_REMJAB_SHIFT)) & TENBASET_PHY_INTENSET2_REMJAB_MASK)

#define TENBASET_PHY_INTENSET2_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENSET2_PINFAULT_SHIFT    (7U)
#define TENBASET_PHY_INTENSET2_PINFAULT_WIDTH    (1U)
#define TENBASET_PHY_INTENSET2_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENSET2_PINFAULT_MASK)

#define TENBASET_PHY_INTENSET2_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENSET2_PLCADIAG_SHIFT    (8U)
#define TENBASET_PHY_INTENSET2_PLCADIAG_WIDTH    (1U)
#define TENBASET_PHY_INTENSET2_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENSET2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENSET2_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENSET2_SMIACCESS_SHIFT   (9U)
#define TENBASET_PHY_INTENSET2_SMIACCESS_WIDTH   (1U)
#define TENBASET_PHY_INTENSET2_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENSET2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENSET2_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENSET2_LCLWK_SHIFT       (10U)
#define TENBASET_PHY_INTENSET2_LCLWK_WIDTH       (1U)
#define TENBASET_PHY_INTENSET2_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_LCLWK_SHIFT)) & TENBASET_PHY_INTENSET2_LCLWK_MASK)

#define TENBASET_PHY_INTENSET2_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENSET2_SSPDET_SHIFT      (11U)
#define TENBASET_PHY_INTENSET2_SSPDET_WIDTH      (1U)
#define TENBASET_PHY_INTENSET2_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_SSPDET_SHIFT)) & TENBASET_PHY_INTENSET2_SSPDET_MASK)

#define TENBASET_PHY_INTENSET2_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENSET2_WUTDET_SHIFT      (12U)
#define TENBASET_PHY_INTENSET2_WUTDET_WIDTH      (1U)
#define TENBASET_PHY_INTENSET2_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_WUTDET_SHIFT)) & TENBASET_PHY_INTENSET2_WUTDET_MASK)

#define TENBASET_PHY_INTENSET2_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENSET2_WUPDONE_SHIFT     (13U)
#define TENBASET_PHY_INTENSET2_WUPDONE_WIDTH     (1U)
#define TENBASET_PHY_INTENSET2_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENSET2_WUPDONE_MASK)

#define TENBASET_PHY_INTENSET2_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENSET2_APBPARITY_SHIFT   (14U)
#define TENBASET_PHY_INTENSET2_APBPARITY_WIDTH   (1U)
#define TENBASET_PHY_INTENSET2_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENSET2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENSET2_APBPARITY_MASK)
/*! @} */

/*! @name INTENCLR2 - Interrupt Enable Clear2 */
/*! @{ */

#define TENBASET_PHY_INTENCLR2_PHYSCOL_MASK      (0x1U)
#define TENBASET_PHY_INTENCLR2_PHYSCOL_SHIFT     (0U)
#define TENBASET_PHY_INTENCLR2_PHYSCOL_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR2_PHYSCOL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTENCLR2_PHYSCOL_MASK)

#define TENBASET_PHY_INTENCLR2_PLCAREC_MASK      (0x2U)
#define TENBASET_PHY_INTENCLR2_PLCAREC_SHIFT     (1U)
#define TENBASET_PHY_INTENCLR2_PLCAREC_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR2_PLCAREC(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCAREC_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCAREC_MASK)

#define TENBASET_PHY_INTENCLR2_PLCASTAT_MASK     (0x4U)
#define TENBASET_PHY_INTENCLR2_PLCASTAT_SHIFT    (2U)
#define TENBASET_PHY_INTENCLR2_PLCASTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR2_PLCASTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCASTAT_MASK)

#define TENBASET_PHY_INTENCLR2_MODESTAT_MASK     (0x8U)
#define TENBASET_PHY_INTENCLR2_MODESTAT_SHIFT    (3U)
#define TENBASET_PHY_INTENCLR2_MODESTAT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR2_MODESTAT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_MODESTAT_SHIFT)) & TENBASET_PHY_INTENCLR2_MODESTAT_MASK)

#define TENBASET_PHY_INTENCLR2_INVLDAPB_MASK     (0x10U)
#define TENBASET_PHY_INTENCLR2_INVLDAPB_SHIFT    (4U)
#define TENBASET_PHY_INTENCLR2_INVLDAPB_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR2_INVLDAPB(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTENCLR2_INVLDAPB_MASK)

#define TENBASET_PHY_INTENCLR2_LOCJAB_MASK       (0x20U)
#define TENBASET_PHY_INTENCLR2_LOCJAB_SHIFT      (5U)
#define TENBASET_PHY_INTENCLR2_LOCJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR2_LOCJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_LOCJAB_SHIFT)) & TENBASET_PHY_INTENCLR2_LOCJAB_MASK)

#define TENBASET_PHY_INTENCLR2_REMJAB_MASK       (0x40U)
#define TENBASET_PHY_INTENCLR2_REMJAB_SHIFT      (6U)
#define TENBASET_PHY_INTENCLR2_REMJAB_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR2_REMJAB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_REMJAB_SHIFT)) & TENBASET_PHY_INTENCLR2_REMJAB_MASK)

#define TENBASET_PHY_INTENCLR2_PINFAULT_MASK     (0x80U)
#define TENBASET_PHY_INTENCLR2_PINFAULT_SHIFT    (7U)
#define TENBASET_PHY_INTENCLR2_PINFAULT_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR2_PINFAULT(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PINFAULT_SHIFT)) & TENBASET_PHY_INTENCLR2_PINFAULT_MASK)

#define TENBASET_PHY_INTENCLR2_PLCADIAG_MASK     (0x100U)
#define TENBASET_PHY_INTENCLR2_PLCADIAG_SHIFT    (8U)
#define TENBASET_PHY_INTENCLR2_PLCADIAG_WIDTH    (1U)
#define TENBASET_PHY_INTENCLR2_PLCADIAG(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTENCLR2_PLCADIAG_MASK)

#define TENBASET_PHY_INTENCLR2_SMIACCESS_MASK    (0x200U)
#define TENBASET_PHY_INTENCLR2_SMIACCESS_SHIFT   (9U)
#define TENBASET_PHY_INTENCLR2_SMIACCESS_WIDTH   (1U)
#define TENBASET_PHY_INTENCLR2_SMIACCESS(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTENCLR2_SMIACCESS_MASK)

#define TENBASET_PHY_INTENCLR2_LCLWK_MASK        (0x400U)
#define TENBASET_PHY_INTENCLR2_LCLWK_SHIFT       (10U)
#define TENBASET_PHY_INTENCLR2_LCLWK_WIDTH       (1U)
#define TENBASET_PHY_INTENCLR2_LCLWK(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_LCLWK_SHIFT)) & TENBASET_PHY_INTENCLR2_LCLWK_MASK)

#define TENBASET_PHY_INTENCLR2_SSPDET_MASK       (0x800U)
#define TENBASET_PHY_INTENCLR2_SSPDET_SHIFT      (11U)
#define TENBASET_PHY_INTENCLR2_SSPDET_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR2_SSPDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_SSPDET_SHIFT)) & TENBASET_PHY_INTENCLR2_SSPDET_MASK)

#define TENBASET_PHY_INTENCLR2_WUTDET_MASK       (0x1000U)
#define TENBASET_PHY_INTENCLR2_WUTDET_SHIFT      (12U)
#define TENBASET_PHY_INTENCLR2_WUTDET_WIDTH      (1U)
#define TENBASET_PHY_INTENCLR2_WUTDET(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_WUTDET_SHIFT)) & TENBASET_PHY_INTENCLR2_WUTDET_MASK)

#define TENBASET_PHY_INTENCLR2_WUPDONE_MASK      (0x2000U)
#define TENBASET_PHY_INTENCLR2_WUPDONE_SHIFT     (13U)
#define TENBASET_PHY_INTENCLR2_WUPDONE_WIDTH     (1U)
#define TENBASET_PHY_INTENCLR2_WUPDONE(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_WUPDONE_SHIFT)) & TENBASET_PHY_INTENCLR2_WUPDONE_MASK)

#define TENBASET_PHY_INTENCLR2_APBPARITY_MASK    (0x4000U)
#define TENBASET_PHY_INTENCLR2_APBPARITY_SHIFT   (14U)
#define TENBASET_PHY_INTENCLR2_APBPARITY_WIDTH   (1U)
#define TENBASET_PHY_INTENCLR2_APBPARITY(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTENCLR2_APBPARITY_SHIFT)) & TENBASET_PHY_INTENCLR2_APBPARITY_MASK)
/*! @} */

/*! @name INTSTAT2 - Interrupt Status2 */
/*! @{ */

#define TENBASET_PHY_INTSTAT2_PHYSCOL_MASK       (0x1U)
#define TENBASET_PHY_INTSTAT2_PHYSCOL_SHIFT      (0U)
#define TENBASET_PHY_INTSTAT2_PHYSCOL_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT2_PHYSCOL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PHYSCOL_SHIFT)) & TENBASET_PHY_INTSTAT2_PHYSCOL_MASK)

#define TENBASET_PHY_INTSTAT2_PLCAREC_MASK       (0x2U)
#define TENBASET_PHY_INTSTAT2_PLCAREC_SHIFT      (1U)
#define TENBASET_PHY_INTSTAT2_PLCAREC_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT2_PLCAREC(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCAREC_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCAREC_MASK)

#define TENBASET_PHY_INTSTAT2_PLCASTAT_MASK      (0x4U)
#define TENBASET_PHY_INTSTAT2_PLCASTAT_SHIFT     (2U)
#define TENBASET_PHY_INTSTAT2_PLCASTAT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT2_PLCASTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCASTAT_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCASTAT_MASK)

#define TENBASET_PHY_INTSTAT2_MODESTAT_MASK      (0x8U)
#define TENBASET_PHY_INTSTAT2_MODESTAT_SHIFT     (3U)
#define TENBASET_PHY_INTSTAT2_MODESTAT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT2_MODESTAT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_MODESTAT_SHIFT)) & TENBASET_PHY_INTSTAT2_MODESTAT_MASK)

#define TENBASET_PHY_INTSTAT2_INVLDAPB_MASK      (0x10U)
#define TENBASET_PHY_INTSTAT2_INVLDAPB_SHIFT     (4U)
#define TENBASET_PHY_INTSTAT2_INVLDAPB_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT2_INVLDAPB(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_INVLDAPB_SHIFT)) & TENBASET_PHY_INTSTAT2_INVLDAPB_MASK)

#define TENBASET_PHY_INTSTAT2_LOCJAB_MASK        (0x20U)
#define TENBASET_PHY_INTSTAT2_LOCJAB_SHIFT       (5U)
#define TENBASET_PHY_INTSTAT2_LOCJAB_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT2_LOCJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_LOCJAB_SHIFT)) & TENBASET_PHY_INTSTAT2_LOCJAB_MASK)

#define TENBASET_PHY_INTSTAT2_REMJAB_MASK        (0x40U)
#define TENBASET_PHY_INTSTAT2_REMJAB_SHIFT       (6U)
#define TENBASET_PHY_INTSTAT2_REMJAB_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT2_REMJAB(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_REMJAB_SHIFT)) & TENBASET_PHY_INTSTAT2_REMJAB_MASK)

#define TENBASET_PHY_INTSTAT2_PINFAULT_MASK      (0x80U)
#define TENBASET_PHY_INTSTAT2_PINFAULT_SHIFT     (7U)
#define TENBASET_PHY_INTSTAT2_PINFAULT_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT2_PINFAULT(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PINFAULT_SHIFT)) & TENBASET_PHY_INTSTAT2_PINFAULT_MASK)

#define TENBASET_PHY_INTSTAT2_PLCADIAG_MASK      (0x100U)
#define TENBASET_PHY_INTSTAT2_PLCADIAG_SHIFT     (8U)
#define TENBASET_PHY_INTSTAT2_PLCADIAG_WIDTH     (1U)
#define TENBASET_PHY_INTSTAT2_PLCADIAG(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_PLCADIAG_SHIFT)) & TENBASET_PHY_INTSTAT2_PLCADIAG_MASK)

#define TENBASET_PHY_INTSTAT2_SMIACCESS_MASK     (0x200U)
#define TENBASET_PHY_INTSTAT2_SMIACCESS_SHIFT    (9U)
#define TENBASET_PHY_INTSTAT2_SMIACCESS_WIDTH    (1U)
#define TENBASET_PHY_INTSTAT2_SMIACCESS(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_SMIACCESS_SHIFT)) & TENBASET_PHY_INTSTAT2_SMIACCESS_MASK)

#define TENBASET_PHY_INTSTAT2_LCLWK_MASK         (0x400U)
#define TENBASET_PHY_INTSTAT2_LCLWK_SHIFT        (10U)
#define TENBASET_PHY_INTSTAT2_LCLWK_WIDTH        (1U)
#define TENBASET_PHY_INTSTAT2_LCLWK(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_LCLWK_SHIFT)) & TENBASET_PHY_INTSTAT2_LCLWK_MASK)

#define TENBASET_PHY_INTSTAT2_SSPDET_MASK        (0x800U)
#define TENBASET_PHY_INTSTAT2_SSPDET_SHIFT       (11U)
#define TENBASET_PHY_INTSTAT2_SSPDET_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT2_SSPDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_SSPDET_SHIFT)) & TENBASET_PHY_INTSTAT2_SSPDET_MASK)

#define TENBASET_PHY_INTSTAT2_WUTDET_MASK        (0x1000U)
#define TENBASET_PHY_INTSTAT2_WUTDET_SHIFT       (12U)
#define TENBASET_PHY_INTSTAT2_WUTDET_WIDTH       (1U)
#define TENBASET_PHY_INTSTAT2_WUTDET(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_WUTDET_SHIFT)) & TENBASET_PHY_INTSTAT2_WUTDET_MASK)

#define TENBASET_PHY_INTSTAT2_WUPDONE_MASK       (0x2000U)
#define TENBASET_PHY_INTSTAT2_WUPDONE_SHIFT      (13U)
#define TENBASET_PHY_INTSTAT2_WUPDONE_WIDTH      (1U)
#define TENBASET_PHY_INTSTAT2_WUPDONE(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_WUPDONE_SHIFT)) & TENBASET_PHY_INTSTAT2_WUPDONE_MASK)

#define TENBASET_PHY_INTSTAT2_APBPARITY_MASK     (0x4000U)
#define TENBASET_PHY_INTSTAT2_APBPARITY_SHIFT    (14U)
#define TENBASET_PHY_INTSTAT2_APBPARITY_WIDTH    (1U)
#define TENBASET_PHY_INTSTAT2_APBPARITY(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_INTSTAT2_APBPARITY_SHIFT)) & TENBASET_PHY_INTSTAT2_APBPARITY_MASK)
/*! @} */

/*! @name PLCADIAG2 - PLCA NXP prop diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG2_EARLYBCN_MASK     (0x1U)
#define TENBASET_PHY_PLCADIAG2_EARLYBCN_SHIFT    (0U)
#define TENBASET_PHY_PLCADIAG2_EARLYBCN_WIDTH    (1U)
#define TENBASET_PHY_PLCADIAG2_EARLYBCN(x)       (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_EARLYBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_EARLYBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_LATEBCN_MASK      (0x2U)
#define TENBASET_PHY_PLCADIAG2_LATEBCN_SHIFT     (1U)
#define TENBASET_PHY_PLCADIAG2_LATEBCN_WIDTH     (1U)
#define TENBASET_PHY_PLCADIAG2_LATEBCN(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_LATEBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_LATEBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_NORXBCN_MASK      (0x4U)
#define TENBASET_PHY_PLCADIAG2_NORXBCN_SHIFT     (2U)
#define TENBASET_PHY_PLCADIAG2_NORXBCN_WIDTH     (1U)
#define TENBASET_PHY_PLCADIAG2_NORXBCN(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_NORXBCN_SHIFT)) & TENBASET_PHY_PLCADIAG2_NORXBCN_MASK)

#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE_MASK   (0x8U)
#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE_SHIFT  (3U)
#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE_WIDTH  (1U)
#define TENBASET_PHY_PLCADIAG2_UNDEFSTATE(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG2_UNDEFSTATE_SHIFT)) & TENBASET_PHY_PLCADIAG2_UNDEFSTATE_MASK)
/*! @} */

/*! @name PLCADIAG3 - PLCA Beacon Counter Diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT_MASK    (0xFFFFU)
#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT_SHIFT   (0U)
#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT_WIDTH   (16U)
#define TENBASET_PHY_PLCADIAG3_RXBCNTCNT(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG3_RXBCNTCNT_SHIFT)) & TENBASET_PHY_PLCADIAG3_RXBCNTCNT_MASK)
/*! @} */

/*! @name PLCADIAG4 - PLCA TO Counter Diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG4_TOCNT_MASK        (0xFFFFU)
#define TENBASET_PHY_PLCADIAG4_TOCNT_SHIFT       (0U)
#define TENBASET_PHY_PLCADIAG4_TOCNT_WIDTH       (16U)
#define TENBASET_PHY_PLCADIAG4_TOCNT(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG4_TOCNT_SHIFT)) & TENBASET_PHY_PLCADIAG4_TOCNT_MASK)
/*! @} */

/*! @name TXCDIAG - Transceiver Diagnostics */
/*! @{ */

#define TENBASET_PHY_TXCDIAG_RXLOWFAIL_MASK      (0x1U)
#define TENBASET_PHY_TXCDIAG_RXLOWFAIL_SHIFT     (0U)
#define TENBASET_PHY_TXCDIAG_RXLOWFAIL_WIDTH     (1U)
#define TENBASET_PHY_TXCDIAG_RXLOWFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_RXLOWFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_RXLOWFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_RXHGHFAIL_MASK      (0x2U)
#define TENBASET_PHY_TXCDIAG_RXHGHFAIL_SHIFT     (1U)
#define TENBASET_PHY_TXCDIAG_RXHGHFAIL_WIDTH     (1U)
#define TENBASET_PHY_TXCDIAG_RXHGHFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_RXHGHFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_RXHGHFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_EDLOWFAIL_MASK      (0x4U)
#define TENBASET_PHY_TXCDIAG_EDLOWFAIL_SHIFT     (2U)
#define TENBASET_PHY_TXCDIAG_EDLOWFAIL_WIDTH     (1U)
#define TENBASET_PHY_TXCDIAG_EDLOWFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_EDLOWFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_EDLOWFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_EDHGHFAIL_MASK      (0x8U)
#define TENBASET_PHY_TXCDIAG_EDHGHFAIL_SHIFT     (3U)
#define TENBASET_PHY_TXCDIAG_EDHGHFAIL_WIDTH     (1U)
#define TENBASET_PHY_TXCDIAG_EDHGHFAIL(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_EDHGHFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_EDHGHFAIL_MASK)

#define TENBASET_PHY_TXCDIAG_LPWRFAIL_MASK       (0x10U)
#define TENBASET_PHY_TXCDIAG_LPWRFAIL_SHIFT      (4U)
#define TENBASET_PHY_TXCDIAG_LPWRFAIL_WIDTH      (1U)
#define TENBASET_PHY_TXCDIAG_LPWRFAIL(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_TXCDIAG_LPWRFAIL_SHIFT)) & TENBASET_PHY_TXCDIAG_LPWRFAIL_MASK)
/*! @} */

/*! @name MSKPLCADIAG1 - Mask Control PLCADIAG1 Flag */
/*! @{ */

#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_MASK   (0x1U)
#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_SHIFT  (0U)
#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_WIDTH  (1U)
#define TENBASET_PHY_MSKPLCADIAG1_BCNBFTO(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_BCNBFTO_MASK)

#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB_MASK    (0x2U)
#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB_SHIFT   (1U)
#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB_WIDTH   (1U)
#define TENBASET_PHY_MSKPLCADIAG1_UNEXPB(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_UNEXPB_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_UNEXPB_MASK)

#define TENBASET_PHY_MSKPLCADIAG1_RXINTO_MASK    (0x4U)
#define TENBASET_PHY_MSKPLCADIAG1_RXINTO_SHIFT   (2U)
#define TENBASET_PHY_MSKPLCADIAG1_RXINTO_WIDTH   (1U)
#define TENBASET_PHY_MSKPLCADIAG1_RXINTO(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG1_RXINTO_SHIFT)) & TENBASET_PHY_MSKPLCADIAG1_RXINTO_MASK)
/*! @} */

/*! @name MSKPLCADIAG2 - Mask Control PLCADIAG2 Flags */
/*! @{ */

#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_MASK  (0x1U)
#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_SHIFT (0U)
#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_WIDTH (1U)
#define TENBASET_PHY_MSKPLCADIAG2_EARLYBCN(x)    (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_EARLYBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN_MASK   (0x2U)
#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN_SHIFT  (1U)
#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN_WIDTH  (1U)
#define TENBASET_PHY_MSKPLCADIAG2_LATEBCN(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_LATEBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_LATEBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN_MASK   (0x4U)
#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN_SHIFT  (2U)
#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN_WIDTH  (1U)
#define TENBASET_PHY_MSKPLCADIAG2_NORXBCN(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_NORXBCN_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_NORXBCN_MASK)

#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_MASK (0x8U)
#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_SHIFT (3U)
#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_WIDTH (1U)
#define TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE(x)  (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_SHIFT)) & TENBASET_PHY_MSKPLCADIAG2_UNDEFSTATE_MASK)
/*! @} */

/*! @name MSKTXCDIAG - Mask Control TXCDIAG Flag */
/*! @{ */

#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_MASK   (0x1U)
#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_SHIFT  (0U)
#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_WIDTH  (1U)
#define TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_RXLOWFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_MASK   (0x2U)
#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_SHIFT  (1U)
#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_WIDTH  (1U)
#define TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_RXHGHFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_MASK   (0x4U)
#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_SHIFT  (2U)
#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_WIDTH  (1U)
#define TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_EDLOWFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_MASK   (0x8U)
#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_SHIFT  (3U)
#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_WIDTH  (1U)
#define TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL(x)     (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_EDHGHFAIL_MASK)

#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_MASK    (0x10U)
#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_SHIFT   (4U)
#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_WIDTH   (1U)
#define TENBASET_PHY_MSKTXCDIAG_LPWRFAIL(x)      (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_SHIFT)) & TENBASET_PHY_MSKTXCDIAG_LPWRFAIL_MASK)
/*! @} */

/*! @name ACCESSCTRL - Global Access Control */
/*! @{ */

#define TENBASET_PHY_ACCESSCTRL_ACCESS_MASK      (0x1U)
#define TENBASET_PHY_ACCESSCTRL_ACCESS_SHIFT     (0U)
#define TENBASET_PHY_ACCESSCTRL_ACCESS_WIDTH     (1U)
#define TENBASET_PHY_ACCESSCTRL_ACCESS(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_ACCESSCTRL_ACCESS_SHIFT)) & TENBASET_PHY_ACCESSCTRL_ACCESS_MASK)
/*! @} */

/*! @name DBGCTRL - Debug Control */
/*! @{ */

#define TENBASET_PHY_DBGCTRL_DEBUG_MASK          (0xFFU)
#define TENBASET_PHY_DBGCTRL_DEBUG_SHIFT         (0U)
#define TENBASET_PHY_DBGCTRL_DEBUG_WIDTH         (8U)
#define TENBASET_PHY_DBGCTRL_DEBUG(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_DBGCTRL_DEBUG_SHIFT)) & TENBASET_PHY_DBGCTRL_DEBUG_MASK)
/*! @} */

/*! @name VERSION - Version Information */
/*! @{ */

#define TENBASET_PHY_VERSION_CUSTVER_MASK        (0xFU)
#define TENBASET_PHY_VERSION_CUSTVER_SHIFT       (0U)
#define TENBASET_PHY_VERSION_CUSTVER_WIDTH       (4U)
#define TENBASET_PHY_VERSION_CUSTVER(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_CUSTVER_SHIFT)) & TENBASET_PHY_VERSION_CUSTVER_MASK)

#define TENBASET_PHY_VERSION_MINORVER_MASK       (0xFF0U)
#define TENBASET_PHY_VERSION_MINORVER_SHIFT      (4U)
#define TENBASET_PHY_VERSION_MINORVER_WIDTH      (8U)
#define TENBASET_PHY_VERSION_MINORVER(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_MINORVER_SHIFT)) & TENBASET_PHY_VERSION_MINORVER_MASK)

#define TENBASET_PHY_VERSION_MAJORVER_MASK       (0xF000U)
#define TENBASET_PHY_VERSION_MAJORVER_SHIFT      (12U)
#define TENBASET_PHY_VERSION_MAJORVER_WIDTH      (4U)
#define TENBASET_PHY_VERSION_MAJORVER(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_VERSION_MAJORVER_SHIFT)) & TENBASET_PHY_VERSION_MAJORVER_MASK)
/*! @} */

/*! @name PLCAIDVER - PLCA Identification and Version */
/*! @{ */

#define TENBASET_PHY_PLCAIDVER_VER_MASK          (0xFFU)
#define TENBASET_PHY_PLCAIDVER_VER_SHIFT         (0U)
#define TENBASET_PHY_PLCAIDVER_VER_WIDTH         (8U)
#define TENBASET_PHY_PLCAIDVER_VER(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCAIDVER_VER_SHIFT)) & TENBASET_PHY_PLCAIDVER_VER_MASK)

#define TENBASET_PHY_PLCAIDVER_IDM_MASK          (0xFF00U)
#define TENBASET_PHY_PLCAIDVER_IDM_SHIFT         (8U)
#define TENBASET_PHY_PLCAIDVER_IDM_WIDTH         (8U)
#define TENBASET_PHY_PLCAIDVER_IDM(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCAIDVER_IDM_SHIFT)) & TENBASET_PHY_PLCAIDVER_IDM_MASK)
/*! @} */

/*! @name PLCACTRL0 - PLCA Control0 */
/*! @{ */

#define TENBASET_PHY_PLCACTRL0_RST_MASK          (0x4000U)
#define TENBASET_PHY_PLCACTRL0_RST_SHIFT         (14U)
#define TENBASET_PHY_PLCACTRL0_RST_WIDTH         (1U)
#define TENBASET_PHY_PLCACTRL0_RST(x)            (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL0_RST_SHIFT)) & TENBASET_PHY_PLCACTRL0_RST_MASK)

#define TENBASET_PHY_PLCACTRL0_EN_MASK           (0x8000U)
#define TENBASET_PHY_PLCACTRL0_EN_SHIFT          (15U)
#define TENBASET_PHY_PLCACTRL0_EN_WIDTH          (1U)
#define TENBASET_PHY_PLCACTRL0_EN(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL0_EN_SHIFT)) & TENBASET_PHY_PLCACTRL0_EN_MASK)
/*! @} */

/*! @name PLCACTRL1 - PLCA Control1 */
/*! @{ */

#define TENBASET_PHY_PLCACTRL1_ID_MASK           (0xFFU)
#define TENBASET_PHY_PLCACTRL1_ID_SHIFT          (0U)
#define TENBASET_PHY_PLCACTRL1_ID_WIDTH          (8U)
#define TENBASET_PHY_PLCACTRL1_ID(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL1_ID_SHIFT)) & TENBASET_PHY_PLCACTRL1_ID_MASK)

#define TENBASET_PHY_PLCACTRL1_NCNT_MASK         (0xFF00U)
#define TENBASET_PHY_PLCACTRL1_NCNT_SHIFT        (8U)
#define TENBASET_PHY_PLCACTRL1_NCNT_WIDTH        (8U)
#define TENBASET_PHY_PLCACTRL1_NCNT(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCACTRL1_NCNT_SHIFT)) & TENBASET_PHY_PLCACTRL1_NCNT_MASK)
/*! @} */

/*! @name PLCASTAT - PLCA Status */
/*! @{ */

#define TENBASET_PHY_PLCASTAT_PST_MASK           (0x8000U)
#define TENBASET_PHY_PLCASTAT_PST_SHIFT          (15U)
#define TENBASET_PHY_PLCASTAT_PST_WIDTH          (1U)
#define TENBASET_PHY_PLCASTAT_PST(x)             (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCASTAT_PST_SHIFT)) & TENBASET_PHY_PLCASTAT_PST_MASK)
/*! @} */

/*! @name PLCATOTMR - PLCA Transmit Opportunity Timer */
/*! @{ */

#define TENBASET_PHY_PLCATOTMR_TOTMR_MASK        (0xFFU)
#define TENBASET_PHY_PLCATOTMR_TOTMR_SHIFT       (0U)
#define TENBASET_PHY_PLCATOTMR_TOTMR_WIDTH       (8U)
#define TENBASET_PHY_PLCATOTMR_TOTMR(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCATOTMR_TOTMR_SHIFT)) & TENBASET_PHY_PLCATOTMR_TOTMR_MASK)
/*! @} */

/*! @name PLCABURST - PLCA Burst Mode Configuration */
/*! @{ */

#define TENBASET_PHY_PLCABURST_BTMR_MASK         (0xFFU)
#define TENBASET_PHY_PLCABURST_BTMR_SHIFT        (0U)
#define TENBASET_PHY_PLCABURST_BTMR_WIDTH        (8U)
#define TENBASET_PHY_PLCABURST_BTMR(x)           (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCABURST_BTMR_SHIFT)) & TENBASET_PHY_PLCABURST_BTMR_MASK)

#define TENBASET_PHY_PLCABURST_MAXBC_MASK        (0xFF00U)
#define TENBASET_PHY_PLCABURST_MAXBC_SHIFT       (8U)
#define TENBASET_PHY_PLCABURST_MAXBC_WIDTH       (8U)
#define TENBASET_PHY_PLCABURST_MAXBC(x)          (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCABURST_MAXBC_SHIFT)) & TENBASET_PHY_PLCABURST_MAXBC_MASK)
/*! @} */

/*! @name PLCADIAG1 - PLCA TC14 Adv diagnostics */
/*! @{ */

#define TENBASET_PHY_PLCADIAG1_BCNBFTO_MASK      (0x1U)
#define TENBASET_PHY_PLCADIAG1_BCNBFTO_SHIFT     (0U)
#define TENBASET_PHY_PLCADIAG1_BCNBFTO_WIDTH     (1U)
#define TENBASET_PHY_PLCADIAG1_BCNBFTO(x)        (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_BCNBFTO_SHIFT)) & TENBASET_PHY_PLCADIAG1_BCNBFTO_MASK)

#define TENBASET_PHY_PLCADIAG1_UNEXPB_MASK       (0x2U)
#define TENBASET_PHY_PLCADIAG1_UNEXPB_SHIFT      (1U)
#define TENBASET_PHY_PLCADIAG1_UNEXPB_WIDTH      (1U)
#define TENBASET_PHY_PLCADIAG1_UNEXPB(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_UNEXPB_SHIFT)) & TENBASET_PHY_PLCADIAG1_UNEXPB_MASK)

#define TENBASET_PHY_PLCADIAG1_RXINTO_MASK       (0x4U)
#define TENBASET_PHY_PLCADIAG1_RXINTO_SHIFT      (2U)
#define TENBASET_PHY_PLCADIAG1_RXINTO_WIDTH      (1U)
#define TENBASET_PHY_PLCADIAG1_RXINTO(x)         (((uint16_t)(((uint16_t)(x)) << TENBASET_PHY_PLCADIAG1_RXINTO_SHIFT)) & TENBASET_PHY_PLCADIAG1_RXINTO_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group TENBASET_PHY_Register_Masks */

/*!
 * @}
 */ /* end of group TENBASET_PHY_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_TENBASET_PHY_H_) */
