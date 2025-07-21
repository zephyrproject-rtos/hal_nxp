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
**         CMSIS Peripheral Access Layer for TRGMUX
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
 * @file PERI_TRGMUX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_K32L2A31VLH1A) || defined(CPU_K32L2A31VLL1A))
#include "K32L2A31A_COMMON.h"
#elif (defined(CPU_K32L2A41VLH1A) || defined(CPU_K32L2A41VLL1A))
#include "K32L2A41A_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

/* ----------------------------------------------------------------------------
   -- Mapping Information
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Mapping_Information Mapping Information
 * @{
 */

/** Mapping Information */
#if !defined(TRGMUX_SOURCE_T_)
#define TRGMUX_SOURCE_T_
/*!
 * @addtogroup trgmux_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Structure for the TRGMUX source
 *
 * Defines the structure for the TRGMUX source collections.
 */
typedef enum _trgmux_source
{
    kTRGMUX_SourceDisabled          = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourcePortPin           = 1U,          /**< Port pin trigger intput is selected */
    kTRGMUX_SourceFlexIOTimer0      = 2U,          /**< FlexIO Timer 0 input is selected */
    kTRGMUX_SourceFlexIOTimer1      = 3U,          /**< FlexIO Timer 1 input is selected */
    kTRGMUX_SourceFlexIOTimer2      = 4U,          /**< FlexIO Timer 2 input is selected */
    kTRGMUX_SourceFlexIOTimer3      = 5U,          /**< FlexIO Timer 3 input is selected */
    kTRGMUX_SourceFlexIOTimer4      = 6U,          /**< FlexIO Timer 4 input is selected */
    kTRGMUX_SourceFlexIOTimer5      = 7U,          /**< FlexIO Timer 5 input is selected */
    kTRGMUX_SourceFlexIOTimer6      = 8U,          /**< FlexIO Timer 6 input is selected */
    kTRGMUX_SourceFlexIOTimer7      = 9U,          /**< FlexIO Timer 7 input is selected */
    kTRGMUX_SourceTpm0Overflow      = 10U,         /**< TPM0 Overflow is selected */
    kTRGMUX_SourceTpm0Ch0           = 11U,         /**< TPM0 Channel 0 is selected */
    kTRGMUX_SourceTpm0Ch1           = 12U,         /**< TPM0 Channel 1 is selected */
    kTRGMUX_SourceTpm1Overflow      = 13U,         /**< TPM1 Overflow is selected */
    kTRGMUX_SourceTpm1Ch0           = 14U,         /**< TPM1 Channel 0 is selected */
    kTRGMUX_SourceTpm1Ch1           = 15U,         /**< TPM1 Channel 1 is selected */
    kTRGMUX_SourceLpit1Ch0          = 16U,         /**< LPIT1 Channel 0 is selected */
    kTRGMUX_SourceLpit1Ch1          = 17U,         /**< LPIT1 Channel 1 is selected */
    kTRGMUX_SourceLpit1Ch2          = 18U,         /**< LPIT1 Channel 2 is selected */
    kTRGMUX_SourceLpit1Ch3          = 19U,         /**< LPIT1 Channel 3 is selected */
    kTRGMUX_SourceLpuart0RxData     = 20U,         /**< LPUART0 RX Data is selected */
    kTRGMUX_SourceLpuart0TxData     = 21U,         /**< LPUART0 TX Data is selected */
    kTRGMUX_SourceLpuart0RxIdle     = 22U,         /**< LPUART0 RX Idle is selected */
    kTRGMUX_SourceLpuart1RxData     = 23U,         /**< LPUART1 RX Data is selected */
    kTRGMUX_SourceLpuart1TxData     = 24U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 25U,         /**< LPUART1 RX Idle is selected */
    kTRGMUX_SourceLpi2c0MasterStop  = 26U,         /**< LPI2C0 Master STOP is selected */
    kTRGMUX_SourceLpi2c0SlaveStop   = 27U,         /**< LPI2C0 Slave STOP is selected */
    kTRGMUX_SourceLpi2c1MasterStop  = 28U,         /**< LPI2C1 Master STOP is selected */
    kTRGMUX_SourceLpi2c1SlaveStop   = 29U,         /**< LPI2C1 Slave STOP is selected */
    kTRGMUX_SourceLpspi0Frame       = 30U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_SourceLpspi0RxData      = 31U,         /**< LPSPI0 RX Data is selected */
    kTRGMUX_SourceLpspi1Frame       = 32U,         /**< LPSPI1 Frame is selected */
    kTRGMUX_SourceLpspi1RxData      = 33U,         /**< LPSPI1 RX Data is selected */
    kTRGMUX_SourceRtcSecCount       = 34U,         /**< RTC Seconds Counter is selected */
    kTRGMUX_SourceRtcAlarm          = 35U,         /**< RTC Alarm is selected */
    kTRGMUX_SourceLptmr0Trg         = 36U,         /**< LPTMR0 Trigger is selected */
    kTRGMUX_SourceLptmr1Trg         = 37U,         /**< LPTMR1 Trigger is selected */
    kTRGMUX_SourceCmp0Output        = 38U,         /**< CMP0 Output is selected */
    kTRGMUX_SourceCmp1Output        = 39U,         /**< CMP1 Output is selected */
    kTRGMUX_SourceAdc0ConvAComplete = 40U,         /**< ADC0 Conversion A Complete is selected */
    kTRGMUX_SourceAdc0ConvBComplete = 41U,         /**< ADC0 Conversion B Complete is selected */
    kTRGMUX_SourcePortAPinTrg       = 42U,         /**< Port A Pin Trigger is selected */
    kTRGMUX_SourcePortBPinTrg       = 43U,         /**< Port B Pin Trigger is selected */
    kTRGMUX_SourcePortCPinTrg       = 44U,         /**< Port C Pin Trigger is selected */
    kTRGMUX_SourcePortDPinTrg       = 45U,         /**< Port D Pin Trigger is selected */
    kTRGMUX_SourcePortEPinTrg       = 46U,         /**< Port E Pin Trigger is selected */
    kTRGMUX_SourceTpm2Overflow      = 47U,         /**< TPM2 Overflow is selected */
    kTRGMUX_SourceTpm2Ch0           = 48U,         /**< TPM2 Channel 0 is selected */
    kTRGMUX_SourceTpm2Ch1           = 49U,         /**< TPM2 Channel 1 is selected */
    kTRGMUX_SourceLpit0Ch0          = 50U,         /**< LPIT0 Channel 0 is selected */
    kTRGMUX_SourceLpit0Ch1          = 51U,         /**< LPIT0 Channel 1 is selected */
    kTRGMUX_SourceLpit0Ch2          = 52U,         /**< LPIT0 Channel 2 is selected */
    kTRGMUX_SourceLpit0Ch3          = 53U,         /**< LPIT0 Channel 3 is selected */
    kTRGMUX_SourceUsbSof            = 54U,         /**< USB Start-of-Frame is selected */
    kTRGMUX_SourceLpuart2RxData     = 55U,         /**< LPUART2 RX Data is selected */
    kTRGMUX_SourceLpuart2TxData     = 56U,         /**< LPUART2 TX Data is selected */
    kTRGMUX_SourceLpuart2RxIdle     = 57U,         /**< LPUART2 RX Idle is selected */
    kTRGMUX_SourceLpi2c2MasterStop  = 58U,         /**< LPI2C2 Master STOP is selected */
    kTRGMUX_SourceLpi2c2SlaveStop   = 59U,         /**< LPI2C2 Slave STOP is selected */
    kTRGMUX_SourceLpspi2Frame       = 60U,         /**< LPSPI2 Frame is selected */
    kTRGMUX_SourceLpspi2RxData      = 61U,         /**< LPSPI2 RX Data is selected */
    kTRGMUX_SourceI2c0TxFrameSync   = 62U,         /**< I2C0 TX Frame Sync is selected */
    kTRGMUX_SourceI2c0RxFrameSync   = 63U,         /**< I2C0 RX Frame Sync is selected */
} trgmux_source_t;
#endif /* TRGMUX_SOURCE_T_ */

#if !defined(TRGMUX_DEVICE_T_)
#define TRGMUX_DEVICE_T_
/*!
 * @brief Structure for the TRGMUX device
 *
 * Defines the structure for the TRGMUX device collections.
 */
typedef enum _trgmux_device
{
    kTRGMUX_Trgmux0Dmamux0          = 0U,          /**< DMAMUX0 device trigger input */
    kTRGMUX_Trgmux0Lpit0            = 1U,          /**< LPIT0 device trigger input */
    kTRGMUX_Trgmux0Tpm2             = 2U,          /**< TPM2 device trigger input */
    kTRGMUX_Trgmux1Tpm0             = 2U,          /**< TPM0 device trigger input */
    kTRGMUX_Trgmux0Adc0             = 4U,          /**< ADC0 device trigger input */
    kTRGMUX_Trgmux1Flexio           = 4U,          /**< FLEXIO device trigger input */
    kTRGMUX_Trgmux0Lpuart2          = 5U,          /**< LPUART2 device trigger input */
    kTRGMUX_Trgmux1Lpuart0          = 5U,          /**< LPUART0 device trigger input */
    kTRGMUX_Trgmux0Lpi2c2           = 7U,          /**< LPI2C2 device trigger input */
    kTRGMUX_Trgmux1Lpi2c0           = 7U,          /**< LPI2C0 device trigger input */
    kTRGMUX_Trgmux0Lpspi2           = 9U,          /**< LPSPI2 device trigger input */
    kTRGMUX_Trgmux1Lpspi0           = 9U,          /**< LPSPI0 device trigger input */
    kTRGMUX_Trgmux0Cmp0             = 11U,         /**< CMP0 device trigger input */
    kTRGMUX_Trgmux0Cmp1             = 12U,         /**< CMP1 device trigger input */
    kTRGMUX_Trgmux0Dac0             = 13U,         /**< DAC0 device trigger input */
    kTRGMUX_Trgmux1Tpm1             = 3U,          /**< TPM1 device trigger input */
    kTRGMUX_Trgmux1Lpuart1          = 6U,          /**< LPUART1 device trigger input */
    kTRGMUX_Trgmux1Lpi2c1           = 8U,          /**< LPI2C1 device trigger input */
    kTRGMUX_Trgmux1Lpspi1           = 10U,         /**< LPSPI1 device trigger input */
} trgmux_device_t;

/* @} */
#endif /* TRGMUX_DEVICE_T_ */


/*!
 * @}
 */ /* end of group Mapping_Information */


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
   -- TRGMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Peripheral_Access_Layer TRGMUX Peripheral Access Layer
 * @{
 */

/** TRGMUX - Size of Registers Arrays */
#define TRGMUX_TRGCFG_COUNT                       14u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX TRGCFG Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX TRGCFG Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x3FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select
 *  0b000000..Trigger function is disabled.
 *  0b000001..Port pin trigger input is selected.
 *  0b000010..FlexIO Timer 0 input is selected.
 *  0b000011..FlexIO Timer 1 input is selected.
 *  0b000100..FlexIO Timer 2 input is selected.
 *  0b000101..FlexIO Timer 3 input is selected.
 *  0b000110..FlexIO Timer 4 input is selected.
 *  0b000111..FlexIO Timer 5 input is selected.
 *  0b001000..FlexIO Timer 6 input is selected.
 *  0b001001..FlexIO Timer 7 input is selected.
 *  0b001010..TPM0 Overflow is selected
 *  0b001011..TPM0 Channel 0 is selected
 *  0b001100..TPM0 Channel 1 is selected
 *  0b001101..TPM1 Overflow is selected
 *  0b001110..TPM1 Channel 0 is selected
 *  0b001111..TPM1 Channel 1 is selected
 *  0b010000..LPIT1 Channel 0 is selected
 *  0b010001..LPIT1 Channel 1 is selected
 *  0b010010..LPIT1 Channel 2 is selected
 *  0b010011..LPIT1 Channel 3 is selected
 *  0b010100..LPUART0 RX Data is selected.
 *  0b010101..LPUART0 TX Data is selected.
 *  0b010110..LPUART0 RX Idle is selected.
 *  0b010111..LPUART1 RX Data is selected.
 *  0b011000..LPUART1 TX Data is selected.
 *  0b011001..LPUART1 RX Idle is selected.
 *  0b011010..LPI2C0 Master STOP is selected.
 *  0b011011..LPI2C0 Slave STOP is selected.
 *  0b011100..LPI2C1 Master STOP is selected.
 *  0b011101..LPI2C1 Slave STOP is selected.
 *  0b011110..LPSPI0 Frame is selected.
 *  0b011111..LPSPI0 RX data is selected.
 *  0b100000..LPSPI1 Frame is selected.
 *  0b100001..LPSPI1 RX data is selected.
 *  0b100010..RTC Seconds Counter is selected.
 *  0b100011..RTC Alarm is selected.
 *  0b100100..LPTMR0 Trigger is selected.
 *  0b100101..LPTMR1 Trigger is selected.
 *  0b100110..CMP0 Output is selected.
 *  0b100111..CMP1 Output is selected.
 *  0b101000..ADC0 Conversion A Complete is selected.
 *  0b101001..ADC0 Conversion B Complete is selected.
 *  0b101010..Port A Pin Trigger is selected.
 *  0b101011..Port B Pin Trigger is selected.
 *  0b101100..Port C Pin Trigger is selected.
 *  0b101101..Port D Pin Trigger is selected.
 *  0b101110..Port E Pin Trigger is selected.
 *  0b101111..TPM2 Overflow selected.
 *  0b110000..TPM2 Channel 0 is selected.
 *  0b110001..TPM2 Channel 1 is selected.
 *  0b110010..LPIT0 Channel 0 is selected.
 *  0b110011..LPIT0 Channel 1 is selected.
 *  0b110100..LPIT0 Channel 2 is selected.
 *  0b110101..LPIT0 Channel 3 is selected.
 *  0b110110..USB Start-of-Frame is selected.
 *  0b110111..LPUART2 RX Data is selected.
 *  0b111000..LPUART2 TX Data is selected.
 *  0b111001..LPUART2 RX Idle is selected.
 *  0b111010..LPI2C2 Master STOP is selected.
 *  0b111011..LPI2C2 Slave STOP is selected.
 *  0b111100..LPSPI2 Frame is selected.
 *  0b111101..LPSPI2 RX Data is selected.
 */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x3F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select
 *  0b000000..Trigger function is disabled.
 *  0b000001..Port pin trigger input is selected.
 *  0b000010..FlexIO Timer 0 input is selected.
 *  0b000011..FlexIO Timer 1 input is selected.
 *  0b000100..FlexIO Timer 2 input is selected.
 *  0b000101..FlexIO Timer 3 input is selected.
 *  0b000110..FlexIO Timer 4 input is selected.
 *  0b000111..FlexIO Timer 5 input is selected.
 *  0b001000..FlexIO Timer 6 input is selected.
 *  0b001001..FlexIO Timer 7 input is selected.
 *  0b001010..TPM0 Overflow is selected
 *  0b001011..TPM0 Channel 0 is selected
 *  0b001100..TPM0 Channel 1 is selected
 *  0b001101..TPM1 Overflow is selected
 *  0b001110..TPM1 Channel 0 is selected
 *  0b001111..TPM1 Channel 1 is selected
 *  0b010000..LPIT1 Channel 0 is selected
 *  0b010001..LPIT1 Channel 1 is selected
 *  0b010010..LPIT1 Channel 2 is selected
 *  0b010011..LPIT1 Channel 3 is selected
 *  0b010100..LPUART0 RX Data is selected.
 *  0b010101..LPUART0 TX Data is selected.
 *  0b010110..LPUART0 RX Idle is selected.
 *  0b010111..LPUART1 RX Data is selected.
 *  0b011000..LPUART1 TX Data is selected.
 *  0b011001..LPUART1 RX Idle is selected.
 *  0b011010..LPI2C0 Master STOP is selected.
 *  0b011011..LPI2C0 Slave STOP is selected.
 *  0b011100..LPI2C1 Master STOP is selected.
 *  0b011101..LPI2C1 Slave STOP is selected.
 *  0b011110..LPSPI0 Frame is selected.
 *  0b011111..LPSPI0 RX data is selected.
 *  0b100000..LPSPI1 Frame is selected.
 *  0b100001..LPSPI1 RX data is selected.
 *  0b100010..RTC Seconds Counter is selected.
 *  0b100011..RTC Alarm is selected.
 *  0b100100..LPTMR0 Trigger is selected.
 *  0b100101..LPTMR1 Trigger is selected.
 *  0b100110..CMP0 Output is selected.
 *  0b100111..CMP1 Output is selected.
 *  0b101000..ADC0 Conversion A Complete is selected.
 *  0b101001..ADC0 Conversion B Complete is selected.
 *  0b101010..Port A Pin Trigger is selected.
 *  0b101011..Port B Pin Trigger is selected.
 *  0b101100..Port C Pin Trigger is selected.
 *  0b101101..Port D Pin Trigger is selected.
 *  0b101110..Port E Pin Trigger is selected.
 *  0b101111..TPM2 Overflow selected.
 *  0b110000..TPM2 Channel 0 is selected.
 *  0b110001..TPM2 Channel 1 is selected.
 *  0b110010..LPIT0 Channel 0 is selected.
 *  0b110011..LPIT0 Channel 1 is selected.
 *  0b110100..LPIT0 Channel 2 is selected.
 *  0b110101..LPIT0 Channel 3 is selected.
 *  0b110110..USB Start-of-Frame is selected.
 *  0b110111..LPUART2 RX Data is selected.
 *  0b111000..LPUART2 TX Data is selected.
 *  0b111001..LPUART2 RX Idle is selected.
 *  0b111010..LPI2C2 Master STOP is selected.
 *  0b111011..LPI2C2 Slave STOP is selected.
 *  0b111100..LPSPI2 Frame is selected.
 *  0b111101..LPSPI2 RX Data is selected.
 */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x3F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select
 *  0b000000..Trigger function is disabled.
 *  0b000001..Port pin trigger input is selected.
 *  0b000010..FlexIO Timer 0 input is selected.
 *  0b000011..FlexIO Timer 1 input is selected.
 *  0b000100..FlexIO Timer 2 input is selected.
 *  0b000101..FlexIO Timer 3 input is selected.
 *  0b000110..FlexIO Timer 4 input is selected.
 *  0b000111..FlexIO Timer 5 input is selected.
 *  0b001000..FlexIO Timer 6 input is selected.
 *  0b001001..FlexIO Timer 7 input is selected.
 *  0b001010..TPM0 Overflow is selected
 *  0b001011..TPM0 Channel 0 is selected
 *  0b001100..TPM0 Channel 1 is selected
 *  0b001101..TPM1 Overflow is selected
 *  0b001110..TPM1 Channel 0 is selected
 *  0b001111..TPM1 Channel 1 is selected
 *  0b010000..LPIT1 Channel 0 is selected
 *  0b010001..LPIT1 Channel 1 is selected
 *  0b010010..LPIT1 Channel 2 is selected
 *  0b010011..LPIT1 Channel 3 is selected
 *  0b010100..LPUART0 RX Data is selected.
 *  0b010101..LPUART0 TX Data is selected.
 *  0b010110..LPUART0 RX Idle is selected.
 *  0b010111..LPUART1 RX Data is selected.
 *  0b011000..LPUART1 TX Data is selected.
 *  0b011001..LPUART1 RX Idle is selected.
 *  0b011010..LPI2C0 Master STOP is selected.
 *  0b011011..LPI2C0 Slave STOP is selected.
 *  0b011100..LPI2C1 Master STOP is selected.
 *  0b011101..LPI2C1 Slave STOP is selected.
 *  0b011110..LPSPI0 Frame is selected.
 *  0b011111..LPSPI0 RX data is selected.
 *  0b100000..LPSPI1 Frame is selected.
 *  0b100001..LPSPI1 RX data is selected.
 *  0b100010..RTC Seconds Counter is selected.
 *  0b100011..RTC Alarm is selected.
 *  0b100100..LPTMR0 Trigger is selected.
 *  0b100101..LPTMR1 Trigger is selected.
 *  0b100110..CMP0 Output is selected.
 *  0b100111..CMP1 Output is selected.
 *  0b101000..ADC0 Conversion A Complete is selected.
 *  0b101001..ADC0 Conversion B Complete is selected.
 *  0b101010..Port A Pin Trigger is selected.
 *  0b101011..Port B Pin Trigger is selected.
 *  0b101100..Port C Pin Trigger is selected.
 *  0b101101..Port D Pin Trigger is selected.
 *  0b101110..Port E Pin Trigger is selected.
 *  0b101111..TPM2 Overflow selected.
 *  0b110000..TPM2 Channel 0 is selected.
 *  0b110001..TPM2 Channel 1 is selected.
 *  0b110010..LPIT0 Channel 0 is selected.
 *  0b110011..LPIT0 Channel 1 is selected.
 *  0b110100..LPIT0 Channel 2 is selected.
 *  0b110101..LPIT0 Channel 3 is selected.
 *  0b110110..USB Start-of-Frame is selected.
 *  0b110111..LPUART2 RX Data is selected.
 *  0b111000..LPUART2 TX Data is selected.
 *  0b111001..LPUART2 RX Idle is selected.
 *  0b111010..LPI2C2 Master STOP is selected.
 *  0b111011..LPI2C2 Slave STOP is selected.
 *  0b111100..LPSPI2 Frame is selected.
 *  0b111101..LPSPI2 RX Data is selected.
 */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x3F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select
 *  0b000000..Trigger function is disabled.
 *  0b000001..Port pin trigger input is selected.
 *  0b000010..FlexIO Timer 0 input is selected.
 *  0b000011..FlexIO Timer 1 input is selected.
 *  0b000100..FlexIO Timer 2 input is selected.
 *  0b000101..FlexIO Timer 3 input is selected.
 *  0b000110..FlexIO Timer 4 input is selected.
 *  0b000111..FlexIO Timer 5 input is selected.
 *  0b001000..FlexIO Timer 6 input is selected.
 *  0b001001..FlexIO Timer 7 input is selected.
 *  0b001010..TPM0 Overflow is selected
 *  0b001011..TPM0 Channel 0 is selected
 *  0b001100..TPM0 Channel 1 is selected
 *  0b001101..TPM1 Overflow is selected
 *  0b001110..TPM1 Channel 0 is selected
 *  0b001111..TPM1 Channel 1 is selected
 *  0b010000..LPIT1 Channel 0 is selected
 *  0b010001..LPIT1 Channel 1 is selected
 *  0b010010..LPIT1 Channel 2 is selected
 *  0b010011..LPIT1 Channel 3 is selected
 *  0b010100..LPUART0 RX Data is selected.
 *  0b010101..LPUART0 TX Data is selected.
 *  0b010110..LPUART0 RX Idle is selected.
 *  0b010111..LPUART1 RX Data is selected.
 *  0b011000..LPUART1 TX Data is selected.
 *  0b011001..LPUART1 RX Idle is selected.
 *  0b011010..LPI2C0 Master STOP is selected.
 *  0b011011..LPI2C0 Slave STOP is selected.
 *  0b011100..LPI2C1 Master STOP is selected.
 *  0b011101..LPI2C1 Slave STOP is selected.
 *  0b011110..LPSPI0 Frame is selected.
 *  0b011111..LPSPI0 RX data is selected.
 *  0b100000..LPSPI1 Frame is selected.
 *  0b100001..LPSPI1 RX data is selected.
 *  0b100010..RTC Seconds Counter is selected.
 *  0b100011..RTC Alarm is selected.
 *  0b100100..LPTMR0 Trigger is selected.
 *  0b100101..LPTMR1 Trigger is selected.
 *  0b100110..CMP0 Output is selected.
 *  0b100111..CMP1 Output is selected.
 *  0b101000..ADC0 Conversion A Complete is selected.
 *  0b101001..ADC0 Conversion B Complete is selected.
 *  0b101010..Port A Pin Trigger is selected.
 *  0b101011..Port B Pin Trigger is selected.
 *  0b101100..Port C Pin Trigger is selected.
 *  0b101101..Port D Pin Trigger is selected.
 *  0b101110..Port E Pin Trigger is selected.
 *  0b101111..TPM2 Overflow selected.
 *  0b110000..TPM2 Channel 0 is selected.
 *  0b110001..TPM2 Channel 1 is selected.
 *  0b110010..LPIT0 Channel 0 is selected.
 *  0b110011..LPIT0 Channel 1 is selected.
 *  0b110100..LPIT0 Channel 2 is selected.
 *  0b110101..LPIT0 Channel 3 is selected.
 *  0b110110..USB Start-of-Frame is selected.
 *  0b110111..LPUART2 RX Data is selected.
 *  0b111000..LPUART2 TX Data is selected.
 *  0b111001..LPUART2 RX Idle is selected.
 *  0b111010..LPI2C2 Master STOP is selected.
 *  0b111011..LPI2C2 Slave STOP is selected.
 *  0b111100..LPSPI2 Frame is selected.
 *  0b111101..LPSPI2 RX Data is selected.
 */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - Enable
 *  0b0..Register can be written.
 *  0b1..Register cannot be written until the next system Reset.
 */
#define TRGMUX_TRGCFG_LK(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_LK_SHIFT)) & TRGMUX_TRGCFG_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */

#define TRGMUX_INSTANCE_MASK      0xF
#define TRGMUX_INSTANCE_SHIFT     12
#define TRGMUX_PERIPHERAL_MASK    0xFFF
#define TRGMUX_PERIPHERAL_SHIFT   0
#define TRGMUX_INSTANCE_0    0
#define TRGMUX_INSTANCE_1    1

#define TRGMUX_DMAMUX0_INDEX   ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 0)
#define TRGMUX_LPIT0_INDEX     ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 1)
#define TRGMUX_TPM2_INDEX      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 2)
#define TRGMUX_ADC0_INDEX      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 4)
#define TRGMUX_LPUART2_INDEX   ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 5)
#define TRGMUX_LPI2C2_INDEX    ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 7)
#define TRGMUX_LPSPI2_INDEX    ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 9)
#define TRGMUX_CMP0_INDEX      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 11)
#define TRGMUX_CMP1_INDEX      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 12)
#define TRGMUX_DAC0_INDEX      ((uint16_t)((TRGMUX_INSTANCE_0 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 13)
#define TRGMUX_DMAMUX0         (TRGMUX0->TRGCFG[0])
#define TRGMUX_LPIT0           (TRGMUX0->TRGCFG[1])
#define TRGMUX_TPM2            (TRGMUX0->TRGCFG[2])
#define TRGMUX_ADC0            (TRGMUX0->TRGCFG[4])
#define TRGMUX_LPUART2         (TRGMUX0->TRGCFG[5])
#define TRGMUX_LPI2C2          (TRGMUX0->TRGCFG[7])
#define TRGMUX_LPSPI2          (TRGMUX0->TRGCFG[9])
#define TRGMUX_CMP0            (TRGMUX0->TRGCFG[11])
#define TRGMUX_CMP1            (TRGMUX0->TRGCFG[12])
#define TRGMUX_DAC0            (TRGMUX0->TRGCFG[13])

#define TRGMUX_TPM0_INDEX      ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 2)
#define TRGMUX_TPM1_INDEX      ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 3)
#define TRGMUX_FLEXIO_INDEX    ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 4)
#define TRGMUX_LPUART0_INDEX   ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 5)
#define TRGMUX_LPUART1_INDEX   ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 6)
#define TRGMUX_LPI2C0_INDEX    ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 7)
#define TRGMUX_LPI2C1_INDEX    ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 8)
#define TRGMUX_LPSPI0_INDEX    ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 9)
#define TRGMUX_LPSPI1_INDEX    ((uint16_t)((TRGMUX_INSTANCE_1 & TRGMUX_INSTANCE_MASK) << TRGMUX_INSTANCE_SHIFT) | 10)
#define TRGMUX_TPM0            (TRGMUX1->TRGCFG[2])
#define TRGMUX_TPM1            (TRGMUX1->TRGCFG[3])
#define TRGMUX_FLEXIO          (TRGMUX1->TRGCFG[4])
#define TRGMUX_LPUART0         (TRGMUX1->TRGCFG[5])
#define TRGMUX_LPUART1         (TRGMUX1->TRGCFG[6])
#define TRGMUX_LPI2C0          (TRGMUX1->TRGCFG[7])
#define TRGMUX_LPI2C1          (TRGMUX1->TRGCFG[8])
#define TRGMUX_LPSPI0          (TRGMUX1->TRGCFG[9])
#define TRGMUX_LPSPI1          (TRGMUX1->TRGCFG[10])


/*!
 * @}
 */ /* end of group TRGMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_TRGMUX_H_ */

