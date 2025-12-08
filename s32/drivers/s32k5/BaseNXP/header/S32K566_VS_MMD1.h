/*
 * Copyright 1997-2016 Freescale Semiconductor, Inc.
 * Copyright 2016-2025 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*!
 * @file S32K566_VS_MMD1.h
 * @version 2.2
 * @date 2025-10-16
 * @brief Peripheral Access Layer for S32K566_VS_MMD1
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
#if !defined(S32K566_VS_MMD1_H_)  /* Check if memory map has not been already included */
#define S32K566_VS_MMD1_H_

#include "S32K566_COMMON.h"

/* ----------------------------------------------------------------------------
   -- VS_MMD1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MMD1_Peripheral_Access_Layer VS_MMD1 Peripheral Access Layer
 * @{
 */

/** VS_MMD1 - Register Layout Typedef */
typedef struct VS_MMD1_Struct {
  __IO uint16_t SR_VSMMD_PMA_ID1;                  /**< SR Control MMD PMA Device Identifier Register 1, offset: 0x0 */
  __IO uint16_t SR_VSMMD_PMA_ID2;                  /**< SR Control MMD PMA Device Identifier Register 2, offset: 0x2 */
  __IO uint16_t SR_VSMMD_DEV_ID1;                  /**< SR Control MMD Device Identifier Register 1, offset: 0x4 */
  __IO uint16_t SR_VSMMD_DEV_ID2;                  /**< SR Control MMD Device Identifier Register 2, offset: 0x6 */
  __IO uint16_t SR_VSMMD_PCS_ID1;                  /**< SR Control MMD PCS Device Identifier Register 1, offset: 0x8 */
  __IO uint16_t SR_VSMMD_PCS_ID2;                  /**< SR Control MMD PCS Device Identifier Register 2, offset: 0xA */
  __IO uint16_t SR_VSMMD_AN_ID1;                   /**< SR Control MMD AN Device Identifier Register 1, offset: 0xC */
  __IO uint16_t SR_VSMMD_AN_ID2;                   /**< SR Control MMD AN Device Identifier Register 2, offset: 0xE */
  __I  uint16_t SR_VSMMD_STS;                      /**< SR Control MMD Status Register, offset: 0x10 */
  __IO uint16_t SR_VSMMD_CTRL;                     /**< SR Control MMD Control Register, offset: 0x12 */
  uint8_t RESERVED_0[8];
  __IO uint16_t SR_VSMMD_PKGID1;                   /**< SR Control MMD Package Identifier Register 1, offset: 0x1C */
  __IO uint16_t SR_VSMMD_PKGID2;                   /**< SR Control MMD Package Identifier Register 2 Note: The values written in the fields of this register are reflected in the corresponding fields of the following registers: - SR_PMA_PKG2 Register - SR_XS_PCS_PKG2 Register - SR_AN_PKG2 Register, offset: 0x1E */
} VS_MMD1_Type, *VS_MMD1_MemMapPtr;

/** Number of instances of the VS_MMD1 module. */
#define VS_MMD1_INSTANCE_COUNT                   (1u)

/* VS_MMD1 - Peripheral instance base addresses */
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1 base address */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1_BASE (0xBC0000u)
/** Peripheral NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1 base pointer */
#define IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1 ((VS_MMD1_Type *)IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1_BASE)
/** Array initializer of VS_MMD1 peripheral base addresses */
#define IP_VS_MMD1_BASE_ADDRS                    { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1_BASE }
/** Array initializer of VS_MMD1 peripheral base pointers */
#define IP_VS_MMD1_BASE_PTRS                     { IP_NETC_ENET_PHY_PHY_CTRL_EX_LOCK__XPCS__VS_MMD1 }

/* ----------------------------------------------------------------------------
   -- VS_MMD1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MMD1_Register_Masks VS_MMD1 Register Masks
 * @{
 */

/*! @name SR_VSMMD_PMA_ID1 - SR Control MMD PMA Device Identifier Register 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_WIDTH (16U)
#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PMA_ID2 - SR Control MMD PMA Device Identifier Register 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK (0xFU)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_WIDTH (4U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT (4U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT (10U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID1 - SR Control MMD Device Identifier Register 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_WIDTH (16U)
#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID2 - SR Control MMD Device Identifier Register 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK  (0xFU)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_WIDTH (4U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT (4U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT (10U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID1 - SR Control MMD PCS Device Identifier Register 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_WIDTH (16U)
#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID2 - SR Control MMD PCS Device Identifier Register 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK (0xFU)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_WIDTH (4U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT (4U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT (10U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_AN_ID1 - SR Control MMD AN Device Identifier Register 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_WIDTH (16U)
#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_AN_ID2 - SR Control MMD AN Device Identifier Register 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_MASK   (0xFU)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_SHIFT  (0U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_WIDTH  (4U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0(x)     (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_MASK  (0x3F0U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_SHIFT (4U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_SHIFT (10U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_STS - SR Control MMD Status Register */
/*! @{ */

#define VS_MMD1_SR_VSMMD_STS_VSDP_MASK           (0xC000U)
#define VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT          (14U)
#define VS_MMD1_SR_VSMMD_STS_VSDP_WIDTH          (2U)
#define VS_MMD1_SR_VSMMD_STS_VSDP(x)             (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT)) & VS_MMD1_SR_VSMMD_STS_VSDP_MASK)
/*! @} */

/*! @name SR_VSMMD_CTRL - SR Control MMD Control Register */
/*! @{ */

#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_MASK     (0x1U)
#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_SHIFT    (0U)
#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_WIDTH    (1U)
#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN(x)       (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK (0x2U)
#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT (1U)
#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_WIDTH (1U)
#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK    (0x4U)
#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT   (2U)
#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_WIDTH   (1U)
#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN(x)      (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK    (0x8U)
#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT   (3U)
#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_WIDTH   (1U)
#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN(x)      (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK       (0x10U)
#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT      (4U)
#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM_WIDTH      (1U)
#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM(x)         (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID1 - SR Control MMD Package Identifier Register 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_WIDTH (16U)
#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID2 - SR Control MMD Package Identifier Register 2 Note: The values written in the fields of this register are reflected in the corresponding fields of the following registers: - SR_PMA_PKG2 Register - SR_XS_PCS_PKG2 Register - SR_AN_PKG2 Register */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK  (0xFU)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT (0U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_WIDTH (4U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT (4U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT (10U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_WIDTH (6U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK)
/*! @} */

/*!
 * @}
 */ /* end of group VS_MMD1_Register_Masks */

/*!
 * @}
 */ /* end of group VS_MMD1_Peripheral_Access_Layer */

#endif  /* #if !defined(S32K566_VS_MMD1_H_) */
