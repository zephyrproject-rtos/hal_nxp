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
**         CMSIS Peripheral Access Layer for PNGDEC
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
 * @file PERI_PNGDEC.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PNGDEC
 *
 * CMSIS Peripheral Access Layer for PNGDEC
 */

#if !defined(PERI_PNGDEC_H_)
#define PERI_PNGDEC_H_                           /**< Symbol preventing repeated inclusion */

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
   -- PNGDEC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PNGDEC_Peripheral_Access_Layer PNGDEC Peripheral Access Layer
 * @{
 */

/** PNGDEC - Register Layout Typedef */
typedef struct {
  __IO uint32_t GLB_CTRL;                          /**< Global Control, offset: 0x0 */
  __IO uint32_t DMA_TRIG;                          /**< DMA Trigger, offset: 0x4 */
  __IO uint32_t CNT_CTRL_CLR;                      /**< Count Control Clear, offset: 0x8 */
       uint8_t RESERVED_0[20];
  __IO uint32_t ENC_DATA_DMA_SRC_ADDR;             /**< Encode Data Source Address, offset: 0x20 */
  __IO uint32_t ENC_DATA_DMA_SRC_LEN;              /**< Encode Data Source Length, offset: 0x24 */
  __IO uint32_t DEC_PIXEL_DMA_DES_ADDR;            /**< Decode Pixel Destination Address, offset: 0x28 */
  __I  uint32_t DEC_PIXEL_DMA_DES_LEN;             /**< Decode Pixel Destination Length, offset: 0x2C */
  __IO uint32_t DEC_ANC_DMA_DES_ADDR;              /**< Decode Ancillary Destination Address, offset: 0x30 */
  __I  uint32_t DEC_ANC_DMA_DES_LEN;               /**< Decode Ancillary Destination Length, offset: 0x34 */
       uint8_t RESERVED_1[72];
  __IO uint32_t DEC_INT_STS;                       /**< Decode Interrupt Status, offset: 0x80 */
  __IO uint32_t DEC_INT_STS_EN;                    /**< Interrupt Enable, offset: 0x84 */
       uint8_t RESERVED_2[24];
  __I  uint32_t AXI3_ENC_DATA_RD_BYTE_CNT;         /**< AXI3 Encoded Data Read Bytes Counter, offset: 0xA0 */
  __I  uint32_t AXI3_DEC_PIXEL_WR_BYTE_CNT;        /**< AXI3 Decoded Pixel Write Bytes Counter, offset: 0xA4 */
  __I  uint32_t AXI3_DEC_ANC_WR_BYTE_CNT;          /**< AXI3 Decode Ancillary Write Bytes Counter, offset: 0xA8 */
} PNGDEC_Type;

/* ----------------------------------------------------------------------------
   -- PNGDEC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PNGDEC_Register_Masks PNGDEC Register Masks
 * @{
 */

/*! @name GLB_CTRL - Global Control */
/*! @{ */

#define PNGDEC_GLB_CTRL_DEC_EN_MASK              (0x1U)
#define PNGDEC_GLB_CTRL_DEC_EN_SHIFT             (0U)
/*! DEC_EN - Decode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_GLB_CTRL_DEC_EN(x)                (((uint32_t)(((uint32_t)(x)) << PNGDEC_GLB_CTRL_DEC_EN_SHIFT)) & PNGDEC_GLB_CTRL_DEC_EN_MASK)

#define PNGDEC_GLB_CTRL_ANC_DROP_EN_MASK         (0x2U)
#define PNGDEC_GLB_CTRL_ANC_DROP_EN_SHIFT        (1U)
/*! ANC_DROP_EN - Ancillary Data Drop Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_GLB_CTRL_ANC_DROP_EN(x)           (((uint32_t)(((uint32_t)(x)) << PNGDEC_GLB_CTRL_ANC_DROP_EN_SHIFT)) & PNGDEC_GLB_CTRL_ANC_DROP_EN_MASK)

#define PNGDEC_GLB_CTRL_DMA_SW_LOGIC_RST_EN_MASK (0x4U)
#define PNGDEC_GLB_CTRL_DMA_SW_LOGIC_RST_EN_SHIFT (2U)
/*! DMA_SW_LOGIC_RST_EN - DMA Software Logic Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_GLB_CTRL_DMA_SW_LOGIC_RST_EN(x)   (((uint32_t)(((uint32_t)(x)) << PNGDEC_GLB_CTRL_DMA_SW_LOGIC_RST_EN_SHIFT)) & PNGDEC_GLB_CTRL_DMA_SW_LOGIC_RST_EN_MASK)

#define PNGDEC_GLB_CTRL_IPCORE_SW_LOGIC_RST_EN_MASK (0x8U)
#define PNGDEC_GLB_CTRL_IPCORE_SW_LOGIC_RST_EN_SHIFT (3U)
/*! IPCORE_SW_LOGIC_RST_EN - Core Software Logic Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_GLB_CTRL_IPCORE_SW_LOGIC_RST_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_GLB_CTRL_IPCORE_SW_LOGIC_RST_EN_SHIFT)) & PNGDEC_GLB_CTRL_IPCORE_SW_LOGIC_RST_EN_MASK)
/*! @} */

/*! @name DMA_TRIG - DMA Trigger */
/*! @{ */

#define PNGDEC_DMA_TRIG_DMA_TRIG_MASK            (0x1U)
#define PNGDEC_DMA_TRIG_DMA_TRIG_SHIFT           (0U)
/*! DMA_TRIG - DMA Trigger
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DMA_TRIG_DMA_TRIG(x)              (((uint32_t)(((uint32_t)(x)) << PNGDEC_DMA_TRIG_DMA_TRIG_SHIFT)) & PNGDEC_DMA_TRIG_DMA_TRIG_MASK)
/*! @} */

/*! @name CNT_CTRL_CLR - Count Control Clear */
/*! @{ */

#define PNGDEC_CNT_CTRL_CLR_CNT_CTRL_CLR_MASK    (0x1U)
#define PNGDEC_CNT_CTRL_CLR_CNT_CTRL_CLR_SHIFT   (0U)
/*! CNT_CTRL_CLR - Count Control Clear
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_CNT_CTRL_CLR_CNT_CTRL_CLR(x)      (((uint32_t)(((uint32_t)(x)) << PNGDEC_CNT_CTRL_CLR_CNT_CTRL_CLR_SHIFT)) & PNGDEC_CNT_CTRL_CLR_CNT_CTRL_CLR_MASK)
/*! @} */

/*! @name ENC_DATA_DMA_SRC_ADDR - Encode Data Source Address */
/*! @{ */

#define PNGDEC_ENC_DATA_DMA_SRC_ADDR_SRC_ADDR_MASK (0xFFFFFFFFU)
#define PNGDEC_ENC_DATA_DMA_SRC_ADDR_SRC_ADDR_SHIFT (0U)
/*! SRC_ADDR - Source Address */
#define PNGDEC_ENC_DATA_DMA_SRC_ADDR_SRC_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_ENC_DATA_DMA_SRC_ADDR_SRC_ADDR_SHIFT)) & PNGDEC_ENC_DATA_DMA_SRC_ADDR_SRC_ADDR_MASK)
/*! @} */

/*! @name ENC_DATA_DMA_SRC_LEN - Encode Data Source Length */
/*! @{ */

#define PNGDEC_ENC_DATA_DMA_SRC_LEN_SRC_LEN_MASK (0xFFFFFFFFU)
#define PNGDEC_ENC_DATA_DMA_SRC_LEN_SRC_LEN_SHIFT (0U)
/*! SRC_LEN - Source Length */
#define PNGDEC_ENC_DATA_DMA_SRC_LEN_SRC_LEN(x)   (((uint32_t)(((uint32_t)(x)) << PNGDEC_ENC_DATA_DMA_SRC_LEN_SRC_LEN_SHIFT)) & PNGDEC_ENC_DATA_DMA_SRC_LEN_SRC_LEN_MASK)
/*! @} */

/*! @name DEC_PIXEL_DMA_DES_ADDR - Decode Pixel Destination Address */
/*! @{ */

#define PNGDEC_DEC_PIXEL_DMA_DES_ADDR_PIXEL_DES_ADDR_MASK (0xFFFFFFFFU)
#define PNGDEC_DEC_PIXEL_DMA_DES_ADDR_PIXEL_DES_ADDR_SHIFT (0U)
/*! PIXEL_DES_ADDR - Pixel Destination Address */
#define PNGDEC_DEC_PIXEL_DMA_DES_ADDR_PIXEL_DES_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_PIXEL_DMA_DES_ADDR_PIXEL_DES_ADDR_SHIFT)) & PNGDEC_DEC_PIXEL_DMA_DES_ADDR_PIXEL_DES_ADDR_MASK)
/*! @} */

/*! @name DEC_PIXEL_DMA_DES_LEN - Decode Pixel Destination Length */
/*! @{ */

#define PNGDEC_DEC_PIXEL_DMA_DES_LEN_PIXEL_DES_LEN_MASK (0xFFFFFFFFU)
#define PNGDEC_DEC_PIXEL_DMA_DES_LEN_PIXEL_DES_LEN_SHIFT (0U)
/*! PIXEL_DES_LEN - Pixel Destination Length */
#define PNGDEC_DEC_PIXEL_DMA_DES_LEN_PIXEL_DES_LEN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_PIXEL_DMA_DES_LEN_PIXEL_DES_LEN_SHIFT)) & PNGDEC_DEC_PIXEL_DMA_DES_LEN_PIXEL_DES_LEN_MASK)
/*! @} */

/*! @name DEC_ANC_DMA_DES_ADDR - Decode Ancillary Destination Address */
/*! @{ */

#define PNGDEC_DEC_ANC_DMA_DES_ADDR_ANC_DES_ADDR_MASK (0xFFFFFFFFU)
#define PNGDEC_DEC_ANC_DMA_DES_ADDR_ANC_DES_ADDR_SHIFT (0U)
/*! ANC_DES_ADDR - Ancillary Destination Address */
#define PNGDEC_DEC_ANC_DMA_DES_ADDR_ANC_DES_ADDR(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_ANC_DMA_DES_ADDR_ANC_DES_ADDR_SHIFT)) & PNGDEC_DEC_ANC_DMA_DES_ADDR_ANC_DES_ADDR_MASK)
/*! @} */

/*! @name DEC_ANC_DMA_DES_LEN - Decode Ancillary Destination Length */
/*! @{ */

#define PNGDEC_DEC_ANC_DMA_DES_LEN_ANC_DES_LEN_MASK (0xFFFFFFFFU)
#define PNGDEC_DEC_ANC_DMA_DES_LEN_ANC_DES_LEN_SHIFT (0U)
/*! ANC_DES_LEN - Ancillary Destination Length */
#define PNGDEC_DEC_ANC_DMA_DES_LEN_ANC_DES_LEN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_ANC_DMA_DES_LEN_ANC_DES_LEN_SHIFT)) & PNGDEC_DEC_ANC_DMA_DES_LEN_ANC_DES_LEN_MASK)
/*! @} */

/*! @name DEC_INT_STS - Decode Interrupt Status */
/*! @{ */

#define PNGDEC_DEC_INT_STS_ERR_ADLER_MASK        (0x1U)
#define PNGDEC_DEC_INT_STS_ERR_ADLER_SHIFT       (0U)
/*! ERR_ADLER - ADLER-32 Checksum Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_ADLER(x)          (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_ADLER_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_ADLER_MASK)

#define PNGDEC_DEC_INT_STS_ERR_CRC_MASK          (0x2U)
#define PNGDEC_DEC_INT_STS_ERR_CRC_SHIFT         (1U)
/*! ERR_CRC - CRC Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_CRC(x)            (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_CRC_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_CRC_MASK)

#define PNGDEC_DEC_INT_STS_ERR_PNG_HEADER_MASK   (0x4U)
#define PNGDEC_DEC_INT_STS_ERR_PNG_HEADER_SHIFT  (2U)
/*! ERR_PNG_HEADER - PNG Header Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_PNG_HEADER(x)     (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_PNG_HEADER_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_PNG_HEADER_MASK)

#define PNGDEC_DEC_INT_STS_ERR_BTYPE_MASK        (0x8U)
#define PNGDEC_DEC_INT_STS_ERR_BTYPE_SHIFT       (3U)
/*! ERR_BTYPE - B-type Error (Block Encoding Type Error in IDAT Chunk)
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_BTYPE(x)          (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_BTYPE_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_BTYPE_MASK)

#define PNGDEC_DEC_INT_STS_ERR_ZLIB_HEADER_MASK  (0x10U)
#define PNGDEC_DEC_INT_STS_ERR_ZLIB_HEADER_SHIFT (4U)
/*! ERR_ZLIB_HEADER - Zlib Header Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_ZLIB_HEADER(x)    (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_ZLIB_HEADER_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_ZLIB_HEADER_MASK)

#define PNGDEC_DEC_INT_STS_ERR_BITDEPTH_MASK     (0x20U)
#define PNGDEC_DEC_INT_STS_ERR_BITDEPTH_SHIFT    (5U)
/*! ERR_BITDEPTH - Bit Depth Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_BITDEPTH(x)       (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_BITDEPTH_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_BITDEPTH_MASK)

#define PNGDEC_DEC_INT_STS_ERR_INTERLACE_MASK    (0x40U)
#define PNGDEC_DEC_INT_STS_ERR_INTERLACE_SHIFT   (6U)
/*! ERR_INTERLACE - Interlace Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_INTERLACE(x)      (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_INTERLACE_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_INTERLACE_MASK)

#define PNGDEC_DEC_INT_STS_ERR_WIDTH_MASK        (0x80U)
#define PNGDEC_DEC_INT_STS_ERR_WIDTH_SHIFT       (7U)
/*! ERR_WIDTH - Width Error
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ERR_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ERR_WIDTH_SHIFT)) & PNGDEC_DEC_INT_STS_ERR_WIDTH_MASK)

#define PNGDEC_DEC_INT_STS_ENC_DATA_DMA_DONE_MASK (0x100U)
#define PNGDEC_DEC_INT_STS_ENC_DATA_DMA_DONE_SHIFT (8U)
/*! ENC_DATA_DMA_DONE - Encoded Data and DMA Copy Done
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_ENC_DATA_DMA_DONE(x)  (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_ENC_DATA_DMA_DONE_SHIFT)) & PNGDEC_DEC_INT_STS_ENC_DATA_DMA_DONE_MASK)

#define PNGDEC_DEC_INT_STS_DEC_PIXEL_DMA_DONE_MASK (0x200U)
#define PNGDEC_DEC_INT_STS_DEC_PIXEL_DMA_DONE_SHIFT (9U)
/*! DEC_PIXEL_DMA_DONE - Decode Pixel and DMA Copy Done
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_DEC_PIXEL_DMA_DONE(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_DEC_PIXEL_DMA_DONE_SHIFT)) & PNGDEC_DEC_INT_STS_DEC_PIXEL_DMA_DONE_MASK)

#define PNGDEC_DEC_INT_STS_DEC_ANC_DMA_DONE_MASK (0x400U)
#define PNGDEC_DEC_INT_STS_DEC_ANC_DMA_DONE_SHIFT (10U)
/*! DEC_ANC_DMA_DONE - Ancillary Decode and DMA Copy Done Flag
 *  0b0..No effect
 *  0b0..No interrupt occurred.
 *  0b1..Clears status flag.
 *  0b1..Interrupt occurred.
 */
#define PNGDEC_DEC_INT_STS_DEC_ANC_DMA_DONE(x)   (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_DEC_ANC_DMA_DONE_SHIFT)) & PNGDEC_DEC_INT_STS_DEC_ANC_DMA_DONE_MASK)
/*! @} */

/*! @name DEC_INT_STS_EN - Interrupt Enable */
/*! @{ */

#define PNGDEC_DEC_INT_STS_EN_ERR_ADLER_EN_MASK  (0x1U)
#define PNGDEC_DEC_INT_STS_EN_ERR_ADLER_EN_SHIFT (0U)
/*! ERR_ADLER_EN - ADLER-32 Checksum Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_ADLER_EN(x)    (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_ADLER_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_ADLER_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_CRC_EN_MASK    (0x2U)
#define PNGDEC_DEC_INT_STS_EN_ERR_CRC_EN_SHIFT   (1U)
/*! ERR_CRC_EN - CRC Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_CRC_EN(x)      (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_CRC_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_CRC_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_PNG_HEADER_EN_MASK (0x4U)
#define PNGDEC_DEC_INT_STS_EN_ERR_PNG_HEADER_EN_SHIFT (2U)
/*! ERR_PNG_HEADER_EN - PNG Header Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_PNG_HEADER_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_PNG_HEADER_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_PNG_HEADER_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_BTYPE_EN_MASK  (0x8U)
#define PNGDEC_DEC_INT_STS_EN_ERR_BTYPE_EN_SHIFT (3U)
/*! ERR_BTYPE_EN - B-Type Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_BTYPE_EN(x)    (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_BTYPE_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_BTYPE_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_ZLIB_HEADER_EN_MASK (0x10U)
#define PNGDEC_DEC_INT_STS_EN_ERR_ZLIB_HEADER_EN_SHIFT (4U)
/*! ERR_ZLIB_HEADER_EN - Zlib Header Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_ZLIB_HEADER_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_ZLIB_HEADER_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_ZLIB_HEADER_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_BITDEPTH_EN_MASK (0x20U)
#define PNGDEC_DEC_INT_STS_EN_ERR_BITDEPTH_EN_SHIFT (5U)
/*! ERR_BITDEPTH_EN - Bit Depth Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_BITDEPTH_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_BITDEPTH_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_BITDEPTH_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_INTERLACE_EN_MASK (0x40U)
#define PNGDEC_DEC_INT_STS_EN_ERR_INTERLACE_EN_SHIFT (6U)
/*! ERR_INTERLACE_EN - Interlace Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_INTERLACE_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_INTERLACE_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_INTERLACE_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ERR_WIDTH_EN_MASK  (0x80U)
#define PNGDEC_DEC_INT_STS_EN_ERR_WIDTH_EN_SHIFT (7U)
/*! ERR_WIDTH_EN - Width Error Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ERR_WIDTH_EN(x)    (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ERR_WIDTH_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ERR_WIDTH_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_ENC_DATA_DMA_DONE_EN_MASK (0x100U)
#define PNGDEC_DEC_INT_STS_EN_ENC_DATA_DMA_DONE_EN_SHIFT (8U)
/*! ENC_DATA_DMA_DONE_EN - Encoded Data and DMA Copy Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_ENC_DATA_DMA_DONE_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_ENC_DATA_DMA_DONE_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_ENC_DATA_DMA_DONE_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_DEC_PIXEL_DMA_DONE_EN_MASK (0x200U)
#define PNGDEC_DEC_INT_STS_EN_DEC_PIXEL_DMA_DONE_EN_SHIFT (9U)
/*! DEC_PIXEL_DMA_DONE_EN - Decode Pixel and DMA Copy Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_DEC_PIXEL_DMA_DONE_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_DEC_PIXEL_DMA_DONE_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_DEC_PIXEL_DMA_DONE_EN_MASK)

#define PNGDEC_DEC_INT_STS_EN_DEC_ANC_DMA_DONE_EN_MASK (0x400U)
#define PNGDEC_DEC_INT_STS_EN_DEC_ANC_DMA_DONE_EN_SHIFT (10U)
/*! DEC_ANC_DMA_DONE_EN - Ancillary Decode and DMA Copy Done Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define PNGDEC_DEC_INT_STS_EN_DEC_ANC_DMA_DONE_EN(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_DEC_INT_STS_EN_DEC_ANC_DMA_DONE_EN_SHIFT)) & PNGDEC_DEC_INT_STS_EN_DEC_ANC_DMA_DONE_EN_MASK)
/*! @} */

/*! @name AXI3_ENC_DATA_RD_BYTE_CNT - AXI3 Encoded Data Read Bytes Counter */
/*! @{ */

#define PNGDEC_AXI3_ENC_DATA_RD_BYTE_CNT_AXI3_ENC_RD_BYTE_MASK (0xFFFFFFFFU)
#define PNGDEC_AXI3_ENC_DATA_RD_BYTE_CNT_AXI3_ENC_RD_BYTE_SHIFT (0U)
/*! AXI3_ENC_RD_BYTE - AXI3 Encoded Data Read Bytes */
#define PNGDEC_AXI3_ENC_DATA_RD_BYTE_CNT_AXI3_ENC_RD_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_AXI3_ENC_DATA_RD_BYTE_CNT_AXI3_ENC_RD_BYTE_SHIFT)) & PNGDEC_AXI3_ENC_DATA_RD_BYTE_CNT_AXI3_ENC_RD_BYTE_MASK)
/*! @} */

/*! @name AXI3_DEC_PIXEL_WR_BYTE_CNT - AXI3 Decoded Pixel Write Bytes Counter */
/*! @{ */

#define PNGDEC_AXI3_DEC_PIXEL_WR_BYTE_CNT_AXI3_PIXEL_WR_BYTE_MASK (0xFFFFFFFFU)
#define PNGDEC_AXI3_DEC_PIXEL_WR_BYTE_CNT_AXI3_PIXEL_WR_BYTE_SHIFT (0U)
/*! AXI3_PIXEL_WR_BYTE - AXI3 Pixel Write Bytes */
#define PNGDEC_AXI3_DEC_PIXEL_WR_BYTE_CNT_AXI3_PIXEL_WR_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_AXI3_DEC_PIXEL_WR_BYTE_CNT_AXI3_PIXEL_WR_BYTE_SHIFT)) & PNGDEC_AXI3_DEC_PIXEL_WR_BYTE_CNT_AXI3_PIXEL_WR_BYTE_MASK)
/*! @} */

/*! @name AXI3_DEC_ANC_WR_BYTE_CNT - AXI3 Decode Ancillary Write Bytes Counter */
/*! @{ */

#define PNGDEC_AXI3_DEC_ANC_WR_BYTE_CNT_AXI3_ANC_WR_BYTE_MASK (0xFFFFFFFFU)
#define PNGDEC_AXI3_DEC_ANC_WR_BYTE_CNT_AXI3_ANC_WR_BYTE_SHIFT (0U)
/*! AXI3_ANC_WR_BYTE - AXI3 Ancillary Write Bytes */
#define PNGDEC_AXI3_DEC_ANC_WR_BYTE_CNT_AXI3_ANC_WR_BYTE(x) (((uint32_t)(((uint32_t)(x)) << PNGDEC_AXI3_DEC_ANC_WR_BYTE_CNT_AXI3_ANC_WR_BYTE_SHIFT)) & PNGDEC_AXI3_DEC_ANC_WR_BYTE_CNT_AXI3_ANC_WR_BYTE_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group PNGDEC_Register_Masks */


/*!
 * @}
 */ /* end of group PNGDEC_Peripheral_Access_Layer */


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


#endif  /* PERI_PNGDEC_H_ */

