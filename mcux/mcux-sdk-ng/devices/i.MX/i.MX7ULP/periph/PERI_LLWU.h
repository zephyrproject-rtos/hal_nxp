/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
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
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LLWU.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LLWU
 *
 * CMSIS Peripheral Access Layer for LLWU
 */

#if !defined(PERI_LLWU_H_)
#define PERI_LLWU_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
  __I  uint32_t PE2;                               /**< Pin Enable 2 register, offset: 0xC */
       uint8_t RESERVED_0[8];
  __IO uint32_t ME;                                /**< Module Interrupt Enable register, offset: 0x18 */
  __I  uint32_t DE;                                /**< Module DMA/Trigger Enable register, offset: 0x1C */
  __IO uint32_t PF;                                /**< Pin Flag register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __I  uint32_t MF;                                /**< Module Interrupt Flag register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t FILT;                              /**< Pin Filter register, offset: 0x30 */
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

/*! @name PE1 - Pin Enable 1 register */
/*! @{ */

#define LLWU_PE1_WUPE0_MASK                      (0x3U)
#define LLWU_PE1_WUPE0_SHIFT                     (0U)
/*! WUPE0 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE0(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE0_SHIFT)) & LLWU_PE1_WUPE0_MASK)

#define LLWU_PE1_WUPE1_MASK                      (0xCU)
#define LLWU_PE1_WUPE1_SHIFT                     (2U)
/*! WUPE1 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE1(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE1_SHIFT)) & LLWU_PE1_WUPE1_MASK)

#define LLWU_PE1_WUPE2_MASK                      (0x30U)
#define LLWU_PE1_WUPE2_SHIFT                     (4U)
/*! WUPE2 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE2(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE2_SHIFT)) & LLWU_PE1_WUPE2_MASK)

#define LLWU_PE1_WUPE3_MASK                      (0xC0U)
#define LLWU_PE1_WUPE3_SHIFT                     (6U)
/*! WUPE3 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE3(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE3_SHIFT)) & LLWU_PE1_WUPE3_MASK)

#define LLWU_PE1_WUPE4_MASK                      (0x300U)
#define LLWU_PE1_WUPE4_SHIFT                     (8U)
/*! WUPE4 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE4(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE4_SHIFT)) & LLWU_PE1_WUPE4_MASK)

#define LLWU_PE1_WUPE5_MASK                      (0xC00U)
#define LLWU_PE1_WUPE5_SHIFT                     (10U)
/*! WUPE5 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE5(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE5_SHIFT)) & LLWU_PE1_WUPE5_MASK)

#define LLWU_PE1_WUPE6_MASK                      (0x3000U)
#define LLWU_PE1_WUPE6_SHIFT                     (12U)
/*! WUPE6 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE6(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE6_SHIFT)) & LLWU_PE1_WUPE6_MASK)

#define LLWU_PE1_WUPE7_MASK                      (0xC000U)
#define LLWU_PE1_WUPE7_SHIFT                     (14U)
/*! WUPE7 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE7(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE7_SHIFT)) & LLWU_PE1_WUPE7_MASK)

#define LLWU_PE1_WUPE8_MASK                      (0x30000U)
#define LLWU_PE1_WUPE8_SHIFT                     (16U)
/*! WUPE8 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE8(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE8_SHIFT)) & LLWU_PE1_WUPE8_MASK)

#define LLWU_PE1_WUPE9_MASK                      (0xC0000U)
#define LLWU_PE1_WUPE9_SHIFT                     (18U)
/*! WUPE9 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE9(x)                        (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE9_SHIFT)) & LLWU_PE1_WUPE9_MASK)

#define LLWU_PE1_WUPE10_MASK                     (0x300000U)
#define LLWU_PE1_WUPE10_SHIFT                    (20U)
/*! WUPE10 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE10(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE10_SHIFT)) & LLWU_PE1_WUPE10_MASK)

#define LLWU_PE1_WUPE11_MASK                     (0xC00000U)
#define LLWU_PE1_WUPE11_SHIFT                    (22U)
/*! WUPE11 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE11(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE11_SHIFT)) & LLWU_PE1_WUPE11_MASK)

#define LLWU_PE1_WUPE12_MASK                     (0x3000000U)
#define LLWU_PE1_WUPE12_SHIFT                    (24U)
/*! WUPE12 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE12(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE12_SHIFT)) & LLWU_PE1_WUPE12_MASK)

#define LLWU_PE1_WUPE13_MASK                     (0xC000000U)
#define LLWU_PE1_WUPE13_SHIFT                    (26U)
/*! WUPE13 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE13(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE13_SHIFT)) & LLWU_PE1_WUPE13_MASK)

#define LLWU_PE1_WUPE14_MASK                     (0x30000000U)
#define LLWU_PE1_WUPE14_SHIFT                    (28U)
/*! WUPE14 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE14(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE14_SHIFT)) & LLWU_PE1_WUPE14_MASK)

#define LLWU_PE1_WUPE15_MASK                     (0xC0000000U)
#define LLWU_PE1_WUPE15_SHIFT                    (30U)
/*! WUPE15 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE1_WUPE15(x)                       (((uint32_t)(((uint32_t)(x)) << LLWU_PE1_WUPE15_SHIFT)) & LLWU_PE1_WUPE15_MASK)
/*! @} */

/*! @name PE2 - Pin Enable 2 register */
/*! @{ */

#define LLWU_PE2_Reserved16_MASK                 (0x3U)
#define LLWU_PE2_Reserved16_SHIFT                (0U)
/*! Reserved16 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved16(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved16_SHIFT)) & LLWU_PE2_Reserved16_MASK)

#define LLWU_PE2_Reserved17_MASK                 (0xCU)
#define LLWU_PE2_Reserved17_SHIFT                (2U)
/*! Reserved17 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved17(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved17_SHIFT)) & LLWU_PE2_Reserved17_MASK)

#define LLWU_PE2_Reserved18_MASK                 (0x30U)
#define LLWU_PE2_Reserved18_SHIFT                (4U)
/*! Reserved18 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved18(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved18_SHIFT)) & LLWU_PE2_Reserved18_MASK)

#define LLWU_PE2_Reserved19_MASK                 (0xC0U)
#define LLWU_PE2_Reserved19_SHIFT                (6U)
/*! Reserved19 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved19(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved19_SHIFT)) & LLWU_PE2_Reserved19_MASK)

#define LLWU_PE2_Reserved20_MASK                 (0x300U)
#define LLWU_PE2_Reserved20_SHIFT                (8U)
/*! Reserved20 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved20(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved20_SHIFT)) & LLWU_PE2_Reserved20_MASK)

#define LLWU_PE2_Reserved21_MASK                 (0xC00U)
#define LLWU_PE2_Reserved21_SHIFT                (10U)
/*! Reserved21 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved21(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved21_SHIFT)) & LLWU_PE2_Reserved21_MASK)

#define LLWU_PE2_Reserved22_MASK                 (0x3000U)
#define LLWU_PE2_Reserved22_SHIFT                (12U)
/*! Reserved22 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved22(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved22_SHIFT)) & LLWU_PE2_Reserved22_MASK)

#define LLWU_PE2_Reserved23_MASK                 (0xC000U)
#define LLWU_PE2_Reserved23_SHIFT                (14U)
/*! Reserved23 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved23(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved23_SHIFT)) & LLWU_PE2_Reserved23_MASK)

#define LLWU_PE2_Reserved24_MASK                 (0x30000U)
#define LLWU_PE2_Reserved24_SHIFT                (16U)
/*! Reserved24 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved24(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved24_SHIFT)) & LLWU_PE2_Reserved24_MASK)

#define LLWU_PE2_Reserved25_MASK                 (0xC0000U)
#define LLWU_PE2_Reserved25_SHIFT                (18U)
/*! Reserved25 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved25(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved25_SHIFT)) & LLWU_PE2_Reserved25_MASK)

#define LLWU_PE2_Reserved26_MASK                 (0x300000U)
#define LLWU_PE2_Reserved26_SHIFT                (20U)
/*! Reserved26 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved26(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved26_SHIFT)) & LLWU_PE2_Reserved26_MASK)

#define LLWU_PE2_Reserved27_MASK                 (0xC00000U)
#define LLWU_PE2_Reserved27_SHIFT                (22U)
/*! Reserved27 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved27(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved27_SHIFT)) & LLWU_PE2_Reserved27_MASK)

#define LLWU_PE2_Reserved28_MASK                 (0x3000000U)
#define LLWU_PE2_Reserved28_SHIFT                (24U)
/*! Reserved28 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved28(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved28_SHIFT)) & LLWU_PE2_Reserved28_MASK)

#define LLWU_PE2_Reserved29_MASK                 (0xC000000U)
#define LLWU_PE2_Reserved29_SHIFT                (26U)
/*! Reserved29 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved29(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved29_SHIFT)) & LLWU_PE2_Reserved29_MASK)

#define LLWU_PE2_Reserved30_MASK                 (0x30000000U)
#define LLWU_PE2_Reserved30_SHIFT                (28U)
/*! Reserved30 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved30(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved30_SHIFT)) & LLWU_PE2_Reserved30_MASK)

#define LLWU_PE2_Reserved31_MASK                 (0xC0000000U)
#define LLWU_PE2_Reserved31_SHIFT                (30U)
/*! Reserved31 - Wakeup pin enable for LLWU_Pn
 *  0b00..External input pin disabled as wakeup input
 *  0b01..External input pin enabled with rising edge detection
 *  0b10..External input pin enabled with falling edge detection
 *  0b11..External input pin enabled with any change detection
 */
#define LLWU_PE2_Reserved31(x)                   (((uint32_t)(((uint32_t)(x)) << LLWU_PE2_Reserved31_SHIFT)) & LLWU_PE2_Reserved31_MASK)
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

#define LLWU_ME_WUME3_MASK                       (0x8U)
#define LLWU_ME_WUME3_SHIFT                      (3U)
/*! WUME3 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME3_SHIFT)) & LLWU_ME_WUME3_MASK)

#define LLWU_ME_WUME4_MASK                       (0x10U)
#define LLWU_ME_WUME4_SHIFT                      (4U)
/*! WUME4 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME4_SHIFT)) & LLWU_ME_WUME4_MASK)

#define LLWU_ME_Reserved5_MASK                   (0x20U)
#define LLWU_ME_Reserved5_SHIFT                  (5U)
/*! Reserved5 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_Reserved5(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_ME_Reserved5_SHIFT)) & LLWU_ME_Reserved5_MASK)

#define LLWU_ME_WUME6_MASK                       (0x40U)
#define LLWU_ME_WUME6_SHIFT                      (6U)
/*! WUME6 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_WUME6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_ME_WUME6_SHIFT)) & LLWU_ME_WUME6_MASK)

#define LLWU_ME_Reserved7_MASK                   (0x80U)
#define LLWU_ME_Reserved7_SHIFT                  (7U)
/*! Reserved7 - Wakeup module enable for module n
 *  0b0..Internal module flag not used as wakeup source
 *  0b1..Internal module flag used as wakeup source
 */
#define LLWU_ME_Reserved7(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_ME_Reserved7_SHIFT)) & LLWU_ME_Reserved7_MASK)
/*! @} */

/*! @name DE - Module DMA/Trigger Enable register */
/*! @{ */

#define LLWU_DE_Reserved0_MASK                   (0x1U)
#define LLWU_DE_Reserved0_SHIFT                  (0U)
/*! Reserved0 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved0(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved0_SHIFT)) & LLWU_DE_Reserved0_MASK)

#define LLWU_DE_Reserved1_MASK                   (0x2U)
#define LLWU_DE_Reserved1_SHIFT                  (1U)
/*! Reserved1 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved1(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved1_SHIFT)) & LLWU_DE_Reserved1_MASK)

#define LLWU_DE_Reserved2_MASK                   (0x4U)
#define LLWU_DE_Reserved2_SHIFT                  (2U)
/*! Reserved2 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved2(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved2_SHIFT)) & LLWU_DE_Reserved2_MASK)

#define LLWU_DE_Reserved3_MASK                   (0x8U)
#define LLWU_DE_Reserved3_SHIFT                  (3U)
/*! Reserved3 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved3(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved3_SHIFT)) & LLWU_DE_Reserved3_MASK)

#define LLWU_DE_Reserved4_MASK                   (0x10U)
#define LLWU_DE_Reserved4_SHIFT                  (4U)
/*! Reserved4 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved4(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved4_SHIFT)) & LLWU_DE_Reserved4_MASK)

#define LLWU_DE_Reserved5_MASK                   (0x20U)
#define LLWU_DE_Reserved5_SHIFT                  (5U)
/*! Reserved5 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved5(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved5_SHIFT)) & LLWU_DE_Reserved5_MASK)

#define LLWU_DE_Reserved6_MASK                   (0x40U)
#define LLWU_DE_Reserved6_SHIFT                  (6U)
/*! Reserved6 - DMA/Trigger wakeup enable for module n
 *  0b0..Internal module request not enabled as a DMA/Trigger wakeup source
 *  0b1..Internal module request enabled as a DMA/Trigger wakeup source
 */
#define LLWU_DE_Reserved6(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_DE_Reserved6_SHIFT)) & LLWU_DE_Reserved6_MASK)

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

#define LLWU_PF_Reserved16_MASK                  (0x10000U)
#define LLWU_PF_Reserved16_SHIFT                 (16U)
/*! Reserved16 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved16(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved16_SHIFT)) & LLWU_PF_Reserved16_MASK)

#define LLWU_PF_Reserved17_MASK                  (0x20000U)
#define LLWU_PF_Reserved17_SHIFT                 (17U)
/*! Reserved17 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved17(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved17_SHIFT)) & LLWU_PF_Reserved17_MASK)

#define LLWU_PF_Reserved18_MASK                  (0x40000U)
#define LLWU_PF_Reserved18_SHIFT                 (18U)
/*! Reserved18 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved18(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved18_SHIFT)) & LLWU_PF_Reserved18_MASK)

#define LLWU_PF_Reserved19_MASK                  (0x80000U)
#define LLWU_PF_Reserved19_SHIFT                 (19U)
/*! Reserved19 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved19(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved19_SHIFT)) & LLWU_PF_Reserved19_MASK)

#define LLWU_PF_Reserved20_MASK                  (0x100000U)
#define LLWU_PF_Reserved20_SHIFT                 (20U)
/*! Reserved20 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved20(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved20_SHIFT)) & LLWU_PF_Reserved20_MASK)

#define LLWU_PF_Reserved21_MASK                  (0x200000U)
#define LLWU_PF_Reserved21_SHIFT                 (21U)
/*! Reserved21 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved21(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved21_SHIFT)) & LLWU_PF_Reserved21_MASK)

#define LLWU_PF_Reserved22_MASK                  (0x400000U)
#define LLWU_PF_Reserved22_SHIFT                 (22U)
/*! Reserved22 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved22(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved22_SHIFT)) & LLWU_PF_Reserved22_MASK)

#define LLWU_PF_Reserved23_MASK                  (0x800000U)
#define LLWU_PF_Reserved23_SHIFT                 (23U)
/*! Reserved23 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved23(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved23_SHIFT)) & LLWU_PF_Reserved23_MASK)

#define LLWU_PF_Reserved24_MASK                  (0x1000000U)
#define LLWU_PF_Reserved24_SHIFT                 (24U)
/*! Reserved24 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved24(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved24_SHIFT)) & LLWU_PF_Reserved24_MASK)

#define LLWU_PF_Reserved25_MASK                  (0x2000000U)
#define LLWU_PF_Reserved25_SHIFT                 (25U)
/*! Reserved25 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved25(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved25_SHIFT)) & LLWU_PF_Reserved25_MASK)

#define LLWU_PF_Reserved26_MASK                  (0x4000000U)
#define LLWU_PF_Reserved26_SHIFT                 (26U)
/*! Reserved26 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved26(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved26_SHIFT)) & LLWU_PF_Reserved26_MASK)

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

#define LLWU_PF_Reserved29_MASK                  (0x20000000U)
#define LLWU_PF_Reserved29_SHIFT                 (29U)
/*! Reserved29 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved29(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved29_SHIFT)) & LLWU_PF_Reserved29_MASK)

#define LLWU_PF_Reserved30_MASK                  (0x40000000U)
#define LLWU_PF_Reserved30_SHIFT                 (30U)
/*! Reserved30 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved30(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved30_SHIFT)) & LLWU_PF_Reserved30_MASK)

#define LLWU_PF_Reserved31_MASK                  (0x80000000U)
#define LLWU_PF_Reserved31_SHIFT                 (31U)
/*! Reserved31 - Wakeup flag for LLWU_Pn
 *  0b0..LLWU_Pn input was not a wakeup source
 *  0b1..LLWU_Pn input was a wakeup source
 */
#define LLWU_PF_Reserved31(x)                    (((uint32_t)(((uint32_t)(x)) << LLWU_PF_Reserved31_SHIFT)) & LLWU_PF_Reserved31_MASK)
/*! @} */

/*! @name MF - Module Interrupt Flag register */
/*! @{ */

#define LLWU_MF_MWUF0_MASK                       (0x1U)
#define LLWU_MF_MWUF0_SHIFT                      (0U)
/*! MWUF0 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF0(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF0_SHIFT)) & LLWU_MF_MWUF0_MASK)

#define LLWU_MF_MWUF1_MASK                       (0x2U)
#define LLWU_MF_MWUF1_SHIFT                      (1U)
/*! MWUF1 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF1(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF1_SHIFT)) & LLWU_MF_MWUF1_MASK)

#define LLWU_MF_MWUF2_MASK                       (0x4U)
#define LLWU_MF_MWUF2_SHIFT                      (2U)
/*! MWUF2 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF2(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF2_SHIFT)) & LLWU_MF_MWUF2_MASK)

#define LLWU_MF_MWUF3_MASK                       (0x8U)
#define LLWU_MF_MWUF3_SHIFT                      (3U)
/*! MWUF3 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF3(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF3_SHIFT)) & LLWU_MF_MWUF3_MASK)

#define LLWU_MF_MWUF4_MASK                       (0x10U)
#define LLWU_MF_MWUF4_SHIFT                      (4U)
/*! MWUF4 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF4(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF4_SHIFT)) & LLWU_MF_MWUF4_MASK)

#define LLWU_MF_Reserved5_MASK                   (0x20U)
#define LLWU_MF_Reserved5_SHIFT                  (5U)
/*! Reserved5 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_Reserved5(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_MF_Reserved5_SHIFT)) & LLWU_MF_Reserved5_MASK)

#define LLWU_MF_MWUF6_MASK                       (0x40U)
#define LLWU_MF_MWUF6_SHIFT                      (6U)
/*! MWUF6 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_MWUF6(x)                         (((uint32_t)(((uint32_t)(x)) << LLWU_MF_MWUF6_SHIFT)) & LLWU_MF_MWUF6_MASK)

#define LLWU_MF_Reserved7_MASK                   (0x80U)
#define LLWU_MF_Reserved7_SHIFT                  (7U)
/*! Reserved7 - Wakeup flag for module n
 *  0b0..Module input was not a wakeup source
 *  0b1..Module input was a wakeup source
 */
#define LLWU_MF_Reserved7(x)                     (((uint32_t)(((uint32_t)(x)) << LLWU_MF_Reserved7_SHIFT)) & LLWU_MF_Reserved7_MASK)
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
 *  0b0..Pin Filter 2 was not a wakeup source
 *  0b1..Pin Filter 2 was a wakeup source
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

