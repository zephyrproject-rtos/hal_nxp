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
**         CMSIS Peripheral Access Layer for HTX_PVI
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
 * @file PERI_HTX_PVI.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for HTX_PVI
 *
 * CMSIS Peripheral Access Layer for HTX_PVI
 */

#if !defined(PERI_HTX_PVI_H_)
#define PERI_HTX_PVI_H_                          /**< Symbol preventing repeated inclusion */

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
   -- HTX_PVI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HTX_PVI_Peripheral_Access_Layer HTX_PVI Peripheral Access Layer
 * @{
 */

/** HTX_PVI - Register Layout Typedef */
typedef struct {
  __IO uint32_t HTX_PVI_CTRL;                      /**< HTX_PVI Control Reg, offset: 0x0 */
  __IO uint32_t HTX_PVI_IRQ_MASK;                  /**< Masks off the Interrupts, offset: 0x4 */
  __I  uint32_t HTX_PVI_IRQ_STATUS;                /**< Interrupt Status, offset: 0x8 */
  __IO uint32_t HTX_PVI_IRQ_CLR;                   /**< Interrupts, offset: 0xC */
  __IO uint32_t HTX_TMG_GEN_DISP_LRC;              /**< Display Coordinates, offset: 0x10 */
  __IO uint32_t HTX_TMG_GEN_DE_ULC;                /**< Data Enable Coordinates, offset: 0x14 */
  __IO uint32_t HTX_TMG_GEN_DE_LRC;                /**< Data Enable Coordinates, offset: 0x18 */
  __IO uint32_t HTX_TMG_GEN_HSYNC;                 /**< Hsync Start and End, offset: 0x1C */
  __IO uint32_t HTX_TMG_GEN_VSYNC;                 /**< Vsync Start and End, offset: 0x20 */
  __IO uint32_t HTX_TMG_GEN_IRQ0;                  /**< Controls the Position of first IRQ from Timing Generator, offset: 0x24 */
  __IO uint32_t HTX_TMG_GEN_IRQ1;                  /**< Controls the Position of Second IRQ from Timing Generator, offset: 0x28 */
  __IO uint32_t HTX_TMG_GEN_IRQ2;                  /**< Controls the Position of Third IRQ from Timing Generator, offset: 0x2C */
  __IO uint32_t HTX_TMG_GEN_IRQ3;                  /**< Controls the Position of Fourth IRQ from Timing Generator, offset: 0x30 */
  __IO uint32_t HTX_TMG_GEN_BG0;                   /**< Background Color insertion for R or Y, offset: 0x34 */
  __IO uint32_t HTX_TMG_GEN_BG1;                   /**< Background Color insertion for G or Cb, offset: 0x38 */
  __IO uint32_t HTX_TMG_GEN_BG2;                   /**< Background Color insertion for B or Cr, offset: 0x3C */
  __IO uint32_t HTX_TMG_GEN_CFG;                   /**< HStart and Vstart Delay Configuration, offset: 0x40 */
} HTX_PVI_Type;

/* ----------------------------------------------------------------------------
   -- HTX_PVI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup HTX_PVI_Register_Masks HTX_PVI Register Masks
 * @{
 */

/*! @name HTX_PVI_CTRL - HTX_PVI Control Reg */
/*! @{ */

#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_EN_MASK     (0x1U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_EN_SHIFT    (0U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_EN(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_HTX_PVI_EN_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_HTX_PVI_EN_MASK)

#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_MODE_MASK   (0x6U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_MODE_SHIFT  (1U)
/*! HTX_PVI_MODE - Selects the mode of operation in HTX PVI
 *  0b00..Select the DCSS Path
 *  0b01..Select the Bypass path from HDMI Rx
 *  0b10..Select the LCDIF Path
 *  0b11..Reserved
 */
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_MODE(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_HTX_PVI_MODE_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_HTX_PVI_MODE_MASK)

#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_UPSMPL_MASK (0x8U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_UPSMPL_SHIFT (3U)
/*! HTX_PVI_UPSMPL - Select the mode of upsample in case of 16bit output and 12bit input
 *  0b0..Fill LSB with 4'b0
 *  0b1..Fill LSB with MSB 4 bits, i.e. [11:8]
 */
#define HTX_PVI_HTX_PVI_CTRL_HTX_PVI_UPSMPL(x)   (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_HTX_PVI_UPSMPL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_HTX_PVI_UPSMPL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_DCSS_YUV420_MODE_MASK (0x10U)
#define HTX_PVI_HTX_PVI_CTRL_DCSS_YUV420_MODE_SHIFT (4U)
#define HTX_PVI_HTX_PVI_CTRL_DCSS_YUV420_MODE(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_DCSS_YUV420_MODE_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_DCSS_YUV420_MODE_MASK)

#define HTX_PVI_HTX_PVI_CTRL_HTX_PLB_EN_MASK     (0x20U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PLB_EN_SHIFT    (5U)
#define HTX_PVI_HTX_PVI_CTRL_HTX_PLB_EN(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_HTX_PLB_EN_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_HTX_PLB_EN_MASK)

#define HTX_PVI_HTX_PVI_CTRL_PIPE_MODE_MASK      (0xC0U)
#define HTX_PVI_HTX_PVI_CTRL_PIPE_MODE_SHIFT     (6U)
/*! PIPE_MODE - Sets the Timing Generator mode.
 *  0b00..bypass
 *  0b01..422 subsample
 *  0b10..420 subsample
 *  0b11..bypass
 */
#define HTX_PVI_HTX_PVI_CTRL_PIPE_MODE(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_PIPE_MODE_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_PIPE_MODE_MASK)

#define HTX_PVI_HTX_PVI_CTRL_VSYNC_SHIFT_MASK    (0x100U)
#define HTX_PVI_HTX_PVI_CTRL_VSYNC_SHIFT_SHIFT   (8U)
/*! VSYNC_SHIFT - VSYNC shift
 *  0b0..Run in general interlaced mode. Every other field the vsync is shifted forward 1/2 scan lines. In
 *       addition, the horizontal back porch is extended 1 scan line.
 *  0b1..Run in special interlaced format. This shifts vsync backwards 1/2 scan line every other field. Remaining timing won't change.
 */
#define HTX_PVI_HTX_PVI_CTRL_VSYNC_SHIFT(x)      (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_VSYNC_SHIFT_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_VSYNC_SHIFT_MASK)

#define HTX_PVI_HTX_PVI_CTRL_TMG_GEN_EN_MASK     (0x200U)
#define HTX_PVI_HTX_PVI_CTRL_TMG_GEN_EN_SHIFT    (9U)
/*! TMG_GEN_EN - Enable Timing Generator to insert the hsync and vsync.
 *  0b0..Disable
 *  0b1..Enable
 */
#define HTX_PVI_HTX_PVI_CTRL_TMG_GEN_EN(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_TMG_GEN_EN_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_TMG_GEN_EN_MASK)

#define HTX_PVI_HTX_PVI_CTRL_INTRLC_EN_MASK      (0x400U)
#define HTX_PVI_HTX_PVI_CTRL_INTRLC_EN_SHIFT     (10U)
/*! INTRLC_EN - Enable interlaced HDMI timing
 *  0b0..Disable
 *  0b1..Enable
 */
#define HTX_PVI_HTX_PVI_CTRL_INTRLC_EN(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_INTRLC_EN_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_INTRLC_EN_MASK)

#define HTX_PVI_HTX_PVI_CTRL_INP_DE_POL_MASK     (0x1000U)
#define HTX_PVI_HTX_PVI_CTRL_INP_DE_POL_SHIFT    (12U)
/*! INP_DE_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_INP_DE_POL(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_INP_DE_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_INP_DE_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_INP_HSYNC_POL_MASK  (0x2000U)
#define HTX_PVI_HTX_PVI_CTRL_INP_HSYNC_POL_SHIFT (13U)
/*! INP_HSYNC_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_INP_HSYNC_POL(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_INP_HSYNC_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_INP_HSYNC_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_INP_VSYNC_POL_MASK  (0x4000U)
#define HTX_PVI_HTX_PVI_CTRL_INP_VSYNC_POL_SHIFT (14U)
/*! INP_VSYNC_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_INP_VSYNC_POL(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_INP_VSYNC_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_INP_VSYNC_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_OP_DE_POL_MASK      (0x10000U)
#define HTX_PVI_HTX_PVI_CTRL_OP_DE_POL_SHIFT     (16U)
/*! OP_DE_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_OP_DE_POL(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_OP_DE_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_OP_DE_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_OP_HSYNC_POL_MASK   (0x20000U)
#define HTX_PVI_HTX_PVI_CTRL_OP_HSYNC_POL_SHIFT  (17U)
/*! OP_HSYNC_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_OP_HSYNC_POL(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_OP_HSYNC_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_OP_HSYNC_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_OP_VSYNC_POL_MASK   (0x40000U)
#define HTX_PVI_HTX_PVI_CTRL_OP_VSYNC_POL_SHIFT  (18U)
/*! OP_VSYNC_POL
 *  0b0..Active Low
 *  0b1..Active High
 */
#define HTX_PVI_HTX_PVI_CTRL_OP_VSYNC_POL(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_OP_VSYNC_POL_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_OP_VSYNC_POL_MASK)

#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_FDCC_MASK (0x100000U)
#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_FDCC_SHIFT (20U)
#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_FDCC(x)   (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_FDCC_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_FDCC_MASK)

#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_UNDRFLW_MASK (0x200000U)
#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_UNDRFLW_SHIFT (21U)
#define HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_UNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_UNDRFLW_SHIFT)) & HTX_PVI_HTX_PVI_CTRL_EN_BG_INS_UNDRFLW_MASK)
/*! @} */

/*! @name HTX_PVI_IRQ_MASK - Masks off the Interrupts */
/*! @{ */

#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_OVRFLW_MASK (0x1U)
#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_OVRFLW_SHIFT (0U)
#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_OVRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_OVRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_OVRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_UNDRFLW_MASK (0x2U)
#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_UNDRFLW_SHIFT (1U)
#define HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_UNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_UNDRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_MASK_ASYNC_FIFO_UNDRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_MASK_TMG_GEN_IRQ_MASK (0x3CU)
#define HTX_PVI_HTX_PVI_IRQ_MASK_TMG_GEN_IRQ_SHIFT (2U)
#define HTX_PVI_HTX_PVI_IRQ_MASK_TMG_GEN_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_MASK_TMG_GEN_IRQ_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_MASK_TMG_GEN_IRQ_MASK)
/*! @} */

/*! @name HTX_PVI_IRQ_STATUS - Interrupt Status */
/*! @{ */

#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_OVRFLW_MASK (0x1U)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_OVRFLW_SHIFT (0U)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_OVRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_OVRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_OVRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_UNDRFLW_MASK (0x2U)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_UNDRFLW_SHIFT (1U)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_UNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_UNDRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_STATUS_ASYNC_FIFO_UNDRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_STATUS_TMG_GEN_IRQ_MASK (0x3CU)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_TMG_GEN_IRQ_SHIFT (2U)
#define HTX_PVI_HTX_PVI_IRQ_STATUS_TMG_GEN_IRQ(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_STATUS_TMG_GEN_IRQ_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_STATUS_TMG_GEN_IRQ_MASK)
/*! @} */

/*! @name HTX_PVI_IRQ_CLR - Interrupts */
/*! @{ */

#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_OVRFLW_MASK (0x1U)
#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_OVRFLW_SHIFT (0U)
#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_OVRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_OVRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_OVRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_UNDRFLW_MASK (0x2U)
#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_UNDRFLW_SHIFT (1U)
#define HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_UNDRFLW(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_UNDRFLW_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_CLR_ASYNC_FIFO_UNDRFLW_MASK)

#define HTX_PVI_HTX_PVI_IRQ_CLR_TMG_GEN_IRQ_MASK (0x3CU)
#define HTX_PVI_HTX_PVI_IRQ_CLR_TMG_GEN_IRQ_SHIFT (2U)
#define HTX_PVI_HTX_PVI_IRQ_CLR_TMG_GEN_IRQ(x)   (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_PVI_IRQ_CLR_TMG_GEN_IRQ_SHIFT)) & HTX_PVI_HTX_PVI_IRQ_CLR_TMG_GEN_IRQ_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_DISP_LRC - Display Coordinates */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSY_MASK   (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSY_SHIFT  (0U)
#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSY(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSY_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSY_MASK)

#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSX_MASK   (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSX_SHIFT  (16U)
#define HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSX(x)     (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSX_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DISP_LRC_POSX_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_DE_ULC - Data Enable Coordinates */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSY_MASK     (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSY_SHIFT    (0U)
#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSY(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DE_ULC_POSY_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DE_ULC_POSY_MASK)

#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSX_MASK     (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSX_SHIFT    (16U)
#define HTX_PVI_HTX_TMG_GEN_DE_ULC_POSX(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DE_ULC_POSX_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DE_ULC_POSX_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_DE_LRC - Data Enable Coordinates */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSY_MASK     (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSY_SHIFT    (0U)
#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSY(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DE_LRC_POSY_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DE_LRC_POSY_MASK)

#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSX_MASK     (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSX_SHIFT    (16U)
#define HTX_PVI_HTX_TMG_GEN_DE_LRC_POSX(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_DE_LRC_POSX_SHIFT)) & HTX_PVI_HTX_TMG_GEN_DE_LRC_POSX_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_HSYNC - Hsync Start and End */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_HSYNC_END_MASK       (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_HSYNC_END_SHIFT      (0U)
#define HTX_PVI_HTX_TMG_GEN_HSYNC_END(x)         (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_HSYNC_END_SHIFT)) & HTX_PVI_HTX_TMG_GEN_HSYNC_END_MASK)

#define HTX_PVI_HTX_TMG_GEN_HSYNC_START_MASK     (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_HSYNC_START_SHIFT    (16U)
#define HTX_PVI_HTX_TMG_GEN_HSYNC_START(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_HSYNC_START_SHIFT)) & HTX_PVI_HTX_TMG_GEN_HSYNC_START_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_VSYNC - Vsync Start and End */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_VSYNC_END_MASK       (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_VSYNC_END_SHIFT      (0U)
#define HTX_PVI_HTX_TMG_GEN_VSYNC_END(x)         (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_VSYNC_END_SHIFT)) & HTX_PVI_HTX_TMG_GEN_VSYNC_END_MASK)

#define HTX_PVI_HTX_TMG_GEN_VSYNC_START_MASK     (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_VSYNC_START_SHIFT    (16U)
#define HTX_PVI_HTX_TMG_GEN_VSYNC_START(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_VSYNC_START_SHIFT)) & HTX_PVI_HTX_TMG_GEN_VSYNC_START_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_IRQ0 - Controls the Position of first IRQ from Timing Generator */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_Y_MASK      (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_Y_SHIFT     (0U)
#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_Y(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ0_POS_Y_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ0_POS_Y_MASK)

#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_X_MASK      (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_X_SHIFT     (16U)
#define HTX_PVI_HTX_TMG_GEN_IRQ0_POS_X(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ0_POS_X_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ0_POS_X_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_IRQ1 - Controls the Position of Second IRQ from Timing Generator */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_Y_MASK      (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_Y_SHIFT     (0U)
#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_Y(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ1_POS_Y_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ1_POS_Y_MASK)

#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_X_MASK      (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_X_SHIFT     (16U)
#define HTX_PVI_HTX_TMG_GEN_IRQ1_POS_X(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ1_POS_X_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ1_POS_X_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_IRQ2 - Controls the Position of Third IRQ from Timing Generator */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_Y_MASK      (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_Y_SHIFT     (0U)
#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_Y(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ2_POS_Y_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ2_POS_Y_MASK)

#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_X_MASK      (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_X_SHIFT     (16U)
#define HTX_PVI_HTX_TMG_GEN_IRQ2_POS_X(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ2_POS_X_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ2_POS_X_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_IRQ3 - Controls the Position of Fourth IRQ from Timing Generator */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_Y_MASK      (0xFFFFU)
#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_Y_SHIFT     (0U)
#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_Y(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ3_POS_Y_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ3_POS_Y_MASK)

#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_X_MASK      (0xFFFF0000U)
#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_X_SHIFT     (16U)
#define HTX_PVI_HTX_TMG_GEN_IRQ3_POS_X(x)        (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_IRQ3_POS_X_SHIFT)) & HTX_PVI_HTX_TMG_GEN_IRQ3_POS_X_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_BG0 - Background Color insertion for R or Y */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_BG0_DEF_VAL_MASK     (0xFFFU)
#define HTX_PVI_HTX_TMG_GEN_BG0_DEF_VAL_SHIFT    (0U)
#define HTX_PVI_HTX_TMG_GEN_BG0_DEF_VAL(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_BG0_DEF_VAL_SHIFT)) & HTX_PVI_HTX_TMG_GEN_BG0_DEF_VAL_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_BG1 - Background Color insertion for G or Cb */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_BG1_DEF_VAL_MASK     (0xFFFU)
#define HTX_PVI_HTX_TMG_GEN_BG1_DEF_VAL_SHIFT    (0U)
#define HTX_PVI_HTX_TMG_GEN_BG1_DEF_VAL(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_BG1_DEF_VAL_SHIFT)) & HTX_PVI_HTX_TMG_GEN_BG1_DEF_VAL_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_BG2 - Background Color insertion for B or Cr */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_BG2_DEF_VAL_MASK     (0xFFFU)
#define HTX_PVI_HTX_TMG_GEN_BG2_DEF_VAL_SHIFT    (0U)
#define HTX_PVI_HTX_TMG_GEN_BG2_DEF_VAL(x)       (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_BG2_DEF_VAL_SHIFT)) & HTX_PVI_HTX_TMG_GEN_BG2_DEF_VAL_MASK)
/*! @} */

/*! @name HTX_TMG_GEN_CFG - HStart and Vstart Delay Configuration */
/*! @{ */

#define HTX_PVI_HTX_TMG_GEN_CFG_H_STRT_DLY_MASK  (0x1FFFU)
#define HTX_PVI_HTX_TMG_GEN_CFG_H_STRT_DLY_SHIFT (0U)
#define HTX_PVI_HTX_TMG_GEN_CFG_H_STRT_DLY(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_CFG_H_STRT_DLY_SHIFT)) & HTX_PVI_HTX_TMG_GEN_CFG_H_STRT_DLY_MASK)

#define HTX_PVI_HTX_TMG_GEN_CFG_V_STRT_DLY_MASK  (0x1FFF0000U)
#define HTX_PVI_HTX_TMG_GEN_CFG_V_STRT_DLY_SHIFT (16U)
#define HTX_PVI_HTX_TMG_GEN_CFG_V_STRT_DLY(x)    (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_CFG_V_STRT_DLY_SHIFT)) & HTX_PVI_HTX_TMG_GEN_CFG_V_STRT_DLY_MASK)

#define HTX_PVI_HTX_TMG_GEN_CFG_EN_HS_DLY_STRT_MASK (0x40000000U)
#define HTX_PVI_HTX_TMG_GEN_CFG_EN_HS_DLY_STRT_SHIFT (30U)
#define HTX_PVI_HTX_TMG_GEN_CFG_EN_HS_DLY_STRT(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_CFG_EN_HS_DLY_STRT_SHIFT)) & HTX_PVI_HTX_TMG_GEN_CFG_EN_HS_DLY_STRT_MASK)

#define HTX_PVI_HTX_TMG_GEN_CFG_EN_VS_DLY_STRT_MASK (0x80000000U)
#define HTX_PVI_HTX_TMG_GEN_CFG_EN_VS_DLY_STRT_SHIFT (31U)
#define HTX_PVI_HTX_TMG_GEN_CFG_EN_VS_DLY_STRT(x) (((uint32_t)(((uint32_t)(x)) << HTX_PVI_HTX_TMG_GEN_CFG_EN_VS_DLY_STRT_SHIFT)) & HTX_PVI_HTX_TMG_GEN_CFG_EN_VS_DLY_STRT_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group HTX_PVI_Register_Masks */


/*!
 * @}
 */ /* end of group HTX_PVI_Peripheral_Access_Layer */


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


#endif  /* PERI_HTX_PVI_H_ */

