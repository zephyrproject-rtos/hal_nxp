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
**         CMSIS Peripheral Access Layer for VS_MII_MMD
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
 * @file PERI_VS_MII_MMD.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for VS_MII_MMD
 *
 * CMSIS Peripheral Access Layer for VS_MII_MMD
 */

#if !defined(PERI_VS_MII_MMD_H_)
#define PERI_VS_MII_MMD_H_                       /**< Symbol preventing repeated inclusion */

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
   -- VS_MII_MMD Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MII_MMD_Peripheral_Access_Layer VS_MII_MMD Peripheral Access Layer
 * @{
 */

/** VS_MII_MMD - Register Layout Typedef */
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
       uint8_t RESERVED_1[3568];
  __I  uint16_t SR_MII_TIME_SYNC_ABL;              /**< SR MII MMD Time Sync Capability, offset: 0xE10 */
  __I  uint16_t SR_MII_TIME_SYNC_TX_MAX_DLY_LWR;   /**< SR MII MMD Time Sync Tx Max Delay Lower, offset: 0xE12 */
  __I  uint16_t SR_MII_TIME_SYNC_TX_MAX_DLY_UPR;   /**< SR MII MMD Time Sync Tx Max Delay Upper, offset: 0xE14 */
  __I  uint16_t SR_MII_TIME_SYNC_TX_MIN_DLY_LWR;   /**< SR MII MMD Time Sync Tx Min Delay Lower, offset: 0xE16 */
  __I  uint16_t SR_MII_TIME_SYNC_TX_MIN_DLY_UPR;   /**< SR MII MMD Time Sync Tx Min Delay Upper, offset: 0xE18 */
  __I  uint16_t SR_MII_TIME_SYNC_RX_MAX_DLY_LWR;   /**< SR MII MMD Time Sync Rx Max Delay Lower, offset: 0xE1A */
  __I  uint16_t SR_MII_TIME_SYNC_RX_MAX_DLY_UPR;   /**< SR MII MMD Time Sync Rx Max Delay Upper, offset: 0xE1C */
  __I  uint16_t SR_MII_TIME_SYNC_RX_MIN_DLY_LWR;   /**< SR MII MMD Time Sync Rx Min Delay Lower, offset: 0xE1E */
  __I  uint16_t SR_MII_TIME_SYNC_RX_MIN_DLY_UPR;   /**< SR MII MMD Time Sync Rx Min Delay Upper, offset: 0xE20 */
       uint8_t RESERVED_2[61918];
  __IO uint16_t VR_MII_DIG_CTRL1;                  /**< VR MII MMD Digital Control1, offset: 0x10000 */
  __IO uint16_t VR_MII_AN_CTRL;                    /**< VR MII MMD AN Control, offset: 0x10002 */
  __IO uint16_t VR_MII_AN_INTR_STS;                /**< VR MII MMD AN Interrupt And Status, offset: 0x10004 */
  __IO uint16_t VR_MII_TC;                         /**< VR MII MMD Test Control, offset: 0x10006 */
       uint8_t RESERVED_3[2];
  __IO uint16_t VR_MII_DBG_CTRL;                   /**< VR MII MMD Debug Control, offset: 0x1000A */
  __IO uint16_t VR_MII_EEE_MCTRL0;                 /**< VR MII MMD EEE Mode Control, offset: 0x1000C */
       uint8_t RESERVED_4[2];
  __IO uint16_t VR_MII_EEE_TXTIMER;                /**< VR MII MMD EEE Tx Timer, offset: 0x10010 */
  __IO uint16_t VR_MII_EEE_RXTIMER;                /**< VR MII MMD EEE Rx Timer, offset: 0x10012 */
  __IO uint16_t VR_MII_LINK_TIMER_CTRL;            /**< VR MII MMD Link Timer Control, offset: 0x10014 */
  __IO uint16_t VR_MII_EEE_MCTRL1;                 /**< VR MII MMD EEE Mode Control 1, offset: 0x10016 */
       uint8_t RESERVED_5[8];
  __I  uint16_t VR_MII_DIG_STS;                    /**< VR MII MMD Digital Status, offset: 0x10020 */
  __I  uint16_t VR_MII_ICG_ERRCNT1;                /**< VR MII MMD Invalid Code Group Error Count 1, offset: 0x10022 */
       uint8_t RESERVED_6[12];
  __I  uint16_t VR_MII_MISC_STS;                   /**< VR MII MMD Miscellaneous Status, offset: 0x10030 */
       uint8_t RESERVED_7[14];
  __I  uint16_t VR_MII_RX_LSTS;                    /**< VR MII PHY Rx Lane Status, offset: 0x10040 */
       uint8_t RESERVED_8[30];
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_GENCTRL0; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx General 0, offset: 0x10060 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_GENCTRL1; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx General 1, offset: 0x10062 */
  __IO uint16_t VR_MII_MP_12G_16G_TX_GENCTRL2;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY Tx General 2, offset: 0x10064 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Tx Boost Control, offset: 0x10066 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_RATE_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Tx Rate Control, offset: 0x10068 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Power State, offset: 0x1006A */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Equalization Control 0, offset: 0x1006C */
  __IO uint16_t VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Equalization Control 1, offset: 0x1006E */
       uint8_t RESERVED_9[8];
  __IO uint16_t VR_MII_CONSUMER_10G_TX_TERM_CTRL;  /**< VR MII Synopsys Consumer 10G PHY Transmit Termination Control, offset: 0x10078 */
       uint8_t RESERVED_10[6];
  __I  uint16_t VR_MII_MP_12G_16G_25G_TX_STS;      /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Status, offset: 0x10080 */
       uint8_t RESERVED_11[30];
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_GENCTRL0; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx General Control 0, offset: 0x100A0 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_GENCTRL1; /**< VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Rx General Control 1, offset: 0x100A2 */
  __IO uint16_t VR_MII_MP_12G_16G_RX_GENCTRL2;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY Rx General Control 2, offset: 0x100A4 */
  __IO uint16_t VR_MII_MP_12G_16G_RX_GENCTRL3;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY Rx General Control 3, offset: 0x100A6 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_RATE_CTRL; /**< VR MII Synopsys Multi-protocol 12G/16G/25G PHY Rx Rate Control, offset: 0x100A8 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx Power State, offset: 0x100AA */
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_CDR_CTRL; /**< VR MII Synopsys Multi-protocol 12G/16G PHY/25G/32G Rx CDR Control, offset: 0x100AC */
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Rx Attenuation Control, offset: 0x100AE */
  __IO uint16_t VR_MII_MP_12G_RX_EQ_CTRL0;         /**< VR MII Synopsys Multi-Protocol 12G PHY Rx Equalization Control 0, offset: 0x100B0 */
       uint8_t RESERVED_12[6];
  __IO uint16_t VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Rx Equalization Control 4, offset: 0x100B8 */
  __IO uint16_t VR_MII_MP_12G_AFE_DFE_EN_CTRL;     /**< VR MII Synopsys Multi-Protocol 12G PHY AFE-DFE Enable, offset: 0x100BA */
  __IO uint16_t VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY DFE Tap Control 0, offset: 0x100BC */
       uint8_t RESERVED_13[2];
  __I  uint16_t VR_MII_MP_12G_16G_25G_RX_STS;      /**< VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx Status, offset: 0x100C0 */
       uint8_t RESERVED_14[6];
  __IO uint16_t VR_MII_CONSUMER_10G_RX_TERM_CTRL;  /**< VR MII Synopsys Consumer 10G PHY Receive Termination Control, offset: 0x100C8 */
       uint8_t RESERVED_15[12];
  __IO uint16_t VR_MII_CONSUMER_10G_RX_IQ_CTRL0;   /**< VR MII Synopsys Consumer 10G PHY RX IQ Control 0, offset: 0x100D6 */
       uint8_t RESERVED_16[8];
  __IO uint16_t VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL; /**< VR MII Synopsys Multi-Protocol 12G/16G/25G PHY MPLL Common Control, offset: 0x100E0 */
  __IO uint16_t VR_MII_MP_12G_16G_MPLLA_CTRL0;     /**< VR MII Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 0, offset: 0x100E2 */
  __IO uint16_t VR_MII_MP_12G_MPLLA_CTRL1;         /**< VR MII Synopsys Multi-protocol 12G PHY MPLLA Control 1, offset: 0x100E4 */
  __IO uint16_t VR_MII_MP_12G_16G_MPLLA_CTRL2;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY MPLLA Control 2, offset: 0x100E6 */
  __IO uint16_t VR_MII_MP_12G_16G_MPLLB_CTRL0;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY MPLLB Control 0, offset: 0x100E8 */
  __IO uint16_t VR_MII_MP_12G_MPLLB_CTRL1;         /**< VR MII Synopsys Multi-protocol 12G PHY MPLLB Control 1, offset: 0x100EA */
  __IO uint16_t VR_MII_MP_12G_16G_MPLLB_CTRL2;     /**< VR MII Synopsys Multi-protocol 12G/16G PHY MPLLB Control 2, offset: 0x100EC */
  __IO uint16_t VR_MII_MP_12G_MPLLA_CTRL3;         /**< VR MII Synopsys Multi-protocol 12G PHY MPLLA Control 3, offset: 0x100EE */
  __IO uint16_t VR_MII_MP_12G_MPLLB_CTRL3;         /**< VR MII Synopsys Multi-protocol 12G PHY MPLLB Control 3, offset: 0x100F0 */
       uint8_t RESERVED_17[46];
  __IO uint16_t VR_MII_MP_12G_16G_25G_MISC_CTRL0;  /**< VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Control 0, offset: 0x10120 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_REF_CLK_CTRL; /**< VR MII Synopsys Multi-protocol 12G/16G/25G PHY Reference Control, offset: 0x10122 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_VCO_CAL_LD0; /**< VR MII Synopsys Multi-protocol 12G/16G/25G PHY VCO Calibration Load 0, offset: 0x10124 */
       uint8_t RESERVED_18[6];
  __IO uint16_t VR_MII_MP_12G_VCO_CAL_REF0;        /**< VR MII Synopsys Multi-protocol 12G PHY VCO Calibration Reference 0, offset: 0x1012C */
       uint8_t RESERVED_19[2];
  __I  uint16_t VR_MII_MP_12G_16G_25G_MISC_STS;    /**< VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Status, offset: 0x10130 */
  __IO uint16_t VR_MII_MP_12G_16G_25G_MISC_CTRL1;  /**< VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Control 1, offset: 0x10132 */
       uint8_t RESERVED_20[2];
  __IO uint16_t VR_MII_MP_12G_16G_25G_SRAM;        /**< VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY SRAM, offset: 0x10136 */
       uint8_t RESERVED_21[8];
  __IO uint16_t VR_MII_SNPS_CR_CTRL;               /**< VR MII Synopsys PHY CR Control, offset: 0x10140 */
  __IO uint16_t VR_MII_SNPS_CR_ADDR;               /**< VR MII Synopsys PHY CR Address, offset: 0x10142 */
  __IO uint16_t VR_MII_SNPS_CR_DATA;               /**< VR MII Synopsys CR Data, offset: 0x10144 */
       uint8_t RESERVED_22[124];
  __IO uint16_t VR_MII_DIG_CTRL2;                  /**< VR MII MMD Digital Control 2, offset: 0x101C2 */
  __IO uint16_t VR_MII_DIG_ERRCNT_SEL;             /**< VR MII MMD Digital Error Count Select, offset: 0x101C4 */
} VS_MII_MMD_Type;

/* ----------------------------------------------------------------------------
   -- VS_MII_MMD Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup VS_MII_MMD_Register_Masks VS_MII_MMD Register Masks
 * @{
 */

/*! @name SR_MII_CTRL - SR MII MMD Control */
/*! @{ */

#define VS_MII_MMD_SR_MII_CTRL_SS5_MASK          (0x20U)
#define VS_MII_MMD_SR_MII_CTRL_SS5_SHIFT         (5U)
/*! SS5 - Reserved */
#define VS_MII_MMD_SR_MII_CTRL_SS5(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_SS5_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_SS5_MASK)

#define VS_MII_MMD_SR_MII_CTRL_SS6_MASK          (0x40U)
#define VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT         (6U)
/*! SS6 - Speed Selection */
#define VS_MII_MMD_SR_MII_CTRL_SS6(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_SS6_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_SS6_MASK)

#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK  (0x100U)
#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT (8U)
/*! DUPLEX_MODE - Duplex Mode
 *  0b0..Half duplex
 *  0b1..Full duplex
 */
#define VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_DUPLEX_MODE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK   (0x200U)
#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT  (9U)
/*! RESTART_AN - Restart Auto-Negotiation (RW,SC Type) */
#define VS_MII_MMD_SR_MII_CTRL_RESTART_AN(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_RESTART_AN_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_RESTART_AN_MASK)

#define VS_MII_MMD_SR_MII_CTRL_LPM_MASK          (0x800U)
#define VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT         (11U)
/*! LPM - Power-Down Mode
 *  0b0..Normal operation
 *  0b1..The DWC_xpcs goes to the power-down mode along with the PHY.
 */
#define VS_MII_MMD_SR_MII_CTRL_LPM(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_LPM_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_LPM_MASK)

#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK    (0x1000U)
#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT   (12U)
/*! AN_ENABLE - Enable Auto-Negotiation */
#define VS_MII_MMD_SR_MII_CTRL_AN_ENABLE(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_AN_ENABLE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_SS13_MASK         (0x2000U)
#define VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT        (13U)
/*! SS13 - Speed Selection (LSB) */
#define VS_MII_MMD_SR_MII_CTRL_SS13(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_SS13_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_SS13_MASK)

#define VS_MII_MMD_SR_MII_CTRL_LBE_MASK          (0x4000U)
#define VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT         (14U)
/*! LBE - Loopback Enable
 *  0b0..The DWC_xpcs de-asserts xpcs_loopback_en_o signal.
 *  0b1..The DWC_xpcs asserts xpcs_loopback_en_o signal.
 */
#define VS_MII_MMD_SR_MII_CTRL_LBE(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_LBE_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_LBE_MASK)

#define VS_MII_MMD_SR_MII_CTRL_RST_MASK          (0x8000U)
#define VS_MII_MMD_SR_MII_CTRL_RST_SHIFT         (15U)
/*! RST - Soft Reset (RW,SC Type) */
#define VS_MII_MMD_SR_MII_CTRL_RST(x)            (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_CTRL_RST_SHIFT)) & VS_MII_MMD_SR_MII_CTRL_RST_MASK)
/*! @} */

/*! @name SR_MII_STS - SR MII MMD Status */
/*! @{ */

#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK   (0x1U)
#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT  (0U)
/*! EXT_REG_CAP - Extended Register Capability
 *  0b0..Extended Register capability does not exist.
 *  0b1..Extended Register capability exists. This bit is always set to 1.
 */
#define VS_MII_MMD_SR_MII_STS_EXT_REG_CAP(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_SHIFT)) & VS_MII_MMD_SR_MII_STS_EXT_REG_CAP_MASK)

#define VS_MII_MMD_SR_MII_STS_LINK_STS_MASK      (0x4U)
#define VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT     (2U)
/*! LINK_STS - Link Status (RO, LL Type)
 *  0b0..Link Down
 *  0b1..Link Up
 */
#define VS_MII_MMD_SR_MII_STS_LINK_STS(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_LINK_STS_SHIFT)) & VS_MII_MMD_SR_MII_STS_LINK_STS_MASK)

#define VS_MII_MMD_SR_MII_STS_AN_ABL_MASK        (0x8U)
#define VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT       (3U)
/*! AN_ABL - Auto-negotiation Ability
 *  0b0..The DWC_xpcs is not able to perform auto-negotiation.
 *  0b1..The DWC_xpcs is able to perform auto-negotiation.
 */
#define VS_MII_MMD_SR_MII_STS_AN_ABL(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_AN_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_AN_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_RF_MASK            (0x10U)
#define VS_MII_MMD_SR_MII_STS_RF_SHIFT           (4U)
/*! RF - Remote Fault (RO, LH Type)
 *  0b0..The DWC_xpcs did not detect a remote fault.
 *  0b1..The DWC_xpcs detected a remote fault.
 */
#define VS_MII_MMD_SR_MII_STS_RF(x)              (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_RF_SHIFT)) & VS_MII_MMD_SR_MII_STS_RF_MASK)

#define VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK       (0x20U)
#define VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT      (5U)
/*! AN_CMPL - Auto-negotiation Complete
 *  0b0..The AN process is not complete
 *  0b1..The AN process is complete
 */
#define VS_MII_MMD_SR_MII_STS_AN_CMPL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_AN_CMPL_SHIFT)) & VS_MII_MMD_SR_MII_STS_AN_CMPL_MASK)

#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK    (0x40U)
#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT   (6U)
/*! MF_PRE_SUP - MF Preamble Suppression
 *  0b0..The DWC_xpcs does not accept the MDIO frames with preamble suppressed.
 *  0b1..The DWC_xpcs accepts the MDIO frames with preamble suppressed.
 */
#define VS_MII_MMD_SR_MII_STS_MF_PRE_SUP(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_SHIFT)) & VS_MII_MMD_SR_MII_STS_MF_PRE_SUP_MASK)

#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK    (0x80U)
#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT   (7U)
/*! UN_DIR_ABL - Unidirectional Ability
 *  0b0..The DWC_xpcs is able to transmit GMII only when the device has determined the valid link.
 *  0b1..The DWC_xpcs is able to transmit GMII irrespective of whether device has determined the valid link or not.
 */
#define VS_MII_MMD_SR_MII_STS_UN_DIR_ABL(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_UN_DIR_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK   (0x100U)
#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT  (8U)
/*! EXT_STS_ABL - Extended Status Information
 *  0b0..No Extended Status information is present at register address 16'h000F of this MMD device.
 *  0b1..Extended Status information is present at register address 16'h000F of this MMD device.
 */
#define VS_MII_MMD_SR_MII_STS_EXT_STS_ABL(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_EXT_STS_ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_HD100T_MASK        (0x200U)
#define VS_MII_MMD_SR_MII_STS_HD100T_SHIFT       (9U)
/*! HD100T - 100BASE-T2 Half-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_HD100T(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD100T_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD100T_MASK)

#define VS_MII_MMD_SR_MII_STS_FD100T_MASK        (0x400U)
#define VS_MII_MMD_SR_MII_STS_FD100T_SHIFT       (10U)
/*! FD100T - 100BASE-T2 Full-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_FD100T(x)          (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD100T_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD100T_MASK)

#define VS_MII_MMD_SR_MII_STS_HD10ABL_MASK       (0x800U)
#define VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT      (11U)
/*! HD10ABL - 10 Mbps Half-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_HD10ABL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD10ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD10ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_FD10ABL_MASK       (0x1000U)
#define VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT      (12U)
/*! FD10ABL - 10 Mbps Full-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_FD10ABL(x)         (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD10ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD10ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_HD100ABL_MASK      (0x2000U)
#define VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT     (13U)
/*! HD100ABL - 100BASE-X Half-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_HD100ABL(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_HD100ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_HD100ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_FD100ABL_MASK      (0x4000U)
#define VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT     (14U)
/*! FD100ABL - 100BASE-X Full-Duplex Ability */
#define VS_MII_MMD_SR_MII_STS_FD100ABL(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_FD100ABL_SHIFT)) & VS_MII_MMD_SR_MII_STS_FD100ABL_MASK)

#define VS_MII_MMD_SR_MII_STS_ABL100T4_MASK      (0x8000U)
#define VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT     (15U)
/*! ABL100T4 - 100BASE-T4 Ability */
#define VS_MII_MMD_SR_MII_STS_ABL100T4(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_STS_ABL100T4_SHIFT)) & VS_MII_MMD_SR_MII_STS_ABL100T4_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID1 - SR MII MMD Device Identifier 1 */
/*! @{ */

#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT (0U)
/*! VS_MII_DEV_OUI_3_18 - Organizationally Unique Identifier[3:18] */
#define VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID1_VS_MII_DEV_OUI_3_18_MASK)
/*! @} */

/*! @name SR_MII_DEV_ID2 - SR MII MMD Device Identifier 2 */
/*! @{ */

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK (0xFU)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT (0U)
/*! VS_MMD_DEV_RN_3_0 - Revision Number */
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_RN_3_0_MASK)

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK (0x3F0U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT (4U)
/*! VS_MMD_DEV_MMN_5_0 - Model Number */
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_MMN_5_0_MASK)

#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK (0xFC00U)
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT (10U)
/*! VS_MMD_DEV_OUI_19_24 - Organizationally Unique Identifier [19:24] */
#define VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_SHIFT)) & VS_MII_MMD_SR_MII_DEV_ID2_VS_MMD_DEV_OUI_19_24_MASK)
/*! @} */

/*! @name SR_MII_AN_ADV - SR MII MMD AN Advertisement */
/*! @{ */

#define VS_MII_MMD_SR_MII_AN_ADV_FD_MASK         (0x20U)
#define VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT        (5U)
/*! FD - Full Duplex */
#define VS_MII_MMD_SR_MII_AN_ADV_FD(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_FD_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_FD_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_HD_MASK         (0x40U)
#define VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT        (6U)
/*! HD - Half Duplex */
#define VS_MII_MMD_SR_MII_AN_ADV_HD(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_HD_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_HD_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK      (0x180U)
#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT     (7U)
/*! PAUSE - Pause Ability
 *  0b00..No Pause
 *  0b01..Asymmetric Pause towards the link partner
 *  0b10..Symmetric Pause
 *  0b11..Symmetric Pause and Asymmetric Pause towards the local device.
 */
#define VS_MII_MMD_SR_MII_AN_ADV_PAUSE(x)        (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_PAUSE_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_PAUSE_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_RF_MASK         (0x3000U)
#define VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT        (12U)
/*! RF - Remote Fault
 *  0b00..No Error
 *  0b01..Offline
 *  0b10..Link Failure
 *  0b11..Auto-negotiation Error
 */
#define VS_MII_MMD_SR_MII_AN_ADV_RF(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_RF_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_RF_MASK)

#define VS_MII_MMD_SR_MII_AN_ADV_NP_MASK         (0x8000U)
#define VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT        (15U)
/*! NP - Next Page */
#define VS_MII_MMD_SR_MII_AN_ADV_NP(x)           (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_ADV_NP_SHIFT)) & VS_MII_MMD_SR_MII_AN_ADV_NP_MASK)
/*! @} */

/*! @name SR_MII_LP_BABL - SR MII MMD AN Link Partner Base Ability */
/*! @{ */

#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK     (0x20U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT    (5U)
/*! LP_FD - Full Duplex */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_FD(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_FD_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_FD_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK     (0x40U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT    (6U)
/*! LP_HD - Half Duplex */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_HD(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_HD_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_HD_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK  (0x180U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT (7U)
/*! LP_PAUSE - Pause Ability
 *  0b00..No Pause
 *  0b01..Asymmetric Pause towards the link partner
 *  0b10..Symmetric Pause
 *  0b11..Both Symmetric Pause and Asymmetric Pause towards the local device
 */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_PAUSE_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK     (0x3000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT    (12U)
/*! LP_RF - Remote Fault
 *  0b00..No Error
 *  0b01..Offline
 *  0b10..Link Failure
 *  0b11..Auto-negotiation Error
 */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_RF(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_RF_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_RF_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK    (0x4000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT   (14U)
/*! LP_ACK - ACK Bit From The Link Partner */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_ACK(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_ACK_MASK)

#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK     (0x8000U)
#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT    (15U)
/*! LP_NP - Next Page */
#define VS_MII_MMD_SR_MII_LP_BABL_LP_NP(x)       (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_LP_BABL_LP_NP_SHIFT)) & VS_MII_MMD_SR_MII_LP_BABL_LP_NP_MASK)
/*! @} */

/*! @name SR_MII_AN_EXPN - SR MII MMD AN Expansion */
/*! @{ */

#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK   (0x2U)
#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT  (1U)
/*! PG_RCVD - Page Received (RO, LH Type)
 *  0b0..The local device did not receive a new page
 *  0b1..The local device received a new page
 */
#define VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_SHIFT)) & VS_MII_MMD_SR_MII_AN_EXPN_PG_RCVD_MASK)

#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK (0x4U)
#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT (2U)
/*! LD_NP_ABL - Local Device NP Able
 *  0b0..The local device does not have the next page ability
 *  0b1..The local device has the next page ability
 */
#define VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_SHIFT)) & VS_MII_MMD_SR_MII_AN_EXPN_LD_NP_ABL_MASK)
/*! @} */

/*! @name SR_MII_EXT_STS - SR MII MMD Extended Status */
/*! @{ */

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK (0x1000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT (12U)
/*! CAP_1G_T_HD - 1000BASE-T Half-Duplex Capable
 *  0b0..Not 1000BASE-T half-duplex capable
 *  0b1..1000BASE-T half-duplex capable
 */
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_HD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK (0x2000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT (13U)
/*! CAP_1G_T_FD - 1000BASE-T Full-Duplex Capable
 *  0b0..Not 1000BASE-T full-duplex capable
 *  0b1..1000BASE-T full-duplex capable
 */
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_T_FD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK (0x4000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT (14U)
/*! CAP_1G_X_HD - 1000BASE-X Half-Duplex Capable
 *  0b0..Not 1000BASE-X half-duplex capable
 *  0b1..1000BASE-X half-duplex capable
 */
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_HD_MASK)

#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK (0x8000U)
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT (15U)
/*! CAP_1G_X_FD - 1000BASE-X Full-Duplex Capable
 *  0b0..Not 1000BASE-X full-duplex capable
 *  0b1..1000BASE-X full-duplex capable
 */
#define VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_SHIFT)) & VS_MII_MMD_SR_MII_EXT_STS_CAP_1G_X_FD_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_ABL - SR MII MMD Time Sync Capability */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_RX_DLY_ABL_MASK (0x1U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_RX_DLY_ABL_SHIFT (0U)
/*! MII_RX_DLY_ABL - DWC_xpcs Receive Path Data Delay Information Available */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_RX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_RX_DLY_ABL_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_RX_DLY_ABL_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_TX_DLY_ABL_MASK (0x2U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_TX_DLY_ABL_SHIFT (1U)
/*! MII_TX_DLY_ABL - DWC_xpcs Transmit Path Data Delay Information Available */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_TX_DLY_ABL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_TX_DLY_ABL_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MII_TX_DLY_ABL_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_RX_DLY_MASK (0x4U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_RX_DLY_SHIFT (2U)
/*! FINE_RX_DLY - Fine Resolution Receive Path Data Delay Available */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_RX_DLY(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_RX_DLY_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_RX_DLY_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_TX_DLY_MASK (0x8U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_TX_DLY_SHIFT (3U)
/*! FINE_TX_DLY - Fine Resolution Transmit Path Data Delay Available */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_TX_DLY(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_TX_DLY_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_FINE_TX_DLY_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TXRX_NUC_MASK (0x400U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TXRX_NUC_SHIFT (10U)
/*! TXRX_NUC - Transmit Or Receive Num_Unit_Change Support Available */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TXRX_NUC(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TXRX_NUC_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TXRX_NUC_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MLS_MASK (0x800U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MLS_SHIFT (11U)
/*! MLS - Multi-lane Support
 *  0b0..DWC_xpcs does not support reporting of multi-PCS lane path data delay
 *  0b1..DWC_xpcs supports reporting of multi-PCS lane path data delay
 */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MLS(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MLS_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_MLS_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_FS_MASK (0x1000U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_FS_SHIFT (12U)
/*! TREF_FS - Timestamp Reference At First Symbol After SFD
 *  0b0..DWC_xpcs does not support data delay measurement point at the beginning of the first symbol after SFD
 *  0b1..DWC_xpcs supports data delay measurement point at the beginning of the first symbol after SFD
 */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_FS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_FS_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_FS_MASK)

#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_SFD_MASK (0x2000U)
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_SFD_SHIFT (13U)
/*! TREF_SFD - Timestamp Reference At SFD
 *  0b0..DWC_xpcs does not support data delay measurement point at the beginning of SFD
 *  0b1..DWC_xpcs supports data delay measurement point at the beginning of SFD
 */
#define VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_SFD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_SFD_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_ABL_TREF_SFD_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_TX_MAX_DLY_LWR - SR MII MMD Time Sync Tx Max Delay Lower */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_LWR_MII_TX_MAX_DLY_LWR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_LWR_MII_TX_MAX_DLY_LWR_SHIFT (0U)
/*! MII_TX_MAX_DLY_LWR - This Field Indicates The Lower 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_LWR_MII_TX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_LWR_MII_TX_MAX_DLY_LWR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_LWR_MII_TX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_TX_MAX_DLY_UPR - SR MII MMD Time Sync Tx Max Delay Upper */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_UPR_MII_TX_MAX_DLY_UPR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_UPR_MII_TX_MAX_DLY_UPR_SHIFT (0U)
/*! MII_TX_MAX_DLY_UPR - This Field Indicates The Upper 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_UPR_MII_TX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_UPR_MII_TX_MAX_DLY_UPR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_TX_MAX_DLY_UPR_MII_TX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_TX_MIN_DLY_LWR - SR MII MMD Time Sync Tx Min Delay Lower */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_LWR_MII_TX_MIN_DLY_LWR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_LWR_MII_TX_MIN_DLY_LWR_SHIFT (0U)
/*! MII_TX_MIN_DLY_LWR - This Field Indicates The Lower 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_LWR_MII_TX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_LWR_MII_TX_MIN_DLY_LWR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_LWR_MII_TX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_TX_MIN_DLY_UPR - SR MII MMD Time Sync Tx Min Delay Upper */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_UPR_MII_TX_MIN_DLY_UPR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_UPR_MII_TX_MIN_DLY_UPR_SHIFT (0U)
/*! MII_TX_MIN_DLY_UPR - This Field Indicates The Upper 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_UPR_MII_TX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_UPR_MII_TX_MIN_DLY_UPR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_TX_MIN_DLY_UPR_MII_TX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_RX_MAX_DLY_LWR - SR MII MMD Time Sync Rx Max Delay Lower */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_LWR_MII_RX_MAX_DLY_LWR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_LWR_MII_RX_MAX_DLY_LWR_SHIFT (0U)
/*! MII_RX_MAX_DLY_LWR - This Field Indicates The Lower 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_LWR_MII_RX_MAX_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_LWR_MII_RX_MAX_DLY_LWR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_LWR_MII_RX_MAX_DLY_LWR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_RX_MAX_DLY_UPR - SR MII MMD Time Sync Rx Max Delay Upper */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_UPR_MII_RX_MAX_DLY_UPR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_UPR_MII_RX_MAX_DLY_UPR_SHIFT (0U)
/*! MII_RX_MAX_DLY_UPR - This Field Indicates The Upper 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_UPR_MII_RX_MAX_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_UPR_MII_RX_MAX_DLY_UPR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_RX_MAX_DLY_UPR_MII_RX_MAX_DLY_UPR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_RX_MIN_DLY_LWR - SR MII MMD Time Sync Rx Min Delay Lower */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_LWR_MII_RX_MIN_DLY_LWR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_LWR_MII_RX_MIN_DLY_LWR_SHIFT (0U)
/*! MII_RX_MIN_DLY_LWR - This Field Indicates The Lower 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_LWR_MII_RX_MIN_DLY_LWR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_LWR_MII_RX_MIN_DLY_LWR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_LWR_MII_RX_MIN_DLY_LWR_MASK)
/*! @} */

/*! @name SR_MII_TIME_SYNC_RX_MIN_DLY_UPR - SR MII MMD Time Sync Rx Min Delay Upper */
/*! @{ */

#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_UPR_MII_RX_MIN_DLY_UPR_MASK (0xFFFFU)
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_UPR_MII_RX_MIN_DLY_UPR_SHIFT (0U)
/*! MII_RX_MIN_DLY_UPR - This Field Indicates The Upper 16-bit Of The 32-bit Value Which */
#define VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_UPR_MII_RX_MIN_DLY_UPR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_UPR_MII_RX_MIN_DLY_UPR_SHIFT)) & VS_MII_MMD_SR_MII_TIME_SYNC_RX_MIN_DLY_UPR_MII_RX_MIN_DLY_UPR_MASK)
/*! @} */

/*! @name VR_MII_DIG_CTRL1 - VR MII MMD Digital Control1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK (0x1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT (0U)
/*! PHY_MODE_CTRL - When SGMII_PHY_AN_AUTO_RESTART = Enabled Or QSGMII_PHY_AN_AUTO_RESTART = Enabled Or USXG_PHY_AN_AUTO_RESTART = Enabled: */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PHY_MODE_CTRL_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK (0x2U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT (1U)
/*! BYP_PWRUP - Bypass Power-Up Sequence */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_BYP_PWRUP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_MASK (0x4U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_SHIFT (2U)
/*! EN_2_5G_MODE - Enable 2.5G GMII Mode */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_EN_2_5G_MODE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK (0x8U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT (3U)
/*! CL37_TMR_OVR_RIDE - Over-Ride Control For CL37 Link Timer */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_TMR_OVR_RIDE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT (4U)
/*! DTXLANED_0 - Tx Lane 0 Disable */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_DTXLANED_0_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK (0x40U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT (6U)
/*! PRE_EMP - Preemption Packet Enable */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PRE_EMP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_MASK (0x80U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_SHIFT (7U)
/*! MSK_RD_ERR - Mask Running Disparity Error */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_MSK_RD_ERR_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_INIT_MASK    (0x100U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_INIT_SHIFT   (8U)
/*! INIT - Datapath Initialization Control */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_INIT(x)      (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_INIT_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_INIT_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK (0x200U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT (9U)
/*! MAC_AUTO_SW - Automatic Speed Mode Change After CL37 AN
 *  0b0..DWC_xpcs operates at the speed or in duplex mode as per the values programmed in the SR_MII_CTRL
 *       register. After the completion of CL37 AN, application must read the negotiated speed or the duplex mode from the
 *       VR_MII_AN_INTR_STS register and then program the SR_MII_CTRL register appropriately.
 *  0b1..DWC_xpcs automatically switches to the negotiated SGMII/USXGMII/QSGMII(port0) speed, after the completion of Clause 37 auto-negotiation.
 */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_MAC_AUTO_SW_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_CS_EN_MASK   (0x400U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CS_EN_SHIFT  (10U)
/*! CS_EN - Clock Stop Enable
 *  0b0..The clock cannot be stopped during LPI mode
 *  0b1..The PHY might stop the clock during LPI mode
 */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CS_EN(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_CS_EN_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_CS_EN_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK   (0x800U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT  (11U)
/*! PWRSV - Power Save
 *  0b0..Normal operation.
 *  0b1..DWC_xpcs and the PHY enter the power-save mode.
 */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_PWRSV_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_SHIFT (12U)
/*! CL37_BP - Enable Clause 37 AN In Backplane Configuration */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_CL37_BP_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK (0x2000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT (13U)
/*! EN_VSMMD1 - Enable Vendor-Specific MMD1 */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_EN_VSMMD1_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK  (0x4000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT (14U)
/*! R2TLBE - Rx To Tx Loopback Enable
 *  0b0..Loopback path is disabled
 *  0b1..Loopback path is enabled
 */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_R2TLBE_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK  (0x8000U)
#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT (15U)
/*! VR_RST - Vendor-Specific Soft Reset (RW, SC Type) */
#define VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL1_VR_RST_MASK)
/*! @} */

/*! @name VR_MII_AN_CTRL - VR MII MMD AN Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT (0U)
/*! MII_AN_INTR_EN - Clause 37 AN Complete Interrupt Enable */
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_MII_AN_INTR_EN_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK  (0x6U)
#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT (1U)
/*! PCS_MODE - When SGMII_EN = Enabled Or QSGMII_EN = Enabled:
 *  0b00..1000BASE-X mode (clause 37 auto-negotiation is as per 1000BaseX).
 *  0b10..SGMII mode (clause 37 auto-negotiation is as per SGMII).
 *  0b11..QSGMII mode (clause 37 auto-negotiation conforms to QSGMII)
 */
#define VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_PCS_MODE_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK (0x8U)
#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT (3U)
/*! TX_CONFIG - When SGMII_EN = Enabled Or QSGMII_EN = Enabled Or USXMII_EN = Enabled:
 *  0b0..Configures the DWC_xpcs as the MAC side SGMII/QSGMII/USXGMII.
 *  0b1..Configures the DWC_xpcs as the PHY side SGMII/QSGMII/USXGMII.
 */
#define VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_TX_CONFIG_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK (0x10U)
#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT (4U)
/*! SGMII_LINK_STS - When SGMII_EN = Enabled Or QSGMII_EN = Enabled Or USXGMII Link Status:
 *  0b0..Link Down
 *  0b1..Link Up
 */
#define VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_SGMII_LINK_STS_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK  (0x100U)
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT (8U)
/*! MII_CTRL - MII Control
 *  0b0..4-bit MII
 *  0b1..8-bit MII
 */
#define VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_MII_CTRL_MASK)

#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK (0x200U)
#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT (9U)
/*! IND_TX_EN - Independent Transmit Enable In 1000BASE-X/KX Mode */
#define VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_SHIFT)) & VS_MII_MMD_VR_MII_AN_CTRL_IND_TX_EN_MASK)
/*! @} */

/*! @name VR_MII_AN_INTR_STS - VR MII MMD AN Interrupt And Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK (0x1U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT (0U)
/*! CL37_ANCMPLT_INTR - Clause 37 AN Complete Interrupt (SS,WC Type) */
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANCMPLT_INTR_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK (0x1EU)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT (1U)
/*! CL37_ANSGM_STS - When SGMII_EN = Enabled Or QSGMII_EN = Enabled:
 *  0b0000..Half Duplex
 *  0b0001..Full Duplex
 *  0b1010..1000 Mbps speed link
 */
#define VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_CL37_ANSGM_STS_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_MASK (0x20U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_SHIFT (5U)
/*! LP_EEE_CAP - Link Partner EEE Capability */
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_LP_EEE_CAP_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_MASK (0x40U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_SHIFT (6U)
/*! LP_CK_STP - Link Partner EEE Clock Stop Capability */
#define VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_LP_CK_STP_MASK)

#define VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_MASK (0x7F00U)
#define VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_SHIFT (8U)
/*! USXG_AN_STS - Reserved */
#define VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_SHIFT)) & VS_MII_MMD_VR_MII_AN_INTR_STS_USXG_AN_STS_MASK)
/*! @} */

/*! @name VR_MII_TC - VR MII MMD Test Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_TC_TP_MASK             (0x3U)
#define VS_MII_MMD_VR_MII_TC_TP_SHIFT            (0U)
/*! TP - Test Pattern Select */
#define VS_MII_MMD_VR_MII_TC_TP(x)               (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_TC_TP_SHIFT)) & VS_MII_MMD_VR_MII_TC_TP_MASK)

#define VS_MII_MMD_VR_MII_TC_TPE_MASK            (0x4U)
#define VS_MII_MMD_VR_MII_TC_TPE_SHIFT           (2U)
/*! TPE - Test Pattern Enable Lanes
 *  0b0..Test pattern disabled
 *  0b1..Test pattern enabled
 */
#define VS_MII_MMD_VR_MII_TC_TPE(x)              (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_TC_TPE_SHIFT)) & VS_MII_MMD_VR_MII_TC_TPE_MASK)
/*! @} */

/*! @name VR_MII_DBG_CTRL - VR MII MMD Debug Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_DBG_CTRL_RESTAR_SYNC_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_RESTAR_SYNC_0_SHIFT (0U)
/*! RESTAR_SYNC_0 - Restart Synchronization */
#define VS_MII_MMD_VR_MII_DBG_CTRL_RESTAR_SYNC_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_RESTAR_SYNC_0_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_RESTAR_SYNC_0_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_LOS_DET_MASK (0x10U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_LOS_DET_SHIFT (4U)
/*! SUPRESS_LOS_DET - Suppress Loss Of Signal Detection */
#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_LOS_DET_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_LOS_DET_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_EEE_LOS_DET_MASK (0x20U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT (5U)
/*! SUPRESS_EEE_LOS_DET - Suppress EEE Loss Of Signal Detection */
#define VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_EEE_LOS_DET(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_EEE_LOS_DET_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_SUPRESS_EEE_LOS_DET_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_DT_EN_CTL_MASK (0x40U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_DT_EN_CTL_SHIFT (6U)
/*! RX_DT_EN_CTL - Rx Data Enable Control */
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_DT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_RX_DT_EN_CTL_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_RX_DT_EN_CTL_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_SYNC_CTL_MASK (0x80U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_SYNC_CTL_SHIFT (7U)
/*! RX_SYNC_CTL - Receive Synchronization Control */
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_SYNC_CTL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_RX_SYNC_CTL_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_RX_SYNC_CTL_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_TX_PMBL_CTL_MASK (0x100U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_TX_PMBL_CTL_SHIFT (8U)
/*! TX_PMBL_CTL - Transmit Preamble Control */
#define VS_MII_MMD_VR_MII_DBG_CTRL_TX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_TX_PMBL_CTL_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_TX_PMBL_CTL_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_PMBL_CTL_MASK (0x200U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_PMBL_CTL_SHIFT (9U)
/*! RX_PMBL_CTL - Receive Preamble Control */
#define VS_MII_MMD_VR_MII_DBG_CTRL_RX_PMBL_CTL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_RX_PMBL_CTL_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_RX_PMBL_CTL_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_SS_CORE_EN_MASK (0x400U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_SS_CORE_EN_SHIFT (10U)
/*! SS_CORE_EN - Reserved */
#define VS_MII_MMD_VR_MII_DBG_CTRL_SS_CORE_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_SS_CORE_EN_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_SS_CORE_EN_MASK)

#define VS_MII_MMD_VR_MII_DBG_CTRL_LOS_SEL_MASK  (0x2000U)
#define VS_MII_MMD_VR_MII_DBG_CTRL_LOS_SEL_SHIFT (13U)
/*! LOS_SEL - Loss-of-Signal Selection */
#define VS_MII_MMD_VR_MII_DBG_CTRL_LOS_SEL(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DBG_CTRL_LOS_SEL_SHIFT)) & VS_MII_MMD_VR_MII_DBG_CTRL_LOS_SEL_MASK)
/*! @} */

/*! @name VR_MII_EEE_MCTRL0 - VR MII MMD EEE Mode Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LTX_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LTX_EN_SHIFT (0U)
/*! LTX_EN - LPI Tx Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LTX_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_LTX_EN_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_LTX_EN_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LRX_EN_MASK (0x2U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LRX_EN_SHIFT (1U)
/*! LRX_EN - LPI Rx Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_LRX_EN(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_LRX_EN_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_LRX_EN_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_QUIET_EN_MASK (0x4U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_QUIET_EN_SHIFT (2U)
/*! TX_QUIET_EN - Tx Quiet Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_QUIET_EN_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_QUIET_EN_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_QUIET_EN_MASK (0x8U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_QUIET_EN_SHIFT (3U)
/*! RX_QUIET_EN - Rx Quiet Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_QUIET_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_QUIET_EN_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_QUIET_EN_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_EN_CTRL_MASK (0x10U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_EN_CTRL_SHIFT (4U)
/*! TX_EN_CTRL - Tx Control Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_EN_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_TX_EN_CTRL_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_SIGN_BIT_MASK (0x40U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_SIGN_BIT_SHIFT (6U)
/*! SIGN_BIT - Effective 100 Ns Tic Value */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_SIGN_BIT(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_SIGN_BIT_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_SIGN_BIT_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_EN_CTRL_MASK (0x80U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_EN_CTRL_SHIFT (7U)
/*! RX_EN_CTRL - Rx Control Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_EN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_EN_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_RX_EN_CTRL_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_MULT_FACT_100NS_MASK (0xF00U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_MULT_FACT_100NS_SHIFT (8U)
/*! MULT_FACT_100NS - 100 Ns Clock Tic Multiplying Factor */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_MULT_FACT_100NS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_MULT_FACT_100NS_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_MULT_FACT_100NS_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL0_CLKSTOP_MASK (0xF000U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_CLKSTOP_SHIFT (12U)
/*! CLKSTOP - Clock Stop */
#define VS_MII_MMD_VR_MII_EEE_MCTRL0_CLKSTOP(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL0_CLKSTOP_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL0_CLKSTOP_MASK)
/*! @} */

/*! @name VR_MII_EEE_TXTIMER - VR MII MMD EEE Tx Timer */
/*! @{ */

#define VS_MII_MMD_VR_MII_EEE_TXTIMER_TSL_RES_MASK (0x3FU)
#define VS_MII_MMD_VR_MII_EEE_TXTIMER_TSL_RES_SHIFT (0U)
/*! TSL_RES - TSL Resolution */
#define VS_MII_MMD_VR_MII_EEE_TXTIMER_TSL_RES(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_TXTIMER_TSL_RES_SHIFT)) & VS_MII_MMD_VR_MII_EEE_TXTIMER_TSL_RES_MASK)
/*! @} */

/*! @name VR_MII_EEE_RXTIMER - VR MII MMD EEE Rx Timer */
/*! @{ */

#define VS_MII_MMD_VR_MII_EEE_RXTIMER_RES_100U_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_EEE_RXTIMER_RES_100U_SHIFT (0U)
/*! RES_100U - 100 Us Resolution */
#define VS_MII_MMD_VR_MII_EEE_RXTIMER_RES_100U(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_RXTIMER_RES_100U_SHIFT)) & VS_MII_MMD_VR_MII_EEE_RXTIMER_RES_100U_MASK)

#define VS_MII_MMD_VR_MII_EEE_RXTIMER_TWR_RES_MASK (0x3F00U)
#define VS_MII_MMD_VR_MII_EEE_RXTIMER_TWR_RES_SHIFT (8U)
/*! TWR_RES - TWR Resolution */
#define VS_MII_MMD_VR_MII_EEE_RXTIMER_TWR_RES(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_RXTIMER_TWR_RES_SHIFT)) & VS_MII_MMD_VR_MII_EEE_RXTIMER_TWR_RES_MASK)
/*! @} */

/*! @name VR_MII_LINK_TIMER_CTRL - VR MII MMD Link Timer Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT (0U)
/*! CL37_LINK_TIME - Programmable Link Timer Value For Clause 37 Auto-negotiation */
#define VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_SHIFT)) & VS_MII_MMD_VR_MII_LINK_TIMER_CTRL_CL37_LINK_TIME_MASK)
/*! @} */

/*! @name VR_MII_EEE_MCTRL1 - VR MII MMD EEE Mode Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_LPI_MASK (0x1U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_LPI_SHIFT (0U)
/*! TRN_LPI - Transparent Tx LPI Mode Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_LPI(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_LPI_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_LPI_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TXEN_EA_TMR_MASK (0x7EU)
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TXEN_EA_TMR_SHIFT (1U)
/*! TXEN_EA_TMR - Transmit Enable Early Assert Time Duration */
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TXEN_EA_TMR(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL1_TXEN_EA_TMR_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL1_TXEN_EA_TMR_MASK)

#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_RXLPI_MASK (0x100U)
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_RXLPI_SHIFT (8U)
/*! TRN_RXLPI - Transparent Rx LPI Mode Enable */
#define VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_RXLPI(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_RXLPI_SHIFT)) & VS_MII_MMD_VR_MII_EEE_MCTRL1_TRN_RXLPI_MASK)
/*! @} */

/*! @name VR_MII_DIG_STS - VR MII MMD Digital Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_DIG_STS_LB_ACTIVE_MASK (0x2U)
#define VS_MII_MMD_VR_MII_DIG_STS_LB_ACTIVE_SHIFT (1U)
/*! LB_ACTIVE - Reserved */
#define VS_MII_MMD_VR_MII_DIG_STS_LB_ACTIVE(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_LB_ACTIVE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_LB_ACTIVE_MASK)

#define VS_MII_MMD_VR_MII_DIG_STS_PSEQ_STATE_MASK (0x1CU)
#define VS_MII_MMD_VR_MII_DIG_STS_PSEQ_STATE_SHIFT (2U)
/*! PSEQ_STATE - Power Up Sequence State */
#define VS_MII_MMD_VR_MII_DIG_STS_PSEQ_STATE(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_PSEQ_STATE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_PSEQ_STATE_MASK)

#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_UNDF_MASK (0x20U)
#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_UNDF_SHIFT (5U)
/*! RXFIFO_UNDF - Rx FIFO Underflow (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..FIFO underflow
 */
#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_UNDF(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_UNDF_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_UNDF_MASK)

#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_OVF_MASK (0x40U)
#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_OVF_SHIFT (6U)
/*! RXFIFO_OVF - Rx FIFO Overflow (RO, LH Type)
 *  0b0..Normal operation
 *  0b1..FIFO overflow
 */
#define VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_OVF(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_OVF_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_RXFIFO_OVF_MASK)

#define VS_MII_MMD_VR_MII_DIG_STS_LRX_STATE_MASK (0x1C00U)
#define VS_MII_MMD_VR_MII_DIG_STS_LRX_STATE_SHIFT (10U)
/*! LRX_STATE - LPI Receive State
 *  0b000..LRX_ACTIVE
 *  0b001..LRX_SLEEP
 *  0b010..LRX_QUIET
 *  0b011..LRX_WAKE
 *  0b100..LRX_WTF
 *  0b101..LRX_LINK_FAIL
 *  0b110..LRX_LPI_K
 */
#define VS_MII_MMD_VR_MII_DIG_STS_LRX_STATE(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_LRX_STATE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_LRX_STATE_MASK)

#define VS_MII_MMD_VR_MII_DIG_STS_LTX_STATE_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_DIG_STS_LTX_STATE_SHIFT (13U)
/*! LTX_STATE - LPI Transmit State
 *  0b000..LTX_ACTIVE
 *  0b001..LTX_SLEEP
 *  0b010..LTX_QUIET
 *  0b011..LTX_REF_WAKE
 *  0b100..LTX_ALERT (valid only if RPCS is present)
 *  0b101..LTX_SCR_BYP (valid only if RPCS is present)
 */
#define VS_MII_MMD_VR_MII_DIG_STS_LTX_STATE(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_STS_LTX_STATE_SHIFT)) & VS_MII_MMD_VR_MII_DIG_STS_LTX_STATE_MASK)
/*! @} */

/*! @name VR_MII_ICG_ERRCNT1 - VR MII MMD Invalid Code Group Error Count 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_ICG_ERRCNT1_EC0_MASK   (0xFFU)
#define VS_MII_MMD_VR_MII_ICG_ERRCNT1_EC0_SHIFT  (0U)
/*! EC0 - Invalid Code Group Count Lane 0 (RO, LH Type) */
#define VS_MII_MMD_VR_MII_ICG_ERRCNT1_EC0(x)     (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_ICG_ERRCNT1_EC0_SHIFT)) & VS_MII_MMD_VR_MII_ICG_ERRCNT1_EC0_MASK)
/*! @} */

/*! @name VR_MII_MISC_STS - VR MII MMD Miscellaneous Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_MISC_STS_BIT_SFT_MASK  (0xFU)
#define VS_MII_MMD_VR_MII_MISC_STS_BIT_SFT_SHIFT (0U)
/*! BIT_SFT - Bit Shift */
#define VS_MII_MMD_VR_MII_MISC_STS_BIT_SFT(x)    (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MISC_STS_BIT_SFT_SHIFT)) & VS_MII_MMD_VR_MII_MISC_STS_BIT_SFT_MASK)
/*! @} */

/*! @name VR_MII_RX_LSTS - VR MII PHY Rx Lane Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_0_SHIFT (4U)
/*! SIG_DET_0 - Rx Signal Detect For Lane 0 */
#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_0(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_0_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_0_MASK)

#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_3_1_SHIFT (5U)
/*! SIG_DET_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_3_1_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_SIG_DET_3_1_MASK)

#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_0_SHIFT (8U)
/*! RX_PLL_STATE_0 - Reserved */
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_0_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_0_MASK)

#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_3_1_SHIFT (9U)
/*! RX_PLL_STATE_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_3_1_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_RX_PLL_STATE_3_1_MASK)

#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_0_SHIFT (12U)
/*! RX_VALID_0 - DPLL Lock Status For Lane 0 */
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_0(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_0_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_0_MASK)

#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_3_1_SHIFT (13U)
/*! RX_VALID_3_1 - DPLL Lock Status For Lanes[3:1] */
#define VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_3_1_SHIFT)) & VS_MII_MMD_VR_MII_RX_LSTS_RX_VALID_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_GENCTRL0 - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx General 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_SHIFT (0U)
/*! TXBCN_EN_0 - Tx Beaconing Enable On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_3_1_SHIFT (1U)
/*! TXBCN_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TXBCN_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_SHIFT (4U)
/*! TX_INV_0 - Tx Invert On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_3_1_SHIFT (5U)
/*! TX_INV_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_INV_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_SHIFT (8U)
/*! TX_RST_0 - Tx Reset On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_3_1_SHIFT (9U)
/*! TX_RST_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_RST_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_SHIFT (12U)
/*! TX_DT_EN_0 - Tx Data Enable On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_3_1_SHIFT (13U)
/*! TX_DT_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL0_TX_DT_EN_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_GENCTRL1 - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx General 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_SHIFT (0U)
/*! DET_RX_REQ_0 - Transmitter Rx-Detection Request On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_3_1_SHIFT (1U)
/*! DET_RX_REQ_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_DET_RX_REQ_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_SHIFT (4U)
/*! VBOOST_EN_0 - Tx Voltage Boost Enable On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_3_1_SHIFT (5U)
/*! VBOOST_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_MASK (0x700U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_SHIFT (8U)
/*! VBOOST_LVL - Tx Voltage Boost Maximum Level */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_VBOOST_LVL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_SHIFT (12U)
/*! TX_CLK_RDY_0 - Transmitter Input Clock Ready On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_3_1_SHIFT (13U)
/*! TX_CLK_RDY_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_GENCTRL1_TX_CLK_RDY_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_TX_GENCTRL2 - VR MII Synopsys Multi-protocol 12G/16G PHY Tx General 2 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_SHIFT (0U)
/*! TX_REQ_0 - Transmitter Operation Request On Lane 0 Of PHY (RW,SC Type) */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_3_1_SHIFT (1U)
/*! TX_REQ_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_REQ_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_SHIFT (4U)
/*! TX_LPD_0 - Transmitter Lane Power Down On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_3_1_SHIFT (5U)
/*! TX_LPD_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX_LPD_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK (0x300U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_SHIFT (8U)
/*! TX0_WIDTH - Tx Datapath Width On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX0_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX1_WIDTH_MASK (0xC00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX1_WIDTH_SHIFT (10U)
/*! TX1_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX1_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX1_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX1_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX2_WIDTH_MASK (0x3000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX2_WIDTH_SHIFT (12U)
/*! TX2_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX2_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX2_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX2_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX3_WIDTH_MASK (0xC000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX3_WIDTH_SHIFT (14U)
/*! TX3_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX3_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX3_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_TX_GENCTRL2_TX3_WIDTH_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Tx Boost Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_MASK (0xFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_SHIFT (0U)
/*! TX0_IBOOST - Tx Current Boost Level On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_BOOST_CTRL_TX0_IBOOST_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_RATE_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Tx Rate Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK (0x7U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_SHIFT (0U)
/*! TX0_RATE - Tx Date Rate On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_RATE_CTRL_TX0_RATE_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Power State */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK (0x3U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_SHIFT (0U)
/*! TX0_PSTATE - Tx Power State Control For Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX0_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX1_PSTATE_MASK (0xCU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX1_PSTATE_SHIFT (2U)
/*! TX1_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX1_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX1_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX1_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX2_PSTATE_MASK (0x30U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX2_PSTATE_SHIFT (4U)
/*! TX2_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX2_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX2_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX2_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX3_PSTATE_MASK (0xC0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX3_PSTATE_SHIFT (6U)
/*! TX3_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX3_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX3_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX3_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_SHIFT (8U)
/*! TX_DISABLE_0 - Transmitter Disable On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_3_1_SHIFT (9U)
/*! TX_DISABLE_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_POWER_STATE_CTRL_TX_DISABLE_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0 - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Equalization Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_MASK (0x3FU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_SHIFT (0U)
/*! TX_EQ_PRE - Tx Pre-Emphasis Level Adjustment Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_PRE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_MASK (0x3F00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_SHIFT (8U)
/*! TX_EQ_MAIN - Control For Setting Tx Driver Output Amplitude */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL0_TX_EQ_MAIN_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1 - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Equalization Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_MASK (0x3FU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_SHIFT (0U)
/*! TX_EQ_POST - Tx Post-Emphasis Level Adjustment Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_POST_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_OVR_RIDE_MASK (0x40U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_OVR_RIDE_SHIFT (6U)
/*! TX_EQ_OVR_RIDE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_OVR_RIDE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_OVR_RIDE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_DEF_CTRL_MASK (0x80U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_DEF_CTRL_SHIFT (7U)
/*! TX_EQ_DEF_CTRL - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_DEF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_DEF_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_TX_EQ_DEF_CTRL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_CA_TX_EQ_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_CA_TX_EQ_SHIFT (8U)
/*! CA_TX_EQ - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_CA_TX_EQ(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_CA_TX_EQ_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_EQ_CTRL1_CA_TX_EQ_MASK)
/*! @} */

/*! @name VR_MII_CONSUMER_10G_TX_TERM_CTRL - VR MII Synopsys Consumer 10G PHY Transmit Termination Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_CONSUMER_10G_TX_TERM_CTRL_TX0_TERM_MASK (0x7U)
#define VS_MII_MMD_VR_MII_CONSUMER_10G_TX_TERM_CTRL_TX0_TERM_SHIFT (0U)
/*! TX0_TERM - Transmit Termination Control For Lane 0 */
#define VS_MII_MMD_VR_MII_CONSUMER_10G_TX_TERM_CTRL_TX0_TERM(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_CONSUMER_10G_TX_TERM_CTRL_TX0_TERM_SHIFT)) & VS_MII_MMD_VR_MII_CONSUMER_10G_TX_TERM_CTRL_TX0_TERM_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_TX_STS - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Tx Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_0_SHIFT (0U)
/*! TX_ACK_0 - Tx Acknowledge On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_3_1_SHIFT (1U)
/*! TX_ACK_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_TX_ACK_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_SHIFT (4U)
/*! DETRX_RSLT_0 - Receiver Detection Result On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_3_1_SHIFT (5U)
/*! DETRX_RSLT_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_TX_STS_DETRX_RSLT_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_GENCTRL0 - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx General Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_SHIFT (0U)
/*! RX_TERM_EN_0 - Rx Termination Enable On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_3_1_SHIFT (1U)
/*! RX_TERM_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_TERM_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_SHIFT (4U)
/*! RX_ALIGN_EN_0 - Rx Data Alignment Enable On Lane 0 Of Multi-Protocol 12G PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_SHIFT (5U)
/*! RX_ALIGN_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_ALIGN_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_SHIFT (8U)
/*! RX_DT_EN_0 - Rx Data Enable On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_3_1_SHIFT (9U)
/*! RX_DT_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_DT_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_SHIFT (12U)
/*! RX_CLKSFT_0 - Rx Clock Shift On Lane 0 Of Multi-protocol 12G PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_SHIFT (13U)
/*! RX_CLKSFT_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL0_RX_CLKSFT_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_GENCTRL1 - VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Rx General Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_SHIFT (0U)
/*! RX_INV_0 - Rx Data Invert On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_3_1_SHIFT (1U)
/*! RX_INV_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_INV_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_SHIFT (4U)
/*! RX_RST_0 - Rx Reset On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_3_1_SHIFT (5U)
/*! RX_RST_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_RST_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_SHIFT (8U)
/*! RX_TERM_ACDC_0 - Rx Termination Control On Lane 0 Of PHY
 *  0b0..DC Termination (Floating Rx)
 *  0b1..AC Termination (Grounded Rx)
 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_3_1_SHIFT (9U)
/*! RX_TERM_ACDC_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_TERM_ACDC_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_SHIFT (12U)
/*! RX_DIV16P5_CLK_EN_0 - Receiver Divide By 16.5 Output Clock On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_3_1_SHIFT (13U)
/*! RX_DIV16P5_CLK_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_GENCTRL1_RX_DIV16P5_CLK_EN_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_RX_GENCTRL2 - VR MII Synopsys Multi-protocol 12G/16G PHY Rx General Control 2 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_SHIFT (0U)
/*! RX_REQ_0 - Receiver Operation Request On Lane 0 Of PHY (RW,SC Type) */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_3_1_SHIFT (1U)
/*! RX_REQ_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_REQ_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_SHIFT (4U)
/*! RX_LPD_0 - Receiver Lane Power Down On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_3_1_SHIFT (5U)
/*! RX_LPD_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX_LPD_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK (0x300U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_SHIFT (8U)
/*! RX0_WIDTH - Rx Datapath Width On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX0_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX1_WIDTH_MASK (0xC00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX1_WIDTH_SHIFT (10U)
/*! RX1_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX1_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX1_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX1_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX2_WIDTH_MASK (0x3000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX2_WIDTH_SHIFT (12U)
/*! RX2_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX2_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX2_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX2_WIDTH_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX3_WIDTH_MASK (0xC000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX3_WIDTH_SHIFT (14U)
/*! RX3_WIDTH - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX3_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX3_WIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL2_RX3_WIDTH_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_RX_GENCTRL3 - VR MII Synopsys Multi-protocol 12G/16G PHY Rx General Control 3 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_MASK (0x7U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_SHIFT (0U)
/*! LOS_TRSHLD_0 - Loss Of Signal Threshold On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_1_MASK (0x38U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_1_SHIFT (3U)
/*! LOS_TRSHLD_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_2_MASK (0x1C0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_2_SHIFT (6U)
/*! LOS_TRSHLD_2 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_2(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_2_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_2_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_3_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_3_SHIFT (9U)
/*! LOS_TRSHLD_3 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_3(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_3_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_TRSHLD_3_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_SHIFT (12U)
/*! LOS_LFPS_EN_0 - Rx LOS LFPS Enable On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_3_1_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_3_1_SHIFT (13U)
/*! LOS_LFPS_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_RX_GENCTRL3_LOS_LFPS_EN_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_RATE_CTRL - VR MII Synopsys Multi-protocol 12G/16G/25G PHY Rx Rate Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK (0x3U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_SHIFT (0U)
/*! RX0_RATE - Rx Date Rate On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_RATE_CTRL_RX0_RATE_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx Power State */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK (0x3U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_SHIFT (0U)
/*! RX0_PSTATE - Rx Power State Control For Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX0_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX1_PSTATE_MASK (0xCU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX1_PSTATE_SHIFT (2U)
/*! RX1_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX1_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX1_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX1_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX2_PSTATE_MASK (0x30U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX2_PSTATE_SHIFT (4U)
/*! RX2_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX2_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX2_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX2_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX3_PSTATE_MASK (0xC0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX3_PSTATE_SHIFT (6U)
/*! RX3_PSTATE - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX3_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX3_PSTATE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX3_PSTATE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_SHIFT (8U)
/*! RX_DISABLE_0 - Receiver Disable On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_3_1_SHIFT (9U)
/*! RX_DISABLE_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_RX_DISABLE_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_SHIFT (12U)
/*! EEE_OVR_RIDE - Rx Power State Override Control During EEE */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_POWER_STATE_CTRL_EEE_OVR_RIDE_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_CDR_CTRL - VR MII Synopsys Multi-protocol 12G/16G PHY/25G/32G Rx CDR Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_0_SHIFT (0U)
/*! CDR_TRACK_EN_0 - Rx CDR Tracking Enable On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_3_1_SHIFT (1U)
/*! CDR_TRACK_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_TRACK_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_SHIFT (4U)
/*! CDR_SSC_EN_0 - Rx CDR SSC Mode Enable On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_3_1_SHIFT (5U)
/*! CDR_SSC_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_CDR_SSC_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_0_SHIFT (8U)
/*! VCO_LOW_FREQ_0 - Rx VCO Lower Frequency Band Mode On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_3_1_SHIFT (9U)
/*! VCO_LOW_FREQ_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_CDR_CTRL_VCO_LOW_FREQ_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Rx Attenuation Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK (0x7U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_SHIFT (0U)
/*! RX0_EQ_ATT_LVL - Rx Equalization Attenuation Level For Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_ATTN_CTRL_RX0_EQ_ATT_LVL_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_RX_EQ_CTRL0 - VR MII Synopsys Multi-Protocol 12G PHY Rx Equalization Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK (0x1FU)
#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_CTLE_BOOST_0_SHIFT (0U)
/*! CTLE_BOOST_0 - Rx Equalization CTLE Boost Value On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_CTLE_BOOST_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_CTLE_BOOST_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_CTLE_BOOST_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_AFE_GAIN_0_MASK (0xF000U)
#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_AFE_GAIN_0_SHIFT (12U)
/*! AFE_GAIN_0 - Rx Equalization AFE Gain On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_AFE_GAIN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_AFE_GAIN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_RX_EQ_CTRL0_AFE_GAIN_0_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4 - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY Rx Equalization Control 4 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_SHIFT (0U)
/*! CONT_ADAPT_0 - Receiver Adaptation Continuous Operation On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_3_1_SHIFT (1U)
/*! CONT_ADAPT_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_ADAPT_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_SHIFT (4U)
/*! CONT_OFF_CAN_0 - Receiver Offset Cancellation Continuous Operation On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_3_1_SHIFT (5U)
/*! CONT_OFF_CAN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_CONT_OFF_CAN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_SHIFT (12U)
/*! RX_AD_REQ - Receive Adaptation Request */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_EQ_CTRL4_RX_AD_REQ_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_AFE_DFE_EN_CTRL - VR MII Synopsys Multi-Protocol 12G PHY AFE-DFE Enable */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_0_SHIFT (0U)
/*! AFE_EN_0 - Rx Adaptation AFE Enable On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_3_1_SHIFT (1U)
/*! AFE_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_AFE_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_0_SHIFT (4U)
/*! DFE_EN_0 - Rx DFE Enable On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_3_1_SHIFT (5U)
/*! DFE_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_AFE_DFE_EN_CTRL_DFE_EN_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0 - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY DFE Tap Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_SHIFT (0U)
/*! DFE_TAP1_0 - Rx Equalization DFE Tap1 Value On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_1_MASK (0xFF00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_1_SHIFT (8U)
/*! DFE_TAP1_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_DFE_TAP_CTRL0_DFE_TAP1_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_RX_STS - VR MII Synopsys Multi-Protocol 12G/16G/25G/32G PHY Rx Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_0_SHIFT (0U)
/*! RX_ACK_0 - Rx Acknowledge On Lane 0 Of PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_3_1_SHIFT (1U)
/*! RX_ACK_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_RX_ACK_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_0_SHIFT (4U)
/*! LF_SD_0 - For Multi-protocol 25G PHY Or Multi-protocol 32G PHY Or Multi-protocol 10G Gen2 PHY Configurations: */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_3_1_SHIFT (5U)
/*! LF_SD_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_LF_SD_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_0_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_0_SHIFT (8U)
/*! HF_SD_0 - Multi-protocol 25G PHY Or Multi-protocol 32G PHY Or For Multi-protocol 10G Gen2 PHY Configurations: */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_3_1_MASK (0xE00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_3_1_SHIFT (9U)
/*! HF_SD_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_RX_STS_HF_SD_3_1_MASK)
/*! @} */

/*! @name VR_MII_CONSUMER_10G_RX_TERM_CTRL - VR MII Synopsys Consumer 10G PHY Receive Termination Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_TERM_CTRL_RX0_TERM_MASK (0x7U)
#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_TERM_CTRL_RX0_TERM_SHIFT (0U)
/*! RX0_TERM - Receive Termination Control For Lane 0 */
#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_TERM_CTRL_RX0_TERM(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_CONSUMER_10G_RX_TERM_CTRL_RX0_TERM_SHIFT)) & VS_MII_MMD_VR_MII_CONSUMER_10G_RX_TERM_CTRL_RX0_TERM_MASK)
/*! @} */

/*! @name VR_MII_CONSUMER_10G_RX_IQ_CTRL0 - VR MII Synopsys Consumer 10G PHY RX IQ Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK (0xF00U)
#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_IQ_CTRL0_RX0_DELTA_IQ_SHIFT (8U)
/*! RX0_DELTA_IQ - RX IQ Offset Value For Lane0 */
#define VS_MII_MMD_VR_MII_CONSUMER_10G_RX_IQ_CTRL0_RX0_DELTA_IQ(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_CONSUMER_10G_RX_IQ_CTRL0_RX0_DELTA_IQ_SHIFT)) & VS_MII_MMD_VR_MII_CONSUMER_10G_RX_IQ_CTRL0_RX0_DELTA_IQ_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL - VR MII Synopsys Multi-Protocol 12G/16G/25G PHY MPLL Common Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_SHIFT (0U)
/*! MPLL_EN_0 - Tx MPLL Enable-lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_3_1_SHIFT (1U)
/*! MPLL_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLL_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_SHIFT (4U)
/*! MPLLB_SEL_0 - Tx MPLLB Select-lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_3_1_SHIFT (5U)
/*! MPLLB_SEL_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MPLL_CMN_CTRL_MPLLB_SEL_3_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_MPLLA_CTRL0 - VR MII Synopsys Multi-Protocol 12G/16G PHY MPLLA Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_SHIFT (0U)
/*! MPLLA_MULTIPLIER - MPLLA Frequency Multiplier Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_MULTIPLIER_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_MASK (0x700U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_SHIFT (8U)
/*! MPLLA_SSC_CLK_SEL - This Field Controls MPLLA Spread-spectrum Clock Select Of Multi-protocol 10G PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_SSC_CLK_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FRAC_EN_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FRAC_EN_SHIFT (12U)
/*! FRAC_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FRAC_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FRAC_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FRAC_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FR_CFG_UP_EN_MASK (0x2000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FR_CFG_UP_EN_SHIFT (13U)
/*! FR_CFG_UP_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FR_CFG_UP_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FR_CFG_UP_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_FR_CFG_UP_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_PMIX_EN_MASK (0x4000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_PMIX_EN_SHIFT (14U)
/*! PMIX_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_PMIX_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_PMIX_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_PMIX_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_MASK (0x8000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_SHIFT (15U)
/*! MPLLA_CAL_DISABLE - MPLLA Calibration Disable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL0_MPLLA_CAL_DISABLE_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_MPLLA_CTRL1 - VR MII Synopsys Multi-protocol 12G PHY MPLLA Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - MPLLA SSC Enable */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_RANGE_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_RANGE_SHIFT (1U)
/*! MPLLA_SSC_RANGE - MPLLA SSC Range */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_RANGE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_RANGE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLA_SSC_CLK_SEL - MPLLA SSC Clock Select */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_SSC_CLK_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK (0xFFE0U)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_SHIFT (5U)
/*! MPLLA_FRACN_CTRL - MPLLA Fractional Control */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL1_MPLLA_FRACN_CTRL_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_MPLLA_CTRL2 - VR MII Synopsys Multi-protocol 12G/16G PHY MPLLA Control 2 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_SHIFT (0U)
/*! MPLLA_DIV_MULT - MPLLA Output Frequency Multiplier Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_MULT_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_SHIFT (8U)
/*! MPLLA_DIV8_CLK_EN - MPLLA Divide By 8 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV8_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK (0x200U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_SHIFT (9U)
/*! MPLLA_DIV10_CLK_EN - MPLLA Divide By 10 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV10_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_MASK (0x400U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_SHIFT (10U)
/*! MPLLA_DIV_CLK_EN - Enable Mplla_div_clk From PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK (0x3800U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_SHIFT (11U)
/*! MPLLA_TX_CLK_DIV - MPLLA Tx Clock Divider */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_TX_CLK_DIV_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK (0x4000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_SHIFT (14U)
/*! MPLLA_DIV16P5_CLK_EN - MPLLA Divide By 16.5 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_DIV16P5_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_MASK (0x8000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_SHIFT (15U)
/*! MPLLA_WRD_DIV2_EN - MPLLA Word Clock Divide By 2 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLA_CTRL2_MPLLA_WRD_DIV2_EN_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_MPLLB_CTRL0 - VR MII Synopsys Multi-protocol 12G/16G PHY MPLLB Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_SHIFT (0U)
/*! MPLLB_MULTIPLIER - MPLLB Frequency Multiplier Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_MULTIPLIER_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_MASK (0x700U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_SHIFT (8U)
/*! MPLLB_SSC_CLK_SEL - This Field Controls MPLLB Spread-spectrum Clock Select Of Multi-protocol 10G PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_SSC_CLK_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FRAC_EN_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FRAC_EN_SHIFT (12U)
/*! FRAC_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FRAC_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FRAC_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FRAC_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FR_CFG_UP_EN_MASK (0x2000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FR_CFG_UP_EN_SHIFT (13U)
/*! FR_CFG_UP_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FR_CFG_UP_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FR_CFG_UP_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_FR_CFG_UP_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_PMIX_EN_MASK (0x4000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_PMIX_EN_SHIFT (14U)
/*! PMIX_EN - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_PMIX_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_PMIX_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_PMIX_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_MASK (0x8000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_SHIFT (15U)
/*! MPLLB_CAL_DISABLE - MPLLB Calibration Disable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL0_MPLLB_CAL_DISABLE_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_MPLLB_CTRL1 - VR MII Synopsys Multi-protocol 12G PHY MPLLB Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - MPLLB Spread Spectrum Enable */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_RANGE_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_RANGE_SHIFT (1U)
/*! MPLLB_SSC_RANGE - MPLLB Spread Spectrum Range */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_RANGE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_SSC_RANGE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK (0xFFE0U)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_SHIFT (5U)
/*! MPLLB_FRACN_CTRL - MPLLB Fractional Control */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL1_MPLLB_FRACN_CTRL_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_MPLLB_CTRL2 - VR MII Synopsys Multi-protocol 12G/16G PHY MPLLB Control 2 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_SHIFT (0U)
/*! MPLLB_DIV_MULT - MPLLB Output Frequency Multiplier Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_MULT_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_SHIFT (8U)
/*! MPLLB_DIV8_CLK_EN - MPLLB Divide By 8 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV8_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_MASK (0x200U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_SHIFT (9U)
/*! MPLLB_DIV10_CLK_EN - MPLLB Divide By 10 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV10_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_MASK (0x400U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_SHIFT (10U)
/*! MPLLB_DIV_CLK_EN - Enable Mpllb_div_clk From PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_DIV_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_MASK (0x3800U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_SHIFT (11U)
/*! MPLLB_TX_CLK_DIV - MPLLB Tx Clock Divider */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_TX_CLK_DIV_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_MASK (0x4000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_SHIFT (14U)
/*! MPLLB_RECAL_BANK_SEL - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_RECAL_BANK_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_WRD_DIV2_EN_MASK (0x8000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_WRD_DIV2_EN_SHIFT (15U)
/*! MPLLB_WRD_DIV2_EN - MPLLB Word Clock Divide By 2 Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_WRD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_WRD_DIV2_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_MPLLB_CTRL2_MPLLB_WRD_DIV2_EN_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_MPLLA_CTRL3 - VR MII Synopsys Multi-protocol 12G PHY MPLLA Control 3 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL3_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - MPLLA Bandwidth Control */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL3_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL3_MPLLA_BANDWIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLA_CTRL3_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_MPLLB_CTRL3 - VR MII Synopsys Multi-protocol 12G PHY MPLLB Control 3 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL3_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL3_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - MPLLB Bandwidth Control */
#define VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL3_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL3_MPLLB_BANDWIDTH_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_MPLLB_CTRL3_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_MISC_CTRL0 - VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Control 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_SHIFT (0U)
/*! TX2RX_LB_EN_0 - Enable Analog Tx-to-Rx Serial Loopback On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_3_1_MASK (0xEU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_3_1_SHIFT (1U)
/*! TX2RX_LB_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_TX2RX_LB_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_SHIFT (4U)
/*! RX2TX_LB_EN_0 - Enable Parallel Rx-to-Tx Loopback On Lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_3_1_MASK (0xE0U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_3_1_SHIFT (5U)
/*! RX2TX_LB_EN_3_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_3_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_3_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX2TX_LB_EN_3_1_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_MASK (0x1F00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_SHIFT (8U)
/*! RX_VREF_CTRL - Rx Biasing Current Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RX_VREF_CTRL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_MASK (0x2000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_SHIFT (13U)
/*! RTUNE_REQ - Resistor Tuning Request */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_RTUNE_REQ_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_MASK (0x4000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_SHIFT (14U)
/*! CR_PARA_SEL - Select CR Para/APB Port To Access PHY Registers
 *  0b0..JTAG
 *  0b1..CR parallel port/APB interface
 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_CR_PARA_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_MASK (0x8000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_SHIFT (15U)
/*! PLL_CTRL - PLL Re-initialization Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL0_PLL_CTRL_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_REF_CLK_CTRL - VR MII Synopsys Multi-protocol 12G/16G/25G PHY Reference Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_SHIFT (0U)
/*! REF_CLK_EN - Reference Clock Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_MASK (0x2U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_SHIFT (1U)
/*! REF_USE_PAD - Use Pad Clk As Reference Clock */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_USE_PAD_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_MASK (0x4U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_SHIFT (2U)
/*! REF_CLK_DIV2 - Reference Clock Divide By 2 */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_CLK_DIV2_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_MASK (0x38U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_SHIFT (3U)
/*! REF_RANGE - Input Reference Clock Range */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RANGE_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_MASK (0x40U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_SHIFT (6U)
/*! REF_MPLLA_DIV2 - MPLLA Reference Clock Divider Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV2_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_MASK (0x80U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_SHIFT (7U)
/*! REF_MPLLB_DIV2 - MPLLB Reference Clock Divider Control */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV2_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_SHIFT (8U)
/*! REF_RPT_CLK_EN - Repeat Reference Clock Enable */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_RPT_CLK_EN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_ALT_LP_CLK_SEL_MASK (0x200U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_ALT_LP_CLK_SEL_SHIFT (9U)
/*! ALT_LP_CLK_SEL - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_ALT_LP_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_ALT_LP_CLK_SEL_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_ALT_LP_CLK_SEL_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_MASK (0x1C00U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_SHIFT (10U)
/*! REF_MPLLA_DIV - For Multi-protocol 25G PHY Or Multi-protocol 10G Gen2 PHY Configurations: */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLA_DIV_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_MASK (0xE000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_SHIFT (13U)
/*! REF_MPLLB_DIV - For Multi-protocol 25G PHY Or Multi-protocol 10G Gen2 PHY Configurations: */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_REF_CLK_CTRL_REF_MPLLB_DIV_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_VCO_CAL_LD0 - VR MII Synopsys Multi-protocol 12G/16G/25G PHY VCO Calibration Load 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK (0x1FFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_SHIFT (0U)
/*! VCO_LD_VAL_0 - Rx VCO Calibration Load Value On Lane 0 Of The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_VCO_CAL_LD0_VCO_LD_VAL_0_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_VCO_CAL_REF0 - VR MII Synopsys Multi-protocol 12G PHY VCO Calibration Reference 0 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_0_MASK (0x3FU)
#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_0_SHIFT (0U)
/*! VCO_REF_LD_0 - Rx VCO Calibration Reference Load Value -lane 0 */
#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_0_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_0_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_1_MASK (0x3F00U)
#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_1_SHIFT (8U)
/*! VCO_REF_LD_1 - Reserved */
#define VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_1(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_1_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_VCO_CAL_REF0_VCO_REF_LD_1_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_MISC_STS - VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Status */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_FOM_MASK (0xFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_FOM_SHIFT (0U)
/*! FOM - Figure Of Merit From The PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_FOM(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_FOM_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_FOM_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_MASK (0x100U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_SHIFT (8U)
/*! RTUNE_ACK - Acknowledgment For Resistor Tune Request */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RTUNE_ACK_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLA_STS_MASK (0x200U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLA_STS_SHIFT (9U)
/*! MPLLA_STS - Status Of MPLLA From PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLA_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLA_STS_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLA_STS_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLB_STS_MASK (0x400U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLB_STS_SHIFT (10U)
/*! MPLLB_STS - Status Of MPLLB From PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLB_STS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLB_STS_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_MPLLB_STS_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_MASK (0x800U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_SHIFT (11U)
/*! REF_CLKDET_RESULT - For Multi-protocol 16G/25G PHY Configurations: */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_REF_CLKDET_RESULT_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_MASK (0x1000U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_SHIFT (12U)
/*! RX_ADPT_ACK - Receive Adaptation Acknowledgment From PHY */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_STS_RX_ADPT_ACK_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_MISC_CTRL1 - VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY Miscellaneous Control 1 */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_SHIFT (0U)
/*! RX_LNK_UP_TIME - Wait Time Before PLL Re-initialization */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_MISC_CTRL1_RX_LNK_UP_TIME_MASK)
/*! @} */

/*! @name VR_MII_MP_12G_16G_25G_SRAM - VR MII Synopsys Multi-protocol 12G/16G/25G/32G PHY SRAM */
/*! @{ */

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_INIT_DN_MASK (0x1U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_INIT_DN_SHIFT (0U)
/*! INIT_DN - SRAM Initialization Done */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_INIT_DN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_INIT_DN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_INIT_DN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_EXT_LD_DN_MASK (0x2U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_EXT_LD_DN_SHIFT (1U)
/*! EXT_LD_DN - SRAM External Loading Done */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_EXT_LD_DN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_EXT_LD_DN_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_EXT_LD_DN_MASK)

#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_BTLD_BYP_MASK (0x4U)
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_BTLD_BYP_SHIFT (2U)
/*! BTLD_BYP - SRAM Bootload Bypass */
#define VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_BTLD_BYP(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_BTLD_BYP_SHIFT)) & VS_MII_MMD_VR_MII_MP_12G_16G_25G_SRAM_BTLD_BYP_MASK)
/*! @} */

/*! @name VR_MII_SNPS_CR_CTRL - VR MII Synopsys PHY CR Control */
/*! @{ */

#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_START_BUSY_MASK (0x1U)
#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_START_BUSY_SHIFT (0U)
/*! START_BUSY - Start CR Port Access Or Busy Indicator (WS,SC Type)
 *  0b0..CR port not busy
 *  0b1..CR port busy
 */
#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_START_BUSY(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_SNPS_CR_CTRL_START_BUSY_SHIFT)) & VS_MII_MMD_VR_MII_SNPS_CR_CTRL_START_BUSY_MASK)

#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_WR_RDN_MASK (0x2U)
#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_WR_RDN_SHIFT (1U)
/*! WR_RDN - Write Or Read Indicator
 *  0b0..Read
 *  0b1..Write
 */
#define VS_MII_MMD_VR_MII_SNPS_CR_CTRL_WR_RDN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_SNPS_CR_CTRL_WR_RDN_SHIFT)) & VS_MII_MMD_VR_MII_SNPS_CR_CTRL_WR_RDN_MASK)
/*! @} */

/*! @name VR_MII_SNPS_CR_ADDR - VR MII Synopsys PHY CR Address */
/*! @{ */

#define VS_MII_MMD_VR_MII_SNPS_CR_ADDR_ADDRESS_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_SNPS_CR_ADDR_ADDRESS_SHIFT (0U)
/*! ADDRESS - CR Port Address */
#define VS_MII_MMD_VR_MII_SNPS_CR_ADDR_ADDRESS(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_SNPS_CR_ADDR_ADDRESS_SHIFT)) & VS_MII_MMD_VR_MII_SNPS_CR_ADDR_ADDRESS_MASK)
/*! @} */

/*! @name VR_MII_SNPS_CR_DATA - VR MII Synopsys CR Data */
/*! @{ */

#define VS_MII_MMD_VR_MII_SNPS_CR_DATA_DATA_MASK (0xFFFFU)
#define VS_MII_MMD_VR_MII_SNPS_CR_DATA_DATA_SHIFT (0U)
/*! DATA - CR Port Data */
#define VS_MII_MMD_VR_MII_SNPS_CR_DATA_DATA(x)   (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_SNPS_CR_DATA_DATA_SHIFT)) & VS_MII_MMD_VR_MII_SNPS_CR_DATA_DATA_MASK)
/*! @} */

/*! @name VR_MII_DIG_CTRL2 - VR MII MMD Digital Control 2 */
/*! @{ */

#define VS_MII_MMD_VR_MII_DIG_CTRL2_RX_POL_INV_0_MASK (0x1U)
#define VS_MII_MMD_VR_MII_DIG_CTRL2_RX_POL_INV_0_SHIFT (0U)
/*! RX_POL_INV_0 - Rx Polarity Invert On Lane 0
 *  0b1..The bits within this field indicate that the data received on Rx serial line is inverted on Lane 0. This
 *       reverses the polarity on the data received from the PHY core. The value 1 indicates that Rx data on Lane 0
 *       is inverted.
 */
#define VS_MII_MMD_VR_MII_DIG_CTRL2_RX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL2_RX_POL_INV_0_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL2_RX_POL_INV_0_MASK)

#define VS_MII_MMD_VR_MII_DIG_CTRL2_TX_POL_INV_0_MASK (0x10U)
#define VS_MII_MMD_VR_MII_DIG_CTRL2_TX_POL_INV_0_SHIFT (4U)
/*! TX_POL_INV_0 - Tx Polarity Invert On Lane 0 */
#define VS_MII_MMD_VR_MII_DIG_CTRL2_TX_POL_INV_0(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_CTRL2_TX_POL_INV_0_SHIFT)) & VS_MII_MMD_VR_MII_DIG_CTRL2_TX_POL_INV_0_MASK)
/*! @} */

/*! @name VR_MII_DIG_ERRCNT_SEL - VR MII MMD Digital Error Count Select */
/*! @{ */

#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_COR_MASK (0x1U)
#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_COR_SHIFT (0U)
/*! COR - Clear On Read
 *  0b0..Normal operation
 *  0b1..Clear any error counter that is read
 */
#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_COR(x)  (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_COR_SHIFT)) & VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_COR_MASK)

#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_INV_EC_EN_MASK (0x10U)
#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT (4U)
/*! INV_EC_EN - Invalid Code Group Error Counter Enable
 *  0b0..The counting of errors is disabled
 *  0b1..The counting of errors is enabled
 */
#define VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_INV_EC_EN(x) (((uint16_t)(((uint16_t)(x)) << VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_INV_EC_EN_SHIFT)) & VS_MII_MMD_VR_MII_DIG_ERRCNT_SEL_INV_EC_EN_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group VS_MII_MMD_Register_Masks */


/*!
 * @}
 */ /* end of group VS_MII_MMD_Peripheral_Access_Layer */


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


#endif  /* PERI_VS_MII_MMD_H_ */

