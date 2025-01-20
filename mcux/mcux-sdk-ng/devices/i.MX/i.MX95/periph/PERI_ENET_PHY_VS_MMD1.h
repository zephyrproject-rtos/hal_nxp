/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ENET_PHY_VS_MMD1
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file ENET_PHY_VS_MMD1.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_VS_MMD1
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_VS_MMD1
 */

#if !defined(ENET_PHY_VS_MMD1_H_)
#define ENET_PHY_VS_MMD1_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- ENET_PHY_VS_MMD1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_VS_MMD1_Peripheral_Access_Layer ENET_PHY_VS_MMD1 Peripheral Access Layer
 * @{
 */

/** ENET_PHY_VS_MMD1 - Register Layout Typedef */
typedef struct {
  __I  uint16_t SR_VSMMD_PMA_ID1;                  /**< SR Control MMD PMA Device Identifier 1, offset: 0x0 */
  __I  uint16_t SR_VSMMD_PMA_ID2;                  /**< SR Control MMD PMA Device Identifier 2, offset: 0x2 */
  __I  uint16_t SR_VSMMD_DEV_ID1;                  /**< SR Control MMD Device Identifier 1, offset: 0x4 */
  __I  uint16_t SR_VSMMD_DEV_ID2;                  /**< SR Control MMD Device Identifier 2, offset: 0x6 */
  __I  uint16_t SR_VSMMD_PCS_ID1;                  /**< SR Control MMD PCS Device Identifier 1, offset: 0x8 */
  __I  uint16_t SR_VSMMD_PCS_ID2;                  /**< SR Control MMD PCS Device Identifier 2, offset: 0xA */
       uint16_t SR_VSMMD_AN_ID1;                   /**< SR Control MMD AN Device Identifier 1, offset: 0xC */
       uint16_t SR_VSMMD_AN_ID2;                   /**< SR Control MMD AN Device Identifier 2, offset: 0xE */
  __I  uint16_t SR_VSMMD_STS;                      /**< SR Control MMD Status, offset: 0x10 */
  __IO uint16_t SR_VSMMD_CTRL;                     /**< SR Control MMD Control, offset: 0x12 */
       uint8_t RESERVED_0[8];
  __I  uint16_t SR_VSMMD_PKGID1;                   /**< SR Control MMD Package Identifier 1, offset: 0x1C */
  __I  uint16_t SR_VSMMD_PKGID2;                   /**< SR Control MMD Package Identifier 2, offset: 0x1E */
} ENET_PHY_VS_MMD1_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_VS_MMD1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_VS_MMD1_Register_Masks ENET_PHY_VS_MMD1 Register Masks
 * @{
 */

/*! @name SR_VSMMD_PMA_ID1 - SR Control MMD PMA Device Identifier 1 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT (0U)
/*! PMADOUI_3_18 - Organizationally Unique Identifier [3:18] for PMA MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID1_PMADOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PMA_ID2 - SR Control MMD PMA Device Identifier 2 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK (0xFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT (0U)
/*! PMADRN_3_0 - Revision Number for PMA MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADRN_3_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK (0x3F0U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT (4U)
/*! PMADMMN_5_0 - Model Number for PMA MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADMMN_5_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK (0xFC00U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT (10U)
/*! PMADOUI_19_24 - Organizationally Unique Identifier [19:24] for PMA MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PMA_ID2_PMADOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID1 - SR Control MMD Device Identifier 1 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT (0U)
/*! VSDOUI_3_18 - Organizationally Unique Identifier [3:18] for Vendor-Specific MMD1 */
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID1_VSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_DEV_ID2 - SR Control MMD Device Identifier 2 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK (0xFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT (0U)
/*! VSDRN_3_0 - Revision Number for Vendor-Specific MMD1 */
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDRN_3_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK (0x3F0U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT (4U)
/*! VSDMMN_5_0 - Model Number for Vendor-Specific MMD1 */
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDMMN_5_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK (0xFC00U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT (10U)
/*! VSDOUI_19_24 - Organizationally Unique Identifier [19:24] for Vendor-Specific MMD1 */
#define ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_DEV_ID2_VSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID1 - SR Control MMD PCS Device Identifier 1 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT (0U)
/*! PCSDOUI_3_18 - Organizationally Unique Identifier [3:18] for PCS MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID1_PCSDOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PCS_ID2 - SR Control MMD PCS Device Identifier 2 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK (0xFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT (0U)
/*! PCSDRN_3_0 - Revision Number for XS or PCS MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDRN_3_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK (0x3F0U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT (4U)
/*! PCSDMMN_5_0 - Model Number for XS or PCS MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDMMN_5_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK (0xFC00U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT (10U)
/*! PCSDOUI_19_24 - Organizationally Unique Identifier[19:24] for PCS MMD */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PCS_ID2_PCSDOUI_19_24_MASK)
/*! @} */

/*! @name SR_VSMMD_STS - SR Control MMD Status */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_STS_VSDP_MASK  (0xC000U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT (14U)
/*! VSDP - Control MMD Device Present
 *  0b10..Device responding at this address
 *  0b00, 0b11, 0b11..No device responding at this address
 */
#define ENET_PHY_VS_MMD1_SR_VSMMD_STS_VSDP(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_STS_VSDP_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_STS_VSDP_MASK)
/*! @} */

/*! @name SR_VSMMD_CTRL - SR Control MMD Control */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK (0x2U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT (1U)
/*! PCS_XS_MMD_EN - PCS MMD Enable */
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PCS_XS_MMD_EN_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK (0x4U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT (2U)
/*! MII_MMD_EN - VS MMD Enable */
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_MII_MMD_EN_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK (0x8U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT (3U)
/*! PMA_MMD_EN - PMA MMD Enable */
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_PMA_MMD_EN_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK (0x10U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT (4U)
/*! FASTSIM - Fast Simulation Enable */
#define ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_FASTSIM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_FASTSIM_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_CTRL_FASTSIM_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID1 - SR Control MMD Package Identifier 1 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT (0U)
/*! MMDPOUI_3_18 - Organizationally Unique Identifier */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PKGID1_MMDPOUI_3_18_MASK)
/*! @} */

/*! @name SR_VSMMD_PKGID2 - SR Control MMD Package Identifier 2 */
/*! @{ */

#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK (0xFU)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT (0U)
/*! MMDPRN_3_0 - Revision Number */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPRN_3_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK (0x3F0U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT (4U)
/*! MMDPMMN_5_0 - Model Number */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPMMN_5_0_MASK)

#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK (0xFC00U)
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT (10U)
/*! MMDPOUI_19_24 - Organizationally Unique Identifier */
#define ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_SHIFT)) & ENET_PHY_VS_MMD1_SR_VSMMD_PKGID2_MMDPOUI_19_24_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_VS_MMD1_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_PHY_VS_MMD1_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_VS_MMD1_H_ */

