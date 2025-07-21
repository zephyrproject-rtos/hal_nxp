/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
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
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
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

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
  __IO uint32_t CTRL1;                             /**< USB Control 1, offset: 0x0 */
  __IO uint32_t CTRL2;                             /**< USB Control 2, offset: 0x4 */
       uint8_t RESERVED_0[152];
  __IO uint32_t LPM_CSR0;                          /**< USB LPM Control and Status 0, offset: 0xA0 */
  __IO uint32_t LPM_CSR1;                          /**< USB LPM Control and Status 1, offset: 0xA4 */
  __IO uint32_t LPM_CSR2;                          /**< USB LPM Control and Status 2, offset: 0xA8 */
       uint8_t RESERVED_1[84];
  __IO uint32_t EUSB_CTRL0;                        /**< eUSB Control 0, offset: 0x100, available only on: USBNC1 (missing on USBNC0) */
  __IO uint32_t EUSB_CTRL1;                        /**< eUSB Control 1, offset: 0x104, available only on: USBNC1 (missing on USBNC0) */
       uint8_t RESERVED_2[4];
  __IO uint32_t EUSB_CTRL3;                        /**< eUSB Control 3, offset: 0x10C, available only on: USBNC1 (missing on USBNC0) */
       uint8_t RESERVED_3[56];
  __IO uint32_t EUSB_RAP;                          /**< eUSB RAP Control and Status, offset: 0x148, available only on: USBNC1 (missing on USBNC0) */
} USBNC_Type;

/* ----------------------------------------------------------------------------
   -- USBNC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBNC_Register_Masks USBNC Register Masks
 * @{
 */

/*! @name CTRL1 - USB Control 1 */
/*! @{ */

#define USBNC_CTRL1_OVER_CUR_DIS_MASK            (0x80U)
#define USBNC_CTRL1_OVER_CUR_DIS_SHIFT           (7U)
/*! OVER_CUR_DIS - Overcurrent Disable
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBNC_CTRL1_OVER_CUR_DIS(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_DIS_SHIFT)) & USBNC_CTRL1_OVER_CUR_DIS_MASK)

#define USBNC_CTRL1_OVER_CUR_POL_MASK            (0x100U)
#define USBNC_CTRL1_OVER_CUR_POL_SHIFT           (8U)
/*! OVER_CUR_POL - Overcurrent Polarity
 *  0b0..Active high
 *  0b1..Active low
 */
#define USBNC_CTRL1_OVER_CUR_POL(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_OVER_CUR_POL_SHIFT)) & USBNC_CTRL1_OVER_CUR_POL_MASK)

#define USBNC_CTRL1_PWR_POL_MASK                 (0x200U)
#define USBNC_CTRL1_PWR_POL_SHIFT                (9U)
/*! PWR_POL - Power Polarity
 *  0b0..Active low
 *  0b1..Active high
 */
#define USBNC_CTRL1_PWR_POL(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_PWR_POL_SHIFT)) & USBNC_CTRL1_PWR_POL_MASK)

#define USBNC_CTRL1_WIE_MASK                     (0x400U)
#define USBNC_CTRL1_WIE_SHIFT                    (10U)
/*! WIE - Wake-Up Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WIE(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIE_SHIFT)) & USBNC_CTRL1_WIE_MASK)

#define USBNC_CTRL1_WKUP_SW_EN_MASK              (0x4000U)
#define USBNC_CTRL1_WKUP_SW_EN_SHIFT             (14U)
/*! WKUP_SW_EN - Software Wake-Up Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WKUP_SW_EN(x)                (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_EN_SHIFT)) & USBNC_CTRL1_WKUP_SW_EN_MASK)

#define USBNC_CTRL1_WKUP_SW_MASK                 (0x8000U)
#define USBNC_CTRL1_WKUP_SW_SHIFT                (15U)
/*! WKUP_SW - Software Wake-Up
 *  0b0..Inactive
 *  0b1..Force wake-up
 */
#define USBNC_CTRL1_WKUP_SW(x)                   (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_SW_SHIFT)) & USBNC_CTRL1_WKUP_SW_MASK)

#define USBNC_CTRL1_WKUP_VBUS_EN_MASK            (0x20000U)
#define USBNC_CTRL1_WKUP_VBUS_EN_SHIFT           (17U)
/*! WKUP_VBUS_EN - Wake-Up After VBUS Change Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_WKUP_VBUS_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_VBUS_EN_SHIFT)) & USBNC_CTRL1_WKUP_VBUS_EN_MASK)

#define USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK        (0x10000000U)
#define USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT       (28U)
/*! REMOTE_WAKEUP_EN - Remote Wake-Up Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_CTRL1_REMOTE_WAKEUP_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_REMOTE_WAKEUP_EN_SHIFT)) & USBNC_CTRL1_REMOTE_WAKEUP_EN_MASK)

#define USBNC_CTRL1_WKUP_DPDM_EN_MASK            (0x20000000U)
#define USBNC_CTRL1_WKUP_DPDM_EN_SHIFT           (29U)
/*! WKUP_DPDM_EN - Wake-Up After DP or DM Change Enable
 *  0b0..Disable only when VBUS is invalid
 *  0b1..Enable (default)
 */
#define USBNC_CTRL1_WKUP_DPDM_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WKUP_DPDM_EN_SHIFT)) & USBNC_CTRL1_WKUP_DPDM_EN_MASK)

#define USBNC_CTRL1_WIR_MASK                     (0x80000000U)
#define USBNC_CTRL1_WIR_SHIFT                    (31U)
/*! WIR - Wake-Up Interrupt Request
 *  0b0..Not received
 *  0b1..Received
 */
#define USBNC_CTRL1_WIR(x)                       (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL1_WIR_SHIFT)) & USBNC_CTRL1_WIR_MASK)
/*! @} */

/*! @name CTRL2 - USB Control 2 */
/*! @{ */

#define USBNC_CTRL2_VBUS_SOURCE_SEL_MASK         (0x3U)
#define USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT        (0U)
/*! VBUS_SOURCE_SEL - VBUS Source Select
 *  0b00..vbus_valid
 *  0b01..sess_valid
 *  0b10..sess_valid
 *  0b11..sess_valid
 */
#define USBNC_CTRL2_VBUS_SOURCE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_VBUS_SOURCE_SEL_SHIFT)) & USBNC_CTRL2_VBUS_SOURCE_SEL_MASK)

#define USBNC_CTRL2_UTMI_CLK_VLD_MASK            (0x80000000U)
#define USBNC_CTRL2_UTMI_CLK_VLD_SHIFT           (31U)
/*! UTMI_CLK_VLD - UTMI Clock Valid Flag
 *  0b0..No effect
 *  0b0..Not valid
 *  0b1..Clear the flag
 *  0b1..Valid
 */
#define USBNC_CTRL2_UTMI_CLK_VLD(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_CTRL2_UTMI_CLK_VLD_SHIFT)) & USBNC_CTRL2_UTMI_CLK_VLD_MASK)
/*! @} */

/*! @name LPM_CSR0 - USB LPM Control and Status 0 */
/*! @{ */

#define USBNC_LPM_CSR0_LPM_EN_MASK               (0x1U)
#define USBNC_LPM_CSR0_LPM_EN_SHIFT              (0U)
/*! LPM_EN - Link Power Management Feature Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_LPM_CSR0_LPM_EN(x)                 (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_EN_SHIFT)) & USBNC_LPM_CSR0_LPM_EN_MASK)

#define USBNC_LPM_CSR0_LPM_ERRATA_EN_MASK        (0x2U)
#define USBNC_LPM_CSR0_LPM_ERRATA_EN_SHIFT       (1U)
/*! LPM_ERRATA_EN - Link Power Management ECN Errata Feature Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_LPM_CSR0_LPM_ERRATA_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_ERRATA_EN_SHIFT)) & USBNC_LPM_CSR0_LPM_ERRATA_EN_MASK)

#define USBNC_LPM_CSR0_LPM_AUTO_PHCD_MASK        (0x8U)
#define USBNC_LPM_CSR0_LPM_AUTO_PHCD_SHIFT       (3U)
/*! LPM_AUTO_PHCD - Auto Low-Power Mode
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_LPM_CSR0_LPM_AUTO_PHCD(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_AUTO_PHCD_SHIFT)) & USBNC_LPM_CSR0_LPM_AUTO_PHCD_MASK)

#define USBNC_LPM_CSR0_LPM_RESUMEOK_MASK         (0x40000000U)
#define USBNC_LPM_CSR0_LPM_RESUMEOK_SHIFT        (30U)
/*! LPM_RESUMEOK - LPM Resume OK
 *  0b0..Cannot resume
 *  0b1..Can resume
 */
#define USBNC_LPM_CSR0_LPM_RESUMEOK(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_RESUMEOK_SHIFT)) & USBNC_LPM_CSR0_LPM_RESUMEOK_MASK)

#define USBNC_LPM_CSR0_LPM_L1_ACTIVE_MASK        (0x80000000U)
#define USBNC_LPM_CSR0_LPM_L1_ACTIVE_SHIFT       (31U)
/*! LPM_L1_ACTIVE - LPM Active
 *  0b0..Inactive
 *  0b1..Active
 */
#define USBNC_LPM_CSR0_LPM_L1_ACTIVE(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR0_LPM_L1_ACTIVE_SHIFT)) & USBNC_LPM_CSR0_LPM_L1_ACTIVE_MASK)
/*! @} */

/*! @name LPM_CSR1 - USB LPM Control and Status 1 */
/*! @{ */

#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_MASK    (0xFU)
#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_SHIFT   (0U)
/*! LPM_DEV_BESLTHRES - Device Required Host Initiated Resume Duration
 *  0b0000..75 us, if LPM_ERRATA_EN = 1; 50 us, if LPM_ERRATA_EN = 0
 *  0b0001..100 us, if LPM_ERRATA_EN = 1; 125 us, if LPM_ERRATA_EN = 0
 *  0b0010..150 us, if LPM_ERRATA_EN = 1; 200 us, if LPM_ERRATA_EN = 0
 *  0b0011..250 us, if LPM_ERRATA_EN = 1; 275 us, if LPM_ERRATA_EN = 0
 *  0b0100..350 us, if LPM_ERRATA_EN = 1; 350 us, if LPM_ERRATA_EN = 0
 *  0b0101..450 us, if LPM_ERRATA_EN = 1; 425 us, if LPM_ERRATA_EN = 0
 *  0b0110..950 us, if LPM_ERRATA_EN = 1; 500 us, if LPM_ERRATA_EN = 0
 *  0b0111..1950 us, if LPM_ERRATA_EN = 1; 575 us, if LPM_ERRATA_EN = 0
 *  0b1000..2950 us, if LPM_ERRATA_EN = 1; 650 us, if LPM_ERRATA_EN = 0
 *  0b1001..3950 us, if LPM_ERRATA_EN = 1; 725 us, if LPM_ERRATA_EN = 0
 *  0b1010..4950 us, if LPM_ERRATA_EN = 1; 800 us, if LPM_ERRATA_EN = 0
 *  0b1011..5950 us, if LPM_ERRATA_EN = 1; 875 us, if LPM_ERRATA_EN = 0
 *  0b1100..6950 us, if LPM_ERRATA_EN = 1; 950 us, if LPM_ERRATA_EN = 0
 *  0b1101..7950 us, if LPM_ERRATA_EN = 1; 1025 us, if LPM_ERRATA_EN = 0
 *  0b1110..8950 us, if LPM_ERRATA_EN = 1; 1100 us, if LPM_ERRATA_EN = 0
 *  0b1111..9950 us, if LPM_ERRATA_EN = 1; 1175 us, if LPM_ERRATA_EN = 0
 */
#define USBNC_LPM_CSR1_LPM_DEV_BESLTHRES(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_BESLTHRES_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RES_MASK          (0x10U)
#define USBNC_LPM_CSR1_LPM_DEV_RES_SHIFT         (4U)
/*! LPM_DEV_RES - LPM Device Response
 *  0b0..Fourth condition not needed
 *  0b1..Fourth condition needed
 */
#define USBNC_LPM_CSR1_LPM_DEV_RES(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RES_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RES_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_DP_MASK           (0x20U)
#define USBNC_LPM_CSR1_LPM_DEV_DP_SHIFT          (5U)
/*! LPM_DEV_DP - LPM Device Data Pending
 *  0b0..Not pending
 *  0b1..Pending
 */
#define USBNC_LPM_CSR1_LPM_DEV_DP(x)             (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_DP_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_DP_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS_MASK       (0x300000U)
#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS_SHIFT      (20U)
/*! LPM_DEV_RSPSTS - LPM Device Response Status
 *  0b00..Invalid
 *  0b01..ACK
 *  0b10..NYET
 *  0b11..STALL
 */
#define USBNC_LPM_CSR1_LPM_DEV_RSPSTS(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RSPSTS_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RSPSTS_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_MASK    (0x800000U)
#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_SHIFT   (23U)
/*! LPM_DEV_RWKENRCVD - LPM Device Received bRemoteWake
 *  0b0..0
 *  0b1..1
 */
#define USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_RWKENRCVD_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_MASK    (0xF000000U)
#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_SHIFT   (24U)
/*! LPM_DEV_LNKSTRCVD - LPM Device Received bLinkState
 *  0b0000..Reserved for future use
 *  0b0001..L1 (Sleep mode)
 *  0b0010-0b1111..Reserved for future use
 */
#define USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_LNKSTRCVD_MASK)

#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_MASK     (0xF0000000U)
#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_SHIFT    (28U)
/*! LPM_DEV_BESLRCVD - LPM Device Received BESL */
#define USBNC_LPM_CSR1_LPM_DEV_BESLRCVD(x)       (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_SHIFT)) & USBNC_LPM_CSR1_LPM_DEV_BESLRCVD_MASK)
/*! @} */

/*! @name LPM_CSR2 - USB LPM Control and Status 2 */
/*! @{ */

#define USBNC_LPM_CSR2_LPM_HST_SEND_MASK         (0x1U)
#define USBNC_LPM_CSR2_LPM_HST_SEND_SHIFT        (0U)
/*! LPM_HST_SEND - LPM Host Send Extension Token
 *  0b0..LPM transaction did not happen or is complete
 *  0b1..LPM transaction is ongoing
 */
#define USBNC_LPM_CSR2_LPM_HST_SEND(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_SEND_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_SEND_MASK)

#define USBNC_LPM_CSR2_LPM_HST_DEVADD_MASK       (0xFEU)
#define USBNC_LPM_CSR2_LPM_HST_DEVADD_SHIFT      (1U)
/*! LPM_HST_DEVADD - LPM Host Extension Token's Device Address */
#define USBNC_LPM_CSR2_LPM_HST_DEVADD(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_DEVADD_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_DEVADD_MASK)

#define USBNC_LPM_CSR2_LPM_HST_BESL_MASK         (0xF00U)
#define USBNC_LPM_CSR2_LPM_HST_BESL_SHIFT        (8U)
/*! LPM_HST_BESL - LPM Host Extension Token's BESL or HIRD */
#define USBNC_LPM_CSR2_LPM_HST_BESL(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_BESL_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_BESL_MASK)

#define USBNC_LPM_CSR2_LPM_HST_RWKEN_MASK        (0x1000U)
#define USBNC_LPM_CSR2_LPM_HST_RWKEN_SHIFT       (12U)
/*! LPM_HST_RWKEN - LPM Host Extension Token's bRemoteWake
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_LPM_CSR2_LPM_HST_RWKEN(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_RWKEN_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_RWKEN_MASK)

#define USBNC_LPM_CSR2_LPM_HST_STSRCVD_MASK      (0x70000000U)
#define USBNC_LPM_CSR2_LPM_HST_STSRCVD_SHIFT     (28U)
/*! LPM_HST_STSRCVD - LPM Host Response Status from the Device
 *  0b000..Invalid
 *  0b001..ACK
 *  0b010..NYET
 *  0b011..STALL
 *  0b100..Timeout
 *  0b101..ERR
 *  0b110..Reserved
 *  0b111..Reserved
 */
#define USBNC_LPM_CSR2_LPM_HST_STSRCVD(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_LPM_CSR2_LPM_HST_STSRCVD_SHIFT)) & USBNC_LPM_CSR2_LPM_HST_STSRCVD_MASK)
/*! @} */

/*! @name EUSB_CTRL0 - eUSB Control 0 */
/*! @{ */

#define USBNC_EUSB_CTRL0_UN_TERMINATED_MODE_MASK (0x20U)
#define USBNC_EUSB_CTRL0_UN_TERMINATED_MODE_SHIFT (5U)
/*! UN_TERMINATED_MODE - HS Receiver Termination Option
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBNC_EUSB_CTRL0_UN_TERMINATED_MODE(x)   (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL0_UN_TERMINATED_MODE_SHIFT)) & USBNC_EUSB_CTRL0_UN_TERMINATED_MODE_MASK)

#define USBNC_EUSB_CTRL0_PONRST_MASK             (0x40U)
#define USBNC_EUSB_CTRL0_PONRST_SHIFT            (6U)
/*! PONRST - Power-On Reset
 *  0b0..Reset
 *  0b1..Operate normally
 */
#define USBNC_EUSB_CTRL0_PONRST(x)               (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL0_PONRST_SHIFT)) & USBNC_EUSB_CTRL0_PONRST_MASK)

#define USBNC_EUSB_CTRL0_NATIVE_MODE_MASK        (0x80U)
#define USBNC_EUSB_CTRL0_NATIVE_MODE_SHIFT       (7U)
/*! NATIVE_MODE - Mode Select
 *  0b0..Repeater mode
 *  0b1..Native mode
 */
#define USBNC_EUSB_CTRL0_NATIVE_MODE(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL0_NATIVE_MODE_SHIFT)) & USBNC_EUSB_CTRL0_NATIVE_MODE_MASK)

#define USBNC_EUSB_CTRL0_EUSB_DEV_PORT_RST_MASK  (0x1000000U)
#define USBNC_EUSB_CTRL0_EUSB_DEV_PORT_RST_SHIFT (24U)
/*! EUSB_DEV_PORT_RST - Trigger Device Issue Port Reset
 *  0b0..No action
 *  0b1..Trigger device issue port reset
 */
#define USBNC_EUSB_CTRL0_EUSB_DEV_PORT_RST(x)    (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL0_EUSB_DEV_PORT_RST_SHIFT)) & USBNC_EUSB_CTRL0_EUSB_DEV_PORT_RST_MASK)
/*! @} */

/*! @name EUSB_CTRL1 - eUSB Control 1 */
/*! @{ */

#define USBNC_EUSB_CTRL1_EUSB_SQ_MASK            (0xE000U)
#define USBNC_EUSB_CTRL1_EUSB_SQ_SHIFT           (13U)
/*! EUSB_SQ - eUSB Squelch
 *  0b000..66.6mV
 *  0b001..63.2mV
 *  0b010..59.7mV
 *  0b011..56mV
 *  0b100..80.6mV
 *  0b101..76.9mV
 *  0b110..73.5mV
 *  0b111..70mV
 */
#define USBNC_EUSB_CTRL1_EUSB_SQ(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL1_EUSB_SQ_SHIFT)) & USBNC_EUSB_CTRL1_EUSB_SQ_MASK)

#define USBNC_EUSB_CTRL1_EUSB_FSTX_OPT_MASK      (0x180000U)
#define USBNC_EUSB_CTRL1_EUSB_FSTX_OPT_SHIFT     (19U)
/*! EUSB_FSTX_OPT - eUSB Full-Speed TX Option
 *  0b00..Default
 *  0b01..Faster 10%
 *  0b10..Slower 20%
 *  0b11..Slower 10%
 */
#define USBNC_EUSB_CTRL1_EUSB_FSTX_OPT(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL1_EUSB_FSTX_OPT_SHIFT)) & USBNC_EUSB_CTRL1_EUSB_FSTX_OPT_MASK)
/*! @} */

/*! @name EUSB_CTRL3 - eUSB Control 3 */
/*! @{ */

#define USBNC_EUSB_CTRL3_XCfg_U2_SWING_MASK      (0xFU)
#define USBNC_EUSB_CTRL3_XCfg_U2_SWING_SHIFT     (0U)
/*! XCfg_U2_SWING - HSTX swing
 *  0b0000..200mV
 *  0b0001..195.9mV
 *  0b0010..191.7mV
 *  0b0011..187.5mV
 *  0b0100..216.7mV
 *  0b0101..212.5mV
 *  0b0110..208.4mV
 *  0b0111..204.2mV
 *  0b1000..233.4mV
 *  0b1001..229.2mV
 *  0b1010..225mV
 *  0b1011..220.9mV
 *  0b1100..250mV
 *  0b1101..245.9mV
 *  0b1110..241.7mV
 *  0b1111..237.5mV
 */
#define USBNC_EUSB_CTRL3_XCfg_U2_SWING(x)        (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_CTRL3_XCfg_U2_SWING_SHIFT)) & USBNC_EUSB_CTRL3_XCfg_U2_SWING_MASK)
/*! @} */

/*! @name EUSB_RAP - eUSB RAP Control and Status */
/*! @{ */

#define USBNC_EUSB_RAP_CM_RAP_WRDATA_MASK        (0xFFU)
#define USBNC_EUSB_RAP_CM_RAP_WRDATA_SHIFT       (0U)
/*! CM_RAP_WRDATA - CM.RAP Write Data */
#define USBNC_EUSB_RAP_CM_RAP_WRDATA(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_WRDATA_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_WRDATA_MASK)

#define USBNC_EUSB_RAP_CM_RAP_ADDR_MASK          (0x3F00U)
#define USBNC_EUSB_RAP_CM_RAP_ADDR_SHIFT         (8U)
/*! CM_RAP_ADDR - CM.RAP Address */
#define USBNC_EUSB_RAP_CM_RAP_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_ADDR_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_ADDR_MASK)

#define USBNC_EUSB_RAP_CM_RAP_OP_MASK            (0xC000U)
#define USBNC_EUSB_RAP_CM_RAP_OP_SHIFT           (14U)
/*! CM_RAP_OP - CM.RAP Operation Code
 *  0b00..Write; data is written to the register address
 *  0b01..Read; data is read from the register address
 *  0b10..Clear; active-high, bitwise clear with the data on the register address
 *  0b11..Set; bitwise OR with the data on the register address
 */
#define USBNC_EUSB_RAP_CM_RAP_OP(x)              (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_OP_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_OP_MASK)

#define USBNC_EUSB_RAP_CM_RAP_INIT_EN_MASK       (0x10000U)
#define USBNC_EUSB_RAP_CM_RAP_INIT_EN_SHIFT      (16U)
/*! CM_RAP_INIT_EN - Enable CM.RAP Feature
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_EUSB_RAP_CM_RAP_INIT_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_INIT_EN_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_INIT_EN_MASK)

#define USBNC_EUSB_RAP_CM_RAP_START_MASK         (0x20000U)
#define USBNC_EUSB_RAP_CM_RAP_START_SHIFT        (17U)
/*! CM_RAP_START - CM.RAP Start
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBNC_EUSB_RAP_CM_RAP_START(x)           (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_START_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_START_MASK)

#define USBNC_EUSB_RAP_CM_RAP_FAIL_MASK          (0x200000U)
#define USBNC_EUSB_RAP_CM_RAP_FAIL_SHIFT         (21U)
/*! CM_RAP_FAIL - CM.RAP Command Fail
 *  0b0..Not failed
 *  0b1..Failed
 */
#define USBNC_EUSB_RAP_CM_RAP_FAIL(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_FAIL_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_FAIL_MASK)

#define USBNC_EUSB_RAP_CM_RAP_DONE_MASK          (0x400000U)
#define USBNC_EUSB_RAP_CM_RAP_DONE_SHIFT         (22U)
/*! CM_RAP_DONE - CM.RAP Command Done
 *  0b0..Not complete
 *  0b1..Complete
 */
#define USBNC_EUSB_RAP_CM_RAP_DONE(x)            (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_DONE_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_DONE_MASK)

#define USBNC_EUSB_RAP_CM_RAP_INIT_READY_MASK    (0x800000U)
#define USBNC_EUSB_RAP_CM_RAP_INIT_READY_SHIFT   (23U)
/*! CM_RAP_INIT_READY - Host and Device Entering CM.RAP State
 *  0b0..Not ready
 *  0b1..Ready
 */
#define USBNC_EUSB_RAP_CM_RAP_INIT_READY(x)      (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_INIT_READY_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_INIT_READY_MASK)

#define USBNC_EUSB_RAP_CM_RAP_RDDATA_MASK        (0xFF000000U)
#define USBNC_EUSB_RAP_CM_RAP_RDDATA_SHIFT       (24U)
/*! CM_RAP_RDDATA - CM.RAP Read Data */
#define USBNC_EUSB_RAP_CM_RAP_RDDATA(x)          (((uint32_t)(((uint32_t)(x)) << USBNC_EUSB_RAP_CM_RAP_RDDATA_SHIFT)) & USBNC_EUSB_RAP_CM_RAP_RDDATA_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_USBNC_H_ */

