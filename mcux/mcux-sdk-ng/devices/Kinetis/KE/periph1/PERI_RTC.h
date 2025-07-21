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
**         CMSIS Peripheral Access Layer for RTC
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
 * @file PERI_RTC.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

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
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< RTC Status and Control Register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< RTC Modulo Register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< RTC Counter Register, offset: 0x8 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name SC - RTC Status and Control Register */
/*! @{ */

#define RTC_SC_RTCO_MASK                         (0x10U)
#define RTC_SC_RTCO_SHIFT                        (4U)
/*! RTCO - Real-Time Counter Output
 *  0b0..Real-time counter output disabled.
 *  0b1..Real-time counter output enabled.
 */
#define RTC_SC_RTCO(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_SC_RTCO_SHIFT)) & RTC_SC_RTCO_MASK)

#define RTC_SC_RTIE_MASK                         (0x40U)
#define RTC_SC_RTIE_SHIFT                        (6U)
/*! RTIE - Real-Time Interrupt Enable
 *  0b0..Real-time interrupt requests are disabled. Use software polling.
 *  0b1..Real-time interrupt requests are enabled.
 */
#define RTC_SC_RTIE(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_SC_RTIE_SHIFT)) & RTC_SC_RTIE_MASK)

#define RTC_SC_RTIF_MASK                         (0x80U)
#define RTC_SC_RTIF_SHIFT                        (7U)
/*! RTIF - Real-Time Interrupt Flag
 *  0b0..RTC counter has not reached the value in the RTC modulo register.
 *  0b1..RTC counter has reached the value in the RTC modulo register.
 */
#define RTC_SC_RTIF(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_SC_RTIF_SHIFT)) & RTC_SC_RTIF_MASK)

#define RTC_SC_RTCPS_MASK                        (0x700U)
#define RTC_SC_RTCPS_SHIFT                       (8U)
/*! RTCPS - Real-Time Clock Prescaler Select
 *  0b000..Off
 *  0b001..If RTCLKS = x0, it is 1; if RTCLKS = x1, it is 128.
 *  0b010..If RTCLKS = x0, it is 2; if RTCLKS = x1, it is 256.
 *  0b011..If RTCLKS = x0, it is 4; if RTCLKS = x1, it is 512.
 *  0b100..If RTCLKS = x0, it is 8; if RTCLKS = x1, it is 1024.
 *  0b101..If RTCLKS = x0, it is 16; if RTCLKS = x1, it is 2048.
 *  0b110..If RTCLKS = x0, it is 32; if RTCLKS = x1, it is 100.
 *  0b111..If RTCLKS = x0, it is 64; if RTCLKS = x1, it is 1000.
 */
#define RTC_SC_RTCPS(x)                          (((uint32_t)(((uint32_t)(x)) << RTC_SC_RTCPS_SHIFT)) & RTC_SC_RTCPS_MASK)

#define RTC_SC_RTCLKS_MASK                       (0xC000U)
#define RTC_SC_RTCLKS_SHIFT                      (14U)
/*! RTCLKS - Real-Time Clock Source Select
 *  0b00..External clock source.
 *  0b01..Real-time clock source is 1 kHz (LPOCLK).
 *  0b10..Internal reference clock (ICSIRCLK).
 *  0b11..Bus clock.
 */
#define RTC_SC_RTCLKS(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_SC_RTCLKS_SHIFT)) & RTC_SC_RTCLKS_MASK)
/*! @} */

/*! @name MOD - RTC Modulo Register */
/*! @{ */

#define RTC_MOD_MOD_MASK                         (0xFFFFU)
#define RTC_MOD_MOD_SHIFT                        (0U)
/*! MOD - RTC Modulo */
#define RTC_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_MOD_MOD_SHIFT)) & RTC_MOD_MOD_MASK)
/*! @} */

/*! @name CNT - RTC Counter Register */
/*! @{ */

#define RTC_CNT_CNT_MASK                         (0xFFFFU)
#define RTC_CNT_CNT_SHIFT                        (0U)
/*! CNT - RTC Count */
#define RTC_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x)) << RTC_CNT_CNT_SHIFT)) & RTC_CNT_CNT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


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


#endif  /* PERI_RTC_H_ */

