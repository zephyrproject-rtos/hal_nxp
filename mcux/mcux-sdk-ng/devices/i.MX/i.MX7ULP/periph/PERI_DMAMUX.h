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
**         CMSIS Peripheral Access Layer for DMAMUX
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
 * @file PERI_DMAMUX.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(PERI_DMAMUX_H_)
#define PERI_DMAMUX_H_                           /**< Symbol preventing repeated inclusion */

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
    kDmaRequestMux0QSPIRx           = 1|0x100U,    /**< QSPI Receive */
    kDmaRequestMux0QSPITx           = 2|0x100U,    /**< QSPI Transmit */
    kDmaRequestMux0LTCRx            = 3|0x100U,    /**< Low Power Trusted Cryptography RX */
    kDmaRequestMux0LTCTx            = 4|0x100U,    /**< Low Power Trusted Cryptography TX */
    kDmaRequestMux0LPTMR0           = 5|0x100U,    /**< Low Power Timer */
    kDmaRequestMux0LPTMR1           = 6|0x100U,    /**< Low Power Timer */
    kDmaRequestMux0TPM0Channel0     = 7|0x100U,    /**< TPM0 Channel 0 */
    kDmaRequestMux0TPM0Channel1     = 8|0x100U,    /**< TPM0 Channel 1 */
    kDmaRequestMux0TPM0Channel2     = 9|0x100U,    /**< TPM0 Channel 2 */
    kDmaRequestMux0TPM0Channel3     = 10|0x100U,   /**< TPM0 Channel 3 */
    kDmaRequestMux0TPM0Channel4     = 11|0x100U,   /**< TPM0 Channel 4 */
    kDmaRequestMux0TPM0Channel5     = 12|0x100U,   /**< TPM0 Channel 5 */
    kDmaRequestMux0TPM0Overflow     = 13|0x100U,   /**< TPM0 Overflow */
    kDmaRequestMux0TPM1Channel0     = 14|0x100U,   /**< TPM1 Channel 0 */
    kDmaRequestMux0TPM1Channel1     = 15|0x100U,   /**< TPM1 Channel 1 */
    kDmaRequestMux0TPM1Overflow     = 16|0x100U,   /**< TPM1 Overflow */
    kDmaRequestMux0TPM2Channel0     = 17|0x100U,   /**< TPM2 Channel 0 */
    kDmaRequestMux0TPM2Channel1     = 18|0x100U,   /**< TPM2 Channel 1 */
    kDmaRequestMux0TPM2Overflow     = 19|0x100U,   /**< TPM2 Overflow */
    kDmaRequestMux0TPM3Channel0     = 20|0x100U,   /**< TPM3 Channel 0 */
    kDmaRequestMux0TPM3Channel1     = 21|0x100U,   /**< TPM3 Channel 1 */
    kDmaRequestMux0TPM3Channel2     = 22|0x100U,   /**< TPM3 Channel 2 */
    kDmaRequestMux0TPM3Channel3     = 23|0x100U,   /**< TPM3 Channel 3 */
    kDmaRequestMux0TPM3Channel4     = 24|0x100U,   /**< TPM3 Channel 4 */
    kDmaRequestMux0TPM3Channel5     = 25|0x100U,   /**< TPM3 Channel 5 */
    kDmaRequestMux0TPM3Overflow     = 26|0x100U,   /**< TPM3 Overflow */
    kDmaRequestMux0FlexIO0Shifter0  = 27|0x100U,   /**< FlexIO0 Shifter 0 */
    kDmaRequestMux0FlexIO0Shifter1  = 28|0x100U,   /**< FlexIO0 Shifter 1 */
    kDmaRequestMux0FlexIO0Shifter2  = 29|0x100U,   /**< FlexIO0 Shifter 2 */
    kDmaRequestMux0FlexIO0Shifter3  = 30|0x100U,   /**< FlexIO0 Shifter 3 */
    kDmaRequestMux0FlexIO0Shifter4  = 31|0x100U,   /**< FlexIO0 Shifter 4 */
    kDmaRequestMux0FlexIO0Shifter5  = 32|0x100U,   /**< FlexIO0 Shifter 5 */
    kDmaRequestMux0FlexIO0Shifter6  = 33|0x100U,   /**< FlexIO0 Shifter 6 */
    kDmaRequestMux0FlexIO0Shifter7  = 34|0x100U,   /**< FlexIO0 Shifter 7 */
    kDmaRequestMux0LPI2C0Rx         = 35|0x100U,   /**< LPI2C0 Master/Slave Receive */
    kDmaRequestMux0LPI2C0Tx         = 36|0x100U,   /**< LPI2C0 Master/Slave Transmit */
    kDmaRequestMux0LPI2C1Rx         = 37|0x100U,   /**< LPI2C1 Master/Slave Receive */
    kDmaRequestMux0LPI2C1Tx         = 38|0x100U,   /**< LPI2C1 Master/Slave Transmit */
    kDmaRequestMux0LPI2C2Rx         = 39|0x100U,   /**< LPI2C2 Master/Slave Receive */
    kDmaRequestMux0LPI2C2Tx         = 40|0x100U,   /**< LPI2C2 Master/Slave Transmit */
    kDmaRequestMux0LPI2C3Rx         = 41|0x100U,   /**< LPI2C3 Master/Slave Receive */
    kDmaRequestMux0LPI2C3Tx         = 42|0x100U,   /**< LPI2C3 Master/Slave Transmit */
    kDmaRequestMux0SAI0Rx           = 43|0x100U,   /**< SAI0 Receive */
    kDmaRequestMux0SAI0Tx           = 44|0x100U,   /**< SAI0 Transmit */
    kDmaRequestMux0SAI1Rx           = 45|0x100U,   /**< SAI1 Receive */
    kDmaRequestMux0SAI1Tx           = 46|0x100U,   /**< SAI1 Transmit */
    kDmaRequestMux0LPSPI0Rx         = 47|0x100U,   /**< LPSPI0 Receive */
    kDmaRequestMux0LPSPI0Tx         = 48|0x100U,   /**< LPSPI0 Transmit */
    kDmaRequestMux0LPSPI1Rx         = 49|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMux0LPSPI1Tx         = 50|0x100U,   /**< LPSPI1 Transmit */
    kDmaRequestMux0LPUART0Rx        = 51|0x100U,   /**< LPUART0 Receive */
    kDmaRequestMux0LPUART0Tx        = 52|0x100U,   /**< LPUART0 Transmit */
    kDmaRequestMux0LPUART1Rx        = 53|0x100U,   /**< LPUART1 Receive */
    kDmaRequestMux0LPUART1Tx        = 54|0x100U,   /**< LPUART1 Transmit */
    kDmaRequestMux0LPUART2Rx        = 55|0x100U,   /**< LPUART2 Receive */
    kDmaRequestMux0LPUART2Tx        = 56|0x100U,   /**< LPUART2 Transmit */
    kDmaRequestMux0LPUART3Rx        = 57|0x100U,   /**< LPUART3 Receive */
    kDmaRequestMux0LPUART3Tx        = 58|0x100U,   /**< LPUART3 Transmit */
    kDmaRequestMux0PCTLA            = 60|0x100U,   /**< Port A pin request */
    kDmaRequestMux0PCTLB            = 61|0x100U,   /**< Port B pin request */
    kDmaRequestMux0ADC0             = 62|0x100U,   /**< ADC0 Conversion Complete */
    kDmaRequestMux0ADC1             = 63|0x100U,   /**< ADC1 Conversion Complete */
    kDmaRequestMux0CMP0             = 64|0x100U,   /**< CMP0 Comparison Event */
    kDmaRequestMux0CMP1             = 65|0x100U,   /**< CMP1 Comparison Event */
    kDmaRequestMux0DAC0             = 66|0x100U,   /**< DAC0 Request */
    kDmaRequestMux0DAC1             = 67|0x100U,   /**< DAC1 Request */
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
    kDmaRequestMux1FlexIO1Shifter0  = 1|0x200U,    /**< FlexIO1 Shifter 0 */
    kDmaRequestMux1FlexIO1Shifter1  = 2|0x200U,    /**< FlexIO1 Shifter 1 */
    kDmaRequestMux1FlexIO1Shifter2  = 3|0x200U,    /**< FlexIO1 Shifter 2 */
    kDmaRequestMux1FlexIO1Shifter3  = 4|0x200U,    /**< FlexIO1 Shifter 3 */
    kDmaRequestMux1FlexIO1Shifter4  = 5|0x200U,    /**< FlexIO1 Shifter 4 */
    kDmaRequestMux1FlexIO1Shifter5  = 6|0x200U,    /**< FlexIO1 Shifter 5 */
    kDmaRequestMux1FlexIO1Shifter6  = 7|0x200U,    /**< FlexIO1 Shifter 6 */
    kDmaRequestMux1FlexIO1Shifter7  = 8|0x200U,    /**< FlexIO1 Shifter 7 */
    kDmaRequestMux1LPI2C4Rx         = 9|0x200U,    /**< LPI2C4 Master/Slave Receive */
    kDmaRequestMux1LPI2C4Tx         = 10|0x200U,   /**< LPI2C4 Master/Slave Transmit */
    kDmaRequestMux1LPI2C5Rx         = 11|0x200U,   /**< LPI2C5 Master/Slave Receive */
    kDmaRequestMux1LPI2C5Tx         = 12|0x200U,   /**< LPI2C5 Master/Slave Transmit */
    kDmaRequestMux1LPI2C6Rx         = 13|0x200U,   /**< LPI2C6 Master/Slave Receive */
    kDmaRequestMux1LPI2C6Tx         = 14|0x200U,   /**< LPI2C6 Master/Slave Transmit */
    kDmaRequestMux1LPI2C7Rx         = 15|0x200U,   /**< LPI2C7 Master/Slave Receive */
    kDmaRequestMux1LPI2C7Tx         = 16|0x200U,   /**< LPI2C7 Master/Slave Transmit */
    kDmaRequestMux1LPUART4Rx        = 17|0x200U,   /**< LPUART4 Receive */
    kDmaRequestMux1LPUART4Tx        = 18|0x200U,   /**< LPUART4 Transmit */
    kDmaRequestMux1LPUART5Rx        = 19|0x200U,   /**< LPUART5 Receive */
    kDmaRequestMux1LPUART5Tx        = 20|0x200U,   /**< LPUART5 Transmit */
    kDmaRequestMux1LPUART6Rx        = 21|0x200U,   /**< LPUART6 Receive */
    kDmaRequestMux1LPUART6Tx        = 22|0x200U,   /**< LPUART6 Transmit */
    kDmaRequestMux1LPUART7Rx        = 23|0x200U,   /**< LPUART7 Receive */
    kDmaRequestMux1LPUART7Tx        = 24|0x200U,   /**< LPUART7 Transmit */
    kDmaRequestMux1LPSPI2Rx         = 25|0x200U,   /**< LPSPI2 Receive */
    kDmaRequestMux1LPSPI2Tx         = 26|0x200U,   /**< LPSPI2 Transmit */
    kDmaRequestMux1LPSPI3Rx         = 27|0x200U,   /**< LPSPI3 Receive */
    kDmaRequestMux1LPSPI3Tx         = 28|0x200U,   /**< LPSPI3 Transmit */
    kDmaRequestMux1TPM4Channel0     = 29|0x200U,   /**< TPM4 Channel 0 */
    kDmaRequestMux1TPM4Channel1     = 30|0x200U,   /**< TPM4 Channel 1 */
    kDmaRequestMux1TPM4Channel2     = 31|0x200U,   /**< TPM4 Channel 2 */
    kDmaRequestMux1TPM4Channel3     = 32|0x200U,   /**< TPM4 Channel 3 */
    kDmaRequestMux1TPM4Channel4     = 33|0x200U,   /**< TPM4 Channel 4 */
    kDmaRequestMux1TPM4Channel5     = 34|0x200U,   /**< TPM4 Channel 5 */
    kDmaRequestMux1TPM4Overflow     = 35|0x200U,   /**< TPM4 Overflow */
    kDmaRequestMux1TPM5Channel0     = 36|0x200U,   /**< TPM5 Channel 0 */
    kDmaRequestMux1TPM5Channel1     = 37|0x200U,   /**< TPM5 Channel 1 */
    kDmaRequestMux1TPM5Overflow     = 38|0x200U,   /**< TPM5 Overflow */
    kDmaRequestMux1TPM6Channel3     = 39|0x200U,   /**< TPM6 Channel 3 */
    kDmaRequestMux1TPM6Channel4     = 40|0x200U,   /**< TPM6 Channel 4 */
    kDmaRequestMux1TPM6Overflow     = 41|0x200U,   /**< TPM6 Overflow */
    kDmaRequestMux1TPM7Channel0     = 42|0x200U,   /**< TPM7 Channel 0 */
    kDmaRequestMux1TPM7Channel1     = 43|0x200U,   /**< TPM7 Channel 1 */
    kDmaRequestMux1TPM7Channel2     = 44|0x200U,   /**< TPM7 Channel 2 */
    kDmaRequestMux1TPM7Channel3     = 45|0x200U,   /**< TPM7 Channel 3 */
    kDmaRequestMux1TPM7Channel4     = 46|0x200U,   /**< TPM7 Channel 4 */
    kDmaRequestMux1TPM7Channel5     = 47|0x200U,   /**< TPM7 Channel 5 */
    kDmaRequestMux1TPM7Overflow     = 48|0x200U,   /**< TPM7 Overflow */
    kDmaRequestMux1PCTLC            = 51|0x200U,   /**< Port Interrupt Control module C */
    kDmaRequestMux1PCTLD            = 52|0x200U,   /**< Port Interrupt Control module D */
    kDmaRequestMux1PCTLE            = 53|0x200U,   /**< Port Interrupt Control module E */
    kDmaRequestMux1PCTLF            = 54|0x200U,   /**< Port Interrupt Control module F */
    kDmaRequestMux1QSPIRx           = 57|0x200U,   /**< QSPI Receive */
    kDmaRequestMux1QSPITx           = 58|0x200U,   /**< QSPI Transmit */
    kDmaRequestMux1SAI0Rx           = 59|0x200U,   /**< SAI0 Receive */
    kDmaRequestMux1SAI0Tx           = 60|0x200U,   /**< SAI0 Transmit */
    kDmaRequestMux1SAI1Rx           = 61|0x200U,   /**< SAI1 Receive */
    kDmaRequestMux1SAI1Tx           = 62|0x200U,   /**< SAI1 Transmit */
    kDmaRequestMux1PCTLA            = 63|0x200U,   /**< Port Interrupt Control module A */
    kDmaRequestMux1PCTLB            = 64|0x200U,   /**< Port Interrupt Control module B */
} dma1_request_source_t;

/* @} */
#endif /* DMA1_REQUEST_SOURCE_T_ */


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
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */
#define DMAMUX_CHCFG_REG_ARRAY_COUNT              32u

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHCFG[DMAMUX_CHCFG_REG_ARRAY_COUNT]; /**< Channel 0 Configuration Register..Channel 31 Configuration Register, array offset: 0x0, array step: 0x4 */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel 0 Configuration Register..Channel 31 Configuration Register */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0x7FU)
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
/*! SOURCE - DMA Channel Source (Slot Number) */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)

#define DMAMUX_CHCFG_A_ON_MASK                   (0x20000000U)
#define DMAMUX_CHCFG_A_ON_SHIFT                  (29U)
/*! A_ON - DMA Channel Always Enable
 *  0b0..DMA Channel Always ON function is disabled
 *  0b1..DMA Channel Always ON function is enabled
 */
#define DMAMUX_CHCFG_A_ON(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_A_ON_SHIFT)) & DMAMUX_CHCFG_A_ON_MASK)

#define DMAMUX_CHCFG_TRIG_MASK                   (0x40000000U)
#define DMAMUX_CHCFG_TRIG_SHIFT                  (30U)
/*! TRIG - DMA Channel Trigger Enable
 *  0b0..Triggering is disabled. If triggering is disabled and ENBL is set, the DMA Channel will simply route the
 *       specified source to the DMA channel. (Normal mode)
 *  0b1..Triggering is enabled. If triggering is enabled and ENBL is set, the DMA_CH_MUX is in Periodic Trigger mode.
 */
#define DMAMUX_CHCFG_TRIG(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_TRIG_SHIFT)) & DMAMUX_CHCFG_TRIG_MASK)

#define DMAMUX_CHCFG_ENBL_MASK                   (0x80000000U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (31U)
/*! ENBL - DMA Mux Channel Enable
 *  0b0..DMA Mux channel is disabled
 *  0b1..DMA Mux channel is enabled
 */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)
/*! @} */

/* The count of DMAMUX_CHCFG */
#define DMAMUX_CHCFG_COUNT                       (32U)


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


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


#endif  /* PERI_DMAMUX_H_ */

