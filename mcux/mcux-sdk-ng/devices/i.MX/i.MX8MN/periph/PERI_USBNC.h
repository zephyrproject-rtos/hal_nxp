/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBNC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
  __IO uint32_t OTG1_CTRL1;                        /**< offset: 0x200 */
  __IO uint32_t OTG1_CTRL2;                        /**< offset: 0x204 */
       uint8_t RESERVED_1[40];
  __IO uint32_t OTG1_PHY_CFG1;                     /**< USB OTG PHY Configuration Register 1, offset: 0x230 */
  __IO uint32_t OTG1_PHY_CFG2;                     /**< USB OTG PHY Configuration Register 2, offset: 0x234 */
       uint8_t RESERVED_2[4];
  __I  uint32_t OTG1_PHY_STATUS;                   /**< USB OTG PHY Status Register, offset: 0x23C */
       uint8_t RESERVED_3[16];
  __IO uint32_t ADP_CFG1;                          /**< offset: 0x250 */
  __IO uint32_t ADP_CFG2;                          /**< offset: 0x254 */
  __I  uint32_t ADP_STATUS;                        /**< offset: 0x258 */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name OTG1_CTRL1 -  */
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

#define USBNC_OTG1_CTRL1_WKUP_DPDM_EN_MASK       (0x20000000U)
#define USBNC_OTG1_CTRL1_WKUP_DPDM_EN_SHIFT      (29U)
/*! WKUP_DPDM_EN
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

/*! @name OTG1_CTRL2 -  */
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

#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDE_MASK   (0x10U)
#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDE_SHIFT  (4U)
#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDE(x)     (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_TERMSEL_OVERRIDE_SHIFT)) & USBNC_OTG1_CTRL2_TERMSEL_OVERRIDE_MASK)

#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDEEN_MASK (0x20U)
#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDEEN_SHIFT (5U)
/*! TERMSEL_OVERRIDEEN
 *  0b0..The state of the UTMI TermSelect signal to the USB PHY is set by the USB controller.
 *  0b1..The state of the UTMI TermSelect signal to the USB PHY is set by the value in the USBNC_x_CTRL2[TERMSEL_OVERRIDE] bit field.
 */
#define USBNC_OTG1_CTRL2_TERMSEL_OVERRIDEEN(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_TERMSEL_OVERRIDEEN_SHIFT)) & USBNC_OTG1_CTRL2_TERMSEL_OVERRIDEEN_MASK)

#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDE_MASK    (0xC0U)
#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDE_SHIFT   (6U)
#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDE(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_OPMODE_OVERRIDE_SHIFT)) & USBNC_OTG1_CTRL2_OPMODE_OVERRIDE_MASK)

#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDEEN_MASK  (0x100U)
#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDEEN_SHIFT (8U)
/*! OPMODE_OVERRIDEEN
 *  0b0..The state of the UTMI OpMode signals to the USB PHY is set by the USB controller.
 *  0b1..The state of the UTMI OpMode signals to the USB PHY is set by the values in the USBNC_x_CTRL2[OPMODE_OVERRIDE] bit field.
 */
#define USBNC_OTG1_CTRL2_OPMODE_OVERRIDEEN(x)    (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_OPMODE_OVERRIDEEN_SHIFT)) & USBNC_OTG1_CTRL2_OPMODE_OVERRIDEEN_MASK)

#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDE_MASK   (0x600U)
#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDE_SHIFT  (9U)
#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDE(x)     (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDE_SHIFT)) & USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDE_MASK)

#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDEEN_MASK (0x800U)
#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDEEN_SHIFT (11U)
/*! XCVRSEL_OVERRIDEEN
 *  0b0..The state of the UTMI XcvrSelect signals to the USB PHY is set by the USB controller.
 *  0b1..The state of the UTMI XcvrSelect signals to the USB PHY is set by the values in the USBNC_x_CTRL2[XCVRSEL_OVERRIDE] bit field.
 */
#define USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDEEN(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDEEN_SHIFT)) & USBNC_OTG1_CTRL2_XCVRSEL_OVERRIDEEN_MASK)

#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDE_MASK (0x1000U)
#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDE_SHIFT (12U)
/*! DPPULLDOWN_OVERRIDE
 *  0b0..DP pulldown resistor disabled
 *  0b1..DP pulldown resistor enabled
 */
#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDE_SHIFT)) & USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDE_MASK)

#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDEEN_MASK (0x2000U)
#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDEEN_SHIFT (13U)
/*! DPPULLDOWN_OVERRIDEEN
 *  0b0..USB controller enables/disables the DP pulldown resistor in the USB PHY.
 *  0b1..Use the value set by the USBNC_n_CTRL2[DPPULLDOWN_OVERRIDE] bit field to enable/disable the DP pulldown resistor in the USB PHY.
 */
#define USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDEEN(x) (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDEEN_SHIFT)) & USBNC_OTG1_CTRL2_DPPULLDOWN_OVERRIDEEN_MASK)

#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDE_MASK (0x4000U)
#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDE_SHIFT (14U)
/*! DMPULLDOWN_OVERRIDE
 *  0b0..DM pulldown resistor disabled
 *  0b1..DM pulldown resistor enabled
 */
#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDE_SHIFT)) & USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDE_MASK)

#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDEEN_MASK (0x8000U)
#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDEEN_SHIFT (15U)
/*! DMPULLDOWN_OVERRIDEEN
 *  0b0..USB controller enables/disables the DM pulldown resistor in the USB PHY.
 *  0b1..Use the value set by the USBNC_n_CTRL2[DMPULLDOWN_OVERRIDE] bit field to enable/disable the DM pulldown resistor in the USB PHY.
 */
#define USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDEEN(x) (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDEEN_SHIFT)) & USBNC_OTG1_CTRL2_DMPULLDOWN_OVERRIDEEN_MASK)

#define USBNC_OTG1_CTRL2_DIG_ID_SEL_MASK         (0x100000U)
#define USBNC_OTG1_CTRL2_DIG_ID_SEL_SHIFT        (20U)
/*! DIG_ID_SEL
 *  0b0..Use the USB_OTG*_ID pin for the USB OTG ID pin detection function(default)
 *  0b1..Use the pin configured by the IOMUXC_USB_OTG*_ID_SELECT_INPUT register for the USB OTG ID pin detection function
 */
#define USBNC_OTG1_CTRL2_DIG_ID_SEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_DIG_ID_SEL_SHIFT)) & USBNC_OTG1_CTRL2_DIG_ID_SEL_MASK)

#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD_MASK       (0x80000000U)
#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD_SHIFT      (31U)
/*! UTMI_CLK_VLD
 *  0b0..UTMI clock to USB PHY is not toggling (Default)
 *  0b1..UTMI clock to USB PHY has toggled several times
 */
#define USBNC_OTG1_CTRL2_UTMI_CLK_VLD(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_OTG1_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name OTG1_PHY_CFG1 - USB OTG PHY Configuration Register 1 */
/*! @{ */

#define USBNC_OTG1_PHY_CFG1_COMMONONN_MASK       (0x1U)
#define USBNC_OTG1_PHY_CFG1_COMMONONN_SHIFT      (0U)
/*! COMMONONN - Common Block Power-Down Control
 *  0b0..
 *  0b0..In Suspend or Sleep modes, the Bias and PLL blocks remain powered
 *  0b1..In Suspend or Sleep modes, the Bias and PLL blocks are powered down
 */
#define USBNC_OTG1_PHY_CFG1_COMMONONN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_COMMONONN_SHIFT)) & USBNC_OTG1_PHY_CFG1_COMMONONN_MASK)

#define USBNC_OTG1_PHY_CFG1_FSEL_MASK            (0xEU)
#define USBNC_OTG1_PHY_CFG1_FSEL_SHIFT           (1U)
/*! FSEL - Reference Clock Frequency Select
 *  0b000..9.6 MHz
 *  0b001..10 MHz
 *  0b010..12 MHz
 *  0b011..19.2 MHz
 *  0b100..20 MHz
 *  0b101..24 MHz (only valid setting for this SOC)
 *  0b110..Reserved
 *  0b111..50 MHz
 */
#define USBNC_OTG1_PHY_CFG1_FSEL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_FSEL_SHIFT)) & USBNC_OTG1_PHY_CFG1_FSEL_MASK)

#define USBNC_OTG1_PHY_CFG1_COMPDISTUNE0_MASK    (0x70U)
#define USBNC_OTG1_PHY_CFG1_COMPDISTUNE0_SHIFT   (4U)
/*! COMPDISTUNE0 - Disconnect Threshold Adjustment
 *  0b000..-6%
 *  0b001..-4.5%
 *  0b010..-3%
 *  0b011..-1.5%
 *  0b100..Design default
 *  0b101..+1.5%
 *  0b110..+3%
 *  0b111..+4.5%
 */
#define USBNC_OTG1_PHY_CFG1_COMPDISTUNE0(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_COMPDISTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_COMPDISTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_SQRXTUNE0_MASK       (0x380U)
#define USBNC_OTG1_PHY_CFG1_SQRXTUNE0_SHIFT      (7U)
/*! SQRXTUNE0 - Squelch Threshold Adjustment
 *  0b000..+15%
 *  0b001..+10%
 *  0b010..+5%
 *  0b011..Design default
 *  0b100..-5%
 *  0b101..-10%
 *  0b110..-15%
 *  0b111..-20%
 */
#define USBNC_OTG1_PHY_CFG1_SQRXTUNE0(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_SQRXTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_SQRXTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_OTGTUNE0_MASK        (0x1C00U)
#define USBNC_OTG1_PHY_CFG1_OTGTUNE0_SHIFT       (10U)
/*! OTGTUNE0 - VBUS Valid Threshold Adjustment
 *  0b000..-6%
 *  0b001..-4.5%
 *  0b010..-3%
 *  0b011..-1.5%
 *  0b100..Design default
 *  0b101..+1.5%
 *  0b110..+3%
 *  0b111..+4.5%
 */
#define USBNC_OTG1_PHY_CFG1_OTGTUNE0(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_OTGTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_OTGTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXHSXVTUNE0_MASK     (0x6000U)
#define USBNC_OTG1_PHY_CFG1_TXHSXVTUNE0_SHIFT    (13U)
/*! TXHSXVTUNE0 - Transmitter High-Speed Crossover Adjustment
 *  0b00..Reserved
 *  0b01..-15mV
 *  0b10..+15mV
 *  0b11..Design default
 */
#define USBNC_OTG1_PHY_CFG1_TXHSXVTUNE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXHSXVTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXHSXVTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXFSLSTUNE0_MASK     (0xF0000U)
#define USBNC_OTG1_PHY_CFG1_TXFSLSTUNE0_SHIFT    (16U)
/*! TXFSLSTUNE0 - FS/LS Source Impedance Adjustment
 *  0b0000..+5%
 *  0b0001..+2.5%
 *  0b0011..Design default
 *  0b0111..-2.5%
 *  0b1111..-5%
 */
#define USBNC_OTG1_PHY_CFG1_TXFSLSTUNE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXFSLSTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXFSLSTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXVREFTUNE0_MASK     (0xF00000U)
#define USBNC_OTG1_PHY_CFG1_TXVREFTUNE0_SHIFT    (20U)
/*! TXVREFTUNE0 - HS DC Voltage Level Adjustment
 *  0b0000..-6%
 *  0b0001..-4%
 *  0b0010..-2%
 *  0b0011..Design default
 *  0b0100..+2%
 *  0b0101..+4%
 *  0b0110..+6%
 *  0b0111..+8%
 *  0b1000..+10%
 *  0b1001..+12%
 *  0b1010..+14%
 *  0b1011..+16%
 *  0b1100..+18%
 *  0b1101..+20%
 *  0b1110..+22%
 *  0b1111..+24%
 */
#define USBNC_OTG1_PHY_CFG1_TXVREFTUNE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXVREFTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXVREFTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXRISETUNE0_MASK     (0x3000000U)
#define USBNC_OTG1_PHY_CFG1_TXRISETUNE0_SHIFT    (24U)
/*! TXRISETUNE0 - HS Transmitter Rise/Fall Time Adjustment
 *  0b00..-10%
 *  0b01..Design default
 *  0b10..+15%
 *  0b11..+20%
 */
#define USBNC_OTG1_PHY_CFG1_TXRISETUNE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXRISETUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXRISETUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXRESTUNE0_MASK      (0xC000000U)
#define USBNC_OTG1_PHY_CFG1_TXRESTUNE0_SHIFT     (26U)
/*! TXRESTUNE0 - USB Source Impedance Adjustment
 *  0b00..Source impedance is increased by approximately 1.5 ohm
 *  0b01..Design default
 *  0b10..Source impedance is decreased by approximately 2 ohm
 *  0b11..Source impedance is decreased by approximately 4 ohm
 */
#define USBNC_OTG1_PHY_CFG1_TXRESTUNE0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXRESTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXRESTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXPREEMPAMPTUNE0_MASK (0x30000000U)
#define USBNC_OTG1_PHY_CFG1_TXPREEMPAMPTUNE0_SHIFT (28U)
/*! TXPREEMPAMPTUNE0 - HS Treansmitter Pre-Emphasis Current Control
 *  0b00..HS Transmitter pre-emphasis is disabled
 *  0b01..HS Transmitter pre-emphasis circuit sources 1X pre-emphasis current (design default)
 *  0b10..HS Transmitter pre-emphasis circuit sources 2X pre-emphasis current
 *  0b11..HS Transmitter pre-emphasis circuit sources 3X pre-emphasis current
 */
#define USBNC_OTG1_PHY_CFG1_TXPREEMPAMPTUNE0(x)  (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXPREEMPAMPTUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXPREEMPAMPTUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_TXPREEMPPULSETUNE0_MASK (0x40000000U)
#define USBNC_OTG1_PHY_CFG1_TXPREEMPPULSETUNE0_SHIFT (30U)
/*! TXPREEMPPULSETUNE0 - HS Transmitter Pre-Emphasis Duration Control
 *  0b0..2X, long pre-emphasis current duration (design default)
 *  0b1..1X, short pre-emphasis current duration
 */
#define USBNC_OTG1_PHY_CFG1_TXPREEMPPULSETUNE0(x) (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_TXPREEMPPULSETUNE0_SHIFT)) & USBNC_OTG1_PHY_CFG1_TXPREEMPPULSETUNE0_MASK)

#define USBNC_OTG1_PHY_CFG1_CHRGDET_Megamix_MASK (0x80000000U)
#define USBNC_OTG1_PHY_CFG1_CHRGDET_Megamix_SHIFT (31U)
/*! CHRGDET_Megamix - USB_OTG1_CHD_B output control
 *  0b0..The external state of USB_OTG1_CHD_B is only controlled by the state of the CHRGDET signal
 *  0b1..The external state of USB_OTG1_CHD_B is forced low
 */
#define USBNC_OTG1_PHY_CFG1_CHRGDET_Megamix(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG1_CHRGDET_Megamix_SHIFT)) & USBNC_OTG1_PHY_CFG1_CHRGDET_Megamix_MASK)
/*! @} */

/*! @name OTG1_PHY_CFG2 - USB OTG PHY Configuration Register 2 */
/*! @{ */

#define USBNC_OTG1_PHY_CFG2_CHRGSEL_MASK         (0x1U)
#define USBNC_OTG1_PHY_CFG2_CHRGSEL_SHIFT        (0U)
/*! CHRGSEL - Battery Charging Source Select
 *  0b0..VDP_SRC is connected to USB_OTG*_DP and IDM_SINK is connected to USB_OTG*_DN. Used for Primary Detection.
 *  0b1..VDM_SRC is connected to USB_OTG*_DN and IDP_SINK is connected to USB_OTG*_DP. Used for Secondary Detection.
 */
#define USBNC_OTG1_PHY_CFG2_CHRGSEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_CHRGSEL_SHIFT)) & USBNC_OTG1_PHY_CFG2_CHRGSEL_MASK)

#define USBNC_OTG1_PHY_CFG2_VDATDETENB0_MASK     (0x2U)
#define USBNC_OTG1_PHY_CFG2_VDATDETENB0_SHIFT    (1U)
/*! VDATDETENB0 - Battery Charging Detection Comparator Enable
 *  0b0..Battery Charging detection comparator connected to USB_OTG*_D* pin is disabled
 *  0b1..Battery Charging detection comparator connected to USB_OTG*_D* pin is enabled
 */
#define USBNC_OTG1_PHY_CFG2_VDATDETENB0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_VDATDETENB0_SHIFT)) & USBNC_OTG1_PHY_CFG2_VDATDETENB0_MASK)

#define USBNC_OTG1_PHY_CFG2_VDATSRCENB0_MASK     (0x4U)
#define USBNC_OTG1_PHY_CFG2_VDATSRCENB0_SHIFT    (2U)
/*! VDATSRCENB0 - Battery Charging Source Select
 *  0b0..VD*_SRC and ID*_SINK are disabled
 *  0b1..VD*_SRC and ID*_SINK are enabled
 */
#define USBNC_OTG1_PHY_CFG2_VDATSRCENB0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_VDATSRCENB0_SHIFT)) & USBNC_OTG1_PHY_CFG2_VDATSRCENB0_MASK)

#define USBNC_OTG1_PHY_CFG2_DCDENB_MASK          (0x8U)
#define USBNC_OTG1_PHY_CFG2_DCDENB_SHIFT         (3U)
/*! DCDENB - Data Contact Detection Enable
 *  0b0..IDP_SRC current and RDM_DWN pull-down resistance are disabled
 *  0b1..IDP_SRC current and RDM_DWN pull-down resistance are enabled
 */
#define USBNC_OTG1_PHY_CFG2_DCDENB(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_DCDENB_SHIFT)) & USBNC_OTG1_PHY_CFG2_DCDENB_MASK)

#define USBNC_OTG1_PHY_CFG2_ACAENB0_MASK         (0x10U)
#define USBNC_OTG1_PHY_CFG2_ACAENB0_SHIFT        (4U)
/*! ACAENB0 - ACA USB_OTG*_ID Pin Resistance Detection Enable
 *  0b0..Disables detection of resistance on the USB_OTG*_ID pin
 *  0b1..Enables detection of resistance on the USB_OTG*_ID pin
 */
#define USBNC_OTG1_PHY_CFG2_ACAENB0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_ACAENB0_SHIFT)) & USBNC_OTG1_PHY_CFG2_ACAENB0_MASK)

#define USBNC_OTG1_PHY_CFG2_SLEEPM0_MASK         (0x20U)
#define USBNC_OTG1_PHY_CFG2_SLEEPM0_SHIFT        (5U)
/*! SLEEPM0 - Sleep Mode Assertion
 *  0b0..Sleep mode
 *  0b1..Normal operating mode
 */
#define USBNC_OTG1_PHY_CFG2_SLEEPM0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_SLEEPM0_SHIFT)) & USBNC_OTG1_PHY_CFG2_SLEEPM0_MASK)

#define USBNC_OTG1_PHY_CFG2_LOOPBACKENB0_MASK    (0x40U)
#define USBNC_OTG1_PHY_CFG2_LOOPBACKENB0_SHIFT   (6U)
/*! LOOPBACKENB0 - Loopback Test Enable
 *  0b0..During data transmission, the receive logic is disabled
 *  0b1..During data transmission, the receive logic is enabled
 */
#define USBNC_OTG1_PHY_CFG2_LOOPBACKENB0(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_LOOPBACKENB0_SHIFT)) & USBNC_OTG1_PHY_CFG2_LOOPBACKENB0_MASK)

#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFEN0_MASK   (0x100U)
#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFEN0_SHIFT  (8U)
/*! TXBITSTUFFEN0 - Low-Byte Transmit Bit-Stuffing Enable
 *  0b0..Bit stuffing is disabled
 *  0b1..Bit stuffing is enabled
 */
#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFEN0(x)     (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_TXBITSTUFFEN0_SHIFT)) & USBNC_OTG1_PHY_CFG2_TXBITSTUFFEN0_MASK)

#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFENH0_MASK  (0x200U)
#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFENH0_SHIFT (9U)
/*! TXBITSTUFFENH0 - High-Byte Transmit Bit-Stuffing Enable
 *  0b0..Bit stuffing is disabled
 *  0b1..Bit stuffing is enabled
 */
#define USBNC_OTG1_PHY_CFG2_TXBITSTUFFENH0(x)    (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_TXBITSTUFFENH0_SHIFT)) & USBNC_OTG1_PHY_CFG2_TXBITSTUFFENH0_MASK)

#define USBNC_OTG1_PHY_CFG2_OTGDISABLE0_MASK     (0x400U)
#define USBNC_OTG1_PHY_CFG2_OTGDISABLE0_SHIFT    (10U)
/*! OTGDISABLE0 - OTG Block Disable
 *  0b0..The OTG block is powered up
 *  0b1..The OTG block is powered down
 */
#define USBNC_OTG1_PHY_CFG2_OTGDISABLE0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_OTGDISABLE0_SHIFT)) & USBNC_OTG1_PHY_CFG2_OTGDISABLE0_MASK)

#define USBNC_OTG1_PHY_CFG2_ADPCHRG0_MASK        (0x800U)
#define USBNC_OTG1_PHY_CFG2_ADPCHRG0_SHIFT       (11U)
/*! ADPCHRG0 - VBUS Input ADP Charge Enable
 *  0b0..Disables charging USB_OTG*_VBUS during ADP
 *  0b1..Disables charging USB_OTG*_VBUS during ADP
 */
#define USBNC_OTG1_PHY_CFG2_ADPCHRG0(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_ADPCHRG0_SHIFT)) & USBNC_OTG1_PHY_CFG2_ADPCHRG0_MASK)

#define USBNC_OTG1_PHY_CFG2_ADPDISCHRG0_MASK     (0x1000U)
#define USBNC_OTG1_PHY_CFG2_ADPDISCHRG0_SHIFT    (12U)
/*! ADPDISCHRG0 - VBUS Input ADP Discharge Enable
 *  0b0..Disables discharging USB_OTG*_VBUS during ADP
 *  0b1..Enables discharging USB_OTG*_VBUS during ADP
 */
#define USBNC_OTG1_PHY_CFG2_ADPDISCHRG0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_ADPDISCHRG0_SHIFT)) & USBNC_OTG1_PHY_CFG2_ADPDISCHRG0_MASK)

#define USBNC_OTG1_PHY_CFG2_ADPPRBENB0_MASK      (0x2000U)
#define USBNC_OTG1_PHY_CFG2_ADPPRBENB0_SHIFT     (13U)
/*! ADPPRBENB0 - ADP Probe Enable
 *  0b0..ADP Probe comparator is disabled
 *  0b1..ADP Probe comparator is enabled
 */
#define USBNC_OTG1_PHY_CFG2_ADPPRBENB0(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_ADPPRBENB0_SHIFT)) & USBNC_OTG1_PHY_CFG2_ADPPRBENB0_MASK)

#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXTSEL0_MASK  (0x4000U)
#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXTSEL0_SHIFT (14U)
/*! VBUSVLDEXTSEL0 - External VBUS Valid Select
 *  0b0..The USB OTG PHY internal Session Valid comparator is used to enable the pull-up resistor on the USB_OTG*_DP pin
 *  0b1..The VBUSVLDEXT signal is used to enable the pull-up resistor on the USB_OTG*_DP pin
 */
#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXTSEL0(x)    (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_VBUSVLDEXTSEL0_SHIFT)) & USBNC_OTG1_PHY_CFG2_VBUSVLDEXTSEL0_MASK)

#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXT_MASK      (0x8000U)
#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXT_SHIFT     (15U)
/*! VBUSVLDEXT - External VBUS Valid Indicator
 *  0b0..The VBUS signal sensed outside the USB OTG PHY is not valid, and the pull-up resistor on USB_OTG*_DP is disabled
 *  0b1..The VBUS signal sensed outside the USB OTG PHY is valid, and the pull-up resistor on USB_OTG*_DP is enabled
 */
#define USBNC_OTG1_PHY_CFG2_VBUSVLDEXT(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_VBUSVLDEXT_SHIFT)) & USBNC_OTG1_PHY_CFG2_VBUSVLDEXT_MASK)

#define USBNC_OTG1_PHY_CFG2_DRVVBUS0_MASK        (0x10000U)
#define USBNC_OTG1_PHY_CFG2_DRVVBUS0_SHIFT       (16U)
/*! DRVVBUS0 - VBUS Valid Comparator Enable
 *  0b0..The VBUS Valid comparator is disabled
 *  0b1..The VBUS Valid comparator is enabled
 */
#define USBNC_OTG1_PHY_CFG2_DRVVBUS0(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_CFG2_DRVVBUS0_SHIFT)) & USBNC_OTG1_PHY_CFG2_DRVVBUS0_MASK)
/*! @} */

/*! @name OTG1_PHY_STATUS - USB OTG PHY Status Register */
/*! @{ */

#define USBNC_OTG1_PHY_STATUS_LINE_STATE_MASK    (0x3U)
#define USBNC_OTG1_PHY_STATUS_LINE_STATE_SHIFT   (0U)
/*! LINE_STATE - Line State Indicator outputs from USB OTG PHY
 *  0b00..SE0 (DP low, DN low)
 *  0b01..J state for high-speed and full-speed USB traffic; K state for low-speed USB traffic (DP high, DN low)
 *  0b10..K state for high-speed and full-speed USB traffic; J state for low-speed USB traffic (DP low, DN high)
 *  0b11..SE1 (DP high, DN high)
 */
#define USBNC_OTG1_PHY_STATUS_LINE_STATE(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_LINE_STATE_SHIFT)) & USBNC_OTG1_PHY_STATUS_LINE_STATE_MASK)

#define USBNC_OTG1_PHY_STATUS_SESS_VLD_MASK      (0x4U)
#define USBNC_OTG1_PHY_STATUS_SESS_VLD_SHIFT     (2U)
/*! SESS_VLD - OTG Device Session Valid Indicator from USB OTG PHY
 *  0b0..The voltage on USB_OTG*_VBUS is below the OTG Device Session Valid threshold
 *  0b1..The voltage on USB_OTG*_VBUS is above the OTG Device Session Valid threshold
 */
#define USBNC_OTG1_PHY_STATUS_SESS_VLD(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_SESS_VLD_SHIFT)) & USBNC_OTG1_PHY_STATUS_SESS_VLD_MASK)

#define USBNC_OTG1_PHY_STATUS_VBUS_VLD_MASK      (0x8U)
#define USBNC_OTG1_PHY_STATUS_VBUS_VLD_SHIFT     (3U)
/*! VBUS_VLD - VBUS Valid Indicator from USB OTG PHY
 *  0b0..The voltage on USB_OTG*_VBUS is below the VBUS Valid threshold
 *  0b1..The voltage on USB_OTG*_VBUS is above the VBUS Valid threshold
 */
#define USBNC_OTG1_PHY_STATUS_VBUS_VLD(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_VBUS_VLD_SHIFT)) & USBNC_OTG1_PHY_STATUS_VBUS_VLD_MASK)

#define USBNC_OTG1_PHY_STATUS_ID_DIG_MASK        (0x10U)
#define USBNC_OTG1_PHY_STATUS_ID_DIG_SHIFT       (4U)
/*! ID_DIG - Micro- or Mini- A/B Plug Indicator
 *  0b0..The connnected plug is a Micro- or Mini-A plug
 *  0b1..The connnected plug is a Micro- or Mini-B plug
 */
#define USBNC_OTG1_PHY_STATUS_ID_DIG(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_ID_DIG_SHIFT)) & USBNC_OTG1_PHY_STATUS_ID_DIG_MASK)

#define USBNC_OTG1_PHY_STATUS_HOST_DISCONNECT_MASK (0x20U)
#define USBNC_OTG1_PHY_STATUS_HOST_DISCONNECT_SHIFT (5U)
/*! HOST_DISCONNECT - Peripheral Disconnect Indicator
 *  0b0..Peripheral is connected
 *  0b1..No peripheral is connected
 */
#define USBNC_OTG1_PHY_STATUS_HOST_DISCONNECT(x) (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_HOST_DISCONNECT_SHIFT)) & USBNC_OTG1_PHY_STATUS_HOST_DISCONNECT_MASK)

#define USBNC_OTG1_PHY_STATUS_RIDC0_MASK         (0x1000000U)
#define USBNC_OTG1_PHY_STATUS_RIDC0_SHIFT        (24U)
/*! RIDC0 - ACA USB_OTG*_ID Pin Resistance Indicator
 *  0b0..ACA OTG_ID pin resistance is >= RID_B (min) and <= RID_GND max
 *  0b1..ACA OTG_ID pin resistance is >= RID_C (min) and <= RID_C max
 */
#define USBNC_OTG1_PHY_STATUS_RIDC0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_RIDC0_SHIFT)) & USBNC_OTG1_PHY_STATUS_RIDC0_MASK)

#define USBNC_OTG1_PHY_STATUS_RIDB0_MASK         (0x2000000U)
#define USBNC_OTG1_PHY_STATUS_RIDB0_SHIFT        (25U)
/*! RIDB0 - ACA USB_OTG*_ID Pin Resistance Indicator
 *  0b0..ACA OTG_ID pin resistance is >= RID_A (min) and <= RID_C max
 *  0b1..ACA OTG_ID pin resistance is >= RID_B (min) and <= RID_B max
 */
#define USBNC_OTG1_PHY_STATUS_RIDB0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_RIDB0_SHIFT)) & USBNC_OTG1_PHY_STATUS_RIDB0_MASK)

#define USBNC_OTG1_PHY_STATUS_RIDA0_MASK         (0x4000000U)
#define USBNC_OTG1_PHY_STATUS_RIDA0_SHIFT        (26U)
/*! RIDA0 - ACA USB_OTG*_ID Pin Resistance Indicator
 *  0b0..ACA OTG_ID pin resistance is >= RID_FLOAT (min) and <= RID_B max
 *  0b1..ACA OTG_ID pin resistance is >= RID_A (min) and <= RID_A max
 */
#define USBNC_OTG1_PHY_STATUS_RIDA0(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_RIDA0_SHIFT)) & USBNC_OTG1_PHY_STATUS_RIDA0_MASK)

#define USBNC_OTG1_PHY_STATUS_RIDGND0_MASK       (0x8000000U)
#define USBNC_OTG1_PHY_STATUS_RIDGND0_SHIFT      (27U)
/*! RIDGND0 - ACA USB_OTG*_ID Pin Resistance Indicator
 *  0b0..ACA OTG_ID pin resistance is >= RID_C (min)
 *  0b1..ACA OTG_ID pin resistance is <= RID_GND (max)
 */
#define USBNC_OTG1_PHY_STATUS_RIDGND0(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_RIDGND0_SHIFT)) & USBNC_OTG1_PHY_STATUS_RIDGND0_MASK)

#define USBNC_OTG1_PHY_STATUS_RIDFLOAT0_MASK     (0x10000000U)
#define USBNC_OTG1_PHY_STATUS_RIDFLOAT0_SHIFT    (28U)
/*! RIDFLOAT0 - ACA USB_OTG*_ID Pin Resistance Indicator
 *  0b0..ACA OTG_ID pin resistance is <= RID_A (max)
 *  0b1..ACA OTG_ID pin resistance is >= RID_FLOAT (min)
 */
#define USBNC_OTG1_PHY_STATUS_RIDFLOAT0(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_RIDFLOAT0_SHIFT)) & USBNC_OTG1_PHY_STATUS_RIDFLOAT0_MASK)

#define USBNC_OTG1_PHY_STATUS_CHRGDET_MASK       (0x20000000U)
#define USBNC_OTG1_PHY_STATUS_CHRGDET_SHIFT      (29U)
/*! CHRGDET - Battery Charger Detection Output
 *  0b0..VD* < VDAT_REF
 *  0b1..VD* > VDAT_REF
 */
#define USBNC_OTG1_PHY_STATUS_CHRGDET(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_CHRGDET_SHIFT)) & USBNC_OTG1_PHY_STATUS_CHRGDET_MASK)

#define USBNC_OTG1_PHY_STATUS_ADPPRB0_MASK       (0x40000000U)
#define USBNC_OTG1_PHY_STATUS_ADPPRB0_SHIFT      (30U)
/*! ADPPRB0 - ADP Probe Indicator
 *  0b0..The voltage on USB_OTG*_VBUS is below the ADP probing voltage
 *  0b1..The voltage on USB_OTG*_VBUS is above the ADP probing voltage
 */
#define USBNC_OTG1_PHY_STATUS_ADPPRB0(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_ADPPRB0_SHIFT)) & USBNC_OTG1_PHY_STATUS_ADPPRB0_MASK)

#define USBNC_OTG1_PHY_STATUS_ADPSNS0_MASK       (0x80000000U)
#define USBNC_OTG1_PHY_STATUS_ADPSNS0_SHIFT      (31U)
/*! ADPSNS0 - ADP Sense Indicator
 *  0b0..The voltage on USB_OTG*_VBUS is below the ADP sensing voltage
 *  0b1..The voltage on USB_OTG*_VBUS is above the ADP sensing voltage
 */
#define USBNC_OTG1_PHY_STATUS_ADPSNS0(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_OTG1_PHY_STATUS_ADPSNS0_SHIFT)) & USBNC_OTG1_PHY_STATUS_ADPSNS0_MASK)
/*! @} */

/*! @name ADP_CFG1 -  */
/*! @{ */

#define USBNC_ADP_CFG1_ADP_WAIT_MASK             (0x3FFFFU)
#define USBNC_ADP_CFG1_ADP_WAIT_SHIFT            (0U)
/*! ADP_WAIT
 *  0b001100000000000000..Default
 */
#define USBNC_ADP_CFG1_ADP_WAIT(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG1_ADP_WAIT_SHIFT)) & USBNC_ADP_CFG1_ADP_WAIT_MASK)

#define USBNC_ADP_CFG1_TIMER_EN_MASK             (0x100000U)
#define USBNC_ADP_CFG1_TIMER_EN_SHIFT            (20U)
/*! TIMER_EN - ADP Timer Test Enable
 *  0b0..Default
 */
#define USBNC_ADP_CFG1_TIMER_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG1_TIMER_EN_SHIFT)) & USBNC_ADP_CFG1_TIMER_EN_MASK)

#define USBNC_ADP_CFG1_ADP_SNS_INT_EN_MASK       (0x200000U)
#define USBNC_ADP_CFG1_ADP_SNS_INT_EN_SHIFT      (21U)
/*! ADP_SNS_INT_EN - ADP Sense Interrupt Enable
 *  0b0..Default
 */
#define USBNC_ADP_CFG1_ADP_SNS_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG1_ADP_SNS_INT_EN_SHIFT)) & USBNC_ADP_CFG1_ADP_SNS_INT_EN_MASK)

#define USBNC_ADP_CFG1_ADP_PRB_INT_EN_MASK       (0x400000U)
#define USBNC_ADP_CFG1_ADP_PRB_INT_EN_SHIFT      (22U)
/*! ADP_PRB_INT_EN
 *  0b0..Default
 */
#define USBNC_ADP_CFG1_ADP_PRB_INT_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG1_ADP_PRB_INT_EN_SHIFT)) & USBNC_ADP_CFG1_ADP_PRB_INT_EN_MASK)

#define USBNC_ADP_CFG1_ADP_PRB_EN_MASK           (0x800000U)
#define USBNC_ADP_CFG1_ADP_PRB_EN_SHIFT          (23U)
/*! ADP_PRB_EN
 *  0b0..Default
 */
#define USBNC_ADP_CFG1_ADP_PRB_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG1_ADP_PRB_EN_SHIFT)) & USBNC_ADP_CFG1_ADP_PRB_EN_MASK)
/*! @} */

/*! @name ADP_CFG2 -  */
/*! @{ */

#define USBNC_ADP_CFG2_ADP_CHRG_DELTA_MASK       (0x7FU)
#define USBNC_ADP_CFG2_ADP_CHRG_DELTA_SHIFT      (0U)
/*! ADP_CHRG_DELTA
 *  0b0010000..Default
 */
#define USBNC_ADP_CFG2_ADP_CHRG_DELTA(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG2_ADP_CHRG_DELTA_SHIFT)) & USBNC_ADP_CFG2_ADP_CHRG_DELTA_MASK)

#define USBNC_ADP_CFG2_ADP_CHRG_SWCMP_MASK       (0x80U)
#define USBNC_ADP_CFG2_ADP_CHRG_SWCMP_SHIFT      (7U)
/*! ADP_CHRG_SWCMP
 *  0b0..Default
 */
#define USBNC_ADP_CFG2_ADP_CHRG_SWCMP(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG2_ADP_CHRG_SWCMP_SHIFT)) & USBNC_ADP_CFG2_ADP_CHRG_SWCMP_MASK)

#define USBNC_ADP_CFG2_ADP_CHRG_SWTIME_MASK      (0xFF00U)
#define USBNC_ADP_CFG2_ADP_CHRG_SWTIME_SHIFT     (8U)
/*! ADP_CHRG_SWTIME
 *  0b01000000..Default
 */
#define USBNC_ADP_CFG2_ADP_CHRG_SWTIME(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG2_ADP_CHRG_SWTIME_SHIFT)) & USBNC_ADP_CFG2_ADP_CHRG_SWTIME_MASK)

#define USBNC_ADP_CFG2_ADP_DISCHG_TIME_MASK      (0xFF0000U)
#define USBNC_ADP_CFG2_ADP_DISCHG_TIME_SHIFT     (16U)
/*! ADP_DISCHG_TIME - ADP Discharge time
 *  0b01000110..Default
 */
#define USBNC_ADP_CFG2_ADP_DISCHG_TIME(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_CFG2_ADP_DISCHG_TIME_SHIFT)) & USBNC_ADP_CFG2_ADP_DISCHG_TIME_MASK)
/*! @} */

/*! @name ADP_STATUS -  */
/*! @{ */

#define USBNC_ADP_STATUS_ADP_PRB_TIMR_MASK       (0xFFU)
#define USBNC_ADP_STATUS_ADP_PRB_TIMR_SHIFT      (0U)
/*! ADP_PRB_TIMR - ADP Probe Time
 *  0b00000000..Default
 */
#define USBNC_ADP_STATUS_ADP_PRB_TIMR(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_STATUS_ADP_PRB_TIMR_SHIFT)) & USBNC_ADP_STATUS_ADP_PRB_TIMR_MASK)

#define USBNC_ADP_STATUS_ADP_CNT_MASK            (0x3FFFF00U)
#define USBNC_ADP_STATUS_ADP_CNT_SHIFT           (8U)
/*! ADP_CNT - ADP Internal 18-bit Counter */
#define USBNC_ADP_STATUS_ADP_CNT(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_STATUS_ADP_CNT_SHIFT)) & USBNC_ADP_STATUS_ADP_CNT_MASK)

#define USBNC_ADP_STATUS_ADP_SNS_INT_MASK        (0x4000000U)
#define USBNC_ADP_STATUS_ADP_SNS_INT_SHIFT       (26U)
/*! ADP_SNS_INT - ADP Sense Interrupt Status
 *  0b0..Default
 */
#define USBNC_ADP_STATUS_ADP_SNS_INT(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_STATUS_ADP_SNS_INT_SHIFT)) & USBNC_ADP_STATUS_ADP_SNS_INT_MASK)

#define USBNC_ADP_STATUS_ADP_PRB_INT_MASK        (0x8000000U)
#define USBNC_ADP_STATUS_ADP_PRB_INT_SHIFT       (27U)
/*! ADP_PRB_INT - ADP Probe Interrupt Status
 *  0b0..Default
 */
#define USBNC_ADP_STATUS_ADP_PRB_INT(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_ADP_STATUS_ADP_PRB_INT_SHIFT)) & USBNC_ADP_STATUS_ADP_PRB_INT_MASK)
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

