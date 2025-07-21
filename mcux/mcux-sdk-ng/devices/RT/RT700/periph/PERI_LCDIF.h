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
 * @file PERI_LCDIF.h
 * @version 3.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCDIF
 *
 * CMSIS Peripheral Access Layer for LCDIF
 */

#if !defined(PERI_LCDIF_H_)
#define PERI_LCDIF_H_                            /**< Symbol preventing repeated inclusion */

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
   -- LCDIF Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Peripheral_Access_Layer LCDIF Peripheral Access Layer
 * @{
 */

/** LCDIF - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8228];
  __IO uint32_t FRAMEBUFFERCONFIG0;                /**< Frame Buffer Configuration, offset: 0x2024 */
  __IO uint32_t FRAMEBUFFERADDRESS0;               /**< Frame Buffer Base Address, offset: 0x2028 */
  __IO uint32_t FRAMEBUFFERSTRIDE0;                /**< Frame Buffer Stride, offset: 0x202C */
       uint8_t RESERVED_1[4];
  __IO uint32_t DCTILEINCFG0;                      /**< Tile Input Configuration, offset: 0x2034 */
  __IO uint32_t DCTILEUVFRAMEBUFFERADR0;           /**< Frame Buffer Tiled UV Base Address, offset: 0x2038 */
  __IO uint32_t DCTILEUVFRAMEBUFFERSTR0;           /**< Frame Buffer Tiled UV Stride, offset: 0x203C */
       uint8_t RESERVED_2[24];
  __IO uint32_t FRAMEBUFFERBACKGROUND;             /**< Frame Buffer Background, offset: 0x2058 */
  __IO uint32_t FRAMEBUFFERCOLORKEY;               /**< Frame Buffer Color Keying Start Address, offset: 0x205C */
  __IO uint32_t FRAMEBUFFERCOLORKEYHIGH;           /**< Frame Buffer Color Key End Address, offset: 0x2060 */
  __IO uint32_t FRAMEBUFFERCLEARVALUE;             /**< Frame Buffer Clear Value, offset: 0x2064 */
  __IO uint32_t VIDEOTL;                           /**< Video Top Left Coordinate, offset: 0x2068 */
  __IO uint32_t FRAMEBUFFERSIZE;                   /**< Frame Buffer Size, offset: 0x206C */
  __IO uint32_t VIDEOGLOBALALPHA;                  /**< Video Global Alpha, offset: 0x2070 */
  __IO uint32_t BLENDSTACKORDER;                   /**< Blend Stack Order, offset: 0x2074 */
  __IO uint32_t VIDEOALPHABLENDCONFIG;             /**< Alpha Blending Configuration, offset: 0x2078 */
  __IO uint32_t OVERLAYCONFIG;                     /**< Overlay Configuration, offset: 0x207C */
  __IO uint32_t OVERLAYADDRESS;                    /**< Overlay Address, offset: 0x2080 */
  __IO uint32_t OVERLAYSTRIDE;                     /**< Overlay Stride, offset: 0x2084 */
  __IO uint32_t DCOVERLAYTILEINCFG;                /**< Tile Input Configuration, offset: 0x2088 */
  __IO uint32_t DCTILEUVOVERLAYADR;                /**< Tile Uv Overlay Address, offset: 0x208C */
  __IO uint32_t DCTILEUVOVERLAYSTR;                /**< Tile Uv Overlay Stride, offset: 0x2090 */
  __IO uint32_t OVERLAYTL;                         /**< Overlay Top Left, offset: 0x2094 */
  __IO uint32_t OVERLAYSIZE;                       /**< Overlay Size, offset: 0x2098 */
  __IO uint32_t OVERLAYCOLORKEY;                   /**< Overlay Color Keying Start Address, offset: 0x209C */
  __IO uint32_t OVERLAYCOLORKEYHIGH;               /**< Overlay Color Keying End Address, offset: 0x20A0 */
  __IO uint32_t OVERLAYALPHABLENDCONFIG;           /**< Overlay Alpha Blending Configuration, offset: 0x20A4 */
  __IO uint32_t OVERLAYGLOBALALPHA;                /**< Overlay Global Alpha, offset: 0x20A8 */
  __IO uint32_t OVERLAYCLEARVALUE;                 /**< Overlay Clear Value, offset: 0x20AC */
  __IO uint32_t OVERLAYCONFIG1;                    /**< Overlay Layer 1 Configuration, offset: 0x20B0 */
  __IO uint32_t OVERLAYADDRESS1;                   /**< Overlay Layer 1 Address, offset: 0x20B4 */
  __IO uint32_t OVERLAYSTRIDE1;                    /**< Overlay Layer 1 Stride, offset: 0x20B8 */
  __IO uint32_t OVERLAYTL1;                        /**< Overlay Layer 1 Top Left, offset: 0x20BC */
  __IO uint32_t OVERLAYSIZE1;                      /**< Overlay Layer 1 Size, offset: 0x20C0 */
  __IO uint32_t OVERLAYCOLORKEY1;                  /**< Overlay Layer 1 Color Keying Start Address, offset: 0x20C4 */
  __IO uint32_t OVERLAYCOLORKEYHIGH1;              /**< Overlay Layer 1 Color Keying End Address, offset: 0x20C8 */
  __IO uint32_t OVERLAYALPHABLENDCONFIG1;          /**< Overlay Layer 1 Alpha Blending Configuration, offset: 0x20CC */
  __IO uint32_t OVERLAYGLOBALALPHA1;               /**< Overlay Layer 1 Global Alpha, offset: 0x20D0 */
  __IO uint32_t OVERLAYCLEARVALUE1;                /**< Overlay Layer 1 Clear Value, offset: 0x20D4 */
       uint8_t RESERVED_3[8];
  __IO uint32_t DISPLAYDITHERTABLELOW0;            /**< Dither Lookup Table Low Threshold, offset: 0x20E0 */
  __IO uint32_t DISPLAYDITHERTABLEHIGH0;           /**< Dither Lookup Table High Threshold, offset: 0x20E4 */
  __IO uint32_t PANELCONFIG0;                      /**< Panel Configuration, offset: 0x20E8 */
  __IO uint32_t PANELCONTROL;                      /**< Panel Control, offset: 0x20EC */
  __IO uint32_t PANELFUNCTION;                     /**< Panel Function, offset: 0x20F0 */
  __O  uint32_t PANELWORKING;                      /**< Panel Working, offset: 0x20F4 */
  __I  uint32_t PANELSTATE;                        /**< Panel State, offset: 0x20F8 */
       uint8_t RESERVED_4[4];
  __IO uint32_t HDISPLAY0;                         /**< Horizontal Display Total and Visible Pixel Count, offset: 0x2100 */
  __IO uint32_t HSYNC0;                            /**< Horizontal Sync Counter, offset: 0x2104 */
       uint8_t RESERVED_5[8];
  __IO uint32_t VDISPLAY0;                         /**< Vertical Total and Visible Pixel Count, offset: 0x2110 */
  __IO uint32_t VSYNC0;                            /**< Vertical Sync Counter, offset: 0x2114 */
  __I  uint32_t DISPLAYCURRENTLOCATION0;           /**< Display Current Location, offset: 0x2118 */
  __O  uint32_t GAMMAINDEX0;                       /**< Gamma Index, offset: 0x211C */
  __O  uint32_t GAMMADATA0;                        /**< Gamma Data, offset: 0x2120 */
  __IO uint32_t CURSORCONFIG;                      /**< Cursor Configuration, offset: 0x2124 */
  __IO uint32_t CURSORADDRESS;                     /**< Cursor Base Address, offset: 0x2128 */
  __IO uint32_t CURSORLOCATION;                    /**< Cursor Location, offset: 0x212C */
  __IO uint32_t CURSORBACKGROUND;                  /**< Cursor Background Color, offset: 0x2130 */
  __IO uint32_t CURSORFOREGROUND;                  /**< Cursor Foreground Color, offset: 0x2134 */
  __I  uint32_t DISPLAYINTR;                       /**< Display Interrupt, offset: 0x2138 */
  __IO uint32_t DISPLAYINTRENABLE;                 /**< Display Interrupt Enable, offset: 0x213C */
  __IO uint32_t DBICONFIG0;                        /**< DBI Configuration, offset: 0x2140 */
  __O  uint32_t DBIIFRESET0;                       /**< DBI Interface Reset, offset: 0x2144 */
  __IO uint32_t DBIWRCHAR10;                       /**< DBI Write AC Characteristics 1, offset: 0x2148 */
  __IO uint32_t DBIWRCHAR20;                       /**< DBI Write AC Characteristics 2, offset: 0x214C */
  __O  uint32_t DBICMD0;                           /**< DBI Command Control, offset: 0x2150 */
  __IO uint32_t DPICONFIG0;                        /**< DPI Configuration, offset: 0x2154 */
       uint8_t RESERVED_6[8];
  __IO uint32_t SRCCONFIGENDIAN;                   /**< Source Endian Configuration, offset: 0x2160 */
  __O  uint32_t SOFTRESET;                         /**< Soft Reset, offset: 0x2164 */
  __IO uint32_t DCCONTROL;                         /**< Display Controller Control, offset: 0x2168 */
       uint8_t RESERVED_7[52];
  __IO uint32_t LAYERCLOCKGATE;                    /**< Layer Clock Gating, offset: 0x21A0 */
} LCDIF_Type;

/* ----------------------------------------------------------------------------
   -- LCDIF Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCDIF_Register_Masks LCDIF Register Masks
 * @{
 */

/*! @name FRAMEBUFFERCONFIG0 - Frame Buffer Configuration */
/*! @{ */

#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT_MASK     (0x7U)
#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT_SHIFT    (0U)
/*! FORMAT - Frame Buffer Format
 *  0b000..None; no frame buffer exists and LCDIF does not produce any output
 *  0b001..A4R4G4B4
 *  0b010..A1R5G5B5
 *  0b011..R5G6B5
 *  0b100..A8R8G8B8
 *  0b101..R8G8B8
 *  0b110..A8R5G6B5
 */
#define LCDIF_FRAMEBUFFERCONFIG0_FORMAT(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_FORMAT_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_FORMAT_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_ENABLE_MASK     (0x8U)
#define LCDIF_FRAMEBUFFERCONFIG0_ENABLE_SHIFT    (3U)
/*! ENABLE - Enable Layer
 *  0b0..Disable
 *  0b1..Enable
 */
#define LCDIF_FRAMEBUFFERCONFIG0_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_ENABLE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_ENABLE_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_CLEAR_EN_MASK   (0x20U)
#define LCDIF_FRAMEBUFFERCONFIG0_CLEAR_EN_SHIFT  (5U)
/*! CLEAR_EN - Enable Clear
 *  0b0..Disable
 *  0b1..Enable
 */
#define LCDIF_FRAMEBUFFERCONFIG0_CLEAR_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_CLEAR_EN_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_CLEAR_EN_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_COLOR_KEY_EN_MASK (0x400U)
#define LCDIF_FRAMEBUFFERCONFIG0_COLOR_KEY_EN_SHIFT (10U)
/*! COLOR_KEY_EN - Enable Color Keying
 *  0b0..Disable
 *  0b1..Enable
 */
#define LCDIF_FRAMEBUFFERCONFIG0_COLOR_KEY_EN(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_COLOR_KEY_EN_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_COLOR_KEY_EN_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_SWIZZLE_MASK    (0x60000U)
#define LCDIF_FRAMEBUFFERCONFIG0_SWIZZLE_SHIFT   (17U)
/*! SWIZZLE - Swizzle for RGB
 *  0b00..ARGB
 *  0b01..RGBA
 *  0b10..ABGR
 *  0b11..BGRA
 */
#define LCDIF_FRAMEBUFFERCONFIG0_SWIZZLE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_SWIZZLE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_SWIZZLE_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_UV_SWIZZLE_MASK (0x80000U)
#define LCDIF_FRAMEBUFFERCONFIG0_UV_SWIZZLE_SHIFT (19U)
/*! UV_SWIZZLE - Swizzle for UV */
#define LCDIF_FRAMEBUFFERCONFIG0_UV_SWIZZLE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_UV_SWIZZLE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_UV_SWIZZLE_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_DEC_MODE_MASK   (0xE00000U)
#define LCDIF_FRAMEBUFFERCONFIG0_DEC_MODE_SHIFT  (21U)
/*! DEC_MODE - Decompression Mode
 *  0b000..Decompression disabled
 *  0b001..Non-Subsample
 *  0b010..Horizontal Subsample
 *  0b011..Horizontal and Vertical Subsample
 *  0b100..ETC2
 */
#define LCDIF_FRAMEBUFFERCONFIG0_DEC_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_DEC_MODE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_DEC_MODE_MASK)

#define LCDIF_FRAMEBUFFERCONFIG0_ROT_ANGLE_MASK  (0x7000000U)
#define LCDIF_FRAMEBUFFERCONFIG0_ROT_ANGLE_SHIFT (24U)
/*! ROT_ANGLE - Rotation Angle
 *  0b000..Sets the rotation angle to 0 degree.
 *  0b010..Sets the rotation angle to 180 degree.
 *  0b100..Flips horizontal
 *  0b101..Flips vertical
 */
#define LCDIF_FRAMEBUFFERCONFIG0_ROT_ANGLE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCONFIG0_ROT_ANGLE_SHIFT)) & LCDIF_FRAMEBUFFERCONFIG0_ROT_ANGLE_MASK)
/*! @} */

/*! @name FRAMEBUFFERADDRESS0 - Frame Buffer Base Address */
/*! @{ */

#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_MASK   (0xFFFFFFFFU)
#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_SHIFT  (0U)
/*! ADDRESS - Starting Address */
#define LCDIF_FRAMEBUFFERADDRESS0_ADDRESS(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_SHIFT)) & LCDIF_FRAMEBUFFERADDRESS0_ADDRESS_MASK)
/*! @} */

/*! @name FRAMEBUFFERSTRIDE0 - Frame Buffer Stride */
/*! @{ */

#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_MASK     (0x1FFFFU)
#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_SHIFT    (0U)
/*! STRIDE - Frame Buffer Stride */
#define LCDIF_FRAMEBUFFERSTRIDE0_STRIDE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_SHIFT)) & LCDIF_FRAMEBUFFERSTRIDE0_STRIDE_MASK)
/*! @} */

/*! @name DCTILEINCFG0 - Tile Input Configuration */
/*! @{ */

#define LCDIF_DCTILEINCFG0_TILE_FORMAT_MASK      (0x3U)
#define LCDIF_DCTILEINCFG0_TILE_FORMAT_SHIFT     (0U)
/*! TILE_FORMAT - Tile Input Format
 *  0b00..No tile input. See DcTileInCfg0[TILE_FORMAT1].
 *  0b01..ARGB8888
 *  0b10..YUY2
 *  0b11..NV12
 */
#define LCDIF_DCTILEINCFG0_TILE_FORMAT(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_TILE_FORMAT_SHIFT)) & LCDIF_DCTILEINCFG0_TILE_FORMAT_MASK)

#define LCDIF_DCTILEINCFG0_YUV_STANDARD_MASK     (0x4U)
#define LCDIF_DCTILEINCFG0_YUV_STANDARD_SHIFT    (2U)
/*! YUV_STANDARD - YUV Standard
 *  0b0..BT601
 *  0b1..BT709
 */
#define LCDIF_DCTILEINCFG0_YUV_STANDARD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_YUV_STANDARD_SHIFT)) & LCDIF_DCTILEINCFG0_YUV_STANDARD_MASK)

#define LCDIF_DCTILEINCFG0_TILE_FORMAT1_MASK     (0x18U)
#define LCDIF_DCTILEINCFG0_TILE_FORMAT1_SHIFT    (3U)
/*! TILE_FORMAT1 - Tile Format 1 */
#define LCDIF_DCTILEINCFG0_TILE_FORMAT1(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEINCFG0_TILE_FORMAT1_SHIFT)) & LCDIF_DCTILEINCFG0_TILE_FORMAT1_MASK)
/*! @} */

/*! @name DCTILEUVFRAMEBUFFERADR0 - Frame Buffer Tiled UV Base Address */
/*! @{ */

#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_MASK (0xFFFFFFFFU)
#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_SHIFT (0U)
/*! ADDRESS - Base Address */
#define LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_SHIFT)) & LCDIF_DCTILEUVFRAMEBUFFERADR0_ADDRESS_MASK)
/*! @} */

/*! @name DCTILEUVFRAMEBUFFERSTR0 - Frame Buffer Tiled UV Stride */
/*! @{ */

#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_MASK (0xFFFFU)
#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_SHIFT (0U)
/*! STRIDE - Stride */
#define LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_SHIFT)) & LCDIF_DCTILEUVFRAMEBUFFERSTR0_STRIDE_MASK)
/*! @} */

/*! @name FRAMEBUFFERBACKGROUND - Frame Buffer Background */
/*! @{ */

#define LCDIF_FRAMEBUFFERBACKGROUND_BLUE_MASK    (0xFFU)
#define LCDIF_FRAMEBUFFERBACKGROUND_BLUE_SHIFT   (0U)
/*! BLUE - Blue */
#define LCDIF_FRAMEBUFFERBACKGROUND_BLUE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERBACKGROUND_BLUE_SHIFT)) & LCDIF_FRAMEBUFFERBACKGROUND_BLUE_MASK)

#define LCDIF_FRAMEBUFFERBACKGROUND_GREEN_MASK   (0xFF00U)
#define LCDIF_FRAMEBUFFERBACKGROUND_GREEN_SHIFT  (8U)
/*! GREEN - Green */
#define LCDIF_FRAMEBUFFERBACKGROUND_GREEN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERBACKGROUND_GREEN_SHIFT)) & LCDIF_FRAMEBUFFERBACKGROUND_GREEN_MASK)

#define LCDIF_FRAMEBUFFERBACKGROUND_RED_MASK     (0xFF0000U)
#define LCDIF_FRAMEBUFFERBACKGROUND_RED_SHIFT    (16U)
/*! RED - Red */
#define LCDIF_FRAMEBUFFERBACKGROUND_RED(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERBACKGROUND_RED_SHIFT)) & LCDIF_FRAMEBUFFERBACKGROUND_RED_MASK)

#define LCDIF_FRAMEBUFFERBACKGROUND_ALPHA_MASK   (0xFF000000U)
#define LCDIF_FRAMEBUFFERBACKGROUND_ALPHA_SHIFT  (24U)
/*! ALPHA - Alpha */
#define LCDIF_FRAMEBUFFERBACKGROUND_ALPHA(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERBACKGROUND_ALPHA_SHIFT)) & LCDIF_FRAMEBUFFERBACKGROUND_ALPHA_MASK)
/*! @} */

/*! @name FRAMEBUFFERCOLORKEY - Frame Buffer Color Keying Start Address */
/*! @{ */

#define LCDIF_FRAMEBUFFERCOLORKEY_BLUE_MASK      (0xFFU)
#define LCDIF_FRAMEBUFFERCOLORKEY_BLUE_SHIFT     (0U)
/*! BLUE - Blue */
#define LCDIF_FRAMEBUFFERCOLORKEY_BLUE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEY_BLUE_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEY_BLUE_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEY_GREEN_MASK     (0xFF00U)
#define LCDIF_FRAMEBUFFERCOLORKEY_GREEN_SHIFT    (8U)
/*! GREEN - Green */
#define LCDIF_FRAMEBUFFERCOLORKEY_GREEN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEY_GREEN_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEY_GREEN_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEY_RED_MASK       (0xFF0000U)
#define LCDIF_FRAMEBUFFERCOLORKEY_RED_SHIFT      (16U)
/*! RED - Red */
#define LCDIF_FRAMEBUFFERCOLORKEY_RED(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEY_RED_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEY_RED_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEY_ALPHA_MASK     (0xFF000000U)
#define LCDIF_FRAMEBUFFERCOLORKEY_ALPHA_SHIFT    (24U)
/*! ALPHA - Alpha */
#define LCDIF_FRAMEBUFFERCOLORKEY_ALPHA(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEY_ALPHA_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEY_ALPHA_MASK)
/*! @} */

/*! @name FRAMEBUFFERCOLORKEYHIGH - Frame Buffer Color Key End Address */
/*! @{ */

#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_BLUE_MASK  (0xFFU)
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_BLUE_SHIFT (0U)
/*! BLUE - Blue */
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_BLUE(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEYHIGH_BLUE_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEYHIGH_BLUE_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_GREEN_MASK (0xFF00U)
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_GREEN_SHIFT (8U)
/*! GREEN - Green */
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_GREEN(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEYHIGH_GREEN_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEYHIGH_GREEN_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_RED_MASK   (0xFF0000U)
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_RED_SHIFT  (16U)
/*! RED - Red */
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_RED(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEYHIGH_RED_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEYHIGH_RED_MASK)

#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_ALPHA_MASK (0xFF000000U)
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_ALPHA_SHIFT (24U)
/*! ALPHA - Alpha */
#define LCDIF_FRAMEBUFFERCOLORKEYHIGH_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCOLORKEYHIGH_ALPHA_SHIFT)) & LCDIF_FRAMEBUFFERCOLORKEYHIGH_ALPHA_MASK)
/*! @} */

/*! @name FRAMEBUFFERCLEARVALUE - Frame Buffer Clear Value */
/*! @{ */

#define LCDIF_FRAMEBUFFERCLEARVALUE_BLUE_MASK    (0xFFU)
#define LCDIF_FRAMEBUFFERCLEARVALUE_BLUE_SHIFT   (0U)
/*! BLUE - Blue */
#define LCDIF_FRAMEBUFFERCLEARVALUE_BLUE(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCLEARVALUE_BLUE_SHIFT)) & LCDIF_FRAMEBUFFERCLEARVALUE_BLUE_MASK)

#define LCDIF_FRAMEBUFFERCLEARVALUE_GREEN_MASK   (0xFF00U)
#define LCDIF_FRAMEBUFFERCLEARVALUE_GREEN_SHIFT  (8U)
/*! GREEN - Green */
#define LCDIF_FRAMEBUFFERCLEARVALUE_GREEN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCLEARVALUE_GREEN_SHIFT)) & LCDIF_FRAMEBUFFERCLEARVALUE_GREEN_MASK)

#define LCDIF_FRAMEBUFFERCLEARVALUE_RED_MASK     (0xFF0000U)
#define LCDIF_FRAMEBUFFERCLEARVALUE_RED_SHIFT    (16U)
/*! RED - Red */
#define LCDIF_FRAMEBUFFERCLEARVALUE_RED(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCLEARVALUE_RED_SHIFT)) & LCDIF_FRAMEBUFFERCLEARVALUE_RED_MASK)

#define LCDIF_FRAMEBUFFERCLEARVALUE_ALPHA_MASK   (0xFF000000U)
#define LCDIF_FRAMEBUFFERCLEARVALUE_ALPHA_SHIFT  (24U)
/*! ALPHA - Alpha */
#define LCDIF_FRAMEBUFFERCLEARVALUE_ALPHA(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERCLEARVALUE_ALPHA_SHIFT)) & LCDIF_FRAMEBUFFERCLEARVALUE_ALPHA_MASK)
/*! @} */

/*! @name VIDEOTL - Video Top Left Coordinate */
/*! @{ */

#define LCDIF_VIDEOTL_X_MASK                     (0xFFFU)
#define LCDIF_VIDEOTL_X_SHIFT                    (0U)
/*! X - Left Boundary */
#define LCDIF_VIDEOTL_X(x)                       (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOTL_X_SHIFT)) & LCDIF_VIDEOTL_X_MASK)

#define LCDIF_VIDEOTL_Y_MASK                     (0xFFF0000U)
#define LCDIF_VIDEOTL_Y_SHIFT                    (16U)
/*! Y - Top Boundary */
#define LCDIF_VIDEOTL_Y(x)                       (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOTL_Y_SHIFT)) & LCDIF_VIDEOTL_Y_MASK)
/*! @} */

/*! @name FRAMEBUFFERSIZE - Frame Buffer Size */
/*! @{ */

#define LCDIF_FRAMEBUFFERSIZE_WIDTH_MASK         (0xFFFU)
#define LCDIF_FRAMEBUFFERSIZE_WIDTH_SHIFT        (0U)
/*! WIDTH - Video Width */
#define LCDIF_FRAMEBUFFERSIZE_WIDTH(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERSIZE_WIDTH_SHIFT)) & LCDIF_FRAMEBUFFERSIZE_WIDTH_MASK)

#define LCDIF_FRAMEBUFFERSIZE_HEIGHT_MASK        (0xFFF0000U)
#define LCDIF_FRAMEBUFFERSIZE_HEIGHT_SHIFT       (16U)
/*! HEIGHT - Video Height */
#define LCDIF_FRAMEBUFFERSIZE_HEIGHT(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_FRAMEBUFFERSIZE_HEIGHT_SHIFT)) & LCDIF_FRAMEBUFFERSIZE_HEIGHT_MASK)
/*! @} */

/*! @name VIDEOGLOBALALPHA - Video Global Alpha */
/*! @{ */

#define LCDIF_VIDEOGLOBALALPHA_SRC_ALPHA_MASK    (0xFFU)
#define LCDIF_VIDEOGLOBALALPHA_SRC_ALPHA_SHIFT   (0U)
/*! SRC_ALPHA - Source Alpha */
#define LCDIF_VIDEOGLOBALALPHA_SRC_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOGLOBALALPHA_SRC_ALPHA_SHIFT)) & LCDIF_VIDEOGLOBALALPHA_SRC_ALPHA_MASK)

#define LCDIF_VIDEOGLOBALALPHA_DST_ALPHA_MASK    (0xFF00U)
#define LCDIF_VIDEOGLOBALALPHA_DST_ALPHA_SHIFT   (8U)
/*! DST_ALPHA - Destination Alpha */
#define LCDIF_VIDEOGLOBALALPHA_DST_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOGLOBALALPHA_DST_ALPHA_SHIFT)) & LCDIF_VIDEOGLOBALALPHA_DST_ALPHA_MASK)
/*! @} */

/*! @name BLENDSTACKORDER - Blend Stack Order */
/*! @{ */

#define LCDIF_BLENDSTACKORDER_ORDER_MASK         (0x7U)
#define LCDIF_BLENDSTACKORDER_ORDER_SHIFT        (0U)
/*! ORDER - Stack Order
 *  0b000..In the order of VG, Overlay 0 and Overlay 1 layers.
 *  0b001..In the order of VG, Overlay 1 and Overlay 0 layers.
 *  0b010..In the order of Overlay 0, VG and Overlay 1 layers.
 *  0b011..In the order of Overlay 0, Overlay 1, and VG layers.
 *  0b100..In the order of Overlay 1, VG and Overlay 0 layers.
 *  0b101..In the order of Overlay 1, Overlay 0, and VG layers.
 */
#define LCDIF_BLENDSTACKORDER_ORDER(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_BLENDSTACKORDER_ORDER_SHIFT)) & LCDIF_BLENDSTACKORDER_ORDER_MASK)
/*! @} */

/*! @name VIDEOALPHABLENDCONFIG - Alpha Blending Configuration */
/*! @{ */

#define LCDIF_VIDEOALPHABLENDCONFIG_ALPHA_BLEND_MASK (0x1U)
#define LCDIF_VIDEOALPHABLENDCONFIG_ALPHA_BLEND_SHIFT (0U)
/*! ALPHA_BLEND - Alpha Blending
 *  0b0..Disables alpha blending for video.
 *  0b1..Enables alpha blending for video.
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_ALPHA_BLEND(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_ALPHA_BLEND_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_ALPHA_BLEND_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_MASK (0x2U)
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_SHIFT (1U)
/*! SRC_ALPHA_MODE - Source Alpha Mode
 *  0b0..Normal source alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_MASK (0x18U)
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_SHIFT (3U)
/*! SRC_GLOBAL_ALPHA_MODE - Source Global Alpha Mode
 *  0b00..Normal source alpha mode
 *  0b01..Global source alpha mode
 *  0b10..Scaled (by the global alpha value) source alpha mode
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_MASK (0xC0U)
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_SHIFT (6U)
/*! SRC_BLENDING_MODE - Source Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the source color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_SRC_BLENDING_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_MASK (0x100U)
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_SHIFT (8U)
/*! SRC_ALPHA_FACTOR - Source Alpha Factor
 *  0b0..Do not generate the blending factor.
 *  0b1..Generates the blending factor.
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_SRC_ALPHA_FACTOR_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_MASK (0x200U)
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_SHIFT (9U)
/*! DST_ALPHA_MODE - Destination Alpha Mode
 *  0b0..Normal destination alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! DST_GLOBAL_ALPHA_MODE - Destination Global Alpha Mode
 *  0b00..Normal destination alpha mode
 *  0b01..Global destination alpha mode
 *  0b10..Scaled (by the global alpha value) destination alpha mode
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_MASK (0x6000U)
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_SHIFT (13U)
/*! DST_BLENDING_MODE - Destination Alpha Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the destination color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_DST_BLENDING_MODE_MASK)

#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_MASK (0x8000U)
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_SHIFT (15U)
/*! DST_ALPHA_FACTOR - Destination Alpha Factor
 *  0b0..Do not generate the blending factor for destination alpha.
 *  0b1..Generates the blending factor for destination alpha.
 */
#define LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_SHIFT)) & LCDIF_VIDEOALPHABLENDCONFIG_DST_ALPHA_FACTOR_MASK)
/*! @} */

/*! @name OVERLAYCONFIG - Overlay Configuration */
/*! @{ */

#define LCDIF_OVERLAYCONFIG_FORMAT_MASK          (0x7U)
#define LCDIF_OVERLAYCONFIG_FORMAT_SHIFT         (0U)
/*! FORMAT - Overlay Format
 *  0b000..No overlay
 *  0b001..Overlay format is A4R4G4B4.
 *  0b010..Overlay format is A1R5G5B5.
 *  0b011..Overlay format is R5G6B5.
 *  0b100..Overlay format is A8R8G8B8.
 *  0b101..Overlay format is A8R5G6B5.
 */
#define LCDIF_OVERLAYCONFIG_FORMAT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_FORMAT_SHIFT)) & LCDIF_OVERLAYCONFIG_FORMAT_MASK)

#define LCDIF_OVERLAYCONFIG_ENABLE_MASK          (0x8U)
#define LCDIF_OVERLAYCONFIG_ENABLE_SHIFT         (3U)
/*! ENABLE - Enable
 *  0b0..Disables this overlay layer.
 *  0b1..Enables this overlay layer.
 */
#define LCDIF_OVERLAYCONFIG_ENABLE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_ENABLE_SHIFT)) & LCDIF_OVERLAYCONFIG_ENABLE_MASK)

#define LCDIF_OVERLAYCONFIG_CLEAR_EN_MASK        (0x20U)
#define LCDIF_OVERLAYCONFIG_CLEAR_EN_SHIFT       (5U)
/*! CLEAR_EN - Clear
 *  0b0..Disables clearing the overlay layer.
 *  0b1..Enables clearing the overlay layer.
 */
#define LCDIF_OVERLAYCONFIG_CLEAR_EN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_CLEAR_EN_SHIFT)) & LCDIF_OVERLAYCONFIG_CLEAR_EN_MASK)

#define LCDIF_OVERLAYCONFIG_SWIZZLE_MASK         (0x60000U)
#define LCDIF_OVERLAYCONFIG_SWIZZLE_SHIFT        (17U)
/*! SWIZZLE - RGB Swizzle
 *  0b00..Input pixel in ARGB format
 *  0b01..Input pixel in RGBA format
 *  0b10..Input pixel in ABGR format
 *  0b11..Input pixel in BGRA format
 */
#define LCDIF_OVERLAYCONFIG_SWIZZLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_SWIZZLE_SHIFT)) & LCDIF_OVERLAYCONFIG_SWIZZLE_MASK)

#define LCDIF_OVERLAYCONFIG_UV_SWIZZLE_MASK      (0x80000U)
#define LCDIF_OVERLAYCONFIG_UV_SWIZZLE_SHIFT     (19U)
/*! UV_SWIZZLE - UV Swizzle */
#define LCDIF_OVERLAYCONFIG_UV_SWIZZLE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_UV_SWIZZLE_SHIFT)) & LCDIF_OVERLAYCONFIG_UV_SWIZZLE_MASK)

#define LCDIF_OVERLAYCONFIG_COLOR_KEY_EN_MASK    (0x100000U)
#define LCDIF_OVERLAYCONFIG_COLOR_KEY_EN_SHIFT   (20U)
/*! COLOR_KEY_EN - Color Keying
 *  0b0..Disables color keying.
 *  0b1..Enables color keying.
 */
#define LCDIF_OVERLAYCONFIG_COLOR_KEY_EN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_COLOR_KEY_EN_SHIFT)) & LCDIF_OVERLAYCONFIG_COLOR_KEY_EN_MASK)

#define LCDIF_OVERLAYCONFIG_DEC_MODE_MASK        (0xE00000U)
#define LCDIF_OVERLAYCONFIG_DEC_MODE_SHIFT       (21U)
/*! DEC_MODE - Decompression Mode
 *  0b000..Disables decompression.
 *  0b001..Non Subsample
 *  0b010..Horizontal Subsample
 *  0b011..Horizontal Vertical Subsample
 *  0b100..ETC2
 */
#define LCDIF_OVERLAYCONFIG_DEC_MODE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_DEC_MODE_SHIFT)) & LCDIF_OVERLAYCONFIG_DEC_MODE_MASK)

#define LCDIF_OVERLAYCONFIG_ROT_ANGLE_MASK       (0x7000000U)
#define LCDIF_OVERLAYCONFIG_ROT_ANGLE_SHIFT      (24U)
/*! ROT_ANGLE - Rotation Angle
 *  0b000..Sets the rotation angle to 0 degree.
 *  0b010..Sets the rotation angle to 180 degree.
 *  0b100..Flips horizontal
 *  0b101..Flips vertical
 */
#define LCDIF_OVERLAYCONFIG_ROT_ANGLE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG_ROT_ANGLE_SHIFT)) & LCDIF_OVERLAYCONFIG_ROT_ANGLE_MASK)
/*! @} */

/*! @name OVERLAYADDRESS - Overlay Address */
/*! @{ */

#define LCDIF_OVERLAYADDRESS_ADDRESS_MASK        (0xFFFFFFFFU)
#define LCDIF_OVERLAYADDRESS_ADDRESS_SHIFT       (0U)
/*! ADDRESS - Starting Address */
#define LCDIF_OVERLAYADDRESS_ADDRESS(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYADDRESS_ADDRESS_SHIFT)) & LCDIF_OVERLAYADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name OVERLAYSTRIDE - Overlay Stride */
/*! @{ */

#define LCDIF_OVERLAYSTRIDE_STRIDE_MASK          (0x1FFFFU)
#define LCDIF_OVERLAYSTRIDE_STRIDE_SHIFT         (0U)
/*! STRIDE - Stride */
#define LCDIF_OVERLAYSTRIDE_STRIDE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSTRIDE_STRIDE_SHIFT)) & LCDIF_OVERLAYSTRIDE_STRIDE_MASK)
/*! @} */

/*! @name DCOVERLAYTILEINCFG - Tile Input Configuration */
/*! @{ */

#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT_MASK (0x3U)
#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT_SHIFT (0U)
/*! TILE_FORMAT - Tile Input Format
 *  0b00..No tile input. See DcOverlayTileInCfg[TILE_FORMAT1].
 *  0b01..Sets the tile input format to ARGB8888.
 *  0b10..Sets the tile input format to YUY2.
 *  0b11..Sets the tile input format to NV12.
 */
#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT_SHIFT)) & LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT_MASK)

#define LCDIF_DCOVERLAYTILEINCFG_YUV_STANDARD_MASK (0x4U)
#define LCDIF_DCOVERLAYTILEINCFG_YUV_STANDARD_SHIFT (2U)
/*! YUV_STANDARD - YUV Standard
 *  0b0..Selects the YUV standard BT601.
 *  0b1..Selects the YUV standard BT709.
 */
#define LCDIF_DCOVERLAYTILEINCFG_YUV_STANDARD(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DCOVERLAYTILEINCFG_YUV_STANDARD_SHIFT)) & LCDIF_DCOVERLAYTILEINCFG_YUV_STANDARD_MASK)

#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT1_MASK (0x18U)
#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT1_SHIFT (3U)
/*! TILE_FORMAT1 - Tile Format 1 */
#define LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT1(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT1_SHIFT)) & LCDIF_DCOVERLAYTILEINCFG_TILE_FORMAT1_MASK)
/*! @} */

/*! @name DCTILEUVOVERLAYADR - Tile Uv Overlay Address */
/*! @{ */

#define LCDIF_DCTILEUVOVERLAYADR_ADDRESS_MASK    (0xFFFFFFFFU)
#define LCDIF_DCTILEUVOVERLAYADR_ADDRESS_SHIFT   (0U)
/*! ADDRESS - Starting Overlay Address */
#define LCDIF_DCTILEUVOVERLAYADR_ADDRESS(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVOVERLAYADR_ADDRESS_SHIFT)) & LCDIF_DCTILEUVOVERLAYADR_ADDRESS_MASK)
/*! @} */

/*! @name DCTILEUVOVERLAYSTR - Tile Uv Overlay Stride */
/*! @{ */

#define LCDIF_DCTILEUVOVERLAYSTR_STRIDE_MASK     (0xFFFFU)
#define LCDIF_DCTILEUVOVERLAYSTR_STRIDE_SHIFT    (0U)
/*! STRIDE - Overlay Stride */
#define LCDIF_DCTILEUVOVERLAYSTR_STRIDE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DCTILEUVOVERLAYSTR_STRIDE_SHIFT)) & LCDIF_DCTILEUVOVERLAYSTR_STRIDE_MASK)
/*! @} */

/*! @name OVERLAYTL - Overlay Top Left */
/*! @{ */

#define LCDIF_OVERLAYTL_X_MASK                   (0xFFFU)
#define LCDIF_OVERLAYTL_X_SHIFT                  (0U)
/*! X - Left Boundary */
#define LCDIF_OVERLAYTL_X(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYTL_X_SHIFT)) & LCDIF_OVERLAYTL_X_MASK)

#define LCDIF_OVERLAYTL_Y_MASK                   (0xFFF0000U)
#define LCDIF_OVERLAYTL_Y_SHIFT                  (16U)
/*! Y - Top Boundary */
#define LCDIF_OVERLAYTL_Y(x)                     (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYTL_Y_SHIFT)) & LCDIF_OVERLAYTL_Y_MASK)
/*! @} */

/*! @name OVERLAYSIZE - Overlay Size */
/*! @{ */

#define LCDIF_OVERLAYSIZE_WIDTH_MASK             (0xFFFU)
#define LCDIF_OVERLAYSIZE_WIDTH_SHIFT            (0U)
/*! WIDTH - Width */
#define LCDIF_OVERLAYSIZE_WIDTH(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSIZE_WIDTH_SHIFT)) & LCDIF_OVERLAYSIZE_WIDTH_MASK)

#define LCDIF_OVERLAYSIZE_HEIGHT_MASK            (0xFFF0000U)
#define LCDIF_OVERLAYSIZE_HEIGHT_SHIFT           (16U)
/*! HEIGHT - Height */
#define LCDIF_OVERLAYSIZE_HEIGHT(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSIZE_HEIGHT_SHIFT)) & LCDIF_OVERLAYSIZE_HEIGHT_MASK)
/*! @} */

/*! @name OVERLAYCOLORKEY - Overlay Color Keying Start Address */
/*! @{ */

#define LCDIF_OVERLAYCOLORKEY_BLUE_MASK          (0xFFU)
#define LCDIF_OVERLAYCOLORKEY_BLUE_SHIFT         (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCOLORKEY_BLUE(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY_BLUE_SHIFT)) & LCDIF_OVERLAYCOLORKEY_BLUE_MASK)

#define LCDIF_OVERLAYCOLORKEY_GREEN_MASK         (0xFF00U)
#define LCDIF_OVERLAYCOLORKEY_GREEN_SHIFT        (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCOLORKEY_GREEN(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY_GREEN_SHIFT)) & LCDIF_OVERLAYCOLORKEY_GREEN_MASK)

#define LCDIF_OVERLAYCOLORKEY_RED_MASK           (0xFF0000U)
#define LCDIF_OVERLAYCOLORKEY_RED_SHIFT          (16U)
/*! RED - Red */
#define LCDIF_OVERLAYCOLORKEY_RED(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY_RED_SHIFT)) & LCDIF_OVERLAYCOLORKEY_RED_MASK)

#define LCDIF_OVERLAYCOLORKEY_ALPHA_MASK         (0xFF000000U)
#define LCDIF_OVERLAYCOLORKEY_ALPHA_SHIFT        (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCOLORKEY_ALPHA(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY_ALPHA_SHIFT)) & LCDIF_OVERLAYCOLORKEY_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYCOLORKEYHIGH - Overlay Color Keying End Address */
/*! @{ */

#define LCDIF_OVERLAYCOLORKEYHIGH_BLUE_MASK      (0xFFU)
#define LCDIF_OVERLAYCOLORKEYHIGH_BLUE_SHIFT     (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCOLORKEYHIGH_BLUE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH_BLUE_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH_BLUE_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH_GREEN_MASK     (0xFF00U)
#define LCDIF_OVERLAYCOLORKEYHIGH_GREEN_SHIFT    (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCOLORKEYHIGH_GREEN(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH_GREEN_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH_GREEN_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH_RED_MASK       (0xFF0000U)
#define LCDIF_OVERLAYCOLORKEYHIGH_RED_SHIFT      (16U)
/*! RED - Red */
#define LCDIF_OVERLAYCOLORKEYHIGH_RED(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH_RED_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH_RED_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH_ALPHA_MASK     (0xFF000000U)
#define LCDIF_OVERLAYCOLORKEYHIGH_ALPHA_SHIFT    (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCOLORKEYHIGH_ALPHA(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH_ALPHA_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYALPHABLENDCONFIG - Overlay Alpha Blending Configuration */
/*! @{ */

#define LCDIF_OVERLAYALPHABLENDCONFIG_ALPHA_BLEND_MASK (0x1U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_ALPHA_BLEND_SHIFT (0U)
/*! ALPHA_BLEND - Alpha Blend
 *  0b0..Disables alpha blending for overlay.
 *  0b1..Enables alpha blending for overlay.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_ALPHA_BLEND(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_ALPHA_BLEND_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_ALPHA_BLEND_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_MASK (0x2U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_SHIFT (1U)
/*! SRC_ALPHA_MODE - Source Alpha Mode
 *  0b0..Normal alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_MASK (0x18U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_SHIFT (3U)
/*! SRC_GLOBAL_ALPHA_MODE - Source Global Alpha Mode
 *  0b00..Normal source alpha mode
 *  0b01..Global source alpha mode
 *  0b10..Scaled (by the global alpha value) source alpha mode
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_SRC_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_MASK (0xC0U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_SHIFT (6U)
/*! SRC_BLENDING_MODE - Source Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the source color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_SRC_BLENDING_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_MASK (0x100U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_SHIFT (8U)
/*! SRC_ALPHA_FACTOR - Source Alpha Factor
 *  0b0..Do not generate the blending factor.
 *  0b1..Generates the blending factor.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_SRC_ALPHA_FACTOR_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_MASK (0x200U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_SHIFT (9U)
/*! DST_ALPHA_MODE - Destination Alpha Mode
 *  0b0..Normal destination alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! DST_GLOBAL_ALPHA_MODE - Destination Global Alpha Mode
 *  0b00..Normal destination alpha mode
 *  0b01..Global destination alpha mode
 *  0b10..Scaled (by the global alpha value) destination alpha mode
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_DST_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_MASK (0x6000U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_SHIFT (13U)
/*! DST_BLENDING_MODE - Destination Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the destination color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_DST_BLENDING_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_MASK (0x8000U)
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_SHIFT (15U)
/*! DST_ALPHA_FACTOR - Destination Alpha Factor
 *  0b0..Do not generate the blending factor for destination alpha.
 *  0b1..Generates the blending factor for destination alpha.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG_DST_ALPHA_FACTOR_MASK)
/*! @} */

/*! @name OVERLAYGLOBALALPHA - Overlay Global Alpha */
/*! @{ */

#define LCDIF_OVERLAYGLOBALALPHA_SRC_ALPHA_MASK  (0xFFU)
#define LCDIF_OVERLAYGLOBALALPHA_SRC_ALPHA_SHIFT (0U)
/*! SRC_ALPHA - Source Alpha */
#define LCDIF_OVERLAYGLOBALALPHA_SRC_ALPHA(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYGLOBALALPHA_SRC_ALPHA_SHIFT)) & LCDIF_OVERLAYGLOBALALPHA_SRC_ALPHA_MASK)

#define LCDIF_OVERLAYGLOBALALPHA_DST_ALPHA_MASK  (0xFF00U)
#define LCDIF_OVERLAYGLOBALALPHA_DST_ALPHA_SHIFT (8U)
/*! DST_ALPHA - Destination Alpha */
#define LCDIF_OVERLAYGLOBALALPHA_DST_ALPHA(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYGLOBALALPHA_DST_ALPHA_SHIFT)) & LCDIF_OVERLAYGLOBALALPHA_DST_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYCLEARVALUE - Overlay Clear Value */
/*! @{ */

#define LCDIF_OVERLAYCLEARVALUE_BLUE_MASK        (0xFFU)
#define LCDIF_OVERLAYCLEARVALUE_BLUE_SHIFT       (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCLEARVALUE_BLUE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE_BLUE_SHIFT)) & LCDIF_OVERLAYCLEARVALUE_BLUE_MASK)

#define LCDIF_OVERLAYCLEARVALUE_GREEN_MASK       (0xFF00U)
#define LCDIF_OVERLAYCLEARVALUE_GREEN_SHIFT      (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCLEARVALUE_GREEN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE_GREEN_SHIFT)) & LCDIF_OVERLAYCLEARVALUE_GREEN_MASK)

#define LCDIF_OVERLAYCLEARVALUE_RED_MASK         (0xFF0000U)
#define LCDIF_OVERLAYCLEARVALUE_RED_SHIFT        (16U)
/*! RED - Red */
#define LCDIF_OVERLAYCLEARVALUE_RED(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE_RED_SHIFT)) & LCDIF_OVERLAYCLEARVALUE_RED_MASK)

#define LCDIF_OVERLAYCLEARVALUE_ALPHA_MASK       (0xFF000000U)
#define LCDIF_OVERLAYCLEARVALUE_ALPHA_SHIFT      (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCLEARVALUE_ALPHA(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE_ALPHA_SHIFT)) & LCDIF_OVERLAYCLEARVALUE_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYCONFIG1 - Overlay Layer 1 Configuration */
/*! @{ */

#define LCDIF_OVERLAYCONFIG1_FORMAT_MASK         (0x7U)
#define LCDIF_OVERLAYCONFIG1_FORMAT_SHIFT        (0U)
/*! FORMAT - Input Format
 *  0b000..No overlay
 *  0b001..Sets the input format to A4R4G4B4.
 *  0b010..Sets the input format to A1R5G5B5.
 *  0b011..Sets the input format to R5G6B5.
 *  0b100..Sets the input format to A8R8G8B8.
 *  0b101..Sets the input format to R8G8B8.
 *  0b110..Sets the input format to A8R5G6B5.
 */
#define LCDIF_OVERLAYCONFIG1_FORMAT(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_FORMAT_SHIFT)) & LCDIF_OVERLAYCONFIG1_FORMAT_MASK)

#define LCDIF_OVERLAYCONFIG1_ENABLE_MASK         (0x8U)
#define LCDIF_OVERLAYCONFIG1_ENABLE_SHIFT        (3U)
/*! ENABLE - Enable
 *  0b0..Disables the overlay layer 1.
 *  0b1..Enables the overlay layer 1.
 */
#define LCDIF_OVERLAYCONFIG1_ENABLE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_ENABLE_SHIFT)) & LCDIF_OVERLAYCONFIG1_ENABLE_MASK)

#define LCDIF_OVERLAYCONFIG1_CLEAR_EN_MASK       (0x20U)
#define LCDIF_OVERLAYCONFIG1_CLEAR_EN_SHIFT      (5U)
/*! CLEAR_EN - Enable Clear
 *  0b0..Disables clearing the overlay layer 1.
 *  0b1..Enables clearing the overlay layer 1.
 */
#define LCDIF_OVERLAYCONFIG1_CLEAR_EN(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_CLEAR_EN_SHIFT)) & LCDIF_OVERLAYCONFIG1_CLEAR_EN_MASK)

#define LCDIF_OVERLAYCONFIG1_SWIZZLE_MASK        (0x60000U)
#define LCDIF_OVERLAYCONFIG1_SWIZZLE_SHIFT       (17U)
/*! SWIZZLE - RGB Swizzle
 *  0b00..Input pixel in ARGB format order
 *  0b01..Input pixel in RGBA format order
 *  0b10..Input pixel in ABGR format order
 *  0b11..Input pixel in BGRA format order
 */
#define LCDIF_OVERLAYCONFIG1_SWIZZLE(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_SWIZZLE_SHIFT)) & LCDIF_OVERLAYCONFIG1_SWIZZLE_MASK)

#define LCDIF_OVERLAYCONFIG1_COLOR_KEY_EN_MASK   (0x100000U)
#define LCDIF_OVERLAYCONFIG1_COLOR_KEY_EN_SHIFT  (20U)
/*! COLOR_KEY_EN - Enable Color Keying
 *  0b0..Disables color keying.
 *  0b1..Enables color keying.
 */
#define LCDIF_OVERLAYCONFIG1_COLOR_KEY_EN(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_COLOR_KEY_EN_SHIFT)) & LCDIF_OVERLAYCONFIG1_COLOR_KEY_EN_MASK)

#define LCDIF_OVERLAYCONFIG1_DEC_MODE_MASK       (0xE00000U)
#define LCDIF_OVERLAYCONFIG1_DEC_MODE_SHIFT      (21U)
/*! DEC_MODE - Decompression Mode
 *  0b000..Disables decompression.
 *  0b001..Enables non_subsample decompression mode.
 *  0b010..Enables horizontal subsample decompression mode.
 *  0b011..Enables horizontal and vertical subsample decompression mode.
 *  0b100..Enables ETC2 decompression mode.
 */
#define LCDIF_OVERLAYCONFIG1_DEC_MODE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_DEC_MODE_SHIFT)) & LCDIF_OVERLAYCONFIG1_DEC_MODE_MASK)

#define LCDIF_OVERLAYCONFIG1_ROT_ANGLE_MASK      (0x7000000U)
#define LCDIF_OVERLAYCONFIG1_ROT_ANGLE_SHIFT     (24U)
/*! ROT_ANGLE - Rotation Angle
 *  0b000..Sets the rotation angle to 0 degree.
 *  0b010..Sets the rotation angle to 180 degree.
 *  0b100..Flips horizontal
 *  0b101..Flips vertical
 */
#define LCDIF_OVERLAYCONFIG1_ROT_ANGLE(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCONFIG1_ROT_ANGLE_SHIFT)) & LCDIF_OVERLAYCONFIG1_ROT_ANGLE_MASK)
/*! @} */

/*! @name OVERLAYADDRESS1 - Overlay Layer 1 Address */
/*! @{ */

#define LCDIF_OVERLAYADDRESS1_ADDRESS_MASK       (0xFFFFFFFFU)
#define LCDIF_OVERLAYADDRESS1_ADDRESS_SHIFT      (0U)
/*! ADDRESS - Start Address */
#define LCDIF_OVERLAYADDRESS1_ADDRESS(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYADDRESS1_ADDRESS_SHIFT)) & LCDIF_OVERLAYADDRESS1_ADDRESS_MASK)
/*! @} */

/*! @name OVERLAYSTRIDE1 - Overlay Layer 1 Stride */
/*! @{ */

#define LCDIF_OVERLAYSTRIDE1_STRIDE_MASK         (0x1FFFFU)
#define LCDIF_OVERLAYSTRIDE1_STRIDE_SHIFT        (0U)
/*! STRIDE - Stride of Overlay Layer 1 */
#define LCDIF_OVERLAYSTRIDE1_STRIDE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSTRIDE1_STRIDE_SHIFT)) & LCDIF_OVERLAYSTRIDE1_STRIDE_MASK)
/*! @} */

/*! @name OVERLAYTL1 - Overlay Layer 1 Top Left */
/*! @{ */

#define LCDIF_OVERLAYTL1_X_MASK                  (0xFFFU)
#define LCDIF_OVERLAYTL1_X_SHIFT                 (0U)
/*! X - Left Boundary */
#define LCDIF_OVERLAYTL1_X(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYTL1_X_SHIFT)) & LCDIF_OVERLAYTL1_X_MASK)

#define LCDIF_OVERLAYTL1_Y_MASK                  (0xFFF0000U)
#define LCDIF_OVERLAYTL1_Y_SHIFT                 (16U)
/*! Y - Top boundary */
#define LCDIF_OVERLAYTL1_Y(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYTL1_Y_SHIFT)) & LCDIF_OVERLAYTL1_Y_MASK)
/*! @} */

/*! @name OVERLAYSIZE1 - Overlay Layer 1 Size */
/*! @{ */

#define LCDIF_OVERLAYSIZE1_WIDTH_MASK            (0xFFFU)
#define LCDIF_OVERLAYSIZE1_WIDTH_SHIFT           (0U)
/*! WIDTH - Width */
#define LCDIF_OVERLAYSIZE1_WIDTH(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSIZE1_WIDTH_SHIFT)) & LCDIF_OVERLAYSIZE1_WIDTH_MASK)

#define LCDIF_OVERLAYSIZE1_HEIGHT_MASK           (0xFFF0000U)
#define LCDIF_OVERLAYSIZE1_HEIGHT_SHIFT          (16U)
/*! HEIGHT - Height */
#define LCDIF_OVERLAYSIZE1_HEIGHT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYSIZE1_HEIGHT_SHIFT)) & LCDIF_OVERLAYSIZE1_HEIGHT_MASK)
/*! @} */

/*! @name OVERLAYCOLORKEY1 - Overlay Layer 1 Color Keying Start Address */
/*! @{ */

#define LCDIF_OVERLAYCOLORKEY1_BLUE_MASK         (0xFFU)
#define LCDIF_OVERLAYCOLORKEY1_BLUE_SHIFT        (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCOLORKEY1_BLUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY1_BLUE_SHIFT)) & LCDIF_OVERLAYCOLORKEY1_BLUE_MASK)

#define LCDIF_OVERLAYCOLORKEY1_GREEN_MASK        (0xFF00U)
#define LCDIF_OVERLAYCOLORKEY1_GREEN_SHIFT       (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCOLORKEY1_GREEN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY1_GREEN_SHIFT)) & LCDIF_OVERLAYCOLORKEY1_GREEN_MASK)

#define LCDIF_OVERLAYCOLORKEY1_RED_MASK          (0xFF0000U)
#define LCDIF_OVERLAYCOLORKEY1_RED_SHIFT         (16U)
/*! RED - red */
#define LCDIF_OVERLAYCOLORKEY1_RED(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY1_RED_SHIFT)) & LCDIF_OVERLAYCOLORKEY1_RED_MASK)

#define LCDIF_OVERLAYCOLORKEY1_ALPHA_MASK        (0xFF000000U)
#define LCDIF_OVERLAYCOLORKEY1_ALPHA_SHIFT       (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCOLORKEY1_ALPHA(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEY1_ALPHA_SHIFT)) & LCDIF_OVERLAYCOLORKEY1_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYCOLORKEYHIGH1 - Overlay Layer 1 Color Keying End Address */
/*! @{ */

#define LCDIF_OVERLAYCOLORKEYHIGH1_BLUE_MASK     (0xFFU)
#define LCDIF_OVERLAYCOLORKEYHIGH1_BLUE_SHIFT    (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCOLORKEYHIGH1_BLUE(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH1_BLUE_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH1_BLUE_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH1_GREEN_MASK    (0xFF00U)
#define LCDIF_OVERLAYCOLORKEYHIGH1_GREEN_SHIFT   (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCOLORKEYHIGH1_GREEN(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH1_GREEN_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH1_GREEN_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH1_RED_MASK      (0xFF0000U)
#define LCDIF_OVERLAYCOLORKEYHIGH1_RED_SHIFT     (16U)
/*! RED - red */
#define LCDIF_OVERLAYCOLORKEYHIGH1_RED(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH1_RED_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH1_RED_MASK)

#define LCDIF_OVERLAYCOLORKEYHIGH1_ALPHA_MASK    (0xFF000000U)
#define LCDIF_OVERLAYCOLORKEYHIGH1_ALPHA_SHIFT   (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCOLORKEYHIGH1_ALPHA(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCOLORKEYHIGH1_ALPHA_SHIFT)) & LCDIF_OVERLAYCOLORKEYHIGH1_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYALPHABLENDCONFIG1 - Overlay Layer 1 Alpha Blending Configuration */
/*! @{ */

#define LCDIF_OVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_MASK (0x1U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_SHIFT (0U)
/*! ALPHA_BLEND - Alpha Blend
 *  0b0..Disables alpha blending for the overlay layer 1.
 *  0b1..Enables alpha blending for the overlay layer 1.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_ALPHA_BLEND(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_ALPHA_BLEND_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_MASK (0x2U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_SHIFT (1U)
/*! SRC_ALPHA_MODE - Source Alpha Mode
 *  0b0..Normal alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_MASK (0x18U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_SHIFT (3U)
/*! SRC_GLOBAL_ALPHA_MODE - Source Global Alpha Mode
 *  0b00..Normal source alpha mode
 *  0b01..Global source alpha mode
 *  0b10..Scaled (by the global alpha value) source alpha mode
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_MASK (0xC0U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_SHIFT (6U)
/*! SRC_BLENDING_MODE - Source Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the source color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_BLENDING_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_MASK (0x100U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_SHIFT (8U)
/*! SRC_ALPHA_FACTOR - Source Alpha Factor
 *  0b0..Do not generate the blending factor for source alpha for the overlay layer 1.
 *  0b1..Generates the blending factor for source alpha for the overlay layer 1.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_SRC_ALPHA_FACTOR_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_MASK (0x200U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_SHIFT (9U)
/*! DST_ALPHA_MODE - Destination Alpha Mode
 *  0b0..Normal alpha mode
 *  0b1..Inversed alpha mode if the internal alpha rule needs to be followed
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_MASK (0xC00U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_SHIFT (10U)
/*! DST_GLOBAL_ALPHA_MODE - Destination Global Alpha Mode
 *  0b00..Normal destination alpha mode
 *  0b01..Global destination alpha mode
 *  0b10..Scaled (by the global alpha value) destination alpha mode
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_DST_GLOBAL_ALPHA_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_MASK (0x6000U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_SHIFT (13U)
/*! DST_BLENDING_MODE - Destination Blending Mode
 *  0b00..Each component of the color is multiplied by (0, 0, 0,0).
 *  0b01..Each component of the color is multiplied by (1, 1, 1,1).
 *  0b10..Normal as the result color is the source color
 *  0b11..Not affected by the color of the underlying pixel
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_DST_BLENDING_MODE_MASK)

#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_MASK (0x8000U)
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_SHIFT (15U)
/*! DST_ALPHA_FACTOR - DST Alpha Factor
 *  0b0..Do not generate the blending factor for destination alpha for the overlay layer 1.
 *  0b1..Generates the blending factor for destination alpha for the overlay layer 1.
 */
#define LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_SHIFT)) & LCDIF_OVERLAYALPHABLENDCONFIG1_DST_ALPHA_FACTOR_MASK)
/*! @} */

/*! @name OVERLAYGLOBALALPHA1 - Overlay Layer 1 Global Alpha */
/*! @{ */

#define LCDIF_OVERLAYGLOBALALPHA1_SRC_ALPHA_MASK (0xFFU)
#define LCDIF_OVERLAYGLOBALALPHA1_SRC_ALPHA_SHIFT (0U)
/*! SRC_ALPHA - Source Alpha */
#define LCDIF_OVERLAYGLOBALALPHA1_SRC_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYGLOBALALPHA1_SRC_ALPHA_SHIFT)) & LCDIF_OVERLAYGLOBALALPHA1_SRC_ALPHA_MASK)

#define LCDIF_OVERLAYGLOBALALPHA1_DST_ALPHA_MASK (0xFF00U)
#define LCDIF_OVERLAYGLOBALALPHA1_DST_ALPHA_SHIFT (8U)
/*! DST_ALPHA - Destination Alpha */
#define LCDIF_OVERLAYGLOBALALPHA1_DST_ALPHA(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYGLOBALALPHA1_DST_ALPHA_SHIFT)) & LCDIF_OVERLAYGLOBALALPHA1_DST_ALPHA_MASK)
/*! @} */

/*! @name OVERLAYCLEARVALUE1 - Overlay Layer 1 Clear Value */
/*! @{ */

#define LCDIF_OVERLAYCLEARVALUE1_BLUE_MASK       (0xFFU)
#define LCDIF_OVERLAYCLEARVALUE1_BLUE_SHIFT      (0U)
/*! BLUE - Blue */
#define LCDIF_OVERLAYCLEARVALUE1_BLUE(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE1_BLUE_SHIFT)) & LCDIF_OVERLAYCLEARVALUE1_BLUE_MASK)

#define LCDIF_OVERLAYCLEARVALUE1_GREEN_MASK      (0xFF00U)
#define LCDIF_OVERLAYCLEARVALUE1_GREEN_SHIFT     (8U)
/*! GREEN - Green */
#define LCDIF_OVERLAYCLEARVALUE1_GREEN(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE1_GREEN_SHIFT)) & LCDIF_OVERLAYCLEARVALUE1_GREEN_MASK)

#define LCDIF_OVERLAYCLEARVALUE1_RED_MASK        (0xFF0000U)
#define LCDIF_OVERLAYCLEARVALUE1_RED_SHIFT       (16U)
/*! RED - Red */
#define LCDIF_OVERLAYCLEARVALUE1_RED(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE1_RED_SHIFT)) & LCDIF_OVERLAYCLEARVALUE1_RED_MASK)

#define LCDIF_OVERLAYCLEARVALUE1_ALPHA_MASK      (0xFF000000U)
#define LCDIF_OVERLAYCLEARVALUE1_ALPHA_SHIFT     (24U)
/*! ALPHA - Alpha */
#define LCDIF_OVERLAYCLEARVALUE1_ALPHA(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_OVERLAYCLEARVALUE1_ALPHA_SHIFT)) & LCDIF_OVERLAYCLEARVALUE1_ALPHA_MASK)
/*! @} */

/*! @name DISPLAYDITHERTABLELOW0 - Dither Lookup Table Low Threshold */
/*! @{ */

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_MASK  (0xFU)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_SHIFT (0U)
/*! Y0_X0 - Y0_X0 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_MASK  (0xF0U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_SHIFT (4U)
/*! Y0_X1 - Y0_X1 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_MASK  (0xF00U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_SHIFT (8U)
/*! Y0_X2 - Y0_X2 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_MASK  (0xF000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_SHIFT (12U)
/*! Y0_X3 - Y0_X3 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y0_X3_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_MASK  (0xF0000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_SHIFT (16U)
/*! Y1_X0 - Y1_X0 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_MASK  (0xF00000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_SHIFT (20U)
/*! Y1_X1 - Y1_X1 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_MASK  (0xF000000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_SHIFT (24U)
/*! Y1_X2 - Y1_X2 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_MASK  (0xF0000000U)
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_SHIFT (28U)
/*! Y1_X3 - Y1_X3 */
#define LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLELOW0_Y1_X3_MASK)
/*! @} */

/*! @name DISPLAYDITHERTABLEHIGH0 - Dither Lookup Table High Threshold */
/*! @{ */

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_MASK (0xFU)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_SHIFT (0U)
/*! Y2_X0 - Y2_X0 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_MASK (0xF0U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_SHIFT (4U)
/*! Y2_X1 - Y2_X1 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_MASK (0xF00U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_SHIFT (8U)
/*! Y2_X2 - Y2_X2 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_MASK (0xF000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_SHIFT (12U)
/*! Y2_X3 - Y2_X3 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y2_X3_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_MASK (0xF0000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_SHIFT (16U)
/*! Y3_X0 - Y3_X0 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X0_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_MASK (0xF00000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_SHIFT (20U)
/*! Y3_X1 - Y3_X1 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X1_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_MASK (0xF000000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_SHIFT (24U)
/*! Y3_X2 - Y3_X2 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X2_MASK)

#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_MASK (0xF0000000U)
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_SHIFT (28U)
/*! Y3_X3 - Y3_X3 */
#define LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_SHIFT)) & LCDIF_DISPLAYDITHERTABLEHIGH0_Y3_X3_MASK)
/*! @} */

/*! @name PANELCONFIG0 - Panel Configuration */
/*! @{ */

#define LCDIF_PANELCONFIG0_DE_MASK               (0x1U)
#define LCDIF_PANELCONFIG0_DE_SHIFT              (0U)
/*! DE - Data Enable
 *  0b0..Disables data.
 *  0b1..Enables data.
 */
#define LCDIF_PANELCONFIG0_DE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DE_SHIFT)) & LCDIF_PANELCONFIG0_DE_MASK)

#define LCDIF_PANELCONFIG0_DE_POLARITY_MASK      (0x2U)
#define LCDIF_PANELCONFIG0_DE_POLARITY_SHIFT     (1U)
/*! DE_POLARITY - Data Enable Polarity
 *  0b0..Sets the polarity of data enabled to positive.
 *  0b1..Sets the polarity of data enabled to negative.
 */
#define LCDIF_PANELCONFIG0_DE_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DE_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_DE_POLARITY_MASK)

#define LCDIF_PANELCONFIG0_DATA_POLARITY_MASK    (0x20U)
#define LCDIF_PANELCONFIG0_DATA_POLARITY_SHIFT   (5U)
/*! DATA_POLARITY - Data Polarity
 *  0b0..Sets the data polarity to positive.
 *  0b1..Sets the data polarity to negative.
 */
#define LCDIF_PANELCONFIG0_DATA_POLARITY(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_DATA_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_DATA_POLARITY_MASK)

#define LCDIF_PANELCONFIG0_CLOCK_MASK            (0x100U)
#define LCDIF_PANELCONFIG0_CLOCK_SHIFT           (8U)
/*! CLOCK - Clock
 *  0b0..Disables clock.
 *  0b1..Enables clock.
 */
#define LCDIF_PANELCONFIG0_CLOCK(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_CLOCK_SHIFT)) & LCDIF_PANELCONFIG0_CLOCK_MASK)

#define LCDIF_PANELCONFIG0_CLOCK_POLARITY_MASK   (0x200U)
#define LCDIF_PANELCONFIG0_CLOCK_POLARITY_SHIFT  (9U)
/*! CLOCK_POLARITY - Clock Polarity
 *  0b0..Sets the clock polarity to positive.
 *  0b1..Sets the clock polarity to negative.
 */
#define LCDIF_PANELCONFIG0_CLOCK_POLARITY(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONFIG0_CLOCK_POLARITY_SHIFT)) & LCDIF_PANELCONFIG0_CLOCK_POLARITY_MASK)
/*! @} */

/*! @name PANELCONTROL - Panel Control */
/*! @{ */

#define LCDIF_PANELCONTROL_VALID_MASK            (0x1U)
#define LCDIF_PANELCONTROL_VALID_SHIFT           (0U)
/*! VALID - Valid
 *  0b0..Pending
 *  0b1..Copies a set of registers at the next VBLANK.
 */
#define LCDIF_PANELCONTROL_VALID(x)              (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONTROL_VALID_SHIFT)) & LCDIF_PANELCONTROL_VALID_MASK)

#define LCDIF_PANELCONTROL_BACK_PRESSURE_DISABLE_MASK (0x2U)
#define LCDIF_PANELCONTROL_BACK_PRESSURE_DISABLE_SHIFT (1U)
/*! BACK_PRESSURE_DISABLE - Back Pressure Disable
 *  0b0..Enables back pressure.
 *  0b1..Disables back pressure.
 */
#define LCDIF_PANELCONTROL_BACK_PRESSURE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELCONTROL_BACK_PRESSURE_DISABLE_SHIFT)) & LCDIF_PANELCONTROL_BACK_PRESSURE_DISABLE_MASK)
/*! @} */

/*! @name PANELFUNCTION - Panel Function */
/*! @{ */

#define LCDIF_PANELFUNCTION_OUTPUT_MASK          (0x1U)
#define LCDIF_PANELFUNCTION_OUTPUT_SHIFT         (0U)
/*! OUTPUT - Output
 *  0b0..Disables output panel.
 *  0b1..Enables output panel.
 */
#define LCDIF_PANELFUNCTION_OUTPUT(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELFUNCTION_OUTPUT_SHIFT)) & LCDIF_PANELFUNCTION_OUTPUT_MASK)

#define LCDIF_PANELFUNCTION_GAMMA_MASK           (0x2U)
#define LCDIF_PANELFUNCTION_GAMMA_SHIFT          (1U)
/*! GAMMA - Gamma
 *  0b0..Disables Gamma.
 *  0b1..Enables Gamma.
 */
#define LCDIF_PANELFUNCTION_GAMMA(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELFUNCTION_GAMMA_SHIFT)) & LCDIF_PANELFUNCTION_GAMMA_MASK)

#define LCDIF_PANELFUNCTION_DITHER_MASK          (0x4U)
#define LCDIF_PANELFUNCTION_DITHER_SHIFT         (2U)
/*! DITHER - Dither
 *  0b0..Disables dither.
 *  0b1..Enables dither.
 */
#define LCDIF_PANELFUNCTION_DITHER(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELFUNCTION_DITHER_SHIFT)) & LCDIF_PANELFUNCTION_DITHER_MASK)
/*! @} */

/*! @name PANELWORKING - Panel Working */
/*! @{ */

#define LCDIF_PANELWORKING_WORKING_MASK          (0x1U)
#define LCDIF_PANELWORKING_WORKING_SHIFT         (0U)
/*! WORKING - Working
 *  0b1..Starts reset of the display controller.
 */
#define LCDIF_PANELWORKING_WORKING(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELWORKING_WORKING_SHIFT)) & LCDIF_PANELWORKING_WORKING_MASK)
/*! @} */

/*! @name PANELSTATE - Panel State */
/*! @{ */

#define LCDIF_PANELSTATE_VIDEO_UNDER_FLOW_MASK   (0x2U)
#define LCDIF_PANELSTATE_VIDEO_UNDER_FLOW_SHIFT  (1U)
/*! VIDEO_UNDER_FLOW - Video Under Flow
 *  0b0..Do not set the display FIFO video to underflow.
 *  0b1..Sets the display FIFO video to underflow.
 */
#define LCDIF_PANELSTATE_VIDEO_UNDER_FLOW(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELSTATE_VIDEO_UNDER_FLOW_SHIFT)) & LCDIF_PANELSTATE_VIDEO_UNDER_FLOW_MASK)

#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW_MASK (0x4U)
#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW_SHIFT (2U)
/*! OVERLAY_UNDER_FLOW - Overlay Layer 0 Under Flow
 *  0b0..Do not set the overlay layer 0 FIFO to underflow.
 *  0b1..Sets the overlay layer 0 FIFO to underflow.
 */
#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW_SHIFT)) & LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW_MASK)

#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW1_MASK (0x8U)
#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW1_SHIFT (3U)
/*! OVERLAY_UNDER_FLOW1 - Overlay Layer 1 Under Flow
 *  0b0..Do not set the overlay layer 1 FIFO to underflow.
 *  0b1..Sets the overlay layer 1 FIFO to underflow.
 */
#define LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW1(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW1_SHIFT)) & LCDIF_PANELSTATE_OVERLAY_UNDER_FLOW1_MASK)
/*! @} */

/*! @name HDISPLAY0 - Horizontal Display Total and Visible Pixel Count */
/*! @{ */

#define LCDIF_HDISPLAY0_DISPLAY_END_MASK         (0x1FFFU)
#define LCDIF_HDISPLAY0_DISPLAY_END_SHIFT        (0U)
/*! DISPLAY_END - Display End */
#define LCDIF_HDISPLAY0_DISPLAY_END(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_HDISPLAY0_DISPLAY_END_SHIFT)) & LCDIF_HDISPLAY0_DISPLAY_END_MASK)

#define LCDIF_HDISPLAY0_TOTAL_MASK               (0x1FFF0000U)
#define LCDIF_HDISPLAY0_TOTAL_SHIFT              (16U)
/*! TOTAL - Total */
#define LCDIF_HDISPLAY0_TOTAL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_HDISPLAY0_TOTAL_SHIFT)) & LCDIF_HDISPLAY0_TOTAL_MASK)
/*! @} */

/*! @name HSYNC0 - Horizontal Sync Counter */
/*! @{ */

#define LCDIF_HSYNC0_START_MASK                  (0x1FFFU)
#define LCDIF_HSYNC0_START_SHIFT                 (0U)
/*! START - Start */
#define LCDIF_HSYNC0_START(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_START_SHIFT)) & LCDIF_HSYNC0_START_MASK)

#define LCDIF_HSYNC0_END_MASK                    (0x1FFF0000U)
#define LCDIF_HSYNC0_END_SHIFT                   (16U)
/*! END - End */
#define LCDIF_HSYNC0_END(x)                      (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_END_SHIFT)) & LCDIF_HSYNC0_END_MASK)

#define LCDIF_HSYNC0_PULSE_MASK                  (0x40000000U)
#define LCDIF_HSYNC0_PULSE_SHIFT                 (30U)
/*! PULSE - Sync Pulse
 *  0b0..Disables horizontal sync pulse control.
 *  0b1..Enables horizontal sync pulse control.
 */
#define LCDIF_HSYNC0_PULSE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_PULSE_SHIFT)) & LCDIF_HSYNC0_PULSE_MASK)

#define LCDIF_HSYNC0_POLARITY_MASK               (0x80000000U)
#define LCDIF_HSYNC0_POLARITY_SHIFT              (31U)
/*! POLARITY - Sync Pulse Polarity
 *  0b0..Sets the polarity of the horizontal sync pulse to positive.
 *  0b1..Sets the polarity of the horizontal sync pulse to negative.
 */
#define LCDIF_HSYNC0_POLARITY(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_HSYNC0_POLARITY_SHIFT)) & LCDIF_HSYNC0_POLARITY_MASK)
/*! @} */

/*! @name VDISPLAY0 - Vertical Total and Visible Pixel Count */
/*! @{ */

#define LCDIF_VDISPLAY0_DISPLAY_END_MASK         (0xFFFU)
#define LCDIF_VDISPLAY0_DISPLAY_END_SHIFT        (0U)
/*! DISPLAY_END - Display End */
#define LCDIF_VDISPLAY0_DISPLAY_END(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_VDISPLAY0_DISPLAY_END_SHIFT)) & LCDIF_VDISPLAY0_DISPLAY_END_MASK)

#define LCDIF_VDISPLAY0_TOTAL_MASK               (0xFFF0000U)
#define LCDIF_VDISPLAY0_TOTAL_SHIFT              (16U)
/*! TOTAL - Total */
#define LCDIF_VDISPLAY0_TOTAL(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_VDISPLAY0_TOTAL_SHIFT)) & LCDIF_VDISPLAY0_TOTAL_MASK)
/*! @} */

/*! @name VSYNC0 - Vertical Sync Counter */
/*! @{ */

#define LCDIF_VSYNC0_START_MASK                  (0xFFFU)
#define LCDIF_VSYNC0_START_SHIFT                 (0U)
/*! START - Start */
#define LCDIF_VSYNC0_START(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_START_SHIFT)) & LCDIF_VSYNC0_START_MASK)

#define LCDIF_VSYNC0_END_MASK                    (0xFFF0000U)
#define LCDIF_VSYNC0_END_SHIFT                   (16U)
/*! END - End */
#define LCDIF_VSYNC0_END(x)                      (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_END_SHIFT)) & LCDIF_VSYNC0_END_MASK)

#define LCDIF_VSYNC0_PULSE_MASK                  (0x40000000U)
#define LCDIF_VSYNC0_PULSE_SHIFT                 (30U)
/*! PULSE - Vertical Sync Pulse
 *  0b0..Disables vertical sync pulse.
 *  0b1..Enables vertical sync pulse.
 */
#define LCDIF_VSYNC0_PULSE(x)                    (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_PULSE_SHIFT)) & LCDIF_VSYNC0_PULSE_MASK)

#define LCDIF_VSYNC0_POLARITY_MASK               (0x80000000U)
#define LCDIF_VSYNC0_POLARITY_SHIFT              (31U)
/*! POLARITY - Polarity
 *  0b0..Sets the polarity of the vertical sync pulse to positive.
 *  0b1..Sets the polarity of the vertical sync pulse to negative.
 */
#define LCDIF_VSYNC0_POLARITY(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_VSYNC0_POLARITY_SHIFT)) & LCDIF_VSYNC0_POLARITY_MASK)
/*! @} */

/*! @name DISPLAYCURRENTLOCATION0 - Display Current Location */
/*! @{ */

#define LCDIF_DISPLAYCURRENTLOCATION0_X_MASK     (0xFFFFU)
#define LCDIF_DISPLAYCURRENTLOCATION0_X_SHIFT    (0U)
/*! X - X */
#define LCDIF_DISPLAYCURRENTLOCATION0_X(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYCURRENTLOCATION0_X_SHIFT)) & LCDIF_DISPLAYCURRENTLOCATION0_X_MASK)

#define LCDIF_DISPLAYCURRENTLOCATION0_Y_MASK     (0xFFFF0000U)
#define LCDIF_DISPLAYCURRENTLOCATION0_Y_SHIFT    (16U)
/*! Y - Y */
#define LCDIF_DISPLAYCURRENTLOCATION0_Y(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYCURRENTLOCATION0_Y_SHIFT)) & LCDIF_DISPLAYCURRENTLOCATION0_Y_MASK)
/*! @} */

/*! @name GAMMAINDEX0 - Gamma Index */
/*! @{ */

#define LCDIF_GAMMAINDEX0_INDEX_MASK             (0xFFU)
#define LCDIF_GAMMAINDEX0_INDEX_SHIFT            (0U)
/*! INDEX - Index */
#define LCDIF_GAMMAINDEX0_INDEX(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMAINDEX0_INDEX_SHIFT)) & LCDIF_GAMMAINDEX0_INDEX_MASK)
/*! @} */

/*! @name GAMMADATA0 - Gamma Data */
/*! @{ */

#define LCDIF_GAMMADATA0_BLUE_MASK               (0xFFU)
#define LCDIF_GAMMADATA0_BLUE_SHIFT              (0U)
/*! BLUE - Blue */
#define LCDIF_GAMMADATA0_BLUE(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_BLUE_SHIFT)) & LCDIF_GAMMADATA0_BLUE_MASK)

#define LCDIF_GAMMADATA0_GREEN_MASK              (0xFF00U)
#define LCDIF_GAMMADATA0_GREEN_SHIFT             (8U)
/*! GREEN - Green */
#define LCDIF_GAMMADATA0_GREEN(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_GREEN_SHIFT)) & LCDIF_GAMMADATA0_GREEN_MASK)

#define LCDIF_GAMMADATA0_RED_MASK                (0xFF0000U)
#define LCDIF_GAMMADATA0_RED_SHIFT               (16U)
/*! RED - Red */
#define LCDIF_GAMMADATA0_RED(x)                  (((uint32_t)(((uint32_t)(x)) << LCDIF_GAMMADATA0_RED_SHIFT)) & LCDIF_GAMMADATA0_RED_MASK)
/*! @} */

/*! @name CURSORCONFIG - Cursor Configuration */
/*! @{ */

#define LCDIF_CURSORCONFIG_FORMAT_MASK           (0x3U)
#define LCDIF_CURSORCONFIG_FORMAT_SHIFT          (0U)
/*! FORMAT - Format
 *  0b00..Disables the format of a cursor.
 *  0b01..Sets the cursor in masked format, where the mask values of the AND and XOR bits decide the color of one cursor image pixel..
 *  0b10..Sets the cursor in A8R8G8B8 format, where the color of the cursor image is decided by the ARGB values fetched from the memory.
 */
#define LCDIF_CURSORCONFIG_FORMAT(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_FORMAT_SHIFT)) & LCDIF_CURSORCONFIG_FORMAT_MASK)

#define LCDIF_CURSORCONFIG_HOT_SPOT_Y_MASK       (0x1F00U)
#define LCDIF_CURSORCONFIG_HOT_SPOT_Y_SHIFT      (8U)
/*! HOT_SPOT_Y - Vertical Hot Spot */
#define LCDIF_CURSORCONFIG_HOT_SPOT_Y(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_HOT_SPOT_Y_SHIFT)) & LCDIF_CURSORCONFIG_HOT_SPOT_Y_MASK)

#define LCDIF_CURSORCONFIG_HOT_SPOT_X_MASK       (0x1F0000U)
#define LCDIF_CURSORCONFIG_HOT_SPOT_X_SHIFT      (16U)
/*! HOT_SPOT_X - Horizontal Hot Spot */
#define LCDIF_CURSORCONFIG_HOT_SPOT_X(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORCONFIG_HOT_SPOT_X_SHIFT)) & LCDIF_CURSORCONFIG_HOT_SPOT_X_MASK)
/*! @} */

/*! @name CURSORADDRESS - Cursor Base Address */
/*! @{ */

#define LCDIF_CURSORADDRESS_ADDRESS_MASK         (0xFFFFFFFFU)
#define LCDIF_CURSORADDRESS_ADDRESS_SHIFT        (0U)
/*! ADDRESS - Base address */
#define LCDIF_CURSORADDRESS_ADDRESS(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORADDRESS_ADDRESS_SHIFT)) & LCDIF_CURSORADDRESS_ADDRESS_MASK)
/*! @} */

/*! @name CURSORLOCATION - Cursor Location */
/*! @{ */

#define LCDIF_CURSORLOCATION_X_MASK              (0x1FFFU)
#define LCDIF_CURSORLOCATION_X_SHIFT             (0U)
/*! X - X */
#define LCDIF_CURSORLOCATION_X(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORLOCATION_X_SHIFT)) & LCDIF_CURSORLOCATION_X_MASK)

#define LCDIF_CURSORLOCATION_Y_MASK              (0xFFF0000U)
#define LCDIF_CURSORLOCATION_Y_SHIFT             (16U)
/*! Y - Y */
#define LCDIF_CURSORLOCATION_Y(x)                (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORLOCATION_Y_SHIFT)) & LCDIF_CURSORLOCATION_Y_MASK)
/*! @} */

/*! @name CURSORBACKGROUND - Cursor Background Color */
/*! @{ */

#define LCDIF_CURSORBACKGROUND_BLUE_MASK         (0xFFU)
#define LCDIF_CURSORBACKGROUND_BLUE_SHIFT        (0U)
/*! BLUE - Blue */
#define LCDIF_CURSORBACKGROUND_BLUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_BLUE_SHIFT)) & LCDIF_CURSORBACKGROUND_BLUE_MASK)

#define LCDIF_CURSORBACKGROUND_GREEN_MASK        (0xFF00U)
#define LCDIF_CURSORBACKGROUND_GREEN_SHIFT       (8U)
/*! GREEN - Green */
#define LCDIF_CURSORBACKGROUND_GREEN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_GREEN_SHIFT)) & LCDIF_CURSORBACKGROUND_GREEN_MASK)

#define LCDIF_CURSORBACKGROUND_RED_MASK          (0xFF0000U)
#define LCDIF_CURSORBACKGROUND_RED_SHIFT         (16U)
/*! RED - Red */
#define LCDIF_CURSORBACKGROUND_RED(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORBACKGROUND_RED_SHIFT)) & LCDIF_CURSORBACKGROUND_RED_MASK)
/*! @} */

/*! @name CURSORFOREGROUND - Cursor Foreground Color */
/*! @{ */

#define LCDIF_CURSORFOREGROUND_BLUE_MASK         (0xFFU)
#define LCDIF_CURSORFOREGROUND_BLUE_SHIFT        (0U)
/*! BLUE - Blue */
#define LCDIF_CURSORFOREGROUND_BLUE(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_BLUE_SHIFT)) & LCDIF_CURSORFOREGROUND_BLUE_MASK)

#define LCDIF_CURSORFOREGROUND_GREEN_MASK        (0xFF00U)
#define LCDIF_CURSORFOREGROUND_GREEN_SHIFT       (8U)
/*! GREEN - Green */
#define LCDIF_CURSORFOREGROUND_GREEN(x)          (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_GREEN_SHIFT)) & LCDIF_CURSORFOREGROUND_GREEN_MASK)

#define LCDIF_CURSORFOREGROUND_RED_MASK          (0xFF0000U)
#define LCDIF_CURSORFOREGROUND_RED_SHIFT         (16U)
/*! RED - Red */
#define LCDIF_CURSORFOREGROUND_RED(x)            (((uint32_t)(((uint32_t)(x)) << LCDIF_CURSORFOREGROUND_RED_SHIFT)) & LCDIF_CURSORFOREGROUND_RED_MASK)
/*! @} */

/*! @name DISPLAYINTR - Display Interrupt */
/*! @{ */

#define LCDIF_DISPLAYINTR_DISP0_MASK             (0x1U)
#define LCDIF_DISPLAYINTR_DISP0_SHIFT            (0U)
/*! DISP0 - Display_0 */
#define LCDIF_DISPLAYINTR_DISP0(x)               (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_DISP0_SHIFT)) & LCDIF_DISPLAYINTR_DISP0_MASK)

#define LCDIF_DISPLAYINTR_DISP0_DBI_CFG_ERROR_MASK (0x1000U)
#define LCDIF_DISPLAYINTR_DISP0_DBI_CFG_ERROR_SHIFT (12U)
/*! DISP0_DBI_CFG_ERROR - Display_0 DBI Configure Error */
#define LCDIF_DISPLAYINTR_DISP0_DBI_CFG_ERROR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_DISP0_DBI_CFG_ERROR_SHIFT)) & LCDIF_DISPLAYINTR_DISP0_DBI_CFG_ERROR_MASK)

#define LCDIF_DISPLAYINTR_PANEL_UNDERFLOW_MASK   (0x20000000U)
#define LCDIF_DISPLAYINTR_PANEL_UNDERFLOW_SHIFT  (29U)
/*! PANEL_UNDERFLOW - Panel Underflow */
#define LCDIF_DISPLAYINTR_PANEL_UNDERFLOW(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_PANEL_UNDERFLOW_SHIFT)) & LCDIF_DISPLAYINTR_PANEL_UNDERFLOW_MASK)

#define LCDIF_DISPLAYINTR_SOFT_RESET_DONE_MASK   (0x40000000U)
#define LCDIF_DISPLAYINTR_SOFT_RESET_DONE_SHIFT  (30U)
/*! SOFT_RESET_DONE - Soft Reset Done */
#define LCDIF_DISPLAYINTR_SOFT_RESET_DONE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_SOFT_RESET_DONE_SHIFT)) & LCDIF_DISPLAYINTR_SOFT_RESET_DONE_MASK)

#define LCDIF_DISPLAYINTR_BUS_ERROR_MASK         (0x80000000U)
#define LCDIF_DISPLAYINTR_BUS_ERROR_SHIFT        (31U)
/*! BUS_ERROR - Bus Error */
#define LCDIF_DISPLAYINTR_BUS_ERROR(x)           (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTR_BUS_ERROR_SHIFT)) & LCDIF_DISPLAYINTR_BUS_ERROR_MASK)
/*! @} */

/*! @name DISPLAYINTRENABLE - Display Interrupt Enable */
/*! @{ */

#define LCDIF_DISPLAYINTRENABLE_DISP0_MASK       (0x1U)
#define LCDIF_DISPLAYINTRENABLE_DISP0_SHIFT      (0U)
/*! DISP0 - Display_0
 *  0b0..Enables Display_0 interrupt.
 *  0b1..Disables Display_0 interrupt.
 */
#define LCDIF_DISPLAYINTRENABLE_DISP0(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_DISP0_SHIFT)) & LCDIF_DISPLAYINTRENABLE_DISP0_MASK)

#define LCDIF_DISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_MASK (0x1000U)
#define LCDIF_DISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_SHIFT (12U)
/*! DISP0_DBI_CFG_ERROR - Display_0 DBI Configuration Error
 *  0b0..Enables Display_0 DBI configuration error.
 *  0b1..Disables Display_0 DBI configuration error.
 */
#define LCDIF_DISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_SHIFT)) & LCDIF_DISPLAYINTRENABLE_DISP0_DBI_CFG_ERROR_MASK)

#define LCDIF_DISPLAYINTRENABLE_PANEL_UNDERFLOW_MASK (0x20000000U)
#define LCDIF_DISPLAYINTRENABLE_PANEL_UNDERFLOW_SHIFT (29U)
/*! PANEL_UNDERFLOW - Panel Underflow
 *  0b0..Enables panel underflow interrupt.
 *  0b1..Disables panel underflow interrupt.
 */
#define LCDIF_DISPLAYINTRENABLE_PANEL_UNDERFLOW(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_PANEL_UNDERFLOW_SHIFT)) & LCDIF_DISPLAYINTRENABLE_PANEL_UNDERFLOW_MASK)

#define LCDIF_DISPLAYINTRENABLE_SOFT_RESET_DONE_MASK (0x40000000U)
#define LCDIF_DISPLAYINTRENABLE_SOFT_RESET_DONE_SHIFT (30U)
/*! SOFT_RESET_DONE - Soft Reset Done
 *  0b0..Disables soft reset done interrupt.
 *  0b1..Enables soft reset done interrupt.
 */
#define LCDIF_DISPLAYINTRENABLE_SOFT_RESET_DONE(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_SOFT_RESET_DONE_SHIFT)) & LCDIF_DISPLAYINTRENABLE_SOFT_RESET_DONE_MASK)

#define LCDIF_DISPLAYINTRENABLE_BUS_ERROR_MASK   (0x80000000U)
#define LCDIF_DISPLAYINTRENABLE_BUS_ERROR_SHIFT  (31U)
/*! BUS_ERROR - Bus Error
 *  0b0..Enables bus error interrupt.
 *  0b1..Disables bus error interrupt.
 */
#define LCDIF_DISPLAYINTRENABLE_BUS_ERROR(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DISPLAYINTRENABLE_BUS_ERROR_SHIFT)) & LCDIF_DISPLAYINTRENABLE_BUS_ERROR_MASK)
/*! @} */

/*! @name DBICONFIG0 - DBI Configuration */
/*! @{ */

#define LCDIF_DBICONFIG0_DBI_TYPE_MASK           (0x3U)
#define LCDIF_DBICONFIG0_DBI_TYPE_SHIFT          (0U)
/*! DBI_TYPE - DBI Type
 *  0b00..Selects DBI Type A Fixed E mode.
 *  0b01..Selects DBI Type A Clocked E mode.
 *  0b10..Selects DBI type B.
 */
#define LCDIF_DBICONFIG0_DBI_TYPE(x)             (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_TYPE_SHIFT)) & LCDIF_DBICONFIG0_DBI_TYPE_MASK)

#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT_MASK    (0x3CU)
#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT_SHIFT   (2U)
/*! DBI_DATA_FORMAT - DBI Data Format
 *  0b0000..D8R3G3B2
 *  0b0001..D8R4G4B4
 *  0b0010..D8R5G6B5
 *  0b0011..D8R6G6B6
 *  0b0100..D8R8G8B8
 *  0b0101..D9R6G6B6
 *  0b0110..D16R3G3B2
 *  0b0111..D16R4G4B4
 *  0b1000..D16R5G6B5
 *  0b1001..D16_R6_G6_B6_OP1
 *  0b1010..D16_R6_G6_B6_OP2
 *  0b1011..D16_R8_G8_B8_OP1
 *  0b1100..D16_R8_G8_B8_OP2
 */
#define LCDIF_DBICONFIG0_DBI_DATA_FORMAT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_DATA_FORMAT_SHIFT)) & LCDIF_DBICONFIG0_DBI_DATA_FORMAT_MASK)

#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_MASK     (0x40U)
#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_SHIFT    (6U)
/*! BUS_OUTPUT_SEL - Output Bus Select
 *  0b0..Uses DPI bus.
 *  0b1..Uses DBI bus.
 */
#define LCDIF_DBICONFIG0_BUS_OUTPUT_SEL(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_SHIFT)) & LCDIF_DBICONFIG0_BUS_OUTPUT_SEL_MASK)

#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_MASK   (0xF00U)
#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_SHIFT  (8U)
/*! DBI_AC_TIME_UNIT - DBI AC Time Unit */
#define LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_SHIFT)) & LCDIF_DBICONFIG0_DBI_AC_TIME_UNIT_MASK)

#define LCDIF_DBICONFIG0_DBI_OUTPUT_SWIZZLE_MASK (0x8000000U)
#define LCDIF_DBICONFIG0_DBI_OUTPUT_SWIZZLE_SHIFT (27U)
/*! DBI_OUTPUT_SWIZZLE - DBIT Output Swizzle Set
 *  0b0..RGB
 *  0b1..BGR
 */
#define LCDIF_DBICONFIG0_DBI_OUTPUT_SWIZZLE(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICONFIG0_DBI_OUTPUT_SWIZZLE_SHIFT)) & LCDIF_DBICONFIG0_DBI_OUTPUT_SWIZZLE_MASK)
/*! @} */

/*! @name DBIIFRESET0 - DBI Interface Reset */
/*! @{ */

#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_MASK (0x1U)
#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_SHIFT (0U)
/*! DBI_IF_LEVEL_RESET - DBI Interface Level Reset
 *  0b1..Resets the DBI bus in idle state.
 */
#define LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET(x)  (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_SHIFT)) & LCDIF_DBIIFRESET0_DBI_IF_LEVEL_RESET_MASK)
/*! @} */

/*! @name DBIWRCHAR10 - DBI Write AC Characteristics 1 */
/*! @{ */

#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_MASK     (0xFFU)
#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_SHIFT    (0U)
/*! DBI_WR_PERIOD - DBI Write Period */
#define LCDIF_DBIWRCHAR10_DBI_WR_PERIOD(x)       (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_PERIOD_MASK)

#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_MASK (0xF00U)
#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_SHIFT (8U)
/*! DBI_WR_EOR_WR_ASSERT - DBI Clock E Signal or WRX Signal Assert */
#define LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_EOR_WR_ASSERT_MASK)

#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_MASK  (0xF000U)
#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_SHIFT (12U)
/*! DBI_WR_CS_ASSERT - DBI Write CS Assert */
#define LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT(x)    (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_SHIFT)) & LCDIF_DBIWRCHAR10_DBI_WR_CS_ASSERT_MASK)
/*! @} */

/*! @name DBIWRCHAR20 - DBI Write AC Characteristics 2 */
/*! @{ */

#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_MASK (0xFFU)
#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_SHIFT (0U)
/*! DBI_WR_EOR_WR_DE_ASRT - DBI Clock E Signal or WRX Signal Desert Assert */
#define LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_SHIFT)) & LCDIF_DBIWRCHAR20_DBI_WR_EOR_WR_DE_ASRT_MASK)

#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_MASK (0xFF00U)
#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_SHIFT (8U)
/*! DBI_WR_CS_DE_ASRT - DBI Write CS De-assert */
#define LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT(x)   (((uint32_t)(((uint32_t)(x)) << LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_SHIFT)) & LCDIF_DBIWRCHAR20_DBI_WR_CS_DE_ASRT_MASK)
/*! @} */

/*! @name DBICMD0 - DBI Command Control */
/*! @{ */

#define LCDIF_DBICMD0_DBI_COMMAND_WORD_MASK      (0xFFFFU)
#define LCDIF_DBICMD0_DBI_COMMAND_WORD_SHIFT     (0U)
/*! DBI_COMMAND_WORD - DBI Command Word */
#define LCDIF_DBICMD0_DBI_COMMAND_WORD(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICMD0_DBI_COMMAND_WORD_SHIFT)) & LCDIF_DBICMD0_DBI_COMMAND_WORD_MASK)

#define LCDIF_DBICMD0_DBI_COMMANDFLAG_MASK       (0xC0000000U)
#define LCDIF_DBICMD0_DBI_COMMANDFLAG_SHIFT      (30U)
/*! DBI_COMMANDFLAG - DBI Command Flag
 *  0b00..Address
 *  0b01..Write Memory Start
 *  0b10..Parameter or Data
 */
#define LCDIF_DBICMD0_DBI_COMMANDFLAG(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_DBICMD0_DBI_COMMANDFLAG_SHIFT)) & LCDIF_DBICMD0_DBI_COMMANDFLAG_MASK)
/*! @} */

/*! @name DPICONFIG0 - DPI Configuration */
/*! @{ */

#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT_MASK    (0x7U)
#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT_SHIFT   (0U)
/*! DPI_DATA_FORMAT - DPI Data Format
 *  0b000..D16CFG1
 *  0b001..D16CFG2
 *  0b010..D16CFG3
 *  0b011..D18CFG1
 *  0b100..D18CFG2
 *  0b101..D24
 */
#define LCDIF_DPICONFIG0_DPI_DATA_FORMAT(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DPICONFIG0_DPI_DATA_FORMAT_SHIFT)) & LCDIF_DPICONFIG0_DPI_DATA_FORMAT_MASK)

#define LCDIF_DPICONFIG0_DPI_COMMAND_MODE_MASK   (0x10U)
#define LCDIF_DPICONFIG0_DPI_COMMAND_MODE_SHIFT  (4U)
/*! DPI_COMMAND_MODE - DPI Command Mode
 *  0b0..Disables the DPI command mode.
 *  0b1..Enables the DPI command mode.
 */
#define LCDIF_DPICONFIG0_DPI_COMMAND_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LCDIF_DPICONFIG0_DPI_COMMAND_MODE_SHIFT)) & LCDIF_DPICONFIG0_DPI_COMMAND_MODE_MASK)
/*! @} */

/*! @name SRCCONFIGENDIAN - Source Endian Configuration */
/*! @{ */

#define LCDIF_SRCCONFIGENDIAN_CONTROL_MASK       (0x3U)
#define LCDIF_SRCCONFIGENDIAN_CONTROL_SHIFT      (0U)
/*! CONTROL - Control
 *  0b00..No Swap
 *  0b01..Swap Word
 *  0b10..Swap Dword
 */
#define LCDIF_SRCCONFIGENDIAN_CONTROL(x)         (((uint32_t)(((uint32_t)(x)) << LCDIF_SRCCONFIGENDIAN_CONTROL_SHIFT)) & LCDIF_SRCCONFIGENDIAN_CONTROL_MASK)
/*! @} */

/*! @name SOFTRESET - Soft Reset */
/*! @{ */

#define LCDIF_SOFTRESET_RESET_MASK               (0x1U)
#define LCDIF_SOFTRESET_RESET_SHIFT              (0U)
/*! RESET - Reset Display Controller
 *  0b0..Disable
 *  0b1..Enable
 */
#define LCDIF_SOFTRESET_RESET(x)                 (((uint32_t)(((uint32_t)(x)) << LCDIF_SOFTRESET_RESET_SHIFT)) & LCDIF_SOFTRESET_RESET_MASK)
/*! @} */

/*! @name DCCONTROL - Display Controller Control */
/*! @{ */

#define LCDIF_DCCONTROL_DEBUG_REGISTER_MASK      (0x8U)
#define LCDIF_DCCONTROL_DEBUG_REGISTER_SHIFT     (3U)
/*! DEBUG_REGISTER - Debug
 *  0b0..Disables debug.
 *  0b1..Enables debug.
 */
#define LCDIF_DCCONTROL_DEBUG_REGISTER(x)        (((uint32_t)(((uint32_t)(x)) << LCDIF_DCCONTROL_DEBUG_REGISTER_SHIFT)) & LCDIF_DCCONTROL_DEBUG_REGISTER_MASK)

#define LCDIF_DCCONTROL_RAM_CLOCK_GATING_MASK    (0x10U)
#define LCDIF_DCCONTROL_RAM_CLOCK_GATING_SHIFT   (4U)
/*! RAM_CLOCK_GATING - Enables or disables RAM clock gating.
 *  0b0..Disables RAM clock gating.
 *  0b1..Enables RAM clock gating.
 */
#define LCDIF_DCCONTROL_RAM_CLOCK_GATING(x)      (((uint32_t)(((uint32_t)(x)) << LCDIF_DCCONTROL_RAM_CLOCK_GATING_SHIFT)) & LCDIF_DCCONTROL_RAM_CLOCK_GATING_MASK)
/*! @} */

/*! @name LAYERCLOCKGATE - Layer Clock Gating */
/*! @{ */

#define LCDIF_LAYERCLOCKGATE_DISABLE_VIDEO_CLK_MASK (0x1U)
#define LCDIF_LAYERCLOCKGATE_DISABLE_VIDEO_CLK_SHIFT (0U)
/*! DISABLE_VIDEO_CLK - Disable Video Clock
 *  0b0..Disables clock gating on the VG layer.
 *  0b1..Enables clock gating on the VG layer.
 */
#define LCDIF_LAYERCLOCKGATE_DISABLE_VIDEO_CLK(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_LAYERCLOCKGATE_DISABLE_VIDEO_CLK_SHIFT)) & LCDIF_LAYERCLOCKGATE_DISABLE_VIDEO_CLK_MASK)

#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_MASK (0x2U)
#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_SHIFT (1U)
/*! DISABLE_OVERLAY0_CLK - Disable Overlay 0 Clock
 *  0b0..Disables clock gating on the overlay 0 layer.
 *  0b1..Enables clock gating on the overlay 0 layer.
 */
#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY0_CLK(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_SHIFT)) & LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY0_CLK_MASK)

#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_MASK (0x4U)
#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_SHIFT (2U)
/*! DISABLE_OVERLAY1_CLK - Disable Overlay 1 Clock
 *  0b0..Disables clock gating on the overlay 1 layer.
 *  0b1..Enables clock gating on the overlay 1 layer.
 */
#define LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY1_CLK(x) (((uint32_t)(((uint32_t)(x)) << LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_SHIFT)) & LCDIF_LAYERCLOCKGATE_DISABLE_OVERLAY1_CLK_MASK)
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

