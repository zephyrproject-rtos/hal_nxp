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
**         CMSIS Peripheral Access Layer for DMA
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
 * @file PERI_DMA.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

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
#if !defined(DMA0_REQUEST_SOURCE_T_)
#define DMA0_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma0_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA0 hardware request
 *
 * Defines the enumeration for the DMA0 hardware request collections.
 */
typedef enum _dma0_request_source
{
    kDmaRequestMux0Disable          = 0|0x100U,    /**< Channel disabled */
    kDmaRequestMux0WUU0             = 1|0x100U,    /**< Wake up event */
    kDmaRequestMux0FlexSPI0Rx       = 2|0x100U,    /**< FlexSPI0 Receive request */
    kDmaRequestMux0FlexSPI0Tx       = 3|0x100U,    /**< FlexSPI0 Transmit request */
    kDmaRequestMux0FlexSPI1Rx       = 4|0x100U,    /**< FlexSPI1 Receive request */
    kDmaRequestMux0FlexSPI1Tx       = 5|0x100U,    /**< FlexSPI1 Transmit request */
    kDmaRequestMux0FlexSPI2Rx       = 6|0x100U,    /**< FlexSPI2 Receive request */
    kDmaRequestMux0FlexSPI2Tx       = 7|0x100U,    /**< FlexSPI2 Transmit request */
    kDmaRequestMux0SNT              = 8|0x100U,    /**< SNT Data request */
    kDmaRequestMux0LPTMR0           = 9|0x100U,    /**< Low Power Timer 0 */
    kDmaRequestMux0LPTMR1           = 10|0x100U,   /**< Low Power Timer 1 */
    kDmaRequestMux0TPM0Channel0     = 13|0x100U,   /**< TPM0 Channel 0 */
    kDmaRequestMux0TPM0Channel1     = 14|0x100U,   /**< TPM0 Channel 1 */
    kDmaRequestMux0TPM0Channel2     = 15|0x100U,   /**< TPM0 Channel 2 */
    kDmaRequestMux0TPM0Channel3     = 16|0x100U,   /**< TPM0 Channel 3 */
    kDmaRequestMux0TPM0Channel4     = 17|0x100U,   /**< TPM0 Channel 4 */
    kDmaRequestMux0TPM0Channel5     = 18|0x100U,   /**< TPM0 Channel 5 */
    kDmaRequestMux0TPM0Overflow     = 19|0x100U,   /**< TPM0 Overflow */
    kDmaRequestMux0TPM1Channel0     = 20|0x100U,   /**< TPM1 Channel 0 */
    kDmaRequestMux0TPM1Channel1     = 21|0x100U,   /**< TPM1 Channel 1 */
    kDmaRequestMux0TPM1Overflow     = 22|0x100U,   /**< TPM1 Overflow */
    kDmaRequestMux0TPM2Channel0     = 23|0x100U,   /**< TPM2 Channel 0 */
    kDmaRequestMux0TPM2Channel1     = 24|0x100U,   /**< TPM2 Channel 1 */
    kDmaRequestMux0TPM2Overflow     = 25|0x100U,   /**< TPM2 Overflow */
    kDmaRequestMux0TPM3Channel0     = 26|0x100U,   /**< TPM3 Channel 0 */
    kDmaRequestMux0TPM3Channel1     = 27|0x100U,   /**< TPM3 Channel 1 */
    kDmaRequestMux0TPM3Channel2     = 28|0x100U,   /**< TPM3 Channel 2 */
    kDmaRequestMux0TPM3Channel3     = 29|0x100U,   /**< TPM3 Channel 3 */
    kDmaRequestMux0TPM3Channel4     = 30|0x100U,   /**< TPM3 Channel 4 */
    kDmaRequestMux0TPM3Channel5     = 31|0x100U,   /**< TPM3 Channel 5 */
    kDmaRequestMux0TPM3Overflow     = 32|0x100U,   /**< TPM3 Overflow */
    kDmaRequestMux0CAN              = 40|0x100U,   /**< CAN DMA request */
    kDmaRequestMux0FlexIO0Shifter0  = 41|0x100U,   /**< FlexIO0 Shifter 0 */
    kDmaRequestMux0FlexIO0Shifter1  = 42|0x100U,   /**< FlexIO0 Shifter 1 */
    kDmaRequestMux0FlexIO0Shifter2  = 43|0x100U,   /**< FlexIO0 Shifter 2 */
    kDmaRequestMux0FlexIO0Shifter3  = 44|0x100U,   /**< FlexIO0 Shifter 3 */
    kDmaRequestMux0FlexIO0Shifter4  = 45|0x100U,   /**< FlexIO0 Shifter 4 */
    kDmaRequestMux0FlexIO0Shifter5  = 46|0x100U,   /**< FlexIO0 Shifter 5 */
    kDmaRequestMux0FlexIO0Shifter6  = 47|0x100U,   /**< FlexIO0 Shifter 6 */
    kDmaRequestMux0FlexIO0Shifter7  = 48|0x100U,   /**< FlexIO0 Shifter 7 */
    kDmaRequestMux0LPI2C0Rx         = 49|0x100U,   /**< LPI2C0 Master/Slave Receive */
    kDmaRequestMux0LPI2C0Tx         = 50|0x100U,   /**< LPI2C0 Master/Slave Transmit */
    kDmaRequestMux0LPI2C1Rx         = 51|0x100U,   /**< LPI2C1 Master/Slave Receive */
    kDmaRequestMux0LPI2C1Tx         = 52|0x100U,   /**< LPI2C1 Master/Slave Transmit */
    kDmaRequestMux0LPI2C2Rx         = 53|0x100U,   /**< LPI2C2 Master/Slave Receive */
    kDmaRequestMux0LPI2C2Tx         = 54|0x100U,   /**< LPI2C2 Master/Slave Transmit */
    kDmaRequestMux0LPI2C3Rx         = 55|0x100U,   /**< LPI2C3 Master/Slave Receive */
    kDmaRequestMux0LPI2C3Tx         = 56|0x100U,   /**< LPI2C3 Master/Slave Transmit */
    kDmaRequestMux0I3C0Rx           = 57|0x100U,   /**< I3C0 Master/Slave Receive */
    kDmaRequestMux0I3C0Tx           = 58|0x100U,   /**< I3C0 Master/Slave Transmit */
    kDmaRequestMux0I3C1Rx           = 59|0x100U,   /**< I3C1 Master/Slave Receive */
    kDmaRequestMux0I3C1Tx           = 60|0x100U,   /**< I3C1 Master/Slave Receive */
    kDmaRequestMux0LPSPI0Rx         = 61|0x100U,   /**< LPSPI0 Receive */
    kDmaRequestMux0LPSPI0Tx         = 62|0x100U,   /**< LPSPI0 Transmit */
    kDmaRequestMux0LPSPI1Rx         = 63|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMux0LPSPI1Tx         = 64|0x100U,   /**< LPSPI1 Transmit */
    kDmaRequestMux0LPSPI2Rx         = 65|0x100U,   /**< LPSPI2 Receive */
    kDmaRequestMux0LPSPI2Tx         = 66|0x100U,   /**< LPSPI2 Transmit */
    kDmaRequestMux0LPSPI3Rx         = 67|0x100U,   /**< LPSPI3 Receive */
    kDmaRequestMux0LPSPI3Tx         = 68|0x100U,   /**< LPSPI3 Transmit */
    kDmaRequestMux0LPUART0Rx        = 69|0x100U,   /**< LPUART0 Receive */
    kDmaRequestMux0LPUART0Tx        = 70|0x100U,   /**< LPUART0 Transmit */
    kDmaRequestMux0LPUART1Rx        = 71|0x100U,   /**< LPUART1 Receive */
    kDmaRequestMux0LPUART1Tx        = 72|0x100U,   /**< LPUART1 Transmit */
    kDmaRequestMux0LPUART2Rx        = 73|0x100U,   /**< LPUART2 Receive */
    kDmaRequestMux0LPUART2Tx        = 74|0x100U,   /**< LPUART2 Transmit */
    kDmaRequestMux0LPUART3Rx        = 75|0x100U,   /**< LPUART3 Receive */
    kDmaRequestMux0LPUART3Tx        = 76|0x100U,   /**< LPUART3 Transmit */
    kDmaRequestMux0SAI0Rx           = 77|0x100U,   /**< SAI0 Receive */
    kDmaRequestMux0SAI0Tx           = 78|0x100U,   /**< SAI0 Transmit */
    kDmaRequestMux0SAI1Rx           = 79|0x100U,   /**< SAI1 Receive */
    kDmaRequestMux0SAI1Tx           = 80|0x100U,   /**< SAI1 Transmit */
    kDmaRequestMux0SAI2Rx           = 81|0x100U,   /**< SAI2 Receive */
    kDmaRequestMux0SAI2Tx           = 82|0x100U,   /**< SAI2 Transmit */
    kDmaRequestMux0SAI3Rx           = 83|0x100U,   /**< SAI3 Receive */
    kDmaRequestMux0SAI3Tx           = 84|0x100U,   /**< SAI3 Transmit */
    kDmaRequestMux0MICFIL           = 91|0x100U,   /**< MICFIL FIFO Request */
    kDmaRequestMux0GPIOAEvent2      = 92|0x100U,   /**< GPIOA Pin event request 2 */
    kDmaRequestMux0GPIOAEvent3      = 93|0x100U,   /**< GPIOA Pin event request 3 */
    kDmaRequestMux0GPIOBEvent2      = 94|0x100U,   /**< GPIOB Pin event request 2 */
    kDmaRequestMux0GPIOBEvent3      = 95|0x100U,   /**< GPIOB Pin event request 3 */
    kDmaRequestMux0GPIOCEvent2      = 96|0x100U,   /**< GPIOC Pin event request 2 */
    kDmaRequestMux0GPIOCEvent3      = 97|0x100U,   /**< GPIOC Pin event request 3 */
    kDmaRequestMux0ADC0             = 104|0x100U,  /**< ADC0 Conversion Complete */
    kDmaRequestMux0ADC1             = 105|0x100U,  /**< ADC1 Conversion Complete */
    kDmaRequestMux0CMP0             = 106|0x100U,  /**< CMP0 Comparison Event */
    kDmaRequestMux0CMP1             = 107|0x100U,  /**< CMP1 Comparison Event */
    kDmaRequestMux0DAC0             = 108|0x100U,  /**< DAC0 Request */
    kDmaRequestMux0DAC1             = 109|0x100U,  /**< DAC1 Request */
} dma0_request_source_t;

/* @} */
#endif /* DMA0_REQUEST_SOURCE_T_ */

#if !defined(DMA1_REQUEST_SOURCE_T_)
#define DMA1_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma1_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA1 hardware request
 *
 * Defines the enumeration for the DMA1 hardware request collections.
 */
typedef enum _dma1_request_source
{
    kDmaRequestMux1Disable          = 0|0x200U,    /**< Channel disabled */
    kDmaRequestMux1WUU1             = 1|0x200U,    /**< Wake up event */
    kDmaRequestMux1FlexSPI0Rx       = 2|0x200U,    /**< FlexSPI0 Receive request */
    kDmaRequestMux1FlexSPI0Tx       = 3|0x200U,    /**< FlexSPI0 Transmit request */
    kDmaRequestMux1FlexSPI1Rx       = 4|0x200U,    /**< FlexSPI1 Receive request */
    kDmaRequestMux1FlexSPI1Tx       = 5|0x200U,    /**< FlexSPI1 Transmit request */
    kDmaRequestMux1FlexSPI2Rx       = 6|0x200U,    /**< FlexSPI2 Receive request */
    kDmaRequestMux1FlexSPI2Tx       = 7|0x200U,    /**< FlexSPI2 Transmit request */
    kDmaRequestMux1SNT              = 8|0x200U,    /**< SNT Data request */
    kDmaRequestMux1TPM4Channel0     = 9|0x200U,    /**< TPM4 Channel 0 */
    kDmaRequestMux1TPM4Channel1     = 10|0x200U,   /**< TPM4 Channel 1 */
    kDmaRequestMux1TPM4Channel2     = 11|0x200U,   /**< TPM4 Channel 2 */
    kDmaRequestMux1TPM4Channel3     = 12|0x200U,   /**< TPM4 Channel 3 */
    kDmaRequestMux1TPM4Channel4     = 13|0x200U,   /**< TPM4 Channel 4 */
    kDmaRequestMux1TPM4Channel5     = 14|0x200U,   /**< TPM4 Channel 5 */
    kDmaRequestMux1TPM4Overflow     = 15|0x200U,   /**< TPM4 Overflow */
    kDmaRequestMux1TPM5Channel0     = 16|0x200U,   /**< TPM5 Channel 0 */
    kDmaRequestMux1TPM5Channel1     = 17|0x200U,   /**< TPM5 Channel 1 */
    kDmaRequestMux1TPM5Overflow     = 18|0x200U,   /**< TPM5 Overflow */
    kDmaRequestMux1TPM6Channel0     = 19|0x200U,   /**< TPM6 Channel 0 */
    kDmaRequestMux1TPM6Channel1     = 20|0x200U,   /**< TPM6 Channel 1 */
    kDmaRequestMux1TPM6Overflow     = 21|0x200U,   /**< TPM6 Overflow */
    kDmaRequestMux1TPM7Channel0     = 22|0x200U,   /**< TPM7 Channel 0 */
    kDmaRequestMux1TPM7Channel1     = 23|0x200U,   /**< TPM7 Channel 1 */
    kDmaRequestMux1TPM7Channel2     = 24|0x200U,   /**< TPM7 Channel 2 */
    kDmaRequestMux1TPM7Channel3     = 25|0x200U,   /**< TPM7 Channel 3 */
    kDmaRequestMux1TPM7Channel4     = 26|0x200U,   /**< TPM7 Channel 4 */
    kDmaRequestMux1TPM7Channel5     = 27|0x200U,   /**< TPM7 Channel 5 */
    kDmaRequestMux1TPM7Overflow     = 28|0x200U,   /**< TPM7 Overflow */
    kDmaRequestMux1FlexIO1Shifter0  = 37|0x200U,   /**< FlexIO1 Shifter 0 */
    kDmaRequestMux1FlexIO1Shifter1  = 38|0x200U,   /**< FlexIO1 Shifter 1 */
    kDmaRequestMux1FlexIO1Shifter2  = 39|0x200U,   /**< FlexIO1 Shifter 2 */
    kDmaRequestMux1FlexIO1Shifter3  = 40|0x200U,   /**< FlexIO1 Shifter 3 */
    kDmaRequestMux1FlexIO1Shifter4  = 41|0x200U,   /**< FlexIO1 Shifter 4 */
    kDmaRequestMux1FlexIO1Shifter5  = 42|0x200U,   /**< FlexIO1 Shifter 5 */
    kDmaRequestMux1FlexIO1Shifter6  = 43|0x200U,   /**< FlexIO1 Shifter 6 */
    kDmaRequestMux1FlexIO1Shifter7  = 44|0x200U,   /**< FlexIO1 Shifter 7 */
    kDmaRequestMux1LPI2C4Rx         = 45|0x200U,   /**< LPI2C4 Master/Slave Receive */
    kDmaRequestMux1LPI2C4Tx         = 46|0x200U,   /**< LPI2C4 Master/Slave Transmit */
    kDmaRequestMux1LPI2C5Rx         = 47|0x200U,   /**< LPI2C5 Master/Slave Receive */
    kDmaRequestMux1LPI2C5Tx         = 48|0x200U,   /**< LPI2C5 Master/Slave Transmit */
    kDmaRequestMux1LPI2C6Rx         = 49|0x200U,   /**< LPI2C6 Master/Slave Receive */
    kDmaRequestMux1LPI2C6Tx         = 50|0x200U,   /**< LPI2C6 Master/Slave Transmit */
    kDmaRequestMux1LPI2C7Rx         = 51|0x200U,   /**< LPI2C7 Master/Slave Receive */
    kDmaRequestMux1LPI2C7Tx         = 52|0x200U,   /**< LPI2C7 Master/Slave Transmit */
    kDmaRequestMux1I3C2Rx           = 53|0x200U,   /**< I3C2 Master/Slave Receive */
    kDmaRequestMux1I3C2Tx           = 54|0x200U,   /**< I3C2 Master/Slave Transmit */
    kDmaRequestMux1LPUART4Rx        = 55|0x200U,   /**< LPUART4 Receive */
    kDmaRequestMux1LPUART4Tx        = 56|0x200U,   /**< LPUART4 Transmit */
    kDmaRequestMux1LPUART5Rx        = 57|0x200U,   /**< LPUART5 Receive */
    kDmaRequestMux1LPUART5Tx        = 58|0x200U,   /**< LPUART5 Transmit */
    kDmaRequestMux1LPUART6Rx        = 59|0x200U,   /**< LPUART6 Receive */
    kDmaRequestMux1LPUART6Tx        = 60|0x200U,   /**< LPUART6 Transmit */
    kDmaRequestMux1LPUART7Rx        = 61|0x200U,   /**< LPUART7 Receive */
    kDmaRequestMux1LPUART7Tx        = 62|0x200U,   /**< LPUART7 Transmit */
    kDmaRequestMux1LPSPI4Rx         = 63|0x200U,   /**< LPSPI4 Receive */
    kDmaRequestMux1LPSPI4Tx         = 64|0x200U,   /**< LPSPI4 Transmit */
    kDmaRequestMux1LPSPI5Rx         = 65|0x200U,   /**< LPSPI5 Receive */
    kDmaRequestMux1LPSPI5Tx         = 66|0x200U,   /**< LPSPI5 Transmit */
    kDmaRequestMux1SAI4Rx           = 67|0x200U,   /**< SAI4 Receive */
    kDmaRequestMux1SAI4Tx           = 68|0x200U,   /**< SAI4 Transmit */
    kDmaRequestMux1SAI5Rx           = 69|0x200U,   /**< SAI5 Receive */
    kDmaRequestMux1SAI5Tx           = 70|0x200U,   /**< SAI5 Transmit */
    kDmaRequestMux1GPIOEEvent0      = 85|0x200U,   /**< GPIOE Pin event request 0 */
    kDmaRequestMux1GPIOEEvent1      = 86|0x200U,   /**< GPIOE Pin event request 1 */
    kDmaRequestMux1GPIOFEvent0      = 87|0x200U,   /**< GPIOF Pin event request 0 */
    kDmaRequestMux1GPIOFEvent1      = 88|0x200U,   /**< GPIOF Pin event request 1 */
    kDmaRequestMux1ENETTimer0       = 89|0x200U,   /**< ENET Timer 0 */
    kDmaRequestMux1ENETTimer1       = 90|0x200U,   /**< ENET Timer 1 */
    kDmaRequestMux1ENETTimer2       = 91|0x200U,   /**< ENET Timer 2 */
    kDmaRequestMux1ENETTimer3       = 92|0x200U,   /**< ENET Timer 3 */
} dma1_request_source_t;

/* @} */
#endif /* DMA1_REQUEST_SOURCE_T_ */

#if !defined(DMA2_REQUEST_SOURCE_T_)
#define DMA2_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma2_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA2 hardware request
 *
 * Defines the enumeration for the DMA2 hardware request collections.
 */
typedef enum _dma2_request_source
{
    kDmaRequestMux2Disable          = 0|0x300U,    /**< Channel disabled */
    kDmaRequestMux2TPM8Channel0     = 1|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Channel1     = 2|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Channel2     = 3|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Channel3     = 4|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Channel4     = 5|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Channel5     = 6|0x300U,    /**< TPM8 Channel 0 */
    kDmaRequestMux2TPM8Overflow     = 7|0x300U,    /**< TPM8 Overflow */
    kDmaRequestMux2FlexSPI0Rx       = 8|0x300U,    /**< FlexSPI0 Receive request */
    kDmaRequestMux2FlexSPI0Tx       = 9|0x300U,    /**< FlexSPI0 Transmit request */
    kDmaRequestMux2FlexSPI1Rx       = 10|0x300U,   /**< FlexSPI1 Receive request */
    kDmaRequestMux2FlexSPI1Tx       = 11|0x300U,   /**< FlexSPI1 Transmit request */
    kDmaRequestMux2FlexSPI2Rx       = 12|0x300U,   /**< FlexSPI2 Receive request */
    kDmaRequestMux2FlexSPI2Tx       = 13|0x300U,   /**< FlexSPI2 Transmit request */
    kDmaRequestMux2FlexIO0Shifter0  = 15|0x300U,   /**< FlexIO0 Shifter 0 */
    kDmaRequestMux2FlexIO0Shifter1  = 16|0x300U,   /**< FlexIO0 Shifter 1 */
    kDmaRequestMux2FlexIO0Shifter2  = 17|0x300U,   /**< FlexIO0 Shifter 2 */
    kDmaRequestMux2FlexIO0Shifter3  = 18|0x300U,   /**< FlexIO0 Shifter 3 */
    kDmaRequestMux2FlexIO0Shifter4  = 19|0x300U,   /**< FlexIO0 Shifter 4 */
    kDmaRequestMux2FlexIO0Shifter5  = 20|0x300U,   /**< FlexIO0 Shifter 5 */
    kDmaRequestMux2FlexIO0Shifter6  = 21|0x300U,   /**< FlexIO0 Shifter 6 */
    kDmaRequestMux2FlexIO0Shifter7  = 22|0x300U,   /**< FlexIO0 Shifter 7 */
    kDmaRequestMux2FlexIO1Shifter0  = 23|0x300U,   /**< FlexIO1 Shifter 0 */
    kDmaRequestMux2FlexIO1Shifter1  = 24|0x300U,   /**< FlexIO1 Shifter 1 */
    kDmaRequestMux2FlexIO1Shifter2  = 25|0x300U,   /**< FlexIO1 Shifter 2 */
    kDmaRequestMux2FlexIO1Shifter3  = 26|0x300U,   /**< FlexIO1 Shifter 3 */
    kDmaRequestMux2FlexIO1Shifter4  = 27|0x300U,   /**< FlexIO1 Shifter 4 */
    kDmaRequestMux2FlexIO1Shifter5  = 28|0x300U,   /**< FlexIO1 Shifter 5 */
    kDmaRequestMux2FlexIO1Shifter6  = 29|0x300U,   /**< FlexIO1 Shifter 6 */
    kDmaRequestMux2FlexIO1Shifter7  = 30|0x300U,   /**< FlexIO1 Shifter 7 */
    kDmaRequestMux2LPI2C3Rx         = 33|0x300U,   /**< LPI2C3 Master/Slave Receive */
    kDmaRequestMux2LPI2C3Tx         = 34|0x300U,   /**< LPI2C3 Master/Slave Transmit */
    kDmaRequestMux2LPI2C5Rx         = 37|0x300U,   /**< LPI2C5 Master/Slave Receive */
    kDmaRequestMux2LPI2C5Tx         = 38|0x300U,   /**< LPI2C5 Master/Slave Transmit */
    kDmaRequestMux2I3C1Rx           = 39|0x300U,   /**< I3C1 Master/Slave Receive */
    kDmaRequestMux2I3C1Tx           = 40|0x300U,   /**< I3C1 Master/Slave Transmit */
    kDmaRequestMux2I3C2Rx           = 41|0x300U,   /**< I3C2 Master/Slave Receive */
    kDmaRequestMux2I3C2Tx           = 42|0x300U,   /**< I3C2 Master/Slave Transmit */
    kDmaRequestMux2LPSPI3Rx         = 45|0x300U,   /**< LPSPI3 Receive */
    kDmaRequestMux2LPSPI3Tx         = 46|0x300U,   /**< LPSPI3 Transmit */
    kDmaRequestMux2LPSPI5Rx         = 49|0x300U,   /**< LPSPI5 Receive */
    kDmaRequestMux2LPSPI5Tx         = 50|0x300U,   /**< LPSPI5 Transmit */
    kDmaRequestMux2LPUART3Rx        = 53|0x300U,   /**< LPUART3 Receive */
    kDmaRequestMux2LPUART3Tx        = 54|0x300U,   /**< LPUART3 Transmit */
    kDmaRequestMux2LPUART5Rx        = 57|0x300U,   /**< LPUART5 Receive */
    kDmaRequestMux2LPUART5Tx        = 58|0x300U,   /**< LPUART5 Transmit */
    kDmaRequestMux2SAI0Rx           = 59|0x300U,   /**< SAI0 Receive */
    kDmaRequestMux2SAI0Tx           = 60|0x300U,   /**< SAI0 Transmit */
    kDmaRequestMux2SAI1Rx           = 61|0x300U,   /**< SAI1 Receive */
    kDmaRequestMux2SAI1Tx           = 62|0x300U,   /**< SAI1 Transmit */
    kDmaRequestMux2SAI4Rx           = 67|0x300U,   /**< SAI4 Receive */
    kDmaRequestMux2SAI4Tx           = 68|0x300U,   /**< SAI4 Transmit */
    kDmaRequestMux2SAI5Rx           = 69|0x300U,   /**< SAI5 Receive */
    kDmaRequestMux2SAI5Tx           = 70|0x300U,   /**< SAI5 Transmit */
    kDmaRequestMux2SAI6Rx           = 71|0x300U,   /**< SAI6 Receive */
    kDmaRequestMux2SAI6Tx           = 72|0x300U,   /**< SAI6 Transmit */
    kDmaRequestMux2SAI7Rx           = 73|0x300U,   /**< SAI7 Receive */
    kDmaRequestMux2SAI7Tx           = 74|0x300U,   /**< SAI7 Transmit */
    kDmaRequestMux2SPDIFRx          = 75|0x300U,   /**< SPDIF Receive */
    kDmaRequestMux2SPDIFTx          = 76|0x300U,   /**< SPDIF Transmit */
    kDmaRequestMux2GPIODEvent0      = 83|0x300U,   /**< GPIOD Pin event request 0 */
    kDmaRequestMux2GPIODEvent1      = 84|0x300U,   /**< GPIOD Pin event request 1 */
} dma2_request_source_t;

/* @} */
#endif /* DMA2_REQUEST_SOURCE_T_ */


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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_MP_GRPRI_COUNT                        32u
#define DMA_CH_COUNT                              32u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT;                            /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t MP_HRS;                            /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_MP_GRPRI_COUNT];      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[3712];
  struct {                                         /* offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x1000, array step: 0x1000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x1004, array step: 0x1000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x1008, array step: 0x1000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x100C, array step: 0x1000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x1010, array step: 0x1000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x1014, array step: 0x1000 */
         uint8_t RESERVED_0[8];
    __IO uint32_t TCD_SADDR;                         /**< TCD Source Address, array offset: 0x1020, array step: 0x1000 */
    __IO uint16_t TCD_SOFF;                          /**< TCD Signed Source Address Offset, array offset: 0x1024, array step: 0x1000 */
    __IO uint16_t TCD_ATTR;                          /**< TCD Transfer Attributes, array offset: 0x1026, array step: 0x1000 */
    union {                                          /* offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFNO;                /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
      __IO uint32_t TCD_NBYTES_MLOFFYES;               /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x1028, array step: 0x1000 */
    };
    __IO uint32_t TCD_SLAST_SDA;                     /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x102C, array step: 0x1000 */
    __IO uint32_t TCD_DADDR;                         /**< TCD Destination Address, array offset: 0x1030, array step: 0x1000 */
    __IO uint16_t TCD_DOFF;                          /**< TCD Signed Destination Address Offset, array offset: 0x1034, array step: 0x1000 */
    union {                                          /* offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKNO;                 /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1036, array step: 0x1000 */
      __IO uint16_t TCD_CITER_ELINKYES;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1036, array step: 0x1000 */
    };
    __IO uint32_t TCD_DLAST_SGA;                     /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x1038, array step: 0x1000 */
    __IO uint16_t TCD_CSR;                           /**< TCD Control and Status, array offset: 0x103C, array step: 0x1000 */
    union {                                          /* offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKNO;                 /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x103E, array step: 0x1000 */
      __IO uint16_t TCD_BITER_ELINKYES;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x103E, array step: 0x1000 */
    };
         uint8_t RESERVED_1[4032];
  } CH[DMA_CH_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA_MP_CSR_EDBG_MASK                     (0x2U)
#define DMA_MP_CSR_EDBG_SHIFT                    (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_MP_CSR_EDBG(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_EDBG_SHIFT)) & DMA_MP_CSR_EDBG_MASK)

#define DMA_MP_CSR_ERCA_MASK                     (0x4U)
#define DMA_MP_CSR_ERCA_SHIFT                    (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_MP_CSR_ERCA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ERCA_SHIFT)) & DMA_MP_CSR_ERCA_MASK)

#define DMA_MP_CSR_HAE_MASK                      (0x10U)
#define DMA_MP_CSR_HAE_SHIFT                     (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_MP_CSR_HAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HAE_SHIFT)) & DMA_MP_CSR_HAE_MASK)

#define DMA_MP_CSR_HALT_MASK                     (0x20U)
#define DMA_MP_CSR_HALT_SHIFT                    (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_MP_CSR_HALT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HALT_SHIFT)) & DMA_MP_CSR_HALT_MASK)

#define DMA_MP_CSR_GCLC_MASK                     (0x40U)
#define DMA_MP_CSR_GCLC_SHIFT                    (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_MP_CSR_GCLC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GCLC_SHIFT)) & DMA_MP_CSR_GCLC_MASK)

#define DMA_MP_CSR_GMRC_MASK                     (0x80U)
#define DMA_MP_CSR_GMRC_SHIFT                    (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication disabled for all channels
 *  0b1..Master ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_MP_CSR_GMRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GMRC_SHIFT)) & DMA_MP_CSR_GMRC_MASK)

#define DMA_MP_CSR_ECX_MASK                      (0x100U)
#define DMA_MP_CSR_ECX_SHIFT                     (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ECX_SHIFT)) & DMA_MP_CSR_ECX_MASK)

#define DMA_MP_CSR_CX_MASK                       (0x200U)
#define DMA_MP_CSR_CX_SHIFT                      (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_CX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_CX_SHIFT)) & DMA_MP_CSR_CX_MASK)

#define DMA_MP_CSR_ACTIVE_ID_MASK                (0x1F000000U)
#define DMA_MP_CSR_ACTIVE_ID_SHIFT               (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_MP_CSR_ACTIVE_ID(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_MP_CSR_ACTIVE_ID_MASK)

#define DMA_MP_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_MP_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_MP_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_SHIFT)) & DMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                       (0x1U)
#define DMA_MP_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_MP_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DBE_SHIFT)) & DMA_MP_ES_DBE_MASK)

#define DMA_MP_ES_SBE_MASK                       (0x2U)
#define DMA_MP_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_MP_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SBE_SHIFT)) & DMA_MP_ES_SBE_MASK)

#define DMA_MP_ES_SGE_MASK                       (0x4U)
#define DMA_MP_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_MP_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SGE_SHIFT)) & DMA_MP_ES_SGE_MASK)

#define DMA_MP_ES_NCE_MASK                       (0x8U)
#define DMA_MP_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_MP_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_NCE_SHIFT)) & DMA_MP_ES_NCE_MASK)

#define DMA_MP_ES_DOE_MASK                       (0x10U)
#define DMA_MP_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_MP_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DOE_SHIFT)) & DMA_MP_ES_DOE_MASK)

#define DMA_MP_ES_DAE_MASK                       (0x20U)
#define DMA_MP_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_MP_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DAE_SHIFT)) & DMA_MP_ES_DAE_MASK)

#define DMA_MP_ES_SOE_MASK                       (0x40U)
#define DMA_MP_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_MP_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SOE_SHIFT)) & DMA_MP_ES_SOE_MASK)

#define DMA_MP_ES_SAE_MASK                       (0x80U)
#define DMA_MP_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_MP_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SAE_SHIFT)) & DMA_MP_ES_SAE_MASK)

#define DMA_MP_ES_ECX_MASK                       (0x100U)
#define DMA_MP_ES_ECX_SHIFT                      (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_MP_ES_ECX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ECX_SHIFT)) & DMA_MP_ES_ECX_MASK)

#define DMA_MP_ES_ERRCHN_MASK                    (0x1F000000U)
#define DMA_MP_ES_ERRCHN_SHIFT                   (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_MP_ES_ERRCHN(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ERRCHN_SHIFT)) & DMA_MP_ES_ERRCHN_MASK)

#define DMA_MP_ES_VLD_MASK                       (0x80000000U)
#define DMA_MP_ES_VLD_SHIFT                      (31U)
/*! VLD - Valid
 *  0b0..No CHn_ES[ERR] fields are set to 1
 *  0b1..At least one CHn_ES[ERR] field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_MP_ES_VLD(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_VLD_SHIFT)) & DMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                      (0xFFFFFFFFU)
#define DMA_MP_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request Status */
#define DMA_MP_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_INT_INT_SHIFT)) & DMA_MP_INT_INT_MASK)
/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                      (0xFFFFFFFFU)
#define DMA_MP_HRS_HRS_SHIFT                     (0U)
/*! HRS - Hardware Request Status */
#define DMA_MP_HRS_HRS(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_HRS_HRS_SHIFT)) & DMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_CH_GRPRI_GRPRI_SHIFT                 (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_CH_GRPRI_GRPRI(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CH_GRPRI_GRPRI_SHIFT)) & DMA_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_CH_GRPRI */
#define DMA_CH_GRPRI_COUNT                       (32U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_CH_CSR_ERQ_MASK                      (0x1U)
#define DMA_CH_CSR_ERQ_SHIFT                     (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_CH_CSR_ERQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ERQ_SHIFT)) & DMA_CH_CSR_ERQ_MASK)

#define DMA_CH_CSR_EARQ_MASK                     (0x2U)
#define DMA_CH_CSR_EARQ_SHIFT                    (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_CH_CSR_EARQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EARQ_SHIFT)) & DMA_CH_CSR_EARQ_MASK)

#define DMA_CH_CSR_EEI_MASK                      (0x4U)
#define DMA_CH_CSR_EEI_SHIFT                     (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_CH_CSR_EEI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EEI_SHIFT)) & DMA_CH_CSR_EEI_MASK)

#define DMA_CH_CSR_EBW_MASK                      (0x8U)
#define DMA_CH_CSR_EBW_SHIFT                     (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_CH_CSR_EBW(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_EBW_SHIFT)) & DMA_CH_CSR_EBW_MASK)

#define DMA_CH_CSR_DONE_MASK                     (0x40000000U)
#define DMA_CH_CSR_DONE_SHIFT                    (30U)
/*! DONE - Channel Done */
#define DMA_CH_CSR_DONE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_DONE_SHIFT)) & DMA_CH_CSR_DONE_MASK)

#define DMA_CH_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_CH_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - Channel Active */
#define DMA_CH_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_CH_CSR_ACTIVE_SHIFT)) & DMA_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA_CH_CSR */
#define DMA_CH_CSR_COUNT                         (32U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_CH_ES_DBE_MASK                       (0x1U)
#define DMA_CH_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_CH_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DBE_SHIFT)) & DMA_CH_ES_DBE_MASK)

#define DMA_CH_ES_SBE_MASK                       (0x2U)
#define DMA_CH_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_CH_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SBE_SHIFT)) & DMA_CH_ES_SBE_MASK)

#define DMA_CH_ES_SGE_MASK                       (0x4U)
#define DMA_CH_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_CH_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SGE_SHIFT)) & DMA_CH_ES_SGE_MASK)

#define DMA_CH_ES_NCE_MASK                       (0x8U)
#define DMA_CH_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_CH_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_NCE_SHIFT)) & DMA_CH_ES_NCE_MASK)

#define DMA_CH_ES_DOE_MASK                       (0x10U)
#define DMA_CH_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_CH_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DOE_SHIFT)) & DMA_CH_ES_DOE_MASK)

#define DMA_CH_ES_DAE_MASK                       (0x20U)
#define DMA_CH_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_CH_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_DAE_SHIFT)) & DMA_CH_ES_DAE_MASK)

#define DMA_CH_ES_SOE_MASK                       (0x40U)
#define DMA_CH_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_CH_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SOE_SHIFT)) & DMA_CH_ES_SOE_MASK)

#define DMA_CH_ES_SAE_MASK                       (0x80U)
#define DMA_CH_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_CH_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_SAE_SHIFT)) & DMA_CH_ES_SAE_MASK)

#define DMA_CH_ES_ERR_MASK                       (0x80000000U)
#define DMA_CH_ES_ERR_SHIFT                      (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_CH_ES_ERR(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_CH_ES_ERR_SHIFT)) & DMA_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA_CH_ES */
#define DMA_CH_ES_COUNT                          (32U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_CH_INT_INT_MASK                      (0x1U)
#define DMA_CH_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_CH_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_INT_INT_SHIFT)) & DMA_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA_CH_INT */
#define DMA_CH_INT_COUNT                         (32U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_CH_SBR_MID_MASK                      (0x3FU)
#define DMA_CH_SBR_MID_SHIFT                     (0U)
/*! MID - Master ID */
#define DMA_CH_SBR_MID(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_MID_SHIFT)) & DMA_CH_SBR_MID_MASK)

#define DMA_CH_SBR_SEC_MASK                      (0x4000U)
#define DMA_CH_SBR_SEC_SHIFT                     (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA_CH_SBR_SEC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_SEC_SHIFT)) & DMA_CH_SBR_SEC_MASK)

#define DMA_CH_SBR_PAL_MASK                      (0x8000U)
#define DMA_CH_SBR_PAL_SHIFT                     (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_CH_SBR_PAL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_PAL_SHIFT)) & DMA_CH_SBR_PAL_MASK)

#define DMA_CH_SBR_EMI_MASK                      (0x10000U)
#define DMA_CH_SBR_EMI_SHIFT                     (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_CH_SBR_EMI(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_EMI_SHIFT)) & DMA_CH_SBR_EMI_MASK)

#define DMA_CH_SBR_ATTR_MASK                     (0x1E0000U)
#define DMA_CH_SBR_ATTR_SHIFT                    (17U)
/*! ATTR - Attribute Output */
#define DMA_CH_SBR_ATTR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_CH_SBR_ATTR_SHIFT)) & DMA_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA_CH_SBR */
#define DMA_CH_SBR_COUNT                         (32U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_CH_PRI_APL_MASK                      (0x7U)
#define DMA_CH_PRI_APL_SHIFT                     (0U)
/*! APL - Arbitration Priority Level */
#define DMA_CH_PRI_APL(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_APL_SHIFT)) & DMA_CH_PRI_APL_MASK)

#define DMA_CH_PRI_DPA_MASK                      (0x40000000U)
#define DMA_CH_PRI_DPA_SHIFT                     (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_CH_PRI_DPA(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_DPA_SHIFT)) & DMA_CH_PRI_DPA_MASK)

#define DMA_CH_PRI_ECP_MASK                      (0x80000000U)
#define DMA_CH_PRI_ECP_SHIFT                     (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_CH_PRI_ECP(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_PRI_ECP_SHIFT)) & DMA_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA_CH_PRI */
#define DMA_CH_PRI_COUNT                         (32U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA_CH_MUX_SRC_MASK                      (0x7FU)
#define DMA_CH_MUX_SRC_SHIFT                     (0U)
/*! SRC - Service Request Source */
#define DMA_CH_MUX_SRC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_CH_MUX_SRC_SHIFT)) & DMA_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA_CH_MUX */
#define DMA_CH_MUX_COUNT                         (32U)

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_TCD_SADDR_SADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_SADDR_SADDR_SHIFT                (0U)
/*! SADDR - Source Address */
#define DMA_TCD_SADDR_SADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SADDR_SADDR_SHIFT)) & DMA_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_TCD_SADDR */
#define DMA_TCD_SADDR_COUNT                      (32U)

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_TCD_SOFF_SOFF_MASK                   (0xFFFFU)
#define DMA_TCD_SOFF_SOFF_SHIFT                  (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_TCD_SOFF_SOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_SOFF_SOFF_SHIFT)) & DMA_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_TCD_SOFF */
#define DMA_TCD_SOFF_COUNT                       (32U)

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_TCD_ATTR_DSIZE_MASK                  (0x7U)
#define DMA_TCD_ATTR_DSIZE_SHIFT                 (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_TCD_ATTR_DSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DSIZE_SHIFT)) & DMA_TCD_ATTR_DSIZE_MASK)

#define DMA_TCD_ATTR_DMOD_MASK                   (0xF8U)
#define DMA_TCD_ATTR_DMOD_SHIFT                  (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_TCD_ATTR_DMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_DMOD_SHIFT)) & DMA_TCD_ATTR_DMOD_MASK)

#define DMA_TCD_ATTR_SSIZE_MASK                  (0x700U)
#define DMA_TCD_ATTR_SSIZE_SHIFT                 (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..
 */
#define DMA_TCD_ATTR_SSIZE(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SSIZE_SHIFT)) & DMA_TCD_ATTR_SSIZE_MASK)

#define DMA_TCD_ATTR_SMOD_MASK                   (0xF800U)
#define DMA_TCD_ATTR_SMOD_SHIFT                  (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_TCD_ATTR_SMOD(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_ATTR_SMOD_SHIFT)) & DMA_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_TCD_ATTR */
#define DMA_TCD_ATTR_COUNT                       (32U)

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK       (0x3FFFFFFFU)
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT      (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFNO_NBYTES(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK        (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT       (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_DMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK        (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT       (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFNO_SMLOE(x)          (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFNO */
#define DMA_TCD_NBYTES_MLOFFNO_COUNT             (32U)

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK      (0x3FFU)
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT     (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_TCD_NBYTES_MLOFFYES_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK       (0x3FFFFC00U)
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT      (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_TCD_NBYTES_MLOFFYES_MLOFF(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK       (0x40000000U)
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT      (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK       (0x80000000U)
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT      (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_TCD_NBYTES_MLOFFYES_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_TCD_NBYTES_MLOFFYES */
#define DMA_TCD_NBYTES_MLOFFYES_COUNT            (32U)

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_TCD_SLAST_SDA_SLAST_SDA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT        (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_TCD_SLAST_SDA_SLAST_SDA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA_TCD_SLAST_SDA */
#define DMA_TCD_SLAST_SDA_COUNT                  (32U)

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_TCD_DADDR_DADDR_MASK                 (0xFFFFFFFFU)
#define DMA_TCD_DADDR_DADDR_SHIFT                (0U)
/*! DADDR - Destination Address */
#define DMA_TCD_DADDR_DADDR(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DADDR_DADDR_SHIFT)) & DMA_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_TCD_DADDR */
#define DMA_TCD_DADDR_COUNT                      (32U)

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_TCD_DOFF_DOFF_MASK                   (0xFFFFU)
#define DMA_TCD_DOFF_DOFF_SHIFT                  (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_TCD_DOFF_DOFF(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_DOFF_DOFF_SHIFT)) & DMA_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_TCD_DOFF */
#define DMA_TCD_DOFF_COUNT                       (32U)

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKNO_CITER_MASK         (0x7FFFU)
#define DMA_TCD_CITER_ELINKNO_CITER_SHIFT        (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKNO_CITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA_TCD_CITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_CITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKNO */
#define DMA_TCD_CITER_ELINKNO_COUNT              (32U)

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_CITER_ELINKYES_CITER_MASK        (0x1FFU)
#define DMA_TCD_CITER_ELINKYES_CITER_SHIFT       (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_TCD_CITER_ELINKYES_CITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA_TCD_CITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_TCD_CITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_CITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_CITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_CITER_ELINKYES */
#define DMA_TCD_CITER_ELINKYES_COUNT             (32U)

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_TCD_DLAST_SGA_DLAST_SGA_MASK         (0xFFFFFFFFU)
#define DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT        (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_TCD_DLAST_SGA_DLAST_SGA(x)           (((uint32_t)(((uint32_t)(x)) << DMA_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA_TCD_DLAST_SGA */
#define DMA_TCD_DLAST_SGA_COUNT                  (32U)

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_TCD_CSR_START_MASK                   (0x1U)
#define DMA_TCD_CSR_START_SHIFT                  (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_TCD_CSR_START(x)                     (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_START_SHIFT)) & DMA_TCD_CSR_START_MASK)

#define DMA_TCD_CSR_INTMAJOR_MASK                (0x2U)
#define DMA_TCD_CSR_INTMAJOR_SHIFT               (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_TCD_CSR_INTMAJOR(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTMAJOR_SHIFT)) & DMA_TCD_CSR_INTMAJOR_MASK)

#define DMA_TCD_CSR_INTHALF_MASK                 (0x4U)
#define DMA_TCD_CSR_INTHALF_SHIFT                (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_TCD_CSR_INTHALF(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_INTHALF_SHIFT)) & DMA_TCD_CSR_INTHALF_MASK)

#define DMA_TCD_CSR_DREQ_MASK                    (0x8U)
#define DMA_TCD_CSR_DREQ_SHIFT                   (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_TCD_CSR_DREQ(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_DREQ_SHIFT)) & DMA_TCD_CSR_DREQ_MASK)

#define DMA_TCD_CSR_ESG_MASK                     (0x10U)
#define DMA_TCD_CSR_ESG_SHIFT                    (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_TCD_CSR_ESG(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESG_SHIFT)) & DMA_TCD_CSR_ESG_MASK)

#define DMA_TCD_CSR_MAJORELINK_MASK              (0x20U)
#define DMA_TCD_CSR_MAJORELINK_SHIFT             (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_CSR_MAJORELINK(x)                (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORELINK_SHIFT)) & DMA_TCD_CSR_MAJORELINK_MASK)

#define DMA_TCD_CSR_EEOP_MASK                    (0x40U)
#define DMA_TCD_CSR_EEOP_SHIFT                   (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_TCD_CSR_EEOP(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_EEOP_SHIFT)) & DMA_TCD_CSR_EEOP_MASK)

#define DMA_TCD_CSR_ESDA_MASK                    (0x80U)
#define DMA_TCD_CSR_ESDA_SHIFT                   (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_TCD_CSR_ESDA(x)                      (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_ESDA_SHIFT)) & DMA_TCD_CSR_ESDA_MASK)

#define DMA_TCD_CSR_MAJORLINKCH_MASK             (0x1F00U)
#define DMA_TCD_CSR_MAJORLINKCH_SHIFT            (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_TCD_CSR_MAJORLINKCH(x)               (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_TCD_CSR_MAJORLINKCH_MASK)

#define DMA_TCD_CSR_BWC_MASK                     (0xC000U)
#define DMA_TCD_CSR_BWC_SHIFT                    (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_TCD_CSR_BWC(x)                       (((uint16_t)(((uint16_t)(x)) << DMA_TCD_CSR_BWC_SHIFT)) & DMA_TCD_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_TCD_CSR */
#define DMA_TCD_CSR_COUNT                        (32U)

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKNO_BITER_MASK         (0x7FFFU)
#define DMA_TCD_BITER_ELINKNO_BITER_SHIFT        (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKNO_BITER(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA_TCD_BITER_ELINKNO_ELINK_MASK         (0x8000U)
#define DMA_TCD_BITER_ELINKNO_ELINK_SHIFT        (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKNO_ELINK(x)           (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKNO */
#define DMA_TCD_BITER_ELINKNO_COUNT              (32U)

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_TCD_BITER_ELINKYES_BITER_MASK        (0x1FFU)
#define DMA_TCD_BITER_ELINKYES_BITER_SHIFT       (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_TCD_BITER_ELINKYES_BITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA_TCD_BITER_ELINKYES_LINKCH_MASK       (0x3E00U)
#define DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT      (9U)
/*! LINKCH - Link Channel Number */
#define DMA_TCD_BITER_ELINKYES_LINKCH(x)         (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA_TCD_BITER_ELINKYES_ELINK_MASK        (0x8000U)
#define DMA_TCD_BITER_ELINKYES_ELINK_SHIFT       (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_TCD_BITER_ELINKYES_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_TCD_BITER_ELINKYES */
#define DMA_TCD_BITER_ELINKYES_COUNT             (32U)


/*!
 * @}
 */ /* end of group DMA_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA_H_ */

