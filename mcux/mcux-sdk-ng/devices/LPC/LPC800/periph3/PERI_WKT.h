/*
** ###################################################################
**     Processors:          LPC864M201JBD64
**                          LPC864M201JHI33
**                          LPC864M201JHI48
**                          LPC865M201JBD64
**                          LPC865M201JHI33
**                          LPC865M201JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WKT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.0 (2021-07-15)
**         Initial version.
**     - rev. 1.0 (2022-03-15)
**         Revesion of Rev. 1.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WKT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WKT
 *
 * CMSIS Peripheral Access Layer for WKT
 */

#if !defined(PERI_WKT_H_)
#define PERI_WKT_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC864M201JBD64) || defined(CPU_LPC864M201JHI33) || defined(CPU_LPC864M201JHI48))
#include "LPC864_COMMON.h"
#elif (defined(CPU_LPC865M201JBD64) || defined(CPU_LPC865M201JHI33) || defined(CPU_LPC865M201JHI48))
#include "LPC865_COMMON.h"
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
   -- WKT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKT_Peripheral_Access_Layer WKT Peripheral Access Layer
 * @{
 */

/** WKT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Self wake-up timer control register., offset: 0x0 */
       uint8_t RESERVED_0[8];
  __IO uint32_t COUNT;                             /**< Counter register., offset: 0xC */
} WKT_Type;

/* ----------------------------------------------------------------------------
   -- WKT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WKT_Register_Masks WKT Register Masks
 * @{
 */

/*! @name CTRL - Self wake-up timer control register. */
/*! @{ */

#define WKT_CTRL_CLKSEL_MASK                     (0x1U)
#define WKT_CTRL_CLKSEL_SHIFT                    (0U)
/*! CLKSEL - Select the self wake-up timer clock source. Remark: This bit only has an effect if the SEL_EXTCLK bit is not set.
 *  0b0..Divided FRO clock. This clock runs at 750 kHz and provides time-out periods of up to approximately 95
 *       minutes in 1.33 us increments. Remark: This clock is not available in not available in Deep-sleep,
 *       power-down, deep power-down modes. Do not select this option if the timer is to be used to wake up from one of these
 *       modes.
 *  0b1..This is the (nominally) 10 kHz clock and provides time-out periods of up to approximately 119 hours in
 *       100 us increments. The accuracy of this clock is limited to +/- 40 % over temperature and processing.
 *       Remark: This clock is available in all power modes. Prior to use, the low-power oscillator must be enabled. The
 *       oscillator must also be set to remain active in Deep power-down if needed.
 */
#define WKT_CTRL_CLKSEL(x)                       (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_CLKSEL_SHIFT)) & WKT_CTRL_CLKSEL_MASK)

#define WKT_CTRL_ALARMFLAG_MASK                  (0x2U)
#define WKT_CTRL_ALARMFLAG_SHIFT                 (1U)
/*! ALARMFLAG - Wake-up or alarm timer flag.
 *  0b0..No time-out. The self wake-up timer has not timed out. Writing a 0 to has no effect.
 *  0b1..Time-out. The self wake-up timer has timed out. This flag generates an interrupt request which can wake
 *       up the part from any reduced power mode including Deep power-down if the clock source is the low power
 *       oscillator. Writing a 1 clears this status bit.
 */
#define WKT_CTRL_ALARMFLAG(x)                    (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_ALARMFLAG_SHIFT)) & WKT_CTRL_ALARMFLAG_MASK)

#define WKT_CTRL_CLEARCTR_MASK                   (0x4U)
#define WKT_CTRL_CLEARCTR_SHIFT                  (2U)
/*! CLEARCTR - Clears the self wake-up timer.
 *  0b0..No effect. Reading this bit always returns 0.
 *  0b1..Clear the counter. Counting is halted until a new count value is loaded.
 */
#define WKT_CTRL_CLEARCTR(x)                     (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_CLEARCTR_SHIFT)) & WKT_CTRL_CLEARCTR_MASK)

#define WKT_CTRL_SEL_EXTCLK_MASK                 (0x8U)
#define WKT_CTRL_SEL_EXTCLK_SHIFT                (3U)
/*! SEL_EXTCLK - Select external or internal clock source for the self wake-up timer. The internal
 *    clock source is selected by the CLKSEL bit in this register if SET_EXTCLK is set to internal.
 *  0b0..Internal. The clock source is the internal clock selected by the CLKSEL bit.
 *  0b1..External. The self wake-up timer uses the external WKTCLKIN pin.
 */
#define WKT_CTRL_SEL_EXTCLK(x)                   (((uint32_t)(((uint32_t)(x)) << WKT_CTRL_SEL_EXTCLK_SHIFT)) & WKT_CTRL_SEL_EXTCLK_MASK)
/*! @} */

/*! @name COUNT - Counter register. */
/*! @{ */

#define WKT_COUNT_VALUE_MASK                     (0xFFFFFFFFU)
#define WKT_COUNT_VALUE_SHIFT                    (0U)
/*! VALUE - A write to this register pre-loads start count value into the timer and starts the
 *    count-down sequence. A read reflects the current value of the timer.
 */
#define WKT_COUNT_VALUE(x)                       (((uint32_t)(((uint32_t)(x)) << WKT_COUNT_VALUE_SHIFT)) & WKT_COUNT_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WKT_Register_Masks */


/*!
 * @}
 */ /* end of group WKT_Peripheral_Access_Layer */


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


#endif  /* PERI_WKT_H_ */

