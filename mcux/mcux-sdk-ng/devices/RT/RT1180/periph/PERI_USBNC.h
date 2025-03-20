/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181XVP2B
**                          MIMXRT1182CVP2B
**                          MIMXRT1182XVP2B
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**
**     Version:             rev. 2.0, 2024-01-18
**     Build:               b240705
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
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**
** ###################################################################
*/

/*!
 * @file USBNC.h
 * @version 2.0
 * @date 2024-01-18
 * @brief CMSIS Peripheral Access Layer for USBNC
 *
 * CMSIS Peripheral Access Layer for USBNC
 */

#if !defined(USBNC_H_)
#define USBNC_H_                                 /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181XVP2B))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182XVP2B))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
  __IO uint32_t CTRL1;                             /**< USB OTG Control 1 Register, offset: 0x0 */
  __IO uint32_t CTRL2;                             /**< USB OTG Control 2 Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t HSIC_CTRL;                         /**< USB Host HSIC Control Register, offset: 0x10 */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name CTRL1 - USB OTG Control 1 Register */
/*! @{ */

#define USBNC_CTRL1_OVER_CUR_DIS_MASK            (0x80U)
#define USBNC_CTRL1_OVER_CUR_DIS_SHIFT           (7U)
/*! OVER_CUR_DIS - OVER_CUR_DIS
 *  0b1..Disables overcurrent detection
 *  0b0..Enables overcurrent detection
 */
#define USBNC_CTRL1_OVER_CUR_DIS(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_CTRL1_OVER_CUR_POL_MASK            (0x100U)
#define USBNC_CTRL1_OVER_CUR_POL_SHIFT           (8U)
/*! OVER_CUR_POL - OVER_CUR_POL
 *  0b1..Low active (low on this signal represents an overcurrent condition)
 *  0b0..High active (high on this signal represents an overcurrent condition)
 */
#define USBNC_CTRL1_OVER_CUR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_CTRL1_PWR_POL_MASK                 (0x200U)
#define USBNC_CTRL1_PWR_POL_SHIFT                (9U)
/*! PWR_POL - PWR_POL
 *  0b1..PMIC Power Pin is High active.
 *  0b0..PMIC Power Pin is Low active.
 */
#define USBNC_CTRL1_PWR_POL(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_PWR_POL_SHIFT)) & USBNC_CTRL1_PWR_POL_MASK)

#define USBNC_CTRL1_WIE_MASK                     (0x400U)
#define USBNC_CTRL1_WIE_SHIFT                    (10U)
/*! WIE - WIE
 *  0b1..Interrupt Enabled
 *  0b0..Interrupt Disabled
 */
#define USBNC_CTRL1_WIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIE_SHIFT)) & USBNC_CTRL1_WIE_MASK)

#define USBNC_CTRL1_WKUP_SW_EN_MASK              (0x4000U)
#define USBNC_CTRL1_WKUP_SW_EN_SHIFT             (14U)
/*! WKUP_SW_EN - WKUP_SW_EN
 *  0b1..Enable
 *  0b0..Disable
 */
#define USBNC_CTRL1_WKUP_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_CTRL1_WKUP_SW_MASK                 (0x8000U)
#define USBNC_CTRL1_WKUP_SW_SHIFT                (15U)
/*! WKUP_SW - WKUP_SW
 *  0b1..Force wake-up
 *  0b0..Inactive
 */
#define USBNC_CTRL1_WKUP_SW(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_SHIFT)) & USBNC_CTRL1_WKUP_SW_MASK)

#define USBNC_CTRL1_WKUP_ID_EN_MASK              (0x10000U)
#define USBNC_CTRL1_WKUP_ID_EN_SHIFT             (16U)
/*! WKUP_ID_EN - WKUP_ID_EN
 *  0b1..Enable
 *  0b0..Disable
 */
#define USBNC_CTRL1_WKUP_ID_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_ID_EN_SHIFT)) & USBNC_CTRL1_WKUP_ID_EN_MASK)

#define USBNC_CTRL1_WKUP_VBUS_EN_MASK            (0x20000U)
#define USBNC_CTRL1_WKUP_VBUS_EN_SHIFT           (17U)
/*! WKUP_VBUS_EN - WKUP_VBUS_EN
 *  0b1..Enable
 *  0b0..Disable
 */
#define USBNC_CTRL1_WKUP_VBUS_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_CTRL1_WKUP_DPDM_EN_MASK            (0x20000000U)
#define USBNC_CTRL1_WKUP_DPDM_EN_SHIFT           (29U)
/*! WKUP_DPDM_EN - Wake-up on DP/DM change enable
 *  0b1..(Default) DP/DM changes wake-up to be enabled, it is for device only.
 *  0b0..DP/DM changes wake-up to be disabled only when VBUS is 0.
 */
#define USBNC_CTRL1_WKUP_DPDM_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_CTRL1_WIR_MASK                     (0x80000000U)
#define USBNC_CTRL1_WIR_SHIFT                    (31U)
/*! WIR - WIR
 *  0b1..Wake-up Interrupt Request received
 *  0b0..No wake-up interrupt request received
 */
#define USBNC_CTRL1_WIR(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIR_SHIFT)) & USBNC_CTRL1_WIR_MASK)
/*! @} */

/*! @name CTRL2 - USB OTG Control 2 Register */
/*! @{ */

#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK         (0x3U)
#define USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT        (0U)
/*! VBUS_SOURCE_SEL - VBUS_SOURCE_SEL
 *  0b00..vbus_valid
 *  0b01..sess_valid
 *  0b10..sess_valid
 *  0b11..sess_valid
 */
#define USBNC_CTRL2_VBUS_SOURCE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_CTRL2_AUTURESUME_EN_MASK           (0x4U)
#define USBNC_CTRL2_AUTURESUME_EN_SHIFT          (2U)
/*! AUTURESUME_EN - Auto Resume Enable
 *  0b0..Default
 */
#define USBNC_CTRL2_AUTURESUME_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_AUTURESUME_EN_SHIFT)) & USBNC_CTRL2_AUTURESUME_EN_MASK)

#define USBNC_CTRL2_LOWSPEED_EN_MASK             (0x8U)
#define USBNC_CTRL2_LOWSPEED_EN_SHIFT            (3U)
/*! LOWSPEED_EN - LOWSPEED_EN
 *  0b0..Default
 */
#define USBNC_CTRL2_LOWSPEED_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_LOWSPEED_EN_SHIFT)) & USBNC_CTRL2_LOWSPEED_EN_MASK)

#define USBNC_CTRL2_SHORT_PKT_EN_MASK            (0x800000U)
#define USBNC_CTRL2_SHORT_PKT_EN_SHIFT           (23U)
/*! SHORT_PKT_EN - Short Packet Interrupt
 *  0b0..Default
 */
#define USBNC_CTRL2_SHORT_PKT_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_SHORT_PKT_EN_SHIFT)) & USBNC_CTRL2_SHORT_PKT_EN_MASK)

#define USBNC_CTRL2_UTMI_CLK_VLD_MASK            (0x80000000U)
#define USBNC_CTRL2_UTMI_CLK_VLD_SHIFT           (31U)
/*! UTMI_CLK_VLD - UTMI_CLK_VLD
 *  0b0..Default
 */
#define USBNC_CTRL2_UTMI_CLK_VLD(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name HSIC_CTRL - USB Host HSIC Control Register */
/*! @{ */

#define USBNC_HSIC_CTRL_HSIC_CLK_ON_MASK         (0x800U)
#define USBNC_HSIC_CTRL_HSIC_CLK_ON_SHIFT        (11U)
/*! HSIC_CLK_ON - HSIC_CLK_ON
 *  0b1..Active
 *  0b0..Inactive
 */
#define USBNC_HSIC_CTRL_HSIC_CLK_ON(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_HSIC_CLK_ON_SHIFT)) & USBNC_HSIC_CTRL_HSIC_CLK_ON_MASK)

#define USBNC_HSIC_CTRL_HSIC_EN_MASK             (0x1000U)
#define USBNC_HSIC_CTRL_HSIC_EN_SHIFT            (12U)
/*! HSIC_EN - HSIC_EN
 *  0b1..Enabled
 *  0b0..Disabled
 */
#define USBNC_HSIC_CTRL_HSIC_EN(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_HSIC_EN_SHIFT)) & USBNC_HSIC_CTRL_HSIC_EN_MASK)

#define USBNC_HSIC_CTRL_CLK_VLD_MASK             (0x80000000U)
#define USBNC_HSIC_CTRL_CLK_VLD_SHIFT            (31U)
/*! CLK_VLD - CLK_VLD
 *  0b1..Valid
 *  0b0..Invalid
 */
#define USBNC_HSIC_CTRL_CLK_VLD(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_HSIC_CTRL_CLK_VLD_SHIFT)) & USBNC_HSIC_CTRL_CLK_VLD_MASK)
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


#endif  /* USBNC_H_ */

