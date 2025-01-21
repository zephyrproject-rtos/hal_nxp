/*
** ###################################################################
**     Processors:          MIMXRT1041DFP6B
**                          MIMXRT1041DJM6B
**                          MIMXRT1041XFP5B
**                          MIMXRT1041XJM5B
**                          MIMXRT1042DFP6B
**                          MIMXRT1042DJM6B
**                          MIMXRT1042XFP5B
**                          MIMXRT1042XJM5B
**                          MIMXRT1043DFP6B
**                          MIMXRT1043XFP5B
**                          MIMXRT1046DFQ6B
**                          MIMXRT1046XFQ5B
**
**     Version:             rev. 0.1, 2021-07-20
**     Build:               b241021
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMAMUX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 0.1 (2021-07-20)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DMAMUX.h
 * @version 0.1
 * @date 2021-07-20
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(DMAMUX_H_)
#define DMAMUX_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1041DFP6B) || defined(CPU_MIMXRT1041DJM6B) || defined(CPU_MIMXRT1041XFP5B) || defined(CPU_MIMXRT1041XJM5B))
#include "MIMXRT1041_COMMON.h"
#elif (defined(CPU_MIMXRT1042DFP6B) || defined(CPU_MIMXRT1042DJM6B) || defined(CPU_MIMXRT1042XFP5B) || defined(CPU_MIMXRT1042XJM5B))
#include "MIMXRT1042_COMMON.h"
#elif (defined(CPU_MIMXRT1043DFP6B) || defined(CPU_MIMXRT1043XFP5B))
#include "MIMXRT1043_COMMON.h"
#elif (defined(CPU_MIMXRT1046DFQ6B) || defined(CPU_MIMXRT1046XFQ5B))
#include "MIMXRT1046_COMMON.h"
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
    kDmaRequestMuxFlexIO2Request0Request1 = 1|0x100U, /**< FlexIO2 Request0 and Request1 */
    kDmaRequestMuxLPUART1Tx         = 2|0x100U,    /**< LPUART1 Transmit */
    kDmaRequestMuxLPUART1Rx         = 3|0x100U,    /**< LPUART1 Receive */
    kDmaRequestMuxLPUART3Tx         = 4|0x100U,    /**< LPUART3 Transmit */
    kDmaRequestMuxLPUART3Rx         = 5|0x100U,    /**< LPUART3 Receive */
    kDmaRequestMuxLPUART5Tx         = 6|0x100U,    /**< LPUART5 Transmit */
    kDmaRequestMuxLPUART5Rx         = 7|0x100U,    /**< LPUART5 Receive */
    kDmaRequestMuxLPUART7Tx         = 8|0x100U,    /**< LPUART7 Transmit */
    kDmaRequestMuxLPUART7Rx         = 9|0x100U,    /**< LPUART7 Receive */
    kDmaRequestMuxCAN3              = 11|0x100U,   /**< CAN3 */
    kDmaRequestMuxLPSPI1Rx          = 13|0x100U,   /**< LPSPI1 Receive */
    kDmaRequestMuxLPSPI1Tx          = 14|0x100U,   /**< LPSPI1 Transmit */
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
    kDmaRequestMuxFlexPWM3CaptureSub0 = 40|0x100U, /**< FlexPWM3 Capture sub-module0 */
    kDmaRequestMuxFlexPWM3CaptureSub1 = 41|0x100U, /**< FlexPWM3 Capture sub-module1 */
    kDmaRequestMuxFlexPWM3CaptureSub2 = 42|0x100U, /**< FlexPWM3 Capture sub-module2 */
    kDmaRequestMuxFlexPWM3CaptureSub3 = 43|0x100U, /**< FlexPWM3 Capture sub-module3 */
    kDmaRequestMuxFlexPWM3ValueSub0 = 44|0x100U,   /**< FlexPWM3 Value sub-module0 */
    kDmaRequestMuxFlexPWM3ValueSub1 = 45|0x100U,   /**< FlexPWM3 Value sub-module1 */
    kDmaRequestMuxFlexPWM3ValueSub2 = 46|0x100U,   /**< FlexPWM3 Value sub-module2 */
    kDmaRequestMuxFlexPWM3ValueSub3 = 47|0x100U,   /**< FlexPWM3 Value sub-module3 */
    kDmaRequestMuxQTIMER1CaptTimer0 = 48|0x100U,   /**< TMR1 Capture timer 0 */
    kDmaRequestMuxQTIMER1CaptTimer1 = 49|0x100U,   /**< TMR1 Capture timer 1 */
    kDmaRequestMuxQTIMER1CaptTimer2 = 50|0x100U,   /**< TMR1 Capture timer 2 */
    kDmaRequestMuxQTIMER1CaptTimer3 = 51|0x100U,   /**< TMR1 Capture timer 3 */
    kDmaRequestMuxQTIMER1Cmpld1Timer0Cmpld2Timer1 = 52|0x100U, /**< TMR1 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER1Cmpld1Timer1Cmpld2Timer0 = 53|0x100U, /**< TMR1 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER1Cmpld1Timer2Cmpld2Timer3 = 54|0x100U, /**< TMR1 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER1Cmpld1Timer3Cmpld2Timer2 = 55|0x100U, /**< TMR1 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDmaRequestMuxQTIMER3CaptTimer0Cmpld1Timer0Cmpld2Timer1 = 56|0x100U, /**< TMR3 capture timer 0, cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER3CaptTimer1Cmpld1Timer1Cmpld2Timer0 = 57|0x100U, /**< TMR3 capture timer 1, cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER3CaptTimer2Cmpld1Timer2Cmpld2Timer3 = 58|0x100U, /**< TMR3 capture timer 2, cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER3CaptTimer3Cmpld1Timer3Cmpld2Timer2 = 59|0x100U, /**< TMR3 capture timer 3, cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDmaRequestMuxFlexSPI2Rx        = 60|0x100U,   /**< FlexSPI2 Receive */
    kDmaRequestMuxFlexSPI2Tx        = 61|0x100U,   /**< FlexSPI2 Transmit */
    kDmaRequestMuxFlexIO1Request2Request3 = 64|0x100U, /**< FlexIO1 Request2 and Request3 */
    kDmaRequestMuxFlexIO2Request2Request3 = 65|0x100U, /**< FlexIO2 Request2 and Request3 */
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
    kDmaRequestMuxLPSPI3Rx          = 79|0x100U,   /**< LPSPI3 Receive */
    kDmaRequestMuxLPSPI3Tx          = 80|0x100U,   /**< LPSPI3 Transmit */
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
    kDmaRequestMuxFlexPWM4CaptureSub0 = 104|0x100U, /**< FlexPWM4 Capture sub-module0 */
    kDmaRequestMuxFlexPWM4CaptureSub1 = 105|0x100U, /**< FlexPWM4 Capture sub-module1 */
    kDmaRequestMuxFlexPWM4CaptureSub2 = 106|0x100U, /**< FlexPWM4 Capture sub-module2 */
    kDmaRequestMuxFlexPWM4CaptureSub3 = 107|0x100U, /**< FlexPWM4 Capture sub-module3 */
    kDmaRequestMuxFlexPWM4ValueSub0 = 108|0x100U,  /**< FlexPWM4 Value sub-module0 */
    kDmaRequestMuxFlexPWM4ValueSub1 = 109|0x100U,  /**< FlexPWM4 Value sub-module1 */
    kDmaRequestMuxFlexPWM4ValueSub2 = 110|0x100U,  /**< FlexPWM4 Value sub-module2 */
    kDmaRequestMuxFlexPWM4ValueSub3 = 111|0x100U,  /**< FlexPWM4 Value sub-module3 */
    kDmaRequestMuxQTIMER2CaptTimer0 = 112|0x100U,  /**< TMR2 Capture timer 0 */
    kDmaRequestMuxQTIMER2CaptTimer1 = 113|0x100U,  /**< TMR2 Capture timer 1 */
    kDmaRequestMuxQTIMER2CaptTimer2 = 114|0x100U,  /**< TMR2 Capture timer 2 */
    kDmaRequestMuxQTIMER2CaptTimer3 = 115|0x100U,  /**< TMR2 Capture timer 3 */
    kDmaRequestMuxQTIMER2Cmpld1Timer0Cmpld2Timer1 = 116|0x100U, /**< TMR2 cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER2Cmpld1Timer1Cmpld2Timer0 = 117|0x100U, /**< TMR2 cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER2Cmpld1Timer2Cmpld2Timer3 = 118|0x100U, /**< TMR2 cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER2Cmpld1Timer3Cmpld2Timer2 = 119|0x100U, /**< TMR2 cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDmaRequestMuxQTIMER4CaptTimer0Cmpld1Timer0Cmpld2Timer1 = 120|0x100U, /**< TMR4 capture timer 0, cmpld1 in timer 0 or cmpld2 in timer 1 */
    kDmaRequestMuxQTIMER4CaptTimer1Cmpld1Timer1Cmpld2Timer0 = 121|0x100U, /**< TMR4 capture timer 1, cmpld1 in timer 1 or cmpld2 in timer 0 */
    kDmaRequestMuxQTIMER4CaptTimer2Cmpld1Timer2Cmpld2Timer3 = 122|0x100U, /**< TMR4 capture timer 2, cmpld1 in timer 2 or cmpld2 in timer 3 */
    kDmaRequestMuxQTIMER4CaptTimer3Cmpld1Timer3Cmpld2Timer2 = 123|0x100U, /**< TMR4 capture timer 3, cmpld1 in timer 3 or cmpld2 in timer 2 */
    kDmaRequestMuxPxp               = 75|0x100U,   /**< PXP */
    kDmaRequestMuxLCDIF             = 76|0x100U,   /**< LCDIF */
    kDmaRequestMuxLPSPI4Rx          = 15|0x100U,   /**< LPSPI4 Receive */
    kDmaRequestMuxLPSPI4Tx          = 16|0x100U,   /**< LPSPI4 Transmit */
    kDmaRequestMuxEnet2Timer0       = 124|0x100U,  /**< ENET2 Timer0 */
    kDmaRequestMuxEnet2Timer1       = 125|0x100U,  /**< ENET2 Timer1 */
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


#endif  /* DMAMUX_H_ */

