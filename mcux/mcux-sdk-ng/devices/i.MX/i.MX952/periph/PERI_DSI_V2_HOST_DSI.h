/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DSI_V2_HOST_DSI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DSI_V2_HOST_DSI.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DSI_V2_HOST_DSI
 *
 * CMSIS Peripheral Access Layer for DSI_V2_HOST_DSI
 */

#if !defined(PERI_DSI_V2_HOST_DSI_H_)
#define PERI_DSI_V2_HOST_DSI_H_                  /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DSI_V2_HOST_DSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_DSI_Peripheral_Access_Layer DSI_V2_HOST_DSI Peripheral Access Layer
 * @{
 */

/** DSI_V2_HOST_DSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t DSI_GENERAL_CFG;                   /**< General Settings, offset: 0x0 */
  __IO uint32_t DSI_VCID_CFG;                      /**< TX Virtual Channel, offset: 0x4 */
  __IO uint32_t DSI_SCRAMBLING_CFG;                /**< Scrambling Configuration, offset: 0x8 */
  __IO uint32_t DSI_VID_TX_CFG;                    /**< Video Transmission Options, offset: 0xC */
  __IO uint32_t DSI_MAX_RPS_CFG;                   /**< Maximum Return Packet Size, offset: 0x10 */
  __IO uint32_t DSI_TEAR_EFFECT_CFG;               /**< Automatic Tear Effect, offset: 0x14 */
       uint8_t RESERVED_0[168];
  __IO uint32_t CRI_TX_HDR;                        /**< CRI TX headers., offset: 0xC0 */
  __O  uint32_t CRI_TX_PLD;                        /**< CRI TX Payload, offset: 0xC4 */
  __I  uint32_t CRI_RX_HDR;                        /**< CRI RX Header, offset: 0xC8 */
  __I  uint32_t CRI_RX_PLD;                        /**< CRI RX Payload, offset: 0xCC */
  __IO uint32_t CRI_TX_CTRL;                       /**< CRI TX Control, offset: 0xD0 */
       uint8_t RESERVED_1[12];
  __IO uint32_t CRI_FIFO_DEPTH_CFG;                /**< CRI External FIFOs Depth Configuration, offset: 0xE0 */
} DSI_V2_HOST_DSI_Type;

/* ----------------------------------------------------------------------------
   -- DSI_V2_HOST_DSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DSI_V2_HOST_DSI_Register_Masks DSI_V2_HOST_DSI Register Masks
 * @{
 */

/*! @name DSI_GENERAL_CFG - General Settings */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_EOTP_TX_EN_MASK (0x1U)
#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_EOTP_TX_EN_SHIFT (0U)
/*! EOTP_TX_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_EOTP_TX_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_GENERAL_CFG_EOTP_TX_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_GENERAL_CFG_EOTP_TX_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_BTA_EN_MASK (0x2U)
#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_BTA_EN_SHIFT (1U)
/*! BTA_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_GENERAL_CFG_BTA_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_GENERAL_CFG_BTA_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_GENERAL_CFG_BTA_EN_MASK)
/*! @} */

/*! @name DSI_VCID_CFG - TX Virtual Channel */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_VCID_CFG_TX_VCID_MASK (0x3U)
#define DSI_V2_HOST_DSI_DSI_VCID_CFG_TX_VCID_SHIFT (0U)
/*! TX_VCID
 *  0b00..
 */
#define DSI_V2_HOST_DSI_DSI_VCID_CFG_TX_VCID(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VCID_CFG_TX_VCID_SHIFT)) & DSI_V2_HOST_DSI_DSI_VCID_CFG_TX_VCID_MASK)
/*! @} */

/*! @name DSI_SCRAMBLING_CFG - Scrambling Configuration */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_EN_MASK (0x1U)
#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_EN_SHIFT (0U)
/*! SCRAMBLING_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_SEED_MASK (0xFFFF0000U)
#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_SEED_SHIFT (16U)
/*! SCRAMBLING_SEED
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_SEED(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_SEED_SHIFT)) & DSI_V2_HOST_DSI_DSI_SCRAMBLING_CFG_SCRAMBLING_SEED_MASK)
/*! @} */

/*! @name DSI_VID_TX_CFG - Video Transmission Options */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE_MASK (0x3U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE_SHIFT (0U)
/*! VID_MODE_TYPE
 *  0b00..Non-burst with sync pulses
 *  0b01..Non-burst with sync events
 *  0b10..Burst mode
 *  0b11..Burst mode
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_VID_MODE_TYPE_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_MASK (0x10U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_SHIFT (4U)
/*! BLK_HSA_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HSA_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_MASK (0x20U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_SHIFT (5U)
/*! BLK_HBP_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HBP_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_MASK (0x40U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_SHIFT (6U)
/*! BLK_HFP_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_HFP_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VSA_HS_EN_MASK (0x1000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VSA_HS_EN_SHIFT (12U)
/*! BLK_VSA_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VSA_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VSA_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VSA_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VBP_HS_EN_MASK (0x2000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VBP_HS_EN_SHIFT (13U)
/*! BLK_VBP_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VBP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VBP_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VBP_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VFP_HS_EN_MASK (0x4000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VFP_HS_EN_SHIFT (14U)
/*! BLK_VFP_HS_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VFP_HS_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VFP_HS_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_BLK_VFP_HS_EN_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_RESERVED_15_MASK (0x8000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_RESERVED_15_SHIFT (15U)
/*! RESERVED_15
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_RESERVED_15(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_RESERVED_15_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_RESERVED_15_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VSA_DISABLE_MASK (0x10000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VSA_DISABLE_SHIFT (16U)
/*! CMD_VSA_DISABLE
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VSA_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VSA_DISABLE_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VSA_DISABLE_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VBP_DISABLE_MASK (0x20000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VBP_DISABLE_SHIFT (17U)
/*! CMD_VBP_DISABLE
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VBP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VBP_DISABLE_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VBP_DISABLE_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_HFP_DISABLE_MASK (0x40000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_HFP_DISABLE_SHIFT (18U)
/*! CMD_HFP_DISABLE
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_HFP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_HFP_DISABLE_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_HFP_DISABLE_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VFP_DISABLE_MASK (0x80000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VFP_DISABLE_SHIFT (19U)
/*! CMD_VFP_DISABLE
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VFP_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VFP_DISABLE_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_CMD_VFP_DISABLE_MASK)

#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_LPDT_DISPLAY_CMD_EN_MASK (0x100000U)
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_LPDT_DISPLAY_CMD_EN_SHIFT (20U)
/*! LPDT_DISPLAY_CMD_EN
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_VID_TX_CFG_LPDT_DISPLAY_CMD_EN(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_VID_TX_CFG_LPDT_DISPLAY_CMD_EN_SHIFT)) & DSI_V2_HOST_DSI_DSI_VID_TX_CFG_LPDT_DISPLAY_CMD_EN_MASK)
/*! @} */

/*! @name DSI_MAX_RPS_CFG - Maximum Return Packet Size */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_MAX_RPS_CFG_MAX_RT_PKT_SZ_MASK (0xFFFFU)
#define DSI_V2_HOST_DSI_DSI_MAX_RPS_CFG_MAX_RT_PKT_SZ_SHIFT (0U)
/*! MAX_RT_PKT_SZ
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_DSI_DSI_MAX_RPS_CFG_MAX_RT_PKT_SZ(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_MAX_RPS_CFG_MAX_RT_PKT_SZ_SHIFT)) & DSI_V2_HOST_DSI_DSI_MAX_RPS_CFG_MAX_RT_PKT_SZ_MASK)
/*! @} */

/*! @name DSI_TEAR_EFFECT_CFG - Automatic Tear Effect */
/*! @{ */

#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_AUTO_TEAR_BTA_DISABLE_MASK (0x1U)
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_AUTO_TEAR_BTA_DISABLE_SHIFT (0U)
/*! AUTO_TEAR_BTA_DISABLE
 *  0b0..
 */
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_AUTO_TEAR_BTA_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_AUTO_TEAR_BTA_DISABLE_SHIFT)) & DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_AUTO_TEAR_BTA_DISABLE_MASK)

#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_TE_TYPE_HW_MASK (0x2U)
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_TE_TYPE_HW_SHIFT (1U)
/*! TE_TYPE_HW
 *  0b0..set_tear_on
 *  0b1..set_tear_scanline
 */
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_TE_TYPE_HW(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_TE_TYPE_HW_SHIFT)) & DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_TE_TYPE_HW_MASK)

#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_TEAR_ON_ARGS_HW_MASK (0xFF00U)
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_TEAR_ON_ARGS_HW_SHIFT (8U)
/*! SET_TEAR_ON_ARGS_HW
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_TEAR_ON_ARGS_HW(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_TEAR_ON_ARGS_HW_SHIFT)) & DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_TEAR_ON_ARGS_HW_MASK)

#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_SCANLINE_MASK (0xFFFF0000U)
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_SCANLINE_SHIFT (16U)
/*! SET_SCANLINE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_SCANLINE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_SCANLINE_SHIFT)) & DSI_V2_HOST_DSI_DSI_TEAR_EFFECT_CFG_SET_SCANLINE_MASK)
/*! @} */

/*! @name CRI_TX_HDR - CRI TX headers. */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE_MASK (0x3FU)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE_SHIFT (0U)
/*! DATA_TYPE
 *  0b000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_DATA_TYPE_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL_MASK (0xC0U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL_SHIFT (6U)
/*! VIRTUAL_CHANNEL
 *  0b00..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_VIRTUAL_CHANNEL_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB_MASK   (0xFF00U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB_SHIFT  (8U)
/*! WC_LSB
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_WC_LSB_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB_MASK   (0xFF0000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB_SHIFT  (16U)
/*! WC_MSB
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_WC_MSB_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_TX_MODE_MASK (0x1000000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_TX_MODE_SHIFT (24U)
/*! CMD_TX_MODE
 *  0b0..High-speed transmission.
 *  0b1..Low-power transmission.
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_TX_MODE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_TX_MODE_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_TX_MODE_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_27_25_MASK (0xE000000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_27_25_SHIFT (25U)
/*! RESERVED_27_25
 *  0b000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_27_25(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_27_25_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_27_25_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_RD_MASK (0x10000000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_RD_SHIFT (28U)
/*! CMD_HDR_RD
 *  0b0..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_RD(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_RD_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_RD_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_LONG_MASK (0x20000000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_LONG_SHIFT (29U)
/*! CMD_HDR_LONG
 *  0b0..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_LONG(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_LONG_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_CMD_HDR_LONG_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_31_30_MASK (0xC0000000U)
#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_31_30_SHIFT (30U)
/*! RESERVED_31_30
 *  0b00..
 */
#define DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_31_30(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_31_30_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_HDR_RESERVED_31_30_MASK)
/*! @} */

/*! @name CRI_TX_PLD - CRI TX Payload */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_0_MASK   (0xFFU)
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_0_SHIFT  (0U)
/*! BYTE_0
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_0(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_0_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_0_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_1_MASK   (0xFF00U)
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_1_SHIFT  (8U)
/*! BYTE_1
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_1(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_1_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_1_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_2_MASK   (0xFF0000U)
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_2_SHIFT  (16U)
/*! BYTE_2
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_2(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_2_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_2_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_3_MASK   (0xFF000000U)
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_3_SHIFT  (24U)
/*! BYTE_3
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_3(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_3_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_PLD_BYTE_3_MASK)
/*! @} */

/*! @name CRI_RX_HDR - CRI RX Header */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_RX_HDR_DATA_TYPE_MASK (0x3FU)
#define DSI_V2_HOST_DSI_CRI_RX_HDR_DATA_TYPE_SHIFT (0U)
/*! DATA_TYPE
 *  0b000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_HDR_DATA_TYPE(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_HDR_DATA_TYPE_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_HDR_DATA_TYPE_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_HDR_VIRTUAL_CHANNEL_MASK (0xC0U)
#define DSI_V2_HOST_DSI_CRI_RX_HDR_VIRTUAL_CHANNEL_SHIFT (6U)
/*! VIRTUAL_CHANNEL
 *  0b00..
 */
#define DSI_V2_HOST_DSI_CRI_RX_HDR_VIRTUAL_CHANNEL(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_HDR_VIRTUAL_CHANNEL_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_HDR_VIRTUAL_CHANNEL_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_LSB_MASK   (0xFF00U)
#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_LSB_SHIFT  (8U)
/*! WC_LSB
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_LSB(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_HDR_WC_LSB_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_HDR_WC_LSB_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_MSB_MASK   (0xFF0000U)
#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_MSB_SHIFT  (16U)
/*! WC_MSB
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_HDR_WC_MSB(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_HDR_WC_MSB_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_HDR_WC_MSB_MASK)
/*! @} */

/*! @name CRI_RX_PLD - CRI RX Payload */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_0_MASK   (0xFFU)
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_0_SHIFT  (0U)
/*! BYTE_0
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_0(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_0_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_0_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_1_MASK   (0xFF00U)
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_1_SHIFT  (8U)
/*! BYTE_1
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_1(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_1_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_1_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_2_MASK   (0xFF0000U)
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_2_SHIFT  (16U)
/*! BYTE_2
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_2(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_2_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_2_MASK)

#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_3_MASK   (0xFF000000U)
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_3_SHIFT  (24U)
/*! BYTE_3
 *  0b00000000..
 */
#define DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_3(x)     (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_3_SHIFT)) & DSI_V2_HOST_DSI_CRI_RX_PLD_BYTE_3_MASK)
/*! @} */

/*! @name CRI_TX_CTRL - CRI TX Control */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_HOLD_MASK (0x1U)
#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_HOLD_SHIFT (0U)
/*! CRI_HOLD
 *  0b0..Allows only 1 CRI packet to be written.
 *  0b1..Allows several CRI packets to be written while active.
 */
#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_HOLD(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_HOLD_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_HOLD_MASK)

#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_MODE_MASK (0x100U)
#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_MODE_SHIFT (8U)
/*! CRI_MODE
 *  0b0..Packet Stack Mode.
 *  0b1..Payload Merge Mode.
 */
#define DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_MODE(x)  (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_MODE_SHIFT)) & DSI_V2_HOST_DSI_CRI_TX_CTRL_CRI_MODE_MASK)
/*! @} */

/*! @name CRI_FIFO_DEPTH_CFG - CRI External FIFOs Depth Configuration */
/*! @{ */

#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_WR_VALUE_MASK (0xFFFFU)
#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_WR_VALUE_SHIFT (0U)
/*! WR_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_WR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_WR_VALUE_SHIFT)) & DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_WR_VALUE_MASK)

#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_RD_VALUE_MASK (0xFFFF0000U)
#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_RD_VALUE_SHIFT (16U)
/*! RD_VALUE
 *  0b0000000000000000..
 */
#define DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_RD_VALUE(x) (((uint32_t)(((uint32_t)(x)) << DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_RD_VALUE_SHIFT)) & DSI_V2_HOST_DSI_CRI_FIFO_DEPTH_CFG_RD_VALUE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_DSI_Register_Masks */


/*!
 * @}
 */ /* end of group DSI_V2_HOST_DSI_Peripheral_Access_Layer */


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


#endif  /* PERI_DSI_V2_HOST_DSI_H_ */

