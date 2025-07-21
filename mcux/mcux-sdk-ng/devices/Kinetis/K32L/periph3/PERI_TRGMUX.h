/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
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
**     - rev. 1.0 (2019-04-22)
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

#if (defined(CPU_K32L3A60VPJ1A_cm0plus))
#include "K32L3A60_cm0plus_COMMON.h"
#elif (defined(CPU_K32L3A60VPJ1A_cm4))
#include "K32L3A60_cm4_COMMON.h"
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
    kTRGMUX_Source0Disabled         = 0U,          /**< Trigger function is disabled */
    kTRGMUX_Source1Disabled         = 0U,          /**< Trigger function is disabled */
    kTRGMUX_Source0Llwu0            = 1U,          /**< LLWU0 trigger is selected */
    kTRGMUX_Source1Llwu1            = 1U,          /**< LLWU1 trigger is selected */
    kTRGMUX_Source0Lpit0Channel0    = 2U,          /**< LPIT0 Channel 0 is selected */
    kTRGMUX_Source1Lpit1Channel0    = 2U,          /**< LPIT1 Channel 0 is selected */
    kTRGMUX_Source0Lpit0Channel1    = 3U,          /**< LPIT0 Channel 1 is selected */
    kTRGMUX_Source1Lpit1Channel1    = 3U,          /**< LPIT1 Channel 1 is selected */
    kTRGMUX_Source0Lpit0Channel2    = 4U,          /**< LPIT0 Channel 2 is selected */
    kTRGMUX_Source1Lpit1Channel2    = 4U,          /**< LPIT1 Channel 2 is selected */
    kTRGMUX_Source0Lpit0Channel3    = 5U,          /**< LPIT0 Channel 3 is selected */
    kTRGMUX_Source1Lpit1Channel3    = 5U,          /**< LPIT1 Channel 3 is selected */
    kTRGMUX_Source0RtcAlarm         = 6U,          /**< RTC Alarm is selected */
    kTRGMUX_Source1Lptmr2Trigger    = 6U,          /**< LPTMR2 Trigger is selected */
    kTRGMUX_Source0RtcSeconds       = 7U,          /**< RTC Seconds is selected */
    kTRGMUX_Source1Tpm3ChannelEven  = 7U,          /**< TPM3 Channel Even is selected */
    kTRGMUX_Source0Lptmr0Trigger    = 8U,          /**< LPTMR0 Trigger is selected */
    kTRGMUX_Source1Tpm3ChannelOdd   = 8U,          /**< TPM3 Channel Odd is selected */
    kTRGMUX_Source0Lptmr1Trigger    = 9U,          /**< LPTMR1 Trigger is selected */
    kTRGMUX_Source1Tpm3Overflow     = 9U,          /**< TPM3 Overflow is selected */
    kTRGMUX_Source0Tpm0ChannelEven  = 10U,         /**< TPM0 Channel Even is selected */
    kTRGMUX_Source1Lpi2c3MasterStop = 10U,         /**< LPI2C3 Master Stop is selected */
    kTRGMUX_Source0Tpm0ChannelOdd   = 11U,         /**< TPM0 Channel Odd is selected */
    kTRGMUX_Source1Lpi2c3SlaveStop  = 11U,         /**< LPI2C3 Slave Stop is selected */
    kTRGMUX_Source0Tpm0Overflow     = 12U,         /**< TPM0 Overflow is selected */
    kTRGMUX_Source1Lpspi3Frame      = 12U,         /**< LPSPI3 Frame is selected */
    kTRGMUX_Source0Tpm1ChannelEven  = 13U,         /**< TPM1 Channel Even is selected */
    kTRGMUX_Source1Lpspi3RX         = 13U,         /**< LPSPI3 Rx is selected */
    kTRGMUX_Source0Tpm1ChannelOdd   = 14U,         /**< TPM1 Channel Odd is selected */
    kTRGMUX_Source1Lpuart3RxData    = 14U,         /**< LPUART3 Rx Data is selected */
    kTRGMUX_Source0Tpm1Overflow     = 15U,         /**< TPM1 Overflow is selected */
    kTRGMUX_Source1Lpuart3RxIdle    = 15U,         /**< LPUART3 Rx Idle is selected */
    kTRGMUX_Source0Tpm2ChannelEven  = 16U,         /**< TPM2 Channel Even is selected */
    kTRGMUX_Source1Lpuart3TxData    = 16U,         /**< LPUART3 Tx Data is selected */
    kTRGMUX_Source0Tpm2ChannelOdd   = 17U,         /**< TPM2 Channel Odd is selected */
    kTRGMUX_Source1PortEPinTrigger  = 17U,         /**< PORTE Pin Trigger is selected */
    kTRGMUX_Source0Tpm2Overflow     = 18U,         /**< TPM2 Overflow is selected */
    kTRGMUX_Source1Lpcmp1Output     = 18U,         /**< LPCMP1 Output is selected */
    kTRGMUX_Source0FlexIO0Timer0    = 19U,         /**< FlexIO0 Timer 0 is selected */
    kTRGMUX_Source1RtcAlarm         = 19U,         /**< RTC Alarm is selected */
    kTRGMUX_Source0FlexIO0Timer1    = 20U,         /**< FlexIO0 Timer 1 is selected */
    kTRGMUX_Source1RtcSeconds       = 20U,         /**< RTC Seconds is selected */
    kTRGMUX_Source0FlexIO0Timer2    = 21U,         /**< FlexIO0 Timer 2 is selected */
    kTRGMUX_Source1Lptmr0Trigger    = 21U,         /**< LPTMR0 Trigger is selected */
    kTRGMUX_Source0FlexIO0Timer3    = 22U,         /**< FlexIO0 Timer 3 is selected */
    kTRGMUX_Source1Lptmr1Trigger    = 22U,         /**< LPTMR1 Trigger is selected */
    kTRGMUX_Source0FlexIO0Timer4    = 23U,         /**< FLexIO0 Timer 4 is selected */
    kTRGMUX_Source1Tpm1ChannelEven  = 23U,         /**< TPM1 Channel Even is selected */
    kTRGMUX_Source0FlexIO0Timer5    = 24U,         /**< FlexIO0 Timer 5 is selected */
    kTRGMUX_Source1Tpm1ChannelOdd   = 24U,         /**< TPM1 Channel Odd is selected */
    kTRGMUX_Source0FlexIO0Timer6    = 25U,         /**< FlexIO0 Timer 6 is selected */
    kTRGMUX_Source1Tpm1Overflow     = 25U,         /**< TPM1 Overflow is selected */
    kTRGMUX_Source0FlexIO0Timer7    = 26U,         /**< FlexIO0 Timer 7 is selected */
    kTRGMUX_Source1Tpm2ChannelEven  = 26U,         /**< TPM2 Channel Even is selected */
    kTRGMUX_Source0Lpi2c0MasterStop = 27U,         /**< LPI2C0 Master Stop is selected */
    kTRGMUX_Source1Tpm2ChannelOdd   = 27U,         /**< TPM2 Channel Odd is selected */
    kTRGMUX_Source0Lpi2c0SlaveStop  = 28U,         /**< LPI2C0 Slave Stop is selected */
    kTRGMUX_Source1Tpm2Overflow     = 28U,         /**< TPM2 Overflow is selected */
    kTRGMUX_Source0Lpi2c1MasterStop = 29U,         /**< LPI2C1 Master Stop is selected */
    kTRGMUX_Source1FlexIO0Timer0    = 29U,         /**< FlexIO0 Timer 0 is selected */
    kTRGMUX_Source0Lpi2c1SlaveStop  = 30U,         /**< LPI2C1 Slave Stop is selected */
    kTRGMUX_Source1FlexIO0Timer1    = 30U,         /**< FlexIO0 Timer 1 is selected */
    kTRGMUX_Source0Lpi2c2MasterStop = 31U,         /**< LPI2C2 Master Stop is selected */
    kTRGMUX_Source1FlexIO0Timer2    = 31U,         /**< FlexIO0 Timer 2 is selected */
    kTRGMUX_Source0Lpi2c2SlaveStop  = 32U,         /**< LPI2C2 Slave Stop is selected */
    kTRGMUX_Source1FlexIO0Timer3    = 32U,         /**< FlexIO0 Timer 3 is selected */
    kTRGMUX_Source0Sai0Rx           = 33U,         /**< SAI0 Rx Frame Sync is selected */
    kTRGMUX_Source1FlexIO0Timer4    = 33U,         /**< FLexIO0 Timer 4 is selected */
    kTRGMUX_Source0Sai0Tx           = 34U,         /**< SAI0 Tx Frame Sync is selected */
    kTRGMUX_Source1FlexIO0Timer5    = 34U,         /**< FlexIO0 Timer 5 is selected */
    kTRGMUX_Source0Lpspi0Frame      = 35U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_Source1FlexIO0Timer6    = 35U,         /**< FlexIO0 Timer 6 is selected */
    kTRGMUX_Source0Lpspi0Rx         = 36U,         /**< LPSPI0 Rx is selected */
    kTRGMUX_Source1FlexIO0Timer7    = 36U,         /**< FlexIO0 Timer 7 is selected */
    kTRGMUX_Source0Lpspi1Frame      = 37U,         /**< LPSPI1 Frame is selected */
    kTRGMUX_Source1Lpi2c0MasterStop = 37U,         /**< LPI2C0 Master Stop is selected */
    kTRGMUX_Source0Lpspi1Rx         = 38U,         /**< LPSPI1 Rx is selected */
    kTRGMUX_Source1Lpi2c0SlaveStop  = 38U,         /**< LPI2C0 Slave Stop is selected */
    kTRGMUX_Source0Lpspi2Frame      = 39U,         /**< LPSPI2 Frame is selected */
    kTRGMUX_Source1Lpi2c1MasterStop = 39U,         /**< LPI2C1 Master Stop is selected */
    kTRGMUX_Source0Lpspi2RX         = 40U,         /**< LPSPI2 Rx is selected */
    kTRGMUX_Source1Lpi2c1SlaveStop  = 40U,         /**< LPI2C1 Slave Stop is selected */
    kTRGMUX_Source0Lpuart0RxData    = 41U,         /**< LPUART0 Rx Data is selected */
    kTRGMUX_Source1Lpi2c2MasterStop = 41U,         /**< LPI2C2 Master Stop is selected */
    kTRGMUX_Source0Lpuart0RxIdle    = 42U,         /**< LPUART0 Rx Idle is selected */
    kTRGMUX_Source1Lpi2c2SlaveStop  = 42U,         /**< LPI2C2 Slave Stop is selected */
    kTRGMUX_Source0Lpuart0TxData    = 43U,         /**< LPUART0 Tx Data is selected */
    kTRGMUX_Source1Sai0Rx           = 43U,         /**< SAI0 Rx Frame Sync is selected */
    kTRGMUX_Source0Lpuart1RxData    = 44U,         /**< LPUART1 Rx Data is selected */
    kTRGMUX_Source1Sai0Tx           = 44U,         /**< SAI0 Tx Frame Sync is selected */
    kTRGMUX_Source0Lpuart1RxIdle    = 45U,         /**< LPUART1 Rx Idle is selected */
    kTRGMUX_Source1Lpspi0Frame      = 45U,         /**< LPSPI0 Frame is selected */
    kTRGMUX_Source0Lpuart1TxData    = 46U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_Source1Lpspi0Rx         = 46U,         /**< LPSPI0 Rx is selected */
    kTRGMUX_Source0Lpuart2RxData    = 47U,         /**< LPUART2 RX Data is selected */
    kTRGMUX_Source1Lpspi1Frame      = 47U,         /**< LPSPI1 Frame is selected */
    kTRGMUX_Source0Lpuart2RxIdle    = 48U,         /**< LPUART2 RX Idle is selected */
    kTRGMUX_Source1Lpspi1Rx         = 48U,         /**< LPSPI1 Rx is selected */
    kTRGMUX_Source0Lpuart2TxData    = 49U,         /**< LPUART2 TX Data is selected */
    kTRGMUX_Source1Lpspi2Frame      = 49U,         /**< LPSPI2 Frame is selected */
    kTRGMUX_Source0Usb0Frame        = 50U,         /**< USB0 Start of Frame is selected */
    kTRGMUX_Source1Lpspi2RX         = 50U,         /**< LPSPI2 Rx is selected */
    kTRGMUX_Source0PortAPinTrigger  = 51U,         /**< PORTA Pin Trigger is selected */
    kTRGMUX_Source1Lpuart0RxData    = 51U,         /**< LPUART0 Rx Data is selected */
    kTRGMUX_Source0PortBPinTrigger  = 52U,         /**< PORTB Pin Trigger is selected */
    kTRGMUX_Source1Lpuart0RxIdle    = 52U,         /**< LPUART0 Rx Idle is selected */
    kTRGMUX_Source0PortCPinTrigger  = 53U,         /**< PORTC Pin Trigger is selected */
    kTRGMUX_Source1Lpuart0TxData    = 53U,         /**< LPUART0 Tx Data is selected */
    kTRGMUX_Source0PortDPinTrigger  = 54U,         /**< PORTD Pin Trigger is selected */
    kTRGMUX_Source1Lpuart1RxData    = 54U,         /**< LPUART1 Rx Data is selected */
    kTRGMUX_Source0Lpcmp0Output     = 55U,         /**< LPCMP0 Output is selected */
    kTRGMUX_Source1Lpuart1RxIdle    = 55U,         /**< LPUART1 Rx Idle is selected */
    kTRGMUX_Source0Lpi2c3MasterStop = 56U,         /**< LPI2C3 Master Stop is selected */
    kTRGMUX_Source1Lpuart1TxData    = 56U,         /**< LPUART1 TX Data is selected */
    kTRGMUX_Source0Lpi2c3SlaveStop  = 57U,         /**< LPI2C3 Slave Stop is selected */
    kTRGMUX_Source1Lpuart2RxData    = 57U,         /**< LPUART2 RX Data is selected */
    kTRGMUX_Source0Lpspi3Frame      = 58U,         /**< LPSPI3 Frame is selected */
    kTRGMUX_Source1Lpuart2RxIdle    = 58U,         /**< LPUART2 RX Idle is selected */
    kTRGMUX_Source0Lpspi3Rx         = 59U,         /**< LPSPI3 Rx Data is selected */
    kTRGMUX_Source1Lpuart2TxData    = 59U,         /**< LPUART2 TX Data is selected */
    kTRGMUX_Source0Lpuart3RxData    = 60U,         /**< LPUART3 Rx Data is selected */
    kTRGMUX_Source1PortAPinTrigger  = 60U,         /**< PORTA Pin Trigger is selected */
    kTRGMUX_Source0Lpuart3RxIdle    = 61U,         /**< LPUART3 Rx Idle is selected */
    kTRGMUX_Source1PortBPinTrigger  = 61U,         /**< PORTB Pin Trigger is selected */
    kTRGMUX_Source0Lpuart3TxData    = 62U,         /**< LPUART3 Tx Data is selected */
    kTRGMUX_Source1PortCPinTrigger  = 62U,         /**< PORTC Pin Trigger is selected */
    kTRGMUX_Source0PortEPinTrigger  = 63U,         /**< PORTE Pin Trigger is selected */
    kTRGMUX_Source1PortDPinTrigger  = 63U,         /**< PORTD Pin Trigger is selected */
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
    kTRGMUX_Trgmux0Dmamux0          = 0U,          /**< DMAMUX0 device trigger input */
    kTRGMUX_Trgmux1Dmamux1          = 0U,          /**< DMAMUX1 device trigger input */
    kTRGMUX_Trgmux0Lpit0            = 1U,          /**< LPIT0 device trigger input */
    kTRGMUX_Trgmux1Lpit1            = 1U,          /**< LPIT1 device trigger input */
    kTRGMUX_Trgmux0Tpm0             = 2U,          /**< TPM0 device trigger input */
    kTRGMUX_Trgmux1Tpm3             = 2U,          /**< TPM3 device trigger input */
    kTRGMUX_Trgmux0Tpm1             = 3U,          /**< TPM1 device trigger input */
    kTRGMUX_Trgmux1Lpi2c3           = 3U,          /**< LPI2C3 device trigger input */
    kTRGMUX_Trgmux0Tpm2             = 4U,          /**< TPM2 device trigger input */
    kTRGMUX_Trgmux1Lpspi3           = 4U,          /**< LPSPI3 device trigger input */
    kTRGMUX_Trgmux0Flexio0          = 5U,          /**< FLEXIO0 device trigger input */
    kTRGMUX_Trgmux1Lpuart3          = 5U,          /**< LPUART3 device trigger input */
    kTRGMUX_Trgmux0Lpi2c0           = 6U,          /**< LPI2C0 device trigger input */
    kTRGMUX_Trgmux1Lpcmp1           = 6U,          /**< LPCMP1 device trigger input */
    kTRGMUX_Trgmux0Lpi2c1           = 7U,          /**< LPI2C1 device trigger input */
    kTRGMUX_Trgmux1Dmamux0          = 7U,          /**< DMAMUX0 device trigger input */
    kTRGMUX_Trgmux0Lpi2c2           = 8U,          /**< LPI2C2 device trigger input */
    kTRGMUX_Trgmux1Lpit0            = 8U,          /**< LPIT0 device trigger input */
    kTRGMUX_Trgmux0Lpspi0           = 9U,          /**< LPSPI0 device trigger input */
    kTRGMUX_Trgmux1Tpm0             = 9U,          /**< TPM0 device trigger input */
    kTRGMUX_Trgmux0Lpspi1           = 10U,         /**< LPSPI1 device trigger input */
    kTRGMUX_Trgmux1Tpm1             = 10U,         /**< TPM1 device trigger input */
    kTRGMUX_Trgmux0Lpspi2           = 11U,         /**< LPSPI2 device trigger input */
    kTRGMUX_Trgmux1Tpm2             = 11U,         /**< TPM2 device trigger input */
    kTRGMUX_Trgmux0Lpuart0          = 12U,         /**< LPUART0 device trigger input */
    kTRGMUX_Trgmux1Flexio0          = 12U,         /**< FLEXIO0 device trigger input */
    kTRGMUX_Trgmux0Lpuart1          = 13U,         /**< LPUART1 device trigger input */
    kTRGMUX_Trgmux1Lpi2c0           = 13U,         /**< LPI2C0 device trigger input */
    kTRGMUX_Trgmux0Lpuart2          = 14U,         /**< LPUART2 device trigger input */
    kTRGMUX_Trgmux1Lpi2c1           = 14U,         /**< LPI2C1 device trigger input */
    kTRGMUX_Trgmux0Lpadc0           = 15U,         /**< LPADC0 device trigger input */
    kTRGMUX_Trgmux1Lpi2c2           = 15U,         /**< LPI2C2 device trigger input */
    kTRGMUX_Trgmux0Lpcmp0           = 16U,         /**< LPCMP0 device trigger input */
    kTRGMUX_Trgmux1Lpspi0           = 16U,         /**< LPSPI0 device trigger input */
    kTRGMUX_Trgmux0Lpdac0           = 17U,         /**< LPDAC0 device trigger input */
    kTRGMUX_Trgmux1Lpspi1           = 17U,         /**< LPSPI1 device trigger input */
    kTRGMUX_Trgmux0Dmamux1          = 18U,         /**< DMAMUX1 device trigger input */
    kTRGMUX_Trgmux1Lpspi2           = 18U,         /**< LPSPI2 device trigger input */
    kTRGMUX_Trgmux0Lpit1            = 19U,         /**< LPIT1 device trigger input */
    kTRGMUX_Trgmux1Lpuart0          = 19U,         /**< LPUART0 device trigger input */
    kTRGMUX_Trgmux0Tpm3             = 20U,         /**< TPM3 device trigger input */
    kTRGMUX_Trgmux1Lpuart1          = 20U,         /**< LPUART1 device trigger input */
    kTRGMUX_Trgmux0Lpi2c3           = 21U,         /**< LPI2C3 device trigger input */
    kTRGMUX_Trgmux1Lpuart2          = 21U,         /**< LPUART2 device trigger input */
    kTRGMUX_Trgmux0Lpspi3           = 22U,         /**< LPSPI3 device trigger input */
    kTRGMUX_Trgmux1Lpadc0           = 22U,         /**< LPADC0 device trigger input */
    kTRGMUX_Trgmux0Lpuart3          = 23U,         /**< LPUART3 device trigger input */
    kTRGMUX_Trgmux1Lpcmp0           = 23U,         /**< LPCMP0 device trigger input */
    kTRGMUX_Trgmux0Lpcmp1           = 24U,         /**< LPCMP1 device trigger input */
    kTRGMUX_Trgmux1Lpdac0           = 24U,         /**< LPDAC0 device trigger input */
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
#define TRGMUX_TRGCFG_COUNT                       25u

/** TRGMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX TRGMUX_DMAMUX0 Register..TRGMUX TRGMUX_LPCMP1 Register, array offset: 0x0, array step: 0x4 */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX TRGMUX_DMAMUX0 Register..TRGMUX TRGMUX_LPCMP1 Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x3FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x3F00U)
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x3F0000U)
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x3F000000U)
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)

#define TRGMUX_TRGCFG_LK_MASK                    (0x80000000U)
#define TRGMUX_TRGCFG_LK_SHIFT                   (31U)
/*! LK - TRGMUX register lock.
 *  0b0..Register can be written.
 *  0b1..Register cannot be written until the next system Reset.
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

