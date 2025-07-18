/*
** ###################################################################
**     Processors:          MC56F81643LVLC
**                          MC56F81646LVLF
**                          MC56F81648LVLH
**                          MC56F81663LVLC
**                          MC56F81666LVLF
**                          MC56F81668LVLH
**                          MC56F81743LVLC
**                          MC56F81746LMLF
**                          MC56F81746LVLF
**                          MC56F81748LMLH
**                          MC56F81748LVLH
**                          MC56F81763LVLC
**                          MC56F81766AMLFA
**                          MC56F81766LMLF
**                          MC56F81766LVLF
**                          MC56F81768AMLHA
**                          MC56F81768LMLH
**                          MC56F81768LVLH
**                          MC56F81866AMLFA
**                          MC56F81866LVLF
**                          MC56F81868AMLHA
**                          MC56F81868LVLH
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
**     - rev. 0.1 (2019-12-10)
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

#if (defined(CPU_MC56F81643LVLC))
#include "MC56F81643_COMMON.h"
#elif (defined(CPU_MC56F81646LVLF))
#include "MC56F81646_COMMON.h"
#elif (defined(CPU_MC56F81648LVLH))
#include "MC56F81648_COMMON.h"
#elif (defined(CPU_MC56F81663LVLC))
#include "MC56F81663_COMMON.h"
#elif (defined(CPU_MC56F81666LVLF))
#include "MC56F81666_COMMON.h"
#elif (defined(CPU_MC56F81668LVLH))
#include "MC56F81668_COMMON.h"
#elif (defined(CPU_MC56F81743LVLC))
#include "MC56F81743_COMMON.h"
#elif (defined(CPU_MC56F81746LMLF) || defined(CPU_MC56F81746LVLF))
#include "MC56F81746_COMMON.h"
#elif (defined(CPU_MC56F81748LMLH) || defined(CPU_MC56F81748LVLH))
#include "MC56F81748_COMMON.h"
#elif (defined(CPU_MC56F81763LVLC))
#include "MC56F81763_COMMON.h"
#elif (defined(CPU_MC56F81766AMLFA) || defined(CPU_MC56F81766LMLF) || defined(CPU_MC56F81766LVLF))
#include "MC56F81766_COMMON.h"
#elif (defined(CPU_MC56F81768AMLHA) || defined(CPU_MC56F81768LMLH) || defined(CPU_MC56F81768LVLH))
#include "MC56F81768_COMMON.h"
#elif (defined(CPU_MC56F81866AMLFA) || defined(CPU_MC56F81866LVLF))
#include "MC56F81866_COMMON.h"
#elif (defined(CPU_MC56F81868AMLHA) || defined(CPU_MC56F81868LVLH))
#include "MC56F81868_COMMON.h"
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
    kDmaRequestMuxLPI2C0MSTXRX      = 18|0x100U,   /**< LPI2C0 Master Slave TX RX requests */
    kDmaRequestMuxFlexPWMACaptureSub0 = 22|0x100U, /**< PWMA Capture sub-module 0 */
    kDmaRequestMuxFlexPWMACaptureSub1 = 23|0x100U, /**< PWMA Capture sub-module 1 */
    kDmaRequestMuxFlexPWMACaptureSub2 = 24|0x100U, /**< PWMA Capture sub-module 2 */
    kDmaRequestMuxFlexPWMACaptureSub3 = 25|0x100U, /**< PWMA Capture sub-module 3 */
    kDmaRequestMuxFlexPWMAValueWriteSub0123 = 26|0x100U, /**< PWMA Value Write sub-module 0, 1, 2, 3 */
    kDmaRequestMuxFlexPWMAValueWriteSub0 = 27|0x100U, /**< PWMA Value Write sub-module 0 */
    kDmaRequestMuxFlexPWMAValueWriteSub1 = 28|0x100U, /**< PWMA Value Write sub-module 1 */
    kDmaRequestMuxFlexPWMAValueWriteSub2 = 29|0x100U, /**< PWMA Value Write sub-module 2 */
    kDmaRequestMuxFlexPWMAValueWriteSub3 = 30|0x100U, /**< PWMA Value Write sub-module 3 */
    kDmaRequestMuxTMRA0CaptureCompare1 = 32|0x100U, /**< TMRA0 Capture or Compare 1 */
    kDmaRequestMuxTMRA0Compare2     = 33|0x100U,   /**< TMRA0 Compare 2 */
    kDmaRequestMuxTMRA1CaptureCompare1 = 34|0x100U, /**< TMRA1 Capture or Compare 1 */
    kDmaRequestMuxTMRA1Compare2     = 35|0x100U,   /**< TMRA1 Compare 2 */
    kDmaRequestMuxTMRA2CaptureCompare1 = 36|0x100U, /**< TMRA2 Capture or Compare 1 */
    kDmaRequestMuxTMRA2Compare2     = 37|0x100U,   /**< TMRA2 Compare 2 */
    kDmaRequestMuxTMRA3CaptureCompare1 = 38|0x100U, /**< TMRA3 Capture or Compare 1 */
    kDmaRequestMuxTMRA3Compare2     = 39|0x100U,   /**< TMRA3 Compare 2 */
    kDmaRequestMuxADCAES            = 48|0x100U,   /**< ADCA End of Scan */
    kDmaRequestMuxADCBES            = 49|0x100U,   /**< ADCB End of Scan */
    kDmaRequestMuxCMPA              = 52|0x100U,   /**< CMPA Toggle */
    kDmaRequestMuxCMPB              = 53|0x100U,   /**< CMPB Toggle */
    kDmaRequestMuxCMPC              = 54|0x100U,   /**< CMPC Toggle */
    kDmaRequestMuxXBAR_DSC0         = 56|0x100U,   /**< XBAR DMA Req 0 */
    kDmaRequestMuxXBAR_DSC1         = 57|0x100U,   /**< XBAR DMA Req 1 */
    kDmaRequestMuxXBAR_DSC2         = 58|0x100U,   /**< XBAR DMA Req 2 */
    kDmaRequestMuxXBAR_DSC3         = 59|0x100U,   /**< XBAR DMA Req 3 */
    kDmaRequestMuxAlwaysOn60        = 60|0x100U,   /**< Always on 60 */
    kDmaRequestMuxAlwaysOn61        = 61|0x100U,   /**< Always on 61 */
    kDmaRequestMuxAlwaysOn62        = 62|0x100U,   /**< Always on 62 */
    kDmaRequestMuxAlwaysOn63        = 63|0x100U,   /**< Always on 63 */
    kDmaRequestMuxSCI1RF            = 4|0x100U,    /**< SCI1 Receive Full */
    kDmaRequestMuxSCI1TE            = 5|0x100U,    /**< SCI1 Transmit Empty */
    kDmaRequestMuxCMPD              = 55|0x100U,   /**< CMPD Toggle */
    kDmaRequestMuxSPI0RF            = 12|0x100U,   /**< SPI0 Receive Full */
    kDmaRequestMuxSPI0TE            = 13|0x100U,   /**< SPI0 Transmit Empty */
    kDmaRequestMuxDACFIFO           = 50|0x100U,   /**< DAC FIFO Water Mark */
    kDmaRequestMuxLPI2C1MSTXRX      = 19|0x100U,   /**< LPI2C1 Master Slave TX RX requests */
    kDmaRequestMuxDSASS             = 1|0x100U,    /**< DSASS request */
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

