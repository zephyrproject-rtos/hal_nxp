/*
** ###################################################################
**     Processors:          MIMXRT1051CVJ5B
**                          MIMXRT1051CVL5B
**                          MIMXRT1051DVJ6B
**                          MIMXRT1051DVL6B
**                          MIMXRT1052CVJ5B
**                          MIMXRT1052CVL5B
**                          MIMXRT1052DVJ6B
**                          MIMXRT1052DVL6B
**                          MIMXRT105SDVL6B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-09-21)
**         Update interrupt vector table and dma request source.
**         Update register BEE_ADDR_OFFSET1's bitfield name to ADDR_OFFSET1.
**         Split GPIO_COMBINED_IRQS to GPIO_COMBINED_LOW_IRQS and GPIO_COMBINED_HIGH_IRQS.
**     - rev. 1.1 (2018-11-16)
**         Update header files to align with IMXRT1050RM Rev.1.
**     - rev. 1.2 (2018-11-27)
**         Update header files to align with IMXRT1050RM Rev.2.1.
**     - rev. 1.3 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.4 (2021-08-10)
**         Update header files to align with IMXRT1050RM Rev.5.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GPIO.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GPIO
 *
 * CMSIS Peripheral Access Layer for GPIO
 */

#if !defined(PERI_GPIO_H_)
#define PERI_GPIO_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1051CVJ5B) || defined(CPU_MIMXRT1051CVL5B) || defined(CPU_MIMXRT1051DVJ6B) || defined(CPU_MIMXRT1051DVL6B))
#include "MIMXRT1051_COMMON.h"
#elif (defined(CPU_MIMXRT1052CVJ5B) || defined(CPU_MIMXRT1052CVL5B) || defined(CPU_MIMXRT1052DVJ6B) || defined(CPU_MIMXRT1052DVL6B))
#include "MIMXRT1052_COMMON.h"
#elif (defined(CPU_MIMXRT105SDVL6B))
#include "MIMXRT105S_COMMON.h"
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
       uint8_t RESERVED_0[100];
  __O  uint32_t DR_SET;                            /**< GPIO data register SET, offset: 0x84 */
  __O  uint32_t DR_CLEAR;                          /**< GPIO data register CLEAR, offset: 0x88 */
  __O  uint32_t DR_TOGGLE;                         /**< GPIO data register TOGGLE, offset: 0x8C */
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
/*! DR - DR */
#define GPIO_DR_DR(x)                            (((uint32_t)(((uint32_t)(x)) << GPIO_DR_DR_SHIFT)) & GPIO_DR_DR_MASK)
/*! @} */

/*! @name GDIR - GPIO direction register */
/*! @{ */

#define GPIO_GDIR_GDIR_MASK                      (0xFFFFFFFFU)
#define GPIO_GDIR_GDIR_SHIFT                     (0U)
/*! GDIR - GDIR */
#define GPIO_GDIR_GDIR(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_GDIR_GDIR_SHIFT)) & GPIO_GDIR_GDIR_MASK)
/*! @} */

/*! @name PSR - GPIO pad status register */
/*! @{ */

#define GPIO_PSR_PSR_MASK                        (0xFFFFFFFFU)
#define GPIO_PSR_PSR_SHIFT                       (0U)
/*! PSR - PSR */
#define GPIO_PSR_PSR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_PSR_PSR_SHIFT)) & GPIO_PSR_PSR_MASK)
/*! @} */

/*! @name ICR1 - GPIO interrupt configuration register1 */
/*! @{ */

#define GPIO_ICR1_ICR0_MASK                      (0x3U)
#define GPIO_ICR1_ICR0_SHIFT                     (0U)
/*! ICR0 - ICR0
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR0(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR0_SHIFT)) & GPIO_ICR1_ICR0_MASK)

#define GPIO_ICR1_ICR1_MASK                      (0xCU)
#define GPIO_ICR1_ICR1_SHIFT                     (2U)
/*! ICR1 - ICR1
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR1(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR1_SHIFT)) & GPIO_ICR1_ICR1_MASK)

#define GPIO_ICR1_ICR2_MASK                      (0x30U)
#define GPIO_ICR1_ICR2_SHIFT                     (4U)
/*! ICR2 - ICR2
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR2(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR2_SHIFT)) & GPIO_ICR1_ICR2_MASK)

#define GPIO_ICR1_ICR3_MASK                      (0xC0U)
#define GPIO_ICR1_ICR3_SHIFT                     (6U)
/*! ICR3 - ICR3
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR3(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR3_SHIFT)) & GPIO_ICR1_ICR3_MASK)

#define GPIO_ICR1_ICR4_MASK                      (0x300U)
#define GPIO_ICR1_ICR4_SHIFT                     (8U)
/*! ICR4 - ICR4
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR4(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR4_SHIFT)) & GPIO_ICR1_ICR4_MASK)

#define GPIO_ICR1_ICR5_MASK                      (0xC00U)
#define GPIO_ICR1_ICR5_SHIFT                     (10U)
/*! ICR5 - ICR5
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR5(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR5_SHIFT)) & GPIO_ICR1_ICR5_MASK)

#define GPIO_ICR1_ICR6_MASK                      (0x3000U)
#define GPIO_ICR1_ICR6_SHIFT                     (12U)
/*! ICR6 - ICR6
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR6(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR6_SHIFT)) & GPIO_ICR1_ICR6_MASK)

#define GPIO_ICR1_ICR7_MASK                      (0xC000U)
#define GPIO_ICR1_ICR7_SHIFT                     (14U)
/*! ICR7 - ICR7
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR7(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR7_SHIFT)) & GPIO_ICR1_ICR7_MASK)

#define GPIO_ICR1_ICR8_MASK                      (0x30000U)
#define GPIO_ICR1_ICR8_SHIFT                     (16U)
/*! ICR8 - ICR8
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR8(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR8_SHIFT)) & GPIO_ICR1_ICR8_MASK)

#define GPIO_ICR1_ICR9_MASK                      (0xC0000U)
#define GPIO_ICR1_ICR9_SHIFT                     (18U)
/*! ICR9 - ICR9
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR9(x)                        (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR9_SHIFT)) & GPIO_ICR1_ICR9_MASK)

#define GPIO_ICR1_ICR10_MASK                     (0x300000U)
#define GPIO_ICR1_ICR10_SHIFT                    (20U)
/*! ICR10 - ICR10
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR10(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR10_SHIFT)) & GPIO_ICR1_ICR10_MASK)

#define GPIO_ICR1_ICR11_MASK                     (0xC00000U)
#define GPIO_ICR1_ICR11_SHIFT                    (22U)
/*! ICR11 - ICR11
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR11(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR11_SHIFT)) & GPIO_ICR1_ICR11_MASK)

#define GPIO_ICR1_ICR12_MASK                     (0x3000000U)
#define GPIO_ICR1_ICR12_SHIFT                    (24U)
/*! ICR12 - ICR12
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR12(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR12_SHIFT)) & GPIO_ICR1_ICR12_MASK)

#define GPIO_ICR1_ICR13_MASK                     (0xC000000U)
#define GPIO_ICR1_ICR13_SHIFT                    (26U)
/*! ICR13 - ICR13
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR13(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR13_SHIFT)) & GPIO_ICR1_ICR13_MASK)

#define GPIO_ICR1_ICR14_MASK                     (0x30000000U)
#define GPIO_ICR1_ICR14_SHIFT                    (28U)
/*! ICR14 - ICR14
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR1_ICR14(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR1_ICR14_SHIFT)) & GPIO_ICR1_ICR14_MASK)

#define GPIO_ICR1_ICR15_MASK                     (0xC0000000U)
#define GPIO_ICR1_ICR15_SHIFT                    (30U)
/*! ICR15 - ICR15
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
/*! ICR16 - ICR16
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR16(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR16_SHIFT)) & GPIO_ICR2_ICR16_MASK)

#define GPIO_ICR2_ICR17_MASK                     (0xCU)
#define GPIO_ICR2_ICR17_SHIFT                    (2U)
/*! ICR17 - ICR17
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR17(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR17_SHIFT)) & GPIO_ICR2_ICR17_MASK)

#define GPIO_ICR2_ICR18_MASK                     (0x30U)
#define GPIO_ICR2_ICR18_SHIFT                    (4U)
/*! ICR18 - ICR18
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR18(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR18_SHIFT)) & GPIO_ICR2_ICR18_MASK)

#define GPIO_ICR2_ICR19_MASK                     (0xC0U)
#define GPIO_ICR2_ICR19_SHIFT                    (6U)
/*! ICR19 - ICR19
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR19(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR19_SHIFT)) & GPIO_ICR2_ICR19_MASK)

#define GPIO_ICR2_ICR20_MASK                     (0x300U)
#define GPIO_ICR2_ICR20_SHIFT                    (8U)
/*! ICR20 - ICR20
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR20(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR20_SHIFT)) & GPIO_ICR2_ICR20_MASK)

#define GPIO_ICR2_ICR21_MASK                     (0xC00U)
#define GPIO_ICR2_ICR21_SHIFT                    (10U)
/*! ICR21 - ICR21
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR21(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR21_SHIFT)) & GPIO_ICR2_ICR21_MASK)

#define GPIO_ICR2_ICR22_MASK                     (0x3000U)
#define GPIO_ICR2_ICR22_SHIFT                    (12U)
/*! ICR22 - ICR22
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR22(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR22_SHIFT)) & GPIO_ICR2_ICR22_MASK)

#define GPIO_ICR2_ICR23_MASK                     (0xC000U)
#define GPIO_ICR2_ICR23_SHIFT                    (14U)
/*! ICR23 - ICR23
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR23(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR23_SHIFT)) & GPIO_ICR2_ICR23_MASK)

#define GPIO_ICR2_ICR24_MASK                     (0x30000U)
#define GPIO_ICR2_ICR24_SHIFT                    (16U)
/*! ICR24 - ICR24
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR24(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR24_SHIFT)) & GPIO_ICR2_ICR24_MASK)

#define GPIO_ICR2_ICR25_MASK                     (0xC0000U)
#define GPIO_ICR2_ICR25_SHIFT                    (18U)
/*! ICR25 - ICR25
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR25(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR25_SHIFT)) & GPIO_ICR2_ICR25_MASK)

#define GPIO_ICR2_ICR26_MASK                     (0x300000U)
#define GPIO_ICR2_ICR26_SHIFT                    (20U)
/*! ICR26 - ICR26
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR26(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR26_SHIFT)) & GPIO_ICR2_ICR26_MASK)

#define GPIO_ICR2_ICR27_MASK                     (0xC00000U)
#define GPIO_ICR2_ICR27_SHIFT                    (22U)
/*! ICR27 - ICR27
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR27(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR27_SHIFT)) & GPIO_ICR2_ICR27_MASK)

#define GPIO_ICR2_ICR28_MASK                     (0x3000000U)
#define GPIO_ICR2_ICR28_SHIFT                    (24U)
/*! ICR28 - ICR28
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR28(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR28_SHIFT)) & GPIO_ICR2_ICR28_MASK)

#define GPIO_ICR2_ICR29_MASK                     (0xC000000U)
#define GPIO_ICR2_ICR29_SHIFT                    (26U)
/*! ICR29 - ICR29
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR29(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR29_SHIFT)) & GPIO_ICR2_ICR29_MASK)

#define GPIO_ICR2_ICR30_MASK                     (0x30000000U)
#define GPIO_ICR2_ICR30_SHIFT                    (28U)
/*! ICR30 - ICR30
 *  0b00..Interrupt n is low-level sensitive.
 *  0b01..Interrupt n is high-level sensitive.
 *  0b10..Interrupt n is rising-edge sensitive.
 *  0b11..Interrupt n is falling-edge sensitive.
 */
#define GPIO_ICR2_ICR30(x)                       (((uint32_t)(((uint32_t)(x)) << GPIO_ICR2_ICR30_SHIFT)) & GPIO_ICR2_ICR30_MASK)

#define GPIO_ICR2_ICR31_MASK                     (0xC0000000U)
#define GPIO_ICR2_ICR31_SHIFT                    (30U)
/*! ICR31 - ICR31
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
/*! IMR - IMR */
#define GPIO_IMR_IMR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_IMR_IMR_SHIFT)) & GPIO_IMR_IMR_MASK)
/*! @} */

/*! @name ISR - GPIO interrupt status register */
/*! @{ */

#define GPIO_ISR_ISR_MASK                        (0xFFFFFFFFU)
#define GPIO_ISR_ISR_SHIFT                       (0U)
/*! ISR - ISR */
#define GPIO_ISR_ISR(x)                          (((uint32_t)(((uint32_t)(x)) << GPIO_ISR_ISR_SHIFT)) & GPIO_ISR_ISR_MASK)
/*! @} */

/*! @name EDGE_SEL - GPIO edge select register */
/*! @{ */

#define GPIO_EDGE_SEL_GPIO_EDGE_SEL_MASK         (0xFFFFFFFFU)
#define GPIO_EDGE_SEL_GPIO_EDGE_SEL_SHIFT        (0U)
/*! GPIO_EDGE_SEL - GPIO_EDGE_SEL */
#define GPIO_EDGE_SEL_GPIO_EDGE_SEL(x)           (((uint32_t)(((uint32_t)(x)) << GPIO_EDGE_SEL_GPIO_EDGE_SEL_SHIFT)) & GPIO_EDGE_SEL_GPIO_EDGE_SEL_MASK)
/*! @} */

/*! @name DR_SET - GPIO data register SET */
/*! @{ */

#define GPIO_DR_SET_DR_SET_MASK                  (0xFFFFFFFFU)
#define GPIO_DR_SET_DR_SET_SHIFT                 (0U)
/*! DR_SET - DR_SET */
#define GPIO_DR_SET_DR_SET(x)                    (((uint32_t)(((uint32_t)(x)) << GPIO_DR_SET_DR_SET_SHIFT)) & GPIO_DR_SET_DR_SET_MASK)
/*! @} */

/*! @name DR_CLEAR - GPIO data register CLEAR */
/*! @{ */

#define GPIO_DR_CLEAR_DR_CLEAR_MASK              (0xFFFFFFFFU)
#define GPIO_DR_CLEAR_DR_CLEAR_SHIFT             (0U)
/*! DR_CLEAR - DR_CLEAR */
#define GPIO_DR_CLEAR_DR_CLEAR(x)                (((uint32_t)(((uint32_t)(x)) << GPIO_DR_CLEAR_DR_CLEAR_SHIFT)) & GPIO_DR_CLEAR_DR_CLEAR_MASK)
/*! @} */

/*! @name DR_TOGGLE - GPIO data register TOGGLE */
/*! @{ */

#define GPIO_DR_TOGGLE_DR_TOGGLE_MASK            (0xFFFFFFFFU)
#define GPIO_DR_TOGGLE_DR_TOGGLE_SHIFT           (0U)
/*! DR_TOGGLE - DR_TOGGLE */
#define GPIO_DR_TOGGLE_DR_TOGGLE(x)              (((uint32_t)(((uint32_t)(x)) << GPIO_DR_TOGGLE_DR_TOGGLE_SHIFT)) & GPIO_DR_TOGGLE_DR_TOGGLE_MASK)
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


#endif  /* PERI_GPIO_H_ */

