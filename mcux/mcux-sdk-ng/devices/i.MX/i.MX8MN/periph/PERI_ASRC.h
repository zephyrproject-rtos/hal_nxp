/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for ASRC
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_ASRC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for ASRC
 *
 * CMSIS Peripheral Access Layer for ASRC
 */

#if !defined(PERI_ASRC_H_)
#define PERI_ASRC_H_                             /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- ASRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASRC_Peripheral_Access_Layer ASRC Peripheral Access Layer
 * @{
 */

/** ASRC - Size of Registers Arrays */
#define ASRC_WRFIFO_COUNT                         4u
#define ASRC_RDFIFO_COUNT                         4u
#define ASRC_CTX_CTRL_COUNT                       4u
#define ASRC_CTX_CTRL_EXT1_COUNT                  4u
#define ASRC_CTX_CTRL_EXT2_COUNT                  4u
#define ASRC_CTRL_IN_ACCESS_COUNT                 4u
#define ASRC_PROC_CTRL_SLOT0_R0_COUNT             4u
#define ASRC_PROC_CTRL_SLOT0_R1_COUNT             4u
#define ASRC_PROC_CTRL_SLOT0_R2_COUNT             4u
#define ASRC_PROC_CTRL_SLOT0_R3_COUNT             4u
#define ASRC_PROC_CTRL_SLOT1_R0_COUNT             4u
#define ASRC_PROC_CTRL_SLOT1_R1_COUNT             4u
#define ASRC_PROC_CTRL_SLOT1_R2_COUNT             4u
#define ASRC_PROC_CTRL_SLOT1_R3_COUNT             4u
#define ASRC_CTX_OUT_CTRL_COUNT                   4u
#define ASRC_CTRL_OUT_ACCESS_COUNT                4u
#define ASRC_SAMPLE_FIFO_STATUS_COUNT             4u
#define ASRC_RS_RATIO_LOW_COUNT                   4u
#define ASRC_RS_UPDATE_CTRL_COUNT                 4u
#define ASRC_RS_UPDATE_RATE_COUNT                 4u
#define ASRC_PRE_COEFF_FIFO_COUNT                 4u
#define ASRC_CHANNEL_STATUS_0_COUNT               4u
#define ASRC_CHANNEL_STATUS_1_COUNT               4u
#define ASRC_CHANNEL_STATUS_2_COUNT               4u
#define ASRC_CHANNEL_STATUS_3_COUNT               4u
#define ASRC_CHANNEL_STATUS_4_COUNT               4u
#define ASRC_CHANNEL_STATUS_5_COUNT               4u

/** ASRC - Register Layout Typedef */
typedef struct {
  __O  uint32_t WRFIFO[ASRC_WRFIFO_COUNT];         /**< ASRC Input Write FIFO, array offset: 0x0, array step: 0x4 */
  __I  uint32_t RDFIFO[ASRC_RDFIFO_COUNT];         /**< ASRC Output Read FIFO, array offset: 0x10, array step: 0x4 */
  __IO uint32_t CTX_CTRL[ASRC_CTX_CTRL_COUNT];     /**< ASRC Context Control, array offset: 0x20, array step: 0x4 */
  __IO uint32_t CTX_CTRL_EXT1[ASRC_CTX_CTRL_EXT1_COUNT]; /**< ASRC Context Control Extended 1, array offset: 0x30, array step: 0x4 */
  __IO uint32_t CTX_CTRL_EXT2[ASRC_CTX_CTRL_EXT2_COUNT]; /**< ASRC Context Control Extended 2, array offset: 0x40, array step: 0x4 */
  __IO uint32_t CTRL_IN_ACCESS[ASRC_CTRL_IN_ACCESS_COUNT]; /**< ASRC Control Input Access, array offset: 0x50, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT0_R0[ASRC_PROC_CTRL_SLOT0_R0_COUNT]; /**< ASRC Datapath Processor Control Slot0 Register0, array offset: 0x60, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT0_R1[ASRC_PROC_CTRL_SLOT0_R1_COUNT]; /**< ASRC Datapath Processor Control Slot0 Register1, array offset: 0x70, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT0_R2[ASRC_PROC_CTRL_SLOT0_R2_COUNT]; /**< ASRC Datapath Processor Control Slot0 Register2, array offset: 0x80, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT0_R3[ASRC_PROC_CTRL_SLOT0_R3_COUNT]; /**< ASRC Datapath Processor Control Slot0 Register3, array offset: 0x90, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT1_R0[ASRC_PROC_CTRL_SLOT1_R0_COUNT]; /**< ASRC Datapath Processor Control Slot1 Register0, array offset: 0xA0, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT1_R1[ASRC_PROC_CTRL_SLOT1_R1_COUNT]; /**< ASRC Datapath Processor Control SLOT1 Register1, array offset: 0xB0, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT1_R2[ASRC_PROC_CTRL_SLOT1_R2_COUNT]; /**< ASRC Datapath Processor Control SLOT1 Register2, array offset: 0xC0, array step: 0x4 */
  __IO uint32_t PROC_CTRL_SLOT1_R3[ASRC_PROC_CTRL_SLOT1_R3_COUNT]; /**< ASRC Datapath Processor Control SLOT1 Register3, array offset: 0xD0, array step: 0x4 */
  __IO uint32_t CTX_OUT_CTRL[ASRC_CTX_OUT_CTRL_COUNT]; /**< ASRC Context Output Control, array offset: 0xE0, array step: 0x4 */
  __IO uint32_t CTRL_OUT_ACCESS[ASRC_CTRL_OUT_ACCESS_COUNT]; /**< ASRC Control Output Access, array offset: 0xF0, array step: 0x4 */
  __I  uint32_t SAMPLE_FIFO_STATUS[ASRC_SAMPLE_FIFO_STATUS_COUNT]; /**< ASRC Sample FIFO Status, array offset: 0x100, array step: 0x4 */
  struct {                                         /* offset: 0x110, array step: 0x8 */
    __IO uint32_t RS_RATIO_LOW;                      /**< ASRC Resampling Ratio Low, array offset: 0x110, array step: 0x8 */
    __IO uint32_t RS_RATIO_HIGH;                     /**< ASRC Resampling Ratio High, array offset: 0x114, array step: 0x8 */
  } RS_RATIO_LOW[ASRC_RS_RATIO_LOW_COUNT];
  __IO uint32_t RS_UPDATE_CTRL[ASRC_RS_UPDATE_CTRL_COUNT]; /**< ASRC Resampling Ratio Update Control, array offset: 0x130, array step: 0x4 */
  __IO uint32_t RS_UPDATE_RATE[ASRC_RS_UPDATE_RATE_COUNT]; /**< ASRC Resampling Ratio Update Rate, array offset: 0x140, array step: 0x4 */
  __IO uint32_t RS_CT_LOW;                         /**< ASRC Resampling Center Tap Coefficient Low, offset: 0x150 */
  __IO uint32_t RS_CT_HIGH;                        /**< ASRC Resampling Center Tap Coefficient High, offset: 0x154 */
       uint8_t RESERVED_0[8];
  __IO uint32_t PRE_COEFF_FIFO[ASRC_PRE_COEFF_FIFO_COUNT]; /**< ASRC Prefilter Coefficient FIFO, array offset: 0x160, array step: 0x4 */
  __O  uint32_t CTX_RS_COEFF_MEM;                  /**< ASRC Context Resampling Coefficient Memory, offset: 0x170 */
  __IO uint32_t CTX_RS_COEFF_CTRL;                 /**< ASRC Context Resampling Coefficient Control, offset: 0x174 */
  __IO uint32_t IRQ_CTRL;                          /**< ASRC Interrupt Control, offset: 0x178 */
  __IO uint32_t IRQ_FLAGS;                         /**< ASRC Interrupt Status Flags, offset: 0x17C */
  __IO uint32_t CHANNEL_STATUS_0[ASRC_CHANNEL_STATUS_0_COUNT]; /**< ASRC Channel Status 0, array offset: 0x180, array step: 0x4 */
  __IO uint32_t CHANNEL_STATUS_1[ASRC_CHANNEL_STATUS_1_COUNT]; /**< ASRC Channel Status 1, array offset: 0x190, array step: 0x4 */
  __IO uint32_t CHANNEL_STATUS_2[ASRC_CHANNEL_STATUS_2_COUNT]; /**< ASRC Channel Status 2, array offset: 0x1A0, array step: 0x4 */
  __IO uint32_t CHANNEL_STATUS_3[ASRC_CHANNEL_STATUS_3_COUNT]; /**< ASRC Channel Status 3, array offset: 0x1B0, array step: 0x4 */
  __IO uint32_t CHANNEL_STATUS_4[ASRC_CHANNEL_STATUS_4_COUNT]; /**< ASRC Channel Status 4, array offset: 0x1C0, array step: 0x4 */
  __IO uint32_t CHANNEL_STATUS_5[ASRC_CHANNEL_STATUS_5_COUNT]; /**< ASRC Channel Status 5, array offset: 0x1D0, array step: 0x4 */
} ASRC_Type;

/* ----------------------------------------------------------------------------
   -- ASRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ASRC_Register_Masks ASRC Register Masks
 * @{
 */

/*! @name WRFIFO - ASRC Input Write FIFO */
/*! @{ */

#define ASRC_WRFIFO_CTX_WR_DATA_MASK             (0xFFFFFFFFU)
#define ASRC_WRFIFO_CTX_WR_DATA_SHIFT            (0U)
/*! CTX_WR_DATA - Write Data For CTX Input FIFO */
#define ASRC_WRFIFO_CTX_WR_DATA(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_WRFIFO_CTX_WR_DATA_SHIFT)) & ASRC_WRFIFO_CTX_WR_DATA_MASK)
/*! @} */

/*! @name RDFIFO - ASRC Output Read FIFO */
/*! @{ */

#define ASRC_RDFIFO_CTX_RD_DATA_MASK             (0xFFFFFFFFU)
#define ASRC_RDFIFO_CTX_RD_DATA_SHIFT            (0U)
/*! CTX_RD_DATA - Read Data For CTX Output FIFO */
#define ASRC_RDFIFO_CTX_RD_DATA(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_RDFIFO_CTX_RD_DATA_SHIFT)) & ASRC_RDFIFO_CTX_RD_DATA_MASK)
/*! @} */

/*! @name CTX_CTRL - ASRC Context Control */
/*! @{ */

#define ASRC_CTX_CTRL_NUM_CH_EN_MASK             (0x1FU)
#define ASRC_CTX_CTRL_NUM_CH_EN_SHIFT            (0U)
/*! NUM_CH_EN - Number of Channels In Context */
#define ASRC_CTX_CTRL_NUM_CH_EN(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_NUM_CH_EN_SHIFT)) & ASRC_CTX_CTRL_NUM_CH_EN_MASK)

#define ASRC_CTX_CTRL_SIGN_IN_MASK               (0x40U)
#define ASRC_CTX_CTRL_SIGN_IN_SHIFT              (6U)
/*! SIGN_IN - Input Data Sign
 *  0b0..Signed Format
 *  0b1..Unsigned Format
 */
#define ASRC_CTX_CTRL_SIGN_IN(x)                 (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_SIGN_IN_SHIFT)) & ASRC_CTX_CTRL_SIGN_IN_MASK)

#define ASRC_CTX_CTRL_FLOAT_FMT_MASK             (0x80U)
#define ASRC_CTX_CTRL_FLOAT_FMT_SHIFT            (7U)
/*! FLOAT_FMT - Context Input Floating Point Format
 *  0b0..Integer Format
 *  0b1..Single Precision Floating Point Format
 */
#define ASRC_CTX_CTRL_FLOAT_FMT(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_FLOAT_FMT_SHIFT)) & ASRC_CTX_CTRL_FLOAT_FMT_MASK)

#define ASRC_CTX_CTRL_BITS_PER_SAMPLE_MASK       (0x300U)
#define ASRC_CTX_CTRL_BITS_PER_SAMPLE_SHIFT      (8U)
/*! BITS_PER_SAMPLE - Number of Bits Per Audio Sample
 *  0b00..16-bits Per Sample
 *  0b01..20-bits Per Sample
 *  0b10..24-bits Per Sample
 *  0b11..32-bits Per Sample
 */
#define ASRC_CTX_CTRL_BITS_PER_SAMPLE(x)         (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_BITS_PER_SAMPLE_SHIFT)) & ASRC_CTX_CTRL_BITS_PER_SAMPLE_MASK)

#define ASRC_CTX_CTRL_BIT_REV_MASK               (0x400U)
#define ASRC_CTX_CTRL_BIT_REV_SHIFT              (10U)
/*! BIT_REV - Sample Bit Reversal
 *  0b0..Keep Input Ordering
 *  0b1..Reverse Bit Ordering
 */
#define ASRC_CTX_CTRL_BIT_REV(x)                 (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_BIT_REV_SHIFT)) & ASRC_CTX_CTRL_BIT_REV_MASK)

#define ASRC_CTX_CTRL_SAMPLE_POSITION_MASK       (0xF800U)
#define ASRC_CTX_CTRL_SAMPLE_POSITION_SHIFT      (11U)
/*! SAMPLE_POSITION - Sample Position */
#define ASRC_CTX_CTRL_SAMPLE_POSITION(x)         (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_SAMPLE_POSITION_SHIFT)) & ASRC_CTX_CTRL_SAMPLE_POSITION_MASK)

#define ASRC_CTX_CTRL_FIFO_WTMK_MASK             (0x7F0000U)
#define ASRC_CTX_CTRL_FIFO_WTMK_SHIFT            (16U)
/*! FIFO_WTMK - Context Input FIFO Watermark */
#define ASRC_CTX_CTRL_FIFO_WTMK(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_FIFO_WTMK_SHIFT)) & ASRC_CTX_CTRL_FIFO_WTMK_MASK)

#define ASRC_CTX_CTRL_FWMDE_MASK                 (0x10000000U)
#define ASRC_CTX_CTRL_FWMDE_SHIFT                (28U)
/*! FWMDE - FIFO Watermark DMA Enable
 *  0b0..Input DMA Requests Not Enabled for This Context
 *  0b1..Input DMA Requests Enabled for This Context
 */
#define ASRC_CTX_CTRL_FWMDE(x)                   (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_FWMDE_SHIFT)) & ASRC_CTX_CTRL_FWMDE_MASK)

#define ASRC_CTX_CTRL_RUN_STOP_MASK              (0x20000000U)
#define ASRC_CTX_CTRL_RUN_STOP_SHIFT             (29U)
/*! RUN_STOP - Context Run Stop */
#define ASRC_CTX_CTRL_RUN_STOP(x)                (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_RUN_STOP_SHIFT)) & ASRC_CTX_CTRL_RUN_STOP_MASK)

#define ASRC_CTX_CTRL_RUN_EN_MASK                (0x80000000U)
#define ASRC_CTX_CTRL_RUN_EN_SHIFT               (31U)
/*! RUN_EN - Context Run Enable */
#define ASRC_CTX_CTRL_RUN_EN(x)                  (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_RUN_EN_SHIFT)) & ASRC_CTX_CTRL_RUN_EN_MASK)
/*! @} */

/*! @name CTX_CTRL_EXT1 - ASRC Context Control Extended 1 */
/*! @{ */

#define ASRC_CTX_CTRL_EXT1_PF_INIT_MODE_MASK     (0x3U)
#define ASRC_CTX_CTRL_EXT1_PF_INIT_MODE_SHIFT    (0U)
/*! PF_INIT_MODE - Prefilter Initialization Mode
 *  0b00..Do not pre-fill any prefilter taps. The first sample written to the ASRC corresponds to the highest index prefilter filter tap.
 *  0b01..Replicate the first sample to fill the right half of the prefilter.
 *  0b10..Zero fill the right half of the prefilter.
 *  0b11..N/A
 */
#define ASRC_CTX_CTRL_EXT1_PF_INIT_MODE(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_INIT_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_INIT_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_RS_INIT_MODE_MASK     (0xCU)
#define ASRC_CTX_CTRL_EXT1_RS_INIT_MODE_SHIFT    (2U)
/*! RS_INIT_MODE - Resampler Initialization Mode
 *  0b00..Do not pre-fill any resampler taps. The first sample output from the prefilter corresponds to the highest index resampling filter tap.
 *  0b01..Replicate the first prefilter output sample to fill the right half of the resampler.
 *  0b10..Fill the right half of the re-sampler with zeros.
 *  0b11..N/A
 */
#define ASRC_CTX_CTRL_EXT1_RS_INIT_MODE(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_RS_INIT_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_RS_INIT_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_STOP_MODE_MASK     (0x10U)
#define ASRC_CTX_CTRL_EXT1_PF_STOP_MODE_SHIFT    (4U)
/*! PF_STOP_MODE - Pre-Filter Stop Mode
 *  0b0..Replicate the last sample input to the ASRC_WRFIFO for the left-half of the pre-filter on RUN_STOP.
 *  0b1..Zero-Fill the left-half of the pre-filter on RUN_STOP.
 */
#define ASRC_CTX_CTRL_EXT1_PF_STOP_MODE(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_STOP_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_STOP_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_RS_STOP_MODE_MASK     (0x20U)
#define ASRC_CTX_CTRL_EXT1_RS_STOP_MODE_SHIFT    (5U)
/*! RS_STOP_MODE - Resampler Stop Mode
 *  0b0..Replicate the final prefilter output for the left-half of the resampler on RUN_STOP.
 *  0b1..Zero-Fill the left-half of the resampler on RUN_STOP.
 */
#define ASRC_CTX_CTRL_EXT1_RS_STOP_MODE(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_RS_STOP_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_RS_STOP_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_BYPASS_MODE_MASK   (0x40U)
#define ASRC_CTX_CTRL_EXT1_PF_BYPASS_MODE_SHIFT  (6U)
/*! PF_BYPASS_MODE - Prefilter Bypass Mode
 *  0b0..Run the prefilter in normal operation.
 *  0b1..Run the prefilter in bypass mode.
 */
#define ASRC_CTX_CTRL_EXT1_PF_BYPASS_MODE(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_BYPASS_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_BYPASS_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_RS_BYPASS_MODE_MASK   (0x80U)
#define ASRC_CTX_CTRL_EXT1_RS_BYPASS_MODE_SHIFT  (7U)
/*! RS_BYPASS_MODE - Resampler Bypass Mode
 *  0b0..Run the resampler in normal operation.
 *  0b1..Run the resampler in bypass mode.
 */
#define ASRC_CTX_CTRL_EXT1_RS_BYPASS_MODE(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_RS_BYPASS_MODE_SHIFT)) & ASRC_CTX_CTRL_EXT1_RS_BYPASS_MODE_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_TWO_STAGE_EN_MASK  (0x100U)
#define ASRC_CTX_CTRL_EXT1_PF_TWO_STAGE_EN_SHIFT (8U)
/*! PF_TWO_STAGE_EN - Prefilter Two-Stage Enable
 *  0b0..The pre-filter will run in single stage mode (ST1 only)
 *  0b1..The pre-filter will run in two stage mode (ST1 and ST2)
 */
#define ASRC_CTX_CTRL_EXT1_PF_TWO_STAGE_EN(x)    (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_TWO_STAGE_EN_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_TWO_STAGE_EN_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_ST1_WB_FLOAT_MASK  (0x200U)
#define ASRC_CTX_CTRL_EXT1_PF_ST1_WB_FLOAT_SHIFT (9U)
/*! PF_ST1_WB_FLOAT - Prefilter Stage1 Writeback Floating Point
 *  0b0..The pre-filter stage1 results are stored in 32-bit integer format.
 *  0b1..The pre-filter stage1 results are stored in 32-bit floating point format.
 */
#define ASRC_CTX_CTRL_EXT1_PF_ST1_WB_FLOAT(x)    (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_ST1_WB_FLOAT_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_ST1_WB_FLOAT_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_EXPANSION_FACTOR_MASK (0xFF0000U)
#define ASRC_CTX_CTRL_EXT1_PF_EXPANSION_FACTOR_SHIFT (16U)
/*! PF_EXPANSION_FACTOR - Prefilter IFIR Expansion Factor */
#define ASRC_CTX_CTRL_EXT1_PF_EXPANSION_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_EXPANSION_FACTOR_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_EXPANSION_FACTOR_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_COEFF_MEM_RST_MASK (0x1000000U)
#define ASRC_CTX_CTRL_EXT1_PF_COEFF_MEM_RST_SHIFT (24U)
/*! PF_COEFF_MEM_RST - Prefilter Coefficient Memory Reset */
#define ASRC_CTX_CTRL_EXT1_PF_COEFF_MEM_RST(x)   (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_COEFF_MEM_RST_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_COEFF_MEM_RST_MASK)

#define ASRC_CTX_CTRL_EXT1_PF_COEFF_STAGE_WR_MASK (0x2000000U)
#define ASRC_CTX_CTRL_EXT1_PF_COEFF_STAGE_WR_SHIFT (25U)
/*! PF_COEFF_STAGE_WR - Prefilter Coefficient Write Select */
#define ASRC_CTX_CTRL_EXT1_PF_COEFF_STAGE_WR(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT1_PF_COEFF_STAGE_WR_SHIFT)) & ASRC_CTX_CTRL_EXT1_PF_COEFF_STAGE_WR_MASK)
/*! @} */

/*! @name CTX_CTRL_EXT2 - ASRC Context Control Extended 2 */
/*! @{ */

#define ASRC_CTX_CTRL_EXT2_ST1_NUM_TAPS_MASK     (0x1FFU)
#define ASRC_CTX_CTRL_EXT2_ST1_NUM_TAPS_SHIFT    (0U)
/*! ST1_NUM_TAPS - Prefilter Stage1 Number of Taps */
#define ASRC_CTX_CTRL_EXT2_ST1_NUM_TAPS(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT2_ST1_NUM_TAPS_SHIFT)) & ASRC_CTX_CTRL_EXT2_ST1_NUM_TAPS_MASK)

#define ASRC_CTX_CTRL_EXT2_ST2_NUM_TAPS_MASK     (0x1FF0000U)
#define ASRC_CTX_CTRL_EXT2_ST2_NUM_TAPS_SHIFT    (16U)
/*! ST2_NUM_TAPS - Prefilter Stage2 Number of Taps */
#define ASRC_CTX_CTRL_EXT2_ST2_NUM_TAPS(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_CTRL_EXT2_ST2_NUM_TAPS_SHIFT)) & ASRC_CTX_CTRL_EXT2_ST2_NUM_TAPS_MASK)
/*! @} */

/*! @name CTRL_IN_ACCESS - ASRC Control Input Access */
/*! @{ */

#define ASRC_CTRL_IN_ACCESS_ACCESS_LENGTH_MASK   (0x3FU)
#define ASRC_CTRL_IN_ACCESS_ACCESS_LENGTH_SHIFT  (0U)
/*! ACCESS_LENGTH - Number Of Channels Per Source */
#define ASRC_CTRL_IN_ACCESS_ACCESS_LENGTH(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_IN_ACCESS_ACCESS_LENGTH_SHIFT)) & ASRC_CTRL_IN_ACCESS_ACCESS_LENGTH_MASK)

#define ASRC_CTRL_IN_ACCESS_GROUP_LENGTH_MASK    (0x3F00U)
#define ASRC_CTRL_IN_ACCESS_GROUP_LENGTH_SHIFT   (8U)
/*! GROUP_LENGTH - Number of Channels in a Context */
#define ASRC_CTRL_IN_ACCESS_GROUP_LENGTH(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_IN_ACCESS_GROUP_LENGTH_SHIFT)) & ASRC_CTRL_IN_ACCESS_GROUP_LENGTH_MASK)

#define ASRC_CTRL_IN_ACCESS_ITERATIONS_MASK      (0x3F0000U)
#define ASRC_CTRL_IN_ACCESS_ITERATIONS_SHIFT     (16U)
/*! ITERATIONS - Number of Sequential Fetches Per Source */
#define ASRC_CTRL_IN_ACCESS_ITERATIONS(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_IN_ACCESS_ITERATIONS_SHIFT)) & ASRC_CTRL_IN_ACCESS_ITERATIONS_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT0_R0 - ASRC Datapath Processor Control Slot0 Register0 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_EN_MASK    (0x1U)
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_EN_SHIFT   (0U)
/*! SLOT0_EN - SLOT0 Enable
 *  0b0..Context SLOT0 is disabled
 *  0b1..Context SLOT0 is enabled
 */
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_EN(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R0_SLOT0_EN_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R0_SLOT0_EN_MASK)

#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_CTX_NUM_MASK (0x6U)
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_CTX_NUM_SHIFT (1U)
/*! SLOT0_CTX_NUM - Context SLOT0 Selection */
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_CTX_NUM(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R0_SLOT0_CTX_NUM_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R0_SLOT0_CTX_NUM_MASK)

#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_NUM_CH_MASK (0x1F00U)
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_NUM_CH_SHIFT (8U)
/*! SLOT0_NUM_CH - SLOT0 Number of Channels
 *  0b00000..Context SLOT0 owns 1 of 8 channels
 *  0b00001..Context SLOT0 owns 2 of 8 channels
 *  0b00010..Context SLOT0 owns 3 of 8 channels
 *  0b00011-0b00111..Context SLOT0 owns N of 8 channels
 */
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_NUM_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R0_SLOT0_NUM_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R0_SLOT0_NUM_CH_MASK)

#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MIN_CH_MASK (0x1F0000U)
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MIN_CH_SHIFT (16U)
/*! SLOT0_MIN_CH - SLOT0 Minimum Global Channel Number */
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MIN_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MIN_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MIN_CH_MASK)

#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MAX_CH_MASK (0x1F000000U)
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MAX_CH_SHIFT (24U)
/*! SLOT0_MAX_CH - SLOT0 Maximum Global Channel Number */
#define ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MAX_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MAX_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R0_SLOT0_MAX_CH_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT0_R1 - ASRC Datapath Processor Control Slot0 Register1 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT0_R1_SLOT0_ST1_CHANxEXP_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT0_R1_SLOT0_ST1_CHANxEXP_SHIFT (0U)
/*! SLOT0_ST1_CHANxEXP - SLOT0 Stage1 Channels x Expansion Factor */
#define ASRC_PROC_CTRL_SLOT0_R1_SLOT0_ST1_CHANxEXP(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R1_SLOT0_ST1_CHANxEXP_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R1_SLOT0_ST1_CHANxEXP_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT0_R2 - ASRC Datapath Processor Control Slot0 Register2 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_ST_ADDR_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_ST_ADDR_SHIFT (0U)
/*! SLOT0_ST1_ST_ADDR - SLOT0 Stage1 Start Address */
#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_ST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_ST_ADDR_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_ST_ADDR_MASK)

#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_MEM_ALLOC_MASK (0x1FFF0000U)
#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_MEM_ALLOC_SHIFT (16U)
/*! SLOT0_ST1_MEM_ALLOC - SLOT0 Stage1 Memory Allocation */
#define ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_MEM_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_MEM_ALLOC_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R2_SLOT0_ST1_MEM_ALLOC_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT0_R3 - ASRC Datapath Processor Control Slot0 Register3 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_ST_ADDR_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_ST_ADDR_SHIFT (0U)
/*! SLOT0_ST2_ST_ADDR - SLOT0 Stage2 Start Address */
#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_ST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_ST_ADDR_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_ST_ADDR_MASK)

#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_MEM_ALLOC_MASK (0x1FFF0000U)
#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_MEM_ALLOC_SHIFT (16U)
/*! SLOT0_ST2_MEM_ALLOC - SLOT0 Stage2 Memory Allocation */
#define ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_MEM_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_MEM_ALLOC_SHIFT)) & ASRC_PROC_CTRL_SLOT0_R3_SLOT0_ST2_MEM_ALLOC_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT1_R0 - ASRC Datapath Processor Control Slot1 Register0 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_EN_MASK    (0x1U)
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_EN_SHIFT   (0U)
/*! SLOT1_EN - SLOT1 Enable
 *  0b0..Context SLOT1 is disabled
 *  0b1..Context SLOT1 is enabled
 */
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_EN(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R0_SLOT1_EN_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R0_SLOT1_EN_MASK)

#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_CTX_NUM_MASK (0x6U)
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_CTX_NUM_SHIFT (1U)
/*! SLOT1_CTX_NUM - Context SLOT1 Selection */
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_CTX_NUM(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R0_SLOT1_CTX_NUM_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R0_SLOT1_CTX_NUM_MASK)

#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_NUM_CH_MASK (0x1F00U)
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_NUM_CH_SHIFT (8U)
/*! SLOT1_NUM_CH - SLOT1 Number of Channels
 *  0b00000..Context SLOT1 owns 1 of 8 channels
 *  0b00001..Context SLOT1 owns 2 of 8 channels
 *  0b00010..Context SLOT1 owns 3 of 8 channels
 *  0b00011-0b00111..Context SLOT1 owns N of 8 channels
 */
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_NUM_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R0_SLOT1_NUM_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R0_SLOT1_NUM_CH_MASK)

#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MIN_CH_MASK (0x1F0000U)
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MIN_CH_SHIFT (16U)
/*! SLOT1_MIN_CH - Slot1 Minimum Global Channel Number */
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MIN_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MIN_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MIN_CH_MASK)

#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MAX_CH_MASK (0x1F000000U)
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MAX_CH_SHIFT (24U)
/*! SLOT1_MAX_CH - Slot1 Maximum Global Channel Number */
#define ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MAX_CH(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MAX_CH_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R0_SLOT1_MAX_CH_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT1_R1 - ASRC Datapath Processor Control SLOT1 Register1 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT1_R1_SLOT1_ST1_CHANxEXP_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT1_R1_SLOT1_ST1_CHANxEXP_SHIFT (0U)
/*! SLOT1_ST1_CHANxEXP - SLOT1 Stage1 Channels x Expansion Factor */
#define ASRC_PROC_CTRL_SLOT1_R1_SLOT1_ST1_CHANxEXP(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R1_SLOT1_ST1_CHANxEXP_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R1_SLOT1_ST1_CHANxEXP_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT1_R2 - ASRC Datapath Processor Control SLOT1 Register2 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_ST_ADDR_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_ST_ADDR_SHIFT (0U)
/*! SLOT1_ST1_ST_ADDR - SLOT1 Stage1 Start Address */
#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_ST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_ST_ADDR_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_ST_ADDR_MASK)

#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_MEM_ALLOC_MASK (0x1FFF0000U)
#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_MEM_ALLOC_SHIFT (16U)
/*! SLOT1_ST1_MEM_ALLOC - SLOT1 Stage1 Memory Allocation */
#define ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_MEM_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_MEM_ALLOC_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R2_SLOT1_ST1_MEM_ALLOC_MASK)
/*! @} */

/*! @name PROC_CTRL_SLOT1_R3 - ASRC Datapath Processor Control SLOT1 Register3 */
/*! @{ */

#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_ST_ADDR_MASK (0x1FFFU)
#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_ST_ADDR_SHIFT (0U)
/*! SLOT1_ST2_ST_ADDR - SLOT1 Stage2 Start Address */
#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_ST_ADDR(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_ST_ADDR_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_ST_ADDR_MASK)

#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_MEM_ALLOC_MASK (0x1FFF0000U)
#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_MEM_ALLOC_SHIFT (16U)
/*! SLOT1_ST2_MEM_ALLOC - SLOT1 Stage2 Memory Allocation */
#define ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_MEM_ALLOC(x) (((uint32_t)(((uint32_t)(x)) << ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_MEM_ALLOC_SHIFT)) & ASRC_PROC_CTRL_SLOT1_R3_SLOT1_ST2_MEM_ALLOC_MASK)
/*! @} */

/*! @name CTX_OUT_CTRL - ASRC Context Output Control */
/*! @{ */

#define ASRC_CTX_OUT_CTRL_DITHER_EN_MASK         (0x1U)
#define ASRC_CTX_OUT_CTRL_DITHER_EN_SHIFT        (0U)
/*! DITHER_EN - Output Dither Enable */
#define ASRC_CTX_OUT_CTRL_DITHER_EN(x)           (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_DITHER_EN_SHIFT)) & ASRC_CTX_OUT_CTRL_DITHER_EN_MASK)

#define ASRC_CTX_OUT_CTRL_IEC_EN_MASK            (0x2U)
#define ASRC_CTX_OUT_CTRL_IEC_EN_SHIFT           (1U)
/*! IEC_EN - IEC60958 Bit-Field Insertion Enable
 *  0b0..No Data Insertion Enabled.
 *  0b1..IEC60958 Bit-Field Insertion Enabled.
 */
#define ASRC_CTX_OUT_CTRL_IEC_EN(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_IEC_EN_SHIFT)) & ASRC_CTX_OUT_CTRL_IEC_EN_MASK)

#define ASRC_CTX_OUT_CTRL_IEC_V_DATA_MASK        (0x4U)
#define ASRC_CTX_OUT_CTRL_IEC_V_DATA_SHIFT       (2U)
/*! IEC_V_DATA - IEC60958 Validity Flag */
#define ASRC_CTX_OUT_CTRL_IEC_V_DATA(x)          (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_IEC_V_DATA_SHIFT)) & ASRC_CTX_OUT_CTRL_IEC_V_DATA_MASK)

#define ASRC_CTX_OUT_CTRL_SIGN_OUT_MASK          (0x40U)
#define ASRC_CTX_OUT_CTRL_SIGN_OUT_SHIFT         (6U)
/*! SIGN_OUT - Output Data Sign
 *  0b0..Signed Format
 *  0b1..Convert to Unsigned
 */
#define ASRC_CTX_OUT_CTRL_SIGN_OUT(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_SIGN_OUT_SHIFT)) & ASRC_CTX_OUT_CTRL_SIGN_OUT_MASK)

#define ASRC_CTX_OUT_CTRL_FLOAT_FMT_MASK         (0x80U)
#define ASRC_CTX_OUT_CTRL_FLOAT_FMT_SHIFT        (7U)
/*! FLOAT_FMT - Context Output Floating Point Format
 *  0b0..Integer Format
 *  0b1..Single Precision Floating Point Format
 */
#define ASRC_CTX_OUT_CTRL_FLOAT_FMT(x)           (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_FLOAT_FMT_SHIFT)) & ASRC_CTX_OUT_CTRL_FLOAT_FMT_MASK)

#define ASRC_CTX_OUT_CTRL_BITS_PER_SAMPLE_MASK   (0x300U)
#define ASRC_CTX_OUT_CTRL_BITS_PER_SAMPLE_SHIFT  (8U)
/*! BITS_PER_SAMPLE - Number of Bits Per Audio Sample
 *  0b00..16-bits Per Sample
 *  0b01..20-bits Per Sample
 *  0b10..24-bits Per Sample
 *  0b11..32-bits Per Sample
 */
#define ASRC_CTX_OUT_CTRL_BITS_PER_SAMPLE(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_BITS_PER_SAMPLE_SHIFT)) & ASRC_CTX_OUT_CTRL_BITS_PER_SAMPLE_MASK)

#define ASRC_CTX_OUT_CTRL_BIT_REV_MASK           (0x400U)
#define ASRC_CTX_OUT_CTRL_BIT_REV_SHIFT          (10U)
/*! BIT_REV - Sample Bit-Reversal
 *  0b0..No change.
 *  0b1..Bit-reverse sample data.
 */
#define ASRC_CTX_OUT_CTRL_BIT_REV(x)             (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_BIT_REV_SHIFT)) & ASRC_CTX_OUT_CTRL_BIT_REV_MASK)

#define ASRC_CTX_OUT_CTRL_SAMPLE_POSITION_MASK   (0xF800U)
#define ASRC_CTX_OUT_CTRL_SAMPLE_POSITION_SHIFT  (11U)
/*! SAMPLE_POSITION - Sample Position */
#define ASRC_CTX_OUT_CTRL_SAMPLE_POSITION(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_SAMPLE_POSITION_SHIFT)) & ASRC_CTX_OUT_CTRL_SAMPLE_POSITION_MASK)

#define ASRC_CTX_OUT_CTRL_FIFO_WTMK_MASK         (0x7F0000U)
#define ASRC_CTX_OUT_CTRL_FIFO_WTMK_SHIFT        (16U)
/*! FIFO_WTMK - Context Output FIFO Watermark */
#define ASRC_CTX_OUT_CTRL_FIFO_WTMK(x)           (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_FIFO_WTMK_SHIFT)) & ASRC_CTX_OUT_CTRL_FIFO_WTMK_MASK)

#define ASRC_CTX_OUT_CTRL_FWMDE_MASK             (0x10000000U)
#define ASRC_CTX_OUT_CTRL_FWMDE_SHIFT            (28U)
/*! FWMDE - Output FIFO Watermark DMA Enable
 *  0b0..Output DMA Requests Not Enabled for This Context
 *  0b1..Output DMA Requests Enabled for This Context
 */
#define ASRC_CTX_OUT_CTRL_FWMDE(x)               (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_OUT_CTRL_FWMDE_SHIFT)) & ASRC_CTX_OUT_CTRL_FWMDE_MASK)
/*! @} */

/*! @name CTRL_OUT_ACCESS - ASRC Control Output Access */
/*! @{ */

#define ASRC_CTRL_OUT_ACCESS_ACCESS_LENGTH_MASK  (0x3FU)
#define ASRC_CTRL_OUT_ACCESS_ACCESS_LENGTH_SHIFT (0U)
/*! ACCESS_LENGTH - Number Of Channels Per Destination */
#define ASRC_CTRL_OUT_ACCESS_ACCESS_LENGTH(x)    (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_OUT_ACCESS_ACCESS_LENGTH_SHIFT)) & ASRC_CTRL_OUT_ACCESS_ACCESS_LENGTH_MASK)

#define ASRC_CTRL_OUT_ACCESS_GROUP_LENGTH_MASK   (0x3F00U)
#define ASRC_CTRL_OUT_ACCESS_GROUP_LENGTH_SHIFT  (8U)
/*! GROUP_LENGTH - Number of Channels in a Context */
#define ASRC_CTRL_OUT_ACCESS_GROUP_LENGTH(x)     (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_OUT_ACCESS_GROUP_LENGTH_SHIFT)) & ASRC_CTRL_OUT_ACCESS_GROUP_LENGTH_MASK)

#define ASRC_CTRL_OUT_ACCESS_ITERATIONS_MASK     (0x3F0000U)
#define ASRC_CTRL_OUT_ACCESS_ITERATIONS_SHIFT    (16U)
/*! ITERATIONS - Number of Sequential Fetches Per Channel Group */
#define ASRC_CTRL_OUT_ACCESS_ITERATIONS(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_CTRL_OUT_ACCESS_ITERATIONS_SHIFT)) & ASRC_CTRL_OUT_ACCESS_ITERATIONS_MASK)
/*! @} */

/*! @name SAMPLE_FIFO_STATUS - ASRC Sample FIFO Status */
/*! @{ */

#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_OUT_MASK (0x7FU)
#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_OUT_SHIFT (0U)
/*! NUM_SAMPLE_GROUPS_OUT - Number Of Sample Groups Stored in the output FIFO */
#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_OUT(x) (((uint32_t)(((uint32_t)(x)) << ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_OUT_SHIFT)) & ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_OUT_MASK)

#define ASRC_SAMPLE_FIFO_STATUS_OUTFIFO_WTMK_MASK (0x80U)
#define ASRC_SAMPLE_FIFO_STATUS_OUTFIFO_WTMK_SHIFT (7U)
/*! OUTFIFO_WTMK - Output FIFO Watermark Flag */
#define ASRC_SAMPLE_FIFO_STATUS_OUTFIFO_WTMK(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_SAMPLE_FIFO_STATUS_OUTFIFO_WTMK_SHIFT)) & ASRC_SAMPLE_FIFO_STATUS_OUTFIFO_WTMK_MASK)

#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_IN_MASK (0x7F0000U)
#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_IN_SHIFT (16U)
/*! NUM_SAMPLE_GROUPS_IN - Number Of Sample Groups Stored in Input FIFO */
#define ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_IN(x) (((uint32_t)(((uint32_t)(x)) << ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_IN_SHIFT)) & ASRC_SAMPLE_FIFO_STATUS_NUM_SAMPLE_GROUPS_IN_MASK)

#define ASRC_SAMPLE_FIFO_STATUS_INFIFO_WTMK_MASK (0x800000U)
#define ASRC_SAMPLE_FIFO_STATUS_INFIFO_WTMK_SHIFT (23U)
/*! INFIFO_WTMK - Input FIFO Watermark Flag */
#define ASRC_SAMPLE_FIFO_STATUS_INFIFO_WTMK(x)   (((uint32_t)(((uint32_t)(x)) << ASRC_SAMPLE_FIFO_STATUS_INFIFO_WTMK_SHIFT)) & ASRC_SAMPLE_FIFO_STATUS_INFIFO_WTMK_MASK)
/*! @} */

/*! @name RS_RATIO_LOW - ASRC Resampling Ratio Low */
/*! @{ */

#define ASRC_RS_RATIO_LOW_RS_RATIO_LOW_MASK      (0xFFFFFFFFU)
#define ASRC_RS_RATIO_LOW_RS_RATIO_LOW_SHIFT     (0U)
/*! RS_RATIO_LOW - Resampling Ratio Low */
#define ASRC_RS_RATIO_LOW_RS_RATIO_LOW(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_RS_RATIO_LOW_RS_RATIO_LOW_SHIFT)) & ASRC_RS_RATIO_LOW_RS_RATIO_LOW_MASK)
/*! @} */

/*! @name RS_RATIO_HIGH - ASRC Resampling Ratio High */
/*! @{ */

#define ASRC_RS_RATIO_HIGH_RS_RATIO_HIGH_MASK    (0xFFFU)
#define ASRC_RS_RATIO_HIGH_RS_RATIO_HIGH_SHIFT   (0U)
/*! RS_RATIO_HIGH - Resampling Ratio High */
#define ASRC_RS_RATIO_HIGH_RS_RATIO_HIGH(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_RS_RATIO_HIGH_RS_RATIO_HIGH_SHIFT)) & ASRC_RS_RATIO_HIGH_RS_RATIO_HIGH_MASK)

#define ASRC_RS_RATIO_HIGH_RS_RATIO_VLD_MASK     (0x80000000U)
#define ASRC_RS_RATIO_HIGH_RS_RATIO_VLD_SHIFT    (31U)
/*! RS_RATIO_VLD - Resampling Ratio Valid */
#define ASRC_RS_RATIO_HIGH_RS_RATIO_VLD(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_RS_RATIO_HIGH_RS_RATIO_VLD_SHIFT)) & ASRC_RS_RATIO_HIGH_RS_RATIO_VLD_MASK)
/*! @} */

/* The count of ASRC_RS_RATIO_HIGH */
#define ASRC_RS_RATIO_HIGH_COUNT                 (4U)

/*! @name RS_UPDATE_CTRL - ASRC Resampling Ratio Update Control */
/*! @{ */

#define ASRC_RS_UPDATE_CTRL_RS_RATIO_MOD_MASK    (0xFFFFFFFFU)
#define ASRC_RS_UPDATE_CTRL_RS_RATIO_MOD_SHIFT   (0U)
/*! RS_RATIO_MOD - Resampling Ratio Modifier */
#define ASRC_RS_UPDATE_CTRL_RS_RATIO_MOD(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_RS_UPDATE_CTRL_RS_RATIO_MOD_SHIFT)) & ASRC_RS_UPDATE_CTRL_RS_RATIO_MOD_MASK)
/*! @} */

/*! @name RS_UPDATE_RATE - ASRC Resampling Ratio Update Rate */
/*! @{ */

#define ASRC_RS_UPDATE_RATE_RS_RATIO_RAMP_RATE_MASK (0x7FFFFFFFU)
#define ASRC_RS_UPDATE_RATE_RS_RATIO_RAMP_RATE_SHIFT (0U)
/*! RS_RATIO_RAMP_RATE - Resampling Ratio Ramp Rate */
#define ASRC_RS_UPDATE_RATE_RS_RATIO_RAMP_RATE(x) (((uint32_t)(((uint32_t)(x)) << ASRC_RS_UPDATE_RATE_RS_RATIO_RAMP_RATE_SHIFT)) & ASRC_RS_UPDATE_RATE_RS_RATIO_RAMP_RATE_MASK)
/*! @} */

/*! @name RS_CT_LOW - ASRC Resampling Center Tap Coefficient Low */
/*! @{ */

#define ASRC_RS_CT_LOW_RS_CT_LOW_MASK            (0xFFFFFFFFU)
#define ASRC_RS_CT_LOW_RS_CT_LOW_SHIFT           (0U)
/*! RS_CT_LOW - Resampling Center Tap Coefficient LSBs */
#define ASRC_RS_CT_LOW_RS_CT_LOW(x)              (((uint32_t)(((uint32_t)(x)) << ASRC_RS_CT_LOW_RS_CT_LOW_SHIFT)) & ASRC_RS_CT_LOW_RS_CT_LOW_MASK)
/*! @} */

/*! @name RS_CT_HIGH - ASRC Resampling Center Tap Coefficient High */
/*! @{ */

#define ASRC_RS_CT_HIGH_RS_CT_HIGH_MASK          (0xFFFFFFFFU)
#define ASRC_RS_CT_HIGH_RS_CT_HIGH_SHIFT         (0U)
/*! RS_CT_HIGH - Resampling Center Tap Coefficient MSBs */
#define ASRC_RS_CT_HIGH_RS_CT_HIGH(x)            (((uint32_t)(((uint32_t)(x)) << ASRC_RS_CT_HIGH_RS_CT_HIGH_SHIFT)) & ASRC_RS_CT_HIGH_RS_CT_HIGH_MASK)
/*! @} */

/*! @name PRE_COEFF_FIFO - ASRC Prefilter Coefficient FIFO */
/*! @{ */

#define ASRC_PRE_COEFF_FIFO_COEFF_DATA_MASK      (0xFFFFFFFFU)
#define ASRC_PRE_COEFF_FIFO_COEFF_DATA_SHIFT     (0U)
/*! COEFF_DATA - Coefficient Value For Prefilter */
#define ASRC_PRE_COEFF_FIFO_COEFF_DATA(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_PRE_COEFF_FIFO_COEFF_DATA_SHIFT)) & ASRC_PRE_COEFF_FIFO_COEFF_DATA_MASK)
/*! @} */

/*! @name CTX_RS_COEFF_MEM - ASRC Context Resampling Coefficient Memory */
/*! @{ */

#define ASRC_CTX_RS_COEFF_MEM_RS_COEFF_WDATA_MASK (0xFFFFFFFFU)
#define ASRC_CTX_RS_COEFF_MEM_RS_COEFF_WDATA_SHIFT (0U)
/*! RS_COEFF_WDATA - Resampling Coefficient Write Data */
#define ASRC_CTX_RS_COEFF_MEM_RS_COEFF_WDATA(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_RS_COEFF_MEM_RS_COEFF_WDATA_SHIFT)) & ASRC_CTX_RS_COEFF_MEM_RS_COEFF_WDATA_MASK)
/*! @} */

/*! @name CTX_RS_COEFF_CTRL - ASRC Context Resampling Coefficient Control */
/*! @{ */

#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_PTR_RST_MASK (0x1U)
#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_PTR_RST_SHIFT (0U)
/*! RS_COEFF_PTR_RST - Resampling Coefficient Write Pointer Reset */
#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_PTR_RST(x) (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_PTR_RST_SHIFT)) & ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_PTR_RST_MASK)

#define ASRC_CTX_RS_COEFF_CTRL_NUM_RES_TAPS_MASK (0x6U)
#define ASRC_CTX_RS_COEFF_CTRL_NUM_RES_TAPS_SHIFT (1U)
/*! NUM_RES_TAPS - Number of Resampling Coefficient Taps
 *  0b00..32-Tap Resampling Filter
 *  0b01..64-Tap Resampling Filter
 *  0b10..128-Tap Resampling Filter
 *  0b11..N/A
 */
#define ASRC_CTX_RS_COEFF_CTRL_NUM_RES_TAPS(x)   (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_RS_COEFF_CTRL_NUM_RES_TAPS_SHIFT)) & ASRC_CTX_RS_COEFF_CTRL_NUM_RES_TAPS_MASK)

#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_ADDR_MASK (0x7FF0000U)
#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_ADDR_SHIFT (16U)
/*! RS_COEFF_ADDR - Resampling Coefficient Address */
#define ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_ADDR(x)  (((uint32_t)(((uint32_t)(x)) << ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_ADDR_SHIFT)) & ASRC_CTX_RS_COEFF_CTRL_RS_COEFF_ADDR_MASK)
/*! @} */

/*! @name IRQ_CTRL - ASRC Interrupt Control */
/*! @{ */

#define ASRC_IRQ_CTRL_INFIFO_OVF_MASK_MASK       (0xFU)
#define ASRC_IRQ_CTRL_INFIFO_OVF_MASK_SHIFT      (0U)
/*! INFIFO_OVF_MASK - ASRC Input FIFO Overflow Mask
 *  0b0000..The INFIFO_OVF interrupt is enabled for Context 0 to 3.
 *  0b0001..The INFIFO_OVF interrupt is disabled for Context 0 and enabled for Context 1 to 3.
 *  0b0010..The INFIFO_OVF interrupt is disabled for Context 1 and enabled for Context 0, 2, and 3.
 *  0b0011-0b1110..The INFIFO_OVF interrupt is enabled for any context with a 1'b0 bit field.
 *  0b1111..The INFIFO_OVF interrupt is disabled for Context 0 to 3.
 */
#define ASRC_IRQ_CTRL_INFIFO_OVF_MASK(x)         (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_CTRL_INFIFO_OVF_MASK_SHIFT)) & ASRC_IRQ_CTRL_INFIFO_OVF_MASK_MASK)

#define ASRC_IRQ_CTRL_OUTFIFO_EMPTY_RD_MASK_MASK (0xF0U)
#define ASRC_IRQ_CTRL_OUTFIFO_EMPTY_RD_MASK_SHIFT (4U)
/*! OUTFIFO_EMPTY_RD_MASK - ASRC Output FIFO Empty Read Mask
 *  0b0000..The OUTFIFO_EMPTY_RD interrupt is enabled for Context 0 to 3.
 *  0b0001..The OUTFIFO_EMPTY_RD interrupt is disabled for Context 0 and enabled for Context 1 to 3.
 *  0b0010..The OUTFIFO_EMPTY_RD interrupt is disabled for Context 1 and enabled for Context 0, 2, and 3.
 *  0b0011-0b1110..The OUTFIFO_EMPTY_RD interrupt is enabled for any context with a 1'b0 bit field.
 *  0b1111..The OUTFIFO_EMPTY_RD interrupt is disabled for Context 0 to 3.
 */
#define ASRC_IRQ_CTRL_OUTFIFO_EMPTY_RD_MASK(x)   (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_CTRL_OUTFIFO_EMPTY_RD_MASK_SHIFT)) & ASRC_IRQ_CTRL_OUTFIFO_EMPTY_RD_MASK_MASK)

#define ASRC_IRQ_CTRL_RUN_STOP_DONE_MASK_MASK    (0xF00U)
#define ASRC_IRQ_CTRL_RUN_STOP_DONE_MASK_SHIFT   (8U)
/*! RUN_STOP_DONE_MASK - ASRC RUN STOP DONE MASK
 *  0b0000..The RUN_STOP_DONE interrupt is enabled for Context 0 to 3.
 *  0b0001..The RUN_STOP_DONE interrupt is disabled for Context 0 and enabled for Context 1 to 3.
 *  0b0010..The RUN_STOP_DONE interrupt is disabled for Context 1 and enabled for Context 0, 2, and 3.
 *  0b0011-0b1110..The RUN_STOP_DONE interrupt is enabled for any context with a 1'b0 bit field.
 *  0b1111..The RUN_STOP_DONE interrupt is disabled for Context 0 to 3.
 */
#define ASRC_IRQ_CTRL_RUN_STOP_DONE_MASK(x)      (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_CTRL_RUN_STOP_DONE_MASK_SHIFT)) & ASRC_IRQ_CTRL_RUN_STOP_DONE_MASK_MASK)
/*! @} */

/*! @name IRQ_FLAGS - ASRC Interrupt Status Flags */
/*! @{ */

#define ASRC_IRQ_FLAGS_INFIFO_OVF_MASK           (0xFU)
#define ASRC_IRQ_FLAGS_INFIFO_OVF_SHIFT          (0U)
/*! INFIFO_OVF - ASRC Input FIFO Overflow Flag
 *  0b0000..No INFIFO_OVF errors have been recorded.
 *  0b0001..The ASRC_WRFIFO0 has overflown.
 *  0b0010..The ASRC_WRFIFO1 has overflown.
 *  0b0011-0b1110..The ASRC_WRFIFOn has overflown. Where n = any bit position set to 0b1.
 *  0b1111..ASRC_WRFIFO0, ASRC_WRFIFO1, ASRC_WRFIFO2, and ASRC_WRFIFO3 have overflown.
 */
#define ASRC_IRQ_FLAGS_INFIFO_OVF(x)             (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_FLAGS_INFIFO_OVF_SHIFT)) & ASRC_IRQ_FLAGS_INFIFO_OVF_MASK)

#define ASRC_IRQ_FLAGS_OUTFIFO_EMPTY_RD_MASK     (0xF0U)
#define ASRC_IRQ_FLAGS_OUTFIFO_EMPTY_RD_SHIFT    (4U)
/*! OUTFIFO_EMPTY_RD - ASRC Output FIFO Empty Read Flag
 *  0b0000..No reads have been requested from an empty ASRC_RDFIFO.
 *  0b0001..A read has been requested from ASRC_RDFIFO0 when it was empty.
 *  0b0010..A read has been requested from ASRC_RDFIFO1 when it was empty.
 *  0b0011-0b1110..A read has been requested from ASRC_RDFIFOn when it was empty. n = any bit position with a 0b1.
 *  0b1111..A read has been requested from ASRC_RDFIFO0, ASRC_RDFIFO1, ASRC_RDFIFO2, and ASRC_RDFIFO3 while empty.
 */
#define ASRC_IRQ_FLAGS_OUTFIFO_EMPTY_RD(x)       (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_FLAGS_OUTFIFO_EMPTY_RD_SHIFT)) & ASRC_IRQ_FLAGS_OUTFIFO_EMPTY_RD_MASK)

#define ASRC_IRQ_FLAGS_RUN_STOP_DONE_MASK        (0xF00U)
#define ASRC_IRQ_FLAGS_RUN_STOP_DONE_SHIFT       (8U)
/*! RUN_STOP_DONE - ASRC RUN STOP DONE FLAG
 *  0b0000..No RUN_STOP operations have been completed.
 *  0b0001..The RUN_STOP operation for Context 0 has completed.
 *  0b0010..The RUN_STOP operation for Context 1 has completed.
 *  0b0011-0b1110..The RUN_STOP operation has completed for any context with a 1'b1 bit field.
 *  0b1111..The RUN_STOP operation has completed for Context 0 to 3.
 */
#define ASRC_IRQ_FLAGS_RUN_STOP_DONE(x)          (((uint32_t)(((uint32_t)(x)) << ASRC_IRQ_FLAGS_RUN_STOP_DONE_SHIFT)) & ASRC_IRQ_FLAGS_RUN_STOP_DONE_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_0 - ASRC Channel Status 0 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_0_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_0_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_0_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_0_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_0_CHN_STAT_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_1 - ASRC Channel Status 1 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_1_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_1_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_1_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_1_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_1_CHN_STAT_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_2 - ASRC Channel Status 2 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_2_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_2_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_2_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_2_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_2_CHN_STAT_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_3 - ASRC Channel Status 3 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_3_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_3_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_3_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_3_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_3_CHN_STAT_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_4 - ASRC Channel Status 4 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_4_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_4_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_4_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_4_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_4_CHN_STAT_MASK)
/*! @} */

/*! @name CHANNEL_STATUS_5 - ASRC Channel Status 5 */
/*! @{ */

#define ASRC_CHANNEL_STATUS_5_CHN_STAT_MASK      (0xFFFFFFFFU)
#define ASRC_CHANNEL_STATUS_5_CHN_STAT_SHIFT     (0U)
/*! CHN_STAT - Channel Status Data */
#define ASRC_CHANNEL_STATUS_5_CHN_STAT(x)        (((uint32_t)(((uint32_t)(x)) << ASRC_CHANNEL_STATUS_5_CHN_STAT_SHIFT)) & ASRC_CHANNEL_STATUS_5_CHN_STAT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ASRC_Register_Masks */


/*!
 * @}
 */ /* end of group ASRC_Peripheral_Access_Layer */


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


#endif  /* PERI_ASRC_H_ */

