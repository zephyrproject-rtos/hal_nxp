/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for OSC32KNP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_OSC32KNP.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for OSC32KNP
 *
 * CMSIS Peripheral Access Layer for OSC32KNP
 */

#if !defined(PERI_OSC32KNP_H_)
#define PERI_OSC32KNP_H_                         /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- OSC32KNP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC32KNP_Peripheral_Access_Layer OSC32KNP Peripheral Access Layer
 * @{
 */

/** OSC32KNP - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< Control, offset: 0x0 */
       uint8_t RESERVED_0[4];
  __IO uint32_t STAT;                              /**< Clock Status, offset: 0x8 */
} OSC32KNP_Type;

/* ----------------------------------------------------------------------------
   -- OSC32KNP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC32KNP_Register_Masks OSC32KNP Register Masks
 * @{
 */

/*! @name CTRL - Control */
/*! @{ */

#define OSC32KNP_CTRL_OSC_DIS_MASK               (0x1U)
#define OSC32KNP_CTRL_OSC_DIS_SHIFT              (0U)
/*! OSC_DIS - Oscillator Output Disable
 *  0b0..Enable the oscillator output
 *  0b1..Disable the oscillator output
 */
#define OSC32KNP_CTRL_OSC_DIS(x)                 (((uint32_t)(((uint32_t)(x)) << OSC32KNP_CTRL_OSC_DIS_SHIFT)) & OSC32KNP_CTRL_OSC_DIS_MASK)

#define OSC32KNP_CTRL_MODE_MASK                  (0x2U)
#define OSC32KNP_CTRL_MODE_SHIFT                 (1U)
/*! MODE - Mode
 *  0b0..Low-Power (Nano-Power) mode
 *  0b1..High-Power mode
 */
#define OSC32KNP_CTRL_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << OSC32KNP_CTRL_MODE_SHIFT)) & OSC32KNP_CTRL_MODE_MASK)

#define OSC32KNP_CTRL_BYPASS_EN_MASK             (0x4U)
#define OSC32KNP_CTRL_BYPASS_EN_SHIFT            (2U)
/*! BYPASS_EN - Bypass Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define OSC32KNP_CTRL_BYPASS_EN(x)               (((uint32_t)(((uint32_t)(x)) << OSC32KNP_CTRL_BYPASS_EN_SHIFT)) & OSC32KNP_CTRL_BYPASS_EN_MASK)

#define OSC32KNP_CTRL_CAP_TRIM_MASK              (0xF00U)
#define OSC32KNP_CTRL_CAP_TRIM_SHIFT             (8U)
/*! CAP_TRIM - Capacitor Trim Value
 *  0b0000..0 pF
 *  0b0001..2 pF
 *  0b0010..4 pF
 *  0b0011..6 pF
 *  0b0100..8 pF
 *  0b0101..10 pF
 *  0b0110..12 pF
 *  0b0111..14 pF
 *  0b1000..16 pF
 *  0b1001..18 pF
 *  0b1010..20 pF
 *  0b1011..22 pF
 *  0b1100..24 pF
 *  0b1101..26 pF
 *  0b1110..28 pF
 *  0b1111..30 pF
 */
#define OSC32KNP_CTRL_CAP_TRIM(x)                (((uint32_t)(((uint32_t)(x)) << OSC32KNP_CTRL_CAP_TRIM_SHIFT)) & OSC32KNP_CTRL_CAP_TRIM_MASK)

#define OSC32KNP_CTRL_CLKMON_EN_MASK             (0x10000U)
#define OSC32KNP_CTRL_CLKMON_EN_SHIFT            (16U)
/*! CLKMON_EN - Clock Monitor Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define OSC32KNP_CTRL_CLKMON_EN(x)               (((uint32_t)(((uint32_t)(x)) << OSC32KNP_CTRL_CLKMON_EN_SHIFT)) & OSC32KNP_CTRL_CLKMON_EN_MASK)
/*! @} */

/*! @name STAT - Clock Status */
/*! @{ */

#define OSC32KNP_STAT_TCXO_STABLE_MASK           (0x1U)
#define OSC32KNP_STAT_TCXO_STABLE_SHIFT          (0U)
/*! TCXO_STABLE - Startup Oscillator (TCXO) Stable
 *  0b0..Unstable
 *  0b1..Stable
 */
#define OSC32KNP_STAT_TCXO_STABLE(x)             (((uint32_t)(((uint32_t)(x)) << OSC32KNP_STAT_TCXO_STABLE_SHIFT)) & OSC32KNP_STAT_TCXO_STABLE_MASK)

#define OSC32KNP_STAT_SCXO_STABLE_MASK           (0x2U)
#define OSC32KNP_STAT_SCXO_STABLE_SHIFT          (1U)
/*! SCXO_STABLE - Self-Charge Oscillator (SCXO) Stable
 *  0b0..Unstable
 *  0b1..Stable
 */
#define OSC32KNP_STAT_SCXO_STABLE(x)             (((uint32_t)(((uint32_t)(x)) << OSC32KNP_STAT_SCXO_STABLE_SHIFT)) & OSC32KNP_STAT_SCXO_STABLE_MASK)

#define OSC32KNP_STAT_CLK_TAMPER_DETECTED_MASK   (0x100U)
#define OSC32KNP_STAT_CLK_TAMPER_DETECTED_SHIFT  (8U)
/*! CLK_TAMPER_DETECTED - Clock Tamper Detected
 *  0b0..Not detected
 *  0b1..Detected
 */
#define OSC32KNP_STAT_CLK_TAMPER_DETECTED(x)     (((uint32_t)(((uint32_t)(x)) << OSC32KNP_STAT_CLK_TAMPER_DETECTED_SHIFT)) & OSC32KNP_STAT_CLK_TAMPER_DETECTED_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group OSC32KNP_Register_Masks */


/*!
 * @}
 */ /* end of group OSC32KNP_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_OSC32KNP_H_ */

