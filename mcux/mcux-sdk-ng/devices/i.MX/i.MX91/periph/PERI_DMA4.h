/*
** ###################################################################
**     Processors:          MIMX9101CVXXC
**                          MIMX9101DVXXC
**                          MIMX9111CVXXJ
**                          MIMX9111DVXXJ
**                          MIMX9121CVVXC
**                          MIMX9121DVVXC
**                          MIMX9131CVVXJ
**                          MIMX9131DVVXJ
**
**     Version:             rev. 1.0, 2024-11-15
**     Build:               b250814
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
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA4.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DMA4
 *
 * CMSIS Peripheral Access Layer for DMA4
 */

#if !defined(PERI_DMA4_H_)
#define PERI_DMA4_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9101CVXXC) || defined(CPU_MIMX9101DVXXC))
#include "MIMX9101_COMMON.h"
#elif (defined(CPU_MIMX9111CVXXJ) || defined(CPU_MIMX9111DVXXJ))
#include "MIMX9111_COMMON.h"
#elif (defined(CPU_MIMX9121CVVXC) || defined(CPU_MIMX9121DVVXC))
#include "MIMX9121_COMMON.h"
#elif (defined(CPU_MIMX9131CVVXJ) || defined(CPU_MIMX9131DVVXJ))
#include "MIMX9131_COMMON.h"
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
#if !defined(DMA4_REQUEST_SOURCE_T_)
#define DMA4_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA4 hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma4_request_source
{
    kDma4RequestMuxCAN2             = 1U,          /**< CAN2 */
    kDma4RequestMuxGPIO2Request0    = 2U,          /**< GPIO2 channel 0 */
    kDma4RequestMuxGPIO2Request1    = 3U,          /**< GPIO2 channel 1 */
    kDma4RequestMuxGPIO3Request0    = 4U,          /**< GPIO3 channel 0 */
    kDma4RequestMuxGPIO3Request1    = 5U,          /**< GPIO3 channel 1 */
    kDma4RequestMuxI3C2ToBusRequest = 6U,          /**< I3C2 To-bus Request */
    kDma4RequestMuxI3C2FromBusRequest = 7U,        /**< I3C2 From-bus Request */
    kDma4RequestMuxLPI2C3Tx         = 8U,          /**< LPI2C3 */
    kDma4RequestMuxLPI2C3Rx         = 9U,          /**< LPI2C3 */
    kDma4RequestMuxLPI2C4Tx         = 10U,         /**< LPI2C4 */
    kDma4RequestMuxLPI2C4Rx         = 11U,         /**< LPI2C4 */
    kDma4RequestMuxLPSPI3Tx         = 12U,         /**< LPSPI3 Transmit */
    kDma4RequestMuxLPSPI3Rx         = 13U,         /**< LPSPI3 Receive */
    kDma4RequestMuxLPSPI4Tx         = 14U,         /**< LPSPI4 Transmit */
    kDma4RequestMuxLPSPI4Rx         = 15U,         /**< LPSPI4 Receive */
    kDma4RequestMuxLPTMR2Request    = 16U,         /**< LPTMR2 Request */
    kDma4RequestMuxLPUART3Tx        = 17U,         /**< LPUART3 Transmit */
    kDma4RequestMuxLPUART3Rx        = 18U,         /**< LPUART3 Receive */
    kDma4RequestMuxLPUART4Tx        = 19U,         /**< LPUART4 Transmit */
    kDma4RequestMuxLPUART4Rx        = 20U,         /**< LPUART4 Receive */
    kDma4RequestMuxLPUART5Tx        = 21U,         /**< LPUART5 Transmit */
    kDma4RequestMuxLPUART5Rx        = 22U,         /**< LPUART5 Receive */
    kDma4RequestMuxLPUART6Tx        = 23U,         /**< LPUART6 Transmit */
    kDma4RequestMuxLPUART6Rx        = 24U,         /**< LPUART6 Receive */
    kDma4RequestMuxTPM3Request0Request2 = 25U,     /**< TPM3 request 0 and request 2 */
    kDma4RequestMuxTPM3Request1Request3 = 26U,     /**< TPM3 request 1 and request 3 */
    kDma4RequestMuxTPM3OverflowRequest = 27U,      /**< TPM3 Overflow request */
    kDma4RequestMuxTPM4Request0Request2 = 28U,     /**< TPM4 request 0 and request 2 */
    kDma4RequestMuxTPM4Request1Request3 = 29U,     /**< TPM4 request 1 and request 3 */
    kDma4RequestMuxTPM4OverflowRequest = 30U,      /**< TPM4 Overflow request */
    kDma4RequestMuxTPM5Request0Request2 = 31U,     /**< TPM5 request 0 and request 2 */
    kDma4RequestMuxTPM5Request1Request3 = 32U,     /**< TPM5 request 1 and request 3 */
    kDma4RequestMuxTPM5OverflowRequest = 33U,      /**< TPM5 Overflow request */
    kDma4RequestMuxTPM6Request0Request2 = 34U,     /**< TPM6 request 0 and request 2 */
    kDma4RequestMuxTPM6Request1Request3 = 35U,     /**< TPM6 request 1 and request 3 */
    kDma4RequestMuxTPM6OverflowRequest = 36U,      /**< TPM6 Overflow request */
    kDma4RequestMuxFlexIO1Request0  = 37U,         /**< FlexIO1 Request0 */
    kDma4RequestMuxFlexIO1Request1  = 38U,         /**< FlexIO1 Request1 */
    kDma4RequestMuxFlexIO1Request2  = 39U,         /**< FlexIO1 Request2 */
    kDma4RequestMuxFlexIO1Request3  = 40U,         /**< FlexIO1 Request3 */
    kDma4RequestMuxFlexIO1Request4  = 41U,         /**< FlexIO1 Request4 */
    kDma4RequestMuxFlexIO1Request5  = 42U,         /**< FlexIO1 Request5 */
    kDma4RequestMuxFlexIO1Request6  = 43U,         /**< FlexIO1 Request6 */
    kDma4RequestMuxFlexIO1Request7  = 44U,         /**< FlexIO1 Request7 */
    kDma4RequestMuxFlexIO2Request0  = 45U,         /**< FlexIO2 Request0 */
    kDma4RequestMuxFlexIO2Request1  = 46U,         /**< FlexIO2 Request1 */
    kDma4RequestMuxFlexIO2Request2  = 47U,         /**< FlexIO2 Request2 */
    kDma4RequestMuxFlexIO2Request3  = 48U,         /**< FlexIO2 Request3 */
    kDma4RequestMuxFlexIO2Request4  = 49U,         /**< FlexIO2 Request4 */
    kDma4RequestMuxFlexIO2Request5  = 50U,         /**< FlexIO2 Request5 */
    kDma4RequestMuxFlexIO2Request6  = 51U,         /**< FlexIO2 Request6 */
    kDma4RequestMuxFlexIO2Request7  = 52U,         /**< FlexIO2 Request7 */
    kDma4RequestMuxFlexSPI1Tx       = 53U,         /**< FlexSPI1 Transmit */
    kDma4RequestMuxFlexSPI1Rx       = 54U,         /**< FlexSPI1 Receive */
    kDma4RequestMuxSai2Tx           = 58U,         /**< SAI2 Transmit */
    kDma4RequestMuxSai2Rx           = 59U,         /**< SAI2 Receive */
    kDma4RequestMuxSai3Tx           = 60U,         /**< SAI3 Transmit */
    kDma4RequestMuxSai3Rx           = 61U,         /**< SAI3 Receive */
    kDma4RequestMuxGPIO4Request0    = 62U,         /**< GPIO4 channel 0 */
    kDma4RequestMuxGPIO4Request1    = 63U,         /**< GPIO4 channel 1 */
    kDma4RequestMuxSPDIFRequest     = 65U,         /**< SPDIF */
    kDma4RequestMuxSPDIFRequest1    = 66U,         /**< SPDIF */
    kDma4RequestMuxENETRequest      = 67U,         /**< ENET */
    kDma4RequestMuxENETRequest1     = 68U,         /**< ENET */
    kDma4RequestMuxENETRequest2     = 69U,         /**< ENET */
    kDma4RequestMuxENETRequest3     = 70U,         /**< ENET */
    kDma4RequestMuxLPI2C5Tx         = 71U,         /**< LPI2C5 */
    kDma4RequestMuxLPI2C5Rx         = 72U,         /**< LPI2C5 */
    kDma4RequestMuxLPI2C6Tx         = 73U,         /**< LPI2C6 */
    kDma4RequestMuxLPI2C6Rx         = 74U,         /**< LPI2C6 */
    kDma4RequestMuxLPI2C7Tx         = 75U,         /**< LPI2C7 */
    kDma4RequestMuxLPI2C7Rx         = 76U,         /**< LPI2C7 */
    kDma4RequestMuxLPI2C8Tx         = 77U,         /**< LPI2C8 */
    kDma4RequestMuxLPI2C8Rx         = 78U,         /**< LPI2C8 */
    kDma4RequestMuxLPSPI5Tx         = 79U,         /**< LPSPI5 Transmit */
    kDma4RequestMuxLPSPI5Rx         = 80U,         /**< LPSPI5 Receive */
    kDma4RequestMuxLPSPI6Tx         = 81U,         /**< LPSPI6 Transmit */
    kDma4RequestMuxLPSPI6Rx         = 82U,         /**< LPSPI6 Receive */
    kDma4RequestMuxLPSPI7Tx         = 83U,         /**< LPSPI7 Transmit */
    kDma4RequestMuxLPSPI7Rx         = 84U,         /**< LPSPI7 Receive */
    kDma4RequestMuxLPSPI8Tx         = 85U,         /**< LPSPI8 Transmit */
    kDma4RequestMuxLPSPI8Rx         = 86U,         /**< LPSPI8 Receive */
    kDma4RequestMuxLPUART7Tx        = 87U,         /**< LPUART7 Transmit */
    kDma4RequestMuxLPUART7Rx        = 88U,         /**< LPUART7 Receive */
    kDma4RequestMuxLPUART8Tx        = 89U,         /**< LPUART8 Transmit */
    kDma4RequestMuxLPUART8Rx        = 90U,         /**< LPUART8 Receive */
    kDma4RequestMuxENET_QOSRequest  = 91U,         /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest1 = 92U,         /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest2 = 93U,         /**< ENET_QOS */
    kDma4RequestMuxENET_QOSRequest3 = 94U,         /**< ENET_QOS */
} dma4_request_source_t;

/* @} */
#endif /* DMA4_REQUEST_SOURCE_T_ */


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

/** DMA4 - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSR;                               /**< Management Page Control Register, offset: 0x0 */
  __I  uint32_t ES;                                /**< Management Page Error Status Register, offset: 0x4 */
  __I  uint32_t INT_LOW;                           /**< Management Page Interrupt Request Status Register - Low, offset: 0x8 */
  __I  uint32_t INT_HIGH;                          /**< Management Page Interrupt Request Status Register- High, offset: 0xC */
  __I  uint32_t HRS_LOW;                           /**< Management Page Hardware Request Status Register - Low, offset: 0x10 */
  __I  uint32_t HRS_HIGH;                          /**< Management Page Hardware Request Status Register - High, offset: 0x14 */
       uint8_t RESERVED_0[232];
  __IO uint32_t CH_GRPRI[DMA4_MP_GRPRI_COUNT];     /**< Channel Arbitration Group Register, array offset: 0x100, array step: 0x4 */
} DMA4_Type;

/* ----------------------------------------------------------------------------
   -- DMA4 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA4_Register_Masks DMA4 Register Masks
 * @{
 */

/*! @name CSR - Management Page Control Register */
/*! @{ */

#define DMA4_CSR_EDBG_MASK                       (0x2U)
#define DMA4_CSR_EDBG_SHIFT                      (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode is disabled.
 *  0b1..Debug mode is enabled.
 */
#define DMA4_CSR_EDBG(x)                         (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_EDBG_SHIFT)) & DMA4_CSR_EDBG_MASK)

#define DMA4_CSR_ERCA_MASK                       (0x4U)
#define DMA4_CSR_ERCA_SHIFT                      (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round robin channel arbitration is disabled.
 *  0b1..Round robin channel arbitration is enabled.
 */
#define DMA4_CSR_ERCA(x)                         (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_ERCA_SHIFT)) & DMA4_CSR_ERCA_MASK)

#define DMA4_CSR_HAE_MASK                        (0x10U)
#define DMA4_CSR_HAE_SHIFT                       (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT bit to set. Subsequently, all service requests are ignored until the HALT bit is cleared.
 */
#define DMA4_CSR_HAE(x)                          (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_HAE_SHIFT)) & DMA4_CSR_HAE_MASK)

#define DMA4_CSR_HALT_MASK                       (0x20U)
#define DMA4_CSR_HALT_SHIFT                      (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels. Executing channels are allowed to complete. Channel execution resumes when this bit is cleared.
 */
#define DMA4_CSR_HALT(x)                         (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_HALT_SHIFT)) & DMA4_CSR_HALT_MASK)

#define DMA4_CSR_GCLC_MASK                       (0x40U)
#define DMA4_CSR_GCLC_SHIFT                      (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking is disabled for all channels.
 *  0b1..Channel linking is available and controlled by each channel's link settings.
 */
#define DMA4_CSR_GCLC(x)                         (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_GCLC_SHIFT)) & DMA4_CSR_GCLC_MASK)

#define DMA4_CSR_GMRC_MASK                       (0x80U)
#define DMA4_CSR_GMRC_SHIFT                      (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication is disabled for all channels.
 *  0b1..Master ID replication is available and is controlled by each channel's CHn_SBR[EMI] setting.
 */
#define DMA4_CSR_GMRC(x)                         (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_GMRC_SHIFT)) & DMA4_CSR_GMRC_MASK)

#define DMA4_CSR_ECX_MASK                        (0x100U)
#define DMA4_CSR_ECX_SHIFT                       (8U)
/*! ECX - Cancel Transfer with Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer in the same fashion as the CX bit. Stop the executing channel and
 *       force the minor loop to finish. The cancel takes effect after the last write of the current read/write
 *       sequence. The ECX bit clears itself after the cancel is honored. In addition to cancelling the transfer, ECX
 *       treats the cancel as an error condition, thus updating the Error Status register (DMAx_ES) and generating an
 *       optional error interrupt.
 */
#define DMA4_CSR_ECX(x)                          (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_ECX_SHIFT)) & DMA4_CSR_ECX_MASK)

#define DMA4_CSR_CX_MASK                         (0x200U)
#define DMA4_CSR_CX_SHIFT                        (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer. Stop the executing channel and force the minor loop to finish. The
 *       cancel takes effect after the last write of the current read/write sequence. The CX bit clears itself after
 *       the cancel has been honored. This cancel retires the channel normally as if the minor loop was completed.
 */
#define DMA4_CSR_CX(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_CX_SHIFT)) & DMA4_CSR_CX_MASK)

#define DMA4_CSR_VER_MASK                        (0xFF0000U)
#define DMA4_CSR_VER_SHIFT                       (16U)
/*! VER - eDMA version */
#define DMA4_CSR_VER(x)                          (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_VER_SHIFT)) & DMA4_CSR_VER_MASK)

#define DMA4_CSR_ACTIVE_ID_MASK                  (0x3F000000U)
#define DMA4_CSR_ACTIVE_ID_SHIFT                 (24U)
/*! ACTIVE_ID - Active channel ID */
#define DMA4_CSR_ACTIVE_ID(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_ACTIVE_ID_SHIFT)) & DMA4_CSR_ACTIVE_ID_MASK)

#define DMA4_CSR_ACTIVE_MASK                     (0x80000000U)
#define DMA4_CSR_ACTIVE_SHIFT                    (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle.
 *  0b1..eDMA is executing a channel.
 */
#define DMA4_CSR_ACTIVE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA4_CSR_ACTIVE_SHIFT)) & DMA4_CSR_ACTIVE_MASK)
/*! @} */

/*! @name ES - Management Page Error Status Register */
/*! @{ */

#define DMA4_ES_DBE_MASK                         (0x1U)
#define DMA4_ES_DBE_SHIFT                        (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error was a bus error on a destination write
 */
#define DMA4_ES_DBE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_DBE_SHIFT)) & DMA4_ES_DBE_MASK)

#define DMA4_ES_SBE_MASK                         (0x2U)
#define DMA4_ES_SBE_SHIFT                        (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..The last recorded error was a bus error on a source read
 */
#define DMA4_ES_SBE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_SBE_SHIFT)) & DMA4_ES_SBE_MASK)

#define DMA4_ES_SGE_MASK                         (0x4U)
#define DMA4_ES_SGE_SHIFT                        (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DLASTSGA field. This field is
 *       checked at the beginning of a scatter/gather operation after major loop completion if TCDn_CSR[ESG] is
 *       enabled. TCDn_DLASTSGA is not on a 32 byte boundary.
 */
#define DMA4_ES_SGE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_SGE_SHIFT)) & DMA4_ES_SGE_MASK)

#define DMA4_ES_NCE_MASK                         (0x8U)
#define DMA4_ES_NCE_SHIFT                        (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA4_ES_NCE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_NCE_SHIFT)) & DMA4_ES_NCE_MASK)

#define DMA4_ES_DOE_MASK                         (0x10U)
#define DMA4_ES_DOE_SHIFT                        (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_ES_DOE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_DOE_SHIFT)) & DMA4_ES_DOE_MASK)

#define DMA4_ES_DAE_MASK                         (0x20U)
#define DMA4_ES_DAE_SHIFT                        (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_ES_DAE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_DAE_SHIFT)) & DMA4_ES_DAE_MASK)

#define DMA4_ES_SOE_MASK                         (0x40U)
#define DMA4_ES_SOE_SHIFT                        (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_ES_SOE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_SOE_SHIFT)) & DMA4_ES_SOE_MASK)

#define DMA4_ES_SAE_MASK                         (0x80U)
#define DMA4_ES_SAE_SHIFT                        (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error.
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_ES_SAE(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_SAE_SHIFT)) & DMA4_ES_SAE_MASK)

#define DMA4_ES_ECX_MASK                         (0x100U)
#define DMA4_ES_ECX_SHIFT                        (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..The last recorded entry was a canceled transfer by the error cancel transfer input.
 */
#define DMA4_ES_ECX(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_ECX_SHIFT)) & DMA4_ES_ECX_MASK)

#define DMA4_ES_ERRCHN_MASK                      (0x3F000000U)
#define DMA4_ES_ERRCHN_SHIFT                     (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA4_ES_ERRCHN(x)                        (((uint32_t)(((uint32_t)(x)) << DMA4_ES_ERRCHN_SHIFT)) & DMA4_ES_ERRCHN_MASK)

#define DMA4_ES_VLD_MASK                         (0x80000000U)
#define DMA4_ES_VLD_SHIFT                        (31U)
/*! VLD - Valid
 *  0b0..No ERR bits are set.
 *  0b1..At least one ERR bit is set indicating a valid error exists that has not been cleared.
 */
#define DMA4_ES_VLD(x)                           (((uint32_t)(((uint32_t)(x)) << DMA4_ES_VLD_SHIFT)) & DMA4_ES_VLD_MASK)
/*! @} */

/*! @name INT_LOW - Management Page Interrupt Request Status Register - Low */
/*! @{ */

#define DMA4_INT_LOW_INT_MASK                    (0xFFFFFFFFU)
#define DMA4_INT_LOW_INT_SHIFT                   (0U)
/*! INT - Interrupt Request Status for channels 31 - 0 */
#define DMA4_INT_LOW_INT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_INT_LOW_INT_SHIFT)) & DMA4_INT_LOW_INT_MASK)
/*! @} */

/*! @name INT_HIGH - Management Page Interrupt Request Status Register- High */
/*! @{ */

#define DMA4_INT_HIGH_INT_MASK                   (0xFFFFFFFFU)
#define DMA4_INT_HIGH_INT_SHIFT                  (0U)
/*! INT - Interrupt Request Status for channels 63-32 */
#define DMA4_INT_HIGH_INT(x)                     (((uint32_t)(((uint32_t)(x)) << DMA4_INT_HIGH_INT_SHIFT)) & DMA4_INT_HIGH_INT_MASK)
/*! @} */

/*! @name HRS_LOW - Management Page Hardware Request Status Register - Low */
/*! @{ */

#define DMA4_HRS_LOW_HRS_MASK                    (0xFFFFFFFFU)
#define DMA4_HRS_LOW_HRS_SHIFT                   (0U)
/*! HRS - Hardware Request Status for channels 31 - 0
 *  0b00000000000000000000000000000000..A hardware service request for the channel is not present
 *  0b00000000000000000000000000000001..A hardware service request for channel 0 is present
 */
#define DMA4_HRS_LOW_HRS(x)                      (((uint32_t)(((uint32_t)(x)) << DMA4_HRS_LOW_HRS_SHIFT)) & DMA4_HRS_LOW_HRS_MASK)
/*! @} */

/*! @name HRS_HIGH - Management Page Hardware Request Status Register - High */
/*! @{ */

#define DMA4_HRS_HIGH_HRS_MASK                   (0xFFFFFFFFU)
#define DMA4_HRS_HIGH_HRS_SHIFT                  (0U)
/*! HRS - Hardware Request Status for channels 63-32
 *  0b00000000000000000000000000000000..A hardware service request for the channel is not present
 *  0b00000000000000000000000000000001..A hardware service request for channel 0 is present
 */
#define DMA4_HRS_HIGH_HRS(x)                     (((uint32_t)(((uint32_t)(x)) << DMA4_HRS_HIGH_HRS_SHIFT)) & DMA4_HRS_HIGH_HRS_MASK)
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
