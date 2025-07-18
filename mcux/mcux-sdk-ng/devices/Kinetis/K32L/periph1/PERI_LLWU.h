/*
** ###################################################################
**     Processors:          K32L2A31VLH1A
**                          K32L2A31VLL1A
**                          K32L2A41VLH1A
**                          K32L2A41VLL1A
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
**     - rev. 1.0 (2019-10-30)
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

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
  __IO uint32_t PE1;                               /**< LLWU Pin Enable 1 register, offset: 0x8 */
  __IO uint32_t PE2;                               /**< LLWU Pin Enable 2 register, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< LLWU Module Interrupt Enable register, offset: 0x18 */
  __IO uint32_t DE;                                /**< LLWU Module DMA Enable register, offset: 0x1C */
  __IO uint32_t PF;                                /**< LLWU Pin Flag register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t MF;                                /**< LLWU Module Interrupt Flag register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FILT;                              /**< LLWU Pin Filter register, offset: 0x30 */
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

/*! @name PE1 - LLWU Pin Enable 1 register */
/*! @{ */

#define LLWU_PE1_WUPE0_MASK                      (0x3U)
#define LLWU_PE1_WUPE0_SHIFT                     (0U)
/*! WUPE0 - Wakeup Pin Enable For LLWU_P0
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE0(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE0_SHIFT)) & LLWU_PE1_WUPE0_MASK)

#define LLWU_PE1_WUPE1_MASK                      (0xCU)
#define LLWU_PE1_WUPE1_SHIFT                     (2U)
/*! WUPE1 - Wakeup Pin Enable For LLWU_P1
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE1(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE1_SHIFT)) & LLWU_PE1_WUPE1_MASK)

#define LLWU_PE1_WUPE2_MASK                      (0x30U)
#define LLWU_PE1_WUPE2_SHIFT                     (4U)
/*! WUPE2 - Wakeup Pin Enable For LLWU_P2
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE2(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE2_SHIFT)) & LLWU_PE1_WUPE2_MASK)

#define LLWU_PE1_WUPE3_MASK                      (0xC0U)
#define LLWU_PE1_WUPE3_SHIFT                     (6U)
/*! WUPE3 - Wakeup Pin Enable For LLWU_P3
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE3(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE3_SHIFT)) & LLWU_PE1_WUPE3_MASK)

#define LLWU_PE1_WUPE4_MASK                      (0x300U)
#define LLWU_PE1_WUPE4_SHIFT                     (8U)
/*! WUPE4 - Wakeup Pin Enable For LLWU_P4
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE4(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE4_SHIFT)) & LLWU_PE1_WUPE4_MASK)

#define LLWU_PE1_WUPE5_MASK                      (0xC00U)
#define LLWU_PE1_WUPE5_SHIFT                     (10U)
/*! WUPE5 - Wakeup Pin Enable For LLWU_P5
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE5(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE5_SHIFT)) & LLWU_PE1_WUPE5_MASK)

#define LLWU_PE1_WUPE6_MASK                      (0x3000U)
#define LLWU_PE1_WUPE6_SHIFT                     (12U)
/*! WUPE6 - Wakeup Pin Enable For LLWU_P6
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE6(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE6_SHIFT)) & LLWU_PE1_WUPE6_MASK)

#define LLWU_PE1_WUPE7_MASK                      (0xC000U)
#define LLWU_PE1_WUPE7_SHIFT                     (14U)
/*! WUPE7 - Wakeup Pin Enable For LLWU_P7
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE7(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE7_SHIFT)) & LLWU_PE1_WUPE7_MASK)

#define LLWU_PE1_WUPE8_MASK                      (0x30000U)
#define LLWU_PE1_WUPE8_SHIFT                     (16U)
/*! WUPE8 - Wakeup Pin Enable For LLWU_P8
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE8(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE8_SHIFT)) & LLWU_PE1_WUPE8_MASK)

#define LLWU_PE1_WUPE9_MASK                      (0xC0000U)
#define LLWU_PE1_WUPE9_SHIFT                     (18U)
/*! WUPE9 - Wakeup Pin Enable For LLWU_P9
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE9(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE9_SHIFT)) & LLWU_PE1_WUPE9_MASK)

#define LLWU_PE1_WUPE10_MASK                     (0x300000U)
#define LLWU_PE1_WUPE10_SHIFT                    (20U)
/*! WUPE10 - Wakeup Pin Enable For LLWU_P10
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE10(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE10_SHIFT)) & LLWU_PE1_WUPE10_MASK)

#define LLWU_PE1_WUPE11_MASK                     (0xC00000U)
#define LLWU_PE1_WUPE11_SHIFT                    (22U)
/*! WUPE11 - Wakeup Pin Enable For LLWU_P11
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE11(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE11_SHIFT)) & LLWU_PE1_WUPE11_MASK)

#define LLWU_PE1_WUPE12_MASK                     (0x3000000U)
#define LLWU_PE1_WUPE12_SHIFT                    (24U)
/*! WUPE12 - Wakeup Pin Enable For LLWU_P12
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE12(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE12_SHIFT)) & LLWU_PE1_WUPE12_MASK)

#define LLWU_PE1_WUPE13_MASK                     (0xC000000U)
#define LLWU_PE1_WUPE13_SHIFT                    (26U)
/*! WUPE13 - Wakeup Pin Enable For LLWU_P13
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE13(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE13_SHIFT)) & LLWU_PE1_WUPE13_MASK)

#define LLWU_PE1_WUPE14_MASK                     (0x30000000U)
#define LLWU_PE1_WUPE14_SHIFT                    (28U)
/*! WUPE14 - Wakeup Pin Enable For LLWU_P14
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE14(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE14_SHIFT)) & LLWU_PE1_WUPE14_MASK)

#define LLWU_PE1_WUPE15_MASK                     (0xC0000000U)
#define LLWU_PE1_WUPE15_SHIFT                    (30U)
/*! WUPE15 - Wakeup Pin Enable For LLWU_P15
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE15(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE15_SHIFT)) & LLWU_PE1_WUPE15_MASK)
/*! @} */

/*! @name PE2 - LLWU Pin Enable 2 register */
/*! @{ */

#define LLWU_PE2_WUPE16_MASK                     (0x3U)
#define LLWU_PE2_WUPE16_SHIFT                    (0U)
/*! WUPE16 - Wakeup Pin Enable For LLWU_P16
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE16(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE16_SHIFT)) & LLWU_PE2_WUPE16_MASK)

#define LLWU_PE2_WUPE17_MASK                     (0xCU)
#define LLWU_PE2_WUPE17_SHIFT                    (2U)
/*! WUPE17 - Wakeup Pin Enable For LLWU_P17
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE17(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE17_SHIFT)) & LLWU_PE2_WUPE17_MASK)

#define LLWU_PE2_WUPE18_MASK                     (0x30U)
#define LLWU_PE2_WUPE18_SHIFT                    (4U)
/*! WUPE18 - Wakeup Pin Enable For LLWU_P18
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE18(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE18_SHIFT)) & LLWU_PE2_WUPE18_MASK)

#define LLWU_PE2_WUPE19_MASK                     (0xC0U)
#define LLWU_PE2_WUPE19_SHIFT                    (6U)
/*! WUPE19 - Wakeup Pin Enable For LLWU_P19
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE19(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE19_SHIFT)) & LLWU_PE2_WUPE19_MASK)

#define LLWU_PE2_WUPE20_MASK                     (0x300U)
#define LLWU_PE2_WUPE20_SHIFT                    (8U)
/*! WUPE20 - Wakeup Pin Enable For LLWU_P20
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE20(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE20_SHIFT)) & LLWU_PE2_WUPE20_MASK)

#define LLWU_PE2_WUPE21_MASK                     (0xC00U)
#define LLWU_PE2_WUPE21_SHIFT                    (10U)
/*! WUPE21 - Wakeup Pin Enable For LLWU_P21
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE21(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE21_SHIFT)) & LLWU_PE2_WUPE21_MASK)

#define LLWU_PE2_WUPE22_MASK                     (0x3000U)
#define LLWU_PE2_WUPE22_SHIFT                    (12U)
/*! WUPE22 - Wakeup Pin Enable For LLWU_P22
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE22(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE22_SHIFT)) & LLWU_PE2_WUPE22_MASK)

#define LLWU_PE2_WUPE23_MASK                     (0xC000U)
#define LLWU_PE2_WUPE23_SHIFT                    (14U)
/*! WUPE23 - Wakeup Pin Enable For LLWU_P23
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE23(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE23_SHIFT)) & LLWU_PE2_WUPE23_MASK)

#define LLWU_PE2_WUPE24_MASK                     (0x30000U)
#define LLWU_PE2_WUPE24_SHIFT                    (16U)
/*! WUPE24 - Wakeup Pin Enable For LLWU_P24
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE24(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE24_SHIFT)) & LLWU_PE2_WUPE24_MASK)

#define LLWU_PE2_WUPE25_MASK                     (0xC0000U)
#define LLWU_PE2_WUPE25_SHIFT                    (18U)
/*! WUPE25 - Wakeup Pin Enable For LLWU_P25
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE25(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE25_SHIFT)) & LLWU_PE2_WUPE25_MASK)

#define LLWU_PE2_WUPE26_MASK                     (0x300000U)
#define LLWU_PE2_WUPE26_SHIFT                    (20U)
/*! WUPE26 - Wakeup Pin Enable For LLWU_P26
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE26(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE26_SHIFT)) & LLWU_PE2_WUPE26_MASK)

#define LLWU_PE2_WUPE27_MASK                     (0xC00000U)
#define LLWU_PE2_WUPE27_SHIFT                    (22U)
/*! WUPE27 - Wakeup Pin Enable For LLWU_P27
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE27(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE27_SHIFT)) & LLWU_PE2_WUPE27_MASK)

#define LLWU_PE2_WUPE28_MASK                     (0x3000000U)
#define LLWU_PE2_WUPE28_SHIFT                    (24U)
/*! WUPE28 - Wakeup Pin Enable For LLWU_P28
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE28(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE28_SHIFT)) & LLWU_PE2_WUPE28_MASK)

#define LLWU_PE2_WUPE29_MASK                     (0xC000000U)
#define LLWU_PE2_WUPE29_SHIFT                    (26U)
/*! WUPE29 - Wakeup Pin Enable For LLWU_P29
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE29(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE29_SHIFT)) & LLWU_PE2_WUPE29_MASK)

#define LLWU_PE2_WUPE30_MASK                     (0x30000000U)
#define LLWU_PE2_WUPE30_SHIFT                    (28U)
/*! WUPE30 - Wakeup Pin Enable For LLWU_P30
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE30(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE30_SHIFT)) & LLWU_PE2_WUPE30_MASK)

#define LLWU_PE2_WUPE31_MASK                     (0xC0000000U)
#define LLWU_PE2_WUPE31_SHIFT                    (30U)
/*! WUPE31 - Wakeup Pin Enable For LLWU_P31
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE31(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_WUPE31_SHIFT)) & LLWU_PE2_WUPE31_MASK)
/*! @} */

/*! @name ME - LLWU Module Interrupt Enable register */
/*! @{ */

#define LLWU_ME_WUME0_MASK                       (0x1U)
#define LLWU_ME_WUME0_SHIFT                      (0U)
/*! WUME0 - Wakeup Module Enable For Module 0
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME0_SHIFT)) & LLWU_ME_WUME0_MASK)

#define LLWU_ME_WUME1_MASK                       (0x2U)
#define LLWU_ME_WUME1_SHIFT                      (1U)
/*! WUME1 - Wakeup Module Enable for Module 1
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME1_SHIFT)) & LLWU_ME_WUME1_MASK)

#define LLWU_ME_WUME2_MASK                       (0x4U)
#define LLWU_ME_WUME2_SHIFT                      (2U)
/*! WUME2 - Wakeup Module Enable For Module 2
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME2_SHIFT)) & LLWU_ME_WUME2_MASK)

#define LLWU_ME_WUME3_MASK                       (0x8U)
#define LLWU_ME_WUME3_SHIFT                      (3U)
/*! WUME3 - Wakeup Module Enable For Module 3
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME3_SHIFT)) & LLWU_ME_WUME3_MASK)

#define LLWU_ME_WUME4_MASK                       (0x10U)
#define LLWU_ME_WUME4_SHIFT                      (4U)
/*! WUME4 - Wakeup Module Enable For Module 4
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME4_SHIFT)) & LLWU_ME_WUME4_MASK)

#define LLWU_ME_WUME5_MASK                       (0x20U)
#define LLWU_ME_WUME5_SHIFT                      (5U)
/*! WUME5 - Wakeup Module Enable For Module 5
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME5(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME5_SHIFT)) & LLWU_ME_WUME5_MASK)

#define LLWU_ME_WUME6_MASK                       (0x40U)
#define LLWU_ME_WUME6_SHIFT                      (6U)
/*! WUME6 - Wakeup Module Enable For Module 6
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME6_SHIFT)) & LLWU_ME_WUME6_MASK)

#define LLWU_ME_WUME7_MASK                       (0x80U)
#define LLWU_ME_WUME7_SHIFT                      (7U)
/*! WUME7 - Wakeup Module Enable For Module 7
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME7(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME7_SHIFT)) & LLWU_ME_WUME7_MASK)
/*! @} */

/*! @name DE - LLWU Module DMA Enable register */
/*! @{ */

#define LLWU_DE_WUDE0_MASK                       (0x1U)
#define LLWU_DE_WUDE0_SHIFT                      (0U)
/*! WUDE0 - DMA Wakeup Enable For Module 0
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE0_SHIFT)) & LLWU_DE_WUDE0_MASK)

#define LLWU_DE_WUDE1_MASK                       (0x2U)
#define LLWU_DE_WUDE1_SHIFT                      (1U)
/*! WUDE1 - DMA Wakeup Enable for Module 1
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE1_SHIFT)) & LLWU_DE_WUDE1_MASK)

#define LLWU_DE_WUDE2_MASK                       (0x4U)
#define LLWU_DE_WUDE2_SHIFT                      (2U)
/*! WUDE2 - DMA Wakeup Enable For Module 2
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE2_SHIFT)) & LLWU_DE_WUDE2_MASK)

#define LLWU_DE_WUDE3_MASK                       (0x8U)
#define LLWU_DE_WUDE3_SHIFT                      (3U)
/*! WUDE3 - DMA Wakeup Enable For Module 3
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE3_SHIFT)) & LLWU_DE_WUDE3_MASK)

#define LLWU_DE_WUDE4_MASK                       (0x10U)
#define LLWU_DE_WUDE4_SHIFT                      (4U)
/*! WUDE4 - DMA Wakeup Enable For Module 4
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE4_SHIFT)) & LLWU_DE_WUDE4_MASK)

#define LLWU_DE_WUDE5_MASK                       (0x20U)
#define LLWU_DE_WUDE5_SHIFT                      (5U)
/*! WUDE5 - DMA Wakeup Enable For Module 5
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE5(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE5_SHIFT)) & LLWU_DE_WUDE5_MASK)

#define LLWU_DE_WUDE6_MASK                       (0x40U)
#define LLWU_DE_WUDE6_SHIFT                      (6U)
/*! WUDE6 - DMA Wakeup Enable For Module 6
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE6_SHIFT)) & LLWU_DE_WUDE6_MASK)

#define LLWU_DE_WUDE7_MASK                       (0x80U)
#define LLWU_DE_WUDE7_SHIFT                      (7U)
/*! WUDE7 - DMA Wakeup Enable For Module 7
 *  0b0..Internal module request not used as a DMA wakeup source
 *  0b1..Internal module request used as a DMA wakeup source
 */
#define LLWU_DE_WUDE7(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_DE_WUDE7_SHIFT)) & LLWU_DE_WUDE7_MASK)
/*! @} */

/*! @name PF - LLWU Pin Flag register */
/*! @{ */

#define LLWU_PF_WUF0_MASK                        (0x1U)
#define LLWU_PF_WUF0_SHIFT                       (0U)
/*! WUF0 - Wakeup Flag For LLWU_P0
 *  0b0..LLWU_P0 input was not a wakeup source
 *  0b1..LLWU_P0 input was a wakeup source
 */
#define LLWU_PF_WUF0(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF0_SHIFT)) & LLWU_PF_WUF0_MASK)

#define LLWU_PF_WUF1_MASK                        (0x2U)
#define LLWU_PF_WUF1_SHIFT                       (1U)
/*! WUF1 - Wakeup Flag For LLWU_P1
 *  0b0..LLWU_P1 input was not a wakeup source
 *  0b1..LLWU_P1 input was a wakeup source
 */
#define LLWU_PF_WUF1(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF1_SHIFT)) & LLWU_PF_WUF1_MASK)

#define LLWU_PF_WUF2_MASK                        (0x4U)
#define LLWU_PF_WUF2_SHIFT                       (2U)
/*! WUF2 - Wakeup Flag For LLWU_P2
 *  0b0..LLWU_P2 input was not a wakeup source
 *  0b1..LLWU_P2 input was a wakeup source
 */
#define LLWU_PF_WUF2(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF2_SHIFT)) & LLWU_PF_WUF2_MASK)

#define LLWU_PF_WUF3_MASK                        (0x8U)
#define LLWU_PF_WUF3_SHIFT                       (3U)
/*! WUF3 - Wakeup Flag For LLWU_P3
 *  0b0..LLWU_P3 input was not a wakeup source
 *  0b1..LLWU_P3 input was a wakeup source
 */
#define LLWU_PF_WUF3(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF3_SHIFT)) & LLWU_PF_WUF3_MASK)

#define LLWU_PF_WUF4_MASK                        (0x10U)
#define LLWU_PF_WUF4_SHIFT                       (4U)
/*! WUF4 - Wakeup Flag For LLWU_P4
 *  0b0..LLWU_P4 input was not a wakeup source
 *  0b1..LLWU_P4 input was a wakeup source
 */
#define LLWU_PF_WUF4(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF4_SHIFT)) & LLWU_PF_WUF4_MASK)

#define LLWU_PF_WUF5_MASK                        (0x20U)
#define LLWU_PF_WUF5_SHIFT                       (5U)
/*! WUF5 - Wakeup Flag For LLWU_P5
 *  0b0..LLWU_P5 input was not a wakeup source
 *  0b1..LLWU_P5 input was a wakeup source
 */
#define LLWU_PF_WUF5(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF5_SHIFT)) & LLWU_PF_WUF5_MASK)

#define LLWU_PF_WUF6_MASK                        (0x40U)
#define LLWU_PF_WUF6_SHIFT                       (6U)
/*! WUF6 - Wakeup Flag For LLWU_P6
 *  0b0..LLWU_P6 input was not a wakeup source
 *  0b1..LLWU_P6 input was a wakeup source
 */
#define LLWU_PF_WUF6(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF6_SHIFT)) & LLWU_PF_WUF6_MASK)

#define LLWU_PF_WUF7_MASK                        (0x80U)
#define LLWU_PF_WUF7_SHIFT                       (7U)
/*! WUF7 - Wakeup Flag For LLWU_P7
 *  0b0..LLWU_P7 input was not a wakeup source
 *  0b1..LLWU_P7 input was a wakeup source
 */
#define LLWU_PF_WUF7(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF7_SHIFT)) & LLWU_PF_WUF7_MASK)

#define LLWU_PF_WUF8_MASK                        (0x100U)
#define LLWU_PF_WUF8_SHIFT                       (8U)
/*! WUF8 - Wakeup Flag For LLWU_P8
 *  0b0..LLWU_P8 input was not a wakeup source
 *  0b1..LLWU_P8 input was a wakeup source
 */
#define LLWU_PF_WUF8(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF8_SHIFT)) & LLWU_PF_WUF8_MASK)

#define LLWU_PF_WUF9_MASK                        (0x200U)
#define LLWU_PF_WUF9_SHIFT                       (9U)
/*! WUF9 - Wakeup Flag For LLWU_P9
 *  0b0..LLWU_P9 input was not a wakeup source
 *  0b1..LLWU_P9 input was a wakeup source
 */
#define LLWU_PF_WUF9(x)                          (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF9_SHIFT)) & LLWU_PF_WUF9_MASK)

#define LLWU_PF_WUF10_MASK                       (0x400U)
#define LLWU_PF_WUF10_SHIFT                      (10U)
/*! WUF10 - Wakeup Flag For LLWU_P10
 *  0b0..LLWU_P10 input was not a wakeup source
 *  0b1..LLWU_P10 input was a wakeup source
 */
#define LLWU_PF_WUF10(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF10_SHIFT)) & LLWU_PF_WUF10_MASK)

#define LLWU_PF_WUF11_MASK                       (0x800U)
#define LLWU_PF_WUF11_SHIFT                      (11U)
/*! WUF11 - Wakeup Flag For LLWU_P11
 *  0b0..LLWU_P11 input was not a wakeup source
 *  0b1..LLWU_P11 input was a wakeup source
 */
#define LLWU_PF_WUF11(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF11_SHIFT)) & LLWU_PF_WUF11_MASK)

#define LLWU_PF_WUF12_MASK                       (0x1000U)
#define LLWU_PF_WUF12_SHIFT                      (12U)
/*! WUF12 - Wakeup Flag For LLWU_P12
 *  0b0..LLWU_P12 input was not a wakeup source
 *  0b1..LLWU_P12 input was a wakeup source
 */
#define LLWU_PF_WUF12(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF12_SHIFT)) & LLWU_PF_WUF12_MASK)

#define LLWU_PF_WUF13_MASK                       (0x2000U)
#define LLWU_PF_WUF13_SHIFT                      (13U)
/*! WUF13 - Wakeup Flag For LLWU_P13
 *  0b0..LLWU_P13 input was not a wakeup source
 *  0b1..LLWU_P13 input was a wakeup source
 */
#define LLWU_PF_WUF13(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF13_SHIFT)) & LLWU_PF_WUF13_MASK)

#define LLWU_PF_WUF14_MASK                       (0x4000U)
#define LLWU_PF_WUF14_SHIFT                      (14U)
/*! WUF14 - Wakeup Flag For LLWU_P14
 *  0b0..LLWU_P14 input was not a wakeup source
 *  0b1..LLWU_P14 input was a wakeup source
 */
#define LLWU_PF_WUF14(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF14_SHIFT)) & LLWU_PF_WUF14_MASK)

#define LLWU_PF_WUF15_MASK                       (0x8000U)
#define LLWU_PF_WUF15_SHIFT                      (15U)
/*! WUF15 - Wakeup Flag For LLWU_P15
 *  0b0..LLWU_P15 input was not a wakeup source
 *  0b1..LLWU_P15 input was a wakeup source
 */
#define LLWU_PF_WUF15(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF15_SHIFT)) & LLWU_PF_WUF15_MASK)

#define LLWU_PF_WUF16_MASK                       (0x10000U)
#define LLWU_PF_WUF16_SHIFT                      (16U)
/*! WUF16 - Wakeup Flag For LLWU_P16
 *  0b0..LLWU_P16 input was not a wakeup source
 *  0b1..LLWU_P16 input was a wakeup source
 */
#define LLWU_PF_WUF16(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF16_SHIFT)) & LLWU_PF_WUF16_MASK)

#define LLWU_PF_WUF17_MASK                       (0x20000U)
#define LLWU_PF_WUF17_SHIFT                      (17U)
/*! WUF17 - Wakeup Flag For LLWU_P17
 *  0b0..LLWU_P17 input was not a wakeup source
 *  0b1..LLWU_P17 input was a wakeup source
 */
#define LLWU_PF_WUF17(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF17_SHIFT)) & LLWU_PF_WUF17_MASK)

#define LLWU_PF_WUF18_MASK                       (0x40000U)
#define LLWU_PF_WUF18_SHIFT                      (18U)
/*! WUF18 - Wakeup Flag For LLWU_P18
 *  0b0..LLWU_P18 input was not a wakeup source
 *  0b1..LLWU_P18 input was a wakeup source
 */
#define LLWU_PF_WUF18(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF18_SHIFT)) & LLWU_PF_WUF18_MASK)

#define LLWU_PF_WUF19_MASK                       (0x80000U)
#define LLWU_PF_WUF19_SHIFT                      (19U)
/*! WUF19 - Wakeup Flag For LLWU_P19
 *  0b0..LLWU_P19 input was not a wakeup source
 *  0b1..LLWU_P19 input was a wakeup source
 */
#define LLWU_PF_WUF19(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF19_SHIFT)) & LLWU_PF_WUF19_MASK)

#define LLWU_PF_WUF20_MASK                       (0x100000U)
#define LLWU_PF_WUF20_SHIFT                      (20U)
/*! WUF20 - Wakeup Flag For LLWU_P20
 *  0b0..LLWU_P20 input was not a wakeup source
 *  0b1..LLWU_P20 input was a wakeup source
 */
#define LLWU_PF_WUF20(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF20_SHIFT)) & LLWU_PF_WUF20_MASK)

#define LLWU_PF_WUF21_MASK                       (0x200000U)
#define LLWU_PF_WUF21_SHIFT                      (21U)
/*! WUF21 - Wakeup Flag For LLWU_P21
 *  0b0..LLWU_P21 input was not a wakeup source
 *  0b1..LLWU_P21 input was a wakeup source
 */
#define LLWU_PF_WUF21(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF21_SHIFT)) & LLWU_PF_WUF21_MASK)

#define LLWU_PF_WUF22_MASK                       (0x400000U)
#define LLWU_PF_WUF22_SHIFT                      (22U)
/*! WUF22 - Wakeup Flag For LLWU_P22
 *  0b0..LLWU_P22 input was not a wakeup source
 *  0b1..LLWU_P22 input was a wakeup source
 */
#define LLWU_PF_WUF22(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF22_SHIFT)) & LLWU_PF_WUF22_MASK)

#define LLWU_PF_WUF23_MASK                       (0x800000U)
#define LLWU_PF_WUF23_SHIFT                      (23U)
/*! WUF23 - Wakeup Flag For LLWU_P23
 *  0b0..LLWU_P23 input was not a wakeup source
 *  0b1..LLWU_P23 input was a wakeup source
 */
#define LLWU_PF_WUF23(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF23_SHIFT)) & LLWU_PF_WUF23_MASK)

#define LLWU_PF_WUF24_MASK                       (0x1000000U)
#define LLWU_PF_WUF24_SHIFT                      (24U)
/*! WUF24 - Wakeup Flag For LLWU_P24
 *  0b0..LLWU_P24 input was not a wakeup source
 *  0b1..LLWU_P24 input was a wakeup source
 */
#define LLWU_PF_WUF24(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF24_SHIFT)) & LLWU_PF_WUF24_MASK)

#define LLWU_PF_WUF25_MASK                       (0x2000000U)
#define LLWU_PF_WUF25_SHIFT                      (25U)
/*! WUF25 - Wakeup Flag For LLWU_P25
 *  0b0..LLWU_P25 input was not a wakeup source
 *  0b1..LLWU_P25 input was a wakeup source
 */
#define LLWU_PF_WUF25(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF25_SHIFT)) & LLWU_PF_WUF25_MASK)

#define LLWU_PF_WUF26_MASK                       (0x4000000U)
#define LLWU_PF_WUF26_SHIFT                      (26U)
/*! WUF26 - Wakeup Flag For LLWU_P26
 *  0b0..LLWU_P26 input was not a wakeup source
 *  0b1..LLWU_P26 input was a wakeup source
 */
#define LLWU_PF_WUF26(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF26_SHIFT)) & LLWU_PF_WUF26_MASK)

#define LLWU_PF_WUF27_MASK                       (0x8000000U)
#define LLWU_PF_WUF27_SHIFT                      (27U)
/*! WUF27 - Wakeup Flag For LLWU_P27
 *  0b0..LLWU_P27 input was not a wakeup source
 *  0b1..LLWU_P27 input was a wakeup source
 */
#define LLWU_PF_WUF27(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF27_SHIFT)) & LLWU_PF_WUF27_MASK)

#define LLWU_PF_WUF28_MASK                       (0x10000000U)
#define LLWU_PF_WUF28_SHIFT                      (28U)
/*! WUF28 - Wakeup Flag For LLWU_P28
 *  0b0..LLWU_P28 input was not a wakeup source
 *  0b1..LLWU_P28 input was a wakeup source
 */
#define LLWU_PF_WUF28(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF28_SHIFT)) & LLWU_PF_WUF28_MASK)

#define LLWU_PF_WUF29_MASK                       (0x20000000U)
#define LLWU_PF_WUF29_SHIFT                      (29U)
/*! WUF29 - Wakeup Flag For LLWU_P29
 *  0b0..LLWU_P29 input was not a wakeup source
 *  0b1..LLWU_P29 input was a wakeup source
 */
#define LLWU_PF_WUF29(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF29_SHIFT)) & LLWU_PF_WUF29_MASK)

#define LLWU_PF_WUF30_MASK                       (0x40000000U)
#define LLWU_PF_WUF30_SHIFT                      (30U)
/*! WUF30 - Wakeup Flag For LLWU_P30
 *  0b0..LLWU_P30 input was not a wakeup source
 *  0b1..LLWU_P30 input was a wakeup source
 */
#define LLWU_PF_WUF30(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF30_SHIFT)) & LLWU_PF_WUF30_MASK)

#define LLWU_PF_WUF31_MASK                       (0x80000000U)
#define LLWU_PF_WUF31_SHIFT                      (31U)
/*! WUF31 - Wakeup Flag For LLWU_P31
 *  0b0..LLWU_P31 input was not a wakeup source
 *  0b1..LLWU_P31 input was a wakeup source
 */
#define LLWU_PF_WUF31(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_PF_WUF31_SHIFT)) & LLWU_PF_WUF31_MASK)
/*! @} */

/*! @name MF - LLWU Module Interrupt Flag register */
/*! @{ */

#define LLWU_MF_MWUF0_MASK                       (0x1U)
#define LLWU_MF_MWUF0_SHIFT                      (0U)
/*! MWUF0 - Wakeup flag For module 0
 *  0b0..Module 0 input was not a wakeup source
 *  0b1..Module 0 input was a wakeup source
 */
#define LLWU_MF_MWUF0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF0_SHIFT)) & LLWU_MF_MWUF0_MASK)

#define LLWU_MF_MWUF1_MASK                       (0x2U)
#define LLWU_MF_MWUF1_SHIFT                      (1U)
/*! MWUF1 - Wakeup flag For module 1
 *  0b0..Module 1 input was not a wakeup source
 *  0b1..Module 1 input was a wakeup source
 */
#define LLWU_MF_MWUF1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF1_SHIFT)) & LLWU_MF_MWUF1_MASK)

#define LLWU_MF_MWUF2_MASK                       (0x4U)
#define LLWU_MF_MWUF2_SHIFT                      (2U)
/*! MWUF2 - Wakeup flag For module 2
 *  0b0..Module 2 input was not a wakeup source
 *  0b1..Module 2 input was a wakeup source
 */
#define LLWU_MF_MWUF2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF2_SHIFT)) & LLWU_MF_MWUF2_MASK)

#define LLWU_MF_MWUF3_MASK                       (0x8U)
#define LLWU_MF_MWUF3_SHIFT                      (3U)
/*! MWUF3 - Wakeup flag For module 3
 *  0b0..Module 3 input was not a wakeup source
 *  0b1..Module 3 input was a wakeup source
 */
#define LLWU_MF_MWUF3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF3_SHIFT)) & LLWU_MF_MWUF3_MASK)

#define LLWU_MF_MWUF4_MASK                       (0x10U)
#define LLWU_MF_MWUF4_SHIFT                      (4U)
/*! MWUF4 - Wakeup flag For module 4
 *  0b0..Module 4 input was not a wakeup source
 *  0b1..Module 4 input was a wakeup source
 */
#define LLWU_MF_MWUF4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF4_SHIFT)) & LLWU_MF_MWUF4_MASK)

#define LLWU_MF_MWUF5_MASK                       (0x20U)
#define LLWU_MF_MWUF5_SHIFT                      (5U)
/*! MWUF5 - Wakeup flag For module 5
 *  0b0..Module 5 input was not a wakeup source
 *  0b1..Module 5 input was a wakeup source
 */
#define LLWU_MF_MWUF5(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF5_SHIFT)) & LLWU_MF_MWUF5_MASK)

#define LLWU_MF_MWUF6_MASK                       (0x40U)
#define LLWU_MF_MWUF6_SHIFT                      (6U)
/*! MWUF6 - Wakeup flag For module 6
 *  0b0..Module 6 input was not a wakeup source
 *  0b1..Module 6 input was a wakeup source
 */
#define LLWU_MF_MWUF6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF6_SHIFT)) & LLWU_MF_MWUF6_MASK)

#define LLWU_MF_MWUF7_MASK                       (0x80U)
#define LLWU_MF_MWUF7_SHIFT                      (7U)
/*! MWUF7 - Wakeup flag For module 7
 *  0b0..Module 7 input was not a wakeup source
 *  0b1..Module 7 input was a wakeup source
 */
#define LLWU_MF_MWUF7(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF7_SHIFT)) & LLWU_MF_MWUF7_MASK)
/*! @} */

/*! @name FILT - LLWU Pin Filter register */
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
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
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
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
 */
#define LLWU_FILT_FILTE2(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTE2_SHIFT)) & LLWU_FILT_FILTE2_MASK)

#define LLWU_FILT_FILTF2_MASK                    (0x8000U)
#define LLWU_FILT_FILTF2_SHIFT                   (15U)
/*! FILTF2 - Filter 2 Flag
 *  0b0..Pin Filter 1 was not a wakeup source
 *  0b1..Pin Filter 1 was a wakeup source
 */
#define LLWU_FILT_FILTF2(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTF2_SHIFT)) & LLWU_FILT_FILTF2_MASK)

#define LLWU_FILT_FILTSEL3_MASK                  (0x1F0000U)
#define LLWU_FILT_FILTSEL3_SHIFT                 (16U)
/*! FILTSEL3 - Filter 3 Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT_FILTSEL3(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTSEL3_SHIFT)) & LLWU_FILT_FILTSEL3_MASK)

#define LLWU_FILT_FILTE3_MASK                    (0x600000U)
#define LLWU_FILT_FILTE3_SHIFT                   (21U)
/*! FILTE3 - Filter 3 Enable
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
 */
#define LLWU_FILT_FILTE3(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTE3_SHIFT)) & LLWU_FILT_FILTE3_MASK)

#define LLWU_FILT_FILTF3_MASK                    (0x800000U)
#define LLWU_FILT_FILTF3_SHIFT                   (23U)
/*! FILTF3 - Filter 3 Flag
 *  0b0..Pin Filter 1 was not a wakeup source
 *  0b1..Pin Filter 1 was a wakeup source
 */
#define LLWU_FILT_FILTF3(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTF3_SHIFT)) & LLWU_FILT_FILTF3_MASK)

#define LLWU_FILT_FILTSEL4_MASK                  (0x1F000000U)
#define LLWU_FILT_FILTSEL4_SHIFT                 (24U)
/*! FILTSEL4 - Filter 4 Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT_FILTSEL4(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTSEL4_SHIFT)) & LLWU_FILT_FILTSEL4_MASK)

#define LLWU_FILT_FILTE4_MASK                    (0x60000000U)
#define LLWU_FILT_FILTE4_SHIFT                   (29U)
/*! FILTE4 - Filter 4 Enable
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
 */
#define LLWU_FILT_FILTE4(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTE4_SHIFT)) & LLWU_FILT_FILTE4_MASK)

#define LLWU_FILT_FILTF4_MASK                    (0x80000000U)
#define LLWU_FILT_FILTF4_SHIFT                   (31U)
/*! FILTF4 - Filter 4 Flag
 *  0b0..Pin Filter 1 was not a wakeup source
 *  0b1..Pin Filter 1 was a wakeup source
 */
#define LLWU_FILT_FILTF4(x)                      (((uint32_t)(((uint32_t)(x)) << LLWU_FILT_FILTF4_SHIFT)) & LLWU_FILT_FILTF4_MASK)
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
#elif defined(__CWCC__)
  #pragma pop
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

