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
**         CMSIS Peripheral Access Layer for VPU_G1_VP8
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
 * @file PERI_VPU_G1_VP8.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_G1_VP8
 *
 * CMSIS Peripheral Access Layer for VPU_G1_VP8
 */

#if !defined(PERI_VPU_G1_VP8_H_)
#define PERI_VPU_G1_VP8_H_                       /**< Symbol preventing repeated inclusion */

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
   -- VPU_G1_VP8 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_VP8_Peripheral_Access_Layer VPU_G1_VP8 Peripheral Access Layer
 * @{
 */

/** VPU_G1_VP8 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[76];
  __IO uint32_t SWREG19_VP8;                       /**< Base address for reference picture index 5 / MPEG4 TRB/TRD delta 0 / VC-1 intensity control 3 List of VLC code lengths in first/second JPEG AC table / VP6/VP7 scan maps, offset: 0x4C */
  __IO uint32_t SWREG20_VP8;                       /**< Base address for reference picture index 6 / / MPEG4 TRB/TRD delta -1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps, offset: 0x50 */
  __IO uint32_t SWREG21_VP8;                       /**< Base address for reference picture index 7 / MPEG4 TRB/TRD delta 1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps, offset: 0x54 */
} VPU_G1_VP8_Type;

/* ----------------------------------------------------------------------------
   -- VPU_G1_VP8 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_VP8_Register_Masks VPU_G1_VP8 Register Masks
 * @{
 */

/*! @name SWREG19_VP8 - Base address for reference picture index 5 / MPEG4 TRB/TRD delta 0 / VC-1 intensity control 3 List of VLC code lengths in first/second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_VP8_SWREG19_VP8_SW_AREF_SIGN_BIAS_MASK (0x1U)
#define VPU_G1_VP8_SWREG19_VP8_SW_AREF_SIGN_BIAS_SHIFT (0U)
/*! SW_AREF_SIGN_BIAS - VP8 only: Reference picture sign bias for Alternate reference frame */
#define VPU_G1_VP8_SWREG19_VP8_SW_AREF_SIGN_BIAS(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG19_VP8_SW_AREF_SIGN_BIAS_SHIFT)) & VPU_G1_VP8_SWREG19_VP8_SW_AREF_SIGN_BIAS_MASK)

#define VPU_G1_VP8_SWREG19_VP8_SW_REFER5_BASE_VP8_MASK (0xFFFFFFFCU)
#define VPU_G1_VP8_SWREG19_VP8_SW_REFER5_BASE_VP8_SHIFT (2U)
/*! SW_REFER5_BASE_VP8 - H.264: Base address for reference picture index 5 VP8: Base address for
 *    alternate reference picture (corresponds picid 5)
 */
#define VPU_G1_VP8_SWREG19_VP8_SW_REFER5_BASE_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG19_VP8_SW_REFER5_BASE_VP8_SHIFT)) & VPU_G1_VP8_SWREG19_VP8_SW_REFER5_BASE_VP8_MASK)
/*! @} */

/*! @name SWREG20_VP8 - Base address for reference picture index 6 / / MPEG4 TRB/TRD delta -1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_CH_BASE_E_MASK (0x1U)
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_CH_BASE_E_SHIFT (0U)
/*! SW_VP8_CH_BASE_E - VP8 separate chrominance enable:
 *  0b0..Write/Read chrominance data from internal offset after the luminance data
 *  0b1..Write/Read chrominance data from separate base addresses given by SW
 */
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_CH_BASE_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG20_VP8_SW_VP8_CH_BASE_E_SHIFT)) & VPU_G1_VP8_SWREG20_VP8_SW_VP8_CH_BASE_E_MASK)

#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_STRIDE_E_MASK (0x2U)
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_STRIDE_E_SHIFT (1U)
/*! SW_VP8_STRIDE_E - VP8 stride enable. Can be set high only if HW configuration supports strides.
 *    Y and C strides are used instead of picture width. Separate chrominance base addresses are
 *    used instead of internal chrominance offsets.
 *  0b0..Not enabled
 *  0b1..Enabled
 */
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_STRIDE_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG20_VP8_SW_VP8_STRIDE_E_SHIFT)) & VPU_G1_VP8_SWREG20_VP8_SW_VP8_STRIDE_E_MASK)

#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_DEC_CH_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_DEC_CH_BASE_SHIFT (2U)
/*! SW_VP8_DEC_CH_BASE - VP8 video base address for decoder output chrominance data (if vp8 stride configuration is enabled) */
#define VPU_G1_VP8_SWREG20_VP8_SW_VP8_DEC_CH_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG20_VP8_SW_VP8_DEC_CH_BASE_SHIFT)) & VPU_G1_VP8_SWREG20_VP8_SW_VP8_DEC_CH_BASE_MASK)
/*! @} */

/*! @name SWREG21_VP8 - Base address for reference picture index 7 / MPEG4 TRB/TRD delta 1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_VP8_SWREG21_VP8_SW_C_STRIDE_POW2_MASK (0x7C00000U)
#define VPU_G1_VP8_SWREG21_VP8_SW_C_STRIDE_POW2_SHIFT (22U)
/*! SW_C_STRIDE_POW2 - VP8 C stride length informed by 2^n (n=sw_c_stride_pow2). Valid range 10-17 for 32 bit bus and 10-18 for 64 bit bus */
#define VPU_G1_VP8_SWREG21_VP8_SW_C_STRIDE_POW2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG21_VP8_SW_C_STRIDE_POW2_SHIFT)) & VPU_G1_VP8_SWREG21_VP8_SW_C_STRIDE_POW2_MASK)

#define VPU_G1_VP8_SWREG21_VP8_SW_Y_STRIDE_POW2_MASK (0xF8000000U)
#define VPU_G1_VP8_SWREG21_VP8_SW_Y_STRIDE_POW2_SHIFT (27U)
/*! SW_Y_STRIDE_POW2 - VP8 Y stride length informed by 2^n (n=sw_y_stride_pow2). Valid range 10-17 for 32 bit bus and 10-18 for 64 bit bus */
#define VPU_G1_VP8_SWREG21_VP8_SW_Y_STRIDE_POW2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP8_SWREG21_VP8_SW_Y_STRIDE_POW2_SHIFT)) & VPU_G1_VP8_SWREG21_VP8_SW_Y_STRIDE_POW2_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_G1_VP8_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_G1_VP8_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_G1_VP8_H_ */

