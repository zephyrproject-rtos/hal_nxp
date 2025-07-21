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
**         CMSIS Peripheral Access Layer for ANADIG_OSC
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
 * @file PERI_ANADIG_OSC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ANADIG_OSC
 *
 * CMSIS Peripheral Access Layer for ANADIG_OSC
 */

#if !defined(PERI_ANADIG_OSC_H_)
#define PERI_ANADIG_OSC_H_                       /**< Symbol preventing repeated inclusion */

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
   -- ANADIG_OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_OSC_Peripheral_Access_Layer ANADIG_OSC Peripheral Access Layer
 * @{
 */

/** ANADIG_OSC - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[17168];
  __IO uint32_t OSC_RC24M_CTRL;                    /**< 24MHz RCOSC Control Register, offset: 0x4310 */
       uint8_t RESERVED_1[12];
  __IO uint32_t OSC_24M_CTRL;                      /**< 24MHz OSC Control Register, offset: 0x4320 */
       uint8_t RESERVED_2[28];
  __I  uint32_t OSC_400M_CTRL0;                    /**< 400MHz RCOSC Control0 Register, offset: 0x4340 */
       uint8_t RESERVED_3[12];
  __IO uint32_t OSC_400M_CTRL1;                    /**< 400MHz RCOSC Control1 Register, offset: 0x4350 */
} ANADIG_OSC_Type;

/* ----------------------------------------------------------------------------
   -- ANADIG_OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ANADIG_OSC_Register_Masks ANADIG_OSC Register Masks
 * @{
 */

/*! @name OSC_RC24M_CTRL - 24MHz RCOSC Control Register */
/*! @{ */

#define ANADIG_OSC_OSC_RC24M_CTRL_TEN_MASK       (0x2U)
#define ANADIG_OSC_OSC_RC24M_CTRL_TEN_SHIFT      (1U)
/*! TEN - RC24M Enable
 *  0b0..Power down
 *  0b1..Power up
 */
#define ANADIG_OSC_OSC_RC24M_CTRL_TEN(x)         (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_RC24M_CTRL_TEN_SHIFT)) & ANADIG_OSC_OSC_RC24M_CTRL_TEN_MASK)

#define ANADIG_OSC_OSC_RC24M_CTRL_SOURCE_SEL_24M_MASK (0x2000000U)
#define ANADIG_OSC_OSC_RC24M_CTRL_SOURCE_SEL_24M_SHIFT (25U)
/*! SOURCE_SEL_24M - source_sel_24M
 *  0b0..OSC_RC24M
 *  0b1..OSC24M
 */
#define ANADIG_OSC_OSC_RC24M_CTRL_SOURCE_SEL_24M(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_RC24M_CTRL_SOURCE_SEL_24M_SHIFT)) & ANADIG_OSC_OSC_RC24M_CTRL_SOURCE_SEL_24M_MASK)

#define ANADIG_OSC_OSC_RC24M_CTRL_RC_24M_CONTROL_MODE_MASK (0x80000000U)
#define ANADIG_OSC_OSC_RC24M_CTRL_RC_24M_CONTROL_MODE_SHIFT (31U)
/*! RC_24M_CONTROL_MODE - RCOSC Control Mode
 *  0b0..Software mode (default)
 *  0b1..GPC mode
 */
#define ANADIG_OSC_OSC_RC24M_CTRL_RC_24M_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_RC24M_CTRL_RC_24M_CONTROL_MODE_SHIFT)) & ANADIG_OSC_OSC_RC24M_CTRL_RC_24M_CONTROL_MODE_MASK)
/*! @} */

/*! @name OSC_24M_CTRL - 24MHz OSC Control Register */
/*! @{ */

#define ANADIG_OSC_OSC_24M_CTRL_BYPASS_EN_MASK   (0x2U)
#define ANADIG_OSC_OSC_24M_CTRL_BYPASS_EN_SHIFT  (1U)
/*! BYPASS_EN - 24MHz OSC Bypass Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANADIG_OSC_OSC_24M_CTRL_BYPASS_EN(x)     (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_BYPASS_EN_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_BYPASS_EN_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_LP_EN_MASK       (0x4U)
#define ANADIG_OSC_OSC_24M_CTRL_LP_EN_SHIFT      (2U)
/*! LP_EN - 24MHz OSC Low-Power Mode Enable
 *  0b0..High Gain mode (HP)
 *  0b1..Low-power mode (LP)
 */
#define ANADIG_OSC_OSC_24M_CTRL_LP_EN(x)         (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_LP_EN_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_LP_EN_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_OSC_COMP_MODE_MASK (0x8U)
#define ANADIG_OSC_OSC_24M_CTRL_OSC_COMP_MODE_SHIFT (3U)
/*! OSC_COMP_MODE - 24MHz OSC Comparator Mode
 *  0b0..Single-ended mode (default)
 *  0b1..Differential mode (test mode)
 */
#define ANADIG_OSC_OSC_24M_CTRL_OSC_COMP_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_OSC_COMP_MODE_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_OSC_COMP_MODE_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_OSC_EN_MASK      (0x10U)
#define ANADIG_OSC_OSC_24M_CTRL_OSC_EN_SHIFT     (4U)
/*! OSC_EN - 24MHz OSC Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define ANADIG_OSC_OSC_24M_CTRL_OSC_EN(x)        (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_OSC_EN_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_OSC_EN_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_GATE_MASK (0x80U)
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_GATE_SHIFT (7U)
/*! OSC_24M_GATE - 24MHz OSC Gate Control
 *  0b0..Not Gated
 *  0b1..Gated
 */
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_GATE(x)  (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_OSC_24M_GATE_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_OSC_24M_GATE_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_STABLE_MASK (0x40000000U)
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_STABLE_SHIFT (30U)
/*! OSC_24M_STABLE - 24MHz OSC Stable
 *  0b0..Not Stable
 *  0b1..Stable
 */
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_STABLE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_OSC_24M_STABLE_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_OSC_24M_STABLE_MASK)

#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_CONTROL_MODE_MASK (0x80000000U)
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_CONTROL_MODE_SHIFT (31U)
/*! OSC_24M_CONTROL_MODE - 24MHz OSC Control Mode
 *  0b0..Software mode (default)
 *  0b1..GPC mode
 */
#define ANADIG_OSC_OSC_24M_CTRL_OSC_24M_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_24M_CTRL_OSC_24M_CONTROL_MODE_SHIFT)) & ANADIG_OSC_OSC_24M_CTRL_OSC_24M_CONTROL_MODE_MASK)
/*! @} */

/*! @name OSC_400M_CTRL0 - 400MHz RCOSC Control0 Register */
/*! @{ */

#define ANADIG_OSC_OSC_400M_CTRL0_OSC400M_AI_BUSY_MASK (0x80000000U)
#define ANADIG_OSC_OSC_400M_CTRL0_OSC400M_AI_BUSY_SHIFT (31U)
/*! OSC400M_AI_BUSY - 400MHz OSC AI BUSY */
#define ANADIG_OSC_OSC_400M_CTRL0_OSC400M_AI_BUSY(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_400M_CTRL0_OSC400M_AI_BUSY_SHIFT)) & ANADIG_OSC_OSC_400M_CTRL0_OSC400M_AI_BUSY_MASK)
/*! @} */

/*! @name OSC_400M_CTRL1 - 400MHz RCOSC Control1 Register */
/*! @{ */

#define ANADIG_OSC_OSC_400M_CTRL1_PWD_MASK       (0x1U)
#define ANADIG_OSC_OSC_400M_CTRL1_PWD_SHIFT      (0U)
/*! PWD - Power down control for 400MHz RCOSC
 *  0b0..No Power down
 *  0b1..Power down
 */
#define ANADIG_OSC_OSC_400M_CTRL1_PWD(x)         (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_400M_CTRL1_PWD_SHIFT)) & ANADIG_OSC_OSC_400M_CTRL1_PWD_MASK)

#define ANADIG_OSC_OSC_400M_CTRL1_CLKGATE_400MEG_MASK (0x2U)
#define ANADIG_OSC_OSC_400M_CTRL1_CLKGATE_400MEG_SHIFT (1U)
/*! CLKGATE_400MEG - Clock gate control for 400MHz RCOSC
 *  0b0..Not Gated
 *  0b1..Gated
 */
#define ANADIG_OSC_OSC_400M_CTRL1_CLKGATE_400MEG(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_400M_CTRL1_CLKGATE_400MEG_SHIFT)) & ANADIG_OSC_OSC_400M_CTRL1_CLKGATE_400MEG_MASK)

#define ANADIG_OSC_OSC_400M_CTRL1_RC_400M_CONTROL_MODE_MASK (0x80000000U)
#define ANADIG_OSC_OSC_400M_CTRL1_RC_400M_CONTROL_MODE_SHIFT (31U)
/*! RC_400M_CONTROL_MODE - 400MHz RCOSC Control mode
 *  0b0..Software mode (default)
 *  0b1..GPC mode
 */
#define ANADIG_OSC_OSC_400M_CTRL1_RC_400M_CONTROL_MODE(x) (((uint32_t)(((uint32_t)(x)) << ANADIG_OSC_OSC_400M_CTRL1_RC_400M_CONTROL_MODE_SHIFT)) & ANADIG_OSC_OSC_400M_CTRL1_RC_400M_CONTROL_MODE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ANADIG_OSC_Register_Masks */


/*!
 * @}
 */ /* end of group ANADIG_OSC_Peripheral_Access_Layer */


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


#endif  /* PERI_ANADIG_OSC_H_ */

