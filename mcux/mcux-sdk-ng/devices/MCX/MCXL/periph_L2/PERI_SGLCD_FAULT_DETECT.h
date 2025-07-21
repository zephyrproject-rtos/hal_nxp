/*
** ###################################################################
**     Processors:          MCXL253VDF_cm0plus
**                          MCXL253VDF_cm33
**                          MCXL253VLL_cm0plus
**                          MCXL253VLL_cm33
**                          MCXL254VDF_cm0plus
**                          MCXL254VDF_cm33
**                          MCXL254VLL_cm0plus
**                          MCXL254VLL_cm33
**                          MCXL255VDF_cm0plus
**                          MCXL255VDF_cm33
**                          MCXL255VLL_cm0plus
**                          MCXL255VLL_cm33
**
**     Version:             rev. 1.0, 2023-01-09
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SGLCD_FAULT_DETECT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-09)
**         Generated based on Rev1 DraftI.
**
** ###################################################################
*/

/*!
 * @file PERI_SGLCD_FAULT_DETECT.h
 * @version 1.0
 * @date 2023-01-09
 * @brief CMSIS Peripheral Access Layer for SGLCD_FAULT_DETECT
 *
 * CMSIS Peripheral Access Layer for SGLCD_FAULT_DETECT
 */

#if !defined(PERI_SGLCD_FAULT_DETECT_H_)
#define PERI_SGLCD_FAULT_DETECT_H_               /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXL253VDF_cm0plus) || defined(CPU_MCXL253VLL_cm0plus))
#include "MCXL253_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL253VDF_cm33) || defined(CPU_MCXL253VLL_cm33))
#include "MCXL253_cm33_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm0plus) || defined(CPU_MCXL254VLL_cm0plus))
#include "MCXL254_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL254VDF_cm33) || defined(CPU_MCXL254VLL_cm33))
#include "MCXL254_cm33_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm0plus) || defined(CPU_MCXL255VLL_cm0plus))
#include "MCXL255_cm0plus_COMMON.h"
#elif (defined(CPU_MCXL255VDF_cm33) || defined(CPU_MCXL255VLL_cm33))
#include "MCXL255_cm33_COMMON.h"
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
   -- SGLCD_FAULT_DETECT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGLCD_FAULT_DETECT_Peripheral_Access_Layer SGLCD_FAULT_DETECT Peripheral Access Layer
 * @{
 */

/** SGLCD_FAULT_DETECT - Size of Registers Arrays */
#define SGLCD_FAULT_DETECT_PEN_DUP_COUNT          2u
#define SGLCD_FAULT_DETECT_BPEN_DUP_COUNT         2u

/** SGLCD_FAULT_DETECT - Register Layout Typedef */
typedef struct {
  __IO uint32_t FDCR;                              /**< LCD Fault Detect Control Register, offset: 0x0 */
  __IO uint32_t FDSR;                              /**< LCD Fault Detect Status Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PEN_DUP[SGLCD_FAULT_DETECT_PEN_DUP_COUNT]; /**< LCD Pin Enable register 0..LCD Pin Enable register 1, array offset: 0x10, array step: 0x4 */
  __IO uint32_t BPEN_DUP[SGLCD_FAULT_DETECT_BPEN_DUP_COUNT]; /**< LCD Back Plane Enable register 0..LCD Back Plane Enable register 1, array offset: 0x18, array step: 0x4 */
} SGLCD_FAULT_DETECT_Type;

/* ----------------------------------------------------------------------------
   -- SGLCD_FAULT_DETECT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SGLCD_FAULT_DETECT_Register_Masks SGLCD_FAULT_DETECT Register Masks
 * @{
 */

/*! @name FDCR - LCD Fault Detect Control Register */
/*! @{ */

#define SGLCD_FAULT_DETECT_FDCR_FDPINID_MASK     (0x3FU)
#define SGLCD_FAULT_DETECT_FDCR_FDPINID_SHIFT    (0U)
/*! FDPINID - Fault Detect Pin ID */
#define SGLCD_FAULT_DETECT_FDCR_FDPINID(x)       (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDPINID_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDPINID_MASK)

#define SGLCD_FAULT_DETECT_FDCR_FDBPEN_MASK      (0x40U)
#define SGLCD_FAULT_DETECT_FDCR_FDBPEN_SHIFT     (6U)
/*! FDBPEN - Fault Detect Back Plane Enable
 *  0b0..Type of the selected pin under fault detect test is front plane.
 *  0b1..Type of the selected pin under fault detect test is back plane.
 */
#define SGLCD_FAULT_DETECT_FDCR_FDBPEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDBPEN_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDBPEN_MASK)

#define SGLCD_FAULT_DETECT_FDCR_FDEN_MASK        (0x80U)
#define SGLCD_FAULT_DETECT_FDCR_FDEN_SHIFT       (7U)
/*! FDEN - Fault Detect Enable
 *  0b0..Disable fault detection.
 *  0b1..Enable fault detection.
 */
#define SGLCD_FAULT_DETECT_FDCR_FDEN(x)          (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDEN_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDEN_MASK)

#define SGLCD_FAULT_DETECT_FDCR_FDSWW_MASK       (0xE00U)
#define SGLCD_FAULT_DETECT_FDCR_FDSWW_SHIFT      (9U)
/*! FDSWW - Fault Detect Sample Window Width
 *  0b000..Sample window width is 4 sample clock cycles.
 *  0b001..Sample window width is 8 sample clock cycles.
 *  0b010..Sample window width is 16 sample clock cycles.
 *  0b011..Sample window width is 32 sample clock cycles.
 *  0b100..Sample window width is 64 sample clock cycles.
 *  0b101..Sample window width is 128 sample clock cycles.
 *  0b110..Sample window width is 256 sample clock cycles.
 *  0b111..Sample window width is 512 sample clock cycles.
 */
#define SGLCD_FAULT_DETECT_FDCR_FDSWW(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDSWW_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDSWW_MASK)

#define SGLCD_FAULT_DETECT_FDCR_FDPRS_MASK       (0x7000U)
#define SGLCD_FAULT_DETECT_FDCR_FDPRS_SHIFT      (12U)
/*! FDPRS - Fault Detect Clock Prescaler
 *  0b000..1/1 bus clock.
 *  0b001..1/2 bus clock.
 *  0b010..1/4 bus clock.
 *  0b011..1/8 bus clock.
 *  0b100..1/16 bus clock.
 *  0b101..1/32 bus clock.
 *  0b110..1/64 bus clock.
 *  0b111..1/128 bus clock.
 */
#define SGLCD_FAULT_DETECT_FDCR_FDPRS(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDPRS_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDPRS_MASK)

#define SGLCD_FAULT_DETECT_FDCR_FDCIEN_MASK      (0x8000U)
#define SGLCD_FAULT_DETECT_FDCR_FDCIEN_SHIFT     (15U)
/*! FDCIEN - LCD Fault Detection Complete Interrupt Enable
 *  0b0..No interrupt request is generated by this event.
 *  0b1..When a fault is detected and FDCF bit is set, this event causes an interrupt request.
 */
#define SGLCD_FAULT_DETECT_FDCR_FDCIEN(x)        (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDCR_FDCIEN_SHIFT)) & SGLCD_FAULT_DETECT_FDCR_FDCIEN_MASK)
/*! @} */

/*! @name FDSR - LCD Fault Detect Status Register */
/*! @{ */

#define SGLCD_FAULT_DETECT_FDSR_FDCNT_MASK       (0xFFU)
#define SGLCD_FAULT_DETECT_FDSR_FDCNT_SHIFT      (0U)
/*! FDCNT - Fault Detect Counter */
#define SGLCD_FAULT_DETECT_FDSR_FDCNT(x)         (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDSR_FDCNT_SHIFT)) & SGLCD_FAULT_DETECT_FDSR_FDCNT_MASK)

#define SGLCD_FAULT_DETECT_FDSR_FDCF_MASK        (0x8000U)
#define SGLCD_FAULT_DETECT_FDSR_FDCF_SHIFT       (15U)
/*! FDCF - Fault Detection Complete Flag
 *  0b0..Fault detection is not completed.
 *  0b1..Fault detection is completed.
 */
#define SGLCD_FAULT_DETECT_FDSR_FDCF(x)          (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_FDSR_FDCF_SHIFT)) & SGLCD_FAULT_DETECT_FDSR_FDCF_MASK)
/*! @} */

/*! @name PEN_DUP - LCD Pin Enable register 0..LCD Pin Enable register 1 */
/*! @{ */

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_0_EN_MASK (0x1U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_0_EN_SHIFT (0U)
/*! PIN_0_EN - LCD Pin 0 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_0_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_0_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_0_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_32_EN_MASK (0x1U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_32_EN_SHIFT (0U)
/*! PIN_32_EN - LCD Pin 32 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_32_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_32_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_32_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_1_EN_MASK (0x2U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_1_EN_SHIFT (1U)
/*! PIN_1_EN - LCD Pin 1 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_1_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_1_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_1_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_33_EN_MASK (0x2U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_33_EN_SHIFT (1U)
/*! PIN_33_EN - LCD Pin 33 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_33_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_33_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_33_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_2_EN_MASK (0x4U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_2_EN_SHIFT (2U)
/*! PIN_2_EN - LCD Pin 2 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_2_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_2_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_2_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_34_EN_MASK (0x4U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_34_EN_SHIFT (2U)
/*! PIN_34_EN - LCD Pin 34 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_34_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_34_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_34_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_3_EN_MASK (0x8U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_3_EN_SHIFT (3U)
/*! PIN_3_EN - LCD Pin 3 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_3_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_3_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_3_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_35_EN_MASK (0x8U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_35_EN_SHIFT (3U)
/*! PIN_35_EN - LCD Pin 35 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_35_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_35_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_35_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_4_EN_MASK (0x10U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_4_EN_SHIFT (4U)
/*! PIN_4_EN - LCD Pin 4 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_4_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_4_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_4_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_36_EN_MASK (0x10U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_36_EN_SHIFT (4U)
/*! PIN_36_EN - LCD Pin 36 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_36_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_36_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_36_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_5_EN_MASK (0x20U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_5_EN_SHIFT (5U)
/*! PIN_5_EN - LCD Pin 5 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_5_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_5_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_5_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_37_EN_MASK (0x20U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_37_EN_SHIFT (5U)
/*! PIN_37_EN - LCD Pin 37 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_37_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_37_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_37_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_6_EN_MASK (0x40U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_6_EN_SHIFT (6U)
/*! PIN_6_EN - LCD Pin 6 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_6_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_6_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_6_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_38_EN_MASK (0x40U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_38_EN_SHIFT (6U)
/*! PIN_38_EN - LCD Pin 38 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_38_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_38_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_38_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_7_EN_MASK (0x80U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_7_EN_SHIFT (7U)
/*! PIN_7_EN - LCD Pin 7 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_7_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_7_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_7_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_39_EN_MASK (0x80U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_39_EN_SHIFT (7U)
/*! PIN_39_EN - LCD Pin 39 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_39_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_39_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_39_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_8_EN_MASK (0x100U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_8_EN_SHIFT (8U)
/*! PIN_8_EN - LCD Pin 8 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_8_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_8_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_8_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_40_EN_MASK (0x100U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_40_EN_SHIFT (8U)
/*! PIN_40_EN - LCD Pin 40 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_40_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_40_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_40_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_9_EN_MASK (0x200U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_9_EN_SHIFT (9U)
/*! PIN_9_EN - LCD Pin 9 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_9_EN(x)   (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_9_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_9_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_41_EN_MASK (0x200U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_41_EN_SHIFT (9U)
/*! PIN_41_EN - LCD Pin 41 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_41_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_41_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_41_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_10_EN_MASK (0x400U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_10_EN_SHIFT (10U)
/*! PIN_10_EN - LCD Pin 10 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_10_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_10_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_10_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_42_EN_MASK (0x400U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_42_EN_SHIFT (10U)
/*! PIN_42_EN - LCD Pin 42 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_42_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_42_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_42_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_11_EN_MASK (0x800U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_11_EN_SHIFT (11U)
/*! PIN_11_EN - LCD Pin 11 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_11_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_11_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_11_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_43_EN_MASK (0x800U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_43_EN_SHIFT (11U)
/*! PIN_43_EN - LCD Pin 43 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_43_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_43_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_43_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_12_EN_MASK (0x1000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_12_EN_SHIFT (12U)
/*! PIN_12_EN - LCD Pin 12 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_12_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_12_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_12_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_44_EN_MASK (0x1000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_44_EN_SHIFT (12U)
/*! PIN_44_EN - LCD Pin 44 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_44_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_44_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_44_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_13_EN_MASK (0x2000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_13_EN_SHIFT (13U)
/*! PIN_13_EN - LCD Pin 13 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_13_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_13_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_13_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_45_EN_MASK (0x2000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_45_EN_SHIFT (13U)
/*! PIN_45_EN - LCD Pin 45 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_45_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_45_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_45_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_14_EN_MASK (0x4000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_14_EN_SHIFT (14U)
/*! PIN_14_EN - LCD Pin 14 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_14_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_14_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_14_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_46_EN_MASK (0x4000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_46_EN_SHIFT (14U)
/*! PIN_46_EN - LCD Pin 46 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_46_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_46_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_46_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_15_EN_MASK (0x8000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_15_EN_SHIFT (15U)
/*! PIN_15_EN - LCD Pin 15 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_15_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_15_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_15_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_47_EN_MASK (0x8000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_47_EN_SHIFT (15U)
/*! PIN_47_EN - LCD Pin 47 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_47_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_47_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_47_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_16_EN_MASK (0x10000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_16_EN_SHIFT (16U)
/*! PIN_16_EN - LCD Pin 16 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_16_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_16_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_16_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_48_EN_MASK (0x10000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_48_EN_SHIFT (16U)
/*! PIN_48_EN - LCD Pin 48 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_48_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_48_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_48_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_17_EN_MASK (0x20000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_17_EN_SHIFT (17U)
/*! PIN_17_EN - LCD Pin 17 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_17_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_17_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_17_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_49_EN_MASK (0x20000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_49_EN_SHIFT (17U)
/*! PIN_49_EN - LCD Pin 49 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_49_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_49_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_49_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_18_EN_MASK (0x40000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_18_EN_SHIFT (18U)
/*! PIN_18_EN - LCD Pin 18 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_18_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_18_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_18_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_50_EN_MASK (0x40000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_50_EN_SHIFT (18U)
/*! PIN_50_EN - LCD Pin 50 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_50_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_50_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_50_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_19_EN_MASK (0x80000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_19_EN_SHIFT (19U)
/*! PIN_19_EN - LCD Pin 19 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_19_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_19_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_19_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_51_EN_MASK (0x80000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_51_EN_SHIFT (19U)
/*! PIN_51_EN - LCD Pin 51 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_51_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_51_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_51_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_20_EN_MASK (0x100000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_20_EN_SHIFT (20U)
/*! PIN_20_EN - LCD Pin 20 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_20_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_20_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_20_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_52_EN_MASK (0x100000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_52_EN_SHIFT (20U)
/*! PIN_52_EN - LCD Pin 52 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_52_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_52_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_52_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_21_EN_MASK (0x200000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_21_EN_SHIFT (21U)
/*! PIN_21_EN - LCD Pin 21 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_21_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_21_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_21_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_53_EN_MASK (0x200000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_53_EN_SHIFT (21U)
/*! PIN_53_EN - LCD Pin 53 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_53_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_53_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_53_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_22_EN_MASK (0x400000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_22_EN_SHIFT (22U)
/*! PIN_22_EN - LCD Pin 22 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_22_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_22_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_22_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_54_EN_MASK (0x400000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_54_EN_SHIFT (22U)
/*! PIN_54_EN - LCD Pin 54 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_54_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_54_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_54_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_23_EN_MASK (0x800000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_23_EN_SHIFT (23U)
/*! PIN_23_EN - LCD Pin 23 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_23_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_23_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_23_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_55_EN_MASK (0x800000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_55_EN_SHIFT (23U)
/*! PIN_55_EN - LCD Pin 55 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_55_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_55_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_55_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_24_EN_MASK (0x1000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_24_EN_SHIFT (24U)
/*! PIN_24_EN - LCD Pin 24 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_24_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_24_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_24_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_25_EN_MASK (0x2000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_25_EN_SHIFT (25U)
/*! PIN_25_EN - LCD Pin 25 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_25_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_25_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_25_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_26_EN_MASK (0x4000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_26_EN_SHIFT (26U)
/*! PIN_26_EN - LCD Pin 26 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_26_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_26_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_26_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_27_EN_MASK (0x8000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_27_EN_SHIFT (27U)
/*! PIN_27_EN - LCD Pin 27 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_27_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_27_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_27_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_28_EN_MASK (0x10000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_28_EN_SHIFT (28U)
/*! PIN_28_EN - LCD Pin 28 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_28_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_28_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_28_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_29_EN_MASK (0x20000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_29_EN_SHIFT (29U)
/*! PIN_29_EN - LCD Pin 29 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_29_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_29_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_29_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_30_EN_MASK (0x40000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_30_EN_SHIFT (30U)
/*! PIN_30_EN - LCD Pin 30 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_30_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_30_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_30_EN_MASK)

#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_31_EN_MASK (0x80000000U)
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_31_EN_SHIFT (31U)
/*! PIN_31_EN - LCD Pin 31 Enable
 *  0b0..Pin Disable
 *  0b1..Pin Enable
 */
#define SGLCD_FAULT_DETECT_PEN_DUP_PIN_31_EN(x)  (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_PEN_DUP_PIN_31_EN_SHIFT)) & SGLCD_FAULT_DETECT_PEN_DUP_PIN_31_EN_MASK)
/*! @} */

/*! @name BPEN_DUP - LCD Back Plane Enable register 0..LCD Back Plane Enable register 1 */
/*! @{ */

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_0_BPEN_MASK (0x1U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_0_BPEN_SHIFT (0U)
/*! PIN_0_BPEN - LCD Pin 0 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_0_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_0_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_0_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_32_BPEN_MASK (0x1U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_32_BPEN_SHIFT (0U)
/*! PIN_32_BPEN - LCD Pin 32 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_32_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_32_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_32_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_1_BPEN_MASK (0x2U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_1_BPEN_SHIFT (1U)
/*! PIN_1_BPEN - LCD Pin 1 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_1_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_1_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_1_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_33_BPEN_MASK (0x2U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_33_BPEN_SHIFT (1U)
/*! PIN_33_BPEN - LCD Pin 33 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_33_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_33_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_33_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_2_BPEN_MASK (0x4U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_2_BPEN_SHIFT (2U)
/*! PIN_2_BPEN - LCD Pin 2 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_2_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_2_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_2_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_34_BPEN_MASK (0x4U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_34_BPEN_SHIFT (2U)
/*! PIN_34_BPEN - LCD Pin 34 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_34_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_34_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_34_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_3_BPEN_MASK (0x8U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_3_BPEN_SHIFT (3U)
/*! PIN_3_BPEN - LCD Pin 3 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_3_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_3_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_3_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_35_BPEN_MASK (0x8U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_35_BPEN_SHIFT (3U)
/*! PIN_35_BPEN - LCD Pin 35 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_35_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_35_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_35_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_4_BPEN_MASK (0x10U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_4_BPEN_SHIFT (4U)
/*! PIN_4_BPEN - LCD Pin 4 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_4_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_4_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_4_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_36_BPEN_MASK (0x10U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_36_BPEN_SHIFT (4U)
/*! PIN_36_BPEN - LCD Pin 36 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_36_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_36_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_36_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_5_BPEN_MASK (0x20U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_5_BPEN_SHIFT (5U)
/*! PIN_5_BPEN - LCD Pin 5 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_5_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_5_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_5_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_37_BPEN_MASK (0x20U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_37_BPEN_SHIFT (5U)
/*! PIN_37_BPEN - LCD Pin 37 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_37_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_37_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_37_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_6_BPEN_MASK (0x40U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_6_BPEN_SHIFT (6U)
/*! PIN_6_BPEN - LCD Pin 6 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_6_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_6_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_6_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_38_BPEN_MASK (0x40U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_38_BPEN_SHIFT (6U)
/*! PIN_38_BPEN - LCD Pin 38 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_38_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_38_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_38_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_7_BPEN_MASK (0x80U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_7_BPEN_SHIFT (7U)
/*! PIN_7_BPEN - LCD Pin 7 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_7_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_7_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_7_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_39_BPEN_MASK (0x80U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_39_BPEN_SHIFT (7U)
/*! PIN_39_BPEN - LCD Pin 39 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_39_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_39_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_39_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_8_BPEN_MASK (0x100U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_8_BPEN_SHIFT (8U)
/*! PIN_8_BPEN - LCD Pin 8 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_8_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_8_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_8_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_40_BPEN_MASK (0x100U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_40_BPEN_SHIFT (8U)
/*! PIN_40_BPEN - LCD Pin 40 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_40_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_40_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_40_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_9_BPEN_MASK (0x200U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_9_BPEN_SHIFT (9U)
/*! PIN_9_BPEN - LCD Pin 9 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_9_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_9_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_9_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_41_BPEN_MASK (0x200U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_41_BPEN_SHIFT (9U)
/*! PIN_41_BPEN - LCD Pin 41 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_41_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_41_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_41_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_10_BPEN_MASK (0x400U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_10_BPEN_SHIFT (10U)
/*! PIN_10_BPEN - LCD Pin 10 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_10_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_10_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_10_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_42_BPEN_MASK (0x400U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_42_BPEN_SHIFT (10U)
/*! PIN_42_BPEN - LCD Pin 42 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_42_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_42_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_42_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_11_BPEN_MASK (0x800U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_11_BPEN_SHIFT (11U)
/*! PIN_11_BPEN - LCD Pin 11 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_11_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_11_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_11_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_43_BPEN_MASK (0x800U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_43_BPEN_SHIFT (11U)
/*! PIN_43_BPEN - LCD Pin 43 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_43_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_43_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_43_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_12_BPEN_MASK (0x1000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_12_BPEN_SHIFT (12U)
/*! PIN_12_BPEN - LCD Pin 12 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_12_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_12_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_12_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_44_BPEN_MASK (0x1000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_44_BPEN_SHIFT (12U)
/*! PIN_44_BPEN - LCD Pin 44 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_44_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_44_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_44_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_13_BPEN_MASK (0x2000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_13_BPEN_SHIFT (13U)
/*! PIN_13_BPEN - LCD Pin 13 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_13_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_13_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_13_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_45_BPEN_MASK (0x2000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_45_BPEN_SHIFT (13U)
/*! PIN_45_BPEN - LCD Pin 45 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_45_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_45_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_45_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_14_BPEN_MASK (0x4000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_14_BPEN_SHIFT (14U)
/*! PIN_14_BPEN - LCD Pin 14 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_14_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_14_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_14_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_46_BPEN_MASK (0x4000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_46_BPEN_SHIFT (14U)
/*! PIN_46_BPEN - LCD Pin 46 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_46_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_46_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_46_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_15_BPEN_MASK (0x8000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_15_BPEN_SHIFT (15U)
/*! PIN_15_BPEN - LCD Pin 15 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_15_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_15_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_15_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_47_BPEN_MASK (0x8000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_47_BPEN_SHIFT (15U)
/*! PIN_47_BPEN - LCD Pin 47 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_47_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_47_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_47_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_16_BPEN_MASK (0x10000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_16_BPEN_SHIFT (16U)
/*! PIN_16_BPEN - LCD Pin 16 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_16_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_16_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_16_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_48_BPEN_MASK (0x10000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_48_BPEN_SHIFT (16U)
/*! PIN_48_BPEN - LCD Pin 48 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_48_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_48_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_48_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_17_BPEN_MASK (0x20000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_17_BPEN_SHIFT (17U)
/*! PIN_17_BPEN - LCD Pin 17 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_17_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_17_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_17_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_49_BPEN_MASK (0x20000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_49_BPEN_SHIFT (17U)
/*! PIN_49_BPEN - LCD Pin 49 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_49_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_49_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_49_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_18_BPEN_MASK (0x40000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_18_BPEN_SHIFT (18U)
/*! PIN_18_BPEN - LCD Pin 18 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_18_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_18_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_18_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_50_BPEN_MASK (0x40000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_50_BPEN_SHIFT (18U)
/*! PIN_50_BPEN - LCD Pin 50 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_50_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_50_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_50_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_19_BPEN_MASK (0x80000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_19_BPEN_SHIFT (19U)
/*! PIN_19_BPEN - LCD Pin 19 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_19_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_19_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_19_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_51_BPEN_MASK (0x80000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_51_BPEN_SHIFT (19U)
/*! PIN_51_BPEN - LCD Pin 51 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_51_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_51_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_51_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_20_BPEN_MASK (0x100000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_20_BPEN_SHIFT (20U)
/*! PIN_20_BPEN - LCD Pin 20 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_20_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_20_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_20_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_52_BPEN_MASK (0x100000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_52_BPEN_SHIFT (20U)
/*! PIN_52_BPEN - LCD Pin 52 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_52_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_52_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_52_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_21_BPEN_MASK (0x200000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_21_BPEN_SHIFT (21U)
/*! PIN_21_BPEN - LCD Pin 21 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_21_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_21_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_21_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_53_BPEN_MASK (0x200000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_53_BPEN_SHIFT (21U)
/*! PIN_53_BPEN - LCD Pin 53 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_53_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_53_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_53_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_22_BPEN_MASK (0x400000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_22_BPEN_SHIFT (22U)
/*! PIN_22_BPEN - LCD Pin 22 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_22_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_22_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_22_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_54_BPEN_MASK (0x400000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_54_BPEN_SHIFT (22U)
/*! PIN_54_BPEN - LCD Pin 54 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_54_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_54_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_54_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_23_BPEN_MASK (0x800000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_23_BPEN_SHIFT (23U)
/*! PIN_23_BPEN - LCD Pin 23 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_23_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_23_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_23_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_55_BPEN_MASK (0x800000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_55_BPEN_SHIFT (23U)
/*! PIN_55_BPEN - LCD Pin 55 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_55_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_55_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_55_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_24_BPEN_MASK (0x1000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_24_BPEN_SHIFT (24U)
/*! PIN_24_BPEN - LCD Pin 24 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_24_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_24_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_24_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_25_BPEN_MASK (0x2000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_25_BPEN_SHIFT (25U)
/*! PIN_25_BPEN - LCD Pin 25 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_25_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_25_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_25_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_26_BPEN_MASK (0x4000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_26_BPEN_SHIFT (26U)
/*! PIN_26_BPEN - LCD Pin 26 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_26_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_26_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_26_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_27_BPEN_MASK (0x8000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_27_BPEN_SHIFT (27U)
/*! PIN_27_BPEN - LCD Pin 27 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_27_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_27_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_27_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_28_BPEN_MASK (0x10000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_28_BPEN_SHIFT (28U)
/*! PIN_28_BPEN - LCD Pin 28 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_28_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_28_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_28_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_29_BPEN_MASK (0x20000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_29_BPEN_SHIFT (29U)
/*! PIN_29_BPEN - LCD Pin 29 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_29_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_29_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_29_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_30_BPEN_MASK (0x40000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_30_BPEN_SHIFT (30U)
/*! PIN_30_BPEN - LCD Pin 30 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_30_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_30_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_30_BPEN_MASK)

#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_31_BPEN_MASK (0x80000000U)
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_31_BPEN_SHIFT (31U)
/*! PIN_31_BPEN - LCD Pin 31 Back Plane Enable
 *  0b0..Pin as Front Plane
 *  0b1..Pin as Back Plane
 */
#define SGLCD_FAULT_DETECT_BPEN_DUP_PIN_31_BPEN(x) (((uint32_t)(((uint32_t)(x)) << SGLCD_FAULT_DETECT_BPEN_DUP_PIN_31_BPEN_SHIFT)) & SGLCD_FAULT_DETECT_BPEN_DUP_PIN_31_BPEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group SGLCD_FAULT_DETECT_Register_Masks */


/*!
 * @}
 */ /* end of group SGLCD_FAULT_DETECT_Peripheral_Access_Layer */


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


#endif  /* PERI_SGLCD_FAULT_DETECT_H_ */

