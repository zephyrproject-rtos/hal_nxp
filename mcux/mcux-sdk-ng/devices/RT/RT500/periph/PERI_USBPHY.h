/*
** ###################################################################
**     Processors:          MIMXRT533SFAWC
**                          MIMXRT533SFFOC
**                          MIMXRT555SFAWC
**                          MIMXRT555SFFOC
**                          MIMXRT595SFAWC_cm33
**                          MIMXRT595SFAWC_dsp
**                          MIMXRT595SFFOC_cm33
**                          MIMXRT595SFFOC_dsp
**
**     Version:             rev. 6.0, 2024-10-29
**     Build:               b250520
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
**     - rev. 1.0 (2019-04-19)
**         Initial version.
**     - rev. 2.0 (2019-07-22)
**         Base on rev 0.7 RM.
**     - rev. 3.0 (2020-03-16)
**         Base on Rev.A RM.
**     - rev. 4.0 (2020-05-18)
**         Base on Rev.B RM.
**     - rev. 5.0 (2020-08-27)
**         Base on Rev.C RM.
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

#if (defined(CPU_MIMXRT533SFAWC) || defined(CPU_MIMXRT533SFFOC))
#include "MIMXRT533S_COMMON.h"
#elif (defined(CPU_MIMXRT555SFAWC) || defined(CPU_MIMXRT555SFFOC))
#include "MIMXRT555S_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_cm33) || defined(CPU_MIMXRT595SFFOC_cm33))
#include "MIMXRT595S_cm33_COMMON.h"
#elif (defined(CPU_MIMXRT595SFAWC_dsp) || defined(CPU_MIMXRT595SFFOC_dsp))
#include "MIMXRT595S_dsp_COMMON.h"
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
  __IO uint32_t PWD;                               /**< Power Down, offset: 0x0 */
  __IO uint32_t PWD_SET;                           /**< Power Down Register Set, offset: 0x4 */
  __IO uint32_t PWD_CLR;                           /**< Power Down Register Clear, offset: 0x8 */
  __IO uint32_t PWD_TOG;                           /**< Power Down Register Toggle, offset: 0xC */
  __IO uint32_t TX;                                /**< TX Control, offset: 0x10 */
  __IO uint32_t TX_SET;                            /**< TX Control Set, offset: 0x14 */
  __IO uint32_t TX_CLR;                            /**< TX Control Clear, offset: 0x18 */
  __IO uint32_t TX_TOG;                            /**< TX Control Toggle, offset: 0x1C */
  __IO uint32_t RX;                                /**< RX Control, offset: 0x20 */
  __IO uint32_t RX_SET;                            /**< RX Control Set, offset: 0x24 */
  __IO uint32_t RX_CLR;                            /**< RX Control Clear, offset: 0x28 */
  __IO uint32_t RX_TOG;                            /**< RX Control Toggle, offset: 0x2C */
  __IO uint32_t CTRL;                              /**< General Purpose Control, offset: 0x30 */
  __IO uint32_t CTRL_SET;                          /**< General Purpose Control Set, offset: 0x34 */
  __IO uint32_t CTRL_CLR;                          /**< General Purpose Control Clear, offset: 0x38 */
  __IO uint32_t CTRL_TOG;                          /**< General Purpose Control Toggle, offset: 0x3C */
  __I  uint32_t STATUS;                            /**< Status, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DEBUG0;                            /**< Debug 0, offset: 0x50 */
  __IO uint32_t DEBUG0_SET;                        /**< Debug 0 Set, offset: 0x54 */
  __IO uint32_t DEBUG0_CLR;                        /**< Debug Clear, offset: 0x58 */
  __IO uint32_t DEBUG0_TOG;                        /**< Debug Toggle, offset: 0x5C */
       uint8_t RESERVED_1[16];
  __IO uint32_t DEBUG1;                            /**< UTMI Debug 1, offset: 0x70 */
  __IO uint32_t DEBUG1_SET;                        /**< UTMI Debug 1 Set, offset: 0x74 */
  __IO uint32_t DEBUG1_CLR;                        /**< UTMI Debug 1 Clear, offset: 0x78 */
  __IO uint32_t DEBUG1_TOG;                        /**< UTMI Debug 1 Toggle, offset: 0x7C */
  __I  uint32_t VERSION;                           /**< Version, offset: 0x80 */
       uint8_t RESERVED_2[28];
  __IO uint32_t PLL_SIC;                           /**< PLL Control/Status, offset: 0xA0 */
  __IO uint32_t PLL_SIC_SET;                       /**< PLL Control/Status Set, offset: 0xA4 */
  __IO uint32_t PLL_SIC_CLR;                       /**< PLL Control/Status Clear, offset: 0xA8 */
  __IO uint32_t PLL_SIC_TOG;                       /**< PLL Control/Status Toggle, offset: 0xAC */
       uint8_t RESERVED_3[16];
  __IO uint32_t USB1_VBUS_DETECT;                  /**< VBUS detect, offset: 0xC0 */
  __IO uint32_t USB1_VBUS_DETECT_SET;              /**< VBUS detect Set, offset: 0xC4 */
  __IO uint32_t USB1_VBUS_DETECT_CLR;              /**< VBUS detect Clear, offset: 0xC8 */
  __IO uint32_t USB1_VBUS_DETECT_TOG;              /**< VBUS detect Toggle, offset: 0xCC */
  __I  uint32_t USB1_VBUS_DET_STAT;                /**< VBUS Detect Status, offset: 0xD0 */
       uint8_t RESERVED_4[12];
  __IO uint32_t USB1_CHRG_DETECT;                  /**< Charger Detect Control, offset: 0xE0 */
  __IO uint32_t USB1_CHRG_DETECT_SET;              /**< Charger Detect Control Set, offset: 0xE4 */
  __IO uint32_t USB1_CHRG_DETECT_CLR;              /**< Charger Detect Control Clear, offset: 0xE8 */
  __IO uint32_t USB1_CHRG_DETECT_TOG;              /**< Charger Detect Control Toggle, offset: 0xEC */
  __I  uint32_t USB1_CHRG_DET_STAT;                /**< Charge Detect Status, offset: 0xF0 */
       uint8_t RESERVED_5[12];
  __IO uint32_t ANACTRL;                           /**< Analog Control, offset: 0x100 */
  __IO uint32_t ANACTRL_SET;                       /**< Analog Control Set, offset: 0x104 */
  __IO uint32_t ANACTRL_CLR;                       /**< Analog Control Clear, offset: 0x108 */
  __IO uint32_t ANACTRL_TOG;                       /**< Analog Control Toggle, offset: 0x10C */
  __IO uint32_t USB1_LOOPBACK;                     /**< USB PHY Loopback Control/Status, offset: 0x110 */
  __IO uint32_t USB1_LOOPBACK_SET;                 /**< USB PHY Loopback Control/Status Set, offset: 0x114 */
  __IO uint32_t USB1_LOOPBACK_CLR;                 /**< USB PHY Loopback Control/Status Clear, offset: 0x118 */
  __IO uint32_t USB1_LOOPBACK_TOG;                 /**< USB PHY Loopback Control/Status Toggle, offset: 0x11C */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT;             /**< Loopback Packet Number Select, offset: 0x120 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_SET;         /**< USB PHY Loopback Packet Number Select Set, offset: 0x124 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_CLR;         /**< USB PHY Loopback Packet Number Select Clear, offset: 0x128 */
  __IO uint32_t USB1_LOOPBACK_HSFSCNT_TOG;         /**< USB PHY Loopback Packet Number Select Toggle, offset: 0x12C */
  __IO uint32_t TRIM_OVERRIDE_EN;                  /**< Trim Override Enable, offset: 0x130 */
  __IO uint32_t TRIM_OVERRIDE_EN_SET;              /**< Trim Set, offset: 0x134 */
  __IO uint32_t TRIM_OVERRIDE_EN_CLR;              /**< Trim Clear, offset: 0x138 */
  __IO uint32_t TRIM_OVERRIDE_EN_TOG;              /**< Trim Toggle, offset: 0x13C */
} USBPHY_Type;

/* ----------------------------------------------------------------------------
   -- USBPHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Register_Masks USBPHY Register Masks
 * @{
 */

/*! @name PWD - Power Down */
/*! @{ */

#define USBPHY_PWD_TXPWDFS_MASK                  (0x400U)
#define USBPHY_PWD_TXPWDFS_SHIFT                 (10U)
/*! TXPWDFS - Power down USB FS drivers.
 *  0b0..Normal operation
 *  0b1..Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output
 */
#define USBPHY_PWD_TXPWDFS(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDFS_SHIFT)) & USBPHY_PWD_TXPWDFS_MASK)

#define USBPHY_PWD_TXPWDIBIAS_MASK               (0x800U)
#define USBPHY_PWD_TXPWDIBIAS_SHIFT              (11U)
/*! TXPWDIBIAS - Power down USB PHY current bias block.
 *  0b0..Normal operation
 *  0b1..Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB
 *       is in suspend mode. This effectively powers down the entire USB transmit path.
 */
#define USBPHY_PWD_TXPWDIBIAS(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TXPWDV2I_MASK                 (0x1000U)
#define USBPHY_PWD_TXPWDV2I_SHIFT                (12U)
/*! TXPWDV2I - Power down USB PHY V-I converter and current mirror.
 *  0b0..Normal operation
 *  0b1..Power-down the USB PHY transmit V-to-I converter and the current mirror
 */
#define USBPHY_PWD_TXPWDV2I(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDV2I_SHIFT)) & USBPHY_PWD_TXPWDV2I_MASK)

#define USBPHY_PWD_RXPWDENV_MASK                 (0x20000U)
#define USBPHY_PWD_RXPWDENV_SHIFT                (17U)
/*! RXPWDENV - Power down USB HS receiver envelope detector.
 *  0b0..Normal operation
 *  0b1..Power down the USB high-speed receiver envelope detector (squelch signal)
 */
#define USBPHY_PWD_RXPWDENV(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDENV_SHIFT)) & USBPHY_PWD_RXPWDENV_MASK)

#define USBPHY_PWD_RXPWD1PT1_MASK                (0x40000U)
#define USBPHY_PWD_RXPWD1PT1_SHIFT               (18U)
/*! RXPWD1PT1 - Power down USB FS differential receiver.
 *  0b0..Normal operation
 *  0b1..Power down the USB full-speed differential receiver
 */
#define USBPHY_PWD_RXPWD1PT1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWD1PT1_SHIFT)) & USBPHY_PWD_RXPWD1PT1_MASK)

#define USBPHY_PWD_RXPWDDIFF_MASK                (0x80000U)
#define USBPHY_PWD_RXPWDDIFF_SHIFT               (19U)
/*! RXPWDDIFF - Power down USB HS differential receiver.
 *  0b0..Normal operation
 *  0b1..Power down the USB high-speed differential receiver
 */
#define USBPHY_PWD_RXPWDDIFF(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDDIFF_SHIFT)) & USBPHY_PWD_RXPWDDIFF_MASK)

#define USBPHY_PWD_RXPWDRX_MASK                  (0x100000U)
#define USBPHY_PWD_RXPWDRX_SHIFT                 (20U)
/*! RXPWDRX - Power down USB PHY receiver except the FS differential.
 *  0b0..Normal operation
 *  0b1..Power-down the entire USB PHY receiver block except for the full-speed differential receiver
 */
#define USBPHY_PWD_RXPWDRX(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDRX_SHIFT)) & USBPHY_PWD_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_SET - Power Down Register Set */
/*! @{ */

#define USBPHY_PWD_SET_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_SET_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power down USB FS drivers.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDFS_SHIFT)) & USBPHY_PWD_SET_TXPWDFS_MASK)

#define USBPHY_PWD_SET_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_SET_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power down USB PHY current bias block.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_SET_TXPWDIBIAS_MASK)

#define USBPHY_PWD_SET_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_SET_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power down USB PHY V-I converter and current mirror.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDV2I_SHIFT)) & USBPHY_PWD_SET_TXPWDV2I_MASK)

#define USBPHY_PWD_SET_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_SET_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power down USB HS receiver envelope detector.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDENV_SHIFT)) & USBPHY_PWD_SET_RXPWDENV_MASK)

#define USBPHY_PWD_SET_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_SET_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power down USB FS differential receiver.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWD1PT1_SHIFT)) & USBPHY_PWD_SET_RXPWD1PT1_MASK)

#define USBPHY_PWD_SET_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_SET_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power down USB HS differential receiver.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDDIFF_SHIFT)) & USBPHY_PWD_SET_RXPWDDIFF_MASK)

#define USBPHY_PWD_SET_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_SET_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power down USB PHY receiver except the FS differential.
 *  0b0..No effect
 *  0b1..Sets the corresponding PWD bit
 */
#define USBPHY_PWD_SET_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDRX_SHIFT)) & USBPHY_PWD_SET_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_CLR - Power Down Register Clear */
/*! @{ */

#define USBPHY_PWD_CLR_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_CLR_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power down USB FS drivers.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDFS_SHIFT)) & USBPHY_PWD_CLR_TXPWDFS_MASK)

#define USBPHY_PWD_CLR_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power down USB PHY current bias block.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_CLR_TXPWDIBIAS_MASK)

#define USBPHY_PWD_CLR_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_CLR_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power down USB PHY V-I converter and current mirror.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDV2I_SHIFT)) & USBPHY_PWD_CLR_TXPWDV2I_MASK)

#define USBPHY_PWD_CLR_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_CLR_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power down USB HS receiver envelope detector.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDENV_SHIFT)) & USBPHY_PWD_CLR_RXPWDENV_MASK)

#define USBPHY_PWD_CLR_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_CLR_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power down USB FS differential receiver.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWD1PT1_SHIFT)) & USBPHY_PWD_CLR_RXPWD1PT1_MASK)

#define USBPHY_PWD_CLR_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_CLR_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power down USB HS differential receiver.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDDIFF_SHIFT)) & USBPHY_PWD_CLR_RXPWDDIFF_MASK)

#define USBPHY_PWD_CLR_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_CLR_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power down USB PHY receiver except the FS differential.
 *  0b0..No effect
 *  0b1..Clears the corresponding PWD bit
 */
#define USBPHY_PWD_CLR_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDRX_SHIFT)) & USBPHY_PWD_CLR_RXPWDRX_MASK)
/*! @} */

/*! @name PWD_TOG - Power Down Register Toggle */
/*! @{ */

#define USBPHY_PWD_TOG_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_TOG_TXPWDFS_SHIFT             (10U)
/*! TXPWDFS - Power down USB FS drivers. */
#define USBPHY_PWD_TOG_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDFS_SHIFT)) & USBPHY_PWD_TOG_TXPWDFS_MASK)

#define USBPHY_PWD_TOG_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT          (11U)
/*! TXPWDIBIAS - Power down USB PHY current bias block.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TOG_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TOG_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_TOG_TXPWDV2I_SHIFT            (12U)
/*! TXPWDV2I - Power down USB PHY V-I converter and current mirror.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDV2I_SHIFT)) & USBPHY_PWD_TOG_TXPWDV2I_MASK)

#define USBPHY_PWD_TOG_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_TOG_RXPWDENV_SHIFT            (17U)
/*! RXPWDENV - Power down USB HS receiver envelope detector.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDENV_SHIFT)) & USBPHY_PWD_TOG_RXPWDENV_MASK)

#define USBPHY_PWD_TOG_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_TOG_RXPWD1PT1_SHIFT           (18U)
/*! RXPWD1PT1 - Power down USB FS differential receiver.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWD1PT1_SHIFT)) & USBPHY_PWD_TOG_RXPWD1PT1_MASK)

#define USBPHY_PWD_TOG_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_TOG_RXPWDDIFF_SHIFT           (19U)
/*! RXPWDDIFF - Power down USB HS differential receiver.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDDIFF_SHIFT)) & USBPHY_PWD_TOG_RXPWDDIFF_MASK)

#define USBPHY_PWD_TOG_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_TOG_RXPWDRX_SHIFT             (20U)
/*! RXPWDRX - Power down USB PHY receiver except the FS differential.
 *  0b0..No effect
 *  0b1..Toggles the corresponding PWD bit
 */
#define USBPHY_PWD_TOG_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDRX_SHIFT)) & USBPHY_PWD_TOG_RXPWDRX_MASK)
/*! @} */

/*! @name TX - TX Control */
/*! @{ */

#define USBPHY_TX_D_CAL_MASK                     (0xFU)
#define USBPHY_TX_D_CAL_SHIFT                    (0U)
/*! D_CAL - Current Trim decode. */
#define USBPHY_TX_D_CAL(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TX_D_CAL_MASK)

#define USBPHY_TX_TXCAL45DM_MASK                 (0xF00U)
#define USBPHY_TX_TXCAL45DM_SHIFT                (8U)
/*! TXCAL45DM - DM series termination resistance trim. */
#define USBPHY_TX_TXCAL45DM(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DM_SHIFT)) & USBPHY_TX_TXCAL45DM_MASK)

#define USBPHY_TX_TXENCAL45DN_MASK               (0x2000U)
#define USBPHY_TX_TXENCAL45DN_SHIFT              (13U)
/*! TXENCAL45DN - DN series Resistance calibration. */
#define USBPHY_TX_TXENCAL45DN(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXENCAL45DN_SHIFT)) & USBPHY_TX_TXENCAL45DN_MASK)

#define USBPHY_TX_TXCAL45DP_MASK                 (0xF0000U)
#define USBPHY_TX_TXCAL45DP_SHIFT                (16U)
/*! TXCAL45DP - DP series termination resistance trim. */
#define USBPHY_TX_TXCAL45DP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DP_SHIFT)) & USBPHY_TX_TXCAL45DP_MASK)

#define USBPHY_TX_TXENCAL45DP_MASK               (0x200000U)
#define USBPHY_TX_TXENCAL45DP_SHIFT              (21U)
/*! TXENCAL45DP - DP series resistance calibration */
#define USBPHY_TX_TXENCAL45DP(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXENCAL45DP_SHIFT)) & USBPHY_TX_TXENCAL45DP_MASK)
/*! @} */

/*! @name TX_SET - TX Control Set */
/*! @{ */

#define USBPHY_TX_SET_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_SET_D_CAL_SHIFT                (0U)
/*! D_CAL - Current Trim decode.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding TX bit
 */
#define USBPHY_TX_SET_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_D_CAL_SHIFT)) & USBPHY_TX_SET_D_CAL_MASK)

#define USBPHY_TX_SET_TXENCAL45DM_MASK           (0xF00U)
#define USBPHY_TX_SET_TXENCAL45DM_SHIFT          (8U)
/*! TXENCAL45DM - DM series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding TX bit
 */
#define USBPHY_TX_SET_TXENCAL45DM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXENCAL45DM_SHIFT)) & USBPHY_TX_SET_TXENCAL45DM_MASK)

#define USBPHY_TX_SET_TXENCAL45DN_MASK           (0x2000U)
#define USBPHY_TX_SET_TXENCAL45DN_SHIFT          (13U)
/*! TXENCAL45DN - Enable resistance calibration on DN.
 *  0b0..No effect
 *  0b1..Sets the corresponding TX bit
 */
#define USBPHY_TX_SET_TXENCAL45DN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXENCAL45DN_SHIFT)) & USBPHY_TX_SET_TXENCAL45DN_MASK)

#define USBPHY_TX_SET_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_SET_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding TX bit
 */
#define USBPHY_TX_SET_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DP_SHIFT)) & USBPHY_TX_SET_TXCAL45DP_MASK)

#define USBPHY_TX_SET_TXENCAL45DP_MASK           (0x200000U)
#define USBPHY_TX_SET_TXENCAL45DP_SHIFT          (21U)
/*! TXENCAL45DP - Enable resistance calibration on DP
 *  0b0..No effect
 *  0b1..Sets the corresponding TX bit
 */
#define USBPHY_TX_SET_TXENCAL45DP(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXENCAL45DP_SHIFT)) & USBPHY_TX_SET_TXENCAL45DP_MASK)
/*! @} */

/*! @name TX_CLR - TX Control Clear */
/*! @{ */

#define USBPHY_TX_CLR_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_CLR_D_CAL_SHIFT                (0U)
/*! D_CAL - Current Trim decode.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding TX bit
 */
#define USBPHY_TX_CLR_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_D_CAL_SHIFT)) & USBPHY_TX_CLR_D_CAL_MASK)

#define USBPHY_TX_CLR_TXENCAL45DM_MASK           (0xF00U)
#define USBPHY_TX_CLR_TXENCAL45DM_SHIFT          (8U)
/*! TXENCAL45DM - DM series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding TX bit
 */
#define USBPHY_TX_CLR_TXENCAL45DM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXENCAL45DM_SHIFT)) & USBPHY_TX_CLR_TXENCAL45DM_MASK)

#define USBPHY_TX_CLR_TXENCAL45DN_MASK           (0x2000U)
#define USBPHY_TX_CLR_TXENCAL45DN_SHIFT          (13U)
/*! TXENCAL45DN - Clears Enable resistance calibration on DN.
 *  0b0..No effect
 *  0b1..Clears the corresponding TX bit
 */
#define USBPHY_TX_CLR_TXENCAL45DN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXENCAL45DN_SHIFT)) & USBPHY_TX_CLR_TXENCAL45DN_MASK)

#define USBPHY_TX_CLR_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_CLR_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding TX bit
 */
#define USBPHY_TX_CLR_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DP_SHIFT)) & USBPHY_TX_CLR_TXCAL45DP_MASK)

#define USBPHY_TX_CLR_TXENCAL45DP_MASK           (0x200000U)
#define USBPHY_TX_CLR_TXENCAL45DP_SHIFT          (21U)
/*! TXENCAL45DP - Enable resistance calibration on DP
 *  0b0..No effect
 *  0b1..Clears the corresponding TX bit
 */
#define USBPHY_TX_CLR_TXENCAL45DP(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXENCAL45DP_SHIFT)) & USBPHY_TX_CLR_TXENCAL45DP_MASK)
/*! @} */

/*! @name TX_TOG - TX Control Toggle */
/*! @{ */

#define USBPHY_TX_TOG_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_TOG_D_CAL_SHIFT                (0U)
/*! D_CAL - Current Trim decode.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding TX bit
 */
#define USBPHY_TX_TOG_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_D_CAL_SHIFT)) & USBPHY_TX_TOG_D_CAL_MASK)

#define USBPHY_TX_TOG_TXENCAL45DM_MASK           (0xF00U)
#define USBPHY_TX_TOG_TXENCAL45DM_SHIFT          (8U)
/*! TXENCAL45DM - DM series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding TX bit
 */
#define USBPHY_TX_TOG_TXENCAL45DM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXENCAL45DM_SHIFT)) & USBPHY_TX_TOG_TXENCAL45DM_MASK)

#define USBPHY_TX_TOG_TXENCAL45DN_MASK           (0x2000U)
#define USBPHY_TX_TOG_TXENCAL45DN_SHIFT          (13U)
/*! TXENCAL45DN - Enable resistance calibration on DN.
 *  0b0..No effect
 *  0b1..Toggles the corresponding TX bit
 */
#define USBPHY_TX_TOG_TXENCAL45DN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXENCAL45DN_SHIFT)) & USBPHY_TX_TOG_TXENCAL45DN_MASK)

#define USBPHY_TX_TOG_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_TOG_TXCAL45DP_SHIFT            (16U)
/*! TXCAL45DP - DP series termination resistance trim.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding TX bit
 */
#define USBPHY_TX_TOG_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DP_SHIFT)) & USBPHY_TX_TOG_TXCAL45DP_MASK)

#define USBPHY_TX_TOG_TXENCAL45DP_MASK           (0x200000U)
#define USBPHY_TX_TOG_TXENCAL45DP_SHIFT          (21U)
/*! TXENCAL45DP - Enable resistance calibration on DP
 *  0b0..No effect
 *  0b1..Toggles the corresponding TX bit
 */
#define USBPHY_TX_TOG_TXENCAL45DP(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXENCAL45DP_SHIFT)) & USBPHY_TX_TOG_TXENCAL45DP_MASK)
/*! @} */

/*! @name RX - RX Control */
/*! @{ */

#define USBPHY_RX_ENVADJ_MASK                    (0x7U)
#define USBPHY_RX_ENVADJ_SHIFT                   (0U)
/*! ENVADJ - Envelope detector trip point.
 *  0b000..Trip-Level Voltage is 0.1000 V
 *  0b001..Trip-Level Voltage is 0.1125 V
 *  0b010..Trip-Level Voltage is 0.1250 V
 *  0b011..Trip-Level Voltage is 0.0875 V
 *  0b100-0b111..Reserved
 */
#define USBPHY_RX_ENVADJ(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_ENVADJ_SHIFT)) & USBPHY_RX_ENVADJ_MASK)

#define USBPHY_RX_DISCONADJ_MASK                 (0x70U)
#define USBPHY_RX_DISCONADJ_SHIFT                (4U)
/*! DISCONADJ - Disconnect detector trip point.
 *  0b000..Trip-Level Voltage is 0.56875 V
 *  0b001..Trip-Level Voltage is 0.55000 V
 *  0b010..Trip-Level Voltage is 0.58125 V
 *  0b011..Trip-Level Voltage is 0.60000 V
 *  0b100..reserved
 *  0b101..reserved
 *  0b110..reserved
 *  0b111..reserved
 */
#define USBPHY_RX_DISCONADJ(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_DISCONADJ_SHIFT)) & USBPHY_RX_DISCONADJ_MASK)

#define USBPHY_RX_RXDBYPASS_MASK                 (0x400000U)
#define USBPHY_RX_RXDBYPASS_SHIFT                (22U)
/*! RXDBYPASS - DM bypass
 *  0b0..Normal operation
 *  0b1..Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver
 */
#define USBPHY_RX_RXDBYPASS(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RXDBYPASS_SHIFT)) & USBPHY_RX_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_SET - RX Control Set */
/*! @{ */

#define USBPHY_RX_SET_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_SET_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope detector trip point.
 *  0b000..No effect
 *  0b001..Sets the corresponding TX bit
 */
#define USBPHY_RX_SET_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_ENVADJ_SHIFT)) & USBPHY_RX_SET_ENVADJ_MASK)

#define USBPHY_RX_SET_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_SET_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect detector trip point.
 *  0b000..No effect
 *  0b001..Sets the corresponding TX bit
 */
#define USBPHY_RX_SET_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_DISCONADJ_SHIFT)) & USBPHY_RX_SET_DISCONADJ_MASK)

#define USBPHY_RX_SET_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_SET_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - DM bypass
 *  0b0..No effect
 *  0b1..Sets the corresponding TX bit
 */
#define USBPHY_RX_SET_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RXDBYPASS_SHIFT)) & USBPHY_RX_SET_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_CLR - RX Control Clear */
/*! @{ */

#define USBPHY_RX_CLR_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_CLR_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope detector trip point.
 *  0b000..No effect
 *  0b001..Clears the corresponding TX bit
 */
#define USBPHY_RX_CLR_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_ENVADJ_SHIFT)) & USBPHY_RX_CLR_ENVADJ_MASK)

#define USBPHY_RX_CLR_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_CLR_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect detector trip point.
 *  0b000..No effect
 *  0b001..Clears the corresponding TX bit
 */
#define USBPHY_RX_CLR_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_DISCONADJ_SHIFT)) & USBPHY_RX_CLR_DISCONADJ_MASK)

#define USBPHY_RX_CLR_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_CLR_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - DM bypass
 *  0b0..No effect
 *  0b1..Clears the corresponding TX bit
 */
#define USBPHY_RX_CLR_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RXDBYPASS_SHIFT)) & USBPHY_RX_CLR_RXDBYPASS_MASK)
/*! @} */

/*! @name RX_TOG - RX Control Toggle */
/*! @{ */

#define USBPHY_RX_TOG_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_TOG_ENVADJ_SHIFT               (0U)
/*! ENVADJ - Envelope detector trip point.
 *  0b000..No effect
 *  0b001..Toggles the corresponding TX bit
 */
#define USBPHY_RX_TOG_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_ENVADJ_SHIFT)) & USBPHY_RX_TOG_ENVADJ_MASK)

#define USBPHY_RX_TOG_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_TOG_DISCONADJ_SHIFT            (4U)
/*! DISCONADJ - Disconnect detector trip point.
 *  0b000..No effect
 *  0b001..Toggles the corresponding TX bit
 */
#define USBPHY_RX_TOG_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_DISCONADJ_SHIFT)) & USBPHY_RX_TOG_DISCONADJ_MASK)

#define USBPHY_RX_TOG_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_TOG_RXDBYPASS_SHIFT            (22U)
/*! RXDBYPASS - DM bypass
 *  0b0..No effect
 *  0b1..Toggles the corresponding TX bit
 */
#define USBPHY_RX_TOG_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RXDBYPASS_SHIFT)) & USBPHY_RX_TOG_RXDBYPASS_MASK)
/*! @} */

/*! @name CTRL - General Purpose Control */
/*! @{ */

#define USBPHY_CTRL_ENHOSTDISCONDETECT_MASK      (0x2U)
#define USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT     (1U)
/*! ENHOSTDISCONDETECT - Disconnect detect. */
#define USBPHY_CTRL_ENHOSTDISCONDETECT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK    (0x8U)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT   (3U)
/*! HOSTDISCONDETECT_IRQ - Device disconnect indication. */
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_ENDEVPLUGINDET_MASK          (0x10U)
#define USBPHY_CTRL_ENDEVPLUGINDET_SHIFT         (4U)
/*! ENDEVPLUGINDET - Enables non-standard resistive plugged-in detection.
 *  0b0..Disables 200kohm pullup resistors on USB_DP and USB_DM pins (Default)
 *  0b1..Enables 200kohm pullup resistors on USB_DP and USB_DM pins (Default)
 */
#define USBPHY_CTRL_ENDEVPLUGINDET(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENDEVPLUGINDET_SHIFT)) & USBPHY_CTRL_ENDEVPLUGINDET_MASK)

#define USBPHY_CTRL_DEVPLUGIN_IRQ_MASK           (0x1000U)
#define USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT          (12U)
/*! DEVPLUGIN_IRQ - Device connected indicator */
#define USBPHY_CTRL_DEVPLUGIN_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_ENUTMILEVEL2_MASK            (0x4000U)
#define USBPHY_CTRL_ENUTMILEVEL2_SHIFT           (14U)
/*! ENUTMILEVEL2 - Enable level 2 operation */
#define USBPHY_CTRL_ENUTMILEVEL2(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_ENUTMILEVEL3_MASK            (0x8000U)
#define USBPHY_CTRL_ENUTMILEVEL3_SHIFT           (15U)
/*! ENUTMILEVEL3 - Enable level 2 operation */
#define USBPHY_CTRL_ENUTMILEVEL3(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_AUTORESUME_EN_MASK           (0x40000U)
#define USBPHY_CTRL_AUTORESUME_EN_SHIFT          (18U)
/*! AUTORESUME_EN - Enable autoresume */
#define USBPHY_CTRL_AUTORESUME_EN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK       (0x80000U)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT      (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear clock gate. */
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK       (0x100000U)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT      (20U)
/*! ENAUTOCLR_PHY_PWD - Autoclear PWD register bits. */
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_FSDLL_RST_EN_MASK            (0x1000000U)
#define USBPHY_CTRL_FSDLL_RST_EN_SHIFT           (24U)
/*! FSDLL_RST_EN - Reset FSDLL lock */
#define USBPHY_CTRL_FSDLL_RST_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK       (0x10000000U)
#define USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT      (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP low-speed timing */
#define USBPHY_CTRL_HOST_FORCE_LS_SE0(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_UTMI_SUSPENDM_MASK           (0x20000000U)
#define USBPHY_CTRL_UTMI_SUSPENDM_SHIFT          (29U)
/*! UTMI_SUSPENDM - UTMI suspend */
#define USBPHY_CTRL_UTMI_SUSPENDM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLKGATE_MASK                 (0x40000000U)
#define USBPHY_CTRL_CLKGATE_SHIFT                (30U)
/*! CLKGATE - UTMI clock gate */
#define USBPHY_CTRL_CLKGATE(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLKGATE_SHIFT)) & USBPHY_CTRL_CLKGATE_MASK)

#define USBPHY_CTRL_SFTRST_MASK                  (0x80000000U)
#define USBPHY_CTRL_SFTRST_SHIFT                 (31U)
/*! SFTRST - Software reset */
#define USBPHY_CTRL_SFTRST(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SFTRST_SHIFT)) & USBPHY_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - General Purpose Control Set */
/*! @{ */

#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Disconnect detect.
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Device disconnect indication.
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_SET_ENDEVPLUGINDET_MASK      (0x10U)
#define USBPHY_CTRL_SET_ENDEVPLUGINDET_SHIFT     (4U)
/*! ENDEVPLUGINDET - Enables non-standard resistive plugged-in detection.
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENDEVPLUGINDET(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENDEVPLUGINDET_SHIFT)) & USBPHY_CTRL_SET_ENDEVPLUGINDET_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device connected indicator
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_SET_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Enable autoresume
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_SET_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear clock gate.
 *  0b0..No effect
 *  0b1..the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - Autoclear PWD register bits.
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_SET_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - Reset FSDLL lock
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_SET_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP low-speed timing */
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI suspend
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_SET_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_SET_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI clock gate
 *  0b0..No effect
 *  0b1..the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_CLKGATE_MASK)

#define USBPHY_CTRL_SET_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_SET_SFTRST_SHIFT             (31U)
/*! SFTRST - Software reset
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_CTRL_SET_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_SFTRST_SHIFT)) & USBPHY_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - General Purpose Control Clear */
/*! @{ */

#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Disconnect detect.
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Device disconnect indication.
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENDEVPLUGINDET_MASK      (0x10U)
#define USBPHY_CTRL_CLR_ENDEVPLUGINDET_SHIFT     (4U)
/*! ENDEVPLUGINDET - Enables non-standard resistive plugged-in detection.
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENDEVPLUGINDET(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENDEVPLUGINDET_SHIFT)) & USBPHY_CTRL_CLR_ENDEVPLUGINDET_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device connected indicator
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_CLR_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Enable autoresume
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_CLR_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear clock gate.
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - Autoclear PWD register bits.
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - Reset FSDLL lock
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP low-speed timing */
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI suspend
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLR_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_CLR_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI clock gate
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_CLR_SFTRST_SHIFT             (31U)
/*! SFTRST - Software reset
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_CTRL_CLR_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_SFTRST_SHIFT)) & USBPHY_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - General Purpose Control Toggle */
/*! @{ */

#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT (1U)
/*! ENHOSTDISCONDETECT - Disconnect detect.
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT (3U)
/*! HOSTDISCONDETECT_IRQ - Device disconnect indication.
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENDEVPLUGINDET_MASK      (0x10U)
#define USBPHY_CTRL_TOG_ENDEVPLUGINDET_SHIFT     (4U)
/*! ENDEVPLUGINDET - Enables non-standard resistive plugged-in detection.
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENDEVPLUGINDET(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENDEVPLUGINDET_SHIFT)) & USBPHY_CTRL_TOG_ENDEVPLUGINDET_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT      (12U)
/*! DEVPLUGIN_IRQ - Device connected indicator
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT       (14U)
/*! ENUTMILEVEL2 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT       (15U)
/*! ENUTMILEVEL3 - Enable level 2 operation
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_TOG_AUTORESUME_EN_MASK       (0x40000U)
#define USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT      (18U)
/*! AUTORESUME_EN - Enable autoresume
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_AUTORESUME_EN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_AUTORESUME_EN_SHIFT)) & USBPHY_CTRL_TOG_AUTORESUME_EN_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT  (19U)
/*! ENAUTOCLR_CLKGATE - Autoclear clock gate.
 *  0b0..No effect
 *  0b1..the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
/*! ENAUTOCLR_PHY_PWD - Autoclear PWD register bits.
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT       (24U)
/*! FSDLL_RST_EN - Reset FSDLL lock
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT  (28U)
/*! HOST_FORCE_LS_SE0 - FS EOP low-speed timing */
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT      (29U)
/*! UTMI_SUSPENDM - UTMI suspend
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_TOG_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_TOG_CLKGATE_SHIFT            (30U)
/*! CLKGATE - UTMI clock gate
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_TOG_SFTRST_SHIFT             (31U)
/*! SFTRST - Software reset
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_CTRL_TOG_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_SFTRST_SHIFT)) & USBPHY_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STATUS - Status */
/*! @{ */

#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK (0x8U)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT (3U)
/*! HOSTDISCONDETECT_STATUS - Host disconnect status
 *  0b0..USB cable disconnect has not been detected at the local host
 *  0b1..USB cable disconnect has been detected at the local host
 */
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT)) & USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK)

#define USBPHY_STATUS_DEVPLUGIN_STATUS_MASK      (0x40U)
#define USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT     (6U)
/*! DEVPLUGIN_STATUS - Status indicator for non-standard resistive plugged-in detection.
 *  0b0..No attachment to a USB host is detected
 *  0b1..Cable attachment to a USB host is detected
 */
#define USBPHY_STATUS_DEVPLUGIN_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT)) & USBPHY_STATUS_DEVPLUGIN_STATUS_MASK)

#define USBPHY_STATUS_RESUME_STATUS_MASK         (0x400U)
#define USBPHY_STATUS_RESUME_STATUS_SHIFT        (10U)
/*! RESUME_STATUS - Resume status */
#define USBPHY_STATUS_RESUME_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RESUME_STATUS_SHIFT)) & USBPHY_STATUS_RESUME_STATUS_MASK)
/*! @} */

/*! @name DEBUG0 - Debug 0 */
/*! @{ */

#define USBPHY_DEBUG0_DEBUG_INTERFACE_HOLD_MASK  (0x2U)
#define USBPHY_DEBUG0_DEBUG_INTERFACE_HOLD_SHIFT (1U)
/*! DEBUG_INTERFACE_HOLD - Debug interface */
#define USBPHY_DEBUG0_DEBUG_INTERFACE_HOLD(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG0_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG0_HSTPULLDOWN_MASK           (0xCU)
#define USBPHY_DEBUG0_HSTPULLDOWN_SHIFT          (2U)
/*! HSTPULLDOWN - HS DP/DM pulldown resistance select. */
#define USBPHY_DEBUG0_HSTPULLDOWN(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_ENHSTPULLDOWN_MASK         (0x30U)
#define USBPHY_DEBUG0_ENHSTPULLDOWN_SHIFT        (4U)
/*! ENHSTPULLDOWN - Enable Host pulldown */
#define USBPHY_DEBUG0_ENHSTPULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_TX2RXCOUNT_MASK            (0xF00U)
#define USBPHY_DEBUG0_TX2RXCOUNT_SHIFT           (8U)
/*! TX2RXCOUNT - TX2RXCOUNT */
#define USBPHY_DEBUG0_TX2RXCOUNT(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_ENTX2RXCOUNT_MASK          (0x1000U)
#define USBPHY_DEBUG0_ENTX2RXCOUNT_SHIFT         (12U)
#define USBPHY_DEBUG0_ENTX2RXCOUNT(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_SQUELCHRESETCOUNT_MASK     (0x1F0000U)
#define USBPHY_DEBUG0_SQUELCHRESETCOUNT_SHIFT    (16U)
/*! SQUELCHRESETCOUNT - Squelch reset count */
#define USBPHY_DEBUG0_SQUELCHRESETCOUNT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG0_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG0_ENSQUELCHRESET_MASK        (0x1000000U)
#define USBPHY_DEBUG0_ENSQUELCHRESET_SHIFT       (24U)
/*! ENSQUELCHRESET - Enable squelch reset */
#define USBPHY_DEBUG0_ENSQUELCHRESET(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG0_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG0_SQUELCHRESETLENGTH_MASK    (0x1E000000U)
#define USBPHY_DEBUG0_SQUELCHRESETLENGTH_SHIFT   (25U)
/*! SQUELCHRESETLENGTH - Squelch reset length */
#define USBPHY_DEBUG0_SQUELCHRESETLENGTH(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG0_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG0_HOST_RESUME_DEBUG_MASK     (0x20000000U)
#define USBPHY_DEBUG0_HOST_RESUME_DEBUG_SHIFT    (29U)
/*! HOST_RESUME_DEBUG - Host resume */
#define USBPHY_DEBUG0_HOST_RESUME_DEBUG(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG0_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG0_CLKGATE_MASK               (0x40000000U)
#define USBPHY_DEBUG0_CLKGATE_SHIFT              (30U)
/*! CLKGATE - Test clock gate */
#define USBPHY_DEBUG0_CLKGATE(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLKGATE_SHIFT)) & USBPHY_DEBUG0_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG0_SET - Debug 0 Set */
/*! @{ */

#define USBPHY_DEBUG0_SET_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG0_SET_DEBUG_INTERFACE_HOLD_SHIFT (1U)
/*! DEBUG_INTERFACE_HOLD - Debug interface
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG0_SET_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG0_SET_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_SET_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - HS DP/DM pulldown resistance select.
 *  0b00..No effect
 *  0b01..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_SET_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host pulldown
 *  0b00..No effect
 *  0b01..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_SET_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_SET_TX2RXCOUNT_MASK        (0xF00U)
#define USBPHY_DEBUG0_SET_TX2RXCOUNT_SHIFT       (8U)
/*! TX2RXCOUNT - TX2RXCOUNT
 *  0b0000..No effect
 *  0b0001..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_TX2RXCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_SET_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_SET_ENTX2RXCOUNT_MASK      (0x1000U)
#define USBPHY_DEBUG0_SET_ENTX2RXCOUNT_SHIFT     (12U)
/*! ENTX2RXCOUNT - ENTX2RXCOUNT
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_ENTX2RXCOUNT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_SET_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_SET_SQUELCHRESETCOUNT_MASK (0x1F0000U)
#define USBPHY_DEBUG0_SET_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch reset count
 *  0b00000..No effect
 *  0b00001..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_SQUELCHRESETCOUNT(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG0_SET_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG0_SET_ENSQUELCHRESET_MASK    (0x1000000U)
#define USBPHY_DEBUG0_SET_ENSQUELCHRESET_SHIFT   (24U)
/*! ENSQUELCHRESET - Enable squelch reset
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_ENSQUELCHRESET(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG0_SET_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG0_SET_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG0_SET_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch reset length
 *  0b0000..No effect
 *  0b0001..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_SQUELCHRESETLENGTH(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG0_SET_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG0_SET_HOST_RESUME_DEBUG_MASK (0x20000000U)
#define USBPHY_DEBUG0_SET_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host resume
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_HOST_RESUME_DEBUG(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG0_SET_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG0_SET_CLKGATE_MASK           (0x40000000U)
#define USBPHY_DEBUG0_SET_CLKGATE_SHIFT          (30U)
/*! CLKGATE - Test clock gate
 *  0b0..No effect
 *  0b1..Sets the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_SET_CLKGATE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_SET_CLKGATE_SHIFT)) & USBPHY_DEBUG0_SET_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG0_CLR - Debug Clear */
/*! @{ */

#define USBPHY_DEBUG0_CLR_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG0_CLR_DEBUG_INTERFACE_HOLD_SHIFT (1U)
/*! DEBUG_INTERFACE_HOLD - Debug interface
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG0_CLR_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG0_CLR_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_CLR_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - HS DP/DM pulldown resistance select.
 *  0b00..No effect
 *  0b01..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_CLR_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host pulldown
 *  0b00..No effect
 *  0b01..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_CLR_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_CLR_TX2RXCOUNT_MASK        (0xF00U)
#define USBPHY_DEBUG0_CLR_TX2RXCOUNT_SHIFT       (8U)
/*! TX2RXCOUNT - TX2RXCOUNT
 *  0b0000..No effect
 *  0b0001..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_TX2RXCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_CLR_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_CLR_ENTX2RXCOUNT_MASK      (0x1000U)
#define USBPHY_DEBUG0_CLR_ENTX2RXCOUNT_SHIFT     (12U)
/*! ENTX2RXCOUNT - ENTX2RXCOUNT
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_ENTX2RXCOUNT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_CLR_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_CLR_SQUELCHRESETCOUNT_MASK (0x1F0000U)
#define USBPHY_DEBUG0_CLR_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch reset count
 *  0b00000..No effect
 *  0b00001..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_SQUELCHRESETCOUNT(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG0_CLR_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG0_CLR_ENSQUELCHRESET_MASK    (0x1000000U)
#define USBPHY_DEBUG0_CLR_ENSQUELCHRESET_SHIFT   (24U)
/*! ENSQUELCHRESET - Enable squelch reset
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_ENSQUELCHRESET(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG0_CLR_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG0_CLR_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG0_CLR_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch reset length
 *  0b0000..No effect
 *  0b0001..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_SQUELCHRESETLENGTH(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG0_CLR_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG0_CLR_HOST_RESUME_DEBUG_MASK (0x20000000U)
#define USBPHY_DEBUG0_CLR_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host resume
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_HOST_RESUME_DEBUG(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG0_CLR_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG0_CLR_CLKGATE_MASK           (0x40000000U)
#define USBPHY_DEBUG0_CLR_CLKGATE_SHIFT          (30U)
/*! CLKGATE - Test clock gate
 *  0b0..No effect
 *  0b1..Clears the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_CLR_CLKGATE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_CLR_CLKGATE_SHIFT)) & USBPHY_DEBUG0_CLR_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG0_TOG - Debug Toggle */
/*! @{ */

#define USBPHY_DEBUG0_TOG_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG0_TOG_DEBUG_INTERFACE_HOLD_SHIFT (1U)
/*! DEBUG_INTERFACE_HOLD - Debug interface
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG0_TOG_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG0_TOG_HSTPULLDOWN_MASK       (0xCU)
#define USBPHY_DEBUG0_TOG_HSTPULLDOWN_SHIFT      (2U)
/*! HSTPULLDOWN - HS DP/DM pulldown resistance select.
 *  0b00..No effect
 *  0b01..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_HSTPULLDOWN(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_TOG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_MASK     (0x30U)
#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_SHIFT    (4U)
/*! ENHSTPULLDOWN - Enable Host pulldown
 *  0b00..No effect
 *  0b01..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_ENHSTPULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG0_TOG_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG0_TOG_TX2RXCOUNT_MASK        (0xF00U)
#define USBPHY_DEBUG0_TOG_TX2RXCOUNT_SHIFT       (8U)
/*! TX2RXCOUNT - TX2RXCOUNT
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_TX2RXCOUNT(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_TOG_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_TOG_ENTX2RXCOUNT_MASK      (0x1000U)
#define USBPHY_DEBUG0_TOG_ENTX2RXCOUNT_SHIFT     (12U)
/*! ENTX2RXCOUNT - ENTX2RXCOUNT
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_ENTX2RXCOUNT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG0_TOG_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG0_TOG_SQUELCHRESETCOUNT_MASK (0x1F0000U)
#define USBPHY_DEBUG0_TOG_SQUELCHRESETCOUNT_SHIFT (16U)
/*! SQUELCHRESETCOUNT - Squelch reset count
 *  0b00000..No effect
 *  0b00001..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_SQUELCHRESETCOUNT(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG0_TOG_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG0_TOG_ENSQUELCHRESET_MASK    (0x1000000U)
#define USBPHY_DEBUG0_TOG_ENSQUELCHRESET_SHIFT   (24U)
/*! ENSQUELCHRESET - Enable squelch reset
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_ENSQUELCHRESET(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG0_TOG_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG0_TOG_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG0_TOG_SQUELCHRESETLENGTH_SHIFT (25U)
/*! SQUELCHRESETLENGTH - Squelch reset length
 *  0b0000..No effect
 *  0b0001..the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_SQUELCHRESETLENGTH(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG0_TOG_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG0_TOG_HOST_RESUME_DEBUG_MASK (0x20000000U)
#define USBPHY_DEBUG0_TOG_HOST_RESUME_DEBUG_SHIFT (29U)
/*! HOST_RESUME_DEBUG - Host resume
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_HOST_RESUME_DEBUG(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG0_TOG_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG0_TOG_CLKGATE_MASK           (0x40000000U)
#define USBPHY_DEBUG0_TOG_CLKGATE_SHIFT          (30U)
/*! CLKGATE - Test clock gate
 *  0b0..No effect
 *  0b1..Toggles the corresponding CTRL bit
 */
#define USBPHY_DEBUG0_TOG_CLKGATE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_TOG_CLKGATE_SHIFT)) & USBPHY_DEBUG0_TOG_CLKGATE_MASK)
/*! @} */

/*! @name DEBUG1 - UTMI Debug 1 */
/*! @{ */

#define USBPHY_DEBUG1_ENTAILADJVD_MASK           (0x6000U)
#define USBPHY_DEBUG1_ENTAILADJVD_SHIFT          (13U)
/*! ENTAILADJVD - Enable delay increment
 *  0b00..Delay is nominal
 *  0b01..Delay is +20%
 *  0b10..Delay is -20%
 *  0b11..Delay is -40%
 */
#define USBPHY_DEBUG1_ENTAILADJVD(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_MASK   (0x1C0000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_SHIFT  (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap adjustment */
#define USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_USB2_REFBIAS_TST_MASK      (0x600000U)
#define USBPHY_DEBUG1_USB2_REFBIAS_TST_SHIFT     (21U)
/*! USB2_REFBIAS_TST - Bias current control */
#define USBPHY_DEBUG1_USB2_REFBIAS_TST(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_SET - UTMI Debug 1 Set */
/*! @{ */

#define USBPHY_DEBUG1_SET_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - Enable delay increment
 *  0b00..No effect
 *  0b01..Sets the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_SET_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_SET_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap adjustment
 *  0b000..No effect
 *  0b001..Sets the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias current control
 *  0b00..No effect
 *  0b01..Sets the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_SET_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_SET_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_CLR - UTMI Debug 1 Clear */
/*! @{ */

#define USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - Enable delay increment
 *  0b00..No effect
 *  0b01..Clears the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_CLR_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap adjustment
 *  0b000..No effect
 *  0b001..Clears the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias current control
 *  0b00..No effect
 *  0b01..Clears the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_CLR_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name DEBUG1_TOG - UTMI Debug 1 Toggle */
/*! @{ */

#define USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT      (13U)
/*! ENTAILADJVD - Enable delay increment
 *  0b00..No effect
 *  0b01..Clears the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_TOG_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_MASK (0x1C0000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_SHIFT (18U)
/*! USB2_REFBIAS_VBGADJ - Bandgap adjustment
 *  0b000..No effect
 *  0b001..Toggles the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_MASK  (0x600000U)
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_SHIFT (21U)
/*! USB2_REFBIAS_TST - Bias current control
 *  0b00..No effect
 *  0b01..Toggles the corresponding DEBUG1 bit
 */
#define USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_SHIFT)) & USBPHY_DEBUG1_TOG_USB2_REFBIAS_TST_MASK)
/*! @} */

/*! @name VERSION - Version */
/*! @{ */

#define USBPHY_VERSION_STEP_MASK                 (0xFFFFU)
#define USBPHY_VERSION_STEP_SHIFT                (0U)
/*! STEP - STEP */
#define USBPHY_VERSION_STEP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_STEP_SHIFT)) & USBPHY_VERSION_STEP_MASK)

#define USBPHY_VERSION_MINOR_MASK                (0xFF0000U)
#define USBPHY_VERSION_MINOR_SHIFT               (16U)
/*! MINOR - MINOR */
#define USBPHY_VERSION_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MINOR_SHIFT)) & USBPHY_VERSION_MINOR_MASK)

#define USBPHY_VERSION_MAJOR_MASK                (0xFF000000U)
#define USBPHY_VERSION_MAJOR_SHIFT               (24U)
/*! MAJOR - MAJOR */
#define USBPHY_VERSION_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MAJOR_SHIFT)) & USBPHY_VERSION_MAJOR_MASK)
/*! @} */

/*! @name PLL_SIC - PLL Control/Status */
/*! @{ */

#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK      (0x40U)
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT     (6U)
/*! PLL_EN_USB_CLKS - PLL clock enable */
#define USBPHY_PLL_SIC_PLL_EN_USB_CLKS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_PLL_POWER_MASK            (0x1000U)
#define USBPHY_PLL_SIC_PLL_POWER_SHIFT           (12U)
/*! PLL_POWER - Power PLL */
#define USBPHY_PLL_SIC_PLL_POWER(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_PLL_ENABLE_MASK           (0x2000U)
#define USBPHY_PLL_SIC_PLL_ENABLE_SHIFT          (13U)
/*! PLL_ENABLE - PLL enable */
#define USBPHY_PLL_SIC_PLL_ENABLE(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_BYPASS_MASK           (0x10000U)
#define USBPHY_PLL_SIC_PLL_BYPASS_SHIFT          (16U)
/*! PLL_BYPASS - Bypass USB PLL
 *  0b0..Use USB PLL
 *  0b1..Bypass USB PLL
 */
#define USBPHY_PLL_SIC_PLL_BYPASS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK      (0x80000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT     (19U)
/*! REFBIAS_PWD_SEL - Reference bias power control
 *  0b0..Selects PLL_POWER to control the reference bias
 *  0b1..Selects REFBIAS_PWD to control the reference bias
 */
#define USBPHY_PLL_SIC_REFBIAS_PWD_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_REFBIAS_PWD_MASK          (0x100000U)
#define USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT         (20U)
/*! REFBIAS_PWD - Power down Reference bias */
#define USBPHY_PLL_SIC_REFBIAS_PWD(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK       (0x200000U)
#define USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT      (21U)
/*! PLL_REG_ENABLE - Enable PLL regulator */
#define USBPHY_PLL_SIC_PLL_REG_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_PLL_DIV_SEL_MASK          (0x1C00000U)
#define USBPHY_PLL_SIC_PLL_DIV_SEL_SHIFT         (22U)
/*! PLL_DIV_SEL - PLL Divider value
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
#define USBPHY_PLL_SIC_PLL_LOCK(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_SET - PLL Control/Status Set */
/*! @{ */

#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL_EN_USB_CLKS
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_SET_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - POWER
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - ENABLE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - REFBIAS_PWD_SEL
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - REFBIAS_PWD
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_SET_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL_REG_ENABLE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL_DIV_SEL
 *  0b000..No effect
 *  0b001..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_SET_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL_LOCK
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_PLL_SIC_SET_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_SET_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_SET_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_CLR - PLL Control/Status Clear */
/*! @{ */

#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL_EN_USB_CLKS
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - POWER
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - ENABLE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - REFBIAS_PWD_SEL
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - REFBIAS_PWD
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_CLR_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL_REG_ENABLE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL_DIV_SEL
 *  0b000..No effect
 *  0b001..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL_LOCK
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_PLL_SIC_CLR_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_CLR_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_CLR_PLL_LOCK_MASK)
/*! @} */

/*! @name PLL_SIC_TOG - PLL Control/Status Toggle */
/*! @{ */

#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK  (0x40U)
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT (6U)
/*! PLL_EN_USB_CLKS - PLL_EN_USB_CLKS
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_EN_USB_CLKS_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_POWER_MASK        (0x1000U)
#define USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT       (12U)
/*! PLL_POWER - POWER
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_POWER(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_POWER_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_POWER_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK       (0x2000U)
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT      (13U)
/*! PLL_ENABLE - PLL ENABLE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_ENABLE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK       (0x10000U)
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT      (16U)
/*! PLL_BYPASS - Bypass USB PLL
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_BYPASS(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_BYPASS_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_BYPASS_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK  (0x80000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT (19U)
/*! REFBIAS_PWD_SEL - REFBIAS_PWD_SEL
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK      (0x100000U)
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT     (20U)
/*! REFBIAS_PWD - REFBIAS_PWD
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_REFBIAS_PWD(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_REFBIAS_PWD_SHIFT)) & USBPHY_PLL_SIC_TOG_REFBIAS_PWD_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK   (0x200000U)
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT  (21U)
/*! PLL_REG_ENABLE - PLL_REG_ENABLE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_REG_ENABLE_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK      (0x1C00000U)
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT     (22U)
/*! PLL_DIV_SEL - PLL_DIV_SEL
 *  0b000..No effect
 *  0b001..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_DIV_SEL(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_DIV_SEL_MASK)

#define USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK         (0x80000000U)
#define USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT        (31U)
/*! PLL_LOCK - PLL_LOCK
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_PLL_SIC_TOG_PLL_LOCK(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_PLL_SIC_TOG_PLL_LOCK_SHIFT)) & USBPHY_PLL_SIC_TOG_PLL_LOCK_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT - VBUS detect */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS comparator threshold */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS detect signal override enable
 *  0b0..Use the results of the internal VBUS_VALID and Session Valid comparators for VBUS_VALID, AVALID, BVALID, and SESSEND (Default)
 *  0b1..Use the override values for VBUS_VALID, AVALID, BVALID, and SESSEND
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override value for SESSEND */
#define USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override value for B-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override value for A-Device Session Valid */
#define USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override value for VBUS_VALID signal sent to USB controller */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller
 *  0b0..Use the VBUS_VALID comparator results for signal reported to the USB controller (Default)
 *  0b1..Use the VBUS_VALID_3V detector results for signal reported to the USB controller
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller
 *  0b00..Use the VBUS_VALID comparator results for signal reported to the USB controller (Default)
 *  0b01..Use the Session Valid comparator results for signal reported to the USB controller
 *  0b10..Use the Session Valid comparator results for signal reported to the USB controller
 *  0b11..Reserved, do not use
 */
#define USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - Selects the comparator used for VBUS_VALID
 *  0b0..Use the VBUS_VALID comparator for VBUS_VALID results
 *  0b1..Use the Session End comparator for VBUS_VALID results. The Session End threshold is >0.8V and <4.0V.
 */
#define USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_MASK  (0x100000U)
#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - Enables the VBUS_VALID comparator
 *  0b0..Powers down the VBUS_VALID comparator
 *  0b1..Enables the VBUS_VALID comparator (default)
 */
#define USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - Controls VBUS discharge resistor
 *  0b0..VBUS discharge resistor is disabled (Default)
 *  0b1..VBUS discharge resistor is enabled
 */
#define USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Enables resistors used for an older method of resistive battery charger detection
 *  0b0..Disable resistive charger detection resistors on DP and DP
 *  0b1..Enable resistive charger detection resistors on DP and DP
 */
#define USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_SET - VBUS detect Set */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS comparator threshold
 *  0b000..No effect
 *  0b001..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS detect signal override. This bit is used when EXT_VBUS_OVERRIDE_EN = 1'b0.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override value for SESSEND
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override value for B-Device Session Valid
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override value for A-Device Session Valid
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override value for VBUS_VALID signal sent to USB controller
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - Selects the comparator used for VBUS_VALID
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_MASK (0x100000U)
#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - Enables the VBUS_VALID comparator
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - Controls VBUS discharge resistor
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Enables resistors used for an older method of resistive battery charger detection
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_SET_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_CLR - VBUS detect Clear */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS comparator threshold
 *  0b000..No effect
 *  0b001..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS detect signal override. This bit is used when EXT_VBUS_OVERRIDE_EN = 1'b0.
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override value for SESSEND
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override value for B-Device Session Valid
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override value for A-Device Session Valid
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override value for VBUS_VALID signal sent to USB controller
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - Selects the comparator used for VBUS_VALID
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_MASK (0x100000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - Enables the VBUS_VALID comparator
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - Controls VBUS discharge resistor
 *  0b0..No effect
 *  0b1..clears the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Enables resistors used for an older method of resistive battery charger detection
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_CLR_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DETECT_TOG - VBUS detect Toggle */
/*! @{ */

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK (0x7U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT (0U)
/*! VBUSVALID_THRESH - VBUS comparator threshold
 *  0b000..No effect
 *  0b001..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_THRESH_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK (0x8U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT (3U)
/*! VBUS_OVERRIDE_EN - VBUS detect signal override. This bit is used when EXT_VBUS_OVERRIDE_EN = 1'b0.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_OVERRIDE_EN_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK (0x10U)
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT (4U)
/*! SESSEND_OVERRIDE - Override value for SESSEND
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_SESSEND_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK (0x20U)
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT (5U)
/*! BVALID_OVERRIDE - Override value for B-Device Session Valid
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_BVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK (0x40U)
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT (6U)
/*! AVALID_OVERRIDE - Override value for A-Device Session Valid
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_AVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK (0x80U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT (7U)
/*! VBUSVALID_OVERRIDE - Override value for VBUS_VALID signal sent to USB controller
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_OVERRIDE_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK (0x100U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT (8U)
/*! VBUSVALID_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK (0x600U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT (9U)
/*! VBUS_SOURCE_SEL - Selects the source of the VBUS_VALID signal reported to the USB controller */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUS_SOURCE_SEL_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_MASK (0x40000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_SHIFT (18U)
/*! VBUSVALID_TO_SESSVALID - Selects the comparator used for VBUS_VALID
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_VBUSVALID_TO_SESSVALID_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_MASK (0x100000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_SHIFT (20U)
/*! PWRUP_CMPS - Enables the VBUS_VALID comparator
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_PWRUP_CMPS_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK (0x4000000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT (26U)
/*! DISCHARGE_VBUS - Controls VBUS discharge resistor
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_DISCHARGE_VBUS_MASK)

#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_MASK (0x80000000U)
#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_SHIFT (31U)
/*! EN_CHARGER_RESISTOR - Enables resistors used for an older method of resistive battery charger detection
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_SHIFT)) & USBPHY_USB1_VBUS_DETECT_TOG_EN_CHARGER_RESISTOR_MASK)
/*! @} */

/*! @name USB1_VBUS_DET_STAT - VBUS Detect Status */
/*! @{ */

#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK   (0x1U)
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT  (0U)
/*! SESSEND - Session End indicator
 *  0b0..The VBUS voltage is above the Session Valid threshold
 *  0b1..The VBUS voltage is below the Session Valid threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_SESSEND(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_SESSEND_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_SESSEND_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK    (0x2U)
#define USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT   (1U)
/*! BVALID - B-Device Session Valid status
 *  0b0..The VBUS voltage is below the Session Valid threshold
 *  0b1..The VBUS voltage is above the Session Valid threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_BVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_BVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_BVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK    (0x4U)
#define USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT   (2U)
/*! AVALID - A-Device Session Valid status
 *  0b0..The VBUS voltage is below the Session Valid threshold
 *  0b1..The VBUS voltage is above the Session Valid threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_AVALID(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_AVALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_AVALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK (0x8U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT (3U)
/*! VBUS_VALID - VBUS voltage status
 *  0b0..VBUS is below the comparator threshold
 *  0b1..VBUS is above the comparator threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_MASK)

#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK (0x10U)
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT (4U)
/*! VBUS_VALID_3V - VBUS_VALID_3V detector status
 *  0b0..VBUS voltage is below VBUS_VALID_3V threshold
 *  0b1..VBUS voltage is above VBUS_VALID_3V threshold
 */
#define USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_SHIFT)) & USBPHY_USB1_VBUS_DET_STAT_VBUS_VALID_3V_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT - Charger Detect Control */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK   (0x4U)
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT  (2U)
/*! PULLUP_DP - PULLUP_DP */
#define USBPHY_USB1_CHRG_DETECT_PULLUP_DP(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_BGR_IBIAS_MASK   (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_BGR_IBIAS_SHIFT  (23U)
/*! BGR_IBIAS - USB charge detector bias current reference
 *  0b0..Bias current is derived from the USB PHY internal current generator.
 *  0b1..Bias current is derived from the reference generator of the bandgap.
 */
#define USBPHY_USB1_CHRG_DETECT_BGR_IBIAS(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_BGR_IBIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_BGR_IBIAS_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_SET - Charger Detect Control Set */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - PULLUP_DP
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_SET_BGR_IBIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_SET_BGR_IBIAS_SHIFT (23U)
/*! BGR_IBIAS - BGR_IBIAS
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_SET_BGR_IBIAS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_SET_BGR_IBIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_SET_BGR_IBIAS_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_CLR - Charger Detect Control Clear */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - PULLUP_DP
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_IBIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_IBIAS_SHIFT (23U)
/*! BGR_IBIAS - BGR_IBIAS
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_CLR_BGR_IBIAS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_CLR_BGR_IBIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_CLR_BGR_IBIAS_MASK)
/*! @} */

/*! @name USB1_CHRG_DETECT_TOG - Charger Detect Control Toggle */
/*! @{ */

#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK (0x4U)
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT (2U)
/*! PULLUP_DP - PULLUP_DP
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_PULLUP_DP_MASK)

#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_IBIAS_MASK (0x800000U)
#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_IBIAS_SHIFT (23U)
/*! BGR_IBIAS - BGR_IBIAS
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_CHRG_DETECT_TOG_BGR_IBIAS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DETECT_TOG_BGR_IBIAS_SHIFT)) & USBPHY_USB1_CHRG_DETECT_TOG_BGR_IBIAS_MASK)
/*! @} */

/*! @name USB1_CHRG_DET_STAT - Charge Detect Status */
/*! @{ */

#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK (0x1U)
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT (0U)
/*! PLUG_CONTACT - Battery Charging Data Contact Detection phase output
 *  0b0..No USB cable attachment has been detected
 *  0b1..A USB cable attachment between the device and host has been detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_PLUG_CONTACT_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK (0x2U)
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT (1U)
/*! CHRG_DETECTED - Battery Charging Primary Detection phase output
 *  0b0..Standard Downstream Port (SDP) has been detected
 *  0b1..Charging Port has been detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_CHRG_DETECTED_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE_MASK  (0x4U)
#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE_SHIFT (2U)
/*! DM_STATE - DM_STATE
 *  0b0..DM pin voltage is < 0.8V
 *  0b1..DM pin voltage is > 2.0V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DM_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DM_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DM_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK  (0x8U)
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT (3U)
/*! DP_STATE - DP_STATE
 *  0b0..DP pin voltage is < 0.8V
 *  0b1..DP pin voltage is > 2.0V
 */
#define USBPHY_USB1_CHRG_DET_STAT_DP_STATE(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_DP_STATE_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_DP_STATE_MASK)

#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK (0x10U)
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT (4U)
/*! SECDET_DCP - Battery Charging Secondary Detection phase output
 *  0b0..Charging Downstream Port (CDP) has been detected
 *  0b1..Downstream Charging Port (DCP) has been detected
 */
#define USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_SHIFT)) & USBPHY_USB1_CHRG_DET_STAT_SECDET_DCP_MASK)
/*! @} */

/*! @name ANACTRL - Analog Control */
/*! @{ */

#define USBPHY_ANACTRL_DEV_PULLDOWN_MASK         (0x400U)
#define USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT        (10U)
/*! DEV_PULLDOWN - Device Pull-down */
#define USBPHY_ANACTRL_DEV_PULLDOWN(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_SET - Analog Control Set */
/*! @{ */

#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pull-down
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_ANACTRL_SET_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_SET_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_SET_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_CLR - Analog Control Clear */
/*! @{ */

#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pull-down
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_ANACTRL_CLR_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_CLR_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_CLR_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name ANACTRL_TOG - Analog Control Toggle */
/*! @{ */

#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK     (0x400U)
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT    (10U)
/*! DEV_PULLDOWN - Device Pull-down
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_ANACTRL_TOG_DEV_PULLDOWN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_ANACTRL_TOG_DEV_PULLDOWN_SHIFT)) & USBPHY_ANACTRL_TOG_DEV_PULLDOWN_MASK)
/*! @} */

/*! @name USB1_LOOPBACK - USB PHY Loopback Control/Status */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - USB loopback test. */
#define USBPHY_USB1_LOOPBACK_UTMI_TESTSTART(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_MASK  (0x2U)
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - Mode control for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_MASK  (0x4U)
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - Mode control for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Select HS or FS mode for USB loopback testing. */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Select HS or FS mode for USB loopback testing. */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN_MASK     (0x20U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN_SHIFT    (5U)
/*! TSTI_TX_EN - Enable TX for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_EN(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_MASK    (0x40U)
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_SHIFT   (6U)
/*! TSTI_TX_HIZ - Sets TX Hi-Z for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_MASK  (0x80U)
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - Status bit for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_MASK  (0x100U)
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - Status bit for USB loopback test. */
#define USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_SHIFT (15U)
#define USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TSTPKT_MASK         (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_TSTPKT_SHIFT        (16U)
/*! TSTPKT - Test packet */
#define USBPHY_USB1_LOOPBACK_TSTPKT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_SET - USB PHY Loopback Control/Status Set */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Select HS or FS mode for USB loopback testing. */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Select HS or FS mode for USB loopback testing.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Enable TX for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Sets TX Hi-Z for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - TSTI_HSFS_MODE_EN
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_SET_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_SET_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Test packet
 *  0b00000000..No effect
 *  0b00000001..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_SET_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_SET_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_SET_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_CLR - USB PHY Loopback Control/Status Clear */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Select HS or FS mode for USB loopback testing. */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Select HS or FS mode for USB loopback testing.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Enable TX for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Sets TX Hi-Z for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - TSTI_HSFS_MODE_EN
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Test packet
 *  0b00000000..No effect
 *  0b00000001..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_CLR_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_CLR_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_CLR_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_TOG - USB PHY Loopback Control/Status Toggle */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_MASK (0x1U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT (0U)
/*! UTMI_TESTSTART - USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_TESTSTART_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_MASK (0x2U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_SHIFT (1U)
/*! UTMI_DIG_TST0 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_MASK (0x4U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_SHIFT (2U)
/*! UTMI_DIG_TST1 - Mode control for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMI_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_MASK (0x8U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_SHIFT (3U)
/*! TSTI_TX_HS_MODE - Select HS or FS mode for USB loopback testing. */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_MASK (0x10U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_SHIFT (4U)
/*! TSTI_TX_LS_MODE - Select HS or FS mode for USB loopback testing.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_LS_MODE_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_MASK (0x20U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_SHIFT (5U)
/*! TSTI_TX_EN - Enable TX for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_MASK (0x40U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_SHIFT (6U)
/*! TSTI_TX_HIZ - Sets TX Hi-Z for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_TX_HIZ_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_MASK (0x80U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_SHIFT (7U)
/*! UTMO_DIG_TST0 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST0_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_MASK (0x100U)
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_SHIFT (8U)
/*! UTMO_DIG_TST1 - Status bit for USB loopback test.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_UTMO_DIG_TST1_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_MASK (0x8000U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_SHIFT (15U)
/*! TSTI_HSFS_MODE_EN - TSTI_HSFS_MODE_EN
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTI_HSFS_MODE_EN_MASK)

#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT_MASK     (0xFF0000U)
#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT_SHIFT    (16U)
/*! TSTPKT - Test packet
 *  0b00000000..No effect
 *  0b00000001..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_TOG_TSTPKT(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_TOG_TSTPKT_SHIFT)) & USBPHY_USB1_LOOPBACK_TOG_TSTPKT_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT - Loopback Packet Number Select */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - USB loopback test HS CNT. */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - USB loopback test FS CNT. */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_SET - USB PHY Loopback Packet Number Select Set */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - USB loopback test HS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - USB loopback test FS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Sets the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_SET_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_CLR - USB PHY Loopback Packet Number Select Clear */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - USB loopback test HS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - USB loopback test FS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Clears the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_CLR_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name USB1_LOOPBACK_HSFSCNT_TOG - USB PHY Loopback Packet Number Select Toggle */
/*! @{ */

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_MASK (0xFFFFU)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_SHIFT (0U)
/*! TSTI_HS_NUMBER - USB loopback test HS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_HS_NUMBER_MASK)

#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_MASK (0xFFFF0000U)
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_SHIFT (16U)
/*! TSTI_FS_NUMBER - USB loopback test FS CNT.
 *  0b0000000000000000..No effect
 *  0b0000000000000001..Toggles the corresponding bit
 */
#define USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_SHIFT)) & USBPHY_USB1_LOOPBACK_HSFSCNT_TOG_TSTI_FS_NUMBER_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN - Trim Override Enable */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - DIV_SEL_OVERRIDE */
#define USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! ENV_TAIL_ADJ_VD_OVERRIDE - ENV_TAIL_ADJ_VD_OVERRIDE */
#define USBPHY_TRIM_OVERRIDE_EN_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - TX_D_CAL_OVERRIDE */
#define USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - TX_CAL45DP_OVERRIDE */
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - TX_CAL45DM_OVERRIDE */
#define USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! REFBIAS_VBGADJ_OVERRIDE - Override enable for bandgap adjustment. */
#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! REFBIAS_TST_OVERRIDE - Override enable for bias current control. */
#define USBPHY_TRIM_OVERRIDE_EN_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! USB2_REFBIAS_VBGADJ - Adjustment bits for bandgap */
#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_TST_SHIFT (13U)
/*! USB2_REFBIAS_TST - Bias current control for usb2_phy and usb_PLL */
#define USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - Default value of PLL_DIV_SEL. */
#define USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! USB_REG_ENV_TAIL_ADJ_VD - Default value of ENV_TAIL_ADJ. */
#define USBPHY_TRIM_OVERRIDE_EN_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - Default value of TX_D_CAL. */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - Default value of TX_CAL45DP. */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - Default value of TX_CAL45DM. */
#define USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_SET - Trim Set */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - DIV_SEL_OVERRIDE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! ENV_TAIL_ADJ_VD_OVERRIDE - ENV_TAIL_ADJ_VD_OVERRIDE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - TX_D_CAL_OVERRIDE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - TX_CAL45DP_OVERRIDE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - TX_CAL45DM_OVERRIDE
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! REFBIAS_VBGADJ_OVERRIDE - Override enable for bandgap adjustment.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! REFBIAS_TST_OVERRIDE - Override enable for bias current control.
 *  0b0..No effect
 *  0b1..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! USB2_REFBIAS_VBGADJ - Adjustment bits for bandgap
 *  0b000..No effect
 *  0b001..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_TST_SHIFT (13U)
/*! USB2_REFBIAS_TST - Bias current control for usb2_phy and usb_PLL
 *  0b00..No effect
 *  0b01..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - Default value of PLL_DIV_SEL.
 *  0b000..No effect
 *  0b001..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! USB_REG_ENV_TAIL_ADJ_VD - Default value of ENV_TAIL_ADJ.
 *  0b00..No effect
 *  0b01..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - Default value of TX_D_CAL.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - Default value of TX_CAL45DP.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - Default value of TX_CAL45DM.
 *  0b0000..No effect
 *  0b0001..Sets the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_SET_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_CLR - Trim Clear */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - DIV_SEL_OVERRIDE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! ENV_TAIL_ADJ_VD_OVERRIDE - ENV_TAIL_ADJ_VD_OVERRIDE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - TX_D_CAL_OVERRIDE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - TX_CAL45DP_OVERRIDE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - TX_CAL45DM_OVERRIDE
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! REFBIAS_VBGADJ_OVERRIDE - Override enable for bandgap adjustment.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! REFBIAS_TST_OVERRIDE - Override enable for bias current control.
 *  0b0..No effect
 *  0b1..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! USB2_REFBIAS_VBGADJ - Adjustment bits for bandgap
 *  0b000..No effect
 *  0b001..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_TST_SHIFT (13U)
/*! USB2_REFBIAS_TST - Bias current control for usb2_phy and usb_PLL
 *  0b00..No effect
 *  0b01..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - Default value of PLL_DIV_SEL.
 *  0b000..No effect
 *  0b001..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! USB_REG_ENV_TAIL_ADJ_VD - Default value of ENV_TAIL_ADJ.
 *  0b00..No effect
 *  0b01..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - Default value of TX_D_CAL.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - Default value of TX_CAL45DP.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - Default value of TX_CAL45DM.
 *  0b0000..No effect
 *  0b0001..Clears the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_CLR_USBPHY_TX_CAL45DN_MASK)
/*! @} */

/*! @name TRIM_OVERRIDE_EN_TOG - Trim Toggle */
/*! @{ */

#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_MASK (0x1U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_SHIFT (0U)
/*! DIV_SEL_OVERRIDE - DIV_SEL_OVERRIDE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_DIV_SEL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_ENV_TAIL_ADJ_VD_OVERRIDE_MASK (0x2U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT (1U)
/*! ENV_TAIL_ADJ_VD_OVERRIDE - ENV_TAIL_ADJ_VD_OVERRIDE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_ENV_TAIL_ADJ_VD_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_ENV_TAIL_ADJ_VD_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_ENV_TAIL_ADJ_VD_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_MASK (0x4U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_SHIFT (2U)
/*! TX_D_CAL_OVERRIDE - TX_D_CAL_OVERRIDE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_D_CAL_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_MASK (0x8U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_SHIFT (3U)
/*! TX_CAL45DP_OVERRIDE - TX_CAL45DP_OVERRIDE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DP_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_MASK (0x10U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_SHIFT (4U)
/*! TX_CAL45DM_OVERRIDE - TX_CAL45DM_OVERRIDE
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_TX_CAL45DM_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_VBGADJ_OVERRIDE_MASK (0x20U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_VBGADJ_OVERRIDE_SHIFT (5U)
/*! REFBIAS_VBGADJ_OVERRIDE - Override enable for bandgap adjustment.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_VBGADJ_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_VBGADJ_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_VBGADJ_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_TST_OVERRIDE_MASK (0x40U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_TST_OVERRIDE_SHIFT (6U)
/*! REFBIAS_TST_OVERRIDE - Override enable for bias current control.
 *  0b0..No effect
 *  0b1..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_TST_OVERRIDE(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_TST_OVERRIDE_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_REFBIAS_TST_OVERRIDE_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_VBGADJ_MASK (0x1C00U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_VBGADJ_SHIFT (10U)
/*! USB2_REFBIAS_VBGADJ - Adjustment bits for bandgap
 *  0b000..No effect
 *  0b001..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_VBGADJ(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_VBGADJ_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_VBGADJ_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_TST_MASK (0x6000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_TST_SHIFT (13U)
/*! USB2_REFBIAS_TST - Bias current control for usb2_phy and usb_PLL
 *  0b00..No effect
 *  0b01..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_TST(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_TST_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USB2_REFBIAS_TST_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_MASK (0x38000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_SHIFT (15U)
/*! PLL_CTRL0_DIV_SEL - Default value of PLL_DIV_SEL.
 *  0b000..No effect
 *  0b001..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_PLL_CTRL0_DIV_SEL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB_REG_ENV_TAIL_ADJ_VD_MASK (0xC0000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB_REG_ENV_TAIL_ADJ_VD_SHIFT (18U)
/*! USB_REG_ENV_TAIL_ADJ_VD - Default value of ENV_TAIL_ADJ.
 *  0b00..No effect
 *  0b01..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USB_REG_ENV_TAIL_ADJ_VD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USB_REG_ENV_TAIL_ADJ_VD_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USB_REG_ENV_TAIL_ADJ_VD_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_MASK (0xF00000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_SHIFT (20U)
/*! USBPHY_TX_D_CAL - Default value of TX_D_CAL.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_D_CAL_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_MASK (0xF000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_SHIFT (24U)
/*! USBPHY_TX_CAL45DP - Default value of TX_CAL45DP.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DP_MASK)

#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_MASK (0xF0000000U)
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_SHIFT (28U)
/*! USBPHY_TX_CAL45DN - Default value of TX_CAL45DM.
 *  0b0000..No effect
 *  0b0001..Toggles the corresponding bit
 */
#define USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_SHIFT)) & USBPHY_TRIM_OVERRIDE_EN_TOG_USBPHY_TX_CAL45DN_MASK)
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

