/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
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
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LCDIF.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCDIF
 *
 * CMSIS Peripheral Access Layer for LCDIF
 */

#if !defined(PERI_LCDIF_H_)
#define PERI_LCDIF_H_                            /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
   -- LCDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Peripheral_Access_Layer LCDIF Peripheral Access Layer
 * @{
 */

/** LCDIF - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[4672];
  __IO uint32_t FRAMEBUFFERCONFIG0;                /**< Frame Buffer Configuration 0, offset: 0x1240 */
       uint8_t RESERVED_1[28];
  __IO uint32_t FRAMEBUFFERADDRESS0;               /**< Starting Address of the Frame Buffer, offset: 0x1260 */
       uint8_t RESERVED_2[28];
  __IO uint32_t FRAMEBUFFERSTRIDE0;                /**< Stride of the Frame Buffer in Bytes, offset: 0x1280 */
       uint8_t RESERVED_3[220];
  __IO uint32_t DISPLAYDITHERCONFIG0;              /**< Configuration for Dithering, offset: 0x1360 */
       uint8_t RESERVED_4[28];
  __IO uint32_t DISPLAYDITHERTABLELOW0;            /**< Dither Table Low, offset: 0x1380 */
       uint8_t RESERVED_5[28];
  __IO uint32_t DISPLAYDITHERTABLEHIGH0;           /**< Dither Table High, offset: 0x13A0 */
       uint8_t RESERVED_6[28];
  __IO uint32_t PANELCONFIG0;                      /**< Panel Configuration, offset: 0x13C0 */
       uint8_t RESERVED_7[28];
  __IO uint32_t PANELTIMING0;                      /**< Timing for Hardware Panel Sequencing, offset: 0x13E0 */
       uint8_t RESERVED_8[28];
  __IO uint32_t HDISPLAY0;                         /**< Horizontal Total and Display End Counters, offset: 0x1400 */
       uint8_t RESERVED_9[28];
  __IO uint32_t HSYNC0;                            /**< Horizontal Sync Counters, offset: 0x1420 */
       uint8_t RESERVED_10[92];
  __IO uint32_t VDISPLAY0;                         /**< Vertical Total and Display End Counters, offset: 0x1480 */
       uint8_t RESERVED_11[28];
  __IO uint32_t VSYNC0;                            /**< Vertical Sync Counters, offset: 0x14A0 */
       uint8_t RESERVED_12[28];
  __I  uint32_t DISPLAYCURRENTLOCATION0;           /**< Current x,y Location of Display Controller, offset: 0x14C0 */
       uint8_t RESERVED_13[28];
  __IO uint32_t GAMMAINDEX0;                       /**< Index into Gamma Table, offset: 0x14E0 */
       uint8_t RESERVED_14[28];
  __IO uint32_t GAMMADATA0;                        /**< Translation Values for the Gamma Table, offset: 0x1500 */
       uint8_t RESERVED_15[28];
  __IO uint32_t CURSORCONFIG;                      /**< Configuration for the Cursor, offset: 0x1520 */
       uint8_t RESERVED_16[12];
  __IO uint32_t CURSORADDRESS;                     /**< Address of the Cursor Shape, offset: 0x1530 */
       uint8_t RESERVED_17[12];
  __IO uint32_t CURSORLOCATION;                    /**< Location of the cursor on the owning display, offset: 0x1540 */
       uint8_t RESERVED_18[12];
  __IO uint32_t CURSORBACKGROUND;                  /**< Background Color for Masked Cursors, offset: 0x1550 */
       uint8_t RESERVED_19[12];
  __IO uint32_t CURSORFOREGROUND;                  /**< Foreground Color for Masked Cursors, offset: 0x1560 */
       uint8_t RESERVED_20[156];
  __IO uint32_t DISPLAYINTR;                       /**< Display Interrupt, offset: 0x1600 */
       uint8_t RESERVED_21[12];
  __IO uint32_t DISPLAYINTRENABLE;                 /**< Interrupt Enable for Display_0 (and Display_1 if present), offset: 0x1610 */
       uint8_t RESERVED_22[12];
  __IO uint32_t DBICONFIG0;                        /**< DBI Configuration 0, offset: 0x1620 */
       uint8_t RESERVED_23[28];
  __O  uint32_t DBIIFRESET0;                       /**< Reset DBI Interface to Idle State, offset: 0x1640 */
       uint8_t RESERVED_24[28];
  __IO uint32_t DBIWRCHAR10;                       /**< DBI Write Characteristics 1, offset: 0x1660 */
       uint8_t RESERVED_25[28];
  __IO uint32_t DBIWRCHAR20;                       /**< DBI Write Characteristics 2, offset: 0x1680 */
       uint8_t RESERVED_26[28];
  __O  uint32_t DBICMD0;                           /**< DBI Command In/Out Port, offset: 0x16A0 */
       uint8_t RESERVED_27[28];
  __IO uint32_t DPICONFIG0;                        /**< DPI Configuration 0, offset: 0x16C0 */
       uint8_t RESERVED_28[44];
  __I  uint32_t DCCHIPREV;                         /**< Revision for the LCDIF Peripheral in BCD, offset: 0x16F0 */
       uint8_t RESERVED_29[12];
  __I  uint32_t DCCHIPDATE;                        /**< Shows the release date for the IP in YYYYMMDD (year, month), offset: 0x1700 */
       uint8_t RESERVED_30[28];
  __I  uint32_t DCCHIPPATCHREV;                    /**< Patch Revision, offset: 0x1720 */
       uint8_t RESERVED_31[28];
  __IO uint32_t DCTILEINCFG0;                      /**< Tile Input Configuration, offset: 0x1740 */
       uint8_t RESERVED_32[28];
  __IO uint32_t DCTILEUVFRAMEBUFFERADR0;           /**< UV Frame Buffer Address when Tile Input, offset: 0x1760 */
       uint8_t RESERVED_33[28];
  __IO uint32_t DCTILEUVFRAMEBUFFERSTR0;           /**< UV Frame Buffer Stride when Tile Input, offset: 0x1780 */
       uint8_t RESERVED_34[44];
  __I  uint32_t DCPRODUCTID;                       /**< Product ID, offset: 0x17B0 */
       uint8_t RESERVED_35[108];
  __IO uint32_t DEBUGCOUNTERSELECT0;               /**< Debug Counter Select, offset: 0x1820 */
       uint8_t RESERVED_36[28];
  __IO uint32_t DEBUGCOUNTERVALUE0;                /**< Debug Counter Value, offset: 0x1840 */
} LCDIF_Type;

/* ----------------------------------------------------------------------------
   -- LCDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Register_Masks LCDIF Register Masks
 * @{
 */

/*! @name FRAMEBUFFERCONFIG0 - Frame Buffer Configuration 0 */
/*! @{ */

#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT_MASK     (0x7U)
#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT_SHIFT    (0U)
/*! FORMAT - The format of the frame buffer. */
#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_FORMAT_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_FORMAT_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_MODE_MASK       (0x10U)
#define LCDIF_FRAMEBUFFERCONFIG0_MODE_SHIFT      (4U)
/*! MODE - Mode of the frame buffer.
 *  0b0..LINEAR
 *  0b1..TILE4x4 INPUT
 */
#define LCDIF_FRAMEBUFFERCONFIG0_MODE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_MODE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_MODE_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_OUTPUT_MASK     (0x100U)
#define LCDIF_FRAMEBUFFERCONFIG0_OUTPUT_SHIFT    (8U)
/*! OUTPUT - Output
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_OUTPUT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_OUTPUT_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_OUTPUT_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_SWITCHPANEL_MASK (0x200U)
#define LCDIF_FRAMEBUFFERCONFIG0_SWITCHPANEL_SHIFT (9U)
/*! SWITCHPANEL - Switch Panel
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_SWITCHPANEL(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_SWITCHPANEL_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_SWITCHPANEL_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_GAMMA_MASK      (0x1000U)
#define LCDIF_FRAMEBUFFERCONFIG0_GAMMA_SHIFT     (12U)
/*! GAMMA - Gamma
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_GAMMA(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_GAMMA_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_GAMMA_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_VALID_MASK      (0x10000U)
#define LCDIF_FRAMEBUFFERCONFIG0_VALID_SHIFT     (16U)
/*! VALID - Valid
 *  0b0..Working
 *  0b1..Pending
 */
#define LCDIF_FRAMEBUFFERCONFIG0_VALID(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_VALID_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_VALID_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_RESET_MASK      (0x100000U)
#define LCDIF_FRAMEBUFFERCONFIG0_RESET_SHIFT     (20U)
/*! RESET - Reset
 *  0b0..For DBI, this field should be = 0.
 *  0b1..Enable DPI Timing, start a DPI transfer.
 */
#define LCDIF_FRAMEBUFFERCONFIG0_RESET(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_RESET_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_RESET_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_UNDERFLOW_MASK  (0x1000000U)
#define LCDIF_FRAMEBUFFERCONFIG0_UNDERFLOW_SHIFT (24U)
/*! UNDERFLOW - Underflow
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_UNDERFLOW(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_UNDERFLOW_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_UNDERFLOW_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_FLIP_IN_PROGRESS_MASK (0x10000000U)
#define LCDIF_FRAMEBUFFERCONFIG0_FLIP_IN_PROGRESS_SHIFT (28U)
/*! FLIP_IN_PROGRESS - Flip in Progress
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_FLIP_IN_PROGRESS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_FLIP_IN_PROGRESS_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_FLIP_IN_PROGRESS_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_BACK_PRESSURE_DISABLE_MASK (0x20000000U)
#define LCDIF_FRAMEBUFFERCONFIG0_BACK_PRESSURE_DISABLE_SHIFT (29U)
/*! BACK_PRESSURE_DISABLE - Disable Back Pressure
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_FRAMEBUFFERCONFIG0_BACK_PRESSURE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_BACK_PRESSURE_DISABLE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_BACK_PRESSURE_DISABLE_MASK)
/*! @} */

/*! @name FRAMEBUFFERADDRESS0 - Starting Address of the Frame Buffer */
/*! @{ */

#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_MASK   (0x7FFFFFFFU)
#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_SHIFT  (0U)
/*! ADDRESS - Address */
#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_SHIFT)) & LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_MASK)

#define LCDIF_FRAMEBUFFERADDRESS0_TYPE_MASK      (0x80000000U)
#define LCDIF_FRAMEBUFFERADDRESS0_TYPE_SHIFT     (31U)
/*! TYPE - System Type
 *  0b0..System
 *  0b1..Virtual system
 */
#define LCDIF_FRAMEBUFFERADDRESS0_TYPE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERADDRESS0_TYPE_SHIFT)) & LCDIF_FRAMEBUFFERADDRESS0_TYPE_MASK)
/*! @} */

/*! @name FRAMEBUFFERSTRIDE0 - Stride of the Frame Buffer in Bytes */
/*! @{ */

#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_MASK     (0x1FFFFU)
#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_SHIFT    (0U)
/*! STRIDE - Number of bytes from start of one line to next line. This value needs to be 128 byte aligned. */
#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_SHIFT)) & LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_MASK)
/*! @} */

/*! @name DISPLAYDITHERCONFIG0 - Configuration for Dithering */
/*! @{ */

#define LCDIF_DISPLAYDITHERCONFIG0_BLUE_SIZE_MASK (0xFU)
#define LCDIF_DISPLAYDITHERCONFIG0_BLUE_SIZE_SHIFT (0U)
/*! BLUE_SIZE - Blue Size */
#define LCDIF_DISPLAYDITHERCONFIG0_BLUE_SIZE(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERCONFIG0_BLUE_SIZE_SHIFT)) & LCDIF_DISPLAYDITHERCONFIG0_BLUE_SIZE_MASK)

#define LCDIF_DISPLAYDITHERCONFIG0_GREEN_SIZE_MASK (0xF00U)
#define LCDIF_DISPLAYDITHERCONFIG0_GREEN_SIZE_SHIFT (8U)
/*! GREEN_SIZE - Green Size */
#define LCDIF_DISPLAYDITHERCONFIG0_GREEN_SIZE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERCONFIG0_GREEN_SIZE_SHIFT)) & LCDIF_DISPLAYDITHERCONFIG0_GREEN_SIZE_MASK)

#define LCDIF_DISPLAYDITHERCONFIG0_RED_SIZE_MASK (0xF0000U)
#define LCDIF_DISPLAYDITHERCONFIG0_RED_SIZE_SHIFT (16U)
/*! RED_SIZE - Red Size */
#define LCDIF_DISPLAYDITHERCONFIG0_RED_SIZE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERCONFIG0_RED_SIZE_SHIFT)) & LCDIF_DISPLAYDITHERCONFIG0_RED_SIZE_MASK)

#define LCDIF_DISPLAYDITHERCONFIG0_ENABLE_MASK   (0x80000000U)
#define LCDIF_DISPLAYDITHERCONFIG0_ENABLE_SHIFT  (31U)
/*! ENABLE - Enable Dithering
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_DISPLAYDITHERCONFIG0_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERCONFIG0_ENABLE_SHIFT)) & LCDIF_DISPLAYDITHERCONFIG0_ENABLE_MASK)
/*! @} */

/*! @name DISPLAYDITHERTABLELOW0 - Dither Table Low */
/*! @{ */

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_MASK  (0xFU)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_SHIFT (0U)
/*! Y0_X0 - Dither threshold value for x,y=0,0. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_MASK  (0xF0U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_SHIFT (4U)
/*! Y0_X1 - Dither threshold value for x,y=1,0. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_MASK  (0xF00U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_SHIFT (8U)
/*! Y0_X2 - Dither threshold value for x,y=2,0. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_MASK  (0xF000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_SHIFT (12U)
/*! Y0_X3 - Dither threshold value for x,y=3,0. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_MASK  (0xF0000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_SHIFT (16U)
/*! Y1_X0 - Dither threshold value for x,y=0,1. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_MASK  (0xF00000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_SHIFT (20U)
/*! Y1_X1 - Dither threshold value for x,y=1,1. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_MASK  (0xF000000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_SHIFT (24U)
/*! Y1_X2 - Dither threshold value for x,y=2,1. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_MASK  (0xF0000000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_SHIFT (28U)
/*! Y1_X3 - Dither threshold value for x,y=3,1. */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_MASK)
/*! @} */

/*! @name DISPLAYDITHERTABLEHIGH0 - Dither Table High */
/*! @{ */

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_MASK (0xFU)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_SHIFT (0U)
/*! Y2_X0 - Dither threshold value for x,y=0,2. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_MASK (0xF0U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_SHIFT (4U)
/*! Y2_X1 - Dither threshold value for x,y=1,2. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_MASK (0xF00U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_SHIFT (8U)
/*! Y2_X2 - Dither threshold value for x,y=2,2. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_MASK (0xF000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_SHIFT (12U)
/*! Y2_X3 - Dither threshold value for x,y=3,2. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_MASK (0xF0000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_SHIFT (16U)
/*! Y3_X0 - Dither threshold value for x,y=0,3. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_MASK (0xF00000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_SHIFT (20U)
/*! Y3_X1 - Dither threshold value for x,y=1,3. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_MASK (0xF000000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_SHIFT (24U)
/*! Y3_X2 - Dither threshold value for x,y=2,3. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_MASK (0xF0000000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_SHIFT (28U)
/*! Y3_X3 - Dither threshold value for x,y=3,3. */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_MASK)
/*! @} */

/*! @name PANELCONFIG0 - Panel Configuration */
/*! @{ */

#define LCDIF_PANELCONFIG0_DE_MASK               (0x1U)
#define LCDIF_PANELCONFIG0_DE_SHIFT              (0U)
/*! DE - Data Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_PANELCONFIG0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DE_SHIFT)) & LCDIF_PANELCONFIG0_DE_MASK)

#define LCDIF_PANELCONFIG0_DE_POLARITY_MASK      (0x2U)
#define LCDIF_PANELCONFIG0_DE_POLARITY_SHIFT     (1U)
/*! DE_POLARITY - Data Enable Polarity
 *  0b0..Positive
 *  0b1..Negative
 */
#define LCDIF_PANELCONFIG0_DE_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DE_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_DE_POLARITY_MASK)

#define LCDIF_PANELCONFIG0_DATA_POLARITY_MASK    (0x20U)
#define LCDIF_PANELCONFIG0_DATA_POLARITY_SHIFT   (5U)
/*! DATA_POLARITY - Data Polarity
 *  0b0..Positive
 *  0b1..Negative
 */
#define LCDIF_PANELCONFIG0_DATA_POLARITY(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DATA_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_DATA_POLARITY_MASK)

#define LCDIF_PANELCONFIG0_CLOCK_MASK            (0x100U)
#define LCDIF_PANELCONFIG0_CLOCK_SHIFT           (8U)
/*! CLOCK - Clock Enable/Disable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_PANELCONFIG0_CLOCK(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_CLOCK_SHIFT)) & LCDIF_PANELCONFIG0_CLOCK_MASK)

#define LCDIF_PANELCONFIG0_CLOCK_POLARITY_MASK   (0x200U)
#define LCDIF_PANELCONFIG0_CLOCK_POLARITY_SHIFT  (9U)
/*! CLOCK_POLARITY - Clock Polarity
 *  0b0..Positive
 *  0b1..Negative
 */
#define LCDIF_PANELCONFIG0_CLOCK_POLARITY(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_CLOCK_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_CLOCK_POLARITY_MASK)

#define LCDIF_PANELCONFIG0_SEQUENCING_MASK       (0x80000000U)
#define LCDIF_PANELCONFIG0_SEQUENCING_SHIFT      (31U)
/*! SEQUENCING - Enable software or hardware panel sequencing.
 *  0b0..Hardware
 *  0b1..Software
 */
#define LCDIF_PANELCONFIG0_SEQUENCING(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_SEQUENCING_SHIFT)) & LCDIF_PANELCONFIG0_SEQUENCING_MASK)
/*! @} */

/*! @name PANELTIMING0 - Timing for Hardware Panel Sequencing */
/*! @{ */

#define LCDIF_PANELTIMING0_POWER_ENABLE_MASK     (0xFU)
#define LCDIF_PANELTIMING0_POWER_ENABLE_SHIFT    (0U)
/*! POWER_ENABLE - Number of VSYNCsto wait after power has been enabled. */
#define LCDIF_PANELTIMING0_POWER_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_POWER_ENABLE_SHIFT)) & LCDIF_PANELTIMING0_POWER_ENABLE_MASK)

#define LCDIF_PANELTIMING0_BACKLIGHT_ENABLE_MASK (0xF0U)
#define LCDIF_PANELTIMING0_BACKLIGHT_ENABLE_SHIFT (4U)
/*! BACKLIGHT_ENABLE - Number of VSYNCs to wait after backlight has been enabled. */
#define LCDIF_PANELTIMING0_BACKLIGHT_ENABLE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_BACKLIGHT_ENABLE_SHIFT)) & LCDIF_PANELTIMING0_BACKLIGHT_ENABLE_MASK)

#define LCDIF_PANELTIMING0_CLOCK_ENABLE_MASK     (0xF00U)
#define LCDIF_PANELTIMING0_CLOCK_ENABLE_SHIFT    (8U)
/*! CLOCK_ENABLE - Number of VSYNCs to wait after clock has been enabled. */
#define LCDIF_PANELTIMING0_CLOCK_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_CLOCK_ENABLE_SHIFT)) & LCDIF_PANELTIMING0_CLOCK_ENABLE_MASK)

#define LCDIF_PANELTIMING0_DATA_ENABLE_MASK      (0xF000U)
#define LCDIF_PANELTIMING0_DATA_ENABLE_SHIFT     (12U)
/*! DATA_ENABLE - Number of VSYNCs to wait after data has been enabled. */
#define LCDIF_PANELTIMING0_DATA_ENABLE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_DATA_ENABLE_SHIFT)) & LCDIF_PANELTIMING0_DATA_ENABLE_MASK)

#define LCDIF_PANELTIMING0_DATA_DISABLE_MASK     (0xF0000U)
#define LCDIF_PANELTIMING0_DATA_DISABLE_SHIFT    (16U)
/*! DATA_DISABLE - Number of VSYNCs to wait after data has been disabled. */
#define LCDIF_PANELTIMING0_DATA_DISABLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_DATA_DISABLE_SHIFT)) & LCDIF_PANELTIMING0_DATA_DISABLE_MASK)

#define LCDIF_PANELTIMING0_CLOCK_DISABLE_MASK    (0xF00000U)
#define LCDIF_PANELTIMING0_CLOCK_DISABLE_SHIFT   (20U)
/*! CLOCK_DISABLE - Number of VSYNCs to wait after clock has been disabled. */
#define LCDIF_PANELTIMING0_CLOCK_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_CLOCK_DISABLE_SHIFT)) & LCDIF_PANELTIMING0_CLOCK_DISABLE_MASK)

#define LCDIF_PANELTIMING0_BACKLIGHT_DISABLE_MASK (0xF000000U)
#define LCDIF_PANELTIMING0_BACKLIGHT_DISABLE_SHIFT (24U)
/*! BACKLIGHT_DISABLE - Number of VSYNCs to wait after backlight has been disabled. */
#define LCDIF_PANELTIMING0_BACKLIGHT_DISABLE(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_BACKLIGHT_DISABLE_SHIFT)) & LCDIF_PANELTIMING0_BACKLIGHT_DISABLE_MASK)

#define LCDIF_PANELTIMING0_POWER_DISABLE_MASK    (0xF0000000U)
#define LCDIF_PANELTIMING0_POWER_DISABLE_SHIFT   (28U)
/*! POWER_DISABLE - Number of VSYNCs to wait after power has been disabled. */
#define LCDIF_PANELTIMING0_POWER_DISABLE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELTIMING0_POWER_DISABLE_SHIFT)) & LCDIF_PANELTIMING0_POWER_DISABLE_MASK)
/*! @} */

/*! @name HDISPLAY0 - Horizontal Total and Display End Counters */
/*! @{ */

#define LCDIF_HDISPLAY0_DISPLAY_END_MASK         (0x1FFFU)
#define LCDIF_HDISPLAY0_DISPLAY_END_SHIFT        (0U)
/*! DISPLAY_END - Number of visible horizontal pixels. */
#define LCDIF_HDISPLAY0_DISPLAY_END(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_HDISPLAY0_DISPLAY_END_SHIFT)) & LCDIF_HDISPLAY0_DISPLAY_END_MASK)

#define LCDIF_HDISPLAY0_TOTAL_MASK               (0x1FFF0000U)
#define LCDIF_HDISPLAY0_TOTAL_SHIFT              (16U)
/*! TOTAL - Total number of horizontal pixels. */
#define LCDIF_HDISPLAY0_TOTAL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_HDISPLAY0_TOTAL_SHIFT)) & LCDIF_HDISPLAY0_TOTAL_MASK)
/*! @} */

/*! @name HSYNC0 - Horizontal Sync Counters */
/*! @{ */

#define LCDIF_HSYNC0_START_MASK                  (0x1FFFU)
#define LCDIF_HSYNC0_START_SHIFT                 (0U)
/*! START - Start of horizontal sync pulse. */
#define LCDIF_HSYNC0_START(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_START_SHIFT)) & LCDIF_HSYNC0_START_MASK)

#define LCDIF_HSYNC0_END_MASK                    (0x1FFF0000U)
#define LCDIF_HSYNC0_END_SHIFT                   (16U)
/*! END - End of horizontal sync pulse. */
#define LCDIF_HSYNC0_END(x)                      (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_END_SHIFT)) & LCDIF_HSYNC0_END_MASK)

#define LCDIF_HSYNC0_PULSE_MASK                  (0x40000000U)
#define LCDIF_HSYNC0_PULSE_SHIFT                 (30U)
/*! PULSE - Horizontal sync pulse control.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_HSYNC0_PULSE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_PULSE_SHIFT)) & LCDIF_HSYNC0_PULSE_MASK)

#define LCDIF_HSYNC0_POLARITY_MASK               (0x80000000U)
#define LCDIF_HSYNC0_POLARITY_SHIFT              (31U)
/*! POLARITY - Polarity of the horizontal sync pulse
 *  0b0..Positive
 *  0b1..Negative
 */
#define LCDIF_HSYNC0_POLARITY(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_POLARITY_SHIFT)) & LCDIF_HSYNC0_POLARITY_MASK)
/*! @} */

/*! @name VDISPLAY0 - Vertical Total and Display End Counters */
/*! @{ */

#define LCDIF_VDISPLAY0_DISPLAY_END_MASK         (0xFFFU)
#define LCDIF_VDISPLAY0_DISPLAY_END_SHIFT        (0U)
/*! DISPLAY_END - Number of visible vertical lines. */
#define LCDIF_VDISPLAY0_DISPLAY_END(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDISPLAY0_DISPLAY_END_SHIFT)) & LCDIF_VDISPLAY0_DISPLAY_END_MASK)

#define LCDIF_VDISPLAY0_TOTAL_MASK               (0xFFF0000U)
#define LCDIF_VDISPLAY0_TOTAL_SHIFT              (16U)
/*! TOTAL - Total number of vertical lines. */
#define LCDIF_VDISPLAY0_TOTAL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_VDISPLAY0_TOTAL_SHIFT)) & LCDIF_VDISPLAY0_TOTAL_MASK)
/*! @} */

/*! @name VSYNC0 - Vertical Sync Counters */
/*! @{ */

#define LCDIF_VSYNC0_START_MASK                  (0xFFFU)
#define LCDIF_VSYNC0_START_SHIFT                 (0U)
/*! START - Start of the vertical sync pulse. */
#define LCDIF_VSYNC0_START(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_START_SHIFT)) & LCDIF_VSYNC0_START_MASK)

#define LCDIF_VSYNC0_END_MASK                    (0xFFF0000U)
#define LCDIF_VSYNC0_END_SHIFT                   (16U)
/*! END - End of the vertical sync pulse. */
#define LCDIF_VSYNC0_END(x)                      (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_END_SHIFT)) & LCDIF_VSYNC0_END_MASK)

#define LCDIF_VSYNC0_PULSE_MASK                  (0x40000000U)
#define LCDIF_VSYNC0_PULSE_SHIFT                 (30U)
/*! PULSE - Vertical sync pulse control.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_VSYNC0_PULSE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_PULSE_SHIFT)) & LCDIF_VSYNC0_PULSE_MASK)

#define LCDIF_VSYNC0_POLARITY_MASK               (0x80000000U)
#define LCDIF_VSYNC0_POLARITY_SHIFT              (31U)
/*! POLARITY - Polarity of the vertical sync pulse.
 *  0b0..Positive
 *  0b1..Active-low
 */
#define LCDIF_VSYNC0_POLARITY(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_POLARITY_SHIFT)) & LCDIF_VSYNC0_POLARITY_MASK)
/*! @} */

/*! @name DISPLAYCURRENTLOCATION0 - Current x,y Location of Display Controller */
/*! @{ */

#define LCDIF_DISPLAYCURRENTLOCATION0_X_MASK     (0xFFFFU)
#define LCDIF_DISPLAYCURRENTLOCATION0_X_SHIFT    (0U)
/*! X - Current X location. */
#define LCDIF_DISPLAYCURRENTLOCATION0_X(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYCURRENTLOCATION0_X_SHIFT)) & LCDIF_DISPLAYCURRENTLOCATION0_X_MASK)

#define LCDIF_DISPLAYCURRENTLOCATION0_Y_MASK     (0xFFFF0000U)
#define LCDIF_DISPLAYCURRENTLOCATION0_Y_SHIFT    (16U)
/*! Y - Current Y location. */
#define LCDIF_DISPLAYCURRENTLOCATION0_Y(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYCURRENTLOCATION0_Y_SHIFT)) & LCDIF_DISPLAYCURRENTLOCATION0_Y_MASK)
/*! @} */

/*! @name GAMMAINDEX0 - Index into Gamma Table */
/*! @{ */

#define LCDIF_GAMMAINDEX0_INDEX_MASK             (0xFFU)
#define LCDIF_GAMMAINDEX0_INDEX_SHIFT            (0U)
/*! INDEX - Index into Gamma Table. */
#define LCDIF_GAMMAINDEX0_INDEX(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMAINDEX0_INDEX_SHIFT)) & LCDIF_GAMMAINDEX0_INDEX_MASK)
/*! @} */

/*! @name GAMMADATA0 - Translation Values for the Gamma Table */
/*! @{ */

#define LCDIF_GAMMADATA0_BLUE_MASK               (0xFFU)
#define LCDIF_GAMMADATA0_BLUE_SHIFT              (0U)
/*! BLUE - Blue translation value. */
#define LCDIF_GAMMADATA0_BLUE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_BLUE_SHIFT)) & LCDIF_GAMMADATA0_BLUE_MASK)

#define LCDIF_GAMMADATA0_GREEN_MASK              (0xFF00U)
#define LCDIF_GAMMADATA0_GREEN_SHIFT             (8U)
/*! GREEN - Green translation value. */
#define LCDIF_GAMMADATA0_GREEN(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_GREEN_SHIFT)) & LCDIF_GAMMADATA0_GREEN_MASK)

#define LCDIF_GAMMADATA0_RED_MASK                (0xFF0000U)
#define LCDIF_GAMMADATA0_RED_SHIFT               (16U)
/*! RED - Red translation value. */
#define LCDIF_GAMMADATA0_RED(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_RED_SHIFT)) & LCDIF_GAMMADATA0_RED_MASK)
/*! @} */

/*! @name CURSORCONFIG - Configuration for the Cursor */
/*! @{ */

#define LCDIF_CURSORCONFIG_FORMAT_MASK           (0x3U)
#define LCDIF_CURSORCONFIG_FORMAT_SHIFT          (0U)
/*! FORMAT - Format of the cursor.
 *  0b00..DISABLED
 *  0b01..MASKED
 *  0b10..A8R8G8B8
 */
#define LCDIF_CURSORCONFIG_FORMAT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_FORMAT_SHIFT)) & LCDIF_CURSORCONFIG_FORMAT_MASK)

#define LCDIF_CURSORCONFIG_DISPLAY_MASK          (0x10U)
#define LCDIF_CURSORCONFIG_DISPLAY_SHIFT         (4U)
/*! DISPLAY - Display Controller owning the cursor.
 *  0b0..DISPLAY0
 *  0b1..DISPLAY1
 */
#define LCDIF_CURSORCONFIG_DISPLAY(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_DISPLAY_SHIFT)) & LCDIF_CURSORCONFIG_DISPLAY_MASK)

#define LCDIF_CURSORCONFIG_HOT_SPOT_Y_MASK       (0x1F00U)
#define LCDIF_CURSORCONFIG_HOT_SPOT_Y_SHIFT      (8U)
/*! HOT_SPOT_Y - Vertical offset to cursor hotspot. */
#define LCDIF_CURSORCONFIG_HOT_SPOT_Y(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_HOT_SPOT_Y_SHIFT)) & LCDIF_CURSORCONFIG_HOT_SPOT_Y_MASK)

#define LCDIF_CURSORCONFIG_HOT_SPOT_X_MASK       (0x1F0000U)
#define LCDIF_CURSORCONFIG_HOT_SPOT_X_SHIFT      (16U)
/*! HOT_SPOT_X - Horizontal offset to cursor hotspot. */
#define LCDIF_CURSORCONFIG_HOT_SPOT_X(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_HOT_SPOT_X_SHIFT)) & LCDIF_CURSORCONFIG_HOT_SPOT_X_MASK)

#define LCDIF_CURSORCONFIG_FLIP_IN_PROGRESS_MASK (0x80000000U)
#define LCDIF_CURSORCONFIG_FLIP_IN_PROGRESS_SHIFT (31U)
/*! FLIP_IN_PROGRESS - When the cursor address gets written to, this bit gets set to one. */
#define LCDIF_CURSORCONFIG_FLIP_IN_PROGRESS(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_FLIP_IN_PROGRESS_SHIFT)) & LCDIF_CURSORCONFIG_FLIP_IN_PROGRESS_MASK)
/*! @} */

/*! @name CURSORADDRESS - Address of the Cursor Shape */
/*! @{ */

#define LCDIF_CURSORADDRESS_ADDRESS_MASK         (0x7FFFFFFFU)
#define LCDIF_CURSORADDRESS_ADDRESS_SHIFT        (0U)
/*! ADDRESS - ADDRESS */
#define LCDIF_CURSORADDRESS_ADDRESS(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORADDRESS_ADDRESS_SHIFT)) & LCDIF_CURSORADDRESS_ADDRESS_MASK)

#define LCDIF_CURSORADDRESS_TYPE_MASK            (0x80000000U)
#define LCDIF_CURSORADDRESS_TYPE_SHIFT           (31U)
/*! TYPE - System Type
 *  0b0..System.
 *  0b1..Virtual system.
 */
#define LCDIF_CURSORADDRESS_TYPE(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORADDRESS_TYPE_SHIFT)) & LCDIF_CURSORADDRESS_TYPE_MASK)
/*! @} */

/*! @name CURSORLOCATION - Location of the cursor on the owning display */
/*! @{ */

#define LCDIF_CURSORLOCATION_X_MASK              (0x1FFFU)
#define LCDIF_CURSORLOCATION_X_SHIFT             (0U)
/*! X - X location of cursor's hotspot. */
#define LCDIF_CURSORLOCATION_X(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORLOCATION_X_SHIFT)) & LCDIF_CURSORLOCATION_X_MASK)

#define LCDIF_CURSORLOCATION_Y_MASK              (0xFFF0000U)
#define LCDIF_CURSORLOCATION_Y_SHIFT             (16U)
/*! Y - Y location of cursor's hotspot. */
#define LCDIF_CURSORLOCATION_Y(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORLOCATION_Y_SHIFT)) & LCDIF_CURSORLOCATION_Y_MASK)
/*! @} */

/*! @name CURSORBACKGROUND - Background Color for Masked Cursors */
/*! @{ */

#define LCDIF_CURSORBACKGROUND_BLUE_MASK         (0xFFU)
#define LCDIF_CURSORBACKGROUND_BLUE_SHIFT        (0U)
/*! BLUE - Blue value */
#define LCDIF_CURSORBACKGROUND_BLUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_BLUE_SHIFT)) & LCDIF_CURSORBACKGROUND_BLUE_MASK)

#define LCDIF_CURSORBACKGROUND_GREEN_MASK        (0xFF00U)
#define LCDIF_CURSORBACKGROUND_GREEN_SHIFT       (8U)
/*! GREEN - Green value */
#define LCDIF_CURSORBACKGROUND_GREEN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_GREEN_SHIFT)) & LCDIF_CURSORBACKGROUND_GREEN_MASK)

#define LCDIF_CURSORBACKGROUND_RED_MASK          (0xFF0000U)
#define LCDIF_CURSORBACKGROUND_RED_SHIFT         (16U)
/*! RED - Red value */
#define LCDIF_CURSORBACKGROUND_RED(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_RED_SHIFT)) & LCDIF_CURSORBACKGROUND_RED_MASK)
/*! @} */

/*! @name CURSORFOREGROUND - Foreground Color for Masked Cursors */
/*! @{ */

#define LCDIF_CURSORFOREGROUND_BLUE_MASK         (0xFFU)
#define LCDIF_CURSORFOREGROUND_BLUE_SHIFT        (0U)
/*! BLUE - Blue value */
#define LCDIF_CURSORFOREGROUND_BLUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_BLUE_SHIFT)) & LCDIF_CURSORFOREGROUND_BLUE_MASK)

#define LCDIF_CURSORFOREGROUND_GREEN_MASK        (0xFF00U)
#define LCDIF_CURSORFOREGROUND_GREEN_SHIFT       (8U)
/*! GREEN - Green value */
#define LCDIF_CURSORFOREGROUND_GREEN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_GREEN_SHIFT)) & LCDIF_CURSORFOREGROUND_GREEN_MASK)

#define LCDIF_CURSORFOREGROUND_RED_MASK          (0xFF0000U)
#define LCDIF_CURSORFOREGROUND_RED_SHIFT         (16U)
/*! RED - Red value */
#define LCDIF_CURSORFOREGROUND_RED(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_RED_SHIFT)) & LCDIF_CURSORFOREGROUND_RED_MASK)
/*! @} */

/*! @name DISPLAYINTR - Display Interrupt */
/*! @{ */

#define LCDIF_DISPLAYINTR_DISP0_MASK             (0x1U)
#define LCDIF_DISPLAYINTR_DISP0_SHIFT            (0U)
/*! DISP0 - Display0 Interrupt */
#define LCDIF_DISPLAYINTR_DISP0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_DISP0_SHIFT)) & LCDIF_DISPLAYINTR_DISP0_MASK)
/*! @} */

/*! @name DISPLAYINTRENABLE - Interrupt Enable for Display_0 (and Display_1 if present) */
/*! @{ */

#define LCDIF_DISPLAYINTRENABLE_DISP0_MASK       (0x1U)
#define LCDIF_DISPLAYINTRENABLE_DISP0_SHIFT      (0U)
/*! DISP0 - Display0 Interrupt Enable */
#define LCDIF_DISPLAYINTRENABLE_DISP0(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_DISP0_SHIFT)) & LCDIF_DISPLAYINTRENABLE_DISP0_MASK)
/*! @} */

/*! @name DBICONFIG0 - DBI Configuration 0 */
/*! @{ */

#define LCDIF_DBICONFIG0_DBI_TYPE_MASK           (0x3U)
#define LCDIF_DBICONFIG0_DBI_TYPE_SHIFT          (0U)
/*! DBI_TYPE - DBI Type Select
 *  0b00..TYPE_AFIXED_E
 *  0b01..TYPE_ACLOCK_E
 *  0b10..TYPE_B
 *  0b11..TYPE_C
 */
#define LCDIF_DBICONFIG0_DBI_TYPE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_TYPE_SHIFT)) & LCDIF_DBICONFIG0_DBI_TYPE_MASK)

#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT_MASK    (0x3CU)
#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT_SHIFT   (2U)
/*! DBI_DATA_FORMAT - DBI Interface Data Format. */
#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_DATA_FORMAT_SHIFT)) & LCDIF_DBICONFIG0_DBI_DATA_FORMAT_MASK)

#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_MASK     (0x40U)
#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_SHIFT    (6U)
/*! BUS_OUTPUT_SEL - Output Bus Select
 *  0b0..DPI
 *  0b1..DBI
 */
#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_SHIFT)) & LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_MASK)

#define LCDIF_DBICONFIG0_DBIX_POLARITY_MASK      (0x80U)
#define LCDIF_DBICONFIG0_DBIX_POLARITY_SHIFT     (7U)
/*! DBIX_POLARITY - D/CX Pin polarity.
 *  0b0..Default
 *  0b1..Reverse
 */
#define LCDIF_DBICONFIG0_DBIX_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBIX_POLARITY_SHIFT)) & LCDIF_DBICONFIG0_DBIX_POLARITY_MASK)

#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_MASK   (0xF00U)
#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_SHIFT  (8U)
/*! DBI_AC_TIME_UNIT - Time Unit for AC Characteristics */
#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_SHIFT)) & LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_MASK)
/*! @} */

/*! @name DBIIFRESET0 - Reset DBI Interface to Idle State */
/*! @{ */

#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_MASK (0x1U)
#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_SHIFT (0U)
/*! DBI_IF_LEVEL_RESET - Reset DBI interface to idle state 1=RESET; */
#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_SHIFT)) & LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_MASK)
/*! @} */

/*! @name DBIWRCHAR10 - DBI Write Characteristics 1 */
/*! @{ */

#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_MASK     (0xFFU)
#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_SHIFT    (0U)
/*! DBI_WR_PERIOD - Single Write Period Duration */
#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_MASK)

#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_MASK (0xF00U)
#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_SHIFT (8U)
/*! DBI_WR_EOR_WR_ASSERT - Cycle number=Setting*(DbiAcTimeUnit+1). */
#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_MASK)

#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_MASK  (0xF000U)
#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_SHIFT (12U)
/*! DBI_WR_CS_ASSERT - Cycle number=Setting*(DbiAcTimeUnit+1). */
#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_MASK)
/*! @} */

/*! @name DBIWRCHAR20 - DBI Write Characteristics 2 */
/*! @{ */

#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_MASK (0xFFU)
#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_SHIFT (0U)
/*! DBI_WR_EOR_WR_DE_ASRT - Cycle number=Setting*(DbiAcTimeUnit+1). */
#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_SHIFT)) & LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_MASK)

#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_MASK (0xFF00U)
#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_SHIFT (8U)
/*! DBI_WR_CS_DE_ASRT - Cycle number=Setting*(DbiAcTimeUnit+1). */
#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_SHIFT)) & LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_MASK)
/*! @} */

/*! @name DBICMD0 - DBI Command In/Out Port */
/*! @{ */

#define LCDIF_DBICMD0_DBI_COMMAND_WORD_MASK      (0xFFFFU)
#define LCDIF_DBICMD0_DBI_COMMAND_WORD_SHIFT     (0U)
/*! DBI_COMMAND_WORD - DBI Command Word */
#define LCDIF_DBICMD0_DBI_COMMAND_WORD(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICMD0_DBI_COMMAND_WORD_SHIFT)) & LCDIF_DBICMD0_DBI_COMMAND_WORD_MASK)

#define LCDIF_DBICMD0_DBI_COMMANDFLAG_MASK       (0xC0000000U)
#define LCDIF_DBICMD0_DBI_COMMANDFLAG_SHIFT      (30U)
/*! DBI_COMMANDFLAG - DBI Command Flag
 *  0b00..ADDRESS
 *  0b01..WRITE_MEM_START
 *  0b10..PARAMETER_OR_DATA
 *  0b11..READ
 */
#define LCDIF_DBICMD0_DBI_COMMANDFLAG(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICMD0_DBI_COMMANDFLAG_SHIFT)) & LCDIF_DBICMD0_DBI_COMMANDFLAG_MASK)
/*! @} */

/*! @name DPICONFIG0 - DPI Configuration 0 */
/*! @{ */

#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT_MASK    (0x7U)
#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT_SHIFT   (0U)
/*! DPI_DATA_FORMAT - DPI Interface Data Format
 *  0b000..D16CFG1
 *  0b001..D16CFG2
 *  0b010..D16CFG3
 *  0b011..D18CFG1
 *  0b100..D18CFG2
 *  0b101..D24
 *  0b110-0b111..-
 */
#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DPICONFIG0_DPI_DATA_FORMAT_SHIFT)) & LCDIF_DPICONFIG0_DPI_DATA_FORMAT_MASK)
/*! @} */

/*! @name DCCHIPREV - Revision for the LCDIF Peripheral in BCD */
/*! @{ */

#define LCDIF_DCCHIPREV_REV_MASK                 (0xFFFFFFFFU)
#define LCDIF_DCCHIPREV_REV_SHIFT                (0U)
/*! REV - Revision */
#define LCDIF_DCCHIPREV_REV(x)                   (((uint32_t)(((uint32_t)(x)) << LCDIF_DCCHIPREV_REV_SHIFT)) & LCDIF_DCCHIPREV_REV_MASK)
/*! @} */

/*! @name DCCHIPDATE - Shows the release date for the IP in YYYYMMDD (year, month) */
/*! @{ */

#define LCDIF_DCCHIPDATE_DATE_MASK               (0xFFFFFFFFU)
#define LCDIF_DCCHIPDATE_DATE_SHIFT              (0U)
/*! DATE - Date */
#define LCDIF_DCCHIPDATE_DATE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_DCCHIPDATE_DATE_SHIFT)) & LCDIF_DCCHIPDATE_DATE_MASK)
/*! @} */

/*! @name DCCHIPPATCHREV - Patch Revision */
/*! @{ */

#define LCDIF_DCCHIPPATCHREV_PATCH_REV_MASK      (0xFFFFFFFFU)
#define LCDIF_DCCHIPPATCHREV_PATCH_REV_SHIFT     (0U)
/*! PATCH_REV - Patch Revision */
#define LCDIF_DCCHIPPATCHREV_PATCH_REV(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCCHIPPATCHREV_PATCH_REV_SHIFT)) & LCDIF_DCCHIPPATCHREV_PATCH_REV_MASK)
/*! @} */

/*! @name DCTILEINCFG0 - Tile Input Configuration */
/*! @{ */

#define LCDIF_DCTILEINCFG0_TILE_FORMAT_MASK      (0x3U)
#define LCDIF_DCTILEINCFG0_TILE_FORMAT_SHIFT     (0U)
/*! TILE_FORMAT - Tile Format */
#define LCDIF_DCTILEINCFG0_TILE_FORMAT(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_TILE_FORMAT_SHIFT)) & LCDIF_DCTILEINCFG0_TILE_FORMAT_MASK)

#define LCDIF_DCTILEINCFG0_YUV_STANDARD_MASK     (0xCU)
#define LCDIF_DCTILEINCFG0_YUV_STANDARD_SHIFT    (2U)
/*! YUV_STANDARD - YUV Standard Select
 *  0b00..BT601
 *  0b01..BT709
 */
#define LCDIF_DCTILEINCFG0_YUV_STANDARD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_YUV_STANDARD_SHIFT)) & LCDIF_DCTILEINCFG0_YUV_STANDARD_MASK)

#define LCDIF_DCTILEINCFG0_YUV2_RGB_EN_MASK      (0x10U)
#define LCDIF_DCTILEINCFG0_YUV2_RGB_EN_SHIFT     (4U)
/*! YUV2_RGB_EN - YUV2RGB Module Enable
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_DCTILEINCFG0_YUV2_RGB_EN(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_YUV2_RGB_EN_SHIFT)) & LCDIF_DCTILEINCFG0_YUV2_RGB_EN_MASK)

#define LCDIF_DCTILEINCFG0_CFG_MODE_EN_MASK      (0x20U)
#define LCDIF_DCTILEINCFG0_CFG_MODE_EN_SHIFT     (5U)
/*! CFG_MODE_EN - Configuration Mode Enable.
 *  0b0..Disabled
 *  0b1..Enabled
 */
#define LCDIF_DCTILEINCFG0_CFG_MODE_EN(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_CFG_MODE_EN_SHIFT)) & LCDIF_DCTILEINCFG0_CFG_MODE_EN_MASK)
/*! @} */

/*! @name DCTILEUVFRAMEBUFFERADR0 - UV Frame Buffer Address when Tile Input */
/*! @{ */

#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_MASK (0xFFFFFFFFU)
#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_SHIFT (0U)
/*! ADDRESS - UV Frame Buffer Address when Tile Input */
#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_SHIFT)) & LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_MASK)
/*! @} */

/*! @name DCTILEUVFRAMEBUFFERSTR0 - UV Frame Buffer Stride when Tile Input */
/*! @{ */

#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_MASK (0xFFFFU)
#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_SHIFT (0U)
/*! STRIDE - UV Frame Buffer Stride when Tile Input */
#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_SHIFT)) & LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_MASK)
/*! @} */

/*! @name DCPRODUCTID - Product ID */
/*! @{ */

#define LCDIF_DCPRODUCTID_PRODUCT_ID_MASK        (0xFFFFFFFFU)
#define LCDIF_DCPRODUCTID_PRODUCT_ID_SHIFT       (0U)
/*! PRODUCT_ID - Product ID */
#define LCDIF_DCPRODUCTID_PRODUCT_ID(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_DCPRODUCTID_PRODUCT_ID_SHIFT)) & LCDIF_DCPRODUCTID_PRODUCT_ID_MASK)
/*! @} */

/*! @name DEBUGCOUNTERSELECT0 - Debug Counter Select */
/*! @{ */

#define LCDIF_DEBUGCOUNTERSELECT0_SELECT_MASK    (0xFFU)
#define LCDIF_DEBUGCOUNTERSELECT0_SELECT_SHIFT   (0U)
/*! SELECT - Select */
#define LCDIF_DEBUGCOUNTERSELECT0_SELECT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DEBUGCOUNTERSELECT0_SELECT_SHIFT)) & LCDIF_DEBUGCOUNTERSELECT0_SELECT_MASK)
/*! @} */

/*! @name DEBUGCOUNTERVALUE0 - Debug Counter Value */
/*! @{ */

#define LCDIF_DEBUGCOUNTERVALUE0_VALUE_MASK      (0xFFFFFFFFU)
#define LCDIF_DEBUGCOUNTERVALUE0_VALUE_SHIFT     (0U)
/*! VALUE - Selected Debug Counter Value */
#define LCDIF_DEBUGCOUNTERVALUE0_VALUE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DEBUGCOUNTERVALUE0_VALUE_SHIFT)) & LCDIF_DEBUGCOUNTERVALUE0_VALUE_MASK)
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
#elif defined(__XTENSA__)
  /* leave anonymous unions enabled */
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


#endif  /* PERI_LCDIF_H_ */

