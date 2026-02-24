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
**         CMSIS Peripheral Access Layer for LDB
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
 * @file PERI_LDB.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for LDB
 *
 * CMSIS Peripheral Access Layer for LDB
 */

#if !defined(PERI_LDB_H_)
#define PERI_LDB_H_                              /**< Symbol preventing repeated inclusion */

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
   -- LDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDB_Peripheral_Access_Layer LDB Peripheral Access Layer
 * @{
 */

/** LDB - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVDS_PHY_CLOCK_CONTROL;            /**< LVDS PHY Clock Control, offset: 0x0 */
  __IO uint32_t PIXEL_MAPPER_CONTROL;              /**< Pixel Mapper Control, offset: 0x4 */
  __IO uint32_t LVDS0_CONTROL;                     /**< LVDS0 Control, offset: 0x8 */
  __IO uint32_t LVDS1_CONTROL;                     /**< LVDS1 Control, offset: 0xC */
} LDB_Type;

/* ----------------------------------------------------------------------------
   -- LDB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDB_Register_Masks LDB Register Masks
 * @{
 */

/*! @name LVDS_PHY_CLOCK_CONTROL - LVDS PHY Clock Control */
/*! @{ */

#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_MASK (0x1U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_SHIFT (0U)
/*! LVDS_PHY_DIV - LVDS PHY Clock Divider Ratio
 *  0b0..PLL clock frequency
 *  0b1..PLL clock frequency / 2
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_MASK (0x2U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_SHIFT (1U)
/*! Serializer_Ch0_clock_Ctrl - LVDS Serializer Channel 0 Clock Gate Control
 *  0b0..Clocked
 *  0b1..Not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_MASK (0x4U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_SHIFT (2U)
/*! Serializer_Ch1_clock_Ctrl - LVDS Serializer Channel 1 Clock Gate Control
 *  0b0..Clocked
 *  0b1..Not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_MASK (0x8U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_SHIFT (3U)
/*! PixelMapper_Di0_clock_Ctrl - LVDS Pixel Mapper DI0 Clock Gate Control
 *  0b0..Clocked
 *  0b1..Not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_MASK (0x10U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_SHIFT (4U)
/*! PixelMapper_Di1_clock_Ctrl - LVDS Pixel Mapper DI1 Clock Gate Control
 *  0b0..Clocked
 *  0b1..Not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_MASK)
/*! @} */

/*! @name PIXEL_MAPPER_CONTROL - Pixel Mapper Control */
/*! @{ */

#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_MASK   (0x3U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_SHIFT  (0U)
/*! CH0_MODE - LVDS Channel 0 Operation Mode
 *  0b00..Channel disabled
 *  0b01..Channel enabled, routed to DI0
 *  0b10..Channel disabled
 *  0b11..Channel enabled, routed to DI1
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_MASK   (0xCU)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_SHIFT  (2U)
/*! CH1_MODE - LVDS Channel 1 Operation Mode
 *  0b00..Channel disabled
 *  0b01..Channel enabled, routed to DI0
 *  0b10..Channel disabled
 *  0b11..Channel enabled, routed to DI1
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_MASK (0x10U)
#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_SHIFT (4U)
/*! SPLIT_MODE - Split Mode Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_MASK (0x20U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_SHIFT (5U)
/*! CH0_DATA_WIDTH - LVDS Channel 0 Data Width
 *  0b0..18
 *  0b1..24
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_MASK (0x40U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_SHIFT (6U)
/*! CH0_BIT_MAPPING - LVDS Channel 0 Data Mapping
 *  0b0..Use SPWG standard
 *  0b1..Use JEIDA standard
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_MASK (0x80U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_SHIFT (7U)
/*! CH1_DATA_WIDTH - LVDS Channel 1 Data Width
 *  0b0..18
 *  0b1..24
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_MASK (0x100U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_SHIFT (8U)
/*! CH1_BIT_MAPPING - LVDS Channel 1 Data Mapping
 *  0b0..Use SPWG standard
 *  0b1..Use JEIDA standard
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_MASK (0x200U)
#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_SHIFT (9U)
/*! DI0_VSYNC_POLARITY - DI0 VSYNC Polarity Select
 *  0b0..VSYNC is active high
 *  0b1..VSYNC is active low
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_MASK (0x400U)
#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_SHIFT (10U)
/*! DI1_VSYNC_POLARITY - DI1 VSYNC Polarity Select
 *  0b0..VSYNC is active high
 *  0b1..VSYNC is active low
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_MASK (0x800U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_SHIFT (11U)
/*! CH0_ASYNC_FIFO_RESET - LVDS Channel 0 Async FIFO Software Reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_MASK (0x1000U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_SHIFT (12U)
/*! CH1_ASYNC_FIFO_RESET - LVDS Channel 1 Async FIFO Software Reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI0_HSYNC_POLARITY_MASK (0x2000U)
#define LDB_PIXEL_MAPPER_CONTROL_DI0_HSYNC_POLARITY_SHIFT (13U)
/*! DI0_HSYNC_POLARITY - HSYNC polarity select for DI0
 *  0b0..HSYNC is active high
 *  0b1..HSYNC is active low
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI0_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI0_HSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI0_HSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI1_HSYNC_POLARITY_MASK (0x4000U)
#define LDB_PIXEL_MAPPER_CONTROL_DI1_HSYNC_POLARITY_SHIFT (14U)
/*! DI1_HSYNC_POLARITY - DI1 HSYNC Polarity Select
 *  0b0..HSYNC is active high
 *  0b1..HSYNC is active low
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI1_HSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI1_HSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI1_HSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_VSYNC_ADJ_EN_MASK (0x80000U)
#define LDB_PIXEL_MAPPER_CONTROL_VSYNC_ADJ_EN_SHIFT (19U)
/*! VSYNC_ADJ_EN - VSYNC Adjust Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_PIXEL_MAPPER_CONTROL_VSYNC_ADJ_EN(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_VSYNC_ADJ_EN_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_VSYNC_ADJ_EN_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_MASK (0x1000000U)
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_SHIFT (24U)
/*! ASYNC_FIFO_ENABLE - Async FIFO Enable
 *  0b0..Disables. Only when display_csr.Display_engines_clock_control[DSIP_CLK1_SEL] set to 0x2 and
 *       display_csr.Display_engines_clock_control[DSIP_CLK0_SEL] set to 0x2, can ASYNC_FIFO_ENABLE be 0.
 *  0b1..Enables async FIFO to buffer RGB data. When display_csr.Display_engines_clock_control[DSIP_CLK1_SEL] set
 *       to 0x0 or 0x1, or display_csr.Display_engines_clock_control[DSIP_CLK0_SEL] set to 0x0 or 0x1,
 *       ASYNC_FIFO_ENABLE must be 1.
 */
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_MASK (0xE000000U)
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_SHIFT (25U)
/*! ASYNC_FIFO_THRESHOLD - Async FIFO Threshold */
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_MASK)
/*! @} */

/*! @name LVDS0_CONTROL - LVDS0 Control */
/*! @{ */

#define LDB_LVDS0_CONTROL_CH0_EN_MASK            (0x1U)
#define LDB_LVDS0_CONTROL_CH0_EN_SHIFT           (0U)
/*! CH0_EN - Channel 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_CH0_EN(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CH0_EN_SHIFT)) & LDB_LVDS0_CONTROL_CH0_EN_MASK)

#define LDB_LVDS0_CONTROL_LVDS_EN_MASK           (0x2U)
#define LDB_LVDS0_CONTROL_LVDS_EN_SHIFT          (1U)
/*! LVDS_EN - LVDS PHY Enable
 *  0b0..Enables. LVDS function is normal.
 *  0b1..Disables
 */
#define LDB_LVDS0_CONTROL_LVDS_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_LVDS_EN_SHIFT)) & LDB_LVDS0_CONTROL_LVDS_EN_MASK)

#define LDB_LVDS0_CONTROL_BG_EN_MASK             (0x4U)
#define LDB_LVDS0_CONTROL_BG_EN_SHIFT            (2U)
/*! BG_EN - Bandgap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_BG_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_BG_EN_SHIFT)) & LDB_LVDS0_CONTROL_BG_EN_MASK)

#define LDB_LVDS0_CONTROL_HS_EN_MASK             (0x8U)
#define LDB_LVDS0_CONTROL_HS_EN_SHIFT            (3U)
/*! HS_EN - HS Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_HS_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_HS_EN_SHIFT)) & LDB_LVDS0_CONTROL_HS_EN_MASK)

#define LDB_LVDS0_CONTROL_PRE_EMPH_EN_MASK       (0x10U)
#define LDB_LVDS0_CONTROL_PRE_EMPH_EN_SHIFT      (4U)
/*! PRE_EMPH_EN - Pre-emphasis Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_PRE_EMPH_EN(x)         (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_PRE_EMPH_EN_SHIFT)) & LDB_LVDS0_CONTROL_PRE_EMPH_EN_MASK)

#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_MASK      (0xE0U)
#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_SHIFT     (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis Adjustment */
#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_MASK)

#define LDB_LVDS0_CONTROL_CM_ADJ_MASK            (0x700U)
#define LDB_LVDS0_CONTROL_CM_ADJ_SHIFT           (8U)
/*! CM_ADJ - Output Common Mode (Vos) Adjustment */
#define LDB_LVDS0_CONTROL_CM_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CM_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_CM_ADJ_MASK)

#define LDB_LVDS0_CONTROL_CC_ADJ_MASK            (0x3800U)
#define LDB_LVDS0_CONTROL_CC_ADJ_SHIFT           (11U)
/*! CC_ADJ - Output Current Adjustment */
#define LDB_LVDS0_CONTROL_CC_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CC_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_CC_ADJ_MASK)

#define LDB_LVDS0_CONTROL_SLEW_ADJ_MASK          (0x1C000U)
#define LDB_LVDS0_CONTROL_SLEW_ADJ_SHIFT         (14U)
/*! SLEW_ADJ - Output Transition Time Adjustment */
#define LDB_LVDS0_CONTROL_SLEW_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_SLEW_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_SLEW_ADJ_MASK)

#define LDB_LVDS0_CONTROL_VBG_ADJ_MASK           (0xE0000U)
#define LDB_LVDS0_CONTROL_VBG_ADJ_SHIFT          (17U)
/*! VBG_ADJ - Bandgap Adjustment */
#define LDB_LVDS0_CONTROL_VBG_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_VBG_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_VBG_ADJ_MASK)

#define LDB_LVDS0_CONTROL_TEST_DIV4_MASK         (0x100000U)
#define LDB_LVDS0_CONTROL_TEST_DIV4_SHIFT        (20U)
/*! TEST_DIV4 - Divide By Four Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_TEST_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_DIV4_SHIFT)) & LDB_LVDS0_CONTROL_TEST_DIV4_MASK)

#define LDB_LVDS0_CONTROL_TEST_EN_MASK           (0x200000U)
#define LDB_LVDS0_CONTROL_TEST_EN_SHIFT          (21U)
/*! TEST_EN - Test Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_TEST_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_EN_SHIFT)) & LDB_LVDS0_CONTROL_TEST_EN_MASK)

#define LDB_LVDS0_CONTROL_TEST_MUX_SRC_MASK      (0xC00000U)
#define LDB_LVDS0_CONTROL_TEST_MUX_SRC_SHIFT     (22U)
/*! TEST_MUX_SRC - Test Signal Select
 *  0b00..LVDS0_D0_P/N
 *  0b01..LVDS0_D1_P/N
 *  0b10..LVDS0_D2_P/N
 *  0b11..LVDS0_D3_P/N
 */
#define LDB_LVDS0_CONTROL_TEST_MUX_SRC(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_MUX_SRC_SHIFT)) & LDB_LVDS0_CONTROL_TEST_MUX_SRC_MASK)

#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_MASK (0x1000000U)
#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_SHIFT (24U)
/*! TEST_RANDOM_NUM_EN - Random Number Generator Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN(x)  (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_SHIFT)) & LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_MASK)

#define LDB_LVDS0_CONTROL_SPARE_IN_MASK          (0xE000000U)
#define LDB_LVDS0_CONTROL_SPARE_IN_SHIFT         (25U)
/*! SPARE_IN - Spare Ports */
#define LDB_LVDS0_CONTROL_SPARE_IN(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_SPARE_IN_SHIFT)) & LDB_LVDS0_CONTROL_SPARE_IN_MASK)
/*! @} */

/*! @name LVDS1_CONTROL - LVDS1 Control */
/*! @{ */

#define LDB_LVDS1_CONTROL_CH0_EN_MASK            (0x1U)
#define LDB_LVDS1_CONTROL_CH0_EN_SHIFT           (0U)
/*! CH0_EN - Channel 0 Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_CH0_EN(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CH0_EN_SHIFT)) & LDB_LVDS1_CONTROL_CH0_EN_MASK)

#define LDB_LVDS1_CONTROL_LVDS_EN_MASK           (0x2U)
#define LDB_LVDS1_CONTROL_LVDS_EN_SHIFT          (1U)
/*! LVDS_EN - LVDS PHY Enable
 *  0b0..Enables. LVDS function is normal.
 *  0b1..Disables
 */
#define LDB_LVDS1_CONTROL_LVDS_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_LVDS_EN_SHIFT)) & LDB_LVDS1_CONTROL_LVDS_EN_MASK)

#define LDB_LVDS1_CONTROL_BG_EN_MASK             (0x4U)
#define LDB_LVDS1_CONTROL_BG_EN_SHIFT            (2U)
/*! BG_EN - Bandgap Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_BG_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_BG_EN_SHIFT)) & LDB_LVDS1_CONTROL_BG_EN_MASK)

#define LDB_LVDS1_CONTROL_HS_EN_MASK             (0x8U)
#define LDB_LVDS1_CONTROL_HS_EN_SHIFT            (3U)
/*! HS_EN - HS Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_HS_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_HS_EN_SHIFT)) & LDB_LVDS1_CONTROL_HS_EN_MASK)

#define LDB_LVDS1_CONTROL_PRE_EMPH_EN_MASK       (0x10U)
#define LDB_LVDS1_CONTROL_PRE_EMPH_EN_SHIFT      (4U)
/*! PRE_EMPH_EN - Pre-emphasis Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_PRE_EMPH_EN(x)         (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_PRE_EMPH_EN_SHIFT)) & LDB_LVDS1_CONTROL_PRE_EMPH_EN_MASK)

#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_MASK      (0xE0U)
#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_SHIFT     (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis Adjustment */
#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_MASK)

#define LDB_LVDS1_CONTROL_CM_ADJ_MASK            (0x700U)
#define LDB_LVDS1_CONTROL_CM_ADJ_SHIFT           (8U)
/*! CM_ADJ - Output Common Mode (Vos) Adjustment */
#define LDB_LVDS1_CONTROL_CM_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CM_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_CM_ADJ_MASK)

#define LDB_LVDS1_CONTROL_CC_ADJ_MASK            (0x3800U)
#define LDB_LVDS1_CONTROL_CC_ADJ_SHIFT           (11U)
/*! CC_ADJ - Output Current Adjustment */
#define LDB_LVDS1_CONTROL_CC_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CC_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_CC_ADJ_MASK)

#define LDB_LVDS1_CONTROL_SLEW_ADJ_MASK          (0x1C000U)
#define LDB_LVDS1_CONTROL_SLEW_ADJ_SHIFT         (14U)
/*! SLEW_ADJ - Output Transition Time Adjustment */
#define LDB_LVDS1_CONTROL_SLEW_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_SLEW_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_SLEW_ADJ_MASK)

#define LDB_LVDS1_CONTROL_VBG_ADJ_MASK           (0xE0000U)
#define LDB_LVDS1_CONTROL_VBG_ADJ_SHIFT          (17U)
/*! VBG_ADJ - Bandgap Adjustment */
#define LDB_LVDS1_CONTROL_VBG_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_VBG_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_VBG_ADJ_MASK)

#define LDB_LVDS1_CONTROL_TEST_DIV4_MASK         (0x100000U)
#define LDB_LVDS1_CONTROL_TEST_DIV4_SHIFT        (20U)
/*! TEST_DIV4 - Divide By Four Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_TEST_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_DIV4_SHIFT)) & LDB_LVDS1_CONTROL_TEST_DIV4_MASK)

#define LDB_LVDS1_CONTROL_TEST_EN_MASK           (0x200000U)
#define LDB_LVDS1_CONTROL_TEST_EN_SHIFT          (21U)
/*! TEST_EN - Test Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_TEST_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_EN_SHIFT)) & LDB_LVDS1_CONTROL_TEST_EN_MASK)

#define LDB_LVDS1_CONTROL_TEST_MUX_SRC_MASK      (0xC00000U)
#define LDB_LVDS1_CONTROL_TEST_MUX_SRC_SHIFT     (22U)
/*! TEST_MUX_SRC - Test Signal Select
 *  0b00..LVDS1_D0_P/N
 *  0b01..LVDS1_D1_P/N
 *  0b10..LVDS1_D2_P/N
 *  0b11..LVDS1_D3_P/N
 */
#define LDB_LVDS1_CONTROL_TEST_MUX_SRC(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_MUX_SRC_SHIFT)) & LDB_LVDS1_CONTROL_TEST_MUX_SRC_MASK)

#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_MASK (0x1000000U)
#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_SHIFT (24U)
/*! TEST_RANDOM_NUM_EN - Random Number Generator Enable
 *  0b0..Disables
 *  0b1..Enables
 */
#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN(x)  (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_SHIFT)) & LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_MASK)

#define LDB_LVDS1_CONTROL_SPARE_IN_MASK          (0xE000000U)
#define LDB_LVDS1_CONTROL_SPARE_IN_SHIFT         (25U)
/*! SPARE_IN - Spare Ports */
#define LDB_LVDS1_CONTROL_SPARE_IN(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_SPARE_IN_SHIFT)) & LDB_LVDS1_CONTROL_SPARE_IN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group LDB_Register_Masks */


/*!
 * @}
 */ /* end of group LDB_Peripheral_Access_Layer */


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


#endif  /* PERI_LDB_H_ */

