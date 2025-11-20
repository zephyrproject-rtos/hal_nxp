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
**     Version:             rev. 1.0, 2025-06-13
**     Build:               b250901
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MRCC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2025-06-13)
**         Generated based on Rev1 DraftH.
**
** ###################################################################
*/

/*!
 * @file PERI_MRCC.h
 * @version 1.0
 * @date 2025-06-13
 * @brief CMSIS Peripheral Access Layer for MRCC
 *
 * CMSIS Peripheral Access Layer for MRCC
 */

#if !defined(PERI_MRCC_H_)
#define PERI_MRCC_H_                             /**< Symbol preventing repeated inclusion */

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
   -- MRCC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Peripheral_Access_Layer MRCC Peripheral Access Layer
 * @{
 */

/** MRCC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_RST0;                          /**< Global Reset Control 0, offset: 0x0 */
  __O  uint32_t GLB_RSTSET0;                       /**< Peripheral Reset Control Set 0, offset: 0x4 */
  __O  uint32_t GLB_RSTCLR0;                       /**< Peripheral Reset Control Clear 0, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t GLB_RST1;                          /**< Peripheral Resets Control 1, offset: 0x10 */
  __O  uint32_t GLB_RSTSET1;                       /**< Peripheral Reset Control Set 1, offset: 0x14 */
  __O  uint32_t GLB_RSTCLR1;                       /**< Peripheral Reset Control Clear 1, offset: 0x18 */
       uint8_t RESERVED_1[36];
  __IO uint32_t GLB_CC0;                           /**< AHB Clock Control 0, offset: 0x40 */
  __O  uint32_t GLB_CCSET0;                        /**< AHB Clock Control Set 0, offset: 0x44 */
  __O  uint32_t GLB_CCCLR0;                        /**< AHB Clock Control Clear 0, offset: 0x48 */
       uint8_t RESERVED_2[4];
  __IO uint32_t GLB_CC1;                           /**< AHB Clock Control 1, offset: 0x50 */
  __O  uint32_t GLB_CCSET1;                        /**< AHB Clock Control Set 1, offset: 0x54 */
  __O  uint32_t GLB_CCCLR1;                        /**< AHB Clock Control Clear 1, offset: 0x58 */
       uint8_t RESERVED_3[36];
  __IO uint32_t GLB_ACC0;                          /**< Control Automatic Clock Gating 0, offset: 0x80 */
  __IO uint32_t GLB_ACC1;                          /**< Control Automatic Clock Gating 1, offset: 0x84 */
       uint8_t RESERVED_4[8];
  __IO uint32_t GLB_PR0;                           /**< Peripheral Enable Configuration 0, offset: 0x90 */
  __IO uint32_t GLB_PR1;                           /**< Global Enable Configuration 1, offset: 0x94 */
       uint8_t RESERVED_5[8];
  __IO uint32_t CTIMERGRP0CLKSEL;                  /**< CTIMER_Group_0 clock selection control, offset: 0xA0 */
  __IO uint32_t CTIMERGRP0CLKDIV;                  /**< CTIMER_Group_0 clock divider control, offset: 0xA4 */
  __IO uint32_t CTIMERGRP1CLKSEL;                  /**< CTIMER_Group_1 clock selection control, offset: 0xA8 */
  __IO uint32_t CTIMERGRP1CLKDIV;                  /**< CTIMER_Group_1 clock divider control, offset: 0xAC */
  __IO uint32_t UTICK0CLKSEL;                      /**< UTICK0 clock selection control, offset: 0xB0 */
       uint8_t RESERVED_6[8];
  __IO uint32_t WWDT0CLKDIV;                       /**< WWDT0 clock divider control, offset: 0xBC */
  __IO uint32_t ADC0CLKSEL;                        /**< ADC0 clock selection control, offset: 0xC0 */
  __IO uint32_t ADC0CLKDIV;                        /**< ADC0 clock divider control, offset: 0xC4 */
       uint8_t RESERVED_7[4];
  __IO uint32_t CMP0FUNCCLKDIV;                    /**< CMP0_FUNC clock divider control, offset: 0xCC */
  __IO uint32_t CMP0RRCLKSEL;                      /**< CMP0_RR clock selection control, offset: 0xD0 */
  __IO uint32_t CMP0RRCLKDIV;                      /**< CMP0_RR clock divider control, offset: 0xD4 */
  __IO uint32_t DBGTRACECLKSEL;                    /**< DBG_TRACE clock selection control, offset: 0xD8 */
  __IO uint32_t DBGTRACECLKDIV;                    /**< DBG_TRACE clock divider control, offset: 0xDC */
  __IO uint32_t CLKOUTCLKSEL;                      /**< CLKOUT clock selection control, offset: 0xE0 */
  __IO uint32_t CLKOUTCLKDIV;                      /**< CLKOUT clock divider control, offset: 0xE4 */
  __IO uint32_t OSTIMER0CLKSEL;                    /**< OSTIMER0 clock selection control, offset: 0xE8 */
       uint8_t RESERVED_8[4];
  __IO uint32_t PGRP0CLKSEL;                       /**< PERIPH_GROUP_0 clock selection control, offset: 0xF0 */
  __IO uint32_t PGRP0CLKDIV;                       /**< PERIPH_GROUP_0 clock divider control, offset: 0xF4 */
  __IO uint32_t PGRP1CLKSEL;                       /**< PERIPH_GROUP_1 clock selection control, offset: 0xF8 */
  __IO uint32_t PGRP1CLKDIV;                       /**< PERIPH_GROUP_1 clock divider control, offset: 0xFC */
  __IO uint32_t SYSTICKCLKSEL;                     /**< SYSTICK clock selection control, offset: 0x100 */
  __IO uint32_t SYSTICKCLKDIV;                     /**< SYSTICK clock divider control, offset: 0x104 */
       uint8_t RESERVED_9[4];
  __IO uint32_t FROHFDIV;                          /**< FRO_HF_DIV clock divider control, offset: 0x10C */
  __IO uint32_t P16KCLKSEL;                        /**< Clock selection control, offset: 0x110 */
} MRCC_Type;

/* ----------------------------------------------------------------------------
   -- MRCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Register_Masks MRCC Register Masks
 * @{
 */

/*! @name GLB_RST0 - Global Reset Control 0 */
/*! @{ */

#define MRCC_GLB_RST0_INPUTMUX0_MASK             (0x1U)
#define MRCC_GLB_RST0_INPUTMUX0_SHIFT            (0U)
/*! INPUTMUX0 - Resets INPUTMUX0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_INPUTMUX0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_INPUTMUX0_SHIFT)) & MRCC_GLB_RST0_INPUTMUX0_MASK)

#define MRCC_GLB_RST0_CTIMER0_MASK               (0x2U)
#define MRCC_GLB_RST0_CTIMER0_SHIFT              (1U)
/*! CTIMER0 - Resets CTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_CTIMER0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_CTIMER0_SHIFT)) & MRCC_GLB_RST0_CTIMER0_MASK)

#define MRCC_GLB_RST0_CTIMER1_MASK               (0x4U)
#define MRCC_GLB_RST0_CTIMER1_SHIFT              (2U)
/*! CTIMER1 - Resets CTIMER1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_CTIMER1(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_CTIMER1_SHIFT)) & MRCC_GLB_RST0_CTIMER1_MASK)

#define MRCC_GLB_RST0_CTIMER2_MASK               (0x8U)
#define MRCC_GLB_RST0_CTIMER2_SHIFT              (3U)
/*! CTIMER2 - Resets CTIMER2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_CTIMER2(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_CTIMER2_SHIFT)) & MRCC_GLB_RST0_CTIMER2_MASK)

#define MRCC_GLB_RST0_FREQME_MASK                (0x10U)
#define MRCC_GLB_RST0_FREQME_SHIFT               (4U)
/*! FREQME - Resets FREQME
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_FREQME(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_FREQME_SHIFT)) & MRCC_GLB_RST0_FREQME_MASK)

#define MRCC_GLB_RST0_UTICK0_MASK                (0x20U)
#define MRCC_GLB_RST0_UTICK0_SHIFT               (5U)
/*! UTICK0 - Resets UTICK0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_UTICK0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_UTICK0_SHIFT)) & MRCC_GLB_RST0_UTICK0_MASK)

#define MRCC_GLB_RST0_DMA0_MASK                  (0x80U)
#define MRCC_GLB_RST0_DMA0_SHIFT                 (7U)
/*! DMA0 - Resets DMA0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_DMA0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_DMA0_SHIFT)) & MRCC_GLB_RST0_DMA0_MASK)

#define MRCC_GLB_RST0_AOI0_MASK                  (0x100U)
#define MRCC_GLB_RST0_AOI0_SHIFT                 (8U)
/*! AOI0 - Resets AOI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_AOI0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_AOI0_SHIFT)) & MRCC_GLB_RST0_AOI0_MASK)

#define MRCC_GLB_RST0_CRC_MASK                   (0x200U)
#define MRCC_GLB_RST0_CRC_SHIFT                  (9U)
/*! CRC - Resets CRC
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_CRC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_CRC_SHIFT)) & MRCC_GLB_RST0_CRC_MASK)

#define MRCC_GLB_RST0_ERM0_MASK                  (0x400U)
#define MRCC_GLB_RST0_ERM0_SHIFT                 (10U)
/*! ERM0 - Resets ERM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_ERM0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_ERM0_SHIFT)) & MRCC_GLB_RST0_ERM0_MASK)

#define MRCC_GLB_RST0_LPI2C0_MASK                (0x4000U)
#define MRCC_GLB_RST0_LPI2C0_SHIFT               (14U)
/*! LPI2C0 - Resets LPI2C0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPI2C0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPI2C0_SHIFT)) & MRCC_GLB_RST0_LPI2C0_MASK)

#define MRCC_GLB_RST0_LPI2C1_MASK                (0x8000U)
#define MRCC_GLB_RST0_LPI2C1_SHIFT               (15U)
/*! LPI2C1 - Resets LPI2C1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPI2C1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPI2C1_SHIFT)) & MRCC_GLB_RST0_LPI2C1_MASK)

#define MRCC_GLB_RST0_LPSPI0_MASK                (0x10000U)
#define MRCC_GLB_RST0_LPSPI0_SHIFT               (16U)
/*! LPSPI0 - Resets LPSPI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPSPI0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPSPI0_SHIFT)) & MRCC_GLB_RST0_LPSPI0_MASK)

#define MRCC_GLB_RST0_LPSPI1_MASK                (0x20000U)
#define MRCC_GLB_RST0_LPSPI1_SHIFT               (17U)
/*! LPSPI1 - Resets LPSPI1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPSPI1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPSPI1_SHIFT)) & MRCC_GLB_RST0_LPSPI1_MASK)

#define MRCC_GLB_RST0_LPUART0_MASK               (0x40000U)
#define MRCC_GLB_RST0_LPUART0_SHIFT              (18U)
/*! LPUART0 - Resets LPUART0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPUART0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPUART0_SHIFT)) & MRCC_GLB_RST0_LPUART0_MASK)

#define MRCC_GLB_RST0_ADC0_MASK                  (0x80000U)
#define MRCC_GLB_RST0_ADC0_SHIFT                 (19U)
/*! ADC0 - Resets ADC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_ADC0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_ADC0_SHIFT)) & MRCC_GLB_RST0_ADC0_MASK)

#define MRCC_GLB_RST0_CMP0_MASK                  (0x200000U)
#define MRCC_GLB_RST0_CMP0_SHIFT                 (21U)
/*! CMP0 - Resets CMP0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_CMP0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_CMP0_SHIFT)) & MRCC_GLB_RST0_CMP0_MASK)

#define MRCC_GLB_RST0_DMA1_MASK                  (0x400000U)
#define MRCC_GLB_RST0_DMA1_SHIFT                 (22U)
/*! DMA1 - Resets DMA1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_DMA1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_DMA1_SHIFT)) & MRCC_GLB_RST0_DMA1_MASK)

#define MRCC_GLB_RST0_GPIO1_MASK                 (0x1000000U)
#define MRCC_GLB_RST0_GPIO1_SHIFT                (24U)
/*! GPIO1 - Resets GPIO1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_GPIO1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_GPIO1_SHIFT)) & MRCC_GLB_RST0_GPIO1_MASK)

#define MRCC_GLB_RST0_GPIO2_MASK                 (0x2000000U)
#define MRCC_GLB_RST0_GPIO2_SHIFT                (25U)
/*! GPIO2 - Resets GPIO2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_GPIO2(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_GPIO2_SHIFT)) & MRCC_GLB_RST0_GPIO2_MASK)

#define MRCC_GLB_RST0_GPIO3_MASK                 (0x4000000U)
#define MRCC_GLB_RST0_GPIO3_SHIFT                (26U)
/*! GPIO3 - Resets GPIO3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_GPIO3(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_GPIO3_SHIFT)) & MRCC_GLB_RST0_GPIO3_MASK)

#define MRCC_GLB_RST0_LPUART1_MASK               (0x8000000U)
#define MRCC_GLB_RST0_LPUART1_SHIFT              (27U)
/*! LPUART1 - Resets LPUART1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_LPUART1(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_LPUART1_SHIFT)) & MRCC_GLB_RST0_LPUART1_MASK)

#define MRCC_GLB_RST0_OSTIMER0_MASK              (0x20000000U)
#define MRCC_GLB_RST0_OSTIMER0_SHIFT             (29U)
/*! OSTIMER0 - Resets OSTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST0_OSTIMER0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST0_OSTIMER0_SHIFT)) & MRCC_GLB_RST0_OSTIMER0_MASK)
/*! @} */

/*! @name GLB_RSTSET0 - Peripheral Reset Control Set 0 */
/*! @{ */

#define MRCC_GLB_RSTSET0_DATA_MASK               (0xFFFFFFFFU)
#define MRCC_GLB_RSTSET0_DATA_SHIFT              (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_RSTn. */
#define MRCC_GLB_RSTSET0_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RSTSET0_DATA_SHIFT)) & MRCC_GLB_RSTSET0_DATA_MASK)
/*! @} */

/*! @name GLB_RSTCLR0 - Peripheral Reset Control Clear 0 */
/*! @{ */

#define MRCC_GLB_RSTCLR0_DATA_MASK               (0xFFFFFFFFU)
#define MRCC_GLB_RSTCLR0_DATA_SHIFT              (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_RSTn. */
#define MRCC_GLB_RSTCLR0_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RSTCLR0_DATA_SHIFT)) & MRCC_GLB_RSTCLR0_DATA_MASK)
/*! @} */

/*! @name GLB_RST1 - Peripheral Resets Control 1 */
/*! @{ */

#define MRCC_GLB_RST1_PKC0_MASK                  (0x1U)
#define MRCC_GLB_RST1_PKC0_SHIFT                 (0U)
/*! PKC0 - Resets PKC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_PKC0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_PKC0_SHIFT)) & MRCC_GLB_RST1_PKC0_MASK)

#define MRCC_GLB_RST1_PORT1_MASK                 (0x2U)
#define MRCC_GLB_RST1_PORT1_SHIFT                (1U)
/*! PORT1 - Resets PORT1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_PORT1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_PORT1_SHIFT)) & MRCC_GLB_RST1_PORT1_MASK)

#define MRCC_GLB_RST1_PORT2_MASK                 (0x4U)
#define MRCC_GLB_RST1_PORT2_SHIFT                (2U)
/*! PORT2 - Resets PORT2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_PORT2(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_PORT2_SHIFT)) & MRCC_GLB_RST1_PORT2_MASK)

#define MRCC_GLB_RST1_PORT3_MASK                 (0x8U)
#define MRCC_GLB_RST1_PORT3_SHIFT                (3U)
/*! PORT3 - Resets PORT3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_PORT3(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_PORT3_SHIFT)) & MRCC_GLB_RST1_PORT3_MASK)

#define MRCC_GLB_RST1_SLCD0_MASK                 (0x40U)
#define MRCC_GLB_RST1_SLCD0_SHIFT                (6U)
/*! SLCD0 - Resets SLCD0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_SLCD0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_SLCD0_SHIFT)) & MRCC_GLB_RST1_SLCD0_MASK)

#define MRCC_GLB_RST1_TRNG0_MASK                 (0x100U)
#define MRCC_GLB_RST1_TRNG0_SHIFT                (8U)
/*! TRNG0 - Resets TRNG0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_GLB_RST1_TRNG0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RST1_TRNG0_SHIFT)) & MRCC_GLB_RST1_TRNG0_MASK)
/*! @} */

/*! @name GLB_RSTSET1 - Peripheral Reset Control Set 1 */
/*! @{ */

#define MRCC_GLB_RSTSET1_DATA_MASK               (0xFFFFFFFFU)
#define MRCC_GLB_RSTSET1_DATA_SHIFT              (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_RSTn. */
#define MRCC_GLB_RSTSET1_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RSTSET1_DATA_SHIFT)) & MRCC_GLB_RSTSET1_DATA_MASK)
/*! @} */

/*! @name GLB_RSTCLR1 - Peripheral Reset Control Clear 1 */
/*! @{ */

#define MRCC_GLB_RSTCLR1_DATA_MASK               (0xFFFFFFFFU)
#define MRCC_GLB_RSTCLR1_DATA_SHIFT              (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_RSTn. */
#define MRCC_GLB_RSTCLR1_DATA(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_RSTCLR1_DATA_SHIFT)) & MRCC_GLB_RSTCLR1_DATA_MASK)
/*! @} */

/*! @name GLB_CC0 - AHB Clock Control 0 */
/*! @{ */

#define MRCC_GLB_CC0_INPUTMUX0_MASK              (0x1U)
#define MRCC_GLB_CC0_INPUTMUX0_SHIFT             (0U)
/*! INPUTMUX0 - Clock gate control INPUTMUX0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_INPUTMUX0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_INPUTMUX0_SHIFT)) & MRCC_GLB_CC0_INPUTMUX0_MASK)

#define MRCC_GLB_CC0_CTIMER0_MASK                (0x2U)
#define MRCC_GLB_CC0_CTIMER0_SHIFT               (1U)
/*! CTIMER0 - Clock gate control CTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_CTIMER0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_CTIMER0_SHIFT)) & MRCC_GLB_CC0_CTIMER0_MASK)

#define MRCC_GLB_CC0_CTIMER1_MASK                (0x4U)
#define MRCC_GLB_CC0_CTIMER1_SHIFT               (2U)
/*! CTIMER1 - Clock gate control CTIMER1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_CTIMER1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_CTIMER1_SHIFT)) & MRCC_GLB_CC0_CTIMER1_MASK)

#define MRCC_GLB_CC0_CTIMER2_MASK                (0x8U)
#define MRCC_GLB_CC0_CTIMER2_SHIFT               (3U)
/*! CTIMER2 - Clock gate control CTIMER2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_CTIMER2(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_CTIMER2_SHIFT)) & MRCC_GLB_CC0_CTIMER2_MASK)

#define MRCC_GLB_CC0_FREQME_MASK                 (0x10U)
#define MRCC_GLB_CC0_FREQME_SHIFT                (4U)
/*! FREQME - Clock gate control FREQME
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_FREQME(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_FREQME_SHIFT)) & MRCC_GLB_CC0_FREQME_MASK)

#define MRCC_GLB_CC0_UTICK0_MASK                 (0x20U)
#define MRCC_GLB_CC0_UTICK0_SHIFT                (5U)
/*! UTICK0 - Clock gate control UTICK0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_UTICK0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_UTICK0_SHIFT)) & MRCC_GLB_CC0_UTICK0_MASK)

#define MRCC_GLB_CC0_WWDT0_MASK                  (0x40U)
#define MRCC_GLB_CC0_WWDT0_SHIFT                 (6U)
/*! WWDT0 - Clock gate control WWDT0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_WWDT0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_WWDT0_SHIFT)) & MRCC_GLB_CC0_WWDT0_MASK)

#define MRCC_GLB_CC0_DMA0_MASK                   (0x80U)
#define MRCC_GLB_CC0_DMA0_SHIFT                  (7U)
/*! DMA0 - Clock gate control DMA0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_DMA0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_DMA0_SHIFT)) & MRCC_GLB_CC0_DMA0_MASK)

#define MRCC_GLB_CC0_AOI0_MASK                   (0x100U)
#define MRCC_GLB_CC0_AOI0_SHIFT                  (8U)
/*! AOI0 - Clock gate control AOI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_AOI0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_AOI0_SHIFT)) & MRCC_GLB_CC0_AOI0_MASK)

#define MRCC_GLB_CC0_CRC_MASK                    (0x200U)
#define MRCC_GLB_CC0_CRC_SHIFT                   (9U)
/*! CRC - Clock gate control CRC
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_CRC(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_CRC_SHIFT)) & MRCC_GLB_CC0_CRC_MASK)

#define MRCC_GLB_CC0_ERM0_MASK                   (0x400U)
#define MRCC_GLB_CC0_ERM0_SHIFT                  (10U)
/*! ERM0 - Clock gate control ERM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_ERM0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_ERM0_SHIFT)) & MRCC_GLB_CC0_ERM0_MASK)

#define MRCC_GLB_CC0_LPI2C0_MASK                 (0x4000U)
#define MRCC_GLB_CC0_LPI2C0_SHIFT                (14U)
/*! LPI2C0 - Clock gate control LPI2C0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPI2C0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPI2C0_SHIFT)) & MRCC_GLB_CC0_LPI2C0_MASK)

#define MRCC_GLB_CC0_LPI2C1_MASK                 (0x8000U)
#define MRCC_GLB_CC0_LPI2C1_SHIFT                (15U)
/*! LPI2C1 - Clock gate control LPI2C1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPI2C1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPI2C1_SHIFT)) & MRCC_GLB_CC0_LPI2C1_MASK)

#define MRCC_GLB_CC0_LPSPI0_MASK                 (0x10000U)
#define MRCC_GLB_CC0_LPSPI0_SHIFT                (16U)
/*! LPSPI0 - Clock gate control LPSPI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPSPI0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPSPI0_SHIFT)) & MRCC_GLB_CC0_LPSPI0_MASK)

#define MRCC_GLB_CC0_LPSPI1_MASK                 (0x20000U)
#define MRCC_GLB_CC0_LPSPI1_SHIFT                (17U)
/*! LPSPI1 - Clock gate control LPSPI1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPSPI1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPSPI1_SHIFT)) & MRCC_GLB_CC0_LPSPI1_MASK)

#define MRCC_GLB_CC0_LPUART0_MASK                (0x40000U)
#define MRCC_GLB_CC0_LPUART0_SHIFT               (18U)
/*! LPUART0 - Clock gate control LPUART0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPUART0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPUART0_SHIFT)) & MRCC_GLB_CC0_LPUART0_MASK)

#define MRCC_GLB_CC0_ADC0_MASK                   (0x80000U)
#define MRCC_GLB_CC0_ADC0_SHIFT                  (19U)
/*! ADC0 - Clock gate control ADC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_ADC0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_ADC0_SHIFT)) & MRCC_GLB_CC0_ADC0_MASK)

#define MRCC_GLB_CC0_CMP0_MASK                   (0x200000U)
#define MRCC_GLB_CC0_CMP0_SHIFT                  (21U)
/*! CMP0 - Clock gate control CMP0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_CMP0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_CMP0_SHIFT)) & MRCC_GLB_CC0_CMP0_MASK)

#define MRCC_GLB_CC0_DMA1_MASK                   (0x400000U)
#define MRCC_GLB_CC0_DMA1_SHIFT                  (22U)
/*! DMA1 - Clock gate control DMA1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_DMA1(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_DMA1_SHIFT)) & MRCC_GLB_CC0_DMA1_MASK)

#define MRCC_GLB_CC0_SRAMA_MASK                  (0x800000U)
#define MRCC_GLB_CC0_SRAMA_SHIFT                 (23U)
/*! SRAMA - Clock gate control SRAM A0/A1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_SRAMA(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_SRAMA_SHIFT)) & MRCC_GLB_CC0_SRAMA_MASK)

#define MRCC_GLB_CC0_GPIO1_MASK                  (0x1000000U)
#define MRCC_GLB_CC0_GPIO1_SHIFT                 (24U)
/*! GPIO1 - Clock gate control GPIO1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_GPIO1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_GPIO1_SHIFT)) & MRCC_GLB_CC0_GPIO1_MASK)

#define MRCC_GLB_CC0_GPIO2_MASK                  (0x2000000U)
#define MRCC_GLB_CC0_GPIO2_SHIFT                 (25U)
/*! GPIO2 - Clock gate control GPIO2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_GPIO2(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_GPIO2_SHIFT)) & MRCC_GLB_CC0_GPIO2_MASK)

#define MRCC_GLB_CC0_GPIO3_MASK                  (0x4000000U)
#define MRCC_GLB_CC0_GPIO3_SHIFT                 (26U)
/*! GPIO3 - Clock gate control GPIO3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_GPIO3(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_GPIO3_SHIFT)) & MRCC_GLB_CC0_GPIO3_MASK)

#define MRCC_GLB_CC0_LPUART1_MASK                (0x8000000U)
#define MRCC_GLB_CC0_LPUART1_SHIFT               (27U)
/*! LPUART1 - Clock gate control LPUART1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_LPUART1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_LPUART1_SHIFT)) & MRCC_GLB_CC0_LPUART1_MASK)

#define MRCC_GLB_CC0_MTR_MASK                    (0x10000000U)
#define MRCC_GLB_CC0_MTR_SHIFT                   (28U)
/*! MTR - Clock gate control MTR
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_MTR(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_MTR_SHIFT)) & MRCC_GLB_CC0_MTR_MASK)

#define MRCC_GLB_CC0_OSTIMER0_MASK               (0x20000000U)
#define MRCC_GLB_CC0_OSTIMER0_SHIFT              (29U)
/*! OSTIMER0 - Clock gate control OSTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_OSTIMER0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_OSTIMER0_SHIFT)) & MRCC_GLB_CC0_OSTIMER0_MASK)

#define MRCC_GLB_CC0_PGRP0_MASK                  (0x40000000U)
#define MRCC_GLB_CC0_PGRP0_SHIFT                 (30U)
/*! PGRP0 - Clock gate control PERIPH_GROUP_0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_PGRP0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_PGRP0_SHIFT)) & MRCC_GLB_CC0_PGRP0_MASK)

#define MRCC_GLB_CC0_PGRP1_MASK                  (0x80000000U)
#define MRCC_GLB_CC0_PGRP1_SHIFT                 (31U)
/*! PGRP1 - Clock gate control PERIPH_GROUP_1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC0_PGRP1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC0_PGRP1_SHIFT)) & MRCC_GLB_CC0_PGRP1_MASK)
/*! @} */

/*! @name GLB_CCSET0 - AHB Clock Control Set 0 */
/*! @{ */

#define MRCC_GLB_CCSET0_DATA_MASK                (0xFFFFFFFFU)
#define MRCC_GLB_CCSET0_DATA_SHIFT               (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_CCn. */
#define MRCC_GLB_CCSET0_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CCSET0_DATA_SHIFT)) & MRCC_GLB_CCSET0_DATA_MASK)
/*! @} */

/*! @name GLB_CCCLR0 - AHB Clock Control Clear 0 */
/*! @{ */

#define MRCC_GLB_CCCLR0_DATA_MASK                (0xFFFFFFFFU)
#define MRCC_GLB_CCCLR0_DATA_SHIFT               (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_CCn. */
#define MRCC_GLB_CCCLR0_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CCCLR0_DATA_SHIFT)) & MRCC_GLB_CCCLR0_DATA_MASK)
/*! @} */

/*! @name GLB_CC1 - AHB Clock Control 1 */
/*! @{ */

#define MRCC_GLB_CC1_PKC0_MASK                   (0x1U)
#define MRCC_GLB_CC1_PKC0_SHIFT                  (0U)
/*! PKC0 - Clock gate control PKC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_PKC0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_PKC0_SHIFT)) & MRCC_GLB_CC1_PKC0_MASK)

#define MRCC_GLB_CC1_PORT1_MASK                  (0x2U)
#define MRCC_GLB_CC1_PORT1_SHIFT                 (1U)
/*! PORT1 - Clock gate control PORT1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_PORT1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_PORT1_SHIFT)) & MRCC_GLB_CC1_PORT1_MASK)

#define MRCC_GLB_CC1_PORT2_MASK                  (0x4U)
#define MRCC_GLB_CC1_PORT2_SHIFT                 (2U)
/*! PORT2 - Clock gate control PORT2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_PORT2(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_PORT2_SHIFT)) & MRCC_GLB_CC1_PORT2_MASK)

#define MRCC_GLB_CC1_PORT3_MASK                  (0x8U)
#define MRCC_GLB_CC1_PORT3_SHIFT                 (3U)
/*! PORT3 - Clock gate control PORT3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_PORT3(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_PORT3_SHIFT)) & MRCC_GLB_CC1_PORT3_MASK)

#define MRCC_GLB_CC1_ROMCP_MASK                  (0x10U)
#define MRCC_GLB_CC1_ROMCP_SHIFT                 (4U)
/*! ROMCP - Clock gate control ROMCP
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_ROMCP(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_ROMCP_SHIFT)) & MRCC_GLB_CC1_ROMCP_MASK)

#define MRCC_GLB_CC1_SGI0_MASK                   (0x20U)
#define MRCC_GLB_CC1_SGI0_SHIFT                  (5U)
/*! SGI0 - Clock gate control SGI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_SGI0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_SGI0_SHIFT)) & MRCC_GLB_CC1_SGI0_MASK)

#define MRCC_GLB_CC1_SLCD0_MASK                  (0x40U)
#define MRCC_GLB_CC1_SLCD0_SHIFT                 (6U)
/*! SLCD0 - Clock gate control SLCD0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_SLCD0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_SLCD0_SHIFT)) & MRCC_GLB_CC1_SLCD0_MASK)

#define MRCC_GLB_CC1_TCU_MASK                    (0x80U)
#define MRCC_GLB_CC1_TCU_SHIFT                   (7U)
/*! TCU - Clock gate control TCU
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_TCU(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_TCU_SHIFT)) & MRCC_GLB_CC1_TCU_MASK)

#define MRCC_GLB_CC1_TRNG0_MASK                  (0x100U)
#define MRCC_GLB_CC1_TRNG0_SHIFT                 (8U)
/*! TRNG0 - Clock gate control TRNG0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_GLB_CC1_TRNG0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CC1_TRNG0_SHIFT)) & MRCC_GLB_CC1_TRNG0_MASK)
/*! @} */

/*! @name GLB_CCSET1 - AHB Clock Control Set 1 */
/*! @{ */

#define MRCC_GLB_CCSET1_DATA_MASK                (0xFFFFFFFFU)
#define MRCC_GLB_CCSET1_DATA_SHIFT               (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_CCn. */
#define MRCC_GLB_CCSET1_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CCSET1_DATA_SHIFT)) & MRCC_GLB_CCSET1_DATA_MASK)
/*! @} */

/*! @name GLB_CCCLR1 - AHB Clock Control Clear 1 */
/*! @{ */

#define MRCC_GLB_CCCLR1_DATA_MASK                (0xFFFFFFFFU)
#define MRCC_GLB_CCCLR1_DATA_SHIFT               (0U)
/*! DATA - Data array value, refer to corresponding position in GLB_CCn. */
#define MRCC_GLB_CCCLR1_DATA(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_CCCLR1_DATA_SHIFT)) & MRCC_GLB_CCCLR1_DATA_MASK)
/*! @} */

/*! @name GLB_ACC0 - Control Automatic Clock Gating 0 */
/*! @{ */

#define MRCC_GLB_ACC0_INPUTMUX0_MASK             (0x1U)
#define MRCC_GLB_ACC0_INPUTMUX0_SHIFT            (0U)
/*! INPUTMUX0 - Automatic clock control INPUTMUX0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_INPUTMUX0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_INPUTMUX0_SHIFT)) & MRCC_GLB_ACC0_INPUTMUX0_MASK)

#define MRCC_GLB_ACC0_CTIMER0_MASK               (0x2U)
#define MRCC_GLB_ACC0_CTIMER0_SHIFT              (1U)
/*! CTIMER0 - Automatic clock control CTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_CTIMER0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_CTIMER0_SHIFT)) & MRCC_GLB_ACC0_CTIMER0_MASK)

#define MRCC_GLB_ACC0_CTIMER1_MASK               (0x4U)
#define MRCC_GLB_ACC0_CTIMER1_SHIFT              (2U)
/*! CTIMER1 - Automatic clock control CTIMER1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_CTIMER1(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_CTIMER1_SHIFT)) & MRCC_GLB_ACC0_CTIMER1_MASK)

#define MRCC_GLB_ACC0_CTIMER2_MASK               (0x8U)
#define MRCC_GLB_ACC0_CTIMER2_SHIFT              (3U)
/*! CTIMER2 - Automatic clock control CTIMER2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_CTIMER2(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_CTIMER2_SHIFT)) & MRCC_GLB_ACC0_CTIMER2_MASK)

#define MRCC_GLB_ACC0_FREQME_MASK                (0x10U)
#define MRCC_GLB_ACC0_FREQME_SHIFT               (4U)
/*! FREQME - Automatic clock control FREQME
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_FREQME(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_FREQME_SHIFT)) & MRCC_GLB_ACC0_FREQME_MASK)

#define MRCC_GLB_ACC0_UTICK0_MASK                (0x20U)
#define MRCC_GLB_ACC0_UTICK0_SHIFT               (5U)
/*! UTICK0 - Automatic clock control UTICK0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_UTICK0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_UTICK0_SHIFT)) & MRCC_GLB_ACC0_UTICK0_MASK)

#define MRCC_GLB_ACC0_WWDT0_MASK                 (0x40U)
#define MRCC_GLB_ACC0_WWDT0_SHIFT                (6U)
/*! WWDT0 - Automatic clock control WWDT0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_WWDT0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_WWDT0_SHIFT)) & MRCC_GLB_ACC0_WWDT0_MASK)

#define MRCC_GLB_ACC0_DMA0_MASK                  (0x80U)
#define MRCC_GLB_ACC0_DMA0_SHIFT                 (7U)
/*! DMA0 - Automatic clock control DMA0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_DMA0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_DMA0_SHIFT)) & MRCC_GLB_ACC0_DMA0_MASK)

#define MRCC_GLB_ACC0_AOI0_MASK                  (0x100U)
#define MRCC_GLB_ACC0_AOI0_SHIFT                 (8U)
/*! AOI0 - Automatic clock control AOI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_AOI0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_AOI0_SHIFT)) & MRCC_GLB_ACC0_AOI0_MASK)

#define MRCC_GLB_ACC0_CRC_MASK                   (0x200U)
#define MRCC_GLB_ACC0_CRC_SHIFT                  (9U)
/*! CRC - Automatic clock control CRC
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_CRC(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_CRC_SHIFT)) & MRCC_GLB_ACC0_CRC_MASK)

#define MRCC_GLB_ACC0_ERM0_MASK                  (0x400U)
#define MRCC_GLB_ACC0_ERM0_SHIFT                 (10U)
/*! ERM0 - Automatic clock control ERM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_ERM0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_ERM0_SHIFT)) & MRCC_GLB_ACC0_ERM0_MASK)

#define MRCC_GLB_ACC0_NVM_MBC_MASK               (0x800U)
#define MRCC_GLB_ACC0_NVM_MBC_SHIFT              (11U)
/*! NVM_MBC - Automatic clock control NVM_MBC
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_NVM_MBC(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_NVM_MBC_SHIFT)) & MRCC_GLB_ACC0_NVM_MBC_MASK)

#define MRCC_GLB_ACC0_NVM_NPX_CTL_MASK           (0x1000U)
#define MRCC_GLB_ACC0_NVM_NPX_CTL_SHIFT          (12U)
/*! NVM_NPX_CTL - Automatic clock control NVM_NPX_CTL
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_NVM_NPX_CTL(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_NVM_NPX_CTL_SHIFT)) & MRCC_GLB_ACC0_NVM_NPX_CTL_MASK)

#define MRCC_GLB_ACC0_FMU0_MASK                  (0x2000U)
#define MRCC_GLB_ACC0_FMU0_SHIFT                 (13U)
/*! FMU0 - Automatic clock control FMU0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_FMU0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_FMU0_SHIFT)) & MRCC_GLB_ACC0_FMU0_MASK)

#define MRCC_GLB_ACC0_LPI2C0_MASK                (0x4000U)
#define MRCC_GLB_ACC0_LPI2C0_SHIFT               (14U)
/*! LPI2C0 - Automatic clock control LPI2C0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPI2C0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPI2C0_SHIFT)) & MRCC_GLB_ACC0_LPI2C0_MASK)

#define MRCC_GLB_ACC0_LPI2C1_MASK                (0x8000U)
#define MRCC_GLB_ACC0_LPI2C1_SHIFT               (15U)
/*! LPI2C1 - Automatic clock control LPI2C1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPI2C1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPI2C1_SHIFT)) & MRCC_GLB_ACC0_LPI2C1_MASK)

#define MRCC_GLB_ACC0_LPSPI0_MASK                (0x10000U)
#define MRCC_GLB_ACC0_LPSPI0_SHIFT               (16U)
/*! LPSPI0 - Automatic clock control LPSPI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPSPI0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPSPI0_SHIFT)) & MRCC_GLB_ACC0_LPSPI0_MASK)

#define MRCC_GLB_ACC0_LPSPI1_MASK                (0x20000U)
#define MRCC_GLB_ACC0_LPSPI1_SHIFT               (17U)
/*! LPSPI1 - Automatic clock control LPSPI1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPSPI1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPSPI1_SHIFT)) & MRCC_GLB_ACC0_LPSPI1_MASK)

#define MRCC_GLB_ACC0_LPUART0_MASK               (0x40000U)
#define MRCC_GLB_ACC0_LPUART0_SHIFT              (18U)
/*! LPUART0 - Automatic clock control LPUART0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPUART0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPUART0_SHIFT)) & MRCC_GLB_ACC0_LPUART0_MASK)

#define MRCC_GLB_ACC0_ADC0_MASK                  (0x80000U)
#define MRCC_GLB_ACC0_ADC0_SHIFT                 (19U)
/*! ADC0 - Automatic clock control ADC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_ADC0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_ADC0_SHIFT)) & MRCC_GLB_ACC0_ADC0_MASK)

#define MRCC_GLB_ACC0_CMP0_MASK                  (0x200000U)
#define MRCC_GLB_ACC0_CMP0_SHIFT                 (21U)
/*! CMP0 - Automatic clock control CMP0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_CMP0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_CMP0_SHIFT)) & MRCC_GLB_ACC0_CMP0_MASK)

#define MRCC_GLB_ACC0_DMA1_MASK                  (0x400000U)
#define MRCC_GLB_ACC0_DMA1_SHIFT                 (22U)
/*! DMA1 - Automatic clock control DMA1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_DMA1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_DMA1_SHIFT)) & MRCC_GLB_ACC0_DMA1_MASK)

#define MRCC_GLB_ACC0_SRAMA_MASK                 (0x800000U)
#define MRCC_GLB_ACC0_SRAMA_SHIFT                (23U)
/*! SRAMA - Automatic clock control SRAM A0/A1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_SRAMA(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_SRAMA_SHIFT)) & MRCC_GLB_ACC0_SRAMA_MASK)

#define MRCC_GLB_ACC0_GPIO1_MASK                 (0x1000000U)
#define MRCC_GLB_ACC0_GPIO1_SHIFT                (24U)
/*! GPIO1 - Automatic clock control GPIO1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_GPIO1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_GPIO1_SHIFT)) & MRCC_GLB_ACC0_GPIO1_MASK)

#define MRCC_GLB_ACC0_GPIO2_MASK                 (0x2000000U)
#define MRCC_GLB_ACC0_GPIO2_SHIFT                (25U)
/*! GPIO2 - Automatic clock control GPIO2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_GPIO2(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_GPIO2_SHIFT)) & MRCC_GLB_ACC0_GPIO2_MASK)

#define MRCC_GLB_ACC0_GPIO3_MASK                 (0x4000000U)
#define MRCC_GLB_ACC0_GPIO3_SHIFT                (26U)
/*! GPIO3 - Automatic clock control GPIO3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_GPIO3(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_GPIO3_SHIFT)) & MRCC_GLB_ACC0_GPIO3_MASK)

#define MRCC_GLB_ACC0_LPUART1_MASK               (0x8000000U)
#define MRCC_GLB_ACC0_LPUART1_SHIFT              (27U)
/*! LPUART1 - Automatic clock control LPUART1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_LPUART1(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_LPUART1_SHIFT)) & MRCC_GLB_ACC0_LPUART1_MASK)

#define MRCC_GLB_ACC0_OSTIMER0_MASK              (0x20000000U)
#define MRCC_GLB_ACC0_OSTIMER0_SHIFT             (29U)
/*! OSTIMER0 - Automatic clock control OSTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_OSTIMER0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_OSTIMER0_SHIFT)) & MRCC_GLB_ACC0_OSTIMER0_MASK)

#define MRCC_GLB_ACC0_PGRP0_MASK                 (0x40000000U)
#define MRCC_GLB_ACC0_PGRP0_SHIFT                (30U)
/*! PGRP0 - Automatic clock control PERIPH_GROUP_0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_PGRP0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_PGRP0_SHIFT)) & MRCC_GLB_ACC0_PGRP0_MASK)

#define MRCC_GLB_ACC0_PGRP1_MASK                 (0x80000000U)
#define MRCC_GLB_ACC0_PGRP1_SHIFT                (31U)
/*! PGRP1 - Automatic clock control PERIPH_GROUP_1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC0_PGRP1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC0_PGRP1_SHIFT)) & MRCC_GLB_ACC0_PGRP1_MASK)
/*! @} */

/*! @name GLB_ACC1 - Control Automatic Clock Gating 1 */
/*! @{ */

#define MRCC_GLB_ACC1_PKC0_MASK                  (0x1U)
#define MRCC_GLB_ACC1_PKC0_SHIFT                 (0U)
/*! PKC0 - Automatic clock control PKC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_PKC0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_PKC0_SHIFT)) & MRCC_GLB_ACC1_PKC0_MASK)

#define MRCC_GLB_ACC1_PORT1_MASK                 (0x2U)
#define MRCC_GLB_ACC1_PORT1_SHIFT                (1U)
/*! PORT1 - Automatic clock control PORT1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_PORT1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_PORT1_SHIFT)) & MRCC_GLB_ACC1_PORT1_MASK)

#define MRCC_GLB_ACC1_PORT2_MASK                 (0x4U)
#define MRCC_GLB_ACC1_PORT2_SHIFT                (2U)
/*! PORT2 - Automatic clock control PORT2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_PORT2(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_PORT2_SHIFT)) & MRCC_GLB_ACC1_PORT2_MASK)

#define MRCC_GLB_ACC1_PORT3_MASK                 (0x8U)
#define MRCC_GLB_ACC1_PORT3_SHIFT                (3U)
/*! PORT3 - Automatic clock control PORT3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_PORT3(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_PORT3_SHIFT)) & MRCC_GLB_ACC1_PORT3_MASK)

#define MRCC_GLB_ACC1_ROMCP_MASK                 (0x10U)
#define MRCC_GLB_ACC1_ROMCP_SHIFT                (4U)
/*! ROMCP - Automatic clock control ROMCP
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_ROMCP(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_ROMCP_SHIFT)) & MRCC_GLB_ACC1_ROMCP_MASK)

#define MRCC_GLB_ACC1_SGI0_MASK                  (0x20U)
#define MRCC_GLB_ACC1_SGI0_SHIFT                 (5U)
/*! SGI0 - Automatic clock control SGI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_SGI0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_SGI0_SHIFT)) & MRCC_GLB_ACC1_SGI0_MASK)

#define MRCC_GLB_ACC1_SLCD0_MASK                 (0x40U)
#define MRCC_GLB_ACC1_SLCD0_SHIFT                (6U)
/*! SLCD0 - Automatic clock control SLCD0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_SLCD0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_SLCD0_SHIFT)) & MRCC_GLB_ACC1_SLCD0_MASK)

#define MRCC_GLB_ACC1_TRNG0_MASK                 (0x100U)
#define MRCC_GLB_ACC1_TRNG0_SHIFT                (8U)
/*! TRNG0 - Automatic clock control TRNG0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_GLB_ACC1_TRNG0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_ACC1_TRNG0_SHIFT)) & MRCC_GLB_ACC1_TRNG0_MASK)
/*! @} */

/*! @name GLB_PR0 - Peripheral Enable Configuration 0 */
/*! @{ */

#define MRCC_GLB_PR0_CTIMER0_MASK                (0x2U)
#define MRCC_GLB_PR0_CTIMER0_SHIFT               (1U)
/*! CTIMER0 - Enable/Disable CTIMER0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_CTIMER0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_CTIMER0_SHIFT)) & MRCC_GLB_PR0_CTIMER0_MASK)

#define MRCC_GLB_PR0_CTIMER1_MASK                (0x4U)
#define MRCC_GLB_PR0_CTIMER1_SHIFT               (2U)
/*! CTIMER1 - Enable/Disable CTIMER1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_CTIMER1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_CTIMER1_SHIFT)) & MRCC_GLB_PR0_CTIMER1_MASK)

#define MRCC_GLB_PR0_CTIMER2_MASK                (0x8U)
#define MRCC_GLB_PR0_CTIMER2_SHIFT               (3U)
/*! CTIMER2 - Enable/Disable CTIMER2
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_CTIMER2(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_CTIMER2_SHIFT)) & MRCC_GLB_PR0_CTIMER2_MASK)

#define MRCC_GLB_PR0_FREQME_MASK                 (0x10U)
#define MRCC_GLB_PR0_FREQME_SHIFT                (4U)
/*! FREQME - Enable/Disable FREQME
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_FREQME(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_FREQME_SHIFT)) & MRCC_GLB_PR0_FREQME_MASK)

#define MRCC_GLB_PR0_UTICK0_MASK                 (0x20U)
#define MRCC_GLB_PR0_UTICK0_SHIFT                (5U)
/*! UTICK0 - Enable/Disable UTICK0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_UTICK0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_UTICK0_SHIFT)) & MRCC_GLB_PR0_UTICK0_MASK)

#define MRCC_GLB_PR0_DMA0_MASK                   (0x80U)
#define MRCC_GLB_PR0_DMA0_SHIFT                  (7U)
/*! DMA0 - Enable/Disable DMA0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_DMA0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_DMA0_SHIFT)) & MRCC_GLB_PR0_DMA0_MASK)

#define MRCC_GLB_PR0_AOI0_MASK                   (0x100U)
#define MRCC_GLB_PR0_AOI0_SHIFT                  (8U)
/*! AOI0 - Enable/Disable AOI0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_AOI0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_AOI0_SHIFT)) & MRCC_GLB_PR0_AOI0_MASK)

#define MRCC_GLB_PR0_CRC_MASK                    (0x200U)
#define MRCC_GLB_PR0_CRC_SHIFT                   (9U)
/*! CRC - Enable/Disable CRC
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_CRC(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_CRC_SHIFT)) & MRCC_GLB_PR0_CRC_MASK)

#define MRCC_GLB_PR0_ERM0_MASK                   (0x400U)
#define MRCC_GLB_PR0_ERM0_SHIFT                  (10U)
/*! ERM0 - Enable/Disable ERM0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_ERM0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_ERM0_SHIFT)) & MRCC_GLB_PR0_ERM0_MASK)

#define MRCC_GLB_PR0_LPI2C0_MASK                 (0x4000U)
#define MRCC_GLB_PR0_LPI2C0_SHIFT                (14U)
/*! LPI2C0 - Enable/Disable LPI2C0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPI2C0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPI2C0_SHIFT)) & MRCC_GLB_PR0_LPI2C0_MASK)

#define MRCC_GLB_PR0_LPI2C1_MASK                 (0x8000U)
#define MRCC_GLB_PR0_LPI2C1_SHIFT                (15U)
/*! LPI2C1 - Enable/Disable LPI2C1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPI2C1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPI2C1_SHIFT)) & MRCC_GLB_PR0_LPI2C1_MASK)

#define MRCC_GLB_PR0_LPSPI0_MASK                 (0x10000U)
#define MRCC_GLB_PR0_LPSPI0_SHIFT                (16U)
/*! LPSPI0 - Enable/Disable LPSPI0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPSPI0(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPSPI0_SHIFT)) & MRCC_GLB_PR0_LPSPI0_MASK)

#define MRCC_GLB_PR0_LPSPI1_MASK                 (0x20000U)
#define MRCC_GLB_PR0_LPSPI1_SHIFT                (17U)
/*! LPSPI1 - Enable/Disable LPSPI1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPSPI1(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPSPI1_SHIFT)) & MRCC_GLB_PR0_LPSPI1_MASK)

#define MRCC_GLB_PR0_LPUART0_MASK                (0x40000U)
#define MRCC_GLB_PR0_LPUART0_SHIFT               (18U)
/*! LPUART0 - Enable/Disable LPUART0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPUART0(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPUART0_SHIFT)) & MRCC_GLB_PR0_LPUART0_MASK)

#define MRCC_GLB_PR0_ADC0_MASK                   (0x80000U)
#define MRCC_GLB_PR0_ADC0_SHIFT                  (19U)
/*! ADC0 - Enable/Disable ADC0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_ADC0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_ADC0_SHIFT)) & MRCC_GLB_PR0_ADC0_MASK)

#define MRCC_GLB_PR0_CMP0_MASK                   (0x200000U)
#define MRCC_GLB_PR0_CMP0_SHIFT                  (21U)
/*! CMP0 - Enable/Disable CMP0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_CMP0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_CMP0_SHIFT)) & MRCC_GLB_PR0_CMP0_MASK)

#define MRCC_GLB_PR0_DMA1_MASK                   (0x400000U)
#define MRCC_GLB_PR0_DMA1_SHIFT                  (22U)
/*! DMA1 - Enable/Disable DMA1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_DMA1(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_DMA1_SHIFT)) & MRCC_GLB_PR0_DMA1_MASK)

#define MRCC_GLB_PR0_GPIO1_MASK                  (0x1000000U)
#define MRCC_GLB_PR0_GPIO1_SHIFT                 (24U)
/*! GPIO1 - Enable/Disable GPIO1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_GPIO1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_GPIO1_SHIFT)) & MRCC_GLB_PR0_GPIO1_MASK)

#define MRCC_GLB_PR0_GPIO2_MASK                  (0x2000000U)
#define MRCC_GLB_PR0_GPIO2_SHIFT                 (25U)
/*! GPIO2 - Enable/Disable GPIO2
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_GPIO2(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_GPIO2_SHIFT)) & MRCC_GLB_PR0_GPIO2_MASK)

#define MRCC_GLB_PR0_GPIO3_MASK                  (0x4000000U)
#define MRCC_GLB_PR0_GPIO3_SHIFT                 (26U)
/*! GPIO3 - Enable/Disable GPIO3
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_GPIO3(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_GPIO3_SHIFT)) & MRCC_GLB_PR0_GPIO3_MASK)

#define MRCC_GLB_PR0_LPUART1_MASK                (0x8000000U)
#define MRCC_GLB_PR0_LPUART1_SHIFT               (27U)
/*! LPUART1 - Enable/Disable LPUART1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_LPUART1(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_LPUART1_SHIFT)) & MRCC_GLB_PR0_LPUART1_MASK)

#define MRCC_GLB_PR0_MTR_MASK                    (0x10000000U)
#define MRCC_GLB_PR0_MTR_SHIFT                   (28U)
/*! MTR - Enable/Disable MTR
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_MTR(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_MTR_SHIFT)) & MRCC_GLB_PR0_MTR_MASK)

#define MRCC_GLB_PR0_OSTIMER0_MASK               (0x20000000U)
#define MRCC_GLB_PR0_OSTIMER0_SHIFT              (29U)
/*! OSTIMER0 - Enable/Disable OSTIMER0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_OSTIMER0(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_OSTIMER0_SHIFT)) & MRCC_GLB_PR0_OSTIMER0_MASK)

#define MRCC_GLB_PR0_PGRP0_MASK                  (0x40000000U)
#define MRCC_GLB_PR0_PGRP0_SHIFT                 (30U)
/*! PGRP0 - Enable/Disable PERIPH_GROUP_0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_PGRP0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_PGRP0_SHIFT)) & MRCC_GLB_PR0_PGRP0_MASK)

#define MRCC_GLB_PR0_PGRP1_MASK                  (0x80000000U)
#define MRCC_GLB_PR0_PGRP1_SHIFT                 (31U)
/*! PGRP1 - Enable/Disable PERIPH_GROUP_1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR0_PGRP1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR0_PGRP1_SHIFT)) & MRCC_GLB_PR0_PGRP1_MASK)
/*! @} */

/*! @name GLB_PR1 - Global Enable Configuration 1 */
/*! @{ */

#define MRCC_GLB_PR1_PKC0_MASK                   (0x1U)
#define MRCC_GLB_PR1_PKC0_SHIFT                  (0U)
/*! PKC0 - Enable/Disable PKC0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_PKC0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_PKC0_SHIFT)) & MRCC_GLB_PR1_PKC0_MASK)

#define MRCC_GLB_PR1_PORT1_MASK                  (0x2U)
#define MRCC_GLB_PR1_PORT1_SHIFT                 (1U)
/*! PORT1 - Enable/Disable PORT1
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_PORT1(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_PORT1_SHIFT)) & MRCC_GLB_PR1_PORT1_MASK)

#define MRCC_GLB_PR1_PORT2_MASK                  (0x4U)
#define MRCC_GLB_PR1_PORT2_SHIFT                 (2U)
/*! PORT2 - Enable/Disable PORT2
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_PORT2(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_PORT2_SHIFT)) & MRCC_GLB_PR1_PORT2_MASK)

#define MRCC_GLB_PR1_PORT3_MASK                  (0x8U)
#define MRCC_GLB_PR1_PORT3_SHIFT                 (3U)
/*! PORT3 - Enable/Disable PORT3
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_PORT3(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_PORT3_SHIFT)) & MRCC_GLB_PR1_PORT3_MASK)

#define MRCC_GLB_PR1_SGI0_MASK                   (0x20U)
#define MRCC_GLB_PR1_SGI0_SHIFT                  (5U)
/*! SGI0 - Enable/Disable SGI0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_SGI0(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_SGI0_SHIFT)) & MRCC_GLB_PR1_SGI0_MASK)

#define MRCC_GLB_PR1_SLCD0_MASK                  (0x40U)
#define MRCC_GLB_PR1_SLCD0_SHIFT                 (6U)
/*! SLCD0 - Enable/Disable SLCD0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_SLCD0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_SLCD0_SHIFT)) & MRCC_GLB_PR1_SLCD0_MASK)

#define MRCC_GLB_PR1_TCU_MASK                    (0x80U)
#define MRCC_GLB_PR1_TCU_SHIFT                   (7U)
/*! TCU - Enable/Disable TCU
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_TCU(x)                      (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_TCU_SHIFT)) & MRCC_GLB_PR1_TCU_MASK)

#define MRCC_GLB_PR1_TRNG0_MASK                  (0x100U)
#define MRCC_GLB_PR1_TRNG0_SHIFT                 (8U)
/*! TRNG0 - Enable/Disable TRNG0
 *  0b0..Peripheral is disabled
 *  0b1..Peripheral is enabled
 */
#define MRCC_GLB_PR1_TRNG0(x)                    (((uint32_t)(((uint32_t)(x)) << MRCC_GLB_PR1_TRNG0_SHIFT)) & MRCC_GLB_PR1_TRNG0_MASK)
/*! @} */

/*! @name CTIMERGRP0CLKSEL - CTIMER_Group_0 clock selection control */
/*! @{ */

#define MRCC_CTIMERGRP0CLKSEL_MUX_MASK           (0x3U)
#define MRCC_CTIMERGRP0CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..CLK_16K
 *  0b11..FRO_HF_DIV
 */
#define MRCC_CTIMERGRP0CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP0CLKSEL_MUX_SHIFT)) & MRCC_CTIMERGRP0CLKSEL_MUX_MASK)
/*! @} */

/*! @name CTIMERGRP0CLKDIV - CTIMER_Group_0 clock divider control */
/*! @{ */

#define MRCC_CTIMERGRP0CLKDIV_DIV_MASK           (0xFU)
#define MRCC_CTIMERGRP0CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_CTIMERGRP0CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP0CLKDIV_DIV_SHIFT)) & MRCC_CTIMERGRP0CLKDIV_DIV_MASK)

#define MRCC_CTIMERGRP0CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_CTIMERGRP0CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_CTIMERGRP0CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP0CLKDIV_RESET_SHIFT)) & MRCC_CTIMERGRP0CLKDIV_RESET_MASK)

#define MRCC_CTIMERGRP0CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_CTIMERGRP0CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_CTIMERGRP0CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP0CLKDIV_HALT_SHIFT)) & MRCC_CTIMERGRP0CLKDIV_HALT_MASK)

#define MRCC_CTIMERGRP0CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_CTIMERGRP0CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_CTIMERGRP0CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP0CLKDIV_UNSTAB_SHIFT)) & MRCC_CTIMERGRP0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CTIMERGRP1CLKSEL - CTIMER_Group_1 clock selection control */
/*! @{ */

#define MRCC_CTIMERGRP1CLKSEL_MUX_MASK           (0x3U)
#define MRCC_CTIMERGRP1CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..CLK_16K
 *  0b11..FRO_HF_DIV
 */
#define MRCC_CTIMERGRP1CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP1CLKSEL_MUX_SHIFT)) & MRCC_CTIMERGRP1CLKSEL_MUX_MASK)
/*! @} */

/*! @name CTIMERGRP1CLKDIV - CTIMER_Group_1 clock divider control */
/*! @{ */

#define MRCC_CTIMERGRP1CLKDIV_DIV_MASK           (0xFU)
#define MRCC_CTIMERGRP1CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_CTIMERGRP1CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP1CLKDIV_DIV_SHIFT)) & MRCC_CTIMERGRP1CLKDIV_DIV_MASK)

#define MRCC_CTIMERGRP1CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_CTIMERGRP1CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_CTIMERGRP1CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP1CLKDIV_RESET_SHIFT)) & MRCC_CTIMERGRP1CLKDIV_RESET_MASK)

#define MRCC_CTIMERGRP1CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_CTIMERGRP1CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_CTIMERGRP1CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP1CLKDIV_HALT_SHIFT)) & MRCC_CTIMERGRP1CLKDIV_HALT_MASK)

#define MRCC_CTIMERGRP1CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_CTIMERGRP1CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_CTIMERGRP1CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_CTIMERGRP1CLKDIV_UNSTAB_SHIFT)) & MRCC_CTIMERGRP1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name UTICK0CLKSEL - UTICK0 clock selection control */
/*! @{ */

#define MRCC_UTICK0CLKSEL_MUX_MASK               (0x3U)
#define MRCC_UTICK0CLKSEL_MUX_SHIFT              (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..FRO12M
 */
#define MRCC_UTICK0CLKSEL_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_UTICK0CLKSEL_MUX_SHIFT)) & MRCC_UTICK0CLKSEL_MUX_MASK)
/*! @} */

/*! @name WWDT0CLKDIV - WWDT0 clock divider control */
/*! @{ */

#define MRCC_WWDT0CLKDIV_DIV_MASK                (0xFU)
#define MRCC_WWDT0CLKDIV_DIV_SHIFT               (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_WWDT0CLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_WWDT0CLKDIV_DIV_SHIFT)) & MRCC_WWDT0CLKDIV_DIV_MASK)

#define MRCC_WWDT0CLKDIV_RESET_MASK              (0x20000000U)
#define MRCC_WWDT0CLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_WWDT0CLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_WWDT0CLKDIV_RESET_SHIFT)) & MRCC_WWDT0CLKDIV_RESET_MASK)

#define MRCC_WWDT0CLKDIV_HALT_MASK               (0x40000000U)
#define MRCC_WWDT0CLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_WWDT0CLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_WWDT0CLKDIV_HALT_SHIFT)) & MRCC_WWDT0CLKDIV_HALT_MASK)

#define MRCC_WWDT0CLKDIV_UNSTAB_MASK             (0x80000000U)
#define MRCC_WWDT0CLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_WWDT0CLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_WWDT0CLKDIV_UNSTAB_SHIFT)) & MRCC_WWDT0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name ADC0CLKSEL - ADC0 clock selection control */
/*! @{ */

#define MRCC_ADC0CLKSEL_MUX_MASK                 (0x3U)
#define MRCC_ADC0CLKSEL_MUX_SHIFT                (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..
 *  0b11..FRO_HF_DIV
 */
#define MRCC_ADC0CLKSEL_MUX(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_ADC0CLKSEL_MUX_SHIFT)) & MRCC_ADC0CLKSEL_MUX_MASK)
/*! @} */

/*! @name ADC0CLKDIV - ADC0 clock divider control */
/*! @{ */

#define MRCC_ADC0CLKDIV_DIV_MASK                 (0xFU)
#define MRCC_ADC0CLKDIV_DIV_SHIFT                (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_ADC0CLKDIV_DIV(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_ADC0CLKDIV_DIV_SHIFT)) & MRCC_ADC0CLKDIV_DIV_MASK)

#define MRCC_ADC0CLKDIV_RESET_MASK               (0x20000000U)
#define MRCC_ADC0CLKDIV_RESET_SHIFT              (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_ADC0CLKDIV_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_ADC0CLKDIV_RESET_SHIFT)) & MRCC_ADC0CLKDIV_RESET_MASK)

#define MRCC_ADC0CLKDIV_HALT_MASK                (0x40000000U)
#define MRCC_ADC0CLKDIV_HALT_SHIFT               (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_ADC0CLKDIV_HALT(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_ADC0CLKDIV_HALT_SHIFT)) & MRCC_ADC0CLKDIV_HALT_MASK)

#define MRCC_ADC0CLKDIV_UNSTAB_MASK              (0x80000000U)
#define MRCC_ADC0CLKDIV_UNSTAB_SHIFT             (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_ADC0CLKDIV_UNSTAB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_ADC0CLKDIV_UNSTAB_SHIFT)) & MRCC_ADC0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP0FUNCCLKDIV - CMP0_FUNC clock divider control */
/*! @{ */

#define MRCC_CMP0FUNCCLKDIV_DIV_MASK             (0xFU)
#define MRCC_CMP0FUNCCLKDIV_DIV_SHIFT            (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_CMP0FUNCCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0FUNCCLKDIV_DIV_SHIFT)) & MRCC_CMP0FUNCCLKDIV_DIV_MASK)

#define MRCC_CMP0FUNCCLKDIV_RESET_MASK           (0x20000000U)
#define MRCC_CMP0FUNCCLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_CMP0FUNCCLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0FUNCCLKDIV_RESET_SHIFT)) & MRCC_CMP0FUNCCLKDIV_RESET_MASK)

#define MRCC_CMP0FUNCCLKDIV_HALT_MASK            (0x40000000U)
#define MRCC_CMP0FUNCCLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_CMP0FUNCCLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0FUNCCLKDIV_HALT_SHIFT)) & MRCC_CMP0FUNCCLKDIV_HALT_MASK)

#define MRCC_CMP0FUNCCLKDIV_UNSTAB_MASK          (0x80000000U)
#define MRCC_CMP0FUNCCLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_CMP0FUNCCLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0FUNCCLKDIV_UNSTAB_SHIFT)) & MRCC_CMP0FUNCCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CMP0RRCLKSEL - CMP0_RR clock selection control */
/*! @{ */

#define MRCC_CMP0RRCLKSEL_MUX_MASK               (0x3U)
#define MRCC_CMP0RRCLKSEL_MUX_SHIFT              (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..Reserved
 *  0b11..FRO_HF_DIV
 */
#define MRCC_CMP0RRCLKSEL_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0RRCLKSEL_MUX_SHIFT)) & MRCC_CMP0RRCLKSEL_MUX_MASK)
/*! @} */

/*! @name CMP0RRCLKDIV - CMP0_RR clock divider control */
/*! @{ */

#define MRCC_CMP0RRCLKDIV_DIV_MASK               (0xFU)
#define MRCC_CMP0RRCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_CMP0RRCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0RRCLKDIV_DIV_SHIFT)) & MRCC_CMP0RRCLKDIV_DIV_MASK)

#define MRCC_CMP0RRCLKDIV_RESET_MASK             (0x20000000U)
#define MRCC_CMP0RRCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_CMP0RRCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0RRCLKDIV_RESET_SHIFT)) & MRCC_CMP0RRCLKDIV_RESET_MASK)

#define MRCC_CMP0RRCLKDIV_HALT_MASK              (0x40000000U)
#define MRCC_CMP0RRCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_CMP0RRCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0RRCLKDIV_HALT_SHIFT)) & MRCC_CMP0RRCLKDIV_HALT_MASK)

#define MRCC_CMP0RRCLKDIV_UNSTAB_MASK            (0x80000000U)
#define MRCC_CMP0RRCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_CMP0RRCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_CMP0RRCLKDIV_UNSTAB_SHIFT)) & MRCC_CMP0RRCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name DBGTRACECLKSEL - DBG_TRACE clock selection control */
/*! @{ */

#define MRCC_DBGTRACECLKSEL_MUX_MASK             (0x3U)
#define MRCC_DBGTRACECLKSEL_MUX_SHIFT            (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved
 */
#define MRCC_DBGTRACECLKSEL_MUX(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_DBGTRACECLKSEL_MUX_SHIFT)) & MRCC_DBGTRACECLKSEL_MUX_MASK)
/*! @} */

/*! @name DBGTRACECLKDIV - DBG_TRACE clock divider control */
/*! @{ */

#define MRCC_DBGTRACECLKDIV_DIV_MASK             (0xFU)
#define MRCC_DBGTRACECLKDIV_DIV_SHIFT            (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_DBGTRACECLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_DBGTRACECLKDIV_DIV_SHIFT)) & MRCC_DBGTRACECLKDIV_DIV_MASK)

#define MRCC_DBGTRACECLKDIV_RESET_MASK           (0x20000000U)
#define MRCC_DBGTRACECLKDIV_RESET_SHIFT          (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_DBGTRACECLKDIV_RESET(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_DBGTRACECLKDIV_RESET_SHIFT)) & MRCC_DBGTRACECLKDIV_RESET_MASK)

#define MRCC_DBGTRACECLKDIV_HALT_MASK            (0x40000000U)
#define MRCC_DBGTRACECLKDIV_HALT_SHIFT           (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_DBGTRACECLKDIV_HALT(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_DBGTRACECLKDIV_HALT_SHIFT)) & MRCC_DBGTRACECLKDIV_HALT_MASK)

#define MRCC_DBGTRACECLKDIV_UNSTAB_MASK          (0x80000000U)
#define MRCC_DBGTRACECLKDIV_UNSTAB_SHIFT         (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_DBGTRACECLKDIV_UNSTAB(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_DBGTRACECLKDIV_UNSTAB_SHIFT)) & MRCC_DBGTRACECLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name CLKOUTCLKSEL - CLKOUT clock selection control */
/*! @{ */

#define MRCC_CLKOUTCLKSEL_MUX_MASK               (0x7U)
#define MRCC_CLKOUTCLKSEL_MUX_SHIFT              (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO12M
 *  0b001..SLOW_CLK
 *  0b011..CLK_16K
 *  0b101..FRO10M
 *  0b111..FRO_HF_DIV
 */
#define MRCC_CLKOUTCLKSEL_MUX(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_CLKOUTCLKSEL_MUX_SHIFT)) & MRCC_CLKOUTCLKSEL_MUX_MASK)
/*! @} */

/*! @name CLKOUTCLKDIV - CLKOUT clock divider control */
/*! @{ */

#define MRCC_CLKOUTCLKDIV_DIV_MASK               (0xFU)
#define MRCC_CLKOUTCLKDIV_DIV_SHIFT              (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_CLKOUTCLKDIV_DIV(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_CLKOUTCLKDIV_DIV_SHIFT)) & MRCC_CLKOUTCLKDIV_DIV_MASK)

#define MRCC_CLKOUTCLKDIV_RESET_MASK             (0x20000000U)
#define MRCC_CLKOUTCLKDIV_RESET_SHIFT            (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_CLKOUTCLKDIV_RESET(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_CLKOUTCLKDIV_RESET_SHIFT)) & MRCC_CLKOUTCLKDIV_RESET_MASK)

#define MRCC_CLKOUTCLKDIV_HALT_MASK              (0x40000000U)
#define MRCC_CLKOUTCLKDIV_HALT_SHIFT             (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_CLKOUTCLKDIV_HALT(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_CLKOUTCLKDIV_HALT_SHIFT)) & MRCC_CLKOUTCLKDIV_HALT_MASK)

#define MRCC_CLKOUTCLKDIV_UNSTAB_MASK            (0x80000000U)
#define MRCC_CLKOUTCLKDIV_UNSTAB_SHIFT           (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_CLKOUTCLKDIV_UNSTAB(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_CLKOUTCLKDIV_UNSTAB_SHIFT)) & MRCC_CLKOUTCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name OSTIMER0CLKSEL - OSTIMER0 clock selection control */
/*! @{ */

#define MRCC_OSTIMER0CLKSEL_MUX_MASK             (0x3U)
#define MRCC_OSTIMER0CLKSEL_MUX_SHIFT            (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CLK_16K[2]
 *  0b01..FRO_16K
 *  0b10..
 *  0b11..CLK_1M
 */
#define MRCC_OSTIMER0CLKSEL_MUX(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_OSTIMER0CLKSEL_MUX_SHIFT)) & MRCC_OSTIMER0CLKSEL_MUX_MASK)
/*! @} */

/*! @name PGRP0CLKSEL - PERIPH_GROUP_0 clock selection control */
/*! @{ */

#define MRCC_PGRP0CLKSEL_MUX_MASK                (0x3U)
#define MRCC_PGRP0CLKSEL_MUX_SHIFT               (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..CLK_16K
 *  0b11..FRO_HF_DIV
 */
#define MRCC_PGRP0CLKSEL_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP0CLKSEL_MUX_SHIFT)) & MRCC_PGRP0CLKSEL_MUX_MASK)
/*! @} */

/*! @name PGRP0CLKDIV - PERIPH_GROUP_0 clock divider control */
/*! @{ */

#define MRCC_PGRP0CLKDIV_DIV_MASK                (0xFU)
#define MRCC_PGRP0CLKDIV_DIV_SHIFT               (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_PGRP0CLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP0CLKDIV_DIV_SHIFT)) & MRCC_PGRP0CLKDIV_DIV_MASK)

#define MRCC_PGRP0CLKDIV_RESET_MASK              (0x20000000U)
#define MRCC_PGRP0CLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_PGRP0CLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP0CLKDIV_RESET_SHIFT)) & MRCC_PGRP0CLKDIV_RESET_MASK)

#define MRCC_PGRP0CLKDIV_HALT_MASK               (0x40000000U)
#define MRCC_PGRP0CLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_PGRP0CLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP0CLKDIV_HALT_SHIFT)) & MRCC_PGRP0CLKDIV_HALT_MASK)

#define MRCC_PGRP0CLKDIV_UNSTAB_MASK             (0x80000000U)
#define MRCC_PGRP0CLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_PGRP0CLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP0CLKDIV_UNSTAB_SHIFT)) & MRCC_PGRP0CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name PGRP1CLKSEL - PERIPH_GROUP_1 clock selection control */
/*! @{ */

#define MRCC_PGRP1CLKSEL_MUX_MASK                (0x3U)
#define MRCC_PGRP1CLKSEL_MUX_SHIFT               (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..FRO12M
 *  0b01..XTAL32K[2]
 *  0b10..CLK_16K
 *  0b11..FRO_HF_DIV
 */
#define MRCC_PGRP1CLKSEL_MUX(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP1CLKSEL_MUX_SHIFT)) & MRCC_PGRP1CLKSEL_MUX_MASK)
/*! @} */

/*! @name PGRP1CLKDIV - PERIPH_GROUP_1 clock divider control */
/*! @{ */

#define MRCC_PGRP1CLKDIV_DIV_MASK                (0xFU)
#define MRCC_PGRP1CLKDIV_DIV_SHIFT               (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_PGRP1CLKDIV_DIV(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP1CLKDIV_DIV_SHIFT)) & MRCC_PGRP1CLKDIV_DIV_MASK)

#define MRCC_PGRP1CLKDIV_RESET_MASK              (0x20000000U)
#define MRCC_PGRP1CLKDIV_RESET_SHIFT             (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_PGRP1CLKDIV_RESET(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP1CLKDIV_RESET_SHIFT)) & MRCC_PGRP1CLKDIV_RESET_MASK)

#define MRCC_PGRP1CLKDIV_HALT_MASK               (0x40000000U)
#define MRCC_PGRP1CLKDIV_HALT_SHIFT              (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_PGRP1CLKDIV_HALT(x)                 (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP1CLKDIV_HALT_SHIFT)) & MRCC_PGRP1CLKDIV_HALT_MASK)

#define MRCC_PGRP1CLKDIV_UNSTAB_MASK             (0x80000000U)
#define MRCC_PGRP1CLKDIV_UNSTAB_SHIFT            (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_PGRP1CLKDIV_UNSTAB(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_PGRP1CLKDIV_UNSTAB_SHIFT)) & MRCC_PGRP1CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name SYSTICKCLKSEL - SYSTICK clock selection control */
/*! @{ */

#define MRCC_SYSTICKCLKSEL_MUX_MASK              (0x3U)
#define MRCC_SYSTICKCLKSEL_MUX_SHIFT             (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved
 */
#define MRCC_SYSTICKCLKSEL_MUX(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_SYSTICKCLKSEL_MUX_SHIFT)) & MRCC_SYSTICKCLKSEL_MUX_MASK)
/*! @} */

/*! @name SYSTICKCLKDIV - SYSTICK clock divider control */
/*! @{ */

#define MRCC_SYSTICKCLKDIV_DIV_MASK              (0xFU)
#define MRCC_SYSTICKCLKDIV_DIV_SHIFT             (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_SYSTICKCLKDIV_DIV(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_SYSTICKCLKDIV_DIV_SHIFT)) & MRCC_SYSTICKCLKDIV_DIV_MASK)

#define MRCC_SYSTICKCLKDIV_RESET_MASK            (0x20000000U)
#define MRCC_SYSTICKCLKDIV_RESET_SHIFT           (29U)
/*! RESET - Resets divider counter
 *  0b0..Divider is not reset
 *  0b1..Divider is reset
 */
#define MRCC_SYSTICKCLKDIV_RESET(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_SYSTICKCLKDIV_RESET_SHIFT)) & MRCC_SYSTICKCLKDIV_RESET_MASK)

#define MRCC_SYSTICKCLKDIV_HALT_MASK             (0x40000000U)
#define MRCC_SYSTICKCLKDIV_HALT_SHIFT            (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_SYSTICKCLKDIV_HALT(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_SYSTICKCLKDIV_HALT_SHIFT)) & MRCC_SYSTICKCLKDIV_HALT_MASK)

#define MRCC_SYSTICKCLKDIV_UNSTAB_MASK           (0x80000000U)
#define MRCC_SYSTICKCLKDIV_UNSTAB_SHIFT          (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency is not stable
 */
#define MRCC_SYSTICKCLKDIV_UNSTAB(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_SYSTICKCLKDIV_UNSTAB_SHIFT)) & MRCC_SYSTICKCLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name FROHFDIV - FRO_HF_DIV clock divider control */
/*! @{ */

#define MRCC_FROHFDIV_DIV_MASK                   (0xFU)
#define MRCC_FROHFDIV_DIV_SHIFT                  (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_FROHFDIV_DIV(x)                     (((uint32_t)(((uint32_t)(x)) << MRCC_FROHFDIV_DIV_SHIFT)) & MRCC_FROHFDIV_DIV_MASK)

#define MRCC_FROHFDIV_UNSTAB_MASK                (0x80000000U)
#define MRCC_FROHFDIV_UNSTAB_SHIFT               (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..clock frequency isn't stable
 */
#define MRCC_FROHFDIV_UNSTAB(x)                  (((uint32_t)(((uint32_t)(x)) << MRCC_FROHFDIV_UNSTAB_SHIFT)) & MRCC_FROHFDIV_UNSTAB_MASK)
/*! @} */

/*! @name P16KCLKSEL - Clock selection control */
/*! @{ */

#define MRCC_P16KCLKSEL_MUX_MASK                 (0x1U)
#define MRCC_P16KCLKSEL_MUX_SHIFT                (0U)
/*! MUX - Functional Clock Mux Select
 *  0b0..FRO16K
 *  0b1..CLK_16K[2]
 */
#define MRCC_P16KCLKSEL_MUX(x)                   (((uint32_t)(((uint32_t)(x)) << MRCC_P16KCLKSEL_MUX_SHIFT)) & MRCC_P16KCLKSEL_MUX_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MRCC_Register_Masks */


/*!
 * @}
 */ /* end of group MRCC_Peripheral_Access_Layer */


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


#endif  /* PERI_MRCC_H_ */

