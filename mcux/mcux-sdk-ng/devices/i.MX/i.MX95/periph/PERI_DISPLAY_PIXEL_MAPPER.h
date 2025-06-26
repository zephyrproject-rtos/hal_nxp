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
**         CMSIS Peripheral Access Layer for DISPLAY_PIXEL_MAPPER
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
 * @file DISPLAY_PIXEL_MAPPER.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for DISPLAY_PIXEL_MAPPER
 *
 * CMSIS Peripheral Access Layer for DISPLAY_PIXEL_MAPPER
 */

#if !defined(DISPLAY_PIXEL_MAPPER_H_)
#define DISPLAY_PIXEL_MAPPER_H_                  /**< Symbol preventing repeated inclusion */

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
   -- DISPLAY_PIXEL_MAPPER Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_PIXEL_MAPPER_Peripheral_Access_Layer DISPLAY_PIXEL_MAPPER Peripheral Access Layer
 * @{
 */

/** DISPLAY_PIXEL_MAPPER - Register Layout Typedef */
typedef struct {
  __IO uint32_t LDB_CTRL;                          /**< LDB Control Register, offset: 0x0 */
} DISPLAY_PIXEL_MAPPER_Type;

/* ----------------------------------------------------------------------------
   -- DISPLAY_PIXEL_MAPPER Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup DISPLAY_PIXEL_MAPPER_Register_Masks DISPLAY_PIXEL_MAPPER Register Masks
 * @{
 */

/*! @name LDB_CTRL - LDB Control Register */
/*! @{ */

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ENABLE_MASK (0x1U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ENABLE_SHIFT (0U)
/*! CH0_ENABLE - LVDS channel 0 enable
 *  0b0..Channel disabled
 *  0b1..Channel enabled
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ENABLE_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ENABLE_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DI_SELECT_MASK (0x2U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DI_SELECT_SHIFT (1U)
/*! CH0_DI_SELECT - LVDS channel 0 source select
 *  0b0..From DI0
 *  0b1..From DI1
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DI_SELECT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DI_SELECT_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DI_SELECT_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ENABLE_MASK (0x4U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ENABLE_SHIFT (2U)
/*! CH1_ENABLE - LVDS channel 1 enable
 *  0b0..Channel disabled
 *  0b1..Channel enabled
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ENABLE_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ENABLE_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DI_SELECT_MASK (0x8U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DI_SELECT_SHIFT (3U)
/*! CH1_DI_SELECT - LVDS channel 1 source select
 *  0b0..From DI0
 *  0b1..From DI1
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DI_SELECT(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DI_SELECT_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DI_SELECT_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_SPLIT_MODE_MASK (0x10U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_SPLIT_MODE_SHIFT (4U)
/*! SPLIT_MODE - Enable split mode
 *  0b0..Split mode disabled
 *  0b1..Split mode enabled
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_SPLIT_MODE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_SPLIT_MODE_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_SPLIT_MODE_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DATA_WIDTH_MASK (0x20U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DATA_WIDTH_SHIFT (5U)
/*! CH0_DATA_WIDTH - Data width for LVDS channel 0.
 *  0b0..Data width is 18 bits wide(LVDS0_D3 is not used)
 *  0b1..Data width is 24 bits wide
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DATA_WIDTH_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_DATA_WIDTH_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_BIT_MAPPING_MASK (0x40U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_BIT_MAPPING_SHIFT (6U)
/*! CH0_BIT_MAPPING - Data mapping for LVDS channel 0.
 *  0b0..Use SPWG standard.
 *  0b1..Use JEIDA standard.
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_BIT_MAPPING_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_BIT_MAPPING_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DATA_WIDTH_MASK (0x80U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DATA_WIDTH_SHIFT (7U)
/*! CH1_DATA_WIDTH - Data width for LVDS channel 1.
 *  0b0..Data width is 18 bits wide(LVDS1_D3 is not used)
 *  0b1..Data width is 24 bits wide
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DATA_WIDTH(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DATA_WIDTH_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_DATA_WIDTH_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_BIT_MAPPING_MASK (0x100U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_BIT_MAPPING_SHIFT (8U)
/*! CH1_BIT_MAPPING - Data mapping for LVDS channel 1.
 *  0b0..Use SPWG standard.
 *  0b1..Use JEIDA standard.
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_BIT_MAPPING(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_BIT_MAPPING_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_BIT_MAPPING_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI0_VSYNC_POLARITY_MASK (0x200U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI0_VSYNC_POLARITY_SHIFT (9U)
/*! DI0_VSYNC_POLARITY - VSYNC polarity select for DI0
 *  0b0..VSYNC is active high
 *  0b1..VSYNC is active low
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI0_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI0_VSYNC_POLARITY_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI0_VSYNC_POLARITY_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI1_VSYNC_POLARITY_MASK (0x400U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI1_VSYNC_POLARITY_SHIFT (10U)
/*! DI1_VSYNC_POLARITY - VSYNC polarity select for DI1
 *  0b0..VSYNC is active high
 *  0b1..VSYNC is active low
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI1_VSYNC_POLARITY(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI1_VSYNC_POLARITY_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_DI1_VSYNC_POLARITY_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ASYNC_FIFO_RESET_MASK (0x800U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ASYNC_FIFO_RESET_SHIFT (11U)
/*! CH0_ASYNC_FIFO_RESET - LVDS channel 0 async FIFO software reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ASYNC_FIFO_RESET_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH0_ASYNC_FIFO_RESET_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ASYNC_FIFO_RESET_MASK (0x1000U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ASYNC_FIFO_RESET_SHIFT (12U)
/*! CH1_ASYNC_FIFO_RESET - LVDS channel 1 async FIFO software reset
 *  0b0..No action
 *  0b1..Software reset
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ASYNC_FIFO_RESET(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ASYNC_FIFO_RESET_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_CH1_ASYNC_FIFO_RESET_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_ENABLE_MASK (0x1000000U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_ENABLE_SHIFT (24U)
/*! ASYNC_FIFO_ENABLE - Channel 0 and channel 1 async FIFO enable
 *  0b0..Disable
 *  0b1..Enable async FIFO to buffer RGB data
 */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_ENABLE(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_ENABLE_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_ENABLE_MASK)

#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_THRESHOLD_MASK (0xE000000U)
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_THRESHOLD_SHIFT (25U)
/*! ASYNC_FIFO_THRESHOLD - Channel 0 and channel 1 async FIFO enable */
#define DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_THRESHOLD(x) (((uint32_t)(((uint32_t)(x)) << DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_THRESHOLD_SHIFT)) & DISPLAY_PIXEL_MAPPER_LDB_CTRL_ASYNC_FIFO_THRESHOLD_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group DISPLAY_PIXEL_MAPPER_Register_Masks */


/*!
 * @}
 */ /* end of group DISPLAY_PIXEL_MAPPER_Peripheral_Access_Layer */


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


#endif  /* DISPLAY_PIXEL_MAPPER_H_ */

