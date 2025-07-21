/*
** ###################################################################
**     Processor:           MCXE31BMPB
**     Version:             rev. 0.1, 2024-11-19
**     Build:               b250512
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
**     - rev. 0.1 (2024-11-19)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_RTC.h
 * @version 0.1
 * @date 2024-11-19
 * @brief CMSIS Peripheral Access Layer for RTC
 *
 * CMSIS Peripheral Access Layer for RTC
 */

#if !defined(PERI_RTC_H_)
#define PERI_RTC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXE31BMPB))
#include "MCXE31B_COMMON.h"
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
/*!
 * @brief List of RTC clock source.
 */
typedef enum _rtc_clock_source
{
    kRTC_SXOSCClock  = 0x0U, /*!< External slow crystal oscillator clock source.   */
    kRTC_SIRCClock   = 0x1U, /*!< Internal slow reference clock (SIRCLK).          */
    kRTC_FIRCClock   = 0x2U, /*!< Internal fast reference clock (FIRCLK).          */
    kRTC_FXOSCClock  = 0x3U, /*!< External fast crystal oscillator clock source.   */
} rtc_clock_source_t;


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t RTCSUPV;                           /**< RTC Supervisor control register, offset: 0x0 */
  __IO uint32_t RTCC;                              /**< RTC Control register, offset: 0x4 */
  __IO uint32_t RTCS;                              /**< RTC Status register, offset: 0x8 */
  __I  uint32_t RTCCNT;                            /**< RTC Counter register, offset: 0xC */
  __IO uint32_t APIVAL;                            /**< API Compare value register, offset: 0x10 */
  __IO uint32_t RTCVAL;                            /**< RTC Compare value register, offset: 0x14 */
} RTC_Type;

/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/*! @name RTCSUPV - RTC Supervisor control register */
/*! @{ */

#define RTC_RTCSUPV_SUPV_MASK                    (0x80000000U)
#define RTC_RTCSUPV_SUPV_SHIFT                   (31U)
/*! SUPV - RTC Supervisor Bit.
 *  0b0..All registers are accessible in both user as well as supervisor mode.
 *  0b1..All other registers are accessible in the supervisor mode only.
 */
#define RTC_RTCSUPV_SUPV(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_RTCSUPV_SUPV_SHIFT)) & RTC_RTCSUPV_SUPV_MASK)
/*! @} */

/*! @name RTCC - RTC Control register */
/*! @{ */

#define RTC_RTCC_TRIG_EN_MASK                    (0x1U)
#define RTC_RTCC_TRIG_EN_SHIFT                   (0U)
/*! TRIG_EN - Trigger enable for Analog Comparator */
#define RTC_RTCC_TRIG_EN(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_TRIG_EN_SHIFT)) & RTC_RTCC_TRIG_EN_MASK)

#define RTC_RTCC_DIV32EN_MASK                    (0x400U)
#define RTC_RTCC_DIV32EN_SHIFT                   (10U)
/*! DIV32EN - Divide by 32 enable.
 *  0b0..Divide by 32 is disabled
 *  0b1..Divide by 32 is enabled
 */
#define RTC_RTCC_DIV32EN(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_DIV32EN_SHIFT)) & RTC_RTCC_DIV32EN_MASK)

#define RTC_RTCC_DIV512EN_MASK                   (0x800U)
#define RTC_RTCC_DIV512EN_SHIFT                  (11U)
/*! DIV512EN - Divide by 512 enable
 *  0b0..Divide by 512 is disabled.
 *  0b1..Divide by 512 is enabled.
 */
#define RTC_RTCC_DIV512EN(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_DIV512EN_SHIFT)) & RTC_RTCC_DIV512EN_MASK)

#define RTC_RTCC_CLKSEL_MASK                     (0x3000U)
#define RTC_RTCC_CLKSEL_SHIFT                    (12U)
/*! CLKSEL - Clock select
 *  0b00..Clock source 0
 *  0b01..Clock source 1
 *  0b10..Clock source 2
 *  0b11..Clock source 3
 */
#define RTC_RTCC_CLKSEL(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_CLKSEL_SHIFT)) & RTC_RTCC_CLKSEL_MASK)

#define RTC_RTCC_APIIE_MASK                      (0x4000U)
#define RTC_RTCC_APIIE_SHIFT                     (14U)
/*! APIIE - API Interrupt Enable.
 *  0b0..API interrupts disabled.
 *  0b1..API interrupts enabled.
 */
#define RTC_RTCC_APIIE(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_APIIE_SHIFT)) & RTC_RTCC_APIIE_MASK)

#define RTC_RTCC_APIEN_MASK                      (0x8000U)
#define RTC_RTCC_APIEN_SHIFT                     (15U)
/*! APIEN - Autonomous Periodic Interrupt Enable.
 *  0b0..API disabled.
 *  0b1..API enabled.
 */
#define RTC_RTCC_APIEN(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_APIEN_SHIFT)) & RTC_RTCC_APIEN_MASK)

#define RTC_RTCC_ROVREN_MASK                     (0x10000000U)
#define RTC_RTCC_ROVREN_SHIFT                    (28U)
/*! ROVREN - Counter Roll Over wakeup/Interrupt Enable.
 *  0b0..RTC rollover wakeup/interrupt disabled
 *  0b1..RTC rollover wakeup/interrupt enabled.
 */
#define RTC_RTCC_ROVREN(x)                       (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_ROVREN_SHIFT)) & RTC_RTCC_ROVREN_MASK)

#define RTC_RTCC_FRZEN_MASK                      (0x20000000U)
#define RTC_RTCC_FRZEN_SHIFT                     (29U)
/*! FRZEN - Freeze Enable Bit
 *  0b0..Counter does not freeze in debug mode.
 *  0b1..Counter freezes in debug mode.
 */
#define RTC_RTCC_FRZEN(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_FRZEN_SHIFT)) & RTC_RTCC_FRZEN_MASK)

#define RTC_RTCC_RTCIE_MASK                      (0x40000000U)
#define RTC_RTCC_RTCIE_SHIFT                     (30U)
/*! RTCIE - RTC Interrupt Enable.
 *  0b0..RTC interrupts disabled.
 *  0b1..RTC interrupts enabled.
 */
#define RTC_RTCC_RTCIE(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_RTCIE_SHIFT)) & RTC_RTCC_RTCIE_MASK)

#define RTC_RTCC_CNTEN_MASK                      (0x80000000U)
#define RTC_RTCC_CNTEN_SHIFT                     (31U)
/*! CNTEN - Counter Enable
 *  0b0..Counter disabled
 *  0b1..Counter enabled
 */
#define RTC_RTCC_CNTEN(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCC_CNTEN_SHIFT)) & RTC_RTCC_CNTEN_MASK)
/*! @} */

/*! @name RTCS - RTC Status register */
/*! @{ */

#define RTC_RTCS_ROVRF_MASK                      (0x400U)
#define RTC_RTCS_ROVRF_SHIFT                     (10U)
/*! ROVRF - Counter Roll Over Interrupt Flag.
 *  0b0..RTC has not rolled over
 *  0b1..RTC has rolled over
 */
#define RTC_RTCS_ROVRF(x)                        (((uint32_t)(((uint32_t)(x)) << RTC_RTCS_ROVRF_SHIFT)) & RTC_RTCS_ROVRF_MASK)

#define RTC_RTCS_APIF_MASK                       (0x2000U)
#define RTC_RTCS_APIF_SHIFT                      (13U)
/*! APIF - API Interrupt Flag.
 *  0b0..Counter is not equal to API offset value.
 *  0b1..Counter matches the API offset value.
 */
#define RTC_RTCS_APIF(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_RTCS_APIF_SHIFT)) & RTC_RTCS_APIF_MASK)

#define RTC_RTCS_INV_API_MASK                    (0x20000U)
#define RTC_RTCS_INV_API_SHIFT                   (17U)
/*! INV_API - Invalid APIVAL write */
#define RTC_RTCS_INV_API(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_RTCS_INV_API_SHIFT)) & RTC_RTCS_INV_API_MASK)

#define RTC_RTCS_INV_RTC_MASK                    (0x40000U)
#define RTC_RTCS_INV_RTC_SHIFT                   (18U)
/*! INV_RTC - Invalid RTC write */
#define RTC_RTCS_INV_RTC(x)                      (((uint32_t)(((uint32_t)(x)) << RTC_RTCS_INV_RTC_SHIFT)) & RTC_RTCS_INV_RTC_MASK)

#define RTC_RTCS_RTCF_MASK                       (0x20000000U)
#define RTC_RTCS_RTCF_SHIFT                      (29U)
/*! RTCF - RTC Interrupt Flag
 *  0b0..RTC counter is not equal to RTCVAL.
 *  0b1..RTC counter matches RTCVAL.
 */
#define RTC_RTCS_RTCF(x)                         (((uint32_t)(((uint32_t)(x)) << RTC_RTCS_RTCF_SHIFT)) & RTC_RTCS_RTCF_MASK)
/*! @} */

/*! @name RTCCNT - RTC Counter register */
/*! @{ */

#define RTC_RTCCNT_RTCCNT_MASK                   (0xFFFFFFFFU)
#define RTC_RTCCNT_RTCCNT_SHIFT                  (0U)
/*! RTCCNT - RTC Counter Value */
#define RTC_RTCCNT_RTCCNT(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_RTCCNT_RTCCNT_SHIFT)) & RTC_RTCCNT_RTCCNT_MASK)
/*! @} */

/*! @name APIVAL - API Compare value register */
/*! @{ */

#define RTC_APIVAL_APIVAL_MASK                   (0xFFFFFFFFU)
#define RTC_APIVAL_APIVAL_SHIFT                  (0U)
/*! APIVAL - API Compare Value. */
#define RTC_APIVAL_APIVAL(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_APIVAL_APIVAL_SHIFT)) & RTC_APIVAL_APIVAL_MASK)
/*! @} */

/*! @name RTCVAL - RTC Compare value register */
/*! @{ */

#define RTC_RTCVAL_RTCVAL_MASK                   (0xFFFFFFFFU)
#define RTC_RTCVAL_RTCVAL_SHIFT                  (0U)
/*! RTCVAL - RTC Compare Value. */
#define RTC_RTCVAL_RTCVAL(x)                     (((uint32_t)(((uint32_t)(x)) << RTC_RTCVAL_RTCVAL_SHIFT)) & RTC_RTCVAL_RTCVAL_MASK)
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

