/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 5.0, 2023-04-27
**     Build:               b240823
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA_AD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**
** ###################################################################
*/

/*!
 * @file DMA_AD.h
 * @version 5.0
 * @date 2023-04-27
 * @brief CMSIS Peripheral Access Layer for DMA_AD
 *
 * CMSIS Peripheral Access Layer for DMA_AD
 */

#if !defined(DMA_AD_H_)
#define DMA_AD_H_                                /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
#else
  #error "No valid CPU defined!"
#endif

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
#elif defined(__XTENSA__)
  /* anonymous unions are enabled by default */
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DMA_AD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_AD_Peripheral_Access_Layer DMA_AD Peripheral Access Layer
 * @{
 */

/** DMA_AD - Size of Registers Arrays */
#define DMA_AD_MP_GRPRI_COUNT                     32u
#define DMA_AD_CH_COUNT                           32u

/** DMA_AD - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT;                            /**< Management Page Interrupt Request Status, offset: 0x8 */
  __I  uint32_t MP_HRS;                            /**< Management Page Hardware Request Status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t CH_GRPRI[DMA_AD_MP_GRPRI_COUNT];   /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_1[65152];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x10004, array step: 0x10000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x10008, array step: 0x10000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x10010, array step: 0x10000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x10014, array step: 0x10000 */
         uint8_t RESERVED_0[8];
    __IO uint32_t TCD_SADDR;                         /**< TCD Source Address, array offset: 0x10020, array step: 0x10000 */
    __IO uint16_t TCD_SOFF;                          /**< TCD Signed Source Address Offset, array offset: 0x10024, array step: 0x10000 */
    __IO uint16_t TCD_ATTR;                          /**< TCD Transfer Attributes, array offset: 0x10026, array step: 0x10000 */
    union {                                          /* offset: 0x10028, array step: 0x10000 */
      __IO uint32_t TCD_NBYTES_MLOFFNO;                /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x10028, array step: 0x10000 */
      __IO uint32_t TCD_NBYTES_MLOFFYES;               /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x10028, array step: 0x10000 */
    };
    __IO uint32_t TCD_SLAST_SDA;                     /**< TCD Last Source Address Adjustment / Store DADDR Address, array offset: 0x1002C, array step: 0x10000 */
    __IO uint32_t TCD_DADDR;                         /**< TCD Destination Address, array offset: 0x10030, array step: 0x10000 */
    __IO uint16_t TCD_DOFF;                          /**< TCD Signed Destination Address Offset, array offset: 0x10034, array step: 0x10000 */
    union {                                          /* offset: 0x10036, array step: 0x10000 */
      __IO uint16_t TCD_CITER_ELINKNO;                 /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x10036, array step: 0x10000 */
      __IO uint16_t TCD_CITER_ELINKYES;                /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x10036, array step: 0x10000 */
    };
    __IO uint32_t TCD_DLAST_SGA;                     /**< TCD Last Destination Address Adjustment / Scatter Gather Address, array offset: 0x10038, array step: 0x10000 */
    __IO uint16_t TCD_CSR;                           /**< TCD Control and Status, array offset: 0x1003C, array step: 0x10000 */
    union {                                          /* offset: 0x1003E, array step: 0x10000 */
      __IO uint16_t TCD_BITER_ELINKNO;                 /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1003E, array step: 0x10000 */
      __IO uint16_t TCD_BITER_ELINKYES;                /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1003E, array step: 0x10000 */
    };
         uint8_t RESERVED_1[65472];
  } CH[DMA_AD_CH_COUNT];
} DMA_AD_Type;

/* ----------------------------------------------------------------------------
   -- DMA_AD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA_AD_Register_Masks DMA_AD Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA_AD_MP_CSR_EDBG_MASK                  (0x2U)
#define DMA_AD_MP_CSR_EDBG_SHIFT                 (1U)
/*! EDBG - Enable Debug
 *  0b0..Debug mode disabled
 *  0b1..Debug mode is enabled.
 */
#define DMA_AD_MP_CSR_EDBG(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_EDBG_SHIFT)) & DMA_AD_MP_CSR_EDBG_MASK)

#define DMA_AD_MP_CSR_ERCA_MASK                  (0x4U)
#define DMA_AD_MP_CSR_ERCA_SHIFT                 (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Round-robin channel arbitration disabled
 *  0b1..Round-robin channel arbitration enabled
 */
#define DMA_AD_MP_CSR_ERCA(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_ERCA_SHIFT)) & DMA_AD_MP_CSR_ERCA_MASK)

#define DMA_AD_MP_CSR_HAE_MASK                   (0x10U)
#define DMA_AD_MP_CSR_HAE_SHIFT                  (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Any error causes the HALT field to be set to 1
 */
#define DMA_AD_MP_CSR_HAE(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_HAE_SHIFT)) & DMA_AD_MP_CSR_HAE_MASK)

#define DMA_AD_MP_CSR_HALT_MASK                  (0x20U)
#define DMA_AD_MP_CSR_HALT_SHIFT                 (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Stall the start of any new channels
 */
#define DMA_AD_MP_CSR_HALT(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_HALT_SHIFT)) & DMA_AD_MP_CSR_HALT_MASK)

#define DMA_AD_MP_CSR_GCLC_MASK                  (0x40U)
#define DMA_AD_MP_CSR_GCLC_SHIFT                 (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Channel linking disabled for all channels
 *  0b1..Channel linking available and controlled by each channel's link settings
 */
#define DMA_AD_MP_CSR_GCLC(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_GCLC_SHIFT)) & DMA_AD_MP_CSR_GCLC_MASK)

#define DMA_AD_MP_CSR_GMRC_MASK                  (0x80U)
#define DMA_AD_MP_CSR_GMRC_SHIFT                 (7U)
/*! GMRC - Global Master ID Replication Control
 *  0b0..Master ID replication disabled for all channels
 *  0b1..Master ID replication available and controlled by each channel's CHn_SBR[EMI] setting
 */
#define DMA_AD_MP_CSR_GMRC(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_GMRC_SHIFT)) & DMA_AD_MP_CSR_GMRC_MASK)

#define DMA_AD_MP_CSR_ECX_MASK                   (0x100U)
#define DMA_AD_MP_CSR_ECX_SHIFT                  (8U)
/*! ECX - Cancel Transfer With Error
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_AD_MP_CSR_ECX(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_ECX_SHIFT)) & DMA_AD_MP_CSR_ECX_MASK)

#define DMA_AD_MP_CSR_CX_MASK                    (0x200U)
#define DMA_AD_MP_CSR_CX_SHIFT                   (9U)
/*! CX - Cancel Transfer
 *  0b0..Normal operation
 *  0b1..Cancel the remaining data transfer
 */
#define DMA_AD_MP_CSR_CX(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_CX_SHIFT)) & DMA_AD_MP_CSR_CX_MASK)

#define DMA_AD_MP_CSR_ACTIVE_ID_MASK             (0x1F000000U)
#define DMA_AD_MP_CSR_ACTIVE_ID_SHIFT            (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA_AD_MP_CSR_ACTIVE_ID(x)               (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_ACTIVE_ID_SHIFT)) & DMA_AD_MP_CSR_ACTIVE_ID_MASK)

#define DMA_AD_MP_CSR_ACTIVE_MASK                (0x80000000U)
#define DMA_AD_MP_CSR_ACTIVE_SHIFT               (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..eDMA is idle
 *  0b1..eDMA is executing a channel
 */
#define DMA_AD_MP_CSR_ACTIVE(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_CSR_ACTIVE_SHIFT)) & DMA_AD_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA_AD_MP_ES_DBE_MASK                    (0x1U)
#define DMA_AD_MP_ES_DBE_SHIFT                   (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was a bus error on a destination write
 */
#define DMA_AD_MP_ES_DBE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_DBE_SHIFT)) & DMA_AD_MP_ES_DBE_MASK)

#define DMA_AD_MP_ES_SBE_MASK                    (0x2U)
#define DMA_AD_MP_ES_SBE_SHIFT                   (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was a bus error on a source read
 */
#define DMA_AD_MP_ES_SBE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_SBE_SHIFT)) & DMA_AD_MP_ES_SBE_MASK)

#define DMA_AD_MP_ES_SGE_MASK                    (0x4U)
#define DMA_AD_MP_ES_SGE_SHIFT                   (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_AD_MP_ES_SGE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_SGE_SHIFT)) & DMA_AD_MP_ES_SGE_MASK)

#define DMA_AD_MP_ES_NCE_MASK                    (0x8U)
#define DMA_AD_MP_ES_NCE_SHIFT                   (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was NBYTES equal to zero or a CITER not equal to BITER error
 */
#define DMA_AD_MP_ES_NCE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_NCE_SHIFT)) & DMA_AD_MP_ES_NCE_MASK)

#define DMA_AD_MP_ES_DOE_MASK                    (0x10U)
#define DMA_AD_MP_ES_DOE_SHIFT                   (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_AD_MP_ES_DOE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_DOE_SHIFT)) & DMA_AD_MP_ES_DOE_MASK)

#define DMA_AD_MP_ES_DAE_MASK                    (0x20U)
#define DMA_AD_MP_ES_DAE_SHIFT                   (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_AD_MP_ES_DAE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_DAE_SHIFT)) & DMA_AD_MP_ES_DAE_MASK)

#define DMA_AD_MP_ES_SOE_MASK                    (0x40U)
#define DMA_AD_MP_ES_SOE_SHIFT                   (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_AD_MP_ES_SOE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_SOE_SHIFT)) & DMA_AD_MP_ES_SOE_MASK)

#define DMA_AD_MP_ES_SAE_MASK                    (0x80U)
#define DMA_AD_MP_ES_SAE_SHIFT                   (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_AD_MP_ES_SAE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_SAE_SHIFT)) & DMA_AD_MP_ES_SAE_MASK)

#define DMA_AD_MP_ES_ECX_MASK                    (0x100U)
#define DMA_AD_MP_ES_ECX_SHIFT                   (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Last recorded entry was a canceled transfer by the error cancel transfer input
 */
#define DMA_AD_MP_ES_ECX(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_ECX_SHIFT)) & DMA_AD_MP_ES_ECX_MASK)

#define DMA_AD_MP_ES_ERRCHN_MASK                 (0x1F000000U)
#define DMA_AD_MP_ES_ERRCHN_SHIFT                (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA_AD_MP_ES_ERRCHN(x)                   (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_ERRCHN_SHIFT)) & DMA_AD_MP_ES_ERRCHN_MASK)

#define DMA_AD_MP_ES_VLD_MASK                    (0x80000000U)
#define DMA_AD_MP_ES_VLD_SHIFT                   (31U)
/*! VLD - Valid
 *  0b0..No CHn_ES[ERR] fields are set to 1
 *  0b1..At least one CHn_ES[ERR] field is set to 1, indicating a valid error exists that software has not cleared
 */
#define DMA_AD_MP_ES_VLD(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_ES_VLD_SHIFT)) & DMA_AD_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT - Management Page Interrupt Request Status */
/*! @{ */

#define DMA_AD_MP_INT_INT_MASK                   (0xFFFFFFFFU)
#define DMA_AD_MP_INT_INT_SHIFT                  (0U)
/*! INT - Interrupt Request Status */
#define DMA_AD_MP_INT_INT(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_INT_INT_SHIFT)) & DMA_AD_MP_INT_INT_MASK)
/*! @} */

/*! @name MP_HRS - Management Page Hardware Request Status */
/*! @{ */

#define DMA_AD_MP_HRS_HRS_MASK                   (0xFFFFFFFFU)
#define DMA_AD_MP_HRS_HRS_SHIFT                  (0U)
/*! HRS - Hardware Request Status */
#define DMA_AD_MP_HRS_HRS(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_MP_HRS_HRS_SHIFT)) & DMA_AD_MP_HRS_HRS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA_AD_CH_GRPRI_GRPRI_MASK               (0x1FU)
#define DMA_AD_CH_GRPRI_GRPRI_SHIFT              (0U)
/*! GRPRI - Arbitration Group For Channel n */
#define DMA_AD_CH_GRPRI_GRPRI(x)                 (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_GRPRI_GRPRI_SHIFT)) & DMA_AD_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA_AD_CH_GRPRI */
#define DMA_AD_CH_GRPRI_COUNT                    (32U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA_AD_CH_CSR_ERQ_MASK                   (0x1U)
#define DMA_AD_CH_CSR_ERQ_SHIFT                  (0U)
/*! ERQ - Enable DMA Request
 *  0b0..DMA hardware request signal for corresponding channel disabled
 *  0b1..DMA hardware request signal for corresponding channel enabled
 */
#define DMA_AD_CH_CSR_ERQ(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_ERQ_SHIFT)) & DMA_AD_CH_CSR_ERQ_MASK)

#define DMA_AD_CH_CSR_EARQ_MASK                  (0x2U)
#define DMA_AD_CH_CSR_EARQ_SHIFT                 (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel
 *  0b1..Enable asynchronous DMA request for the channel
 */
#define DMA_AD_CH_CSR_EARQ(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_EARQ_SHIFT)) & DMA_AD_CH_CSR_EARQ_MASK)

#define DMA_AD_CH_CSR_EEI_MASK                   (0x4U)
#define DMA_AD_CH_CSR_EEI_SHIFT                  (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Error signal for corresponding channel does not generate error interrupt
 *  0b1..Assertion of error signal for corresponding channel generates error interrupt request
 */
#define DMA_AD_CH_CSR_EEI(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_EEI_SHIFT)) & DMA_AD_CH_CSR_EEI_MASK)

#define DMA_AD_CH_CSR_EBW_MASK                   (0x8U)
#define DMA_AD_CH_CSR_EBW_SHIFT                  (3U)
/*! EBW - Enable Buffered Writes
 *  0b0..Buffered writes on system bus disabled
 *  0b1..Buffered writes on system bus enabled
 */
#define DMA_AD_CH_CSR_EBW(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_EBW_SHIFT)) & DMA_AD_CH_CSR_EBW_MASK)

#define DMA_AD_CH_CSR_DONE_MASK                  (0x40000000U)
#define DMA_AD_CH_CSR_DONE_SHIFT                 (30U)
/*! DONE - Channel Done */
#define DMA_AD_CH_CSR_DONE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_DONE_SHIFT)) & DMA_AD_CH_CSR_DONE_MASK)

#define DMA_AD_CH_CSR_ACTIVE_MASK                (0x80000000U)
#define DMA_AD_CH_CSR_ACTIVE_SHIFT               (31U)
/*! ACTIVE - Channel Active */
#define DMA_AD_CH_CSR_ACTIVE(x)                  (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_CSR_ACTIVE_SHIFT)) & DMA_AD_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA_AD_CH_CSR */
#define DMA_AD_CH_CSR_COUNT                      (32U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA_AD_CH_ES_DBE_MASK                    (0x1U)
#define DMA_AD_CH_ES_DBE_SHIFT                   (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..Last recorded error was bus error on destination write
 */
#define DMA_AD_CH_ES_DBE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_DBE_SHIFT)) & DMA_AD_CH_ES_DBE_MASK)

#define DMA_AD_CH_ES_SBE_MASK                    (0x2U)
#define DMA_AD_CH_ES_SBE_SHIFT                   (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..Last recorded error was bus error on source read
 */
#define DMA_AD_CH_ES_SBE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_SBE_SHIFT)) & DMA_AD_CH_ES_SBE_MASK)

#define DMA_AD_CH_ES_SGE_MASK                    (0x4U)
#define DMA_AD_CH_ES_SGE_SHIFT                   (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DLAST_SGA field
 */
#define DMA_AD_CH_ES_SGE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_SGE_SHIFT)) & DMA_AD_CH_ES_SGE_MASK)

#define DMA_AD_CH_ES_NCE_MASK                    (0x8U)
#define DMA_AD_CH_ES_NCE_SHIFT                   (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields
 */
#define DMA_AD_CH_ES_NCE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_NCE_SHIFT)) & DMA_AD_CH_ES_NCE_MASK)

#define DMA_AD_CH_ES_DOE_MASK                    (0x10U)
#define DMA_AD_CH_ES_DOE_SHIFT                   (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DOFF field
 */
#define DMA_AD_CH_ES_DOE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_DOE_SHIFT)) & DMA_AD_CH_ES_DOE_MASK)

#define DMA_AD_CH_ES_DAE_MASK                    (0x20U)
#define DMA_AD_CH_ES_DAE_SHIFT                   (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_DADDR field
 */
#define DMA_AD_CH_ES_DAE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_DAE_SHIFT)) & DMA_AD_CH_ES_DAE_MASK)

#define DMA_AD_CH_ES_SOE_MASK                    (0x40U)
#define DMA_AD_CH_ES_SOE_SHIFT                   (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SOFF field
 */
#define DMA_AD_CH_ES_SOE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_SOE_SHIFT)) & DMA_AD_CH_ES_SOE_MASK)

#define DMA_AD_CH_ES_SAE_MASK                    (0x80U)
#define DMA_AD_CH_ES_SAE_SHIFT                   (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error
 *  0b1..Last recorded error was a configuration error detected in the TCDn_SADDR field
 */
#define DMA_AD_CH_ES_SAE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_SAE_SHIFT)) & DMA_AD_CH_ES_SAE_MASK)

#define DMA_AD_CH_ES_ERR_MASK                    (0x80000000U)
#define DMA_AD_CH_ES_ERR_SHIFT                   (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA_AD_CH_ES_ERR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_ES_ERR_SHIFT)) & DMA_AD_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA_AD_CH_ES */
#define DMA_AD_CH_ES_COUNT                       (32U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA_AD_CH_INT_INT_MASK                   (0x1U)
#define DMA_AD_CH_INT_INT_SHIFT                  (0U)
/*! INT - Interrupt Request
 *  0b0..Interrupt request for corresponding channel cleared
 *  0b1..Interrupt request for corresponding channel active
 */
#define DMA_AD_CH_INT_INT(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_INT_INT_SHIFT)) & DMA_AD_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA_AD_CH_INT */
#define DMA_AD_CH_INT_COUNT                      (32U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA_AD_CH_SBR_MID_MASK                   (0x3FU)
#define DMA_AD_CH_SBR_MID_SHIFT                  (0U)
/*! MID - Master ID */
#define DMA_AD_CH_SBR_MID(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_SBR_MID_SHIFT)) & DMA_AD_CH_SBR_MID_MASK)

#define DMA_AD_CH_SBR_SEC_MASK                   (0x4000U)
#define DMA_AD_CH_SBR_SEC_SHIFT                  (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA_AD_CH_SBR_SEC(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_SBR_SEC_SHIFT)) & DMA_AD_CH_SBR_SEC_MASK)

#define DMA_AD_CH_SBR_PAL_MASK                   (0x8000U)
#define DMA_AD_CH_SBR_PAL_SHIFT                  (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA_AD_CH_SBR_PAL(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_SBR_PAL_SHIFT)) & DMA_AD_CH_SBR_PAL_MASK)

#define DMA_AD_CH_SBR_EMI_MASK                   (0x10000U)
#define DMA_AD_CH_SBR_EMI_SHIFT                  (16U)
/*! EMI - Enable Master ID Replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA_AD_CH_SBR_EMI(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_SBR_EMI_SHIFT)) & DMA_AD_CH_SBR_EMI_MASK)

#define DMA_AD_CH_SBR_ATTR_MASK                  (0x1E0000U)
#define DMA_AD_CH_SBR_ATTR_SHIFT                 (17U)
/*! ATTR - Attribute Output */
#define DMA_AD_CH_SBR_ATTR(x)                    (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_SBR_ATTR_SHIFT)) & DMA_AD_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA_AD_CH_SBR */
#define DMA_AD_CH_SBR_COUNT                      (32U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA_AD_CH_PRI_APL_MASK                   (0x7U)
#define DMA_AD_CH_PRI_APL_SHIFT                  (0U)
/*! APL - Arbitration Priority Level */
#define DMA_AD_CH_PRI_APL(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_PRI_APL_SHIFT)) & DMA_AD_CH_PRI_APL_MASK)

#define DMA_AD_CH_PRI_DPA_MASK                   (0x40000000U)
#define DMA_AD_CH_PRI_DPA_SHIFT                  (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Channel can suspend a lower-priority channel
 *  0b1..Channel cannot suspend any other channel, regardless of channel priority
 */
#define DMA_AD_CH_PRI_DPA(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_PRI_DPA_SHIFT)) & DMA_AD_CH_PRI_DPA_MASK)

#define DMA_AD_CH_PRI_ECP_MASK                   (0x80000000U)
#define DMA_AD_CH_PRI_ECP_SHIFT                  (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Channel cannot be suspended by a higher-priority channel's service request
 *  0b1..Channel can be temporarily suspended by a higher-priority channel's service request
 */
#define DMA_AD_CH_PRI_ECP(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_PRI_ECP_SHIFT)) & DMA_AD_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA_AD_CH_PRI */
#define DMA_AD_CH_PRI_COUNT                      (32U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA_AD_CH_MUX_SRC_MASK                   (0x7FU)
#define DMA_AD_CH_MUX_SRC_SHIFT                  (0U)
/*! SRC - Service Request Source */
#define DMA_AD_CH_MUX_SRC(x)                     (((uint32_t)(((uint32_t)(x)) << DMA_AD_CH_MUX_SRC_SHIFT)) & DMA_AD_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA_AD_CH_MUX */
#define DMA_AD_CH_MUX_COUNT                      (32U)

/*! @name TCD_SADDR - TCD Source Address */
/*! @{ */

#define DMA_AD_TCD_SADDR_SADDR_MASK              (0xFFFFFFFFU)
#define DMA_AD_TCD_SADDR_SADDR_SHIFT             (0U)
/*! SADDR - Source Address */
#define DMA_AD_TCD_SADDR_SADDR(x)                (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_SADDR_SADDR_SHIFT)) & DMA_AD_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA_AD_TCD_SADDR */
#define DMA_AD_TCD_SADDR_COUNT                   (32U)

/*! @name TCD_SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA_AD_TCD_SOFF_SOFF_MASK                (0xFFFFU)
#define DMA_AD_TCD_SOFF_SOFF_SHIFT               (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA_AD_TCD_SOFF_SOFF(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_SOFF_SOFF_SHIFT)) & DMA_AD_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA_AD_TCD_SOFF */
#define DMA_AD_TCD_SOFF_COUNT                    (32U)

/*! @name TCD_ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA_AD_TCD_ATTR_DSIZE_MASK               (0x7U)
#define DMA_AD_TCD_ATTR_DSIZE_SHIFT              (0U)
/*! DSIZE - Destination Data Transfer Size */
#define DMA_AD_TCD_ATTR_DSIZE(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_ATTR_DSIZE_SHIFT)) & DMA_AD_TCD_ATTR_DSIZE_MASK)

#define DMA_AD_TCD_ATTR_DMOD_MASK                (0xF8U)
#define DMA_AD_TCD_ATTR_DMOD_SHIFT               (3U)
/*! DMOD - Destination Address Modulo */
#define DMA_AD_TCD_ATTR_DMOD(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_ATTR_DMOD_SHIFT)) & DMA_AD_TCD_ATTR_DMOD_MASK)

#define DMA_AD_TCD_ATTR_SSIZE_MASK               (0x700U)
#define DMA_AD_TCD_ATTR_SSIZE_SHIFT              (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..
 */
#define DMA_AD_TCD_ATTR_SSIZE(x)                 (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_ATTR_SSIZE_SHIFT)) & DMA_AD_TCD_ATTR_SSIZE_MASK)

#define DMA_AD_TCD_ATTR_SMOD_MASK                (0xF800U)
#define DMA_AD_TCD_ATTR_SMOD_SHIFT               (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Source address modulo feature disabled
 *  0b00001..Source address modulo feature enabled for any non-zero value [1-31]
 */
#define DMA_AD_TCD_ATTR_SMOD(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_ATTR_SMOD_SHIFT)) & DMA_AD_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA_AD_TCD_ATTR */
#define DMA_AD_TCD_ATTR_COUNT                    (32U)

/*! @name TCD_NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA_AD_TCD_NBYTES_MLOFFNO_NBYTES_MASK    (0x3FFFFFFFU)
#define DMA_AD_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT   (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_AD_TCD_NBYTES_MLOFFNO_NBYTES(x)      (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA_AD_TCD_NBYTES_MLOFFNO_DMLOE_MASK     (0x40000000U)
#define DMA_AD_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT    (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_AD_TCD_NBYTES_MLOFFNO_DMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA_AD_TCD_NBYTES_MLOFFNO_SMLOE_MASK     (0x80000000U)
#define DMA_AD_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT    (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_AD_TCD_NBYTES_MLOFFNO_SMLOE(x)       (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA_AD_TCD_NBYTES_MLOFFNO */
#define DMA_AD_TCD_NBYTES_MLOFFNO_COUNT          (32U)

/*! @name TCD_NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA_AD_TCD_NBYTES_MLOFFYES_NBYTES_MASK   (0x3FFU)
#define DMA_AD_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT  (0U)
/*! NBYTES - Number of Bytes To Transfer Per Service Request */
#define DMA_AD_TCD_NBYTES_MLOFFYES_NBYTES(x)     (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA_AD_TCD_NBYTES_MLOFFYES_MLOFF_MASK    (0x3FFFFC00U)
#define DMA_AD_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT   (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA_AD_TCD_NBYTES_MLOFFYES_MLOFF(x)      (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA_AD_TCD_NBYTES_MLOFFYES_DMLOE_MASK    (0x40000000U)
#define DMA_AD_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT   (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to DADDR
 *  0b1..Minor loop offset applied to DADDR
 */
#define DMA_AD_TCD_NBYTES_MLOFFYES_DMLOE(x)      (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA_AD_TCD_NBYTES_MLOFFYES_SMLOE_MASK    (0x80000000U)
#define DMA_AD_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT   (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Minor loop offset not applied to SADDR
 *  0b1..Minor loop offset applied to SADDR
 */
#define DMA_AD_TCD_NBYTES_MLOFFYES_SMLOE(x)      (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA_AD_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA_AD_TCD_NBYTES_MLOFFYES */
#define DMA_AD_TCD_NBYTES_MLOFFYES_COUNT         (32U)

/*! @name TCD_SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address */
/*! @{ */

#define DMA_AD_TCD_SLAST_SDA_SLAST_SDA_MASK      (0xFFFFFFFFU)
#define DMA_AD_TCD_SLAST_SDA_SLAST_SDA_SHIFT     (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA_AD_TCD_SLAST_SDA_SLAST_SDA(x)        (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA_AD_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA_AD_TCD_SLAST_SDA */
#define DMA_AD_TCD_SLAST_SDA_COUNT               (32U)

/*! @name TCD_DADDR - TCD Destination Address */
/*! @{ */

#define DMA_AD_TCD_DADDR_DADDR_MASK              (0xFFFFFFFFU)
#define DMA_AD_TCD_DADDR_DADDR_SHIFT             (0U)
/*! DADDR - Destination Address */
#define DMA_AD_TCD_DADDR_DADDR(x)                (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_DADDR_DADDR_SHIFT)) & DMA_AD_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA_AD_TCD_DADDR */
#define DMA_AD_TCD_DADDR_COUNT                   (32U)

/*! @name TCD_DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA_AD_TCD_DOFF_DOFF_MASK                (0xFFFFU)
#define DMA_AD_TCD_DOFF_DOFF_SHIFT               (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA_AD_TCD_DOFF_DOFF(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_DOFF_DOFF_SHIFT)) & DMA_AD_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA_AD_TCD_DOFF */
#define DMA_AD_TCD_DOFF_COUNT                    (32U)

/*! @name TCD_CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_AD_TCD_CITER_ELINKNO_CITER_MASK      (0x7FFFU)
#define DMA_AD_TCD_CITER_ELINKNO_CITER_SHIFT     (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_AD_TCD_CITER_ELINKNO_CITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA_AD_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA_AD_TCD_CITER_ELINKNO_ELINK_MASK      (0x8000U)
#define DMA_AD_TCD_CITER_ELINKNO_ELINK_SHIFT     (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_AD_TCD_CITER_ELINKNO_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA_AD_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_AD_TCD_CITER_ELINKNO */
#define DMA_AD_TCD_CITER_ELINKNO_COUNT           (32U)

/*! @name TCD_CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_AD_TCD_CITER_ELINKYES_CITER_MASK     (0x1FFU)
#define DMA_AD_TCD_CITER_ELINKYES_CITER_SHIFT    (0U)
/*! CITER - Current Major Iteration Count */
#define DMA_AD_TCD_CITER_ELINKYES_CITER(x)       (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA_AD_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA_AD_TCD_CITER_ELINKYES_LINKCH_MASK    (0x3E00U)
#define DMA_AD_TCD_CITER_ELINKYES_LINKCH_SHIFT   (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA_AD_TCD_CITER_ELINKYES_LINKCH(x)      (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA_AD_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA_AD_TCD_CITER_ELINKYES_ELINK_MASK     (0x8000U)
#define DMA_AD_TCD_CITER_ELINKYES_ELINK_SHIFT    (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_AD_TCD_CITER_ELINKYES_ELINK(x)       (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA_AD_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_AD_TCD_CITER_ELINKYES */
#define DMA_AD_TCD_CITER_ELINKYES_COUNT          (32U)

/*! @name TCD_DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address */
/*! @{ */

#define DMA_AD_TCD_DLAST_SGA_DLAST_SGA_MASK      (0xFFFFFFFFU)
#define DMA_AD_TCD_DLAST_SGA_DLAST_SGA_SHIFT     (0U)
/*! DLAST_SGA - Last Destination Address Adjustment / Scatter Gather Address */
#define DMA_AD_TCD_DLAST_SGA_DLAST_SGA(x)        (((uint32_t)(((uint32_t)(x)) << DMA_AD_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA_AD_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA_AD_TCD_DLAST_SGA */
#define DMA_AD_TCD_DLAST_SGA_COUNT               (32U)

/*! @name TCD_CSR - TCD Control and Status */
/*! @{ */

#define DMA_AD_TCD_CSR_START_MASK                (0x1U)
#define DMA_AD_TCD_CSR_START_SHIFT               (0U)
/*! START - Channel Start
 *  0b0..Channel not explicitly started
 *  0b1..Channel explicitly started via a software-initiated service request
 */
#define DMA_AD_TCD_CSR_START(x)                  (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_START_SHIFT)) & DMA_AD_TCD_CSR_START_MASK)

#define DMA_AD_TCD_CSR_INTMAJOR_MASK             (0x2U)
#define DMA_AD_TCD_CSR_INTMAJOR_SHIFT            (1U)
/*! INTMAJOR - Enable Interrupt If Major count complete
 *  0b0..End-of-major loop interrupt disabled
 *  0b1..End-of-major loop interrupt enabled
 */
#define DMA_AD_TCD_CSR_INTMAJOR(x)               (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_INTMAJOR_SHIFT)) & DMA_AD_TCD_CSR_INTMAJOR_MASK)

#define DMA_AD_TCD_CSR_INTHALF_MASK              (0x4U)
#define DMA_AD_TCD_CSR_INTHALF_SHIFT             (2U)
/*! INTHALF - Enable Interrupt If Major Counter Half-complete
 *  0b0..Halfway point interrupt disabled
 *  0b1..Halfway point interrupt enabled
 */
#define DMA_AD_TCD_CSR_INTHALF(x)                (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_INTHALF_SHIFT)) & DMA_AD_TCD_CSR_INTHALF_MASK)

#define DMA_AD_TCD_CSR_DREQ_MASK                 (0x8U)
#define DMA_AD_TCD_CSR_DREQ_SHIFT                (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear the ERQ field to 0 upon major loop completion, thus disabling hardware service requests
 */
#define DMA_AD_TCD_CSR_DREQ(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_DREQ_SHIFT)) & DMA_AD_TCD_CSR_DREQ_MASK)

#define DMA_AD_TCD_CSR_ESG_MASK                  (0x10U)
#define DMA_AD_TCD_CSR_ESG_SHIFT                 (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Current channel's TCD is normal format
 *  0b1..Current channel's TCD specifies scatter/gather format.
 */
#define DMA_AD_TCD_CSR_ESG(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_ESG_SHIFT)) & DMA_AD_TCD_CSR_ESG_MASK)

#define DMA_AD_TCD_CSR_MAJORELINK_MASK           (0x20U)
#define DMA_AD_TCD_CSR_MAJORELINK_SHIFT          (5U)
/*! MAJORELINK - Enable Link When Major Loop Complete
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_AD_TCD_CSR_MAJORELINK(x)             (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_MAJORELINK_SHIFT)) & DMA_AD_TCD_CSR_MAJORELINK_MASK)

#define DMA_AD_TCD_CSR_EEOP_MASK                 (0x40U)
#define DMA_AD_TCD_CSR_EEOP_SHIFT                (6U)
/*! EEOP - Enable End-Of-Packet Processing
 *  0b0..End-of-packet operation disabled
 *  0b1..End-of-packet hardware input signal enabled
 */
#define DMA_AD_TCD_CSR_EEOP(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_EEOP_SHIFT)) & DMA_AD_TCD_CSR_EEOP_MASK)

#define DMA_AD_TCD_CSR_ESDA_MASK                 (0x80U)
#define DMA_AD_TCD_CSR_ESDA_SHIFT                (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Ability to store destination address to system memory disabled
 *  0b1..Ability to store destination address to system memory enabled
 */
#define DMA_AD_TCD_CSR_ESDA(x)                   (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_ESDA_SHIFT)) & DMA_AD_TCD_CSR_ESDA_MASK)

#define DMA_AD_TCD_CSR_MAJORLINKCH_MASK          (0x1F00U)
#define DMA_AD_TCD_CSR_MAJORLINKCH_SHIFT         (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA_AD_TCD_CSR_MAJORLINKCH(x)            (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA_AD_TCD_CSR_MAJORLINKCH_MASK)

#define DMA_AD_TCD_CSR_BWC_MASK                  (0xC000U)
#define DMA_AD_TCD_CSR_BWC_SHIFT                 (14U)
/*! BWC - Bandwidth Control
 *  0b00..No eDMA engine stalls
 *  0b01..Enable eDMA master high-priority elevation (HPE) mode. No eDMA engine stalls.
 *  0b10..eDMA engine stalls for 4 cycles after each R/W
 *  0b11..eDMA engine stalls for 8 cycles after each R/W
 */
#define DMA_AD_TCD_CSR_BWC(x)                    (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_CSR_BWC_SHIFT)) & DMA_AD_TCD_CSR_BWC_MASK)
/*! @} */

/* The count of DMA_AD_TCD_CSR */
#define DMA_AD_TCD_CSR_COUNT                     (32U)

/*! @name TCD_BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA_AD_TCD_BITER_ELINKNO_BITER_MASK      (0x7FFFU)
#define DMA_AD_TCD_BITER_ELINKNO_BITER_SHIFT     (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_AD_TCD_BITER_ELINKNO_BITER(x)        (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA_AD_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA_AD_TCD_BITER_ELINKNO_ELINK_MASK      (0x8000U)
#define DMA_AD_TCD_BITER_ELINKNO_ELINK_SHIFT     (15U)
/*! ELINK - Enables Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_AD_TCD_BITER_ELINKNO_ELINK(x)        (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA_AD_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA_AD_TCD_BITER_ELINKNO */
#define DMA_AD_TCD_BITER_ELINKNO_COUNT           (32U)

/*! @name TCD_BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA_AD_TCD_BITER_ELINKYES_BITER_MASK     (0x1FFU)
#define DMA_AD_TCD_BITER_ELINKYES_BITER_SHIFT    (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA_AD_TCD_BITER_ELINKYES_BITER(x)       (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA_AD_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA_AD_TCD_BITER_ELINKYES_LINKCH_MASK    (0x3E00U)
#define DMA_AD_TCD_BITER_ELINKYES_LINKCH_SHIFT   (9U)
/*! LINKCH - Link Channel Number */
#define DMA_AD_TCD_BITER_ELINKYES_LINKCH(x)      (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA_AD_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA_AD_TCD_BITER_ELINKYES_ELINK_MASK     (0x8000U)
#define DMA_AD_TCD_BITER_ELINKYES_ELINK_SHIFT    (15U)
/*! ELINK - Enable Link
 *  0b0..Channel-to-channel linking disabled
 *  0b1..Channel-to-channel linking enabled
 */
#define DMA_AD_TCD_BITER_ELINKYES_ELINK(x)       (((uint16_t)(((uint16_t)(x)) << DMA_AD_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA_AD_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA_AD_TCD_BITER_ELINKYES */
#define DMA_AD_TCD_BITER_ELINKYES_COUNT          (32U)


/*!
 * @}
 */ /* end of group DMA_AD_Register_Masks */


/*!
 * @}
 */ /* end of group DMA_AD_Peripheral_Access_Layer */


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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* DMA_AD_H_ */

