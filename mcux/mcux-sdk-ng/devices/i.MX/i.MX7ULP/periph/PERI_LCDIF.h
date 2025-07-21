/*
** ###################################################################
**     Processors:          MCIMX7U3CVP06
**                          MCIMX7U3DVK07
**                          MCIMX7U5CVP06
**                          MCIMX7U5DVK07
**                          MCIMX7U5DVP07
**
**     Version:             rev. 8.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2016-04-13)
**         Initial version.
**     - rev. 2.0 (2016-07-19)
**         RevC Header ER
**     - rev. 3.0 (2017-02-28)
**         RevD Header ER
**     - rev. 4.0 (2017-05-02)
**         RevE Header ER
**     - rev. 5.0 (2017-12-22)
**         RevA(B0) Header GA
**     - rev. 6.0 (2018-02-01)
**         RevB(B0) Header GA
**     - rev. 7.0 (2018-11-05)
**         RevA(B1) Header
**     - rev. 8.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LCDIF.h
 * @version 8.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCDIF
 *
 * CMSIS Peripheral Access Layer for LCDIF
 */

#if !defined(PERI_LCDIF_H_)
#define PERI_LCDIF_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MCIMX7U3CVP06) || defined(CPU_MCIMX7U3DVK07))
#include "MCIMX7U3_cm4_COMMON.h"
#elif (defined(CPU_MCIMX7U5CVP06) || defined(CPU_MCIMX7U5DVK07) || defined(CPU_MCIMX7U5DVP07))
#include "MCIMX7U5_cm4_COMMON.h"
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
       uint8_t RESERVED_2[28];
  __IO uint32_t VDCTRL0;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x70 */
  __IO uint32_t VDCTRL0_SET;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x74 */
  __IO uint32_t VDCTRL0_CLR;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x78 */
  __IO uint32_t VDCTRL0_TOG;                       /**< LCDIF VSYNC Mode and Dotclk Mode Control Register0, offset: 0x7C */
  __IO uint32_t VDCTRL1;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register1, offset: 0x80 */
       uint8_t RESERVED_3[12];
  __IO uint32_t VDCTRL2;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register2, offset: 0x90 */
       uint8_t RESERVED_4[12];
  __IO uint32_t VDCTRL3;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register3, offset: 0xA0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t VDCTRL4;                           /**< LCDIF VSYNC Mode and Dotclk Mode Control Register4, offset: 0xB0 */
       uint8_t RESERVED_6[220];
  __IO uint32_t BM_ERROR_STAT;                     /**< Bus Master Error Status Register, offset: 0x190 */
       uint8_t RESERVED_7[12];
  __IO uint32_t CRC_STAT;                          /**< CRC Status Register, offset: 0x1A0 */
       uint8_t RESERVED_8[12];
  __I  uint32_t STAT;                              /**< LCD Interface Status Register, offset: 0x1B0 */
       uint8_t RESERVED_9[92];
  __IO uint32_t AS_CTRL;                           /**< LCDIF AS Buffer Control Register, offset: 0x210 */
       uint8_t RESERVED_10[12];
  __IO uint32_t AS_BUF;                            /**< Alpha Surface Buffer Pointer, offset: 0x220 */
       uint8_t RESERVED_11[12];
  __IO uint32_t AS_NEXT_BUF;                       /**< offset: 0x230 */
       uint8_t RESERVED_12[12];
  __IO uint32_t AS_CLRKEYLOW;                      /**< LCDIF Overlay Color Key Low, offset: 0x240 */
       uint8_t RESERVED_13[12];
  __IO uint32_t AS_CLRKEYHIGH;                     /**< LCDIF Overlay Color Key High, offset: 0x250 */
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

#define LCDIF_CTRL_DOTCLK_MODE_MASK              (0x20000U)
#define LCDIF_CTRL_DOTCLK_MODE_SHIFT             (17U)
#define LCDIF_CTRL_DOTCLK_MODE(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_BYPASS_COUNT_MASK             (0x80000U)
#define LCDIF_CTRL_BYPASS_COUNT_SHIFT            (19U)
#define LCDIF_CTRL_BYPASS_COUNT(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_BYPASS_COUNT_MASK)

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

#define LCDIF_CTRL_SET_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_SET_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_SET_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_SET_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_SET_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_SET_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_SET_BYPASS_COUNT_MASK)

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

#define LCDIF_CTRL_CLR_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_CLR_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_CLR_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_CLR_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_CLR_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_CLR_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_CLR_BYPASS_COUNT_MASK)

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

#define LCDIF_CTRL_TOG_DOTCLK_MODE_MASK          (0x20000U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT         (17U)
#define LCDIF_CTRL_TOG_DOTCLK_MODE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_DOTCLK_MODE_SHIFT)) & LCDIF_CTRL_TOG_DOTCLK_MODE_MASK)

#define LCDIF_CTRL_TOG_BYPASS_COUNT_MASK         (0x80000U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT        (19U)
#define LCDIF_CTRL_TOG_BYPASS_COUNT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL_TOG_BYPASS_COUNT_SHIFT)) & LCDIF_CTRL_TOG_BYPASS_COUNT_MASK)

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
/*! @} */

/*! @name CTRL2 - LCDIF General Control2 Register */
/*! @{ */

#define LCDIF_CTRL2_RSRVD0_MASK                  (0xFFFU)
#define LCDIF_CTRL2_RSRVD0_SHIFT                 (0U)
#define LCDIF_CTRL2_RSRVD0(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_RSRVD0_SHIFT)) & LCDIF_CTRL2_RSRVD0_MASK)

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

#define LCDIF_CTRL2_SET_RSRVD0_MASK              (0xFFFU)
#define LCDIF_CTRL2_SET_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_SET_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_SET_RSRVD0_SHIFT)) & LCDIF_CTRL2_SET_RSRVD0_MASK)

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

#define LCDIF_CTRL2_CLR_RSRVD0_MASK              (0xFFFU)
#define LCDIF_CTRL2_CLR_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_CLR_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_CLR_RSRVD0_SHIFT)) & LCDIF_CTRL2_CLR_RSRVD0_MASK)

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

#define LCDIF_CTRL2_TOG_RSRVD0_MASK              (0xFFFU)
#define LCDIF_CTRL2_TOG_RSRVD0_SHIFT             (0U)
#define LCDIF_CTRL2_TOG_RSRVD0(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CTRL2_TOG_RSRVD0_SHIFT)) & LCDIF_CTRL2_TOG_RSRVD0_MASK)

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

#define LCDIF_STAT_RSRVD0_MASK                   (0x1FFFE00U)
#define LCDIF_STAT_RSRVD0_SHIFT                  (9U)
#define LCDIF_STAT_RSRVD0(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_STAT_RSRVD0_SHIFT)) & LCDIF_STAT_RSRVD0_MASK)

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

#define LCDIF_AS_CTRL_RVDS1_MASK                 (0xFF000000U)
#define LCDIF_AS_CTRL_RVDS1_SHIFT                (24U)
#define LCDIF_AS_CTRL_RVDS1(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_AS_CTRL_RVDS1_SHIFT)) & LCDIF_AS_CTRL_RVDS1_MASK)
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

