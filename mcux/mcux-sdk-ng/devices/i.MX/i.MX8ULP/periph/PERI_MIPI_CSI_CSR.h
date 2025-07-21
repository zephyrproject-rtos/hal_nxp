/*
** ###################################################################
**     Processors:          MIMX8UD3CVP08_ca35
**                          MIMX8UD3CVP08_cm33
**                          MIMX8UD3CVP08_dsp0
**                          MIMX8UD3CVP08_dsp1
**                          MIMX8UD3DVK08_ca35
**                          MIMX8UD3DVK08_cm33
**                          MIMX8UD3DVK08_dsp0
**                          MIMX8UD3DVK08_dsp1
**                          MIMX8UD3DVP08_ca35
**                          MIMX8UD3DVP08_cm33
**                          MIMX8UD3DVP08_dsp0
**                          MIMX8UD3DVP08_dsp1
**                          MIMX8UD5CVP08_ca35
**                          MIMX8UD5CVP08_cm33
**                          MIMX8UD5CVP08_dsp0
**                          MIMX8UD5CVP08_dsp1
**                          MIMX8UD5DVK08_ca35
**                          MIMX8UD5DVK08_cm33
**                          MIMX8UD5DVK08_dsp0
**                          MIMX8UD5DVK08_dsp1
**                          MIMX8UD5DVP08_ca35
**                          MIMX8UD5DVP08_cm33
**                          MIMX8UD5DVP08_dsp0
**                          MIMX8UD5DVP08_dsp1
**                          MIMX8UD7CVP08_ca35
**                          MIMX8UD7CVP08_cm33
**                          MIMX8UD7CVP08_dsp0
**                          MIMX8UD7CVP08_dsp1
**                          MIMX8UD7DVK08_ca35
**                          MIMX8UD7DVK08_cm33
**                          MIMX8UD7DVK08_dsp0
**                          MIMX8UD7DVK08_dsp1
**                          MIMX8UD7DVP08_ca35
**                          MIMX8UD7DVP08_cm33
**                          MIMX8UD7DVP08_dsp0
**                          MIMX8UD7DVP08_dsp1
**                          MIMX8US3CVP08_ca35
**                          MIMX8US3CVP08_cm33
**                          MIMX8US3CVP08_dsp0
**                          MIMX8US3CVP08_dsp1
**                          MIMX8US3DVK08_ca35
**                          MIMX8US3DVK08_cm33
**                          MIMX8US3DVK08_dsp0
**                          MIMX8US3DVK08_dsp1
**                          MIMX8US3DVP08_ca35
**                          MIMX8US3DVP08_cm33
**                          MIMX8US3DVP08_dsp0
**                          MIMX8US3DVP08_dsp1
**                          MIMX8US5CVP08_ca35
**                          MIMX8US5CVP08_cm33
**                          MIMX8US5CVP08_dsp0
**                          MIMX8US5CVP08_dsp1
**                          MIMX8US5DVK08_ca35
**                          MIMX8US5DVK08_cm33
**                          MIMX8US5DVK08_dsp0
**                          MIMX8US5DVK08_dsp1
**                          MIMX8US5DVP08_ca35
**                          MIMX8US5DVP08_cm33
**                          MIMX8US5DVP08_dsp0
**                          MIMX8US5DVP08_dsp1
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250521
**
**     Abstract:
**         CMSIS Peripheral Access Layer for MIPI_CSI_CSR
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**     - rev. 1.0 (2020-05-25)
**         Initial version.
**     - rev. 2.0 (2020-09-18)
**         Base on rev A RM
**     - rev. 3.0 (2021-01-20)
**         Base on rev A.1 RM
**     - rev. 4.0 (2021-07-05)
**         Base on rev B RM
**     - rev. 5.0 (2023-04-27)
**         Base on rev D RM
**     - rev. 6.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_MIPI_CSI_CSR.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for MIPI_CSI_CSR
 *
 * CMSIS Peripheral Access Layer for MIPI_CSI_CSR
 */

#if !defined(PERI_MIPI_CSI_CSR_H_)
#define PERI_MIPI_CSI_CSR_H_                     /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMX8UD3CVP08_ca35) || defined(CPU_MIMX8UD3DVK08_ca35) || defined(CPU_MIMX8UD3DVP08_ca35))
#include "MIMX8UD3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_cm33) || defined(CPU_MIMX8UD3DVK08_cm33) || defined(CPU_MIMX8UD3DVP08_cm33))
#include "MIMX8UD3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp0) || defined(CPU_MIMX8UD3DVK08_dsp0) || defined(CPU_MIMX8UD3DVP08_dsp0))
#include "MIMX8UD3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD3CVP08_dsp1) || defined(CPU_MIMX8UD3DVK08_dsp1) || defined(CPU_MIMX8UD3DVP08_dsp1))
#include "MIMX8UD3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_ca35) || defined(CPU_MIMX8UD5DVK08_ca35) || defined(CPU_MIMX8UD5DVP08_ca35))
#include "MIMX8UD5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_cm33) || defined(CPU_MIMX8UD5DVK08_cm33) || defined(CPU_MIMX8UD5DVP08_cm33))
#include "MIMX8UD5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp0) || defined(CPU_MIMX8UD5DVK08_dsp0) || defined(CPU_MIMX8UD5DVP08_dsp0))
#include "MIMX8UD5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD5CVP08_dsp1) || defined(CPU_MIMX8UD5DVK08_dsp1) || defined(CPU_MIMX8UD5DVP08_dsp1))
#include "MIMX8UD5_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_ca35) || defined(CPU_MIMX8UD7DVK08_ca35) || defined(CPU_MIMX8UD7DVP08_ca35))
#include "MIMX8UD7_ca35_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_cm33) || defined(CPU_MIMX8UD7DVK08_cm33) || defined(CPU_MIMX8UD7DVP08_cm33))
#include "MIMX8UD7_cm33_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp0) || defined(CPU_MIMX8UD7DVK08_dsp0) || defined(CPU_MIMX8UD7DVP08_dsp0))
#include "MIMX8UD7_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8UD7CVP08_dsp1) || defined(CPU_MIMX8UD7DVK08_dsp1) || defined(CPU_MIMX8UD7DVP08_dsp1))
#include "MIMX8UD7_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_ca35) || defined(CPU_MIMX8US3DVK08_ca35) || defined(CPU_MIMX8US3DVP08_ca35))
#include "MIMX8US3_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_cm33) || defined(CPU_MIMX8US3DVK08_cm33) || defined(CPU_MIMX8US3DVP08_cm33))
#include "MIMX8US3_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp0) || defined(CPU_MIMX8US3DVK08_dsp0) || defined(CPU_MIMX8US3DVP08_dsp0))
#include "MIMX8US3_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US3CVP08_dsp1) || defined(CPU_MIMX8US3DVK08_dsp1) || defined(CPU_MIMX8US3DVP08_dsp1))
#include "MIMX8US3_dsp1_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_ca35) || defined(CPU_MIMX8US5DVK08_ca35) || defined(CPU_MIMX8US5DVP08_ca35))
#include "MIMX8US5_ca35_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_cm33) || defined(CPU_MIMX8US5DVK08_cm33) || defined(CPU_MIMX8US5DVP08_cm33))
#include "MIMX8US5_cm33_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp0) || defined(CPU_MIMX8US5DVK08_dsp0) || defined(CPU_MIMX8US5DVP08_dsp0))
#include "MIMX8US5_dsp0_COMMON.h"
#elif (defined(CPU_MIMX8US5CVP08_dsp1) || defined(CPU_MIMX8US5DVK08_dsp1) || defined(CPU_MIMX8US5DVP08_dsp1))
#include "MIMX8US5_dsp1_COMMON.h"
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
   -- MIPI_CSI_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_CSR_Peripheral_Access_Layer MIPI_CSI_CSR Peripheral Access Layer
 * @{
 */

/** MIPI_CSI_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t PLM_CTRL;                          /**< Pixel Link Master (PLM) Control, offset: 0x0 */
  __IO uint32_t PHY_CTRL;                          /**< PHY_CTRL are outputs from CSR to the PHY or Controller., offset: 0x4 */
  __I  uint32_t PHY_STATUS;                        /**< offset: 0x8 */
       uint8_t RESERVED_0[36];
  __IO uint32_t VC_INTERLACED;                     /**< offset: 0x30 */
       uint8_t RESERVED_1[4];
  __IO uint32_t DATA_TYPE_DISABLE_BF;              /**< offset: 0x38 */
       uint8_t RESERVED_2[4];
  __IO uint32_t YUV420_FIRST_LINE_DATA_TYPE;       /**< offset: 0x40 */
  __IO uint32_t CONTROLLER_CLOCK_RESET_CONTROL;    /**< offset: 0x44 */
  __IO uint32_t STREAM_FENCING_CONTROL;            /**< Stream Fencing Control (RW - to Pixel Reformatter), offset: 0x48 */
  __I  uint32_t STREAM_FENCING_STATUS;             /**< Stream Fencing Status (RO - from Pixel Reformatter), offset: 0x4C */
} MIPI_CSI_CSR_Type;

/* ----------------------------------------------------------------------------
   -- MIPI_CSI_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MIPI_CSI_CSR_Register_Masks MIPI_CSI_CSR Register Masks
 * @{
 */

/*! @name PLM_CTRL - Pixel Link Master (PLM) Control */
/*! @{ */

#define MIPI_CSI_CSR_PLM_CTRL_ENABLE_MASK        (0x1U)
#define MIPI_CSI_CSR_PLM_CTRL_ENABLE_SHIFT       (0U)
/*! ENABLE - Enable - for pixel link */
#define MIPI_CSI_CSR_PLM_CTRL_ENABLE(x)          (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_ENABLE_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_ENABLE_MASK)

#define MIPI_CSI_CSR_PLM_CTRL_ADDR_MASK          (0x6U)
#define MIPI_CSI_CSR_PLM_CTRL_ADDR_SHIFT         (1U)
/*! ADDR - For selecting the destination module that receives the data. Can be defaulted to 0. */
#define MIPI_CSI_CSR_PLM_CTRL_ADDR(x)            (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_ADDR_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_ADDR_MASK)

#define MIPI_CSI_CSR_PLM_CTRL_VSYNC_OVERIDE_MASK (0x200U)
#define MIPI_CSI_CSR_PLM_CTRL_VSYNC_OVERIDE_SHIFT (9U)
/*! VSYNC_OVERIDE - Used to force the Pixel Link Master VSYNC input to be active */
#define MIPI_CSI_CSR_PLM_CTRL_VSYNC_OVERIDE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_VSYNC_OVERIDE_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_VSYNC_OVERIDE_MASK)

#define MIPI_CSI_CSR_PLM_CTRL_HSYNC_OVERIDE_MASK (0x400U)
#define MIPI_CSI_CSR_PLM_CTRL_HSYNC_OVERIDE_SHIFT (10U)
/*! HSYNC_OVERIDE - Used to force the Pixel Link Master HSYNC input to be active */
#define MIPI_CSI_CSR_PLM_CTRL_HSYNC_OVERIDE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_HSYNC_OVERIDE_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_HSYNC_OVERIDE_MASK)

#define MIPI_CSI_CSR_PLM_CTRL_VALID_OVERRIDE_MASK (0x800U)
#define MIPI_CSI_CSR_PLM_CTRL_VALID_OVERRIDE_SHIFT (11U)
/*! VALID_OVERRIDE - Used to drive valid on the Pixel Link */
#define MIPI_CSI_CSR_PLM_CTRL_VALID_OVERRIDE(x)  (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_VALID_OVERRIDE_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_VALID_OVERRIDE_MASK)

#define MIPI_CSI_CSR_PLM_CTRL_POLARITY_MASK      (0x1000U)
#define MIPI_CSI_CSR_PLM_CTRL_POLARITY_SHIFT     (12U)
/*! POLARITY - POLARITY
 *  0b0..HSYNC and VSYNC signals should be active low. Also a reset value (active low).
 *  0b1..HSYNC and VSYNC signals should be active high
 */
#define MIPI_CSI_CSR_PLM_CTRL_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PLM_CTRL_POLARITY_SHIFT)) & MIPI_CSI_CSR_PLM_CTRL_POLARITY_MASK)
/*! @} */

/*! @name PHY_CTRL - PHY_CTRL are outputs from CSR to the PHY or Controller. */
/*! @{ */

#define MIPI_CSI_CSR_PHY_CTRL_RX_ENABLE_MASK     (0x1U)
#define MIPI_CSI_CSR_PHY_CTRL_RX_ENABLE_SHIFT    (0U)
/*! RX_ENABLE - Receive Enable */
#define MIPI_CSI_CSR_PHY_CTRL_RX_ENABLE(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_RX_ENABLE_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_RX_ENABLE_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_AUTO_PD_EN_MASK    (0x2U)
#define MIPI_CSI_CSR_PHY_CTRL_AUTO_PD_EN_SHIFT   (1U)
/*! AUTO_PD_EN - Powers down inactive lanes reported by CFG_NUM_LANES input bus.
 *  0b0..Inactive lanes are powered up.
 *  0b1..Inactive lanes are powered down.
 */
#define MIPI_CSI_CSR_PHY_CTRL_AUTO_PD_EN(x)      (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_AUTO_PD_EN_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_AUTO_PD_EN_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_DDRCLK_EN_MASK     (0x4U)
#define MIPI_CSI_CSR_PHY_CTRL_DDRCLK_EN_SHIFT    (2U)
/*! DDRCLK_EN - DDR Clock Enable. When set, enables received DDR clock on CLK_DRXHS. */
#define MIPI_CSI_CSR_PHY_CTRL_DDRCLK_EN(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_DDRCLK_EN_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_DDRCLK_EN_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_CONT_CLK_MODE_MASK (0x8U)
#define MIPI_CSI_CSR_PHY_CTRL_CONT_CLK_MODE_SHIFT (3U)
/*! CONT_CLK_MODE - Enables the slave clock lane feature to maintain HS reception state during
 *    continuous clock mode operation, despite line glitches.
 *  0b0..Feature disabled.
 *  0b1..Feature enabled.
 */
#define MIPI_CSI_CSR_PHY_CTRL_CONT_CLK_MODE(x)   (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_CONT_CLK_MODE_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_CONT_CLK_MODE_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_S_PRG_RXHS_SETTLE_MASK (0x3F0U)
#define MIPI_CSI_CSR_PHY_CTRL_S_PRG_RXHS_SETTLE_SHIFT (4U)
/*! S_PRG_RXHS_SETTLE - Bits used to program T_HS_SETTLE. HS-RX waits for Time-out T_HS_SETTLE in order to neglect transition effects. */
#define MIPI_CSI_CSR_PHY_CTRL_S_PRG_RXHS_SETTLE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_S_PRG_RXHS_SETTLE_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_S_PRG_RXHS_SETTLE_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_RTERM_SEL_MASK     (0x200000U)
#define MIPI_CSI_CSR_PHY_CTRL_RTERM_SEL_SHIFT    (21U)
/*! RTERM_SEL - Selects voltage levels that enable HS termination.
 *  0b0..LPCD levels enable HS termination (VIL-CD).
 *  0b1..LPRX levels enable HS termination (VIL-LP).
 */
#define MIPI_CSI_CSR_PHY_CTRL_RTERM_SEL(x)       (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_RTERM_SEL_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_RTERM_SEL_MASK)

#define MIPI_CSI_CSR_PHY_CTRL_PD_MASK            (0x400000U)
#define MIPI_CSI_CSR_PHY_CTRL_PD_SHIFT           (22U)
/*! PD - Power Down input for D-PHY. When high, all blocks are powered down. */
#define MIPI_CSI_CSR_PHY_CTRL_PD(x)              (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_CTRL_PD_SHIFT)) & MIPI_CSI_CSR_PHY_CTRL_PD_MASK)
/*! @} */

/*! @name PHY_STATUS -  */
/*! @{ */

#define MIPI_CSI_CSR_PHY_STATUS_LANES_STOPPED_MASK (0x1U)
#define MIPI_CSI_CSR_PHY_STATUS_LANES_STOPPED_SHIFT (0U)
/*! LANES_STOPPED - LANES_STOPPED (csi_controller.ulps_active[4:0] = 5'b0) */
#define MIPI_CSI_CSR_PHY_STATUS_LANES_STOPPED(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_PHY_STATUS_LANES_STOPPED_SHIFT)) & MIPI_CSI_CSR_PHY_STATUS_LANES_STOPPED_MASK)
/*! @} */

/*! @name VC_INTERLACED -  */
/*! @{ */

#define MIPI_CSI_CSR_VC_INTERLACED_VC0_MASK      (0x1U)
#define MIPI_CSI_CSR_VC_INTERLACED_VC0_SHIFT     (0U)
/*! VC0
 *  0b0..Default
 *  0b1..VC0 is interlaced
 */
#define MIPI_CSI_CSR_VC_INTERLACED_VC0(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_VC_INTERLACED_VC0_SHIFT)) & MIPI_CSI_CSR_VC_INTERLACED_VC0_MASK)

#define MIPI_CSI_CSR_VC_INTERLACED_VC1_MASK      (0x2U)
#define MIPI_CSI_CSR_VC_INTERLACED_VC1_SHIFT     (1U)
/*! VC1
 *  0b0..Default
 *  0b1..VC1 is interlaced
 */
#define MIPI_CSI_CSR_VC_INTERLACED_VC1(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_VC_INTERLACED_VC1_SHIFT)) & MIPI_CSI_CSR_VC_INTERLACED_VC1_MASK)

#define MIPI_CSI_CSR_VC_INTERLACED_VC2_MASK      (0x4U)
#define MIPI_CSI_CSR_VC_INTERLACED_VC2_SHIFT     (2U)
/*! VC2
 *  0b0..Default
 *  0b1..VC2 is interlaced
 */
#define MIPI_CSI_CSR_VC_INTERLACED_VC2(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_VC_INTERLACED_VC2_SHIFT)) & MIPI_CSI_CSR_VC_INTERLACED_VC2_MASK)

#define MIPI_CSI_CSR_VC_INTERLACED_VC3_MASK      (0x8U)
#define MIPI_CSI_CSR_VC_INTERLACED_VC3_SHIFT     (3U)
/*! VC3
 *  0b0..Default
 *  0b1..VC3 is interlaced
 */
#define MIPI_CSI_CSR_VC_INTERLACED_VC3(x)        (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_VC_INTERLACED_VC3_SHIFT)) & MIPI_CSI_CSR_VC_INTERLACED_VC3_MASK)
/*! @} */

/*! @name DATA_TYPE_DISABLE_BF -  */
/*! @{ */

#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_DATA_TYPE_DISABLE_MASK (0xFFFFFFU)
#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_DATA_TYPE_DISABLE_SHIFT (0U)
/*! DATA_TYPE_DISABLE - Data Type Disable */
#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_DATA_TYPE_DISABLE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_DATA_TYPE_DISABLE_SHIFT)) & MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_DATA_TYPE_DISABLE_MASK)

#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_NO_RAW_SHIFTING_MASK (0x80000000U)
#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_NO_RAW_SHIFTING_SHIFT (31U)
/*! NO_RAW_SHIFTING - When set, prevents shifting of RAW8 to RAW14 pixel format inside pixel reformatting module.
 *  0b0..RAW8 is changed to RAW14 (default).
 *  0b1..Prevents shitfing of RAW8 to RAW14 format.
 */
#define MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_NO_RAW_SHIFTING(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_NO_RAW_SHIFTING_SHIFT)) & MIPI_CSI_CSR_DATA_TYPE_DISABLE_BF_NO_RAW_SHIFTING_MASK)
/*! @} */

/*! @name YUV420_FIRST_LINE_DATA_TYPE -  */
/*! @{ */

#define MIPI_CSI_CSR_YUV420_FIRST_LINE_DATA_TYPE_YUV420_FIRST_LINE_DATA_TYPE_MASK (0x1U)
#define MIPI_CSI_CSR_YUV420_FIRST_LINE_DATA_TYPE_YUV420_FIRST_LINE_DATA_TYPE_SHIFT (0U)
/*! YUV420_FIRST_LINE_DATA_TYPE - YUV420_FIRST_LINE_DATA_TYPE
 *  0b0..Odd (reset value)
 *  0b1..Even
 */
#define MIPI_CSI_CSR_YUV420_FIRST_LINE_DATA_TYPE_YUV420_FIRST_LINE_DATA_TYPE(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_YUV420_FIRST_LINE_DATA_TYPE_YUV420_FIRST_LINE_DATA_TYPE_SHIFT)) & MIPI_CSI_CSR_YUV420_FIRST_LINE_DATA_TYPE_YUV420_FIRST_LINE_DATA_TYPE_MASK)
/*! @} */

/*! @name CONTROLLER_CLOCK_RESET_CONTROL -  */
/*! @{ */

#define MIPI_CSI_CSR_CONTROLLER_CLOCK_RESET_CONTROL_CONTROLLER_CLOCK_RESET_CONTROL_MASK (0x3U)
#define MIPI_CSI_CSR_CONTROLLER_CLOCK_RESET_CONTROL_CONTROLLER_CLOCK_RESET_CONTROL_SHIFT (0U)
/*! CONTROLLER_CLOCK_RESET_CONTROL - CONTROLLER_CLOCK_RESET_CONTROL
 *  0b00..SW_RESETN (reset value is 0)
 *  0b01..CTL_CLK_OFF (connect to LPCG) (reset value is 1)
 */
#define MIPI_CSI_CSR_CONTROLLER_CLOCK_RESET_CONTROL_CONTROLLER_CLOCK_RESET_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_CONTROLLER_CLOCK_RESET_CONTROL_CONTROLLER_CLOCK_RESET_CONTROL_SHIFT)) & MIPI_CSI_CSR_CONTROLLER_CLOCK_RESET_CONTROL_CONTROLLER_CLOCK_RESET_CONTROL_MASK)
/*! @} */

/*! @name STREAM_FENCING_CONTROL - Stream Fencing Control (RW - to Pixel Reformatter) */
/*! @{ */

#define MIPI_CSI_CSR_STREAM_FENCING_CONTROL_STREAM_FENCING_CONTROL_MASK (0xFU)
#define MIPI_CSI_CSR_STREAM_FENCING_CONTROL_STREAM_FENCING_CONTROL_SHIFT (0U)
/*! STREAM_FENCING_CONTROL
 *  0b0001..Fence VC0
 *  0b0010..Fence VC1
 *  0b0100..Fence VC2
 *  0b1000..Fence VC3
 */
#define MIPI_CSI_CSR_STREAM_FENCING_CONTROL_STREAM_FENCING_CONTROL(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_STREAM_FENCING_CONTROL_STREAM_FENCING_CONTROL_SHIFT)) & MIPI_CSI_CSR_STREAM_FENCING_CONTROL_STREAM_FENCING_CONTROL_MASK)
/*! @} */

/*! @name STREAM_FENCING_STATUS - Stream Fencing Status (RO - from Pixel Reformatter) */
/*! @{ */

#define MIPI_CSI_CSR_STREAM_FENCING_STATUS_STREAM_FENCING_STATUS_MASK (0xFU)
#define MIPI_CSI_CSR_STREAM_FENCING_STATUS_STREAM_FENCING_STATUS_SHIFT (0U)
/*! STREAM_FENCING_STATUS
 *  0b0001..VC0 is fenced
 *  0b0010..VC1 is fenced
 *  0b0100..VC2 is fenced
 *  0b1000..VC3 is fenced
 */
#define MIPI_CSI_CSR_STREAM_FENCING_STATUS_STREAM_FENCING_STATUS(x) (((uint32_t)(((uint32_t)(x)) << MIPI_CSI_CSR_STREAM_FENCING_STATUS_STREAM_FENCING_STATUS_SHIFT)) & MIPI_CSI_CSR_STREAM_FENCING_STATUS_STREAM_FENCING_STATUS_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MIPI_CSI_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group MIPI_CSI_CSR_Peripheral_Access_Layer */


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


#endif  /* PERI_MIPI_CSI_CSR_H_ */

