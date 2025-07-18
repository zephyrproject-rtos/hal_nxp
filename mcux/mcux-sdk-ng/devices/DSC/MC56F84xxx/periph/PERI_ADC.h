/*
** ###################################################################
**     Processors:          MC56F84441VLF
**                          MC56F84442VLH
**                          MC56F84451VLF
**                          MC56F84452VLH
**                          MC56F84462VLH
**                          MC56F84540VLF
**                          MC56F84543VLH
**                          MC56F84550VLF
**                          MC56F84553VLH
**                          MC56F84565VLK
**                          MC56F84567VLL
**                          MC56F84587VLL
**                          MC56F84763VLH
**                          MC56F84766VLK
**                          MC56F84769VLL
**                          MC56F84786VLK
**                          MC56F84789VLL
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ADC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 2.0 (2021-02-06)
**         Initial version.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F84441VLF))
#include "MC56F84441_COMMON.h"
#elif (defined(CPU_MC56F84442VLH))
#include "MC56F84442_COMMON.h"
#elif (defined(CPU_MC56F84451VLF))
#include "MC56F84451_COMMON.h"
#elif (defined(CPU_MC56F84452VLH))
#include "MC56F84452_COMMON.h"
#elif (defined(CPU_MC56F84462VLH))
#include "MC56F84462_COMMON.h"
#elif (defined(CPU_MC56F84540VLF))
#include "MC56F84540_COMMON.h"
#elif (defined(CPU_MC56F84543VLH))
#include "MC56F84543_COMMON.h"
#elif (defined(CPU_MC56F84550VLF))
#include "MC56F84550_COMMON.h"
#elif (defined(CPU_MC56F84553VLH))
#include "MC56F84553_COMMON.h"
#elif (defined(CPU_MC56F84565VLK))
#include "MC56F84565_COMMON.h"
#elif (defined(CPU_MC56F84567VLL))
#include "MC56F84567_COMMON.h"
#elif (defined(CPU_MC56F84587VLL))
#include "MC56F84587_COMMON.h"
#elif (defined(CPU_MC56F84763VLH))
#include "MC56F84763_COMMON.h"
#elif (defined(CPU_MC56F84766VLK))
#include "MC56F84766_COMMON.h"
#elif (defined(CPU_MC56F84769VLL))
#include "MC56F84769_COMMON.h"
#elif (defined(CPU_MC56F84786VLK))
#include "MC56F84786_COMMON.h"
#elif (defined(CPU_MC56F84789VLL))
#include "MC56F84789_COMMON.h"
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Size of Registers Arrays */
#define ADC_RSLT_COUNT                            16u
#define ADC_LOLIM_COUNT                           16u
#define ADC_HILIM_COUNT                           16u
#define ADC_OFFST_COUNT                           16u

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint16_t CTRL1;                             /**< ADC Control Register 1, offset: 0x0 */
  __IO uint16_t CTRL2;                             /**< ADC Control Register 2, offset: 0x1 */
  __IO uint16_t ZXCTRL1;                           /**< ADC Zero Crossing Control 1 Register, offset: 0x2 */
  __IO uint16_t ZXCTRL2;                           /**< ADC Zero Crossing Control 2 Register, offset: 0x3 */
  __IO uint16_t CLIST1;                            /**< ADC Channel List Register 1, offset: 0x4 */
  __IO uint16_t CLIST2;                            /**< ADC Channel List Register 2, offset: 0x5 */
  __IO uint16_t CLIST3;                            /**< ADC Channel List Register 3, offset: 0x6 */
  __IO uint16_t CLIST4;                            /**< ADC Channel List Register 4, offset: 0x7 */
  __IO uint16_t SDIS;                              /**< ADC Sample Disable Register, offset: 0x8 */
  __IO uint16_t STAT;                              /**< ADC Status Register, offset: 0x9 */
  __I  uint16_t RDY;                               /**< ADC Ready Register, offset: 0xA */
  __IO uint16_t LOLIMSTAT;                         /**< ADC Low Limit Status Register, offset: 0xB */
  __IO uint16_t HILIMSTAT;                         /**< ADC High Limit Status Register, offset: 0xC */
  __IO uint16_t ZXSTAT;                            /**< ADC Zero Crossing Status Register, offset: 0xD */
  __IO uint16_t RSLT[ADC_RSLT_COUNT];              /**< ADC Result Registers with sign extension, array offset: 0xE, array step: 0x1 */
  __IO uint16_t LOLIM[ADC_LOLIM_COUNT];            /**< ADC Low Limit Registers, array offset: 0x1E, array step: 0x1 */
  __IO uint16_t HILIM[ADC_HILIM_COUNT];            /**< ADC High Limit Registers, array offset: 0x2E, array step: 0x1 */
  __IO uint16_t OFFST[ADC_OFFST_COUNT];            /**< ADC Offset Registers, array offset: 0x3E, array step: 0x1 */
  __IO uint16_t PWR;                               /**< ADC Power Control Register, offset: 0x4E */
  __IO uint16_t CAL;                               /**< ADC Calibration Register, offset: 0x4F */
  __IO uint16_t GC1;                               /**< Gain Control 1 Register, offset: 0x50 */
  __IO uint16_t GC2;                               /**< Gain Control 2 Register, offset: 0x51 */
  __IO uint16_t SCTRL;                             /**< ADC Scan Control Register, offset: 0x52 */
  __IO uint16_t PWR2;                              /**< ADC Power Control Register, offset: 0x53 */
  __IO uint16_t CTRL3;                             /**< ADC Control Register 3, offset: 0x54 */
  __IO uint16_t SCHLTEN;                           /**< ADC Scan Halted Interrupt Enable Register, offset: 0x55 */
} ADC_Type;

/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/*! @name CTRL1 - ADC Control Register 1 */
/*! @{ */

#define ADC_CTRL1_SMODE_MASK                     (0x7U)
#define ADC_CTRL1_SMODE_SHIFT                    (0U)
/*! SMODE - ADC Scan Mode Control
 *  0b000..Once (single) sequential
 *  0b001..Once parallel
 *  0b010..Loop sequential
 *  0b011..Loop parallel
 *  0b100..Triggered sequential
 *  0b101..Triggered parallel (default)
 *  0b11x..Reserved
 */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_SMODE_SHIFT)) & ADC_CTRL1_SMODE_MASK)

#define ADC_CTRL1_CHNCFG_L_MASK                  (0xF0U)
#define ADC_CTRL1_CHNCFG_L_SHIFT                 (4U)
/*! CHNCFG_L - CHCNF (Channel Configure Low) bits
 *  0b1xxx..Inputs = ANB2-ANB3 Configured as differential pair (ANB2 is + and ANB3 is --)
 *  0bx0xx..Inputs = ANB0-ANB1 Both configured as single ended inputs
 *  0bx1xx..Inputs = ANB0-ANB1 Configured as differential pair (ANB0 is + and ANB1 is --)
 *  0bxx0x..Inputs = ANA2-ANA3 Both configured as single ended inputs
 *  0bxx1x..Inputs = ANA2-ANA3 Configured as differential pair (ANA2 is + and ANA3 is --)
 *  0bxxx0..Inputs = ANA0-ANA1 Both configured as single ended inputs
 *  0bxxx1..Inputs = ANA0-ANA1 Configured as differential pair (ANA0 is + and ANA1 is --)
 */
#define ADC_CTRL1_CHNCFG_L(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_CHNCFG_L_SHIFT)) & ADC_CTRL1_CHNCFG_L_MASK)

#define ADC_CTRL1_HLMTIE_MASK                    (0x100U)
#define ADC_CTRL1_HLMTIE_SHIFT                   (8U)
/*! HLMTIE - High Limit Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CTRL1_HLMTIE(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_HLMTIE_SHIFT)) & ADC_CTRL1_HLMTIE_MASK)

#define ADC_CTRL1_LLMTIE_MASK                    (0x200U)
#define ADC_CTRL1_LLMTIE_SHIFT                   (9U)
/*! LLMTIE - Low Limit Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CTRL1_LLMTIE(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_LLMTIE_SHIFT)) & ADC_CTRL1_LLMTIE_MASK)

#define ADC_CTRL1_ZCIE_MASK                      (0x400U)
#define ADC_CTRL1_ZCIE_SHIFT                     (10U)
/*! ZCIE - Zero Crossing Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CTRL1_ZCIE(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_ZCIE_SHIFT)) & ADC_CTRL1_ZCIE_MASK)

#define ADC_CTRL1_EOSIE0_MASK                    (0x800U)
#define ADC_CTRL1_EOSIE0_SHIFT                   (11U)
/*! EOSIE0 - End Of Scan Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CTRL1_EOSIE0(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_EOSIE0_SHIFT)) & ADC_CTRL1_EOSIE0_MASK)

#define ADC_CTRL1_SYNC0_MASK                     (0x1000U)
#define ADC_CTRL1_SYNC0_SHIFT                    (12U)
/*! SYNC0 - SYNC0 Enable
 *  0b0..Scan is initiated by a write to CTRL1[START0] only
 *  0b1..Use a SYNC0 input pulse or CTRL1[START0] to initiate a scan
 */
#define ADC_CTRL1_SYNC0(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_SYNC0_SHIFT)) & ADC_CTRL1_SYNC0_MASK)

#define ADC_CTRL1_START0_MASK                    (0x2000U)
#define ADC_CTRL1_START0_SHIFT                   (13U)
/*! START0 - START0 Conversion
 *  0b0..No action
 *  0b1..Start command is issued
 */
#define ADC_CTRL1_START0(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_START0_SHIFT)) & ADC_CTRL1_START0_MASK)

#define ADC_CTRL1_STOP0_MASK                     (0x4000U)
#define ADC_CTRL1_STOP0_SHIFT                    (14U)
/*! STOP0 - Stop
 *  0b0..Normal operation
 *  0b1..Stop mode
 */
#define ADC_CTRL1_STOP0(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_STOP0_SHIFT)) & ADC_CTRL1_STOP0_MASK)

#define ADC_CTRL1_DMAEN0_MASK                    (0x8000U)
#define ADC_CTRL1_DMAEN0_SHIFT                   (15U)
/*! DMAEN0 - DMA enable
 *  0b0..DMA is not enabled.
 *  0b1..DMA is enabled.
 */
#define ADC_CTRL1_DMAEN0(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_DMAEN0_SHIFT)) & ADC_CTRL1_DMAEN0_MASK)
/*! @} */

/*! @name CTRL2 - ADC Control Register 2 */
/*! @{ */

#define ADC_CTRL2_DIV0_MASK                      (0x3FU)
#define ADC_CTRL2_DIV0_SHIFT                     (0U)
/*! DIV0 - Clock Divisor Select */
#define ADC_CTRL2_DIV0(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_DIV0_SHIFT)) & ADC_CTRL2_DIV0_MASK)

#define ADC_CTRL2_SIMULT_MASK                    (0x40U)
#define ADC_CTRL2_SIMULT_SHIFT                   (6U)
/*! SIMULT - Simultaneous mode
 *  0b0..Parallel scans done independently
 *  0b1..Parallel scans done simultaneously (default)
 */
#define ADC_CTRL2_SIMULT(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_SIMULT_SHIFT)) & ADC_CTRL2_SIMULT_MASK)

#define ADC_CTRL2_CHNCFG_H_MASK                  (0x780U)
#define ADC_CTRL2_CHNCFG_H_SHIFT                 (7U)
/*! CHNCFG_H - CHCNF (Channel Configure High) bits
 *  0b1xxx..Inputs = ANB6-ANB7 Configured as differential pair (ANB6 is + and ANB7 is --)
 *  0bx0xx..Inputs = ANB4-ANB5 Both configured as single ended inputs
 *  0bx1xx..Inputs = ANB4-ANB5 Configured as differential pair (ANB4 is + and ANB5 is --)
 *  0bxx0x..Inputs = ANA6-ANA7 Both configured as single ended inputs
 *  0bxx1x..Inputs = ANA6-ANA7 Configured as differential pair (ANA6 is + and ANA7 is --)
 *  0bxxx0..Inputs = ANA4-ANA5 Both configured as single ended inputs
 *  0bxxx1..Inputs = ANA4-ANA5 Configured as differential pair (ANA4 is + and ANA5 is --)
 */
#define ADC_CTRL2_CHNCFG_H(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_CHNCFG_H_SHIFT)) & ADC_CTRL2_CHNCFG_H_MASK)

#define ADC_CTRL2_EOSIE1_MASK                    (0x800U)
#define ADC_CTRL2_EOSIE1_SHIFT                   (11U)
/*! EOSIE1 - End Of Scan Interrupt Enable
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define ADC_CTRL2_EOSIE1(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_EOSIE1_SHIFT)) & ADC_CTRL2_EOSIE1_MASK)

#define ADC_CTRL2_SYNC1_MASK                     (0x1000U)
#define ADC_CTRL2_SYNC1_SHIFT                    (12U)
/*! SYNC1 - SYNC1 Enable
 *  0b0..B converter parallel scan is initiated by a write to CTRL2[START1] bit only
 *  0b1..Use a SYNC1 input pulse or CTRL2[START1] bit to initiate a B converter parallel scan
 */
#define ADC_CTRL2_SYNC1(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_SYNC1_SHIFT)) & ADC_CTRL2_SYNC1_MASK)

#define ADC_CTRL2_START1_MASK                    (0x2000U)
#define ADC_CTRL2_START1_SHIFT                   (13U)
/*! START1 - START1 Conversion
 *  0b0..No action
 *  0b1..Start command is issued
 */
#define ADC_CTRL2_START1(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_START1_SHIFT)) & ADC_CTRL2_START1_MASK)

#define ADC_CTRL2_STOP1_MASK                     (0x4000U)
#define ADC_CTRL2_STOP1_SHIFT                    (14U)
/*! STOP1 - Stop
 *  0b0..Normal operation
 *  0b1..Stop mode
 */
#define ADC_CTRL2_STOP1(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_STOP1_SHIFT)) & ADC_CTRL2_STOP1_MASK)

#define ADC_CTRL2_DMAEN1_MASK                    (0x8000U)
#define ADC_CTRL2_DMAEN1_SHIFT                   (15U)
/*! DMAEN1 - DMA enable
 *  0b0..DMA is not enabled.
 *  0b1..DMA is enabled.
 */
#define ADC_CTRL2_DMAEN1(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL2_DMAEN1_SHIFT)) & ADC_CTRL2_DMAEN1_MASK)
/*! @} */

/*! @name ZXCTRL1 - ADC Zero Crossing Control 1 Register */
/*! @{ */

#define ADC_ZXCTRL1_ZCE0_MASK                    (0x3U)
#define ADC_ZXCTRL1_ZCE0_SHIFT                   (0U)
/*! ZCE0 - Zero crossing enable 0
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE0(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE0_SHIFT)) & ADC_ZXCTRL1_ZCE0_MASK)

#define ADC_ZXCTRL1_ZCE1_MASK                    (0xCU)
#define ADC_ZXCTRL1_ZCE1_SHIFT                   (2U)
/*! ZCE1 - Zero crossing enable 1
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE1(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE1_SHIFT)) & ADC_ZXCTRL1_ZCE1_MASK)

#define ADC_ZXCTRL1_ZCE2_MASK                    (0x30U)
#define ADC_ZXCTRL1_ZCE2_SHIFT                   (4U)
/*! ZCE2 - Zero crossing enable 2
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE2(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE2_SHIFT)) & ADC_ZXCTRL1_ZCE2_MASK)

#define ADC_ZXCTRL1_ZCE3_MASK                    (0xC0U)
#define ADC_ZXCTRL1_ZCE3_SHIFT                   (6U)
/*! ZCE3 - Zero crossing enable 3
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE3(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE3_SHIFT)) & ADC_ZXCTRL1_ZCE3_MASK)

#define ADC_ZXCTRL1_ZCE4_MASK                    (0x300U)
#define ADC_ZXCTRL1_ZCE4_SHIFT                   (8U)
/*! ZCE4 - Zero crossing enable 4
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE4(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE4_SHIFT)) & ADC_ZXCTRL1_ZCE4_MASK)

#define ADC_ZXCTRL1_ZCE5_MASK                    (0xC00U)
#define ADC_ZXCTRL1_ZCE5_SHIFT                   (10U)
/*! ZCE5 - Zero crossing enable 5
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE5(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE5_SHIFT)) & ADC_ZXCTRL1_ZCE5_MASK)

#define ADC_ZXCTRL1_ZCE6_MASK                    (0x3000U)
#define ADC_ZXCTRL1_ZCE6_SHIFT                   (12U)
/*! ZCE6 - Zero crossing enable 6
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE6(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE6_SHIFT)) & ADC_ZXCTRL1_ZCE6_MASK)

#define ADC_ZXCTRL1_ZCE7_MASK                    (0xC000U)
#define ADC_ZXCTRL1_ZCE7_SHIFT                   (14U)
/*! ZCE7 - Zero crossing enable 7
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL1_ZCE7(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL1_ZCE7_SHIFT)) & ADC_ZXCTRL1_ZCE7_MASK)
/*! @} */

/*! @name ZXCTRL2 - ADC Zero Crossing Control 2 Register */
/*! @{ */

#define ADC_ZXCTRL2_ZCE8_MASK                    (0x3U)
#define ADC_ZXCTRL2_ZCE8_SHIFT                   (0U)
/*! ZCE8 - Zero crossing enable 8
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE8(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE8_SHIFT)) & ADC_ZXCTRL2_ZCE8_MASK)

#define ADC_ZXCTRL2_ZCE9_MASK                    (0xCU)
#define ADC_ZXCTRL2_ZCE9_SHIFT                   (2U)
/*! ZCE9 - Zero crossing enable 9
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE9(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE9_SHIFT)) & ADC_ZXCTRL2_ZCE9_MASK)

#define ADC_ZXCTRL2_ZCE10_MASK                   (0x30U)
#define ADC_ZXCTRL2_ZCE10_SHIFT                  (4U)
/*! ZCE10 - Zero crossing enable 10
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE10(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE10_SHIFT)) & ADC_ZXCTRL2_ZCE10_MASK)

#define ADC_ZXCTRL2_ZCE11_MASK                   (0xC0U)
#define ADC_ZXCTRL2_ZCE11_SHIFT                  (6U)
/*! ZCE11 - Zero crossing enable 11
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE11(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE11_SHIFT)) & ADC_ZXCTRL2_ZCE11_MASK)

#define ADC_ZXCTRL2_ZCE12_MASK                   (0x300U)
#define ADC_ZXCTRL2_ZCE12_SHIFT                  (8U)
/*! ZCE12 - Zero crossing enable 12
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE12(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE12_SHIFT)) & ADC_ZXCTRL2_ZCE12_MASK)

#define ADC_ZXCTRL2_ZCE13_MASK                   (0xC00U)
#define ADC_ZXCTRL2_ZCE13_SHIFT                  (10U)
/*! ZCE13 - Zero crossing enable 13
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE13(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE13_SHIFT)) & ADC_ZXCTRL2_ZCE13_MASK)

#define ADC_ZXCTRL2_ZCE14_MASK                   (0x3000U)
#define ADC_ZXCTRL2_ZCE14_SHIFT                  (12U)
/*! ZCE14 - Zero crossing enable 14
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE14(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE14_SHIFT)) & ADC_ZXCTRL2_ZCE14_MASK)

#define ADC_ZXCTRL2_ZCE15_MASK                   (0xC000U)
#define ADC_ZXCTRL2_ZCE15_SHIFT                  (14U)
/*! ZCE15 - Zero crossing enable 15
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL2_ZCE15(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL2_ZCE15_SHIFT)) & ADC_ZXCTRL2_ZCE15_MASK)
/*! @} */

/*! @name CLIST1 - ADC Channel List Register 1 */
/*! @{ */

#define ADC_CLIST1_SAMPLE0_MASK                  (0xFU)
#define ADC_CLIST1_SAMPLE0_SHIFT                 (0U)
/*! SAMPLE0 - Sample Field 0
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST1_SAMPLE0(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST1_SAMPLE0_SHIFT)) & ADC_CLIST1_SAMPLE0_MASK)

#define ADC_CLIST1_SAMPLE1_MASK                  (0xF0U)
#define ADC_CLIST1_SAMPLE1_SHIFT                 (4U)
/*! SAMPLE1 - Sample Field 1
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST1_SAMPLE1(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST1_SAMPLE1_SHIFT)) & ADC_CLIST1_SAMPLE1_MASK)

#define ADC_CLIST1_SAMPLE2_MASK                  (0xF00U)
#define ADC_CLIST1_SAMPLE2_SHIFT                 (8U)
/*! SAMPLE2 - Sample Field 2
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST1_SAMPLE2(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST1_SAMPLE2_SHIFT)) & ADC_CLIST1_SAMPLE2_MASK)

#define ADC_CLIST1_SAMPLE3_MASK                  (0xF000U)
#define ADC_CLIST1_SAMPLE3_SHIFT                 (12U)
/*! SAMPLE3 - Sample Field 3
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST1_SAMPLE3(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST1_SAMPLE3_SHIFT)) & ADC_CLIST1_SAMPLE3_MASK)
/*! @} */

/*! @name CLIST2 - ADC Channel List Register 2 */
/*! @{ */

#define ADC_CLIST2_SAMPLE4_MASK                  (0xFU)
#define ADC_CLIST2_SAMPLE4_SHIFT                 (0U)
/*! SAMPLE4 - Sample Field 4
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST2_SAMPLE4(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST2_SAMPLE4_SHIFT)) & ADC_CLIST2_SAMPLE4_MASK)

#define ADC_CLIST2_SAMPLE5_MASK                  (0xF0U)
#define ADC_CLIST2_SAMPLE5_SHIFT                 (4U)
/*! SAMPLE5 - Sample Field 5
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST2_SAMPLE5(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST2_SAMPLE5_SHIFT)) & ADC_CLIST2_SAMPLE5_MASK)

#define ADC_CLIST2_SAMPLE6_MASK                  (0xF00U)
#define ADC_CLIST2_SAMPLE6_SHIFT                 (8U)
/*! SAMPLE6 - Sample Field 6
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST2_SAMPLE6(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST2_SAMPLE6_SHIFT)) & ADC_CLIST2_SAMPLE6_MASK)

#define ADC_CLIST2_SAMPLE7_MASK                  (0xF000U)
#define ADC_CLIST2_SAMPLE7_SHIFT                 (12U)
/*! SAMPLE7 - Sample Field 7
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST2_SAMPLE7(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST2_SAMPLE7_SHIFT)) & ADC_CLIST2_SAMPLE7_MASK)
/*! @} */

/*! @name CLIST3 - ADC Channel List Register 3 */
/*! @{ */

#define ADC_CLIST3_SAMPLE8_MASK                  (0xFU)
#define ADC_CLIST3_SAMPLE8_SHIFT                 (0U)
/*! SAMPLE8 - Sample Field 8
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST3_SAMPLE8(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST3_SAMPLE8_SHIFT)) & ADC_CLIST3_SAMPLE8_MASK)

#define ADC_CLIST3_SAMPLE9_MASK                  (0xF0U)
#define ADC_CLIST3_SAMPLE9_SHIFT                 (4U)
/*! SAMPLE9 - Sample Field 9
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST3_SAMPLE9(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_CLIST3_SAMPLE9_SHIFT)) & ADC_CLIST3_SAMPLE9_MASK)

#define ADC_CLIST3_SAMPLE10_MASK                 (0xF00U)
#define ADC_CLIST3_SAMPLE10_SHIFT                (8U)
/*! SAMPLE10 - Sample Field 10
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST3_SAMPLE10(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST3_SAMPLE10_SHIFT)) & ADC_CLIST3_SAMPLE10_MASK)

#define ADC_CLIST3_SAMPLE11_MASK                 (0xF000U)
#define ADC_CLIST3_SAMPLE11_SHIFT                (12U)
/*! SAMPLE11 - Sample Field 11
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST3_SAMPLE11(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST3_SAMPLE11_SHIFT)) & ADC_CLIST3_SAMPLE11_MASK)
/*! @} */

/*! @name CLIST4 - ADC Channel List Register 4 */
/*! @{ */

#define ADC_CLIST4_SAMPLE12_MASK                 (0xFU)
#define ADC_CLIST4_SAMPLE12_SHIFT                (0U)
/*! SAMPLE12 - Sample Field 12
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST4_SAMPLE12(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST4_SAMPLE12_SHIFT)) & ADC_CLIST4_SAMPLE12_MASK)

#define ADC_CLIST4_SAMPLE13_MASK                 (0xF0U)
#define ADC_CLIST4_SAMPLE13_SHIFT                (4U)
/*! SAMPLE13 - Sample Field 13
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST4_SAMPLE13(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST4_SAMPLE13_SHIFT)) & ADC_CLIST4_SAMPLE13_MASK)

#define ADC_CLIST4_SAMPLE14_MASK                 (0xF00U)
#define ADC_CLIST4_SAMPLE14_SHIFT                (8U)
/*! SAMPLE14 - Sample Field 14
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST4_SAMPLE14(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST4_SAMPLE14_SHIFT)) & ADC_CLIST4_SAMPLE14_MASK)

#define ADC_CLIST4_SAMPLE15_MASK                 (0xF000U)
#define ADC_CLIST4_SAMPLE15_SHIFT                (12U)
/*! SAMPLE15 - Sample Field 15
 *  0b0000..Single Ended: ANA0, Differential: ANA0+, ANA1-
 *  0b0001..Single Ended: ANA1, Differential: ANA0+, ANA1-
 *  0b0010..Single Ended: ANA2, Differential: ANA2+, ANA3-
 *  0b0011..Single Ended: ANA3, Differential: ANA2+, ANA3-
 *  0b0100..Single Ended: ANA4, Differential: ANA4+, ANA5-
 *  0b0101..Single Ended: ANA5, Differential: ANA4+, ANA5-
 *  0b0110..Single Ended: ANA6, Differential: ANA6+, ANA7-
 *  0b0111..Single Ended: ANA7, Differential: ANA6+, ANA7-
 *  0b1000..Single Ended: ANB0, Differential: ANB0+, ANB1-
 *  0b1001..Single Ended: ANB1, Differential: ANB0+, ANB1-
 *  0b1010..Single Ended: ANB2, Differential: ANB2+, ANB3-
 *  0b1011..Single Ended: ANB3, Differential: ANB2+, ANB3-
 *  0b1100..Single Ended: ANB4, Differential: ANB4+, ANB5-
 *  0b1101..Single Ended: ANB5, Differential: ANB4+, ANB5-
 *  0b1110..Single Ended: ANB6, Differential: ANB6+, ANB7-
 *  0b1111..Single Ended: ANB7, Differential: ANB6+, ANB7-
 */
#define ADC_CLIST4_SAMPLE15(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST4_SAMPLE15_SHIFT)) & ADC_CLIST4_SAMPLE15_MASK)
/*! @} */

/*! @name SDIS - ADC Sample Disable Register */
/*! @{ */

#define ADC_SDIS_DS_MASK                         (0xFFFFU)
#define ADC_SDIS_DS_SHIFT                        (0U)
/*! DS - Disable Sample Bits
 *  0b0000000000000000..Enable CLIST*[SAMPLEx].
 *  0b0000000000000001..Disable CLIST*[SAMPLEx] and all subsequent samples. Which samples are actually disabled
 *                      will depend on the conversion mode, sequential/parallel, and the value of CTRL2[SIMULT].
 */
#define ADC_SDIS_DS(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_SDIS_DS_SHIFT)) & ADC_SDIS_DS_MASK)
/*! @} */

/*! @name STAT - ADC Status Register */
/*! @{ */

#define ADC_STAT_UNDEFINED_MASK                  (0xFFU)
#define ADC_STAT_UNDEFINED_SHIFT                 (0U)
#define ADC_STAT_UNDEFINED(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_STAT_UNDEFINED_SHIFT)) & ADC_STAT_UNDEFINED_MASK)

#define ADC_STAT_HLMTI_MASK                      (0x100U)
#define ADC_STAT_HLMTI_SHIFT                     (8U)
/*! HLMTI - High Limit Interrupt
 *  0b0..No high limit interrupt request
 *  0b1..High limit exceeded, IRQ pending if CTRL1[HLMTIE] is set
 */
#define ADC_STAT_HLMTI(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_STAT_HLMTI_SHIFT)) & ADC_STAT_HLMTI_MASK)

#define ADC_STAT_LLMTI_MASK                      (0x200U)
#define ADC_STAT_LLMTI_SHIFT                     (9U)
/*! LLMTI - Low Limit Interrupt
 *  0b0..No low limit interrupt request
 *  0b1..Low limit exceeded, IRQ pending if CTRL1[LLMTIE] is set
 */
#define ADC_STAT_LLMTI(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_STAT_LLMTI_SHIFT)) & ADC_STAT_LLMTI_MASK)

#define ADC_STAT_ZCI_MASK                        (0x400U)
#define ADC_STAT_ZCI_SHIFT                       (10U)
/*! ZCI - Zero Crossing Interrupt
 *  0b0..No zero crossing interrupt request
 *  0b1..Zero crossing encountered, IRQ pending if CTRL1[ZCIE] is set
 */
#define ADC_STAT_ZCI(x)                          (((uint16_t)(((uint16_t)(x)) << ADC_STAT_ZCI_SHIFT)) & ADC_STAT_ZCI_MASK)

#define ADC_STAT_EOSI0_MASK                      (0x800U)
#define ADC_STAT_EOSI0_SHIFT                     (11U)
/*! EOSI0 - End of Scan Interrupt
 *  0b0..A scan cycle has not been completed, no end of scan IRQ pending
 *  0b1..A scan cycle has been completed, end of scan IRQ pending
 */
#define ADC_STAT_EOSI0(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_STAT_EOSI0_SHIFT)) & ADC_STAT_EOSI0_MASK)

#define ADC_STAT_EOSI1_MASK                      (0x1000U)
#define ADC_STAT_EOSI1_SHIFT                     (12U)
/*! EOSI1 - End of Scan Interrupt
 *  0b0..A scan cycle has not been completed, no end of scan IRQ pending
 *  0b1..A scan cycle has been completed, end of scan IRQ pending
 */
#define ADC_STAT_EOSI1(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_STAT_EOSI1_SHIFT)) & ADC_STAT_EOSI1_MASK)

#define ADC_STAT_CIP1_MASK                       (0x4000U)
#define ADC_STAT_CIP1_SHIFT                      (14U)
/*! CIP1 - Conversion in Progress
 *  0b0..Idle state
 *  0b1..A scan cycle is in progress. The ADC will ignore all sync pulses or start commands
 */
#define ADC_STAT_CIP1(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_STAT_CIP1_SHIFT)) & ADC_STAT_CIP1_MASK)

#define ADC_STAT_CIP0_MASK                       (0x8000U)
#define ADC_STAT_CIP0_SHIFT                      (15U)
/*! CIP0 - Conversion in Progress
 *  0b0..Idle state
 *  0b1..A scan cycle is in progress. The ADC will ignore all sync pulses or start commands
 */
#define ADC_STAT_CIP0(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_STAT_CIP0_SHIFT)) & ADC_STAT_CIP0_MASK)
/*! @} */

/*! @name RDY - ADC Ready Register */
/*! @{ */

#define ADC_RDY_RDY_MASK                         (0xFFFFU)
#define ADC_RDY_RDY_SHIFT                        (0U)
/*! RDY - Ready Sample
 *  0b0000000000000000..Sample not ready or has been read
 *  0b0000000000000001..Sample ready to be read
 */
#define ADC_RDY_RDY(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_RDY_RDY_SHIFT)) & ADC_RDY_RDY_MASK)
/*! @} */

/*! @name LOLIMSTAT - ADC Low Limit Status Register */
/*! @{ */

#define ADC_LOLIMSTAT_LLS_MASK                   (0xFFFFU)
#define ADC_LOLIMSTAT_LLS_SHIFT                  (0U)
/*! LLS - Low Limit Status Bits */
#define ADC_LOLIMSTAT_LLS(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_LOLIMSTAT_LLS_SHIFT)) & ADC_LOLIMSTAT_LLS_MASK)
/*! @} */

/*! @name HILIMSTAT - ADC High Limit Status Register */
/*! @{ */

#define ADC_HILIMSTAT_HLS_MASK                   (0xFFFFU)
#define ADC_HILIMSTAT_HLS_SHIFT                  (0U)
/*! HLS - High Limit Status Bits */
#define ADC_HILIMSTAT_HLS(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_HILIMSTAT_HLS_SHIFT)) & ADC_HILIMSTAT_HLS_MASK)
/*! @} */

/*! @name ZXSTAT - ADC Zero Crossing Status Register */
/*! @{ */

#define ADC_ZXSTAT_ZCS_MASK                      (0xFFFFU)
#define ADC_ZXSTAT_ZCS_SHIFT                     (0U)
/*! ZCS - Zero Crossing Status
 *  0b0000000000000000..Either: A sign change did not occur in a comparison between the current channelx result
 *                      and the previous channelx result, or Zero crossing control is disabled for channelx in the
 *                      zero crossing control register, ZXCTRL
 *  0b0000000000000001..In a comparison between the current channelx result and the previous channelx result, a
 *                      sign change condition occurred as defined in the zero crossing control register (ZXCTRL)
 */
#define ADC_ZXSTAT_ZCS(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_ZXSTAT_ZCS_SHIFT)) & ADC_ZXSTAT_ZCS_MASK)
/*! @} */

/*! @name RSLT - ADC Result Registers with sign extension */
/*! @{ */

#define ADC_RSLT_RSLT_MASK                       (0x7FF8U)
#define ADC_RSLT_RSLT_SHIFT                      (3U)
/*! RSLT - Digital Result of the Conversion */
#define ADC_RSLT_RSLT(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_RSLT_RSLT_SHIFT)) & ADC_RSLT_RSLT_MASK)

#define ADC_RSLT_SEXT_MASK                       (0x8000U)
#define ADC_RSLT_SEXT_SHIFT                      (15U)
/*! SEXT - Sign Extend */
#define ADC_RSLT_SEXT(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_RSLT_SEXT_SHIFT)) & ADC_RSLT_SEXT_MASK)
/*! @} */

/*! @name LOLIM - ADC Low Limit Registers */
/*! @{ */

#define ADC_LOLIM_LLMT_MASK                      (0x7FF8U)
#define ADC_LOLIM_LLMT_SHIFT                     (3U)
/*! LLMT - Low Limit Bits */
#define ADC_LOLIM_LLMT(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_LOLIM_LLMT_SHIFT)) & ADC_LOLIM_LLMT_MASK)
/*! @} */

/*! @name HILIM - ADC High Limit Registers */
/*! @{ */

#define ADC_HILIM_HLMT_MASK                      (0x7FF8U)
#define ADC_HILIM_HLMT_SHIFT                     (3U)
/*! HLMT - High Limit Bits */
#define ADC_HILIM_HLMT(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_HILIM_HLMT_SHIFT)) & ADC_HILIM_HLMT_MASK)
/*! @} */

/*! @name OFFST - ADC Offset Registers */
/*! @{ */

#define ADC_OFFST_OFFSET_MASK                    (0x7FF8U)
#define ADC_OFFST_OFFSET_SHIFT                   (3U)
/*! OFFSET - ADC Offset Bits */
#define ADC_OFFST_OFFSET(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_OFFST_OFFSET_SHIFT)) & ADC_OFFST_OFFSET_MASK)
/*! @} */

/*! @name PWR - ADC Power Control Register */
/*! @{ */

#define ADC_PWR_PD0_MASK                         (0x1U)
#define ADC_PWR_PD0_SHIFT                        (0U)
/*! PD0 - Manual Power Down for Converter A
 *  0b0..Power Up ADC converter A
 *  0b1..Power Down ADC converter A
 */
#define ADC_PWR_PD0(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_PWR_PD0_SHIFT)) & ADC_PWR_PD0_MASK)

#define ADC_PWR_PD1_MASK                         (0x2U)
#define ADC_PWR_PD1_SHIFT                        (1U)
/*! PD1 - Manual Power Down for Converter B
 *  0b0..Power Up ADC converter B
 *  0b1..Power Down ADC converter B
 */
#define ADC_PWR_PD1(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_PWR_PD1_SHIFT)) & ADC_PWR_PD1_MASK)

#define ADC_PWR_APD_MASK                         (0x8U)
#define ADC_PWR_APD_SHIFT                        (3U)
/*! APD - Auto Powerdown
 *  0b0..Auto Powerdown Mode is not active
 *  0b1..Auto Powerdown Mode is active
 */
#define ADC_PWR_APD(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_PWR_APD_SHIFT)) & ADC_PWR_APD_MASK)

#define ADC_PWR_PUDELAY_MASK                     (0x3F0U)
#define ADC_PWR_PUDELAY_SHIFT                    (4U)
/*! PUDELAY - Power Up Delay */
#define ADC_PWR_PUDELAY(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_PWR_PUDELAY_SHIFT)) & ADC_PWR_PUDELAY_MASK)

#define ADC_PWR_PSTS0_MASK                       (0x400U)
#define ADC_PWR_PSTS0_SHIFT                      (10U)
/*! PSTS0 - ADC Converter A Power Status
 *  0b0..ADC Converter A is currently powered up
 *  0b1..ADC Converter A is currently powered down
 */
#define ADC_PWR_PSTS0(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_PWR_PSTS0_SHIFT)) & ADC_PWR_PSTS0_MASK)

#define ADC_PWR_PSTS1_MASK                       (0x800U)
#define ADC_PWR_PSTS1_SHIFT                      (11U)
/*! PSTS1 - ADC Converter B Power Status
 *  0b0..ADC Converter B is currently powered up
 *  0b1..ADC Converter B is currently powered down
 */
#define ADC_PWR_PSTS1(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_PWR_PSTS1_SHIFT)) & ADC_PWR_PSTS1_MASK)

#define ADC_PWR_ASB_MASK                         (0x8000U)
#define ADC_PWR_ASB_SHIFT                        (15U)
/*! ASB - Auto Standby
 *  0b0..Auto standby mode disabled
 *  0b1..Auto standby mode enabled
 */
#define ADC_PWR_ASB(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_PWR_ASB_SHIFT)) & ADC_PWR_ASB_MASK)
/*! @} */

/*! @name CAL - ADC Calibration Register */
/*! @{ */

#define ADC_CAL_SEL_VREFLO_A_MASK                (0x1000U)
#define ADC_CAL_SEL_VREFLO_A_SHIFT               (12U)
/*! SEL_VREFLO_A - Select V REFLO Source
 *  0b0..Internal VSSA
 *  0b1..ANA3
 */
#define ADC_CAL_SEL_VREFLO_A(x)                  (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFLO_A_SHIFT)) & ADC_CAL_SEL_VREFLO_A_MASK)

#define ADC_CAL_SEL_VREFH_A_MASK                 (0x2000U)
#define ADC_CAL_SEL_VREFH_A_SHIFT                (13U)
/*! SEL_VREFH_A - Select V REFH Source
 *  0b0..Internal VDDA
 *  0b1..ANA2
 */
#define ADC_CAL_SEL_VREFH_A(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFH_A_SHIFT)) & ADC_CAL_SEL_VREFH_A_MASK)

#define ADC_CAL_SEL_VREFLO_B_MASK                (0x4000U)
#define ADC_CAL_SEL_VREFLO_B_SHIFT               (14U)
/*! SEL_VREFLO_B - Select V REFLO Source
 *  0b0..Internal VSSA
 *  0b1..ANB3
 */
#define ADC_CAL_SEL_VREFLO_B(x)                  (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFLO_B_SHIFT)) & ADC_CAL_SEL_VREFLO_B_MASK)

#define ADC_CAL_SEL_VREFH_B_MASK                 (0x8000U)
#define ADC_CAL_SEL_VREFH_B_SHIFT                (15U)
/*! SEL_VREFH_B - Select V REFH Source
 *  0b0..Internal VDDA
 *  0b1..ANB2
 */
#define ADC_CAL_SEL_VREFH_B(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFH_B_SHIFT)) & ADC_CAL_SEL_VREFH_B_MASK)
/*! @} */

/*! @name GC1 - Gain Control 1 Register */
/*! @{ */

#define ADC_GC1_GAIN0_MASK                       (0x3U)
#define ADC_GC1_GAIN0_SHIFT                      (0U)
/*! GAIN0 - Gain Control Bit 0
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN0(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN0_SHIFT)) & ADC_GC1_GAIN0_MASK)

#define ADC_GC1_GAIN1_MASK                       (0xCU)
#define ADC_GC1_GAIN1_SHIFT                      (2U)
/*! GAIN1 - Gain Control Bit 1
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN1(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN1_SHIFT)) & ADC_GC1_GAIN1_MASK)

#define ADC_GC1_GAIN2_MASK                       (0x30U)
#define ADC_GC1_GAIN2_SHIFT                      (4U)
/*! GAIN2 - Gain Control Bit 2
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN2(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN2_SHIFT)) & ADC_GC1_GAIN2_MASK)

#define ADC_GC1_GAIN3_MASK                       (0xC0U)
#define ADC_GC1_GAIN3_SHIFT                      (6U)
/*! GAIN3 - Gain Control Bit 3
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN3(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN3_SHIFT)) & ADC_GC1_GAIN3_MASK)

#define ADC_GC1_GAIN4_MASK                       (0x300U)
#define ADC_GC1_GAIN4_SHIFT                      (8U)
/*! GAIN4 - Gain Control Bit 4
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN4(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN4_SHIFT)) & ADC_GC1_GAIN4_MASK)

#define ADC_GC1_GAIN5_MASK                       (0xC00U)
#define ADC_GC1_GAIN5_SHIFT                      (10U)
/*! GAIN5 - Gain Control Bit 5
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN5(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN5_SHIFT)) & ADC_GC1_GAIN5_MASK)

#define ADC_GC1_GAIN6_MASK                       (0x3000U)
#define ADC_GC1_GAIN6_SHIFT                      (12U)
/*! GAIN6 - Gain Control Bit 6
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN6(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN6_SHIFT)) & ADC_GC1_GAIN6_MASK)

#define ADC_GC1_GAIN7_MASK                       (0xC000U)
#define ADC_GC1_GAIN7_SHIFT                      (14U)
/*! GAIN7 - Gain Control Bit 7
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC1_GAIN7(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC1_GAIN7_SHIFT)) & ADC_GC1_GAIN7_MASK)
/*! @} */

/*! @name GC2 - Gain Control 2 Register */
/*! @{ */

#define ADC_GC2_GAIN8_MASK                       (0x3U)
#define ADC_GC2_GAIN8_SHIFT                      (0U)
/*! GAIN8 - Gain Control Bit 8
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN8(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN8_SHIFT)) & ADC_GC2_GAIN8_MASK)

#define ADC_GC2_GAIN9_MASK                       (0xCU)
#define ADC_GC2_GAIN9_SHIFT                      (2U)
/*! GAIN9 - Gain Control Bit 9
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN9(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN9_SHIFT)) & ADC_GC2_GAIN9_MASK)

#define ADC_GC2_GAIN10_MASK                      (0x30U)
#define ADC_GC2_GAIN10_SHIFT                     (4U)
/*! GAIN10 - Gain Control Bit 10
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN10(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN10_SHIFT)) & ADC_GC2_GAIN10_MASK)

#define ADC_GC2_GAIN11_MASK                      (0xC0U)
#define ADC_GC2_GAIN11_SHIFT                     (6U)
/*! GAIN11 - Gain Control Bit 11
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN11(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN11_SHIFT)) & ADC_GC2_GAIN11_MASK)

#define ADC_GC2_GAIN12_MASK                      (0x300U)
#define ADC_GC2_GAIN12_SHIFT                     (8U)
/*! GAIN12 - Gain Control Bit 12
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN12(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN12_SHIFT)) & ADC_GC2_GAIN12_MASK)

#define ADC_GC2_GAIN13_MASK                      (0xC00U)
#define ADC_GC2_GAIN13_SHIFT                     (10U)
/*! GAIN13 - Gain Control Bit 13
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN13(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN13_SHIFT)) & ADC_GC2_GAIN13_MASK)

#define ADC_GC2_GAIN14_MASK                      (0x3000U)
#define ADC_GC2_GAIN14_SHIFT                     (12U)
/*! GAIN14 - Gain Control Bit 14
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN14(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN14_SHIFT)) & ADC_GC2_GAIN14_MASK)

#define ADC_GC2_GAIN15_MASK                      (0xC000U)
#define ADC_GC2_GAIN15_SHIFT                     (14U)
/*! GAIN15 - Gain Control Bit 15
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC2_GAIN15(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC2_GAIN15_SHIFT)) & ADC_GC2_GAIN15_MASK)
/*! @} */

/*! @name SCTRL - ADC Scan Control Register */
/*! @{ */

#define ADC_SCTRL_SC_MASK                        (0xFFFFU)
#define ADC_SCTRL_SC_SHIFT                       (0U)
/*! SC - Scan Control Bits
 *  0b0000000000000000..Perform sample immediately after the completion of the current sample.
 *  0b0000000000000001..Delay sample until a new sync input occurs.
 */
#define ADC_SCTRL_SC(x)                          (((uint16_t)(((uint16_t)(x)) << ADC_SCTRL_SC_SHIFT)) & ADC_SCTRL_SC_MASK)
/*! @} */

/*! @name PWR2 - ADC Power Control Register */
/*! @{ */

#define ADC_PWR2_SPEEDA_MASK                     (0x3U)
#define ADC_PWR2_SPEEDA_SHIFT                    (0U)
/*! SPEEDA - ADCA Speed Control Bits
 *  0b00..Conversion clock frequency <= 5 MHz; current consumption per converter = 5 mA
 *  0b01..Conversion clock frequency <= 10 MHz; current consumption per converter = 9 mA
 *  0b10..Conversion clock frequency <= 15 MHz; current consumption per converter = 15 mA
 *  0b11..Conversion clock frequency <= 20 MHz; current consumption per converter = 21 mA
 */
#define ADC_PWR2_SPEEDA(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_PWR2_SPEEDA_SHIFT)) & ADC_PWR2_SPEEDA_MASK)

#define ADC_PWR2_SPEEDB_MASK                     (0xCU)
#define ADC_PWR2_SPEEDB_SHIFT                    (2U)
/*! SPEEDB - ADCB Speed Control Bits
 *  0b00..Conversion clock frequency <= 5 MHz; current consumption per converter = 5 mA
 *  0b01..Conversion clock frequency <= 10 MHz; current consumption per converter = 9 mA
 *  0b10..Conversion clock frequency <= 15 MHz; current consumption per converter = 15 mA
 *  0b11..Conversion clock frequency <= 20 MHz; current consumption per converter = 21 mA
 */
#define ADC_PWR2_SPEEDB(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_PWR2_SPEEDB_SHIFT)) & ADC_PWR2_SPEEDB_MASK)

#define ADC_PWR2_DIV1_MASK                       (0x3F00U)
#define ADC_PWR2_DIV1_SHIFT                      (8U)
/*! DIV1 - Clock Divisor Select */
#define ADC_PWR2_DIV1(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_PWR2_DIV1_SHIFT)) & ADC_PWR2_DIV1_MASK)
/*! @} */

/*! @name CTRL3 - ADC Control Register 3 */
/*! @{ */

#define ADC_CTRL3_SCNT0_MASK                     (0x7U)
#define ADC_CTRL3_SCNT0_SHIFT                    (0U)
/*! SCNT0 - Sample Window Count 0 */
#define ADC_CTRL3_SCNT0(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_SCNT0_SHIFT)) & ADC_CTRL3_SCNT0_MASK)

#define ADC_CTRL3_SCNT1_MASK                     (0x38U)
#define ADC_CTRL3_SCNT1_SHIFT                    (3U)
/*! SCNT1 - Sample Window Count 1 */
#define ADC_CTRL3_SCNT1(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_SCNT1_SHIFT)) & ADC_CTRL3_SCNT1_MASK)

#define ADC_CTRL3_DMASRC_MASK                    (0x40U)
#define ADC_CTRL3_DMASRC_SHIFT                   (6U)
/*! DMASRC - DMA Trigger Source
 *  0b0..DMA trigger source is end of scan interrupt
 *  0b1..DMA trigger source is RDY bits
 */
#define ADC_CTRL3_DMASRC(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_DMASRC_SHIFT)) & ADC_CTRL3_DMASRC_MASK)
/*! @} */

/*! @name SCHLTEN - ADC Scan Halted Interrupt Enable Register */
/*! @{ */

#define ADC_SCHLTEN_SCHLTEN_MASK                 (0xFFFFU)
#define ADC_SCHLTEN_SCHLTEN_SHIFT                (0U)
/*! SCHLTEN - Scan Halted Interrupt Enable
 *  0b0000000000000000..Scan halted interrupt is not enabled for this sample.
 *  0b0000000000000001..Scan halted interrupt is enabled for this sample.
 */
#define ADC_SCHLTEN_SCHLTEN(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_SCHLTEN_SCHLTEN_SHIFT)) & ADC_SCHLTEN_SCHLTEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_ADC_H_ */

