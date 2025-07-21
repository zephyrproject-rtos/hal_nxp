/*
** ###################################################################
**     Processors:          MIMXRT1064CVJ5A
**                          MIMXRT1064CVJ5B
**                          MIMXRT1064CVL5A
**                          MIMXRT1064CVL5B
**                          MIMXRT1064DVJ6A
**                          MIMXRT1064DVJ6B
**                          MIMXRT1064DVL6A
**                          MIMXRT1064DVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 0.1 (2018-06-22)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1064RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1064RM Rev.0.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1064RM Rev.2.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBNC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(PERI_USBNC_H_)
#define PERI_USBNC_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1064CVJ5A) || defined(CPU_MIMXRT1064CVJ5B) || defined(CPU_MIMXRT1064CVL5A) || defined(CPU_MIMXRT1064CVL5B) || defined(CPU_MIMXRT1064DVJ6A) || defined(CPU_MIMXRT1064DVJ6B) || defined(CPU_MIMXRT1064DVL6A) || defined(CPU_MIMXRT1064DVL6B))
#include "MIMXRT1064_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
       uint8_t RESERVED_0[2048];
  __IO uint32_t USB_OTGn_CTRL;                     /**< USB OTG1 Control Register, offset: 0x800 */
       uint8_t RESERVED_1[20];
  __IO uint32_t USB_OTGn_PHY_CTRL_0;               /**< OTG1 UTMI PHY Control 0 Register, offset: 0x818 */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name USB_OTGn_CTRL - USB OTG1 Control Register */
/*! @{ */

#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK    (0x80U)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT   (7U)
/*! OVER_CUR_DIS
 *  0b0..Enables overcurrent detection
 *  0b1..Disables overcurrent detection
 */
#define USBNC_USB_OTGn_CTRL_OVER_CUR_DIS(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_SHIFT)) & USBNC_USB_OTGn_CTRL_OVER_CUR_DIS_MASK)

#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK    (0x100U)
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT   (8U)
/*! OVER_CUR_POL
 *  0b0..High active (high on this signal represents an overcurrent condition)
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 */
#define USBNC_USB_OTGn_CTRL_OVER_CUR_POL(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_OVER_CUR_POL_SHIFT)) & USBNC_USB_OTGn_CTRL_OVER_CUR_POL_MASK)

#define USBNC_USB_OTGn_CTRL_PWR_POL_MASK         (0x200U)
#define USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT        (9U)
/*! PWR_POL
 *  0b0..PMIC Power Pin is Low active.
 *  0b1..PMIC Power Pin is High active.
 */
#define USBNC_USB_OTGn_CTRL_PWR_POL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_PWR_POL_SHIFT)) & USBNC_USB_OTGn_CTRL_PWR_POL_MASK)

#define USBNC_USB_OTGn_CTRL_WIE_MASK             (0x400U)
#define USBNC_USB_OTGn_CTRL_WIE_SHIFT            (10U)
/*! WIE
 *  0b0..Interrupt Disabled
 *  0b1..Interrupt Enabled
 */
#define USBNC_USB_OTGn_CTRL_WIE(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WIE_SHIFT)) & USBNC_USB_OTGn_CTRL_WIE_MASK)

#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK      (0x4000U)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT     (14U)
/*! WKUP_SW_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTGn_CTRL_WKUP_SW_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WKUP_SW_EN_SHIFT)) & USBNC_USB_OTGn_CTRL_WKUP_SW_EN_MASK)

#define USBNC_USB_OTGn_CTRL_WKUP_SW_MASK         (0x8000U)
#define USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT        (15U)
/*! WKUP_SW
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_USB_OTGn_CTRL_WKUP_SW(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WKUP_SW_SHIFT)) & USBNC_USB_OTGn_CTRL_WKUP_SW_MASK)

#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_MASK      (0x10000U)
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN_SHIFT     (16U)
/*! WKUP_ID_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTGn_CTRL_WKUP_ID_EN(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WKUP_ID_EN_SHIFT)) & USBNC_USB_OTGn_CTRL_WKUP_ID_EN_MASK)

#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK    (0x20000U)
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT   (17U)
/*! WKUP_VBUS_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_SHIFT)) & USBNC_USB_OTGn_CTRL_WKUP_VBUS_EN_MASK)

#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK    (0x20000000U)
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT   (29U)
/*! WKUP_DPDM_EN
 *  0b0..DPDM changes wake-up to be disabled only when VBUS is 0.
 *  0b1..(Default) DPDM changes wake-up to be enabled, it is for device only.
 */
#define USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_SHIFT)) & USBNC_USB_OTGn_CTRL_WKUP_DPDM_EN_MASK)

#define USBNC_USB_OTGn_CTRL_WIR_MASK             (0x80000000U)
#define USBNC_USB_OTGn_CTRL_WIR_SHIFT            (31U)
/*! WIR
 *  0b0..No wake-up interrupt request received
 *  0b1..Wake-up Interrupt Request received
 */
#define USBNC_USB_OTGn_CTRL_WIR(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_CTRL_WIR_SHIFT)) & USBNC_USB_OTGn_CTRL_WIR_MASK)
/*! @} */

/*! @name USB_OTGn_PHY_CTRL_0 - OTG1 UTMI PHY Control 0 Register */
/*! @{ */

#define USBNC_USB_OTGn_PHY_CTRL_0_UTMI_CLK_VLD_MASK (0x80000000U)
#define USBNC_USB_OTGn_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT (31U)
/*! UTMI_CLK_VLD
 *  0b0..Invalid
 *  0b1..Valid
 */
#define USBNC_USB_OTGn_PHY_CTRL_0_UTMI_CLK_VLD(x) (((uint32_t)(((uint32_t)(x)) << USBNC_USB_OTGn_PHY_CTRL_0_UTMI_CLK_VLD_SHIFT)) & USBNC_USB_OTGn_PHY_CTRL_0_UTMI_CLK_VLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBNC_Register_Masks */

/* Backward compatibility */
#define USBNC_STACK_BASE_ADDRS                   { USBNC1_BASE, USBNC2_BASE }


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
#elif defined(__CWCC__)
  #pragma pop
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

