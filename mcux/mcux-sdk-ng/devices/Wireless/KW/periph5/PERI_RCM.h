/*
** ###################################################################
**     Processors:          MKW21Z256VHT4
**                          MKW21Z512VHT4
**                          MKW31Z256VHT4
**                          MKW31Z512CAT4
**                          MKW31Z512VHT4
**                          MKW41Z256VHT4
**                          MKW41Z512CAT4
**                          MKW41Z512VHT4
**
**     Version:             rev. 1.0, 2015-09-23
**     Build:               b240710
**
**     Abstract:
**         CMSIS Peripheral Access Layer for RCM
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2015-09-23)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file RCM.h
 * @version 1.0
 * @date 2015-09-23
 * @brief CMSIS Peripheral Access Layer for RCM
 *
 * CMSIS Peripheral Access Layer for RCM
 */

#if !defined(RCM_H_)
#define RCM_H_                                   /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKW21Z256VHT4) || defined(CPU_MKW21Z512VHT4))
#include "MKW21Z4_COMMON.h"
#elif (defined(CPU_MKW31Z256VHT4) || defined(CPU_MKW31Z512CAT4) || defined(CPU_MKW31Z512VHT4))
#include "MKW31Z4_COMMON.h"
#elif (defined(CPU_MKW41Z256VHT4) || defined(CPU_MKW41Z512CAT4) || defined(CPU_MKW41Z512VHT4))
#include "MKW41Z4_COMMON.h"
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
   -- RCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Peripheral_Access_Layer RCM Peripheral Access Layer
 * @{
 */

/** RCM - Register Layout Typedef */
typedef struct {
  __I  uint8_t SRS0;                               /**< System Reset Status Register 0, offset: 0x0 */
  __I  uint8_t SRS1;                               /**< System Reset Status Register 1, offset: 0x1 */
       uint8_t RESERVED_0[2];
  __IO uint8_t RPFC;                               /**< Reset Pin Filter Control register, offset: 0x4 */
  __IO uint8_t RPFW;                               /**< Reset Pin Filter Width register, offset: 0x5 */
} RCM_Type;

/* ----------------------------------------------------------------------------
   -- RCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RCM_Register_Masks RCM Register Masks
 * @{
 */

/*! @name SRS0 - System Reset Status Register 0 */
/*! @{ */

#define RCM_SRS0_WAKEUP_MASK                     (0x1U)
#define RCM_SRS0_WAKEUP_SHIFT                    (0U)
/*! WAKEUP - Low Leakage Wakeup Reset
 *  0b0..Reset not caused by LLWU module wakeup source
 *  0b1..Reset caused by LLWU module wakeup source
 */
#define RCM_SRS0_WAKEUP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_WAKEUP_SHIFT)) & RCM_SRS0_WAKEUP_MASK)

#define RCM_SRS0_LVD_MASK                        (0x2U)
#define RCM_SRS0_LVD_SHIFT                       (1U)
/*! LVD - Low-Voltage Detect Reset
 *  0b0..Reset not caused by LVD trip or POR
 *  0b1..Reset caused by LVD trip or POR
 */
#define RCM_SRS0_LVD(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_LVD_SHIFT)) & RCM_SRS0_LVD_MASK)

#define RCM_SRS0_LOC_MASK                        (0x4U)
#define RCM_SRS0_LOC_SHIFT                       (2U)
/*! LOC - Loss-of-Clock Reset
 *  0b0..Reset not caused by a loss of external clock.
 *  0b1..Reset caused by a loss of external clock.
 */
#define RCM_SRS0_LOC(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_LOC_SHIFT)) & RCM_SRS0_LOC_MASK)

#define RCM_SRS0_WDOG_MASK                       (0x20U)
#define RCM_SRS0_WDOG_SHIFT                      (5U)
/*! WDOG - Watchdog
 *  0b0..Reset not caused by watchdog timeout
 *  0b1..Reset caused by watchdog timeout
 */
#define RCM_SRS0_WDOG(x)                         (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_WDOG_SHIFT)) & RCM_SRS0_WDOG_MASK)

#define RCM_SRS0_PIN_MASK                        (0x40U)
#define RCM_SRS0_PIN_SHIFT                       (6U)
/*! PIN - External Reset Pin
 *  0b0..Reset not caused by external reset pin
 *  0b1..Reset caused by external reset pin
 */
#define RCM_SRS0_PIN(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_PIN_SHIFT)) & RCM_SRS0_PIN_MASK)

#define RCM_SRS0_POR_MASK                        (0x80U)
#define RCM_SRS0_POR_SHIFT                       (7U)
/*! POR - Power-On Reset
 *  0b0..Reset not caused by POR
 *  0b1..Reset caused by POR
 */
#define RCM_SRS0_POR(x)                          (((uint8_t)(((uint8_t)(x)) << RCM_SRS0_POR_SHIFT)) & RCM_SRS0_POR_MASK)
/*! @} */

/*! @name SRS1 - System Reset Status Register 1 */
/*! @{ */

#define RCM_SRS1_LOCKUP_MASK                     (0x2U)
#define RCM_SRS1_LOCKUP_SHIFT                    (1U)
/*! LOCKUP - Core Lockup
 *  0b0..Reset not caused by core LOCKUP event
 *  0b1..Reset caused by core LOCKUP event
 */
#define RCM_SRS1_LOCKUP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_LOCKUP_SHIFT)) & RCM_SRS1_LOCKUP_MASK)

#define RCM_SRS1_SW_MASK                         (0x4U)
#define RCM_SRS1_SW_SHIFT                        (2U)
/*! SW - Software
 *  0b0..Reset not caused by software setting of SYSRESETREQ bit
 *  0b1..Reset caused by software setting of SYSRESETREQ bit
 */
#define RCM_SRS1_SW(x)                           (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_SW_SHIFT)) & RCM_SRS1_SW_MASK)

#define RCM_SRS1_MDM_AP_MASK                     (0x8U)
#define RCM_SRS1_MDM_AP_SHIFT                    (3U)
/*! MDM_AP - MDM-AP System Reset Request
 *  0b0..Reset not caused by host debugger system setting of the System Reset Request bit
 *  0b1..Reset caused by host debugger system setting of the System Reset Request bit
 */
#define RCM_SRS1_MDM_AP(x)                       (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_MDM_AP_SHIFT)) & RCM_SRS1_MDM_AP_MASK)

#define RCM_SRS1_SACKERR_MASK                    (0x20U)
#define RCM_SRS1_SACKERR_SHIFT                   (5U)
/*! SACKERR - Stop Mode Acknowledge Error Reset
 *  0b0..Reset not caused by peripheral failure to acknowledge attempt to enter stop mode
 *  0b1..Reset caused by peripheral failure to acknowledge attempt to enter stop mode
 */
#define RCM_SRS1_SACKERR(x)                      (((uint8_t)(((uint8_t)(x)) << RCM_SRS1_SACKERR_SHIFT)) & RCM_SRS1_SACKERR_MASK)
/*! @} */

/*! @name RPFC - Reset Pin Filter Control register */
/*! @{ */

#define RCM_RPFC_RSTFLTSRW_MASK                  (0x3U)
#define RCM_RPFC_RSTFLTSRW_SHIFT                 (0U)
/*! RSTFLTSRW - Reset Pin Filter Select in Run and Wait Modes
 *  0b00..All filtering disabled
 *  0b01..Bus clock filter enabled for normal operation
 *  0b10..LPO clock filter enabled for normal operation
 *  0b11..Reserved
 */
#define RCM_RPFC_RSTFLTSRW(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSRW_SHIFT)) & RCM_RPFC_RSTFLTSRW_MASK)

#define RCM_RPFC_RSTFLTSS_MASK                   (0x4U)
#define RCM_RPFC_RSTFLTSS_SHIFT                  (2U)
/*! RSTFLTSS - Reset Pin Filter Select in Stop Mode
 *  0b0..All filtering disabled
 *  0b1..LPO clock filter enabled
 */
#define RCM_RPFC_RSTFLTSS(x)                     (((uint8_t)(((uint8_t)(x)) << RCM_RPFC_RSTFLTSS_SHIFT)) & RCM_RPFC_RSTFLTSS_MASK)
/*! @} */

/*! @name RPFW - Reset Pin Filter Width register */
/*! @{ */

#define RCM_RPFW_RSTFLTSEL_MASK                  (0x1FU)
#define RCM_RPFW_RSTFLTSEL_SHIFT                 (0U)
/*! RSTFLTSEL - Reset Pin Filter Bus Clock Select
 *  0b00000..Bus clock filter count is 1
 *  0b00001..Bus clock filter count is 2
 *  0b00010..Bus clock filter count is 3
 *  0b00011..Bus clock filter count is 4
 *  0b00100..Bus clock filter count is 5
 *  0b00101..Bus clock filter count is 6
 *  0b00110..Bus clock filter count is 7
 *  0b00111..Bus clock filter count is 8
 *  0b01000..Bus clock filter count is 9
 *  0b01001..Bus clock filter count is 10
 *  0b01010..Bus clock filter count is 11
 *  0b01011..Bus clock filter count is 12
 *  0b01100..Bus clock filter count is 13
 *  0b01101..Bus clock filter count is 14
 *  0b01110..Bus clock filter count is 15
 *  0b01111..Bus clock filter count is 16
 *  0b10000..Bus clock filter count is 17
 *  0b10001..Bus clock filter count is 18
 *  0b10010..Bus clock filter count is 19
 *  0b10011..Bus clock filter count is 20
 *  0b10100..Bus clock filter count is 21
 *  0b10101..Bus clock filter count is 22
 *  0b10110..Bus clock filter count is 23
 *  0b10111..Bus clock filter count is 24
 *  0b11000..Bus clock filter count is 25
 *  0b11001..Bus clock filter count is 26
 *  0b11010..Bus clock filter count is 27
 *  0b11011..Bus clock filter count is 28
 *  0b11100..Bus clock filter count is 29
 *  0b11101..Bus clock filter count is 30
 *  0b11110..Bus clock filter count is 31
 *  0b11111..Bus clock filter count is 32
 */
#define RCM_RPFW_RSTFLTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << RCM_RPFW_RSTFLTSEL_SHIFT)) & RCM_RPFW_RSTFLTSEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RCM_Register_Masks */


/*!
 * @}
 */ /* end of group RCM_Peripheral_Access_Layer */


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


#endif  /* RCM_H_ */

