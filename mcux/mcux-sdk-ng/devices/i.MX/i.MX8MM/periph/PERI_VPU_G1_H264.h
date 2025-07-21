/*
** ###################################################################
**     Processors:          MIMX8MM1CVTKZ_ca53
**                          MIMX8MM1CVTKZ_cm4
**                          MIMX8MM1DVTLZ_ca53
**                          MIMX8MM1DVTLZ_cm4
**                          MIMX8MM2CVTKZ_ca53
**                          MIMX8MM2CVTKZ_cm4
**                          MIMX8MM2DVTLZ_ca53
**                          MIMX8MM2DVTLZ_cm4
**                          MIMX8MM3CVTKZ_ca53
**                          MIMX8MM3CVTKZ_cm4
**                          MIMX8MM3DVTLZ_ca53
**                          MIMX8MM3DVTLZ_cm4
**                          MIMX8MM4CVTKZ_ca53
**                          MIMX8MM4CVTKZ_cm4
**                          MIMX8MM4DVTLZ_ca53
**                          MIMX8MM4DVTLZ_cm4
**                          MIMX8MM5CVTKZ_ca53
**                          MIMX8MM5CVTKZ_cm4
**                          MIMX8MM5DVTLZ_ca53
**                          MIMX8MM5DVTLZ_cm4
**                          MIMX8MM6CVTKZ_ca53
**                          MIMX8MM6CVTKZ_cm4
**                          MIMX8MM6DVTLZ_ca53
**                          MIMX8MM6DVTLZ_cm4
**
**     Version:             rev. 5.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_G1_H264
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2018-03-26)
**         Initial version.
**     - rev. 2.0 (2018-07-20)
**         Rev.A Header EAR
**     - rev. 3.0 (2018-10-24)
**         Rev.B Header PRC
**     - rev. 4.0 (2019-02-18)
**         Rev.0 Header RFP
**     - rev. 5.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_VPU_G1_H264.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_G1_H264
 *
 * CMSIS Peripheral Access Layer for VPU_G1_H264
 */

#if !defined(PERI_VPU_G1_H264_H_)
#define PERI_VPU_G1_H264_H_                      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MM1CVTKZ_ca53) || defined(CPU_MIMX8MM1DVTLZ_ca53))
#include "MIMX8MM1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM1CVTKZ_cm4) || defined(CPU_MIMX8MM1DVTLZ_cm4))
#include "MIMX8MM1_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_ca53) || defined(CPU_MIMX8MM2DVTLZ_ca53))
#include "MIMX8MM2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM2CVTKZ_cm4) || defined(CPU_MIMX8MM2DVTLZ_cm4))
#include "MIMX8MM2_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_ca53) || defined(CPU_MIMX8MM3DVTLZ_ca53))
#include "MIMX8MM3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM3CVTKZ_cm4) || defined(CPU_MIMX8MM3DVTLZ_cm4))
#include "MIMX8MM3_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_ca53) || defined(CPU_MIMX8MM4DVTLZ_ca53))
#include "MIMX8MM4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM4CVTKZ_cm4) || defined(CPU_MIMX8MM4DVTLZ_cm4))
#include "MIMX8MM4_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_ca53) || defined(CPU_MIMX8MM5DVTLZ_ca53))
#include "MIMX8MM5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM5CVTKZ_cm4) || defined(CPU_MIMX8MM5DVTLZ_cm4))
#include "MIMX8MM5_cm4_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_ca53) || defined(CPU_MIMX8MM6DVTLZ_ca53))
#include "MIMX8MM6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MM6CVTKZ_cm4) || defined(CPU_MIMX8MM6DVTLZ_cm4))
#include "MIMX8MM6_cm4_COMMON.h"
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
   -- VPU_G1_H264 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_H264_Peripheral_Access_Layer VPU_G1_H264 Peripheral Access Layer
 * @{
 */

/** VPU_G1_H264 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[16];
  __IO uint32_t SWREG4;                            /**< Decoder control register 1 (picture parameters), offset: 0x10 */
  __IO uint32_t SWREG5;                            /**< Decoder control register 2 (stream decoding table selects), offset: 0x14 */
  __IO uint32_t SWREG6;                            /**< Decoder control register 3 (stream buffer information), offset: 0x18 */
  __IO uint32_t SWREG7;                            /**< Decoder control register 4 (H264, VC-1, VP6 and progressive JPEG control), offset: 0x1C */
  __IO uint32_t SWREG8;                            /**< Decoder control register 5 (H264, VC-1, VP6, Progressive JPEG and RV control), offset: 0x20 */
  __IO uint32_t SWREG9;                            /**< Decoder control register 6 / base address for MB-control (RLC) / VC-1 intensity control 0/ VP6,VP7,VP8 ctrl-stream length/ RV pic slice amount, offset: 0x24 */
  __IO uint32_t SWREG10;                           /**< Base address for differential motion vector base address (RLC-mode) /H264 P initial fwd ref pic list register (4-9)/ VC-1 intensity control 1/ VP7 and VP8 segmentation base register, offset: 0x28 */
  __IO uint32_t SWREG11;                           /**< Decoder control register 7 (VLC) / base address for H.264 intra prediction 4x4 / base address for MPEG-4 DC component (RLC) / H264 P initial fwd ref pic list register (10-15) / VC-1 intensity control 2, offset: 0x2C */
       uint8_t RESERVED_1[8];
  __IO uint32_t SWREG14;                           /**< Base address for reference picture index 0 / base address for JPEG decoder output chrominance picture, offset: 0x38 */
  __IO uint32_t SWREG15;                           /**< Base address for reference picture index 1 / JPEG control, offset: 0x3C */
  __IO uint32_t SWREG16;                           /**< Base address for reference picture index 2 / List of VLC code lengths in first JPEG AC table, offset: 0x40 */
  __IO uint32_t SWREG17;                           /**< Base address for reference picture index 3 / List of VLC code lengths in first JPEG AC table, offset: 0x44 */
  __IO uint32_t SWREG18;                           /**< Base address for reference picture index 4 / VC1 control / MPEG4 MVD control/ List of VLC code lengths in first JPEG AC table / VC-1 intensity control 4 / VP6/VP7, VP8 Golden refer picture base, offset: 0x48 */
  __IO uint32_t SWREG19;                           /**< Base address for reference picture index 5 / MPEG4 TRB/TRD delta 0 / VC-1 intensity control 3 List of VLC code lengths in first/second JPEG AC table / VP6/VP7 scan maps, offset: 0x4C */
  __IO uint32_t SWREG20;                           /**< Base address for reference picture index 6 / / MPEG4 TRB/TRD delta -1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps, offset: 0x50 */
  __IO uint32_t SWREG21;                           /**< Base address for reference picture index 7 / MPEG4 TRB/TRD delta 1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps, offset: 0x54 */
  __IO uint32_t SWREG22;                           /**< Base address for reference picture index 8 / List of VLC code lengths in second JPEG AC table / VP6 scan maps / VP7,VP8 DCT stream 1 base, offset: 0x58 */
  __IO uint32_t SWREG23;                           /**< Base address for reference picture index 9 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 2 base, offset: 0x5C */
  __IO uint32_t SWREG24;                           /**< Base address for reference picture index 10 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 3 base, offset: 0x60 */
  __IO uint32_t SWREG25;                           /**< Base address for reference picture index 11 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 4 base, offset: 0x64 */
  __IO uint32_t SWREG26;                           /**< Base address for reference picture index 12 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 5 base, offset: 0x68 */
  __IO uint32_t SWREG27;                           /**< Base address for reference picture index 13 / VC-1 bitpl mbctrl or VP6,VP7,VP8 ctrl stream base /Progressive JPEG DC table, offset: 0x6C */
  __IO uint32_t SWREG28;                           /**< Base address for reference picture index 14 / VP6 scan maps /Progressive JPEG DC table / VP7,VP8 DCT stream 6 base, offset: 0x70 */
  __IO uint32_t SWREG29;                           /**< Base address for reference picture index 15 / VP6 scan maps / VP7,VP8 DCT stream 7 base, offset: 0x74 */
  __IO uint32_t SWREG30;                           /**< Reference picture numbers for index 0 and 1 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter mb level adjusts, offset: 0x78 */
  __IO uint32_t SWREG31;                           /**< Reference picture numbers for index 2 and 3 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter ref pic level adjusts, offset: 0x7C */
  __IO uint32_t SWREG32;                           /**< Reference picture numbers for index 4 and 5 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter levels, offset: 0x80 */
  __IO uint32_t SWREG33;                           /**< Reference picture numbers for index 6 and 7 (H264 VLC) / VP6 scan maps / VP7,VP8 quantization values, offset: 0x84 */
  __IO uint32_t SWREG34;                           /**< Reference picture numbers for index 8 and 9 (H264 VLC) / MPEG4, VC1, VPx prediction filter taps, offset: 0x88 */
  __IO uint32_t SWREG35;                           /**< Reference picture numbers for index 10 and 11 (H264 VLC) / VC1, VPx prediction filter taps, offset: 0x8C */
  __IO uint32_t SWREG36;                           /**< Reference picture numbers for index 12 and 13 (H264 VLC) / VC1, VPx prediction filter taps, offset: 0x90 */
  __IO uint32_t SWREG37;                           /**< Reference picture numbers for index 14 and 15 (H264 VLC) / VPx prediction filter taps, offset: 0x94 */
  __IO uint32_t SWREG38;                           /**< Reference picture long term flags (H264 VLC) / VPx prediction filter taps, offset: 0x98 */
  __IO uint32_t SWREG39;                           /**< Reference picture valid flags (H264 VLC) / VPx prediction filter taps, offset: 0x9C */
       uint8_t RESERVED_2[8];
  __IO uint32_t SWREG42_H264;                      /**< bi_dir initial ref pic list register (0-2) / VP6 prediction filter taps / Progressive JPEG Cb ACDC coefficient base, offset: 0xA8 */
  __IO uint32_t SWREG43_H264;                      /**< bi-dir initial ref pic list register (3-5) / VP6 prediction filter taps / Progressive JPEG Cr ACDC coefficient base, offset: 0xAC */
  __IO uint32_t SWREG44_H264;                      /**< bi-dir initial ref pic list register (6-8) / VP6 prediction filter taps, offset: 0xB0 */
  __IO uint32_t SWREG45;                           /**< bi-dir initial ref pic list register (9-11) / VP6 prediction filter taps, offset: 0xB4 */
  __IO uint32_t SWREG46;                           /**< bi-dir initial ref pic list register (12-14) / VP7,VP8 quantization values, offset: 0xB8 */
  __IO uint32_t SWREG47;                           /**< bi-dir and P fwd initial ref pic list register (15 and P 0-3) / VP7,VP8 quantization values, offset: 0xBC */
} VPU_G1_H264_Type;

/* ----------------------------------------------------------------------------
   -- VPU_G1_H264 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_H264_Register_Masks VPU_G1_H264 Register Masks
 * @{
 */

/*! @name SWREG4 - Decoder control register 1 (picture parameters) */
/*! @{ */

#define VPU_G1_H264_SWREG4_SW_REF_FRAMES_MASK    (0x1FU)
#define VPU_G1_H264_SWREG4_SW_REF_FRAMES_SHIFT   (0U)
/*! SW_REF_FRAMES - H.264: num_ref_frames, maximum number of short and long term reference frames in
 *    decoded picture buffer VC-1: num_ref semantics
 */
#define VPU_G1_H264_SWREG4_SW_REF_FRAMES(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_REF_FRAMES_SHIFT)) & VPU_G1_H264_SWREG4_SW_REF_FRAMES_MASK)

#define VPU_G1_H264_SWREG4_SW_ALT_SCAN_E_MASK    (0x40U)
#define VPU_G1_H264_SWREG4_SW_ALT_SCAN_E_SHIFT   (6U)
/*! SW_ALT_SCAN_E - indicates alternative vertical scan method used for interlaced frames */
#define VPU_G1_H264_SWREG4_SW_ALT_SCAN_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_ALT_SCAN_E_SHIFT)) & VPU_G1_H264_SWREG4_SW_ALT_SCAN_E_MASK)

#define VPU_G1_H264_SWREG4_SW_MB_HEIGHT_OFF_MASK (0x780U)
#define VPU_G1_H264_SWREG4_SW_MB_HEIGHT_OFF_SHIFT (7U)
/*! SW_MB_HEIGHT_OFF - The amount of meaningful vertical pixels in last MB (height offset 0 if
 *    exactly 16 pixels multiple picture and all the vertical pixels in last MB are meaningfull
 */
#define VPU_G1_H264_SWREG4_SW_MB_HEIGHT_OFF(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_MB_HEIGHT_OFF_SHIFT)) & VPU_G1_H264_SWREG4_SW_MB_HEIGHT_OFF_MASK)

#define VPU_G1_H264_SWREG4_SW_PIC_MB_HEIGHT_P_MASK (0x7F800U)
#define VPU_G1_H264_SWREG4_SW_PIC_MB_HEIGHT_P_SHIFT (11U)
/*! SW_PIC_MB_HEIGHT_P - Picture height in macroblocks =((height in pixels+15)/16). Picture height
 *    is informed as size of the (progressive) frame also for single field (of interlaced content) is
 *    being decoded
 */
#define VPU_G1_H264_SWREG4_SW_PIC_MB_HEIGHT_P(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_PIC_MB_HEIGHT_P_SHIFT)) & VPU_G1_H264_SWREG4_SW_PIC_MB_HEIGHT_P_MASK)

#define VPU_G1_H264_SWREG4_SW_MB_WIDTH_OFF_MASK  (0x780000U)
#define VPU_G1_H264_SWREG4_SW_MB_WIDTH_OFF_SHIFT (19U)
/*! SW_MB_WIDTH_OFF - The amount of meaningfull horizontal pixels in last MB (width offset) 0 if
 *    exactly 16 pixels multiple picture and all the horizontal pixels in last MB are meaningfull
 */
#define VPU_G1_H264_SWREG4_SW_MB_WIDTH_OFF(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_MB_WIDTH_OFF_SHIFT)) & VPU_G1_H264_SWREG4_SW_MB_WIDTH_OFF_MASK)

#define VPU_G1_H264_SWREG4_SW_PIC_MB_WIDTH_MASK  (0xFF800000U)
#define VPU_G1_H264_SWREG4_SW_PIC_MB_WIDTH_SHIFT (23U)
/*! SW_PIC_MB_WIDTH - Picture width in macroblocks = ((width in pixels + 15) /16) */
#define VPU_G1_H264_SWREG4_SW_PIC_MB_WIDTH(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG4_SW_PIC_MB_WIDTH_SHIFT)) & VPU_G1_H264_SWREG4_SW_PIC_MB_WIDTH_MASK)
/*! @} */

/*! @name SWREG5 - Decoder control register 2 (stream decoding table selects) */
/*! @{ */

#define VPU_G1_H264_SWREG5_SW_FIELDPIC_FLAG_E_MASK (0x1U)
#define VPU_G1_H264_SWREG5_SW_FIELDPIC_FLAG_E_SHIFT (0U)
/*! SW_FIELDPIC_FLAG_E - Flag for streamd that field_pic_flag exists in stream */
#define VPU_G1_H264_SWREG5_SW_FIELDPIC_FLAG_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_FIELDPIC_FLAG_E_SHIFT)) & VPU_G1_H264_SWREG5_SW_FIELDPIC_FLAG_E_MASK)

#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET2_MASK (0x7C000U)
#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET2_SHIFT (14U)
/*! SW_CH_QP_OFFSET2 - Chroma Qp filter offset for cr type */
#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET2(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET2_SHIFT)) & VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET2_MASK)

#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET_MASK  (0xF80000U)
#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET_SHIFT (19U)
/*! SW_CH_QP_OFFSET - Chroma Qp filter offset. (For H.264 this offset concerns Cb only) */
#define VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET_SHIFT)) & VPU_G1_H264_SWREG5_SW_CH_QP_OFFSET_MASK)

#define VPU_G1_H264_SWREG5_SW_TYPE1_QUANT_E_MASK (0x1000000U)
#define VPU_G1_H264_SWREG5_SW_TYPE1_QUANT_E_SHIFT (24U)
#define VPU_G1_H264_SWREG5_SW_TYPE1_QUANT_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_TYPE1_QUANT_E_SHIFT)) & VPU_G1_H264_SWREG5_SW_TYPE1_QUANT_E_MASK)

#define VPU_G1_H264_SWREG5_SW_SYNC_MARKER_E_MASK (0x2000000U)
#define VPU_G1_H264_SWREG5_SW_SYNC_MARKER_E_SHIFT (25U)
/*! SW_SYNC_MARKER_E - Sync markers enable
 *  0b0..synch markers are not used
 *  0b1..synch markers are used.
 */
#define VPU_G1_H264_SWREG5_SW_SYNC_MARKER_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_SYNC_MARKER_E_SHIFT)) & VPU_G1_H264_SWREG5_SW_SYNC_MARKER_E_MASK)

#define VPU_G1_H264_SWREG5_SW_STRM_START_BIT_MASK (0xFC000000U)
#define VPU_G1_H264_SWREG5_SW_STRM_START_BIT_SHIFT (26U)
/*! SW_STRM_START_BIT - Exact bit of stream start word where decoding can be started (assosiates with sw_rlc_vlc_base) */
#define VPU_G1_H264_SWREG5_SW_STRM_START_BIT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG5_SW_STRM_START_BIT_SHIFT)) & VPU_G1_H264_SWREG5_SW_STRM_START_BIT_MASK)
/*! @} */

/*! @name SWREG6 - Decoder control register 3 (stream buffer information) */
/*! @{ */

#define VPU_G1_H264_SWREG6_SW_STREAM_LEN_MASK    (0xFFFFFFU)
#define VPU_G1_H264_SWREG6_SW_STREAM_LEN_SHIFT   (0U)
/*! SW_STREAM_LEN - Amount of stream data bytes in input buffer. If the given buffer size is not
 *    enough for finishing the picture the corresponding interrupt is given and new stream buffer base
 *    address and stream buffer size information should be given (assosiates with sw_rlc_vlc_base).
 *    For VC-1/VP6 the buffer must include data for one picture/slice of the picture For
 *    H264/MPEG4/H263/MPEG2/MPEG1 the buffer must include at least data for one slice/VP of the picture For
 *    JPEG the buffer size must be a multiple of 256 bytes or the amount of data for one picture.
 */
#define VPU_G1_H264_SWREG6_SW_STREAM_LEN(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG6_SW_STREAM_LEN_SHIFT)) & VPU_G1_H264_SWREG6_SW_STREAM_LEN_MASK)

#define VPU_G1_H264_SWREG6_SW_CH_8PIX_ILEAV_E_MASK (0x1000000U)
#define VPU_G1_H264_SWREG6_SW_CH_8PIX_ILEAV_E_SHIFT (24U)
/*! SW_CH_8PIX_ILEAV_E - Enable for additional chrominance data format writing where decoder writes
 *    chrominance in group of 8 pixels of Cb and then corresponding 8 pixels of Cr. Data is written
 *    to sw_dec_ch8pix_base. Cannot be used if tiled mode is enabled
 */
#define VPU_G1_H264_SWREG6_SW_CH_8PIX_ILEAV_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG6_SW_CH_8PIX_ILEAV_E_SHIFT)) & VPU_G1_H264_SWREG6_SW_CH_8PIX_ILEAV_E_MASK)

#define VPU_G1_H264_SWREG6_SW_INIT_QP_MASK       (0x7E000000U)
#define VPU_G1_H264_SWREG6_SW_INIT_QP_SHIFT      (25U)
/*! SW_INIT_QP - Initial value for quantization parameter (picture quantizer). */
#define VPU_G1_H264_SWREG6_SW_INIT_QP(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG6_SW_INIT_QP_SHIFT)) & VPU_G1_H264_SWREG6_SW_INIT_QP_MASK)

#define VPU_G1_H264_SWREG6_SW_START_CODE_E_MASK  (0x80000000U)
#define VPU_G1_H264_SWREG6_SW_START_CODE_E_SHIFT (31U)
/*! SW_START_CODE_E - Bit for indicating stream start code existence:
 *  0b0..stream doesn't contain start codes
 *  0b1..stream contains start codes
 */
#define VPU_G1_H264_SWREG6_SW_START_CODE_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG6_SW_START_CODE_E_SHIFT)) & VPU_G1_H264_SWREG6_SW_START_CODE_E_MASK)
/*! @} */

/*! @name SWREG7 - Decoder control register 4 (H264, VC-1, VP6 and progressive JPEG control) */
/*! @{ */

#define VPU_G1_H264_SWREG7_SW_FRAMENUM_MASK      (0xFFFFU)
#define VPU_G1_H264_SWREG7_SW_FRAMENUM_SHIFT     (0U)
/*! SW_FRAMENUM - current frame_num, used to identify short-term reference frames. Used in reference picture reordering */
#define VPU_G1_H264_SWREG7_SW_FRAMENUM(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_FRAMENUM_SHIFT)) & VPU_G1_H264_SWREG7_SW_FRAMENUM_MASK)

#define VPU_G1_H264_SWREG7_SW_FRAMENUM_LEN_MASK  (0x1F0000U)
#define VPU_G1_H264_SWREG7_SW_FRAMENUM_LEN_SHIFT (16U)
/*! SW_FRAMENUM_LEN - H.264: Bit length of frame_num in data stream RV: frame size length. Informs
 *    how many bits in stream are used for frame size (HW discards these bits)
 */
#define VPU_G1_H264_SWREG7_SW_FRAMENUM_LEN(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_FRAMENUM_LEN_SHIFT)) & VPU_G1_H264_SWREG7_SW_FRAMENUM_LEN_MASK)

#define VPU_G1_H264_SWREG7_SW_AVS_H264_H_EXT_MASK (0x2000000U)
#define VPU_G1_H264_SWREG7_SW_AVS_H264_H_EXT_SHIFT (25U)
/*! SW_AVS_H264_H_EXT - Resolution extension to support 4k resolution for AVS/H264. Used as MSB of sw_pic_mb_height */
#define VPU_G1_H264_SWREG7_SW_AVS_H264_H_EXT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_AVS_H264_H_EXT_SHIFT)) & VPU_G1_H264_SWREG7_SW_AVS_H264_H_EXT_MASK)

#define VPU_G1_H264_SWREG7_SW_WEIGHT_BIPR_IDC_MASK (0xC000000U)
#define VPU_G1_H264_SWREG7_SW_WEIGHT_BIPR_IDC_SHIFT (26U)
/*! SW_WEIGHT_BIPR_IDC - weighted prediction specification for B slices:
 *  0b00..default weighted prediction is applied to B slices
 *  0b01..explicit weighted prediction shall be applied to B slices
 *  0b10..implicit weighted prediction shall be applied to B slices
 */
#define VPU_G1_H264_SWREG7_SW_WEIGHT_BIPR_IDC(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_WEIGHT_BIPR_IDC_SHIFT)) & VPU_G1_H264_SWREG7_SW_WEIGHT_BIPR_IDC_MASK)

#define VPU_G1_H264_SWREG7_SW_WEIGHT_PRED_E_MASK (0x10000000U)
#define VPU_G1_H264_SWREG7_SW_WEIGHT_PRED_E_SHIFT (28U)
/*! SW_WEIGHT_PRED_E - Weighted prediction enable for P slices */
#define VPU_G1_H264_SWREG7_SW_WEIGHT_PRED_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_WEIGHT_PRED_E_SHIFT)) & VPU_G1_H264_SWREG7_SW_WEIGHT_PRED_E_MASK)

#define VPU_G1_H264_SWREG7_SW_DIR_8X8_INFER_E_MASK (0x20000000U)
#define VPU_G1_H264_SWREG7_SW_DIR_8X8_INFER_E_SHIFT (29U)
/*! SW_DIR_8X8_INFER_E - Specifies the method to use to derive luma motion vectors in B_skip,
 *    B_Direct_16x16 and B_direct_8x8_inference_flag (see direct_8x8_inference flag)
 */
#define VPU_G1_H264_SWREG7_SW_DIR_8X8_INFER_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_DIR_8X8_INFER_E_SHIFT)) & VPU_G1_H264_SWREG7_SW_DIR_8X8_INFER_E_MASK)

#define VPU_G1_H264_SWREG7_SW_BLACKWHITE_E_MASK  (0x40000000U)
#define VPU_G1_H264_SWREG7_SW_BLACKWHITE_E_SHIFT (30U)
/*! SW_BLACKWHITE_E
 *  0b0..4:2:0 sampling format
 *  0b1..4:0:0 sampling format (H264 monochroma)
 */
#define VPU_G1_H264_SWREG7_SW_BLACKWHITE_E(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_BLACKWHITE_E_SHIFT)) & VPU_G1_H264_SWREG7_SW_BLACKWHITE_E_MASK)

#define VPU_G1_H264_SWREG7_SW_CABAC_E_MASK       (0x80000000U)
#define VPU_G1_H264_SWREG7_SW_CABAC_E_SHIFT      (31U)
/*! SW_CABAC_E - CABAC enable */
#define VPU_G1_H264_SWREG7_SW_CABAC_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG7_SW_CABAC_E_SHIFT)) & VPU_G1_H264_SWREG7_SW_CABAC_E_MASK)
/*! @} */

/*! @name SWREG8 - Decoder control register 5 (H264, VC-1, VP6, Progressive JPEG and RV control) */
/*! @{ */

#define VPU_G1_H264_SWREG8_SW_IDR_PIC_ID_MASK    (0xFFFFU)
#define VPU_G1_H264_SWREG8_SW_IDR_PIC_ID_SHIFT   (0U)
/*! SW_IDR_PIC_ID - idr_pic_id, identifies IDR (instantaneous decoding refresh) picture */
#define VPU_G1_H264_SWREG8_SW_IDR_PIC_ID(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_IDR_PIC_ID_SHIFT)) & VPU_G1_H264_SWREG8_SW_IDR_PIC_ID_MASK)

#define VPU_G1_H264_SWREG8_SW_IDR_PIC_E_MASK     (0x10000U)
#define VPU_G1_H264_SWREG8_SW_IDR_PIC_E_SHIFT    (16U)
/*! SW_IDR_PIC_E - IDR (instantaneous decoding refresh) picture flag. */
#define VPU_G1_H264_SWREG8_SW_IDR_PIC_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_IDR_PIC_E_SHIFT)) & VPU_G1_H264_SWREG8_SW_IDR_PIC_E_MASK)

#define VPU_G1_H264_SWREG8_SW_REFPIC_MK_LEN_MASK (0xFFE0000U)
#define VPU_G1_H264_SWREG8_SW_REFPIC_MK_LEN_SHIFT (17U)
/*! SW_REFPIC_MK_LEN - Length of decoded reference picture marking bits */
#define VPU_G1_H264_SWREG8_SW_REFPIC_MK_LEN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_REFPIC_MK_LEN_SHIFT)) & VPU_G1_H264_SWREG8_SW_REFPIC_MK_LEN_MASK)

#define VPU_G1_H264_SWREG8_SW_8X8TRANS_FLAG_E_MASK (0x10000000U)
#define VPU_G1_H264_SWREG8_SW_8X8TRANS_FLAG_E_SHIFT (28U)
/*! SW_8X8TRANS_FLAG_E - 8x8 transform flag enable for stream decoding */
#define VPU_G1_H264_SWREG8_SW_8X8TRANS_FLAG_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_8X8TRANS_FLAG_E_SHIFT)) & VPU_G1_H264_SWREG8_SW_8X8TRANS_FLAG_E_MASK)

#define VPU_G1_H264_SWREG8_SW_RDPIC_CNT_PRES_MASK (0x20000000U)
#define VPU_G1_H264_SWREG8_SW_RDPIC_CNT_PRES_SHIFT (29U)
/*! SW_RDPIC_CNT_PRES - redundant_pic_cnt_present_flag specifies whether redundant_pic_cnt syntax elements are present in the slice header. */
#define VPU_G1_H264_SWREG8_SW_RDPIC_CNT_PRES(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_RDPIC_CNT_PRES_SHIFT)) & VPU_G1_H264_SWREG8_SW_RDPIC_CNT_PRES_MASK)

#define VPU_G1_H264_SWREG8_SW_FILT_CTRL_PRES_MASK (0x40000000U)
#define VPU_G1_H264_SWREG8_SW_FILT_CTRL_PRES_SHIFT (30U)
/*! SW_FILT_CTRL_PRES - deblocking_filter_control_present_flag indicates whether extra variables
 *    controlling characteristics of the deblocking filter are present in the slice header.
 */
#define VPU_G1_H264_SWREG8_SW_FILT_CTRL_PRES(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_FILT_CTRL_PRES_SHIFT)) & VPU_G1_H264_SWREG8_SW_FILT_CTRL_PRES_MASK)

#define VPU_G1_H264_SWREG8_SW_CONST_INTRA_E_MASK (0x80000000U)
#define VPU_G1_H264_SWREG8_SW_CONST_INTRA_E_SHIFT (31U)
/*! SW_CONST_INTRA_E - constrained_intra_pred_flag equal to 1 specifies that intra prediction uses
 *    only neighbouring intra macroblocks in prediction. When equal to 0 also neighbouring inter
 *    macroblocks are used in intra prediction process.
 */
#define VPU_G1_H264_SWREG8_SW_CONST_INTRA_E(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG8_SW_CONST_INTRA_E_SHIFT)) & VPU_G1_H264_SWREG8_SW_CONST_INTRA_E_MASK)
/*! @} */

/*! @name SWREG9 - Decoder control register 6 / base address for MB-control (RLC) / VC-1 intensity control 0/ VP6,VP7,VP8 ctrl-stream length/ RV pic slice amount */
/*! @{ */

#define VPU_G1_H264_SWREG9_SW_POC_LENGTH_MASK    (0xFFU)
#define VPU_G1_H264_SWREG9_SW_POC_LENGTH_SHIFT   (0U)
/*! SW_POC_LENGTH - Length of picture order count field in stream */
#define VPU_G1_H264_SWREG9_SW_POC_LENGTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG9_SW_POC_LENGTH_SHIFT)) & VPU_G1_H264_SWREG9_SW_POC_LENGTH_MASK)

#define VPU_G1_H264_SWREG9_SW_REFIDX0_ACTIVE_MASK (0x7C000U)
#define VPU_G1_H264_SWREG9_SW_REFIDX0_ACTIVE_SHIFT (14U)
/*! SW_REFIDX0_ACTIVE - Specifies the maximum reference index that can be used while decoding inter
 *    predicted macro blocks. This is same as in previous decoders (width increased with q bit)
 */
#define VPU_G1_H264_SWREG9_SW_REFIDX0_ACTIVE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG9_SW_REFIDX0_ACTIVE_SHIFT)) & VPU_G1_H264_SWREG9_SW_REFIDX0_ACTIVE_MASK)

#define VPU_G1_H264_SWREG9_SW_REFIDX1_ACTIVE_MASK (0xF80000U)
#define VPU_G1_H264_SWREG9_SW_REFIDX1_ACTIVE_SHIFT (19U)
/*! SW_REFIDX1_ACTIVE - Specifies the maximum reference index that can be used while decoding inter predicted macro blocks. */
#define VPU_G1_H264_SWREG9_SW_REFIDX1_ACTIVE(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG9_SW_REFIDX1_ACTIVE_SHIFT)) & VPU_G1_H264_SWREG9_SW_REFIDX1_ACTIVE_MASK)

#define VPU_G1_H264_SWREG9_SW_PPS_ID_MASK        (0xFF000000U)
#define VPU_G1_H264_SWREG9_SW_PPS_ID_SHIFT       (24U)
/*! SW_PPS_ID - pic_parameter_set_id, identifies the picture parameter set that is referred to in the slice header. */
#define VPU_G1_H264_SWREG9_SW_PPS_ID(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG9_SW_PPS_ID_SHIFT)) & VPU_G1_H264_SWREG9_SW_PPS_ID_MASK)
/*! @} */

/*! @name SWREG10 - Base address for differential motion vector base address (RLC-mode) /H264 P initial fwd ref pic list register (4-9)/ VC-1 intensity control 1/ VP7 and VP8 segmentation base register */
/*! @{ */

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F4_MASK (0x1FU)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F4_SHIFT (0U)
/*! SW_PINIT_RLIST_F4 - Initial reference picture list for P forward picid 4 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F4(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F4_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F4_MASK)

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F5_MASK (0x3E0U)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F5_SHIFT (5U)
/*! SW_PINIT_RLIST_F5 - Initial reference picture list for P forward picid 5 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F5(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F5_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F5_MASK)

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F6_MASK (0x7C00U)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F6_SHIFT (10U)
/*! SW_PINIT_RLIST_F6 - Initial reference picture list for P forward picid 6 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F6(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F6_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F6_MASK)

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F7_MASK (0xF8000U)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F7_SHIFT (15U)
/*! SW_PINIT_RLIST_F7 - Initial reference picture list for P forward picid 7 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F7(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F7_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F7_MASK)

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F8_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F8_SHIFT (20U)
/*! SW_PINIT_RLIST_F8 - Initial reference picture list for P forward picid 8 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F8(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F8_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F8_MASK)

#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F9_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F9_SHIFT (25U)
/*! SW_PINIT_RLIST_F9 - Initial reference picture list for P forward picid 9 */
#define VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F9(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F9_SHIFT)) & VPU_G1_H264_SWREG10_SW_PINIT_RLIST_F9_MASK)
/*! @} */

/*! @name SWREG11 - Decoder control register 7 (VLC) / base address for H.264 intra prediction 4x4 / base address for MPEG-4 DC component (RLC) / H264 P initial fwd ref pic list register (10-15) / VC-1 intensity control 2 */
/*! @{ */

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F10_MASK (0x1FU)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F10_SHIFT (0U)
/*! SW_PINIT_RLIST_F10 - Initial reference picture list for P forward picid 10 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F10(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F10_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F10_MASK)

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F11_MASK (0x3E0U)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F11_SHIFT (5U)
/*! SW_PINIT_RLIST_F11 - Initial reference picture list for P forward picid 11 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F11(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F11_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F11_MASK)

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F12_MASK (0x7C00U)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F12_SHIFT (10U)
/*! SW_PINIT_RLIST_F12 - Initial reference picture list for P forward picid 12 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F12(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F12_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F12_MASK)

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F13_MASK (0xF8000U)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F13_SHIFT (15U)
/*! SW_PINIT_RLIST_F13 - Initial reference picture list for P forward picid 13 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F13(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F13_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F13_MASK)

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F14_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F14_SHIFT (20U)
/*! SW_PINIT_RLIST_F14 - Initial reference picture list for P forward picid 14 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F14(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F14_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F14_MASK)

#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F15_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F15_SHIFT (25U)
/*! SW_PINIT_RLIST_F15 - Initial reference picture list for P forward picid 15 */
#define VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F15(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F15_SHIFT)) & VPU_G1_H264_SWREG11_SW_PINIT_RLIST_F15_MASK)
/*! @} */

/*! @name SWREG14 - Base address for reference picture index 0 / base address for JPEG decoder output chrominance picture */
/*! @{ */

#define VPU_G1_H264_SWREG14_SW_REFER0_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG14_SW_REFER0_TOPC_E_SHIFT (0U)
/*! SW_REFER0_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..Bottom field is closer to current picture
 *  0b1..Top field is closer to current picture
 */
#define VPU_G1_H264_SWREG14_SW_REFER0_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG14_SW_REFER0_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG14_SW_REFER0_TOPC_E_MASK)

#define VPU_G1_H264_SWREG14_SW_REFER0_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG14_SW_REFER0_FIELD_E_SHIFT (1U)
/*! SW_REFER0_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG14_SW_REFER0_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG14_SW_REFER0_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG14_SW_REFER0_FIELD_E_MASK)

#define VPU_G1_H264_SWREG14_SW_REFER0_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG14_SW_REFER0_BASE_SHIFT (2U)
/*! SW_REFER0_BASE - Base address for reference picture index 0. See picture index definition from toplevel_sp */
#define VPU_G1_H264_SWREG14_SW_REFER0_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG14_SW_REFER0_BASE_SHIFT)) & VPU_G1_H264_SWREG14_SW_REFER0_BASE_MASK)
/*! @} */

/*! @name SWREG15 - Base address for reference picture index 1 / JPEG control */
/*! @{ */

#define VPU_G1_H264_SWREG15_SW_REFER1_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG15_SW_REFER1_TOPC_E_SHIFT (0U)
/*! SW_REFER1_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG15_SW_REFER1_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG15_SW_REFER1_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG15_SW_REFER1_TOPC_E_MASK)

#define VPU_G1_H264_SWREG15_SW_REFER1_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG15_SW_REFER1_FIELD_E_SHIFT (1U)
/*! SW_REFER1_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG15_SW_REFER1_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG15_SW_REFER1_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG15_SW_REFER1_FIELD_E_MASK)

#define VPU_G1_H264_SWREG15_SW_REFER1_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG15_SW_REFER1_BASE_SHIFT (2U)
/*! SW_REFER1_BASE - Base address for reference picture index 1. See picture index definition from
 *    toplevel_sp. For VP8 this base address is used as Chrominance base address for reference
 *    picture 0 (if vp8 stride configuration is enabled)
 */
#define VPU_G1_H264_SWREG15_SW_REFER1_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG15_SW_REFER1_BASE_SHIFT)) & VPU_G1_H264_SWREG15_SW_REFER1_BASE_MASK)
/*! @} */

/*! @name SWREG16 - Base address for reference picture index 2 / List of VLC code lengths in first JPEG AC table */
/*! @{ */

#define VPU_G1_H264_SWREG16_SW_REFER2_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG16_SW_REFER2_TOPC_E_SHIFT (0U)
/*! SW_REFER2_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG16_SW_REFER2_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG16_SW_REFER2_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG16_SW_REFER2_TOPC_E_MASK)

#define VPU_G1_H264_SWREG16_SW_REFER2_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG16_SW_REFER2_FIELD_E_SHIFT (1U)
/*! SW_REFER2_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG16_SW_REFER2_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG16_SW_REFER2_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG16_SW_REFER2_FIELD_E_MASK)

#define VPU_G1_H264_SWREG16_SW_REFER2_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG16_SW_REFER2_BASE_SHIFT (2U)
/*! SW_REFER2_BASE - Base address for reference picture index 2. See picture index definition from
 *    toplevel_sp. For VP8 video this base address is used as Golden reference chrominance base
 *    address (if vp8 stride configuration is enabled)
 */
#define VPU_G1_H264_SWREG16_SW_REFER2_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG16_SW_REFER2_BASE_SHIFT)) & VPU_G1_H264_SWREG16_SW_REFER2_BASE_MASK)
/*! @} */

/*! @name SWREG17 - Base address for reference picture index 3 / List of VLC code lengths in first JPEG AC table */
/*! @{ */

#define VPU_G1_H264_SWREG17_SW_REFER3_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG17_SW_REFER3_TOPC_E_SHIFT (0U)
/*! SW_REFER3_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG17_SW_REFER3_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG17_SW_REFER3_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG17_SW_REFER3_TOPC_E_MASK)

#define VPU_G1_H264_SWREG17_SW_REFER3_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG17_SW_REFER3_FIELD_E_SHIFT (1U)
/*! SW_REFER3_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG17_SW_REFER3_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG17_SW_REFER3_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG17_SW_REFER3_FIELD_E_MASK)

#define VPU_G1_H264_SWREG17_SW_REFER3_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG17_SW_REFER3_BASE_SHIFT (2U)
/*! SW_REFER3_BASE - Base address for reference picture index 3. See picture index definition from
 *    toplevel_sp. For VP8 video this base address is used as Alternate reference chrominance base
 *    address (if vp8 stride configuration is enabled)
 */
#define VPU_G1_H264_SWREG17_SW_REFER3_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG17_SW_REFER3_BASE_SHIFT)) & VPU_G1_H264_SWREG17_SW_REFER3_BASE_MASK)
/*! @} */

/*! @name SWREG18 - Base address for reference picture index 4 / VC1 control / MPEG4 MVD control/ List of VLC code lengths in first JPEG AC table / VC-1 intensity control 4 / VP6/VP7, VP8 Golden refer picture base */
/*! @{ */

#define VPU_G1_H264_SWREG18_SW_REFER4_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG18_SW_REFER4_TOPC_E_SHIFT (0U)
/*! SW_REFER4_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG18_SW_REFER4_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG18_SW_REFER4_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG18_SW_REFER4_TOPC_E_MASK)

#define VPU_G1_H264_SWREG18_SW_REFER4_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG18_SW_REFER4_FIELD_E_SHIFT (1U)
/*! SW_REFER4_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG18_SW_REFER4_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG18_SW_REFER4_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG18_SW_REFER4_FIELD_E_MASK)

#define VPU_G1_H264_SWREG18_SW_REFER4_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG18_SW_REFER4_BASE_SHIFT (2U)
/*! SW_REFER4_BASE - H264: Base address for reference picture index 4 VP6/VP7/VP8: Base address for
 *    Golden reference picture (corresponds picid 4)
 */
#define VPU_G1_H264_SWREG18_SW_REFER4_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG18_SW_REFER4_BASE_SHIFT)) & VPU_G1_H264_SWREG18_SW_REFER4_BASE_MASK)
/*! @} */

/*! @name SWREG19 - Base address for reference picture index 5 / MPEG4 TRB/TRD delta 0 / VC-1 intensity control 3 List of VLC code lengths in first/second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_H264_SWREG19_SW_REFER5_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG19_SW_REFER5_TOPC_E_SHIFT (0U)
/*! SW_REFER5_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG19_SW_REFER5_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG19_SW_REFER5_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG19_SW_REFER5_TOPC_E_MASK)

#define VPU_G1_H264_SWREG19_SW_REFER5_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG19_SW_REFER5_FIELD_E_SHIFT (1U)
/*! SW_REFER5_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG19_SW_REFER5_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG19_SW_REFER5_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG19_SW_REFER5_FIELD_E_MASK)

#define VPU_G1_H264_SWREG19_SW_REFER5_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG19_SW_REFER5_BASE_SHIFT (2U)
/*! SW_REFER5_BASE - H.264: Base address for reference picture index 5 VP8: Base address for
 *    alternate reference picture (corresponds picid 5)
 */
#define VPU_G1_H264_SWREG19_SW_REFER5_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG19_SW_REFER5_BASE_SHIFT)) & VPU_G1_H264_SWREG19_SW_REFER5_BASE_MASK)
/*! @} */

/*! @name SWREG20 - Base address for reference picture index 6 / / MPEG4 TRB/TRD delta -1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_H264_SWREG20_SW_REFER6_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG20_SW_REFER6_TOPC_E_SHIFT (0U)
/*! SW_REFER6_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG20_SW_REFER6_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG20_SW_REFER6_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG20_SW_REFER6_TOPC_E_MASK)

#define VPU_G1_H264_SWREG20_SW_REFER6_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG20_SW_REFER6_FIELD_E_SHIFT (1U)
/*! SW_REFER6_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG20_SW_REFER6_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG20_SW_REFER6_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG20_SW_REFER6_FIELD_E_MASK)

#define VPU_G1_H264_SWREG20_SW_REFER6_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG20_SW_REFER6_BASE_SHIFT (2U)
/*! SW_REFER6_BASE - Base address for reference picture index 6. For VP8 video this base address is
 *    used as decoder output chrominance base address (if vp8 stride configuration is enabled)
 */
#define VPU_G1_H264_SWREG20_SW_REFER6_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG20_SW_REFER6_BASE_SHIFT)) & VPU_G1_H264_SWREG20_SW_REFER6_BASE_MASK)
/*! @} */

/*! @name SWREG21 - Base address for reference picture index 7 / MPEG4 TRB/TRD delta 1 / List of VLC code lengths in second JPEG AC table / VP6/VP7 scan maps */
/*! @{ */

#define VPU_G1_H264_SWREG21_SW_REFER7_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG21_SW_REFER7_TOPC_E_SHIFT (0U)
/*! SW_REFER7_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG21_SW_REFER7_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG21_SW_REFER7_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG21_SW_REFER7_TOPC_E_MASK)

#define VPU_G1_H264_SWREG21_SW_REFER7_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG21_SW_REFER7_FIELD_E_SHIFT (1U)
/*! SW_REFER7_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG21_SW_REFER7_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG21_SW_REFER7_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG21_SW_REFER7_FIELD_E_MASK)

#define VPU_G1_H264_SWREG21_SW_REFER7_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG21_SW_REFER7_BASE_SHIFT (2U)
/*! SW_REFER7_BASE - Base address for reference picture index 7 */
#define VPU_G1_H264_SWREG21_SW_REFER7_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG21_SW_REFER7_BASE_SHIFT)) & VPU_G1_H264_SWREG21_SW_REFER7_BASE_MASK)
/*! @} */

/*! @name SWREG22 - Base address for reference picture index 8 / List of VLC code lengths in second JPEG AC table / VP6 scan maps / VP7,VP8 DCT stream 1 base */
/*! @{ */

#define VPU_G1_H264_SWREG22_SW_REFER8_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG22_SW_REFER8_TOPC_E_SHIFT (0U)
/*! SW_REFER8_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG22_SW_REFER8_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG22_SW_REFER8_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG22_SW_REFER8_TOPC_E_MASK)

#define VPU_G1_H264_SWREG22_SW_REFER8_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG22_SW_REFER8_FIELD_E_SHIFT (1U)
/*! SW_REFER8_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG22_SW_REFER8_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG22_SW_REFER8_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG22_SW_REFER8_FIELD_E_MASK)

#define VPU_G1_H264_SWREG22_SW_REFER8_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG22_SW_REFER8_BASE_SHIFT (2U)
/*! SW_REFER8_BASE - Base address for reference picture index 8 */
#define VPU_G1_H264_SWREG22_SW_REFER8_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG22_SW_REFER8_BASE_SHIFT)) & VPU_G1_H264_SWREG22_SW_REFER8_BASE_MASK)
/*! @} */

/*! @name SWREG23 - Base address for reference picture index 9 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 2 base */
/*! @{ */

#define VPU_G1_H264_SWREG23_SW_REFER9_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG23_SW_REFER9_TOPC_E_SHIFT (0U)
/*! SW_REFER9_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG23_SW_REFER9_TOPC_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG23_SW_REFER9_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG23_SW_REFER9_TOPC_E_MASK)

#define VPU_G1_H264_SWREG23_SW_REFER9_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG23_SW_REFER9_FIELD_E_SHIFT (1U)
/*! SW_REFER9_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG23_SW_REFER9_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG23_SW_REFER9_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG23_SW_REFER9_FIELD_E_MASK)

#define VPU_G1_H264_SWREG23_SW_REFER9_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG23_SW_REFER9_BASE_SHIFT (2U)
/*! SW_REFER9_BASE - Base address for reference picture index 9 */
#define VPU_G1_H264_SWREG23_SW_REFER9_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG23_SW_REFER9_BASE_SHIFT)) & VPU_G1_H264_SWREG23_SW_REFER9_BASE_MASK)
/*! @} */

/*! @name SWREG24 - Base address for reference picture index 10 / List of VLC code lengths in first JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 3 base */
/*! @{ */

#define VPU_G1_H264_SWREG24_SW_REFER10_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG24_SW_REFER10_TOPC_E_SHIFT (0U)
/*! SW_REFER10_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG24_SW_REFER10_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG24_SW_REFER10_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG24_SW_REFER10_TOPC_E_MASK)

#define VPU_G1_H264_SWREG24_SW_REFER10_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG24_SW_REFER10_FIELD_E_SHIFT (1U)
/*! SW_REFER10_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG24_SW_REFER10_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG24_SW_REFER10_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG24_SW_REFER10_FIELD_E_MASK)

#define VPU_G1_H264_SWREG24_SW_REFER10_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG24_SW_REFER10_BASE_SHIFT (2U)
/*! SW_REFER10_BASE - Base address for reference picture index 10 */
#define VPU_G1_H264_SWREG24_SW_REFER10_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG24_SW_REFER10_BASE_SHIFT)) & VPU_G1_H264_SWREG24_SW_REFER10_BASE_MASK)
/*! @} */

/*! @name SWREG25 - Base address for reference picture index 11 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 4 base */
/*! @{ */

#define VPU_G1_H264_SWREG25_SW_REFER11_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG25_SW_REFER11_TOPC_E_SHIFT (0U)
/*! SW_REFER11_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG25_SW_REFER11_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG25_SW_REFER11_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG25_SW_REFER11_TOPC_E_MASK)

#define VPU_G1_H264_SWREG25_SW_REFER11_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG25_SW_REFER11_FIELD_E_SHIFT (1U)
/*! SW_REFER11_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG25_SW_REFER11_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG25_SW_REFER11_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG25_SW_REFER11_FIELD_E_MASK)

#define VPU_G1_H264_SWREG25_SW_REFER11_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG25_SW_REFER11_BASE_SHIFT (2U)
/*! SW_REFER11_BASE - Base address for reference picture index 11 */
#define VPU_G1_H264_SWREG25_SW_REFER11_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG25_SW_REFER11_BASE_SHIFT)) & VPU_G1_H264_SWREG25_SW_REFER11_BASE_MASK)
/*! @} */

/*! @name SWREG26 - Base address for reference picture index 12 / List of VLC code lengths in second JPEG DC table / VP6 scan maps / VP7,VP8 DCT stream 5 base */
/*! @{ */

#define VPU_G1_H264_SWREG26_SW_REFER12_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG26_SW_REFER12_TOPC_E_SHIFT (0U)
/*! SW_REFER12_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG26_SW_REFER12_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG26_SW_REFER12_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG26_SW_REFER12_TOPC_E_MASK)

#define VPU_G1_H264_SWREG26_SW_REFER12_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG26_SW_REFER12_FIELD_E_SHIFT (1U)
/*! SW_REFER12_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG26_SW_REFER12_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG26_SW_REFER12_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG26_SW_REFER12_FIELD_E_MASK)

#define VPU_G1_H264_SWREG26_SW_REFER12_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG26_SW_REFER12_BASE_SHIFT (2U)
/*! SW_REFER12_BASE - Base address for reference picture index 12 */
#define VPU_G1_H264_SWREG26_SW_REFER12_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG26_SW_REFER12_BASE_SHIFT)) & VPU_G1_H264_SWREG26_SW_REFER12_BASE_MASK)
/*! @} */

/*! @name SWREG27 - Base address for reference picture index 13 / VC-1 bitpl mbctrl or VP6,VP7,VP8 ctrl stream base /Progressive JPEG DC table */
/*! @{ */

#define VPU_G1_H264_SWREG27_SW_REFER13_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG27_SW_REFER13_TOPC_E_SHIFT (0U)
/*! SW_REFER13_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG27_SW_REFER13_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG27_SW_REFER13_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG27_SW_REFER13_TOPC_E_MASK)

#define VPU_G1_H264_SWREG27_SW_REFER13_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG27_SW_REFER13_FIELD_E_SHIFT (1U)
/*! SW_REFER13_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG27_SW_REFER13_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG27_SW_REFER13_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG27_SW_REFER13_FIELD_E_MASK)

#define VPU_G1_H264_SWREG27_SW_REFER13_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG27_SW_REFER13_BASE_SHIFT (2U)
/*! SW_REFER13_BASE - Base address for reference picture index 13 */
#define VPU_G1_H264_SWREG27_SW_REFER13_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG27_SW_REFER13_BASE_SHIFT)) & VPU_G1_H264_SWREG27_SW_REFER13_BASE_MASK)
/*! @} */

/*! @name SWREG28 - Base address for reference picture index 14 / VP6 scan maps /Progressive JPEG DC table / VP7,VP8 DCT stream 6 base */
/*! @{ */

#define VPU_G1_H264_SWREG28_SW_REFER14_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG28_SW_REFER14_TOPC_E_SHIFT (0U)
/*! SW_REFER14_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG28_SW_REFER14_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG28_SW_REFER14_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG28_SW_REFER14_TOPC_E_MASK)

#define VPU_G1_H264_SWREG28_SW_REFER14_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG28_SW_REFER14_FIELD_E_SHIFT (1U)
/*! SW_REFER14_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG28_SW_REFER14_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG28_SW_REFER14_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG28_SW_REFER14_FIELD_E_MASK)

#define VPU_G1_H264_SWREG28_SW_REFER14_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG28_SW_REFER14_BASE_SHIFT (2U)
/*! SW_REFER14_BASE - Base address for reference picture index 14 */
#define VPU_G1_H264_SWREG28_SW_REFER14_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG28_SW_REFER14_BASE_SHIFT)) & VPU_G1_H264_SWREG28_SW_REFER14_BASE_MASK)
/*! @} */

/*! @name SWREG29 - Base address for reference picture index 15 / VP6 scan maps / VP7,VP8 DCT stream 7 base */
/*! @{ */

#define VPU_G1_H264_SWREG29_SW_REFER15_TOPC_E_MASK (0x1U)
#define VPU_G1_H264_SWREG29_SW_REFER15_TOPC_E_SHIFT (0U)
/*! SW_REFER15_TOPC_E - Which field of reference picture is closer to current picture:
 *  0b0..bottom field is closer to current picture
 *  0b1..top field is closer to current picture
 */
#define VPU_G1_H264_SWREG29_SW_REFER15_TOPC_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG29_SW_REFER15_TOPC_E_SHIFT)) & VPU_G1_H264_SWREG29_SW_REFER15_TOPC_E_MASK)

#define VPU_G1_H264_SWREG29_SW_REFER15_FIELD_E_MASK (0x2U)
#define VPU_G1_H264_SWREG29_SW_REFER15_FIELD_E_SHIFT (1U)
/*! SW_REFER15_FIELD_E - Refer picture consist of single fields or frame:
 *  0b0..reference picture consists of frame
 *  0b1..reference picture consists of fields
 */
#define VPU_G1_H264_SWREG29_SW_REFER15_FIELD_E(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG29_SW_REFER15_FIELD_E_SHIFT)) & VPU_G1_H264_SWREG29_SW_REFER15_FIELD_E_MASK)

#define VPU_G1_H264_SWREG29_SW_REFER15_BASE_MASK (0xFFFFFFFCU)
#define VPU_G1_H264_SWREG29_SW_REFER15_BASE_SHIFT (2U)
/*! SW_REFER15_BASE - Base address for reference picture index 15. For Multi View Coding this base address refers to inter view base address */
#define VPU_G1_H264_SWREG29_SW_REFER15_BASE(x)   (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG29_SW_REFER15_BASE_SHIFT)) & VPU_G1_H264_SWREG29_SW_REFER15_BASE_MASK)
/*! @} */

/*! @name SWREG30 - Reference picture numbers for index 0 and 1 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter mb level adjusts */
/*! @{ */

#define VPU_G1_H264_SWREG30_SW_REFER0_NBR_MASK   (0xFFFFU)
#define VPU_G1_H264_SWREG30_SW_REFER0_NBR_SHIFT  (0U)
/*! SW_REFER0_NBR - Number for reference picture index 0 */
#define VPU_G1_H264_SWREG30_SW_REFER0_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG30_SW_REFER0_NBR_SHIFT)) & VPU_G1_H264_SWREG30_SW_REFER0_NBR_MASK)

#define VPU_G1_H264_SWREG30_SW_REFER1_NBR_MASK   (0xFFFF0000U)
#define VPU_G1_H264_SWREG30_SW_REFER1_NBR_SHIFT  (16U)
/*! SW_REFER1_NBR - Number for reference picture index 1 */
#define VPU_G1_H264_SWREG30_SW_REFER1_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG30_SW_REFER1_NBR_SHIFT)) & VPU_G1_H264_SWREG30_SW_REFER1_NBR_MASK)
/*! @} */

/*! @name SWREG31 - Reference picture numbers for index 2 and 3 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter ref pic level adjusts */
/*! @{ */

#define VPU_G1_H264_SWREG31_SW_REFER2_NBR_MASK   (0xFFFFU)
#define VPU_G1_H264_SWREG31_SW_REFER2_NBR_SHIFT  (0U)
/*! SW_REFER2_NBR - Number for reference picture index 2 */
#define VPU_G1_H264_SWREG31_SW_REFER2_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG31_SW_REFER2_NBR_SHIFT)) & VPU_G1_H264_SWREG31_SW_REFER2_NBR_MASK)

#define VPU_G1_H264_SWREG31_SW_REFER3_NBR_MASK   (0xFFFF0000U)
#define VPU_G1_H264_SWREG31_SW_REFER3_NBR_SHIFT  (16U)
/*! SW_REFER3_NBR - Number for reference picture index 3 */
#define VPU_G1_H264_SWREG31_SW_REFER3_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG31_SW_REFER3_NBR_SHIFT)) & VPU_G1_H264_SWREG31_SW_REFER3_NBR_MASK)
/*! @} */

/*! @name SWREG32 - Reference picture numbers for index 4 and 5 (H264 VLC) / VP6 scan maps / VP7,VP8 loop filter levels */
/*! @{ */

#define VPU_G1_H264_SWREG32_SW_REFER4_NBR_MASK   (0xFFFFU)
#define VPU_G1_H264_SWREG32_SW_REFER4_NBR_SHIFT  (0U)
/*! SW_REFER4_NBR - Number for reference picture index 4 */
#define VPU_G1_H264_SWREG32_SW_REFER4_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG32_SW_REFER4_NBR_SHIFT)) & VPU_G1_H264_SWREG32_SW_REFER4_NBR_MASK)

#define VPU_G1_H264_SWREG32_SW_REFER5_NBR_MASK   (0xFFFF0000U)
#define VPU_G1_H264_SWREG32_SW_REFER5_NBR_SHIFT  (16U)
/*! SW_REFER5_NBR - Number for reference picture index 5 */
#define VPU_G1_H264_SWREG32_SW_REFER5_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG32_SW_REFER5_NBR_SHIFT)) & VPU_G1_H264_SWREG32_SW_REFER5_NBR_MASK)
/*! @} */

/*! @name SWREG33 - Reference picture numbers for index 6 and 7 (H264 VLC) / VP6 scan maps / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_H264_SWREG33_SW_REFER6_NBR_MASK   (0xFFFFU)
#define VPU_G1_H264_SWREG33_SW_REFER6_NBR_SHIFT  (0U)
/*! SW_REFER6_NBR - Number for reference picture index 6 */
#define VPU_G1_H264_SWREG33_SW_REFER6_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG33_SW_REFER6_NBR_SHIFT)) & VPU_G1_H264_SWREG33_SW_REFER6_NBR_MASK)

#define VPU_G1_H264_SWREG33_SW_REFER7_NBR_MASK   (0xFFFF0000U)
#define VPU_G1_H264_SWREG33_SW_REFER7_NBR_SHIFT  (16U)
/*! SW_REFER7_NBR - Number for reference picture index 7 */
#define VPU_G1_H264_SWREG33_SW_REFER7_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG33_SW_REFER7_NBR_SHIFT)) & VPU_G1_H264_SWREG33_SW_REFER7_NBR_MASK)
/*! @} */

/*! @name SWREG34 - Reference picture numbers for index 8 and 9 (H264 VLC) / MPEG4, VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG34_SW_REFER8_NBR_MASK   (0xFFFFU)
#define VPU_G1_H264_SWREG34_SW_REFER8_NBR_SHIFT  (0U)
/*! SW_REFER8_NBR - Number for reference picture index 8 */
#define VPU_G1_H264_SWREG34_SW_REFER8_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG34_SW_REFER8_NBR_SHIFT)) & VPU_G1_H264_SWREG34_SW_REFER8_NBR_MASK)

#define VPU_G1_H264_SWREG34_SW_REFER9_NBR_MASK   (0xFFFF0000U)
#define VPU_G1_H264_SWREG34_SW_REFER9_NBR_SHIFT  (16U)
/*! SW_REFER9_NBR - Number for reference picture index 9 */
#define VPU_G1_H264_SWREG34_SW_REFER9_NBR(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG34_SW_REFER9_NBR_SHIFT)) & VPU_G1_H264_SWREG34_SW_REFER9_NBR_MASK)
/*! @} */

/*! @name SWREG35 - Reference picture numbers for index 10 and 11 (H264 VLC) / VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG35_SW_REFER10_NBR_MASK  (0xFFFFU)
#define VPU_G1_H264_SWREG35_SW_REFER10_NBR_SHIFT (0U)
/*! SW_REFER10_NBR - Number for reference picture index 10 */
#define VPU_G1_H264_SWREG35_SW_REFER10_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG35_SW_REFER10_NBR_SHIFT)) & VPU_G1_H264_SWREG35_SW_REFER10_NBR_MASK)

#define VPU_G1_H264_SWREG35_SW_REFER11_NBR_MASK  (0xFFFF0000U)
#define VPU_G1_H264_SWREG35_SW_REFER11_NBR_SHIFT (16U)
/*! SW_REFER11_NBR - Number for reference picture index 11 */
#define VPU_G1_H264_SWREG35_SW_REFER11_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG35_SW_REFER11_NBR_SHIFT)) & VPU_G1_H264_SWREG35_SW_REFER11_NBR_MASK)
/*! @} */

/*! @name SWREG36 - Reference picture numbers for index 12 and 13 (H264 VLC) / VC1, VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG36_SW_REFER12_NBR_MASK  (0xFFFFU)
#define VPU_G1_H264_SWREG36_SW_REFER12_NBR_SHIFT (0U)
/*! SW_REFER12_NBR - Number for reference picture index 12 */
#define VPU_G1_H264_SWREG36_SW_REFER12_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG36_SW_REFER12_NBR_SHIFT)) & VPU_G1_H264_SWREG36_SW_REFER12_NBR_MASK)

#define VPU_G1_H264_SWREG36_SW_REFER13_NBR_MASK  (0xFFFF0000U)
#define VPU_G1_H264_SWREG36_SW_REFER13_NBR_SHIFT (16U)
/*! SW_REFER13_NBR - Number for reference picture index 13 */
#define VPU_G1_H264_SWREG36_SW_REFER13_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG36_SW_REFER13_NBR_SHIFT)) & VPU_G1_H264_SWREG36_SW_REFER13_NBR_MASK)
/*! @} */

/*! @name SWREG37 - Reference picture numbers for index 14 and 15 (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG37_SW_REFER14_NBR_MASK  (0xFFFFU)
#define VPU_G1_H264_SWREG37_SW_REFER14_NBR_SHIFT (0U)
/*! SW_REFER14_NBR - Number for reference picture index 14 */
#define VPU_G1_H264_SWREG37_SW_REFER14_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG37_SW_REFER14_NBR_SHIFT)) & VPU_G1_H264_SWREG37_SW_REFER14_NBR_MASK)

#define VPU_G1_H264_SWREG37_SW_REFER15_NBR_MASK  (0xFFFF0000U)
#define VPU_G1_H264_SWREG37_SW_REFER15_NBR_SHIFT (16U)
/*! SW_REFER15_NBR - Number for reference picture index 15 */
#define VPU_G1_H264_SWREG37_SW_REFER15_NBR(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG37_SW_REFER15_NBR_SHIFT)) & VPU_G1_H264_SWREG37_SW_REFER15_NBR_MASK)
/*! @} */

/*! @name SWREG38 - Reference picture long term flags (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG38_SW_REFER_LTERM_E_MASK (0xFFFFFFFFU)
#define VPU_G1_H264_SWREG38_SW_REFER_LTERM_E_SHIFT (0U)
/*! SW_REFER_LTERM_E - Long term flag for reference picture index [31:0]. Definition: If frame is
 *    being decoded the bits 31:15 are used, Bit 31 for picture index 0, Bit 30 for picture index 1
 *    etc... IF field is being decoded the bits 31:0 are used, Bit 31 for reference picture 0 top
 *    field, bit 30 for reference picture 0 bottom field etc...
 */
#define VPU_G1_H264_SWREG38_SW_REFER_LTERM_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG38_SW_REFER_LTERM_E_SHIFT)) & VPU_G1_H264_SWREG38_SW_REFER_LTERM_E_MASK)
/*! @} */

/*! @name SWREG39 - Reference picture valid flags (H264 VLC) / VPx prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG39_SW_REFER_VALID_E_MASK (0xFFFFFFFFU)
#define VPU_G1_H264_SWREG39_SW_REFER_VALID_E_SHIFT (0U)
/*! SW_REFER_VALID_E - Valid flag for reference picture index [31:0].Definition: If frame is being
 *    decoded the bits 31:15 are used, Bit 31 for picture index 0, Bit 30 for picture index 1 etc...
 *    IF field is being decoded the bits 31:0 are used, Bit 31 for reference picture 0 top field,
 *    bit 30 for reference picture 0 bottom field etc...
 */
#define VPU_G1_H264_SWREG39_SW_REFER_VALID_E(x)  (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG39_SW_REFER_VALID_E_SHIFT)) & VPU_G1_H264_SWREG39_SW_REFER_VALID_E_MASK)
/*! @} */

/*! @name SWREG42_H264 - bi_dir initial ref pic list register (0-2) / VP6 prediction filter taps / Progressive JPEG Cb ACDC coefficient base */
/*! @{ */

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F0_H264_MASK (0x1FU)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F0_H264_SHIFT (0U)
/*! SW_BINIT_RLIST_F0_H264 - Initial reference picture list for bi-direct forward picid 0 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F0_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F0_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F0_H264_MASK)

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B0_H264_MASK (0x3E0U)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B0_H264_SHIFT (5U)
/*! SW_BINIT_RLIST_B0_H264 - Initial reference picture list for bi-direct backward picid 0 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B0_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B0_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B0_H264_MASK)

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F1_H264_MASK (0x7C00U)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F1_H264_SHIFT (10U)
/*! SW_BINIT_RLIST_F1_H264 - Initial reference picture list for bi-direct forward picid 1 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F1_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F1_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F1_H264_MASK)

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B1_H264_MASK (0xF8000U)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B1_H264_SHIFT (15U)
/*! SW_BINIT_RLIST_B1_H264 - Initial reference picture list for bi-direct backward picid 1 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B1_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B1_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B1_H264_MASK)

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F2_H264_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F2_H264_SHIFT (20U)
/*! SW_BINIT_RLIST_F2_H264 - Initial reference picture list for bi-direct forward picid 2 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F2_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F2_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_F2_H264_MASK)

#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B2_H264_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B2_H264_SHIFT (25U)
/*! SW_BINIT_RLIST_B2_H264 - Initial reference picture list for bi-direct backward picid 2 */
#define VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B2_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B2_H264_SHIFT)) & VPU_G1_H264_SWREG42_H264_SW_BINIT_RLIST_B2_H264_MASK)
/*! @} */

/*! @name SWREG43_H264 - bi-dir initial ref pic list register (3-5) / VP6 prediction filter taps / Progressive JPEG Cr ACDC coefficient base */
/*! @{ */

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F3_H264_MASK (0x1FU)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F3_H264_SHIFT (0U)
/*! SW_BINIT_RLIST_F3_H264 - Initial reference picture list for bi-direct forward picid 3 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F3_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F3_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F3_H264_MASK)

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B3_H264_MASK (0x3E0U)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B3_H264_SHIFT (5U)
/*! SW_BINIT_RLIST_B3_H264 - Initial reference picture list for bi-direct backward picid 3 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B3_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B3_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B3_H264_MASK)

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F4_H264_MASK (0x7C00U)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F4_H264_SHIFT (10U)
/*! SW_BINIT_RLIST_F4_H264 - Initial reference picture list for bi-direct forward picid 4 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F4_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F4_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F4_H264_MASK)

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B4_H264_MASK (0xF8000U)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B4_H264_SHIFT (15U)
/*! SW_BINIT_RLIST_B4_H264 - Initial reference picture list for bi-direct backward picid 4 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B4_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B4_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B4_H264_MASK)

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F5_H264_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F5_H264_SHIFT (20U)
/*! SW_BINIT_RLIST_F5_H264 - Initial reference picture list for bi-direct forward picid 5 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F5_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F5_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_F5_H264_MASK)

#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B5_H264_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B5_H264_SHIFT (25U)
/*! SW_BINIT_RLIST_B5_H264 - Initial reference picture list for bi-direct backward picid 5 */
#define VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B5_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B5_H264_SHIFT)) & VPU_G1_H264_SWREG43_H264_SW_BINIT_RLIST_B5_H264_MASK)
/*! @} */

/*! @name SWREG44_H264 - bi-dir initial ref pic list register (6-8) / VP6 prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F6_H264_MASK (0x1FU)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F6_H264_SHIFT (0U)
/*! SW_BINIT_RLIST_F6_H264 - Initial reference picture list for bi-direct forward picid 6 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F6_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F6_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F6_H264_MASK)

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B6_H264_MASK (0x3E0U)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B6_H264_SHIFT (5U)
/*! SW_BINIT_RLIST_B6_H264 - Initial reference picture list for bi-direct backward picid 6 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B6_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B6_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B6_H264_MASK)

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F7_H264_MASK (0x7C00U)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F7_H264_SHIFT (10U)
/*! SW_BINIT_RLIST_F7_H264 - Initial reference picture list for bi-direct forward picid 7 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F7_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F7_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F7_H264_MASK)

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B7_H264_MASK (0xF8000U)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B7_H264_SHIFT (15U)
/*! SW_BINIT_RLIST_B7_H264 - Initial reference picture list for bi-direct backward picid 7 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B7_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B7_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B7_H264_MASK)

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F8_H264_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F8_H264_SHIFT (20U)
/*! SW_BINIT_RLIST_F8_H264 - Initial reference picture list for bi-direct forward picid 8 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F8_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F8_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_F8_H264_MASK)

#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B8_H264_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B8_H264_SHIFT (25U)
/*! SW_BINIT_RLIST_B8_H264 - Initial reference picture list for bi-direct backward picid 8 */
#define VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B8_H264(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B8_H264_SHIFT)) & VPU_G1_H264_SWREG44_H264_SW_BINIT_RLIST_B8_H264_MASK)
/*! @} */

/*! @name SWREG45 - bi-dir initial ref pic list register (9-11) / VP6 prediction filter taps */
/*! @{ */

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F9_MASK (0x1FU)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F9_SHIFT (0U)
/*! SW_BINIT_RLIST_F9 - Initial reference picture list for bi-direct forward picid 9 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F9(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F9_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F9_MASK)

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B9_MASK (0x3E0U)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B9_SHIFT (5U)
/*! SW_BINIT_RLIST_B9 - Initial reference picture list for bi-direct backward picid 9 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B9(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B9_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B9_MASK)

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F10_MASK (0x7C00U)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F10_SHIFT (10U)
/*! SW_BINIT_RLIST_F10 - Initial reference picture list for bi-direct forward picid 10 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F10(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F10_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F10_MASK)

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B10_MASK (0xF8000U)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B10_SHIFT (15U)
/*! SW_BINIT_RLIST_B10 - Initial reference picture list for bi-direct backward picid 10 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B10(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B10_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B10_MASK)

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F11_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F11_SHIFT (20U)
/*! SW_BINIT_RLIST_F11 - Initial reference picture list for bi-direct forward picid 11 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F11(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F11_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_F11_MASK)

#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B11_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B11_SHIFT (25U)
/*! SW_BINIT_RLIST_B11 - Initial reference picture list for bi-direct backward picid 11 */
#define VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B11(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B11_SHIFT)) & VPU_G1_H264_SWREG45_SW_BINIT_RLIST_B11_MASK)
/*! @} */

/*! @name SWREG46 - bi-dir initial ref pic list register (12-14) / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F12_MASK (0x1FU)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F12_SHIFT (0U)
/*! SW_BINIT_RLIST_F12 - Initial reference picture list for bi-direct forward picid 12 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F12(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F12_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F12_MASK)

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B12_MASK (0x3E0U)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B12_SHIFT (5U)
/*! SW_BINIT_RLIST_B12 - Initial reference picture list for bi-direct backward picid 12 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B12(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B12_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B12_MASK)

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F13_MASK (0x7C00U)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F13_SHIFT (10U)
/*! SW_BINIT_RLIST_F13 - Initial reference picture list for bi-direct forward picid 13 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F13(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F13_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F13_MASK)

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B13_MASK (0xF8000U)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B13_SHIFT (15U)
/*! SW_BINIT_RLIST_B13 - Initial reference picture list for bi-direct backward picid 13 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B13(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B13_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B13_MASK)

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F14_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F14_SHIFT (20U)
/*! SW_BINIT_RLIST_F14 - Initial reference picture list for bi-direct forward picid 14 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F14(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F14_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_F14_MASK)

#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B14_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B14_SHIFT (25U)
/*! SW_BINIT_RLIST_B14 - Initial reference picture list for bi-direct backward picid 14 */
#define VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B14(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B14_SHIFT)) & VPU_G1_H264_SWREG46_SW_BINIT_RLIST_B14_MASK)
/*! @} */

/*! @name SWREG47 - bi-dir and P fwd initial ref pic list register (15 and P 0-3) / VP7,VP8 quantization values */
/*! @{ */

#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_F15_MASK (0x1FU)
#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_F15_SHIFT (0U)
/*! SW_BINIT_RLIST_F15 - Initial reference picture list for bi-direct forward picid 15 */
#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_F15(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_BINIT_RLIST_F15_SHIFT)) & VPU_G1_H264_SWREG47_SW_BINIT_RLIST_F15_MASK)

#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_B15_MASK (0x3E0U)
#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_B15_SHIFT (5U)
/*! SW_BINIT_RLIST_B15 - Initial reference picture list for bi-direct backward picid 15 */
#define VPU_G1_H264_SWREG47_SW_BINIT_RLIST_B15(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_BINIT_RLIST_B15_SHIFT)) & VPU_G1_H264_SWREG47_SW_BINIT_RLIST_B15_MASK)

#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F0_MASK (0x7C00U)
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F0_SHIFT (10U)
/*! SW_PINIT_RLIST_F0 - Initial reference picture list for P forward picid 0 */
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F0(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F0_SHIFT)) & VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F0_MASK)

#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F1_MASK (0xF8000U)
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F1_SHIFT (15U)
/*! SW_PINIT_RLIST_F1 - Initial reference picture list for P forward picid 1 */
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F1(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F1_SHIFT)) & VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F1_MASK)

#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F2_MASK (0x1F00000U)
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F2_SHIFT (20U)
/*! SW_PINIT_RLIST_F2 - Initial reference picture list for P forward picid 2 */
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F2(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F2_SHIFT)) & VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F2_MASK)

#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F3_MASK (0x3E000000U)
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F3_SHIFT (25U)
/*! SW_PINIT_RLIST_F3 - Initial reference picture list for P forward picid 3 */
#define VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F3(x) (((uint32_t)(((uint32_t)(x)) << VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F3_SHIFT)) & VPU_G1_H264_SWREG47_SW_PINIT_RLIST_F3_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_G1_H264_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_G1_H264_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_G1_H264_H_ */

