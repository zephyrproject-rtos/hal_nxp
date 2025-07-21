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
**         CMSIS Peripheral Access Layer for USBPHY
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
 * @file PERI_USBPHY.h
 * @version 6.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBPHY
 *
 * CMSIS Peripheral Access Layer for USBPHY
 */

#if !defined(PERI_USBPHY_H_)
#define PERI_USBPHY_H_                           /**< Symbol preventing repeated inclusion */

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
   -- USBPHY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Peripheral_Access_Layer USBPHY Peripheral Access Layer
 * @{
 */

/** USBPHY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PWD;                               /**< USBPHY Powerdown, offset: 0x0 */
  __IO uint32_t PWD_SET;                           /**< USBPHY Powerdown, offset: 0x4 */
  __IO uint32_t PWD_CLR;                           /**< USBPHY Powerdown, offset: 0x8 */
  __IO uint32_t PWD_TOG;                           /**< USBPHY Powerdown, offset: 0xC */
  __IO uint32_t TX;                                /**< USBPHY Transmitter Control, offset: 0x10 */
  __IO uint32_t TX_SET;                            /**< USBPHY Transmitter Control, offset: 0x14 */
  __IO uint32_t TX_CLR;                            /**< USBPHY Transmitter Control, offset: 0x18 */
  __IO uint32_t TX_TOG;                            /**< USBPHY Transmitter Control, offset: 0x1C */
  __IO uint32_t RX;                                /**< USBPHY Receiver Control, offset: 0x20 */
  __IO uint32_t RX_SET;                            /**< USBPHY Receiver Control, offset: 0x24 */
  __IO uint32_t RX_CLR;                            /**< USBPHY Receiver Control, offset: 0x28 */
  __IO uint32_t RX_TOG;                            /**< USBPHY Receiver Control, offset: 0x2C */
  __IO uint32_t CTRL;                              /**< USBPHY General Control, offset: 0x30 */
  __IO uint32_t CTRL_SET;                          /**< USBPHY General Control, offset: 0x34 */
  __IO uint32_t CTRL_CLR;                          /**< USBPHY General Control, offset: 0x38 */
  __IO uint32_t CTRL_TOG;                          /**< USBPHY General Control, offset: 0x3C */
  __I  uint32_t STATUS;                            /**< USBPHY Status, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DEBUGr;                            /**< USBPHY Debug, offset: 0x50, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
  __IO uint32_t DEBUG_SET;                         /**< USBPHY Debug, offset: 0x54 */
  __IO uint32_t DEBUG_CLR;                         /**< USBPHY Debug, offset: 0x58 */
  __IO uint32_t DEBUG_TOG;                         /**< USBPHY Debug, offset: 0x5C */
  __I  uint32_t DEBUG0_STATUS;                     /**< UTMI Debug Status 0, offset: 0x60 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DEBUG1;                            /**< UTMI Debug Status 1, offset: 0x70 */
  __IO uint32_t DEBUG1_SET;                        /**< UTMI Debug Status 1, offset: 0x74 */
  __IO uint32_t DEBUG1_CLR;                        /**< UTMI Debug Status 1, offset: 0x78 */
  __IO uint32_t DEBUG1_TOG;                        /**< UTMI Debug Status 1, offset: 0x7C */
  __I  uint32_t VERSION;                           /**< USBPHY Version, offset: 0x80 */
       uint8_t RESERVED_2[28];
  __IO uint32_t PLL_SIC;                           /**< USBPHY PLL Control and Status, offset: 0xA0 */
  __IO uint32_t PLL_SIC_SET;                       /**< USBPHY PLL Control and Status, offset: 0xA4 */
  __IO uint32_t PLL_SIC_CLR;                       /**< USBPHY PLL Control and Status, offset: 0xA8 */
  __IO uint32_t PLL_SIC_TOG;                       /**< USBPHY PLL Control and Status, offset: 0xAC */
       uint8_t RESERVED_3[16];
  __IO uint32_t USB1_VBUS_DETECT;                  /**< USBPHY VBUS Detect Control, offset: 0xC0 */
  __IO uint32_t USB1_VBUS_DETECT_SET;              /**< USBPHY VBUS Detect Control, offset: 0xC4 */
  __IO uint32_t USB1_VBUS_DETECT_CLR;              /**< USBPHY VBUS Detect Control, offset: 0xC8 */
  __IO uint32_t USB1_VBUS_DETECT_TOG;              /**< USBPHY VBUS Detect Control, offset: 0xCC */
  __I  uint32_t USB1_VBUS_DET_STAT;                /**< USBPHY VBUS Detector Status, offset: 0xD0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t USB1_CHRG_DETECT;                  /**< USBPHY Charger Detect Control, offset: 0xE0 */
  __IO uint32_t USB1_CHRG_DETECT_SET;              /**< USBPHY Charger Detect Control, offset: 0xE4 */
  __IO uint32_t USB1_CHRG_DETECT_CLR;              /**< USBPHY Charger Detect Control, offset: 0xE8 */
  __IO uint32_t USB1_CHRG_DETECT_TOG;              /**< USBPHY Charger Detect Control, offset: 0xEC */
  __I  uint32_t USB1_CHRG_DET_STAT;                /**< USBPHY Charger Detect Status, offset: 0xF0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t ANACTRL;                           /**< USBPHY Analog Control, offset: 0x100 */
  __IO uint32_t ANACTRL_SET;                       /**< USBPHY Analog Control, offset: 0x104 */
  __IO uint32_t ANACTRL_CLR;                       /**< USBPHY Analog Control, offset: 0x108 */
  __IO uint32_t ANACTRL_TOG;                       /**< USBPHY Analog Control, offset: 0x10C */
  __IO uint32_t USB1_LOOPBACK;                     /**< USBPHY Loopback Control and Status, offset: 0x110 */
  __IO uint32_t USB1_LOOPBACK_SET;                 /**< USBPHY Loopback Control and Status, offset: 0x114 */
  __IO uint32_t USB1_LOOPBACK_CLR;                 /**< USBPHY Loopback Control and Status, offset: 0x118 */
  __IO uint32_t USB1_LOOPBACK_TOG;                 /**< USBPHY Loopback Control and Status, offset: 0x11C */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT;             /**< USBPHY Loopback Packet Number Selection, offset: 0x120 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_SET;         /**< USBPHY Loopback Packet Number Selection, offset: 0x124 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_CLR;         /**< USBPHY Loopback Packet Number Selection, offset: 0x128 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_TOG;         /**< USBPHY Loopback Packet Number Selection, offset: 0x12C */
  __IO uint32_t TRIM_OVERRIDE_EN;                  /**< USBPHY Trim Override Enable, offset: 0x130 */
  __IO uint32_t TRIM_OVERRIDE_EN_SET;              /**< USBPHY Trim Override Enable, offset: 0x134 */
  __IO uint32_t TRIM_OVERRIDE_EN_CLR;              /**< USBPHY Trim Override Enable, offset: 0x138 */
  __IO uint32_t TRIM_OVERRIDE_EN_TOG;              /**< USBPHY Trim Override Enable, offset: 0x13C */
} USBPHY_Type;

/* ----------------------------------------------------------------------------
   -- USBPHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Register_Masks USBPHY Register Masks
 * @{
 */

/*! @name PWD - USBPHY Powerdown */
/*! @{ */

#define USBPHY_PWD_TXPWDFS_MASK                  (0x400U)
#define USBPHY_PWD_TXPWDFS_SHIFT                 (10U)
/*! TXPWDFS - FS Transmitter Powerdown
 *  0b0..Provide bias to enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDFS(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDFS_SHIFT)) & USBPHY_PWD_TXPWDFS_MASK)

#define USBPHY_PWD_TXPWDIBIAS_MASK               (0x800U)
#define USBPHY_PWD_TXPWDIBIAS_SHIFT              (11U)
/*! TXPWDIBIAS - Transmitter Bias Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDIBIAS(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TXPWDV2I_MASK                 (0x1000U)
#define USBPHY_PWD_TXPWDV2I_SHIFT                (12U)
/*! TXPWDV2I - USBPHY TX V-I Converter and Current Mirror Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_TXPWDV2I(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDV2I_SHIFT)) & USBPHY_PWD_TXPWDV2I_MASK)

#define USBPHY_PWD_RXPWDENV_MASK                 (0x20000U)
#define USBPHY_PWD_RXPWDENV_SHIFT                (17U)
/*! RXPWDENV - Receiver Envelope Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWDENV(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDENV_SHIFT)) & USBPHY_PWD_RXPWDENV_MASK)

#define USBPHY_PWD_RXPWD1PT1_MASK                (0x40000U)
#define USBPHY_PWD_RXPWD1PT1_SHIFT               (18U)
/*! RXPWD1PT1 - FS Receiver Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWD1PT1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWD1PT1_SHIFT)) & USBPHY_PWD_RXPWD1PT1_MASK)

#define USBPHY_PWD_RXPWDDIFF_MASK                (0x80000U)
#define USBPHY_PWD_RXPWDDIFF_SHIFT               (19U)
/*! RXPWDDIFF - HS Receiver Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down
 */
#define USBPHY_PWD_RXPWDDIFF(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDDIFF_SHIFT)) & USBPHY_PWD_RXPWDDIFF_MASK)

#define USBPHY_PWD_RXPWDRX_MASK                  (0x100000U)
#define USBPHY_PWD_RXPWDRX_SHIFT                 (20U)
/*! RXPWDRX - Receiver Powerdown
 *  0b0..Enable for normal operation
 *  0b1..Disable or power down RX circuits
 */
#define USBPHY_PWD_RXPWDRX(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDRX_SHIFT)) & USBPHY_PWD_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_SET - USBPHY Powerdown */
/*! @{ */

#define USBPHY_PWD_SET_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_SET_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - FS Transmitter Powerdown */
#define USBPHY_PWD_SET_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDFS_SHIFT)) & USBPHY_PWD_SET_TXPWDFS_MASK)

#define USBPHY_PWD_SET_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_SET_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Transmitter Bias Powerdown */
#define USBPHY_PWD_SET_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_SET_TXPWDIBIAS_MASK)

#define USBPHY_PWD_SET_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_SET_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - USBPHY TX V-I Converter and Current Mirror Powerdown */
#define USBPHY_PWD_SET_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDV2I_SHIFT)) & USBPHY_PWD_SET_TXPWDV2I_MASK)

#define USBPHY_PWD_SET_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_SET_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Receiver Envelope Powerdown */
#define USBPHY_PWD_SET_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDENV_SHIFT)) & USBPHY_PWD_SET_RXPWDENV_MASK)

#define USBPHY_PWD_SET_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_SET_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - FS Receiver Powerdown */
#define USBPHY_PWD_SET_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWD1PT1_SHIFT)) & USBPHY_PWD_SET_RXPWD1PT1_MASK)

#define USBPHY_PWD_SET_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_SET_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - HS Receiver Powerdown */
#define USBPHY_PWD_SET_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDDIFF_SHIFT)) & USBPHY_PWD_SET_RXPWDDIFF_MASK)

#define USBPHY_PWD_SET_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_SET_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Receiver Powerdown */
#define USBPHY_PWD_SET_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDRX_SHIFT)) & USBPHY_PWD_SET_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_CLR - USBPHY Powerdown */
/*! @{ */

#define USBPHY_PWD_CLR_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_CLR_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - FS Transmitter Powerdown */
#define USBPHY_PWD_CLR_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDFS_SHIFT)) & USBPHY_PWD_CLR_TXPWDFS_MASK)

#define USBPHY_PWD_CLR_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Transmitter Bias Powerdown */
#define USBPHY_PWD_CLR_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_CLR_TXPWDIBIAS_MASK)

#define USBPHY_PWD_CLR_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_CLR_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - USBPHY TX V-I Converter and Current Mirror Powerdown */
#define USBPHY_PWD_CLR_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDV2I_SHIFT)) & USBPHY_PWD_CLR_TXPWDV2I_MASK)

#define USBPHY_PWD_CLR_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_CLR_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Receiver Envelope Powerdown */
#define USBPHY_PWD_CLR_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDENV_SHIFT)) & USBPHY_PWD_CLR_RXPWDENV_MASK)

#define USBPHY_PWD_CLR_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_CLR_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - FS Receiver Powerdown */
#define USBPHY_PWD_CLR_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWD1PT1_SHIFT)) & USBPHY_PWD_CLR_RXPWD1PT1_MASK)

#define USBPHY_PWD_CLR_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_CLR_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - HS Receiver Powerdown */
#define USBPHY_PWD_CLR_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDDIFF_SHIFT)) & USBPHY_PWD_CLR_RXPWDDIFF_MASK)

#define USBPHY_PWD_CLR_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_CLR_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Receiver Powerdown */
#define USBPHY_PWD_CLR_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDRX_SHIFT)) & USBPHY_PWD_CLR_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_TOG - USBPHY Powerdown */
/*! @{ */

#define USBPHY_PWD_TOG_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_TOG_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - FS Transmitter Powerdown */
#define USBPHY_PWD_TOG_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDFS_SHIFT)) & USBPHY_PWD_TOG_TXPWDFS_MASK)

#define USBPHY_PWD_TOG_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Transmitter Bias Powerdown */
#define USBPHY_PWD_TOG_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TOG_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TOG_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_TOG_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - USBPHY TX V-I Converter and Current Mirror Powerdown */
#define USBPHY_PWD_TOG_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDV2I_SHIFT)) & USBPHY_PWD_TOG_TXPWDV2I_MASK)

#define USBPHY_PWD_TOG_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_TOG_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Receiver Envelope Powerdown */
#define USBPHY_PWD_TOG_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDENV_SHIFT)) & USBPHY_PWD_TOG_RXPWDENV_MASK)

#define USBPHY_PWD_TOG_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_TOG_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - FS Receiver Powerdown */
#define USBPHY_PWD_TOG_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWD1PT1_SHIFT)) & USBPHY_PWD_TOG_RXPWD1PT1_MASK)

#define USBPHY_PWD_TOG_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_TOG_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - HS Receiver Powerdown */
#define USBPHY_PWD_TOG_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDDIFF_SHIFT)) & USBPHY_PWD_TOG_RXPWDDIFF_MASK)

#define USBPHY_PWD_TOG_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_TOG_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Receiver Powerdown */
#define USBPHY_PWD_TOG_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDRX_SHIFT)) & USBPHY_PWD_TOG_RXPWDRX_MASK)
/*! @} */

/*! @name TX - USBPHY Transmitter Control */
/*! @{ */

#define USBPHY_TX_D_CAL_MASK                     (0xFU)
#define USBPHY_TX_D_CAL_SHIFT                    (0U)
/*! D_CAL - HS Transmit Output Current Trim
 *  0b0000..+20.30%
 *  0b0001..+17.60%
 *  0b0010..+14.80%
 *  0b0011..+12.60%
 *  0b0100..+8.79%
 *  0b0101..+6.04%
 *  0b0110..+2.75%
 *  0b0111..0%
 *  0b1000..-2.75%
 *  0b1001..-5.49%
 *  0b1010..-7.69%
 *  0b1011..-10.40%
 *  0b1100..-12.60%
 *  0b1101..-14.30%
 *  0b1110..-18.10%
 *  0b1111..-22.00%
 */
#define USBPHY_TX_D_CAL(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TX_D_CAL_MASK)

#define USBPHY_TX_TXCAL45DN_MASK                 (0xF00U)
#define USBPHY_TX_TXCAL45DN_SHIFT                (8U)
/*! TXCAL45DN - Transmit Calculation 45 ohm DN
 *  0b0000..+19.95%
 *  0b0001..+17.35%
 *  0b0010..+14.85%
 *  0b0011..+12.46%
 *  0b0100..+9.07%
 *  0b0101..+5.87%
 *  0b0110..+2.85%
 *  0b0111..0%
 *  0b1000..-2.70%
 *  0b1001..-5.25%
 *  0b1010..-7.67%
 *  0b1011..-9.98%
 *  0b1100..-12.17%
 *  0b1101..-14.25%
 *  0b1110..-18.14%
 *  0b1111..-21.68%
 */
#define USBPHY_TX_TXCAL45DN(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DN_SHIFT)) & USBPHY_TX_TXCAL45DN_MASK)

#define USBPHY_TX_TXCAL45DP_MASK                 (0xF0000U)
#define USBPHY_TX_TXCAL45DP_SHIFT                (16U)
/*! TXCAL45DP - Transmit Calculation 45 ohm DP
 *  0b0000..+19.95%
 *  0b0001..+17.35%
 *  0b0010..+14.85%
 *  0b0011..+12.46%
 *  0b0100..+9.07%
 *  0b0101..+5.87%
 *  0b0110..+2.85%
 *  0b0111..0%
 *  0b1000..-2.70%
 *  0b1001..-5.25%
 *  0b1010..-7.67%
 *  0b1011..-9.98%
 *  0b1100..-12.17%
 *  0b1101..-14.25%
 *  0b1110..-18.14%
 *  0b1111..-21.68%
 */
#define USBPHY_TX_TXCAL45DP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DP_SHIFT)) & USBPHY_TX_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_SET - USBPHY Transmitter Control */
/*! @{ */

#define USBPHY_TX_SET_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_SET_D_CAL_SHIFT                (0U)
/*! D_CAL - HS Transmit Output Current Trim */
#define USBPHY_TX_SET_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_D_CAL_SHIFT)) & USBPHY_TX_SET_D_CAL_MASK)

#define USBPHY_TX_SET_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_SET_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - Transmit Calculation 45 ohm DN */
#define USBPHY_TX_SET_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DN_SHIFT)) & USBPHY_TX_SET_TXCAL45DN_MASK)

#define USBPHY_TX_SET_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_SET_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - Transmit Calculation 45 ohm DP */
#define USBPHY_TX_SET_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DP_SHIFT)) & USBPHY_TX_SET_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_CLR - USBPHY Transmitter Control */
/*! @{ */

#define USBPHY_TX_CLR_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_CLR_D_CAL_SHIFT                (0U)
/*! D_CAL - HS Transmit Output Current Trim */
#define USBPHY_TX_CLR_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_D_CAL_SHIFT)) & USBPHY_TX_CLR_D_CAL_MASK)

#define USBPHY_TX_CLR_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_CLR_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - Transmit Calculation 45 ohm DN */
#define USBPHY_TX_CLR_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DN_SHIFT)) & USBPHY_TX_CLR_TXCAL45DN_MASK)

#define USBPHY_TX_CLR_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_CLR_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - Transmit Calculation 45 ohm DP */
#define USBPHY_TX_CLR_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DP_SHIFT)) & USBPHY_TX_CLR_TXCAL45DP_MASK)
/*! @} */

/*! @name TX_TOG - USBPHY Transmitter Control */
/*! @{ */

#define USBPHY_TX_TOG_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_TOG_D_CAL_SHIFT                (0U)
/*! D_CAL - HS Transmit Output Current Trim */
#define USBPHY_TX_TOG_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_D_CAL_SHIFT)) & USBPHY_TX_TOG_D_CAL_MASK)

#define USBPHY_TX_TOG_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_TOG_TXCAL45DN_SHIFT            (8U)
/*! TXCAL45DN - Transmit Calculation 45 ohm DN */
#define USBPHY_TX_TOG_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DN_SHIFT)) & USBPHY_TX_TOG_TXCAL45DN_MASK)

#define USBPHY_TX_TOG_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_TOG_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - Transmit Calculation 45 ohm DP */
#define USBPHY_TX_TOG_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DP_SHIFT)) & USBPHY_TX_TOG_TXCAL45DP_MASK)
/*! @} */

/*! @name RX - USBPHY Receiver Control */
/*! @{ */

#define USBPHY_RX_ENVADJ_MASK                    (0x7U)
#define USBPHY_RX_ENVADJ_SHIFT                   (0U)
/*! ENVADJ - Envelope Adjustment
 *  0b000..0.1000 V
 *  0b001..0.1125 V
 *  0b010..0.1250 V
 *  0b011..0.0875 V
 *  0b1xx..Reserved
 */
#define USBPHY_RX_ENVADJ(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_ENVADJ_SHIFT)) & USBPHY_RX_ENVADJ_MASK)

#define USBPHY_RX_DISCONADJ_MASK                 (0x70U)
#define USBPHY_RX_DISCONADJ_SHIFT                (4U)
/*! DISCONADJ - Disconnect Adjustment
 *  0b000..0.56875 V
 *  0b001..0.55000 V
 *  0b010..0.58125 V
 *  0b011..0.60000 V
 *  0b1xx..Reserved
 */
#define USBPHY_RX_DISCONADJ(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_DISCONADJ_SHIFT)) & USBPHY_RX_DISCONADJ_MASK)

#define USBPHY_RX_RXDBYPASS_MASK                 (0x400000U)
#define USBPHY_RX_RXDBYPASS_SHIFT                (22U)
/*! RXDBYPASS - Differential Receiver Bypass
 *  0b0..Operate normally
 *  0b1..Bypass
 */
#define USBPHY_RX_RXDBYPASS(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RXDBYPASS_SHIFT)) & USBPHY_RX_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_SET - USBPHY Receiver Control */
/*! @{ */

#define USBPHY_RX_SET_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_SET_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Adjustment */
#define USBPHY_RX_SET_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_ENVADJ_SHIFT)) & USBPHY_RX_SET_ENVADJ_MASK)

#define USBPHY_RX_SET_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_SET_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Adjustment */
#define USBPHY_RX_SET_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_DISCONADJ_SHIFT)) & USBPHY_RX_SET_DISCONADJ_MASK)

#define USBPHY_RX_SET_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_SET_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - Differential Receiver Bypass */
#define USBPHY_RX_SET_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RXDBYPASS_SHIFT)) & USBPHY_RX_SET_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_CLR - USBPHY Receiver Control */
/*! @{ */

#define USBPHY_RX_CLR_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_CLR_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Adjustment */
#define USBPHY_RX_CLR_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_ENVADJ_SHIFT)) & USBPHY_RX_CLR_ENVADJ_MASK)

#define USBPHY_RX_CLR_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_CLR_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Adjustment */
#define USBPHY_RX_CLR_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_DISCONADJ_SHIFT)) & USBPHY_RX_CLR_DISCONADJ_MASK)

#define USBPHY_RX_CLR_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_CLR_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - Differential Receiver Bypass */
#define USBPHY_RX_CLR_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RXDBYPASS_SHIFT)) & USBPHY_RX_CLR_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_TOG - USBPHY Receiver Control */
/*! @{ */

#define USBPHY_RX_TOG_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_TOG_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope Adjustment */
#define USBPHY_RX_TOG_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_ENVADJ_SHIFT)) & USBPHY_RX_TOG_ENVADJ_MASK)

#define USBPHY_RX_TOG_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_TOG_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect Adjustment */
#define USBPHY_RX_TOG_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_DISCONADJ_SHIFT)) & USBPHY_RX_TOG_DISCONADJ_MASK)

#define USBPHY_RX_TOG_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_TOG_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - Differential Receiver Bypass */
#define USBPHY_RX_TOG_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RXDBYPASS_SHIFT)) & USBPHY_RX_TOG_RXDBYPASS_MASK)
/*! @} */

/*! @name CTRL - USBPHY General Control */
/*! @{ */

#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK        (0x1U)
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT       (0U)
/*! ENOTG_ID_CHG_IRQ - ID Change Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENHOSTDISCONDETECT_MASK      (0x2U)
#define USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT     (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENHOSTDISCONDETECT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_ENIRQHOSTDISCON_MASK         (0x4U)
#define USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT        (2U)
/*! ENIRQHOSTDISCON - Host Disconnect Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQHOSTDISCON(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK    (0x8U)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT   (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt
 *  0b0..Connected
 *  0b1..Disconnected
 */
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_ENDEVPLUGINDETECT_MASK       (0x10U)
#define USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT      (4U)
/*! ENDEVPLUGINDETECT - Nonstandard Resistive Plugged-In Detection Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENDEVPLUGINDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK      (0x20U)
#define USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT     (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity
 *  0b0..Plugged in
 *  0b1..Unplugged
 */
#define USBPHY_CTRL_DEVPLUGIN_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK          (0x40U)
#define USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT         (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt
 *  0b0..No ID change interrupt
 *  0b1..ID change interrupt
 */
#define USBPHY_CTRL_OTG_ID_CHG_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENOTGIDDETECT_MASK           (0x80U)
#define USBPHY_CTRL_ENOTGIDDETECT_SHIFT          (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENOTGIDDETECT(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_RESUMEIRQSTICKY_MASK         (0x100U)
#define USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT        (8U)
/*! RESUMEIRQSTICKY - RESUME_IRQ Sticky
 *  0b0..Remains 1 during the wake-up period
 *  0b1..Remains 1 until you write 0 to it
 */
#define USBPHY_CTRL_RESUMEIRQSTICKY(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_ENIRQRESUMEDETECT_MASK       (0x200U)
#define USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT      (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQRESUMEDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_RESUME_IRQ_MASK              (0x400U)
#define USBPHY_CTRL_RESUME_IRQ_SHIFT             (10U)
/*! RESUME_IRQ - Interrupt Resume
 *  0b0..No resume interrupt
 *  0b1..Resume interrupt
 */
#define USBPHY_CTRL_RESUME_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_RESUME_IRQ_MASK)

#define USBPHY_CTRL_ENIRQDEVPLUGIN_MASK          (0x800U)
#define USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT         (11U)
/*! ENIRQDEVPLUGIN - Device Plug-In Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQDEVPLUGIN(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_DEVPLUGIN_IRQ_MASK           (0x1000U)
#define USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT          (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt
 *  0b0..Not connected
 *  0b1..Connected
 */
#define USBPHY_CTRL_DEVPLUGIN_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_ENUTMILEVEL2_MASK            (0x4000U)
#define USBPHY_CTRL_ENUTMILEVEL2_SHIFT           (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENUTMILEVEL2(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_ENUTMILEVEL3_MASK            (0x8000U)
#define USBPHY_CTRL_ENUTMILEVEL3_SHIFT           (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENUTMILEVEL3(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_ENIRQWAKEUP_MASK             (0x10000U)
#define USBPHY_CTRL_ENIRQWAKEUP_SHIFT            (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENIRQWAKEUP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_WAKEUP_IRQ_MASK              (0x20000U)
#define USBPHY_CTRL_WAKEUP_IRQ_SHIFT             (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt
 *  0b0..No wake-up event exists
 *  0b1..Wake-up event exists
 */
#define USBPHY_CTRL_WAKEUP_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_AUTORESUME_EN_MASK           (0x40000U)
#define USBPHY_CTRL_AUTORESUME_EN_SHIFT          (18U)
/*! AUTORESUME_EN - Auto Resume Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_AUTORESUME_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK       (0x80000U)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT      (19U)
/*! ENAUTOCLR_CLKGATE - Clock Gating Auto Clear Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK       (0x100000U)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT      (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Auto Clear Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_FSDLL_RST_EN_MASK            (0x1000000U)
#define USBPHY_CTRL_FSDLL_RST_EN_SHIFT           (24U)
/*! FSDLL_RST_EN - FSDLL Reset Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_CTRL_FSDLL_RST_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_OTG_ID_VALUE_MASK            (0x8000000U)
#define USBPHY_CTRL_OTG_ID_VALUE_SHIFT           (27U)
/*! OTG_ID_VALUE - ID Value
 *  0b0..Lesser ID resistance than Ra_Plug_ID
 *  0b1..Greater ID resistance than Rb_Plug_ID
 */
#define USBPHY_CTRL_OTG_ID_VALUE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK       (0x10000000U)
#define USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT      (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP LS Timing
 *  0b0..Do not force the next FS packet
 *  0b1..Force the next FS packet
 */
#define USBPHY_CTRL_HOST_FORCE_LS_SE0(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_UTMI_SUSPENDM_MASK           (0x20000000U)
#define USBPHY_CTRL_UTMI_SUSPENDM_SHIFT          (29U)
/*! UTMI_SUSPENDM - UTMI Suspend Mode
 *  0b0..Not suspended
 *  0b1..Suspended
 */
#define USBPHY_CTRL_UTMI_SUSPENDM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLKGATE_MASK                 (0x40000000U)
#define USBPHY_CTRL_CLKGATE_SHIFT                (30U)
/*! CLKGATE - Clock Gating
 *  0b0..Run clocks
 *  0b1..Gate clocks
 */
#define USBPHY_CTRL_CLKGATE(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLKGATE_SHIFT)) & USBPHY_CTRL_CLKGATE_MASK)

#define USBPHY_CTRL_SFTRST_MASK                  (0x80000000U)
#define USBPHY_CTRL_SFTRST_SHIFT                 (31U)
/*! SFTRST - Software Reset
 *  0b0..Release from reset
 *  0b1..Reset
 */
#define USBPHY_CTRL_SFTRST(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SFTRST_SHIFT)) & USBPHY_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - USBPHY General Control */
/*! @{ */

#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - ID Change Interrupt Enable */
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Host Disconnect Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Nonstandard Resistive Plugged-In Detection Enable */
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_SET_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_SET_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - RESUME_IRQ Sticky */
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_SET_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_SET_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Interrupt Resume */
#define USBPHY_CTRL_SET_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_SET_RESUME_IRQ_MASK)

#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Device Plug-In Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_SET_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_SET_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_SET_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_SET_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_SET_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_SET_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_SET_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_SET_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_SET_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Auto Resume Enable */
#define USBPHY_CTRL_SET_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_SET_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Clock Gating Auto Clear Enable */
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Auto Clear Enable */
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_SET_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - FSDLL Reset Enable */
#define USBPHY_CTRL_SET_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_SET_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_SET_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - ID Value */
#define USBPHY_CTRL_SET_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP LS Timing */
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend Mode */
#define USBPHY_CTRL_SET_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_SET_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_SET_CLKGATE_SHIFT            (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_CTRL_SET_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_CLKGATE_MASK)

#define USBPHY_CTRL_SET_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_SET_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_SET_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_SFTRST_SHIFT)) & USBPHY_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - USBPHY General Control */
/*! @{ */

#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - ID Change Interrupt Enable */
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Host Disconnect Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Nonstandard Resistive Plugged-In Detection Enable */
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_CLR_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - RESUME_IRQ Sticky */
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Interrupt Resume */
#define USBPHY_CTRL_CLR_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_CLR_RESUME_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Device Plug-In Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_CLR_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_CLR_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_CLR_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_CLR_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_CLR_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Auto Resume Enable */
#define USBPHY_CTRL_CLR_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_CLR_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Clock Gating Auto Clear Enable */
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Auto Clear Enable */
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - FSDLL Reset Enable */
#define USBPHY_CTRL_CLR_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - ID Value */
#define USBPHY_CTRL_CLR_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP LS Timing */
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend Mode */
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLR_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_CLR_CLKGATE_SHIFT            (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_CTRL_CLR_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_CLR_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_CLR_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_SFTRST_SHIFT)) & USBPHY_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - USBPHY General Control */
/*! @{ */

#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
/*! ENOTG_ID_CHG_IRQ - ID Change Interrupt Enable */
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Host Disconnect Detection Enable */
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT    (2U)
/*! ENIRQHOSTDISCON - Host Disconnect Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Host Disconnect Detection Interrupt */
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT  (4U)
/*! ENDEVPLUGINDETECT - Nonstandard Resistive Plugged-In Detection Enable */
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT (5U)
/*! DEVPLUGIN_POLARITY - Device Plug-In Polarity */
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT     (6U)
/*! OTG_ID_CHG_IRQ - OTG ID Change Interrupt */
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT      (7U)
/*! ENOTGIDDETECT - Enable Internal OTG ID Detector */
#define USBPHY_CTRL_TOG_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT    (8U)
/*! RESUMEIRQSTICKY - RESUME_IRQ Sticky */
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT  (9U)
/*! ENIRQRESUMEDETECT - Resume Detection Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT         (10U)
/*! RESUME_IRQ - Interrupt Resume */
#define USBPHY_CTRL_TOG_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_TOG_RESUME_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT     (11U)
/*! ENIRQDEVPLUGIN - Device Plug-In Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device Plug-In Interrupt */
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - UTMI Level 2 Enable */
#define USBPHY_CTRL_TOG_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - UTMI Level 3 Enable */
#define USBPHY_CTRL_TOG_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT        (16U)
/*! ENIRQWAKEUP - Wake-Up Interrupt Enable */
#define USBPHY_CTRL_TOG_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT         (17U)
/*! WAKEUP_IRQ - Wake-Up Interrupt */
#define USBPHY_CTRL_TOG_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_TOG_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Auto Resume Enable */
#define USBPHY_CTRL_TOG_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_TOG_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Clock Gating Auto Clear Enable */
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - PHY PWD Auto Clear Enable */
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - FSDLL Reset Enable */
#define USBPHY_CTRL_TOG_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT       (27U)
/*! OTG_ID_VALUE - ID Value */
#define USBPHY_CTRL_TOG_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP LS Timing */
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI Suspend Mode */
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_TOG_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_TOG_CLKGATE_SHIFT            (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_CTRL_TOG_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_TOG_SFTRST_SHIFT             (31U)
/*! SFTRST - Software Reset */
#define USBPHY_CTRL_TOG_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_SFTRST_SHIFT)) & USBPHY_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STATUS - USBPHY Status */
/*! @{ */

#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK (0x8U)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT (3U)
/*! HOSTDISCONDETECT_STATUS - Host Disconnect Detection Status
 *  0b0..Do not detect
 *  0b1..Detect
 */
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT)) & USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK)

#define USBPHY_STATUS_DEVPLUGIN_STATUS_MASK      (0x40U)
#define USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT     (6U)
/*! DEVPLUGIN_STATUS - Status Indicator for Nonstandard Resistive Plugged-In Detection
 *  0b0..No attachment detected
 *  0b1..Cable attachment detected
 */
#define USBPHY_STATUS_DEVPLUGIN_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT)) & USBPHY_STATUS_DEVPLUGIN_STATUS_MASK)

#define USBPHY_STATUS_OTGID_STATUS_MASK          (0x100U)
#define USBPHY_STATUS_OTGID_STATUS_SHIFT         (8U)
/*! OTGID_STATUS - OTG ID Status
 *  0b0..Lesser ID resistance
 *  0b1..Greater ID resistance
 */
#define USBPHY_STATUS_OTGID_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_OTGID_STATUS_SHIFT)) & USBPHY_STATUS_OTGID_STATUS_MASK)

#define USBPHY_STATUS_RESUME_STATUS_MASK         (0x400U)
#define USBPHY_STATUS_RESUME_STATUS_SHIFT        (10U)
/*! RESUME_STATUS - Resume Status
 *  0b0..Is in J state
 *  0b1..Is not in J state
 */
#define USBPHY_STATUS_RESUME_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RESUME_STATUS_SHIFT)) & USBPHY_STATUS_RESUME_STATUS_MASK)
/*! @} */

/*! @name DEBUG - USBPHY Debug */
/*! @{ */

#define USBPHY_DEBUG_OTGIDPIOLOCK_MASK           (0x1U)
#define USBPHY_DEBUG_OTGIDPIOLOCK_SHIFT          (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG_OTGIDPIOLOCK(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_HSTPULLDOWN_MASK            (0xCU)
#define USBPHY_DEBUG_HSTPULLDOWN_SHIFT           (2U)
/*! HSTPULLDOWN - Select DP and DN Pulldown Resistors in Host Pulldown Overdrive Mode
 *  0b00..Disconnect the resistors
 *  0b01..Connect 15 kohm pulldown on DN
 *  0b10..Connect 15 kohm pulldown on DP
 *  0b11..Connect 15 kohm pulldown on DP and DN
 */
#define USBPHY_DEBUG_HSTPULLDOWN(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_ENHSTPULLDOWN_MASK          (0x30U)
#define USBPHY_DEBUG_ENHSTPULLDOWN_SHIFT         (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode
 *  0b00..Disable Host Pulldown Overdrive mode
 *  0b01..Override the control of DN 15 kohm pulldown
 *  0b10..Override the control of DP 15 kohm pulldown
 *  0b11..Override the control of DP and DN 15 kohm pulldown
 */
#define USBPHY_DEBUG_ENHSTPULLDOWN(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_TX2RXCOUNT_MASK             (0xF00U)
#define USBPHY_DEBUG_TX2RXCOUNT_SHIFT            (8U)
/*! TX2RXCOUNT - Set Countdown Delay Value from TX to RX Packets for Debug */
#define USBPHY_DEBUG_TX2RXCOUNT(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_ENTX2RXCOUNT_MASK           (0x1000U)
#define USBPHY_DEBUG_ENTX2RXCOUNT_SHIFT          (12U)
/*! ENTX2RXCOUNT - Enable Countdown from TX to RX Packets for Debug
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_DEBUG_ENTX2RXCOUNT(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_SQUELCHRESETCOUNT_MASK      (0x1F0000U)
#define USBPHY_DEBUG_SQUELCHRESETCOUNT_SHIFT     (16U)
/*! SQUELCHRESETCOUNT - Squelch Reset Count */
#define USBPHY_DEBUG_SQUELCHRESETCOUNT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_ENSQUELCHRESET_MASK         (0x1000000U)
#define USBPHY_DEBUG_ENSQUELCHRESET_SHIFT        (24U)
/*! ENSQUELCHRESET - Enable Squelch Reset
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_DEBUG_ENSQUELCHRESET(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_SQUELCHRESETLENGTH_MASK     (0x1E000000U)
#define USBPHY_DEBUG_SQUELCHRESETLENGTH_SHIFT    (25U)
/*! SQUELCHRESETLENGTH - Squelch Reset Length */
#define USBPHY_DEBUG_SQUELCHRESETLENGTH(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_HOST_RESUME_DEBUG_MASK      (0x20000000U)
#define USBPHY_DEBUG_HOST_RESUME_DEBUG_SHIFT     (29U)
/*! HOST_RESUME_DEBUG - Host Resume
 *  0b0..Based on CTRL[HOST_FORCE_LS_SE0]
 *  0b1..Based on CTRL[UTMI_SUSPENDM]
 */
#define USBPHY_DEBUG_HOST_RESUME_DEBUG(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_CLKGATE_MASK                (0x40000000U)
#define USBPHY_DEBUG_CLKGATE_SHIFT               (30U)
/*! CLKGATE - Clock Gating
 *  0b0..Run clocks
 *  0b1..Gate clocks
 */
#define USBPHY_DEBUG_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLKGATE_SHIFT)) & USBPHY_DEBUG_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG_SET - USBPHY Debug */
/*! @{ */

#define USBPHY_DEBUG_SET_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_SET_OTGIDPIOLOCK_SHIFT      (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG_SET_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_SET_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_SET_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_SET_HSTPULLDOWN_SHIFT       (2U)
/*! HSTPULLDOWN - Select DP and DN Pulldown Resistors in Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_SET_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_SET_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_SET_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_SET_ENHSTPULLDOWN_SHIFT     (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_SET_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_SET_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_SET_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_SET_TX2RXCOUNT_SHIFT        (8U)
/*! TX2RXCOUNT - Set Countdown Delay Value from TX to RX Packets for Debug */
#define USBPHY_DEBUG_SET_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_SET_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_SET_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_SET_ENTX2RXCOUNT_SHIFT      (12U)
/*! ENTX2RXCOUNT - Enable Countdown from TX to RX Packets for Debug */
#define USBPHY_DEBUG_SET_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_SET_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch Reset Count */
#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_SET_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_SET_ENSQUELCHRESET_SHIFT    (24U)
/*! ENSQUELCHRESET - Enable Squelch Reset */
#define USBPHY_DEBUG_SET_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_SET_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch Reset Length */
#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host Resume */
#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_SET_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_SET_CLKGATE_SHIFT           (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_DEBUG_SET_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_CLKGATE_SHIFT)) & USBPHY_DEBUG_SET_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG_CLR - USBPHY Debug */
/*! @{ */

#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK_SHIFT      (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_CLR_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_CLR_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_CLR_HSTPULLDOWN_SHIFT       (2U)
/*! HSTPULLDOWN - Select DP and DN Pulldown Resistors in Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_CLR_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_CLR_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN_SHIFT     (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_CLR_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_CLR_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_CLR_TX2RXCOUNT_SHIFT        (8U)
/*! TX2RXCOUNT - Set Countdown Delay Value from TX to RX Packets for Debug */
#define USBPHY_DEBUG_CLR_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT_SHIFT      (12U)
/*! ENTX2RXCOUNT - Enable Countdown from TX to RX Packets for Debug */
#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch Reset Count */
#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_CLR_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_CLR_ENSQUELCHRESET_SHIFT    (24U)
/*! ENSQUELCHRESET - Enable Squelch Reset */
#define USBPHY_DEBUG_CLR_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_CLR_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch Reset Length */
#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host Resume */
#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_CLR_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_CLR_CLKGATE_SHIFT           (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_DEBUG_CLR_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_CLKGATE_SHIFT)) & USBPHY_DEBUG_CLR_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG_TOG - USBPHY Debug */
/*! @{ */

#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK_SHIFT      (0U)
/*! OTGIDPIOLOCK - Hold OTG_ID */
#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_TOG_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_TOG_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_TOG_HSTPULLDOWN_SHIFT       (2U)
/*! HSTPULLDOWN - Select DP and DN Pulldown Resistors in Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_TOG_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_TOG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN_SHIFT     (4U)
/*! ENHSTPULLDOWN - Enable Host Pulldown Overdrive Mode */
#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_TOG_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_TOG_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_TOG_TX2RXCOUNT_SHIFT        (8U)
/*! TX2RXCOUNT - Set Countdown Delay Value from TX to RX Packets for Debug */
#define USBPHY_DEBUG_TOG_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT_SHIFT      (12U)
/*! ENTX2RXCOUNT - Enable Countdown from TX to RX Packets for Debug */
#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch Reset Count */
#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_TOG_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_TOG_ENSQUELCHRESET_SHIFT    (24U)
/*! ENSQUELCHRESET - Enable Squelch Reset */
#define USBPHY_DEBUG_TOG_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_TOG_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch Reset Length */
#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host Resume */
#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_TOG_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_TOG_CLKGATE_SHIFT           (30U)
/*! CLKGATE - Clock Gating */
#define USBPHY_DEBUG_TOG_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_CLKGATE_SHIFT)) & USBPHY_DEBUG_TOG_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG0_STATUS - UTMI Debug Status 0 */
/*! @{ */

#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_MASK (0xFFFFU)
#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_SHIFT (0U)
/*! LOOP_BACK_FAIL_COUNT - Loopback Fail Count */
#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_MASK)

#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_MASK (0x3FF0000U)
#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_SHIFT (16U)
/*! UTMI_RXERROR_FAIL_COUNT - UTMI Receive Error Fail Count */
#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_MASK)

#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_MASK  (0xFC000000U)
#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_SHIFT (26U)
/*! SQUELCH_COUNT - Squelch Count */
#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_MASK)
/*! @} */

/*! @name DEBUG1 - UTMI Debug Status 1 */
/*! @{ */

#define USBPHY_DEBUG1_ENTAILADJVD_MASK           (0x6000U)
#define USBPHY_DEBUG1_ENTAILADJVD_SHIFT          (13U)
/*! ENTAILADJVD - HS RX Squelch Rise Time Delay Trim
 *  0b00..Squelch rising edge delay is nominal
 *  0b01..+20% delay compared to nominal
 *  0b10..-20% delay compared to nominal
 *  0b11..-40% delay compared to nominal
 */
#define USBPHY_DEBUG1_ENTAILADJVD(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_SELFBIASOFF_MASK (0x8000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_SELFBIASOFF_SHIFT (15U)
/*! USB2_REFBIAS_SELFBIASOFF - Self-Bias Off for Reference Bias Amplifiers and Comparators
 *  0b0..Self-bias
 *  0b1..Current reference bias
 */
#define USBPHY_DEBUG1_USB2_REFBIAS_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_SELFBIASOFF_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_SELFBIASOFF_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_PWDVBGUP_MASK (0x10000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_PWDVBGUP_SHIFT (16U)
/*! USB2_REFBIAS_PWDVBGUP - Bandgap Voltage Status Comparator Powerdown
 *  0b0..Enable
 *  0b1..Disable
 */
#define USBPHY_DEBUG1_USB2_REFBIAS_PWDVBGUP(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_PWDVBGUP_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_PWDVBGUP_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_LOWPWR_MASK   (0x20000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_LOWPWR_SHIFT  (17U)
/*! USB2_REFBIAS_LOWPWR - Reference Bias Low Power Configuration
 *  0b0..Nominal bias current
 *  0b1..50% of nominal bias current
 */
#define USBPHY_DEBUG1_USB2_REFBIAS_LOWPWR(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_LOWPWR_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_LOWPWR_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_MASK   (0x1C0000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_SHIFT  (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment
 *  0b000..Nominal bandgap voltage; flattest temperature coefficient
 *  0b001..≈ +10 mV compared to nominal
 *  0b010..≈ +20 mV compared to nominal
 *  0b011..≈ +30 mV compared to nominal; most-positive temperature coefficient
 *  0b100..≈ -10 mV compared to nominal
 *  0b101..≈ -20 mV compared to nominal
 *  0b110..≈ -30 mV compared to nominal
 *  0b111..≈ -40 mV compared to nominal; most-negative temperature coefficient
 */
#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_TST_MASK      (0x600000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_TST_SHIFT     (21U)
/*! USB2_REFBIAS_TST - Bias Current Control Adjustment
 *  0b00..≈ 10 uA reference current; nominal
 *  0b01..≈ 0.9x compared to nominal
 *  0b10..≈ 0.8x compared to nominal
 *  0b11..≈ 1.1x compared to nominal
 */
#define USBPHY_DEBUG1_USB2_REFBIAS_TST(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_SET - UTMI Debug Status 1 */
/*! @{ */

#define USBPHY_DEBUG1_SET_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - HS RX Squelch Rise Time Delay Trim */
#define USBPHY_DEBUG1_SET_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_SET_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_SELFBIASOFF_MASK (0x8000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_SELFBIASOFF_SHIFT (15U)
/*! USB2_REFBIAS_SELFBIASOFF - Self-Bias Off for Reference Bias Amplifiers and Comparators */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_SELFBIASOFF_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_SELFBIASOFF_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_PWDVBGUP_MASK (0x10000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_PWDVBGUP_SHIFT (16U)
/*! USB2_REFBIAS_PWDVBGUP - Bandgap Voltage Status Comparator Powerdown */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_PWDVBGUP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_PWDVBGUP_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_PWDVBGUP_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_LOWPWR_MASK (0x20000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_LOWPWR_SHIFT (17U)
/*! USB2_REFBIAS_LOWPWR - Reference Bias Low Power Configuration */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_LOWPWR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_LOWPWR_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_LOWPWR_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias Current Control Adjustment */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_CLR - UTMI Debug Status 1 */
/*! @{ */

#define USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - HS RX Squelch Rise Time Delay Trim */
#define USBPHY_DEBUG1_CLR_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_SELFBIASOFF_MASK (0x8000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_SELFBIASOFF_SHIFT (15U)
/*! USB2_REFBIAS_SELFBIASOFF - Self-Bias Off for Reference Bias Amplifiers and Comparators */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_SELFBIASOFF_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_SELFBIASOFF_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_PWDVBGUP_MASK (0x10000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_PWDVBGUP_SHIFT (16U)
/*! USB2_REFBIAS_PWDVBGUP - Bandgap Voltage Status Comparator Powerdown */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_PWDVBGUP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_PWDVBGUP_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_PWDVBGUP_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_LOWPWR_MASK (0x20000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_LOWPWR_SHIFT (17U)
/*! USB2_REFBIAS_LOWPWR - Reference Bias Low Power Configuration */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_LOWPWR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_LOWPWR_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_LOWPWR_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias Current Control Adjustment */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_TOG - UTMI Debug Status 1 */
/*! @{ */

#define USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - HS RX Squelch Rise Time Delay Trim */
#define USBPHY_DEBUG1_TOG_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_SELFBIASOFF_MASK (0x8000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_SELFBIASOFF_SHIFT (15U)
/*! USB2_REFBIAS_SELFBIASOFF - Self-Bias Off for Reference Bias Amplifiers and Comparators */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_SELFBIASOFF(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_SELFBIASOFF_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_SELFBIASOFF_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_PWDVBGUP_MASK (0x10000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_PWDVBGUP_SHIFT (16U)
/*! USB2_REFBIAS_PWDVBGUP - Bandgap Voltage Status Comparator Powerdown */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_PWDVBGUP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_PWDVBGUP_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_PWDVBGUP_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_LOWPWR_MASK (0x20000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_LOWPWR_SHIFT (17U)
/*! USB2_REFBIAS_LOWPWR - Reference Bias Low Power Configuration */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_LOWPWR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_LOWPWR_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_LOWPWR_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias Current Control Adjustment */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name VERSION - USBPHY Version */
/*! @{ */

#define USBPHY_VERSION_STEP_MASK                 (0xFFFFU)
#define USBPHY_VERSION_STEP_SHIFT                (0U)
/*! STEP - Step */
#define USBPHY_VERSION_STEP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_STEP_SHIFT)) & USBPHY_VERSION_STEP_MASK)

#define USBPHY_VERSION_MINOR_MASK                (0xFF0000U)
#define USBPHY_VERSION_MINOR_SHIFT               (16U)
/*! MINOR - Minor */
#define USBPHY_VERSION_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MINOR_SHIFT)) & USBPHY_VERSION_MINOR_MASK)

#define USBPHY_VERSION_MAJOR_MASK                (0xFF000000U)
#define USBPHY_VERSION_MAJOR_SHIFT               (24U)
/*! MAJOR - Major */
#define USBPHY_VERSION_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MAJOR_SHIFT)) & USBPHY_VERSION_MAJOR_MASK)
/*! @} */

/*! @name PLL_SIC - USBPHY PLL Control and Status */
/*! @{ */

#define USBPHY_PLL_SIC_PLL_POSTDIV_MASK          (0x1CU)
#define USBPHY_PLL_SIC_PLL_POSTDIV_SHIFT         (2U)
/*! PLL_POSTDIV - PLL Post-Divider Output Value Configuration
 *  0b000..Disable the output of PLL post divider
 *  0b001..Divide value is 1
 *  0b010..Divide value is 2
 *  0b011..Divide value is 3
 *  0b100..Divide value is 4
 *  0b101..Divide value is 5
 *  0b110..Divide value is 6
 *  0b111..Reserved; do not use
 */
#define USBPHY_PLL_SIC_PLL_POSTDIV(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_POSTDIV_SHIFT)) & USBPHY_PLL_SIC_PLL_POSTDIV_MASK)

#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK      (0x40U)
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT     (6U)
/*! PLL_EN_USB_CLKS - PLL USB Clocks Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_PLL_POWER_MASK            (0x1000U)
#define USBPHY_PLL_SIC_PLL_POWER_SHIFT           (12U)
/*! PLL_POWER - PLL Power
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_POWER(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_PLL_ENABLE_MASK           (0x2000U)
#define USBPHY_PLL_SIC_PLL_ENABLE_SHIFT          (13U)
/*! PLL_ENABLE - PLL Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_BYPASS_MASK           (0x10000U)
#define USBPHY_PLL_SIC_PLL_BYPASS_SHIFT          (16U)
/*! PLL_BYPASS - PLL Bypass
 *  0b0..Do not bypass
 *  0b1..Bypass
 */
#define USBPHY_PLL_SIC_PLL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK      (0x80000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT     (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Powerdown Selection
 *  0b0..PLL_POWER
 *  0b1..REFBIAS_PWD
 */
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_MASK          (0x100000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT         (20U)
/*! REFBIAS_PWD - Reference Bias Powerdown
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_REFBIAS_PWD(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK       (0x200000U)
#define USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT      (21U)
/*! PLL_REG_ENABLE - PLL Regulator Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_PLL_SIC_PLL_REG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_DIV_SEL_MASK          (0x1C00000U)
#define USBPHY_PLL_SIC_PLL_DIV_SEL_SHIFT         (22U)
/*! PLL_DIV_SEL - PLL Divider Selection
 *  0b000..Divide by 13
 *  0b001..Divide by 15
 *  0b010..Divide by 16
 *  0b011..Divide by 20
 *  0b100..Divide by 22
 *  0b101..Divide by 25
 *  0b110..Divide by 30
 *  0b111..Divide by 240
 */
#define USBPHY_PLL_SIC_PLL_DIV_SEL(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_PLL_LOCK_MASK             (0x80000000U)
#define USBPHY_PLL_SIC_PLL_LOCK_SHIFT            (31U)
/*! PLL_LOCK - PLL Lock
 *  0b0..Not locked
 *  0b1..Locked
 */
#define USBPHY_PLL_SIC_PLL_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_SET - USBPHY PLL Control and Status */
/*! @{ */

#define USBPHY_PLL_SIC_SET_PLL_POSTDIV_MASK      (0x1CU)
#define USBPHY_PLL_SIC_SET_PLL_POSTDIV_SHIFT     (2U)
/*! PLL_POSTDIV - PLL Post-Divider Output Value Configuration */
#define USBPHY_PLL_SIC_SET_PLL_POSTDIV(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_POSTDIV_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_POSTDIV_MASK)

#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL USB Clocks Enable */
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_SET_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - PLL Power */
#define USBPHY_PLL_SIC_SET_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Enable */
#define USBPHY_PLL_SIC_SET_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - PLL Bypass */
#define USBPHY_PLL_SIC_SET_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Powerdown Selection */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Reference Bias Powerdown */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL Regulator Enable */
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Selection */
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_SET_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL Lock */
#define USBPHY_PLL_SIC_SET_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_CLR - USBPHY PLL Control and Status */
/*! @{ */

#define USBPHY_PLL_SIC_CLR_PLL_POSTDIV_MASK      (0x1CU)
#define USBPHY_PLL_SIC_CLR_PLL_POSTDIV_SHIFT     (2U)
/*! PLL_POSTDIV - PLL Post-Divider Output Value Configuration */
#define USBPHY_PLL_SIC_CLR_PLL_POSTDIV(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_POSTDIV_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_POSTDIV_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL USB Clocks Enable */
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - PLL Power */
#define USBPHY_PLL_SIC_CLR_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Enable */
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - PLL Bypass */
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Powerdown Selection */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Reference Bias Powerdown */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL Regulator Enable */
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Selection */
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL Lock */
#define USBPHY_PLL_SIC_CLR_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_TOG - USBPHY PLL Control and Status */
/*! @{ */

#define USBPHY_PLL_SIC_TOG_PLL_POSTDIV_MASK      (0x1CU)
#define USBPHY_PLL_SIC_TOG_PLL_POSTDIV_SHIFT     (2U)
/*! PLL_POSTDIV - PLL Post-Divider Output Value Configuration */
#define USBPHY_PLL_SIC_TOG_PLL_POSTDIV(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_POSTDIV_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_POSTDIV_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL USB Clocks Enable */
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - PLL Power */
#define USBPHY_PLL_SIC_TOG_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL Enable */
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - PLL Bypass */
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - Reference Bias Powerdown Selection */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - Reference Bias Powerdown */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL Regulator Enable */
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL Divider Selection */
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL Lock */
#define USBPHY_PLL_SIC_TOG_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT - USBPHY VBUS Detect Control */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUSVALID Threshold
 *  0b000..4.0 V
 *  0b001..4.1 V
 *  0b010..4.2 V
 *  0b011..4.3 V
 *  0b100..4.4 V
 *  0b101..4.5 V
 *  0b110..4.6 V
 *  0b111..4.7 V
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Override Enable
 *  0b0..Results of VBUS_VALID and session valid comparators for VBUS_VALID, AVALID, BVALID, and SESSEND
 *  0b1..Override values for VBUS_VALID, AVALID, BVALID, and SESSEND
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND
 *  0b0..Overridden to 0
 *  0b1..Overridden to 1
 */
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid
 *  0b0..Overridden to 0
 *  0b1..Overridden to 1
 */
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid
 *  0b0..Overridden to 0
 *  0b1..Overridden to 1
 */
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal
 *  0b0..Overridden to 0
 *  0b1..Overridden to 1
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Source Selection
 *  0b0..VBUS_VALID comparator results
 *  0b1..VBUS_VALID_3V detector results
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection
 *  0b00..VBUS_VALID comparator results
 *  0b01..Session valid comparator results
 *  0b10..Session valid comparator result
 *  0b11..Reserved; do not use
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override
 *  0b0..Do not allow override
 *  0b1..Allow override
 */
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override Value */
#define USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - VBUS_VALID Comparator Selection
 *  0b0..VBUS_VALID comparator for the VBUS_VALID results
 *  0b1..Session end comparator for the VBUS_VALID results
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_MASK  (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - VBUS_VALID Comparator Enable
 *  0b000..Disable the VBUS_VALID comparator
 *  0b001..Enable the SESS_VALID comparator
 *  0b010..Enable 3V detection
 */
#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor Controller
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Charger Resistor Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_SET - USBPHY VBUS Detect Control */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUSVALID Threshold */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Override Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override Value */
#define USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor Controller */
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Charger Resistor Enable */
#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_CLR - USBPHY VBUS Detect Control */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUSVALID Threshold */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Override Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override Value */
#define USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor Controller */
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Charger Resistor Enable */
#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_TOG - USBPHY VBUS Detect Control */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUSVALID Threshold */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS Detect Signal Override Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override Value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override Value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override Value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override Value for the VBUS_VALID Signal */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - VBUS_VALID Source Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_MASK (0x800U)
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_SHIFT (11U)
/*! ID_OVERRIDE_EN - Enable Local ID Pin Status Override */
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_MASK (0x1000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_SHIFT (12U)
/*! ID_OVERRIDE - ID Pin Status Local Override Value */
#define USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_ID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - VBUS_VALID Comparator Selection */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_MASK (0x700000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - VBUS_VALID Comparator Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - VBUS Discharge Resistor Controller */
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Charger Resistor Enable */
#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT - USBPHY VBUS Detector Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK   (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT  (0U)
/*! SESSEND - Session End Indicator
 *  0b0..Above threshold
 *  0b1..Below threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK    (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT   (1U)
/*! BVALID - B-Device Session Valid Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_BVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK    (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT   (2U)
/*! AVALID - A-Device Session Valid Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_AVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS Voltage Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V Detector Status
 *  0b0..Below threshold
 *  0b1..Above threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT - USBPHY Charger Detect Control */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK   (0x4U)
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT  (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_BGR_BIAS_MASK    (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_BGR_BIAS_SHIFT   (23U)
/*! BGR_BIAS - BGR Bias
 *  0b0..Local bias
 *  0b1..Bandgap bias
 */
#define USBPHY_USB1_CHRG_DETECT_BGR_BIAS(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_BGR_BIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_BGR_BIAS_MASK)

#define USBPHY_USB1_CHRG_DETECT_DCDSEL_MASK      (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_DCDSEL_SHIFT     (31U)
/*! DCDSEL - DCD Selection
 *  0b0..Fields in the USB1_CHRG_DETECT register
 *  0b1..Fields and state machines in the USBHSDCD module
 */
#define USBPHY_USB1_CHRG_DETECT_DCDSEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_SET - USBPHY Charger Detect Control */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_BGR_BIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_SET_BGR_BIAS_SHIFT (23U)
/*! BGR_BIAS - BGR Bias */
#define USBPHY_USB1_CHRG_DETECT_SET_BGR_BIAS(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_BGR_BIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_BGR_BIAS_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_SET_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_CLR - USBPHY Charger Detect Control */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_BIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_BIAS_SHIFT (23U)
/*! BGR_BIAS - BGR Bias */
#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_BIAS(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_BGR_BIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_BGR_BIAS_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_TOG - USBPHY Charger Detect Control */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - DP Pullup Resistor Enable Override Control */
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_BIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_BIAS_SHIFT (23U)
/*! BGR_BIAS - BGR Bias */
#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_BIAS(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_BGR_BIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_BGR_BIAS_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_MASK  (0x80000000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_SHIFT (31U)
/*! DCDSEL - DCD Selection */
#define USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_DCDSEL_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT - USBPHY Charger Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection Phase Output
 *  0b0..Not detected
 *  0b1..Detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection Phase Output
 *  0b0..SDP detected
 *  0b1..Charging port detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DN_STATE_MASK  (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_DN_STATE_SHIFT (2U)
/*! DN_STATE - DN State
 *  0b0..< 0.8 V
 *  0b1..> 2.0 V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DN_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DN_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DN_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK  (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP State
 *  0b0..< 0.8 V
 *  0b1..> 2.0 V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection Phase Output
 *  0b0..CDP detected
 *  0b1..DCP detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK)
/*! @} */

/*! @name ANACTRL - USBPHY Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_DEV_PULLDOWN_MASK         (0x400U)
#define USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT        (10U)
/*! DEV_PULLDOWN - Device Pulldown
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_ANACTRL_DEV_PULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_SET - USBPHY Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown */
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_CLR - USBPHY Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown */
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_TOG - USBPHY Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pulldown */
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name USB1_LOOPBACK - USBPHY Loopback Control and Status */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - UTMI Test Start
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_MASK  (0x2U)
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - UTMI Digital Test 0
 *  0b0..Pseudorandom mode
 *  0b1..Pulse mode
 */
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_MASK  (0x4U)
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - UTMI Digital Test 1
 *  0b0..Pulse mode
 *  0b1..Pseudorandom mode
 */
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Loopback Test HS Mode
 *  0b0..FS
 *  0b1..HS
 */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Loopback Test LS Mode
 *  0b0..HS or FS (defined by TSTI1_TX_HS)
 *  0b1..LS
 */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN_MASK     (0x20U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN_SHIFT    (5U)
/*! TSTI_TX_EN - Loopback Test Transmit Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_MASK    (0x40U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_SHIFT   (6U)
/*! TSTI_TX_HIZ - Loopback Test Transmit Hi-Z
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_MASK  (0x80U)
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - UTMO Digital Test 0
 *  0b0..Passing
 *  0b1..Not passing
 */
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_MASK  (0x100U)
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - UTMO Digital Test 1
 *  0b0..Not passing
 *  0b1..Passing
 */
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - Loopback Test HS-FS Mode Enable
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TSTPKT_MASK         (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_TSTPKT_SHIFT        (16U)
/*! TSTPKT - Testing Packet */
#define USBPHY_USB1_LOOPBACK_TSTPKT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_SET - USBPHY Loopback Control and Status */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - UTMI Test Start */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - UTMI Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - UTMI Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Loopback Test HS Mode */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Loopback Test LS Mode */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Loopback Test Transmit Enable */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Loopback Test Transmit Hi-Z */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - UTMO Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - UTMO Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - Loopback Test HS-FS Mode Enable */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_SET_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Testing Packet */
#define USBPHY_USB1_LOOPBACK_SET_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_CLR - USBPHY Loopback Control and Status */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - UTMI Test Start */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - UTMI Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - UTMI Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Loopback Test HS Mode */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Loopback Test LS Mode */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Loopback Test Transmit Enable */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Loopback Test Transmit Hi-Z */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - UTMO Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - UTMO Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - Loopback Test HS-FS Mode Enable */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Testing Packet */
#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_TOG - USBPHY Loopback Control and Status */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - UTMI Test Start */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - UTMI Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - UTMI Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Loopback Test HS Mode */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Loopback Test LS Mode */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Loopback Test Transmit Enable */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Loopback Test Transmit Hi-Z */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - UTMO Digital Test 0 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - UTMO Digital Test 1 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - Loopback Test HS-FS Mode Enable */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Testing Packet */
#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT - USBPHY Loopback Packet Number Selection */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - Loopback Test HS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - Loopback Test FS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_SET - USBPHY Loopback Packet Number Selection */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - Loopback Test HS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - Loopback Test FS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_CLR - USBPHY Loopback Packet Number Selection */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - Loopback Test HS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - Loopback Test FS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_TOG - USBPHY Loopback Packet Number Selection */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - Loopback Test HS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - Loopback Test FS Packet Number */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN - USBPHY Trim Override Enable */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! TRIM_DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! TRIM_ENV_TAIL_ADJ_VD_OVERRIDE - Override Enable for HS RX Squelch Rise Time Delay Trim
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TRIM_TX_D_CAL_OVERRIDE - Override Enable for the HS TX Output Current Trim
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TRIM_TX_CAL45DP_OVERRIDE - Override Enable for DP Series Termination Trim
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DN_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DN_OVERRIDE_SHIFT (4U)
/*! TRIM_TX_CAL45DN_OVERRIDE - Override Enable for DN Series Termination Trim
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DN_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DN_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_TX_CAL45DN_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! TRIM_REFBIAS_VBGADJ_OVERRIDE - Override Enable for Bandgap Voltage Adjustment
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! TRIM_REFBIAS_TST_OVERRIDE - Override Enable for Bias Current Control
 *  0b0..Disable
 *  0b1..Enable
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! TRIM_USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_TST_SHIFT (13U)
/*! TRIM_USB2_REFBIAS_TST - Bias Current Control Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! TRIM_PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! TRIM_USB_REG_ENV_TAIL_ADJ_VD - HS RX Squelch Rise Time Delay Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL_SHIFT (20U)
/*! TRIM_USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY
 *  0b0000..Maximum current; approximately 19% above nominal
 *  0b0111..Nominal
 *  0b1111..Minimum current; approximately 19% below nominal
 */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! TRIM_USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! TRIM_USBPHY_TX_CAL45DN - DN Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TRIM_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_SET - USBPHY Trim Override Enable */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! TRIM_DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! TRIM_ENV_TAIL_ADJ_VD_OVERRIDE - Override Enable for HS RX Squelch Rise Time Delay Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TRIM_TX_D_CAL_OVERRIDE - Override Enable for the HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TRIM_TX_CAL45DP_OVERRIDE - Override Enable for DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DN_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DN_OVERRIDE_SHIFT (4U)
/*! TRIM_TX_CAL45DN_OVERRIDE - Override Enable for DN Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DN_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DN_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_TX_CAL45DN_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! TRIM_REFBIAS_VBGADJ_OVERRIDE - Override Enable for Bandgap Voltage Adjustment */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! TRIM_REFBIAS_TST_OVERRIDE - Override Enable for Bias Current Control */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! TRIM_USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_TST_SHIFT (13U)
/*! TRIM_USB2_REFBIAS_TST - Bias Current Control Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! TRIM_PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! TRIM_USB_REG_ENV_TAIL_ADJ_VD - HS RX Squelch Rise Time Delay Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL_SHIFT (20U)
/*! TRIM_USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! TRIM_USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! TRIM_USBPHY_TX_CAL45DN - DN Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TRIM_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_CLR - USBPHY Trim Override Enable */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! TRIM_DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! TRIM_ENV_TAIL_ADJ_VD_OVERRIDE - Override Enable for HS RX Squelch Rise Time Delay Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TRIM_TX_D_CAL_OVERRIDE - Override Enable for the HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TRIM_TX_CAL45DP_OVERRIDE - Override Enable for DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DN_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DN_OVERRIDE_SHIFT (4U)
/*! TRIM_TX_CAL45DN_OVERRIDE - Override Enable for DN Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DN_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DN_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_TX_CAL45DN_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! TRIM_REFBIAS_VBGADJ_OVERRIDE - Override Enable for Bandgap Voltage Adjustment */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! TRIM_REFBIAS_TST_OVERRIDE - Override Enable for Bias Current Control */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! TRIM_USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_TST_SHIFT (13U)
/*! TRIM_USB2_REFBIAS_TST - Bias Current Control Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! TRIM_PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! TRIM_USB_REG_ENV_TAIL_ADJ_VD - HS RX Squelch Rise Time Delay Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL_SHIFT (20U)
/*! TRIM_USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! TRIM_USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! TRIM_USBPHY_TX_CAL45DN - DN Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TRIM_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_TOG - USBPHY Trim Override Enable */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! TRIM_DIV_SEL_OVERRIDE - Override Enable for PLL Divider Value */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! TRIM_ENV_TAIL_ADJ_VD_OVERRIDE - Override Enable for HS RX Squelch Rise Time Delay Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TRIM_TX_D_CAL_OVERRIDE - Override Enable for the HS TX Output Current Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TRIM_TX_CAL45DP_OVERRIDE - Override Enable for DP Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DN_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DN_OVERRIDE_SHIFT (4U)
/*! TRIM_TX_CAL45DN_OVERRIDE - Override Enable for DN Series Termination Trim */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DN_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DN_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_TX_CAL45DN_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! TRIM_REFBIAS_VBGADJ_OVERRIDE - Override Enable for Bandgap Voltage Adjustment */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! TRIM_REFBIAS_TST_OVERRIDE - Override Enable for Bias Current Control */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! TRIM_USB2_REFBIAS_VBGADJ - Bandgap Voltage Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_TST_SHIFT (13U)
/*! TRIM_USB2_REFBIAS_TST - Bias Current Control Adjustment Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! TRIM_PLL_CTRL0_DIV_SEL - PLL Divider Value Configuration Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! TRIM_USB_REG_ENV_TAIL_ADJ_VD - HS RX Squelch Rise Time Delay Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL_SHIFT (20U)
/*! TRIM_USBPHY_TX_D_CAL - HS TX Output Current Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! TRIM_USBPHY_TX_CAL45DP - DP Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! TRIM_USBPHY_TX_CAL45DN - DN Series Termination Resistance Trim Bits from Outside USBPHY */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TRIM_USBPHY_TX_CAL45DN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group USBPHY_Register_Masks */


/*!
 * @}
 */ /* end of group USBPHY_Peripheral_Access_Layer */


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


#endif  /* PERI_USBPHY_H_ */

