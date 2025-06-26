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
**         CMSIS Peripheral Access Layer for LDB
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
 * @file LDB.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for LDB
 *
 * CMSIS Peripheral Access Layer for LDB
 */

#if !defined(LDB_H_)
#define LDB_H_                                   /**< Symbol preventing repeated inclusion */

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
   -- LDB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LDB_Peripheral_Access_Layer LDB Peripheral Access Layer
 * @{
 */

/** LDB - Register Layout Typedef */
typedef struct {
  __IO uint32_t LVDS_PHY_CLOCK_CONTROL;            /**< LVDS PHY Clock Control, offset: 0x0 */
  __IO uint32_t PIXEL_MAPPER_CONTROL;              /**< Pixel mapper control, offset: 0x4 */
  __IO uint32_t LVDS0_CONTROL;                     /**< LVDS0 control, offset: 0x8 */
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
/*! LVDS_PHY_DIV - Defines the PHY clock divider ratio
 *  0b1..PHY clock frequency is equal to PLL clock frequency / 2
 *  0b0..PHY clock frequency is equal to PLL clock frequency
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PHY_DIV_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_MASK (0x2U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_SHIFT (1U)
/*! Serializer_Ch0_clock_Ctrl - LVDS serializer channel 0 clock gate control
 *  0b0..LVDS serializer channel 0 are clocked
 *  0b1..LVDS serializer channel 0 are not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch0_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_MASK (0x4U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_SHIFT (2U)
/*! Serializer_Ch1_clock_Ctrl - LVDS serializer channel 1 clock gate control
 *  0b1..LVDS serializer channel 1 are not clocked
 *  0b0..LVDS serializer channel 1 are clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_Serializer_Ch1_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_MASK (0x8U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_SHIFT (3U)
/*! PixelMapper_Di0_clock_Ctrl - LVDS pixel mapper Di0 clock gate control
 *  0b0..LVDS pixel mapper Di0 are clocked
 *  0b1..LVDS pixel mapper Di0 are not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di0_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_MASK (0x10U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_SHIFT (4U)
/*! PixelMapper_Di1_clock_Ctrl - LVDS pixel mapper Di1 clock gate control
 *  0b0..LVDS pixel mapper Di1 are clocked
 *  0b1..LVDS pixel mapper Di1 are not clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_PixelMapper_Di1_clock_Ctrl_MASK)

#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PLL_clock_ctrl_MASK (0x20U)
#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PLL_clock_ctrl_SHIFT (5U)
/*! LVDS_PLL_clock_ctrl - Control the clock gating logic of the LVDS PLL input clock
 *  0b1..LVDS PLL input clock are not clocked
 *  0b0..LVDS PLL input clock are clocked
 */
#define LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PLL_clock_ctrl(x) (((uint32_t)(((uint32_t)(x)) << LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PLL_clock_ctrl_SHIFT)) & LDB_LVDS_PHY_CLOCK_CONTROL_LVDS_PLL_clock_ctrl_MASK)
/*! @} */

/*! @name PIXEL_MAPPER_CONTROL - Pixel mapper control */
/*! @{ */

#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_MASK   (0x3U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_SHIFT  (0U)
/*! CH0_MODE - LVDS channel 0 operation mode
 *  0b01..Channel enabled, routed to DI0
 *  0b00..Channel disabled
 *  0b10..Channel disabled
 *  0b11..Channel enabled, routed to DI1
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_MASK   (0xCU)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_SHIFT  (2U)
/*! CH1_MODE - LVDS channel 1 operation mode
 *  0b01..Channel enabled, routed to DI0
 *  0b00..Channel disabled
 *  0b10..Channel disabled
 *  0b11..Channel enabled, routed to DI1
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_MODE(x)     (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_MASK (0x10U)
#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_SHIFT (4U)
/*! SPLIT_MODE - Enable split mode
 *  0b1..Split mode is enabled. In this mode both channels should be enabled and working with the same DI.
 *  0b0..Split mode is disabled.
 */
#define LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE(x)   (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_SPLIT_MODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_MASK (0x20U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_SHIFT (5U)
/*! CH0_DATA_WIDTH - Data width for LVDS channel 0
 *  0b0..Data width is 18 bits wide
 *  0b1..Data width is 24 bits wide
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_DATA_WIDTH_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_MASK (0x40U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_SHIFT (6U)
/*! CH0_BIT_MAPPING - Data mapping for LVDS channel 0
 *  0b1..Use JEIDA standard
 *  0b0..Use SPWG standard
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_BIT_MAPPING_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_MASK (0x80U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_SHIFT (7U)
/*! CH1_DATA_WIDTH - Data width for LVDS channel 1
 *  0b1..Data width is 24 bits wide
 *  0b0..Data width is 18 bits wide
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_DATA_WIDTH_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_MASK (0x100U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_SHIFT (8U)
/*! CH1_BIT_MAPPING - Data mapping for LVDS channel 1
 *  0b0..Use SPWG standard
 *  0b1..Use JEIDA standard
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_BIT_MAPPING_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_MASK (0x200U)
#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_SHIFT (9U)
/*! DI0_VSYNC_POLARITY - VSYNC polarity select for DI0
 *  0b1..VSYNC is active low
 *  0b0..VSYNC is active high
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI0_VSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_MASK (0x400U)
#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_SHIFT (10U)
/*! DI1_VSYNC_POLARITY - VSYNC polarity select for DI1
 *  0b0..VSYNC is active high
 *  0b1..VSYNC is active low
 */
#define LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_DI1_VSYNC_POLARITY_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_MASK (0x800U)
#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_SHIFT (11U)
/*! CH0_ASYNC_FIFO_RESET - LVDS channel 0 async FIFO software reset
 *  0b1..Software reset
 *  0b0..No action
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH0_ASYNC_FIFO_RESET_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_MASK (0x1000U)
#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_SHIFT (12U)
/*! CH1_ASYNC_FIFO_RESET - LVDS channel 1 async FIFO software reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_CH1_ASYNC_FIFO_RESET_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_BGREF_RRMODE_MASK (0x8000U)
#define LDB_PIXEL_MAPPER_CONTROL_BGREF_RRMODE_SHIFT (15U)
/*! BGREF_RRMODE - Select reference resistor for bandgap
 *  0b0..External resistor of 29kOhm is selected
 *  0b1..Internal resistor is selected
 */
#define LDB_PIXEL_MAPPER_CONTROL_BGREF_RRMODE(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_BGREF_RRMODE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_BGREF_RRMODE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_MASK (0x1000000U)
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_SHIFT (24U)
/*! ASYNC_FIFO_ENABLE - Channel 0 and channel 1 async FIFO enable
 *  0b0..Disable
 *  0b1..Enable async FIFO to buffer RGB data
 */
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_ENABLE_MASK)

#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_MASK (0xE000000U)
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_SHIFT (25U)
/*! ASYNC_FIFO_THRESHOLD - Reset value for the LDB counter which determines when the shift registers are loaded with data. */
#define LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_SHIFT)) & LDB_PIXEL_MAPPER_CONTROL_ASYNC_FIFO_THRESHOLD_MASK)
/*! @} */

/*! @name LVDS0_CONTROL - LVDS0 control */
/*! @{ */

#define LDB_LVDS0_CONTROL_CH0_EN_MASK            (0x1U)
#define LDB_LVDS0_CONTROL_CH0_EN_SHIFT           (0U)
/*! CH0_EN - Channel 0 enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_CH0_EN(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CH0_EN_SHIFT)) & LDB_LVDS0_CONTROL_CH0_EN_MASK)

#define LDB_LVDS0_CONTROL_LVDS_EN_MASK           (0x2U)
#define LDB_LVDS0_CONTROL_LVDS_EN_SHIFT          (1U)
/*! LVDS_EN - LVDS PHY enable
 *  0b0..Enable. LVDS function is normal.
 *  0b1..Disable
 */
#define LDB_LVDS0_CONTROL_LVDS_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_LVDS_EN_SHIFT)) & LDB_LVDS0_CONTROL_LVDS_EN_MASK)

#define LDB_LVDS0_CONTROL_BG_EN_MASK             (0x4U)
#define LDB_LVDS0_CONTROL_BG_EN_SHIFT            (2U)
/*! BG_EN - Bandgap enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_BG_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_BG_EN_SHIFT)) & LDB_LVDS0_CONTROL_BG_EN_MASK)

#define LDB_LVDS0_CONTROL_HS_EN_MASK             (0x8U)
#define LDB_LVDS0_CONTROL_HS_EN_SHIFT            (3U)
/*! HS_EN - Enable 100 ohm termination in the chip enable which also doubles power dissipation.
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_HS_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_HS_EN_SHIFT)) & LDB_LVDS0_CONTROL_HS_EN_MASK)

#define LDB_LVDS0_CONTROL_PRE_EMPH_EN_MASK       (0x10U)
#define LDB_LVDS0_CONTROL_PRE_EMPH_EN_SHIFT      (4U)
/*! PRE_EMPH_EN - Enable pre-emphasis
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_PRE_EMPH_EN(x)         (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_PRE_EMPH_EN_SHIFT)) & LDB_LVDS0_CONTROL_PRE_EMPH_EN_MASK)

#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_MASK      (0xE0U)
#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_SHIFT     (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis adjustment. */
#define LDB_LVDS0_CONTROL_PRE_EMPH_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_PRE_EMPH_ADJ_MASK)

#define LDB_LVDS0_CONTROL_CM_ADJ_MASK            (0x700U)
#define LDB_LVDS0_CONTROL_CM_ADJ_SHIFT           (8U)
/*! CM_ADJ - Output common mode (Vos) adjustment */
#define LDB_LVDS0_CONTROL_CM_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CM_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_CM_ADJ_MASK)

#define LDB_LVDS0_CONTROL_CC_ADJ_MASK            (0x3800U)
#define LDB_LVDS0_CONTROL_CC_ADJ_SHIFT           (11U)
/*! CC_ADJ - Output current adjustment */
#define LDB_LVDS0_CONTROL_CC_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_CC_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_CC_ADJ_MASK)

#define LDB_LVDS0_CONTROL_SLEW_ADJ_MASK          (0x1C000U)
#define LDB_LVDS0_CONTROL_SLEW_ADJ_SHIFT         (14U)
/*! SLEW_ADJ - Output transition time adjustment */
#define LDB_LVDS0_CONTROL_SLEW_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_SLEW_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_SLEW_ADJ_MASK)

#define LDB_LVDS0_CONTROL_VBG_ADJ_MASK           (0xE0000U)
#define LDB_LVDS0_CONTROL_VBG_ADJ_SHIFT          (17U)
/*! VBG_ADJ - Bandgap adjustment */
#define LDB_LVDS0_CONTROL_VBG_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_VBG_ADJ_SHIFT)) & LDB_LVDS0_CONTROL_VBG_ADJ_MASK)

#define LDB_LVDS0_CONTROL_TEST_DIV4_MASK         (0x100000U)
#define LDB_LVDS0_CONTROL_TEST_DIV4_SHIFT        (20U)
/*! TEST_DIV4 - Divide the input signal/clock by 4.
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_TEST_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_DIV4_SHIFT)) & LDB_LVDS0_CONTROL_TEST_DIV4_MASK)

#define LDB_LVDS0_CONTROL_TEST_EN_MASK           (0x200000U)
#define LDB_LVDS0_CONTROL_TEST_EN_SHIFT          (21U)
/*! TEST_EN - Test enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_TEST_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_EN_SHIFT)) & LDB_LVDS0_CONTROL_TEST_EN_MASK)

#define LDB_LVDS0_CONTROL_TEST_MUX_SRC_MASK      (0xC00000U)
#define LDB_LVDS0_CONTROL_TEST_MUX_SRC_SHIFT     (22U)
/*! TEST_MUX_SRC - Select which signals to test
 *  0b11..LVDS0_D3_P/N
 *  0b10..LVDS0_D2_P/N
 *  0b00..LVDS0_D0_P/N
 *  0b01..LVDS0_D1_P/N
 */
#define LDB_LVDS0_CONTROL_TEST_MUX_SRC(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_MUX_SRC_SHIFT)) & LDB_LVDS0_CONTROL_TEST_MUX_SRC_MASK)

#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_MASK (0x1000000U)
#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_SHIFT (24U)
/*! TEST_RANDOM_NUM_EN - Random number generator enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN(x)  (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_SHIFT)) & LDB_LVDS0_CONTROL_TEST_RANDOM_NUM_EN_MASK)

#define LDB_LVDS0_CONTROL_SPARE_IN_MASK          (0xE000000U)
#define LDB_LVDS0_CONTROL_SPARE_IN_SHIFT         (25U)
/*! SPARE_IN - Spare ports */
#define LDB_LVDS0_CONTROL_SPARE_IN(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS0_CONTROL_SPARE_IN_SHIFT)) & LDB_LVDS0_CONTROL_SPARE_IN_MASK)
/*! @} */

/*! @name LVDS1_CONTROL - LVDS1 Control */
/*! @{ */

#define LDB_LVDS1_CONTROL_CH0_EN_MASK            (0x1U)
#define LDB_LVDS1_CONTROL_CH0_EN_SHIFT           (0U)
/*! CH0_EN - Channel 0 enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define LDB_LVDS1_CONTROL_CH0_EN(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CH0_EN_SHIFT)) & LDB_LVDS1_CONTROL_CH0_EN_MASK)

#define LDB_LVDS1_CONTROL_LVDS_EN_MASK           (0x2U)
#define LDB_LVDS1_CONTROL_LVDS_EN_SHIFT          (1U)
/*! LVDS_EN - LVDS PHY enable
 *  0b1..Disable
 *  0b0..Enable. LVDS function is normal.
 */
#define LDB_LVDS1_CONTROL_LVDS_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_LVDS_EN_SHIFT)) & LDB_LVDS1_CONTROL_LVDS_EN_MASK)

#define LDB_LVDS1_CONTROL_BG_EN_MASK             (0x4U)
#define LDB_LVDS1_CONTROL_BG_EN_SHIFT            (2U)
/*! BG_EN - Bandgap enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_BG_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_BG_EN_SHIFT)) & LDB_LVDS1_CONTROL_BG_EN_MASK)

#define LDB_LVDS1_CONTROL_HS_EN_MASK             (0x8U)
#define LDB_LVDS1_CONTROL_HS_EN_SHIFT            (3U)
/*! HS_EN - Enable 100 ohm termination in the chip enable which also doubles power dissipation.
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_HS_EN(x)               (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_HS_EN_SHIFT)) & LDB_LVDS1_CONTROL_HS_EN_MASK)

#define LDB_LVDS1_CONTROL_PRE_EMPH_EN_MASK       (0x10U)
#define LDB_LVDS1_CONTROL_PRE_EMPH_EN_SHIFT      (4U)
/*! PRE_EMPH_EN - Enable pre-emphasis
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_PRE_EMPH_EN(x)         (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_PRE_EMPH_EN_SHIFT)) & LDB_LVDS1_CONTROL_PRE_EMPH_EN_MASK)

#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_MASK      (0xE0U)
#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_SHIFT     (5U)
/*! PRE_EMPH_ADJ - Pre-emphasis adjustment. */
#define LDB_LVDS1_CONTROL_PRE_EMPH_ADJ(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_PRE_EMPH_ADJ_MASK)

#define LDB_LVDS1_CONTROL_CM_ADJ_MASK            (0x700U)
#define LDB_LVDS1_CONTROL_CM_ADJ_SHIFT           (8U)
/*! CM_ADJ - Output common mode (Vos) adjustment */
#define LDB_LVDS1_CONTROL_CM_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CM_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_CM_ADJ_MASK)

#define LDB_LVDS1_CONTROL_CC_ADJ_MASK            (0x3800U)
#define LDB_LVDS1_CONTROL_CC_ADJ_SHIFT           (11U)
/*! CC_ADJ - Output current adjustment */
#define LDB_LVDS1_CONTROL_CC_ADJ(x)              (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_CC_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_CC_ADJ_MASK)

#define LDB_LVDS1_CONTROL_SLEW_ADJ_MASK          (0x1C000U)
#define LDB_LVDS1_CONTROL_SLEW_ADJ_SHIFT         (14U)
/*! SLEW_ADJ - Output transition time adjustment */
#define LDB_LVDS1_CONTROL_SLEW_ADJ(x)            (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_SLEW_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_SLEW_ADJ_MASK)

#define LDB_LVDS1_CONTROL_VBG_ADJ_MASK           (0xE0000U)
#define LDB_LVDS1_CONTROL_VBG_ADJ_SHIFT          (17U)
/*! VBG_ADJ - Bandgap adjustment */
#define LDB_LVDS1_CONTROL_VBG_ADJ(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_VBG_ADJ_SHIFT)) & LDB_LVDS1_CONTROL_VBG_ADJ_MASK)

#define LDB_LVDS1_CONTROL_TEST_DIV4_MASK         (0x100000U)
#define LDB_LVDS1_CONTROL_TEST_DIV4_SHIFT        (20U)
/*! TEST_DIV4 - Divide the input signal/clock by 4.
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_TEST_DIV4(x)           (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_DIV4_SHIFT)) & LDB_LVDS1_CONTROL_TEST_DIV4_MASK)

#define LDB_LVDS1_CONTROL_TEST_EN_MASK           (0x200000U)
#define LDB_LVDS1_CONTROL_TEST_EN_SHIFT          (21U)
/*! TEST_EN - Test enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_TEST_EN(x)             (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_EN_SHIFT)) & LDB_LVDS1_CONTROL_TEST_EN_MASK)

#define LDB_LVDS1_CONTROL_TEST_MUX_SRC_MASK      (0xC00000U)
#define LDB_LVDS1_CONTROL_TEST_MUX_SRC_SHIFT     (22U)
/*! TEST_MUX_SRC - Select which signals to test
 *  0b01..LVDS1_D1_P/N
 *  0b00..LVDS1_D0_P/N
 *  0b10..LVDS1_D2_P/N
 *  0b11..LVDS1_D3_P/N
 */
#define LDB_LVDS1_CONTROL_TEST_MUX_SRC(x)        (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_MUX_SRC_SHIFT)) & LDB_LVDS1_CONTROL_TEST_MUX_SRC_MASK)

#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_MASK (0x1000000U)
#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_SHIFT (24U)
/*! TEST_RANDOM_NUM_EN - Random number generator enable
 *  0b1..Enable
 *  0b0..Disable
 */
#define LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN(x)  (((uint32_t)(((uint32_t)(x)) << LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_SHIFT)) & LDB_LVDS1_CONTROL_TEST_RANDOM_NUM_EN_MASK)

#define LDB_LVDS1_CONTROL_SPARE_IN_MASK          (0xE000000U)
#define LDB_LVDS1_CONTROL_SPARE_IN_SHIFT         (25U)
/*! SPARE_IN - Spare ports */
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


#endif  /* LDB_H_ */

