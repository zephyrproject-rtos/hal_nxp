/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LLWU
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LLWU.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LLWU
 *
 * CMSIS Peripheral Access Layer for LLWU
 */

#if !defined(PERI_LLWU_H_)
#define PERI_LLWU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
   -- LLWU Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Peripheral_Access_Layer LLWU Peripheral Access Layer
 * @{
 */

/** LLWU - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
  __IO uint32_t PE1;                               /**< Pin Enable 1 register, offset: 0x8 */
  __IO uint32_t PE2;                               /**< Pin Enable 2 register, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< Module Interrupt Enable register, offset: 0x18 */
  __IO uint32_t DE;                                /**< Module DMA/Trigger Enable register, offset: 0x1C */
  __IO uint32_t PF;                                /**< Pin Flag register, offset: 0x20 */
       uint8_t RESERVED_1[12];
  __IO uint32_t FILT;                              /**< Pin Filter register, offset: 0x30 */
       uint8_t RESERVED_2[4];
  __IO uint32_t PDC1;                              /**< Pin DMA/Trigger Configuration 1 register, offset: 0x38 */
  __IO uint32_t PDC2;                              /**< Pin DMA/Trigger Configuration 2 register, offset: 0x3C */
       uint8_t RESERVED_3[8];
  __IO uint32_t FDC;                               /**< Pin Filter DMA/Trigger Configuration register, offset: 0x48 */
       uint8_t RESERVED_4[4];
  __IO uint32_t PMC;                               /**< Pin Mode Configuration register, offset: 0x50 */
       uint8_t RESERVED_5[4];
  __IO uint32_t FMCr;                              /**< Pin Filter Mode Configuration register, offset: 0x58, 'r' suffix has been added to avoid a clash with peripheral base pointer macro 'FMC' */
} LLWU_Type;

/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

/*! @name VERID - Version ID Register */
/*! @{ */

#define LLWU_VERID_FEATURE_MASK                  (0xFFFFU)
#define LLWU_VERID_FEATURE_SHIFT                 (0U)
/*! FEATURE - Feature Specification Number
 *  0b0000000000000000..Standard features implemented
 *  0b0000000000000001..Support for DMA/Trigger generation from wakeup pins and filters enabled. Support for
 *                      external pin/filter detection during all power modes enabled.
 */
#define LLWU_VERID_FEATURE(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_VERID_FEATURE_SHIFT)) & LLWU_VERID_FEATURE_MASK)

#define LLWU_VERID_MINOR_MASK                    (0xFF0000U)
#define LLWU_VERID_MINOR_SHIFT                   (16U)
/*! MINOR - Minor Version Number */
#define LLWU_VERID_MINOR(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_VERID_MINOR_SHIFT)) & LLWU_VERID_MINOR_MASK)

#define LLWU_VERID_MAJOR_MASK                    (0xFF000000U)
#define LLWU_VERID_MAJOR_SHIFT                   (24U)
/*! MAJOR - Major Version Number */
#define LLWU_VERID_MAJOR(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_VERID_MAJOR_SHIFT)) & LLWU_VERID_MAJOR_MASK)
/*! @} */

/*! @name PARAM - Parameter Register */
/*! @{ */

#define LLWU_PARAM_FILTERS_MASK                  (0xFFU)
#define LLWU_PARAM_FILTERS_SHIFT                 (0U)
/*! FILTERS - Filter Number */
#define LLWU_PARAM_FILTERS(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PARAM_FILTERS_SHIFT)) & LLWU_PARAM_FILTERS_MASK)

#define LLWU_PARAM_DMAS_MASK                     (0xFF00U)
#define LLWU_PARAM_DMAS_SHIFT                    (8U)
/*! DMAS - DMA Number */
#define LLWU_PARAM_DMAS(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PARAM_DMAS_SHIFT)) & LLWU_PARAM_DMAS_MASK)

#define LLWU_PARAM_MODULES_MASK                  (0xFF0000U)
#define LLWU_PARAM_MODULES_SHIFT                 (16U)
/*! MODULES - Module Number */
#define LLWU_PARAM_MODULES(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PARAM_MODULES_SHIFT)) & LLWU_PARAM_MODULES_MASK)

#define LLWU_PARAM_PINS_MASK                     (0xFF000000U)
#define LLWU_PARAM_PINS_SHIFT                    (24U)
/*! PINS - Pin Number */
#define LLWU_PARAM_PINS(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PARAM_PINS_SHIFT)) & LLWU_PARAM_PINS_MASK)
/*! @} */

/*! @name PE1 - Pin Enable 1 register */
/*! @{ */

#define LLWU_PE1_WUPE0_MASK                      (0x3U)
#define LLWU_PE1_WUPE0_SHIFT                     (0U)
/*! WUPE0 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE0(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE0_SHIFT)) & LLWU_PE1_WUPE0_MASK)

#define LLWU_PE1_WUPE1_MASK                      (0xCU)
#define LLWU_PE1_WUPE1_SHIFT                     (2U)
/*! WUPE1 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE1(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE1_SHIFT)) & LLWU_PE1_WUPE1_MASK)

#define LLWU_PE1_WUPE2_MASK                      (0x30U)
#define LLWU_PE1_WUPE2_SHIFT                     (4U)
/*! WUPE2 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE2(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE2_SHIFT)) & LLWU_PE1_WUPE2_MASK)

#define LLWU_PE1_WUPE3_MASK                      (0xC0U)
#define LLWU_PE1_WUPE3_SHIFT                     (6U)
/*! WUPE3 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE3(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE3_SHIFT)) & LLWU_PE1_WUPE3_MASK)

#define LLWU_PE1_WUPE4_MASK                      (0x300U)
#define LLWU_PE1_WUPE4_SHIFT                     (8U)
/*! WUPE4 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE4(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE4_SHIFT)) & LLWU_PE1_WUPE4_MASK)

#define LLWU_PE1_WUPE5_MASK                      (0xC00U)
#define LLWU_PE1_WUPE5_SHIFT                     (10U)
/*! WUPE5 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE5(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE5_SHIFT)) & LLWU_PE1_WUPE5_MASK)

#define LLWU_PE1_WUPE6_MASK                      (0x3000U)
#define LLWU_PE1_WUPE6_SHIFT                     (12U)
/*! WUPE6 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE6(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE6_SHIFT)) & LLWU_PE1_WUPE6_MASK)

#define LLWU_PE1_WUPE7_MASK                      (0xC000U)
#define LLWU_PE1_WUPE7_SHIFT                     (14U)
/*! WUPE7 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE7(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE7_SHIFT)) & LLWU_PE1_WUPE7_MASK)

#define LLWU_PE1_WUPE8_MASK                      (0x30000U)
#define LLWU_PE1_WUPE8_SHIFT                     (16U)
/*! WUPE8 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE8(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE8_SHIFT)) & LLWU_PE1_WUPE8_MASK)

#define LLWU_PE1_WUPE9_MASK                      (0xC0000U)
#define LLWU_PE1_WUPE9_SHIFT                     (18U)
/*! WUPE9 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE9(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE9_SHIFT)) & LLWU_PE1_WUPE9_MASK)

#define LLWU_PE1_WUPE10_MASK                     (0x300000U)
#define LLWU_PE1_WUPE10_SHIFT                    (20U)
/*! WUPE10 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE10(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE10_SHIFT)) & LLWU_PE1_WUPE10_MASK)

#define LLWU_PE1_WUPE11_MASK                     (0xC00000U)
#define LLWU_PE1_WUPE11_SHIFT                    (22U)
/*! WUPE11 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE11(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE11_SHIFT)) & LLWU_PE1_WUPE11_MASK)

#define LLWU_PE1_WUPE12_MASK                     (0x3000000U)
#define LLWU_PE1_WUPE12_SHIFT                    (24U)
/*! WUPE12 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE12(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE12_SHIFT)) & LLWU_PE1_WUPE12_MASK)

#define LLWU_PE1_WUPE13_MASK                     (0xC000000U)
#define LLWU_PE1_WUPE13_SHIFT                    (26U)
/*! WUPE13 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE13(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE13_SHIFT)) & LLWU_PE1_WUPE13_MASK)

#define LLWU_PE1_WUPE14_MASK                     (0x30000000U)
#define LLWU_PE1_WUPE14_SHIFT                    (28U)
/*! WUPE14 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE14(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE14_SHIFT)) & LLWU_PE1_WUPE14_MASK)

#define LLWU_PE1_WUPE15_MASK                     (0xC0000000U)
#define LLWU_PE1_WUPE15_SHIFT                    (30U)
/*! WUPE15 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE1_WUPE15(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE15_SHIFT)) & LLWU_PE1_WUPE15_MASK)
/*! @} */

/*! @name PE2 - Pin Enable 2 register */
/*! @{ */

#define LLWU_PE2_WUPE16_MASK                     (0x3U)
#define LLWU_PE2_WUPE16_SHIFT                    (0U)
/*! WUPE16 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE16(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE16_SHIFT)) & LLWU_PE2_WUPE16_MASK)

#define LLWU_PE2_WUPE17_MASK                     (0xCU)
#define LLWU_PE2_WUPE17_SHIFT                    (2U)
/*! WUPE17 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE17(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE17_SHIFT)) & LLWU_PE2_WUPE17_MASK)

#define LLWU_PE2_WUPE18_MASK                     (0x30U)
#define LLWU_PE2_WUPE18_SHIFT                    (4U)
/*! WUPE18 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE18(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE18_SHIFT)) & LLWU_PE2_WUPE18_MASK)

#define LLWU_PE2_WUPE19_MASK                     (0xC0U)
#define LLWU_PE2_WUPE19_SHIFT                    (6U)
/*! WUPE19 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE19(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE19_SHIFT)) & LLWU_PE2_WUPE19_MASK)

#define LLWU_PE2_WUPE20_MASK                     (0x300U)
#define LLWU_PE2_WUPE20_SHIFT                    (8U)
/*! WUPE20 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE20(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE20_SHIFT)) & LLWU_PE2_WUPE20_MASK)

#define LLWU_PE2_WUPE21_MASK                     (0xC00U)
#define LLWU_PE2_WUPE21_SHIFT                    (10U)
/*! WUPE21 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE21(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE21_SHIFT)) & LLWU_PE2_WUPE21_MASK)

#define LLWU_PE2_WUPE22_MASK                     (0x3000U)
#define LLWU_PE2_WUPE22_SHIFT                    (12U)
/*! WUPE22 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE22(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE22_SHIFT)) & LLWU_PE2_WUPE22_MASK)

#define LLWU_PE2_WUPE23_MASK                     (0xC000U)
#define LLWU_PE2_WUPE23_SHIFT                    (14U)
/*! WUPE23 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE23(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE23_SHIFT)) & LLWU_PE2_WUPE23_MASK)

#define LLWU_PE2_WUPE24_MASK                     (0x30000U)
#define LLWU_PE2_WUPE24_SHIFT                    (16U)
/*! WUPE24 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE24(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE24_SHIFT)) & LLWU_PE2_WUPE24_MASK)

#define LLWU_PE2_WUPE25_MASK                     (0xC0000U)
#define LLWU_PE2_WUPE25_SHIFT                    (18U)
/*! WUPE25 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE25(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE25_SHIFT)) & LLWU_PE2_WUPE25_MASK)

#define LLWU_PE2_WUPE26_MASK                     (0x300000U)
#define LLWU_PE2_WUPE26_SHIFT                    (20U)
/*! WUPE26 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE26(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE26_SHIFT)) & LLWU_PE2_WUPE26_MASK)

#define LLWU_PE2_Reserved27_MASK                 (0xC00000U)
#define LLWU_PE2_Reserved27_SHIFT                (22U)
/*! Reserved27 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_Reserved27(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved27_SHIFT)) & LLWU_PE2_Reserved27_MASK)

#define LLWU_PE2_Reserved28_MASK                 (0x3000000U)
#define LLWU_PE2_Reserved28_SHIFT                (24U)
/*! Reserved28 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_Reserved28(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved28_SHIFT)) & LLWU_PE2_Reserved28_MASK)

#define LLWU_PE2_WUPE29_MASK                     (0xC000000U)
#define LLWU_PE2_WUPE29_SHIFT                    (26U)
/*! WUPE29 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE29(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE29_SHIFT)) & LLWU_PE2_WUPE29_MASK)

#define LLWU_PE2_WUPE30_MASK                     (0x30000000U)
#define LLWU_PE2_WUPE30_SHIFT                    (28U)
/*! WUPE30 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE30(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE30_SHIFT)) & LLWU_PE2_WUPE30_MASK)

#define LLWU_PE2_WUPE31_MASK                     (0xC0000000U)
#define LLWU_PE2_WUPE31_SHIFT                    (30U)
/*! WUPE31 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection when configured as interrupt/DMA request or high
 *        level detection when configured as trigger request
 *  0b10..External input pin enabled with falling edge detection when configured as interrupt/DMA request or low
 *        level detection when configured as trigger request
 *  0b11..External input pin enabled with any change detection when configured as interrupt/DMA request
 */
#define LLWU_PE2_WUPE31(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE31_SHIFT)) & LLWU_PE2_WUPE31_MASK)
/*! @} */

/*! @name ME - Module Interrupt Enable register */
/*! @{ */

#define LLWU_ME_WUME0_MASK                       (0x1U)
#define LLWU_ME_WUME0_SHIFT                      (0U)
/*! WUME0 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME0_SHIFT)) & LLWU_ME_WUME0_MASK)

#define LLWU_ME_WUME1_MASK                       (0x2U)
#define LLWU_ME_WUME1_SHIFT                      (1U)
/*! WUME1 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME1_SHIFT)) & LLWU_ME_WUME1_MASK)

#define LLWU_ME_WUME2_MASK                       (0x4U)
#define LLWU_ME_WUME2_SHIFT                      (2U)
/*! WUME2 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME2_SHIFT)) & LLWU_ME_WUME2_MASK)

#define LLWU_ME_Reserved3_MASK                   (0x8U)
#define LLWU_ME_Reserved3_SHIFT                  (3U)
/*! Reserved3 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_Reserved3(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_ME_Reserved3_SHIFT)) & LLWU_ME_Reserved3_MASK)

#define LLWU_ME_WUME3_MASK                       (0x8U)
#define LLWU_ME_WUME3_SHIFT                      (3U)
/*! WUME3 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME3_SHIFT)) & LLWU_ME_WUME3_MASK)

#define LLWU_ME_Reserved4_MASK                   (0x10U)
#define LLWU_ME_Reserved4_SHIFT                  (4U)
/*! Reserved4 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_Reserved4(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_ME_Reserved4_SHIFT)) & LLWU_ME_Reserved4_MASK)

#define LLWU_ME_WUME5_MASK                       (0x20U)
#define LLWU_ME_WUME5_SHIFT                      (5U)
/*! WUME5 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME5(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME5_SHIFT)) & LLWU_ME_WUME5_MASK)

#define LLWU_ME_WUME6_MASK                       (0x40U)
#define LLWU_ME_WUME6_SHIFT                      (6U)
/*! WUME6 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME6_SHIFT)) & LLWU_ME_WUME6_MASK)

#define LLWU_ME_WUME7_MASK                       (0x80U)
#define LLWU_ME_WUME7_SHIFT                      (7U)
/*! WUME7 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME7(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME7_SHIFT)) & LLWU_ME_WUME7_MASK)
/*! @} */

/*! @name DE - Module DMA/Trigger Enable register */
/*! @{ */

#define LLWU_DE_WUDE0_MASK                       (0x1U)
#define LLWU_DE_WUDE0_SHIFT                      (0U)
/*! WUDE0 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE0_SHIFT)) & LLWU_DE_WUDE0_MASK)

#define LLWU_DE_WUDE1_MASK                       (0x2U)
#define LLWU_DE_WUDE1_SHIFT                      (1U)
/*! WUDE1 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE1_SHIFT)) & LLWU_DE_WUDE1_MASK)

#define LLWU_DE_WUDE2_MASK                       (0x4U)
#define LLWU_DE_WUDE2_SHIFT                      (2U)
/*! WUDE2 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE2_SHIFT)) & LLWU_DE_WUDE2_MASK)

#define LLWU_DE_Reserved3_MASK                   (0x8U)
#define LLWU_DE_Reserved3_SHIFT                  (3U)
/*! Reserved3 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved3(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved3_SHIFT)) & LLWU_DE_Reserved3_MASK)

#define LLWU_DE_WUDE4_MASK                       (0x10U)
#define LLWU_DE_WUDE4_SHIFT                      (4U)
/*! WUDE4 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE4_SHIFT)) & LLWU_DE_WUDE4_MASK)

#define LLWU_DE_WUDE5_MASK                       (0x20U)
#define LLWU_DE_WUDE5_SHIFT                      (5U)
/*! WUDE5 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE5(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE5_SHIFT)) & LLWU_DE_WUDE5_MASK)

#define LLWU_DE_WUDE6_MASK                       (0x40U)
#define LLWU_DE_WUDE6_SHIFT                      (6U)
/*! WUDE6 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_WUDE6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE6_SHIFT)) & LLWU_DE_WUDE6_MASK)

#define LLWU_DE_Reserved7_MASK                   (0x80U)
#define LLWU_DE_Reserved7_SHIFT                  (7U)
/*! Reserved7 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved7(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved7_SHIFT)) & LLWU_DE_Reserved7_MASK)
/*! @} */

/*! @name PF - Pin Flag register */
/*! @{ */

#define LLWU_PF_WUF0_MASK                        (0x1U)
#define LLWU_PF_WUF0_SHIFT                       (0U)
/*! WUF0 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF0(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF0_SHIFT)) & LLWU_PF_WUF0_MASK)

#define LLWU_PF_WUF1_MASK                        (0x2U)
#define LLWU_PF_WUF1_SHIFT                       (1U)
/*! WUF1 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF1(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF1_SHIFT)) & LLWU_PF_WUF1_MASK)

#define LLWU_PF_WUF2_MASK                        (0x4U)
#define LLWU_PF_WUF2_SHIFT                       (2U)
/*! WUF2 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF2(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF2_SHIFT)) & LLWU_PF_WUF2_MASK)

#define LLWU_PF_WUF3_MASK                        (0x8U)
#define LLWU_PF_WUF3_SHIFT                       (3U)
/*! WUF3 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF3(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF3_SHIFT)) & LLWU_PF_WUF3_MASK)

#define LLWU_PF_WUF4_MASK                        (0x10U)
#define LLWU_PF_WUF4_SHIFT                       (4U)
/*! WUF4 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF4(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF4_SHIFT)) & LLWU_PF_WUF4_MASK)

#define LLWU_PF_WUF5_MASK                        (0x20U)
#define LLWU_PF_WUF5_SHIFT                       (5U)
/*! WUF5 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF5(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF5_SHIFT)) & LLWU_PF_WUF5_MASK)

#define LLWU_PF_WUF6_MASK                        (0x40U)
#define LLWU_PF_WUF6_SHIFT                       (6U)
/*! WUF6 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF6(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF6_SHIFT)) & LLWU_PF_WUF6_MASK)

#define LLWU_PF_WUF7_MASK                        (0x80U)
#define LLWU_PF_WUF7_SHIFT                       (7U)
/*! WUF7 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF7(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF7_SHIFT)) & LLWU_PF_WUF7_MASK)

#define LLWU_PF_WUF8_MASK                        (0x100U)
#define LLWU_PF_WUF8_SHIFT                       (8U)
/*! WUF8 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF8(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF8_SHIFT)) & LLWU_PF_WUF8_MASK)

#define LLWU_PF_WUF9_MASK                        (0x200U)
#define LLWU_PF_WUF9_SHIFT                       (9U)
/*! WUF9 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF9(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF9_SHIFT)) & LLWU_PF_WUF9_MASK)

#define LLWU_PF_WUF10_MASK                       (0x400U)
#define LLWU_PF_WUF10_SHIFT                      (10U)
/*! WUF10 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF10(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF10_SHIFT)) & LLWU_PF_WUF10_MASK)

#define LLWU_PF_WUF11_MASK                       (0x800U)
#define LLWU_PF_WUF11_SHIFT                      (11U)
/*! WUF11 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF11(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF11_SHIFT)) & LLWU_PF_WUF11_MASK)

#define LLWU_PF_WUF12_MASK                       (0x1000U)
#define LLWU_PF_WUF12_SHIFT                      (12U)
/*! WUF12 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF12(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF12_SHIFT)) & LLWU_PF_WUF12_MASK)

#define LLWU_PF_WUF13_MASK                       (0x2000U)
#define LLWU_PF_WUF13_SHIFT                      (13U)
/*! WUF13 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF13(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF13_SHIFT)) & LLWU_PF_WUF13_MASK)

#define LLWU_PF_WUF14_MASK                       (0x4000U)
#define LLWU_PF_WUF14_SHIFT                      (14U)
/*! WUF14 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF14(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF14_SHIFT)) & LLWU_PF_WUF14_MASK)

#define LLWU_PF_WUF15_MASK                       (0x8000U)
#define LLWU_PF_WUF15_SHIFT                      (15U)
/*! WUF15 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF15(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF15_SHIFT)) & LLWU_PF_WUF15_MASK)

#define LLWU_PF_WUF16_MASK                       (0x10000U)
#define LLWU_PF_WUF16_SHIFT                      (16U)
/*! WUF16 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF16(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF16_SHIFT)) & LLWU_PF_WUF16_MASK)

#define LLWU_PF_WUF17_MASK                       (0x20000U)
#define LLWU_PF_WUF17_SHIFT                      (17U)
/*! WUF17 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF17(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF17_SHIFT)) & LLWU_PF_WUF17_MASK)

#define LLWU_PF_WUF18_MASK                       (0x40000U)
#define LLWU_PF_WUF18_SHIFT                      (18U)
/*! WUF18 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF18(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF18_SHIFT)) & LLWU_PF_WUF18_MASK)

#define LLWU_PF_WUF19_MASK                       (0x80000U)
#define LLWU_PF_WUF19_SHIFT                      (19U)
/*! WUF19 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF19(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF19_SHIFT)) & LLWU_PF_WUF19_MASK)

#define LLWU_PF_WUF20_MASK                       (0x100000U)
#define LLWU_PF_WUF20_SHIFT                      (20U)
/*! WUF20 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF20(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF20_SHIFT)) & LLWU_PF_WUF20_MASK)

#define LLWU_PF_WUF21_MASK                       (0x200000U)
#define LLWU_PF_WUF21_SHIFT                      (21U)
/*! WUF21 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF21(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF21_SHIFT)) & LLWU_PF_WUF21_MASK)

#define LLWU_PF_WUF22_MASK                       (0x400000U)
#define LLWU_PF_WUF22_SHIFT                      (22U)
/*! WUF22 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF22(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF22_SHIFT)) & LLWU_PF_WUF22_MASK)

#define LLWU_PF_WUF23_MASK                       (0x800000U)
#define LLWU_PF_WUF23_SHIFT                      (23U)
/*! WUF23 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF23(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF23_SHIFT)) & LLWU_PF_WUF23_MASK)

#define LLWU_PF_WUF24_MASK                       (0x1000000U)
#define LLWU_PF_WUF24_SHIFT                      (24U)
/*! WUF24 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF24(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF24_SHIFT)) & LLWU_PF_WUF24_MASK)

#define LLWU_PF_WUF25_MASK                       (0x2000000U)
#define LLWU_PF_WUF25_SHIFT                      (25U)
/*! WUF25 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF25(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF25_SHIFT)) & LLWU_PF_WUF25_MASK)

#define LLWU_PF_WUF26_MASK                       (0x4000000U)
#define LLWU_PF_WUF26_SHIFT                      (26U)
/*! WUF26 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF26(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF26_SHIFT)) & LLWU_PF_WUF26_MASK)

#define LLWU_PF_Reserved27_MASK                  (0x8000000U)
#define LLWU_PF_Reserved27_SHIFT                 (27U)
/*! Reserved27 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved27(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved27_SHIFT)) & LLWU_PF_Reserved27_MASK)

#define LLWU_PF_Reserved28_MASK                  (0x10000000U)
#define LLWU_PF_Reserved28_SHIFT                 (28U)
/*! Reserved28 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved28(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved28_SHIFT)) & LLWU_PF_Reserved28_MASK)

#define LLWU_PF_WUF29_MASK                       (0x20000000U)
#define LLWU_PF_WUF29_SHIFT                      (29U)
/*! WUF29 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF29(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF29_SHIFT)) & LLWU_PF_WUF29_MASK)

#define LLWU_PF_WUF30_MASK                       (0x40000000U)
#define LLWU_PF_WUF30_SHIFT                      (30U)
/*! WUF30 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF30(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF30_SHIFT)) & LLWU_PF_WUF30_MASK)

#define LLWU_PF_WUF31_MASK                       (0x80000000U)
#define LLWU_PF_WUF31_SHIFT                      (31U)
/*! WUF31 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_WUF31(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF31_SHIFT)) & LLWU_PF_WUF31_MASK)
/*! @} */

/*! @name FILT - Pin Filter register */
/*! @{ */

#define LLWU_FILT_FILTSEL1_MASK                  (0x1FU)
#define LLWU_FILT_FILTSEL1_SHIFT                 (0U)
/*! FILTSEL1 - Filter 1 Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT_FILTSEL1(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTSEL1_SHIFT)) & LLWU_FILT_FILTSEL1_MASK)

#define LLWU_FILT_FILTE1_MASK                    (0x60U)
#define LLWU_FILT_FILTE1_SHIFT                   (5U)
/*! FILTE1 - Filter 1 Enable
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled when configured as interrupt/DMA request or high level detection when configured as trigger request
 *  0b10..Filter negedge detect enabled when configured as interrupt/DMA request or low level detection when configured as trigger request
 *  0b11..Filter any edge detect enabled when configured as interrupt/DMA request
 */
#define LLWU_FILT_FILTE1(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTE1_SHIFT)) & LLWU_FILT_FILTE1_MASK)

#define LLWU_FILT_FILTF1_MASK                    (0x80U)
#define LLWU_FILT_FILTF1_SHIFT                   (7U)
/*! FILTF1 - Filter 1 Flag
 *  0b0..Pin Filter 1 was not a wakeup source
 *  0b1..Pin Filter 1 was a wakeup source
 */
#define LLWU_FILT_FILTF1(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTF1_SHIFT)) & LLWU_FILT_FILTF1_MASK)

#define LLWU_FILT_FILTSEL2_MASK                  (0x1F00U)
#define LLWU_FILT_FILTSEL2_SHIFT                 (8U)
/*! FILTSEL2 - Filter 2 Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT_FILTSEL2(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTSEL2_SHIFT)) & LLWU_FILT_FILTSEL2_MASK)

#define LLWU_FILT_FILTE2_MASK                    (0x6000U)
#define LLWU_FILT_FILTE2_SHIFT                   (13U)
/*! FILTE2 - Filter 2 Enable
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled when configured as interrupt/DMA request or high level detection when configured as trigger request
 *  0b10..Filter negedge detect enabled when configured as interrupt/DMA request or low level detection when configured as trigger request
 *  0b11..Filter any edge detect enabled when configured as interrupt/DMA request
 */
#define LLWU_FILT_FILTE2(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTE2_SHIFT)) & LLWU_FILT_FILTE2_MASK)

#define LLWU_FILT_FILTF2_MASK                    (0x8000U)
#define LLWU_FILT_FILTF2_SHIFT                   (15U)
/*! FILTF2 - Filter 2 Flag
 *  0b0..Pin Filter 2 was not a wakeup source
 *  0b1..Pin Filter 2 was a wakeup source
 */
#define LLWU_FILT_FILTF2(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTF2_SHIFT)) & LLWU_FILT_FILTF2_MASK)
/*! @} */

/*! @name PDC1 - Pin DMA/Trigger Configuration 1 register */
/*! @{ */

#define LLWU_PDC1_WUPDC0_MASK                    (0x3U)
#define LLWU_PDC1_WUPDC0_SHIFT                   (0U)
/*! WUPDC0 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC0(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC0_SHIFT)) & LLWU_PDC1_WUPDC0_MASK)

#define LLWU_PDC1_WUPDC1_MASK                    (0xCU)
#define LLWU_PDC1_WUPDC1_SHIFT                   (2U)
/*! WUPDC1 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC1(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC1_SHIFT)) & LLWU_PDC1_WUPDC1_MASK)

#define LLWU_PDC1_WUPDC2_MASK                    (0x30U)
#define LLWU_PDC1_WUPDC2_SHIFT                   (4U)
/*! WUPDC2 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC2(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC2_SHIFT)) & LLWU_PDC1_WUPDC2_MASK)

#define LLWU_PDC1_WUPDC3_MASK                    (0xC0U)
#define LLWU_PDC1_WUPDC3_SHIFT                   (6U)
/*! WUPDC3 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC3(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC3_SHIFT)) & LLWU_PDC1_WUPDC3_MASK)

#define LLWU_PDC1_WUPDC4_MASK                    (0x300U)
#define LLWU_PDC1_WUPDC4_SHIFT                   (8U)
/*! WUPDC4 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC4(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC4_SHIFT)) & LLWU_PDC1_WUPDC4_MASK)

#define LLWU_PDC1_WUPDC5_MASK                    (0xC00U)
#define LLWU_PDC1_WUPDC5_SHIFT                   (10U)
/*! WUPDC5 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC5(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC5_SHIFT)) & LLWU_PDC1_WUPDC5_MASK)

#define LLWU_PDC1_WUPDC6_MASK                    (0x3000U)
#define LLWU_PDC1_WUPDC6_SHIFT                   (12U)
/*! WUPDC6 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC6(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC6_SHIFT)) & LLWU_PDC1_WUPDC6_MASK)

#define LLWU_PDC1_WUPDC7_MASK                    (0xC000U)
#define LLWU_PDC1_WUPDC7_SHIFT                   (14U)
/*! WUPDC7 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC7(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC7_SHIFT)) & LLWU_PDC1_WUPDC7_MASK)

#define LLWU_PDC1_WUPDC8_MASK                    (0x30000U)
#define LLWU_PDC1_WUPDC8_SHIFT                   (16U)
/*! WUPDC8 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC8(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC8_SHIFT)) & LLWU_PDC1_WUPDC8_MASK)

#define LLWU_PDC1_WUPDC9_MASK                    (0xC0000U)
#define LLWU_PDC1_WUPDC9_SHIFT                   (18U)
/*! WUPDC9 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC9(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC9_SHIFT)) & LLWU_PDC1_WUPDC9_MASK)

#define LLWU_PDC1_WUPDC10_MASK                   (0x300000U)
#define LLWU_PDC1_WUPDC10_SHIFT                  (20U)
/*! WUPDC10 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC10(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC10_SHIFT)) & LLWU_PDC1_WUPDC10_MASK)

#define LLWU_PDC1_WUPDC11_MASK                   (0xC00000U)
#define LLWU_PDC1_WUPDC11_SHIFT                  (22U)
/*! WUPDC11 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC11(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC11_SHIFT)) & LLWU_PDC1_WUPDC11_MASK)

#define LLWU_PDC1_WUPDC12_MASK                   (0x3000000U)
#define LLWU_PDC1_WUPDC12_SHIFT                  (24U)
/*! WUPDC12 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC12(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC12_SHIFT)) & LLWU_PDC1_WUPDC12_MASK)

#define LLWU_PDC1_WUPDC13_MASK                   (0xC000000U)
#define LLWU_PDC1_WUPDC13_SHIFT                  (26U)
/*! WUPDC13 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC13(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC13_SHIFT)) & LLWU_PDC1_WUPDC13_MASK)

#define LLWU_PDC1_WUPDC14_MASK                   (0x30000000U)
#define LLWU_PDC1_WUPDC14_SHIFT                  (28U)
/*! WUPDC14 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC14(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC14_SHIFT)) & LLWU_PDC1_WUPDC14_MASK)

#define LLWU_PDC1_WUPDC15_MASK                   (0xC0000000U)
#define LLWU_PDC1_WUPDC15_SHIFT                  (30U)
/*! WUPDC15 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC1_WUPDC15(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC1_WUPDC15_SHIFT)) & LLWU_PDC1_WUPDC15_MASK)
/*! @} */

/*! @name PDC2 - Pin DMA/Trigger Configuration 2 register */
/*! @{ */

#define LLWU_PDC2_WUPDC16_MASK                   (0x3U)
#define LLWU_PDC2_WUPDC16_SHIFT                  (0U)
/*! WUPDC16 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC16(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC16_SHIFT)) & LLWU_PDC2_WUPDC16_MASK)

#define LLWU_PDC2_WUPDC17_MASK                   (0xCU)
#define LLWU_PDC2_WUPDC17_SHIFT                  (2U)
/*! WUPDC17 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC17(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC17_SHIFT)) & LLWU_PDC2_WUPDC17_MASK)

#define LLWU_PDC2_WUPDC18_MASK                   (0x30U)
#define LLWU_PDC2_WUPDC18_SHIFT                  (4U)
/*! WUPDC18 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC18(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC18_SHIFT)) & LLWU_PDC2_WUPDC18_MASK)

#define LLWU_PDC2_WUPDC19_MASK                   (0xC0U)
#define LLWU_PDC2_WUPDC19_SHIFT                  (6U)
/*! WUPDC19 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC19(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC19_SHIFT)) & LLWU_PDC2_WUPDC19_MASK)

#define LLWU_PDC2_WUPDC20_MASK                   (0x300U)
#define LLWU_PDC2_WUPDC20_SHIFT                  (8U)
/*! WUPDC20 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC20(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC20_SHIFT)) & LLWU_PDC2_WUPDC20_MASK)

#define LLWU_PDC2_WUPDC21_MASK                   (0xC00U)
#define LLWU_PDC2_WUPDC21_SHIFT                  (10U)
/*! WUPDC21 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC21(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC21_SHIFT)) & LLWU_PDC2_WUPDC21_MASK)

#define LLWU_PDC2_WUPDC22_MASK                   (0x3000U)
#define LLWU_PDC2_WUPDC22_SHIFT                  (12U)
/*! WUPDC22 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC22(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC22_SHIFT)) & LLWU_PDC2_WUPDC22_MASK)

#define LLWU_PDC2_WUPDC23_MASK                   (0xC000U)
#define LLWU_PDC2_WUPDC23_SHIFT                  (14U)
/*! WUPDC23 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC23(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC23_SHIFT)) & LLWU_PDC2_WUPDC23_MASK)

#define LLWU_PDC2_WUPDC24_MASK                   (0x30000U)
#define LLWU_PDC2_WUPDC24_SHIFT                  (16U)
/*! WUPDC24 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC24(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC24_SHIFT)) & LLWU_PDC2_WUPDC24_MASK)

#define LLWU_PDC2_WUPDC25_MASK                   (0xC0000U)
#define LLWU_PDC2_WUPDC25_SHIFT                  (18U)
/*! WUPDC25 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC25(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC25_SHIFT)) & LLWU_PDC2_WUPDC25_MASK)

#define LLWU_PDC2_WUPDC26_MASK                   (0x300000U)
#define LLWU_PDC2_WUPDC26_SHIFT                  (20U)
/*! WUPDC26 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC26(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC26_SHIFT)) & LLWU_PDC2_WUPDC26_MASK)

#define LLWU_PDC2_Reserved27_MASK                (0xC00000U)
#define LLWU_PDC2_Reserved27_SHIFT               (22U)
/*! Reserved27 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_Reserved27(x)                  (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_Reserved27_SHIFT)) & LLWU_PDC2_Reserved27_MASK)

#define LLWU_PDC2_Reserved28_MASK                (0x3000000U)
#define LLWU_PDC2_Reserved28_SHIFT               (24U)
/*! Reserved28 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_Reserved28(x)                  (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_Reserved28_SHIFT)) & LLWU_PDC2_Reserved28_MASK)

#define LLWU_PDC2_WUPDC29_MASK                   (0xC000000U)
#define LLWU_PDC2_WUPDC29_SHIFT                  (26U)
/*! WUPDC29 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC29(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC29_SHIFT)) & LLWU_PDC2_WUPDC29_MASK)

#define LLWU_PDC2_WUPDC30_MASK                   (0x30000000U)
#define LLWU_PDC2_WUPDC30_SHIFT                  (28U)
/*! WUPDC30 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC30(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC30_SHIFT)) & LLWU_PDC2_WUPDC30_MASK)

#define LLWU_PDC2_WUPDC31_MASK                   (0xC0000000U)
#define LLWU_PDC2_WUPDC31_SHIFT                  (30U)
/*! WUPDC31 - Wakeup pin configuration for LLWU_Pn
 *  0b00..External input pin configured as interrupt
 *  0b01..External input pin configured as DMA request
 *  0b10..External input pin configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_PDC2_WUPDC31(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_PDC2_WUPDC31_SHIFT)) & LLWU_PDC2_WUPDC31_MASK)
/*! @} */

/*! @name FDC - Pin Filter DMA/Trigger Configuration register */
/*! @{ */

#define LLWU_FDC_FILTC1_MASK                     (0x3U)
#define LLWU_FDC_FILTC1_SHIFT                    (0U)
/*! FILTC1 - Filter configuration for FILT1
 *  0b00..Filter output configured as interrupt
 *  0b01..Filter output configured as DMA request
 *  0b10..Filter output configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_FDC_FILTC1(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_FDC_FILTC1_SHIFT)) & LLWU_FDC_FILTC1_MASK)

#define LLWU_FDC_FILTC2_MASK                     (0xCU)
#define LLWU_FDC_FILTC2_SHIFT                    (2U)
/*! FILTC2 - Filter configuration for FILT2
 *  0b00..Filter output configured as interrupt
 *  0b01..Filter output configured as DMA request
 *  0b10..Filter output configured as trigger event
 *  0b11..Reserved
 */
#define LLWU_FDC_FILTC2(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_FDC_FILTC2_SHIFT)) & LLWU_FDC_FILTC2_MASK)
/*! @} */

/*! @name PMC - Pin Mode Configuration register */
/*! @{ */

#define LLWU_PMC_WUPMC0_MASK                     (0x1U)
#define LLWU_PMC_WUPMC0_SHIFT                    (0U)
/*! WUPMC0 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC0(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC0_SHIFT)) & LLWU_PMC_WUPMC0_MASK)

#define LLWU_PMC_WUPMC1_MASK                     (0x2U)
#define LLWU_PMC_WUPMC1_SHIFT                    (1U)
/*! WUPMC1 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC1(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC1_SHIFT)) & LLWU_PMC_WUPMC1_MASK)

#define LLWU_PMC_WUPMC2_MASK                     (0x4U)
#define LLWU_PMC_WUPMC2_SHIFT                    (2U)
/*! WUPMC2 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC2(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC2_SHIFT)) & LLWU_PMC_WUPMC2_MASK)

#define LLWU_PMC_WUPMC3_MASK                     (0x8U)
#define LLWU_PMC_WUPMC3_SHIFT                    (3U)
/*! WUPMC3 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC3(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC3_SHIFT)) & LLWU_PMC_WUPMC3_MASK)

#define LLWU_PMC_WUPMC4_MASK                     (0x10U)
#define LLWU_PMC_WUPMC4_SHIFT                    (4U)
/*! WUPMC4 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC4(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC4_SHIFT)) & LLWU_PMC_WUPMC4_MASK)

#define LLWU_PMC_WUPMC5_MASK                     (0x20U)
#define LLWU_PMC_WUPMC5_SHIFT                    (5U)
/*! WUPMC5 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC5(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC5_SHIFT)) & LLWU_PMC_WUPMC5_MASK)

#define LLWU_PMC_WUPMC6_MASK                     (0x40U)
#define LLWU_PMC_WUPMC6_SHIFT                    (6U)
/*! WUPMC6 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC6(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC6_SHIFT)) & LLWU_PMC_WUPMC6_MASK)

#define LLWU_PMC_WUPMC7_MASK                     (0x80U)
#define LLWU_PMC_WUPMC7_SHIFT                    (7U)
/*! WUPMC7 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC7(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC7_SHIFT)) & LLWU_PMC_WUPMC7_MASK)

#define LLWU_PMC_WUPMC8_MASK                     (0x100U)
#define LLWU_PMC_WUPMC8_SHIFT                    (8U)
/*! WUPMC8 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC8(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC8_SHIFT)) & LLWU_PMC_WUPMC8_MASK)

#define LLWU_PMC_WUPMC9_MASK                     (0x200U)
#define LLWU_PMC_WUPMC9_SHIFT                    (9U)
/*! WUPMC9 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC9(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC9_SHIFT)) & LLWU_PMC_WUPMC9_MASK)

#define LLWU_PMC_WUPMC10_MASK                    (0x400U)
#define LLWU_PMC_WUPMC10_SHIFT                   (10U)
/*! WUPMC10 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC10(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC10_SHIFT)) & LLWU_PMC_WUPMC10_MASK)

#define LLWU_PMC_WUPMC11_MASK                    (0x800U)
#define LLWU_PMC_WUPMC11_SHIFT                   (11U)
/*! WUPMC11 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC11(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC11_SHIFT)) & LLWU_PMC_WUPMC11_MASK)

#define LLWU_PMC_WUPMC12_MASK                    (0x1000U)
#define LLWU_PMC_WUPMC12_SHIFT                   (12U)
/*! WUPMC12 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC12(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC12_SHIFT)) & LLWU_PMC_WUPMC12_MASK)

#define LLWU_PMC_WUPMC13_MASK                    (0x2000U)
#define LLWU_PMC_WUPMC13_SHIFT                   (13U)
/*! WUPMC13 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC13(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC13_SHIFT)) & LLWU_PMC_WUPMC13_MASK)

#define LLWU_PMC_WUPMC14_MASK                    (0x4000U)
#define LLWU_PMC_WUPMC14_SHIFT                   (14U)
/*! WUPMC14 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC14(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC14_SHIFT)) & LLWU_PMC_WUPMC14_MASK)

#define LLWU_PMC_WUPMC15_MASK                    (0x8000U)
#define LLWU_PMC_WUPMC15_SHIFT                   (15U)
/*! WUPMC15 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC15(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC15_SHIFT)) & LLWU_PMC_WUPMC15_MASK)

#define LLWU_PMC_WUPMC16_MASK                    (0x10000U)
#define LLWU_PMC_WUPMC16_SHIFT                   (16U)
/*! WUPMC16 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC16(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC16_SHIFT)) & LLWU_PMC_WUPMC16_MASK)

#define LLWU_PMC_WUPMC17_MASK                    (0x20000U)
#define LLWU_PMC_WUPMC17_SHIFT                   (17U)
/*! WUPMC17 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC17(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC17_SHIFT)) & LLWU_PMC_WUPMC17_MASK)

#define LLWU_PMC_WUPMC18_MASK                    (0x40000U)
#define LLWU_PMC_WUPMC18_SHIFT                   (18U)
/*! WUPMC18 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC18(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC18_SHIFT)) & LLWU_PMC_WUPMC18_MASK)

#define LLWU_PMC_WUPMC19_MASK                    (0x80000U)
#define LLWU_PMC_WUPMC19_SHIFT                   (19U)
/*! WUPMC19 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC19(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC19_SHIFT)) & LLWU_PMC_WUPMC19_MASK)

#define LLWU_PMC_WUPMC20_MASK                    (0x100000U)
#define LLWU_PMC_WUPMC20_SHIFT                   (20U)
/*! WUPMC20 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC20(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC20_SHIFT)) & LLWU_PMC_WUPMC20_MASK)

#define LLWU_PMC_WUPMC21_MASK                    (0x200000U)
#define LLWU_PMC_WUPMC21_SHIFT                   (21U)
/*! WUPMC21 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC21(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC21_SHIFT)) & LLWU_PMC_WUPMC21_MASK)

#define LLWU_PMC_WUPMC22_MASK                    (0x400000U)
#define LLWU_PMC_WUPMC22_SHIFT                   (22U)
/*! WUPMC22 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC22(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC22_SHIFT)) & LLWU_PMC_WUPMC22_MASK)

#define LLWU_PMC_WUPMC23_MASK                    (0x800000U)
#define LLWU_PMC_WUPMC23_SHIFT                   (23U)
/*! WUPMC23 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC23(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC23_SHIFT)) & LLWU_PMC_WUPMC23_MASK)

#define LLWU_PMC_WUPMC24_MASK                    (0x1000000U)
#define LLWU_PMC_WUPMC24_SHIFT                   (24U)
/*! WUPMC24 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC24(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC24_SHIFT)) & LLWU_PMC_WUPMC24_MASK)

#define LLWU_PMC_WUPMC25_MASK                    (0x2000000U)
#define LLWU_PMC_WUPMC25_SHIFT                   (25U)
/*! WUPMC25 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC25(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC25_SHIFT)) & LLWU_PMC_WUPMC25_MASK)

#define LLWU_PMC_WUPMC26_MASK                    (0x4000000U)
#define LLWU_PMC_WUPMC26_SHIFT                   (26U)
/*! WUPMC26 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC26(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC26_SHIFT)) & LLWU_PMC_WUPMC26_MASK)

#define LLWU_PMC_Reserved27_MASK                 (0x8000000U)
#define LLWU_PMC_Reserved27_SHIFT                (27U)
/*! Reserved27 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_Reserved27(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_Reserved27_SHIFT)) & LLWU_PMC_Reserved27_MASK)

#define LLWU_PMC_Reserved28_MASK                 (0x10000000U)
#define LLWU_PMC_Reserved28_SHIFT                (28U)
/*! Reserved28 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_Reserved28(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_Reserved28_SHIFT)) & LLWU_PMC_Reserved28_MASK)

#define LLWU_PMC_WUPMC29_MASK                    (0x20000000U)
#define LLWU_PMC_WUPMC29_SHIFT                   (29U)
/*! WUPMC29 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC29(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC29_SHIFT)) & LLWU_PMC_WUPMC29_MASK)

#define LLWU_PMC_WUPMC30_MASK                    (0x40000000U)
#define LLWU_PMC_WUPMC30_SHIFT                   (30U)
/*! WUPMC30 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC30(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC30_SHIFT)) & LLWU_PMC_WUPMC30_MASK)

#define LLWU_PMC_WUPMC31_MASK                    (0x80000000U)
#define LLWU_PMC_WUPMC31_SHIFT                   (31U)
/*! WUPMC31 - Wakeup pin mode for LLWU_Pn
 *  0b0..External input pin detection active only during LLS/VLLS mode
 *  0b1..External input pin detection active during all power modes
 */
#define LLWU_PMC_WUPMC31(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_PMC_WUPMC31_SHIFT)) & LLWU_PMC_WUPMC31_MASK)
/*! @} */

/*! @name FMC - Pin Filter Mode Configuration register */
/*! @{ */

#define LLWU_FMC_FILTM1_MASK                     (0x1U)
#define LLWU_FMC_FILTM1_SHIFT                    (0U)
/*! FILTM1 - Filter Mode for FILT1
 *  0b0..External input pin filter detection active only during LLS/VLLS mode
 *  0b1..External input pin filter detection active during all power modes
 */
#define LLWU_FMC_FILTM1(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_FMC_FILTM1_SHIFT)) & LLWU_FMC_FILTM1_MASK)

#define LLWU_FMC_FILTM2_MASK                     (0x2U)
#define LLWU_FMC_FILTM2_SHIFT                    (1U)
/*! FILTM2 - Filter Mode for FILT2
 *  0b0..External input pin filter detection active only during LLS/VLLS mode
 *  0b1..External input pin filter detection active during all power modes
 */
#define LLWU_FMC_FILTM2(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_FMC_FILTM2_SHIFT)) & LLWU_FMC_FILTM2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LLWU_Register_Masks */


/*!
 * @}
 */ /* end of group LLWU_Peripheral_Access_Layer */


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


#endif  /* PERI_LLWU_H_ */

