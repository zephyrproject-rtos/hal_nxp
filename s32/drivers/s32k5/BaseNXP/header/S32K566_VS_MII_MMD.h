/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_VS_MII_MMD.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_VS_MII_MMD
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
#if !defined(S32K566_VS_MII_MMD_H_)  /* Check if memory map has not been already included */
#define S32K566_VS_MII_MMD_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VS_MII_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MII_MMD_Peripheral_Access_Layer VS_MII_MMD Peripheral Access Layer
 * @{
 */

/** VS_MII_MMD - Register Layout Typedef */
typedef struct VS_MII_MMD_Struct {
  __IO uint16_t SR_MII_CTRL;                       /**< SR MII MMD Control Register The host can use this register to control (enable or disable) some of the features supported by the DWC_xpcs with 1G (1000BASE-X) or USXGMII support) and Clause 37 auto-negotiation support., offset: 0x0 */
  __I  uint16_t SR_MII_STS;                        /**< SR MII MMD Status Register The host uses this register to know the features supported by the DWC_xpcs in the 1000BASE-X mode., offset: 0x2 */
  __I  uint16_t SR_MII_DEV_ID1;                    /**< SR MII MMD Device Identifier Register 1 This register returns the configurable Organizationally Unique Identifier (OUI) to the host., offset: 0x4 */
  __I  uint16_t SR_MII_DEV_ID2;                    /**< SR MII MMD Device Identifier Register 2 This register returns the configurable Organizationally Unique Identifier (OUI), Model Number, and Revision Number of the device to the host., offset: 0x6 */
  __IO uint16_t SR_MII_AN_ADV;                     /**< SR MII MMD AN Advertisement Register The host uses this register to advertise the abilities and status of the local device to its link partner through Clause 37 auto-negotiation protocol., offset: 0x8 */
  __I  uint16_t SR_MII_LP_BABL;                    /**< SR_MII_LP_BABL, offset: 0xA */
  __I  uint16_t SR_MII_AN_EXPN;                    /**< SR MII MMD AN Expansion Register, offset: 0xC */
  uint8_t RESERVED_0[16];
  __I  uint16_t SR_MII_EXT_STS;                    /**< SR MII MMD Extended Status Register This register is present only for configurations with 1G/KX support., offset: 0x1E */
  uint8_t RESERVED_1[65504];
  __IO uint16_t VR_MII_DIG_CTRL1;                  /**< VR MII MMD Digital Control1 Register, offset: 0x10000 */
  __IO uint16_t VR_MII_AN_CTRL;                    /**< VR MII MMD AN Control Register, offset: 0x10002 */
  __IO uint16_t VR_MII_AN_INTR_STS;                /**< VR MII MMD AN Interrupt and Status Register, offset: 0x10004 */
  uint8_t RESERVED_2[14];
  __IO uint16_t VR_MII_LINK_TIMER_CTRL;            /**< VR MII MMD Link Timer Control Register, offset: 0x10014 */
} VS_MII_MMD_Type, *VS_MII_MMD_MemMapPtr;

/** Number of instances of the VS_MII_MMD module. */
#define VS_MII_MMD_INSTANCE_COUNT                (1u)

/* VS_MII_MMD - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD_BASE (0xBE0000u)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD ((VS_MII_MMD_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD_BASE)
/** Array initializer of VS_MII_MMD peripheral base addresses */
#define IP_VS_MII_MMD_BASE_ADDRS                 { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD_BASE }
/** Array initializer of VS_MII_MMD peripheral base pointers */
#define IP_VS_MII_MMD_BASE_PTRS                  { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MII_MMD }

/* ----------------------------------------------------------------------------
   -- VS_MII_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MII_MMD_Register_Masks VS_MII_MMD Register Masks
 * @{
 */

/*! @name SR_MII_CTRL - SR MII MMD Control Register The host can use this register to control (enable or disable) some of the features supported by the DWC_xpcs with 1G (1000BASE-X) or USXGMII support) and Clause 37 auto-negotiation support. */
/*! @{ */

#define VS_MII_MMD_SR_MII_CTRL_SS6_MASK          (0x40U)
#define VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT         (6U)
#define VS_MII_MMD_SR_MII_CTRL_SS6_WIDTH         (1U)
#define VS_MII_MMD_SR_MII_CTRL_SS6(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_SS6_MASK)

#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK  (0x100U)
#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT (8U)
#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_WIDTH (1U)
#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK   (0x200U)
#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT  (9U)
#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN_WIDTH  (1U)
#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK)

#define VS_MII_MMD_SR_MII_CTRL_LPM_MASK          (0x800U)
#define VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT         (11U)
#define VS_MII_MMD_SR_MII_CTRL_LPM_WIDTH         (1U)
#define VS_MII_MMD_SR_MII_CTRL_LPM(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_LPM_MASK)

#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK    (0x1000U)
#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT   (12U)
#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_WIDTH   (1U)
#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_SS13_MASK         (0x2000U)
#define VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT        (13U)
#define VS_MII_MMD_SR_MII_CTRL_SS13_WIDTH        (1U)
#define VS_MII_MMD_SR_MII_CTRL_SS13(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_SS13_MASK)

#define VS_MII_MMD_SR_MII_CTRL_LBE_MASK          (0x4000U)
#define VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT         (14U)
#define VS_MII_MMD_SR_MII_CTRL_LBE_WIDTH         (1U)
#define VS_MII_MMD_SR_MII_CTRL_LBE(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_LBE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_RST_MASK          (0x8000U)
#define VS_MII_MMD_SR_MII_CTRL_RST_SHIFT         (15U)
#define VS_MII_MMD_SR_MII_CTRL_RST_WIDTH         (1U)
#define VS_MII_MMD_SR_MII_CTRL_RST(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_RST_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_RST_MASK)
/*! @} */

/*! @name SR_MII_STS - SR MII MMD Status Register The host uses this register to know the features supported by the DWC_xpcs in the 1000BASE-X mode. */
/*! @{ */

#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK   (0x1U)
#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT  (0U)
#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_WIDTH  (1U)
#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT)) & VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK)

#define VS_MII_MMD_SR_MII_STS_LINK_STS_MASK      (0x4U)
#define VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT     (2U)
#define VS_MII_MMD_SR_MII_STS_LINK_STS_WIDTH     (1U)
#define VS_MII_MMD_SR_MII_STS_LINK_STS(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT)) & VS_MII_MMD_SR_MII_STS_LINK_STS_MASK)

#define VS_MII_MMD_SR_MII_STS_AN_ABL_MASK        (0x8U)
#define VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT       (3U)
#define VS_MII_MMD_SR_MII_STS_AN_ABL_WIDTH       (1U)
#define VS_MII_MMD_SR_MII_STS_AN_ABL(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_AN_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_RF_MASK            (0x10U)
#define VS_MII_MMD_SR_MII_STS_RF_SHIFT           (4U)
#define VS_MII_MMD_SR_MII_STS_RF_WIDTH           (1U)
#define VS_MII_MMD_SR_MII_STS_RF(x)              (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_RF_SHIFT)) & VS_MII_MMD_SR_MII_STS_RF_MASK)

#define VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK       (0x20U)
#define VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT      (5U)
#define VS_MII_MMD_SR_MII_STS_AN_CMPL_WIDTH      (1U)
#define VS_MII_MMD_SR_MII_STS_AN_CMPL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT)) & VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK)

#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK    (0x40U)
#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT   (6U)
#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_WIDTH   (1U)
#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT)) & VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK)

#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK    (0x80U)
#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT   (7U)
#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_WIDTH   (1U)
#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK   (0x100U)
#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT  (8U)
#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_WIDTH  (1U)
#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_HD100T_MASK        (0x200U)
#define VS_MII_MMD_SR_MII_STS_HD100T_SHIFT       (9U)
#define VS_MII_MMD_SR_MII_STS_HD100T_WIDTH       (1U)
#define VS_MII_MMD_SR_MII_STS_HD100T(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD100T_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD100T_MASK)

#define VS_MII_MMD_SR_MII_STS_FD100T_MASK        (0x400U)
#define VS_MII_MMD_SR_MII_STS_FD100T_SHIFT       (10U)
#define VS_MII_MMD_SR_MII_STS_FD100T_WIDTH       (1U)
#define VS_MII_MMD_SR_MII_STS_FD100T(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD100T_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD100T_MASK)

#define VS_MII_MMD_SR_MII_STS_HD10ABL_MASK       (0x800U)
#define VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT      (11U)
#define VS_MII_MMD_SR_MII_STS_HD10ABL_WIDTH      (1U)
#define VS_MII_MMD_SR_MII_STS_HD10ABL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD10ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_FD10ABL_MASK       (0x1000U)
#define VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT      (12U)
#define VS_MII_MMD_SR_MII_STS_FD10ABL_WIDTH      (1U)
#define VS_MII_MMD_SR_MII_STS_FD10ABL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD10ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_HD100ABL_MASK      (0x2000U)
#define VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT     (13U)
#define VS_MII_MMD_SR_MII_STS_HD100ABL_WIDTH     (1U)
#define VS_MII_MMD_SR_MII_STS_HD100ABL(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD100ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_FD100ABL_MASK      (0x4000U)
#define VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT     (14U)
#define VS_MII_MMD_SR_MII_STS_FD100ABL_WIDTH     (1U)
#define VS_MII_MMD_SR_MII_STS_FD100ABL(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD100ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_ABL100T4_MASK      (0x8000U)
#define VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT     (15U)
#define VS_MII_MMD_SR_MII_STS_ABL100T4_WIDTH     (1U)
#define VS_MII_MMD_SR_MII_STS_ABL100T4(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT)) & VS_MII_MMD_SR_MII_STS_ABL100T4_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID1 - SR MII MMD Device Identifier Register 1 This register returns the configurable Organizationally Unique Identifier (OUI) to the host. */
/*! @{ */

#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT (0U)
#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_WIDTH (16U)
#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID2 - SR MII MMD Device Identifier Register 2 This register returns the configurable Organizationally Unique Identifier (OUI), Model Number, and Revision Number of the device to the host. */
/*! @{ */

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK (0xFU)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT (0U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_WIDTH (4U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK)

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK (0x3F0U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT (4U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_WIDTH (6U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK)

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK (0xFC00U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT (10U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_WIDTH (6U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_MII_AN_ADV - SR MII MMD AN Advertisement Register The host uses this register to advertise the abilities and status of the local device to its link partner through Clause 37 auto-negotiation protocol. */
/*! @{ */

#define VS_MII_MMD_SR_MII_AN_ADV_FD_MASK         (0x20U)
#define VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT        (5U)
#define VS_MII_MMD_SR_MII_AN_ADV_FD_WIDTH        (1U)
#define VS_MII_MMD_SR_MII_AN_ADV_FD(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_FD_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_HD_MASK         (0x40U)
#define VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT        (6U)
#define VS_MII_MMD_SR_MII_AN_ADV_HD_WIDTH        (1U)
#define VS_MII_MMD_SR_MII_AN_ADV_HD(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_HD_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK      (0x180U)
#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT     (7U)
#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE_WIDTH     (2U)
#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_RF_MASK         (0x3000U)
#define VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT        (12U)
#define VS_MII_MMD_SR_MII_AN_ADV_RF_WIDTH        (2U)
#define VS_MII_MMD_SR_MII_AN_ADV_RF(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_RF_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_NP_MASK         (0x8000U)
#define VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT        (15U)
#define VS_MII_MMD_SR_MII_AN_ADV_NP_WIDTH        (1U)
#define VS_MII_MMD_SR_MII_AN_ADV_NP(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_NP_MASK)
/*! @} */

/*! @name SR_MII_LP_BABL - SR_MII_LP_BABL */
/*! @{ */

#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK     (0x20U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT    (5U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD_WIDTH    (1U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK     (0x40U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT    (6U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD_WIDTH    (1U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK  (0x180U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT (7U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_WIDTH (2U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK     (0x3000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT    (12U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF_WIDTH    (2U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK    (0x4000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT   (14U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_WIDTH   (1U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK     (0x8000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT    (15U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP_WIDTH    (1U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK)
/*! @} */

/*! @name SR_MII_AN_EXPN - SR MII MMD AN Expansion Register */
/*! @{ */

#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK   (0x2U)
#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT  (1U)
#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_WIDTH  (1U)
#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT)) & VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK)

#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK (0x4U)
#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT (2U)
#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_WIDTH (1U)
#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT)) & VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK)
/*! @} */

/*! @name SR_MII_EXT_STS - SR MII MMD Extended Status Register This register is present only for configurations with 1G/KX support. */
/*! @{ */

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK (0x1000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT (12U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_WIDTH (1U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK (0x2000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT (13U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_WIDTH (1U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK (0x4000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT (14U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_WIDTH (1U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK (0x8000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT (15U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_WIDTH (1U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK)
/*! @} */

/*! @name VR_MII_DIG_CTRL1 - VR MII MMD Digital Control1 Register */
/*! @{ */

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK (0x1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT (0U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_MASK (0x4U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_SHIFT (2U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK (0x8U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT (3U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK (0x40U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT (6U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_MASK (0x80U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_SHIFT (7U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK (0x200U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT (9U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK   (0x800U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT  (11U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_WIDTH  (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_SHIFT (12U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK (0x2000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT (13U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK  (0x4000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT (14U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK  (0x8000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT (15U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_WIDTH (1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_MII_AN_CTRL - VR MII MMD AN Control Register */
/*! @{ */

#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT (0U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK  (0x6U)
#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_WIDTH (2U)
#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK (0x8U)
#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT (3U)
#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK (0x10U)
#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT (4U)
#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK  (0x100U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT (8U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK (0x200U)
#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT (9U)
#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK)
/*! @} */

/*! @name VR_MII_AN_INTR_STS - VR MII MMD AN Interrupt and Status Register */
/*! @{ */

#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK (0x1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT (0U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK (0x1EU)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT (1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_WIDTH (4U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_MASK (0x20U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_SHIFT (5U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_MASK (0x40U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_SHIFT (6U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_WIDTH (1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_MASK)
/*! @} */

/*! @name VR_MII_LINK_TIMER_CTRL - VR MII MMD Link Timer Control Register */
/*! @{ */

#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT (0U)
#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_WIDTH (16U)
#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT)) & VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VS_MII_MMD_Register_Masks */

/*!
 * @}
 */ /* end of group VS_MII_MMD_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_VS_MII_MMD_H_) */
