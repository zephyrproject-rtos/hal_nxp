/*
** ###################################################################
**     Processors:          MIMXRT2660CHPAA
**                          MIMXRT2660CVVAA
**                          MIMXRT2660DHPAA
**                          MIMXRT2660DVVAA
**                          MIMXRT2660XHP8A
**                          MIMXRT2660XVV8A
**                          MIMXRT2661CHPAA
**                          MIMXRT2661CVVAA
**                          MIMXRT2661DHPAA
**                          MIMXRT2661DVVAA
**                          MIMXRT2661XHP8A
**                          MIMXRT2661XVV8A
**                          MIMXRT2662AHP8A
**                          MIMXRT2662AVV8A
**                          MIMXRT2662CHPAA
**                          MIMXRT2662CVVAA
**                          MIMXRT2662DHPAA
**                          MIMXRT2662DVVAA
**                          MIMXRT2662XHP8A
**                          MIMXRT2662XVV8A
**                          MIMXRT2663AHP8A
**                          MIMXRT2663AVV8A
**                          MIMXRT2663CHPAA
**                          MIMXRT2663CVVAA
**                          MIMXRT2663DHPAA
**                          MIMXRT2663DVVAA
**                          MIMXRT2663XHP8A
**                          MIMXRT2663XHPAA
**                          MIMXRT2663XVV8A
**                          MIMXRT2663XVVAA
**
**     Version:             rev. 1.0, 2024-11-05
**     Build:               b260818
**
**     Abstract:
**         CMSIS Peripheral Access Layer for CSI
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2026 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2024-11-05)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file PERI_CSI.h
 * @version 1.0
 * @date 2024-11-05
 * @brief CMSIS Peripheral Access Layer for CSI
 *
 * CMSIS Peripheral Access Layer for CSI
 */

#if !defined(PERI_CSI_H_)
#define PERI_CSI_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT2660CHPAA) || defined(CPU_MIMXRT2660CVVAA) || defined(CPU_MIMXRT2660DHPAA) || defined(CPU_MIMXRT2660DVVAA) || defined(CPU_MIMXRT2660XHP8A) || defined(CPU_MIMXRT2660XVV8A))
#include "MIMXRT2660_COMMON.h"
#elif (defined(CPU_MIMXRT2661CHPAA) || defined(CPU_MIMXRT2661CVVAA) || defined(CPU_MIMXRT2661DHPAA) || defined(CPU_MIMXRT2661DVVAA) || defined(CPU_MIMXRT2661XHP8A) || defined(CPU_MIMXRT2661XVV8A))
#include "MIMXRT2661_COMMON.h"
#elif (defined(CPU_MIMXRT2662AHP8A) || defined(CPU_MIMXRT2662AVV8A) || defined(CPU_MIMXRT2662CHPAA) || defined(CPU_MIMXRT2662CVVAA) || defined(CPU_MIMXRT2662DHPAA) || defined(CPU_MIMXRT2662DVVAA) || defined(CPU_MIMXRT2662XHP8A) || defined(CPU_MIMXRT2662XVV8A))
#include "MIMXRT2662_COMMON.h"
#elif (defined(CPU_MIMXRT2663AHP8A) || defined(CPU_MIMXRT2663AVV8A) || defined(CPU_MIMXRT2663CHPAA) || defined(CPU_MIMXRT2663CVVAA) || defined(CPU_MIMXRT2663DHPAA) || defined(CPU_MIMXRT2663DVVAA) || defined(CPU_MIMXRT2663XHP8A) || defined(CPU_MIMXRT2663XHPAA) || defined(CPU_MIMXRT2663XVV8A) || defined(CPU_MIMXRT2663XVVAA))
#include "MIMXRT2663_COMMON.h"
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
   -- CSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSI_Peripheral_Access_Layer CSI Peripheral Access Layer
 * @{
 */

/** CSI - Size of Registers Arrays */
#define CSI_CR_COUNT                              256u

/** CSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CR1;                               /**< CSI Control Register 1, offset: 0x0 */
  __IO uint32_t CR2;                               /**< CSI Control Register 2, offset: 0x4 */
  __IO uint32_t CR3;                               /**< CSI Control Register 3, offset: 0x8 */
  __I  uint32_t STATFIFO;                          /**< CSI Statistic FIFO Register, offset: 0xC */
  __I  uint32_t RFIFO;                             /**< CSI RX FIFO Register, offset: 0x10 */
  __IO uint32_t RXCNT;                             /**< CSI RX Count Register, offset: 0x14 */
  __IO uint32_t SR;                                /**< CSI Status Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t DMASA_STATFIFO;                    /**< CSI DMA Start Address Register - for STATFIFO, offset: 0x20 */
  __IO uint32_t DMATS_STATFIFO;                    /**< CSI DMA Transfer Size Register - for STATFIFO, offset: 0x24 */
  __IO uint32_t DMASA_FB1;                         /**< CSI DMA Start Address Register - for Frame Buffer1, offset: 0x28 */
  __IO uint32_t DMASA_FB2;                         /**< CSI DMA Start Address Register - for Frame Buffer2, offset: 0x2C */
  __IO uint32_t FBUF_PARA;                         /**< CSI Frame Buffer Parameter Register, offset: 0x30 */
  __IO uint32_t IMAG_PARA;                         /**< CSI Image Parameter Register, offset: 0x34 */
       uint8_t RESERVED_1[16];
  __IO uint32_t CR18;                              /**< CSI Control Register 18, offset: 0x48 */
  __IO uint32_t CR19;                              /**< CSI Control Register 19, offset: 0x4C */
  __IO uint32_t CR20;                              /**< CSI Control Register 20, offset: 0x50 */
  __IO uint32_t CR[CSI_CR_COUNT];                  /**< CSI Control Register, array offset: 0x54, array step: 0x4 */
} CSI_Type;

/* ----------------------------------------------------------------------------
   -- CSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSI_Register_Masks CSI Register Masks
 * @{
 */

/*! @name CR1 - CSI Control Register 1 */
/*! @{ */

#define CSI_CR1_PIXEL_BIT_MASK                   (0x1U)
#define CSI_CR1_PIXEL_BIT_SHIFT                  (0U)
/*! PIXEL_BIT - Pixel Bit
 *  0b0..8-bit data for each pixel
 *  0b1..10-bit data for each pixel
 */
#define CSI_CR1_PIXEL_BIT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_PIXEL_BIT_SHIFT)) & CSI_CR1_PIXEL_BIT_MASK)

#define CSI_CR1_REDGE_MASK                       (0x2U)
#define CSI_CR1_REDGE_SHIFT                      (1U)
/*! REDGE - Valid Pixel Clock Edge Select
 *  0b0..Pixel data is latched at the falling edge of CSI_PIXCLK
 *  0b1..Pixel data is latched at the rising edge of CSI_PIXCLK
 */
#define CSI_CR1_REDGE(x)                         (((uint32_t)(((uint32_t)(x)) << CSI_CR1_REDGE_SHIFT)) & CSI_CR1_REDGE_MASK)

#define CSI_CR1_INV_PCLK_MASK                    (0x4U)
#define CSI_CR1_INV_PCLK_SHIFT                   (2U)
/*! INV_PCLK - Invert Pixel Clock Input
 *  0b0..CSI_PIXCLK is directly applied to internal circuitry
 *  0b1..CSI_PIXCLK is inverted before applied to internal circuitry
 */
#define CSI_CR1_INV_PCLK(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CR1_INV_PCLK_SHIFT)) & CSI_CR1_INV_PCLK_MASK)

#define CSI_CR1_INV_DATA_MASK                    (0x8U)
#define CSI_CR1_INV_DATA_SHIFT                   (3U)
/*! INV_DATA - Invert Data Input
 *  0b0..CSI_D[7:0] data lines are directly applied to internal circuitry
 *  0b1..CSI_D[7:0] data lines are inverted before applied to internal circuitry
 */
#define CSI_CR1_INV_DATA(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CR1_INV_DATA_SHIFT)) & CSI_CR1_INV_DATA_MASK)

#define CSI_CR1_GCLK_MODE_MASK                   (0x10U)
#define CSI_CR1_GCLK_MODE_SHIFT                  (4U)
/*! GCLK_MODE - Gated Clock Mode Enable
 *  0b0..Non-gated clock mode. All incoming pixel clocks are valid. HSYNC is ignored.
 *  0b1..Gated clock mode. Pixel clock signal is valid only when HSYNC is active.
 */
#define CSI_CR1_GCLK_MODE(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_GCLK_MODE_SHIFT)) & CSI_CR1_GCLK_MODE_MASK)

#define CSI_CR1_CLR_RXFIFO_MASK                  (0x20U)
#define CSI_CR1_CLR_RXFIFO_SHIFT                 (5U)
/*! CLR_RXFIFO - Asynchronous RXFIFO Clear */
#define CSI_CR1_CLR_RXFIFO(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR1_CLR_RXFIFO_SHIFT)) & CSI_CR1_CLR_RXFIFO_MASK)

#define CSI_CR1_CLR_STATFIFO_MASK                (0x40U)
#define CSI_CR1_CLR_STATFIFO_SHIFT               (6U)
/*! CLR_STATFIFO - Asynchronous STATFIFO Clear */
#define CSI_CR1_CLR_STATFIFO(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR1_CLR_STATFIFO_SHIFT)) & CSI_CR1_CLR_STATFIFO_MASK)

#define CSI_CR1_PACK_DIR_MASK                    (0x80U)
#define CSI_CR1_PACK_DIR_SHIFT                   (7U)
/*! PACK_DIR - Data Packing Direction
 *  0b0..Pack from LSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x44332211 in RX FIFO. For
 *       stat data, 0xAAAA, 0xBBBB, it will appear as 0xBBBBAAAA in STAT FIFO.
 *  0b1..Pack from MSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x11223344 in RX FIFO. For
 *       stat data, 0xAAAA, 0xBBBB, it will appear as 0xAAAABBBB in STAT FIFO.
 */
#define CSI_CR1_PACK_DIR(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CR1_PACK_DIR_SHIFT)) & CSI_CR1_PACK_DIR_MASK)

#define CSI_CR1_FCC_MASK                         (0x100U)
#define CSI_CR1_FCC_SHIFT                        (8U)
/*! FCC - FIFO Clear Control
 *  0b0..Asynchronous FIFO clear is selected.
 *  0b1..Synchronous FIFO clear is selected.
 */
#define CSI_CR1_FCC(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR1_FCC_SHIFT)) & CSI_CR1_FCC_MASK)

#define CSI_CR1_CCIR_EN_MASK                     (0x400U)
#define CSI_CR1_CCIR_EN_SHIFT                    (10U)
/*! CCIR_EN - BT.656 Interface Enable
 *  0b0..Traditional interface is selected.
 *  0b1..BT.656 interface is selected.
 */
#define CSI_CR1_CCIR_EN(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_CR1_CCIR_EN_SHIFT)) & CSI_CR1_CCIR_EN_MASK)

#define CSI_CR1_HSYNC_POL_MASK                   (0x800U)
#define CSI_CR1_HSYNC_POL_SHIFT                  (11U)
/*! HSYNC_POL - HSYNC Polarity Select
 *  0b0..HSYNC is active low
 *  0b1..HSYNC is active high
 */
#define CSI_CR1_HSYNC_POL(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_HSYNC_POL_SHIFT)) & CSI_CR1_HSYNC_POL_MASK)

#define CSI_CR1_HISTOGRAM_CALC_DONE_IE_MASK      (0x1000U)
#define CSI_CR1_HISTOGRAM_CALC_DONE_IE_SHIFT     (12U)
/*! HISTOGRAM_CALC_DONE_IE - Histogram Interrupt Enable
 *  0b0..Histogram done interrupt disable
 *  0b1..Histogram done interrupt enable
 */
#define CSI_CR1_HISTOGRAM_CALC_DONE_IE(x)        (((uint32_t)(((uint32_t)(x)) << CSI_CR1_HISTOGRAM_CALC_DONE_IE_SHIFT)) & CSI_CR1_HISTOGRAM_CALC_DONE_IE_MASK)

#define CSI_CR1_SOF_INTEN_MASK                   (0x10000U)
#define CSI_CR1_SOF_INTEN_SHIFT                  (16U)
/*! SOF_INTEN - Start Of Frame (SOF) Interrupt Enable
 *  0b0..SOF interrupt disable
 *  0b1..SOF interrupt enable
 */
#define CSI_CR1_SOF_INTEN(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_SOF_INTEN_SHIFT)) & CSI_CR1_SOF_INTEN_MASK)

#define CSI_CR1_SOF_POL_MASK                     (0x20000U)
#define CSI_CR1_SOF_POL_SHIFT                    (17U)
/*! SOF_POL - SOF Interrupt Polarity
 *  0b0..SOF interrupt is generated on SOF falling edge
 *  0b1..SOF interrupt is generated on SOF rising edge
 */
#define CSI_CR1_SOF_POL(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_CR1_SOF_POL_SHIFT)) & CSI_CR1_SOF_POL_MASK)

#define CSI_CR1_RXFF_INTEN_MASK                  (0x40000U)
#define CSI_CR1_RXFF_INTEN_SHIFT                 (18U)
/*! RXFF_INTEN - RxFIFO Full Interrupt Enable
 *  0b0..RxFIFO full interrupt disable
 *  0b1..RxFIFO full interrupt enable
 */
#define CSI_CR1_RXFF_INTEN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR1_RXFF_INTEN_SHIFT)) & CSI_CR1_RXFF_INTEN_MASK)

#define CSI_CR1_FB1_DMA_DONE_INTEN_MASK          (0x80000U)
#define CSI_CR1_FB1_DMA_DONE_INTEN_SHIFT         (19U)
/*! FB1_DMA_DONE_INTEN - Frame Buffer1 DMA Transfer Done Interrupt Enable
 *  0b0..Frame Buffer1 DMA Transfer Done interrupt disable
 *  0b1..Frame Buffer1 DMA Transfer Done interrupt enable
 */
#define CSI_CR1_FB1_DMA_DONE_INTEN(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CR1_FB1_DMA_DONE_INTEN_SHIFT)) & CSI_CR1_FB1_DMA_DONE_INTEN_MASK)

#define CSI_CR1_FB2_DMA_DONE_INTEN_MASK          (0x100000U)
#define CSI_CR1_FB2_DMA_DONE_INTEN_SHIFT         (20U)
/*! FB2_DMA_DONE_INTEN - Frame Buffer2 DMA Transfer Done Interrupt Enable
 *  0b0..Frame Buffer2 DMA Transfer Done interrupt disable
 *  0b1..Frame Buffer2 DMA Transfer Done interrupt enable
 */
#define CSI_CR1_FB2_DMA_DONE_INTEN(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CR1_FB2_DMA_DONE_INTEN_SHIFT)) & CSI_CR1_FB2_DMA_DONE_INTEN_MASK)

#define CSI_CR1_STATFF_INTEN_MASK                (0x200000U)
#define CSI_CR1_STATFF_INTEN_SHIFT               (21U)
/*! STATFF_INTEN - STATFIFO Full Interrupt Enable
 *  0b0..STATFIFO full interrupt disable
 *  0b1..STATFIFO full interrupt enable
 */
#define CSI_CR1_STATFF_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR1_STATFF_INTEN_SHIFT)) & CSI_CR1_STATFF_INTEN_MASK)

#define CSI_CR1_SFF_DMA_DONE_INTEN_MASK          (0x400000U)
#define CSI_CR1_SFF_DMA_DONE_INTEN_SHIFT         (22U)
/*! SFF_DMA_DONE_INTEN - STATFIFO DMA Transfer Done Interrupt Enable
 *  0b0..STATFIFO DMA Transfer Done interrupt disable
 *  0b1..STATFIFO DMA Transfer Done interrupt enable
 */
#define CSI_CR1_SFF_DMA_DONE_INTEN(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CR1_SFF_DMA_DONE_INTEN_SHIFT)) & CSI_CR1_SFF_DMA_DONE_INTEN_MASK)

#define CSI_CR1_RF_OR_INTEN_MASK                 (0x1000000U)
#define CSI_CR1_RF_OR_INTEN_SHIFT                (24U)
/*! RF_OR_INTEN - RxFIFO Overrun Interrupt Enable
 *  0b0..RxFIFO overrun interrupt is disabled
 *  0b1..RxFIFO overrun interrupt is enabled
 */
#define CSI_CR1_RF_OR_INTEN(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CR1_RF_OR_INTEN_SHIFT)) & CSI_CR1_RF_OR_INTEN_MASK)

#define CSI_CR1_SF_OR_INTEN_MASK                 (0x2000000U)
#define CSI_CR1_SF_OR_INTEN_SHIFT                (25U)
/*! SF_OR_INTEN - STAT FIFO Overrun Interrupt Enable
 *  0b0..STATFIFO overrun interrupt is disabled
 *  0b1..STATFIFO overrun interrupt is enabled
 */
#define CSI_CR1_SF_OR_INTEN(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CR1_SF_OR_INTEN_SHIFT)) & CSI_CR1_SF_OR_INTEN_MASK)

#define CSI_CR1_COF_INT_EN_MASK                  (0x4000000U)
#define CSI_CR1_COF_INT_EN_SHIFT                 (26U)
/*! COF_INT_EN - Change Of Image Field (COF) Interrupt Enable
 *  0b0..COF interrupt is disabled
 *  0b1..COF interrupt is enabled
 */
#define CSI_CR1_COF_INT_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR1_COF_INT_EN_SHIFT)) & CSI_CR1_COF_INT_EN_MASK)

#define CSI_CR1_VIDEO_MODE_MASK                  (0x8000000U)
#define CSI_CR1_VIDEO_MODE_SHIFT                 (27U)
/*! VIDEO_MODE - Video mode select
 *  0b0..Progressive mode is selected
 *  0b1..Interlace mode is selected
 */
#define CSI_CR1_VIDEO_MODE(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR1_VIDEO_MODE_SHIFT)) & CSI_CR1_VIDEO_MODE_MASK)

#define CSI_CR1_EOF_INT_EN_MASK                  (0x20000000U)
#define CSI_CR1_EOF_INT_EN_SHIFT                 (29U)
/*! EOF_INT_EN - End-of-Frame Interrupt Enable
 *  0b0..EOF interrupt is disabled.
 *  0b1..EOF interrupt is generated when RX count value is reached.
 */
#define CSI_CR1_EOF_INT_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR1_EOF_INT_EN_SHIFT)) & CSI_CR1_EOF_INT_EN_MASK)

#define CSI_CR1_EXT_VSYNC_MASK                   (0x40000000U)
#define CSI_CR1_EXT_VSYNC_SHIFT                  (30U)
/*! EXT_VSYNC - External VSYNC Enable
 *  0b0..Internal VSYNC mode
 *  0b1..External VSYNC mode
 */
#define CSI_CR1_EXT_VSYNC(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_EXT_VSYNC_SHIFT)) & CSI_CR1_EXT_VSYNC_MASK)

#define CSI_CR1_SWAP16_EN_MASK                   (0x80000000U)
#define CSI_CR1_SWAP16_EN_SHIFT                  (31U)
/*! SWAP16_EN - SWAP 16-Bit Enable
 *  0b0..Disable swapping
 *  0b1..Enable swapping
 */
#define CSI_CR1_SWAP16_EN(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CR1_SWAP16_EN_SHIFT)) & CSI_CR1_SWAP16_EN_MASK)
/*! @} */

/*! @name CR2 - CSI Control Register 2 */
/*! @{ */

#define CSI_CR2_HSC_MASK                         (0xFFU)
#define CSI_CR2_HSC_SHIFT                        (0U)
/*! HSC - Horizontal Skip Count
 *  0b00000000-0b11111111..Number of pixels to skip minus 1
 */
#define CSI_CR2_HSC(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_HSC_SHIFT)) & CSI_CR2_HSC_MASK)

#define CSI_CR2_VSC_MASK                         (0xFF00U)
#define CSI_CR2_VSC_SHIFT                        (8U)
/*! VSC - Vertical Skip Count
 *  0b00000000-0b11111111..Number of rows to skip minus 1
 */
#define CSI_CR2_VSC(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_VSC_SHIFT)) & CSI_CR2_VSC_MASK)

#define CSI_CR2_LVRM_MASK                        (0x70000U)
#define CSI_CR2_LVRM_SHIFT                       (16U)
/*! LVRM - Live View Resolution Mode
 *  0b000..512 x 384
 *  0b001..448 x 336
 *  0b010..384 x 288
 *  0b011..384 x 256
 *  0b100..320 x 240
 *  0b101..288 x 216
 *  0b110..400 x 300
 */
#define CSI_CR2_LVRM(x)                          (((uint32_t)(((uint32_t)(x)) << CSI_CR2_LVRM_SHIFT)) & CSI_CR2_LVRM_MASK)

#define CSI_CR2_BTS_MASK                         (0x180000U)
#define CSI_CR2_BTS_SHIFT                        (19U)
/*! BTS - Bayer Tile Start
 *  0b00..GR
 *  0b01..RG
 *  0b10..BG
 *  0b11..GB
 */
#define CSI_CR2_BTS(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_BTS_SHIFT)) & CSI_CR2_BTS_MASK)

#define CSI_CR2_SCE_MASK                         (0x800000U)
#define CSI_CR2_SCE_SHIFT                        (23U)
/*! SCE - Skip Count Enable
 *  0b0..Skip count disable
 *  0b1..Skip count enable
 */
#define CSI_CR2_SCE(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_SCE_SHIFT)) & CSI_CR2_SCE_MASK)

#define CSI_CR2_AFS_MASK                         (0x3000000U)
#define CSI_CR2_AFS_SHIFT                        (24U)
/*! AFS - Auto Focus Spread
 *  0b00..Abs Diff on consecutive green pixels
 *  0b01..Abs Diff on every third green pixels
 *  0b1x..Abs Diff on every four green pixels
 */
#define CSI_CR2_AFS(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_AFS_SHIFT)) & CSI_CR2_AFS_MASK)

#define CSI_CR2_DRM_MASK                         (0x4000000U)
#define CSI_CR2_DRM_SHIFT                        (26U)
/*! DRM - Double Resolution Mode
 *  0b0..Stats grid of 8 x 6
 *  0b1..Stats grid of 8 x 12
 */
#define CSI_CR2_DRM(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_CR2_DRM_SHIFT)) & CSI_CR2_DRM_MASK)

#define CSI_CR2_DMA_BURST_TYPE_SFF_MASK          (0x30000000U)
#define CSI_CR2_DMA_BURST_TYPE_SFF_SHIFT         (28U)
/*! DMA_BURST_TYPE_SFF - Burst Type of DMA Transfer from STATFIFO
 *  0b01..INCR4
 *  0b11..INCR16
 *  0bx0..INCR8
 */
#define CSI_CR2_DMA_BURST_TYPE_SFF(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CR2_DMA_BURST_TYPE_SFF_SHIFT)) & CSI_CR2_DMA_BURST_TYPE_SFF_MASK)

#define CSI_CR2_DMA_BURST_TYPE_RFF_MASK          (0xC0000000U)
#define CSI_CR2_DMA_BURST_TYPE_RFF_SHIFT         (30U)
/*! DMA_BURST_TYPE_RFF - Burst Type of DMA Transfer from RxFIFO
 *  0b01..INCR4
 *  0b11..INCR16
 *  0bx0..INCR8
 */
#define CSI_CR2_DMA_BURST_TYPE_RFF(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CR2_DMA_BURST_TYPE_RFF_SHIFT)) & CSI_CR2_DMA_BURST_TYPE_RFF_MASK)
/*! @} */

/*! @name CR3 - CSI Control Register 3 */
/*! @{ */

#define CSI_CR3_ECC_AUTO_EN_MASK                 (0x1U)
#define CSI_CR3_ECC_AUTO_EN_SHIFT                (0U)
/*! ECC_AUTO_EN - Automatic Error Correction Enable
 *  0b0..Auto Error correction is disabled.
 *  0b1..Auto Error correction is enabled.
 */
#define CSI_CR3_ECC_AUTO_EN(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CR3_ECC_AUTO_EN_SHIFT)) & CSI_CR3_ECC_AUTO_EN_MASK)

#define CSI_CR3_ECC_INT_EN_MASK                  (0x2U)
#define CSI_CR3_ECC_INT_EN_SHIFT                 (1U)
/*! ECC_INT_EN - Error Detection Interrupt Enable
 *  0b0..No interrupt is generated when error is detected. Only the status bit ECC_INT is set.
 *  0b1..Interrupt is generated when error is detected.
 */
#define CSI_CR3_ECC_INT_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR3_ECC_INT_EN_SHIFT)) & CSI_CR3_ECC_INT_EN_MASK)

#define CSI_CR3_ZERO_PACK_EN_MASK                (0x4U)
#define CSI_CR3_ZERO_PACK_EN_SHIFT               (2U)
/*! ZERO_PACK_EN - Dummy Zero Packing Enable
 *  0b0..Zero packing disabled
 *  0b1..Zero packing enabled
 */
#define CSI_CR3_ZERO_PACK_EN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR3_ZERO_PACK_EN_SHIFT)) & CSI_CR3_ZERO_PACK_EN_MASK)

#define CSI_CR3_SENSOR_16BITS_MASK               (0x8U)
#define CSI_CR3_SENSOR_16BITS_SHIFT              (3U)
/*! SENSOR_16BITS - 16-bit Sensor Mode
 *  0b0..Only one 8-bit sensor is connected.
 *  0b1..One 16-bit sensor is connected.
 */
#define CSI_CR3_SENSOR_16BITS(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CR3_SENSOR_16BITS_SHIFT)) & CSI_CR3_SENSOR_16BITS_MASK)

#define CSI_CR3_RxFF_LEVEL_MASK                  (0x70U)
#define CSI_CR3_RxFF_LEVEL_SHIFT                 (4U)
/*! RxFF_LEVEL - RxFIFO Full Level
 *  0b000..4 Double words
 *  0b001..8 Double words
 *  0b010..16 Double words
 *  0b011..24 Double words
 *  0b100..32 Double words
 *  0b101..48 Double words
 *  0b110..64 Double words
 *  0b111..96 Double words
 */
#define CSI_CR3_RxFF_LEVEL(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR3_RxFF_LEVEL_SHIFT)) & CSI_CR3_RxFF_LEVEL_MASK)

#define CSI_CR3_HRESP_ERR_EN_MASK                (0x80U)
#define CSI_CR3_HRESP_ERR_EN_SHIFT               (7U)
/*! HRESP_ERR_EN - Hresponse Error Enable
 *  0b0..Disable hresponse error interrupt
 *  0b1..Enable hresponse error interrupt
 */
#define CSI_CR3_HRESP_ERR_EN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR3_HRESP_ERR_EN_SHIFT)) & CSI_CR3_HRESP_ERR_EN_MASK)

#define CSI_CR3_STATFF_LEVEL_MASK                (0x700U)
#define CSI_CR3_STATFF_LEVEL_SHIFT               (8U)
/*! STATFF_LEVEL - STATFIFO Full Level
 *  0b000..4 Double words
 *  0b001..8 Double words
 *  0b010..12 Double words
 *  0b011..16 Double words
 *  0b100..24 Double words
 *  0b101..32 Double words
 *  0b110..48 Double words
 *  0b111..64 Double words
 */
#define CSI_CR3_STATFF_LEVEL(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR3_STATFF_LEVEL_SHIFT)) & CSI_CR3_STATFF_LEVEL_MASK)

#define CSI_CR3_DMA_REQ_EN_SFF_MASK              (0x800U)
#define CSI_CR3_DMA_REQ_EN_SFF_SHIFT             (11U)
/*! DMA_REQ_EN_SFF - DMA Request Enable for STATFIFO
 *  0b0..Disable the dma request
 *  0b1..Enable the dma request
 */
#define CSI_CR3_DMA_REQ_EN_SFF(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CR3_DMA_REQ_EN_SFF_SHIFT)) & CSI_CR3_DMA_REQ_EN_SFF_MASK)

#define CSI_CR3_DMA_REQ_EN_RFF_MASK              (0x1000U)
#define CSI_CR3_DMA_REQ_EN_RFF_SHIFT             (12U)
/*! DMA_REQ_EN_RFF - DMA Request Enable for RxFIFO
 *  0b0..Disable the dma request
 *  0b1..Enable the dma request
 */
#define CSI_CR3_DMA_REQ_EN_RFF(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CR3_DMA_REQ_EN_RFF_SHIFT)) & CSI_CR3_DMA_REQ_EN_RFF_MASK)

#define CSI_CR3_DMA_REFLASH_SFF_MASK             (0x2000U)
#define CSI_CR3_DMA_REFLASH_SFF_SHIFT            (13U)
/*! DMA_REFLASH_SFF - Reflash DMA Controller for STATFIFO
 *  0b0..No reflashing
 *  0b1..Reflash the embedded DMA controller
 */
#define CSI_CR3_DMA_REFLASH_SFF(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR3_DMA_REFLASH_SFF_SHIFT)) & CSI_CR3_DMA_REFLASH_SFF_MASK)

#define CSI_CR3_DMA_REFLASH_RFF_MASK             (0x4000U)
#define CSI_CR3_DMA_REFLASH_RFF_SHIFT            (14U)
/*! DMA_REFLASH_RFF - Reflash DMA Controller for RxFIFO
 *  0b0..No reflashing
 *  0b1..Reflash the embedded DMA controller
 */
#define CSI_CR3_DMA_REFLASH_RFF(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR3_DMA_REFLASH_RFF_SHIFT)) & CSI_CR3_DMA_REFLASH_RFF_MASK)

#define CSI_CR3_FRMCNT_RST_MASK                  (0x8000U)
#define CSI_CR3_FRMCNT_RST_SHIFT                 (15U)
/*! FRMCNT_RST - Frame Count Reset
 *  0b0..Do not reset
 *  0b1..Reset frame counter immediately
 */
#define CSI_CR3_FRMCNT_RST(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR3_FRMCNT_RST_SHIFT)) & CSI_CR3_FRMCNT_RST_MASK)

#define CSI_CR3_FRMCNT_MASK                      (0xFFFF0000U)
#define CSI_CR3_FRMCNT_SHIFT                     (16U)
/*! FRMCNT - Frame Counter */
#define CSI_CR3_FRMCNT(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CR3_FRMCNT_SHIFT)) & CSI_CR3_FRMCNT_MASK)
/*! @} */

/*! @name STATFIFO - CSI Statistic FIFO Register */
/*! @{ */

#define CSI_STATFIFO_STAT_MASK                   (0xFFFFFFFFU)
#define CSI_STATFIFO_STAT_SHIFT                  (0U)
/*! STAT - Static data from sensor */
#define CSI_STATFIFO_STAT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_STATFIFO_STAT_SHIFT)) & CSI_STATFIFO_STAT_MASK)
/*! @} */

/*! @name RFIFO - CSI RX FIFO Register */
/*! @{ */

#define CSI_RFIFO_IMAGE_MASK                     (0xFFFFFFFFU)
#define CSI_RFIFO_IMAGE_SHIFT                    (0U)
/*! IMAGE - Received image data */
#define CSI_RFIFO_IMAGE(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_RFIFO_IMAGE_SHIFT)) & CSI_RFIFO_IMAGE_MASK)
/*! @} */

/*! @name RXCNT - CSI RX Count Register */
/*! @{ */

#define CSI_RXCNT_RXCNT_MASK                     (0x3FFFFFU)
#define CSI_RXCNT_RXCNT_SHIFT                    (0U)
/*! RXCNT - RxFIFO Count */
#define CSI_RXCNT_RXCNT(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_RXCNT_RXCNT_SHIFT)) & CSI_RXCNT_RXCNT_MASK)
/*! @} */

/*! @name SR - CSI Status Register */
/*! @{ */

#define CSI_SR_DRDY_MASK                         (0x1U)
#define CSI_SR_DRDY_SHIFT                        (0U)
/*! DRDY - RXFIFO Data Ready
 *  0b0..No data (word) is ready
 *  0b1..At least 1 datum (word) is ready in RXFIFO.
 */
#define CSI_SR_DRDY(x)                           (((uint32_t)(((uint32_t)(x)) << CSI_SR_DRDY_SHIFT)) & CSI_SR_DRDY_MASK)

#define CSI_SR_ECC_INT_MASK                      (0x2U)
#define CSI_SR_ECC_INT_SHIFT                     (1U)
/*! ECC_INT - BT.656 Error Interrupt
 *  0b0..No error detected
 *  0b1..Error is detected in BT.656 coding
 */
#define CSI_SR_ECC_INT(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_SR_ECC_INT_SHIFT)) & CSI_SR_ECC_INT_MASK)

#define CSI_SR_HISTOGRAM_CALC_DONE_INT_MASK      (0x4U)
#define CSI_SR_HISTOGRAM_CALC_DONE_INT_SHIFT     (2U)
/*! HISTOGRAM_CALC_DONE_INT - HISTOGRAM_CALC_DONE_INT
 *  0b0..Histogram calculation is not finished
 *  0b1..Histogram calculation is done and driver can access the PIXEL_COUNTERS(CSI_CSICR21~CSI_CSICR276) to get the gray level
 */
#define CSI_SR_HISTOGRAM_CALC_DONE_INT(x)        (((uint32_t)(((uint32_t)(x)) << CSI_SR_HISTOGRAM_CALC_DONE_INT_SHIFT)) & CSI_SR_HISTOGRAM_CALC_DONE_INT_MASK)

#define CSI_SR_HRESP_ERR_INT_MASK                (0x80U)
#define CSI_SR_HRESP_ERR_INT_SHIFT               (7U)
/*! HRESP_ERR_INT - Hresponse Error Interrupt Status
 *  0b0..No hresponse error.
 *  0b1..Hresponse error is detected.
 */
#define CSI_SR_HRESP_ERR_INT(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_SR_HRESP_ERR_INT_SHIFT)) & CSI_SR_HRESP_ERR_INT_MASK)

#define CSI_SR_COF_INT_MASK                      (0x2000U)
#define CSI_SR_COF_INT_SHIFT                     (13U)
/*! COF_INT - Change Of Field Interrupt Status
 *  0b0..Video field has no change.
 *  0b1..Change of video field is detected.
 */
#define CSI_SR_COF_INT(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_SR_COF_INT_SHIFT)) & CSI_SR_COF_INT_MASK)

#define CSI_SR_F1_INT_MASK                       (0x4000U)
#define CSI_SR_F1_INT_SHIFT                      (14U)
/*! F1_INT - BT.656 Field 1 Interrupt Status
 *  0b0..Field 1 of video is not detected.
 *  0b1..Field 1 of video is about to start.
 */
#define CSI_SR_F1_INT(x)                         (((uint32_t)(((uint32_t)(x)) << CSI_SR_F1_INT_SHIFT)) & CSI_SR_F1_INT_MASK)

#define CSI_SR_F2_INT_MASK                       (0x8000U)
#define CSI_SR_F2_INT_SHIFT                      (15U)
/*! F2_INT - BT.656 Field 2 Interrupt Status
 *  0b0..Field 2 of video is not detected
 *  0b1..Field 2 of video is about to start
 */
#define CSI_SR_F2_INT(x)                         (((uint32_t)(((uint32_t)(x)) << CSI_SR_F2_INT_SHIFT)) & CSI_SR_F2_INT_MASK)

#define CSI_SR_SOF_INT_MASK                      (0x10000U)
#define CSI_SR_SOF_INT_SHIFT                     (16U)
/*! SOF_INT - Start of Frame Interrupt Status
 *  0b0..SOF is not detected.
 *  0b1..SOF is detected.
 */
#define CSI_SR_SOF_INT(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_SR_SOF_INT_SHIFT)) & CSI_SR_SOF_INT_MASK)

#define CSI_SR_EOF_INT_MASK                      (0x20000U)
#define CSI_SR_EOF_INT_SHIFT                     (17U)
/*! EOF_INT - End of Frame (EOF) Interrupt Status
 *  0b0..EOF is not detected.
 *  0b1..EOF is detected.
 */
#define CSI_SR_EOF_INT(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_SR_EOF_INT_SHIFT)) & CSI_SR_EOF_INT_MASK)

#define CSI_SR_RxFF_INT_MASK                     (0x40000U)
#define CSI_SR_RxFF_INT_SHIFT                    (18U)
/*! RxFF_INT - RXFIFO Full Interrupt Status
 *  0b0..RxFIFO is not full.
 *  0b1..RxFIFO is full.
 */
#define CSI_SR_RxFF_INT(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_SR_RxFF_INT_SHIFT)) & CSI_SR_RxFF_INT_MASK)

#define CSI_SR_DMA_TSF_DONE_FB1_MASK             (0x80000U)
#define CSI_SR_DMA_TSF_DONE_FB1_SHIFT            (19U)
/*! DMA_TSF_DONE_FB1 - DMA Transfer Done in Frame Buffer1
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_SR_DMA_TSF_DONE_FB1(x)               (((uint32_t)(((uint32_t)(x)) << CSI_SR_DMA_TSF_DONE_FB1_SHIFT)) & CSI_SR_DMA_TSF_DONE_FB1_MASK)

#define CSI_SR_DMA_TSF_DONE_FB2_MASK             (0x100000U)
#define CSI_SR_DMA_TSF_DONE_FB2_SHIFT            (20U)
/*! DMA_TSF_DONE_FB2 - DMA Transfer Done in Frame Buffer2
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_SR_DMA_TSF_DONE_FB2(x)               (((uint32_t)(((uint32_t)(x)) << CSI_SR_DMA_TSF_DONE_FB2_SHIFT)) & CSI_SR_DMA_TSF_DONE_FB2_MASK)

#define CSI_SR_STATFF_INT_MASK                   (0x200000U)
#define CSI_SR_STATFF_INT_SHIFT                  (21U)
/*! STATFF_INT - STATFIFO Full Interrupt Status
 *  0b0..STATFIFO is not full.
 *  0b1..STATFIFO is full.
 */
#define CSI_SR_STATFF_INT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_SR_STATFF_INT_SHIFT)) & CSI_SR_STATFF_INT_MASK)

#define CSI_SR_DMA_TSF_DONE_SFF_MASK             (0x400000U)
#define CSI_SR_DMA_TSF_DONE_SFF_SHIFT            (22U)
/*! DMA_TSF_DONE_SFF - DMA Transfer Done from StatFIFO
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_SR_DMA_TSF_DONE_SFF(x)               (((uint32_t)(((uint32_t)(x)) << CSI_SR_DMA_TSF_DONE_SFF_SHIFT)) & CSI_SR_DMA_TSF_DONE_SFF_MASK)

#define CSI_SR_RF_OR_INT_MASK                    (0x1000000U)
#define CSI_SR_RF_OR_INT_SHIFT                   (24U)
/*! RF_OR_INT - RxFIFO Overrun Interrupt Status
 *  0b0..RXFIFO has not overflowed.
 *  0b1..RXFIFO has overflowed.
 */
#define CSI_SR_RF_OR_INT(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_SR_RF_OR_INT_SHIFT)) & CSI_SR_RF_OR_INT_MASK)

#define CSI_SR_SF_OR_INT_MASK                    (0x2000000U)
#define CSI_SR_SF_OR_INT_SHIFT                   (25U)
/*! SF_OR_INT - STATFIFO Overrun Interrupt Status
 *  0b0..STATFIFO has not overflowed.
 *  0b1..STATFIFO has overflowed.
 */
#define CSI_SR_SF_OR_INT(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_SR_SF_OR_INT_SHIFT)) & CSI_SR_SF_OR_INT_MASK)

#define CSI_SR_DMA_FIELD1_DONE_MASK              (0x4000000U)
#define CSI_SR_DMA_FIELD1_DONE_SHIFT             (26U)
/*! DMA_FIELD1_DONE - DMA_FIELD1_DONE */
#define CSI_SR_DMA_FIELD1_DONE(x)                (((uint32_t)(((uint32_t)(x)) << CSI_SR_DMA_FIELD1_DONE_SHIFT)) & CSI_SR_DMA_FIELD1_DONE_MASK)

#define CSI_SR_DMA_FIELD0_DONE_MASK              (0x8000000U)
#define CSI_SR_DMA_FIELD0_DONE_SHIFT             (27U)
/*! DMA_FIELD0_DONE - DMA_FIELD0_DONE */
#define CSI_SR_DMA_FIELD0_DONE(x)                (((uint32_t)(((uint32_t)(x)) << CSI_SR_DMA_FIELD0_DONE_SHIFT)) & CSI_SR_DMA_FIELD0_DONE_MASK)

#define CSI_SR_BASEADDR_CHHANGE_ERROR_MASK       (0x10000000U)
#define CSI_SR_BASEADDR_CHHANGE_ERROR_SHIFT      (28U)
/*! BASEADDR_CHHANGE_ERROR - BASEADDR_CHHANGE_ERROR */
#define CSI_SR_BASEADDR_CHHANGE_ERROR(x)         (((uint32_t)(((uint32_t)(x)) << CSI_SR_BASEADDR_CHHANGE_ERROR_SHIFT)) & CSI_SR_BASEADDR_CHHANGE_ERROR_MASK)
/*! @} */

/*! @name DMASA_STATFIFO - CSI DMA Start Address Register - for STATFIFO */
/*! @{ */

#define CSI_DMASA_STATFIFO_DMA_START_ADDR_SFF_MASK (0xFFFFFFF8U)
#define CSI_DMASA_STATFIFO_DMA_START_ADDR_SFF_SHIFT (3U)
/*! DMA_START_ADDR_SFF - DMA Start Address for STATFIFO */
#define CSI_DMASA_STATFIFO_DMA_START_ADDR_SFF(x) (((uint32_t)(((uint32_t)(x)) << CSI_DMASA_STATFIFO_DMA_START_ADDR_SFF_SHIFT)) & CSI_DMASA_STATFIFO_DMA_START_ADDR_SFF_MASK)
/*! @} */

/*! @name DMATS_STATFIFO - CSI DMA Transfer Size Register - for STATFIFO */
/*! @{ */

#define CSI_DMATS_STATFIFO_DMA_TSF_SIZE_SFF_MASK (0xFFFFFFFFU)
#define CSI_DMATS_STATFIFO_DMA_TSF_SIZE_SFF_SHIFT (0U)
/*! DMA_TSF_SIZE_SFF - DMA Transfer Size for STATFIFO */
#define CSI_DMATS_STATFIFO_DMA_TSF_SIZE_SFF(x)   (((uint32_t)(((uint32_t)(x)) << CSI_DMATS_STATFIFO_DMA_TSF_SIZE_SFF_SHIFT)) & CSI_DMATS_STATFIFO_DMA_TSF_SIZE_SFF_MASK)
/*! @} */

/*! @name DMASA_FB1 - CSI DMA Start Address Register - for Frame Buffer1 */
/*! @{ */

#define CSI_DMASA_FB1_DMA_START_ADDR_FB1_MASK    (0xFFFFFFF8U)
#define CSI_DMASA_FB1_DMA_START_ADDR_FB1_SHIFT   (3U)
/*! DMA_START_ADDR_FB1 - DMA Start Address in Frame Buffer1 */
#define CSI_DMASA_FB1_DMA_START_ADDR_FB1(x)      (((uint32_t)(((uint32_t)(x)) << CSI_DMASA_FB1_DMA_START_ADDR_FB1_SHIFT)) & CSI_DMASA_FB1_DMA_START_ADDR_FB1_MASK)
/*! @} */

/*! @name DMASA_FB2 - CSI DMA Start Address Register - for Frame Buffer2 */
/*! @{ */

#define CSI_DMASA_FB2_DMA_START_ADDR_FB2_MASK    (0xFFFFFFF8U)
#define CSI_DMASA_FB2_DMA_START_ADDR_FB2_SHIFT   (3U)
/*! DMA_START_ADDR_FB2 - DMA Start Address in Frame Buffer2 */
#define CSI_DMASA_FB2_DMA_START_ADDR_FB2(x)      (((uint32_t)(((uint32_t)(x)) << CSI_DMASA_FB2_DMA_START_ADDR_FB2_SHIFT)) & CSI_DMASA_FB2_DMA_START_ADDR_FB2_MASK)
/*! @} */

/*! @name FBUF_PARA - CSI Frame Buffer Parameter Register */
/*! @{ */

#define CSI_FBUF_PARA_FBUF_STRIDE_MASK           (0xFFFFU)
#define CSI_FBUF_PARA_FBUF_STRIDE_SHIFT          (0U)
/*! FBUF_STRIDE - Frame Buffer Parameter */
#define CSI_FBUF_PARA_FBUF_STRIDE(x)             (((uint32_t)(((uint32_t)(x)) << CSI_FBUF_PARA_FBUF_STRIDE_SHIFT)) & CSI_FBUF_PARA_FBUF_STRIDE_MASK)

#define CSI_FBUF_PARA_DEINTERLACE_STRIDE_MASK    (0xFFFF0000U)
#define CSI_FBUF_PARA_DEINTERLACE_STRIDE_SHIFT   (16U)
/*! DEINTERLACE_STRIDE - DEINTERLACE_STRIDE */
#define CSI_FBUF_PARA_DEINTERLACE_STRIDE(x)      (((uint32_t)(((uint32_t)(x)) << CSI_FBUF_PARA_DEINTERLACE_STRIDE_SHIFT)) & CSI_FBUF_PARA_DEINTERLACE_STRIDE_MASK)
/*! @} */

/*! @name IMAG_PARA - CSI Image Parameter Register */
/*! @{ */

#define CSI_IMAG_PARA_IMAGE_HEIGHT_MASK          (0xFFFFU)
#define CSI_IMAG_PARA_IMAGE_HEIGHT_SHIFT         (0U)
/*! IMAGE_HEIGHT - Image Height */
#define CSI_IMAG_PARA_IMAGE_HEIGHT(x)            (((uint32_t)(((uint32_t)(x)) << CSI_IMAG_PARA_IMAGE_HEIGHT_SHIFT)) & CSI_IMAG_PARA_IMAGE_HEIGHT_MASK)

#define CSI_IMAG_PARA_IMAGE_WIDTH_MASK           (0xFFFF0000U)
#define CSI_IMAG_PARA_IMAGE_WIDTH_SHIFT          (16U)
/*! IMAGE_WIDTH - Image Width */
#define CSI_IMAG_PARA_IMAGE_WIDTH(x)             (((uint32_t)(((uint32_t)(x)) << CSI_IMAG_PARA_IMAGE_WIDTH_SHIFT)) & CSI_IMAG_PARA_IMAGE_WIDTH_MASK)
/*! @} */

/*! @name CR18 - CSI Control Register 18 */
/*! @{ */

#define CSI_CR18_NTSC_EN_MASK                    (0x1U)
#define CSI_CR18_NTSC_EN_SHIFT                   (0U)
/*! NTSC_EN - NTSC_EN
 *  0b0..PAL
 *  0b1..NTSC
 */
#define CSI_CR18_NTSC_EN(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CR18_NTSC_EN_SHIFT)) & CSI_CR18_NTSC_EN_MASK)

#define CSI_CR18_TVDECODER_IN_EN_MASK            (0x2U)
#define CSI_CR18_TVDECODER_IN_EN_SHIFT           (1U)
/*! TVDECODER_IN_EN - TVDECODER_IN_EN */
#define CSI_CR18_TVDECODER_IN_EN(x)              (((uint32_t)(((uint32_t)(x)) << CSI_CR18_TVDECODER_IN_EN_SHIFT)) & CSI_CR18_TVDECODER_IN_EN_MASK)

#define CSI_CR18_DEINTERLACE_EN_MASK             (0x4U)
#define CSI_CR18_DEINTERLACE_EN_SHIFT            (2U)
/*! DEINTERLACE_EN - DEINTERLACE_EN
 *  0b0..Deinterlace disabled
 *  0b1..Deinterlace enabled
 */
#define CSI_CR18_DEINTERLACE_EN(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR18_DEINTERLACE_EN_SHIFT)) & CSI_CR18_DEINTERLACE_EN_MASK)

#define CSI_CR18_PARALLEL24_EN_MASK              (0x8U)
#define CSI_CR18_PARALLEL24_EN_SHIFT             (3U)
/*! PARALLEL24_EN - PARALLEL24_EN
 *  0b0..Input is disabled
 *  0b1..Input is enabled
 */
#define CSI_CR18_PARALLEL24_EN(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CR18_PARALLEL24_EN_SHIFT)) & CSI_CR18_PARALLEL24_EN_MASK)

#define CSI_CR18_BASEADDR_SWITCH_EN_MASK         (0x10U)
#define CSI_CR18_BASEADDR_SWITCH_EN_SHIFT        (4U)
/*! BASEADDR_SWITCH_EN - BASEADDR_SWITCH_EN */
#define CSI_CR18_BASEADDR_SWITCH_EN(x)           (((uint32_t)(((uint32_t)(x)) << CSI_CR18_BASEADDR_SWITCH_EN_SHIFT)) & CSI_CR18_BASEADDR_SWITCH_EN_MASK)

#define CSI_CR18_BASEADDR_SWITCH_SEL_MASK        (0x20U)
#define CSI_CR18_BASEADDR_SWITCH_SEL_SHIFT       (5U)
/*! BASEADDR_SWITCH_SEL - BASEADDR_SWITCH_SEL
 *  0b0..Switching base address at the edge of the vsync
 *  0b1..Switching base address at the edge of the first data of each frame
 */
#define CSI_CR18_BASEADDR_SWITCH_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CSI_CR18_BASEADDR_SWITCH_SEL_SHIFT)) & CSI_CR18_BASEADDR_SWITCH_SEL_MASK)

#define CSI_CR18_FIELD0_DONE_IE_MASK             (0x40U)
#define CSI_CR18_FIELD0_DONE_IE_SHIFT            (6U)
/*! FIELD0_DONE_IE - FIELD0_DONE_IE
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CSI_CR18_FIELD0_DONE_IE(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR18_FIELD0_DONE_IE_SHIFT)) & CSI_CR18_FIELD0_DONE_IE_MASK)

#define CSI_CR18_DMA_FIELD1_DONE_IE_MASK         (0x80U)
#define CSI_CR18_DMA_FIELD1_DONE_IE_SHIFT        (7U)
/*! DMA_FIELD1_DONE_IE - DMA_FIELD1_DONE_IE
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CSI_CR18_DMA_FIELD1_DONE_IE(x)           (((uint32_t)(((uint32_t)(x)) << CSI_CR18_DMA_FIELD1_DONE_IE_SHIFT)) & CSI_CR18_DMA_FIELD1_DONE_IE_MASK)

#define CSI_CR18_LAST_DMA_REQ_SEL_MASK           (0x100U)
#define CSI_CR18_LAST_DMA_REQ_SEL_SHIFT          (8U)
/*! LAST_DMA_REQ_SEL - LAST_DMA_REQ_SEL
 *  0b0..fifo_full_level
 *  0b1..hburst_length
 */
#define CSI_CR18_LAST_DMA_REQ_SEL(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CR18_LAST_DMA_REQ_SEL_SHIFT)) & CSI_CR18_LAST_DMA_REQ_SEL_MASK)

#define CSI_CR18_BASEADDR_CHANGE_ERROR_IE_MASK   (0x200U)
#define CSI_CR18_BASEADDR_CHANGE_ERROR_IE_SHIFT  (9U)
/*! BASEADDR_CHANGE_ERROR_IE - BASEADDR_CHANGE_ERROR_IE
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CSI_CR18_BASEADDR_CHANGE_ERROR_IE(x)     (((uint32_t)(((uint32_t)(x)) << CSI_CR18_BASEADDR_CHANGE_ERROR_IE_SHIFT)) & CSI_CR18_BASEADDR_CHANGE_ERROR_IE_MASK)

#define CSI_CR18_RGB888A_FORMAT_SEL_MASK         (0x400U)
#define CSI_CR18_RGB888A_FORMAT_SEL_SHIFT        (10U)
/*! RGB888A_FORMAT_SEL - RGB888A_FORMAT_SEL
 *  0b0..{8'h0, data[23:0]}
 *  0b1..{data[23:0], 8'h0}
 */
#define CSI_CR18_RGB888A_FORMAT_SEL(x)           (((uint32_t)(((uint32_t)(x)) << CSI_CR18_RGB888A_FORMAT_SEL_SHIFT)) & CSI_CR18_RGB888A_FORMAT_SEL_MASK)

#define CSI_CR18_AHB_HPROT_MASK                  (0xF000U)
#define CSI_CR18_AHB_HPROT_SHIFT                 (12U)
/*! AHB_HPROT - AHB_HPROT */
#define CSI_CR18_AHB_HPROT(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR18_AHB_HPROT_SHIFT)) & CSI_CR18_AHB_HPROT_MASK)

#define CSI_CR18_MASK_OPTION_MASK                (0xC0000U)
#define CSI_CR18_MASK_OPTION_SHIFT               (18U)
/*! MASK_OPTION - MASK_OPTION
 *  0b00..Writing to memory (OCRAM or external DDR) from first completely frame, when using this option, the CSI_ENABLE should be 1.
 *  0b01..Writing to memory when CSI_ENABLE is 1.
 *  0b10..Writing to memory from second completely frame, when using this option, the CSI_ENABLE should be 1.
 *  0b11..Writing to memory when data comes in, not matter the CSI_ENABLE is 1 or 0.
 */
#define CSI_CR18_MASK_OPTION(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CR18_MASK_OPTION_SHIFT)) & CSI_CR18_MASK_OPTION_MASK)

#define CSI_CR18_CSI_ENABLE_MASK                 (0x80000000U)
#define CSI_CR18_CSI_ENABLE_SHIFT                (31U)
/*! CSI_ENABLE - CSI_ENABLE */
#define CSI_CR18_CSI_ENABLE(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CR18_CSI_ENABLE_SHIFT)) & CSI_CR18_CSI_ENABLE_MASK)
/*! @} */

/*! @name CR19 - CSI Control Register 19 */
/*! @{ */

#define CSI_CR19_DMA_RFIFO_HIGHEST_FIFO_LEVEL_MASK (0xFFU)
#define CSI_CR19_DMA_RFIFO_HIGHEST_FIFO_LEVEL_SHIFT (0U)
/*! DMA_RFIFO_HIGHEST_FIFO_LEVEL - DMA_RFIFO_HIGHEST_FIFO_LEVEL */
#define CSI_CR19_DMA_RFIFO_HIGHEST_FIFO_LEVEL(x) (((uint32_t)(((uint32_t)(x)) << CSI_CR19_DMA_RFIFO_HIGHEST_FIFO_LEVEL_SHIFT)) & CSI_CR19_DMA_RFIFO_HIGHEST_FIFO_LEVEL_MASK)
/*! @} */

/*! @name CR20 - CSI Control Register 20 */
/*! @{ */

#define CSI_CR20_THRESHOLD_MASK                  (0xFFU)
#define CSI_CR20_THRESHOLD_SHIFT                 (0U)
/*! THRESHOLD - THRESHOLD */
#define CSI_CR20_THRESHOLD(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR20_THRESHOLD_SHIFT)) & CSI_CR20_THRESHOLD_MASK)

#define CSI_CR20_BINARY_EN_MASK                  (0x100U)
#define CSI_CR20_BINARY_EN_SHIFT                 (8U)
/*! BINARY_EN - BINARY_EN
 *  0b0..Output is Y8 format(8 bits each pixel)
 *  0b1..Output is Y1 format(1 bit each pixel)
 */
#define CSI_CR20_BINARY_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR20_BINARY_EN_SHIFT)) & CSI_CR20_BINARY_EN_MASK)

#define CSI_CR20_QR_DATA_FORMAT_MASK             (0xE00U)
#define CSI_CR20_QR_DATA_FORMAT_SHIFT            (9U)
/*! QR_DATA_FORMAT - QR_DATA_FORMAT
 *  0b000..YU YV one cycle per 1 pixel input
 *  0b001..UY VY one cycle per1 pixel input
 *  0b010..Y U Y V two cycles per 1 pixel input
 *  0b011..U Y V Y two cycles per 1 pixel input
 *  0b100..YUV one cycle per 1 pixel input
 *  0b101..Y U V three cycles per 1 pixel input
 */
#define CSI_CR20_QR_DATA_FORMAT(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR20_QR_DATA_FORMAT_SHIFT)) & CSI_CR20_QR_DATA_FORMAT_MASK)

#define CSI_CR20_BIG_END_MASK                    (0x1000U)
#define CSI_CR20_BIG_END_SHIFT                   (12U)
/*! BIG_END - BIG_END
 *  0b0..The newest (most recent) data will be assigned the lowest position when store to memory.
 *  0b1..The newest (most recent) data will be assigned the highest position when store to memory.
 */
#define CSI_CR20_BIG_END(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CR20_BIG_END_SHIFT)) & CSI_CR20_BIG_END_MASK)

#define CSI_CR20_TEN_BIT_NEW_EN_MASK             (0x20000000U)
#define CSI_CR20_TEN_BIT_NEW_EN_SHIFT            (29U)
/*! TEN_BIT_NEW_EN - 10BIT_NEW_EN
 *  0b0..When input 8bits data, it will use the data[9:2]
 *  0b1..If input is 10bits data, it will use the data[7:0] (optional)
 */
#define CSI_CR20_TEN_BIT_NEW_EN(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CR20_TEN_BIT_NEW_EN_SHIFT)) & CSI_CR20_TEN_BIT_NEW_EN_MASK)

#define CSI_CR20_HISTOGRAM_EN_MASK               (0x40000000U)
#define CSI_CR20_HISTOGRAM_EN_SHIFT              (30U)
/*! HISTOGRAM_EN - HISTOGRAM_EN
 *  0b0..Histogram disable
 *  0b1..Histogram enable
 */
#define CSI_CR20_HISTOGRAM_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CR20_HISTOGRAM_EN_SHIFT)) & CSI_CR20_HISTOGRAM_EN_MASK)

#define CSI_CR20_QRCODE_EN_MASK                  (0x80000000U)
#define CSI_CR20_QRCODE_EN_SHIFT                 (31U)
/*! QRCODE_EN - QRCODE_EN
 *  0b0..Normal mode
 *  0b1..Gray scale mode
 */
#define CSI_CR20_QRCODE_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CR20_QRCODE_EN_SHIFT)) & CSI_CR20_QRCODE_EN_MASK)
/*! @} */

/*! @name CR - CSI Control Register */
/*! @{ */

#define CSI_CR_PIXEL_COUNTERS_MASK               (0xFFFFFFU)
#define CSI_CR_PIXEL_COUNTERS_SHIFT              (0U)
/*! PIXEL_COUNTERS - PIXEL_COUNTERS */
#define CSI_CR_PIXEL_COUNTERS(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CR_PIXEL_COUNTERS_SHIFT)) & CSI_CR_PIXEL_COUNTERS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CSI_Register_Masks */


/*!
 * @}
 */ /* end of group CSI_Peripheral_Access_Layer */


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


#endif  /* PERI_CSI_H_ */

