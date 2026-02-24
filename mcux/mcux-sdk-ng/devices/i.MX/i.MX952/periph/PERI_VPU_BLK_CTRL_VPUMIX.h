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
**         CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
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
 * @file PERI_VPU_BLK_CTRL_VPUMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
 *
 * CMSIS Peripheral Access Layer for VPU_BLK_CTRL_VPUMIX
 */

#if !defined(PERI_VPU_BLK_CTRL_VPUMIX_H_)
#define PERI_VPU_BLK_CTRL_VPUMIX_H_              /**< Symbol preventing repeated inclusion */

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
   -- VPU_BLK_CTRL_VPUMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTRL_VPUMIX_Peripheral_Access_Layer VPU_BLK_CTRL_VPUMIX Peripheral Access Layer
 * @{
 */

/** VPU_BLK_CTRL_VPUMIX - Register Layout Typedef */
typedef struct {
  __I  uint32_t VPU_STATUS;                        /**< VPU Status, offset: 0x0 */
  __I  uint32_t INIT_PENDING_TX;                   /**< Initiator Pending Transaction, offset: 0x4 */
  __IO uint32_t VPU_ATU_PM_EN;                     /**< VPU ATU Performance Monitor Enable, offset: 0x8 */
  __IO uint32_t FORCE_ON_OFF;                      /**< LPCG Configuration Control, offset: 0xC */
  __IO uint32_t APB_ERROR_CTRL;                    /**< disable ppmr feature for error response, offset: 0x10 */
} VPU_BLK_CTRL_VPUMIX_Type;

/* ----------------------------------------------------------------------------
   -- VPU_BLK_CTRL_VPUMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTRL_VPUMIX_Register_Masks VPU_BLK_CTRL_VPUMIX Register Masks
 * @{
 */

/*! @name VPU_STATUS - VPU Status */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_WAVE511_IDLE_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_WAVE511_IDLE_SHIFT (0U)
/*! WAVE511_IDLE - WAVE511 Idle Status
 *  0b0..Not idle
 *  0b1..Idle
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_WAVE511_IDLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_STATUS_WAVE511_IDLE_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_STATUS_WAVE511_IDLE_MASK)

#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_CODA980_IDLE_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_CODA980_IDLE_SHIFT (1U)
/*! CODA980_IDLE - CODA980 Idle Status
 *  0b0..Not idle
 *  0b1..Idle
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_STATUS_CODA980_IDLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_STATUS_CODA980_IDLE_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_STATUS_CODA980_IDLE_MASK)
/*! @} */

/*! @name INIT_PENDING_TX - Initiator Pending Transaction */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_SHIFT (0U)
/*! WAVE511_Primary - WAVE511 Primary NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_V0_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_V0_SHIFT (1U)
/*! WAVE511_Primary_V0 - WAVE511 Primary V0 NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_V0(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_V0_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Primary_V0_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_BWB_WR_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_BWB_WR_SHIFT (2U)
/*! WAVE511_BWB_WR - WAVE511 BWB WR NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_BWB_WR(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_BWB_WR_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_BWB_WR_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Secondary_MASK (0x8U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Secondary_SHIFT (3U)
/*! WAVE511_Secondary - WAVE511 Secondary NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Secondary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Secondary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_WAVE511_Secondary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Primary_MASK (0x10U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Primary_SHIFT (4U)
/*! CODA980_Primary - CODA980 Primary NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Primary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Primary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Primary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Secondary_MASK (0x20U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Secondary_SHIFT (5U)
/*! CODA980_Secondary - CODA980 Secondary NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Secondary(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Secondary_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_CODA980_Secondary_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_MASK (0x40U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_SHIFT (6U)
/*! JPEG_Encode - JPEG Encoder NIUs Pending Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Encode_MASK)

#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_MASK (0x80U)
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_SHIFT (7U)
/*! JPEG_Decode - JPEG Decoder NIUs Pending Transactions Status
 *  0b0..No pending transaction
 *  0b1..Pending transaction
 */
#define VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_SHIFT)) & VPU_BLK_CTRL_VPUMIX_INIT_PENDING_TX_JPEG_Decode_MASK)
/*! @} */

/*! @name VPU_ATU_PM_EN - VPU ATU Performance Monitor Enable */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_PRIM_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_PRIM_SHIFT (0U)
/*! CODA_PRIM - CODA980 Primary Bus Performance Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_PRIM(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_PRIM_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_PRIM_MASK)

#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_SEC_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_SEC_SHIFT (1U)
/*! CODA_SEC - CODA980 Secondary Bus Performance Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_SEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_SEC_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_CODA_SEC_MASK)

#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_ENC_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_ENC_SHIFT (2U)
/*! JPEG_ENC - JPEG Encoder Performance Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_ENC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_ENC_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_ENC_MASK)

#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_DEC_MASK (0x8U)
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_DEC_SHIFT (3U)
/*! JPEG_DEC - JPEG Decoder Performance Monitor Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_DEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_DEC_SHIFT)) & VPU_BLK_CTRL_VPUMIX_VPU_ATU_PM_EN_JPEG_DEC_MASK)
/*! @} */

/*! @name FORCE_ON_OFF - LPCG Configuration Control */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_coda980_ipc_clk_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_coda980_ipc_clk_SHIFT (0U)
/*! coda980_ipc_clk - Control force_on_off of coda980_ipc_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_coda980_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_coda980_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_coda980_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_coda980_ipc_clk_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_coda980_ipc_clk_SHIFT (1U)
/*! sel_coda980_ipc_clk - Control force_on_off_sel of coda980_ipc_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_coda980_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_coda980_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_coda980_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_dec_ipc_clk_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_dec_ipc_clk_SHIFT (2U)
/*! jpeg_dec_ipc_clk - Control force_on_off of jpeg_dec_ipc_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_dec_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_dec_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_dec_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_dec_ipc_clk_MASK (0x8U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_dec_ipc_clk_SHIFT (3U)
/*! sel_jpeg_dec_ipc_clk - Control force_on_off_sel of jpeg_dec_ipc_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_dec_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_dec_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_dec_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_enc_ipc_clk_MASK (0x10U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_enc_ipc_clk_SHIFT (4U)
/*! jpeg_enc_ipc_clk - Control force_on_off of jpeg_enc_ipc_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_enc_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_enc_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_jpeg_enc_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_enc_ipc_clk_MASK (0x20U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_enc_ipc_clk_SHIFT (5U)
/*! sel_jpeg_enc_ipc_clk - Control force_on_off_sel of jpeg_enc_ipc_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_enc_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_enc_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_jpeg_enc_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_ssi_ipc_clk_MASK (0x40U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_ssi_ipc_clk_SHIFT (6U)
/*! ssi_ipc_clk - Control force_on_off of ssi_ipc_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_ssi_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_ssi_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_ssi_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_ssi_ipc_clk_MASK (0x80U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_ssi_ipc_clk_SHIFT (7U)
/*! sel_ssi_ipc_clk - Control force_on_off_sel of ssi_ipc_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_ssi_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_ssi_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_ssi_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_wave511_ipc_clk_MASK (0x100U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_wave511_ipc_clk_SHIFT (8U)
/*! wave511_ipc_clk - Control force_on_off of wave511_ipc_clk
 *  0b0..Disables
 *  0b1..Enables
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_wave511_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_wave511_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_wave511_ipc_clk_MASK)

#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_wave511_ipc_clk_MASK (0x200U)
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_wave511_ipc_clk_SHIFT (9U)
/*! sel_wave511_ipc_clk - Control force_on_off_sel of wave511_ipc_clk
 *  0b0..Not selected
 *  0b1..Selected
 */
#define VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_wave511_ipc_clk(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_wave511_ipc_clk_SHIFT)) & VPU_BLK_CTRL_VPUMIX_FORCE_ON_OFF_sel_wave511_ipc_clk_MASK)
/*! @} */

/*! @name APB_ERROR_CTRL - disable ppmr feature for error response */
/*! @{ */

#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_DEC_PPMR_CTRL_MASK (0x1U)
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_DEC_PPMR_CTRL_SHIFT (0U)
/*! JPEG_DEC_PPMR_CTRL - JPEG_DEC disable ppmr
 *  0b0..not disable
 *  0b1..disable
 */
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_DEC_PPMR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_DEC_PPMR_CTRL_SHIFT)) & VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_DEC_PPMR_CTRL_MASK)

#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_ENC_PPMR_CTRL_MASK (0x2U)
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_ENC_PPMR_CTRL_SHIFT (1U)
/*! JPEG_ENC_PPMR_CTRL - JPEG_ENC disable ppmr
 *  0b0..not disable
 *  0b1..disable
 */
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_ENC_PPMR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_ENC_PPMR_CTRL_SHIFT)) & VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_JPEG_ENC_PPMR_CTRL_MASK)

#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_WAVE511_PPMR_CTRL_MASK (0x4U)
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_WAVE511_PPMR_CTRL_SHIFT (2U)
/*! WAVE511_PPMR_CTRL - WAVE511 disable ppmr
 *  0b0..not disable
 *  0b1..disable
 */
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_WAVE511_PPMR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_WAVE511_PPMR_CTRL_SHIFT)) & VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_WAVE511_PPMR_CTRL_MASK)

#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_CODA980_PPMR_CTRL_MASK (0x8U)
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_CODA980_PPMR_CTRL_SHIFT (3U)
/*! CODA980_PPMR_CTRL - CODA980 disable ppmr
 *  0b0..not disable
 *  0b1..disable
 */
#define VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_CODA980_PPMR_CTRL(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_CODA980_PPMR_CTRL_SHIFT)) & VPU_BLK_CTRL_VPUMIX_APB_ERROR_CTRL_CODA980_PPMR_CTRL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_BLK_CTRL_VPUMIX_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_BLK_CTRL_VPUMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_BLK_CTRL_VPUMIX_H_ */

