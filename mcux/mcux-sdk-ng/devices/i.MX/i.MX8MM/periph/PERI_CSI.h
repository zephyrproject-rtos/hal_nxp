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
**         CMSIS Peripheral Access Layer for CSI
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
 * @file PERI_CSI.h
 * @version 5.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CSI
 *
 * CMSIS Peripheral Access Layer for CSI
 */

#if !defined(PERI_CSI_H_)
#define PERI_CSI_H_                              /**< Symbol preventing repeated inclusion */

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
   -- CSI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSI_Peripheral_Access_Layer CSI Peripheral Access Layer
 * @{
 */

/** CSI - Register Layout Typedef */
typedef struct {
  __IO uint32_t CSICR1;                            /**< CSI Control Register 1, offset: 0x0 */
  __IO uint32_t CSICR2;                            /**< CSI Control Register 2, offset: 0x4 */
  __IO uint32_t CSICR3;                            /**< CSI Control Register 3, offset: 0x8 */
  __I  uint32_t CSISTATFIFO;                       /**< CSI Statistic FIFO Register, offset: 0xC */
  __I  uint32_t CSIRFIFO;                          /**< CSI RX FIFO Register, offset: 0x10 */
  __IO uint32_t CSIRXCNT;                          /**< CSI RX Count Register, offset: 0x14 */
  __IO uint32_t CSISR;                             /**< CSI Status Register, offset: 0x18 */
       uint8_t RESERVED_0[4];
  __IO uint32_t CSIDMASA_STATFIFO;                 /**< CSI DMA Start Address Register - for STATFIFO, offset: 0x20 */
  __IO uint32_t CSIDMATS_STATFIFO;                 /**< CSI DMA Transfer Size Register - for STATFIFO, offset: 0x24 */
  __IO uint32_t CSIDMASA_FB1;                      /**< CSI DMA Start Address Register - for Frame Buffer1, offset: 0x28 */
  __IO uint32_t CSIDMASA_FB2;                      /**< CSI DMA Transfer Size Register - for Frame Buffer2, offset: 0x2C */
  __IO uint32_t CSIFBUF_PARA;                      /**< CSI Frame Buffer Parameter Register, offset: 0x30 */
  __IO uint32_t CSIIMAG_PARA;                      /**< CSI Image Parameter Register, offset: 0x34 */
       uint8_t RESERVED_1[16];
  __IO uint32_t CSICR18;                           /**< CSI Control Register 18, offset: 0x48 */
} CSI_Type;

/* ----------------------------------------------------------------------------
   -- CSI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CSI_Register_Masks CSI Register Masks
 * @{
 */

/*! @name CSICR1 - CSI Control Register 1 */
/*! @{ */

#define CSI_CSICR1_PIXEL_BIT_MASK                (0x1U)
#define CSI_CSICR1_PIXEL_BIT_SHIFT               (0U)
/*! PIXEL_BIT
 *  0b0..8-bit data for each pixel
 *  0b1..10-bit data for each pixel
 */
#define CSI_CSICR1_PIXEL_BIT(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_PIXEL_BIT_SHIFT)) & CSI_CSICR1_PIXEL_BIT_MASK)

#define CSI_CSICR1_REDGE_MASK                    (0x2U)
#define CSI_CSICR1_REDGE_SHIFT                   (1U)
/*! REDGE
 *  0b0..Pixel data is latched at the falling edge of CSI_PIXCLK
 *  0b1..Pixel data is latched at the rising edge of CSI_PIXCLK
 */
#define CSI_CSICR1_REDGE(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_REDGE_SHIFT)) & CSI_CSICR1_REDGE_MASK)

#define CSI_CSICR1_INV_PCLK_MASK                 (0x4U)
#define CSI_CSICR1_INV_PCLK_SHIFT                (2U)
/*! INV_PCLK
 *  0b0..CSI_PIXCLK is directly applied to internal circuitry
 *  0b1..CSI_PIXCLK is inverted before applied to internal circuitry
 */
#define CSI_CSICR1_INV_PCLK(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_INV_PCLK_SHIFT)) & CSI_CSICR1_INV_PCLK_MASK)

#define CSI_CSICR1_INV_DATA_MASK                 (0x8U)
#define CSI_CSICR1_INV_DATA_SHIFT                (3U)
/*! INV_DATA
 *  0b0..CSI_D[7:0] data lines are directly applied to internal circuitry
 *  0b1..CSI_D[7:0] data lines are inverted before applied to internal circuitry
 */
#define CSI_CSICR1_INV_DATA(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_INV_DATA_SHIFT)) & CSI_CSICR1_INV_DATA_MASK)

#define CSI_CSICR1_GCLK_MODE_MASK                (0x10U)
#define CSI_CSICR1_GCLK_MODE_SHIFT               (4U)
/*! GCLK_MODE
 *  0b0..Non-gated clock mode. All incoming pixel clocks are valid. HSYNC is ignored.
 *  0b1..Gated clock mode. Pixel clock signal is valid only when HSYNC is active.
 */
#define CSI_CSICR1_GCLK_MODE(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_GCLK_MODE_SHIFT)) & CSI_CSICR1_GCLK_MODE_MASK)

#define CSI_CSICR1_CLR_RXFIFO_MASK               (0x20U)
#define CSI_CSICR1_CLR_RXFIFO_SHIFT              (5U)
#define CSI_CSICR1_CLR_RXFIFO(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_CLR_RXFIFO_SHIFT)) & CSI_CSICR1_CLR_RXFIFO_MASK)

#define CSI_CSICR1_CLR_STATFIFO_MASK             (0x40U)
#define CSI_CSICR1_CLR_STATFIFO_SHIFT            (6U)
#define CSI_CSICR1_CLR_STATFIFO(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_CLR_STATFIFO_SHIFT)) & CSI_CSICR1_CLR_STATFIFO_MASK)

#define CSI_CSICR1_PACK_DIR_MASK                 (0x80U)
#define CSI_CSICR1_PACK_DIR_SHIFT                (7U)
/*! PACK_DIR
 *  0b0..Pack from LSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x44332211 in RX FIFO. For
 *       stat data, 0xAAAA, 0xBBBB, it will appear as 0xBBBBAAAA in STAT FIFO.
 *  0b1..Pack from MSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x11223344 in RX FIFO. For
 *       stat data, 0xAAAA, 0xBBBB, it will appear as 0xAAAABBBB in STAT FIFO.
 */
#define CSI_CSICR1_PACK_DIR(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_PACK_DIR_SHIFT)) & CSI_CSICR1_PACK_DIR_MASK)

#define CSI_CSICR1_FCC_MASK                      (0x100U)
#define CSI_CSICR1_FCC_SHIFT                     (8U)
/*! FCC
 *  0b0..Asynchronous FIFO clear is selected.
 *  0b1..Synchronous FIFO clear is selected.
 */
#define CSI_CSICR1_FCC(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_FCC_SHIFT)) & CSI_CSICR1_FCC_MASK)

#define CSI_CSICR1_CCIR_EN_MASK                  (0x400U)
#define CSI_CSICR1_CCIR_EN_SHIFT                 (10U)
/*! CCIR_EN
 *  0b0..Traditional interface is selected. Timing interface logic is used to latch data.
 *  0b1..CCIR656 interface is selected.
 */
#define CSI_CSICR1_CCIR_EN(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_CCIR_EN_SHIFT)) & CSI_CSICR1_CCIR_EN_MASK)

#define CSI_CSICR1_HSYNC_POL_MASK                (0x800U)
#define CSI_CSICR1_HSYNC_POL_SHIFT               (11U)
/*! HSYNC_POL
 *  0b0..HSYNC is active low
 *  0b1..HSYNC is active high
 */
#define CSI_CSICR1_HSYNC_POL(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_HSYNC_POL_SHIFT)) & CSI_CSICR1_HSYNC_POL_MASK)

#define CSI_CSICR1_SOF_INTEN_MASK                (0x10000U)
#define CSI_CSICR1_SOF_INTEN_SHIFT               (16U)
/*! SOF_INTEN
 *  0b0..SOF interrupt disable
 *  0b1..SOF interrupt enable
 */
#define CSI_CSICR1_SOF_INTEN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_SOF_INTEN_SHIFT)) & CSI_CSICR1_SOF_INTEN_MASK)

#define CSI_CSICR1_SOF_POL_MASK                  (0x20000U)
#define CSI_CSICR1_SOF_POL_SHIFT                 (17U)
/*! SOF_POL
 *  0b0..SOF interrupt is generated on SOF falling edge
 *  0b1..SOF interrupt is generated on SOF rising edge
 */
#define CSI_CSICR1_SOF_POL(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_SOF_POL_SHIFT)) & CSI_CSICR1_SOF_POL_MASK)

#define CSI_CSICR1_RXFF_INTEN_MASK               (0x40000U)
#define CSI_CSICR1_RXFF_INTEN_SHIFT              (18U)
/*! RXFF_INTEN
 *  0b0..RxFIFO full interrupt disable
 *  0b1..RxFIFO full interrupt enable
 */
#define CSI_CSICR1_RXFF_INTEN(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_RXFF_INTEN_SHIFT)) & CSI_CSICR1_RXFF_INTEN_MASK)

#define CSI_CSICR1_FB1_DMA_DONE_INTEN_MASK       (0x80000U)
#define CSI_CSICR1_FB1_DMA_DONE_INTEN_SHIFT      (19U)
/*! FB1_DMA_DONE_INTEN
 *  0b0..Frame Buffer1 DMA Transfer Done interrupt disable
 *  0b1..Frame Buffer1 DMA Transfer Done interrupt enable
 */
#define CSI_CSICR1_FB1_DMA_DONE_INTEN(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_FB1_DMA_DONE_INTEN_SHIFT)) & CSI_CSICR1_FB1_DMA_DONE_INTEN_MASK)

#define CSI_CSICR1_FB2_DMA_DONE_INTEN_MASK       (0x100000U)
#define CSI_CSICR1_FB2_DMA_DONE_INTEN_SHIFT      (20U)
/*! FB2_DMA_DONE_INTEN
 *  0b0..Frame Buffer2 DMA Transfer Done interrupt disable
 *  0b1..Frame Buffer2 DMA Transfer Done interrupt enable
 */
#define CSI_CSICR1_FB2_DMA_DONE_INTEN(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_FB2_DMA_DONE_INTEN_SHIFT)) & CSI_CSICR1_FB2_DMA_DONE_INTEN_MASK)

#define CSI_CSICR1_STATFF_INTEN_MASK             (0x200000U)
#define CSI_CSICR1_STATFF_INTEN_SHIFT            (21U)
/*! STATFF_INTEN
 *  0b0..STATFIFO full interrupt disable
 *  0b1..STATFIFO full interrupt enable
 */
#define CSI_CSICR1_STATFF_INTEN(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_STATFF_INTEN_SHIFT)) & CSI_CSICR1_STATFF_INTEN_MASK)

#define CSI_CSICR1_SFF_DMA_DONE_INTEN_MASK       (0x400000U)
#define CSI_CSICR1_SFF_DMA_DONE_INTEN_SHIFT      (22U)
/*! SFF_DMA_DONE_INTEN
 *  0b0..STATFIFO DMA Transfer Done interrupt disable
 *  0b1..STATFIFO DMA Transfer Done interrupt enable
 */
#define CSI_CSICR1_SFF_DMA_DONE_INTEN(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_SFF_DMA_DONE_INTEN_SHIFT)) & CSI_CSICR1_SFF_DMA_DONE_INTEN_MASK)

#define CSI_CSICR1_RF_OR_INTEN_MASK              (0x1000000U)
#define CSI_CSICR1_RF_OR_INTEN_SHIFT             (24U)
/*! RF_OR_INTEN
 *  0b0..RxFIFO overrun interrupt is disabled
 *  0b1..RxFIFO overrun interrupt is enabled
 */
#define CSI_CSICR1_RF_OR_INTEN(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_RF_OR_INTEN_SHIFT)) & CSI_CSICR1_RF_OR_INTEN_MASK)

#define CSI_CSICR1_SF_OR_INTEN_MASK              (0x2000000U)
#define CSI_CSICR1_SF_OR_INTEN_SHIFT             (25U)
/*! SF_OR_INTEN
 *  0b0..STATFIFO overrun interrupt is disabled
 *  0b1..STATFIFO overrun interrupt is enabled
 */
#define CSI_CSICR1_SF_OR_INTEN(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_SF_OR_INTEN_SHIFT)) & CSI_CSICR1_SF_OR_INTEN_MASK)

#define CSI_CSICR1_COF_INT_EN_MASK               (0x4000000U)
#define CSI_CSICR1_COF_INT_EN_SHIFT              (26U)
/*! COF_INT_EN
 *  0b0..COF interrupt is disabled
 *  0b1..COF interrupt is enabled
 */
#define CSI_CSICR1_COF_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_COF_INT_EN_SHIFT)) & CSI_CSICR1_COF_INT_EN_MASK)

#define CSI_CSICR1_VIDEO_MODE_MASK               (0x8000000U)
#define CSI_CSICR1_VIDEO_MODE_SHIFT              (27U)
/*! VIDEO_MODE
 *  0b0..Progressive mode is selected
 *  0b1..Interlace mode is selected
 */
#define CSI_CSICR1_VIDEO_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_VIDEO_MODE_SHIFT)) & CSI_CSICR1_VIDEO_MODE_MASK)

#define CSI_CSICR1_PrP_IF_EN_MASK                (0x10000000U)
#define CSI_CSICR1_PrP_IF_EN_SHIFT               (28U)
/*! PrP_IF_EN
 *  0b0..CSI to PrP bus is disabled
 *  0b1..CSI to PrP bus is enabled
 */
#define CSI_CSICR1_PrP_IF_EN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_PrP_IF_EN_SHIFT)) & CSI_CSICR1_PrP_IF_EN_MASK)

#define CSI_CSICR1_EOF_INT_EN_MASK               (0x20000000U)
#define CSI_CSICR1_EOF_INT_EN_SHIFT              (29U)
/*! EOF_INT_EN
 *  0b0..EOF interrupt is disabled.
 *  0b1..EOF interrupt is generated when RX count value is reached.
 */
#define CSI_CSICR1_EOF_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_EOF_INT_EN_SHIFT)) & CSI_CSICR1_EOF_INT_EN_MASK)

#define CSI_CSICR1_EXT_VSYNC_MASK                (0x40000000U)
#define CSI_CSICR1_EXT_VSYNC_SHIFT               (30U)
/*! EXT_VSYNC
 *  0b0..Internal VSYNC mode
 *  0b1..External VSYNC mode
 */
#define CSI_CSICR1_EXT_VSYNC(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_EXT_VSYNC_SHIFT)) & CSI_CSICR1_EXT_VSYNC_MASK)

#define CSI_CSICR1_SWAP16_EN_MASK                (0x80000000U)
#define CSI_CSICR1_SWAP16_EN_SHIFT               (31U)
/*! SWAP16_EN
 *  0b0..Disable swapping
 *  0b1..Enable swapping
 */
#define CSI_CSICR1_SWAP16_EN(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR1_SWAP16_EN_SHIFT)) & CSI_CSICR1_SWAP16_EN_MASK)
/*! @} */

/*! @name CSICR2 - CSI Control Register 2 */
/*! @{ */

#define CSI_CSICR2_HSC_MASK                      (0xFFU)
#define CSI_CSICR2_HSC_SHIFT                     (0U)
/*! HSC
 *  0b00000000-0b11111111..Number of pixels to skip minus 1
 */
#define CSI_CSICR2_HSC(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_HSC_SHIFT)) & CSI_CSICR2_HSC_MASK)

#define CSI_CSICR2_VSC_MASK                      (0xFF00U)
#define CSI_CSICR2_VSC_SHIFT                     (8U)
/*! VSC
 *  0b00000000-0b11111111..Number of rows to skip minus 1
 */
#define CSI_CSICR2_VSC(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_VSC_SHIFT)) & CSI_CSICR2_VSC_MASK)

#define CSI_CSICR2_LVRM_MASK                     (0x70000U)
#define CSI_CSICR2_LVRM_SHIFT                    (16U)
/*! LVRM
 *  0b000..512 x 384
 *  0b001..448 x 336
 *  0b010..384 x 288
 *  0b011..384 x 256
 *  0b100..320 x 240
 *  0b101..288 x 216
 *  0b110..400 x 300
 */
#define CSI_CSICR2_LVRM(x)                       (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_LVRM_SHIFT)) & CSI_CSICR2_LVRM_MASK)

#define CSI_CSICR2_BTS_MASK                      (0x180000U)
#define CSI_CSICR2_BTS_SHIFT                     (19U)
/*! BTS
 *  0b00..GR
 *  0b01..RG
 *  0b10..BG
 *  0b11..GB
 */
#define CSI_CSICR2_BTS(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_BTS_SHIFT)) & CSI_CSICR2_BTS_MASK)

#define CSI_CSICR2_SCE_MASK                      (0x800000U)
#define CSI_CSICR2_SCE_SHIFT                     (23U)
/*! SCE
 *  0b0..Skip count disable
 *  0b1..Skip count enable
 */
#define CSI_CSICR2_SCE(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_SCE_SHIFT)) & CSI_CSICR2_SCE_MASK)

#define CSI_CSICR2_AFS_MASK                      (0x3000000U)
#define CSI_CSICR2_AFS_SHIFT                     (24U)
/*! AFS
 *  0b00..Abs Diff on consecutive green pixels
 *  0b01..Abs Diff on every third green pixels
 *  0b1x..Abs Diff on every four green pixels
 */
#define CSI_CSICR2_AFS(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_AFS_SHIFT)) & CSI_CSICR2_AFS_MASK)

#define CSI_CSICR2_DRM_MASK                      (0x4000000U)
#define CSI_CSICR2_DRM_SHIFT                     (26U)
/*! DRM
 *  0b0..Stats grid of 8 x 6
 *  0b1..Stats grid of 8 x 12
 */
#define CSI_CSICR2_DRM(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_DRM_SHIFT)) & CSI_CSICR2_DRM_MASK)

#define CSI_CSICR2_DMA_BURST_TYPE_SFF_MASK       (0x30000000U)
#define CSI_CSICR2_DMA_BURST_TYPE_SFF_SHIFT      (28U)
/*! DMA_BURST_TYPE_SFF
 *  0b01..INCR4
 *  0b11..INCR16
 *  0bx0..INCR8
 */
#define CSI_CSICR2_DMA_BURST_TYPE_SFF(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_DMA_BURST_TYPE_SFF_SHIFT)) & CSI_CSICR2_DMA_BURST_TYPE_SFF_MASK)

#define CSI_CSICR2_DMA_BURST_TYPE_RFF_MASK       (0xC0000000U)
#define CSI_CSICR2_DMA_BURST_TYPE_RFF_SHIFT      (30U)
/*! DMA_BURST_TYPE_RFF
 *  0b01..INCR4
 *  0b11..INCR16
 *  0bx0..INCR8
 */
#define CSI_CSICR2_DMA_BURST_TYPE_RFF(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR2_DMA_BURST_TYPE_RFF_SHIFT)) & CSI_CSICR2_DMA_BURST_TYPE_RFF_MASK)
/*! @} */

/*! @name CSICR3 - CSI Control Register 3 */
/*! @{ */

#define CSI_CSICR3_ECC_AUTO_EN_MASK              (0x1U)
#define CSI_CSICR3_ECC_AUTO_EN_SHIFT             (0U)
/*! ECC_AUTO_EN
 *  0b0..Auto Error correction is disabled.
 *  0b1..Auto Error correction is enabled.
 */
#define CSI_CSICR3_ECC_AUTO_EN(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_ECC_AUTO_EN_SHIFT)) & CSI_CSICR3_ECC_AUTO_EN_MASK)

#define CSI_CSICR3_ECC_INT_EN_MASK               (0x2U)
#define CSI_CSICR3_ECC_INT_EN_SHIFT              (1U)
/*! ECC_INT_EN
 *  0b0..No interrupt is generated when error is detected. Only the status bit ECC_INT is set.
 *  0b1..Interrupt is generated when error is detected.
 */
#define CSI_CSICR3_ECC_INT_EN(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_ECC_INT_EN_SHIFT)) & CSI_CSICR3_ECC_INT_EN_MASK)

#define CSI_CSICR3_ZERO_PACK_EN_MASK             (0x4U)
#define CSI_CSICR3_ZERO_PACK_EN_SHIFT            (2U)
/*! ZERO_PACK_EN
 *  0b0..Zero packing disabled
 *  0b1..Zero packing enabled
 */
#define CSI_CSICR3_ZERO_PACK_EN(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_ZERO_PACK_EN_SHIFT)) & CSI_CSICR3_ZERO_PACK_EN_MASK)

#define CSI_CSICR3_TWO_8BIT_SENSOR_MASK          (0x8U)
#define CSI_CSICR3_TWO_8BIT_SENSOR_SHIFT         (3U)
/*! TWO_8BIT_SENSOR
 *  0b0..Only one 8-bit sensor is connected.
 *  0b1..One 16-bit sensor is connected.
 */
#define CSI_CSICR3_TWO_8BIT_SENSOR(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_TWO_8BIT_SENSOR_SHIFT)) & CSI_CSICR3_TWO_8BIT_SENSOR_MASK)

#define CSI_CSICR3_RxFF_LEVEL_MASK               (0x70U)
#define CSI_CSICR3_RxFF_LEVEL_SHIFT              (4U)
/*! RxFF_LEVEL
 *  0b000..4 Double words
 *  0b001..8 Double words
 *  0b010..16 Double words
 *  0b011..24 Double words
 *  0b100..32 Double words
 *  0b101..48 Double words
 *  0b110..64 Double words
 *  0b111..96 Double words
 */
#define CSI_CSICR3_RxFF_LEVEL(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_RxFF_LEVEL_SHIFT)) & CSI_CSICR3_RxFF_LEVEL_MASK)

#define CSI_CSICR3_HRESP_ERR_EN_MASK             (0x80U)
#define CSI_CSICR3_HRESP_ERR_EN_SHIFT            (7U)
/*! HRESP_ERR_EN
 *  0b0..Disable hresponse error interrupt
 *  0b1..Enable hresponse error interrupt
 */
#define CSI_CSICR3_HRESP_ERR_EN(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_HRESP_ERR_EN_SHIFT)) & CSI_CSICR3_HRESP_ERR_EN_MASK)

#define CSI_CSICR3_STATFF_LEVEL_MASK             (0x700U)
#define CSI_CSICR3_STATFF_LEVEL_SHIFT            (8U)
/*! STATFF_LEVEL
 *  0b000..4 Double words
 *  0b001..8 Double words
 *  0b010..12 Double words
 *  0b011..16 Double words
 *  0b100..24 Double words
 *  0b101..32 Double words
 *  0b110..48 Double words
 *  0b111..64 Double words
 */
#define CSI_CSICR3_STATFF_LEVEL(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_STATFF_LEVEL_SHIFT)) & CSI_CSICR3_STATFF_LEVEL_MASK)

#define CSI_CSICR3_DMA_REQ_EN_SFF_MASK           (0x800U)
#define CSI_CSICR3_DMA_REQ_EN_SFF_SHIFT          (11U)
/*! DMA_REQ_EN_SFF
 *  0b0..Disable the dma request
 *  0b1..Enable the dma request
 */
#define CSI_CSICR3_DMA_REQ_EN_SFF(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_DMA_REQ_EN_SFF_SHIFT)) & CSI_CSICR3_DMA_REQ_EN_SFF_MASK)

#define CSI_CSICR3_DMA_REQ_EN_RFF_MASK           (0x1000U)
#define CSI_CSICR3_DMA_REQ_EN_RFF_SHIFT          (12U)
/*! DMA_REQ_EN_RFF
 *  0b0..Disable the dma request
 *  0b1..Enable the dma request
 */
#define CSI_CSICR3_DMA_REQ_EN_RFF(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_DMA_REQ_EN_RFF_SHIFT)) & CSI_CSICR3_DMA_REQ_EN_RFF_MASK)

#define CSI_CSICR3_DMA_REFLASH_SFF_MASK          (0x2000U)
#define CSI_CSICR3_DMA_REFLASH_SFF_SHIFT         (13U)
/*! DMA_REFLASH_SFF
 *  0b0..No reflashing
 *  0b1..Reflash the embedded DMA controller
 */
#define CSI_CSICR3_DMA_REFLASH_SFF(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_DMA_REFLASH_SFF_SHIFT)) & CSI_CSICR3_DMA_REFLASH_SFF_MASK)

#define CSI_CSICR3_DMA_REFLASH_RFF_MASK          (0x4000U)
#define CSI_CSICR3_DMA_REFLASH_RFF_SHIFT         (14U)
/*! DMA_REFLASH_RFF
 *  0b0..No reflashing
 *  0b1..Reflash the embedded DMA controller
 */
#define CSI_CSICR3_DMA_REFLASH_RFF(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_DMA_REFLASH_RFF_SHIFT)) & CSI_CSICR3_DMA_REFLASH_RFF_MASK)

#define CSI_CSICR3_FRMCNT_RST_MASK               (0x8000U)
#define CSI_CSICR3_FRMCNT_RST_SHIFT              (15U)
/*! FRMCNT_RST
 *  0b0..Do not reset
 *  0b1..Reset frame counter immediately
 */
#define CSI_CSICR3_FRMCNT_RST(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_FRMCNT_RST_SHIFT)) & CSI_CSICR3_FRMCNT_RST_MASK)

#define CSI_CSICR3_FRMCNT_MASK                   (0xFFFF0000U)
#define CSI_CSICR3_FRMCNT_SHIFT                  (16U)
#define CSI_CSICR3_FRMCNT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CSICR3_FRMCNT_SHIFT)) & CSI_CSICR3_FRMCNT_MASK)
/*! @} */

/*! @name CSISTATFIFO - CSI Statistic FIFO Register */
/*! @{ */

#define CSI_CSISTATFIFO_STAT_MASK                (0xFFFFFFFFU)
#define CSI_CSISTATFIFO_STAT_SHIFT               (0U)
#define CSI_CSISTATFIFO_STAT(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSISTATFIFO_STAT_SHIFT)) & CSI_CSISTATFIFO_STAT_MASK)
/*! @} */

/*! @name CSIRFIFO - CSI RX FIFO Register */
/*! @{ */

#define CSI_CSIRFIFO_IMAGE_MASK                  (0xFFFFFFFFU)
#define CSI_CSIRFIFO_IMAGE_SHIFT                 (0U)
#define CSI_CSIRFIFO_IMAGE(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CSIRFIFO_IMAGE_SHIFT)) & CSI_CSIRFIFO_IMAGE_MASK)
/*! @} */

/*! @name CSIRXCNT - CSI RX Count Register */
/*! @{ */

#define CSI_CSIRXCNT_RXCNT_MASK                  (0x3FFFFFU)
#define CSI_CSIRXCNT_RXCNT_SHIFT                 (0U)
#define CSI_CSIRXCNT_RXCNT(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CSIRXCNT_RXCNT_SHIFT)) & CSI_CSIRXCNT_RXCNT_MASK)
/*! @} */

/*! @name CSISR - CSI Status Register */
/*! @{ */

#define CSI_CSISR_DRDY_MASK                      (0x1U)
#define CSI_CSISR_DRDY_SHIFT                     (0U)
/*! DRDY
 *  0b0..No data (word) is ready
 *  0b1..At least 1 datum (word) is ready in RXFIFO.
 */
#define CSI_CSISR_DRDY(x)                        (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DRDY_SHIFT)) & CSI_CSISR_DRDY_MASK)

#define CSI_CSISR_ECC_INT_MASK                   (0x2U)
#define CSI_CSISR_ECC_INT_SHIFT                  (1U)
/*! ECC_INT
 *  0b0..No error detected
 *  0b1..Error is detected in CCIR coding
 */
#define CSI_CSISR_ECC_INT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_ECC_INT_SHIFT)) & CSI_CSISR_ECC_INT_MASK)

#define CSI_CSISR_HRESP_ERR_INT_MASK             (0x80U)
#define CSI_CSISR_HRESP_ERR_INT_SHIFT            (7U)
/*! HRESP_ERR_INT
 *  0b0..No hresponse error.
 *  0b1..Hresponse error is detected.
 */
#define CSI_CSISR_HRESP_ERR_INT(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_HRESP_ERR_INT_SHIFT)) & CSI_CSISR_HRESP_ERR_INT_MASK)

#define CSI_CSISR_COF_INT_MASK                   (0x2000U)
#define CSI_CSISR_COF_INT_SHIFT                  (13U)
/*! COF_INT
 *  0b0..Video field has no change.
 *  0b1..Change of video field is detected.
 */
#define CSI_CSISR_COF_INT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_COF_INT_SHIFT)) & CSI_CSISR_COF_INT_MASK)

#define CSI_CSISR_F1_INT_MASK                    (0x4000U)
#define CSI_CSISR_F1_INT_SHIFT                   (14U)
/*! F1_INT
 *  0b0..Field 1 of video is not detected.
 *  0b1..Field 1 of video is about to start.
 */
#define CSI_CSISR_F1_INT(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_F1_INT_SHIFT)) & CSI_CSISR_F1_INT_MASK)

#define CSI_CSISR_F2_INT_MASK                    (0x8000U)
#define CSI_CSISR_F2_INT_SHIFT                   (15U)
/*! F2_INT
 *  0b0..Field 2 of video is not detected
 *  0b1..Field 2 of video is about to start
 */
#define CSI_CSISR_F2_INT(x)                      (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_F2_INT_SHIFT)) & CSI_CSISR_F2_INT_MASK)

#define CSI_CSISR_SOF_INT_MASK                   (0x10000U)
#define CSI_CSISR_SOF_INT_SHIFT                  (16U)
/*! SOF_INT
 *  0b0..SOF is not detected.
 *  0b1..SOF is detected.
 */
#define CSI_CSISR_SOF_INT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_SOF_INT_SHIFT)) & CSI_CSISR_SOF_INT_MASK)

#define CSI_CSISR_EOF_INT_MASK                   (0x20000U)
#define CSI_CSISR_EOF_INT_SHIFT                  (17U)
/*! EOF_INT
 *  0b0..EOF is not detected.
 *  0b1..EOF is detected.
 */
#define CSI_CSISR_EOF_INT(x)                     (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_EOF_INT_SHIFT)) & CSI_CSISR_EOF_INT_MASK)

#define CSI_CSISR_RxFF_INT_MASK                  (0x40000U)
#define CSI_CSISR_RxFF_INT_SHIFT                 (18U)
/*! RxFF_INT
 *  0b0..RxFIFO is not full.
 *  0b1..RxFIFO is full.
 */
#define CSI_CSISR_RxFF_INT(x)                    (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_RxFF_INT_SHIFT)) & CSI_CSISR_RxFF_INT_MASK)

#define CSI_CSISR_DMA_TSF_DONE_FB1_MASK          (0x80000U)
#define CSI_CSISR_DMA_TSF_DONE_FB1_SHIFT         (19U)
/*! DMA_TSF_DONE_FB1
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_CSISR_DMA_TSF_DONE_FB1(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DMA_TSF_DONE_FB1_SHIFT)) & CSI_CSISR_DMA_TSF_DONE_FB1_MASK)

#define CSI_CSISR_DMA_TSF_DONE_FB2_MASK          (0x100000U)
#define CSI_CSISR_DMA_TSF_DONE_FB2_SHIFT         (20U)
/*! DMA_TSF_DONE_FB2
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_CSISR_DMA_TSF_DONE_FB2(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DMA_TSF_DONE_FB2_SHIFT)) & CSI_CSISR_DMA_TSF_DONE_FB2_MASK)

#define CSI_CSISR_STATFF_INT_MASK                (0x200000U)
#define CSI_CSISR_STATFF_INT_SHIFT               (21U)
/*! STATFF_INT
 *  0b0..STATFIFO is not full.
 *  0b1..STATFIFO is full.
 */
#define CSI_CSISR_STATFF_INT(x)                  (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_STATFF_INT_SHIFT)) & CSI_CSISR_STATFF_INT_MASK)

#define CSI_CSISR_DMA_TSF_DONE_SFF_MASK          (0x400000U)
#define CSI_CSISR_DMA_TSF_DONE_SFF_SHIFT         (22U)
/*! DMA_TSF_DONE_SFF
 *  0b0..DMA transfer is not completed.
 *  0b1..DMA transfer is completed.
 */
#define CSI_CSISR_DMA_TSF_DONE_SFF(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DMA_TSF_DONE_SFF_SHIFT)) & CSI_CSISR_DMA_TSF_DONE_SFF_MASK)

#define CSI_CSISR_RF_OR_INT_MASK                 (0x1000000U)
#define CSI_CSISR_RF_OR_INT_SHIFT                (24U)
/*! RF_OR_INT
 *  0b0..RXFIFO has not overflowed.
 *  0b1..RXFIFO has overflowed.
 */
#define CSI_CSISR_RF_OR_INT(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_RF_OR_INT_SHIFT)) & CSI_CSISR_RF_OR_INT_MASK)

#define CSI_CSISR_SF_OR_INT_MASK                 (0x2000000U)
#define CSI_CSISR_SF_OR_INT_SHIFT                (25U)
/*! SF_OR_INT
 *  0b0..STATFIFO has not overflowed.
 *  0b1..STATFIFO has overflowed.
 */
#define CSI_CSISR_SF_OR_INT(x)                   (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_SF_OR_INT_SHIFT)) & CSI_CSISR_SF_OR_INT_MASK)

#define CSI_CSISR_DMA_FIELD1_DONE_MASK           (0x4000000U)
#define CSI_CSISR_DMA_FIELD1_DONE_SHIFT          (26U)
#define CSI_CSISR_DMA_FIELD1_DONE(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DMA_FIELD1_DONE_SHIFT)) & CSI_CSISR_DMA_FIELD1_DONE_MASK)

#define CSI_CSISR_DMA_FIELD0_DONE_MASK           (0x8000000U)
#define CSI_CSISR_DMA_FIELD0_DONE_SHIFT          (27U)
#define CSI_CSISR_DMA_FIELD0_DONE(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_DMA_FIELD0_DONE_SHIFT)) & CSI_CSISR_DMA_FIELD0_DONE_MASK)

#define CSI_CSISR_BASEADDR_CHHANGE_ERROR_MASK    (0x10000000U)
#define CSI_CSISR_BASEADDR_CHHANGE_ERROR_SHIFT   (28U)
#define CSI_CSISR_BASEADDR_CHHANGE_ERROR(x)      (((uint32_t)(((uint32_t)(x)) << CSI_CSISR_BASEADDR_CHHANGE_ERROR_SHIFT)) & CSI_CSISR_BASEADDR_CHHANGE_ERROR_MASK)
/*! @} */

/*! @name CSIDMASA_STATFIFO - CSI DMA Start Address Register - for STATFIFO */
/*! @{ */

#define CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF_MASK (0xFFFFFFFCU)
#define CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF_SHIFT (2U)
#define CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(x) (((uint32_t)(((uint32_t)(x)) << CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF_SHIFT)) & CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF_MASK)
/*! @} */

/*! @name CSIDMATS_STATFIFO - CSI DMA Transfer Size Register - for STATFIFO */
/*! @{ */

#define CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF_MASK (0xFFFFFFFFU)
#define CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF_SHIFT (0U)
#define CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(x) (((uint32_t)(((uint32_t)(x)) << CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF_SHIFT)) & CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF_MASK)
/*! @} */

/*! @name CSIDMASA_FB1 - CSI DMA Start Address Register - for Frame Buffer1 */
/*! @{ */

#define CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1_MASK (0xFFFFFFFCU)
#define CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1_SHIFT (2U)
#define CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(x)   (((uint32_t)(((uint32_t)(x)) << CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1_SHIFT)) & CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1_MASK)
/*! @} */

/*! @name CSIDMASA_FB2 - CSI DMA Transfer Size Register - for Frame Buffer2 */
/*! @{ */

#define CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2_MASK (0xFFFFFFFCU)
#define CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2_SHIFT (2U)
#define CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(x)   (((uint32_t)(((uint32_t)(x)) << CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2_SHIFT)) & CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2_MASK)
/*! @} */

/*! @name CSIFBUF_PARA - CSI Frame Buffer Parameter Register */
/*! @{ */

#define CSI_CSIFBUF_PARA_FBUF_STRIDE_MASK        (0xFFFFU)
#define CSI_CSIFBUF_PARA_FBUF_STRIDE_SHIFT       (0U)
#define CSI_CSIFBUF_PARA_FBUF_STRIDE(x)          (((uint32_t)(((uint32_t)(x)) << CSI_CSIFBUF_PARA_FBUF_STRIDE_SHIFT)) & CSI_CSIFBUF_PARA_FBUF_STRIDE_MASK)

#define CSI_CSIFBUF_PARA_DEINTERLACE_STRIDE_MASK (0xFFFF0000U)
#define CSI_CSIFBUF_PARA_DEINTERLACE_STRIDE_SHIFT (16U)
#define CSI_CSIFBUF_PARA_DEINTERLACE_STRIDE(x)   (((uint32_t)(((uint32_t)(x)) << CSI_CSIFBUF_PARA_DEINTERLACE_STRIDE_SHIFT)) & CSI_CSIFBUF_PARA_DEINTERLACE_STRIDE_MASK)
/*! @} */

/*! @name CSIIMAG_PARA - CSI Image Parameter Register */
/*! @{ */

#define CSI_CSIIMAG_PARA_IMAGE_HEIGHT_MASK       (0xFFFFU)
#define CSI_CSIIMAG_PARA_IMAGE_HEIGHT_SHIFT      (0U)
#define CSI_CSIIMAG_PARA_IMAGE_HEIGHT(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSIIMAG_PARA_IMAGE_HEIGHT_SHIFT)) & CSI_CSIIMAG_PARA_IMAGE_HEIGHT_MASK)

#define CSI_CSIIMAG_PARA_IMAGE_WIDTH_MASK        (0xFFFF0000U)
#define CSI_CSIIMAG_PARA_IMAGE_WIDTH_SHIFT       (16U)
#define CSI_CSIIMAG_PARA_IMAGE_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << CSI_CSIIMAG_PARA_IMAGE_WIDTH_SHIFT)) & CSI_CSIIMAG_PARA_IMAGE_WIDTH_MASK)
/*! @} */

/*! @name CSICR18 - CSI Control Register 18 */
/*! @{ */

#define CSI_CSICR18_DEINTERLACE_EN_MASK          (0x4U)
#define CSI_CSICR18_DEINTERLACE_EN_SHIFT         (2U)
/*! DEINTERLACE_EN
 *  0b0..Deinterlace disabled
 *  0b1..Deinterlace enabled
 */
#define CSI_CSICR18_DEINTERLACE_EN(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_DEINTERLACE_EN_SHIFT)) & CSI_CSICR18_DEINTERLACE_EN_MASK)

#define CSI_CSICR18_PARALLEL24_EN_MASK           (0x8U)
#define CSI_CSICR18_PARALLEL24_EN_SHIFT          (3U)
#define CSI_CSICR18_PARALLEL24_EN(x)             (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_PARALLEL24_EN_SHIFT)) & CSI_CSICR18_PARALLEL24_EN_MASK)

#define CSI_CSICR18_BASEADDR_SWITCH_EN_MASK      (0x10U)
#define CSI_CSICR18_BASEADDR_SWITCH_EN_SHIFT     (4U)
#define CSI_CSICR18_BASEADDR_SWITCH_EN(x)        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_BASEADDR_SWITCH_EN_SHIFT)) & CSI_CSICR18_BASEADDR_SWITCH_EN_MASK)

#define CSI_CSICR18_BASEADDR_SWITCH_SEL_MASK     (0x20U)
#define CSI_CSICR18_BASEADDR_SWITCH_SEL_SHIFT    (5U)
/*! BASEADDR_SWITCH_SEL
 *  0b0..Switching base address at the edge of the vsync
 *  0b1..Switching base address at the edge of the first data of each frame
 */
#define CSI_CSICR18_BASEADDR_SWITCH_SEL(x)       (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_BASEADDR_SWITCH_SEL_SHIFT)) & CSI_CSICR18_BASEADDR_SWITCH_SEL_MASK)

#define CSI_CSICR18_FIELD0_DONE_IE_MASK          (0x40U)
#define CSI_CSICR18_FIELD0_DONE_IE_SHIFT         (6U)
/*! FIELD0_DONE_IE
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CSI_CSICR18_FIELD0_DONE_IE(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_FIELD0_DONE_IE_SHIFT)) & CSI_CSICR18_FIELD0_DONE_IE_MASK)

#define CSI_CSICR18_DMA_FIELD1_DONE_IE_MASK      (0x80U)
#define CSI_CSICR18_DMA_FIELD1_DONE_IE_SHIFT     (7U)
/*! DMA_FIELD1_DONE_IE
 *  0b0..Interrupt disabled
 *  0b1..Interrupt enabled
 */
#define CSI_CSICR18_DMA_FIELD1_DONE_IE(x)        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_DMA_FIELD1_DONE_IE_SHIFT)) & CSI_CSICR18_DMA_FIELD1_DONE_IE_MASK)

#define CSI_CSICR18_LAST_DMA_REQ_SEL_MASK        (0x100U)
#define CSI_CSICR18_LAST_DMA_REQ_SEL_SHIFT       (8U)
/*! LAST_DMA_REQ_SEL
 *  0b0..fifo_full_level
 *  0b1..hburst_length
 */
#define CSI_CSICR18_LAST_DMA_REQ_SEL(x)          (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_LAST_DMA_REQ_SEL_SHIFT)) & CSI_CSICR18_LAST_DMA_REQ_SEL_MASK)

#define CSI_CSICR18_BASEADDR_CHANGE_ERROR_IE_MASK (0x200U)
#define CSI_CSICR18_BASEADDR_CHANGE_ERROR_IE_SHIFT (9U)
#define CSI_CSICR18_BASEADDR_CHANGE_ERROR_IE(x)  (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_BASEADDR_CHANGE_ERROR_IE_SHIFT)) & CSI_CSICR18_BASEADDR_CHANGE_ERROR_IE_MASK)

#define CSI_CSICR18_RGB888A_FORMAT_SEL_MASK      (0x400U)
#define CSI_CSICR18_RGB888A_FORMAT_SEL_SHIFT     (10U)
/*! RGB888A_FORMAT_SEL
 *  0b0..{8'h0, data[23:0]}
 *  0b1..{data[23:0], 8'h0}
 */
#define CSI_CSICR18_RGB888A_FORMAT_SEL(x)        (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_RGB888A_FORMAT_SEL_SHIFT)) & CSI_CSICR18_RGB888A_FORMAT_SEL_MASK)

#define CSI_CSICR18_AHB_HPROT_MASK               (0xF000U)
#define CSI_CSICR18_AHB_HPROT_SHIFT              (12U)
#define CSI_CSICR18_AHB_HPROT(x)                 (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_AHB_HPROT_SHIFT)) & CSI_CSICR18_AHB_HPROT_MASK)

#define CSI_CSICR18_CSI_LCDIF_BUFFER_LINES_MASK  (0x30000U)
#define CSI_CSICR18_CSI_LCDIF_BUFFER_LINES_SHIFT (16U)
/*! CSI_LCDIF_BUFFER_LINES
 *  0b00..4 lines
 *  0b01..8 lines
 *  0b10..16 lines
 *  0b11..16 lines
 */
#define CSI_CSICR18_CSI_LCDIF_BUFFER_LINES(x)    (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_CSI_LCDIF_BUFFER_LINES_SHIFT)) & CSI_CSICR18_CSI_LCDIF_BUFFER_LINES_MASK)

#define CSI_CSICR18_MASK_OPTION_MASK             (0xC0000U)
#define CSI_CSICR18_MASK_OPTION_SHIFT            (18U)
/*! MASK_OPTION
 *  0b00..Writing to memory from first completely frame, when using this option, the CSI_ENABLE should be 1.
 *  0b01..Writing to memory when CSI_ENABLE is 1.
 *  0b10..Writing to memory from second completely frame, when using this option, the CSI_ENABLE should be 1.
 *  0b11..Writing to memory when data comes in, not matter the CSI_ENABLE is 1 or 0.
 */
#define CSI_CSICR18_MASK_OPTION(x)               (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_MASK_OPTION_SHIFT)) & CSI_CSICR18_MASK_OPTION_MASK)

#define CSI_CSICR18_MIPI_DOUBLE_CMPNT_MASK       (0x100000U)
#define CSI_CSICR18_MIPI_DOUBLE_CMPNT_SHIFT      (20U)
/*! MIPI_DOUBLE_CMPNT
 *  0b0..Single component per clock cycle (half pixel per clock cycle)
 *  0b1..Double component per clock cycle (a pixel per clock cycle)
 */
#define CSI_CSICR18_MIPI_DOUBLE_CMPNT(x)         (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_MIPI_DOUBLE_CMPNT_SHIFT)) & CSI_CSICR18_MIPI_DOUBLE_CMPNT_MASK)

#define CSI_CSICR18_MIPI_YU_SWAP_MASK            (0x200000U)
#define CSI_CSICR18_MIPI_YU_SWAP_SHIFT           (21U)
/*! MIPI_YU_SWAP - It only works in MIPI CSI YUV422 double component mode. */
#define CSI_CSICR18_MIPI_YU_SWAP(x)              (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_MIPI_YU_SWAP_SHIFT)) & CSI_CSICR18_MIPI_YU_SWAP_MASK)

#define CSI_CSICR18_DATA_FROM_MIPI_MASK          (0x400000U)
#define CSI_CSICR18_DATA_FROM_MIPI_SHIFT         (22U)
/*! DATA_FROM_MIPI
 *  0b0..Data from parallel sensor
 *  0b1..Data from MIPI
 */
#define CSI_CSICR18_DATA_FROM_MIPI(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_DATA_FROM_MIPI_SHIFT)) & CSI_CSICR18_DATA_FROM_MIPI_MASK)

#define CSI_CSICR18_LINE_STRIDE_EN_MASK          (0x1000000U)
#define CSI_CSICR18_LINE_STRIDE_EN_SHIFT         (24U)
#define CSI_CSICR18_LINE_STRIDE_EN(x)            (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_LINE_STRIDE_EN_SHIFT)) & CSI_CSICR18_LINE_STRIDE_EN_MASK)

#define CSI_CSICR18_MIPI_DATA_FORMAT_MASK        (0x7E000000U)
#define CSI_CSICR18_MIPI_DATA_FORMAT_SHIFT       (25U)
/*! MIPI_DATA_FORMAT - Image Data Format */
#define CSI_CSICR18_MIPI_DATA_FORMAT(x)          (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_MIPI_DATA_FORMAT_SHIFT)) & CSI_CSICR18_MIPI_DATA_FORMAT_MASK)

#define CSI_CSICR18_CSI_ENABLE_MASK              (0x80000000U)
#define CSI_CSICR18_CSI_ENABLE_SHIFT             (31U)
#define CSI_CSICR18_CSI_ENABLE(x)                (((uint32_t)(((uint32_t)(x)) << CSI_CSICR18_CSI_ENABLE_SHIFT)) & CSI_CSICR18_CSI_ENABLE_MASK)
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

