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
**         CMSIS Peripheral Access Layer for ENET_PHY_XS_PCS_MMD
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
 * @file ENET_PHY_XS_PCS_MMD.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_XS_PCS_MMD
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_XS_PCS_MMD
 */

#if !defined(ENET_PHY_XS_PCS_MMD_H_)
#define ENET_PHY_XS_PCS_MMD_H_                   /**< Symbol preventing repeated inclusion */

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
   -- ENET_PHY_XS_PCS_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_XS_PCS_MMD_Peripheral_Access_Layer ENET_PHY_XS_PCS_MMD Peripheral Access Layer
 * @{
 */

/** ENET_PHY_XS_PCS_MMD - Register Layout Typedef */
typedef struct {
  __IO uint16_t SR_XS_PCS_CTRL1;                   /**< SR XS or PCS MMD Control 1, offset: 0x0 */
  __I  uint16_t SR_XS_PCS_STS1;                    /**< SR XS or PCS MMD Status1, offset: 0x2 */
  __I  uint16_t SR_XS_PCS_DEV_ID1;                 /**< SR XS or PCS MMD Device Identifier 1, offset: 0x4 */
  __I  uint16_t SR_XS_PCS_DEV_ID2;                 /**< SR XS or PCS MMD Device Identifier 2, offset: 0x6 */
  __I  uint16_t SR_XS_PCS_SPD_ABL;                 /**< SR XS or PCS MMD Speed Ability, offset: 0x8 */
  __I  uint16_t SR_XS_PCS_DEV_PKG1;                /**< SR XS or PCS MMD Devices in Package 1, offset: 0xA */
  __I  uint16_t SR_XS_PCS_DEV_PKG2;                /**< SR XS or PCS MMD Devices in Package 2, offset: 0xC */
  __IO uint16_t SR_XS_PCS_CTRL2;                   /**< SR PCS Control 2, offset: 0xE */
  __I  uint16_t SR_XS_PCS_STS2;                    /**< SR XS or PCS MMD Status 2, offset: 0x10 */
  __I  uint16_t SR_XS_PCS_STS3;                    /**< SR PCS MMD Status 3, offset: 0x12 */
       uint8_t RESERVED_0[8];
  __I  uint16_t SR_XS_PCS_PKG1;                    /**< SR XS or PCS MMD Package Identifier 1, offset: 0x1C */
  __I  uint16_t SR_XS_PCS_PKG2;                    /**< SR XS or PCS MMD Package Identifier 2, offset: 0x1E */
       uint8_t RESERVED_1[8];
  __I  uint16_t SR_XS_PCS_EEE_ABL;                 /**< SR XS or PCS MMD EEE Capability, offset: 0x28 */
  __I  uint16_t SR_XS_PCS_EEE_ABL2;                /**< SR PCS MMD EEE Control and Capability 2, offset: 0x2A */
  __I  uint16_t SR_XS_PCS_EEE_WKERR;               /**< SR XS or PCS MMD EEE Wake Error Counter, offset: 0x2C */
       uint8_t RESERVED_2[2];
  __I  uint16_t SR_XS_PCS_LSTS;                    /**< SR XS or PCS MMD 10GBASE-X Lane Status, offset: 0x30 */
  __IO uint16_t SR_XS_PCS_TCTRL;                   /**< SR XS or PCS MMD 10GBASE-X Test Control, offset: 0x32 */
       uint8_t RESERVED_3[12];
  __I  uint16_t SR_XS_PCS_KR_STS1;                 /**< SR PCS MMD 10GBASE-R Status 1, offset: 0x40 */
  __I  uint16_t SR_XS_PCS_KR_STS2;                 /**< SR PCS MMD 10GBASE-R Status 2, offset: 0x42 */
  __IO uint16_t SR_XS_PCS_TP_A0;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A0, offset: 0x44 */
  __IO uint16_t SR_XS_PCS_TP_A1;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A1, offset: 0x46 */
  __IO uint16_t SR_XS_PCS_TP_A2;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A2 Register, offset: 0x48 */
  __IO uint16_t SR_XS_PCS_TP_A3;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A3 Register, offset: 0x4A */
  __IO uint16_t SR_XS_PCS_TP_B0;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B0, offset: 0x4C */
  __IO uint16_t SR_XS_PCS_TP_B1;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B1, offset: 0x4E */
  __IO uint16_t SR_XS_PCS_TP_B2;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B2, offset: 0x50 */
  __IO uint16_t SR_XS_PCS_TP_B3;                   /**< SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B3, offset: 0x52 */
  __IO uint16_t SR_XS_PCS_TP_CTRL;                 /**< SR PCS BASE-R Test Pattern Control, offset: 0x54 */
  __I  uint16_t SR_XS_PCS_TP_ERRCTR;               /**< SR PCS BASE-R Test Pattern Error Counter, offset: 0x56 */
       uint8_t RESERVED_4[3512];
  __I  uint16_t SR_PCS_TIME_SYNC_PCS_ABL;          /**< SR PCS MMD Time Sync Capability, offset: 0xE10 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR;   /**< SR PCS MMD Time Sync TX Max Delay Lower, offset: 0xE12 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR;   /**< SR PCS MMD Time Sync TX Max Delay Upper, offset: 0xE14 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR;   /**< SR PCS MMD Time Sync TX Min Delay Lower, offset: 0xE16 */
  __I  uint16_t SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR;   /**< SR PCS MMD Time Sync TX Min Delay Upper, offset: 0xE18 */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR;   /**< SR PCS MMD Time Sync RX Max Delay Lower, offset: 0xE1A */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR;   /**< SR PCS MMD Time Sync RX Max Delay Upper, offset: 0xE1C */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR;   /**< SR PCS MMD Time Sync RX Min Delay Lower, offset: 0xE1E */
  __I  uint16_t SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR;   /**< SR PCS MMD Time Sync RX Min Delay Upper, offset: 0xE20 */
       uint8_t RESERVED_5[61918];
  __IO uint16_t VR_XS_PCS_DIG_CTRL1;               /**< VR XS or PCS MMD Digital Control 1, offset: 0x10000 */
  __IO uint16_t VR_XS_PCS_DIG_CTRL2;               /**< VR XS or PCS MMD Digital Control 2, offset: 0x10002 */
  __IO uint16_t VR_XS_PCS_DIG_ERRCNT_SEL;          /**< VR XS or PCS MMD Digital Error Count Select, offset: 0x10004 */
       uint8_t RESERVED_6[2];
  __I  uint16_t VR_XS_PCS_XAUI_CTRL;               /**< VR XS or PCS MMD XAUI Mode Control, offset: 0x10008 */
  __IO uint16_t VR_XS_PCS_DEBUG_CTRL;              /**< VR XS or PCS MMD Debug Control, offset: 0x1000A */
  __IO uint16_t VR_XS_PCS_EEE_MCTRL0;              /**< VR XS or PCS MMD EEE Mode Control, offset: 0x1000C */
  __IO uint16_t VR_XS_PCS_KR_CTRL;                 /**< VR PCS 10GBASE-R Control, offset: 0x1000E */
  __IO uint16_t VR_XS_PCS_EEE_TXTIMER;             /**< VR XS or PCS MMD EEE TX Timer, offset: 0x10010 */
  __IO uint16_t VR_XS_PCS_EEE_RXTIMER;             /**< VR XS or PCS MMD EEE RX Timer, offset: 0x10012 */
       uint8_t RESERVED_7[2];
  __IO uint16_t VR_XS_PCS_EEE_MCTRL1;              /**< VR XS or PCS MMD EEE Mode Control 1, offset: 0x10016 */
       uint8_t RESERVED_8[8];
  __I  uint16_t VR_XS_PCS_DIG_STS;                 /**< VR XS or PCS MMD Digital Status, offset: 0x10020 */
  __I  uint16_t VR_XS_PCS_ICG_ERRCNT1;             /**< VR XS or PCS MMD Invalid Code Group Error Count 1, offset: 0x10022 */
} ENET_PHY_XS_PCS_MMD_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_XS_PCS_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_XS_PCS_MMD_Register_Masks ENET_PHY_XS_PCS_MMD Register Masks
 * @{
 */

/*! @name SR_XS_PCS_CTRL1 - SR XS or PCS MMD Control 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_MASK (0x3CU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_SHIFT (2U)
/*! SS_5_2 - Speed Selection Bits [5:2] */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS_5_2_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_SHIFT (6U)
/*! SS6 - Speed Selection Bit 6 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS6_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_MASK (0x400U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_SHIFT (10U)
/*! CS_EN - CS_EN */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_CS_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_MASK (0x800U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_SHIFT (11U)
/*! LPM - Low-Power Enable
 *  0b0..Normal operation
 *  0b1..DWC_XPCS goes to power-down mode along with the PHY
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_LPM_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_MASK (0x2000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_SHIFT (13U)
/*! SS13 - Speed Selection
 *  0b0..DWC_XPCS is in 1G speed
 *  0b1..DWC_XPCS is in 10G speed
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_SS13_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_MASK (0x8000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_SHIFT (15U)
/*! RST - Soft Reset (RW, SC Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL1_RST_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS1 - SR XS or PCS MMD Status1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_SHIFT (1U)
/*! LPMS - Low-Power Mode Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_LPMS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_LPMS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RLU_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RLU_SHIFT (2U)
/*! RLU - RX Link Up (RO, LL Type)
 *  0b0..Not successful
 *  0b1..Successful
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RLU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RLU_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RLU_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_CSC_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_CSC_SHIFT (6U)
/*! CSC - Clock Stop Capable
 *  0b1..The MAC can stop the clock during the LPI mode
 *  0b0..The MAC cannot stop the clock during the LPI mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_CSC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_CSC_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_CSC_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_FLT_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_FLT_SHIFT (7U)
/*! FLT - Fault Condition Detected */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_FLT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_FLT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_FLT_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_MASK (0x100U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_SHIFT (8U)
/*! RXLPII - RX LPI Indication
 *  0b1..DWC_XPCS RX is currently receiving LPI
 *  0b0..DWC_XPCS RX is currently not receiving LPI
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPII_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_MASK (0x200U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_SHIFT (9U)
/*! TXLPII - TX LPI Indication
 *  0b1..DWC_XPCS TX is currently receiving LPI
 *  0b0..DWC_XPCS TX is currently not receiving LPI
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPII_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_MASK (0x400U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_SHIFT (10U)
/*! RXLPIR - RX LPI Received (RO, LH Type)
 *  0b1..LPI received
 *  0b0..LPI not received
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_RXLPIR_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_MASK (0x800U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_SHIFT (11U)
/*! TXLPIR - TX LPI Received (RO, LH Type)
 *  0b1..LPI received
 *  0b0..LPI not received
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS1_TXLPIR_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_ID1 - SR XS or PCS MMD Device Identifier 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_SHIFT (0U)
/*! PCS_DEV_OUI_3_18 - Organizationally Unique Identifier [3:18] */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID1_PCS_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_ID2 - SR XS or PCS MMD Device Identifier 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_MASK (0xFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_SHIFT (0U)
/*! PCS_DEV_RN_3_0 - Revision Number */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_RN_3_0_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_MASK (0x3F0U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_SHIFT (4U)
/*! PCS_DEV_MMN_5_0 - Model Number */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_MMN_5_0_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_MASK (0xFC00U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_SHIFT (10U)
/*! PCS_DEV_OUI_19_24 - Organizationally Unique Identifier [19:24] */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_ID2_PCS_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_XS_PCS_SPD_ABL - SR XS or PCS MMD Speed Ability */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_SHIFT (0U)
/*! XGC - 10G Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_SPD_ABL_XGC_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_PKG1 - SR XS or PCS MMD Devices in Package 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_SHIFT (0U)
/*! CLS22 - Clause 22 Register Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_CLS22_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_SHIFT (1U)
/*! PMA_PMD - PMA or PMD MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PMA_PMD_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_SHIFT (2U)
/*! WIS - WIS MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_WIS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_SHIFT (3U)
/*! PCS - PCS MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PCS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_SHIFT (4U)
/*! PHYXS - PHY XGXS MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_PHYXS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_SHIFT (5U)
/*! DTEXS - DTE XGXS MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_DTEXS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_SHIFT (6U)
/*! TC - TC MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_TC_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_SHIFT (7U)
/*! AN - Auto-Negotiation MMD */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG1_AN_MASK)
/*! @} */

/*! @name SR_XS_PCS_DEV_PKG2 - SR XS or PCS MMD Devices in Package 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_MASK (0x4000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_SHIFT (14U)
/*! VSD1 - Vendor-specific Device 1 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD1_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_MASK (0x8000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_SHIFT (15U)
/*! VSD2 - Vendor-Specific Device 2 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_DEV_PKG2_VSD2_MASK)
/*! @} */

/*! @name SR_XS_PCS_CTRL2 - SR PCS Control 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK (0xFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_SHIFT (0U)
/*! PCS_TYPE_SEL - PCS Type Select
 *  0b0001..Select 10GBASE-X PCS Type
 *  *..Reserved
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_CTRL2_PCS_TYPE_SEL_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS2 - SR XS or PCS MMD Status 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_SHIFT (0U)
/*! CAP_EN - 10GBASE-R Capable
 *  0b1..DWC_XPCS can support 10GBASE-R PCS type
 *  0b0..DWC_XPCS cannot support 10GBASE-R PCS type
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_SHIFT (1U)
/*! CAP_10_1GC - 10GBASE-X Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10_1GC_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_SHIFT (2U)
/*! CAP_10GBW - 10GBASE-W Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBW_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_SHIFT (3U)
/*! CAP_10GBT - 10GBASE-T Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_CAP_10GBT_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_RF_MASK (0x400U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_RF_SHIFT (10U)
/*! RF - Receiver Fault (LH Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_RF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_RF_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_RF_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_TF_MASK (0x800U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_TF_SHIFT (11U)
/*! TF - Transmitter Fault (LH Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_TF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_TF_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_TF_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_DS_MASK (0xC000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_DS_SHIFT (14U)
/*! DS - Device Present Status
 *  0b10..MMD is present and responding to this register address
 *  *..MMD is not present or not functioning properly
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_DS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_DS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS2_DS_MASK)
/*! @} */

/*! @name SR_XS_PCS_STS3 - SR PCS MMD Status 3 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_SHIFT (0U)
/*! CAP_200GR - 200GBASE-R Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_200GR_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_SHIFT (1U)
/*! CAP_400GR - 400GBASE-R Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_400GR_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_SHIFT (2U)
/*! CAP_2PT5GX - 2.5GBASE-X Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_2PT5GX_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_SHIFT (3U)
/*! CAP_5GR - 5GBASE-R Capable */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_STS3_CAP_5GR_MASK)
/*! @} */

/*! @name SR_XS_PCS_PKG1 - SR XS or PCS MMD Package Identifier 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_SHIFT (0U)
/*! PCS_PKG_OUI_3_18 - Organizationally Unique Identifier */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG1_PCS_PKG_OUI_3_18_MASK)
/*! @} */

/*! @name SR_XS_PCS_PKG2 - SR XS or PCS MMD Package Identifier 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_MASK (0xFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_SHIFT (0U)
/*! PCS_PKG_RN_3_0 - Revision Number */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_RN_3_0_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_MASK (0x3F0U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_SHIFT (4U)
/*! PCS_PKG_MMN_5_0 - Model Number */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_MMN_5_0_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_MASK (0xFC00U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_SHIFT (10U)
/*! PCS_PKG_OUI_19_24 - Organizationally Unique Identifier */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_PKG2_PCS_PKG_OUI_19_24_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_ABL - SR XS or PCS MMD EEE Capability */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_SHIFT (1U)
/*! EN_100TEE - 100BASE-T Mode EEE Support
 *  0b0..EEE is not supported in the 100BASE-T mode
 *  0b1..EEE is supported in the 100BASE-T mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_100TEE_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_SHIFT (2U)
/*! EN_1GTEEE - 1000BASE-T Mode EEE Support
 *  0b0..EEE is not supported in the 1000BASE-T mode
 *  0b1..EEE is supported in the 1000BASE-T mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_EN_1GTEEE_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_SHIFT (3U)
/*! TEEE - 10GBASE-T Mode EEE Support
 *  0b0..EEE is not supported in the 10GBASE-T mode
 *  0b1..EEE is supported in the 10GBASE-T mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_TEEE_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_SHIFT (4U)
/*! KXEEE - XGXS, or 1G EEE Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KXEEE_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_SHIFT (5U)
/*! KX4EEE - 10GBASE-X PCS EEE Support
 *  0b0..EEE is not supported in 10GBASE-X PCS mode
 *  0b1..EE is supported in 10GBASE-X PCS mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KX4EEE_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_SHIFT (6U)
/*! KREEE - 10GBASE-R PCS Mode EEE Support
 *  0b0..EEE is not supported in 10GBASE-R PCS mode
 *  0b1..EEE is supported in 10GBASE-R PCS or mode
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL_KREEE_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_ABL2 - SR PCS MMD EEE Control and Capability 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_SHIFT (0U)
/*! EEE_2PT5GT - 2.5GBASE-T EEE Mode Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_2PT5GT_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_SHIFT (1U)
/*! EEE_5GT - 5GBASE-T EEE Mode Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_5GT_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_SHIFT (2U)
/*! EEE_25GT - 25GBASE-T EEE Mode Support */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_ABL2_EEE_25GT_MASK)
/*! @} */

/*! @name SR_XS_PCS_EEE_WKERR - SR XS or PCS MMD EEE Wake Error Counter */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_SHIFT (0U)
/*! EEE_WEC - EEE Wake Error Counter */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_EEE_WKERR_EEE_WEC_MASK)
/*! @} */

/*! @name SR_XS_PCS_LSTS - SR XS or PCS MMD 10GBASE-X Lane Status */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_MASK (0xFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_SHIFT (0U)
/*! LNS - Lane Synchronization */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LNS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LNS_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_MASK (0x400U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_SHIFT (10U)
/*! LBA - LBA */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LBA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LBA_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_MASK (0x800U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_SHIFT (11U)
/*! TPA - Test Pattern Ability */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_TPA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_TPA_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LA_MASK (0x1000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LA_SHIFT (12U)
/*! LA - Receiver Lanes are Aligned
 *  0b0..RX lanes are not deskewed
 *  0b1..RX lanes are deskewed
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LA_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_LSTS_LA_MASK)
/*! @} */

/*! @name SR_XS_PCS_TCTRL - SR XS or PCS MMD 10GBASE-X Test Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_MASK (0x3U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_SHIFT (0U)
/*! TP - Test Pattern Select
 *  0b00..High Frequency Test Pattern
 *  0b01..Low Frequency Test Pattern
 *  0b10..Mixed Frequency Test Pattern
 *  0b11..Continuous Test Pattern (CJPAT or CRPAT)
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TP_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_SHIFT (2U)
/*! TPE - Test Pattern Enable Lanes
 *  0b0..Test pattern disabled
 *  0b1..Test pattern enabled
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TCTRL_TPE_MASK)
/*! @} */

/*! @name SR_XS_PCS_KR_STS1 - SR PCS MMD 10GBASE-R Status 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_BKLK_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_BKLK_SHIFT (0U)
/*! RPCS_BKLK - 10GBASE-R Block Lock
 *  0b0..10GBASE-R is not locked to received blocks
 *  0b1..10GBASE-R is locked (Block Alignment Success) to received blocks
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_BKLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_BKLK_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_BKLK_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_HIBER_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_HIBER_SHIFT (1U)
/*! RPCS_HIBER - 10GBASE-R PCS High Bit Error Rate
 *  0b0..10GBASE-R PCS not reporting a high BER
 *  0b1..10GBASE-R PCS reporting a high BER
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_HIBER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_HIBER_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_RPCS_HIBER_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS31ABL_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS31ABL_SHIFT (2U)
/*! PRBS31ABL - PRBS31 Testing Ability
 *  0b0..DWC_XPCS does not support the PRBS31 pattern testing
 *  0b1..DWC_XPCS supports the PRBS31 pattern testing
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS31ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS31ABL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS31ABL_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS9ABL_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS9ABL_SHIFT (3U)
/*! PRBS9ABL - PRBS9 Testing Ability
 *  0b0..DWC_XPCS does not support the PRBS9 pattern testing
 *  0b1..DWC_XPCS supports the PRBS9 pattern testing
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS9ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS9ABL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PRBS9ABL_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PLU_MASK (0x1000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PLU_SHIFT (12U)
/*! PLU - RPCS Link Up
 *  0b1..10GBASE-R PCS receive link is up
 *  0b0..10GBASE-R PCS receive link is down
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PLU(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PLU_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS1_PLU_MASK)
/*! @} */

/*! @name SR_XS_PCS_KR_STS2 - SR PCS MMD 10GBASE-R Status 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_ERR_BLK_MASK (0xFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_ERR_BLK_SHIFT (0U)
/*! ERR_BLK - Error Block Counter Value (RO, COR Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_ERR_BLK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_ERR_BLK_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_ERR_BLK_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_BER_CNT_MASK (0x3F00U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_BER_CNT_SHIFT (8U)
/*! BER_CNT - Bit Error Rate Counter Value (RO, COR Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_BER_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_BER_CNT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_BER_CNT_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_HBER_MASK (0x4000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_HBER_SHIFT (14U)
/*! LAT_HBER - Latched High Bit Error Rate (RO, LH Type)
 *  0b1..10GBASE-R PCS is reporting a high BER
 *  0b0..10GBASE-R PCS is not reporting a high BER
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_HBER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_HBER_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_HBER_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_BL_MASK (0x8000U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_BL_SHIFT (15U)
/*! LAT_BL - Latched Block Lock (RO, LL Type)
 *  0b1..10GBASE-R PCS achieved the 66-bit code group alignment
 *  0b0..10GBASE-R PCS did not achieve the 66-bit code group alignment
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_BL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_BL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_KR_STS2_LAT_BL_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_A0 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A0 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A0_TP_SA0_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A0_TP_SA0_SHIFT (0U)
/*! TP_SA0 - Test Pattern Seed A0 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A0_TP_SA0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A0_TP_SA0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A0_TP_SA0_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_A1 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A1_TP_SA1_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A1_TP_SA1_SHIFT (0U)
/*! TP_SA1 - Test Pattern Seed A1 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A1_TP_SA1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A1_TP_SA1_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A1_TP_SA1_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_A2 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A2 Register */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A2_TP_SA2_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A2_TP_SA2_SHIFT (0U)
/*! TP_SA2 - Test Pattern Seed A2 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A2_TP_SA2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A2_TP_SA2_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A2_TP_SA2_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_A3 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed A3 Register */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A3_TP_SA3_MASK (0x3FFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A3_TP_SA3_SHIFT (0U)
/*! TP_SA3 - Test Pattern Seed A3 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A3_TP_SA3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A3_TP_SA3_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_A3_TP_SA3_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_B0 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B0 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B0_TP_SB0_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B0_TP_SB0_SHIFT (0U)
/*! TP_SB0 - Test Pattern Seed B0 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B0_TP_SB0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B0_TP_SB0_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B0_TP_SB0_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_B1 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B1_TP_SB1_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B1_TP_SB1_SHIFT (0U)
/*! TP_SB1 - Test Pattern Seed B1 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B1_TP_SB1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B1_TP_SB1_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B1_TP_SB1_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_B2 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B2_TP_SB2_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B2_TP_SB2_SHIFT (0U)
/*! TP_SB2 - Test Pattern Seed B2 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B2_TP_SB2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B2_TP_SB2_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B2_TP_SB2_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_B3 - SR PCS MMD 5G/10GBASE-R Pseudo-Random Test Pattern Seed B3 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B3_TP_SB3_MASK (0x3FFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B3_TP_SB3_SHIFT (0U)
/*! TP_SB3 - Test Pattern Seed B3 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B3_TP_SB3(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B3_TP_SB3_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_B3_TP_SB3_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_CTRL - SR PCS BASE-R Test Pattern Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_DP_SEL_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_DP_SEL_SHIFT (0U)
/*! DP_SEL - Data Pattern Select for Pseudo-Random Testing
 *  0b1..All-zero
 *  0b0..Encoded local-fault pattern (LF)
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_DP_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_DP_SEL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_DP_SEL_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TP_SEL_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TP_SEL_SHIFT (1U)
/*! TP_SEL - Transmit Test Pattern Select */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TP_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TP_SEL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TP_SEL_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_RTP_EN_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_RTP_EN_SHIFT (2U)
/*! RTP_EN - Receive Test Pattern Enable
 *  0b1..Enables receive pseudo-random test pattern when bit 1 (TP_SEL) is set to 0
 *  0b0..Disables receive pseudo-random test pattern
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_RTP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_RTP_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_RTP_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TTP_EN_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TTP_EN_SHIFT (3U)
/*! TTP_EN - Transmit Pseudo-Random or Square Wave Test Pattern Enable
 *  0b1..Enables pseudo-random or square wave test pattern depending on bit 1 (TP_SEL)
 *  0b0..Disables pseudo-random or square wave test patterns
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TTP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TTP_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_TTP_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31T_EN_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31T_EN_SHIFT (4U)
/*! PRBS31T_EN - PRBS31 Transmit Pattern Enable
 *  0b1..Enable PRBS31 test pattern on the Transmit path when bit 3 (TTP_EN) and bit 1 (TP_SEL) of this register is set to 0
 *  0b0..Disable PRBS31 test-pattern mode on the Transmit path
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31T_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31T_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31T_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31R_EN_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31R_EN_SHIFT (5U)
/*! PRBS31R_EN - PRBS31 Receive Test Pattern Enable
 *  0b1..Enable PRBS31 test pattern checking on the Receive path when bit 2 (RTP_EN) is set to 0
 *  0b0..Disable PRBS31 test pattern checking on the Receive path
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31R_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31R_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS31R_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS9T_EN_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS9T_EN_SHIFT (6U)
/*! PRBS9T_EN - PRBS9 Transmit Test Pattern Enable
 *  0b1..Enable PRBS9 test pattern on the Transmit path when bit 3 (TTP_EN), bit 1 (TP_SEL), and bit 4 (PRBS31T_EN) are set to 0
 *  0b0..Disable PRBS9 test-pattern mode on the Transmit path
 */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS9T_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS9T_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_CTRL_PRBS9T_EN_MASK)
/*! @} */

/*! @name SR_XS_PCS_TP_ERRCTR - SR PCS BASE-R Test Pattern Error Counter */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_ERRCTR_TP_ERR_CNT_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_ERRCTR_TP_ERR_CNT_SHIFT (0U)
/*! TP_ERR_CNT - Test Pattern Error Counter (RO, COR Type) */
#define ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_ERRCTR_TP_ERR_CNT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_ERRCTR_TP_ERR_CNT_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_XS_PCS_TP_ERRCTR_TP_ERR_CNT_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_PCS_ABL - SR PCS MMD Time Sync Capability */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_RX_DLY_ABL_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_RX_DLY_ABL_SHIFT (0U)
/*! PCS_RX_DLY_ABL - PCS Receive Path Data Delay Information Available */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_RX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_RX_DLY_ABL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_RX_DLY_ABL_MASK)

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_TX_DLY_ABL_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_TX_DLY_ABL_SHIFT (1U)
/*! PCS_TX_DLY_ABL - PCS Transmit Path Data Delay Information Available */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_TX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_TX_DLY_ABL_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_PCS_ABL_PCS_TX_DLY_ABL_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR - SR PCS MMD Time Sync TX Max Delay Lower */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_SHIFT (0U)
/*! PCS_TX_MAX_DLY_LWR - PCS Transmit Max Delay Lower */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_LWR_PCS_TX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR - SR PCS MMD Time Sync TX Max Delay Upper */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_SHIFT (0U)
/*! PCS_TX_MAX_DLY_UPR - PCS Transmit Max Delay Upper */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MAX_DLY_UPR_PCS_TX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR - SR PCS MMD Time Sync TX Min Delay Lower */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_SHIFT (0U)
/*! PCS_TX_MIN_DLY_LWR - PCS Transmit Min Delay Lower */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_LWR_PCS_TX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR - SR PCS MMD Time Sync TX Min Delay Upper */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_SHIFT (0U)
/*! PCS_TX_MIN_DLY_UPR - PCS Transmit Min Delay Upper */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_TX_MIN_DLY_UPR_PCS_TX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR - SR PCS MMD Time Sync RX Max Delay Lower */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_SHIFT (0U)
/*! PCS_RX_MAX_DLY_LWR - PCS Receive Max Delay Lower */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_LWR_PCS_RX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR - SR PCS MMD Time Sync RX Max Delay Upper */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_SHIFT (0U)
/*! PCS_RX_MAX_DLY_UPR - PCS Receive Max Delay Upper */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MAX_DLY_UPR_PCS_RX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR - SR PCS MMD Time Sync RX Min Delay Lower */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_SHIFT (0U)
/*! PCS_RX_MIN_DLY_LWR - PCS Receive Min Delay Lower */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_LWR_PCS_RX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR - SR PCS MMD Time Sync RX Min Delay Upper */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_SHIFT (0U)
/*! PCS_RX_MIN_DLY_UPR - PCS Receive Min Delay Upper */
#define ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_SHIFT)) & ENET_PHY_XS_PCS_MMD_SR_PCS_TIME_SYNC_RX_MIN_DLY_UPR_PCS_RX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_CTRL1 - VR XS or PCS MMD Digital Control 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_SHIFT (0U)
/*! DSKBYP - DSKBYP */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DSKBYP_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
/*! BYP_PWRUP - Bypass Power-Up Sequence */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_BYP_PWRUP_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_SHIFT (2U)
/*! EN_2_5G_MODE - Enable 2.5G GMII Mode */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_2_5G_MODE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
/*! DTXLANED_0 - TX Disable on Lane 0 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_DTXLANED_0_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_MASK (0x100U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_SHIFT (8U)
/*! INIT - Datapath Initialization Control */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_INIT_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_MASK (0x200U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_SHIFT (9U)
/*! USXG_EN - USXGMII Mode Enable */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USXG_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK (0x400U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_SHIFT (10U)
/*! USRA_RST - USXGMII Rate Adaptor Reset (Port 0) */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_USRA_RST_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_MASK (0x800U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_SHIFT (11U)
/*! PWRSV - Power Save
 *  0b0..Normal operation
 *  0b1..DWC_XPCS and the PHY enter the power-save mode
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_PWRSV_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_MASK (0x2000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_SHIFT (13U)
/*! EN_VSMMD1 - Enable Vendor-Specific MMD1 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_EN_VSMMD1_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_MASK (0x4000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_SHIFT (14U)
/*! R2TLBE - RX to TX Loopback Enable
 *  0b0..Loopback path is disabled
 *  0b1..Loopback path is enabled
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_R2TLBE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK (0x8000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_SHIFT (15U)
/*! VR_RST - Vendor-Specific Soft Reset (RW, SC Type) */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_CTRL2 - VR XS or PCS MMD Digital Control 2 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_SHIFT (0U)
/*! RX_POL_INV_0 - RX Polarity Invert on Lane 0 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_RX_POL_INV_0_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_SHIFT (4U)
/*! TX_POL_INV_0 - TX Polarity Invert on Lane 0 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_CTRL2_TX_POL_INV_0_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_ERRCNT_SEL - VR XS or PCS MMD Digital Error Count Select */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_SHIFT (0U)
/*! COR - Clear on Read
 *  0b0..Normal operation
 *  0b1..Clear any error counter that is read
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_COR_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT (4U)
/*! INV_EC_EN - Invalid Code Group Error Counter Enable
 *  0b0..The counting of errors is disabled
 *  0b1..The counting of errors is enabled
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_ERRCNT_SEL_INV_EC_EN_MASK)
/*! @} */

/*! @name VR_XS_PCS_XAUI_CTRL - VR XS or PCS MMD XAUI Mode Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_SHIFT (0U)
/*! XAUI_MODE - Reserved */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_XAUI_MODE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_SHIFT (1U)
/*! MRVL_RXAUI - Reserved */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_XAUI_CTRL_MRVL_RXAUI_MASK)
/*! @} */

/*! @name VR_XS_PCS_DEBUG_CTRL - VR XS or PCS MMD Debug Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_SHIFT (0U)
/*! RESTAR_SYNC_0 - Restart Synchronization on Lane 0 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RESTAR_SYNC_0_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_SHIFT (4U)
/*! SUPRESS_LOS_DET - Suppress Loss of Signal Detection */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_LOS_DET_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT (5U)
/*! SUPRESS_EEE_LOS_DET - Suppress EEE Loss of Signal Detection */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_SUPRESS_EEE_LOS_DET_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_SHIFT (6U)
/*! RX_DT_EN_CTL - RX Data Enable Control */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_DT_EN_CTL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_SHIFT (7U)
/*! RX_SYNC_CTL - Receive Synchronization Control */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_SYNC_CTL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_MASK (0x100U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_SHIFT (8U)
/*! TX_PMBL_CTL - Transmit Preamble Control */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_TX_PMBL_CTL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_MASK (0x200U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_SHIFT (9U)
/*! RX_PMBL_CTL - Receive Preamble Control */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DEBUG_CTRL_RX_PMBL_CTL_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_MCTRL0 - VR XS or PCS MMD EEE Mode Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_SHIFT (0U)
/*! LTX_EN - LPI TX Enable
 *  0b0..Disables the support for Energy Efficient Ethernet in DWC_XPCS Transmit path
 *  0b1..Enables the Energy Efficient Ethernet support in DWC_XPCS Transmit path
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LTX_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_MASK (0x2U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_SHIFT (1U)
/*! LRX_EN - LPI RX Enable
 *  0b0..Disables the support for Energy Efficient Ethernet in DWC_XPCS Receive path
 *  0b1..Enables the Energy Efficient Ethernet support in DWC_XPCS Receive path
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_LRX_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_MASK (0x4U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_SHIFT (2U)
/*! TX_QUIET_EN - TX Quiet Enable
 *  0b0..The xpcs_lpitx_quiet_o output is not set to 1
 *  0b1..The xpcs_lpitx_quiet_o output is set to 1 when the EEE transmit controller reaches the Quiet state
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_QUIET_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_MASK (0x8U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_SHIFT (3U)
/*! RX_QUIET_EN - RX Quiet Enable
 *  0b0..The xpcs_lpirx_quiet_o output is not set to 1
 *  0b1..The xpcs_lpirx_quiet_o output is set to 1 when the EEE receive controller reaches the Quiet state
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_QUIET_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_MASK (0x10U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_SHIFT (4U)
/*! TX_EN_CTRL - TX Control Enable
 *  0b0..The xgxs_tx{lane}_en_o or xpcs_tx_en_o{lane} signal is not de-asserted when the EEE transmit controller reaches the Quiet state
 *  0b1..The xgxs_tx{lane}_en_o or xpcs_tx_en_o{lane} signal is de-asserted when the EEE transmit controller reaches the Quiet state
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_TX_EN_CTRL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_SHIFT (5U)
/*! EEE_SLR_BYP - Scrambler Bypass
 *  0b0..The scrambler is not bypassed
 *  0b1..The scrambler is bypassed in PCS-R during EEE TX mode
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_EEE_SLR_BYP_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_SHIFT (6U)
/*! SIGN_BIT - Effective 100 ns Tic Value */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_SIGN_BIT_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_SHIFT (7U)
/*! RX_EN_CTRL - RX Control Enable
 *  0b0..The xpcs_rx_en_o signal is not de-asserted when the EEE transmit controller reaches the Quiet state
 *  0b1..The xpcs_rx_en_o signal is de-asserted when the EEE receive controller reaches the Quiet state
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_RX_EN_CTRL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_MASK (0xF00U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_SHIFT (8U)
/*! MULT_FACT_100NS - 100 ns Clock Tic Multiplying Factor */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_MULT_FACT_100NS_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_MASK (0xF000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_SHIFT (12U)
/*! CLKSTOP - Clock Stop */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL0_CLKSTOP_MASK)
/*! @} */

/*! @name VR_XS_PCS_KR_CTRL - VR PCS 10GBASE-R Control */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_VR_TP_EN_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_VR_TP_EN_SHIFT (0U)
/*! VR_TP_EN - PCS-R Vendor-Specific Test Pattern Enable */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_VR_TP_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_VR_TP_EN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_VR_TP_EN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PR_DATA_MASK (0xEU)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PR_DATA_SHIFT (1U)
/*! PR_DATA - Pseudo-Random Test Pattern Data
 *  0b000..Data = All zero (0x00); IEEE specified
 *  0b001..Data = XGMII local fault (encoded version); IEEE specified
 *  0b010..Data = All five (0x55); HFTP
 *  0b011..Data = All A (0xAA); HFTP
 *  0b100..Data = All ones (0xFF); LFTP
 *  0b101..Data = All three (0x33); MFTP
 *  0b110..Data = All C (0xCC); MFTP
 *  0b111..Reserved
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PR_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PR_DATA_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PR_DATA_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_NVAL_SEL_MASK (0x70U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_NVAL_SEL_SHIFT (4U)
/*! NVAL_SEL - Square Wave Control
 *  0b000..4
 *  0b001..5
 *  0b010..6
 *  0b011..7
 *  0b100..8
 *  0b101..9
 *  0b110..10
 *  0b111..11
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_NVAL_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_NVAL_SEL_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_NVAL_SEL_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PRBS9RXEN_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PRBS9RXEN_SHIFT (7U)
/*! PRBS9RXEN - Enable PRBS9 Testing in Receive Path */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PRBS9RXEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PRBS9RXEN_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_PRBS9RXEN_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_SCR_MASK (0x100U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_SCR_SHIFT (8U)
/*! DIS_SCR - Disable Scrambler */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_SCR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_SCR_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_SCR_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_DESCR_MASK (0x200U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_DESCR_SHIFT (9U)
/*! DIS_DESCR - Disable Descrambler */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_DESCR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_DESCR_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_DIS_DESCR_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE_MASK (0x1C00U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE_SHIFT (10U)
/*! USXG_MODE - USXGMII Mode Select
 *  0b000..10G-SXGMII
 *  0b001..5G-SXGMII
 *  0b010..2.5G-SXGMII
 *  0b011..10G-DXGMII
 *  0b100..5G-DXGMII
 *  0b101..10G-QXGMII
 *  0b110, 0b111..Reserved
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_MODE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_2PT5G_GMII_MASK (0x2000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_2PT5G_GMII_SHIFT (13U)
/*! USXG_2PT5G_GMII - MAC/PCS Interface Select in USXGMII 2.5G Mode
 *  0b0..Use XGMII interface
 *  0b1..Use GMII interface
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_2PT5G_GMII(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_2PT5G_GMII_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_KR_CTRL_USXG_2PT5G_GMII_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_TXTIMER - VR XS or PCS MMD EEE TX Timer */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_MASK (0x3FU)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_SHIFT (0U)
/*! TSL_RES - TSL Resolution */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TSL_RES_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_MASK (0xC0U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_SHIFT (6U)
/*! T1U_RES - T1u Resolution */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_T1U_RES_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_MASK (0x1F00U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_SHIFT (8U)
/*! TWL_RES - TWL Resolution */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_TXTIMER_TWL_RES_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_RXTIMER - VR XS or PCS MMD EEE RX Timer */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_MASK (0xFFU)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_SHIFT (0U)
/*! RES_100U - 100 us Resolution */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_RES_100U_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_MASK (0x3F00U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_SHIFT (8U)
/*! TWR_RES - TWR Resolution */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_RXTIMER_TWR_RES_MASK)
/*! @} */

/*! @name VR_XS_PCS_EEE_MCTRL1 - VR XS or PCS MMD EEE Mode Control 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_MASK (0x1U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_SHIFT (0U)
/*! TRN_LPI - Transparent TX LPI Mode Enable */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_EEE_MCTRL1_TRN_LPI_MASK)
/*! @} */

/*! @name VR_XS_PCS_DIG_STS - VR XS or PCS MMD Digital Status */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_MASK (0x1CU)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_SHIFT (2U)
/*! PSEQ_STATE - Power Up Sequence State
 *  0b000..Wait for MPLL ON (for Synopsys multi-protocol 6G PHY), Wait for ACK High 0 (for Synopsys multi-protocol 12G/16G PHY)
 *  0b001..Wait for TX up (6G PHY), Wait for ACK Low 0 (12G/16G/ PHY)
 *  0b010..Wait for RX up (6G PHY), Wait for ACK High 1 (12G/16G PHY)
 *  0b011..TX/RX Stable (Power_Good state) (6G PHY), Wait for ACK Low 1 (12G/16G PHY)
 *  0b100..TX/RX Stable (Power_Good state)
 *  0b101..Wait for RX down (MPLL still ON) (6G PHY), Power Save state (12G/16G PHY)
 *  0b110..MPLL OFF (6G PHY), Power Down state (12G/16G PHY)
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_PSEQ_STATE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_MASK (0x20U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_SHIFT (5U)
/*! RXFIFO_UNDF - RX FIFO Underflow (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..FIFO underflow
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_UNDF_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_MASK (0x40U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_SHIFT (6U)
/*! RXFIFO_OVF - RX FIFO Overflow (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..FIFO overflow
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_RXFIFO_OVF_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_MASK (0x80U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_SHIFT (7U)
/*! INV_XGM_SOP - Invalid XGMII Start Character (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..Invalid SOP character
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_SOP_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_MASK (0x100U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_SHIFT (8U)
/*! INV_XGM_T - Invalid XGMII T Character (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..Invalid Terminate character
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_T_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_MASK (0x200U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_SHIFT (9U)
/*! INV_XGM_CHAR - Invalid XGMII Character (RO, LH Type)
 *  0b0..No Invalid XGMII character
 *  0b1..Invalid character
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_INV_XGM_CHAR_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_MASK (0x1C00U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_SHIFT (10U)
/*! LRX_STATE - LPI Receive State
 *  0b000..LRX_ACTIVE
 *  0b001..LRX_SLEEP
 *  0b010..LRX_QUIET
 *  0b011..LRX_WAKE
 *  0b100..LRX_WTF
 *  0b101..LRX_LINK_FAIL
 *  0b110..LRX_LPI_K (present only in configurations with 1G speed)
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LRX_STATE_MASK)

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_MASK (0xE000U)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_SHIFT (13U)
/*! LTX_STATE - LPI Transmit State
 *  0b000..LTX_ACTIVE
 *  0b001..LTX_SLEEP
 *  0b010..LTX_QUIET
 *  0b011..LTX_REF_WAKE
 *  0b100..LTX_ALERT (valid only if PCS-R is present)
 *  0b101..LTX_SCR_BYP (valid only if PCS-R is present)
 */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_DIG_STS_LTX_STATE_MASK)
/*! @} */

/*! @name VR_XS_PCS_ICG_ERRCNT1 - VR XS or PCS MMD Invalid Code Group Error Count 1 */
/*! @{ */

#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_MASK (0xFFU)
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_SHIFT (0U)
/*! EC0 - Error Count 0: Invalid Code Group Count on Lane 0 (RO, COR Type) */
#define ENET_PHY_XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_SHIFT)) & ENET_PHY_XS_PCS_MMD_VR_XS_PCS_ICG_ERRCNT1_EC0_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_XS_PCS_MMD_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_PHY_XS_PCS_MMD_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_XS_PCS_MMD_H_ */

