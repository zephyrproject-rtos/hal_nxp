/*
 * Copyright 2024 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef _FSL_EDMA_SOC_H_
#define _FSL_EDMA_SOC_H_

#include "fsl_common.h"

/*!
 * @addtogroup edma_soc
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/*! @name Driver version */
/*@{*/
/*! @brief Driver version 2.0.0. */
#define FSL_EDMA_SOC_DRIVER_VERSION (MAKE_VERSION(2, 0, 0))
/*@}*/

/*!@brief DMA IP version */
#define FSL_EDMA_SOC_IP_DMA3 (1)
#define FSL_EDMA_SOC_IP_DMA5 (1)

/**
 * @brief DMA base table
 * @details DMA3 is ip version, the instance index is 1, so it can be EDMA1_CH1(EDMA1), EDMA5 is ip version, the instance index is 2
 *
 */
#define EDMA_BASE_PTRS \
    {                  \
        EDMA1, EDMA2, EDMA3, EDMA4           \
    }

#define EDMA_CHN_IRQS                                                                                               \
    {                                                                                                               \
        {                                                                                                           \
            EDMA1_CH0_IRQn, EDMA1_CH1_IRQn, EDMA1_CH2_IRQn, EDMA1_CH3_IRQn, EDMA1_CH4_IRQn, EDMA1_CH5_IRQn, EDMA1_CH6_IRQn, EDMA1_CH7_IRQn, \
                EDMA1_CH8_IRQn, EDMA1_CH9_IRQn, EDMA1_CH10_IRQn, EDMA1_CH11_IRQn, EDMA1_CH12_IRQn, EDMA1_CH13_IRQn, EDMA1_CH14_IRQn,     \
                EDMA1_CH15_IRQn, EDMA1_CH16_IRQn, EDMA1_CH17_IRQn, EDMA1_CH18_IRQn, EDMA1_CH19_IRQn, EDMA1_CH20_IRQn, EDMA1_CH21_IRQn,   \
                EDMA1_CH22_IRQn, EDMA1_CH23_IRQn, EDMA1_CH24_IRQn, EDMA1_CH25_IRQn, EDMA1_CH26_IRQn, EDMA1_CH27_IRQn, EDMA1_CH28_IRQn,   \
                EDMA1_CH29_IRQn, EDMA1_CH30_IRQn, EDMA1_CH31_IRQn                                                                        \
        },                                                                                                           \
        {                                                                                                             \
            EDMA2_CH0_IRQn, EDMA2_CH1_IRQn, EDMA2_CH2_IRQn, EDMA2_CH3_IRQn, EDMA2_CH4_IRQn, EDMA2_CH5_IRQn, EDMA2_CH6_IRQn,  \
                EDMA2_CH7_IRQn, EDMA2_CH8_IRQn, EDMA2_CH9_IRQn, EDMA2_CH10_IRQn, EDMA2_CH11_IRQn, EDMA2_CH12_IRQn,       \
                EDMA2_CH13_IRQn, EDMA2_CH14_IRQn, EDMA2_CH15_IRQn, EDMA2_CH16_IRQn, EDMA2_CH17_IRQn, EDMA2_CH18_IRQn, \
                EDMA2_CH19_IRQn, EDMA2_CH20_IRQn, EDMA2_CH21_IRQn, EDMA2_CH22_IRQn, EDMA2_CH23_IRQn, EDMA2_CH24_IRQn, \
                EDMA2_CH25_IRQn, EDMA2_CH26_IRQn, EDMA2_CH27_IRQn, EDMA2_CH28_IRQn, EDMA2_CH29_IRQn, EDMA2_CH30_IRQn, \
                EDMA2_CH31_IRQn, EDMA2_CH32_IRQn, EDMA2_CH33_IRQn, EDMA2_CH34_IRQn, EDMA2_CH35_IRQn, EDMA2_CH36_IRQn, \
                EDMA2_CH37_IRQn, EDMA2_CH38_IRQn, EDMA2_CH39_IRQn, EDMA2_CH40_IRQn, EDMA2_CH41_IRQn, EDMA2_CH42_IRQn, \
                EDMA2_CH43_IRQn, EDMA2_CH44_IRQn, EDMA2_CH45_IRQn, EDMA2_CH46_IRQn, EDMA2_CH47_IRQn, EDMA2_CH48_IRQn, \
                EDMA2_CH49_IRQn, EDMA2_CH50_IRQn, EDMA2_CH51_IRQn, EDMA2_CH52_IRQn, EDMA2_CH53_IRQn, EDMA2_CH54_IRQn, \
                EDMA2_CH55_IRQn, EDMA2_CH56_IRQn, EDMA2_CH57_IRQn, EDMA2_CH58_IRQn, EDMA2_CH59_IRQn, EDMA2_CH60_IRQn, \
                EDMA2_CH61_IRQn, EDMA2_CH62_IRQn, EDMA2_CH63_IRQn,                                                    \
        },                                                                                                             \
        {                                                                                                             \
            EDMA3_CH0_IRQn, EDMA3_CH1_IRQn, EDMA3_CH2_IRQn, EDMA3_CH3_IRQn, EDMA3_CH4_IRQn, EDMA3_CH5_IRQn, EDMA3_CH6_IRQn,  \
                EDMA3_CH7_IRQn, EDMA3_CH8_IRQn, EDMA3_CH9_IRQn, EDMA3_CH10_IRQn, EDMA3_CH11_IRQn, EDMA3_CH12_IRQn,       \
                EDMA3_CH13_IRQn, EDMA3_CH14_IRQn, EDMA3_CH15_IRQn, EDMA3_CH16_IRQn, EDMA3_CH17_IRQn, EDMA3_CH18_IRQn, \
                EDMA3_CH19_IRQn, EDMA3_CH20_IRQn, EDMA3_CH21_IRQn, EDMA3_CH22_IRQn, EDMA3_CH23_IRQn, EDMA3_CH24_IRQn, \
                EDMA3_CH25_IRQn, EDMA3_CH26_IRQn, EDMA3_CH27_IRQn, EDMA3_CH28_IRQn, EDMA3_CH29_IRQn, EDMA3_CH30_IRQn, \
                EDMA3_CH31_IRQn, EDMA3_CH32_IRQn, EDMA3_CH33_IRQn, EDMA3_CH34_IRQn, EDMA3_CH35_IRQn, EDMA3_CH36_IRQn, \
                EDMA3_CH37_IRQn, EDMA3_CH38_IRQn, EDMA3_CH39_IRQn, EDMA3_CH40_IRQn, EDMA3_CH41_IRQn, EDMA3_CH42_IRQn, \
                EDMA3_CH43_IRQn, EDMA3_CH44_IRQn, EDMA3_CH45_IRQn, EDMA3_CH46_IRQn, EDMA3_CH47_IRQn, EDMA3_CH48_IRQn, \
                EDMA3_CH49_IRQn, EDMA3_CH50_IRQn, EDMA3_CH51_IRQn, EDMA3_CH52_IRQn, EDMA3_CH53_IRQn, EDMA3_CH54_IRQn, \
                EDMA3_CH55_IRQn, EDMA3_CH56_IRQn, EDMA3_CH57_IRQn, EDMA3_CH58_IRQn, EDMA3_CH59_IRQn, EDMA3_CH60_IRQn, \
                EDMA3_CH61_IRQn, EDMA3_CH62_IRQn, EDMA3_CH63_IRQn,                                                    \
        },                                                                                                             \
        {                                                                                                             \
            EDMA4_CH0_IRQn, EDMA4_CH1_IRQn, EDMA4_CH2_IRQn, EDMA4_CH3_IRQn, EDMA4_CH4_IRQn, EDMA4_CH5_IRQn, EDMA4_CH6_IRQn,  \
                EDMA4_CH7_IRQn, EDMA4_CH8_IRQn, EDMA4_CH9_IRQn, EDMA4_CH10_IRQn, EDMA4_CH11_IRQn, EDMA4_CH12_IRQn,       \
                EDMA4_CH13_IRQn, EDMA4_CH14_IRQn, EDMA4_CH15_IRQn, EDMA4_CH16_IRQn, EDMA4_CH17_IRQn, EDMA4_CH18_IRQn, \
                EDMA4_CH19_IRQn, EDMA4_CH20_IRQn, EDMA4_CH21_IRQn, EDMA4_CH22_IRQn, EDMA4_CH23_IRQn, EDMA4_CH24_IRQn, \
                EDMA4_CH25_IRQn, EDMA4_CH26_IRQn, EDMA4_CH27_IRQn, EDMA4_CH28_IRQn, EDMA4_CH29_IRQn, EDMA4_CH30_IRQn, \
                EDMA4_CH31_IRQn, EDMA4_CH32_IRQn, EDMA4_CH33_IRQn, EDMA4_CH34_IRQn, EDMA4_CH35_IRQn, EDMA4_CH36_IRQn, \
                EDMA4_CH37_IRQn, EDMA4_CH38_IRQn, EDMA4_CH39_IRQn, EDMA4_CH40_IRQn, EDMA4_CH41_IRQn, EDMA4_CH42_IRQn, \
                EDMA4_CH43_IRQn, EDMA4_CH44_IRQn, EDMA4_CH45_IRQn, EDMA4_CH46_IRQn, EDMA4_CH47_IRQn, EDMA4_CH48_IRQn, \
                EDMA4_CH49_IRQn, EDMA4_CH50_IRQn, EDMA4_CH51_IRQn, EDMA4_CH52_IRQn, EDMA4_CH53_IRQn, EDMA4_CH54_IRQn, \
                EDMA4_CH55_IRQn, EDMA4_CH56_IRQn, EDMA4_CH57_IRQn, EDMA4_CH58_IRQn, EDMA4_CH59_IRQn, EDMA4_CH60_IRQn, \
                EDMA4_CH61_IRQn, EDMA4_CH62_IRQn, EDMA4_CH63_IRQn,                                                    \
        }                                                                                                             \
    }

/* @brief dma1 request source */
typedef enum _dma1_request_source
{
    kDma1RequestMuxReserved0 = 0U, /**< nan */
    kDma1RequestMuxCan1 = 1U, /**< CAN-FD 1 DMA request and response */
    kDma1RequestMuxLptmr1 = 2U, /**< LPTIMER1 DMA request and response */
    kDma1RequestMuxReserved1 = 3U, /**< nan */
    kDma1RequestMuxTpm1Overflow = 4U, /**< LPTPM1 DMA Overflow request and response */
    kDma1RequestMuxTpm2Overflow = 5U, /**< LPTPM2 DMA Overflow request and response */
    kDma1RequestMuxPdm = 6U, /**< PDM DMA request and response */
    kDma1RequestMuxAdc1 = 7U, /**< ADC DMA request */
    kDma1RequestMuxGpio1Ch0 = 8U, /**< GPIO1 channel 0 DMA request and response */
    kDma1RequestMuxGpio1Ch1 = 9U, /**< GPIO1 channel 1 DMA request and response */
    kDma1RequestMuxI3c1ToBus = 10U, /**< I3C1 "To-bus" DMA request and response */
    kDma1RequestMuxI3c1FromBus = 11U, /**< I3C1 "from-bus" DMA request and response */
    kDma1RequestMuxLpi2c1Tx = 12U, /**< LPI2C1 Master TX DMA request; LPI2C1 Slave TX DMA request */
    kDma1RequestMuxLpi2c1Rx = 13U, /**< LPI2C1 Master RX DMA request; LPI2C1 Slave RX DMA request */
    kDma1RequestMuxLpi2c2Tx = 14U, /**< LPI2C2 Master TX DMA request; LPI2C2 Slave TX DMA request */
    kDma1RequestMuxLpi2c2Rx = 15U, /**< LPI2C2 Master RX DMA request; LPI2C2 Slave RX DMA request */
    kDma1RequestMuxLpspi1Tx = 16U, /**< LPSPI1 TX DMA request */
    kDma1RequestMuxLpspi1Rx = 17U, /**< LPSPI1 RX DMA request */
    kDma1RequestMuxLpspi2Tx = 18U, /**< LPSPI2 TX DMA request */
    kDma1RequestMuxLpspi2Rx = 19U, /**< LPSPI2 RX DMA request */
    kDma1RequestMuxLpuart1Tx = 20U, /**< LPUART1 DMA TX request */
    kDma1RequestMuxLpuart1Rx = 21U, /**< LPUART1 DMA RX request and response */
    kDma1RequestMuxLpuart2Tx = 22U, /**< LPUART2 DMA TX request */
    kDma1RequestMuxLpuart2Rx = 23U, /**< LPUART2 DMA RX request and response */
    kDma1RequestMuxSai1Tx = 24U, /**< SAI1 TX DMA request and response */
    kDma1RequestMuxSai1Rx = 25U, /**< SAI1 RX DMA request and response */
    kDma1RequestMuxTpm1Ch0Ch2 = 26U, /**< LPTPM1 DMA Channel 0 request and response; LPTPM1 DMA Channel 2 request and response */
    kDma1RequestMuxTpm1Ch1Ch3 = 27U, /**< LPTPM1 DMA Channel 1 request and response; LPTPM1 DMA Channel 3 request and response */
    kDma1RequestMuxTpm2Ch0Ch2 = 28U, /**< LPTPM2 DMA Channel 0 request and response; LPTPM2 DMA Channel 2 request and response */
    kDma1RequestMuxTpm2Ch1Ch3 = 29U, /**< LPTPM2 DMA Channel 1 request and response; LPTPM2 DMA Channel 3 request and response */
    kDma1RequestMuxReserved2 = 30U, /**< Reserved - PDM Digital Microphone Interface DMA request and response */
    kDma1RequestMuxReserved3 = 31U, /**< nan */
} dma1_request_source_t;

/* @brief dma2 request source */
typedef enum _dma2_request_source
{
    kDma2RequestMuxReserved0 = 0U, /**< Default - Channel Disabled (Do Not Re-assign) */
    kDma2RequestMuxGpio2Ch0 = 1U, /**< GPIO2 channel 0 DMA request and response */
    kDma2RequestMuxGpio2Ch1 = 2U, /**< GPIO2 channel 1 DMA request and response */
    kDma2RequestMuxI3c2ToBus = 3U, /**< I3C2 "To-bus" DMA request and response */
    kDma2RequestMuxI3c2FromBus = 4U, /**< I3C2 "from-bus" DMA request and response */
    kDma2RequestMuxLpi2c3Tx = 5U, /**< LPI2C3 Master TX DMA request; LPI2C3 Slave TX DMA request */
    kDma2RequestMuxLpi2c3Rx = 6U, /**< LPI2C3 Master RX DMA request; LPI2C3 Slave RX DMA request */
    kDma2RequestMuxLpspi3Tx = 7U, /**< LPSPI3 TX DMA request */
    kDma2RequestMuxLpspi3Rx = 8U, /**< LPSPI3 RX DMA request */
    kDma2RequestMuxLpuart3Tx = 9U, /**< LPUART3 DMA TX request */
    kDma2RequestMuxLpuart3Rx = 10U, /**< LPUART3 DMA RX request and response */
    kDma2RequestMuxLpuart5Tx = 11U, /**< LPUART5 DMA TX request */
    kDma2RequestMuxLpuart5Rx = 12U, /**< LPUART5 DMA RX request and response */
    kDma2RequestMuxTpm3Ch0Ch2 = 13U, /**< LPTPM3 DMA Channel 0 request and response; LPTPM3 DMA Channel 2 request and response */
    kDma2RequestMuxTpm3Ch1Ch3 = 14U, /**< LPTPM3 DMA Channel 1 request and response; LPTPM3 DMA Channel 3 request and response */
    kDma2RequestMuxTpm3Overflow = 15U, /**< LPTPM3 DMA Overflow request and response */
    kDma2RequestMuxTpm5Ch0Ch2 = 16U, /**< LPTPM5 DMA Channel 0 request and response; LPTPM5 DMA Channel 2 request and response */
    kDma2RequestMuxTpm5Ch1Ch3 = 17U, /**< LPTPM5 DMA Channel 1 request and response; LPTPM5 DMA Channel 3 request and response */
    kDma2RequestMuxTpm5Overflow = 18U, /**< LPTPM5 DMA Overflow request and response */
    kDma2RequestMuxFlexio2Ch0 = 19U, /**< FLEXIO2 Shifter DMA Channel 0 request; FLEXIO2 Timer DMA Channel 0 request */
    kDma2RequestMuxFlexio2Ch1 = 20U, /**< FLEXIO2 Shifter DMA Channel 1 request; FLEXIO2 Timer DMA Channel 1 request */
    kDma2RequestMuxFlexio2Ch2 = 21U, /**< FLEXIO2 Shifter DMA Channel 2 request; FLEXIO2 Timer DMA Channel 2 request */
    kDma2RequestMuxFlexio2Ch3 = 22U, /**< FLEXIO2 Shifter DMA Channel 3 request; FLEXIO2 Timer DMA Channel 3 request */
    kDma2RequestMuxFlexio2Ch4 = 23U, /**< FLEXIO2 Shifter DMA Channel 4 request; FLEXIO2 Timer DMA Channel 4 request */
    kDma2RequestMuxFlexio2Ch5 = 24U, /**< FLEXIO2 Shifter DMA Channel 5 request; FLEXIO2 Timer DMA Channel 5 request */
    kDma2RequestMuxFlexio2Ch6 = 25U, /**< FLEXIO2 Shifter DMA Channel 6 request; FLEXIO2 Timer DMA Channel 6 request */
    kDma2RequestMuxFlexio2Ch7 = 26U, /**< FLEXIO2 Shifter DMA Channel 7 request; FLEXIO2 Timer DMA Channel 7 request */
    kDma2RequestMuxXspi1Tx = 27U, /**< xspi1 DMA TX request */
    kDma2RequestMuxXspi1Rx = 28U, /**< xspi1 DMA RX request */
    kDma2RequestMuxSai2Tx = 29U, /**< SAI2 TX DMA request and response */
    kDma2RequestMuxSai2Rx = 30U, /**< SAI2 RX DMA request and response */
    kDma2RequestMuxSai3Tx = 31U, /**< SAI3 TX DMA request and response */
    kDma2RequestMuxSai3Rx = 32U, /**< SAI3 RX DMA request and response */
    kDma2RequestMuxGpio4Ch0 = 33U, /**< GPIO4 channel 0 DMA request and response */
    kDma2RequestMuxGpio4Ch1 = 34U, /**< GPIO4 channel 1 DMA request and response */
    kDma2RequestMuxSai4Tx = 35U, /**< SAI4 TX DMA request and response */
    kDma2RequestMuxSai4Rx = 36U, /**< SAI4 RX DMA request and response */
    kDma2RequestMuxLpi2c5Tx = 37U, /**< LPI2C5 Master TX DMA request; LPI2C5 Slave TX DMA request */
    kDma2RequestMuxLpi2c5Rx = 38U, /**< LPI2C5 Master RX DMA request; LPI2C5 Slave RX DMA request */
    kDma2RequestMuxLpi2c7Tx = 39U, /**< LPI2C7 Master TX DMA request; LPI2C7 Slave TX DMA request */
    kDma2RequestMuxLpi2c7Rx = 40U, /**< LPI2C7 Master RX DMA request; LPI2C7 Slave RX DMA request */
    kDma2RequestMuxLpspi5Tx = 41U, /**< LPSPI5 TX DMA request */
    kDma2RequestMuxLpspi5Rx = 42U, /**< LPSPI5 RX DMA request */
    kDma2RequestMuxLpspi7Tx = 43U, /**< LPSPI7 TX DMA request */
    kDma2RequestMuxLpspi7Rx = 44U, /**< LPSPI7 RX DMA request */
    kDma2RequestMuxLpuart7Tx = 45U, /**< LPUART7 DMA TX request */
    kDma2RequestMuxLpuart7Rx = 46U, /**< LPUART7 DMA RX request and response */
    kDma2RequestMuxV2xfh = 47U, /**< V2X_FH DMA request */
    kDma2RequestMuxGpio6Ch0 = 48U, /**< GPIO6 channel 0 DMA request and response */
    kDma2RequestMuxGpio6Ch1 = 49U, /**< GPIO6 channel 1 DMA request and response */
    kDma2RequestMuxLpuart9Tx = 50U, /**< LPUART9 DMA TX request */
    kDma2RequestMuxLpuart9Rx = 51U, /**< LPUART9 DMA RX request and response */
    kDma2RequestMuxLpuart11Tx = 52U, /**< LPUART11 DMA TX request */
    kDma2RequestMuxLpuart11Rx = 53U, /**< LPUART11 DMA RX request and response */
    kDma2RequestMuxSinc2Ch0 = 54U, /**< SIN2 DMA request Ch0 */
    kDma2RequestMuxSinc2Ch1 = 55U, /**< SIN2 DMA request Ch1 */
    kDma2RequestMuxSinc2Ch2 = 56U, /**< SIN2 DMA request Ch2 */
    kDma2RequestMuxSinc2Ch3 = 57U, /**< SIN2 DMA request Ch3 */
    kDma2RequestMuxSinc4Ch0 = 58U, /**< SIN4 DMA request Ch0 */
    kDma2RequestMuxSinc4Ch1 = 59U, /**< SIN4 DMA request Ch1 */
    kDma2RequestMuxSinc4Ch2 = 60U, /**< SIN4 DMA request Ch2 */
    kDma2RequestMuxSinc4Ch3 = 61U, /**< SIN4 DMA request Ch3 */
    kDma2RequestMuxFlexpwm2CaptureRegsOfSubmodule0 = 62U, /**< FLEXPWM2 Read DMA request for capture regs of sub-module0 */
    kDma2RequestMuxFlexpwm2CaptureRegsOfSubmodule1 = 63U, /**< FLEXPWM2 Read DMA request for capture regs of sub-module1 */
    kDma2RequestMuxFlexpwm2CaptureRegsOfSubmodule2 = 64U, /**< FLEXPWM2 Read DMA request for capture regs of sub-module2 */
    kDma2RequestMuxFlexpwm2CaptureRegsOfSubmodule3 = 65U, /**< FLEXPWM2 Read DMA request for capture regs of sub-module3 */
    kDma2RequestMuxFlexpwm2ValueRegsOfSubmodule0 = 66U, /**< FLEXPWM2 Write DMA request for value regs of sub-module0 */
    kDma2RequestMuxFlexpwm2ValueRegsOfSubmodule1 = 67U, /**< FLEXPWM2 Write DMA request for value regs of sub-module1 */
    kDma2RequestMuxFlexpwm2ValueRegsOfSubmodule2 = 68U, /**< FLEXPWM2 Write DMA request for value regs of sub-module2 */
    kDma2RequestMuxFlexpwm2ValueRegsOfSubmodule3 = 69U, /**< FLEXPWM2 Write DMA request for value regs of sub-module3 */
    kDma2RequestMuxFlexpwm4CaptureRegsOfSubmodule0 = 70U, /**< FLEXPWM4 Read DMA request for capture regs of sub-module0 */
    kDma2RequestMuxFlexpwm4CaptureRegsOfSubmodule1 = 71U, /**< FLEXPWM4 Read DMA request for capture regs of sub-module1 */
    kDma2RequestMuxFlexpwm4CaptureRegsOfSubmodule2 = 72U, /**< FLEXPWM4 Read DMA request for capture regs of sub-module2 */
    kDma2RequestMuxFlexpwm4CaptureRegsOfSubmodule3 = 73U, /**< FLEXPWM4 Read DMA request for capture regs of sub-module3 */
    kDma2RequestMuxFlexpwm4ValueRegsOfSubmodule0 = 74U, /**< FLEXPWM4 Write DMA request for value regs of sub-module0 */
    kDma2RequestMuxFlexpwm4ValueRegsOfSubmodule1 = 75U, /**< FLEXPWM4 Write DMA request for value regs of sub-module1 */
    kDma2RequestMuxFlexpwm4ValueRegsOfSubmodule2 = 76U, /**< FLEXPWM4 Write DMA request for value regs of sub-module2 */
    kDma2RequestMuxFlexpwm4ValueRegsOfSubmodule3 = 77U, /**< FLEXPWM4 Write DMA request for value regs of sub-module3 */
    kDma2RequestMuxEnc2 = 78U, /**< nan */
    kDma2RequestMuxEnc4 = 79U, /**< nan */
    kDma2RequestMuxFlexio4Ch0 = 80U, /**< flexio4 Shifter DMA Channel 0 request; flexio4 Timer DMA Channel 0 request */
    kDma2RequestMuxFlexio4Ch1 = 81U, /**< flexio4 Shifter DMA Channel 1 request; flexio4 Timer DMA Channel 1 request */
    kDma2RequestMuxFlexio4Ch2 = 82U, /**< flexio4 Shifter DMA Channel 2 request; flexio4 Timer DMA Channel 2 request */
    kDma2RequestMuxFlexio4Ch3 = 83U, /**< flexio4 Shifter DMA Channel 3 request; flexio4 Timer DMA Channel 3 request */
    kDma2RequestMuxFlexio4Ch4 = 84U, /**< flexio4 Shifter DMA Channel 4 request; flexio4 Timer DMA Channel 4 request */
    kDma2RequestMuxFlexio4Ch5 = 85U, /**< flexio4 Shifter DMA Channel 5 request; flexio4 Timer DMA Channel 5 request */
    kDma2RequestMuxFlexio4Ch6 = 86U, /**< flexio4 Shifter DMA Channel 6 request; flexio4 Timer DMA Channel 6 request */
    kDma2RequestMuxFlexio4Ch7 = 87U, /**< flexio4 Shifter DMA Channel 7 request; flexio4 Timer DMA Channel 7 request */
    kDma2RequestMuxQtimer2CaptInTimer0 = 88U, /**< QUADTIMER2 DMA read request for capt in timer #0 */
    kDma2RequestMuxQtimer2CaptInTimer1 = 89U, /**< QUADTIMER2 DMA read request for capt in timer #1 */
    kDma2RequestMuxQtimer2CaptInTimer2 = 90U, /**< QUADTIMER2 DMA read request for capt in timer #2 */
    kDma2RequestMuxQtimer2CaptInTimer3 = 91U, /**< QUADTIMER2 DMA read request for capt in timer #3 */
    kDma2RequestMuxQtimer2Cmpld1InTimer0Cmpld2InTimer1 = 92U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #0; QUADTIMER2 DMA write request for cmpld2 in timer #1 */
    kDma2RequestMuxQtimer2Cmpld1InTimer1Cmpld2InTimer0 = 93U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #1; QUADTIMER2 DMA write request for cmpld2 in timer #0 */
    kDma2RequestMuxQtimer2Cmpld1InTimer2Cmpld2InTimer3 = 94U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #2; QUADTIMER2 DMA write request for cmpld2 in timer #3 */
    kDma2RequestMuxQtimer2Cmpld1InTimer3Cmpld2InTimer2 = 95U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #3; QUADTIMER2 DMA write request for cmpld2 in timer #2 */
    kDma2RequestMuxQtimer4CaptInTimer0 = 96U, /**< QUADTIMER4 DMA read request for capt in timer #0 */
    kDma2RequestMuxQtimer4CaptInTimer1 = 97U, /**< QUADTIMER4 DMA read request for capt in timer #1 */
    kDma2RequestMuxQtimer4CaptInTimer2 = 98U, /**< QUADTIMER4 DMA read request for capt in timer #2 */
    kDma2RequestMuxQtimer4CaptInTimer3 = 99U, /**< QUADTIMER4 DMA read request for capt in timer #3 */
    kDma2RequestMuxQtimer4Cmpld1InTimer0Cmpld2InTimer1 = 100U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #0; QUADTIMER4 DMA write request for cmpld2 in timer #1 */
    kDma2RequestMuxQtimer4Cmpld1InTimer1Cmpld2InTimer0 = 101U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #1; QUADTIMER4 DMA write request for cmpld2 in timer #0 */
    kDma2RequestMuxQtimer4Cmpld1InTimer2Cmpld2InTimer3 = 102U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #2; QUADTIMER4 DMA write request for cmpld2 in timer #3 */
    kDma2RequestMuxQtimer4Cmpld1InTimer3Cmpld2InTimer2 = 103U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #3; QUADTIMER4 DMA write request for cmpld2 in timer #2 */
    kDma2RequestMuxQtimer6CaptInTimer0 = 104U, /**< QUADTIMER6 DMA read request for capt in timer #0 */
    kDma2RequestMuxQtimer6CaptInTimer1 = 105U, /**< QUADTIMER6 DMA read request for capt in timer #1 */
    kDma2RequestMuxQtimer6CaptInTimer2 = 106U, /**< QUADTIMER6 DMA read request for capt in timer #2 */
    kDma2RequestMuxQtimer6CaptInTimer3 = 107U, /**< QUADTIMER6 DMA read request for capt in timer #3 */
    kDma2RequestMuxQtimer6Cmpld1InTimer0Cmpld2InTimer1 = 108U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #0; QUADTIMER6 DMA write request for cmpld2 in timer #1 */
    kDma2RequestMuxQtimer6Cmpld1InTimer1Cmpld2InTimer0 = 109U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #1; QUADTIMER6 DMA write request for cmpld2 in timer #0 */
    kDma2RequestMuxQtimer6Cmpld1InTimer2Cmpld2InTimer3 = 110U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #2; QUADTIMER6 DMA write request for cmpld2 in timer #3 */
    kDma2RequestMuxQtimer6Cmpld1InTimer3Cmpld2InTimer2 = 111U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #3; QUADTIMER6 DMA write request for cmpld2 in timer #2 */
    kDma2RequestMuxQtimer8CaptInTimer0 = 112U, /**< QUADTIMER8 DMA read request for capt in timer #0 */
    kDma2RequestMuxQtimer8CaptInTimer1 = 113U, /**< QUADTIMER8 DMA read request for capt in timer #1 */
    kDma2RequestMuxQtimer8CaptInTimer2 = 114U, /**< QUADTIMER8 DMA read request for capt in timer #2 */
    kDma2RequestMuxQtimer8CaptInTimer3 = 115U, /**< QUADTIMER8 DMA read request for capt in timer #3 */
    kDma2RequestMuxQtimer8Cmpld1InTimer0Cmpld2InTimer1 = 116U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #0; QUADTIMER8 DMA write request for cmpld2 in timer #1 */
    kDma2RequestMuxQtimer8Cmpld1InTimer1Cmpld2InTimer0 = 117U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #1; QUADTIMER8 DMA write request for cmpld2 in timer #0 */
    kDma2RequestMuxQtimer8Cmpld1InTimer2Cmpld2InTimer3 = 118U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #2; QUADTIMER8 DMA write request for cmpld2 in timer #3 */
    kDma2RequestMuxQtimer8Cmpld1InTimer3 = 119U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #3 */
    kDma2RequestMuxHiperface2SafePos1= 120U, /**< HIPERFACE2 Safe Pos1 */
    kDma2RequestMuxHiperface2FastPos= 121U, /**< HIPERFACE2 Fast Pos */
    kDma2RequestMuxHiperface2SafePos2= 122U, /**< HIPERFACE2 Safe Pos2 */
    kDma2RequestMuxReserved1 = 123U, /**< nan */
} dma2_request_source_t;

/* @brief dma3 request source */
typedef enum _dma3_request_source
{
    kDma3RequestMuxReserved0 = 0U, /**< Default - Channel Disabled (Do Not Re-assign) */
    kDma3RequestMuxCan2 = 1U, /**< CAN-FD 2 DMA request and response */
    kDma3RequestMuxGpio2Ch0 = 2U, /**< GPIO2 channel 0 DMA request and response */
    kDma3RequestMuxGpio2Ch1 = 3U, /**< GPIO2 channel 1 DMA request and response */
    kDma3RequestMuxGpio3Ch0 = 4U, /**< GPIO3 channel 0 DMA request and response */
    kDma3RequestMuxGpio3Ch1 = 5U, /**< GPIO3 channel 1 DMA request and response */
    kDma3RequestMuxI3c2ToBus = 6U, /**< I3C2 "To-bus" DMA request and response */
    kDma3RequestMuxI3c2FromBus = 7U, /**< I3C2 "from-bus" DMA request and response */
    kDma3RequestMuxLpi2c3Tx = 8U, /**< LPI2C3 Master TX DMA request; LPI2C3 Slave TX DMA request */
    kDma3RequestMuxLpi2c3Rx = 9U, /**< LPI2C3 Master RX DMA request; LPI2C3 Slave RX DMA request */
    kDma3RequestMuxLpi2c4Tx = 10U, /**< LPI2C4 Master TX DMA request; LPI2C4 Slave TX DMA request */
    kDma3RequestMuxLpi2c4Rx = 11U, /**< LPI2C4 Master RX DMA request; LPI2C4 Slave RX DMA request */
    kDma3RequestMuxLpspi3Tx = 12U, /**< LPSPI3 TX DMA request */
    kDma3RequestMuxLpspi3Rx = 13U, /**< LPSPI3 RX DMA request */
    kDma3RequestMuxLpspi4Tx = 14U, /**< LPSPI4 TX DMA request */
    kDma3RequestMuxLpspi4Rx = 15U, /**< LPSPI4 RX DMA request */
    kDma3RequestMuxLptmr2 = 16U, /**< LPTIMER2 DMA request and response */
    kDma3RequestMuxLpuart3Tx = 17U, /**< LPUART3 DMA TX request */
    kDma3RequestMuxLpuart3Rx = 18U, /**< LPUART3 DMA RX request and response */
    kDma3RequestMuxLpuart4Tx = 19U, /**< LPUART4 DMA TX request */
    kDma3RequestMuxLpuart4Rx = 20U, /**< LPUART4 DMA RX request and response */
    kDma3RequestMuxLpuart5Tx = 21U, /**< LPUART5 DMA TX request */
    kDma3RequestMuxLpuart5Rx = 22U, /**< LPUART5 DMA RX request and response */
    kDma3RequestMuxLpuart6Tx = 23U, /**< LPUART6 DMA TX request */
    kDma3RequestMuxLpuart6Rx = 24U, /**< LPUART6 DMA RX request and response */
    kDma3RequestMuxTpm3Ch0Ch2 = 25U, /**< LPTPM3 DMA Channel 0 request and response; LPTPM3 DMA Channel 2 request and response */
    kDma3RequestMuxTpm3Ch1Ch3 = 26U, /**< LPTPM3 DMA Channel 1 request and response; LPTPM3 DMA Channel 3 request and response */
    kDma3RequestMuxTpm3Overflow = 27U, /**< LPTPM3 DMA Overflow request and response */
    kDma3RequestMuxTpm4Ch0Ch2 = 28U, /**< LPTPM4 DMA Channel 0 request and response; LPTPM4 DMA Channel 2 request and response */
    kDma3RequestMuxTpm4Ch1Ch3 = 29U, /**< LPTPM4 DMA Channel 1 request and response; LPTPM4 DMA Channel 3 request and response */
    kDma3RequestMuxTpm4Overflow = 30U, /**< LPTPM4 DMA Overflow request and response */
    kDma3RequestMuxTpm5Ch0Ch2 = 31U, /**< LPTPM5 DMA Channel 0 request and response; LPTPM5 DMA Channel 2 request and response */
    kDma3RequestMuxTpm5Ch1Ch3 = 32U, /**< LPTPM5 DMA Channel 1 request and response; LPTPM5 DMA Channel 3 request and response */
    kDma3RequestMuxTpm5Overflow = 33U, /**< LPTPM5 DMA Overflow request and response */
    kDma3RequestMuxTpm6Ch0Ch2 = 34U, /**< LPTPM6 DMA Channel 0 request and response; LPTPM6 DMA Channel 2 request and response */
    kDma3RequestMuxTpm6Ch1Ch3 = 35U, /**< LPTPM6 DMA Channel 1 request and response; LPTPM6 DMA Channel 3 request and response */
    kDma3RequestMuxTpm6Overflow = 36U, /**< LPTPM6 DMA Overflow request and response */
    kDma3RequestMuxFlexio1Ch0 = 37U, /**< FLEXIO1 Shifter DMA Channel 0 request; FLEXIO1 Timer DMA Channel 0 request */
    kDma3RequestMuxFlexio1Ch1 = 38U, /**< FLEXIO1 Shifter DMA Channel 1 request; FLEXIO1 Timer DMA Channel 1 request */
    kDma3RequestMuxFlexio1Ch2 = 39U, /**< FLEXIO1 Shifter DMA Channel 2 request; FLEXIO1 Timer DMA Channel 2 request */
    kDma3RequestMuxFlexio1Ch3 = 40U, /**< FLEXIO1 Shifter DMA Channel 3 request; FLEXIO1 Timer DMA Channel 3 request */
    kDma3RequestMuxFlexio1Ch4 = 41U, /**< FLEXIO1 Shifter DMA Channel 4 request; FLEXIO1 Timer DMA Channel 4 request */
    kDma3RequestMuxFlexio1Ch5 = 42U, /**< FLEXIO1 Shifter DMA Channel 5 request; FLEXIO1 Timer DMA Channel 5 request */
    kDma3RequestMuxFlexio1Ch6 = 43U, /**< FLEXIO1 Shifter DMA Channel 6 request; FLEXIO1 Timer DMA Channel 6 request */
    kDma3RequestMuxFlexio1Ch7 = 44U, /**< FLEXIO1 Shifter DMA Channel 7 request; FLEXIO1 Timer DMA Channel 7 request */
    kDma3RequestMuxFlexio2Ch0 = 45U, /**< FLEXIO2 Shifter DMA Channel 0 request; FLEXIO2 Timer DMA Channel 0 request */
    kDma3RequestMuxFlexio2Ch1 = 46U, /**< FLEXIO2 Shifter DMA Channel 1 request; FLEXIO2 Timer DMA Channel 1 request */
    kDma3RequestMuxFlexio2Ch2 = 47U, /**< FLEXIO2 Shifter DMA Channel 2 request; FLEXIO2 Timer DMA Channel 2 request */
    kDma3RequestMuxFlexio2Ch3 = 48U, /**< FLEXIO2 Shifter DMA Channel 3 request; FLEXIO2 Timer DMA Channel 3 request */
    kDma3RequestMuxFlexio2Ch4 = 49U, /**< FLEXIO2 Shifter DMA Channel 4 request; FLEXIO2 Timer DMA Channel 4 request */
    kDma3RequestMuxFlexio2Ch5 = 50U, /**< FLEXIO2 Shifter DMA Channel 5 request; FLEXIO2 Timer DMA Channel 5 request */
    kDma3RequestMuxFlexio2Ch6 = 51U, /**< FLEXIO2 Shifter DMA Channel 6 request; FLEXIO2 Timer DMA Channel 6 request */
    kDma3RequestMuxFlexio2Ch7 = 52U, /**< FLEXIO2 Shifter DMA Channel 7 request; FLEXIO2 Timer DMA Channel 7 request */
    kDma3RequestMuxFlexspi1Tx = 53U, /**< FLEXSPI1 DMA TX request */
    kDma3RequestMuxFlexspi1Rx = 54U, /**< FLEXSPI1 DMA RX request */
    kDma3RequestMuxGpio5Ch0 = 55U, /**< GPIO5 channel 0 DMA request and response */
    kDma3RequestMuxGpio5Ch1 = 56U, /**< GPIO5 channel 1 DMA request and response */
    kDma3RequestMuxCan3 = 57U, /**< CAN-FD 3 DMA request and response */
    kDma3RequestMuxSai2Tx = 58U, /**< SAI2 TX DMA request and response */
    kDma3RequestMuxSai2Rx = 59U, /**< SAI2 RX DMA request and response */
    kDma3RequestMuxSai3Tx = 60U, /**< SAI3 TX DMA request and response */
    kDma3RequestMuxSai3Rx = 61U, /**< SAI3 RX DMA request and response */
    kDma3RequestMuxGpio4Ch0 = 62U, /**< GPIO4 channel 0 DMA request and response */
    kDma3RequestMuxGpio4Ch1 = 63U, /**< GPIO4 channel 1 DMA request and response */
    kDma3RequestMuxSai4Tx = 64U, /**< SAI4 TX DMA request and response */
    kDma3RequestMuxSai4Rx = 65U, /**< SAI4 RX DMA request and response */
    kDma3RequestMuxLpi2c5Tx = 66U, /**< LPI2C5 Master TX DMA request; LPI2C5 Slave TX DMA request */
    kDma3RequestMuxLpi2c5Rx = 67U, /**< LPI2C5 Master RX DMA request; LPI2C5 Slave RX DMA request */
    kDma3RequestMuxLpi2c6Tx = 68U, /**< LPI2C6 Master TX DMA request; LPI2C6 Slave TX DMA request */
    kDma3RequestMuxLpi2c6Rx = 69U, /**< LPI2C6 Master RX DMA request; LPI2C6 Slave RX DMA request */
    kDma3RequestMuxLpi2c7Tx = 70U, /**< LPI2C7 Master TX DMA request; LPI2C7 Slave TX DMA request */
    kDma3RequestMuxLpi2c7Rx = 71U, /**< LPI2C7 Master RX DMA request; LPI2C7 Slave RX DMA request */
    kDma3RequestMuxLpi2c8Tx = 72U, /**< LPI2C8 Master TX DMA request; LPI2C8 Slave TX DMA request */
    kDma3RequestMuxLpi2c8Rx = 73U, /**< LPI2C8 Master RX DMA request; LPI2C8 Slave RX DMA request */
    kDma3RequestMuxLpspi5Tx = 74U, /**< LPSPI5 TX DMA request */
    kDma3RequestMuxLpspi5Rx = 75U, /**< LPSPI5 RX DMA request */
    kDma3RequestMuxLpspi6Tx = 76U, /**< LPSPI6 TX DMA request */
    kDma3RequestMuxLpspi6Rx = 77U, /**< LPSPI6 RX DMA request */
    kDma3RequestMuxLpspi7Tx = 78U, /**< LPSPI7 TX DMA request */
    kDma3RequestMuxLpspi7Rx = 79U, /**< LPSPI7 RX DMA request */
    kDma3RequestMuxLpspi8Tx = 80U, /**< LPSPI8 TX DMA request */
    kDma3RequestMuxLpspi8Rx = 81U, /**< LPSPI8 RX DMA request */
    kDma3RequestMuxLpuart7Tx = 82U, /**< LPUART7 DMA TX request */
    kDma3RequestMuxLpuart7Rx = 83U, /**< LPUART7 DMA RX request and response */
    kDma3RequestMuxLpuart8Tx = 84U, /**< LPUART8 DMA TX request */
    kDma3RequestMuxLpuart8Rx = 85U, /**< LPUART8 DMA RX request and response */
    kDma3RequestMuxCan4 = 86U, /**< CAN-FD 4 DMA request and response */
    kDma3RequestMuxCan5 = 87U, /**< CAN-FD 5 DMA request and response */
    kDma3RequestMuxV2xfh = 88U, /**< V2X_FH DMA request */
    kDma3RequestMuxFlexspi2Tx = 89U, /**< FLEXSPI2 DMA TX request */
    kDma3RequestMuxFlexspi2Rx = 90U, /**< FLEXSPI2 DMA RX request */
    kDma3RequestMuxGpio6Ch0 = 91U, /**< GPIO6 channel 0 DMA request and response */
    kDma3RequestMuxGpio6Ch1 = 92U, /**< GPIO6 channel 1 DMA request and response */
    kDma3RequestMuxGpio7Ch0 = 93U, /**< GPIO7 channel 0 DMA request and response */
    kDma3RequestMuxGpio7Ch1 = 94U, /**< GPIO7 channel 1 DMA request and response */
    kDma3RequestMuxLpuart9Tx = 95U, /**< LPUART9 DMA TX request */
    kDma3RequestMuxLpuart9Rx = 96U, /**< LPUART9 DMA RX request and response */
    kDma3RequestMuxLpuart10Tx = 97U, /**< LPUART10 DMA TX request */
    kDma3RequestMuxLpuart10Rx = 98U, /**< LPUART10 DMA RX request and response */
    kDma3RequestMuxLpuart11Tx = 99U, /**< LPUART11 DMA TX request */
    kDma3RequestMuxLpuart11Rx = 100U, /**< LPUART11 DMA RX request and response */
    kDma3RequestMuxLpuart12Tx = 101U, /**< LPUART12 DMA TX request */
    kDma3RequestMuxLpuart12Rx = 102U, /**< LPUART12 DMA RX request and response */
    kDma3RequestMuxFlexio3Ch0 = 103U, /**< flexio3 Shifter DMA Channel 0 request; flexio3 Timer DMA Channel 0 request */
    kDma3RequestMuxFlexio3Ch1 = 104U, /**< flexio3 Shifter DMA Channel 1 request; flexio3 Timer DMA Channel 1 request */
    kDma3RequestMuxFlexio3Ch2 = 105U, /**< flexio3 Shifter DMA Channel 2 request; flexio3 Timer DMA Channel 2 request */
    kDma3RequestMuxFlexio3Ch3 = 106U, /**< flexio3 Shifter DMA Channel 3 request; flexio3 Timer DMA Channel 3 request */
    kDma3RequestMuxFlexio3Ch4 = 107U, /**< flexio3 Shifter DMA Channel 4 request; flexio3 Timer DMA Channel 4 request */
    kDma3RequestMuxFlexio3Ch5 = 108U, /**< flexio3 Shifter DMA Channel 5 request; flexio3 Timer DMA Channel 5 request */
    kDma3RequestMuxFlexio3Ch6 = 109U, /**< flexio3 Shifter DMA Channel 6 request; flexio3 Timer DMA Channel 6 request */
    kDma3RequestMuxFlexio3Ch7 = 110U, /**< flexio3 Shifter DMA Channel 7 request; flexio3 Timer DMA Channel 7 request */
    kDma3RequestMuxFlexio4Ch0 = 111U, /**< flexio4 Shifter DMA Channel 0 request; flexio4 Timer DMA Channel 0 request */
    kDma3RequestMuxFlexio4Ch1 = 112U, /**< flexio4 Shifter DMA Channel 1 request; flexio4 Timer DMA Channel 1 request */
    kDma3RequestMuxFlexio4Ch2 = 113U, /**< flexio4 Shifter DMA Channel 2 request; flexio4 Timer DMA Channel 2 request */
    kDma3RequestMuxFlexio4Ch3 = 114U, /**< flexio4 Shifter DMA Channel 3 request; flexio4 Timer DMA Channel 3 request */
    kDma3RequestMuxFlexio4Ch4 = 115U, /**< flexio4 Shifter DMA Channel 4 request; flexio4 Timer DMA Channel 4 request */
    kDma3RequestMuxFlexio4Ch5 = 116U, /**< flexio4 Shifter DMA Channel 5 request; flexio4 Timer DMA Channel 5 request */
    kDma3RequestMuxFlexio4Ch6 = 117U, /**< flexio4 Shifter DMA Channel 6 request; flexio4 Timer DMA Channel 6 request */
    kDma3RequestMuxFlexio4Ch7 = 118U, /**< flexio4 Shifter DMA Channel 7 request; flexio4 Timer DMA Channel 7 request */
    kDma3RequestMuxQtimer1CaptInTimer0 = 119U, /**< QUADTIMER1 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer1CaptInTimer1 = 120U, /**< QUADTIMER1 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer1CaptInTimer2 = 121U, /**< QUADTIMER1 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer1CaptInTimer3 = 122U, /**< QUADTIMER1 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer1Cmpld1InTimer0Cmpld2InTimer1 = 123U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #0; QUADTIMER1 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer1Cmpld1InTimer1Cmpld2InTimer0 = 124U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #1; QUADTIMER1 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer1Cmpld1InTimer2Cmpld2InTimer3 = 125U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #2; QUADTIMER1 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer1Cmpld1InTimer3Cmpld2InTimer2 = 126U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #3; QUADTIMER1 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer2CaptInTimer0 = 127U, /**< QUADTIMER2 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer2CaptInTimer1 = 128U, /**< QUADTIMER2 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer2CaptInTimer2 = 129U, /**< QUADTIMER2 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer2CaptInTimer3 = 130U, /**< QUADTIMER2 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer2Cmpld1InTimer0Cmpld2InTimer1 = 131U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #0; QUADTIMER2 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer2Cmpld1InTimer1Cmpld2InTimer0 = 132U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #1; QUADTIMER2 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer2Cmpld1InTimer2Cmpld2InTimer3 = 133U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #2; QUADTIMER2 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer2Cmpld1InTimer3Cmpld2InTimer2 = 134U, /**< QUADTIMER2 DMA write request for cmpld1 in timer #3; QUADTIMER2 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer3CaptInTimer0 = 135U, /**< QUADTIMER3 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer3CaptInTimer1 = 136U, /**< QUADTIMER3 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer3CaptInTimer2 = 137U, /**< QUADTIMER3 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer3CaptInTimer3 = 138U, /**< QUADTIMER3 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer3Cmpld1InTimer0Cmpld2InTimer1 = 139U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #0; QUADTIMER3 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer3Cmpld1InTimer1Cmpld2InTimer0 = 140U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #1; QUADTIMER3 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer3Cmpld1InTimer2Cmpld2InTimer3 = 141U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #2; QUADTIMER3 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer3Cmpld1InTimer3Cmpld2InTimer2 = 142U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #3; QUADTIMER3 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer4CaptInTimer0 = 143U, /**< QUADTIMER4 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer4CaptInTimer1 = 144U, /**< QUADTIMER4 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer4CaptInTimer2 = 145U, /**< QUADTIMER4 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer4CaptInTimer3 = 146U, /**< QUADTIMER4 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer4Cmpld1InTimer0Cmpld2InTimer1 = 147U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #0; QUADTIMER4 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer4Cmpld1InTimer1Cmpld2InTimer0 = 148U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #1; QUADTIMER4 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer4Cmpld1InTimer2Cmpld2InTimer3 = 149U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #2; QUADTIMER4 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer4Cmpld1InTimer3Cmpld2InTimer2 = 150U, /**< QUADTIMER4 DMA write request for cmpld1 in timer #3; QUADTIMER4 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer5CaptInTimer0 = 151U, /**< QUADTIMER5 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer5CaptInTimer1 = 152U, /**< QUADTIMER5 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer5CaptInTimer2 = 153U, /**< QUADTIMER5 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer5CaptInTimer3 = 154U, /**< QUADTIMER5 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer5Cmpld1InTimer0Cmpld2InTimer1 = 155U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #0; QUADTIMER5 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer5Cmpld1InTimer1Cmpld2InTimer0 = 156U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #1; QUADTIMER5 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer5Cmpld1InTimer2Cmpld2InTimer3 = 157U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #2; QUADTIMER5 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer5Cmpld1InTimer3Cmpld2InTimer2 = 158U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #3; QUADTIMER5 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer6CaptInTimer0 = 159U, /**< QUADTIMER6 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer6CaptInTimer1 = 160U, /**< QUADTIMER6 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer6CaptInTimer2 = 161U, /**< QUADTIMER6 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer6CaptInTimer3 = 162U, /**< QUADTIMER6 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer6Cmpld1InTimer0Cmpld2InTimer1 = 163U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #0; QUADTIMER6 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer6Cmpld1InTimer1Cmpld2InTimer0 = 164U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #1; QUADTIMER6 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer6Cmpld1InTimer2Cmpld2InTimer3 = 165U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #2; QUADTIMER6 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer6Cmpld1InTimer3Cmpld2InTimer2 = 166U, /**< QUADTIMER6 DMA write request for cmpld1 in timer #3; QUADTIMER6 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer7CaptInTimer0 = 167U, /**< QUADTIMER7 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer7CaptInTimer1 = 168U, /**< QUADTIMER7 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer7CaptInTimer2 = 169U, /**< QUADTIMER7 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer7CaptInTimer3 = 170U, /**< QUADTIMER7 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer7Cmpld1InTimer0Cmpld2InTimer1 = 171U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #0; QUADTIMER7 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer7Cmpld1InTimer1Cmpld2InTimer0 = 172U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #1; QUADTIMER7 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer7Cmpld1InTimer2Cmpld2InTimer3 = 173U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #2; QUADTIMER7 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer7Cmpld1InTimer3Cmpld2InTimer2 = 174U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #3; QUADTIMER7 DMA write request for cmpld2 in timer #2 */
    kDma3RequestMuxQtimer8CaptInTimer0 = 175U, /**< QUADTIMER8 DMA read request for capt in timer #0 */
    kDma3RequestMuxQtimer8CaptInTimer1 = 176U, /**< QUADTIMER8 DMA read request for capt in timer #1 */
    kDma3RequestMuxQtimer8CaptInTimer2 = 177U, /**< QUADTIMER8 DMA read request for capt in timer #2 */
    kDma3RequestMuxQtimer8CaptInTimer3 = 178U, /**< QUADTIMER8 DMA read request for capt in timer #3 */
    kDma3RequestMuxQtimer8Cmpld1InTimer0Cmpld2InTimer1 = 179U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #0; QUADTIMER8 DMA write request for cmpld2 in timer #1 */
    kDma3RequestMuxQtimer8Cmpld1InTimer1Cmpld2InTimer0 = 180U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #1; QUADTIMER8 DMA write request for cmpld2 in timer #0 */
    kDma3RequestMuxQtimer8Cmpld1InTimer2Cmpld2InTimer3 = 181U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #2; QUADTIMER8 DMA write request for cmpld2 in timer #3 */
    kDma3RequestMuxQtimer8Cmpld1InTimer3 = 182U, /**< QUADTIMER8 DMA write request for cmpld1 in timer #3 */
    kDma3RequestMuxReserved1 = 183U, /**< nan */
} dma3_request_source_t;

/* @brief dma4 request source */
typedef enum _dma4_request_source
{
    kDma4RequestMuxReserved0 = 0U, /**< Default - Channel Disabled (Do Not Re-assign) */
    kDma4RequestMuxCan2 = 1U, /**< CAN-FD 2 DMA request and response */
    kDma4RequestMuxGpio3Ch0 = 2U, /**< GPIO3 channel 0 DMA request and response */
    kDma4RequestMuxGpio3Ch1 = 3U, /**< GPIO3 channel 1 DMA request and response */
    kDma4RequestMuxLpi2c4Tx = 4U, /**< LPI2C4 Master TX DMA request; LPI2C4 Slave TX DMA request */
    kDma4RequestMuxLpi2c4Rx = 5U, /**< LPI2C4 Master RX DMA request; LPI2C4 Slave RX DMA request */
    kDma4RequestMuxLpspi4Tx = 6U, /**< LPSPI4 TX DMA request */
    kDma4RequestMuxLpspi4Rx = 7U, /**< LPSPI4 RX DMA request */
    kDma4RequestMuxLptmr2 = 8U, /**< LPTIMER2 DMA request and response */
    kDma4RequestMuxLpuart4Tx = 9U, /**< LPUART4 DMA TX request */
    kDma4RequestMuxLpuart4Rx = 10U, /**< LPUART4 DMA RX request and response */
    kDma4RequestMuxLpuart6Tx = 11U, /**< LPUART6 DMA TX request */
    kDma4RequestMuxLpuart6Rx = 12U, /**< LPUART6 DMA RX request and response */
    kDma4RequestMuxTpm4Ch0Ch2 = 13U, /**< LPTPM4 DMA Channel 0 request and response; LPTPM4 DMA Channel 2 request and response */
    kDma4RequestMuxTpm4Ch1Ch3 = 14U, /**< LPTPM4 DMA Channel 1 request and response; LPTPM4 DMA Channel 3 request and response */
    kDma4RequestMuxTpm4Overflow = 15U, /**< LPTPM4 DMA Overflow request and response */
    kDma4RequestMuxTpm6Ch0Ch2 = 16U, /**< LPTPM6 DMA Channel 0 request and response; LPTPM6 DMA Channel 2 request and response */
    kDma4RequestMuxTpm6Ch1Ch3 = 17U, /**< LPTPM6 DMA Channel 1 request and response; LPTPM6 DMA Channel 3 request and response */
    kDma4RequestMuxTpm6Overflow = 18U, /**< LPTPM6 DMA Overflow request and response */
    kDma4RequestMuxFlexio1Ch0 = 19U, /**< FLEXIO1 Shifter DMA Channel 0 request; FLEXIO1 Timer DMA Channel 0 request */
    kDma4RequestMuxFlexio1Ch1 = 20U, /**< FLEXIO1 Shifter DMA Channel 1 request; FLEXIO1 Timer DMA Channel 1 request */
    kDma4RequestMuxFlexio1Ch2 = 21U, /**< FLEXIO1 Shifter DMA Channel 2 request; FLEXIO1 Timer DMA Channel 2 request */
    kDma4RequestMuxFlexio1Ch3 = 22U, /**< FLEXIO1 Shifter DMA Channel 3 request; FLEXIO1 Timer DMA Channel 3 request */
    kDma4RequestMuxFlexio1Ch4 = 23U, /**< FLEXIO1 Shifter DMA Channel 4 request; FLEXIO1 Timer DMA Channel 4 request */
    kDma4RequestMuxFlexio1Ch5 = 24U, /**< FLEXIO1 Shifter DMA Channel 5 request; FLEXIO1 Timer DMA Channel 5 request */
    kDma4RequestMuxFlexio1Ch6 = 25U, /**< FLEXIO1 Shifter DMA Channel 6 request; FLEXIO1 Timer DMA Channel 6 request */
    kDma4RequestMuxFlexio1Ch7 = 26U, /**< FLEXIO1 Shifter DMA Channel 7 request; FLEXIO1 Timer DMA Channel 7 request */
    kDma4RequestMuxGpio5Ch0 = 27U, /**< GPIO5 channel 0 DMA request and response */
    kDma4RequestMuxGpio5Ch1 = 28U, /**< GPIO5 channel 1 DMA request and response */
    kDma4RequestMuxCan3 = 29U, /**< CAN-FD 3 DMA request and response */
    kDma4RequestMuxLpi2c6Tx = 30U, /**< LPI2C6 Master TX DMA request; LPI2C6 Slave TX DMA request */
    kDma4RequestMuxLpi2c6Rx = 31U, /**< LPI2C6 Master RX DMA request; LPI2C6 Slave RX DMA request */
    kDma4RequestMuxLpi2c8Tx = 32U, /**< LPI2C8 Master TX DMA request; LPI2C8 Slave TX DMA request */
    kDma4RequestMuxLpi2c8Rx = 33U, /**< LPI2C8 Master RX DMA request; LPI2C8 Slave RX DMA request */
    kDma4RequestMuxLpspi6Tx = 34U, /**< LPSPI6 TX DMA request */
    kDma4RequestMuxLpspi6Rx = 35U, /**< LPSPI6 RX DMA request */
    kDma4RequestMuxLpspi8Tx = 36U, /**< LPSPI8 TX DMA request */
    kDma4RequestMuxLpspi8Rx = 37U, /**< LPSPI8 RX DMA request */
    kDma4RequestMuxLpuart8Tx = 38U, /**< LPUART8 DMA TX request */
    kDma4RequestMuxLpuart8Rx = 39U, /**< LPUART8 DMA RX request and response */
    kDma4RequestMuxCan4 = 40U, /**< CAN-FD 4 DMA request and response */
    kDma4RequestMuxCan5 = 41U, /**< CAN-FD 5 DMA request and response */
    kDma4RequestMuxXspi2Tx = 42U, /**< xspi2 DMA TX request */
    kDma4RequestMuxXspi2Rx = 43U, /**< xspi2 DMA RX request */
    kDma4RequestMuxGpio7Ch0 = 44U, /**< GPIO7 channel 0 DMA request and response */
    kDma4RequestMuxGpio7Ch1 = 45U, /**< GPIO7 channel 1 DMA request and response */
    kDma4RequestMuxLpuart10Tx = 46U, /**< LPUART10 DMA TX request */
    kDma4RequestMuxLpuart10Rx = 47U, /**< LPUART10 DMA RX request and response */
    kDma4RequestMuxLpuart12Tx = 48U, /**< LPUART12 DMA TX request */
    kDma4RequestMuxLpuart12Rx = 49U, /**< LPUART12 DMA RX request and response */
    kDma4RequestMuxSinc1Ch0 = 50U, /**< nan */
    kDma4RequestMuxSinc1Ch1 = 51U, /**< nan */
    kDma4RequestMuxSinc1Ch2 = 52U, /**< nan */
    kDma4RequestMuxSinc1Ch3 = 53U, /**< nan */
    kDma4RequestMuxSinc3Ch0 = 54U, /**< nan */
    kDma4RequestMuxSinc3Ch1 = 55U, /**< nan */
    kDma4RequestMuxSinc3Ch2 = 56U, /**< nan */
    kDma4RequestMuxSinc3Ch3 = 57U, /**< nan */
    kDma4RequestMuxFlexpwm1CaptureRegsOfSubmodule0 = 58U, /**< FLEXPWM1 Read DMA request for capture regs of sub-module0 */
    kDma4RequestMuxFlexpwm1CaptureRegsOfSubmodule1 = 59U, /**< FLEXPWM1 Read DMA request for capture regs of sub-module1 */
    kDma4RequestMuxFlexpwm1CaptureRegsOfSubmodule2 = 60U, /**< FLEXPWM1 Read DMA request for capture regs of sub-module2 */
    kDma4RequestMuxFlexpwm1CaptureRegsOfSubmodule3 = 61U, /**< FLEXPWM1 Read DMA request for capture regs of sub-module3 */
    kDma4RequestMuxFlexpwm1ValueRegsOfSubmodule0 = 62U, /**< FLEXPWM1 Write DMA request for value regs of sub-module0 */
    kDma4RequestMuxFlexpwm1ValueRegsOfSubmodule1 = 63U, /**< FLEXPWM1 Write DMA request for value regs of sub-module1 */
    kDma4RequestMuxFlexpwm1ValueRegsOfSubmodule2 = 64U, /**< FLEXPWM1 Write DMA request for value regs of sub-module2 */
    kDma4RequestMuxFlexpwm1ValueRegsOfSubmodule3 = 65U, /**< FLEXPWM1 Write DMA request for value regs of sub-module3 */
    kDma4RequestMuxFlexpwm3CaptureRegsOfSubmodule0 = 66U, /**< FLEXPWM3 Read DMA request for capture regs of sub-module0 */
    kDma4RequestMuxFlexpwm3CaptureRegsOfSubmodule1 = 67U, /**< FLEXPWM3 Read DMA request for capture regs of sub-module1 */
    kDma4RequestMuxFlexpwm3CaptureRegsOfSubmodule2 = 68U, /**< FLEXPWM3 Read DMA request for capture regs of sub-module2 */
    kDma4RequestMuxFlexpwm3CaptureRegsOfSubmodule3 = 69U, /**< FLEXPWM3 Read DMA request for capture regs of sub-module3 */
    kDma4RequestMuxFlexpwm3ValueRegsOfSubmodule0 = 70U, /**< FLEXPWM3 Write DMA request for value regs of sub-module0 */
    kDma4RequestMuxFlexpwm3ValueRegsOfSubmodule1 = 71U, /**< FLEXPWM3 Write DMA request for value regs of sub-module1 */
    kDma4RequestMuxFlexpwm3ValueRegsOfSubmodule2 = 72U, /**< FLEXPWM3 Write DMA request for value regs of sub-module2 */
    kDma4RequestMuxFlexpwm3ValueRegsOfSubmodule3 = 73U, /**< FLEXPWM3 Write DMA request for value regs of sub-module3 */
    kDma4RequestMuxEnc1 = 74U, /**< nan */
    kDma4RequestMuxEnc3 = 75U, /**< nan */
    kDma4RequestMuxXbar1Ch0 = 76U, /**< XBAR DMA request 0 */
    kDma4RequestMuxXbar1Ch1 = 77U, /**< XBAR DMA request 1 */
    kDma4RequestMuxXbar1Ch2 = 78U, /**< XBAR DMA request 2 */
    kDma4RequestMuxXbar1Ch3 = 79U, /**< XBAR DMA request 3 */
    kDma4RequestMuxFlexio3Ch0 = 80U, /**< flexio3 Shifter DMA Channel 0 request; flexio3 Timer DMA Channel 0 request */
    kDma4RequestMuxFlexio3Ch1 = 81U, /**< flexio3 Shifter DMA Channel 1 request; flexio3 Timer DMA Channel 1 request */
    kDma4RequestMuxFlexio3Ch2 = 82U, /**< flexio3 Shifter DMA Channel 2 request; flexio3 Timer DMA Channel 2 request */
    kDma4RequestMuxFlexio3Ch3 = 83U, /**< flexio3 Shifter DMA Channel 3 request; flexio3 Timer DMA Channel 3 request */
    kDma4RequestMuxFlexio3Ch4 = 84U, /**< flexio3 Shifter DMA Channel 4 request; flexio3 Timer DMA Channel 4 request */
    kDma4RequestMuxFlexio3Ch5 = 85U, /**< flexio3 Shifter DMA Channel 5 request; flexio3 Timer DMA Channel 5 request */
    kDma4RequestMuxFlexio3Ch6 = 86U, /**< flexio3 Shifter DMA Channel 6 request; flexio3 Timer DMA Channel 6 request */
    kDma4RequestMuxFlexio3Ch7 = 87U, /**< flexio3 Shifter DMA Channel 7 request; flexio3 Timer DMA Channel 7 request */
    kDma4RequestMuxQtimer1CaptInTimer0 = 88U, /**< QUADTIMER1 DMA read request for capt in timer #0 */
    kDma4RequestMuxQtimer1CaptInTimer1 = 89U, /**< QUADTIMER1 DMA read request for capt in timer #1 */
    kDma4RequestMuxQtimer1CaptInTimer2 = 90U, /**< QUADTIMER1 DMA read request for capt in timer #2 */
    kDma4RequestMuxQtimer1CaptInTimer3 = 91U, /**< QUADTIMER1 DMA read request for capt in timer #3 */
    kDma4RequestMuxQtimer1Cmpld1InTimer0Cmpld2InTimer1 = 92U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #0; QUADTIMER1 DMA write request for cmpld2 in timer #1 */
    kDma4RequestMuxQtimer1Cmpld1InTimer1Cmpld2InTimer0 = 93U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #1; QUADTIMER1 DMA write request for cmpld2 in timer #0 */
    kDma4RequestMuxQtimer1Cmpld1InTimer2Cmpld2InTimer3 = 94U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #2; QUADTIMER1 DMA write request for cmpld2 in timer #3 */
    kDma4RequestMuxQtimer1Cmpld1InTimer3Cmpld2InTimer2 = 95U, /**< QUADTIMER1 DMA write request for cmpld1 in timer #3; QUADTIMER1 DMA write request for cmpld2 in timer #2 */
    kDma4RequestMuxQtimer3CaptInTimer0 = 96U, /**< QUADTIMER3 DMA read request for capt in timer #0 */
    kDma4RequestMuxQtimer3CaptInTimer1 = 97U, /**< QUADTIMER3 DMA read request for capt in timer #1 */
    kDma4RequestMuxQtimer3CaptInTimer2 = 98U, /**< QUADTIMER3 DMA read request for capt in timer #2 */
    kDma4RequestMuxQtimer3CaptInTimer3 = 99U, /**< QUADTIMER3 DMA read request for capt in timer #3 */
    kDma4RequestMuxQtimer3Cmpld1InTimer0Cmpld2InTimer1 = 100U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #0; QUADTIMER3 DMA write request for cmpld2 in timer #1 */
    kDma4RequestMuxQtimer3Cmpld1InTimer1Cmpld2InTimer0 = 101U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #1; QUADTIMER3 DMA write request for cmpld2 in timer #0 */
    kDma4RequestMuxQtimer3Cmpld1InTimer2Cmpld2InTimer3 = 102U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #2; QUADTIMER3 DMA write request for cmpld2 in timer #3 */
    kDma4RequestMuxQtimer3Cmpld1InTimer3Cmpld2InTimer2 = 103U, /**< QUADTIMER3 DMA write request for cmpld1 in timer #3; QUADTIMER3 DMA write request for cmpld2 in timer #2 */
    kDma4RequestMuxQtimer5CaptInTimer0 = 104U, /**< QUADTIMER5 DMA read request for capt in timer #0 */
    kDma4RequestMuxQtimer5CaptInTimer1 = 105U, /**< QUADTIMER5 DMA read request for capt in timer #1 */
    kDma4RequestMuxQtimer5CaptInTimer2 = 106U, /**< QUADTIMER5 DMA read request for capt in timer #2 */
    kDma4RequestMuxQtimer5CaptInTimer3 = 107U, /**< QUADTIMER5 DMA read request for capt in timer #3 */
    kDma4RequestMuxQtimer5Cmpld1InTimer0Cmpld2InTimer1 = 108U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #0; QUADTIMER5 DMA write request for cmpld2 in timer #1 */
    kDma4RequestMuxQtimer5Cmpld1InTimer1Cmpld2InTimer0 = 109U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #1; QUADTIMER5 DMA write request for cmpld2 in timer #0 */
    kDma4RequestMuxQtimer5Cmpld1InTimer2Cmpld2InTimer3 = 110U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #2; QUADTIMER5 DMA write request for cmpld2 in timer #3 */
    kDma4RequestMuxQtimer5Cmpld1InTimer3Cmpld2InTimer2 = 111U, /**< QUADTIMER5 DMA write request for cmpld1 in timer #3; QUADTIMER5 DMA write request for cmpld2 in timer #2 */
    kDma4RequestMuxQtimer7CaptInTimer0 = 112U, /**< QUADTIMER7 DMA read request for capt in timer #0 */
    kDma4RequestMuxQtimer7CaptInTimer1 = 113U, /**< QUADTIMER7 DMA read request for capt in timer #1 */
    kDma4RequestMuxQtimer7CaptInTimer2 = 114U, /**< QUADTIMER7 DMA read request for capt in timer #2 */
    kDma4RequestMuxQtimer7CaptInTimer3 = 115U, /**< QUADTIMER7 DMA read request for capt in timer #3 */
    kDma4RequestMuxQtimer7Cmpld1InTimer0Cmpld2InTimer1 = 116U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #0; QUADTIMER7 DMA write request for cmpld2 in timer #1 */
    kDma4RequestMuxQtimer7Cmpld1InTimer1Cmpld2InTimer0 = 117U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #1; QUADTIMER7 DMA write request for cmpld2 in timer #0 */
    kDma4RequestMuxQtimer7Cmpld1InTimer2Cmpld2InTimer3 = 118U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #2; QUADTIMER7 DMA write request for cmpld2 in timer #3 */
    kDma4RequestMuxQtimer7Cmpld1InTimer3Cmpld2InTimer2 = 119U, /**< QUADTIMER7 DMA write request for cmpld1 in timer #3; QUADTIMER7 DMA write request for cmpld2 in timer #2 */
    kDma4RequestMuxHiperface1SafePos1 = 120U, /**< HIPERFACE1 Safe Pos1 */
    kDma4RequestMuxHiperface1FastPos = 121U, /**< HIPERFACE1 Fast Pos */
    kDma4RequestMuxHiperface1SafePos2 = 122U, /**< HIPERFACE1 Safe Pos2 */
    kDma4RequestMuxReserved1 = 123U, /**< nan */
} dma4_request_source_t;

/*!< Verify dma base and request source */
#define EDMA_CHANNEL_HAS_REQUEST_SOURCE(base, source) ((base) == EDMA1 ? ((source)&0x100U) : ((source)&0x200U))

/*!@brief EDMA base address convert macro */
#define EDMA_CHANNEL_OFFSET           0x10000U
#define EDMA_CHANNEL_ARRAY_STEP(base) ((base) == EDMA1 ? 0x10000U : 0x8000U)

/*******************************************************************************
 * API
 ******************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

/*!
 * @}
 */

#endif /* _FSL_EDMA_SOC_H_ */
