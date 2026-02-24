/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for HSIO_GHZ_LN_PLL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_HSIO_GHZ_LN_PLL.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HSIO_GHZ_LN_PLL
 *
 * CMSIS Peripheral Access Layer for HSIO_GHZ_LN_PLL
 */

#if !defined(PERI_HSIO_GHZ_LN_PLL_H_)
#define PERI_HSIO_GHZ_LN_PLL_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- HSIO_GHZ_LN_PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_GHZ_LN_PLL_Peripheral_Access_Layer HSIO_GHZ_LN_PLL Peripheral Access Layer
 * @{
 */

/** HSIO_GHZ_LN_PLL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< PLL Control, offset: 0x0 */
    __IO uint32_t SET;                               /**< PLL Control, offset: 0x4 */
    __IO uint32_t CLR;                               /**< PLL Control, offset: 0x8 */
    __IO uint32_t TOG;                               /**< PLL Control, offset: 0xC */
  } CTRL;
       uint8_t RESERVED_0[32];
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Spread Spectrum, offset: 0x30 */
    __IO uint32_t SET;                               /**< Spread Spectrum, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Spread Spectrum, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Spread Spectrum, offset: 0x3C */
  } SPREAD_SPECTRUM;
  struct {                                         /* offset: 0x40 */
    __IO uint32_t RW;                                /**< Numerator, offset: 0x40 */
    __IO uint32_t SET;                               /**< Numerator, offset: 0x44 */
    __IO uint32_t CLR;                               /**< Numerator, offset: 0x48 */
    __IO uint32_t TOG;                               /**< Numerator, offset: 0x4C */
  } NUMERATOR;
  struct {                                         /* offset: 0x50 */
    __IO uint32_t RW;                                /**< Denominator, offset: 0x50 */
    __IO uint32_t SET;                               /**< Denominator, offset: 0x54 */
    __IO uint32_t CLR;                               /**< Denominator, offset: 0x58 */
    __IO uint32_t TOG;                               /**< Denominator, offset: 0x5C */
  } DENOMINATOR;
  struct {                                         /* offset: 0x60 */
    __IO uint32_t RW;                                /**< PLL Dividers, offset: 0x60 */
    __IO uint32_t SET;                               /**< PLL Dividers, offset: 0x64 */
    __IO uint32_t CLR;                               /**< PLL Dividers, offset: 0x68 */
    __IO uint32_t TOG;                               /**< PLL Dividers, offset: 0x6C */
  } DIV;
       uint8_t RESERVED_1[128];
  __I  uint32_t PLL_STATUS;                        /**< PLL Status, offset: 0xF0 */
} HSIO_GHZ_LN_PLL_Type;

/* ----------------------------------------------------------------------------
   -- HSIO_GHZ_LN_PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HSIO_GHZ_LN_PLL_Register_Masks HSIO_GHZ_LN_PLL Register Masks
 * @{
 */

/*! @name CTRL - PLL Control */
/*! @{ */

#define HSIO_GHZ_LN_PLL_CTRL_POWERUP_MASK        (0x1U)
#define HSIO_GHZ_LN_PLL_CTRL_POWERUP_SHIFT       (0U)
/*! POWERUP - Power Up
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSIO_GHZ_LN_PLL_CTRL_POWERUP(x)          (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_POWERUP_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_POWERUP_MASK)

#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_EN_MASK      (0x2U)
#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_EN_SHIFT     (1U)
/*! CLKMUX_EN - CLKMUX Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_EN(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_CLKMUX_EN_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_CLKMUX_EN_MASK)

#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_BYPASS_MASK  (0x4U)
#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_BYPASS_SHIFT (2U)
/*! CLKMUX_BYPASS - CLKMUX_Bypass
 *  0b0..Normal mode
 *  0b1..PLL Bypass mode
 */
#define HSIO_GHZ_LN_PLL_CTRL_CLKMUX_BYPASS(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_CLKMUX_BYPASS_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_CLKMUX_BYPASS_MASK)

#define HSIO_GHZ_LN_PLL_CTRL_SPREADCTL_MASK      (0x100U)
#define HSIO_GHZ_LN_PLL_CTRL_SPREADCTL_SHIFT     (8U)
/*! SPREADCTL - Modulation Type Select
 *  0b0..Centered around nominal frequency
 *  0b1..Spread below nominal frequency
 */
#define HSIO_GHZ_LN_PLL_CTRL_SPREADCTL(x)        (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_SPREADCTL_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_SPREADCTL_MASK)

#define HSIO_GHZ_LN_PLL_CTRL_HW_CTRL_SEL_MASK    (0x10000U)
#define HSIO_GHZ_LN_PLL_CTRL_HW_CTRL_SEL_SHIFT   (16U)
/*! HW_CTRL_SEL - Hardware Control Select
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSIO_GHZ_LN_PLL_CTRL_HW_CTRL_SEL(x)      (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_HW_CTRL_SEL_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_HW_CTRL_SEL_MASK)

#define HSIO_GHZ_LN_PLL_CTRL_LOCK_BYPASS_MASK    (0x80000000U)
#define HSIO_GHZ_LN_PLL_CTRL_LOCK_BYPASS_SHIFT   (31U)
/*! LOCK_BYPASS - Lock Bypass
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSIO_GHZ_LN_PLL_CTRL_LOCK_BYPASS(x)      (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_CTRL_LOCK_BYPASS_SHIFT)) & HSIO_GHZ_LN_PLL_CTRL_LOCK_BYPASS_MASK)
/*! @} */

/*! @name SPREAD_SPECTRUM - Spread Spectrum */
/*! @{ */

#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STEP_MASK (0x7FFFU)
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STEP_SHIFT (0U)
/*! STEP - Step */
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STEP(x)  (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STEP_SHIFT)) & HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STEP_MASK)

#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_ENABLE_MASK (0x8000U)
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_ENABLE_SHIFT (15U)
/*! ENABLE - Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_ENABLE_SHIFT)) & HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_ENABLE_MASK)

#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STOP_MASK (0xFFFF0000U)
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STOP_SHIFT (16U)
/*! STOP - Stop */
#define HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STOP(x)  (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STOP_SHIFT)) & HSIO_GHZ_LN_PLL_SPREAD_SPECTRUM_STOP_MASK)
/*! @} */

/*! @name NUMERATOR - Numerator */
/*! @{ */

#define HSIO_GHZ_LN_PLL_NUMERATOR_MFN_MASK       (0xFFFFFFFCU)
#define HSIO_GHZ_LN_PLL_NUMERATOR_MFN_SHIFT      (2U)
/*! MFN - Numerator */
#define HSIO_GHZ_LN_PLL_NUMERATOR_MFN(x)         (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_NUMERATOR_MFN_SHIFT)) & HSIO_GHZ_LN_PLL_NUMERATOR_MFN_MASK)
/*! @} */

/*! @name DENOMINATOR - Denominator */
/*! @{ */

#define HSIO_GHZ_LN_PLL_DENOMINATOR_MFD_MASK     (0x3FFFFFFFU)
#define HSIO_GHZ_LN_PLL_DENOMINATOR_MFD_SHIFT    (0U)
/*! MFD - Denominator */
#define HSIO_GHZ_LN_PLL_DENOMINATOR_MFD(x)       (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_DENOMINATOR_MFD_SHIFT)) & HSIO_GHZ_LN_PLL_DENOMINATOR_MFD_MASK)
/*! @} */

/*! @name DIV - PLL Dividers */
/*! @{ */

#define HSIO_GHZ_LN_PLL_DIV_ODIV_MASK            (0xFFU)
#define HSIO_GHZ_LN_PLL_DIV_ODIV_SHIFT           (0U)
/*! ODIV - Output Frequency Divider for Clock Output */
#define HSIO_GHZ_LN_PLL_DIV_ODIV(x)              (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_DIV_ODIV_SHIFT)) & HSIO_GHZ_LN_PLL_DIV_ODIV_MASK)

#define HSIO_GHZ_LN_PLL_DIV_RDIV_MASK            (0xE000U)
#define HSIO_GHZ_LN_PLL_DIV_RDIV_SHIFT           (13U)
/*! RDIV - Input Clock Predivider
 *  0b000..Divide by 1
 *  0b001..Divide by 1
 *  0b010..Divide by 2
 *  0b011..Divide by 3
 *  0b100..Divide by 4
 *  0b101..Divide by 5
 *  0b110..Divide by 6
 *  0b111..Divide by 7
 */
#define HSIO_GHZ_LN_PLL_DIV_RDIV(x)              (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_DIV_RDIV_SHIFT)) & HSIO_GHZ_LN_PLL_DIV_RDIV_MASK)

#define HSIO_GHZ_LN_PLL_DIV_MFI_MASK             (0x1FF0000U)
#define HSIO_GHZ_LN_PLL_DIV_MFI_SHIFT            (16U)
/*! MFI - Integer Portion of Loop Divider */
#define HSIO_GHZ_LN_PLL_DIV_MFI(x)               (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_DIV_MFI_SHIFT)) & HSIO_GHZ_LN_PLL_DIV_MFI_MASK)
/*! @} */

/*! @name PLL_STATUS - PLL Status */
/*! @{ */

#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOCK_MASK (0x1U)
#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOCK_SHIFT (0U)
/*! PLL_LOCK - PLL_LOCK */
#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOCK(x)   (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOCK_SHIFT)) & HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOCK_MASK)

#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOL_MASK  (0x2U)
#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOL_SHIFT (1U)
/*! PLL_LOL - PLL_LOL */
#define HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOL(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOL_SHIFT)) & HSIO_GHZ_LN_PLL_PLL_STATUS_PLL_LOL_MASK)

#define HSIO_GHZ_LN_PLL_PLL_STATUS_ANA_MFN_MASK  (0xFFFFFFFCU)
#define HSIO_GHZ_LN_PLL_PLL_STATUS_ANA_MFN_SHIFT (2U)
/*! ANA_MFN - ANA_MFN */
#define HSIO_GHZ_LN_PLL_PLL_STATUS_ANA_MFN(x)    (((uint32_t)(((uint32_t)(x)) << HSIO_GHZ_LN_PLL_PLL_STATUS_ANA_MFN_SHIFT)) & HSIO_GHZ_LN_PLL_PLL_STATUS_ANA_MFN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HSIO_GHZ_LN_PLL_Register_Masks */


/*!
 * @}
 */ /* end of group HSIO_GHZ_LN_PLL_Peripheral_Access_Layer */


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


#endif  /* PERI_HSIO_GHZ_LN_PLL_H_ */

