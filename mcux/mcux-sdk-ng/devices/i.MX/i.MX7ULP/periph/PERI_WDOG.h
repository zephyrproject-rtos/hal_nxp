/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 7.0, 2018-11-05
**     Build:               b240708
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WDOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**
** ###################################################################
*/

/*!
 * @file WDOG.h
 * @version 7.0
 * @date 2018-11-05
 * @brief CMSIS Peripheral Access Layer for WDOG
 *
 * CMSIS Peripheral Access Layer for WDOG
 */

#if !defined(WDOG_H_)
#define WDOG_H_                                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint32_t CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  __IO uint32_t TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  __IO uint32_t WIN;                               /**< Watchdog Window Register, offset: 0xC */
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name CS - Watchdog Control and Status Register */
/*! @{ */

#define WDOG_CS_STOP_MASK                        (0x1U)
#define WDOG_CS_STOP_SHIFT                       (0U)
/*! STOP - Stop Enable
 *  0b0..Watchdog disabled in chip stop mode.
 *  0b1..Watchdog enabled in chip stop mode.
 */
#define WDOG_CS_STOP(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_STOP_SHIFT)) & WDOG_CS_STOP_MASK)

#define WDOG_CS_WAIT_MASK                        (0x2U)
#define WDOG_CS_WAIT_SHIFT                       (1U)
/*! WAIT - Wait Enable
 *  0b0..Watchdog disabled in chip wait mode.
 *  0b1..Watchdog enabled in chip wait mode.
 */
#define WDOG_CS_WAIT(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WAIT_SHIFT)) & WDOG_CS_WAIT_MASK)

#define WDOG_CS_DBG_MASK                         (0x4U)
#define WDOG_CS_DBG_SHIFT                        (2U)
/*! DBG - Debug Enable
 *  0b0..Watchdog disabled in chip debug mode.
 *  0b1..Watchdog enabled in chip debug mode.
 */
#define WDOG_CS_DBG(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_DBG_SHIFT)) & WDOG_CS_DBG_MASK)

#define WDOG_CS_TST_MASK                         (0x18U)
#define WDOG_CS_TST_SHIFT                        (3U)
/*! TST - Watchdog Test
 *  0b00..Watchdog test mode disabled.
 *  0b01..Watchdog user mode enabled. (Watchdog test mode disabled.) After testing the watchdog, software should
 *        use this setting to indicate that the watchdog is functioning normally in user mode.
 *  0b10..Watchdog test mode enabled, only the low byte is used. CNT[CNTLOW] is compared with TOVAL[TOVALLOW].
 *  0b11..Watchdog test mode enabled, only the high byte is used. CNT[CNTHIGH] is compared with TOVAL[TOVALHIGH].
 */
#define WDOG_CS_TST(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_TST_SHIFT)) & WDOG_CS_TST_MASK)

#define WDOG_CS_UPDATE_MASK                      (0x20U)
#define WDOG_CS_UPDATE_SHIFT                     (5U)
/*! UPDATE - Allow updates
 *  0b0..Updates not allowed. After the initial configuration, the watchdog cannot be later modified without forcing a reset.
 *  0b1..Updates allowed. Software can modify the watchdog configuration registers within 128 bus clocks after performing the unlock write sequence.
 */
#define WDOG_CS_UPDATE(x)                        (((uint32_t)(((uint32_t)(x)) << WDOG_CS_UPDATE_SHIFT)) & WDOG_CS_UPDATE_MASK)

#define WDOG_CS_INT_MASK                         (0x40U)
#define WDOG_CS_INT_SHIFT                        (6U)
/*! INT - Watchdog Interrupt
 *  0b0..Watchdog interrupts are disabled. Watchdog resets are not delayed.
 *  0b1..Watchdog interrupts are enabled. Watchdog resets are delayed by 128 bus clocks from the interrupt vector fetch.
 */
#define WDOG_CS_INT(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_INT_SHIFT)) & WDOG_CS_INT_MASK)

#define WDOG_CS_EN_MASK                          (0x80U)
#define WDOG_CS_EN_SHIFT                         (7U)
/*! EN - Watchdog Enable
 *  0b0..Watchdog disabled.
 *  0b1..Watchdog enabled.
 */
#define WDOG_CS_EN(x)                            (((uint32_t)(((uint32_t)(x)) << WDOG_CS_EN_SHIFT)) & WDOG_CS_EN_MASK)

#define WDOG_CS_CLK_MASK                         (0x300U)
#define WDOG_CS_CLK_SHIFT                        (8U)
/*! CLK - Watchdog Clock
 *  0b00..Bus clock
 *  0b01..LPO clock
 *  0b10..INTCLK (internal clock)
 *  0b11..ERCLK (external reference clock)
 */
#define WDOG_CS_CLK(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CLK_SHIFT)) & WDOG_CS_CLK_MASK)

#define WDOG_CS_RCS_MASK                         (0x400U)
#define WDOG_CS_RCS_SHIFT                        (10U)
/*! RCS - Reconfiguration Success
 *  0b0..Reconfiguring WDOG.
 *  0b1..Reconfiguration is successful.
 */
#define WDOG_CS_RCS(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_RCS_SHIFT)) & WDOG_CS_RCS_MASK)

#define WDOG_CS_ULK_MASK                         (0x800U)
#define WDOG_CS_ULK_SHIFT                        (11U)
/*! ULK - Unlock status
 *  0b0..WDOG is locked.
 *  0b1..WDOG is unlocked.
 */
#define WDOG_CS_ULK(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_ULK_SHIFT)) & WDOG_CS_ULK_MASK)

#define WDOG_CS_PRES_MASK                        (0x1000U)
#define WDOG_CS_PRES_SHIFT                       (12U)
/*! PRES - Watchdog prescaler
 *  0b0..256 prescaler disabled.
 *  0b1..256 prescaler enabled.
 */
#define WDOG_CS_PRES(x)                          (((uint32_t)(((uint32_t)(x)) << WDOG_CS_PRES_SHIFT)) & WDOG_CS_PRES_MASK)

#define WDOG_CS_CMD32EN_MASK                     (0x2000U)
#define WDOG_CS_CMD32EN_SHIFT                    (13U)
/*! CMD32EN - Enables or disables WDOG support for 32-bit (otherwise 16-bit or 8-bit) refresh/unlock command write words
 *  0b0..Disables support for 32-bit refresh/unlock command write words. Only 16-bit or 8-bit is supported.
 *  0b1..Enables support for 32-bit refresh/unlock command write words. 16-bit or 8-bit is NOT supported.
 */
#define WDOG_CS_CMD32EN(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_CS_CMD32EN_SHIFT)) & WDOG_CS_CMD32EN_MASK)

#define WDOG_CS_FLG_MASK                         (0x4000U)
#define WDOG_CS_FLG_SHIFT                        (14U)
/*! FLG - Watchdog Interrupt Flag
 *  0b0..No interrupt occurred.
 *  0b1..An interrupt occurred.
 */
#define WDOG_CS_FLG(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_FLG_SHIFT)) & WDOG_CS_FLG_MASK)

#define WDOG_CS_WIN_MASK                         (0x8000U)
#define WDOG_CS_WIN_SHIFT                        (15U)
/*! WIN - Watchdog Window
 *  0b0..Window mode disabled.
 *  0b1..Window mode enabled.
 */
#define WDOG_CS_WIN(x)                           (((uint32_t)(((uint32_t)(x)) << WDOG_CS_WIN_SHIFT)) & WDOG_CS_WIN_MASK)
/*! @} */

/*! @name CNT - Watchdog Counter Register */
/*! @{ */

#define WDOG_CNT_CNTLOW_MASK                     (0xFFU)
#define WDOG_CNT_CNTLOW_SHIFT                    (0U)
/*! CNTLOW - Low byte of the Watchdog Counter */
#define WDOG_CNT_CNTLOW(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTLOW_SHIFT)) & WDOG_CNT_CNTLOW_MASK)

#define WDOG_CNT_CNTHIGH_MASK                    (0xFF00U)
#define WDOG_CNT_CNTHIGH_SHIFT                   (8U)
/*! CNTHIGH - High byte of the Watchdog Counter */
#define WDOG_CNT_CNTHIGH(x)                      (((uint32_t)(((uint32_t)(x)) << WDOG_CNT_CNTHIGH_SHIFT)) & WDOG_CNT_CNTHIGH_MASK)
/*! @} */

/*! @name TOVAL - Watchdog Timeout Value Register */
/*! @{ */

#define WDOG_TOVAL_TOVALLOW_MASK                 (0xFFU)
#define WDOG_TOVAL_TOVALLOW_SHIFT                (0U)
/*! TOVALLOW - Low byte of the timeout value */
#define WDOG_TOVAL_TOVALLOW(x)                   (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALLOW_SHIFT)) & WDOG_TOVAL_TOVALLOW_MASK)

#define WDOG_TOVAL_TOVALHIGH_MASK                (0xFF00U)
#define WDOG_TOVAL_TOVALHIGH_SHIFT               (8U)
/*! TOVALHIGH - High byte of the timeout value */
#define WDOG_TOVAL_TOVALHIGH(x)                  (((uint32_t)(((uint32_t)(x)) << WDOG_TOVAL_TOVALHIGH_SHIFT)) & WDOG_TOVAL_TOVALHIGH_MASK)
/*! @} */

/*! @name WIN - Watchdog Window Register */
/*! @{ */

#define WDOG_WIN_WINLOW_MASK                     (0xFFU)
#define WDOG_WIN_WINLOW_SHIFT                    (0U)
/*! WINLOW - Low byte of Watchdog Window */
#define WDOG_WIN_WINLOW(x)                       (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINLOW_SHIFT)) & WDOG_WIN_WINLOW_MASK)

#define WDOG_WIN_WINHIGH_MASK                    (0xFF00U)
#define WDOG_WIN_WINHIGH_SHIFT                   (8U)
/*! WINHIGH - High byte of Watchdog Window */
#define WDOG_WIN_WINHIGH(x)                      (((uint32_t)(((uint32_t)(x)) << WDOG_WIN_WINHIGH_SHIFT)) & WDOG_WIN_WINHIGH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WDOG_Register_Masks */

/* Extra definition */
#define WDOG_UPDATE_KEY                          (0xD928C520U)
#define WDOG_REFRESH_KEY                         (0xB480A602U)


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


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


#endif  /* WDOG_H_ */

