/*
** ###################################################################
**     Processors:          MCXA266VLH
**                          MCXA266VLL
**                          MCXA266VLQ
**                          MCXA266VPN
**                          MCXA345VLH
**                          MCXA345VLL
**                          MCXA345VLQ
**                          MCXA345VPN
**                          MCXA346VLH
**                          MCXA346VLL
**                          MCXA346VLQ
**                          MCXA346VPN
**                          MCXA366VLH
**                          MCXA366VLL
**                          MCXA366VLQ
**                          MCXA366VPN
**
**     Version:             rev. 1.0, 2024-11-21
**     Build:               b250729
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
**     - rev. 1.0 (2024-11-21)
**         Initial version based on Rev1 RM
**
** ###################################################################
*/

/*!
 * @file PERI_MRCC.h
 * @version 1.0
 * @date 2024-11-21
 * @brief CMSIS Peripheral Access Layer for MRCC
 *
 * CMSIS Peripheral Access Layer for MRCC
 */

#if !defined(PERI_MRCC_H_)
#define PERI_MRCC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCXA266VLH) || defined(CPU_MCXA266VLL) || defined(CPU_MCXA266VLQ) || defined(CPU_MCXA266VPN))
#include "MCXA266_COMMON.h"
#elif (defined(CPU_MCXA345VLH) || defined(CPU_MCXA345VLL) || defined(CPU_MCXA345VLQ) || defined(CPU_MCXA345VPN))
#include "MCXA345_COMMON.h"
#elif (defined(CPU_MCXA346VLH) || defined(CPU_MCXA346VLL) || defined(CPU_MCXA346VLQ) || defined(CPU_MCXA346VPN))
#include "MCXA346_COMMON.h"
#elif (defined(CPU_MCXA366VLH) || defined(CPU_MCXA366VLL) || defined(CPU_MCXA366VLQ) || defined(CPU_MCXA366VPN))
#include "MCXA366_COMMON.h"
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
  __IO uint32_t MRCC_GLB_RST0;                     /**< Peripheral Reset Control 0, offset: 0x0 */
  __O  uint32_t MRCC_GLB_RST0_SET;                 /**< Peripheral Reset Control Set 0, offset: 0x4 */
  __O  uint32_t MRCC_GLB_RST0_CLR;                 /**< Peripheral Reset Control Clear 0, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t MRCC_GLB_RST1;                     /**< Peripheral Reset Control 1, offset: 0x10 */
  __O  uint32_t MRCC_GLB_RST1_SET;                 /**< Peripheral Reset Control Set 1, offset: 0x14 */
  __O  uint32_t MRCC_GLB_RST1_CLR;                 /**< Peripheral Reset Control Clear 1, offset: 0x18 */
       uint8_t RESERVED_1[4];
  __IO uint32_t MRCC_GLB_RST2;                     /**< Peripheral Reset Control 2, offset: 0x20 */
  __O  uint32_t MRCC_GLB_RST2_SET;                 /**< Peripheral Reset Control Set 2, offset: 0x24 */
  __O  uint32_t MRCC_GLB_RST2_CLR;                 /**< Peripheral Reset Control Clear 2, offset: 0x28 */
       uint8_t RESERVED_2[20];
  __IO uint32_t MRCC_GLB_CC0;                      /**< AHB Clock Control 0, offset: 0x40 */
  __O  uint32_t MRCC_GLB_CC0_SET;                  /**< AHB Clock Control Set 0, offset: 0x44 */
  __O  uint32_t MRCC_GLB_CC0_CLR;                  /**< AHB Clock Control Clear 0, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MRCC_GLB_CC1;                      /**< AHB Clock Control 1, offset: 0x50 */
  __O  uint32_t MRCC_GLB_CC1_SET;                  /**< AHB Clock Control Set 1, offset: 0x54 */
  __O  uint32_t MRCC_GLB_CC1_CLR;                  /**< AHB Clock Control Clear 1, offset: 0x58 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MRCC_GLB_CC2;                      /**< AHB Clock Control 2, offset: 0x60 */
  __O  uint32_t MRCC_GLB_CC2_SET;                  /**< AHB Clock Control Set 2, offset: 0x64 */
  __O  uint32_t MRCC_GLB_CC2_CLR;                  /**< AHB Clock Control Clear 2, offset: 0x68 */
       uint8_t RESERVED_5[20];
  __IO uint32_t MRCC_GLB_ACC0;                     /**< Control Automatic Clock Gating 0, offset: 0x80 */
  __IO uint32_t MRCC_GLB_ACC1;                     /**< Control Automatic Clock Gating 1, offset: 0x84 */
  __IO uint32_t MRCC_GLB_ACC2;                     /**< Control Automatic Clock Gating 2, offset: 0x88 */
       uint8_t RESERVED_6[20];
  __IO uint32_t MRCC_I3C0_FCLK_CLKSEL;             /**< I3C0_FCLK clock selection control, offset: 0xA0 */
  __IO uint32_t MRCC_I3C0_FCLK_CLKDIV;             /**< I3C0_FCLK clock divider control, offset: 0xA4 */
  __IO uint32_t MRCC_CTIMER0_CLKSEL;               /**< CTIMER0 clock selection control, offset: 0xA8 */
  __IO uint32_t MRCC_CTIMER0_CLKDIV;               /**< CTIMER0 clock divider control, offset: 0xAC */
  __IO uint32_t MRCC_CTIMER1_CLKSEL;               /**< CTIMER1 clock selection control, offset: 0xB0 */
  __IO uint32_t MRCC_CTIMER1_CLKDIV;               /**< CTIMER1 clock divider control, offset: 0xB4 */
  __IO uint32_t MRCC_CTIMER2_CLKSEL;               /**< CTIMER2 clock selection control, offset: 0xB8 */
  __IO uint32_t MRCC_CTIMER2_CLKDIV;               /**< CTIMER2 clock divider control, offset: 0xBC */
  __IO uint32_t MRCC_CTIMER3_CLKSEL;               /**< CTIMER3 clock selection control, offset: 0xC0 */
  __IO uint32_t MRCC_CTIMER3_CLKDIV;               /**< CTIMER3 clock divider control, offset: 0xC4 */
  __IO uint32_t MRCC_CTIMER4_CLKSEL;               /**< CTIMER4 clock selection control, offset: 0xC8 */
  __IO uint32_t MRCC_CTIMER4_CLKDIV;               /**< CTIMER4 clock divider control, offset: 0xCC */
       uint8_t RESERVED_7[4];
  __IO uint32_t MRCC_WWDT0_CLKDIV;                 /**< WWDT0 clock divider control, offset: 0xD4 */
  __IO uint32_t MRCC_FLEXIO0_CLKSEL;               /**< FLEXIO0 clock selection control, offset: 0xD8 */
  __IO uint32_t MRCC_FLEXIO0_CLKDIV;               /**< FLEXIO0 clock divider control, offset: 0xDC */
  __IO uint32_t MRCC_LPI2C0_CLKSEL;                /**< LPI2C0 clock selection control, offset: 0xE0 */
  __IO uint32_t MRCC_LPI2C0_CLKDIV;                /**< LPI2C0 clock divider control, offset: 0xE4 */
  __IO uint32_t MRCC_LPI2C1_CLKSEL;                /**< LPI2C1 clock selection control, offset: 0xE8 */
  __IO uint32_t MRCC_LPI2C1_CLKDIV;                /**< LPI2C1 clock divider control, offset: 0xEC */
  __IO uint32_t MRCC_LPSPI0_CLKSEL;                /**< LPSPI0 clock selection control, offset: 0xF0 */
  __IO uint32_t MRCC_LPSPI0_CLKDIV;                /**< LPSPI0 clock divider control, offset: 0xF4 */
  __IO uint32_t MRCC_LPSPI1_CLKSEL;                /**< LPSPI1 clock selection control, offset: 0xF8 */
  __IO uint32_t MRCC_LPSPI1_CLKDIV;                /**< LPSPI1 clock divider control, offset: 0xFC */
  __IO uint32_t MRCC_LPUART0_CLKSEL;               /**< LPUART0 clock selection control, offset: 0x100 */
  __IO uint32_t MRCC_LPUART0_CLKDIV;               /**< LPUART0 clock divider control, offset: 0x104 */
  __IO uint32_t MRCC_LPUART1_CLKSEL;               /**< LPUART1 clock selection control, offset: 0x108 */
  __IO uint32_t MRCC_LPUART1_CLKDIV;               /**< LPUART1 clock divider control, offset: 0x10C */
  __IO uint32_t MRCC_LPUART2_CLKSEL;               /**< LPUART2 clock selection control, offset: 0x110 */
  __IO uint32_t MRCC_LPUART2_CLKDIV;               /**< LPUART2 clock divider control, offset: 0x114 */
  __IO uint32_t MRCC_LPUART3_CLKSEL;               /**< LPUART3 clock selection control, offset: 0x118 */
  __IO uint32_t MRCC_LPUART3_CLKDIV;               /**< LPUART3 clock divider control, offset: 0x11C */
  __IO uint32_t MRCC_LPUART4_CLKSEL;               /**< LPUART4 clock selection control, offset: 0x120 */
  __IO uint32_t MRCC_LPUART4_CLKDIV;               /**< LPUART4 clock divider control, offset: 0x124 */
  __IO uint32_t MRCC_USB0_CLKSEL;                  /**< USB0 clock selection control, offset: 0x128 */
  __IO uint32_t MRCC_USB0_CLKDIV;                  /**< USB0 clock divider control, offset: 0x12C */
  __IO uint32_t MRCC_LPTMR0_CLKSEL;                /**< LPTMR0 clock selection control, offset: 0x130 */
  __IO uint32_t MRCC_LPTMR0_CLKDIV;                /**< LPTMR0 clock divider control, offset: 0x134 */
  __IO uint32_t MRCC_OSTIMER0_CLKSEL;              /**< OSTIMER0 clock selection control, offset: 0x138 */
       uint8_t RESERVED_8[4];
  __IO uint32_t MRCC_ADC_CLKSEL;                   /**< ADCx clock selection control, offset: 0x140 */
  __IO uint32_t MRCC_ADC_CLKDIV;                   /**< ADCx clock divider control, offset: 0x144 */
       uint8_t RESERVED_9[4];
  __IO uint32_t MRCC_CMP0_FUNC_CLKDIV;             /**< CMP0_FUNC clock divider control, offset: 0x14C */
  __IO uint32_t MRCC_CMP0_RR_CLKSEL;               /**< CMP0_RR clock selection control, offset: 0x150 */
  __IO uint32_t MRCC_CMP0_RR_CLKDIV;               /**< CMP0_RR clock divider control, offset: 0x154 */
       uint8_t RESERVED_10[4];
  __IO uint32_t MRCC_CMP1_FUNC_CLKDIV;             /**< CMP1_FUNC clock divider control, offset: 0x15C */
  __IO uint32_t MRCC_CMP1_RR_CLKSEL;               /**< CMP1_RR clock selection control, offset: 0x160 */
  __IO uint32_t MRCC_CMP1_RR_CLKDIV;               /**< CMP1_RR clock divider control, offset: 0x164 */
       uint8_t RESERVED_11[4];
  __IO uint32_t MRCC_CMP2_FUNC_CLKDIV;             /**< CMP2_FUNC clock divider control, offset: 0x16C */
  __IO uint32_t MRCC_CMP2_RR_CLKSEL;               /**< CMP2_RR clock selection control, offset: 0x170 */
  __IO uint32_t MRCC_CMP2_RR_CLKDIV;               /**< CMP2_RR clock divider control, offset: 0x174 */
  __IO uint32_t MRCC_DAC0_CLKSEL;                  /**< DAC0 clock selection control, offset: 0x178 */
  __IO uint32_t MRCC_DAC0_CLKDIV;                  /**< DAC0 clock divider control, offset: 0x17C */
  __IO uint32_t MRCC_FLEXCAN0_CLKSEL;              /**< FLEXCAN0 clock selection control, offset: 0x180 */
  __IO uint32_t MRCC_FLEXCAN0_CLKDIV;              /**< FLEXCAN0 clock divider control, offset: 0x184 */
  __IO uint32_t MRCC_FLEXCAN1_CLKSEL;              /**< FLEXCAN1 clock selection control, offset: 0x188 */
  __IO uint32_t MRCC_FLEXCAN1_CLKDIV;              /**< FLEXCAN1 clock divider control, offset: 0x18C */
  __IO uint32_t MRCC_LPI2C2_CLKSEL;                /**< LPI2C2 clock selection control, offset: 0x190 */
  __IO uint32_t MRCC_LPI2C2_CLKDIV;                /**< LPI2C2 clock divider control, offset: 0x194 */
  __IO uint32_t MRCC_LPI2C3_CLKSEL;                /**< LPI2C3 clock selection control, offset: 0x198 */
  __IO uint32_t MRCC_LPI2C3_CLKDIV;                /**< LPI2C3 clock divider control, offset: 0x19C */
  __IO uint32_t MRCC_LPUART5_CLKSEL;               /**< LPUART5 clock selection control, offset: 0x1A0 */
  __IO uint32_t MRCC_LPUART5_CLKDIV;               /**< LPUART5 clock divider control, offset: 0x1A4 */
  __IO uint32_t MRCC_DBG_TRACE_CLKSEL;             /**< DBG_TRACE clock selection control, offset: 0x1A8 */
  __IO uint32_t MRCC_DBG_TRACE_CLKDIV;             /**< DBG_TRACE clock divider control, offset: 0x1AC */
  __IO uint32_t MRCC_CLKOUT_CLKSEL;                /**< CLKOUT clock selection control, offset: 0x1B0 */
  __IO uint32_t MRCC_CLKOUT_CLKDIV;                /**< CLKOUT clock divider control, offset: 0x1B4 */
  __IO uint32_t MRCC_SYSTICK_CLKSEL;               /**< SYSTICK clock selection control, offset: 0x1B8 */
  __IO uint32_t MRCC_SYSTICK_CLKDIV;               /**< SYSTICK clock divider control, offset: 0x1BC */
} MRCC_Type;

/* ----------------------------------------------------------------------------
   -- MRCC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MRCC_Register_Masks MRCC Register Masks
 * @{
 */

/*! @name MRCC_GLB_RST0 - Peripheral Reset Control 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_INPUTMUX0_MASK        (0x1U)
#define MRCC_MRCC_GLB_RST0_INPUTMUX0_SHIFT       (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_INPUTMUX0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_RST0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_RST0_I3C0_MASK             (0x2U)
#define MRCC_MRCC_GLB_RST0_I3C0_SHIFT            (1U)
/*! I3C0 - I3C0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_I3C0_SHIFT)) & MRCC_MRCC_GLB_RST0_I3C0_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER0_MASK          (0x4U)
#define MRCC_MRCC_GLB_RST0_CTIMER0_SHIFT         (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER1_MASK          (0x8U)
#define MRCC_MRCC_GLB_RST0_CTIMER1_SHIFT         (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER2_MASK          (0x10U)
#define MRCC_MRCC_GLB_RST0_CTIMER2_SHIFT         (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER3_MASK          (0x20U)
#define MRCC_MRCC_GLB_RST0_CTIMER3_SHIFT         (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_RST0_CTIMER4_MASK          (0x40U)
#define MRCC_MRCC_GLB_RST0_CTIMER4_SHIFT         (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CTIMER4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_RST0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_RST0_FREQME_MASK           (0x80U)
#define MRCC_MRCC_GLB_RST0_FREQME_SHIFT          (7U)
/*! FREQME - FREQME
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_FREQME_SHIFT)) & MRCC_MRCC_GLB_RST0_FREQME_MASK)

#define MRCC_MRCC_GLB_RST0_UTICK0_MASK           (0x100U)
#define MRCC_MRCC_GLB_RST0_UTICK0_SHIFT          (8U)
/*! UTICK0 - UTICK0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_UTICK0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_RST0_UTICK0_MASK)

#define MRCC_MRCC_GLB_RST0_SMARTDMA0_MASK        (0x400U)
#define MRCC_MRCC_GLB_RST0_SMARTDMA0_SHIFT       (10U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_SMARTDMA0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_RST0_SMARTDMA0_MASK)

#define MRCC_MRCC_GLB_RST0_DMA0_MASK             (0x800U)
#define MRCC_MRCC_GLB_RST0_DMA0_SHIFT            (11U)
/*! DMA0 - DMA0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_DMA0_SHIFT)) & MRCC_MRCC_GLB_RST0_DMA0_MASK)

#define MRCC_MRCC_GLB_RST0_AOI0_MASK             (0x1000U)
#define MRCC_MRCC_GLB_RST0_AOI0_SHIFT            (12U)
/*! AOI0 - AOI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_AOI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_AOI0_SHIFT)) & MRCC_MRCC_GLB_RST0_AOI0_MASK)

#define MRCC_MRCC_GLB_RST0_CRC0_MASK             (0x2000U)
#define MRCC_MRCC_GLB_RST0_CRC0_SHIFT            (13U)
/*! CRC0 - CRC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_CRC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CRC0_SHIFT)) & MRCC_MRCC_GLB_RST0_CRC0_MASK)

#define MRCC_MRCC_GLB_RST0_EIM0_MASK             (0x4000U)
#define MRCC_MRCC_GLB_RST0_EIM0_SHIFT            (14U)
/*! EIM0 - EIM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_EIM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_EIM0_SHIFT)) & MRCC_MRCC_GLB_RST0_EIM0_MASK)

#define MRCC_MRCC_GLB_RST0_ERM0_MASK             (0x8000U)
#define MRCC_MRCC_GLB_RST0_ERM0_SHIFT            (15U)
/*! ERM0 - ERM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_ERM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_ERM0_SHIFT)) & MRCC_MRCC_GLB_RST0_ERM0_MASK)

#define MRCC_MRCC_GLB_RST0_AOI1_MASK             (0x20000U)
#define MRCC_MRCC_GLB_RST0_AOI1_SHIFT            (17U)
/*! AOI1 - AOI1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_AOI1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_AOI1_SHIFT)) & MRCC_MRCC_GLB_RST0_AOI1_MASK)

#define MRCC_MRCC_GLB_RST0_FLEXIO0_MASK          (0x40000U)
#define MRCC_MRCC_GLB_RST0_FLEXIO0_SHIFT         (18U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_FLEXIO0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_RST0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C0_MASK           (0x80000U)
#define MRCC_MRCC_GLB_RST0_LPI2C0_SHIFT          (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_RST0_LPI2C1_MASK           (0x100000U)
#define MRCC_MRCC_GLB_RST0_LPI2C1_SHIFT          (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPI2C1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_RST0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_RST0_LPSPI0_MASK           (0x200000U)
#define MRCC_MRCC_GLB_RST0_LPSPI0_SHIFT          (21U)
/*! LPSPI0 - LPSPI0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPSPI0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_RST0_LPSPI0_MASK)

#define MRCC_MRCC_GLB_RST0_LPSPI1_MASK           (0x400000U)
#define MRCC_MRCC_GLB_RST0_LPSPI1_SHIFT          (22U)
/*! LPSPI1 - LPSPI1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPSPI1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_RST0_LPSPI1_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART0_MASK          (0x800000U)
#define MRCC_MRCC_GLB_RST0_LPUART0_SHIFT         (23U)
/*! LPUART0 - LPUART0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART0_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART1_MASK          (0x1000000U)
#define MRCC_MRCC_GLB_RST0_LPUART1_SHIFT         (24U)
/*! LPUART1 - LPUART1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART1_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART2_MASK          (0x2000000U)
#define MRCC_MRCC_GLB_RST0_LPUART2_SHIFT         (25U)
/*! LPUART2 - LPUART2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART2_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART3_MASK          (0x4000000U)
#define MRCC_MRCC_GLB_RST0_LPUART3_SHIFT         (26U)
/*! LPUART3 - LPUART3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART3_MASK)

#define MRCC_MRCC_GLB_RST0_LPUART4_MASK          (0x8000000U)
#define MRCC_MRCC_GLB_RST0_LPUART4_SHIFT         (27U)
/*! LPUART4 - LPUART4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_LPUART4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_RST0_LPUART4_MASK)

#define MRCC_MRCC_GLB_RST0_USB0_MASK             (0x10000000U)
#define MRCC_MRCC_GLB_RST0_USB0_SHIFT            (28U)
/*! USB0 - USB0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_USB0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_USB0_SHIFT)) & MRCC_MRCC_GLB_RST0_USB0_MASK)

#define MRCC_MRCC_GLB_RST0_QDC0_MASK             (0x20000000U)
#define MRCC_MRCC_GLB_RST0_QDC0_SHIFT            (29U)
/*! QDC0 - QDC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_QDC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_QDC0_SHIFT)) & MRCC_MRCC_GLB_RST0_QDC0_MASK)

#define MRCC_MRCC_GLB_RST0_QDC1_MASK             (0x40000000U)
#define MRCC_MRCC_GLB_RST0_QDC1_SHIFT            (30U)
/*! QDC1 - QDC1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_QDC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_QDC1_SHIFT)) & MRCC_MRCC_GLB_RST0_QDC1_MASK)

#define MRCC_MRCC_GLB_RST0_FLEXPWM0_MASK         (0x80000000U)
#define MRCC_MRCC_GLB_RST0_FLEXPWM0_SHIFT        (31U)
/*! FLEXPWM0 - FLEXPWM0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST0_FLEXPWM0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_FLEXPWM0_SHIFT)) & MRCC_MRCC_GLB_RST0_FLEXPWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST0_SET - Peripheral Reset Control Set 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST0_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST0_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST0_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST0_CLR - Peripheral Reset Control Clear 0 */
/*! @{ */

#define MRCC_MRCC_GLB_RST0_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST0_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST0_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST0_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST0_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1 - Peripheral Reset Control 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_FLEXPWM1_MASK         (0x1U)
#define MRCC_MRCC_GLB_RST1_FLEXPWM1_SHIFT        (0U)
/*! FLEXPWM1 - FLEXPWM1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_FLEXPWM1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_FLEXPWM1_SHIFT)) & MRCC_MRCC_GLB_RST1_FLEXPWM1_MASK)

#define MRCC_MRCC_GLB_RST1_OSTIMER0_MASK         (0x2U)
#define MRCC_MRCC_GLB_RST1_OSTIMER0_SHIFT        (1U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_OSTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_RST1_OSTIMER0_MASK)

#define MRCC_MRCC_GLB_RST1_ADC0_MASK             (0x4U)
#define MRCC_MRCC_GLB_RST1_ADC0_SHIFT            (2U)
/*! ADC0 - ADC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC0_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC0_MASK)

#define MRCC_MRCC_GLB_RST1_ADC1_MASK             (0x8U)
#define MRCC_MRCC_GLB_RST1_ADC1_SHIFT            (3U)
/*! ADC1 - ADC1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC1_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC1_MASK)

#define MRCC_MRCC_GLB_RST1_CMP1_MASK             (0x20U)
#define MRCC_MRCC_GLB_RST1_CMP1_SHIFT            (5U)
/*! CMP1 - CMP1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_CMP1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_CMP1_SHIFT)) & MRCC_MRCC_GLB_RST1_CMP1_MASK)

#define MRCC_MRCC_GLB_RST1_CMP2_MASK             (0x40U)
#define MRCC_MRCC_GLB_RST1_CMP2_SHIFT            (6U)
/*! CMP2 - CMP2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_CMP2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_CMP2_SHIFT)) & MRCC_MRCC_GLB_RST1_CMP2_MASK)

#define MRCC_MRCC_GLB_RST1_DAC0_MASK             (0x80U)
#define MRCC_MRCC_GLB_RST1_DAC0_SHIFT            (7U)
/*! DAC0 - DAC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_DAC0_SHIFT)) & MRCC_MRCC_GLB_RST1_DAC0_MASK)

#define MRCC_MRCC_GLB_RST1_OPAMP0_MASK           (0x100U)
#define MRCC_MRCC_GLB_RST1_OPAMP0_SHIFT          (8U)
/*! OPAMP0 - OPAMP0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_OPAMP0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_OPAMP0_SHIFT)) & MRCC_MRCC_GLB_RST1_OPAMP0_MASK)

#define MRCC_MRCC_GLB_RST1_OPAMP1_MASK           (0x200U)
#define MRCC_MRCC_GLB_RST1_OPAMP1_SHIFT          (9U)
/*! OPAMP1 - OPAMP1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_OPAMP1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_OPAMP1_SHIFT)) & MRCC_MRCC_GLB_RST1_OPAMP1_MASK)

#define MRCC_MRCC_GLB_RST1_OPAMP2_MASK           (0x400U)
#define MRCC_MRCC_GLB_RST1_OPAMP2_SHIFT          (10U)
/*! OPAMP2 - OPAMP2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_OPAMP2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_OPAMP2_SHIFT)) & MRCC_MRCC_GLB_RST1_OPAMP2_MASK)

#define MRCC_MRCC_GLB_RST1_OPAMP3_MASK           (0x800U)
#define MRCC_MRCC_GLB_RST1_OPAMP3_SHIFT          (11U)
/*! OPAMP3 - OPAMP3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_OPAMP3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_OPAMP3_SHIFT)) & MRCC_MRCC_GLB_RST1_OPAMP3_MASK)

#define MRCC_MRCC_GLB_RST1_PORT0_MASK            (0x1000U)
#define MRCC_MRCC_GLB_RST1_PORT0_SHIFT           (12U)
/*! PORT0 - PORT0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT0_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT0_MASK)

#define MRCC_MRCC_GLB_RST1_PORT1_MASK            (0x2000U)
#define MRCC_MRCC_GLB_RST1_PORT1_SHIFT           (13U)
/*! PORT1 - PORT1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT1_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT1_MASK)

#define MRCC_MRCC_GLB_RST1_PORT2_MASK            (0x4000U)
#define MRCC_MRCC_GLB_RST1_PORT2_SHIFT           (14U)
/*! PORT2 - PORT2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT2_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT2_MASK)

#define MRCC_MRCC_GLB_RST1_PORT3_MASK            (0x8000U)
#define MRCC_MRCC_GLB_RST1_PORT3_SHIFT           (15U)
/*! PORT3 - PORT3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT3_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT3_MASK)

#define MRCC_MRCC_GLB_RST1_PORT4_MASK            (0x10000U)
#define MRCC_MRCC_GLB_RST1_PORT4_SHIFT           (16U)
/*! PORT4 - PORT4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PORT4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PORT4_SHIFT)) & MRCC_MRCC_GLB_RST1_PORT4_MASK)

#define MRCC_MRCC_GLB_RST1_SLCD0_MASK            (0x20000U)
#define MRCC_MRCC_GLB_RST1_SLCD0_SHIFT           (17U)
/*! SLCD0 - SLCD0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_SLCD0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_SLCD0_SHIFT)) & MRCC_MRCC_GLB_RST1_SLCD0_MASK)

#define MRCC_MRCC_GLB_RST1_FLEXCAN0_MASK         (0x40000U)
#define MRCC_MRCC_GLB_RST1_FLEXCAN0_SHIFT        (18U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_FLEXCAN0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_RST1_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_RST1_FLEXCAN1_MASK         (0x80000U)
#define MRCC_MRCC_GLB_RST1_FLEXCAN1_SHIFT        (19U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_FLEXCAN1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_RST1_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_RST1_LPI2C2_MASK           (0x100000U)
#define MRCC_MRCC_GLB_RST1_LPI2C2_SHIFT          (20U)
/*! LPI2C2 - LPI2C2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPI2C2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_RST1_LPI2C2_MASK)

#define MRCC_MRCC_GLB_RST1_LPI2C3_MASK           (0x200000U)
#define MRCC_MRCC_GLB_RST1_LPI2C3_SHIFT          (21U)
/*! LPI2C3 - LPI2C3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPI2C3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_RST1_LPI2C3_MASK)

#define MRCC_MRCC_GLB_RST1_LPUART5_MASK          (0x400000U)
#define MRCC_MRCC_GLB_RST1_LPUART5_SHIFT         (22U)
/*! LPUART5 - LPUART5
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_LPUART5(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_LPUART5_SHIFT)) & MRCC_MRCC_GLB_RST1_LPUART5_MASK)

#define MRCC_MRCC_GLB_RST1_PKC0_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_RST1_PKC0_SHIFT            (24U)
/*! PKC0 - PKC0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_PKC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_PKC0_SHIFT)) & MRCC_MRCC_GLB_RST1_PKC0_MASK)

#define MRCC_MRCC_GLB_RST1_TRNG0_MASK            (0x4000000U)
#define MRCC_MRCC_GLB_RST1_TRNG0_SHIFT           (26U)
/*! TRNG0 - TRNG0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_TRNG0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_TRNG0_SHIFT)) & MRCC_MRCC_GLB_RST1_TRNG0_MASK)

#define MRCC_MRCC_GLB_RST1_ADC2_MASK             (0x10000000U)
#define MRCC_MRCC_GLB_RST1_ADC2_SHIFT            (28U)
/*! ADC2 - ADC2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC2_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC2_MASK)

#define MRCC_MRCC_GLB_RST1_ADC3_MASK             (0x20000000U)
#define MRCC_MRCC_GLB_RST1_ADC3_SHIFT            (29U)
/*! ADC3 - ADC3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST1_ADC3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_ADC3_SHIFT)) & MRCC_MRCC_GLB_RST1_ADC3_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1_SET - Peripheral Reset Control Set 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST1_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST1_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST1_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST1_CLR - Peripheral Reset Control Clear 1 */
/*! @{ */

#define MRCC_MRCC_GLB_RST1_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST1_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST1_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST1_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST1_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2 - Peripheral Reset Control 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_GPIO0_MASK            (0x10U)
#define MRCC_MRCC_GLB_RST2_GPIO0_SHIFT           (4U)
/*! GPIO0 - GPIO0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_GPIO0_SHIFT)) & MRCC_MRCC_GLB_RST2_GPIO0_MASK)

#define MRCC_MRCC_GLB_RST2_GPIO1_MASK            (0x20U)
#define MRCC_MRCC_GLB_RST2_GPIO1_SHIFT           (5U)
/*! GPIO1 - GPIO1
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_GPIO1_SHIFT)) & MRCC_MRCC_GLB_RST2_GPIO1_MASK)

#define MRCC_MRCC_GLB_RST2_GPIO2_MASK            (0x40U)
#define MRCC_MRCC_GLB_RST2_GPIO2_SHIFT           (6U)
/*! GPIO2 - GPIO2
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_GPIO2_SHIFT)) & MRCC_MRCC_GLB_RST2_GPIO2_MASK)

#define MRCC_MRCC_GLB_RST2_GPIO3_MASK            (0x80U)
#define MRCC_MRCC_GLB_RST2_GPIO3_SHIFT           (7U)
/*! GPIO3 - GPIO3
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_GPIO3_SHIFT)) & MRCC_MRCC_GLB_RST2_GPIO3_MASK)

#define MRCC_MRCC_GLB_RST2_GPIO4_MASK            (0x100U)
#define MRCC_MRCC_GLB_RST2_GPIO4_SHIFT           (8U)
/*! GPIO4 - GPIO4
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_GPIO4_SHIFT)) & MRCC_MRCC_GLB_RST2_GPIO4_MASK)

#define MRCC_MRCC_GLB_RST2_MAU0_MASK             (0x200U)
#define MRCC_MRCC_GLB_RST2_MAU0_SHIFT            (9U)
/*! MAU0 - MAU0
 *  0b0..Peripheral is held in reset
 *  0b1..Peripheral is released from reset
 */
#define MRCC_MRCC_GLB_RST2_MAU0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_MAU0_SHIFT)) & MRCC_MRCC_GLB_RST2_MAU0_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2_SET - Peripheral Reset Control Set 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_SET_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST2_SET_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST2_SET_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_RST2_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_RST2_CLR - Peripheral Reset Control Clear 2 */
/*! @{ */

#define MRCC_MRCC_GLB_RST2_CLR_DATA_MASK         (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_RST2_CLR_DATA_SHIFT        (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_RSTn. */
#define MRCC_MRCC_GLB_RST2_CLR_DATA(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_RST2_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_RST2_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0 - AHB Clock Control 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_INPUTMUX0_MASK         (0x1U)
#define MRCC_MRCC_GLB_CC0_INPUTMUX0_SHIFT        (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_INPUTMUX0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_CC0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_CC0_I3C0_MASK              (0x2U)
#define MRCC_MRCC_GLB_CC0_I3C0_SHIFT             (1U)
/*! I3C0 - I3C0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_I3C0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_I3C0_SHIFT)) & MRCC_MRCC_GLB_CC0_I3C0_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER0_MASK           (0x4U)
#define MRCC_MRCC_GLB_CC0_CTIMER0_SHIFT          (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER1_MASK           (0x8U)
#define MRCC_MRCC_GLB_CC0_CTIMER1_SHIFT          (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER2_MASK           (0x10U)
#define MRCC_MRCC_GLB_CC0_CTIMER2_SHIFT          (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER3_MASK           (0x20U)
#define MRCC_MRCC_GLB_CC0_CTIMER3_SHIFT          (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_CC0_CTIMER4_MASK           (0x40U)
#define MRCC_MRCC_GLB_CC0_CTIMER4_SHIFT          (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CTIMER4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_CC0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_CC0_FREQME_MASK            (0x80U)
#define MRCC_MRCC_GLB_CC0_FREQME_SHIFT           (7U)
/*! FREQME - FREQME
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_FREQME(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_FREQME_SHIFT)) & MRCC_MRCC_GLB_CC0_FREQME_MASK)

#define MRCC_MRCC_GLB_CC0_UTICK0_MASK            (0x100U)
#define MRCC_MRCC_GLB_CC0_UTICK0_SHIFT           (8U)
/*! UTICK0 - UTICK0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_UTICK0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_CC0_UTICK0_MASK)

#define MRCC_MRCC_GLB_CC0_WWDT0_MASK             (0x200U)
#define MRCC_MRCC_GLB_CC0_WWDT0_SHIFT            (9U)
/*! WWDT0 - WWDT0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_WWDT0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_WWDT0_SHIFT)) & MRCC_MRCC_GLB_CC0_WWDT0_MASK)

#define MRCC_MRCC_GLB_CC0_SMARTDMA0_MASK         (0x400U)
#define MRCC_MRCC_GLB_CC0_SMARTDMA0_SHIFT        (10U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_SMARTDMA0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_CC0_SMARTDMA0_MASK)

#define MRCC_MRCC_GLB_CC0_DMA0_MASK              (0x800U)
#define MRCC_MRCC_GLB_CC0_DMA0_SHIFT             (11U)
/*! DMA0 - DMA0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_DMA0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_DMA0_SHIFT)) & MRCC_MRCC_GLB_CC0_DMA0_MASK)

#define MRCC_MRCC_GLB_CC0_AOI0_MASK              (0x1000U)
#define MRCC_MRCC_GLB_CC0_AOI0_SHIFT             (12U)
/*! AOI0 - AOI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_AOI0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_AOI0_SHIFT)) & MRCC_MRCC_GLB_CC0_AOI0_MASK)

#define MRCC_MRCC_GLB_CC0_CRC0_MASK              (0x2000U)
#define MRCC_MRCC_GLB_CC0_CRC0_SHIFT             (13U)
/*! CRC0 - CRC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_CRC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CRC0_SHIFT)) & MRCC_MRCC_GLB_CC0_CRC0_MASK)

#define MRCC_MRCC_GLB_CC0_EIM0_MASK              (0x4000U)
#define MRCC_MRCC_GLB_CC0_EIM0_SHIFT             (14U)
/*! EIM0 - EIM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_EIM0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_EIM0_SHIFT)) & MRCC_MRCC_GLB_CC0_EIM0_MASK)

#define MRCC_MRCC_GLB_CC0_ERM0_MASK              (0x8000U)
#define MRCC_MRCC_GLB_CC0_ERM0_SHIFT             (15U)
/*! ERM0 - ERM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_ERM0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_ERM0_SHIFT)) & MRCC_MRCC_GLB_CC0_ERM0_MASK)

#define MRCC_MRCC_GLB_CC0_AOI1_MASK              (0x20000U)
#define MRCC_MRCC_GLB_CC0_AOI1_SHIFT             (17U)
/*! AOI1 - AOI1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_AOI1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_AOI1_SHIFT)) & MRCC_MRCC_GLB_CC0_AOI1_MASK)

#define MRCC_MRCC_GLB_CC0_FLEXIO0_MASK           (0x40000U)
#define MRCC_MRCC_GLB_CC0_FLEXIO0_SHIFT          (18U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_FLEXIO0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_CC0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C0_MASK            (0x80000U)
#define MRCC_MRCC_GLB_CC0_LPI2C0_SHIFT           (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_CC0_LPI2C1_MASK            (0x100000U)
#define MRCC_MRCC_GLB_CC0_LPI2C1_SHIFT           (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPI2C1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_CC0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_CC0_LPSPI0_MASK            (0x200000U)
#define MRCC_MRCC_GLB_CC0_LPSPI0_SHIFT           (21U)
/*! LPSPI0 - LPSPI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPSPI0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_CC0_LPSPI0_MASK)

#define MRCC_MRCC_GLB_CC0_LPSPI1_MASK            (0x400000U)
#define MRCC_MRCC_GLB_CC0_LPSPI1_SHIFT           (22U)
/*! LPSPI1 - LPSPI1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPSPI1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_CC0_LPSPI1_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART0_MASK           (0x800000U)
#define MRCC_MRCC_GLB_CC0_LPUART0_SHIFT          (23U)
/*! LPUART0 - LPUART0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART0_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART1_MASK           (0x1000000U)
#define MRCC_MRCC_GLB_CC0_LPUART1_SHIFT          (24U)
/*! LPUART1 - LPUART1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART1_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART2_MASK           (0x2000000U)
#define MRCC_MRCC_GLB_CC0_LPUART2_SHIFT          (25U)
/*! LPUART2 - LPUART2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART2_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART3_MASK           (0x4000000U)
#define MRCC_MRCC_GLB_CC0_LPUART3_SHIFT          (26U)
/*! LPUART3 - LPUART3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART3_MASK)

#define MRCC_MRCC_GLB_CC0_LPUART4_MASK           (0x8000000U)
#define MRCC_MRCC_GLB_CC0_LPUART4_SHIFT          (27U)
/*! LPUART4 - LPUART4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_LPUART4(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_CC0_LPUART4_MASK)

#define MRCC_MRCC_GLB_CC0_USB0_MASK              (0x10000000U)
#define MRCC_MRCC_GLB_CC0_USB0_SHIFT             (28U)
/*! USB0 - USB0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_USB0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_USB0_SHIFT)) & MRCC_MRCC_GLB_CC0_USB0_MASK)

#define MRCC_MRCC_GLB_CC0_QDC0_MASK              (0x20000000U)
#define MRCC_MRCC_GLB_CC0_QDC0_SHIFT             (29U)
/*! QDC0 - QDC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_QDC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_QDC0_SHIFT)) & MRCC_MRCC_GLB_CC0_QDC0_MASK)

#define MRCC_MRCC_GLB_CC0_QDC1_MASK              (0x40000000U)
#define MRCC_MRCC_GLB_CC0_QDC1_SHIFT             (30U)
/*! QDC1 - QDC1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_QDC1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_QDC1_SHIFT)) & MRCC_MRCC_GLB_CC0_QDC1_MASK)

#define MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK          (0x80000000U)
#define MRCC_MRCC_GLB_CC0_FLEXPWM0_SHIFT         (31U)
/*! FLEXPWM0 - FLEXPWM0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC0_FLEXPWM0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_FLEXPWM0_SHIFT)) & MRCC_MRCC_GLB_CC0_FLEXPWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0_SET - AHB Clock Control Set 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC0_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC0_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC0_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC0_CLR - AHB Clock Control Clear 0 */
/*! @{ */

#define MRCC_MRCC_GLB_CC0_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC0_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC0_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC0_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC0_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1 - AHB Clock Control 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_FLEXPWM1_MASK          (0x1U)
#define MRCC_MRCC_GLB_CC1_FLEXPWM1_SHIFT         (0U)
/*! FLEXPWM1 - FLEXPWM1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_FLEXPWM1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_FLEXPWM1_SHIFT)) & MRCC_MRCC_GLB_CC1_FLEXPWM1_MASK)

#define MRCC_MRCC_GLB_CC1_OSTIMER0_MASK          (0x2U)
#define MRCC_MRCC_GLB_CC1_OSTIMER0_SHIFT         (1U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_OSTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_CC1_OSTIMER0_MASK)

#define MRCC_MRCC_GLB_CC1_ADC0_MASK              (0x4U)
#define MRCC_MRCC_GLB_CC1_ADC0_SHIFT             (2U)
/*! ADC0 - ADC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC0_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC0_MASK)

#define MRCC_MRCC_GLB_CC1_ADC1_MASK              (0x8U)
#define MRCC_MRCC_GLB_CC1_ADC1_SHIFT             (3U)
/*! ADC1 - ADC1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC1_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC1_MASK)

#define MRCC_MRCC_GLB_CC1_CMP0_MASK              (0x10U)
#define MRCC_MRCC_GLB_CC1_CMP0_SHIFT             (4U)
/*! CMP0 - CMP0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_CMP0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CMP0_SHIFT)) & MRCC_MRCC_GLB_CC1_CMP0_MASK)

#define MRCC_MRCC_GLB_CC1_CMP1_MASK              (0x20U)
#define MRCC_MRCC_GLB_CC1_CMP1_SHIFT             (5U)
/*! CMP1 - CMP1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_CMP1(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CMP1_SHIFT)) & MRCC_MRCC_GLB_CC1_CMP1_MASK)

#define MRCC_MRCC_GLB_CC1_CMP2_MASK              (0x40U)
#define MRCC_MRCC_GLB_CC1_CMP2_SHIFT             (6U)
/*! CMP2 - CMP2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_CMP2(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CMP2_SHIFT)) & MRCC_MRCC_GLB_CC1_CMP2_MASK)

#define MRCC_MRCC_GLB_CC1_DAC0_MASK              (0x80U)
#define MRCC_MRCC_GLB_CC1_DAC0_SHIFT             (7U)
/*! DAC0 - DAC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_DAC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_DAC0_SHIFT)) & MRCC_MRCC_GLB_CC1_DAC0_MASK)

#define MRCC_MRCC_GLB_CC1_OPAMP0_MASK            (0x100U)
#define MRCC_MRCC_GLB_CC1_OPAMP0_SHIFT           (8U)
/*! OPAMP0 - OPAMP0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_OPAMP0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_OPAMP0_SHIFT)) & MRCC_MRCC_GLB_CC1_OPAMP0_MASK)

#define MRCC_MRCC_GLB_CC1_OPAMP1_MASK            (0x200U)
#define MRCC_MRCC_GLB_CC1_OPAMP1_SHIFT           (9U)
/*! OPAMP1 - OPAMP1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_OPAMP1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_OPAMP1_SHIFT)) & MRCC_MRCC_GLB_CC1_OPAMP1_MASK)

#define MRCC_MRCC_GLB_CC1_OPAMP2_MASK            (0x400U)
#define MRCC_MRCC_GLB_CC1_OPAMP2_SHIFT           (10U)
/*! OPAMP2 - OPAMP2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_OPAMP2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_OPAMP2_SHIFT)) & MRCC_MRCC_GLB_CC1_OPAMP2_MASK)

#define MRCC_MRCC_GLB_CC1_OPAMP3_MASK            (0x800U)
#define MRCC_MRCC_GLB_CC1_OPAMP3_SHIFT           (11U)
/*! OPAMP3 - OPAMP3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_OPAMP3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_OPAMP3_SHIFT)) & MRCC_MRCC_GLB_CC1_OPAMP3_MASK)

#define MRCC_MRCC_GLB_CC1_PORT0_MASK             (0x1000U)
#define MRCC_MRCC_GLB_CC1_PORT0_SHIFT            (12U)
/*! PORT0 - PORT0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT0_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT0_MASK)

#define MRCC_MRCC_GLB_CC1_PORT1_MASK             (0x2000U)
#define MRCC_MRCC_GLB_CC1_PORT1_SHIFT            (13U)
/*! PORT1 - PORT1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT1_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT1_MASK)

#define MRCC_MRCC_GLB_CC1_PORT2_MASK             (0x4000U)
#define MRCC_MRCC_GLB_CC1_PORT2_SHIFT            (14U)
/*! PORT2 - PORT2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT2_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT2_MASK)

#define MRCC_MRCC_GLB_CC1_PORT3_MASK             (0x8000U)
#define MRCC_MRCC_GLB_CC1_PORT3_SHIFT            (15U)
/*! PORT3 - PORT3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT3_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT3_MASK)

#define MRCC_MRCC_GLB_CC1_PORT4_MASK             (0x10000U)
#define MRCC_MRCC_GLB_CC1_PORT4_SHIFT            (16U)
/*! PORT4 - PORT4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PORT4(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PORT4_SHIFT)) & MRCC_MRCC_GLB_CC1_PORT4_MASK)

#define MRCC_MRCC_GLB_CC1_SLCD0_MASK             (0x20000U)
#define MRCC_MRCC_GLB_CC1_SLCD0_SHIFT            (17U)
/*! SLCD0 - SLCD0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_SLCD0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_SLCD0_SHIFT)) & MRCC_MRCC_GLB_CC1_SLCD0_MASK)

#define MRCC_MRCC_GLB_CC1_FLEXCAN0_MASK          (0x40000U)
#define MRCC_MRCC_GLB_CC1_FLEXCAN0_SHIFT         (18U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_FLEXCAN0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_CC1_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_CC1_FLEXCAN1_MASK          (0x80000U)
#define MRCC_MRCC_GLB_CC1_FLEXCAN1_SHIFT         (19U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_FLEXCAN1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_CC1_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_CC1_LPI2C2_MASK            (0x100000U)
#define MRCC_MRCC_GLB_CC1_LPI2C2_SHIFT           (20U)
/*! LPI2C2 - LPI2C2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPI2C2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_CC1_LPI2C2_MASK)

#define MRCC_MRCC_GLB_CC1_LPI2C3_MASK            (0x200000U)
#define MRCC_MRCC_GLB_CC1_LPI2C3_SHIFT           (21U)
/*! LPI2C3 - LPI2C3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPI2C3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_CC1_LPI2C3_MASK)

#define MRCC_MRCC_GLB_CC1_LPUART5_MASK           (0x400000U)
#define MRCC_MRCC_GLB_CC1_LPUART5_SHIFT          (22U)
/*! LPUART5 - LPUART5
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_LPUART5(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_LPUART5_SHIFT)) & MRCC_MRCC_GLB_CC1_LPUART5_MASK)

#define MRCC_MRCC_GLB_CC1_TDET0_MASK             (0x800000U)
#define MRCC_MRCC_GLB_CC1_TDET0_SHIFT            (23U)
/*! TDET0 - TDET0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_TDET0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_TDET0_SHIFT)) & MRCC_MRCC_GLB_CC1_TDET0_MASK)

#define MRCC_MRCC_GLB_CC1_PKC0_MASK              (0x1000000U)
#define MRCC_MRCC_GLB_CC1_PKC0_SHIFT             (24U)
/*! PKC0 - PKC0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_PKC0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_PKC0_SHIFT)) & MRCC_MRCC_GLB_CC1_PKC0_MASK)

#define MRCC_MRCC_GLB_CC1_SGI0_MASK              (0x2000000U)
#define MRCC_MRCC_GLB_CC1_SGI0_SHIFT             (25U)
/*! SGI0 - SGI0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_SGI0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_SGI0_SHIFT)) & MRCC_MRCC_GLB_CC1_SGI0_MASK)

#define MRCC_MRCC_GLB_CC1_TRNG0_MASK             (0x4000000U)
#define MRCC_MRCC_GLB_CC1_TRNG0_SHIFT            (26U)
/*! TRNG0 - TRNG0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_TRNG0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_TRNG0_SHIFT)) & MRCC_MRCC_GLB_CC1_TRNG0_MASK)

#define MRCC_MRCC_GLB_CC1_UDF0_MASK              (0x8000000U)
#define MRCC_MRCC_GLB_CC1_UDF0_SHIFT             (27U)
/*! UDF0 - UDF0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_UDF0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_UDF0_SHIFT)) & MRCC_MRCC_GLB_CC1_UDF0_MASK)

#define MRCC_MRCC_GLB_CC1_ADC2_MASK              (0x10000000U)
#define MRCC_MRCC_GLB_CC1_ADC2_SHIFT             (28U)
/*! ADC2 - ADC2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC2(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC2_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC2_MASK)

#define MRCC_MRCC_GLB_CC1_ADC3_MASK              (0x20000000U)
#define MRCC_MRCC_GLB_CC1_ADC3_SHIFT             (29U)
/*! ADC3 - ADC3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC1_ADC3(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_ADC3_SHIFT)) & MRCC_MRCC_GLB_CC1_ADC3_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1_SET - AHB Clock Control Set 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC1_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC1_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC1_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC1_CLR - AHB Clock Control Clear 1 */
/*! @{ */

#define MRCC_MRCC_GLB_CC1_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC1_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC1_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC1_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC1_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2 - AHB Clock Control 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_RAMA_MASK              (0x2U)
#define MRCC_MRCC_GLB_CC2_RAMA_SHIFT             (1U)
/*! RAMA - RAMA
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_RAMA(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_RAMA_SHIFT)) & MRCC_MRCC_GLB_CC2_RAMA_MASK)

#define MRCC_MRCC_GLB_CC2_RAMB_MASK              (0x4U)
#define MRCC_MRCC_GLB_CC2_RAMB_SHIFT             (2U)
/*! RAMB - RAMB
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_RAMB(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_RAMB_SHIFT)) & MRCC_MRCC_GLB_CC2_RAMB_MASK)

#define MRCC_MRCC_GLB_CC2_RAMC_MASK              (0x8U)
#define MRCC_MRCC_GLB_CC2_RAMC_SHIFT             (3U)
/*! RAMC - RAMC
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_RAMC(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_RAMC_SHIFT)) & MRCC_MRCC_GLB_CC2_RAMC_MASK)

#define MRCC_MRCC_GLB_CC2_GPIO0_MASK             (0x10U)
#define MRCC_MRCC_GLB_CC2_GPIO0_SHIFT            (4U)
/*! GPIO0 - GPIO0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_GPIO0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_GPIO0_SHIFT)) & MRCC_MRCC_GLB_CC2_GPIO0_MASK)

#define MRCC_MRCC_GLB_CC2_GPIO1_MASK             (0x20U)
#define MRCC_MRCC_GLB_CC2_GPIO1_SHIFT            (5U)
/*! GPIO1 - GPIO1
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_GPIO1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_GPIO1_SHIFT)) & MRCC_MRCC_GLB_CC2_GPIO1_MASK)

#define MRCC_MRCC_GLB_CC2_GPIO2_MASK             (0x40U)
#define MRCC_MRCC_GLB_CC2_GPIO2_SHIFT            (6U)
/*! GPIO2 - GPIO2
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_GPIO2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_GPIO2_SHIFT)) & MRCC_MRCC_GLB_CC2_GPIO2_MASK)

#define MRCC_MRCC_GLB_CC2_GPIO3_MASK             (0x80U)
#define MRCC_MRCC_GLB_CC2_GPIO3_SHIFT            (7U)
/*! GPIO3 - GPIO3
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_GPIO3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_GPIO3_SHIFT)) & MRCC_MRCC_GLB_CC2_GPIO3_MASK)

#define MRCC_MRCC_GLB_CC2_GPIO4_MASK             (0x100U)
#define MRCC_MRCC_GLB_CC2_GPIO4_SHIFT            (8U)
/*! GPIO4 - GPIO4
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_GPIO4(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_GPIO4_SHIFT)) & MRCC_MRCC_GLB_CC2_GPIO4_MASK)

#define MRCC_MRCC_GLB_CC2_MAU0_MASK              (0x200U)
#define MRCC_MRCC_GLB_CC2_MAU0_SHIFT             (9U)
/*! MAU0 - MAU0
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_MAU0(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_MAU0_SHIFT)) & MRCC_MRCC_GLB_CC2_MAU0_MASK)

#define MRCC_MRCC_GLB_CC2_ROMC_MASK              (0x400U)
#define MRCC_MRCC_GLB_CC2_ROMC_SHIFT             (10U)
/*! ROMC - ROMC
 *  0b0..Peripheral clock is disabled
 *  0b1..Peripheral clock is enabled
 */
#define MRCC_MRCC_GLB_CC2_ROMC(x)                (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_ROMC_SHIFT)) & MRCC_MRCC_GLB_CC2_ROMC_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2_SET - AHB Clock Control Set 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_SET_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC2_SET_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC2_SET_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_SET_DATA_SHIFT)) & MRCC_MRCC_GLB_CC2_SET_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_CC2_CLR - AHB Clock Control Clear 2 */
/*! @{ */

#define MRCC_MRCC_GLB_CC2_CLR_DATA_MASK          (0xFFFFFFFFU)
#define MRCC_MRCC_GLB_CC2_CLR_DATA_SHIFT         (0U)
/*! DATA - Data array value, refer to corresponding position in MRCC_GLB_CCn. */
#define MRCC_MRCC_GLB_CC2_CLR_DATA(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_CC2_CLR_DATA_SHIFT)) & MRCC_MRCC_GLB_CC2_CLR_DATA_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC0 - Control Automatic Clock Gating 0 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC0_INPUTMUX0_MASK        (0x1U)
#define MRCC_MRCC_GLB_ACC0_INPUTMUX0_SHIFT       (0U)
/*! INPUTMUX0 - INPUTMUX0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_INPUTMUX0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_INPUTMUX0_SHIFT)) & MRCC_MRCC_GLB_ACC0_INPUTMUX0_MASK)

#define MRCC_MRCC_GLB_ACC0_I3C0_MASK             (0x2U)
#define MRCC_MRCC_GLB_ACC0_I3C0_SHIFT            (1U)
/*! I3C0 - I3C0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_I3C0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_I3C0_SHIFT)) & MRCC_MRCC_GLB_ACC0_I3C0_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER0_MASK          (0x4U)
#define MRCC_MRCC_GLB_ACC0_CTIMER0_SHIFT         (2U)
/*! CTIMER0 - CTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER0_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER0_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER1_MASK          (0x8U)
#define MRCC_MRCC_GLB_ACC0_CTIMER1_SHIFT         (3U)
/*! CTIMER1 - CTIMER1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER1_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER1_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER2_MASK          (0x10U)
#define MRCC_MRCC_GLB_ACC0_CTIMER2_SHIFT         (4U)
/*! CTIMER2 - CTIMER2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER2_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER2_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER3_MASK          (0x20U)
#define MRCC_MRCC_GLB_ACC0_CTIMER3_SHIFT         (5U)
/*! CTIMER3 - CTIMER3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER3_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER3_MASK)

#define MRCC_MRCC_GLB_ACC0_CTIMER4_MASK          (0x40U)
#define MRCC_MRCC_GLB_ACC0_CTIMER4_SHIFT         (6U)
/*! CTIMER4 - CTIMER4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CTIMER4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CTIMER4_SHIFT)) & MRCC_MRCC_GLB_ACC0_CTIMER4_MASK)

#define MRCC_MRCC_GLB_ACC0_FREQME_MASK           (0x80U)
#define MRCC_MRCC_GLB_ACC0_FREQME_SHIFT          (7U)
/*! FREQME - FREQME
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_FREQME(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_FREQME_SHIFT)) & MRCC_MRCC_GLB_ACC0_FREQME_MASK)

#define MRCC_MRCC_GLB_ACC0_UTICK0_MASK           (0x100U)
#define MRCC_MRCC_GLB_ACC0_UTICK0_SHIFT          (8U)
/*! UTICK0 - UTICK0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_UTICK0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_UTICK0_SHIFT)) & MRCC_MRCC_GLB_ACC0_UTICK0_MASK)

#define MRCC_MRCC_GLB_ACC0_WWDT0_MASK            (0x200U)
#define MRCC_MRCC_GLB_ACC0_WWDT0_SHIFT           (9U)
/*! WWDT0 - WWDT0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_WWDT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_WWDT0_SHIFT)) & MRCC_MRCC_GLB_ACC0_WWDT0_MASK)

#define MRCC_MRCC_GLB_ACC0_SMARTDMA0_MASK        (0x400U)
#define MRCC_MRCC_GLB_ACC0_SMARTDMA0_SHIFT       (10U)
/*! SMARTDMA0 - SMARTDMA0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_SMARTDMA0(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_SMARTDMA0_SHIFT)) & MRCC_MRCC_GLB_ACC0_SMARTDMA0_MASK)

#define MRCC_MRCC_GLB_ACC0_DMA0_MASK             (0x800U)
#define MRCC_MRCC_GLB_ACC0_DMA0_SHIFT            (11U)
/*! DMA0 - DMA0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_DMA0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_DMA0_SHIFT)) & MRCC_MRCC_GLB_ACC0_DMA0_MASK)

#define MRCC_MRCC_GLB_ACC0_AOI0_MASK             (0x1000U)
#define MRCC_MRCC_GLB_ACC0_AOI0_SHIFT            (12U)
/*! AOI0 - AOI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_AOI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_AOI0_SHIFT)) & MRCC_MRCC_GLB_ACC0_AOI0_MASK)

#define MRCC_MRCC_GLB_ACC0_CRC0_MASK             (0x2000U)
#define MRCC_MRCC_GLB_ACC0_CRC0_SHIFT            (13U)
/*! CRC0 - CRC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_CRC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_CRC0_SHIFT)) & MRCC_MRCC_GLB_ACC0_CRC0_MASK)

#define MRCC_MRCC_GLB_ACC0_EIM0_MASK             (0x4000U)
#define MRCC_MRCC_GLB_ACC0_EIM0_SHIFT            (14U)
/*! EIM0 - EIM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_EIM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_EIM0_SHIFT)) & MRCC_MRCC_GLB_ACC0_EIM0_MASK)

#define MRCC_MRCC_GLB_ACC0_ERM0_MASK             (0x8000U)
#define MRCC_MRCC_GLB_ACC0_ERM0_SHIFT            (15U)
/*! ERM0 - ERM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_ERM0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_ERM0_SHIFT)) & MRCC_MRCC_GLB_ACC0_ERM0_MASK)

#define MRCC_MRCC_GLB_ACC0_AOI1_MASK             (0x20000U)
#define MRCC_MRCC_GLB_ACC0_AOI1_SHIFT            (17U)
/*! AOI1 - AOI1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_AOI1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_AOI1_SHIFT)) & MRCC_MRCC_GLB_ACC0_AOI1_MASK)

#define MRCC_MRCC_GLB_ACC0_FLEXIO0_MASK          (0x40000U)
#define MRCC_MRCC_GLB_ACC0_FLEXIO0_SHIFT         (18U)
/*! FLEXIO0 - FLEXIO0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_FLEXIO0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_FLEXIO0_SHIFT)) & MRCC_MRCC_GLB_ACC0_FLEXIO0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C0_MASK           (0x80000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C0_SHIFT          (19U)
/*! LPI2C0 - LPI2C0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C0_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPI2C1_MASK           (0x100000U)
#define MRCC_MRCC_GLB_ACC0_LPI2C1_SHIFT          (20U)
/*! LPI2C1 - LPI2C1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPI2C1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPI2C1_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPI2C1_MASK)

#define MRCC_MRCC_GLB_ACC0_LPSPI0_MASK           (0x200000U)
#define MRCC_MRCC_GLB_ACC0_LPSPI0_SHIFT          (21U)
/*! LPSPI0 - LPSPI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPSPI0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPSPI0_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPSPI0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPSPI1_MASK           (0x400000U)
#define MRCC_MRCC_GLB_ACC0_LPSPI1_SHIFT          (22U)
/*! LPSPI1 - LPSPI1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPSPI1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPSPI1_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPSPI1_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART0_MASK          (0x800000U)
#define MRCC_MRCC_GLB_ACC0_LPUART0_SHIFT         (23U)
/*! LPUART0 - LPUART0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART0(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART0_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART0_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART1_MASK          (0x1000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART1_SHIFT         (24U)
/*! LPUART1 - LPUART1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART1(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART1_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART1_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART2_MASK          (0x2000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART2_SHIFT         (25U)
/*! LPUART2 - LPUART2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART2(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART2_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART2_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART3_MASK          (0x4000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART3_SHIFT         (26U)
/*! LPUART3 - LPUART3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART3(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART3_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART3_MASK)

#define MRCC_MRCC_GLB_ACC0_LPUART4_MASK          (0x8000000U)
#define MRCC_MRCC_GLB_ACC0_LPUART4_SHIFT         (27U)
/*! LPUART4 - LPUART4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_LPUART4(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_LPUART4_SHIFT)) & MRCC_MRCC_GLB_ACC0_LPUART4_MASK)

#define MRCC_MRCC_GLB_ACC0_USB0_MASK             (0x10000000U)
#define MRCC_MRCC_GLB_ACC0_USB0_SHIFT            (28U)
/*! USB0 - USB0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_USB0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_USB0_SHIFT)) & MRCC_MRCC_GLB_ACC0_USB0_MASK)

#define MRCC_MRCC_GLB_ACC0_QDC0_MASK             (0x20000000U)
#define MRCC_MRCC_GLB_ACC0_QDC0_SHIFT            (29U)
/*! QDC0 - QDC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_QDC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_QDC0_SHIFT)) & MRCC_MRCC_GLB_ACC0_QDC0_MASK)

#define MRCC_MRCC_GLB_ACC0_QDC1_MASK             (0x40000000U)
#define MRCC_MRCC_GLB_ACC0_QDC1_SHIFT            (30U)
/*! QDC1 - QDC1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_QDC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_QDC1_SHIFT)) & MRCC_MRCC_GLB_ACC0_QDC1_MASK)

#define MRCC_MRCC_GLB_ACC0_FLEXPWM0_MASK         (0x80000000U)
#define MRCC_MRCC_GLB_ACC0_FLEXPWM0_SHIFT        (31U)
/*! FLEXPWM0 - FLEXPWM0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC0_FLEXPWM0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC0_FLEXPWM0_SHIFT)) & MRCC_MRCC_GLB_ACC0_FLEXPWM0_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC1 - Control Automatic Clock Gating 1 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC1_FLEXPWM1_MASK         (0x1U)
#define MRCC_MRCC_GLB_ACC1_FLEXPWM1_SHIFT        (0U)
/*! FLEXPWM1 - FLEXPWM1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_FLEXPWM1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_FLEXPWM1_SHIFT)) & MRCC_MRCC_GLB_ACC1_FLEXPWM1_MASK)

#define MRCC_MRCC_GLB_ACC1_OSTIMER0_MASK         (0x2U)
#define MRCC_MRCC_GLB_ACC1_OSTIMER0_SHIFT        (1U)
/*! OSTIMER0 - OSTIMER0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_OSTIMER0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_OSTIMER0_SHIFT)) & MRCC_MRCC_GLB_ACC1_OSTIMER0_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC0_MASK             (0x4U)
#define MRCC_MRCC_GLB_ACC1_ADC0_SHIFT            (2U)
/*! ADC0 - ADC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC0_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC0_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC1_MASK             (0x8U)
#define MRCC_MRCC_GLB_ACC1_ADC1_SHIFT            (3U)
/*! ADC1 - ADC1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC1_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC1_MASK)

#define MRCC_MRCC_GLB_ACC1_CMP0_MASK             (0x10U)
#define MRCC_MRCC_GLB_ACC1_CMP0_SHIFT            (4U)
/*! CMP0 - CMP0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_CMP0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_CMP0_SHIFT)) & MRCC_MRCC_GLB_ACC1_CMP0_MASK)

#define MRCC_MRCC_GLB_ACC1_CMP1_MASK             (0x20U)
#define MRCC_MRCC_GLB_ACC1_CMP1_SHIFT            (5U)
/*! CMP1 - CMP1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_CMP1(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_CMP1_SHIFT)) & MRCC_MRCC_GLB_ACC1_CMP1_MASK)

#define MRCC_MRCC_GLB_ACC1_CMP2_MASK             (0x40U)
#define MRCC_MRCC_GLB_ACC1_CMP2_SHIFT            (6U)
/*! CMP2 - CMP2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_CMP2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_CMP2_SHIFT)) & MRCC_MRCC_GLB_ACC1_CMP2_MASK)

#define MRCC_MRCC_GLB_ACC1_DAC0_MASK             (0x80U)
#define MRCC_MRCC_GLB_ACC1_DAC0_SHIFT            (7U)
/*! DAC0 - DAC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_DAC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_DAC0_SHIFT)) & MRCC_MRCC_GLB_ACC1_DAC0_MASK)

#define MRCC_MRCC_GLB_ACC1_OPAMP0_MASK           (0x100U)
#define MRCC_MRCC_GLB_ACC1_OPAMP0_SHIFT          (8U)
/*! OPAMP0 - OPAMP0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_OPAMP0(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_OPAMP0_SHIFT)) & MRCC_MRCC_GLB_ACC1_OPAMP0_MASK)

#define MRCC_MRCC_GLB_ACC1_OPAMP1_MASK           (0x200U)
#define MRCC_MRCC_GLB_ACC1_OPAMP1_SHIFT          (9U)
/*! OPAMP1 - OPAMP1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_OPAMP1(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_OPAMP1_SHIFT)) & MRCC_MRCC_GLB_ACC1_OPAMP1_MASK)

#define MRCC_MRCC_GLB_ACC1_OPAMP2_MASK           (0x400U)
#define MRCC_MRCC_GLB_ACC1_OPAMP2_SHIFT          (10U)
/*! OPAMP2 - OPAMP2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_OPAMP2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_OPAMP2_SHIFT)) & MRCC_MRCC_GLB_ACC1_OPAMP2_MASK)

#define MRCC_MRCC_GLB_ACC1_OPAMP3_MASK           (0x800U)
#define MRCC_MRCC_GLB_ACC1_OPAMP3_SHIFT          (11U)
/*! OPAMP3 - OPAMP3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_OPAMP3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_OPAMP3_SHIFT)) & MRCC_MRCC_GLB_ACC1_OPAMP3_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT0_MASK            (0x1000U)
#define MRCC_MRCC_GLB_ACC1_PORT0_SHIFT           (12U)
/*! PORT0 - PORT0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT0_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT0_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT1_MASK            (0x2000U)
#define MRCC_MRCC_GLB_ACC1_PORT1_SHIFT           (13U)
/*! PORT1 - PORT1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT1_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT1_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT2_MASK            (0x4000U)
#define MRCC_MRCC_GLB_ACC1_PORT2_SHIFT           (14U)
/*! PORT2 - PORT2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT2_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT2_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT3_MASK            (0x8000U)
#define MRCC_MRCC_GLB_ACC1_PORT3_SHIFT           (15U)
/*! PORT3 - PORT3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT3_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT3_MASK)

#define MRCC_MRCC_GLB_ACC1_PORT4_MASK            (0x10000U)
#define MRCC_MRCC_GLB_ACC1_PORT4_SHIFT           (16U)
/*! PORT4 - PORT4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PORT4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PORT4_SHIFT)) & MRCC_MRCC_GLB_ACC1_PORT4_MASK)

#define MRCC_MRCC_GLB_ACC1_SLCD0_MASK            (0x20000U)
#define MRCC_MRCC_GLB_ACC1_SLCD0_SHIFT           (17U)
/*! SLCD0 - SLCD0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_SLCD0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_SLCD0_SHIFT)) & MRCC_MRCC_GLB_ACC1_SLCD0_MASK)

#define MRCC_MRCC_GLB_ACC1_FLEXCAN0_MASK         (0x40000U)
#define MRCC_MRCC_GLB_ACC1_FLEXCAN0_SHIFT        (18U)
/*! FLEXCAN0 - FLEXCAN0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_FLEXCAN0(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_FLEXCAN0_SHIFT)) & MRCC_MRCC_GLB_ACC1_FLEXCAN0_MASK)

#define MRCC_MRCC_GLB_ACC1_FLEXCAN1_MASK         (0x80000U)
#define MRCC_MRCC_GLB_ACC1_FLEXCAN1_SHIFT        (19U)
/*! FLEXCAN1 - FLEXCAN1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_FLEXCAN1(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_FLEXCAN1_SHIFT)) & MRCC_MRCC_GLB_ACC1_FLEXCAN1_MASK)

#define MRCC_MRCC_GLB_ACC1_LPI2C2_MASK           (0x100000U)
#define MRCC_MRCC_GLB_ACC1_LPI2C2_SHIFT          (20U)
/*! LPI2C2 - LPI2C2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPI2C2(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPI2C2_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPI2C2_MASK)

#define MRCC_MRCC_GLB_ACC1_LPI2C3_MASK           (0x200000U)
#define MRCC_MRCC_GLB_ACC1_LPI2C3_SHIFT          (21U)
/*! LPI2C3 - LPI2C3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPI2C3(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPI2C3_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPI2C3_MASK)

#define MRCC_MRCC_GLB_ACC1_LPUART5_MASK          (0x400000U)
#define MRCC_MRCC_GLB_ACC1_LPUART5_SHIFT         (22U)
/*! LPUART5 - LPUART5
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_LPUART5(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_LPUART5_SHIFT)) & MRCC_MRCC_GLB_ACC1_LPUART5_MASK)

#define MRCC_MRCC_GLB_ACC1_PKC0_MASK             (0x1000000U)
#define MRCC_MRCC_GLB_ACC1_PKC0_SHIFT            (24U)
/*! PKC0 - PKC0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_PKC0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_PKC0_SHIFT)) & MRCC_MRCC_GLB_ACC1_PKC0_MASK)

#define MRCC_MRCC_GLB_ACC1_SGI0_MASK             (0x2000000U)
#define MRCC_MRCC_GLB_ACC1_SGI0_SHIFT            (25U)
/*! SGI0 - SGI0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_SGI0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_SGI0_SHIFT)) & MRCC_MRCC_GLB_ACC1_SGI0_MASK)

#define MRCC_MRCC_GLB_ACC1_TRNG0_MASK            (0x4000000U)
#define MRCC_MRCC_GLB_ACC1_TRNG0_SHIFT           (26U)
/*! TRNG0 - TRNG0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_TRNG0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_TRNG0_SHIFT)) & MRCC_MRCC_GLB_ACC1_TRNG0_MASK)

#define MRCC_MRCC_GLB_ACC1_UDF0_MASK             (0x8000000U)
#define MRCC_MRCC_GLB_ACC1_UDF0_SHIFT            (27U)
/*! UDF0 - UDF0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_UDF0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_UDF0_SHIFT)) & MRCC_MRCC_GLB_ACC1_UDF0_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC2_MASK             (0x10000000U)
#define MRCC_MRCC_GLB_ACC1_ADC2_SHIFT            (28U)
/*! ADC2 - ADC2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC2(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC2_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC2_MASK)

#define MRCC_MRCC_GLB_ACC1_ADC3_MASK             (0x20000000U)
#define MRCC_MRCC_GLB_ACC1_ADC3_SHIFT            (29U)
/*! ADC3 - ADC3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC1_ADC3(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC1_ADC3_SHIFT)) & MRCC_MRCC_GLB_ACC1_ADC3_MASK)
/*! @} */

/*! @name MRCC_GLB_ACC2 - Control Automatic Clock Gating 2 */
/*! @{ */

#define MRCC_MRCC_GLB_ACC2_RAMA_MASK             (0x2U)
#define MRCC_MRCC_GLB_ACC2_RAMA_SHIFT            (1U)
/*! RAMA - RAMA
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_RAMA(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_RAMA_SHIFT)) & MRCC_MRCC_GLB_ACC2_RAMA_MASK)

#define MRCC_MRCC_GLB_ACC2_RAMB_MASK             (0x4U)
#define MRCC_MRCC_GLB_ACC2_RAMB_SHIFT            (2U)
/*! RAMB - RAMB
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_RAMB(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_RAMB_SHIFT)) & MRCC_MRCC_GLB_ACC2_RAMB_MASK)

#define MRCC_MRCC_GLB_ACC2_RAMC_MASK             (0x8U)
#define MRCC_MRCC_GLB_ACC2_RAMC_SHIFT            (3U)
/*! RAMC - RAMC
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_RAMC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_RAMC_SHIFT)) & MRCC_MRCC_GLB_ACC2_RAMC_MASK)

#define MRCC_MRCC_GLB_ACC2_GPIO0_MASK            (0x10U)
#define MRCC_MRCC_GLB_ACC2_GPIO0_SHIFT           (4U)
/*! GPIO0 - GPIO0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_GPIO0(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_GPIO0_SHIFT)) & MRCC_MRCC_GLB_ACC2_GPIO0_MASK)

#define MRCC_MRCC_GLB_ACC2_GPIO1_MASK            (0x20U)
#define MRCC_MRCC_GLB_ACC2_GPIO1_SHIFT           (5U)
/*! GPIO1 - GPIO1
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_GPIO1(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_GPIO1_SHIFT)) & MRCC_MRCC_GLB_ACC2_GPIO1_MASK)

#define MRCC_MRCC_GLB_ACC2_GPIO2_MASK            (0x40U)
#define MRCC_MRCC_GLB_ACC2_GPIO2_SHIFT           (6U)
/*! GPIO2 - GPIO2
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_GPIO2(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_GPIO2_SHIFT)) & MRCC_MRCC_GLB_ACC2_GPIO2_MASK)

#define MRCC_MRCC_GLB_ACC2_GPIO3_MASK            (0x80U)
#define MRCC_MRCC_GLB_ACC2_GPIO3_SHIFT           (7U)
/*! GPIO3 - GPIO3
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_GPIO3(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_GPIO3_SHIFT)) & MRCC_MRCC_GLB_ACC2_GPIO3_MASK)

#define MRCC_MRCC_GLB_ACC2_GPIO4_MASK            (0x100U)
#define MRCC_MRCC_GLB_ACC2_GPIO4_SHIFT           (8U)
/*! GPIO4 - GPIO4
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_GPIO4(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_GPIO4_SHIFT)) & MRCC_MRCC_GLB_ACC2_GPIO4_MASK)

#define MRCC_MRCC_GLB_ACC2_MAU0_MASK             (0x200U)
#define MRCC_MRCC_GLB_ACC2_MAU0_SHIFT            (9U)
/*! MAU0 - MAU0
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_MAU0(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_MAU0_SHIFT)) & MRCC_MRCC_GLB_ACC2_MAU0_MASK)

#define MRCC_MRCC_GLB_ACC2_ROMC_MASK             (0x400U)
#define MRCC_MRCC_GLB_ACC2_ROMC_SHIFT            (10U)
/*! ROMC - ROMC
 *  0b0..Automatic clock gating is disabled
 *  0b1..Automatic clock gating is enabled
 */
#define MRCC_MRCC_GLB_ACC2_ROMC(x)               (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_GLB_ACC2_ROMC_SHIFT)) & MRCC_MRCC_GLB_ACC2_ROMC_MASK)
/*! @} */

/*! @name MRCC_I3C0_FCLK_CLKSEL - I3C0_FCLK clock selection control */
/*! @{ */

#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_MASK      (0x7U)
#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_I3C0_FCLK_CLKDIV - I3C0_FCLK clock divider control */
/*! @{ */

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_I3C0_FCLK_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER0_CLKSEL - CTIMER0 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER0_CLKDIV - CTIMER0 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER1_CLKSEL - CTIMER1 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER1_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER1_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER1_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER1_CLKDIV - CTIMER1 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER1_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER1_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER1_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER2_CLKSEL - CTIMER2 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER2_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER2_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER2_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER2_CLKDIV - CTIMER2 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER2_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER2_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER2_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER3_CLKSEL - CTIMER3 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER3_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER3_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER3_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER3_CLKDIV - CTIMER3 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER3_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER3_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER3_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CTIMER4_CLKSEL - CTIMER4 clock selection control */
/*! @{ */

#define MRCC_MRCC_CTIMER4_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CTIMER4_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CTIMER4_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CTIMER4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CTIMER4_CLKDIV - CTIMER4 clock divider control */
/*! @{ */

#define MRCC_MRCC_CTIMER4_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CTIMER4_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CTIMER4_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CTIMER4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_WWDT0_CLKDIV - WWDT0 clock divider control */
/*! @{ */

#define MRCC_MRCC_WWDT0_CLKDIV_DIV_MASK          (0xFU)
#define MRCC_MRCC_WWDT0_CLKDIV_DIV_SHIFT         (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_WWDT0_CLKDIV_DIV(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_RESET_MASK        (0x20000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_RESET_SHIFT       (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_WWDT0_CLKDIV_RESET(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_HALT_MASK         (0x40000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_HALT_SHIFT        (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_WWDT0_CLKDIV_HALT(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_MASK       (0x80000000U)
#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_SHIFT      (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_WWDT0_CLKDIV_UNSTAB(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_WWDT0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXIO0_CLKSEL - FLEXIO0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXIO0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXIO0_CLKDIV - FLEXIO0 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXIO0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXIO0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C0_CLKSEL - LPI2C0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C0_CLKDIV - LPI2C0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C1_CLKSEL - LPI2C1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C1_CLKDIV - LPI2C1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C1_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C1_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C1_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI0_CLKSEL - LPSPI0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI0_CLKDIV - LPSPI0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPSPI1_CLKSEL - LPSPI1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPSPI1_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPSPI1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPSPI1_CLKDIV - LPSPI1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPSPI1_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPSPI1_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPSPI1_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPSPI1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART0_CLKSEL - LPUART0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART0_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART0_CLKDIV - LPUART0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART0_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART0_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART0_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART0_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART0_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART0_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART1_CLKSEL - LPUART1 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART1_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART1_CLKDIV - LPUART1 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART1_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART1_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART1_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART1_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART1_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART1_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART2_CLKSEL - LPUART2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART2_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART2_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART2_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART2_CLKDIV - LPUART2 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART2_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART2_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART2_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART2_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART2_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART2_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART3_CLKSEL - LPUART3 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART3_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART3_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART3_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART3_CLKDIV - LPUART3 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART3_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART3_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART3_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART3_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART3_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART3_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART4_CLKSEL - LPUART4 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART4_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART4_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART4_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART4_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART4_CLKDIV - LPUART4 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART4_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART4_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART4_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART4_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART4_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART4_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART4_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_USB0_CLKSEL - USB0 clock selection control */
/*! @{ */

#define MRCC_MRCC_USB0_CLKSEL_MUX_MASK           (0x3U)
#define MRCC_MRCC_USB0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..PLL1_CLK
 *  0b01..CLK_48M
 *  0b10..CLK_IN
 *  0b11..Reserved(NO Clock)
 */
#define MRCC_MRCC_USB0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_USB0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_USB0_CLKDIV - USB0 clock divider control */
/*! @{ */

#define MRCC_MRCC_USB0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_USB0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_USB0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_USB0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_USB0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_USB0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_USB0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_USB0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_USB0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_USB0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_USB0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_USB0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_USB0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_USB0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_USB0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_USB0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_USB0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPTMR0_CLKSEL - LPTMR0 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPTMR0_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPTMR0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPTMR0_CLKDIV - LPTMR0 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPTMR0_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPTMR0_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPTMR0_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPTMR0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_OSTIMER0_CLKSEL - OSTIMER0 clock selection control */
/*! @{ */

#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX_MASK       (0x3U)
#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CLK_16K
 *  0b10..CLK_1M
 *  0b11..Reserved2(NO Clock)
 */
#define MRCC_MRCC_OSTIMER0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_OSTIMER0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_OSTIMER0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_ADC_CLKSEL - ADCx clock selection control */
/*! @{ */

#define MRCC_MRCC_ADC_CLKSEL_MUX_MASK            (0x7U)
#define MRCC_MRCC_ADC_CLKSEL_MUX_SHIFT           (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b001..FRO_HF_GATED
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_ADC_CLKSEL_MUX(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_ADC_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_ADC_CLKDIV - ADCx clock divider control */
/*! @{ */

#define MRCC_MRCC_ADC_CLKDIV_DIV_MASK            (0xFU)
#define MRCC_MRCC_ADC_CLKDIV_DIV_SHIFT           (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_ADC_CLKDIV_DIV(x)              (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_ADC_CLKDIV_RESET_MASK          (0x20000000U)
#define MRCC_MRCC_ADC_CLKDIV_RESET_SHIFT         (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_ADC_CLKDIV_RESET(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_ADC_CLKDIV_HALT_MASK           (0x40000000U)
#define MRCC_MRCC_ADC_CLKDIV_HALT_SHIFT          (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_ADC_CLKDIV_HALT(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_ADC_CLKDIV_UNSTAB_MASK         (0x80000000U)
#define MRCC_MRCC_ADC_CLKDIV_UNSTAB_SHIFT        (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_ADC_CLKDIV_UNSTAB(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_ADC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_ADC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP0_FUNC_CLKDIV - CMP0_FUNC clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP0_FUNC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP0_RR_CLKSEL - CMP0_RR clock selection control */
/*! @{ */

#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CMP0_RR_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CMP0_RR_CLKDIV - CMP0_RR clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP0_RR_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP0_RR_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP1_FUNC_CLKDIV - CMP1_FUNC clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP1_FUNC_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_FUNC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP1_FUNC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP1_FUNC_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_FUNC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP1_FUNC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP1_FUNC_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_FUNC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP1_FUNC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP1_FUNC_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP1_FUNC_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_FUNC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP1_FUNC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP1_RR_CLKSEL - CMP1_RR clock selection control */
/*! @{ */

#define MRCC_MRCC_CMP1_RR_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CMP1_RR_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CMP1_RR_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_RR_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CMP1_RR_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CMP1_RR_CLKDIV - CMP1_RR clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP1_RR_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CMP1_RR_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP1_RR_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_RR_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP1_RR_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP1_RR_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CMP1_RR_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP1_RR_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_RR_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP1_RR_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP1_RR_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CMP1_RR_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP1_RR_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_RR_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP1_RR_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP1_RR_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CMP1_RR_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP1_RR_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP1_RR_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP1_RR_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP2_FUNC_CLKDIV - CMP2_FUNC clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP2_FUNC_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_FUNC_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP2_FUNC_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP2_FUNC_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_FUNC_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP2_FUNC_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP2_FUNC_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_FUNC_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP2_FUNC_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP2_FUNC_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP2_FUNC_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_FUNC_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP2_FUNC_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CMP2_RR_CLKSEL - CMP2_RR clock selection control */
/*! @{ */

#define MRCC_MRCC_CMP2_RR_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_CMP2_RR_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CMP2_RR_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_RR_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CMP2_RR_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CMP2_RR_CLKDIV - CMP2_RR clock divider control */
/*! @{ */

#define MRCC_MRCC_CMP2_RR_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_CMP2_RR_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CMP2_RR_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_RR_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CMP2_RR_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CMP2_RR_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_CMP2_RR_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CMP2_RR_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_RR_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CMP2_RR_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CMP2_RR_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_CMP2_RR_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CMP2_RR_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_RR_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CMP2_RR_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CMP2_RR_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_CMP2_RR_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CMP2_RR_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CMP2_RR_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CMP2_RR_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_DAC0_CLKSEL - DAC0 clock selection control */
/*! @{ */

#define MRCC_MRCC_DAC0_CLKSEL_MUX_MASK           (0x7U)
#define MRCC_MRCC_DAC0_CLKSEL_MUX_SHIFT          (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_DAC0_CLKSEL_MUX(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_DAC0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_DAC0_CLKDIV - DAC0 clock divider control */
/*! @{ */

#define MRCC_MRCC_DAC0_CLKDIV_DIV_MASK           (0xFU)
#define MRCC_MRCC_DAC0_CLKDIV_DIV_SHIFT          (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_DAC0_CLKDIV_DIV(x)             (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_RESET_MASK         (0x20000000U)
#define MRCC_MRCC_DAC0_CLKDIV_RESET_SHIFT        (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_DAC0_CLKDIV_RESET(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_HALT_MASK          (0x40000000U)
#define MRCC_MRCC_DAC0_CLKDIV_HALT_SHIFT         (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_DAC0_CLKDIV_HALT(x)            (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB_MASK        (0x80000000U)
#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB_SHIFT       (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_DAC0_CLKDIV_UNSTAB(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DAC0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_DAC0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN0_CLKSEL - FLEXCAN0 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXCAN0_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN0_CLKDIV - FLEXCAN0 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXCAN0_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN1_CLKSEL - FLEXCAN1 clock selection control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_MASK       (0x7U)
#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_SHIFT      (0U)
/*! MUX - Functional Clock Mux Select
 *  0b001..FRO_HF_GATED
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b110..PLL1_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_FLEXCAN1_CLKSEL_MUX(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_FLEXCAN1_CLKDIV - FLEXCAN1 clock divider control */
/*! @{ */

#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_MASK       (0xFU)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_SHIFT      (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_DIV(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_DIV_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_MASK     (0x20000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_SHIFT    (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_RESET(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_RESET_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_MASK      (0x40000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_SHIFT     (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_HALT(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_HALT_MASK)

#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_MASK    (0x80000000U)
#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_SHIFT   (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_FLEXCAN1_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C2_CLKSEL - LPI2C2 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C2_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C2_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C2_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C2_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C2_CLKDIV - LPI2C2 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C2_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C2_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C2_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C2_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPI2C3_CLKSEL - LPI2C3 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPI2C3_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_LPI2C3_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPI2C3_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPI2C3_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPI2C3_CLKDIV - LPI2C3 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPI2C3_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_LPI2C3_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPI2C3_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPI2C3_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_LPUART5_CLKSEL - LPUART5 clock selection control */
/*! @{ */

#define MRCC_MRCC_LPUART5_CLKSEL_MUX_MASK        (0x7U)
#define MRCC_MRCC_LPUART5_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_LF_DIV
 *  0b010..FRO_HF_DIV
 *  0b011..CLK_IN
 *  0b100..CLK_16K
 *  0b101..CLK_1M
 *  0b110..PLL1_CLK_DIV
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_LPUART5_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_LPUART5_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_LPUART5_CLKDIV - LPUART5 clock divider control */
/*! @{ */

#define MRCC_MRCC_LPUART5_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_LPUART5_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_LPUART5_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_DIV_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_LPUART5_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_RESET_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_LPUART5_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_HALT_MASK)

#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_LPUART5_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_LPUART5_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_DBG_TRACE_CLKSEL - DBG_TRACE clock selection control */
/*! @{ */

#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_MASK      (0x3U)
#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_SHIFT     (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved1(NO Clock)
 */
#define MRCC_MRCC_DBG_TRACE_CLKSEL_MUX(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_DBG_TRACE_CLKDIV - DBG_TRACE clock divider control */
/*! @{ */

#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_MASK      (0xFU)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_SHIFT     (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_DIV(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_DIV_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_MASK    (0x20000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_SHIFT   (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_RESET(x)      (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_RESET_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_MASK     (0x40000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_SHIFT    (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_HALT(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_HALT_MASK)

#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_MASK   (0x80000000U)
#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_SHIFT  (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB(x)     (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_DBG_TRACE_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_CLKOUT_CLKSEL - CLKOUT clock selection control */
/*! @{ */

#define MRCC_MRCC_CLKOUT_CLKSEL_MUX_MASK         (0x7U)
#define MRCC_MRCC_CLKOUT_CLKSEL_MUX_SHIFT        (0U)
/*! MUX - Functional Clock Mux Select
 *  0b000..FRO_12M
 *  0b001..FRO_HF_DIV
 *  0b010..CLK_IN
 *  0b011..CLK_16K
 *  0b101..PLL1_CLK
 *  0b110..SLOW_CLK
 *  0b111..Reserved(NO Clock)
 */
#define MRCC_MRCC_CLKOUT_CLKSEL_MUX(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_CLKOUT_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_CLKOUT_CLKDIV - CLKOUT clock divider control */
/*! @{ */

#define MRCC_MRCC_CLKOUT_CLKDIV_DIV_MASK         (0xFU)
#define MRCC_MRCC_CLKOUT_CLKDIV_DIV_SHIFT        (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_CLKOUT_CLKDIV_DIV(x)           (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_DIV_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_RESET_MASK       (0x20000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_RESET_SHIFT      (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_RESET(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_RESET_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_HALT_MASK        (0x40000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_HALT_SHIFT       (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_HALT(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_HALT_MASK)

#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_MASK      (0x80000000U)
#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_SHIFT     (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_CLKOUT_CLKDIV_UNSTAB_MASK)
/*! @} */

/*! @name MRCC_SYSTICK_CLKSEL - SYSTICK clock selection control */
/*! @{ */

#define MRCC_MRCC_SYSTICK_CLKSEL_MUX_MASK        (0x3U)
#define MRCC_MRCC_SYSTICK_CLKSEL_MUX_SHIFT       (0U)
/*! MUX - Functional Clock Mux Select
 *  0b00..CPU_CLK
 *  0b01..CLK_1M
 *  0b10..CLK_16K
 *  0b11..Reserved1(NO Clock)
 */
#define MRCC_MRCC_SYSTICK_CLKSEL_MUX(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKSEL_MUX_SHIFT)) & MRCC_MRCC_SYSTICK_CLKSEL_MUX_MASK)
/*! @} */

/*! @name MRCC_SYSTICK_CLKDIV - SYSTICK clock divider control */
/*! @{ */

#define MRCC_MRCC_SYSTICK_CLKDIV_DIV_MASK        (0xFU)
#define MRCC_MRCC_SYSTICK_CLKDIV_DIV_SHIFT       (0U)
/*! DIV - Functional Clock Divider */
#define MRCC_MRCC_SYSTICK_CLKDIV_DIV(x)          (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_DIV_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_DIV_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_RESET_MASK      (0x20000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_RESET_SHIFT     (29U)
/*! RESET - Reset divider counter
 *  0b0..Divider isn't reset
 *  0b1..Divider is reset
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_RESET(x)        (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_RESET_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_RESET_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_HALT_MASK       (0x40000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_HALT_SHIFT      (30U)
/*! HALT - Halt divider counter
 *  0b0..Divider clock is running
 *  0b1..Divider clock is stopped
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_HALT(x)         (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_HALT_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_HALT_MASK)

#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_MASK     (0x80000000U)
#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_SHIFT    (31U)
/*! UNSTAB - Divider status flag
 *  0b0..Divider clock is stable
 *  0b1..Clock frequency isn't stable
 */
#define MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB(x)       (((uint32_t)(((uint32_t)(x)) << MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_SHIFT)) & MRCC_MRCC_SYSTICK_CLKDIV_UNSTAB_MASK)
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

