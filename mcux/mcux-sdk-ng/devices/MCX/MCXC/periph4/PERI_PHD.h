/*
** ###################################################################
**     Processors:          MCXC352GAMFM
**                          MCXC352GAMFT
**                          MCXC352MLF
**                          MCXC353GAMFM
**                          MCXC353GAMFT
**                          MCXC353MLF
**
**     Version:             rev. 1.0, 2025-11-26
**     Build:               b260826
**
**     Abstract:
**         CMSIS Peripheral Access Layer for PHD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-11-26)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_PHD.h
 * @version 1.0
 * @date 2025-11-26
 * @brief CMSIS Peripheral Access Layer for PHD
 *
 * CMSIS Peripheral Access Layer for PHD
 */

#if !defined(PERI_PHD_H_)
#define PERI_PHD_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXC352GAMFM) || defined(CPU_MCXC352GAMFT) || defined(CPU_MCXC352MLF))
#include "MCXC352_COMMON.h"
#elif (defined(CPU_MCXC353GAMFM) || defined(CPU_MCXC353GAMFT) || defined(CPU_MCXC353MLF))
#include "MCXC353_COMMON.h"
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
   -- PHD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHD_Peripheral_Access_Layer PHD Peripheral Access Layer
 * @{
 */

/** PHD - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PHCMP0CR;                          /**< Phase Detector Comparator 0 Control Register, offset: 0x10 */
  __IO uint32_t PHCMP0SCR;                         /**< Phase Detector Comparator 0 Status and Control Register, offset: 0x14 */
       uint8_t RESERVED_1[8];
  __IO uint32_t PHCMP1CR;                          /**< Phase Detector Comparator 1 Control Register, offset: 0x20 */
  __IO uint32_t PHCMP1SCR;                         /**< Phase Detector Comparator 1 Status and Control Register, offset: 0x24 */
       uint8_t RESERVED_2[8];
  __IO uint32_t PHCMP2CR;                          /**< Phase Detector Comparator 2 Control Register, offset: 0x30 */
  __IO uint32_t PHCMP2SCR;                         /**< Phase Detector Comparator 2 Status and Control Register, offset: 0x34 */
       uint8_t RESERVED_3[8];
  __IO uint32_t PHASECTRL;                         /**< Phase Detector Control Register, offset: 0x40 */
  __I  uint32_t PHASESTAT;                         /**< Phase Detector Status Register, offset: 0x44 */
} PHD_Type;

/* ----------------------------------------------------------------------------
   -- PHD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHD_Register_Masks PHD Register Masks
 * @{
 */

/*! @name VERID - Version ID */
/*! @{ */

#define PHD_VERID_FEATURE_MASK                   (0xFFFFU)
#define PHD_VERID_FEATURE_SHIFT                  (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000001..Round robin feature
 */
#define PHD_VERID_FEATURE(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_VERID_FEATURE_SHIFT)) & PHD_VERID_FEATURE_MASK)

#define PHD_VERID_MINOR_MASK                     (0xFF0000U)
#define PHD_VERID_MINOR_SHIFT                    (16U)
/*! MINOR - Minor Version Number */
#define PHD_VERID_MINOR(x)                       (((uint32_t)(((uint32_t)(x)) << PHD_VERID_MINOR_SHIFT)) & PHD_VERID_MINOR_MASK)

#define PHD_VERID_MAJOR_MASK                     (0xFF000000U)
#define PHD_VERID_MAJOR_SHIFT                    (24U)
/*! MAJOR - Major Version Number */
#define PHD_VERID_MAJOR(x)                       (((uint32_t)(((uint32_t)(x)) << PHD_VERID_MAJOR_SHIFT)) & PHD_VERID_MAJOR_MASK)
/*! @} */

/*! @name PHCMP0CR - Phase Detector Comparator 0 Control Register */
/*! @{ */

#define PHD_PHCMP0CR_COUT_PEN_MASK               (0x1U)
#define PHD_PHCMP0CR_COUT_PEN_SHIFT              (0U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define PHD_PHCMP0CR_COUT_PEN(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0CR_COUT_PEN_SHIFT)) & PHD_PHCMP0CR_COUT_PEN_MASK)

#define PHD_PHCMP0CR_COUT_SEL_MASK               (0x2U)
#define PHD_PHCMP0CR_COUT_SEL_SHIFT              (1U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define PHD_PHCMP0CR_COUT_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0CR_COUT_SEL_SHIFT)) & PHD_PHCMP0CR_COUT_SEL_MASK)

#define PHD_PHCMP0CR_COUT_INV_MASK               (0x4U)
#define PHD_PHCMP0CR_COUT_INV_SHIFT              (2U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define PHD_PHCMP0CR_COUT_INV(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0CR_COUT_INV_SHIFT)) & PHD_PHCMP0CR_COUT_INV_MASK)

#define PHD_PHCMP0CR_WINDOW_EN_MASK              (0x10U)
#define PHD_PHCMP0CR_WINDOW_EN_SHIFT             (4U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP0CR_WINDOW_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0CR_WINDOW_EN_SHIFT)) & PHD_PHCMP0CR_WINDOW_EN_MASK)

#define PHD_PHCMP0CR_SAMPLE_EN_MASK              (0x20U)
#define PHD_PHCMP0CR_SAMPLE_EN_SHIFT             (5U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP0CR_SAMPLE_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0CR_SAMPLE_EN_SHIFT)) & PHD_PHCMP0CR_SAMPLE_EN_MASK)
/*! @} */

/*! @name PHCMP0SCR - Phase Detector Comparator 0 Status and Control Register */
/*! @{ */

#define PHD_PHCMP0SCR_COUT_MASK                  (0x1U)
#define PHD_PHCMP0SCR_COUT_SHIFT                 (0U)
/*! COUT - Analog Comparator Output */
#define PHD_PHCMP0SCR_COUT(x)                    (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0SCR_COUT_SHIFT)) & PHD_PHCMP0SCR_COUT_MASK)

#define PHD_PHCMP0SCR_CFF_MASK                   (0x2U)
#define PHD_PHCMP0SCR_CFF_SHIFT                  (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP0SCR_CFF(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0SCR_CFF_SHIFT)) & PHD_PHCMP0SCR_CFF_MASK)

#define PHD_PHCMP0SCR_CFR_MASK                   (0x4U)
#define PHD_PHCMP0SCR_CFR_SHIFT                  (2U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP0SCR_CFR(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0SCR_CFR_SHIFT)) & PHD_PHCMP0SCR_CFR_MASK)

#define PHD_PHCMP0SCR_CFF_IE_MASK                (0x10U)
#define PHD_PHCMP0SCR_CFF_IE_SHIFT               (4U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disables the comparator flag falling interrupt.
 *  0b1..Enables the comparator flag falling interrupt when CFF is set.
 */
#define PHD_PHCMP0SCR_CFF_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0SCR_CFF_IE_SHIFT)) & PHD_PHCMP0SCR_CFF_IE_MASK)

#define PHD_PHCMP0SCR_CFR_IE_MASK                (0x20U)
#define PHD_PHCMP0SCR_CFR_IE_SHIFT               (5U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disables the comparator flag rising interrupt.
 *  0b1..Enables the comparator flag rising interrupt when CFR is set.
 */
#define PHD_PHCMP0SCR_CFR_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP0SCR_CFR_IE_SHIFT)) & PHD_PHCMP0SCR_CFR_IE_MASK)
/*! @} */

/*! @name PHCMP1CR - Phase Detector Comparator 1 Control Register */
/*! @{ */

#define PHD_PHCMP1CR_COUT_PEN_MASK               (0x1U)
#define PHD_PHCMP1CR_COUT_PEN_SHIFT              (0U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define PHD_PHCMP1CR_COUT_PEN(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1CR_COUT_PEN_SHIFT)) & PHD_PHCMP1CR_COUT_PEN_MASK)

#define PHD_PHCMP1CR_COUT_SEL_MASK               (0x2U)
#define PHD_PHCMP1CR_COUT_SEL_SHIFT              (1U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define PHD_PHCMP1CR_COUT_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1CR_COUT_SEL_SHIFT)) & PHD_PHCMP1CR_COUT_SEL_MASK)

#define PHD_PHCMP1CR_COUT_INV_MASK               (0x4U)
#define PHD_PHCMP1CR_COUT_INV_SHIFT              (2U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define PHD_PHCMP1CR_COUT_INV(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1CR_COUT_INV_SHIFT)) & PHD_PHCMP1CR_COUT_INV_MASK)

#define PHD_PHCMP1CR_WINDOW_EN_MASK              (0x10U)
#define PHD_PHCMP1CR_WINDOW_EN_SHIFT             (4U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP1CR_WINDOW_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1CR_WINDOW_EN_SHIFT)) & PHD_PHCMP1CR_WINDOW_EN_MASK)

#define PHD_PHCMP1CR_SAMPLE_EN_MASK              (0x20U)
#define PHD_PHCMP1CR_SAMPLE_EN_SHIFT             (5U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP1CR_SAMPLE_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1CR_SAMPLE_EN_SHIFT)) & PHD_PHCMP1CR_SAMPLE_EN_MASK)
/*! @} */

/*! @name PHCMP1SCR - Phase Detector Comparator 1 Status and Control Register */
/*! @{ */

#define PHD_PHCMP1SCR_COUT_MASK                  (0x1U)
#define PHD_PHCMP1SCR_COUT_SHIFT                 (0U)
/*! COUT - Analog Comparator Output */
#define PHD_PHCMP1SCR_COUT(x)                    (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1SCR_COUT_SHIFT)) & PHD_PHCMP1SCR_COUT_MASK)

#define PHD_PHCMP1SCR_CFF_MASK                   (0x2U)
#define PHD_PHCMP1SCR_CFF_SHIFT                  (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP1SCR_CFF(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1SCR_CFF_SHIFT)) & PHD_PHCMP1SCR_CFF_MASK)

#define PHD_PHCMP1SCR_CFR_MASK                   (0x4U)
#define PHD_PHCMP1SCR_CFR_SHIFT                  (2U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP1SCR_CFR(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1SCR_CFR_SHIFT)) & PHD_PHCMP1SCR_CFR_MASK)

#define PHD_PHCMP1SCR_CFF_IE_MASK                (0x10U)
#define PHD_PHCMP1SCR_CFF_IE_SHIFT               (4U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disables the comparator flag falling interrupt.
 *  0b1..Enables the comparator flag falling interrupt when CFF is set.
 */
#define PHD_PHCMP1SCR_CFF_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1SCR_CFF_IE_SHIFT)) & PHD_PHCMP1SCR_CFF_IE_MASK)

#define PHD_PHCMP1SCR_CFR_IE_MASK                (0x20U)
#define PHD_PHCMP1SCR_CFR_IE_SHIFT               (5U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disables the comparator flag rising interrupt.
 *  0b1..Enables the comparator flag rising interrupt when CFR is set.
 */
#define PHD_PHCMP1SCR_CFR_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP1SCR_CFR_IE_SHIFT)) & PHD_PHCMP1SCR_CFR_IE_MASK)
/*! @} */

/*! @name PHCMP2CR - Phase Detector Comparator 2 Control Register */
/*! @{ */

#define PHD_PHCMP2CR_COUT_PEN_MASK               (0x1U)
#define PHD_PHCMP2CR_COUT_PEN_SHIFT              (0U)
/*! COUT_PEN - Comparator Output Pin Enable
 *  0b0..Not available
 *  0b1..Available
 */
#define PHD_PHCMP2CR_COUT_PEN(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2CR_COUT_PEN_SHIFT)) & PHD_PHCMP2CR_COUT_PEN_MASK)

#define PHD_PHCMP2CR_COUT_SEL_MASK               (0x2U)
#define PHD_PHCMP2CR_COUT_SEL_SHIFT              (1U)
/*! COUT_SEL - Comparator Output Select
 *  0b0..Use COUT (filtered)
 *  0b1..Use COUTA (unfiltered)
 */
#define PHD_PHCMP2CR_COUT_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2CR_COUT_SEL_SHIFT)) & PHD_PHCMP2CR_COUT_SEL_MASK)

#define PHD_PHCMP2CR_COUT_INV_MASK               (0x4U)
#define PHD_PHCMP2CR_COUT_INV_SHIFT              (2U)
/*! COUT_INV - Comparator Invert
 *  0b0..Do not invert
 *  0b1..Invert
 */
#define PHD_PHCMP2CR_COUT_INV(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2CR_COUT_INV_SHIFT)) & PHD_PHCMP2CR_COUT_INV_MASK)

#define PHD_PHCMP2CR_WINDOW_EN_MASK              (0x10U)
#define PHD_PHCMP2CR_WINDOW_EN_SHIFT             (4U)
/*! WINDOW_EN - Windowing Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP2CR_WINDOW_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2CR_WINDOW_EN_SHIFT)) & PHD_PHCMP2CR_WINDOW_EN_MASK)

#define PHD_PHCMP2CR_SAMPLE_EN_MASK              (0x20U)
#define PHD_PHCMP2CR_SAMPLE_EN_SHIFT             (5U)
/*! SAMPLE_EN - Sampling Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PHD_PHCMP2CR_SAMPLE_EN(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2CR_SAMPLE_EN_SHIFT)) & PHD_PHCMP2CR_SAMPLE_EN_MASK)
/*! @} */

/*! @name PHCMP2SCR - Phase Detector Comparator 2 Status and Control Register */
/*! @{ */

#define PHD_PHCMP2SCR_COUT_MASK                  (0x1U)
#define PHD_PHCMP2SCR_COUT_SHIFT                 (0U)
/*! COUT - Analog Comparator Output */
#define PHD_PHCMP2SCR_COUT(x)                    (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2SCR_COUT_SHIFT)) & PHD_PHCMP2SCR_COUT_MASK)

#define PHD_PHCMP2SCR_CFF_MASK                   (0x2U)
#define PHD_PHCMP2SCR_CFF_SHIFT                  (1U)
/*! CFF - Analog Comparator Flag Falling
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP2SCR_CFF(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2SCR_CFF_SHIFT)) & PHD_PHCMP2SCR_CFF_MASK)

#define PHD_PHCMP2SCR_CFR_MASK                   (0x4U)
#define PHD_PHCMP2SCR_CFR_SHIFT                  (2U)
/*! CFR - Analog Comparator Flag Rising
 *  0b0..Not detected
 *  0b1..Detected
 */
#define PHD_PHCMP2SCR_CFR(x)                     (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2SCR_CFR_SHIFT)) & PHD_PHCMP2SCR_CFR_MASK)

#define PHD_PHCMP2SCR_CFF_IE_MASK                (0x10U)
#define PHD_PHCMP2SCR_CFF_IE_SHIFT               (4U)
/*! CFF_IE - Comparator Flag Falling Interrupt Enable
 *  0b0..Disables the comparator flag falling interrupt.
 *  0b1..Enables the comparator flag falling interrupt when CFF is set.
 */
#define PHD_PHCMP2SCR_CFF_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2SCR_CFF_IE_SHIFT)) & PHD_PHCMP2SCR_CFF_IE_MASK)

#define PHD_PHCMP2SCR_CFR_IE_MASK                (0x20U)
#define PHD_PHCMP2SCR_CFR_IE_SHIFT               (5U)
/*! CFR_IE - Comparator Flag Rising Interrupt Enable
 *  0b0..Disables the comparator flag rising interrupt.
 *  0b1..Enables the comparator flag rising interrupt when CFR is set.
 */
#define PHD_PHCMP2SCR_CFR_IE(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHCMP2SCR_CFR_IE_SHIFT)) & PHD_PHCMP2SCR_CFR_IE_MASK)
/*! @} */

/*! @name PHASECTRL - Phase Detector Control Register */
/*! @{ */

#define PHD_PHASECTRL_CMP_EN_MASK                (0x1U)
#define PHD_PHASECTRL_CMP_EN_SHIFT               (0U)
/*! CMP_EN - Comparator Enable
 *  0b0..Disable (The analog logic remains off and consumes no power.)
 *  0b1..Enable
 */
#define PHD_PHASECTRL_CMP_EN(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_CMP_EN_SHIFT)) & PHD_PHASECTRL_CMP_EN_MASK)

#define PHD_PHASECTRL_CMP_STOP_EN_MASK           (0x2U)
#define PHD_PHASECTRL_CMP_STOP_EN_SHIFT          (1U)
/*! CMP_STOP_EN - Comparator Stop Mode Enable
 *  0b0..Disables the analog comparator regardless of CMP_EN.
 *  0b1..Allows CMP_EN to enable the analog comparator.
 */
#define PHD_PHASECTRL_CMP_STOP_EN(x)             (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_CMP_STOP_EN_SHIFT)) & PHD_PHASECTRL_CMP_STOP_EN_MASK)

#define PHD_PHASECTRL_HYSTCTR_MASK               (0xCU)
#define PHD_PHASECTRL_HYSTCTR_SHIFT              (2U)
/*! HYSTCTR - Comparator Hysteresis Control
 *  0b00..Level 0: Analog comparator hysteresis 0 mV.
 *  0b01..Level 1: Analog comparator hysteresis 10 mV.
 *  0b10..Level 2: Analog comparator hysteresis 20 mV.
 *  0b11..Level 3: Analog comparator hysteresis 30 mV.
 */
#define PHD_PHASECTRL_HYSTCTR(x)                 (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_HYSTCTR_SHIFT)) & PHD_PHASECTRL_HYSTCTR_MASK)

#define PHD_PHASECTRL_FUNC_CLK_SEL_MASK          (0x30U)
#define PHD_PHASECTRL_FUNC_CLK_SEL_SHIFT         (4U)
/*! FUNC_CLK_SEL - Functional Clock Source Select
 *  0b00..Select functional clock source 0
 *  0b01..Select functional clock source 1
 *  0b10..Select functional clock source 2
 *  0b11..Select functional clock source 3
 */
#define PHD_PHASECTRL_FUNC_CLK_SEL(x)            (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_FUNC_CLK_SEL_SHIFT)) & PHD_PHASECTRL_FUNC_CLK_SEL_MASK)

#define PHD_PHASECTRL_PHSEL0_MASK                (0x100U)
#define PHD_PHASECTRL_PHSEL0_SHIFT               (8U)
/*! PHSEL0 - Virtual Network Phase 0 Selection
 *  0b0..Phase 0 is off.
 *  0b1..Phase 0 is on.
 */
#define PHD_PHASECTRL_PHSEL0(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_PHSEL0_SHIFT)) & PHD_PHASECTRL_PHSEL0_MASK)

#define PHD_PHASECTRL_PHSEL1_MASK                (0x200U)
#define PHD_PHASECTRL_PHSEL1_SHIFT               (9U)
/*! PHSEL1 - Virtual Network Phase 1 Selection
 *  0b0..Phase 1 is off.
 *  0b1..Phase 1 is on.
 */
#define PHD_PHASECTRL_PHSEL1(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_PHSEL1_SHIFT)) & PHD_PHASECTRL_PHSEL1_MASK)

#define PHD_PHASECTRL_PHSEL2_MASK                (0x400U)
#define PHD_PHASECTRL_PHSEL2_SHIFT               (10U)
/*! PHSEL2 - Virtual Network Phase 2 Selection
 *  0b0..Phase 2 is off.
 *  0b1..Phase 2 is on.
 */
#define PHD_PHASECTRL_PHSEL2(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_PHSEL2_SHIFT)) & PHD_PHASECTRL_PHSEL2_MASK)

#define PHD_PHASECTRL_EXTSEL_MASK                (0x1000U)
#define PHD_PHASECTRL_EXTSEL_SHIFT               (12U)
/*! EXTSEL - Virtual Neutral External Connection
 *  0b0..EXTSEL MUX disabled.
 *  0b1..EXTSET MUX enabled, virtual neutral is connected to the external pin.
 */
#define PHD_PHASECTRL_EXTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_EXTSEL_SHIFT)) & PHD_PHASECTRL_EXTSEL_MASK)

#define PHD_PHASECTRL_INTSEL_MASK                (0x2000U)
#define PHD_PHASECTRL_INTSEL_SHIFT               (13U)
/*! INTSEL - Virtual Neutral Internal Connection
 *  0b0..INTSEL MUX disabled.
 *  0b1..INTSET MUX enabled, virtual neutral is connected to the internal 8-bit DAC in the CMP module.
 */
#define PHD_PHASECTRL_INTSEL(x)                  (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_INTSEL_SHIFT)) & PHD_PHASECTRL_INTSEL_MASK)

#define PHD_PHASECTRL_VNEN_MASK                  (0x4000U)
#define PHD_PHASECTRL_VNEN_SHIFT                 (14U)
/*! VNEN - Virtual Neutral Enable
 *  0b0..Virtual resistor network disabled.
 *  0b1..Virtual resistor network enabled.
 */
#define PHD_PHASECTRL_VNEN(x)                    (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_VNEN_SHIFT)) & PHD_PHASECTRL_VNEN_MASK)

#define PHD_PHASECTRL_IBIAS_TRIM_MASK            (0x8000U)
#define PHD_PHASECTRL_IBIAS_TRIM_SHIFT           (15U)
/*! IBIAS_TRIM - IBIAS TRIM
 *  0b0..IBIAS trim value 0.
 *  0b1..IBIAS trim value 1.
 */
#define PHD_PHASECTRL_IBIAS_TRIM(x)              (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_IBIAS_TRIM_SHIFT)) & PHD_PHASECTRL_IBIAS_TRIM_MASK)

#define PHD_PHASECTRL_FILT_CNT_MASK              (0x70000U)
#define PHD_PHASECTRL_FILT_CNT_SHIFT             (16U)
/*! FILT_CNT - Filter Sample Count
 *  0b000..Filter is bypassed: COUT = COUTA
 *  0b001..1 consecutive sample (Comparator output is simply sampled.)
 *  0b010..2 consecutive samples
 *  0b011..3 consecutive samples
 *  0b100..4 consecutive samples
 *  0b101..5 consecutive samples
 *  0b110..6 consecutive samples
 *  0b111..7 consecutive samples
 */
#define PHD_PHASECTRL_FILT_CNT(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_FILT_CNT_SHIFT)) & PHD_PHASECTRL_FILT_CNT_MASK)

#define PHD_PHASECTRL_FILT_PER_MASK              (0xFF000000U)
#define PHD_PHASECTRL_FILT_PER_SHIFT             (24U)
/*! FILT_PER - Filter Sample Period */
#define PHD_PHASECTRL_FILT_PER(x)                (((uint32_t)(((uint32_t)(x)) << PHD_PHASECTRL_FILT_PER_SHIFT)) & PHD_PHASECTRL_FILT_PER_MASK)
/*! @} */

/*! @name PHASESTAT - Phase Detector Status Register */
/*! @{ */

#define PHD_PHASESTAT_PHASE_MASK                 (0x7U)
#define PHD_PHASESTAT_PHASE_SHIFT                (0U)
/*! PHASE - Phase Status */
#define PHD_PHASESTAT_PHASE(x)                   (((uint32_t)(((uint32_t)(x)) << PHD_PHASESTAT_PHASE_SHIFT)) & PHD_PHASESTAT_PHASE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PHD_Register_Masks */


/*!
 * @}
 */ /* end of group PHD_Peripheral_Access_Layer */


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


#endif  /* PERI_PHD_H_ */

