/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
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
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
#if !defined(TRGMUX0_SOURCE_T_)
#define TRGMUX0_SOURCE_T_
/*!
 * @addtogroup trgmux0_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the TRGMUX0 source
 *
 * Defines the enumeration for the TRGMUX0 source collections.
 */
typedef enum _trgmux0_source
{
    kTRGMUX0_SourceDisabled         = 0U,          /**< Trigger function is disabled */
    kTRGMUX0_SourceFlexIO0Timer0    = 2U,          /**< FlexIO0 Timer0 input is selected */
    kTRGMUX0_SourceFlexIO0Timer1    = 3U,          /**< FlexIO0 Timer1 input is selected */
    kTRGMUX0_SourceFlexIO0Timer2    = 4U,          /**< FlexIO0 Timer2 input is selected */
    kTRGMUX0_SourceFlexIO0Timer3    = 5U,          /**< FlexIO0 Timer3 input is selected */
    kTRGMUX0_SourceFlexIO0Timer4    = 6U,          /**< FlexIO0 Timer4 input is selected */
    kTRGMUX0_SourceFlexIO0Timer5    = 7U,          /**< FlexIO0 Timer5 input is selected */
    kTRGMUX0_SourceFlexIO0Timer6    = 8U,          /**< FlexIO0 Timer6 input is selected */
    kTRGMUX0_SourceFlexIO0Timer7    = 9U,          /**< FlexIO0 Timer7 input is selected */
    kTRGMUX0_SourceTPM0Overflow     = 10U,         /**< TPM0 Overflow input is selected */
    kTRGMUX0_SourceTPM0Channel0     = 11U,         /**< TPM0 Channel0 input is selected */
    kTRGMUX0_SourceTPM0Channel1     = 12U,         /**< TPM0 Channel1 input is selected */
    kTRGMUX0_SourceTPM1Overflow     = 13U,         /**< TPM1 Overflow input is selected */
    kTRGMUX0_SourceTPM1Channel0     = 14U,         /**< TPM1 Channel0 input is selected */
    kTRGMUX0_SourceTPM1Channel1     = 15U,         /**< TPM1 Channel1 input is selected */
    kTRGMUX0_SourceTPM2Overflow     = 16U,         /**< TPM2 Overflow input is selected */
    kTRGMUX0_SourceTPM2Channel0     = 17U,         /**< TPM2 Channel0 input is selected */
    kTRGMUX0_SourceTPM2Channel1     = 18U,         /**< TPM2 Channel1 input is selected */
    kTRGMUX0_SourceTPM3Overflow     = 19U,         /**< TPM3 Overflow input is selected */
    kTRGMUX0_SourceTPM3Channel0     = 20U,         /**< TPM3 Channel0 input is selected */
    kTRGMUX0_SourceTPM3Channel1     = 21U,         /**< TPM3 Channel1 input is selected */
    kTRGMUX0_SourceLPIT0Channel0    = 22U,         /**< LPIT0 Channel0 input is selected */
    kTRGMUX0_SourceLPIT0Channel1    = 23U,         /**< LPIT0 Channel1 input is selected */
    kTRGMUX0_SourceLPIT0Channel2    = 24U,         /**< LPIT0 Channel2 input is selected */
    kTRGMUX0_SourceLPIT0Channel3    = 25U,         /**< LPIT0 Channel3 input is selected */
    kTRGMUX0_SourceLPUART0RxData    = 30U,         /**< LPUART0 RX Data input is selected */
    kTRGMUX0_SourceLPUART0TxData    = 31U,         /**< LPUART0 TX Data input is selected */
    kTRGMUX0_SourceLPUART0RxIdle    = 32U,         /**< LPUART0 RX Idle input is selected */
    kTRGMUX0_SourceLPUART1RxData    = 33U,         /**< LPUART1 RX Data input is selected */
    kTRGMUX0_SourceLPUART1TxData    = 34U,         /**< LPUART1 TX Data input is selected */
    kTRGMUX0_SourceLPUART1RxIdle    = 35U,         /**< LPUART1 RX Idle input is selected */
    kTRGMUX0_SourceLPUART2RxData    = 36U,         /**< LPUART2 RX Data input is selected */
    kTRGMUX0_SourceLPUART2TxData    = 37U,         /**< LPUART2 TX Data input is selected */
    kTRGMUX0_SourceLPUART2RxIdle    = 38U,         /**< LPUART2 RX Idle input is selected */
    kTRGMUX0_SourceLPUART3RxData    = 39U,         /**< LPUART3 RX Data input is selected */
    kTRGMUX0_SourceLPUART3TxData    = 40U,         /**< LPUART3 TX Data input is selected */
    kTRGMUX0_SourceLPUART3RxIdle    = 41U,         /**< LPUART3 RX Idle input is selected */
    kTRGMUX0_SourceLPI2C0MasterStop = 42U,         /**< LPI2C0 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C0SlaveStop  = 43U,         /**< LPI2C0 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C1MasterStop = 44U,         /**< LPI2C1 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C1SlaveStop  = 45U,         /**< LPI2C1 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C2MasterStop = 46U,         /**< LPI2C2 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C2SlaveStop  = 47U,         /**< LPI2C2 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C3MasterStop = 48U,         /**< LPI2C3 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C3SlaveStop  = 49U,         /**< LPI2C3 Slave Stop input is selected */
    kTRGMUX0_SourceLPSPI0Frame      = 50U,         /**< LPSPI0 Frame input is selected */
    kTRGMUX0_SourceLPSPI0RxData     = 51U,         /**< LPSPI0 RX Data input is selected */
    kTRGMUX0_SourceLPSPI1Frame      = 52U,         /**< LPSPI1 Frame input is selected */
    kTRGMUX0_SourceLPSPI1RxData     = 53U,         /**< LPSPI1 RX Data input is selected */
    kTRGMUX0_SourceLPTMR0           = 56U,         /**< LPTMR0 input is selected */
    kTRGMUX0_SourceLPTMR1           = 57U,         /**< LPTMR1 input is selected */
    kTRGMUX0_SourceCMP0Output       = 58U,         /**< CMP0 Output input is selected */
    kTRGMUX0_SourceCMP1Output       = 59U,         /**< CMP1 Output input is selected */
    kTRGMUX0_SourcePORTAPin         = 64U,         /**< PORT A Pin input is selected */
    kTRGMUX0_SourcePORTBPin         = 65U,         /**< PORT B Pin input is selected */
    kTRGMUX0_SourceI2S0TxFrameSync  = 66U,         /**< I2S0 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S0RxFrameSync  = 67U,         /**< I2S0 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S1TxFrameSync  = 68U,         /**< I2S1 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S1RxFrameSync  = 69U,         /**< I2S1 RX Frame Sync input is selected */
} trgmux0_source_t;

/* @} */
#endif /* TRGMUX0_SOURCE_T_ */

#if !defined(TRGMUX1_SOURCE_T_)
#define TRGMUX1_SOURCE_T_
/*!
 * @addtogroup trgmux1_source
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the TRGMUX1 source
 *
 * Defines the enumeration for the TRGMUX1 source collections.
 */
typedef enum _trgmux1_source
{
    kTRGMUX1_SourceDisabled         = 0U,          /**< Trigger function is disabled */
    kTRGMUX1_SourceFlexIO1Timer0    = 1U,          /**< FlexIO1 Timer0 input is selected */
    kTRGMUX1_SourceFlexIO1Timer1    = 2U,          /**< FlexIO1 Timer1 input is selected */
    kTRGMUX1_SourceFlexIO1Timer2    = 3U,          /**< FlexIO1 Timer2 input is selected */
    kTRGMUX1_SourceFlexIO1Timer3    = 4U,          /**< FlexIO1 Timer3 input is selected */
    kTRGMUX1_SourceFlexIO1Timer4    = 5U,          /**< FlexIO1 Timer4 input is selected */
    kTRGMUX1_SourceFlexIO1Timer5    = 6U,          /**< FlexIO1 Timer5 input is selected */
    kTRGMUX1_SourceFlexIO1Timer6    = 7U,          /**< FlexIO1 Timer6 input is selected */
    kTRGMUX1_SourceFlexIO1Timer7    = 8U,          /**< FlexIO1 Timer7 input is selected */
    kTRGMUX1_SourceTPM4Overflow     = 9U,          /**< TPM4 Overflow input is selected */
    kTRGMUX1_SourceTPM4Channel0     = 10U,         /**< TPM4 Channel0 input is selected */
    kTRGMUX1_SourceTPM4Channel1     = 11U,         /**< TPM4 Channel1 input is selected */
    kTRGMUX1_SourceTPM5Overflow     = 12U,         /**< TPM5 Overflow input is selected */
    kTRGMUX1_SourceTPM5Channel0     = 13U,         /**< TPM5 Channel0 input is selected */
    kTRGMUX1_SourceTPM5Channel1     = 14U,         /**< TPM5 Channel1 input is selected */
    kTRGMUX1_SourceTPM6Overflow     = 15U,         /**< TPM6 Overflow input is selected */
    kTRGMUX1_SourceTPM6Channel0     = 16U,         /**< TPM6 Channel0 input is selected */
    kTRGMUX1_SourceTPM6Channel1     = 17U,         /**< TPM6 Channel1 input is selected */
    kTRGMUX1_SourceTPM7Overflow     = 18U,         /**< TPM7 Overflow input is selected */
    kTRGMUX1_SourceTPM7Channel0     = 19U,         /**< TPM7 Channel0 input is selected */
    kTRGMUX1_SourceTPM7Channel1     = 20U,         /**< TPM7 Channel1 input is selected */
    kTRGMUX1_SourceLPUART4RxData    = 21U,         /**< LPUART4 RX data input is selected */
    kTRGMUX1_SourceLPUART4TxData    = 22U,         /**< LPUART4 TX data input is selected */
    kTRGMUX1_SourceLPUART4RxIdle    = 23U,         /**< LPUART4 RX idle input is selected */
    kTRGMUX1_SourceLPUART5RxData    = 24U,         /**< LPUART5 RX data input is selected */
    kTRGMUX1_SourceLPUART5TxData    = 25U,         /**< LPUART5 TX data input is selected */
    kTRGMUX1_SourceLPUART5RXIdle    = 26U,         /**< LPUART5 RX Idle input is selected */
    kTRGMUX1_SourceLPUART6RxData    = 27U,         /**< LPUART6 RX data input is selected */
    kTRGMUX1_SourceLPUART6TxData    = 28U,         /**< LPUART6 TX data input is selected */
    kTRGMUX1_SourceLPUART6RxIdle    = 29U,         /**< LPUART6 RX idle input is selected */
    kTRGMUX1_SourceLPUART7RxData    = 30U,         /**< LPUART7 RX data input is selected */
    kTRGMUX1_SourceLPUART7TxData    = 31U,         /**< LPUART7 TX data input is selected */
    kTRGMUX1_SourceLPUART7RxIdle    = 32U,         /**< LPUART7 RX idle input is selected */
    kTRGMUX1_SourceLPI2C4MasterSTOP = 33U,         /**< LPI2C4 Master STOP input is selected */
    kTRGMUX1_SourceLPI2C4SlaveSTOP  = 34U,         /**< LPI2C4 Slave STOP input is selected */
    kTRGMUX1_SourceLPI2C5MasterSTOP = 35U,         /**< LPI2C5 Master STOP input is selected */
    kTRGMUX1_SourceLPI2C5SlaveSTOP  = 36U,         /**< LPI2C5 Slave STOP input is selected */
    kTRGMUX1_SourceLPI2C6MasterSTOP = 37U,         /**< LPI2C6 Master STOP input is selected */
    kTRGMUX1_SourceLPI2C6SlaveSTOP  = 38U,         /**< LPI2C6 Slave STOP input is selected */
    kTRGMUX1_SourceLPI2C7MasterSTOP = 39U,         /**< LPI2C7 Master STOP input is selected */
    kTRGMUX1_SourceLPI2C7SlaveSTOP  = 40U,         /**< LPI2C7 Slave STOP input is selected */
    kTRGMUX1_SourceLPSPI2Frame      = 41U,         /**< LPSPI2 Frame input is selected */
    kTRGMUX1_SourceLPSPI2RxData     = 42U,         /**< LPSPI2 RX data input is selected */
    kTRGMUX1_SourceLPSPI3Frame      = 43U,         /**< LPSPI3 Frame input is selected */
    kTRGMUX1_SourceLPSPI3RxData     = 44U,         /**< LPSPI3 RX data input is selected */
    kTRGMUX1_SourcePORTCPin         = 45U,         /**< PORT C Pin input is selected */
    kTRGMUX1_SourcePORTDPin         = 46U,         /**< PORT D Pin input is selected */
    kTRGMUX1_SourcePORTEPin         = 47U,         /**< PORT E Pin input is selected */
    kTRGMUX1_SourcePORTFPin         = 48U,         /**< PORT F Pin input is selected */
    kTRGMUX1_SourceUSB0StartOfFrame = 49U,         /**< USB0 Start of Frame input is selected */
    kTRGMUX1_SourceUSB1StartOfFrame = 50U,         /**< USB1 Start of Frame input is selected */
    kTRGMUX1_SourceLPIT1Channel0    = 51U,         /**< LPIT1 Channel 0 input is selected */
    kTRGMUX1_SourceLPIT1Channel1    = 52U,         /**< LPIT1 Channel 1 input is selected */
    kTRGMUX1_SourceLPIT1Channel2    = 53U,         /**< LPIT1 Channel 2 input is selected */
    kTRGMUX1_SourceLPIT1Channel3    = 54U,         /**< LPIT1 Channel 3 input is selected */
} trgmux1_source_t;

/* @} */
#endif /* TRGMUX1_SOURCE_T_ */

#if !defined(TRGMUX0_DEVICE_T_)
#define TRGMUX0_DEVICE_T_
/*!
 * @brief Enumeration for the TRGMUX0 device
 *
 * Defines the enumeration for the TRGMUX0 device collections.
 */
typedef enum _trgmux0_device
{
    kTRGMUX0_DMAMUX0_CH0_3          = 0U,          /**< DMAMUX0 channel 0-3 trigger */
    kTRGMUX0_DMAMUX0_CH4_7          = 1U,          /**< DMAMUX0 channel 4-7 trigger */
    kTRGMUX0_LPIT0                  = 2U,          /**< LPIT0 trigger 0-3 */
    kTRGMUX0_TPM0                   = 4U,          /**< TPM0 channel 0-1 trigger */
    kTRGMUX0_TPM1                   = 5U,          /**< TPM1 channel 0-1 trigger */
    kTRGMUX0_TPM2                   = 6U,          /**< TPM2 channel 0-1 trigger */
    kTRGMUX0_TPM3                   = 7U,          /**< TPM3 channel 0-1 trigger */
    kTRGMUX0_ADC0                   = 8U,          /**< ADC0 Trigger A, B */
    kTRGMUX0_ADC1                   = 9U,          /**< ADC1 Trigger A, B */
    kTRGMUX0_CMP0                   = 10U,         /**< CMP0 Window trigger */
    kTRGMUX0_CMP1                   = 11U,         /**< CMP1 Window trigger */
    kTRGMUX0_DAC0                   = 12U,         /**< DAC0 Trigger */
    kTRGMUX0_DAC1                   = 13U,         /**< DAC1 Trigger */
    kTRGMUX0_LPUART0                = 14U,         /**< LPUART0 input */
    kTRGMUX0_LPUART1                = 15U,         /**< LPUART1 input */
    kTRGMUX0_LPUART2                = 16U,         /**< LPUART2 input */
    kTRGMUX0_LPUART3                = 17U,         /**< LPUART3 input */
    kTRGMUX0_LPI2C0                 = 18U,         /**< LPI2C0 Host request */
    kTRGMUX0_LPI2C1                 = 19U,         /**< LPI2C1 Host request */
    kTRGMUX0_LPI2C2                 = 20U,         /**< LPI2C2 Host request */
    kTRGMUX0_LPI2C3                 = 21U,         /**< LPI2C3 Host request */
    kTRGMUX0_LPSPI0                 = 22U,         /**< LPSPI0 Host request */
    kTRGMUX0_LPSPI1                 = 23U,         /**< LPSPI1 Host request */
    kTRGMUX0_FLEXIO0                = 24U,         /**< FlexIO0 trigger 0-3 */
} trgmux0_device_t;
#endif /* TRGMUX0_DEVICE_T_ */

#if !defined(TRGMUX1_DEVICE_T_)
#define TRGMUX1_DEVICE_T_
/*!
 * @brief Enumeration for the TRGMUX1 device
 *
 * Defines the enumeration for the TRGMUX1 device collections.
 */
typedef enum _trgmux1_device
{
    kTRGMUX1_DMAMUX1_CH0_3          = 0U,          /**< DMAMUX1 channel 0-3 trigger */
    kTRGMUX1_DMAMUX1_CH4_7          = 1U,          /**< DMAMUX1 channel 4-7 trigger */
    kTRGMUX1_TPM4                   = 2U,          /**< TPM4 channel 0-1 trigger */
    kTRGMUX1_TPM5                   = 3U,          /**< TPM5 channel 0-1 trigger */
    kTRGMUX1_TPM6                   = 4U,          /**< TPM6 channel 0-1 trigger */
    kTRGMUX1_TPM7                   = 5U,          /**< TPM7 channel 0-1 trigger */
    kTRGMUX1_LPUART4                = 6U,          /**< LPUART4 input */
    kTRGMUX1_LPUART5                = 7U,          /**< LPUART5 input */
    kTRGMUX1_LPUART6                = 8U,          /**< LPUART6 input */
    kTRGMUX1_LPUART7                = 9U,          /**< LPUART7 input */
    kTRGMUX1_LPI2C4                 = 10U,         /**< LPI2C4 Host request */
    kTRGMUX1_LPI2C5                 = 11U,         /**< LPI2C5 Host request */
    kTRGMUX1_LPI2C6                 = 12U,         /**< LPI2C6 Host request */
    kTRGMUX1_LPI2C7                 = 13U,         /**< LPI2C7 Host request */
    kTRGMUX1_LPSPI2                 = 14U,         /**< LPSPI2 Host request */
    kTRGMUX1_LPSPI3                 = 15U,         /**< LPSPI3 Host request */
    kTRGMUX1_FLEXIO1                = 16U,         /**< FlexIO1 trigger 0-3 */
    kTRGMUX1_LPIT1                  = 17U,         /**< LPIT1 trigger 0-3 */
} trgmux1_device_t;
#endif /* TRGMUX1_DEVICE_T_ */


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
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX DMAMUX0_A Register..TRGMUX FLEXIO0 Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX DMAMUX0_A Register..TRGMUX FLEXIO0 Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - Trigger MUX Input 0 Source Select */
#define TRGMUX_TRGCFG_SEL0(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL0_SHIFT)) & TRGMUX_TRGCFG_SEL0_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

#define TRGMUX_TRGCFG_SEL1_MASK                  (0x7F00U)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_TRGCFG_SEL1_SHIFT                 (8U)
/*! SEL1 - Trigger MUX Input 1 Source Select */
#define TRGMUX_TRGCFG_SEL1(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL1_SHIFT)) & TRGMUX_TRGCFG_SEL1_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

#define TRGMUX_TRGCFG_SEL2_MASK                  (0x7F0000U)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_TRGCFG_SEL2_SHIFT                 (16U)
/*! SEL2 - Trigger MUX Input 2 Source Select */
#define TRGMUX_TRGCFG_SEL2(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL2_SHIFT)) & TRGMUX_TRGCFG_SEL2_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

#define TRGMUX_TRGCFG_SEL3_MASK                  (0x7F000000U)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */
#define TRGMUX_TRGCFG_SEL3_SHIFT                 (24U)
/*! SEL3 - Trigger MUX Input 3 Source Select */
#define TRGMUX_TRGCFG_SEL3(x)                    (((uint32_t)(((uint32_t)(x)) << TRGMUX_TRGCFG_SEL3_SHIFT)) & TRGMUX_TRGCFG_SEL3_MASK)  /* Merged from fields with different position or width, of widths (6, 7), largest definition used */

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

