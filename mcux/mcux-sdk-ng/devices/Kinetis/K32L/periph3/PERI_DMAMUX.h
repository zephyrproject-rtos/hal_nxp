/*
** ###################################################################
**     Processors:          K32L3A60VPJ1A_cm0plus
**                          K32L3A60VPJ1A_cm4
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMAMUX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(PERI_DMAMUX_H_)
#define PERI_DMAMUX_H_                           /**< Symbol preventing repeated inclusion */

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
#if !defined(DMA_REQUEST_SOURCE_T_)
#define DMA_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{ */

/*******************************************************************************
 * Definitions
*******************************************************************************/

/*!
 * @brief Enumeration for the DMA hardware request
 *
 * Defines the enumeration for the DMA hardware request collections.
 */
typedef enum _dma_request_source
{
    kDmaRequestMux0LLWU0            = 0|0x100U,    /**< LLWU0 Wakeup */
    kDmaRequestMux0LPTMR0           = 1|0x100U,    /**< LPTMR0 Trigger */
    kDmaRequestMux0LPTMR1           = 2|0x100U,    /**< LPTMR1 Trigger */
    kDmaRequestMux0TPM0Channel0     = 3|0x100U,    /**< TPM0 Channel 0 */
    kDmaRequestMux0TPM0Channel1     = 4|0x100U,    /**< TPM0 Channel 1 */
    kDmaRequestMux0TPM0Channel2     = 5|0x100U,    /**< TPM0 Channel 2 */
    kDmaRequestMux0TPM0Channel3     = 6|0x100U,    /**< TPM0 Channel 3 */
    kDmaRequestMux0TPM0Channel4     = 7|0x100U,    /**< TPM0 Channel 4 */
    kDmaRequestMux0TPM0Channel5     = 8|0x100U,    /**< TPM0 Channel 5 */
    kDmaRequestMux0TPM0Overflow     = 9|0x100U,    /**< TPM0 Overflow */
    kDmaRequestMux0TPM1Channel0     = 10|0x100U,   /**< TPM1 Channel 0 */
    kDmaRequestMux0TPM1Channel1     = 11|0x100U,   /**< TPM1 Channel 1 */
    kDmaRequestMux0TPM1Overflow     = 12|0x100U,   /**< TPM1 Overflow */
    kDmaRequestMux0TPM2Channel0     = 13|0x100U,   /**< TPM2 Channel 0 */
    kDmaRequestMux0TPM2Channel1     = 14|0x100U,   /**< TPM2 Channel 1 */
    kDmaRequestMux0TPM2Channel2     = 15|0x100U,   /**< TPM2 Channel 2 */
    kDmaRequestMux0TPM2Channel3     = 16|0x100U,   /**< TPM2 Channel 3 */
    kDmaRequestMux0TPM2Channel4     = 17|0x100U,   /**< TPM2 Channel 4 */
    kDmaRequestMux0TPM2Channel5     = 18|0x100U,   /**< TPM2 Channel 5 */
    kDmaRequestMux0TPM2Overflow     = 19|0x100U,   /**< TPM2 Overflow */
    kDmaRequestMux0EMVSIM0Rx        = 20|0x100U,   /**< EMVSIM0 Receive */
    kDmaRequestMux0EMVSIM0Tx        = 21|0x100U,   /**< EMVSIM0 Transmit */
    kDmaRequestMux0FLEXIO0Channel0  = 22|0x100U,   /**< FLEXIO0 Channel 0 */
    kDmaRequestMux0FLEXIO0Channel1  = 23|0x100U,   /**< FLEXIO0 Channel 1 */
    kDmaRequestMux0FLEXIO0Channel2  = 24|0x100U,   /**< FLEXIO0 Channel 2 */
    kDmaRequestMux0FLEXIO0Channel3  = 25|0x100U,   /**< FLEXIO0 Channel 3 */
    kDmaRequestMux0FLEXIO0Channel4  = 26|0x100U,   /**< FLEXIO0 Channel 4 */
    kDmaRequestMux0FLEXIO0Channel5  = 27|0x100U,   /**< FLEXIO0 Channel 5 */
    kDmaRequestMux0FLEXIO0Channel6  = 28|0x100U,   /**< FLEXIO0 Channel 6 */
    kDmaRequestMux0FLEXIO0Channel7  = 29|0x100U,   /**< FLEXIO0 Channel 7 */
    kDmaRequestMux0LPI2C0Rx         = 30|0x100U,   /**< LPI2C0 Receive */
    kDmaRequestMux0LPI2C0Tx         = 31|0x100U,   /**< LPI2C0 Transmit */
    kDmaRequestMux0LPI2C1Rx         = 32|0x100U,   /**< LPI2C1 Receive */
    kDmaRequestMux0LPI2C1Tx         = 33|0x100U,   /**< LPI2C1 Transmit */
    kDmaRequestMux0LPI2C2Rx         = 34|0x100U,   /**< LPI2C2 Receive */
    kDmaRequestMux0LPI2C2Tx         = 35|0x100U,   /**< LPI2C2 Transmit */
    kDmaRequestMux0I2S0Rx           = 36|0x100U,   /**< I2S0 Receive */
    kDmaRequestMux0I2S0Tx           = 37|0x100U,   /**< I2S0 Transmit */
    kDmaRequestMux0LPSPI0Rx         = 38|0x100U,   /**< LPSPI0 Receive */
    kDmaRequestMux0LPSPI0Tx         = 39|0x100U,   /**< LPSPI0 Transmit */
    kDmaRequestMux0LPSPI1Rx         = 40|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMux0LPSPI1Tx         = 41|0x100U,   /**< LPSPI1 Transmit */
    kDmaRequestMux0LPSPI2Rx         = 42|0x100U,   /**< LPSPI2 Receive */
    kDmaRequestMux0LPSPI2Tx         = 43|0x100U,   /**< LPSPI2 Transmit */
    kDmaRequestMux0LPUART0Rx        = 44|0x100U,   /**< LPUART0 Receive */
    kDmaRequestMux0LPUART0Tx        = 45|0x100U,   /**< LPUART0 Transmit */
    kDmaRequestMux0LPUART1Rx        = 46|0x100U,   /**< LPUART1 Receive */
    kDmaRequestMux0LPUART1Tx        = 47|0x100U,   /**< LPUART1 Transmit */
    kDmaRequestMux0LPUART2Rx        = 48|0x100U,   /**< LPUART2 Receive */
    kDmaRequestMux0LPUART2Tx        = 49|0x100U,   /**< LPUART2 Transmit */
    kDmaRequestMux0PORTA            = 50|0x100U,   /**< PORTA Pin Request */
    kDmaRequestMux0PORTB            = 51|0x100U,   /**< PORTB Pin Request */
    kDmaRequestMux0PORTC            = 52|0x100U,   /**< PORTC Pin Request */
    kDmaRequestMux0PORTD            = 53|0x100U,   /**< PORTD Pin Request */
    kDmaRequestMux0LPADC0           = 54|0x100U,   /**< LPADC0 Conversion Complete */
    kDmaRequestMux0LPCMP0           = 55|0x100U,   /**< LPCMP0 Comparator Trigger */
    kDmaRequestMux0DAC0             = 56|0x100U,   /**< DAC0 Conversion Complete */
    kDmaRequestMux0CAU3             = 57|0x100U,   /**< CAU3 Data Request */
    kDmaRequestMux0LPTMR2           = 58|0x100U,   /**< LPTMR2 Trigger */
    kDmaRequestMux0LPSPI3Rx         = 59|0x100U,   /**< LPSPI3 Receive */
    kDmaRequestMux0LPSPI3Tx         = 60|0x100U,   /**< LPSPI3 Transmit */
    kDmaRequestMux0LPUART3Rx        = 61|0x100U,   /**< LPUART3 Receive */
    kDmaRequestMux0LPUART3Tx        = 62|0x100U,   /**< LPUART3 Transmit */
    kDmaRequestMux0PORTE            = 63|0x100U,   /**< PORTE Pin Request */
    kDmaRequestMux1LLWU1            = 0|0x200U,    /**< LLWU1 Wakeup */
    kDmaRequestMux1CAU3             = 1|0x200U,    /**< CAU3 Data Request */
    kDmaRequestMux1LPTMR2           = 2|0x200U,    /**< LPTMR2 Trigger */
    kDmaRequestMux1TPM3Channel0     = 3|0x200U,    /**< TPM3 Channel 0 */
    kDmaRequestMux1TPM3Channel1     = 4|0x200U,    /**< TPM3 Channel 1 */
    kDmaRequestMux1TPM3Overflow     = 5|0x200U,    /**< TPM3 Overflow */
    kDmaRequestMux1LPI2C3Rx         = 6|0x200U,    /**< LPI2C3 Receive */
    kDmaRequestMux1LPI2C3Tx         = 7|0x200U,    /**< LPI2C3 Transmit */
    kDmaRequestMux1RF0Rx            = 8|0x200U,    /**< 2.4GHz Radio 0 Receive */
    kDmaRequestMux1LPSPI3Rx         = 9|0x200U,    /**< LPSPI3 Receive */
    kDmaRequestMux1LPSPI3Tx         = 10|0x200U,   /**< LPSPI3 Transmit */
    kDmaRequestMux1LPUART3Rx        = 11|0x200U,   /**< LPUART3 Receive */
    kDmaRequestMux1LPUART3Tx        = 12|0x200U,   /**< LPUART3 Transmit */
    kDmaRequestMux1PORTE            = 13|0x200U,   /**< PORTE Pin Request */
    kDmaRequestMux1LPCMP1           = 14|0x200U,   /**< LPCMP1 Comparator Trigger */
    kDmaRequestMux1LPTMR1           = 15|0x200U,   /**< LPTMR1 Trigger */
    kDmaRequestMux1FLEXIO0Channel0  = 16|0x200U,   /**< FLEXIO0 Channel 0 */
    kDmaRequestMux1FLEXIO0Channel1  = 17|0x200U,   /**< FLEXIO0 Channel 1 */
    kDmaRequestMux1FLEXIO0Channel2  = 18|0x200U,   /**< FLEXIO0 Channel 2 */
    kDmaRequestMux1FLEXIO0Channel3  = 19|0x200U,   /**< FLEXIO0 Channel 3 */
    kDmaRequestMux1FLEXIO0Channel4  = 20|0x200U,   /**< FLEXIO0 Channel 4 */
    kDmaRequestMux1FLEXIO0Channel5  = 21|0x200U,   /**< FLEXIO0 Channel 5 */
    kDmaRequestMux1FLEXIO0Channel6  = 22|0x200U,   /**< FLEXIO0 Channel 6 */
    kDmaRequestMux1FLEXIO0Channel7  = 23|0x200U,   /**< FLEXIO0 Channel 7 */
    kDmaRequestMux1I2S0Rx           = 24|0x200U,   /**< I2S0 Receive */
    kDmaRequestMux1I2S0Tx           = 25|0x200U,   /**< I2S0 Transmit */
    kDmaRequestMux1PORTA            = 26|0x200U,   /**< PORTA Pin Request */
    kDmaRequestMux1PORTB            = 27|0x200U,   /**< PORTB Pin Request */
    kDmaRequestMux1PORTC            = 28|0x200U,   /**< PORTC Pin Request */
    kDmaRequestMux1PORTD            = 29|0x200U,   /**< PORTD Pin Request */
    kDmaRequestMux1LPADC0           = 30|0x200U,   /**< LPADC0 Conversion Complete */
    kDmaRequestMux1DAC0             = 31|0x200U,   /**< DAC0 Conversion Complete */
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
   -- DMAMUX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Peripheral_Access_Layer DMAMUX Peripheral Access Layer
 * @{
 */

/** DMAMUX - Size of Registers Arrays */
#define DMAMUX_CHCFG_REG_ARRAY_COUNT              16u

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint32_t CHCFG[DMAMUX_CHCFG_REG_ARRAY_COUNT]; /**< Channel 0 Configuration Register..Channel 15 Configuration Register, array offset: 0x0, array step: 0x4, irregular array, not all indices are valid */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel 0 Configuration Register..Channel 15 Configuration Register */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)  /* Merged from fields with different position or width, of widths (5, 6), largest definition used */
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
/*! SOURCE - DMA Channel Source (Slot Number) */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint32_t)(((uint32_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)  /* Merged from fields with different position or width, of widths (5, 6), largest definition used */

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
#define DMAMUX_CHCFG_COUNT                       (16U)


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

