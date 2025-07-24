/*
** ###################################################################
**     Processors:          MIMX8ML2CVNKZ_ca53
**                          MIMX8ML2CVNKZ_cm7
**                          MIMX8ML2CVNKZ_dsp
**                          MIMX8ML2DVNLZ_ca53
**                          MIMX8ML2DVNLZ_cm7
**                          MIMX8ML2DVNLZ_dsp
**                          MIMX8ML3CVNKZ_ca53
**                          MIMX8ML3CVNKZ_cm7
**                          MIMX8ML3CVNKZ_dsp
**                          MIMX8ML3DVNLZ_ca53
**                          MIMX8ML3DVNLZ_cm7
**                          MIMX8ML3DVNLZ_dsp
**                          MIMX8ML4CVNKZ_ca53
**                          MIMX8ML4CVNKZ_cm7
**                          MIMX8ML4DVNLZ_ca53
**                          MIMX8ML4DVNLZ_cm7
**                          MIMX8ML5CVNKZ_ca53
**                          MIMX8ML5CVNKZ_cm7
**                          MIMX8ML5CVNKZ_dsp
**                          MIMX8ML5DVNLZ_ca53
**                          MIMX8ML5DVNLZ_cm7
**                          MIMX8ML5DVNLZ_dsp
**                          MIMX8ML6CVNKZ_ca53
**                          MIMX8ML6CVNKZ_cm7
**                          MIMX8ML6DVNLZ_ca53
**                          MIMX8ML6DVNLZ_cm7
**                          MIMX8ML8CVNKZ_ca53
**                          MIMX8ML8CVNKZ_cm7
**                          MIMX8ML8CVNKZ_dsp
**                          MIMX8ML8DVNLZ_ca53
**                          MIMX8ML8DVNLZ_cm7
**                          MIMX8ML8DVNLZ_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for INTERRUPT
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-10-11)
**         Initial version.
**     - rev. 2.0 (2020-02-21)
**         Rev.B Header.
**     - rev. 3.0 (2020-06-22)
**         Rev.C Header.
**     - rev. 4.0 (2020-11-16)
**         Rev.D Header.
**     - rev. 5.0 (2021-03-01)
**         Rev.D Header Final.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_INTERRUPT.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for INTERRUPT
 *
 * CMSIS Peripheral Access Layer for INTERRUPT
 */

#if !defined(PERI_INTERRUPT_H_)
#define PERI_INTERRUPT_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8ML2CVNKZ_ca53) || defined(CPU_MIMX8ML2DVNLZ_ca53))
#include "MIMX8ML2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_cm7) || defined(CPU_MIMX8ML2DVNLZ_cm7))
#include "MIMX8ML2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML2CVNKZ_dsp) || defined(CPU_MIMX8ML2DVNLZ_dsp))
#include "MIMX8ML2_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_ca53) || defined(CPU_MIMX8ML3DVNLZ_ca53))
#include "MIMX8ML3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_cm7) || defined(CPU_MIMX8ML3DVNLZ_cm7))
#include "MIMX8ML3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML3CVNKZ_dsp) || defined(CPU_MIMX8ML3DVNLZ_dsp))
#include "MIMX8ML3_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_ca53) || defined(CPU_MIMX8ML4DVNLZ_ca53))
#include "MIMX8ML4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML4CVNKZ_cm7) || defined(CPU_MIMX8ML4DVNLZ_cm7))
#include "MIMX8ML4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_ca53) || defined(CPU_MIMX8ML5DVNLZ_ca53))
#include "MIMX8ML5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_cm7) || defined(CPU_MIMX8ML5DVNLZ_cm7))
#include "MIMX8ML5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML5CVNKZ_dsp) || defined(CPU_MIMX8ML5DVNLZ_dsp))
#include "MIMX8ML5_dsp_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_ca53) || defined(CPU_MIMX8ML6DVNLZ_ca53))
#include "MIMX8ML6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML6CVNKZ_cm7) || defined(CPU_MIMX8ML6DVNLZ_cm7))
#include "MIMX8ML6_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_ca53) || defined(CPU_MIMX8ML8DVNLZ_ca53))
#include "MIMX8ML8_ca53_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_cm7) || defined(CPU_MIMX8ML8DVNLZ_cm7))
#include "MIMX8ML8_cm7_COMMON.h"
#elif (defined(CPU_MIMX8ML8CVNKZ_dsp) || defined(CPU_MIMX8ML8DVNLZ_dsp))
#include "MIMX8ML8_dsp_COMMON.h"
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
   -- INTERRUPT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTERRUPT_Peripheral_Access_Layer INTERRUPT Peripheral Access Layer
 * @{
 */

/** INTERRUPT - Register Layout Typedef */
typedef struct {
  __IO uint8_t IH_FC_STAT0;                        /**< Frame Composer Interrupt Status Register 0 (Packet Interrupts), offset: 0x0 */
  __IO uint8_t IH_FC_STAT1;                        /**< Frame Composer Interrupt Status Register 1 (Packet Interrupts), offset: 0x1 */
  __IO uint8_t IH_FC_STAT2;                        /**< Frame Composer Interrupt Status Register 2 (Packet Interrupts), offset: 0x2 */
  __IO uint8_t IH_AS_STAT0;                        /**< Audio Sampler Interrupt Status Register (FIFO Threshold, Underflow and Overflow Interrupts), offset: 0x3 */
  __IO uint8_t IH_PHY_STAT0;                       /**< PHY Interface Interrupt Status Register (RXSENSE, PLL Lock and HPD Interrupts), offset: 0x4 */
  __IO uint8_t IH_I2CM_STAT0;                      /**< E-DDC I2C Master Interrupt Status Register (Done and Error Interrupts), offset: 0x5 */
  __IO uint8_t IH_CEC_STAT0;                       /**< CEC Interrupt Status Register (Functional Operation Interrupts), offset: 0x6 */
  __IO uint8_t IH_VP_STAT0;                        /**< Video Packetizer Interrupt Status Register (FIFO Full and Empty Interrupts), offset: 0x7 */
  __IO uint8_t IH_I2CMPHY_STAT0;                   /**< PHY GEN2 I2C Master Interrupt Status Register (Done and Error Interrupts), offset: 0x8 */
       uint8_t RESERVED_0[103];
  __I  uint8_t IH_DECODE;                          /**< Interruption Handler Decode Assist Register, offset: 0x70 */
       uint8_t RESERVED_1[15];
  __IO uint8_t IH_MUTE_FC_STAT0;                   /**< Frame Composer Interrupt Mute Control Register 0, offset: 0x80 */
  __IO uint8_t IH_MUTE_FC_STAT1;                   /**< Frame Composer Interrupt Mute Control Register 1, offset: 0x81 */
  __IO uint8_t IH_MUTE_FC_STAT2;                   /**< Frame Composer Interrupt Mute Control Register 2, offset: 0x82 */
  __IO uint8_t IH_MUTE_AS_STAT0;                   /**< Audio Sampler Interrupt Mute Control Register, offset: 0x83 */
  __IO uint8_t IH_MUTE_PHY_STAT0;                  /**< PHY Interface Interrupt Mute Control Register, offset: 0x84 */
  __IO uint8_t IH_MUTE_I2CM_STAT0;                 /**< E-DDC I2C Master Interrupt Mute Control Register, offset: 0x85 */
  __IO uint8_t IH_MUTE_CEC_STAT0;                  /**< CEC Interrupt Mute Control Register, offset: 0x86 */
  __IO uint8_t IH_MUTE_VP_STAT0;                   /**< Video Packetizer Interrupt Mute Control Register, offset: 0x87 */
  __IO uint8_t IH_MUTE_I2CMPHY_STAT0;              /**< PHY GEN2 I2C Master Interrupt Mute Control Register, offset: 0x88 */
       uint8_t RESERVED_2[118];
  __IO uint8_t IH_MUTE;                            /**< Global Interrupt Mute Control Register, offset: 0xFF */
} INTERRUPT_Type;

/* ----------------------------------------------------------------------------
   -- INTERRUPT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup INTERRUPT_Register_Masks INTERRUPT Register Masks
 * @{
 */

/*! @name IH_FC_STAT0 - Frame Composer Interrupt Status Register 0 (Packet Interrupts) */
/*! @{ */

#define INTERRUPT_IH_FC_STAT0_NULL_MASK          (0x1U)
#define INTERRUPT_IH_FC_STAT0_NULL_SHIFT         (0U)
/*! NULL - Active after successful transmission of an Null packet. */
#define INTERRUPT_IH_FC_STAT0_NULL(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_NULL_SHIFT)) & INTERRUPT_IH_FC_STAT0_NULL_MASK)

#define INTERRUPT_IH_FC_STAT0_ACR_MASK           (0x2U)
#define INTERRUPT_IH_FC_STAT0_ACR_SHIFT          (1U)
/*! ACR - Active after successful transmission of an Audio Clock Regeneration (N/CTS transmission) packet. */
#define INTERRUPT_IH_FC_STAT0_ACR(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_ACR_SHIFT)) & INTERRUPT_IH_FC_STAT0_ACR_MASK)

#define INTERRUPT_IH_FC_STAT0_AUDS_MASK          (0x4U)
#define INTERRUPT_IH_FC_STAT0_AUDS_SHIFT         (2U)
/*! AUDS - Active after successful transmission of an Audio Sample packet. */
#define INTERRUPT_IH_FC_STAT0_AUDS(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_AUDS_SHIFT)) & INTERRUPT_IH_FC_STAT0_AUDS_MASK)

#define INTERRUPT_IH_FC_STAT0_NVBI_MASK          (0x8U)
#define INTERRUPT_IH_FC_STAT0_NVBI_SHIFT         (3U)
/*! NVBI - Active after successful transmission of an NTSC VBI packet */
#define INTERRUPT_IH_FC_STAT0_NVBI(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_NVBI_SHIFT)) & INTERRUPT_IH_FC_STAT0_NVBI_MASK)

#define INTERRUPT_IH_FC_STAT0_MAS_MASK           (0x10U)
#define INTERRUPT_IH_FC_STAT0_MAS_SHIFT          (4U)
/*! MAS - Active after successful transmission of an MultiStream Audio packet */
#define INTERRUPT_IH_FC_STAT0_MAS(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_MAS_SHIFT)) & INTERRUPT_IH_FC_STAT0_MAS_MASK)

#define INTERRUPT_IH_FC_STAT0_HBR_MASK           (0x20U)
#define INTERRUPT_IH_FC_STAT0_HBR_SHIFT          (5U)
/*! HBR - Active after successful transmission of an Audio HBR packet. */
#define INTERRUPT_IH_FC_STAT0_HBR(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_HBR_SHIFT)) & INTERRUPT_IH_FC_STAT0_HBR_MASK)

#define INTERRUPT_IH_FC_STAT0_ACP_MASK           (0x40U)
#define INTERRUPT_IH_FC_STAT0_ACP_SHIFT          (6U)
/*! ACP - Active after successful transmission of an Audio Content Protection packet. */
#define INTERRUPT_IH_FC_STAT0_ACP(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_ACP_SHIFT)) & INTERRUPT_IH_FC_STAT0_ACP_MASK)

#define INTERRUPT_IH_FC_STAT0_AUDI_MASK          (0x80U)
#define INTERRUPT_IH_FC_STAT0_AUDI_SHIFT         (7U)
/*! AUDI - Active after successful transmission of an Audio InfoFrame packet. */
#define INTERRUPT_IH_FC_STAT0_AUDI(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT0_AUDI_SHIFT)) & INTERRUPT_IH_FC_STAT0_AUDI_MASK)
/*! @} */

/*! @name IH_FC_STAT1 - Frame Composer Interrupt Status Register 1 (Packet Interrupts) */
/*! @{ */

#define INTERRUPT_IH_FC_STAT1_GCP_MASK           (0x1U)
#define INTERRUPT_IH_FC_STAT1_GCP_SHIFT          (0U)
/*! GCP - Active after successful transmission of an General Control Packet. */
#define INTERRUPT_IH_FC_STAT1_GCP(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_GCP_SHIFT)) & INTERRUPT_IH_FC_STAT1_GCP_MASK)

#define INTERRUPT_IH_FC_STAT1_AVI_MASK           (0x2U)
#define INTERRUPT_IH_FC_STAT1_AVI_SHIFT          (1U)
/*! AVI - Active after successful transmission of an AVI InfoFrame packet. */
#define INTERRUPT_IH_FC_STAT1_AVI(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_AVI_SHIFT)) & INTERRUPT_IH_FC_STAT1_AVI_MASK)

#define INTERRUPT_IH_FC_STAT1_AMP_MASK           (0x4U)
#define INTERRUPT_IH_FC_STAT1_AMP_SHIFT          (2U)
/*! AMP - Active after successful transmission of an Audio Metadata packet */
#define INTERRUPT_IH_FC_STAT1_AMP(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_AMP_SHIFT)) & INTERRUPT_IH_FC_STAT1_AMP_MASK)

#define INTERRUPT_IH_FC_STAT1_SPD_MASK           (0x8U)
#define INTERRUPT_IH_FC_STAT1_SPD_SHIFT          (3U)
/*! SPD - Active after successful transmission of an Source Product Descriptor InfoFrame packet. */
#define INTERRUPT_IH_FC_STAT1_SPD(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_SPD_SHIFT)) & INTERRUPT_IH_FC_STAT1_SPD_MASK)

#define INTERRUPT_IH_FC_STAT1_VSD_MASK           (0x10U)
#define INTERRUPT_IH_FC_STAT1_VSD_SHIFT          (4U)
/*! VSD - Active after successful transmission of an Vendor Specific Data InfoFrame packet. */
#define INTERRUPT_IH_FC_STAT1_VSD(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_VSD_SHIFT)) & INTERRUPT_IH_FC_STAT1_VSD_MASK)

#define INTERRUPT_IH_FC_STAT1_ISCR2_MASK         (0x20U)
#define INTERRUPT_IH_FC_STAT1_ISCR2_SHIFT        (5U)
/*! ISCR2 - Active after successful transmission of an International Standard Recording Code 2 packet */
#define INTERRUPT_IH_FC_STAT1_ISCR2(x)           (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_ISCR2_SHIFT)) & INTERRUPT_IH_FC_STAT1_ISCR2_MASK)

#define INTERRUPT_IH_FC_STAT1_ISCR1_MASK         (0x40U)
#define INTERRUPT_IH_FC_STAT1_ISCR1_SHIFT        (6U)
/*! ISCR1 - Active after successful transmission of an International Standard Recording Code 1 packet. */
#define INTERRUPT_IH_FC_STAT1_ISCR1(x)           (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_ISCR1_SHIFT)) & INTERRUPT_IH_FC_STAT1_ISCR1_MASK)

#define INTERRUPT_IH_FC_STAT1_GMD_MASK           (0x80U)
#define INTERRUPT_IH_FC_STAT1_GMD_SHIFT          (7U)
/*! GMD - Active after successful transmission of an Gamut metadata packet. */
#define INTERRUPT_IH_FC_STAT1_GMD(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT1_GMD_SHIFT)) & INTERRUPT_IH_FC_STAT1_GMD_MASK)
/*! @} */

/*! @name IH_FC_STAT2 - Frame Composer Interrupt Status Register 2 (Packet Interrupts) */
/*! @{ */

#define INTERRUPT_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW_MASK (0x1U)
#define INTERRUPT_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW_SHIFT (0U)
/*! HighPriority_overflow - Frame Composer high priority packet queue descriptor overflow indication */
#define INTERRUPT_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW_SHIFT)) & INTERRUPT_IH_FC_STAT2_HIGHPRIORITY_OVERFLOW_MASK)

#define INTERRUPT_IH_FC_STAT2_LOWPRIORITY_OVERFLOW_MASK (0x2U)
#define INTERRUPT_IH_FC_STAT2_LOWPRIORITY_OVERFLOW_SHIFT (1U)
/*! LowPriority_overflow - Frame Composer low priority packet queue descriptor overflow indication */
#define INTERRUPT_IH_FC_STAT2_LOWPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT2_LOWPRIORITY_OVERFLOW_SHIFT)) & INTERRUPT_IH_FC_STAT2_LOWPRIORITY_OVERFLOW_MASK)

#define INTERRUPT_IH_FC_STAT2_DRM_MASK           (0x10U)
#define INTERRUPT_IH_FC_STAT2_DRM_SHIFT          (4U)
/*! DRM - Active after successful transmission of an DRM packet */
#define INTERRUPT_IH_FC_STAT2_DRM(x)             (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_FC_STAT2_DRM_SHIFT)) & INTERRUPT_IH_FC_STAT2_DRM_MASK)
/*! @} */

/*! @name IH_AS_STAT0 - Audio Sampler Interrupt Status Register (FIFO Threshold, Underflow and Overflow Interrupts) */
/*! @{ */

#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_OVERFLOW_MASK (0x1U)
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_OVERFLOW_SHIFT (0U)
/*! Aud_fifo_overflow - Audio Sampler audio FIFO full indication. */
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_AS_STAT0_AUD_FIFO_OVERFLOW_SHIFT)) & INTERRUPT_IH_AS_STAT0_AUD_FIFO_OVERFLOW_MASK)

#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_MASK (0x2U)
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_SHIFT (1U)
/*! Aud_fifo_underflow - Audio Sampler audio FIFO empty indication. */
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_SHIFT)) & INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_MASK)

#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_MASK (0x4U)
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_SHIFT (2U)
/*! Aud_fifo_underflow_thr - Audio Sampler audio FIFO empty threshold (four samples) indication for the legacy HBR audio interface. */
#define INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_SHIFT)) & INTERRUPT_IH_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_MASK)

#define INTERRUPT_IH_AS_STAT0_FIFO_OVERRUN_MASK  (0x8U)
#define INTERRUPT_IH_AS_STAT0_FIFO_OVERRUN_SHIFT (3U)
/*! fifo_overrun - Indicates an overrun on the audio FIFO. */
#define INTERRUPT_IH_AS_STAT0_FIFO_OVERRUN(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_AS_STAT0_FIFO_OVERRUN_SHIFT)) & INTERRUPT_IH_AS_STAT0_FIFO_OVERRUN_MASK)
/*! @} */

/*! @name IH_PHY_STAT0 - PHY Interface Interrupt Status Register (RXSENSE, PLL Lock and HPD Interrupts) */
/*! @{ */

#define INTERRUPT_IH_PHY_STAT0_HPD_MASK          (0x1U)
#define INTERRUPT_IH_PHY_STAT0_HPD_SHIFT         (0U)
/*! HPD - HDMI Hot Plug Detect indication. */
#define INTERRUPT_IH_PHY_STAT0_HPD(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_HPD_SHIFT)) & INTERRUPT_IH_PHY_STAT0_HPD_MASK)

#define INTERRUPT_IH_PHY_STAT0_TX_PHY_LOCK_MASK  (0x2U)
#define INTERRUPT_IH_PHY_STAT0_TX_PHY_LOCK_SHIFT (1U)
/*! TX_PHY_LOCK - TX PHY PLL lock indication. */
#define INTERRUPT_IH_PHY_STAT0_TX_PHY_LOCK(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_TX_PHY_LOCK_SHIFT)) & INTERRUPT_IH_PHY_STAT0_TX_PHY_LOCK_MASK)

#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_0_MASK   (0x4U)
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_0_SHIFT  (2U)
/*! RX_SENSE_0 - TX PHY RX_SENSE indication for driver 0. */
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_0(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_RX_SENSE_0_SHIFT)) & INTERRUPT_IH_PHY_STAT0_RX_SENSE_0_MASK)

#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_1_MASK   (0x8U)
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_1_SHIFT  (3U)
/*! RX_SENSE_1 - TX PHY RX_SENSE indication for driver 1. */
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_1(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_RX_SENSE_1_SHIFT)) & INTERRUPT_IH_PHY_STAT0_RX_SENSE_1_MASK)

#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_2_MASK   (0x10U)
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_2_SHIFT  (4U)
/*! RX_SENSE_2 - TX PHY RX_SENSE indication for driver 2. */
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_2(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_RX_SENSE_2_SHIFT)) & INTERRUPT_IH_PHY_STAT0_RX_SENSE_2_MASK)

#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_3_MASK   (0x20U)
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_3_SHIFT  (5U)
/*! RX_SENSE_3 - TX PHY RX_SENSE indication for driver 3. */
#define INTERRUPT_IH_PHY_STAT0_RX_SENSE_3(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_PHY_STAT0_RX_SENSE_3_SHIFT)) & INTERRUPT_IH_PHY_STAT0_RX_SENSE_3_MASK)
/*! @} */

/*! @name IH_I2CM_STAT0 - E-DDC I2C Master Interrupt Status Register (Done and Error Interrupts) */
/*! @{ */

#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERERROR_MASK (0x1U)
#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERERROR_SHIFT (0U)
/*! I2Cmastererror - I2C Master error indication */
#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERERROR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_I2CM_STAT0_I2CMASTERERROR_SHIFT)) & INTERRUPT_IH_I2CM_STAT0_I2CMASTERERROR_MASK)

#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERDONE_MASK (0x2U)
#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERDONE_SHIFT (1U)
/*! I2Cmasterdone - I2C Master done indication */
#define INTERRUPT_IH_I2CM_STAT0_I2CMASTERDONE(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_I2CM_STAT0_I2CMASTERDONE_SHIFT)) & INTERRUPT_IH_I2CM_STAT0_I2CMASTERDONE_MASK)

#define INTERRUPT_IH_I2CM_STAT0_SCDC_READREQ_MASK (0x4U)
#define INTERRUPT_IH_I2CM_STAT0_SCDC_READREQ_SHIFT (2U)
/*! scdc_readreq - I2C Master SCDC read request indication. */
#define INTERRUPT_IH_I2CM_STAT0_SCDC_READREQ(x)  (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_I2CM_STAT0_SCDC_READREQ_SHIFT)) & INTERRUPT_IH_I2CM_STAT0_SCDC_READREQ_MASK)
/*! @} */

/*! @name IH_CEC_STAT0 - CEC Interrupt Status Register (Functional Operation Interrupts) */
/*! @{ */

#define INTERRUPT_IH_CEC_STAT0_DONE_MASK         (0x1U)
#define INTERRUPT_IH_CEC_STAT0_DONE_SHIFT        (0U)
/*! DONE - CEC Done Indication */
#define INTERRUPT_IH_CEC_STAT0_DONE(x)           (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_DONE_SHIFT)) & INTERRUPT_IH_CEC_STAT0_DONE_MASK)

#define INTERRUPT_IH_CEC_STAT0_EOM_MASK          (0x2U)
#define INTERRUPT_IH_CEC_STAT0_EOM_SHIFT         (1U)
/*! EOM - CEC End of Message Indication */
#define INTERRUPT_IH_CEC_STAT0_EOM(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_EOM_SHIFT)) & INTERRUPT_IH_CEC_STAT0_EOM_MASK)

#define INTERRUPT_IH_CEC_STAT0_NACK_MASK         (0x4U)
#define INTERRUPT_IH_CEC_STAT0_NACK_SHIFT        (2U)
/*! NACK - CEC Not Acknowledge indication */
#define INTERRUPT_IH_CEC_STAT0_NACK(x)           (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_NACK_SHIFT)) & INTERRUPT_IH_CEC_STAT0_NACK_MASK)

#define INTERRUPT_IH_CEC_STAT0_ARB_LOST_MASK     (0x8U)
#define INTERRUPT_IH_CEC_STAT0_ARB_LOST_SHIFT    (3U)
/*! ARB_LOST - CEC Arbitration Lost indication */
#define INTERRUPT_IH_CEC_STAT0_ARB_LOST(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_ARB_LOST_SHIFT)) & INTERRUPT_IH_CEC_STAT0_ARB_LOST_MASK)

#define INTERRUPT_IH_CEC_STAT0_ERROR_INITIATOR_MASK (0x10U)
#define INTERRUPT_IH_CEC_STAT0_ERROR_INITIATOR_SHIFT (4U)
/*! ERROR_INITIATOR - CEC Error Initiator indication */
#define INTERRUPT_IH_CEC_STAT0_ERROR_INITIATOR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_ERROR_INITIATOR_SHIFT)) & INTERRUPT_IH_CEC_STAT0_ERROR_INITIATOR_MASK)

#define INTERRUPT_IH_CEC_STAT0_ERROR_FOLLOW_MASK (0x20U)
#define INTERRUPT_IH_CEC_STAT0_ERROR_FOLLOW_SHIFT (5U)
/*! ERROR_FOLLOW - CEC Error Follow indication */
#define INTERRUPT_IH_CEC_STAT0_ERROR_FOLLOW(x)   (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_ERROR_FOLLOW_SHIFT)) & INTERRUPT_IH_CEC_STAT0_ERROR_FOLLOW_MASK)

#define INTERRUPT_IH_CEC_STAT0_WAKEUP_MASK       (0x40U)
#define INTERRUPT_IH_CEC_STAT0_WAKEUP_SHIFT      (6U)
/*! WAKEUP - CEC Wake-up indication */
#define INTERRUPT_IH_CEC_STAT0_WAKEUP(x)         (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_CEC_STAT0_WAKEUP_SHIFT)) & INTERRUPT_IH_CEC_STAT0_WAKEUP_MASK)
/*! @} */

/*! @name IH_VP_STAT0 - Video Packetizer Interrupt Status Register (FIFO Full and Empty Interrupts) */
/*! @{ */

#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREMAP_MASK (0x4U)
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREMAP_SHIFT (2U)
/*! fifoemptyremap - Video Packetizer pixel YCbCr 422 re-mapper FIFO empty interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREMAP(x)  (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOEMPTYREMAP_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOEMPTYREMAP_MASK)

#define INTERRUPT_IH_VP_STAT0_FIFOFULLREMAP_MASK (0x8U)
#define INTERRUPT_IH_VP_STAT0_FIFOFULLREMAP_SHIFT (3U)
/*! fifofullremap - Video Packetizer pixel YCbCr 422 re-mapper FIFO full interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOFULLREMAP(x)   (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOFULLREMAP_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOFULLREMAP_MASK)

#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYPP_MASK   (0x10U)
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYPP_SHIFT  (4U)
/*! fifoemptypp - Video Packetizer pixel packing FIFO empty interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYPP(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOEMPTYPP_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOEMPTYPP_MASK)

#define INTERRUPT_IH_VP_STAT0_FIFOFULLPP_MASK    (0x20U)
#define INTERRUPT_IH_VP_STAT0_FIFOFULLPP_SHIFT   (5U)
/*! fifofullpp - Video Packetizer pixel packing FIFO full interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOFULLPP(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOFULLPP_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOFULLPP_MASK)

#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREPET_MASK (0x40U)
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREPET_SHIFT (6U)
/*! fifoemptyrepet - Video Packetizer pixel repeater FIFO empty interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOEMPTYREPET(x)  (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOEMPTYREPET_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOEMPTYREPET_MASK)

#define INTERRUPT_IH_VP_STAT0_FIFOFULLREPET_MASK (0x80U)
#define INTERRUPT_IH_VP_STAT0_FIFOFULLREPET_SHIFT (7U)
/*! fifofullrepet - Video Packetizer pixel repeater FIFO full interrupt */
#define INTERRUPT_IH_VP_STAT0_FIFOFULLREPET(x)   (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_VP_STAT0_FIFOFULLREPET_SHIFT)) & INTERRUPT_IH_VP_STAT0_FIFOFULLREPET_MASK)
/*! @} */

/*! @name IH_I2CMPHY_STAT0 - PHY GEN2 I2C Master Interrupt Status Register (Done and Error Interrupts) */
/*! @{ */

#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYERROR_MASK (0x1U)
#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYERROR_SHIFT (0U)
/*! I2Cmphyerror - I2C Master PHY error indication */
#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYERROR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYERROR_SHIFT)) & INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYERROR_MASK)

#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYDONE_MASK (0x2U)
#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYDONE_SHIFT (1U)
/*! I2Cmphydone - I2C Master PHY done indication */
#define INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYDONE(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYDONE_SHIFT)) & INTERRUPT_IH_I2CMPHY_STAT0_I2CMPHYDONE_MASK)
/*! @} */

/*! @name IH_DECODE - Interruption Handler Decode Assist Register */
/*! @{ */

#define INTERRUPT_IH_DECODE_IH_AHBDMAAUD_STAT0_MASK (0x1U)
#define INTERRUPT_IH_DECODE_IH_AHBDMAAUD_STAT0_SHIFT (0U)
/*! ih_ahbdmaaud_stat0 - Interruption active at the ih_ahbdmaaud_stat0 register */
#define INTERRUPT_IH_DECODE_IH_AHBDMAAUD_STAT0(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_AHBDMAAUD_STAT0_SHIFT)) & INTERRUPT_IH_DECODE_IH_AHBDMAAUD_STAT0_MASK)

#define INTERRUPT_IH_DECODE_IH_CEC_STAT0_MASK    (0x2U)
#define INTERRUPT_IH_DECODE_IH_CEC_STAT0_SHIFT   (1U)
/*! ih_cec_stat0 - Interruption active at the ih_cec_stat0 register */
#define INTERRUPT_IH_DECODE_IH_CEC_STAT0(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_CEC_STAT0_SHIFT)) & INTERRUPT_IH_DECODE_IH_CEC_STAT0_MASK)

#define INTERRUPT_IH_DECODE_IH_I2CM_STAT0_MASK   (0x4U)
#define INTERRUPT_IH_DECODE_IH_I2CM_STAT0_SHIFT  (2U)
/*! ih_i2cm_stat0 - Interruption active at the ih_i2cm_stat0 register */
#define INTERRUPT_IH_DECODE_IH_I2CM_STAT0(x)     (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_I2CM_STAT0_SHIFT)) & INTERRUPT_IH_DECODE_IH_I2CM_STAT0_MASK)

#define INTERRUPT_IH_DECODE_IH_PHY_MASK          (0x8U)
#define INTERRUPT_IH_DECODE_IH_PHY_SHIFT         (3U)
/*! ih_phy - Interruption active at the ih_phy_stat0 or ih_i2cmphy_stat0 register */
#define INTERRUPT_IH_DECODE_IH_PHY(x)            (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_PHY_SHIFT)) & INTERRUPT_IH_DECODE_IH_PHY_MASK)

#define INTERRUPT_IH_DECODE_IH_AS_STAT0_MASK     (0x10U)
#define INTERRUPT_IH_DECODE_IH_AS_STAT0_SHIFT    (4U)
/*! ih_as_stat0 - Interruption active at the ih_as_stat0 register */
#define INTERRUPT_IH_DECODE_IH_AS_STAT0(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_AS_STAT0_SHIFT)) & INTERRUPT_IH_DECODE_IH_AS_STAT0_MASK)

#define INTERRUPT_IH_DECODE_IH_FC_STAT2_VP_MASK  (0x20U)
#define INTERRUPT_IH_DECODE_IH_FC_STAT2_VP_SHIFT (5U)
/*! ih_fc_stat2_vp - Interruption active at the ih_fc_stat2 or ih_vp_stat0 register */
#define INTERRUPT_IH_DECODE_IH_FC_STAT2_VP(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_FC_STAT2_VP_SHIFT)) & INTERRUPT_IH_DECODE_IH_FC_STAT2_VP_MASK)

#define INTERRUPT_IH_DECODE_IH_FC_STAT1_MASK     (0x40U)
#define INTERRUPT_IH_DECODE_IH_FC_STAT1_SHIFT    (6U)
/*! ih_fc_stat1 - Interruption active at the ih_fc_stat1 register */
#define INTERRUPT_IH_DECODE_IH_FC_STAT1(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_FC_STAT1_SHIFT)) & INTERRUPT_IH_DECODE_IH_FC_STAT1_MASK)

#define INTERRUPT_IH_DECODE_IH_FC_STAT0_MASK     (0x80U)
#define INTERRUPT_IH_DECODE_IH_FC_STAT0_SHIFT    (7U)
/*! ih_fc_stat0 - Interruption active at the ih_fc_stat0 register */
#define INTERRUPT_IH_DECODE_IH_FC_STAT0(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_DECODE_IH_FC_STAT0_SHIFT)) & INTERRUPT_IH_DECODE_IH_FC_STAT0_MASK)
/*! @} */

/*! @name IH_MUTE_FC_STAT0 - Frame Composer Interrupt Mute Control Register 0 */
/*! @{ */

#define INTERRUPT_IH_MUTE_FC_STAT0_NULL_MASK     (0x1U)
#define INTERRUPT_IH_MUTE_FC_STAT0_NULL_SHIFT    (0U)
/*! NULL - When set to 1, mutes ih_fc_stat0[0] */
#define INTERRUPT_IH_MUTE_FC_STAT0_NULL(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_NULL_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_NULL_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_ACR_MASK      (0x2U)
#define INTERRUPT_IH_MUTE_FC_STAT0_ACR_SHIFT     (1U)
/*! ACR - When set to 1, mutes ih_fc_stat0[1] */
#define INTERRUPT_IH_MUTE_FC_STAT0_ACR(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_ACR_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_ACR_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_AUDS_MASK     (0x4U)
#define INTERRUPT_IH_MUTE_FC_STAT0_AUDS_SHIFT    (2U)
/*! AUDS - When set to 1, mutes ih_fc_stat0[2] */
#define INTERRUPT_IH_MUTE_FC_STAT0_AUDS(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_AUDS_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_AUDS_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_NVBI_MASK     (0x8U)
#define INTERRUPT_IH_MUTE_FC_STAT0_NVBI_SHIFT    (3U)
/*! NVBI - When set to 1, mutes ih_fc_stat0[3]. */
#define INTERRUPT_IH_MUTE_FC_STAT0_NVBI(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_NVBI_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_NVBI_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_MAS_MASK      (0x10U)
#define INTERRUPT_IH_MUTE_FC_STAT0_MAS_SHIFT     (4U)
/*! MAS - When set to 1, mutes ih_fc_stat0[4]. */
#define INTERRUPT_IH_MUTE_FC_STAT0_MAS(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_MAS_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_MAS_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_HBR_MASK      (0x20U)
#define INTERRUPT_IH_MUTE_FC_STAT0_HBR_SHIFT     (5U)
/*! HBR - When set to 1, mutes ih_fc_stat0[5] */
#define INTERRUPT_IH_MUTE_FC_STAT0_HBR(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_HBR_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_HBR_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_ACP_MASK      (0x40U)
#define INTERRUPT_IH_MUTE_FC_STAT0_ACP_SHIFT     (6U)
/*! ACP - When set to 1, mutes ih_fc_stat0[6] */
#define INTERRUPT_IH_MUTE_FC_STAT0_ACP(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_ACP_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_ACP_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT0_AUDI_MASK     (0x80U)
#define INTERRUPT_IH_MUTE_FC_STAT0_AUDI_SHIFT    (7U)
/*! AUDI - When set to 1, mutes ih_fc_stat0[7] */
#define INTERRUPT_IH_MUTE_FC_STAT0_AUDI(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT0_AUDI_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT0_AUDI_MASK)
/*! @} */

/*! @name IH_MUTE_FC_STAT1 - Frame Composer Interrupt Mute Control Register 1 */
/*! @{ */

#define INTERRUPT_IH_MUTE_FC_STAT1_GCP_MASK      (0x1U)
#define INTERRUPT_IH_MUTE_FC_STAT1_GCP_SHIFT     (0U)
/*! GCP - When set to 1, mutes ih_fc_stat1[0] */
#define INTERRUPT_IH_MUTE_FC_STAT1_GCP(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_GCP_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_GCP_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_AVI_MASK      (0x2U)
#define INTERRUPT_IH_MUTE_FC_STAT1_AVI_SHIFT     (1U)
/*! AVI - When set to 1, mutes ih_fc_stat1[1] */
#define INTERRUPT_IH_MUTE_FC_STAT1_AVI(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_AVI_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_AVI_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_AMP_MASK      (0x4U)
#define INTERRUPT_IH_MUTE_FC_STAT1_AMP_SHIFT     (2U)
/*! AMP - When set to 1, mutes ih_fc_stat1[2]. */
#define INTERRUPT_IH_MUTE_FC_STAT1_AMP(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_AMP_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_AMP_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_SPD_MASK      (0x8U)
#define INTERRUPT_IH_MUTE_FC_STAT1_SPD_SHIFT     (3U)
/*! SPD - When set to 1, mutes ih_fc_stat1[3] */
#define INTERRUPT_IH_MUTE_FC_STAT1_SPD(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_SPD_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_SPD_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_VSD_MASK      (0x10U)
#define INTERRUPT_IH_MUTE_FC_STAT1_VSD_SHIFT     (4U)
/*! VSD - When set to 1, mutes ih_fc_stat1[4] */
#define INTERRUPT_IH_MUTE_FC_STAT1_VSD(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_VSD_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_VSD_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR2_MASK    (0x20U)
#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR2_SHIFT   (5U)
/*! ISCR2 - When set to 1, mutes ih_fc_stat1[5] */
#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR2(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_ISCR2_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_ISCR2_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR1_MASK    (0x40U)
#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR1_SHIFT   (6U)
/*! ISCR1 - When set to 1, mutes ih_fc_stat1[6] */
#define INTERRUPT_IH_MUTE_FC_STAT1_ISCR1(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_ISCR1_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_ISCR1_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT1_GMD_MASK      (0x80U)
#define INTERRUPT_IH_MUTE_FC_STAT1_GMD_SHIFT     (7U)
/*! GMD - When set to 1, mutes ih_fc_stat1[7] */
#define INTERRUPT_IH_MUTE_FC_STAT1_GMD(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT1_GMD_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT1_GMD_MASK)
/*! @} */

/*! @name IH_MUTE_FC_STAT2 - Frame Composer Interrupt Mute Control Register 2 */
/*! @{ */

#define INTERRUPT_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW_MASK (0x1U)
#define INTERRUPT_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW_SHIFT (0U)
/*! HighPriority_overflow - When set to 1, mutes ih_fc_stat2[0] */
#define INTERRUPT_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT2_HIGHPRIORITY_OVERFLOW_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW_MASK (0x2U)
#define INTERRUPT_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW_SHIFT (1U)
/*! LowPriority_overflow - When set to 1, mutes ih_fc_stat2[1] */
#define INTERRUPT_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT2_LOWPRIORITY_OVERFLOW_MASK)

#define INTERRUPT_IH_MUTE_FC_STAT2_DRM_MASK      (0x10U)
#define INTERRUPT_IH_MUTE_FC_STAT2_DRM_SHIFT     (4U)
/*! DRM - When set to 1, mutes ih_fc_stat2[4]. */
#define INTERRUPT_IH_MUTE_FC_STAT2_DRM(x)        (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_FC_STAT2_DRM_SHIFT)) & INTERRUPT_IH_MUTE_FC_STAT2_DRM_MASK)
/*! @} */

/*! @name IH_MUTE_AS_STAT0 - Audio Sampler Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW_MASK (0x1U)
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW_SHIFT (0U)
/*! Aud_fifo_overflow - When set to 1, mutes ih_as_stat0[0] */
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW_SHIFT)) & INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_OVERFLOW_MASK)

#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_MASK (0x2U)
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_SHIFT (1U)
/*! Aud_fifo_underflow - When set to 1, mutes ih_as_stat0[1] */
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_SHIFT)) & INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_MASK)

#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_MASK (0x4U)
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_SHIFT (2U)
/*! Aud_fifo_underflow_thr - When set to 1, mutes ih_as_stat0[2] */
#define INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_SHIFT)) & INTERRUPT_IH_MUTE_AS_STAT0_AUD_FIFO_UNDERFLOW_THR_MASK)

#define INTERRUPT_IH_MUTE_AS_STAT0_FIFO_OVERRUN_MASK (0x8U)
#define INTERRUPT_IH_MUTE_AS_STAT0_FIFO_OVERRUN_SHIFT (3U)
/*! fifo_overrun - When set to 1, mutes ih_as_stat0[3] */
#define INTERRUPT_IH_MUTE_AS_STAT0_FIFO_OVERRUN(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_AS_STAT0_FIFO_OVERRUN_SHIFT)) & INTERRUPT_IH_MUTE_AS_STAT0_FIFO_OVERRUN_MASK)
/*! @} */

/*! @name IH_MUTE_PHY_STAT0 - PHY Interface Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_PHY_STAT0_HPD_MASK     (0x1U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_HPD_SHIFT    (0U)
/*! HPD - When set to 1, mutes ih_phy_stat0[0] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_HPD(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_HPD_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_HPD_MASK)

#define INTERRUPT_IH_MUTE_PHY_STAT0_TX_PHY_LOCK_MASK (0x2U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_TX_PHY_LOCK_SHIFT (1U)
/*! TX_PHY_LOCK - When set to 1, mutes ih_phy_stat0[1] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_TX_PHY_LOCK(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_TX_PHY_LOCK_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_TX_PHY_LOCK_MASK)

#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_0_MASK (0x4U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_0_SHIFT (2U)
/*! RX_SENSE_0 - When set to 1, mutes ih_phy_stat0[2] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_0(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_0_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_0_MASK)

#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_1_MASK (0x8U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_1_SHIFT (3U)
/*! RX_SENSE_1 - When set to 1, mutes ih_phy_stat0[3] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_1(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_1_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_1_MASK)

#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_2_MASK (0x10U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_2_SHIFT (4U)
/*! RX_SENSE_2 - When set to 1, mutes ih_phy_stat0[4] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_2(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_2_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_2_MASK)

#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_3_MASK (0x20U)
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_3_SHIFT (5U)
/*! RX_SENSE_3 - When set to 1, mutes ih_phy_stat0[5] */
#define INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_3(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_3_SHIFT)) & INTERRUPT_IH_MUTE_PHY_STAT0_RX_SENSE_3_MASK)
/*! @} */

/*! @name IH_MUTE_I2CM_STAT0 - E-DDC I2C Master Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERERROR_MASK (0x1U)
#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERERROR_SHIFT (0U)
/*! I2Cmastererror - When set to 1, mutes ih_i2cm_stat0[0] */
#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERERROR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERERROR_SHIFT)) & INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERERROR_MASK)

#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERDONE_MASK (0x2U)
#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERDONE_SHIFT (1U)
/*! I2Cmasterdone - When set to 1, mutes ih_i2cm_stat0[1] */
#define INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERDONE(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERDONE_SHIFT)) & INTERRUPT_IH_MUTE_I2CM_STAT0_I2CMASTERDONE_MASK)

#define INTERRUPT_IH_MUTE_I2CM_STAT0_SCDC_READREQ_MASK (0x4U)
#define INTERRUPT_IH_MUTE_I2CM_STAT0_SCDC_READREQ_SHIFT (2U)
/*! scdc_readreq - When set to 1, mutes ih_i2cm_stat0[2] */
#define INTERRUPT_IH_MUTE_I2CM_STAT0_SCDC_READREQ(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_I2CM_STAT0_SCDC_READREQ_SHIFT)) & INTERRUPT_IH_MUTE_I2CM_STAT0_SCDC_READREQ_MASK)
/*! @} */

/*! @name IH_MUTE_CEC_STAT0 - CEC Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_CEC_STAT0_DONE_MASK    (0x1U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_DONE_SHIFT   (0U)
/*! DONE - When set to 1, mutes ih_cec_stat0[0] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_DONE(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_DONE_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_DONE_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_EOM_MASK     (0x2U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_EOM_SHIFT    (1U)
/*! EOM - When set to 1, mutes ih_cec_stat0[1] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_EOM(x)       (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_EOM_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_EOM_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_NACK_MASK    (0x4U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_NACK_SHIFT   (2U)
/*! NACK - When set to 1, mutes ih_cec_stat0[2] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_NACK(x)      (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_NACK_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_NACK_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_ARB_LOST_MASK (0x8U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_ARB_LOST_SHIFT (3U)
/*! ARB_LOST - When set to 1, mutes ih_cec_stat0[3] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_ARB_LOST(x)  (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_ARB_LOST_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_ARB_LOST_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_INITIATOR_MASK (0x10U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_INITIATOR_SHIFT (4U)
/*! ERROR_INITIATOR - When set to 1, mutes ih_cec_stat0[4] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_INITIATOR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_INITIATOR_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_INITIATOR_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_FOLLOW_MASK (0x20U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_FOLLOW_SHIFT (5U)
/*! ERROR_FOLLOW - When set to 1, mutes ih_cec_stat0[5] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_FOLLOW(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_FOLLOW_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_ERROR_FOLLOW_MASK)

#define INTERRUPT_IH_MUTE_CEC_STAT0_WAKEUP_MASK  (0x40U)
#define INTERRUPT_IH_MUTE_CEC_STAT0_WAKEUP_SHIFT (6U)
/*! WAKEUP - When set to 1, mutes ih_cec_stat0[6] */
#define INTERRUPT_IH_MUTE_CEC_STAT0_WAKEUP(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_CEC_STAT0_WAKEUP_SHIFT)) & INTERRUPT_IH_MUTE_CEC_STAT0_WAKEUP_MASK)
/*! @} */

/*! @name IH_MUTE_VP_STAT0 - Video Packetizer Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_1_MASK  (0x1U)
#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_1_SHIFT (0U)
/*! spare_1 - Reserved as "spare" bit with no associated functionality. */
#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_1(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_SPARE_1_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_SPARE_1_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_2_MASK  (0x2U)
#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_2_SHIFT (1U)
/*! spare_2 - Reserved as "spare" bit with no associated functionality. */
#define INTERRUPT_IH_MUTE_VP_STAT0_SPARE_2(x)    (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_SPARE_2_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_SPARE_2_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP_MASK (0x4U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP_SHIFT (2U)
/*! fifoemptyremap - When set to 1, mutes ih_vp_stat0[2] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREMAP_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREMAP_MASK (0x8U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREMAP_SHIFT (3U)
/*! fifofullremap - When set to 1, mutes ih_vp_stat0[3] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREMAP(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREMAP_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREMAP_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYPP_MASK (0x10U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYPP_SHIFT (4U)
/*! fifoemptypp - When set to 1, mutes ih_vp_stat0[4] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYPP(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYPP_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYPP_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLPP_MASK (0x20U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLPP_SHIFT (5U)
/*! fifofullpp - When set to 1, mutes ih_vp_stat0[5] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLPP(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLPP_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLPP_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREPET_MASK (0x40U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREPET_SHIFT (6U)
/*! fifoemptyrepet - When set to 1, mutes ih_vp_stat0[6] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREPET(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREPET_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOEMPTYREPET_MASK)

#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREPET_MASK (0x80U)
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREPET_SHIFT (7U)
/*! fifofullrepet - When set to 1, mutes ih_vp_stat0[7] */
#define INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREPET(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREPET_SHIFT)) & INTERRUPT_IH_MUTE_VP_STAT0_FIFOFULLREPET_MASK)
/*! @} */

/*! @name IH_MUTE_I2CMPHY_STAT0 - PHY GEN2 I2C Master Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR_MASK (0x1U)
#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR_SHIFT (0U)
/*! I2Cmphyerror - When set to 1, mutes ih_i2cmphy_stat0[0] */
#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR_SHIFT)) & INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYERROR_MASK)

#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE_MASK (0x2U)
#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE_SHIFT (1U)
/*! I2Cmphydone - When set to 1, mutes ih_i2cmphy_stat0[1] */
#define INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE_SHIFT)) & INTERRUPT_IH_MUTE_I2CMPHY_STAT0_I2CMPHYDONE_MASK)
/*! @} */

/*! @name IH_MUTE - Global Interrupt Mute Control Register */
/*! @{ */

#define INTERRUPT_IH_MUTE_MUTE_ALL_INTERRUPT_MASK (0x1U)
#define INTERRUPT_IH_MUTE_MUTE_ALL_INTERRUPT_SHIFT (0U)
/*! mute_all_interrupt - When set to 1, mutes the main interrupt line (where all interrupts are ORed). */
#define INTERRUPT_IH_MUTE_MUTE_ALL_INTERRUPT(x)  (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_MUTE_ALL_INTERRUPT_SHIFT)) & INTERRUPT_IH_MUTE_MUTE_ALL_INTERRUPT_MASK)

#define INTERRUPT_IH_MUTE_MUTE_WAKEUP_INTERRUPT_MASK (0x2U)
#define INTERRUPT_IH_MUTE_MUTE_WAKEUP_INTERRUPT_SHIFT (1U)
/*! mute_wakeup_interrupt - When set to 1, mutes the main interrupt output port. */
#define INTERRUPT_IH_MUTE_MUTE_WAKEUP_INTERRUPT(x) (((uint8_t)(((uint8_t)(x)) << INTERRUPT_IH_MUTE_MUTE_WAKEUP_INTERRUPT_SHIFT)) & INTERRUPT_IH_MUTE_MUTE_WAKEUP_INTERRUPT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group INTERRUPT_Register_Masks */


/*!
 * @}
 */ /* end of group INTERRUPT_Peripheral_Access_Layer */


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


#endif  /* PERI_INTERRUPT_H_ */

