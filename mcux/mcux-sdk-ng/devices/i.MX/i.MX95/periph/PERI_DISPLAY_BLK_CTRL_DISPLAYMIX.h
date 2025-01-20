/*
** ###################################################################
**     Processors:          MIMX9594AVZXN_ca55
**                          MIMX9594AVZXN_cm33
**                          MIMX9594AVZXN_cm7
**                          MIMX9596AVTXN_ca55
**                          MIMX9596AVTXN_cm33
**                          MIMX9596AVTXN_cm7
**                          MIMX9596AVYXN_ca55
**                          MIMX9596AVYXN_cm33
**                          MIMX9596AVYXN_cm7
**                          MIMX9596AVZXN_ca55
**                          MIMX9596AVZXN_cm33
**                          MIMX9596AVZXN_cm7
**                          MIMX9596CVTXN_ca55
**                          MIMX9596CVTXN_cm33
**                          MIMX9596CVTXN_cm7
**                          MIMX9596CVYXN_ca55
**                          MIMX9596CVYXN_cm33
**                          MIMX9596CVYXN_cm7
**                          MIMX9596CVZXN_ca55
**                          MIMX9596CVZXN_cm33
**                          MIMX9596CVZXN_cm7
**                          MIMX9596DVTXN_ca55
**                          MIMX9596DVTXN_cm33
**                          MIMX9596DVTXN_cm7
**                          MIMX9596DVYXN_ca55
**                          MIMX9596DVYXN_cm33
**                          MIMX9596DVYXN_cm7
**                          MIMX9596DVYXQ_ca55
**                          MIMX9596DVYXQ_cm33
**                          MIMX9596DVYXQ_cm7
**                          MIMX9596DVZXN_ca55
**                          MIMX9596DVZXN_cm33
**                          MIMX9596DVZXN_cm7
**                          MIMX9596XVTXN_ca55
**                          MIMX9596XVTXN_cm33
**                          MIMX9596XVTXN_cm7
**                          MIMX9596XVYXN_ca55
**                          MIMX9596XVYXN_cm33
**                          MIMX9596XVYXN_cm7
**                          MIMX9596XVZXN_ca55
**                          MIMX9596XVZXN_cm33
**                          MIMX9596XVZXN_cm7
**
**     Version:             rev. 1.0, 2023-01-10
**     Build:               b240728
**
**     Abstract:
**         CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2024 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2023-01-10)
**         Initial version.
**
** ###################################################################
*/

/*!
 * @file DISPLAY_BLK_CTRL_DISPLAYMIX.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
 *
 * CMSIS Peripheral Access Layer for DISPLAY_BLK_CTRL_DISPLAYMIX
 */

#if !defined(DISPLAY_BLK_CTRL_DISPLAYMIX_H_)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_H_           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX9594AVZXN_ca55))
#include "MIMX9594_ca55_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm33))
#include "MIMX9594_cm33_COMMON.h"
#elif (defined(CPU_MIMX9594AVZXN_cm7))
#include "MIMX9594_cm7_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_ca55) || defined(CPU_MIMX9596AVYXN_ca55) || defined(CPU_MIMX9596AVZXN_ca55) || defined(CPU_MIMX9596CVTXN_ca55) || defined(CPU_MIMX9596CVYXN_ca55) || defined(CPU_MIMX9596CVZXN_ca55) || defined(CPU_MIMX9596DVTXN_ca55) || defined(CPU_MIMX9596DVYXN_ca55) || defined(CPU_MIMX9596DVYXQ_ca55) || defined(CPU_MIMX9596DVZXN_ca55) || defined(CPU_MIMX9596XVTXN_ca55) || defined(CPU_MIMX9596XVYXN_ca55) || defined(CPU_MIMX9596XVZXN_ca55))
#include "MIMX9596_ca55_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm33) || defined(CPU_MIMX9596AVYXN_cm33) || defined(CPU_MIMX9596AVZXN_cm33) || defined(CPU_MIMX9596CVTXN_cm33) || defined(CPU_MIMX9596CVYXN_cm33) || defined(CPU_MIMX9596CVZXN_cm33) || defined(CPU_MIMX9596DVTXN_cm33) || defined(CPU_MIMX9596DVYXN_cm33) || defined(CPU_MIMX9596DVYXQ_cm33) || defined(CPU_MIMX9596DVZXN_cm33) || defined(CPU_MIMX9596XVTXN_cm33) || defined(CPU_MIMX9596XVYXN_cm33) || defined(CPU_MIMX9596XVZXN_cm33))
#include "MIMX9596_cm33_COMMON.h"
#elif (defined(CPU_MIMX9596AVTXN_cm7) || defined(CPU_MIMX9596AVYXN_cm7) || defined(CPU_MIMX9596AVZXN_cm7) || defined(CPU_MIMX9596CVTXN_cm7) || defined(CPU_MIMX9596CVYXN_cm7) || defined(CPU_MIMX9596CVZXN_cm7) || defined(CPU_MIMX9596DVTXN_cm7) || defined(CPU_MIMX9596DVYXN_cm7) || defined(CPU_MIMX9596DVYXQ_cm7) || defined(CPU_MIMX9596DVZXN_cm7) || defined(CPU_MIMX9596XVTXN_cm7) || defined(CPU_MIMX9596XVYXN_cm7) || defined(CPU_MIMX9596XVZXN_cm7))
#include "MIMX9596_cm7_COMMON.h"
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
  __IO uint32_t DISPLAY_ENGINES_CLOCK_CONTROL;     /**< Display engines clock control, offset: 0x0 */
  __IO uint32_t PIXEL_INTERLEAVER_CONTROL;         /**< Pixel interleaver control, offset: 0x4 */
  __IO uint32_t PIXEL_LINK_CTRL;                   /**< Pixel Link Control, offset: 0x8 */
       uint8_t RESERVED_0[12];
  __IO uint32_t AXCACHE_CONTROL;                   /**< AxCache control, offset: 0x18 */
  __IO uint32_t QOS_SETTING;                       /**< QoS setting, offset: 0x1C */
  __IO uint32_t DISPLAYENGINE_PLANE_ASSOCIATION;   /**< Display Engine Plane Association, offset: 0x20 */
} DISPLAY_BLK_CTRL_DISPLAYMIX_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_BLK_CTRL_DISPLAYMIX Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_BLK_CTRL_DISPLAYMIX_Register_Masks DISPLAY_BLK_CTRL_DISPLAYMIX Register Masks
 * @{
 */

/*! @name DISPLAY_ENGINES_CLOCK_CONTROL - Display engines clock control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_MASK (0x3U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_SHIFT (0U)
/*! DSIP_CLK0_SEL - Select the clock feeding the display engine 0
 *  0b11..Reserved
 *  0b10..LVDS PLL Div/7 clock
 *  0b01..DSI PLL Div clock
 *  0b00..CCM.video_pll_clk
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK0_SEL_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_MASK (0xCU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_SHIFT (2U)
/*! DSIP_CLK1_SEL - Select the clock feeding the display engine 1
 *  0b00..CCM.video_pll_clk
 *  0b01..DSI PLL Div clock
 *  0b10..LVDS PLL Div/7 clock
 *  0b11..Reserved
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAY_ENGINES_CLOCK_CONTROL_DSIP_CLK1_SEL_MASK)
/*! @} */

/*! @name PIXEL_INTERLEAVER_CONTROL - Pixel interleaver control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_SHIFT (0U)
/*! Mode - Select the pixel interleaver mode
 *  0b0..Pixel interleaver is in bypass mode.
 *  0b1..Pixel interleaver is in split mode #2.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Mode_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_MASK (0x2U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_SHIFT (1U)
/*! Disp_in_sel - Select the input stream when mode is set in split mode #2
 *  0b0..Display input stream 0 is interleaved.
 *  0b1..Display input stream 1 is interleaved.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_INTERLEAVER_CONTROL_Disp_in_sel_MASK)
/*! @} */

/*! @name PIXEL_LINK_CTRL - Pixel Link Control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_SHIFT (0U)
/*! PL0_enable - Start Pixel Link 0
 *  0b1..Start Pixel Link 0
 *  0b0..Do not start Pixel Link 0
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_enable_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_MASK (0x2U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_SHIFT (1U)
/*! PL0_valid - Indicates valid pixels / control
 *  0b0..Not valid pixels/control
 *  0b1..Valid pixels/control
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL0_valid_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_MASK (0x10U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_SHIFT (4U)
/*! PL1_enable - Start Pixel Link1
 *  0b0..Do not start Pixel Link 1
 *  0b1..Start Pixel Link 1
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_enable_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_MASK (0x20U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_SHIFT (5U)
/*! PL1_valid - Indicates valid pixels / control
 *  0b1..Valid pixels/control
 *  0b0..Not valid pixels/control
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_PIXEL_LINK_CTRL_PL1_valid_MASK)
/*! @} */

/*! @name AXCACHE_CONTROL - AxCache control */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_MASK (0xFU)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_SHIFT (0U)
/*! ArCache - Set the AXI ArCache signal for all AXI read master ports of the Display Controller except for the command sequencer one */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_ArCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_MASK (0xF00U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_SHIFT (8U)
/*! AwCache - Set the AXI AwCache signal for the AXI write master port (blitter output) of the
 *    Display Controller except for the command sequencer one
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_AwCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_MASK (0xF0000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_SHIFT (16U)
/*! CmdSeq_ArCache - Set the AXI ArCache signal for the 32-bit AXI read master ports (command sequencer) of the Display Controller */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_ArCache_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_MASK (0xF00000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_SHIFT (20U)
/*! CmdSeq_AwCache - Set the AXI AwCache signal for the 32-bit AXI write master parts (command sequencer) of the Display Controller */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_AXCACHE_CONTROL_CmdSeq_AwCache_MASK)
/*! @} */

/*! @name QOS_SETTING - QoS setting */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_MASK (0x7U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_SHIFT (0U)
/*! Display_ArQoS - Default priority level of the AXI read master ports of the Display controller when the Display FIFO panic is not active */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_ArQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_MASK (0x70U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_SHIFT (4U)
/*! Display_Panic_QoS - Priority level when the Display FIFO panic is active */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Display_Panic_QoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_MASK (0x700U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_SHIFT (8U)
/*! Blitter_AxQoS - Defines the priority level of the AXI read and write master port of the Blitter
 *    fetch units when the Display FIFO panic is not active
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_Blitter_AxQoS_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_MASK (0x70000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_SHIFT (16U)
/*! CmdSeq_QoS - Defines the priority level of the AXI read and write master port of the command
 *    sequencer when the Display FIFO panic is not active
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_QOS_SETTING_CmdSeq_QoS_MASK)
/*! @} */

/*! @name DISPLAYENGINE_PLANE_ASSOCIATION - Display Engine Plane Association */
/*! @{ */

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_MASK (0x1U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_SHIFT (0U)
/*! FracPlane_0 - FetchLayer#0
 *  0b1..Fetch unit is associated with Display Engine 1.
 *  0b0..Fetch unit is associated with Display Engine 0.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_MASK (0x4U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_SHIFT (2U)
/*! FracPlane_1 - FetchLayer#1
 *  0b1..Fetch unit is associated with Display Engine 1.
 *  0b0..Fetch unit is associated with Display Engine 0.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_FracPlane_1_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_MASK (0x40U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_SHIFT (6U)
/*! IntPlane_0 - FetchYUV#3
 *  0b1..Fetch unit is associated with Display Engine 1.
 *  0b0..Fetch unit is associated with Display Engine 0.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_IntPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_MASK (0x100U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_SHIFT (8U)
/*! VideoPlane_0 - FetchYUV#0 + FetchEco#0
 *  0b1..Fetch unit is associated with Display Engine 1.
 *  0b0..Fetch unit is associated with Display Engine 0.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_0_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_MASK (0x400U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_SHIFT (10U)
/*! VideoPlane_1 - FetchYUV#1 + FetchEco#1
 *  0b0..Fetch unit is associated with Display Engine 0.
 *  0b1..Fetch unit is associated with Display Engine 1.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_1_MASK)

#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_2_MASK (0x1000U)
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_2_SHIFT (12U)
/*! VideoPlane_2 - FetchYUV#2 + FetchEco#2
 *  0b1..Fetch unit is associated with Display Engine 1.
 *  0b0..Fetch unit is associated with Display Engine 0.
 */
#define DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_2(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_2_SHIFT)) & DISPLAY_BLK_CTRL_DISPLAYMIX_DISPLAYENGINE_PLANE_ASSOCIATION_VideoPlane_2_MASK)
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


#endif  /* DISPLAY_BLK_CTRL_DISPLAYMIX_H_ */

