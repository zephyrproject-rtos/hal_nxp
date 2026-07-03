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
**     - rev. 1.0 (2024-11-15)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DMA
 *
 * CMSIS Peripheral Access Layer for DMA
 */

#if !defined(PERI_DMA_H_)
#define PERI_DMA_H_                              /**< Symbol preventing repeated inclusion */

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
#if !defined(DMA3_REQUEST_SOURCE_T_)
#define DMA3_REQUEST_SOURCE_T_
/*!
 * @addtogroup edma_request
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @brief Structure for the DMA3 hardware request
 *
 * Defines the structure for the DMA hardware request collections. The user can configure the
 * hardware request into DMAMUX to trigger the DMA transfer accordingly. The index
 * of the hardware request varies according  to the to SoC.
 */
typedef enum _dma3_request_source
{
    kDma3RequestMuxCAN1             = 1U,          /**< CAN1 */
    kDma3RequestMuxGPIO1Request0    = 3U,          /**< GPIO1 channel 0 */
    kDma3RequestMuxGPIO1Request1    = 4U,          /**< GPIO1 channel 1 */
    kDma3RequestMuxI3C1ToBusRequest = 5U,          /**< I3C1 To-bus Request */
    kDma3RequestMuxI3C1FromBusRequest = 6U,        /**< I3C1 From-bus Request */
    kDma3RequestMuxLPI2C1Tx         = 7U,          /**< LPI2C1 */
    kDma3RequestMuxLPI2C1Rx         = 8U,          /**< LPI2C1 */
    kDma3RequestMuxLPI2C2Tx         = 9U,          /**< LPI2C2 */
    kDma3RequestMuxLPI2C2Rx         = 10U,         /**< LPI2C2 */
    kDma3RequestMuxLPSPI1Tx         = 11U,         /**< LPSPI1 Transmit */
    kDma3RequestMuxLPSPI1Rx         = 12U,         /**< LPSPI1 Receive */
    kDma3RequestMuxLPSPI2Tx         = 13U,         /**< LPSPI2 Transmit */
    kDma3RequestMuxLPSPI2Rx         = 14U,         /**< LPSPI2 Receive */
    kDma3RequestMuxLPTMR1Request    = 15U,         /**< LPTMR1 Request */
    kDma3RequestMuxLPUART1Tx        = 16U,         /**< LPUART1 Transmit */
    kDma3RequestMuxLPUART1Rx        = 17U,         /**< LPUART1 Receive */
    kDma3RequestMuxLPUART2Tx        = 18U,         /**< LPUART2 Transmit */
    kDma3RequestMuxLPUART2Rx        = 19U,         /**< LPUART2 Receive */
    kDma3RequestMuxEdgelockRequest  = 20U,         /**< Edgelock enclave DMA Request */
    kDma3RequestMuxSai1Tx           = 21U,         /**< SAI1 Transmit */
    kDma3RequestMuxSai1Rx           = 22U,         /**< SAI1 Receive */
    kDma3RequestMuxTPM1Request0Request2 = 23U,     /**< TPM1 request 0 and request 2 */
    kDma3RequestMuxTPM1Request1Request3 = 24U,     /**< TPM1 request 1 and request 3 */
    kDma3RequestMuxTPM1OverflowRequest = 25U,      /**< TPM1 Overflow request */
    kDma3RequestMuxTPM2Request0Request2 = 26U,     /**< TPM2 request 0 and request 2 */
    kDma3RequestMuxTPM2Request1Request3 = 27U,     /**< TPM2 request 1 and request 3 */
    kDma3RequestMuxTPM2OverflowRequest = 28U,      /**< TPM2 Overflow request */
    kDma3RequestMuxPDMRequest       = 29U,         /**< PDM */
    kDma3RequestMuxADC1Request      = 30U,         /**< ADC1 */
} dma3_request_source_t;

/* @} */
#endif /* DMA3_REQUEST_SOURCE_T_ */


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
   -- DMA Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Peripheral_Access_Layer DMA Peripheral Access Layer
 * @{
 */

/** DMA - Size of Registers Arrays */
#define DMA_MP_GRPRI_COUNT                        31u

/** DMA - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT;                            /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t MP_HRS;                            /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_MP_GRPRI_COUNT];      /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
} DMA_Type;

/* ----------------------------------------------------------------------------
   -- DMA Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_Register_Masks DMA Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA_MP_CSR_EDBG_MASK                     (0x2U)
#define DMA_MP_CSR_EDBG_SHIFT                    (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_MP_CSR_EDBG(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_EDBG_SHIFT)) & DMA_MP_CSR_EDBG_MASK)

#define DMA_MP_CSR_ERCA_MASK                     (0x4U)
#define DMA_MP_CSR_ERCA_SHIFT                    (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_MP_CSR_ERCA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ERCA_SHIFT)) & DMA_MP_CSR_ERCA_MASK)

#define DMA_MP_CSR_HAE_MASK                      (0x10U)
#define DMA_MP_CSR_HAE_SHIFT                     (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_MP_CSR_HAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HAE_SHIFT)) & DMA_MP_CSR_HAE_MASK)

#define DMA_MP_CSR_HALT_MASK                     (0x20U)
#define DMA_MP_CSR_HALT_SHIFT                    (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_MP_CSR_HALT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_HALT_SHIFT)) & DMA_MP_CSR_HALT_MASK)

#define DMA_MP_CSR_GCLC_MASK                     (0x40U)
#define DMA_MP_CSR_GCLC_SHIFT                    (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_MP_CSR_GCLC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GCLC_SHIFT)) & DMA_MP_CSR_GCLC_MASK)

#define DMA_MP_CSR_GMRC_MASK                     (0x80U)
#define DMA_MP_CSR_GMRC_SHIFT                    (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication disabled for all channels
 *  0b1..Master ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_MP_CSR_GMRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_GMRC_SHIFT)) & DMA_MP_CSR_GMRC_MASK)

#define DMA_MP_CSR_ECX_MASK                      (0x100U)
#define DMA_MP_CSR_ECX_SHIFT                     (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ECX_SHIFT)) & DMA_MP_CSR_ECX_MASK)

#define DMA_MP_CSR_CX_MASK                       (0x200U)
#define DMA_MP_CSR_CX_SHIFT                      (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_MP_CSR_CX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_CX_SHIFT)) & DMA_MP_CSR_CX_MASK)

#define DMA_MP_CSR_ACTIVE_ID_MASK                (0x1F000000U)
#define DMA_MP_CSR_ACTIVE_ID_SHIFT               (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_MP_CSR_ACTIVE_ID(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_MP_CSR_ACTIVE_ID_MASK)

#define DMA_MP_CSR_ACTIVE_MASK                   (0x80000000U)
#define DMA_MP_CSR_ACTIVE_SHIFT                  (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_MP_CSR_ACTIVE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_MP_CSR_ACTIVE_SHIFT)) & DMA_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_MP_ES_DBE_MASK                       (0x1U)
#define DMA_MP_ES_DBE_SHIFT                      (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_MP_ES_DBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DBE_SHIFT)) & DMA_MP_ES_DBE_MASK)

#define DMA_MP_ES_SBE_MASK                       (0x2U)
#define DMA_MP_ES_SBE_SHIFT                      (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_MP_ES_SBE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SBE_SHIFT)) & DMA_MP_ES_SBE_MASK)

#define DMA_MP_ES_SGE_MASK                       (0x4U)
#define DMA_MP_ES_SGE_SHIFT                      (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_MP_ES_SGE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SGE_SHIFT)) & DMA_MP_ES_SGE_MASK)

#define DMA_MP_ES_NCE_MASK                       (0x8U)
#define DMA_MP_ES_NCE_SHIFT                      (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_MP_ES_NCE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_NCE_SHIFT)) & DMA_MP_ES_NCE_MASK)

#define DMA_MP_ES_DOE_MASK                       (0x10U)
#define DMA_MP_ES_DOE_SHIFT                      (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_MP_ES_DOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DOE_SHIFT)) & DMA_MP_ES_DOE_MASK)

#define DMA_MP_ES_DAE_MASK                       (0x20U)
#define DMA_MP_ES_DAE_SHIFT                      (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_MP_ES_DAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_DAE_SHIFT)) & DMA_MP_ES_DAE_MASK)

#define DMA_MP_ES_SOE_MASK                       (0x40U)
#define DMA_MP_ES_SOE_SHIFT                      (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_MP_ES_SOE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SOE_SHIFT)) & DMA_MP_ES_SOE_MASK)

#define DMA_MP_ES_SAE_MASK                       (0x80U)
#define DMA_MP_ES_SAE_SHIFT                      (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_MP_ES_SAE(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_SAE_SHIFT)) & DMA_MP_ES_SAE_MASK)

#define DMA_MP_ES_ECX_MASK                       (0x100U)
#define DMA_MP_ES_ECX_SHIFT                      (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_MP_ES_ECX(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ECX_SHIFT)) & DMA_MP_ES_ECX_MASK)

#define DMA_MP_ES_ERRCHN_MASK                    (0x1F000000U)
#define DMA_MP_ES_ERRCHN_SHIFT                   (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_MP_ES_ERRCHN(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_ERRCHN_SHIFT)) & DMA_MP_ES_ERRCHN_MASK)

#define DMA_MP_ES_VLD_MASK                       (0x80000000U)
#define DMA_MP_ES_VLD_SHIFT                      (31U)
/*! VLD - Valid
 *  0b0..No CHn_ES[ERR] fields are set to 1
 *  0b1..At least one CHn_ES[ERR] field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_MP_ES_VLD(x)                         (((uint32_t)(((uint32_t)(x)) << DMA_MP_ES_VLD_SHIFT)) & DMA_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_MP_INT_INT_MASK                      (0x7FFFFFFFU)
#define DMA_MP_INT_INT_SHIFT                     (0U)
/*! INT - Interrupt Request Status */
#define DMA_MP_INT_INT(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_INT_INT_SHIFT)) & DMA_MP_INT_INT_MASK)
/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_MP_HRS_HRS_MASK                      (0xFFFFFFFFU)
#define DMA_MP_HRS_HRS_SHIFT                     (0U)
/*! HRS - Hardware Request Status */
#define DMA_MP_HRS_HRS(x)                        (((uint32_t)(((uint32_t)(x)) << DMA_MP_HRS_HRS_SHIFT)) & DMA_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_CH_GRPRI_GRPRI_MASK                  (0x1FU)
#define DMA_CH_GRPRI_GRPRI_SHIFT                 (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_CH_GRPRI_GRPRI(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_CH_GRPRI_GRPRI_SHIFT)) & DMA_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_CH_GRPRI */
#define DMA_CH_GRPRI_COUNT                       (31U)


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
