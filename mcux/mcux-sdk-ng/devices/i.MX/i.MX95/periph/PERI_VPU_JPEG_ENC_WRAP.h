/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for VPU_JPEG_ENC_WRAP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file VPU_JPEG_ENC_WRAP.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for VPU_JPEG_ENC_WRAP
 *
 * CMSIS Peripheral Access Layer for VPU_JPEG_ENC_WRAP
 */

#if !defined(VPU_JPEG_ENC_WRAP_H_)
#define VPU_JPEG_ENC_WRAP_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
   -- VPU_JPEG_ENC_WRAP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_JPEG_ENC_WRAP_Peripheral_Access_Layer VPU_JPEG_ENC_WRAP Peripheral Access Layer
 * @{
 */

/** VPU_JPEG_ENC_WRAP - Size of Registers Arrays */
#define VPU_JPEG_ENC_WRAP_BIT_STREAM_COUNT        4u

/** VPU_JPEG_ENC_WRAP - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_CTRL;                          /**< Global Control, offset: 0x0 */
  __I  uint32_t COM_STATUS;                        /**< Common Status, offset: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t IN_BUF_BASE0;                      /**< Input Image Frame Buffer 0 Base Address, offset: 0x14 */
  __IO uint32_t IN_BUF_BASE1;                      /**< Input Image Frame Buffer 1 Base Address, offset: 0x18 */
  __IO uint32_t IN_LINE_PITCH;                     /**< Input Image Frame Buffer Line Pitch, offset: 0x1C */
  __IO uint32_t STM_BUFBASE;                       /**< Output JPEG Stream Buffer Base Address, offset: 0x20 */
  __IO uint32_t STM_BUFSIZE;                       /**< Output JPEG Stream Buffer Size, offset: 0x24 */
  __IO uint32_t IMGSIZE;                           /**< Image Resolution, offset: 0x28 */
  __IO uint32_t STM_CTRL;                          /**< Bit Stream Switch and Control, offset: 0x2C */
       uint8_t RESERVED_1[65488];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_STATUS;                       /**< Bit Stream Slot Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_IRQ_EN;                       /**< Bit Stream Interrupt Enable, array offset: 0x10004, array step: 0x10000 */
    __I  uint32_t SLOT_BUF_PTR;                      /**< Bit Stream Buffer Pointer, array offset: 0x10008, array step: 0x10000 */
    __I  uint32_t SLOT_CUR_DESCPT_PTR;               /**< Current Encoding Descriptor Pointer, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t SLOT_NXT_DESCPT_PTR;               /**< Next Encoding Descriptor Pointer, array offset: 0x10010, array step: 0x10000 */
         uint8_t RESERVED_0[65516];
  } BIT_STREAM[VPU_JPEG_ENC_WRAP_BIT_STREAM_COUNT];
} VPU_JPEG_ENC_WRAP_Type;

/* ----------------------------------------------------------------------------
   -- VPU_JPEG_ENC_WRAP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VPU_JPEG_ENC_WRAP_Register_Masks VPU_JPEG_ENC_WRAP Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_GLB_CTRL_JPG_ENC_EN_MASK (0x1U)
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_JPG_ENC_EN_SHIFT (0U)
/*! JPG_ENC_EN - JPEG Encoder and Wrapper Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_JPG_ENC_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_GLB_CTRL_JPG_ENC_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_GLB_CTRL_JPG_ENC_EN_MASK)

#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SFTRST_MASK   (0x2U)
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SFTRST_SHIFT  (1U)
/*! SFTRST - Engine Soft Reset
 *  0b0..No effect
 *  0b1..Soft reset
 */
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SFTRST(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_GLB_CTRL_SFTRST_SHIFT)) & VPU_JPEG_ENC_WRAP_GLB_CTRL_SFTRST_MASK)

#define VPU_JPEG_ENC_WRAP_GLB_CTRL_ENC_GO_MASK   (0x4U)
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_ENC_GO_SHIFT  (2U)
/*! ENC_GO - Start Encoding
 *  0b0..Do not start encoding
 *  0b1..Start encoding
 */
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_ENC_GO(x)     (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_GLB_CTRL_ENC_GO_SHIFT)) & VPU_JPEG_ENC_WRAP_GLB_CTRL_ENC_GO_MASK)

#define VPU_JPEG_ENC_WRAP_GLB_CTRL_L_ENDIAN_MASK (0x8U)
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_L_ENDIAN_SHIFT (3U)
/*! L_ENDIAN - Little Endian
 *  0b0..Enables the big-endian bit stream format
 *  0b1..Enables the little-endian bit stream format
 */
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_L_ENDIAN(x)   (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_GLB_CTRL_L_ENDIAN_SHIFT)) & VPU_JPEG_ENC_WRAP_GLB_CTRL_L_ENDIAN_MASK)

#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SLOT_EN_MASK  (0xF0U)
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SLOT_EN_SHIFT (4U)
/*! SLOT_EN - Slot Enable */
#define VPU_JPEG_ENC_WRAP_GLB_CTRL_SLOT_EN(x)    (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_GLB_CTRL_SLOT_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_GLB_CTRL_SLOT_EN_MASK)
/*! @} */

/*! @name COM_STATUS - Common Status */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_COM_STATUS_CUR_SLOT_MASK (0x60000000U)
#define VPU_JPEG_ENC_WRAP_COM_STATUS_CUR_SLOT_SHIFT (29U)
/*! CUR_SLOT - Current Slot */
#define VPU_JPEG_ENC_WRAP_COM_STATUS_CUR_SLOT(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_COM_STATUS_CUR_SLOT_SHIFT)) & VPU_JPEG_ENC_WRAP_COM_STATUS_CUR_SLOT_MASK)

#define VPU_JPEG_ENC_WRAP_COM_STATUS_ENC_ONGOING_MASK (0x80000000U)
#define VPU_JPEG_ENC_WRAP_COM_STATUS_ENC_ONGOING_SHIFT (31U)
/*! ENC_ONGOING - Encoding Ongoing */
#define VPU_JPEG_ENC_WRAP_COM_STATUS_ENC_ONGOING(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_COM_STATUS_ENC_ONGOING_SHIFT)) & VPU_JPEG_ENC_WRAP_COM_STATUS_ENC_ONGOING_MASK)
/*! @} */

/*! @name IN_BUF_BASE0 - Input Image Frame Buffer 0 Base Address */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE0_IN_BUF_BASE0_MASK (0xFFFFFFF0U)
#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE0_IN_BUF_BASE0_SHIFT (4U)
/*! IN_BUF_BASE0 - Frame Buffer 0 Base Address */
#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE0_IN_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_IN_BUF_BASE0_IN_BUF_BASE0_SHIFT)) & VPU_JPEG_ENC_WRAP_IN_BUF_BASE0_IN_BUF_BASE0_MASK)
/*! @} */

/*! @name IN_BUF_BASE1 - Input Image Frame Buffer 1 Base Address */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE1_IN_BUF_BASE1_MASK (0xFFFFFFF0U)
#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE1_IN_BUF_BASE1_SHIFT (4U)
/*! IN_BUF_BASE1 - Frame Buffer 1 Base Address */
#define VPU_JPEG_ENC_WRAP_IN_BUF_BASE1_IN_BUF_BASE1(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_IN_BUF_BASE1_IN_BUF_BASE1_SHIFT)) & VPU_JPEG_ENC_WRAP_IN_BUF_BASE1_IN_BUF_BASE1_MASK)
/*! @} */

/*! @name IN_LINE_PITCH - Input Image Frame Buffer Line Pitch */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_IN_LINE_PITCH_IN_LINE_PITCH_MASK (0xFFFFU)
#define VPU_JPEG_ENC_WRAP_IN_LINE_PITCH_IN_LINE_PITCH_SHIFT (0U)
/*! IN_LINE_PITCH - Input Image Line Pitches */
#define VPU_JPEG_ENC_WRAP_IN_LINE_PITCH_IN_LINE_PITCH(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_IN_LINE_PITCH_IN_LINE_PITCH_SHIFT)) & VPU_JPEG_ENC_WRAP_IN_LINE_PITCH_IN_LINE_PITCH_MASK)
/*! @} */

/*! @name STM_BUFBASE - Output JPEG Stream Buffer Base Address */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_STM_BUFBASE_STM_BUFBASE_MASK (0xFFFFFFF0U)
#define VPU_JPEG_ENC_WRAP_STM_BUFBASE_STM_BUFBASE_SHIFT (4U)
/*! STM_BUFBASE - Bit Stream Buffer Base Address */
#define VPU_JPEG_ENC_WRAP_STM_BUFBASE_STM_BUFBASE(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_BUFBASE_STM_BUFBASE_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_BUFBASE_STM_BUFBASE_MASK)
/*! @} */

/*! @name STM_BUFSIZE - Output JPEG Stream Buffer Size */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_STM_BUFSIZE_STM_BUFSIZE_MASK (0xFFFFFC00U)
#define VPU_JPEG_ENC_WRAP_STM_BUFSIZE_STM_BUFSIZE_SHIFT (10U)
/*! STM_BUFSIZE - Bit Stream Buffer Size */
#define VPU_JPEG_ENC_WRAP_STM_BUFSIZE_STM_BUFSIZE(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_BUFSIZE_STM_BUFSIZE_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_BUFSIZE_STM_BUFSIZE_MASK)
/*! @} */

/*! @name IMGSIZE - Image Resolution */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_HEIGHT_MASK (0x3FFFU)
#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_HEIGHT_SHIFT (0U)
/*! IMG_HEIGHT - Image Height */
#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_HEIGHT(x)  (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_HEIGHT_SHIFT)) & VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_HEIGHT_MASK)

#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_WIDTH_MASK (0x3FFF0000U)
#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_WIDTH_SHIFT (16U)
/*! IMG_WIDTH - Image Width */
#define VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_WIDTH_SHIFT)) & VPU_JPEG_ENC_WRAP_IMGSIZE_IMG_WIDTH_MASK)
/*! @} */

/*! @name STM_CTRL - Bit Stream Switch and Control */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_STM_CTRL_PIXEL_PRECISION_MASK (0x4U)
#define VPU_JPEG_ENC_WRAP_STM_CTRL_PIXEL_PRECISION_SHIFT (2U)
/*! PIXEL_PRECISION - Pixel Precision
 *  0b0..8-bit
 *  0b1..12-bit
 */
#define VPU_JPEG_ENC_WRAP_STM_CTRL_PIXEL_PRECISION(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_CTRL_PIXEL_PRECISION_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_CTRL_PIXEL_PRECISION_MASK)

#define VPU_JPEG_ENC_WRAP_STM_CTRL_IMAGE_FORMAT_MASK (0x78U)
#define VPU_JPEG_ENC_WRAP_STM_CTRL_IMAGE_FORMAT_SHIFT (3U)
/*! IMAGE_FORMAT - Image Format
 *  0b0000..YUV420 (2-planar, Y at the first planar and UV at the second planar)
 *  0b0001..YUV422 (1-planar in the YUYV sequence)
 *  0b0010..RGB (RGBRGB packed format)
 *  0b0011..YUV444 (1-planar in the YUVYUV sequence)
 *  0b0100..Gray (Y8 or Y12) or single component
 *  0b0101..Reserved for future use
 *  0b0110..ARGB (ARGBARGB packed format)
 */
#define VPU_JPEG_ENC_WRAP_STM_CTRL_IMAGE_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_CTRL_IMAGE_FORMAT_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_CTRL_IMAGE_FORMAT_MASK)

#define VPU_JPEG_ENC_WRAP_STM_CTRL_BITBUF_PTR_CLR_MASK (0x80U)
#define VPU_JPEG_ENC_WRAP_STM_CTRL_BITBUF_PTR_CLR_SHIFT (7U)
/*! BITBUF_PTR_CLR - Bit Buffer Pointer Clear
 *  0b0..Keeps the last bit stream buffer point.
 *  0b1..Clears the bit stream buffer point to base value.
 */
#define VPU_JPEG_ENC_WRAP_STM_CTRL_BITBUF_PTR_CLR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_CTRL_BITBUF_PTR_CLR_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_CTRL_BITBUF_PTR_CLR_MASK)

#define VPU_JPEG_ENC_WRAP_STM_CTRL_AUTO_START_MASK (0x100U)
#define VPU_JPEG_ENC_WRAP_STM_CTRL_AUTO_START_SHIFT (8U)
/*! AUTO_START - Auto Start
 *  0b0..Do not write 1 to CTRL[GO] in the JPEG encoder automatically.
 *  0b1..Writes 1 to CTRL[GO] in the JPEG encoder automatically.
 */
#define VPU_JPEG_ENC_WRAP_STM_CTRL_AUTO_START(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_CTRL_AUTO_START_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_CTRL_AUTO_START_MASK)

#define VPU_JPEG_ENC_WRAP_STM_CTRL_CONFIG_MOD_MASK (0x200U)
#define VPU_JPEG_ENC_WRAP_STM_CTRL_CONFIG_MOD_SHIFT (9U)
/*! CONFIG_MOD - Configuration Mode
 *  0b0..No effect
 *  0b1..In configuration mode
 */
#define VPU_JPEG_ENC_WRAP_STM_CTRL_CONFIG_MOD(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_STM_CTRL_CONFIG_MOD_SHIFT)) & VPU_JPEG_ENC_WRAP_STM_CTRL_CONFIG_MOD_MASK)
/*! @} */

/*! @name SLOT_STATUS - Bit Stream Slot Status */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_HALF_MASK (0x1U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_HALF_SHIFT (0U)
/*! STMBUF_HALF - Stream Buffer Half Flag
 *  0b0..Buffer did not pass the half mark.
 *  0b1..Buffer passed the half mark.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_HALF(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_HALF_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_HALF_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_RTND_MASK (0x2U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_RTND_SHIFT (1U)
/*! STMBUF_RTND - Stream Buffer Returned Flag
 *  0b0..Buffer did not pass the top mark.
 *  0b1..Buffer passed the top mark.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_RTND(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_RTND_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_STMBUF_RTND_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_SWITCHED_IN_MASK (0x4U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_SWITCHED_IN_SHIFT (2U)
/*! SWITCHED_IN - Switched-In Flag
 *  0b0..Did not switch.
 *  0b1..Switched to current slot.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_SWITCHED_IN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_SWITCHED_IN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_SWITCHED_IN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_FRMDONE_MASK (0x8U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_FRMDONE_SHIFT (3U)
/*! FRMDONE - Frame Done Flag
 *  0b0..Full frame is not encoded.
 *  0b1..Full frame is encoded.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_FRMDONE(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_FRMDONE_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_FRMDONE_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_CONFG_ERR_MASK (0x100U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_CONFG_ERR_SHIFT (8U)
/*! ENC_CONFG_ERR - Encoder Configure Error Flag
 *  0b0..Error did not occur.
 *  0b1..Error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_CONFG_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_CONFG_ERR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_CONFG_ERR_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_DES_RD_ERR_MASK (0x200U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_DES_RD_ERR_SHIFT (9U)
/*! DES_RD_ERR - Descriptor Read Error Flag
 *  0b0..Error did not occur.
 *  0b1..Error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_DES_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_DES_RD_ERR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_DES_RD_ERR_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_BIT_WT_ERR_MASK (0x400U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_BIT_WT_ERR_SHIFT (10U)
/*! BIT_WT_ERR - Bit Write Error Flag
 *  0b0..Error did not occur.
 *  0b1..Error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_BIT_WT_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_BIT_WT_ERR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_BIT_WT_ERR_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_IMG_RD_ERR_MASK (0x800U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_IMG_RD_ERR_SHIFT (11U)
/*! IMG_RD_ERR - Image Read Error Flag
 *  0b0..Error did not occur.
 *  0b1..Error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_IMG_RD_ERR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_IMG_RD_ERR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_IMG_RD_ERR_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_CUR_SLOT_MASK (0x60000000U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_CUR_SLOT_SHIFT (29U)
/*! CUR_SLOT - Current Slot */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_CUR_SLOT(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_CUR_SLOT_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_CUR_SLOT_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_ONGOING_MASK (0x80000000U)
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_ONGOING_SHIFT (31U)
/*! ENC_ONGOING - Encoding Ongoing
 *  0b0..Encoding is paused or stopped.
 *  0b1..Encoding is ongoing.
 */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_ONGOING(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_ONGOING_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_STATUS_ENC_ONGOING_MASK)
/*! @} */

/* The count of VPU_JPEG_ENC_WRAP_SLOT_STATUS */
#define VPU_JPEG_ENC_WRAP_SLOT_STATUS_COUNT      (4U)

/*! @name SLOT_IRQ_EN - Bit Stream Interrupt Enable */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK (0x1U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT (0U)
/*! STMBUF_HALF_IRQ_EN - Stream Buffer Half Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK (0x2U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT (1U)
/*! STMBUF_RTND_IRQ_EN - Stream Buffer Returned Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK (0x4U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT (2U)
/*! SWITCHED_IN_IRQ_EN - Switched-In Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK (0x8U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT (3U)
/*! FRMDONE_IRQ_EN - Frame Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_MASK (0x100U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_SHIFT (8U)
/*! ENC_CONFG_ERR_IRQ_EN - Encoder Configure Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_ENC_CONFG_ERR_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK (0x200U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT (9U)
/*! DES_RD_ERR_IRQ_EN - Descriptor Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_MASK (0x400U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_SHIFT (10U)
/*! BIT_WT_ERR_IRQ_EN - Bit Write Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_BIT_WT_ERR_IRQ_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_MASK (0x800U)
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_SHIFT (11U)
/*! IMG_RD_ERR_IRQ_EN - Image Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_IMG_RD_ERR_IRQ_EN_MASK)
/*! @} */

/* The count of VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN */
#define VPU_JPEG_ENC_WRAP_SLOT_IRQ_EN_COUNT      (4U)

/*! @name SLOT_BUF_PTR - Bit Stream Buffer Pointer */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_MASK (0xFFFFFFFFU)
#define VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT (0U)
/*! STMBUF_PTR - Stream 0 Buffer Pointer */
#define VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_STMBUF_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_MASK)
/*! @} */

/* The count of VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR */
#define VPU_JPEG_ENC_WRAP_SLOT_BUF_PTR_COUNT     (4U)

/*! @name SLOT_CUR_DESCPT_PTR - Current Encoding Descriptor Pointer */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PTR_MASK (0xFFFFFFFCU)
#define VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PTR_SHIFT (2U)
/*! CUR_DESCPT_PTR - Current Descriptors Pointer */
#define VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PTR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PTR_MASK)
/*! @} */

/* The count of VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR */
#define VPU_JPEG_ENC_WRAP_SLOT_CUR_DESCPT_PTR_COUNT (4U)

/*! @name SLOT_NXT_DESCPT_PTR - Next Encoding Descriptor Pointer */
/*! @{ */

#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_MASK (0x1U)
#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_SHIFT (0U)
/*! NXT_DESCPT_PTR_EN - Slot Next Stream Descriptor Pointer Enable
 *  0b0..Invalid
 *  0b1..Valid
 */
#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_EN_MASK)

#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK (0xFFFFFFFCU)
#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT (2U)
/*! NXT_DESCPT_PTR - Slot Next Encoding Descriptors Pointer */
#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR(x) (((uint32_t)(((uint32_t)(x)) << VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT)) & VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK)
/*! @} */

/* The count of VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR */
#define VPU_JPEG_ENC_WRAP_SLOT_NXT_DESCPT_PTR_COUNT (4U)


/*!
 * @}
 */ /* end of group VPU_JPEG_ENC_WRAP_Register_Masks */


/*!
 * @}
 */ /* end of group VPU_JPEG_ENC_WRAP_Peripheral_Access_Layer */


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


#endif  /* VPU_JPEG_ENC_WRAP_H_ */

