/*
** ###################################################################
**     Processors:          MIMXRT1041DFP6B
**                          MIMXRT1041DJM6B
**                          MIMXRT1041XFP5B
**                          MIMXRT1041XJM5B
**                          MIMXRT1042DFP6B
**                          MIMXRT1042DJM6B
**                          MIMXRT1042XFP5B
**                          MIMXRT1042XJM5B
**                          MIMXRT1043DFP6B
**                          MIMXRT1043XFP5B
**                          MIMXRT1046DFQ6B
**                          MIMXRT1046XFQ5B
**
**     Version:             rev. 0.1, 2021-07-20
**     Build:               b241021
**
**     Abstract:
**         CMSIS Peripheral Access Layer for USBNC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2021-07-20)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file USBNC.h
 * @version 0.1
 * @date 2021-07-20
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(USBNC_H_)
#define USBNC_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1041DFP6B) || defined(CPU_MIMXRT1041DJM6B) || defined(CPU_MIMXRT1041XFP5B) || defined(CPU_MIMXRT1041XJM5B))
#include "MIMXRT1041_COMMON.h"
#elif (defined(CPU_MIMXRT1042DFP6B) || defined(CPU_MIMXRT1042DJM6B) || defined(CPU_MIMXRT1042XFP5B) || defined(CPU_MIMXRT1042XJM5B))
#include "MIMXRT1042_COMMON.h"
#elif (defined(CPU_MIMXRT1043DFP6B) || defined(CPU_MIMXRT1043XFP5B))
#include "MIMXRT1043_COMMON.h"
#elif (defined(CPU_MIMXRT1046DFQ6B) || defined(CPU_MIMXRT1046XFQ5B))
#include "MIMXRT1046_COMMON.h"
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


#endif  /* USBNC_H_ */

