/*
** ###################################################################
**     Processors:          LPC54005JBD100
**                          LPC54005JET100
**                          LPC54016JBD100
**                          LPC54016JBD208
**                          LPC54016JET100
**                          LPC54016JET180
**                          LPC54018JBD208
**                          LPC54018JET180
**                          LPC54S005JBD100
**                          LPC54S005JET100
**                          LPC54S016JBD100
**                          LPC54S016JBD208
**                          LPC54S016JET100
**                          LPC54S016JET180
**                          LPC54S018JBD208
**                          LPC54S018JET180
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for LCD
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2016-08-12)
**         Initial version.
**     - rev. 1.1 (2016-11-25)
**         Update CANFD and Classic CAN register.
**         Add MAC TIMERSTAMP registers.
**     - rev. 1.2 (2017-06-08)
**         Remove RTC_CTRL_RTC_OSC_BYPASS.
**         SYSCON_ARMTRCLKDIV rename to SYSCON_ARMTRACECLKDIV.
**         Remove RESET and HALT from SYSCON_AHBCLKDIV.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_LCD.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LCD
 *
 * CMSIS Peripheral Access Layer for LCD
 */

#if !defined(PERI_LCD_H_)
#define PERI_LCD_H_                              /**< Symbol preventing repeated inclusion */

#if (defined(CPU_LPC54005JBD100) || defined(CPU_LPC54005JET100))
#include "LPC54005_COMMON.h"
#elif (defined(CPU_LPC54016JBD100) || defined(CPU_LPC54016JBD208) || defined(CPU_LPC54016JET100) || defined(CPU_LPC54016JET180))
#include "LPC54016_COMMON.h"
#elif (defined(CPU_LPC54018JBD208) || defined(CPU_LPC54018JET180))
#include "LPC54018_COMMON.h"
#elif (defined(CPU_LPC54S005JBD100) || defined(CPU_LPC54S005JET100))
#include "LPC54S005_COMMON.h"
#elif (defined(CPU_LPC54S016JBD100) || defined(CPU_LPC54S016JBD208) || defined(CPU_LPC54S016JET100) || defined(CPU_LPC54S016JET180))
#include "LPC54S016_COMMON.h"
#elif (defined(CPU_LPC54S018JBD208) || defined(CPU_LPC54S018JET180))
#include "LPC54S018_COMMON.h"
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
   -- LCD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCD_Peripheral_Access_Layer LCD Peripheral Access Layer
 * @{
 */

/** LCD - Size of Registers Arrays */
#define LCD_PAL_COUNT                             128u
#define LCD_CRSR_IMG_COUNT                        256u

/** LCD - Register Layout Typedef */
typedef struct {
  __IO uint32_t TIMH;                              /**< Horizontal Timing Control register, offset: 0x0 */
  __IO uint32_t TIMV;                              /**< Vertical Timing Control register, offset: 0x4 */
  __IO uint32_t POL;                               /**< Clock and Signal Polarity Control register, offset: 0x8 */
  __IO uint32_t LE;                                /**< Line End Control register, offset: 0xC */
  __IO uint32_t UPBASE;                            /**< Upper Panel Frame Base Address register, offset: 0x10 */
  __IO uint32_t LPBASE;                            /**< Lower Panel Frame Base Address register, offset: 0x14 */
  __IO uint32_t CTRL;                              /**< LCD Control register, offset: 0x18 */
  __IO uint32_t INTMSK;                            /**< Interrupt Mask register, offset: 0x1C */
  __I  uint32_t INTRAW;                            /**< Raw Interrupt Status register, offset: 0x20 */
  __I  uint32_t INTSTAT;                           /**< Masked Interrupt Status register, offset: 0x24 */
  __O  uint32_t INTCLR;                            /**< Interrupt Clear register, offset: 0x28 */
  __I  uint32_t UPCURR;                            /**< Upper Panel Current Address Value register, offset: 0x2C */
  __I  uint32_t LPCURR;                            /**< Lower Panel Current Address Value register, offset: 0x30 */
       uint8_t RESERVED_0[460];
  __IO uint32_t PAL[LCD_PAL_COUNT];                /**< 256x16-bit Color Palette registers, array offset: 0x200, array step: 0x4 */
       uint8_t RESERVED_1[1024];
  __IO uint32_t CRSR_IMG[LCD_CRSR_IMG_COUNT];      /**< Cursor Image registers, array offset: 0x800, array step: 0x4 */
  __IO uint32_t CRSR_CTRL;                         /**< Cursor Control register, offset: 0xC00 */
  __IO uint32_t CRSR_CFG;                          /**< Cursor Configuration register, offset: 0xC04 */
  __IO uint32_t CRSR_PAL0;                         /**< Cursor Palette register 0, offset: 0xC08 */
  __IO uint32_t CRSR_PAL1;                         /**< Cursor Palette register 1, offset: 0xC0C */
  __IO uint32_t CRSR_XY;                           /**< Cursor XY Position register, offset: 0xC10 */
  __IO uint32_t CRSR_CLIP;                         /**< Cursor Clip Position register, offset: 0xC14 */
       uint8_t RESERVED_2[8];
  __IO uint32_t CRSR_INTMSK;                       /**< Cursor Interrupt Mask register, offset: 0xC20 */
  __O  uint32_t CRSR_INTCLR;                       /**< Cursor Interrupt Clear register, offset: 0xC24 */
  __I  uint32_t CRSR_INTRAW;                       /**< Cursor Raw Interrupt Status register, offset: 0xC28 */
  __I  uint32_t CRSR_INTSTAT;                      /**< Cursor Masked Interrupt Status register, offset: 0xC2C */
} LCD_Type;

/* ----------------------------------------------------------------------------
   -- LCD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LCD_Register_Masks LCD Register Masks
 * @{
 */

/*! @name TIMH - Horizontal Timing Control register */
/*! @{ */

#define LCD_TIMH_PPL_MASK                        (0xFCU)
#define LCD_TIMH_PPL_SHIFT                       (2U)
/*! PPL - Pixels-per-line. */
#define LCD_TIMH_PPL(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMH_PPL_SHIFT)) & LCD_TIMH_PPL_MASK)

#define LCD_TIMH_HSW_MASK                        (0xFF00U)
#define LCD_TIMH_HSW_SHIFT                       (8U)
/*! HSW - Horizontal synchronization pulse width. */
#define LCD_TIMH_HSW(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMH_HSW_SHIFT)) & LCD_TIMH_HSW_MASK)

#define LCD_TIMH_HFP_MASK                        (0xFF0000U)
#define LCD_TIMH_HFP_SHIFT                       (16U)
/*! HFP - Horizontal front porch. */
#define LCD_TIMH_HFP(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMH_HFP_SHIFT)) & LCD_TIMH_HFP_MASK)

#define LCD_TIMH_HBP_MASK                        (0xFF000000U)
#define LCD_TIMH_HBP_SHIFT                       (24U)
/*! HBP - Horizontal back porch. */
#define LCD_TIMH_HBP(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMH_HBP_SHIFT)) & LCD_TIMH_HBP_MASK)
/*! @} */

/*! @name TIMV - Vertical Timing Control register */
/*! @{ */

#define LCD_TIMV_LPP_MASK                        (0x3FFU)
#define LCD_TIMV_LPP_SHIFT                       (0U)
/*! LPP - Lines per panel. */
#define LCD_TIMV_LPP(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMV_LPP_SHIFT)) & LCD_TIMV_LPP_MASK)

#define LCD_TIMV_VSW_MASK                        (0xFC00U)
#define LCD_TIMV_VSW_SHIFT                       (10U)
/*! VSW - Vertical synchronization pulse width. */
#define LCD_TIMV_VSW(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMV_VSW_SHIFT)) & LCD_TIMV_VSW_MASK)

#define LCD_TIMV_VFP_MASK                        (0xFF0000U)
#define LCD_TIMV_VFP_SHIFT                       (16U)
/*! VFP - Vertical front porch. */
#define LCD_TIMV_VFP(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMV_VFP_SHIFT)) & LCD_TIMV_VFP_MASK)

#define LCD_TIMV_VBP_MASK                        (0xFF000000U)
#define LCD_TIMV_VBP_SHIFT                       (24U)
/*! VBP - Vertical back porch. */
#define LCD_TIMV_VBP(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_TIMV_VBP_SHIFT)) & LCD_TIMV_VBP_MASK)
/*! @} */

/*! @name POL - Clock and Signal Polarity Control register */
/*! @{ */

#define LCD_POL_PCD_LO_MASK                      (0x1FU)
#define LCD_POL_PCD_LO_SHIFT                     (0U)
/*! PCD_LO - Lower five bits of panel clock divisor. */
#define LCD_POL_PCD_LO(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_POL_PCD_LO_SHIFT)) & LCD_POL_PCD_LO_MASK)

#define LCD_POL_ACB_MASK                         (0x7C0U)
#define LCD_POL_ACB_SHIFT                        (6U)
/*! ACB - AC bias pin frequency. */
#define LCD_POL_ACB(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_ACB_SHIFT)) & LCD_POL_ACB_MASK)

#define LCD_POL_IVS_MASK                         (0x800U)
#define LCD_POL_IVS_SHIFT                        (11U)
/*! IVS - Invert vertical synchronization. */
#define LCD_POL_IVS(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_IVS_SHIFT)) & LCD_POL_IVS_MASK)

#define LCD_POL_IHS_MASK                         (0x1000U)
#define LCD_POL_IHS_SHIFT                        (12U)
/*! IHS - Invert horizontal synchronization. */
#define LCD_POL_IHS(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_IHS_SHIFT)) & LCD_POL_IHS_MASK)

#define LCD_POL_IPC_MASK                         (0x2000U)
#define LCD_POL_IPC_SHIFT                        (13U)
/*! IPC - Invert panel clock. */
#define LCD_POL_IPC(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_IPC_SHIFT)) & LCD_POL_IPC_MASK)

#define LCD_POL_IOE_MASK                         (0x4000U)
#define LCD_POL_IOE_SHIFT                        (14U)
/*! IOE - Invert output enable. */
#define LCD_POL_IOE(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_IOE_SHIFT)) & LCD_POL_IOE_MASK)

#define LCD_POL_CPL_MASK                         (0x3FF0000U)
#define LCD_POL_CPL_SHIFT                        (16U)
/*! CPL - Clocks per line. */
#define LCD_POL_CPL(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_CPL_SHIFT)) & LCD_POL_CPL_MASK)

#define LCD_POL_BCD_MASK                         (0x4000000U)
#define LCD_POL_BCD_SHIFT                        (26U)
/*! BCD - Bypass panel clock divider. */
#define LCD_POL_BCD(x)                           (((uint32_t)(((uint32_t)(x)) << LCD_POL_BCD_SHIFT)) & LCD_POL_BCD_MASK)

#define LCD_POL_PCD_HI_MASK                      (0xF8000000U)
#define LCD_POL_PCD_HI_SHIFT                     (27U)
/*! PCD_HI - Upper five bits of panel clock divisor. */
#define LCD_POL_PCD_HI(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_POL_PCD_HI_SHIFT)) & LCD_POL_PCD_HI_MASK)
/*! @} */

/*! @name LE - Line End Control register */
/*! @{ */

#define LCD_LE_LED_MASK                          (0x7FU)
#define LCD_LE_LED_SHIFT                         (0U)
/*! LED - Line-end delay. */
#define LCD_LE_LED(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_LE_LED_SHIFT)) & LCD_LE_LED_MASK)

#define LCD_LE_LEE_MASK                          (0x10000U)
#define LCD_LE_LEE_SHIFT                         (16U)
/*! LEE - LCD Line end enable. */
#define LCD_LE_LEE(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_LE_LEE_SHIFT)) & LCD_LE_LEE_MASK)
/*! @} */

/*! @name UPBASE - Upper Panel Frame Base Address register */
/*! @{ */

#define LCD_UPBASE_LCDUPBASE_MASK                (0xFFFFFFF8U)
#define LCD_UPBASE_LCDUPBASE_SHIFT               (3U)
/*! LCDUPBASE - LCD upper panel base address. */
#define LCD_UPBASE_LCDUPBASE(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_UPBASE_LCDUPBASE_SHIFT)) & LCD_UPBASE_LCDUPBASE_MASK)
/*! @} */

/*! @name LPBASE - Lower Panel Frame Base Address register */
/*! @{ */

#define LCD_LPBASE_LCDLPBASE_MASK                (0xFFFFFFF8U)
#define LCD_LPBASE_LCDLPBASE_SHIFT               (3U)
/*! LCDLPBASE - LCD lower panel base address. */
#define LCD_LPBASE_LCDLPBASE(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_LPBASE_LCDLPBASE_SHIFT)) & LCD_LPBASE_LCDLPBASE_MASK)
/*! @} */

/*! @name CTRL - LCD Control register */
/*! @{ */

#define LCD_CTRL_LCDEN_MASK                      (0x1U)
#define LCD_CTRL_LCDEN_SHIFT                     (0U)
/*! LCDEN - LCD enable control bit. */
#define LCD_CTRL_LCDEN(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDEN_SHIFT)) & LCD_CTRL_LCDEN_MASK)

#define LCD_CTRL_LCDBPP_MASK                     (0xEU)
#define LCD_CTRL_LCDBPP_SHIFT                    (1U)
/*! LCDBPP - LCD bits per pixel. */
#define LCD_CTRL_LCDBPP(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDBPP_SHIFT)) & LCD_CTRL_LCDBPP_MASK)

#define LCD_CTRL_LCDBW_MASK                      (0x10U)
#define LCD_CTRL_LCDBW_SHIFT                     (4U)
/*! LCDBW - STN LCD monochrome/color selection. */
#define LCD_CTRL_LCDBW(x)                        (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDBW_SHIFT)) & LCD_CTRL_LCDBW_MASK)

#define LCD_CTRL_LCDTFT_MASK                     (0x20U)
#define LCD_CTRL_LCDTFT_SHIFT                    (5U)
/*! LCDTFT - LCD panel TFT type selection. */
#define LCD_CTRL_LCDTFT(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDTFT_SHIFT)) & LCD_CTRL_LCDTFT_MASK)

#define LCD_CTRL_LCDMONO8_MASK                   (0x40U)
#define LCD_CTRL_LCDMONO8_SHIFT                  (6U)
/*! LCDMONO8 - Monochrome LCD interface width. */
#define LCD_CTRL_LCDMONO8(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDMONO8_SHIFT)) & LCD_CTRL_LCDMONO8_MASK)

#define LCD_CTRL_LCDDUAL_MASK                    (0x80U)
#define LCD_CTRL_LCDDUAL_SHIFT                   (7U)
/*! LCDDUAL - Single or Dual LCD panel selection. */
#define LCD_CTRL_LCDDUAL(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDDUAL_SHIFT)) & LCD_CTRL_LCDDUAL_MASK)

#define LCD_CTRL_BGR_MASK                        (0x100U)
#define LCD_CTRL_BGR_SHIFT                       (8U)
/*! BGR - Color format selection. */
#define LCD_CTRL_BGR(x)                          (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_BGR_SHIFT)) & LCD_CTRL_BGR_MASK)

#define LCD_CTRL_BEBO_MASK                       (0x200U)
#define LCD_CTRL_BEBO_SHIFT                      (9U)
/*! BEBO - Big-endian Byte Order. */
#define LCD_CTRL_BEBO(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_BEBO_SHIFT)) & LCD_CTRL_BEBO_MASK)

#define LCD_CTRL_BEPO_MASK                       (0x400U)
#define LCD_CTRL_BEPO_SHIFT                      (10U)
/*! BEPO - Big-Endian Pixel Ordering. */
#define LCD_CTRL_BEPO(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_BEPO_SHIFT)) & LCD_CTRL_BEPO_MASK)

#define LCD_CTRL_LCDPWR_MASK                     (0x800U)
#define LCD_CTRL_LCDPWR_SHIFT                    (11U)
/*! LCDPWR - LCD power enable. */
#define LCD_CTRL_LCDPWR(x)                       (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDPWR_SHIFT)) & LCD_CTRL_LCDPWR_MASK)

#define LCD_CTRL_LCDVCOMP_MASK                   (0x3000U)
#define LCD_CTRL_LCDVCOMP_SHIFT                  (12U)
/*! LCDVCOMP - LCD Vertical Compare Interrupt. */
#define LCD_CTRL_LCDVCOMP(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_LCDVCOMP_SHIFT)) & LCD_CTRL_LCDVCOMP_MASK)

#define LCD_CTRL_WATERMARK_MASK                  (0x10000U)
#define LCD_CTRL_WATERMARK_SHIFT                 (16U)
/*! WATERMARK - LCD DMA FIFO watermark level. */
#define LCD_CTRL_WATERMARK(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_CTRL_WATERMARK_SHIFT)) & LCD_CTRL_WATERMARK_MASK)
/*! @} */

/*! @name INTMSK - Interrupt Mask register */
/*! @{ */

#define LCD_INTMSK_FUFIM_MASK                    (0x2U)
#define LCD_INTMSK_FUFIM_SHIFT                   (1U)
/*! FUFIM - FIFO underflow interrupt enable. */
#define LCD_INTMSK_FUFIM(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_INTMSK_FUFIM_SHIFT)) & LCD_INTMSK_FUFIM_MASK)

#define LCD_INTMSK_LNBUIM_MASK                   (0x4U)
#define LCD_INTMSK_LNBUIM_SHIFT                  (2U)
/*! LNBUIM - LCD next base address update interrupt enable. */
#define LCD_INTMSK_LNBUIM(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_INTMSK_LNBUIM_SHIFT)) & LCD_INTMSK_LNBUIM_MASK)

#define LCD_INTMSK_VCOMPIM_MASK                  (0x8U)
#define LCD_INTMSK_VCOMPIM_SHIFT                 (3U)
/*! VCOMPIM - Vertical compare interrupt enable. */
#define LCD_INTMSK_VCOMPIM(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_INTMSK_VCOMPIM_SHIFT)) & LCD_INTMSK_VCOMPIM_MASK)

#define LCD_INTMSK_BERIM_MASK                    (0x10U)
#define LCD_INTMSK_BERIM_SHIFT                   (4U)
/*! BERIM - AHB master error interrupt enable. */
#define LCD_INTMSK_BERIM(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_INTMSK_BERIM_SHIFT)) & LCD_INTMSK_BERIM_MASK)
/*! @} */

/*! @name INTRAW - Raw Interrupt Status register */
/*! @{ */

#define LCD_INTRAW_FUFRIS_MASK                   (0x2U)
#define LCD_INTRAW_FUFRIS_SHIFT                  (1U)
/*! FUFRIS - FIFO underflow raw interrupt status. */
#define LCD_INTRAW_FUFRIS(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_INTRAW_FUFRIS_SHIFT)) & LCD_INTRAW_FUFRIS_MASK)

#define LCD_INTRAW_LNBURIS_MASK                  (0x4U)
#define LCD_INTRAW_LNBURIS_SHIFT                 (2U)
/*! LNBURIS - LCD next address base update raw interrupt status. */
#define LCD_INTRAW_LNBURIS(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_INTRAW_LNBURIS_SHIFT)) & LCD_INTRAW_LNBURIS_MASK)

#define LCD_INTRAW_VCOMPRIS_MASK                 (0x8U)
#define LCD_INTRAW_VCOMPRIS_SHIFT                (3U)
/*! VCOMPRIS - Vertical compare raw interrupt status. */
#define LCD_INTRAW_VCOMPRIS(x)                   (((uint32_t)(((uint32_t)(x)) << LCD_INTRAW_VCOMPRIS_SHIFT)) & LCD_INTRAW_VCOMPRIS_MASK)

#define LCD_INTRAW_BERRAW_MASK                   (0x10U)
#define LCD_INTRAW_BERRAW_SHIFT                  (4U)
/*! BERRAW - AHB master bus error raw interrupt status. */
#define LCD_INTRAW_BERRAW(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_INTRAW_BERRAW_SHIFT)) & LCD_INTRAW_BERRAW_MASK)
/*! @} */

/*! @name INTSTAT - Masked Interrupt Status register */
/*! @{ */

#define LCD_INTSTAT_FUFMIS_MASK                  (0x2U)
#define LCD_INTSTAT_FUFMIS_SHIFT                 (1U)
/*! FUFMIS - FIFO underflow masked interrupt status. */
#define LCD_INTSTAT_FUFMIS(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_INTSTAT_FUFMIS_SHIFT)) & LCD_INTSTAT_FUFMIS_MASK)

#define LCD_INTSTAT_LNBUMIS_MASK                 (0x4U)
#define LCD_INTSTAT_LNBUMIS_SHIFT                (2U)
/*! LNBUMIS - LCD next address base update masked interrupt status. */
#define LCD_INTSTAT_LNBUMIS(x)                   (((uint32_t)(((uint32_t)(x)) << LCD_INTSTAT_LNBUMIS_SHIFT)) & LCD_INTSTAT_LNBUMIS_MASK)

#define LCD_INTSTAT_VCOMPMIS_MASK                (0x8U)
#define LCD_INTSTAT_VCOMPMIS_SHIFT               (3U)
/*! VCOMPMIS - Vertical compare masked interrupt status. */
#define LCD_INTSTAT_VCOMPMIS(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_INTSTAT_VCOMPMIS_SHIFT)) & LCD_INTSTAT_VCOMPMIS_MASK)

#define LCD_INTSTAT_BERMIS_MASK                  (0x10U)
#define LCD_INTSTAT_BERMIS_SHIFT                 (4U)
/*! BERMIS - AHB master bus error masked interrupt status. */
#define LCD_INTSTAT_BERMIS(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_INTSTAT_BERMIS_SHIFT)) & LCD_INTSTAT_BERMIS_MASK)
/*! @} */

/*! @name INTCLR - Interrupt Clear register */
/*! @{ */

#define LCD_INTCLR_FUFIC_MASK                    (0x2U)
#define LCD_INTCLR_FUFIC_SHIFT                   (1U)
/*! FUFIC - FIFO underflow interrupt clear. */
#define LCD_INTCLR_FUFIC(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_INTCLR_FUFIC_SHIFT)) & LCD_INTCLR_FUFIC_MASK)

#define LCD_INTCLR_LNBUIC_MASK                   (0x4U)
#define LCD_INTCLR_LNBUIC_SHIFT                  (2U)
/*! LNBUIC - LCD next address base update interrupt clear. */
#define LCD_INTCLR_LNBUIC(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_INTCLR_LNBUIC_SHIFT)) & LCD_INTCLR_LNBUIC_MASK)

#define LCD_INTCLR_VCOMPIC_MASK                  (0x8U)
#define LCD_INTCLR_VCOMPIC_SHIFT                 (3U)
/*! VCOMPIC - Vertical compare interrupt clear. */
#define LCD_INTCLR_VCOMPIC(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_INTCLR_VCOMPIC_SHIFT)) & LCD_INTCLR_VCOMPIC_MASK)

#define LCD_INTCLR_BERIC_MASK                    (0x10U)
#define LCD_INTCLR_BERIC_SHIFT                   (4U)
/*! BERIC - AHB master error interrupt clear. */
#define LCD_INTCLR_BERIC(x)                      (((uint32_t)(((uint32_t)(x)) << LCD_INTCLR_BERIC_SHIFT)) & LCD_INTCLR_BERIC_MASK)
/*! @} */

/*! @name UPCURR - Upper Panel Current Address Value register */
/*! @{ */

#define LCD_UPCURR_LCDUPCURR_MASK                (0xFFFFFFFFU)
#define LCD_UPCURR_LCDUPCURR_SHIFT               (0U)
/*! LCDUPCURR - LCD Upper Panel Current Address. */
#define LCD_UPCURR_LCDUPCURR(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_UPCURR_LCDUPCURR_SHIFT)) & LCD_UPCURR_LCDUPCURR_MASK)
/*! @} */

/*! @name LPCURR - Lower Panel Current Address Value register */
/*! @{ */

#define LCD_LPCURR_LCDLPCURR_MASK                (0xFFFFFFFFU)
#define LCD_LPCURR_LCDLPCURR_SHIFT               (0U)
/*! LCDLPCURR - LCD Lower Panel Current Address. */
#define LCD_LPCURR_LCDLPCURR(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_LPCURR_LCDLPCURR_SHIFT)) & LCD_LPCURR_LCDLPCURR_MASK)
/*! @} */

/*! @name PAL - 256x16-bit Color Palette registers */
/*! @{ */

#define LCD_PAL_R04_0_MASK                       (0x1FU)
#define LCD_PAL_R04_0_SHIFT                      (0U)
/*! R04_0 - Red palette data. */
#define LCD_PAL_R04_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_R04_0_SHIFT)) & LCD_PAL_R04_0_MASK)

#define LCD_PAL_G04_0_MASK                       (0x3E0U)
#define LCD_PAL_G04_0_SHIFT                      (5U)
/*! G04_0 - Green palette data. */
#define LCD_PAL_G04_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_G04_0_SHIFT)) & LCD_PAL_G04_0_MASK)

#define LCD_PAL_B04_0_MASK                       (0x7C00U)
#define LCD_PAL_B04_0_SHIFT                      (10U)
/*! B04_0 - Blue palette data. */
#define LCD_PAL_B04_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_B04_0_SHIFT)) & LCD_PAL_B04_0_MASK)

#define LCD_PAL_I0_MASK                          (0x8000U)
#define LCD_PAL_I0_SHIFT                         (15U)
/*! I0 - Intensity / unused bit. */
#define LCD_PAL_I0(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_PAL_I0_SHIFT)) & LCD_PAL_I0_MASK)

#define LCD_PAL_R14_0_MASK                       (0x1F0000U)
#define LCD_PAL_R14_0_SHIFT                      (16U)
/*! R14_0 - Red palette data. */
#define LCD_PAL_R14_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_R14_0_SHIFT)) & LCD_PAL_R14_0_MASK)

#define LCD_PAL_G14_0_MASK                       (0x3E00000U)
#define LCD_PAL_G14_0_SHIFT                      (21U)
/*! G14_0 - Green palette data. */
#define LCD_PAL_G14_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_G14_0_SHIFT)) & LCD_PAL_G14_0_MASK)

#define LCD_PAL_B14_0_MASK                       (0x7C000000U)
#define LCD_PAL_B14_0_SHIFT                      (26U)
/*! B14_0 - Blue palette data. */
#define LCD_PAL_B14_0(x)                         (((uint32_t)(((uint32_t)(x)) << LCD_PAL_B14_0_SHIFT)) & LCD_PAL_B14_0_MASK)

#define LCD_PAL_I1_MASK                          (0x80000000U)
#define LCD_PAL_I1_SHIFT                         (31U)
/*! I1 - Intensity / unused bit. */
#define LCD_PAL_I1(x)                            (((uint32_t)(((uint32_t)(x)) << LCD_PAL_I1_SHIFT)) & LCD_PAL_I1_MASK)
/*! @} */

/*! @name CRSR_IMG - Cursor Image registers */
/*! @{ */

#define LCD_CRSR_IMG_CRSR_IMG_MASK               (0xFFFFFFFFU)
#define LCD_CRSR_IMG_CRSR_IMG_SHIFT              (0U)
/*! CRSR_IMG - Cursor Image data. */
#define LCD_CRSR_IMG_CRSR_IMG(x)                 (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_IMG_CRSR_IMG_SHIFT)) & LCD_CRSR_IMG_CRSR_IMG_MASK)
/*! @} */

/*! @name CRSR_CTRL - Cursor Control register */
/*! @{ */

#define LCD_CRSR_CTRL_CRSRON_MASK                (0x1U)
#define LCD_CRSR_CTRL_CRSRON_SHIFT               (0U)
/*! CRSRON - Cursor enable. */
#define LCD_CRSR_CTRL_CRSRON(x)                  (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CTRL_CRSRON_SHIFT)) & LCD_CRSR_CTRL_CRSRON_MASK)

#define LCD_CRSR_CTRL_CRSRNUM1_0_MASK            (0x30U)
#define LCD_CRSR_CTRL_CRSRNUM1_0_SHIFT           (4U)
/*! CRSRNUM1_0 - Cursor image number. */
#define LCD_CRSR_CTRL_CRSRNUM1_0(x)              (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CTRL_CRSRNUM1_0_SHIFT)) & LCD_CRSR_CTRL_CRSRNUM1_0_MASK)
/*! @} */

/*! @name CRSR_CFG - Cursor Configuration register */
/*! @{ */

#define LCD_CRSR_CFG_CRSRSIZE_MASK               (0x1U)
#define LCD_CRSR_CFG_CRSRSIZE_SHIFT              (0U)
/*! CRSRSIZE - Cursor size selection. */
#define LCD_CRSR_CFG_CRSRSIZE(x)                 (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CFG_CRSRSIZE_SHIFT)) & LCD_CRSR_CFG_CRSRSIZE_MASK)

#define LCD_CRSR_CFG_FRAMESYNC_MASK              (0x2U)
#define LCD_CRSR_CFG_FRAMESYNC_SHIFT             (1U)
/*! FRAMESYNC - Cursor frame synchronization type. */
#define LCD_CRSR_CFG_FRAMESYNC(x)                (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CFG_FRAMESYNC_SHIFT)) & LCD_CRSR_CFG_FRAMESYNC_MASK)
/*! @} */

/*! @name CRSR_PAL0 - Cursor Palette register 0 */
/*! @{ */

#define LCD_CRSR_PAL0_RED_MASK                   (0xFFU)
#define LCD_CRSR_PAL0_RED_SHIFT                  (0U)
/*! RED - Red color component. */
#define LCD_CRSR_PAL0_RED(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL0_RED_SHIFT)) & LCD_CRSR_PAL0_RED_MASK)

#define LCD_CRSR_PAL0_GREEN_MASK                 (0xFF00U)
#define LCD_CRSR_PAL0_GREEN_SHIFT                (8U)
/*! GREEN - Green color component. */
#define LCD_CRSR_PAL0_GREEN(x)                   (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL0_GREEN_SHIFT)) & LCD_CRSR_PAL0_GREEN_MASK)

#define LCD_CRSR_PAL0_BLUE_MASK                  (0xFF0000U)
#define LCD_CRSR_PAL0_BLUE_SHIFT                 (16U)
/*! BLUE - Blue color component. */
#define LCD_CRSR_PAL0_BLUE(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL0_BLUE_SHIFT)) & LCD_CRSR_PAL0_BLUE_MASK)
/*! @} */

/*! @name CRSR_PAL1 - Cursor Palette register 1 */
/*! @{ */

#define LCD_CRSR_PAL1_RED_MASK                   (0xFFU)
#define LCD_CRSR_PAL1_RED_SHIFT                  (0U)
/*! RED - Red color component. */
#define LCD_CRSR_PAL1_RED(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL1_RED_SHIFT)) & LCD_CRSR_PAL1_RED_MASK)

#define LCD_CRSR_PAL1_GREEN_MASK                 (0xFF00U)
#define LCD_CRSR_PAL1_GREEN_SHIFT                (8U)
/*! GREEN - Green color component. */
#define LCD_CRSR_PAL1_GREEN(x)                   (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL1_GREEN_SHIFT)) & LCD_CRSR_PAL1_GREEN_MASK)

#define LCD_CRSR_PAL1_BLUE_MASK                  (0xFF0000U)
#define LCD_CRSR_PAL1_BLUE_SHIFT                 (16U)
/*! BLUE - Blue color component. */
#define LCD_CRSR_PAL1_BLUE(x)                    (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_PAL1_BLUE_SHIFT)) & LCD_CRSR_PAL1_BLUE_MASK)
/*! @} */

/*! @name CRSR_XY - Cursor XY Position register */
/*! @{ */

#define LCD_CRSR_XY_CRSRX_MASK                   (0x3FFU)
#define LCD_CRSR_XY_CRSRX_SHIFT                  (0U)
/*! CRSRX - X ordinate of the cursor origin measured in pixels. */
#define LCD_CRSR_XY_CRSRX(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_XY_CRSRX_SHIFT)) & LCD_CRSR_XY_CRSRX_MASK)

#define LCD_CRSR_XY_CRSRY_MASK                   (0x3FF0000U)
#define LCD_CRSR_XY_CRSRY_SHIFT                  (16U)
/*! CRSRY - Y ordinate of the cursor origin measured in pixels. */
#define LCD_CRSR_XY_CRSRY(x)                     (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_XY_CRSRY_SHIFT)) & LCD_CRSR_XY_CRSRY_MASK)
/*! @} */

/*! @name CRSR_CLIP - Cursor Clip Position register */
/*! @{ */

#define LCD_CRSR_CLIP_CRSRCLIPX_MASK             (0x3FU)
#define LCD_CRSR_CLIP_CRSRCLIPX_SHIFT            (0U)
/*! CRSRCLIPX - Cursor clip position for X direction. */
#define LCD_CRSR_CLIP_CRSRCLIPX(x)               (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CLIP_CRSRCLIPX_SHIFT)) & LCD_CRSR_CLIP_CRSRCLIPX_MASK)

#define LCD_CRSR_CLIP_CRSRCLIPY_MASK             (0x3F00U)
#define LCD_CRSR_CLIP_CRSRCLIPY_SHIFT            (8U)
/*! CRSRCLIPY - Cursor clip position for Y direction. */
#define LCD_CRSR_CLIP_CRSRCLIPY(x)               (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_CLIP_CRSRCLIPY_SHIFT)) & LCD_CRSR_CLIP_CRSRCLIPY_MASK)
/*! @} */

/*! @name CRSR_INTMSK - Cursor Interrupt Mask register */
/*! @{ */

#define LCD_CRSR_INTMSK_CRSRIM_MASK              (0x1U)
#define LCD_CRSR_INTMSK_CRSRIM_SHIFT             (0U)
/*! CRSRIM - Cursor interrupt mask. */
#define LCD_CRSR_INTMSK_CRSRIM(x)                (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_INTMSK_CRSRIM_SHIFT)) & LCD_CRSR_INTMSK_CRSRIM_MASK)
/*! @} */

/*! @name CRSR_INTCLR - Cursor Interrupt Clear register */
/*! @{ */

#define LCD_CRSR_INTCLR_CRSRIC_MASK              (0x1U)
#define LCD_CRSR_INTCLR_CRSRIC_SHIFT             (0U)
/*! CRSRIC - Cursor interrupt clear. */
#define LCD_CRSR_INTCLR_CRSRIC(x)                (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_INTCLR_CRSRIC_SHIFT)) & LCD_CRSR_INTCLR_CRSRIC_MASK)
/*! @} */

/*! @name CRSR_INTRAW - Cursor Raw Interrupt Status register */
/*! @{ */

#define LCD_CRSR_INTRAW_CRSRRIS_MASK             (0x1U)
#define LCD_CRSR_INTRAW_CRSRRIS_SHIFT            (0U)
/*! CRSRRIS - Cursor raw interrupt status. */
#define LCD_CRSR_INTRAW_CRSRRIS(x)               (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_INTRAW_CRSRRIS_SHIFT)) & LCD_CRSR_INTRAW_CRSRRIS_MASK)
/*! @} */

/*! @name CRSR_INTSTAT - Cursor Masked Interrupt Status register */
/*! @{ */

#define LCD_CRSR_INTSTAT_CRSRMIS_MASK            (0x1U)
#define LCD_CRSR_INTSTAT_CRSRMIS_SHIFT           (0U)
/*! CRSRMIS - Cursor masked interrupt status. */
#define LCD_CRSR_INTSTAT_CRSRMIS(x)              (((uint32_t)(((uint32_t)(x)) << LCD_CRSR_INTSTAT_CRSRMIS_SHIFT)) & LCD_CRSR_INTSTAT_CRSRMIS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LCD_Register_Masks */


/*!
 * @}
 */ /* end of group LCD_Peripheral_Access_Layer */


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


#endif  /* PERI_LCD_H_ */

