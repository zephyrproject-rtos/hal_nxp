/*
** ###################################################################
**     Processors:          MKE02Z16VFM4
**                          MKE02Z16VLC4
**                          MKE02Z16VLD4
**                          MKE02Z32VFM4
**                          MKE02Z32VLC4
**                          MKE02Z32VLD4
**                          MKE02Z32VLH4
**                          MKE02Z32VQH4
**                          MKE02Z64VFM4
**                          MKE02Z64VLC4
**                          MKE02Z64VLD4
**                          MKE02Z64VLH4
**                          MKE02Z64VQH4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for WDOG
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-05-19)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_WDOG.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for WDOG
 *
 * CMSIS Peripheral Access Layer for WDOG
 */

#if !defined(PERI_WDOG_H_)
#define PERI_WDOG_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKE02Z16VFM4) || defined(CPU_MKE02Z16VLC4) || defined(CPU_MKE02Z16VLD4) || defined(CPU_MKE02Z32VFM4) || defined(CPU_MKE02Z32VLC4) || defined(CPU_MKE02Z32VLD4) || defined(CPU_MKE02Z32VLH4) || defined(CPU_MKE02Z32VQH4) || defined(CPU_MKE02Z64VFM4) || defined(CPU_MKE02Z64VLC4) || defined(CPU_MKE02Z64VLD4) || defined(CPU_MKE02Z64VLH4) || defined(CPU_MKE02Z64VQH4))
#include "MKE02Z4_COMMON.h"
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
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS1;                                /**< Watchdog Control and Status Register 1, offset: 0x0 */
  __IO uint8_t CS2;                                /**< Watchdog Control and Status Register 2, offset: 0x1 */
  union {                                          /* offset: 0x2 */
    struct {                                         /* offset: 0x2 */
      __IO uint8_t CNTH;                               /**< Watchdog Counter Register: High, offset: 0x2 */
      __IO uint8_t CNTL;                               /**< Watchdog Counter Register: Low, offset: 0x3 */
    } CNT8B;
    __IO uint16_t CNT;                               /**< WDOG_CNT register., offset: 0x2 */
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t TOVALH;                             /**< Watchdog Timeout Value Register: High, offset: 0x4 */
      __IO uint8_t TOVALL;                             /**< Watchdog Timeout Value Register: Low, offset: 0x5 */
    } TOVAL8B;
    __IO uint16_t TOVAL;                             /**< WDOG_TOVAL register., offset: 0x4 */
  };
  union {                                          /* offset: 0x6 */
    struct {                                         /* offset: 0x6 */
      __IO uint8_t WINH;                               /**< Watchdog Window Register: High, offset: 0x6 */
      __IO uint8_t WINL;                               /**< Watchdog Window Register: Low, offset: 0x7 */
    } WIN8B;
    __IO uint16_t WIN;                               /**< WDOG_WIN register., offset: 0x6 */
  };
} WDOG_Type;

/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/*! @name CS1 - Watchdog Control and Status Register 1 */
/*! @{ */

#define WDOG_CS1_STOP_MASK                       (0x1U)
#define WDOG_CS1_STOP_SHIFT                      (0U)
/*! STOP - Stop Enable
 *  0b0..Watchdog disabled in chip stop mode.
 *  0b1..Watchdog enabled in chip stop mode.
 */
#define WDOG_CS1_STOP(x)                         (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_STOP_SHIFT)) & WDOG_CS1_STOP_MASK)

#define WDOG_CS1_WAIT_MASK                       (0x2U)
#define WDOG_CS1_WAIT_SHIFT                      (1U)
/*! WAIT - Wait Enable
 *  0b0..Watchdog disabled in chip wait mode.
 *  0b1..Watchdog enabled in chip wait mode.
 */
#define WDOG_CS1_WAIT(x)                         (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_WAIT_SHIFT)) & WDOG_CS1_WAIT_MASK)

#define WDOG_CS1_DBG_MASK                        (0x4U)
#define WDOG_CS1_DBG_SHIFT                       (2U)
/*! DBG - Debug Enable
 *  0b0..Watchdog disabled in chip debug mode.
 *  0b1..Watchdog enabled in chip debug mode.
 */
#define WDOG_CS1_DBG(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_DBG_SHIFT)) & WDOG_CS1_DBG_MASK)

#define WDOG_CS1_TST_MASK                        (0x18U)
#define WDOG_CS1_TST_SHIFT                       (3U)
/*! TST - Watchdog Test
 *  0b00..Watchdog test mode disabled.
 *  0b01..Watchdog user mode enabled. (Watchdog test mode disabled.) After testing the watchdog, software should
 *        use this setting to indicate that the watchdog is functioning normally in user mode.
 *  0b10..Watchdog test mode enabled, only the low byte is used. WDOG_CNTL is compared with WDOG_TOVALL.
 *  0b11..Watchdog test mode enabled, only the high byte is used. WDOG_CNTH is compared with WDOG_TOVALH.
 */
#define WDOG_CS1_TST(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_TST_SHIFT)) & WDOG_CS1_TST_MASK)

#define WDOG_CS1_UPDATE_MASK                     (0x20U)
#define WDOG_CS1_UPDATE_SHIFT                    (5U)
/*! UPDATE - Allow updates
 *  0b0..Updates not allowed. After the initial configuration, the watchdog cannot be later modified without forcing a reset.
 *  0b1..Updates allowed. Software can modify the watchdog configuration registers within 128 bus clocks after performing the unlock write sequence.
 */
#define WDOG_CS1_UPDATE(x)                       (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_UPDATE_SHIFT)) & WDOG_CS1_UPDATE_MASK)

#define WDOG_CS1_INT_MASK                        (0x40U)
#define WDOG_CS1_INT_SHIFT                       (6U)
/*! INT - Watchdog Interrupt
 *  0b0..Watchdog interrupts are disabled. Watchdog resets are not delayed.
 *  0b1..Watchdog interrupts are enabled. Watchdog resets are delayed by 128 bus clocks.
 */
#define WDOG_CS1_INT(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_INT_SHIFT)) & WDOG_CS1_INT_MASK)

#define WDOG_CS1_EN_MASK                         (0x80U)
#define WDOG_CS1_EN_SHIFT                        (7U)
/*! EN - Watchdog Enable
 *  0b0..Watchdog disabled.
 *  0b1..Watchdog enabled.
 */
#define WDOG_CS1_EN(x)                           (((uint8_t)(((uint8_t)(x)) << WDOG_CS1_EN_SHIFT)) & WDOG_CS1_EN_MASK)
/*! @} */

/*! @name CS2 - Watchdog Control and Status Register 2 */
/*! @{ */

#define WDOG_CS2_CLK_MASK                        (0x3U)
#define WDOG_CS2_CLK_SHIFT                       (0U)
/*! CLK - Watchdog Clock
 *  0b00..Bus clock.
 *  0b01..1 kHz internal low-power oscillator (LPOCLK).
 *  0b10..32 kHz internal oscillator (ICSIRCLK).
 *  0b11..External clock source.
 */
#define WDOG_CS2_CLK(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS2_CLK_SHIFT)) & WDOG_CS2_CLK_MASK)

#define WDOG_CS2_PRES_MASK                       (0x10U)
#define WDOG_CS2_PRES_SHIFT                      (4U)
/*! PRES - Watchdog Prescalar
 *  0b0..256 prescalar disabled.
 *  0b1..256 prescalar enabled.
 */
#define WDOG_CS2_PRES(x)                         (((uint8_t)(((uint8_t)(x)) << WDOG_CS2_PRES_SHIFT)) & WDOG_CS2_PRES_MASK)

#define WDOG_CS2_FLG_MASK                        (0x40U)
#define WDOG_CS2_FLG_SHIFT                       (6U)
/*! FLG - Watchdog Interrupt Flag
 *  0b0..No interrupt occurred.
 *  0b1..An interrupt occurred.
 */
#define WDOG_CS2_FLG(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS2_FLG_SHIFT)) & WDOG_CS2_FLG_MASK)

#define WDOG_CS2_WIN_MASK                        (0x80U)
#define WDOG_CS2_WIN_SHIFT                       (7U)
/*! WIN - Watchdog Window
 *  0b0..Window mode disabled.
 *  0b1..Window mode enabled.
 */
#define WDOG_CS2_WIN(x)                          (((uint8_t)(((uint8_t)(x)) << WDOG_CS2_WIN_SHIFT)) & WDOG_CS2_WIN_MASK)
/*! @} */

/*! @name CNTH - Watchdog Counter Register: High */
/*! @{ */

#define WDOG_CNTH_CNTHIGH_MASK                   (0xFFU)
#define WDOG_CNTH_CNTHIGH_SHIFT                  (0U)
/*! CNTHIGH - High byte of the Watchdog Counter */
#define WDOG_CNTH_CNTHIGH(x)                     (((uint8_t)(((uint8_t)(x)) << WDOG_CNTH_CNTHIGH_SHIFT)) & WDOG_CNTH_CNTHIGH_MASK)
/*! @} */

/*! @name CNTL - Watchdog Counter Register: Low */
/*! @{ */

#define WDOG_CNTL_CNTLOW_MASK                    (0xFFU)
#define WDOG_CNTL_CNTLOW_SHIFT                   (0U)
/*! CNTLOW - Low byte of the Watchdog Counter */
#define WDOG_CNTL_CNTLOW(x)                      (((uint8_t)(((uint8_t)(x)) << WDOG_CNTL_CNTLOW_SHIFT)) & WDOG_CNTL_CNTLOW_MASK)
/*! @} */

/*! @name CNT - WDOG_CNT register. */
/*! @{ */

#define WDOG_CNT_CNTHIGH_MASK                    (0xFFU)
#define WDOG_CNT_CNTHIGH_SHIFT                   (0U)
/*! CNTHIGH - High byte of the Watchdog Counter */
#define WDOG_CNT_CNTHIGH(x)                      (((uint16_t)(((uint16_t)(x)) << WDOG_CNT_CNTHIGH_SHIFT)) & WDOG_CNT_CNTHIGH_MASK)

#define WDOG_CNT_CNTLOW_MASK                     (0xFF00U)
#define WDOG_CNT_CNTLOW_SHIFT                    (8U)
/*! CNTLOW - Low byte of the Watchdog Counter */
#define WDOG_CNT_CNTLOW(x)                       (((uint16_t)(((uint16_t)(x)) << WDOG_CNT_CNTLOW_SHIFT)) & WDOG_CNT_CNTLOW_MASK)
/*! @} */

/*! @name TOVALH - Watchdog Timeout Value Register: High */
/*! @{ */

#define WDOG_TOVALH_TOVALHIGH_MASK               (0xFFU)
#define WDOG_TOVALH_TOVALHIGH_SHIFT              (0U)
/*! TOVALHIGH - High byte of the timeout value */
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint8_t)(((uint8_t)(x)) << WDOG_TOVALH_TOVALHIGH_SHIFT)) & WDOG_TOVALH_TOVALHIGH_MASK)
/*! @} */

/*! @name TOVALL - Watchdog Timeout Value Register: Low */
/*! @{ */

#define WDOG_TOVALL_TOVALLOW_MASK                (0xFFU)
#define WDOG_TOVALL_TOVALLOW_SHIFT               (0U)
/*! TOVALLOW - Low byte of the timeout value */
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint8_t)(((uint8_t)(x)) << WDOG_TOVALL_TOVALLOW_SHIFT)) & WDOG_TOVALL_TOVALLOW_MASK)
/*! @} */

/*! @name TOVAL - WDOG_TOVAL register. */
/*! @{ */

#define WDOG_TOVAL_TOVALHIGH_MASK                (0xFFU)
#define WDOG_TOVAL_TOVALHIGH_SHIFT               (0U)
/*! TOVALHIGH - High byte of the timeout value */
#define WDOG_TOVAL_TOVALHIGH(x)                  (((uint16_t)(((uint16_t)(x)) << WDOG_TOVAL_TOVALHIGH_SHIFT)) & WDOG_TOVAL_TOVALHIGH_MASK)

#define WDOG_TOVAL_TOVALLOW_MASK                 (0xFF00U)
#define WDOG_TOVAL_TOVALLOW_SHIFT                (8U)
/*! TOVALLOW - Low byte of the timeout value */
#define WDOG_TOVAL_TOVALLOW(x)                   (((uint16_t)(((uint16_t)(x)) << WDOG_TOVAL_TOVALLOW_SHIFT)) & WDOG_TOVAL_TOVALLOW_MASK)
/*! @} */

/*! @name WINH - Watchdog Window Register: High */
/*! @{ */

#define WDOG_WINH_WINHIGH_MASK                   (0xFFU)
#define WDOG_WINH_WINHIGH_SHIFT                  (0U)
/*! WINHIGH - High byte of Watchdog Window */
#define WDOG_WINH_WINHIGH(x)                     (((uint8_t)(((uint8_t)(x)) << WDOG_WINH_WINHIGH_SHIFT)) & WDOG_WINH_WINHIGH_MASK)
/*! @} */

/*! @name WINL - Watchdog Window Register: Low */
/*! @{ */

#define WDOG_WINL_WINLOW_MASK                    (0xFFU)
#define WDOG_WINL_WINLOW_SHIFT                   (0U)
/*! WINLOW - Low byte of Watchdog Window */
#define WDOG_WINL_WINLOW(x)                      (((uint8_t)(((uint8_t)(x)) << WDOG_WINL_WINLOW_SHIFT)) & WDOG_WINL_WINLOW_MASK)
/*! @} */

/*! @name WIN - WDOG_WIN register. */
/*! @{ */

#define WDOG_WIN_WINHIGH_MASK                    (0xFFU)
#define WDOG_WIN_WINHIGH_SHIFT                   (0U)
/*! WINHIGH - High byte of Watchdog Window */
#define WDOG_WIN_WINHIGH(x)                      (((uint16_t)(((uint16_t)(x)) << WDOG_WIN_WINHIGH_SHIFT)) & WDOG_WIN_WINHIGH_MASK)

#define WDOG_WIN_WINLOW_MASK                     (0xFF00U)
#define WDOG_WIN_WINLOW_SHIFT                    (8U)
/*! WINLOW - Low byte of Watchdog Window */
#define WDOG_WIN_WINLOW(x)                       (((uint16_t)(((uint16_t)(x)) << WDOG_WIN_WINLOW_SHIFT)) & WDOG_WIN_WINLOW_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group WDOG_Register_Masks */

#define WDOG_UPDATE_KEY1                         (0x20C5U)
#define WDOG_UPDATE_KEY_H1                       (0x20U)
#define WDOG_UPDATE_KEY_L1                       (0xC5U)
#define WDOG_UPDATE_KEY2                         (0x28D9U)
#define WDOG_UPDATE_KEY_H2                       (0x28U)
#define WDOG_UPDATE_KEY_L2                       (0xD9U)
#define WDOG_REFRESH_KEY1                        (0x02A6U)
#define WDOG_REFRESH_KEY_H1                      (0x02U)
#define WDOG_REFRESH_KEY_L1                      (0xA6U)
#define WDOG_REFRESH_KEY2                        (0x80B4U)
#define WDOG_REFRESH_KEY_H2                      (0x80U)
#define WDOG_REFRESH_KEY_L2                      (0xB4U)


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


#endif  /* PERI_WDOG_H_ */

