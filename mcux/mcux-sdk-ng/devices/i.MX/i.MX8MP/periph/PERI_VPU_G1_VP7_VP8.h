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
**         CMSIS Peripheral Access Layer for VPU_G1_VP7_VP8
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
 * @file PERI_VPU_G1_VP7_VP8.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_G1_VP7_VP8
 *
 * CMSIS Peripheral Access Layer for VPU_G1_VP7_VP8
 */

#if !defined(PERI_VPU_G1_VP7_VP8_H_)
#define PERI_VPU_G1_VP7_VP8_H_                   /**< Symbol preventing repeated inclusion */

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
   -- VPU_G1_VP7_VP8 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_VP7_VP8_Peripheral_Access_Layer VPU_G1_VP7_VP8 Peripheral Access Layer
 * @{
 */

/** VPU_G1_VP7_VP8 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SWREG4_JPEG_VP7_VP8;               /**< Decoder control register 1 (picture parameters), offset: 0x10 */
  __IO uint32_t SWREG5_VP7_VP8;                    /**< Decoder control register 2 (stream decoding table selects), offset: 0x14 */
  __IO uint32_t SWREG6_VP7_VP8;                    /**< Decoder control register 3 (stream buffer information), offset: 0x18 */
  __IO uint32_t SWREG7_VP7_VP8;                    /**< Decoder control register 4 (H264, VC-1, VP6 and progressive JPEG control), offset: 0x1C */
       uint8_t RESERVED_1[8];
  __IO uint32_t SWREG10_VP7_VP8;                   /**< Base address for differential motion vector base address (RLC-mode) /H264 P initial fwd ref pic list register (4-9)/ VC-1 intensity control 1/ VP7 and VP8 segmentation base register, offset: 0x28 */
  __IO uint32_t SWREG11_VP7_VP8;                   /**< Decoder control register 7 (VLC) / base address for H.264 intra prediction 4x4 / base address for MPEG-4 DC component (RLC) / H264 P initial fwd ref pic list register (10-15) / VC-1 intensity control 2, offset: 0x2C */
       uint8_t RESERVED_2[8];
  __IO uint32_t SWREG14_VP7_VP8;                   /**< Base address for reference picture index 0 / base address for JPEG decoder output chrominance picture, offset: 0x38 */
  __IO uint32_t SWREG15_VP7_VP8;                   /**< Base address for reference picture index 1 / JPEG control, offset: 0x3C */
       uint8_t RESERVED_3[8];
  __IO uint32_t SWREG18_VP7_VP8;                   /**< Base address for reference picture index 4 / VC1 control / MPEG4 MVD control/ List of VLC code lengths in first JPEG AC table / VC-1 intensity control 4 / VP6/VP7, VP8 Golden refer picture base, offset: 0x48 */
       uint8_t RESERVED_4[12];
  __IO uint32_t SWREG22_VP7_VP8;                   /**< Base address for reference picture index 8 / List of VLC code lengths in second JPEG AC table / VP6 scan maps / VP7,VP8 DCT stream 1 base, offset: 0x58 */
  __IO uint32_t SWREG23_VP7_VP8;                   /**< Base address for reference picture index 9 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 2 base, offset: 0x5C */
  __IO uint32_t SWREG24_VP7_VP8;                   /**< Base address for reference picture index 10 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 3 base, offset: 0x60 */
  __IO uint32_t SWREG25_VP7_VP8;                   /**< Base address for reference picture index 11 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 4 base, offset: 0x64 */
  __IO uint32_t SWREG26_VP7_VP8;                   /**< Base address for reference picture index 12 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 5 base, offset: 0x68 */
  __IO uint32_t SWREG27_VC1;                       /**< Base address for reference picture index 13 / VC-1 bitpl mbctrl or VP6,VP7,VP8 ctrl stream base /Progressive JPEG DC table, offset: 0x6C */
  __IO uint32_t SWREG28_VP7_VP8;                   /**< Base address for reference picture index 14 / VP6 scan maps /Progressive JPEG DC table / VP7,VP8 DCT stream 6 base, offset: 0x70 */
  __IO uint32_t SWREG29_VP7_VP8;                   /**< Base address for reference picture index 15 / VP6 scan maps / VP7,VP8 DCT stream 7 base, offset: 0x74 */
  __IO uint32_t SWREG30_VP7_VP8;                   /**< Reference picture numbers for index 0 and 1 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter mb level adjusts, offset: 0x78 */
  __IO uint32_t SWREG31_VP7_VP8;                   /**< Reference picture numbers for index 2 and 3 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter ref pic level adjusts, offset: 0x7C */
  __IO uint32_t SWREG32_VP7_VP8;                   /**< Reference picture numbers for index 4 and 5 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter levels, offset: 0x80 */
  __IO uint32_t SWREG33_VP7_VP8;                   /**< Reference picture numbers for index 6 and 7 (H264 VLC) / VP6 scan maps / VP7,VP8 quantization values, offset: 0x84 */
  __IO uint32_t SWREG34_H263;                      /**< Reference picture numbers for index 8 and 9 (H264 VLC) / MPEG4, VC1, VPx prediction filter taps, offset: 0x88 */
  __IO uint32_t SWREG35_VC1;                       /**< Reference picture numbers for index 10 and 11 (H264 VLC) / VC1, VPx prediction filter taps, offset: 0x8C */
  __IO uint32_t SWREG36_VC1;                       /**< Reference picture numbers for index 12 and 13 (H264 VLC) / VC1, VPx prediction filter taps, offset: 0x90 */
  __IO uint32_t SWREG37_VP6_VP7_VP8;               /**< Reference picture numbers for index 14 and 15 (H264 VLC) / VPx prediction filter taps, offset: 0x94 */
  __IO uint32_t SWREG38_VP6_VP7_VP8;               /**< Reference picture long term flags (H264 VLC) / VPx prediction filter taps, offset: 0x98 */
  __IO uint32_t SWREG39_VP6_VP7_VP8;               /**< Reference picture valid flags (H264 VLC) / VPx prediction filter taps, offset: 0x9C */
       uint8_t RESERVED_5[8];
  __IO uint32_t SWREG42_VP6;                       /**< bi_dir initial ref pic list register (0-2) / VP6 prediction filter taps / Progressive JPEG Cb ACDC coefficient base, offset: 0xA8 */
  __IO uint32_t SWREG43_VP7_VP8;                   /**< bi-dir initial ref pic list register (3-5) / VP6 prediction filter taps / Progressive JPEG Cr ACDC coefficient base, offset: 0xAC */
  __IO uint32_t SWREG44_VP7_VP8;                   /**< bi-dir initial ref pic list register (6-8) / VP6 prediction filter taps, offset: 0xB0 */
  __IO uint32_t SWREG45_VP7_VP8;                   /**< bi-dir initial ref pic list register (9-11) / VP6 prediction filter taps, offset: 0xB4 */
  __IO uint32_t SWREG46_VP7_VP8;                   /**< bi-dir initial ref pic list register (12-14) / VP7,VP8 quantization values, offset: 0xB8 */
  __IO uint32_t SWREG47_VP7_VP8;                   /**< bi-dir and P fwd initial ref pic list register (15 and P 0-3) / VP7,VP8 quantization values, offset: 0xBC */
} VPU_G1_VP7_VP8_Type;

/* ----------------------------------------------------------------------------
   -- VPU_G1_VP7_VP8 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_VP7_VP8_Register_Masks VPU_G1_VP7_VP8 Register Masks
 * @{
 */

/*! @name SWREG4_JPEG_VP7_VP8 - Decoder control register 1 (picture parameters) */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_H_EXT_JPEG_VP7_VP6_MASK (0x7U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_H_EXT_JPEG_VP7_VP6_SHIFT (0U)
/*! SW_PIC_MB_H_EXT_JPEG_VP7_VP6 - Picture mb height extension. If sw_pic_mb_height_p does not fit
 *    to 9 bits then these bits are used to increase the range upto 11 bits (used as 3 msb). For 4k
 *    video one bit is used for extension (bit 0)
 */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_H_EXT_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_H_EXT_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_H_EXT_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_W_EXT_JPEG_VP7_VP6_MASK (0x38U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_W_EXT_JPEG_VP7_VP6_SHIFT (3U)
/*! SW_PIC_MB_W_EXT_JPEG_VP7_VP6 - Picture mb width extension. If sw_pic_mb_width does not fit to 9
 *    bits then these bits are used to increase the range upto 11 bits (used as 3 msb)
 */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_W_EXT_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_W_EXT_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_W_EXT_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_ALT_SCAN_E_JPEG_VP7_VP6_MASK (0x40U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_ALT_SCAN_E_JPEG_VP7_VP6_SHIFT (6U)
/*! SW_ALT_SCAN_E_JPEG_VP7_VP6 - indicates alternative vertical scan method used for interlaced frames */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_ALT_SCAN_E_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_ALT_SCAN_E_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_ALT_SCAN_E_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_HEIGHT_OFF_JPEG_VP7_VP6_MASK (0x780U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_HEIGHT_OFF_JPEG_VP7_VP6_SHIFT (7U)
/*! SW_MB_HEIGHT_OFF_JPEG_VP7_VP6 - The amount of meaningful vertical pixels in last MB (height
 *    offset 0 if exactly 16 pixels multiple picture and all the vertical pixels in last MB are
 *    meaningfull
 */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_HEIGHT_OFF_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_HEIGHT_OFF_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_HEIGHT_OFF_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6_MASK (0x7F800U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6_SHIFT (11U)
/*! SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6 - Picture height in macroblocks =((height in pixels+15)/16).
 *    Picture height is informed as size of the (progressive) frame also for single field (of
 *    interlaced content) is being decoded
 */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_HEIGHT_P_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_WIDTH_OFF_JPEG_VP7_VP6_MASK (0x780000U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_WIDTH_OFF_JPEG_VP7_VP6_SHIFT (19U)
/*! SW_MB_WIDTH_OFF_JPEG_VP7_VP6 - The amount of meaningfull horizontal pixels in last MB (width
 *    offset) 0 if exactly 16 pixels multiple picture and all the horizontal pixels in last MB are
 *    meaningfull
 */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_WIDTH_OFF_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_WIDTH_OFF_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_MB_WIDTH_OFF_JPEG_VP7_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_WIDTH_JPEG_VP7_VP6_MASK (0xFF800000U)
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_WIDTH_JPEG_VP7_VP6_SHIFT (23U)
/*! SW_PIC_MB_WIDTH_JPEG_VP7_VP6 - Picture width in macroblocks = ((width in pixels + 15) /16) */
#define VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_WIDTH_JPEG_VP7_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_WIDTH_JPEG_VP7_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG4_JPEG_VP7_VP8_SW_PIC_MB_WIDTH_JPEG_VP7_VP6_MASK)
/*! @} */

/*! @name SWREG5_VP7_VP8 - Decoder control register 2 (stream decoding table selects) */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_RANGE_VP7_VP8_MASK (0xFFU)
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_RANGE_VP7_VP8_SHIFT (0U)
/*! SW_BOOLEAN_RANGE_VP7_VP8 - Initial range for boolean dec */
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_RANGE_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_RANGE_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_RANGE_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_VALUE_VP7_VP8_MASK (0xFF00U)
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_VALUE_VP7_VP8_SHIFT (8U)
/*! SW_BOOLEAN_VALUE_VP7_VP8 - Initial value for boolean dec */
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_VALUE_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_VALUE_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_BOOLEAN_VALUE_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM1_START_BIT_VP7_VP8_MASK (0xFC0000U)
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM1_START_BIT_VP7_VP8_SHIFT (18U)
/*! SW_STRM1_START_BIT_VP7_VP8 - Start bit for ctrl-stream (needed if multistream is enabled, assosiates with sw_bitpl_ctrl_base) */
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM1_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM1_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM1_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM_START_BIT_VP7_VP8_MASK (0xFC000000U)
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM_START_BIT_VP7_VP8_SHIFT (26U)
/*! SW_STRM_START_BIT_VP7_VP8 - Exact bit of stream start word where decoding can be started (assosiates with sw_rlc_vlc_base) */
#define VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG5_VP7_VP8_SW_STRM_START_BIT_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG6_VP7_VP8 - Decoder control register 3 (stream buffer information) */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_VP7_VP8_MASK (0xFFFFFFU)
#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_VP7_VP8_SHIFT (0U)
/*! SW_STREAM_LEN_VP7_VP8 - Amount of stream data bytes in input buffer. If the given buffer size is
 *    not enough for finishing the picture the corresponding interrupt is given and new stream
 *    buffer base address and stream buffer size information should be given (assosiates with
 *    sw_rlc_vlc_base). For VC-1/VP6 the buffer must include data for one picture/slice of the picture For
 *    H264/MPEG4/H263/MPEG2/MPEG1 the buffer must include at least data for one slice/VP of the picture
 *    For JPEG the buffer size must be a multiple of 256 bytes or the amount of data for one
 *    picture.
 */
#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_EXT_VP7_VP8_MASK (0xFF000000U)
#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_EXT_VP7_VP8_SHIFT (24U)
/*! SW_STREAM_LEN_EXT_VP7_VP8 - Extended stream length for WEBP/VP8 */
#define VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_EXT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_EXT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG6_VP7_VP8_SW_STREAM_LEN_EXT_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG7_VP7_VP8 - Decoder control register 4 (H264, VC-1, VP6 and progressive JPEG control) */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_VP7_VERSION_VP7_VP8_MASK (0x20U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_VP7_VERSION_VP7_VP8_SHIFT (5U)
/*! SW_VP7_VERSION_VP7_VP8 - VP7 version information to streamd:
 *  0b0..VP7 version 7.0
 *  0b1..VP7 version 7.1 or better
 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_VP7_VERSION_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_VP7_VERSION_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_VP7_VERSION_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH1_VP7_VP8_MASK (0x1C0U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH1_VP7_VP8_SHIFT (6U)
/*! SW_INIT_DC_MATCH1_VP7_VP8 - Initial DC prediction mach count 1. After HW has decoded a picture
 *    HW returns the final match count1 information which is read by SW
 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH0_VP7_VP8_MASK (0xE00U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH0_VP7_VP8_SHIFT (9U)
/*! SW_INIT_DC_MATCH0_VP7_VP8 - Initial DC prediction mach count 0. After HW has decoded a picture
 *    HW returns the final match count0 information which is read by SW
 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH0_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH0_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_INIT_DC_MATCH0_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_BILIN_MC_E_VP7_VP8_MASK (0x1000U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_BILIN_MC_E_VP7_VP8_SHIFT (12U)
/*! SW_BILIN_MC_E_VP7_VP8 - Bilinear motion compensation enable:
 *  0b0..Bicubic interpolation used
 *  0b1..Bilinear interpolation used
 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_BILIN_MC_E_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_BILIN_MC_E_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_BILIN_MC_E_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_CH_MV_RES_VP7_VP8_MASK (0x2000U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_CH_MV_RES_VP7_VP8_SHIFT (13U)
/*! SW_CH_MV_RES_VP7_VP8 - VP7/VP8 Chrominance motion vector resolution:
 *  0b0..Full pixel
 *  0b1..1/8 pixel
 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_CH_MV_RES_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_CH_MV_RES_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_CH_MV_RES_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT2_START_BIT_VP7_VP8_MASK (0x3F00000U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT2_START_BIT_VP7_VP8_SHIFT (20U)
/*! SW_DCT2_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 2 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT2_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT2_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT2_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT1_START_BIT_VP7_VP8_MASK (0xFC000000U)
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT1_START_BIT_VP7_VP8_SHIFT (26U)
/*! SW_DCT1_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 1 */
#define VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT1_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT1_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG7_VP7_VP8_SW_DCT1_START_BIT_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG10_VP7_VP8 - Base address for differential motion vector base address (RLC-mode) /H264 P initial fwd ref pic list register (4-9)/ VC-1 intensity control 1/ VP7 and VP8 segmentation base register */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_E_VP7_VP8_MASK (0x1U)
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_E_VP7_VP8_SHIFT (0U)
/*! SW_SEGMENT_E_VP7_VP8 - Segmentation enable: '0': segmentation is not enabled '1': segmentation is enabled (sw_segment_upd_e value is used) */
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_E_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_E_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_E_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_UPD_E_VP7_VP8_MASK (0x2U)
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_UPD_E_VP7_VP8_SHIFT (1U)
/*! SW_SEGMENT_UPD_E_VP7_VP8 - VP7/VP8 Segmentation map update enable: '0': segmentation values are
 *    read from external memory (from segment_base) '1': segmentation update is included in stream
 */
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_UPD_E_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_UPD_E_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_UPD_E_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_BASE_VP7_VP8_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_BASE_VP7_VP8_SHIFT (2U)
/*! SW_SEGMENT_BASE_VP7_VP8 - VP7/VP8: base address for segmentation map values */
#define VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_BASE_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_BASE_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG10_VP7_VP8_SW_SEGMENT_BASE_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG11_VP7_VP8 - Decoder control register 7 (VLC) / base address for H.264 intra prediction 4x4 / base address for MPEG-4 DC component (RLC) / H264 P initial fwd ref pic list register (10-15) / VC-1 intensity control 2 */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT7_START_BIT_VP7_VP8_MASK (0x3FU)
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT7_START_BIT_VP7_VP8_SHIFT (0U)
/*! SW_DCT7_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 7 */
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT7_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT7_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT7_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT6_START_BIT_VP7_VP8_MASK (0xFC0U)
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT6_START_BIT_VP7_VP8_SHIFT (6U)
/*! SW_DCT6_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 6 */
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT6_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT6_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT6_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT5_START_BIT_VP7_VP8_MASK (0x3F000U)
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT5_START_BIT_VP7_VP8_SHIFT (12U)
/*! SW_DCT5_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 5 */
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT5_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT5_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT5_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT4_START_BIT_VP7_VP8_MASK (0xFC0000U)
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT4_START_BIT_VP7_VP8_SHIFT (18U)
/*! SW_DCT4_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 4 */
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT4_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT4_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT4_START_BIT_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT3_START_BIT_VP7_VP8_MASK (0x3F000000U)
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT3_START_BIT_VP7_VP8_SHIFT (24U)
/*! SW_DCT3_START_BIT_VP7_VP8 - Start bit for VP7/VP8 DCT stream partition index 3 */
#define VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT3_START_BIT_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT3_START_BIT_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG11_VP7_VP8_SW_DCT3_START_BIT_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG14_VP7_VP8 - Base address for reference picture index 0 / base address for JPEG decoder output chrominance picture */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG14_VP7_VP8_SW_JPG_CH_OUT_BASE_VP7_VP8_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG14_VP7_VP8_SW_JPG_CH_OUT_BASE_VP7_VP8_SHIFT (2U)
/*! SW_JPG_CH_OUT_BASE_VP7_VP8 - Base address for decoder output chrominance picture. Used in JPEG
 *    and web-p picture mode (not needed if decoder output is not written)
 */
#define VPU_G1_VP7_VP8_SWREG14_VP7_VP8_SW_JPG_CH_OUT_BASE_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG14_VP7_VP8_SW_JPG_CH_OUT_BASE_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG14_VP7_VP8_SW_JPG_CH_OUT_BASE_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG15_VP7_VP8 - Base address for reference picture index 1 / JPEG control */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG15_VP7_VP8_SW_JPEG_SLICE_H_VP7_VP8_MASK (0xFFU)
#define VPU_G1_VP7_VP8_SWREG15_VP7_VP8_SW_JPEG_SLICE_H_VP7_VP8_SHIFT (0U)
/*! SW_JPEG_SLICE_H_VP7_VP8 - JPEG/Web-p. Height of the slice (multiple of 16 pixels) that HW
 *    decodes before interrupt. When slice is decoded HW will rise an interrupt and reset external
 *    addresses back to base address. Note, value 0 disables slice mode. Slice mode must be used if picture
 *    size is more than 16 Mpixels. However for bigger than 4096 MBs the slice mode usage is
 *    recommended.
 */
#define VPU_G1_VP7_VP8_SWREG15_VP7_VP8_SW_JPEG_SLICE_H_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG15_VP7_VP8_SW_JPEG_SLICE_H_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG15_VP7_VP8_SW_JPEG_SLICE_H_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG18_VP7_VP8 - Base address for reference picture index 4 / VC1 control / MPEG4 MVD control/ List of VLC code lengths in first JPEG AC table / VC-1 intensity control 4 / VP6/VP7, VP8 Golden refer picture base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_GREF_SIGN_BIAS_VP7_VP8_MASK (0x1U)
#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_GREF_SIGN_BIAS_VP7_VP8_SHIFT (0U)
/*! SW_GREF_SIGN_BIAS_VP7_VP8 - Reference picture sign bias for Golden reference frame */
#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_GREF_SIGN_BIAS_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_GREF_SIGN_BIAS_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_GREF_SIGN_BIAS_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_REFER4_BASE_VP7_VP8_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_REFER4_BASE_VP7_VP8_SHIFT (2U)
/*! SW_REFER4_BASE_VP7_VP8 - H264: Base address for reference picture index 4 VP6/VP7/VP8: Base
 *    address for Golden reference picture (corresponds picid 4)
 */
#define VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_REFER4_BASE_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_REFER4_BASE_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG18_VP7_VP8_SW_REFER4_BASE_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG22_VP7_VP8 - Base address for reference picture index 8 / List of VLC code lengths in second JPEG AC table / VP6 scan maps / VP7,VP8 DCT stream 1 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG22_VP7_VP8_SW_DCT_STRM1_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG22_VP7_VP8_SW_DCT_STRM1_BASE_SHIFT (2U)
/*! SW_DCT_STRM1_BASE - Base address for VP7/VP8 DCT stream MB row 1,2n+1 */
#define VPU_G1_VP7_VP8_SWREG22_VP7_VP8_SW_DCT_STRM1_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG22_VP7_VP8_SW_DCT_STRM1_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG22_VP7_VP8_SW_DCT_STRM1_BASE_MASK)
/*! @} */

/*! @name SWREG23_VP7_VP8 - Base address for reference picture index 9 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 2 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG23_VP7_VP8_SW_DCT_STRM2_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG23_VP7_VP8_SW_DCT_STRM2_BASE_SHIFT (2U)
/*! SW_DCT_STRM2_BASE - Base address for VP7/VP8 DCT stream MB row 2,2n+2 */
#define VPU_G1_VP7_VP8_SWREG23_VP7_VP8_SW_DCT_STRM2_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG23_VP7_VP8_SW_DCT_STRM2_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG23_VP7_VP8_SW_DCT_STRM2_BASE_MASK)
/*! @} */

/*! @name SWREG24_VP7_VP8 - Base address for reference picture index 10 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 3 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG24_VP7_VP8_SW_DCT_STRM3_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG24_VP7_VP8_SW_DCT_STRM3_BASE_SHIFT (2U)
/*! SW_DCT_STRM3_BASE - Base address for VP7/VP8 DCT stream MB row 3,2n+3 */
#define VPU_G1_VP7_VP8_SWREG24_VP7_VP8_SW_DCT_STRM3_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG24_VP7_VP8_SW_DCT_STRM3_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG24_VP7_VP8_SW_DCT_STRM3_BASE_MASK)
/*! @} */

/*! @name SWREG25_VP7_VP8 - Base address for reference picture index 11 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 4 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG25_VP7_VP8_SW_DCT_STRM4_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG25_VP7_VP8_SW_DCT_STRM4_BASE_SHIFT (2U)
/*! SW_DCT_STRM4_BASE - Base address for VP7/VP8 DCT stream MB row 4,2n+4 */
#define VPU_G1_VP7_VP8_SWREG25_VP7_VP8_SW_DCT_STRM4_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG25_VP7_VP8_SW_DCT_STRM4_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG25_VP7_VP8_SW_DCT_STRM4_BASE_MASK)
/*! @} */

/*! @name SWREG26_VP7_VP8 - Base address for reference picture index 12 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 5 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG26_VP7_VP8_SW_DCT_STRM5_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG26_VP7_VP8_SW_DCT_STRM5_BASE_SHIFT (2U)
/*! SW_DCT_STRM5_BASE - Base address for VP7/VP8 DCT stream MB row 5,2n+5 */
#define VPU_G1_VP7_VP8_SWREG26_VP7_VP8_SW_DCT_STRM5_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG26_VP7_VP8_SW_DCT_STRM5_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG26_VP7_VP8_SW_DCT_STRM5_BASE_MASK)
/*! @} */

/*! @name SWREG27_VC1 - Base address for reference picture index 13 / VC-1 bitpl mbctrl or VP6,VP7,VP8 ctrl stream base /Progressive JPEG DC table */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG27_VC1_SW_BITPL_CTRL_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG27_VC1_SW_BITPL_CTRL_BASE_SHIFT (2U)
/*! SW_BITPL_CTRL_BASE - VC-1: Base address for bitplane mb control VP6/VP7/VP8 : Base address for
 *    ctrl data stream. Used if multistream is enabled
 */
#define VPU_G1_VP7_VP8_SWREG27_VC1_SW_BITPL_CTRL_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG27_VC1_SW_BITPL_CTRL_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG27_VC1_SW_BITPL_CTRL_BASE_MASK)
/*! @} */

/*! @name SWREG28_VP7_VP8 - Base address for reference picture index 14 / VP6 scan maps /Progressive JPEG DC table / VP7,VP8 DCT stream 6 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG28_VP7_VP8_SW_DCT_STRM6_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG28_VP7_VP8_SW_DCT_STRM6_BASE_SHIFT (2U)
/*! SW_DCT_STRM6_BASE - Base address for VP7/VP8 DCT stream MB row 6,2n+6 */
#define VPU_G1_VP7_VP8_SWREG28_VP7_VP8_SW_DCT_STRM6_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG28_VP7_VP8_SW_DCT_STRM6_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG28_VP7_VP8_SW_DCT_STRM6_BASE_MASK)
/*! @} */

/*! @name SWREG29_VP7_VP8 - Base address for reference picture index 15 / VP6 scan maps / VP7,VP8 DCT stream 7 base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG29_VP7_VP8_SW_DCT_STRM7_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_VP7_VP8_SWREG29_VP7_VP8_SW_DCT_STRM7_BASE_SHIFT (2U)
/*! SW_DCT_STRM7_BASE - Base address for VP7/VP8 DCT stream MB row 7,2n+7 */
#define VPU_G1_VP7_VP8_SWREG29_VP7_VP8_SW_DCT_STRM7_BASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG29_VP7_VP8_SW_DCT_STRM7_BASE_SHIFT)) & VPU_G1_VP7_VP8_SWREG29_VP7_VP8_SW_DCT_STRM7_BASE_MASK)
/*! @} */

/*! @name SWREG30_VP7_VP8 - Reference picture numbers for index 0 and 1 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter mb level adjusts */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_3_MASK (0x7FU)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_3_SHIFT (0U)
/*! SW_FILT_MB_ADJ_3 - VP7/VP8 filter level adjustment for MB type 3 */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_3_MASK)

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_2_MASK (0x3F80U)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_2_SHIFT (7U)
/*! SW_FILT_MB_ADJ_2 - VP7/VP8 filter level adjustment for MB type 2 */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_2_MASK)

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_1_MASK (0x1FC000U)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_1_SHIFT (14U)
/*! SW_FILT_MB_ADJ_1 - VP7/VP8 filter level adjustment for MB type 1 */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_1_MASK)

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_0_MASK (0xFE00000U)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_0_SHIFT (21U)
/*! SW_FILT_MB_ADJ_0 - VP7/VP8 filter level adjustment for MB type 0 */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_MB_ADJ_0_MASK)

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_SHARPNESS_MASK (0x70000000U)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_SHARPNESS_SHIFT (28U)
/*! SW_FILT_SHARPNESS - VP7/VP8 loop filter sharpness */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_SHARPNESS(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_SHARPNESS_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_SHARPNESS_MASK)

#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_TYPE_MASK (0x80000000U)
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_TYPE_SHIFT (31U)
/*! SW_FILT_TYPE - VP7/VP8 loop filter type */
#define VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_TYPE(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_TYPE_SHIFT)) & VPU_G1_VP7_VP8_SWREG30_VP7_VP8_SW_FILT_TYPE_MASK)
/*! @} */

/*! @name SWREG31_VP7_VP8 - Reference picture numbers for index 2 and 3 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter ref pic level adjusts */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_3_MASK (0x7FU)
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_3_SHIFT (0U)
/*! SW_FILT_REF_ADJ_3 - VP7/VP8 filter level adjustment for reference frame type 3 */
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_3_MASK)

#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_2_MASK (0x3F80U)
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_2_SHIFT (7U)
/*! SW_FILT_REF_ADJ_2 - VP7/VP8 filter level adjustment for reference frame type 2 */
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_2_MASK)

#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_1_MASK (0x1FC000U)
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_1_SHIFT (14U)
/*! SW_FILT_REF_ADJ_1 - VP7/VP8 filter level adjustment for reference frame type 1 */
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_1_MASK)

#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_0_MASK (0xFE00000U)
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_0_SHIFT (21U)
/*! SW_FILT_REF_ADJ_0 - VP7/VP8 filter level adjustment for reference frame type 0 */
#define VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG31_VP7_VP8_SW_FILT_REF_ADJ_0_MASK)
/*! @} */

/*! @name SWREG32_VP7_VP8 - Reference picture numbers for index 4 and 5 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter levels */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_3_MASK (0x3FU)
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_3_SHIFT (0U)
/*! SW_FILT_LEVEL_3 - VP7/VP8 filter level value for reference frame type 3 */
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_3_MASK)

#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_2_MASK (0xFC0U)
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_2_SHIFT (6U)
/*! SW_FILT_LEVEL_2 - VP7/VP8 filter level value for reference frame type 2 */
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_2_MASK)

#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_1_MASK (0x3F000U)
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_1_SHIFT (12U)
/*! SW_FILT_LEVEL_1 - VP7/VP8 filter level value for reference frame type 1 */
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_1_MASK)

#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_0_MASK (0xFC0000U)
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_0_SHIFT (18U)
/*! SW_FILT_LEVEL_0 - VP7/VP8 filter level value for reference frame type 0 */
#define VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG32_VP7_VP8_SW_FILT_LEVEL_0_MASK)
/*! @} */

/*! @name SWREG33_VP7_VP8 - Reference picture numbers for index 6 and 7 (H264 VLC) / VP6 scan maps / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_1_MASK (0x7FFU)
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_1_SHIFT (0U)
/*! SW_QUANT_1 - VP7: QP (11 bit) VP8: quantisizer value for LUT (7 bit) */
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_1_MASK)

#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_0_MASK (0x3FF800U)
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_0_SHIFT (11U)
/*! SW_QUANT_0 - VP7: QP (11 bit) VP8: quantisizer value for LUT (7 bit) */
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_0_MASK)

#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_1_MASK (0x7C00000U)
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_1_SHIFT (22U)
/*! SW_QUANT_DELTA_1 - VP8 quantisizer delta 1 */
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_1_MASK)

#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_0_MASK (0xF8000000U)
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_0_SHIFT (27U)
/*! SW_QUANT_DELTA_0 - VP8 quantisizer delta 0 */
#define VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG33_VP7_VP8_SW_QUANT_DELTA_0_MASK)
/*! @} */

/*! @name SWREG34_H263 - Reference picture numbers for index 8 and 9 (H264 VLC) / MPEG4, VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_1_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_1_SHIFT (2U)
/*! SW_PRED_BC_TAP_1_1 - Prediction filter set 1, tap 1 */
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_1_MASK)

#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_0_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_0_SHIFT (12U)
/*! SW_PRED_BC_TAP_1_0 - Prediction filter set 1, tap 0 */
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_1_0_MASK)

#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_0_3_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_0_3_SHIFT (22U)
/*! SW_PRED_BC_TAP_0_3 - Prediction filter set 0, tap 3 */
#define VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_0_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_0_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG34_H263_SW_PRED_BC_TAP_0_3_MASK)
/*! @} */

/*! @name SWREG35_VC1 - Reference picture numbers for index 10 and 11 (H264 VLC) / VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_2_0_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_2_0_SHIFT (2U)
/*! SW_PRED_BC_TAP_2_0 - Prediction filter set 2, tap 0 */
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_2_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_2_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_2_0_MASK)

#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_3_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_3_SHIFT (12U)
/*! SW_PRED_BC_TAP_1_3 - Prediction filter set 1, tap 3 */
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_3_MASK)

#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_2_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_2_SHIFT (22U)
/*! SW_PRED_BC_TAP_1_2 - Prediction filter set 1, tap 2 */
#define VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG35_VC1_SW_PRED_BC_TAP_1_2_MASK)
/*! @} */

/*! @name SWREG36_VC1 - Reference picture numbers for index 12 and 13 (H264 VLC) / VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_3_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_3_SHIFT (2U)
/*! SW_PRED_BC_TAP_2_3 - Prediction filter set 2, tap 3 */
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_3_MASK)

#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_2_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_2_SHIFT (12U)
/*! SW_PRED_BC_TAP_2_2 - Prediction filter set 2, tap 2 */
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_2_MASK)

#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_1_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_1_SHIFT (22U)
/*! SW_PRED_BC_TAP_2_1 - Prediction filter set 2, tap 1 */
#define VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG36_VC1_SW_PRED_BC_TAP_2_1_MASK)
/*! @} */

/*! @name SWREG37_VP6_VP7_VP8 - Reference picture numbers for index 14 and 15 (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_2_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_2_SHIFT (2U)
/*! SW_PRED_BC_TAP_3_2 - Prediction filter set 3, tap 2 */
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_2_MASK)

#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_1_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_1_SHIFT (12U)
/*! SW_PRED_BC_TAP_3_1 - Prediction filter set 3, tap 1 */
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_1_MASK)

#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_0_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_0_SHIFT (22U)
/*! SW_PRED_BC_TAP_3_0 - Prediction filter set 3, tap 0 */
#define VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG37_VP6_VP7_VP8_SW_PRED_BC_TAP_3_0_MASK)
/*! @} */

/*! @name SWREG38_VP6_VP7_VP8 - Reference picture long term flags (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_1_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_1_SHIFT (2U)
/*! SW_PRED_BC_TAP_4_1 - Prediction filter set 4, tap 1 */
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_1_SHIFT)) & VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_1_MASK)

#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_0_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_0_SHIFT (12U)
/*! SW_PRED_BC_TAP_4_0 - Prediction filter set 4, tap 0 */
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_4_0_MASK)

#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_3_3_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_3_3_SHIFT (22U)
/*! SW_PRED_BC_TAP_3_3 - Prediction filter set 3, tap 3 */
#define VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_3_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_3_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG38_VP6_VP7_VP8_SW_PRED_BC_TAP_3_3_MASK)
/*! @} */

/*! @name SWREG39_VP6_VP7_VP8 - Reference picture valid flags (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_5_0_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_5_0_SHIFT (2U)
/*! SW_PRED_BC_TAP_5_0 - Prediction filter set 5, tap 0 */
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_5_0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_5_0_SHIFT)) & VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_5_0_MASK)

#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_3_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_3_SHIFT (12U)
/*! SW_PRED_BC_TAP_4_3 - Prediction filter set 4, tap 3 */
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_3_SHIFT)) & VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_3_MASK)

#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_2_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_2_SHIFT (22U)
/*! SW_PRED_BC_TAP_4_2 - Prediction filter set 4, tap 2 */
#define VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_2_SHIFT)) & VPU_G1_VP7_VP8_SWREG39_VP6_VP7_VP8_SW_PRED_BC_TAP_4_2_MASK)
/*! @} */

/*! @name SWREG42_VP6 - bi_dir initial ref pic list register (0-2) / VP6 prediction filter taps / Progressive JPEG Cb ACDC coefficient base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_3_VP6_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_3_VP6_SHIFT (2U)
/*! SW_PRED_BC_TAP_5_3_VP6 - Prediction filter set 5, tap 3 */
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_3_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_3_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_3_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_2_VP6_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_2_VP6_SHIFT (12U)
/*! SW_PRED_BC_TAP_5_2_VP6 - Prediction filter set 5, tap 2 */
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_2_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_2_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_2_VP6_MASK)

#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_1_VP6_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_1_VP6_SHIFT (22U)
/*! SW_PRED_BC_TAP_5_1_VP6 - Prediction filter set 5, tap 1 */
#define VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_1_VP6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_1_VP6_SHIFT)) & VPU_G1_VP7_VP8_SWREG42_VP6_SW_PRED_BC_TAP_5_1_VP6_MASK)
/*! @} */

/*! @name SWREG43_VP7_VP8 - bi-dir initial ref pic list register (3-5) / VP6 prediction filter taps / Progressive JPEG Cr ACDC coefficient base */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_2_VP7_VP8_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_2_VP7_VP8_SHIFT (2U)
/*! SW_PRED_BC_TAP_6_2_VP7_VP8 - Prediction filter set 6, tap 2 */
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_2_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_2_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_2_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_1_VP7_VP8_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_1_VP7_VP8_SHIFT (12U)
/*! SW_PRED_BC_TAP_6_1_VP7_VP8 - Prediction filter set 6, tap 1 */
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_0_VP7_VP8_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_0_VP7_VP8_SHIFT (22U)
/*! SW_PRED_BC_TAP_6_0_VP7_VP8 - Prediction filter set 6, tap 0 */
#define VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_0_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_0_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG43_VP7_VP8_SW_PRED_BC_TAP_6_0_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG44_VP7_VP8 - bi-dir initial ref pic list register (6-8) / VP6 prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_1_VP7_VP8_MASK (0xFFCU)
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_1_VP7_VP8_SHIFT (2U)
/*! SW_PRED_BC_TAP_7_1_VP7_VP8 - Prediction filter set 7, tap 1 */
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_0_VP7_VP8_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_0_VP7_VP8_SHIFT (12U)
/*! SW_PRED_BC_TAP_7_0_VP7_VP8 - Prediction filter set 7, tap 0 */
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_0_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_0_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_7_0_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_6_3_VP7_VP8_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_6_3_VP7_VP8_SHIFT (22U)
/*! SW_PRED_BC_TAP_6_3_VP7_VP8 - Prediction filter set 6, tap 3 */
#define VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_6_3_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_6_3_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG44_VP7_VP8_SW_PRED_BC_TAP_6_3_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG45_VP7_VP8 - bi-dir initial ref pic list register (9-11) / VP6 prediction filter taps */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_4_VP7_VP8_MASK (0x3U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_4_VP7_VP8_SHIFT (0U)
/*! SW_PRED_TAP_6_4_VP7_VP8 - Additional Prediction filter tap 4 for set 6 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_4_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_4_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_4_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_M1_VP7_VP8_MASK (0xCU)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_M1_VP7_VP8_SHIFT (2U)
/*! SW_PRED_TAP_6_M1_VP7_VP8 - Additional Prediction filter tap -1 for set 6 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_M1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_M1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_6_M1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_4_VP7_VP8_MASK (0x30U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_4_VP7_VP8_SHIFT (4U)
/*! SW_PRED_TAP_4_4_VP7_VP8 - Additional Prediction filter tap 4 for set 4 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_4_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_4_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_4_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_M1_VP7_VP8_MASK (0xC0U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_M1_VP7_VP8_SHIFT (6U)
/*! SW_PRED_TAP_4_M1_VP7_VP8 - Additional Prediction filter tap -1 for set 4 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_M1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_M1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_4_M1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_4_VP7_VP8_MASK (0x300U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_4_VP7_VP8_SHIFT (8U)
/*! SW_PRED_TAP_2_4_VP7_VP8 - Additional Prediction filter tap 4 for set 2 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_4_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_4_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_4_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_M1_VP7_VP8_MASK (0xC00U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_M1_VP7_VP8_SHIFT (10U)
/*! SW_PRED_TAP_2_M1_VP7_VP8 - Additional Prediction filter tap -1 for set 2 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_M1_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_M1_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_TAP_2_M1_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_3_VP7_VP8_MASK (0x3FF000U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_3_VP7_VP8_SHIFT (12U)
/*! SW_PRED_BC_TAP_7_3_VP7_VP8 - Prediction filter set 7, tap 3 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_3_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_3_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_3_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_2_VP7_VP8_MASK (0xFFC00000U)
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_2_VP7_VP8_SHIFT (22U)
/*! SW_PRED_BC_TAP_7_2_VP7_VP8 - Prediction filter set 7, tap 2 */
#define VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_2_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_2_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG45_VP7_VP8_SW_PRED_BC_TAP_7_2_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG46_VP7_VP8 - bi-dir initial ref pic list register (12-14) / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_3_VP7_VP8_MASK (0x7FFU)
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_3_VP7_VP8_SHIFT (0U)
/*! SW_QUANT_3_VP7_VP8 - VP7: QP (11 bit) VP8: quantisizer value for LUT (7 bit) */
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_3_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_3_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_3_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_2_VP7_VP8_MASK (0x3FF800U)
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_2_VP7_VP8_SHIFT (11U)
/*! SW_QUANT_2_VP7_VP8 - VP7: QP (11 bit) VP8: quantisizer value for LUT (7 bit) */
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_2_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_2_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_2_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_3_VP7_VP8_MASK (0x7C00000U)
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_3_VP7_VP8_SHIFT (22U)
/*! SW_QUANT_DELTA_3_VP7_VP8 - VP8 quantisizer delta 3 */
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_3_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_3_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_3_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_2_VP7_VP8_MASK (0xF8000000U)
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_2_VP7_VP8_SHIFT (27U)
/*! SW_QUANT_DELTA_2_VP7_VP8 - VP8 quantisizer delta 2 */
#define VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_2_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_2_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG46_VP7_VP8_SW_QUANT_DELTA_2_VP7_VP8_MASK)
/*! @} */

/*! @name SWREG47_VP7_VP8 - bi-dir and P fwd initial ref pic list register (15 and P 0-3) / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_5_VP7_VP8_MASK (0x7FFU)
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_5_VP7_VP8_SHIFT (0U)
/*! SW_QUANT_5_VP7_VP8 - VP7 QP (11 bit) */
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_5_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_5_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_5_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_4_VP7_VP8_MASK (0x3FF800U)
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_4_VP7_VP8_SHIFT (11U)
/*! SW_QUANT_4_VP7_VP8 - VP7 QP (11 bit) */
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_4_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_4_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_4_VP7_VP8_MASK)

#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_DELTA_4_VP7_VP8_MASK (0xF8000000U)
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_DELTA_4_VP7_VP8_SHIFT (27U)
/*! SW_QUANT_DELTA_4_VP7_VP8 - VP8 quantisizer delta 4 */
#define VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_DELTA_4_VP7_VP8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_DELTA_4_VP7_VP8_SHIFT)) & VPU_G1_VP7_VP8_SWREG47_VP7_VP8_SW_QUANT_DELTA_4_VP7_VP8_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_G1_VP7_VP8_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_G1_VP7_VP8_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_G1_VP7_VP8_H_ */

