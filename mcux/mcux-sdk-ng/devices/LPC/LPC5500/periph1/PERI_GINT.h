/*
** ###################################################################
**     Processors:          LPC5534JBD100
**                          LPC5534JBD64
**                          LPC5534JHI48
**                          LPC5536JBD100
**                          LPC5536JBD64
**                          LPC5536JHI48
**                          LPC55S36JBD100
**                          LPC55S36JHI48
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for GINT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-04-12)
**         Initial version based on RM DraftF
**     - rev. 1.1 (2021-08-04)
**         Initial version based on RM DraftG
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_GINT.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for GINT
 *
 * CMSIS Peripheral Access Layer for GINT
 */

#if !defined(PERI_GINT_H_)
#define PERI_GINT_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC5534JBD100) || defined(CPU_LPC5534JBD64) || defined(CPU_LPC5534JHI48))
#include "LPC5534_COMMON.h"
#elif (defined(CPU_LPC5536JBD100) || defined(CPU_LPC5536JBD64) || defined(CPU_LPC5536JHI48))
#include "LPC5536_COMMON.h"
#elif (defined(CPU_LPC55S36JBD100) || defined(CPU_LPC55S36JHI48))
#include "LPC55S36_COMMON.h"
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
   -- GINT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GINT_Peripheral_Access_Layer GINT Peripheral Access Layer
 * @{
 */

/** GINT - Size of Registers Arrays */
#define GINT_PORT_POL_COUNT                       2u
#define GINT_PORT_ENA_COUNT                       2u

/** GINT - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< GPIO grouped interrupt control, offset: 0x0 */
       uint8_t RESERVED_0[28];
  __IO uint32_t PORT_POL[GINT_PORT_POL_COUNT];     /**< Port polarity, array offset: 0x20, array step: 0x4 */
       uint8_t RESERVED_1[24];
  __IO uint32_t PORT_ENA[GINT_PORT_ENA_COUNT];     /**< GPIO grouped interrupt port 0 enable register, array offset: 0x40, array step: 0x4 */
} GINT_Type;

/* ----------------------------------------------------------------------------
   -- GINT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GINT_Register_Masks GINT Register Masks
 * @{
 */

/*! @name CTRL - GPIO grouped interrupt control */
/*! @{ */

#define GINT_CTRL_INT_MASK                       (0x1U)
#define GINT_CTRL_INT_SHIFT                      (0U)
/*! INT - Group interrupt status
 *  0b0..No interrupt request is pending.
 *  0b1..Interrupt request is pending.
 */
#define GINT_CTRL_INT(x)                         (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_INT_SHIFT)) & GINT_CTRL_INT_MASK)

#define GINT_CTRL_COMB_MASK                      (0x2U)
#define GINT_CTRL_COMB_SHIFT                     (1U)
/*! COMB - Combine enabled inputs for group interrupt
 *  0b0..OR functionality
 *  0b1..AND functionality
 */
#define GINT_CTRL_COMB(x)                        (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_COMB_SHIFT)) & GINT_CTRL_COMB_MASK)

#define GINT_CTRL_TRIG_MASK                      (0x4U)
#define GINT_CTRL_TRIG_SHIFT                     (2U)
/*! TRIG - Group interrupt trigger
 *  0b0..Edge-triggered
 *  0b1..Level-triggered
 */
#define GINT_CTRL_TRIG(x)                        (((uint32_t)(((uint32_t)(x)) << GINT_CTRL_TRIG_SHIFT)) & GINT_CTRL_TRIG_MASK)
/*! @} */

/*! @name PORT_POL - Port polarity */
/*! @{ */

#define GINT_PORT_POL_POL0_MASK                  (0x1U)
#define GINT_PORT_POL_POL0_SHIFT                 (0U)
/*! POL0 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL0(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL0_SHIFT)) & GINT_PORT_POL_POL0_MASK)

#define GINT_PORT_POL_POL1_MASK                  (0x2U)
#define GINT_PORT_POL_POL1_SHIFT                 (1U)
/*! POL1 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL1(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL1_SHIFT)) & GINT_PORT_POL_POL1_MASK)

#define GINT_PORT_POL_POL2_MASK                  (0x4U)
#define GINT_PORT_POL_POL2_SHIFT                 (2U)
/*! POL2 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL2(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL2_SHIFT)) & GINT_PORT_POL_POL2_MASK)

#define GINT_PORT_POL_POL3_MASK                  (0x8U)
#define GINT_PORT_POL_POL3_SHIFT                 (3U)
/*! POL3 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL3(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL3_SHIFT)) & GINT_PORT_POL_POL3_MASK)

#define GINT_PORT_POL_POL4_MASK                  (0x10U)
#define GINT_PORT_POL_POL4_SHIFT                 (4U)
/*! POL4 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL4(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL4_SHIFT)) & GINT_PORT_POL_POL4_MASK)

#define GINT_PORT_POL_POL5_MASK                  (0x20U)
#define GINT_PORT_POL_POL5_SHIFT                 (5U)
/*! POL5 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL5(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL5_SHIFT)) & GINT_PORT_POL_POL5_MASK)

#define GINT_PORT_POL_POL6_MASK                  (0x40U)
#define GINT_PORT_POL_POL6_SHIFT                 (6U)
/*! POL6 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL6(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL6_SHIFT)) & GINT_PORT_POL_POL6_MASK)

#define GINT_PORT_POL_POL7_MASK                  (0x80U)
#define GINT_PORT_POL_POL7_SHIFT                 (7U)
/*! POL7 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL7(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL7_SHIFT)) & GINT_PORT_POL_POL7_MASK)

#define GINT_PORT_POL_POL8_MASK                  (0x100U)
#define GINT_PORT_POL_POL8_SHIFT                 (8U)
/*! POL8 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL8(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL8_SHIFT)) & GINT_PORT_POL_POL8_MASK)

#define GINT_PORT_POL_POL9_MASK                  (0x200U)
#define GINT_PORT_POL_POL9_SHIFT                 (9U)
/*! POL9 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL9(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL9_SHIFT)) & GINT_PORT_POL_POL9_MASK)

#define GINT_PORT_POL_POL10_MASK                 (0x400U)
#define GINT_PORT_POL_POL10_SHIFT                (10U)
/*! POL10 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL10(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL10_SHIFT)) & GINT_PORT_POL_POL10_MASK)

#define GINT_PORT_POL_POL11_MASK                 (0x800U)
#define GINT_PORT_POL_POL11_SHIFT                (11U)
/*! POL11 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL11(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL11_SHIFT)) & GINT_PORT_POL_POL11_MASK)

#define GINT_PORT_POL_POL12_MASK                 (0x1000U)
#define GINT_PORT_POL_POL12_SHIFT                (12U)
/*! POL12 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL12(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL12_SHIFT)) & GINT_PORT_POL_POL12_MASK)

#define GINT_PORT_POL_POL13_MASK                 (0x2000U)
#define GINT_PORT_POL_POL13_SHIFT                (13U)
/*! POL13 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL13(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL13_SHIFT)) & GINT_PORT_POL_POL13_MASK)

#define GINT_PORT_POL_POL14_MASK                 (0x4000U)
#define GINT_PORT_POL_POL14_SHIFT                (14U)
/*! POL14 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL14(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL14_SHIFT)) & GINT_PORT_POL_POL14_MASK)

#define GINT_PORT_POL_POL15_MASK                 (0x8000U)
#define GINT_PORT_POL_POL15_SHIFT                (15U)
/*! POL15 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL15(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL15_SHIFT)) & GINT_PORT_POL_POL15_MASK)

#define GINT_PORT_POL_POL16_MASK                 (0x10000U)
#define GINT_PORT_POL_POL16_SHIFT                (16U)
/*! POL16 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL16(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL16_SHIFT)) & GINT_PORT_POL_POL16_MASK)

#define GINT_PORT_POL_POL17_MASK                 (0x20000U)
#define GINT_PORT_POL_POL17_SHIFT                (17U)
/*! POL17 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL17(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL17_SHIFT)) & GINT_PORT_POL_POL17_MASK)

#define GINT_PORT_POL_POL18_MASK                 (0x40000U)
#define GINT_PORT_POL_POL18_SHIFT                (18U)
/*! POL18 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL18(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL18_SHIFT)) & GINT_PORT_POL_POL18_MASK)

#define GINT_PORT_POL_POL19_MASK                 (0x80000U)
#define GINT_PORT_POL_POL19_SHIFT                (19U)
/*! POL19 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL19(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL19_SHIFT)) & GINT_PORT_POL_POL19_MASK)

#define GINT_PORT_POL_POL20_MASK                 (0x100000U)
#define GINT_PORT_POL_POL20_SHIFT                (20U)
/*! POL20 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL20(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL20_SHIFT)) & GINT_PORT_POL_POL20_MASK)

#define GINT_PORT_POL_POL21_MASK                 (0x200000U)
#define GINT_PORT_POL_POL21_SHIFT                (21U)
/*! POL21 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL21(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL21_SHIFT)) & GINT_PORT_POL_POL21_MASK)

#define GINT_PORT_POL_POL22_MASK                 (0x400000U)
#define GINT_PORT_POL_POL22_SHIFT                (22U)
/*! POL22 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL22(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL22_SHIFT)) & GINT_PORT_POL_POL22_MASK)

#define GINT_PORT_POL_POL23_MASK                 (0x800000U)
#define GINT_PORT_POL_POL23_SHIFT                (23U)
/*! POL23 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL23(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL23_SHIFT)) & GINT_PORT_POL_POL23_MASK)

#define GINT_PORT_POL_POL24_MASK                 (0x1000000U)
#define GINT_PORT_POL_POL24_SHIFT                (24U)
/*! POL24 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL24(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL24_SHIFT)) & GINT_PORT_POL_POL24_MASK)

#define GINT_PORT_POL_POL25_MASK                 (0x2000000U)
#define GINT_PORT_POL_POL25_SHIFT                (25U)
/*! POL25 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL25(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL25_SHIFT)) & GINT_PORT_POL_POL25_MASK)

#define GINT_PORT_POL_POL26_MASK                 (0x4000000U)
#define GINT_PORT_POL_POL26_SHIFT                (26U)
/*! POL26 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL26(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL26_SHIFT)) & GINT_PORT_POL_POL26_MASK)

#define GINT_PORT_POL_POL27_MASK                 (0x8000000U)
#define GINT_PORT_POL_POL27_SHIFT                (27U)
/*! POL27 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL27(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL27_SHIFT)) & GINT_PORT_POL_POL27_MASK)

#define GINT_PORT_POL_POL28_MASK                 (0x10000000U)
#define GINT_PORT_POL_POL28_SHIFT                (28U)
/*! POL28 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL28(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL28_SHIFT)) & GINT_PORT_POL_POL28_MASK)

#define GINT_PORT_POL_POL29_MASK                 (0x20000000U)
#define GINT_PORT_POL_POL29_SHIFT                (29U)
/*! POL29 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL29(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL29_SHIFT)) & GINT_PORT_POL_POL29_MASK)

#define GINT_PORT_POL_POL30_MASK                 (0x40000000U)
#define GINT_PORT_POL_POL30_SHIFT                (30U)
/*! POL30 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL30(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL30_SHIFT)) & GINT_PORT_POL_POL30_MASK)

#define GINT_PORT_POL_POL31_MASK                 (0x80000000U)
#define GINT_PORT_POL_POL31_SHIFT                (31U)
/*! POL31 - Polarity of pin n of the port
 *  0b0..Pin is active LOW
 *  0b1..Pin is active HIGH
 */
#define GINT_PORT_POL_POL31(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_POL_POL31_SHIFT)) & GINT_PORT_POL_POL31_MASK)
/*! @} */

/*! @name PORT_ENA - GPIO grouped interrupt port 0 enable register */
/*! @{ */

#define GINT_PORT_ENA_ENA0_MASK                  (0x1U)
#define GINT_PORT_ENA_ENA0_SHIFT                 (0U)
/*! ENA0 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA0(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA0_SHIFT)) & GINT_PORT_ENA_ENA0_MASK)

#define GINT_PORT_ENA_ENA1_MASK                  (0x2U)
#define GINT_PORT_ENA_ENA1_SHIFT                 (1U)
/*! ENA1 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA1(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA1_SHIFT)) & GINT_PORT_ENA_ENA1_MASK)

#define GINT_PORT_ENA_ENA2_MASK                  (0x4U)
#define GINT_PORT_ENA_ENA2_SHIFT                 (2U)
/*! ENA2 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA2(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA2_SHIFT)) & GINT_PORT_ENA_ENA2_MASK)

#define GINT_PORT_ENA_ENA3_MASK                  (0x8U)
#define GINT_PORT_ENA_ENA3_SHIFT                 (3U)
/*! ENA3 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA3(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA3_SHIFT)) & GINT_PORT_ENA_ENA3_MASK)

#define GINT_PORT_ENA_ENA4_MASK                  (0x10U)
#define GINT_PORT_ENA_ENA4_SHIFT                 (4U)
/*! ENA4 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA4(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA4_SHIFT)) & GINT_PORT_ENA_ENA4_MASK)

#define GINT_PORT_ENA_ENA5_MASK                  (0x20U)
#define GINT_PORT_ENA_ENA5_SHIFT                 (5U)
/*! ENA5 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA5(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA5_SHIFT)) & GINT_PORT_ENA_ENA5_MASK)

#define GINT_PORT_ENA_ENA6_MASK                  (0x40U)
#define GINT_PORT_ENA_ENA6_SHIFT                 (6U)
/*! ENA6 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA6(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA6_SHIFT)) & GINT_PORT_ENA_ENA6_MASK)

#define GINT_PORT_ENA_ENA7_MASK                  (0x80U)
#define GINT_PORT_ENA_ENA7_SHIFT                 (7U)
/*! ENA7 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA7(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA7_SHIFT)) & GINT_PORT_ENA_ENA7_MASK)

#define GINT_PORT_ENA_ENA8_MASK                  (0x100U)
#define GINT_PORT_ENA_ENA8_SHIFT                 (8U)
/*! ENA8 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA8(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA8_SHIFT)) & GINT_PORT_ENA_ENA8_MASK)

#define GINT_PORT_ENA_ENA9_MASK                  (0x200U)
#define GINT_PORT_ENA_ENA9_SHIFT                 (9U)
/*! ENA9 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA9(x)                    (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA9_SHIFT)) & GINT_PORT_ENA_ENA9_MASK)

#define GINT_PORT_ENA_ENA10_MASK                 (0x400U)
#define GINT_PORT_ENA_ENA10_SHIFT                (10U)
/*! ENA10 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA10(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA10_SHIFT)) & GINT_PORT_ENA_ENA10_MASK)

#define GINT_PORT_ENA_ENA11_MASK                 (0x800U)
#define GINT_PORT_ENA_ENA11_SHIFT                (11U)
/*! ENA11 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA11(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA11_SHIFT)) & GINT_PORT_ENA_ENA11_MASK)

#define GINT_PORT_ENA_ENA12_MASK                 (0x1000U)
#define GINT_PORT_ENA_ENA12_SHIFT                (12U)
/*! ENA12 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA12(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA12_SHIFT)) & GINT_PORT_ENA_ENA12_MASK)

#define GINT_PORT_ENA_ENA13_MASK                 (0x2000U)
#define GINT_PORT_ENA_ENA13_SHIFT                (13U)
/*! ENA13 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA13(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA13_SHIFT)) & GINT_PORT_ENA_ENA13_MASK)

#define GINT_PORT_ENA_ENA14_MASK                 (0x4000U)
#define GINT_PORT_ENA_ENA14_SHIFT                (14U)
/*! ENA14 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA14(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA14_SHIFT)) & GINT_PORT_ENA_ENA14_MASK)

#define GINT_PORT_ENA_ENA15_MASK                 (0x8000U)
#define GINT_PORT_ENA_ENA15_SHIFT                (15U)
/*! ENA15 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA15(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA15_SHIFT)) & GINT_PORT_ENA_ENA15_MASK)

#define GINT_PORT_ENA_ENA16_MASK                 (0x10000U)
#define GINT_PORT_ENA_ENA16_SHIFT                (16U)
/*! ENA16 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA16(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA16_SHIFT)) & GINT_PORT_ENA_ENA16_MASK)

#define GINT_PORT_ENA_ENA17_MASK                 (0x20000U)
#define GINT_PORT_ENA_ENA17_SHIFT                (17U)
/*! ENA17 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA17(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA17_SHIFT)) & GINT_PORT_ENA_ENA17_MASK)

#define GINT_PORT_ENA_ENA18_MASK                 (0x40000U)
#define GINT_PORT_ENA_ENA18_SHIFT                (18U)
/*! ENA18 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA18(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA18_SHIFT)) & GINT_PORT_ENA_ENA18_MASK)

#define GINT_PORT_ENA_ENA19_MASK                 (0x80000U)
#define GINT_PORT_ENA_ENA19_SHIFT                (19U)
/*! ENA19 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA19(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA19_SHIFT)) & GINT_PORT_ENA_ENA19_MASK)

#define GINT_PORT_ENA_ENA20_MASK                 (0x100000U)
#define GINT_PORT_ENA_ENA20_SHIFT                (20U)
/*! ENA20 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA20(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA20_SHIFT)) & GINT_PORT_ENA_ENA20_MASK)

#define GINT_PORT_ENA_ENA21_MASK                 (0x200000U)
#define GINT_PORT_ENA_ENA21_SHIFT                (21U)
/*! ENA21 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA21(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA21_SHIFT)) & GINT_PORT_ENA_ENA21_MASK)

#define GINT_PORT_ENA_ENA22_MASK                 (0x400000U)
#define GINT_PORT_ENA_ENA22_SHIFT                (22U)
/*! ENA22 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA22(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA22_SHIFT)) & GINT_PORT_ENA_ENA22_MASK)

#define GINT_PORT_ENA_ENA23_MASK                 (0x800000U)
#define GINT_PORT_ENA_ENA23_SHIFT                (23U)
/*! ENA23 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA23(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA23_SHIFT)) & GINT_PORT_ENA_ENA23_MASK)

#define GINT_PORT_ENA_ENA24_MASK                 (0x1000000U)
#define GINT_PORT_ENA_ENA24_SHIFT                (24U)
/*! ENA24 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA24(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA24_SHIFT)) & GINT_PORT_ENA_ENA24_MASK)

#define GINT_PORT_ENA_ENA25_MASK                 (0x2000000U)
#define GINT_PORT_ENA_ENA25_SHIFT                (25U)
/*! ENA25 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA25(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA25_SHIFT)) & GINT_PORT_ENA_ENA25_MASK)

#define GINT_PORT_ENA_ENA26_MASK                 (0x4000000U)
#define GINT_PORT_ENA_ENA26_SHIFT                (26U)
/*! ENA26 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA26(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA26_SHIFT)) & GINT_PORT_ENA_ENA26_MASK)

#define GINT_PORT_ENA_ENA27_MASK                 (0x8000000U)
#define GINT_PORT_ENA_ENA27_SHIFT                (27U)
/*! ENA27 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA27(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA27_SHIFT)) & GINT_PORT_ENA_ENA27_MASK)

#define GINT_PORT_ENA_ENA28_MASK                 (0x10000000U)
#define GINT_PORT_ENA_ENA28_SHIFT                (28U)
/*! ENA28 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA28(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA28_SHIFT)) & GINT_PORT_ENA_ENA28_MASK)

#define GINT_PORT_ENA_ENA29_MASK                 (0x20000000U)
#define GINT_PORT_ENA_ENA29_SHIFT                (29U)
/*! ENA29 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA29(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA29_SHIFT)) & GINT_PORT_ENA_ENA29_MASK)

#define GINT_PORT_ENA_ENA30_MASK                 (0x40000000U)
#define GINT_PORT_ENA_ENA30_SHIFT                (30U)
/*! ENA30 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA30(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA30_SHIFT)) & GINT_PORT_ENA_ENA30_MASK)

#define GINT_PORT_ENA_ENA31_MASK                 (0x80000000U)
#define GINT_PORT_ENA_ENA31_SHIFT                (31U)
/*! ENA31 - Enables port pin n to contribute to the group interrupt
 *  0b0..Pin is disabled and does not contribute to the grouped interrupt
 *  0b1..Pin is enabled and contributes to the grouped interrupt
 */
#define GINT_PORT_ENA_ENA31(x)                   (((uint32_t)(((uint32_t)(x)) << GINT_PORT_ENA_ENA31_SHIFT)) & GINT_PORT_ENA_ENA31_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group GINT_Register_Masks */


/*!
 * @}
 */ /* end of group GINT_Peripheral_Access_Layer */


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


#endif  /* PERI_GINT_H_ */

