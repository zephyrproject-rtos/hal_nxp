/*
** ###################################################################
**     Processors:          MKM14Z128ACHH5
**                          MKM14Z64ACHH5
**                          MKM33Z128ACLH5
**                          MKM33Z128ACLL5
**                          MKM33Z64ACLH5
**                          MKM33Z64ACLL5
**                          MKM34Z128ACLL5
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2014-07-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MKM14Z128ACHH5) || defined(CPU_MKM14Z64ACHH5))
#include "MKM14ZA5_COMMON.h"
#elif (defined(CPU_MKM33Z128ACLH5) || defined(CPU_MKM33Z128ACLL5) || defined(CPU_MKM33Z64ACLH5) || defined(CPU_MKM33Z64ACLL5))
#include "MKM33ZA5_COMMON.h"
#elif (defined(CPU_MKM34Z128ACLL5))
#include "MKM34ZA5_COMMON.h"
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
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma_request_source
{
    kDmaRequestMux0Disable          = 0|0x100U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMux0SPI0Tx           = 1|0x100U,    /**< SPI0 Transmit (DMAMUX0) */
    kDmaRequestMux0SPI0Rx           = 2|0x100U,    /**< SPI0 Receive (DMAMUX0) */
    kDmaRequestMux0UART0Tx          = 3|0x100U,    /**< UART0 Transmit (DMAMUX0) */
    kDmaRequestMux0UART0Rx          = 4|0x100U,    /**< UART0 Receive (DMAMUX0) */
    kDmaRequestMux0I2C0             = 5|0x100U,    /**< I2C0 (DMAMUX0) */
    kDmaRequestMux0XBAR             = 6|0x100U,    /**< XBAR (DMAMUX0) */
    kDmaRequestMux0UART3Tx          = 7|0x100U,    /**< UART3 Transmit (DMAMUX0) */
    kDmaRequestMux0UART3Rx          = 8|0x100U,    /**< UART3 Receive (DMAMUX0) */
    kDmaRequestMux0AFEChannel0      = 9|0x100U,    /**< AFE channel 0 (DMAMUX0) */
    kDmaRequestMux0TMR0             = 10|0x100U,   /**< TMR0 (DMAMUX0) */
    kDmaRequestMux0TMR3             = 11|0x100U,   /**< TMR3 (DMAMUX0) */
    kDmaRequestMux0AFEChannel2      = 12|0x100U,   /**< AFE channel 2 (DMAMUX0) */
    kDmaRequestMux0ADC              = 13|0x100U,   /**< ADC (DMAMUX0) */
    kDmaRequestMux0CMP0             = 14|0x100U,   /**< CMP0 (DMAMUX0) */
    kDmaRequestMux0PTE              = 15|0x100U,   /**< PTE (DMAMUX0) */
    kDmaRequestMux0PTA              = 16|0x100U,   /**< PTA (DMAMUX0) */
    kDmaRequestMux0AlwaysEnabledslot17 = 17|0x100U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux0AlwaysEnabledslot18 = 18|0x100U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux0Reserved19       = 19|0x100U,   /**< Reserved19 */
    kDmaRequestMux0Reserved20       = 20|0x100U,   /**< Reserved20 */
    kDmaRequestMux0Reserved21       = 21|0x100U,   /**< Reserved21 */
    kDmaRequestMux0Reserved22       = 22|0x100U,   /**< Reserved22 */
    kDmaRequestMux0Reserved23       = 23|0x100U,   /**< Reserved23 */
    kDmaRequestMux0Reserved24       = 24|0x100U,   /**< Reserved24 */
    kDmaRequestMux0Reserved25       = 25|0x100U,   /**< Reserved25 */
    kDmaRequestMux0Reserved26       = 26|0x100U,   /**< Reserved26 */
    kDmaRequestMux0Reserved27       = 27|0x100U,   /**< Reserved27 */
    kDmaRequestMux0Reserved28       = 28|0x100U,   /**< Reserved28 */
    kDmaRequestMux0Reserved29       = 29|0x100U,   /**< Reserved29 */
    kDmaRequestMux0Reserved30       = 30|0x100U,   /**< Reserved30 */
    kDmaRequestMux0Reserved31       = 31|0x100U,   /**< Reserved31 */
    kDmaRequestMux0Reserved32       = 32|0x100U,   /**< Reserved32 */
    kDmaRequestMux0Reserved33       = 33|0x100U,   /**< Reserved33 */
    kDmaRequestMux0Reserved34       = 34|0x100U,   /**< Reserved34 */
    kDmaRequestMux0Reserved35       = 35|0x100U,   /**< Reserved35 */
    kDmaRequestMux0Reserved36       = 36|0x100U,   /**< Reserved36 */
    kDmaRequestMux0Reserved37       = 37|0x100U,   /**< Reserved37 */
    kDmaRequestMux0Reserved38       = 38|0x100U,   /**< Reserved38 */
    kDmaRequestMux0Reserved39       = 39|0x100U,   /**< Reserved39 */
    kDmaRequestMux0Reserved40       = 40|0x100U,   /**< Reserved40 */
    kDmaRequestMux0Reserved41       = 41|0x100U,   /**< Reserved41 */
    kDmaRequestMux0Reserved42       = 42|0x100U,   /**< Reserved42 */
    kDmaRequestMux0Reserved43       = 43|0x100U,   /**< Reserved43 */
    kDmaRequestMux0Reserved44       = 44|0x100U,   /**< Reserved44 */
    kDmaRequestMux0Reserved45       = 45|0x100U,   /**< Reserved45 */
    kDmaRequestMux0Reserved46       = 46|0x100U,   /**< Reserved46 */
    kDmaRequestMux0Reserved47       = 47|0x100U,   /**< Reserved47 */
    kDmaRequestMux0Reserved48       = 48|0x100U,   /**< Reserved48 */
    kDmaRequestMux0Reserved49       = 49|0x100U,   /**< Reserved49 */
    kDmaRequestMux0Reserved50       = 50|0x100U,   /**< Reserved50 */
    kDmaRequestMux0Reserved51       = 51|0x100U,   /**< Reserved51 */
    kDmaRequestMux0Reserved52       = 52|0x100U,   /**< Reserved52 */
    kDmaRequestMux0Reserved53       = 53|0x100U,   /**< Reserved53 */
    kDmaRequestMux0Reserved54       = 54|0x100U,   /**< Reserved54 */
    kDmaRequestMux0Reserved55       = 55|0x100U,   /**< Reserved55 */
    kDmaRequestMux0Reserved56       = 56|0x100U,   /**< Reserved56 */
    kDmaRequestMux0Reserved57       = 57|0x100U,   /**< Reserved57 */
    kDmaRequestMux0Reserved58       = 58|0x100U,   /**< Reserved58 */
    kDmaRequestMux0Reserved59       = 59|0x100U,   /**< Reserved59 */
    kDmaRequestMux0Reserved60       = 60|0x100U,   /**< Reserved60 */
    kDmaRequestMux0Reserved61       = 61|0x100U,   /**< Reserved61 */
    kDmaRequestMux0Reserved62       = 62|0x100U,   /**< Reserved62 */
    kDmaRequestMux0Reserved63       = 63|0x100U,   /**< Reserved63 */
    kDmaRequestMux1Disable          = 0|0x200U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMux1SPI0Tx           = 1|0x200U,    /**< SPI0 Transmit (DMAMUX1) */
    kDmaRequestMux1SPI0Rx           = 2|0x200U,    /**< SPI0 Receive (DMAMUX1) */
    kDmaRequestMux1UART1Tx          = 3|0x200U,    /**< UART1 Transmit (DMAMUX1) */
    kDmaRequestMux1UART1Rx          = 4|0x200U,    /**< UART1 Receive (DMAMUX1) */
    kDmaRequestMux1I2C0             = 5|0x200U,    /**< I2C0 (DMAMUX1) */
    kDmaRequestMux1XBAR             = 6|0x200U,    /**< XBAR (DMAMUX1) */
    kDmaRequestMux1UART3Tx          = 7|0x200U,    /**< UART3 Transmit (DMAMUX1) */
    kDmaRequestMux1UART3Rx          = 8|0x200U,    /**< UART3 Receive (DMAMUX1) */
    kDmaRequestMux1AFEChannel0      = 9|0x200U,    /**< AFE channel 0 (DMAMUX1) */
    kDmaRequestMux1TMR0             = 10|0x200U,   /**< TMR0 (DMAMUX1) */
    kDmaRequestMux1TMR3             = 11|0x200U,   /**< TMR3 (DMAMUX1) */
    kDmaRequestMux1AFEChannel2      = 12|0x200U,   /**< AFE channel 2 (DMAMUX1) */
    kDmaRequestMux1PTE              = 13|0x200U,   /**< PTE (DMAMUX1) */
    kDmaRequestMux1CMP0             = 14|0x200U,   /**< CMP0 (DMAMUX1) */
    kDmaRequestMux1PTF              = 15|0x200U,   /**< PTF (DMAMUX1) */
    kDmaRequestMux1PTB              = 16|0x200U,   /**< PTB (DMAMUX1) */
    kDmaRequestMux1AlwaysEnabledslot17 = 17|0x200U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux1AlwaysEnabledslot18 = 18|0x200U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux1Reserved19       = 19|0x200U,   /**< Reserved19 */
    kDmaRequestMux1Reserved20       = 20|0x200U,   /**< Reserved20 */
    kDmaRequestMux1Reserved21       = 21|0x200U,   /**< Reserved21 */
    kDmaRequestMux1Reserved22       = 22|0x200U,   /**< Reserved22 */
    kDmaRequestMux1Reserved23       = 23|0x200U,   /**< Reserved23 */
    kDmaRequestMux1Reserved24       = 24|0x200U,   /**< Reserved24 */
    kDmaRequestMux1Reserved25       = 25|0x200U,   /**< Reserved25 */
    kDmaRequestMux1Reserved26       = 26|0x200U,   /**< Reserved26 */
    kDmaRequestMux1Reserved27       = 27|0x200U,   /**< Reserved27 */
    kDmaRequestMux1Reserved28       = 28|0x200U,   /**< Reserved28 */
    kDmaRequestMux1Reserved29       = 29|0x200U,   /**< Reserved29 */
    kDmaRequestMux1Reserved30       = 30|0x200U,   /**< Reserved30 */
    kDmaRequestMux1Reserved31       = 31|0x200U,   /**< Reserved31 */
    kDmaRequestMux1Reserved32       = 32|0x200U,   /**< Reserved32 */
    kDmaRequestMux1Reserved33       = 33|0x200U,   /**< Reserved33 */
    kDmaRequestMux1Reserved34       = 34|0x200U,   /**< Reserved34 */
    kDmaRequestMux1Reserved35       = 35|0x200U,   /**< Reserved35 */
    kDmaRequestMux1Reserved36       = 36|0x200U,   /**< Reserved36 */
    kDmaRequestMux1Reserved37       = 37|0x200U,   /**< Reserved37 */
    kDmaRequestMux1Reserved38       = 38|0x200U,   /**< Reserved38 */
    kDmaRequestMux1Reserved39       = 39|0x200U,   /**< Reserved39 */
    kDmaRequestMux1Reserved40       = 40|0x200U,   /**< Reserved40 */
    kDmaRequestMux1Reserved41       = 41|0x200U,   /**< Reserved41 */
    kDmaRequestMux1Reserved42       = 42|0x200U,   /**< Reserved42 */
    kDmaRequestMux1Reserved43       = 43|0x200U,   /**< Reserved43 */
    kDmaRequestMux1Reserved44       = 44|0x200U,   /**< Reserved44 */
    kDmaRequestMux1Reserved45       = 45|0x200U,   /**< Reserved45 */
    kDmaRequestMux1Reserved46       = 46|0x200U,   /**< Reserved46 */
    kDmaRequestMux1Reserved47       = 47|0x200U,   /**< Reserved47 */
    kDmaRequestMux1Reserved48       = 48|0x200U,   /**< Reserved48 */
    kDmaRequestMux1Reserved49       = 49|0x200U,   /**< Reserved49 */
    kDmaRequestMux1Reserved50       = 50|0x200U,   /**< Reserved50 */
    kDmaRequestMux1Reserved51       = 51|0x200U,   /**< Reserved51 */
    kDmaRequestMux1Reserved52       = 52|0x200U,   /**< Reserved52 */
    kDmaRequestMux1Reserved53       = 53|0x200U,   /**< Reserved53 */
    kDmaRequestMux1Reserved54       = 54|0x200U,   /**< Reserved54 */
    kDmaRequestMux1Reserved55       = 55|0x200U,   /**< Reserved55 */
    kDmaRequestMux1Reserved56       = 56|0x200U,   /**< Reserved56 */
    kDmaRequestMux1Reserved57       = 57|0x200U,   /**< Reserved57 */
    kDmaRequestMux1Reserved58       = 58|0x200U,   /**< Reserved58 */
    kDmaRequestMux1Reserved59       = 59|0x200U,   /**< Reserved59 */
    kDmaRequestMux1Reserved60       = 60|0x200U,   /**< Reserved60 */
    kDmaRequestMux1Reserved61       = 61|0x200U,   /**< Reserved61 */
    kDmaRequestMux1Reserved62       = 62|0x200U,   /**< Reserved62 */
    kDmaRequestMux1Reserved63       = 63|0x200U,   /**< Reserved63 */
    kDmaRequestMux2Disable          = 0|0x300U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMux2SPI1Tx           = 1|0x300U,    /**< SPI1 Transmit (DMAMUX2) */
    kDmaRequestMux2SPI1Rx           = 2|0x300U,    /**< SPI1 Receive (DMAMUX2) */
    kDmaRequestMux2UART1Tx          = 3|0x300U,    /**< UART1 Transmit (DMAMUX2) */
    kDmaRequestMux2UART1Rx          = 4|0x300U,    /**< UART1 Receive (DMAMUX2) */
    kDmaRequestMux2I2C1             = 5|0x300U,    /**< I2C1 (DMAMUX2) */
    kDmaRequestMux2XBAR             = 6|0x300U,    /**< XBAR (DMAMUX2) */
    kDmaRequestMux2UART2Tx          = 7|0x300U,    /**< UART2 Transmit (DMAMUX2) */
    kDmaRequestMux2UART2Rx          = 8|0x300U,    /**< UART2 Receive (DMAMUX2) */
    kDmaRequestMux2AFEChannel1      = 9|0x300U,    /**< AFE channel 1 (DMAMUX2) */
    kDmaRequestMux2TMR2             = 10|0x300U,   /**< TMR2 (DMAMUX2) */
    kDmaRequestMux2TMR1             = 11|0x300U,   /**< TMR1 (DMAMUX2) */
    kDmaRequestMux2AFEChannel3      = 12|0x300U,   /**< AFE channel 3 (DMAMUX2) */
    kDmaRequestMux2PTI              = 13|0x300U,   /**< PTI (DMAMUX2) */
    kDmaRequestMux2CMP1             = 14|0x300U,   /**< CMP1 (DMAMUX2) */
    kDmaRequestMux2PTG              = 15|0x300U,   /**< PTG (DMAMUX2) */
    kDmaRequestMux2PTC              = 16|0x300U,   /**< PTC (DMAMUX2) */
    kDmaRequestMux2AlwaysEnabledslot17 = 17|0x300U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux2AlwaysEnabledslot18 = 18|0x300U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux2Reserved19       = 19|0x300U,   /**< Reserved19 */
    kDmaRequestMux2Reserved20       = 20|0x300U,   /**< Reserved20 */
    kDmaRequestMux2Reserved21       = 21|0x300U,   /**< Reserved21 */
    kDmaRequestMux2Reserved22       = 22|0x300U,   /**< Reserved22 */
    kDmaRequestMux2Reserved23       = 23|0x300U,   /**< Reserved23 */
    kDmaRequestMux2Reserved24       = 24|0x300U,   /**< Reserved24 */
    kDmaRequestMux2Reserved25       = 25|0x300U,   /**< Reserved25 */
    kDmaRequestMux2Reserved26       = 26|0x300U,   /**< Reserved26 */
    kDmaRequestMux2Reserved27       = 27|0x300U,   /**< Reserved27 */
    kDmaRequestMux2Reserved28       = 28|0x300U,   /**< Reserved28 */
    kDmaRequestMux2Reserved29       = 29|0x300U,   /**< Reserved29 */
    kDmaRequestMux2Reserved30       = 30|0x300U,   /**< Reserved30 */
    kDmaRequestMux2Reserved31       = 31|0x300U,   /**< Reserved31 */
    kDmaRequestMux2Reserved32       = 32|0x300U,   /**< Reserved32 */
    kDmaRequestMux2Reserved33       = 33|0x300U,   /**< Reserved33 */
    kDmaRequestMux2Reserved34       = 34|0x300U,   /**< Reserved34 */
    kDmaRequestMux2Reserved35       = 35|0x300U,   /**< Reserved35 */
    kDmaRequestMux2Reserved36       = 36|0x300U,   /**< Reserved36 */
    kDmaRequestMux2Reserved37       = 37|0x300U,   /**< Reserved37 */
    kDmaRequestMux2Reserved38       = 38|0x300U,   /**< Reserved38 */
    kDmaRequestMux2Reserved39       = 39|0x300U,   /**< Reserved39 */
    kDmaRequestMux2Reserved40       = 40|0x300U,   /**< Reserved40 */
    kDmaRequestMux2Reserved41       = 41|0x300U,   /**< Reserved41 */
    kDmaRequestMux2Reserved42       = 42|0x300U,   /**< Reserved42 */
    kDmaRequestMux2Reserved43       = 43|0x300U,   /**< Reserved43 */
    kDmaRequestMux2Reserved44       = 44|0x300U,   /**< Reserved44 */
    kDmaRequestMux2Reserved45       = 45|0x300U,   /**< Reserved45 */
    kDmaRequestMux2Reserved46       = 46|0x300U,   /**< Reserved46 */
    kDmaRequestMux2Reserved47       = 47|0x300U,   /**< Reserved47 */
    kDmaRequestMux2Reserved48       = 48|0x300U,   /**< Reserved48 */
    kDmaRequestMux2Reserved49       = 49|0x300U,   /**< Reserved49 */
    kDmaRequestMux2Reserved50       = 50|0x300U,   /**< Reserved50 */
    kDmaRequestMux2Reserved51       = 51|0x300U,   /**< Reserved51 */
    kDmaRequestMux2Reserved52       = 52|0x300U,   /**< Reserved52 */
    kDmaRequestMux2Reserved53       = 53|0x300U,   /**< Reserved53 */
    kDmaRequestMux2Reserved54       = 54|0x300U,   /**< Reserved54 */
    kDmaRequestMux2Reserved55       = 55|0x300U,   /**< Reserved55 */
    kDmaRequestMux2Reserved56       = 56|0x300U,   /**< Reserved56 */
    kDmaRequestMux2Reserved57       = 57|0x300U,   /**< Reserved57 */
    kDmaRequestMux2Reserved58       = 58|0x300U,   /**< Reserved58 */
    kDmaRequestMux2Reserved59       = 59|0x300U,   /**< Reserved59 */
    kDmaRequestMux2Reserved60       = 60|0x300U,   /**< Reserved60 */
    kDmaRequestMux2Reserved61       = 61|0x300U,   /**< Reserved61 */
    kDmaRequestMux2Reserved62       = 62|0x300U,   /**< Reserved62 */
    kDmaRequestMux2Reserved63       = 63|0x300U,   /**< Reserved63 */
    kDmaRequestMux3Disable          = 0|0x400U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMux3SPI1Tx           = 1|0x400U,    /**< SPI1 Transmit (DMAMUX3) */
    kDmaRequestMux3SPI1Rx           = 2|0x400U,    /**< SPI1 Receive (DMAMUX3) */
    kDmaRequestMux3UART0Tx          = 3|0x400U,    /**< UART0 Transmit (DMAMUX3) */
    kDmaRequestMux3UART0Rx          = 4|0x400U,    /**< UART0 Receive (DMAMUX3) */
    kDmaRequestMux3I2C1             = 5|0x400U,    /**< I2C1 (DMAMUX3) */
    kDmaRequestMux3XBAR             = 6|0x400U,    /**< XBAR (DMAMUX3) */
    kDmaRequestMux3UART2Tx          = 7|0x400U,    /**< UART2 Transmit (DMAMUX3) */
    kDmaRequestMux3UART2Rx          = 8|0x400U,    /**< UART2 Receive (DMAMUX3) */
    kDmaRequestMux3AFEChannel1      = 9|0x400U,    /**< AFE channel 1 (DMAMUX3) */
    kDmaRequestMux3TMR2             = 10|0x400U,   /**< TMR2 (DMAMUX3) */
    kDmaRequestMux3TMR1             = 11|0x400U,   /**< TMR1 (DMAMUX3) */
    kDmaRequestMux3AFEChannel3      = 12|0x400U,   /**< AFE channel 3 (DMAMUX3) */
    kDmaRequestMux3ADC              = 13|0x400U,   /**< ADC (DMAMUX3) */
    kDmaRequestMux3CMP1             = 14|0x400U,   /**< CMP1 (DMAMUX3) */
    kDmaRequestMux3PTH              = 15|0x400U,   /**< PTH (DMAMUX3) */
    kDmaRequestMux3PTD              = 16|0x400U,   /**< PTD (DMAMUX3) */
    kDmaRequestMux3AlwaysEnabledslot17 = 17|0x400U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux3AlwaysEnabledslot18 = 18|0x400U, /**< DMAMUX Always Enabled slot */
    kDmaRequestMux3Reserved19       = 19|0x400U,   /**< Reserved19 */
    kDmaRequestMux3Reserved20       = 20|0x400U,   /**< Reserved20 */
    kDmaRequestMux3Reserved21       = 21|0x400U,   /**< Reserved21 */
    kDmaRequestMux3Reserved22       = 22|0x400U,   /**< Reserved22 */
    kDmaRequestMux3Reserved23       = 23|0x400U,   /**< Reserved23 */
    kDmaRequestMux3Reserved24       = 24|0x400U,   /**< Reserved24 */
    kDmaRequestMux3Reserved25       = 25|0x400U,   /**< Reserved25 */
    kDmaRequestMux3Reserved26       = 26|0x400U,   /**< Reserved26 */
    kDmaRequestMux3Reserved27       = 27|0x400U,   /**< Reserved27 */
    kDmaRequestMux3Reserved28       = 28|0x400U,   /**< Reserved28 */
    kDmaRequestMux3Reserved29       = 29|0x400U,   /**< Reserved29 */
    kDmaRequestMux3Reserved30       = 30|0x400U,   /**< Reserved30 */
    kDmaRequestMux3Reserved31       = 31|0x400U,   /**< Reserved31 */
    kDmaRequestMux3Reserved32       = 32|0x400U,   /**< Reserved32 */
    kDmaRequestMux3Reserved33       = 33|0x400U,   /**< Reserved33 */
    kDmaRequestMux3Reserved34       = 34|0x400U,   /**< Reserved34 */
    kDmaRequestMux3Reserved35       = 35|0x400U,   /**< Reserved35 */
    kDmaRequestMux3Reserved36       = 36|0x400U,   /**< Reserved36 */
    kDmaRequestMux3Reserved37       = 37|0x400U,   /**< Reserved37 */
    kDmaRequestMux3Reserved38       = 38|0x400U,   /**< Reserved38 */
    kDmaRequestMux3Reserved39       = 39|0x400U,   /**< Reserved39 */
    kDmaRequestMux3Reserved40       = 40|0x400U,   /**< Reserved40 */
    kDmaRequestMux3Reserved41       = 41|0x400U,   /**< Reserved41 */
    kDmaRequestMux3Reserved42       = 42|0x400U,   /**< Reserved42 */
    kDmaRequestMux3Reserved43       = 43|0x400U,   /**< Reserved43 */
    kDmaRequestMux3Reserved44       = 44|0x400U,   /**< Reserved44 */
    kDmaRequestMux3Reserved45       = 45|0x400U,   /**< Reserved45 */
    kDmaRequestMux3Reserved46       = 46|0x400U,   /**< Reserved46 */
    kDmaRequestMux3Reserved47       = 47|0x400U,   /**< Reserved47 */
    kDmaRequestMux3Reserved48       = 48|0x400U,   /**< Reserved48 */
    kDmaRequestMux3Reserved49       = 49|0x400U,   /**< Reserved49 */
    kDmaRequestMux3Reserved50       = 50|0x400U,   /**< Reserved50 */
    kDmaRequestMux3Reserved51       = 51|0x400U,   /**< Reserved51 */
    kDmaRequestMux3Reserved52       = 52|0x400U,   /**< Reserved52 */
    kDmaRequestMux3Reserved53       = 53|0x400U,   /**< Reserved53 */
    kDmaRequestMux3Reserved54       = 54|0x400U,   /**< Reserved54 */
    kDmaRequestMux3Reserved55       = 55|0x400U,   /**< Reserved55 */
    kDmaRequestMux3Reserved56       = 56|0x400U,   /**< Reserved56 */
    kDmaRequestMux3Reserved57       = 57|0x400U,   /**< Reserved57 */
    kDmaRequestMux3Reserved58       = 58|0x400U,   /**< Reserved58 */
    kDmaRequestMux3Reserved59       = 59|0x400U,   /**< Reserved59 */
    kDmaRequestMux3Reserved60       = 60|0x400U,   /**< Reserved60 */
    kDmaRequestMux3Reserved61       = 61|0x400U,   /**< Reserved61 */
    kDmaRequestMux3Reserved62       = 62|0x400U,   /**< Reserved62 */
    kDmaRequestMux3Reserved63       = 63|0x400U,   /**< Reserved63 */
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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_DMA_COUNT                             4u

/** DMA - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[256];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t SAR;                               /**< Source Address Register, array offset: 0x100, array step: 0x10 */
    __IO uint32_t DAR;                               /**< Destination Address Register, array offset: 0x104, array step: 0x10 */
    union {                                          /* offset: 0x108, array step: 0x10 */
      struct {                                         /* offset: 0x108, array step: 0x10 */
             uint8_t RESERVED_0[3];
             uint8_t DSR;                                /**< DMA_DSR0 register...DMA_DSR3 register., array offset: 0x10B, array step: 0x10 */
      } DMA_DSR_ACCESS8BIT;
      __IO uint32_t DSR_BCR;                           /**< DMA Status Register / Byte Count Register, array offset: 0x108, array step: 0x10 */
    };
    __IO uint32_t DCR;                               /**< DMA Control Register, array offset: 0x10C, array step: 0x10 */
  } DMA[DMA_DMA_COUNT];
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name SAR - Source Address Register */
/*! @{ */

#define DMA_SAR_SAR_MASK                         (0xFFFFFFFFU)
#define DMA_SAR_SAR_SHIFT                        (0U)
/*! SAR - SAR */
#define DMA_SAR_SAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_SAR_SAR_SHIFT)) & DMA_SAR_SAR_MASK)
/*! @} */

/* The count of DMA_SAR */
#define DMA_SAR_COUNT                            (4U)

/*! @name DAR - Destination Address Register */
/*! @{ */

#define DMA_DAR_DAR_MASK                         (0xFFFFFFFFU)
#define DMA_DAR_DAR_SHIFT                        (0U)
/*! DAR - DAR */
#define DMA_DAR_DAR(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DAR_DAR_SHIFT)) & DMA_DAR_DAR_MASK)
/*! @} */

/* The count of DMA_DAR */
#define DMA_DAR_COUNT                            (4U)

/* The count of DMA_DSR */
#define DMA_DSR_COUNT                            (4U)

/*! @name DSR_BCR - DMA Status Register / Byte Count Register */
/*! @{ */

#define DMA_DSR_BCR_BCR_MASK                     (0xFFFFFFU)
#define DMA_DSR_BCR_BCR_SHIFT                    (0U)
/*! BCR - BCR */
#define DMA_DSR_BCR_BCR(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BCR_SHIFT)) & DMA_DSR_BCR_BCR_MASK)

#define DMA_DSR_BCR_DONE_MASK                    (0x1000000U)
#define DMA_DSR_BCR_DONE_SHIFT                   (24U)
/*! DONE - Transactions Done
 *  0b0..DMA transfer is not yet complete. Writing a 0 has no effect.
 *  0b1..DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an
 *       interrupt service routine to clear the DMA interrupt and error bits.
 */
#define DMA_DSR_BCR_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_DONE_SHIFT)) & DMA_DSR_BCR_DONE_MASK)

#define DMA_DSR_BCR_BSY_MASK                     (0x2000000U)
#define DMA_DSR_BCR_BSY_SHIFT                    (25U)
/*! BSY - Busy
 *  0b0..DMA channel is inactive. Cleared when the DMA has finished the last transaction.
 *  0b1..BSY is set the first time the channel is enabled after a transfer is initiated.
 */
#define DMA_DSR_BCR_BSY(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BSY_SHIFT)) & DMA_DSR_BCR_BSY_MASK)

#define DMA_DSR_BCR_REQ_MASK                     (0x4000000U)
#define DMA_DSR_BCR_REQ_SHIFT                    (26U)
/*! REQ - Request
 *  0b0..No request is pending or the channel is currently active. Cleared when the channel is selected.
 *  0b1..The DMA channel has a transfer remaining and the channel is not selected.
 */
#define DMA_DSR_BCR_REQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_REQ_SHIFT)) & DMA_DSR_BCR_REQ_MASK)

#define DMA_DSR_BCR_BED_MASK                     (0x10000000U)
#define DMA_DSR_BCR_BED_SHIFT                    (28U)
/*! BED - Bus Error on Destination
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the write portion of a transfer.
 */
#define DMA_DSR_BCR_BED(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BED_SHIFT)) & DMA_DSR_BCR_BED_MASK)

#define DMA_DSR_BCR_BES_MASK                     (0x20000000U)
#define DMA_DSR_BCR_BES_SHIFT                    (29U)
/*! BES - Bus Error on Source
 *  0b0..No bus error occurred.
 *  0b1..The DMA channel terminated with a bus error during the read portion of a transfer.
 */
#define DMA_DSR_BCR_BES(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_BES_SHIFT)) & DMA_DSR_BCR_BES_MASK)

#define DMA_DSR_BCR_CE_MASK                      (0x40000000U)
#define DMA_DSR_BCR_CE_SHIFT                     (30U)
/*! CE - Configuration Error
 *  0b0..No configuration error exists.
 *  0b1..A configuration error has occurred.
 */
#define DMA_DSR_BCR_CE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DSR_BCR_CE_SHIFT)) & DMA_DSR_BCR_CE_MASK)
/*! @} */

/* The count of DMA_DSR_BCR */
#define DMA_DSR_BCR_COUNT                        (4U)

/*! @name DCR - DMA Control Register */
/*! @{ */

#define DMA_DCR_LCH2_MASK                        (0x3U)
#define DMA_DCR_LCH2_SHIFT                       (0U)
/*! LCH2 - Link Channel 2
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH2(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH2_SHIFT)) & DMA_DCR_LCH2_MASK)

#define DMA_DCR_LCH1_MASK                        (0xCU)
#define DMA_DCR_LCH1_SHIFT                       (2U)
/*! LCH1 - Link Channel 1
 *  0b00..DMA Channel 0
 *  0b01..DMA Channel 1
 *  0b10..DMA Channel 2
 *  0b11..DMA Channel 3
 */
#define DMA_DCR_LCH1(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LCH1_SHIFT)) & DMA_DCR_LCH1_MASK)

#define DMA_DCR_LINKCC_MASK                      (0x30U)
#define DMA_DCR_LINKCC_SHIFT                     (4U)
/*! LINKCC - Link Channel Control
 *  0b00..No channel-to-channel linking
 *  0b01..Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to 0.
 *  0b10..Perform a link to channel LCH1 after each cycle-steal transfer
 *  0b11..Perform a link to channel LCH1 after the BCR decrements to 0.
 */
#define DMA_DCR_LINKCC(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DCR_LINKCC_SHIFT)) & DMA_DCR_LINKCC_MASK)

#define DMA_DCR_D_REQ_MASK                       (0x80U)
#define DMA_DCR_D_REQ_SHIFT                      (7U)
/*! D_REQ - Disable Request
 *  0b0..ERQ bit is not affected.
 *  0b1..ERQ bit is cleared when the BCR is exhausted.
 */
#define DMA_DCR_D_REQ(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_D_REQ_SHIFT)) & DMA_DCR_D_REQ_MASK)

#define DMA_DCR_DMOD_MASK                        (0xF00U)
#define DMA_DCR_DMOD_SHIFT                       (8U)
/*! DMOD - Destination Address Modulo
 *  0b0000..Buffer disabled
 *  0b0001..Circular buffer size is 16 bytes
 *  0b0010..Circular buffer size is 32 bytes
 *  0b0011..Circular buffer size is 64 bytes
 *  0b0100..Circular buffer size is 128 bytes
 *  0b0101..Circular buffer size is 256 bytes
 *  0b0110..Circular buffer size is 512 bytes
 *  0b0111..Circular buffer size is 1 KB
 *  0b1000..Circular buffer size is 2 KB
 *  0b1001..Circular buffer size is 4 KB
 *  0b1010..Circular buffer size is 8 KB
 *  0b1011..Circular buffer size is 16 KB
 *  0b1100..Circular buffer size is 32 KB
 *  0b1101..Circular buffer size is 64 KB
 *  0b1110..Circular buffer size is 128 KB
 *  0b1111..Circular buffer size is 256 KB
 */
#define DMA_DCR_DMOD(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DMOD_SHIFT)) & DMA_DCR_DMOD_MASK)

#define DMA_DCR_SMOD_MASK                        (0xF000U)
#define DMA_DCR_SMOD_SHIFT                       (12U)
/*! SMOD - Source Address Modulo
 *  0b0000..Buffer disabled
 *  0b0001..Circular buffer size is 16 bytes.
 *  0b0010..Circular buffer size is 32 bytes.
 *  0b0011..Circular buffer size is 64 bytes.
 *  0b0100..Circular buffer size is 128 bytes.
 *  0b0101..Circular buffer size is 256 bytes.
 *  0b0110..Circular buffer size is 512 bytes.
 *  0b0111..Circular buffer size is 1 KB.
 *  0b1000..Circular buffer size is 2 KB.
 *  0b1001..Circular buffer size is 4 KB.
 *  0b1010..Circular buffer size is 8 KB.
 *  0b1011..Circular buffer size is 16 KB.
 *  0b1100..Circular buffer size is 32 KB.
 *  0b1101..Circular buffer size is 64 KB.
 *  0b1110..Circular buffer size is 128 KB.
 *  0b1111..Circular buffer size is 256 KB.
 */
#define DMA_DCR_SMOD(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SMOD_SHIFT)) & DMA_DCR_SMOD_MASK)

#define DMA_DCR_START_MASK                       (0x10000U)
#define DMA_DCR_START_SHIFT                      (16U)
/*! START - Start Transfer
 *  0b0..DMA inactive
 *  0b1..The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after
 *       one module clock and always reads as logic 0.
 */
#define DMA_DCR_START(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_START_SHIFT)) & DMA_DCR_START_MASK)

#define DMA_DCR_DSIZE_MASK                       (0x60000U)
#define DMA_DCR_DSIZE_SHIFT                      (17U)
/*! DSIZE - Destination Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_DSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DSIZE_SHIFT)) & DMA_DCR_DSIZE_MASK)

#define DMA_DCR_DINC_MASK                        (0x80000U)
#define DMA_DCR_DINC_SHIFT                       (19U)
/*! DINC - Destination Increment
 *  0b0..No change to the DAR after a successful transfer.
 *  0b1..The DAR increments by 1, 2, 4 depending upon the size of the transfer.
 */
#define DMA_DCR_DINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_DINC_SHIFT)) & DMA_DCR_DINC_MASK)

#define DMA_DCR_SSIZE_MASK                       (0x300000U)
#define DMA_DCR_SSIZE_SHIFT                      (20U)
/*! SSIZE - Source Size
 *  0b00..32-bit
 *  0b01..8-bit
 *  0b10..16-bit
 *  0b11..Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 */
#define DMA_DCR_SSIZE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SSIZE_SHIFT)) & DMA_DCR_SSIZE_MASK)

#define DMA_DCR_SINC_MASK                        (0x400000U)
#define DMA_DCR_SINC_SHIFT                       (22U)
/*! SINC - Source Increment
 *  0b0..No change to SAR after a successful transfer.
 *  0b1..The SAR increments by 1, 2, 4 as determined by the transfer size.
 */
#define DMA_DCR_SINC(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_SINC_SHIFT)) & DMA_DCR_SINC_MASK)

#define DMA_DCR_EADREQ_MASK                      (0x800000U)
#define DMA_DCR_EADREQ_SHIFT                     (23U)
/*! EADREQ - Enable asynchronous DMA requests
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define DMA_DCR_EADREQ(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_DCR_EADREQ_SHIFT)) & DMA_DCR_EADREQ_MASK)

#define DMA_DCR_UMNSM_MASK                       (0x3000000U)
#define DMA_DCR_UMNSM_SHIFT                      (24U)
/*! UMNSM - User Mode, Nonsecure Mode
 *  0b00..Channel attributes are set to the current mode.
 *  0b01..If the current mode is privileged and secure, then attributes are set to {privileged, secure}.
 *        Otherwise, writing this value terminates in an error.
 *  0b10..If the current mode is privileged and secure or if the current mode is user and secure, then attributes
 *        are set to {user, secure}. Otherwise, writing this value terminates in an error.
 *  0b11..If the current mode is privileged and secure, user and secure, or user and nonsecure, then attributes are set to {user, nonsecure}.
 */
#define DMA_DCR_UMNSM(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_UMNSM_SHIFT)) & DMA_DCR_UMNSM_MASK)

#define DMA_DCR_CHACR_MASK                       (0xC000000U)
#define DMA_DCR_CHACR_SHIFT                      (26U)
/*! CHACR - Channel Access Control */
#define DMA_DCR_CHACR(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_DCR_CHACR_SHIFT)) & DMA_DCR_CHACR_MASK)

#define DMA_DCR_AA_MASK                          (0x10000000U)
#define DMA_DCR_AA_SHIFT                         (28U)
/*! AA - Auto-align
 *  0b0..Auto-align disabled
 *  0b1..If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise,
 *       destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If
 *       auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.
 */
#define DMA_DCR_AA(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_AA_SHIFT)) & DMA_DCR_AA_MASK)

#define DMA_DCR_CS_MASK                          (0x20000000U)
#define DMA_DCR_CS_SHIFT                         (29U)
/*! CS - Cycle Steal
 *  0b0..DMA continuously makes read/write transfers until the BCR decrements to 0.
 *  0b1..Forces a single read/write transfer per request.
 */
#define DMA_DCR_CS(x)                            (((uint32_t)(((uint32_t)(x)) << DMA_DCR_CS_SHIFT)) & DMA_DCR_CS_MASK)

#define DMA_DCR_ERQ_MASK                         (0x40000000U)
#define DMA_DCR_ERQ_SHIFT                        (30U)
/*! ERQ - Enable Peripheral Request
 *  0b0..Peripheral request is ignored.
 *  0b1..Enables peripheral request to initiate transfer. A software-initiated request (setting START) is always enabled.
 */
#define DMA_DCR_ERQ(x)                           (((uint32_t)(((uint32_t)(x)) << DMA_DCR_ERQ_SHIFT)) & DMA_DCR_ERQ_MASK)

#define DMA_DCR_EINT_MASK                        (0x80000000U)
#define DMA_DCR_EINT_SHIFT                       (31U)
/*! EINT - Enable Interrupt on Completion of Transfer
 *  0b0..No interrupt is generated.
 *  0b1..Interrupt signal is enabled.
 */
#define DMA_DCR_EINT(x)                          (((uint32_t)(((uint32_t)(x)) << DMA_DCR_EINT_SHIFT)) & DMA_DCR_EINT_MASK)
/*! @} */

/* The count of DMA_DCR */
#define DMA_DCR_COUNT                            (4U)


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


#endif  /* PERI_DMA_H_ */

