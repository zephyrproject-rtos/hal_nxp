/*
** ###################################################################
**     Processors:          MIMX8MN1CVPIZ_ca53
**                          MIMX8MN1CVPIZ_cm7
**                          MIMX8MN1CVTIZ_ca53
**                          MIMX8MN1CVTIZ_cm7
**                          MIMX8MN1DVPIZ_ca53
**                          MIMX8MN1DVPIZ_cm7
**                          MIMX8MN1DVTJZ_ca53
**                          MIMX8MN1DVTJZ_cm7
**                          MIMX8MN2CVTIZ_ca53
**                          MIMX8MN2CVTIZ_cm7
**                          MIMX8MN2DVTJZ_ca53
**                          MIMX8MN2DVTJZ_cm7
**                          MIMX8MN3CVPIZ_ca53
**                          MIMX8MN3CVPIZ_cm7
**                          MIMX8MN3CVTIZ_ca53
**                          MIMX8MN3CVTIZ_cm7
**                          MIMX8MN3DVPIZ_ca53
**                          MIMX8MN3DVPIZ_cm7
**                          MIMX8MN3DVTJZ_ca53
**                          MIMX8MN3DVTJZ_cm7
**                          MIMX8MN4CVTIZ_ca53
**                          MIMX8MN4CVTIZ_cm7
**                          MIMX8MN4DVTJZ_ca53
**                          MIMX8MN4DVTJZ_cm7
**                          MIMX8MN5CVPIZ_ca53
**                          MIMX8MN5CVPIZ_cm7
**                          MIMX8MN5CVTIZ_ca53
**                          MIMX8MN5CVTIZ_cm7
**                          MIMX8MN5DVPIZ_ca53
**                          MIMX8MN5DVPIZ_cm7
**                          MIMX8MN5DVTJZ_ca53
**                          MIMX8MN5DVTJZ_cm7
**                          MIMX8MN6CVTIZ_ca53
**                          MIMX8MN6CVTIZ_cm7
**                          MIMX8MN6DVTJZ_ca53
**                          MIMX8MN6DVTJZ_cm7
**
**     Version:             rev. 3.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LCDIF
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2019-04-22)
**         Initial version.
**     - rev. 2.0 (2019-09-23)
**         Rev.B Header RFP
**     - rev. 3.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LCDIF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCDIF
 *
 * CMSIS Peripheral Access Layer for LCDIF
 */

#if !defined(PERI_LCDIF_H_)
#define PERI_LCDIF_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8MN1CVPIZ_ca53) || defined(CPU_MIMX8MN1CVTIZ_ca53) || defined(CPU_MIMX8MN1DVPIZ_ca53) || defined(CPU_MIMX8MN1DVTJZ_ca53))
#include "MIMX8MN1_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN1CVPIZ_cm7) || defined(CPU_MIMX8MN1CVTIZ_cm7) || defined(CPU_MIMX8MN1DVPIZ_cm7) || defined(CPU_MIMX8MN1DVTJZ_cm7))
#include "MIMX8MN1_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_ca53) || defined(CPU_MIMX8MN2DVTJZ_ca53))
#include "MIMX8MN2_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN2CVTIZ_cm7) || defined(CPU_MIMX8MN2DVTJZ_cm7))
#include "MIMX8MN2_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_ca53) || defined(CPU_MIMX8MN3CVTIZ_ca53) || defined(CPU_MIMX8MN3DVPIZ_ca53) || defined(CPU_MIMX8MN3DVTJZ_ca53))
#include "MIMX8MN3_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN3CVPIZ_cm7) || defined(CPU_MIMX8MN3CVTIZ_cm7) || defined(CPU_MIMX8MN3DVPIZ_cm7) || defined(CPU_MIMX8MN3DVTJZ_cm7))
#include "MIMX8MN3_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_ca53) || defined(CPU_MIMX8MN4DVTJZ_ca53))
#include "MIMX8MN4_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN4CVTIZ_cm7) || defined(CPU_MIMX8MN4DVTJZ_cm7))
#include "MIMX8MN4_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_ca53) || defined(CPU_MIMX8MN5CVTIZ_ca53) || defined(CPU_MIMX8MN5DVPIZ_ca53) || defined(CPU_MIMX8MN5DVTJZ_ca53))
#include "MIMX8MN5_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN5CVPIZ_cm7) || defined(CPU_MIMX8MN5CVTIZ_cm7) || defined(CPU_MIMX8MN5DVPIZ_cm7) || defined(CPU_MIMX8MN5DVTJZ_cm7))
#include "MIMX8MN5_cm7_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_ca53) || defined(CPU_MIMX8MN6DVTJZ_ca53))
#include "MIMX8MN6_ca53_COMMON.h"
#elif (defined(CPU_MIMX8MN6CVTIZ_cm7) || defined(CPU_MIMX8MN6DVTJZ_cm7))
#include "MIMX8MN6_cm7_COMMON.h"
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
   -- LCDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Peripheral_Access_Layer LCDIF Peripheral Access Layer
 * @{
 */

/** LCDIF - Size of Registers Arrays */
#define LCDIF_PIGEON_n_COUNT                      12u

/** LCDIF - Register Layout Typedef */
typedef struct {
  __IO uint32_t CTRL;                              /**< LCDIF General Control Register, offset: 0x0 */
  __IO uint32_t CTRL_SET;                          /**< LCDIF General Control Register, offset: 0x4 */
  __IO uint32_t CTRL_CLR;                          /**< LCDIF General Control Register, offset: 0x8 */
  __IO uint32_t CTRL_TOG;                          /**< LCDIF General Control Register, offset: 0xC */
  __IO uint32_t CTRL1;                             /**< LCDIF General Control1 Register, offset: 0x10 */
  __IO uint32_t CTRL1_SET;                         /**< LCDIF General Control1 Register, offset: 0x14 */
  __IO uint32_t CTRL1_CLR;                         /**< LCDIF General Control1 Register, offset: 0x18 */
  __IO uint32_t CTRL1_TOG;                         /**< LCDIF General Control1 Register, offset: 0x1C */
  __IO uint32_t CTRL2;                             /**< LCDIF General Control2 Register, offset: 0x20 */
  __IO uint32_t CTRL2_SET;                         /**< LCDIF General Control2 Register, offset: 0x24 */
  __IO uint32_t CTRL2_CLR;                         /**< LCDIF General Control2 Register, offset: 0x28 */
  __IO uint32_t CTRL2_TOG;                         /**< LCDIF General Control2 Register, offset: 0x2C */
  __IO uint32_t TRANSFER_COUNT;                    /**< LCDIF Horizontal and Vertical Valid Data Count Register, offset: 0x30 */
       uint8_t RESERVED_0[12];
  __IO uint32_t CUR_BUF;                           /**< LCD Interface Current Buffer Address Register, offset: 0x40 */
       uint8_t RESERVED_1[12];
  __IO uint32_t NEXT_BUF;                          /**< LCD Interface Next Buffer Address Register, offset: 0x50 */
       uint8_t RESERVED_2[12];
  __IO uint32_t TIMING;                            /**< LCD Interface Timing Register, offset: 0x60 */
       uint8_t RESERVED_3[12];
  __IO uint32_t VDCTRL0;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x70 */
  __IO uint32_t VDCTRL0_SET;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x74 */
  __IO uint32_t VDCTRL0_CLR;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x78 */
  __IO uint32_t VDCTRL0_TOG;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x7C */
  __IO uint32_t VDCTRL1;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register1, offset: 0x80 */
       uint8_t RESERVED_4[12];
  __IO uint32_t VDCTRL2;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register2, offset: 0x90 */
       uint8_t RESERVED_5[12];
  __IO uint32_t VDCTRL3;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register3, offset: 0xA0 */
       uint8_t RESERVED_6[12];
  __IO uint32_t VDCTRL4;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register4, offset: 0xB0 */
       uint8_t RESERVED_7[12];
  __IO uint32_t DVICTRL0;                          /**< Digital Video Interface Control0 Register, offset: 0xC0 */
       uint8_t RESERVED_8[12];
  __IO uint32_t DVICTRL1;                          /**< Digital Video Interface Control1 Register, offset: 0xD0 */
       uint8_t RESERVED_9[12];
  __IO uint32_t DVICTRL2;                          /**< Digital Video Interface Control2 Register, offset: 0xE0 */
       uint8_t RESERVED_10[12];
  __IO uint32_t DVICTRL3;                          /**< Digital Video Interface Control3 Register, offset: 0xF0 */
       uint8_t RESERVED_11[12];
  __IO uint32_t DVICTRL4;                          /**< Digital Video Interface Control4 Register, offset: 0x100 */
       uint8_t RESERVED_12[12];
  __IO uint32_t CSC_COEFF0;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient0 Register, offset: 0x110 */
       uint8_t RESERVED_13[12];
  __IO uint32_t CSC_COEFF1;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient1 Register, offset: 0x120 */
       uint8_t RESERVED_14[12];
  __IO uint32_t CSC_COEFF2;                        /**< RGB to YCbCr 4:2:2 CSC Coefficent2 Register, offset: 0x130 */
       uint8_t RESERVED_15[12];
  __IO uint32_t CSC_COEFF3;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient3 Register, offset: 0x140 */
       uint8_t RESERVED_16[12];
  __IO uint32_t CSC_COEFF4;                        /**< RGB to YCbCr 4:2:2 CSC Coefficient4 Register, offset: 0x150 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CSC_OFFSET;                        /**< RGB to YCbCr 4:2:2 CSC Offset Register, offset: 0x160 */
       uint8_t RESERVED_18[12];
  __IO uint32_t CSC_LIMIT;                         /**< RGB to YCbCr 4:2:2 CSC Limit Register, offset: 0x170 */
       uint8_t RESERVED_19[12];
  __IO uint32_t DATA;                              /**< LCD Interface Data Register, offset: 0x180 */
       uint8_t RESERVED_20[12];
  __IO uint32_t BM_ERROR_STAT;                     /**< Bus Master Error Status Register, offset: 0x190 */
       uint8_t RESERVED_21[12];
  __IO uint32_t CRC_STAT;                          /**< CRC Status Register, offset: 0x1A0 */
       uint8_t RESERVED_22[12];
  __I  uint32_t STAT;                              /**< LCD Interface Status Register, offset: 0x1B0 */
       uint8_t RESERVED_23[76];
  __IO uint32_t THRES;                             /**< LCDIF Threshold Register, offset: 0x200 */
       uint8_t RESERVED_24[12];
  __IO uint32_t AS_CTRL;                           /**< LCDIF AS Buffer Control Register, offset: 0x210 */
       uint8_t RESERVED_25[12];
  __IO uint32_t AS_BUF;                            /**< Alpha Surface Buffer Pointer, offset: 0x220 */
       uint8_t RESERVED_26[12];
  __IO uint32_t AS_NEXT_BUF;                       /**< offset: 0x230 */
       uint8_t RESERVED_27[12];
  __IO uint32_t AS_CLRKEYLOW;                      /**< LCDIF Overlay Color Key Low, offset: 0x240 */
       uint8_t RESERVED_28[12];
  __IO uint32_t AS_CLRKEYHIGH;                     /**< LCDIF Overlay Color Key High, offset: 0x250 */
       uint8_t RESERVED_29[12];
  __IO uint32_t SYNC_DELAY;                        /**< LCD working insync mode with CSI for VSYNC delay, offset: 0x260 */
       uint8_t RESERVED_30[284];
  __IO uint32_t PIGEONCTRL0;                       /**< LCDIF Pigeon Mode Control0 Register, offset: 0x380 */
  __IO uint32_t PIGEONCTRL0_SET;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x384 */
  __IO uint32_t PIGEONCTRL0_CLR;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x388 */
  __IO uint32_t PIGEONCTRL0_TOG;                   /**< LCDIF Pigeon Mode Control0 Register, offset: 0x38C */
  __IO uint32_t PIGEONCTRL1;                       /**< LCDIF Pigeon Mode Control1 Register, offset: 0x390 */
  __IO uint32_t PIGEONCTRL1_SET;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x394 */
  __IO uint32_t PIGEONCTRL1_CLR;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x398 */
  __IO uint32_t PIGEONCTRL1_TOG;                   /**< LCDIF Pigeon Mode Control1 Register, offset: 0x39C */
  __IO uint32_t PIGEONCTRL2;                       /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A0 */
  __IO uint32_t PIGEONCTRL2_SET;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A4 */
  __IO uint32_t PIGEONCTRL2_CLR;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3A8 */
  __IO uint32_t PIGEONCTRL2_TOG;                   /**< LCDIF Pigeon Mode Control2 Register, offset: 0x3AC */
       uint8_t RESERVED_31[1104];
  struct {                                         /* offset: 0x800, array step: 0x40 */
    __IO uint32_t PIGEON_n_0;                        /**< Panel Interface Signal Generator Register, array offset: 0x800, array step: 0x40 */
         uint8_t RESERVED_0[12];
    __IO uint32_t PIGEON_n_1;                        /**< Panel Interface Signal Generator Register, array offset: 0x810, array step: 0x40 */
         uint8_t RESERVED_1[12];
    __IO uint32_t PIGEON_n_2;                        /**< Panel Interface Signal Generator Register, array offset: 0x820, array step: 0x40 */
         uint8_t RESERVED_2[28];
  } PIGEON_n[LCDIF_PIGEON_n_COUNT];
} LCDIF_Type;

/* ----------------------------------------------------------------------------
   -- LCDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Register_Masks LCDIF Register Masks
 * @{
 */

/*! @name CTRL - LCDIF General Control Register */
/*! @{ */

#define LCDIF_CTRL_RUN_MASK                      (0x1U)
#define LCDIF_CTRL_RUN_SHIFT                     (0U)
#define LCDIF_CTRL_RUN(x)                        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RUN_SHIFT)) & LCDIF_CTRL_RUN_MASK)

#define LCDIF_CTRL_DATA_FORMAT_24_BIT_MASK       (0x2U)
#define LCDIF_CTRL_DATA_FORMAT_24_BIT_SHIFT      (1U)
/*! DATA_FORMAT_24_BIT
 *  0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
 *  0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
 *       each byte do not contain any useful data, and should be dropped.
 */
#define LCDIF_CTRL_DATA_FORMAT_24_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_24_BIT_MASK)

#define LCDIF_CTRL_DATA_FORMAT_18_BIT_MASK       (0x4U)
#define LCDIF_CTRL_DATA_FORMAT_18_BIT_SHIFT      (2U)
/*! DATA_FORMAT_18_BIT
 *  0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits do not contain any useful data.
 *  0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits do not contain any useful data.
 */
#define LCDIF_CTRL_DATA_FORMAT_18_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_18_BIT_MASK)

#define LCDIF_CTRL_DATA_FORMAT_16_BIT_MASK       (0x8U)
#define LCDIF_CTRL_DATA_FORMAT_16_BIT_SHIFT      (3U)
#define LCDIF_CTRL_DATA_FORMAT_16_BIT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_DATA_FORMAT_16_BIT_MASK)

#define LCDIF_CTRL_RSRVD0_MASK                   (0x10U)
#define LCDIF_CTRL_RSRVD0_SHIFT                  (4U)
#define LCDIF_CTRL_RSRVD0(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RSRVD0_SHIFT)) & LCDIF_CTRL_RSRVD0_MASK)

#define LCDIF_CTRL_MASTER_MASK                   (0x20U)
#define LCDIF_CTRL_MASTER_SHIFT                  (5U)
#define LCDIF_CTRL_MASTER(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_MASTER_SHIFT)) & LCDIF_CTRL_MASTER_MASK)

#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_MASK     (0x40U)
#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_SHIFT    (6U)
#define LCDIF_CTRL_ENABLE_PXP_HANDSHAKE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_ENABLE_PXP_HANDSHAKE_MASK)

#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC_MASK      (0x80U)
#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC_SHIFT     (7U)
#define LCDIF_CTRL_RGB_TO_YCBCR422_CSC(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_RGB_TO_YCBCR422_CSC_MASK)

#define LCDIF_CTRL_WORD_LENGTH_MASK              (0x300U)
#define LCDIF_CTRL_WORD_LENGTH_SHIFT             (8U)
/*! WORD_LENGTH
 *  0b00..Input data is 16 bits per pixel.
 *  0b01..Input data is 8 bits wide.
 *  0b10..Input data is 18 bits per pixel.
 *  0b11..Input data is 24 bits per pixel.
 */
#define LCDIF_CTRL_WORD_LENGTH(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_WORD_LENGTH_MASK)

#define LCDIF_CTRL_LCD_DATABUS_WIDTH_MASK        (0xC00U)
#define LCDIF_CTRL_LCD_DATABUS_WIDTH_SHIFT       (10U)
/*! LCD_DATABUS_WIDTH
 *  0b00..16-bit data bus mode.
 *  0b01..8-bit data bus mode.
 *  0b10..18-bit data bus mode.
 *  0b11..24-bit data bus mode.
 */
#define LCDIF_CTRL_LCD_DATABUS_WIDTH(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_LCD_DATABUS_WIDTH_MASK)

#define LCDIF_CTRL_CSC_DATA_SWIZZLE_MASK         (0x3000U)
#define LCDIF_CTRL_CSC_DATA_SWIZZLE_SHIFT        (12U)
/*! CSC_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_CSC_DATA_SWIZZLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CSC_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_INPUT_DATA_SWIZZLE_MASK       (0xC000U)
#define LCDIF_CTRL_INPUT_DATA_SWIZZLE_SHIFT      (14U)
/*! INPUT_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_INPUT_DATA_SWIZZLE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_INPUT_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_DATA_SELECT_MASK              (0x10000U)
#define LCDIF_CTRL_DATA_SELECT_SHIFT             (16U)
/*! DATA_SELECT
 *  0b0..Command Mode. LCD_RS signal is Low.
 *  0b1..Data Mode. LCD_RS signal is High.
 */
#define LCDIF_CTRL_DATA_SELECT(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_SELECT_SHIFT)) & LCDIF_CTRL_DATA_SELECT_MASK)

#define LCDIF_CTRL_DOTCLK_MODE_MASK              (0x20000U)
#define LCDIF_CTRL_DOTCLK_MODE_SHIFT             (17U)
#define LCDIF_CTRL_DOTCLK_MODE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_VSYNC_MODE_MASK               (0x40000U)
#define LCDIF_CTRL_VSYNC_MODE_SHIFT              (18U)
#define LCDIF_CTRL_VSYNC_MODE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_VSYNC_MODE_MASK)

#define LCDIF_CTRL_BYPASS_COUNT_MASK             (0x80000U)
#define LCDIF_CTRL_BYPASS_COUNT_SHIFT            (19U)
#define LCDIF_CTRL_BYPASS_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_BYPASS_COUNT_MASK)

#define LCDIF_CTRL_DVI_MODE_MASK                 (0x100000U)
#define LCDIF_CTRL_DVI_MODE_SHIFT                (20U)
#define LCDIF_CTRL_DVI_MODE(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DVI_MODE_SHIFT)) & LCDIF_CTRL_DVI_MODE_MASK)

#define LCDIF_CTRL_SHIFT_NUM_BITS_MASK           (0x3E00000U)
#define LCDIF_CTRL_SHIFT_NUM_BITS_SHIFT          (21U)
#define LCDIF_CTRL_SHIFT_NUM_BITS(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_SHIFT_NUM_BITS_MASK)

#define LCDIF_CTRL_DATA_SHIFT_DIR_MASK           (0x4000000U)
#define LCDIF_CTRL_DATA_SHIFT_DIR_SHIFT          (26U)
/*! DATA_SHIFT_DIR
 *  0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
 *  0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
 */
#define LCDIF_CTRL_DATA_SHIFT_DIR(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_DATA_SHIFT_DIR_MASK)

#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_MASK      (0x8000000U)
#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_SHIFT     (27U)
#define LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_WAIT_FOR_VSYNC_EDGE_MASK)

#define LCDIF_CTRL_READ_WRITEB_MASK              (0x10000000U)
#define LCDIF_CTRL_READ_WRITEB_SHIFT             (28U)
#define LCDIF_CTRL_READ_WRITEB(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_READ_WRITEB_SHIFT)) & LCDIF_CTRL_READ_WRITEB_MASK)

#define LCDIF_CTRL_YCBCR422_INPUT_MASK           (0x20000000U)
#define LCDIF_CTRL_YCBCR422_INPUT_SHIFT          (29U)
#define LCDIF_CTRL_YCBCR422_INPUT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_YCBCR422_INPUT_MASK)

#define LCDIF_CTRL_CLKGATE_MASK                  (0x40000000U)
#define LCDIF_CTRL_CLKGATE_SHIFT                 (30U)
#define LCDIF_CTRL_CLKGATE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLKGATE_SHIFT)) & LCDIF_CTRL_CLKGATE_MASK)

#define LCDIF_CTRL_SFTRST_MASK                   (0x80000000U)
#define LCDIF_CTRL_SFTRST_SHIFT                  (31U)
#define LCDIF_CTRL_SFTRST(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SFTRST_SHIFT)) & LCDIF_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - LCDIF General Control Register */
/*! @{ */

#define LCDIF_CTRL_SET_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_SET_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_SET_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RUN_SHIFT)) & LCDIF_CTRL_SET_RUN_MASK)

#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_SHIFT  (1U)
/*! DATA_FORMAT_24_BIT
 *  0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
 *  0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
 *       each byte do not contain any useful data, and should be dropped.
 */
#define LCDIF_CTRL_SET_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_24_BIT_MASK)

#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_SHIFT  (2U)
/*! DATA_FORMAT_18_BIT
 *  0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits do not contain any useful data.
 *  0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits do not contain any useful data.
 */
#define LCDIF_CTRL_SET_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_18_BIT_MASK)

#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_SET_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_SET_DATA_FORMAT_16_BIT_MASK)

#define LCDIF_CTRL_SET_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_SET_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_SET_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RSRVD0_SHIFT)) & LCDIF_CTRL_SET_RSRVD0_MASK)

#define LCDIF_CTRL_SET_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_SET_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_SET_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_MASTER_SHIFT)) & LCDIF_CTRL_SET_MASTER_MASK)

#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_SET_ENABLE_PXP_HANDSHAKE_MASK)

#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_SET_RGB_TO_YCBCR422_CSC_MASK)

#define LCDIF_CTRL_SET_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_SET_WORD_LENGTH_SHIFT         (8U)
/*! WORD_LENGTH
 *  0b00..Input data is 16 bits per pixel.
 *  0b01..Input data is 8 bits wide.
 *  0b10..Input data is 18 bits per pixel.
 *  0b11..Input data is 24 bits per pixel.
 */
#define LCDIF_CTRL_SET_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_SET_WORD_LENGTH_MASK)

#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_SHIFT   (10U)
/*! LCD_DATABUS_WIDTH
 *  0b00..16-bit data bus mode.
 *  0b01..8-bit data bus mode.
 *  0b10..18-bit data bus mode.
 *  0b11..24-bit data bus mode.
 */
#define LCDIF_CTRL_SET_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_SET_LCD_DATABUS_WIDTH_MASK)

#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_SHIFT    (12U)
/*! CSC_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_SET_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_SET_CSC_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_SHIFT  (14U)
/*! INPUT_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_SET_INPUT_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_SET_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_SET_DATA_SELECT_SHIFT         (16U)
/*! DATA_SELECT
 *  0b0..Command Mode. LCD_RS signal is Low.
 *  0b1..Data Mode. LCD_RS signal is High.
 */
#define LCDIF_CTRL_SET_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_SELECT_SHIFT)) & LCDIF_CTRL_SET_DATA_SELECT_MASK)

#define LCDIF_CTRL_SET_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_SET_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_SET_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_SET_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_SET_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_SET_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_SET_VSYNC_MODE_MASK)

#define LCDIF_CTRL_SET_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_SET_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_SET_BYPASS_COUNT_MASK)

#define LCDIF_CTRL_SET_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_SET_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_SET_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DVI_MODE_SHIFT)) & LCDIF_CTRL_SET_DVI_MODE_MASK)

#define LCDIF_CTRL_SET_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_SET_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_SET_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_SET_SHIFT_NUM_BITS_MASK)

#define LCDIF_CTRL_SET_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_SET_DATA_SHIFT_DIR_SHIFT      (26U)
/*! DATA_SHIFT_DIR
 *  0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
 *  0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
 */
#define LCDIF_CTRL_SET_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_SET_DATA_SHIFT_DIR_MASK)

#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_SET_WAIT_FOR_VSYNC_EDGE_MASK)

#define LCDIF_CTRL_SET_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_SET_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_SET_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_READ_WRITEB_SHIFT)) & LCDIF_CTRL_SET_READ_WRITEB_MASK)

#define LCDIF_CTRL_SET_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_SET_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_SET_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_SET_YCBCR422_INPUT_MASK)

#define LCDIF_CTRL_SET_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_SET_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_SET_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_CLKGATE_SHIFT)) & LCDIF_CTRL_SET_CLKGATE_MASK)

#define LCDIF_CTRL_SET_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_SET_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_SET_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_SFTRST_SHIFT)) & LCDIF_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - LCDIF General Control Register */
/*! @{ */

#define LCDIF_CTRL_CLR_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_CLR_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_CLR_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RUN_SHIFT)) & LCDIF_CTRL_CLR_RUN_MASK)

#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_SHIFT  (1U)
/*! DATA_FORMAT_24_BIT
 *  0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
 *  0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
 *       each byte do not contain any useful data, and should be dropped.
 */
#define LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_24_BIT_MASK)

#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_SHIFT  (2U)
/*! DATA_FORMAT_18_BIT
 *  0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits do not contain any useful data.
 *  0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits do not contain any useful data.
 */
#define LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_18_BIT_MASK)

#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_CLR_DATA_FORMAT_16_BIT_MASK)

#define LCDIF_CTRL_CLR_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_CLR_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_CLR_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL_CLR_RSRVD0_MASK)

#define LCDIF_CTRL_CLR_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_CLR_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_CLR_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_MASTER_SHIFT)) & LCDIF_CTRL_CLR_MASTER_MASK)

#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_CLR_ENABLE_PXP_HANDSHAKE_MASK)

#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_CLR_RGB_TO_YCBCR422_CSC_MASK)

#define LCDIF_CTRL_CLR_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_CLR_WORD_LENGTH_SHIFT         (8U)
/*! WORD_LENGTH
 *  0b00..Input data is 16 bits per pixel.
 *  0b01..Input data is 8 bits wide.
 *  0b10..Input data is 18 bits per pixel.
 *  0b11..Input data is 24 bits per pixel.
 */
#define LCDIF_CTRL_CLR_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_CLR_WORD_LENGTH_MASK)

#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_SHIFT   (10U)
/*! LCD_DATABUS_WIDTH
 *  0b00..16-bit data bus mode.
 *  0b01..8-bit data bus mode.
 *  0b10..18-bit data bus mode.
 *  0b11..24-bit data bus mode.
 */
#define LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_CLR_LCD_DATABUS_WIDTH_MASK)

#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_SHIFT    (12U)
/*! CSC_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CLR_CSC_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_SHIFT  (14U)
/*! INPUT_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_CLR_INPUT_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_CLR_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_CLR_DATA_SELECT_SHIFT         (16U)
/*! DATA_SELECT
 *  0b0..Command Mode. LCD_RS signal is Low.
 *  0b1..Data Mode. LCD_RS signal is High.
 */
#define LCDIF_CTRL_CLR_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_SELECT_SHIFT)) & LCDIF_CTRL_CLR_DATA_SELECT_MASK)

#define LCDIF_CTRL_CLR_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_CLR_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_CLR_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_CLR_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_CLR_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_CLR_VSYNC_MODE_MASK)

#define LCDIF_CTRL_CLR_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_CLR_BYPASS_COUNT_MASK)

#define LCDIF_CTRL_CLR_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_CLR_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_CLR_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DVI_MODE_SHIFT)) & LCDIF_CTRL_CLR_DVI_MODE_MASK)

#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_CLR_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_CLR_SHIFT_NUM_BITS_MASK)

#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR_SHIFT      (26U)
/*! DATA_SHIFT_DIR
 *  0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
 *  0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
 */
#define LCDIF_CTRL_CLR_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_CLR_DATA_SHIFT_DIR_MASK)

#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_CLR_WAIT_FOR_VSYNC_EDGE_MASK)

#define LCDIF_CTRL_CLR_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_CLR_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_CLR_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_READ_WRITEB_SHIFT)) & LCDIF_CTRL_CLR_READ_WRITEB_MASK)

#define LCDIF_CTRL_CLR_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_CLR_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_CLR_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_CLR_YCBCR422_INPUT_MASK)

#define LCDIF_CTRL_CLR_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_CLR_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_CLR_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_CLKGATE_SHIFT)) & LCDIF_CTRL_CLR_CLKGATE_MASK)

#define LCDIF_CTRL_CLR_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_CLR_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_CLR_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_SFTRST_SHIFT)) & LCDIF_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - LCDIF General Control Register */
/*! @{ */

#define LCDIF_CTRL_TOG_RUN_MASK                  (0x1U)
#define LCDIF_CTRL_TOG_RUN_SHIFT                 (0U)
#define LCDIF_CTRL_TOG_RUN(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RUN_SHIFT)) & LCDIF_CTRL_TOG_RUN_MASK)

#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_MASK   (0x2U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_SHIFT  (1U)
/*! DATA_FORMAT_24_BIT
 *  0b0..Data input to the block is in 24 bpp format, such that all RGB 888 data is contained in 24 bits.
 *  0b1..Data input to the block is actually RGB 18 bpp, but there is 1 color per byte, hence the upper 2 bits in
 *       each byte do not contain any useful data, and should be dropped.
 */
#define LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_24_BIT_MASK)

#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_MASK   (0x4U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_SHIFT  (2U)
/*! DATA_FORMAT_18_BIT
 *  0b0..Data input to the block is in 18 bpp format, such that lower 18 bits contain RGB 666 and upper 14 bits do not contain any useful data.
 *  0b1..Data input to the block is in 18 bpp format, such that upper 18 bits contain RGB 666 and lower 14 bits do not contain any useful data.
 */
#define LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_18_BIT_MASK)

#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_MASK   (0x8U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_SHIFT  (3U)
#define LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_SHIFT)) & LCDIF_CTRL_TOG_DATA_FORMAT_16_BIT_MASK)

#define LCDIF_CTRL_TOG_RSRVD0_MASK               (0x10U)
#define LCDIF_CTRL_TOG_RSRVD0_SHIFT              (4U)
#define LCDIF_CTRL_TOG_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL_TOG_RSRVD0_MASK)

#define LCDIF_CTRL_TOG_MASTER_MASK               (0x20U)
#define LCDIF_CTRL_TOG_MASTER_SHIFT              (5U)
#define LCDIF_CTRL_TOG_MASTER(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_MASTER_SHIFT)) & LCDIF_CTRL_TOG_MASTER_MASK)

#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_MASK (0x40U)
#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_SHIFT (6U)
#define LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_SHIFT)) & LCDIF_CTRL_TOG_ENABLE_PXP_HANDSHAKE_MASK)

#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_MASK  (0x80U)
#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_SHIFT (7U)
#define LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_SHIFT)) & LCDIF_CTRL_TOG_RGB_TO_YCBCR422_CSC_MASK)

#define LCDIF_CTRL_TOG_WORD_LENGTH_MASK          (0x300U)
#define LCDIF_CTRL_TOG_WORD_LENGTH_SHIFT         (8U)
/*! WORD_LENGTH
 *  0b00..Input data is 16 bits per pixel.
 *  0b01..Input data is 8 bits wide.
 *  0b10..Input data is 18 bits per pixel.
 *  0b11..Input data is 24 bits per pixel.
 */
#define LCDIF_CTRL_TOG_WORD_LENGTH(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_WORD_LENGTH_SHIFT)) & LCDIF_CTRL_TOG_WORD_LENGTH_MASK)

#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_MASK    (0xC00U)
#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_SHIFT   (10U)
/*! LCD_DATABUS_WIDTH
 *  0b00..16-bit data bus mode.
 *  0b01..8-bit data bus mode.
 *  0b10..18-bit data bus mode.
 *  0b11..24-bit data bus mode.
 */
#define LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_SHIFT)) & LCDIF_CTRL_TOG_LCD_DATABUS_WIDTH_MASK)

#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_MASK     (0x3000U)
#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_SHIFT    (12U)
/*! CSC_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_TOG_CSC_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_MASK   (0xC000U)
#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_SHIFT  (14U)
/*! INPUT_DATA_SWIZZLE
 *  0b00..Little Endian byte ordering (same as NO_SWAP).
 *  0b00..No byte swapping.(Little endian)
 *  0b01..Big Endian swap (swap bytes 0,3 and 1,2).
 *  0b01..Swizzle all bytes, swap bytes 0,3 and 1,2 (aka Big Endian).
 *  0b10..Swap half-words.
 *  0b11..Swap bytes within each half-word.
 */
#define LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_CTRL_TOG_INPUT_DATA_SWIZZLE_MASK)

#define LCDIF_CTRL_TOG_DATA_SELECT_MASK          (0x10000U)
#define LCDIF_CTRL_TOG_DATA_SELECT_SHIFT         (16U)
/*! DATA_SELECT
 *  0b0..Command Mode. LCD_RS signal is Low.
 *  0b1..Data Mode. LCD_RS signal is High.
 */
#define LCDIF_CTRL_TOG_DATA_SELECT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_SELECT_SHIFT)) & LCDIF_CTRL_TOG_DATA_SELECT_MASK)

#define LCDIF_CTRL_TOG_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_TOG_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_TOG_VSYNC_MODE_MASK           (0x40000U)
#define LCDIF_CTRL_TOG_VSYNC_MODE_SHIFT          (18U)
#define LCDIF_CTRL_TOG_VSYNC_MODE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_VSYNC_MODE_SHIFT)) & LCDIF_CTRL_TOG_VSYNC_MODE_MASK)

#define LCDIF_CTRL_TOG_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_TOG_BYPASS_COUNT_MASK)

#define LCDIF_CTRL_TOG_DVI_MODE_MASK             (0x100000U)
#define LCDIF_CTRL_TOG_DVI_MODE_SHIFT            (20U)
#define LCDIF_CTRL_TOG_DVI_MODE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DVI_MODE_SHIFT)) & LCDIF_CTRL_TOG_DVI_MODE_MASK)

#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS_MASK       (0x3E00000U)
#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS_SHIFT      (21U)
#define LCDIF_CTRL_TOG_SHIFT_NUM_BITS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_SHIFT_NUM_BITS_SHIFT)) & LCDIF_CTRL_TOG_SHIFT_NUM_BITS_MASK)

#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR_MASK       (0x4000000U)
#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR_SHIFT      (26U)
/*! DATA_SHIFT_DIR
 *  0b0..Data to be transmitted is shifted LEFT by SHIFT_NUM_BITS bits.
 *  0b1..Data to be transmitted is shifted RIGHT by SHIFT_NUM_BITS bits.
 */
#define LCDIF_CTRL_TOG_DATA_SHIFT_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DATA_SHIFT_DIR_SHIFT)) & LCDIF_CTRL_TOG_DATA_SHIFT_DIR_MASK)

#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_MASK  (0x8000000U)
#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_SHIFT (27U)
#define LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_SHIFT)) & LCDIF_CTRL_TOG_WAIT_FOR_VSYNC_EDGE_MASK)

#define LCDIF_CTRL_TOG_READ_WRITEB_MASK          (0x10000000U)
#define LCDIF_CTRL_TOG_READ_WRITEB_SHIFT         (28U)
#define LCDIF_CTRL_TOG_READ_WRITEB(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_READ_WRITEB_SHIFT)) & LCDIF_CTRL_TOG_READ_WRITEB_MASK)

#define LCDIF_CTRL_TOG_YCBCR422_INPUT_MASK       (0x20000000U)
#define LCDIF_CTRL_TOG_YCBCR422_INPUT_SHIFT      (29U)
#define LCDIF_CTRL_TOG_YCBCR422_INPUT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_YCBCR422_INPUT_SHIFT)) & LCDIF_CTRL_TOG_YCBCR422_INPUT_MASK)

#define LCDIF_CTRL_TOG_CLKGATE_MASK              (0x40000000U)
#define LCDIF_CTRL_TOG_CLKGATE_SHIFT             (30U)
#define LCDIF_CTRL_TOG_CLKGATE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_CLKGATE_SHIFT)) & LCDIF_CTRL_TOG_CLKGATE_MASK)

#define LCDIF_CTRL_TOG_SFTRST_MASK               (0x80000000U)
#define LCDIF_CTRL_TOG_SFTRST_SHIFT              (31U)
#define LCDIF_CTRL_TOG_SFTRST(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_SFTRST_SHIFT)) & LCDIF_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name CTRL1 - LCDIF General Control1 Register */
/*! @{ */

#define LCDIF_CTRL1_RESET_MASK                   (0x1U)
#define LCDIF_CTRL1_RESET_SHIFT                  (0U)
/*! RESET
 *  0b0..LCD_RESET output signal is low.
 *  0b1..LCD_RESET output signal is high.
 */
#define LCDIF_CTRL1_RESET(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RESET_SHIFT)) & LCDIF_CTRL1_RESET_MASK)

#define LCDIF_CTRL1_MODE86_MASK                  (0x2U)
#define LCDIF_CTRL1_MODE86_SHIFT                 (1U)
/*! MODE86
 *  0b0..Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
 *  0b1..Pins LCD_WR_RWn and LCD_RD_E function as Read/Write and active high Enable signals respectively.
 */
#define LCDIF_CTRL1_MODE86(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_MODE86_SHIFT)) & LCDIF_CTRL1_MODE86_MASK)

#define LCDIF_CTRL1_BUSY_ENABLE_MASK             (0x4U)
#define LCDIF_CTRL1_BUSY_ENABLE_SHIFT            (2U)
/*! BUSY_ENABLE
 *  0b0..The busy signal from the LCD controller will be ignored.
 *  0b1..Enable the use of the busy signal from the LCD controller.
 */
#define LCDIF_CTRL1_BUSY_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_BUSY_ENABLE_MASK)

#define LCDIF_CTRL1_RSRVD0_MASK                  (0xF8U)
#define LCDIF_CTRL1_RSRVD0_SHIFT                 (3U)
#define LCDIF_CTRL1_RSRVD0(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RSRVD0_SHIFT)) & LCDIF_CTRL1_RSRVD0_MASK)

#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK          (0x100U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_SHIFT         (8U)
/*! VSYNC_EDGE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_VSYNC_EDGE_IRQ_MASK)

#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_MASK      (0x200U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_SHIFT     (9U)
/*! CUR_FRAME_DONE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_MASK)

#define LCDIF_CTRL1_UNDERFLOW_IRQ_MASK           (0x400U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_SHIFT          (10U)
/*! UNDERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_UNDERFLOW_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_UNDERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_OVERFLOW_IRQ_MASK            (0x800U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_SHIFT           (11U)
/*! OVERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_OVERFLOW_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_OVERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_MASK       (0x1000U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_SHIFT      (12U)
#define LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_VSYNC_EDGE_IRQ_EN_MASK)

#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_MASK   (0x2000U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_SHIFT  (13U)
#define LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CUR_FRAME_DONE_IRQ_EN_MASK)

#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN_MASK        (0x4000U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN_SHIFT       (14U)
#define LCDIF_CTRL1_UNDERFLOW_IRQ_EN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_UNDERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_OVERFLOW_IRQ_EN_MASK         (0x8000U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_EN_SHIFT        (15U)
#define LCDIF_CTRL1_OVERFLOW_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_OVERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_BYTE_PACKING_FORMAT_MASK     (0xF0000U)
#define LCDIF_CTRL1_BYTE_PACKING_FORMAT_SHIFT    (16U)
#define LCDIF_CTRL1_BYTE_PACKING_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_BYTE_PACKING_FORMAT_MASK)

#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_IRQ_ON_ALTERNATE_FIELDS_MASK)

#define LCDIF_CTRL1_FIFO_CLEAR_MASK              (0x200000U)
#define LCDIF_CTRL1_FIFO_CLEAR_SHIFT             (21U)
#define LCDIF_CTRL1_FIFO_CLEAR(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_FIFO_CLEAR_MASK)

#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_START_INTERLACE_FROM_SECOND_FIELD_MASK)

#define LCDIF_CTRL1_INTERLACE_FIELDS_MASK        (0x800000U)
#define LCDIF_CTRL1_INTERLACE_FIELDS_SHIFT       (23U)
#define LCDIF_CTRL1_INTERLACE_FIELDS(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_INTERLACE_FIELDS_MASK)

#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_MASK    (0x1000000U)
#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_SHIFT   (24U)
#define LCDIF_CTRL1_RECOVER_ON_UNDERFLOW(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_RECOVER_ON_UNDERFLOW_MASK)

#define LCDIF_CTRL1_BM_ERROR_IRQ_MASK            (0x2000000U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_SHIFT           (25U)
/*! BM_ERROR_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_BM_ERROR_IRQ(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_BM_ERROR_IRQ_MASK)

#define LCDIF_CTRL1_BM_ERROR_IRQ_EN_MASK         (0x4000000U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_EN_SHIFT        (26U)
#define LCDIF_CTRL1_BM_ERROR_IRQ_EN(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_BM_ERROR_IRQ_EN_MASK)

#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB_MASK     (0x8000000U)
#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB_SHIFT    (27U)
#define LCDIF_CTRL1_COMBINE_MPU_WR_STRB(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_COMBINE_MPU_WR_STRB_MASK)
/*! @} */

/*! @name CTRL1_SET - LCDIF General Control1 Register */
/*! @{ */

#define LCDIF_CTRL1_SET_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_SET_RESET_SHIFT              (0U)
/*! RESET
 *  0b0..LCD_RESET output signal is low.
 *  0b1..LCD_RESET output signal is high.
 */
#define LCDIF_CTRL1_SET_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RESET_SHIFT)) & LCDIF_CTRL1_SET_RESET_MASK)

#define LCDIF_CTRL1_SET_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_SET_MODE86_SHIFT             (1U)
/*! MODE86
 *  0b0..Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
 *  0b1..Pins LCD_WR_RWn and LCD_RD_E function as Read/Write and active high Enable signals respectively.
 */
#define LCDIF_CTRL1_SET_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_MODE86_SHIFT)) & LCDIF_CTRL1_SET_MODE86_MASK)

#define LCDIF_CTRL1_SET_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_SET_BUSY_ENABLE_SHIFT        (2U)
/*! BUSY_ENABLE
 *  0b0..The busy signal from the LCD controller will be ignored.
 *  0b1..Enable the use of the busy signal from the LCD controller.
 */
#define LCDIF_CTRL1_SET_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_SET_BUSY_ENABLE_MASK)

#define LCDIF_CTRL1_SET_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_SET_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_SET_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RSRVD0_SHIFT)) & LCDIF_CTRL1_SET_RSRVD0_MASK)

#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_SHIFT     (8U)
/*! VSYNC_EDGE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_MASK)

#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_SHIFT (9U)
/*! CUR_FRAME_DONE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_MASK)

#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_SHIFT      (10U)
/*! UNDERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_SET_UNDERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_SHIFT       (11U)
/*! OVERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_SET_OVERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_VSYNC_EDGE_IRQ_EN_MASK)

#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_CUR_FRAME_DONE_IRQ_EN_MASK)

#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_UNDERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_OVERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_SET_BYTE_PACKING_FORMAT_MASK)

#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_SET_IRQ_ON_ALTERNATE_FIELDS_MASK)

#define LCDIF_CTRL1_SET_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_SET_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_SET_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_SET_FIFO_CLEAR_MASK)

#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_SET_START_INTERLACE_FROM_SECOND_FIELD_MASK)

#define LCDIF_CTRL1_SET_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_SET_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_SET_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_SET_INTERLACE_FIELDS_MASK)

#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_SET_RECOVER_ON_UNDERFLOW_MASK)

#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_SHIFT       (25U)
/*! BM_ERROR_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_SET_BM_ERROR_IRQ_MASK)

#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_SET_BM_ERROR_IRQ_EN_MASK)

#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_SET_COMBINE_MPU_WR_STRB_MASK)
/*! @} */

/*! @name CTRL1_CLR - LCDIF General Control1 Register */
/*! @{ */

#define LCDIF_CTRL1_CLR_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_CLR_RESET_SHIFT              (0U)
/*! RESET
 *  0b0..LCD_RESET output signal is low.
 *  0b1..LCD_RESET output signal is high.
 */
#define LCDIF_CTRL1_CLR_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RESET_SHIFT)) & LCDIF_CTRL1_CLR_RESET_MASK)

#define LCDIF_CTRL1_CLR_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_CLR_MODE86_SHIFT             (1U)
/*! MODE86
 *  0b0..Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
 *  0b1..Pins LCD_WR_RWn and LCD_RD_E function as Read/Write and active high Enable signals respectively.
 */
#define LCDIF_CTRL1_CLR_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_MODE86_SHIFT)) & LCDIF_CTRL1_CLR_MODE86_MASK)

#define LCDIF_CTRL1_CLR_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_CLR_BUSY_ENABLE_SHIFT        (2U)
/*! BUSY_ENABLE
 *  0b0..The busy signal from the LCD controller will be ignored.
 *  0b1..Enable the use of the busy signal from the LCD controller.
 */
#define LCDIF_CTRL1_CLR_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_CLR_BUSY_ENABLE_MASK)

#define LCDIF_CTRL1_CLR_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_CLR_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_CLR_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL1_CLR_RSRVD0_MASK)

#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_SHIFT     (8U)
/*! VSYNC_EDGE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_MASK)

#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_SHIFT (9U)
/*! CUR_FRAME_DONE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_MASK)

#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_SHIFT      (10U)
/*! UNDERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_SHIFT       (11U)
/*! OVERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_OVERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_VSYNC_EDGE_IRQ_EN_MASK)

#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_CUR_FRAME_DONE_IRQ_EN_MASK)

#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_UNDERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_OVERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_CLR_BYTE_PACKING_FORMAT_MASK)

#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_CLR_IRQ_ON_ALTERNATE_FIELDS_MASK)

#define LCDIF_CTRL1_CLR_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_CLR_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_CLR_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_CLR_FIFO_CLEAR_MASK)

#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_CLR_START_INTERLACE_FROM_SECOND_FIELD_MASK)

#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_CLR_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_CLR_INTERLACE_FIELDS_MASK)

#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_CLR_RECOVER_ON_UNDERFLOW_MASK)

#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_SHIFT       (25U)
/*! BM_ERROR_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_CLR_BM_ERROR_IRQ_MASK)

#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_CLR_BM_ERROR_IRQ_EN_MASK)

#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_CLR_COMBINE_MPU_WR_STRB_MASK)
/*! @} */

/*! @name CTRL1_TOG - LCDIF General Control1 Register */
/*! @{ */

#define LCDIF_CTRL1_TOG_RESET_MASK               (0x1U)
#define LCDIF_CTRL1_TOG_RESET_SHIFT              (0U)
/*! RESET
 *  0b0..LCD_RESET output signal is low.
 *  0b1..LCD_RESET output signal is high.
 */
#define LCDIF_CTRL1_TOG_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RESET_SHIFT)) & LCDIF_CTRL1_TOG_RESET_MASK)

#define LCDIF_CTRL1_TOG_MODE86_MASK              (0x2U)
#define LCDIF_CTRL1_TOG_MODE86_SHIFT             (1U)
/*! MODE86
 *  0b0..Pins LCD_WR_RWn and LCD_RD_E function as active low WR and active low RD signals respectively.
 *  0b1..Pins LCD_WR_RWn and LCD_RD_E function as Read/Write and active high Enable signals respectively.
 */
#define LCDIF_CTRL1_TOG_MODE86(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_MODE86_SHIFT)) & LCDIF_CTRL1_TOG_MODE86_MASK)

#define LCDIF_CTRL1_TOG_BUSY_ENABLE_MASK         (0x4U)
#define LCDIF_CTRL1_TOG_BUSY_ENABLE_SHIFT        (2U)
/*! BUSY_ENABLE
 *  0b0..The busy signal from the LCD controller will be ignored.
 *  0b1..Enable the use of the busy signal from the LCD controller.
 */
#define LCDIF_CTRL1_TOG_BUSY_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BUSY_ENABLE_SHIFT)) & LCDIF_CTRL1_TOG_BUSY_ENABLE_MASK)

#define LCDIF_CTRL1_TOG_RSRVD0_MASK              (0xF8U)
#define LCDIF_CTRL1_TOG_RSRVD0_SHIFT             (3U)
#define LCDIF_CTRL1_TOG_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL1_TOG_RSRVD0_MASK)

#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_MASK      (0x100U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_SHIFT     (8U)
/*! VSYNC_EDGE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_MASK)

#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_MASK  (0x200U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_SHIFT (9U)
/*! CUR_FRAME_DONE_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_MASK)

#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_MASK       (0x400U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_SHIFT      (10U)
/*! UNDERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_MASK        (0x800U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_SHIFT       (11U)
/*! OVERFLOW_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_OVERFLOW_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_OVERFLOW_IRQ_MASK)

#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_MASK   (0x1000U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_SHIFT  (12U)
#define LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_VSYNC_EDGE_IRQ_EN_MASK)

#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_MASK (0x2000U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_SHIFT (13U)
#define LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_CUR_FRAME_DONE_IRQ_EN_MASK)

#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_MASK    (0x4000U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_SHIFT   (14U)
#define LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_UNDERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_MASK     (0x8000U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_SHIFT    (15U)
#define LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_OVERFLOW_IRQ_EN_MASK)

#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_MASK (0xF0000U)
#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_SHIFT (16U)
#define LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_SHIFT)) & LCDIF_CTRL1_TOG_BYTE_PACKING_FORMAT_MASK)

#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_MASK (0x100000U)
#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_SHIFT (20U)
#define LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_SHIFT)) & LCDIF_CTRL1_TOG_IRQ_ON_ALTERNATE_FIELDS_MASK)

#define LCDIF_CTRL1_TOG_FIFO_CLEAR_MASK          (0x200000U)
#define LCDIF_CTRL1_TOG_FIFO_CLEAR_SHIFT         (21U)
#define LCDIF_CTRL1_TOG_FIFO_CLEAR(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_FIFO_CLEAR_SHIFT)) & LCDIF_CTRL1_TOG_FIFO_CLEAR_MASK)

#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_MASK (0x400000U)
#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_SHIFT (22U)
#define LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_SHIFT)) & LCDIF_CTRL1_TOG_START_INTERLACE_FROM_SECOND_FIELD_MASK)

#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS_MASK    (0x800000U)
#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS_SHIFT   (23U)
#define LCDIF_CTRL1_TOG_INTERLACE_FIELDS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_INTERLACE_FIELDS_SHIFT)) & LCDIF_CTRL1_TOG_INTERLACE_FIELDS_MASK)

#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_MASK (0x1000000U)
#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_SHIFT (24U)
#define LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_SHIFT)) & LCDIF_CTRL1_TOG_RECOVER_ON_UNDERFLOW_MASK)

#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_MASK        (0x2000000U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_SHIFT       (25U)
/*! BM_ERROR_IRQ
 *  0b0..No Interrupt Request Pending.
 *  0b1..Interrupt Request Pending.
 */
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BM_ERROR_IRQ_SHIFT)) & LCDIF_CTRL1_TOG_BM_ERROR_IRQ_MASK)

#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_MASK     (0x4000000U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_SHIFT    (26U)
#define LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_SHIFT)) & LCDIF_CTRL1_TOG_BM_ERROR_IRQ_EN_MASK)

#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_MASK (0x8000000U)
#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_SHIFT (27U)
#define LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_SHIFT)) & LCDIF_CTRL1_TOG_COMBINE_MPU_WR_STRB_MASK)
/*! @} */

/*! @name CTRL2 - LCDIF General Control2 Register */
/*! @{ */

#define LCDIF_CTRL2_RSRVD0_MASK                  (0x1U)
#define LCDIF_CTRL2_RSRVD0_SHIFT                 (0U)
#define LCDIF_CTRL2_RSRVD0(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD0_SHIFT)) & LCDIF_CTRL2_RSRVD0_MASK)

#define LCDIF_CTRL2_INITIAL_DUMMY_READ_MASK      (0xEU)
#define LCDIF_CTRL2_INITIAL_DUMMY_READ_SHIFT     (1U)
#define LCDIF_CTRL2_INITIAL_DUMMY_READ(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_INITIAL_DUMMY_READ_MASK)

#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_READ_MODE_NUM_PACKED_SUBWORDS_MASK)

#define LCDIF_CTRL2_RSRVD1_MASK                  (0x80U)
#define LCDIF_CTRL2_RSRVD1_SHIFT                 (7U)
#define LCDIF_CTRL2_RSRVD1(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD1_SHIFT)) & LCDIF_CTRL2_RSRVD1_MASK)

#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_MASK   (0x100U)
#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_SHIFT  (8U)
#define LCDIF_CTRL2_READ_MODE_6_BIT_INPUT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_READ_MODE_6_BIT_INPUT_MASK)

#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)

#define LCDIF_CTRL2_READ_PACK_DIR_MASK           (0x400U)
#define LCDIF_CTRL2_READ_PACK_DIR_SHIFT          (10U)
#define LCDIF_CTRL2_READ_PACK_DIR(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_READ_PACK_DIR_MASK)

#define LCDIF_CTRL2_RSRVD2_MASK                  (0x800U)
#define LCDIF_CTRL2_RSRVD2_SHIFT                 (11U)
#define LCDIF_CTRL2_RSRVD2(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD2_SHIFT)) & LCDIF_CTRL2_RSRVD2_MASK)

#define LCDIF_CTRL2_EVEN_LINE_PATTERN_MASK       (0x7000U)
#define LCDIF_CTRL2_EVEN_LINE_PATTERN_SHIFT      (12U)
/*! EVEN_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_EVEN_LINE_PATTERN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_EVEN_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_RSRVD3_MASK                  (0x8000U)
#define LCDIF_CTRL2_RSRVD3_SHIFT                 (15U)
#define LCDIF_CTRL2_RSRVD3(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD3_SHIFT)) & LCDIF_CTRL2_RSRVD3_MASK)

#define LCDIF_CTRL2_ODD_LINE_PATTERN_MASK        (0x70000U)
#define LCDIF_CTRL2_ODD_LINE_PATTERN_SHIFT       (16U)
/*! ODD_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_ODD_LINE_PATTERN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_ODD_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_RSRVD4_MASK                  (0x80000U)
#define LCDIF_CTRL2_RSRVD4_SHIFT                 (19U)
#define LCDIF_CTRL2_RSRVD4(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD4_SHIFT)) & LCDIF_CTRL2_RSRVD4_MASK)

#define LCDIF_CTRL2_BURST_LEN_8_MASK             (0x100000U)
#define LCDIF_CTRL2_BURST_LEN_8_SHIFT            (20U)
#define LCDIF_CTRL2_BURST_LEN_8(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_BURST_LEN_8_MASK)

#define LCDIF_CTRL2_OUTSTANDING_REQS_MASK        (0xE00000U)
#define LCDIF_CTRL2_OUTSTANDING_REQS_SHIFT       (21U)
/*! OUTSTANDING_REQS
 *  0b000..REQ_1
 *  0b001..REQ_2
 *  0b010..REQ_4
 *  0b011..REQ_8
 *  0b100..REQ_16
 */
#define LCDIF_CTRL2_OUTSTANDING_REQS(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_OUTSTANDING_REQS_MASK)

#define LCDIF_CTRL2_RSRVD5_MASK                  (0xFF000000U)
#define LCDIF_CTRL2_RSRVD5_SHIFT                 (24U)
#define LCDIF_CTRL2_RSRVD5(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD5_SHIFT)) & LCDIF_CTRL2_RSRVD5_MASK)
/*! @} */

/*! @name CTRL2_SET - LCDIF General Control2 Register */
/*! @{ */

#define LCDIF_CTRL2_SET_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_SET_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_SET_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD0_SHIFT)) & LCDIF_CTRL2_SET_RSRVD0_MASK)

#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_SET_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_SET_INITIAL_DUMMY_READ_MASK)

#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_NUM_PACKED_SUBWORDS_MASK)

#define LCDIF_CTRL2_SET_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_SET_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_SET_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD1_SHIFT)) & LCDIF_CTRL2_SET_RSRVD1_MASK)

#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_6_BIT_INPUT_MASK)

#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_SET_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)

#define LCDIF_CTRL2_SET_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_SET_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_SET_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_SET_READ_PACK_DIR_MASK)

#define LCDIF_CTRL2_SET_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_SET_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_SET_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD2_SHIFT)) & LCDIF_CTRL2_SET_RSRVD2_MASK)

#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_SHIFT  (12U)
/*! EVEN_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_SET_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_SET_EVEN_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_SET_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_SET_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_SET_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD3_SHIFT)) & LCDIF_CTRL2_SET_RSRVD3_MASK)

#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN_SHIFT   (16U)
/*! ODD_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_SET_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_SET_ODD_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_SET_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_SET_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_SET_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD4_SHIFT)) & LCDIF_CTRL2_SET_RSRVD4_MASK)

#define LCDIF_CTRL2_SET_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_SET_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_SET_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_SET_BURST_LEN_8_MASK)

#define LCDIF_CTRL2_SET_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_SET_OUTSTANDING_REQS_SHIFT   (21U)
/*! OUTSTANDING_REQS
 *  0b000..REQ_1
 *  0b001..REQ_2
 *  0b010..REQ_4
 *  0b011..REQ_8
 *  0b100..REQ_16
 */
#define LCDIF_CTRL2_SET_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_SET_OUTSTANDING_REQS_MASK)

#define LCDIF_CTRL2_SET_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_SET_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_SET_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD5_SHIFT)) & LCDIF_CTRL2_SET_RSRVD5_MASK)
/*! @} */

/*! @name CTRL2_CLR - LCDIF General Control2 Register */
/*! @{ */

#define LCDIF_CTRL2_CLR_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_CLR_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_CLR_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD0_MASK)

#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_CLR_INITIAL_DUMMY_READ_MASK)

#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_NUM_PACKED_SUBWORDS_MASK)

#define LCDIF_CTRL2_CLR_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_CLR_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_CLR_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD1_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD1_MASK)

#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_6_BIT_INPUT_MASK)

#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_CLR_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)

#define LCDIF_CTRL2_CLR_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_CLR_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_CLR_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_CLR_READ_PACK_DIR_MASK)

#define LCDIF_CTRL2_CLR_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_CLR_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_CLR_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD2_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD2_MASK)

#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_SHIFT  (12U)
/*! EVEN_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_CLR_EVEN_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_CLR_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_CLR_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_CLR_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD3_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD3_MASK)

#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_SHIFT   (16U)
/*! ODD_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_CLR_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_CLR_ODD_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_CLR_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_CLR_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_CLR_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD4_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD4_MASK)

#define LCDIF_CTRL2_CLR_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_CLR_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_CLR_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_CLR_BURST_LEN_8_MASK)

#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS_SHIFT   (21U)
/*! OUTSTANDING_REQS
 *  0b000..REQ_1
 *  0b001..REQ_2
 *  0b010..REQ_4
 *  0b011..REQ_8
 *  0b100..REQ_16
 */
#define LCDIF_CTRL2_CLR_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_CLR_OUTSTANDING_REQS_MASK)

#define LCDIF_CTRL2_CLR_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_CLR_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_CLR_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD5_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD5_MASK)
/*! @} */

/*! @name CTRL2_TOG - LCDIF General Control2 Register */
/*! @{ */

#define LCDIF_CTRL2_TOG_RSRVD0_MASK              (0x1U)
#define LCDIF_CTRL2_TOG_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_TOG_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD0_MASK)

#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_MASK  (0xEU)
#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_SHIFT (1U)
#define LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_SHIFT)) & LCDIF_CTRL2_TOG_INITIAL_DUMMY_READ_MASK)

#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_MASK (0x70U)
#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT (4U)
#define LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_NUM_PACKED_SUBWORDS_MASK)

#define LCDIF_CTRL2_TOG_RSRVD1_MASK              (0x80U)
#define LCDIF_CTRL2_TOG_RSRVD1_SHIFT             (7U)
#define LCDIF_CTRL2_TOG_RSRVD1(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD1_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD1_MASK)

#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_MASK (0x100U)
#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_SHIFT (8U)
#define LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_6_BIT_INPUT_MASK)

#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK (0x200U)
#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT (9U)
#define LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_SHIFT)) & LCDIF_CTRL2_TOG_READ_MODE_OUTPUT_IN_RGB_FORMAT_MASK)

#define LCDIF_CTRL2_TOG_READ_PACK_DIR_MASK       (0x400U)
#define LCDIF_CTRL2_TOG_READ_PACK_DIR_SHIFT      (10U)
#define LCDIF_CTRL2_TOG_READ_PACK_DIR(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_READ_PACK_DIR_SHIFT)) & LCDIF_CTRL2_TOG_READ_PACK_DIR_MASK)

#define LCDIF_CTRL2_TOG_RSRVD2_MASK              (0x800U)
#define LCDIF_CTRL2_TOG_RSRVD2_SHIFT             (11U)
#define LCDIF_CTRL2_TOG_RSRVD2(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD2_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD2_MASK)

#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_MASK   (0x7000U)
#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_SHIFT  (12U)
/*! EVEN_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_TOG_EVEN_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_TOG_RSRVD3_MASK              (0x8000U)
#define LCDIF_CTRL2_TOG_RSRVD3_SHIFT             (15U)
#define LCDIF_CTRL2_TOG_RSRVD3(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD3_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD3_MASK)

#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_MASK    (0x70000U)
#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_SHIFT   (16U)
/*! ODD_LINE_PATTERN
 *  0b000..RGB
 *  0b001..RBG
 *  0b010..GBR
 *  0b011..GRB
 *  0b100..BRG
 *  0b101..BGR
 */
#define LCDIF_CTRL2_TOG_ODD_LINE_PATTERN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_SHIFT)) & LCDIF_CTRL2_TOG_ODD_LINE_PATTERN_MASK)

#define LCDIF_CTRL2_TOG_RSRVD4_MASK              (0x80000U)
#define LCDIF_CTRL2_TOG_RSRVD4_SHIFT             (19U)
#define LCDIF_CTRL2_TOG_RSRVD4(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD4_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD4_MASK)

#define LCDIF_CTRL2_TOG_BURST_LEN_8_MASK         (0x100000U)
#define LCDIF_CTRL2_TOG_BURST_LEN_8_SHIFT        (20U)
#define LCDIF_CTRL2_TOG_BURST_LEN_8(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_BURST_LEN_8_SHIFT)) & LCDIF_CTRL2_TOG_BURST_LEN_8_MASK)

#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS_MASK    (0xE00000U)
#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS_SHIFT   (21U)
/*! OUTSTANDING_REQS
 *  0b000..REQ_1
 *  0b001..REQ_2
 *  0b010..REQ_4
 *  0b011..REQ_8
 *  0b100..REQ_16
 */
#define LCDIF_CTRL2_TOG_OUTSTANDING_REQS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_OUTSTANDING_REQS_SHIFT)) & LCDIF_CTRL2_TOG_OUTSTANDING_REQS_MASK)

#define LCDIF_CTRL2_TOG_RSRVD5_MASK              (0xFF000000U)
#define LCDIF_CTRL2_TOG_RSRVD5_SHIFT             (24U)
#define LCDIF_CTRL2_TOG_RSRVD5(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD5_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD5_MASK)
/*! @} */

/*! @name TRANSFER_COUNT - LCDIF Horizontal and Vertical Valid Data Count Register */
/*! @{ */

#define LCDIF_TRANSFER_COUNT_H_COUNT_MASK        (0xFFFFU)
#define LCDIF_TRANSFER_COUNT_H_COUNT_SHIFT       (0U)
#define LCDIF_TRANSFER_COUNT_H_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_TRANSFER_COUNT_H_COUNT_SHIFT)) & LCDIF_TRANSFER_COUNT_H_COUNT_MASK)

#define LCDIF_TRANSFER_COUNT_V_COUNT_MASK        (0xFFFF0000U)
#define LCDIF_TRANSFER_COUNT_V_COUNT_SHIFT       (16U)
#define LCDIF_TRANSFER_COUNT_V_COUNT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_TRANSFER_COUNT_V_COUNT_SHIFT)) & LCDIF_TRANSFER_COUNT_V_COUNT_MASK)
/*! @} */

/*! @name CUR_BUF - LCD Interface Current Buffer Address Register */
/*! @{ */

#define LCDIF_CUR_BUF_ADDR_MASK                  (0xFFFFFFFFU)
#define LCDIF_CUR_BUF_ADDR_SHIFT                 (0U)
#define LCDIF_CUR_BUF_ADDR(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CUR_BUF_ADDR_SHIFT)) & LCDIF_CUR_BUF_ADDR_MASK)
/*! @} */

/*! @name NEXT_BUF - LCD Interface Next Buffer Address Register */
/*! @{ */

#define LCDIF_NEXT_BUF_ADDR_MASK                 (0xFFFFFFFFU)
#define LCDIF_NEXT_BUF_ADDR_SHIFT                (0U)
#define LCDIF_NEXT_BUF_ADDR(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_NEXT_BUF_ADDR_SHIFT)) & LCDIF_NEXT_BUF_ADDR_MASK)
/*! @} */

/*! @name TIMING - LCD Interface Timing Register */
/*! @{ */

#define LCDIF_TIMING_DATA_SETUP_MASK             (0xFFU)
#define LCDIF_TIMING_DATA_SETUP_SHIFT            (0U)
#define LCDIF_TIMING_DATA_SETUP(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_DATA_SETUP_SHIFT)) & LCDIF_TIMING_DATA_SETUP_MASK)

#define LCDIF_TIMING_DATA_HOLD_MASK              (0xFF00U)
#define LCDIF_TIMING_DATA_HOLD_SHIFT             (8U)
#define LCDIF_TIMING_DATA_HOLD(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_DATA_HOLD_SHIFT)) & LCDIF_TIMING_DATA_HOLD_MASK)

#define LCDIF_TIMING_CMD_SETUP_MASK              (0xFF0000U)
#define LCDIF_TIMING_CMD_SETUP_SHIFT             (16U)
#define LCDIF_TIMING_CMD_SETUP(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_CMD_SETUP_SHIFT)) & LCDIF_TIMING_CMD_SETUP_MASK)

#define LCDIF_TIMING_CMD_HOLD_MASK               (0xFF000000U)
#define LCDIF_TIMING_CMD_HOLD_SHIFT              (24U)
#define LCDIF_TIMING_CMD_HOLD(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_TIMING_CMD_HOLD_SHIFT)) & LCDIF_TIMING_CMD_HOLD_MASK)
/*! @} */

/*! @name VDCTRL0 - LCDIF VSYNC Mode and Dotclk Mode Control Register0 */
/*! @{ */

#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_MASK     (0x3FFFFU)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_SHIFT    (0U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_MASK)

#define LCDIF_VDCTRL0_HALF_LINE_MODE_MASK        (0x40000U)
#define LCDIF_VDCTRL0_HALF_LINE_MODE_SHIFT       (18U)
#define LCDIF_VDCTRL0_HALF_LINE_MODE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_HALF_LINE_MODE_MASK)

#define LCDIF_VDCTRL0_HALF_LINE_MASK             (0x80000U)
#define LCDIF_VDCTRL0_HALF_LINE_SHIFT            (19U)
#define LCDIF_VDCTRL0_HALF_LINE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_HALF_LINE_MASK)

#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PULSE_WIDTH_UNIT_MASK)

#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_MASK     (0x200000U)
#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_SHIFT    (21U)
#define LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_VSYNC_PERIOD_UNIT_MASK)

#define LCDIF_VDCTRL0_RSRVD1_MASK                (0xC00000U)
#define LCDIF_VDCTRL0_RSRVD1_SHIFT               (22U)
#define LCDIF_VDCTRL0_RSRVD1(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_RSRVD1_MASK)

#define LCDIF_VDCTRL0_ENABLE_POL_MASK            (0x1000000U)
#define LCDIF_VDCTRL0_ENABLE_POL_SHIFT           (24U)
#define LCDIF_VDCTRL0_ENABLE_POL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_ENABLE_POL_MASK)

#define LCDIF_VDCTRL0_DOTCLK_POL_MASK            (0x2000000U)
#define LCDIF_VDCTRL0_DOTCLK_POL_SHIFT           (25U)
#define LCDIF_VDCTRL0_DOTCLK_POL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_DOTCLK_POL_MASK)

#define LCDIF_VDCTRL0_HSYNC_POL_MASK             (0x4000000U)
#define LCDIF_VDCTRL0_HSYNC_POL_SHIFT            (26U)
#define LCDIF_VDCTRL0_HSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_HSYNC_POL_MASK)

#define LCDIF_VDCTRL0_VSYNC_POL_MASK             (0x8000000U)
#define LCDIF_VDCTRL0_VSYNC_POL_SHIFT            (27U)
#define LCDIF_VDCTRL0_VSYNC_POL(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_VSYNC_POL_MASK)

#define LCDIF_VDCTRL0_ENABLE_PRESENT_MASK        (0x10000000U)
#define LCDIF_VDCTRL0_ENABLE_PRESENT_SHIFT       (28U)
#define LCDIF_VDCTRL0_ENABLE_PRESENT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_ENABLE_PRESENT_MASK)

#define LCDIF_VDCTRL0_VSYNC_OEB_MASK             (0x20000000U)
#define LCDIF_VDCTRL0_VSYNC_OEB_SHIFT            (29U)
/*! VSYNC_OEB
 *  0b0..The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the LCDIF block.
 *  0b1..The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.
 */
#define LCDIF_VDCTRL0_VSYNC_OEB(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_VSYNC_OEB_MASK)

#define LCDIF_VDCTRL0_RSRVD2_MASK                (0xC0000000U)
#define LCDIF_VDCTRL0_RSRVD2_SHIFT               (30U)
#define LCDIF_VDCTRL0_RSRVD2(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_RSRVD2_MASK)
/*! @} */

/*! @name VDCTRL0_SET - LCDIF VSYNC Mode and Dotclk Mode Control Register0 */
/*! @{ */

#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_MASK)

#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_SET_HALF_LINE_MODE_MASK)

#define LCDIF_VDCTRL0_SET_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_SET_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_SET_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_SET_HALF_LINE_MASK)

#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PULSE_WIDTH_UNIT_MASK)

#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_PERIOD_UNIT_MASK)

#define LCDIF_VDCTRL0_SET_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_SET_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_SET_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_SET_RSRVD1_MASK)

#define LCDIF_VDCTRL0_SET_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_SET_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_SET_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_SET_ENABLE_POL_MASK)

#define LCDIF_VDCTRL0_SET_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_SET_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_SET_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_SET_DOTCLK_POL_MASK)

#define LCDIF_VDCTRL0_SET_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_SET_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_SET_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_SET_HSYNC_POL_MASK)

#define LCDIF_VDCTRL0_SET_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_SET_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_SET_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_POL_MASK)

#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_SET_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_SET_ENABLE_PRESENT_MASK)

#define LCDIF_VDCTRL0_SET_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_SET_VSYNC_OEB_SHIFT        (29U)
/*! VSYNC_OEB
 *  0b0..The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the LCDIF block.
 *  0b1..The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.
 */
#define LCDIF_VDCTRL0_SET_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_SET_VSYNC_OEB_MASK)

#define LCDIF_VDCTRL0_SET_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_SET_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_SET_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_SET_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_SET_RSRVD2_MASK)
/*! @} */

/*! @name VDCTRL0_CLR - LCDIF VSYNC Mode and Dotclk Mode Control Register0 */
/*! @{ */

#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_MASK)

#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_CLR_HALF_LINE_MODE_MASK)

#define LCDIF_VDCTRL0_CLR_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_CLR_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_CLR_HALF_LINE_MASK)

#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PULSE_WIDTH_UNIT_MASK)

#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_PERIOD_UNIT_MASK)

#define LCDIF_VDCTRL0_CLR_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_CLR_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_CLR_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_CLR_RSRVD1_MASK)

#define LCDIF_VDCTRL0_CLR_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_CLR_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_CLR_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_ENABLE_POL_MASK)

#define LCDIF_VDCTRL0_CLR_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_CLR_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_CLR_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_DOTCLK_POL_MASK)

#define LCDIF_VDCTRL0_CLR_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_CLR_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_CLR_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_HSYNC_POL_MASK)

#define LCDIF_VDCTRL0_CLR_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_CLR_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_POL_MASK)

#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_CLR_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_CLR_ENABLE_PRESENT_MASK)

#define LCDIF_VDCTRL0_CLR_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_CLR_VSYNC_OEB_SHIFT        (29U)
/*! VSYNC_OEB
 *  0b0..The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the LCDIF block.
 *  0b1..The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.
 */
#define LCDIF_VDCTRL0_CLR_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_CLR_VSYNC_OEB_MASK)

#define LCDIF_VDCTRL0_CLR_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_CLR_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_CLR_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_CLR_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_CLR_RSRVD2_MASK)
/*! @} */

/*! @name VDCTRL0_TOG - LCDIF VSYNC Mode and Dotclk Mode Control Register0 */
/*! @{ */

#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_MASK (0x3FFFFU)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_SHIFT (0U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_MASK)

#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_MASK    (0x40000U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_SHIFT   (18U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_MODE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_SHIFT)) & LCDIF_VDCTRL0_TOG_HALF_LINE_MODE_MASK)

#define LCDIF_VDCTRL0_TOG_HALF_LINE_MASK         (0x80000U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE_SHIFT        (19U)
#define LCDIF_VDCTRL0_TOG_HALF_LINE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HALF_LINE_SHIFT)) & LCDIF_VDCTRL0_TOG_HALF_LINE_MASK)

#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_MASK (0x100000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_SHIFT (20U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PULSE_WIDTH_UNIT_MASK)

#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_MASK (0x200000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_SHIFT (21U)
#define LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_PERIOD_UNIT_MASK)

#define LCDIF_VDCTRL0_TOG_RSRVD1_MASK            (0xC00000U)
#define LCDIF_VDCTRL0_TOG_RSRVD1_SHIFT           (22U)
#define LCDIF_VDCTRL0_TOG_RSRVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_RSRVD1_SHIFT)) & LCDIF_VDCTRL0_TOG_RSRVD1_MASK)

#define LCDIF_VDCTRL0_TOG_ENABLE_POL_MASK        (0x1000000U)
#define LCDIF_VDCTRL0_TOG_ENABLE_POL_SHIFT       (24U)
#define LCDIF_VDCTRL0_TOG_ENABLE_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_ENABLE_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_ENABLE_POL_MASK)

#define LCDIF_VDCTRL0_TOG_DOTCLK_POL_MASK        (0x2000000U)
#define LCDIF_VDCTRL0_TOG_DOTCLK_POL_SHIFT       (25U)
#define LCDIF_VDCTRL0_TOG_DOTCLK_POL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_DOTCLK_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_DOTCLK_POL_MASK)

#define LCDIF_VDCTRL0_TOG_HSYNC_POL_MASK         (0x4000000U)
#define LCDIF_VDCTRL0_TOG_HSYNC_POL_SHIFT        (26U)
#define LCDIF_VDCTRL0_TOG_HSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_HSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_HSYNC_POL_MASK)

#define LCDIF_VDCTRL0_TOG_VSYNC_POL_MASK         (0x8000000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_POL_SHIFT        (27U)
#define LCDIF_VDCTRL0_TOG_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_POL_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_POL_MASK)

#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_MASK    (0x10000000U)
#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_SHIFT   (28U)
#define LCDIF_VDCTRL0_TOG_ENABLE_PRESENT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_SHIFT)) & LCDIF_VDCTRL0_TOG_ENABLE_PRESENT_MASK)

#define LCDIF_VDCTRL0_TOG_VSYNC_OEB_MASK         (0x20000000U)
#define LCDIF_VDCTRL0_TOG_VSYNC_OEB_SHIFT        (29U)
/*! VSYNC_OEB
 *  0b0..The VSYNC pin is in the output mode and the VSYNC signal has to be generated by the LCDIF block.
 *  0b1..The VSYNC pin is in the input mode and the LCD controller sends the VSYNC signal to the block.
 */
#define LCDIF_VDCTRL0_TOG_VSYNC_OEB(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_VSYNC_OEB_SHIFT)) & LCDIF_VDCTRL0_TOG_VSYNC_OEB_MASK)

#define LCDIF_VDCTRL0_TOG_RSRVD2_MASK            (0xC0000000U)
#define LCDIF_VDCTRL0_TOG_RSRVD2_SHIFT           (30U)
#define LCDIF_VDCTRL0_TOG_RSRVD2(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL0_TOG_RSRVD2_SHIFT)) & LCDIF_VDCTRL0_TOG_RSRVD2_MASK)
/*! @} */

/*! @name VDCTRL1 - LCDIF VSYNC Mode and Dotclk Mode Control Register1 */
/*! @{ */

#define LCDIF_VDCTRL1_VSYNC_PERIOD_MASK          (0xFFFFFFFFU)
#define LCDIF_VDCTRL1_VSYNC_PERIOD_SHIFT         (0U)
#define LCDIF_VDCTRL1_VSYNC_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL1_VSYNC_PERIOD_SHIFT)) & LCDIF_VDCTRL1_VSYNC_PERIOD_MASK)
/*! @} */

/*! @name VDCTRL2 - LCDIF VSYNC Mode and Dotclk Mode Control Register2 */
/*! @{ */

#define LCDIF_VDCTRL2_HSYNC_PERIOD_MASK          (0x3FFFFU)
#define LCDIF_VDCTRL2_HSYNC_PERIOD_SHIFT         (0U)
#define LCDIF_VDCTRL2_HSYNC_PERIOD(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL2_HSYNC_PERIOD_SHIFT)) & LCDIF_VDCTRL2_HSYNC_PERIOD_MASK)

#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_MASK     (0xFFFC0000U)
#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_SHIFT    (18U)
#define LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_SHIFT)) & LCDIF_VDCTRL2_HSYNC_PULSE_WIDTH_MASK)
/*! @} */

/*! @name VDCTRL3 - LCDIF VSYNC Mode and Dotclk Mode Control Register3 */
/*! @{ */

#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_MASK     (0xFFFFU)
#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_SHIFT    (0U)
#define LCDIF_VDCTRL3_VERTICAL_WAIT_CNT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_SHIFT)) & LCDIF_VDCTRL3_VERTICAL_WAIT_CNT_MASK)

#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_MASK   (0xFFF0000U)
#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_SHIFT  (16U)
#define LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_SHIFT)) & LCDIF_VDCTRL3_HORIZONTAL_WAIT_CNT_MASK)

#define LCDIF_VDCTRL3_VSYNC_ONLY_MASK            (0x10000000U)
#define LCDIF_VDCTRL3_VSYNC_ONLY_SHIFT           (28U)
#define LCDIF_VDCTRL3_VSYNC_ONLY(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_VSYNC_ONLY_SHIFT)) & LCDIF_VDCTRL3_VSYNC_ONLY_MASK)

#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_MASK      (0x20000000U)
#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_SHIFT     (29U)
#define LCDIF_VDCTRL3_MUX_SYNC_SIGNALS(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_SHIFT)) & LCDIF_VDCTRL3_MUX_SYNC_SIGNALS_MASK)

#define LCDIF_VDCTRL3_RSRVD0_MASK                (0xC0000000U)
#define LCDIF_VDCTRL3_RSRVD0_SHIFT               (30U)
#define LCDIF_VDCTRL3_RSRVD0(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL3_RSRVD0_SHIFT)) & LCDIF_VDCTRL3_RSRVD0_MASK)
/*! @} */

/*! @name VDCTRL4 - LCDIF VSYNC Mode and Dotclk Mode Control Register4 */
/*! @{ */

#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_MASK (0x3FFFFU)
#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_SHIFT (0U)
#define LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_SHIFT)) & LCDIF_VDCTRL4_DOTCLK_H_VALID_DATA_CNT_MASK)

#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON_MASK       (0x40000U)
#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON_SHIFT      (18U)
#define LCDIF_VDCTRL4_SYNC_SIGNALS_ON(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_SYNC_SIGNALS_ON_SHIFT)) & LCDIF_VDCTRL4_SYNC_SIGNALS_ON_MASK)

#define LCDIF_VDCTRL4_RSRVD0_MASK                (0x1FF80000U)
#define LCDIF_VDCTRL4_RSRVD0_SHIFT               (19U)
#define LCDIF_VDCTRL4_RSRVD0(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_RSRVD0_SHIFT)) & LCDIF_VDCTRL4_RSRVD0_MASK)

#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL_MASK        (0xE0000000U)
#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL_SHIFT       (29U)
#define LCDIF_VDCTRL4_DOTCLK_DLY_SEL(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_VDCTRL4_DOTCLK_DLY_SEL_SHIFT)) & LCDIF_VDCTRL4_DOTCLK_DLY_SEL_MASK)
/*! @} */

/*! @name DVICTRL0 - Digital Video Interface Control0 Register */
/*! @{ */

#define LCDIF_DVICTRL0_H_BLANKING_CNT_MASK       (0xFFFU)
#define LCDIF_DVICTRL0_H_BLANKING_CNT_SHIFT      (0U)
#define LCDIF_DVICTRL0_H_BLANKING_CNT(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_H_BLANKING_CNT_SHIFT)) & LCDIF_DVICTRL0_H_BLANKING_CNT_MASK)

#define LCDIF_DVICTRL0_RSRVD0_MASK               (0xF000U)
#define LCDIF_DVICTRL0_RSRVD0_SHIFT              (12U)
#define LCDIF_DVICTRL0_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_RSRVD0_SHIFT)) & LCDIF_DVICTRL0_RSRVD0_MASK)

#define LCDIF_DVICTRL0_H_ACTIVE_CNT_MASK         (0xFFF0000U)
#define LCDIF_DVICTRL0_H_ACTIVE_CNT_SHIFT        (16U)
#define LCDIF_DVICTRL0_H_ACTIVE_CNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_H_ACTIVE_CNT_SHIFT)) & LCDIF_DVICTRL0_H_ACTIVE_CNT_MASK)

#define LCDIF_DVICTRL0_RSRVD1_MASK               (0xF0000000U)
#define LCDIF_DVICTRL0_RSRVD1_SHIFT              (28U)
#define LCDIF_DVICTRL0_RSRVD1(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL0_RSRVD1_SHIFT)) & LCDIF_DVICTRL0_RSRVD1_MASK)
/*! @} */

/*! @name DVICTRL1 - Digital Video Interface Control1 Register */
/*! @{ */

#define LCDIF_DVICTRL1_F2_START_LINE_MASK        (0x3FFU)
#define LCDIF_DVICTRL1_F2_START_LINE_SHIFT       (0U)
#define LCDIF_DVICTRL1_F2_START_LINE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F2_START_LINE_SHIFT)) & LCDIF_DVICTRL1_F2_START_LINE_MASK)

#define LCDIF_DVICTRL1_F1_END_LINE_MASK          (0xFFC00U)
#define LCDIF_DVICTRL1_F1_END_LINE_SHIFT         (10U)
#define LCDIF_DVICTRL1_F1_END_LINE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F1_END_LINE_SHIFT)) & LCDIF_DVICTRL1_F1_END_LINE_MASK)

#define LCDIF_DVICTRL1_F1_START_LINE_MASK        (0x3FF00000U)
#define LCDIF_DVICTRL1_F1_START_LINE_SHIFT       (20U)
#define LCDIF_DVICTRL1_F1_START_LINE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_F1_START_LINE_SHIFT)) & LCDIF_DVICTRL1_F1_START_LINE_MASK)

#define LCDIF_DVICTRL1_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL1_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL1_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL1_RSRVD0_SHIFT)) & LCDIF_DVICTRL1_RSRVD0_MASK)
/*! @} */

/*! @name DVICTRL2 - Digital Video Interface Control2 Register */
/*! @{ */

#define LCDIF_DVICTRL2_V1_BLANK_END_LINE_MASK    (0x3FFU)
#define LCDIF_DVICTRL2_V1_BLANK_END_LINE_SHIFT   (0U)
#define LCDIF_DVICTRL2_V1_BLANK_END_LINE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_V1_BLANK_END_LINE_SHIFT)) & LCDIF_DVICTRL2_V1_BLANK_END_LINE_MASK)

#define LCDIF_DVICTRL2_V1_BLANK_START_LINE_MASK  (0xFFC00U)
#define LCDIF_DVICTRL2_V1_BLANK_START_LINE_SHIFT (10U)
#define LCDIF_DVICTRL2_V1_BLANK_START_LINE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_V1_BLANK_START_LINE_SHIFT)) & LCDIF_DVICTRL2_V1_BLANK_START_LINE_MASK)

#define LCDIF_DVICTRL2_F2_END_LINE_MASK          (0x3FF00000U)
#define LCDIF_DVICTRL2_F2_END_LINE_SHIFT         (20U)
#define LCDIF_DVICTRL2_F2_END_LINE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_F2_END_LINE_SHIFT)) & LCDIF_DVICTRL2_F2_END_LINE_MASK)

#define LCDIF_DVICTRL2_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL2_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL2_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL2_RSRVD0_SHIFT)) & LCDIF_DVICTRL2_RSRVD0_MASK)
/*! @} */

/*! @name DVICTRL3 - Digital Video Interface Control3 Register */
/*! @{ */

#define LCDIF_DVICTRL3_V_LINES_CNT_MASK          (0x3FFU)
#define LCDIF_DVICTRL3_V_LINES_CNT_SHIFT         (0U)
#define LCDIF_DVICTRL3_V_LINES_CNT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V_LINES_CNT_SHIFT)) & LCDIF_DVICTRL3_V_LINES_CNT_MASK)

#define LCDIF_DVICTRL3_V2_BLANK_END_LINE_MASK    (0xFFC00U)
#define LCDIF_DVICTRL3_V2_BLANK_END_LINE_SHIFT   (10U)
#define LCDIF_DVICTRL3_V2_BLANK_END_LINE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V2_BLANK_END_LINE_SHIFT)) & LCDIF_DVICTRL3_V2_BLANK_END_LINE_MASK)

#define LCDIF_DVICTRL3_V2_BLANK_START_LINE_MASK  (0x3FF00000U)
#define LCDIF_DVICTRL3_V2_BLANK_START_LINE_SHIFT (20U)
#define LCDIF_DVICTRL3_V2_BLANK_START_LINE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_V2_BLANK_START_LINE_SHIFT)) & LCDIF_DVICTRL3_V2_BLANK_START_LINE_MASK)

#define LCDIF_DVICTRL3_RSRVD0_MASK               (0xC0000000U)
#define LCDIF_DVICTRL3_RSRVD0_SHIFT              (30U)
#define LCDIF_DVICTRL3_RSRVD0(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL3_RSRVD0_SHIFT)) & LCDIF_DVICTRL3_RSRVD0_MASK)
/*! @} */

/*! @name DVICTRL4 - Digital Video Interface Control4 Register */
/*! @{ */

#define LCDIF_DVICTRL4_H_FILL_CNT_MASK           (0xFFU)
#define LCDIF_DVICTRL4_H_FILL_CNT_SHIFT          (0U)
#define LCDIF_DVICTRL4_H_FILL_CNT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_H_FILL_CNT_SHIFT)) & LCDIF_DVICTRL4_H_FILL_CNT_MASK)

#define LCDIF_DVICTRL4_CR_FILL_VALUE_MASK        (0xFF00U)
#define LCDIF_DVICTRL4_CR_FILL_VALUE_SHIFT       (8U)
#define LCDIF_DVICTRL4_CR_FILL_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_CR_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_CR_FILL_VALUE_MASK)

#define LCDIF_DVICTRL4_CB_FILL_VALUE_MASK        (0xFF0000U)
#define LCDIF_DVICTRL4_CB_FILL_VALUE_SHIFT       (16U)
#define LCDIF_DVICTRL4_CB_FILL_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_CB_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_CB_FILL_VALUE_MASK)

#define LCDIF_DVICTRL4_Y_FILL_VALUE_MASK         (0xFF000000U)
#define LCDIF_DVICTRL4_Y_FILL_VALUE_SHIFT        (24U)
#define LCDIF_DVICTRL4_Y_FILL_VALUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_DVICTRL4_Y_FILL_VALUE_SHIFT)) & LCDIF_DVICTRL4_Y_FILL_VALUE_MASK)
/*! @} */

/*! @name CSC_COEFF0 - RGB to YCbCr 4:2:2 CSC Coefficient0 Register */
/*! @{ */

#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_MASK (0x3U)
#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_SHIFT (0U)
/*! CSC_SUBSAMPLE_FILTER
 *  0b00..No filtering, simply keep every chroma value for samples numbered 2n and discard chroma values associated with all samples numbered 2n+1.
 *  0b01..Reserved
 *  0b10..Chroma samples numbered 2n and 2n+1 are averaged (weights 1/2, 1/2) and that chroma value replaces the
 *        two chroma values at 2n and 2n+1. This chroma now exists horizontally halfway between the two luma samples.
 *  0b11..Chroma samples numbered 2n-1, 2n, and 2n+1 are averaged (weights 1/4, 1/2, 1/4) and that chroma value
 *        exists at the same site as the luma sample numbered 2n and the chroma samples at 2n+1 are discarded.
 */
#define LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_SHIFT)) & LCDIF_CSC_COEFF0_CSC_SUBSAMPLE_FILTER_MASK)

#define LCDIF_CSC_COEFF0_RSRVD0_MASK             (0xFFFCU)
#define LCDIF_CSC_COEFF0_RSRVD0_SHIFT            (2U)
#define LCDIF_CSC_COEFF0_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF0_RSRVD0_MASK)

#define LCDIF_CSC_COEFF0_C0_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF0_C0_SHIFT                (16U)
#define LCDIF_CSC_COEFF0_C0(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_C0_SHIFT)) & LCDIF_CSC_COEFF0_C0_MASK)

#define LCDIF_CSC_COEFF0_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF0_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF0_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF0_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF0_RSRVD1_MASK)
/*! @} */

/*! @name CSC_COEFF1 - RGB to YCbCr 4:2:2 CSC Coefficient1 Register */
/*! @{ */

#define LCDIF_CSC_COEFF1_C1_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF1_C1_SHIFT                (0U)
#define LCDIF_CSC_COEFF1_C1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_C1_SHIFT)) & LCDIF_CSC_COEFF1_C1_MASK)

#define LCDIF_CSC_COEFF1_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF1_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF1_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF1_RSRVD0_MASK)

#define LCDIF_CSC_COEFF1_C2_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF1_C2_SHIFT                (16U)
#define LCDIF_CSC_COEFF1_C2(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_C2_SHIFT)) & LCDIF_CSC_COEFF1_C2_MASK)

#define LCDIF_CSC_COEFF1_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF1_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF1_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF1_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF1_RSRVD1_MASK)
/*! @} */

/*! @name CSC_COEFF2 - RGB to YCbCr 4:2:2 CSC Coefficent2 Register */
/*! @{ */

#define LCDIF_CSC_COEFF2_C3_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF2_C3_SHIFT                (0U)
#define LCDIF_CSC_COEFF2_C3(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_C3_SHIFT)) & LCDIF_CSC_COEFF2_C3_MASK)

#define LCDIF_CSC_COEFF2_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF2_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF2_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF2_RSRVD0_MASK)

#define LCDIF_CSC_COEFF2_C4_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF2_C4_SHIFT                (16U)
#define LCDIF_CSC_COEFF2_C4(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_C4_SHIFT)) & LCDIF_CSC_COEFF2_C4_MASK)

#define LCDIF_CSC_COEFF2_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF2_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF2_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF2_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF2_RSRVD1_MASK)
/*! @} */

/*! @name CSC_COEFF3 - RGB to YCbCr 4:2:2 CSC Coefficient3 Register */
/*! @{ */

#define LCDIF_CSC_COEFF3_C5_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF3_C5_SHIFT                (0U)
#define LCDIF_CSC_COEFF3_C5(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_C5_SHIFT)) & LCDIF_CSC_COEFF3_C5_MASK)

#define LCDIF_CSC_COEFF3_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF3_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF3_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF3_RSRVD0_MASK)

#define LCDIF_CSC_COEFF3_C6_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF3_C6_SHIFT                (16U)
#define LCDIF_CSC_COEFF3_C6(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_C6_SHIFT)) & LCDIF_CSC_COEFF3_C6_MASK)

#define LCDIF_CSC_COEFF3_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF3_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF3_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF3_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF3_RSRVD1_MASK)
/*! @} */

/*! @name CSC_COEFF4 - RGB to YCbCr 4:2:2 CSC Coefficient4 Register */
/*! @{ */

#define LCDIF_CSC_COEFF4_C7_MASK                 (0x3FFU)
#define LCDIF_CSC_COEFF4_C7_SHIFT                (0U)
#define LCDIF_CSC_COEFF4_C7(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_C7_SHIFT)) & LCDIF_CSC_COEFF4_C7_MASK)

#define LCDIF_CSC_COEFF4_RSRVD0_MASK             (0xFC00U)
#define LCDIF_CSC_COEFF4_RSRVD0_SHIFT            (10U)
#define LCDIF_CSC_COEFF4_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_RSRVD0_SHIFT)) & LCDIF_CSC_COEFF4_RSRVD0_MASK)

#define LCDIF_CSC_COEFF4_C8_MASK                 (0x3FF0000U)
#define LCDIF_CSC_COEFF4_C8_SHIFT                (16U)
#define LCDIF_CSC_COEFF4_C8(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_C8_SHIFT)) & LCDIF_CSC_COEFF4_C8_MASK)

#define LCDIF_CSC_COEFF4_RSRVD1_MASK             (0xFC000000U)
#define LCDIF_CSC_COEFF4_RSRVD1_SHIFT            (26U)
#define LCDIF_CSC_COEFF4_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_COEFF4_RSRVD1_SHIFT)) & LCDIF_CSC_COEFF4_RSRVD1_MASK)
/*! @} */

/*! @name CSC_OFFSET - RGB to YCbCr 4:2:2 CSC Offset Register */
/*! @{ */

#define LCDIF_CSC_OFFSET_Y_OFFSET_MASK           (0x1FFU)
#define LCDIF_CSC_OFFSET_Y_OFFSET_SHIFT          (0U)
#define LCDIF_CSC_OFFSET_Y_OFFSET(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_Y_OFFSET_SHIFT)) & LCDIF_CSC_OFFSET_Y_OFFSET_MASK)

#define LCDIF_CSC_OFFSET_RSRVD0_MASK             (0xFE00U)
#define LCDIF_CSC_OFFSET_RSRVD0_SHIFT            (9U)
#define LCDIF_CSC_OFFSET_RSRVD0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_RSRVD0_SHIFT)) & LCDIF_CSC_OFFSET_RSRVD0_MASK)

#define LCDIF_CSC_OFFSET_CBCR_OFFSET_MASK        (0x1FF0000U)
#define LCDIF_CSC_OFFSET_CBCR_OFFSET_SHIFT       (16U)
#define LCDIF_CSC_OFFSET_CBCR_OFFSET(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_CBCR_OFFSET_SHIFT)) & LCDIF_CSC_OFFSET_CBCR_OFFSET_MASK)

#define LCDIF_CSC_OFFSET_RSRVD1_MASK             (0xFE000000U)
#define LCDIF_CSC_OFFSET_RSRVD1_SHIFT            (25U)
#define LCDIF_CSC_OFFSET_RSRVD1(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_OFFSET_RSRVD1_SHIFT)) & LCDIF_CSC_OFFSET_RSRVD1_MASK)
/*! @} */

/*! @name CSC_LIMIT - RGB to YCbCr 4:2:2 CSC Limit Register */
/*! @{ */

#define LCDIF_CSC_LIMIT_Y_MAX_MASK               (0xFFU)
#define LCDIF_CSC_LIMIT_Y_MAX_SHIFT              (0U)
#define LCDIF_CSC_LIMIT_Y_MAX(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_Y_MAX_SHIFT)) & LCDIF_CSC_LIMIT_Y_MAX_MASK)

#define LCDIF_CSC_LIMIT_Y_MIN_MASK               (0xFF00U)
#define LCDIF_CSC_LIMIT_Y_MIN_SHIFT              (8U)
#define LCDIF_CSC_LIMIT_Y_MIN(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_Y_MIN_SHIFT)) & LCDIF_CSC_LIMIT_Y_MIN_MASK)

#define LCDIF_CSC_LIMIT_CBCR_MAX_MASK            (0xFF0000U)
#define LCDIF_CSC_LIMIT_CBCR_MAX_SHIFT           (16U)
#define LCDIF_CSC_LIMIT_CBCR_MAX(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_CBCR_MAX_SHIFT)) & LCDIF_CSC_LIMIT_CBCR_MAX_MASK)

#define LCDIF_CSC_LIMIT_CBCR_MIN_MASK            (0xFF000000U)
#define LCDIF_CSC_LIMIT_CBCR_MIN_SHIFT           (24U)
#define LCDIF_CSC_LIMIT_CBCR_MIN(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CSC_LIMIT_CBCR_MIN_SHIFT)) & LCDIF_CSC_LIMIT_CBCR_MIN_MASK)
/*! @} */

/*! @name DATA - LCD Interface Data Register */
/*! @{ */

#define LCDIF_DATA_DATA_ZERO_MASK                (0xFFU)
#define LCDIF_DATA_DATA_ZERO_SHIFT               (0U)
#define LCDIF_DATA_DATA_ZERO(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_ZERO_SHIFT)) & LCDIF_DATA_DATA_ZERO_MASK)

#define LCDIF_DATA_DATA_ONE_MASK                 (0xFF00U)
#define LCDIF_DATA_DATA_ONE_SHIFT                (8U)
#define LCDIF_DATA_DATA_ONE(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_ONE_SHIFT)) & LCDIF_DATA_DATA_ONE_MASK)

#define LCDIF_DATA_DATA_TWO_MASK                 (0xFF0000U)
#define LCDIF_DATA_DATA_TWO_SHIFT                (16U)
#define LCDIF_DATA_DATA_TWO(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_TWO_SHIFT)) & LCDIF_DATA_DATA_TWO_MASK)

#define LCDIF_DATA_DATA_THREE_MASK               (0xFF000000U)
#define LCDIF_DATA_DATA_THREE_SHIFT              (24U)
#define LCDIF_DATA_DATA_THREE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DATA_DATA_THREE_SHIFT)) & LCDIF_DATA_DATA_THREE_MASK)
/*! @} */

/*! @name BM_ERROR_STAT - Bus Master Error Status Register */
/*! @{ */

#define LCDIF_BM_ERROR_STAT_ADDR_MASK            (0xFFFFFFFFU)
#define LCDIF_BM_ERROR_STAT_ADDR_SHIFT           (0U)
#define LCDIF_BM_ERROR_STAT_ADDR(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_BM_ERROR_STAT_ADDR_SHIFT)) & LCDIF_BM_ERROR_STAT_ADDR_MASK)
/*! @} */

/*! @name CRC_STAT - CRC Status Register */
/*! @{ */

#define LCDIF_CRC_STAT_CRC_VALUE_MASK            (0xFFFFFFFFU)
#define LCDIF_CRC_STAT_CRC_VALUE_SHIFT           (0U)
#define LCDIF_CRC_STAT_CRC_VALUE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CRC_STAT_CRC_VALUE_SHIFT)) & LCDIF_CRC_STAT_CRC_VALUE_MASK)
/*! @} */

/*! @name STAT - LCD Interface Status Register */
/*! @{ */

#define LCDIF_STAT_LFIFO_COUNT_MASK              (0x1FFU)
#define LCDIF_STAT_LFIFO_COUNT_SHIFT             (0U)
#define LCDIF_STAT_LFIFO_COUNT(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_COUNT_SHIFT)) & LCDIF_STAT_LFIFO_COUNT_MASK)

#define LCDIF_STAT_RSRVD0_MASK                   (0xFFFE00U)
#define LCDIF_STAT_RSRVD0_SHIFT                  (9U)
#define LCDIF_STAT_RSRVD0(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_RSRVD0_SHIFT)) & LCDIF_STAT_RSRVD0_MASK)

#define LCDIF_STAT_DVI_CURRENT_FIELD_MASK        (0x1000000U)
#define LCDIF_STAT_DVI_CURRENT_FIELD_SHIFT       (24U)
#define LCDIF_STAT_DVI_CURRENT_FIELD(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_DVI_CURRENT_FIELD_SHIFT)) & LCDIF_STAT_DVI_CURRENT_FIELD_MASK)

#define LCDIF_STAT_BUSY_MASK                     (0x2000000U)
#define LCDIF_STAT_BUSY_SHIFT                    (25U)
#define LCDIF_STAT_BUSY(x)                       (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_BUSY_SHIFT)) & LCDIF_STAT_BUSY_MASK)

#define LCDIF_STAT_TXFIFO_EMPTY_MASK             (0x4000000U)
#define LCDIF_STAT_TXFIFO_EMPTY_SHIFT            (26U)
#define LCDIF_STAT_TXFIFO_EMPTY(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_TXFIFO_EMPTY_SHIFT)) & LCDIF_STAT_TXFIFO_EMPTY_MASK)

#define LCDIF_STAT_TXFIFO_FULL_MASK              (0x8000000U)
#define LCDIF_STAT_TXFIFO_FULL_SHIFT             (27U)
#define LCDIF_STAT_TXFIFO_FULL(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_TXFIFO_FULL_SHIFT)) & LCDIF_STAT_TXFIFO_FULL_MASK)

#define LCDIF_STAT_LFIFO_EMPTY_MASK              (0x10000000U)
#define LCDIF_STAT_LFIFO_EMPTY_SHIFT             (28U)
#define LCDIF_STAT_LFIFO_EMPTY(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_EMPTY_SHIFT)) & LCDIF_STAT_LFIFO_EMPTY_MASK)

#define LCDIF_STAT_LFIFO_FULL_MASK               (0x20000000U)
#define LCDIF_STAT_LFIFO_FULL_SHIFT              (29U)
#define LCDIF_STAT_LFIFO_FULL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_LFIFO_FULL_SHIFT)) & LCDIF_STAT_LFIFO_FULL_MASK)

#define LCDIF_STAT_PRESENT_MASK                  (0x80000000U)
#define LCDIF_STAT_PRESENT_SHIFT                 (31U)
#define LCDIF_STAT_PRESENT(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_PRESENT_SHIFT)) & LCDIF_STAT_PRESENT_MASK)
/*! @} */

/*! @name THRES - LCDIF Threshold Register */
/*! @{ */

#define LCDIF_THRES_PANIC_MASK                   (0x1FFU)
#define LCDIF_THRES_PANIC_SHIFT                  (0U)
#define LCDIF_THRES_PANIC(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_PANIC_SHIFT)) & LCDIF_THRES_PANIC_MASK)

#define LCDIF_THRES_RSRVD1_MASK                  (0xFE00U)
#define LCDIF_THRES_RSRVD1_SHIFT                 (9U)
#define LCDIF_THRES_RSRVD1(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_RSRVD1_SHIFT)) & LCDIF_THRES_RSRVD1_MASK)

#define LCDIF_THRES_FASTCLOCK_MASK               (0x1FF0000U)
#define LCDIF_THRES_FASTCLOCK_SHIFT              (16U)
#define LCDIF_THRES_FASTCLOCK(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_FASTCLOCK_SHIFT)) & LCDIF_THRES_FASTCLOCK_MASK)

#define LCDIF_THRES_RSRVD2_MASK                  (0xFE000000U)
#define LCDIF_THRES_RSRVD2_SHIFT                 (25U)
#define LCDIF_THRES_RSRVD2(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_THRES_RSRVD2_SHIFT)) & LCDIF_THRES_RSRVD2_MASK)
/*! @} */

/*! @name AS_CTRL - LCDIF AS Buffer Control Register */
/*! @{ */

#define LCDIF_AS_CTRL_AS_ENABLE_MASK             (0x1U)
#define LCDIF_AS_CTRL_AS_ENABLE_SHIFT            (0U)
#define LCDIF_AS_CTRL_AS_ENABLE(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_AS_ENABLE_SHIFT)) & LCDIF_AS_CTRL_AS_ENABLE_MASK)

#define LCDIF_AS_CTRL_ALPHA_CTRL_MASK            (0x6U)
#define LCDIF_AS_CTRL_ALPHA_CTRL_SHIFT           (1U)
#define LCDIF_AS_CTRL_ALPHA_CTRL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_CTRL_SHIFT)) & LCDIF_AS_CTRL_ALPHA_CTRL_MASK)

#define LCDIF_AS_CTRL_ENABLE_COLORKEY_MASK       (0x8U)
#define LCDIF_AS_CTRL_ENABLE_COLORKEY_SHIFT      (3U)
#define LCDIF_AS_CTRL_ENABLE_COLORKEY(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ENABLE_COLORKEY_SHIFT)) & LCDIF_AS_CTRL_ENABLE_COLORKEY_MASK)

#define LCDIF_AS_CTRL_FORMAT_MASK                (0xF0U)
#define LCDIF_AS_CTRL_FORMAT_SHIFT               (4U)
#define LCDIF_AS_CTRL_FORMAT(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_FORMAT_SHIFT)) & LCDIF_AS_CTRL_FORMAT_MASK)

#define LCDIF_AS_CTRL_ALPHA_MASK                 (0xFF00U)
#define LCDIF_AS_CTRL_ALPHA_SHIFT                (8U)
#define LCDIF_AS_CTRL_ALPHA(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_SHIFT)) & LCDIF_AS_CTRL_ALPHA_MASK)

#define LCDIF_AS_CTRL_ROP_MASK                   (0xF0000U)
#define LCDIF_AS_CTRL_ROP_SHIFT                  (16U)
#define LCDIF_AS_CTRL_ROP(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ROP_SHIFT)) & LCDIF_AS_CTRL_ROP_MASK)

#define LCDIF_AS_CTRL_ALPHA_INVERT_MASK          (0x100000U)
#define LCDIF_AS_CTRL_ALPHA_INVERT_SHIFT         (20U)
#define LCDIF_AS_CTRL_ALPHA_INVERT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_ALPHA_INVERT_SHIFT)) & LCDIF_AS_CTRL_ALPHA_INVERT_MASK)

#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_MASK    (0x600000U)
#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_SHIFT   (21U)
#define LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_SHIFT)) & LCDIF_AS_CTRL_INPUT_DATA_SWIZZLE_MASK)

#define LCDIF_AS_CTRL_PS_DISABLE_MASK            (0x800000U)
#define LCDIF_AS_CTRL_PS_DISABLE_SHIFT           (23U)
#define LCDIF_AS_CTRL_PS_DISABLE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_PS_DISABLE_SHIFT)) & LCDIF_AS_CTRL_PS_DISABLE_MASK)

#define LCDIF_AS_CTRL_RVDS1_MASK                 (0x7000000U)
#define LCDIF_AS_CTRL_RVDS1_SHIFT                (24U)
#define LCDIF_AS_CTRL_RVDS1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_RVDS1_SHIFT)) & LCDIF_AS_CTRL_RVDS1_MASK)

#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_MASK       (0x8000000U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_SHIFT      (27U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_SHIFT)) & LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_MASK)

#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_MASK    (0x10000000U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_SHIFT   (28U)
#define LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_SHIFT)) & LCDIF_AS_CTRL_CSI_SYNC_ON_IRQ_EN_MASK)

#define LCDIF_AS_CTRL_CSI_VSYNC_MODE_MASK        (0x20000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_MODE_SHIFT       (29U)
#define LCDIF_AS_CTRL_CSI_VSYNC_MODE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_MODE_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_MODE_MASK)

#define LCDIF_AS_CTRL_CSI_VSYNC_POL_MASK         (0x40000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_POL_SHIFT        (30U)
#define LCDIF_AS_CTRL_CSI_VSYNC_POL(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_POL_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_POL_MASK)

#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_MASK      (0x80000000U)
#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_SHIFT     (31U)
#define LCDIF_AS_CTRL_CSI_VSYNC_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_SHIFT)) & LCDIF_AS_CTRL_CSI_VSYNC_ENABLE_MASK)
/*! @} */

/*! @name AS_BUF - Alpha Surface Buffer Pointer */
/*! @{ */

#define LCDIF_AS_BUF_ADDR_MASK                   (0xFFFFFFFFU)
#define LCDIF_AS_BUF_ADDR_SHIFT                  (0U)
#define LCDIF_AS_BUF_ADDR(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_BUF_ADDR_SHIFT)) & LCDIF_AS_BUF_ADDR_MASK)
/*! @} */

/*! @name AS_NEXT_BUF -  */
/*! @{ */

#define LCDIF_AS_NEXT_BUF_ADDR_MASK              (0xFFFFFFFFU)
#define LCDIF_AS_NEXT_BUF_ADDR_SHIFT             (0U)
#define LCDIF_AS_NEXT_BUF_ADDR(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_NEXT_BUF_ADDR_SHIFT)) & LCDIF_AS_NEXT_BUF_ADDR_MASK)
/*! @} */

/*! @name AS_CLRKEYLOW - LCDIF Overlay Color Key Low */
/*! @{ */

#define LCDIF_AS_CLRKEYLOW_PIXEL_MASK            (0xFFFFFFU)
#define LCDIF_AS_CLRKEYLOW_PIXEL_SHIFT           (0U)
#define LCDIF_AS_CLRKEYLOW_PIXEL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYLOW_PIXEL_SHIFT)) & LCDIF_AS_CLRKEYLOW_PIXEL_MASK)

#define LCDIF_AS_CLRKEYLOW_RSVD1_MASK            (0xFF000000U)
#define LCDIF_AS_CLRKEYLOW_RSVD1_SHIFT           (24U)
#define LCDIF_AS_CLRKEYLOW_RSVD1(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYLOW_RSVD1_SHIFT)) & LCDIF_AS_CLRKEYLOW_RSVD1_MASK)
/*! @} */

/*! @name AS_CLRKEYHIGH - LCDIF Overlay Color Key High */
/*! @{ */

#define LCDIF_AS_CLRKEYHIGH_PIXEL_MASK           (0xFFFFFFU)
#define LCDIF_AS_CLRKEYHIGH_PIXEL_SHIFT          (0U)
#define LCDIF_AS_CLRKEYHIGH_PIXEL(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYHIGH_PIXEL_SHIFT)) & LCDIF_AS_CLRKEYHIGH_PIXEL_MASK)

#define LCDIF_AS_CLRKEYHIGH_RSVD1_MASK           (0xFF000000U)
#define LCDIF_AS_CLRKEYHIGH_RSVD1_SHIFT          (24U)
#define LCDIF_AS_CLRKEYHIGH_RSVD1(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CLRKEYHIGH_RSVD1_SHIFT)) & LCDIF_AS_CLRKEYHIGH_RSVD1_MASK)
/*! @} */

/*! @name SYNC_DELAY - LCD working insync mode with CSI for VSYNC delay */
/*! @{ */

#define LCDIF_SYNC_DELAY_H_COUNT_DELAY_MASK      (0xFFFFU)
#define LCDIF_SYNC_DELAY_H_COUNT_DELAY_SHIFT     (0U)
#define LCDIF_SYNC_DELAY_H_COUNT_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_SYNC_DELAY_H_COUNT_DELAY_SHIFT)) & LCDIF_SYNC_DELAY_H_COUNT_DELAY_MASK)

#define LCDIF_SYNC_DELAY_V_COUNT_DELAY_MASK      (0xFFFF0000U)
#define LCDIF_SYNC_DELAY_V_COUNT_DELAY_SHIFT     (16U)
#define LCDIF_SYNC_DELAY_V_COUNT_DELAY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_SYNC_DELAY_V_COUNT_DELAY_SHIFT)) & LCDIF_SYNC_DELAY_V_COUNT_DELAY_MASK)
/*! @} */

/*! @name PIGEONCTRL0 - LCDIF Pigeon Mode Control0 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL0_FD_PERIOD_MASK         (0xFFFU)
#define LCDIF_PIGEONCTRL0_FD_PERIOD_SHIFT        (0U)
#define LCDIF_PIGEONCTRL0_FD_PERIOD(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_FD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_FD_PERIOD_MASK)

#define LCDIF_PIGEONCTRL0_LD_PERIOD_MASK         (0xFFF0000U)
#define LCDIF_PIGEONCTRL0_LD_PERIOD_SHIFT        (16U)
#define LCDIF_PIGEONCTRL0_LD_PERIOD(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_LD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_LD_PERIOD_MASK)
/*! @} */

/*! @name PIGEONCTRL0_SET - LCDIF Pigeon Mode Control0 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL0_SET_FD_PERIOD_MASK     (0xFFFU)
#define LCDIF_PIGEONCTRL0_SET_FD_PERIOD_SHIFT    (0U)
#define LCDIF_PIGEONCTRL0_SET_FD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_SET_FD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_SET_FD_PERIOD_MASK)

#define LCDIF_PIGEONCTRL0_SET_LD_PERIOD_MASK     (0xFFF0000U)
#define LCDIF_PIGEONCTRL0_SET_LD_PERIOD_SHIFT    (16U)
#define LCDIF_PIGEONCTRL0_SET_LD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_SET_LD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_SET_LD_PERIOD_MASK)
/*! @} */

/*! @name PIGEONCTRL0_CLR - LCDIF Pigeon Mode Control0 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL0_CLR_FD_PERIOD_MASK     (0xFFFU)
#define LCDIF_PIGEONCTRL0_CLR_FD_PERIOD_SHIFT    (0U)
#define LCDIF_PIGEONCTRL0_CLR_FD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_CLR_FD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_CLR_FD_PERIOD_MASK)

#define LCDIF_PIGEONCTRL0_CLR_LD_PERIOD_MASK     (0xFFF0000U)
#define LCDIF_PIGEONCTRL0_CLR_LD_PERIOD_SHIFT    (16U)
#define LCDIF_PIGEONCTRL0_CLR_LD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_CLR_LD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_CLR_LD_PERIOD_MASK)
/*! @} */

/*! @name PIGEONCTRL0_TOG - LCDIF Pigeon Mode Control0 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL0_TOG_FD_PERIOD_MASK     (0xFFFU)
#define LCDIF_PIGEONCTRL0_TOG_FD_PERIOD_SHIFT    (0U)
#define LCDIF_PIGEONCTRL0_TOG_FD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_TOG_FD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_TOG_FD_PERIOD_MASK)

#define LCDIF_PIGEONCTRL0_TOG_LD_PERIOD_MASK     (0xFFF0000U)
#define LCDIF_PIGEONCTRL0_TOG_LD_PERIOD_SHIFT    (16U)
#define LCDIF_PIGEONCTRL0_TOG_LD_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL0_TOG_LD_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL0_TOG_LD_PERIOD_MASK)
/*! @} */

/*! @name PIGEONCTRL1 - LCDIF Pigeon Mode Control1 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL1_FRAME_CNT_PERIOD_MASK  (0xFFFU)
#define LCDIF_PIGEONCTRL1_FRAME_CNT_PERIOD_SHIFT (0U)
#define LCDIF_PIGEONCTRL1_FRAME_CNT_PERIOD(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_FRAME_CNT_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL1_FRAME_CNT_PERIOD_MASK)

#define LCDIF_PIGEONCTRL1_FRAME_CNT_CYCLES_MASK  (0xFFF0000U)
#define LCDIF_PIGEONCTRL1_FRAME_CNT_CYCLES_SHIFT (16U)
#define LCDIF_PIGEONCTRL1_FRAME_CNT_CYCLES(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_FRAME_CNT_CYCLES_SHIFT)) & LCDIF_PIGEONCTRL1_FRAME_CNT_CYCLES_MASK)
/*! @} */

/*! @name PIGEONCTRL1_SET - LCDIF Pigeon Mode Control1 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_PERIOD_MASK (0xFFFU)
#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_PERIOD_SHIFT (0U)
#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_SET_FRAME_CNT_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL1_SET_FRAME_CNT_PERIOD_MASK)

#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_CYCLES_MASK (0xFFF0000U)
#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_CYCLES_SHIFT (16U)
#define LCDIF_PIGEONCTRL1_SET_FRAME_CNT_CYCLES(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_SET_FRAME_CNT_CYCLES_SHIFT)) & LCDIF_PIGEONCTRL1_SET_FRAME_CNT_CYCLES_MASK)
/*! @} */

/*! @name PIGEONCTRL1_CLR - LCDIF Pigeon Mode Control1 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_PERIOD_MASK (0xFFFU)
#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_PERIOD_SHIFT (0U)
#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_PERIOD_MASK)

#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_CYCLES_MASK (0xFFF0000U)
#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_CYCLES_SHIFT (16U)
#define LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_CYCLES(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_CYCLES_SHIFT)) & LCDIF_PIGEONCTRL1_CLR_FRAME_CNT_CYCLES_MASK)
/*! @} */

/*! @name PIGEONCTRL1_TOG - LCDIF Pigeon Mode Control1 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_PERIOD_MASK (0xFFFU)
#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_PERIOD_SHIFT (0U)
#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_PERIOD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_PERIOD_SHIFT)) & LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_PERIOD_MASK)

#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_CYCLES_MASK (0xFFF0000U)
#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_CYCLES_SHIFT (16U)
#define LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_CYCLES(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_CYCLES_SHIFT)) & LCDIF_PIGEONCTRL1_TOG_FRAME_CNT_CYCLES_MASK)
/*! @} */

/*! @name PIGEONCTRL2 - LCDIF Pigeon Mode Control2 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL2_PIGEON_DATA_EN_MASK    (0x1U)
#define LCDIF_PIGEONCTRL2_PIGEON_DATA_EN_SHIFT   (0U)
#define LCDIF_PIGEONCTRL2_PIGEON_DATA_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_PIGEON_DATA_EN_SHIFT)) & LCDIF_PIGEONCTRL2_PIGEON_DATA_EN_MASK)

#define LCDIF_PIGEONCTRL2_PIGEON_CLK_GATE_MASK   (0x2U)
#define LCDIF_PIGEONCTRL2_PIGEON_CLK_GATE_SHIFT  (1U)
#define LCDIF_PIGEONCTRL2_PIGEON_CLK_GATE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_PIGEON_CLK_GATE_SHIFT)) & LCDIF_PIGEONCTRL2_PIGEON_CLK_GATE_MASK)
/*! @} */

/*! @name PIGEONCTRL2_SET - LCDIF Pigeon Mode Control2 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL2_SET_PIGEON_DATA_EN_MASK (0x1U)
#define LCDIF_PIGEONCTRL2_SET_PIGEON_DATA_EN_SHIFT (0U)
#define LCDIF_PIGEONCTRL2_SET_PIGEON_DATA_EN(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_SET_PIGEON_DATA_EN_SHIFT)) & LCDIF_PIGEONCTRL2_SET_PIGEON_DATA_EN_MASK)

#define LCDIF_PIGEONCTRL2_SET_PIGEON_CLK_GATE_MASK (0x2U)
#define LCDIF_PIGEONCTRL2_SET_PIGEON_CLK_GATE_SHIFT (1U)
#define LCDIF_PIGEONCTRL2_SET_PIGEON_CLK_GATE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_SET_PIGEON_CLK_GATE_SHIFT)) & LCDIF_PIGEONCTRL2_SET_PIGEON_CLK_GATE_MASK)
/*! @} */

/*! @name PIGEONCTRL2_CLR - LCDIF Pigeon Mode Control2 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL2_CLR_PIGEON_DATA_EN_MASK (0x1U)
#define LCDIF_PIGEONCTRL2_CLR_PIGEON_DATA_EN_SHIFT (0U)
#define LCDIF_PIGEONCTRL2_CLR_PIGEON_DATA_EN(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_CLR_PIGEON_DATA_EN_SHIFT)) & LCDIF_PIGEONCTRL2_CLR_PIGEON_DATA_EN_MASK)

#define LCDIF_PIGEONCTRL2_CLR_PIGEON_CLK_GATE_MASK (0x2U)
#define LCDIF_PIGEONCTRL2_CLR_PIGEON_CLK_GATE_SHIFT (1U)
#define LCDIF_PIGEONCTRL2_CLR_PIGEON_CLK_GATE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_CLR_PIGEON_CLK_GATE_SHIFT)) & LCDIF_PIGEONCTRL2_CLR_PIGEON_CLK_GATE_MASK)
/*! @} */

/*! @name PIGEONCTRL2_TOG - LCDIF Pigeon Mode Control2 Register */
/*! @{ */

#define LCDIF_PIGEONCTRL2_TOG_PIGEON_DATA_EN_MASK (0x1U)
#define LCDIF_PIGEONCTRL2_TOG_PIGEON_DATA_EN_SHIFT (0U)
#define LCDIF_PIGEONCTRL2_TOG_PIGEON_DATA_EN(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_TOG_PIGEON_DATA_EN_SHIFT)) & LCDIF_PIGEONCTRL2_TOG_PIGEON_DATA_EN_MASK)

#define LCDIF_PIGEONCTRL2_TOG_PIGEON_CLK_GATE_MASK (0x2U)
#define LCDIF_PIGEONCTRL2_TOG_PIGEON_CLK_GATE_SHIFT (1U)
#define LCDIF_PIGEONCTRL2_TOG_PIGEON_CLK_GATE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEONCTRL2_TOG_PIGEON_CLK_GATE_SHIFT)) & LCDIF_PIGEONCTRL2_TOG_PIGEON_CLK_GATE_MASK)
/*! @} */

/*! @name PIGEON_n_0 - Panel Interface Signal Generator Register */
/*! @{ */

#define LCDIF_PIGEON_n_0_EN_MASK                 (0x1U)
#define LCDIF_PIGEON_n_0_EN_SHIFT                (0U)
#define LCDIF_PIGEON_n_0_EN(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_EN_SHIFT)) & LCDIF_PIGEON_n_0_EN_MASK)

#define LCDIF_PIGEON_n_0_POL_MASK                (0x2U)
#define LCDIF_PIGEON_n_0_POL_SHIFT               (1U)
/*! POL
 *  0b0..Normal Signal (Active high)
 *  0b1..Inverted signal (Active low)
 */
#define LCDIF_PIGEON_n_0_POL(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_POL_SHIFT)) & LCDIF_PIGEON_n_0_POL_MASK)

#define LCDIF_PIGEON_n_0_INC_SEL_MASK            (0xCU)
#define LCDIF_PIGEON_n_0_INC_SEL_SHIFT           (2U)
/*! INC_SEL
 *  0b00..pclk
 *  0b01..Line start pulse
 *  0b10..Frame start pulse
 *  0b11..Use another signal as tick event
 */
#define LCDIF_PIGEON_n_0_INC_SEL(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_INC_SEL_SHIFT)) & LCDIF_PIGEON_n_0_INC_SEL_MASK)

#define LCDIF_PIGEON_n_0_OFFSET_MASK             (0xF0U)
#define LCDIF_PIGEON_n_0_OFFSET_SHIFT            (4U)
#define LCDIF_PIGEON_n_0_OFFSET(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_OFFSET_SHIFT)) & LCDIF_PIGEON_n_0_OFFSET_MASK)

#define LCDIF_PIGEON_n_0_MASK_CNT_SEL_MASK       (0xF00U)
#define LCDIF_PIGEON_n_0_MASK_CNT_SEL_SHIFT      (8U)
/*! MASK_CNT_SEL
 *  0b0000..pclk counter within one hscan state
 *  0b0001..pclk cycle within one hscan state
 *  0b0010..line counter within one vscan state
 *  0b0011..line cycle within one vscan state
 *  0b0100..frame counter
 *  0b0101..frame cycle
 *  0b0110..horizontal counter (pclk counter within one line )
 *  0b0111..vertical counter (line counter within one frame)
 */
#define LCDIF_PIGEON_n_0_MASK_CNT_SEL(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_MASK_CNT_SEL_SHIFT)) & LCDIF_PIGEON_n_0_MASK_CNT_SEL_MASK)

#define LCDIF_PIGEON_n_0_MASK_CNT_MASK           (0xFFF000U)
#define LCDIF_PIGEON_n_0_MASK_CNT_SHIFT          (12U)
#define LCDIF_PIGEON_n_0_MASK_CNT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_MASK_CNT_SHIFT)) & LCDIF_PIGEON_n_0_MASK_CNT_MASK)

#define LCDIF_PIGEON_n_0_STATE_MASK_MASK         (0xFF000000U)
#define LCDIF_PIGEON_n_0_STATE_MASK_SHIFT        (24U)
/*! STATE_MASK
 *  0b00000001..FRAME SYNC
 *  0b00000010..FRAME BEGIN
 *  0b00000100..FRAME DATA
 *  0b00001000..FRAME END
 *  0b00010000..LINE SYNC
 *  0b00100000..LINE BEGIN
 *  0b01000000..LINE DATA
 *  0b10000000..LINE END
 */
#define LCDIF_PIGEON_n_0_STATE_MASK(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_0_STATE_MASK_SHIFT)) & LCDIF_PIGEON_n_0_STATE_MASK_MASK)
/*! @} */

/* The count of LCDIF_PIGEON_n_0 */
#define LCDIF_PIGEON_n_0_COUNT                   (12U)

/*! @name PIGEON_n_1 - Panel Interface Signal Generator Register */
/*! @{ */

#define LCDIF_PIGEON_n_1_SET_CNT_MASK            (0xFFFFU)
#define LCDIF_PIGEON_n_1_SET_CNT_SHIFT           (0U)
/*! SET_CNT
 *  0b0000000000000000..Start as active
 */
#define LCDIF_PIGEON_n_1_SET_CNT(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_1_SET_CNT_SHIFT)) & LCDIF_PIGEON_n_1_SET_CNT_MASK)

#define LCDIF_PIGEON_n_1_CLR_CNT_MASK            (0xFFFF0000U)
#define LCDIF_PIGEON_n_1_CLR_CNT_SHIFT           (16U)
/*! CLR_CNT
 *  0b0000000000000000..Keep active until mask off
 */
#define LCDIF_PIGEON_n_1_CLR_CNT(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_1_CLR_CNT_SHIFT)) & LCDIF_PIGEON_n_1_CLR_CNT_MASK)
/*! @} */

/* The count of LCDIF_PIGEON_n_1 */
#define LCDIF_PIGEON_n_1_COUNT                   (12U)

/*! @name PIGEON_n_2 - Panel Interface Signal Generator Register */
/*! @{ */

#define LCDIF_PIGEON_n_2_SIG_LOGIC_MASK          (0xFU)
#define LCDIF_PIGEON_n_2_SIG_LOGIC_SHIFT         (0U)
/*! SIG_LOGIC
 *  0b0000..No logic operation
 *  0b0001..sigout = sig_another AND this_sig
 *  0b0010..sigout = sig_another OR this_sig
 *  0b0011..mask = sig_another AND other_masks
 */
#define LCDIF_PIGEON_n_2_SIG_LOGIC(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_2_SIG_LOGIC_SHIFT)) & LCDIF_PIGEON_n_2_SIG_LOGIC_MASK)

#define LCDIF_PIGEON_n_2_SIG_ANOTHER_MASK        (0x1F0U)
#define LCDIF_PIGEON_n_2_SIG_ANOTHER_SHIFT       (4U)
/*! SIG_ANOTHER
 *  0b00000..Keep active until mask off
 */
#define LCDIF_PIGEON_n_2_SIG_ANOTHER(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_2_SIG_ANOTHER_SHIFT)) & LCDIF_PIGEON_n_2_SIG_ANOTHER_MASK)

#define LCDIF_PIGEON_n_2_RSVD_MASK               (0xFFFFFE00U)
#define LCDIF_PIGEON_n_2_RSVD_SHIFT              (9U)
#define LCDIF_PIGEON_n_2_RSVD(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_PIGEON_n_2_RSVD_SHIFT)) & LCDIF_PIGEON_n_2_RSVD_MASK)
/*! @} */

/* The count of LCDIF_PIGEON_n_2 */
#define LCDIF_PIGEON_n_2_COUNT                   (12U)


/*!
 * @}
 */ /* end of group LCDIF_Register_Masks */


/*!
 * @}
 */ /* end of group LCDIF_Peripheral_Access_Layer */


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


#endif  /* PERI_LCDIF_H_ */

