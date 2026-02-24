/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VS_MMD1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VS_MMD1.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VS_MMD1
 *
 * CMSIS Peripheral Access Layer for VS_MMD1
 */

#if !defined(PERI_VS_MMD1_H_)
#define PERI_VS_MMD1_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic push
  #else
    #pragma push
    #pragma anon_unions
  #endif
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- VS_MMD1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MMD1_Peripheral_Access_Layer VS_MMD1 Peripheral Access Layer
 * @{
 */

/** VS_MMD1 - Register Layout Typedef */
typedef struct {
  __I  uint16_t SR_VSMMD_PMA_ID1;                  /**< SR Control MMD PMA Device Identifier 1, offset: 0x0 */
  __I  uint16_t SR_VSMMD_PMA_ID2;                  /**< SR Control MMD PMA Device Identifier 2, offset: 0x2 */
  __I  uint16_t SR_VSMMD_DEV_ID1;                  /**< SR Control MMD Device Identifier 1, offset: 0x4 */
  __I  uint16_t SR_VSMMD_DEV_ID2;                  /**< SR Control MMD Device Identifier 2, offset: 0x6 */
  __I  uint16_t SR_VSMMD_PCS_ID1;                  /**< SR Control MMD PCS Device Identifier 1, offset: 0x8 */
  __I  uint16_t SR_VSMMD_PCS_ID2;                  /**< SR Control MMD PCS Device Identifier 2, offset: 0xA */
  __I  uint16_t SR_VSMMD_AN_ID1;                   /**< SR Control MMD AN Device Identifier 1, offset: 0xC */
  __I  uint16_t SR_VSMMD_AN_ID2;                   /**< SR Control MMD AN Device Identifier 2, offset: 0xE */
  __I  uint16_t SR_VSMMD_STS;                      /**< SR Control MMD Status, offset: 0x10 */
  __IO uint16_t SR_VSMMD_CTRL;                     /**< SR Control MMD Control, offset: 0x12 */
       uint8_t RESERVED_0[8];
  __I  uint16_t SR_VSMMD_PKGID1;                   /**< SR Control MMD Package Identifier 1, offset: 0x1C */
  __I  uint16_t SR_VSMMD_PKGID2;                   /**< SR Control MMD Package Identifier 2, offset: 0x1E */
} VS_MMD1_Type;

/* ----------------------------------------------------------------------------
   -- VS_MMD1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MMD1_Register_Masks VS_MMD1 Register Masks
 * @{
 */

/*! @name SR_VSMMD_PMA_ID1 - SR Control MMD PMA Device Identifier 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT (0U)
/*! PMADOUI_3_18 - Reserved */
#define VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PMA_ID2 - SR Control MMD PMA Device Identifier 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK (0xFU)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT (0U)
/*! PMADRN_3_0 - Reserved */
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT (4U)
/*! PMADMMN_5_0 - Reserved */
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT (10U)
/*! PMADOUI_19_24 - Reserved */
#define VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID1 - SR Control MMD Device Identifier 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT (0U)
/*! VSDOUI_3_18 - Organizationally Unique Identifier[3:18] For Vendor-Specific MMD1 */
#define VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID2 - SR Control MMD Device Identifier 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK  (0xFU)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT (0U)
/*! VSDRN_3_0 - Revision Number For Vendor-Specific MMD1 */
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT (4U)
/*! VSDMMN_5_0 - Model Number For Vendor-Specific MMD1 */
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT (10U)
/*! VSDOUI_19_24 - Organizationally Unique Identifier[19:24] For Vendor-Specific MMD1 */
#define VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID1 - SR Control MMD PCS Device Identifier 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT (0U)
/*! PCSDOUI_3_18 - Organizationally Unique Identifier[3:18] For PCS MMD */
#define VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID2 - SR Control MMD PCS Device Identifier 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK (0xFU)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT (0U)
/*! PCSDRN_3_0 - Revision Number For XS Or PCS MMD */
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT (4U)
/*! PCSDMMN_5_0 - Model Number For XS Or PCS MMD */
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT (10U)
/*! PCSDOUI_19_24 - Organizationally Unique Identifier[19:24] For PCS MMD */
#define VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_AN_ID1 - SR Control MMD AN Device Identifier 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_SHIFT (0U)
/*! ANDOUI_3_18 - Reserved */
#define VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID1_ANDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_AN_ID2 - SR Control MMD AN Device Identifier 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_MASK   (0xFU)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_SHIFT  (0U)
/*! ANDRN_3_0 - Reserved */
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0(x)     (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_MASK  (0x3F0U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_SHIFT (4U)
/*! ANDMMN_5_0 - Reserved */
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_SHIFT (10U)
/*! ANDOUI_19_24 - Reserved */
#define VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_AN_ID2_ANDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_STS - SR Control MMD Status */
/*! @{ */

#define VS_MMD1_SR_VSMMD_STS_VSDP_MASK           (0xC000U)
#define VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT          (14U)
/*! VSDP - Control MMD Device Present
 *  0b10..Device responding at this address
 */
#define VS_MMD1_SR_VSMMD_STS_VSDP(x)             (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT)) & VS_MMD1_SR_VSMMD_STS_VSDP_MASK)
/*! @} */

/*! @name SR_VSMMD_CTRL - SR Control MMD Control */
/*! @{ */

#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_MASK     (0x1U)
#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_SHIFT    (0U)
/*! AN_MMD_EN - Reserved */
#define VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN(x)       (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_AN_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK (0x2U)
#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT (1U)
/*! PCS_XS_MMD_EN - Reserved */
#define VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK    (0x4U)
#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT   (2U)
/*! MII_MMD_EN - VS MMD Enable */
#define VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN(x)      (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK    (0x8U)
#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT   (3U)
/*! PMA_MMD_EN - Reserved */
#define VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN(x)      (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK       (0x10U)
#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT      (4U)
/*! FASTSIM - Fast Simulation Enable */
#define VS_MMD1_SR_VSMMD_CTRL_FASTSIM(x)         (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK)

#define VS_MMD1_SR_VSMMD_CTRL_PD_CTRL_MASK       (0x20U)
#define VS_MMD1_SR_VSMMD_CTRL_PD_CTRL_SHIFT      (5U)
/*! PD_CTRL - Reserved */
#define VS_MMD1_SR_VSMMD_CTRL_PD_CTRL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_CTRL_PD_CTRL_SHIFT)) & VS_MMD1_SR_VSMMD_CTRL_PD_CTRL_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID1 - SR Control MMD Package Identifier 1 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK (0xFFFFU)
#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT (0U)
/*! MMDPOUI_3_18 - Reserved */
#define VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18(x)  (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID2 - SR Control MMD Package Identifier 2 */
/*! @{ */

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK  (0xFU)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT (0U)
/*! MMDPRN_3_0 - Reserved */
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0(x)    (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK)

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK (0x3F0U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT (4U)
/*! MMDPMMN_5_0 - Reserved */
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK)

#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK (0xFC00U)
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT (10U)
/*! MMDPOUI_19_24 - Reserved */
#define VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT)) & VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VS_MMD1_Register_Masks */


/*!
 * @}
 */ /* end of group VS_MMD1_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #if (__ARMCC_VERSION >= 6010050)
    #pragma clang diagnostic pop
  #else
    #pragma pop
  #endif
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_VS_MMD1_H_ */

