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
**         CMSIS Peripheral Access Layer for DMA4_TCD
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
 * @file PERI_DMA4_TCD.h
 * @version 1.0
 * @date 2024-11-15
 * @brief CMSIS Peripheral Access Layer for DMA4_TCD
 *
 * CMSIS Peripheral Access Layer for DMA4_TCD
 */

#if !defined(PERI_DMA4_TCD_H_)
#define PERI_DMA4_TCD_H_                         /**< Symbol preventing repeated inclusion */

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
   -- DMA4_TCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA4_TCD_Peripheral_Access_Layer DMA4_TCD Peripheral Access Layer
 * @{
 */

/** DMA4_TCD - Size of Registers Arrays */
#define DMA4_TCD_TCD_COUNT                        64u

/** DMA4_TCD - Register Layout Typedef */
typedef struct {
  struct {                                         /* offset: 0x0, array step: 0x1000 */
    __IO uint32_t CH_CSR;                            /**< Channel Control and Status Register, array offset: 0x0, array step: 0x1000 */
    __IO uint32_t CH_ES;                             /**< Channel Error Status Register, array offset: 0x4, array step: 0x1000 */
    __IO uint32_t CH_INT;                            /**< Channel Interrupt Status Register, array offset: 0x8, array step: 0x1000 */
    __IO uint32_t CH_SBR;                            /**< Channel System Bus Register, array offset: 0xC, array step: 0x1000 */
    __IO uint32_t CH_PRI;                            /**< Channel Priority Register, array offset: 0x10, array step: 0x1000 */
    __IO uint32_t CH_MUX;                            /**< Channel Multiplexor Configuration, array offset: 0x14, array step: 0x1000 */
    __IO uint16_t CH_MATTR;                          /**< Memory Attributes Register, array offset: 0x18, array step: 0x1000 */
         uint8_t RESERVED_0[6];
    __IO uint32_t SADDR;                             /**< TCD Source Address Register, array offset: 0x20, array step: 0x1000 */
    __IO uint16_t SOFF;                              /**< TCD Signed Source Address Offset Register, array offset: 0x24, array step: 0x1000 */
    __IO uint16_t ATTR;                              /**< TCD Transfer Attributes Register, array offset: 0x26, array step: 0x1000 */
    union {                                          /* offset: 0x28, array step: 0x1000 */
      __IO uint32_t NBYTES_MLOFFNO;                    /**< TCD Transfer Size without Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
      __IO uint32_t NBYTES_MLOFFYES;                   /**< TCD Transfer Size with Minor Loop Offsets Register, array offset: 0x28, array step: 0x1000 */
    };
    __IO uint32_t SLAST_SDA;                         /**< TCD Last Source Address Adjustment / Store DADDR Address Register, array offset: 0x2C, array step: 0x1000 */
    __IO uint32_t DADDR;                             /**< TCD Destination Address Register, array offset: 0x30, array step: 0x1000 */
    __IO uint16_t DOFF;                              /**< TCD Signed Destination Address Offset Register, array offset: 0x34, array step: 0x1000 */
    union {                                          /* offset: 0x36, array step: 0x1000 */
      __IO uint16_t CITER_ELINKNO;                     /**< TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x36, array step: 0x1000 */
      __IO uint16_t CITER_ELINKYES;                    /**< TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x36, array step: 0x1000 */
    };
    __IO uint32_t DLAST_SGA;                         /**< TCD Last Destination Address Adjustment / Scatter Gather Address Register, array offset: 0x38, array step: 0x1000 */
    __IO uint16_t CSR;                               /**< TCD Control and Status Register, array offset: 0x3C, array step: 0x1000 */
    union {                                          /* offset: 0x3E, array step: 0x1000 */
      __IO uint16_t BITER_ELINKNO;                     /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register, array offset: 0x3E, array step: 0x1000 */
      __IO uint16_t BITER_ELINKYES;                    /**< TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register, array offset: 0x3E, array step: 0x1000 */
    };
         uint8_t RESERVED_1[4032];
  } TCD[DMA4_TCD_TCD_COUNT];
} DMA4_TCD_Type;

/* ----------------------------------------------------------------------------
   -- DMA4_TCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DMA4_TCD_Register_Masks DMA4_TCD Register Masks
 * @{
 */

/*! @name CH_CSR - Channel Control and Status Register */
/*! @{ */

#define DMA4_TCD_CH_CSR_ERQ_MASK                 (0x1U)
#define DMA4_TCD_CH_CSR_ERQ_SHIFT                (0U)
/*! ERQ - Enable DMA Request
 *  0b0..The DMA hardware request signal for the corresponding channel is disabled.
 *  0b1..The DMA hardware request signal for the corresponding channel is enabled.
 */
#define DMA4_TCD_CH_CSR_ERQ(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_ERQ_SHIFT)) & DMA4_TCD_CH_CSR_ERQ_MASK)

#define DMA4_TCD_CH_CSR_EARQ_MASK                (0x2U)
#define DMA4_TCD_CH_CSR_EARQ_SHIFT               (1U)
/*! EARQ - Enable Asynchronous DMA Request
 *  0b0..Disable asynchronous DMA request for the channel.
 *  0b1..Enable asynchronous DMA request for the channel.
 */
#define DMA4_TCD_CH_CSR_EARQ(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_EARQ_SHIFT)) & DMA4_TCD_CH_CSR_EARQ_MASK)

#define DMA4_TCD_CH_CSR_EEI_MASK                 (0x4U)
#define DMA4_TCD_CH_CSR_EEI_SHIFT                (2U)
/*! EEI - Enable Error Interrupt
 *  0b0..The error signal for corresponding channel does not generate an error interrupt
 *  0b1..The assertion of the error signal for corresponding channel generates an error interrupt request
 */
#define DMA4_TCD_CH_CSR_EEI(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_EEI_SHIFT)) & DMA4_TCD_CH_CSR_EEI_MASK)

#define DMA4_TCD_CH_CSR_SWAP_MASK                (0xF000U)
#define DMA4_TCD_CH_CSR_SWAP_SHIFT               (12U)
/*! SWAP - Swap size
 *  0b0000..disabled
 *  0b0001..read with 8-bit swap
 *  0b0010..read with 16-bit swap
 *  0b0011..read with 32-bit swap
 *  0b0100-0b1000..reserved
 *  0b1001..write with 8-bit swap
 *  0b1010..write with 16-bit swap
 *  0b1011..write with 32-bit swap
 *  0b1100-0b1111..reserved
 */
#define DMA4_TCD_CH_CSR_SWAP(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_SWAP_SHIFT)) & DMA4_TCD_CH_CSR_SWAP_MASK)

#define DMA4_TCD_CH_CSR_SIGNEXT_MASK             (0x3F0000U)
#define DMA4_TCD_CH_CSR_SIGNEXT_SHIFT            (16U)
/*! SIGNEXT - Sign Extension
 *  0b000000..disabled
 *  0b000001..A non-zero value specifying the sign extend bit position
 */
#define DMA4_TCD_CH_CSR_SIGNEXT(x)               (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_SIGNEXT_SHIFT)) & DMA4_TCD_CH_CSR_SIGNEXT_MASK)

#define DMA4_TCD_CH_CSR_DONE_MASK                (0x40000000U)
#define DMA4_TCD_CH_CSR_DONE_SHIFT               (30U)
/*! DONE - Channel Done */
#define DMA4_TCD_CH_CSR_DONE(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_DONE_SHIFT)) & DMA4_TCD_CH_CSR_DONE_MASK)

#define DMA4_TCD_CH_CSR_ACTIVE_MASK              (0x80000000U)
#define DMA4_TCD_CH_CSR_ACTIVE_SHIFT             (31U)
/*! ACTIVE - Channel Active */
#define DMA4_TCD_CH_CSR_ACTIVE(x)                (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_CSR_ACTIVE_SHIFT)) & DMA4_TCD_CH_CSR_ACTIVE_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_CSR */
#define DMA4_TCD_CH_CSR_COUNT                    (64U)

/*! @name CH_ES - Channel Error Status Register */
/*! @{ */

#define DMA4_TCD_CH_ES_DBE_MASK                  (0x1U)
#define DMA4_TCD_CH_ES_DBE_SHIFT                 (0U)
/*! DBE - Destination Bus Error
 *  0b0..No destination bus error
 *  0b1..The last recorded error was a bus error on a destination write
 */
#define DMA4_TCD_CH_ES_DBE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_DBE_SHIFT)) & DMA4_TCD_CH_ES_DBE_MASK)

#define DMA4_TCD_CH_ES_SBE_MASK                  (0x2U)
#define DMA4_TCD_CH_ES_SBE_SHIFT                 (1U)
/*! SBE - Source Bus Error
 *  0b0..No source bus error
 *  0b1..The last recorded error was a bus error on a source read
 */
#define DMA4_TCD_CH_ES_SBE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_SBE_SHIFT)) & DMA4_TCD_CH_ES_SBE_MASK)

#define DMA4_TCD_CH_ES_SGE_MASK                  (0x4U)
#define DMA4_TCD_CH_ES_SGE_SHIFT                 (2U)
/*! SGE - Scatter/Gather Configuration Error
 *  0b0..No scatter/gather configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DLASTSGA field. This field is
 *       checked at the beginning of a scatter/gather operation after major loop completion if TCDn_CSR[ESG] is
 *       enabled. TCDn_DLASTSGA is not on a 32 byte boundary.
 */
#define DMA4_TCD_CH_ES_SGE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_SGE_SHIFT)) & DMA4_TCD_CH_ES_SGE_MASK)

#define DMA4_TCD_CH_ES_NCE_MASK                  (0x8U)
#define DMA4_TCD_CH_ES_NCE_SHIFT                 (3U)
/*! NCE - NBYTES/CITER Configuration Error
 *  0b0..No NBYTES/CITER configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_NBYTES or TCDn_CITER fields.
 *       TCDn_NBYTES is not a multiple of TCDn_ATTR[SSIZE] and TCDn_ATTR[DSIZE], or TCDn_CITER[CITER] is equal to zero,
 *       or TCDn_CITER[ELINK] is not equal to TCDn_BITER[ELINK]
 */
#define DMA4_TCD_CH_ES_NCE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_NCE_SHIFT)) & DMA4_TCD_CH_ES_NCE_MASK)

#define DMA4_TCD_CH_ES_DOE_MASK                  (0x10U)
#define DMA4_TCD_CH_ES_DOE_SHIFT                 (4U)
/*! DOE - Destination Offset Error
 *  0b0..No destination offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DOFF field. TCDn_DOFF is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_TCD_CH_ES_DOE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_DOE_SHIFT)) & DMA4_TCD_CH_ES_DOE_MASK)

#define DMA4_TCD_CH_ES_DAE_MASK                  (0x20U)
#define DMA4_TCD_CH_ES_DAE_SHIFT                 (5U)
/*! DAE - Destination Address Error
 *  0b0..No destination address configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_DADDR field. TCDn_DADDR is inconsistent with TCDn_ATTR[DSIZE].
 */
#define DMA4_TCD_CH_ES_DAE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_DAE_SHIFT)) & DMA4_TCD_CH_ES_DAE_MASK)

#define DMA4_TCD_CH_ES_SOE_MASK                  (0x40U)
#define DMA4_TCD_CH_ES_SOE_SHIFT                 (6U)
/*! SOE - Source Offset Error
 *  0b0..No source offset configuration error
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SOFF field. TCDn_SOFF is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_TCD_CH_ES_SOE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_SOE_SHIFT)) & DMA4_TCD_CH_ES_SOE_MASK)

#define DMA4_TCD_CH_ES_SAE_MASK                  (0x80U)
#define DMA4_TCD_CH_ES_SAE_SHIFT                 (7U)
/*! SAE - Source Address Error
 *  0b0..No source address configuration error.
 *  0b1..The last recorded error was a configuration error detected in the TCDn_SADDR field. TCDn_SADDR is inconsistent with TCDn_ATTR[SSIZE].
 */
#define DMA4_TCD_CH_ES_SAE(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_SAE_SHIFT)) & DMA4_TCD_CH_ES_SAE_MASK)

#define DMA4_TCD_CH_ES_ERR_MASK                  (0x80000000U)
#define DMA4_TCD_CH_ES_ERR_SHIFT                 (31U)
/*! ERR - Error In Channel
 *  0b0..An error in this channel has not occurred
 *  0b1..An error in this channel has occurred
 */
#define DMA4_TCD_CH_ES_ERR(x)                    (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_ES_ERR_SHIFT)) & DMA4_TCD_CH_ES_ERR_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_ES */
#define DMA4_TCD_CH_ES_COUNT                     (64U)

/*! @name CH_INT - Channel Interrupt Status Register */
/*! @{ */

#define DMA4_TCD_CH_INT_INT_MASK                 (0x1U)
#define DMA4_TCD_CH_INT_INT_SHIFT                (0U)
/*! INT - Interrupt Request
 *  0b0..The interrupt request for corresponding channel is cleared
 *  0b1..The interrupt request for corresponding channel is active
 */
#define DMA4_TCD_CH_INT_INT(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_INT_INT_SHIFT)) & DMA4_TCD_CH_INT_INT_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_INT */
#define DMA4_TCD_CH_INT_COUNT                    (64U)

/*! @name CH_SBR - Channel System Bus Register */
/*! @{ */

#define DMA4_TCD_CH_SBR_MID_MASK                 (0xFU)
#define DMA4_TCD_CH_SBR_MID_SHIFT                (0U)
/*! MID - Master ID */
#define DMA4_TCD_CH_SBR_MID(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_MID_SHIFT)) & DMA4_TCD_CH_SBR_MID_MASK)

#define DMA4_TCD_CH_SBR_INSTR_MASK               (0x2000U)
#define DMA4_TCD_CH_SBR_INSTR_SHIFT              (13U)
/*! INSTR - Instruction/Data Access
 *  0b0..Data access for DMA transfers
 *  0b1..Instruction access for DMA transfers
 */
#define DMA4_TCD_CH_SBR_INSTR(x)                 (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_INSTR_SHIFT)) & DMA4_TCD_CH_SBR_INSTR_MASK)

#define DMA4_TCD_CH_SBR_SEC_MASK                 (0x4000U)
#define DMA4_TCD_CH_SBR_SEC_SHIFT                (14U)
/*! SEC - Security Level
 *  0b0..Nonsecure protection level for DMA transfers
 *  0b1..Secure protection level for DMA transfers
 */
#define DMA4_TCD_CH_SBR_SEC(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_SEC_SHIFT)) & DMA4_TCD_CH_SBR_SEC_MASK)

#define DMA4_TCD_CH_SBR_PAL_MASK                 (0x8000U)
#define DMA4_TCD_CH_SBR_PAL_SHIFT                (15U)
/*! PAL - Privileged Access Level
 *  0b0..User protection level for DMA transfers
 *  0b1..Privileged protection level for DMA transfers
 */
#define DMA4_TCD_CH_SBR_PAL(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_PAL_SHIFT)) & DMA4_TCD_CH_SBR_PAL_MASK)

#define DMA4_TCD_CH_SBR_EMI_MASK                 (0x10000U)
#define DMA4_TCD_CH_SBR_EMI_SHIFT                (16U)
/*! EMI - Enable Master ID replication
 *  0b0..Master ID replication is disabled
 *  0b1..Master ID replication is enabled
 */
#define DMA4_TCD_CH_SBR_EMI(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_EMI_SHIFT)) & DMA4_TCD_CH_SBR_EMI_MASK)

#define DMA4_TCD_CH_SBR_ATTR_MASK                (0x7E0000U)
#define DMA4_TCD_CH_SBR_ATTR_SHIFT               (17U)
/*! ATTR - Attribute Output */
#define DMA4_TCD_CH_SBR_ATTR(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_SBR_ATTR_SHIFT)) & DMA4_TCD_CH_SBR_ATTR_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_SBR */
#define DMA4_TCD_CH_SBR_COUNT                    (64U)

/*! @name CH_PRI - Channel Priority Register */
/*! @{ */

#define DMA4_TCD_CH_PRI_APL_MASK                 (0x7U)
#define DMA4_TCD_CH_PRI_APL_SHIFT                (0U)
/*! APL - Arbitration Priority Level */
#define DMA4_TCD_CH_PRI_APL(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_PRI_APL_SHIFT)) & DMA4_TCD_CH_PRI_APL_MASK)

#define DMA4_TCD_CH_PRI_DPA_MASK                 (0x40000000U)
#define DMA4_TCD_CH_PRI_DPA_SHIFT                (30U)
/*! DPA - Disable Preempt Ability.
 *  0b0..The channel can suspend a lower priority channel.
 *  0b1..The channel cannot suspend any other channel, regardless of channel priority.
 */
#define DMA4_TCD_CH_PRI_DPA(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_PRI_DPA_SHIFT)) & DMA4_TCD_CH_PRI_DPA_MASK)

#define DMA4_TCD_CH_PRI_ECP_MASK                 (0x80000000U)
#define DMA4_TCD_CH_PRI_ECP_SHIFT                (31U)
/*! ECP - Enable Channel Preemption.
 *  0b0..The channel cannot be suspended by a higher priority channel's service request.
 *  0b1..The channel can be temporarily suspended by the service request of a higher priority channel.
 */
#define DMA4_TCD_CH_PRI_ECP(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_PRI_ECP_SHIFT)) & DMA4_TCD_CH_PRI_ECP_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_PRI */
#define DMA4_TCD_CH_PRI_COUNT                    (64U)

/*! @name CH_MUX - Channel Multiplexor Configuration */
/*! @{ */

#define DMA4_TCD_CH_MUX_SRC_MASK                 (0x7FU)
#define DMA4_TCD_CH_MUX_SRC_SHIFT                (0U)
/*! SRC - Service Request Source */
#define DMA4_TCD_CH_MUX_SRC(x)                   (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_CH_MUX_SRC_SHIFT)) & DMA4_TCD_CH_MUX_SRC_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_MUX */
#define DMA4_TCD_CH_MUX_COUNT                    (64U)

/*! @name CH_MATTR - Memory Attributes Register */
/*! @{ */

#define DMA4_TCD_CH_MATTR_RCACHE_MASK            (0xFU)
#define DMA4_TCD_CH_MATTR_RCACHE_SHIFT           (0U)
/*! RCACHE - Read Cache Attributes */
#define DMA4_TCD_CH_MATTR_RCACHE(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CH_MATTR_RCACHE_SHIFT)) & DMA4_TCD_CH_MATTR_RCACHE_MASK)

#define DMA4_TCD_CH_MATTR_WCACHE_MASK            (0xF0U)
#define DMA4_TCD_CH_MATTR_WCACHE_SHIFT           (4U)
/*! WCACHE - Write Cache Attributes */
#define DMA4_TCD_CH_MATTR_WCACHE(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CH_MATTR_WCACHE_SHIFT)) & DMA4_TCD_CH_MATTR_WCACHE_MASK)
/*! @} */

/* The count of DMA4_TCD_CH_MATTR */
#define DMA4_TCD_CH_MATTR_COUNT                  (64U)

/*! @name SADDR - TCD Source Address Register */
/*! @{ */

#define DMA4_TCD_SADDR_SADDR_MASK                (0xFFFFFFFFU)
#define DMA4_TCD_SADDR_SADDR_SHIFT               (0U)
/*! SADDR - Source Address */
#define DMA4_TCD_SADDR_SADDR(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_SADDR_SADDR_SHIFT)) & DMA4_TCD_SADDR_SADDR_MASK)
/*! @} */

/* The count of DMA4_TCD_SADDR */
#define DMA4_TCD_SADDR_COUNT                     (64U)

/*! @name SOFF - TCD Signed Source Address Offset Register */
/*! @{ */

#define DMA4_TCD_SOFF_SOFF_MASK                  (0xFFFFU)
#define DMA4_TCD_SOFF_SOFF_SHIFT                 (0U)
/*! SOFF - Source address signed offset */
#define DMA4_TCD_SOFF_SOFF(x)                    (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_SOFF_SOFF_SHIFT)) & DMA4_TCD_SOFF_SOFF_MASK)
/*! @} */

/* The count of DMA4_TCD_SOFF */
#define DMA4_TCD_SOFF_COUNT                      (64U)

/*! @name ATTR - TCD Transfer Attributes Register */
/*! @{ */

#define DMA4_TCD_ATTR_DSIZE_MASK                 (0x7U)
#define DMA4_TCD_ATTR_DSIZE_SHIFT                (0U)
/*! DSIZE - Destination data transfer size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA4_TCD_ATTR_DSIZE(x)                   (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_ATTR_DSIZE_SHIFT)) & DMA4_TCD_ATTR_DSIZE_MASK)

#define DMA4_TCD_ATTR_DMOD_MASK                  (0xF8U)
#define DMA4_TCD_ATTR_DMOD_SHIFT                 (3U)
/*! DMOD - Destination address modulo */
#define DMA4_TCD_ATTR_DMOD(x)                    (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_ATTR_DMOD_SHIFT)) & DMA4_TCD_ATTR_DMOD_MASK)

#define DMA4_TCD_ATTR_SSIZE_MASK                 (0x700U)
#define DMA4_TCD_ATTR_SSIZE_SHIFT                (8U)
/*! SSIZE - Source data transfer size
 *  0b000..8-bit
 *  0b001..16-bit
 *  0b010..32-bit
 *  0b011..64-bit
 *  0b100..16-byte
 *  0b101..32-byte
 *  0b110..64-byte
 *  0b111..128-byte
 */
#define DMA4_TCD_ATTR_SSIZE(x)                   (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_ATTR_SSIZE_SHIFT)) & DMA4_TCD_ATTR_SSIZE_MASK)

#define DMA4_TCD_ATTR_SMOD_MASK                  (0xF800U)
#define DMA4_TCD_ATTR_SMOD_SHIFT                 (11U)
/*! SMOD - Source address modulo
 *  0b00000..Source address modulo feature is disabled
 *  0b00001..Source address modulo feature is enabled for any non-zero value [1-31]
 */
#define DMA4_TCD_ATTR_SMOD(x)                    (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_ATTR_SMOD_SHIFT)) & DMA4_TCD_ATTR_SMOD_MASK)
/*! @} */

/* The count of DMA4_TCD_ATTR */
#define DMA4_TCD_ATTR_COUNT                      (64U)

/*! @name NBYTES_MLOFFNO - TCD Transfer Size without Minor Loop Offsets Register */
/*! @{ */

#define DMA4_TCD_NBYTES_MLOFFNO_NBYTES_MASK      (0x3FFFFFFFU)
#define DMA4_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT     (0U)
/*! NBYTES - Number of Bytes to transfer per service request */
#define DMA4_TCD_NBYTES_MLOFFNO_NBYTES(x)        (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFNO_NBYTES_SHIFT)) & DMA4_TCD_NBYTES_MLOFFNO_NBYTES_MASK)

#define DMA4_TCD_NBYTES_MLOFFNO_DMLOE_MASK       (0x40000000U)
#define DMA4_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT      (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA4_TCD_NBYTES_MLOFFNO_DMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFNO_DMLOE_SHIFT)) & DMA4_TCD_NBYTES_MLOFFNO_DMLOE_MASK)

#define DMA4_TCD_NBYTES_MLOFFNO_SMLOE_MASK       (0x80000000U)
#define DMA4_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT      (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA4_TCD_NBYTES_MLOFFNO_SMLOE(x)         (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFNO_SMLOE_SHIFT)) & DMA4_TCD_NBYTES_MLOFFNO_SMLOE_MASK)
/*! @} */

/* The count of DMA4_TCD_NBYTES_MLOFFNO */
#define DMA4_TCD_NBYTES_MLOFFNO_COUNT            (64U)

/*! @name NBYTES_MLOFFYES - TCD Transfer Size with Minor Loop Offsets Register */
/*! @{ */

#define DMA4_TCD_NBYTES_MLOFFYES_NBYTES_MASK     (0x3FFU)
#define DMA4_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT    (0U)
/*! NBYTES - Number of Bytes to transfer per service request */
#define DMA4_TCD_NBYTES_MLOFFYES_NBYTES(x)       (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFYES_NBYTES_SHIFT)) & DMA4_TCD_NBYTES_MLOFFYES_NBYTES_MASK)

#define DMA4_TCD_NBYTES_MLOFFYES_MLOFF_MASK      (0x3FFFFC00U)
#define DMA4_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT     (10U)
/*! MLOFF - Minor Loop Offset */
#define DMA4_TCD_NBYTES_MLOFFYES_MLOFF(x)        (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFYES_MLOFF_SHIFT)) & DMA4_TCD_NBYTES_MLOFFYES_MLOFF_MASK)

#define DMA4_TCD_NBYTES_MLOFFYES_DMLOE_MASK      (0x40000000U)
#define DMA4_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT     (30U)
/*! DMLOE - Destination Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the DADDR
 *  0b1..The minor loop offset is applied to the DADDR
 */
#define DMA4_TCD_NBYTES_MLOFFYES_DMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFYES_DMLOE_SHIFT)) & DMA4_TCD_NBYTES_MLOFFYES_DMLOE_MASK)

#define DMA4_TCD_NBYTES_MLOFFYES_SMLOE_MASK      (0x80000000U)
#define DMA4_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT     (31U)
/*! SMLOE - Source Minor Loop Offset Enable
 *  0b0..The minor loop offset is not applied to the SADDR
 *  0b1..The minor loop offset is applied to the SADDR
 */
#define DMA4_TCD_NBYTES_MLOFFYES_SMLOE(x)        (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_NBYTES_MLOFFYES_SMLOE_SHIFT)) & DMA4_TCD_NBYTES_MLOFFYES_SMLOE_MASK)
/*! @} */

/* The count of DMA4_TCD_NBYTES_MLOFFYES */
#define DMA4_TCD_NBYTES_MLOFFYES_COUNT           (64U)

/*! @name SLAST_SDA - TCD Last Source Address Adjustment / Store DADDR Address Register */
/*! @{ */

#define DMA4_TCD_SLAST_SDA_SLAST_SDA_MASK        (0xFFFFFFFFU)
#define DMA4_TCD_SLAST_SDA_SLAST_SDA_SHIFT       (0U)
/*! SLAST_SDA - Last Source Address Adjustment / Store DADDR Address */
#define DMA4_TCD_SLAST_SDA_SLAST_SDA(x)          (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_SLAST_SDA_SLAST_SDA_SHIFT)) & DMA4_TCD_SLAST_SDA_SLAST_SDA_MASK)
/*! @} */

/* The count of DMA4_TCD_SLAST_SDA */
#define DMA4_TCD_SLAST_SDA_COUNT                 (64U)

/*! @name DADDR - TCD Destination Address Register */
/*! @{ */

#define DMA4_TCD_DADDR_DADDR_MASK                (0xFFFFFFFFU)
#define DMA4_TCD_DADDR_DADDR_SHIFT               (0U)
/*! DADDR - Destination Address */
#define DMA4_TCD_DADDR_DADDR(x)                  (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_DADDR_DADDR_SHIFT)) & DMA4_TCD_DADDR_DADDR_MASK)
/*! @} */

/* The count of DMA4_TCD_DADDR */
#define DMA4_TCD_DADDR_COUNT                     (64U)

/*! @name DOFF - TCD Signed Destination Address Offset Register */
/*! @{ */

#define DMA4_TCD_DOFF_DOFF_MASK                  (0xFFFFU)
#define DMA4_TCD_DOFF_DOFF_SHIFT                 (0U)
/*! DOFF - Destination Address Signed Offset */
#define DMA4_TCD_DOFF_DOFF(x)                    (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_DOFF_DOFF_SHIFT)) & DMA4_TCD_DOFF_DOFF_MASK)
/*! @} */

/* The count of DMA4_TCD_DOFF */
#define DMA4_TCD_DOFF_COUNT                      (64U)

/*! @name CITER_ELINKNO - TCD Current Major Loop Count (Minor Loop Channel Linking Disabled) Register */
/*! @{ */

#define DMA4_TCD_CITER_ELINKNO_CITER_MASK        (0x7FFFU)
#define DMA4_TCD_CITER_ELINKNO_CITER_SHIFT       (0U)
/*! CITER - Current Major Iteration Count */
#define DMA4_TCD_CITER_ELINKNO_CITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CITER_ELINKNO_CITER_SHIFT)) & DMA4_TCD_CITER_ELINKNO_CITER_MASK)

#define DMA4_TCD_CITER_ELINKNO_ELINK_MASK        (0x8000U)
#define DMA4_TCD_CITER_ELINKNO_ELINK_SHIFT       (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_TCD_CITER_ELINKNO_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CITER_ELINKNO_ELINK_SHIFT)) & DMA4_TCD_CITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA4_TCD_CITER_ELINKNO */
#define DMA4_TCD_CITER_ELINKNO_COUNT             (64U)

/*! @name CITER_ELINKYES - TCD Current Major Loop Count (Minor Loop Channel Linking Enabled) Register */
/*! @{ */

#define DMA4_TCD_CITER_ELINKYES_CITER_MASK       (0x1FFU)
#define DMA4_TCD_CITER_ELINKYES_CITER_SHIFT      (0U)
/*! CITER - Current Major Iteration Count */
#define DMA4_TCD_CITER_ELINKYES_CITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CITER_ELINKYES_CITER_SHIFT)) & DMA4_TCD_CITER_ELINKYES_CITER_MASK)

#define DMA4_TCD_CITER_ELINKYES_LINKCH_MASK      (0x7E00U)
#define DMA4_TCD_CITER_ELINKYES_LINKCH_SHIFT     (9U)
/*! LINKCH - Minor Loop Link Channel Number */
#define DMA4_TCD_CITER_ELINKYES_LINKCH(x)        (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CITER_ELINKYES_LINKCH_SHIFT)) & DMA4_TCD_CITER_ELINKYES_LINKCH_MASK)

#define DMA4_TCD_CITER_ELINKYES_ELINK_MASK       (0x8000U)
#define DMA4_TCD_CITER_ELINKYES_ELINK_SHIFT      (15U)
/*! ELINK - Enable channel-to-channel linking on minor-loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_TCD_CITER_ELINKYES_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CITER_ELINKYES_ELINK_SHIFT)) & DMA4_TCD_CITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA4_TCD_CITER_ELINKYES */
#define DMA4_TCD_CITER_ELINKYES_COUNT            (64U)

/*! @name DLAST_SGA - TCD Last Destination Address Adjustment / Scatter Gather Address Register */
/*! @{ */

#define DMA4_TCD_DLAST_SGA_DLAST_SGA_MASK        (0xFFFFFFFFU)
#define DMA4_TCD_DLAST_SGA_DLAST_SGA_SHIFT       (0U)
/*! DLAST_SGA - Final Destination Address Adjustment / Scatter Gather Address */
#define DMA4_TCD_DLAST_SGA_DLAST_SGA(x)          (((uint32_t)(((uint32_t)(x)) << DMA4_TCD_DLAST_SGA_DLAST_SGA_SHIFT)) & DMA4_TCD_DLAST_SGA_DLAST_SGA_MASK)
/*! @} */

/* The count of DMA4_TCD_DLAST_SGA */
#define DMA4_TCD_DLAST_SGA_COUNT                 (64U)

/*! @name CSR - TCD Control and Status Register */
/*! @{ */

#define DMA4_TCD_CSR_START_MASK                  (0x1U)
#define DMA4_TCD_CSR_START_SHIFT                 (0U)
/*! START - Channel Start
 *  0b0..The channel is not explicitly started.
 *  0b1..The channel is explicitly started via a software initiated service request.
 */
#define DMA4_TCD_CSR_START(x)                    (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_START_SHIFT)) & DMA4_TCD_CSR_START_MASK)

#define DMA4_TCD_CSR_INTMAJOR_MASK               (0x2U)
#define DMA4_TCD_CSR_INTMAJOR_SHIFT              (1U)
/*! INTMAJOR - Enable an interrupt when major iteration count completes.
 *  0b0..The end-of-major loop interrupt is disabled.
 *  0b1..The end-of-major loop interrupt is enabled.
 */
#define DMA4_TCD_CSR_INTMAJOR(x)                 (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_INTMAJOR_SHIFT)) & DMA4_TCD_CSR_INTMAJOR_MASK)

#define DMA4_TCD_CSR_INTHALF_MASK                (0x4U)
#define DMA4_TCD_CSR_INTHALF_SHIFT               (2U)
/*! INTHALF - Enable an interrupt when major counter is half complete.
 *  0b0..The half-point interrupt is disabled.
 *  0b1..The half-point interrupt is enabled.
 */
#define DMA4_TCD_CSR_INTHALF(x)                  (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_INTHALF_SHIFT)) & DMA4_TCD_CSR_INTHALF_MASK)

#define DMA4_TCD_CSR_DREQ_MASK                   (0x8U)
#define DMA4_TCD_CSR_DREQ_SHIFT                  (3U)
/*! DREQ - Disable request
 *  0b0..No operation
 *  0b1..Clear the ERQ bit upon major loop completion, thus disabling hardware service requests.
 */
#define DMA4_TCD_CSR_DREQ(x)                     (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_DREQ_SHIFT)) & DMA4_TCD_CSR_DREQ_MASK)

#define DMA4_TCD_CSR_ESG_MASK                    (0x10U)
#define DMA4_TCD_CSR_ESG_SHIFT                   (4U)
/*! ESG - Enable Scatter/Gather processing
 *  0b0..The current channel's TCD is normal format.
 *  0b1..The current channel's TCD specifies a scatter gather format. The DLASTSGA field provides a memory pointer
 *       to the next TCD to be loaded into this channel after the major loop completes its execution.
 */
#define DMA4_TCD_CSR_ESG(x)                      (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_ESG_SHIFT)) & DMA4_TCD_CSR_ESG_MASK)

#define DMA4_TCD_CSR_MAJORELINK_MASK             (0x20U)
#define DMA4_TCD_CSR_MAJORELINK_SHIFT            (5U)
/*! MAJORELINK - Enable channel-to-channel linking on major loop complete
 *  0b0..The channel-to-channel linking is disabled.
 *  0b1..The channel-to-channel linking is enabled.
 */
#define DMA4_TCD_CSR_MAJORELINK(x)               (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_MAJORELINK_SHIFT)) & DMA4_TCD_CSR_MAJORELINK_MASK)

#define DMA4_TCD_CSR_EEOP_MASK                   (0x40U)
#define DMA4_TCD_CSR_EEOP_SHIFT                  (6U)
/*! EEOP - Enable end-of-packet processing
 *  0b0..The end-of-packet operation is disabled.
 *  0b1..The end-of-packet hardware input signal is enabled.
 */
#define DMA4_TCD_CSR_EEOP(x)                     (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_EEOP_SHIFT)) & DMA4_TCD_CSR_EEOP_MASK)

#define DMA4_TCD_CSR_ESDA_MASK                   (0x80U)
#define DMA4_TCD_CSR_ESDA_SHIFT                  (7U)
/*! ESDA - Enable store destination address
 *  0b0..The store destination address to system memory operation is disabled.
 *  0b1..The store destination address to system memory operation is enabled.
 */
#define DMA4_TCD_CSR_ESDA(x)                     (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_ESDA_SHIFT)) & DMA4_TCD_CSR_ESDA_MASK)

#define DMA4_TCD_CSR_MAJORLINKCH_MASK            (0x3F00U)
#define DMA4_TCD_CSR_MAJORLINKCH_SHIFT           (8U)
/*! MAJORLINKCH - Major loop link channel number */
#define DMA4_TCD_CSR_MAJORLINKCH(x)              (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_MAJORLINKCH_SHIFT)) & DMA4_TCD_CSR_MAJORLINKCH_MASK)

#define DMA4_TCD_CSR_TMC_MASK                    (0xC000U)
#define DMA4_TCD_CSR_TMC_SHIFT                   (14U)
/*! TMC - Transfer Mode Control
 *  0b00..Read/Write
 *  0b01..Read Only
 *  0b10..Write Only
 *  0b11..Reserved
 */
#define DMA4_TCD_CSR_TMC(x)                      (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_CSR_TMC_SHIFT)) & DMA4_TCD_CSR_TMC_MASK)
/*! @} */

/* The count of DMA4_TCD_CSR */
#define DMA4_TCD_CSR_COUNT                       (64U)

/*! @name BITER_ELINKNO - TCD Beginning Major Loop Count (Minor Loop Channel Linking Disabled) Register */
/*! @{ */

#define DMA4_TCD_BITER_ELINKNO_BITER_MASK        (0x7FFFU)
#define DMA4_TCD_BITER_ELINKNO_BITER_SHIFT       (0U)
/*! BITER - Starting Major Iteration Count */
#define DMA4_TCD_BITER_ELINKNO_BITER(x)          (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_BITER_ELINKNO_BITER_SHIFT)) & DMA4_TCD_BITER_ELINKNO_BITER_MASK)

#define DMA4_TCD_BITER_ELINKNO_ELINK_MASK        (0x8000U)
#define DMA4_TCD_BITER_ELINKNO_ELINK_SHIFT       (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_TCD_BITER_ELINKNO_ELINK(x)          (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_BITER_ELINKNO_ELINK_SHIFT)) & DMA4_TCD_BITER_ELINKNO_ELINK_MASK)
/*! @} */

/* The count of DMA4_TCD_BITER_ELINKNO */
#define DMA4_TCD_BITER_ELINKNO_COUNT             (64U)

/*! @name BITER_ELINKYES - TCD Beginning Major Loop Count (Minor Loop Channel Linking Enabled) Register */
/*! @{ */

#define DMA4_TCD_BITER_ELINKYES_BITER_MASK       (0x1FFU)
#define DMA4_TCD_BITER_ELINKYES_BITER_SHIFT      (0U)
/*! BITER - Starting major iteration count */
#define DMA4_TCD_BITER_ELINKYES_BITER(x)         (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_BITER_ELINKYES_BITER_SHIFT)) & DMA4_TCD_BITER_ELINKYES_BITER_MASK)

#define DMA4_TCD_BITER_ELINKYES_LINKCH_MASK      (0x7E00U)
#define DMA4_TCD_BITER_ELINKYES_LINKCH_SHIFT     (9U)
/*! LINKCH - Link Channel Number */
#define DMA4_TCD_BITER_ELINKYES_LINKCH(x)        (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_BITER_ELINKYES_LINKCH_SHIFT)) & DMA4_TCD_BITER_ELINKYES_LINKCH_MASK)

#define DMA4_TCD_BITER_ELINKYES_ELINK_MASK       (0x8000U)
#define DMA4_TCD_BITER_ELINKYES_ELINK_SHIFT      (15U)
/*! ELINK - Enables channel-to-channel linking on minor loop complete
 *  0b0..The channel-to-channel linking is disabled
 *  0b1..The channel-to-channel linking is enabled
 */
#define DMA4_TCD_BITER_ELINKYES_ELINK(x)         (((uint16_t)(((uint16_t)(x)) << DMA4_TCD_BITER_ELINKYES_ELINK_SHIFT)) & DMA4_TCD_BITER_ELINKYES_ELINK_MASK)
/*! @} */

/* The count of DMA4_TCD_BITER_ELINKYES */
#define DMA4_TCD_BITER_ELINKYES_COUNT            (64U)


/*!
 * @}
 */ /* end of group DMA4_TCD_Register_Masks */


/*!
 * @}
 */ /* end of group DMA4_TCD_Peripheral_Access_Layer */


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


#endif  /* PERI_DMA4_TCD_H_ */
