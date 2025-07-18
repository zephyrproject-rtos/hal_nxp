/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
**
**     Version:             rev. 1.0, 2024-10-29
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
**     - rev. 0.1 (2019-09-23)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ADC.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ADC
 *
 * CMSIS Peripheral Access Layer for ADC
 */

#if !defined(PERI_ADC_H_)
#define PERI_ADC_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
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
#define ADC_RSLT2_COUNT                           4u
#define ADC_LOLIM2_COUNT                          4u
#define ADC_HILIM2_COUNT                          4u
#define ADC_OFFST2_COUNT                          4u

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
  __IO uint16_t PWR2;                              /**< ADC Power Control Register 2, offset: 0x53 */
  __IO uint16_t CTRL3;                             /**< ADC Control Register 3, offset: 0x54 */
  __IO uint16_t SCHLTEN;                           /**< ADC Scan Interrupt Enable Register, offset: 0x55 */
       uint16_t RESERVED_0[2];
  __IO uint16_t ZXCTRL3;                           /**< ADC Zero Crossing Control 3 Register, offset: 0x58 */
  __IO uint16_t CLIST5;                            /**< ADC Channel List Register 5, offset: 0x59 */
  __IO uint16_t SDIS2;                             /**< ADC Sample Disable Register 2, offset: 0x5A */
  __I  uint16_t RDY2;                              /**< ADC Ready Register 2, offset: 0x5B */
  __IO uint16_t LOLIMSTAT2;                        /**< ADC Low Limit Status Register 2, offset: 0x5C */
  __IO uint16_t HILIMSTAT2;                        /**< ADC High Limit Status Register 2, offset: 0x5D */
  __IO uint16_t ZXSTAT2;                           /**< ADC Zero Crossing Status Register 2, offset: 0x5E */
  __IO uint16_t RSLT2[ADC_RSLT2_COUNT];            /**< ADC Result Registers 2 with sign extension, array offset: 0x5F, array step: 0x1 */
  __IO uint16_t LOLIM2[ADC_LOLIM2_COUNT];          /**< ADC Low Limit Registers 2, array offset: 0x63, array step: 0x1 */
  __IO uint16_t HILIM2[ADC_HILIM2_COUNT];          /**< ADC High Limit Registers 2, array offset: 0x67, array step: 0x1 */
  __IO uint16_t OFFST2[ADC_OFFST2_COUNT];          /**< ADC Offset Registers 2, array offset: 0x6B, array step: 0x1 */
  __IO uint16_t GC3;                               /**< Gain Control 3 Register, offset: 0x6F */
  __IO uint16_t SCTRL2;                            /**< ADC Scan Control Register 2, offset: 0x70 */
  __IO uint16_t SCHLTEN2;                          /**< ADC Scan Interrupt Enable Register 2, offset: 0x71 */
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
 *  0b000..Once (single) sequential - Upon start or an enabled sync signal, samples are taken one at a time
 *         starting with CLIST1[SAMPLE0], until the first disabled sample is encountered. If no disabled sample is
 *         encountered, conversion concludes after CLIST4[SAMPLE15]. If CLIST5[SAMPLE16] is enabled in SDIS2 then the
 *         scan will continue until the first disabled sample is encountered or when all 4 additional samples are
 *         completed. If the scan is initiated by a SYNC signal, only one scan is completed because the CTRL*[SYNC*]
 *         bit is cleared automatically by the initial SYNC detection. CTRL*[SYNC*] can be set again at any time
 *         during the scan.
 *  0b001..Once parallel - Upon start or an armed and enabled sync signal: In parallel, converter A converts
 *         SAMPLEs 0-7 , and converter B converts SAMPLEs 8-15 . When CTRL2[SIMULT] is 1 (default), scanning stops when
 *         either converter encounters a disabled sample or both converters complete all 8 samples. When
 *         CTRL2[SIMULT] is 0, a converter stops scanning when it encounters a disabled sample or completes all 8 samples. If
 *         additional samples are enabled in SDIS2 then the parallel scan will continue with converter A
 *         converting SAMPLEs 16-17 and convert B converting SAMPLEs 18-19, until the first disabled sample is encountered
 *         or when each converter completes 2 additional samples. If the scan is initiated by a SYNC signal, only
 *         one scan is completed because the CTRL*[SYNC*] bit is cleared automatically by the initial SYNC detection.
 *         CTRL*[SYNC*] can be set again at any time during the scan. If CTRL2[SIMULT] is 0, the B converter must
 *         be rearmed by writing the CTRL2[SYNC1] bit.
 *  0b010..Loop sequential - Upon an initial start or enabled sync pulse, up to 16 samples in the order SAMPLEs
 *         0-15 are taken one at a time until a disabled sample is encountered. If additional samples are enabled in
 *         the SDIS2 register, the scan will continue with SAMPLEs 16-19 until a disabled sample is encountered.
 *         The process repeats perpetually until the CTRL1[STOP0] bit is set. While a loop mode is running, any
 *         additional start commands or sync pulses are ignored unless the scan is paused using the SCTRL[SC*] bits. If
 *         PWR[APD] is the selected power mode control, PWR[PUDELAY] is applied only on the first conversion.
 *  0b011..Loop parallel - Upon an initial start or enabled sync pulse, converter A converts SAMPLEs 0-7 , and
 *         converter B converts SAMPLEs 8-15 . If additional samples are enabled in SDIS2 then the parallel scan will
 *         continue with converter A converting SAMPLEs 16-17 and convert B converting SAMPLEs 18-19, until the
 *         first disabled sample is encountered or when each converter completes 2 additional samples. Each time a
 *         converter completes its current scan, it immediately restarts its scan sequence. This process continues
 *         until the CTRL*[STOP*] bit is asserted. While a loop is running, any additional start commands or sync
 *         pulses are ignored unless the scan is paused using the SCTRL[SC*] bits. When CTRL2[SIMULT] is 1 (default),
 *         scanning restarts when either converter encounters a disabled sample. When CTRL2[SIMULT] is 0, a
 *         converter restarts scanning when it encounters a disabled sample. If PWR[APD] is the selected power mode
 *         control, PWR[PUDELAY] is applied only on the first conversion.
 *  0b100..Triggered sequential - Upon start or an enabled sync signal, samples are taken one at a time starting
 *         with CLIST1[SAMPLE0], until the first disabled sample is encountered. If no disabled sample is
 *         encountered, conversion concludes after CLIST4[SAMPLE15]. If CLIST5[SAMPLE16] is enabled in SDIS2 then the scan
 *         will continue until the first disabled sample is encountered or when all 4 additional samples are
 *         completed. If external sync is enabled, new scans start for each SYNC pulse that does not overlap with a current
 *         scan in progress.
 *  0b101..Triggered parallel (default) - Upon start or an enabled sync signal: In parallel, converter A converts
 *         SAMPLEs 0-7 , and converter B converts SAMPLEs 8-15 . When CTRL2[SIMULT] is 1 (default), scanning stops
 *         when either converter encounters a disabled sample. When CTRL2[SIMULT] is 0, a converter stops scanning
 *         when it encounters a disabled sample. If additional samples are enabled in SDIS2 then the parallel scan
 *         will continue with converter A converting SAMPLEs 16-17 and convert B converting SAMPLEs 18-19, until
 *         the first disabled sample is encountered or when each converter completes 2 additional samples. If
 *         external sync is enabled, new scans start for each SYNC pulse that does not overlap with a current scan in
 *         progress.
 *  0b11x..Reserved
 */
#define ADC_CTRL1_SMODE(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_CTRL1_SMODE_SHIFT)) & ADC_CTRL1_SMODE_MASK)

#define ADC_CTRL1_CHNCFG_L_MASK                  (0xF0U)
#define ADC_CTRL1_CHNCFG_L_SHIFT                 (4U)
/*! CHNCFG_L - CHCNF (Channel Configure Low) bits
 *  0b0xxx..Inputs = ANB2-ANB3 : Both configured as single ended inputs
 *  0b1xxx..Inputs = ANB2-ANB3 : Configured as differential pair (ANB2 is + and ANB3 is -)
 *  0bx0xx..Inputs = ANB0-ANB1 : Both configured as single ended inputs
 *  0bx1xx..Inputs = ANB0-ANB1 : Configured as differential pair (ANB0 is + and ANB1 is -)
 *  0bxx0x..Inputs = ANA2-ANA3 : Both configured as single ended inputs
 *  0bxx1x..Inputs = ANA2-ANA3 : Configured as differential pair (ANA2 is + and ANA3 is -)
 *  0bxxx0..Inputs = ANA0-ANA1 : Both configured as single ended inputs
 *  0bxxx1..Inputs = ANA0-ANA1 : Configured as differential pair (ANA0 is + and ANA1 is -)
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
 *  0b0xxx..Inputs = ANA6-ANA7 : Both configured as single ended inputs
 *  0b1xxx..Inputs = ANA6-ANA7 : Configured as differential pair (ANB6 is + and ANB7 is -)
 *  0bx0xx..Inputs = ANA4-ANA5 : Both configured as single ended inputs
 *  0bx1xx..Inputs = ANA4-ANA5 : Configured as differential pair (ANB4 is + and ANB5 is -)
 *  0bxx0x..Inputs = ANA6-ANA7 : Both configured as single ended inputs
 *  0bxx1x..Inputs = ANA6-ANA7 : Configured as differential pair (ANA6 is + and ANA7 is -)
 *  0bxxx0..Inputs = ANA4-ANA5 : Both configured as single ended inputs
 *  0bxxx1..Inputs = ANA4-ANA5 : Configured as differential pair (ANA4 is + and ANA5 is -)
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
 *  0b0000000000000000..SAMPLEx channel is enabled for ADC scan.
 *  0b0000000000000001..SAMPLEx channel is disabled for ADC scan and corresponding channels after SAMPLEx will also not occur in an ADC scan.
 */
#define ADC_SDIS_DS(x)                           (((uint16_t)(((uint16_t)(x)) << ADC_SDIS_DS_SHIFT)) & ADC_SDIS_DS_MASK)
/*! @} */

/*! @name STAT - ADC Status Register */
/*! @{ */

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
/*! @} */

/*! @name CAL - ADC Calibration Register */
/*! @{ */

#define ADC_CAL_SEL_VREFL_A_MASK                 (0x1000U)
#define ADC_CAL_SEL_VREFL_A_SHIFT                (12U)
/*! SEL_VREFL_A - Select V REFLO Source
 *  0b0..Internal VSSA
 *  0b1..ANA3
 */
#define ADC_CAL_SEL_VREFL_A(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFL_A_SHIFT)) & ADC_CAL_SEL_VREFL_A_MASK)

#define ADC_CAL_SEL_VREFH_A_MASK                 (0x2000U)
#define ADC_CAL_SEL_VREFH_A_SHIFT                (13U)
/*! SEL_VREFH_A - Select V REFH Source
 *  0b0..Internal VDDA
 *  0b1..ANA2
 */
#define ADC_CAL_SEL_VREFH_A(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFH_A_SHIFT)) & ADC_CAL_SEL_VREFH_A_MASK)

#define ADC_CAL_SEL_VREFL_B_MASK                 (0x4000U)
#define ADC_CAL_SEL_VREFL_B_SHIFT                (14U)
/*! SEL_VREFL_B - Select V REFLO Source
 *  0b0..Internal VSSA
 *  0b1..ANB3
 */
#define ADC_CAL_SEL_VREFL_B(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CAL_SEL_VREFL_B_SHIFT)) & ADC_CAL_SEL_VREFL_B_MASK)

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

/*! @name PWR2 - ADC Power Control Register 2 */
/*! @{ */

#define ADC_PWR2_DIV1_MASK                       (0x3F00U)
#define ADC_PWR2_DIV1_SHIFT                      (8U)
/*! DIV1 - Clock Divisor Select */
#define ADC_PWR2_DIV1(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_PWR2_DIV1_SHIFT)) & ADC_PWR2_DIV1_MASK)
/*! @} */

/*! @name CTRL3 - ADC Control Register 3 */
/*! @{ */

#define ADC_CTRL3_DMASRC_MASK                    (0x40U)
#define ADC_CTRL3_DMASRC_SHIFT                   (6U)
/*! DMASRC - DMA Trigger Source
 *  0b0..DMA trigger source is end of scan interrupt
 *  0b1..DMA trigger source is RDY bits
 */
#define ADC_CTRL3_DMASRC(x)                      (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_DMASRC_SHIFT)) & ADC_CTRL3_DMASRC_MASK)

#define ADC_CTRL3_UPDEN_L_MASK                   (0xF00U)
#define ADC_CTRL3_UPDEN_L_SHIFT                  (8U)
/*! UPDEN_L - Unipolar Differential Enable Low bits
 *  0b0xxx..Inputs = ANB2-ANB3 : Fully differential mode enabled on ANB2-ANB3
 *  0b1xxx..Inputs = ANB2-ANB3 : Unipolar differential mode enabled on ANB2-ANB3
 *  0bx0xx..Inputs = ANB0-ANB1 : Fully differential mode enabled on ANB0-ANB1
 *  0bx1xx..Inputs = ANB0-ANB1 : Unipolar differential mode enabled on ANB0-ANB1
 *  0bxx0x..Inputs = ANA2-ANA3 : Fully differential mode enabled on ANA2-ANA3
 *  0bxx1x..Inputs = ANA2-ANA3 : Unipolar differential mode enabled on ANA2-ANA3
 *  0bxxx0..Inputs = ANA0-ANA1 : Fully differential mode enabled on ANA0-ANA1
 *  0bxxx1..Inputs = ANA0-ANA1 : Unipolar differential mode enabled on ANA0-ANA1
 */
#define ADC_CTRL3_UPDEN_L(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_UPDEN_L_SHIFT)) & ADC_CTRL3_UPDEN_L_MASK)

#define ADC_CTRL3_UPDEN_H_MASK                   (0xF000U)
#define ADC_CTRL3_UPDEN_H_SHIFT                  (12U)
/*! UPDEN_H - Unipolar Differential Enable High bits
 *  0b0xxx..Inputs = ANB6-ANB7 : Fully differential mode enabled on ANB6-ANB7
 *  0b1xxx..Inputs = ANB6-ANB7 : Unipolar differential mode enabled on ANB6-ANB7
 *  0bx0xx..Inputs = ANB4-ANB5 : Fully differential mode enabled on ANB4-ANB5
 *  0bx1xx..Inputs = ANB4-ANB5 : Unipolar differential mode enabled on ANB4-ANB5
 *  0bxx0x..Inputs = ANA6-ANA7 : Fully differential mode enabled on ANA6-ANA7
 *  0bxx1x..Inputs = ANA6-ANA7 : Unipolar differential mode enabled on ANA6-ANA7
 *  0bxxx0..Inputs = ANA4-ANA5 : Fully differential mode enabled on ANA4-ANA5
 *  0bxxx1..Inputs = ANA4-ANA5 : Unipolar differential mode enabled on ANA4-ANA5
 */
#define ADC_CTRL3_UPDEN_H(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_CTRL3_UPDEN_H_SHIFT)) & ADC_CTRL3_UPDEN_H_MASK)
/*! @} */

/*! @name SCHLTEN - ADC Scan Interrupt Enable Register */
/*! @{ */

#define ADC_SCHLTEN_SCHLTEN_MASK                 (0xFFFFU)
#define ADC_SCHLTEN_SCHLTEN_SHIFT                (0U)
/*! SCHLTEN - SCHLTEN
 *  0b0000000000000000..Scan interrupt is not enabled for this sample.
 *  0b0000000000000001..Scan interrupt is enabled for this sample.
 */
#define ADC_SCHLTEN_SCHLTEN(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_SCHLTEN_SCHLTEN_SHIFT)) & ADC_SCHLTEN_SCHLTEN_MASK)
/*! @} */

/*! @name ZXCTRL3 - ADC Zero Crossing Control 3 Register */
/*! @{ */

#define ADC_ZXCTRL3_ZCE16_MASK                   (0x3U)
#define ADC_ZXCTRL3_ZCE16_SHIFT                  (0U)
/*! ZCE16 - Zero crossing enable 16
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL3_ZCE16(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL3_ZCE16_SHIFT)) & ADC_ZXCTRL3_ZCE16_MASK)

#define ADC_ZXCTRL3_ZCE17_MASK                   (0xCU)
#define ADC_ZXCTRL3_ZCE17_SHIFT                  (2U)
/*! ZCE17 - Zero crossing enable 17
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL3_ZCE17(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL3_ZCE17_SHIFT)) & ADC_ZXCTRL3_ZCE17_MASK)

#define ADC_ZXCTRL3_ZCE18_MASK                   (0x30U)
#define ADC_ZXCTRL3_ZCE18_SHIFT                  (4U)
/*! ZCE18 - Zero crossing enable 18
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL3_ZCE18(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL3_ZCE18_SHIFT)) & ADC_ZXCTRL3_ZCE18_MASK)

#define ADC_ZXCTRL3_ZCE19_MASK                   (0xC0U)
#define ADC_ZXCTRL3_ZCE19_SHIFT                  (6U)
/*! ZCE19 - Zero crossing enable 19
 *  0b00..Zero Crossing disabled
 *  0b01..Zero Crossing enabled for positive to negative sign change
 *  0b10..Zero Crossing enabled for negative to positive sign change
 *  0b11..Zero Crossing enabled for any sign change
 */
#define ADC_ZXCTRL3_ZCE19(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_ZXCTRL3_ZCE19_SHIFT)) & ADC_ZXCTRL3_ZCE19_MASK)
/*! @} */

/*! @name CLIST5 - ADC Channel List Register 5 */
/*! @{ */

#define ADC_CLIST5_SAMPLE16_MASK                 (0x3U)
#define ADC_CLIST5_SAMPLE16_SHIFT                (0U)
/*! SAMPLE16 - Sample Field 16
 *  0b00..Single Ended: ADCA temperature sensor
 *  0b01..Single Ended: ADCA analog input for on-chip generated signals
 *  0b10..Single Ended: ADCB temperature sensor
 *  0b11..Single Ended: ADCB analog input for on-chip generated signals
 */
#define ADC_CLIST5_SAMPLE16(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SAMPLE16_SHIFT)) & ADC_CLIST5_SAMPLE16_MASK)

#define ADC_CLIST5_SAMPLE17_MASK                 (0xCU)
#define ADC_CLIST5_SAMPLE17_SHIFT                (2U)
/*! SAMPLE17 - Sample Field 17
 *  0b00..Single Ended: ADCA temperature sensor
 *  0b01..Single Ended: ADCA analog input for on-chip generated signals
 *  0b10..Single Ended: ADCB temperature sensor
 *  0b11..Single Ended: ADCB analog input for on-chip generated signals
 */
#define ADC_CLIST5_SAMPLE17(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SAMPLE17_SHIFT)) & ADC_CLIST5_SAMPLE17_MASK)

#define ADC_CLIST5_SAMPLE18_MASK                 (0x30U)
#define ADC_CLIST5_SAMPLE18_SHIFT                (4U)
/*! SAMPLE18 - Sample Field 18
 *  0b00..Single Ended: ADCA temperature sensor
 *  0b01..Single Ended: ADCA analog input for on-chip generated signals
 *  0b10..Single Ended: ADCB temperature sensor
 *  0b11..Single Ended: ADC B analog input for on-chip generated signals
 */
#define ADC_CLIST5_SAMPLE18(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SAMPLE18_SHIFT)) & ADC_CLIST5_SAMPLE18_MASK)

#define ADC_CLIST5_SAMPLE19_MASK                 (0xC0U)
#define ADC_CLIST5_SAMPLE19_SHIFT                (6U)
/*! SAMPLE19 - Sample Field 19
 *  0b00..Single Ended: ADCA temperature sensor
 *  0b01..Single Ended: ADCA analog input for on-chip generated signals
 *  0b10..Single Ended: ADCB temperature sensor
 *  0b11..Single Ended: ADCB analog input for on-chip generated signals
 */
#define ADC_CLIST5_SAMPLE19(x)                   (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SAMPLE19_SHIFT)) & ADC_CLIST5_SAMPLE19_MASK)

#define ADC_CLIST5_SEL_TEMP_0_MASK               (0x100U)
#define ADC_CLIST5_SEL_TEMP_0_SHIFT              (8U)
/*! SEL_TEMP_0 - Select Temperature Sensor Alternate Source
 *  0b0..Normal Operation (ADCA6)
 *  0b1..ADCA6 input is replaced with ADCA temperature sensor
 */
#define ADC_CLIST5_SEL_TEMP_0(x)                 (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SEL_TEMP_0_SHIFT)) & ADC_CLIST5_SEL_TEMP_0_MASK)

#define ADC_CLIST5_SEL_INTERNAL_0_MASK           (0x200U)
#define ADC_CLIST5_SEL_INTERNAL_0_SHIFT          (9U)
/*! SEL_INTERNAL_0 - Select On-Chip Analog Input Alternate Source
 *  0b0..Normal Operation (ADCA7)
 *  0b1..ADCA7 input is replaced with ADCA on-chip analog input
 */
#define ADC_CLIST5_SEL_INTERNAL_0(x)             (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SEL_INTERNAL_0_SHIFT)) & ADC_CLIST5_SEL_INTERNAL_0_MASK)

#define ADC_CLIST5_SEL_TEMP_1_MASK               (0x400U)
#define ADC_CLIST5_SEL_TEMP_1_SHIFT              (10U)
/*! SEL_TEMP_1 - Select Temperature Sensor Alternate Source
 *  0b0..Normal Operation (ADCB6)
 *  0b1..ADCB6 input is replaced with ADCB temperature sensor
 */
#define ADC_CLIST5_SEL_TEMP_1(x)                 (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SEL_TEMP_1_SHIFT)) & ADC_CLIST5_SEL_TEMP_1_MASK)

#define ADC_CLIST5_SEL_INTERNAL_1_MASK           (0x800U)
#define ADC_CLIST5_SEL_INTERNAL_1_SHIFT          (11U)
/*! SEL_INTERNAL_1 - Select On-Chip Analog Input Alternate Source
 *  0b0..Normal operation (ADCB7)
 *  0b1..ADCB7 input is replaced with ADCB on-chip analog input
 */
#define ADC_CLIST5_SEL_INTERNAL_1(x)             (((uint16_t)(((uint16_t)(x)) << ADC_CLIST5_SEL_INTERNAL_1_SHIFT)) & ADC_CLIST5_SEL_INTERNAL_1_MASK)
/*! @} */

/*! @name SDIS2 - ADC Sample Disable Register 2 */
/*! @{ */

#define ADC_SDIS2_DS_MASK                        (0xFU)
#define ADC_SDIS2_DS_SHIFT                       (0U)
/*! DS - Disable Sample Bits
 *  0b0000..SAMPLEx channel is enabled for ADC scan.
 *  0b0001..SAMPLEx channel is disabled for ADC scan and corresponding channels after SAMPLEx will also not occur
 *          in an ADC scan. NOTE: Please note that enabling the four extra sample slots by themselves
 *          (ADC_SDIS=FFFF, and samples enabled in ADC_SDIS2 ) is supported only in once sequential mode. Sequential loop, and
 *          parallel (both sequential and loop) modes are not supported. It is suggested to poll the ADC_RDY2
 *          register to check for conversion completion for this case.
 */
#define ADC_SDIS2_DS(x)                          (((uint16_t)(((uint16_t)(x)) << ADC_SDIS2_DS_SHIFT)) & ADC_SDIS2_DS_MASK)
/*! @} */

/*! @name RDY2 - ADC Ready Register 2 */
/*! @{ */

#define ADC_RDY2_RDY_MASK                        (0xFU)
#define ADC_RDY2_RDY_SHIFT                       (0U)
/*! RDY - Ready Sample
 *  0b0000..Sample not ready or has been read
 *  0b0001..Sample ready to be read
 */
#define ADC_RDY2_RDY(x)                          (((uint16_t)(((uint16_t)(x)) << ADC_RDY2_RDY_SHIFT)) & ADC_RDY2_RDY_MASK)
/*! @} */

/*! @name LOLIMSTAT2 - ADC Low Limit Status Register 2 */
/*! @{ */

#define ADC_LOLIMSTAT2_LLS_MASK                  (0xFU)
#define ADC_LOLIMSTAT2_LLS_SHIFT                 (0U)
/*! LLS - Low Limit Status Bits */
#define ADC_LOLIMSTAT2_LLS(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_LOLIMSTAT2_LLS_SHIFT)) & ADC_LOLIMSTAT2_LLS_MASK)
/*! @} */

/*! @name HILIMSTAT2 - ADC High Limit Status Register 2 */
/*! @{ */

#define ADC_HILIMSTAT2_HLS_MASK                  (0xFU)
#define ADC_HILIMSTAT2_HLS_SHIFT                 (0U)
/*! HLS - High Limit Status Bits */
#define ADC_HILIMSTAT2_HLS(x)                    (((uint16_t)(((uint16_t)(x)) << ADC_HILIMSTAT2_HLS_SHIFT)) & ADC_HILIMSTAT2_HLS_MASK)
/*! @} */

/*! @name ZXSTAT2 - ADC Zero Crossing Status Register 2 */
/*! @{ */

#define ADC_ZXSTAT2_ZCS_MASK                     (0xFU)
#define ADC_ZXSTAT2_ZCS_SHIFT                    (0U)
/*! ZCS - Zero Crossing Status
 *  0b0000..Either: A sign change did not occur in a comparison between the current channelx result and the
 *          previous channelx result, or Zero crossing control is disabled for channelx in the zero crossing control
 *          register, ZXCTRL3
 *  0b0001..In a comparison between the current channelx result and the previous channelx result, a sign change
 *          condition occurred as defined in the zero crossing control register (ZXCTRL3)
 */
#define ADC_ZXSTAT2_ZCS(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_ZXSTAT2_ZCS_SHIFT)) & ADC_ZXSTAT2_ZCS_MASK)
/*! @} */

/*! @name RSLT2 - ADC Result Registers 2 with sign extension */
/*! @{ */

#define ADC_RSLT2_RSLT_MASK                      (0x7FF8U)
#define ADC_RSLT2_RSLT_SHIFT                     (3U)
/*! RSLT - Digital Result of the Conversion */
#define ADC_RSLT2_RSLT(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_RSLT2_RSLT_SHIFT)) & ADC_RSLT2_RSLT_MASK)

#define ADC_RSLT2_SEXT_MASK                      (0x8000U)
#define ADC_RSLT2_SEXT_SHIFT                     (15U)
/*! SEXT - Sign Extend */
#define ADC_RSLT2_SEXT(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_RSLT2_SEXT_SHIFT)) & ADC_RSLT2_SEXT_MASK)
/*! @} */

/*! @name LOLIM2 - ADC Low Limit Registers 2 */
/*! @{ */

#define ADC_LOLIM2_LLMT_MASK                     (0x7FF8U)
#define ADC_LOLIM2_LLMT_SHIFT                    (3U)
/*! LLMT - Low Limit Bits */
#define ADC_LOLIM2_LLMT(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_LOLIM2_LLMT_SHIFT)) & ADC_LOLIM2_LLMT_MASK)
/*! @} */

/*! @name HILIM2 - ADC High Limit Registers 2 */
/*! @{ */

#define ADC_HILIM2_HLMT_MASK                     (0x7FF8U)
#define ADC_HILIM2_HLMT_SHIFT                    (3U)
/*! HLMT - High Limit Bits */
#define ADC_HILIM2_HLMT(x)                       (((uint16_t)(((uint16_t)(x)) << ADC_HILIM2_HLMT_SHIFT)) & ADC_HILIM2_HLMT_MASK)
/*! @} */

/*! @name OFFST2 - ADC Offset Registers 2 */
/*! @{ */

#define ADC_OFFST2_OFFSET_MASK                   (0x7FF8U)
#define ADC_OFFST2_OFFSET_SHIFT                  (3U)
/*! OFFSET - ADC Offset Bits */
#define ADC_OFFST2_OFFSET(x)                     (((uint16_t)(((uint16_t)(x)) << ADC_OFFST2_OFFSET_SHIFT)) & ADC_OFFST2_OFFSET_MASK)
/*! @} */

/*! @name GC3 - Gain Control 3 Register */
/*! @{ */

#define ADC_GC3_GAIN16_MASK                      (0x3U)
#define ADC_GC3_GAIN16_SHIFT                     (0U)
/*! GAIN16 - Gain Control Bit 16
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC3_GAIN16(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC3_GAIN16_SHIFT)) & ADC_GC3_GAIN16_MASK)

#define ADC_GC3_GAIN17_MASK                      (0xCU)
#define ADC_GC3_GAIN17_SHIFT                     (2U)
/*! GAIN17 - Gain Control Bit 17
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC3_GAIN17(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC3_GAIN17_SHIFT)) & ADC_GC3_GAIN17_MASK)

#define ADC_GC3_GAIN18_MASK                      (0x30U)
#define ADC_GC3_GAIN18_SHIFT                     (4U)
/*! GAIN18 - Gain Control Bit 18
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC3_GAIN18(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC3_GAIN18_SHIFT)) & ADC_GC3_GAIN18_MASK)

#define ADC_GC3_GAIN19_MASK                      (0xC0U)
#define ADC_GC3_GAIN19_SHIFT                     (6U)
/*! GAIN19 - Gain Control Bit 19
 *  0b00..x1 amplification
 *  0b01..x2 amplification
 *  0b10..x4 amplification
 *  0b11..reserved
 */
#define ADC_GC3_GAIN19(x)                        (((uint16_t)(((uint16_t)(x)) << ADC_GC3_GAIN19_SHIFT)) & ADC_GC3_GAIN19_MASK)
/*! @} */

/*! @name SCTRL2 - ADC Scan Control Register 2 */
/*! @{ */

#define ADC_SCTRL2_SC_MASK                       (0xFU)
#define ADC_SCTRL2_SC_SHIFT                      (0U)
/*! SC - Scan Control Bits
 *  0b0000..Perform sample immediately after the completion of the current sample.
 *  0b0001..Delay sample until a new sync input occurs.
 */
#define ADC_SCTRL2_SC(x)                         (((uint16_t)(((uint16_t)(x)) << ADC_SCTRL2_SC_SHIFT)) & ADC_SCTRL2_SC_MASK)
/*! @} */

/*! @name SCHLTEN2 - ADC Scan Interrupt Enable Register 2 */
/*! @{ */

#define ADC_SCHLTEN2_SCHLTEN_MASK                (0xFU)
#define ADC_SCHLTEN2_SCHLTEN_SHIFT               (0U)
/*! SCHLTEN - SCHLTEN
 *  0b0000..Scan interrupt is not enabled for this sample.
 *  0b0001..Scan interrupt is enabled for this sample.
 */
#define ADC_SCHLTEN2_SCHLTEN(x)                  (((uint16_t)(((uint16_t)(x)) << ADC_SCHLTEN2_SCHLTEN_SHIFT)) & ADC_SCHLTEN2_SCHLTEN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ADC_Register_Masks */

/* Backward compatibility */
#define ADC_CAL_SEL_VREFLO_A_MASK                ADC_CAL_SEL_VREFL_A_MASK
#define ADC_CAL_SEL_VREFLO_A_SHIFT               ADC_CAL_SEL_VREFL_A_SHIFT
#define ADC_CAL_SEL_VREFLO_A(x)                  ADC_CAL_SEL_VREFL_A(x)
#define ADC_CAL_SEL_VREFLO_B_MASK                ADC_CAL_SEL_VREFL_B_MASK
#define ADC_CAL_SEL_VREFLO_B_SHIFT               ADC_CAL_SEL_VREFL_B_SHIFT
#define ADC_CAL_SEL_VREFLO_B(x)                  ADC_CAL_SEL_VREFL_B(x)


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

