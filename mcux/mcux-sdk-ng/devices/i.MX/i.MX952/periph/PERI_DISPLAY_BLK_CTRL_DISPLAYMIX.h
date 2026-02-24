/*
** ###################################################################
**     Processors:          MIMX95294AVTN_ca55
**                          MIMX95294AVTN_cm33
**                          MIMX95294AVTN_cm7
**                          MIMX95294AVYN_ca55
**                          MIMX95294AVYN_cm33
**                          MIMX95294AVYN_cm7
**                          MIMX95294AVZN_ca55
**                          MIMX95294AVZN_cm33
**                          MIMX95294AVZN_cm7
**                          MIMX95294CVTN_ca55
**                          MIMX95294CVTN_cm33
**                          MIMX95294CVTN_cm7
**                          MIMX95294CVYN_ca55
**                          MIMX95294CVYN_cm33
**                          MIMX95294CVYN_cm7
**                          MIMX95294CVZN_ca55
**                          MIMX95294CVZN_cm33
**                          MIMX95294CVZN_cm7
**                          MIMX95294DVTN_ca55
**                          MIMX95294DVTN_cm33
**                          MIMX95294DVTN_cm7
**                          MIMX95294DVYN_ca55
**                          MIMX95294DVYN_cm33
**                          MIMX95294DVYN_cm7
**                          MIMX95294DVZN_ca55
**                          MIMX95294DVZN_cm33
**                          MIMX95294DVZN_cm7
**                          MIMX95294XVTN_ca55
**                          MIMX95294XVTN_cm33
**                          MIMX95294XVTN_cm7
**                          MIMX95294XVYN_ca55
**                          MIMX95294XVYN_cm33
**                          MIMX95294XVYN_cm7
**                          MIMX95294XVZN_ca55
**                          MIMX95294XVZN_cm33
**                          MIMX95294XVZN_cm7
**
**     Version:             rev. 2.0, 2024-10-29
**     Build:               b250903
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_DISPLAY_BLK_CTRL_DISPLAYMIX.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
 *
 * CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
 */

#if !defined(PERI_DISPLAY_BLK_CTRL_DISPLAYMIX_H_)
#define PERI_DISPLAY_BLK_CTRL_DISPLAYMIX_H_      /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX95294AVTN_ca55) || defined(CPU_MIMX95294AVYN_ca55) || defined(CPU_MIMX95294AVZN_ca55) || defined(CPU_MIMX95294CVTN_ca55) || defined(CPU_MIMX95294CVYN_ca55) || defined(CPU_MIMX95294CVZN_ca55) || defined(CPU_MIMX95294DVTN_ca55) || defined(CPU_MIMX95294DVYN_ca55) || defined(CPU_MIMX95294DVZN_ca55) || defined(CPU_MIMX95294XVTN_ca55) || defined(CPU_MIMX95294XVYN_ca55) || defined(CPU_MIMX95294XVZN_ca55))
#include "MIMX95294_ca55_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm33) || defined(CPU_MIMX95294AVYN_cm33) || defined(CPU_MIMX95294AVZN_cm33) || defined(CPU_MIMX95294CVTN_cm33) || defined(CPU_MIMX95294CVYN_cm33) || defined(CPU_MIMX95294CVZN_cm33) || defined(CPU_MIMX95294DVTN_cm33) || defined(CPU_MIMX95294DVYN_cm33) || defined(CPU_MIMX95294DVZN_cm33) || defined(CPU_MIMX95294XVTN_cm33) || defined(CPU_MIMX95294XVYN_cm33) || defined(CPU_MIMX95294XVZN_cm33))
#include "MIMX95294_cm33_COMMON.h"
#elif (defined(CPU_MIMX95294AVTN_cm7) || defined(CPU_MIMX95294AVYN_cm7) || defined(CPU_MIMX95294AVZN_cm7) || defined(CPU_MIMX95294CVTN_cm7) || defined(CPU_MIMX95294CVYN_cm7) || defined(CPU_MIMX95294CVZN_cm7) || defined(CPU_MIMX95294DVTN_cm7) || defined(CPU_MIMX95294DVYN_cm7) || defined(CPU_MIMX95294DVZN_cm7) || defined(CPU_MIMX95294XVTN_cm7) || defined(CPU_MIMX95294XVYN_cm7) || defined(CPU_MIMX95294XVZN_cm7))
#include "MIMX95294_cm7_COMMON.h"
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
   -- DISPLAY_BLK_CTRL_DISPLAYMIX Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_BLK_CTRL_DISPLAYMIX_Peripheral_Access_Layer DISPLAY_BLK_CTRL_DISPLAYMIX Peripheral Access Layer
 * @{
 */

/** DISPLAY_BLK_CTRL_DISPLAYMIX - Register Layout Typedef */
typedef struct {
  __IO uint32_t LPCG_CONTROL;                      /**< Display OCRAM Clock Control, offset: 0x0 */
  __IO uint32_t DISPLAY_ENGINES_CLOCK_CONTROL;     /**< Display Engines Clock Control, offset: 0x4 */
  __IO uint32_t PIXEL_INTERLEAVER_CONTROL;         /**< Pixel Interleaver Control, offset: 0x8 */
  __IO uint32_t PIXEL_LINK_CTRL;                   /**< Pixel Link Control, offset: 0xC */
  __IO uint32_t AXCACHE_CONTROL;                   /**< AxCache Control, offset: 0x10 */
  __IO uint32_t QOS_SETTING;                       /**< QoS Setting, offset: 0x14 */
  __IO uint32_t DISPLAYENGINE_PLANE_ASSOCIATION;   /**< Display Engine Plane Association, offset: 0x18 */
       uint8_t RESERVED_0[40];
  __IO uint32_t LD_HSYNC_GEN;                      /**< Local Dimming HSYNC signal Setting, offset: 0x44 */
  __IO uint32_t LD_VSYNC_STRETCH;                  /**< Local Dimming VSYNC signal pulse stretching, offset: 0x48 */
} DISPLAY_BLK_CTRL_DISPLAYMIX_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_BLK_CTRL_DISPLAYMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_BLK_CTRL_DISPLAYMIX_Register_Masks DISPLAY_BLK_CTRL_DISPLAYMIX Register Masks
 * @{
 */

/*! @name LPCG_CONTROL - Display OCRAM Clock Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LPCG_CONTROL_DISP_OCRAM_CLK_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LPCG_CONTROL_DISP_OCRAM_CLK_SHIFT (0U)
/*! DISP_OCRAM_CLK - Display OCRAM Clock Control
 *  0b0..Clock is not gated
 *  0b1..Clock is gated
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LPCG_CONTROL_DISP_OCRAM_CLK(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LPCG_CONTROL_DISP_OCRAM_CLK_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LPCG_CONTROL_DISP_OCRAM_CLK_MASK)
/*! @} */

/*! @name DISPLAY_ENGINES_CLOCK_CONTROL - Display Engines Clock Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_MASK (0x3U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_SHIFT (0U)
/*! DSIP_CLK0_SEL - Display Engine 0 Feeding Clock Select
 *  0b00..CCM.video_pll_clk
 *  0b01..DSI PLL Div clock
 *  0b10..LVDS PLL Div/7 clock
 *  0b11..Reserved
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_MASK (0xCU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_SHIFT (2U)
/*! DSIP_CLK1_SEL - Display Engine 1 Feeding Clock Select
 *  0b00..CCM.video_pll_clk
 *  0b01..DSI PLL Div clock
 *  0b10..LVDS PLL Div/7 clock
 *  0b11..Reserved
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_MASK)
/*! @} */

/*! @name PIXEL_INTERLEAVER_CONTROL - Pixel Interleaver Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_SHIFT (0U)
/*! Mode - Pixel Interleaver Mode Select
 *  0b0..In bypass mode
 *  0b1..In split mode #2
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_MASK (0x2U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_SHIFT (1U)
/*! Disp_in_sel - Display Input Stream Select
 *  0b0..Display input stream 0 is interleaved
 *  0b1..Display input stream 1 is interleaved
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_MASK)
/*! @} */

/*! @name PIXEL_LINK_CTRL - Pixel Link Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_SHIFT (0U)
/*! PL0_enable - Pixel Link 0 Enable
 *  0b0..Do not start Pixel Link 0
 *  0b1..Start Pixel Link 0
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_MASK (0x2U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_SHIFT (1U)
/*! PL0_valid - Pixel Link 0 Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_MASK (0x100U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_SHIFT (8U)
/*! PL1_enable - Pixel Link 1 Enable
 *  0b0..Do not start Pixel Link 1
 *  0b1..Start Pixel Link 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_MASK (0x200U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_SHIFT (9U)
/*! PL1_valid - Pixel Link 1 Valid
 *  0b0..Invalid
 *  0b1..Valid
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_MASK)
/*! @} */

/*! @name AXCACHE_CONTROL - AxCache Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_MASK (0xFU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_SHIFT (0U)
/*! ArCache - AXI Read Initiator Port (Blitter Output) ArCache Signal Enable */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_MASK (0xF00U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_SHIFT (8U)
/*! AwCache - AXI Write Initiator Port (Blitter Output) AwCache Signal Enable */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_MASK (0xF0000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_SHIFT (16U)
/*! CmdSeq_ArCache - AXI Read Initiator Port (Command Sequencer) ArCache Signal Enable */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_MASK (0xF00000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_SHIFT (20U)
/*! CmdSeq_AwCache - AXI Write Initiator Port (Command Sequencer) AwCache Signal Enable */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_MASK)
/*! @} */

/*! @name QOS_SETTING - QoS Setting */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_MASK (0x7U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_SHIFT (0U)
/*! Display_ArQoS - Display FIFO Default Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_MASK (0x70U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_SHIFT (4U)
/*! Display_Panic_QoS - Display FIFO Panic Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_MASK (0x700U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_SHIFT (8U)
/*! Blitter_AxQoS - Blitter AXI Read and Write Initiator Port Default Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_Panic_AxQoS_MASK (0x7000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_Panic_AxQoS_SHIFT (12U)
/*! Blitter_Panic_AxQoS - Blitter AXI Read and Write Initiator Port Panic Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_Panic_AxQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_Panic_AxQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_Panic_AxQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_MASK (0x70000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_SHIFT (16U)
/*! CmdSeq_QoS - Command Sequencer AXI Read and Write Initiator Port Default Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_QoS_MASK (0x700000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_QoS_SHIFT (20U)
/*! CmdSeq_Panic_QoS - Command Sequencer AXI Read and Write Initiator Port Panic Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_QoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_QoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_QoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_AwQoS_MASK (0x7000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_AwQoS_SHIFT (24U)
/*! CmdSeq_AwQoS - Command Sequencer AXI Write Initiator Port Default Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_AwQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_AwQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_AwQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_AwQoS_MASK (0x70000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_AwQoS_SHIFT (28U)
/*! CmdSeq_Panic_AwQoS - Command Sequencer AXI Write Initiator Port Panic Priority Level */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_AwQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_AwQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_Panic_AwQoS_MASK)
/*! @} */

/*! @name DISPLAYENGINE_PLANE_ASSOCIATION - Display Engine Plane Association */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_SHIFT (0U)
/*! FracPlane_0 - FetchLayer#0
 *  0b0..Display Engine 0
 *  0b1..Display Engine 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_MASK (0x4U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_SHIFT (2U)
/*! FracPlane_1 - FetchLayer#1
 *  0b0..Display Engine 0
 *  0b1..Display Engine 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_MASK (0x40U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_SHIFT (6U)
/*! IntPlane_0 - FetchYUV#4
 *  0b0..Display Engine 0
 *  0b1..Display Engine 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_MASK (0x100U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_SHIFT (8U)
/*! VideoPlane_0 - FetchYUV#0 + FetchEco#0
 *  0b0..Display Engine 0
 *  0b1..Display Engine 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_MASK (0x400U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_SHIFT (10U)
/*! VideoPlane_1 - FetchYUV#1 + FetchEco#1
 *  0b0..Display Engine 0
 *  0b1..Display Engine 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_MASK)
/*! @} */

/*! @name LD_HSYNC_GEN - Local Dimming HSYNC signal Setting */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_MASK (0x1FFFFU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_SHIFT (0U)
/*! CLK_DIV - Local Dimming HSYNC signal Clock Division Factor */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_CLKOUT_MASK (0x80000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_CLKOUT_SHIFT (31U)
/*! CLK_DIV_CLKOUT - Local Dimming HSYNC signal Clock Gate
 *  0b0..Not gated
 *  0b1..Gated
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_CLKOUT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_CLKOUT_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_HSYNC_GEN_CLK_DIV_CLKOUT_MASK)
/*! @} */

/*! @name LD_VSYNC_STRETCH - Local Dimming VSYNC signal pulse stretching */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_MASK (0xFFFU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_SHIFT (0U)
/*! STRETCH_HOLD - Local Dimming VSYNC signal Pulse Stretch Period */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_EN_MASK (0x20000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_EN_SHIFT (29U)
/*! STRETCH_HOLD_EN - Local Dimming VSYNC pulse stretch hold time enable */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_EN(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_EN_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_STRETCH_HOLD_EN_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_POLARITY_REVERT_MASK (0x40000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_POLARITY_REVERT_SHIFT (30U)
/*! POLARITY_REVERT - Revert Polarity of Local Dimming VSYNC
 *  0b0..No Revert Polarity of Local Dimming VSYNC
 *  0b1..Revert Polarity of Local Dimming VSYNC
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_POLARITY_REVERT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_POLARITY_REVERT_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_POLARITY_REVERT_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_BYPASS_STRETCH_MASK (0x80000000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_BYPASS_STRETCH_SHIFT (31U)
/*! BYPASS_STRETCH - Bypass Local Dimming VSYNC Stretch logic
 *  0b0..Use stretched VSYNC
 *  0b1..Bypass and use Seeris output VSYNC
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_BYPASS_STRETCH(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_BYPASS_STRETCH_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_LD_VSYNC_STRETCH_BYPASS_STRETCH_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_BLK_CTRL_DISPLAYMIX_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_BLK_CTRL_DISPLAYMIX_Peripheral_Access_Layer */


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


#endif  /* PERI_DISPLAY_BLK_CTRL_DISPLAYMIX_H_ */

