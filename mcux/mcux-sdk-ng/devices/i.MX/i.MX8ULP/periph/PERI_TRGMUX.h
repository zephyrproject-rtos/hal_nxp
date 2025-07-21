/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_TRGMUX.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for TRGMUX
 *
 * CMSIS Peripheral Access Layer for TRGMUX
 */

#if !defined(PERI_TRGMUX_H_)
#define PERI_TRGMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
    kTRGMUX0_SourceWUU0             = 1U,          /**< WUU0 input is selected */
    kTRGMUX0_SourceRTC0Alarm        = 2U,          /**< RTC0 Alarm event input is selected */
    kTRGMUX0_SourceRTC0Seconds      = 3U,          /**< RTC0 Seconds input is selected */
    kTRGMUX0_SourceLPTMR0           = 4U,          /**< LPTMR0 input is selected */
    kTRGMUX0_SourceLPTMR1           = 5U,          /**< LPTMR1 input is selected */
    kTRGMUX0_SourceLPIT0Channel0    = 8U,          /**< LPIT0 Channel0 input is selected */
    kTRGMUX0_SourceLPIT0Channel1    = 9U,          /**< LPIT0 Channel1 input is selected */
    kTRGMUX0_SourceLPIT0Channel2    = 10U,         /**< LPIT0 Channel2 input is selected */
    kTRGMUX0_SourceLPIT0Channel3    = 11U,         /**< LPIT0 Channel3 input is selected */
    kTRGMUX0_SourceTPM0Channel0     = 12U,         /**< TPM0 Channel0 input is selected */
    kTRGMUX0_SourceTPM0Channel1     = 13U,         /**< TPM0 Channel1 input is selected */
    kTRGMUX0_SourceTPM0Channel2     = 14U,         /**< TPM0 Channel2 input is selected */
    kTRGMUX0_SourceTPM0Channel3     = 15U,         /**< TPM0 Channel3 input is selected */
    kTRGMUX0_SourceTPM0Channel4     = 16U,         /**< TPM0 Channel4 input is selected */
    kTRGMUX0_SourceTPM0Channel5     = 17U,         /**< TPM0 Channel5 input is selected */
    kTRGMUX0_SourceTPM0Overflow     = 18U,         /**< TPM0 Overflow input is selected */
    kTRGMUX0_SourceTPM1Channel0     = 19U,         /**< TPM1 Channel0 input is selected */
    kTRGMUX0_SourceTPM1Channel1     = 20U,         /**< TPM1 Channel1 input is selected */
    kTRGMUX0_SourceTPM1Overflow     = 25U,         /**< TPM1 Overflow input is selected */
    kTRGMUX0_SourceTPM2Channel0     = 26U,         /**< TPM2 Channel0 input is selected */
    kTRGMUX0_SourceTPM2Channel1     = 27U,         /**< TPM2 Channel1 input is selected */
    kTRGMUX0_SourceTPM2Overflow     = 32U,         /**< TPM2 Overflow input is selected */
    kTRGMUX0_SourceTPM3Channel0     = 33U,         /**< TPM3 Channel0 input is selected */
    kTRGMUX0_SourceTPM3Channel1     = 34U,         /**< TPM3 Channel1 input is selected */
    kTRGMUX0_SourceTPM3Channel2     = 35U,         /**< TPM3 Channel2 input is selected */
    kTRGMUX0_SourceTPM3Channel3     = 36U,         /**< TPM3 Channel3 input is selected */
    kTRGMUX0_SourceTPM3Channel4     = 37U,         /**< TPM3 Channel4 input is selected */
    kTRGMUX0_SourceTPM3Channel5     = 38U,         /**< TPM3 Channel5 input is selected */
    kTRGMUX0_SourceTPM3Overflow     = 39U,         /**< TPM3 Overflow input is selected */
    kTRGMUX0_SourceTPM8Channel0     = 40U,         /**< TPM8 Channel0 input is selected */
    kTRGMUX0_SourceTPM8Channel1     = 41U,         /**< TPM8 Channel1 input is selected */
    kTRGMUX0_SourceTPM8Channel2     = 42U,         /**< TPM8 Channel2 input is selected */
    kTRGMUX0_SourceTPM8Channel3     = 43U,         /**< TPM8 Channel3 input is selected */
    kTRGMUX0_SourceTPM8Channel4     = 44U,         /**< TPM8 Channel4 input is selected */
    kTRGMUX0_SourceTPM8Channel5     = 45U,         /**< TPM8 Channel5 input is selected */
    kTRGMUX0_SourceTPM8Overflow     = 46U,         /**< TPM8 Overflow input is selected */
    kTRGMUX0_SourceFlexIO0Channel0  = 47U,         /**< FlexIO0 Channel0 input is selected */
    kTRGMUX0_SourceFlexIO0Channel1  = 48U,         /**< FlexIO0 Channel1 input is selected */
    kTRGMUX0_SourceFlexIO0Channel2  = 49U,         /**< FlexIO0 Channel2 input is selected */
    kTRGMUX0_SourceFlexIO0Channel3  = 50U,         /**< FlexIO0 Channel3 input is selected */
    kTRGMUX0_SourceFlexIO0Channel4  = 51U,         /**< FlexIO0 Channel4 input is selected */
    kTRGMUX0_SourceFlexIO0Channel5  = 52U,         /**< FlexIO0 Channel5 input is selected */
    kTRGMUX0_SourceFlexIO0Channel6  = 53U,         /**< FlexIO0 Channel6 input is selected */
    kTRGMUX0_SourceFlexIO0Channel7  = 54U,         /**< FlexIO0 Channel7 input is selected */
    kTRGMUX0_SourceLPI2C0MasterStop = 55U,         /**< LPI2C0 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C0SlaveStop  = 56U,         /**< LPI2C0 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C1MasterStop = 57U,         /**< LPI2C1 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C1SlaveStop  = 58U,         /**< LPI2C1 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C2MasterStop = 59U,         /**< LPI2C2 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C2SlaveStop  = 60U,         /**< LPI2C2 Slave Stop input is selected */
    kTRGMUX0_SourceLPI2C3MasterStop = 61U,         /**< LPI2C3 Master Stop input is selected */
    kTRGMUX0_SourceLPI2C3SlaveStop  = 62U,         /**< LPI2C3 Slave Stop input is selected */
    kTRGMUX0_SourceI2S0TxFrameSync  = 63U,         /**< SAI0 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S0RxFrameSync  = 64U,         /**< SAI0 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S1TxFrameSync  = 65U,         /**< SAI1 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S1RxFrameSync  = 66U,         /**< SAI1 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S2TxFrameSync  = 67U,         /**< SAI2 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S2RxFrameSync  = 68U,         /**< SAI2 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S3TxFrameSync  = 69U,         /**< SAI3 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S3RxFrameSync  = 70U,         /**< SAI3 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S6TxFrameSync  = 71U,         /**< SAI6 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S6RxFrameSync  = 72U,         /**< SAI6 RX Frame Sync input is selected */
    kTRGMUX0_SourceI2S7TxFrameSync  = 73U,         /**< SAI7 TX Frame Sync input is selected */
    kTRGMUX0_SourceI2S7RxFrameSync  = 74U,         /**< SAI7 RX Frame Sync input is selected */
    kTRGMUX0_SourceLPSPI0Frame      = 75U,         /**< LPSPI0 Frame input is selected */
    kTRGMUX0_SourceLPSPI0RxData     = 76U,         /**< LPSPI0 RX Data input is selected */
    kTRGMUX0_SourceLPSPI1Frame      = 77U,         /**< LPSPI1 Frame input is selected */
    kTRGMUX0_SourceLPSPI1RxData     = 78U,         /**< LPSPI1 RX Data input is selected */
    kTRGMUX0_SourceLPSPI2Frame      = 79U,         /**< LPSPI2 Frame input is selected */
    kTRGMUX0_SourceLPSPI2RxData     = 80U,         /**< LPSPI2 RX Data input is selected */
    kTRGMUX0_SourceLPSPI3Frame      = 81U,         /**< LPSPI3 Frame input is selected */
    kTRGMUX0_SourceLPSPI3RxData     = 82U,         /**< LPSPI3 RX Data input is selected */
    kTRGMUX0_SourceLPUART0RxData    = 83U,         /**< LPUART0 RX Data input is selected */
    kTRGMUX0_SourceLPUART0TxData    = 84U,         /**< LPUART0 TX Data input is selected */
    kTRGMUX0_SourceLPUART0RxIdle    = 85U,         /**< LPUART0 RX Idle input is selected */
    kTRGMUX0_SourceLPUART1RxData    = 86U,         /**< LPUART1 RX Data input is selected */
    kTRGMUX0_SourceLPUART1TxData    = 87U,         /**< LPUART1 TX Data input is selected */
    kTRGMUX0_SourceLPUART1RxIdle    = 88U,         /**< LPUART1 RX Idle input is selected */
    kTRGMUX0_SourceLPUART2RxData    = 89U,         /**< LPUART2 RX Data input is selected */
    kTRGMUX0_SourceLPUART2TxData    = 90U,         /**< LPUART2 TX Data input is selected */
    kTRGMUX0_SourceLPUART2RxIdle    = 91U,         /**< LPUART2 RX Idle input is selected */
    kTRGMUX0_SourceLPUART3RxData    = 92U,         /**< LPUART3 RX Data input is selected */
    kTRGMUX0_SourceLPUART3TxData    = 93U,         /**< LPUART3 TX Data input is selected */
    kTRGMUX0_SourceLPUART3RxIdle    = 94U,         /**< LPUART3 RX Idle input is selected */
    kTRGMUX0_SourceUSB0StartOfFrame = 95U,         /**< USB0 Start of Frame input is selected */
    kTRGMUX0_SourceUSB1StartOfFrame = 96U,         /**< USB1 Start of Frame input is selected */
    kTRGMUX0_SourceGPIOAPinEvent2   = 97U,         /**< GPIO A Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIOAPinEvent3   = 98U,         /**< GPIO A Pin event trigger 3 is selected */
    kTRGMUX0_SourceGPIOBPinEvent2   = 99U,         /**< GPIO B Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIOBPinEvent3   = 100U,        /**< GPIO B Pin event trigger 3 is selected */
    kTRGMUX0_SourceGPIOCPinEvent2   = 101U,        /**< GPIO C Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIOCPinEvent3   = 102U,        /**< GPIO C Pin event trigger 3 is selected */
    kTRGMUX0_SourceGPIODPinEvent2   = 103U,        /**< GPIO D Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIODPinEvent3   = 104U,        /**< GPIO D Pin event trigger 3 is selected */
    kTRGMUX0_SourceGPIOEPinEvent2   = 105U,        /**< GPIO E Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIOEPinEvent3   = 106U,        /**< GPIO E Pin event trigger 3 is selected */
    kTRGMUX0_SourceGPIOFPinEvent2   = 107U,        /**< GPIO F Pin event trigger 2 is selected */
    kTRGMUX0_SourceGPIOFPinEvent3   = 108U,        /**< GPIO F Pin event trigger 3 is selected */
    kTRGMUX0_SourceADC0Output0      = 109U,        /**< ADC0 Output0 input is selected */
    kTRGMUX0_SourceADC0Output1      = 110U,        /**< ADC0 Output1 input is selected */
    kTRGMUX0_SourceADC0Output2      = 111U,        /**< ADC0 Output2 input is selected */
    kTRGMUX0_SourceADC0Output3      = 112U,        /**< ADC0 Output3 input is selected */
    kTRGMUX0_SourceADC1Output0      = 113U,        /**< ADC1 Output0 input is selected */
    kTRGMUX0_SourceADC1Output1      = 114U,        /**< ADC1 Output1 input is selected */
    kTRGMUX0_SourceADC1Output2      = 115U,        /**< ADC1 Output2 input is selected */
    kTRGMUX0_SourceADC1Output3      = 116U,        /**< ADC1 Output3 input is selected */
    kTRGMUX0_SourceCMP0Output       = 117U,        /**< CMP0 Output input is selected */
    kTRGMUX0_SourceCMP1Output       = 118U,        /**< CMP1 Output input is selected */
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
    kTRGMUX1_SourceWUU1             = 1U,          /**< WUU1 input is selected */
    kTRGMUX1_SourceRTC0Alarm        = 2U,          /**< RTC0 Alarm event input is selected */
    kTRGMUX1_SourceRTC0Seconds      = 3U,          /**< RTC0 Seconds input is selected */
    kTRGMUX1_SourceLPIT1Channel0    = 4U,          /**< LPIT1 Channel0 input is selected */
    kTRGMUX1_SourceLPIT1Channel1    = 5U,          /**< LPIT1 Channel1 input is selected */
    kTRGMUX1_SourceLPIT1Channel2    = 6U,          /**< LPIT1 Channel2 input is selected */
    kTRGMUX1_SourceLPIT1Channel3    = 7U,          /**< LPIT1 Channel3 input is selected */
    kTRGMUX1_SourceTPM4Channel0     = 8U,          /**< TPM4 Channel0 input is selected */
    kTRGMUX1_SourceTPM4Channel1     = 9U,          /**< TPM4 Channel1 input is selected */
    kTRGMUX1_SourceTPM4Channel2     = 10U,         /**< TPM4 Channel2 input is selected */
    kTRGMUX1_SourceTPM4Channel3     = 11U,         /**< TPM4 Channel3 input is selected */
    kTRGMUX1_SourceTPM4Channel4     = 12U,         /**< TPM4 Channel4 input is selected */
    kTRGMUX1_SourceTPM4Channel5     = 13U,         /**< TPM4 Channel5 input is selected */
    kTRGMUX1_SourceTPM4Overflow     = 14U,         /**< TPM4 Overflow input is selected */
    kTRGMUX1_SourceTPM5Channel0     = 15U,         /**< TPM5 Channel0 input is selected */
    kTRGMUX1_SourceTPM5Channel1     = 16U,         /**< TPM5 Channel1 input is selected */
    kTRGMUX1_SourceTPM5Overflow     = 21U,         /**< TPM5 Overflow input is selected */
    kTRGMUX1_SourceTPM6Channel0     = 22U,         /**< TPM6 Channel0 input is selected */
    kTRGMUX1_SourceTPM6Channel1     = 23U,         /**< TPM6 Channel1 input is selected */
    kTRGMUX1_SourceTPM6Overflow     = 28U,         /**< TPM6 Overflow input is selected */
    kTRGMUX1_SourceTPM7Channel0     = 29U,         /**< TPM7 Channel0 input is selected */
    kTRGMUX1_SourceTPM7Channel1     = 30U,         /**< TPM7 Channel1 input is selected */
    kTRGMUX1_SourceTPM7Channel2     = 31U,         /**< TPM7 Channel2 input is selected */
    kTRGMUX1_SourceTPM7Channel3     = 32U,         /**< TPM7 Channel3 input is selected */
    kTRGMUX1_SourceTPM7Channel4     = 33U,         /**< TPM7 Channel4 input is selected */
    kTRGMUX1_SourceTPM7Channel5     = 34U,         /**< TPM7 Channel5 input is selected */
    kTRGMUX1_SourceTPM7Overflow     = 35U,         /**< TPM7 Overflow input is selected */
    kTRGMUX1_SourceTPM8Channel0     = 36U,         /**< TPM8 Channel0 input is selected */
    kTRGMUX1_SourceTPM8Channel1     = 37U,         /**< TPM8 Channel1 input is selected */
    kTRGMUX1_SourceTPM8Channel2     = 38U,         /**< TPM8 Channel2 input is selected */
    kTRGMUX1_SourceTPM8Channel3     = 39U,         /**< TPM8 Channel3 input is selected */
    kTRGMUX1_SourceTPM8Channel4     = 40U,         /**< TPM8 Channel4 input is selected */
    kTRGMUX1_SourceTPM8Channel5     = 41U,         /**< TPM8 Channel5 input is selected */
    kTRGMUX1_SourceTPM8Overflow     = 42U,         /**< TPM8 Overflow input is selected */
    kTRGMUX1_SourceFlexIO1Channel0  = 43U,         /**< FlexIO1 Channel0 input is selected */
    kTRGMUX1_SourceFlexIO1Channel1  = 44U,         /**< FlexIO1 Channel1 input is selected */
    kTRGMUX1_SourceFlexIO1Channel2  = 45U,         /**< FlexIO1 Channel2 input is selected */
    kTRGMUX1_SourceFlexIO1Channel3  = 46U,         /**< FlexIO1 Channel3 input is selected */
    kTRGMUX1_SourceFlexIO1Channel4  = 47U,         /**< FlexIO1 Channel4 input is selected */
    kTRGMUX1_SourceFlexIO1Channel5  = 48U,         /**< FlexIO1 Channel5 input is selected */
    kTRGMUX1_SourceFlexIO1Channel6  = 49U,         /**< FlexIO1 Channel6 input is selected */
    kTRGMUX1_SourceFlexIO1Channel7  = 50U,         /**< FlexIO1 Channel7 input is selected */
    kTRGMUX1_SourceLPI2C4MasterStop = 51U,         /**< LPI2C4 Master Stop input is selected */
    kTRGMUX1_SourceLPI2C4SlaveStop  = 52U,         /**< LPI2C4 Slave Stop input is selected */
    kTRGMUX1_SourceLPI2C5MasterStop = 53U,         /**< LPI2C5 Master Stop input is selected */
    kTRGMUX1_SourceLPI2C5SlaveStop  = 54U,         /**< LPI2C5 Slave Stop input is selected */
    kTRGMUX1_SourceLPI2C6MasterStop = 55U,         /**< LPI2C6 Master Stop input is selected */
    kTRGMUX1_SourceLPI2C6SlaveStop  = 56U,         /**< LPI2C6 Slave Stop input is selected */
    kTRGMUX1_SourceLPI2C7MasterStop = 57U,         /**< LPI2C7 Master Stop input is selected */
    kTRGMUX1_SourceLPI2C7SlaveStop  = 58U,         /**< LPI2C7 Slave Stop input is selected */
    kTRGMUX1_SourceI2S4TxFrameSync  = 59U,         /**< SAI4 TX Frame Sync input is selected */
    kTRGMUX1_SourceI2S4RxFrameSync  = 60U,         /**< SAI4 RX Frame Sync input is selected */
    kTRGMUX1_SourceI2S5TxFrameSync  = 61U,         /**< SAI5 TX Frame Sync input is selected */
    kTRGMUX1_SourceI2S5RxFrameSync  = 62U,         /**< SAI5 RX Frame Sync input is selected */
    kTRGMUX1_SourceI2S6TxFrameSync  = 63U,         /**< SAI6 TX Frame Sync input is selected */
    kTRGMUX1_SourceI2S6RxFrameSync  = 64U,         /**< SAI6 RX Frame Sync input is selected */
    kTRGMUX1_SourceI2S7TxFrameSync  = 65U,         /**< SAI7 TX Frame Sync input is selected */
    kTRGMUX1_SourceI2S7RxFrameSync  = 66U,         /**< SAI7 RX Frame Sync input is selected */
    kTRGMUX1_SourceLPSPI4Frame      = 67U,         /**< LPSPI4 Frame input is selected */
    kTRGMUX1_SourceLPSPI4RxData     = 68U,         /**< LPSPI4 RX Data input is selected */
    kTRGMUX1_SourceLPSPI5Frame      = 69U,         /**< LPSPI5 Frame input is selected */
    kTRGMUX1_SourceLPSPI5RxData     = 70U,         /**< LPSPI5 RX Data input is selected */
    kTRGMUX1_SourceLPUART4RxData    = 71U,         /**< LPUART4 RX Data input is selected */
    kTRGMUX1_SourceLPUART4TxData    = 72U,         /**< LPUART4 TX Data input is selected */
    kTRGMUX1_SourceLPUART4RxIdle    = 73U,         /**< LPUART4 RX Idle input is selected */
    kTRGMUX1_SourceLPUART5RxData    = 74U,         /**< LPUART5 RX Data input is selected */
    kTRGMUX1_SourceLPUART5TxData    = 75U,         /**< LPUART5 TX Data input is selected */
    kTRGMUX1_SourceLPUART5RxIdle    = 76U,         /**< LPUART5 RX Idle input is selected */
    kTRGMUX1_SourceLPUART6RxData    = 77U,         /**< LPUART6 RX Data input is selected */
    kTRGMUX1_SourceLPUART6TxData    = 78U,         /**< LPUART6 TX Data input is selected */
    kTRGMUX1_SourceLPUART6RxIdle    = 79U,         /**< LPUART6 RX Idle input is selected */
    kTRGMUX1_SourceLPUART7RxData    = 80U,         /**< LPUART7 RX Data input is selected */
    kTRGMUX1_SourceLPUART7TxData    = 81U,         /**< LPUART7 TX Data input is selected */
    kTRGMUX1_SourceLPUART7RxIdle    = 82U,         /**< LPUART7 RX Idle input is selected */
    kTRGMUX1_SourceUSB0StartOfFrame = 83U,         /**< USB0 Start of Frame input is selected */
    kTRGMUX1_SourceUSB1StartOfFrame = 84U,         /**< USB1 Start of Frame input is selected */
    kTRGMUX1_SourceGPIOAPinEvent0   = 85U,         /**< GPIO A Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIOAPinEvent1   = 86U,         /**< GPIO A Pin event trigger 1 is selected */
    kTRGMUX1_SourceGPIOBPinEvent0   = 87U,         /**< GPIO B Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIOBPinEvent1   = 88U,         /**< GPIO B Pin event trigger 1 is selected */
    kTRGMUX1_SourceGPIOCPinEvent0   = 89U,         /**< GPIO C Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIOCPinEvent1   = 90U,         /**< GPIO C Pin event trigger 1 is selected */
    kTRGMUX1_SourceGPIODPinEvent0   = 91U,         /**< GPIO D Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIODPinEvent1   = 92U,         /**< GPIO D Pin event trigger 1 is selected */
    kTRGMUX1_SourceGPIOEPinEvent0   = 93U,         /**< GPIO E Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIOEPinEvent1   = 94U,         /**< GPIO E Pin event trigger 1 is selected */
    kTRGMUX1_SourceGPIOFPinEvent0   = 95U,         /**< GPIO F Pin event trigger 0 is selected */
    kTRGMUX1_SourceGPIOFPinEvent1   = 96U,         /**< GPIO F Pin event trigger 1 is selected */
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
    kTRGMUX0_LPIT0                  = 0U,          /**< LPIT0 trigger 0-3 */
    kTRGMUX0_TPM0                   = 1U,          /**< TPM0 channel 0-1 trigger */
    kTRGMUX0_TPM1                   = 2U,          /**< TPM1 channel 0-1 trigger */
    kTRGMUX0_TPM2                   = 3U,          /**< TPM2 channel 0-1 trigger */
    kTRGMUX0_TPM3                   = 4U,          /**< TPM3 channel 0-1 trigger */
    kTRGMUX0_TPM8                   = 5U,          /**< TPM8 channel 0-1 trigger */
    kTRGMUX0_FLEXIO0                = 6U,          /**< FlexIO0 trigger 0-3 */
    kTRGMUX0_LPI2C0                 = 7U,          /**< LPI2C0 Host request */
    kTRGMUX0_LPI2C1                 = 8U,          /**< LPI2C1 Host request */
    kTRGMUX0_LPI2C2                 = 9U,          /**< LPI2C2 Host request */
    kTRGMUX0_LPI2C3                 = 10U,         /**< LPI2C3 Host request */
    kTRGMUX0_LPSPI0                 = 11U,         /**< LPSPI0 Host request */
    kTRGMUX0_LPSPI1                 = 12U,         /**< LPSPI1 Host request */
    kTRGMUX0_LPSPI2                 = 13U,         /**< LPSPI2 Host request */
    kTRGMUX0_LPSPI3                 = 14U,         /**< LPSPI3 Host request */
    kTRGMUX0_LPUART0                = 15U,         /**< LPUART0 input */
    kTRGMUX0_LPUART1                = 16U,         /**< LPUART1 input */
    kTRGMUX0_LPUART2                = 17U,         /**< LPUART2 input */
    kTRGMUX0_LPUART3                = 18U,         /**< LPUART3 input */
    kTRGMUX0_ADC0                   = 19U,         /**< ADC0 trigger */
    kTRGMUX0_ADC1                   = 20U,         /**< ADC1 trigger */
    kTRGMUX0_CMP0                   = 21U,         /**< CMP0 Window trigger */
    kTRGMUX0_CMP1                   = 22U,         /**< CMP1 Window trigger */
    kTRGMUX0_DAC0                   = 23U,         /**< DAC0 Trigger */
    kTRGMUX0_DAC1                   = 24U,         /**< DAC1 Trigger */
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
    kTRGMUX1_LPIT1                  = 0U,          /**< LPIT1 trigger 0-3 */
    kTRGMUX1_TPM4                   = 1U,          /**< TPM4 channel 0-1 trigger */
    kTRGMUX1_TPM5                   = 2U,          /**< TPM5 channel 0-1 trigger */
    kTRGMUX1_TPM6                   = 3U,          /**< TPM6 channel 0-1 trigger */
    kTRGMUX1_TPM7                   = 4U,          /**< TPM7 channel 0-1 trigger */
    kTRGMUX1_TPM8                   = 5U,          /**< TPM8 channel 0-1 trigger */
    kTRGMUX1_FLEXIO1                = 6U,          /**< FlexIO1 trigger 0-3 */
    kTRGMUX1_LPI2C4                 = 7U,          /**< LPI2C4 Host request */
    kTRGMUX1_LPI2C5                 = 8U,          /**< LPI2C5 Host request */
    kTRGMUX1_LPI2C6                 = 9U,          /**< LPI2C6 Host request */
    kTRGMUX1_LPI2C7                 = 10U,         /**< LPI2C7 Host request */
    kTRGMUX1_LPSPI4                 = 11U,         /**< LPSPI4 Host request */
    kTRGMUX1_LPSPI5                 = 12U,         /**< LPSPI5 Host request */
    kTRGMUX1_LPUART4                = 13U,         /**< LPUART4 input */
    kTRGMUX1_LPUART5                = 14U,         /**< LPUART5 input */
    kTRGMUX1_LPUART6                = 15U,         /**< LPUART6 input */
    kTRGMUX1_LPUART7                = 16U,         /**< LPUART7 input */
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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
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
  __IO uint32_t TRGCFG[TRGMUX_TRGCFG_COUNT];       /**< TRGMUX LPIT0 Register..TRGMUX DAC1 Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} TRGMUX_Type;

/* ----------------------------------------------------------------------------
   -- TRGMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup TRGMUX_Register_Masks TRGMUX Register Masks
 * @{
 */

/*! @name TRGCFG - TRGMUX LPIT0 Register..TRGMUX DAC1 Register */
/*! @{ */

#define TRGMUX_TRGCFG_SEL0_MASK                  (0x7FU)
#define TRGMUX_TRGCFG_SEL0_SHIFT                 (0U)
/*! SEL0 - TRGMUX Source Select 1 */
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_TRGMUX_H_ */

