/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for XTALOSC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_XTALOSC.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for XTALOSC
 *
 * CMSIS Peripheral Access Layer for XTALOSC
 */

#if !defined(PERI_XTALOSC_H_)
#define PERI_XTALOSC_H_                          /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- XTALOSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XTALOSC_Peripheral_Access_Layer XTALOSC Peripheral Access Layer
 * @{
 */

/** XTALOSC - Register Layout Typedef */
typedef struct {
  __IO uint32_t OSC25M_CTL_CFG;                    /**< 25M Oscillator Control Configuration Register, offset: 0x0 */
  __IO uint32_t OSC25M_TEST_CFG;                   /**< 25M Oscillator Test Configuration Register, offset: 0x4 */
       uint8_t RESERVED_0[32760];
  __IO uint32_t OSC27M_CTL_CFG;                    /**< 27M Oscillator Control Configuration Register, offset: 0x8000 */
  __IO uint32_t OSC27M_TEST_CFG;                   /**< 27M Oscillator Test Configuration Register, offset: 0x8004 */
} XTALOSC_Type;

/* ----------------------------------------------------------------------------
   -- XTALOSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup XTALOSC_Register_Masks XTALOSC Register Masks
 * @{
 */

/*! @name OSC25M_CTL_CFG - 25M Oscillator Control Configuration Register */
/*! @{ */

#define XTALOSC_OSC25M_CTL_CFG_OSC_ALC_CTL_MASK  (0x4U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_ALC_CTL_SHIFT (2U)
/*! OSC_ALC_CTL
 *  0b0..Enable automatic level controller
 *  0b1..Disable automatic level controller
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_ALC_CTL(x)    (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_ALC_CTL_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_ALC_CTL_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_HYST_CTL_MASK (0x8U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_HYST_CTL_SHIFT (3U)
/*! OSC_HYST_CTL
 *  0b0..Enable hysteresis control
 *  0b1..Disable hysteresis control
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_HYST_CTL(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_HYST_CTL_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_HYST_CTL_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_SEL_MASK   (0x70U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_SEL_SHIFT  (4U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_GM_SEL_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_GM_SEL_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_STU_MASK  (0x80U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_STU_SHIFT (7U)
/*! OSC_INT_STU
 *  0b0..No oscillator clock interrupt occurred
 *  0b1..Oscillator clock interrupt pending
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_STU(x)    (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_INT_STU_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_INT_STU_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_DIV_MASK      (0x1F00U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_DIV_SHIFT     (8U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_DIV(x)        (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_DIV_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_DIV_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_OK_BYPASS_MASK (0x2000U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_OK_BYPASS_SHIFT (13U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_OK_BYPASS(x)  (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_OK_BYPASS_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_OK_BYPASS_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_MASK_MASK (0x8000U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_MASK_SHIFT (15U)
/*! OSC_INT_MASK
 *  0b0..Crystal oscillator clock interrupt is masked
 *  0b1..Crystal oscillator clock interrupt is enabled
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_INT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_INT_MASK_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_INT_MASK_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_EOCV_MASK     (0xFF0000U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_EOCV_SHIFT    (16U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_EOCV(x)       (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_EOCV_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_EOCV_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_TST_SEL_MASK (0x40000000U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_TST_SEL_SHIFT (30U)
/*! OSC_GM_TST_SEL
 *  0b0..Normal run mode
 *  0b1..Enable test mode measurement of GM
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_GM_TST_SEL(x) (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_GM_TST_SEL_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_GM_TST_SEL_MASK)

#define XTALOSC_OSC25M_CTL_CFG_OSC_BYPSS_MASK    (0x80000000U)
#define XTALOSC_OSC25M_CTL_CFG_OSC_BYPSS_SHIFT   (31U)
/*! OSC_BYPSS
 *  0b0..Oscillator output is used as root clock.
 *  0b1..EXTAL is used as root clock
 */
#define XTALOSC_OSC25M_CTL_CFG_OSC_BYPSS(x)      (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_CTL_CFG_OSC_BYPSS_SHIFT)) & XTALOSC_OSC25M_CTL_CFG_OSC_BYPSS_MASK)
/*! @} */

/*! @name OSC25M_TEST_CFG - 25M Oscillator Test Configuration Register */
/*! @{ */

#define XTALOSC_OSC25M_TEST_CFG_XOSC_TESTEN_MASK (0x80000000U)
#define XTALOSC_OSC25M_TEST_CFG_XOSC_TESTEN_SHIFT (31U)
#define XTALOSC_OSC25M_TEST_CFG_XOSC_TESTEN(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC25M_TEST_CFG_XOSC_TESTEN_SHIFT)) & XTALOSC_OSC25M_TEST_CFG_XOSC_TESTEN_MASK)
/*! @} */

/*! @name OSC27M_CTL_CFG - 27M Oscillator Control Configuration Register */
/*! @{ */

#define XTALOSC_OSC27M_CTL_CFG_OSC_ALC_CTL_MASK  (0x4U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_ALC_CTL_SHIFT (2U)
/*! OSC_ALC_CTL
 *  0b0..Enable automatic level controller
 *  0b1..Disable automatic level controller
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_ALC_CTL(x)    (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_ALC_CTL_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_ALC_CTL_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_HYST_CTL_MASK (0x8U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_HYST_CTL_SHIFT (3U)
/*! OSC_HYST_CTL
 *  0b0..Enable hysteresis control
 *  0b1..Disable hysteresis control
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_HYST_CTL(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_HYST_CTL_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_HYST_CTL_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_SEL_MASK   (0x70U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_SEL_SHIFT  (4U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_SEL(x)     (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_GM_SEL_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_GM_SEL_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_STU_MASK  (0x80U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_STU_SHIFT (7U)
/*! OSC_INT_STU
 *  0b0..No oscillator clock interrupt occurred
 *  0b1..Oscillator clock interrupt pending
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_STU(x)    (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_INT_STU_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_INT_STU_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_DIV_MASK      (0x1F00U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_DIV_SHIFT     (8U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_DIV(x)        (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_DIV_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_DIV_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_OK_BYPASS_MASK (0x2000U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_OK_BYPASS_SHIFT (13U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_OK_BYPASS(x)  (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_OK_BYPASS_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_OK_BYPASS_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_MASK_MASK (0x8000U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_MASK_SHIFT (15U)
/*! OSC_INT_MASK
 *  0b0..Crystal oscillator clock interrupt is masked
 *  0b1..Crystal oscillator clock interrupt is enabled
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_INT_MASK(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_INT_MASK_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_INT_MASK_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_EOCV_MASK     (0xFF0000U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_EOCV_SHIFT    (16U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_EOCV(x)       (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_EOCV_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_EOCV_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_TST_SEL_MASK (0x40000000U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_TST_SEL_SHIFT (30U)
/*! OSC_GM_TST_SEL
 *  0b0..Normal run mode
 *  0b1..Enable test mode measurement of GM
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_GM_TST_SEL(x) (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_GM_TST_SEL_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_GM_TST_SEL_MASK)

#define XTALOSC_OSC27M_CTL_CFG_OSC_BYPSS_MASK    (0x80000000U)
#define XTALOSC_OSC27M_CTL_CFG_OSC_BYPSS_SHIFT   (31U)
/*! OSC_BYPSS
 *  0b0..Oscillator output is used as root clock.
 *  0b1..EXTAL is used as root clock
 */
#define XTALOSC_OSC27M_CTL_CFG_OSC_BYPSS(x)      (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_CTL_CFG_OSC_BYPSS_SHIFT)) & XTALOSC_OSC27M_CTL_CFG_OSC_BYPSS_MASK)
/*! @} */

/*! @name OSC27M_TEST_CFG - 27M Oscillator Test Configuration Register */
/*! @{ */

#define XTALOSC_OSC27M_TEST_CFG_XOSC_TESTEN_MASK (0x80000000U)
#define XTALOSC_OSC27M_TEST_CFG_XOSC_TESTEN_SHIFT (31U)
#define XTALOSC_OSC27M_TEST_CFG_XOSC_TESTEN(x)   (((uint32_t)(((uint32_t)(x)) << XTALOSC_OSC27M_TEST_CFG_XOSC_TESTEN_SHIFT)) & XTALOSC_OSC27M_TEST_CFG_XOSC_TESTEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group XTALOSC_Register_Masks */


/*!
 * @}
 */ /* end of group XTALOSC_Peripheral_Access_Layer */


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


#endif  /* PERI_XTALOSC_H_ */

