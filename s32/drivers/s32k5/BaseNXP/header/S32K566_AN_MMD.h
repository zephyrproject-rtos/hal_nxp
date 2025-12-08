/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_AN_MMD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_AN_MMD
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
#if !defined(S32K566_AN_MMD_H_)  /* Check if memory map has not been already included */
#define S32K566_AN_MMD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- AN_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AN_MMD_Peripheral_Access_Layer AN_MMD Peripheral Access Layer
 * @{
 */

/** AN_MMD - Register Layout Typedef */
typedef struct AN_MMD_Struct {
  __IO uint16_t SR_AN_CTRL;                        /**< SR AN MMD Control Register, offset: 0x0 */
  __I  uint16_t SR_AN_STS;                         /**< SR AN MMD Status Register, offset: 0x2 */
  __I  uint16_t SR_AN_DEV_ID1;                     /**< SR AN MMD Device Identifier Register 1, offset: 0x4 */
  __I  uint16_t SR_AN_DEV_ID2;                     /**< SR AN MMD Device Identifier Register 2, offset: 0x6 */
  uint8_t RESERVED_0[2];
  __I  uint16_t SR_AN_DEV_PKG1;                    /**< SR AN MMD Devices in Package Register 1, offset: 0xA */
  __I  uint16_t SR_AN_DEV_PKG2;                    /**< SR AN MMD Devices in Package Register 2, offset: 0xC */
  uint8_t RESERVED_1[14];
  __I  uint16_t SR_AN_PKG1;                        /**< SR AN MMD Package Identifier Register 1, offset: 0x1C */
  __I  uint16_t SR_AN_PKG2;                        /**< SR AN MMD Package Identifier Register 2, offset: 0x1E */
  __IO uint16_t SR_AN_ADV1;                        /**< SR AN MMD Advertisement Register 1 The AN Advertisement Register 1, 2, and 3 contain the Base Page Link Code Word for the local device., offset: 0x20 */
  __IO uint16_t SR_AN_ADV2;                        /**< SR AN MMD Advertisement Register 2, offset: 0x22 */
  __IO uint16_t SR_AN_ADV3;                        /**< SR AN MMD Advertisement Register 3, offset: 0x24 */
  __I  uint16_t SR_AN_LP_ABL1;                     /**< SR_AN_LP_ABL1, offset: 0x26 */
  __I  uint16_t SR_AN_LP_ABL2;                     /**< SR AN MMD LP Base Page Ability Register 2, offset: 0x28 */
  __I  uint16_t SR_AN_LP_ABL3;                     /**< SR AN MMD LP Base Page Ability Register 3, offset: 0x2A */
  __IO uint16_t SR_AN_XNP_TX1;                     /**< SR_AN_XNP_TX1, offset: 0x2C */
  __IO uint16_t SR_AN_XNP_TX2;                     /**< SR AN MMD XNP Transmit Register 2, offset: 0x2E */
  __IO uint16_t SR_AN_XNP_TX3;                     /**< SR AN MMD XNP Transmit Register 3, offset: 0x30 */
  __I  uint16_t SR_AN_LP_XNP_ABL1;                 /**< SR_AN_LP_XNP_ABL1, offset: 0x32 */
  __I  uint16_t SR_AN_LP_XNP_ABL2;                 /**< SR AN MMD LP XNP Ability Register 2, offset: 0x34 */
  __I  uint16_t SR_AN_LP_XNP_ABL3;                 /**< SR AN MMD LP XNP Ability Register 3, offset: 0x36 */
  uint8_t RESERVED_2[40];
  __I  uint16_t SR_AN_COMP_STS;                    /**< SR AN MMD Completion Status Register, offset: 0x60 */
  uint8_t RESERVED_3[22];
  __IO uint16_t SR_AN_EEE_ABL1;                    /**< SR AN MMD EEE Capability 1 Register, offset: 0x78 */
  __I  uint16_t SR_AN_EEE_LP_ABL1;                 /**< SR AN MMD EEE Link Partner Capability Register, offset: 0x7A */
  __IO uint16_t SR_AN_EEE_ABL2;                    /**< SR AN MMD EEE Capability 2 Register, offset: 0x7C */
  __I  uint16_t SR_AN_EEE_LP_ABL2;                 /**< SR AN MMD EEE Link Partner Capability 2 Register, offset: 0x7E */
  uint8_t RESERVED_4[65408];
  __IO uint16_t VR_AN_DIG_CTRL1;                   /**< VR AN MMD Digital Control1 Register, offset: 0x10000 */
  __IO uint16_t VR_AN_INTR_MSK;                    /**< VR AN MMD Interrupt Mask Register, offset: 0x10002 */
  __IO uint16_t VR_AN_INTR;                        /**< VR AN MMD Interrupt Register Note: The interrupt output port 'sbd_intr_o' goes high when any bit of this register is set along with the corresponding bit of VR_AN_INTR_MSK Register., offset: 0x10004 */
  __I  uint16_t VR_AN_KR_MODE_CTRL;                /**< VR AN MMD KR Mode Control Register, offset: 0x10006 */
  __IO uint16_t VR_AN_TIMER_CTRL0;                 /**< VR AN MMD Timer Control 0 Register, offset: 0x10008 */
  __IO uint16_t VR_AN_TIMER_CTRL1;                 /**< VR AN MMD Timer Control 1 Register, offset: 0x1000A */
  uint8_t RESERVED_5[20];
  __I  uint16_t VR_AN_DIG_STS;                     /**< VR AN MMD Digital Status Register, offset: 0x10020 */
} AN_MMD_Type, *AN_MMD_MemMapPtr;

/** Number of instances of the AN_MMD module. */
#define AN_MMD_INSTANCE_COUNT                    (1u)

/* AN_MMD - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD_BASE (0x8E0000u)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD ((AN_MMD_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD_BASE)
/** Array initializer of AN_MMD peripheral base addresses */
#define IP_AN_MMD_BASE_ADDRS                     { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD_BASE }
/** Array initializer of AN_MMD peripheral base pointers */
#define IP_AN_MMD_BASE_PTRS                      { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__AN_MMD }

/* ----------------------------------------------------------------------------
   -- AN_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup AN_MMD_Register_Masks AN_MMD Register Masks
 * @{
 */

/*! @name SR_AN_CTRL - SR AN MMD Control Register */
/*! @{ */

#define AN_MMD_SR_AN_CTRL_RSTRT_AN_MASK          (0x200U)
#define AN_MMD_SR_AN_CTRL_RSTRT_AN_SHIFT         (9U)
#define AN_MMD_SR_AN_CTRL_RSTRT_AN_WIDTH         (1U)
#define AN_MMD_SR_AN_CTRL_RSTRT_AN(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_CTRL_RSTRT_AN_SHIFT)) & AN_MMD_SR_AN_CTRL_RSTRT_AN_MASK)

#define AN_MMD_SR_AN_CTRL_LPM_MASK               (0x800U)
#define AN_MMD_SR_AN_CTRL_LPM_SHIFT              (11U)
#define AN_MMD_SR_AN_CTRL_LPM_WIDTH              (1U)
#define AN_MMD_SR_AN_CTRL_LPM(x)                 (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_CTRL_LPM_SHIFT)) & AN_MMD_SR_AN_CTRL_LPM_MASK)

#define AN_MMD_SR_AN_CTRL_AN_EN_MASK             (0x1000U)
#define AN_MMD_SR_AN_CTRL_AN_EN_SHIFT            (12U)
#define AN_MMD_SR_AN_CTRL_AN_EN_WIDTH            (1U)
#define AN_MMD_SR_AN_CTRL_AN_EN(x)               (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_CTRL_AN_EN_SHIFT)) & AN_MMD_SR_AN_CTRL_AN_EN_MASK)

#define AN_MMD_SR_AN_CTRL_EXT_NP_CTL_MASK        (0x2000U)
#define AN_MMD_SR_AN_CTRL_EXT_NP_CTL_SHIFT       (13U)
#define AN_MMD_SR_AN_CTRL_EXT_NP_CTL_WIDTH       (1U)
#define AN_MMD_SR_AN_CTRL_EXT_NP_CTL(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_CTRL_EXT_NP_CTL_SHIFT)) & AN_MMD_SR_AN_CTRL_EXT_NP_CTL_MASK)

#define AN_MMD_SR_AN_CTRL_AN_RST_MASK            (0x8000U)
#define AN_MMD_SR_AN_CTRL_AN_RST_SHIFT           (15U)
#define AN_MMD_SR_AN_CTRL_AN_RST_WIDTH           (1U)
#define AN_MMD_SR_AN_CTRL_AN_RST(x)              (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_CTRL_AN_RST_SHIFT)) & AN_MMD_SR_AN_CTRL_AN_RST_MASK)
/*! @} */

/*! @name SR_AN_STS - SR AN MMD Status Register */
/*! @{ */

#define AN_MMD_SR_AN_STS_LP_AN_ABL_MASK          (0x1U)
#define AN_MMD_SR_AN_STS_LP_AN_ABL_SHIFT         (0U)
#define AN_MMD_SR_AN_STS_LP_AN_ABL_WIDTH         (1U)
#define AN_MMD_SR_AN_STS_LP_AN_ABL(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_LP_AN_ABL_SHIFT)) & AN_MMD_SR_AN_STS_LP_AN_ABL_MASK)

#define AN_MMD_SR_AN_STS_AN_LS_MASK              (0x4U)
#define AN_MMD_SR_AN_STS_AN_LS_SHIFT             (2U)
#define AN_MMD_SR_AN_STS_AN_LS_WIDTH             (1U)
#define AN_MMD_SR_AN_STS_AN_LS(x)                (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_AN_LS_SHIFT)) & AN_MMD_SR_AN_STS_AN_LS_MASK)

#define AN_MMD_SR_AN_STS_AN_ABL_MASK             (0x8U)
#define AN_MMD_SR_AN_STS_AN_ABL_SHIFT            (3U)
#define AN_MMD_SR_AN_STS_AN_ABL_WIDTH            (1U)
#define AN_MMD_SR_AN_STS_AN_ABL(x)               (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_AN_ABL_SHIFT)) & AN_MMD_SR_AN_STS_AN_ABL_MASK)

#define AN_MMD_SR_AN_STS_AN_RF_MASK              (0x10U)
#define AN_MMD_SR_AN_STS_AN_RF_SHIFT             (4U)
#define AN_MMD_SR_AN_STS_AN_RF_WIDTH             (1U)
#define AN_MMD_SR_AN_STS_AN_RF(x)                (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_AN_RF_SHIFT)) & AN_MMD_SR_AN_STS_AN_RF_MASK)

#define AN_MMD_SR_AN_STS_ANC_MASK                (0x20U)
#define AN_MMD_SR_AN_STS_ANC_SHIFT               (5U)
#define AN_MMD_SR_AN_STS_ANC_WIDTH               (1U)
#define AN_MMD_SR_AN_STS_ANC(x)                  (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_ANC_SHIFT)) & AN_MMD_SR_AN_STS_ANC_MASK)

#define AN_MMD_SR_AN_STS_PR_MASK                 (0x40U)
#define AN_MMD_SR_AN_STS_PR_SHIFT                (6U)
#define AN_MMD_SR_AN_STS_PR_WIDTH                (1U)
#define AN_MMD_SR_AN_STS_PR(x)                   (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_PR_SHIFT)) & AN_MMD_SR_AN_STS_PR_MASK)

#define AN_MMD_SR_AN_STS_EXT_NP_STS_MASK         (0x80U)
#define AN_MMD_SR_AN_STS_EXT_NP_STS_SHIFT        (7U)
#define AN_MMD_SR_AN_STS_EXT_NP_STS_WIDTH        (1U)
#define AN_MMD_SR_AN_STS_EXT_NP_STS(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_EXT_NP_STS_SHIFT)) & AN_MMD_SR_AN_STS_EXT_NP_STS_MASK)

#define AN_MMD_SR_AN_STS_PDF_MASK                (0x200U)
#define AN_MMD_SR_AN_STS_PDF_SHIFT               (9U)
#define AN_MMD_SR_AN_STS_PDF_WIDTH               (1U)
#define AN_MMD_SR_AN_STS_PDF(x)                  (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_STS_PDF_SHIFT)) & AN_MMD_SR_AN_STS_PDF_MASK)
/*! @} */

/*! @name SR_AN_DEV_ID1 - SR AN MMD Device Identifier Register 1 */
/*! @{ */

#define AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18_MASK (0xFFFFU)
#define AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18_SHIFT (0U)
#define AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18_WIDTH (16U)
#define AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18_SHIFT)) & AN_MMD_SR_AN_DEV_ID1_AN_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_AN_DEV_ID2 - SR AN MMD Device Identifier Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0_MASK  (0xFU)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0_SHIFT (0U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0_WIDTH (4U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0_SHIFT)) & AN_MMD_SR_AN_DEV_ID2_AN_DEV_RN_3_0_MASK)

#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0_MASK (0x3F0U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0_SHIFT (4U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0_WIDTH (6U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0_SHIFT)) & AN_MMD_SR_AN_DEV_ID2_AN_DEV_MMN_5_0_MASK)

#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24_MASK (0xFC00U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24_SHIFT (10U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24_WIDTH (6U)
#define AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24_SHIFT)) & AN_MMD_SR_AN_DEV_ID2_AN_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_AN_DEV_PKG1 - SR AN MMD Devices in Package Register 1 */
/*! @{ */

#define AN_MMD_SR_AN_DEV_PKG1_CLS22_MASK         (0x1U)
#define AN_MMD_SR_AN_DEV_PKG1_CLS22_SHIFT        (0U)
#define AN_MMD_SR_AN_DEV_PKG1_CLS22_WIDTH        (1U)
#define AN_MMD_SR_AN_DEV_PKG1_CLS22(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_CLS22_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_CLS22_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_PMA_PMD_MASK       (0x2U)
#define AN_MMD_SR_AN_DEV_PKG1_PMA_PMD_SHIFT      (1U)
#define AN_MMD_SR_AN_DEV_PKG1_PMA_PMD_WIDTH      (1U)
#define AN_MMD_SR_AN_DEV_PKG1_PMA_PMD(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_PMA_PMD_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_PMA_PMD_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_WIS_MASK           (0x4U)
#define AN_MMD_SR_AN_DEV_PKG1_WIS_SHIFT          (2U)
#define AN_MMD_SR_AN_DEV_PKG1_WIS_WIDTH          (1U)
#define AN_MMD_SR_AN_DEV_PKG1_WIS(x)             (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_WIS_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_WIS_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_PCS_MASK           (0x8U)
#define AN_MMD_SR_AN_DEV_PKG1_PCS_SHIFT          (3U)
#define AN_MMD_SR_AN_DEV_PKG1_PCS_WIDTH          (1U)
#define AN_MMD_SR_AN_DEV_PKG1_PCS(x)             (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_PCS_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_PCS_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_PHYXS_MASK         (0x10U)
#define AN_MMD_SR_AN_DEV_PKG1_PHYXS_SHIFT        (4U)
#define AN_MMD_SR_AN_DEV_PKG1_PHYXS_WIDTH        (1U)
#define AN_MMD_SR_AN_DEV_PKG1_PHYXS(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_PHYXS_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_PHYXS_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_DTEXS_MASK         (0x20U)
#define AN_MMD_SR_AN_DEV_PKG1_DTEXS_SHIFT        (5U)
#define AN_MMD_SR_AN_DEV_PKG1_DTEXS_WIDTH        (1U)
#define AN_MMD_SR_AN_DEV_PKG1_DTEXS(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_DTEXS_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_DTEXS_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_TC_MASK            (0x40U)
#define AN_MMD_SR_AN_DEV_PKG1_TC_SHIFT           (6U)
#define AN_MMD_SR_AN_DEV_PKG1_TC_WIDTH           (1U)
#define AN_MMD_SR_AN_DEV_PKG1_TC(x)              (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_TC_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_TC_MASK)

#define AN_MMD_SR_AN_DEV_PKG1_AN_MASK            (0x80U)
#define AN_MMD_SR_AN_DEV_PKG1_AN_SHIFT           (7U)
#define AN_MMD_SR_AN_DEV_PKG1_AN_WIDTH           (1U)
#define AN_MMD_SR_AN_DEV_PKG1_AN(x)              (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG1_AN_SHIFT)) & AN_MMD_SR_AN_DEV_PKG1_AN_MASK)
/*! @} */

/*! @name SR_AN_DEV_PKG2 - SR AN MMD Devices in Package Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_DEV_PKG2_VSD1_MASK          (0x4000U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD1_SHIFT         (14U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD1_WIDTH         (1U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD1(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG2_VSD1_SHIFT)) & AN_MMD_SR_AN_DEV_PKG2_VSD1_MASK)

#define AN_MMD_SR_AN_DEV_PKG2_VSD2_MASK          (0x8000U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD2_SHIFT         (15U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD2_WIDTH         (1U)
#define AN_MMD_SR_AN_DEV_PKG2_VSD2(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_DEV_PKG2_VSD2_SHIFT)) & AN_MMD_SR_AN_DEV_PKG2_VSD2_MASK)
/*! @} */

/*! @name SR_AN_PKG1 - SR AN MMD Package Identifier Register 1 */
/*! @{ */

#define AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18_MASK   (0xFFFFU)
#define AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18_SHIFT  (0U)
#define AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18_WIDTH  (16U)
#define AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18_SHIFT)) & AN_MMD_SR_AN_PKG1_AN_PKG_OUI_3_18_MASK)
/*! @} */

/*! @name SR_AN_PKG2 - SR AN MMD Package Identifier Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0_MASK     (0xFU)
#define AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0_SHIFT    (0U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0_WIDTH    (4U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0_SHIFT)) & AN_MMD_SR_AN_PKG2_AN_PKG_RN_3_0_MASK)

#define AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0_MASK    (0x3F0U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0_SHIFT   (4U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0_WIDTH   (6U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0_SHIFT)) & AN_MMD_SR_AN_PKG2_AN_PKG_MMN_5_0_MASK)

#define AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24_MASK  (0xFC00U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24_SHIFT (10U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24_WIDTH (6U)
#define AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24_SHIFT)) & AN_MMD_SR_AN_PKG2_AN_PKG_OUI_19_24_MASK)
/*! @} */

/*! @name SR_AN_ADV1 - SR AN MMD Advertisement Register 1 The AN Advertisement Register 1, 2, and 3 contain the Base Page Link Code Word for the local device. */
/*! @{ */

#define AN_MMD_SR_AN_ADV1_AN_ADV_SF_MASK         (0x1FU)
#define AN_MMD_SR_AN_ADV1_AN_ADV_SF_SHIFT        (0U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_SF_WIDTH        (5U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_SF(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV1_AN_ADV_SF_SHIFT)) & AN_MMD_SR_AN_ADV1_AN_ADV_SF_MASK)

#define AN_MMD_SR_AN_ADV1_DATA_MASK              (0xFE0U)
#define AN_MMD_SR_AN_ADV1_DATA_SHIFT             (5U)
#define AN_MMD_SR_AN_ADV1_DATA_WIDTH             (7U)
#define AN_MMD_SR_AN_ADV1_DATA(x)                (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV1_DATA_SHIFT)) & AN_MMD_SR_AN_ADV1_DATA_MASK)

#define AN_MMD_SR_AN_ADV1_AN_ADV_RF_13_MASK      (0x2000U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_RF_13_SHIFT     (13U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_RF_13_WIDTH     (1U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_RF_13(x)        (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV1_AN_ADV_RF_13_SHIFT)) & AN_MMD_SR_AN_ADV1_AN_ADV_RF_13_MASK)

#define AN_MMD_SR_AN_ADV1_AN_ADV_ACK_MASK        (0x4000U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_ACK_SHIFT       (14U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_ACK_WIDTH       (1U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_ACK(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV1_AN_ADV_ACK_SHIFT)) & AN_MMD_SR_AN_ADV1_AN_ADV_ACK_MASK)

#define AN_MMD_SR_AN_ADV1_AN_ADV_NP_MASK         (0x8000U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_NP_SHIFT        (15U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_NP_WIDTH        (1U)
#define AN_MMD_SR_AN_ADV1_AN_ADV_NP(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV1_AN_ADV_NP_SHIFT)) & AN_MMD_SR_AN_ADV1_AN_ADV_NP_MASK)
/*! @} */

/*! @name SR_AN_ADV2 - SR AN MMD Advertisement Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_ADV2_DATA_31_16_MASK        (0xFFFFU)
#define AN_MMD_SR_AN_ADV2_DATA_31_16_SHIFT       (0U)
#define AN_MMD_SR_AN_ADV2_DATA_31_16_WIDTH       (16U)
#define AN_MMD_SR_AN_ADV2_DATA_31_16(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV2_DATA_31_16_SHIFT)) & AN_MMD_SR_AN_ADV2_DATA_31_16_MASK)
/*! @} */

/*! @name SR_AN_ADV3 - SR AN MMD Advertisement Register 3 */
/*! @{ */

#define AN_MMD_SR_AN_ADV3_DATA_47_32_MASK        (0xFFFFU)
#define AN_MMD_SR_AN_ADV3_DATA_47_32_SHIFT       (0U)
#define AN_MMD_SR_AN_ADV3_DATA_47_32_WIDTH       (16U)
#define AN_MMD_SR_AN_ADV3_DATA_47_32(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_ADV3_DATA_47_32_SHIFT)) & AN_MMD_SR_AN_ADV3_DATA_47_32_MASK)
/*! @} */

/*! @name SR_AN_LP_ABL1 - SR_AN_LP_ABL1 */
/*! @{ */

#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF_MASK   (0x1FU)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF_SHIFT  (0U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF_WIDTH  (5U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF_SHIFT)) & AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_SF_MASK)

#define AN_MMD_SR_AN_LP_ABL1_DATA_MASK           (0xFE0U)
#define AN_MMD_SR_AN_LP_ABL1_DATA_SHIFT          (5U)
#define AN_MMD_SR_AN_LP_ABL1_DATA_WIDTH          (7U)
#define AN_MMD_SR_AN_LP_ABL1_DATA(x)             (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL1_DATA_SHIFT)) & AN_MMD_SR_AN_LP_ABL1_DATA_MASK)

#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF_MASK   (0x2000U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF_SHIFT  (13U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF_WIDTH  (1U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF_SHIFT)) & AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_RF_MASK)

#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK_MASK  (0x4000U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK_SHIFT (14U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK_WIDTH (1U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK_SHIFT)) & AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_ACK_MASK)

#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP_MASK   (0x8000U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP_SHIFT  (15U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP_WIDTH  (1U)
#define AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP_SHIFT)) & AN_MMD_SR_AN_LP_ABL1_AN_LP_ADV_NP_MASK)
/*! @} */

/*! @name SR_AN_LP_ABL2 - SR AN MMD LP Base Page Ability Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_LP_ABL2_DATA_31_16_MASK     (0xFFFFU)
#define AN_MMD_SR_AN_LP_ABL2_DATA_31_16_SHIFT    (0U)
#define AN_MMD_SR_AN_LP_ABL2_DATA_31_16_WIDTH    (16U)
#define AN_MMD_SR_AN_LP_ABL2_DATA_31_16(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL2_DATA_31_16_SHIFT)) & AN_MMD_SR_AN_LP_ABL2_DATA_31_16_MASK)
/*! @} */

/*! @name SR_AN_LP_ABL3 - SR AN MMD LP Base Page Ability Register 3 */
/*! @{ */

#define AN_MMD_SR_AN_LP_ABL3_DATA_47_32_MASK     (0xFFFFU)
#define AN_MMD_SR_AN_LP_ABL3_DATA_47_32_SHIFT    (0U)
#define AN_MMD_SR_AN_LP_ABL3_DATA_47_32_WIDTH    (16U)
#define AN_MMD_SR_AN_LP_ABL3_DATA_47_32(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_ABL3_DATA_47_32_SHIFT)) & AN_MMD_SR_AN_LP_ABL3_DATA_47_32_MASK)
/*! @} */

/*! @name SR_AN_XNP_TX1 - SR_AN_XNP_TX1 */
/*! @{ */

#define AN_MMD_SR_AN_XNP_TX1_MCF_MASK            (0x7FFU)
#define AN_MMD_SR_AN_XNP_TX1_MCF_SHIFT           (0U)
#define AN_MMD_SR_AN_XNP_TX1_MCF_WIDTH           (11U)
#define AN_MMD_SR_AN_XNP_TX1_MCF(x)              (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX1_MCF_SHIFT)) & AN_MMD_SR_AN_XNP_TX1_MCF_MASK)

#define AN_MMD_SR_AN_XNP_TX1_TB_MASK             (0x800U)
#define AN_MMD_SR_AN_XNP_TX1_TB_SHIFT            (11U)
#define AN_MMD_SR_AN_XNP_TX1_TB_WIDTH            (1U)
#define AN_MMD_SR_AN_XNP_TX1_TB(x)               (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX1_TB_SHIFT)) & AN_MMD_SR_AN_XNP_TX1_TB_MASK)

#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2_MASK    (0x1000U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2_SHIFT   (12U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2_WIDTH   (1U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2_SHIFT)) & AN_MMD_SR_AN_XNP_TX1_AN_XNP_ACK2_MASK)

#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP_MASK      (0x2000U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP_SHIFT     (13U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP_WIDTH     (1U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP(x)        (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP_SHIFT)) & AN_MMD_SR_AN_XNP_TX1_AN_XNP_MP_MASK)

#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP_MASK      (0x8000U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP_SHIFT     (15U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP_WIDTH     (1U)
#define AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP(x)        (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP_SHIFT)) & AN_MMD_SR_AN_XNP_TX1_AN_XNP_NP_MASK)
/*! @} */

/*! @name SR_AN_XNP_TX2 - SR AN MMD XNP Transmit Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_XNP_TX2_UMCF1_MASK          (0xFFFFU)
#define AN_MMD_SR_AN_XNP_TX2_UMCF1_SHIFT         (0U)
#define AN_MMD_SR_AN_XNP_TX2_UMCF1_WIDTH         (16U)
#define AN_MMD_SR_AN_XNP_TX2_UMCF1(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX2_UMCF1_SHIFT)) & AN_MMD_SR_AN_XNP_TX2_UMCF1_MASK)
/*! @} */

/*! @name SR_AN_XNP_TX3 - SR AN MMD XNP Transmit Register 3 */
/*! @{ */

#define AN_MMD_SR_AN_XNP_TX3_UMCF2_MASK          (0xFFFFU)
#define AN_MMD_SR_AN_XNP_TX3_UMCF2_SHIFT         (0U)
#define AN_MMD_SR_AN_XNP_TX3_UMCF2_WIDTH         (16U)
#define AN_MMD_SR_AN_XNP_TX3_UMCF2(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_XNP_TX3_UMCF2_SHIFT)) & AN_MMD_SR_AN_XNP_TX3_UMCF2_MASK)
/*! @} */

/*! @name SR_AN_LP_XNP_ABL1 - SR_AN_LP_XNP_ABL1 */
/*! @{ */

#define AN_MMD_SR_AN_LP_XNP_ABL1_MCF_MASK        (0x7FFU)
#define AN_MMD_SR_AN_LP_XNP_ABL1_MCF_SHIFT       (0U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_MCF_WIDTH       (11U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_MCF(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_MCF_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_MCF_MASK)

#define AN_MMD_SR_AN_LP_XNP_ABL1_TB_MASK         (0x800U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_TB_SHIFT        (11U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_TB_WIDTH        (1U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_TB(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_TB_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_TB_MASK)

#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2_MASK (0x1000U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2_SHIFT (12U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2_WIDTH (1U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK2_MASK)

#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP_MASK (0x2000U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP_SHIFT (13U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP_WIDTH (1U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_MP_MASK)

#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK_MASK (0x4000U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK_SHIFT (14U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK_WIDTH (1U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_ACK_MASK)

#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP_MASK (0x8000U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP_SHIFT (15U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP_WIDTH (1U)
#define AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL1_AN_LP_XNP_NP_MASK)
/*! @} */

/*! @name SR_AN_LP_XNP_ABL2 - SR AN MMD LP XNP Ability Register 2 */
/*! @{ */

#define AN_MMD_SR_AN_LP_XNP_ABL2_UCF1_MASK       (0xFFFFU)
#define AN_MMD_SR_AN_LP_XNP_ABL2_UCF1_SHIFT      (0U)
#define AN_MMD_SR_AN_LP_XNP_ABL2_UCF1_WIDTH      (16U)
#define AN_MMD_SR_AN_LP_XNP_ABL2_UCF1(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL2_UCF1_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL2_UCF1_MASK)
/*! @} */

/*! @name SR_AN_LP_XNP_ABL3 - SR AN MMD LP XNP Ability Register 3 */
/*! @{ */

#define AN_MMD_SR_AN_LP_XNP_ABL3_UCF2_MASK       (0xFFFFU)
#define AN_MMD_SR_AN_LP_XNP_ABL3_UCF2_SHIFT      (0U)
#define AN_MMD_SR_AN_LP_XNP_ABL3_UCF2_WIDTH      (16U)
#define AN_MMD_SR_AN_LP_XNP_ABL3_UCF2(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_LP_XNP_ABL3_UCF2_SHIFT)) & AN_MMD_SR_AN_LP_XNP_ABL3_UCF2_MASK)
/*! @} */

/*! @name SR_AN_COMP_STS - SR AN MMD Completion Status Register */
/*! @{ */

#define AN_MMD_SR_AN_COMP_STS_BP_AN_ABL_MASK     (0x1U)
#define AN_MMD_SR_AN_COMP_STS_BP_AN_ABL_SHIFT    (0U)
#define AN_MMD_SR_AN_COMP_STS_BP_AN_ABL_WIDTH    (1U)
#define AN_MMD_SR_AN_COMP_STS_BP_AN_ABL(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_COMP_STS_BP_AN_ABL_SHIFT)) & AN_MMD_SR_AN_COMP_STS_BP_AN_ABL_MASK)

#define AN_MMD_SR_AN_COMP_STS_AN_COMP_KX_MASK    (0x2U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_KX_SHIFT   (1U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_KX_WIDTH   (1U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_KX(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_COMP_STS_AN_COMP_KX_SHIFT)) & AN_MMD_SR_AN_COMP_STS_AN_COMP_KX_MASK)

#define AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC_MASK   (0x10U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC_SHIFT  (4U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC_WIDTH  (1U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC_SHIFT)) & AN_MMD_SR_AN_COMP_STS_AN_COMP_FEC_MASK)

#define AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G_MASK (0x4000U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G_SHIFT (14U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G_WIDTH (1U)
#define AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G(x)   (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G_SHIFT)) & AN_MMD_SR_AN_COMP_STS_AN_COMP_2PT5G_MASK)
/*! @} */

/*! @name SR_AN_EEE_ABL1 - SR AN MMD EEE Capability 1 Register */
/*! @{ */

#define AN_MMD_SR_AN_EEE_ABL1_EN_100TEE_MASK     (0x2U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_100TEE_SHIFT    (1U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_100TEE_WIDTH    (1U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_100TEE(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_EN_100TEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_EN_100TEE_MASK)

#define AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE_MASK     (0x4U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE_SHIFT    (2U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE_WIDTH    (1U)
#define AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE(x)       (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_EN_1GTEEE_MASK)

#define AN_MMD_SR_AN_EEE_ABL1_TEEE_MASK          (0x8U)
#define AN_MMD_SR_AN_EEE_ABL1_TEEE_SHIFT         (3U)
#define AN_MMD_SR_AN_EEE_ABL1_TEEE_WIDTH         (1U)
#define AN_MMD_SR_AN_EEE_ABL1_TEEE(x)            (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_TEEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_TEEE_MASK)

#define AN_MMD_SR_AN_EEE_ABL1_KXEEE_MASK         (0x10U)
#define AN_MMD_SR_AN_EEE_ABL1_KXEEE_SHIFT        (4U)
#define AN_MMD_SR_AN_EEE_ABL1_KXEEE_WIDTH        (1U)
#define AN_MMD_SR_AN_EEE_ABL1_KXEEE(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_KXEEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_KXEEE_MASK)

#define AN_MMD_SR_AN_EEE_ABL1_KX4EEE_MASK        (0x20U)
#define AN_MMD_SR_AN_EEE_ABL1_KX4EEE_SHIFT       (5U)
#define AN_MMD_SR_AN_EEE_ABL1_KX4EEE_WIDTH       (1U)
#define AN_MMD_SR_AN_EEE_ABL1_KX4EEE(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_KX4EEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_KX4EEE_MASK)

#define AN_MMD_SR_AN_EEE_ABL1_KREEE_MASK         (0x40U)
#define AN_MMD_SR_AN_EEE_ABL1_KREEE_SHIFT        (6U)
#define AN_MMD_SR_AN_EEE_ABL1_KREEE_WIDTH        (1U)
#define AN_MMD_SR_AN_EEE_ABL1_KREEE(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL1_KREEE_SHIFT)) & AN_MMD_SR_AN_EEE_ABL1_KREEE_MASK)
/*! @} */

/*! @name SR_AN_EEE_LP_ABL1 - SR AN MMD EEE Link Partner Capability Register */
/*! @{ */

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE_MASK  (0x2U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE_SHIFT (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE_WIDTH (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_100TEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE_MASK  (0x4U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE_SHIFT (2U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE_WIDTH (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_1GTEEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE_MASK    (0x8U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE_SHIFT   (3U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE_WIDTH   (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_TEEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE_MASK   (0x10U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE_SHIFT  (4U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE_WIDTH  (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_KXEEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE_MASK  (0x20U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE_SHIFT (5U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE_WIDTH (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_KX4EEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE_MASK   (0x40U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE_SHIFT  (6U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE_WIDTH  (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL1_LP_KREEE_MASK)
/*! @} */

/*! @name SR_AN_EEE_ABL2 - SR AN MMD EEE Capability 2 Register */
/*! @{ */

#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT_MASK    (0x1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT_SHIFT   (0U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT_WIDTH   (1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT_SHIFT)) & AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GT_MASK)

#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GT_MASK       (0x2U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GT_SHIFT      (1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GT_WIDTH      (1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GT(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL2_EEE_5GT_SHIFT)) & AN_MMD_SR_AN_EEE_ABL2_EEE_5GT_MASK)

#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX_MASK   (0x4U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX_SHIFT  (2U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX_WIDTH  (1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX_SHIFT)) & AN_MMD_SR_AN_EEE_ABL2_EEE_2PT5GKX_MASK)

#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR_MASK      (0x8U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR_SHIFT     (3U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR_WIDTH     (1U)
#define AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR(x)        (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR_SHIFT)) & AN_MMD_SR_AN_EEE_ABL2_EEE_5GKR_MASK)
/*! @} */

/*! @name SR_AN_EEE_LP_ABL2 - SR AN MMD EEE Link Partner Capability 2 Register */
/*! @{ */

#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE_MASK (0x4U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE_SHIFT (2U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE_WIDTH (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL2_LP_2PT5GKXEEE_MASK)

#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE_MASK (0x8U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE_SHIFT (3U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE_WIDTH (1U)
#define AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE(x)   (((uint16_t)(((uint16_t)(x)) << AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE_SHIFT)) & AN_MMD_SR_AN_EEE_LP_ABL2_LP_5GKREEE_MASK)
/*! @} */

/*! @name VR_AN_DIG_CTRL1 - VR AN MMD Digital Control1 Register */
/*! @{ */

#define AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP_MASK    (0x2U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP_SHIFT   (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP_WIDTH   (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP(x)      (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP_SHIFT)) & AN_MMD_VR_AN_DIG_CTRL1_BYP_PWRUP_MASK)

#define AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT_MASK (0x4U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT_SHIFT (2U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT_WIDTH (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT(x)  (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT_SHIFT)) & AN_MMD_VR_AN_DIG_CTRL1_BYP_NONCE_MAT_MASK)

#define AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE_MASK (0x8U)
#define AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE_SHIFT (3U)
#define AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE_WIDTH (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE_SHIFT)) & AN_MMD_VR_AN_DIG_CTRL1_CL73_TMR_OVR_RIDE_MASK)

#define AN_MMD_VR_AN_DIG_CTRL1_PWRSV_MASK        (0x800U)
#define AN_MMD_VR_AN_DIG_CTRL1_PWRSV_SHIFT       (11U)
#define AN_MMD_VR_AN_DIG_CTRL1_PWRSV_WIDTH       (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_PWRSV(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_CTRL1_PWRSV_SHIFT)) & AN_MMD_VR_AN_DIG_CTRL1_PWRSV_MASK)

#define AN_MMD_VR_AN_DIG_CTRL1_VR_RST_MASK       (0x8000U)
#define AN_MMD_VR_AN_DIG_CTRL1_VR_RST_SHIFT      (15U)
#define AN_MMD_VR_AN_DIG_CTRL1_VR_RST_WIDTH      (1U)
#define AN_MMD_VR_AN_DIG_CTRL1_VR_RST(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_CTRL1_VR_RST_SHIFT)) & AN_MMD_VR_AN_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_AN_INTR_MSK - VR AN MMD Interrupt Mask Register */
/*! @{ */

#define AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE_MASK (0x1U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE_SHIFT (0U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE_WIDTH (1U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE_SHIFT)) & AN_MMD_VR_AN_INTR_MSK_AN_INT_CMPLT_IE_MASK)

#define AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE_MASK (0x2U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE_SHIFT (1U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE_WIDTH (1U)
#define AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE(x)  (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE_SHIFT)) & AN_MMD_VR_AN_INTR_MSK_AN_INC_LINK_IE_MASK)

#define AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE_MASK  (0x4U)
#define AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE_SHIFT (2U)
#define AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE_WIDTH (1U)
#define AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE(x)    (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE_SHIFT)) & AN_MMD_VR_AN_INTR_MSK_AN_PG_RCV_IE_MASK)
/*! @} */

/*! @name VR_AN_INTR - VR AN MMD Interrupt Register Note: The interrupt output port 'sbd_intr_o' goes high when any bit of this register is set along with the corresponding bit of VR_AN_INTR_MSK Register. */
/*! @{ */

#define AN_MMD_VR_AN_INTR_AN_INT_CMPLT_MASK      (0x1U)
#define AN_MMD_VR_AN_INTR_AN_INT_CMPLT_SHIFT     (0U)
#define AN_MMD_VR_AN_INTR_AN_INT_CMPLT_WIDTH     (1U)
#define AN_MMD_VR_AN_INTR_AN_INT_CMPLT(x)        (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_AN_INT_CMPLT_SHIFT)) & AN_MMD_VR_AN_INTR_AN_INT_CMPLT_MASK)

#define AN_MMD_VR_AN_INTR_AN_INC_LINK_MASK       (0x2U)
#define AN_MMD_VR_AN_INTR_AN_INC_LINK_SHIFT      (1U)
#define AN_MMD_VR_AN_INTR_AN_INC_LINK_WIDTH      (1U)
#define AN_MMD_VR_AN_INTR_AN_INC_LINK(x)         (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_AN_INC_LINK_SHIFT)) & AN_MMD_VR_AN_INTR_AN_INC_LINK_MASK)

#define AN_MMD_VR_AN_INTR_AN_PG_RCV_MASK         (0x4U)
#define AN_MMD_VR_AN_INTR_AN_PG_RCV_SHIFT        (2U)
#define AN_MMD_VR_AN_INTR_AN_PG_RCV_WIDTH        (1U)
#define AN_MMD_VR_AN_INTR_AN_PG_RCV(x)           (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_INTR_AN_PG_RCV_SHIFT)) & AN_MMD_VR_AN_INTR_AN_PG_RCV_MASK)
/*! @} */

/*! @name VR_AN_KR_MODE_CTRL - VR AN MMD KR Mode Control Register */
/*! @{ */

#define AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN_MASK   (0x1U)
#define AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN_SHIFT  (0U)
#define AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN_WIDTH  (1U)
#define AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN(x)     (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN_SHIFT)) & AN_MMD_VR_AN_KR_MODE_CTRL_PDET_EN_MASK)
/*! @} */

/*! @name VR_AN_TIMER_CTRL0 - VR AN MMD Timer Control 0 Register */
/*! @{ */

#define AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME_MASK (0xFFFFU)
#define AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME_SHIFT (0U)
#define AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME_WIDTH (16U)
#define AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME_SHIFT)) & AN_MMD_VR_AN_TIMER_CTRL0_BRK_LINK_TIME_MASK)
/*! @} */

/*! @name VR_AN_TIMER_CTRL1 - VR AN MMD Timer Control 1 Register */
/*! @{ */

#define AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME_MASK (0xFFFFU)
#define AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME_SHIFT (0U)
#define AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME_WIDTH (16U)
#define AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME(x) (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME_SHIFT)) & AN_MMD_VR_AN_TIMER_CTRL1_INHBT_OR_WAIT_TIME_MASK)
/*! @} */

/*! @name VR_AN_DIG_STS - VR AN MMD Digital Status Register */
/*! @{ */

#define AN_MMD_VR_AN_DIG_STS_ANA_FSM_MASK        (0xFU)
#define AN_MMD_VR_AN_DIG_STS_ANA_FSM_SHIFT       (0U)
#define AN_MMD_VR_AN_DIG_STS_ANA_FSM_WIDTH       (4U)
#define AN_MMD_VR_AN_DIG_STS_ANA_FSM(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_STS_ANA_FSM_SHIFT)) & AN_MMD_VR_AN_DIG_STS_ANA_FSM_MASK)

#define AN_MMD_VR_AN_DIG_STS_ANR_FSM_MASK        (0x1F0U)
#define AN_MMD_VR_AN_DIG_STS_ANR_FSM_SHIFT       (4U)
#define AN_MMD_VR_AN_DIG_STS_ANR_FSM_WIDTH       (5U)
#define AN_MMD_VR_AN_DIG_STS_ANR_FSM(x)          (((uint16_t)(((uint16_t)(x)) << AN_MMD_VR_AN_DIG_STS_ANR_FSM_SHIFT)) & AN_MMD_VR_AN_DIG_STS_ANR_FSM_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group AN_MMD_Register_Masks */

/*!
 * @}
 */ /* end of group AN_MMD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_AN_MMD_H_) */
