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
**         CMSIS Peripheral Access Layer for VPU_G1
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
 * @file PERI_VPU_G1.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VPU_G1
 *
 * CMSIS Peripheral Access Layer for VPU_G1
 */

#if !defined(PERI_VPU_G1_H_)
#define PERI_VPU_G1_H_                           /**< Symbol preventing repeated inclusion */

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
   -- VPU_G1 Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_Peripheral_Access_Layer VPU_G1 Peripheral Access Layer
 * @{
 */

/** VPU_G1 - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4];
  __IO uint32_t SWREG1;                            /**< Interrupt register decoder, offset: 0x4 */
  __IO uint32_t SWREG2;                            /**< Device configuration register decoder, offset: 0x8 */
  __IO uint32_t SWREG3;                            /**< Decoder control register 0 (decmode,picture type etc), offset: 0xC */
       uint8_t RESERVED_1[32];
  __IO uint32_t SWREG12;                           /**< Base address for RLC data (RLC) / stream start address/decoded end addr register (VLC), offset: 0x30 */
  __IO uint32_t SWREG13;                           /**< Base address for decoded picture, offset: 0x34 */
       uint8_t RESERVED_2[104];
  __IO uint32_t SWREG40;                           /**< Base address for standard dependent tables, offset: 0xA0 */
  __IO uint32_t SWREG41;                           /**< Base address for direct mode motion vectors, offset: 0xA4 */
       uint8_t RESERVED_3[24];
  __IO uint32_t SWREG48;                           /**< Error concealment register, offset: 0xC0 */
  __IO uint32_t SWREG49;                           /**< Prediction filter tap register for H264, offset: 0xC4 */
  __I  uint32_t SWREG50;                           /**< Synthesis configuration register decoder 0, offset: 0xC8 */
  __IO uint32_t SWREG51;                           /**< Reference picture buffer control register, offset: 0xCC */
  __I  uint32_t SWREG52;                           /**< Reference picture buffer information register 1, offset: 0xD0 */
  __I  uint32_t SWREG53;                           /**< Reference picture buffer information register 2, offset: 0xD4 */
  __I  uint32_t SWREG54;                           /**< Synthesis configuration register decoder 1, offset: 0xD8 */
  __IO uint32_t SWREG55;                           /**< Reference picture buffer 2 / Advanced prefetch control register, offset: 0xDC */
  __I  uint32_t SWREG56;                           /**< Reference buffer information register 3, offset: 0xE0 */
  __I  uint32_t SWREG57;                           /**< Decoder fuse register, offset: 0xE4 */
  __IO uint32_t SWREG58;                           /**< Device configuration register decoder 2 + Multi core control register, offset: 0xE8 */
  __IO uint32_t SWREG59;                           /**< H264 Chrominance 8 pixel interleaved data base, offset: 0xEC */
  __IO uint32_t SWREG60;                           /**< Interrupt register post-processor, offset: 0xF0 */
  __IO uint32_t SWREG61;                           /**< Device configuration register post-processor, offset: 0xF4 */
  __IO uint32_t SWREG62;                           /**< Deinterlace control register, offset: 0xF8 */
  __IO uint32_t SWREG63;                           /**< Base address for reading post-processing input picture luminance (top field/frame), offset: 0xFC */
  __IO uint32_t SWREG64;                           /**< Base address for reading post-processing input picture Cb/Ch (top field/frame), offset: 0x100 */
  __IO uint32_t SWREG65;                           /**< Base address for reading post-processing input picture Cr, offset: 0x104 */
  __IO uint32_t SWREG66;                           /**< Base address for writing post-processed picture luminance/RGB, offset: 0x108 */
  __IO uint32_t SWREG67;                           /**< Base address for writing post-processed picture Ch, offset: 0x10C */
  __IO uint32_t SWREG68;                           /**< Register for contrast adjusting, offset: 0x110 */
  __IO uint32_t SWREG69;                           /**< Register for colour conversion and contrast adjusting/YUYV 422 channel orders, offset: 0x114 */
  __IO uint32_t SWREG70;                           /**< Register for colour conversion 0, offset: 0x118 */
  __IO uint32_t SWREG71;                           /**< Register for colour conversion 1 + rotation mode, offset: 0x11C */
  __IO uint32_t SWREG72;                           /**< PP input size and -cropping register, offset: 0x120 */
  __IO uint32_t SWREG73;                           /**< PP input picture base address for Y bottom field, offset: 0x124 */
  __IO uint32_t SWREG74;                           /**< PP input picture base for Ch bottom field, offset: 0x128 */
       uint8_t RESERVED_4[16];
  __IO uint32_t SWREG79;                           /**< Scaling register 0 ratio and padding for R and G, offset: 0x13C */
  __IO uint32_t SWREG80;                           /**< Scaling ratio register 1 and padding for B, offset: 0x140 */
  __IO uint32_t SWREG81;                           /**< Scaling ratio register 2, offset: 0x144 */
  __IO uint32_t SWREG82;                           /**< Rmask register, offset: 0x148 */
  __IO uint32_t SWREG83;                           /**< Gmask register, offset: 0x14C */
  __IO uint32_t SWREG84;                           /**< Bmask register, offset: 0x150 */
  __IO uint32_t SWREG85;                           /**< Post-processor control register, offset: 0x154 */
  __IO uint32_t SWREG86;                           /**< Mask 1 start coordinate register, offset: 0x158 */
  __IO uint32_t SWREG87;                           /**< Mask 2 start coordinate register + Mask extensions, offset: 0x15C */
  __IO uint32_t SWREG88;                           /**< Mask 1 size and PP original width register, offset: 0x160 */
  __IO uint32_t SWREG89;                           /**< Mask 2 size register + mask extensions, offset: 0x164 */
  __IO uint32_t SWREG90;                           /**< PiP register 0, offset: 0x168 */
  __IO uint32_t SWREG91;                           /**< PiP register 1 and dithering control, offset: 0x16C */
  __IO uint32_t SWREG92;                           /**< Display width and PP input size extension register, offset: 0x170 */
  __IO uint32_t SWREG93;                           /**< Base address for alpha blend 1 gui component, offset: 0x174 */
  __IO uint32_t SWREG94;                           /**< Base address for alpha blend 2 gui component, offset: 0x178 */
  __IO uint32_t SWREG95;                           /**< Alpha blend input cropping register (scanline for cropping), offset: 0x17C */
       uint8_t RESERVED_5[12];
  __I  uint32_t SWREG99;                           /**< PP fuse register, offset: 0x18C */
  __I  uint32_t SWREG100;                          /**< Synthesis configuration register post-processor, offset: 0x190 */
       uint8_t RESERVED_6[4];
  __IO uint32_t SWREG102;                          /**< Base address for H264 decoded chroma picture, offset: 0x198 */
  __IO uint32_t SWREG103;                          /**< Base address for reference chroma picture index 0, offset: 0x19C */
  __IO uint32_t SWREG104;                          /**< Base address for reference chroma picture index 1, offset: 0x1A0 */
  __IO uint32_t SWREG105;                          /**< Base address for reference chroma picture index 2, offset: 0x1A4 */
  __IO uint32_t SWREG106;                          /**< Base address for reference chroma picture index 3, offset: 0x1A8 */
  __IO uint32_t SWREG107;                          /**< Base address for reference chroma picture index 4, offset: 0x1AC */
  __IO uint32_t SWREG108;                          /**< Base address for reference chroma picture index 5, offset: 0x1B0 */
  __IO uint32_t SWREG109;                          /**< Base address for reference chroma picture index 6, offset: 0x1B4 */
  __IO uint32_t SWREG110;                          /**< Base address for reference chroma picture index 7, offset: 0x1B8 */
  __IO uint32_t SWREG111;                          /**< Base address for reference chroma picture index 8, offset: 0x1BC */
  __IO uint32_t SWREG112;                          /**< Base address for reference chroma picture index 9, offset: 0x1C0 */
  __IO uint32_t SWREG113;                          /**< Base address for reference chroma picture index 10, offset: 0x1C4 */
  __IO uint32_t SWREG114;                          /**< Base address for reference chroma picture index 11, offset: 0x1C8 */
  __IO uint32_t SWREG115;                          /**< Base address for reference chroma picture index 12, offset: 0x1CC */
  __IO uint32_t SWREG116;                          /**< Base address for reference chroma picture index 13, offset: 0x1D0 */
  __IO uint32_t SWREG117;                          /**< Base address for reference chroma picture index 14, offset: 0x1D4 */
  __IO uint32_t SWREG118;                          /**< Base address for reference chroma picture index 15, offset: 0x1D8 */
} VPU_G1_Type;

/* ----------------------------------------------------------------------------
   -- VPU_G1 Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_G1_Register_Masks VPU_G1 Register Masks
 * @{
 */

/*! @name SWREG1 - Interrupt register decoder */
/*! @{ */

#define VPU_G1_SWREG1_SW_DEC_E_MASK              (0x1U)
#define VPU_G1_SWREG1_SW_DEC_E_SHIFT             (0U)
/*! SW_DEC_E - Decoder enable. Setting this bit high will start the decoding operation. HW will
 *    reset this when picture is processed or ASO or stream error is detected or bus error or timeout
 *    interrupt is given.
 */
#define VPU_G1_SWREG1_SW_DEC_E(x)                (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_E_SHIFT)) & VPU_G1_SWREG1_SW_DEC_E_MASK)

#define VPU_G1_SWREG1_SW_DEC_IRQ_DIS_MASK        (0x10U)
#define VPU_G1_SWREG1_SW_DEC_IRQ_DIS_SHIFT       (4U)
/*! SW_DEC_IRQ_DIS - Decoder IRQ disable. When high, there are no interrupts concerning decoder from
 *    HW. Polling must be used to see the interrupt statuses.
 */
#define VPU_G1_SWREG1_SW_DEC_IRQ_DIS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_IRQ_DIS_SHIFT)) & VPU_G1_SWREG1_SW_DEC_IRQ_DIS_MASK)

#define VPU_G1_SWREG1_SW_DEC_ABORT_E_MASK        (0x20U)
#define VPU_G1_SWREG1_SW_DEC_ABORT_E_SHIFT       (5U)
/*! SW_DEC_ABORT_E - Abort decoding enable. Setting this bit high will cause HW to abort decoding
 *    and safely to reset itself down. After abort is complete the corresponding interrupt status is
 *    set and this bit is set low as well as the decoder enable.
 */
#define VPU_G1_SWREG1_SW_DEC_ABORT_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_ABORT_E_SHIFT)) & VPU_G1_SWREG1_SW_DEC_ABORT_E_MASK)

#define VPU_G1_SWREG1_SW_DEC_IRQ_MASK            (0x100U)
#define VPU_G1_SWREG1_SW_DEC_IRQ_SHIFT           (8U)
/*! SW_DEC_IRQ - Decoder IRQ. When high, decoder requests an interrupt. SW will reset this after interrupt is handled. */
#define VPU_G1_SWREG1_SW_DEC_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_IRQ_SHIFT)) & VPU_G1_SWREG1_SW_DEC_IRQ_MASK)

#define VPU_G1_SWREG1_SW_DEC_RDY_INT_MASK        (0x1000U)
#define VPU_G1_SWREG1_SW_DEC_RDY_INT_SHIFT       (12U)
/*! SW_DEC_RDY_INT - Interrupt status bit decoder. When this bit is high decoder has decoded a picture. HW will self reset. */
#define VPU_G1_SWREG1_SW_DEC_RDY_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_RDY_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_RDY_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_BUS_INT_MASK        (0x2000U)
#define VPU_G1_SWREG1_SW_DEC_BUS_INT_SHIFT       (13U)
/*! SW_DEC_BUS_INT - Interrupt status bit bus. Error response from bus. */
#define VPU_G1_SWREG1_SW_DEC_BUS_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_BUS_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_BUS_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_BUFFER_INT_MASK     (0x4000U)
#define VPU_G1_SWREG1_SW_DEC_BUFFER_INT_SHIFT    (14U)
/*! SW_DEC_BUFFER_INT - Interrupt status bit input buffer empty. When high, input stream buffer is
 *    empty but picture is not ready. HW will not self reset.
 */
#define VPU_G1_SWREG1_SW_DEC_BUFFER_INT(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_BUFFER_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_BUFFER_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_ASO_INT_MASK        (0x8000U)
#define VPU_G1_SWREG1_SW_DEC_ASO_INT_SHIFT       (15U)
/*! SW_DEC_ASO_INT - H264: Interrupt status bit ASO (Arbitrary Slice Ordering) detected. When high,
 *    ASO detected in input data stream decoding. HW will self reset. VP8: Error detected in
 *    Residual data. HW returns MB number in error concealment register for MB it detected it
 */
#define VPU_G1_SWREG1_SW_DEC_ASO_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_ASO_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_ASO_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_ERROR_INT_MASK      (0x10000U)
#define VPU_G1_SWREG1_SW_DEC_ERROR_INT_SHIFT     (16U)
/*! SW_DEC_ERROR_INT - Interrupt status bit input stream error. When high, an error is found in input data stream decoding. HW will self reset. */
#define VPU_G1_SWREG1_SW_DEC_ERROR_INT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_ERROR_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_ERROR_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_SLICE_INT_MASK      (0x20000U)
#define VPU_G1_SWREG1_SW_DEC_SLICE_INT_SHIFT     (17U)
/*! SW_DEC_SLICE_INT - Interrupt status bit dec_slice_decoded. When high SW must set new base
 *    addresses for sw_dec_out_base and sw_jpg_ch_out_base before resetting this status bit. Used for VP8
 *    web-p modes
 */
#define VPU_G1_SWREG1_SW_DEC_SLICE_INT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_SLICE_INT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_SLICE_INT_MASK)

#define VPU_G1_SWREG1_SW_DEC_TIMEOUT_MASK        (0x40000U)
#define VPU_G1_SWREG1_SW_DEC_TIMEOUT_SHIFT       (18U)
/*! SW_DEC_TIMEOUT - Interrupt status bit decoder timeout. When high the decoder has been idling for
 *    too long. HW will self reset. Possible only if timeout interrupt is enabled
 */
#define VPU_G1_SWREG1_SW_DEC_TIMEOUT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_TIMEOUT_SHIFT)) & VPU_G1_SWREG1_SW_DEC_TIMEOUT_MASK)

#define VPU_G1_SWREG1_SW_DEC_PIC_INF_MASK        (0x1000000U)
#define VPU_G1_SWREG1_SW_DEC_PIC_INF_SHIFT       (24U)
/*! SW_DEC_PIC_INF - B slice detected. This signal is driven high during picture ready interrupt if
 *    B-type slice is found. This bit does not launch interrupt but is used to inform SW about h264
 *    tools.
 */
#define VPU_G1_SWREG1_SW_DEC_PIC_INF(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG1_SW_DEC_PIC_INF_SHIFT)) & VPU_G1_SWREG1_SW_DEC_PIC_INF_MASK)
/*! @} */

/*! @name SWREG2 - Device configuration register decoder */
/*! @{ */

#define VPU_G1_SWREG2_SW_DEC_MAX_BURST_MASK      (0x1FU)
#define VPU_G1_SWREG2_SW_DEC_MAX_BURST_SHIFT     (0U)
/*! SW_DEC_MAX_BURST - Maximum burst length for decoder bus transactions. */
#define VPU_G1_SWREG2_SW_DEC_MAX_BURST(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_MAX_BURST_SHIFT)) & VPU_G1_SWREG2_SW_DEC_MAX_BURST_MASK)

#define VPU_G1_SWREG2_SW_DEC_SCMD_DIS_MASK       (0x20U)
#define VPU_G1_SWREG2_SW_DEC_SCMD_DIS_SHIFT      (5U)
/*! SW_DEC_SCMD_DIS - 9170 decoder and later->: AXI Single Command Multiple Data disable. 9170 axi
 *    wrapper supports this mode by default (where only the first addresses of the burst are given
 *    from address generator). This bit is used to disable the feature (possible SW workaround if
 *    something is not working correctly)
 */
#define VPU_G1_SWREG2_SW_DEC_SCMD_DIS(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_SCMD_DIS_SHIFT)) & VPU_G1_SWREG2_SW_DEC_SCMD_DIS_MASK)

#define VPU_G1_SWREG2_SW_DEC_ADV_PRE_DIS_MASK    (0x40U)
#define VPU_G1_SWREG2_SW_DEC_ADV_PRE_DIS_SHIFT   (6U)
/*! SW_DEC_ADV_PRE_DIS - Advanced PREFETCH mode disable (advanced reference picture reading mode for video) */
#define VPU_G1_SWREG2_SW_DEC_ADV_PRE_DIS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_ADV_PRE_DIS_SHIFT)) & VPU_G1_SWREG2_SW_DEC_ADV_PRE_DIS_MASK)

#define VPU_G1_SWREG2_SW_TILED_MODE_LSB_MASK     (0x80U)
#define VPU_G1_SWREG2_SW_TILED_MODE_LSB_SHIFT    (7U)
/*! SW_TILED_MODE_LSB - Tiled mode lsb. Concatenated to Tiled mode msb which form 2 bit tiled mode. Defined in tiled_mode_msb */
#define VPU_G1_SWREG2_SW_TILED_MODE_LSB(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_TILED_MODE_LSB_SHIFT)) & VPU_G1_SWREG2_SW_TILED_MODE_LSB_MASK)

#define VPU_G1_SWREG2_SW_DEC_OUT_ENDIAN_MASK     (0x100U)
#define VPU_G1_SWREG2_SW_DEC_OUT_ENDIAN_SHIFT    (8U)
/*! SW_DEC_OUT_ENDIAN - Decoder output endian mode:
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG2_SW_DEC_OUT_ENDIAN(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_OUT_ENDIAN_SHIFT)) & VPU_G1_SWREG2_SW_DEC_OUT_ENDIAN_MASK)

#define VPU_G1_SWREG2_SW_DEC_IN_ENDIAN_MASK      (0x200U)
#define VPU_G1_SWREG2_SW_DEC_IN_ENDIAN_SHIFT     (9U)
/*! SW_DEC_IN_ENDIAN - Decoder input endian mode for other than stream data:
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG2_SW_DEC_IN_ENDIAN(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_IN_ENDIAN_SHIFT)) & VPU_G1_SWREG2_SW_DEC_IN_ENDIAN_MASK)

#define VPU_G1_SWREG2_SW_DEC_CLK_GATE_E_MASK     (0x400U)
#define VPU_G1_SWREG2_SW_DEC_CLK_GATE_E_SHIFT    (10U)
/*! SW_DEC_CLK_GATE_E - Decoder dynamic clock gating enable:
 *  0b0..Clock is running for all structures
 *  0b1..Clock is gated for decoder structures that are not used. Note: Clock gating value can be changed only when decoder is disabled.
 */
#define VPU_G1_SWREG2_SW_DEC_CLK_GATE_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_CLK_GATE_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_CLK_GATE_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_LATENCY_MASK        (0x1F800U)
#define VPU_G1_SWREG2_SW_DEC_LATENCY_SHIFT       (11U)
/*! SW_DEC_LATENCY - Decoder master interface additional latency. */
#define VPU_G1_SWREG2_SW_DEC_LATENCY(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_LATENCY_SHIFT)) & VPU_G1_SWREG2_SW_DEC_LATENCY_MASK)

#define VPU_G1_SWREG2_SW_TILED_MODE_MSB_MASK     (0x20000U)
#define VPU_G1_SWREG2_SW_TILED_MODE_MSB_SHIFT    (17U)
/*! SW_TILED_MODE_MSB - Tiled mode msb. Concatenated to Tiled mode lsb which form 2 bit tiled mode.
 *  0b0..Tiled mode not enabled
 *  0b1..Tiled mode enabled for 8x4 tile size
 */
#define VPU_G1_SWREG2_SW_TILED_MODE_MSB(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_TILED_MODE_MSB_SHIFT)) & VPU_G1_SWREG2_SW_TILED_MODE_MSB_MASK)

#define VPU_G1_SWREG2_SW_DEC_DATA_DISC_E_MASK    (0x40000U)
#define VPU_G1_SWREG2_SW_DEC_DATA_DISC_E_SHIFT   (18U)
/*! SW_DEC_DATA_DISC_E - Data discard enable. Precise burst lengths are used with reading services.
 *    Extra data is discarded internally. Note. If AHB maxburst 17 is used data discard cannot be
 *    enabled (causes conflict)
 */
#define VPU_G1_SWREG2_SW_DEC_DATA_DISC_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_DATA_DISC_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_DATA_DISC_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_OUTSWAP32_E_MASK    (0x80000U)
#define VPU_G1_SWREG2_SW_DEC_OUTSWAP32_E_SHIFT   (19U)
/*! SW_DEC_OUTSWAP32_E - Decoder output 32bit data swap (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order(also little endian should be enabled))
 */
#define VPU_G1_SWREG2_SW_DEC_OUTSWAP32_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_OUTSWAP32_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_OUTSWAP32_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_INSWAP32_E_MASK     (0x100000U)
#define VPU_G1_SWREG2_SW_DEC_INSWAP32_E_SHIFT    (20U)
/*! SW_DEC_INSWAP32_E - Decoder input 32bit data swap for other than stream data (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order(also little endian should be enabled))
 */
#define VPU_G1_SWREG2_SW_DEC_INSWAP32_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_INSWAP32_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_INSWAP32_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_STRENDIAN_E_MASK    (0x200000U)
#define VPU_G1_SWREG2_SW_DEC_STRENDIAN_E_SHIFT   (21U)
/*! SW_DEC_STRENDIAN_E - Decoder input endian mode for stream data:
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG2_SW_DEC_STRENDIAN_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_STRENDIAN_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_STRENDIAN_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_STRSWAP32_E_MASK    (0x400000U)
#define VPU_G1_SWREG2_SW_DEC_STRSWAP32_E_SHIFT   (22U)
/*! SW_DEC_STRSWAP32_E - Decoder input 32bit data swap for stream data (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order(also little endian should be enabled))
 */
#define VPU_G1_SWREG2_SW_DEC_STRSWAP32_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_STRSWAP32_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_STRSWAP32_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_TIMEOUT_E_MASK      (0x800000U)
#define VPU_G1_SWREG2_SW_DEC_TIMEOUT_E_SHIFT     (23U)
/*! SW_DEC_TIMEOUT_E - Timeout interrupt enable. If enabled HW may return timeout interrupt in case HW gets stuck while decoding picture. */
#define VPU_G1_SWREG2_SW_DEC_TIMEOUT_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_TIMEOUT_E_SHIFT)) & VPU_G1_SWREG2_SW_DEC_TIMEOUT_E_MASK)

#define VPU_G1_SWREG2_SW_DEC_AXI_RD_ID_MASK      (0xFF000000U)
#define VPU_G1_SWREG2_SW_DEC_AXI_RD_ID_SHIFT     (24U)
/*! SW_DEC_AXI_RD_ID - Read ID used for decoder reading services in AXI bus (if connected to AXI). */
#define VPU_G1_SWREG2_SW_DEC_AXI_RD_ID(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG2_SW_DEC_AXI_RD_ID_SHIFT)) & VPU_G1_SWREG2_SW_DEC_AXI_RD_ID_MASK)
/*! @} */

/*! @name SWREG3 - Decoder control register 0 (decmode,picture type etc) */
/*! @{ */

#define VPU_G1_SWREG3_SW_DEC_AXI_WR_ID_MASK      (0xFFU)
#define VPU_G1_SWREG3_SW_DEC_AXI_WR_ID_SHIFT     (0U)
/*! SW_DEC_AXI_WR_ID - Write ID used for decoder writing services in AXI bus (if connected to AXI) */
#define VPU_G1_SWREG3_SW_DEC_AXI_WR_ID(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_DEC_AXI_WR_ID_SHIFT)) & VPU_G1_SWREG3_SW_DEC_AXI_WR_ID_MASK)

#define VPU_G1_SWREG3_SW_DEC_AHB_HLOCK_E_MASK    (0x100U)
#define VPU_G1_SWREG3_SW_DEC_AHB_HLOCK_E_SHIFT   (8U)
/*! SW_DEC_AHB_HLOCK_E - AHB master HLOCK enable. When high the service is locked to decoder as long
 *    as it needs the bus (whenever decoder requests the bus it will be granted)
 */
#define VPU_G1_SWREG3_SW_DEC_AHB_HLOCK_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_DEC_AHB_HLOCK_E_SHIFT)) & VPU_G1_SWREG3_SW_DEC_AHB_HLOCK_E_MASK)

#define VPU_G1_SWREG3_SW_PICORD_COUNT_E_MASK     (0x200U)
#define VPU_G1_SWREG3_SW_PICORD_COUNT_E_SHIFT    (9U)
/*! SW_PICORD_COUNT_E - h264_high config: Picture order count table read enable. If enabled HW will
 *    read picture order counts from memory in the beginning of picture
 */
#define VPU_G1_SWREG3_SW_PICORD_COUNT_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PICORD_COUNT_E_SHIFT)) & VPU_G1_SWREG3_SW_PICORD_COUNT_E_MASK)

#define VPU_G1_SWREG3_SW_SEQ_MBAFF_E_MASK        (0x400U)
#define VPU_G1_SWREG3_SW_SEQ_MBAFF_E_SHIFT       (10U)
/*! SW_SEQ_MBAFF_E - Sequence includes MBAFF coded pictures */
#define VPU_G1_SWREG3_SW_SEQ_MBAFF_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_SEQ_MBAFF_E_SHIFT)) & VPU_G1_SWREG3_SW_SEQ_MBAFF_E_MASK)

#define VPU_G1_SWREG3_SW_REFTOPFIRST_E_MASK      (0x800U)
#define VPU_G1_SWREG3_SW_REFTOPFIRST_E_SHIFT     (11U)
/*! SW_REFTOPFIRST_E - Indicates which FWD reference field has been decoded first.
 *  0b0..FWD reference bottom field
 *  0b1..FWD reference top field
 */
#define VPU_G1_SWREG3_SW_REFTOPFIRST_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_REFTOPFIRST_E_SHIFT)) & VPU_G1_SWREG3_SW_REFTOPFIRST_E_MASK)

#define VPU_G1_SWREG3_SW_WRITE_MVS_E_MASK        (0x1000U)
#define VPU_G1_SWREG3_SW_WRITE_MVS_E_SHIFT       (12U)
/*! SW_WRITE_MVS_E - Direct mode motion vector write enable for current picture / VPX motion vector
 *    write enable for error concealment purposes:
 *  0b0..Writing disabled for current picture
 *  0b1..The direct mode motion vectors are written to external memory. H264 direct mode motion vectors are
 *       written to DPB aside with the corresponding reference picture. Other decoding mode dir mode mvs are written to
 *       external memory starting from sw_dir_mv_base.
 */
#define VPU_G1_SWREG3_SW_WRITE_MVS_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_WRITE_MVS_E_SHIFT)) & VPU_G1_SWREG3_SW_WRITE_MVS_E_MASK)

#define VPU_G1_SWREG3_SW_WEBP_E_MASK             (0x2000U)
#define VPU_G1_SWREG3_SW_WEBP_E_SHIFT            (13U)
#define VPU_G1_SWREG3_SW_WEBP_E(x)               (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_WEBP_E_SHIFT)) & VPU_G1_SWREG3_SW_WEBP_E_MASK)

#define VPU_G1_SWREG3_SW_FILTERING_DIS_MASK      (0x4000U)
#define VPU_G1_SWREG3_SW_FILTERING_DIS_SHIFT     (14U)
/*! SW_FILTERING_DIS - De-block filtering disable:
 *  0b0..filtering is enabled for current picture
 *  0b1..filtering is disabled for current picture
 */
#define VPU_G1_SWREG3_SW_FILTERING_DIS(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_FILTERING_DIS_SHIFT)) & VPU_G1_SWREG3_SW_FILTERING_DIS_MASK)

#define VPU_G1_SWREG3_SW_DEC_OUT_DIS_MASK        (0x8000U)
#define VPU_G1_SWREG3_SW_DEC_OUT_DIS_SHIFT       (15U)
/*! SW_DEC_OUT_DIS - Disable decoder output picture writing:
 *  0b0..Decoder output picture is written to external memory
 *  0b1..Decoder output picture is not written to external memory
 */
#define VPU_G1_SWREG3_SW_DEC_OUT_DIS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_DEC_OUT_DIS_SHIFT)) & VPU_G1_SWREG3_SW_DEC_OUT_DIS_MASK)

#define VPU_G1_SWREG3_SW_REF_TOPFIELD_E_MASK     (0x10000U)
#define VPU_G1_SWREG3_SW_REF_TOPFIELD_E_SHIFT    (16U)
/*! SW_REF_TOPFIELD_E - Indicates which field should be used as reference if sw_ref_frames = '0':
 *  0b0..bottom field
 *  0b1..top field
 */
#define VPU_G1_SWREG3_SW_REF_TOPFIELD_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_REF_TOPFIELD_E_SHIFT)) & VPU_G1_SWREG3_SW_REF_TOPFIELD_E_MASK)

#define VPU_G1_SWREG3_SW_FWD_INTERLACE_E_MASK    (0x40000U)
#define VPU_G1_SWREG3_SW_FWD_INTERLACE_E_SHIFT   (18U)
/*! SW_FWD_INTERLACE_E - Coding mode of forward reference picture
 *  0b0..progressive
 *  0b1..interlaced
 */
#define VPU_G1_SWREG3_SW_FWD_INTERLACE_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_FWD_INTERLACE_E_SHIFT)) & VPU_G1_SWREG3_SW_FWD_INTERLACE_E_MASK)

#define VPU_G1_SWREG3_SW_PIC_TOPFIELD_E_MASK     (0x80000U)
#define VPU_G1_SWREG3_SW_PIC_TOPFIELD_E_SHIFT    (19U)
/*! SW_PIC_TOPFIELD_E - If field structure is enabled, this bit informs which one of the fields is being decoded:
 *  0b0..bottom field
 *  0b1..top field
 */
#define VPU_G1_SWREG3_SW_PIC_TOPFIELD_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PIC_TOPFIELD_E_SHIFT)) & VPU_G1_SWREG3_SW_PIC_TOPFIELD_E_MASK)

#define VPU_G1_SWREG3_SW_PIC_INTER_E_MASK        (0x100000U)
#define VPU_G1_SWREG3_SW_PIC_INTER_E_SHIFT       (20U)
/*! SW_PIC_INTER_E - Picture type. Please also see SW_PIC_B_E.
 *  0b0..Intra type (I)
 *  0b1..Inter type (P)
 */
#define VPU_G1_SWREG3_SW_PIC_INTER_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PIC_INTER_E_SHIFT)) & VPU_G1_SWREG3_SW_PIC_INTER_E_MASK)

#define VPU_G1_SWREG3_SW_PIC_B_E_MASK            (0x200000U)
#define VPU_G1_SWREG3_SW_PIC_B_E_SHIFT           (21U)
/*! SW_PIC_B_E - B picture enable for current picture:
 *  0b0..picture type is I or P depending on sw_pic_inter_e
 *  0b1..picture type is B depending on sw_pic_inter_e (not valid for H264 since it is slice based information)
 */
#define VPU_G1_SWREG3_SW_PIC_B_E(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PIC_B_E_SHIFT)) & VPU_G1_SWREG3_SW_PIC_B_E_MASK)

#define VPU_G1_SWREG3_SW_PIC_FIELDMODE_E_MASK    (0x400000U)
#define VPU_G1_SWREG3_SW_PIC_FIELDMODE_E_SHIFT   (22U)
/*! SW_PIC_FIELDMODE_E - Structure of the current picture (residual structure)
 *  0b0..Frame structure. For H264, this means MBAFF structured picture for interlaced sequence
 *  0b1..Field structure
 */
#define VPU_G1_SWREG3_SW_PIC_FIELDMODE_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PIC_FIELDMODE_E_SHIFT)) & VPU_G1_SWREG3_SW_PIC_FIELDMODE_E_MASK)

#define VPU_G1_SWREG3_SW_PIC_INTERLACE_E_MASK    (0x800000U)
#define VPU_G1_SWREG3_SW_PIC_INTERLACE_E_SHIFT   (23U)
/*! SW_PIC_INTERLACE_E - Coding mode of the current picture:
 *  0b0..progressive
 *  0b1..interlaced
 */
#define VPU_G1_SWREG3_SW_PIC_INTERLACE_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_PIC_INTERLACE_E_SHIFT)) & VPU_G1_SWREG3_SW_PIC_INTERLACE_E_MASK)

#define VPU_G1_SWREG3_SW_SKIP_MODE_MASK          (0x4000000U)
#define VPU_G1_SWREG3_SW_SKIP_MODE_SHIFT         (26U)
#define VPU_G1_SWREG3_SW_SKIP_MODE(x)            (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_SKIP_MODE_SHIFT)) & VPU_G1_SWREG3_SW_SKIP_MODE_MASK)

#define VPU_G1_SWREG3_SW_RLC_MODE_E_MASK         (0x8000000U)
#define VPU_G1_SWREG3_SW_RLC_MODE_E_SHIFT        (27U)
/*! SW_RLC_MODE_E - RLC mode enable:
 *  0b0..HW decodes video from bit stream (VLC mode) + side information
 *  0b1..HW decodes video from RLC input data + side information (Differential MV's, separate DC coeffs, Intra 4x4
 *       modes, MB control). Valid only for H.264 Baseline.
 */
#define VPU_G1_SWREG3_SW_RLC_MODE_E(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_RLC_MODE_E_SHIFT)) & VPU_G1_SWREG3_SW_RLC_MODE_E_MASK)

#define VPU_G1_SWREG3_SW_DEC_MODE_MASK           (0xF0000000U)
#define VPU_G1_SWREG3_SW_DEC_MODE_SHIFT          (28U)
/*! SW_DEC_MODE - Decoding mode:
 *  0b0000..H.264
 *  0b0001..Reserved
 *  0b0010..Reserved
 *  0b0011..Reserved
 *  0b0100..Reserved
 *  0b0101..Reserved
 *  0b0110..Reserved
 *  0b0111..Reserved
 *  0b1000..Reserved
 *  0b1001..Reserved
 *  0b1010..VP8
 *  0b1011..Reserved
 *  0b1100..Reserved
 *  0b1101..Reserved
 *  0b1110..Reserved
 *  0b1111..Reserved
 */
#define VPU_G1_SWREG3_SW_DEC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG3_SW_DEC_MODE_SHIFT)) & VPU_G1_SWREG3_SW_DEC_MODE_MASK)
/*! @} */

/*! @name SWREG12 - Base address for RLC data (RLC) / stream start address/decoded end addr register (VLC) */
/*! @{ */

#define VPU_G1_SWREG12_SW_RLC_VLC_BASE_MASK      (0xFFFFFFFFU)
#define VPU_G1_SWREG12_SW_RLC_VLC_BASE_SHIFT     (0U)
#define VPU_G1_SWREG12_SW_RLC_VLC_BASE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG12_SW_RLC_VLC_BASE_SHIFT)) & VPU_G1_SWREG12_SW_RLC_VLC_BASE_MASK)
/*! @} */

/*! @name SWREG13 - Base address for decoded picture */
/*! @{ */

#define VPU_G1_SWREG13_SW_DPB_ILACE_MODE_MASK    (0x2U)
#define VPU_G1_SWREG13_SW_DPB_ILACE_MODE_SHIFT   (1U)
/*! SW_DPB_ILACE_MODE - DPB ilaced mode: '0' : DPB consist of ilaced/progressive frames '1' : DPB
 *    consist of progressive frames / separate fields. This mode requires config support from HW
 */
#define VPU_G1_SWREG13_SW_DPB_ILACE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG13_SW_DPB_ILACE_MODE_SHIFT)) & VPU_G1_SWREG13_SW_DPB_ILACE_MODE_MASK)

#define VPU_G1_SWREG13_SW_DEC_OUT_BASE_MASK      (0xFFFFFFFCU)
#define VPU_G1_SWREG13_SW_DEC_OUT_BASE_SHIFT     (2U)
/*! SW_DEC_OUT_BASE - Video: Base address for decoder output picture. Points directly to start of decoder output picture or field. */
#define VPU_G1_SWREG13_SW_DEC_OUT_BASE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG13_SW_DEC_OUT_BASE_SHIFT)) & VPU_G1_SWREG13_SW_DEC_OUT_BASE_MASK)
/*! @} */

/*! @name SWREG40 - Base address for standard dependent tables */
/*! @{ */

#define VPU_G1_SWREG40_SW_QTABLE_BASE_MASK       (0xFFFFFFFCU)
#define VPU_G1_SWREG40_SW_QTABLE_BASE_SHIFT      (2U)
/*! SW_QTABLE_BASE - Base address for standard dependent tables: */
#define VPU_G1_SWREG40_SW_QTABLE_BASE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG40_SW_QTABLE_BASE_SHIFT)) & VPU_G1_SWREG40_SW_QTABLE_BASE_MASK)
/*! @} */

/*! @name SWREG41 - Base address for direct mode motion vectors */
/*! @{ */

#define VPU_G1_SWREG41_SW_DIR_MV_BASE_MASK       (0xFFFFFFFCU)
#define VPU_G1_SWREG41_SW_DIR_MV_BASE_SHIFT      (2U)
/*! SW_DIR_MV_BASE - Direct mode motion vector write/read base address. For H264 this is used only
 *    for direct mode motion vector write base. VP8: Motion vectors are written for error concealment
 *    purposes if sw_write_mvs is high. In error concealment mode motion vectors are read from this
 *    base address
 */
#define VPU_G1_SWREG41_SW_DIR_MV_BASE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG41_SW_DIR_MV_BASE_SHIFT)) & VPU_G1_SWREG41_SW_DIR_MV_BASE_MASK)
/*! @} */

/*! @name SWREG48 - Error concealment register */
/*! @{ */

#define VPU_G1_SWREG48_SW_ERROR_CONC_MODE_MASK   (0x3000U)
#define VPU_G1_SWREG48_SW_ERROR_CONC_MODE_SHIFT  (12U)
/*! SW_ERROR_CONC_MODE - Error concealment mode:
 *  0b00..disabled (normal decoding mode)
 *  0b01..enabled for direct mode MV usage starting from MB defined by sw_startmb_x, sw_startmb_y
 */
#define VPU_G1_SWREG48_SW_ERROR_CONC_MODE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG48_SW_ERROR_CONC_MODE_SHIFT)) & VPU_G1_SWREG48_SW_ERROR_CONC_MODE_MASK)

#define VPU_G1_SWREG48_SW_STARTMB_Y_MASK         (0x7FC000U)
#define VPU_G1_SWREG48_SW_STARTMB_Y_SHIFT        (14U)
/*! SW_STARTMB_Y - Start MB from SW for Y dimension. Used in error concealment case as HW return
 *    value if HW founds an error or in HW init mb for error concealment if SW enables error concealment
 */
#define VPU_G1_SWREG48_SW_STARTMB_Y(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG48_SW_STARTMB_Y_SHIFT)) & VPU_G1_SWREG48_SW_STARTMB_Y_MASK)

#define VPU_G1_SWREG48_SW_STARTMB_X_MASK         (0xFF800000U)
#define VPU_G1_SWREG48_SW_STARTMB_X_SHIFT        (23U)
/*! SW_STARTMB_X - Start MB from SW for X dimension. Used in error concealment case as HW return
 *    value if HW founds an error or in HW init mb for error concealment if SW enables error concealment
 */
#define VPU_G1_SWREG48_SW_STARTMB_X(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG48_SW_STARTMB_X_SHIFT)) & VPU_G1_SWREG48_SW_STARTMB_X_MASK)
/*! @} */

/*! @name SWREG49 - Prediction filter tap register for H264 */
/*! @{ */

#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_2_MASK   (0xFFCU)
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_2_SHIFT  (2U)
/*! SW_PRED_BC_TAP_0_2 - Prediction filter set 0, tap 2 */
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_2(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG49_SW_PRED_BC_TAP_0_2_SHIFT)) & VPU_G1_SWREG49_SW_PRED_BC_TAP_0_2_MASK)

#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_1_MASK   (0x3FF000U)
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_1_SHIFT  (12U)
/*! SW_PRED_BC_TAP_0_1 - Prediction filter set 0, tap 1 */
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_1(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG49_SW_PRED_BC_TAP_0_1_SHIFT)) & VPU_G1_SWREG49_SW_PRED_BC_TAP_0_1_MASK)

#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_0_MASK   (0xFFC00000U)
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_0_SHIFT  (22U)
/*! SW_PRED_BC_TAP_0_0 - Prediction filter set 0, tap 0 */
#define VPU_G1_SWREG49_SW_PRED_BC_TAP_0_0(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG49_SW_PRED_BC_TAP_0_0_SHIFT)) & VPU_G1_SWREG49_SW_PRED_BC_TAP_0_0_MASK)
/*! @} */

/*! @name SWREG50 - Synthesis configuration register decoder 0 */
/*! @{ */

#define VPU_G1_SWREG50_SW_DEC_MAX_OWIDTH_MASK    (0x7FFU)
#define VPU_G1_SWREG50_SW_DEC_MAX_OWIDTH_SHIFT   (0U)
/*! SW_DEC_MAX_OWIDTH - Max configured decoder video resolution that can be decoded. Informed as width of the picture in pixels. */
#define VPU_G1_SWREG50_SW_DEC_MAX_OWIDTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_MAX_OWIDTH_SHIFT)) & VPU_G1_SWREG50_SW_DEC_MAX_OWIDTH_MASK)

#define VPU_G1_SWREG50_SW_DEC_SOREN_PROF_MASK    (0x800U)
#define VPU_G1_SWREG50_SW_DEC_SOREN_PROF_SHIFT   (11U)
/*! SW_DEC_SOREN_PROF - Decoding format support, Sorenson
 *  0b0..not supported
 *  0b1..supported
 */
#define VPU_G1_SWREG50_SW_DEC_SOREN_PROF(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_SOREN_PROF_SHIFT)) & VPU_G1_SWREG50_SW_DEC_SOREN_PROF_MASK)

#define VPU_G1_SWREG50_SW_DEC_BUS_WIDTH_MASK     (0x3000U)
#define VPU_G1_SWREG50_SW_DEC_BUS_WIDTH_SHIFT    (12U)
/*! SW_DEC_BUS_WIDTH
 *  0b00..error
 *  0b01..32 bit bus
 *  0b10..64 bit bus
 *  0b11..128 bit bus
 */
#define VPU_G1_SWREG50_SW_DEC_BUS_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_BUS_WIDTH_SHIFT)) & VPU_G1_SWREG50_SW_DEC_BUS_WIDTH_MASK)

#define VPU_G1_SWREG50_SW_DEC_SYNTH_LAN_MASK     (0xC000U)
#define VPU_G1_SWREG50_SW_DEC_SYNTH_LAN_SHIFT    (14U)
/*! SW_DEC_SYNTH_LAN
 *  0b00..error
 *  0b01..vhdl
 *  0b10..verilog
 */
#define VPU_G1_SWREG50_SW_DEC_SYNTH_LAN(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_SYNTH_LAN_SHIFT)) & VPU_G1_SWREG50_SW_DEC_SYNTH_LAN_MASK)

#define VPU_G1_SWREG50_SW_DEC_BUS_STRD_MASK      (0xF0000U)
#define VPU_G1_SWREG50_SW_DEC_BUS_STRD_SHIFT     (16U)
/*! SW_DEC_BUS_STRD - Connected to standard bus:
 *  0b0000..error
 *  0b0001..AHB master, AHB slave
 *  0b0010..OCP master, OCP slave
 *  0b0011..AXI master, AXI slave
 *  0b0100..AXI master, APB slave
 *  0b0101..AXI master, AHB slave
 */
#define VPU_G1_SWREG50_SW_DEC_BUS_STRD(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_BUS_STRD_SHIFT)) & VPU_G1_SWREG50_SW_DEC_BUS_STRD_MASK)

#define VPU_G1_SWREG50_SW_REF_BUFF_EXIST_MASK    (0x100000U)
#define VPU_G1_SWREG50_SW_REF_BUFF_EXIST_SHIFT   (20U)
/*! SW_REF_BUFF_EXIST - Reference picture buffer usage:
 *  0b0..not supported
 *  0b1..reference buffer is used
 */
#define VPU_G1_SWREG50_SW_REF_BUFF_EXIST(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_REF_BUFF_EXIST_SHIFT)) & VPU_G1_SWREG50_SW_REF_BUFF_EXIST_MASK)

#define VPU_G1_SWREG50_SW_DEC_OBUFF_LEVEL_MASK   (0x200000U)
#define VPU_G1_SWREG50_SW_DEC_OBUFF_LEVEL_SHIFT  (21U)
/*! SW_DEC_OBUFF_LEVEL - Decoder output buffer level:
 *  0b0..1 MB buffering is used
 *  0b1..4 MB buffering is used
 */
#define VPU_G1_SWREG50_SW_DEC_OBUFF_LEVEL(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_OBUFF_LEVEL_SHIFT)) & VPU_G1_SWREG50_SW_DEC_OBUFF_LEVEL_MASK)

#define VPU_G1_SWREG50_SW_DEC_H264_PROF_MASK     (0x3000000U)
#define VPU_G1_SWREG50_SW_DEC_H264_PROF_SHIFT    (24U)
/*! SW_DEC_H264_PROF - Decoding format support, H.264
 *  0b00..not supported
 *  0b01..supported up to baseline profile
 *  0b10..supported up to high profile labeled stream with restricted high profile tools (Tools that are used in Hantro 7280, 8270 encoder)
 *  0b11..supported up to high profile
 */
#define VPU_G1_SWREG50_SW_DEC_H264_PROF(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG50_SW_DEC_H264_PROF_SHIFT)) & VPU_G1_SWREG50_SW_DEC_H264_PROF_MASK)
/*! @} */

/*! @name SWREG51 - Reference picture buffer control register */
/*! @{ */

#define VPU_G1_SWREG51_SW_REFBU_Y_OFFSET_MASK    (0x1FFU)
#define VPU_G1_SWREG51_SW_REFBU_Y_OFFSET_SHIFT   (0U)
/*! SW_REFBU_Y_OFFSET - Y offset for refbufferd. This coordinate is used to compensate the global motion of the video for better buffer hit rate */
#define VPU_G1_SWREG51_SW_REFBU_Y_OFFSET(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_Y_OFFSET_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_Y_OFFSET_MASK)

#define VPU_G1_SWREG51_SW_REFBU_FPARMOD_E_MASK   (0x1000U)
#define VPU_G1_SWREG51_SW_REFBU_FPARMOD_E_SHIFT  (12U)
/*! SW_REFBU_FPARMOD_E - Field parity mode enable. Used in refbufferd evaluation mode.
 *  0b0..use the result field of the evaluation
 *  0b1..use the parity mode field
 */
#define VPU_G1_SWREG51_SW_REFBU_FPARMOD_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_FPARMOD_E_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_FPARMOD_E_MASK)

#define VPU_G1_SWREG51_SW_REFBU_EVAL_E_MASK      (0x2000U)
#define VPU_G1_SWREG51_SW_REFBU_EVAL_E_SHIFT     (13U)
/*! SW_REFBU_EVAL_E - Enable for HW internal reference ID calculation. If given threshold level is
 *    reached by any picture_id after first MB row, that picture_id is used for reference buffer fill
 *    for rest of the picture
 */
#define VPU_G1_SWREG51_SW_REFBU_EVAL_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_EVAL_E_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_EVAL_E_MASK)

#define VPU_G1_SWREG51_SW_REFBU_PICID_MASK       (0x7C000U)
#define VPU_G1_SWREG51_SW_REFBU_PICID_SHIFT      (14U)
/*! SW_REFBU_PICID - The used reference picture ID for reference buffer usage */
#define VPU_G1_SWREG51_SW_REFBU_PICID(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_PICID_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_PICID_MASK)

#define VPU_G1_SWREG51_SW_REFBU_THR_MASK         (0x7FF80000U)
#define VPU_G1_SWREG51_SW_REFBU_THR_SHIFT        (19U)
/*! SW_REFBU_THR - Reference buffer disable threshold value (cache miss amount). Used to buffer shut down (if more misses than allowed) */
#define VPU_G1_SWREG51_SW_REFBU_THR(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_THR_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_THR_MASK)

#define VPU_G1_SWREG51_SW_REFBU_E_MASK           (0x80000000U)
#define VPU_G1_SWREG51_SW_REFBU_E_SHIFT          (31U)
/*! SW_REFBU_E - Refer picture buffer enable:
 *  0b0..refer picture buffer disabled
 *  0b1..refer picture buffer enabled. Valid if picture size is QVGA or more.
 */
#define VPU_G1_SWREG51_SW_REFBU_E(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG51_SW_REFBU_E_SHIFT)) & VPU_G1_SWREG51_SW_REFBU_E_MASK)
/*! @} */

/*! @name SWREG52 - Reference picture buffer information register 1 */
/*! @{ */

#define VPU_G1_SWREG52_SW_REFBU_INTRA_SUM_MASK   (0xFFFFU)
#define VPU_G1_SWREG52_SW_REFBU_INTRA_SUM_SHIFT  (0U)
/*! SW_REFBU_INTRA_SUM - The sum of the luminance 8x8 intra partitions of the picture. The
 *    proceeding of the HW calculation can be read during HW decoding.
 */
#define VPU_G1_SWREG52_SW_REFBU_INTRA_SUM(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG52_SW_REFBU_INTRA_SUM_SHIFT)) & VPU_G1_SWREG52_SW_REFBU_INTRA_SUM_MASK)

#define VPU_G1_SWREG52_SW_REFBU_HIT_SUM_MASK     (0xFFFF0000U)
#define VPU_G1_SWREG52_SW_REFBU_HIT_SUM_SHIFT    (16U)
/*! SW_REFBU_HIT_SUM - The sum of the refbufferd hits of the picture. Determined for each 8x8
 *    luminance partition of the picture. The proceeding of the HW calculation can be read during HW
 *    decoding.
 */
#define VPU_G1_SWREG52_SW_REFBU_HIT_SUM(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG52_SW_REFBU_HIT_SUM_SHIFT)) & VPU_G1_SWREG52_SW_REFBU_HIT_SUM_MASK)
/*! @} */

/*! @name SWREG53 - Reference picture buffer information register 2 */
/*! @{ */

#define VPU_G1_SWREG53_SW_REFBU_Y_MV_SUM_MASK    (0x3FFFFFU)
#define VPU_G1_SWREG53_SW_REFBU_Y_MV_SUM_SHIFT   (0U)
/*! SW_REFBU_Y_MV_SUM - The sum of the decoded motion vector y-components of the picture. The first
 *    luminance motion vector of each MB is used in calculation. Other motion vectors of the MB are
 *    discarded. Each motion vector is saturated between -256 - 255 before calculation. The
 *    proceeding of the HW calculation can be read during HW decoding.
 */
#define VPU_G1_SWREG53_SW_REFBU_Y_MV_SUM(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG53_SW_REFBU_Y_MV_SUM_SHIFT)) & VPU_G1_SWREG53_SW_REFBU_Y_MV_SUM_MASK)
/*! @} */

/*! @name SWREG54 - Synthesis configuration register decoder 1 */
/*! @{ */

#define VPU_G1_SWREG54_SW_DEC_CORE_AM_MASK       (0x380U)
#define VPU_G1_SWREG54_SW_DEC_CORE_AM_SHIFT      (7U)
/*! SW_DEC_CORE_AM - Decoder core amount. If other than 0, the multicore can be used. Each
 *    individual cores can be identified from corresponding core ID register:
 *  0b000..single core decoder
 *  0b001..dual core decoder
 *  0b010..3 core decoder
 *  0b011..4 core decoder
 *  0b100..5 core decoder
 *  0b101..6 core decoder
 *  0b110..7 core decoder
 *  0b111..8 core decoder
 */
#define VPU_G1_SWREG54_SW_DEC_CORE_AM(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_CORE_AM_SHIFT)) & VPU_G1_SWREG54_SW_DEC_CORE_AM_MASK)

#define VPU_G1_SWREG54_SW_DPB_FIELD_E_MASK       (0x400U)
#define VPU_G1_SWREG54_SW_DPB_FIELD_E_SHIFT      (10U)
/*! SW_DPB_FIELD_E - DPB field separate mode support for ilaced content:
 *  0b0..Not supported. For ilaced content, DPB is ilaced frame order.
 *  0b1..Supported. For ilaced content, DPB can consist of ilaced frames or separate fields (TOP/BOT).
 */
#define VPU_G1_SWREG54_SW_DPB_FIELD_E(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DPB_FIELD_E_SHIFT)) & VPU_G1_SWREG54_SW_DPB_FIELD_E_MASK)

#define VPU_G1_SWREG54_SW_VP8_STRIDE_E_MASK      (0x800U)
#define VPU_G1_SWREG54_SW_VP8_STRIDE_E_SHIFT     (11U)
/*! SW_VP8_STRIDE_E - Decoder output stride support for VP8. Separate base addresses for Y/C data
 *    and possibility to set scanline bigger than picture width:
 *  0b0..not supported, Y and C tables attached.
 *  0b1..supported, Y and C tables can be set freely.
 */
#define VPU_G1_SWREG54_SW_VP8_STRIDE_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_VP8_STRIDE_E_SHIFT)) & VPU_G1_SWREG54_SW_VP8_STRIDE_E_MASK)

#define VPU_G1_SWREG54_SW_DEC_ERRCO_LEVEL_MASK   (0x3000U)
#define VPU_G1_SWREG54_SW_DEC_ERRCO_LEVEL_SHIFT  (12U)
/*! SW_DEC_ERRCO_LEVEL - Decoder error concealment support level:
 *  0b00..Error concealment not supported (only error detection)
 *  0b01..VP8 direct mode motion vector error concealment supported
 */
#define VPU_G1_SWREG54_SW_DEC_ERRCO_LEVEL(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_ERRCO_LEVEL_SHIFT)) & VPU_G1_SWREG54_SW_DEC_ERRCO_LEVEL_MASK)

#define VPU_G1_SWREG54_SW_DEC_MAX_OW_EXT_MASK    (0xC000U)
#define VPU_G1_SWREG54_SW_DEC_MAX_OW_EXT_SHIFT   (14U)
/*! SW_DEC_MAX_OW_EXT - Max configured decoder video resolution that can be decoded. This is the MSB part of the configuration signal */
#define VPU_G1_SWREG54_SW_DEC_MAX_OW_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_MAX_OW_EXT_SHIFT)) & VPU_G1_SWREG54_SW_DEC_MAX_OW_EXT_MASK)

#define VPU_G1_SWREG54_SW_DEC_VP8S_ARCH_MASK     (0x10000U)
#define VPU_G1_SWREG54_SW_DEC_VP8S_ARCH_SHIFT    (16U)
/*! SW_DEC_VP8S_ARCH - VP8 Architecture type (for prediction)
 *  0b0..Same prediction architecture as for other decoding formats
 *  0b1..Dedicated small architecture for VP8 (refbuffer cannot be used either)
 */
#define VPU_G1_SWREG54_SW_DEC_VP8S_ARCH(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_VP8S_ARCH_SHIFT)) & VPU_G1_SWREG54_SW_DEC_VP8S_ARCH_MASK)

#define VPU_G1_SWREG54_SW_DEC_TILED_L_MASK       (0x60000U)
#define VPU_G1_SWREG54_SW_DEC_TILED_L_SHIFT      (17U)
/*! SW_DEC_TILED_L - Tiled mode support level
 *  0b00..not supported
 *  0b01..supported with 8x4 tile size for progressive content
 *  0b10..supported with 8x4 tile size for progressive/ilaced content
 */
#define VPU_G1_SWREG54_SW_DEC_TILED_L(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_TILED_L_SHIFT)) & VPU_G1_SWREG54_SW_DEC_TILED_L_MASK)

#define VPU_G1_SWREG54_SW_DEC_WEBP_E_MASK        (0x80000U)
#define VPU_G1_SWREG54_SW_DEC_WEBP_E_SHIFT       (19U)
/*! SW_DEC_WEBP_E - Decoding format support, Web-p
 *  0b0..not supported bigger than 1080p resolution
 *  0b1..supported upto 16kx16k pixel resolution (defined max)
 */
#define VPU_G1_SWREG54_SW_DEC_WEBP_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_WEBP_E_SHIFT)) & VPU_G1_SWREG54_SW_DEC_WEBP_E_MASK)

#define VPU_G1_SWREG54_SW_DEC_MVC_PROF_MASK      (0x100000U)
#define VPU_G1_SWREG54_SW_DEC_MVC_PROF_SHIFT     (20U)
/*! SW_DEC_MVC_PROF - Decoding format support, MVC
 *  0b0..not supported
 *  0b1..supported
 */
#define VPU_G1_SWREG54_SW_DEC_MVC_PROF(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_MVC_PROF_SHIFT)) & VPU_G1_SWREG54_SW_DEC_MVC_PROF_MASK)

#define VPU_G1_SWREG54_SW_DEC_VP8_PROF_MASK      (0x800000U)
#define VPU_G1_SWREG54_SW_DEC_VP8_PROF_SHIFT     (23U)
/*! SW_DEC_VP8_PROF - Decoding format support, VP8
 *  0b0..not supported
 *  0b1..supported
 */
#define VPU_G1_SWREG54_SW_DEC_VP8_PROF(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_VP8_PROF_SHIFT)) & VPU_G1_SWREG54_SW_DEC_VP8_PROF_MASK)

#define VPU_G1_SWREG54_SW_DEC_RTL_ROM_MASK       (0x2000000U)
#define VPU_G1_SWREG54_SW_DEC_RTL_ROM_SHIFT      (25U)
/*! SW_DEC_RTL_ROM - ROM implementation type (If design includes ROMs)
 *  0b0..ROMs are implemented from actual ROM units
 *  0b1..ROMs are implemented from RTL
 */
#define VPU_G1_SWREG54_SW_DEC_RTL_ROM(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_RTL_ROM_SHIFT)) & VPU_G1_SWREG54_SW_DEC_RTL_ROM_MASK)

#define VPU_G1_SWREG54_SW_REF_BUFF2_EXIST_MASK   (0x10000000U)
#define VPU_G1_SWREG54_SW_REF_BUFF2_EXIST_SHIFT  (28U)
/*! SW_REF_BUFF2_EXIST - Reference picture buffer 2 usage:
 *  0b0..not supported
 *  0b1..reference buffer 2 is used
 */
#define VPU_G1_SWREG54_SW_REF_BUFF2_EXIST(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_REF_BUFF2_EXIST_SHIFT)) & VPU_G1_SWREG54_SW_REF_BUFF2_EXIST_MASK)

#define VPU_G1_SWREG54_SW_DEC_DIVX_PROF_MASK     (0x20000000U)
#define VPU_G1_SWREG54_SW_DEC_DIVX_PROF_SHIFT    (29U)
/*! SW_DEC_DIVX_PROF - DIVX Support:
 *  0b0..not supported
 *  0b1..supported
 */
#define VPU_G1_SWREG54_SW_DEC_DIVX_PROF(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_DIVX_PROF_SHIFT)) & VPU_G1_SWREG54_SW_DEC_DIVX_PROF_MASK)

#define VPU_G1_SWREG54_SW_DEC_REFBU_ILACE_MASK   (0x40000000U)
#define VPU_G1_SWREG54_SW_DEC_REFBU_ILACE_SHIFT  (30U)
/*! SW_DEC_REFBU_ILACE - Refbufferd support for interlaced content:
 *  0b0..not supported
 *  0b1..supported
 */
#define VPU_G1_SWREG54_SW_DEC_REFBU_ILACE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG54_SW_DEC_REFBU_ILACE_SHIFT)) & VPU_G1_SWREG54_SW_DEC_REFBU_ILACE_MASK)
/*! @} */

/*! @name SWREG55 - Reference picture buffer 2 / Advanced prefetch control register */
/*! @{ */

#define VPU_G1_SWREG55_SW_APF_THRESHOLD_MASK     (0x3FFFU)
#define VPU_G1_SWREG55_SW_APF_THRESHOLD_SHIFT    (0U)
/*! SW_APF_THRESHOLD - G1 decoder and later :Advanced prefetch threshold value. If current MB
 *    exceeds the threshold the advanced mode is not used. Value 0 disables threshold usage and advanced
 *    prefetch usage is restricted by internal memory limitation only
 */
#define VPU_G1_SWREG55_SW_APF_THRESHOLD(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG55_SW_APF_THRESHOLD_SHIFT)) & VPU_G1_SWREG55_SW_APF_THRESHOLD_MASK)

#define VPU_G1_SWREG55_SW_REFBU2_PICID_MASK      (0x7C000U)
#define VPU_G1_SWREG55_SW_REFBU2_PICID_SHIFT     (14U)
/*! SW_REFBU2_PICID - The used reference picture ID for reference buffer usage */
#define VPU_G1_SWREG55_SW_REFBU2_PICID(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG55_SW_REFBU2_PICID_SHIFT)) & VPU_G1_SWREG55_SW_REFBU2_PICID_MASK)

#define VPU_G1_SWREG55_SW_REFBU2_THR_MASK        (0x7FF80000U)
#define VPU_G1_SWREG55_SW_REFBU2_THR_SHIFT       (19U)
/*! SW_REFBU2_THR - Reference buffer disable threshold value (buffer miss amount). Used to buffer shut down (if more misses than allowed) */
#define VPU_G1_SWREG55_SW_REFBU2_THR(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG55_SW_REFBU2_THR_SHIFT)) & VPU_G1_SWREG55_SW_REFBU2_THR_MASK)

#define VPU_G1_SWREG55_SW_REFBU2_BUF_E_MASK      (0x80000000U)
#define VPU_G1_SWREG55_SW_REFBU2_BUF_E_SHIFT     (31U)
/*! SW_REFBU2_BUF_E - Refer picture buffer 2 enable:
 *  0b0..refer picture buffer disabled
 *  0b1..refer picture buffer enabled. Valid if picture size is QVGA or more (can be turned of by HW if threshold value reached).
 */
#define VPU_G1_SWREG55_SW_REFBU2_BUF_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG55_SW_REFBU2_BUF_E_SHIFT)) & VPU_G1_SWREG55_SW_REFBU2_BUF_E_MASK)
/*! @} */

/*! @name SWREG56 - Reference buffer information register 3 */
/*! @{ */

#define VPU_G1_SWREG56_SW_REFBU_BOT_SUM_MASK     (0xFFFFU)
#define VPU_G1_SWREG56_SW_REFBU_BOT_SUM_SHIFT    (0U)
/*! SW_REFBU_BOT_SUM - The sum of the bottom partitions of the picture */
#define VPU_G1_SWREG56_SW_REFBU_BOT_SUM(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG56_SW_REFBU_BOT_SUM_SHIFT)) & VPU_G1_SWREG56_SW_REFBU_BOT_SUM_MASK)

#define VPU_G1_SWREG56_SW_REFBU_TOP_SUM_MASK     (0xFFFF0000U)
#define VPU_G1_SWREG56_SW_REFBU_TOP_SUM_SHIFT    (16U)
/*! SW_REFBU_TOP_SUM - The sum of the top partitions of the picture */
#define VPU_G1_SWREG56_SW_REFBU_TOP_SUM(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG56_SW_REFBU_TOP_SUM_SHIFT)) & VPU_G1_SWREG56_SW_REFBU_TOP_SUM_MASK)
/*! @} */

/*! @name SWREG57 - Decoder fuse register */
/*! @{ */

#define VPU_G1_SWREG57_FUSE_DEC_REFBUFFER_MASK   (0x80U)
#define VPU_G1_SWREG57_FUSE_DEC_REFBUFFER_SHIFT  (7U)
/*! FUSE_DEC_REFBUFFER - 1 = reference buffer used */
#define VPU_G1_SWREG57_FUSE_DEC_REFBUFFER(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_REFBUFFER_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_REFBUFFER_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MAXW_352_MASK    (0x1000U)
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_352_SHIFT   (12U)
/*! FUSE_DEC_MAXW_352 - 1 = Max video width up to 352 pixels enabled. Priority coded with priority 5. */
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_352(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MAXW_352_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MAXW_352_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MAXW_720_MASK    (0x2000U)
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_720_SHIFT   (13U)
/*! FUSE_DEC_MAXW_720 - 1 = Max video width up to 720 pixels enabled. Priority coded with priority 4. */
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_720(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MAXW_720_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MAXW_720_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1280_MASK   (0x4000U)
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1280_SHIFT  (14U)
/*! FUSE_DEC_MAXW_1280 - 1 = Max video width up to 1280 pixels enabled. Priority coded with priority 3. */
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1280(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MAXW_1280_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MAXW_1280_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1920_MASK   (0x8000U)
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1920_SHIFT  (15U)
/*! FUSE_DEC_MAXW_1920 - 1 = Max video width up to 1920 pixels enabled. Priority coded with priority 2. */
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_1920(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MAXW_1920_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MAXW_1920_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MAXW_4K_MASK     (0x10000U)
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_4K_SHIFT    (16U)
/*! FUSE_DEC_MAXW_4K - 1 = Max video width up to 4096 pixels enabled. Priority coded with priority 1. */
#define VPU_G1_SWREG57_FUSE_DEC_MAXW_4K(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MAXW_4K_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MAXW_4K_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_MVC_MASK         (0x40000U)
#define VPU_G1_SWREG57_FUSE_DEC_MVC_SHIFT        (18U)
/*! FUSE_DEC_MVC - 1 = MVC enabled (requires also H264 to be enabled) */
#define VPU_G1_SWREG57_FUSE_DEC_MVC(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_MVC_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_MVC_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_VP8_MASK         (0x100000U)
#define VPU_G1_SWREG57_FUSE_DEC_VP8_SHIFT        (20U)
/*! FUSE_DEC_VP8 - 1 = VP8 enabled */
#define VPU_G1_SWREG57_FUSE_DEC_VP8(x)           (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_VP8_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_VP8_MASK)

#define VPU_G1_SWREG57_FUSE_DEC_H264_MASK        (0x80000000U)
#define VPU_G1_SWREG57_FUSE_DEC_H264_SHIFT       (31U)
/*! FUSE_DEC_H264 - 1 = H.264 enabled */
#define VPU_G1_SWREG57_FUSE_DEC_H264(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG57_FUSE_DEC_H264_SHIFT)) & VPU_G1_SWREG57_FUSE_DEC_H264_MASK)
/*! @} */

/*! @name SWREG58 - Device configuration register decoder 2 + Multi core control register */
/*! @{ */

#define VPU_G1_SWREG58_SW_DEC_MC_POLLTIME_MASK   (0x7FE0000U)
#define VPU_G1_SWREG58_SW_DEC_MC_POLLTIME_SHIFT  (17U)
/*! SW_DEC_MC_POLLTIME - sw_dec_mc_polltime definition depends on sw_dec_mc_mode. */
#define VPU_G1_SWREG58_SW_DEC_MC_POLLTIME(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG58_SW_DEC_MC_POLLTIME_SHIFT)) & VPU_G1_SWREG58_SW_DEC_MC_POLLTIME_MASK)

#define VPU_G1_SWREG58_SW_DEC_MC_POLLMODE_MASK   (0x18000000U)
#define VPU_G1_SWREG58_SW_DEC_MC_POLLMODE_SHIFT  (27U)
/*! SW_DEC_MC_POLLMODE - Decoder multicore status reading mode:
 *  0b00..HW internal status polling mechanism is used. Status of reference picture is read only when required
 *        coordinate for the reference picture is not big enough. If the status is still not big enough after reading
 *        it the HW waits N clock cycles per pixel from the coordinate difference. The N is defined by the
 *        sw_dec_mc_polltime (range 0...4).
 *  0b01..Dummy status polling mechanism is used for all reference pictures. HW reads status of all reference
 *        pictures at frequency defined by sw_dec_mc_polltime.
 */
#define VPU_G1_SWREG58_SW_DEC_MC_POLLMODE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG58_SW_DEC_MC_POLLMODE_SHIFT)) & VPU_G1_SWREG58_SW_DEC_MC_POLLMODE_MASK)

#define VPU_G1_SWREG58_SW_DEC_WRITESTAT_E_MASK   (0x20000000U)
#define VPU_G1_SWREG58_SW_DEC_WRITESTAT_E_SHIFT  (29U)
/*! SW_DEC_WRITESTAT_E - Decoder write statusword enable. Must be high if multi core decoding
 *    enabled. HW writes output picture data proceeding to external memory after picture data (and after
 *    H264 direct mode MVS if they exist)
 */
#define VPU_G1_SWREG58_SW_DEC_WRITESTAT_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG58_SW_DEC_WRITESTAT_E_SHIFT)) & VPU_G1_SWREG58_SW_DEC_WRITESTAT_E_MASK)

#define VPU_G1_SWREG58_SW_DEC_MULTICORE_E_MASK   (0x40000000U)
#define VPU_G1_SWREG58_SW_DEC_MULTICORE_E_SHIFT  (30U)
/*! SW_DEC_MULTICORE_E - Decoder multi core enable:
 *  0b0..Multi core disabled or only one core exists in design.
 *  0b1..Multi core enable. Each reference picture status must be verified from external memory status field
 *       before usage. 128 bits status word exists after each reference picture and include picture proceeding
 *       coordinates Y and X.
 */
#define VPU_G1_SWREG58_SW_DEC_MULTICORE_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG58_SW_DEC_MULTICORE_E_SHIFT)) & VPU_G1_SWREG58_SW_DEC_MULTICORE_E_MASK)

#define VPU_G1_SWREG58_SW_SERV_MERGE_DIS_MASK    (0x80000000U)
#define VPU_G1_SWREG58_SW_SERV_MERGE_DIS_SHIFT   (31U)
/*! SW_SERV_MERGE_DIS - Decoder service merge disable:
 *  0b0..HW merges simultaneous sub-block requests internally if they are same type (read or write).
 *  0b1..decoder serves one sub-block per service and merging is disabled.
 */
#define VPU_G1_SWREG58_SW_SERV_MERGE_DIS(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG58_SW_SERV_MERGE_DIS_SHIFT)) & VPU_G1_SWREG58_SW_SERV_MERGE_DIS_MASK)
/*! @} */

/*! @name SWREG59 - H264 Chrominance 8 pixel interleaved data base */
/*! @{ */

#define VPU_G1_SWREG59_SW_DEC_CH8PIX_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG59_SW_DEC_CH8PIX_BASE_SHIFT  (2U)
/*! SW_DEC_CH8PIX_BASE - Base address for additional chrominance data format where chrominance is
 *    interleaved in group of 8 pixels. The usage is enabled by sw_ch_8pix_ileav_e
 */
#define VPU_G1_SWREG59_SW_DEC_CH8PIX_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG59_SW_DEC_CH8PIX_BASE_SHIFT)) & VPU_G1_SWREG59_SW_DEC_CH8PIX_BASE_MASK)
/*! @} */

/*! @name SWREG60 - Interrupt register post-processor */
/*! @{ */

#define VPU_G1_SWREG60_SW_PP_E_MASK              (0x1U)
#define VPU_G1_SWREG60_SW_PP_E_SHIFT             (0U)
/*! SW_PP_E - External mode post-processing enable. This bit will start the post-processing
 *    operation. Not to be used if PP is in pipeline with decoder (sw_pp_pipeline_e = 1). HW will reset this
 *    when picture is post-processed.
 */
#define VPU_G1_SWREG60_SW_PP_E(x)                (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_E_SHIFT)) & VPU_G1_SWREG60_SW_PP_E_MASK)

#define VPU_G1_SWREG60_SW_PP_PIPELINE_E_MASK     (0x2U)
#define VPU_G1_SWREG60_SW_PP_PIPELINE_E_SHIFT    (1U)
/*! SW_PP_PIPELINE_E - Decoder - post-processing pipeline enable:
 *  0b0..Post-processing is processing different picture than decoder or is disabled
 *  0b1..Post-processing is performed in pipeline with decoder
 */
#define VPU_G1_SWREG60_SW_PP_PIPELINE_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_PIPELINE_E_SHIFT)) & VPU_G1_SWREG60_SW_PP_PIPELINE_E_MASK)

#define VPU_G1_SWREG60_SW_PP_IRQ_DIS_MASK        (0x10U)
#define VPU_G1_SWREG60_SW_PP_IRQ_DIS_SHIFT       (4U)
/*! SW_PP_IRQ_DIS - Post-processor IRQ disable. When high, there are no interrupts from HW
 *    concerning post processing. Polling must be used to see the interrupt
 */
#define VPU_G1_SWREG60_SW_PP_IRQ_DIS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_IRQ_DIS_SHIFT)) & VPU_G1_SWREG60_SW_PP_IRQ_DIS_MASK)

#define VPU_G1_SWREG60_SW_PP_IRQ_MASK            (0x100U)
#define VPU_G1_SWREG60_SW_PP_IRQ_SHIFT           (8U)
/*! SW_PP_IRQ - Post-processor IRQ. SW will reset this after interrupt is handled. HINTpp is not
 *    used for pp if IRQ disable pp is high (sw_pp_irq_n_e = 1). In pipeline mode this bit is not used
 */
#define VPU_G1_SWREG60_SW_PP_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_IRQ_SHIFT)) & VPU_G1_SWREG60_SW_PP_IRQ_MASK)

#define VPU_G1_SWREG60_SW_PP_RDY_INT_MASK        (0x1000U)
#define VPU_G1_SWREG60_SW_PP_RDY_INT_SHIFT       (12U)
/*! SW_PP_RDY_INT - Interrupt status bit pp. When this bit is high post processor has processed a
 *    picture in external mode. In pipeline mode this bit is not used.
 */
#define VPU_G1_SWREG60_SW_PP_RDY_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_RDY_INT_SHIFT)) & VPU_G1_SWREG60_SW_PP_RDY_INT_MASK)

#define VPU_G1_SWREG60_SW_PP_BUS_INT_MASK        (0x2000U)
#define VPU_G1_SWREG60_SW_PP_BUS_INT_SHIFT       (13U)
/*! SW_PP_BUS_INT - Interrupt status bit bus. Error response from bus. In pipeline mode this bit is not used */
#define VPU_G1_SWREG60_SW_PP_BUS_INT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG60_SW_PP_BUS_INT_SHIFT)) & VPU_G1_SWREG60_SW_PP_BUS_INT_MASK)
/*! @} */

/*! @name SWREG61 - Device configuration register post-processor */
/*! @{ */

#define VPU_G1_SWREG61_SW_PP_MAX_BURST_MASK      (0x1FU)
#define VPU_G1_SWREG61_SW_PP_MAX_BURST_SHIFT     (0U)
/*! SW_PP_MAX_BURST - Maximum burst length for PP bus transactions. */
#define VPU_G1_SWREG61_SW_PP_MAX_BURST(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_MAX_BURST_SHIFT)) & VPU_G1_SWREG61_SW_PP_MAX_BURST_MASK)

#define VPU_G1_SWREG61_SW_PP_OUT_SWAP32_E_MASK   (0x20U)
#define VPU_G1_SWREG61_SW_PP_OUT_SWAP32_E_SHIFT  (5U)
/*! SW_PP_OUT_SWAP32_E - PP output data word swap (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order (also little endian should be enabled))
 */
#define VPU_G1_SWREG61_SW_PP_OUT_SWAP32_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_OUT_SWAP32_E_SHIFT)) & VPU_G1_SWREG61_SW_PP_OUT_SWAP32_E_MASK)

#define VPU_G1_SWREG61_SW_PP_OUT_ENDIAN_MASK     (0x40U)
#define VPU_G1_SWREG61_SW_PP_OUT_ENDIAN_SHIFT    (6U)
/*! SW_PP_OUT_ENDIAN - PP output picture endian mode for YCbCr data or for any data if config value SW_PP_OEN_VERSION = 1.
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG61_SW_PP_OUT_ENDIAN(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_OUT_ENDIAN_SHIFT)) & VPU_G1_SWREG61_SW_PP_OUT_ENDIAN_MASK)

#define VPU_G1_SWREG61_SW_PP_IN_ENDIAN_MASK      (0x80U)
#define VPU_G1_SWREG61_SW_PP_IN_ENDIAN_SHIFT     (7U)
/*! SW_PP_IN_ENDIAN - PP input picture byte endian mode. Used only if PP is in standalone mode. If
 *    PP is running pipelined with the decoder, this bit has no effect.
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG61_SW_PP_IN_ENDIAN(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_IN_ENDIAN_SHIFT)) & VPU_G1_SWREG61_SW_PP_IN_ENDIAN_MASK)

#define VPU_G1_SWREG61_SW_PP_CLK_GATE_E_MASK     (0x100U)
#define VPU_G1_SWREG61_SW_PP_CLK_GATE_E_SHIFT    (8U)
/*! SW_PP_CLK_GATE_E - PP dynamic clock gating enable.
 *  0b0..Clock is running for all PP structures
 *  0b1..Clock is gated from PP structures that are not used
 */
#define VPU_G1_SWREG61_SW_PP_CLK_GATE_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_CLK_GATE_E_SHIFT)) & VPU_G1_SWREG61_SW_PP_CLK_GATE_E_MASK)

#define VPU_G1_SWREG61_SW_PP_DATA_DISC_E_MASK    (0x200U)
#define VPU_G1_SWREG61_SW_PP_DATA_DISC_E_SHIFT   (9U)
/*! SW_PP_DATA_DISC_E - PP data discard enable. Precise burst lengths are used with reading
 *    services. Extra data is discarded internally. Note. If AHB maxburst 17 is used data discard cannot be
 *    enabled (causes conflict)
 */
#define VPU_G1_SWREG61_SW_PP_DATA_DISC_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_DATA_DISC_E_SHIFT)) & VPU_G1_SWREG61_SW_PP_DATA_DISC_E_MASK)

#define VPU_G1_SWREG61_SW_PP_IN_SWAP32_E_MASK    (0x400U)
#define VPU_G1_SWREG61_SW_PP_IN_SWAP32_E_SHIFT   (10U)
/*! SW_PP_IN_SWAP32_E - PP input 32bit data swap (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order(also little endian should be enabled))
 */
#define VPU_G1_SWREG61_SW_PP_IN_SWAP32_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_IN_SWAP32_E_SHIFT)) & VPU_G1_SWREG61_SW_PP_IN_SWAP32_E_MASK)

#define VPU_G1_SWREG61_SW_PP_IN_A1_ENDIAN_MASK   (0x800U)
#define VPU_G1_SWREG61_SW_PP_IN_A1_ENDIAN_SHIFT  (11U)
/*! SW_PP_IN_A1_ENDIAN - Alpha blend source 1 input data byte endian mode.
 *  0b0..Big endian (0-1-2-3 order)
 *  0b1..Little endian (3-2-1-0 order)
 */
#define VPU_G1_SWREG61_SW_PP_IN_A1_ENDIAN(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_IN_A1_ENDIAN_SHIFT)) & VPU_G1_SWREG61_SW_PP_IN_A1_ENDIAN_MASK)

#define VPU_G1_SWREG61_SW_PP_IN_A1_SWAP32_MASK   (0x1000U)
#define VPU_G1_SWREG61_SW_PP_IN_A1_SWAP32_SHIFT  (12U)
/*! SW_PP_IN_A1_SWAP32 - Alpha blend source 1 input 32bit data swap (may be used for 64 bit environment):
 *  0b0..no swapping of 32 bit words
 *  0b1..32 bit data words are swapped (needed in 64 bit environment to achieve 7-6-5-4-3-2-1-0 byte order(also little endian should be enabled))
 */
#define VPU_G1_SWREG61_SW_PP_IN_A1_SWAP32(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_IN_A1_SWAP32_SHIFT)) & VPU_G1_SWREG61_SW_PP_IN_A1_SWAP32_MASK)

#define VPU_G1_SWREG61_SW_PP_IN_A2_ENDSEL_MASK   (0x2000U)
#define VPU_G1_SWREG61_SW_PP_IN_A2_ENDSEL_SHIFT  (13U)
/*! SW_PP_IN_A2_ENDSEL - Endian/swap select for Alpha blend input source 2:
 *  0b0..Use PP in endian/swap definitions (sw_pp_in_endian, sw_pp_in_swap)
 *  0b1..Use Ablend source 1 endian/swap definitions (sw_pp_in_a1_endian, sw_pp_in_a1_swap)
 */
#define VPU_G1_SWREG61_SW_PP_IN_A2_ENDSEL(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_IN_A2_ENDSEL_SHIFT)) & VPU_G1_SWREG61_SW_PP_IN_A2_ENDSEL_MASK)

#define VPU_G1_SWREG61_SW_PP_SCMD_DIS_MASK       (0x4000U)
#define VPU_G1_SWREG61_SW_PP_SCMD_DIS_SHIFT      (14U)
/*! SW_PP_SCMD_DIS - 9170 decoder: AXI Single Command Multiple Data disable. 9170 axi wrapper
 *    supports this mode by default (where only the first addresses of the burst are given from address
 *    generator). This bit is used to disable the feature (possible SW workaround if something is not
 *    working correctly)
 */
#define VPU_G1_SWREG61_SW_PP_SCMD_DIS(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_SCMD_DIS_SHIFT)) & VPU_G1_SWREG61_SW_PP_SCMD_DIS_MASK)

#define VPU_G1_SWREG61_SW_PP_AHB_HLOCK_E_MASK    (0x8000U)
#define VPU_G1_SWREG61_SW_PP_AHB_HLOCK_E_SHIFT   (15U)
/*! SW_PP_AHB_HLOCK_E - AHB master HLOCK enable. When high the service is locked to pp as long as it
 *    needs the bus (whenever pp requests the bus it will be granted)
 */
#define VPU_G1_SWREG61_SW_PP_AHB_HLOCK_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_AHB_HLOCK_E_SHIFT)) & VPU_G1_SWREG61_SW_PP_AHB_HLOCK_E_MASK)

#define VPU_G1_SWREG61_SW_PP_AXI_WR_ID_MASK      (0xFF0000U)
#define VPU_G1_SWREG61_SW_PP_AXI_WR_ID_SHIFT     (16U)
/*! SW_PP_AXI_WR_ID - Write ID used for AXI PP write services (if connected to AXI) */
#define VPU_G1_SWREG61_SW_PP_AXI_WR_ID(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_AXI_WR_ID_SHIFT)) & VPU_G1_SWREG61_SW_PP_AXI_WR_ID_MASK)

#define VPU_G1_SWREG61_SW_PP_AXI_RD_ID_MASK      (0xFF000000U)
#define VPU_G1_SWREG61_SW_PP_AXI_RD_ID_SHIFT     (24U)
/*! SW_PP_AXI_RD_ID - Read ID used for AXI PP read services (if connected to AXI) */
#define VPU_G1_SWREG61_SW_PP_AXI_RD_ID(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG61_SW_PP_AXI_RD_ID_SHIFT)) & VPU_G1_SWREG61_SW_PP_AXI_RD_ID_MASK)
/*! @} */

/*! @name SWREG62 - Deinterlace control register */
/*! @{ */

#define VPU_G1_SWREG62_SW_DEINT_EDGE_DET_MASK    (0x7FFFU)
#define VPU_G1_SWREG62_SW_DEINT_EDGE_DET_SHIFT   (0U)
/*! SW_DEINT_EDGE_DET - Edge detect value used for deinterlacing */
#define VPU_G1_SWREG62_SW_DEINT_EDGE_DET(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG62_SW_DEINT_EDGE_DET_SHIFT)) & VPU_G1_SWREG62_SW_DEINT_EDGE_DET_MASK)

#define VPU_G1_SWREG62_SW_DEINT_BLEND_E_MASK     (0x8000U)
#define VPU_G1_SWREG62_SW_DEINT_BLEND_E_SHIFT    (15U)
/*! SW_DEINT_BLEND_E - Blend enable for de-interlacing */
#define VPU_G1_SWREG62_SW_DEINT_BLEND_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG62_SW_DEINT_BLEND_E_SHIFT)) & VPU_G1_SWREG62_SW_DEINT_BLEND_E_MASK)

#define VPU_G1_SWREG62_SW_DEINT_THRESHOLD_MASK   (0x3FFF0000U)
#define VPU_G1_SWREG62_SW_DEINT_THRESHOLD_SHIFT  (16U)
/*! SW_DEINT_THRESHOLD - Threshold value used in deinterlacing */
#define VPU_G1_SWREG62_SW_DEINT_THRESHOLD(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG62_SW_DEINT_THRESHOLD_SHIFT)) & VPU_G1_SWREG62_SW_DEINT_THRESHOLD_MASK)

#define VPU_G1_SWREG62_SW_DEINT_E_MASK           (0x80000000U)
#define VPU_G1_SWREG62_SW_DEINT_E_SHIFT          (31U)
/*! SW_DEINT_E - De-interlace enable. Input data is in interlaced format and deinterlacing needs to be performed */
#define VPU_G1_SWREG62_SW_DEINT_E(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG62_SW_DEINT_E_SHIFT)) & VPU_G1_SWREG62_SW_DEINT_E_MASK)
/*! @} */

/*! @name SWREG63 - Base address for reading post-processing input picture luminance (top field/frame) */
/*! @{ */

#define VPU_G1_SWREG63_SW_PP_IN_LU_BASE_MASK     (0xFFFFFFFCU)
#define VPU_G1_SWREG63_SW_PP_IN_LU_BASE_SHIFT    (2U)
/*! SW_PP_IN_LU_BASE - Base address for post-processing input luminance picture. If PP input picture
 *    is fetched from fields this base address is used to point to top field of the picture. Used
 *    in external mode only.
 */
#define VPU_G1_SWREG63_SW_PP_IN_LU_BASE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG63_SW_PP_IN_LU_BASE_SHIFT)) & VPU_G1_SWREG63_SW_PP_IN_LU_BASE_MASK)
/*! @} */

/*! @name SWREG64 - Base address for reading post-processing input picture Cb/Ch (top field/frame) */
/*! @{ */

#define VPU_G1_SWREG64_SW_PP_IN_CB_BASE_MASK     (0xFFFFFFFCU)
#define VPU_G1_SWREG64_SW_PP_IN_CB_BASE_SHIFT    (2U)
/*! SW_PP_IN_CB_BASE - Base address for post-processing input Cb picture or for both chrominance
 *    pictures (if chrominances interleaved). If PP input picture is fetched from fields this base
 *    address is used to point to top field of the picture. Used in external mode only
 */
#define VPU_G1_SWREG64_SW_PP_IN_CB_BASE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG64_SW_PP_IN_CB_BASE_SHIFT)) & VPU_G1_SWREG64_SW_PP_IN_CB_BASE_MASK)
/*! @} */

/*! @name SWREG65 - Base address for reading post-processing input picture Cr */
/*! @{ */

#define VPU_G1_SWREG65_SW_PP_IN_CR_BASE_MASK     (0xFFFFFFFCU)
#define VPU_G1_SWREG65_SW_PP_IN_CR_BASE_SHIFT    (2U)
/*! SW_PP_IN_CR_BASE - Base address for post-processing input cr picture. Used in external mode only */
#define VPU_G1_SWREG65_SW_PP_IN_CR_BASE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG65_SW_PP_IN_CR_BASE_SHIFT)) & VPU_G1_SWREG65_SW_PP_IN_CR_BASE_MASK)
/*! @} */

/*! @name SWREG66 - Base address for writing post-processed picture luminance/RGB */
/*! @{ */

#define VPU_G1_SWREG66_SW_PP_OUT_LU_BASE_MASK    (0xFFFFFFFFU)
#define VPU_G1_SWREG66_SW_PP_OUT_LU_BASE_SHIFT   (0U)
/*! SW_PP_OUT_LU_BASE - Base address for post-processing output picture (luminance/YUYV/RGB). NOTE:
 *    Bits 2:0 are used to adjust the post-processor output to start from zertain byte (1:0 for 32
 *    bit bus). These bits can be other than zero only if Pixel Accurate PP output configuration is
 *    enabled
 */
#define VPU_G1_SWREG66_SW_PP_OUT_LU_BASE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG66_SW_PP_OUT_LU_BASE_SHIFT)) & VPU_G1_SWREG66_SW_PP_OUT_LU_BASE_MASK)
/*! @} */

/*! @name SWREG67 - Base address for writing post-processed picture Ch */
/*! @{ */

#define VPU_G1_SWREG67_SW_PP_OUT_CH_BASE_MASK    (0xFFFFFFFFU)
#define VPU_G1_SWREG67_SW_PP_OUT_CH_BASE_SHIFT   (0U)
/*! SW_PP_OUT_CH_BASE - Base address for post-processing output chrominance picture (interleaved
 *    chrominance). NOTE: Bits 2:0 are used to adjust the post-processor output to start from zertain
 *    byte (1:0 for 32 bit bus). These bits can be other than zero only if Pixel Accurate PP output
 *    configuration is enabled
 */
#define VPU_G1_SWREG67_SW_PP_OUT_CH_BASE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG67_SW_PP_OUT_CH_BASE_SHIFT)) & VPU_G1_SWREG67_SW_PP_OUT_CH_BASE_MASK)
/*! @} */

/*! @name SWREG68 - Register for contrast adjusting */
/*! @{ */

#define VPU_G1_SWREG68_SW_CONTRAST_OFF1_MASK     (0x3FFU)
#define VPU_G1_SWREG68_SW_CONTRAST_OFF1_SHIFT    (0U)
/*! SW_CONTRAST_OFF1 - Offset value 1, used with contrast adjusting */
#define VPU_G1_SWREG68_SW_CONTRAST_OFF1(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG68_SW_CONTRAST_OFF1_SHIFT)) & VPU_G1_SWREG68_SW_CONTRAST_OFF1_MASK)

#define VPU_G1_SWREG68_SW_CONTRAST_OFF2_MASK     (0xFFC00U)
#define VPU_G1_SWREG68_SW_CONTRAST_OFF2_SHIFT    (10U)
/*! SW_CONTRAST_OFF2 - Offset value 2, used with contrast adjusting */
#define VPU_G1_SWREG68_SW_CONTRAST_OFF2(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG68_SW_CONTRAST_OFF2_SHIFT)) & VPU_G1_SWREG68_SW_CONTRAST_OFF2_MASK)

#define VPU_G1_SWREG68_SW_CONTRAST_THR1_MASK     (0xFF000000U)
#define VPU_G1_SWREG68_SW_CONTRAST_THR1_SHIFT    (24U)
/*! SW_CONTRAST_THR1 - Threshold value 1, used with contrast adjusting */
#define VPU_G1_SWREG68_SW_CONTRAST_THR1(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG68_SW_CONTRAST_THR1_SHIFT)) & VPU_G1_SWREG68_SW_CONTRAST_THR1_MASK)
/*! @} */

/*! @name SWREG69 - Register for colour conversion and contrast adjusting/YUYV 422 channel orders */
/*! @{ */

#define VPU_G1_SWREG69_SW_CONTRAST_THR2_MASK     (0xFFU)
#define VPU_G1_SWREG69_SW_CONTRAST_THR2_SHIFT    (0U)
/*! SW_CONTRAST_THR2 - Threshold value 2, used with contrast adjusting */
#define VPU_G1_SWREG69_SW_CONTRAST_THR2(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_CONTRAST_THR2_SHIFT)) & VPU_G1_SWREG69_SW_CONTRAST_THR2_MASK)

#define VPU_G1_SWREG69_SW_COLOR_COEFFA1_MASK     (0x3FF00U)
#define VPU_G1_SWREG69_SW_COLOR_COEFFA1_SHIFT    (8U)
/*! SW_COLOR_COEFFA1 - Coefficient a1, used with Y pixel to calculate all color components */
#define VPU_G1_SWREG69_SW_COLOR_COEFFA1(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_COLOR_COEFFA1_SHIFT)) & VPU_G1_SWREG69_SW_COLOR_COEFFA1_MASK)

#define VPU_G1_SWREG69_SW_COLOR_COEFFA2_MASK     (0xFFC0000U)
#define VPU_G1_SWREG69_SW_COLOR_COEFFA2_SHIFT    (18U)
/*! SW_COLOR_COEFFA2 - Coefficient a2, used with Y pixel to calculate all color components */
#define VPU_G1_SWREG69_SW_COLOR_COEFFA2(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_COLOR_COEFFA2_SHIFT)) & VPU_G1_SWREG69_SW_COLOR_COEFFA2_MASK)

#define VPU_G1_SWREG69_SW_PP_OUT_CR_FIRST_MASK   (0x10000000U)
#define VPU_G1_SWREG69_SW_PP_OUT_CR_FIRST_SHIFT  (28U)
/*! SW_PP_OUT_CR_FIRST - For YUYV 422 output format. Enable for Cr first (before Cb).
 *  0b0..the order is Y0CbY0Cr or CbY0CrY0
 *  0b1..the order is Y0CrY0Cb or CrY0CbY0
 */
#define VPU_G1_SWREG69_SW_PP_OUT_CR_FIRST(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_PP_OUT_CR_FIRST_SHIFT)) & VPU_G1_SWREG69_SW_PP_OUT_CR_FIRST_MASK)

#define VPU_G1_SWREG69_SW_PP_OUT_START_CH_MASK   (0x20000000U)
#define VPU_G1_SWREG69_SW_PP_OUT_START_CH_SHIFT  (29U)
/*! SW_PP_OUT_START_CH - For YUYV 422 output format. Enable for start_with_chrominance.
 *  0b0..the order is Y0CbY0Cr or Y0CrY0Cb
 *  0b1..the order is CbY0CrY0 or CrY0CbY0
 */
#define VPU_G1_SWREG69_SW_PP_OUT_START_CH(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_PP_OUT_START_CH_SHIFT)) & VPU_G1_SWREG69_SW_PP_OUT_START_CH_MASK)

#define VPU_G1_SWREG69_SW_PP_IN_CR_FIRST_MASK    (0x40000000U)
#define VPU_G1_SWREG69_SW_PP_IN_CR_FIRST_SHIFT   (30U)
/*! SW_PP_IN_CR_FIRST - For YUYV 422 input format. Enable for Cr first (before Cb).
 *  0b0..the order is Y0CbY0Cr or CbY0CrY0 (if 420 semiplanar chrominance: CbCrCbCr)
 *  0b1..the order is Y0CrY0Cb or CrY0CbY0 (if 420 semiplanar chrominance: CrCbCrCb)
 */
#define VPU_G1_SWREG69_SW_PP_IN_CR_FIRST(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_PP_IN_CR_FIRST_SHIFT)) & VPU_G1_SWREG69_SW_PP_IN_CR_FIRST_MASK)

#define VPU_G1_SWREG69_SW_PP_IN_START_CH_MASK    (0x80000000U)
#define VPU_G1_SWREG69_SW_PP_IN_START_CH_SHIFT   (31U)
/*! SW_PP_IN_START_CH - For YUYV 422 input format. Enable for start_with_chrominance.
 *  0b0..the order is Y0CbY0Cr or Y0CrY0Cb
 *  0b1..the order is CbY0CrY0 or CrY0CbY0
 */
#define VPU_G1_SWREG69_SW_PP_IN_START_CH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG69_SW_PP_IN_START_CH_SHIFT)) & VPU_G1_SWREG69_SW_PP_IN_START_CH_MASK)
/*! @} */

/*! @name SWREG70 - Register for colour conversion 0 */
/*! @{ */

#define VPU_G1_SWREG70_SW_COLOR_COEFFB_MASK      (0x3FFU)
#define VPU_G1_SWREG70_SW_COLOR_COEFFB_SHIFT     (0U)
/*! SW_COLOR_COEFFB - Coefficient b, used with Cr to calculate red component value */
#define VPU_G1_SWREG70_SW_COLOR_COEFFB(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG70_SW_COLOR_COEFFB_SHIFT)) & VPU_G1_SWREG70_SW_COLOR_COEFFB_MASK)

#define VPU_G1_SWREG70_SW_COLOR_COEFFC_MASK      (0xFFC00U)
#define VPU_G1_SWREG70_SW_COLOR_COEFFC_SHIFT     (10U)
/*! SW_COLOR_COEFFC - Coefficient c, used with Cr to calculate green component value */
#define VPU_G1_SWREG70_SW_COLOR_COEFFC(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG70_SW_COLOR_COEFFC_SHIFT)) & VPU_G1_SWREG70_SW_COLOR_COEFFC_MASK)

#define VPU_G1_SWREG70_SW_COLOR_COEFFD_MASK      (0x3FF00000U)
#define VPU_G1_SWREG70_SW_COLOR_COEFFD_SHIFT     (20U)
/*! SW_COLOR_COEFFD - Coefficient d, used with Cb to calculate green component value */
#define VPU_G1_SWREG70_SW_COLOR_COEFFD(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG70_SW_COLOR_COEFFD_SHIFT)) & VPU_G1_SWREG70_SW_COLOR_COEFFD_MASK)

#define VPU_G1_SWREG70_SW_PP_OUT_H_EXT_MASK      (0xC0000000U)
#define VPU_G1_SWREG70_SW_PP_OUT_H_EXT_SHIFT     (30U)
/*! SW_PP_OUT_H_EXT - Extended output height for 4k resolution */
#define VPU_G1_SWREG70_SW_PP_OUT_H_EXT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG70_SW_PP_OUT_H_EXT_SHIFT)) & VPU_G1_SWREG70_SW_PP_OUT_H_EXT_MASK)
/*! @} */

/*! @name SWREG71 - Register for colour conversion 1 + rotation mode */
/*! @{ */

#define VPU_G1_SWREG71_SW_COLOR_COEFFE_MASK      (0x3FFU)
#define VPU_G1_SWREG71_SW_COLOR_COEFFE_SHIFT     (0U)
/*! SW_COLOR_COEFFE - Coefficient e, used with Cb to calculate blue component value */
#define VPU_G1_SWREG71_SW_COLOR_COEFFE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG71_SW_COLOR_COEFFE_SHIFT)) & VPU_G1_SWREG71_SW_COLOR_COEFFE_MASK)

#define VPU_G1_SWREG71_SW_COLOR_COEFFF_MASK      (0x3FC00U)
#define VPU_G1_SWREG71_SW_COLOR_COEFFF_SHIFT     (10U)
/*! SW_COLOR_COEFFF - Coefficient f, used with Y to adjust brightness */
#define VPU_G1_SWREG71_SW_COLOR_COEFFF(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG71_SW_COLOR_COEFFF_SHIFT)) & VPU_G1_SWREG71_SW_COLOR_COEFFF_MASK)

#define VPU_G1_SWREG71_SW_ROTATION_MODE_MASK     (0x1C0000U)
#define VPU_G1_SWREG71_SW_ROTATION_MODE_SHIFT    (18U)
/*! SW_ROTATION_MODE - Rotation mode:
 *  0b000..rotation disabled
 *  0b001..rotate + 90
 *  0b010..rotate - 90
 *  0b011..horizontal flip (mirror)
 *  0b100..vertical flip
 *  0b101..rotate 180
 */
#define VPU_G1_SWREG71_SW_ROTATION_MODE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG71_SW_ROTATION_MODE_SHIFT)) & VPU_G1_SWREG71_SW_ROTATION_MODE_MASK)

#define VPU_G1_SWREG71_SW_CROP_STARTX_MASK       (0x3FE00000U)
#define VPU_G1_SWREG71_SW_CROP_STARTX_SHIFT      (21U)
/*! SW_CROP_STARTX - Start coordinate x for the cropped area in macroblocks. */
#define VPU_G1_SWREG71_SW_CROP_STARTX(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG71_SW_CROP_STARTX_SHIFT)) & VPU_G1_SWREG71_SW_CROP_STARTX_MASK)

#define VPU_G1_SWREG71_SW_PP_OUT_W_EXT_MASK      (0xC0000000U)
#define VPU_G1_SWREG71_SW_PP_OUT_W_EXT_SHIFT     (30U)
/*! SW_PP_OUT_W_EXT - Extended output width for 4k resolution */
#define VPU_G1_SWREG71_SW_PP_OUT_W_EXT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG71_SW_PP_OUT_W_EXT_SHIFT)) & VPU_G1_SWREG71_SW_PP_OUT_W_EXT_MASK)
/*! @} */

/*! @name SWREG72 - PP input size and -cropping register */
/*! @{ */

#define VPU_G1_SWREG72_SW_PP_IN_WIDTH_MASK       (0x1FFU)
#define VPU_G1_SWREG72_SW_PP_IN_WIDTH_SHIFT      (0U)
/*! SW_PP_IN_WIDTH - PP input picture width in MBs. Can be cropped from a bigger input picture in external mode */
#define VPU_G1_SWREG72_SW_PP_IN_WIDTH(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG72_SW_PP_IN_WIDTH_SHIFT)) & VPU_G1_SWREG72_SW_PP_IN_WIDTH_MASK)

#define VPU_G1_SWREG72_SW_PP_IN_HEIGHT_MASK      (0x1FE00U)
#define VPU_G1_SWREG72_SW_PP_IN_HEIGHT_SHIFT     (9U)
/*! SW_PP_IN_HEIGHT - PP input picture height in MBs. Can be cropped from a bigger input picture in external mode */
#define VPU_G1_SWREG72_SW_PP_IN_HEIGHT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG72_SW_PP_IN_HEIGHT_SHIFT)) & VPU_G1_SWREG72_SW_PP_IN_HEIGHT_MASK)

#define VPU_G1_SWREG72_SW_RANGEMAP_COEF_Y_MASK   (0x7C0000U)
#define VPU_G1_SWREG72_SW_RANGEMAP_COEF_Y_SHIFT  (18U)
/*! SW_RANGEMAP_COEF_Y - Range map value for Y component */
#define VPU_G1_SWREG72_SW_RANGEMAP_COEF_Y(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG72_SW_RANGEMAP_COEF_Y_SHIFT)) & VPU_G1_SWREG72_SW_RANGEMAP_COEF_Y_MASK)

#define VPU_G1_SWREG72_SW_CROP_STARTY_MASK       (0xFF000000U)
#define VPU_G1_SWREG72_SW_CROP_STARTY_SHIFT      (24U)
/*! SW_CROP_STARTY - Start coordinate y for the cropped area in macroblocks. */
#define VPU_G1_SWREG72_SW_CROP_STARTY(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG72_SW_CROP_STARTY_SHIFT)) & VPU_G1_SWREG72_SW_CROP_STARTY_MASK)
/*! @} */

/*! @name SWREG73 - PP input picture base address for Y bottom field */
/*! @{ */

#define VPU_G1_SWREG73_SW_PP_BOT_YIN_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG73_SW_PP_BOT_YIN_BASE_SHIFT  (2U)
/*! SW_PP_BOT_YIN_BASE - PP input Y base for bottom field */
#define VPU_G1_SWREG73_SW_PP_BOT_YIN_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG73_SW_PP_BOT_YIN_BASE_SHIFT)) & VPU_G1_SWREG73_SW_PP_BOT_YIN_BASE_MASK)
/*! @} */

/*! @name SWREG74 - PP input picture base for Ch bottom field */
/*! @{ */

#define VPU_G1_SWREG74_SW_PP_BOT_CIN_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG74_SW_PP_BOT_CIN_BASE_SHIFT  (2U)
/*! SW_PP_BOT_CIN_BASE - PP input C base for bottom field (mixed chrominance) */
#define VPU_G1_SWREG74_SW_PP_BOT_CIN_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG74_SW_PP_BOT_CIN_BASE_SHIFT)) & VPU_G1_SWREG74_SW_PP_BOT_CIN_BASE_MASK)
/*! @} */

/*! @name SWREG79 - Scaling register 0 ratio and padding for R and G */
/*! @{ */

#define VPU_G1_SWREG79_SW_SCALE_WRATIO_MASK      (0x3FFFFU)
#define VPU_G1_SWREG79_SW_SCALE_WRATIO_SHIFT     (0U)
/*! SW_SCALE_WRATIO - Scaling ratio for width (outputw-1/inputw-1) */
#define VPU_G1_SWREG79_SW_SCALE_WRATIO(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_SCALE_WRATIO_SHIFT)) & VPU_G1_SWREG79_SW_SCALE_WRATIO_MASK)

#define VPU_G1_SWREG79_SW_RGB_G_PADD_MASK        (0x7C0000U)
#define VPU_G1_SWREG79_SW_RGB_G_PADD_SHIFT       (18U)
/*! SW_RGB_G_PADD - Amount of ones that will be padded in front of the G-component */
#define VPU_G1_SWREG79_SW_RGB_G_PADD(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_RGB_G_PADD_SHIFT)) & VPU_G1_SWREG79_SW_RGB_G_PADD_MASK)

#define VPU_G1_SWREG79_SW_RGB_R_PADD_MASK        (0xF800000U)
#define VPU_G1_SWREG79_SW_RGB_R_PADD_SHIFT       (23U)
/*! SW_RGB_R_PADD - Amount of ones that will be padded in front of the R-component */
#define VPU_G1_SWREG79_SW_RGB_R_PADD(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_RGB_R_PADD_SHIFT)) & VPU_G1_SWREG79_SW_RGB_R_PADD_MASK)

#define VPU_G1_SWREG79_SW_RGB_PIX_IN32_MASK      (0x10000000U)
#define VPU_G1_SWREG79_SW_RGB_PIX_IN32_SHIFT     (28U)
/*! SW_RGB_PIX_IN32 - RGB pixel amount/ 32 bit word
 *  0b0..1 RGB pixel/32 bit
 *  0b1..2 RGB pixels/32 bit
 */
#define VPU_G1_SWREG79_SW_RGB_PIX_IN32(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_RGB_PIX_IN32_SHIFT)) & VPU_G1_SWREG79_SW_RGB_PIX_IN32_MASK)

#define VPU_G1_SWREG79_SW_YCBCR_RANGE_MASK       (0x20000000U)
#define VPU_G1_SWREG79_SW_YCBCR_RANGE_SHIFT      (29U)
/*! SW_YCBCR_RANGE - Defines the YCbCr range in RGB conversion:
 *  0b0..16...235 for Y, 16...240 for Chrominance.
 *  0b1..0...255 for all components
 */
#define VPU_G1_SWREG79_SW_YCBCR_RANGE(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_YCBCR_RANGE_SHIFT)) & VPU_G1_SWREG79_SW_YCBCR_RANGE_MASK)

#define VPU_G1_SWREG79_SW_RANGEMAP_C_E_MASK      (0x40000000U)
#define VPU_G1_SWREG79_SW_RANGEMAP_C_E_SHIFT     (30U)
/*! SW_RANGEMAP_C_E - Range map enable for chrominance component */
#define VPU_G1_SWREG79_SW_RANGEMAP_C_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_RANGEMAP_C_E_SHIFT)) & VPU_G1_SWREG79_SW_RANGEMAP_C_E_MASK)

#define VPU_G1_SWREG79_SW_RANGEMAP_Y_E_MASK      (0x80000000U)
#define VPU_G1_SWREG79_SW_RANGEMAP_Y_E_SHIFT     (31U)
/*! SW_RANGEMAP_Y_E - Range map enable for Y component */
#define VPU_G1_SWREG79_SW_RANGEMAP_Y_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG79_SW_RANGEMAP_Y_E_SHIFT)) & VPU_G1_SWREG79_SW_RANGEMAP_Y_E_MASK)
/*! @} */

/*! @name SWREG80 - Scaling ratio register 1 and padding for B */
/*! @{ */

#define VPU_G1_SWREG80_SW_SCALE_HRATIO_MASK      (0x3FFFFU)
#define VPU_G1_SWREG80_SW_SCALE_HRATIO_SHIFT     (0U)
/*! SW_SCALE_HRATIO - Scaling ratio for height (outputh-1/inputh-1) */
#define VPU_G1_SWREG80_SW_SCALE_HRATIO(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_SCALE_HRATIO_SHIFT)) & VPU_G1_SWREG80_SW_SCALE_HRATIO_MASK)

#define VPU_G1_SWREG80_SW_RGB_B_PADD_MASK        (0x7C0000U)
#define VPU_G1_SWREG80_SW_RGB_B_PADD_SHIFT       (18U)
/*! SW_RGB_B_PADD - Amount of ones that will be padded in front of the B-component */
#define VPU_G1_SWREG80_SW_RGB_B_PADD(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_RGB_B_PADD_SHIFT)) & VPU_G1_SWREG80_SW_RGB_B_PADD_MASK)

#define VPU_G1_SWREG80_SW_VER_SCALE_MODE_MASK    (0x1800000U)
#define VPU_G1_SWREG80_SW_VER_SCALE_MODE_SHIFT   (23U)
/*! SW_VER_SCALE_MODE - Vertical scaling mode:
 *  0b00..Off
 *  0b01..Upscale
 *  0b10..Downscale
 */
#define VPU_G1_SWREG80_SW_VER_SCALE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_VER_SCALE_MODE_SHIFT)) & VPU_G1_SWREG80_SW_VER_SCALE_MODE_MASK)

#define VPU_G1_SWREG80_SW_HOR_SCALE_MODE_MASK    (0x6000000U)
#define VPU_G1_SWREG80_SW_HOR_SCALE_MODE_SHIFT   (25U)
/*! SW_HOR_SCALE_MODE - Horizontal scaling mode:
 *  0b00..Off
 *  0b01..Upscale
 *  0b10..Downscale
 */
#define VPU_G1_SWREG80_SW_HOR_SCALE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_HOR_SCALE_MODE_SHIFT)) & VPU_G1_SWREG80_SW_HOR_SCALE_MODE_MASK)

#define VPU_G1_SWREG80_SW_PP_IN_STRUCT_MASK      (0x38000000U)
#define VPU_G1_SWREG80_SW_PP_IN_STRUCT_SHIFT     (27U)
/*! SW_PP_IN_STRUCT - PP input data picture structure:
 *  0b000..Top field / progressive frame structure: Read input data from top field base address /frame base address and read every line.
 *  0b001..Bottom field structure: Read input data from bottom field base address and read every line.
 *  0b010..Interlaced field structure: Read input data from both top and bottom field base address and take every line from each field.
 *  0b011..Interlaced frame structure: Read input data from both top and bottom field base address and take every second line from each field.
 *  0b100..Ripped top field structure: Read input data from top field base address and read every second line.
 *  0b101..Ripped bottom field structure: Read input data from bottom field base address and read every second line.
 */
#define VPU_G1_SWREG80_SW_PP_IN_STRUCT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_PP_IN_STRUCT_SHIFT)) & VPU_G1_SWREG80_SW_PP_IN_STRUCT_MASK)

#define VPU_G1_SWREG80_SW_PP_FAST_SCALE_E_MASK   (0x40000000U)
#define VPU_G1_SWREG80_SW_PP_FAST_SCALE_E_SHIFT  (30U)
/*! SW_PP_FAST_SCALE_E
 *  0b0..fast downscaling is not enabled
 *  0b1..fast downscaling is enabled. The quality of the picture is decreased but performance is improved.
 */
#define VPU_G1_SWREG80_SW_PP_FAST_SCALE_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG80_SW_PP_FAST_SCALE_E_SHIFT)) & VPU_G1_SWREG80_SW_PP_FAST_SCALE_E_MASK)
/*! @} */

/*! @name SWREG81 - Scaling ratio register 2 */
/*! @{ */

#define VPU_G1_SWREG81_SW_HSCALE_INVRA_MASK      (0xFFFFU)
#define VPU_G1_SWREG81_SW_HSCALE_INVRA_SHIFT     (0U)
/*! SW_HSCALE_INVRA - Inverse scaling ratio for height or cv (inputh-1 / outputh-1) */
#define VPU_G1_SWREG81_SW_HSCALE_INVRA(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG81_SW_HSCALE_INVRA_SHIFT)) & VPU_G1_SWREG81_SW_HSCALE_INVRA_MASK)

#define VPU_G1_SWREG81_SW_WSCALE_INVRA_MASK      (0xFFFF0000U)
#define VPU_G1_SWREG81_SW_WSCALE_INVRA_SHIFT     (16U)
/*! SW_WSCALE_INVRA - Inverse scaling ratio for width, or ch (inputw-1 / outputw-1) */
#define VPU_G1_SWREG81_SW_WSCALE_INVRA(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG81_SW_WSCALE_INVRA_SHIFT)) & VPU_G1_SWREG81_SW_WSCALE_INVRA_MASK)
/*! @} */

/*! @name SWREG82 - Rmask register */
/*! @{ */

#define VPU_G1_SWREG82_SW_R_MASK_MASK            (0xFFFFFFFFU)
#define VPU_G1_SWREG82_SW_R_MASK_SHIFT           (0U)
/*! SW_R_MASK - Bit mask for R component (and alpha channel) */
#define VPU_G1_SWREG82_SW_R_MASK(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG82_SW_R_MASK_SHIFT)) & VPU_G1_SWREG82_SW_R_MASK_MASK)
/*! @} */

/*! @name SWREG83 - Gmask register */
/*! @{ */

#define VPU_G1_SWREG83_SW_G_MASK_MASK            (0xFFFFFFFFU)
#define VPU_G1_SWREG83_SW_G_MASK_SHIFT           (0U)
/*! SW_G_MASK - Bit mask for G component (and alpha channel) */
#define VPU_G1_SWREG83_SW_G_MASK(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG83_SW_G_MASK_SHIFT)) & VPU_G1_SWREG83_SW_G_MASK_MASK)
/*! @} */

/*! @name SWREG84 - Bmask register */
/*! @{ */

#define VPU_G1_SWREG84_SW_B_MASK_MASK            (0xFFFFFFFFU)
#define VPU_G1_SWREG84_SW_B_MASK_SHIFT           (0U)
/*! SW_B_MASK - Bit mask for B component (and alpha channel) */
#define VPU_G1_SWREG84_SW_B_MASK(x)              (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG84_SW_B_MASK_SHIFT)) & VPU_G1_SWREG84_SW_B_MASK_MASK)
/*! @} */

/*! @name SWREG85 - Post-processor control register */
/*! @{ */

#define VPU_G1_SWREG85_SW_PP_CROP8_D_E_MASK      (0x1U)
#define VPU_G1_SWREG85_SW_PP_CROP8_D_E_SHIFT     (0U)
/*! SW_PP_CROP8_D_E - PP input picture height is not 16 pixels multiple. Only 8 pixel rows of the
 *    most down MB of the unrotated input picture is used for PP input.
 */
#define VPU_G1_SWREG85_SW_PP_CROP8_D_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_CROP8_D_E_SHIFT)) & VPU_G1_SWREG85_SW_PP_CROP8_D_E_MASK)

#define VPU_G1_SWREG85_SW_PP_CROP8_R_E_MASK      (0x2U)
#define VPU_G1_SWREG85_SW_PP_CROP8_R_E_SHIFT     (1U)
/*! SW_PP_CROP8_R_E - PP input picture width is not 16 pixels multiple. Only 8 pixels of the most
 *    right MB of the unrotated input picture is used for PP input.
 */
#define VPU_G1_SWREG85_SW_PP_CROP8_R_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_CROP8_R_E_SHIFT)) & VPU_G1_SWREG85_SW_PP_CROP8_R_E_MASK)

#define VPU_G1_SWREG85_SW_PP_OUT_SWAP16_E_MASK   (0x4U)
#define VPU_G1_SWREG85_SW_PP_OUT_SWAP16_E_SHIFT  (2U)
/*! SW_PP_OUT_SWAP16_E - PP output swap 16, swaps 16 bit half inside of 32 bit word. Can be used for
 *    16 bit RGB to change pixel orders but is valid also for any output format. NOTE: requires
 *    that configuration of SW_PPD_OEN_VERSION=1
 */
#define VPU_G1_SWREG85_SW_PP_OUT_SWAP16_E(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_OUT_SWAP16_E_SHIFT)) & VPU_G1_SWREG85_SW_PP_OUT_SWAP16_E_MASK)

#define VPU_G1_SWREG85_SW_PP_OUT_TILED_E_MASK    (0x8U)
#define VPU_G1_SWREG85_SW_PP_OUT_TILED_E_SHIFT   (3U)
/*! SW_PP_OUT_TILED_E - Tiled mode enable for PP output. Can be used only for YCbYCr 422 output
 *    format. Can be used only if corresponding configuration supports this feature. Tile size is 4x4
 *    pixels.
 */
#define VPU_G1_SWREG85_SW_PP_OUT_TILED_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_OUT_TILED_E_SHIFT)) & VPU_G1_SWREG85_SW_PP_OUT_TILED_E_MASK)

#define VPU_G1_SWREG85_SW_PP_OUT_WIDTH_MASK      (0x7FF0U)
#define VPU_G1_SWREG85_SW_PP_OUT_WIDTH_SHIFT     (4U)
/*! SW_PP_OUT_WIDTH - Scaled picture width in pixels. Must be dividable by 8 or by any if Pixel
 *    Accurate PP output configuration is enabled. Max scaled picture width is 1920 pixels or maximum
 *    three times the input source width minus 8 pixels
 */
#define VPU_G1_SWREG85_SW_PP_OUT_WIDTH(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_OUT_WIDTH_SHIFT)) & VPU_G1_SWREG85_SW_PP_OUT_WIDTH_MASK)

#define VPU_G1_SWREG85_SW_PP_OUT_HEIGHT_MASK     (0x3FF8000U)
#define VPU_G1_SWREG85_SW_PP_OUT_HEIGHT_SHIFT    (15U)
/*! SW_PP_OUT_HEIGHT - Scaled picture height in pixels (Must be dividable by 2 or by any if Pixel
 *    Accurate PP output configuration is enabled) Max scaled picture height is 1920 pixels or maximum
 *    three times the input source height minus 8 pixels
 */
#define VPU_G1_SWREG85_SW_PP_OUT_HEIGHT(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_OUT_HEIGHT_SHIFT)) & VPU_G1_SWREG85_SW_PP_OUT_HEIGHT_MASK)

#define VPU_G1_SWREG85_SW_PP_OUT_FORMAT_MASK     (0x1C000000U)
#define VPU_G1_SWREG85_SW_PP_OUT_FORMAT_SHIFT    (26U)
/*! SW_PP_OUT_FORMAT - PP output picture data format:
 *  0b000..RGB
 *  0b001..YCbCr 4:2:0 planar (Not supported)
 *  0b010..YCbCr 4:2:2 planar (Not supported)
 *  0b011..YUYV 4:2:2 interleaved
 *  0b100..YCbCr 4:4:4 planar (Not supported)
 *  0b101..YCh 4:2:0 chrominance interleaved
 *  0b110..YCh 4:2:2 (Not supported)
 *  0b111..YCh 4:4:4 (Not supported)
 */
#define VPU_G1_SWREG85_SW_PP_OUT_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_OUT_FORMAT_SHIFT)) & VPU_G1_SWREG85_SW_PP_OUT_FORMAT_MASK)

#define VPU_G1_SWREG85_SW_PP_IN_FORMAT_MASK      (0xE0000000U)
#define VPU_G1_SWREG85_SW_PP_IN_FORMAT_SHIFT     (29U)
/*! SW_PP_IN_FORMAT - PP input picture data format
 *  0b000..YUYV 4:2:2 interleaved (supported only in external mode)
 *  0b001..YCbCr 4:2:0 Semi-planar in linear raster-scan format
 *  0b010..YCbCr 4:2:0 planar (supported only in external mode)
 *  0b011..YCbCr 4:0:0 (supported only in pipelined mode)
 *  0b100..YCbCr 4:2:2 Semi-planar (supported only in pipelined mode)
 *  0b101..YCbCr 4:2:0 Semi-planar in tiled format (supported only in external mode (8170 decoder only)
 *  0b110..Reserved
 *  0b111..Escape pp input data format. Defined in swreg86.
 */
#define VPU_G1_SWREG85_SW_PP_IN_FORMAT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG85_SW_PP_IN_FORMAT_SHIFT)) & VPU_G1_SWREG85_SW_PP_IN_FORMAT_MASK)
/*! @} */

/*! @name SWREG86 - Mask 1 start coordinate register */
/*! @{ */

#define VPU_G1_SWREG86_SW_MASK1_STARTX_MASK      (0x7FFU)
#define VPU_G1_SWREG86_SW_MASK1_STARTX_SHIFT     (0U)
/*! SW_MASK1_STARTX - Horizontal start pixel for mask area 1. Defines the x coordinate. Coordinate
 *    0,0 means the up-left corner in PP output luminance picture. See Table 47 for restrictions
 */
#define VPU_G1_SWREG86_SW_MASK1_STARTX(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG86_SW_MASK1_STARTX_SHIFT)) & VPU_G1_SWREG86_SW_MASK1_STARTX_MASK)

#define VPU_G1_SWREG86_SW_MASK1_STARTY_MASK      (0x3FF800U)
#define VPU_G1_SWREG86_SW_MASK1_STARTY_SHIFT     (11U)
/*! SW_MASK1_STARTY - Vertical start pixel for mask area 1. Defines the y coordinate. Coordinate 0,0
 *    means the up-left corner in PP output luminance picture. See Table 47 for restrictions
 */
#define VPU_G1_SWREG86_SW_MASK1_STARTY(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG86_SW_MASK1_STARTY_SHIFT)) & VPU_G1_SWREG86_SW_MASK1_STARTY_MASK)

#define VPU_G1_SWREG86_SW_MASK1_ABLEND_E_MASK    (0x400000U)
#define VPU_G1_SWREG86_SW_MASK1_ABLEND_E_SHIFT   (22U)
/*! SW_MASK1_ABLEND_E - Mask 1 alpha blending enable. Instead of masking the output picture the
 *    alpha blending is performed. Alpha blending source can be found from alpha blend 1 base address.
 *    Alpha blending can be enabled only for RGB/ YUYV 422 data.
 */
#define VPU_G1_SWREG86_SW_MASK1_ABLEND_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG86_SW_MASK1_ABLEND_E_SHIFT)) & VPU_G1_SWREG86_SW_MASK1_ABLEND_E_MASK)

#define VPU_G1_SWREG86_SW_RANGEMAP_COEF_C_MASK   (0xF800000U)
#define VPU_G1_SWREG86_SW_RANGEMAP_COEF_C_SHIFT  (23U)
/*! SW_RANGEMAP_COEF_C - Range map value for chrominance component */
#define VPU_G1_SWREG86_SW_RANGEMAP_COEF_C(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG86_SW_RANGEMAP_COEF_C_SHIFT)) & VPU_G1_SWREG86_SW_RANGEMAP_COEF_C_MASK)

#define VPU_G1_SWREG86_SW_PP_IN_FORMAT_ES_MASK   (0xE0000000U)
#define VPU_G1_SWREG86_SW_PP_IN_FORMAT_ES_SHIFT  (29U)
/*! SW_PP_IN_FORMAT_ES - Escape PP in format. Used if sw_pp_in_format is defined to 7.
 *  0b000..YCbCr 4:4:4
 *  0b001..YCbCr 4:1:1
 */
#define VPU_G1_SWREG86_SW_PP_IN_FORMAT_ES(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG86_SW_PP_IN_FORMAT_ES_SHIFT)) & VPU_G1_SWREG86_SW_PP_IN_FORMAT_ES_MASK)
/*! @} */

/*! @name SWREG87 - Mask 2 start coordinate register + Mask extensions */
/*! @{ */

#define VPU_G1_SWREG87_SW_MASK2_STARTX_MASK      (0x7FFU)
#define VPU_G1_SWREG87_SW_MASK2_STARTX_SHIFT     (0U)
/*! SW_MASK2_STARTX - Horizontal start pixel for mask area 2. Defines the x coordinate. Coordinate
 *    0,0 means the up-left corner in PP output Y picture. See Table 47 for restrictions
 */
#define VPU_G1_SWREG87_SW_MASK2_STARTX(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK2_STARTX_SHIFT)) & VPU_G1_SWREG87_SW_MASK2_STARTX_MASK)

#define VPU_G1_SWREG87_SW_MASK2_STARTY_MASK      (0x3FF800U)
#define VPU_G1_SWREG87_SW_MASK2_STARTY_SHIFT     (11U)
/*! SW_MASK2_STARTY - Vertical start pixel for mask area 2. Defines the y coordinate. Coordinate 0,0
 *    means the up-left corner in PP output Y picture. See Table 47 for restrictions
 */
#define VPU_G1_SWREG87_SW_MASK2_STARTY(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK2_STARTY_SHIFT)) & VPU_G1_SWREG87_SW_MASK2_STARTY_MASK)

#define VPU_G1_SWREG87_SW_MASK2_ABLEND_E_MASK    (0x400000U)
#define VPU_G1_SWREG87_SW_MASK2_ABLEND_E_SHIFT   (22U)
/*! SW_MASK2_ABLEND_E - Mask 2 alpha blending enable. Instead of masking the output picture the
 *    alpha blending is performed. Alpha blending source can be found from alpha blend 2 base address.
 *    Alpha blending can be enabled only for RGB/YUYV 422 data.
 */
#define VPU_G1_SWREG87_SW_MASK2_ABLEND_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK2_ABLEND_E_SHIFT)) & VPU_G1_SWREG87_SW_MASK2_ABLEND_E_MASK)

#define VPU_G1_SWREG87_SW_MASK2_STARTY_EXT_MASK  (0x1800000U)
#define VPU_G1_SWREG87_SW_MASK2_STARTY_EXT_SHIFT (23U)
/*! SW_MASK2_STARTY_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG87_SW_MASK2_STARTY_EXT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK2_STARTY_EXT_SHIFT)) & VPU_G1_SWREG87_SW_MASK2_STARTY_EXT_MASK)

#define VPU_G1_SWREG87_SW_MASK2_STARTX_EXT_MASK  (0x6000000U)
#define VPU_G1_SWREG87_SW_MASK2_STARTX_EXT_SHIFT (25U)
/*! SW_MASK2_STARTX_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG87_SW_MASK2_STARTX_EXT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK2_STARTX_EXT_SHIFT)) & VPU_G1_SWREG87_SW_MASK2_STARTX_EXT_MASK)

#define VPU_G1_SWREG87_SW_MASK1_STARTY_EXT_MASK  (0x18000000U)
#define VPU_G1_SWREG87_SW_MASK1_STARTY_EXT_SHIFT (27U)
/*! SW_MASK1_STARTY_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG87_SW_MASK1_STARTY_EXT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK1_STARTY_EXT_SHIFT)) & VPU_G1_SWREG87_SW_MASK1_STARTY_EXT_MASK)

#define VPU_G1_SWREG87_SW_MASK1_STARTX_EXT_MASK  (0x60000000U)
#define VPU_G1_SWREG87_SW_MASK1_STARTX_EXT_SHIFT (29U)
/*! SW_MASK1_STARTX_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG87_SW_MASK1_STARTX_EXT(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG87_SW_MASK1_STARTX_EXT_SHIFT)) & VPU_G1_SWREG87_SW_MASK1_STARTX_EXT_MASK)
/*! @} */

/*! @name SWREG88 - Mask 1 size and PP original width register */
/*! @{ */

#define VPU_G1_SWREG88_SW_MASK1_ENDX_MASK        (0x7FFU)
#define VPU_G1_SWREG88_SW_MASK1_ENDX_SHIFT       (0U)
/*! SW_MASK1_ENDX - Mask 1 end coordinate x in pixels (inside of PPD output picture). Range must be
 *    between [Mask1StartCoordinateX, ScaledWidth]
 */
#define VPU_G1_SWREG88_SW_MASK1_ENDX(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG88_SW_MASK1_ENDX_SHIFT)) & VPU_G1_SWREG88_SW_MASK1_ENDX_MASK)

#define VPU_G1_SWREG88_SW_MASK1_ENDY_MASK        (0x3FF800U)
#define VPU_G1_SWREG88_SW_MASK1_ENDY_SHIFT       (11U)
/*! SW_MASK1_ENDY - Mask 1 end coordinate y in pixels (inside of PPD output picture). Range must be
 *    between [Mask1StartCoordinateY, ScaledHeight].
 */
#define VPU_G1_SWREG88_SW_MASK1_ENDY(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG88_SW_MASK1_ENDY_SHIFT)) & VPU_G1_SWREG88_SW_MASK1_ENDY_MASK)

#define VPU_G1_SWREG88_SW_MASK1_E_MASK           (0x400000U)
#define VPU_G1_SWREG88_SW_MASK1_E_SHIFT          (22U)
/*! SW_MASK1_E - Mask 1 enable. If mask 1 is used this bit is high */
#define VPU_G1_SWREG88_SW_MASK1_E(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG88_SW_MASK1_E_SHIFT)) & VPU_G1_SWREG88_SW_MASK1_E_MASK)

#define VPU_G1_SWREG88_SW_EXT_ORIG_WIDTH_MASK    (0xFF800000U)
#define VPU_G1_SWREG88_SW_EXT_ORIG_WIDTH_SHIFT   (23U)
/*! SW_EXT_ORIG_WIDTH - PP input picture original width in macro blocks. */
#define VPU_G1_SWREG88_SW_EXT_ORIG_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG88_SW_EXT_ORIG_WIDTH_SHIFT)) & VPU_G1_SWREG88_SW_EXT_ORIG_WIDTH_MASK)
/*! @} */

/*! @name SWREG89 - Mask 2 size register + mask extensions */
/*! @{ */

#define VPU_G1_SWREG89_SW_MASK2_ENDX_MASK        (0x7FFU)
#define VPU_G1_SWREG89_SW_MASK2_ENDX_SHIFT       (0U)
/*! SW_MASK2_ENDX - Mask 2 end coordinate x in pixels (inside of PP output picture). Range must be
 *    between [Mask2StartCoordinateX, ScaledWidth].
 */
#define VPU_G1_SWREG89_SW_MASK2_ENDX(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK2_ENDX_SHIFT)) & VPU_G1_SWREG89_SW_MASK2_ENDX_MASK)

#define VPU_G1_SWREG89_SW_MASK2_ENDY_MASK        (0x3FF800U)
#define VPU_G1_SWREG89_SW_MASK2_ENDY_SHIFT       (11U)
/*! SW_MASK2_ENDY - Mask 2 end coordinate y in pixels (inside of PP output picture). Range must be
 *    between [Mask2StartCoordinateY, ScaledHeight].
 */
#define VPU_G1_SWREG89_SW_MASK2_ENDY(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK2_ENDY_SHIFT)) & VPU_G1_SWREG89_SW_MASK2_ENDY_MASK)

#define VPU_G1_SWREG89_SW_MASK2_E_MASK           (0x400000U)
#define VPU_G1_SWREG89_SW_MASK2_E_SHIFT          (22U)
/*! SW_MASK2_E - Mask 2 enable. If mask 1 is used this bit is high */
#define VPU_G1_SWREG89_SW_MASK2_E(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK2_E_SHIFT)) & VPU_G1_SWREG89_SW_MASK2_E_MASK)

#define VPU_G1_SWREG89_SW_MASK2_ENDY_EXT_MASK    (0x1800000U)
#define VPU_G1_SWREG89_SW_MASK2_ENDY_EXT_SHIFT   (23U)
/*! SW_MASK2_ENDY_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG89_SW_MASK2_ENDY_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK2_ENDY_EXT_SHIFT)) & VPU_G1_SWREG89_SW_MASK2_ENDY_EXT_MASK)

#define VPU_G1_SWREG89_SW_MASK2_ENDX_EXT_MASK    (0x6000000U)
#define VPU_G1_SWREG89_SW_MASK2_ENDX_EXT_SHIFT   (25U)
/*! SW_MASK2_ENDX_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG89_SW_MASK2_ENDX_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK2_ENDX_EXT_SHIFT)) & VPU_G1_SWREG89_SW_MASK2_ENDX_EXT_MASK)

#define VPU_G1_SWREG89_SW_MASK1_ENDY_EXT_MASK    (0x18000000U)
#define VPU_G1_SWREG89_SW_MASK1_ENDY_EXT_SHIFT   (27U)
/*! SW_MASK1_ENDY_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG89_SW_MASK1_ENDY_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK1_ENDY_EXT_SHIFT)) & VPU_G1_SWREG89_SW_MASK1_ENDY_EXT_MASK)

#define VPU_G1_SWREG89_SW_MASK1_ENDX_EXT_MASK    (0x60000000U)
#define VPU_G1_SWREG89_SW_MASK1_ENDX_EXT_SHIFT   (29U)
/*! SW_MASK1_ENDX_EXT - Extended coordinate upto 4k resolution */
#define VPU_G1_SWREG89_SW_MASK1_ENDX_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG89_SW_MASK1_ENDX_EXT_SHIFT)) & VPU_G1_SWREG89_SW_MASK1_ENDX_EXT_MASK)
/*! @} */

/*! @name SWREG90 - PiP register 0 */
/*! @{ */

#define VPU_G1_SWREG90_SW_DOWN_CROSS_MASK        (0x7FFU)
#define VPU_G1_SWREG90_SW_DOWN_CROSS_SHIFT       (0U)
/*! SW_DOWN_CROSS - Amount of downward overcross (vertical pixels outside of display from the down
 *    side). Range must be between [0, ScaledHeight].
 */
#define VPU_G1_SWREG90_SW_DOWN_CROSS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_DOWN_CROSS_SHIFT)) & VPU_G1_SWREG90_SW_DOWN_CROSS_MASK)

#define VPU_G1_SWREG90_SW_DOWN_CROSS_EXT_MASK    (0x1800U)
#define VPU_G1_SWREG90_SW_DOWN_CROSS_EXT_SHIFT   (11U)
/*! SW_DOWN_CROSS_EXT - Extended coordinate for 4k resolution */
#define VPU_G1_SWREG90_SW_DOWN_CROSS_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_DOWN_CROSS_EXT_SHIFT)) & VPU_G1_SWREG90_SW_DOWN_CROSS_EXT_MASK)

#define VPU_G1_SWREG90_SW_UP_CROSS_MASK          (0x3FF8000U)
#define VPU_G1_SWREG90_SW_UP_CROSS_SHIFT         (15U)
/*! SW_UP_CROSS - Amount of upward overcross (vertical pixels outside of display from the upper
 *    side). Range must be between [0, ScaledHeight].
 */
#define VPU_G1_SWREG90_SW_UP_CROSS(x)            (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_UP_CROSS_SHIFT)) & VPU_G1_SWREG90_SW_UP_CROSS_MASK)

#define VPU_G1_SWREG90_SW_DOWN_CROSS_E_MASK      (0x4000000U)
#define VPU_G1_SWREG90_SW_DOWN_CROSS_E_SHIFT     (26U)
/*! SW_DOWN_CROSS_E - Downward overcross enable.
 *  0b0..No downward overcross
 *  0b1..Downward overcross
 */
#define VPU_G1_SWREG90_SW_DOWN_CROSS_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_DOWN_CROSS_E_SHIFT)) & VPU_G1_SWREG90_SW_DOWN_CROSS_E_MASK)

#define VPU_G1_SWREG90_SW_UP_CROSS_E_MASK        (0x8000000U)
#define VPU_G1_SWREG90_SW_UP_CROSS_E_SHIFT       (27U)
/*! SW_UP_CROSS_E - Upward overcross enable.
 *  0b0..No upward overcross
 *  0b1..Upward overcross
 */
#define VPU_G1_SWREG90_SW_UP_CROSS_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_UP_CROSS_E_SHIFT)) & VPU_G1_SWREG90_SW_UP_CROSS_E_MASK)

#define VPU_G1_SWREG90_SW_LEFT_CROSS_E_MASK      (0x10000000U)
#define VPU_G1_SWREG90_SW_LEFT_CROSS_E_SHIFT     (28U)
/*! SW_LEFT_CROSS_E - Left side overcross enable.
 *  0b0..No left side overcross
 *  0b1..Left side overcross
 */
#define VPU_G1_SWREG90_SW_LEFT_CROSS_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_LEFT_CROSS_E_SHIFT)) & VPU_G1_SWREG90_SW_LEFT_CROSS_E_MASK)

#define VPU_G1_SWREG90_SW_RIGHT_CROSS_E_MASK     (0x20000000U)
#define VPU_G1_SWREG90_SW_RIGHT_CROSS_E_SHIFT    (29U)
/*! SW_RIGHT_CROSS_E - Right side overcross enable.
 *  0b0..No right side overcross
 *  0b1..Right side overcross
 */
#define VPU_G1_SWREG90_SW_RIGHT_CROSS_E(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG90_SW_RIGHT_CROSS_E_SHIFT)) & VPU_G1_SWREG90_SW_RIGHT_CROSS_E_MASK)
/*! @} */

/*! @name SWREG91 - PiP register 1 and dithering control */
/*! @{ */

#define VPU_G1_SWREG91_SW_LEFT_CROSS_MASK        (0x7FFU)
#define VPU_G1_SWREG91_SW_LEFT_CROSS_SHIFT       (0U)
/*! SW_LEFT_CROSS - Amount of left side overcross (Horizontal pixels outside of display from the
 *    left side). Range must be between [0, ScaledWidth].
 */
#define VPU_G1_SWREG91_SW_LEFT_CROSS(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_LEFT_CROSS_SHIFT)) & VPU_G1_SWREG91_SW_LEFT_CROSS_MASK)

#define VPU_G1_SWREG91_SW_RIGHT_CROSS_MASK       (0x3FF800U)
#define VPU_G1_SWREG91_SW_RIGHT_CROSS_SHIFT      (11U)
/*! SW_RIGHT_CROSS - Amount of right side overcross (Horizontal pixels outside of display from the
 *    right side). Range must be between [0, ScaledWidth].
 */
#define VPU_G1_SWREG91_SW_RIGHT_CROSS(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_RIGHT_CROSS_SHIFT)) & VPU_G1_SWREG91_SW_RIGHT_CROSS_MASK)

#define VPU_G1_SWREG91_SW_PP_TILED_MODE_MASK     (0xC00000U)
#define VPU_G1_SWREG91_SW_PP_TILED_MODE_SHIFT    (22U)
/*! SW_PP_TILED_MODE - Input data is in tiled mode (at the moment valid only for YCbCr 420 data, pipeline or external mode):
 *  0b00..Tiled mode not used
 *  0b01..Tiled mode enabled for 8x4 sized tiles
 */
#define VPU_G1_SWREG91_SW_PP_TILED_MODE(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_PP_TILED_MODE_SHIFT)) & VPU_G1_SWREG91_SW_PP_TILED_MODE_MASK)

#define VPU_G1_SWREG91_SW_DITHER_SELECT_B_MASK   (0xC000000U)
#define VPU_G1_SWREG91_SW_DITHER_SELECT_B_SHIFT  (26U)
/*! SW_DITHER_SELECT_B - Dithering control for B channel:
 *  0b00..dithering disabled
 *  0b01..use four-bit dither matrix
 *  0b10..use five-bit dither matrix
 *  0b11..use six-bit dither matrix
 */
#define VPU_G1_SWREG91_SW_DITHER_SELECT_B(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_DITHER_SELECT_B_SHIFT)) & VPU_G1_SWREG91_SW_DITHER_SELECT_B_MASK)

#define VPU_G1_SWREG91_SW_DITHER_SELECT_G_MASK   (0x30000000U)
#define VPU_G1_SWREG91_SW_DITHER_SELECT_G_SHIFT  (28U)
/*! SW_DITHER_SELECT_G - Dithering control for G channel:
 *  0b00..dithering disabled
 *  0b01..use four-bit dither matrix
 *  0b10..use five-bit dither matrix
 *  0b11..use six-bit dither matrix
 */
#define VPU_G1_SWREG91_SW_DITHER_SELECT_G(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_DITHER_SELECT_G_SHIFT)) & VPU_G1_SWREG91_SW_DITHER_SELECT_G_MASK)

#define VPU_G1_SWREG91_SW_DITHER_SELECT_R_MASK   (0xC0000000U)
#define VPU_G1_SWREG91_SW_DITHER_SELECT_R_SHIFT  (30U)
/*! SW_DITHER_SELECT_R - Dithering control for R channel:
 *  0b00..dithering disabled
 *  0b01..use four-bit dither matrix
 *  0b10..use five-bit dither matrix
 *  0b11..use six-bit dither matrix
 */
#define VPU_G1_SWREG91_SW_DITHER_SELECT_R(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG91_SW_DITHER_SELECT_R_SHIFT)) & VPU_G1_SWREG91_SW_DITHER_SELECT_R_MASK)
/*! @} */

/*! @name SWREG92 - Display width and PP input size extension register */
/*! @{ */

#define VPU_G1_SWREG92_SW_DISPLAY_WIDTH_MASK     (0x1FFFU)
#define VPU_G1_SWREG92_SW_DISPLAY_WIDTH_SHIFT    (0U)
/*! SW_DISPLAY_WIDTH - Width of the display in pixels. Max 4k (depends on HW config support) */
#define VPU_G1_SWREG92_SW_DISPLAY_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_DISPLAY_WIDTH_SHIFT)) & VPU_G1_SWREG92_SW_DISPLAY_WIDTH_MASK)

#define VPU_G1_SWREG92_SW_UP_CROSS_EXT_MASK      (0xC000U)
#define VPU_G1_SWREG92_SW_UP_CROSS_EXT_SHIFT     (14U)
/*! SW_UP_CROSS_EXT - Extended coordinate for 4k resolution */
#define VPU_G1_SWREG92_SW_UP_CROSS_EXT(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_UP_CROSS_EXT_SHIFT)) & VPU_G1_SWREG92_SW_UP_CROSS_EXT_MASK)

#define VPU_G1_SWREG92_SW_LEFT_CROSS_EXT_MASK    (0x30000U)
#define VPU_G1_SWREG92_SW_LEFT_CROSS_EXT_SHIFT   (16U)
/*! SW_LEFT_CROSS_EXT - Extended coordinate for 4k resolution */
#define VPU_G1_SWREG92_SW_LEFT_CROSS_EXT(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_LEFT_CROSS_EXT_SHIFT)) & VPU_G1_SWREG92_SW_LEFT_CROSS_EXT_MASK)

#define VPU_G1_SWREG92_SW_RIGHT_CROSS_EXT_MASK   (0xC0000U)
#define VPU_G1_SWREG92_SW_RIGHT_CROSS_EXT_SHIFT  (18U)
/*! SW_RIGHT_CROSS_EXT - Extended coordinate for 4k resolution */
#define VPU_G1_SWREG92_SW_RIGHT_CROSS_EXT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_RIGHT_CROSS_EXT_SHIFT)) & VPU_G1_SWREG92_SW_RIGHT_CROSS_EXT_MASK)

#define VPU_G1_SWREG92_SW_CROP_STARTX_EXT_MASK   (0x700000U)
#define VPU_G1_SWREG92_SW_CROP_STARTX_EXT_SHIFT  (20U)
/*! SW_CROP_STARTX_EXT - Extended PP input crop start coordinate y. Used with WEBP */
#define VPU_G1_SWREG92_SW_CROP_STARTX_EXT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_CROP_STARTX_EXT_SHIFT)) & VPU_G1_SWREG92_SW_CROP_STARTX_EXT_MASK)

#define VPU_G1_SWREG92_SW_CROP_STARTY_EXT_MASK   (0x3800000U)
#define VPU_G1_SWREG92_SW_CROP_STARTY_EXT_SHIFT  (23U)
/*! SW_CROP_STARTY_EXT - Extended PP input crop start coordinate x. Used with WEBP */
#define VPU_G1_SWREG92_SW_CROP_STARTY_EXT(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_CROP_STARTY_EXT_SHIFT)) & VPU_G1_SWREG92_SW_CROP_STARTY_EXT_MASK)

#define VPU_G1_SWREG92_SW_PP_IN_W_EXT_MASK       (0x1C000000U)
#define VPU_G1_SWREG92_SW_PP_IN_W_EXT_SHIFT      (26U)
/*! SW_PP_IN_W_EXT - Extended PP input width. Used with WEBP */
#define VPU_G1_SWREG92_SW_PP_IN_W_EXT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_PP_IN_W_EXT_SHIFT)) & VPU_G1_SWREG92_SW_PP_IN_W_EXT_MASK)

#define VPU_G1_SWREG92_SW_PP_IN_H_EXT_MASK       (0xE0000000U)
#define VPU_G1_SWREG92_SW_PP_IN_H_EXT_SHIFT      (29U)
/*! SW_PP_IN_H_EXT - Extended PP input height. Used with WEBP */
#define VPU_G1_SWREG92_SW_PP_IN_H_EXT(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG92_SW_PP_IN_H_EXT_SHIFT)) & VPU_G1_SWREG92_SW_PP_IN_H_EXT_MASK)
/*! @} */

/*! @name SWREG93 - Base address for alpha blend 1 gui component */
/*! @{ */

#define VPU_G1_SWREG93_SW_ABLEND1_BASE_MASK      (0xFFFFFFFFU)
#define VPU_G1_SWREG93_SW_ABLEND1_BASE_SHIFT     (0U)
/*! SW_ABLEND1_BASE - Base address for alpha blending input 1 (if mask1 is used in alpha blending
 *    mode). Format of data is 24 bit RGB/ YCbCr and endian/swap -mode is as in PP input. Amount of
 *    data is informed with mask 1 size or with ablend1_scanline if ablend cropping is supported in
 *    configuration.
 */
#define VPU_G1_SWREG93_SW_ABLEND1_BASE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG93_SW_ABLEND1_BASE_SHIFT)) & VPU_G1_SWREG93_SW_ABLEND1_BASE_MASK)
/*! @} */

/*! @name SWREG94 - Base address for alpha blend 2 gui component */
/*! @{ */

#define VPU_G1_SWREG94_SW_ABLEND2_BASE_MASK      (0xFFFFFFFFU)
#define VPU_G1_SWREG94_SW_ABLEND2_BASE_SHIFT     (0U)
/*! SW_ABLEND2_BASE - Base address for alpha blending input 2 (if mask2 is used in alpha blending
 *    mode). Format of data is 24 bit RGB/ YCbCr and endian/swap -mode is as in PP input. Amount of
 *    data is informed with mask 2 size or with ablend2_scanline if ablend cropping is supported in
 *    configuration.
 */
#define VPU_G1_SWREG94_SW_ABLEND2_BASE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG94_SW_ABLEND2_BASE_SHIFT)) & VPU_G1_SWREG94_SW_ABLEND2_BASE_MASK)
/*! @} */

/*! @name SWREG95 - Alpha blend input cropping register (scanline for cropping) */
/*! @{ */

#define VPU_G1_SWREG95_SW_ABLEND1_SCANL_MASK     (0x1FFFU)
#define VPU_G1_SWREG95_SW_ABLEND1_SCANL_SHIFT    (0U)
/*! SW_ABLEND1_SCANL - Scanline width in pixels for Ablend 1. Usage enabled if corresponding configuration bit is enabled */
#define VPU_G1_SWREG95_SW_ABLEND1_SCANL(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG95_SW_ABLEND1_SCANL_SHIFT)) & VPU_G1_SWREG95_SW_ABLEND1_SCANL_MASK)

#define VPU_G1_SWREG95_SW_ABLEND2_SCANL_MASK     (0x3FFE000U)
#define VPU_G1_SWREG95_SW_ABLEND2_SCANL_SHIFT    (13U)
/*! SW_ABLEND2_SCANL - Scanline width in pixels for Ablend 2. Usage enabled if corresponding configuration bit is enabled */
#define VPU_G1_SWREG95_SW_ABLEND2_SCANL(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG95_SW_ABLEND2_SCANL_SHIFT)) & VPU_G1_SWREG95_SW_ABLEND2_SCANL_MASK)
/*! @} */

/*! @name SWREG99 - PP fuse register */
/*! @{ */

#define VPU_G1_SWREG99_FUSE_PP_MAXW_352_MASK     (0x1000U)
#define VPU_G1_SWREG99_FUSE_PP_MAXW_352_SHIFT    (12U)
/*! FUSE_PP_MAXW_352 - 1 = Max PP output width up to 352 pixels enabled. Priority coded with priority 5 */
#define VPU_G1_SWREG99_FUSE_PP_MAXW_352(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_MAXW_352_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_MAXW_352_MASK)

#define VPU_G1_SWREG99_FUSE_PP_MAXW_720_MASK     (0x2000U)
#define VPU_G1_SWREG99_FUSE_PP_MAXW_720_SHIFT    (13U)
/*! FUSE_PP_MAXW_720 - 1 = Max PP output width up to 720 pixels enabled. Priority coded with priority 4 */
#define VPU_G1_SWREG99_FUSE_PP_MAXW_720(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_MAXW_720_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_MAXW_720_MASK)

#define VPU_G1_SWREG99_FUSE_PP_MAXW_1280_MASK    (0x4000U)
#define VPU_G1_SWREG99_FUSE_PP_MAXW_1280_SHIFT   (14U)
/*! FUSE_PP_MAXW_1280 - 1 = Max PP output width up to 1280 pixels enabled. Priority coded with priority 3 */
#define VPU_G1_SWREG99_FUSE_PP_MAXW_1280(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_MAXW_1280_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_MAXW_1280_MASK)

#define VPU_G1_SWREG99_FUSE_PP_MAXW_1920_MASK    (0x8000U)
#define VPU_G1_SWREG99_FUSE_PP_MAXW_1920_SHIFT   (15U)
/*! FUSE_PP_MAXW_1920 - 1 = Max PP output width up to 1920 pixels enabled. Priority coded with priority 2 */
#define VPU_G1_SWREG99_FUSE_PP_MAXW_1920(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_MAXW_1920_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_MAXW_1920_MASK)

#define VPU_G1_SWREG99_FUSE_PP_MAXW_4K_MASK      (0x10000U)
#define VPU_G1_SWREG99_FUSE_PP_MAXW_4K_SHIFT     (16U)
/*! FUSE_PP_MAXW_4K - 1 = Max PP output width up to 4096 pixels enabled. Priority coded with priority 1 */
#define VPU_G1_SWREG99_FUSE_PP_MAXW_4K(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_MAXW_4K_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_MAXW_4K_MASK)

#define VPU_G1_SWREG99_FUSE_PP_ABLEND_MASK       (0x20000000U)
#define VPU_G1_SWREG99_FUSE_PP_ABLEND_SHIFT      (29U)
/*! FUSE_PP_ABLEND - 1 = Alpha Blending enabled */
#define VPU_G1_SWREG99_FUSE_PP_ABLEND(x)         (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_ABLEND_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_ABLEND_MASK)

#define VPU_G1_SWREG99_FUSE_PP_DEINT_MASK        (0x40000000U)
#define VPU_G1_SWREG99_FUSE_PP_DEINT_SHIFT       (30U)
/*! FUSE_PP_DEINT - 1 = Deinterlacing enabled */
#define VPU_G1_SWREG99_FUSE_PP_DEINT(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_DEINT_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_DEINT_MASK)

#define VPU_G1_SWREG99_FUSE_PP_PP_MASK           (0x80000000U)
#define VPU_G1_SWREG99_FUSE_PP_PP_SHIFT          (31U)
/*! FUSE_PP_PP - 1 = PP enabled */
#define VPU_G1_SWREG99_FUSE_PP_PP(x)             (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG99_FUSE_PP_PP_SHIFT)) & VPU_G1_SWREG99_FUSE_PP_PP_MASK)
/*! @} */

/*! @name SWREG100 - Synthesis configuration register post-processor */
/*! @{ */

#define VPU_G1_SWREG100_SW_PPD_MAX_OWIDTH_MASK   (0x1FFFU)
#define VPU_G1_SWREG100_SW_PPD_MAX_OWIDTH_SHIFT  (0U)
/*! SW_PPD_MAX_OWIDTH - Max supported PP output width in pixels */
#define VPU_G1_SWREG100_SW_PPD_MAX_OWIDTH(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_MAX_OWIDTH_SHIFT)) & VPU_G1_SWREG100_SW_PPD_MAX_OWIDTH_MASK)

#define VPU_G1_SWREG100_SW_PPD_IN_TILED_L_MASK   (0xC000U)
#define VPU_G1_SWREG100_SW_PPD_IN_TILED_L_SHIFT  (14U)
/*! SW_PPD_IN_TILED_L - PPD input tiled mode support level
 *  0b00..not supported
 *  0b01..8x4 tile size supported
 */
#define VPU_G1_SWREG100_SW_PPD_IN_TILED_L(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_IN_TILED_L_SHIFT)) & VPU_G1_SWREG100_SW_PPD_IN_TILED_L_MASK)

#define VPU_G1_SWREG100_SW_PPD_PP_EXIST_MASK     (0x10000U)
#define VPU_G1_SWREG100_SW_PPD_PP_EXIST_SHIFT    (16U)
/*! SW_PPD_PP_EXIST - PPD exists:
 *  0b0..No
 *  0b1..Yes
 */
#define VPU_G1_SWREG100_SW_PPD_PP_EXIST(x)       (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_PP_EXIST_SHIFT)) & VPU_G1_SWREG100_SW_PPD_PP_EXIST_MASK)

#define VPU_G1_SWREG100_SW_PPD_OBUFF_LEVEL_MASK  (0x20000U)
#define VPU_G1_SWREG100_SW_PPD_OBUFF_LEVEL_SHIFT (17U)
/*! SW_PPD_OBUFF_LEVEL - PP output buffering level:
 *  0b0..1 unit output buffering is used
 *  0b1..4 unit output buffering is used
 */
#define VPU_G1_SWREG100_SW_PPD_OBUFF_LEVEL(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_OBUFF_LEVEL_SHIFT)) & VPU_G1_SWREG100_SW_PPD_OBUFF_LEVEL_MASK)

#define VPU_G1_SWREG100_SW_PPD_OEN_VERSION_MASK  (0x40000U)
#define VPU_G1_SWREG100_SW_PPD_OEN_VERSION_SHIFT (18U)
/*! SW_PPD_OEN_VERSION - PP output endian version:
 *  0b0..Endian mode supported for other than RGB
 *  0b1..Endian mode supported for any output format
 */
#define VPU_G1_SWREG100_SW_PPD_OEN_VERSION(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_OEN_VERSION_SHIFT)) & VPU_G1_SWREG100_SW_PPD_OEN_VERSION_MASK)

#define VPU_G1_SWREG100_SW_PPD_IBUFF_LEVEL_MASK  (0x800000U)
#define VPU_G1_SWREG100_SW_PPD_IBUFF_LEVEL_SHIFT (23U)
/*! SW_PPD_IBUFF_LEVEL - PP input buffering level:
 *  0b0..1 MB input buffering is used
 *  0b1..4 MB input buffering is used
 */
#define VPU_G1_SWREG100_SW_PPD_IBUFF_LEVEL(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_IBUFF_LEVEL_SHIFT)) & VPU_G1_SWREG100_SW_PPD_IBUFF_LEVEL_MASK)

#define VPU_G1_SWREG100_SW_PPD_BLEND_EXIST_MASK  (0x1000000U)
#define VPU_G1_SWREG100_SW_PPD_BLEND_EXIST_SHIFT (24U)
/*! SW_PPD_BLEND_EXIST - Alpha blending exists:
 *  0b0..No
 *  0b1..Yes
 */
#define VPU_G1_SWREG100_SW_PPD_BLEND_EXIST(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_BLEND_EXIST_SHIFT)) & VPU_G1_SWREG100_SW_PPD_BLEND_EXIST_MASK)

#define VPU_G1_SWREG100_SW_PPD_DEINT_EXIST_MASK  (0x2000000U)
#define VPU_G1_SWREG100_SW_PPD_DEINT_EXIST_SHIFT (25U)
/*! SW_PPD_DEINT_EXIST - De-interlacing exits:
 *  0b0..No
 *  0b1..Yes
 */
#define VPU_G1_SWREG100_SW_PPD_DEINT_EXIST(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_DEINT_EXIST_SHIFT)) & VPU_G1_SWREG100_SW_PPD_DEINT_EXIST_MASK)

#define VPU_G1_SWREG100_SW_PPD_SCALE_LEVEL_MASK  (0xC000000U)
#define VPU_G1_SWREG100_SW_PPD_SCALE_LEVEL_SHIFT (26U)
/*! SW_PPD_SCALE_LEVEL - Scaling support:
 *  0b00..No scaling
 *  0b01..Scaling with lo performance architecture
 *  0b10..Scaling with high performance architecture
 *  0b11..Scaling with high performance architecture + fast downscaling enabled
 */
#define VPU_G1_SWREG100_SW_PPD_SCALE_LEVEL(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_SCALE_LEVEL_SHIFT)) & VPU_G1_SWREG100_SW_PPD_SCALE_LEVEL_MASK)

#define VPU_G1_SWREG100_SW_PPD_DITH_EXIST_MASK   (0x10000000U)
#define VPU_G1_SWREG100_SW_PPD_DITH_EXIST_SHIFT  (28U)
/*! SW_PPD_DITH_EXIST - Dithering exists:
 *  0b0..No
 *  0b1..Yes
 */
#define VPU_G1_SWREG100_SW_PPD_DITH_EXIST(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_DITH_EXIST_SHIFT)) & VPU_G1_SWREG100_SW_PPD_DITH_EXIST_MASK)

#define VPU_G1_SWREG100_SW_PPD_TILED_EXIST_MASK  (0x20000000U)
#define VPU_G1_SWREG100_SW_PPD_TILED_EXIST_SHIFT (29U)
/*! SW_PPD_TILED_EXIST - PP output YCbYCr 422 tiled support (4x4 pixel tiles)
 *  0b0..Not supported
 *  0b1..Supported
 */
#define VPU_G1_SWREG100_SW_PPD_TILED_EXIST(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_TILED_EXIST_SHIFT)) & VPU_G1_SWREG100_SW_PPD_TILED_EXIST_MASK)

#define VPU_G1_SWREG100_SW_PPD_PIXAC_E_MASK      (0x40000000U)
#define VPU_G1_SWREG100_SW_PPD_PIXAC_E_SHIFT     (30U)
/*! SW_PPD_PIXAC_E - Pixel Accurate PP output mode exists:
 *  0b0..PIP, Scaling and masks can be adjusted by steps of 8 pixels (width) or 2 pixels (height)
 *  0b1..PIP, Scaling and masks can be adjusted by steps of 1 pixel for RGB and 2 pixels for subsampled chroma
 *       formats (by using bus specific write strobe functionality)
 */
#define VPU_G1_SWREG100_SW_PPD_PIXAC_E(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_PPD_PIXAC_E_SHIFT)) & VPU_G1_SWREG100_SW_PPD_PIXAC_E_MASK)

#define VPU_G1_SWREG100_SW_ABLEND_CROP_E_MASK    (0x80000000U)
#define VPU_G1_SWREG100_SW_ABLEND_CROP_E_SHIFT   (31U)
/*! SW_ABLEND_CROP_E - Alpha blending support for input cropping:
 *  0b0..Not supported. External memory must include the exact image of the area being alpha blended.
 *  0b1..Supported. External memory can include a picture from blended area can be cropped. Requires usage of swreg95.
 */
#define VPU_G1_SWREG100_SW_ABLEND_CROP_E(x)      (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG100_SW_ABLEND_CROP_E_SHIFT)) & VPU_G1_SWREG100_SW_ABLEND_CROP_E_MASK)
/*! @} */

/*! @name SWREG102 - Base address for H264 decoded chroma picture */
/*! @{ */

#define VPU_G1_SWREG102_SW_CH_BASE_E_MASK        (0x1U)
#define VPU_G1_SWREG102_SW_CH_BASE_E_SHIFT       (0U)
/*! SW_CH_BASE_E - chroma address separate mode enable:
 *  0b0..HW outputs decoded chroma picture to the end of decoded luma picture. HW calculates the chroma picture
 *       address according to sw_dec_base and luma data length.
 *  0b1..HW outputs decoded chroma picture to independent memory address
 */
#define VPU_G1_SWREG102_SW_CH_BASE_E(x)          (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG102_SW_CH_BASE_E_SHIFT)) & VPU_G1_SWREG102_SW_CH_BASE_E_MASK)

#define VPU_G1_SWREG102_SW_DEC_CH_BASE_MASK      (0xFFFFFFFCU)
#define VPU_G1_SWREG102_SW_DEC_CH_BASE_SHIFT     (2U)
/*! SW_DEC_CH_BASE - Valid only if chroma address separate mode is enabled. H264: Base address for
 *    decoder output chroma picture. Points directly to start of decoder output chroma picture or
 *    field.
 */
#define VPU_G1_SWREG102_SW_DEC_CH_BASE(x)        (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG102_SW_DEC_CH_BASE_SHIFT)) & VPU_G1_SWREG102_SW_DEC_CH_BASE_MASK)
/*! @} */

/*! @name SWREG103 - Base address for reference chroma picture index 0 */
/*! @{ */

#define VPU_G1_SWREG103_SW_REFER0_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG103_SW_REFER0_CH_BASE_SHIFT  (2U)
/*! SW_REFER0_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 0. */
#define VPU_G1_SWREG103_SW_REFER0_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG103_SW_REFER0_CH_BASE_SHIFT)) & VPU_G1_SWREG103_SW_REFER0_CH_BASE_MASK)
/*! @} */

/*! @name SWREG104 - Base address for reference chroma picture index 1 */
/*! @{ */

#define VPU_G1_SWREG104_SW_REFER1_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG104_SW_REFER1_CH_BASE_SHIFT  (2U)
/*! SW_REFER1_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 1. */
#define VPU_G1_SWREG104_SW_REFER1_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG104_SW_REFER1_CH_BASE_SHIFT)) & VPU_G1_SWREG104_SW_REFER1_CH_BASE_MASK)
/*! @} */

/*! @name SWREG105 - Base address for reference chroma picture index 2 */
/*! @{ */

#define VPU_G1_SWREG105_SW_REFER2_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG105_SW_REFER2_CH_BASE_SHIFT  (2U)
/*! SW_REFER2_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 2. */
#define VPU_G1_SWREG105_SW_REFER2_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG105_SW_REFER2_CH_BASE_SHIFT)) & VPU_G1_SWREG105_SW_REFER2_CH_BASE_MASK)
/*! @} */

/*! @name SWREG106 - Base address for reference chroma picture index 3 */
/*! @{ */

#define VPU_G1_SWREG106_SW_REFER3_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG106_SW_REFER3_CH_BASE_SHIFT  (2U)
/*! SW_REFER3_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 3. */
#define VPU_G1_SWREG106_SW_REFER3_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG106_SW_REFER3_CH_BASE_SHIFT)) & VPU_G1_SWREG106_SW_REFER3_CH_BASE_MASK)
/*! @} */

/*! @name SWREG107 - Base address for reference chroma picture index 4 */
/*! @{ */

#define VPU_G1_SWREG107_SW_REFER4_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG107_SW_REFER4_CH_BASE_SHIFT  (2U)
/*! SW_REFER4_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 4. */
#define VPU_G1_SWREG107_SW_REFER4_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG107_SW_REFER4_CH_BASE_SHIFT)) & VPU_G1_SWREG107_SW_REFER4_CH_BASE_MASK)
/*! @} */

/*! @name SWREG108 - Base address for reference chroma picture index 5 */
/*! @{ */

#define VPU_G1_SWREG108_SW_REFER5_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG108_SW_REFER5_CH_BASE_SHIFT  (2U)
/*! SW_REFER5_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 5. */
#define VPU_G1_SWREG108_SW_REFER5_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG108_SW_REFER5_CH_BASE_SHIFT)) & VPU_G1_SWREG108_SW_REFER5_CH_BASE_MASK)
/*! @} */

/*! @name SWREG109 - Base address for reference chroma picture index 6 */
/*! @{ */

#define VPU_G1_SWREG109_SW_REFER6_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG109_SW_REFER6_CH_BASE_SHIFT  (2U)
/*! SW_REFER6_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 6. */
#define VPU_G1_SWREG109_SW_REFER6_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG109_SW_REFER6_CH_BASE_SHIFT)) & VPU_G1_SWREG109_SW_REFER6_CH_BASE_MASK)
/*! @} */

/*! @name SWREG110 - Base address for reference chroma picture index 7 */
/*! @{ */

#define VPU_G1_SWREG110_SW_REFER7_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG110_SW_REFER7_CH_BASE_SHIFT  (2U)
/*! SW_REFER7_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 7. */
#define VPU_G1_SWREG110_SW_REFER7_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG110_SW_REFER7_CH_BASE_SHIFT)) & VPU_G1_SWREG110_SW_REFER7_CH_BASE_MASK)
/*! @} */

/*! @name SWREG111 - Base address for reference chroma picture index 8 */
/*! @{ */

#define VPU_G1_SWREG111_SW_REFER8_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG111_SW_REFER8_CH_BASE_SHIFT  (2U)
/*! SW_REFER8_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 8. */
#define VPU_G1_SWREG111_SW_REFER8_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG111_SW_REFER8_CH_BASE_SHIFT)) & VPU_G1_SWREG111_SW_REFER8_CH_BASE_MASK)
/*! @} */

/*! @name SWREG112 - Base address for reference chroma picture index 9 */
/*! @{ */

#define VPU_G1_SWREG112_SW_REFER9_CH_BASE_MASK   (0xFFFFFFFCU)
#define VPU_G1_SWREG112_SW_REFER9_CH_BASE_SHIFT  (2U)
/*! SW_REFER9_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 9. */
#define VPU_G1_SWREG112_SW_REFER9_CH_BASE(x)     (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG112_SW_REFER9_CH_BASE_SHIFT)) & VPU_G1_SWREG112_SW_REFER9_CH_BASE_MASK)
/*! @} */

/*! @name SWREG113 - Base address for reference chroma picture index 10 */
/*! @{ */

#define VPU_G1_SWREG113_SW_REFER10_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG113_SW_REFER10_CH_BASE_SHIFT (2U)
/*! SW_REFER10_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 10. */
#define VPU_G1_SWREG113_SW_REFER10_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG113_SW_REFER10_CH_BASE_SHIFT)) & VPU_G1_SWREG113_SW_REFER10_CH_BASE_MASK)
/*! @} */

/*! @name SWREG114 - Base address for reference chroma picture index 11 */
/*! @{ */

#define VPU_G1_SWREG114_SW_REFER11_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG114_SW_REFER11_CH_BASE_SHIFT (2U)
/*! SW_REFER11_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 11. */
#define VPU_G1_SWREG114_SW_REFER11_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG114_SW_REFER11_CH_BASE_SHIFT)) & VPU_G1_SWREG114_SW_REFER11_CH_BASE_MASK)
/*! @} */

/*! @name SWREG115 - Base address for reference chroma picture index 12 */
/*! @{ */

#define VPU_G1_SWREG115_SW_REFER12_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG115_SW_REFER12_CH_BASE_SHIFT (2U)
/*! SW_REFER12_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 12. */
#define VPU_G1_SWREG115_SW_REFER12_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG115_SW_REFER12_CH_BASE_SHIFT)) & VPU_G1_SWREG115_SW_REFER12_CH_BASE_MASK)
/*! @} */

/*! @name SWREG116 - Base address for reference chroma picture index 13 */
/*! @{ */

#define VPU_G1_SWREG116_SW_REFER13_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG116_SW_REFER13_CH_BASE_SHIFT (2U)
/*! SW_REFER13_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 13. */
#define VPU_G1_SWREG116_SW_REFER13_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG116_SW_REFER13_CH_BASE_SHIFT)) & VPU_G1_SWREG116_SW_REFER13_CH_BASE_MASK)
/*! @} */

/*! @name SWREG117 - Base address for reference chroma picture index 14 */
/*! @{ */

#define VPU_G1_SWREG117_SW_REFER14_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG117_SW_REFER14_CH_BASE_SHIFT (2U)
/*! SW_REFER14_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 14. */
#define VPU_G1_SWREG117_SW_REFER14_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG117_SW_REFER14_CH_BASE_SHIFT)) & VPU_G1_SWREG117_SW_REFER14_CH_BASE_MASK)
/*! @} */

/*! @name SWREG118 - Base address for reference chroma picture index 15 */
/*! @{ */

#define VPU_G1_SWREG118_SW_REFER15_CH_BASE_MASK  (0xFFFFFFFCU)
#define VPU_G1_SWREG118_SW_REFER15_CH_BASE_SHIFT (2U)
/*! SW_REFER15_CH_BASE - Valid only if chroma address separate mode is enabled. Base address for reference chroma picture index 15. */
#define VPU_G1_SWREG118_SW_REFER15_CH_BASE(x)    (((uint32_t)(((uint32_t)(x)) << VPU_G1_SWREG118_SW_REFER15_CH_BASE_SHIFT)) & VPU_G1_SWREG118_SW_REFER15_CH_BASE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VPU_G1_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_G1_Peripheral_Access_Layer */


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


#endif  /* PERI_VPU_G1_H_ */

