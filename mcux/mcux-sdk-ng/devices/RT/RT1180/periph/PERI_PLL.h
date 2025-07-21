/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PLL
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
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
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_PLL.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PLL
 *
 * CMSIS Peripheral Access Layer for PLL
 */

#if !defined(PERI_PLL_H_)
#define PERI_PLL_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
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
   -- PLL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Peripheral_Access_Layer PLL Peripheral Access Layer
 * @{
 */

/** PLL - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Fractional PLL Control Register, offset: 0x0 */
    __IO uint32_t SET;                               /**< Fractional PLL Control Register, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Fractional PLL Control Register, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Fractional PLL Control Register, offset: 0xC */
  } CTRL0;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Fractional PLL Spread Spectrum Control Register, offset: 0x10 */
    __IO uint32_t SET;                               /**< Fractional PLL Spread Spectrum Control Register, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Fractional PLL Spread Spectrum Control Register, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Fractional PLL Spread Spectrum Control Register, offset: 0x1C */
  } SPREAD_SPECTRUM;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Fractional PLL Numerator Control Register, offset: 0x20 */
    __IO uint32_t SET;                               /**< Fractional PLL Numerator Control Register, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Fractional PLL Numerator Control Register, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Fractional PLL Numerator Control Register, offset: 0x2C */
  } NUMERATOR;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Fractional PLL Denominator Control Register, offset: 0x30 */
    __IO uint32_t SET;                               /**< Fractional PLL Denominator Control Register, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Fractional PLL Denominator Control Register, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Fractional PLL Denominator Control Register, offset: 0x3C */
  } DENOMINATOR;
} PLL_Type;

/* ----------------------------------------------------------------------------
   -- PLL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PLL_Register_Masks PLL Register Masks
 * @{
 */

/*! @name CTRL0 - Fractional PLL Control Register */
/*! @{ */

#define PLL_CTRL0_DIV_SELECT_MASK                (0x7FU)
#define PLL_CTRL0_DIV_SELECT_SHIFT               (0U)
/*! DIV_SELECT - DIV_SELECT */
#define PLL_CTRL0_DIV_SELECT(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_DIV_SELECT_SHIFT)) & PLL_CTRL0_DIV_SELECT_MASK)

#define PLL_CTRL0_ENABLE_ALT_MASK                (0x100U)
#define PLL_CTRL0_ENABLE_ALT_SHIFT               (8U)
/*! ENABLE_ALT - ENABLE_ALT
 *  0b0..Disable the alternate clock output
 *  0b1..Enable the alternate clock output which is the output of the post_divider, and cannot be bypassed
 */
#define PLL_CTRL0_ENABLE_ALT(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_ENABLE_ALT_SHIFT)) & PLL_CTRL0_ENABLE_ALT_MASK)

#define PLL_CTRL0_HOLD_RING_OFF_MASK             (0x2000U)
#define PLL_CTRL0_HOLD_RING_OFF_SHIFT            (13U)
/*! HOLD_RING_OFF - PLL Start up initialization
 *  0b0..Normal operation
 *  0b1..Initialize PLL start up
 */
#define PLL_CTRL0_HOLD_RING_OFF(x)               (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_HOLD_RING_OFF_SHIFT)) & PLL_CTRL0_HOLD_RING_OFF_MASK)

#define PLL_CTRL0_POWERUP_MASK                   (0x4000U)
#define PLL_CTRL0_POWERUP_SHIFT                  (14U)
/*! POWERUP - POWERUP
 *  0b0..Power down the PLL
 *  0b1..Power Up the PLL
 */
#define PLL_CTRL0_POWERUP(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_POWERUP_SHIFT)) & PLL_CTRL0_POWERUP_MASK)

#define PLL_CTRL0_ENABLE_MASK                    (0x8000U)
#define PLL_CTRL0_ENABLE_SHIFT                   (15U)
/*! ENABLE - ENABLE
 *  0b0..Disable the clock output
 *  0b1..Enable the clock output
 */
#define PLL_CTRL0_ENABLE(x)                      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_ENABLE_SHIFT)) & PLL_CTRL0_ENABLE_MASK)

#define PLL_CTRL0_BYPASS_MASK                    (0x10000U)
#define PLL_CTRL0_BYPASS_SHIFT                   (16U)
/*! BYPASS - BYPASS
 *  0b0..No Bypass
 *  0b1..Bypass the PLL
 */
#define PLL_CTRL0_BYPASS(x)                      (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_BYPASS_SHIFT)) & PLL_CTRL0_BYPASS_MASK)

#define PLL_CTRL0_DITHER_EN_MASK                 (0x20000U)
#define PLL_CTRL0_DITHER_EN_SHIFT                (17U)
/*! DITHER_EN - DITHER_EN
 *  0b0..Disable Dither
 *  0b1..Enable Dither
 */
#define PLL_CTRL0_DITHER_EN(x)                   (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_DITHER_EN_SHIFT)) & PLL_CTRL0_DITHER_EN_MASK)

#define PLL_CTRL0_PLL_REG_EN_MASK                (0x400000U)
#define PLL_CTRL0_PLL_REG_EN_SHIFT               (22U)
/*! PLL_REG_EN - PLL_REG_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define PLL_CTRL0_PLL_REG_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_PLL_REG_EN_SHIFT)) & PLL_CTRL0_PLL_REG_EN_MASK)

#define PLL_CTRL0_POST_DIV_SEL_MASK              (0xE000000U)
#define PLL_CTRL0_POST_DIV_SEL_SHIFT             (25U)
/*! POST_DIV_SEL - Post Divide Select
 *  0b000..Divide by 1
 *  0b001..Divide by 2
 *  0b010..Divide by 4
 *  0b011..Divide by 8
 *  0b100..Divide by 16
 *  0b101..Divide by 32
 */
#define PLL_CTRL0_POST_DIV_SEL(x)                (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_POST_DIV_SEL_SHIFT)) & PLL_CTRL0_POST_DIV_SEL_MASK)

#define PLL_CTRL0_BIAS_SELECT_MASK               (0x20000000U)
#define PLL_CTRL0_BIAS_SELECT_SHIFT              (29U)
/*! BIAS_SELECT - BIAS_SELECT
 *  0b0..Used in SoCs with a bias current of 10uA
 *  0b1..Used in SoCs with a bias current of 2uA
 */
#define PLL_CTRL0_BIAS_SELECT(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_CTRL0_BIAS_SELECT_SHIFT)) & PLL_CTRL0_BIAS_SELECT_MASK)
/*! @} */

/*! @name SPREAD_SPECTRUM - Fractional PLL Spread Spectrum Control Register */
/*! @{ */

#define PLL_SPREAD_SPECTRUM_STEP_MASK            (0x7FFFU)
#define PLL_SPREAD_SPECTRUM_STEP_SHIFT           (0U)
/*! STEP - Step */
#define PLL_SPREAD_SPECTRUM_STEP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STEP_SHIFT)) & PLL_SPREAD_SPECTRUM_STEP_MASK)

#define PLL_SPREAD_SPECTRUM_ENABLE_MASK          (0x8000U)
#define PLL_SPREAD_SPECTRUM_ENABLE_SHIFT         (15U)
/*! ENABLE - Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PLL_SPREAD_SPECTRUM_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_ENABLE_SHIFT)) & PLL_SPREAD_SPECTRUM_ENABLE_MASK)

#define PLL_SPREAD_SPECTRUM_STOP_MASK            (0xFFFF0000U)
#define PLL_SPREAD_SPECTRUM_STOP_SHIFT           (16U)
/*! STOP - Stop */
#define PLL_SPREAD_SPECTRUM_STOP(x)              (((uint32_t)(((uint32_t)(x)) << PLL_SPREAD_SPECTRUM_STOP_SHIFT)) & PLL_SPREAD_SPECTRUM_STOP_MASK)
/*! @} */

/*! @name NUMERATOR - Fractional PLL Numerator Control Register */
/*! @{ */

#define PLL_NUMERATOR_NUM_MASK                   (0x3FFFFFFFU)
#define PLL_NUMERATOR_NUM_SHIFT                  (0U)
/*! NUM - Numerator */
#define PLL_NUMERATOR_NUM(x)                     (((uint32_t)(((uint32_t)(x)) << PLL_NUMERATOR_NUM_SHIFT)) & PLL_NUMERATOR_NUM_MASK)
/*! @} */

/*! @name DENOMINATOR - Fractional PLL Denominator Control Register */
/*! @{ */

#define PLL_DENOMINATOR_DENOM_MASK               (0x3FFFFFFFU)
#define PLL_DENOMINATOR_DENOM_SHIFT              (0U)
/*! DENOM - Denominator */
#define PLL_DENOMINATOR_DENOM(x)                 (((uint32_t)(((uint32_t)(x)) << PLL_DENOMINATOR_DENOM_SHIFT)) & PLL_DENOMINATOR_DENOM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PLL_Register_Masks */


/*!
 * @}
 */ /* end of group PLL_Peripheral_Access_Layer */


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


#endif  /* PERI_PLL_H_ */

