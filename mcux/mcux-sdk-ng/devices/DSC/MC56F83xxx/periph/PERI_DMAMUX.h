/*
** ###################################################################
**     Processors:          MC56F83663VLH
**                          MC56F83683VLH
**                          MC56F83686VLK
**                          MC56F83689VLL
**                          MC56F83763AVLH
**                          MC56F83763VLH
**                          MC56F83766VLK
**                          MC56F83769AVLL
**                          MC56F83769VLL
**                          MC56F83783AVLH
**                          MC56F83783VLH
**                          MC56F83786VLK
**                          MC56F83789AVLL
**                          MC56F83789VLL
**
**     Version:             rev. 1.0, 2024-10-29
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
**     - rev. 0.1 (2019-09-23)
**         Initial version.
**     - rev. 1.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DMAMUX.h
 * @version 1.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DMAMUX
 *
 * CMSIS Peripheral Access Layer for DMAMUX
 */

#if !defined(PERI_DMAMUX_H_)
#define PERI_DMAMUX_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MC56F83663VLH))
#include "MC56F83663_COMMON.h"
#elif (defined(CPU_MC56F83683VLH))
#include "MC56F83683_COMMON.h"
#elif (defined(CPU_MC56F83686VLK))
#include "MC56F83686_COMMON.h"
#elif (defined(CPU_MC56F83689VLL))
#include "MC56F83689_COMMON.h"
#elif (defined(CPU_MC56F83763AVLH) || defined(CPU_MC56F83763VLH))
#include "MC56F83763_COMMON.h"
#elif (defined(CPU_MC56F83766VLK))
#include "MC56F83766_COMMON.h"
#elif (defined(CPU_MC56F83769AVLL) || defined(CPU_MC56F83769VLL))
#include "MC56F83769_COMMON.h"
#elif (defined(CPU_MC56F83783AVLH) || defined(CPU_MC56F83783VLH))
#include "MC56F83783_COMMON.h"
#elif (defined(CPU_MC56F83786VLK))
#include "MC56F83786_COMMON.h"
#elif (defined(CPU_MC56F83789AVLL) || defined(CPU_MC56F83789VLL))
#include "MC56F83789_COMMON.h"
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
    kDmaRequestMuxDisable           = 0|0x100U,    /**< DMAMUX TriggerDisabled */
    kDmaRequestMuxSCI0RF            = 2|0x100U,    /**< SCI0 Receive Full */
    kDmaRequestMuxSCI0TE            = 3|0x100U,    /**< SCI0 Transmit Empty */
    kDmaRequestMuxSCI1RF            = 4|0x100U,    /**< SCI1 Receive Full */
    kDmaRequestMuxSCI1TE            = 5|0x100U,    /**< SCI1 Transmit Empty */
    kDmaRequestMuxSPI0RF            = 12|0x100U,   /**< SPI0 Receive Full */
    kDmaRequestMuxSPI0TE            = 13|0x100U,   /**< SPI0 Transmit Empty */
    kDmaRequestMuxCANFD             = 16|0x100U,   /**< CAN Msg Rx FIFO Full */
    kDmaRequestMuxI2C0              = 18|0x100U,   /**< I2C0 DMA Req */
    kDmaRequestMuxI2C1              = 19|0x100U,   /**< I2C1 DMA Req */
    kDmaRequestMuxFlexPWMACaptureSub0 = 22|0x100U, /**< PWMA Capture sub-module 0 */
    kDmaRequestMuxFlexPWMACaptureSub1 = 23|0x100U, /**< PWMA Capture sub-module 1 */
    kDmaRequestMuxFlexPWMACaptureSub2 = 24|0x100U, /**< PWMA Capture sub-module 2 */
    kDmaRequestMuxFlexPWMACaptureSub3 = 25|0x100U, /**< PWMA Capture sub-module 3 */
    kDmaRequestMuxFlexPWMAValueWriteSub0123 = 26|0x100U, /**< PWMA Value Write sub-module 0, 1, 2, 3 */
    kDmaRequestMuxFlexPWMBCaptureSub0 = 27|0x100U, /**< PWMB Capture sub-module 0 */
    kDmaRequestMuxFlexPWMBCaptureSub1 = 28|0x100U, /**< PWMB Capture sub-module 1 */
    kDmaRequestMuxFlexPWMBCaptureSub2 = 29|0x100U, /**< PWMB Capture sub-module 2 */
    kDmaRequestMuxFlexPWMBCaptureSub3 = 30|0x100U, /**< PWMB Capture sub-module 3 */
    kDmaRequestMuxFlexPWMBValueSub0123 = 31|0x100U, /**< PWMB Value sub-module 0, 1, 2, 3 */
    kDmaRequestMuxTMRA0CaptureCompare1 = 32|0x100U, /**< TMRA0 Capture or Compare 1 */
    kDmaRequestMuxTMRA0Compare2     = 33|0x100U,   /**< TMRA0 Compare 2 */
    kDmaRequestMuxTMRA1CaptureCompare1 = 34|0x100U, /**< TMRA1 Capture or Compare 1 */
    kDmaRequestMuxTMRA1Compare2     = 35|0x100U,   /**< TMRA1 Compare 2 */
    kDmaRequestMuxTMRA2CaptureCompare1 = 36|0x100U, /**< TMRA2 Capture or Compare 1 */
    kDmaRequestMuxTMRA2Compare2     = 37|0x100U,   /**< TMRA2 Compare 2 */
    kDmaRequestMuxTMRA3CaptureCompare1 = 38|0x100U, /**< TMRA3 Capture or Compare 1 */
    kDmaRequestMuxTMRA3Compare2     = 39|0x100U,   /**< TMRA3 Compare 2 */
    kDmaRequestMuxTMRB0CaptureCompare1 = 40|0x100U, /**< TMRB0 Capture or Compare 1 */
    kDmaRequestMuxTMRB0Compare2     = 41|0x100U,   /**< TMRB0 Compare 2 */
    kDmaRequestMuxTMRB1CaptureCompare1 = 42|0x100U, /**< TMRB1 Capture or Compare 1 */
    kDmaRequestMuxTMRB1Compare2     = 43|0x100U,   /**< TMRB1 Compare 2 */
    kDmaRequestMuxTMRB2CaptureCompare1 = 44|0x100U, /**< TMRB2 Capture or Compare 1 */
    kDmaRequestMuxTMRB2Compare2     = 45|0x100U,   /**< TMRB2 Compare 2 */
    kDmaRequestMuxTMRB3CaptureCompare1 = 46|0x100U, /**< TMRB3 Capture or Compare 1 */
    kDmaRequestMuxTMRB3Compare2     = 47|0x100U,   /**< TMRB3 Compare 2 */
    kDmaRequestMuxADCAES            = 48|0x100U,   /**< ADCA End of Scan */
    kDmaRequestMuxADCBES            = 49|0x100U,   /**< ADCB End of Scan */
    kDmaRequestMuxCMPA              = 52|0x100U,   /**< CMPA Toggle */
    kDmaRequestMuxCMPB              = 53|0x100U,   /**< CMPB Toggle */
    kDmaRequestMuxCMPC              = 54|0x100U,   /**< CMPC Toggle */
    kDmaRequestMuxCMPD              = 55|0x100U,   /**< CMPD Toggle */
    kDmaRequestMuxXBAR_DSC0         = 56|0x100U,   /**< XBAR DMA Req 0 */
    kDmaRequestMuxXBAR_DSC1         = 57|0x100U,   /**< XBAR DMA Req 1 */
    kDmaRequestMuxXBAR_DSC2         = 58|0x100U,   /**< XBAR DMA Req 2 */
    kDmaRequestMuxXBAR_DSC3         = 59|0x100U,   /**< XBAR DMA Req 3 */
    kDmaRequestMuxAlwaysOn60        = 60|0x100U,   /**< Always on 60 */
    kDmaRequestMuxAlwaysOn61        = 61|0x100U,   /**< Always on 61 */
    kDmaRequestMuxAlwaysOn62        = 62|0x100U,   /**< Always on 62 */
    kDmaRequestMuxAlwaysOn63        = 63|0x100U,   /**< Always on 63 */
    kDmaRequestMuxSCI2RF            = 6|0x100U,    /**< SCI2 Receive Full */
    kDmaRequestMuxSCI2TE            = 7|0x100U,    /**< SCI2 Transmit Empty */
    kDmaRequestMuxSPI1RF            = 14|0x100U,   /**< SPI1 Receive Full */
    kDmaRequestMuxSPI1TE            = 15|0x100U,   /**< SPI1 Transmit Empty */
    kDmaRequestMuxDACAFIFO          = 50|0x100U,   /**< DACA FIFO Water Mark */
    kDmaRequestMuxDACBFIFO          = 51|0x100U,   /**< DACB FIFO Water Mark */
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

#if defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
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
#define DMAMUX_CHCFG_COUNT                        4u

/** DMAMUX - Register Layout Typedef */
typedef struct {
  __IO uint8_t CHCFG[DMAMUX_CHCFG_COUNT];          /**< Channel Configuration register, array offset: 0x0, array step: 0x1 */
} DMAMUX_Type;

/* ----------------------------------------------------------------------------
   -- DMAMUX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMAMUX_Register_Masks DMAMUX Register Masks
 * @{
 */

/*! @name CHCFG - Channel Configuration register */
/*! @{ */

#define DMAMUX_CHCFG_SOURCE_MASK                 (0x3FU)
#define DMAMUX_CHCFG_SOURCE_SHIFT                (0U)
/*! SOURCE - DMA Channel Source (Slot) */
#define DMAMUX_CHCFG_SOURCE(x)                   (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_SOURCE_SHIFT)) & DMAMUX_CHCFG_SOURCE_MASK)

#define DMAMUX_CHCFG_ENBL_MASK                   (0x80U)
#define DMAMUX_CHCFG_ENBL_SHIFT                  (7U)
/*! ENBL - DMA Channel Enable
 *  0b0..DMA channel is disabled. This mode is primarily used during configuration of the DMAMux. The DMA has
 *       separate channel enables/disables, which should be used to disable or reconfigure a DMA channel.
 *  0b1..DMA channel is enabled
 */
#define DMAMUX_CHCFG_ENBL(x)                     (((uint8_t)(((uint8_t)(x)) << DMAMUX_CHCFG_ENBL_SHIFT)) & DMAMUX_CHCFG_ENBL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DMAMUX_Register_Masks */


/*!
 * @}
 */ /* end of group DMAMUX_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__CWCC__)
  #pragma pop
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_DMAMUX_H_ */

