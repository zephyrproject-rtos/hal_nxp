/*
** ###################################################################
**     Processors:          MIMXRT1021CAF4A
**                          MIMXRT1021CAF4B
**                          MIMXRT1021CAG4A
**                          MIMXRT1021CAG4B
**                          MIMXRT1021DAF5A
**                          MIMXRT1021DAF5B
**                          MIMXRT1021DAG5A
**                          MIMXRT1021DAG5B
**                          MIMXRT1024CAG4A
**                          MIMXRT1024CAG4B
**                          MIMXRT1024DAG5A
**                          MIMXRT1024DAG5B
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
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
**     - rev. 0.1 (2017-11-06)
**         Initial version.
**     - rev. 1.0 (2018-11-27)
**         Update header files to align with IMXRT1020RM Rev.1.
**     - rev. 1.1 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.2 (2021-08-10)
**         Update header files to align with IMXRT1020RM Rev.2.
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

#if (defined(CPU_MIMXRT1021CAF4A) || defined(CPU_MIMXRT1021CAF4B) || defined(CPU_MIMXRT1021CAG4A) || defined(CPU_MIMXRT1021CAG4B) || defined(CPU_MIMXRT1021DAF5A) || defined(CPU_MIMXRT1021DAF5B) || defined(CPU_MIMXRT1021DAG5A) || defined(CPU_MIMXRT1021DAG5B))
#include "MIMXRT1021_COMMON.h"
#elif (defined(CPU_MIMXRT1024CAG4A) || defined(CPU_MIMXRT1024CAG4B) || defined(CPU_MIMXRT1024DAG5A) || defined(CPU_MIMXRT1024DAG5B))
#include "MIMXRT1024_COMMON.h"
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
    kDmaRequestMuxFlexIO1Request0Request1 = 0|0x100U, /**< FlexIO1 Request0 and Request1 */
    kDmaRequestMuxFlexIO1Request4Request5 = 1|0x100U, /**< FlexIO1 Request4 and Request5 */
    kDmaRequestMuxLPUART1Tx         = 2|0x100U,    /**< LPUART1 Transmit */
    kDmaRequestMuxLPUART1Rx         = 3|0x100U,    /**< LPUART1 Receive */
    kDmaRequestMuxLPUART3Tx         = 4|0x100U,    /**< LPUART3 Transmit */
    kDmaRequestMuxLPUART3Rx         = 5|0x100U,    /**< LPUART3 Receive */
    kDmaRequestMuxLPUART5Tx         = 6|0x100U,    /**< LPUART5 Transmit */
    kDmaRequestMuxLPUART5Rx         = 7|0x100U,    /**< LPUART5 Receive */
    kDmaRequestMuxLPUART7Tx         = 8|0x100U,    /**< LPUART7 Transmit */
    kDmaRequestMuxLPUART7Rx         = 9|0x100U,    /**< LPUART7 Receive */
    kDmaRequestMuxLPSPI1Rx          = 13|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMuxLPSPI1Tx          = 14|0x100U,   /**< LPSPI1 Transmit */
    kDmaRequestMuxLPSPI3Rx          = 15|0x100U,   /**< LPSPI3 Receive */
    kDmaRequestMuxLPSPI3Tx          = 16|0x100U,   /**< LPSPI3 Transmit */
    kDmaRequestMuxLPI2C1            = 17|0x100U,   /**< LPI2C1 */
    kDmaRequestMuxLPI2C3            = 18|0x100U,   /**< LPI2C3 */
    kDmaRequestMuxSai1Rx            = 19|0x100U,   /**< SAI1 Receive */
    kDmaRequestMuxSai1Tx            = 20|0x100U,   /**< SAI1 Transmit */
    kDmaRequestMuxSai2Rx            = 21|0x100U,   /**< SAI2 Receive */
    kDmaRequestMuxSai2Tx            = 22|0x100U,   /**< SAI2 Transmit */
    kDmaRequestMuxADC_ETC           = 23|0x100U,   /**< ADC_ETC */
    kDmaRequestMuxADC1              = 24|0x100U,   /**< ADC1 */
    kDmaRequestMuxACMP1             = 25|0x100U,   /**< ACMP1 */
    kDmaRequestMuxACMP3             = 26|0x100U,   /**< ACMP3 */
    kDmaRequestMuxFlexSPIRx         = 28|0x100U,   /**< FlexSPI Receive */
    kDmaRequestMuxFlexSPITx         = 29|0x100U,   /**< FlexSPI Transmit */
    kDmaRequestMuxXBAR1Request0     = 30|0x100U,   /**< XBAR1 Request 0 */
    kDmaRequestMuxXBAR1Request1     = 31|0x100U,   /**< XBAR1 Request 1 */
    kDmaRequestMuxFlexPWM1CaptureSub0 = 32|0x100U, /**< FlexPWM1 Capture sub-module0 */
    kDmaRequestMuxFlexPWM1CaptureSub1 = 33|0x100U, /**< FlexPWM1 Capture sub-module1 */
    kDmaRequestMuxFlexPWM1CaptureSub2 = 34|0x100U, /**< FlexPWM1 Capture sub-module2 */
    kDmaRequestMuxFlexPWM1CaptureSub3 = 35|0x100U, /**< FlexPWM1 Capture sub-module3 */
    kDmaRequestMuxFlexPWM1ValueSub0 = 36|0x100U,   /**< FlexPWM1 Value sub-module0 */
    kDmaRequestMuxFlexPWM1ValueSub1 = 37|0x100U,   /**< FlexPWM1 Value sub-module1 */
    kDmaRequestMuxFlexPWM1ValueSub2 = 38|0x100U,   /**< FlexPWM1 Value sub-module2 */
    kDmaRequestMuxFlexPWM1ValueSub3 = 39|0x100U,   /**< FlexPWM1 Value sub-module3 */
    kDmaRequestMuxQTIMER1CaptTimer0 = 48|0x100U,   /**< TMR1 Capture timer 0 */
    kDmaRequestMuxQTIMER1CaptTimer1 = 49|0x100U,   /**< TMR1 Capture timer 1 */
    kDmaRequestMuxQTIMER1CaptTimer2 = 50|0x100U,   /**< TMR1 Capture timer 2 */
    kDmaRequestMuxQTIMER1CaptTimer3 = 51|0x100U,   /**< TMR1 Capture timer 3 */
    kDmaRequestMuxQTIMER1Cmpld1Timer0Cmpld2Timer1 = 52|0x100U, /**< TMR1 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER1Cmpld1Timer1Cmpld2Timer0 = 53|0x100U, /**< TMR1 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER1Cmpld1Timer2Cmpld2Timer3 = 54|0x100U, /**< TMR1 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER1Cmpld1Timer3Cmpld2Timer2 = 55|0x100U, /**< TMR1 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDmaRequestMuxFlexIO1Request2Request3 = 64|0x100U, /**< FlexIO1 Request2 and Request3 */
    kDmaRequestMuxFlexIO1Request6Request7 = 65|0x100U, /**< FlexIO1 Request6 and Request7 */
    kDmaRequestMuxLPUART2Tx         = 66|0x100U,   /**< LPUART2 Transmit */
    kDmaRequestMuxLPUART2Rx         = 67|0x100U,   /**< LPUART2 Receive */
    kDmaRequestMuxLPUART4Tx         = 68|0x100U,   /**< LPUART4 Transmit */
    kDmaRequestMuxLPUART4Rx         = 69|0x100U,   /**< LPUART4 Receive */
    kDmaRequestMuxLPUART6Tx         = 70|0x100U,   /**< LPUART6 Transmit */
    kDmaRequestMuxLPUART6Rx         = 71|0x100U,   /**< LPUART6 Receive */
    kDmaRequestMuxLPUART8Tx         = 72|0x100U,   /**< LPUART8 Transmit */
    kDmaRequestMuxLPUART8Rx         = 73|0x100U,   /**< LPUART8 Receive */
    kDmaRequestMuxLPSPI2Rx          = 77|0x100U,   /**< LPSPI2 Receive */
    kDmaRequestMuxLPSPI2Tx          = 78|0x100U,   /**< LPSPI2 Transmit */
    kDmaRequestMuxLPSPI4Rx          = 79|0x100U,   /**< LPSPI4 Receive */
    kDmaRequestMuxLPSPI4Tx          = 80|0x100U,   /**< LPSPI4 Transmit */
    kDmaRequestMuxLPI2C2            = 81|0x100U,   /**< LPI2C2 */
    kDmaRequestMuxLPI2C4            = 82|0x100U,   /**< LPI2C4 */
    kDmaRequestMuxSai3Rx            = 83|0x100U,   /**< SAI3 Receive */
    kDmaRequestMuxSai3Tx            = 84|0x100U,   /**< SAI3 Transmit */
    kDmaRequestMuxSpdifRx           = 85|0x100U,   /**< SPDIF Receive */
    kDmaRequestMuxSpdifTx           = 86|0x100U,   /**< SPDIF Transmit */
    kDmaRequestMuxADC2              = 88|0x100U,   /**< ADC2 */
    kDmaRequestMuxACMP2             = 89|0x100U,   /**< ACMP2 */
    kDmaRequestMuxACMP4             = 90|0x100U,   /**< ACMP4 */
    kDmaRequestMuxEnetTimer0        = 92|0x100U,   /**< ENET Timer0 */
    kDmaRequestMuxEnetTimer1        = 93|0x100U,   /**< ENET Timer1 */
    kDmaRequestMuxXBAR1Request2     = 94|0x100U,   /**< XBAR1 Request 2 */
    kDmaRequestMuxXBAR1Request3     = 95|0x100U,   /**< XBAR1 Request 3 */
    kDmaRequestMuxFlexPWM2CaptureSub0 = 96|0x100U, /**< FlexPWM2 Capture sub-module0 */
    kDmaRequestMuxFlexPWM2CaptureSub1 = 97|0x100U, /**< FlexPWM2 Capture sub-module1 */
    kDmaRequestMuxFlexPWM2CaptureSub2 = 98|0x100U, /**< FlexPWM2 Capture sub-module2 */
    kDmaRequestMuxFlexPWM2CaptureSub3 = 99|0x100U, /**< FlexPWM2 Capture sub-module3 */
    kDmaRequestMuxFlexPWM2ValueSub0 = 100|0x100U,  /**< FlexPWM2 Value sub-module0 */
    kDmaRequestMuxFlexPWM2ValueSub1 = 101|0x100U,  /**< FlexPWM2 Value sub-module1 */
    kDmaRequestMuxFlexPWM2ValueSub2 = 102|0x100U,  /**< FlexPWM2 Value sub-module2 */
    kDmaRequestMuxFlexPWM2ValueSub3 = 103|0x100U,  /**< FlexPWM2 Value sub-module3 */
    kDmaRequestMuxQTIMER2CaptTimer0 = 112|0x100U,  /**< TMR2 Capture timer 0 */
    kDmaRequestMuxQTIMER2CaptTimer1 = 113|0x100U,  /**< TMR2 Capture timer 1 */
    kDmaRequestMuxQTIMER2CaptTimer2 = 114|0x100U,  /**< TMR2 Capture timer 2 */
    kDmaRequestMuxQTIMER2CaptTimer3 = 115|0x100U,  /**< TMR2 Capture timer 3 */
    kDmaRequestMuxQTIMER2Cmpld1Timer0Cmpld2Timer1 = 116|0x100U, /**< TMR2 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER2Cmpld1Timer1Cmpld2Timer0 = 117|0x100U, /**< TMR2 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER2Cmpld1Timer2Cmpld2Timer3 = 118|0x100U, /**< TMR2 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER2Cmpld1Timer3Cmpld2Timer2 = 119|0x100U, /**< TMR2 cmpld1 in timer 3 or cmpld2 in timer 2 */
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


#endif  /* PERI_DMAMUX_H_ */

