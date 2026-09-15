/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DMA5
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_DMA5.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for DMA5
 *
 * CMSIS Peripheral Access Layer for DMA5
 */

#if !defined(PERI_DMA5_H_)
#define PERI_DMA5_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- DMA5 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA5_Peripheral_Access_Layer DMA5 Peripheral Access Layer
 * @{
 */

/** DMA5 - Size of Registers Arrays */
#define DMA5_MP_GRPRI_COUNT                       16u
#define DMA5_MP_CHMUX_COUNT                       16u
#define DMA5_TCD_COUNT                            16u

/** DMA5 - Register Layout Typedef */
typedef struct {
  __IO uint32_t MP_CSR;                            /**< Management Page Control, offset: 0x0 */
  __I  uint32_t MP_ES;                             /**< Management Page Error Status, offset: 0x4 */
  __I  uint32_t MP_INT_LOW;                        /**< Management Page Interrupt Request Status, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __I  uint32_t MP_HRS_LOW;                        /**< Hardware Request Status, offset: 0x10 */
       uint8_t RESERVED_1[12];
  __IO uint32_t MP_STOPCH;                         /**< Stop Channel, offset: 0x20 */
       uint8_t RESERVED_2[12];
  __I  uint32_t MP_SSR_LOW;                        /**< Stop Status, offset: 0x30 */
       uint8_t RESERVED_3[204];
  __IO uint32_t CH_GRPRI[DMA5_MP_GRPRI_COUNT];     /**< Channel Arbitration Group, array offset: 0x100, array step: 0x4 */
       uint8_t RESERVED_4[192];
  __IO uint32_t CH_MUX[DMA5_MP_CHMUX_COUNT];       /**< Channel Multiplexor Configuration, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_5[64960];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status, array offset: 0x10004, array step: 0x10000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status, array offset: 0x10008, array step: 0x10000 */
    __I  uint32_t CH_SBR;                            /**< Channel System Bus, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority, array offset: 0x10010, array step: 0x10000 */
         uint8_t RESERVED_0[4];
    __IO uint32_t CH_MATTR;                          /**< Memory Attributes, array offset: 0x10018, array step: 0x10000 */
         uint8_t RESERVED_1[4];
    __IO uint32_t SADDR;                             /**< TCD Source Address, array offset: 0x10020, array step: 0x10000 */
    __IO uint32_t SADDR_HIGH;                        /**< TCD Source Address, array offset: 0x10024, array step: 0x10000 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset, array offset: 0x10028, array step: 0x10000 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes, array offset: 0x1002A, array step: 0x10000 */
    union {                                          /* offset: 0x1002C, array step: 0x10000 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Transfer Size Without Minor Loop Offsets, array offset: 0x1002C, array step: 0x10000 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Transfer Size with Minor Loop Offsets, array offset: 0x1002C, array step: 0x10000 */
    };
    __IO uint32_t SLAST_SDA;                         /**< TCD Last Source Address Adjustment and Store DADDR Address, array offset: 0x10030, array step: 0x10000 */
    __IO uint32_t SLAST_SDA_HIGH;                    /**< TCD Last Source Address Adjustment and Store DADDR Address, array offset: 0x10034, array step: 0x10000 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address, array offset: 0x10038, array step: 0x10000 */
    __IO uint32_t DADDR_HIGH;                        /**< TCD Destination Address, array offset: 0x1003C, array step: 0x10000 */
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, array offset: 0x10040, array step: 0x10000 */
    __IO uint32_t DLAST_SGA_HIGH;                    /**< TCD Last Destination Address Adjustment and Scatter/Gather Address, array offset: 0x10044, array step: 0x10000 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset, array offset: 0x10048, array step: 0x10000 */
    union {                                          /* offset: 0x1004A, array step: 0x10000 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1004A, array step: 0x10000 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1004A, array step: 0x10000 */
    };
    __IO uint16_t CSR;                               /**< TCD Control and Status, array offset: 0x1004C, array step: 0x10000 */
    union {                                          /* offset: 0x1004E, array step: 0x10000 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled), array offset: 0x1004E, array step: 0x10000 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled), array offset: 0x1004E, array step: 0x10000 */
    };
         uint8_t RESERVED_2[65456];
  } TCD[DMA5_TCD_COUNT];
} DMA5_Type;

/* ----------------------------------------------------------------------------
   -- DMA5 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA5_Register_Masks DMA5 Register Masks
 * @{
 */

/*! @name MP_CSR - Management Page Control */
/*! @{ */

#define DMA5_MP_CSR_EDBG_MASK                    (0x2U)
#define DMA5_MP_CSR_EDBG_SHIFT                   (1U)
/*! EDBG - Enable Debug
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_MP_CSR_EDBG(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_EDBG_SHIFT)) & DMA5_MP_CSR_EDBG_MASK)

#define DMA5_MP_CSR_ERCA_MASK                    (0x4U)
#define DMA5_MP_CSR_ERCA_SHIFT                   (2U)
/*! ERCA - Enable Round Robin Channel Arbitration
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_MP_CSR_ERCA(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_ERCA_SHIFT)) & DMA5_MP_CSR_ERCA_MASK)

#define DMA5_MP_CSR_GCPC_MASK                    (0x8U)
#define DMA5_MP_CSR_GCPC_SHIFT                   (3U)
/*! GCPC - Global Channel Preemption Control
 *  0b0..Disabled for all channels
 *  0b1..Available within each channel group
 */
#define DMA5_MP_CSR_GCPC(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_GCPC_SHIFT)) & DMA5_MP_CSR_GCPC_MASK)

#define DMA5_MP_CSR_HAE_MASK                     (0x10U)
#define DMA5_MP_CSR_HAE_SHIFT                    (4U)
/*! HAE - Halt After Error
 *  0b0..Normal operation
 *  0b1..Halt
 */
#define DMA5_MP_CSR_HAE(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_HAE_SHIFT)) & DMA5_MP_CSR_HAE_MASK)

#define DMA5_MP_CSR_HALT_MASK                    (0x20U)
#define DMA5_MP_CSR_HALT_SHIFT                   (5U)
/*! HALT - Halt DMA Operations
 *  0b0..Normal operation
 *  0b1..Halt operation
 */
#define DMA5_MP_CSR_HALT(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_HALT_SHIFT)) & DMA5_MP_CSR_HALT_MASK)

#define DMA5_MP_CSR_GCLC_MASK                    (0x40U)
#define DMA5_MP_CSR_GCLC_SHIFT                   (6U)
/*! GCLC - Global Channel Linking Control
 *  0b0..Disabled
 *  0b1..Available
 */
#define DMA5_MP_CSR_GCLC(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_GCLC_SHIFT)) & DMA5_MP_CSR_GCLC_MASK)

#define DMA5_MP_CSR_VER_MASK                     (0xFF0000U)
#define DMA5_MP_CSR_VER_SHIFT                    (16U)
/*! VER - EDMA5 Version */
#define DMA5_MP_CSR_VER(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_VER_SHIFT)) & DMA5_MP_CSR_VER_MASK)

#define DMA5_MP_CSR_ACTIVE_ID_MASK               (0xF000000U)
#define DMA5_MP_CSR_ACTIVE_ID_SHIFT              (24U)
/*! ACTIVE_ID - Active Channel ID */
#define DMA5_MP_CSR_ACTIVE_ID(x)                 (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_ACTIVE_ID_SHIFT)) & DMA5_MP_CSR_ACTIVE_ID_MASK)

#define DMA5_MP_CSR_ACTIVE_MASK                  (0x80000000U)
#define DMA5_MP_CSR_ACTIVE_SHIFT                 (31U)
/*! ACTIVE - DMA Active Status
 *  0b0..Idle
 *  0b1..Executing
 */
#define DMA5_MP_CSR_ACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA5_MP_CSR_ACTIVE_SHIFT)) & DMA5_MP_CSR_ACTIVE_MASK)
/*! @} */

/*! @name MP_ES - Management Page Error Status */
/*! @{ */

#define DMA5_MP_ES_DBE_MASK                      (0x1U)
#define DMA5_MP_ES_DBE_SHIFT                     (0U)
/*! DBE - Destination Bus Error
 *  0b0..No error
 *  0b1..Error
 */
#define DMA5_MP_ES_DBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_DBE_SHIFT)) & DMA5_MP_ES_DBE_MASK)

#define DMA5_MP_ES_SBE_MASK                      (0x2U)
#define DMA5_MP_ES_SBE_SHIFT                     (1U)
/*! SBE - Source Bus Error
 *  0b0..No error
 *  0b1..Error
 */
#define DMA5_MP_ES_SBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_SBE_SHIFT)) & DMA5_MP_ES_SBE_MASK)

#define DMA5_MP_ES_SGE_MASK                      (0x4U)
#define DMA5_MP_ES_SGE_SHIFT                     (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_SGE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_SGE_SHIFT)) & DMA5_MP_ES_SGE_MASK)

#define DMA5_MP_ES_NCE_MASK                      (0x8U)
#define DMA5_MP_ES_NCE_SHIFT                     (3U)
/*! NCE - NBYTES or CITER Configuration Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_NCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_NCE_SHIFT)) & DMA5_MP_ES_NCE_MASK)

#define DMA5_MP_ES_DOE_MASK                      (0x10U)
#define DMA5_MP_ES_DOE_SHIFT                     (4U)
/*! DOE - Destination Offset Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_DOE_SHIFT)) & DMA5_MP_ES_DOE_MASK)

#define DMA5_MP_ES_DAE_MASK                      (0x20U)
#define DMA5_MP_ES_DAE_SHIFT                     (5U)
/*! DAE - Destination Address Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_DAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_DAE_SHIFT)) & DMA5_MP_ES_DAE_MASK)

#define DMA5_MP_ES_SOE_MASK                      (0x40U)
#define DMA5_MP_ES_SOE_SHIFT                     (6U)
/*! SOE - Source Offset Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_SOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_SOE_SHIFT)) & DMA5_MP_ES_SOE_MASK)

#define DMA5_MP_ES_SAE_MASK                      (0x80U)
#define DMA5_MP_ES_SAE_SHIFT                     (7U)
/*! SAE - Source Address Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_MP_ES_SAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_SAE_SHIFT)) & DMA5_MP_ES_SAE_MASK)

#define DMA5_MP_ES_ECX_MASK                      (0x100U)
#define DMA5_MP_ES_ECX_SHIFT                     (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Canceled transfer
 */
#define DMA5_MP_ES_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_ECX_SHIFT)) & DMA5_MP_ES_ECX_MASK)

#define DMA5_MP_ES_UCE_MASK                      (0x200U)
#define DMA5_MP_ES_UCE_SHIFT                     (9U)
/*! UCE - Uncorrectable TCD Error During Channel Execution
 *  0b0..No error
 *  0b1..TCD RAM error
 */
#define DMA5_MP_ES_UCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_UCE_SHIFT)) & DMA5_MP_ES_UCE_MASK)

#define DMA5_MP_ES_ERRCHN_MASK                   (0xF000000U)
#define DMA5_MP_ES_ERRCHN_SHIFT                  (24U)
/*! ERRCHN - Error Channel Number or Canceled Channel Number */
#define DMA5_MP_ES_ERRCHN(x)                     (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_ERRCHN_SHIFT)) & DMA5_MP_ES_ERRCHN_MASK)

#define DMA5_MP_ES_VLD_MASK                      (0x80000000U)
#define DMA5_MP_ES_VLD_SHIFT                     (31U)
/*! VLD - Valid
 *  0b0..No bits are set
 *  0b1..At least one bit is set
 */
#define DMA5_MP_ES_VLD(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_MP_ES_VLD_SHIFT)) & DMA5_MP_ES_VLD_MASK)
/*! @} */

/*! @name MP_INT_LOW - Management Page Interrupt Request Status */
/*! @{ */

#define DMA5_MP_INT_LOW_INT_MASK                 (0xFFFFU)
#define DMA5_MP_INT_LOW_INT_SHIFT                (0U)
/*! INT - Interrupt Request Status */
#define DMA5_MP_INT_LOW_INT(x)                   (((uint32_t)(((uint32_t)(x)) << DMA5_MP_INT_LOW_INT_SHIFT)) & DMA5_MP_INT_LOW_INT_MASK)
/*! @} */

/*! @name MP_HRS_LOW - Hardware Request Status */
/*! @{ */

#define DMA5_MP_HRS_LOW_HRS_MASK                 (0xFFFFU)
#define DMA5_MP_HRS_LOW_HRS_SHIFT                (0U)
/*! HRS - Hardware Request Status */
#define DMA5_MP_HRS_LOW_HRS(x)                   (((uint32_t)(((uint32_t)(x)) << DMA5_MP_HRS_LOW_HRS_SHIFT)) & DMA5_MP_HRS_LOW_HRS_MASK)
/*! @} */

/*! @name MP_STOPCH - Stop Channel */
/*! @{ */

#define DMA5_MP_STOPCH_STOPCH_MASK               (0xFU)
#define DMA5_MP_STOPCH_STOPCH_SHIFT              (0U)
/*! STOPCH - Stop Channel */
#define DMA5_MP_STOPCH_STOPCH(x)                 (((uint32_t)(((uint32_t)(x)) << DMA5_MP_STOPCH_STOPCH_SHIFT)) & DMA5_MP_STOPCH_STOPCH_MASK)

#define DMA5_MP_STOPCH_ERR_MASK                  (0x80U)
#define DMA5_MP_STOPCH_ERR_SHIFT                 (7U)
/*! ERR - Stop Channel with Error Exit
 *  0b0..Stop channel without error reporting
 *  0b1..Stop channel with error reporting
 */
#define DMA5_MP_STOPCH_ERR(x)                    (((uint32_t)(((uint32_t)(x)) << DMA5_MP_STOPCH_ERR_SHIFT)) & DMA5_MP_STOPCH_ERR_MASK)
/*! @} */

/*! @name MP_SSR_LOW - Stop Status */
/*! @{ */

#define DMA5_MP_SSR_LOW_CSS_MASK                 (0xFFFFU)
#define DMA5_MP_SSR_LOW_CSS_SHIFT                (0U)
/*! CSS - Channel Stop Status */
#define DMA5_MP_SSR_LOW_CSS(x)                   (((uint32_t)(((uint32_t)(x)) << DMA5_MP_SSR_LOW_CSS_SHIFT)) & DMA5_MP_SSR_LOW_CSS_MASK)
/*! @} */

/*! @name CH_GRPRI - Channel Arbitration Group */
/*! @{ */

#define DMA5_CH_GRPRI_GRPRI_MASK                 (0x3FU)
#define DMA5_CH_GRPRI_GRPRI_SHIFT                (0U)
/*! GRPRI - Arbitration Group Per Channel */
#define DMA5_CH_GRPRI_GRPRI(x)                   (((uint32_t)(((uint32_t)(x)) << DMA5_CH_GRPRI_GRPRI_SHIFT)) & DMA5_CH_GRPRI_GRPRI_MASK)
/*! @} */

/* The count of DMA5_CH_GRPRI */
#define DMA5_CH_GRPRI_COUNT                      (16U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA5_CH_MUX_SRC_MASK                     (0x7FU)
#define DMA5_CH_MUX_SRC_SHIFT                    (0U)
/*! SRC - Service Request Source */
#define DMA5_CH_MUX_SRC(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_MUX_SRC_SHIFT)) & DMA5_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA5_CH_MUX */
#define DMA5_CH_MUX_COUNT                        (16U)

/*! @name CH_CSR - Channel Control and Status */
/*! @{ */

#define DMA5_CH_CSR_ERQ_MASK                     (0x1U)
#define DMA5_CH_CSR_ERQ_SHIFT                    (0U)
/*! ERQ - Enable DMA Request
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CH_CSR_ERQ(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_ERQ_SHIFT)) & DMA5_CH_CSR_ERQ_MASK)

#define DMA5_CH_CSR_EARQ_MASK                    (0x2U)
#define DMA5_CH_CSR_EARQ_SHIFT                   (1U)
/*! EARQ - Enable Asynchronous DMA Request in Stop Mode for Channel
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CH_CSR_EARQ(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_EARQ_SHIFT)) & DMA5_CH_CSR_EARQ_MASK)

#define DMA5_CH_CSR_EEI_MASK                     (0x4U)
#define DMA5_CH_CSR_EEI_SHIFT                    (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..Do not generate
 *  0b1..Generate
 */
#define DMA5_CH_CSR_EEI(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_EEI_SHIFT)) & DMA5_CH_CSR_EEI_MASK)

#define DMA5_CH_CSR_CX_MASK                      (0x40U)
#define DMA5_CH_CSR_CX_SHIFT                     (6U)
/*! CX - Stop Transferring Data
 *  0b0..No operation
 *  0b1..Stop the channel; no error reporting
 */
#define DMA5_CH_CSR_CX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_CX_SHIFT)) & DMA5_CH_CSR_CX_MASK)

#define DMA5_CH_CSR_ECX_MASK                     (0x80U)
#define DMA5_CH_CSR_ECX_SHIFT                    (7U)
/*! ECX - Stop Transferring Data and Set an Error
 *  0b0..No operation
 *  0b1..Stop the channel with error reporting
 */
#define DMA5_CH_CSR_ECX(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_ECX_SHIFT)) & DMA5_CH_CSR_ECX_MASK)

#define DMA5_CH_CSR_SWAP_MASK                    (0xF000U)
#define DMA5_CH_CSR_SWAP_SHIFT                   (12U)
/*! SWAP - Swap Size
 *  0b0000..Disabled
 *  0b0001..Read with 8-bit swap
 *  0b0010..Read with 16-bit swap
 *  0b0011..Read with 32-bit swap
 *  0b0100-0b1000..Reserved
 *  0b1001..Write with 8-bit swap
 *  0b1010..Write with 16-bit swap
 *  0b1011..Write with 32-bit swap
 *  0b1100-0b1111..Reserved
 */
#define DMA5_CH_CSR_SWAP(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_SWAP_SHIFT)) & DMA5_CH_CSR_SWAP_MASK)

#define DMA5_CH_CSR_SIGNEXT_MASK                 (0x3F0000U)
#define DMA5_CH_CSR_SIGNEXT_SHIFT                (16U)
/*! SIGNEXT - Sign Extension
 *  0b000000..Sign extension disabled
 *  0b000001..Nonzero value specifying the sign extend bit position
 */
#define DMA5_CH_CSR_SIGNEXT(x)                   (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_SIGNEXT_SHIFT)) & DMA5_CH_CSR_SIGNEXT_MASK)

#define DMA5_CH_CSR_DONE_MASK                    (0x40000000U)
#define DMA5_CH_CSR_DONE_SHIFT                   (30U)
/*! DONE - Channel Done Flag
 *  0b0..No effect
 *  0b0..Not done
 *  0b1..Clear the flag
 *  0b1..Done
 */
#define DMA5_CH_CSR_DONE(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_DONE_SHIFT)) & DMA5_CH_CSR_DONE_MASK)

#define DMA5_CH_CSR_ACTIVE_MASK                  (0x80000000U)
#define DMA5_CH_CSR_ACTIVE_SHIFT                 (31U)
/*! ACTIVE - Channel Active */
#define DMA5_CH_CSR_ACTIVE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA5_CH_CSR_ACTIVE_SHIFT)) & DMA5_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA5_CH_CSR */
#define DMA5_CH_CSR_COUNT                        (16U)

/*! @name CH_ES - Channel Error Status */
/*! @{ */

#define DMA5_CH_ES_DBE_MASK                      (0x1U)
#define DMA5_CH_ES_DBE_SHIFT                     (0U)
/*! DBE - Destination Bus Error
 *  0b0..No error
 *  0b1..Error
 */
#define DMA5_CH_ES_DBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_DBE_SHIFT)) & DMA5_CH_ES_DBE_MASK)

#define DMA5_CH_ES_SBE_MASK                      (0x2U)
#define DMA5_CH_ES_SBE_SHIFT                     (1U)
/*! SBE - Source Bus Error
 *  0b0..No error
 *  0b1..Error
 */
#define DMA5_CH_ES_SBE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_SBE_SHIFT)) & DMA5_CH_ES_SBE_MASK)

#define DMA5_CH_ES_SGE_MASK                      (0x4U)
#define DMA5_CH_ES_SGE_SHIFT                     (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_SGE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_SGE_SHIFT)) & DMA5_CH_ES_SGE_MASK)

#define DMA5_CH_ES_NCE_MASK                      (0x8U)
#define DMA5_CH_ES_NCE_SHIFT                     (3U)
/*! NCE - NBYTES or CITER Configuration Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_NCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_NCE_SHIFT)) & DMA5_CH_ES_NCE_MASK)

#define DMA5_CH_ES_DOE_MASK                      (0x10U)
#define DMA5_CH_ES_DOE_SHIFT                     (4U)
/*! DOE - Destination Offset Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_DOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_DOE_SHIFT)) & DMA5_CH_ES_DOE_MASK)

#define DMA5_CH_ES_DAE_MASK                      (0x20U)
#define DMA5_CH_ES_DAE_SHIFT                     (5U)
/*! DAE - Destination Address Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_DAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_DAE_SHIFT)) & DMA5_CH_ES_DAE_MASK)

#define DMA5_CH_ES_SOE_MASK                      (0x40U)
#define DMA5_CH_ES_SOE_SHIFT                     (6U)
/*! SOE - Source Offset Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_SOE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_SOE_SHIFT)) & DMA5_CH_ES_SOE_MASK)

#define DMA5_CH_ES_SAE_MASK                      (0x80U)
#define DMA5_CH_ES_SAE_SHIFT                     (7U)
/*! SAE - Source Address Error
 *  0b0..No error detected
 *  0b1..Error detected
 */
#define DMA5_CH_ES_SAE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_SAE_SHIFT)) & DMA5_CH_ES_SAE_MASK)

#define DMA5_CH_ES_ECX_MASK                      (0x100U)
#define DMA5_CH_ES_ECX_SHIFT                     (8U)
/*! ECX - Transfer Canceled
 *  0b0..No canceled transfers
 *  0b1..Canceled transfer
 */
#define DMA5_CH_ES_ECX(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_ECX_SHIFT)) & DMA5_CH_ES_ECX_MASK)

#define DMA5_CH_ES_UCE_MASK                      (0x200U)
#define DMA5_CH_ES_UCE_SHIFT                     (9U)
/*! UCE - Uncorrectable TCD Error During Channel Execution
 *  0b0..No error
 *  0b1..Error
 */
#define DMA5_CH_ES_UCE(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_UCE_SHIFT)) & DMA5_CH_ES_UCE_MASK)

#define DMA5_CH_ES_ERR_MASK                      (0x80000000U)
#define DMA5_CH_ES_ERR_SHIFT                     (31U)
/*! ERR - Error in Channel Flag
 *  0b0..No effect
 *  0b0..Not occurred
 *  0b1..Clear the flag
 *  0b1..Occurred
 */
#define DMA5_CH_ES_ERR(x)                        (((uint32_t)(((uint32_t)(x)) << DMA5_CH_ES_ERR_SHIFT)) & DMA5_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA5_CH_ES */
#define DMA5_CH_ES_COUNT                         (16U)

/*! @name CH_INT - Channel Interrupt Status */
/*! @{ */

#define DMA5_CH_INT_INT_MASK                     (0x1U)
#define DMA5_CH_INT_INT_SHIFT                    (0U)
/*! INT - Interrupt Request Flag
 *  0b0..Cleared
 *  0b0..No effect
 *  0b1..Active
 *  0b1..Clear the flag
 */
#define DMA5_CH_INT_INT(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_INT_INT_SHIFT)) & DMA5_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA5_CH_INT */
#define DMA5_CH_INT_COUNT                        (16U)

/*! @name CH_SBR - Channel System Bus */
/*! @{ */

#define DMA5_CH_SBR_INSTR_MASK                   (0x2000U)
#define DMA5_CH_SBR_INSTR_SHIFT                  (13U)
/*! INSTR - Instruction or Data Access
 *  0b0..Data access
 *  0b1..Instruction access
 */
#define DMA5_CH_SBR_INSTR(x)                     (((uint32_t)(((uint32_t)(x)) << DMA5_CH_SBR_INSTR_SHIFT)) & DMA5_CH_SBR_INSTR_MASK)
/*! @} */

/* The count of DMA5_CH_SBR */
#define DMA5_CH_SBR_COUNT                        (16U)

/*! @name CH_PRI - Channel Priority */
/*! @{ */

#define DMA5_CH_PRI_APL_MASK                     (0x7U)
#define DMA5_CH_PRI_APL_SHIFT                    (0U)
/*! APL - Arbitration Priority Level */
#define DMA5_CH_PRI_APL(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_PRI_APL_SHIFT)) & DMA5_CH_PRI_APL_MASK)

#define DMA5_CH_PRI_DPA_MASK                     (0x40000000U)
#define DMA5_CH_PRI_DPA_SHIFT                    (30U)
/*! DPA - Disable Preempt Ability
 *  0b0..Can suspend a lower priority channel
 *  0b1..Cannot suspend any other channel
 */
#define DMA5_CH_PRI_DPA(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_PRI_DPA_SHIFT)) & DMA5_CH_PRI_DPA_MASK)

#define DMA5_CH_PRI_ECP_MASK                     (0x80000000U)
#define DMA5_CH_PRI_ECP_SHIFT                    (31U)
/*! ECP - Enable Channel Preemption
 *  0b0..Cannot be suspended
 *  0b1..Can be temporarily suspended
 */
#define DMA5_CH_PRI_ECP(x)                       (((uint32_t)(((uint32_t)(x)) << DMA5_CH_PRI_ECP_SHIFT)) & DMA5_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA5_CH_PRI */
#define DMA5_CH_PRI_COUNT                        (16U)

/*! @name CH_MATTR - Memory Attributes */
/*! @{ */

#define DMA5_CH_MATTR_RCACHE_MASK                (0xFU)
#define DMA5_CH_MATTR_RCACHE_SHIFT               (0U)
/*! RCACHE - Read Cache Attributes */
#define DMA5_CH_MATTR_RCACHE(x)                  (((uint32_t)(((uint32_t)(x)) << DMA5_CH_MATTR_RCACHE_SHIFT)) & DMA5_CH_MATTR_RCACHE_MASK)

#define DMA5_CH_MATTR_WCACHE_MASK                (0xF0U)
#define DMA5_CH_MATTR_WCACHE_SHIFT               (4U)
/*! WCACHE - Write Cache Attributes */
#define DMA5_CH_MATTR_WCACHE(x)                  (((uint32_t)(((uint32_t)(x)) << DMA5_CH_MATTR_WCACHE_SHIFT)) & DMA5_CH_MATTR_WCACHE_MASK)
/*! @} */

/* The count of DMA5_CH_MATTR */
#define DMA5_CH_MATTR_COUNT                      (16U)

/*! @name SADDR - TCD Source Address */
/*! @{ */

#define DMA5_SADDR_SADDR_MASK                    (0xFFFFFFFFU)
#define DMA5_SADDR_SADDR_SHIFT                   (0U)
/*! SADDR - Source Address */
#define DMA5_SADDR_SADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_SADDR_SADDR_SHIFT)) & DMA5_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA5_SADDR */
#define DMA5_SADDR_COUNT                         (16U)

/*! @name SADDR_HIGH - TCD Source Address */
/*! @{ */

#define DMA5_SADDR_HIGH_SADDR_MASK               (0xFFFFFFFFU)
#define DMA5_SADDR_HIGH_SADDR_SHIFT              (0U)
/*! SADDR - Source Address */
#define DMA5_SADDR_HIGH_SADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA5_SADDR_HIGH_SADDR_SHIFT)) & DMA5_SADDR_HIGH_SADDR_MASK)
/*! @} */

/* The count of DMA5_SADDR_HIGH */
#define DMA5_SADDR_HIGH_COUNT                    (16U)

/*! @name SOFF - TCD Signed Source Address Offset */
/*! @{ */

#define DMA5_SOFF_SOFF_MASK                      (0xFFFFU)
#define DMA5_SOFF_SOFF_SHIFT                     (0U)
/*! SOFF - Source Address Signed Offset */
#define DMA5_SOFF_SOFF(x)                        (((uint16_t)(((uint16_t)(x)) << DMA5_SOFF_SOFF_SHIFT)) & DMA5_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA5_SOFF */
#define DMA5_SOFF_COUNT                          (16U)

/*! @name ATTR - TCD Transfer Attributes */
/*! @{ */

#define DMA5_ATTR_DSIZE_MASK                     (0x7U)
#define DMA5_ATTR_DSIZE_SHIFT                    (0U)
/*! DSIZE - Destination Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA5_ATTR_DSIZE(x)                       (((uint16_t)(((uint16_t)(x)) << DMA5_ATTR_DSIZE_SHIFT)) & DMA5_ATTR_DSIZE_MASK)

#define DMA5_ATTR_DMOD_MASK                      (0xF8U)
#define DMA5_ATTR_DMOD_SHIFT                     (3U)
/*! DMOD - Destination Address Modulo */
#define DMA5_ATTR_DMOD(x)                        (((uint16_t)(((uint16_t)(x)) << DMA5_ATTR_DMOD_SHIFT)) & DMA5_ATTR_DMOD_MASK)

#define DMA5_ATTR_SSIZE_MASK                     (0x700U)
#define DMA5_ATTR_SSIZE_SHIFT                    (8U)
/*! SSIZE - Source Data Transfer Size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA5_ATTR_SSIZE(x)                       (((uint16_t)(((uint16_t)(x)) << DMA5_ATTR_SSIZE_SHIFT)) & DMA5_ATTR_SSIZE_MASK)

#define DMA5_ATTR_SMOD_MASK                      (0xF800U)
#define DMA5_ATTR_SMOD_SHIFT                     (11U)
/*! SMOD - Source Address Modulo
 *  0b00000..Disable
 *  0b00001..Enable
 */
#define DMA5_ATTR_SMOD(x)                        (((uint16_t)(((uint16_t)(x)) << DMA5_ATTR_SMOD_SHIFT)) & DMA5_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA5_ATTR */
#define DMA5_ATTR_COUNT                          (16U)

/*! @name NBYTES_MLOFFNO - TCD Transfer Size Without Minor Loop Offsets */
/*! @{ */

#define DMA5_NBYTES_MLOFFNO_NBYTES_MASK          (0x3FFFFFFFU)
#define DMA5_NBYTES_MLOFFNO_NBYTES_SHIFT         (0U)
/*! NBYTES - Number of Bytes to Transfer Per Service Request */
#define DMA5_NBYTES_MLOFFNO_NBYTES(x)            (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA5_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA5_NBYTES_MLOFFNO_DMLOE_MASK           (0x40000000U)
#define DMA5_NBYTES_MLOFFNO_DMLOE_SHIFT          (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Do not apply
 *  0b1..Apply
 */
#define DMA5_NBYTES_MLOFFNO_DMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA5_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA5_NBYTES_MLOFFNO_SMLOE_MASK           (0x80000000U)
#define DMA5_NBYTES_MLOFFNO_SMLOE_SHIFT          (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Do not apply
 *  0b1..Apply
 */
#define DMA5_NBYTES_MLOFFNO_SMLOE(x)             (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA5_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA5_NBYTES_MLOFFNO */
#define DMA5_NBYTES_MLOFFNO_COUNT                (16U)

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets */
/*! @{ */

#define DMA5_NBYTES_MLOFFYES_NBYTES_MASK         (0x3FFU)
#define DMA5_NBYTES_MLOFFYES_NBYTES_SHIFT        (0U)
/*! NBYTES - Number of Bytes to Transfer Per Service Request */
#define DMA5_NBYTES_MLOFFYES_NBYTES(x)           (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA5_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA5_NBYTES_MLOFFYES_MLOFF_MASK          (0x3FFFFC00U)
#define DMA5_NBYTES_MLOFFYES_MLOFF_SHIFT         (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA5_NBYTES_MLOFFYES_MLOFF(x)            (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA5_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA5_NBYTES_MLOFFYES_DMLOE_MASK          (0x40000000U)
#define DMA5_NBYTES_MLOFFYES_DMLOE_SHIFT         (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..Do not apply
 *  0b1..Apply
 */
#define DMA5_NBYTES_MLOFFYES_DMLOE(x)            (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA5_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA5_NBYTES_MLOFFYES_SMLOE_MASK          (0x80000000U)
#define DMA5_NBYTES_MLOFFYES_SMLOE_SHIFT         (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..Do not apply
 *  0b1..Apply
 */
#define DMA5_NBYTES_MLOFFYES_SMLOE(x)            (((uint32_t)(((uint32_t)(x)) << DMA5_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA5_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA5_NBYTES_MLOFFYES */
#define DMA5_NBYTES_MLOFFYES_COUNT               (16U)

/*! @name SLAST_SDA - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define DMA5_SLAST_SDA_SLAST_SDA_MASK            (0xFFFFFFFFU)
#define DMA5_SLAST_SDA_SLAST_SDA_SHIFT           (0U)
/*! SLAST_SDA - Last Source Address Adjustment and Store DADDR Address */
#define DMA5_SLAST_SDA_SLAST_SDA(x)              (((uint32_t)(((uint32_t)(x)) << DMA5_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA5_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA5_SLAST_SDA */
#define DMA5_SLAST_SDA_COUNT                     (16U)

/*! @name SLAST_SDA_HIGH - TCD Last Source Address Adjustment and Store DADDR Address */
/*! @{ */

#define DMA5_SLAST_SDA_HIGH_SLAST_SDA_MASK       (0xFFFFFFFFU)
#define DMA5_SLAST_SDA_HIGH_SLAST_SDA_SHIFT      (0U)
/*! SLAST_SDA - Last Source Address Adjustment and Store DADDR Address */
#define DMA5_SLAST_SDA_HIGH_SLAST_SDA(x)         (((uint32_t)(((uint32_t)(x)) << DMA5_SLAST_SDA_HIGH_SLAST_SDA_SHIFT)) & DMA5_SLAST_SDA_HIGH_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA5_SLAST_SDA_HIGH */
#define DMA5_SLAST_SDA_HIGH_COUNT                (16U)

/*! @name DADDR - TCD Destination Address */
/*! @{ */

#define DMA5_DADDR_DADDR_MASK                    (0xFFFFFFFFU)
#define DMA5_DADDR_DADDR_SHIFT                   (0U)
/*! DADDR - Destination Address */
#define DMA5_DADDR_DADDR(x)                      (((uint32_t)(((uint32_t)(x)) << DMA5_DADDR_DADDR_SHIFT)) & DMA5_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA5_DADDR */
#define DMA5_DADDR_COUNT                         (16U)

/*! @name DADDR_HIGH - TCD Destination Address */
/*! @{ */

#define DMA5_DADDR_HIGH_DADDR_MASK               (0xFFFFFFFFU)
#define DMA5_DADDR_HIGH_DADDR_SHIFT              (0U)
/*! DADDR - Destination Address */
#define DMA5_DADDR_HIGH_DADDR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA5_DADDR_HIGH_DADDR_SHIFT)) & DMA5_DADDR_HIGH_DADDR_MASK)
/*! @} */

/* The count of DMA5_DADDR_HIGH */
#define DMA5_DADDR_HIGH_COUNT                    (16U)

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define DMA5_DLAST_SGA_DLAST_SGA_MASK            (0xFFFFFFFFU)
#define DMA5_DLAST_SGA_DLAST_SGA_SHIFT           (0U)
/*! DLAST_SGA - Final Destination Address Adjustment and Scatter/Gather Address */
#define DMA5_DLAST_SGA_DLAST_SGA(x)              (((uint32_t)(((uint32_t)(x)) << DMA5_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA5_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA5_DLAST_SGA */
#define DMA5_DLAST_SGA_COUNT                     (16U)

/*! @name DLAST_SGA_HIGH - TCD Last Destination Address Adjustment and Scatter/Gather Address */
/*! @{ */

#define DMA5_DLAST_SGA_HIGH_DLAST_SGA_MASK       (0xFFFFFFFFU)
#define DMA5_DLAST_SGA_HIGH_DLAST_SGA_SHIFT      (0U)
/*! DLAST_SGA - Final Destination Address Adjustment and Scatter/Gather Address */
#define DMA5_DLAST_SGA_HIGH_DLAST_SGA(x)         (((uint32_t)(((uint32_t)(x)) << DMA5_DLAST_SGA_HIGH_DLAST_SGA_SHIFT)) & DMA5_DLAST_SGA_HIGH_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA5_DLAST_SGA_HIGH */
#define DMA5_DLAST_SGA_HIGH_COUNT                (16U)

/*! @name DOFF - TCD Signed Destination Address Offset */
/*! @{ */

#define DMA5_DOFF_DOFF_MASK                      (0xFFFFU)
#define DMA5_DOFF_DOFF_SHIFT                     (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA5_DOFF_DOFF(x)                        (((uint16_t)(((uint16_t)(x)) << DMA5_DOFF_DOFF_SHIFT)) & DMA5_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA5_DOFF */
#define DMA5_DOFF_COUNT                          (16U)

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA5_CITER_ELINKNO_CITER_MASK            (0x7FFFU)
#define DMA5_CITER_ELINKNO_CITER_SHIFT           (0U)
/*! CITER - Current Major Iteration Count */
#define DMA5_CITER_ELINKNO_CITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA5_CITER_ELINKNO_CITER_SHIFT)) & DMA5_CITER_ELINKNO_CITER_MASK)

#define DMA5_CITER_ELINKNO_ELINK_MASK            (0x8000U)
#define DMA5_CITER_ELINKNO_ELINK_SHIFT           (15U)
/*! ELINK - Enable Channel-to-Channel Linking on Minor-Loop Completion
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CITER_ELINKNO_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA5_CITER_ELINKNO_ELINK_SHIFT)) & DMA5_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA5_CITER_ELINKNO */
#define DMA5_CITER_ELINKNO_COUNT                 (16U)

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA5_CITER_ELINKYES_CITER_MASK           (0x1FFU)
#define DMA5_CITER_ELINKYES_CITER_SHIFT          (0U)
/*! CITER - Current Major Iteration Count */
#define DMA5_CITER_ELINKYES_CITER(x)             (((uint16_t)(((uint16_t)(x)) << DMA5_CITER_ELINKYES_CITER_SHIFT)) & DMA5_CITER_ELINKYES_CITER_MASK)

#define DMA5_CITER_ELINKYES_LINKCH_MASK          (0x1E00U)
#define DMA5_CITER_ELINKYES_LINKCH_SHIFT         (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA5_CITER_ELINKYES_LINKCH(x)            (((uint16_t)(((uint16_t)(x)) << DMA5_CITER_ELINKYES_LINKCH_SHIFT)) & DMA5_CITER_ELINKYES_LINKCH_MASK)

#define DMA5_CITER_ELINKYES_ELINK_MASK           (0x8000U)
#define DMA5_CITER_ELINKYES_ELINK_SHIFT          (15U)
/*! ELINK - Enable Channel-to-Channel Linking on Minor-Loop Complete
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CITER_ELINKYES_ELINK(x)             (((uint16_t)(((uint16_t)(x)) << DMA5_CITER_ELINKYES_ELINK_SHIFT)) & DMA5_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA5_CITER_ELINKYES */
#define DMA5_CITER_ELINKYES_COUNT                (16U)

/*! @name CSR - TCD Control and Status */
/*! @{ */

#define DMA5_CSR_START_MASK                      (0x1U)
#define DMA5_CSR_START_SHIFT                     (0U)
/*! START - Channel Start
 *  0b0..Not started
 *  0b1..Started
 */
#define DMA5_CSR_START(x)                        (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_START_SHIFT)) & DMA5_CSR_START_MASK)

#define DMA5_CSR_INTMAJOR_MASK                   (0x2U)
#define DMA5_CSR_INTMAJOR_SHIFT                  (1U)
/*! INTMAJOR - Enable an Interrupt when Major Iteration Count Completes
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CSR_INTMAJOR(x)                     (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_INTMAJOR_SHIFT)) & DMA5_CSR_INTMAJOR_MASK)

#define DMA5_CSR_INTHALF_MASK                    (0x4U)
#define DMA5_CSR_INTHALF_SHIFT                   (2U)
/*! INTHALF - Enable an Interrupt when Major Counter is Half Complete
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CSR_INTHALF(x)                      (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_INTHALF_SHIFT)) & DMA5_CSR_INTHALF_MASK)

#define DMA5_CSR_DREQ_MASK                       (0x8U)
#define DMA5_CSR_DREQ_SHIFT                      (3U)
/*! DREQ - Disable Request
 *  0b0..No operation
 *  0b1..Clear ERQ
 */
#define DMA5_CSR_DREQ(x)                         (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_DREQ_SHIFT)) & DMA5_CSR_DREQ_MASK)

#define DMA5_CSR_ESG_MASK                        (0x10U)
#define DMA5_CSR_ESG_SHIFT                       (4U)
/*! ESG - Enable Scatter/Gather Processing
 *  0b0..Normal format
 *  0b1..Scatter/gather format
 */
#define DMA5_CSR_ESG(x)                          (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_ESG_SHIFT)) & DMA5_CSR_ESG_MASK)

#define DMA5_CSR_MAJORELINK_MASK                 (0x20U)
#define DMA5_CSR_MAJORELINK_SHIFT                (5U)
/*! MAJORELINK - Enable Channel-to-Channel Linking on Major Loop Complete
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CSR_MAJORELINK(x)                   (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_MAJORELINK_SHIFT)) & DMA5_CSR_MAJORELINK_MASK)

#define DMA5_CSR_EEOP_MASK                       (0x40U)
#define DMA5_CSR_EEOP_SHIFT                      (6U)
/*! EEOP - Enable End-of-Packet Processing
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CSR_EEOP(x)                         (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_EEOP_SHIFT)) & DMA5_CSR_EEOP_MASK)

#define DMA5_CSR_ESDA_MASK                       (0x80U)
#define DMA5_CSR_ESDA_SHIFT                      (7U)
/*! ESDA - Enable Store Destination Address
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_CSR_ESDA(x)                         (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_ESDA_SHIFT)) & DMA5_CSR_ESDA_MASK)

#define DMA5_CSR_MAJORLINKCH_MASK                (0x3F00U)
#define DMA5_CSR_MAJORLINKCH_SHIFT               (8U)
/*! MAJORLINKCH - Major Loop Link Channel Number */
#define DMA5_CSR_MAJORLINKCH(x)                  (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_MAJORLINKCH_SHIFT)) & DMA5_CSR_MAJORLINKCH_MASK)

#define DMA5_CSR_TMC_MASK                        (0xC000U)
#define DMA5_CSR_TMC_SHIFT                       (14U)
/*! TMC - Transfer Mode Control
 *  0b00..Read/Write
 *  0b01..Read-Only
 *  0b10..Write-Only
 *  0b11..Reserved
 */
#define DMA5_CSR_TMC(x)                          (((uint16_t)(((uint16_t)(x)) << DMA5_CSR_TMC_SHIFT)) & DMA5_CSR_TMC_MASK)
/*! @} */

/* The count of DMA5_CSR */
#define DMA5_CSR_COUNT                           (16U)

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) */
/*! @{ */

#define DMA5_BITER_ELINKNO_BITER_MASK            (0x7FFFU)
#define DMA5_BITER_ELINKNO_BITER_SHIFT           (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA5_BITER_ELINKNO_BITER(x)              (((uint16_t)(((uint16_t)(x)) << DMA5_BITER_ELINKNO_BITER_SHIFT)) & DMA5_BITER_ELINKNO_BITER_MASK)

#define DMA5_BITER_ELINKNO_ELINK_MASK            (0x8000U)
#define DMA5_BITER_ELINKNO_ELINK_SHIFT           (15U)
/*! ELINK - Enables Channel-to-Channel Linking on Minor Loop Complete
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_BITER_ELINKNO_ELINK(x)              (((uint16_t)(((uint16_t)(x)) << DMA5_BITER_ELINKNO_ELINK_SHIFT)) & DMA5_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA5_BITER_ELINKNO */
#define DMA5_BITER_ELINKNO_COUNT                 (16U)

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) */
/*! @{ */

#define DMA5_BITER_ELINKYES_BITER_MASK           (0x1FFU)
#define DMA5_BITER_ELINKYES_BITER_SHIFT          (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA5_BITER_ELINKYES_BITER(x)             (((uint16_t)(((uint16_t)(x)) << DMA5_BITER_ELINKYES_BITER_SHIFT)) & DMA5_BITER_ELINKYES_BITER_MASK)

#define DMA5_BITER_ELINKYES_LINKCH_MASK          (0x1E00U)
#define DMA5_BITER_ELINKYES_LINKCH_SHIFT         (9U)
/*! LINKCH - Link Channel Number */
#define DMA5_BITER_ELINKYES_LINKCH(x)            (((uint16_t)(((uint16_t)(x)) << DMA5_BITER_ELINKYES_LINKCH_SHIFT)) & DMA5_BITER_ELINKYES_LINKCH_MASK)

#define DMA5_BITER_ELINKYES_ELINK_MASK           (0x8000U)
#define DMA5_BITER_ELINKYES_ELINK_SHIFT          (15U)
/*! ELINK - Enables Channel-to-Channel Linking on Minor Loop Complete
 *  0b0..Disable
 *  0b1..Enable
 */
#define DMA5_BITER_ELINKYES_ELINK(x)             (((uint16_t)(((uint16_t)(x)) << DMA5_BITER_ELINKYES_ELINK_SHIFT)) & DMA5_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA5_BITER_ELINKYES */
#define DMA5_BITER_ELINKYES_COUNT                (16U)


/*!
 * @}
 */ /* end of group DMA5_Register_Masks */


/*!
 * @}
 */ /* end of group DMA5_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA5_H_ */

