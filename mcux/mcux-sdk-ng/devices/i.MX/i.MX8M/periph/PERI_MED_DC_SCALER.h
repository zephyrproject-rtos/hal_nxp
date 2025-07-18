/*
** ###################################################################
**     Processors:          MIMX8MD6CVAHZ_ca53
**                          MIMX8MD6CVAHZ_cm4
**                          MIMX8MD6DVAJZ_ca53
**                          MIMX8MD6DVAJZ_cm4
**                          MIMX8MD7CVAHZ_ca53
**                          MIMX8MD7CVAHZ_cm4
**                          MIMX8MD7DVAJZ_ca53
**                          MIMX8MD7DVAJZ_cm4
**                          MIMX8MQ5CVAHZ_ca53
**                          MIMX8MQ5CVAHZ_cm4
**                          MIMX8MQ5DVAJZ_ca53
**                          MIMX8MQ5DVAJZ_cm4
**                          MIMX8MQ6CVAHZ_ca53
**                          MIMX8MQ6CVAHZ_cm4
**                          MIMX8MQ6DVAJZ_ca53
**                          MIMX8MQ6DVAJZ_cm4
**                          MIMX8MQ7CVAHZ_ca53
**                          MIMX8MQ7CVAHZ_cm4
**                          MIMX8MQ7DVAJZ_ca53
**                          MIMX8MQ7DVAJZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MED_DC_SCALER
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2017-01-10)
**         Initial version.
**     - rev. 2.0 (2017-04-27)
**         Rev.B Header EAR1
**     - rev. 3.0 (2017-07-19)
**         Rev.C Header EAR2
**     - rev. 4.0 (2018-01-26)
**         Rev.D Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MED_DC_SCALER.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MED_DC_SCALER
 *
 * CMSIS Peripheral Access Layer for MED_DC_SCALER
 */

#if !defined(PERI_MED_DC_SCALER_H_)
#define PERI_MED_DC_SCALER_H_                    /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MD6CVAHZ_ca53) || defined(CPU_MIMX8MD6DVAJZ_ca53))
#include "MIMX8MD6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD6CVAHZ_cm4) || defined(CPU_MIMX8MD6DVAJZ_cm4))
#include "MIMX8MD6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_ca53) || defined(CPU_MIMX8MD7DVAJZ_ca53))
#include "MIMX8MD7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MD7CVAHZ_cm4) || defined(CPU_MIMX8MD7DVAJZ_cm4))
#include "MIMX8MD7_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_ca53) || defined(CPU_MIMX8MQ5DVAJZ_ca53))
#include "MIMX8MQ5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ5CVAHZ_cm4) || defined(CPU_MIMX8MQ5DVAJZ_cm4))
#include "MIMX8MQ5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_ca53) || defined(CPU_MIMX8MQ6DVAJZ_ca53))
#include "MIMX8MQ6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ6CVAHZ_cm4) || defined(CPU_MIMX8MQ6DVAJZ_cm4))
#include "MIMX8MQ6_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_ca53) || defined(CPU_MIMX8MQ7DVAJZ_ca53))
#include "MIMX8MQ7_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MQ7CVAHZ_cm4) || defined(CPU_MIMX8MQ7DVAJZ_cm4))
#include "MIMX8MQ7_cm4_COMMON.h"
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
   -- MED_DC_SCALER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MED_DC_SCALER_Peripheral_Access_Layer MED_DC_SCALER Peripheral Access Layer
 * @{
 */

/** MED_DC_SCALER - Register Layout Typedef */
typedef struct {
  __IO uint32_t SCALE_CTRL;                        /**< Scale Control Register, offset: 0x0 */
  __IO uint32_t SCALE_OFIFO_CTRL;                  /**< Scale Output FIFO Control Register, offset: 0x4 */
  __IO uint32_t SCALE_SRC_DATA_CTRL;               /**< Scale Source Data Control Register, offset: 0x8 */
  __IO uint32_t SCALE_BIT_DEPTH;                   /**< Scale Bit Depth Control Register, offset: 0xC */
  __IO uint32_t SCALE_SRC_FORMAT;                  /**< Scale Source Format Control Register, offset: 0x10 */
  __IO uint32_t SCALE_DST_FORMAT;                  /**< Scale Destination Format Control Register, offset: 0x14 */
  __IO uint32_t SCALE_SRC_LUMA_RES;                /**< Scale Source Luma Resolution Register, offset: 0x18 */
  __IO uint32_t SCALE_SRC_CHROMA_RES;              /**< Scale Source Chroma Resolution Register, offset: 0x1C */
  __IO uint32_t SCALE_DST_LUMA_RES;                /**< Scale Destination Luma Resolution Register, offset: 0x20 */
  __IO uint32_t SCALE_DST_CHROMA_RES;              /**< Scale Destination Chroma Resolution Register, offset: 0x24 */
       uint8_t RESERVED_0[32];
  __IO uint32_t SCALE_V_LUMA_START;                /**< Scale Vertical Luma Start Register, offset: 0x48 */
  __IO uint32_t SCALE_V_LUMA_INC;                  /**< Scale Vertical Luma Increment Register, offset: 0x4C */
  __IO uint32_t SCALE_H_LUMA_START;                /**< Scale Horizontal Luma Start Register, offset: 0x50 */
  __IO uint32_t SCALE_H_LUMA_INC;                  /**< Scale Horizontal Luma Increment Register, offset: 0x54 */
  __IO uint32_t SCALE_V_CHROMA_START;              /**< Scale Vertical Chroma Start Register, offset: 0x58 */
  __IO uint32_t SCALE_V_CHROMA_INC;                /**< Scale Vertical Chroma Increment Register, offset: 0x5C */
  __IO uint32_t SCALE_H_CHROMA_START;              /**< Scale Horizontal Chroma Start Register, offset: 0x60 */
  __IO uint32_t SCALE_H_CHROMA_INC;                /**< Scale Horizontal Chroma Increment Register, offset: 0x64 */
       uint8_t RESERVED_1[24];
  __IO uint32_t SCALE_COEF_ARRAY;                  /**< Scale Coefficient Memory Array, offset: 0x80 */
} MED_DC_SCALER_Type;

/* ----------------------------------------------------------------------------
   -- MED_DC_SCALER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MED_DC_SCALER_Register_Masks MED_DC_SCALER Register Masks
 * @{
 */

/*! @name SCALE_CTRL - Scale Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALER_MASK (0x1U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALER_SHIFT (0U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALER(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALER_SHIFT)) & MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALER_MASK)

#define MED_DC_SCALER_SCALE_CTRL_ENABLE_REPEAT_MASK (0x10U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_REPEAT_SHIFT (4U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_REPEAT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_CTRL_ENABLE_REPEAT_SHIFT)) & MED_DC_SCALER_SCALE_CTRL_ENABLE_REPEAT_MASK)

#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALE2MEM_MASK (0x100U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALE2MEM_SHIFT (8U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALE2MEM(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALE2MEM_SHIFT)) & MED_DC_SCALER_SCALE_CTRL_ENABLE_SCALE2MEM_MASK)

#define MED_DC_SCALER_SCALE_CTRL_ENABLE_MEM2OFIFO_MASK (0x1000U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_MEM2OFIFO_SHIFT (12U)
#define MED_DC_SCALER_SCALE_CTRL_ENABLE_MEM2OFIFO(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_CTRL_ENABLE_MEM2OFIFO_SHIFT)) & MED_DC_SCALER_SCALE_CTRL_ENABLE_MEM2OFIFO_MASK)
/*! @} */

/*! @name SCALE_OFIFO_CTRL - Scale Output FIFO Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_LOW_THRESH_MASK (0x3FFU)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_LOW_THRESH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_LOW_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_LOW_THRESH_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_LOW_THRESH_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_HIGH_THRESH_MASK (0x3FF0000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_HIGH_THRESH_SHIFT (16U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_HIGH_THRESH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_HIGH_THRESH_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_OFIFO_HIGH_THRESH_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_UNDERRUN_DETECT_MASK (0x4000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_UNDERRUN_DETECT_SHIFT (26U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_UNDERRUN_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_UNDERRUN_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_UNDERRUN_DETECT_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_LOW_THRESH_DETECT_MASK (0x8000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_LOW_THRESH_DETECT_SHIFT (27U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_LOW_THRESH_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_LOW_THRESH_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_LOW_THRESH_DETECT_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_HIGH_THRESH_DETECT_MASK (0x10000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_HIGH_THRESH_DETECT_SHIFT (28U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_HIGH_THRESH_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_HIGH_THRESH_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_CLEAR_HIGH_THRESH_DETECT_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_UNDERRUN_DETECT_MASK (0x20000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_UNDERRUN_DETECT_SHIFT (29U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_UNDERRUN_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_UNDERRUN_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_UNDERRUN_DETECT_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_LOW_THRESH_DETECT_MASK (0x40000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_LOW_THRESH_DETECT_SHIFT (30U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_LOW_THRESH_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_LOW_THRESH_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_LOW_THRESH_DETECT_MASK)

#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_HIGH_THRESH_DETECT_MASK (0x80000000U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_HIGH_THRESH_DETECT_SHIFT (31U)
#define MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_HIGH_THRESH_DETECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_HIGH_THRESH_DETECT_SHIFT)) & MED_DC_SCALER_SCALE_OFIFO_CTRL_ENABLE_HIGH_THRESH_DETECT_MASK)
/*! @} */

/*! @name SCALE_SRC_DATA_CTRL - Scale Source Data Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_SRC_SELECT_MASK (0x1U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_SRC_SELECT_SHIFT (0U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_SRC_SELECT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_DATA_CTRL_SRC_SELECT_SHIFT)) & MED_DC_SCALER_SCALE_SRC_DATA_CTRL_SRC_SELECT_MASK)

#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_RTRAM_LINES_PER_BANK_MASK (0x2U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_RTRAM_LINES_PER_BANK_SHIFT (1U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_RTRAM_LINES_PER_BANK(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_DATA_CTRL_RTRAM_LINES_PER_BANK_SHIFT)) & MED_DC_SCALER_SCALE_SRC_DATA_CTRL_RTRAM_LINES_PER_BANK_MASK)

#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_Y_UV_BYTE_SWAP_MASK (0x10U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_Y_UV_BYTE_SWAP_SHIFT (4U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_Y_UV_BYTE_SWAP(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_DATA_CTRL_Y_UV_BYTE_SWAP_SHIFT)) & MED_DC_SCALER_SCALE_SRC_DATA_CTRL_Y_UV_BYTE_SWAP_MASK)

#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_A2R10G10B10_FORMAT_MASK (0xF00U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_A2R10G10B10_FORMAT_SHIFT (8U)
#define MED_DC_SCALER_SCALE_SRC_DATA_CTRL_A2R10G10B10_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_DATA_CTRL_A2R10G10B10_FORMAT_SHIFT)) & MED_DC_SCALER_SCALE_SRC_DATA_CTRL_A2R10G10B10_FORMAT_MASK)
/*! @} */

/*! @name SCALE_BIT_DEPTH - Scale Bit Depth Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_BIT_DEPTH_LUMA_BIT_DEPTH_MASK (0x3U)
#define MED_DC_SCALER_SCALE_BIT_DEPTH_LUMA_BIT_DEPTH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_BIT_DEPTH_LUMA_BIT_DEPTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_BIT_DEPTH_LUMA_BIT_DEPTH_SHIFT)) & MED_DC_SCALER_SCALE_BIT_DEPTH_LUMA_BIT_DEPTH_MASK)

#define MED_DC_SCALER_SCALE_BIT_DEPTH_CHROMA_BIT_DEPTH_MASK (0x30U)
#define MED_DC_SCALER_SCALE_BIT_DEPTH_CHROMA_BIT_DEPTH_SHIFT (4U)
#define MED_DC_SCALER_SCALE_BIT_DEPTH_CHROMA_BIT_DEPTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_BIT_DEPTH_CHROMA_BIT_DEPTH_SHIFT)) & MED_DC_SCALER_SCALE_BIT_DEPTH_CHROMA_BIT_DEPTH_MASK)
/*! @} */

/*! @name SCALE_SRC_FORMAT - Scale Source Format Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_SRC_FORMAT_SRC_FORMAT_MASK (0x3U)
#define MED_DC_SCALER_SCALE_SRC_FORMAT_SRC_FORMAT_SHIFT (0U)
#define MED_DC_SCALER_SCALE_SRC_FORMAT_SRC_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_FORMAT_SRC_FORMAT_SHIFT)) & MED_DC_SCALER_SCALE_SRC_FORMAT_SRC_FORMAT_MASK)
/*! @} */

/*! @name SCALE_DST_FORMAT - Scale Destination Format Control Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_DST_FORMAT_DST_FORMAT_MASK (0x3U)
#define MED_DC_SCALER_SCALE_DST_FORMAT_DST_FORMAT_SHIFT (0U)
#define MED_DC_SCALER_SCALE_DST_FORMAT_DST_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_DST_FORMAT_DST_FORMAT_SHIFT)) & MED_DC_SCALER_SCALE_DST_FORMAT_DST_FORMAT_MASK)
/*! @} */

/*! @name SCALE_SRC_LUMA_RES - Scale Source Luma Resolution Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_WIDTH_MASK (0xFFFU)
#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_WIDTH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_LUMA_RES_WIDTH_SHIFT)) & MED_DC_SCALER_SCALE_SRC_LUMA_RES_WIDTH_MASK)

#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_HEIGHT_MASK (0xFFF0000U)
#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_HEIGHT_SHIFT (16U)
#define MED_DC_SCALER_SCALE_SRC_LUMA_RES_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_LUMA_RES_HEIGHT_SHIFT)) & MED_DC_SCALER_SCALE_SRC_LUMA_RES_HEIGHT_MASK)
/*! @} */

/*! @name SCALE_SRC_CHROMA_RES - Scale Source Chroma Resolution Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_WIDTH_MASK (0xFFFU)
#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_WIDTH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_CHROMA_RES_WIDTH_SHIFT)) & MED_DC_SCALER_SCALE_SRC_CHROMA_RES_WIDTH_MASK)

#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_HEIGHT_MASK (0xFFF0000U)
#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_HEIGHT_SHIFT (16U)
#define MED_DC_SCALER_SCALE_SRC_CHROMA_RES_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_SRC_CHROMA_RES_HEIGHT_SHIFT)) & MED_DC_SCALER_SCALE_SRC_CHROMA_RES_HEIGHT_MASK)
/*! @} */

/*! @name SCALE_DST_LUMA_RES - Scale Destination Luma Resolution Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_DST_LUMA_RES_WIDTH_MASK (0xFFFU)
#define MED_DC_SCALER_SCALE_DST_LUMA_RES_WIDTH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_DST_LUMA_RES_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_DST_LUMA_RES_WIDTH_SHIFT)) & MED_DC_SCALER_SCALE_DST_LUMA_RES_WIDTH_MASK)

#define MED_DC_SCALER_SCALE_DST_LUMA_RES_HEIGHT_MASK (0xFFF0000U)
#define MED_DC_SCALER_SCALE_DST_LUMA_RES_HEIGHT_SHIFT (16U)
#define MED_DC_SCALER_SCALE_DST_LUMA_RES_HEIGHT(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_DST_LUMA_RES_HEIGHT_SHIFT)) & MED_DC_SCALER_SCALE_DST_LUMA_RES_HEIGHT_MASK)
/*! @} */

/*! @name SCALE_DST_CHROMA_RES - Scale Destination Chroma Resolution Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_DST_CHROMA_RES_WIDTH_MASK (0xFFFU)
#define MED_DC_SCALER_SCALE_DST_CHROMA_RES_WIDTH_SHIFT (0U)
#define MED_DC_SCALER_SCALE_DST_CHROMA_RES_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_DST_CHROMA_RES_WIDTH_SHIFT)) & MED_DC_SCALER_SCALE_DST_CHROMA_RES_WIDTH_MASK)
/*! @} */

/*! @name SCALE_V_LUMA_START - Scale Vertical Luma Start Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_V_LUMA_START_V_START_MASK (0x3FFFFFFU)
#define MED_DC_SCALER_SCALE_V_LUMA_START_V_START_SHIFT (0U)
#define MED_DC_SCALER_SCALE_V_LUMA_START_V_START(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_V_LUMA_START_V_START_SHIFT)) & MED_DC_SCALER_SCALE_V_LUMA_START_V_START_MASK)
/*! @} */

/*! @name SCALE_V_LUMA_INC - Scale Vertical Luma Increment Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_V_LUMA_INC_V_INC_MASK (0xFFFFFU)
#define MED_DC_SCALER_SCALE_V_LUMA_INC_V_INC_SHIFT (0U)
#define MED_DC_SCALER_SCALE_V_LUMA_INC_V_INC(x)  (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_V_LUMA_INC_V_INC_SHIFT)) & MED_DC_SCALER_SCALE_V_LUMA_INC_V_INC_MASK)
/*! @} */

/*! @name SCALE_H_LUMA_START - Scale Horizontal Luma Start Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_H_LUMA_START_H_START_MASK (0x3FFFFFFU)
#define MED_DC_SCALER_SCALE_H_LUMA_START_H_START_SHIFT (0U)
#define MED_DC_SCALER_SCALE_H_LUMA_START_H_START(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_H_LUMA_START_H_START_SHIFT)) & MED_DC_SCALER_SCALE_H_LUMA_START_H_START_MASK)
/*! @} */

/*! @name SCALE_H_LUMA_INC - Scale Horizontal Luma Increment Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_H_LUMA_INC_H_INC_MASK (0xFFFFFU)
#define MED_DC_SCALER_SCALE_H_LUMA_INC_H_INC_SHIFT (0U)
#define MED_DC_SCALER_SCALE_H_LUMA_INC_H_INC(x)  (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_H_LUMA_INC_H_INC_SHIFT)) & MED_DC_SCALER_SCALE_H_LUMA_INC_H_INC_MASK)
/*! @} */

/*! @name SCALE_V_CHROMA_START - Scale Vertical Chroma Start Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_V_CHROMA_START_V_START_MASK (0x3FFFFFFU)
#define MED_DC_SCALER_SCALE_V_CHROMA_START_V_START_SHIFT (0U)
#define MED_DC_SCALER_SCALE_V_CHROMA_START_V_START(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_V_CHROMA_START_V_START_SHIFT)) & MED_DC_SCALER_SCALE_V_CHROMA_START_V_START_MASK)
/*! @} */

/*! @name SCALE_V_CHROMA_INC - Scale Vertical Chroma Increment Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_V_CHROMA_INC_V_INC_MASK (0xFFFFFU)
#define MED_DC_SCALER_SCALE_V_CHROMA_INC_V_INC_SHIFT (0U)
#define MED_DC_SCALER_SCALE_V_CHROMA_INC_V_INC(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_V_CHROMA_INC_V_INC_SHIFT)) & MED_DC_SCALER_SCALE_V_CHROMA_INC_V_INC_MASK)
/*! @} */

/*! @name SCALE_H_CHROMA_START - Scale Horizontal Chroma Start Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_H_CHROMA_START_H_START_MASK (0x3FFFFFFU)
#define MED_DC_SCALER_SCALE_H_CHROMA_START_H_START_SHIFT (0U)
#define MED_DC_SCALER_SCALE_H_CHROMA_START_H_START(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_H_CHROMA_START_H_START_SHIFT)) & MED_DC_SCALER_SCALE_H_CHROMA_START_H_START_MASK)
/*! @} */

/*! @name SCALE_H_CHROMA_INC - Scale Horizontal Chroma Increment Register */
/*! @{ */

#define MED_DC_SCALER_SCALE_H_CHROMA_INC_H_INC_MASK (0xFFFFFU)
#define MED_DC_SCALER_SCALE_H_CHROMA_INC_H_INC_SHIFT (0U)
#define MED_DC_SCALER_SCALE_H_CHROMA_INC_H_INC(x) (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_H_CHROMA_INC_H_INC_SHIFT)) & MED_DC_SCALER_SCALE_H_CHROMA_INC_H_INC_MASK)
/*! @} */

/*! @name SCALE_COEF_ARRAY - Scale Coefficient Memory Array */
/*! @{ */

#define MED_DC_SCALER_SCALE_COEF_ARRAY_COEF_MASK (0xFFFU)
#define MED_DC_SCALER_SCALE_COEF_ARRAY_COEF_SHIFT (0U)
#define MED_DC_SCALER_SCALE_COEF_ARRAY_COEF(x)   (((uint32_t)(((uint32_t)(x)) << MED_DC_SCALER_SCALE_COEF_ARRAY_COEF_SHIFT)) & MED_DC_SCALER_SCALE_COEF_ARRAY_COEF_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MED_DC_SCALER_Register_Masks */


/*!
 * @}
 */ /* end of group MED_DC_SCALER_Peripheral_Access_Layer */


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


#endif  /* PERI_MED_DC_SCALER_H_ */

