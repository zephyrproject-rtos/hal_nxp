/*
** ###################################################################
**     Processors:          MIMXRT1181CVP2B
**                          MIMXRT1181CVP2C
**                          MIMXRT1181XVP2B
**                          MIMXRT1181XVP2C
**                          MIMXRT1182CVP2B
**                          MIMXRT1182CVP2C
**                          MIMXRT1182XVP2B
**                          MIMXRT1182XVP2C
**                          MIMXRT1186CVJ8C_cm33
**                          MIMXRT1186CVJ8C_cm7
**                          MIMXRT1186XVJ8C_cm33
**                          MIMXRT1186XVJ8C_cm7
**                          MIMXRT1187AVM8B_cm33
**                          MIMXRT1187AVM8B_cm7
**                          MIMXRT1187AVM8C_cm33
**                          MIMXRT1187AVM8C_cm7
**                          MIMXRT1187CVM8B_cm33
**                          MIMXRT1187CVM8B_cm7
**                          MIMXRT1187CVM8C_cm33
**                          MIMXRT1187CVM8C_cm7
**                          MIMXRT1187XVM8B_cm33
**                          MIMXRT1187XVM8B_cm7
**                          MIMXRT1187XVM8C_cm33
**                          MIMXRT1187XVM8C_cm7
**                          MIMXRT1189CVM8B_cm33
**                          MIMXRT1189CVM8B_cm7
**                          MIMXRT1189CVM8C_cm33
**                          MIMXRT1189CVM8C_cm7
**                          MIMXRT1189XVM8B_cm33
**                          MIMXRT1189XVM8B_cm7
**                          MIMXRT1189XVM8C_cm33
**                          MIMXRT1189XVM8C_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250520
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA4
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2021-03-09)
**         Initial version.
**     - rev. 2.0 (2024-01-18)
**         Header RFP.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA4.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA4
 *
 * CMSIS Peripheral Access Layer for DMA4
 */

#if !defined(PERI_DMA4_H_)
#define PERI_DMA4_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1181CVP2B) || defined(CPU_MIMXRT1181CVP2C) || defined(CPU_MIMXRT1181XVP2B) || defined(CPU_MIMXRT1181XVP2C))
#include "MIMXRT1181_COMMON.h"
#elif (defined(CPU_MIMXRT1182CVP2B) || defined(CPU_MIMXRT1182CVP2C) || defined(CPU_MIMXRT1182XVP2B) || defined(CPU_MIMXRT1182XVP2C))
#include "MIMXRT1182_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm33) || defined(CPU_MIMXRT1186XVJ8C_cm33))
#include "MIMXRT1186_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1186CVJ8C_cm7) || defined(CPU_MIMXRT1186XVJ8C_cm7))
#include "MIMXRT1186_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm33) || defined(CPU_MIMXRT1187AVM8C_cm33) || defined(CPU_MIMXRT1187CVM8B_cm33) || defined(CPU_MIMXRT1187CVM8C_cm33) || defined(CPU_MIMXRT1187XVM8B_cm33) || defined(CPU_MIMXRT1187XVM8C_cm33))
#include "MIMXRT1187_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1187AVM8B_cm7) || defined(CPU_MIMXRT1187AVM8C_cm7) || defined(CPU_MIMXRT1187CVM8B_cm7) || defined(CPU_MIMXRT1187CVM8C_cm7) || defined(CPU_MIMXRT1187XVM8B_cm7) || defined(CPU_MIMXRT1187XVM8C_cm7))
#include "MIMXRT1187_cm7_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm33) || defined(CPU_MIMXRT1189CVM8C_cm33) || defined(CPU_MIMXRT1189XVM8B_cm33) || defined(CPU_MIMXRT1189XVM8C_cm33))
#include "MIMXRT1189_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT1189CVM8B_cm7) || defined(CPU_MIMXRT1189CVM8C_cm7) || defined(CPU_MIMXRT1189XVM8B_cm7) || defined(CPU_MIMXRT1189XVM8C_cm7))
#include "MIMXRT1189_cm7_COMMON.h"
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
#if !defined(DMA_REQUEST_SOURCE_T_)
#define DMA_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA hardware request
 *
 * Defines the structure for the DMA hardware request collections.
 */
typedef enum _dma_request_source
{
    kDma3RequestMuxReserved0        = 0|0x100U,    /**< Reserved 0 */
    kDma3RequestMuxCAN1             = 1|0x100U,    /**< CAN1 */
    kDma3RequestMuxReserved2        = 2|0x100U,    /**< Reserved 2 */
    kDma3RequestMuxGPIO1Request0    = 3|0x100U,    /**< GPIO1 channel 0 */
    kDma3RequestMuxGPIO1Request1    = 4|0x100U,    /**< GPIO1 channel 1 */
    kDma3RequestMuxI3C1ToBusRequest = 5|0x100U,    /**< I3C1 To-bus Request */
    kDma3RequestMuxI3C1FromBusRequest = 6|0x100U,  /**< I3C1 From-bus Request */
    kDma3RequestMuxLPI2C1Tx         = 7|0x100U,    /**< LPI2C1 TX */
    kDma3RequestMuxLPI2C1Rx         = 8|0x100U,    /**< LPI2C1 RX */
    kDma3RequestMuxLPI2C2Tx         = 9|0x100U,    /**< LPI2C2 TX */
    kDma3RequestMuxLPI2C2Rx         = 10|0x100U,   /**< LPI2C2 RX */
    kDma3RequestMuxLPSPI1Tx         = 11|0x100U,   /**< LPSPI1 TX */
    kDma3RequestMuxLPSPI1Rx         = 12|0x100U,   /**< LPSPI1 RX */
    kDma3RequestMuxLPSPI2Tx         = 13|0x100U,   /**< LPSPI2 TX */
    kDma3RequestMuxLPSPI2Rx         = 14|0x100U,   /**< LPSPI2 RX */
    kDma3RequestMuxLPTMR1Request    = 15|0x100U,   /**< LPTMR1 */
    kDma3RequestMuxLPUART1Tx        = 16|0x100U,   /**< LPUART1 TX */
    kDma3RequestMuxLPUART1Rx        = 17|0x100U,   /**< LPUART1 RX */
    kDma3RequestMuxLPUART2Tx        = 18|0x100U,   /**< LPUART2 TX */
    kDma3RequestMuxLPUART2Rx        = 19|0x100U,   /**< LPUART2 RX */
    kDma3RequestMuxEdgelockRequest  = 20|0x100U,   /**< Edgelock enclave DMA Request */
    kDma3RequestMuxSai1Tx           = 21|0x100U,   /**< SAI1 TX */
    kDma3RequestMuxSai1Rx           = 22|0x100U,   /**< SAI1 RX */
    kDma3RequestMuxTPM1Request0Request2 = 23|0x100U, /**< TPM1 request 0 and request 2 */
    kDma3RequestMuxTPM1Request1Request3 = 24|0x100U, /**< TPM1 request 1 and request 3 */
    kDma3RequestMuxTPM1OverflowRequest = 25|0x100U, /**< TPM1 Overflow request */
    kDma3RequestMuxTPM2Request0Request2 = 26|0x100U, /**< TPM2 request 0 and request 2 */
    kDma3RequestMuxTPM2Request1Request3 = 27|0x100U, /**< TPM2 request 1 and request 3 */
    kDma3RequestMuxTPM2OverflowRequest = 28|0x100U, /**< TPM2 Overflow request */
    kDma3RequestMuxLPUART7Tx        = 29|0x100U,   /**< LPUART7 TX */
    kDma3RequestMuxLPUART7Rx        = 30|0x100U,   /**< LPUART7 RX */
    kDma3RequestMuxFlexSPI2Tx       = 33|0x100U,   /**< FlexSPI2 TX */
    kDma3RequestMuxFlexSPI2Rx       = 34|0x100U,   /**< FlexSPI2 RX */
    kDma3RequestMuxReserved35       = 35|0x100U,   /**< Reserved 35 */
    kDma3RequestMuxReserved36       = 36|0x100U,   /**< Reserved 36 */
    kDma3RequestMuxReserved37       = 37|0x100U,   /**< Reserved 37 */
    kDma3RequestMuxCAN3             = 38|0x100U,   /**< CAN3 */
    kDma4RequestMuxReserved0        = 0|0x200U,    /**< Reserved 0 */
    kDma4RequestMuxGPIO2Request0    = 2|0x200U,    /**< GPIO2 channel 0 */
    kDma4RequestMuxGPIO2Request1    = 3|0x200U,    /**< GPIO2 channel 1 */
    kDma4RequestMuxGPIO3Request0    = 4|0x200U,    /**< GPIO3 channel 0 */
    kDma4RequestMuxGPIO3Request1    = 5|0x200U,    /**< GPIO3 channel 1 */
    kDma4RequestMuxI3C2ToBusRequest = 6|0x200U,    /**< I3C2 To-bus Request */
    kDma4RequestMuxI3C2FromBusRequest = 7|0x200U,  /**< I3C2 From-bus Request */
    kDma4RequestMuxLPI2C3Tx         = 8|0x200U,    /**< LPI2C3 TX */
    kDma4RequestMuxLPI2C3Rx         = 9|0x200U,    /**< LPI2C3 RX */
    kDma4RequestMuxReserved10       = 10|0x200U,   /**< Reserved 10 */
    kDma4RequestMuxReserved11       = 11|0x200U,   /**< Reserved 11 */
    kDma4RequestMuxLPSPI3Tx         = 12|0x200U,   /**< LPSPI3 TX */
    kDma4RequestMuxLPSPI3Rx         = 13|0x200U,   /**< LPSPI3 RX */
    kDma4RequestMuxLPSPI4Tx         = 14|0x200U,   /**< LPSPI4 TX */
    kDma4RequestMuxLPSPI4Rx         = 15|0x200U,   /**< LPSPI4 RX */
    kDma4RequestMuxLPUART3Tx        = 17|0x200U,   /**< LPUART3 TX */
    kDma4RequestMuxLPUART3Rx        = 18|0x200U,   /**< LPUART3 RX */
    kDma4RequestMuxLPUART4Tx        = 19|0x200U,   /**< LPUART4 TX */
    kDma4RequestMuxLPUART4Rx        = 20|0x200U,   /**< LPUART4 RX */
    kDma4RequestMuxLPUART5Tx        = 21|0x200U,   /**< LPUART5 TX */
    kDma4RequestMuxLPUART5Rx        = 22|0x200U,   /**< LPUART5 RX */
    kDma4RequestMuxLPUART6Tx        = 23|0x200U,   /**< LPUART6 TX */
    kDma4RequestMuxLPUART6Rx        = 24|0x200U,   /**< LPUART6 RX */
    kDma4RequestMuxTPM3Request0Request2 = 25|0x200U, /**< TPM3 request 0 and request 2 */
    kDma4RequestMuxTPM3Request1Request3 = 26|0x200U, /**< TPM3 request 1 and request 3 */
    kDma4RequestMuxTPM3OverflowRequest = 27|0x200U, /**< TPM3 Overflow request */
    kDma4RequestMuxFlexIO1Request0  = 37|0x200U,   /**< FlexIO1 Request0 */
    kDma4RequestMuxFlexIO1Request1  = 38|0x200U,   /**< FlexIO1 Request1 */
    kDma4RequestMuxFlexIO1Request2  = 39|0x200U,   /**< FlexIO1 Request2 */
    kDma4RequestMuxFlexIO1Request3  = 40|0x200U,   /**< FlexIO1 Request3 */
    kDma4RequestMuxFlexIO1Request4  = 41|0x200U,   /**< FlexIO1 Request4 */
    kDma4RequestMuxFlexIO1Request5  = 42|0x200U,   /**< FlexIO1 Request5 */
    kDma4RequestMuxFlexIO1Request6  = 43|0x200U,   /**< FlexIO1 Request6 */
    kDma4RequestMuxFlexIO1Request7  = 44|0x200U,   /**< FlexIO1 Request7 */
    kDma4RequestMuxFlexIO2Request0  = 45|0x200U,   /**< FlexIO2 Request0 */
    kDma4RequestMuxFlexIO2Request1  = 46|0x200U,   /**< FlexIO2 Request1 */
    kDma4RequestMuxFlexIO2Request2  = 47|0x200U,   /**< FlexIO2 Request2 */
    kDma4RequestMuxFlexIO2Request3  = 48|0x200U,   /**< FlexIO2 Request3 */
    kDma4RequestMuxFlexIO2Request4  = 49|0x200U,   /**< FlexIO2 Request4 */
    kDma4RequestMuxFlexIO2Request5  = 50|0x200U,   /**< FlexIO2 Request5 */
    kDma4RequestMuxFlexIO2Request6  = 51|0x200U,   /**< FlexIO2 Request6 */
    kDma4RequestMuxFlexIO2Request7  = 52|0x200U,   /**< FlexIO2 Request7 */
    kDma4RequestMuxFlexSPI1Tx       = 53|0x200U,   /**< FlexSPI1 TX */
    kDma4RequestMuxFlexSPI1Rx       = 54|0x200U,   /**< FlexSPI1 RX */
    kDma4RequestMuxReserved55       = 55|0x200U,   /**< Reserved 55 */
    kDma4RequestMuxReserved56       = 56|0x200U,   /**< Reserved 56 */
    kDma4RequestMuxADC1Request0     = 57|0x200U,   /**< ADC1 Request 0 */
    kDma4RequestMuxFlexPWM3CaptureSub0 = 74|0x200U, /**< FlexPWM3 Capture sub-module0 */
    kDma4RequestMuxFlexPWM3CaptureSub1 = 75|0x200U, /**< FlexPWM3 Capture sub-module1 */
    kDma4RequestMuxFlexPWM3CaptureSub2 = 76|0x200U, /**< FlexPWM3 Capture sub-module2 */
    kDma4RequestMuxFlexPWM3CaptureSub3 = 77|0x200U, /**< FlexPWM3 Capture sub-module3 */
    kDma4RequestMuxFlexPWM3ValueSub0 = 78|0x200U,  /**< FlexPWM3 Value sub-module 0 */
    kDma4RequestMuxFlexPWM3ValueSub1 = 79|0x200U,  /**< FlexPWM3 Value sub-module 1 */
    kDma4RequestMuxFlexPWM3ValueSub2 = 80|0x200U,  /**< FlexPWM3 Value sub-module 2 */
    kDma4RequestMuxFlexPWM3ValueSub3 = 81|0x200U,  /**< FlexPWM3 Value sub-module 3 */
    kDma4RequestMuxFlexPWM4CaptureSub0 = 82|0x200U, /**< FlexPWM4 Capture sub-module0 */
    kDma4RequestMuxFlexPWM4CaptureSub1 = 83|0x200U, /**< FlexPWM4 Capture sub-module1 */
    kDma4RequestMuxFlexPWM4CaptureSub2 = 84|0x200U, /**< FlexPWM4 Capture sub-module2 */
    kDma4RequestMuxFlexPWM4CaptureSub3 = 85|0x200U, /**< FlexPWM4 Capture sub-module3 */
    kDma4RequestMuxFlexPWM4ValueSub0 = 86|0x200U,  /**< FlexPWM4 Value sub-module 0 */
    kDma4RequestMuxFlexPWM4ValueSub1 = 87|0x200U,  /**< FlexPWM4 Value sub-module 1 */
    kDma4RequestMuxFlexPWM4ValueSub2 = 88|0x200U,  /**< FlexPWM4 Value sub-module 2 */
    kDma4RequestMuxFlexPWM4ValueSub3 = 89|0x200U,  /**< FlexPWM4 Value sub-module 3 */
    kDma4RequestMuxQTIMER1CaptTimer0 = 90|0x200U,  /**< TMR1 Capture timer 0 */
    kDma4RequestMuxQTIMER1CaptTimer1 = 91|0x200U,  /**< TMR1 Capture timer 1 */
    kDma4RequestMuxQTIMER1CaptTimer2 = 92|0x200U,  /**< TMR1 Capture timer 2 */
    kDma4RequestMuxQTIMER1CaptTimer3 = 93|0x200U,  /**< TMR1 Capture timer 3 */
    kDma4RequestMuxQTIMER1Cmpld1Timer0Cmpld2Timer1 = 94|0x200U, /**< TMR1 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER1Cmpld1Timer1Cmpld2Timer0 = 95|0x200U, /**< TMR1 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER1Cmpld1Timer2Cmpld2Timer3 = 96|0x200U, /**< TMR1 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER1Cmpld1Timer3Cmpld2Timer2 = 97|0x200U, /**< TMR1 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER2CaptTimer0 = 98|0x200U,  /**< TMR2 Capture timer 0 */
    kDma4RequestMuxQTIMER2CaptTimer1 = 99|0x200U,  /**< TMR2 Capture timer 1 */
    kDma4RequestMuxQTIMER2CaptTimer2 = 100|0x200U, /**< TMR2 Capture timer 2 */
    kDma4RequestMuxQTIMER2CaptTimer3 = 101|0x200U, /**< TMR2 Capture timer 3 */
    kDma4RequestMuxQTIMER2Cmpld1Timer0Cmpld2Timer1 = 102|0x200U, /**< TMR2 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER2Cmpld1Timer1Cmpld2Timer0 = 103|0x200U, /**< TMR2 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER2Cmpld1Timer2Cmpld2Timer3 = 104|0x200U, /**< TMR2 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER2Cmpld1Timer3Cmpld2Timer2 = 105|0x200U, /**< TMR2 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER3CaptTimer0 = 106|0x200U, /**< TMR3 Capture timer 0 */
    kDma4RequestMuxQTIMER3CaptTimer1 = 107|0x200U, /**< TMR3 Capture timer 1 */
    kDma4RequestMuxQTIMER3CaptTimer2 = 108|0x200U, /**< TMR3 Capture timer 2 */
    kDma4RequestMuxQTIMER3CaptTimer3 = 109|0x200U, /**< TMR3 Capture timer 3 */
    kDma4RequestMuxQTIMER3Cmpld1Timer0Cmpld2Timer1 = 110|0x200U, /**< TMR3 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER3Cmpld1Timer1Cmpld2Timer0 = 111|0x200U, /**< TMR3 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER3Cmpld1Timer2Cmpld2Timer3 = 112|0x200U, /**< TMR3 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER3Cmpld1Timer3Cmpld2Timer2 = 113|0x200U, /**< TMR3 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER4CaptTimer0 = 114|0x200U, /**< TMR4 Capture timer 0 */
    kDma4RequestMuxQTIMER4CaptTimer1 = 115|0x200U, /**< TMR4 Capture timer 1 */
    kDma4RequestMuxQTIMER4CaptTimer2 = 116|0x200U, /**< TMR4 Capture timer 2 */
    kDma4RequestMuxQTIMER4CaptTimer3 = 117|0x200U, /**< TMR4 Capture timer 3 */
    kDma4RequestMuxQTIMER4Cmpld1Timer0Cmpld2Timer1 = 118|0x200U, /**< TMR4 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER4Cmpld1Timer1Cmpld2Timer0 = 119|0x200U, /**< TMR4 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER4Cmpld1Timer2Cmpld2Timer3 = 120|0x200U, /**< TMR4 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER4Cmpld1Timer3Cmpld2Timer2 = 121|0x200U, /**< TMR4 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxXBAR1Request0    = 154|0x200U,  /**< XBAR1 Request 0 */
    kDma4RequestMuxXBAR1Request1    = 155|0x200U,  /**< XBAR1 Request 1 */
    kDma4RequestMuxXBAR1Request2    = 156|0x200U,  /**< XBAR1 Request 2 */
    kDma4RequestMuxXBAR1Request3    = 157|0x200U,  /**< XBAR1 Request 3 */
    kDma4RequestMuxADC2Request0     = 158|0x200U,  /**< ADC2 Request 0 */
    kDma4RequestMuxEQDC1            = 159|0x200U,  /**< EQDC1 */
    kDma4RequestMuxEQDC2            = 160|0x200U,  /**< EQDC2 */
    kDma4RequestMuxEQDC3            = 161|0x200U,  /**< EQDC3 */
    kDma4RequestMuxEQDC4            = 162|0x200U,  /**< EQDC4 */
    kDma4RequestMuxReserved163      = 163|0x200U,  /**< Reserved 163 */
    kDma4RequestMuxReserved164      = 164|0x200U,  /**< Reserved 164 */
    kDma4RequestMuxLPSPI5Tx         = 167|0x200U,  /**< LPSPI5 TX */
    kDma4RequestMuxLPSPI5Rx         = 168|0x200U,  /**< LPSPI5 RX */
    kDma4RequestMuxLPSPI6Tx         = 169|0x200U,  /**< LPSPI6 TX */
    kDma4RequestMuxLPSPI6Rx         = 170|0x200U,  /**< LPSPI6 RX */
    kDma4RequestMuxLPUART8Tx        = 178|0x200U,  /**< LPUART8 TX */
    kDma4RequestMuxLPUART8Rx        = 179|0x200U,  /**< LPUART8 RX */
    kDma4RequestMuxDAC              = 186|0x200U,  /**< DAC */
    kDma4RequestMuxCMP3             = 189|0x200U,  /**< CMP3 */
    kDma4RequestMuxASRCRequest1     = 191|0x200U,  /**< ASRC request 1 pair A input request */
    kDma4RequestMuxASRCRequest2     = 192|0x200U,  /**< ASRC request 2 pair B input request */
    kDma4RequestMuxASRCRequest3     = 193|0x200U,  /**< ASRC request 3 pair C input request */
    kDma4RequestMuxASRCRequest4     = 194|0x200U,  /**< ASRC request 4 pair A output request */
    kDma4RequestMuxASRCRequest5     = 195|0x200U,  /**< ASRC request 5 pair B output request */
    kDma4RequestMuxASRCRequest6     = 196|0x200U,  /**< ASRC request 6 pair C output request */
    kDma4RequestMuxSpdifRx          = 197|0x200U,  /**< SPDIF RX */
    kDma4RequestMuxSpdifTx          = 198|0x200U,  /**< SPDIF TX */
    kDma4RequestMuxPdmRx            = 199|0x200U,  /**< PDM */
    kDma4RequestMuxGPIO4Request0    = 200|0x200U,  /**< GPIO4 channel 0 */
    kDma4RequestMuxGPIO4Request1    = 201|0x200U,  /**< GPIO4 channel 1 */
    kDma4RequestMuxGPIO5Request0    = 202|0x200U,  /**< GPIO5 channel 0 */
    kDma4RequestMuxGPIO5Request1    = 203|0x200U,  /**< GPIO5 channel 1 */
    kDma4RequestMuxGPIO6Request0    = 204|0x200U,  /**< GPIO6 channel 0 */
    kDma4RequestMuxGPIO6Request1    = 205|0x200U,  /**< GPIO6 channel 1 */
    kDma4RequestMuxReserved206      = 206|0x200U,  /**< Reserved 206 */
    kDma4RequestMuxReserved207      = 207|0x200U,  /**< Reserved 207 */
    kDma4RequestMuxSINC3Request0    = 216|0x200U,  /**< SINC3 Request 0 */
    kDma4RequestMuxSINC3Request1    = 217|0x200U,  /**< SINC3 Request 1 */
    kDma4RequestMuxSINC3Request2    = 218|0x200U,  /**< SINC3 Request 2 */
    kDma4RequestMuxSINC3Request3    = 219|0x200U,  /**< SINC3 Request 3 */
    kDma4RequestMuxADC1Request1     = 220|0x200U,  /**< ADC1 Request 1 */
    kDma4RequestMuxADC2Request1     = 221|0x200U,  /**< ADC2 Request 1 */
    kDma4RequestMuxCAN2             = 1|0x200U,    /**< CAN2 */
    kDma4RequestMuxLPTMR2Request    = 16|0x200U,   /**< LPTMR2 */
    kDma4RequestMuxTPM4Request0Request2 = 28|0x200U, /**< TPM4 request 0 and request 2 */
    kDma4RequestMuxTPM4Request1Request3 = 29|0x200U, /**< TPM4 request 1 and request 3 */
    kDma4RequestMuxTPM4OverflowRequest = 30|0x200U, /**< TPM4 Overflow request */
    kDma4RequestMuxFlexPWM1CaptureSub0 = 58|0x200U, /**< FlexPWM1 Capture sub-module0 */
    kDma4RequestMuxFlexPWM1CaptureSub1 = 59|0x200U, /**< FlexPWM1 Capture sub-module1 */
    kDma4RequestMuxFlexPWM1CaptureSub2 = 60|0x200U, /**< FlexPWM1 Capture sub-module2 */
    kDma4RequestMuxFlexPWM1CaptureSub3 = 61|0x200U, /**< FlexPWM1 Capture sub-module3 */
    kDma4RequestMuxFlexPWM1ValueSub0 = 62|0x200U,  /**< FlexPWM1 Value sub-module 0 */
    kDma4RequestMuxFlexPWM1ValueSub1 = 63|0x200U,  /**< FlexPWM1 Value sub-module 1 */
    kDma4RequestMuxFlexPWM1ValueSub2 = 64|0x200U,  /**< FlexPWM1 Value sub-module 2 */
    kDma4RequestMuxFlexPWM1ValueSub3 = 65|0x200U,  /**< FlexPWM1 Value sub-module 3 */
    kDma4RequestMuxFlexPWM2CaptureSub0 = 66|0x200U, /**< FlexPWM2 Capture sub-module0 */
    kDma4RequestMuxFlexPWM2CaptureSub1 = 67|0x200U, /**< FlexPWM2 Capture sub-module1 */
    kDma4RequestMuxFlexPWM2CaptureSub2 = 68|0x200U, /**< FlexPWM2 Capture sub-module2 */
    kDma4RequestMuxFlexPWM2CaptureSub3 = 69|0x200U, /**< FlexPWM2 Capture sub-module3 */
    kDma4RequestMuxFlexPWM2ValueSub0 = 70|0x200U,  /**< FlexPWM2 Value sub-module 0 */
    kDma4RequestMuxFlexPWM2ValueSub1 = 71|0x200U,  /**< FlexPWM2 Value sub-module 1 */
    kDma4RequestMuxFlexPWM2ValueSub2 = 72|0x200U,  /**< FlexPWM2 Value sub-module 2 */
    kDma4RequestMuxFlexPWM2ValueSub3 = 73|0x200U,  /**< FlexPWM2 Value sub-module 3 */
    kDma4RequestMuxQTIMER5CaptTimer0 = 122|0x200U, /**< TMR5 Capture timer 0 */
    kDma4RequestMuxQTIMER5CaptTimer1 = 123|0x200U, /**< TMR5 Capture timer 1 */
    kDma4RequestMuxQTIMER5CaptTimer2 = 124|0x200U, /**< TMR5 Capture timer 2 */
    kDma4RequestMuxQTIMER5CaptTimer3 = 125|0x200U, /**< TMR5 Capture timer 3 */
    kDma4RequestMuxQTIMER5Cmpld1Timer0Cmpld2Timer1 = 126|0x200U, /**< TMR5 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER5Cmpld1Timer1Cmpld2Timer0 = 127|0x200U, /**< TMR5 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER5Cmpld1Timer2Cmpld2Timer3 = 128|0x200U, /**< TMR5 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER5Cmpld1Timer3Cmpld2Timer2 = 129|0x200U, /**< TMR5 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER6CaptTimer0 = 130|0x200U, /**< TMR6 Capture timer 0 */
    kDma4RequestMuxQTIMER6CaptTimer1 = 131|0x200U, /**< TMR6 Capture timer 1 */
    kDma4RequestMuxQTIMER6CaptTimer2 = 132|0x200U, /**< TMR6 Capture timer 2 */
    kDma4RequestMuxQTIMER6CaptTimer3 = 133|0x200U, /**< TMR6 Capture timer 3 */
    kDma4RequestMuxQTIMER6Cmpld1Timer0Cmpld2Timer1 = 134|0x200U, /**< TMR6 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER6Cmpld1Timer1Cmpld2Timer0 = 135|0x200U, /**< TMR6 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER6Cmpld1Timer2Cmpld2Timer3 = 136|0x200U, /**< TMR6 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER6Cmpld1Timer3Cmpld2Timer2 = 137|0x200U, /**< TMR6 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER7CaptTimer0 = 138|0x200U, /**< TMR7 Capture timer 0 */
    kDma4RequestMuxQTIMER7CaptTimer1 = 139|0x200U, /**< TMR7 Capture timer 1 */
    kDma4RequestMuxQTIMER7CaptTimer2 = 140|0x200U, /**< TMR7 Capture timer 2 */
    kDma4RequestMuxQTIMER7CaptTimer3 = 141|0x200U, /**< TMR7 Capture timer 3 */
    kDma4RequestMuxQTIMER7Cmpld1Timer0Cmpld2Timer1 = 142|0x200U, /**< TMR7 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER7Cmpld1Timer1Cmpld2Timer0 = 143|0x200U, /**< TMR7 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER7Cmpld1Timer2Cmpld2Timer3 = 144|0x200U, /**< TMR7 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER7Cmpld1Timer3Cmpld2Timer2 = 145|0x200U, /**< TMR7 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxQTIMER8CaptTimer0 = 146|0x200U, /**< TMR8 Capture timer 0 */
    kDma4RequestMuxQTIMER8CaptTimer1 = 147|0x200U, /**< TMR8 Capture timer 1 */
    kDma4RequestMuxQTIMER8CaptTimer2 = 148|0x200U, /**< TMR8 Capture timer 2 */
    kDma4RequestMuxQTIMER8CaptTimer3 = 149|0x200U, /**< TMR8 Capture timer 3 */
    kDma4RequestMuxQTIMER8Cmpld1Timer0Cmpld2Timer1 = 150|0x200U, /**< TMR8 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDma4RequestMuxQTIMER8Cmpld1Timer1Cmpld2Timer0 = 151|0x200U, /**< TMR8 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDma4RequestMuxQTIMER8Cmpld1Timer2Cmpld2Timer3 = 152|0x200U, /**< TMR8 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDma4RequestMuxQTIMER8Cmpld1Timer3Cmpld2Timer2 = 153|0x200U, /**< TMR8 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDma4RequestMuxLPI2C6Tx         = 165|0x200U,  /**< LPI2C6 TX */
    kDma4RequestMuxLPI2C6Rx         = 166|0x200U,  /**< LPI2C6 RX */
    kDma4RequestMuxLPTMR3Request    = 171|0x200U,  /**< LPTMR3 */
    kDma4RequestMuxSai2Tx           = 180|0x200U,  /**< SAI2 TX */
    kDma4RequestMuxSai2Rx           = 181|0x200U,  /**< SAI2 RX */
    kDma4RequestMuxSai4Tx           = 184|0x200U,  /**< SAI4 TX */
    kDma4RequestMuxSai4Rx           = 185|0x200U,  /**< SAI4 RX */
    kDma4RequestMuxSINC1Request0    = 208|0x200U,  /**< SINC1 Request 0 */
    kDma4RequestMuxSINC1Request1    = 209|0x200U,  /**< SINC1 Request 1 */
    kDma4RequestMuxSINC1Request2    = 210|0x200U,  /**< SINC1 Request 2 */
    kDma4RequestMuxSINC1Request3    = 211|0x200U,  /**< SINC1 Request 3 */
    kDma4RequestMuxSINC2Request0    = 212|0x200U,  /**< SINC2 Request 0 */
    kDma4RequestMuxSINC2Request1    = 213|0x200U,  /**< SINC2 Request 1 */
    kDma4RequestMuxSINC2Request2    = 214|0x200U,  /**< SINC2 Request 2 */
    kDma4RequestMuxSINC2Request3    = 215|0x200U,  /**< SINC2 Request 3 */
    kDma3RequestMuxLPUART12Tx       = 31|0x100U,   /**< LPUART12 TX */
    kDma3RequestMuxLPUART12Rx       = 32|0x100U,   /**< LPUART12 RX */
    kDma4RequestMuxTPM5Request0Request2 = 31|0x200U, /**< TPM5 request 0 and request 2 */
    kDma4RequestMuxTPM5Request1Request3 = 32|0x200U, /**< TPM5 request 1 and request 3 */
    kDma4RequestMuxTPM5OverflowRequest = 33|0x200U, /**< TPM5 Overflow request */
    kDma4RequestMuxTPM6Request0Request2 = 34|0x200U, /**< TPM6 request 0 and request 2 */
    kDma4RequestMuxTPM6Request1Request3 = 35|0x200U, /**< TPM6 request 1 and request 3 */
    kDma4RequestMuxTPM6OverflowRequest = 36|0x200U, /**< TPM6 Overflow request */
    kDma4RequestMuxLPUART9Tx        = 172|0x200U,  /**< LPUART9 TX */
    kDma4RequestMuxLPUART9Rx        = 173|0x200U,  /**< LPUART9 RX */
    kDma4RequestMuxLPUART10Tx       = 174|0x200U,  /**< LPUART10 TX */
    kDma4RequestMuxLPUART10Rx       = 175|0x200U,  /**< LPUART10 RX */
    kDma4RequestMuxLPUART11Tx       = 176|0x200U,  /**< LPUART11 TX */
    kDma4RequestMuxLPUART11Rx       = 177|0x200U,  /**< LPUART11 RX */
    kDma4RequestMuxSai3Tx           = 182|0x200U,  /**< SAI3 TX */
    kDma4RequestMuxSai3Rx           = 183|0x200U,  /**< SAI3 RX */
    kDma4RequestMuxCMP1             = 187|0x200U,  /**< CMP1 */
    kDma4RequestMuxCMP2             = 188|0x200U,  /**< CMP2 */
    kDma4RequestMuxCMP4             = 190|0x200U,  /**< CMP4 */
} dma_request_source_t;

/* @} */
#endif /* DMA_REQUEST_SOURCE_T_ */


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
   -- DMA4 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA4_Peripheral_Access_Layer DMA4 Peripheral Access Layer
 * @{
 */

/** DMA4 - Size of Registers Arrays */
#define DMA4_MP_GRPRI_COUNT                       64u
#define DMA4_TCD_COUNT                            64u

/** DMA4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control Register, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status Register, offset: 0x4 */
  __I  uint32_t MP_INT_LOW;                        /**< Management Page Interrupt Request Status Register - Low, offset: 0x8 */
  __I  uint32_t MP_INT_HIGH;                       /**< Management Page Interrupt Request Status Register- High, offset: 0xC */
  __I  uint32_t MP_HRS_LOW;                        /**< Management Page Hardware Request Status Register - Low, offset: 0x10 */
  __I  uint32_t MP_HRS_HIGH;                       /**< Management Page Hardware Request Status Register - High, offset: 0x14 */
       uint8_t RESERVED_0[232];
  __IO uint32_t CH_GRPRI[DMA4_MP_GRPRI_COUNT];     /**< Channel Arbitration Group Register, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[65024];
  struct {                                         /* offset: 0x10000, array step: 0x8000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status Register, array offset: 0x10000, array step: 0x8000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status Register, array offset: 0x10004, array step: 0x8000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status Register, array offset: 0x10008, array step: 0x8000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus Register, array offset: 0x1000C, array step: 0x8000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority Register, array offset: 0x10010, array step: 0x8000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x10014, array step: 0x8000 */
    __IO uint16_t CH_MATTR;                          /**< Memory Attributes Register, array offset: 0x10018, array step: 0x8000 */
         uint8_t RESERVED_0[6];
    __IO uint32_t SADDR;                             /**< TCD Source Address Register, array offset: 0x10020, array step: 0x8000 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset Register, array offset: 0x10024, array step: 0x8000 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes Register, array offset: 0x10026, array step: 0x8000 */
    union {                                          /* offset: 0x10028, array step: 0x8000 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Transfer Size without Minor Loop Offsets Register, array offset: 0x10028, array step: 0x8000 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Transfer Size with Minor Loop Offsets Register, array offset: 0x10028, array step: 0x8000 */
    };
    __IO uint32_t SLAST_SDA;                         /**< TCD Last Source Address Adjustment / Store DADDR Address Register, array offset: 0x1002C, array step: 0x8000 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address Register, array offset: 0x10030, array step: 0x8000 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset Register, array offset: 0x10034, array step: 0x8000 */
    union {                                          /* offset: 0x10036, array step: 0x8000 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x10036, array step: 0x8000 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x10036, array step: 0x8000 */
    };
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment / Scatter Gather Address Register, array offset: 0x10038, array step: 0x8000 */
    __IO uint16_t CSR;                               /**< TCD Control and Status Register, array offset: 0x1003C, array step: 0x8000 */
    union {                                          /* offset: 0x1003E, array step: 0x8000 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x1003E, array step: 0x8000 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x1003E, array step: 0x8000 */
    };
         uint8_t RESERVED_1[32704];
  } TCD[DMA4_TCD_COUNT];
} DMA4_Type;

/* ----------------------------------------------------------------------------
   -- DMA4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA4_Register_Masks DMA4 Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control Register */
/*! @{ */

#define DMA4_MP_CSR_EDBG_MASK                    (0x2U)
#define DMA4_MP_CSR_EDBG_SHIFT                   (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode is disabled.
 *  0b1..Debug mode is enabled.
 */
#define DMA4_MP_CSR_EDBG(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_EDBG_SHIFT)) & DMA4_MP_CSR_EDBG_MASK)

#define DMA4_MP_CSR_ERCA_MASK                    (0x4U)
#define DMA4_MP_CSR_ERCA_SHIFT                   (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round robin channel arbitration is disabled.
 *  0b1..Round robin channel arbitration is enabled.
 */
#define DMA4_MP_CSR_ERCA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_ERCA_SHIFT)) & DMA4_MP_CSR_ERCA_MASK)

#define DMA4_MP_CSR_HAE_MASK                     (0x10U)
#define DMA4_MP_CSR_HAE_SHIFT                    (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT bit to set. Subsequently, all service requests are ignored until the HALT bit is cleared.
 */
#define DMA4_MP_CSR_HAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_HAE_SHIFT)) & DMA4_MP_CSR_HAE_MASK)

#define DMA4_MP_CSR_HALT_MASK                    (0x20U)
#define DMA4_MP_CSR_HALT_SHIFT                   (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels. Executing channels are allowed to complete. Channel execution resumes when this bit is cleared.
 */
#define DMA4_MP_CSR_HALT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_HALT_SHIFT)) & DMA4_MP_CSR_HALT_MASK)

#define DMA4_MP_CSR_GCLC_MASK                    (0x40U)
#define DMA4_MP_CSR_GCLC_SHIFT                   (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking is disabled for all channels.
 *  0b1..Channel linking is available and controlled by each channel's link settings.
 */
#define DMA4_MP_CSR_GCLC(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_GCLC_SHIFT)) & DMA4_MP_CSR_GCLC_MASK)

#define DMA4_MP_CSR_GMRC_MASK                    (0x80U)
#define DMA4_MP_CSR_GMRC_SHIFT                   (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication is disabled for all channels.
 *  0b1..Master ID replication is available and is controlled by each channel's CHn_SBR[EMI] setting.
 */
#define DMA4_MP_CSR_GMRC(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_GMRC_SHIFT)) & DMA4_MP_CSR_GMRC_MASK)

#define DMA4_MP_CSR_VER_MASK                     (0xFF0000U)
#define DMA4_MP_CSR_VER_SHIFT                    (16U)
/*! VER - eDMA version */
#define DMA4_MP_CSR_VER(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_VER_SHIFT)) & DMA4_MP_CSR_VER_MASK)

#define DMA4_MP_CSR_ACTIVE_ID_MASK               (0x3F000000U)
#define DMA4_MP_CSR_ACTIVE_ID_SHIFT              (24U)
/*! ACTIVE_ID - Active channel ID */
#define DMA4_MP_CSR_ACTIVE_ID(x)                 (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_ACTIVE_ID_SHIFT)) & DMA4_MP_CSR_ACTIVE_ID_MASK)

#define DMA4_MP_CSR_ACTIVE_MASK                  (0x80000000U)
#define DMA4_MP_CSR_ACTIVE_SHIFT                 (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle.
 *  0b1..eDMA is executing a channel.
 */
#define DMA4_MP_CSR_ACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_MP_CSR_ACTIVE_SHIFT)) & DMA4_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status Register */
/*! @{ */

#define DMA4_MP_ES_DBE_MASK                      (0x1U)
#define DMA4_MP_ES_DBE_SHIFT                     (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error was a bus error on a destination write
 */
#define DMA4_MP_ES_DBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_DBE_SHIFT)) & DMA4_MP_ES_DBE_MASK)

#define DMA4_MP_ES_SBE_MASK                      (0x2U)
#define DMA4_MP_ES_SBE_SHIFT                     (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..The last recorded error was a bus error on a source read
 */
#define DMA4_MP_ES_SBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_SBE_SHIFT)) & DMA4_MP_ES_SBE_MASK)

#define DMA4_MP_ES_SGE_MASK                      (0x4U)
#define DMA4_MP_ES_SGE_SHIFT                     (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DLASTSGA field. This field is
 *       checked at the beginning of a scatter/gather operation after major loop completion if TCDn_CSR[ESG] is
 *       enabled. TCDn_DLASTSGA is not on a 32 byte boundary.
 */
#define DMA4_MP_ES_SGE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_SGE_SHIFT)) & DMA4_MP_ES_SGE_MASK)

#define DMA4_MP_ES_NCE_MASK                      (0x8U)
#define DMA4_MP_ES_NCE_SHIFT                     (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA4_MP_ES_NCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_NCE_SHIFT)) & DMA4_MP_ES_NCE_MASK)

#define DMA4_MP_ES_DOE_MASK                      (0x10U)
#define DMA4_MP_ES_DOE_SHIFT                     (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_MP_ES_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_DOE_SHIFT)) & DMA4_MP_ES_DOE_MASK)

#define DMA4_MP_ES_DAE_MASK                      (0x20U)
#define DMA4_MP_ES_DAE_SHIFT                     (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_MP_ES_DAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_DAE_SHIFT)) & DMA4_MP_ES_DAE_MASK)

#define DMA4_MP_ES_SOE_MASK                      (0x40U)
#define DMA4_MP_ES_SOE_SHIFT                     (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_MP_ES_SOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_SOE_SHIFT)) & DMA4_MP_ES_SOE_MASK)

#define DMA4_MP_ES_SAE_MASK                      (0x80U)
#define DMA4_MP_ES_SAE_SHIFT                     (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error.
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_MP_ES_SAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_SAE_SHIFT)) & DMA4_MP_ES_SAE_MASK)

#define DMA4_MP_ES_ECX_MASK                      (0x100U)
#define DMA4_MP_ES_ECX_SHIFT                     (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..The last recorded entry was a canceled transfer by the error cancel transfer input.
 */
#define DMA4_MP_ES_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_ECX_SHIFT)) & DMA4_MP_ES_ECX_MASK)

#define DMA4_MP_ES_ERRCHN_MASK                   (0x3F000000U)
#define DMA4_MP_ES_ERRCHN_SHIFT                  (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA4_MP_ES_ERRCHN(x)                     (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_ERRCHN_SHIFT)) & DMA4_MP_ES_ERRCHN_MASK)

#define DMA4_MP_ES_VLD_MASK                      (0x80000000U)
#define DMA4_MP_ES_VLD_SHIFT                     (31U)
/*! VLD - Valid
 *  0b0..No ERR bits are set.
 *  0b1..At least one ERR bit is set indicating a valid error exists that has not been cleared.
 */
#define DMA4_MP_ES_VLD(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_MP_ES_VLD_SHIFT)) & DMA4_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT_LOW - Management Page Interrupt Request Status Register - Low */
/*! @{ */

#define DMA4_MP_INT_LOW_INT_MASK                 (0xFFFFFFFFU)
#define DMA4_MP_INT_LOW_INT_SHIFT                (0U)
/*! INT - Interrupt Request Status for channels 31 - 0 */
#define DMA4_MP_INT_LOW_INT(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_MP_INT_LOW_INT_SHIFT)) & DMA4_MP_INT_LOW_INT_MASK)
/*! @} */

/*! @name MP_INT_HIGH - Management Page Interrupt Request Status Register- High */
/*! @{ */

#define DMA4_MP_INT_HIGH_INT_MASK                (0xFFFFFFFFU)
#define DMA4_MP_INT_HIGH_INT_SHIFT               (0U)
/*! INT - Interrupt Request Status for channels 63-32 */
#define DMA4_MP_INT_HIGH_INT(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_MP_INT_HIGH_INT_SHIFT)) & DMA4_MP_INT_HIGH_INT_MASK)
/*! @} */

/*! @name MP_HRS_LOW - Management Page Hardware Request Status Register - Low */
/*! @{ */

#define DMA4_MP_HRS_LOW_HRS_MASK                 (0xFFFFFFFFU)
#define DMA4_MP_HRS_LOW_HRS_SHIFT                (0U)
/*! HRS - Hardware Request Status for channels 31 - 0
 *  0b00000000000000000000000000000000..A hardware service request for the channel is not present
 *  0b00000000000000000000000000000001..A hardware service request for channel 0 is present
 */
#define DMA4_MP_HRS_LOW_HRS(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_MP_HRS_LOW_HRS_SHIFT)) & DMA4_MP_HRS_LOW_HRS_MASK)
/*! @} */

/*! @name MP_HRS_HIGH - Management Page Hardware Request Status Register - High */
/*! @{ */

#define DMA4_MP_HRS_HIGH_HRS_MASK                (0xFFFFFFFFU)
#define DMA4_MP_HRS_HIGH_HRS_SHIFT               (0U)
/*! HRS - Hardware Request Status for channels 63-32
 *  0b00000000000000000000000000000000..A hardware service request for the channel is not present
 *  0b00000000000000000000000000000001..A hardware service request for channel 0 is present
 */
#define DMA4_MP_HRS_HIGH_HRS(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_MP_HRS_HIGH_HRS_SHIFT)) & DMA4_MP_HRS_HIGH_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group Register */
/*! @{ */

#define DMA4_CH_GRPRI_GRPRI_MASK                 (0x3FU)
#define DMA4_CH_GRPRI_GRPRI_SHIFT                (0U)
/*! GRPRI - Arbitration group per channel. */
#define DMA4_CH_GRPRI_GRPRI(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_CH_GRPRI_GRPRI_SHIFT)) & DMA4_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA4_CH_GRPRI */
#define DMA4_CH_GRPRI_COUNT                      (64U)

/*! @name CH_CSR - Channel Control and Status Register */
/*! @{ */

#define DMA4_CH_CSR_ERQ_MASK                     (0x1U)
#define DMA4_CH_CSR_ERQ_SHIFT                    (0U)
/*! ERQ - Enable DMA Request
 *  0b0..The DMA hardware request signal for the corresponding channel is disabled.
 *  0b1..The DMA hardware request signal for the corresponding channel is enabled.
 */
#define DMA4_CH_CSR_ERQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_ERQ_SHIFT)) & DMA4_CH_CSR_ERQ_MASK)

#define DMA4_CH_CSR_EARQ_MASK                    (0x2U)
#define DMA4_CH_CSR_EARQ_SHIFT                   (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel.
 *  0b1..Enable asynchronous DMA request for the channel.
 */
#define DMA4_CH_CSR_EARQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_EARQ_SHIFT)) & DMA4_CH_CSR_EARQ_MASK)

#define DMA4_CH_CSR_EEI_MASK                     (0x4U)
#define DMA4_CH_CSR_EEI_SHIFT                    (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA4_CH_CSR_EEI(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_EEI_SHIFT)) & DMA4_CH_CSR_EEI_MASK)

#define DMA4_CH_CSR_SWAP_MASK                    (0xF000U)
#define DMA4_CH_CSR_SWAP_SHIFT                   (12U)
/*! SWAP - Swap size
 *  0b0000..disabled
 *  0b0001..read with 8-bit swap
 *  0b0010..read with 16-bit swap
 *  0b0011..read with 32-bit swap
 *  0b0100-0b1000..reserved
 *  0b1001..write with 8-bit swap
 *  0b1010..write with 16-bit swap
 *  0b1011..write with 32-bit swap
 *  0b1100-0b1111..reserved
 */
#define DMA4_CH_CSR_SWAP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_SWAP_SHIFT)) & DMA4_CH_CSR_SWAP_MASK)

#define DMA4_CH_CSR_SIGNEXT_MASK                 (0x3F0000U)
#define DMA4_CH_CSR_SIGNEXT_SHIFT                (16U)
/*! SIGNEXT - Sign Extension
 *  0b000000..disabled
 *  0b000001..A non-zero value specifying the sign extend bit position
 */
#define DMA4_CH_CSR_SIGNEXT(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_SIGNEXT_SHIFT)) & DMA4_CH_CSR_SIGNEXT_MASK)

#define DMA4_CH_CSR_DONE_MASK                    (0x40000000U)
#define DMA4_CH_CSR_DONE_SHIFT                   (30U)
/*! DONE - Channel Done */
#define DMA4_CH_CSR_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_DONE_SHIFT)) & DMA4_CH_CSR_DONE_MASK)

#define DMA4_CH_CSR_ACTIVE_MASK                  (0x80000000U)
#define DMA4_CH_CSR_ACTIVE_SHIFT                 (31U)
/*! ACTIVE - Channel Active */
#define DMA4_CH_CSR_ACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_CH_CSR_ACTIVE_SHIFT)) & DMA4_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA4_CH_CSR */
#define DMA4_CH_CSR_COUNT                        (64U)

/*! @name CH_ES - Channel Error Status Register */
/*! @{ */

#define DMA4_CH_ES_DBE_MASK                      (0x1U)
#define DMA4_CH_ES_DBE_SHIFT                     (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error was a bus error on a destination write
 */
#define DMA4_CH_ES_DBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_DBE_SHIFT)) & DMA4_CH_ES_DBE_MASK)

#define DMA4_CH_ES_SBE_MASK                      (0x2U)
#define DMA4_CH_ES_SBE_SHIFT                     (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..The last recorded error was a bus error on a source read
 */
#define DMA4_CH_ES_SBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_SBE_SHIFT)) & DMA4_CH_ES_SBE_MASK)

#define DMA4_CH_ES_SGE_MASK                      (0x4U)
#define DMA4_CH_ES_SGE_SHIFT                     (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DLASTSGA field. This field is
 *       checked at the beginning of a scatter/gather operation after major loop completion if TCDn_CSR[ESG] is
 *       enabled. TCDn_DLASTSGA is not on a 32 byte boundary.
 */
#define DMA4_CH_ES_SGE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_SGE_SHIFT)) & DMA4_CH_ES_SGE_MASK)

#define DMA4_CH_ES_NCE_MASK                      (0x8U)
#define DMA4_CH_ES_NCE_SHIFT                     (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields.
 *       TCDn_NBYTES is not a multiple of TCDn_ATTR[SSIZE] and TCDn_ATTR[DSIZE], or TCDn_CITER[CITER] is equal to zero,
 *       or TCDn_CITER[ELINK] is not equal to TCDn_BITER[ELINK]
 */
#define DMA4_CH_ES_NCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_NCE_SHIFT)) & DMA4_CH_ES_NCE_MASK)

#define DMA4_CH_ES_DOE_MASK                      (0x10U)
#define DMA4_CH_ES_DOE_SHIFT                     (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_CH_ES_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_DOE_SHIFT)) & DMA4_CH_ES_DOE_MASK)

#define DMA4_CH_ES_DAE_MASK                      (0x20U)
#define DMA4_CH_ES_DAE_SHIFT                     (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_CH_ES_DAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_DAE_SHIFT)) & DMA4_CH_ES_DAE_MASK)

#define DMA4_CH_ES_SOE_MASK                      (0x40U)
#define DMA4_CH_ES_SOE_SHIFT                     (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_CH_ES_SOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_SOE_SHIFT)) & DMA4_CH_ES_SOE_MASK)

#define DMA4_CH_ES_SAE_MASK                      (0x80U)
#define DMA4_CH_ES_SAE_SHIFT                     (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error.
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_CH_ES_SAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_SAE_SHIFT)) & DMA4_CH_ES_SAE_MASK)

#define DMA4_CH_ES_ERR_MASK                      (0x80000000U)
#define DMA4_CH_ES_ERR_SHIFT                     (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA4_CH_ES_ERR(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_CH_ES_ERR_SHIFT)) & DMA4_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA4_CH_ES */
#define DMA4_CH_ES_COUNT                         (64U)

/*! @name CH_INT - Channel Interrupt Status Register */
/*! @{ */

#define DMA4_CH_INT_INT_MASK                     (0x1U)
#define DMA4_CH_INT_INT_SHIFT                    (0U)
/*! INT - Interrupt Request
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA4_CH_INT_INT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_INT_INT_SHIFT)) & DMA4_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA4_CH_INT */
#define DMA4_CH_INT_COUNT                        (64U)

/*! @name CH_SBR - Channel System Bus Register */
/*! @{ */

#define DMA4_CH_SBR_MID_MASK                     (0xFU)
#define DMA4_CH_SBR_MID_SHIFT                    (0U)
/*! MID - Master ID */
#define DMA4_CH_SBR_MID(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_MID_SHIFT)) & DMA4_CH_SBR_MID_MASK)

#define DMA4_CH_SBR_INSTR_MASK                   (0x2000U)
#define DMA4_CH_SBR_INSTR_SHIFT                  (13U)
/*! INSTR - Instruction/Data Access
 *  0b0..Data access for DMA transfers
 *  0b1..Instruction access for DMA transfers
 */
#define DMA4_CH_SBR_INSTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_INSTR_SHIFT)) & DMA4_CH_SBR_INSTR_MASK)

#define DMA4_CH_SBR_SEC_MASK                     (0x4000U)
#define DMA4_CH_SBR_SEC_SHIFT                    (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA4_CH_SBR_SEC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_SEC_SHIFT)) & DMA4_CH_SBR_SEC_MASK)

#define DMA4_CH_SBR_PAL_MASK                     (0x8000U)
#define DMA4_CH_SBR_PAL_SHIFT                    (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA4_CH_SBR_PAL(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_PAL_SHIFT)) & DMA4_CH_SBR_PAL_MASK)

#define DMA4_CH_SBR_EMI_MASK                     (0x10000U)
#define DMA4_CH_SBR_EMI_SHIFT                    (16U)
/*! EMI - Enable Master ID replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA4_CH_SBR_EMI(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_EMI_SHIFT)) & DMA4_CH_SBR_EMI_MASK)

#define DMA4_CH_SBR_ATTR_MASK                    (0x7E0000U)
#define DMA4_CH_SBR_ATTR_SHIFT                   (17U)
/*! ATTR - Attribute Output */
#define DMA4_CH_SBR_ATTR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_CH_SBR_ATTR_SHIFT)) & DMA4_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA4_CH_SBR */
#define DMA4_CH_SBR_COUNT                        (64U)

/*! @name CH_PRI - Channel Priority Register */
/*! @{ */

#define DMA4_CH_PRI_APL_MASK                     (0x7U)
#define DMA4_CH_PRI_APL_SHIFT                    (0U)
/*! APL - Arbitration Priority Level */
#define DMA4_CH_PRI_APL(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_PRI_APL_SHIFT)) & DMA4_CH_PRI_APL_MASK)

#define DMA4_CH_PRI_DPA_MASK                     (0x40000000U)
#define DMA4_CH_PRI_DPA_SHIFT                    (30U)
/*! DPA - Disable Preempt Ability.
 *  0b0..The channel can suspend a lower priority channel.
 *  0b1..The channel cannot suspend any other channel, regardless of channel priority.
 */
#define DMA4_CH_PRI_DPA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_PRI_DPA_SHIFT)) & DMA4_CH_PRI_DPA_MASK)

#define DMA4_CH_PRI_ECP_MASK                     (0x80000000U)
#define DMA4_CH_PRI_ECP_SHIFT                    (31U)
/*! ECP - Enable Channel Preemption.
 *  0b0..The channel cannot be suspended by a higher priority channel's service request.
 *  0b1..The channel can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA4_CH_PRI_ECP(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_PRI_ECP_SHIFT)) & DMA4_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA4_CH_PRI */
#define DMA4_CH_PRI_COUNT                        (64U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA4_CH_MUX_SRC_MASK                     (0xFFU)
#define DMA4_CH_MUX_SRC_SHIFT                    (0U)
/*! SRC - Service Request Source */
#define DMA4_CH_MUX_SRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CH_MUX_SRC_SHIFT)) & DMA4_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA4_CH_MUX */
#define DMA4_CH_MUX_COUNT                        (64U)

/*! @name CH_MATTR - Memory Attributes Register */
/*! @{ */

#define DMA4_CH_MATTR_RCACHE_MASK                (0xFU)
#define DMA4_CH_MATTR_RCACHE_SHIFT               (0U)
/*! RCACHE - Read Cache Attributes */
#define DMA4_CH_MATTR_RCACHE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA4_CH_MATTR_RCACHE_SHIFT)) & DMA4_CH_MATTR_RCACHE_MASK)

#define DMA4_CH_MATTR_WCACHE_MASK                (0xF0U)
#define DMA4_CH_MATTR_WCACHE_SHIFT               (4U)
/*! WCACHE - Write Cache Attributes */
#define DMA4_CH_MATTR_WCACHE(x)                  (((uint16_t)(((uint16_t)(x)) << DMA4_CH_MATTR_WCACHE_SHIFT)) & DMA4_CH_MATTR_WCACHE_MASK)
/*! @} */

/* The count of DMA4_CH_MATTR */
#define DMA4_CH_MATTR_COUNT                      (64U)

/*! @name SADDR - TCD Source Address Register */
/*! @{ */

#define DMA4_SADDR_SADDR_MASK                    (0xFFFFFFFFU)
#define DMA4_SADDR_SADDR_SHIFT                   (0U)
/*! SADDR - Source Address */
#define DMA4_SADDR_SADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_SADDR_SADDR_SHIFT)) & DMA4_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA4_SADDR */
#define DMA4_SADDR_COUNT                         (64U)

/*! @name SOFF - TCD Signed Source Address Offset Register */
/*! @{ */

#define DMA4_SOFF_SOFF_MASK                      (0xFFFFU)
#define DMA4_SOFF_SOFF_SHIFT                     (0U)
/*! SOFF - Source address signed offset */
#define DMA4_SOFF_SOFF(x)                        (((uint16_t)(((uint16_t)(x)) << DMA4_SOFF_SOFF_SHIFT)) & DMA4_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA4_SOFF */
#define DMA4_SOFF_COUNT                          (64U)

/*! @name ATTR - TCD Transfer Attributes Register */
/*! @{ */

#define DMA4_ATTR_DSIZE_MASK                     (0x7U)
#define DMA4_ATTR_DSIZE_SHIFT                    (0U)
/*! DSIZE - Destination data transfer size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA4_ATTR_DSIZE(x)                       (((uint16_t)(((uint16_t)(x)) << DMA4_ATTR_DSIZE_SHIFT)) & DMA4_ATTR_DSIZE_MASK)

#define DMA4_ATTR_DMOD_MASK                      (0xF8U)
#define DMA4_ATTR_DMOD_SHIFT                     (3U)
/*! DMOD - Destination address modulo */
#define DMA4_ATTR_DMOD(x)                        (((uint16_t)(((uint16_t)(x)) << DMA4_ATTR_DMOD_SHIFT)) & DMA4_ATTR_DMOD_MASK)

#define DMA4_ATTR_SSIZE_MASK                     (0x700U)
#define DMA4_ATTR_SSIZE_SHIFT                    (8U)
/*! SSIZE - Source data transfer size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA4_ATTR_SSIZE(x)                       (((uint16_t)(((uint16_t)(x)) << DMA4_ATTR_SSIZE_SHIFT)) & DMA4_ATTR_SSIZE_MASK)

#define DMA4_ATTR_SMOD_MASK                      (0xF800U)
#define DMA4_ATTR_SMOD_SHIFT                     (11U)
/*! SMOD - Source address modulo
 *  0b00000..Source address modulo feature is disabled
 *  0b00001..Source address modulo feature is enabled for any non-zero value [1-31]
 */
#define DMA4_ATTR_SMOD(x)                        (((uint16_t)(((uint16_t)(x)) << DMA4_ATTR_SMOD_SHIFT)) & DMA4_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA4_ATTR */
#define DMA4_ATTR_COUNT                          (64U)

/*! @name NBYTES_MLOFFNO - TCD Transfer Size without Minor Loop Offsets Register */
/*! @{ */

#define DMA4_NBYTES_MLOFFNO_NBYTES_MASK          (0x3FFFFFFFU)
#define DMA4_NBYTES_MLOFFNO_NBYTES_SHIFT         (0U)
/*! NBYTES - Number of Bytes to transfer per service request */
#define DMA4_NBYTES_MLOFFNO_NBYTES(x)            (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA4_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA4_NBYTES_MLOFFNO_DMLOE_MASK           (0x40000000U)
#define DMA4_NBYTES_MLOFFNO_DMLOE_SHIFT          (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA4_NBYTES_MLOFFNO_DMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA4_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA4_NBYTES_MLOFFNO_SMLOE_MASK           (0x80000000U)
#define DMA4_NBYTES_MLOFFNO_SMLOE_SHIFT          (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA4_NBYTES_MLOFFNO_SMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA4_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA4_NBYTES_MLOFFNO */
#define DMA4_NBYTES_MLOFFNO_COUNT                (64U)

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets Register */
/*! @{ */

#define DMA4_NBYTES_MLOFFYES_NBYTES_MASK         (0x3FFU)
#define DMA4_NBYTES_MLOFFYES_NBYTES_SHIFT        (0U)
/*! NBYTES - Number of Bytes to transfer per service request */
#define DMA4_NBYTES_MLOFFYES_NBYTES(x)           (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA4_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA4_NBYTES_MLOFFYES_MLOFF_MASK          (0x3FFFFC00U)
#define DMA4_NBYTES_MLOFFYES_MLOFF_SHIFT         (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA4_NBYTES_MLOFFYES_MLOFF(x)            (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA4_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA4_NBYTES_MLOFFYES_DMLOE_MASK          (0x40000000U)
#define DMA4_NBYTES_MLOFFYES_DMLOE_SHIFT         (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA4_NBYTES_MLOFFYES_DMLOE(x)            (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA4_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA4_NBYTES_MLOFFYES_SMLOE_MASK          (0x80000000U)
#define DMA4_NBYTES_MLOFFYES_SMLOE_SHIFT         (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA4_NBYTES_MLOFFYES_SMLOE(x)            (((uint32_t)(((uint32_t)(x)) << DMA4_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA4_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA4_NBYTES_MLOFFYES */
#define DMA4_NBYTES_MLOFFYES_COUNT               (64U)

/*! @name SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address Register */
/*! @{ */

#define DMA4_SLAST_SDA_SLAST_SDA_MASK            (0xFFFFFFFFU)
#define DMA4_SLAST_SDA_SLAST_SDA_SHIFT           (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA4_SLAST_SDA_SLAST_SDA(x)              (((uint32_t)(((uint32_t)(x)) << DMA4_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA4_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA4_SLAST_SDA */
#define DMA4_SLAST_SDA_COUNT                     (64U)

/*! @name DADDR - TCD Destination Address Register */
/*! @{ */

#define DMA4_DADDR_DADDR_MASK                    (0xFFFFFFFFU)
#define DMA4_DADDR_DADDR_SHIFT                   (0U)
/*! DADDR - Destination Address */
#define DMA4_DADDR_DADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_DADDR_DADDR_SHIFT)) & DMA4_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA4_DADDR */
#define DMA4_DADDR_COUNT                         (64U)

/*! @name DOFF - TCD Signed Destination Address Offset Register */
/*! @{ */

#define DMA4_DOFF_DOFF_MASK                      (0xFFFFU)
#define DMA4_DOFF_DOFF_SHIFT                     (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA4_DOFF_DOFF(x)                        (((uint16_t)(((uint16_t)(x)) << DMA4_DOFF_DOFF_SHIFT)) & DMA4_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA4_DOFF */
#define DMA4_DOFF_COUNT                          (64U)

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register */
/*! @{ */

#define DMA4_CITER_ELINKNO_CITER_MASK            (0x7FFFU)
#define DMA4_CITER_ELINKNO_CITER_SHIFT           (0U)
/*! CITER - Current Major Iteration Count */
#define DMA4_CITER_ELINKNO_CITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_CITER_ELINKNO_CITER_SHIFT)) & DMA4_CITER_ELINKNO_CITER_MASK)

#define DMA4_CITER_ELINKNO_ELINK_MASK            (0x8000U)
#define DMA4_CITER_ELINKNO_ELINK_SHIFT           (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_CITER_ELINKNO_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_CITER_ELINKNO_ELINK_SHIFT)) & DMA4_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA4_CITER_ELINKNO */
#define DMA4_CITER_ELINKNO_COUNT                 (64U)

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register */
/*! @{ */

#define DMA4_CITER_ELINKYES_CITER_MASK           (0x1FFU)
#define DMA4_CITER_ELINKYES_CITER_SHIFT          (0U)
/*! CITER - Current Major Iteration Count */
#define DMA4_CITER_ELINKYES_CITER(x)             (((uint16_t)(((uint16_t)(x)) << DMA4_CITER_ELINKYES_CITER_SHIFT)) & DMA4_CITER_ELINKYES_CITER_MASK)

#define DMA4_CITER_ELINKYES_LINKCH_MASK          (0x7E00U)
#define DMA4_CITER_ELINKYES_LINKCH_SHIFT         (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA4_CITER_ELINKYES_LINKCH(x)            (((uint16_t)(((uint16_t)(x)) << DMA4_CITER_ELINKYES_LINKCH_SHIFT)) & DMA4_CITER_ELINKYES_LINKCH_MASK)

#define DMA4_CITER_ELINKYES_ELINK_MASK           (0x8000U)
#define DMA4_CITER_ELINKYES_ELINK_SHIFT          (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_CITER_ELINKYES_ELINK(x)             (((uint16_t)(((uint16_t)(x)) << DMA4_CITER_ELINKYES_ELINK_SHIFT)) & DMA4_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA4_CITER_ELINKYES */
#define DMA4_CITER_ELINKYES_COUNT                (64U)

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address Register */
/*! @{ */

#define DMA4_DLAST_SGA_DLAST_SGA_MASK            (0xFFFFFFFFU)
#define DMA4_DLAST_SGA_DLAST_SGA_SHIFT           (0U)
/*! DLAST_SGA - Final Destination Address Adjustment / Scatter Gather Address */
#define DMA4_DLAST_SGA_DLAST_SGA(x)              (((uint32_t)(((uint32_t)(x)) << DMA4_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA4_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA4_DLAST_SGA */
#define DMA4_DLAST_SGA_COUNT                     (64U)

/*! @name CSR - TCD Control and Status Register */
/*! @{ */

#define DMA4_CSR_START_MASK                      (0x1U)
#define DMA4_CSR_START_SHIFT                     (0U)
/*! START - Channel Start
 *  0b0..The channel is not explicitly started.
 *  0b1..The channel is explicitly started via a software initiated service request.
 */
#define DMA4_CSR_START(x)                        (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_START_SHIFT)) & DMA4_CSR_START_MASK)

#define DMA4_CSR_INTMAJOR_MASK                   (0x2U)
#define DMA4_CSR_INTMAJOR_SHIFT                  (1U)
/*! INTMAJOR - Enable an interrupt when major iteration count completes.
 *  0b0..The end-of-major loop interrupt is disabled.
 *  0b1..The end-of-major loop interrupt is enabled.
 */
#define DMA4_CSR_INTMAJOR(x)                     (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_INTMAJOR_SHIFT)) & DMA4_CSR_INTMAJOR_MASK)

#define DMA4_CSR_INTHALF_MASK                    (0x4U)
#define DMA4_CSR_INTHALF_SHIFT                   (2U)
/*! INTHALF - Enable an interrupt when major counter is half complete.
 *  0b0..The half-point interrupt is disabled.
 *  0b1..The half-point interrupt is enabled.
 */
#define DMA4_CSR_INTHALF(x)                      (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_INTHALF_SHIFT)) & DMA4_CSR_INTHALF_MASK)

#define DMA4_CSR_DREQ_MASK                       (0x8U)
#define DMA4_CSR_DREQ_SHIFT                      (3U)
/*! DREQ - Disable request
 *  0b0..No operation
 *  0b1..Clear the ERQ bit upon major loop completion, thus disabling hardware service requests.
 */
#define DMA4_CSR_DREQ(x)                         (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_DREQ_SHIFT)) & DMA4_CSR_DREQ_MASK)

#define DMA4_CSR_ESG_MASK                        (0x10U)
#define DMA4_CSR_ESG_SHIFT                       (4U)
/*! ESG - Enable Scatter/Gather processing
 *  0b0..The current channel's TCD is normal format.
 *  0b1..The current channel's TCD specifies a scatter gather format. The DLASTSGA field provides a memory pointer
 *       to the next TCD to be loaded into this channel after the major loop completes its execution.
 */
#define DMA4_CSR_ESG(x)                          (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_ESG_SHIFT)) & DMA4_CSR_ESG_MASK)

#define DMA4_CSR_MAJORELINK_MASK                 (0x20U)
#define DMA4_CSR_MAJORELINK_SHIFT                (5U)
/*! MAJORELINK - Enable channel-to-channel linking on major loop complete
 *  0b0..The channel-to-channel linking is disabled.
 *  0b1..The channel-to-channel linking is enabled.
 */
#define DMA4_CSR_MAJORELINK(x)                   (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_MAJORELINK_SHIFT)) & DMA4_CSR_MAJORELINK_MASK)

#define DMA4_CSR_EEOP_MASK                       (0x40U)
#define DMA4_CSR_EEOP_SHIFT                      (6U)
/*! EEOP - Enable end-of-packet processing
 *  0b0..The end-of-packet operation is disabled.
 *  0b1..The end-of-packet hardware input signal is enabled.
 */
#define DMA4_CSR_EEOP(x)                         (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_EEOP_SHIFT)) & DMA4_CSR_EEOP_MASK)

#define DMA4_CSR_ESDA_MASK                       (0x80U)
#define DMA4_CSR_ESDA_SHIFT                      (7U)
/*! ESDA - Enable store destination address
 *  0b0..The store destination address to system memory operation is disabled.
 *  0b1..The store destination address to system memory operation is enabled.
 */
#define DMA4_CSR_ESDA(x)                         (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_ESDA_SHIFT)) & DMA4_CSR_ESDA_MASK)

#define DMA4_CSR_MAJORLINKCH_MASK                (0x3F00U)
#define DMA4_CSR_MAJORLINKCH_SHIFT               (8U)
/*! MAJORLINKCH - Major loop link channel number */
#define DMA4_CSR_MAJORLINKCH(x)                  (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_MAJORLINKCH_SHIFT)) & DMA4_CSR_MAJORLINKCH_MASK)

#define DMA4_CSR_TMC_MASK                        (0xC000U)
#define DMA4_CSR_TMC_SHIFT                       (14U)
/*! TMC - Transfer Mode Control
 *  0b00..Read/Write
 *  0b01..Read Only
 *  0b10..Write Only
 *  0b11..Reserved
 */
#define DMA4_CSR_TMC(x)                          (((uint16_t)(((uint16_t)(x)) << DMA4_CSR_TMC_SHIFT)) & DMA4_CSR_TMC_MASK)
/*! @} */

/* The count of DMA4_CSR */
#define DMA4_CSR_COUNT                           (64U)

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register */
/*! @{ */

#define DMA4_BITER_ELINKNO_BITER_MASK            (0x7FFFU)
#define DMA4_BITER_ELINKNO_BITER_SHIFT           (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA4_BITER_ELINKNO_BITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_BITER_ELINKNO_BITER_SHIFT)) & DMA4_BITER_ELINKNO_BITER_MASK)

#define DMA4_BITER_ELINKNO_ELINK_MASK            (0x8000U)
#define DMA4_BITER_ELINKNO_ELINK_SHIFT           (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_BITER_ELINKNO_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_BITER_ELINKNO_ELINK_SHIFT)) & DMA4_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA4_BITER_ELINKNO */
#define DMA4_BITER_ELINKNO_COUNT                 (64U)

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register */
/*! @{ */

#define DMA4_BITER_ELINKYES_BITER_MASK           (0x1FFU)
#define DMA4_BITER_ELINKYES_BITER_SHIFT          (0U)
/*! BITER - Starting major iteration count */
#define DMA4_BITER_ELINKYES_BITER(x)             (((uint16_t)(((uint16_t)(x)) << DMA4_BITER_ELINKYES_BITER_SHIFT)) & DMA4_BITER_ELINKYES_BITER_MASK)

#define DMA4_BITER_ELINKYES_LINKCH_MASK          (0x7E00U)
#define DMA4_BITER_ELINKYES_LINKCH_SHIFT         (9U)
/*! LINKCH - Link Channel Number */
#define DMA4_BITER_ELINKYES_LINKCH(x)            (((uint16_t)(((uint16_t)(x)) << DMA4_BITER_ELINKYES_LINKCH_SHIFT)) & DMA4_BITER_ELINKYES_LINKCH_MASK)

#define DMA4_BITER_ELINKYES_ELINK_MASK           (0x8000U)
#define DMA4_BITER_ELINKYES_ELINK_SHIFT          (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_BITER_ELINKYES_ELINK(x)             (((uint16_t)(((uint16_t)(x)) << DMA4_BITER_ELINKYES_ELINK_SHIFT)) & DMA4_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA4_BITER_ELINKYES */
#define DMA4_BITER_ELINKYES_COUNT                (64U)


/*!
 * @}
 */ /* end of group DMA4_Register_Masks */


/*!
 * @}
 */ /* end of group DMA4_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA4_H_ */

