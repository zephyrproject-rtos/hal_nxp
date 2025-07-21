/*
** ###################################################################
**     Processors:          MIMXRT1061CVJ5A
**                          MIMXRT1061CVJ5B
**                          MIMXRT1061CVL5A
**                          MIMXRT1061CVL5B
**                          MIMXRT1061DVJ6A
**                          MIMXRT1061DVJ6B
**                          MIMXRT1061DVL6A
**                          MIMXRT1061DVL6B
**                          MIMXRT1061XVN5B
**                          MIMXRT1062CVJ5A
**                          MIMXRT1062CVJ5B
**                          MIMXRT1062CVL5A
**                          MIMXRT1062CVL5B
**                          MIMXRT1062DVJ6A
**                          MIMXRT1062DVJ6B
**                          MIMXRT1062DVL6A
**                          MIMXRT1062DVL6B
**                          MIMXRT1062DVN6B
**                          MIMXRT1062XVN5B
**                          MIMXRT106ADVL6A
**                          MIMXRT106CDVL6A
**                          MIMXRT106FDVL6A
**                          MIMXRT106LDVL6A
**                          MIMXRT106SDVL6A
**
**     Version:             rev. 2.0, 2024-10-29
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
**     - rev. 0.1 (2017-01-10)
**         Initial version.
**     - rev. 1.0 (2018-11-16)
**         Update header files to align with IMXRT1060RM Rev.0.
**     - rev. 1.1 (2018-11-27)
**         Update header files to align with IMXRT1060RM Rev.1.
**     - rev. 1.2 (2019-04-29)
**         Add SET/CLR/TOG register group to register CTRL, STAT, CHANNELCTRL, CH0STAT, CH0OPTS, CH1STAT, CH1OPTS, CH2STAT, CH2OPTS, CH3STAT, CH3OPTS of DCP module.
**     - rev. 1.3 (2021-08-10)
**         Update header files to align with IMXRT1060RM Rev.3.
**     - rev. 1.4 (2022-03-25)
**         Add RT1060X device
**     - rev. 2.0 (2024-10-29)
**         Change the device header file from single flat file to multiple files based on peripherals,
**         each peripheral with dedicated header file located in periphN folder.
**
** ###################################################################
*/

/*!
 * @file PERI_USBPHY.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for USBPHY
 *
 * CMSIS Peripheral Access Layer for USBPHY
 */

#if !defined(PERI_USBPHY_H_)
#define PERI_USBPHY_H_                           /**< Symbol preventing repeated inclusion */

#if (defined(CPU_MIMXRT1061CVJ5A) || defined(CPU_MIMXRT1061CVJ5B) || defined(CPU_MIMXRT1061CVL5A) || defined(CPU_MIMXRT1061CVL5B) || defined(CPU_MIMXRT1061DVJ6A) || defined(CPU_MIMXRT1061DVJ6B) || defined(CPU_MIMXRT1061DVL6A) || defined(CPU_MIMXRT1061DVL6B) || defined(CPU_MIMXRT1061XVN5B))
#include "MIMXRT1061_COMMON.h"
#elif (defined(CPU_MIMXRT1062CVJ5A) || defined(CPU_MIMXRT1062CVJ5B) || defined(CPU_MIMXRT1062CVL5A) || defined(CPU_MIMXRT1062CVL5B) || defined(CPU_MIMXRT1062DVJ6A) || defined(CPU_MIMXRT1062DVJ6B) || defined(CPU_MIMXRT1062DVL6A) || defined(CPU_MIMXRT1062DVL6B) || defined(CPU_MIMXRT1062DVN6B) || defined(CPU_MIMXRT1062XVN5B))
#include "MIMXRT1062_COMMON.h"
#elif (defined(CPU_MIMXRT106ADVL6A))
#include "MIMXRT106A_COMMON.h"
#elif (defined(CPU_MIMXRT106CDVL6A))
#include "MIMXRT106C_COMMON.h"
#elif (defined(CPU_MIMXRT106FDVL6A))
#include "MIMXRT106F_COMMON.h"
#elif (defined(CPU_MIMXRT106LDVL6A))
#include "MIMXRT106L_COMMON.h"
#elif (defined(CPU_MIMXRT106SDVL6A))
#include "MIMXRT106S_COMMON.h"
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
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
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
  __IO uint32_t PWD;                               /**< USB PHY Power-Down Register, offset: 0x0 */
  __IO uint32_t PWD_SET;                           /**< USB PHY Power-Down Register, offset: 0x4 */
  __IO uint32_t PWD_CLR;                           /**< USB PHY Power-Down Register, offset: 0x8 */
  __IO uint32_t PWD_TOG;                           /**< USB PHY Power-Down Register, offset: 0xC */
  __IO uint32_t TX;                                /**< USB PHY Transmitter Control Register, offset: 0x10 */
  __IO uint32_t TX_SET;                            /**< USB PHY Transmitter Control Register, offset: 0x14 */
  __IO uint32_t TX_CLR;                            /**< USB PHY Transmitter Control Register, offset: 0x18 */
  __IO uint32_t TX_TOG;                            /**< USB PHY Transmitter Control Register, offset: 0x1C */
  __IO uint32_t RX;                                /**< USB PHY Receiver Control Register, offset: 0x20 */
  __IO uint32_t RX_SET;                            /**< USB PHY Receiver Control Register, offset: 0x24 */
  __IO uint32_t RX_CLR;                            /**< USB PHY Receiver Control Register, offset: 0x28 */
  __IO uint32_t RX_TOG;                            /**< USB PHY Receiver Control Register, offset: 0x2C */
  __IO uint32_t CTRL;                              /**< USB PHY General Control Register, offset: 0x30 */
  __IO uint32_t CTRL_SET;                          /**< USB PHY General Control Register, offset: 0x34 */
  __IO uint32_t CTRL_CLR;                          /**< USB PHY General Control Register, offset: 0x38 */
  __IO uint32_t CTRL_TOG;                          /**< USB PHY General Control Register, offset: 0x3C */
  __IO uint32_t STATUS;                            /**< USB PHY Status Register, offset: 0x40 */
       uint8_t RESERVED_0[12];
  __IO uint32_t DEBUGr;                            /**< USB PHY Debug Register, offset: 0x50, 'r' suffix has been added to avoid clash with DEBUG symbolic constant */
  __IO uint32_t DEBUG_SET;                         /**< USB PHY Debug Register, offset: 0x54 */
  __IO uint32_t DEBUG_CLR;                         /**< USB PHY Debug Register, offset: 0x58 */
  __IO uint32_t DEBUG_TOG;                         /**< USB PHY Debug Register, offset: 0x5C */
  __I  uint32_t DEBUG0_STATUS;                     /**< UTMI Debug Status Register 0, offset: 0x60 */
       uint8_t RESERVED_1[12];
  __IO uint32_t DEBUG1;                            /**< UTMI Debug Status Register 1, offset: 0x70 */
  __IO uint32_t DEBUG1_SET;                        /**< UTMI Debug Status Register 1, offset: 0x74 */
  __IO uint32_t DEBUG1_CLR;                        /**< UTMI Debug Status Register 1, offset: 0x78 */
  __IO uint32_t DEBUG1_TOG;                        /**< UTMI Debug Status Register 1, offset: 0x7C */
  __I  uint32_t VERSION;                           /**< UTMI RTL Version, offset: 0x80 */
} USBPHY_Type;

/* ----------------------------------------------------------------------------
   -- USBPHY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USBPHY_Register_Masks USBPHY Register Masks
 * @{
 */

/*! @name PWD - USB PHY Power-Down Register */
/*! @{ */

#define USBPHY_PWD_RSVD0_MASK                    (0x3FFU)
#define USBPHY_PWD_RSVD0_SHIFT                   (0U)
#define USBPHY_PWD_RSVD0(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RSVD0_SHIFT)) & USBPHY_PWD_RSVD0_MASK)

#define USBPHY_PWD_TXPWDFS_MASK                  (0x400U)
#define USBPHY_PWD_TXPWDFS_SHIFT                 (10U)
#define USBPHY_PWD_TXPWDFS(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDFS_SHIFT)) & USBPHY_PWD_TXPWDFS_MASK)

#define USBPHY_PWD_TXPWDIBIAS_MASK               (0x800U)
#define USBPHY_PWD_TXPWDIBIAS_SHIFT              (11U)
#define USBPHY_PWD_TXPWDIBIAS(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TXPWDV2I_MASK                 (0x1000U)
#define USBPHY_PWD_TXPWDV2I_SHIFT                (12U)
#define USBPHY_PWD_TXPWDV2I(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TXPWDV2I_SHIFT)) & USBPHY_PWD_TXPWDV2I_MASK)

#define USBPHY_PWD_RSVD1_MASK                    (0x1E000U)
#define USBPHY_PWD_RSVD1_SHIFT                   (13U)
#define USBPHY_PWD_RSVD1(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RSVD1_SHIFT)) & USBPHY_PWD_RSVD1_MASK)

#define USBPHY_PWD_RXPWDENV_MASK                 (0x20000U)
#define USBPHY_PWD_RXPWDENV_SHIFT                (17U)
#define USBPHY_PWD_RXPWDENV(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDENV_SHIFT)) & USBPHY_PWD_RXPWDENV_MASK)

#define USBPHY_PWD_RXPWD1PT1_MASK                (0x40000U)
#define USBPHY_PWD_RXPWD1PT1_SHIFT               (18U)
#define USBPHY_PWD_RXPWD1PT1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWD1PT1_SHIFT)) & USBPHY_PWD_RXPWD1PT1_MASK)

#define USBPHY_PWD_RXPWDDIFF_MASK                (0x80000U)
#define USBPHY_PWD_RXPWDDIFF_SHIFT               (19U)
#define USBPHY_PWD_RXPWDDIFF(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDDIFF_SHIFT)) & USBPHY_PWD_RXPWDDIFF_MASK)

#define USBPHY_PWD_RXPWDRX_MASK                  (0x100000U)
#define USBPHY_PWD_RXPWDRX_SHIFT                 (20U)
#define USBPHY_PWD_RXPWDRX(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RXPWDRX_SHIFT)) & USBPHY_PWD_RXPWDRX_MASK)

#define USBPHY_PWD_RSVD2_MASK                    (0xFFE00000U)
#define USBPHY_PWD_RSVD2_SHIFT                   (21U)
#define USBPHY_PWD_RSVD2(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_RSVD2_SHIFT)) & USBPHY_PWD_RSVD2_MASK)
/*! @} */

/*! @name PWD_SET - USB PHY Power-Down Register */
/*! @{ */

#define USBPHY_PWD_SET_RSVD0_MASK                (0x3FFU)
#define USBPHY_PWD_SET_RSVD0_SHIFT               (0U)
#define USBPHY_PWD_SET_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RSVD0_SHIFT)) & USBPHY_PWD_SET_RSVD0_MASK)

#define USBPHY_PWD_SET_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_SET_TXPWDFS_SHIFT             (10U)
#define USBPHY_PWD_SET_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDFS_SHIFT)) & USBPHY_PWD_SET_TXPWDFS_MASK)

#define USBPHY_PWD_SET_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_SET_TXPWDIBIAS_SHIFT          (11U)
#define USBPHY_PWD_SET_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_SET_TXPWDIBIAS_MASK)

#define USBPHY_PWD_SET_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_SET_TXPWDV2I_SHIFT            (12U)
#define USBPHY_PWD_SET_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_TXPWDV2I_SHIFT)) & USBPHY_PWD_SET_TXPWDV2I_MASK)

#define USBPHY_PWD_SET_RSVD1_MASK                (0x1E000U)
#define USBPHY_PWD_SET_RSVD1_SHIFT               (13U)
#define USBPHY_PWD_SET_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RSVD1_SHIFT)) & USBPHY_PWD_SET_RSVD1_MASK)

#define USBPHY_PWD_SET_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_SET_RXPWDENV_SHIFT            (17U)
#define USBPHY_PWD_SET_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDENV_SHIFT)) & USBPHY_PWD_SET_RXPWDENV_MASK)

#define USBPHY_PWD_SET_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_SET_RXPWD1PT1_SHIFT           (18U)
#define USBPHY_PWD_SET_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWD1PT1_SHIFT)) & USBPHY_PWD_SET_RXPWD1PT1_MASK)

#define USBPHY_PWD_SET_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_SET_RXPWDDIFF_SHIFT           (19U)
#define USBPHY_PWD_SET_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDDIFF_SHIFT)) & USBPHY_PWD_SET_RXPWDDIFF_MASK)

#define USBPHY_PWD_SET_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_SET_RXPWDRX_SHIFT             (20U)
#define USBPHY_PWD_SET_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RXPWDRX_SHIFT)) & USBPHY_PWD_SET_RXPWDRX_MASK)

#define USBPHY_PWD_SET_RSVD2_MASK                (0xFFE00000U)
#define USBPHY_PWD_SET_RSVD2_SHIFT               (21U)
#define USBPHY_PWD_SET_RSVD2(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_SET_RSVD2_SHIFT)) & USBPHY_PWD_SET_RSVD2_MASK)
/*! @} */

/*! @name PWD_CLR - USB PHY Power-Down Register */
/*! @{ */

#define USBPHY_PWD_CLR_RSVD0_MASK                (0x3FFU)
#define USBPHY_PWD_CLR_RSVD0_SHIFT               (0U)
#define USBPHY_PWD_CLR_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RSVD0_SHIFT)) & USBPHY_PWD_CLR_RSVD0_MASK)

#define USBPHY_PWD_CLR_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_CLR_TXPWDFS_SHIFT             (10U)
#define USBPHY_PWD_CLR_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDFS_SHIFT)) & USBPHY_PWD_CLR_TXPWDFS_MASK)

#define USBPHY_PWD_CLR_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT          (11U)
#define USBPHY_PWD_CLR_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_CLR_TXPWDIBIAS_MASK)

#define USBPHY_PWD_CLR_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_CLR_TXPWDV2I_SHIFT            (12U)
#define USBPHY_PWD_CLR_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_TXPWDV2I_SHIFT)) & USBPHY_PWD_CLR_TXPWDV2I_MASK)

#define USBPHY_PWD_CLR_RSVD1_MASK                (0x1E000U)
#define USBPHY_PWD_CLR_RSVD1_SHIFT               (13U)
#define USBPHY_PWD_CLR_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RSVD1_SHIFT)) & USBPHY_PWD_CLR_RSVD1_MASK)

#define USBPHY_PWD_CLR_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_CLR_RXPWDENV_SHIFT            (17U)
#define USBPHY_PWD_CLR_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDENV_SHIFT)) & USBPHY_PWD_CLR_RXPWDENV_MASK)

#define USBPHY_PWD_CLR_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_CLR_RXPWD1PT1_SHIFT           (18U)
#define USBPHY_PWD_CLR_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWD1PT1_SHIFT)) & USBPHY_PWD_CLR_RXPWD1PT1_MASK)

#define USBPHY_PWD_CLR_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_CLR_RXPWDDIFF_SHIFT           (19U)
#define USBPHY_PWD_CLR_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDDIFF_SHIFT)) & USBPHY_PWD_CLR_RXPWDDIFF_MASK)

#define USBPHY_PWD_CLR_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_CLR_RXPWDRX_SHIFT             (20U)
#define USBPHY_PWD_CLR_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RXPWDRX_SHIFT)) & USBPHY_PWD_CLR_RXPWDRX_MASK)

#define USBPHY_PWD_CLR_RSVD2_MASK                (0xFFE00000U)
#define USBPHY_PWD_CLR_RSVD2_SHIFT               (21U)
#define USBPHY_PWD_CLR_RSVD2(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_CLR_RSVD2_SHIFT)) & USBPHY_PWD_CLR_RSVD2_MASK)
/*! @} */

/*! @name PWD_TOG - USB PHY Power-Down Register */
/*! @{ */

#define USBPHY_PWD_TOG_RSVD0_MASK                (0x3FFU)
#define USBPHY_PWD_TOG_RSVD0_SHIFT               (0U)
#define USBPHY_PWD_TOG_RSVD0(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RSVD0_SHIFT)) & USBPHY_PWD_TOG_RSVD0_MASK)

#define USBPHY_PWD_TOG_TXPWDFS_MASK              (0x400U)
#define USBPHY_PWD_TOG_TXPWDFS_SHIFT             (10U)
#define USBPHY_PWD_TOG_TXPWDFS(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDFS_SHIFT)) & USBPHY_PWD_TOG_TXPWDFS_MASK)

#define USBPHY_PWD_TOG_TXPWDIBIAS_MASK           (0x800U)
#define USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT          (11U)
#define USBPHY_PWD_TOG_TXPWDIBIAS(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDIBIAS_SHIFT)) & USBPHY_PWD_TOG_TXPWDIBIAS_MASK)

#define USBPHY_PWD_TOG_TXPWDV2I_MASK             (0x1000U)
#define USBPHY_PWD_TOG_TXPWDV2I_SHIFT            (12U)
#define USBPHY_PWD_TOG_TXPWDV2I(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_TXPWDV2I_SHIFT)) & USBPHY_PWD_TOG_TXPWDV2I_MASK)

#define USBPHY_PWD_TOG_RSVD1_MASK                (0x1E000U)
#define USBPHY_PWD_TOG_RSVD1_SHIFT               (13U)
#define USBPHY_PWD_TOG_RSVD1(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RSVD1_SHIFT)) & USBPHY_PWD_TOG_RSVD1_MASK)

#define USBPHY_PWD_TOG_RXPWDENV_MASK             (0x20000U)
#define USBPHY_PWD_TOG_RXPWDENV_SHIFT            (17U)
#define USBPHY_PWD_TOG_RXPWDENV(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDENV_SHIFT)) & USBPHY_PWD_TOG_RXPWDENV_MASK)

#define USBPHY_PWD_TOG_RXPWD1PT1_MASK            (0x40000U)
#define USBPHY_PWD_TOG_RXPWD1PT1_SHIFT           (18U)
#define USBPHY_PWD_TOG_RXPWD1PT1(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWD1PT1_SHIFT)) & USBPHY_PWD_TOG_RXPWD1PT1_MASK)

#define USBPHY_PWD_TOG_RXPWDDIFF_MASK            (0x80000U)
#define USBPHY_PWD_TOG_RXPWDDIFF_SHIFT           (19U)
#define USBPHY_PWD_TOG_RXPWDDIFF(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDDIFF_SHIFT)) & USBPHY_PWD_TOG_RXPWDDIFF_MASK)

#define USBPHY_PWD_TOG_RXPWDRX_MASK              (0x100000U)
#define USBPHY_PWD_TOG_RXPWDRX_SHIFT             (20U)
#define USBPHY_PWD_TOG_RXPWDRX(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RXPWDRX_SHIFT)) & USBPHY_PWD_TOG_RXPWDRX_MASK)

#define USBPHY_PWD_TOG_RSVD2_MASK                (0xFFE00000U)
#define USBPHY_PWD_TOG_RSVD2_SHIFT               (21U)
#define USBPHY_PWD_TOG_RSVD2(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_PWD_TOG_RSVD2_SHIFT)) & USBPHY_PWD_TOG_RSVD2_MASK)
/*! @} */

/*! @name TX - USB PHY Transmitter Control Register */
/*! @{ */

#define USBPHY_TX_D_CAL_MASK                     (0xFU)
#define USBPHY_TX_D_CAL_SHIFT                    (0U)
#define USBPHY_TX_D_CAL(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_D_CAL_SHIFT)) & USBPHY_TX_D_CAL_MASK)

#define USBPHY_TX_RSVD0_MASK                     (0xF0U)
#define USBPHY_TX_RSVD0_SHIFT                    (4U)
#define USBPHY_TX_RSVD0(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_RSVD0_SHIFT)) & USBPHY_TX_RSVD0_MASK)

#define USBPHY_TX_TXCAL45DN_MASK                 (0xF00U)
#define USBPHY_TX_TXCAL45DN_SHIFT                (8U)
#define USBPHY_TX_TXCAL45DN(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DN_SHIFT)) & USBPHY_TX_TXCAL45DN_MASK)

#define USBPHY_TX_RSVD1_MASK                     (0xF000U)
#define USBPHY_TX_RSVD1_SHIFT                    (12U)
#define USBPHY_TX_RSVD1(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_RSVD1_SHIFT)) & USBPHY_TX_RSVD1_MASK)

#define USBPHY_TX_TXCAL45DP_MASK                 (0xF0000U)
#define USBPHY_TX_TXCAL45DP_SHIFT                (16U)
#define USBPHY_TX_TXCAL45DP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TXCAL45DP_SHIFT)) & USBPHY_TX_TXCAL45DP_MASK)

#define USBPHY_TX_RSVD2_MASK                     (0x3F00000U)
#define USBPHY_TX_RSVD2_SHIFT                    (20U)
#define USBPHY_TX_RSVD2(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_RSVD2_SHIFT)) & USBPHY_TX_RSVD2_MASK)

#define USBPHY_TX_USBPHY_TX_EDGECTRL_MASK        (0x1C000000U)
#define USBPHY_TX_USBPHY_TX_EDGECTRL_SHIFT       (26U)
#define USBPHY_TX_USBPHY_TX_EDGECTRL(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_USBPHY_TX_EDGECTRL_SHIFT)) & USBPHY_TX_USBPHY_TX_EDGECTRL_MASK)

#define USBPHY_TX_RSVD5_MASK                     (0xE0000000U)
#define USBPHY_TX_RSVD5_SHIFT                    (29U)
#define USBPHY_TX_RSVD5(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_RSVD5_SHIFT)) & USBPHY_TX_RSVD5_MASK)
/*! @} */

/*! @name TX_SET - USB PHY Transmitter Control Register */
/*! @{ */

#define USBPHY_TX_SET_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_SET_D_CAL_SHIFT                (0U)
#define USBPHY_TX_SET_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_D_CAL_SHIFT)) & USBPHY_TX_SET_D_CAL_MASK)

#define USBPHY_TX_SET_RSVD0_MASK                 (0xF0U)
#define USBPHY_TX_SET_RSVD0_SHIFT                (4U)
#define USBPHY_TX_SET_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_RSVD0_SHIFT)) & USBPHY_TX_SET_RSVD0_MASK)

#define USBPHY_TX_SET_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_SET_TXCAL45DN_SHIFT            (8U)
#define USBPHY_TX_SET_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DN_SHIFT)) & USBPHY_TX_SET_TXCAL45DN_MASK)

#define USBPHY_TX_SET_RSVD1_MASK                 (0xF000U)
#define USBPHY_TX_SET_RSVD1_SHIFT                (12U)
#define USBPHY_TX_SET_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_RSVD1_SHIFT)) & USBPHY_TX_SET_RSVD1_MASK)

#define USBPHY_TX_SET_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_SET_TXCAL45DP_SHIFT            (16U)
#define USBPHY_TX_SET_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_TXCAL45DP_SHIFT)) & USBPHY_TX_SET_TXCAL45DP_MASK)

#define USBPHY_TX_SET_RSVD2_MASK                 (0x3F00000U)
#define USBPHY_TX_SET_RSVD2_SHIFT                (20U)
#define USBPHY_TX_SET_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_RSVD2_SHIFT)) & USBPHY_TX_SET_RSVD2_MASK)

#define USBPHY_TX_SET_USBPHY_TX_EDGECTRL_MASK    (0x1C000000U)
#define USBPHY_TX_SET_USBPHY_TX_EDGECTRL_SHIFT   (26U)
#define USBPHY_TX_SET_USBPHY_TX_EDGECTRL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_USBPHY_TX_EDGECTRL_SHIFT)) & USBPHY_TX_SET_USBPHY_TX_EDGECTRL_MASK)

#define USBPHY_TX_SET_RSVD5_MASK                 (0xE0000000U)
#define USBPHY_TX_SET_RSVD5_SHIFT                (29U)
#define USBPHY_TX_SET_RSVD5(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_SET_RSVD5_SHIFT)) & USBPHY_TX_SET_RSVD5_MASK)
/*! @} */

/*! @name TX_CLR - USB PHY Transmitter Control Register */
/*! @{ */

#define USBPHY_TX_CLR_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_CLR_D_CAL_SHIFT                (0U)
#define USBPHY_TX_CLR_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_D_CAL_SHIFT)) & USBPHY_TX_CLR_D_CAL_MASK)

#define USBPHY_TX_CLR_RSVD0_MASK                 (0xF0U)
#define USBPHY_TX_CLR_RSVD0_SHIFT                (4U)
#define USBPHY_TX_CLR_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_RSVD0_SHIFT)) & USBPHY_TX_CLR_RSVD0_MASK)

#define USBPHY_TX_CLR_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_CLR_TXCAL45DN_SHIFT            (8U)
#define USBPHY_TX_CLR_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DN_SHIFT)) & USBPHY_TX_CLR_TXCAL45DN_MASK)

#define USBPHY_TX_CLR_RSVD1_MASK                 (0xF000U)
#define USBPHY_TX_CLR_RSVD1_SHIFT                (12U)
#define USBPHY_TX_CLR_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_RSVD1_SHIFT)) & USBPHY_TX_CLR_RSVD1_MASK)

#define USBPHY_TX_CLR_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_CLR_TXCAL45DP_SHIFT            (16U)
#define USBPHY_TX_CLR_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_TXCAL45DP_SHIFT)) & USBPHY_TX_CLR_TXCAL45DP_MASK)

#define USBPHY_TX_CLR_RSVD2_MASK                 (0x3F00000U)
#define USBPHY_TX_CLR_RSVD2_SHIFT                (20U)
#define USBPHY_TX_CLR_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_RSVD2_SHIFT)) & USBPHY_TX_CLR_RSVD2_MASK)

#define USBPHY_TX_CLR_USBPHY_TX_EDGECTRL_MASK    (0x1C000000U)
#define USBPHY_TX_CLR_USBPHY_TX_EDGECTRL_SHIFT   (26U)
#define USBPHY_TX_CLR_USBPHY_TX_EDGECTRL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_USBPHY_TX_EDGECTRL_SHIFT)) & USBPHY_TX_CLR_USBPHY_TX_EDGECTRL_MASK)

#define USBPHY_TX_CLR_RSVD5_MASK                 (0xE0000000U)
#define USBPHY_TX_CLR_RSVD5_SHIFT                (29U)
#define USBPHY_TX_CLR_RSVD5(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_CLR_RSVD5_SHIFT)) & USBPHY_TX_CLR_RSVD5_MASK)
/*! @} */

/*! @name TX_TOG - USB PHY Transmitter Control Register */
/*! @{ */

#define USBPHY_TX_TOG_D_CAL_MASK                 (0xFU)
#define USBPHY_TX_TOG_D_CAL_SHIFT                (0U)
#define USBPHY_TX_TOG_D_CAL(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_D_CAL_SHIFT)) & USBPHY_TX_TOG_D_CAL_MASK)

#define USBPHY_TX_TOG_RSVD0_MASK                 (0xF0U)
#define USBPHY_TX_TOG_RSVD0_SHIFT                (4U)
#define USBPHY_TX_TOG_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_RSVD0_SHIFT)) & USBPHY_TX_TOG_RSVD0_MASK)

#define USBPHY_TX_TOG_TXCAL45DN_MASK             (0xF00U)
#define USBPHY_TX_TOG_TXCAL45DN_SHIFT            (8U)
#define USBPHY_TX_TOG_TXCAL45DN(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DN_SHIFT)) & USBPHY_TX_TOG_TXCAL45DN_MASK)

#define USBPHY_TX_TOG_RSVD1_MASK                 (0xF000U)
#define USBPHY_TX_TOG_RSVD1_SHIFT                (12U)
#define USBPHY_TX_TOG_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_RSVD1_SHIFT)) & USBPHY_TX_TOG_RSVD1_MASK)

#define USBPHY_TX_TOG_TXCAL45DP_MASK             (0xF0000U)
#define USBPHY_TX_TOG_TXCAL45DP_SHIFT            (16U)
#define USBPHY_TX_TOG_TXCAL45DP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_TXCAL45DP_SHIFT)) & USBPHY_TX_TOG_TXCAL45DP_MASK)

#define USBPHY_TX_TOG_RSVD2_MASK                 (0x3F00000U)
#define USBPHY_TX_TOG_RSVD2_SHIFT                (20U)
#define USBPHY_TX_TOG_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_RSVD2_SHIFT)) & USBPHY_TX_TOG_RSVD2_MASK)

#define USBPHY_TX_TOG_USBPHY_TX_EDGECTRL_MASK    (0x1C000000U)
#define USBPHY_TX_TOG_USBPHY_TX_EDGECTRL_SHIFT   (26U)
#define USBPHY_TX_TOG_USBPHY_TX_EDGECTRL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_USBPHY_TX_EDGECTRL_SHIFT)) & USBPHY_TX_TOG_USBPHY_TX_EDGECTRL_MASK)

#define USBPHY_TX_TOG_RSVD5_MASK                 (0xE0000000U)
#define USBPHY_TX_TOG_RSVD5_SHIFT                (29U)
#define USBPHY_TX_TOG_RSVD5(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_TX_TOG_RSVD5_SHIFT)) & USBPHY_TX_TOG_RSVD5_MASK)
/*! @} */

/*! @name RX - USB PHY Receiver Control Register */
/*! @{ */

#define USBPHY_RX_ENVADJ_MASK                    (0x7U)
#define USBPHY_RX_ENVADJ_SHIFT                   (0U)
#define USBPHY_RX_ENVADJ(x)                      (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_ENVADJ_SHIFT)) & USBPHY_RX_ENVADJ_MASK)

#define USBPHY_RX_RSVD0_MASK                     (0x8U)
#define USBPHY_RX_RSVD0_SHIFT                    (3U)
#define USBPHY_RX_RSVD0(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RSVD0_SHIFT)) & USBPHY_RX_RSVD0_MASK)

#define USBPHY_RX_DISCONADJ_MASK                 (0x70U)
#define USBPHY_RX_DISCONADJ_SHIFT                (4U)
#define USBPHY_RX_DISCONADJ(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_DISCONADJ_SHIFT)) & USBPHY_RX_DISCONADJ_MASK)

#define USBPHY_RX_RSVD1_MASK                     (0x3FFF80U)
#define USBPHY_RX_RSVD1_SHIFT                    (7U)
#define USBPHY_RX_RSVD1(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RSVD1_SHIFT)) & USBPHY_RX_RSVD1_MASK)

#define USBPHY_RX_RXDBYPASS_MASK                 (0x400000U)
#define USBPHY_RX_RXDBYPASS_SHIFT                (22U)
#define USBPHY_RX_RXDBYPASS(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RXDBYPASS_SHIFT)) & USBPHY_RX_RXDBYPASS_MASK)

#define USBPHY_RX_RSVD2_MASK                     (0xFF800000U)
#define USBPHY_RX_RSVD2_SHIFT                    (23U)
#define USBPHY_RX_RSVD2(x)                       (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_RSVD2_SHIFT)) & USBPHY_RX_RSVD2_MASK)
/*! @} */

/*! @name RX_SET - USB PHY Receiver Control Register */
/*! @{ */

#define USBPHY_RX_SET_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_SET_ENVADJ_SHIFT               (0U)
#define USBPHY_RX_SET_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_ENVADJ_SHIFT)) & USBPHY_RX_SET_ENVADJ_MASK)

#define USBPHY_RX_SET_RSVD0_MASK                 (0x8U)
#define USBPHY_RX_SET_RSVD0_SHIFT                (3U)
#define USBPHY_RX_SET_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RSVD0_SHIFT)) & USBPHY_RX_SET_RSVD0_MASK)

#define USBPHY_RX_SET_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_SET_DISCONADJ_SHIFT            (4U)
#define USBPHY_RX_SET_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_DISCONADJ_SHIFT)) & USBPHY_RX_SET_DISCONADJ_MASK)

#define USBPHY_RX_SET_RSVD1_MASK                 (0x3FFF80U)
#define USBPHY_RX_SET_RSVD1_SHIFT                (7U)
#define USBPHY_RX_SET_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RSVD1_SHIFT)) & USBPHY_RX_SET_RSVD1_MASK)

#define USBPHY_RX_SET_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_SET_RXDBYPASS_SHIFT            (22U)
#define USBPHY_RX_SET_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RXDBYPASS_SHIFT)) & USBPHY_RX_SET_RXDBYPASS_MASK)

#define USBPHY_RX_SET_RSVD2_MASK                 (0xFF800000U)
#define USBPHY_RX_SET_RSVD2_SHIFT                (23U)
#define USBPHY_RX_SET_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_SET_RSVD2_SHIFT)) & USBPHY_RX_SET_RSVD2_MASK)
/*! @} */

/*! @name RX_CLR - USB PHY Receiver Control Register */
/*! @{ */

#define USBPHY_RX_CLR_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_CLR_ENVADJ_SHIFT               (0U)
#define USBPHY_RX_CLR_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_ENVADJ_SHIFT)) & USBPHY_RX_CLR_ENVADJ_MASK)

#define USBPHY_RX_CLR_RSVD0_MASK                 (0x8U)
#define USBPHY_RX_CLR_RSVD0_SHIFT                (3U)
#define USBPHY_RX_CLR_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RSVD0_SHIFT)) & USBPHY_RX_CLR_RSVD0_MASK)

#define USBPHY_RX_CLR_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_CLR_DISCONADJ_SHIFT            (4U)
#define USBPHY_RX_CLR_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_DISCONADJ_SHIFT)) & USBPHY_RX_CLR_DISCONADJ_MASK)

#define USBPHY_RX_CLR_RSVD1_MASK                 (0x3FFF80U)
#define USBPHY_RX_CLR_RSVD1_SHIFT                (7U)
#define USBPHY_RX_CLR_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RSVD1_SHIFT)) & USBPHY_RX_CLR_RSVD1_MASK)

#define USBPHY_RX_CLR_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_CLR_RXDBYPASS_SHIFT            (22U)
#define USBPHY_RX_CLR_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RXDBYPASS_SHIFT)) & USBPHY_RX_CLR_RXDBYPASS_MASK)

#define USBPHY_RX_CLR_RSVD2_MASK                 (0xFF800000U)
#define USBPHY_RX_CLR_RSVD2_SHIFT                (23U)
#define USBPHY_RX_CLR_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_CLR_RSVD2_SHIFT)) & USBPHY_RX_CLR_RSVD2_MASK)
/*! @} */

/*! @name RX_TOG - USB PHY Receiver Control Register */
/*! @{ */

#define USBPHY_RX_TOG_ENVADJ_MASK                (0x7U)
#define USBPHY_RX_TOG_ENVADJ_SHIFT               (0U)
#define USBPHY_RX_TOG_ENVADJ(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_ENVADJ_SHIFT)) & USBPHY_RX_TOG_ENVADJ_MASK)

#define USBPHY_RX_TOG_RSVD0_MASK                 (0x8U)
#define USBPHY_RX_TOG_RSVD0_SHIFT                (3U)
#define USBPHY_RX_TOG_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RSVD0_SHIFT)) & USBPHY_RX_TOG_RSVD0_MASK)

#define USBPHY_RX_TOG_DISCONADJ_MASK             (0x70U)
#define USBPHY_RX_TOG_DISCONADJ_SHIFT            (4U)
#define USBPHY_RX_TOG_DISCONADJ(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_DISCONADJ_SHIFT)) & USBPHY_RX_TOG_DISCONADJ_MASK)

#define USBPHY_RX_TOG_RSVD1_MASK                 (0x3FFF80U)
#define USBPHY_RX_TOG_RSVD1_SHIFT                (7U)
#define USBPHY_RX_TOG_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RSVD1_SHIFT)) & USBPHY_RX_TOG_RSVD1_MASK)

#define USBPHY_RX_TOG_RXDBYPASS_MASK             (0x400000U)
#define USBPHY_RX_TOG_RXDBYPASS_SHIFT            (22U)
#define USBPHY_RX_TOG_RXDBYPASS(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RXDBYPASS_SHIFT)) & USBPHY_RX_TOG_RXDBYPASS_MASK)

#define USBPHY_RX_TOG_RSVD2_MASK                 (0xFF800000U)
#define USBPHY_RX_TOG_RSVD2_SHIFT                (23U)
#define USBPHY_RX_TOG_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_RX_TOG_RSVD2_SHIFT)) & USBPHY_RX_TOG_RSVD2_MASK)
/*! @} */

/*! @name CTRL - USB PHY General Control Register */
/*! @{ */

#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK        (0x1U)
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT       (0U)
#define USBPHY_CTRL_ENOTG_ID_CHG_IRQ(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENHOSTDISCONDETECT_MASK      (0x2U)
#define USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT     (1U)
#define USBPHY_CTRL_ENHOSTDISCONDETECT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_ENIRQHOSTDISCON_MASK         (0x4U)
#define USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT        (2U)
#define USBPHY_CTRL_ENIRQHOSTDISCON(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK    (0x8U)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT   (3U)
#define USBPHY_CTRL_HOSTDISCONDETECT_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_ENDEVPLUGINDETECT_MASK       (0x10U)
#define USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT      (4U)
#define USBPHY_CTRL_ENDEVPLUGINDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK      (0x20U)
#define USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT     (5U)
#define USBPHY_CTRL_DEVPLUGIN_POLARITY(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK          (0x40U)
#define USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT         (6U)
#define USBPHY_CTRL_OTG_ID_CHG_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_ENOTGIDDETECT_MASK           (0x80U)
#define USBPHY_CTRL_ENOTGIDDETECT_SHIFT          (7U)
#define USBPHY_CTRL_ENOTGIDDETECT(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_RESUMEIRQSTICKY_MASK         (0x100U)
#define USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT        (8U)
#define USBPHY_CTRL_RESUMEIRQSTICKY(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_ENIRQRESUMEDETECT_MASK       (0x200U)
#define USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT      (9U)
#define USBPHY_CTRL_ENIRQRESUMEDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_RESUME_IRQ_MASK              (0x400U)
#define USBPHY_CTRL_RESUME_IRQ_SHIFT             (10U)
#define USBPHY_CTRL_RESUME_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_RESUME_IRQ_MASK)

#define USBPHY_CTRL_ENIRQDEVPLUGIN_MASK          (0x800U)
#define USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT         (11U)
#define USBPHY_CTRL_ENIRQDEVPLUGIN(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_DEVPLUGIN_IRQ_MASK           (0x1000U)
#define USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT          (12U)
#define USBPHY_CTRL_DEVPLUGIN_IRQ(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_DATA_ON_LRADC_MASK           (0x2000U)
#define USBPHY_CTRL_DATA_ON_LRADC_SHIFT          (13U)
#define USBPHY_CTRL_DATA_ON_LRADC(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_ENUTMILEVEL2_MASK            (0x4000U)
#define USBPHY_CTRL_ENUTMILEVEL2_SHIFT           (14U)
#define USBPHY_CTRL_ENUTMILEVEL2(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_ENUTMILEVEL3_MASK            (0x8000U)
#define USBPHY_CTRL_ENUTMILEVEL3_SHIFT           (15U)
#define USBPHY_CTRL_ENUTMILEVEL3(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_ENIRQWAKEUP_MASK             (0x10000U)
#define USBPHY_CTRL_ENIRQWAKEUP_SHIFT            (16U)
#define USBPHY_CTRL_ENIRQWAKEUP(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_WAKEUP_IRQ_MASK              (0x20000U)
#define USBPHY_CTRL_WAKEUP_IRQ_SHIFT             (17U)
#define USBPHY_CTRL_WAKEUP_IRQ(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_ENAUTO_PWRON_PLL_MASK        (0x40000U)
#define USBPHY_CTRL_ENAUTO_PWRON_PLL_SHIFT       (18U)
#define USBPHY_CTRL_ENAUTO_PWRON_PLL(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTO_PWRON_PLL_SHIFT)) & USBPHY_CTRL_ENAUTO_PWRON_PLL_MASK)

#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK       (0x80000U)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT      (19U)
#define USBPHY_CTRL_ENAUTOCLR_CLKGATE(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK       (0x100000U)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT      (20U)
#define USBPHY_CTRL_ENAUTOCLR_PHY_PWD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_ENDPDMCHG_WKUP_MASK          (0x200000U)
#define USBPHY_CTRL_ENDPDMCHG_WKUP_SHIFT         (21U)
#define USBPHY_CTRL_ENDPDMCHG_WKUP(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENDPDMCHG_WKUP_SHIFT)) & USBPHY_CTRL_ENDPDMCHG_WKUP_MASK)

#define USBPHY_CTRL_ENIDCHG_WKUP_MASK            (0x400000U)
#define USBPHY_CTRL_ENIDCHG_WKUP_SHIFT           (22U)
#define USBPHY_CTRL_ENIDCHG_WKUP(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENIDCHG_WKUP_SHIFT)) & USBPHY_CTRL_ENIDCHG_WKUP_MASK)

#define USBPHY_CTRL_ENVBUSCHG_WKUP_MASK          (0x800000U)
#define USBPHY_CTRL_ENVBUSCHG_WKUP_SHIFT         (23U)
#define USBPHY_CTRL_ENVBUSCHG_WKUP(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_ENVBUSCHG_WKUP_SHIFT)) & USBPHY_CTRL_ENVBUSCHG_WKUP_MASK)

#define USBPHY_CTRL_FSDLL_RST_EN_MASK            (0x1000000U)
#define USBPHY_CTRL_FSDLL_RST_EN_SHIFT           (24U)
#define USBPHY_CTRL_FSDLL_RST_EN(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_RSVD1_MASK                   (0x6000000U)
#define USBPHY_CTRL_RSVD1_SHIFT                  (25U)
#define USBPHY_CTRL_RSVD1(x)                     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_RSVD1_SHIFT)) & USBPHY_CTRL_RSVD1_MASK)

#define USBPHY_CTRL_OTG_ID_VALUE_MASK            (0x8000000U)
#define USBPHY_CTRL_OTG_ID_VALUE_SHIFT           (27U)
#define USBPHY_CTRL_OTG_ID_VALUE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK       (0x10000000U)
#define USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT      (28U)
#define USBPHY_CTRL_HOST_FORCE_LS_SE0(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_UTMI_SUSPENDM_MASK           (0x20000000U)
#define USBPHY_CTRL_UTMI_SUSPENDM_SHIFT          (29U)
#define USBPHY_CTRL_UTMI_SUSPENDM(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLKGATE_MASK                 (0x40000000U)
#define USBPHY_CTRL_CLKGATE_SHIFT                (30U)
#define USBPHY_CTRL_CLKGATE(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLKGATE_SHIFT)) & USBPHY_CTRL_CLKGATE_MASK)

#define USBPHY_CTRL_SFTRST_MASK                  (0x80000000U)
#define USBPHY_CTRL_SFTRST_SHIFT                 (31U)
#define USBPHY_CTRL_SFTRST(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SFTRST_SHIFT)) & USBPHY_CTRL_SFTRST_MASK)
/*! @} */

/*! @name CTRL_SET - USB PHY General Control Register */
/*! @{ */

#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
#define USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT (1U)
#define USBPHY_CTRL_SET_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_SET_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT    (2U)
#define USBPHY_CTRL_SET_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_SET_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT (3U)
#define USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_SET_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT  (4U)
#define USBPHY_CTRL_SET_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_SET_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT (5U)
#define USBPHY_CTRL_SET_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT     (6U)
#define USBPHY_CTRL_SET_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_SET_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT      (7U)
#define USBPHY_CTRL_SET_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_SET_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT    (8U)
#define USBPHY_CTRL_SET_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_SET_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT  (9U)
#define USBPHY_CTRL_SET_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_SET_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_SET_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_SET_RESUME_IRQ_SHIFT         (10U)
#define USBPHY_CTRL_SET_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_SET_RESUME_IRQ_MASK)

#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT     (11U)
#define USBPHY_CTRL_SET_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_SET_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT      (12U)
#define USBPHY_CTRL_SET_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_SET_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_SET_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_SET_DATA_ON_LRADC_SHIFT      (13U)
#define USBPHY_CTRL_SET_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_SET_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT       (14U)
#define USBPHY_CTRL_SET_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_SET_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT       (15U)
#define USBPHY_CTRL_SET_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_SET_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_SET_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT        (16U)
#define USBPHY_CTRL_SET_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_SET_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_SET_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT         (17U)
#define USBPHY_CTRL_SET_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_SET_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_SET_ENAUTO_PWRON_PLL_MASK    (0x40000U)
#define USBPHY_CTRL_SET_ENAUTO_PWRON_PLL_SHIFT   (18U)
#define USBPHY_CTRL_SET_ENAUTO_PWRON_PLL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTO_PWRON_PLL_SHIFT)) & USBPHY_CTRL_SET_ENAUTO_PWRON_PLL_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT  (19U)
#define USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
#define USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_SET_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_SET_ENDPDMCHG_WKUP_MASK      (0x200000U)
#define USBPHY_CTRL_SET_ENDPDMCHG_WKUP_SHIFT     (21U)
#define USBPHY_CTRL_SET_ENDPDMCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENDPDMCHG_WKUP_SHIFT)) & USBPHY_CTRL_SET_ENDPDMCHG_WKUP_MASK)

#define USBPHY_CTRL_SET_ENIDCHG_WKUP_MASK        (0x400000U)
#define USBPHY_CTRL_SET_ENIDCHG_WKUP_SHIFT       (22U)
#define USBPHY_CTRL_SET_ENIDCHG_WKUP(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENIDCHG_WKUP_SHIFT)) & USBPHY_CTRL_SET_ENIDCHG_WKUP_MASK)

#define USBPHY_CTRL_SET_ENVBUSCHG_WKUP_MASK      (0x800000U)
#define USBPHY_CTRL_SET_ENVBUSCHG_WKUP_SHIFT     (23U)
#define USBPHY_CTRL_SET_ENVBUSCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_ENVBUSCHG_WKUP_SHIFT)) & USBPHY_CTRL_SET_ENVBUSCHG_WKUP_MASK)

#define USBPHY_CTRL_SET_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT       (24U)
#define USBPHY_CTRL_SET_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_SET_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_SET_RSVD1_MASK               (0x6000000U)
#define USBPHY_CTRL_SET_RSVD1_SHIFT              (25U)
#define USBPHY_CTRL_SET_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_RSVD1_SHIFT)) & USBPHY_CTRL_SET_RSVD1_MASK)

#define USBPHY_CTRL_SET_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT       (27U)
#define USBPHY_CTRL_SET_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_SET_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT  (28U)
#define USBPHY_CTRL_SET_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_SET_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT      (29U)
#define USBPHY_CTRL_SET_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_SET_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_SET_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_SET_CLKGATE_SHIFT            (30U)
#define USBPHY_CTRL_SET_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_CLKGATE_SHIFT)) & USBPHY_CTRL_SET_CLKGATE_MASK)

#define USBPHY_CTRL_SET_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_SET_SFTRST_SHIFT             (31U)
#define USBPHY_CTRL_SET_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_SET_SFTRST_SHIFT)) & USBPHY_CTRL_SET_SFTRST_MASK)
/*! @} */

/*! @name CTRL_CLR - USB PHY General Control Register */
/*! @{ */

#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
#define USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT (1U)
#define USBPHY_CTRL_CLR_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT    (2U)
#define USBPHY_CTRL_CLR_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_CLR_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT (3U)
#define USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_CLR_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT  (4U)
#define USBPHY_CTRL_CLR_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT (5U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT     (6U)
#define USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT      (7U)
#define USBPHY_CTRL_CLR_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT    (8U)
#define USBPHY_CTRL_CLR_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_CLR_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT  (9U)
#define USBPHY_CTRL_CLR_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_CLR_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_CLR_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT         (10U)
#define USBPHY_CTRL_CLR_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_CLR_RESUME_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT     (11U)
#define USBPHY_CTRL_CLR_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_CLR_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT      (12U)
#define USBPHY_CTRL_CLR_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_CLR_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_CLR_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_CLR_DATA_ON_LRADC_SHIFT      (13U)
#define USBPHY_CTRL_CLR_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_CLR_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT       (14U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT       (15U)
#define USBPHY_CTRL_CLR_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_CLR_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT        (16U)
#define USBPHY_CTRL_CLR_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_CLR_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT         (17U)
#define USBPHY_CTRL_CLR_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_CLR_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_CLR_ENAUTO_PWRON_PLL_MASK    (0x40000U)
#define USBPHY_CTRL_CLR_ENAUTO_PWRON_PLL_SHIFT   (18U)
#define USBPHY_CTRL_CLR_ENAUTO_PWRON_PLL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTO_PWRON_PLL_SHIFT)) & USBPHY_CTRL_CLR_ENAUTO_PWRON_PLL_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT  (19U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
#define USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_CLR_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_CLR_ENDPDMCHG_WKUP_MASK      (0x200000U)
#define USBPHY_CTRL_CLR_ENDPDMCHG_WKUP_SHIFT     (21U)
#define USBPHY_CTRL_CLR_ENDPDMCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENDPDMCHG_WKUP_SHIFT)) & USBPHY_CTRL_CLR_ENDPDMCHG_WKUP_MASK)

#define USBPHY_CTRL_CLR_ENIDCHG_WKUP_MASK        (0x400000U)
#define USBPHY_CTRL_CLR_ENIDCHG_WKUP_SHIFT       (22U)
#define USBPHY_CTRL_CLR_ENIDCHG_WKUP(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENIDCHG_WKUP_SHIFT)) & USBPHY_CTRL_CLR_ENIDCHG_WKUP_MASK)

#define USBPHY_CTRL_CLR_ENVBUSCHG_WKUP_MASK      (0x800000U)
#define USBPHY_CTRL_CLR_ENVBUSCHG_WKUP_SHIFT     (23U)
#define USBPHY_CTRL_CLR_ENVBUSCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_ENVBUSCHG_WKUP_SHIFT)) & USBPHY_CTRL_CLR_ENVBUSCHG_WKUP_MASK)

#define USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT       (24U)
#define USBPHY_CTRL_CLR_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_CLR_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_CLR_RSVD1_MASK               (0x6000000U)
#define USBPHY_CTRL_CLR_RSVD1_SHIFT              (25U)
#define USBPHY_CTRL_CLR_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_RSVD1_SHIFT)) & USBPHY_CTRL_CLR_RSVD1_MASK)

#define USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT       (27U)
#define USBPHY_CTRL_CLR_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_CLR_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT  (28U)
#define USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_CLR_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT      (29U)
#define USBPHY_CTRL_CLR_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_CLR_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_CLR_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_CLR_CLKGATE_SHIFT            (30U)
#define USBPHY_CTRL_CLR_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_CLKGATE_SHIFT)) & USBPHY_CTRL_CLR_CLKGATE_MASK)

#define USBPHY_CTRL_CLR_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_CLR_SFTRST_SHIFT             (31U)
#define USBPHY_CTRL_CLR_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_CLR_SFTRST_SHIFT)) & USBPHY_CTRL_CLR_SFTRST_MASK)
/*! @} */

/*! @name CTRL_TOG - USB PHY General Control Register */
/*! @{ */

#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK    (0x1U)
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT   (0U)
#define USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_ENOTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK  (0x2U)
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT (1U)
#define USBPHY_CTRL_TOG_ENHOSTDISCONDETECT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENHOSTDISCONDETECT_MASK)

#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK     (0x4U)
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT    (2U)
#define USBPHY_CTRL_TOG_ENIRQHOSTDISCON(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQHOSTDISCON_SHIFT)) & USBPHY_CTRL_TOG_ENIRQHOSTDISCON_MASK)

#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK (0x8U)
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT (3U)
#define USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ(x)  (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_SHIFT)) & USBPHY_CTRL_TOG_HOSTDISCONDETECT_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK   (0x10U)
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT  (4U)
#define USBPHY_CTRL_TOG_ENDEVPLUGINDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENDEVPLUGINDETECT_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK  (0x20U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT (5U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_POLARITY_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK      (0x40U)
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT     (6U)
#define USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_CHG_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK       (0x80U)
#define USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT      (7U)
#define USBPHY_CTRL_TOG_ENOTGIDDETECT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENOTGIDDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENOTGIDDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK     (0x100U)
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT    (8U)
#define USBPHY_CTRL_TOG_RESUMEIRQSTICKY(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUMEIRQSTICKY_SHIFT)) & USBPHY_CTRL_TOG_RESUMEIRQSTICKY_MASK)

#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK   (0x200U)
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT  (9U)
#define USBPHY_CTRL_TOG_ENIRQRESUMEDETECT(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_SHIFT)) & USBPHY_CTRL_TOG_ENIRQRESUMEDETECT_MASK)

#define USBPHY_CTRL_TOG_RESUME_IRQ_MASK          (0x400U)
#define USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT         (10U)
#define USBPHY_CTRL_TOG_RESUME_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RESUME_IRQ_SHIFT)) & USBPHY_CTRL_TOG_RESUME_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK      (0x800U)
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT     (11U)
#define USBPHY_CTRL_TOG_ENIRQDEVPLUGIN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_SHIFT)) & USBPHY_CTRL_TOG_ENIRQDEVPLUGIN_MASK)

#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK       (0x1000U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT      (12U)
#define USBPHY_CTRL_TOG_DEVPLUGIN_IRQ(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_SHIFT)) & USBPHY_CTRL_TOG_DEVPLUGIN_IRQ_MASK)

#define USBPHY_CTRL_TOG_DATA_ON_LRADC_MASK       (0x2000U)
#define USBPHY_CTRL_TOG_DATA_ON_LRADC_SHIFT      (13U)
#define USBPHY_CTRL_TOG_DATA_ON_LRADC(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_DATA_ON_LRADC_SHIFT)) & USBPHY_CTRL_TOG_DATA_ON_LRADC_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK        (0x4000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT       (14U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL2(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL2_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL2_MASK)

#define USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK        (0x8000U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT       (15U)
#define USBPHY_CTRL_TOG_ENUTMILEVEL3(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENUTMILEVEL3_SHIFT)) & USBPHY_CTRL_TOG_ENUTMILEVEL3_MASK)

#define USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK         (0x10000U)
#define USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT        (16U)
#define USBPHY_CTRL_TOG_ENIRQWAKEUP(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIRQWAKEUP_SHIFT)) & USBPHY_CTRL_TOG_ENIRQWAKEUP_MASK)

#define USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK          (0x20000U)
#define USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT         (17U)
#define USBPHY_CTRL_TOG_WAKEUP_IRQ(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_WAKEUP_IRQ_SHIFT)) & USBPHY_CTRL_TOG_WAKEUP_IRQ_MASK)

#define USBPHY_CTRL_TOG_ENAUTO_PWRON_PLL_MASK    (0x40000U)
#define USBPHY_CTRL_TOG_ENAUTO_PWRON_PLL_SHIFT   (18U)
#define USBPHY_CTRL_TOG_ENAUTO_PWRON_PLL(x)      (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTO_PWRON_PLL_SHIFT)) & USBPHY_CTRL_TOG_ENAUTO_PWRON_PLL_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK   (0x80000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT  (19U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK   (0x100000U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT  (20U)
#define USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_SHIFT)) & USBPHY_CTRL_TOG_ENAUTOCLR_PHY_PWD_MASK)

#define USBPHY_CTRL_TOG_ENDPDMCHG_WKUP_MASK      (0x200000U)
#define USBPHY_CTRL_TOG_ENDPDMCHG_WKUP_SHIFT     (21U)
#define USBPHY_CTRL_TOG_ENDPDMCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENDPDMCHG_WKUP_SHIFT)) & USBPHY_CTRL_TOG_ENDPDMCHG_WKUP_MASK)

#define USBPHY_CTRL_TOG_ENIDCHG_WKUP_MASK        (0x400000U)
#define USBPHY_CTRL_TOG_ENIDCHG_WKUP_SHIFT       (22U)
#define USBPHY_CTRL_TOG_ENIDCHG_WKUP(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENIDCHG_WKUP_SHIFT)) & USBPHY_CTRL_TOG_ENIDCHG_WKUP_MASK)

#define USBPHY_CTRL_TOG_ENVBUSCHG_WKUP_MASK      (0x800000U)
#define USBPHY_CTRL_TOG_ENVBUSCHG_WKUP_SHIFT     (23U)
#define USBPHY_CTRL_TOG_ENVBUSCHG_WKUP(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_ENVBUSCHG_WKUP_SHIFT)) & USBPHY_CTRL_TOG_ENVBUSCHG_WKUP_MASK)

#define USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK        (0x1000000U)
#define USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT       (24U)
#define USBPHY_CTRL_TOG_FSDLL_RST_EN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_FSDLL_RST_EN_SHIFT)) & USBPHY_CTRL_TOG_FSDLL_RST_EN_MASK)

#define USBPHY_CTRL_TOG_RSVD1_MASK               (0x6000000U)
#define USBPHY_CTRL_TOG_RSVD1_SHIFT              (25U)
#define USBPHY_CTRL_TOG_RSVD1(x)                 (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_RSVD1_SHIFT)) & USBPHY_CTRL_TOG_RSVD1_MASK)

#define USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK        (0x8000000U)
#define USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT       (27U)
#define USBPHY_CTRL_TOG_OTG_ID_VALUE(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_OTG_ID_VALUE_SHIFT)) & USBPHY_CTRL_TOG_OTG_ID_VALUE_MASK)

#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK   (0x10000000U)
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT  (28U)
#define USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_SHIFT)) & USBPHY_CTRL_TOG_HOST_FORCE_LS_SE0_MASK)

#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK       (0x20000000U)
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT      (29U)
#define USBPHY_CTRL_TOG_UTMI_SUSPENDM(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_UTMI_SUSPENDM_SHIFT)) & USBPHY_CTRL_TOG_UTMI_SUSPENDM_MASK)

#define USBPHY_CTRL_TOG_CLKGATE_MASK             (0x40000000U)
#define USBPHY_CTRL_TOG_CLKGATE_SHIFT            (30U)
#define USBPHY_CTRL_TOG_CLKGATE(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_CLKGATE_SHIFT)) & USBPHY_CTRL_TOG_CLKGATE_MASK)

#define USBPHY_CTRL_TOG_SFTRST_MASK              (0x80000000U)
#define USBPHY_CTRL_TOG_SFTRST_SHIFT             (31U)
#define USBPHY_CTRL_TOG_SFTRST(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_CTRL_TOG_SFTRST_SHIFT)) & USBPHY_CTRL_TOG_SFTRST_MASK)
/*! @} */

/*! @name STATUS - USB PHY Status Register */
/*! @{ */

#define USBPHY_STATUS_RSVD0_MASK                 (0x7U)
#define USBPHY_STATUS_RSVD0_SHIFT                (0U)
#define USBPHY_STATUS_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RSVD0_SHIFT)) & USBPHY_STATUS_RSVD0_MASK)

#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK (0x8U)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT (3U)
#define USBPHY_STATUS_HOSTDISCONDETECT_STATUS(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_HOSTDISCONDETECT_STATUS_SHIFT)) & USBPHY_STATUS_HOSTDISCONDETECT_STATUS_MASK)

#define USBPHY_STATUS_RSVD1_MASK                 (0x30U)
#define USBPHY_STATUS_RSVD1_SHIFT                (4U)
#define USBPHY_STATUS_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RSVD1_SHIFT)) & USBPHY_STATUS_RSVD1_MASK)

#define USBPHY_STATUS_DEVPLUGIN_STATUS_MASK      (0x40U)
#define USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT     (6U)
#define USBPHY_STATUS_DEVPLUGIN_STATUS(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_DEVPLUGIN_STATUS_SHIFT)) & USBPHY_STATUS_DEVPLUGIN_STATUS_MASK)

#define USBPHY_STATUS_RSVD2_MASK                 (0x80U)
#define USBPHY_STATUS_RSVD2_SHIFT                (7U)
#define USBPHY_STATUS_RSVD2(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RSVD2_SHIFT)) & USBPHY_STATUS_RSVD2_MASK)

#define USBPHY_STATUS_OTGID_STATUS_MASK          (0x100U)
#define USBPHY_STATUS_OTGID_STATUS_SHIFT         (8U)
#define USBPHY_STATUS_OTGID_STATUS(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_OTGID_STATUS_SHIFT)) & USBPHY_STATUS_OTGID_STATUS_MASK)

#define USBPHY_STATUS_RSVD3_MASK                 (0x200U)
#define USBPHY_STATUS_RSVD3_SHIFT                (9U)
#define USBPHY_STATUS_RSVD3(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RSVD3_SHIFT)) & USBPHY_STATUS_RSVD3_MASK)

#define USBPHY_STATUS_RESUME_STATUS_MASK         (0x400U)
#define USBPHY_STATUS_RESUME_STATUS_SHIFT        (10U)
#define USBPHY_STATUS_RESUME_STATUS(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RESUME_STATUS_SHIFT)) & USBPHY_STATUS_RESUME_STATUS_MASK)

#define USBPHY_STATUS_RSVD4_MASK                 (0xFFFFF800U)
#define USBPHY_STATUS_RSVD4_SHIFT                (11U)
#define USBPHY_STATUS_RSVD4(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_STATUS_RSVD4_SHIFT)) & USBPHY_STATUS_RSVD4_MASK)
/*! @} */

/*! @name DEBUG - USB PHY Debug Register */
/*! @{ */

#define USBPHY_DEBUG_OTGIDPIOLOCK_MASK           (0x1U)
#define USBPHY_DEBUG_OTGIDPIOLOCK_SHIFT          (0U)
#define USBPHY_DEBUG_OTGIDPIOLOCK(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_DEBUG_INTERFACE_HOLD_MASK   (0x2U)
#define USBPHY_DEBUG_DEBUG_INTERFACE_HOLD_SHIFT  (1U)
#define USBPHY_DEBUG_DEBUG_INTERFACE_HOLD(x)     (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG_HSTPULLDOWN_MASK            (0xCU)
#define USBPHY_DEBUG_HSTPULLDOWN_SHIFT           (2U)
#define USBPHY_DEBUG_HSTPULLDOWN(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_ENHSTPULLDOWN_MASK          (0x30U)
#define USBPHY_DEBUG_ENHSTPULLDOWN_SHIFT         (4U)
#define USBPHY_DEBUG_ENHSTPULLDOWN(x)            (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_RSVD0_MASK                  (0xC0U)
#define USBPHY_DEBUG_RSVD0_SHIFT                 (6U)
#define USBPHY_DEBUG_RSVD0(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_RSVD0_SHIFT)) & USBPHY_DEBUG_RSVD0_MASK)

#define USBPHY_DEBUG_TX2RXCOUNT_MASK             (0xF00U)
#define USBPHY_DEBUG_TX2RXCOUNT_SHIFT            (8U)
#define USBPHY_DEBUG_TX2RXCOUNT(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_ENTX2RXCOUNT_MASK           (0x1000U)
#define USBPHY_DEBUG_ENTX2RXCOUNT_SHIFT          (12U)
#define USBPHY_DEBUG_ENTX2RXCOUNT(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_RSVD1_MASK                  (0xE000U)
#define USBPHY_DEBUG_RSVD1_SHIFT                 (13U)
#define USBPHY_DEBUG_RSVD1(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_RSVD1_SHIFT)) & USBPHY_DEBUG_RSVD1_MASK)

#define USBPHY_DEBUG_SQUELCHRESETCOUNT_MASK      (0x1F0000U)
#define USBPHY_DEBUG_SQUELCHRESETCOUNT_SHIFT     (16U)
#define USBPHY_DEBUG_SQUELCHRESETCOUNT(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_RSVD2_MASK                  (0xE00000U)
#define USBPHY_DEBUG_RSVD2_SHIFT                 (21U)
#define USBPHY_DEBUG_RSVD2(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_RSVD2_SHIFT)) & USBPHY_DEBUG_RSVD2_MASK)

#define USBPHY_DEBUG_ENSQUELCHRESET_MASK         (0x1000000U)
#define USBPHY_DEBUG_ENSQUELCHRESET_SHIFT        (24U)
#define USBPHY_DEBUG_ENSQUELCHRESET(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_SQUELCHRESETLENGTH_MASK     (0x1E000000U)
#define USBPHY_DEBUG_SQUELCHRESETLENGTH_SHIFT    (25U)
#define USBPHY_DEBUG_SQUELCHRESETLENGTH(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_HOST_RESUME_DEBUG_MASK      (0x20000000U)
#define USBPHY_DEBUG_HOST_RESUME_DEBUG_SHIFT     (29U)
#define USBPHY_DEBUG_HOST_RESUME_DEBUG(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_CLKGATE_MASK                (0x40000000U)
#define USBPHY_DEBUG_CLKGATE_SHIFT               (30U)
#define USBPHY_DEBUG_CLKGATE(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLKGATE_SHIFT)) & USBPHY_DEBUG_CLKGATE_MASK)

#define USBPHY_DEBUG_RSVD3_MASK                  (0x80000000U)
#define USBPHY_DEBUG_RSVD3_SHIFT                 (31U)
#define USBPHY_DEBUG_RSVD3(x)                    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_RSVD3_SHIFT)) & USBPHY_DEBUG_RSVD3_MASK)
/*! @} */

/*! @name DEBUG_SET - USB PHY Debug Register */
/*! @{ */

#define USBPHY_DEBUG_SET_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_SET_OTGIDPIOLOCK_SHIFT      (0U)
#define USBPHY_DEBUG_SET_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_SET_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD_SHIFT (1U)
#define USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG_SET_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG_SET_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_SET_HSTPULLDOWN_SHIFT       (2U)
#define USBPHY_DEBUG_SET_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_SET_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_SET_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_SET_ENHSTPULLDOWN_SHIFT     (4U)
#define USBPHY_DEBUG_SET_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_SET_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_SET_RSVD0_MASK              (0xC0U)
#define USBPHY_DEBUG_SET_RSVD0_SHIFT             (6U)
#define USBPHY_DEBUG_SET_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_RSVD0_SHIFT)) & USBPHY_DEBUG_SET_RSVD0_MASK)

#define USBPHY_DEBUG_SET_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_SET_TX2RXCOUNT_SHIFT        (8U)
#define USBPHY_DEBUG_SET_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_SET_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_SET_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_SET_ENTX2RXCOUNT_SHIFT      (12U)
#define USBPHY_DEBUG_SET_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_SET_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_SET_RSVD1_MASK              (0xE000U)
#define USBPHY_DEBUG_SET_RSVD1_SHIFT             (13U)
#define USBPHY_DEBUG_SET_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_RSVD1_SHIFT)) & USBPHY_DEBUG_SET_RSVD1_MASK)

#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_SHIFT (16U)
#define USBPHY_DEBUG_SET_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_SET_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_SET_RSVD2_MASK              (0xE00000U)
#define USBPHY_DEBUG_SET_RSVD2_SHIFT             (21U)
#define USBPHY_DEBUG_SET_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_RSVD2_SHIFT)) & USBPHY_DEBUG_SET_RSVD2_MASK)

#define USBPHY_DEBUG_SET_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_SET_ENSQUELCHRESET_SHIFT    (24U)
#define USBPHY_DEBUG_SET_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_SET_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_SHIFT (25U)
#define USBPHY_DEBUG_SET_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_SET_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_SHIFT (29U)
#define USBPHY_DEBUG_SET_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_SET_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_SET_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_SET_CLKGATE_SHIFT           (30U)
#define USBPHY_DEBUG_SET_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_CLKGATE_SHIFT)) & USBPHY_DEBUG_SET_CLKGATE_MASK)

#define USBPHY_DEBUG_SET_RSVD3_MASK              (0x80000000U)
#define USBPHY_DEBUG_SET_RSVD3_SHIFT             (31U)
#define USBPHY_DEBUG_SET_RSVD3(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_SET_RSVD3_SHIFT)) & USBPHY_DEBUG_SET_RSVD3_MASK)
/*! @} */

/*! @name DEBUG_CLR - USB PHY Debug Register */
/*! @{ */

#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK_SHIFT      (0U)
#define USBPHY_DEBUG_CLR_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_CLR_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD_SHIFT (1U)
#define USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG_CLR_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG_CLR_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_CLR_HSTPULLDOWN_SHIFT       (2U)
#define USBPHY_DEBUG_CLR_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_CLR_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN_SHIFT     (4U)
#define USBPHY_DEBUG_CLR_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_CLR_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_CLR_RSVD0_MASK              (0xC0U)
#define USBPHY_DEBUG_CLR_RSVD0_SHIFT             (6U)
#define USBPHY_DEBUG_CLR_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_RSVD0_SHIFT)) & USBPHY_DEBUG_CLR_RSVD0_MASK)

#define USBPHY_DEBUG_CLR_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_CLR_TX2RXCOUNT_SHIFT        (8U)
#define USBPHY_DEBUG_CLR_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT_SHIFT      (12U)
#define USBPHY_DEBUG_CLR_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_CLR_RSVD1_MASK              (0xE000U)
#define USBPHY_DEBUG_CLR_RSVD1_SHIFT             (13U)
#define USBPHY_DEBUG_CLR_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_RSVD1_SHIFT)) & USBPHY_DEBUG_CLR_RSVD1_MASK)

#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_SHIFT (16U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_CLR_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_CLR_RSVD2_MASK              (0xE00000U)
#define USBPHY_DEBUG_CLR_RSVD2_SHIFT             (21U)
#define USBPHY_DEBUG_CLR_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_RSVD2_SHIFT)) & USBPHY_DEBUG_CLR_RSVD2_MASK)

#define USBPHY_DEBUG_CLR_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_CLR_ENSQUELCHRESET_SHIFT    (24U)
#define USBPHY_DEBUG_CLR_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_CLR_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_SHIFT (25U)
#define USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_CLR_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_SHIFT (29U)
#define USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_CLR_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_CLR_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_CLR_CLKGATE_SHIFT           (30U)
#define USBPHY_DEBUG_CLR_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_CLKGATE_SHIFT)) & USBPHY_DEBUG_CLR_CLKGATE_MASK)

#define USBPHY_DEBUG_CLR_RSVD3_MASK              (0x80000000U)
#define USBPHY_DEBUG_CLR_RSVD3_SHIFT             (31U)
#define USBPHY_DEBUG_CLR_RSVD3(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_CLR_RSVD3_SHIFT)) & USBPHY_DEBUG_CLR_RSVD3_MASK)
/*! @} */

/*! @name DEBUG_TOG - USB PHY Debug Register */
/*! @{ */

#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK_MASK       (0x1U)
#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK_SHIFT      (0U)
#define USBPHY_DEBUG_TOG_OTGIDPIOLOCK(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_OTGIDPIOLOCK_SHIFT)) & USBPHY_DEBUG_TOG_OTGIDPIOLOCK_MASK)

#define USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD_MASK (0x2U)
#define USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD_SHIFT (1U)
#define USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD_SHIFT)) & USBPHY_DEBUG_TOG_DEBUG_INTERFACE_HOLD_MASK)

#define USBPHY_DEBUG_TOG_HSTPULLDOWN_MASK        (0xCU)
#define USBPHY_DEBUG_TOG_HSTPULLDOWN_SHIFT       (2U)
#define USBPHY_DEBUG_TOG_HSTPULLDOWN(x)          (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_HSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_TOG_HSTPULLDOWN_MASK)

#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN_MASK      (0x30U)
#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN_SHIFT     (4U)
#define USBPHY_DEBUG_TOG_ENHSTPULLDOWN(x)        (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENHSTPULLDOWN_SHIFT)) & USBPHY_DEBUG_TOG_ENHSTPULLDOWN_MASK)

#define USBPHY_DEBUG_TOG_RSVD0_MASK              (0xC0U)
#define USBPHY_DEBUG_TOG_RSVD0_SHIFT             (6U)
#define USBPHY_DEBUG_TOG_RSVD0(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_RSVD0_SHIFT)) & USBPHY_DEBUG_TOG_RSVD0_MASK)

#define USBPHY_DEBUG_TOG_TX2RXCOUNT_MASK         (0xF00U)
#define USBPHY_DEBUG_TOG_TX2RXCOUNT_SHIFT        (8U)
#define USBPHY_DEBUG_TOG_TX2RXCOUNT(x)           (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_TX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_TX2RXCOUNT_MASK)

#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT_MASK       (0x1000U)
#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT_SHIFT      (12U)
#define USBPHY_DEBUG_TOG_ENTX2RXCOUNT(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENTX2RXCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_ENTX2RXCOUNT_MASK)

#define USBPHY_DEBUG_TOG_RSVD1_MASK              (0xE000U)
#define USBPHY_DEBUG_TOG_RSVD1_SHIFT             (13U)
#define USBPHY_DEBUG_TOG_RSVD1(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_RSVD1_SHIFT)) & USBPHY_DEBUG_TOG_RSVD1_MASK)

#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_MASK  (0x1F0000U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_SHIFT (16U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_SHIFT)) & USBPHY_DEBUG_TOG_SQUELCHRESETCOUNT_MASK)

#define USBPHY_DEBUG_TOG_RSVD2_MASK              (0xE00000U)
#define USBPHY_DEBUG_TOG_RSVD2_SHIFT             (21U)
#define USBPHY_DEBUG_TOG_RSVD2(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_RSVD2_SHIFT)) & USBPHY_DEBUG_TOG_RSVD2_MASK)

#define USBPHY_DEBUG_TOG_ENSQUELCHRESET_MASK     (0x1000000U)
#define USBPHY_DEBUG_TOG_ENSQUELCHRESET_SHIFT    (24U)
#define USBPHY_DEBUG_TOG_ENSQUELCHRESET(x)       (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_ENSQUELCHRESET_SHIFT)) & USBPHY_DEBUG_TOG_ENSQUELCHRESET_MASK)

#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_MASK (0x1E000000U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_SHIFT (25U)
#define USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH(x)   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_SHIFT)) & USBPHY_DEBUG_TOG_SQUELCHRESETLENGTH_MASK)

#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_MASK  (0x20000000U)
#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_SHIFT (29U)
#define USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_SHIFT)) & USBPHY_DEBUG_TOG_HOST_RESUME_DEBUG_MASK)

#define USBPHY_DEBUG_TOG_CLKGATE_MASK            (0x40000000U)
#define USBPHY_DEBUG_TOG_CLKGATE_SHIFT           (30U)
#define USBPHY_DEBUG_TOG_CLKGATE(x)              (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_CLKGATE_SHIFT)) & USBPHY_DEBUG_TOG_CLKGATE_MASK)

#define USBPHY_DEBUG_TOG_RSVD3_MASK              (0x80000000U)
#define USBPHY_DEBUG_TOG_RSVD3_SHIFT             (31U)
#define USBPHY_DEBUG_TOG_RSVD3(x)                (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG_TOG_RSVD3_SHIFT)) & USBPHY_DEBUG_TOG_RSVD3_MASK)
/*! @} */

/*! @name DEBUG0_STATUS - UTMI Debug Status Register 0 */
/*! @{ */

#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_MASK (0xFFFFU)
#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_SHIFT (0U)
#define USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT_MASK)

#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_MASK (0x3FF0000U)
#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_SHIFT (16U)
#define USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(x) (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT_MASK)

#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_MASK  (0xFC000000U)
#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_SHIFT (26U)
#define USBPHY_DEBUG0_STATUS_SQUELCH_COUNT(x)    (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_SHIFT)) & USBPHY_DEBUG0_STATUS_SQUELCH_COUNT_MASK)
/*! @} */

/*! @name DEBUG1 - UTMI Debug Status Register 1 */
/*! @{ */

#define USBPHY_DEBUG1_RSVD0_MASK                 (0x1FFFU)
#define USBPHY_DEBUG1_RSVD0_SHIFT                (0U)
#define USBPHY_DEBUG1_RSVD0(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_RSVD0_SHIFT)) & USBPHY_DEBUG1_RSVD0_MASK)

#define USBPHY_DEBUG1_ENTAILADJVD_MASK           (0x6000U)
#define USBPHY_DEBUG1_ENTAILADJVD_SHIFT          (13U)
#define USBPHY_DEBUG1_ENTAILADJVD(x)             (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_RSVD1_MASK                 (0xFFFF8000U)
#define USBPHY_DEBUG1_RSVD1_SHIFT                (15U)
#define USBPHY_DEBUG1_RSVD1(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_RSVD1_SHIFT)) & USBPHY_DEBUG1_RSVD1_MASK)
/*! @} */

/*! @name DEBUG1_SET - UTMI Debug Status Register 1 */
/*! @{ */

#define USBPHY_DEBUG1_SET_RSVD0_MASK             (0x1FFFU)
#define USBPHY_DEBUG1_SET_RSVD0_SHIFT            (0U)
#define USBPHY_DEBUG1_SET_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_RSVD0_SHIFT)) & USBPHY_DEBUG1_SET_RSVD0_MASK)

#define USBPHY_DEBUG1_SET_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT      (13U)
#define USBPHY_DEBUG1_SET_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_SET_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_SET_RSVD1_MASK             (0xFFFF8000U)
#define USBPHY_DEBUG1_SET_RSVD1_SHIFT            (15U)
#define USBPHY_DEBUG1_SET_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_SET_RSVD1_SHIFT)) & USBPHY_DEBUG1_SET_RSVD1_MASK)
/*! @} */

/*! @name DEBUG1_CLR - UTMI Debug Status Register 1 */
/*! @{ */

#define USBPHY_DEBUG1_CLR_RSVD0_MASK             (0x1FFFU)
#define USBPHY_DEBUG1_CLR_RSVD0_SHIFT            (0U)
#define USBPHY_DEBUG1_CLR_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_RSVD0_SHIFT)) & USBPHY_DEBUG1_CLR_RSVD0_MASK)

#define USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT      (13U)
#define USBPHY_DEBUG1_CLR_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_CLR_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_CLR_RSVD1_MASK             (0xFFFF8000U)
#define USBPHY_DEBUG1_CLR_RSVD1_SHIFT            (15U)
#define USBPHY_DEBUG1_CLR_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_CLR_RSVD1_SHIFT)) & USBPHY_DEBUG1_CLR_RSVD1_MASK)
/*! @} */

/*! @name DEBUG1_TOG - UTMI Debug Status Register 1 */
/*! @{ */

#define USBPHY_DEBUG1_TOG_RSVD0_MASK             (0x1FFFU)
#define USBPHY_DEBUG1_TOG_RSVD0_SHIFT            (0U)
#define USBPHY_DEBUG1_TOG_RSVD0(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_RSVD0_SHIFT)) & USBPHY_DEBUG1_TOG_RSVD0_MASK)

#define USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK       (0x6000U)
#define USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT      (13U)
#define USBPHY_DEBUG1_TOG_ENTAILADJVD(x)         (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_ENTAILADJVD_SHIFT)) & USBPHY_DEBUG1_TOG_ENTAILADJVD_MASK)

#define USBPHY_DEBUG1_TOG_RSVD1_MASK             (0xFFFF8000U)
#define USBPHY_DEBUG1_TOG_RSVD1_SHIFT            (15U)
#define USBPHY_DEBUG1_TOG_RSVD1(x)               (((uint32_t)(((uint32_t)(x)) << USBPHY_DEBUG1_TOG_RSVD1_SHIFT)) & USBPHY_DEBUG1_TOG_RSVD1_MASK)
/*! @} */

/*! @name VERSION - UTMI RTL Version */
/*! @{ */

#define USBPHY_VERSION_STEP_MASK                 (0xFFFFU)
#define USBPHY_VERSION_STEP_SHIFT                (0U)
#define USBPHY_VERSION_STEP(x)                   (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_STEP_SHIFT)) & USBPHY_VERSION_STEP_MASK)

#define USBPHY_VERSION_MINOR_MASK                (0xFF0000U)
#define USBPHY_VERSION_MINOR_SHIFT               (16U)
#define USBPHY_VERSION_MINOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MINOR_SHIFT)) & USBPHY_VERSION_MINOR_MASK)

#define USBPHY_VERSION_MAJOR_MASK                (0xFF000000U)
#define USBPHY_VERSION_MAJOR_SHIFT               (24U)
#define USBPHY_VERSION_MAJOR(x)                  (((uint32_t)(((uint32_t)(x)) << USBPHY_VERSION_MAJOR_SHIFT)) & USBPHY_VERSION_MAJOR_MASK)
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
#elif defined(__CWCC__)
  #pragma pop
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


#endif  /* PERI_USBPHY_H_ */

