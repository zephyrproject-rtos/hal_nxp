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
**         CMSIS Peripheral Access Layer for ENET_PHY_VS_MII_MMD
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
 * @file ENET_PHY_VS_MII_MMD.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_VS_MII_MMD
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_VS_MII_MMD
 */

#if !defined(ENET_PHY_VS_MII_MMD_H_)
#define ENET_PHY_VS_MII_MMD_H_                   /**< Symbol preventing repeated inclusion */

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
   -- ENET_PHY_VS_MII_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_VS_MII_MMD_Peripheral_Access_Layer ENET_PHY_VS_MII_MMD Peripheral Access Layer
 * @{
 */

/** ENET_PHY_VS_MII_MMD - Register Layout Typedef */
typedef struct {
  __IO uint16_t SR_MII_CTRL;                       /**< SR MII MMD Control, offset: 0x0 */
  __I  uint16_t SR_MII_STS;                        /**< SR MII MMD Status, offset: 0x2 */
  __I  uint16_t SR_MII_DEV_ID1;                    /**< SR MII MMD Device Identifier 1, offset: 0x4 */
  __I  uint16_t SR_MII_DEV_ID2;                    /**< SR MII MMD Device Identifier 2, offset: 0x6 */
  __IO uint16_t SR_MII_AN_ADV;                     /**< SR MII MMD AN Advertisement, offset: 0x8 */
  __I  uint16_t SR_MII_LP_BABL;                    /**< SR MII MMD AN Link Partner Base Ability, offset: 0xA */
  __I  uint16_t SR_MII_AN_EXPN;                    /**< SR MII MMD AN Expansion, offset: 0xC */
       uint8_t RESERVED_0[16];
  __I  uint16_t SR_MII_EXT_STS;                    /**< SR MII MMD Extended Status, offset: 0x1E */
       uint8_t RESERVED_1[65504];
  __IO uint16_t VR_MII_DIG_CTRL1;                  /**< VR MII MMD Digital Control 1, offset: 0x10000 */
  __IO uint16_t VR_MII_AN_CTRL;                    /**< VR MII MMD AN Control, offset: 0x10002 */
  __IO uint16_t VR_MII_AN_INTR_STS;                /**< VR MII MMD AN Interrupt and Status, offset: 0x10004 */
       uint8_t RESERVED_2[14];
  __IO uint16_t VR_MII_LINK_TIMER_CTRL;            /**< VR MII MMD Link Timer Control, offset: 0x10014 */
} ENET_PHY_VS_MII_MMD_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_VS_MII_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_VS_MII_MMD_Register_Masks ENET_PHY_VS_MII_MMD Register Masks
 * @{
 */

/*! @name SR_MII_CTRL - SR MII MMD Control */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5_MASK (0x20U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5_SHIFT (5U)
/*! SS5 - Speed Selection */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS5_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6_MASK (0x40U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT (6U)
/*! SS6 - Speed Selection */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS6_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK (0x100U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT (8U)
/*! DUPLEX_MODE - Duplex Mode
 *  0b0..Half duplex
 *  0b1..Full duplex
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK (0x200U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT (9U)
/*! RESTART_AN - Restart Auto-Negotiation (RW, SC Type) */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RESTART_AN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LPM_MASK (0x800U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT (11U)
/*! LPM - Power-Down Mode
 *  0b0..Normal operation
 *  0b1..DWC_XPCS goes to the power-down mode along with the PHY
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LPM(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LPM_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK (0x1000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT (12U)
/*! AN_ENABLE - Enable Auto-Negotiation
 *  0b1..Enables the Clause 37 auto-negotiation process
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13_MASK (0x2000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT (13U)
/*! SS13 - Speed Selection (LSB) */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_SS13_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LBE_MASK (0x4000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT (14U)
/*! LBE - Loopback Enable
 *  0b1..DWC_XPCS asserts xpcs_loopback_en_o signal
 *  0b0..DWC_XPCS de-asserts xpcs_loopback_en_o signal
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LBE(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_LBE_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RST_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RST_SHIFT (15U)
/*! RST - Soft Reset (RW, SC Type) */
#define ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RST(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RST_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_CTRL_RST_MASK)
/*! @} */

/*! @name SR_MII_STS - SR MII MMD Status */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK (0x1U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT (0U)
/*! EXT_REG_CAP - Extended Register Capability
 *  0b1..Extended Register capability exists
 *  0b0..Extended Register capability does not exist
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_REG_CAP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_LINK_STS_MASK (0x4U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT (2U)
/*! LINK_STS - Link Status (RO, LL Type)
 *  0b1..Link up
 *  0b0..Link down
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_LINK_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_LINK_STS_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_ABL_MASK (0x8U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT (3U)
/*! AN_ABL - Auto-Negotiation Ability
 *  0b1..DWC_XPCS is able to perform auto-negotiation
 *  0b0..DWC_XPCS is not able to perform auto-negotiation
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_RF_MASK   (0x10U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_RF_SHIFT  (4U)
/*! RF - Remote Fault (RO, LH Type)
 *  0b1..DWC_XPCS detected a remote fault
 *  0b0..DWC_XPCS did not detect a remote fault
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_RF(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_RF_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_RF_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK (0x20U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT (5U)
/*! AN_CMPL - Auto-Negotiation Complete
 *  0b1..The AN process is complete
 *  0b0..The AN process is not complete
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_CMPL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK (0x40U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT (6U)
/*! MF_PRE_SUP - MF Preamble Suppression
 *  0b1..DWC_XPCS accepts the MDIO frames with preamble suppressed
 *  0b0..DWC_XPCS does not accept the MDIO frames with preamble suppressed
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_MF_PRE_SUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK (0x80U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT (7U)
/*! UN_DIR_ABL - Unidirectional Ability
 *  0b1..DWC_XPCS is able to transmit GMII irrespective of whether device has determined the valid link or not
 *  0b0..DWC_XPCS is able to transmit GMII only when the device has determined the valid link
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_UN_DIR_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK (0x100U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT (8U)
/*! EXT_STS_ABL - Extended Status Information
 *  0b1..Extended Status information is present at register address 16'h000F of this MMD device
 *  0b0..No Extended Status information is present at register address 16'h000F of this MMD device
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_STS_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100T_MASK (0x200U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100T_SHIFT (9U)
/*! HD100T - 100BASE-T2 Half-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100T(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100T_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100T_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100T_MASK (0x400U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100T_SHIFT (10U)
/*! FD100T - 100BASE-T2 Full-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100T(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100T_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100T_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD10ABL_MASK (0x800U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT (11U)
/*! HD10ABL - 10 Mbit/s Half-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD10ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_HD10ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD10ABL_MASK (0x1000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT (12U)
/*! FD10ABL - 10 Mbit/s Full-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD10ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_FD10ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100ABL_MASK (0x2000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT (13U)
/*! HD100ABL - 100BASE-X Half-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_HD100ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100ABL_MASK (0x4000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT (14U)
/*! FD100ABL - 100BASE-X Full-Duplex Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_FD100ABL_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_STS_ABL100T4_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT (15U)
/*! ABL100T4 - 100BASE-T4 Ability */
#define ENET_PHY_VS_MII_MMD_SR_MII_STS_ABL100T4(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_STS_ABL100T4_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID1 - SR MII MMD Device Identifier 1 */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT (0U)
/*! VS_MII_DEV_OUI_3_18 - Organizationally Unique Identifier [3:18] */
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID2 - SR MII MMD Device Identifier 2 */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK (0xFU)
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT (0U)
/*! VS_MMD_DEV_RN_3_0 - Revision Number */
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK (0x3F0U)
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT (4U)
/*! VS_MMD_DEV_MMN_5_0 - Model Number */
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK (0xFC00U)
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT (10U)
/*! VS_MMD_DEV_OUI_19_24 - Organizationally Unique Identifier [19:24] */
#define ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_MII_AN_ADV - SR MII MMD AN Advertisement */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_FD_MASK (0x20U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT (5U)
/*! FD - Full Duplex */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_FD(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_FD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_HD_MASK (0x40U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT (6U)
/*! HD - Half Duplex */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_HD(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_HD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK (0x180U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT (7U)
/*! PAUSE - Pause Ability
 *  0b00..No pause
 *  0b01..Asymmetric pause towards the link partner
 *  0b10..Symmetric pause
 *  0b11..Symmetric pause and asymmetric pause towards the local device
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_PAUSE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_RF_MASK (0x3000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT (12U)
/*! RF - Remote Fault
 *  0b00..No error
 *  0b01..Offline
 *  0b10..Link failure
 *  0b11..Auto-negotiation error
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_RF(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_RF_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_NP_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT (15U)
/*! NP - Next Page */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_NP(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_ADV_NP_MASK)
/*! @} */

/*! @name SR_MII_LP_BABL - SR MII MMD AN Link Partner Base Ability */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK (0x20U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT (5U)
/*! LP_FD - Full Duplex */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_FD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK (0x40U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT (6U)
/*! LP_HD - Half Duplex */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_HD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK (0x180U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT (7U)
/*! LP_PAUSE - Pause Ability
 *  0b00..No pause
 *  0b01..Asymmetric pause towards the link partner
 *  0b10..Symmetric pause
 *  0b11..Both symmetric pause and asymmetric pause towards the local device
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK (0x3000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT (12U)
/*! LP_RF - Remote Fault
 *  0b00..No error
 *  0b01..Offline
 *  0b10..Link failure
 *  0b11..Auto-negotiation error
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_RF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK (0x4000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT (14U)
/*! LP_ACK - ACK Bit from the Link Partner */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT (15U)
/*! LP_NP - Next Page */
#define ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_NP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK)
/*! @} */

/*! @name SR_MII_AN_EXPN - SR MII MMD AN Expansion */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK (0x2U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT (1U)
/*! PG_RCVD - Page Received (RO, LH Type)
 *  0b1..The local device received a new page
 *  0b0..The local device did not receive a new page
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK (0x4U)
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT (2U)
/*! LD_NP_ABL - Local Device NP Able
 *  0b1..The local device has the next page ability
 *  0b0..The local device does not have the next page ability
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK)
/*! @} */

/*! @name SR_MII_EXT_STS - SR MII MMD Extended Status */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK (0x1000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT (12U)
/*! CAP_1G_T_HD - 1000BASE-T Half-Duplex Capable
 *  0b1..1000BASE-T half-duplex capable
 *  0b0..Not 1000BASE-T half-duplex capable
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK (0x2000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT (13U)
/*! CAP_1G_T_FD - 1000BASE-T Full-Duplex Capable
 *  0b1..1000BASE-T full-duplex capable
 *  0b0..Not 1000BASE-T full-duplex capable
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK (0x4000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT (14U)
/*! CAP_1G_X_HD - 1000BASE-X Half-Duplex Capable
 *  0b1..1000BASE-X half-duplex capable
 *  0b0..Not 1000BASE-X half-duplex capable
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK)

#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT (15U)
/*! CAP_1G_X_FD - 1000BASE-X Full-Duplex Capable
 *  0b1..1000BASE-X full-duplex capable
 *  0b0..Not 1000BASE-X full-duplex capable
 */
#define ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT)) & ENET_PHY_VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK)
/*! @} */

/*! @name VR_MII_DIG_CTRL1 - VR MII MMD Digital Control 1 */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK (0x1U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT (0U)
/*! PHY_MODE_CTRL - PHY Mode Control */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
/*! BYP_PWRUP - Bypass Power-Up Sequence */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK (0x8U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT (3U)
/*! CL37_TMR_OVR_RIDE - Over-Ride Control for CL37 Link Timer */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
/*! DTXLANED_0 - TX Lane 0 Disable */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_100M_MASK (0x20U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_100M_SHIFT (5U)
/*! EN_100M - Enable 100Mbit/s PCS Mode */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_100M(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_100M_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_100M_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK (0x40U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT (6U)
/*! PRE_EMP - Pre-emption Packet Enable */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK (0x200U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT (9U)
/*! MAC_AUTO_SW - Automatic Speed Mode Change After CL37 AN */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK (0x800U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT (11U)
/*! PWRSV - Power Save
 *  0b0..Normal operation
 *  0b1..DWC_XPCS and the PHY enter the power-save mode
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK (0x2000U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT (13U)
/*! EN_VSMMD1 - Enable Vendor-Specific MMD1 */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK (0x4000U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT (14U)
/*! R2TLBE - RX to TX Loopback Enable
 *  0b0..Loopback path is disabled
 *  0b1..Loopback path is enabled
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK (0x8000U)
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT (15U)
/*! VR_RST - Vendor-Specific Soft Reset (RW, SC Type) */
#define ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_MII_AN_CTRL - VR MII MMD AN Control */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK (0x1U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT (0U)
/*! MII_AN_INTR_EN - Clause 37 AN Complete Interrupt Enable
 *  0b1..Enables the generation of Clause 37 auto-negotiation complete interrupt output
 *  0b0..Disables the generation of Clause 37 auto-negotiation complete interrupt
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK (0x6U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT (1U)
/*! PCS_MODE - PCS Mode
 *  0b00..1000BASE-X mode (clause 37 auto-negotiation is as per 1000BaseX)
 *  0b10..SGMII mode (clause 37 auto-negotiation is as per SGMII)
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK (0x8U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT (3U)
/*! TX_CONFIG - Transmit Configuration
 *  0b1..Configures DWC_XPCS as the PHY side SGMII/USXGMII
 *  0b0..Configures DWC_XPCS as the MAC side SGMII/USXGMII
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK (0x10U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT (4U)
/*! SGMII_LINK_STS - SGMII Link Status / USXGMII Link Status
 *  0b0..Link down
 *  0b1..Link up
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK (0x100U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT (8U)
/*! MII_CTRL - MII Control
 *  0b0..4-bit MII
 *  0b1..8-bit MII
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK (0x200U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT (9U)
/*! IND_TX_EN - Independent Transmit Enable in 1000BASE-X Mode
 *  0b1..DWC_XPCS transmits the GMII TX data, irrespective of its receive link status (provided auto-negotiation is not enabled)
 *  0b0..DWC_XPCS sends IDLE till its receiver has attained synchronization
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK)
/*! @} */

/*! @name VR_MII_AN_INTR_STS - VR MII MMD AN Interrupt and Status */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK (0x1U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT (0U)
/*! CL37_ANCMPLT_INTR - Clause 37 AN Complete Interrupt (SS, WC Type) */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK (0x1EU)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT (1U)
/*! CL37_ANSGM_STS - Clause 37 AN SGMII Status
 *  0bxxx0..Half Duplex
 *  0bxxx1..Full Duplex
 *  0bx01x..100 Mbit/s speed link
 *  0bx10x..1000 Mbit/s speed link
 *  0b0xxx..Link is Down
 *  0b1xxx..Link is Up
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK)

#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_MASK (0x7F00U)
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_SHIFT (8U)
/*! USXG_AN_STS - USXGMII Clause 37 AN Status
 *  0bxxxxxx0..EEE clock-stop not supported
 *  0bxxxxxx1..EEE clock-stop supported
 *  0bxxxxx1x..EEE supported
 *  0bxxxxx0x..EEE not supported
 *  0bxx001xx..100 Mbit/s speed link
 *  0bxx010xx..1000 Mbit/s speed link
 *  0bxx011xx..10 Gbit/s speed link
 *  0bxx100xx..2.5 Gbit/s speed link
 *  0bxx101xx..5 Gbit/s speed link
 *  0bx0xxxxx..Half Duplex
 *  0bx1xxxxx..Full Duplex
 *  0b0xxxxxx..Link is Down
 *  0b1xxxxxx..Link is Up
 */
#define ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_MASK)
/*! @} */

/*! @name VR_MII_LINK_TIMER_CTRL - VR MII MMD Link Timer Control */
/*! @{ */

#define ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK (0xFFFFU)
#define ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT (0U)
/*! CL37_LINK_TIME - Programmable Link Timer Value for Clause 37 Auto-Negotiation */
#define ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT)) & ENET_PHY_VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_VS_MII_MMD_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_PHY_VS_MII_MMD_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_VS_MII_MMD_H_ */

