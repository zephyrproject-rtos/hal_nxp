/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GPIO
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPIO.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPIO
 *
 * CMSIS Peripheral Access Layer for GPIO
 */

#if !defined(PERI_GPIO_H_)
#define PERI_GPIO_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t DR;                                /**< GPIO data register, offset: 0x0 */
  __IO uint32_t GDIR;                              /**< GPIO direction register, offset: 0x4 */
  __I  uint32_t PSR;                               /**< GPIO pad status register, offset: 0x8 */
  __IO uint32_t ICR1;                              /**< GPIO interrupt configuration register1, offset: 0xC */
  __IO uint32_t ICR2;                              /**< GPIO interrupt configuration register2, offset: 0x10 */
  __IO uint32_t IMR;                               /**< GPIO interrupt mask register, offset: 0x14 */
  __IO uint32_t ISR;                               /**< GPIO interrupt status register, offset: 0x18 */
  __IO uint32_t EDGE_SEL;                          /**< GPIO edge select register, offset: 0x1C */
} GPIO_Type;

/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name DR - GPIO data register */
/*! @{ */

#define GPIO_DR_DR_MASK                          (0xFFFFFFFFU)
#define GPIO_DR_DR_SHIFT                         (0U)
#define GPIO_DR_DR(x)                            (((uint32_t)(((uint32_t)(x)) << GPIO_DR_DR_SHIFT)) & GPIO_DR_DR_MASK)
/*! @} */

/*! @name GDIR - GPIO direction register */
/*! @{ */

#define GPIO_GDIR_GDIR_MASK                      (0xFFFFFFFFU)
#define GPIO_GDIR_GDIR_SHIFT                     (0U)
/*! GDIR
 *  0b00000000000000000000000000000000..GPIO is configured as input.
 *  0b00000000000000000000000000000001..GPIO is configured as output.
 */
#define GPIO_GDIR_GDIR(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_GDIR_GDIR_SHIFT)) & GPIO_GDIR_GDIR_MASK)
/*! @} */

/*! @name PSR - GPIO pad status register */
/*! @{ */

#define GPIO_PSR_PSR_MASK                        (0xFFFFFFFFU)
#define GPIO_PSR_PSR_SHIFT                       (0U)
#define GPIO_PSR_PSR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_PSR_PSR_SHIFT)) & GPIO_PSR_PSR_MASK)
/*! @} */

/*! @name ICR1 - GPIO interrupt configuration register1 */
/*! @{ */

#define GPIO_ICR1_ICR0_MASK                      (0x3U)
#define GPIO_ICR1_ICR0_SHIFT                     (0U)
/*! ICR0
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR0_SHIFT)) & GPIO_ICR1_ICR0_MASK)

#define GPIO_ICR1_ICR1_MASK                      (0xCU)
#define GPIO_ICR1_ICR1_SHIFT                     (2U)
/*! ICR1
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR1_SHIFT)) & GPIO_ICR1_ICR1_MASK)

#define GPIO_ICR1_ICR2_MASK                      (0x30U)
#define GPIO_ICR1_ICR2_SHIFT                     (4U)
/*! ICR2
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR2_SHIFT)) & GPIO_ICR1_ICR2_MASK)

#define GPIO_ICR1_ICR3_MASK                      (0xC0U)
#define GPIO_ICR1_ICR3_SHIFT                     (6U)
/*! ICR3
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR3_SHIFT)) & GPIO_ICR1_ICR3_MASK)

#define GPIO_ICR1_ICR4_MASK                      (0x300U)
#define GPIO_ICR1_ICR4_SHIFT                     (8U)
/*! ICR4
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR4_SHIFT)) & GPIO_ICR1_ICR4_MASK)

#define GPIO_ICR1_ICR5_MASK                      (0xC00U)
#define GPIO_ICR1_ICR5_SHIFT                     (10U)
/*! ICR5
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR5_SHIFT)) & GPIO_ICR1_ICR5_MASK)

#define GPIO_ICR1_ICR6_MASK                      (0x3000U)
#define GPIO_ICR1_ICR6_SHIFT                     (12U)
/*! ICR6
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR6_SHIFT)) & GPIO_ICR1_ICR6_MASK)

#define GPIO_ICR1_ICR7_MASK                      (0xC000U)
#define GPIO_ICR1_ICR7_SHIFT                     (14U)
/*! ICR7
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR7_SHIFT)) & GPIO_ICR1_ICR7_MASK)

#define GPIO_ICR1_ICR8_MASK                      (0x30000U)
#define GPIO_ICR1_ICR8_SHIFT                     (16U)
/*! ICR8
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR8_SHIFT)) & GPIO_ICR1_ICR8_MASK)

#define GPIO_ICR1_ICR9_MASK                      (0xC0000U)
#define GPIO_ICR1_ICR9_SHIFT                     (18U)
/*! ICR9
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR9_SHIFT)) & GPIO_ICR1_ICR9_MASK)

#define GPIO_ICR1_ICR10_MASK                     (0x300000U)
#define GPIO_ICR1_ICR10_SHIFT                    (20U)
/*! ICR10
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR10_SHIFT)) & GPIO_ICR1_ICR10_MASK)

#define GPIO_ICR1_ICR11_MASK                     (0xC00000U)
#define GPIO_ICR1_ICR11_SHIFT                    (22U)
/*! ICR11
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR11_SHIFT)) & GPIO_ICR1_ICR11_MASK)

#define GPIO_ICR1_ICR12_MASK                     (0x3000000U)
#define GPIO_ICR1_ICR12_SHIFT                    (24U)
/*! ICR12
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR12_SHIFT)) & GPIO_ICR1_ICR12_MASK)

#define GPIO_ICR1_ICR13_MASK                     (0xC000000U)
#define GPIO_ICR1_ICR13_SHIFT                    (26U)
/*! ICR13
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR13_SHIFT)) & GPIO_ICR1_ICR13_MASK)

#define GPIO_ICR1_ICR14_MASK                     (0x30000000U)
#define GPIO_ICR1_ICR14_SHIFT                    (28U)
/*! ICR14
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR14_SHIFT)) & GPIO_ICR1_ICR14_MASK)

#define GPIO_ICR1_ICR15_MASK                     (0xC0000000U)
#define GPIO_ICR1_ICR15_SHIFT                    (30U)
/*! ICR15
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR15(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR15_SHIFT)) & GPIO_ICR1_ICR15_MASK)
/*! @} */

/*! @name ICR2 - GPIO interrupt configuration register2 */
/*! @{ */

#define GPIO_ICR2_ICR16_MASK                     (0x3U)
#define GPIO_ICR2_ICR16_SHIFT                    (0U)
/*! ICR16
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR16_SHIFT)) & GPIO_ICR2_ICR16_MASK)

#define GPIO_ICR2_ICR17_MASK                     (0xCU)
#define GPIO_ICR2_ICR17_SHIFT                    (2U)
/*! ICR17
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR17_SHIFT)) & GPIO_ICR2_ICR17_MASK)

#define GPIO_ICR2_ICR18_MASK                     (0x30U)
#define GPIO_ICR2_ICR18_SHIFT                    (4U)
/*! ICR18
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR18_SHIFT)) & GPIO_ICR2_ICR18_MASK)

#define GPIO_ICR2_ICR19_MASK                     (0xC0U)
#define GPIO_ICR2_ICR19_SHIFT                    (6U)
/*! ICR19
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR19_SHIFT)) & GPIO_ICR2_ICR19_MASK)

#define GPIO_ICR2_ICR20_MASK                     (0x300U)
#define GPIO_ICR2_ICR20_SHIFT                    (8U)
/*! ICR20
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR20_SHIFT)) & GPIO_ICR2_ICR20_MASK)

#define GPIO_ICR2_ICR21_MASK                     (0xC00U)
#define GPIO_ICR2_ICR21_SHIFT                    (10U)
/*! ICR21
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR21_SHIFT)) & GPIO_ICR2_ICR21_MASK)

#define GPIO_ICR2_ICR22_MASK                     (0x3000U)
#define GPIO_ICR2_ICR22_SHIFT                    (12U)
/*! ICR22
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR22_SHIFT)) & GPIO_ICR2_ICR22_MASK)

#define GPIO_ICR2_ICR23_MASK                     (0xC000U)
#define GPIO_ICR2_ICR23_SHIFT                    (14U)
/*! ICR23
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR23_SHIFT)) & GPIO_ICR2_ICR23_MASK)

#define GPIO_ICR2_ICR24_MASK                     (0x30000U)
#define GPIO_ICR2_ICR24_SHIFT                    (16U)
/*! ICR24
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR24_SHIFT)) & GPIO_ICR2_ICR24_MASK)

#define GPIO_ICR2_ICR25_MASK                     (0xC0000U)
#define GPIO_ICR2_ICR25_SHIFT                    (18U)
/*! ICR25
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR25_SHIFT)) & GPIO_ICR2_ICR25_MASK)

#define GPIO_ICR2_ICR26_MASK                     (0x300000U)
#define GPIO_ICR2_ICR26_SHIFT                    (20U)
/*! ICR26
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR26_SHIFT)) & GPIO_ICR2_ICR26_MASK)

#define GPIO_ICR2_ICR27_MASK                     (0xC00000U)
#define GPIO_ICR2_ICR27_SHIFT                    (22U)
/*! ICR27
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR27_SHIFT)) & GPIO_ICR2_ICR27_MASK)

#define GPIO_ICR2_ICR28_MASK                     (0x3000000U)
#define GPIO_ICR2_ICR28_SHIFT                    (24U)
/*! ICR28
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR28_SHIFT)) & GPIO_ICR2_ICR28_MASK)

#define GPIO_ICR2_ICR29_MASK                     (0xC000000U)
#define GPIO_ICR2_ICR29_SHIFT                    (26U)
/*! ICR29
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR29_SHIFT)) & GPIO_ICR2_ICR29_MASK)

#define GPIO_ICR2_ICR30_MASK                     (0x30000000U)
#define GPIO_ICR2_ICR30_SHIFT                    (28U)
/*! ICR30
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR30_SHIFT)) & GPIO_ICR2_ICR30_MASK)

#define GPIO_ICR2_ICR31_MASK                     (0xC0000000U)
#define GPIO_ICR2_ICR31_SHIFT                    (30U)
/*! ICR31
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR31(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR31_SHIFT)) & GPIO_ICR2_ICR31_MASK)
/*! @} */

/*! @name IMR - GPIO interrupt mask register */
/*! @{ */

#define GPIO_IMR_IMR_MASK                        (0xFFFFFFFFU)
#define GPIO_IMR_IMR_SHIFT                       (0U)
/*! IMR
 *  0b00000000000000000000000000000000..Interrupt n is disabled.
 *  0b00000000000000000000000000000001..Interrupt n is enabled.
 */
#define GPIO_IMR_IMR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_IMR_IMR_SHIFT)) & GPIO_IMR_IMR_MASK)
/*! @} */

/*! @name ISR - GPIO interrupt status register */
/*! @{ */

#define GPIO_ISR_ISR_MASK                        (0xFFFFFFFFU)
#define GPIO_ISR_ISR_SHIFT                       (0U)
#define GPIO_ISR_ISR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_ISR_ISR_SHIFT)) & GPIO_ISR_ISR_MASK)
/*! @} */

/*! @name EDGE_SEL - GPIO edge select register */
/*! @{ */

#define GPIO_EDGE_SEL_GPIO_EDGE_SEL_MASK         (0xFFFFFFFFU)
#define GPIO_EDGE_SEL_GPIO_EDGE_SEL_SHIFT        (0U)
#define GPIO_EDGE_SEL_GPIO_EDGE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << GPIO_EDGE_SEL_GPIO_EDGE_SEL_SHIFT)) & GPIO_EDGE_SEL_GPIO_EDGE_SEL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


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


#endif  /* PERI_GPIO_H_ */

