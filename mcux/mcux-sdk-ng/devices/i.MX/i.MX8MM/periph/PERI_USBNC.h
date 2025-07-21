/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBNC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBNC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- USBNC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Peripheral_Access_Layer USBNC Peripheral Access Layer
 * @{
 */

/** USBNC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[512];
  __IO uint32_t OTG1_CTRL1;                        /**< USB OTG Control 1 Register, offset: 0x200 */
  __IO uint32_t OTG1_CTRL2;                        /**< USB OTG Control 2 Register, offset: 0x204 */
       uint8_t RESERVED_1[1528];
  __IO uint32_t USB_OTG1_CTRL;                     /**< USB OTG1 Control Register, offset: 0x800 */
  __IO uint32_t USB_OTG2_CTRL;                     /**< USB OTG2 Control Register, offset: 0x804 */
       uint8_t RESERVED_2[16];
  __IO uint32_t USB_OTG1_PHY_CTRL_0;               /**< OTG1 UTMI PHY Control 0 Register, offset: 0x818 */
  __IO uint32_t USB_OTG2_PHY_CTRL_0;               /**< OTG2 UTMI PHY Control 0 Register, offset: 0x81C */
       uint8_t RESERVED_3[63968];
  __IO uint32_t OTG2_CTRL1;                        /**< USB OTG Control 1 Register, offset: 0x10200 */
  __IO uint32_t OTG2_CTRL2;                        /**< USB OTG Control 2 Register, offset: 0x10204 */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name OTG1_CTRL1 - USB OTG Control 1 Register */
/*! @{ */

#define USBNC_OTG1_CTRL1_OVER_CUR_DIS_MASK       (0x80U)
#define USBNC_OTG1_CTRL1_OVER_CUR_DIS_SHIFT      (7U)
/*! OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_OTG1_CTRL1_OVER_CUR_DIS(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_OTG1_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_OTG1_CTRL1_OVER_CUR_POL_MASK       (0x100U)
#define USBNC_OTG1_CTRL1_OVER_CUR_POL_SHIFT      (8U)
/*! OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_OTG1_CTRL1_OVER_CUR_POL(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_OTG1_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_OTG1_CTRL1_PWR_POL_MASK            (0x200U)
#define USBNC_OTG1_CTRL1_PWR_POL_SHIFT           (9U)
/*! PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_OTG1_CTRL1_PWR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_PWR_POL_SHIFT)) & USBNC_OTG1_CTRL1_PWR_POL_MASK)

#define USBNC_OTG1_CTRL1_WIE_MASK                (0x400U)
#define USBNC_OTG1_CTRL1_WIE_SHIFT               (10U)
/*! WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_OTG1_CTRL1_WIE(x)                  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WIE_SHIFT)) & USBNC_OTG1_CTRL1_WIE_MASK)

#define USBNC_OTG1_CTRL1_WKUP_SW_EN_MASK         (0x4000U)
#define USBNC_OTG1_CTRL1_WKUP_SW_EN_SHIFT        (14U)
/*! WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG1_CTRL1_WKUP_SW_EN(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_OTG1_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_OTG1_CTRL1_WKUP_SW_MASK            (0x8000U)
#define USBNC_OTG1_CTRL1_WKUP_SW_SHIFT           (15U)
/*! WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_OTG1_CTRL1_WKUP_SW(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WKUP_SW_SHIFT)) & USBNC_OTG1_CTRL1_WKUP_SW_MASK)

#define USBNC_OTG1_CTRL1_WKUP_ID_EN_MASK         (0x10000U)
#define USBNC_OTG1_CTRL1_WKUP_ID_EN_SHIFT        (16U)
/*! WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG1_CTRL1_WKUP_ID_EN(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_OTG1_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_OTG1_CTRL1_WKUP_VBUS_EN_MASK       (0x20000U)
#define USBNC_OTG1_CTRL1_WKUP_VBUS_EN_SHIFT      (17U)
/*! WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG1_CTRL1_WKUP_VBUS_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_OTG1_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_OTG1_CTRL1_ULPI_PHY_CLK_EN_MASK    (0x100000U)
#define USBNC_OTG1_CTRL1_ULPI_PHY_CLK_EN_SHIFT   (20U)
/*! ULPI_PHY_CLK_EN - ULPI PHY clock enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG1_CTRL1_ULPI_PHY_CLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_ULPI_PHY_CLK_EN_SHIFT)) & USBNC_OTG1_CTRL1_ULPI_PHY_CLK_EN_MASK)

#define USBNC_OTG1_CTRL1_WKUP_DPDM_EN_MASK       (0x20000000U)
#define USBNC_OTG1_CTRL1_WKUP_DPDM_EN_SHIFT      (29U)
/*! WKUP_DPDM_EN - Wake-up on DPDM change enable
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_OTG1_CTRL1_WKUP_DPDM_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_OTG1_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_OTG1_CTRL1_WIR_MASK                (0x80000000U)
#define USBNC_OTG1_CTRL1_WIR_SHIFT               (31U)
/*! WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_OTG1_CTRL1_WIR(x)                  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL1_WIR_SHIFT)) & USBNC_OTG1_CTRL1_WIR_MASK)
/*! @} */

/*! @name OTG1_CTRL2 - USB OTG Control 2 Register */
/*! @{ */

#define USBNC_OTG1_CTRL2_VBUS_SOURCE_SEL_MASK    (0x3U)
#define USBNC_OTG1_CTRL2_VBUS_SOURCE_SEL_SHIFT   (0U)
#define USBNC_OTG1_CTRL2_VBUS_SOURCE_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_OTG1_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_OTG1_CTRL2_AUTURESUME_EN_MASK      (0x4U)
#define USBNC_OTG1_CTRL2_AUTURESUME_EN_SHIFT     (2U)
/*! AUTURESUME_EN - Auto Resume Enable
 *  0b0..Default
 */
#define USBNC_OTG1_CTRL2_AUTURESUME_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_AUTURESUME_EN_SHIFT)) & USBNC_OTG1_CTRL2_AUTURESUME_EN_MASK)

#define USBNC_OTG1_CTRL2_LOWSPEED_EN_MASK        (0x8U)
#define USBNC_OTG1_CTRL2_LOWSPEED_EN_SHIFT       (3U)
/*! LOWSPEED_EN
 *  0b0..Default
 */
#define USBNC_OTG1_CTRL2_LOWSPEED_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_LOWSPEED_EN_SHIFT)) & USBNC_OTG1_CTRL2_LOWSPEED_EN_MASK)

#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD_MASK       (0x80000000U)
#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD_SHIFT      (31U)
/*! UTMI_CLK_VLD
 *  0b0..Default
 */
#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_OTG1_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name USB_OTG1_CTRL - USB OTG1 Control Register */
/*! @{ */

#define USBNC_USB_OTG1_CTRL_OVER_CUR_DIS_MASK    (0x80U)
#define USBNC_USB_OTG1_CTRL_OVER_CUR_DIS_SHIFT   (7U)
/*! OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_USB_OTG1_CTRL_OVER_CUR_DIS(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_OVER_CUR_DIS_SHIFT)) & USBNC_USB_OTG1_CTRL_OVER_CUR_DIS_MASK)

#define USBNC_USB_OTG1_CTRL_OVER_CUR_POL_MASK    (0x100U)
#define USBNC_USB_OTG1_CTRL_OVER_CUR_POL_SHIFT   (8U)
/*! OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_USB_OTG1_CTRL_OVER_CUR_POL(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_OVER_CUR_POL_SHIFT)) & USBNC_USB_OTG1_CTRL_OVER_CUR_POL_MASK)

#define USBNC_USB_OTG1_CTRL_PWR_POL_MASK         (0x200U)
#define USBNC_USB_OTG1_CTRL_PWR_POL_SHIFT        (9U)
/*! PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_USB_OTG1_CTRL_PWR_POL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_PWR_POL_SHIFT)) & USBNC_USB_OTG1_CTRL_PWR_POL_MASK)

#define USBNC_USB_OTG1_CTRL_WIE_MASK             (0x400U)
#define USBNC_USB_OTG1_CTRL_WIE_SHIFT            (10U)
/*! WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_USB_OTG1_CTRL_WIE(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WIE_SHIFT)) & USBNC_USB_OTG1_CTRL_WIE_MASK)

#define USBNC_USB_OTG1_CTRL_WKUP_SW_EN_MASK      (0x4000U)
#define USBNC_USB_OTG1_CTRL_WKUP_SW_EN_SHIFT     (14U)
/*! WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG1_CTRL_WKUP_SW_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WKUP_SW_EN_SHIFT)) & USBNC_USB_OTG1_CTRL_WKUP_SW_EN_MASK)

#define USBNC_USB_OTG1_CTRL_WKUP_SW_MASK         (0x8000U)
#define USBNC_USB_OTG1_CTRL_WKUP_SW_SHIFT        (15U)
/*! WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_USB_OTG1_CTRL_WKUP_SW(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WKUP_SW_SHIFT)) & USBNC_USB_OTG1_CTRL_WKUP_SW_MASK)

#define USBNC_USB_OTG1_CTRL_WKUP_ID_EN_MASK      (0x10000U)
#define USBNC_USB_OTG1_CTRL_WKUP_ID_EN_SHIFT     (16U)
/*! WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG1_CTRL_WKUP_ID_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WKUP_ID_EN_SHIFT)) & USBNC_USB_OTG1_CTRL_WKUP_ID_EN_MASK)

#define USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN_MASK    (0x20000U)
#define USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN_SHIFT   (17U)
/*! WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN_SHIFT)) & USBNC_USB_OTG1_CTRL_WKUP_VBUS_EN_MASK)

#define USBNC_USB_OTG1_CTRL_WKUP_DPDM_EN_MASK    (0x20000000U)
#define USBNC_USB_OTG1_CTRL_WKUP_DPDM_EN_SHIFT   (29U)
/*! WKUP_DPDM_EN
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_USB_OTG1_CTRL_WKUP_DPDM_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WKUP_DPDM_EN_SHIFT)) & USBNC_USB_OTG1_CTRL_WKUP_DPDM_EN_MASK)

#define USBNC_USB_OTG1_CTRL_WIR_MASK             (0x80000000U)
#define USBNC_USB_OTG1_CTRL_WIR_SHIFT            (31U)
/*! WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_USB_OTG1_CTRL_WIR(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_CTRL_WIR_SHIFT)) & USBNC_USB_OTG1_CTRL_WIR_MASK)
/*! @} */

/*! @name USB_OTG2_CTRL - USB OTG2 Control Register */
/*! @{ */

#define USBNC_USB_OTG2_CTRL_OVER_CUR_DIS_MASK    (0x80U)
#define USBNC_USB_OTG2_CTRL_OVER_CUR_DIS_SHIFT   (7U)
/*! OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_USB_OTG2_CTRL_OVER_CUR_DIS(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_OVER_CUR_DIS_SHIFT)) & USBNC_USB_OTG2_CTRL_OVER_CUR_DIS_MASK)

#define USBNC_USB_OTG2_CTRL_OVER_CUR_POL_MASK    (0x100U)
#define USBNC_USB_OTG2_CTRL_OVER_CUR_POL_SHIFT   (8U)
/*! OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_USB_OTG2_CTRL_OVER_CUR_POL(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_OVER_CUR_POL_SHIFT)) & USBNC_USB_OTG2_CTRL_OVER_CUR_POL_MASK)

#define USBNC_USB_OTG2_CTRL_PWR_POL_MASK         (0x200U)
#define USBNC_USB_OTG2_CTRL_PWR_POL_SHIFT        (9U)
/*! PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_USB_OTG2_CTRL_PWR_POL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_PWR_POL_SHIFT)) & USBNC_USB_OTG2_CTRL_PWR_POL_MASK)

#define USBNC_USB_OTG2_CTRL_WIE_MASK             (0x400U)
#define USBNC_USB_OTG2_CTRL_WIE_SHIFT            (10U)
/*! WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_USB_OTG2_CTRL_WIE(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WIE_SHIFT)) & USBNC_USB_OTG2_CTRL_WIE_MASK)

#define USBNC_USB_OTG2_CTRL_WKUP_SW_EN_MASK      (0x4000U)
#define USBNC_USB_OTG2_CTRL_WKUP_SW_EN_SHIFT     (14U)
/*! WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG2_CTRL_WKUP_SW_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WKUP_SW_EN_SHIFT)) & USBNC_USB_OTG2_CTRL_WKUP_SW_EN_MASK)

#define USBNC_USB_OTG2_CTRL_WKUP_SW_MASK         (0x8000U)
#define USBNC_USB_OTG2_CTRL_WKUP_SW_SHIFT        (15U)
/*! WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_USB_OTG2_CTRL_WKUP_SW(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WKUP_SW_SHIFT)) & USBNC_USB_OTG2_CTRL_WKUP_SW_MASK)

#define USBNC_USB_OTG2_CTRL_WKUP_ID_EN_MASK      (0x10000U)
#define USBNC_USB_OTG2_CTRL_WKUP_ID_EN_SHIFT     (16U)
/*! WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG2_CTRL_WKUP_ID_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WKUP_ID_EN_SHIFT)) & USBNC_USB_OTG2_CTRL_WKUP_ID_EN_MASK)

#define USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN_MASK    (0x20000U)
#define USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN_SHIFT   (17U)
/*! WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN_SHIFT)) & USBNC_USB_OTG2_CTRL_WKUP_VBUS_EN_MASK)

#define USBNC_USB_OTG2_CTRL_WKUP_DPDM_EN_MASK    (0x20000000U)
#define USBNC_USB_OTG2_CTRL_WKUP_DPDM_EN_SHIFT   (29U)
/*! WKUP_DPDM_EN
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_USB_OTG2_CTRL_WKUP_DPDM_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WKUP_DPDM_EN_SHIFT)) & USBNC_USB_OTG2_CTRL_WKUP_DPDM_EN_MASK)

#define USBNC_USB_OTG2_CTRL_WIR_MASK             (0x80000000U)
#define USBNC_USB_OTG2_CTRL_WIR_SHIFT            (31U)
/*! WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_USB_OTG2_CTRL_WIR(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_CTRL_WIR_SHIFT)) & USBNC_USB_OTG2_CTRL_WIR_MASK)
/*! @} */

/*! @name USB_OTG1_PHY_CTRL_0 - OTG1 UTMI PHY Control 0 Register */
/*! @{ */

#define USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD_MASK (0x80000000U)
#define USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT (31U)
/*! UTMI_CLK_VLD
 *  0b0..Invalid
 *  0b1..Valid
 */
#define USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD(x) (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT)) & USBNC_USB_OTG1_PHY_CTRL_0_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name USB_OTG2_PHY_CTRL_0 - OTG2 UTMI PHY Control 0 Register */
/*! @{ */

#define USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD_MASK (0x80000000U)
#define USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT (31U)
/*! UTMI_CLK_VLD
 *  0b0..Invalid
 *  0b1..Valid
 */
#define USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD(x) (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT)) & USBNC_USB_OTG2_PHY_CTRL_0_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name OTG2_CTRL1 - USB OTG Control 1 Register */
/*! @{ */

#define USBNC_OTG2_CTRL1_OVER_CUR_DIS_MASK       (0x80U)
#define USBNC_OTG2_CTRL1_OVER_CUR_DIS_SHIFT      (7U)
/*! OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_OTG2_CTRL1_OVER_CUR_DIS(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_OTG2_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_OTG2_CTRL1_OVER_CUR_POL_MASK       (0x100U)
#define USBNC_OTG2_CTRL1_OVER_CUR_POL_SHIFT      (8U)
/*! OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_OTG2_CTRL1_OVER_CUR_POL(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_OTG2_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_OTG2_CTRL1_PWR_POL_MASK            (0x200U)
#define USBNC_OTG2_CTRL1_PWR_POL_SHIFT           (9U)
/*! PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_OTG2_CTRL1_PWR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_PWR_POL_SHIFT)) & USBNC_OTG2_CTRL1_PWR_POL_MASK)

#define USBNC_OTG2_CTRL1_WIE_MASK                (0x400U)
#define USBNC_OTG2_CTRL1_WIE_SHIFT               (10U)
/*! WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_OTG2_CTRL1_WIE(x)                  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WIE_SHIFT)) & USBNC_OTG2_CTRL1_WIE_MASK)

#define USBNC_OTG2_CTRL1_WKUP_SW_EN_MASK         (0x4000U)
#define USBNC_OTG2_CTRL1_WKUP_SW_EN_SHIFT        (14U)
/*! WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG2_CTRL1_WKUP_SW_EN(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_OTG2_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_OTG2_CTRL1_WKUP_SW_MASK            (0x8000U)
#define USBNC_OTG2_CTRL1_WKUP_SW_SHIFT           (15U)
/*! WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_OTG2_CTRL1_WKUP_SW(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WKUP_SW_SHIFT)) & USBNC_OTG2_CTRL1_WKUP_SW_MASK)

#define USBNC_OTG2_CTRL1_WKUP_ID_EN_MASK         (0x10000U)
#define USBNC_OTG2_CTRL1_WKUP_ID_EN_SHIFT        (16U)
/*! WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG2_CTRL1_WKUP_ID_EN(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_OTG2_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_OTG2_CTRL1_WKUP_VBUS_EN_MASK       (0x20000U)
#define USBNC_OTG2_CTRL1_WKUP_VBUS_EN_SHIFT      (17U)
/*! WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG2_CTRL1_WKUP_VBUS_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_OTG2_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_OTG2_CTRL1_ULPI_PHY_CLK_EN_MASK    (0x100000U)
#define USBNC_OTG2_CTRL1_ULPI_PHY_CLK_EN_SHIFT   (20U)
/*! ULPI_PHY_CLK_EN - ULPI PHY clock enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_OTG2_CTRL1_ULPI_PHY_CLK_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_ULPI_PHY_CLK_EN_SHIFT)) & USBNC_OTG2_CTRL1_ULPI_PHY_CLK_EN_MASK)

#define USBNC_OTG2_CTRL1_WKUP_DPDM_EN_MASK       (0x20000000U)
#define USBNC_OTG2_CTRL1_WKUP_DPDM_EN_SHIFT      (29U)
/*! WKUP_DPDM_EN - Wake-up on DPDM change enable
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_OTG2_CTRL1_WKUP_DPDM_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_OTG2_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_OTG2_CTRL1_WIR_MASK                (0x80000000U)
#define USBNC_OTG2_CTRL1_WIR_SHIFT               (31U)
/*! WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_OTG2_CTRL1_WIR(x)                  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL1_WIR_SHIFT)) & USBNC_OTG2_CTRL1_WIR_MASK)
/*! @} */

/*! @name OTG2_CTRL2 - USB OTG Control 2 Register */
/*! @{ */

#define USBNC_OTG2_CTRL2_VBUS_SOURCE_SEL_MASK    (0x3U)
#define USBNC_OTG2_CTRL2_VBUS_SOURCE_SEL_SHIFT   (0U)
#define USBNC_OTG2_CTRL2_VBUS_SOURCE_SEL(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_OTG2_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_OTG2_CTRL2_AUTURESUME_EN_MASK      (0x4U)
#define USBNC_OTG2_CTRL2_AUTURESUME_EN_SHIFT     (2U)
/*! AUTURESUME_EN - Auto Resume Enable
 *  0b0..Default
 */
#define USBNC_OTG2_CTRL2_AUTURESUME_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL2_AUTURESUME_EN_SHIFT)) & USBNC_OTG2_CTRL2_AUTURESUME_EN_MASK)

#define USBNC_OTG2_CTRL2_LOWSPEED_EN_MASK        (0x8U)
#define USBNC_OTG2_CTRL2_LOWSPEED_EN_SHIFT       (3U)
/*! LOWSPEED_EN
 *  0b0..Default
 */
#define USBNC_OTG2_CTRL2_LOWSPEED_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL2_LOWSPEED_EN_SHIFT)) & USBNC_OTG2_CTRL2_LOWSPEED_EN_MASK)

#define USBNC_OTG2_CTRL2_UTMI_CLK_VLD_MASK       (0x80000000U)
#define USBNC_OTG2_CTRL2_UTMI_CLK_VLD_SHIFT      (31U)
/*! UTMI_CLK_VLD
 *  0b0..Default
 */
#define USBNC_OTG2_CTRL2_UTMI_CLK_VLD(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG2_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_OTG2_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBNC_Register_Masks */


/*!
 * @}
 */ /* end of group USBNC_Peripheral_Access_Layer */


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


#endif  /* PERI_USBNC_H_ */

