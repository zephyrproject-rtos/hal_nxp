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
**         CMSIS Peripheral Access Layer for VPU_BLK_CTL
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
 * @file PERI_VPU_BLK_CTL.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_BLK_CTL
 *
 * CMSIS Peripheral Access Layer for VPU_BLK_CTL
 */

#if !defined(PERI_VPU_BLK_CTL_H_)
#define PERI_VPU_BLK_CTL_H_                      /**< Symbol preventing repeated inclusion */

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
   -- VPU_BLK_CTL Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTL_Peripheral_Access_Layer VPU_BLK_CTL Peripheral Access Layer
 * @{
 */

/** VPU_BLK_CTL - Register Layout Typedef */
typedef struct {
  __IO uint32_t BLK_SFT_RSTN_CSR;                  /**< VPUMIX block soft reset control, offset: 0x0 */
  __IO uint32_t BLK_CLK_EN_CSR;                    /**< VPUMIX block clock enable control, offset: 0x4 */
  __IO uint32_t G1_FUSE_DEC_CSR;                   /**< VPUMIX G1 fuse_dec control, offset: 0x8 */
  __IO uint32_t G1_FUSE_PP_CSR;                    /**< VPUMIX G1 fuse_pp control, offset: 0xC */
  __IO uint32_t G2_FUSE_DEC_CSR;                   /**< VPUMIX G2 fuse_dec control, offset: 0x10 */
  __IO uint32_t VC8000E_FUSE_ENC_CSR;              /**< VPUMIX VC8000E fuse_enc control, offset: 0x14 */
  __IO uint32_t VPU_CACHE_EN_CSR;                  /**< VPUMIX block cache enable control, offset: 0x18 */
  __I  uint32_t VPU_NO_PENDING_CSR;                /**< VPUMIX block pending transaction status, offset: 0x1C */
  __IO uint32_t G1_OTR_BEAT_LIMIT_CSR;             /**< VPUMIX G1 outstanding read beat limit control, offset: 0x20 */
  __IO uint32_t G2_OTR_BEAT_LIMIT_CSR;             /**< VPUMIX G2 outstanding read beat limit control, offset: 0x24 */
  __IO uint32_t VC8000E_OTR_BEAT_LIMIT_CSR;        /**< VPUMIX VC8000E outstanding read beat limit control, offset: 0x28 */
} VPU_BLK_CTL_Type;

/* ----------------------------------------------------------------------------
   -- VPU_BLK_CTL Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_BLK_CTL_Register_Masks VPU_BLK_CTL Register Masks
 * @{
 */

/*! @name BLK_SFT_RSTN_CSR - VPUMIX block soft reset control */
/*! @{ */

#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G2_SFT_RSTN_MASK (0x1U)
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G2_SFT_RSTN_SHIFT (0U)
/*! G2_SFT_RSTN
 *  0b0..Reset
 *  0b1..Normal
 */
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G2_SFT_RSTN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G2_SFT_RSTN_SHIFT)) & VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G2_SFT_RSTN_MASK)

#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G1_SFT_RSTN_MASK (0x2U)
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G1_SFT_RSTN_SHIFT (1U)
/*! G1_SFT_RSTN
 *  0b0..Reset
 *  0b1..Normal
 */
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G1_SFT_RSTN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G1_SFT_RSTN_SHIFT)) & VPU_BLK_CTL_BLK_SFT_RSTN_CSR_G1_SFT_RSTN_MASK)

#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_VC8000E_SFT_RSTN_MASK (0x4U)
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_VC8000E_SFT_RSTN_SHIFT (2U)
/*! VC8000E_SFT_RSTN
 *  0b0..Reset
 *  0b1..Normal
 */
#define VPU_BLK_CTL_BLK_SFT_RSTN_CSR_VC8000E_SFT_RSTN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_SFT_RSTN_CSR_VC8000E_SFT_RSTN_SHIFT)) & VPU_BLK_CTL_BLK_SFT_RSTN_CSR_VC8000E_SFT_RSTN_MASK)
/*! @} */

/*! @name BLK_CLK_EN_CSR - VPUMIX block clock enable control */
/*! @{ */

#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G2_CLK_EN_MASK (0x1U)
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G2_CLK_EN_SHIFT (0U)
/*! G2_CLK_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G2_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_CLK_EN_CSR_G2_CLK_EN_SHIFT)) & VPU_BLK_CTL_BLK_CLK_EN_CSR_G2_CLK_EN_MASK)

#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G1_CLK_EN_MASK (0x2U)
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G1_CLK_EN_SHIFT (1U)
/*! G1_CLK_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_G1_CLK_EN(x)  (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_CLK_EN_CSR_G1_CLK_EN_SHIFT)) & VPU_BLK_CTL_BLK_CLK_EN_CSR_G1_CLK_EN_MASK)

#define VPU_BLK_CTL_BLK_CLK_EN_CSR_VC8000E_CLK_EN_MASK (0x4U)
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_VC8000E_CLK_EN_SHIFT (2U)
/*! VC8000E_CLK_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_VC8000E_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_CLK_EN_CSR_VC8000E_CLK_EN_SHIFT)) & VPU_BLK_CTL_BLK_CLK_EN_CSR_VC8000E_CLK_EN_MASK)

#define VPU_BLK_CTL_BLK_CLK_EN_CSR_MAIN_CLK_EN_MASK (0x8U)
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_MAIN_CLK_EN_SHIFT (3U)
/*! MAIN_CLK_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_BLK_CLK_EN_CSR_MAIN_CLK_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_BLK_CLK_EN_CSR_MAIN_CLK_EN_SHIFT)) & VPU_BLK_CTL_BLK_CLK_EN_CSR_MAIN_CLK_EN_MASK)
/*! @} */

/*! @name G1_FUSE_DEC_CSR - VPUMIX G1 fuse_dec control */
/*! @{ */

#define VPU_BLK_CTL_G1_FUSE_DEC_CSR_G1_FUSE_DEC_MASK (0xFFFFFFFFU)
#define VPU_BLK_CTL_G1_FUSE_DEC_CSR_G1_FUSE_DEC_SHIFT (0U)
/*! G1_FUSE_DEC
 *  0b00000000000000000000000000000000..Disable
 *  0b00000000000000000000000000000001..Enable
 */
#define VPU_BLK_CTL_G1_FUSE_DEC_CSR_G1_FUSE_DEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G1_FUSE_DEC_CSR_G1_FUSE_DEC_SHIFT)) & VPU_BLK_CTL_G1_FUSE_DEC_CSR_G1_FUSE_DEC_MASK)
/*! @} */

/*! @name G1_FUSE_PP_CSR - VPUMIX G1 fuse_pp control */
/*! @{ */

#define VPU_BLK_CTL_G1_FUSE_PP_CSR_G1_FUSE_PP_MASK (0xFFFFFFFFU)
#define VPU_BLK_CTL_G1_FUSE_PP_CSR_G1_FUSE_PP_SHIFT (0U)
/*! G1_FUSE_PP
 *  0b00000000000000000000000000000000..Disable
 *  0b00000000000000000000000000000001..Enable
 */
#define VPU_BLK_CTL_G1_FUSE_PP_CSR_G1_FUSE_PP(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G1_FUSE_PP_CSR_G1_FUSE_PP_SHIFT)) & VPU_BLK_CTL_G1_FUSE_PP_CSR_G1_FUSE_PP_MASK)
/*! @} */

/*! @name G2_FUSE_DEC_CSR - VPUMIX G2 fuse_dec control */
/*! @{ */

#define VPU_BLK_CTL_G2_FUSE_DEC_CSR_G2_FUSE_DEC_MASK (0xFFFFFFFFU)
#define VPU_BLK_CTL_G2_FUSE_DEC_CSR_G2_FUSE_DEC_SHIFT (0U)
/*! G2_FUSE_DEC
 *  0b00000000000000000000000000000000..Disable
 *  0b00000000000000000000000000000001..Enable
 */
#define VPU_BLK_CTL_G2_FUSE_DEC_CSR_G2_FUSE_DEC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G2_FUSE_DEC_CSR_G2_FUSE_DEC_SHIFT)) & VPU_BLK_CTL_G2_FUSE_DEC_CSR_G2_FUSE_DEC_MASK)
/*! @} */

/*! @name VC8000E_FUSE_ENC_CSR - VPUMIX VC8000E fuse_enc control */
/*! @{ */

#define VPU_BLK_CTL_VC8000E_FUSE_ENC_CSR_VC8000E_FUSE_ENC_MASK (0xFFFFFFFFU)
#define VPU_BLK_CTL_VC8000E_FUSE_ENC_CSR_VC8000E_FUSE_ENC_SHIFT (0U)
/*! VC8000E_FUSE_ENC
 *  0b00000000000000000000000000000000..Disable
 *  0b00000000000000000000000000000001..Enable
 */
#define VPU_BLK_CTL_VC8000E_FUSE_ENC_CSR_VC8000E_FUSE_ENC(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VC8000E_FUSE_ENC_CSR_VC8000E_FUSE_ENC_SHIFT)) & VPU_BLK_CTL_VC8000E_FUSE_ENC_CSR_VC8000E_FUSE_ENC_MASK)
/*! @} */

/*! @name VPU_CACHE_EN_CSR - VPUMIX block cache enable control */
/*! @{ */

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_ARCACHE_EN_MASK (0x1U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_ARCACHE_EN_SHIFT (0U)
/*! G1_ARCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_ARCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_ARCACHE_EN_MASK)

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_AWCACHE_EN_MASK (0x2U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_AWCACHE_EN_SHIFT (1U)
/*! G1_AWCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_AWCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_G1_AWCACHE_EN_MASK)

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_ARCACHE_EN_MASK (0x4U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_ARCACHE_EN_SHIFT (2U)
/*! G2_ARCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_ARCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_ARCACHE_EN_MASK)

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_AWCACHE_EN_MASK (0x8U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_AWCACHE_EN_SHIFT (3U)
/*! G2_AWCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_AWCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_G2_AWCACHE_EN_MASK)

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_ARCACHE_EN_MASK (0x10U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_ARCACHE_EN_SHIFT (4U)
/*! VC8000E_ARCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_ARCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_ARCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_ARCACHE_EN_MASK)

#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_AWCACHE_EN_MASK (0x20U)
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_AWCACHE_EN_SHIFT (5U)
/*! VC8000E_AWCACHE_EN
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_AWCACHE_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_AWCACHE_EN_SHIFT)) & VPU_BLK_CTL_VPU_CACHE_EN_CSR_VC8000E_AWCACHE_EN_MASK)
/*! @} */

/*! @name VPU_NO_PENDING_CSR - VPUMIX block pending transaction status */
/*! @{ */

#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G1_NO_PENDING_MASK (0x1U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G1_NO_PENDING_SHIFT (0U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G1_NO_PENDING(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_NO_PENDING_CSR_G1_NO_PENDING_SHIFT)) & VPU_BLK_CTL_VPU_NO_PENDING_CSR_G1_NO_PENDING_MASK)

#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G2_NO_PENDING_MASK (0x2U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G2_NO_PENDING_SHIFT (1U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_G2_NO_PENDING(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_NO_PENDING_CSR_G2_NO_PENDING_SHIFT)) & VPU_BLK_CTL_VPU_NO_PENDING_CSR_G2_NO_PENDING_MASK)

#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_VC8000E_NO_PENDING_MASK (0x4U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_VC8000E_NO_PENDING_SHIFT (2U)
#define VPU_BLK_CTL_VPU_NO_PENDING_CSR_VC8000E_NO_PENDING(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VPU_NO_PENDING_CSR_VC8000E_NO_PENDING_SHIFT)) & VPU_BLK_CTL_VPU_NO_PENDING_CSR_VC8000E_NO_PENDING_MASK)
/*! @} */

/*! @name G1_OTR_BEAT_LIMIT_CSR - VPUMIX G1 outstanding read beat limit control */
/*! @{ */

#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_NUM_MASK (0xFFFFU)
#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_NUM_SHIFT (0U)
#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_NUM_SHIFT)) & VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_NUM_MASK)

#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_ENABLE_MASK (0x10000U)
#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_ENABLE_SHIFT (16U)
#define VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_ENABLE_SHIFT)) & VPU_BLK_CTL_G1_OTR_BEAT_LIMIT_CSR_G1_BEAT_LIMIT_ENABLE_MASK)
/*! @} */

/*! @name G2_OTR_BEAT_LIMIT_CSR - VPUMIX G2 outstanding read beat limit control */
/*! @{ */

#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_NUM_MASK (0xFFFFU)
#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_NUM_SHIFT (0U)
#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_NUM_SHIFT)) & VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_NUM_MASK)

#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_ENABLE_MASK (0x10000U)
#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_ENABLE_SHIFT (16U)
#define VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_ENABLE_SHIFT)) & VPU_BLK_CTL_G2_OTR_BEAT_LIMIT_CSR_G2_BEAT_LIMIT_ENABLE_MASK)
/*! @} */

/*! @name VC8000E_OTR_BEAT_LIMIT_CSR - VPUMIX VC8000E outstanding read beat limit control */
/*! @{ */

#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_NUM_MASK (0xFFFFU)
#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_NUM_SHIFT (0U)
#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_NUM(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_NUM_SHIFT)) & VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_NUM_MASK)

#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_ENABLE_MASK (0x10000U)
#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_ENABLE_SHIFT (16U)
#define VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_ENABLE_SHIFT)) & VPU_BLK_CTL_VC8000E_OTR_BEAT_LIMIT_CSR_VC8000E_BEAT_LIMIT_ENABLE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_BLK_CTL_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_BLK_CTL_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_BLK_CTL_H_ */

