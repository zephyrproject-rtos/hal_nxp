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
**         CMSIS Peripheral Access Layer for ENET_PHY_PMA_MMD
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
 * @file ENET_PHY_PMA_MMD.h
 * @version 1.0
 * @date 2023-01-10
 * @brief CMSIS Peripheral Access Layer for ENET_PHY_PMA_MMD
 *
 * CMSIS Peripheral Access Layer for ENET_PHY_PMA_MMD
 */

#if !defined(ENET_PHY_PMA_MMD_H_)
#define ENET_PHY_PMA_MMD_H_                      /**< Symbol preventing repeated inclusion */

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
   -- ENET_PHY_PMA_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_PMA_MMD_Peripheral_Access_Layer ENET_PHY_PMA_MMD Peripheral Access Layer
 * @{
 */

/** ENET_PHY_PMA_MMD - Register Layout Typedef */
typedef struct {
  __IO uint16_t SR_PMA_CTRL1;                      /**< SR PMA MMD Control 1, offset: 0x0 */
  __I  uint16_t SR_PMA_STATUS1;                    /**< SR PMA MMD Status1, offset: 0x2 */
  __I  uint16_t SR_PMA_DEV_ID_1;                   /**< SR PMA MMD Device Identifier 1, offset: 0x4 */
  __I  uint16_t SR_PMA_DEV_ID_2;                   /**< SR PMA MMD Device Identifier 2, offset: 0x6 */
  __I  uint16_t SR_PMA_SPD_ABL;                    /**< SR PMA MMD Speed Ability, offset: 0x8 */
  __I  uint16_t SR_PMA_DEV_PKG1;                   /**< SR PMA MMD Devices in Package 1, offset: 0xA */
  __I  uint16_t SR_PMA_DEV_PKG2;                   /**< SR PMA MMD Devices in Package 2, offset: 0xC */
       uint8_t RESERVED_0[2];
  __I  uint16_t SR_PMA_STATUS2;                    /**< SR PMA MMD Status 2, offset: 0x10 */
  __IO uint16_t SR_PMA_TX_DIS;                     /**< SR PMA MMD Transmit Disable, offset: 0x12 */
  __I  uint16_t SR_PMA_RX_SIG_DET;                 /**< SR PMA MMD Receive Signal Detect, offset: 0x14 */
  __I  uint16_t SR_PMA_EXT_ABL;                    /**< SR PMA or PMD Extended Ability, offset: 0x16 */
       uint8_t RESERVED_1[4];
  __I  uint16_t SR_PMA_PKG1;                       /**< SR PMA MMD Package Identifier 1, offset: 0x1C */
  __I  uint16_t SR_PMA_PKG2;                       /**< SR PMA MMD Package Identifier 2, offset: 0x1E */
       uint8_t RESERVED_2[10];
  __I  uint16_t SR_PMA_2PT5G_5G_EXT_ABL;           /**< SR PMA MMD 2.5G/5G Extended Ability, offset: 0x2A */
       uint8_t RESERVED_3[3556];
  __I  uint16_t SR_PMA_TIME_SYNC_PMA_ABL;          /**< SR PMA MMD Time Sync Capability, offset: 0xE10 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR;   /**< SR PMA MMD Time Sync TX Max Delay Lower, offset: 0xE12 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR;   /**< SR PMA MMD Time Sync TX Max Delay Upper, offset: 0xE14 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR;   /**< SR PMA MMD Time Sync TX Min Delay Lower, offset: 0xE16 */
  __I  uint16_t SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR;   /**< SR PMA MMD Time Sync TX Min Delay Upper, offset: 0xE18 */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR;   /**< SR PMA MMD Time Sync RX Max Delay Lower, offset: 0xE1A */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR;   /**< SR PMA MMD Time Sync RX Max Delay Upper, offset: 0xE1C */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR;   /**< SR PMA MMD Time Sync RX Min Delay Lower, offset: 0xE1E */
  __I  uint16_t SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR;   /**< SR PMA MMD Time Sync RX Min Delay Upper, offset: 0xE20 */
       uint8_t RESERVED_4[61918];
  __IO uint16_t VR_PMA_DIG_CTRL1;                  /**< VR PMA MMD Digital Control 1, offset: 0x10000 */
       uint8_t RESERVED_5[30];
  __I  uint16_t VR_PMA_DIG_STS;                    /**< VR PMA MMD Digital Status, offset: 0x10020 */
       uint8_t RESERVED_6[30];
  __I  uint16_t VR_XS_PMA_RX_LSTS;                 /**< VR XS or PMA PHY RX Lane Status, offset: 0x10040 */
       uint8_t RESERVED_7[30];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX General 0, offset: 0x10060 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX General 1, offset: 0x10062 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_TX_GENCTRL2;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY TX General 2, offset: 0x10064 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Boost Control, offset: 0x10066 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Rate Control, offset: 0x10068 */
  __IO uint16_t MP_12G_16G_25G_TX_POWER_STATE_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Power State, offset: 0x1006A */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Equalization Control 0, offset: 0x1006C */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Equalization Control 1, offset: 0x1006E */
       uint8_t RESERVED_8[8];
  __IO uint16_t VR_XS_PMA_MP_16G_25G_TX_GENCTRL3;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX General Control 3, offset: 0x10078 */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_TX_GENCTRL4;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX General Control 4, offset: 0x1007A */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX Miscellaneous Control 0, offset: 0x1007C */
       uint8_t RESERVED_9[2];
  __I  uint16_t VR_XS_PMA_MP_12G_16G_25G_TX_STS;   /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Status, offset: 0x10080 */
       uint8_t RESERVED_10[30];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX General Control 0, offset: 0x100A0 */
  __IO uint16_t MP_12G_16G_25G_RX_GENCTRL1;        /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX General Control 1, offset: 0x100A2 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_RX_GENCTRL2;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY RX General Control 2, offset: 0x100A4 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_RX_GENCTRL3;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY RX General Control 3, offset: 0x100A6 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Rate Control, offset: 0x100A8 */
  __IO uint16_t MP_12G_16G_25G_RX_POWER_STATE_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Power State, offset: 0x100AA */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX CDR Control, offset: 0x100AC */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Attenuation Control, offset: 0x100AE */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Equalization Control 0, offset: 0x100B0 */
       uint8_t RESERVED_11[6];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Equalization Control 4, offset: 0x100B8 */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Equalization Control 5, offset: 0x100BA */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY DFE Tap Control 0, offset: 0x100BC */
       uint8_t RESERVED_12[2];
  __I  uint16_t VR_XS_PMA_MP_12G_16G_25G_RX_STS;   /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Status, offset: 0x100C0 */
  __I  uint16_t VR_XS_PMA_MP_16G_25G_RX_PPM_STS0;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX PPM Status 0, offset: 0x100C2 */
       uint8_t RESERVED_13[4];
  __IO uint16_t VR_XS_PMA_MP_16G_RX_CDR_CTRL1;     /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY RX CDR Control 1, offset: 0x100C8 */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX PPM Control 0, offset: 0x100CA */
       uint8_t RESERVED_14[4];
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_GENCTRL4;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX General Control 4, offset: 0x100D0 */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Miscellaneous Control 0, offset: 0x100D2 */
       uint8_t RESERVED_15[2];
  __IO uint16_t VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0;  /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX IQ Control 0, offset: 0x100D6 */
       uint8_t RESERVED_16[8];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY MPLL Common Control, offset: 0x100E0 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 0, offset: 0x100E2 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLA_CTRL1;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 1, offset: 0x100E4 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 2, offset: 0x100E6 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLB Control 0, offset: 0x100E8 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLB_CTRL1;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 1, offset: 0x100EA */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2;  /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLB Control 2, offset: 0x100EC */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLA_CTRL3;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 3, offset: 0x100EE */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLB_CTRL3;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 3, offset: 0x100F0 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLA_CTRL4;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 4, offset: 0x100F2 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLA_CTRL5;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 5, offset: 0x100F4 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLB_CTRL4;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 4, offset: 0x100F6 */
  __IO uint16_t VR_XS_PMA_MP_16G_MPLLB_CTRL5;      /**< VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 5, offset: 0x100F8 */
       uint8_t RESERVED_17[38];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Control 0, offset: 0x10120 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Reference Control, offset: 0x10122 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY VCO Calibration Load 0, offset: 0x10124 */
       uint8_t RESERVED_18[6];
  __IO uint16_t VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0; /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY VCO Calibration Reference 0, offset: 0x1012C */
       uint8_t RESERVED_19[2];
  __I  uint16_t VR_XS_PMA_MP_12G_16G_25G_MISC_STS; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Status, offset: 0x10130 */
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1; /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Control 1, offset: 0x10132 */
       uint8_t RESERVED_20[2];
  __IO uint16_t VR_XS_PMA_MP_12G_16G_25G_SRAM;     /**< VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY SRAM, offset: 0x10136 */
  __IO uint16_t VR_XS_PMA_MP_16G_25G_MISC_CTRL2;   /**< VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY Miscellaneous Control 2, offset: 0x10138 */
       uint8_t RESERVED_21[6];
  __IO uint16_t VR_XS_PMA_SNPS_CR_CTRL;            /**< VR XS or PMA Synopsys PHY CR Control, offset: 0x10140 */
  __IO uint16_t VR_XS_PMA_SNPS_CR_ADDR;            /**< VR XS or PMA Synopsys PHY CR Address, offset: 0x10142 */
  __IO uint16_t VR_XS_PMA_SNPS_CR_DATA;            /**< VR XS or PMA Synopsys CR Data, offset: 0x10144 */
} ENET_PHY_PMA_MMD_Type;

/* ----------------------------------------------------------------------------
   -- ENET_PHY_PMA_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ENET_PHY_PMA_MMD_Register_Masks ENET_PHY_PMA_MMD Register Masks
 * @{
 */

/*! @name SR_PMA_CTRL1 - SR PMA MMD Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LB_MASK    (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LB_SHIFT   (0U)
/*! LB - Loopback Enable
 *  0b0..DWC_XPCS de-asserts the xgxs_loopback_en_o{lane} signal
 *  0b1..DWC_XPCS asserts the xgxs_loopback_en_o{lane} signal
 */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LB(x)      (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LB_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LB_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS_5_2_MASK (0x3CU)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS_5_2_SHIFT (2U)
/*! SS_5_2 - Speed Selection Bits[5:2] */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS_5_2(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS_5_2_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS_5_2_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS6_MASK   (0x40U)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS6_SHIFT  (6U)
/*! SS6 - Speed Selection Bit 6 */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS6(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS6_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS6_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LPM_MASK   (0x800U)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LPM_SHIFT  (11U)
/*! LPM - Low-Power Enable
 *  0b0..Normal operation
 *  0b1..DWC_XPCS enters power-down mode along with the PHY
 */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LPM(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LPM_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_LPM_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS13_MASK  (0x2000U)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS13_SHIFT (13U)
/*! SS13 - Speed Selection
 *  0b0..DWC_XPCS is in the 1000BASEX-Only PCS mode (1G speed)
 *  0b1..DWC_XPCS is in the 10GBASE-X PCS mode (10G speed)
 */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS13(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS13_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_SS13_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_RST_MASK   (0x8000U)
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_RST_SHIFT  (15U)
/*! RST - Soft Reset (RW, SC Type) */
#define ENET_PHY_PMA_MMD_SR_PMA_CTRL1_RST(x)     (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_CTRL1_RST_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_CTRL1_RST_MASK)
/*! @} */

/*! @name SR_PMA_STATUS1 - SR PMA MMD Status1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_LPMS_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_LPMS_SHIFT (1U)
/*! LPMS - Low-Power Mode Support */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_LPMS(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS1_LPMS_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS1_LPMS_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_RLU_MASK (0x4U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_RLU_SHIFT (2U)
/*! RLU - RX Link Up (RO,LL Type)
 *  0b0..Goes low when the CDR status of the PHY goes low (indicated by xgxs_rx_valid_i{lane})
 *  0b1..Set when the CDR status of the PHY goes high (indicated by xgxs_rx_valid_i{lane})
 */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_RLU(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS1_RLU_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS1_RLU_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_FLT_MASK (0x80U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_FLT_SHIFT (7U)
/*! FLT - Fault Condition Detected */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS1_FLT(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS1_FLT_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS1_FLT_MASK)
/*! @} */

/*! @name SR_PMA_DEV_ID_1 - SR PMA MMD Device Identifier 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_SHIFT (0U)
/*! PMA_DEV_OUI_3_18 - Organizationally Unique Identifier [3:18] */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_1_PMA_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_PMA_DEV_ID_2 - SR PMA MMD Device Identifier 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_MASK (0xFU)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_SHIFT (0U)
/*! PMA_DEV_RN_3_0 - Revision Number */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_RN_3_0_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_MASK (0x3F0U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_SHIFT (4U)
/*! PMA_DEV_MMN_5_0 - Model Number */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_MMN_5_0_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_MASK (0xFC00U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_SHIFT (10U)
/*! PMA_DEV_OUI_19_24 - Organizationally Unique Identifier [19:24] */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_ID_2_PMA_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_PMA_SPD_ABL - SR PMA MMD Speed Ability */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_XGC_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_XGC_SHIFT (0U)
/*! XGC - 10G Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_XGC(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_XGC_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_XGC_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_GC_MASK  (0x10U)
#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_GC_SHIFT (4U)
/*! GC - 1G Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_GC(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_GC_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_SPD_ABL_GC_MASK)
/*! @} */

/*! @name SR_PMA_DEV_PKG1 - SR PMA MMD Devices in Package 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_CLS22_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_CLS22_SHIFT (0U)
/*! CLS22 - Clause 22 Register Support */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_CLS22(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_CLS22_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_CLS22_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_SHIFT (1U)
/*! PMA_PMD - PMA or PMD MMD
 *  0b1..10GBASE-X PCS for Synopsys PHY, 10GBASE-R PCS for Synopsys PHY
 *  0b0..All other configurations
 */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PMA_PMD_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_WIS_MASK (0x4U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_WIS_SHIFT (2U)
/*! WIS - WIS MMD */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_WIS(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_WIS_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_WIS_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PCS_MASK (0x8U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PCS_SHIFT (3U)
/*! PCS - PCS MMD
 *  0b1..MAIN_MODE = 10GBASE-X PCS, or 10GBASE-R PCS
 *  0b0..All other configurations
 */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PCS(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PCS_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PCS_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_MASK (0x10U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_SHIFT (4U)
/*! PHYXS - PHY XGXS MMD */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PHYXS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_PHYXS_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_MASK (0x20U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_SHIFT (5U)
/*! DTEXS - DTE XGXS MMD */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_DTEXS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_DTEXS_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_TC_MASK (0x40U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_TC_SHIFT (6U)
/*! TC - TC MMD */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_TC(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_TC_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_TC_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_AN_MASK (0x80U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_AN_SHIFT (7U)
/*! AN - Auto-Negotiation MMD */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_AN(x)   (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_AN_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG1_AN_MASK)
/*! @} */

/*! @name SR_PMA_DEV_PKG2 - SR PMA MMD Devices in Package 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD1_MASK (0x4000U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD1_SHIFT (14U)
/*! VSD1 - Vendor-Specific Device 1 */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD1_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD1_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD2_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD2_SHIFT (15U)
/*! VSD2 - Vendor-Specific Device 2 */
#define ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD2_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_DEV_PKG2_VSD2_MASK)
/*! @} */

/*! @name SR_PMA_STATUS2 - SR PMA MMD Status 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_SHIFT (0U)
/*! PMA_LOOP - PMA Loopback Ability */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PMA_LOOP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PMA_LOOP_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGEWEN_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGEWEN_SHIFT (1U)
/*! XGEWEN - 10GBASE-EW Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGEWEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGEWEN_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGEWEN_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGLWEN_MASK (0x4U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGLWEN_SHIFT (2U)
/*! XGLWEN - 10GBASE-LW Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGLWEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGLWEN_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGLWEN_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGSWEN_MASK (0x8U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGSWEN_SHIFT (3U)
/*! XGSWEN - 10GBASE-SW Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGSWEN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGSWEN_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_XGSWEN_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LX4_ABL_MASK (0x10U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LX4_ABL_SHIFT (4U)
/*! LX4_ABL - 10GBASE-LX4 Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LX4_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LX4_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LX4_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_ER_ABL_MASK (0x20U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_ER_ABL_SHIFT (5U)
/*! ER_ABL - 10GBASE-ER Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_ER_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_ER_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_ER_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LR_ABL_MASK (0x40U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LR_ABL_SHIFT (6U)
/*! LR_ABL - 10GBASE-LR Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LR_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LR_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_LR_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_SR_ABL_MASK (0x80U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_SR_ABL_SHIFT (7U)
/*! SR_ABL - 10GBASE-SR Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_SR_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_SR_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_SR_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TD_ABL_MASK (0x100U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TD_ABL_SHIFT (8U)
/*! TD_ABL - PMA TX Disable Ability */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TD_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TD_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TD_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_EXT_ABL_MASK (0x200U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_EXT_ABL_SHIFT (9U)
/*! EXT_ABL - Extended Ability */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_EXT_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_EXT_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_EXT_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_RF_MASK  (0x400U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_RF_SHIFT (10U)
/*! RF - Receiver Fault (LH Type) */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_RF(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_RF_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_RF_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TF_MASK  (0x800U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TF_SHIFT (11U)
/*! TF - Transmitter Fault */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TF(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TF_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_TF_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PRFA_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PRFA_SHIFT (12U)
/*! PRFA - PMA RX Fault Ability */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PRFA(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PRFA_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PRFA_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PTFA_MASK (0x2000U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PTFA_SHIFT (13U)
/*! PTFA - PMA TX Fault Ability */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PTFA(x)  (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PTFA_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_PTFA_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_DP_MASK  (0xC000U)
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_DP_SHIFT (14U)
/*! DP - Device Present Status
 *  0b10..PMA MMD is present and responding to this register address
 *  *..PMA MMD is not present or not functioning properly
 */
#define ENET_PHY_PMA_MMD_SR_PMA_STATUS2_DP(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_STATUS2_DP_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_STATUS2_DP_MASK)
/*! @} */

/*! @name SR_PMA_TX_DIS - SR PMA MMD Transmit Disable */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_GTD_MASK  (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_GTD_SHIFT (0U)
/*! GTD - Global Transmit Disable */
#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_GTD(x)    (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_GTD_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_GTD_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_SHIFT (1U)
/*! PMA_TX_DIS_0 - Transmit Disable on Lane 0 */
#define ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TX_DIS_PMA_TX_DIS_0_MASK)
/*! @} */

/*! @name SR_PMA_RX_SIG_DET - SR PMA MMD Receive Signal Detect */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_SHIFT (0U)
/*! RX_DET - Global Receive Signal Detect */
#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_RX_DET_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_SHIFT (1U)
/*! PMA_RX_DET_0 - Receive Signal Detect on Lane 0 */
#define ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_RX_SIG_DET_PMA_RX_DET_0_MASK)
/*! @} */

/*! @name SR_PMA_EXT_ABL - SR PMA or PMD Extended Ability */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_SHIFT (0U)
/*! XGBCX4_ABL - 10GBASE-CX4 Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBCX4_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_SHIFT (1U)
/*! XGBLRM_ABL - 10GBASE-LRM Capable
 *  0b1..10GBASE-R PCS configuration
 *  0b0..All other configurations
 */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBLRM_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_MASK (0x4U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_SHIFT (2U)
/*! XGBT_ABL - 10GBASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_XGBT_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_MASK (0x20U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_SHIFT (5U)
/*! GBT_ABL - 1000BASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_GBT_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_MASK (0x80U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_SHIFT (7U)
/*! R_100BT_ABL - 100BASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_100BT_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_MASK (0x100U)
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_SHIFT (8U)
/*! R_10BT_ABL - 10BASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_EXT_ABL_R_10BT_ABL_MASK)
/*! @} */

/*! @name SR_PMA_PKG1 - SR PMA MMD Package Identifier 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_SHIFT (0U)
/*! PMA_PKG_OUI_3_18 - Organizationally Unique Identifier */
#define ENET_PHY_PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_PKG1_PMA_PKG_OUI_3_18_MASK)
/*! @} */

/*! @name SR_PMA_PKG2 - SR PMA MMD Package Identifier 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_MASK (0xFU)
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_SHIFT (0U)
/*! PMA_PKG_RN_3_0 - Revision Number */
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_RN_3_0_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_MASK (0x3F0U)
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_SHIFT (4U)
/*! PMA_PKG_MMN_5_0 - Model Number */
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_MMN_5_0_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_MASK (0xFC00U)
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_SHIFT (10U)
/*! PMA_PKG_OUI_19_24 - Organizationally Unique Identifier */
#define ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_PKG2_PMA_PKG_OUI_19_24_MASK)
/*! @} */

/*! @name SR_PMA_2PT5G_5G_EXT_ABL - SR PMA MMD 2.5G/5G Extended Ability */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_SHIFT (0U)
/*! ABL_2PT5GT - 2.5GBASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_2PT5GT_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_SHIFT (1U)
/*! ABL_5GT - 5GBASE-T Capable */
#define ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_2PT5G_5G_EXT_ABL_ABL_5GT_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_PMA_ABL - SR PMA MMD Time Sync Capability */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_MASK (0x1U)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_SHIFT (0U)
/*! PMA_RX_DLY_ABL - PMA Receive Path Data Delay Information Available */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_RX_DLY_ABL_MASK)

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_MASK (0x2U)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_SHIFT (1U)
/*! PMA_TX_DLY_ABL - PMA Transmit Path Data Delay Information Available */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_PMA_ABL_PMA_TX_DLY_ABL_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR - SR PMA MMD Time Sync TX Max Delay Lower */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_SHIFT (0U)
/*! PMA_TX_MAX_DLY_LWR - Maximum Data Delay in TX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_LWR_PMA_TX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR - SR PMA MMD Time Sync TX Max Delay Upper */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_SHIFT (0U)
/*! PMA_TX_MAX_DLY_UPR - Maximum Data Delay in TX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MAX_DLY_UPR_PMA_TX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR - SR PMA MMD Time Sync TX Min Delay Lower */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_SHIFT (0U)
/*! PMA_TX_MIN_DLY_LWR - Minimum Data Delay in TX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_LWR_PMA_TX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR - SR PMA MMD Time Sync TX Min Delay Upper */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_SHIFT (0U)
/*! PMA_TX_MIN_DLY_UPR - Minimum Data Delay in TX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_TX_MIN_DLY_UPR_PMA_TX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR - SR PMA MMD Time Sync RX Max Delay Lower */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_SHIFT (0U)
/*! PMA_RX_MAX_DLY_LWR - Maximum Data Delay in RX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_LWR_PMA_RX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR - SR PMA MMD Time Sync RX Max Delay Upper */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_SHIFT (0U)
/*! PMA_RX_MAX_DLY_UPR - Maximum Data Delay in RX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MAX_DLY_UPR_PMA_RX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR - SR PMA MMD Time Sync RX Min Delay Lower */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_SHIFT (0U)
/*! PMA_RX_MIN_DLY_LWR - Minimum Data Delay in RX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_LWR_PMA_RX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR - SR PMA MMD Time Sync RX Min Delay Upper */
/*! @{ */

#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_SHIFT (0U)
/*! PMA_RX_MIN_DLY_UPR - Minimum Data Delay in RX Path */
#define ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_SHIFT)) & ENET_PHY_PMA_MMD_SR_PMA_TIME_SYNC_RX_MIN_DLY_UPR_PMA_RX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name VR_PMA_DIG_CTRL1 - VR PMA MMD Digital Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
/*! BYP_PWRUP - Bypass Power-Up Sequence
 *  0b1..DWC_XPCS bypasses the normal flow of the power-up sequence and reaches the Power_Good state to enable transmission or reception
 *  0b0..DWC_XPCS waits for the MPLL, TX, or RX PLL status from the Synopsys PHY before resuming the normal transmission and reception
 */
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_SHIFT)) & ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_BYP_PWRUP_MASK)

#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
/*! DTXLANED_0 - TX Disable on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_DTXLANED_0_MASK)

#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_MASK (0x800U)
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_SHIFT (11U)
/*! PWRSV - Power Save
 *  0b0..Normal operation
 *  0b1..DWC_XPCS and the PHY enter the power-save mode
 */
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_SHIFT)) & ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_PWRSV_MASK)

#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_SHIFT (15U)
/*! VR_RST - Vendor-specific Soft Reset (RW, SC Type)
 *  0b1..DWC_XPCS initiates the reset for all the internal blocks except the Management Interface block and the CSR block
 */
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_SHIFT)) & ENET_PHY_PMA_MMD_VR_PMA_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_PMA_DIG_STS - VR PMA MMD Digital Status */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_MASK (0x1CU)
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_SHIFT (2U)
/*! PSEQ_STATE - Power Up Sequence State
 *  0b000..Wait for MPLL ON (for Synopsys multi-protocol 6G PHY), Wait for ACK High 0 (for Synopsys multi-protocol 12G/16G/25G/32G PHY)
 *  0b001..Wait for TX up (6G PHY), Wait for ACK Low 0 (12G/16G/25G/32G PHY)
 *  0b010..Wait for RX up (6G PHY), Wait for ACK High 1 (12G/16G/25G/32G PHY)
 *  0b011..TX/RX Stable (Power_Good state) (6G PHY), Wait for ACK Low 1 (12G/16G/25G/32G PHY)
 *  0b100..TX/RX Stable (Power_Good state)
 *  0b101..Wait for RX down (MPLL still ON) (6G PHY), Power Save state (12G/16G/25G/32G PHY)
 *  0b110..MPLL OFF (6G PHY), Power Down state (12G/16G/25G/32G PHY)
 *  0b111..Other intermediate states (valid only for 32G PHY configurations)
 */
#define ENET_PHY_PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_SHIFT)) & ENET_PHY_PMA_MMD_VR_PMA_DIG_STS_PSEQ_STATE_MASK)
/*! @} */

/*! @name VR_XS_PMA_RX_LSTS - VR XS or PMA PHY RX Lane Status */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_SIG_DET_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_SIG_DET_0_SHIFT (4U)
/*! SIG_DET_0 - RX Signal Detect for Lane 0
 *  0b1..Lane 0 signal is detected
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_SIG_DET_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_SIG_DET_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_SIG_DET_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_PLL_STATE_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_PLL_STATE_0_SHIFT (8U)
/*! RX_PLL_STATE_0 - RX DPLL State for Lane 0
 *  0b1..Lane 0 RX is successful
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_PLL_STATE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_PLL_STATE_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_PLL_STATE_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0_SHIFT (12U)
/*! RX_VALID_0 - DPLL Lock Status for Lane 0
 *  0b1..Lane 0 DPLL bit is locked
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_3_1_MASK (0xE000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_3_1_SHIFT (13U)
/*! RX_VALID_3_1 - DPLL Lock Status for Lanes [3:1]
 *  0bxx1..Lane 1 DPLL bit is locked
 *  0bx1x..Lane 2 DPLL bit is locked
 *  0b1xx..Lane 3 DPLL bit is locked
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_RX_LSTS_RX_VALID_3_1_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX General 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_SHIFT (0U)
/*! TXBCN_EN_0 - TX Beaconing Enable on lane 0 of PHY
 *  0b1..PHY enables transmitter beaconing (LFPS)
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_SHIFT (4U)
/*! TX_INV_0 - TX Invert on Lane 0 of PHY
 *  0b1..The data on PHY TX serial lines are logically inverted
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_SHIFT (8U)
/*! TX_RST_0 - TX Reset on Lane 0 of PHY
 *  0b1..PHY transmitter is reset, including common-mode adjustment and receiver detection state machines
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_SHIFT (12U)
/*! TX_DT_EN_0 - TX Data Enable on Lane 0 of PHY
 *  0b1..Transmit Output Driver in the PHY is enabled
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX General 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_SHIFT (0U)
/*! DET_RX_REQ_0 - Transmitter RX-Detection Request on Lane 0 of PHY
 *  0b1..A receiver detection request is made towards the PHY on lane 0
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_SHIFT (4U)
/*! VBOOST_EN_0 - TX Voltage Boost Enable on Lane 0 of PHY
 *  0b1..The current mode TX Swing boost in the PHY is enabled
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_MASK (0x700U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_SHIFT (8U)
/*! VBOOST_LVL - TX Voltage Boost Maximum Level */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_SHIFT (12U)
/*! TX_CLK_RDY_0 - Transmitter Input Clock Ready on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_TX_GENCTRL2 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY TX General 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_SHIFT (0U)
/*! TX_REQ_0 - Transmitter Operation Request on Lane 0 of E12G/E16G PHY (RW, SC Type) */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_SHIFT (4U)
/*! TX_LPD_0 - Transmitter Lane Power Down on Lane 0 of PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_LPD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK (0x300U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_SHIFT (8U)
/*! TX0_WIDTH - TX Datapath Width on Lane 0 of the PHY
 *  0b00..8-bit
 *  0b01..10-bit
 *  0b10..16-bit
 *  0b11..20-bit
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Boost Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_MASK (0xFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_SHIFT (0U)
/*! TX0_IBOOST - TX Current Boost Level on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Rate Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK (0x7U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_SHIFT (0U)
/*! TX0_RATE - TX Date Rate on Lane 0 of the PHY
 *  0b000..Baud
 *  0b001..Baud/2
 *  0b010..Baud/4
 *  0b011..Baud/8
 *  0b111..Baud/10
 *  0b100-0b110..Not supported
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK)
/*! @} */

/*! @name MP_12G_16G_25G_TX_POWER_STATE_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Power State */
/*! @{ */

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK (0x3U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_SHIFT (0U)
/*! TX0_PSTATE - TX Power State Control for Lane 0 of PHY
 *  0b00..P0
 *  0b01..P0s
 *  0b10..P1
 *  0b11..P2
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_SHIFT (8U)
/*! TX_DISABLE_0 - Transmitter Disable on Lane 0 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Equalization Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_MASK (0x3FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_SHIFT (0U)
/*! TX_EQ_PRE - TX Pre-Emphasis Level Adjustment Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_MASK (0x3F00U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_SHIFT (8U)
/*! TX_EQ_MAIN - Control for Setting TX Driver Output Amplitude */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Equalization Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_MASK (0x3FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_SHIFT (0U)
/*! TX_EQ_POST - TX Post-Emphasis Level Adjustment Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_TX_GENCTRL3 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX General Control 3 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL3_TXUP_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL3_TXUP_TERM_OFFSET_SHIFT (0U)
/*! TXUP_TERM_OFFSET - Offset for TX Up Termination */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL3_TXUP_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL3_TXUP_TERM_OFFSET_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL3_TXUP_TERM_OFFSET_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_TX_GENCTRL4 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX General Control 4 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL4_TXDN_TERM_OFFSET_MASK (0x1FFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL4_TXDN_TERM_OFFSET_SHIFT (0U)
/*! TXDN_TERM_OFFSET - Offset for TX Down Termination */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL4_TXDN_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL4_TXDN_TERM_OFFSET_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_GENCTRL4_TXDN_TERM_OFFSET_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY TX Miscellaneous Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC_SHIFT (0U)
/*! TX0_MISC - TX Miscellaneous Control for Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_TX_MISC_CTRL0_TX0_MISC_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_TX_STS - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY TX Status */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_TX_ACK_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_TX_ACK_0_SHIFT (0U)
/*! TX_ACK_0 - TX Acknowledge on Lane 0 of PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_TX_ACK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_TX_ACK_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_TX_ACK_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_SHIFT (4U)
/*! DETRX_RSLT_0 - Receiver Detection Result on Lane 0 of PHY
 *  0b0..Receiver not detected
 *  0b1..Receiver detected
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX General Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_SHIFT (0U)
/*! RX_TERM_EN_0 - RX Termination Enable on Lane 0 of PHY
 *  0b0..The termination is in high impedance
 *  0b1..PHY RX is terminated with a nominal 50 ohm resistance
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_SHIFT (4U)
/*! RX_ALIGN_EN_0 - RX Data Alignment Enable on Lane 0 of Multi-Protocol 12G PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_MASK (0xE0U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_SHIFT (5U)
/*! RX_ALIGN_EN_3_1 - RX Data Alignment Enable on Lanes [3:1] of Multi-Protocol 12G PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_SHIFT (8U)
/*! RX_DT_EN_0 - RX Data Enable on Lane 0 of PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_SHIFT (12U)
/*! RX_CLKSFT_0 - RX Clock Shift on Lane 0 of Multi-Protocol 12G PHY
 *  0b1..1-bit shift of receive data happens relate to receive clock
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_MASK (0xE000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_SHIFT (13U)
/*! RX_CLKSFT_3_1 - RX Clock Shift on Lanes [3:1] of Multi-Protocol 12G PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_MASK)
/*! @} */

/*! @name MP_12G_16G_25G_RX_GENCTRL1 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX General Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_SHIFT (0U)
/*! RX_INV_0 - RX Data Invert on Lane 0 of PHY
 *  0b1..The data on PHY RX serial lines are logically inverted
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_SHIFT (4U)
/*! RX_RST_0 - RX Reset on Lane 0 of PHY
 *  0b1..RX data path, all the receiver settings and state machines of the PHY are reset
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_SHIFT (8U)
/*! RX_TERM_ACDC_0 - RX Termination Control on Lane 0 of PHY
 *  0b0..DC Termination (Floating RX)
 *  0b1..AC Termination (Grounded RX)
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_SHIFT (12U)
/*! RX_DIV16P5_CLK_EN_0 - Receiver Divide by 16
 *  0b1..Enables the divide by 16.5 RX VCO recovered clock of the PHY
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_RX_GENCTRL2 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY RX General Control 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_SHIFT (0U)
/*! RX_REQ_0 - Receiver Operation Request on Lane 0 of PHY (RW, SC Type)
 *  0b1..A new receiver setting request is made towards the PHY
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_SHIFT (4U)
/*! RX_LPD_0 - Receiver Lane Power Down on Lane 0 of PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_LPD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK (0x300U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_SHIFT (8U)
/*! RX0_WIDTH - RX Datapath Width on Lane 0 of the PHY
 *  0b00..8-bit
 *  0b01..10-bit
 *  0b10..16-bit
 *  0b11..20-bit
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_RX_GENCTRL3 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY RX General Control 3 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_MASK (0x7U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_SHIFT (0U)
/*! LOS_TRSHLD_0 - Loss of Signal Threshold on Lane 0 of PHY
 *  0b000..Reserved
 *  0b001..90 mVpp
 *  0b010..120 mVpp
 *  0b011..150 mVpp
 *  0b100..180 mVpp
 *  0b101..210 mVpp
 *  0b110..240 mVpp
 *  0b111..270 mVpp
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_SHIFT (12U)
/*! LOS_LFPS_EN_0 - RX LOS LFPS Enable on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Rate Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK (0x3U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_SHIFT (0U)
/*! RX0_RATE - RX Date Rate on Lane 0 of the PHY
 *  0b00..Baud
 *  0b01..Baud/2
 *  0b10..Baud/4
 *  0b11..Baud/8
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK)
/*! @} */

/*! @name MP_12G_16G_25G_RX_POWER_STATE_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Power State */
/*! @{ */

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK (0x3U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_SHIFT (0U)
/*! RX0_PSTATE - RX Power State Control for Lane 0 of PHY
 *  0b00..P0
 *  0b01..P0s
 *  0b10..P1
 *  0b11..P2
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_SHIFT (8U)
/*! RX_DISABLE_0 - Receiver Disable on Lane 0 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK)

#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_SHIFT (12U)
/*! EEE_OVR_RIDE - RX Power State Override Control During EEE
 *  0b1..Override the behavior of DWC_XPCS
 */
#define ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_SHIFT)) & ENET_PHY_PMA_MMD_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX CDR Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_SHIFT (4U)
/*! CDR_SSC_EN_0 - RX CDR SSC Mode Enable on Lane 0 of the PHY
 *  0b1..Receive data has a spread spectrum clock
 *  0b0..Receive data does not have SSC
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Attenuation Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK (0x7U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_SHIFT (0U)
/*! RX0_EQ_ATT_LVL - RX Equalization Attenuation Level for Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Equalization Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK (0x1FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_SHIFT (0U)
/*! CTLE_BOOST_0 - RX Equalization CTLE Boost Value on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0_MASK (0x60U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0_SHIFT (5U)
/*! CTLE_POLE_0 - RX Equalization CTLE Pole Value on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_CTLE_POLE_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0_MASK (0x700U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0_SHIFT (8U)
/*! VGA2_GAIN_0 - RX Equalization VGA2 Gain on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA2_GAIN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0_MASK (0x7000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0_SHIFT (12U)
/*! VGA1_GAIN_0 - RX Equalization VGA1 Gain on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL0_VGA1_GAIN_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Equalization Control 4 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_SHIFT (0U)
/*! CONT_ADAPT_0 - Receiver Adaptation Continuous Operation on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_SHIFT (4U)
/*! CONT_OFF_CAN_0 - Receiver Offset Cancellation Continuous Operation on Lane 0
 *  0b0..Offset cancellation runs when receiver exits P2 power state
 *  0b1..Continuous receiver offset cancellation enabled
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_SHIFT (12U)
/*! RX_AD_REQ - Receive Adaptation Request */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Equalization Control 5 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0_SHIFT (0U)
/*! RX_ADPT_SEL_0 - Select Storage Bank for RX Adaptation on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_SEL_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_MASK (0x30U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_SHIFT (4U)
/*! RX0_ADPT_MODE - RX Adaptation for Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX0_ADPT_MODE_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_PROG_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_PROG_0_SHIFT (12U)
/*! RX_ADPT_PROG_0 - Receiver Adaptation in Progress - Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_PROG_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_PROG_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_ADPT_PROG_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_AD_PROG_3_1_MASK (0xE000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_AD_PROG_3_1_SHIFT (13U)
/*! RX_AD_PROG_3_1 - Receiver Adaptation in Progress - Lanes 3 to 1 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_AD_PROG_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_AD_PROG_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_EQ_CTRL5_RX_AD_PROG_3_1_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY DFE Tap Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_SHIFT (0U)
/*! DFE_TAP1_0 - RX Equalization DFE Tap1 Value on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_RX_STS - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY RX Status */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_RX_ACK_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_RX_ACK_0_SHIFT (0U)
/*! RX_ACK_0 - RX Acknowledge on Lane 0 of PHY
 *  0b1..The requested receiver setting is complete
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_RX_ACK_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_RX_ACK_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_RX_ACK_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_0_SHIFT (4U)
/*! LF_SD_0 - Low-Frequency Signal Detect on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_3_1_MASK (0xE0U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_3_1_SHIFT (5U)
/*! LF_SD_3_1 - Low-Frequency Signal Detect on Lanes 1-3 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_LF_SD_3_1_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_0_SHIFT (8U)
/*! HF_SD_0 - High-Frequency Signal Detect on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_3_1_MASK (0xE00U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_3_1_SHIFT (9U)
/*! HF_SD_3_1 - High-Frequency Signal Detect on Lanes 1-3 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_RX_STS_HF_SD_3_1_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_PPM_STS0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX PPM Status 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_MASK (0x3FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_SHIFT (0U)
/*! RX0_PPM_DRIFT - RX CDR PPM Drift on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_VLD_MASK (0x80U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_VLD_SHIFT (7U)
/*! RX0_PPM_DRIFT_VLD - RX CDR PPM Drift Valid on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_VLD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_VLD_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_STS0_RX0_PPM_DRIFT_VLD_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_RX_CDR_CTRL1 - VR XS or PMA Synopsys Multi-Protocol 16G PHY RX CDR Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_SHIFT (0U)
/*! VCO_TEMP_COMP_EN_0 - RX_CDR VCO Temperature Compensation Enable Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_TEMP_COMP_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_SHIFT (4U)
/*! VCO_STEP_CTRL_0 - RX_CDR VCO Step Control Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_STEP_CTRL_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_MASK (0x300U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_SHIFT (8U)
/*! VCO_FRQBAND_0 - RX CDR VCO Frequency Band Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_RX_CDR_CTRL1_VCO_FRQBAND_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX PPM Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_MASK (0x1FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_SHIFT (0U)
/*! RX0_CDR_PPM_MAX - Maximum Allowed PPM on the RX0 CDR Clock */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_PPM_CTRL0_RX0_CDR_PPM_MAX_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_GENCTRL4 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX General Control 4 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_TERM_OFFSET_MASK (0x1FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_TERM_OFFSET_SHIFT (0U)
/*! RX_TERM_OFFSET - Offset for RX Termination */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_TERM_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_TERM_OFFSET_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_TERM_OFFSET_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_SHIFT (8U)
/*! RX_DFE_BYP_0 - RX DFE Bypass Enable on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_DFE_BYP_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_0_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_0_SHIFT (12U)
/*! RX_125MHZ_CLK_EN_0 - RX 125 MHz Clock Generation Enable on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_3_1_MASK (0xE000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_3_1_SHIFT (13U)
/*! RX_125MHZ_CLK_EN_3_1 - RX 125MHz clock generation Enable on Lane 3 to 1 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_3_1_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_GENCTRL4_RX_125MHZ_CLK_EN_3_1_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX Miscellaneous Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_SHIFT (0U)
/*! RX0_MISC - RX Miscellaneous Control for Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_MISC_CTRL0_RX0_MISC_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY RX IQ Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_MARGIN_IQ_MASK (0x7FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_MARGIN_IQ_SHIFT (0U)
/*! RX0_MARGIN_IQ - Value of RX IQ Margining on Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_MARGIN_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_MARGIN_IQ_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_MARGIN_IQ_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK (0xF00U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_SHIFT (8U)
/*! RX0_DELTA_IQ - RX IQ Offset Value for Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY MPLL Common Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_SHIFT (0U)
/*! MPLL_EN_0 - TX MPLL Enable - Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_SHIFT (4U)
/*! MPLLB_SEL_0 - TX MPLLB Select - Lane 0
 *  0b1..Multi-protocol 12G/16G/25G PHYs select MPLLB to generate TX analog clocks on lane 0
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_SHIFT (0U)
/*! MPLLA_MULTIPLIER - MPLLA frequency Multiplier Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_MASK (0x700U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_SHIFT (8U)
/*! MPLLA_SSC_CLK_SEL - MPLLA Spread-Spectrum Clock Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_SHIFT (15U)
/*! MPLLA_CAL_DISABLE - MPLLA Calibration Disable
 *  0b1..Disable calibration of MPLLA by PHY firmware
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLA_CTRL1 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - MPLLA SSC Enable
 *  0b1..Enable spread-spectrum generation on mplla_div_clk output
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLA_SSC_CLK_SEL - MPLLA SSC Clock Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK (0xFFE0U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_SHIFT (5U)
/*! MPLLA_FRACN_CTRL - MPLLA Fractional Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK (0x7FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_SHIFT (0U)
/*! MPLLA_DIV_MULT - MPLLA Output Frequency Multiplier Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_MASK (0x80U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_SHIFT (7U)
/*! MPLLA_DIV_CLK_EN - Enable mplla_div_clk from PHY
 *  0b1..The frequency of mplla_div_clk from PHY is the MPLLA frequency divided by 'mplla_div_multiplier'
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_SHIFT (8U)
/*! MPLLA_DIV8_CLK_EN - MPLLA Divide by 8 Enable
 *  0b1..The frequency of the mplla_word_clk output clock from PHY is MPLLA frequency divided by 8
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK (0x200U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_SHIFT (9U)
/*! MPLLA_DIV10_CLK_EN - MPLLA Divide by 10 Enable
 *  0b1..The frequency of the mplla_word_clk output clock from PHY is MPLLA frequency divided by 10
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK (0x400U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_SHIFT (10U)
/*! MPLLA_DIV16P5_CLK_EN - MPLLA Divide by 16.5 Enable
 *  0b1..Enable output clocks derived from MPLLA based on 16.5, 33 and 66 division ratios
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK (0x1800U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_SHIFT (11U)
/*! MPLLA_TX_CLK_DIV - MPLLA TX Clock Divider */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_RECAL_BANK_SEL_MASK (0x6000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_RECAL_BANK_SEL_SHIFT (13U)
/*! MPLLA_RECAL_BANK_SEL - MPLLA Re-calibration Bank Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_RECAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_RECAL_BANK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_RECAL_BANK_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_SHIFT (15U)
/*! MPLLA_WRD_DIV2_EN - MPLLA Word Clock Divide by 2 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLB Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_SHIFT (0U)
/*! MPLLB_MULTIPLIER - MPLLB Frequency Multiplier Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_MASK (0x700U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_SHIFT (8U)
/*! MPLLB_SSC_CLK_SEL - MPLLB Spread-Spectrum Clock Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_SHIFT (15U)
/*! MPLLB_CAL_DISABLE - MPLLB Calibration Disable
 *  0b1..Disable calibration of MPLLB by PHY firmware
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLB_CTRL1 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_EN_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - MPLLB Spread Spectrum Enable
 *  0b1..Enable spread-spectrum generation on mpllb_div_clk output
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLB_SSC_CLK_SEL - MPLLB Spread Spectrum Clock Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_SSC_CLK_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK (0xFFE0U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_SHIFT (5U)
/*! MPLLB_FRACN_CTRL - MPLLB Fractional Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2 - VR XS or PMA Synopsys Multi-Protocol 12G/16G PHY MPLLB Control 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_MASK (0x7FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_SHIFT (0U)
/*! MPLLB_DIV_MULT - MPLLB Output Frequency Multiplier Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_MASK (0x80U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_SHIFT (7U)
/*! MPLLB_DIV_CLK_EN - Enable mpllb_div_clk from PHY
 *  0b1..The frequency of mpllb_div_clk output from PHY is MPLLB frequency divided by 'mpllb_div_multiplier'
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_SHIFT (8U)
/*! MPLLB_DIV8_CLK_EN - MPLLB Divide by 8 Enable
 *  0b1..The frequency of the mpllb_word_clk output clock from PHY is MPLLB frequency divided by 8
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_MASK (0x200U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_SHIFT (9U)
/*! MPLLB_DIV10_CLK_EN - MPLLB Divide by 10 Enable
 *  0b1..The frequency of the mpllb_word_clk output clock from PHY is MPLLB frequency divided by 10
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_MASK (0x1800U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_SHIFT (11U)
/*! MPLLB_TX_CLK_DIV - MPLLB TX Clock Divider */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_MASK (0x6000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_SHIFT (13U)
/*! MPLLB_RECAL_BANK_SEL - MPLLB Re-Calibration Bank Select */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLA_CTRL3 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 3 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - MPLLA Bandwidth Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLB_CTRL3 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 3 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL3_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL3_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - MPLLB Bandwidth Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL3_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL3_MPLLB_BANDWIDTH_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL3_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLA_CTRL4 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 4 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_MASK (0xFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_SHIFT (0U)
/*! MPLLA_SSC_FRQ_CNT_INT - MPLLA SSC Frequency Counter Initialization */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL4_MPLLA_SSC_FRQ_CNT_INT_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLA_CTRL5 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLA Control 5 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_SHIFT (0U)
/*! MPLLA_SSC_FRQ_CNT_PK - MPLLA SSC Frequency Counter Peak */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_FRQ_CNT_PK_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN_SHIFT (8U)
/*! MPLLA_SSC_SPD_EN - MPLLA SSC Up Spread Enable */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLA_CTRL5_MPLLA_SSC_SPD_EN_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLB_CTRL4 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 4 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT_MASK (0xFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT_SHIFT (0U)
/*! MPLLB_SSC_FRQ_CNT_INT - MPLLB SSC Frequency Counter Initialization */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL4_MPLLB_SSC_FRQ_CNT_INT_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_MPLLB_CTRL5 - VR XS or PMA Synopsys Multi-Protocol 16G PHY MPLLB Control 5 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK_SHIFT (0U)
/*! MPLLB_SSC_FRQ_CNT_PK - MPLLB SSC Frequency Counter Peak */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_FRQ_CNT_PK_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_SPD_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_SPD_EN_SHIFT (8U)
/*! MPLLB_SSC_SPD_EN - MPLLB SSC Up Spread Enable */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_SPD_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_SPD_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_MPLLB_CTRL5_MPLLB_SSC_SPD_EN_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Control 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_SHIFT (0U)
/*! TX2RX_LB_EN_0 - Enable Analog TX-to-RX Serial Loopback on Lane 0
 *  0b1..Enable serial loopback in the PHY from TX pre-driver to RX analog front-end
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_MASK (0x10U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_SHIFT (4U)
/*! RX2TX_LB_EN_0 - Enable Parallel RX-to-TX Loopback on Lane 0
 *  0b1..Recovered parallel data from PHY receiver is looped back to the transmit serializer
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_MASK (0x1F00U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_SHIFT (8U)
/*! RX_VREF_CTRL - RX Biasing Current Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_MASK (0x2000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_SHIFT (13U)
/*! RTUNE_REQ - Resistor Tuning Request
 *  0b1..Trigger a resistor tune request to the PHY
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_MASK (0x4000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_SHIFT (14U)
/*! CR_PARA_SEL - Select CR Para/APB3 Port
 *  0b0..JTAG
 *  0b1..CR parallel port
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_MASK (0x8000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_SHIFT (15U)
/*! PLL_CTRL - PLL Re-Initialization Control */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Reference Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_SHIFT (0U)
/*! REF_CLK_EN - Reference Clock Enable
 *  0b1..Enable reference clock to the PHY
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_MASK (0x2U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_SHIFT (1U)
/*! REF_USE_PAD - Use Pad Clk as Reference Clock
 *  0b1..PHY selects the clock connected to ref_pad_clk_p/m as its reference clock
 *  0b0..PHY selects the clock connected to ref_alt_clk_p/m
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_MASK (0x4U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_SHIFT (2U)
/*! REF_CLK_DIV2 - Reference Clock Divide by 2
 *  0b1..Reference clock provided to PHY gets divided by 2 internally in the PHY
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_MASK (0x38U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_SHIFT (3U)
/*! REF_RANGE - Input Reference Clock Range
 *  0b000..20 - 26 MHz
 *  0b001..26.1 - 52 MHz
 *  0b010..52.1 - 78 MHz
 *  0b011..78.1 - 104 MHz
 *  0b100..104.1 - 130 MHz
 *  0b101..130.1 - 156 MHz
 *  0b110..156.1 - 182 MHz
 *  0b111..182.1 - 200 MHz
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_MASK (0x40U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_SHIFT (6U)
/*! REF_MPLLA_DIV2 - MPLLA Reference Clock Divider Control
 *  0b1..The reference clock used for MPLLA calibration and locking can be divided by 2
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_MASK (0x80U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_SHIFT (7U)
/*! REF_MPLLB_DIV2 - MPLLB Reference Clock Divider Control
 *  0b1..The reference clock used for MPLLB calibration and locking can be divided by 2
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_SHIFT (8U)
/*! REF_RPT_CLK_EN - Repeat Reference Clock Enable
 *  0b1..'ref_repeat_clk_{p,m}' clock from PHY is enabled
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_MASK (0x1C00U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_SHIFT (10U)
/*! REF_MPLLA_DIV - MPLLA Reference Clock Division */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_MASK (0xE000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_SHIFT (13U)
/*! REF_MPLLB_DIV - MPLLB Reference Clock Division */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY VCO Calibration Load 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK (0x1FFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_SHIFT (0U)
/*! VCO_LD_VAL_0 - RX VCO Calibration Load Value on Lane 0 of the PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY VCO Calibration Reference 0 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_MASK (0x7FU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_SHIFT (0U)
/*! VCO_REF_LD_0 - RX VCO Calibration Reference Load Value - Lane 0 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_VCO_CAL_REF0_VCO_REF_LD_0_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_MISC_STS - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Status */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_FOM_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_FOM_SHIFT (0U)
/*! FOM - Figure of Merit (FOM) */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_FOM(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_FOM_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_FOM_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_SHIFT (8U)
/*! RTUNE_ACK - Acknowledgment for Resistor Tune Request */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLA_STS_MASK (0x200U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLA_STS_SHIFT (9U)
/*! MPLLA_STS - Status of MPLLA from PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLA_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLA_STS_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLA_STS_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLB_STS_MASK (0x400U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLB_STS_SHIFT (10U)
/*! MPLLB_STS - Status of MPLLB from PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLB_STS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLB_STS_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_MPLLB_STS_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_MASK (0x800U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_SHIFT (11U)
/*! REF_CLKDET_RESULT - Reference Clock Detection Result */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_MASK (0x1000U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_SHIFT (12U)
/*! RX_ADPT_ACK - Receive Adaptation Acknowledgment from PHY */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1 - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY Miscellaneous Control 1 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_SHIFT (0U)
/*! RX_LNK_UP_TIME - Wait Time Before PLL Re-Initialization */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_12G_16G_25G_SRAM - VR XS or PMA Synopsys Multi-Protocol 12G/16G/25G PHY SRAM */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_SHIFT (0U)
/*! INIT_DN - SRAM Initialization Done */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_INIT_DN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN_MASK (0x2U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN_SHIFT (1U)
/*! EXT_LD_DN - SRAM External Loading Done */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_EXT_LD_DN_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_BTLD_BYP_MASK (0x4U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_BTLD_BYP_SHIFT (2U)
/*! BTLD_BYP - SRAM Boatload Bypass */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_BTLD_BYP(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_BTLD_BYP_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_12G_16G_25G_SRAM_BTLD_BYP_MASK)
/*! @} */

/*! @name VR_XS_PMA_MP_16G_25G_MISC_CTRL2 - VR XS or PMA Synopsys Multi-Protocol 16G/25G PHY Miscellaneous Control 2 */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC_MASK (0xFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC_SHIFT (0U)
/*! SUP_MISC - Support Miscellaneous Controls */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_SUP_MISC_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_REF_CLK_DET_EN_MASK (0x100U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_REF_CLK_DET_EN_SHIFT (8U)
/*! REF_CLK_DET_EN - Reference Clock Detect Enable */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_REF_CLK_DET_EN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_REF_CLK_DET_EN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_MP_16G_25G_MISC_CTRL2_REF_CLK_DET_EN_MASK)
/*! @} */

/*! @name VR_XS_PMA_SNPS_CR_CTRL - VR XS or PMA Synopsys PHY CR Control */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_START_BUSY_MASK (0x1U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_START_BUSY_SHIFT (0U)
/*! START_BUSY - Start CR Port Access or Busy Indicator (WS, SC Type)
 *  0b0..CR port not busy
 *  0b1..CR port busy
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_START_BUSY(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_START_BUSY_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_START_BUSY_MASK)

#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_WR_RDN_MASK (0x2U)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_WR_RDN_SHIFT (1U)
/*! WR_RDN - Write or Read Indicator
 *  0b0..Read
 *  0b1..Write
 */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_WR_RDN(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_WR_RDN_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_CTRL_WR_RDN_MASK)
/*! @} */

/*! @name VR_XS_PMA_SNPS_CR_ADDR - VR XS or PMA Synopsys PHY CR Address */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_ADDR_ADDRESS_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_ADDR_ADDRESS_SHIFT (0U)
/*! ADDRESS - CR Port Address */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_ADDR_ADDRESS(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_ADDR_ADDRESS_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_ADDR_ADDRESS_MASK)
/*! @} */

/*! @name VR_XS_PMA_SNPS_CR_DATA - VR XS or PMA Synopsys CR Data */
/*! @{ */

#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_DATA_DATA_MASK (0xFFFFU)
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_DATA_DATA_SHIFT (0U)
/*! DATA - CR Port Data */
#define ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_DATA_DATA(x) (((uint16_t)(((uint16_t)(x)) << ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_DATA_DATA_SHIFT)) & ENET_PHY_PMA_MMD_VR_XS_PMA_SNPS_CR_DATA_DATA_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group ENET_PHY_PMA_MMD_Register_Masks */


/*!
 * @}
 */ /* end of group ENET_PHY_PMA_MMD_Peripheral_Access_Layer */


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


#endif  /* ENET_PHY_PMA_MMD_H_ */

