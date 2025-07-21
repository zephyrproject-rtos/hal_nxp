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
**         CMSIS Peripheral Access Layer for OSC_RC_400M
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
 * @file PERI_OSC_RC_400M.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSC_RC_400M
 *
 * CMSIS Peripheral Access Layer for OSC_RC_400M
 */

#if !defined(PERI_OSC_RC_400M_H_)
#define PERI_OSC_RC_400M_H_                      /**< Symbol preventing repeated inclusion */

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
   -- OSC_RC_400M Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_RC_400M_Peripheral_Access_Layer OSC_RC_400M Peripheral Access Layer
 * @{
 */

/** OSC_RC_400M - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0 */
    __IO uint32_t RW;                                /**< Analog Control Register CTRL0, offset: 0x0 */
    __IO uint32_t SET;                               /**< Analog Control Register CTRL0, offset: 0x4 */
    __IO uint32_t CLR;                               /**< Analog Control Register CTRL0, offset: 0x8 */
    __IO uint32_t TOG;                               /**< Analog Control Register CTRL0, offset: 0xC */
  } CTRL0;
  struct {                                         /* offset: 0x10 */
    __IO uint32_t RW;                                /**< Analog Control Register CTRL1, offset: 0x10 */
    __IO uint32_t SET;                               /**< Analog Control Register CTRL1, offset: 0x14 */
    __IO uint32_t CLR;                               /**< Analog Control Register CTRL1, offset: 0x18 */
    __IO uint32_t TOG;                               /**< Analog Control Register CTRL1, offset: 0x1C */
  } CTRL1;
  struct {                                         /* offset: 0x20 */
    __IO uint32_t RW;                                /**< Analog Control Register CTRL2, offset: 0x20 */
    __IO uint32_t SET;                               /**< Analog Control Register CTRL2, offset: 0x24 */
    __IO uint32_t CLR;                               /**< Analog Control Register CTRL2, offset: 0x28 */
    __IO uint32_t TOG;                               /**< Analog Control Register CTRL2, offset: 0x2C */
  } CTRL2;
  struct {                                         /* offset: 0x30 */
    __IO uint32_t RW;                                /**< Analog Control Register CTRL3, offset: 0x30 */
    __IO uint32_t SET;                               /**< Analog Control Register CTRL3, offset: 0x34 */
    __IO uint32_t CLR;                               /**< Analog Control Register CTRL3, offset: 0x38 */
    __IO uint32_t TOG;                               /**< Analog Control Register CTRL3, offset: 0x3C */
  } CTRL3;
       uint8_t RESERVED_0[16];
  __I  uint32_t STAT0;                             /**< Analog Status Register STAT0, offset: 0x50 */
       uint8_t RESERVED_1[12];
  __I  uint32_t STAT1;                             /**< Analog Status Register STAT1, offset: 0x60 */
       uint8_t RESERVED_2[12];
  __I  uint32_t STAT2;                             /**< Analog Status Register STAT2, offset: 0x70 */
} OSC_RC_400M_Type;

/* ----------------------------------------------------------------------------
   -- OSC_RC_400M Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_RC_400M_Register_Masks OSC_RC_400M Register Masks
 * @{
 */

/*! @name CTRL0 - Analog Control Register CTRL0 */
/*! @{ */

#define OSC_RC_400M_CTRL0_REF_CLK_DIV_MASK       (0x3F000000U)
#define OSC_RC_400M_CTRL0_REF_CLK_DIV_SHIFT      (24U)
/*! REF_CLK_DIV - Divide value for ref_clk to generate slow_clk. */
#define OSC_RC_400M_CTRL0_REF_CLK_DIV(x)         (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL0_REF_CLK_DIV_SHIFT)) & OSC_RC_400M_CTRL0_REF_CLK_DIV_MASK)
/*! @} */

/*! @name CTRL1 - Analog Control Register CTRL1 */
/*! @{ */

#define OSC_RC_400M_CTRL1_HYST_MINUS_MASK        (0xFU)
#define OSC_RC_400M_CTRL1_HYST_MINUS_SHIFT       (0U)
/*! HYST_MINUS - Negative hysteresis value for the tuned clock. */
#define OSC_RC_400M_CTRL1_HYST_MINUS(x)          (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL1_HYST_MINUS_SHIFT)) & OSC_RC_400M_CTRL1_HYST_MINUS_MASK)

#define OSC_RC_400M_CTRL1_HYST_PLUS_MASK         (0xF00U)
#define OSC_RC_400M_CTRL1_HYST_PLUS_SHIFT        (8U)
/*! HYST_PLUS - Positive hysteresis value for the tuned clock. */
#define OSC_RC_400M_CTRL1_HYST_PLUS(x)           (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL1_HYST_PLUS_SHIFT)) & OSC_RC_400M_CTRL1_HYST_PLUS_MASK)

#define OSC_RC_400M_CTRL1_TARGET_COUNT_MASK      (0xFFFF0000U)
#define OSC_RC_400M_CTRL1_TARGET_COUNT_SHIFT     (16U)
/*! TARGET_COUNT - Target count for the fast clock. */
#define OSC_RC_400M_CTRL1_TARGET_COUNT(x)        (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL1_TARGET_COUNT_SHIFT)) & OSC_RC_400M_CTRL1_TARGET_COUNT_MASK)
/*! @} */

/*! @name CTRL2 - Analog Control Register CTRL2 */
/*! @{ */

#define OSC_RC_400M_CTRL2_TUNE_INV_MASK          (0x100U)
#define OSC_RC_400M_CTRL2_TUNE_INV_SHIFT         (8U)
/*! TUNE_INV - Inverse tuning direction. */
#define OSC_RC_400M_CTRL2_TUNE_INV(x)            (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL2_TUNE_INV_SHIFT)) & OSC_RC_400M_CTRL2_TUNE_INV_MASK)

#define OSC_RC_400M_CTRL2_TUNE_BYP_MASK          (0x400U)
#define OSC_RC_400M_CTRL2_TUNE_BYP_SHIFT         (10U)
/*! TUNE_BYP - Bypass the tuning logic */
#define OSC_RC_400M_CTRL2_TUNE_BYP(x)            (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL2_TUNE_BYP_SHIFT)) & OSC_RC_400M_CTRL2_TUNE_BYP_MASK)

#define OSC_RC_400M_CTRL2_TUNE_EN_MASK           (0x1000U)
#define OSC_RC_400M_CTRL2_TUNE_EN_SHIFT          (12U)
/*! TUNE_EN - Freeze/Unfreeze the tuning value. */
#define OSC_RC_400M_CTRL2_TUNE_EN(x)             (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL2_TUNE_EN_SHIFT)) & OSC_RC_400M_CTRL2_TUNE_EN_MASK)

#define OSC_RC_400M_CTRL2_TUNE_START_MASK        (0x4000U)
#define OSC_RC_400M_CTRL2_TUNE_START_SHIFT       (14U)
/*! TUNE_START - Start/Stop tuning. */
#define OSC_RC_400M_CTRL2_TUNE_START(x)          (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL2_TUNE_START_SHIFT)) & OSC_RC_400M_CTRL2_TUNE_START_MASK)

#define OSC_RC_400M_CTRL2_OSC_TUNE_VAL_MASK      (0xFF000000U)
#define OSC_RC_400M_CTRL2_OSC_TUNE_VAL_SHIFT     (24U)
/*! OSC_TUNE_VAL - Program the oscillator frequency. */
#define OSC_RC_400M_CTRL2_OSC_TUNE_VAL(x)        (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL2_OSC_TUNE_VAL_SHIFT)) & OSC_RC_400M_CTRL2_OSC_TUNE_VAL_MASK)
/*! @} */

/*! @name CTRL3 - Analog Control Register CTRL3 */
/*! @{ */

#define OSC_RC_400M_CTRL3_CLR_ERR_MASK           (0x1U)
#define OSC_RC_400M_CTRL3_CLR_ERR_SHIFT          (0U)
/*! CLR_ERR - Clear the error flag CLK1M_ERR
 *  0b0..Normal operation
 *  0b1..Clears the error flag CLK1M_ERR in status register STAT0.
 */
#define OSC_RC_400M_CTRL3_CLR_ERR(x)             (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL3_CLR_ERR_SHIFT)) & OSC_RC_400M_CTRL3_CLR_ERR_MASK)

#define OSC_RC_400M_CTRL3_EN_1M_CLK_MASK         (0x100U)
#define OSC_RC_400M_CTRL3_EN_1M_CLK_SHIFT        (8U)
/*! EN_1M_CLK - 1: Disable clk_1m_out. */
#define OSC_RC_400M_CTRL3_EN_1M_CLK(x)           (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL3_EN_1M_CLK_SHIFT)) & OSC_RC_400M_CTRL3_EN_1M_CLK_MASK)

#define OSC_RC_400M_CTRL3_MUX_1M_CLK_MASK        (0x400U)
#define OSC_RC_400M_CTRL3_MUX_1M_CLK_SHIFT       (10U)
/*! MUX_1M_CLK - Select free/locked 1MHz output */
#define OSC_RC_400M_CTRL3_MUX_1M_CLK(x)          (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL3_MUX_1M_CLK_SHIFT)) & OSC_RC_400M_CTRL3_MUX_1M_CLK_MASK)

#define OSC_RC_400M_CTRL3_COUNT_1M_CLK_MASK      (0xFFFF0000U)
#define OSC_RC_400M_CTRL3_COUNT_1M_CLK_SHIFT     (16U)
/*! COUNT_1M_CLK - Count for the locked clk_1m_out. */
#define OSC_RC_400M_CTRL3_COUNT_1M_CLK(x)        (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_CTRL3_COUNT_1M_CLK_SHIFT)) & OSC_RC_400M_CTRL3_COUNT_1M_CLK_MASK)
/*! @} */

/*! @name STAT0 - Analog Status Register STAT0 */
/*! @{ */

#define OSC_RC_400M_STAT0_CLK1M_ERR_MASK         (0x1U)
#define OSC_RC_400M_STAT0_CLK1M_ERR_SHIFT        (0U)
/*! CLK1M_ERR - Error flag for clk_1m_locked.
 *  0b0..No error.
 *  0b1..Indicates error.
 */
#define OSC_RC_400M_STAT0_CLK1M_ERR(x)           (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_STAT0_CLK1M_ERR_SHIFT)) & OSC_RC_400M_STAT0_CLK1M_ERR_MASK)
/*! @} */

/*! @name STAT1 - Analog Status Register STAT1 */
/*! @{ */

#define OSC_RC_400M_STAT1_CURR_COUNT_VAL_MASK    (0xFFFF0000U)
#define OSC_RC_400M_STAT1_CURR_COUNT_VAL_SHIFT   (16U)
/*! CURR_COUNT_VAL - Current count for the fast clock. */
#define OSC_RC_400M_STAT1_CURR_COUNT_VAL(x)      (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_STAT1_CURR_COUNT_VAL_SHIFT)) & OSC_RC_400M_STAT1_CURR_COUNT_VAL_MASK)
/*! @} */

/*! @name STAT2 - Analog Status Register STAT2 */
/*! @{ */

#define OSC_RC_400M_STAT2_CURR_OSC_TUNE_VAL_MASK (0xFF000000U)
#define OSC_RC_400M_STAT2_CURR_OSC_TUNE_VAL_SHIFT (24U)
/*! CURR_OSC_TUNE_VAL - Current tuning value used by oscillator. */
#define OSC_RC_400M_STAT2_CURR_OSC_TUNE_VAL(x)   (((uint32_t)(((uint32_t)(x)) << OSC_RC_400M_STAT2_CURR_OSC_TUNE_VAL_SHIFT)) & OSC_RC_400M_STAT2_CURR_OSC_TUNE_VAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC_RC_400M_Register_Masks */


/*!
 * @}
 */ /* end of group OSC_RC_400M_Peripheral_Access_Layer */


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


#endif  /* PERI_OSC_RC_400M_H_ */

