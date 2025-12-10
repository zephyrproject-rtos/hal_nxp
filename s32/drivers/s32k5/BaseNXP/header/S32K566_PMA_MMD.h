/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_PMA_MMD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_PMA_MMD
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
#if !defined(S32K566_PMA_MMD_H_)  /* Check if memory map has not been already included */
#define S32K566_PMA_MMD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- PMA_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMA_MMD_Peripheral_Access_Layer PMA_MMD Peripheral Access Layer
 * @{
 */

/** PMA_MMD - Register Layout Typedef */
typedef struct PMA_MMD_Struct {
  __IO uint16_t SR_PMA_CTRL1;                      /**< SR PMA MMD Control1 Register, offset: 0x0 */
  __I  uint16_t SR_PMA_STATUS1;                    /**< SR PMA MMD Status1 Register, offset: 0x2 */
  __I  uint16_t SR_PMA_DEV_ID_1;                   /**< SR PMA MMD Device Identifier 1 Register, offset: 0x4 */
  __I  uint16_t SR_PMA_DEV_ID_2;                   /**< SR PMA MMD Device Identifier 2 Register, offset: 0x6 */
  __I  uint16_t SR_PMA_SPD_ABL;                    /**< SR PMA MMD Speed Ability Register, offset: 0x8 */
  __I  uint16_t SR_PMA_DEV_PKG1;                   /**< SR PMA MMD Devices in Package 1 Register, offset: 0xA */
  __I  uint16_t SR_PMA_DEV_PKG2;                   /**< SR PMA MMD Devices in Package 2 Register, offset: 0xC */
  __IO uint16_t SR_PMA_CTRL2;                      /**< SR PMA MMD Control2 Register, offset: 0xE */
  __I  uint16_t SR_PMA_STATUS2;                    /**< SR PMA MMD Status2 Register, offset: 0x10 */
  __IO uint16_t SR_PMA_TX_DIS;                     /**< SR_PMA_TX_DIS, offset: 0x12 */
  __I  uint16_t SR_PMA_RX_SIG_DET;                 /**< SR PMA MMD Receive Signal Detect Register, offset: 0x14 */
  __I  uint16_t SR_PMA_EXT_ABL;                    /**< SR PMA or PMD Extended Ability Register, offset: 0x16 */
  uint8_t RESERVED_0[4];
  __I  uint16_t SR_PMA_PKG1;                       /**< SR PMA MMD Package Identifier 1 Register, offset: 0x1C */
  __I  uint16_t SR_PMA_PKG2;                       /**< SR PMA MMD Package Identifier 2 Register, offset: 0x1E */
  uint8_t RESERVED_1[10];
  __I  uint16_t SR_PMA_2PT5G_5G_EXT_ABL;           /**< SR PMA MMD 2., offset: 0x2A */
  uint8_t RESERVED_2[276];
  __IO uint16_t SR_PMA_KX_CTRL;                    /**< SR PMA or PMD KX Control Register This register is present only in the configurations with KX_Present mode., offset: 0x140 */
  __I  uint16_t SR_PMA_KX_STS;                     /**< SR PMA or PMD KX Status Register This register is present only in the configurations with KX_Present mode., offset: 0x142 */
  uint8_t RESERVED_3[3276];
  __I  uint16_t SR_PMA_TIME_SYNC_PMA_ABL;          /**< SR PMA MMD Time Sync Capability Register, offset: 0xE10 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR;   /**< SR PMA MMD Time Sync Tx Max Delay Lower Register, offset: 0xE12 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR;   /**< SR PMA MMD Time Sync Tx Max Delay Upper Register, offset: 0xE14 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR;   /**< SR PMA MMD Time Sync Tx Min Delay Lower Register, offset: 0xE16 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR;   /**< SR PMA MMD Time Sync Tx Min Delay Upper Register, offset: 0xE18 */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR;   /**< SR PMA MMD Time Sync Rx Max Delay Lower Register, offset: 0xE1A */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR;   /**< SR PMA MMD Time Sync Rx Max Delay Upper Register, offset: 0xE1C */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR;   /**< SR PMA MMD Time Sync Rx Min Delay Lower Register, offset: 0xE1E */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR;   /**< SR PMA MMD Time Sync Rx Min Delay Upper Register, offset: 0xE20 */
  uint8_t RESERVED_4[61918];
  __IO uint16_t VR_PMA_DIG_CTRL1;                  /**< VR PMA MMD Digital Control1 Register, offset: 0x10000 */
  uint8_t RESERVED_5[30];
  __I  uint16_t VR_PMA_DIG_STS;                    /**< VR PMA MMD Digital Status Register, offset: 0x10020 */
} PMA_MMD_Type, *PMA_MMD_MemMapPtr;

/** Number of instances of the PMA_MMD module. */
#define PMA_MMD_INSTANCE_COUNT                   (1u)

/* PMA_MMD - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD_BASE (0x81003Eu)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD ((PMA_MMD_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD_BASE)
/** Array initializer of PMA_MMD peripheral base addresses */
#define IP_PMA_MMD_BASE_ADDRS                    { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD_BASE }
/** Array initializer of PMA_MMD peripheral base pointers */
#define IP_PMA_MMD_BASE_PTRS                     { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__PMA_MMD }

/* ----------------------------------------------------------------------------
   -- PMA_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMA_MMD_Register_Masks PMA_MMD Register Masks
 * @{
 */

/*! @name SR_PMA_CTRL1 - SR PMA MMD Control1 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_CTRL1_LB_MASK             (0x1U)
#define PMA_MMD_SR_PMA_CTRL1_LB_SHIFT            (0U)
#define PMA_MMD_SR_PMA_CTRL1_LB_WIDTH            (1U)
#define PMA_MMD_SR_PMA_CTRL1_LB(x)               (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_LB_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_LB_MASK)

#define PMA_MMD_SR_PMA_CTRL1_SS_5_2_MASK         (0x3CU)
#define PMA_MMD_SR_PMA_CTRL1_SS_5_2_SHIFT        (2U)
#define PMA_MMD_SR_PMA_CTRL1_SS_5_2_WIDTH        (4U)
#define PMA_MMD_SR_PMA_CTRL1_SS_5_2(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_SS_5_2_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_SS_5_2_MASK)

#define PMA_MMD_SR_PMA_CTRL1_SS6_MASK            (0x40U)
#define PMA_MMD_SR_PMA_CTRL1_SS6_SHIFT           (6U)
#define PMA_MMD_SR_PMA_CTRL1_SS6_WIDTH           (1U)
#define PMA_MMD_SR_PMA_CTRL1_SS6(x)              (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_SS6_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_SS6_MASK)

#define PMA_MMD_SR_PMA_CTRL1_LPM_MASK            (0x800U)
#define PMA_MMD_SR_PMA_CTRL1_LPM_SHIFT           (11U)
#define PMA_MMD_SR_PMA_CTRL1_LPM_WIDTH           (1U)
#define PMA_MMD_SR_PMA_CTRL1_LPM(x)              (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_LPM_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_LPM_MASK)

#define PMA_MMD_SR_PMA_CTRL1_SS13_MASK           (0x2000U)
#define PMA_MMD_SR_PMA_CTRL1_SS13_SHIFT          (13U)
#define PMA_MMD_SR_PMA_CTRL1_SS13_WIDTH          (1U)
#define PMA_MMD_SR_PMA_CTRL1_SS13(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_SS13_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_SS13_MASK)

#define PMA_MMD_SR_PMA_CTRL1_RST_MASK            (0x8000U)
#define PMA_MMD_SR_PMA_CTRL1_RST_SHIFT           (15U)
#define PMA_MMD_SR_PMA_CTRL1_RST_WIDTH           (1U)
#define PMA_MMD_SR_PMA_CTRL1_RST(x)              (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL1_RST_SHIFT)) & PMA_MMD_SR_PMA_CTRL1_RST_MASK)
/*! @} */

/*! @name SR_PMA_STATUS1 - SR PMA MMD Status1 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_STATUS1_LPMS_MASK         (0x2U)
#define PMA_MMD_SR_PMA_STATUS1_LPMS_SHIFT        (1U)
#define PMA_MMD_SR_PMA_STATUS1_LPMS_WIDTH        (1U)
#define PMA_MMD_SR_PMA_STATUS1_LPMS(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS1_LPMS_SHIFT)) & PMA_MMD_SR_PMA_STATUS1_LPMS_MASK)

#define PMA_MMD_SR_PMA_STATUS1_RLU_MASK          (0x4U)
#define PMA_MMD_SR_PMA_STATUS1_RLU_SHIFT         (2U)
#define PMA_MMD_SR_PMA_STATUS1_RLU_WIDTH         (1U)
#define PMA_MMD_SR_PMA_STATUS1_RLU(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS1_RLU_SHIFT)) & PMA_MMD_SR_PMA_STATUS1_RLU_MASK)

#define PMA_MMD_SR_PMA_STATUS1_FLT_MASK          (0x80U)
#define PMA_MMD_SR_PMA_STATUS1_FLT_SHIFT         (7U)
#define PMA_MMD_SR_PMA_STATUS1_FLT_WIDTH         (1U)
#define PMA_MMD_SR_PMA_STATUS1_FLT(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS1_FLT_SHIFT)) & PMA_MMD_SR_PMA_STATUS1_FLT_MASK)
/*! @} */

/*! @name SR_PMA_DEV_ID_1 - SR PMA MMD Device Identifier 1 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_SHIFT (0U)
#define PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_WIDTH (16U)
#define PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_SHIFT)) & PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_PMA_DEV_ID_2 - SR PMA MMD Device Identifier 2 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_MASK (0xFU)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_SHIFT (0U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_WIDTH (4U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_SHIFT)) & PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_MASK)

#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_MASK (0x3F0U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_SHIFT (4U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_WIDTH (6U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_SHIFT)) & PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_MASK)

#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_MASK (0xFC00U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_SHIFT (10U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_WIDTH (6U)
#define PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_SHIFT)) & PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_PMA_SPD_ABL - SR PMA MMD Speed Ability Register */
/*! @{ */

#define PMA_MMD_SR_PMA_SPD_ABL_XGC_MASK          (0x1U)
#define PMA_MMD_SR_PMA_SPD_ABL_XGC_SHIFT         (0U)
#define PMA_MMD_SR_PMA_SPD_ABL_XGC_WIDTH         (1U)
#define PMA_MMD_SR_PMA_SPD_ABL_XGC(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_SPD_ABL_XGC_SHIFT)) & PMA_MMD_SR_PMA_SPD_ABL_XGC_MASK)

#define PMA_MMD_SR_PMA_SPD_ABL_GC_MASK           (0x10U)
#define PMA_MMD_SR_PMA_SPD_ABL_GC_SHIFT          (4U)
#define PMA_MMD_SR_PMA_SPD_ABL_GC_WIDTH          (1U)
#define PMA_MMD_SR_PMA_SPD_ABL_GC(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_SPD_ABL_GC_SHIFT)) & PMA_MMD_SR_PMA_SPD_ABL_GC_MASK)
/*! @} */

/*! @name SR_PMA_DEV_PKG1 - SR PMA MMD Devices in Package 1 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_DEV_PKG1_CLS22_MASK       (0x1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_CLS22_SHIFT      (0U)
#define PMA_MMD_SR_PMA_DEV_PKG1_CLS22_WIDTH      (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_CLS22(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_CLS22_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_CLS22_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_MASK     (0x2U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_SHIFT    (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_WIDTH    (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD(x)       (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_WIS_MASK         (0x4U)
#define PMA_MMD_SR_PMA_DEV_PKG1_WIS_SHIFT        (2U)
#define PMA_MMD_SR_PMA_DEV_PKG1_WIS_WIDTH        (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_WIS(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_WIS_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_WIS_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_PCS_MASK         (0x8U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PCS_SHIFT        (3U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PCS_WIDTH        (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PCS(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_PCS_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_PCS_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_MASK       (0x10U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_SHIFT      (4U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_WIDTH      (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_PHYXS(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_MASK       (0x20U)
#define PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_SHIFT      (5U)
#define PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_WIDTH      (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_DTEXS(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_TC_MASK          (0x40U)
#define PMA_MMD_SR_PMA_DEV_PKG1_TC_SHIFT         (6U)
#define PMA_MMD_SR_PMA_DEV_PKG1_TC_WIDTH         (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_TC(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_TC_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_TC_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG1_AN_MASK          (0x80U)
#define PMA_MMD_SR_PMA_DEV_PKG1_AN_SHIFT         (7U)
#define PMA_MMD_SR_PMA_DEV_PKG1_AN_WIDTH         (1U)
#define PMA_MMD_SR_PMA_DEV_PKG1_AN(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG1_AN_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG1_AN_MASK)
/*! @} */

/*! @name SR_PMA_DEV_PKG2 - SR PMA MMD Devices in Package 2 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_DEV_PKG2_VSD1_MASK        (0x4000U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD1_SHIFT       (14U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD1_WIDTH       (1U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD1(x)          (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG2_VSD1_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG2_VSD1_MASK)

#define PMA_MMD_SR_PMA_DEV_PKG2_VSD2_MASK        (0x8000U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD2_SHIFT       (15U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD2_WIDTH       (1U)
#define PMA_MMD_SR_PMA_DEV_PKG2_VSD2(x)          (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_DEV_PKG2_VSD2_SHIFT)) & PMA_MMD_SR_PMA_DEV_PKG2_VSD2_MASK)
/*! @} */

/*! @name SR_PMA_CTRL2 - SR PMA MMD Control2 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_CTRL2_PMA_TYPE_MASK       (0x3FU)
#define PMA_MMD_SR_PMA_CTRL2_PMA_TYPE_SHIFT      (0U)
#define PMA_MMD_SR_PMA_CTRL2_PMA_TYPE_WIDTH      (6U)
#define PMA_MMD_SR_PMA_CTRL2_PMA_TYPE(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_CTRL2_PMA_TYPE_SHIFT)) & PMA_MMD_SR_PMA_CTRL2_PMA_TYPE_MASK)
/*! @} */

/*! @name SR_PMA_STATUS2 - SR PMA MMD Status2 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_MASK     (0x1U)
#define PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_SHIFT    (0U)
#define PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_WIDTH    (1U)
#define PMA_MMD_SR_PMA_STATUS2_PMA_LOOP(x)       (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_MASK)

#define PMA_MMD_SR_PMA_STATUS2_XGEWEN_MASK       (0x2U)
#define PMA_MMD_SR_PMA_STATUS2_XGEWEN_SHIFT      (1U)
#define PMA_MMD_SR_PMA_STATUS2_XGEWEN_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_XGEWEN(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_XGEWEN_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_XGEWEN_MASK)

#define PMA_MMD_SR_PMA_STATUS2_XGLWEN_MASK       (0x4U)
#define PMA_MMD_SR_PMA_STATUS2_XGLWEN_SHIFT      (2U)
#define PMA_MMD_SR_PMA_STATUS2_XGLWEN_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_XGLWEN(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_XGLWEN_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_XGLWEN_MASK)

#define PMA_MMD_SR_PMA_STATUS2_XGSWEN_MASK       (0x8U)
#define PMA_MMD_SR_PMA_STATUS2_XGSWEN_SHIFT      (3U)
#define PMA_MMD_SR_PMA_STATUS2_XGSWEN_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_XGSWEN(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_XGSWEN_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_XGSWEN_MASK)

#define PMA_MMD_SR_PMA_STATUS2_LX4_ABL_MASK      (0x10U)
#define PMA_MMD_SR_PMA_STATUS2_LX4_ABL_SHIFT     (4U)
#define PMA_MMD_SR_PMA_STATUS2_LX4_ABL_WIDTH     (1U)
#define PMA_MMD_SR_PMA_STATUS2_LX4_ABL(x)        (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_LX4_ABL_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_LX4_ABL_MASK)

#define PMA_MMD_SR_PMA_STATUS2_ER_ABL_MASK       (0x20U)
#define PMA_MMD_SR_PMA_STATUS2_ER_ABL_SHIFT      (5U)
#define PMA_MMD_SR_PMA_STATUS2_ER_ABL_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_ER_ABL(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_ER_ABL_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_ER_ABL_MASK)

#define PMA_MMD_SR_PMA_STATUS2_LR_ABL_MASK       (0x40U)
#define PMA_MMD_SR_PMA_STATUS2_LR_ABL_SHIFT      (6U)
#define PMA_MMD_SR_PMA_STATUS2_LR_ABL_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_LR_ABL(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_LR_ABL_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_LR_ABL_MASK)

#define PMA_MMD_SR_PMA_STATUS2_SR_ABL_MASK       (0x80U)
#define PMA_MMD_SR_PMA_STATUS2_SR_ABL_SHIFT      (7U)
#define PMA_MMD_SR_PMA_STATUS2_SR_ABL_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_SR_ABL(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_SR_ABL_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_SR_ABL_MASK)

#define PMA_MMD_SR_PMA_STATUS2_TD_ABL_MASK       (0x100U)
#define PMA_MMD_SR_PMA_STATUS2_TD_ABL_SHIFT      (8U)
#define PMA_MMD_SR_PMA_STATUS2_TD_ABL_WIDTH      (1U)
#define PMA_MMD_SR_PMA_STATUS2_TD_ABL(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_TD_ABL_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_TD_ABL_MASK)

#define PMA_MMD_SR_PMA_STATUS2_RF_MASK           (0x400U)
#define PMA_MMD_SR_PMA_STATUS2_RF_SHIFT          (10U)
#define PMA_MMD_SR_PMA_STATUS2_RF_WIDTH          (1U)
#define PMA_MMD_SR_PMA_STATUS2_RF(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_RF_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_RF_MASK)

#define PMA_MMD_SR_PMA_STATUS2_TF_MASK           (0x800U)
#define PMA_MMD_SR_PMA_STATUS2_TF_SHIFT          (11U)
#define PMA_MMD_SR_PMA_STATUS2_TF_WIDTH          (1U)
#define PMA_MMD_SR_PMA_STATUS2_TF(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_TF_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_TF_MASK)

#define PMA_MMD_SR_PMA_STATUS2_PRFA_MASK         (0x1000U)
#define PMA_MMD_SR_PMA_STATUS2_PRFA_SHIFT        (12U)
#define PMA_MMD_SR_PMA_STATUS2_PRFA_WIDTH        (1U)
#define PMA_MMD_SR_PMA_STATUS2_PRFA(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_PRFA_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_PRFA_MASK)

#define PMA_MMD_SR_PMA_STATUS2_PTFA_MASK         (0x2000U)
#define PMA_MMD_SR_PMA_STATUS2_PTFA_SHIFT        (13U)
#define PMA_MMD_SR_PMA_STATUS2_PTFA_WIDTH        (1U)
#define PMA_MMD_SR_PMA_STATUS2_PTFA(x)           (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_PTFA_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_PTFA_MASK)

#define PMA_MMD_SR_PMA_STATUS2_DP_MASK           (0xC000U)
#define PMA_MMD_SR_PMA_STATUS2_DP_SHIFT          (14U)
#define PMA_MMD_SR_PMA_STATUS2_DP_WIDTH          (2U)
#define PMA_MMD_SR_PMA_STATUS2_DP(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_STATUS2_DP_SHIFT)) & PMA_MMD_SR_PMA_STATUS2_DP_MASK)
/*! @} */

/*! @name SR_PMA_TX_DIS - SR_PMA_TX_DIS */
/*! @{ */

#define PMA_MMD_SR_PMA_TX_DIS_GTD_MASK           (0x1U)
#define PMA_MMD_SR_PMA_TX_DIS_GTD_SHIFT          (0U)
#define PMA_MMD_SR_PMA_TX_DIS_GTD_WIDTH          (1U)
#define PMA_MMD_SR_PMA_TX_DIS_GTD(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TX_DIS_GTD_SHIFT)) & PMA_MMD_SR_PMA_TX_DIS_GTD_MASK)

#define PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_MASK  (0x2U)
#define PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_SHIFT (1U)
#define PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_WIDTH (1U)
#define PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0(x)    (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_SHIFT)) & PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_MASK)
/*! @} */

/*! @name SR_PMA_RX_SIG_DET - SR PMA MMD Receive Signal Detect Register */
/*! @{ */

#define PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_MASK    (0x1U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_SHIFT   (0U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_WIDTH   (1U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET(x)      (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_SHIFT)) & PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_MASK)

#define PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_MASK (0x2U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_SHIFT (1U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_WIDTH (1U)
#define PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_SHIFT)) & PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_MASK)
/*! @} */

/*! @name SR_PMA_EXT_ABL - SR PMA or PMD Extended Ability Register */
/*! @{ */

#define PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_MASK   (0x1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_SHIFT  (0U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_WIDTH  (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL(x)     (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_MASK   (0x2U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_SHIFT  (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_WIDTH  (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL(x)     (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_MASK     (0x4U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_SHIFT    (2U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_WIDTH    (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL(x)       (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL_MASK    (0x8U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL_SHIFT   (3U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL_WIDTH   (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL(x)      (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_XGKX4_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL_MASK    (0x10U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL_SHIFT   (4U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL_WIDTH   (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL(x)      (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_XGBKR_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_MASK      (0x20U)
#define PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_SHIFT     (5U)
#define PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_WIDTH     (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL(x)        (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL_MASK (0x40U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL_SHIFT (6U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL_WIDTH (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL(x)   (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_R_100BKX_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_MASK  (0x80U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_SHIFT (7U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_WIDTH (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL(x)    (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_MASK)

#define PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_MASK   (0x100U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_SHIFT  (8U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_WIDTH  (1U)
#define PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL(x)     (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_SHIFT)) & PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_MASK)
/*! @} */

/*! @name SR_PMA_PKG1 - SR PMA MMD Package Identifier 1 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_SHIFT (0U)
#define PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_WIDTH (16U)
#define PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_SHIFT)) & PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_MASK)
/*! @} */

/*! @name SR_PMA_PKG2 - SR PMA MMD Package Identifier 2 Register */
/*! @{ */

#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_MASK  (0xFU)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_SHIFT (0U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_WIDTH (4U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_SHIFT)) & PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_MASK)

#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_MASK (0x3F0U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_SHIFT (4U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_WIDTH (6U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_SHIFT)) & PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_MASK)

#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_MASK (0xFC00U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_SHIFT (10U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_WIDTH (6U)
#define PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_SHIFT)) & PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_MASK)
/*! @} */

/*! @name SR_PMA_2PT5G_5G_EXT_ABL - SR PMA MMD 2. */
/*! @{ */

#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_MASK (0x1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_SHIFT (0U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_WIDTH (1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_SHIFT)) & PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_MASK)

#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_MASK (0x2U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_SHIFT (1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_WIDTH (1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_SHIFT)) & PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_MASK)

#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX_MASK (0x4U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX_SHIFT (2U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX_WIDTH (1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX_SHIFT)) & PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GKX_MASK)

#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR_MASK (0x8U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR_SHIFT (3U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR_WIDTH (1U)
#define PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR_SHIFT)) & PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GKR_MASK)
/*! @} */

/*! @name SR_PMA_KX_CTRL - SR PMA or PMD KX Control Register This register is present only in the configurations with KX_Present mode. */
/*! @{ */

#define PMA_MMD_SR_PMA_KX_CTRL_TOC_MASK          (0x1U)
#define PMA_MMD_SR_PMA_KX_CTRL_TOC_SHIFT         (0U)
#define PMA_MMD_SR_PMA_KX_CTRL_TOC_WIDTH         (1U)
#define PMA_MMD_SR_PMA_KX_CTRL_TOC(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_CTRL_TOC_SHIFT)) & PMA_MMD_SR_PMA_KX_CTRL_TOC_MASK)
/*! @} */

/*! @name SR_PMA_KX_STS - SR PMA or PMD KX Status Register This register is present only in the configurations with KX_Present mode. */
/*! @{ */

#define PMA_MMD_SR_PMA_KX_STS_SD_MASK            (0x1U)
#define PMA_MMD_SR_PMA_KX_STS_SD_SHIFT           (0U)
#define PMA_MMD_SR_PMA_KX_STS_SD_WIDTH           (1U)
#define PMA_MMD_SR_PMA_KX_STS_SD(x)              (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_SD_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_SD_MASK)

#define PMA_MMD_SR_PMA_KX_STS_PMA_TDA_MASK       (0x100U)
#define PMA_MMD_SR_PMA_KX_STS_PMA_TDA_SHIFT      (8U)
#define PMA_MMD_SR_PMA_KX_STS_PMA_TDA_WIDTH      (1U)
#define PMA_MMD_SR_PMA_KX_STS_PMA_TDA(x)         (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_PMA_TDA_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_PMA_TDA_MASK)

#define PMA_MMD_SR_PMA_KX_STS_RX_F_MASK          (0x400U)
#define PMA_MMD_SR_PMA_KX_STS_RX_F_SHIFT         (10U)
#define PMA_MMD_SR_PMA_KX_STS_RX_F_WIDTH         (1U)
#define PMA_MMD_SR_PMA_KX_STS_RX_F(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_RX_F_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_RX_F_MASK)

#define PMA_MMD_SR_PMA_KX_STS_TX_F_MASK          (0x800U)
#define PMA_MMD_SR_PMA_KX_STS_TX_F_SHIFT         (11U)
#define PMA_MMD_SR_PMA_KX_STS_TX_F_WIDTH         (1U)
#define PMA_MMD_SR_PMA_KX_STS_TX_F(x)            (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_TX_F_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_TX_F_MASK)

#define PMA_MMD_SR_PMA_KX_STS_RFA_MASK           (0x1000U)
#define PMA_MMD_SR_PMA_KX_STS_RFA_SHIFT          (12U)
#define PMA_MMD_SR_PMA_KX_STS_RFA_WIDTH          (1U)
#define PMA_MMD_SR_PMA_KX_STS_RFA(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_RFA_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_RFA_MASK)

#define PMA_MMD_SR_PMA_KX_STS_TFA_MASK           (0x2000U)
#define PMA_MMD_SR_PMA_KX_STS_TFA_SHIFT          (13U)
#define PMA_MMD_SR_PMA_KX_STS_TFA_WIDTH          (1U)
#define PMA_MMD_SR_PMA_KX_STS_TFA(x)             (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_KX_STS_TFA_SHIFT)) & PMA_MMD_SR_PMA_KX_STS_TFA_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_PMA_ABL - SR PMA MMD Time Sync Capability Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_MASK (0x1U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_WIDTH (1U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_MASK)

#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_MASK (0x2U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_SHIFT (1U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_WIDTH (1U)
#define PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR - SR PMA MMD Time Sync Tx Max Delay Lower Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR - SR PMA MMD Time Sync Tx Max Delay Upper Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR - SR PMA MMD Time Sync Tx Min Delay Lower Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR - SR PMA MMD Time Sync Tx Min Delay Upper Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR - SR PMA MMD Time Sync Rx Max Delay Lower Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR - SR PMA MMD Time Sync Rx Max Delay Upper Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR - SR PMA MMD Time Sync Rx Min Delay Lower Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR - SR PMA MMD Time Sync Rx Min Delay Upper Register */
/*! @{ */

#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_MASK (0xFFFFU)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_SHIFT (0U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_WIDTH (16U)
#define PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_SHIFT)) & PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name VR_PMA_DIG_CTRL1 - VR PMA MMD Digital Control1 Register */
/*! @{ */

#define PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO_MASK  (0x1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO_SHIFT (0U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO_WIDTH (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO(x)    (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO_SHIFT)) & PMA_MMD_VR_PMA_DIG_CTRL1_CL72_AUTO_MASK)

#define PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_MASK  (0x2U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_WIDTH (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP(x)    (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_SHIFT)) & PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_MASK)

#define PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_WIDTH (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0(x)   (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_SHIFT)) & PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_MASK)

#define PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_MASK      (0x800U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_SHIFT     (11U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_WIDTH     (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV(x)        (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_SHIFT)) & PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_MASK)

#define PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_MASK     (0x8000U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_SHIFT    (15U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_WIDTH    (1U)
#define PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST(x)       (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_SHIFT)) & PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_PMA_DIG_STS - VR PMA MMD Digital Status Register */
/*! @{ */

#define PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_MASK   (0x1CU)
#define PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_SHIFT  (2U)
#define PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_WIDTH  (3U)
#define PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE(x)     (((uint16_t)(((uint16_t)(x)) << PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_SHIFT)) & PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group PMA_MMD_Register_Masks */

/*!
 * @}
 */ /* end of group PMA_MMD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_PMA_MMD_H_) */
