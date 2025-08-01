/*
** ###################################################################
**     Processors:          MKM34Z256VLL7
**                          MKM34Z256VLQ7
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
**     - rev. 1.0 (2014-10-17)
**         Initial version.
**     - rev. 1.1 (2015-01-27)
**         Update according to reference manual rev. 1, RC.
**     - rev. 1.2 (2015-03-06)
**         Update according to reference manual rev. 1.
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

#if (defined(CPU_MKM34Z256VLL7) || defined(CPU_MKM34Z256VLQ7))
#include "MKM34Z7_COMMON.h"
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
  __IO uint8_t PE1;                                /**< LLWU Pin Enable 1 register, offset: 0x0 */
  __IO uint8_t PE2;                                /**< LLWU Pin Enable 2 register, offset: 0x1 */
  __IO uint8_t PE3;                                /**< LLWU Pin Enable 3 register, offset: 0x2 */
  __IO uint8_t PE4;                                /**< LLWU Pin Enable 4 register, offset: 0x3 */
  __IO uint8_t PE5;                                /**< LLWU Pin Enable 5 register, offset: 0x4 */
  __IO uint8_t PE6;                                /**< LLWU Pin Enable 6 register, offset: 0x5 */
  __IO uint8_t PE7;                                /**< LLWU Pin Enable 7 register, offset: 0x6 */
  __IO uint8_t PE8;                                /**< LLWU Pin Enable 8 register, offset: 0x7 */
  __IO uint8_t ME;                                 /**< LLWU Module Enable register, offset: 0x8 */
  __IO uint8_t PF1;                                /**< LLWU Pin Flag 1 register, offset: 0x9 */
  __IO uint8_t PF2;                                /**< LLWU Pin Flag 2 register, offset: 0xA */
  __IO uint8_t PF3;                                /**< LLWU Pin Flag 3 register, offset: 0xB */
  __IO uint8_t PF4;                                /**< LLWU Pin Flag 4 register, offset: 0xC */
  __I  uint8_t MF5;                                /**< LLWU Module Flag 5 register, offset: 0xD */
  __IO uint8_t FILT1;                              /**< LLWU Pin Filter 1 register, offset: 0xE */
  __IO uint8_t FILT2;                              /**< LLWU Pin Filter 2 register, offset: 0xF */
} LLWU_Type;

/* ----------------------------------------------------------------------------
   -- LLWU Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LLWU_Register_Masks LLWU Register Masks
 * @{
 */

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
#define LLWU_PE1_WUPE0(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE0_SHIFT)) & LLWU_PE1_WUPE0_MASK)

#define LLWU_PE1_WUPE1_MASK                      (0xCU)
#define LLWU_PE1_WUPE1_SHIFT                     (2U)
/*! WUPE1 - Wakeup Pin Enable For LLWU_P1
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE1(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE1_SHIFT)) & LLWU_PE1_WUPE1_MASK)

#define LLWU_PE1_WUPE2_MASK                      (0x30U)
#define LLWU_PE1_WUPE2_SHIFT                     (4U)
/*! WUPE2 - Wakeup Pin Enable For LLWU_P2
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE2(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE2_SHIFT)) & LLWU_PE1_WUPE2_MASK)

#define LLWU_PE1_WUPE3_MASK                      (0xC0U)
#define LLWU_PE1_WUPE3_SHIFT                     (6U)
/*! WUPE3 - Wakeup Pin Enable For LLWU_P3
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE3(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE1_WUPE3_SHIFT)) & LLWU_PE1_WUPE3_MASK)
/*! @} */

/*! @name PE2 - LLWU Pin Enable 2 register */
/*! @{ */

#define LLWU_PE2_WUPE4_MASK                      (0x3U)
#define LLWU_PE2_WUPE4_SHIFT                     (0U)
/*! WUPE4 - Wakeup Pin Enable For LLWU_P4
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE4(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE4_SHIFT)) & LLWU_PE2_WUPE4_MASK)

#define LLWU_PE2_WUPE5_MASK                      (0xCU)
#define LLWU_PE2_WUPE5_SHIFT                     (2U)
/*! WUPE5 - Wakeup Pin Enable For LLWU_P5
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE5(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE5_SHIFT)) & LLWU_PE2_WUPE5_MASK)

#define LLWU_PE2_WUPE6_MASK                      (0x30U)
#define LLWU_PE2_WUPE6_SHIFT                     (4U)
/*! WUPE6 - Wakeup Pin Enable For LLWU_P6
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE6(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE6_SHIFT)) & LLWU_PE2_WUPE6_MASK)

#define LLWU_PE2_WUPE7_MASK                      (0xC0U)
#define LLWU_PE2_WUPE7_SHIFT                     (6U)
/*! WUPE7 - Wakeup Pin Enable For LLWU_P7
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_WUPE7(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE2_WUPE7_SHIFT)) & LLWU_PE2_WUPE7_MASK)
/*! @} */

/*! @name PE3 - LLWU Pin Enable 3 register */
/*! @{ */

#define LLWU_PE3_WUPE8_MASK                      (0x3U)
#define LLWU_PE3_WUPE8_SHIFT                     (0U)
/*! WUPE8 - Wakeup Pin Enable For LLWU_P8
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE3_WUPE8(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE8_SHIFT)) & LLWU_PE3_WUPE8_MASK)

#define LLWU_PE3_WUPE9_MASK                      (0xCU)
#define LLWU_PE3_WUPE9_SHIFT                     (2U)
/*! WUPE9 - Wakeup Pin Enable For LLWU_P9
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE3_WUPE9(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE9_SHIFT)) & LLWU_PE3_WUPE9_MASK)

#define LLWU_PE3_WUPE10_MASK                     (0x30U)
#define LLWU_PE3_WUPE10_SHIFT                    (4U)
/*! WUPE10 - Wakeup Pin Enable For LLWU_P10
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE3_WUPE10(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE10_SHIFT)) & LLWU_PE3_WUPE10_MASK)

#define LLWU_PE3_WUPE11_MASK                     (0xC0U)
#define LLWU_PE3_WUPE11_SHIFT                    (6U)
/*! WUPE11 - Wakeup Pin Enable For LLWU_P11
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE3_WUPE11(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE3_WUPE11_SHIFT)) & LLWU_PE3_WUPE11_MASK)
/*! @} */

/*! @name PE4 - LLWU Pin Enable 4 register */
/*! @{ */

#define LLWU_PE4_WUPE12_MASK                     (0x3U)
#define LLWU_PE4_WUPE12_SHIFT                    (0U)
/*! WUPE12 - Wakeup Pin Enable For LLWU_P12
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE4_WUPE12(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE12_SHIFT)) & LLWU_PE4_WUPE12_MASK)

#define LLWU_PE4_WUPE13_MASK                     (0xCU)
#define LLWU_PE4_WUPE13_SHIFT                    (2U)
/*! WUPE13 - Wakeup Pin Enable For LLWU_P13
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE4_WUPE13(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE13_SHIFT)) & LLWU_PE4_WUPE13_MASK)

#define LLWU_PE4_WUPE14_MASK                     (0x30U)
#define LLWU_PE4_WUPE14_SHIFT                    (4U)
/*! WUPE14 - Wakeup Pin Enable For LLWU_P14
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE4_WUPE14(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE14_SHIFT)) & LLWU_PE4_WUPE14_MASK)

#define LLWU_PE4_WUPE15_MASK                     (0xC0U)
#define LLWU_PE4_WUPE15_SHIFT                    (6U)
/*! WUPE15 - Wakeup Pin Enable For LLWU_P15
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE4_WUPE15(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE4_WUPE15_SHIFT)) & LLWU_PE4_WUPE15_MASK)
/*! @} */

/*! @name PE5 - LLWU Pin Enable 5 register */
/*! @{ */

#define LLWU_PE5_WUPE16_MASK                     (0x3U)
#define LLWU_PE5_WUPE16_SHIFT                    (0U)
/*! WUPE16 - Wakeup Pin Enable For LLWU_P16
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE5_WUPE16(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE16_SHIFT)) & LLWU_PE5_WUPE16_MASK)

#define LLWU_PE5_WUPE17_MASK                     (0xCU)
#define LLWU_PE5_WUPE17_SHIFT                    (2U)
/*! WUPE17 - Wakeup Pin Enable For LLWU_P17
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE5_WUPE17(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE17_SHIFT)) & LLWU_PE5_WUPE17_MASK)

#define LLWU_PE5_WUPE18_MASK                     (0x30U)
#define LLWU_PE5_WUPE18_SHIFT                    (4U)
/*! WUPE18 - Wakeup Pin Enable For LLWU_P18
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE5_WUPE18(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE18_SHIFT)) & LLWU_PE5_WUPE18_MASK)

#define LLWU_PE5_WUPE19_MASK                     (0xC0U)
#define LLWU_PE5_WUPE19_SHIFT                    (6U)
/*! WUPE19 - Wakeup Pin Enable For LLWU_P19
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE5_WUPE19(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE5_WUPE19_SHIFT)) & LLWU_PE5_WUPE19_MASK)
/*! @} */

/*! @name PE6 - LLWU Pin Enable 6 register */
/*! @{ */

#define LLWU_PE6_WUPE20_MASK                     (0x3U)
#define LLWU_PE6_WUPE20_SHIFT                    (0U)
/*! WUPE20 - Wakeup Pin Enable For LLWU_P20
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE6_WUPE20(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE20_SHIFT)) & LLWU_PE6_WUPE20_MASK)

#define LLWU_PE6_WUPE21_MASK                     (0xCU)
#define LLWU_PE6_WUPE21_SHIFT                    (2U)
/*! WUPE21 - Wakeup Pin Enable For LLWU_P21
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE6_WUPE21(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE21_SHIFT)) & LLWU_PE6_WUPE21_MASK)

#define LLWU_PE6_WUPE22_MASK                     (0x30U)
#define LLWU_PE6_WUPE22_SHIFT                    (4U)
/*! WUPE22 - Wakeup Pin Enable For LLWU_P22
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE6_WUPE22(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE22_SHIFT)) & LLWU_PE6_WUPE22_MASK)

#define LLWU_PE6_WUPE23_MASK                     (0xC0U)
#define LLWU_PE6_WUPE23_SHIFT                    (6U)
/*! WUPE23 - Wakeup Pin Enable For LLWU_P23
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE6_WUPE23(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE6_WUPE23_SHIFT)) & LLWU_PE6_WUPE23_MASK)
/*! @} */

/*! @name PE7 - LLWU Pin Enable 7 register */
/*! @{ */

#define LLWU_PE7_WUPE24_MASK                     (0x3U)
#define LLWU_PE7_WUPE24_SHIFT                    (0U)
/*! WUPE24 - Wakeup Pin Enable For LLWU_P24
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE7_WUPE24(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE24_SHIFT)) & LLWU_PE7_WUPE24_MASK)

#define LLWU_PE7_WUPE25_MASK                     (0xCU)
#define LLWU_PE7_WUPE25_SHIFT                    (2U)
/*! WUPE25 - Wakeup Pin Enable For LLWU_P25
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE7_WUPE25(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE25_SHIFT)) & LLWU_PE7_WUPE25_MASK)

#define LLWU_PE7_WUPE26_MASK                     (0x30U)
#define LLWU_PE7_WUPE26_SHIFT                    (4U)
/*! WUPE26 - Wakeup Pin Enable For LLWU_P26
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE7_WUPE26(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE26_SHIFT)) & LLWU_PE7_WUPE26_MASK)

#define LLWU_PE7_WUPE27_MASK                     (0xC0U)
#define LLWU_PE7_WUPE27_SHIFT                    (6U)
/*! WUPE27 - Wakeup Pin Enable For LLWU_P27
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE7_WUPE27(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE7_WUPE27_SHIFT)) & LLWU_PE7_WUPE27_MASK)
/*! @} */

/*! @name PE8 - LLWU Pin Enable 8 register */
/*! @{ */

#define LLWU_PE8_WUPE28_MASK                     (0x3U)
#define LLWU_PE8_WUPE28_SHIFT                    (0U)
/*! WUPE28 - Wakeup Pin Enable For LLWU_P28
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE8_WUPE28(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE28_SHIFT)) & LLWU_PE8_WUPE28_MASK)

#define LLWU_PE8_WUPE29_MASK                     (0xCU)
#define LLWU_PE8_WUPE29_SHIFT                    (2U)
/*! WUPE29 - Wakeup Pin Enable For LLWU_P29
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE8_WUPE29(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE29_SHIFT)) & LLWU_PE8_WUPE29_MASK)

#define LLWU_PE8_WUPE30_MASK                     (0x30U)
#define LLWU_PE8_WUPE30_SHIFT                    (4U)
/*! WUPE30 - Wakeup Pin Enable For LLWU_P30
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE8_WUPE30(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE30_SHIFT)) & LLWU_PE8_WUPE30_MASK)

#define LLWU_PE8_WUPE31_MASK                     (0xC0U)
#define LLWU_PE8_WUPE31_SHIFT                    (6U)
/*! WUPE31 - Wakeup Pin Enable For LLWU_P31
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE8_WUPE31(x)                       (((uint8_t)(((uint8_t)(x)) << LLWU_PE8_WUPE31_SHIFT)) & LLWU_PE8_WUPE31_MASK)
/*! @} */

/*! @name ME - LLWU Module Enable register */
/*! @{ */

#define LLWU_ME_WUME0_MASK                       (0x1U)
#define LLWU_ME_WUME0_SHIFT                      (0U)
/*! WUME0 - Wakeup Module Enable For Module 0
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME0(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME0_SHIFT)) & LLWU_ME_WUME0_MASK)

#define LLWU_ME_WUME1_MASK                       (0x2U)
#define LLWU_ME_WUME1_SHIFT                      (1U)
/*! WUME1 - Wakeup Module Enable for Module 1
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME1(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME1_SHIFT)) & LLWU_ME_WUME1_MASK)

#define LLWU_ME_WUME2_MASK                       (0x4U)
#define LLWU_ME_WUME2_SHIFT                      (2U)
/*! WUME2 - Wakeup Module Enable For Module 2
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME2(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME2_SHIFT)) & LLWU_ME_WUME2_MASK)

#define LLWU_ME_WUME3_MASK                       (0x8U)
#define LLWU_ME_WUME3_SHIFT                      (3U)
/*! WUME3 - Wakeup Module Enable For Module 3
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME3(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME3_SHIFT)) & LLWU_ME_WUME3_MASK)

#define LLWU_ME_WUME4_MASK                       (0x10U)
#define LLWU_ME_WUME4_SHIFT                      (4U)
/*! WUME4 - Wakeup Module Enable For Module 4
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME4(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME4_SHIFT)) & LLWU_ME_WUME4_MASK)

#define LLWU_ME_WUME5_MASK                       (0x20U)
#define LLWU_ME_WUME5_SHIFT                      (5U)
/*! WUME5 - Wakeup Module Enable For Module 5
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME5(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME5_SHIFT)) & LLWU_ME_WUME5_MASK)

#define LLWU_ME_WUME6_MASK                       (0x40U)
#define LLWU_ME_WUME6_SHIFT                      (6U)
/*! WUME6 - Wakeup Module Enable For Module 6
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME6(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME6_SHIFT)) & LLWU_ME_WUME6_MASK)

#define LLWU_ME_WUME7_MASK                       (0x80U)
#define LLWU_ME_WUME7_SHIFT                      (7U)
/*! WUME7 - Wakeup Module Enable For Module 7
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME7(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_ME_WUME7_SHIFT)) & LLWU_ME_WUME7_MASK)
/*! @} */

/*! @name PF1 - LLWU Pin Flag 1 register */
/*! @{ */

#define LLWU_PF1_WUF0_MASK                       (0x1U)
#define LLWU_PF1_WUF0_SHIFT                      (0U)
/*! WUF0 - Wakeup Flag For LLWU_P0
 *  0b0..LLWU_P0 input was not a wakeup source
 *  0b1..LLWU_P0 input was a wakeup source
 */
#define LLWU_PF1_WUF0(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF0_SHIFT)) & LLWU_PF1_WUF0_MASK)

#define LLWU_PF1_WUF1_MASK                       (0x2U)
#define LLWU_PF1_WUF1_SHIFT                      (1U)
/*! WUF1 - Wakeup Flag For LLWU_P1
 *  0b0..LLWU_P1 input was not a wakeup source
 *  0b1..LLWU_P1 input was a wakeup source
 */
#define LLWU_PF1_WUF1(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF1_SHIFT)) & LLWU_PF1_WUF1_MASK)

#define LLWU_PF1_WUF2_MASK                       (0x4U)
#define LLWU_PF1_WUF2_SHIFT                      (2U)
/*! WUF2 - Wakeup Flag For LLWU_P2
 *  0b0..LLWU_P2 input was not a wakeup source
 *  0b1..LLWU_P2 input was a wakeup source
 */
#define LLWU_PF1_WUF2(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF2_SHIFT)) & LLWU_PF1_WUF2_MASK)

#define LLWU_PF1_WUF3_MASK                       (0x8U)
#define LLWU_PF1_WUF3_SHIFT                      (3U)
/*! WUF3 - Wakeup Flag For LLWU_P3
 *  0b0..LLWU_P3 input was not a wakeup source
 *  0b1..LLWU_P3 input was a wakeup source
 */
#define LLWU_PF1_WUF3(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF3_SHIFT)) & LLWU_PF1_WUF3_MASK)

#define LLWU_PF1_WUF4_MASK                       (0x10U)
#define LLWU_PF1_WUF4_SHIFT                      (4U)
/*! WUF4 - Wakeup Flag For LLWU_P4
 *  0b0..LLWU_P4 input was not a wakeup source
 *  0b1..LLWU_P4 input was a wakeup source
 */
#define LLWU_PF1_WUF4(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF4_SHIFT)) & LLWU_PF1_WUF4_MASK)

#define LLWU_PF1_WUF5_MASK                       (0x20U)
#define LLWU_PF1_WUF5_SHIFT                      (5U)
/*! WUF5 - Wakeup Flag For LLWU_P5
 *  0b0..LLWU_P5 input was not a wakeup source
 *  0b1..LLWU_P5 input was a wakeup source
 */
#define LLWU_PF1_WUF5(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF5_SHIFT)) & LLWU_PF1_WUF5_MASK)

#define LLWU_PF1_WUF6_MASK                       (0x40U)
#define LLWU_PF1_WUF6_SHIFT                      (6U)
/*! WUF6 - Wakeup Flag For LLWU_P6
 *  0b0..LLWU_P6 input was not a wakeup source
 *  0b1..LLWU_P6 input was a wakeup source
 */
#define LLWU_PF1_WUF6(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF6_SHIFT)) & LLWU_PF1_WUF6_MASK)

#define LLWU_PF1_WUF7_MASK                       (0x80U)
#define LLWU_PF1_WUF7_SHIFT                      (7U)
/*! WUF7 - Wakeup Flag For LLWU_P7
 *  0b0..LLWU_P7 input was not a wakeup source
 *  0b1..LLWU_P7 input was a wakeup source
 */
#define LLWU_PF1_WUF7(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF1_WUF7_SHIFT)) & LLWU_PF1_WUF7_MASK)
/*! @} */

/*! @name PF2 - LLWU Pin Flag 2 register */
/*! @{ */

#define LLWU_PF2_WUF8_MASK                       (0x1U)
#define LLWU_PF2_WUF8_SHIFT                      (0U)
/*! WUF8 - Wakeup Flag For LLWU_P8
 *  0b0..LLWU_P8 input was not a wakeup source
 *  0b1..LLWU_P8 input was a wakeup source
 */
#define LLWU_PF2_WUF8(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF8_SHIFT)) & LLWU_PF2_WUF8_MASK)

#define LLWU_PF2_WUF9_MASK                       (0x2U)
#define LLWU_PF2_WUF9_SHIFT                      (1U)
/*! WUF9 - Wakeup Flag For LLWU_P9
 *  0b0..LLWU_P9 input was not a wakeup source
 *  0b1..LLWU_P9 input was a wakeup source
 */
#define LLWU_PF2_WUF9(x)                         (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF9_SHIFT)) & LLWU_PF2_WUF9_MASK)

#define LLWU_PF2_WUF10_MASK                      (0x4U)
#define LLWU_PF2_WUF10_SHIFT                     (2U)
/*! WUF10 - Wakeup Flag For LLWU_P10
 *  0b0..LLWU_P10 input was not a wakeup source
 *  0b1..LLWU_P10 input was a wakeup source
 */
#define LLWU_PF2_WUF10(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF10_SHIFT)) & LLWU_PF2_WUF10_MASK)

#define LLWU_PF2_WUF11_MASK                      (0x8U)
#define LLWU_PF2_WUF11_SHIFT                     (3U)
/*! WUF11 - Wakeup Flag For LLWU_P11
 *  0b0..LLWU_P11 input was not a wakeup source
 *  0b1..LLWU_P11 input was a wakeup source
 */
#define LLWU_PF2_WUF11(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF11_SHIFT)) & LLWU_PF2_WUF11_MASK)

#define LLWU_PF2_WUF12_MASK                      (0x10U)
#define LLWU_PF2_WUF12_SHIFT                     (4U)
/*! WUF12 - Wakeup Flag For LLWU_P12
 *  0b0..LLWU_P12 input was not a wakeup source
 *  0b1..LLWU_P12 input was a wakeup source
 */
#define LLWU_PF2_WUF12(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF12_SHIFT)) & LLWU_PF2_WUF12_MASK)

#define LLWU_PF2_WUF13_MASK                      (0x20U)
#define LLWU_PF2_WUF13_SHIFT                     (5U)
/*! WUF13 - Wakeup Flag For LLWU_P13
 *  0b0..LLWU_P13 input was not a wakeup source
 *  0b1..LLWU_P13 input was a wakeup source
 */
#define LLWU_PF2_WUF13(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF13_SHIFT)) & LLWU_PF2_WUF13_MASK)

#define LLWU_PF2_WUF14_MASK                      (0x40U)
#define LLWU_PF2_WUF14_SHIFT                     (6U)
/*! WUF14 - Wakeup Flag For LLWU_P14
 *  0b0..LLWU_P14 input was not a wakeup source
 *  0b1..LLWU_P14 input was a wakeup source
 */
#define LLWU_PF2_WUF14(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF14_SHIFT)) & LLWU_PF2_WUF14_MASK)

#define LLWU_PF2_WUF15_MASK                      (0x80U)
#define LLWU_PF2_WUF15_SHIFT                     (7U)
/*! WUF15 - Wakeup Flag For LLWU_P15
 *  0b0..LLWU_P15 input was not a wakeup source
 *  0b1..LLWU_P15 input was a wakeup source
 */
#define LLWU_PF2_WUF15(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF2_WUF15_SHIFT)) & LLWU_PF2_WUF15_MASK)
/*! @} */

/*! @name PF3 - LLWU Pin Flag 3 register */
/*! @{ */

#define LLWU_PF3_WUF16_MASK                      (0x1U)
#define LLWU_PF3_WUF16_SHIFT                     (0U)
/*! WUF16 - Wakeup Flag For LLWU_P16
 *  0b0..LLWU_P16 input was not a wakeup source
 *  0b1..LLWU_P16 input was a wakeup source
 */
#define LLWU_PF3_WUF16(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF16_SHIFT)) & LLWU_PF3_WUF16_MASK)

#define LLWU_PF3_WUF17_MASK                      (0x2U)
#define LLWU_PF3_WUF17_SHIFT                     (1U)
/*! WUF17 - Wakeup Flag For LLWU_P17
 *  0b0..LLWU_P17 input was not a wakeup source
 *  0b1..LLWU_P17 input was a wakeup source
 */
#define LLWU_PF3_WUF17(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF17_SHIFT)) & LLWU_PF3_WUF17_MASK)

#define LLWU_PF3_WUF18_MASK                      (0x4U)
#define LLWU_PF3_WUF18_SHIFT                     (2U)
/*! WUF18 - Wakeup Flag For LLWU_P18
 *  0b0..LLWU_P18 input was not a wakeup source
 *  0b1..LLWU_P18 input was a wakeup source
 */
#define LLWU_PF3_WUF18(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF18_SHIFT)) & LLWU_PF3_WUF18_MASK)

#define LLWU_PF3_WUF19_MASK                      (0x8U)
#define LLWU_PF3_WUF19_SHIFT                     (3U)
/*! WUF19 - Wakeup Flag For LLWU_P19
 *  0b0..LLWU_P19 input was not a wakeup source
 *  0b1..LLWU_P19 input was a wakeup source
 */
#define LLWU_PF3_WUF19(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF19_SHIFT)) & LLWU_PF3_WUF19_MASK)

#define LLWU_PF3_WUF20_MASK                      (0x10U)
#define LLWU_PF3_WUF20_SHIFT                     (4U)
/*! WUF20 - Wakeup Flag For LLWU_P20
 *  0b0..LLWU_P20 input was not a wakeup source
 *  0b1..LLWU_P20 input was a wakeup source
 */
#define LLWU_PF3_WUF20(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF20_SHIFT)) & LLWU_PF3_WUF20_MASK)

#define LLWU_PF3_WUF21_MASK                      (0x20U)
#define LLWU_PF3_WUF21_SHIFT                     (5U)
/*! WUF21 - Wakeup Flag For LLWU_P21
 *  0b0..LLWU_P21 input was not a wakeup source
 *  0b1..LLWU_P21 input was a wakeup source
 */
#define LLWU_PF3_WUF21(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF21_SHIFT)) & LLWU_PF3_WUF21_MASK)

#define LLWU_PF3_WUF22_MASK                      (0x40U)
#define LLWU_PF3_WUF22_SHIFT                     (6U)
/*! WUF22 - Wakeup Flag For LLWU_P22
 *  0b0..LLWU_P22 input was not a wakeup source
 *  0b1..LLWU_P22 input was a wakeup source
 */
#define LLWU_PF3_WUF22(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF22_SHIFT)) & LLWU_PF3_WUF22_MASK)

#define LLWU_PF3_WUF23_MASK                      (0x80U)
#define LLWU_PF3_WUF23_SHIFT                     (7U)
/*! WUF23 - Wakeup Flag For LLWU_P23
 *  0b0..LLWU_P23 input was not a wakeup source
 *  0b1..LLWU_P23 input was a wakeup source
 */
#define LLWU_PF3_WUF23(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF3_WUF23_SHIFT)) & LLWU_PF3_WUF23_MASK)
/*! @} */

/*! @name PF4 - LLWU Pin Flag 4 register */
/*! @{ */

#define LLWU_PF4_WUF24_MASK                      (0x1U)
#define LLWU_PF4_WUF24_SHIFT                     (0U)
/*! WUF24 - Wakeup Flag For LLWU_P24
 *  0b0..LLWU_P24 input was not a wakeup source
 *  0b1..LLWU_P24 input was a wakeup source
 */
#define LLWU_PF4_WUF24(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF24_SHIFT)) & LLWU_PF4_WUF24_MASK)

#define LLWU_PF4_WUF25_MASK                      (0x2U)
#define LLWU_PF4_WUF25_SHIFT                     (1U)
/*! WUF25 - Wakeup Flag For LLWU_P25
 *  0b0..LLWU_P25 input was not a wakeup source
 *  0b1..LLWU_P25 input was a wakeup source
 */
#define LLWU_PF4_WUF25(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF25_SHIFT)) & LLWU_PF4_WUF25_MASK)

#define LLWU_PF4_WUF26_MASK                      (0x4U)
#define LLWU_PF4_WUF26_SHIFT                     (2U)
/*! WUF26 - Wakeup Flag For LLWU_P26
 *  0b0..LLWU_P26 input was not a wakeup source
 *  0b1..LLWU_P26 input was a wakeup source
 */
#define LLWU_PF4_WUF26(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF26_SHIFT)) & LLWU_PF4_WUF26_MASK)

#define LLWU_PF4_WUF27_MASK                      (0x8U)
#define LLWU_PF4_WUF27_SHIFT                     (3U)
/*! WUF27 - Wakeup Flag For LLWU_P27
 *  0b0..LLWU_P27 input was not a wakeup source
 *  0b1..LLWU_P27 input was a wakeup source
 */
#define LLWU_PF4_WUF27(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF27_SHIFT)) & LLWU_PF4_WUF27_MASK)

#define LLWU_PF4_WUF28_MASK                      (0x10U)
#define LLWU_PF4_WUF28_SHIFT                     (4U)
/*! WUF28 - Wakeup Flag For LLWU_P28
 *  0b0..LLWU_P28 input was not a wakeup source
 *  0b1..LLWU_P28 input was a wakeup source
 */
#define LLWU_PF4_WUF28(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF28_SHIFT)) & LLWU_PF4_WUF28_MASK)

#define LLWU_PF4_WUF29_MASK                      (0x20U)
#define LLWU_PF4_WUF29_SHIFT                     (5U)
/*! WUF29 - Wakeup Flag For LLWU_P29
 *  0b0..LLWU_P29 input was not a wakeup source
 *  0b1..LLWU_P29 input was a wakeup source
 */
#define LLWU_PF4_WUF29(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF29_SHIFT)) & LLWU_PF4_WUF29_MASK)

#define LLWU_PF4_WUF30_MASK                      (0x40U)
#define LLWU_PF4_WUF30_SHIFT                     (6U)
/*! WUF30 - Wakeup Flag For LLWU_P30
 *  0b0..LLWU_P30 input was not a wakeup source
 *  0b1..LLWU_P30 input was a wakeup source
 */
#define LLWU_PF4_WUF30(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF30_SHIFT)) & LLWU_PF4_WUF30_MASK)

#define LLWU_PF4_WUF31_MASK                      (0x80U)
#define LLWU_PF4_WUF31_SHIFT                     (7U)
/*! WUF31 - Wakeup Flag For LLWU_P31
 *  0b0..LLWU_P31 input was not a wakeup source
 *  0b1..LLWU_P31 input was a wakeup source
 */
#define LLWU_PF4_WUF31(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_PF4_WUF31_SHIFT)) & LLWU_PF4_WUF31_MASK)
/*! @} */

/*! @name MF5 - LLWU Module Flag 5 register */
/*! @{ */

#define LLWU_MF5_MWUF0_MASK                      (0x1U)
#define LLWU_MF5_MWUF0_SHIFT                     (0U)
/*! MWUF0 - Wakeup flag For module 0
 *  0b0..Module 0 input was not a wakeup source
 *  0b1..Module 0 input was a wakeup source
 */
#define LLWU_MF5_MWUF0(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF0_SHIFT)) & LLWU_MF5_MWUF0_MASK)

#define LLWU_MF5_MWUF1_MASK                      (0x2U)
#define LLWU_MF5_MWUF1_SHIFT                     (1U)
/*! MWUF1 - Wakeup flag For module 1
 *  0b0..Module 1 input was not a wakeup source
 *  0b1..Module 1 input was a wakeup source
 */
#define LLWU_MF5_MWUF1(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF1_SHIFT)) & LLWU_MF5_MWUF1_MASK)

#define LLWU_MF5_MWUF2_MASK                      (0x4U)
#define LLWU_MF5_MWUF2_SHIFT                     (2U)
/*! MWUF2 - Wakeup flag For module 2
 *  0b0..Module 2 input was not a wakeup source
 *  0b1..Module 2 input was a wakeup source
 */
#define LLWU_MF5_MWUF2(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF2_SHIFT)) & LLWU_MF5_MWUF2_MASK)

#define LLWU_MF5_MWUF3_MASK                      (0x8U)
#define LLWU_MF5_MWUF3_SHIFT                     (3U)
/*! MWUF3 - Wakeup flag For module 3
 *  0b0..Module 3 input was not a wakeup source
 *  0b1..Module 3 input was a wakeup source
 */
#define LLWU_MF5_MWUF3(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF3_SHIFT)) & LLWU_MF5_MWUF3_MASK)

#define LLWU_MF5_MWUF4_MASK                      (0x10U)
#define LLWU_MF5_MWUF4_SHIFT                     (4U)
/*! MWUF4 - Wakeup flag For module 4
 *  0b0..Module 4 input was not a wakeup source
 *  0b1..Module 4 input was a wakeup source
 */
#define LLWU_MF5_MWUF4(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF4_SHIFT)) & LLWU_MF5_MWUF4_MASK)

#define LLWU_MF5_MWUF5_MASK                      (0x20U)
#define LLWU_MF5_MWUF5_SHIFT                     (5U)
/*! MWUF5 - Wakeup flag For module 5
 *  0b0..Module 5 input was not a wakeup source
 *  0b1..Module 5 input was a wakeup source
 */
#define LLWU_MF5_MWUF5(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF5_SHIFT)) & LLWU_MF5_MWUF5_MASK)

#define LLWU_MF5_MWUF6_MASK                      (0x40U)
#define LLWU_MF5_MWUF6_SHIFT                     (6U)
/*! MWUF6 - Wakeup flag For module 6
 *  0b0..Module 6 input was not a wakeup source
 *  0b1..Module 6 input was a wakeup source
 */
#define LLWU_MF5_MWUF6(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF6_SHIFT)) & LLWU_MF5_MWUF6_MASK)

#define LLWU_MF5_MWUF7_MASK                      (0x80U)
#define LLWU_MF5_MWUF7_SHIFT                     (7U)
/*! MWUF7 - Wakeup flag For module 7
 *  0b0..Module 7 input was not a wakeup source
 *  0b1..Module 7 input was a wakeup source
 */
#define LLWU_MF5_MWUF7(x)                        (((uint8_t)(((uint8_t)(x)) << LLWU_MF5_MWUF7_SHIFT)) & LLWU_MF5_MWUF7_MASK)
/*! @} */

/*! @name FILT1 - LLWU Pin Filter 1 register */
/*! @{ */

#define LLWU_FILT1_FILTSEL_MASK                  (0x1FU)
#define LLWU_FILT1_FILTSEL_SHIFT                 (0U)
/*! FILTSEL - Filter Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT1_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTSEL_SHIFT)) & LLWU_FILT1_FILTSEL_MASK)

#define LLWU_FILT1_FILTE_MASK                    (0x60U)
#define LLWU_FILT1_FILTE_SHIFT                   (5U)
/*! FILTE - Digital Filter On External Pin
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
 */
#define LLWU_FILT1_FILTE(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTE_SHIFT)) & LLWU_FILT1_FILTE_MASK)

#define LLWU_FILT1_FILTF_MASK                    (0x80U)
#define LLWU_FILT1_FILTF_SHIFT                   (7U)
/*! FILTF - Filter Detect Flag
 *  0b0..Pin Filter 1 was not a wakeup source
 *  0b1..Pin Filter 1 was a wakeup source
 */
#define LLWU_FILT1_FILTF(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT1_FILTF_SHIFT)) & LLWU_FILT1_FILTF_MASK)
/*! @} */

/*! @name FILT2 - LLWU Pin Filter 2 register */
/*! @{ */

#define LLWU_FILT2_FILTSEL_MASK                  (0x1FU)
#define LLWU_FILT2_FILTSEL_SHIFT                 (0U)
/*! FILTSEL - Filter Pin Select
 *  0b00000..Select LLWU_P0 for filter
 *  0b11111..Select LLWU_P31 for filter
 */
#define LLWU_FILT2_FILTSEL(x)                    (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTSEL_SHIFT)) & LLWU_FILT2_FILTSEL_MASK)

#define LLWU_FILT2_FILTE_MASK                    (0x60U)
#define LLWU_FILT2_FILTE_SHIFT                   (5U)
/*! FILTE - Digital Filter On External Pin
 *  0b00..Filter disabled
 *  0b01..Filter posedge detect enabled
 *  0b10..Filter negedge detect enabled
 *  0b11..Filter any edge detect enabled
 */
#define LLWU_FILT2_FILTE(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTE_SHIFT)) & LLWU_FILT2_FILTE_MASK)

#define LLWU_FILT2_FILTF_MASK                    (0x80U)
#define LLWU_FILT2_FILTF_SHIFT                   (7U)
/*! FILTF - Filter Detect Flag
 *  0b0..Pin Filter 2 was not a wakeup source
 *  0b1..Pin Filter 2 was a wakeup source
 */
#define LLWU_FILT2_FILTF(x)                      (((uint8_t)(((uint8_t)(x)) << LLWU_FILT2_FILTF_SHIFT)) & LLWU_FILT2_FILTF_MASK)
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

