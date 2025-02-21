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
**         CMSIS Peripheral Access Layer for JPEG_DEC_WRAP
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
 * @file JPEG_DEC_WRAP.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for JPEG_DEC_WRAP
 *
 * CMSIS Peripheral Access Layer for JPEG_DEC_WRAP
 */

#if !defined(JPEG_DEC_WRAP_H_)
#define JPEG_DEC_WRAP_H_                         /**< Symbol preventing repeated inclusion */

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
   -- JPEG_DEC_WRAP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPEG_DEC_WRAP_Peripheral_Access_Layer JPEG_DEC_WRAP Peripheral Access Layer
 * @{
 */

/** JPEG_DEC_WRAP - Size of Registers Arrays */
#define JPEG_DEC_WRAP_BITSTRM_SLOT_REGS_COUNT     4u

/** JPEG_DEC_WRAP - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_CTRL;                          /**< Global Control, offset: 0x0 */
  __I  uint32_t COM_STATUS;                        /**< Common Status, offset: 0x4 */
       uint8_t RESERVED_0[12];
  __IO uint32_t OUT_BUF_BASE0;                     /**< Output Image Frame Buffer0 Base Address, offset: 0x14 */
  __IO uint32_t OUT_BUF_BASE1;                     /**< Output Image Frame Buffer1 Base Address, offset: 0x18 */
  __IO uint32_t OUT_PITCH;                         /**< Image Output Buffer Pitch, offset: 0x1C */
  __IO uint32_t STM_BUFBASE;                       /**< Input JPEG Stream Buffer Base Address, offset: 0x20 */
  __IO uint32_t STM_BUFSIZE;                       /**< Input JPEG Stream Buffer Size, offset: 0x24 */
  __IO uint32_t IMGSIZE;                           /**< Image Resolution, offset: 0x28 */
  __IO uint32_t STM_CTRL;                          /**< Bit Stream and Switching Control, offset: 0x2C */
       uint8_t RESERVED_1[65488];
  struct {                                         /* offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_STATUS;                       /**< Bit Stream Status, array offset: 0x10000, array step: 0x10000 */
    __IO uint32_t SLOT_IRQ_EN;                       /**< Bit Stream Interrupt Enable, array offset: 0x10004, array step: 0x10000 */
    __I  uint32_t SLOT_BUF_PTR;                      /**< Bit Stream Buffer Pointer, array offset: 0x10008, array step: 0x10000 */
    __I  uint32_t SLOT_CUR_DESCPT_PTR;               /**< Current Descriptors, array offset: 0x1000C, array step: 0x10000 */
    __IO uint32_t SLOT_NXT_DESCPT_PTR;               /**< Next Descriptors, array offset: 0x10010, array step: 0x10000 */
         uint8_t RESERVED_0[65516];
  } BITSTRM_SLOT_REGS[JPEG_DEC_WRAP_BITSTRM_SLOT_REGS_COUNT];
} JPEG_DEC_WRAP_Type;

/* ----------------------------------------------------------------------------
   -- JPEG_DEC_WRAP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPEG_DEC_WRAP_Register_Masks JPEG_DEC_WRAP Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
/*! @{ */

#define JPEG_DEC_WRAP_GLB_CTRL_JPG_DEC_EN_MASK   (0x1U)
#define JPEG_DEC_WRAP_GLB_CTRL_JPG_DEC_EN_SHIFT  (0U)
/*! JPG_DEC_EN - JPEGDEC and JPGDECWRP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_GLB_CTRL_JPG_DEC_EN(x)     (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_GLB_CTRL_JPG_DEC_EN_SHIFT)) & JPEG_DEC_WRAP_GLB_CTRL_JPG_DEC_EN_MASK)

#define JPEG_DEC_WRAP_GLB_CTRL_SFTRST_MASK       (0x2U)
#define JPEG_DEC_WRAP_GLB_CTRL_SFTRST_SHIFT      (1U)
/*! SFTRST - Engine Soft Reset
 *  0b0..No effect
 *  0b1..Performs a soft reset.
 */
#define JPEG_DEC_WRAP_GLB_CTRL_SFTRST(x)         (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_GLB_CTRL_SFTRST_SHIFT)) & JPEG_DEC_WRAP_GLB_CTRL_SFTRST_MASK)

#define JPEG_DEC_WRAP_GLB_CTRL_DEC_GO_MASK       (0x4U)
#define JPEG_DEC_WRAP_GLB_CTRL_DEC_GO_SHIFT      (2U)
/*! DEC_GO - Start Decoding
 *  0b0..Do not start decoding manually.
 *  0b1..Starts decoding manually.
 */
#define JPEG_DEC_WRAP_GLB_CTRL_DEC_GO(x)         (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_GLB_CTRL_DEC_GO_SHIFT)) & JPEG_DEC_WRAP_GLB_CTRL_DEC_GO_MASK)

#define JPEG_DEC_WRAP_GLB_CTRL_L_ENDIAN_MASK     (0x8U)
#define JPEG_DEC_WRAP_GLB_CTRL_L_ENDIAN_SHIFT    (3U)
/*! L_ENDIAN - Little-Endian Enable
 *  0b0..Big-Endian
 *  0b1..Little-Endian
 */
#define JPEG_DEC_WRAP_GLB_CTRL_L_ENDIAN(x)       (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_GLB_CTRL_L_ENDIAN_SHIFT)) & JPEG_DEC_WRAP_GLB_CTRL_L_ENDIAN_MASK)

#define JPEG_DEC_WRAP_GLB_CTRL_SLOT_EN_MASK      (0xF0U)
#define JPEG_DEC_WRAP_GLB_CTRL_SLOT_EN_SHIFT     (4U)
/*! SLOT_EN - Slots Enable
 *  0b0000..Disables all slots.
 *  0b0001..Enables SLOT0.
 *  0b0010..Enables SLOT1.
 *  0b0100..Enables SLOT2.
 *  0b1000..Enables SLOT3.
 *  *..
 */
#define JPEG_DEC_WRAP_GLB_CTRL_SLOT_EN(x)        (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_GLB_CTRL_SLOT_EN_SHIFT)) & JPEG_DEC_WRAP_GLB_CTRL_SLOT_EN_MASK)
/*! @} */

/*! @name COM_STATUS - Common Status */
/*! @{ */

#define JPEG_DEC_WRAP_COM_STATUS_CUR_SLOT_MASK   (0x60000000U)
#define JPEG_DEC_WRAP_COM_STATUS_CUR_SLOT_SHIFT  (29U)
/*! CUR_SLOT - Current Slot */
#define JPEG_DEC_WRAP_COM_STATUS_CUR_SLOT(x)     (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_COM_STATUS_CUR_SLOT_SHIFT)) & JPEG_DEC_WRAP_COM_STATUS_CUR_SLOT_MASK)

#define JPEG_DEC_WRAP_COM_STATUS_DEC_ONGOING_MASK (0x80000000U)
#define JPEG_DEC_WRAP_COM_STATUS_DEC_ONGOING_SHIFT (31U)
/*! DEC_ONGOING - Decoding Ongoing */
#define JPEG_DEC_WRAP_COM_STATUS_DEC_ONGOING(x)  (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_COM_STATUS_DEC_ONGOING_SHIFT)) & JPEG_DEC_WRAP_COM_STATUS_DEC_ONGOING_MASK)
/*! @} */

/*! @name OUT_BUF_BASE0 - Output Image Frame Buffer0 Base Address */
/*! @{ */

#define JPEG_DEC_WRAP_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK (0xFFFFFFF0U)
#define JPEG_DEC_WRAP_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT (4U)
/*! OUT_BUF_BASE0 - Pixel Frame Buffer0 Base */
#define JPEG_DEC_WRAP_OUT_BUF_BASE0_OUT_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT)) & JPEG_DEC_WRAP_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK)
/*! @} */

/*! @name OUT_BUF_BASE1 - Output Image Frame Buffer1 Base Address */
/*! @{ */

#define JPEG_DEC_WRAP_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK (0xFFFFFFF0U)
#define JPEG_DEC_WRAP_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT (4U)
/*! OUT_BUF_BASE1 - Pixel Frame Buffer1 Base */
#define JPEG_DEC_WRAP_OUT_BUF_BASE1_OUT_BUF_BASE1(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT)) & JPEG_DEC_WRAP_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK)
/*! @} */

/*! @name OUT_PITCH - Image Output Buffer Pitch */
/*! @{ */

#define JPEG_DEC_WRAP_OUT_PITCH_OUT_PITCH_MASK   (0xFFFFU)
#define JPEG_DEC_WRAP_OUT_PITCH_OUT_PITCH_SHIFT  (0U)
/*! OUT_PITCH - Output Image Pitch */
#define JPEG_DEC_WRAP_OUT_PITCH_OUT_PITCH(x)     (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_OUT_PITCH_OUT_PITCH_SHIFT)) & JPEG_DEC_WRAP_OUT_PITCH_OUT_PITCH_MASK)
/*! @} */

/*! @name STM_BUFBASE - Input JPEG Stream Buffer Base Address */
/*! @{ */

#define JPEG_DEC_WRAP_STM_BUFBASE_STM_BUFBASE_MASK (0xFFFFFFF0U)
#define JPEG_DEC_WRAP_STM_BUFBASE_STM_BUFBASE_SHIFT (4U)
/*! STM_BUFBASE - Bit Stream Buffer Base */
#define JPEG_DEC_WRAP_STM_BUFBASE_STM_BUFBASE(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_BUFBASE_STM_BUFBASE_SHIFT)) & JPEG_DEC_WRAP_STM_BUFBASE_STM_BUFBASE_MASK)
/*! @} */

/*! @name STM_BUFSIZE - Input JPEG Stream Buffer Size */
/*! @{ */

#define JPEG_DEC_WRAP_STM_BUFSIZE_STM_BUFSIZE_MASK (0xFFFFFC00U)
#define JPEG_DEC_WRAP_STM_BUFSIZE_STM_BUFSIZE_SHIFT (10U)
/*! STM_BUFSIZE - Bit Stream Buffer Size */
#define JPEG_DEC_WRAP_STM_BUFSIZE_STM_BUFSIZE(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_BUFSIZE_STM_BUFSIZE_SHIFT)) & JPEG_DEC_WRAP_STM_BUFSIZE_STM_BUFSIZE_MASK)
/*! @} */

/*! @name IMGSIZE - Image Resolution */
/*! @{ */

#define JPEG_DEC_WRAP_IMGSIZE_IMG_HEIGHT_MASK    (0x3FFFU)
#define JPEG_DEC_WRAP_IMGSIZE_IMG_HEIGHT_SHIFT   (0U)
/*! IMG_HEIGHT - Image Height */
#define JPEG_DEC_WRAP_IMGSIZE_IMG_HEIGHT(x)      (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_IMGSIZE_IMG_HEIGHT_SHIFT)) & JPEG_DEC_WRAP_IMGSIZE_IMG_HEIGHT_MASK)

#define JPEG_DEC_WRAP_IMGSIZE_IMG_WIDTH_MASK     (0x3FFF0000U)
#define JPEG_DEC_WRAP_IMGSIZE_IMG_WIDTH_SHIFT    (16U)
/*! IMG_WIDTH - Image Width */
#define JPEG_DEC_WRAP_IMGSIZE_IMG_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_IMGSIZE_IMG_WIDTH_SHIFT)) & JPEG_DEC_WRAP_IMGSIZE_IMG_WIDTH_MASK)
/*! @} */

/*! @name STM_CTRL - Bit Stream and Switching Control */
/*! @{ */

#define JPEG_DEC_WRAP_STM_CTRL_PIXEL_PRECISION_MASK (0x4U)
#define JPEG_DEC_WRAP_STM_CTRL_PIXEL_PRECISION_SHIFT (2U)
/*! PIXEL_PRECISION - Pixel Precision
 *  0b0..8-bit
 *  0b1..12-bit
 */
#define JPEG_DEC_WRAP_STM_CTRL_PIXEL_PRECISION(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_CTRL_PIXEL_PRECISION_SHIFT)) & JPEG_DEC_WRAP_STM_CTRL_PIXEL_PRECISION_MASK)

#define JPEG_DEC_WRAP_STM_CTRL_IMAGE_FORMAT_MASK (0x78U)
#define JPEG_DEC_WRAP_STM_CTRL_IMAGE_FORMAT_SHIFT (3U)
/*! IMAGE_FORMAT - Image Format
 *  0b0000..YUV420 (2-planar, Y at the first planar, and UV at the second planar)
 *  0b0001..YUV422 (1-planar in the YUYV sequence)
 *  0b0010..RGB (BGRBGR packed format)
 *  0b0011..YUV444 (first planar in the YUVYUV sequence)
 *  0b0100..Gray (Y8 or Y12) or single component
 *  0b0101..
 *  0b0110..ARGB
 */
#define JPEG_DEC_WRAP_STM_CTRL_IMAGE_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_CTRL_IMAGE_FORMAT_SHIFT)) & JPEG_DEC_WRAP_STM_CTRL_IMAGE_FORMAT_MASK)

#define JPEG_DEC_WRAP_STM_CTRL_BITBUF_PTR_CLR_MASK (0x80U)
#define JPEG_DEC_WRAP_STM_CTRL_BITBUF_PTR_CLR_SHIFT (7U)
/*! BITBUF_PTR_CLR - Bit Buffer Pointer Clear
 *  0b0..Restores the bit stream buffer pointer from the save pointer.
 *  0b1..Clears the bit stream buffer pointer from the save pointer.
 */
#define JPEG_DEC_WRAP_STM_CTRL_BITBUF_PTR_CLR(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_CTRL_BITBUF_PTR_CLR_SHIFT)) & JPEG_DEC_WRAP_STM_CTRL_BITBUF_PTR_CLR_MASK)

#define JPEG_DEC_WRAP_STM_CTRL_AUTO_START_MASK   (0x100U)
#define JPEG_DEC_WRAP_STM_CTRL_AUTO_START_SHIFT  (8U)
/*! AUTO_START - Auto Start
 *  0b0..Do not write 1 to CTRL[GO] in JPEGDEC.
 *  0b1..Writes 1 to CTRL[GO] in JPEGDEC.
 */
#define JPEG_DEC_WRAP_STM_CTRL_AUTO_START(x)     (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_STM_CTRL_AUTO_START_SHIFT)) & JPEG_DEC_WRAP_STM_CTRL_AUTO_START_MASK)
/*! @} */

/*! @name SLOT_STATUS - Bit Stream Status */
/*! @{ */

#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_HALF_MASK (0x1U)
#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_HALF_SHIFT (0U)
/*! STMBUF_HALF - Stream Buffer Half Flag
 *  0b0..The bit stream buffer pointer for the current slot has not passed half of the buffer size.
 *  0b1..The bit stream buffer pointer for the current slot passed half of the buffer size.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_HALF(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_HALF_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_HALF_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_RTND_MASK (0x2U)
#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_RTND_SHIFT (1U)
/*! STMBUF_RTND - Stream Buffer Returned Flag
 *  0b0..The bit stream buffer pointer for the current slot has not passed the top mark of the buffer.
 *  0b1..The bit stream buffer pointer for the current slot passed the top mark of the buffer.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_RTND(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_RTND_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_STMBUF_RTND_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_SWITCHED_IN_MASK (0x4U)
#define JPEG_DEC_WRAP_SLOT_STATUS_SWITCHED_IN_SHIFT (2U)
/*! SWITCHED_IN - Switched In Flag
 *  0b0..The current slot is not switched in during context switching.
 *  0b1..The current slot is switched in during context switching.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_SWITCHED_IN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_SWITCHED_IN_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_SWITCHED_IN_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_FRMDONE_MASK   (0x8U)
#define JPEG_DEC_WRAP_SLOT_STATUS_FRMDONE_SHIFT  (3U)
/*! FRMDONE - Frame Done Flag
 *  0b0..Decoding is not completed.
 *  0b1..Decoding is completed.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_FRMDONE(x)     (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_FRMDONE_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_FRMDONE_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_DECERR_MASK    (0x100U)
#define JPEG_DEC_WRAP_SLOT_STATUS_DECERR_SHIFT   (8U)
/*! DECERR - Decoding Error Flag
 *  0b0..No decoding error occurred.
 *  0b1..A decoding error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_DECERR(x)      (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_DECERR_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_DECERR_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_DES_RD_ERR_MASK (0x200U)
#define JPEG_DEC_WRAP_SLOT_STATUS_DES_RD_ERR_SHIFT (9U)
/*! DES_RD_ERR - Descriptor Read Error Flag
 *  0b0..No descriptor read error occurred.
 *  0b1..A descriptor read error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_DES_RD_ERR(x)  (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_DES_RD_ERR_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_DES_RD_ERR_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_BIT_RD_ERR_MASK (0x400U)
#define JPEG_DEC_WRAP_SLOT_STATUS_BIT_RD_ERR_SHIFT (10U)
/*! BIT_RD_ERR - Bit Read Error Flag
 *  0b0..No bit read error occurred.
 *  0b1..A bit read error occurred.
 *  0b0..No effect
 *  0b1..Clear the flag
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_BIT_RD_ERR(x)  (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_BIT_RD_ERR_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_BIT_RD_ERR_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_PIXEL_WT_ERR_MASK (0x800U)
#define JPEG_DEC_WRAP_SLOT_STATUS_PIXEL_WT_ERR_SHIFT (11U)
/*! PIXEL_WT_ERR - Pixel Write Error Flag
 *  0b0..No pixel write error occurred.
 *  0b1..A pixel write error occurred.
 *  0b0..No effect
 *  0b1..Clears the flag.
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_PIXEL_WT_ERR(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_PIXEL_WT_ERR_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_PIXEL_WT_ERR_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_CUR_SLOT_MASK  (0x60000000U)
#define JPEG_DEC_WRAP_SLOT_STATUS_CUR_SLOT_SHIFT (29U)
/*! CUR_SLOT - Current Slot */
#define JPEG_DEC_WRAP_SLOT_STATUS_CUR_SLOT(x)    (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_CUR_SLOT_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_CUR_SLOT_MASK)

#define JPEG_DEC_WRAP_SLOT_STATUS_DEC_ONGOING_MASK (0x80000000U)
#define JPEG_DEC_WRAP_SLOT_STATUS_DEC_ONGOING_SHIFT (31U)
/*! DEC_ONGOING - Decoding Ongoing
 *  0b0..Paused or stopped
 *  0b1..Ongoing
 */
#define JPEG_DEC_WRAP_SLOT_STATUS_DEC_ONGOING(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_STATUS_DEC_ONGOING_SHIFT)) & JPEG_DEC_WRAP_SLOT_STATUS_DEC_ONGOING_MASK)
/*! @} */

/* The count of JPEG_DEC_WRAP_SLOT_STATUS */
#define JPEG_DEC_WRAP_SLOT_STATUS_COUNT          (4U)

/*! @name SLOT_IRQ_EN - Bit Stream Interrupt Enable */
/*! @{ */

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK (0x1U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT (0U)
/*! STMBUF_HALF_IRQ_EN - Stream Buffer Half Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK (0x2U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT (1U)
/*! STMBUF_RTND_IRQ_EN - Stream Buffer Returned Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK (0x4U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT (2U)
/*! SWITCHED_IN_IRQ_EN - Switched In Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK (0x8U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT (3U)
/*! FRMDONE_IRQ_EN - Frame Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK (0x100U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT (8U)
/*! DECERR_IRQ_EN - Decoding Error Status Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DECERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK (0x200U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT (9U)
/*! DES_RD_ERR_IRQ_EN - Descriptor Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK (0x400U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT (10U)
/*! BIT_RD_ERR_IRQ_EN - Bit Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK (0x800U)
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT (11U)
/*! PIXEL_WT_ERR_IRQ_EN - Pixel Write Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK)
/*! @} */

/* The count of JPEG_DEC_WRAP_SLOT_IRQ_EN */
#define JPEG_DEC_WRAP_SLOT_IRQ_EN_COUNT          (4U)

/*! @name SLOT_BUF_PTR - Bit Stream Buffer Pointer */
/*! @{ */

#define JPEG_DEC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_MASK (0xFFFFFFFFU)
#define JPEG_DEC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT (0U)
/*! STMBUF_PTR - Stream Buffer Pointer */
#define JPEG_DEC_WRAP_SLOT_BUF_PTR_STMBUF_PTR(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT)) & JPEG_DEC_WRAP_SLOT_BUF_PTR_STMBUF_PTR_MASK)
/*! @} */

/* The count of JPEG_DEC_WRAP_SLOT_BUF_PTR */
#define JPEG_DEC_WRAP_SLOT_BUF_PTR_COUNT         (4U)

/*! @name SLOT_CUR_DESCPT_PTR - Current Descriptors */
/*! @{ */

#define JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT (2U)
/*! CUR_DESCPT_PRT - Current Decoding Descriptor Pointer */
#define JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT)) & JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK)
/*! @} */

/* The count of JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR */
#define JPEG_DEC_WRAP_SLOT_CUR_DESCPT_PTR_COUNT  (4U)

/*! @name SLOT_NXT_DESCPT_PTR - Next Descriptors */
/*! @{ */

#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK (0x1U)
#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT (0U)
/*! NXT_DESCPT_EN - Next Stream Descriptor Pointer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT)) & JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK)

#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK (0xFFFFFFFCU)
#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT (2U)
/*! NXT_DESCPT_PTR - Next Descriptor Pointer */
#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR(x) (((uint32_t)(((uint32_t)(x)) << JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT)) & JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK)
/*! @} */

/* The count of JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR */
#define JPEG_DEC_WRAP_SLOT_NXT_DESCPT_PTR_COUNT  (4U)


/*!
 * @}
 */ /* end of group JPEG_DEC_WRAP_Register_Masks */


/*!
 * @}
 */ /* end of group JPEG_DEC_WRAP_Peripheral_Access_Layer */


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


#endif  /* JPEG_DEC_WRAP_H_ */

