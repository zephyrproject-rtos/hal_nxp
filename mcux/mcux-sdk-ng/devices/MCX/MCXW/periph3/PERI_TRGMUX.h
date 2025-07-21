/*
** ###################################################################
**     Processors:          MCXW727AMFTA_cm33_core0
**                          MCXW727AMFTA_cm33_core1
**                          MCXW727CMFTA_cm33_core0
**                          MCXW727CMFTA_cm33_core1
**                          MCXW727DMFTA_cm33_core0
**                          MCXW727DMFTA_cm33_core1
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250522
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
**     - rev. 1.0 (2024-10-13)
**         Rev. 1, 2024-10-13
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

#if (defined(CPU_MCXW727AMFTA_cm33_core0))
#include "MCXW727A_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727AMFTA_cm33_core1))
#include "MCXW727A_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core0))
#include "MCXW727C_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727CMFTA_cm33_core1))
#include "MCXW727C_cm33_core1_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core0))
#include "MCXW727D_cm33_core0_COMMON.h"
#elif (defined(CPU_MCXW727DMFTA_cm33_core1))
#include "MCXW727D_cm33_core1_COMMON.h"
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
 * @brief Enumeration for the TRGMUX source
 *
 * Defines the enumeration for the TRGMUX source collections.
 */
typedef enum _trgmux_source
{
    kTRGMUX_SourceDisabled          = 0U,          /**< Trigger function is disabled */
    kTRGMUX_SourceAlwaysHigh        = 1U,          /**< Trigger function is always high */
    kTRGMUX_SourceTrgmux0Input0     = 2U,          /**< TRGMUX0 Input 0 is selected */
    kTRGMUX_SourceTrgmux0Input1     = 3U,          /**< TRGMUX0 Input 1 is selected */
    kTRGMUX_SourceTrgmux0Input2     = 4U,          /**< TRGMUX0 Input 2 is selected */
    kTRGMUX_SourceTrgmux0Input3     = 5U,          /**< TRGMUX0 Input 3 is selected */
    kTRGMUX_SourceWuu0Trigger       = 6U,          /**< WUU0 Trigger Event is selected */
    kTRGMUX_SourceRtcAlarm          = 7U,          /**< RTC Alarm Event is selected */
    kTRGMUX_SourceRtcSeconds        = 8U,          /**< RTC Seconds Match is selected */
    kTRGMUX_SourceLptmr0Trigger     = 9U,          /**< LPTMR0 Counter Match is selected */
    kTRGMUX_SourceLptmr1Trigger     = 10U,         /**< LPTMR1 Counter Match is selected */
    kTRGMUX_SourceLpit0Channel0     = 11U,         /**< LPIT0 Channel 0 is selected */
    kTRGMUX_SourceLpit0Channel1     = 12U,         /**< LPIT0 Channel 1 is selected */
    kTRGMUX_SourceLpit0Channel2     = 13U,         /**< LPIT0 Channel 2 is selected */
    kTRGMUX_SourceLpit0Channel3     = 14U,         /**< LPIT0 Channel 3 is selected */
    kTRGMUX_SourceTpm0Channel0      = 15U,         /**< TPM0 Channel 0 is selected */
    kTRGMUX_SourceTpm0Channel1      = 16U,         /**< TPM0 Channel 1 is selected */
    kTRGMUX_SourceTpm0Channel2      = 17U,         /**< TPM0 Channel 2 is selected */
    kTRGMUX_SourceTpm0Channel3      = 18U,         /**< TPM0 Channel 3 is selected */
    kTRGMUX_SourceTpm0Channel4      = 19U,         /**< TPM0 Channel 4 is selected */
    kTRGMUX_SourceTpm0Channel5      = 20U,         /**< TPM0 Channel 5 is selected */
    kTRGMUX_SourceTpm0Overflow      = 21U,         /**< TPM0 Overflow is selected */
    kTRGMUX_SourceTpm1Channel0      = 22U,         /**< TPM1 Channel 0 is selected */
    kTRGMUX_SourceTpm1Channel1      = 23U,         /**< TPM1 Channel 1 is selected */
    kTRGMUX_SourceTpm1Channel2      = 24U,         /**< TPM1 Channel 2 is selected */
    kTRGMUX_SourceTpm1Channel3      = 25U,         /**< TPM1 Channel 3 is selected */
    kTRGMUX_SourceTpm1Channel4      = 26U,         /**< TPM1 Channel 4 is selected */
    kTRGMUX_SourceTpm1Channel5      = 27U,         /**< TPM1 Channel 5 is selected */
    kTRGMUX_SourceTpm1Overflow      = 28U,         /**< TPM1 Overflow is selected */
    kTRGMUX_SourceLpi2c0MasterStop  = 29U,         /**< LPI2C0 Master End of Packet is selected */
    kTRGMUX_SourceLpi2c0SlaveStop   = 30U,         /**< LPI2C0 Slave End of Packet is selected */
    kTRGMUX_SourceLpi2c1MasterStop  = 31U,         /**< LPI2C1 Master End of Packet is selected */
    kTRGMUX_SourceLpi2c1SlaveStop   = 32U,         /**< LPI2C1 Slave End of Packet is selected */
    kTRGMUX_SourceLpspi0Frame       = 33U,         /**< LPSPI0 End of Frame is selected */
    kTRGMUX_SourceLpspi0Rx          = 34U,         /**< LPSPI0 Received Data Word is selected */
    kTRGMUX_SourceLpspi1Frame       = 35U,         /**< LPSPI1 End of Frame is selected */
    kTRGMUX_SourceLpspi1Rx          = 36U,         /**< LPSPI1 Received Data Word is selected */
    kTRGMUX_SourceLpuart0RxData     = 37U,         /**< LPUART0 Received Data Word is selected */
    kTRGMUX_SourceLpuart0TxData     = 38U,         /**< LPUART0 Transmitted Data Word is selected */
    kTRGMUX_SourceLpuart0RxIdle     = 39U,         /**< LPUART0 Receive Line Idle is selected */
    kTRGMUX_SourceLpuart1RxData     = 40U,         /**< LPUART1 Received Data Word is selected */
    kTRGMUX_SourceLpuart1TxData     = 41U,         /**< LPUART1 Transmitted Data Word is selected */
    kTRGMUX_SourceLpuart1RxIdle     = 42U,         /**< LPUART1 Receive Line Idle is selected */
    kTRGMUX_SourceFlexIO0Timer0     = 43U,         /**< FlexIO0 Channel 0 is selected */
    kTRGMUX_SourceFlexIO0Timer1     = 44U,         /**< FlexIO0 Channel 1 is selected */
    kTRGMUX_SourceFlexIO0Timer2     = 45U,         /**< FlexIO0 Channel 2 is selected */
    kTRGMUX_SourceFlexIO0Timer3     = 46U,         /**< FlexIO0 Channel 3 is selected */
    kTRGMUX_SourceFlexIO0Timer4     = 47U,         /**< FLexIO0 Channel 4 is selected */
    kTRGMUX_SourceFlexIO0Timer5     = 48U,         /**< FlexIO0 Channel 5 is selected */
    kTRGMUX_SourceFlexIO0Timer6     = 49U,         /**< FlexIO0 Channel 6 is selected */
    kTRGMUX_SourceFlexIO0Timer7     = 50U,         /**< FlexIO0 Channel 7 is selected */
    kTRGMUX_SourceGpioAPinTrigger0  = 51U,         /**< GPIOA Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioAPinTrigger1  = 52U,         /**< GPIOA Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioBPinTrigger0  = 53U,         /**< GPIOB Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioBPinTrigger1  = 54U,         /**< GPIOB Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioCPinTrigger0  = 55U,         /**< GPIOC Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioCPinTrigger1  = 56U,         /**< GPIOC Pin event Trigger 1 is selected */
    kTRGMUX_SourceGpioDPinTrigger0  = 57U,         /**< GPIOD Pin event Trigger 0 is selected */
    kTRGMUX_SourceGpioDPinTrigger1  = 58U,         /**< GPIOD Pin event Trigger 1 is selected */
    kTRGMUX_SourceAdcGp0Output0     = 59U,         /**< ADC-GP0 Trigger Output 0 is selected */
    kTRGMUX_SourceAdcGp0Output1     = 60U,         /**< ADC-GP0 Trigger Output 1 is selected */
    kTRGMUX_SourceAdcGp0Output2     = 61U,         /**< ADC-GP0 Trigger Output 2 is selected */
    kTRGMUX_SourceAdcGp0Output3     = 62U,         /**< ADC-GP0 Trigger Output 3 is selected */
    kTRGMUX_SourceCmpGp0Output      = 63U,         /**< CMP-GP0 Comparator Output is selected */
    kTRGMUX_SourceCmpGp1Output      = 64U,         /**< CMP-GP1 Comparator Output is selected */
    kTRGMUX_SourceSpc0DcdcBurst     = 65U,         /**< SPC0 DCDC Burst Trig is selected */
    kTRGMUX_SourceRf2p4gTofTimestamp = 66U,        /**< RF-2.4G TOF TIMESTAMP TRIG is selected */
    kTRGMUX_SourceRf2p4gLantSw      = 67U,         /**< RF-2.4G LANT_SW is selected */
    kTRGMUX_SourceEzhIntChannel8    = 68U,         /**< EZH Interrupt channel 8 is selected */
    kTRGMUX_SourceEzhIntChannel9    = 69U,         /**< EZH Interrupt channel 9 is selected */
    kTRGMUX_SourceEzhIntChannel10   = 70U,         /**< EZH Interrupt channel 10 is selected */
    kTRGMUX_SourceEzhIntChannel11   = 71U,         /**< EZH Interrupt channel 11 is selected */
    kTRGMUX_SourceEzhIntChannel12   = 72U,         /**< EZH Interrupt channel 12 is selected */
    kTRGMUX_SourceEzhIntChannel13   = 73U,         /**< EZH Interrupt channel 13 is selected */
    kTRGMUX_SourceEzhIntChannel14   = 74U,         /**< EZH Interrupt channel 14 is selected */
    kTRGMUX_SourceEzhIntChannel15   = 75U,         /**< EZH Interrupt channel 15 is selected */
    kTRGMUX_SourceCpu0TxEv          = 76U,         /**< CM33 (Main) */
    kTRGMUX_SourceCpu1TxEv          = 77U,         /**< CM33 (Radio) */
} trgmux_source_t;

/* @} */
#endif /* TRGMUX_SOURCE_T_ */

#if !defined(TRGMUX_DEVICE_T_)
#define TRGMUX_DEVICE_T_
/*!
 * @brief Enumeration for the TRGMUX device
 *
 * Defines the enumeration for the TRGMUX device collections.
 */
typedef enum _trgmux_device
{
    kTRGMUX_Trgmux0Output0          = 0U,          /**< TRGMUX_OUT0 device trigger input */
    kTRGMUX_Trgmux0Lpit0            = 1U,          /**< LPIT0 device trigger input */
    kTRGMUX_Trgmux0Tpm0             = 2U,          /**< TPM0 device trigger input */
    kTRGMUX_Trgmux0Tpm1             = 3U,          /**< TPM1 device trigger input */
    kTRGMUX_Trgmux0Lpi2c0           = 4U,          /**< LPI2C0 device trigger input */
    kTRGMUX_Trgmux0Lpi2c1           = 5U,          /**< LPI2C1 device trigger input */
    kTRGMUX_Trgmux0Lpspi0           = 6U,          /**< LPSPI0 device trigger input */
    kTRGMUX_Trgmux0Lpspi1           = 7U,          /**< LPSPI1 device trigger input */
    kTRGMUX_Trgmux0Lpuart0          = 8U,          /**< LPUART0 device trigger input */
    kTRGMUX_Trgmux0Lpuart1          = 9U,          /**< LPUART1 device trigger input */
    kTRGMUX_Trgmux0Flexio0          = 10U,         /**< FlexIO0 device trigger input */
    kTRGMUX_Trgmux0AdcGp0           = 11U,         /**< ADC_GP0 device trigger input */
    kTRGMUX_Trgmux0CmpGp0           = 12U,         /**< CMP_GP0 device trigger input */
    kTRGMUX_Trgmux0CmpGp1           = 13U,         /**< CMP_GP1 device trigger input */
    kTRGMUX_Trgmux0Can0             = 14U,         /**< CAN0 device trigger input */
    kTRGMUX_Trgmux0Can1             = 15U,         /**< CAN1 device trigger input */
    kTRGMUX_Trgmux0Dsp0_0           = 16U,         /**< DSP0 device trigger input */
    kTRGMUX_Trgmux0Dsp0_1           = 17U,         /**< DSP0 device trigger input */
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
#define TRGMUX_TRGCFG_COUNT                       18u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX TRGMUX_OUT0..TRGMUX EZH_BLCIN_7_4, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX TRGMUX_OUT0..TRGMUX EZH_BLCIN_7_4 */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - TRGMUX Source Select 0 */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x7F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - TRGMUX Source Select 1 */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x7F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - TRGMUX Source Select 2 */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x7F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - TRGMUX Source Select 3 */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - TRGMUX Register Lock
 *  0b0..Register is writable
 *  0b1..Register is not writable until the next system reset
 */
#define TRGMUX_TRGCFG_LK(x)                      (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_LK_SHIFT)) & TRGMUX_TRGCFG_LK_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group TRGMUX_Register_Masks */


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

