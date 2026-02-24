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
**         CMSIS Peripheral Access Layer for CAMERA_PHY_CSR
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
 * @file PERI_CAMERA_PHY_CSR.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for CAMERA_PHY_CSR
 *
 * CMSIS Peripheral Access Layer for CAMERA_PHY_CSR
 */

#if !defined(PERI_CAMERA_PHY_CSR_H_)
#define PERI_CAMERA_PHY_CSR_H_                   /**< Symbol preventing repeated inclusion */

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
   -- CAMERA_PHY_CSR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_PHY_CSR_Peripheral_Access_Layer CAMERA_PHY_CSR Peripheral Access Layer
 * @{
 */

/** CAMERA_PHY_CSR - Register Layout Typedef */
typedef struct {
  __IO uint32_t PRIMARY_PHY_MODE_CONTROL;          /**< PRIMARY Rx DPHY mode control, offset: 0x0 */
  __IO uint32_t PRIMARY_PHY_FREQ_CONTROL;          /**< PRIMARY Rx DPHY frequency control, offset: 0x4 */
  __IO uint32_t PRIMARY_PHY_TEST_MODE_CONTROL;     /**< PRIMARY Rx DPHY test mode control, offset: 0x8 */
  __I  uint32_t PRIMARY_PHY_TEST_MODE_STATUS;      /**< Primary Rx DPHY test mode status, offset: 0xC */
       uint8_t RESERVED_0[240];
  __IO uint32_t SECONDARY_PHY_MODE_CONTROL;        /**< Secondary Rx DPHY mode control, offset: 0x100 */
  __IO uint32_t SECONDARY_PHY_FREQ_CONTROL;        /**< Secondary Rx DPHY frequency control, offset: 0x104 */
  __IO uint32_t SECONDARY_PHY_TEST_MODE_CONTROL;   /**< Secondary Rx DPHY test mode control, offset: 0x108 */
  __I  uint32_t SECONDARY_PHY_TEST_MODE_STATUS;    /**< Secondary Rx DPHY test mode status, offset: 0x10C */
  __I  uint32_t LP_LOOPBACK_STATUS0;               /**< low power loopback test status register., offset: 0x110 */
  __I  uint32_t LP_LOOPBACK_STATUS1;               /**< low power loopback test status register., offset: 0x114 */
       uint8_t RESERVED_1[232];
  __IO uint32_t PHY_TEST_IO_CONT;                  /**< Rx DPHY test IO continuity, offset: 0x200 */
       uint8_t RESERVED_2[252];
  __IO uint32_t CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL; /**< CSI2_4L_2L_AGGR_COMPLEX mode control, offset: 0x300 */
} CAMERA_PHY_CSR_Type;

/* ----------------------------------------------------------------------------
   -- CAMERA_PHY_CSR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAMERA_PHY_CSR_Register_Masks CAMERA_PHY_CSR Register Masks
 * @{
 */

/*! @name PRIMARY_PHY_MODE_CONTROL - PRIMARY Rx DPHY mode control */
/*! @{ */

#define CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK (0x30U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT (4U)
/*! PHY_ENABLE_EXT - PHY lane enable for individual lane control
 *  0b00..Disable individual lane control
 *  0b01..Enable individual lane control
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK)
/*! @} */

/*! @name PRIMARY_PHY_FREQ_CONTROL - PRIMARY Rx DPHY frequency control */
/*! @{ */

#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK (0x3FU)
#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT (0U)
/*! Phy_cfgclkfreqrange - System clock frequency configuration preset. */
#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK (0x7F0000U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT (16U)
/*! Phy_hsfreqrange - High-speed frequency range selection */
#define CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)
/*! @} */

/*! @name PRIMARY_PHY_TEST_MODE_CONTROL - PRIMARY Rx DPHY test mode control */
/*! @{ */

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK (0x1U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT (0U)
/*! basedir_0 - Base direction for lane 0
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK (0x10U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT (4U)
/*! forcetxstopmode_0 - Force lane module into transmit mode and generate Stop state for lane 0 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK (0x100U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT (8U)
/*! forcerxmode_0 - Force lane module into receive mode/wait for Stop State for lane 0 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK (0x200U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT (9U)
/*! forcerxmode_1 - Force lane module into receive mode/wait for Stop State for lane 1 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK (0x1000U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT (12U)
/*! enableclk_ext
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turndisable_0_MASK (0x2000U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT (13U)
/*! turndisable_0 - Disable Turn Around for Lane 0
 *  0b0..Allow turn around
 *  0b1..Disable turn around
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turndisable_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turndisable_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK (0x4000U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT (14U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK (0x8000U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT (15U)
/*! turnrequest_0 - Turn around request. */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turnrequest_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK)
/*! @} */

/*! @name PRIMARY_PHY_TEST_MODE_STATUS - Primary Rx DPHY test mode status */
/*! @{ */

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK (0x1U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT (0U)
/*! ulpsactivenot_0 - Indicates lane 0 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK (0x2U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT (1U)
/*! ulpsactivenot_1 - Indicates lane 1 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_0_MASK (0x10U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT (4U)
/*! errcontrol_0 - Indicates control error for lane 0
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_1_MASK (0x20U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT (5U)
/*! errcontrol_1 - Indicates control error for lane 1
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_errcontrol_1_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_direction_0_MASK (0x100U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_direction_0_SHIFT (8U)
/*! direction_0 - Indicates the current direction of lane 0
 *  0b0..The lane is in transmit mode
 *  0b1..The lane is in receive mode
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_direction_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_direction_0_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_direction_0_MASK)

#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK (0x200U)
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT (9U)
/*! ulpsactivenotclk - Indicates that the clock lane is in the ULP state
 *  0b0..Clock lane is in ULP state
 *  0b1..Clock lane is not in ULP state
 */
#define CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT)) & CAMERA_PHY_CSR_PRIMARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK)
/*! @} */

/*! @name SECONDARY_PHY_MODE_CONTROL - Secondary Rx DPHY mode control */
/*! @{ */

#define CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK (0x30U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT (4U)
/*! PHY_ENABLE_EXT - PHY lane enable for individual lane control
 *  0b00..Disable individual lane control
 *  0b01..Enable individual lane control
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_MODE_CONTROL_PHY_ENABLE_EXT_MASK)
/*! @} */

/*! @name SECONDARY_PHY_FREQ_CONTROL - Secondary Rx DPHY frequency control */
/*! @{ */

#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK (0x3FU)
#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT (0U)
/*! Phy_cfgclkfreqrange - System clock frequency configuration preset. */
#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_cfgclkfreqrange_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK (0x7F0000U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT (16U)
/*! Phy_hsfreqrange - High-speed frequency range selection */
#define CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_FREQ_CONTROL_Phy_hsfreqrange_MASK)
/*! @} */

/*! @name SECONDARY_PHY_TEST_MODE_CONTROL - Secondary Rx DPHY test mode control */
/*! @{ */

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK (0x1U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT (0U)
/*! basedir_0 - Base direction for lane 0
 *  0b0..Configure lane as TX
 *  0b1..Configure lane as RX
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_basedir_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK (0x10U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT (4U)
/*! forcetxstopmode_0 - Force lane module into transmit mode and generate Stop state for lane 0 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcetxstopmode_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK (0x100U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT (8U)
/*! forcerxmode_0 - Force lane module into receive mode/wait for Stop State for lane 0 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK (0x200U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT (9U)
/*! forcerxmode_1 - Force lane module into receive mode/wait for Stop State for lane 1 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_forcerxmode_1_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK (0x1000U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT (12U)
/*! enableclk_ext
 *  0b0..Clock disabled
 *  0b1..Clock enabled
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_enableclk_ext_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turndisable_0_MASK (0x2000U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT (13U)
/*! turndisable_0 - Disable Turn Around for Lane 0
 *  0b0..Allow turn around
 *  0b1..Disable turn around
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turndisable_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turndisable_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turndisable_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK (0x4000U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT (14U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_phy_enable_byp_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK (0x8000U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT (15U)
/*! turnrequest_0 - Turn around request. */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turnrequest_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turnrequest_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_CONTROL_turnrequest_0_MASK)
/*! @} */

/*! @name SECONDARY_PHY_TEST_MODE_STATUS - Secondary Rx DPHY test mode status */
/*! @{ */

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK (0x1U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT (0U)
/*! ulpsactivenot_0 - Indicates lane 0 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK (0x2U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT (1U)
/*! ulpsactivenot_1 - Indicates lane 1 is in the Ultra Low Power (ULP) state
 *  0b0..Lane is in ULP state
 *  0b1..Lane is not in ULP state
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenot_1_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_0_MASK (0x10U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT (4U)
/*! errcontrol_0 - Indicates control error for lane 0
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_1_MASK (0x20U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT (5U)
/*! errcontrol_1 - Indicates control error for lane 1
 *  0b0..No control error detected
 *  0b1..Control error detected
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_1_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_errcontrol_1_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_direction_0_MASK (0x100U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_direction_0_SHIFT (8U)
/*! direction_0 - Indicates the current direction of lane 0
 *  0b0..The lane is in transmit mode
 *  0b1..The lane is in receive mode
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_direction_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_direction_0_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_direction_0_MASK)

#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK (0x200U)
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT (9U)
/*! ulpsactivenotclk - Indicates that the clock lane is in the ULP state
 *  0b0..Clock lane is in ULP state
 *  0b1..Clock lane is not in ULP state
 */
#define CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_SHIFT)) & CAMERA_PHY_CSR_SECONDARY_PHY_TEST_MODE_STATUS_ulpsactivenotclk_MASK)
/*! @} */

/*! @name LP_LOOPBACK_STATUS0 - low power loopback test status register. */
/*! @{ */

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_0_MASK (0xFFU)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_0_SHIFT (0U)
/*! pp_rxdataesc_0 - This is the 8-bit bus data output received by the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_1_MASK (0xFF00U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_1_SHIFT (8U)
/*! pp_rxdataesc_1 - This is the 8-bit bus data output received by the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_pp_rxdataesc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_0_MASK (0xFF0000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_0_SHIFT (16U)
/*! sp_rxdataesc_0 - This is the 8-bit bus data output received by the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_1_MASK (0xFF000000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_1_SHIFT (24U)
/*! sp_rxdataesc_1 - This is the 8-bit bus data output received by the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS0_sp_rxdataesc_1_MASK)
/*! @} */

/*! @name LP_LOOPBACK_STATUS1 - low power loopback test status register. */
/*! @{ */

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_0_MASK (0x1U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_0_SHIFT (0U)
/*! pp_rxvalidesc_0 - This signal indicates that the lane module is driving valid data to the protocol layer on the rxdataesc_N bus. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_1_MASK (0x2U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_1_SHIFT (1U)
/*! pp_rxvalidesc_1 - This signal indicates that the lane module is driving valid data to the protocol layer on the rxdataesc_N bus. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxvalidesc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_0_MASK (0x4U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_0_SHIFT (2U)
/*! sp_rxvalidesc_0 - This signal indicates that the lane module is driving valid data to the protocol layer on the rxdataesc_N bus. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_1_MASK (0x8U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_1_SHIFT (3U)
/*! sp_rxvalidesc_1 - This signal indicates that the lane module is driving valid data to the protocol layer on the rxdataesc_N bus. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxvalidesc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_0_MASK (0xF0U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_0_SHIFT (4U)
/*! pp_rxtriggeresc_0 - This signal indicates that a trigger event has been received in the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_1_MASK (0xF00U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_1_SHIFT (8U)
/*! pp_rxtriggeresc_1 - This signal indicates that a trigger event has been received in the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_rxtriggeresc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_0_MASK (0xF000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_0_SHIFT (12U)
/*! sp_rxtriggeresc_0 - This signal indicates that a trigger event has been received in the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_1_MASK (0xF0000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_1_SHIFT (16U)
/*! sp_rxtriggeresc_1 - This signal indicates that a trigger event has been received in the lane interconnect. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_rxtriggeresc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_0_MASK (0x100000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_0_SHIFT (20U)
/*! pp_errsyncesc_0 - Low-Power Data Transmission Synchronization Error. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_1_MASK (0x200000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_1_SHIFT (21U)
/*! pp_errsyncesc_1 - Low-Power Data Transmission Synchronization Error. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_pp_errsyncesc_1_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_0_MASK (0x400000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_0_SHIFT (22U)
/*! sp_errsyncesc_0 - Low-Power Data Transmission Synchronization Error. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_0(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_0_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_0_MASK)

#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_1_MASK (0x800000U)
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_1_SHIFT (23U)
/*! sp_errsyncesc_1 - Low-Power Data Transmission Synchronization Error. */
#define CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_1(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_1_SHIFT)) & CAMERA_PHY_CSR_LP_LOOPBACK_STATUS1_sp_errsyncesc_1_MASK)
/*! @} */

/*! @name PHY_TEST_IO_CONT - Rx DPHY test IO continuity */
/*! @{ */

#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en_MASK (0x1U)
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en_SHIFT (0U)
/*! Primary_phy_cont_en - IO continuity test mode enable
 *  0b0..Disable IO continuity test mode
 *  0b1..Enable IO continuity test mode
 */
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en_SHIFT)) & CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_en_MASK)

#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_en_MASK (0x2U)
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_en_SHIFT (1U)
/*! Secondary_phy_cont_en - IO continuity test mode enable
 *  0b0..Disable IO continuity test mode
 *  0b1..Enable IO continuity test mode
 */
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_en(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_en_SHIFT)) & CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_en_MASK)

#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_data_MASK (0x7F0000U)
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_data_SHIFT (16U)
/*! Primary_phy_cont_data - Continuity data signals */
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_data(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_data_SHIFT)) & CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Primary_phy_cont_data_MASK)

#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_data_MASK (0x3F800000U)
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_data_SHIFT (23U)
/*! Secondary_phy_cont_data - Continuity data signals */
#define CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_data(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_data_SHIFT)) & CAMERA_PHY_CSR_PHY_TEST_IO_CONT_Secondary_phy_cont_data_MASK)
/*! @} */

/*! @name CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL - CSI2_4L_2L_AGGR_COMPLEX mode control */
/*! @{ */

#define CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK (0x1U)
#define CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_SHIFT (0U)
/*! Aggr_mode - Selection between aggregated mode or standalone mode.
 *  0b0..Standalone mode
 *  0b1..Aggregated mode
 */
#define CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode(x) (((uint32_t)(((uint32_t)(x)) << CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_SHIFT)) & CAMERA_PHY_CSR_CSI2_4L_2L_AGGR_COMPLEX_MODE_CONTROL_Aggr_mode_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group CAMERA_PHY_CSR_Register_Masks */


/*!
 * @}
 */ /* end of group CAMERA_PHY_CSR_Peripheral_Access_Layer */


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


#endif  /* PERI_CAMERA_PHY_CSR_H_ */

