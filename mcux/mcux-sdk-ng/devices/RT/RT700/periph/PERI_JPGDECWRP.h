/*
** ###################################################################
**     Processors:          MIMXRT735SGAWAR_cm33_core0
**                          MIMXRT735SGAWAR_cm33_core1
**                          MIMXRT735SGAWAR_ezhv
**                          MIMXRT735SGAWAR_hifi1
**                          MIMXRT735SGFOA_cm33_core0
**                          MIMXRT735SGFOA_cm33_core1
**                          MIMXRT735SGFOA_ezhv
**                          MIMXRT735SGFOA_hifi1
**                          MIMXRT758SGAWAR_cm33_core0
**                          MIMXRT758SGAWAR_cm33_core1
**                          MIMXRT758SGAWAR_ezhv
**                          MIMXRT758SGAWAR_hifi1
**                          MIMXRT758SGFOA_cm33_core0
**                          MIMXRT758SGFOA_cm33_core1
**                          MIMXRT758SGFOA_ezhv
**                          MIMXRT758SGFOA_hifi1
**                          MIMXRT798SGAWAR_cm33_core0
**                          MIMXRT798SGAWAR_cm33_core1
**                          MIMXRT798SGAWAR_ezhv
**                          MIMXRT798SGAWAR_hifi1
**                          MIMXRT798SGAWAR_hifi4
**                          MIMXRT798SGFOA_cm33_core0
**                          MIMXRT798SGFOA_cm33_core1
**                          MIMXRT798SGFOA_ezhv
**                          MIMXRT798SGFOA_hifi1
**                          MIMXRT798SGFOA_hifi4
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250526
**
**     Abstract:
**         CMSIS Peripheral Access Layer for JPGDECWRP
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2022-09-15)
**         Initial version.
**     - rev. 2.0 (2024-05-28)
**         Rev2 DraftA.
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_JPGDECWRP.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for JPGDECWRP
 *
 * CMSIS Peripheral Access Layer for JPGDECWRP
 */

#if !defined(PERI_JPGDECWRP_H_)
#define PERI_JPGDECWRP_H_                        /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT735SGAWAR_cm33_core0) || defined(CPU_MIMXRT735SGFOA_cm33_core0))
#include "MIMXRT735S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_cm33_core1) || defined(CPU_MIMXRT735SGFOA_cm33_core1))
#include "MIMXRT735S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_ezhv) || defined(CPU_MIMXRT735SGFOA_ezhv))
#include "MIMXRT735S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT735SGAWAR_hifi1) || defined(CPU_MIMXRT735SGFOA_hifi1))
#include "MIMXRT735S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core0) || defined(CPU_MIMXRT758SGFOA_cm33_core0))
#include "MIMXRT758S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_cm33_core1) || defined(CPU_MIMXRT758SGFOA_cm33_core1))
#include "MIMXRT758S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_ezhv) || defined(CPU_MIMXRT758SGFOA_ezhv))
#include "MIMXRT758S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT758SGAWAR_hifi1) || defined(CPU_MIMXRT758SGFOA_hifi1))
#include "MIMXRT758S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core0) || defined(CPU_MIMXRT798SGFOA_cm33_core0))
#include "MIMXRT798S_cm33_core0_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_cm33_core1) || defined(CPU_MIMXRT798SGFOA_cm33_core1))
#include "MIMXRT798S_cm33_core1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_ezhv) || defined(CPU_MIMXRT798SGFOA_ezhv))
#include "MIMXRT798S_ezhv_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi1) || defined(CPU_MIMXRT798SGFOA_hifi1))
#include "MIMXRT798S_hifi1_COMMON.h"
#elif (defined(CPU_MIMXRT798SGAWAR_hifi4) || defined(CPU_MIMXRT798SGFOA_hifi4))
#include "MIMXRT798S_hifi4_COMMON.h"
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
   -- JPGDECWRP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGDECWRP_Peripheral_Access_Layer JPGDECWRP Peripheral Access Layer
 * @{
 */

/** JPGDECWRP - Size of Registers Arrays */
#define JPGDECWRP_SLOT_REGS_COUNT                 4u

/** JPGDECWRP - Register Layout Typedef */
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
       uint8_t RESERVED_1[464];
  struct {                                         /* offset: 0x200, array step: 0x200 */
    __IO uint32_t SLOT_STATUS;                       /**< Bit Stream Status, array offset: 0x200, array step: 0x200 */
    __IO uint32_t SLOT_IRQ_EN;                       /**< Bit Stream Interrupt Enable, array offset: 0x204, array step: 0x200 */
    __I  uint32_t SLOT_BUF_PTR;                      /**< Bit Stream Buffer Pointer, array offset: 0x208, array step: 0x200 */
    __I  uint32_t SLOT_CUR_DESCPT_PTR;               /**< Current Descriptors, array offset: 0x20C, array step: 0x200 */
    __IO uint32_t SLOT_NXT_DESCPT_PTR;               /**< Next Descriptors, array offset: 0x210, array step: 0x200 */
         uint8_t RESERVED_0[492];
  } SLOT_REGS[JPGDECWRP_SLOT_REGS_COUNT];
} JPGDECWRP_Type;

/* ----------------------------------------------------------------------------
   -- JPGDECWRP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup JPGDECWRP_Register_Masks JPGDECWRP Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
/*! @{ */

#define JPGDECWRP_GLB_CTRL_JPG_DEC_EN_MASK       (0x1U)
#define JPGDECWRP_GLB_CTRL_JPG_DEC_EN_SHIFT      (0U)
/*! JPG_DEC_EN - JPEGDEC and JPGDECWRP Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_GLB_CTRL_JPG_DEC_EN(x)         (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_GLB_CTRL_JPG_DEC_EN_SHIFT)) & JPGDECWRP_GLB_CTRL_JPG_DEC_EN_MASK)

#define JPGDECWRP_GLB_CTRL_SFTRST_MASK           (0x2U)
#define JPGDECWRP_GLB_CTRL_SFTRST_SHIFT          (1U)
/*! SFTRST - Engine Soft Reset
 *  0b0..No effect
 *  0b1..Performs a soft reset.
 */
#define JPGDECWRP_GLB_CTRL_SFTRST(x)             (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_GLB_CTRL_SFTRST_SHIFT)) & JPGDECWRP_GLB_CTRL_SFTRST_MASK)

#define JPGDECWRP_GLB_CTRL_DEC_GO_MASK           (0x4U)
#define JPGDECWRP_GLB_CTRL_DEC_GO_SHIFT          (2U)
/*! DEC_GO - Start Decoding
 *  0b0..Do not start decoding manually.
 *  0b1..Starts decoding manually.
 */
#define JPGDECWRP_GLB_CTRL_DEC_GO(x)             (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_GLB_CTRL_DEC_GO_SHIFT)) & JPGDECWRP_GLB_CTRL_DEC_GO_MASK)

#define JPGDECWRP_GLB_CTRL_L_ENDIAN_MASK         (0x8U)
#define JPGDECWRP_GLB_CTRL_L_ENDIAN_SHIFT        (3U)
/*! L_ENDIAN - Little-Endian Enable
 *  0b0..Big-Endian
 *  0b1..Little-Endian
 */
#define JPGDECWRP_GLB_CTRL_L_ENDIAN(x)           (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_GLB_CTRL_L_ENDIAN_SHIFT)) & JPGDECWRP_GLB_CTRL_L_ENDIAN_MASK)

#define JPGDECWRP_GLB_CTRL_SLOT_EN_MASK          (0xF0U)
#define JPGDECWRP_GLB_CTRL_SLOT_EN_SHIFT         (4U)
/*! SLOT_EN - Slots Enable
 *  0b0000..Disables all slots.
 *  0b0001..Enables SLOT0.
 *  0b0010..Enables SLOT1.
 *  0b0100..Enables SLOT2.
 *  0b1000..Enables SLOT3.
 */
#define JPGDECWRP_GLB_CTRL_SLOT_EN(x)            (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_GLB_CTRL_SLOT_EN_SHIFT)) & JPGDECWRP_GLB_CTRL_SLOT_EN_MASK)
/*! @} */

/*! @name COM_STATUS - Common Status */
/*! @{ */

#define JPGDECWRP_COM_STATUS_CUR_SLOT_MASK       (0x60000000U)
#define JPGDECWRP_COM_STATUS_CUR_SLOT_SHIFT      (29U)
/*! CUR_SLOT - Current Slot */
#define JPGDECWRP_COM_STATUS_CUR_SLOT(x)         (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_COM_STATUS_CUR_SLOT_SHIFT)) & JPGDECWRP_COM_STATUS_CUR_SLOT_MASK)

#define JPGDECWRP_COM_STATUS_DEC_ONGOING_MASK    (0x80000000U)
#define JPGDECWRP_COM_STATUS_DEC_ONGOING_SHIFT   (31U)
/*! DEC_ONGOING - Decoding Ongoing */
#define JPGDECWRP_COM_STATUS_DEC_ONGOING(x)      (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_COM_STATUS_DEC_ONGOING_SHIFT)) & JPGDECWRP_COM_STATUS_DEC_ONGOING_MASK)
/*! @} */

/*! @name OUT_BUF_BASE0 - Output Image Frame Buffer0 Base Address */
/*! @{ */

#define JPGDECWRP_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK (0xFFFFFFF0U)
#define JPGDECWRP_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT (4U)
/*! OUT_BUF_BASE0 - Pixel Frame Buffer0 Base */
#define JPGDECWRP_OUT_BUF_BASE0_OUT_BUF_BASE0(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_OUT_BUF_BASE0_OUT_BUF_BASE0_SHIFT)) & JPGDECWRP_OUT_BUF_BASE0_OUT_BUF_BASE0_MASK)
/*! @} */

/*! @name OUT_BUF_BASE1 - Output Image Frame Buffer1 Base Address */
/*! @{ */

#define JPGDECWRP_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK (0xFFFFFFF0U)
#define JPGDECWRP_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT (4U)
/*! OUT_BUF_BASE1 - Pixel Frame Buffer1 Base */
#define JPGDECWRP_OUT_BUF_BASE1_OUT_BUF_BASE1(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_OUT_BUF_BASE1_OUT_BUF_BASE1_SHIFT)) & JPGDECWRP_OUT_BUF_BASE1_OUT_BUF_BASE1_MASK)
/*! @} */

/*! @name OUT_PITCH - Image Output Buffer Pitch */
/*! @{ */

#define JPGDECWRP_OUT_PITCH_OUT_PITCH_MASK       (0xFFFFU)
#define JPGDECWRP_OUT_PITCH_OUT_PITCH_SHIFT      (0U)
/*! OUT_PITCH - Output Image Pitch */
#define JPGDECWRP_OUT_PITCH_OUT_PITCH(x)         (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_OUT_PITCH_OUT_PITCH_SHIFT)) & JPGDECWRP_OUT_PITCH_OUT_PITCH_MASK)
/*! @} */

/*! @name STM_BUFBASE - Input JPEG Stream Buffer Base Address */
/*! @{ */

#define JPGDECWRP_STM_BUFBASE_STM_BUFBASE_MASK   (0xFFFFFFF0U)
#define JPGDECWRP_STM_BUFBASE_STM_BUFBASE_SHIFT  (4U)
/*! STM_BUFBASE - Bit Stream Buffer Base */
#define JPGDECWRP_STM_BUFBASE_STM_BUFBASE(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_BUFBASE_STM_BUFBASE_SHIFT)) & JPGDECWRP_STM_BUFBASE_STM_BUFBASE_MASK)
/*! @} */

/*! @name STM_BUFSIZE - Input JPEG Stream Buffer Size */
/*! @{ */

#define JPGDECWRP_STM_BUFSIZE_STM_BUFSIZE_MASK   (0xFFFFFC00U)
#define JPGDECWRP_STM_BUFSIZE_STM_BUFSIZE_SHIFT  (10U)
/*! STM_BUFSIZE - Bit Stream Buffer Size */
#define JPGDECWRP_STM_BUFSIZE_STM_BUFSIZE(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_BUFSIZE_STM_BUFSIZE_SHIFT)) & JPGDECWRP_STM_BUFSIZE_STM_BUFSIZE_MASK)
/*! @} */

/*! @name IMGSIZE - Image Resolution */
/*! @{ */

#define JPGDECWRP_IMGSIZE_IMG_HEIGHT_MASK        (0x3FFFU)
#define JPGDECWRP_IMGSIZE_IMG_HEIGHT_SHIFT       (0U)
/*! IMG_HEIGHT - Image Height */
#define JPGDECWRP_IMGSIZE_IMG_HEIGHT(x)          (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_IMGSIZE_IMG_HEIGHT_SHIFT)) & JPGDECWRP_IMGSIZE_IMG_HEIGHT_MASK)

#define JPGDECWRP_IMGSIZE_IMG_WIDTH_MASK         (0x3FFF0000U)
#define JPGDECWRP_IMGSIZE_IMG_WIDTH_SHIFT        (16U)
/*! IMG_WIDTH - Image Width */
#define JPGDECWRP_IMGSIZE_IMG_WIDTH(x)           (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_IMGSIZE_IMG_WIDTH_SHIFT)) & JPGDECWRP_IMGSIZE_IMG_WIDTH_MASK)
/*! @} */

/*! @name STM_CTRL - Bit Stream and Switching Control */
/*! @{ */

#define JPGDECWRP_STM_CTRL_PIXEL_PRECISION_MASK  (0x4U)
#define JPGDECWRP_STM_CTRL_PIXEL_PRECISION_SHIFT (2U)
/*! PIXEL_PRECISION - Pixel Precision
 *  0b0..8-bit
 *  0b1..12-bit
 */
#define JPGDECWRP_STM_CTRL_PIXEL_PRECISION(x)    (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_CTRL_PIXEL_PRECISION_SHIFT)) & JPGDECWRP_STM_CTRL_PIXEL_PRECISION_MASK)

#define JPGDECWRP_STM_CTRL_IMAGE_FORMAT_MASK     (0x78U)
#define JPGDECWRP_STM_CTRL_IMAGE_FORMAT_SHIFT    (3U)
/*! IMAGE_FORMAT - Image Format
 *  0b0000..YUV420 (2-planar, Y at the first planar, and UV at the second planar)
 *  0b0001..YUV422 (1-planar in the YUYV sequence)
 *  0b0010..RGB (BGRBGR packed format)
 *  0b0011..YUV444 (first planar in the YUVYUV sequence)
 *  0b0100..Gray (Y8 or Y12) or single component
 *  0b0101..
 *  0b0110..ARGB
 */
#define JPGDECWRP_STM_CTRL_IMAGE_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_CTRL_IMAGE_FORMAT_SHIFT)) & JPGDECWRP_STM_CTRL_IMAGE_FORMAT_MASK)

#define JPGDECWRP_STM_CTRL_BITBUF_PTR_CLR_MASK   (0x80U)
#define JPGDECWRP_STM_CTRL_BITBUF_PTR_CLR_SHIFT  (7U)
/*! BITBUF_PTR_CLR - Bit Buffer Pointer Clear
 *  0b0..Restores the bit stream buffer pointer from the save pointer.
 *  0b1..Clears the bit stream buffer pointer from the save pointer.
 */
#define JPGDECWRP_STM_CTRL_BITBUF_PTR_CLR(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_CTRL_BITBUF_PTR_CLR_SHIFT)) & JPGDECWRP_STM_CTRL_BITBUF_PTR_CLR_MASK)

#define JPGDECWRP_STM_CTRL_AUTO_START_MASK       (0x100U)
#define JPGDECWRP_STM_CTRL_AUTO_START_SHIFT      (8U)
/*! AUTO_START - Auto Start
 *  0b0..Do not write 1 to CTRL[GO] in JPEGDEC.
 *  0b1..Writes 1 to CTRL[GO] in JPEGDEC.
 */
#define JPGDECWRP_STM_CTRL_AUTO_START(x)         (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_STM_CTRL_AUTO_START_SHIFT)) & JPGDECWRP_STM_CTRL_AUTO_START_MASK)
/*! @} */

/*! @name SLOT_STATUS - Bit Stream Status */
/*! @{ */

#define JPGDECWRP_SLOT_STATUS_STMBUF_HALF_MASK   (0x1U)
#define JPGDECWRP_SLOT_STATUS_STMBUF_HALF_SHIFT  (0U)
/*! STMBUF_HALF - Stream Buffer Half Flag
 *  0b0..No effect
 *  0b0..The bit stream buffer pointer for the current slot has not passed half of the buffer size.
 *  0b1..Clears the flag.
 *  0b1..The bit stream buffer pointer for the current slot passed half of the buffer size.
 */
#define JPGDECWRP_SLOT_STATUS_STMBUF_HALF(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_STMBUF_HALF_SHIFT)) & JPGDECWRP_SLOT_STATUS_STMBUF_HALF_MASK)

#define JPGDECWRP_SLOT_STATUS_STMBUF_RTND_MASK   (0x2U)
#define JPGDECWRP_SLOT_STATUS_STMBUF_RTND_SHIFT  (1U)
/*! STMBUF_RTND - Stream Buffer Returned Flag
 *  0b0..No effect
 *  0b0..The bit stream buffer pointer for the current slot has not passed the top mark of the buffer.
 *  0b1..Clears the flag.
 *  0b1..The bit stream buffer pointer for the current slot passed the top mark of the buffer.
 */
#define JPGDECWRP_SLOT_STATUS_STMBUF_RTND(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_STMBUF_RTND_SHIFT)) & JPGDECWRP_SLOT_STATUS_STMBUF_RTND_MASK)

#define JPGDECWRP_SLOT_STATUS_SWITCHED_IN_MASK   (0x4U)
#define JPGDECWRP_SLOT_STATUS_SWITCHED_IN_SHIFT  (2U)
/*! SWITCHED_IN - Switched In Flag
 *  0b0..No effect
 *  0b0..The current slot is not switched in during context switching.
 *  0b1..Clears the flag.
 *  0b1..The current slot is switched in during context switching.
 */
#define JPGDECWRP_SLOT_STATUS_SWITCHED_IN(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_SWITCHED_IN_SHIFT)) & JPGDECWRP_SLOT_STATUS_SWITCHED_IN_MASK)

#define JPGDECWRP_SLOT_STATUS_FRMDONE_MASK       (0x8U)
#define JPGDECWRP_SLOT_STATUS_FRMDONE_SHIFT      (3U)
/*! FRMDONE - Frame Done Flag
 *  0b0..Decoding is not completed.
 *  0b0..No effect
 *  0b1..Clears the flag.
 *  0b1..Decoding is completed.
 */
#define JPGDECWRP_SLOT_STATUS_FRMDONE(x)         (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_FRMDONE_SHIFT)) & JPGDECWRP_SLOT_STATUS_FRMDONE_MASK)

#define JPGDECWRP_SLOT_STATUS_DECERR_MASK        (0x100U)
#define JPGDECWRP_SLOT_STATUS_DECERR_SHIFT       (8U)
/*! DECERR - Decoding Error Flag
 *  0b0..No decoding error occurred.
 *  0b0..No effect
 *  0b1..A decoding error occurred.
 *  0b1..Clears the flag.
 */
#define JPGDECWRP_SLOT_STATUS_DECERR(x)          (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_DECERR_SHIFT)) & JPGDECWRP_SLOT_STATUS_DECERR_MASK)

#define JPGDECWRP_SLOT_STATUS_DES_RD_ERR_MASK    (0x200U)
#define JPGDECWRP_SLOT_STATUS_DES_RD_ERR_SHIFT   (9U)
/*! DES_RD_ERR - Descriptor Read Error Flag
 *  0b0..No descriptor read error occurred.
 *  0b0..No effect
 *  0b1..A descriptor read error occurred.
 *  0b1..Clears the flag.
 */
#define JPGDECWRP_SLOT_STATUS_DES_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_DES_RD_ERR_SHIFT)) & JPGDECWRP_SLOT_STATUS_DES_RD_ERR_MASK)

#define JPGDECWRP_SLOT_STATUS_BIT_RD_ERR_MASK    (0x400U)
#define JPGDECWRP_SLOT_STATUS_BIT_RD_ERR_SHIFT   (10U)
/*! BIT_RD_ERR - Bit Read Error Flag
 *  0b0..No bit read error occurred.
 *  0b0..No effect
 *  0b1..A bit read error occurred.
 *  0b1..Clear the flag
 */
#define JPGDECWRP_SLOT_STATUS_BIT_RD_ERR(x)      (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_BIT_RD_ERR_SHIFT)) & JPGDECWRP_SLOT_STATUS_BIT_RD_ERR_MASK)

#define JPGDECWRP_SLOT_STATUS_PIXEL_WT_ERR_MASK  (0x800U)
#define JPGDECWRP_SLOT_STATUS_PIXEL_WT_ERR_SHIFT (11U)
/*! PIXEL_WT_ERR - Pixel Write Error Flag
 *  0b0..No effect
 *  0b0..No pixel write error occurred.
 *  0b1..A pixel write error occurred.
 *  0b1..Clears the flag.
 */
#define JPGDECWRP_SLOT_STATUS_PIXEL_WT_ERR(x)    (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_PIXEL_WT_ERR_SHIFT)) & JPGDECWRP_SLOT_STATUS_PIXEL_WT_ERR_MASK)

#define JPGDECWRP_SLOT_STATUS_CUR_SLOT_MASK      (0x60000000U)
#define JPGDECWRP_SLOT_STATUS_CUR_SLOT_SHIFT     (29U)
/*! CUR_SLOT - Current Slot */
#define JPGDECWRP_SLOT_STATUS_CUR_SLOT(x)        (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_CUR_SLOT_SHIFT)) & JPGDECWRP_SLOT_STATUS_CUR_SLOT_MASK)

#define JPGDECWRP_SLOT_STATUS_DEC_ONGOING_MASK   (0x80000000U)
#define JPGDECWRP_SLOT_STATUS_DEC_ONGOING_SHIFT  (31U)
/*! DEC_ONGOING - Decoding Ongoing
 *  0b0..Paused or stopped
 *  0b1..Ongoing
 */
#define JPGDECWRP_SLOT_STATUS_DEC_ONGOING(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_STATUS_DEC_ONGOING_SHIFT)) & JPGDECWRP_SLOT_STATUS_DEC_ONGOING_MASK)
/*! @} */

/* The count of JPGDECWRP_SLOT_STATUS */
#define JPGDECWRP_SLOT_STATUS_COUNT              (4U)

/*! @name SLOT_IRQ_EN - Bit Stream Interrupt Enable */
/*! @{ */

#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK (0x1U)
#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT (0U)
/*! STMBUF_HALF_IRQ_EN - Stream Buffer Half Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_STMBUF_HALF_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK (0x2U)
#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT (1U)
/*! STMBUF_RTND_IRQ_EN - Stream Buffer Returned Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_STMBUF_RTND_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK (0x4U)
#define JPGDECWRP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT (2U)
/*! SWITCHED_IN_IRQ_EN - Switched In Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_SWITCHED_IN_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK (0x8U)
#define JPGDECWRP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT (3U)
/*! FRMDONE_IRQ_EN - Frame Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_FRMDONE_IRQ_EN(x)  (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_FRMDONE_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK (0x100U)
#define JPGDECWRP_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT (8U)
/*! DECERR_IRQ_EN - Decoding Error Status Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_DECERR_IRQ_EN(x)   (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_DECERR_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_DECERR_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK (0x200U)
#define JPGDECWRP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT (9U)
/*! DES_RD_ERR_IRQ_EN - Descriptor Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_DES_RD_ERR_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK (0x400U)
#define JPGDECWRP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT (10U)
/*! BIT_RD_ERR_IRQ_EN - Bit Read Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_BIT_RD_ERR_IRQ_EN_MASK)

#define JPGDECWRP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK (0x800U)
#define JPGDECWRP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT (11U)
/*! PIXEL_WT_ERR_IRQ_EN - Pixel Write Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_SHIFT)) & JPGDECWRP_SLOT_IRQ_EN_PIXEL_WT_ERR_IRQ_EN_MASK)
/*! @} */

/* The count of JPGDECWRP_SLOT_IRQ_EN */
#define JPGDECWRP_SLOT_IRQ_EN_COUNT              (4U)

/*! @name SLOT_BUF_PTR - Bit Stream Buffer Pointer */
/*! @{ */

#define JPGDECWRP_SLOT_BUF_PTR_STMBUF_PTR_MASK   (0xFFFFFFFFU)
#define JPGDECWRP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT  (0U)
/*! STMBUF_PTR - Stream Buffer Pointer */
#define JPGDECWRP_SLOT_BUF_PTR_STMBUF_PTR(x)     (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_BUF_PTR_STMBUF_PTR_SHIFT)) & JPGDECWRP_SLOT_BUF_PTR_STMBUF_PTR_MASK)
/*! @} */

/* The count of JPGDECWRP_SLOT_BUF_PTR */
#define JPGDECWRP_SLOT_BUF_PTR_COUNT             (4U)

/*! @name SLOT_CUR_DESCPT_PTR - Current Descriptors */
/*! @{ */

#define JPGDECWRP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK (0xFFFFFFFCU)
#define JPGDECWRP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT (2U)
/*! CUR_DESCPT_PRT - Current Decoding Descriptor Pointer */
#define JPGDECWRP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_SHIFT)) & JPGDECWRP_SLOT_CUR_DESCPT_PTR_CUR_DESCPT_PRT_MASK)
/*! @} */

/* The count of JPGDECWRP_SLOT_CUR_DESCPT_PTR */
#define JPGDECWRP_SLOT_CUR_DESCPT_PTR_COUNT      (4U)

/*! @name SLOT_NXT_DESCPT_PTR - Next Descriptors */
/*! @{ */

#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK (0x1U)
#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT (0U)
/*! NXT_DESCPT_EN - Next Stream Descriptor Pointer Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_SHIFT)) & JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_EN_MASK)

#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK (0xFFFFFFFCU)
#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT (2U)
/*! NXT_DESCPT_PTR - Next Descriptor Pointer */
#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR(x) (((uint32_t)(((uint32_t)(x)) << JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_SHIFT)) & JPGDECWRP_SLOT_NXT_DESCPT_PTR_NXT_DESCPT_PTR_MASK)
/*! @} */

/* The count of JPGDECWRP_SLOT_NXT_DESCPT_PTR */
#define JPGDECWRP_SLOT_NXT_DESCPT_PTR_COUNT      (4U)


/*!
 * @}
 */ /* end of group JPGDECWRP_Register_Masks */


/*!
 * @}
 */ /* end of group JPGDECWRP_Peripheral_Access_Layer */


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


#endif  /* PERI_JPGDECWRP_H_ */

