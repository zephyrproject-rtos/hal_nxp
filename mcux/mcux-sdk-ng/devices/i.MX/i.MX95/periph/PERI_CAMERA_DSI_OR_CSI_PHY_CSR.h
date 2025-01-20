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
**         CMSIS Peripheral Access Layer for CAMERA_DSI_OR_CSI_PHY_CSR
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
 * @file CAMERA_DSI_OR_CSI_PHY_CSR.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for CAMERA_DSI_OR_CSI_PHY_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_DSI_OR_CSI_PHY_CSR
 */

#if !defined(CAMERA_DSI_OR_CSI_PHY_CSR_H_)
#define CAMERA_DSI_OR_CSI_PHY_CSR_H_             /**< Symbol preventing repeated inclusion */

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
   -- CAMERA_DSI_OR_CSI_PHY_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_OR_CSI_PHY_CSR_Peripheral_Access_Layer CAMERA_DSI_OR_CSI_PHY_CSR Peripheral Access Layer
 * @{
 */

/** CAMERA_DSI_OR_CSI_PHY_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t STANDALONE_PHY_MODE_CONTROL;       /**< Rx DPHY mode control, offset: 0x0 */
  __IO uint32_t STANDALONE_PHY_FREQ_CONTROL;       /**< Rx DPHY frequency control, offset: 0x4 */
  __IO uint32_t STANDALONE_PHY_TEST_MODE_CONTROL;  /**< Rx DPHY test mode control, offset: 0x8 */
  __I  uint32_t STANDALONE_PHY_TEST_MODE_STATUS;   /**< Rx DPHY test mode status, offset: 0xC */
  __IO uint32_t STANDALONE_PHY_TEST_IO_CONT;       /**< Rx DPHY test IO continuity, offset: 0x10 */
       uint8_t RESERVED_0[236];
  __IO uint32_t COMBO_PHY_MODE_CONTROL;            /**< Rx/Tx DPHY mode control, offset: 0x100 */
  __IO uint32_t COMBO_PHY_FREQ_CONTROL;            /**< Rx/Tx DPHY frequency control, offset: 0x104 */
  __IO uint32_t COMBO_PHY_TEST_MODE_CONTROL;       /**< Rx/Tx DPHY test mode control, offset: 0x108 */
  __I  uint32_t COMBO_PHY_TEST_MODE_STATUS;        /**< Rx/Tx DPHY test mode status, offset: 0x10C */
  __IO uint32_t COMBO_PHY_TEST_IO_CONT;            /**< Rx/Tx DPHY test IO continuity, offset: 0x110 */
} CAMERA_DSI_OR_CSI_PHY_CSR_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_DSI_OR_CSI_PHY_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_DSI_OR_CSI_PHY_CSR_Register_Masks CAMERA_DSI_OR_CSI_PHY_CSR Register Masks
 * @{
 */

/*! @name STANDALONE_PHY_MODE_CONTROL - Rx DPHY mode control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK (0xF0U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT (4U)
/*! PHY_ENABLE_EXT - PHY lane enable for individual lane control
 *  0b0000..Disable individual lane control
 *  0b0001..Enable individual lane control
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK)
/*! @} */

/*! @name STANDALONE_PHY_FREQ_CONTROL - Rx DPHY frequency control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK (0x3FU)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT (0U)
/*! Phy_cfgclkfreqrange - System clock frequency configuration preset. */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK (0x7F0000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT (16U)
/*! Phy_hsfreqrange - High-speed frequency range selection */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)
/*! @} */

/*! @name STANDALONE_PHY_TEST_MODE_CONTROL - Rx DPHY test mode control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT (0U)
/*! basedir_0 - Base direction for lane 0
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_basedir_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK (0x10U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT (4U)
/*! forcetxstopmode_0 - Force lane module into transmit mode and generate Stop state for lane 0 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcetxstopmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK (0x100U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT (8U)
/*! forcerxmode_0 - Force lane module into receive mode/wait for Stop State for lane 0 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK (0x200U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT (9U)
/*! forcerxmode_1 - Force lane module into receive mode/wait for Stop State for lane 1 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_2_MASK (0x400U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_2_SHIFT (10U)
/*! forcerxmode_2 - Force lane module into receive mode/wait for Stop State for lane 2 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_3_MASK (0x800U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_3_SHIFT (11U)
/*! forcerxmode_3 - Force lane module into receive mode/wait for Stop State for lane 3 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_forcerxmode_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK (0x1000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT (12U)
/*! enableclk_ext
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turndisable_0_MASK (0x2000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT (13U)
/*! turndisable_0 - Disable Turn Around for Lane 0
 *  0b1..Disable turn around
 *  0b0..Allow turn around
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turndisable_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turndisable_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK (0x4000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT (14U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK (0x8000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT (15U)
/*! turnrequest_0 - Turn around request. */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turnrequest_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK)
/*! @} */

/*! @name STANDALONE_PHY_TEST_MODE_STATUS - Rx DPHY test mode status */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT (0U)
/*! ulpsactivenot_0 - Indicates lane 0 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK (0x2U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT (1U)
/*! ulpsactivenot_1 - Indicates lane 1 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK (0x4U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT (2U)
/*! ulpsactivenot_2 - Indicates lane 2 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK (0x8U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT (3U)
/*! ulpsactivenot_3 - Indicates lane 3 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_0_MASK (0x10U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT (4U)
/*! errcontrol_0 - Indicates control error for lane 0
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_1_MASK (0x20U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT (5U)
/*! errcontrol_1 - Indicates control error for lane 1
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_2_MASK (0x40U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT (6U)
/*! errcontrol_2 - Indicates control error for lane 2
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_3_MASK (0x80U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT (7U)
/*! errcontrol_3 - Indicates control error for lane 3
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_errcontrol_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_direction_0_MASK (0x100U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_direction_0_SHIFT (8U)
/*! direction_0 - Indicates the current direction of lane 0
 *  0b0..The lane is in transmit mode
 *  0b1..The lane is in receive mode
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_direction_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_direction_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_direction_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK (0x200U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT (9U)
/*! ulpsactivenotclk - Indicates that the clock lane is in the ULP state
 *  0b0..Clock lane is in ULP state
 *  0b1..Clock lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK)
/*! @} */

/*! @name STANDALONE_PHY_TEST_IO_CONT - Rx DPHY test IO continuity */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_Cont_en_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT (0U)
/*! Phy_Cont_en - IO continuity test mode enable
 *  0b1..Enable IO continuity test mode
 *  0b0..Disable IO continuity test mode
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_Cont_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_Cont_en_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_cont_data_MASK (0x7FF0000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT (16U)
/*! Phy_cont_data - Continuity data signals */
#define CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_cont_data(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_STANDALONE_PHY_TEST_IO_CONT_Phy_cont_data_MASK)
/*! @} */

/*! @name COMBO_PHY_MODE_CONTROL - Rx/Tx DPHY mode control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_Tx_Rxz_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_Tx_Rxz_SHIFT (0U)
/*! Tx_Rxz - PHY configuration
 *  0b0..CSI mode
 *  0b1..DSI mode
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_Tx_Rxz(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_Tx_Rxz_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_Tx_Rxz_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_clksel_MASK (0x6U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_clksel_SHIFT (1U)
/*! PLL_clksel - Control of PLL clock output selection
 *  0b00..Clocks stopped
 *  0b01..Clock generation
 *  0b10..Buffered clkext
 *  0b11..Reserved
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_clksel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_clksel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_clksel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_gp_clk_en_MASK (0x8U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_gp_clk_en_SHIFT (3U)
/*! PLL_gp_clk_en - Enable signal for clkout_gp clock.
 *  0b0..Disable gp_clk_en
 *  0b1..Enable
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_gp_clk_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_gp_clk_en_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PLL_gp_clk_en_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PHY_enable_ext_MASK (0xF0U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PHY_enable_ext_SHIFT (4U)
/*! PHY_enable_ext - PHY lane enable for individual lane control. */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PHY_enable_ext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PHY_enable_ext_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_MODE_CONTROL_PHY_enable_ext_MASK)
/*! @} */

/*! @name COMBO_PHY_FREQ_CONTROL - Rx/Tx DPHY frequency control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK (0xFFU)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT (0U)
/*! Phy_cfgclkfreqrange - System clock frequency configuration preset */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK (0x7F0000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT (16U)
/*! Phy_hsfreqrange - High-speed frequency range selection */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_hsfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)
/*! @} */

/*! @name COMBO_PHY_TEST_MODE_CONTROL - Rx/Tx DPHY test mode control */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_0_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT (0U)
/*! basedir_0 - Base direction for lane 0
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_1_MASK (0x2U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_1_SHIFT (1U)
/*! basedir_1 - Base direction for lane 1
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_2_MASK (0x4U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_2_SHIFT (2U)
/*! basedir_2 - Base direction for lane 2
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_3_MASK (0x8U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_3_SHIFT (3U)
/*! basedir_3 - Base direction for lane 3
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_basedir_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK (0x10U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT (4U)
/*! forcetxstopmode_0 - Force lane module into transmit mode and generate Stop state for lane 0
 *  0b0..Do not force lane module into transmit mode and Stop state following an error indication
 *  0b1..Force lane module into transmit mode and Stop state following an error indication
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_1_MASK (0x20U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_1_SHIFT (5U)
/*! forcetxstopmode_1 - Force lane module into transmit mode and generate Stop state for lane 1
 *  0b1..Force lane module into transmit mode and Stop state following an error indication
 *  0b0..Do not force lane module into transmit mode and Stop state following an error indication
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_2_MASK (0x40U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_2_SHIFT (6U)
/*! forcetxstopmode_2 - Force lane module into transmit mode and generate Stop state for lane 2
 *  0b1..Force lane module into transmit mode and Stop state following an error indication
 *  0b0..Do not force lane module into transmit mode and Stop state following an error indication
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_3_MASK (0x80U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_3_SHIFT (7U)
/*! forcetxstopmode_3 - Force lane module into transmit mode and generate Stop state for lane 3
 *  0b1..Force lane module into transmit mode and Stop state following an error indication
 *  0b0..Do not force lane module into transmit mode and Stop state following an error indication
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcetxstopmode_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK (0x100U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT (8U)
/*! forcerxmode_0 - Force lane module into receive mode/wait for Stop State for lane 0
 *  0b1..Force lane module into receive mode and wait for Stop state
 *  0b0..Do not force lane module into receive mode and wait for Stop state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK (0x200U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT (9U)
/*! forcerxmode_1 - Force lane module into receive mode/wait for Stop State for lane 1
 *  0b0..Do not force lane module into receive mode and wait for Stop state
 *  0b1..Force lane module into receive mode and wait for Stop state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_2_MASK (0x400U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_2_SHIFT (10U)
/*! forcerxmode_2 - Force lane module into receive mode/wait for Stop State for lane 2
 *  0b0..Do not force lane module into receive mode and wait for Stop state
 *  0b1..Force lane module into receive mode and wait for Stop state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_3_MASK (0x800U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_3_SHIFT (11U)
/*! forcerxmode_3 - Force lane module into receive mode/wait for Stop State for lane 3
 *  0b0..Do not force lane module into receive mode and wait for Stop state
 *  0b1..Force lane module into receive mode and wait for Stop state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_forcerxmode_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK (0x1000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT (12U)
/*! enableclk_ext - Enable clock lane
 *  0b0..Disable clock lane
 *  0b1..Enable clock lane
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_enableclk_ext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turndisable_0_MASK (0x2000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT (13U)
/*! turndisable_0 - Disable turn around for lane 0, Could be used only when the DSI/CSI complex is in DSI mode.
 *  0b0..Allow turn around
 *  0b1..Disable turn around
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turndisable_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turndisable_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK (0x4000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT (14U)
/*! phy_enable_byp - Mux select between CSI/DSI controllers generated PHY enable signals and external phy_enable_ext
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_phy_enable_byp(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turnrequest_0_sel_MASK (0x8000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turnrequest_0_sel_SHIFT (15U)
/*! turnrequest_0_sel - Mux select between controller generated and external turn around request signal
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turnrequest_0_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turnrequest_0_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_turnrequest_0_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txdatahs_sel_MASK (0x10000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txdatahs_sel_SHIFT (16U)
/*! txdatahs_sel - Mux select between controller generated and external high-speed data lanes
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txdatahs_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txdatahs_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txdatahs_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_MASK (0x20000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_SHIFT (17U)
/*! txbyteclkhs_sel - Mux select between controller generated and external high-speed transmit clock
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txbyteclkhs_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txulpsclk_sel_MASK (0x40000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txulpsclk_sel_SHIFT (18U)
/*! txulpsclk_sel - Mux select between controller generated and external transmit ULP signals
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txulpsclk_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txulpsclk_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txulpsclk_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txlp_data_esc_sel_MASK (0x80000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txlp_data_esc_sel_SHIFT (19U)
/*! txlp_data_esc_sel - Mux select between controller generated and external escape mode transmit data signals
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txlp_data_esc_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txlp_data_esc_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txlp_data_esc_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txclkesc_sel_MASK (0x100000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txclkesc_sel_SHIFT (20U)
/*! txclkesc_sel - Mux select between controller generated and external escape mode transmit clock
 *  0b0..Controller generated signals
 *  0b1..External signals
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txclkesc_sel(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txclkesc_sel_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_txclkesc_sel_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_biston_MASK (0x200000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_biston_SHIFT (21U)
/*! biston - Starts the HS bist test.
 *  0b0..BIST off
 *  0b1..Start BIST
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_biston(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_biston_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_CONTROL_biston_MASK)
/*! @} */

/*! @name COMBO_PHY_TEST_MODE_STATUS - Rx/Tx DPHY test mode status */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT (0U)
/*! ulpsactivenot_0 - Indicates lane 0 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK (0x2U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT (1U)
/*! ulpsactivenot_1 - Indicates lane 1 is in the Ultra Low Power (ULP) state
 *  0b1..Lane is not in ULP state
 *  0b0..Lane is in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK (0x4U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT (2U)
/*! ulpsactivenot_2 - Indicates lane 2 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK (0x8U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT (3U)
/*! ulpsactivenot_3 - Indicates lane 3 is in the Ultra Low Power (ULP) state
 *  0b1..Lane is not in ULP state
 *  0b0..Lane is in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenot_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_0_MASK (0x10U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT (4U)
/*! errcontrol_0 - Indicates control error for lane 0
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_0_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_1_MASK (0x20U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT (5U)
/*! errcontrol_1 - Indicates control error for lane 1
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_1_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_2_MASK (0x40U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT (6U)
/*! errcontrol_2 - Indicates control error for lane 2
 *  0b1..Control error detected
 *  0b0..No control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_2(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_2_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_2_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_3_MASK (0x80U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT (7U)
/*! errcontrol_3 - Indicates control error for lane 3
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_3(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_3_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_errcontrol_3_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_rxulpsclknot_MASK (0x100U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_rxulpsclknot_SHIFT (8U)
/*! rxulpsclknot - Indicates that the clock lane module has entered the ULP state
 *  0b1..Clock lane is not in ULP state
 *  0b0..Clock lane is in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_rxulpsclknot(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_rxulpsclknot_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_rxulpsclknot_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK (0x200U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT (9U)
/*! ulpsactivenotclk - Indicates that the clock lane is in the ULP state
 *  0b0..Clock lane is in ULP state
 *  0b1..Clock lane is not in ULP state
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_phy_lock_MASK (0x800U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_phy_lock_SHIFT (11U)
/*! phy_lock - PLL lock indication
 *  0b0..PLL is not locked
 *  0b1..PLL is locked
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_phy_lock(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_phy_lock_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_phy_lock_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistDone_MASK (0x1000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistDone_SHIFT (12U)
/*! BistDone - HS bist test done.
 *  0b0..HS bist test not done.
 *  0b1..HS bist test done.
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistDone(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistDone_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistDone_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistOK_MASK (0x2000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistOK_SHIFT (13U)
/*! BistOK - Status of BIST test
 *  0b1..BIST test is OK
 *  0b0..BIST test completed with errors
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistOK(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistOK_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_MODE_STATUS_BistOK_MASK)
/*! @} */

/*! @name COMBO_PHY_TEST_IO_CONT - Rx/Tx DPHY test IO continuity */
/*! @{ */

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_Cont_en_MASK (0x1U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT (0U)
/*! Phy_Cont_en - IO continuity test mode enable
 *  0b1..Enable IO continuity test mode
 *  0b0..Disable IO continuity test mode
 */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_Cont_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_Cont_en_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_Cont_en_MASK)

#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_cont_data_MASK (0x7FF0000U)
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT (16U)
/*! Phy_cont_data - Continuity data signals */
#define CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_cont_data(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_cont_data_SHIFT)) & CAMERA_DSI_OR_CSI_PHY_CSR_COMBO_PHY_TEST_IO_CONT_Phy_cont_data_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_DSI_OR_CSI_PHY_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_DSI_OR_CSI_PHY_CSR_Peripheral_Access_Layer */


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


#endif  /* CAMERA_DSI_OR_CSI_PHY_CSR_H_ */

