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
**         CMSIS Peripheral Access Layer for PHY_ENET
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
 * @file PERI_PHY_ENET.h
 * @version 2.0
 * @date 2024-10-29
 * @brief CMSIS Peripheral Access Layer for PHY_ENET
 *
 * CMSIS Peripheral Access Layer for PHY_ENET
 */

#if !defined(PERI_PHY_ENET_H_)
#define PERI_PHY_ENET_H_                         /**< Symbol preventing repeated inclusion */

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
   -- PHY_ENET Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHY_ENET_Peripheral_Access_Layer PHY_ENET Peripheral Access Layer
 * @{
 */

/** PHY_ENET - Size of Registers Arrays */
#define PHY_ENET_RAWMEM_DIG_ROM_CMNX_COUNT        16u
#define PHY_ENET_RAWMEM_DIG_ROM_CMNX_RAWMEM_DIG_ROM_CMNX_BY_COUNT 8u
#define PHY_ENET_RAWMEM_DIG_ROM_CMNX_RAWMEM_DIG_ROM_CMNX_BY_RAWMEM_DIG_ROM_CMNX_BY_RZ_COUNT 32u
#define PHY_ENET_RAWMEM_DIG_RAM_CMNX_COUNT        16u
#define PHY_ENET_RAWMEM_DIG_RAM_CMNX_RAWMEM_DIG_RAM_CMNX_BY_COUNT 8u
#define PHY_ENET_RAWMEM_DIG_RAM_CMNX_RAWMEM_DIG_RAM_CMNX_BY_RAWMEM_DIG_RAM_CMNX_BY_RZ_COUNT 32u

/** PHY_ENET - Register Layout Typedef */
typedef struct {
  __I  uint16_t SUP_DIG_IDCODE_LO;                 /**< Low 16 bits of IDCODE, offset: 0x0 */
       uint8_t RESERVED_0[2];
  __I  uint16_t SUP_DIG_IDCODE_HI;                 /**< High 16 bits of IDCODE, offset: 0x4 */
       uint8_t RESERVED_1[2];
  __IO uint16_t SUP_DIG_REFCLK_OVRD_IN;            /**< Override values for incoming REFCLK and RESET controls from ASIC, offset: 0x8 */
       uint8_t RESERVED_2[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_IN;               /**< Override values for support block ASIC inputs, offset: 0xC */
       uint8_t RESERVED_3[2];
  __IO uint16_t SUP_DIG_SUP_OVRD_OUT;              /**< Override values for support block ASIC outputs, offset: 0x10 */
       uint8_t RESERVED_4[2];
  __IO uint16_t SUP_DIG_LVL_OVRD_IN;               /**< Override values for level settings, offset: 0x14 */
       uint8_t RESERVED_5[2];
  __IO uint16_t SUP_DIG_DEBUG;                     /**< Debug controls, offset: 0x18 */
       uint8_t RESERVED_6[2];
  __I  uint16_t SUP_DIG_ASIC_IN;                   /**< Current values for incoming SUP control signals from ASIC, offset: 0x1C */
       uint8_t RESERVED_7[2];
  __I  uint16_t SUP_DIG_LVL_ASIC_IN;               /**< Current values for incoming level controls from ASIC, offset: 0x20 */
       uint8_t RESERVED_8[2];
  __I  uint16_t SUP_DIG_BANDGAP_ASIC_IN;           /**< Current values for incoming bandgap control from ASIC, offset: 0x24 */
       uint8_t RESERVED_9[2];
  __IO uint16_t SUP_DIG_CLK_RST_BG_PWRUP_TIME_0;   /**< BG Power UP Time Register #0, offset: 0x28 */
       uint8_t RESERVED_10[2];
  __IO uint16_t SUP_DIG_CLK_RST_BG_PWRUP_TIME_1;   /**< BG Power UP Time Register #1, offset: 0x2C */
       uint8_t RESERVED_11[2];
  __IO uint16_t SUP_ANA_RTUNE_CTRL;                /**< RTUNE_CTRL, offset: 0x30 */
       uint8_t RESERVED_12[2];
  __IO uint16_t SUP_ANA_SWITCH_PWR_MEAS;           /**< SWITCH_PWR_MEAS, offset: 0x34 */
       uint8_t RESERVED_13[2];
  __IO uint16_t SUP_ANA_SWITCH_MISC_MEAS;          /**< SWITCH_MISC_MEAS, offset: 0x38 */
       uint8_t RESERVED_14[2];
  __IO uint16_t SUP_ANA_BG;                        /**< BG, offset: 0x3C */
       uint8_t RESERVED_15[2];
  __IO uint16_t SUP_ANA_PRESCALER_CTRL;            /**< PRESCALER_CTRL, offset: 0x40 */
       uint8_t RESERVED_16[2];
  __IO uint16_t SUP_DIG_RTUNE_DEBUG;               /**< Resistor tuning debug controls, offset: 0x44 */
       uint8_t RESERVED_17[2];
  __IO uint16_t SUP_DIG_RTUNE_CONFIG;              /**< Configure Rtune Operation, offset: 0x48 */
       uint8_t RESERVED_18[2];
  __I  uint16_t SUP_DIG_RTUNE_STAT;                /**< Resistor tuning register status, offset: 0x4C */
       uint8_t RESERVED_19[2];
  __IO uint16_t SUP_DIG_RTUNE_RX_SET_VAL;          /**< Set value of RX Resistor, offset: 0x50 */
       uint8_t RESERVED_20[2];
  __IO uint16_t SUP_DIG_RTUNE_TXDN_SET_VAL;        /**< Set value of TX-DN Resistor, offset: 0x54 */
       uint8_t RESERVED_21[2];
  __IO uint16_t SUP_DIG_RTUNE_TXUP_SET_VAL;        /**< Set value of TX-UP Resistor, offset: 0x58 */
       uint8_t RESERVED_22[2];
  __I  uint16_t SUP_DIG_RTUNE_RX_STAT;             /**< RX Resistor tuning register status, offset: 0x5C */
       uint8_t RESERVED_23[2];
  __I  uint16_t SUP_DIG_RTUNE_TXDN_STAT;           /**< TX-DN Resistor tuning register status, offset: 0x60 */
       uint8_t RESERVED_24[2];
  __I  uint16_t SUP_DIG_RTUNE_TXUP_STAT;           /**< TX-UP Resistor tuning register status, offset: 0x64 */
       uint8_t RESERVED_25[2];
  __IO uint16_t SUP_DIG_ANA_RTUNE_OVRD_OUT;        /**< Override value for RTUNE signals going to ANA, offset: 0x68 */
       uint8_t RESERVED_26[2];
  __I  uint16_t SUP_DIG_ANA_STAT;                  /**< SUP input status register for SUP ANA outputs, offset: 0x6C */
       uint8_t RESERVED_27[2];
  __IO uint16_t SUP_DIG_ANA_ANA_OVRD_OUT;          /**< Override values for ana_async_rst and bandgap signals going to ANA, offset: 0x70 */
       uint8_t RESERVED_28[2];
  __IO uint16_t RAWCMN_DIG_CMN_CTL;                /**< Common control register, offset: 0x74 */
       uint8_t RESERVED_29[2];
  __IO uint16_t RAWCMN_DIG_LANE_FSM_OP_XTND;       /**< Lane FSM OP XTND control register, offset: 0x78 */
       uint8_t RESERVED_30[2];
  __IO uint16_t RAWCMN_DIG_CMN_CTL_1;              /**< Common control register 1, offset: 0x7C */
       uint8_t RESERVED_31[2];
  __IO uint16_t RAWCMN_DIG_CMN_CTL_2;              /**< Common control register 2, offset: 0x80 */
       uint8_t RESERVED_32[2];
  __IO uint16_t RAWCMN_DIG_MPLL_STATE_CTL;         /**< MPLL control signals for force ack state machine, offset: 0x84 */
       uint8_t RESERVED_33[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0; /**< Resistor Tune RX Value 0, offset: 0x88 */
       uint8_t RESERVED_34[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0; /**< Resistor Tune TX Down Value 0, offset: 0x8C */
       uint8_t RESERVED_35[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0; /**< Resistor Tune TX Up Value 0, offset: 0x90 */
       uint8_t RESERVED_36[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1; /**< Resistor Tune RX Value 1, offset: 0x94 */
       uint8_t RESERVED_37[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1; /**< Resistor Tune TX Down Value 1, offset: 0x98 */
       uint8_t RESERVED_38[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1; /**< Resistor Tune TX Up Value 1, offset: 0x9C */
       uint8_t RESERVED_39[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2; /**< Resistor Tune RX Value 2, offset: 0xA0 */
       uint8_t RESERVED_40[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2; /**< Resistor Tune TX Down Value 2, offset: 0xA4 */
       uint8_t RESERVED_41[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2; /**< Resistor Tune TX Up Value 2, offset: 0xA8 */
       uint8_t RESERVED_42[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3; /**< Resistor Tune RX Value 3, offset: 0xAC */
       uint8_t RESERVED_43[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3; /**< Resistor Tune TX Down Value 3, offset: 0xB0 */
       uint8_t RESERVED_44[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3; /**< Resistor Tune TX Up Value 3, offset: 0xB4 */
       uint8_t RESERVED_45[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4; /**< Resistor Tune RX Value 4, offset: 0xB8 */
       uint8_t RESERVED_46[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4; /**< Resistor Tune TX Down Value 4, offset: 0xBC */
       uint8_t RESERVED_47[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4; /**< Resistor Tune TX Up Value 4, offset: 0xC0 */
       uint8_t RESERVED_48[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5; /**< Resistor Tune RX Value 5, offset: 0xC4 */
       uint8_t RESERVED_49[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5; /**< Resistor Tune TX Down Value 5, offset: 0xC8 */
       uint8_t RESERVED_50[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5; /**< Resistor Tune TX Up Value 5, offset: 0xCC */
       uint8_t RESERVED_51[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6; /**< Resistor Tune RX Value 6, offset: 0xD0 */
       uint8_t RESERVED_52[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6; /**< Resistor Tune TX Down Value 6, offset: 0xD4 */
       uint8_t RESERVED_53[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6; /**< Resistor Tune TX Up Value 6, offset: 0xD8 */
       uint8_t RESERVED_54[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7; /**< Resistor Tune RX Value 7, offset: 0xDC */
       uint8_t RESERVED_55[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7; /**< Resistor Tune TX Down Value 7, offset: 0xE0 */
       uint8_t RESERVED_56[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7; /**< Resistor Tune TX Up Value 7, offset: 0xE4 */
       uint8_t RESERVED_57[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN; /**< Enable SRAM bootloader on power-gated exit, offset: 0xE8 */
       uint8_t RESERVED_58[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_PG_OVRD_IN;     /**< Override values for incoming power-gating signals, offset: 0xEC */
       uint8_t RESERVED_59[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_PG_OVRD_OUT;    /**< Override values for outgoing power-gating signals, offset: 0xF0 */
       uint8_t RESERVED_60[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_SUP_OVRD_IN;    /**< Override values for incoming SUP signals, offset: 0xF4 */
       uint8_t RESERVED_61[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE;  /**< Firmware Power-Up Done Status, offset: 0xF8 */
       uint8_t RESERVED_62[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL; /**< Firmware version register #0, offset: 0xFC */
       uint8_t RESERVED_63[2];
  __IO uint16_t RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL; /**< Firmware version register #1, offset: 0x100 */
       uint8_t RESERVED_64[130814];
  __IO uint16_t SUP_DIG_MPLLA_DIV_CLK_OVRD_IN;     /**< Override values for incoming MPLLA_DIV_CLK controls from ASIC, offset: 0x20000 */
       uint8_t RESERVED_65[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_0;           /**< Override values for incoming MPLLA controls from ASIC, offset: 0x20004 */
       uint8_t RESERVED_66[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_1;           /**< Override values for incoming MPLLA controls from ASIC, offset: 0x20008 */
       uint8_t RESERVED_67[2];
  __IO uint16_t SUP_DIG_MPLLA_OVRD_IN_2;           /**< Override values for incoming MPLLA controls from ASIC, offset: 0x2000C */
       uint8_t RESERVED_68[2];
  __IO uint16_t SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN;   /**< Override values for incoming MPLLA bandwidth controls from ASIC, offset: 0x20010 */
       uint8_t RESERVED_69[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_0;           /**< Current values for incoming MPLLA controls from ASIC, offset: 0x20014 */
       uint8_t RESERVED_70[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_1;           /**< Current values for incoming MPLLA controls from ASIC, offset: 0x20018 */
       uint8_t RESERVED_71[2];
  __I  uint16_t SUP_DIG_MPLLA_ASIC_IN_2;           /**< Current values for incoming MPLLA controls from ASIC, offset: 0x2001C */
       uint8_t RESERVED_72[2];
  __I  uint16_t SUP_DIG_MPLLA_DIV_CLK_ASIC_IN;     /**< Current values for incoming MPLLA_DIV_CLK controls from ASIC, offset: 0x20020 */
       uint8_t RESERVED_73[2];
  __I  uint16_t SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN;   /**< Current values for incoming MPLLA bandwidth controls from ASIC, offset: 0x20024 */
       uint8_t RESERVED_74[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL; /**< MPLL Calibration controls, offset: 0x20028 */
       uint8_t RESERVED_75[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD; /**< MPLL override controls, offset: 0x2002C */
       uint8_t RESERVED_76[2];
  __I  uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT;   /**< MPLL status register, offset: 0x20030 */
       uint8_t RESERVED_77[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD; /**< Thresholds for MPLL CAL Update timer and MPLL VCO Stabilization timer, offset: 0x20034 */
       uint8_t RESERVED_78[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD; /**< Thresholds for PCLK enable and MPLL VCO Clock Stabilization timer, offset: 0x20038 */
       uint8_t RESERVED_79[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD; /**< Thresholds for PCLK disable and MPLL VCO POWER DOWN timer, offset: 0x2003C */
       uint8_t RESERVED_80[2];
  __IO uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD; /**< Thresholds for MPLL feedback clock enable and MPLL feedback digital clock disable and MPLL ANA POWER UP timer, offset: 0x20040 */
       uint8_t RESERVED_81[2];
  __I  uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL; /**< MPLL coarse_tune value register, offset: 0x20044 */
       uint8_t RESERVED_82[2];
  __I  uint16_t SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE; /**< Value for MPLL coarse_tune when skipping calibration, offset: 0x20048 */
       uint8_t RESERVED_83[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_PHASE;        /**< Current MPLL phase selector value, offset: 0x2004C */
       uint8_t RESERVED_84[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_FREQ_0;       /**< Frequency Control for Spread Spectrum #0, offset: 0x20050 */
       uint8_t RESERVED_85[2];
  __IO uint16_t SUP_DIG_MPLLA_SSC_SS_FREQ_1;       /**< Frequency Control for Spread Spectrum #1, offset: 0x20054 */
       uint8_t RESERVED_86[2];
  __IO uint16_t SUP_ANA_MPLLA_MISC;                /**< MPLLA_MISC, offset: 0x20058 */
       uint8_t RESERVED_87[2];
  __IO uint16_t SUP_ANA_MPLLA_OVRD;                /**< MPLLA_OVRD, offset: 0x2005C */
       uint8_t RESERVED_88[2];
  __IO uint16_t SUP_ANA_MPLLA_ATB1;                /**< MPLLA_ATB1, offset: 0x20060 */
       uint8_t RESERVED_89[2];
  __IO uint16_t SUP_ANA_MPLLA_ATB2;                /**< MPLLA_ATB2, offset: 0x20064 */
       uint8_t RESERVED_90[2];
  __IO uint16_t SUP_ANA_MPLLA_ATB3;                /**< MPLLA_ATB3, offset: 0x20068 */
       uint8_t RESERVED_91[2];
  __IO uint16_t SUP_DIG_ANA_MPLLA_OVRD_OUT;        /**< Override value for mplla signals going to ANA, offset: 0x2006C */
       uint8_t RESERVED_92[2];
  __IO uint16_t SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT;   /**< Override value for mplla pmix signals going to ANA, offset: 0x20070 */
       uint8_t RESERVED_93[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_OVRD_IN;          /**< Override values for incoming MPLLA signals, offset: 0x20074 */
       uint8_t RESERVED_94[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_BW_OVRD_IN;       /**< Override values for incoming MPLLA bandwidth, offset: 0x20078 */
       uint8_t RESERVED_95[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0; /**< Override values for incoming MPLLA SSC control settings, offset: 0x2007C */
       uint8_t RESERVED_96[2];
  __IO uint16_t RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1; /**< Override values for incoming MPLLA SSC control settings, offset: 0x20080 */
       uint8_t RESERVED_97[130942];
  __IO uint16_t SUP_DIG_MPLLB_DIV_CLK_OVRD_IN;     /**< Override values for incoming MPLLB_DIV_CLK controls from ASIC, offset: 0x40000 */
       uint8_t RESERVED_98[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_0;           /**< Override values for incoming MPLLB controls from ASIC, offset: 0x40004 */
       uint8_t RESERVED_99[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_1;           /**< Override values for incoming MPLLB controls from ASIC, offset: 0x40008 */
       uint8_t RESERVED_100[2];
  __IO uint16_t SUP_DIG_MPLLB_OVRD_IN_2;           /**< Override values for incoming MPLLB controls from ASIC, offset: 0x4000C */
       uint8_t RESERVED_101[2];
  __IO uint16_t SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN;   /**< Override values for incoming MPLLB bandwidth controls from ASIC, offset: 0x40010 */
       uint8_t RESERVED_102[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_0;           /**< Current values for incoming MPLLB controls from ASIC, offset: 0x40014 */
       uint8_t RESERVED_103[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_1;           /**< Current values for incoming MPLLB controls from ASIC, offset: 0x40018 */
       uint8_t RESERVED_104[2];
  __I  uint16_t SUP_DIG_MPLLB_ASIC_IN_2;           /**< Current values for incoming MPLLB controls from ASIC, offset: 0x4001C */
       uint8_t RESERVED_105[2];
  __I  uint16_t SUP_DIG_MPLLB_DIV_CLK_ASIC_IN;     /**< Current values for incoming MPLLB_DIV_CLK controls from ASIC, offset: 0x40020 */
       uint8_t RESERVED_106[2];
  __I  uint16_t SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN;   /**< Current values for incoming MPLLB bandwidth controls from ASIC, offset: 0x40024 */
       uint8_t RESERVED_107[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL; /**< MPLL Calibration controls, offset: 0x40028 */
       uint8_t RESERVED_108[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD; /**< MPLL override controls, offset: 0x4002C */
       uint8_t RESERVED_109[2];
  __I  uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT;   /**< MPLL status register, offset: 0x40030 */
       uint8_t RESERVED_110[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD; /**< Thresholds for MPLL CAL Update timer and MPLL VCO Stabilization timer, offset: 0x40034 */
       uint8_t RESERVED_111[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD; /**< Thresholds for PCLK enable and MPLL VCO Clock Stabilization timer, offset: 0x40038 */
       uint8_t RESERVED_112[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD; /**< Thresholds for PCLK disable and MPLL VCO POWER DOWN timer, offset: 0x4003C */
       uint8_t RESERVED_113[2];
  __IO uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD; /**< Thresholds for MPLL feedback clock enable and MPLL feedback digital clock disable and MPLL ANA POWER UP timer, offset: 0x40040 */
       uint8_t RESERVED_114[2];
  __I  uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL; /**< MPLL coarse_tune value register, offset: 0x40044 */
       uint8_t RESERVED_115[2];
  __I  uint16_t SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE; /**< Value for MPLL coarse_tune when skipping calibration, offset: 0x40048 */
       uint8_t RESERVED_116[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_PHASE;        /**< Current MPLL phase selector value, offset: 0x4004C */
       uint8_t RESERVED_117[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_FREQ_0;       /**< Frequency Control for Spread Spectrum #0, offset: 0x40050 */
       uint8_t RESERVED_118[2];
  __IO uint16_t SUP_DIG_MPLLB_SSC_SS_FREQ_1;       /**< Frequency Control for Spread Spectrum #1, offset: 0x40054 */
       uint8_t RESERVED_119[2];
  __IO uint16_t SUP_ANA_MPLLB_MISC;                /**< MPLLB_MISC, offset: 0x40058 */
       uint8_t RESERVED_120[2];
  __IO uint16_t SUP_ANA_MPLLB_OVRD;                /**< MPLLB_OVRD, offset: 0x4005C */
       uint8_t RESERVED_121[2];
  __IO uint16_t SUP_ANA_MPLLB_ATB1;                /**< MPLLB_ATB1, offset: 0x40060 */
       uint8_t RESERVED_122[2];
  __IO uint16_t SUP_ANA_MPLLB_ATB2;                /**< MPLLB_ATB2, offset: 0x40064 */
       uint8_t RESERVED_123[2];
  __IO uint16_t SUP_ANA_MPLLB_ATB3;                /**< MPLLB_ATB3, offset: 0x40068 */
       uint8_t RESERVED_124[2];
  __IO uint16_t SUP_DIG_ANA_MPLLB_OVRD_OUT;        /**< Override value for mpllb signals going to ANA, offset: 0x4006C */
       uint8_t RESERVED_125[2];
  __IO uint16_t SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT;   /**< Override value for mpllb pmix signals going to ANA, offset: 0x40070 */
       uint8_t RESERVED_126[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_OVRD_IN;          /**< Override values for incoming MPLLB signals, offset: 0x40074 */
       uint8_t RESERVED_127[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_BW_OVRD_IN;       /**< Override values for incoming MPLLB bandwidth, offset: 0x40078 */
       uint8_t RESERVED_128[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0; /**< Override values for incoming MPLLB SSC control settings, offset: 0x4007C */
       uint8_t RESERVED_129[2];
  __IO uint16_t RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1; /**< Override values for incoming MPLLB SSC control settings, offset: 0x40080 */
       uint8_t RESERVED_130[130942];
  __IO uint16_t LANE0_DIG_ASIC_LANE_OVRD_IN;       /**< Override values for incoming LANE controls from ASIC, offset: 0x60000 */
       uint8_t RESERVED_131[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_0;       /**< Override values for incoming TX controls from ASIC, register #0, offset: 0x60004 */
       uint8_t RESERVED_132[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_1;       /**< Override values for incoming TX drive controls from ASIC, register #1, offset: 0x60008 */
       uint8_t RESERVED_133[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_2;       /**< Override values for incoming TX drive controls from ASIC, register #2, offset: 0x6000C */
       uint8_t RESERVED_134[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_3;       /**< Override values for incoming TX drive controls from ASIC, register #3, offset: 0x60010 */
       uint8_t RESERVED_135[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_IN_4;       /**< Override values for incoming TX drive controls from ASIC, register #4, offset: 0x60014 */
       uint8_t RESERVED_136[2];
  __IO uint16_t LANE0_DIG_ASIC_TX_OVRD_OUT;        /**< Override values for outgoing TX controls to ASIC, offset: 0x60018 */
       uint8_t RESERVED_137[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_0;       /**< Override values for incoming RX controls from ASIC, register #0, offset: 0x6001C */
       uint8_t RESERVED_138[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_1;       /**< Override values for incoming RX controls from ASIC, register #1, offset: 0x60020 */
       uint8_t RESERVED_139[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_2;       /**< Override values for incoming RX controls from ASIC, register #2, offset: 0x60024 */
       uint8_t RESERVED_140[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_3;       /**< Override values for incoming RX controls from ASIC, register #3, offset: 0x60028 */
       uint8_t RESERVED_141[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_4;       /**< Override values for incoming RX controls from ASIC, register #4, offset: 0x6002C */
       uint8_t RESERVED_142[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_IN_5;       /**< Override values for incoming RX controls from ASIC, register #5, offset: 0x60030 */
       uint8_t RESERVED_143[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0;    /**< Override values for incoming RX EQ controls from ASIC, register #0, offset: 0x60034 */
       uint8_t RESERVED_144[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1;    /**< Override values for incoming RX EQ controls from ASIC, register #1, offset: 0x60038 */
       uint8_t RESERVED_145[2];
  __IO uint16_t LANE0_DIG_ASIC_RX_OVRD_OUT_0;      /**< Override values for outgoing RX controls to ASIC, register #0, offset: 0x6003C */
       uint8_t RESERVED_146[2];
  __I  uint16_t LANE0_DIG_ASIC_LANE_ASIC_IN;       /**< Current values for incoming LANE controls from ASIC, offset: 0x60040 */
       uint8_t RESERVED_147[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_0;       /**< Current values for incoming TX controls from ASIC, register #0, offset: 0x60044 */
       uint8_t RESERVED_148[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_1;       /**< Current values for incoming TX controls from ASIC, register #1, offset: 0x60048 */
       uint8_t RESERVED_149[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_IN_2;       /**< Current values for incoming TX controls from ASIC, register #2, offset: 0x6004C */
       uint8_t RESERVED_150[2];
  __I  uint16_t LANE0_DIG_ASIC_TX_ASIC_OUT;        /**< Current values for outgoing TX status controls from PHY, offset: 0x60050 */
       uint8_t RESERVED_151[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_IN_0;       /**< Current values for incoming RX controls from ASIC, register #0, offset: 0x60054 */
       uint8_t RESERVED_152[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_IN_1;       /**< Current values for incoming RX controls from ASIC, register #1, offset: 0x60058 */
       uint8_t RESERVED_153[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0;    /**< Current values for incoming RX EQ controls from ASIC, register #0, offset: 0x6005C */
       uint8_t RESERVED_154[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1;    /**< Current values for incoming RX EQ controls from ASIC, register #1, offset: 0x60060 */
       uint8_t RESERVED_155[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0; /**< Current values for incoming RX CDR VCO controls from ASIC, register #0, offset: 0x60064 */
       uint8_t RESERVED_156[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1; /**< Current values for incoming RX CDR VCO controls from ASIC, register #1, offset: 0x60068 */
       uint8_t RESERVED_157[2];
  __I  uint16_t LANE0_DIG_ASIC_RX_ASIC_OUT_0;      /**< Current values for outgoing RX status controls from PHY, register #0, offset: 0x6006C */
       uint8_t RESERVED_158[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0;  /**< TX Power State Control Register for P0, offset: 0x60070 */
       uint8_t RESERVED_159[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S; /**< TX Power State Control Register for P0S, offset: 0x60074 */
       uint8_t RESERVED_160[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1;  /**< TX Power State Control Register for P1, offset: 0x60078 */
       uint8_t RESERVED_161[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2;  /**< TX Power State Control Register for P2, offset: 0x6007C */
       uint8_t RESERVED_162[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0; /**< TX Power UP Time Register #0, offset: 0x60080 */
       uint8_t RESERVED_163[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1; /**< TX Power UP Time Register #1, offset: 0x60084 */
       uint8_t RESERVED_164[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2; /**< TX Power UP Time Register #2, offset: 0x60088 */
       uint8_t RESERVED_165[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3; /**< TX Power UP Time Register #3, offset: 0x6008C */
       uint8_t RESERVED_166[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4; /**< TX Power UP Time Register #4, offset: 0x60090 */
       uint8_t RESERVED_167[2];
  __IO uint16_t LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5; /**< TX Power UP Time Register #5, offset: 0x60094 */
       uint8_t RESERVED_168[2];
  __IO uint16_t LANE0_DIG_TX_LBERT_CTL;            /**< Pattern Generator controls, offset: 0x60098 */
       uint8_t RESERVED_169[2];
  __IO uint16_t LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0;   /**< TX Clock Alignment Control Register #0, offset: 0x6009C */
       uint8_t RESERVED_170[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0;  /**< RX Power State Control Register for P0, offset: 0x600A0 */
       uint8_t RESERVED_171[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S; /**< RX Power State Control Register for P0S, offset: 0x600A4 */
       uint8_t RESERVED_172[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1;  /**< RX Power State Control Register for P1, offset: 0x600A8 */
       uint8_t RESERVED_173[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2;  /**< RX Power State Control Register for P2, offset: 0x600AC */
       uint8_t RESERVED_174[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0; /**< RX Power UP Time Register #0, offset: 0x600B0 */
       uint8_t RESERVED_175[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1; /**< RX Power UP Time Register #1, offset: 0x600B4 */
       uint8_t RESERVED_176[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2; /**< RX Power UP Time Register #2, offset: 0x600B8 */
       uint8_t RESERVED_177[2];
  __IO uint16_t LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3; /**< RX Power UP Time Register #3, offset: 0x600BC */
       uint8_t RESERVED_178[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0; /**< RX VCO calibration controls register #0, offset: 0x600C0 */
       uint8_t RESERVED_179[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1; /**< RX VCO calibration controls register #1, offset: 0x600C4 */
       uint8_t RESERVED_180[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2; /**< RX VCO calibration controls register #2, offset: 0x600C8 */
       uint8_t RESERVED_181[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0; /**< RX Power UP Time Register #0, offset: 0x600CC */
       uint8_t RESERVED_182[2];
  __IO uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1; /**< RX Power UP Time Register #1, offset: 0x600D0 */
       uint8_t RESERVED_183[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0; /**< RX VCO status register #0, offset: 0x600D4 */
       uint8_t RESERVED_184[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1; /**< RX VCO status register #1, offset: 0x600D8 */
       uint8_t RESERVED_185[2];
  __I  uint16_t LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2; /**< RX VCO status register #2, offset: 0x600DC */
       uint8_t RESERVED_186[2];
  __IO uint16_t LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK; /**< XAUI_COMMA Mask, offset: 0x600E0 */
       uint8_t RESERVED_187[2];
  __IO uint16_t LANE0_DIG_RX_LBERT_CTL;            /**< Pattern Matcher controls, offset: 0x600E4 */
       uint8_t RESERVED_188[2];
  __IO uint16_t LANE0_DIG_RX_LBERT_ERR;            /**< Pattern match error counter, offset: 0x600E8 */
       uint8_t RESERVED_189[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_0;        /**< Control bits for receiver in recovered domain, offset: 0x600EC */
       uint8_t RESERVED_190[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_1;        /**< CDR Control Register #1, offset: 0x600F0 */
       uint8_t RESERVED_191[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_2;        /**< CDR Control Register #2, offset: 0x600F4 */
       uint8_t RESERVED_192[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_3;        /**< CDR Control Register #3, offset: 0x600F8 */
       uint8_t RESERVED_193[2];
  __IO uint16_t LANE0_DIG_RX_CDR_CDR_CTL_4;        /**< CDR Control Register #4, offset: 0x600FC */
       uint8_t RESERVED_194[2];
  __I  uint16_t LANE0_DIG_RX_CDR_STAT;             /**< Current output values to dpll (phug, frug), offset: 0x60100 */
       uint8_t RESERVED_195[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ;            /**< Current frequency integrator value., offset: 0x60104 */
       uint8_t RESERVED_196[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ_BOUND_0;    /**< Frequency Bounds for incoming data stream #0, offset: 0x60108 */
       uint8_t RESERVED_197[2];
  __IO uint16_t LANE0_DIG_RX_DPLL_FREQ_BOUND_1;    /**< Frequency Bounds for incoming data stream #1, offset: 0x6010C */
       uint8_t RESERVED_198[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0;   /**< Adaptation Configuration Register #0, offset: 0x60110 */
       uint8_t RESERVED_199[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1;   /**< Adaptation Configuration Register #1, offset: 0x60114 */
       uint8_t RESERVED_200[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2;   /**< Adaptation Configuration Register #2, offset: 0x60118 */
       uint8_t RESERVED_201[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3;   /**< Adaptation Configuration Register #3, offset: 0x6011C */
       uint8_t RESERVED_202[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4;   /**< Adaptation Configuration Register #4, offset: 0x60120 */
       uint8_t RESERVED_203[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5;   /**< Adaptation Configuration Register #5, offset: 0x60124 */
       uint8_t RESERVED_204[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6;   /**< Adaptation Configuration Register #6, offset: 0x60128 */
       uint8_t RESERVED_205[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7;   /**< Adaptation Configuration Register #7, offset: 0x6012C */
       uint8_t RESERVED_206[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8;   /**< Adaptation Configuration Register #8, offset: 0x60130 */
       uint8_t RESERVED_207[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9;   /**< Adaptation Configuration Register #9, offset: 0x60134 */
       uint8_t RESERVED_208[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG; /**< Reset Adaptation Configuration Register, offset: 0x60138 */
       uint8_t RESERVED_209[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_ATT_STATUS;   /**< Value of ATT Adaptation code, offset: 0x6013C */
       uint8_t RESERVED_210[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_VGA_STATUS;   /**< Value of VGA Adaptation code, offset: 0x60140 */
       uint8_t RESERVED_211[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_CTLE_STATUS;  /**< Value of CTLE Adaptation code, offset: 0x60144 */
       uint8_t RESERVED_212[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS; /**< Value of DFE Tap1 Adaptation code, offset: 0x60148 */
       uint8_t RESERVED_213[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS; /**< Value of DFE Tap2 Adaptation code, offset: 0x6014C */
       uint8_t RESERVED_214[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS; /**< Value of DFE Tap3 Adaptation code, offset: 0x60150 */
       uint8_t RESERVED_215[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS; /**< Value of DFE Tap4 Adaptation code, offset: 0x60154 */
       uint8_t RESERVED_216[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS; /**< Value of DFE Tap5 Adaptation code, offset: 0x60158 */
       uint8_t RESERVED_217[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST; /**< Offset values for RX DFE Data Even vDAC, offset: 0x6015C */
       uint8_t RESERVED_218[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST; /**< Offset values for RX DFE Data Odd vDAC, offset: 0x60160 */
       uint8_t RESERVED_219[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN; /**< Sets values for RX SLICER CTRL EVEN signals going to ANA, offset: 0x60164 */
       uint8_t RESERVED_220[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD; /**< Sets values for RX SLICER CTRL ODD signals going to ANA, offset: 0x60168 */
       uint8_t RESERVED_221[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST; /**< Offset values for RX DFE Error Even vDAC, offset: 0x6016C */
       uint8_t RESERVED_222[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST; /**< Offset values for RX DFE Error Odd vDAC, offset: 0x60170 */
       uint8_t RESERVED_223[2];
  __I  uint16_t LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL; /**< Value of Error Slicer Level, offset: 0x60174 */
       uint8_t RESERVED_224[2];
  __IO uint16_t LANE0_DIG_RX_ADPTCTL_ADPT_RESET;   /**< Adaptation reset register, offset: 0x60178 */
       uint8_t RESERVED_225[2];
  __IO uint16_t LANE0_DIG_RX_STAT_LD_VAL_1;        /**< Stat load value for the sample counter #1, offset: 0x6017C */
       uint8_t RESERVED_226[2];
  __IO uint16_t LANE0_DIG_RX_STAT_DATA_MSK;        /**< Stat data mask bits [15:0], offset: 0x60180 */
       uint8_t RESERVED_227[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL0;      /**< Stat match controls register #0, offset: 0x60184 */
       uint8_t RESERVED_228[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL1;      /**< Stat match controls register #1, offset: 0x60188 */
       uint8_t RESERVED_229[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL0;       /**< Stat controls register #0, offset: 0x6018C */
       uint8_t RESERVED_230[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL1;       /**< Stat controls register #1, offset: 0x60190 */
       uint8_t RESERVED_231[2];
  __I  uint16_t LANE0_DIG_RX_STAT_SMPL_CNT1;       /**< Sample Counter #1 Status, offset: 0x60194 */
       uint8_t RESERVED_232[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_0;      /**< Stat Counter 0 Status, offset: 0x60198 */
       uint8_t RESERVED_233[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_1;      /**< Stat Counter 1 Status, offset: 0x6019C */
       uint8_t RESERVED_234[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_2;      /**< Stat Counter 2 Status, offset: 0x601A0 */
       uint8_t RESERVED_235[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_3;      /**< Stat Counter 3 Status, offset: 0x601A4 */
       uint8_t RESERVED_236[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_4;      /**< Stat Counter 4 Status, offset: 0x601A8 */
       uint8_t RESERVED_237[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_5;      /**< Stat Counter 5 Status, offset: 0x601AC */
       uint8_t RESERVED_238[2];
  __I  uint16_t LANE0_DIG_RX_STAT_STAT_CNT_6;      /**< Stat Counter 6 Status, offset: 0x601B0 */
       uint8_t RESERVED_239[2];
  __IO uint16_t LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL; /**< Calibration Comparator Control, offset: 0x601B4 */
       uint8_t RESERVED_240[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL2;      /**< Stat match controls register #2, offset: 0x601B8 */
       uint8_t RESERVED_241[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL3;      /**< Stat match controls register #3, offset: 0x601BC */
       uint8_t RESERVED_242[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL4;      /**< Stat match controls register #4, offset: 0x601C0 */
       uint8_t RESERVED_243[2];
  __IO uint16_t LANE0_DIG_RX_STAT_MATCH_CTL5;      /**< Stat match controls register #5, offset: 0x601C4 */
       uint8_t RESERVED_244[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_CTL2;       /**< Stat controls register #2, offset: 0x601C8 */
       uint8_t RESERVED_245[2];
  __IO uint16_t LANE0_DIG_RX_STAT_STAT_STOP;       /**< Stat stop register, offset: 0x601CC */
       uint8_t RESERVED_246[2];
  __IO uint16_t LANE0_DIG_ANA_TX_OVRD_OUT;         /**< Override values for TX signals going to ANA, offset: 0x601D0 */
       uint8_t RESERVED_247[2];
  __IO uint16_t LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT; /**< Override value for TX termination code going to ANA, offset: 0x601D4 */
       uint8_t RESERVED_248[2];
  __IO uint16_t LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT; /**< Override value for TX termination code clocks going to ANA, offset: 0x601D8 */
       uint8_t RESERVED_249[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0;    /**< Override values for TX EQ signals going to ANA register #0, offset: 0x601DC */
       uint8_t RESERVED_250[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1;    /**< Override values for TX EQ signals going to ANA register #1, offset: 0x601E0 */
       uint8_t RESERVED_251[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2;    /**< Override values for TX EQ signals going to ANA register #2, offset: 0x601E4 */
       uint8_t RESERVED_252[2];
  __IO uint16_t LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3;    /**< Override values for TX EQ signals going to ANA register #3, offset: 0x601E8 */
       uint8_t RESERVED_253[2];
  __IO uint16_t LANE0_DIG_ANA_RX_CTL_OVRD_OUT;     /**< Override values for RX control signals going to ANA, offset: 0x601EC */
       uint8_t RESERVED_254[2];
  __IO uint16_t LANE0_DIG_ANA_RX_PWR_OVRD_OUT;     /**< Override values for RX PWR UP/DN signals going to ANA, offset: 0x601F0 */
       uint8_t RESERVED_255[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0;   /**< RX VCO Outgoing Signals Override ANA #0, offset: 0x601F4 */
       uint8_t RESERVED_256[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1;   /**< Override values for RX VCO signals going to ANA #1, offset: 0x601F8 */
       uint8_t RESERVED_257[2];
  __IO uint16_t LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2;   /**< RX VCO Outgoing Signals Override ANA #2, offset: 0x601FC */
       uint8_t RESERVED_258[2];
  __IO uint16_t LANE0_DIG_ANA_RX_CAL;              /**< Sets values for RX CAL signals going to ANA register, offset: 0x60200 */
       uint8_t RESERVED_259[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL;         /**< Sets values for RX DAC CTRL value going to ANA, offset: 0x60204 */
       uint8_t RESERVED_260[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL_OVRD;    /**< Overrides RX DAC CTRL bus (en/val/sel) going to ANA, offset: 0x60208 */
       uint8_t RESERVED_261[2];
  __IO uint16_t LANE0_DIG_ANA_RX_DAC_CTRL_SEL;     /**< Sets values for RX DAC CTRL Select signal going to ANA, offset: 0x6020C */
       uint8_t RESERVED_262[2];
  __IO uint16_t LANE0_DIG_ANA_RX_AFE_ATT_VGA;      /**< Value for RX AFE ATT & VGA signals going to ANA, offset: 0x60210 */
       uint8_t RESERVED_263[2];
  __IO uint16_t LANE0_DIG_ANA_RX_AFE_CTLE;         /**< Values for RX AFE CTLE signals going to ANA, offset: 0x60214 */
       uint8_t RESERVED_264[2];
  __IO uint16_t LANE0_DIG_ANA_RX_SCOPE;            /**< Values for RX SCOPE signals going to ANA, offset: 0x60218 */
       uint8_t RESERVED_265[2];
  __IO uint16_t LANE0_DIG_ANA_RX_SLICER_CTRL;      /**< Sets values for RX Slicer Ctrl signals going to ANA register, offset: 0x6021C */
       uint8_t RESERVED_266[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST; /**< Sets values for RX ANA IQ PHASE Adjust signal going to ANA register, offset: 0x60220 */
       uint8_t RESERVED_267[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN;  /**< Sets values for RX ANA IQ SENSE signal, offset: 0x60224 */
       uint8_t RESERVED_268[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN; /**< DAC CTRL enable signal, offset: 0x60228 */
       uint8_t RESERVED_269[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE; /**< Afe update enable signal, offset: 0x6022C */
       uint8_t RESERVED_270[2];
  __IO uint16_t LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK; /**< Phase adjust clock signal, offset: 0x60230 */
       uint8_t RESERVED_271[2];
  __I  uint16_t LANE0_DIG_ANA_STATUS_0;            /**< Lane input status register #0, offset: 0x60234 */
       uint8_t RESERVED_272[2];
  __I  uint16_t LANE0_DIG_ANA_STATUS_1;            /**< Lane input status register #1, offset: 0x60238 */
       uint8_t RESERVED_273[2];
  __IO uint16_t LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT; /**< Override value for RX termination code going to ANA, offset: 0x6023C */
       uint8_t RESERVED_274[2];
  __IO uint16_t LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT; /**< Override value for RX termination code clock going to ANA, offset: 0x60240 */
       uint8_t RESERVED_275[2];
  __IO uint16_t LANE0_ANA_TX_OVRD_MEAS;            /**< TX_OVRD_MEAS, offset: 0x60244 */
       uint8_t RESERVED_276[2];
  __IO uint16_t LANE0_ANA_TX_PWR_OVRD;             /**< TX_PWR_OVRD, offset: 0x60248 */
       uint8_t RESERVED_277[2];
  __IO uint16_t LANE0_ANA_TX_ALT_BUS;              /**< TX_ALT_BUS, offset: 0x6024C */
       uint8_t RESERVED_278[2];
  __IO uint16_t LANE0_ANA_TX_ATB1;                 /**< TX_ATB1, offset: 0x60250 */
       uint8_t RESERVED_279[2];
  __IO uint16_t LANE0_ANA_TX_ATB2;                 /**< TX_ATB2, offset: 0x60254 */
       uint8_t RESERVED_280[2];
  __IO uint16_t LANE0_ANA_TX_VBOOST;               /**< TX_VBOOST, offset: 0x60258 */
       uint8_t RESERVED_281[2];
  __IO uint16_t LANE0_ANA_TX_TERM_CODE;            /**< TX_TERM_CODE, offset: 0x6025C */
       uint8_t RESERVED_282[2];
  __IO uint16_t LANE0_ANA_TX_TERM_CODE_CTRL;       /**< TX_TERM_CODE_CTRL, offset: 0x60260 */
       uint8_t RESERVED_283[2];
  __IO uint16_t LANE0_ANA_TX_IBOOST_CODE;          /**< TX_IBOOST_CODE, offset: 0x60264 */
       uint8_t RESERVED_284[2];
  __IO uint16_t LANE0_ANA_TX_OVRD_CLK;             /**< TX_OVRD_CLK, offset: 0x60268 */
       uint8_t RESERVED_285[2];
  __IO uint16_t LANE0_ANA_TX_MISC;                 /**< TX_MISC, offset: 0x6026C */
       uint8_t RESERVED_286[2];
  __IO uint16_t LANE0_ANA_RX_ATB_IQSKEW;           /**< RX_ATB_IQSKEW, offset: 0x60270 */
       uint8_t RESERVED_287[2];
  __IO uint16_t LANE0_ANA_RX_DCC_OVRD;             /**< RX_DCC_OVRD, offset: 0x60274 */
       uint8_t RESERVED_288[2];
  __IO uint16_t LANE0_ANA_RX_PWR_CTRL1;            /**< RX_PWR_CTRL1, offset: 0x60278 */
       uint8_t RESERVED_289[2];
  __IO uint16_t LANE0_ANA_RX_ATB_REGREF;           /**< RX_ATB_REGREF, offset: 0x6027C */
       uint8_t RESERVED_290[2];
  __IO uint16_t LANE0_ANA_RX_CDR_AFE;              /**< RX_CDR_AFE, offset: 0x60280 */
       uint8_t RESERVED_291[2];
  __IO uint16_t LANE0_ANA_RX_PWR_CTRL2;            /**< RX_PWR_CTRL2, offset: 0x60284 */
       uint8_t RESERVED_292[2];
  __IO uint16_t LANE0_ANA_RX_MISC_OVRD;            /**< RX_MISC_OVRD, offset: 0x60288 */
       uint8_t RESERVED_293[2];
  __IO uint16_t LANE0_ANA_RX_CAL_MUXA;             /**< RX_CAL_MUXA, offset: 0x6028C */
       uint8_t RESERVED_294[2];
  __IO uint16_t LANE0_ANA_RX_ATB_MEAS1;            /**< RX_ATB_MEAS1, offset: 0x60290 */
       uint8_t RESERVED_295[2];
  __IO uint16_t LANE0_ANA_RX_ATB_MEAS2;            /**< RX_ATB_MEAS2, offset: 0x60294 */
       uint8_t RESERVED_296[2];
  __IO uint16_t LANE0_ANA_RX_CAL_MUXB;             /**< RX_CAL_MUXB, offset: 0x60298 */
       uint8_t RESERVED_297[2];
  __IO uint16_t LANE0_ANA_RX_TERM;                 /**< RX_TERM, offset: 0x6029C */
       uint8_t RESERVED_298[2];
  __IO uint16_t LANE0_ANA_RX_SLC_CTRL;             /**< RX_SLC_CTRL, offset: 0x602A0 */
       uint8_t RESERVED_299[2];
  __IO uint16_t LANE0_ANA_RX_ATB_VREG;             /**< RX_ATB_VREG, offset: 0x602A4 */
       uint8_t RESERVED_300[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_IN;    /**< Override values for incoming TX controls from PCS, offset: 0x602A8 */
       uint8_t RESERVED_301[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1;  /**< Override values for incoming TX controls from PCS, register #1, offset: 0x602AC */
       uint8_t RESERVED_302[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_TX_PCS_IN;     /**< Current values for incoming TX controls from PCS, offset: 0x602B0 */
       uint8_t RESERVED_303[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT;   /**< Override values for outgoing TX controls to PCS, offset: 0x602B4 */
       uint8_t RESERVED_304[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_TX_PCS_OUT;    /**< Current values for outgoing TX status controls from Raw PCS, offset: 0x602B8 */
       uint8_t RESERVED_305[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN;    /**< Override values for incoming RX controls from PCS, offset: 0x602BC */
       uint8_t RESERVED_306[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1;  /**< Override values for incoming RX controls from PCS, register #1, offset: 0x602C0 */
       uint8_t RESERVED_307[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2;  /**< Override values for incoming RX controls from PCS, register #2, offset: 0x602C4 */
       uint8_t RESERVED_308[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3;  /**< Override values for incoming RX controls from PCS, register #3, offset: 0x602C8 */
       uint8_t RESERVED_309[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN;     /**< Current values for incoming RX controls from PCS, offset: 0x602CC */
       uint8_t RESERVED_310[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1;   /**< Current values for incoming RX controls from PCS, register #1, offset: 0x602D0 */
       uint8_t RESERVED_311[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2;   /**< Current values for incoming RX controls from PCS, register #2, offset: 0x602D4 */
       uint8_t RESERVED_312[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3;   /**< Current values for incoming RX controls from PCS, register #3, offset: 0x602D8 */
       uint8_t RESERVED_313[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4;   /**< Current values for incoming RX controls from PCS, register #4, offset: 0x602DC */
       uint8_t RESERVED_314[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT;   /**< Override values for outgoing RX controls to PCS, offset: 0x602E0 */
       uint8_t RESERVED_315[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_RX_PCS_OUT;    /**< Current values for outgoing RX status controls from Raw PCS, offset: 0x602E4 */
       uint8_t RESERVED_316[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK;  /**< RX Adaptation Acknowledge, offset: 0x602E8 */
       uint8_t RESERVED_317[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM;  /**< RX Adaptation Figure of Merit, offset: 0x602EC */
       uint8_t RESERVED_318[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR;  /**< RX calculated direction for TX-pre, offset: 0x602F0 */
       uint8_t RESERVED_319[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR; /**< RX calculated direction for TX-Main, offset: 0x602F4 */
       uint8_t RESERVED_320[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR; /**< RX calculated direction for TX-Post, offset: 0x602F8 */
       uint8_t RESERVED_321[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_LANE_NUMBER;   /**< Current lane number, offset: 0x602FC */
       uint8_t RESERVED_322[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN; /**< Override incoming values for lane_xcvr_mode, offset: 0x60300 */
       uint8_t RESERVED_323[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN; /**< Lane transceiver mode status, offset: 0x60304 */
       uint8_t RESERVED_324[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN;   /**< ATE Override input to control top-level inputs, offset: 0x60308 */
       uint8_t RESERVED_325[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN; /**< Override incoming values for rx_eq_delta_iq, offset: 0x6030C */
       uint8_t RESERVED_326[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN; /**< Override incoming values for tx/rx_term_ctrl, offset: 0x60310 */
       uint8_t RESERVED_327[2];
  __I  uint16_t RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN; /**< tx/rx_term_ctrl status, offset: 0x60314 */
       uint8_t RESERVED_328[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1; /**< Override values for outgoing RX controls to PCS, register #1, offset: 0x60318 */
       uint8_t RESERVED_329[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1; /**< Override values for incoming RX EQ controls from PCS, register #1, offset: 0x6031C */
       uint8_t RESERVED_330[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2; /**< Override values for incoming RX EQ controls from PCS, register #2, offset: 0x60320 */
       uint8_t RESERVED_331[2];
  __IO uint16_t RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2; /**< Override value for RX VALID/DATA_EN/DATA_EN/LANE_TX2RX_SER_LB_EN/LANE_RX2TX_PAR_LB_EN signal from PCS, offset: 0x60324 */
       uint8_t RESERVED_332[2];
  __IO uint16_t RAWLANE0_DIG_FSM_FSM_OVRD_CTL;     /**< FSM override control register, offset: 0x60328 */
       uint8_t RESERVED_333[2];
  __I  uint16_t RAWLANE0_DIG_FSM_MEM_ADDR_MON;     /**< Memory Address Monitor, offset: 0x6032C */
       uint8_t RESERVED_334[2];
  __I  uint16_t RAWLANE0_DIG_FSM_STATUS_MON;       /**< FSM Status Monitor, offset: 0x60330 */
       uint8_t RESERVED_335[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL; /**< Status of Fast RX Start Up Calibration, offset: 0x60334 */
       uint8_t RESERVED_336[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_ADAPT;    /**< Status of Fast RX Adaptation, offset: 0x60338 */
       uint8_t RESERVED_337[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL;  /**< Status of Fast RX AFE Calibration, offset: 0x6033C */
       uint8_t RESERVED_338[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL;  /**< Status of Fast RX DFE Calibration, offset: 0x60340 */
       uint8_t RESERVED_339[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT; /**< Enables fast RX DFE re -adaptation, offset: 0x60344 */
       uint8_t RESERVED_340[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL; /**< Status of Fast RX Reference Level Calibration, offset: 0x60348 */
       uint8_t RESERVED_341[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL;   /**< Status of Fast RX IQ Calibration, offset: 0x6034C */
       uint8_t RESERVED_342[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT; /**< Status of Fast RX AFE Adaptation, offset: 0x60350 */
       uint8_t RESERVED_343[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT; /**< Status of Fast RX DFE Adaptation, offset: 0x60354 */
       uint8_t RESERVED_344[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_SUP;         /**< Status of Fast Support block, offset: 0x60358 */
       uint8_t RESERVED_345[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE; /**< Status of Fast TX Common-mode Charge-up, offset: 0x6035C */
       uint8_t RESERVED_346[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_TX_RXDET;    /**< Status of Fast TX detect RX, offset: 0x60360 */
       uint8_t RESERVED_347[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_PWRUP;    /**< Status of Fast RX Power-up, offset: 0x60364 */
       uint8_t RESERVED_348[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT; /**< Status of Fast RX VCO Wait Times, offset: 0x60368 */
       uint8_t RESERVED_349[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL;  /**< Status of Fast RX VCO Calibration, offset: 0x6036C */
       uint8_t RESERVED_350[2];
  __I  uint16_t RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS; /**< Status of MPLL common calibration initiation, offset: 0x60370 */
       uint8_t RESERVED_351[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT; /**< Status of Fast RX Continuous Calibration/Adaptation, offset: 0x60374 */
       uint8_t RESERVED_352[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT; /**< Status of Fast RX Continuous Adaptation, offset: 0x60378 */
       uint8_t RESERVED_353[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL; /**< Status of Fast RX Continuous Data Calibration, offset: 0x6037C */
       uint8_t RESERVED_354[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL; /**< Status of Fast RX Continuous Phase Calibration, offset: 0x60380 */
       uint8_t RESERVED_355[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL; /**< Status of Fast RX Continuous AFE Calibration, offset: 0x60384 */
       uint8_t RESERVED_356[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT; /**< Status of Fast RX IQ_ADAPT, offset: 0x60388 */
       uint8_t RESERVED_357[2];
  __I  uint16_t RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD;  /**< Status of RX Delta addition, offset: 0x6038C */
       uint8_t RESERVED_358[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT; /**< Enables fast RX ATT adaptation, offset: 0x60390 */
       uint8_t RESERVED_359[2];
  __I  uint16_t RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT; /**< Enables fast RX CTLE adaptation, offset: 0x60394 */
       uint8_t RESERVED_360[2];
  __IO uint16_t RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN; /**< CR interface timing extension enable, offset: 0x60398 */
       uint8_t RESERVED_361[2];
  __IO uint16_t RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG; /**< TX Eq update flag, offset: 0x6039C */
       uint8_t RESERVED_362[2];
  __I  uint16_t RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS; /**< Status of RTUNE common calibration initiation, offset: 0x603A0 */
       uint8_t RESERVED_363[2];
  __I  uint16_t RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET; /**< Offset value for IQ Phase Calculation, offset: 0x603A4 */
       uint8_t RESERVED_364[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST; /**< Offset value for RX AFE ATT iDAC, offset: 0x603A8 */
       uint8_t RESERVED_365[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST; /**< Offset value for RX AFE CTLE iDAC, offset: 0x603AC */
       uint8_t RESERVED_366[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE; /**< Reference level for RX AFE Adaptation, offset: 0x603B0 */
       uint8_t RESERVED_367[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADAPT_FOM;     /**< Adaptation Figure of Merit (FOM), offset: 0x603B4 */
       uint8_t RESERVED_368[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST; /**< Offset values for RX CTLE Loopback path iDAC, offset: 0x603B8 */
       uint8_t RESERVED_369[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST; /**< Offset values for RX DFE Phase Even vDAC, offset: 0x603BC */
       uint8_t RESERVED_370[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST; /**< Offset values for RX DFE Phase Odd vDAC, offset: 0x603C0 */
       uint8_t RESERVED_371[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL; /**< DFE Even reference level, offset: 0x603C4 */
       uint8_t RESERVED_372[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_ODD_REF_LVL;  /**< DFE Odd reference level, offset: 0x603C8 */
       uint8_t RESERVED_373[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_LIN;    /**< RX Phase Adjust Linear Value, offset: 0x603CC */
       uint8_t RESERVED_374[2];
  __I  uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_MAP;    /**< RX Phase Adjust Mapped Value, offset: 0x603D0 */
       uint8_t RESERVED_375[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST; /**< Offset values for RX DFE Data Even High vDAC, offset: 0x603D4 */
       uint8_t RESERVED_376[2];
  __IO uint16_t RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL; /**< Custom tx_iboost_lvl values for lfps and ss modes, offset: 0x603D8 */
       uint8_t RESERVED_377[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST; /**< Offset values for RX DFE Data Odd High vDAC, offset: 0x603DC */
       uint8_t RESERVED_378[2];
  __IO uint16_t RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS; /**< Override tx_eq_pre/post/main value in LFPS mode, offset: 0x603E0 */
       uint8_t RESERVED_379[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST; /**< Offset values for RX DFE By-Pass Even vDAC, offset: 0x603E4 */
       uint8_t RESERVED_380[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST; /**< Offset values for RX DFE By-Pass Odd vDAC, offset: 0x603E8 */
       uint8_t RESERVED_381[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST; /**< Offset values for RX DFE Error Even vDAC, offset: 0x603EC */
       uint8_t RESERVED_382[2];
  __IO uint16_t RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST; /**< Offset values for RX DFE Error Odd vDAC, offset: 0x603F0 */
       uint8_t RESERVED_383[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST; /**< Value for RX IQ PHASE Adjust, offset: 0x603F4 */
       uint8_t RESERVED_384[2];
  __IO uint16_t RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE; /**< MPLLA_COARSE_TUNE, offset: 0x603F8 */
       uint8_t RESERVED_385[2];
  __IO uint16_t RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE; /**< MPLLB_COARSE_TUNE, offset: 0x603FC */
       uint8_t RESERVED_386[2];
  __IO uint16_t RAWLANE0_DIG_AON_INIT_PWRUP_DONE;  /**< Initial Power-Up Done Status, offset: 0x60400 */
       uint8_t RESERVED_387[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_ATT;      /**< RX Adapted value of ATT, offset: 0x60404 */
       uint8_t RESERVED_388[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_VGA;      /**< RX Adapted value of VGA, offset: 0x60408 */
       uint8_t RESERVED_389[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_CTLE;     /**< RX Adapted value of CTLE, offset: 0x6040C */
       uint8_t RESERVED_390[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1; /**< RX Adapted value of DFE TAP1, offset: 0x60410 */
       uint8_t RESERVED_391[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADAPT_DONE;    /**< RX Adaptation Done Status, offset: 0x60414 */
       uint8_t RESERVED_392[2];
  __IO uint16_t RAWLANE0_DIG_AON_FAST_FLAGS;       /**< Fast flags for simulation only, offset: 0x60418 */
       uint8_t RESERVED_393[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2; /**< RX Adapted value of DFE TAP2, offset: 0x6041C */
       uint8_t RESERVED_394[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT; /**< RX last stable iq phase of Right of the eye, offset: 0x60420 */
       uint8_t RESERVED_395[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT; /**< RX last stable iq phase of Left of the eye, offset: 0x60424 */
       uint8_t RESERVED_396[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT; /**< RX Adapted value of PHASE IQ, offset: 0x60428 */
       uint8_t RESERVED_397[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN; /**< Sets values for RX SLICER CTRL EVEN signals going to ANA, offset: 0x6042C */
       uint8_t RESERVED_398[2];
  __IO uint16_t RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD; /**< Sets values for RX SLICER CTRL ODD signals going to ANA, offset: 0x60430 */
       uint8_t RESERVED_399[2];
  __IO uint16_t RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS; /**< MPLL Common Calibration Status, offset: 0x60434 */
       uint8_t RESERVED_400[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_0;       /**< Adaptation Control register #0, offset: 0x60438 */
       uint8_t RESERVED_401[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_1;       /**< Adaptation Control register #1, offset: 0x6043C */
       uint8_t RESERVED_402[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_2;       /**< Adaptation Control register #2, offset: 0x60440 */
       uint8_t RESERVED_403[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_3;       /**< Adaptation Control register #3, offset: 0x60444 */
       uint8_t RESERVED_404[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_4;       /**< Adaptation Control register #4, offset: 0x60448 */
       uint8_t RESERVED_405[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_5;       /**< Adaptation Control register #5, offset: 0x6044C */
       uint8_t RESERVED_406[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_6;       /**< Adaptation Control register #6, offset: 0x60450 */
       uint8_t RESERVED_407[2];
  __IO uint16_t RAWLANE0_DIG_AON_ADPT_CTL_7;       /**< Adaptation Control register #7, offset: 0x60454 */
       uint8_t RESERVED_408[2];
  __IO uint16_t RAWLANE0_DIG_AON_MPLL_DISABLE;     /**< LANE_MPLLA/B_DISABLE override, offset: 0x60458 */
       uint8_t RESERVED_409[2];
  __IO uint16_t RAWLANE0_DIG_AON_FAST_FLAGS_2;     /**< Fast flags for simulation only, offset: 0x6045C */
       uint8_t RESERVED_410[2];
  __IO uint16_t RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS; /**< RTUNE Common Calibration Status, offset: 0x60460 */
       uint8_t RESERVED_411[2];
  __IO uint16_t RAWLANE0_DIG_AON_TXRX_OVRD_IN;     /**< Override values for incoming AON TX/RX controls from PCS, offset: 0x60464 */
       uint8_t RESERVED_412[2];
  __IO uint16_t RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST; /**< Offset value for RX AFE ATT_2 iDAC, offset: 0x60468 */
       uint8_t RESERVED_413[2];
  __IO uint16_t RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN;  /**< Override incoming values for rxtx_cc, offset: 0x6046C */
       uint8_t RESERVED_414[2];
  __I  uint16_t RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN; /**< Incoming value of CC status from TCA, offset: 0x60470 */
       uint8_t RESERVED_415[2];
  __I  uint16_t RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT; /**< Current values for outgoing CC status to PMA, offset: 0x60474 */
       uint8_t RESERVED_416[2];
  __IO uint16_t RAWLANE0_DIG_AON_RESERVED_REG_1;   /**< Reserved for future use, offset: 0x60478 */
       uint8_t RESERVED_417[2];
  __IO uint16_t RAWLANE0_DIG_AON_RESERVED_REG_2;   /**< Reserved for future use, offset: 0x6047C */
       uint8_t RESERVED_418[2];
  __IO uint16_t RAWLANE0_DIG_AON_RESERVED_REG_3;   /**< Reserved for future use, offset: 0x60480 */
       uint8_t RESERVED_419[2];
  __IO uint16_t RAWLANE0_DIG_AON_RESERVED_REG_4;   /**< Reserved for future use, offset: 0x60484 */
       uint8_t RESERVED_420[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ; /**< Reset routine request, offset: 0x60488 */
       uint8_t RESERVED_421[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ; /**< Rx reset interrupt, offset: 0x6048C */
       uint8_t RESERVED_422[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ;   /**< Rx request interrupt, offset: 0x60490 */
       uint8_t RESERVED_423[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ;  /**< Rx rate change interrupt request, offset: 0x60494 */
       uint8_t RESERVED_424[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ; /**< Rx pstate change interrupt request, offset: 0x60498 */
       uint8_t RESERVED_425[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ; /**< Rx adaptation request interrupt, offset: 0x6049C */
       uint8_t RESERVED_426[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ; /**< Rx adaptation disable interrupt, offset: 0x604A0 */
       uint8_t RESERVED_427[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR; /**< RX reset interrupt clear, offset: 0x604A4 */
       uint8_t RESERVED_428[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR; /**< RX request interrupt clear, offset: 0x604A8 */
       uint8_t RESERVED_429[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR; /**< RX rate change interrupt clear, offset: 0x604AC */
       uint8_t RESERVED_430[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR; /**< RX pstate change interrupt clear, offset: 0x604B0 */
       uint8_t RESERVED_431[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR; /**< RX adaptation request interrupt clear, offset: 0x604B4 */
       uint8_t RESERVED_432[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR; /**< RX adaptation disable interrupt clear, offset: 0x604B8 */
       uint8_t RESERVED_433[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_IRQ_MASK;     /**< Interrupt Mask, offset: 0x604BC */
       uint8_t RESERVED_434[2];
  __I  uint16_t RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ; /**< Lane transceiver mode interrupt, offset: 0x604C0 */
       uint8_t RESERVED_435[2];
  __IO uint16_t RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR; /**< Lane transceiver mode interrupt clear, offset: 0x604C4 */
       uint8_t RESERVED_436[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN;  /**< Override values for incoming LANE controls, offset: 0x604C8 */
       uint8_t RESERVED_437[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT; /**< Override values for outgoing LANE controls, offset: 0x604CC */
       uint8_t RESERVED_438[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN;   /**< Override values for incoming SUP controls from PMA, offset: 0x604D0 */
       uint8_t RESERVED_439[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_SUP_PMA_IN;    /**< Current values for incoming MPLL status controls from PMA, offset: 0x604D4 */
       uint8_t RESERVED_440[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT;   /**< Override values for outgoing TX controls to PMA, offset: 0x604D8 */
       uint8_t RESERVED_441[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_TX_PMA_IN;     /**< Current values for coming TX status controls from PMA, offset: 0x604DC */
       uint8_t RESERVED_442[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT;   /**< Override values for outgoing RX controls to PMA, offset: 0x604E0 */
       uint8_t RESERVED_443[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_RX_PMA_IN;     /**< Current values for coming RX status controls from PMA, offset: 0x604E4 */
       uint8_t RESERVED_444[2];
  __IO uint16_t RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL; /**< Lane Rtune Controls, offset: 0x604E8 */
       uint8_t RESERVED_445[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1;  /**< Current values for incoming RTUNE status controls from PMA, offset: 0x604EC */
       uint8_t RESERVED_446[2];
  __I  uint16_t RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID; /**< Current value of RX valid from PMA, offset: 0x604F0 */
       uint8_t RESERVED_447[2];
  __IO uint16_t RAWLANE0_DIG_TX_CTL_TX_FSM_CTL;    /**< TX FSM Control, offset: 0x604F4 */
       uint8_t RESERVED_448[2];
  __IO uint16_t RAWLANE0_DIG_TX_CTL_TX_CLK_CTL;    /**< Select clock to act as TX input clock, offset: 0x604F8 */
       uint8_t RESERVED_449[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_FSM_CTL;    /**< RX FSM control register, offset: 0x604FC */
       uint8_t RESERVED_450[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL; /**< RX LOS Mask Control, offset: 0x60500 */
       uint8_t RESERVED_451[2];
  __IO uint16_t RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL; /**< RX Data Enable Override Control, offset: 0x60504 */
       uint8_t RESERVED_452[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS; /**< RX continuous offset cancellation status, offset: 0x60508 */
       uint8_t RESERVED_453[2];
  __I  uint16_t RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS; /**< RX continuous adaptation status, offset: 0x6050C */
       uint8_t RESERVED_454[129778];
  struct {                                         /* offset: 0x80000, array step: index*0x400, index2*0x80, index3*0x4 */
    __I  uint16_t RAWMEM_DIG_ROM_CMN_B_R;            /**< Common Read Only Memory, array offset: 0x80000, array step: index*0x400, index2*0x80, index3*0x4 */
         uint8_t RESERVED_0[2];
  } RAWMEM_DIG_ROM_CMNX_BY_RZ[PHY_ENET_RAWMEM_DIG_ROM_CMNX_COUNT][PHY_ENET_RAWMEM_DIG_ROM_CMNX_RAWMEM_DIG_ROM_CMNX_BY_COUNT][PHY_ENET_RAWMEM_DIG_ROM_CMNX_RAWMEM_DIG_ROM_CMNX_BY_RAWMEM_DIG_ROM_CMNX_BY_RZ_COUNT];
       uint8_t RESERVED_455[114688];
  struct {                                         /* offset: 0xA0000, array step: index*0x400, index2*0x80, index3*0x4 */
    __IO uint16_t RAWMEM_DIG_RAM_CMN_B_R;            /**< Common Random Access Memory, array offset: 0xA0000, array step: index*0x400, index2*0x80, index3*0x4 */
         uint8_t RESERVED_0[2];
  } RAWMEM_DIG_RAM_CMNX_BY_RZ[PHY_ENET_RAWMEM_DIG_RAM_CMNX_COUNT][PHY_ENET_RAWMEM_DIG_RAM_CMNX_RAWMEM_DIG_RAM_CMNX_BY_COUNT][PHY_ENET_RAWMEM_DIG_RAM_CMNX_RAWMEM_DIG_RAM_CMNX_BY_RAWMEM_DIG_RAM_CMNX_BY_RZ_COUNT];
} PHY_ENET_Type;

/* ----------------------------------------------------------------------------
   -- PHY_ENET Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PHY_ENET_Register_Masks PHY_ENET Register Masks
 * @{
 */

/*! @name SUP_DIG_IDCODE_LO - Low 16 bits of IDCODE */
/*! @{ */

#define PHY_ENET_SUP_DIG_IDCODE_LO_data_MASK     (0xFFFFU)
#define PHY_ENET_SUP_DIG_IDCODE_LO_data_SHIFT    (0U)
/*! data - data */
#define PHY_ENET_SUP_DIG_IDCODE_LO_data(x)       (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_IDCODE_LO_data_SHIFT)) & PHY_ENET_SUP_DIG_IDCODE_LO_data_MASK)
/*! @} */

/*! @name SUP_DIG_IDCODE_HI - High 16 bits of IDCODE */
/*! @{ */

#define PHY_ENET_SUP_DIG_IDCODE_HI_data_MASK     (0xFFFFU)
#define PHY_ENET_SUP_DIG_IDCODE_HI_data_SHIFT    (0U)
/*! data - data */
#define PHY_ENET_SUP_DIG_IDCODE_HI_data(x)       (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_IDCODE_HI_data_SHIFT)) & PHY_ENET_SUP_DIG_IDCODE_HI_data_MASK)
/*! @} */

/*! @name SUP_DIG_REFCLK_OVRD_IN - Override values for incoming REFCLK and RESET controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_SHIFT (0U)
/*! REF_CLK_EN - Override value for ref_clk_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT (1U)
/*! REF_CLK_EN_OVRD_EN - Enable override for ref_clk_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_SHIFT (2U)
/*! REF_CLK_DIV2_EN - Override value for ref_clk_div2_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_OVRD_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_OVRD_EN_SHIFT (3U)
/*! REF_CLK_DIV2_EN_OVRD_EN - Enable override for ref_clk_div2_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_DIV2_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_MASK (0x10U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_SHIFT (4U)
/*! REF_USE_PAD - Override value for ref_use_pad */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_OVRD_EN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_OVRD_EN_SHIFT (5U)
/*! REF_USE_PAD_OVRD_EN - Enable override for ref_use_pad */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_USE_PAD_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_SHIFT (6U)
/*! REF_REPEAT_CLK_EN - Override value for ref_repeat_clk_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_OVRD_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_OVRD_EN_SHIFT (7U)
/*! REF_REPEAT_CLK_EN_OVRD_EN - Enable override for ref_repeat_clk_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_REPEAT_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_MASK (0x700U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_SHIFT (8U)
/*! REF_CLK_RANGE - Override value for ref_range */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_OVRD_EN_MASK (0x800U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_OVRD_EN_SHIFT (11U)
/*! REF_CLK_RANGE_OVRD_EN - Enable override for ref_range */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_REF_CLK_RANGE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_SHIFT (12U)
/*! BG_EN - Override value for bg_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_OVRD_EN_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_OVRD_EN_SHIFT (13U)
/*! BG_EN_OVRD_EN - Enable override for bg_en */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_BG_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_RESERVED_15_14_SHIFT)) & PHY_ENET_SUP_DIG_REFCLK_OVRD_IN_RESERVED_15_14_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_IN - Override values for support block ASIC inputs */
/*! @{ */

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_REQ_MASK (0x1U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_REQ_SHIFT (0U)
/*! RTUNE_REQ - Override value for rtune_req */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_REQ_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_REQ_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_OVRD_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_OVRD_EN_SHIFT (1U)
/*! RTUNE_OVRD_EN - Enable override of rtune_req */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RTUNE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_REQ_IN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_REQ_IN_SHIFT (2U)
/*! RES_REQ_IN - Override value for res_req_in */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_REQ_IN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_REQ_IN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_REQ_IN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_ACK_IN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_ACK_IN_SHIFT (3U)
/*! RES_ACK_IN - Override value for res_ack_in */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_ACK_IN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_ACK_IN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_ACK_IN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_OVRD_EN_MASK (0x10U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_OVRD_EN_SHIFT (4U)
/*! RES_OVRD_EN - Enable override of res_req_in and res_ack_in */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RES_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_SUP_OVRD_IN_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_IN_RESERVED_15_5_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_IN_RESERVED_15_5_MASK)
/*! @} */

/*! @name SUP_DIG_SUP_OVRD_OUT - Override values for support block ASIC outputs */
/*! @{ */

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_MASK (0x1U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_SHIFT (0U)
/*! RTUNE_ACK - Override value for rtune_ack output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_OVRD_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_OVRD_EN_SHIFT (1U)
/*! RTUNE_ACK_OVRD_EN - Enable override for rtune_ack output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RTUNE_ACK_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_MASK (0x4U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_SHIFT (2U)
/*! RES_REQ_OUT - Override value for res_req_out output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_OVRD_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_OVRD_EN_SHIFT (3U)
/*! RES_REQ_OUT_OVRD_EN - Enable override for res_req_out output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_REQ_OUT_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_MASK (0x10U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_SHIFT (4U)
/*! RES_ACK_OUT - Override value for res_ack_out output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_OVRD_EN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_OVRD_EN_SHIFT (5U)
/*! RES_ACK_OUT_OVRD_EN - Enable override for res_ack_out output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RES_ACK_OUT_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_MASK (0x40U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_SHIFT (6U)
/*! MPLLA_STATE - Override value for mplla_state output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_OVRD_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_OVRD_EN_SHIFT (7U)
/*! MPLLA_STATE_OVRD_EN - Enable override for mplla_state output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLA_STATE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_MASK (0x100U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_SHIFT (8U)
/*! MPLLB_STATE - Override value for mpllb_state output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_OVRD_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_OVRD_EN_SHIFT (9U)
/*! MPLLB_STATE_OVRD_EN - Enable override for mpllb_state output */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_MPLLB_STATE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_MASK (0x400U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_SHIFT (10U)
/*! BG_LANE_STATE - Override value for bg_lane_state signal */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_EN_MASK (0x800U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_EN_SHIFT (11U)
/*! BG_LANE_STATE_OVRD_EN - Enable override for bg_lane_state signal */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_LANE_STATE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_SHIFT (12U)
/*! BG_SUP_STATE - Override value for bg_sup_state signal */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_EN_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_EN_SHIFT (13U)
/*! BG_SUP_STATE_OVRD_EN - Enable override for bg_sup_state signal */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_BG_SUP_STATE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RESERVED_15_14_SHIFT)) & PHY_ENET_SUP_DIG_SUP_OVRD_OUT_RESERVED_15_14_MASK)
/*! @} */

/*! @name SUP_DIG_LVL_OVRD_IN - Override values for level settings */
/*! @{ */

#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_MASK (0x1FU)
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_SHIFT (0U)
/*! RX_VREF_CTRL - Override value for rx_vref_ctrl */
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_MASK)

#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_SHIFT (5U)
/*! RX_VREF_CTRL_EN - Enable override value for rx_vref_ctrl */
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_SHIFT)) & PHY_ENET_SUP_DIG_LVL_OVRD_IN_RX_VREF_CTRL_EN_MASK)

#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_MASK (0x1C0U)
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_SHIFT (6U)
/*! TX_VBOOST_LVL - Override value for tx_vboost_lvl */
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_SHIFT)) & PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_MASK)

#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_SHIFT (9U)
/*! TX_VBOOST_LVL_EN - Enable override value for tx_vboost_lvl */
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_SHIFT)) & PHY_ENET_SUP_DIG_LVL_OVRD_IN_TX_VBOOST_LVL_EN_MASK)

#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_LVL_OVRD_IN_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_OVRD_IN_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_LVL_OVRD_IN_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_DEBUG - Debug controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_DEBUG_DTB_SEL_MASK      (0x7U)
#define PHY_ENET_SUP_DIG_DEBUG_DTB_SEL_SHIFT     (0U)
/*! DTB_SEL - The lane DTB's are OR'd together with the support DTB signals selected with the below encodings */
#define PHY_ENET_SUP_DIG_DEBUG_DTB_SEL(x)        (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_DEBUG_DTB_SEL_SHIFT)) & PHY_ENET_SUP_DIG_DEBUG_DTB_SEL_MASK)

#define PHY_ENET_SUP_DIG_DEBUG_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_SUP_DIG_DEBUG_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_DEBUG_RESERVED_15_3(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_DEBUG_RESERVED_15_3_SHIFT)) & PHY_ENET_SUP_DIG_DEBUG_RESERVED_15_3_MASK)
/*! @} */

/*! @name SUP_DIG_ASIC_IN - Current values for incoming SUP control signals from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_ASIC_IN_PHY_RESET_MASK  (0x1U)
#define PHY_ENET_SUP_DIG_ASIC_IN_PHY_RESET_SHIFT (0U)
/*! PHY_RESET - Value from ASIC for phy_reset */
#define PHY_ENET_SUP_DIG_ASIC_IN_PHY_RESET(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_PHY_RESET_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_PHY_RESET_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_EN_SHIFT (1U)
/*! REF_CLK_EN - Value from ASIC for ref_clk_en */
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_EN(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_SHIFT (2U)
/*! REF_CLK_DIV2_EN - Value from ASIC for ref_clk_div2_en */
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_REF_CLK_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_SHIFT (3U)
/*! REF_REPEAT_CLK_EN - Value from ASIC for ref_repeat_clk_en */
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_REF_REPEAT_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_REF_USE_PAD_MASK (0x10U)
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_USE_PAD_SHIFT (4U)
/*! REF_USE_PAD - Value from ASIC for ref_use_pad */
#define PHY_ENET_SUP_DIG_ASIC_IN_REF_USE_PAD(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_REF_USE_PAD_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_REF_USE_PAD_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_BURNIN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_BURNIN_SHIFT (5U)
/*! TEST_BURNIN - Value from ASIC for test_burnin */
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_BURNIN(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_TEST_BURNIN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_TEST_BURNIN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_POWERDOWN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_POWERDOWN_SHIFT (6U)
/*! TEST_POWERDOWN - Value from ASIC for test_powerdown */
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_POWERDOWN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_TEST_POWERDOWN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_TEST_POWERDOWN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_REQ_MASK  (0x80U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_REQ_SHIFT (7U)
/*! RTUNE_REQ - Value from ASIC for rtune_req */
#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_REQ(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_REQ_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_REQ_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_ACK_MASK  (0x100U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_ACK_SHIFT (8U)
/*! RTUNE_ACK - Value to ASIC for rtune_ack_i */
#define PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_ACK(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_ACK_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RTUNE_ACK_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_IN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_IN_SHIFT (9U)
/*! RES_REQ_IN - Value from ASIC for res_req_in */
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_IN(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_IN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_IN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_OUT_MASK (0x400U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_OUT_SHIFT (10U)
/*! RES_REQ_OUT - Value to ASIC for res_ack_out_i */
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_OUT(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_OUT_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RES_REQ_OUT_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_IN_MASK (0x800U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_IN_SHIFT (11U)
/*! RES_ACK_IN - Value from ASIC for res_req_in */
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_IN(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_IN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_IN_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_OUT_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_OUT_SHIFT (12U)
/*! RES_ACK_OUT - Value to ASIC for res_ack_out_i */
#define PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_OUT(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_OUT_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_RES_ACK_OUT_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLA_STATE_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLA_STATE_SHIFT (13U)
/*! MPLLA_STATE - Value to ASIC for mplla_state_i */
#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLA_STATE(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_MPLLA_STATE_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_MPLLA_STATE_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLB_STATE_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLB_STATE_SHIFT (14U)
/*! MPLLB_STATE - Value to ASIC for mpllb_state_i */
#define PHY_ENET_SUP_DIG_ASIC_IN_MPLLB_STATE(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_MPLLB_STATE_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_MPLLB_STATE_MASK)

#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_TX_REF_CLK_EN_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_TX_REF_CLK_EN_SHIFT (15U)
/*! TEST_TX_REF_CLK_EN - Value from ASIC for test_tx_refclk_en */
#define PHY_ENET_SUP_DIG_ASIC_IN_TEST_TX_REF_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ASIC_IN_TEST_TX_REF_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ASIC_IN_TEST_TX_REF_CLK_EN_MASK)
/*! @} */

/*! @name SUP_DIG_LVL_ASIC_IN - Current values for incoming level controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_MASK (0x1FU)
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_SHIFT (0U)
/*! RX_VREF_CTRL - Value from ASIC for rx_vref_ctrl */
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_LVL_ASIC_IN_RX_VREF_CTRL_MASK)

#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_MASK (0xE0U)
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_SHIFT (5U)
/*! TX_VBOOST_LVL - Value from ASIC for tx_vboost_lvl */
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_SHIFT)) & PHY_ENET_SUP_DIG_LVL_ASIC_IN_TX_VBOOST_LVL_MASK)

#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_LVL_ASIC_IN_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_LVL_ASIC_IN_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_LVL_ASIC_IN_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_BANDGAP_ASIC_IN - Current values for incoming bandgap control from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_BG_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_BG_EN_SHIFT (0U)
/*! BG_EN - Value from ASIC for bg_en */
#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_BG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_BG_EN_SHIFT)) & PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_BG_EN_MASK)

#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_RESERVED_15_1_SHIFT)) & PHY_ENET_SUP_DIG_BANDGAP_ASIC_IN_RESERVED_15_1_MASK)
/*! @} */

/*! @name SUP_DIG_CLK_RST_BG_PWRUP_TIME_0 - BG Power UP Time Register #0 */
/*! @{ */

#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_MASK (0x1FFU)
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_SHIFT (0U)
/*! BG_SUP_EN_TIME - Power up time (in ref_range cycles) for bandgap in SUP (spec >=5us) */
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_SHIFT)) & PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_BG_SUP_EN_TIME_MASK)

#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_MASK (0x200U)
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_SHIFT (9U)
/*! FAST_BG_WAIT - Enable fast BG times (simulation only) */
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_SHIFT)) & PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_FAST_BG_WAIT_MASK)

#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_CLK_RST_BG_PWRUP_TIME_1 - BG Power UP Time Register #1 */
/*! @{ */

#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_MASK (0x3FFU)
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_SHIFT (0U)
/*! BG_LANE_EN_TIME - Power up time (in ref_range cycles) for bandgap in LANE (spec >= 20us) */
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_SHIFT)) & PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_BG_LANE_EN_TIME_MASK)

#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_CLK_RST_BG_PWRUP_TIME_1_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_ANA_RTUNE_CTRL - RTUNE_CTRL */
/*! @{ */

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbf_MASK (0x1U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbf_SHIFT (0U)
/*! rt_sel_atbf - RTUNE ATB input select: */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbf(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbf_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbf_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbp_MASK (0x2U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbp_SHIFT (1U)
/*! rt_sel_atbp - RTUNE ATB input select: */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbp_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_sel_atbp_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_atb_MASK  (0x4U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_atb_SHIFT (2U)
/*! rt_atb - RTUNE ATB mode control. */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_atb(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_atb_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_atb_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_chop_MASK (0x8U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_chop_SHIFT (3U)
/*! rt_dac_chop - [RT_DAC_CHOP,RT_DAC_MODE] Function */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_chop(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_chop_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_chop_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_mode_MASK (0x30U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_mode_SHIFT (4U)
/*! rt_dac_mode - Margin DAC mode control bits. */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_mode(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_mode_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_dac_mode_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_NC6_MASK     (0x40U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_NC6_SHIFT    (6U)
/*! NC6 - Reserved */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_NC6(x)       (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_NC6_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_NC6_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_en_frcon_MASK (0x80U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_en_frcon_SHIFT (7U)
/*! rt_en_frcon - Local rtune block enable control, force rtune block on if asserted */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_en_frcon(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_en_frcon_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_rt_en_frcon_MASK)

#define PHY_ENET_SUP_ANA_RTUNE_CTRL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_RTUNE_CTRL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_RTUNE_CTRL_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_RTUNE_CTRL_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_SWITCH_PWR_MEAS - SWITCH_PWR_MEAS */
/*! @{ */

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_bias_ref_MASK (0x1U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_bias_ref_SHIFT (0U)
/*! atb_sw_vbg_bias_ref - Connect vbg_bias_ref to atb_s_p If asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_bias_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_bias_ref_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_bias_ref_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vph_MASK (0x2U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vph_SHIFT (1U)
/*! atb_sw_vph - Connect atb_s_p to vph if bit 5 is asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vph(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vph_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vph_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_vref_MASK (0x4U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_vref_SHIFT (2U)
/*! atb_sw_vbg_vref - Connect vbg_vref to atb_s_p if asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_vref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_vref_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vbg_vref_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vp_MASK (0x8U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vp_SHIFT (3U)
/*! atb_sw_vp - Connect atb_s_p to vp if asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vp_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_vp_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_gd_MASK (0x10U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_gd_SHIFT (4U)
/*! atb_sw_gd - Connect atb_s_m to gd if asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_gd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_gd_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_gd_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_half_vph_MASK (0x20U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_half_vph_SHIFT (5U)
/*! atb_sw_half_vph - Connect atb_s_p to vph/2 if asserted. */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_half_vph(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_half_vph_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_half_vph_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_MASK (0x40U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_SHIFT (6U)
/*! atb_sw - Connect atb_s_p to atb_s_m if asserted */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_atb_sw_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_NC7_MASK (0x80U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_NC7_SHIFT (7U)
/*! NC7 - Reserved */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_NC7(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_NC7_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_NC7_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_PWR_MEAS_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_SWITCH_MISC_MEAS - SWITCH_MISC_MEAS */
/*! @{ */

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_MASK (0x3U)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_SHIFT (0U)
/*! hyst_ref - Function */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_hyst_ref_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_sel_vpll_ref_MASK (0xCU)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_sel_vpll_ref_SHIFT (2U)
/*! sel_vpll_ref - Select the reference voltage for the MPLL */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_sel_vpll_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_sel_vpll_ref_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_sel_vpll_ref_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC4_MASK (0x10U)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC4_SHIFT (4U)
/*! NC4 - Reserved */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC4_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC4_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_temp_meas_MASK (0x20U)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_temp_meas_SHIFT (5U)
/*! temp_meas - If asserted, enable temperature measurement. */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_temp_meas(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_temp_meas_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_temp_meas_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC7_6_MASK (0xC0U)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC7_6_SHIFT (6U)
/*! NC7_6 - Reserved */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC7_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC7_6_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_NC7_6_MASK)

#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_SWITCH_MISC_MEAS_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_BG - BG */
/*! @{ */

#define PHY_ENET_SUP_ANA_BG_bypass_bg_MASK       (0x1U)
#define PHY_ENET_SUP_ANA_BG_bypass_bg_SHIFT      (0U)
/*! bypass_bg - Bypass bandgap with VP */
#define PHY_ENET_SUP_ANA_BG_bypass_bg(x)         (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_bypass_bg_SHIFT)) & PHY_ENET_SUP_ANA_BG_bypass_bg_MASK)

#define PHY_ENET_SUP_ANA_BG_sel_vbg_vref_MASK    (0x6U)
#define PHY_ENET_SUP_ANA_BG_sel_vbg_vref_SHIFT   (1U)
/*! sel_vbg_vref - vbg_vref voltage level select */
#define PHY_ENET_SUP_ANA_BG_sel_vbg_vref(x)      (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_sel_vbg_vref_SHIFT)) & PHY_ENET_SUP_ANA_BG_sel_vbg_vref_MASK)

#define PHY_ENET_SUP_ANA_BG_chop_en_MASK         (0x8U)
#define PHY_ENET_SUP_ANA_BG_chop_en_SHIFT        (3U)
/*! chop_en - Enable chopper clock for bandgap */
#define PHY_ENET_SUP_ANA_BG_chop_en(x)           (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_chop_en_SHIFT)) & PHY_ENET_SUP_ANA_BG_chop_en_MASK)

#define PHY_ENET_SUP_ANA_BG_por_start_kick_en_MASK (0x10U)
#define PHY_ENET_SUP_ANA_BG_por_start_kick_en_SHIFT (4U)
/*! por_start_kick_en - Enable fast startup using bg kick voltage for POR bandgap outputs */
#define PHY_ENET_SUP_ANA_BG_por_start_kick_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_por_start_kick_en_SHIFT)) & PHY_ENET_SUP_ANA_BG_por_start_kick_en_MASK)

#define PHY_ENET_SUP_ANA_BG_NC7_5_MASK           (0xE0U)
#define PHY_ENET_SUP_ANA_BG_NC7_5_SHIFT          (5U)
/*! NC7_5 - Reserved */
#define PHY_ENET_SUP_ANA_BG_NC7_5(x)             (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_NC7_5_SHIFT)) & PHY_ENET_SUP_ANA_BG_NC7_5_MASK)

#define PHY_ENET_SUP_ANA_BG_RESERVED_15_8_MASK   (0xFF00U)
#define PHY_ENET_SUP_ANA_BG_RESERVED_15_8_SHIFT  (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_BG_RESERVED_15_8(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_BG_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_BG_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_PRESCALER_CTRL - PRESCALER_CTRL */
/*! @{ */

#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_meas_vreg_MASK (0x1U)
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_meas_vreg_SHIFT (0U)
/*! meas_vreg - If asserted, measure sup_prescaler regulator output voltage (vp_lcl) through atb_s_p */
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_meas_vreg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_PRESCALER_CTRL_meas_vreg_SHIFT)) & PHY_ENET_SUP_ANA_PRESCALER_CTRL_meas_vreg_MASK)

#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC1_MASK (0x2U)
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC1_SHIFT (1U)
/*! NC1 - Reserved */
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC1(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC1_SHIFT)) & PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC1_MASK)

#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_atb_select_MASK (0x4U)
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_atb_select_SHIFT (2U)
/*! atb_select - Connect internal ATB_S signals to external ATB_S signals */
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_atb_select(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_PRESCALER_CTRL_atb_select_SHIFT)) & PHY_ENET_SUP_ANA_PRESCALER_CTRL_atb_select_MASK)

#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC7_3_MASK (0xF8U)
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC7_3_SHIFT (3U)
/*! NC7_3 - Reserved */
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC7_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC7_3_SHIFT)) & PHY_ENET_SUP_ANA_PRESCALER_CTRL_NC7_3_MASK)

#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_PRESCALER_CTRL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_PRESCALER_CTRL_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_PRESCALER_CTRL_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_DEBUG - Resistor tuning debug controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_MASK (0x1U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_SHIFT (0U)
/*! FLIP_COMP - Invert analog comparator output */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_FLIP_COMP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_FLIP_COMP_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_MASK (0x2U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_SHIFT (1U)
/*! MAN_TUNE - Write to a 1 to do a manual tuning specified by TYPE field starting a manual tune
 *    while a tune is currently running can cause unpredictable results.
 */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_MAN_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_MAN_TUNE_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_SET_VAL_MASK (0x4U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_SET_VAL_SHIFT (2U)
/*! SET_VAL - Set value Write to a 1 to manually write the register specified by the TYPE field to the value in the VALUE field */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_SET_VAL(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_SET_VAL_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_SET_VAL_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TYPE_MASK   (0x18U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TYPE_SHIFT  (3U)
/*! TYPE - Type of manual tuning or register read/write to execute 0 - ADC, or read/write rt_value */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TYPE(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_TYPE_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_TYPE_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_VALUE_MASK  (0x7FE0U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_VALUE_SHIFT (5U)
/*! VALUE - Value to use when triggering SET_VAL field only the 6 LSB's are used when setting rx cal values */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_VALUE(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_VALUE_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_VALUE_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TXUP_GO_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TXUP_GO_SHIFT (15U)
/*! TXUP_GO - Enable TxUP tune to continue in manual tune mode when TYPE is TxUP tune. */
#define PHY_ENET_SUP_DIG_RTUNE_DEBUG_TXUP_GO(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_DEBUG_TXUP_GO_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_DEBUG_TXUP_GO_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_CONFIG - Configure Rtune Operation */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RX_CAL_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RX_CAL_EN_SHIFT (0U)
/*! RX_CAL_EN - Enable calibration of RX resistor */
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RX_CAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_CONFIG_RX_CAL_EN_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_CONFIG_RX_CAL_EN_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_FAST_RTUNE_MASK (0x2U)
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_FAST_RTUNE_SHIFT (1U)
/*! FAST_RTUNE - Enable fast resitor tuning (simulation only) */
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_FAST_RTUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_CONFIG_FAST_RTUNE_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_CONFIG_FAST_RTUNE_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_TX_CAL_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_TX_CAL_EN_SHIFT (2U)
/*! TX_CAL_EN - Enable calibration of TX resistor */
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_TX_CAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_CONFIG_TX_CAL_EN_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_CONFIG_TX_CAL_EN_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_SUP_ANA_TERM_CTRL_MASK (0x38U)
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_SUP_ANA_TERM_CTRL_SHIFT (3U)
/*! SUP_ANA_TERM_CTRL - Set the reference resistor in the analog Value Impedence (Ohms) */
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_SUP_ANA_TERM_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_CONFIG_SUP_ANA_TERM_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_CONFIG_SUP_ANA_TERM_CTRL_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_CONFIG_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_CONFIG_RESERVED_15_6_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_CONFIG_RESERVED_15_6_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_STAT - Resistor tuning register status */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_STAT_STAT_MASK    (0x3FFU)
#define PHY_ENET_SUP_DIG_RTUNE_STAT_STAT_SHIFT   (0U)
/*! STAT - Current value of the register specifed by the DEBUG. */
#define PHY_ENET_SUP_DIG_RTUNE_STAT_STAT(x)      (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_STAT_STAT_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_STAT_STAT_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_STAT_DTB_RTUNE_MASK (0xC00U)
#define PHY_ENET_SUP_DIG_RTUNE_STAT_DTB_RTUNE_SHIFT (10U)
/*! DTB_RTUNE - DTB sampling for rtune */
#define PHY_ENET_SUP_DIG_RTUNE_STAT_DTB_RTUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_STAT_DTB_RTUNE_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_STAT_DTB_RTUNE_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_STAT_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_SUP_DIG_RTUNE_STAT_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_STAT_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_STAT_RESERVED_15_12_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_STAT_RESERVED_15_12_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_RX_SET_VAL - Set value of RX Resistor */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_MASK (0x3FU)
#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_SHIFT (0U)
/*! RX_SET_VAL - Set value of rx resistor Writing a value to this register will set the rx resistor value. */
#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RX_SET_VAL_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RESERVED_15_6_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_RX_SET_VAL_RESERVED_15_6_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXDN_SET_VAL - Set value of TX-DN Resistor */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_MASK (0x3FFU)
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_SHIFT (0U)
/*! TXDN_SET_VAL - Set value of tx-dn resistor Writing a value to this register will set the tx-dn resistor value. */
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_TXDN_SET_VAL_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXDN_SET_VAL_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXUP_SET_VAL - Set value of TX-UP Resistor */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_MASK (0x3FFU)
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_SHIFT (0U)
/*! TXUP_SET_VAL - Set value of tx-up resistor Writing a value to this register will set the tx-up resistor value. */
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_TXUP_SET_VAL_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXUP_SET_VAL_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_RX_STAT - RX Resistor tuning register status */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RX_STAT_MASK (0x3FU)
#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RX_STAT_SHIFT (0U)
/*! RX_STAT - Current value of the rx resistor tuning register */
#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RX_STAT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RX_STAT_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RX_STAT_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RESERVED_15_6_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_RX_STAT_RESERVED_15_6_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXDN_STAT - TX-DN Resistor tuning register status */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_MASK (0x3FFU)
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_SHIFT (0U)
/*! TXDN_STAT - Current value of the tx-dn resistor tuning register */
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_TXDN_STAT_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXDN_STAT_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_RTUNE_TXUP_STAT - TX-UP Resistor tuning register status */
/*! @{ */

#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_MASK (0x3FFU)
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_SHIFT (0U)
/*! TXUP_STAT - Current value of the tx-up resistor tuning register */
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_TXUP_STAT_MASK)

#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_RTUNE_TXUP_STAT_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_RTUNE_OVRD_OUT - Override value for RTUNE signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_MASK (0x1U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_SHIFT (0U)
/*! RTUNE_COMP_RST - Overrides the rt_ana_comp_rst signal */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_COMP_RST_MASK)

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_MASK (0x6U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_SHIFT (1U)
/*! RTUNE_MODE - Overrides the rt_ana_mode[1:0] signal */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_MODE_MASK)

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_SHIFT (3U)
/*! RTUNE_EN - Overrides the rt_ana_en signal */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_MASK (0x3FF0U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_SHIFT (4U)
/*! RTUNE_VALUE - Overrides the rt_ana_value[9:0] signal */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_VALUE_MASK)

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_SHIFT (14U)
/*! RTUNE_OVRD_EN - Override bit for rtune (rt_ana_* and term) outputs */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RTUNE_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_ANA_RTUNE_OVRD_OUT_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_STAT - SUP input status register for SUP ANA outputs */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_MASK (0x1U)
#define PHY_ENET_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_SHIFT (0U)
/*! RT_ANA_COMP_RESULT - Value from ANA for rt_ana_comp_result */
#define PHY_ENET_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_SHIFT)) & PHY_ENET_SUP_DIG_ANA_STAT_RT_ANA_COMP_RESULT_MASK)

#define PHY_ENET_SUP_DIG_ANA_STAT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_SUP_DIG_ANA_STAT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_STAT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_STAT_RESERVED_15_1_SHIFT)) & PHY_ENET_SUP_DIG_ANA_STAT_RESERVED_15_1_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_ANA_OVRD_OUT - Override values for ana_async_rst and bandgap signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_FAST_START_MASK (0x1U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_FAST_START_SHIFT (0U)
/*! BG_FAST_START - Overrides the bg_ana_fast_start signal */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_FAST_START(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_FAST_START_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_FAST_START_MASK)

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_EN_SHIFT (1U)
/*! BG_EN - Overrides the bg_ana_en signal */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_OVRD_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_OVRD_EN_SHIFT (2U)
/*! BG_OVRD_EN - Override bit for bandgap outputs */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_BG_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_MASK (0x8U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_SHIFT (3U)
/*! ANA_ASYNC_RST - Override value for reset register for analog latches */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_MASK)

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_OVRD_EN_MASK (0x10U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_OVRD_EN_SHIFT (4U)
/*! ANA_ASYNC_RST_OVRD_EN - Override enable for ana_async_rst */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_ANA_ASYNC_RST_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_RESERVED_15_5_SHIFT)) & PHY_ENET_SUP_DIG_ANA_ANA_OVRD_OUT_RESERVED_15_5_MASK)
/*! @} */

/*! @name RAWCMN_DIG_CMN_CTL - Common control register */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_SHIFT (0U)
/*! PHY_FUNC_RST - Resets the PHY except registers in the Raw PCS common and always-on registers. */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_PHY_FUNC_RST_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_LANE_FSM_OP_XTND - Lane FSM OP XTND control register */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_data_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_data_SHIFT (0U)
/*! data - Required to prevent timing violations while accessing through external interface. */
#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_data(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_data_SHIFT)) & PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_data_MASK)

#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_LANE_FSM_OP_XTND_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_CMN_CTL_1 - Common control register 1 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_SHIFT (0U)
/*! MPLLA_INIT_CAL_DISABLE_OVRD_VAL - Override value for mplla_init_cal_disable */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_SHIFT (1U)
/*! MPLLA_INIT_CAL_DISABLE_OVRD_EN - Override enable for mplla_init_cal_disable */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLA_INIT_CAL_DISABLE_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_SHIFT (2U)
/*! MPLLB_INIT_CAL_DISABLE_OVRD_VAL - Override value for mpllb_init_cal_disable */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_SHIFT (3U)
/*! MPLLB_INIT_CAL_DISABLE_OVRD_EN - Override enable for mpllb_init_cal_disable */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_MPLLB_INIT_CAL_DISABLE_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_SHIFT (4U)
/*! RTUNE_REQ_OVRD_VAL - Override value for rtune_req */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_SHIFT (5U)
/*! RTUNE_REQ_OVRD_EN - Override enable for rtune_req */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RTUNE_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_1_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_CMN_CTL_2 - Common control register 2 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_TX_WAIT_MPLL_OFF_TIME_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_TX_WAIT_MPLL_OFF_TIME_SHIFT (0U)
/*! TX_WAIT_MPLL_OFF_TIME - Number of ref_range cycles to wait for MPLL to turn off */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_TX_WAIT_MPLL_OFF_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_2_TX_WAIT_MPLL_OFF_TIME_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_2_TX_WAIT_MPLL_OFF_TIME_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_FW_PWRUP_DONE_MASK (0x40U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_FW_PWRUP_DONE_SHIFT (6U)
/*! FW_PWRUP_DONE - Indicates whether Firmware power-up has completed or not. */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_FW_PWRUP_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_2_FW_PWRUP_DONE_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_2_FW_PWRUP_DONE_MASK)

#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_CMN_CTL_2_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_CMN_CTL_2_RESERVED_15_7_SHIFT)) & PHY_ENET_RAWCMN_DIG_CMN_CTL_2_RESERVED_15_7_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLL_STATE_CTL - MPLL control signals for force ack state machine */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLL_FORCE_ON_TIME_MASK (0xFU)
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLL_FORCE_ON_TIME_SHIFT (0U)
/*! MPLL_FORCE_ON_TIME - Wait Counter for turning on MPLL using mplla/b_force_en This is to ensure
 *    there is no collision between the force_en logic and the tx_req logic
 */
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLL_FORCE_ON_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLL_FORCE_ON_TIME_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLL_FORCE_ON_TIME_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLB_BANK_SEL_MASK (0x10U)
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLB_BANK_SEL_SHIFT (4U)
/*! MPLLB_BANK_SEL - Enable of mpllb_force_ctl */
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLB_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLB_BANK_SEL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLB_BANK_SEL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLA_BANK_SEL_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLA_BANK_SEL_SHIFT (5U)
/*! MPLLA_BANK_SEL - Enable of mplla_force_ctl */
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLA_BANK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLA_BANK_SEL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_MPLLA_BANK_SEL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLL_STATE_CTL_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0 - Resistor Tune RX Value 0 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RTUNE_RX_VAL_0_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RTUNE_RX_VAL_0_SHIFT (0U)
/*! RTUNE_RX_VAL_0 - Stored resister tune RX value 0 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RTUNE_RX_VAL_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RTUNE_RX_VAL_0_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RTUNE_RX_VAL_0_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_0_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0 - Resistor Tune TX Down Value 0 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RTUNE_TXDN_VAL_0_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RTUNE_TXDN_VAL_0_SHIFT (0U)
/*! RTUNE_TXDN_VAL_0 - Stored resister tune TX down value 0 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RTUNE_TXDN_VAL_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RTUNE_TXDN_VAL_0_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RTUNE_TXDN_VAL_0_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0 - Resistor Tune TX Up Value 0 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RTUNE_TXUP_VAL_0_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RTUNE_TXUP_VAL_0_SHIFT (0U)
/*! RTUNE_TXUP_VAL_0 - Stored resister tune TX up value 0 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RTUNE_TXUP_VAL_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RTUNE_TXUP_VAL_0_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RTUNE_TXUP_VAL_0_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1 - Resistor Tune RX Value 1 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RTUNE_RX_VAL_1_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RTUNE_RX_VAL_1_SHIFT (0U)
/*! RTUNE_RX_VAL_1 - Stored resister tune RX value 1 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RTUNE_RX_VAL_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RTUNE_RX_VAL_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RTUNE_RX_VAL_1_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_1_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1 - Resistor Tune TX Down Value 1 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RTUNE_TXDN_VAL_1_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RTUNE_TXDN_VAL_1_SHIFT (0U)
/*! RTUNE_TXDN_VAL_1 - Stored resister tune TX down value 1 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RTUNE_TXDN_VAL_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RTUNE_TXDN_VAL_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RTUNE_TXDN_VAL_1_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_1_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1 - Resistor Tune TX Up Value 1 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RTUNE_TXUP_VAL_1_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RTUNE_TXUP_VAL_1_SHIFT (0U)
/*! RTUNE_TXUP_VAL_1 - Stored resister tune TX up value 1 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RTUNE_TXUP_VAL_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RTUNE_TXUP_VAL_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RTUNE_TXUP_VAL_1_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_1_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2 - Resistor Tune RX Value 2 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RTUNE_RX_VAL_2_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RTUNE_RX_VAL_2_SHIFT (0U)
/*! RTUNE_RX_VAL_2 - Stored resister tune RX value 2 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RTUNE_RX_VAL_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RTUNE_RX_VAL_2_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RTUNE_RX_VAL_2_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_2_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2 - Resistor Tune TX Down Value 2 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RTUNE_TXDN_VAL_2_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RTUNE_TXDN_VAL_2_SHIFT (0U)
/*! RTUNE_TXDN_VAL_2 - Stored resister tune TX down value 2 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RTUNE_TXDN_VAL_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RTUNE_TXDN_VAL_2_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RTUNE_TXDN_VAL_2_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_2_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2 - Resistor Tune TX Up Value 2 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RTUNE_TXUP_VAL_2_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RTUNE_TXUP_VAL_2_SHIFT (0U)
/*! RTUNE_TXUP_VAL_2 - Stored resister tune TX up value 2 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RTUNE_TXUP_VAL_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RTUNE_TXUP_VAL_2_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RTUNE_TXUP_VAL_2_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_2_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3 - Resistor Tune RX Value 3 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RTUNE_RX_VAL_3_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RTUNE_RX_VAL_3_SHIFT (0U)
/*! RTUNE_RX_VAL_3 - Stored resister tune RX value 3 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RTUNE_RX_VAL_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RTUNE_RX_VAL_3_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RTUNE_RX_VAL_3_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_3_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3 - Resistor Tune TX Down Value 3 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RTUNE_TXDN_VAL_3_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RTUNE_TXDN_VAL_3_SHIFT (0U)
/*! RTUNE_TXDN_VAL_3 - Stored resister tune TX down value 3 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RTUNE_TXDN_VAL_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RTUNE_TXDN_VAL_3_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RTUNE_TXDN_VAL_3_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_3_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3 - Resistor Tune TX Up Value 3 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RTUNE_TXUP_VAL_3_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RTUNE_TXUP_VAL_3_SHIFT (0U)
/*! RTUNE_TXUP_VAL_3 - Stored resister tune TX up value 3 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RTUNE_TXUP_VAL_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RTUNE_TXUP_VAL_3_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RTUNE_TXUP_VAL_3_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_3_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4 - Resistor Tune RX Value 4 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RTUNE_RX_VAL_4_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RTUNE_RX_VAL_4_SHIFT (0U)
/*! RTUNE_RX_VAL_4 - Stored resister tune RX value 4 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RTUNE_RX_VAL_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RTUNE_RX_VAL_4_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RTUNE_RX_VAL_4_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_4_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4 - Resistor Tune TX Down Value 4 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RTUNE_TXDN_VAL_4_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RTUNE_TXDN_VAL_4_SHIFT (0U)
/*! RTUNE_TXDN_VAL_4 - Stored resister tune TX down value 4 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RTUNE_TXDN_VAL_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RTUNE_TXDN_VAL_4_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RTUNE_TXDN_VAL_4_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_4_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4 - Resistor Tune TX Up Value 4 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RTUNE_TXUP_VAL_4_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RTUNE_TXUP_VAL_4_SHIFT (0U)
/*! RTUNE_TXUP_VAL_4 - Stored resister tune TX up value 4 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RTUNE_TXUP_VAL_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RTUNE_TXUP_VAL_4_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RTUNE_TXUP_VAL_4_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_4_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5 - Resistor Tune RX Value 5 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RTUNE_RX_VAL_5_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RTUNE_RX_VAL_5_SHIFT (0U)
/*! RTUNE_RX_VAL_5 - Stored resister tune RX value 5 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RTUNE_RX_VAL_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RTUNE_RX_VAL_5_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RTUNE_RX_VAL_5_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_5_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5 - Resistor Tune TX Down Value 5 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RTUNE_TXDN_VAL_5_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RTUNE_TXDN_VAL_5_SHIFT (0U)
/*! RTUNE_TXDN_VAL_5 - Stored resister tune TX down value 5 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RTUNE_TXDN_VAL_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RTUNE_TXDN_VAL_5_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RTUNE_TXDN_VAL_5_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_5_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5 - Resistor Tune TX Up Value 5 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RTUNE_TXUP_VAL_5_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RTUNE_TXUP_VAL_5_SHIFT (0U)
/*! RTUNE_TXUP_VAL_5 - Stored resister tune TX up value 5 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RTUNE_TXUP_VAL_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RTUNE_TXUP_VAL_5_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RTUNE_TXUP_VAL_5_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_5_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6 - Resistor Tune RX Value 6 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RTUNE_RX_VAL_6_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RTUNE_RX_VAL_6_SHIFT (0U)
/*! RTUNE_RX_VAL_6 - Stored resister tune RX value 6 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RTUNE_RX_VAL_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RTUNE_RX_VAL_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RTUNE_RX_VAL_6_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_6_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6 - Resistor Tune TX Down Value 6 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RTUNE_TXDN_VAL_6_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RTUNE_TXDN_VAL_6_SHIFT (0U)
/*! RTUNE_TXDN_VAL_6 - Stored resister tune TX down value 6 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RTUNE_TXDN_VAL_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RTUNE_TXDN_VAL_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RTUNE_TXDN_VAL_6_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_6_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6 - Resistor Tune TX Up Value 6 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RTUNE_TXUP_VAL_6_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RTUNE_TXUP_VAL_6_SHIFT (0U)
/*! RTUNE_TXUP_VAL_6 - Stored resister tune TX up value 6 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RTUNE_TXUP_VAL_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RTUNE_TXUP_VAL_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RTUNE_TXUP_VAL_6_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_6_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7 - Resistor Tune RX Value 7 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RTUNE_RX_VAL_7_MASK (0x3FU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RTUNE_RX_VAL_7_SHIFT (0U)
/*! RTUNE_RX_VAL_7 - Stored resister tune RX value 7 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RTUNE_RX_VAL_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RTUNE_RX_VAL_7_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RTUNE_RX_VAL_7_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_RX_VAL_7_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7 - Resistor Tune TX Down Value 7 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RTUNE_TXDN_VAL_7_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RTUNE_TXDN_VAL_7_SHIFT (0U)
/*! RTUNE_TXDN_VAL_7 - Stored resister tune TX down value 7 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RTUNE_TXDN_VAL_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RTUNE_TXDN_VAL_7_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RTUNE_TXDN_VAL_7_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXDN_VAL_7_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7 - Resistor Tune TX Up Value 7 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RTUNE_TXUP_VAL_7_MASK (0x3FFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RTUNE_TXUP_VAL_7_SHIFT (0U)
/*! RTUNE_TXUP_VAL_7 - Stored resister tune TX up value 7 */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RTUNE_TXUP_VAL_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RTUNE_TXUP_VAL_7_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RTUNE_TXUP_VAL_7_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_RTUNE_TXUP_VAL_7_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN - Enable SRAM bootloader on power-gated exit */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_SHIFT (0U)
/*! SRAM_PGATE_BL_EN - Enable SRAM bootloader on power-gated exit. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_SRAM_PGATE_BL_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SRAM_PGATE_BL_EN_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_PG_OVRD_IN - Override values for incoming power-gating signals */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_SHIFT (0U)
/*! PMA_PWR_STABLE_OVRD - Enable overriding pma_pwr_stable to 1'b1. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PMA_PWR_STABLE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PMA_PWR_STABLE_OVRD_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_SHIFT (1U)
/*! PCS_PWR_STABLE_OVRD - Enable overriding pcs_pwr_stable to 1'b1. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PCS_PWR_STABLE_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PCS_PWR_STABLE_OVRD_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_VAL_SHIFT (2U)
/*! PG_RESET_OVRD_VAL - Override value for pg_reset. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_EN_SHIFT (3U)
/*! PG_RESET_OVRD_EN - Override enable for pg_reset. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_RESET_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_SHIFT (4U)
/*! PG_MODE_EN_OVRD_VAL - Override value for pg_mode_en. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_SHIFT (5U)
/*! PG_MODE_EN_OVRD_EN - Override enable for pg_mode_en. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_PG_MODE_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_IN_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_PG_OVRD_OUT - Override values for outgoing power-gating signals */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PMA_PWR_EN_OVRD_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PMA_PWR_EN_OVRD_SHIFT (0U)
/*! PMA_PWR_EN_OVRD - Enable overriding pma_pwr_en to 1'b1. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PMA_PWR_EN_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PMA_PWR_EN_OVRD_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PMA_PWR_EN_OVRD_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PCS_PWR_EN_OVRD_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PCS_PWR_EN_OVRD_SHIFT (1U)
/*! PCS_PWR_EN_OVRD - Enable overriding pcs_pwr_en to 1'b1. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PCS_PWR_EN_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PCS_PWR_EN_OVRD_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_PCS_PWR_EN_OVRD_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_PG_OVRD_OUT_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_SUP_OVRD_IN - Override values for incoming SUP signals */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_SHIFT (0U)
/*! MPLLA_FORCE_EN_OVRD_VAL - Override value for mplla_force_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_SHIFT (1U)
/*! MPLLA_FORCE_EN_OVRD_EN - Override enable for mplla_force_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLA_FORCE_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_SHIFT (2U)
/*! MPLLB_FORCE_EN_OVRD_VAL - Override value for mpllb_force_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_SHIFT (3U)
/*! MPLLB_FORCE_EN_OVRD_EN - Override enable for mpllb_force_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_MPLLB_FORCE_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_SHIFT (4U)
/*! REF_CLK_EN_OVRD_VAL - Override value for ref_clk_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT (5U)
/*! REF_CLK_EN_OVRD_EN - Override enable for ref_clk_en */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_REF_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_SUP_OVRD_IN_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE - Firmware Power-Up Done Status */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_FW_PWRUP_DONE_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_FW_PWRUP_DONE_SHIFT (0U)
/*! FW_PWRUP_DONE - Indicates whether Firmware power-up has completed or not. */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_FW_PWRUP_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_FW_PWRUP_DONE_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_FW_PWRUP_DONE_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_FW_PWRUP_DONE_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL - Firmware version register #0 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL_PMA_LABEL_MASK (0xFFFFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL_PMA_LABEL_SHIFT (0U)
/*! PMA_LABEL - PMA LABEL */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL_PMA_LABEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL_PMA_LABEL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PMA_LABEL_PMA_LABEL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL - Firmware version register #1 */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_FW_LABEL_MASK (0xFFU)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_FW_LABEL_SHIFT (0U)
/*! FW_LABEL - FW LABEL */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_FW_LABEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_FW_LABEL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_FW_LABEL_MASK)

#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_PCS_RAW_LABEL_MASK (0xFF00U)
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_PCS_RAW_LABEL_SHIFT (8U)
/*! PCS_RAW_LABEL - PCS_RAW LABEL */
#define PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_PCS_RAW_LABEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_PCS_RAW_LABEL_SHIFT)) & PHY_ENET_RAWCMN_DIG_AON_CMN_FW_VERSION_PCS_RAW_FW_LABEL_PCS_RAW_LABEL_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_DIV_CLK_OVRD_IN - Override values for incoming MPLLA_DIV_CLK controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_SHIFT (0U)
/*! MPLLA_DIV_CLK_EN - Override value for mplla_div_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_MASK (0x1FEU)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLA_DIV_MULTIPLIER - Override value for mplla_div_multiplier */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_OVRD_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_OVRD_EN_SHIFT (9U)
/*! MPLLA_DIV_OVRD_EN - Enable overrides for MPLLA Div clock */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_MPLLA_DIV_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_OVRD_IN_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_0 - Override values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_SHIFT (0U)
/*! MPLLA_EN - Override value for mplla_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLA_DIV2_EN - Override value for ref_clk_mplla_div2_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLA_DIV8_CLK_EN - Override value for mplla_div8_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLA_DIV10_CLK_EN - Override value for mplla_div10_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_MASK (0xFF0U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_SHIFT (4U)
/*! MPLLA_MULTIPLIER - Override value for mplla_multiplier */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_MASK (0x7000U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_SHIFT (12U)
/*! MPLLA_TX_CLK_DIV - Override value for mplla_tx_clk_div */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_MPLLA_TX_CLK_DIV_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_SHIFT (15U)
/*! OVRD_EN - Enable override values for all inputs controlled by this register (mplla_word_div2_en) */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_0_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_1 - Override values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - Override value for mplla_ssc_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_RANGE_MASK (0xEU)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_RANGE_SHIFT (1U)
/*! MPLLA_SSC_RANGE - Override value for mplla_ssc_range */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_RANGE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_RANGE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_MASK (0x70U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLA_SSC_CLK_SEL - Override value for mplla_ssc_clk_sel */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_CLK_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_OVRD_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_OVRD_EN_SHIFT (7U)
/*! MPLLA_SSC_OVRD_EN - Enable override values for MPLLA SSC inputs */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_SSC_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_WORD_DIV2_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_WORD_DIV2_EN_SHIFT (8U)
/*! MPLLA_WORD_DIV2_EN - Override value for mplla_word_div2_en */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_WORD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_WORD_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_MPLLA_WORD_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_OVRD_IN_2 - Override values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_FRACN_CTRL_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_FRACN_CTRL_SHIFT (0U)
/*! MPLLA_FRACN_CTRL - Override value for mplla_fracn_ctrl */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_FRACN_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_MPLLA_FRACN_CTRL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_OVRD_IN_2_RESERVED_15_11_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN - Override values for incoming MPLLA bandwidth controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - Override value for mplla_bandwidth[15:0] */
#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN_MPLLA_BANDWIDTH_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_OVRD_IN_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_0 - Current values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_SHIFT (0U)
/*! MPLLA_EN - Value from ASIC for mplla_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLA_DIV2_EN - Value from ASIC for ref_clk_mplla_div2_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_REF_CLK_MPLLA_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLA_DIV8_CLK_EN - Value from ASIC for mplla_div8_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLA_DIV10_CLK_EN - Value from ASIC for mplla_div10_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_MASK (0xFF0U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_SHIFT (4U)
/*! MPLLA_MULTIPLIER - Value from ASIC for mplla_multiplier */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_MASK (0x7000U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_SHIFT (12U)
/*! MPLLA_TX_CLK_DIV - Value from ASIC for mplla_tx_clk_div */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_MPLLA_TX_CLK_DIV_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_0_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_1 - Current values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_SHIFT (0U)
/*! MPLLA_SSC_EN - Value from mplla_ssc_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_RANGE_MASK (0xEU)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_RANGE_SHIFT (1U)
/*! MPLLA_SSC_RANGE - Value from mplla_ssc_range */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_RANGE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_RANGE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_MASK (0x70U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLA_SSC_CLK_SEL - Value from mplla_ssc_clk_sel */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_SSC_CLK_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_WORD_DIV2_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_WORD_DIV2_EN_SHIFT (7U)
/*! MPLLA_WORD_DIV2_EN - Value from mplla_word_div2_en */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_WORD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_WORD_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_MPLLA_WORD_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_1_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_ASIC_IN_2 - Current values for incoming MPLLA controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_FRACN_CTRL_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_FRACN_CTRL_SHIFT (0U)
/*! MPLLA_FRACN_CTRL - Value from mplla_fracn_ctrl */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_FRACN_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_MPLLA_FRACN_CTRL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_ASIC_IN_2_RESERVED_15_11_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_DIV_CLK_ASIC_IN - Current values for incoming MPLLA_DIV_CLK controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_SHIFT (0U)
/*! MPLLA_DIV_CLK_EN - Value from mplla_div_clk_en */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_MASK (0x1FEU)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLA_DIV_MULTIPLIER - Value from mplla_div_multiplier */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_MPLLA_DIV_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_DIV_CLK_ASIC_IN_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN - Current values for incoming MPLLA bandwidth controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN_MPLLA_BANDWIDTH_MASK (0xFFFFU)
#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN_MPLLA_BANDWIDTH_SHIFT (0U)
/*! MPLLA_BANDWIDTH - Value from ASIC for mplla_bandwidth */
#define PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN_MPLLA_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN_MPLLA_BANDWIDTH_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_BANDWIDTH_ASIC_IN_MPLLA_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL - MPLL Calibration controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT (0U)
/*! LOAD_CNT - MSBs for the CHKFRQ FSM ld_val[10:0] load value 0x0 - gives a ld_val of 0, no PPM difference can be detected */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT (4U)
/*! MPLL_SKIPCAL - Skip automatic (internal) calibration of MPLL (and also skip external calibration if it is enabled) */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK (0x20U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT (5U)
/*! MPLL_EXTCAL - Enable external calibration of MPLL */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT (6U)
/*! EXT_CHKFRQ_EN - Check the frequency of the MPLL Only valid in external calibration mode */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK (0x7F80U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT (7U)
/*! EXT_COARSE_TUNE - Value of mpll_ana_coarse_tune_i[7:0] in external calibration mode */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT (15U)
/*! EXT_CAL_DONE - Set the external calibration status to done */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD - MPLL override controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT (0U)
/*! OVRD_SEL - Override enable bit */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT (1U)
/*! MPLL_FBDIGCLK_EN - Overrides the PWR FSM mpll_fb_dig_clk_en signal */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT (2U)
/*! MPLL_PCLK_EN - Overrides the PWR FSM mpll_pclk_en signal */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_SHIFT (3U)
/*! FAST_MPLL_PWRUP - Enable fast MPLL powerup */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_SHIFT (4U)
/*! FAST_MPLL_LOCK - Enable fast MPLL locking */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK (0x3E0U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT (5U)
/*! DTB_SEL - DTB select for MPLL dtb signals */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT - MPLL status register */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT (0U)
/*! FSM_STATE - Current value of the PWR FSM state register */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_FSM_STATE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT (4U)
/*! MPLL_TOOSLOW - Current value of mpll_tooslow */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK (0x20U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT (5U)
/*! CHKFRQ_DONE - Current value of mpll_chkfrq_done */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK (0x40U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT (6U)
/*! MPLL_CAL_RDY - Current value of mpll_cal_rdy */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT (7U)
/*! MPLL_R_LANES - Current value of lane_mpll_r */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT (8U)
/*! MPLL_L_LANES - Current value of lane_mpll_l */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT (9U)
/*! MPLL_PCLK_EN - Current value of mpll_pclk_en */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK (0x400U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT (10U)
/*! MPLL_OUTPUT_EN - Current value of mpll_ana_output_en_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK (0x800U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT (11U)
/*! MPLL_FBCLK_EN - Current value of mpll_ana_fb_clk_en_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT (12U)
/*! MPLL_CAL - Current value of mpll_ana_cal_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT (13U)
/*! MPLL_RST - Current value of mpll_ana_rst_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_RST_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT (14U)
/*! MPLL_ANA_EN - Current value of mpll_ana_en_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_STAT_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD - Thresholds for MPLL CAL Update timer and MPLL VCO Stabilization timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK (0x1FFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO stabilization timer in terms of number
 *    of reference clock cycles Here the reference clock means the one that is fed to the phase
 *    detector of the corresponding PLL not the raw reference clock.
 */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK (0x1E00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT (9U)
/*! MPLL_CAL_UPDATE_TIME_THRESHOLD - Threshold for the MPLL calibration control word update timer in terms of number of ref_rang_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD - Thresholds for PCLK enable and MPLL VCO Clock Stabilization timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_CLK_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO clock stabilization timer in terms
 *    of number of reference clock cycles Here the reference clock means the one that is fed to the
 *    phase detector of the corresponding PLL not the raw reference clock.
 */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT (11U)
/*! PCLK_EN_TIME_THRESHOLD - Threshold for the PCLK enable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD - Thresholds for PCLK disable and MPLL VCO POWER DOWN timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_MASK (0x1FU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_SHIFT (0U)
/*! PCLK_DIS_TIME_THRESHOLD - Threshold for the PCLK disable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK (0x3E0U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT (5U)
/*! MPLL_VCO_PWRDN_TIME_THRESHOLD - Threshold for the MPLL VCO power down timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD - Thresholds for MPLL feedback clock enable and MPLL feedback digital clock disable and MPLL ANA POWER UP timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_FBCLK_EN_TIME_THRESHOLD - Threshold for the MPLL feedback clock enable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK (0xF0U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT (4U)
/*! MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Threshold for the MPLL feedback digital clock disable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK (0x7F00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT (8U)
/*! MPLL_ANA_PWRUP_TIME_THRESHOLD - Threshold for the MPLL analog power up timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL - MPLL coarse_tune value register */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT (0U)
/*! MPLL_COARSE_TUNE_VAL - Current value of mpll_ana_coarse_tune_i */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when skipping calibration */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT (0U)
/*! MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when calibration is skipped */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_PHASE - Current MPLL phase selector value */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_MASK (0x3U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_SHIFT (0U)
/*! DTHR - Bits below the useful resolution (2 reads needed to read value) */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_DTHR_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_MASK (0x7FCU)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_SHIFT (2U)
/*! VAL - Phase value from zero reference (2 reads needed to read value) */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_VAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_MASK (0x800U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_SHIFT (11U)
/*! ZERO_FREQ - Zero frequency register. */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_ZERO_FREQ_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_RESERVED_15_12_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_PHASE_RESERVED_15_12_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_FREQ_0 - Frequency Control for Spread Spectrum #0 */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK (0xFFFU)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT (0U)
/*! FREQ_CNT_INIT - Initial Frequency Counter Value */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT (12U)
/*! FREQ_0_OVRD - Frequency Reigster Override. */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_RESERVED_15_13_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_0_RESERVED_15_13_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLA_SSC_SS_FREQ_1 - Frequency Control for Spread Spectrum #1 */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PK_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PK_SHIFT (0U)
/*! FREQ_PK - Peak Frequency Value (for changing direction) */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PK_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_PK_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT (8U)
/*! FREQ_1_OVRD - Frequency Reigster Override. */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK)

#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLA_SSC_SS_FREQ_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_MISC - MPLLA_MISC */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLA_MISC_bypass_buf_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_bypass_buf_SHIFT (0U)
/*! bypass_buf - To bypass CP buffers. */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_bypass_buf(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_bypass_buf_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_bypass_buf_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_MISC_ovrd_pr_bypass_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_ovrd_pr_bypass_SHIFT (1U)
/*! ovrd_pr_bypass - If asserted, pr_bypass take effect on phase rotator bypass control */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_ovrd_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_ovrd_pr_bypass_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_ovrd_pr_bypass_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_MISC_mode_old_ssc_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_mode_old_ssc_SHIFT (2U)
/*! mode_old_ssc - Uses just two bits for SSC interpolation */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_mode_old_ssc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_mode_old_ssc_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_mode_old_ssc_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_MISC_pr_bypass_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_pr_bypass_SHIFT (3U)
/*! pr_bypass - If ovrd_pr_bypass is enabled: */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_pr_bypass_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_pr_bypass_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_MISC_NC7_4_MASK   (0xF0U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_NC7_4_SHIFT  (4U)
/*! NC7_4 - Reserved */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_NC7_4(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_NC7_4_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_NC7_4_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_MISC_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLA_MISC_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLA_MISC_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_MISC_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_MISC_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_OVRD - MPLLA_OVRD */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_enable_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_enable_SHIFT (0U)
/*! ovrd_enable - enable local control of enable signal (mpll_en) */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_enable(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_enable_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_enable_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_enable_reg_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_enable_reg_SHIFT (1U)
/*! enable_reg - set local enable control to ON */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_enable_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_enable_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_enable_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_cal_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_cal_SHIFT (2U)
/*! ovrd_cal - enable local control of calibration signal (mpll_cal) */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_cal(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_cal_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_cal_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_cal_reg_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_cal_reg_SHIFT (3U)
/*! cal_reg - set local calibration control to ON */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_cal_reg(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_cal_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_cal_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_SHIFT (4U)
/*! ovrd_fb_clk_en - enable local control of feedback clock control signal (mpll_fb_clk_en) */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_fb_clk_en_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_SHIFT (5U)
/*! fb_clk_en_reg - set local feedback clock control to ON */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_fb_clk_en_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_reset_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_reset_SHIFT (6U)
/*! ovrd_reset - enable local control of reset signal (mpll_rst) */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_reset(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_reset_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_ovrd_reset_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_reset_reg_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_reset_reg_SHIFT (7U)
/*! reset_reg - set local reset control to ON */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_reset_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_reset_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_reset_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_OVRD_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLA_OVRD_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_OVRD_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_OVRD_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_ATB1 - MPLLA_ATB1 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vco_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vco_SHIFT (0U)
/*! override_vreg_vco - Override vreg_vco to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vco(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vco_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vco_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_right_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_right_SHIFT (1U)
/*! override_vreg_right - Override vreg_right to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_right(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_right_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_right_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_left_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_left_SHIFT (2U)
/*! override_vreg_left - Override vreg_left to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_left(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_left_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_left_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vp_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vp_SHIFT (3U)
/*! override_vreg_vp - Override vreg_vp to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_cp_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_cp_SHIFT (4U)
/*! override_vreg_cp - Override vreg_cp to be 4/3X of voltage on atb_s_m. */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_cp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_cp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_override_vreg_cp_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_vco_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_vco_SHIFT (5U)
/*! meas_vreg_vco - Measure vreg_vco (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_vco(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_vco_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_vco_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_s_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_s_SHIFT (6U)
/*! meas_vreg_s - Measure vreg_s in MPLL voltage regulator (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_s(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_s_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_s_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_l_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_l_SHIFT (7U)
/*! meas_vreg_l - Measure vreg_left (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_l(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_l_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_meas_vreg_l_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLA_ATB1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB1_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB1_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_ATB2 - MPLLA_ATB2 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_r_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_r_SHIFT (0U)
/*! meas_vreg_r - Measure vreg_right (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_r(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_r_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_r_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_vp_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_vp_SHIFT (1U)
/*! meas_vreg_vp - Measure vreg_vp (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_cp_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_cp_SHIFT (2U)
/*! meas_vreg_cp - Measure vreg_cp (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_cp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_cp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vreg_cp_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vp_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vp_SHIFT (3U)
/*! meas_vp - Measure VP in MPLL (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vp(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_gd_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_gd_SHIFT (4U)
/*! meas_gd - Measure GD in MPLL (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_gd(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_gd_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_gd_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_ctl_fine_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_ctl_fine_SHIFT (5U)
/*! meas_ctl_fine - Measure buffered version of ctrl_fine_int (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_ctl_fine(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_ctl_fine_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_ctl_fine_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ctrl_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ctrl_SHIFT (6U)
/*! meas_mag_ctrl - Measure VCO magntitude control signal vdrive (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ctrl(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ctrl_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ctrl_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ref_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ref_SHIFT (7U)
/*! meas_mag_ref - Measure reference voltage for VCO magnitude control amp (atb_s_m) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ref_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_meas_mag_ref_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB2_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLA_ATB2_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB2_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB2_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLA_ATB3 - MPLLA_ATB3 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_high_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_high_SHIFT (0U)
/*! force_fine_high - Force fine control voltage to be ~40mV higher than default setting (max value) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_high(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_high_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_high_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_low_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_low_SHIFT (1U)
/*! force_fine_low - Force fine control voltage to be ~40mV lower than default setting (min value) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_low(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_low_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_force_fine_low_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_atb_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_atb_SHIFT (2U)
/*! override_amp_atb - Override VCO amp reference to be the voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_atb(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_atb_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_atb_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_high_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_high_SHIFT (3U)
/*! override_amp_high - Override the default VCO amplitude to make the amplitude larger (high amplitude) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_high(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_high_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_high_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_low_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_low_SHIFT (4U)
/*! override_amp_low - Override the default VCO amplitude to make the amplitude smaller (low amplitude) */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_low(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_low_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_override_amp_low_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_meas_atb_dll_bias_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_meas_atb_dll_bias_SHIFT (5U)
/*! meas_atb_dll_bias - Measures mpll pmix dll bias voltage */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_meas_atb_dll_bias(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_meas_atb_dll_bias_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_meas_atb_dll_bias_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_atb_select_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_atb_select_SHIFT (6U)
/*! atb_select - Connect internal ATB_S signals to external ATB_S signals */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_atb_select(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_atb_select_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_atb_select_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_NC7_MASK     (0x80U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_NC7_SHIFT    (7U)
/*! NC7 - Reserved */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_NC7(x)       (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_NC7_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_NC7_MASK)

#define PHY_ENET_SUP_ANA_MPLLA_ATB3_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLA_ATB3_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLA_ATB3_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLA_ATB3_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLA_OVRD_OUT - Override value for mplla signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_SHIFT (0U)
/*! MPLLA_ANA_EN - Overrides the mplla_ana_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_ANA_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_MASK (0x2U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_SHIFT (1U)
/*! MPLLA_RST - Overrides the mplla_ana_rst signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_RST_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_MASK (0x4U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_SHIFT (2U)
/*! MPLLA_CAL - Overrides the mplla_ana_cal signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_CAL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_SHIFT (3U)
/*! MPLLA_OUTPUT_EN - Overrides the mplla_ana_output_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_MASK (0x10U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_SHIFT (4U)
/*! MPLLA_OUTPUT_L_EN - Overrides the mplla_ana_output_l_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_L_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_SHIFT (5U)
/*! MPLLA_OUTPUT_R_EN - Overrides the mplla_ana_output_r_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_OUTPUT_R_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_SHIFT (6U)
/*! MPLLA_DIV8_CLK_EN - Overrides the mplla_ana_div8_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_SHIFT (7U)
/*! MPLLA_DIV10_CLK_EN - Overrides the mplla_ana_div10_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_SHIFT (8U)
/*! MPLLA_FBCLK_EN - Overrides the mplla_fb_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_FBCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_MASK (0x1E00U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_SHIFT (9U)
/*! RESERVED - RESERVED */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_SHIFT (13U)
/*! MPLLA_DIV_CLK_EN - Overrides the mplla_ana_div_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_MPLLA_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_SHIFT (14U)
/*! OVRD_SEL - Override bit for mplla_ana outputs */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_OVRD_SEL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_OVRD_OUT_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT - Override value for mplla pmix signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_SHIFT (0U)
/*! MPLLA_PMIX_SEL - Overrides the mplla_ana_pmix_sel signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_SHIFT (8U)
/*! MPLLA_PMIX_EN - Override bit for mplla_ana_pmix_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_SHIFT (9U)
/*! MPLLA_PMIX_SEL_OVRD_EN - Override bit for mplla_ana_pmix_sel signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_SEL_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_OVRD_EN_MASK (0x400U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_OVRD_EN_SHIFT (10U)
/*! MPLLA_PMIX_EN_OVRD_EN - Override bit for mplla_ana_pmix_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_MPLLA_PMIX_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLA_PMIX_OVRD_OUT_RESERVED_15_11_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_OVRD_IN - Override values for incoming MPLLA signals */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_VAL_SHIFT (0U)
/*! MPLLA_WORD_DIV2_EN_OVRD_VAL - Override value for mplla_word_div2_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_EN_SHIFT (1U)
/*! MPLLA_WORD_DIV2_EN_OVRD_EN - Override enable for mplla_word_div2_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_WORD_DIV2_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_MASK (0x1CU)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_SHIFT (2U)
/*! MPLLA_TX_CLK_DIV_OVRD_VAL - Override value for mplla_tx_clk_div[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_EN_SHIFT (5U)
/*! MPLLA_TX_CLK_DIV_OVRD_EN - Override enable for mplla_tx_clk_div[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_TX_CLK_DIV_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_VAL_MASK (0x40U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_VAL_SHIFT (6U)
/*! MPLLA_DIV10_CLK_EN_OVRD_VAL - Override value for mplla_div10_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_EN_SHIFT (7U)
/*! MPLLA_DIV10_CLK_EN_OVRD_EN - Override enable for mplla_div10_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV10_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_VAL_MASK (0x100U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_VAL_SHIFT (8U)
/*! MPLLA_DIV8_CLK_EN_OVRD_VAL - Override value for mplla_div8_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_EN_MASK (0x200U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_EN_SHIFT (9U)
/*! MPLLA_DIV8_CLK_EN_OVRD_EN - Override enable for mplla_div8_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV8_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_BW_OVRD_EN_MASK (0x400U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_BW_OVRD_EN_SHIFT (10U)
/*! MPLLA_BW_OVRD_EN - Override enable for mplla_bandwidth[15:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_BW_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_BW_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_BW_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_EN_MASK (0x800U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_EN_SHIFT (11U)
/*! MPLLA_DIV16P5_CLK_EN_OVRD_EN - Override enable for mplla_div_16p5_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_VAL_MASK (0x1000U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_VAL_SHIFT (12U)
/*! MPLLA_DIV16P5_CLK_EN_OVRD_VAL - Override value for mplla_div_16p5_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_MPLLA_DIV16P5_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_OVRD_IN_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_BW_OVRD_IN - Override values for incoming MPLLA bandwidth */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_SHIFT (0U)
/*! MPLLA_BW_OVRD_VAL - Override value for mplla_bandwidth[15:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_BW_OVRD_IN_MPLLA_BW_OVRD_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0 - Override values for incoming MPLLA SSC control settings */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_VAL_MASK (0x7U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_VAL_SHIFT (0U)
/*! MPLLA_SSC_RANGE_OVRD_VAL - Override value for mplla_ssc_range[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_EN_SHIFT (3U)
/*! MPLLA_SSC_RANGE_OVRD_EN - Override enable for mplla_ssc_range[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_RANGE_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_VAL_MASK (0x70U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_VAL_SHIFT (4U)
/*! MPLLA_SSC_CLK_SEL_OVRD_VAL - Override value for mplla_ssc_clk_sel[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_EN_SHIFT (7U)
/*! MPLLA_SSC_CLK_SEL_OVRD_EN - Override enable for mplla_ssc_clk_sel[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_CLK_SEL_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_VAL_MASK (0x100U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_VAL_SHIFT (8U)
/*! MPLLA_SSC_EN_OVRD_VAL - Override value for mplla_ssc_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_EN_MASK (0x200U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_EN_SHIFT (9U)
/*! MPLLA_SSC_EN_OVRD_EN - Override enable for mplla_ssc_en */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_MPLLA_SSC_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1 - Override values for incoming MPLLA SSC control settings */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_VAL_MASK (0x7FFU)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_VAL_SHIFT (0U)
/*! MPLLA_FRACN_CTRL_OVRD_VAL - Override value for mplla_fracn_ctrl[10:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_EN_MASK (0x800U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_EN_SHIFT (11U)
/*! MPLLA_FRACN_CTRL_OVRD_EN - Override enable for mplla_fracn_ctrl[10:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_MPLLA_FRACN_CTRL_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_RESERVED_15_12_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLA_SSC_CTL_OVRD_IN_1_RESERVED_15_12_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_DIV_CLK_OVRD_IN - Override values for incoming MPLLB_DIV_CLK controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_SHIFT (0U)
/*! MPLLB_DIV_CLK_EN - Override value for mpllb_div_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_MASK (0x1FEU)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLB_DIV_MULTIPLIER - Override value for mpllb_div_multiplier */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_OVRD_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_OVRD_EN_SHIFT (9U)
/*! MPLLB_DIV_OVRD_EN - Enable overrides for MPLLB Div clock */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_MPLLB_DIV_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_OVRD_IN_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_0 - Override values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_SHIFT (0U)
/*! MPLLB_EN - Override value for mpllb_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLB_DIV2_EN - Override value for ref_clk_mpllb_div2_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLB_DIV8_CLK_EN - Override value for mpllb_div8_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLB_DIV10_CLK_EN - Override value for mpllb_div10_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_MASK (0xFF0U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_SHIFT (4U)
/*! MPLLB_MULTIPLIER - Override value for mpllb_multiplier */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_MASK (0x7000U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_SHIFT (12U)
/*! MPLLB_TX_CLK_DIV - Override value for mpllb_tx_clk_div */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_MPLLB_TX_CLK_DIV_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_SHIFT (15U)
/*! OVRD_EN - Enable override values for all inputs controlled by this register */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_0_OVRD_EN_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_1 - Override values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - Override value for mpllb_ssc_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_RANGE_MASK (0xEU)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_RANGE_SHIFT (1U)
/*! MPLLB_SSC_RANGE - Override value for mpllb_ssc_range */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_RANGE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_RANGE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_MASK (0x70U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLB_SSC_CLK_SEL - Override value for mpllb_ssc_clk_sel[2:0] */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_CLK_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_OVRD_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_OVRD_EN_SHIFT (7U)
/*! MPLLB_SSC_OVRD_EN - Enable override values for MPLLB SSC inputs */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_SSC_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_WORD_DIV2_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_WORD_DIV2_EN_SHIFT (8U)
/*! MPLLB_WORD_DIV2_EN - Override value for mpllb_word_div2_en */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_WORD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_WORD_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_MPLLB_WORD_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_OVRD_IN_2 - Override values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_FRACN_CTRL_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_FRACN_CTRL_SHIFT (0U)
/*! MPLLB_FRACN_CTRL - Override value for mpllb_fracn_ctrl */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_FRACN_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_MPLLB_FRACN_CTRL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_OVRD_IN_2_RESERVED_15_11_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN - Override values for incoming MPLLB bandwidth controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - Override value for mpllb_bandwidth[15:0] */
#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN_MPLLB_BANDWIDTH_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_OVRD_IN_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_0 - Current values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_SHIFT (0U)
/*! MPLLB_EN - Value from ASIC for mpllb_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT (1U)
/*! REF_CLK_MPLLB_DIV2_EN - Value from ASIC for ref_clk_mpllb_div2_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_REF_CLK_MPLLB_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_SHIFT (2U)
/*! MPLLB_DIV8_CLK_EN - Value from ASIC for mpllb_div8_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_SHIFT (3U)
/*! MPLLB_DIV10_CLK_EN - Value from ASIC for mpllb_div10_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_MASK (0xFF0U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_SHIFT (4U)
/*! MPLLB_MULTIPLIER - Value from ASIC for mpllb_multiplier */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_MASK (0x7000U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_SHIFT (12U)
/*! MPLLB_TX_CLK_DIV - Value from ASIC for mpllb_tx_clk_div */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_MPLLB_TX_CLK_DIV_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_0_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_1 - Current values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_SHIFT (0U)
/*! MPLLB_SSC_EN - Value from mpllb_ssc_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_RANGE_MASK (0xEU)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_RANGE_SHIFT (1U)
/*! MPLLB_SSC_RANGE - Value from mpllb_ssc_range */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_RANGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_RANGE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_RANGE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_MASK (0x70U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_SHIFT (4U)
/*! MPLLB_SSC_CLK_SEL - Value from mpllb_ssc_clk_sel */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_SSC_CLK_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_WORD_DIV2_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_WORD_DIV2_EN_SHIFT (7U)
/*! MPLLB_WORD_DIV2_EN - Value from mpllb_word_div2_en */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_WORD_DIV2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_WORD_DIV2_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_MPLLB_WORD_DIV2_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_1_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_ASIC_IN_2 - Current values for incoming MPLLB controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_FRACN_CTRL_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_FRACN_CTRL_SHIFT (0U)
/*! MPLLB_FRACN_CTRL - Value from mpllb_fracn_ctrl */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_FRACN_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_FRACN_CTRL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_MPLLB_FRACN_CTRL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_ASIC_IN_2_RESERVED_15_11_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_DIV_CLK_ASIC_IN - Current values for incoming MPLLB_DIV_CLK controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_SHIFT (0U)
/*! MPLLB_DIV_CLK_EN - Value from mpllb_div_clk_en */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_MASK (0x1FEU)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_SHIFT (1U)
/*! MPLLB_DIV_MULTIPLIER - Value from mpllb_div_multiplier */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_MPLLB_DIV_MULTIPLIER_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_DIV_CLK_ASIC_IN_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN - Current values for incoming MPLLB bandwidth controls from ASIC */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN_MPLLB_BANDWIDTH_MASK (0xFFFFU)
#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN_MPLLB_BANDWIDTH_SHIFT (0U)
/*! MPLLB_BANDWIDTH - Value from ASIC for mpllb_bandwidth */
#define PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN_MPLLB_BANDWIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN_MPLLB_BANDWIDTH_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_BANDWIDTH_ASIC_IN_MPLLB_BANDWIDTH_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL - MPLL Calibration controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT (0U)
/*! LOAD_CNT - MSBs for the CHKFRQ FSM ld_val[10:0] load value 0x0 - gives a ld_val of 0, no PPM difference can be detected */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_LOAD_CNT_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT (4U)
/*! MPLL_SKIPCAL - Skip automatic (internal) calibration of MPLL (and also skip external calibration if it is enabled) */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_SKIPCAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK (0x20U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT (5U)
/*! MPLL_EXTCAL - Enable external calibration of MPLL */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_MPLL_EXTCAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT (6U)
/*! EXT_CHKFRQ_EN - Check the frequency of the MPLL Only valid in external calibration mode */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CHKFRQ_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK (0x7F80U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT (7U)
/*! EXT_COARSE_TUNE - Value of mpll_ana_coarse_tune_i[7:0] in external calibration mode */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_COARSE_TUNE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT (15U)
/*! EXT_CAL_DONE - Set the external calibration status to done */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_CAL_CTRL_EXT_CAL_DONE_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD - MPLL override controls */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK (0x1U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT (0U)
/*! OVRD_SEL - Override enable bit */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_OVRD_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK (0x2U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT (1U)
/*! MPLL_FBDIGCLK_EN - Overrides the PWR FSM mpll_fb_dig_clk_en signal */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_FBDIGCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK (0x4U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT (2U)
/*! MPLL_PCLK_EN - Overrides the PWR FSM mpll_pclk_en signal */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_MPLL_PCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_MASK (0x8U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_SHIFT (3U)
/*! FAST_MPLL_PWRUP - Enable fast MPLL powerup */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_PWRUP_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_SHIFT (4U)
/*! FAST_MPLL_LOCK - Enable fast MPLL locking */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_FAST_MPLL_LOCK_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK (0x3E0U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT (5U)
/*! DTB_SEL - DTB select for MPLL dtb signals */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_DTB_SEL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_OVRD_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT - MPLL status register */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT (0U)
/*! FSM_STATE - Current value of the PWR FSM state register */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_FSM_STATE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK (0x10U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT (4U)
/*! MPLL_TOOSLOW - Current value of mpll_tooslow */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_TOOSLOW_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK (0x20U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT (5U)
/*! CHKFRQ_DONE - Current value of mpll_chkfrq_done */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_CHKFRQ_DONE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK (0x40U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT (6U)
/*! MPLL_CAL_RDY - Current value of mpll_cal_rdy */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_RDY_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK (0x80U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT (7U)
/*! MPLL_R_LANES - Current value of lane_mpll_r */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_R_LANES_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT (8U)
/*! MPLL_L_LANES - Current value of lane_mpll_l */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_L_LANES_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT (9U)
/*! MPLL_PCLK_EN - Current value of mpll_pclk_en */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_PCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK (0x400U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT (10U)
/*! MPLL_OUTPUT_EN - Current value of mpll_ana_output_en_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_OUTPUT_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK (0x800U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT (11U)
/*! MPLL_FBCLK_EN - Current value of mpll_ana_fb_clk_en_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_FBCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT (12U)
/*! MPLL_CAL - Current value of mpll_ana_cal_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_CAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT (13U)
/*! MPLL_RST - Current value of mpll_ana_rst_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_RST_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT (14U)
/*! MPLL_ANA_EN - Current value of mpll_ana_en_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_MPLL_ANA_EN_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_STAT_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD - Thresholds for MPLL CAL Update timer and MPLL VCO Stabilization timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK (0x1FFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO stabilization timer in terms of number
 *    of reference clock cycles Here the reference clock means the one that is fed to the phase
 *    detector of the corresponding PLL not the raw reference clock.
 */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_VCO_STABILIZATION_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK (0x1E00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT (9U)
/*! MPLL_CAL_UPDATE_TIME_THRESHOLD - Threshold for the MPLL calibration control word update timer in terms of number of ref_rang_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_MPLL_CAL_UPDATE_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_MISC_TIME_THRESHOLD_RESERVED_15_13_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD - Thresholds for PCLK enable and MPLL VCO Clock Stabilization timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK (0x7FFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT (0U)
/*! VCO_CLK_STABILIZATION_TIME_THRESHOLD - Threshold for the VCO clock stabilization timer in terms
 *    of number of reference clock cycles Here the reference clock means the one that is fed to the
 *    phase detector of the corresponding PLL not the raw reference clock.
 */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_VCO_CLK_STABILIZATION_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT (11U)
/*! PCLK_EN_TIME_THRESHOLD - Threshold for the PCLK enable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_EN_AND_VCO_CLK_STABILIZATION_TIME_THRESHOLD_PCLK_EN_TIME_THRESHOLD_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD - Thresholds for PCLK disable and MPLL VCO POWER DOWN timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_MASK (0x1FU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_SHIFT (0U)
/*! PCLK_DIS_TIME_THRESHOLD - Threshold for the PCLK disable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_PCLK_DIS_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK (0x3E0U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT (5U)
/*! MPLL_VCO_PWRDN_TIME_THRESHOLD - Threshold for the MPLL VCO power down timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_MPLL_VCO_PWRDN_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_PCLK_DIS_AND_MPLL_VCO_PWRDN_THRESHOLD_RESERVED_15_10_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD - Thresholds for MPLL feedback clock enable and MPLL feedback digital clock disable and MPLL ANA POWER UP timer */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK (0xFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT (0U)
/*! MPLL_FBCLK_EN_TIME_THRESHOLD - Threshold for the MPLL feedback clock enable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBCLK_EN_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK (0xF0U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT (4U)
/*! MPLL_FBDIGCLK_DIS_TIME_THRESHOLD - Threshold for the MPLL feedback digital clock disable timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_FBDIGCLK_DIS_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK (0x7F00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT (8U)
/*! MPLL_ANA_PWRUP_TIME_THRESHOLD - Threshold for the MPLL analog power up timer in terms of number of ref_range_clk cycles */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_MPLL_ANA_PWRUP_TIME_THRESHOLD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_FBCLK_EN_AND_MPLL_FBDIGCLK_DIS_AND_MPLL_ANA_PWRUP_TIME_THRESHOLD_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL - MPLL coarse_tune value register */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT (0U)
/*! MPLL_COARSE_TUNE_VAL - Current value of mpll_ana_coarse_tune_i */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_MPLL_COARSE_TUNE_VAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_COARSE_TUNE_VAL_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when skipping calibration */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT (0U)
/*! MPLL_SKIPCAL_COARSE_TUNE - Value for MPLL coarse_tune when calibration is skipped */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_MPLL_SKIPCAL_COARSE_TUNE_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_MPLL_PWR_CTL_MPLL_SKIPCAL_COARSE_TUNE_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_PHASE - Current MPLL phase selector value */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_MASK (0x3U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_SHIFT (0U)
/*! DTHR - Bits below the useful resolution (2 reads needed to read value) */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_DTHR_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_MASK (0x7FCU)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_SHIFT (2U)
/*! VAL - Phase value from zero reference (2 reads needed to read value) */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_VAL_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_MASK (0x800U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_SHIFT (11U)
/*! ZERO_FREQ - Zero frequency register. */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_ZERO_FREQ_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_RESERVED_15_12_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_PHASE_RESERVED_15_12_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_FREQ_0 - Frequency Control for Spread Spectrum #0 */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK (0xFFFU)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT (0U)
/*! FREQ_CNT_INIT - Initial Frequency Counter Value */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_CNT_INIT_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK (0x1000U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT (12U)
/*! FREQ_0_OVRD - Frequency Reigster Override. */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_FREQ_0_OVRD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_RESERVED_15_13_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_0_RESERVED_15_13_MASK)
/*! @} */

/*! @name SUP_DIG_MPLLB_SSC_SS_FREQ_1 - Frequency Control for Spread Spectrum #1 */
/*! @{ */

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PK_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PK_SHIFT (0U)
/*! FREQ_PK - Peak Frequency Value (for changing direction) */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PK_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_PK_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK (0x100U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT (8U)
/*! FREQ_1_OVRD - Frequency Reigster Override. */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_FREQ_1_OVRD_MASK)

#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_RESERVED_15_9_SHIFT)) & PHY_ENET_SUP_DIG_MPLLB_SSC_SS_FREQ_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_MISC - MPLLB_MISC */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLB_MISC_bypass_buf_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_bypass_buf_SHIFT (0U)
/*! bypass_buf - To bypass CP buffers. */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_bypass_buf(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_bypass_buf_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_bypass_buf_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_MISC_ovrd_pr_bypass_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_ovrd_pr_bypass_SHIFT (1U)
/*! ovrd_pr_bypass - If asserted, pr_bypass take effect on phase rotator bypass control */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_ovrd_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_ovrd_pr_bypass_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_ovrd_pr_bypass_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_MISC_mode_old_ssc_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_mode_old_ssc_SHIFT (2U)
/*! mode_old_ssc - Uses just two bits for SSC interpolation */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_mode_old_ssc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_mode_old_ssc_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_mode_old_ssc_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_MISC_pr_bypass_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_pr_bypass_SHIFT (3U)
/*! pr_bypass - If ovrd_pr_bypass is enabled: */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_pr_bypass(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_pr_bypass_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_pr_bypass_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_MISC_NC7_4_MASK   (0xF0U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_NC7_4_SHIFT  (4U)
/*! NC7_4 - Reserved */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_NC7_4(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_NC7_4_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_NC7_4_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_MISC_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLB_MISC_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLB_MISC_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_MISC_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_MISC_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_OVRD - MPLLB_OVRD */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_enable_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_enable_SHIFT (0U)
/*! ovrd_enable - enable local control of enable signal (mpll_en) */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_enable(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_enable_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_enable_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_enable_reg_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_enable_reg_SHIFT (1U)
/*! enable_reg - set local enable control to ON */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_enable_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_enable_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_enable_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_cal_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_cal_SHIFT (2U)
/*! ovrd_cal - enable local control of calibration signal (mpll_cal) */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_cal(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_cal_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_cal_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_cal_reg_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_cal_reg_SHIFT (3U)
/*! cal_reg - set local calibration control to ON */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_cal_reg(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_cal_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_cal_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_SHIFT (4U)
/*! ovrd_fb_clk_en - enable local control of feedback clock control signal (mpll_fb_clk_en) */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_fb_clk_en_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_SHIFT (5U)
/*! fb_clk_en_reg - set local feedback clock control to ON */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_fb_clk_en_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_reset_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_reset_SHIFT (6U)
/*! ovrd_reset - enable local control of reset signal (mpll_rst) */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_reset(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_reset_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_ovrd_reset_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_reset_reg_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_reset_reg_SHIFT (7U)
/*! reset_reg - set local reset control to ON */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_reset_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_reset_reg_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_reset_reg_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_OVRD_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLB_OVRD_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_OVRD_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_OVRD_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_ATB1 - MPLLB_ATB1 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vco_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vco_SHIFT (0U)
/*! override_vreg_vco - Override vreg_vco to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vco(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vco_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vco_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_right_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_right_SHIFT (1U)
/*! override_vreg_right - Override vreg_right to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_right(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_right_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_right_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_left_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_left_SHIFT (2U)
/*! override_vreg_left - Override vreg_left to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_left(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_left_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_left_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vp_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vp_SHIFT (3U)
/*! override_vreg_vp - Override vreg_vp to be 4/3X of voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_cp_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_cp_SHIFT (4U)
/*! override_vreg_cp - Override vreg_cp to be 4/3X of voltage on atb_s_m. */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_cp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_cp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_override_vreg_cp_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_vco_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_vco_SHIFT (5U)
/*! meas_vreg_vco - Measure vreg_vco (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_vco(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_vco_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_vco_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_s_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_s_SHIFT (6U)
/*! meas_vreg_s - Measure vreg_s in MPLL voltage regulator (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_s(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_s_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_s_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_l_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_l_SHIFT (7U)
/*! meas_vreg_l - Measure vreg_left (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_l(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_l_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_meas_vreg_l_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLB_ATB1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB1_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB1_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_ATB2 - MPLLB_ATB2 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_r_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_r_SHIFT (0U)
/*! meas_vreg_r - Measure vreg_right (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_r(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_r_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_r_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_vp_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_vp_SHIFT (1U)
/*! meas_vreg_vp - Measure vreg_vp (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_cp_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_cp_SHIFT (2U)
/*! meas_vreg_cp - Measure vreg_cp (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_cp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_cp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vreg_cp_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vp_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vp_SHIFT (3U)
/*! meas_vp - Measure VP in MPLL (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vp(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vp_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_vp_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_gd_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_gd_SHIFT (4U)
/*! meas_gd - Measure GD in MPLL (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_gd(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_gd_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_gd_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_ctl_fine_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_ctl_fine_SHIFT (5U)
/*! meas_ctl_fine - Measure buffered version of ctrl_fine_int (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_ctl_fine(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_ctl_fine_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_ctl_fine_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ctrl_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ctrl_SHIFT (6U)
/*! meas_mag_ctrl - Measure VCO magntitude control signal vdrive (atb_s_p) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ctrl(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ctrl_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ctrl_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ref_MASK (0x80U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ref_SHIFT (7U)
/*! meas_mag_ref - Measure reference voltage for VCO magnitude control amp (atb_s_m) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ref_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_meas_mag_ref_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB2_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLB_ATB2_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB2_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB2_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_ANA_MPLLB_ATB3 - MPLLB_ATB3 */
/*! @{ */

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_high_MASK (0x1U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_high_SHIFT (0U)
/*! force_fine_high - Force fine control voltage to be ~40mV higher than default setting (max value) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_high(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_high_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_high_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_low_MASK (0x2U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_low_SHIFT (1U)
/*! force_fine_low - Force fine control voltage to be ~40mV lower than default setting (min value) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_low(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_low_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_force_fine_low_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_atb_MASK (0x4U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_atb_SHIFT (2U)
/*! override_amp_atb - Override VCO amp reference to be the voltage on atb_s_m */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_atb(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_atb_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_atb_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_high_MASK (0x8U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_high_SHIFT (3U)
/*! override_amp_high - Override the default VCO amplitude to make the amplitude larger (high amplitude) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_high(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_high_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_high_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_low_MASK (0x10U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_low_SHIFT (4U)
/*! override_amp_low - Override the default VCO amplitude to make the amplitude smaller (low amplitude) */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_low(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_low_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_override_amp_low_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_meas_atb_dll_bias_MASK (0x20U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_meas_atb_dll_bias_SHIFT (5U)
/*! meas_atb_dll_bias - Measures mpll pmix dll bias voltage */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_meas_atb_dll_bias(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_meas_atb_dll_bias_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_meas_atb_dll_bias_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_atb_select_MASK (0x40U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_atb_select_SHIFT (6U)
/*! atb_select - Connect internal ATB_S signals to external ATB_S signals */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_atb_select(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_atb_select_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_atb_select_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_NC7_MASK     (0x80U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_NC7_SHIFT    (7U)
/*! NC7 - Reserved */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_NC7(x)       (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_NC7_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_NC7_MASK)

#define PHY_ENET_SUP_ANA_MPLLB_ATB3_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_SUP_ANA_MPLLB_ATB3_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_ANA_MPLLB_ATB3_RESERVED_15_8_SHIFT)) & PHY_ENET_SUP_ANA_MPLLB_ATB3_RESERVED_15_8_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLB_OVRD_OUT - Override value for mpllb signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_MASK (0x1U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_SHIFT (0U)
/*! MPLLB_ANA_EN - Overrides the mpllb_ana_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_ANA_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_MASK (0x2U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_SHIFT (1U)
/*! MPLLB_RST - Overrides the mpllb_ana_rst signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_RST_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_MASK (0x4U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_SHIFT (2U)
/*! MPLLB_CAL - Overrides the mpllb_ana_cal signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_CAL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_MASK (0x8U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_SHIFT (3U)
/*! MPLLB_OUTPUT_EN - Overrides the mpllb_ana_output_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_MASK (0x10U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_SHIFT (4U)
/*! MPLLB_OUTPUT_L_EN - Overrides the mpllb_ana_output_l_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_L_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_MASK (0x20U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_SHIFT (5U)
/*! MPLLB_OUTPUT_R_EN - Overrides the mpllb_ana_output_r_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_OUTPUT_R_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_MASK (0x40U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_SHIFT (6U)
/*! MPLLB_DIV8_CLK_EN - Overrides the mpllb_ana_div8_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV8_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_MASK (0x80U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_SHIFT (7U)
/*! MPLLB_DIV10_CLK_EN - Overrides the mpllb_ana_div10_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV10_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_SHIFT (8U)
/*! MPLLB_FBCLK_EN - Overrides the mpllb_fb_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_FBCLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_MASK (0x1E00U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_SHIFT (9U)
/*! RESERVED - RESERVED */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_MASK (0x2000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_SHIFT (13U)
/*! MPLLB_DIV_CLK_EN - Overrides the mpllb_ana_div_clk_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_MPLLB_DIV_CLK_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_MASK (0x4000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_SHIFT (14U)
/*! OVRD_SEL - Override bit for mpllb_ana outputs */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_OVRD_SEL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_15_15_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_OVRD_OUT_RESERVED_15_15_MASK)
/*! @} */

/*! @name SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT - Override value for mpllb pmix signals going to ANA */
/*! @{ */

#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_MASK (0xFFU)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_SHIFT (0U)
/*! MPLLB_PMIX_SEL - Overrides the mpllb_ana_pmix_sel signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_MASK (0x100U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_SHIFT (8U)
/*! MPLLB_PMIX_EN - Override bit for mpllb_ana_pmix_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_MASK (0x200U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_SHIFT (9U)
/*! MPLLB_PMIX_SEL_OVRD_EN - Override bit for mpllb_ana_pmix_sel signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_SEL_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_OVRD_EN_MASK (0x400U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_OVRD_EN_SHIFT (10U)
/*! MPLLB_PMIX_EN_OVRD_EN - Override bit for mpllb_ana_pmix_en signal */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_OVRD_EN_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_MPLLB_PMIX_EN_OVRD_EN_MASK)

#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_RESERVED_15_11_SHIFT)) & PHY_ENET_SUP_DIG_ANA_MPLLB_PMIX_OVRD_OUT_RESERVED_15_11_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_OVRD_IN - Override values for incoming MPLLB signals */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_VAL_SHIFT (0U)
/*! MPLLB_WORD_DIV2_EN_OVRD_VAL - Override value for mpllb_word_div2_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_EN_SHIFT (1U)
/*! MPLLB_WORD_DIV2_EN_OVRD_EN - Override enable for mpllb_word_div2_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_WORD_DIV2_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_MASK (0x1CU)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_SHIFT (2U)
/*! MPLLB_TX_CLK_DIV_OVRD_VAL - Override value for mpllb_tx_clk_div[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_EN_SHIFT (5U)
/*! MPLLB_TX_CLK_DIV_OVRD_EN - Override enable for mpllb_tx_clk_div[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_TX_CLK_DIV_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_VAL_MASK (0x40U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_VAL_SHIFT (6U)
/*! MPLLB_DIV10_CLK_EN_OVRD_VAL - Override value for mpllb_div10_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_EN_SHIFT (7U)
/*! MPLLB_DIV10_CLK_EN_OVRD_EN - Override enable for mpllb_div10_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV10_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_VAL_MASK (0x100U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_VAL_SHIFT (8U)
/*! MPLLB_DIV8_CLK_EN_OVRD_VAL - Override value for mpllb_div8_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_EN_MASK (0x200U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_EN_SHIFT (9U)
/*! MPLLB_DIV8_CLK_EN_OVRD_EN - Override enable for mpllb_div8_clk_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_DIV8_CLK_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_BW_OVRD_EN_MASK (0x400U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_BW_OVRD_EN_SHIFT (10U)
/*! MPLLB_BW_OVRD_EN - Override enable for mpllb_bandwidth[15:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_BW_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_BW_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_MPLLB_BW_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_RESERVED_15_11_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_OVRD_IN_RESERVED_15_11_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_BW_OVRD_IN - Override values for incoming MPLLB bandwidth */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_SHIFT (0U)
/*! MPLLB_BW_OVRD_VAL - Override value for mpllb_bandwidth[15:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_BW_OVRD_IN_MPLLB_BW_OVRD_VAL_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0 - Override values for incoming MPLLB SSC control settings */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_VAL_MASK (0x7U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_VAL_SHIFT (0U)
/*! MPLLB_SSC_RANGE_OVRD_VAL - Override value for mpllb_ssc_range[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_EN_SHIFT (3U)
/*! MPLLB_SSC_RANGE_OVRD_EN - Override enable for mpllb_ssc_range[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_RANGE_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_VAL_MASK (0x70U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_VAL_SHIFT (4U)
/*! MPLLB_SSC_CLK_SEL_OVRD_VAL - Override value for mpllb_ssc_clk_sel[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_EN_SHIFT (7U)
/*! MPLLB_SSC_CLK_SEL_OVRD_EN - Override enable for mpllb_ssc_clk_sel[2:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_CLK_SEL_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_VAL_MASK (0x100U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_VAL_SHIFT (8U)
/*! MPLLB_SSC_EN_OVRD_VAL - Override value for mpllb_ssc_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_EN_MASK (0x200U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_EN_SHIFT (9U)
/*! MPLLB_SSC_EN_OVRD_EN - Override enable for mpllb_ssc_en */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_MPLLB_SSC_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1 - Override values for incoming MPLLB SSC control settings */
/*! @{ */

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_VAL_MASK (0x7FFU)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_VAL_SHIFT (0U)
/*! MPLLB_FRACN_CTRL_OVRD_VAL - Override value for mpllb_fracn_ctrl[10:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_VAL_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_EN_MASK (0x800U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_EN_SHIFT (11U)
/*! MPLLB_FRACN_CTRL_OVRD_EN - Override enable for mpllb_fracn_ctrl[10:0] */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_EN_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_MPLLB_FRACN_CTRL_OVRD_EN_MASK)

#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_RESERVED_15_12_SHIFT)) & PHY_ENET_RAWCMN_DIG_MPLLB_SSC_CTL_OVRD_IN_1_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_LANE_OVRD_IN - Override values for incoming LANE controls from ASIC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_SHIFT (0U)
/*! LANE_TX2RX_SER_LB - Override value for lane_tx2rx_ser_lb_en_r */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_TX2RX_SER_LB_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_SHIFT (1U)
/*! LANE_RX2TX_PAR_LB - Override value for lane_rx2tx_par_lb_en_r */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_LANE_RX2TX_PAR_LB_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_SHIFT (2U)
/*! EN - Enable override values for all inputs controlled by this register */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_RESERVED_15_3_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_OVRD_IN_RESERVED_15_3_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_0 - Override values for incoming TX controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_SHIFT (0U)
/*! REQ - Override value for tx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_OVRD_EN_SHIFT (1U)
/*! REQ_OVRD_EN - Enable override for tx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_REQ_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_MASK (0xCU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_SHIFT (2U)
/*! PSTATE - Override value for tx_pstate[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_OVRD_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_OVRD_EN_SHIFT (4U)
/*! PSTATE_OVRD_EN - Enable override for tx_pstate[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_PSTATE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_MASK (0xE0U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_SHIFT (5U)
/*! RATE - Override value for tx_rate[2:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_OVRD_EN_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_OVRD_EN_SHIFT (8U)
/*! RATE_OVRD_EN - Enable override for tx_rate[2:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_RATE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_MASK (0x600U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_SHIFT (9U)
/*! WIDTH - Override value for tx_width[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_OVRD_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_OVRD_EN_SHIFT (11U)
/*! WIDTH_OVRD_EN - Enable override for tx_width[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_WIDTH_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_SHIFT (12U)
/*! MPLLB_SEL - Override value for tx_mpllb_sel */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_OVRD_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_OVRD_EN_SHIFT (13U)
/*! MPLLB_SEL_OVRD_EN - Enable override for tx_mpllb_sel */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_MPLLB_SEL_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_SHIFT (14U)
/*! DATA_EN - Override value for tx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_OVRD_EN_SHIFT (15U)
/*! DATA_EN_OVRD_EN - Enable override for tx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_0_DATA_EN_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_1 - Override values for incoming TX drive controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_SHIFT (0U)
/*! NYQUIST_DATA - Override incoming data to nyquist */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_NYQUIST_DATA_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_SHIFT (1U)
/*! DISABLE - Override value for tx_disable */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_SHIFT (2U)
/*! BEACON_EN - Override value for tx_beacon_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_BEACON_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_MASK (0x78U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_SHIFT (3U)
/*! IBOOST_LVL - Override value for tx_iboost_lvl */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_IBOOST_LVL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_SHIFT (7U)
/*! VBOOST_EN - Override value for tx_vboost_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_VBOOST_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_SHIFT (8U)
/*! EN - Enable override values for inputs below controlled by this register */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_MASK (0x7E00U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_SHIFT (9U)
/*! TX_MAIN_CURSOR - Override value for tx_eq_main */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_TX_MAIN_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_SHIFT (15U)
/*! MAIN_OVRD_EN - Enable override values for TX EQ main input */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_1_MAIN_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_2 - Override values for incoming TX drive controls from ASIC, register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_SHIFT (0U)
/*! TX_PRE_CURSOR - Override value for tx_eq_pre */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_PRE_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_SHIFT (6U)
/*! PRE_OVRD_EN - Enable override values for TX EQ pre input */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_PRE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_MASK (0x1F80U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_SHIFT (7U)
/*! TX_POST_CURSOR - Override value for tx_eq_post */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_TX_POST_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_SHIFT (13U)
/*! POST_OVRD_EN - Enable override values for TX EQ post input */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_POST_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_2_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_3 - Override values for incoming TX drive controls from ASIC, register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_SHIFT (0U)
/*! CLK_RDY - Override value for tx_clk_rdy */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_OVRD_EN_SHIFT (1U)
/*! CLK_RDY_OVRD_EN - Enable override for tx_clk_rdy */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_CLK_RDY_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_SHIFT (2U)
/*! DETECT_RX_REQ - Override value for tx_detrx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_OVRD_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_OVRD_EN_SHIFT (3U)
/*! DETECT_RX_REQ_OVRD_EN - Enable override for tx_detrx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_DETECT_RX_REQ_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_SHIFT (4U)
/*! INVERT - Override value for tx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_OVRD_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_OVRD_EN_SHIFT (5U)
/*! INVERT_OVRD_EN - Enable override for tx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_INVERT_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_SHIFT (6U)
/*! LPD - Override value for tx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_OVRD_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_OVRD_EN_SHIFT (7U)
/*! LPD_OVRD_EN - Enable override for tx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_LPD_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_3_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_IN_4 - Override values for incoming TX drive controls from ASIC, register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_SHIFT (0U)
/*! RESET - Override value for tx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Enable override for tx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESET_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_IN_4_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_OVRD_OUT - Override values for outgoing TX controls to ASIC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_SHIFT (0U)
/*! TX_ACK - Override value for tx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_TX_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_SHIFT (1U)
/*! EN_TX_ACK - Enable for override value for tx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_TX_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_SHIFT (2U)
/*! DETRX_RESULT - Override value for tx_detrx_result */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_DETRX_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_SHIFT (3U)
/*! EN_DETRX_RESULT - Enable for override value for tx_detrx_result */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_EN_DETRX_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_RESERVED_15_4_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_OVRD_OUT_RESERVED_15_4_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_0 - Override values for incoming RX controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_SHIFT (0U)
/*! REQ - Override value for rx_req */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_OVRD_EN_SHIFT (1U)
/*! REQ_OVRD_EN - Enable override value for rx_req */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_REQ_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_SHIFT (2U)
/*! DATA_EN - Override value for rx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_OVRD_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_OVRD_EN_SHIFT (3U)
/*! DATA_EN_OVRD_EN - Enable override value for rx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_DATA_EN_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_MASK (0x30U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_SHIFT (4U)
/*! PSTATE - Override value for rx_pstate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_OVRD_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_OVRD_EN_SHIFT (6U)
/*! PSTATE_OVRD_EN - Enable override value for rx_pstate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_PSTATE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_MASK (0x180U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_SHIFT (7U)
/*! RATE - Override value for rx_rate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_OVRD_EN_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_OVRD_EN_SHIFT (9U)
/*! RATE_OVRD_EN - Enable override value for rx_rate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RATE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_MASK (0xC00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_SHIFT (10U)
/*! WIDTH - Override value for rx_width */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_OVRD_EN_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_OVRD_EN_SHIFT (12U)
/*! WIDTH_OVRD_EN - Enable override for rx_width */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_WIDTH_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_0_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_1 - Override values for incoming RX controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_5_0_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_5_0_SHIFT (0U)
/*! RX_REF_LD_VAL_5_0 - Override value for rx_ref_ld_val[5:0] */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_5_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_5_0_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_5_0_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_LOWFREQ_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_LOWFREQ_SHIFT (6U)
/*! RX_CDR_VCO_LOWFREQ - Override value for rx_cdr_vco_lowfreq */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_LOWFREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_LOWFREQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_CDR_VCO_LOWFREQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_SHIFT (7U)
/*! EN - Enable override values for all inputs controlled by this register */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_6_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_6_SHIFT (8U)
/*! RX_REF_LD_VAL_6 - Override value for rx_ref_ld_val[6] */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_6_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RX_REF_LD_VAL_6_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_2 - Override values for incoming RX controls from ASIC, register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_SHIFT (0U)
/*! RX_VCO_LD_VAL - Override value for rx_vco_ld_val */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RX_VCO_LD_VAL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_SHIFT (13U)
/*! EN - Enable override values for all inputs controlled by this register */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_2_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_3 - Override values for incoming RX controls from ASIC, register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_SHIFT (0U)
/*! CDR_TRACK_EN - Override value for rx_cdr_track_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_OVRD_EN_SHIFT (1U)
/*! CDR_TRACK_EN_OVRD_EN - Enable override value for rx_cdr_track_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_TRACK_EN_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_SHIFT (2U)
/*! CDR_SSC_EN - Override value for rx_cdr_ssc_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_OVRD_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_OVRD_EN_SHIFT (3U)
/*! CDR_SSC_EN_OVRD_EN - Enable override value for rx_cdr_ssc_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CDR_SSC_EN_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_SHIFT (4U)
/*! ALIGN_EN - Override value for rx_align_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_OVRD_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_OVRD_EN_SHIFT (5U)
/*! ALIGN_EN_OVRD_EN - Enable override for rx_align_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_ALIGN_EN_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_SHIFT (6U)
/*! CLK_SHIFT - Override value for rx_clk_shift */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_OVRD_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_OVRD_EN_SHIFT (7U)
/*! CLK_SHIFT_OVRD_EN - Enable override for rx_clk_shift */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_CLK_SHIFT_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_SHIFT (8U)
/*! DISABLE - Override value for rx_disable */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_OVRD_EN_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_OVRD_EN_SHIFT (9U)
/*! DISABLE_OVRD_EN - Enable override for rx_disable */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_DISABLE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_MASK (0x1C00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_SHIFT (10U)
/*! LOS_THRSHLD - Override value for rx_los_threshold */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_THRSHLD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_SHIFT (13U)
/*! LOS_LPFS_EN - Override value for rx_los_lfps_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_LPFS_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_OVRD_EN_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_OVRD_EN_SHIFT (14U)
/*! LOS_OVRD_EN - Enable override for rx_los_lfps_en and rx_los_threshold */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_LOS_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_3_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_4 - Override values for incoming RX controls from ASIC, register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_SHIFT (0U)
/*! LPD - Override value for rx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_OVRD_EN_SHIFT (1U)
/*! LPD_OVRD_EN - Enable override for rx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_LPD_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_SHIFT (2U)
/*! INVERT - Override value for rx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_OVRD_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_OVRD_EN_SHIFT (3U)
/*! INVERT_OVRD_EN - Enable override for rx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_INVERT_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_AFE_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_AFE_EN_SHIFT (4U)
/*! ADAPT_AFE_EN - Override value for rx_adapt_afe_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_DFE_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_DFE_EN_SHIFT (5U)
/*! ADAPT_DFE_EN - Override value for rx_adapt_dfe_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_DFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADAPT_DFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADPT_OVRD_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADPT_OVRD_EN_SHIFT (6U)
/*! ADPT_OVRD_EN - Enable override for rx_adpt_dfe_en and rx_adpt_afe_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADPT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADPT_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_ADPT_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_EN_SHIFT (7U)
/*! TERM_EN - Override value for rx_term_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_ACDC_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_ACDC_SHIFT (8U)
/*! TERM_ACDC - Override value for rx_term_acdc */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_ACDC(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_ACDC_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_ACDC_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_OVRD_EN_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_OVRD_EN_SHIFT (9U)
/*! TERM_OVRD_EN - Enable override for rx_term_acdc and rx_term_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_TERM_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_4_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_IN_5 - Override values for incoming RX controls from ASIC, register #5 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_SHIFT (0U)
/*! RESET - Override value for rx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Enable override for rx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESET_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_IN_5_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0 - Override values for incoming RX EQ controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Override value for rx_eq_att_lvl */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_ATT_LVL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_AFE_GAIN_MASK (0x78U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_AFE_GAIN_SHIFT (3U)
/*! EQ_AFE_GAIN - Override value for rx_eq_afe_gain */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_AFE_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_AFE_GAIN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_AFE_GAIN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_RESERVED_MASK (0x780U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_RESERVED_SHIFT (7U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_MASK (0xF800U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_SHIFT (11U)
/*! EQ_CTLE_BOOST - Override value for rx_eq_ctle_boost */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_0_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1 - Override values for incoming RX EQ controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP2_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP2_SHIFT (0U)
/*! EQ_DFE_TAP2 - Override value for rx_eq_dfe_tap2 */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP2_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_MASK (0x7F80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_SHIFT (7U)
/*! EQ_DFE_TAP1 - Override value for rx_eq_dfe_tap1 */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_DFE_TAP1_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_SHIFT (15U)
/*! EQ_OVRD_EN - Enable override value for rx_eq_* inputs */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_EQ_IN_1_EQ_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_OVRD_OUT_0 - Override values for outgoing RX controls to ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_SHIFT (0U)
/*! ACK - Override value for rx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_OVRD_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_OVRD_EN_SHIFT (1U)
/*! ACK_OVRD_EN - Enable override for rx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ACK_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_SHIFT (2U)
/*! LOS - Override value for rx_los */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_OUT_OVRD_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_OUT_OVRD_EN_SHIFT (3U)
/*! LOS_OUT_OVRD_EN - Enable override for rx_los_r */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_OUT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_OUT_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_LOS_OUT_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_MASK (0x30U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_SHIFT (4U)
/*! ADAPT_STS - Override value for rx_adapt_sts */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_OVRD_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_OVRD_EN_SHIFT (6U)
/*! ADAPT_STS_OVRD_EN - Enable override for rx_adapt_sts */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_ADAPT_STS_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_RESERVED_15_7_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_OVRD_OUT_0_RESERVED_15_7_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_LANE_ASIC_IN - Current values for incoming LANE controls from ASIC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_SHIFT (0U)
/*! LANE_TX2RX_SER_LB - Value from ASIC for lane_tx2rx_ser_lb_en_r */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_TX2RX_SER_LB_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_SHIFT (1U)
/*! LANE_RX2TX_PAR_LB - Value from ASIC for lane_rx2tx_par_lb_en_r */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_LANE_RX2TX_PAR_LB_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_LANE_ASIC_IN_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_0 - Current values for incoming TX controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_SHIFT (0U)
/*! CLK_RDY - Value from ASIC for tx_clk_rdy */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_CLK_RDY_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_SHIFT (1U)
/*! RESET - Value from ASIC for tx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RESET_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_SHIFT (2U)
/*! INVERT - Value from ASIC for tx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_INVERT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_SHIFT (3U)
/*! DATA_EN - Value from ASIC for tx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_SHIFT (4U)
/*! REQ - Value from ASIC for tx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_SHIFT (5U)
/*! LPD - Value from ASIC for tx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_LPD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_MASK (0xC0U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_SHIFT (6U)
/*! PSTATE - Value from ASIC for tx_pstate[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_PSTATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_MASK (0x700U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_SHIFT (8U)
/*! RATE - Value from ASIC for tx_rate[2:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_MASK (0x1800U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_SHIFT (11U)
/*! WIDTH - Value from ASIC for tx_width[1:0] */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_WIDTH_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_SHIFT (13U)
/*! MPLLB_SEL - Value from ASIC for tx_mpllb_sel */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_MPLLB_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_SHIFT (14U)
/*! DETECT_RX_REQ - Value from ASIC for tx_detrx_req */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DETECT_RX_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_SHIFT (15U)
/*! DISABLE - Value from ASIC for tx_disable */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_0_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_1 - Current values for incoming TX controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_SHIFT (0U)
/*! BEACON_EN - Value from ASIC for tx_beacon_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_BEACON_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_MASK (0x1EU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_SHIFT (1U)
/*! IBOOST_LVL - Value from ASIC for tx_iboost_lvl */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_IBOOST_LVL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_SHIFT (5U)
/*! VBOOST_EN - Value from ASIC for tx_vboost_en */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_VBOOST_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_MASK (0xFC0U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_SHIFT (6U)
/*! TX_MAIN_CURSOR - Value from ASIC for tx_eq_main */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_TX_MAIN_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_1_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_IN_2 - Current values for incoming TX controls from ASIC, register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_SHIFT (0U)
/*! TX_PRE_CURSOR - Value from ASIC for tx_eq_pre */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_PRE_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_MASK (0xFC0U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_SHIFT (6U)
/*! TX_POST_CURSOR - Value from ASIC for tx_eq_post */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_TX_POST_CURSOR_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_IN_2_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_TX_ASIC_OUT - Current values for outgoing TX status controls from PHY */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_SHIFT (0U)
/*! TX_ACK - Value from PHY for tx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_TX_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_SHIFT (1U)
/*! DETRX_RESULT - Value from PHY for tx_detrx_result */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_DETRX_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_TX_ASIC_OUT_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_IN_0 - Current values for incoming RX controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_SHIFT (0U)
/*! RESET - Value from ASIC for rx_reset */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESET_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_SHIFT (1U)
/*! INVERT - Value from ASIC for rx_invert */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_INVERT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_SHIFT (2U)
/*! DATA_EN - Value from ASIC for rx_data_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_SHIFT (3U)
/*! REQ - Value from ASIC for rx_req */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_REQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_SHIFT (4U)
/*! LPD - Value from ASIC for rx_lpd */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_LPD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_MASK (0x60U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_SHIFT (5U)
/*! PSTATE - Value from ASIC for rx_pstate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_PSTATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_MASK (0x180U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_SHIFT (7U)
/*! RATE - Value from ASIC for rx_rate */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_MASK (0x600U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_SHIFT (9U)
/*! WIDTH - Value from ASIC for rx_width */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_WIDTH_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_SHIFT (11U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_AFE_EN_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_AFE_EN_SHIFT (12U)
/*! ADAPT_AFE_EN - Value from ASIC for rx_adapt_afe_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_DFE_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_DFE_EN_SHIFT (13U)
/*! ADAPT_DFE_EN - Value from ASIC for rx_adapt_dfe_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_DFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_ADAPT_DFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_SHIFT (14U)
/*! CDR_TRACK_EN - Value from ASIC for rx_cdr_track_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_CDR_TRACK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_0_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_IN_1 - Current values for incoming RX controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_SHIFT (0U)
/*! CDR_SSC_EN - Value from ASIC for rx_cdr_ssc_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CDR_SSC_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_SHIFT (1U)
/*! ALIGN_EN - Value from ASIC for rx_align_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_ALIGN_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_SHIFT (2U)
/*! CLK_SHIFT - Value from ASIC for rx_clk_shift */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_CLK_SHIFT_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_SHIFT (3U)
/*! DISABLE - Value from ASIC for rx_disable */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_MASK (0x70U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_SHIFT (4U)
/*! LOS_THRSHLD - Value from ASIC for rx_los_threshold */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_THRSHLD_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_SHIFT (7U)
/*! LOS_LPFS_EN - Value from ASIC for rx_los_lfps_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_LOS_LPFS_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_SHIFT (8U)
/*! RX_TERM_EN - Value from ASIC for rx_term_en */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_EN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_SHIFT (9U)
/*! RX_TERM_ACDC - Value from ASIC for rx_term_acdc */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RX_TERM_ACDC_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_IN_1_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0 - Current values for incoming RX EQ controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Value from ASIC for rx_eq_att_lvl */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_ATT_LVL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_AFE_GAIN_MASK (0x78U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_AFE_GAIN_SHIFT (3U)
/*! EQ_AFE_GAIN - Value from ASIC for rx_eq_afe_gain */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_AFE_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_AFE_GAIN_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_AFE_GAIN_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_RESERVED_MASK (0x780U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_RESERVED_SHIFT (7U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_MASK (0xF800U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_SHIFT (11U)
/*! EQ_CTLE_BOOST - Value from ASIC for rx_eq_ctle_boost */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_0_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1 - Current values for incoming RX EQ controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP2_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP2_SHIFT (0U)
/*! EQ_DFE_TAP2 - Value from ASIC for rx_eq_dfe_tap2 */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP2_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP2_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_MASK (0x7F80U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_SHIFT (7U)
/*! EQ_DFE_TAP1 - Value from ASIC for rx_eq_dfe_tap1 */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_EQ_DFE_TAP1_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_EQ_ASIC_IN_1_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0 - Current values for incoming RX CDR VCO controls from ASIC, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_LOWFREQ_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_LOWFREQ_SHIFT (0U)
/*! RX_CDR_VCO_LOWFREQ - Value from ASIC for rx_cdr_vco_lowfreq */
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_LOWFREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_LOWFREQ_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_CDR_VCO_LOWFREQ_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_MASK (0xFEU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_SHIFT (1U)
/*! RX_REF_LD_VAL - Value from ASIC for rx_ref_ld_val */
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RX_REF_LD_VAL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_0_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1 - Current values for incoming RX CDR VCO controls from ASIC, register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_SHIFT (0U)
/*! RX_VCO_LD_VAL - Value from ASIC for rx_vco_ld_val */
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RX_VCO_LD_VAL_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_CDR_VCO_ASIC_IN_1_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_ASIC_RX_ASIC_OUT_0 - Current values for outgoing RX status controls from PHY, register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_SHIFT (0U)
/*! ACK - Value from PHY for rx_ack */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_SHIFT (1U)
/*! LOS - Value from PHY for rx_los */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_LOS_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_SHIFT (2U)
/*! VALID - Value from PHY for rx_valid */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_VALID_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_MASK (0x18U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_SHIFT (3U)
/*! ADAPT_STS - Value from PHY for rx_adapt_sts */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_ADAPT_STS_MASK)

#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_RESERVED_15_5_SHIFT)) & PHY_ENET_LANE0_DIG_ASIC_RX_ASIC_OUT_0_RESERVED_15_5_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0 - TX Power State Control Register for P0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P0_ANA_REFGEN_EN - Value of TX ana refgen_en in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_REFGEN_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P0_ANA_VCM_HOLD - Value of TX ana vcm_hold in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_VCM_HOLD_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_SHIFT (2U)
/*! TX_P0_ANA_CLK_EN - Value of TX ana clk_en in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P0_ANA_WORD_CLK_EN - Value of TX ana word_clk_en in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_SHIFT (4U)
/*! TX_P0_ANA_RESET - Value of TX ana reset in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_RESET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P0_ANA_SERIAL_EN - Value of TX ana serial_en in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ANA_SERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_SHIFT (6U)
/*! TX_P0_DIG_CLK_EN - Enable/Disable TX digital clocks in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_SHIFT (7U)
/*! TX_P0_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_SHIFT (8U)
/*! TX_P0_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_TX_P0_ALLOW_RXDET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S - TX Power State Control Register for P0S */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P0S_ANA_REFGEN_EN - Value of TX ana refgen_en in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_REFGEN_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P0S_ANA_VCM_HOLD - Value of TX ana vcm_hold in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_VCM_HOLD_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_SHIFT (2U)
/*! TX_P0S_ANA_CLK_EN - Value of TX ana clk_en in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P0S_ANA_WORD_CLK_EN - Value of TX ana word_clk_en in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_SHIFT (4U)
/*! TX_P0S_ANA_RESET - Value of TX ana reset in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_RESET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P0S_ANA_SERIAL_EN - Value of TX ana serial_en in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ANA_SERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_SHIFT (6U)
/*! TX_P0S_DIG_CLK_EN - Enable/Disable TX digital clocks in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_SHIFT (7U)
/*! TX_P0S_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_SHIFT (8U)
/*! TX_P0S_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0S */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_TX_P0S_ALLOW_RXDET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P0S_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1 - TX Power State Control Register for P1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P1_ANA_REFGEN_EN - Value of TX ana refgen_en in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_REFGEN_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P1_ANA_VCM_HOLD - Value of TX ana vcm_hold in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_VCM_HOLD_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_SHIFT (2U)
/*! TX_P1_ANA_CLK_EN - Value of TX ana clk_en in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P1_ANA_WORD_CLK_EN - Value of TX ana word_clk_en in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_SHIFT (4U)
/*! TX_P1_ANA_RESET - Value of TX ana reset in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_RESET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P1_ANA_SERIAL_EN - Value of TX ana serial_en in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ANA_SERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_SHIFT (6U)
/*! TX_P1_DIG_CLK_EN - Enable/Disable TX digital clocks in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_SHIFT (7U)
/*! TX_P1_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_SHIFT (8U)
/*! TX_P1_ALLOW_RXDET - If asserted, then rxdet request is allowed in P1 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_TX_P1_ALLOW_RXDET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P1_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2 - TX Power State Control Register for P2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_SHIFT (0U)
/*! TX_P2_ANA_REFGEN_EN - Value of TX ana refgen_en in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_REFGEN_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_SHIFT (1U)
/*! TX_P2_ANA_VCM_HOLD - Value of TX ana vcm_hold in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_VCM_HOLD_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_SHIFT (2U)
/*! TX_P2_ANA_CLK_EN - Value of TX ana clk_en in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_SHIFT (3U)
/*! TX_P2_ANA_WORD_CLK_EN - Value of TX ana word_clk_en in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_SHIFT (4U)
/*! TX_P2_ANA_RESET - Value of TX ana reset in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_RESET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_SHIFT (5U)
/*! TX_P2_ANA_SERIAL_EN - Value of TX ana serial_en in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ANA_SERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_SHIFT (6U)
/*! TX_P2_DIG_CLK_EN - Enable/Disable TX digital clocks in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_SHIFT (7U)
/*! TX_P2_DATA_EN - This is ANDed with top-level tx_data_en asic input */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_SHIFT (8U)
/*! TX_P2_ALLOW_RXDET - If asserted, then rxdet request is allowed */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_RXDET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_VBOOST_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_VBOOST_SHIFT (9U)
/*! TX_P2_ALLOW_VBOOST - If asserted, then vboost is allowed in P2 */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_VBOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_VBOOST_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_TX_P2_ALLOW_VBOOST_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PSTATE_P2_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0 - TX Power UP Time Register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_SHIFT (0U)
/*! TX_REFGEN_EN_TIME - Power up time (in ref_range cycles) for TX ana refgen enable (spec: >=500ns) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_REFGEN_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_SHIFT (8U)
/*! TX_CLK_EN - Power up time (in ref_range cycles) for TX ana clock enable (spec: >=1us) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_0_TX_CLK_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1 - TX Power UP Time Register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_14_0_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_14_0_SHIFT (0U)
/*! TX_VCM_HOLD_TIME_14_0 - Power up time (in ref_range cycles) for TX common mode (spec: >=800us) (bits 14:0) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_14_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_14_0_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_TX_VCM_HOLD_TIME_14_0_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_SHIFT (15U)
/*! SKIP_TX_VCM_HOLD_WAIT - Skip wait for TX common mode hold power up */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_1_SKIP_TX_VCM_HOLD_WAIT_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2 - TX Power UP Time Register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_12_0_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_12_0_SHIFT (0U)
/*! TX_VBOOST_DIS_TIME_12_0 - TX vboost disable time (in ref_range cycles) (spec: >=200us) (bits 12:0) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_12_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_12_0_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_TX_VBOOST_DIS_TIME_12_0_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_SHIFT (13U)
/*! DTB_SEL - Selects data to drive on DTB */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_2_DTB_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3 - TX Power UP Time Register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VCM_HOLD_TIME_17_15_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VCM_HOLD_TIME_17_15_SHIFT (0U)
/*! TX_VCM_HOLD_TIME_17_15 - Power up time (in ref_range cycles) for TX common mode (spec: >=800us) (bits 17:15) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VCM_HOLD_TIME_17_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VCM_HOLD_TIME_17_15_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VCM_HOLD_TIME_17_15_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VBOOST_DIS_TIME_13_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VBOOST_DIS_TIME_13_SHIFT (3U)
/*! TX_VBOOST_DIS_TIME_13 - TX vboost disable time (in ref_range cycles) (spec: >=200us) (bit 13) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VBOOST_DIS_TIME_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VBOOST_DIS_TIME_13_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_TX_VBOOST_DIS_TIME_13_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_RESERVED_15_4_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_3_RESERVED_15_4_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4 - TX Power UP Time Register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_VCM_HOLD_GS_TIME_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_VCM_HOLD_GS_TIME_SHIFT (0U)
/*! TX_VCM_HOLD_GS_TIME - TX common mode gear-shift time (in ref range cycles) (spec: >=400us) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_VCM_HOLD_GS_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_VCM_HOLD_GS_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_TX_VCM_HOLD_GS_TIME_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_4_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5 - TX Power UP Time Register #5 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RXDET_TIME_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RXDET_TIME_SHIFT (0U)
/*! TX_RXDET_TIME - RX Detect up time (in ref_range cycles), starting from asserting rxdet_en (spec: from 3. */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RXDET_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RXDET_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RXDET_TIME_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_FAST_TX_RXDET_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_FAST_TX_RXDET_SHIFT (10U)
/*! FAST_TX_RXDET - Enable fast TX RX-detection (simulation only) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_FAST_TX_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_FAST_TX_RXDET_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_FAST_TX_RXDET_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RESET_TIME_MASK (0x1800U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RESET_TIME_SHIFT (11U)
/*! TX_RESET_TIME - TX Reset deassertion time (in ref_range cycles) (spec: >=50ns) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RESET_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RESET_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_RESET_TIME_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_SERIAL_EN_TIME_MASK (0x6000U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_SERIAL_EN_TIME_SHIFT (13U)
/*! TX_SERIAL_EN_TIME - Power up time (in ref_range cycles) for TX ana serial enable (spec: >=50ns) */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_SERIAL_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_SERIAL_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_TX_SERIAL_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_TX_PWRCTL_TX_PWRUP_TIME_5_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_LBERT_CTL - Pattern Generator controls */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_MODE_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_MODE_SHIFT (0U)
/*! MODE - Pattern to generate When changing modes, you must change to disabled first */
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_MODE(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_LBERT_CTL_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_TX_LBERT_CTL_MODE_MASK)

#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_SHIFT (4U)
/*! TRIGGER_ERR - Insert a single error into a lsb Any write of a 1 to this bit will insert an error */
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_SHIFT)) & PHY_ENET_LANE0_DIG_TX_LBERT_CTL_TRIGGER_ERR_MASK)

#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_PAT0_MASK (0x7FE0U)
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_PAT0_SHIFT (5U)
/*! PAT0 - Pattern for modes 3-5 */
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_PAT0(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_LBERT_CTL_PAT0_SHIFT)) & PHY_ENET_LANE0_DIG_TX_LBERT_CTL_PAT0_MASK)

#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_LBERT_CTL_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_LBERT_CTL_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_TX_LBERT_CTL_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0 - TX Clock Alignment Control Register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_16B_MODE_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_16B_MODE_SHIFT (0U)
/*! TX_NUM_2UI_SHIFTS_16B_MODE - TX_NUM_2UI_SHIFTS_16B_MODE */
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_16B_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_16B_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_16B_MODE_MASK)

#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_20B_MODE_MASK (0xF0U)
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_20B_MODE_SHIFT (4U)
/*! TX_NUM_2UI_SHIFTS_20B_MODE - TX_NUM_2UI_SHIFTS_20B_MODE */
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_20B_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_20B_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_NUM_2UI_SHIFTS_20B_MODE_MASK)

#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_FIFO_BYPASS_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_FIFO_BYPASS_SHIFT (8U)
/*! TX_FIFO_BYPASS - By-pass TX datapath FIFO */
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_FIFO_BYPASS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_FIFO_BYPASS_SHIFT)) & PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_TX_FIFO_BYPASS_MASK)

#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_TX_CLK_ALIGN_TX_CTL_0_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0 - RX Power State Control Register for P0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_SHIFT (0U)
/*! RX_P0_ANA_LOS_EN - Value of RX ana los_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_LOS_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_SHIFT (1U)
/*! RX_P0_ANA_AFE_EN - Value of RX ana afe_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P0_ANA_CLK_VREG_EN - Value of RX ana clk_vreg_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_SHIFT (3U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_SHIFT (4U)
/*! RX_P0_ANA_CLK_EN - Value of RX ana clk_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P0_ANA_CLK_DCC_EN - Value of RX ana CLK_DCC_EN in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CLK_DCC_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_SHIFT (6U)
/*! RX_P0_ANA_DESER_EN - Value of RX ana deserial_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_DESER_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_SHIFT (7U)
/*! RX_P0_ANA_CDR_EN - Value of RX ana cdr_en in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_ANA_CDR_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P0_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_SHIFT (9U)
/*! RX_P0_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P0_VCO_CONTCAL_EN - Enable/Disable continous calibration of the RX VCO in P0 If
 *    RX_P0_DIG_CLK_EN and the top-level rx_data_en are both asserted, then contiuous calibration is turned off
 *    and this value is ignored
 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_SHIFT (11U)
/*! RX_P0_DIG_CLK_EN - Enable/Disable RX digital clocks in P0 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RX_P0_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S - RX Power State Control Register for P0S */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_SHIFT (0U)
/*! RX_P0S_ANA_LOS_EN - Value of RX ana los_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_LOS_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_SHIFT (1U)
/*! RX_P0S_ANA_AFE_EN - Value of RX ana afe_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P0S_ANA_CLK_VREG_EN - Value of RX ana clk_vreg_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_SHIFT (3U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_SHIFT (4U)
/*! RX_P0S_ANA_CLK_EN - Value of RX ana clk_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P0S_ANA_CLK_DCC_EN - Value of RX ana CLK_DCC_EN in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CLK_DCC_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_SHIFT (6U)
/*! RX_P0S_ANA_DESER_EN - Value of RX ana deserial_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_DESER_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_SHIFT (7U)
/*! RX_P0S_ANA_CDR_EN - Value of RX ana cdr_en in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_ANA_CDR_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P0S_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_SHIFT (9U)
/*! RX_P0S_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P0S_VCO_CONTCAL_EN - Enable/Disable continous calibration of the RX VCO in P0S If
 *    RX_P0S_DIG_CLK_EN and the top-level rx_data_en are both asserted, then contiuous calibration is turned
 *    off and this value is ignored
 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_SHIFT (11U)
/*! RX_P0S_DIG_CLK_EN - Enable/Disable RX digital clocks in P0S */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RX_P0S_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P0S_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1 - RX Power State Control Register for P1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_SHIFT (0U)
/*! RX_P1_ANA_LOS_EN - Value of RX ana los_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_LOS_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_SHIFT (1U)
/*! RX_P1_ANA_AFE_EN - Value of RX ana afe_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P1_ANA_CLK_VREG_EN - Value of RX ana clk_vreg_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_SHIFT (3U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_SHIFT (4U)
/*! RX_P1_ANA_CLK_EN - Value of RX ana clk_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P1_ANA_CLK_DCC_EN - Value of RX ana CLK_DCC_EN in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CLK_DCC_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_SHIFT (6U)
/*! RX_P1_ANA_DESER_EN - Value of RX ana deserial_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_DESER_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_SHIFT (7U)
/*! RX_P1_ANA_CDR_EN - Value of RX ana cdr_en in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_ANA_CDR_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P1_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_SHIFT (9U)
/*! RX_P1_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P1_VCO_CONTCAL_EN - Enable/Disable continous calibration of the RX VCO in P1 If
 *    RX_P1_DIG_CLK_EN and the top-level rx_data_en are both asserted, then contiuous calibration is turned off
 *    and this value is ignored
 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_SHIFT (11U)
/*! RX_P1_DIG_CLK_EN - Enable/Disable RX digital clocks in P1 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RX_P1_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P1_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2 - RX Power State Control Register for P2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_SHIFT (0U)
/*! RX_P2_ANA_LOS_EN - Value of RX ana los_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_LOS_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_SHIFT (1U)
/*! RX_P2_ANA_AFE_EN - Value of RX ana afe_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_P2_ANA_CLK_VREG_EN - Value of RX ana clk_vreg_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_SHIFT (3U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_SHIFT (4U)
/*! RX_P2_ANA_CLK_EN - Value of RX ana clk_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_SHIFT (5U)
/*! RX_P2_ANA_CLK_DCC_EN - Value of RX ana CLK_DCC_EN in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CLK_DCC_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_SHIFT (6U)
/*! RX_P2_ANA_DESER_EN - Value of RX ana deserial_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_DESER_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_SHIFT (7U)
/*! RX_P2_ANA_CDR_EN - Value of RX ana cdr_en in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_ANA_CDR_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_SHIFT (8U)
/*! RX_P2_VCO_FREQ_RST - Enable/Disable resetting the RX VCO frequency in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_SHIFT (9U)
/*! RX_P2_VCO_CAL_RST - Enable/Disable resetting the RX VCO in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_SHIFT (10U)
/*! RX_P2_VCO_CONTCAL_EN - Enable/Disable continous calibration of the RX VCO in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_SHIFT (11U)
/*! RX_P2_DIG_CLK_EN - Enable/Disable RX digital clocks in P2 */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RX_P2_DIG_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PSTATE_P2_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0 - RX Power UP Time Register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_MASK (0x1FFU)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_SHIFT (0U)
/*! RX_LOS_EN_TIME - Power up time (in ref_range cycles) for RX ana los enable (spec >=10us) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RX_LOS_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_SKIP_RX_LOS_EN_WAIT_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_SKIP_RX_LOS_EN_WAIT_SHIFT (9U)
/*! SKIP_RX_LOS_EN_WAIT - Skip wait for RX LOS enable */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_SKIP_RX_LOS_EN_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_SKIP_RX_LOS_EN_WAIT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_SKIP_RX_LOS_EN_WAIT_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_0_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1 - RX Power UP Time Register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_AFE_EN_TIME_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_AFE_EN_TIME_SHIFT (0U)
/*! RX_AFE_EN_TIME - Power up time (in ref_range cycles) for RX ana AFE enable (spec >=1us) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_AFE_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_AFE_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_AFE_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_AFE_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_AFE_EN_SHIFT (6U)
/*! FAST_RX_AFE_EN - Enable fast RX AFE enable (simulation only) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_MASK (0x1F80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_SHIFT (7U)
/*! RX_VREG_EN_TIME - Power up time (in ref_range cycles) for RX ana vreg enable (spec 500ns) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RX_VREG_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_VREG_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_VREG_EN_SHIFT (13U)
/*! FAST_RX_VREG_EN - Enable fast RX VREG enable (simulation only) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_FAST_RX_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_1_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2 - RX Power UP Time Register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CLK_EN_TIME_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CLK_EN_TIME_SHIFT (0U)
/*! RX_CLK_EN_TIME - Power up time (in ref_range cycles) for RX ana clk (or dcc) enable (spec >1us) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CLK_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CLK_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RX_CLK_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_FAST_RX_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_FAST_RX_CLK_EN_SHIFT (6U)
/*! FAST_RX_CLK_EN - Enable fast RX clock enable (simulation only) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_FAST_RX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_FAST_RX_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_FAST_RX_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RESERVED_15_7_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_2_RESERVED_15_7_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3 - RX Power UP Time Register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_RATE_TIME_MASK (0x3U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_RATE_TIME_SHIFT (0U)
/*! RX_RATE_TIME - Power up time (in ref_range cycles) for RX ana rate or width change */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_RATE_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_RATE_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_RATE_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RSVD_3_7_2_MASK (0xFCU)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RSVD_3_7_2_SHIFT (2U)
/*! RSVD_3_7_2 - Reserved */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RSVD_3_7_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RSVD_3_7_2_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RSVD_3_7_2_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CDR_EN_TIME_MASK (0xF00U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CDR_EN_TIME_SHIFT (8U)
/*! RX_CDR_EN_TIME - Power up time (in ref_range cycles) for RX ana cdr (or dfe/dfe_taps) enable (spec 0ns) */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CDR_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CDR_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_CDR_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_EN_TIME_MASK (0x3000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_EN_TIME_SHIFT (12U)
/*! RX_DESER_EN_TIME - Power up time (in ref_range cycles) for RX ana deserial enable */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_EN_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_EN_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_EN_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_DIS_TIME_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_DIS_TIME_SHIFT (14U)
/*! RX_DESER_DIS_TIME - Power down time in (ref_range cycles) for RX ana deserial enable */
#define PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_DIS_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_DIS_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_PWRCTL_RX_PWRUP_TIME_3_RX_DESER_DIS_TIME_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0 - RX VCO calibration controls register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_SHIFT (0U)
/*! INT_GAIN_CAL_FIXED_CNT - Number of steps done during int_gain code calibration when INT_GAIN_CAL_FIXED_CNT_EN is enabled. */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_EN_SHIFT (5U)
/*! INT_GAIN_CAL_FIXED_CNT_EN - Enable a fixed count (instead of bounce count) for int_gain code calibration */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_FIXED_CNT_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_CNT_SHIFT_MASK (0x1C0U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_CNT_SHIFT_SHIFT (6U)
/*! INT_GAIN_CAL_CNT_SHIFT - Number of shifts to apply to ld_cnt inputs when performing int_gain code calibration */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_CNT_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_CNT_SHIFT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_CNT_SHIFT_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_MASK (0xE00U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_SHIFT (9U)
/*! INT_GAIN_CAL_BOUNCE_CNT - Number of bounces (i. */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_INT_GAIN_CAL_BOUNCE_CNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_0_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1 - RX VCO calibration controls register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_SHIFT (0U)
/*! RX_VCO_OVRD_SEL - Override the calibration controls from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_OVRD_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_SHIFT (1U)
/*! RX_VCO_FREQ_RST - Override value for the frequency reset from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_SHIFT (2U)
/*! RX_VCO_CAL_RST - Override value for the calibration reset from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_SHIFT (3U)
/*! RX_VCO_CONTCAL_EN - Override value for the continous calibration enable from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_RX_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_SHIFT (4U)
/*! DISABLE_INT_CAL_MODE - When asserted, then the DPLL frequency register is never modified by the
 *    RX VCO calibration FSM (even if DPLL_CAL_UG is non-zero).
 */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DISABLE_INT_CAL_MODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_MASK (0x1E0U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_SHIFT (5U)
/*! DPLL_CAL_UG - DPLL calibration update on int_gain code */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DPLL_CAL_UG_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_SHIFT (9U)
/*! DTB_SEL - DTB select for RX VCO dtb signals */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_1_DTB_SEL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2 - RX VCO calibration controls register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_START_VAL_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_START_VAL_SHIFT (0U)
/*! FREQ_TUNE_START_VAL - Starting value of freq tune code */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_START_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_START_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_START_VAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_CAL_STEPS_MASK (0x3C00U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_CAL_STEPS_SHIFT (10U)
/*! FREQ_TUNE_CAL_STEPS - Number of cal steps of freq tune */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_CAL_STEPS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_CAL_STEPS_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_FREQ_TUNE_CAL_STEPS_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_FREQ_TUNE_CAL_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_FREQ_TUNE_CAL_SHIFT (14U)
/*! SKIP_RX_VCO_FREQ_TUNE_CAL - Skip RX VCO coarse calibration */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_FREQ_TUNE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_FREQ_TUNE_CAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_FREQ_TUNE_CAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_CAL_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_CAL_SHIFT (15U)
/*! SKIP_RX_VCO_CAL - Skip RX VCO calibration altogether */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_CAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_CTRL_2_SKIP_RX_VCO_CAL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0 - RX Power UP Time Register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_STARTUP_TIME_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_STARTUP_TIME_SHIFT (0U)
/*! RX_VCO_STARTUP_TIME - Power up time (in ref_range cycles) for RX ana vco startup (spec >1us) */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_STARTUP_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_STARTUP_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_STARTUP_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_MASK (0x780U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_SHIFT (7U)
/*! RX_VCO_UPDATE_TIME - Settle time (in ref_range cycles) for RX ana vco update (freq_tune or int_gain) (spec >200ns) */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_UPDATE_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_MASK (0x7800U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_SHIFT (11U)
/*! RX_VCO_CNTR_PWRUP_TIME - Power up time (in ref_range cycles) for Rx ana vco cnter (spec >200ns) */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_RX_VCO_CNTR_PWRUP_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_SHIFT (15U)
/*! FAST_RX_VCO_WAIT - Enable fast RX VCO power up (simulation only) */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_0_FAST_RX_VCO_WAIT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1 - RX Power UP Time Register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_SHIFT (0U)
/*! RX_VCO_CNTR_SETTLE_TIME - RX VCO counter value settling time in (ref_dig_clk cycles) (spec: 3 ref_dig_clk cycle) */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RX_VCO_CNTR_SETTLE_TIME_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RESERVED_15_3_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_CAL_TIME_1_RESERVED_15_3_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0 - RX VCO status register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT (0U)
/*! RX_ANA_CDR_FREQ_TUNE - Current value of rx_ana_cdr_freq_tune_i */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_FREQ_TUNE_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_SHIFT (10U)
/*! RX_ANA_VCO_CNTR_PD - Current value of rx_ana_vco_cntr_pd_i */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_PD_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_SHIFT (11U)
/*! RX_ANA_VCO_CNTR_EN - Current value of rx_ana_vco_cntr_en_i */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_VCO_CNTR_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_SHIFT (12U)
/*! RX_ANA_CDR_STARTUP - Current value of rx_ana_cdr_startup_i */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_STARTUP_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_SHIFT (13U)
/*! RX_ANA_CDR_VCO_EN - Current value of rx_ana_cdr_vco_en_i */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RX_ANA_CDR_VCO_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_0_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1 - RX VCO status register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_SHIFT (0U)
/*! RX_VCO_FSM_STATE - Value of the RX VCO CAL FSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FSM_STATE_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_SHIFT (4U)
/*! RX_VCO_FREQ_RST - Value of the RX VCO frequency reset from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_SHIFT (5U)
/*! RX_VCO_CAL_RST - Value of the calibration reset from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_SHIFT (6U)
/*! RX_VCO_CONTCAL_EN - Value of the continous calibration enable from the RX PWRSM */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CONTCAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_SHIFT (7U)
/*! RX_VCO_CAL_DONE - Indicates that the RX VCO has completed calibration */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RX_VCO_CAL_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_SHIFT (8U)
/*! DPLL_FREQ_RST - Indicates that the RX integral frequency is reset or not */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_DPLL_FREQ_RST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_1_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2 - RX VCO status register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_SHIFT (0U)
/*! VCO_CNTR_FINAL - Value of Rx VCO counter when refclk counter expired */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCO_CNTR_FINAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_SHIFT (13U)
/*! VCOCLK_TOO_FAST - Indicates that the RX VCO clock frequency is too fast */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_VCOCLK_TOO_FAST_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_SHIFT (14U)
/*! RX_VCO_CORRECT - Indicates that the RX VCO clock has the correct frequency */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_CORRECT_MASK)

#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_SHIFT (15U)
/*! RX_VCO_UP - Indicates that the RX VCO is ready */
#define PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_SHIFT)) & PHY_ENET_LANE0_DIG_RX_VCOCAL_RX_VCO_STAT_2_RX_VCO_UP_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK - XAUI_COMMA Mask */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_XAUI_COMM_MASK_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_XAUI_COMM_MASK_SHIFT (0U)
/*! XAUI_COMM_MASK - XAUI_COMMA Mask. */
#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_XAUI_COMM_MASK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_XAUI_COMM_MASK_SHIFT)) & PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_XAUI_COMM_MASK_MASK)

#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_RX_RX_ALIGN_XAUI_COMM_MASK_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_LBERT_CTL - Pattern Matcher controls */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_MODE_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_MODE_SHIFT (0U)
/*! MODE - Pattern to match When changing modes, you must change to disabled first */
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_MODE(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_LBERT_CTL_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_LBERT_CTL_MODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_SYNC_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_SYNC_SHIFT (4U)
/*! SYNC - Synchronize pattern matcher LFSR with incoming data A write of a one to this bit will
 *    reset the error counter and start a synchronization of the PM
 */
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_SYNC(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_LBERT_CTL_SYNC_SHIFT)) & PHY_ENET_LANE0_DIG_RX_LBERT_CTL_SYNC_MASK)

#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_LBERT_CTL_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_LBERT_CTL_RESERVED_15_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_LBERT_CTL_RESERVED_15_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_LBERT_ERR - Pattern match error counter */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_COUNT_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_COUNT_SHIFT (0U)
/*! COUNT - A read of this register, or a sync of the PM resets the error count. */
#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_COUNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_LBERT_ERR_COUNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_LBERT_ERR_COUNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_OV14_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_OV14_SHIFT (15U)
/*! OV14 - If active, multiply COUNT by 128. */
#define PHY_ENET_LANE0_DIG_RX_LBERT_ERR_OV14(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_LBERT_ERR_OV14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_LBERT_ERR_OV14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_0 - Control bits for receiver in recovered domain */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_MASK (0x3U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_SHIFT (0U)
/*! PHDET_EN - Enable phase detector. */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_MASK (0xCU)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_SHIFT (2U)
/*! PHDET_EDGE - Edges to use for phase detection. */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EDGE_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_SHIFT (4U)
/*! PHDET_POL - Reverse polarity of phase error */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_POL_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_SHIFT (5U)
/*! PHDET_EN_PR_MODE - Enable partial response phase detector mode */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_PHDET_EN_PR_MODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_SHIFT (6U)
/*! ALWAYS_REALIGN - Realign on any misaligned comma */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_ALWAYS_REALIGN_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_MASK (0x780U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_SHIFT (7U)
/*! DTB_SEL - Select to drive various signals onto the dtb */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_DTB_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_RESERVED_15_11_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_0_RESERVED_15_11_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_1 - CDR Control Register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_SHIFT (0U)
/*! SSC_OFF_CNT0 - When SSC mode is disabled, the 12-bit word count in gain stage 0 is: */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_SHIFT (10U)
/*! SSC_OFF_CNT1 - When SSC mode is disabled, the 12-bit word count in gain stage 1 is: */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_1_SSC_OFF_CNT1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_2 - CDR Control Register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_MASK (0x1FFU)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_SHIFT (0U)
/*! SSC_ON_CNT0 - When SSC mode is enabled, the 12-bit word count in gain stage 0 is: */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_SHIFT (9U)
/*! SSC_ON_CNT1 - When SSC mode is enabled, the 12-bit word count in gain stage 1 is: */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_2_SSC_ON_CNT1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_3 - CDR Control Register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_SHIFT (0U)
/*! SSC_OFF_PHUG0 - When SSC mode is disabled, the phug value in gain stage 0 is SSC_OFF_PHUG0 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_SHIFT (3U)
/*! SSC_OFF_PHUG1 - When SSC mode is disabled, the phug value in gain stage 1 is SSC_OFF_PHUG1 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_PHUG1_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_MASK (0x1C0U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_SHIFT (6U)
/*! SSC_OFF_FRUG0 - When SSC mode is disabled, the frug value in gain stage 0 is SSC_OFF_FRUG0 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_SSC_OFF_FRUG0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_SHIFT (9U)
/*! OVRD_DPLL_GAIN - Override PHUG and FRUG values */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_OVRD_DPLL_GAIN_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_MASK (0x1C00U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_SHIFT (10U)
/*! PHUG_OVRD_VALUE - Override value for PHUG (phase update gain) */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_PHUG_OVRD_VALUE_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_SHIFT (13U)
/*! FRUG_OVRD_VALUE - Override value for FRUG (frequency update gain) */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_3_FRUG_OVRD_VALUE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_CDR_CTL_4 - CDR Control Register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_SHIFT (0U)
/*! SSC_OFF_FRUG1 - When SSC mode is disabled, the frug value in gain stage 1 is SSC_OFF_FRUG1 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_OFF_FRUG1_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_SHIFT (3U)
/*! SSC_ON_FRUG0 - When SSC mode is enabled, the frug value in gain stage 0 is SSC_ON_FRUG0 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_MASK (0x1C0U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_SHIFT (6U)
/*! SSC_ON_FRUG1 - When SSC mode is enabled, the frug value in gain stage 1 is SSC_ON_FRUG1 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_FRUG1_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_MASK (0xE00U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_SHIFT (9U)
/*! SSC_ON_PHUG0 - When SSC mode is enabled, the phug value in gain stage 0 is SSC_ON_PHUG0 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG0_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_MASK (0x7000U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_SHIFT (12U)
/*! SSC_ON_PHUG1 - When SSC mode is enabled, the phug value in gain stage 1 is SSC_ON_PHUG1 */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_SSC_ON_PHUG1_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_CDR_CTL_4_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_CDR_STAT - Current output values to dpll (phug, frug) */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_SHIFT (0U)
/*! PHUG_VALUE - NOTES: Current value for dpll_phug[2:0] */
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_STAT_PHUG_VALUE_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_SHIFT (3U)
/*! FRUG_VALUE - NOTES: Current value for dpll_frug[2:0] */
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_STAT_FRUG_VALUE_MASK)

#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_CDR_STAT_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_CDR_STAT_RESERVED_15_6_SHIFT)) & PHY_ENET_LANE0_DIG_RX_CDR_STAT_RESERVED_15_6_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ - Current frequency integrator value. */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_VAL_MASK (0x3FFFU)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_VAL_SHIFT (0U)
/*! VAL - Freq is 125*VAL ppm from the reference (2 reads needed to read value) */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_VAL(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_VAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ_BOUND_0 - Frequency Bounds for incoming data stream #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_SHIFT (0U)
/*! FREQ_BOUND_EN - Enable the frequency bounds feature */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_FREQ_BOUND_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_MASK (0x7FEU)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_SHIFT (1U)
/*! UPPER_FREQ_BOUND - Upper frequency bound in terms of LSBs of the integral control code */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_UPPER_FREQ_BOUND_MASK)

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_RESERVED_15_11_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_0_RESERVED_15_11_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_DPLL_FREQ_BOUND_1 - Frequency Bounds for incoming data stream #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_SHIFT (0U)
/*! LOWER_FREQ_BOUND - Lower frequency bound in terms of LSBs of the integral control code */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_LOWER_FREQ_BOUND_MASK)

#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_RX_DPLL_FREQ_BOUND_1_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0 - Adaptation Configuration Register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_SHIFT (0U)
/*! N_TOP_ASM1 - Number of top level loop iterations for ASM1 */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TOP_ASM1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_MASK (0x3C00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_SHIFT (10U)
/*! N_TGG_ASM1 - Number of toggle loop iterations for ASM1 */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_N_TGG_ASM1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_SHIFT (14U)
/*! START_ASM1 - Start adaptation state machine #1 (VGA, CTLE, DFE, EYEH) This register-bit is self-clearing */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_START_ASM1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_SHIFT (15U)
/*! ADPT_CLK_DIV4_EN - Set the adaptation clock to be divided by 4 (default is div2) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_0_ADPT_CLK_DIV4_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1 - Adaptation Configuration Register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_SHIFT (0U)
/*! N_WAIT_ASM1 - Number of wait cycles for Adaptation SM #1 */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_N_WAIT_ASM1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_FAST_AFE_DFE_SETTLE_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_FAST_AFE_DFE_SETTLE_SHIFT (7U)
/*! FAST_AFE_DFE_SETTLE - Enable fast AFE and DFE settling time (simulation only) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_FAST_AFE_DFE_SETTLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_FAST_AFE_DFE_SETTLE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_FAST_AFE_DFE_SETTLE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_MASK (0x700U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_SHIFT (8U)
/*! CTLE_POLE_OVRD_VAL - CTLE Pole override value to load at start of adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_VAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_SHIFT (11U)
/*! CTLE_POLE_OVRD_EN - Override CTLE pole value (only valid if adaptation is run) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_CTLE_POLE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_1_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2 - Adaptation Configuration Register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_SHIFT (0U)
/*! TGG_PTTRN_0 - Pattern for the first toggle loop Error slicer is moved downward by Data tap1 if this pattern is matched */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_MASK (0x3E0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_SHIFT (5U)
/*! TGG_PTTRN_1 - Pattern for the second toggle loop Error slicer is moved upward by Data tap1 if this pattern is matched */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_TGG_PTTRN_1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_RESERVED_15_10_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_2_RESERVED_15_10_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3 - Adaptation Configuration Register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_SHIFT (0U)
/*! CTLE_EN - Enable CTLE boost adaptation The five bits determine which correlators are used to adapt the CTLE */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_CTLE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_SHIFT (5U)
/*! VGA_EN - Enable VGA adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_VGA_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_SHIFT (6U)
/*! ATT_EN - Enable ATT adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ATT_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_MASK (0xF80U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_SHIFT (7U)
/*! DFE_EN - Enable DFE adaptation for taps 5-1 */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_DFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_SHIFT (12U)
/*! EYEHE_EN - Enable eye height measurement using even error slicer */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_SHIFT (13U)
/*! EYEHO_EN - Enable eye height measurement using odd error slicer */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_EYEHO_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_SHIFT (14U)
/*! TGG_EN - Enable toggling of the error slicer */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_TGG_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_SHIFT (15U)
/*! ESL_TWICE_DSL - Assert if error slicer has twice the voltage range as the data slicer (for the same 8 bits). */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_3_ESL_TWICE_DSL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4 - Adaptation Configuration Register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_SHIFT (0U)
/*! CTLE_TH - CTLE correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_CTLE_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_MASK (0xF0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_SHIFT (4U)
/*! VGA_TH - VGA correlation decision threshold (2^N-1) During eye height measurement, the VGA_TH is
 *    repurporsed for error slicer updates
 */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_VGA_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_MASK (0xF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_SHIFT (8U)
/*! DFE1_TH - DFE Tap1 correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE1_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_SHIFT (12U)
/*! DFE2_TH - DFE Tap2 correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_4_DFE2_TH_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5 - Adaptation Configuration Register #5 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_SHIFT (0U)
/*! DFE3_TH - DFE Tap3 correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE3_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_MASK (0xF0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_SHIFT (4U)
/*! DFE4_TH - DFE Tap4 correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE4_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_MASK (0xF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_SHIFT (8U)
/*! DFE5_TH - DFE Tap5 correlation decision threshold (2^N-1) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_DFE5_TH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_SHIFT (12U)
/*! TH_OFFSET - Apply an offset to the decision threshold */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_5_TH_OFFSET_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6 - Adaptation Configuration Register #6 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_SHIFT (0U)
/*! CTLE_MU - CTLE Boost code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_CTLE_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_SHIFT (3U)
/*! VGA_MU - VGA gain code update gain (2^N) During eye height measurement, the VGA_MU is repurporsed for error slicer updates */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_MASK (0x1C0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_SHIFT (6U)
/*! ATT_MU - ATT gain code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_MASK (0xE00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_SHIFT (9U)
/*! VGA_SAT_CNT - VGA saturation count */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_SHIFT (12U)
/*! VGA_SAT_CNT_STICKY - If deasserted, then VGA saturation counts must be consecutive to change ATT */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_VGA_SAT_CNT_STICKY_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_SHIFT (13U)
/*! ATT_LOW_TH - ATT low threshold */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_6_ATT_LOW_TH_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7 - Adaptation Configuration Register #7 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_SHIFT (0U)
/*! VGA_MIN_SAT - VGA minimum saturation limit */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_MIN_SAT_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_MASK (0x3E0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_SHIFT (5U)
/*! VGA_LEV_HIGH - VGA level high saturation limit */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_HIGH_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_MASK (0x7C00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_SHIFT (10U)
/*! VGA_LEV_LOW - VGA level low saturation limit */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_VGA_LEV_LOW_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_7_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8 - Adaptation Configuration Register #8 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_SHIFT (0U)
/*! DFE1_MU - DFE tap1 code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE1_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_SHIFT (3U)
/*! DFE2_MU - DFE tap2 code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE2_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_MASK (0x1C0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_SHIFT (6U)
/*! DFE3_MU - DFE tap3 code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE3_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_MASK (0xE00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_SHIFT (9U)
/*! DFE4_MU - DFE tap4 code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE4_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_MASK (0x7000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_SHIFT (12U)
/*! DFE5_MU - DFE tap5 code update gain (2^N) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_DFE5_MU_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_8_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9 - Adaptation Configuration Register #9 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_SHIFT (0U)
/*! ERR_SLE_ADPT_INIT - The error even slicer is initialized to this value at the start of a new adaptation request. */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLE_ADPT_INIT_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_SHIFT (8U)
/*! ERR_SLO_ADPT_INIT - The error odd slicer is initialized to this value at the start of a new adaptation request. */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_CFG_9_ERR_SLO_ADPT_INIT_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG - Reset Adaptation Configuration Register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_SHIFT (0U)
/*! RST_ADPT_ATT - Reset ATT when turning off AFE adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_ATT_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_SHIFT (1U)
/*! RST_ADPT_VGA - Reset VGA when turning off AFE adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_VGA_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_SHIFT (2U)
/*! RST_ADPT_CTLE_BOOST - Reset CTLE Boost when turning off AFE adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_BOOST_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_SHIFT (3U)
/*! RST_ADPT_CTLE_POLE - Reset CTLE Pole when turning off AFE adaptation */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_CTLE_POLE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_SHIFT (4U)
/*! RST_ADPT_TAP1 - Reset Data Tap1 when turning off DFE adaptation (Taps 2-5 are always turned off when DFE adaptation is turned off) */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RST_ADPT_TAP1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RESERVED_15_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RST_ADPT_CFG_RESERVED_15_5_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ATT_STATUS - Value of ATT Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_SHIFT (0U)
/*! ATT_ADPT_CODE - Value of ATT adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ATT_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_SHIFT (8U)
/*! ASM1_DON - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_ASM1_DON_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ATT_STATUS_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_VGA_STATUS - Value of VGA Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_SHIFT (0U)
/*! VGA_ADPT_CODE - Value of VGA adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_VGA_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_SHIFT (10U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_RESERVED_15_11_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_VGA_STATUS_RESERVED_15_11_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_CTLE_STATUS - Value of CTLE Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_SHIFT (0U)
/*! CTLE_BOOST_ADPT_CODE - Value of CTLE Boost adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_BOOST_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_MASK (0x1C00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_SHIFT (10U)
/*! CTLE_POLE_ADPT_CODE - Value of CTLE Pole adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_CTLE_POLE_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_SHIFT (13U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_CTLE_STATUS_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS - Value of DFE Tap1 Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP1_ADPT_CODE - Value of DFE tap1 adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_DFE_TAP1_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_SHIFT (13U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP1_STATUS_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS - Value of DFE Tap2 Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_MASK (0xFFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP2_ADPT_CODE - Value of DFE tap2 adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_DFE_TAP2_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP2_STATUS_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS - Value of DFE Tap3 Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_MASK (0xFFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP3_ADPT_CODE - Value of DFE tap3 adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_DFE_TAP3_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP3_STATUS_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS - Value of DFE Tap4 Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_MASK (0xFFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP4_ADPT_CODE - Value of DFE tap4 adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_DFE_TAP4_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP4_STATUS_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS - Value of DFE Tap5 Adaptation code */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_MASK (0xFFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_SHIFT (0U)
/*! DFE_TAP5_ADPT_CODE - Value of DFE tap5 adaptation code */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_DFE_TAP5_ADPT_CODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_SHIFT (12U)
/*! ASM1_DONE - Asserts when Adaptation state machine #1 is done */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_ASM1_DONE_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_TAP5_STATUS_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST - Offset values for RX DFE Data Even vDAC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_DFE_DATA_EVEN_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_DFE_DATA_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_VDAC_OFST - Offset value for DFE Data Even vDAC */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_DFE_DATA_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_DFE_DATA_EVEN_VDAC_OFST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_DFE_DATA_EVEN_VDAC_OFST_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_EVEN_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST - Offset values for RX DFE Data Odd vDAC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_DFE_DATA_ODD_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_DFE_DATA_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_VDAC_OFST - Offset value for DFE Data Odd vDAC */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_DFE_DATA_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_DFE_DATA_ODD_VDAC_OFST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_DFE_DATA_ODD_VDAC_OFST_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_DATA_ODD_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN - Sets values for RX SLICER CTRL EVEN signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_E - Value for rx_ana_slicer_ctrl_e[3:0] */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RESERVED_15_4_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_EVEN_RESERVED_15_4_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD - Sets values for RX SLICER CTRL ODD signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_O - Value for rx_ana_slicer_ctrl_o[3:0] */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RESERVED_15_4_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_RX_SLICER_CTRL_ODD_RESERVED_15_4_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST - Offset values for RX DFE Error Even vDAC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_EVEN_VDAC_OFST - Offset value for DFE Error Even vDAC */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST - Offset values for RX DFE Error Odd vDAC */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_ODD_VDAC_OFST - Offset value for DFE Error Odd vDAC */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL - Value of Error Slicer Level */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_SHIFT (0U)
/*! E_SLO_LVL - Odd Error Slicer Level */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLO_LVL_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_SHIFT (8U)
/*! E_SLE_LVL - Even Error Slicer Level */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ERROR_SLICER_LEVEL_E_SLE_LVL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_ADPTCTL_ADPT_RESET - Adaptation reset register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_SHIFT (0U)
/*! RESET_ASM1 - Resets adaptation state machine (ASM1) as well as the stats capture block. */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESET_ASM1_MASK)

#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESERVED_15_1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_ADPTCTL_ADPT_RESET_RESERVED_15_1_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_LD_VAL_1 - Stat load value for the sample counter #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_SHIFT (0U)
/*! SC1_LD_VAL - Sample counter #1 load value */
#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_LD_VAL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_SHIFT (15U)
/*! SC1_START - Start sample counter #1 This is a self-clearing bit */
#define PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_LD_VAL_1_SC1_START_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_DATA_MSK - Stat data mask bits [15:0] */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_MASK (0xFFFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_SHIFT (0U)
/*! DATA_MSK_15_0 - Value of data_msk_r[15:0] */
#define PHY_ENET_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_DATA_MSK_DATA_MSK_15_0_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL0 - Stat match controls register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_SHIFT (0U)
/*! PTTRN_MSK_CR1A_4_0 - Value of pattern A mask for 1st correlator (bits 4:0) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_MSK_CR1A_4_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_MASK (0x3E0U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_SHIFT (5U)
/*! PTTRN_CR1A_4_0 - Value of pattern A for 1st correlator (bits 4:0) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_PTTRN_CR1A_4_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_MASK (0x3C00U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_SHIFT (10U)
/*! DATA_MSK_19_16 - Value of data_msk_r[19:16] */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_DATA_MSK_19_16_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_SHIFT (14U)
/*! SCOPE_DLY - # of clock cycle delays on scope_data_rx_clk An additional MSB is added in SCOPE_DLY_2 */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL0_SCOPE_DLY_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL1 - Stat match controls register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_SHIFT (0U)
/*! PTTRN_CR1B_EN - Enable pattern B matching for 1st correlator */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_MASK (0x3EU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_SHIFT (1U)
/*! PTTRN_MSK_CR1B_4_0 - Value of pattern B mask for 1st correlator (bits 4:0) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_MSK_CR1B_4_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_MASK (0x7C0U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_SHIFT (6U)
/*! PTTRN_CR1B_4_0 - Value of pattern B for 1st correlator (bits 4:0) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1B_4_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_SHIFT (11U)
/*! PTTRN_CR1A_ADPT_EN - Enable ORing of adapation pattern with pattern CR1A */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_PTTRN_CR1A_ADPT_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL1_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL0 - Stat controls register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_RESERVED_0_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_RESERVED_0_SHIFT (0U)
/*! RESERVED_0 - Reserved bit */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_RESERVED_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_RESERVED_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_RESERVED_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_SHIFT (1U)
/*! CORR_SHFT_SEL_VGA - Select shift for error going to VGA. */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_VGA_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_SHIFT (2U)
/*! CORR_SHFT_SEL - Select shift for phase. */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SHFT_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_MASK (0x18U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_SHIFT (3U)
/*! CORR_SRC_SEL - Select correlation input source */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_SRC_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_SHIFT (5U)
/*! CORR_MODE_EN - Enable correlation mode */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_CORR_MODE_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_MASK (0x3C0U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_SHIFT (6U)
/*! STAT_SHFT_SEL - Select stat source shift value */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SHFT_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_MASK (0x1C00U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_SHIFT (10U)
/*! STAT_SRC_SEL - Select stat source input */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_SRC_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_SHIFT (13U)
/*! STAT_RXCLK_SEL - Select stat clock */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_STAT_RXCLK_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_SHIFT (14U)
/*! SC_TIMER_MODE - Sample counter operation mode 0x0 - counts number of matched samples */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SC_TIMER_MODE_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_SHIFT (15U)
/*! SKIP_EN - Value of skip_en_r */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL0_SKIP_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL1 - Stat controls register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_SHIFT (0U)
/*! STAT_CNT_0_EN - Enable for stat counter 0 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_0_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_SHIFT (1U)
/*! STAT_CNT_1_EN - Enable for stat counter 1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_1_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_SHIFT (2U)
/*! STAT_CNT_2_EN - Enable for stat counter 2 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_2_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_SHIFT (3U)
/*! STAT_CNT_3_EN - Enable for stat counter 3 Only counter to be enabled by default, since used for offset calibration */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_3_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_SHIFT (4U)
/*! STAT_CNT_4_EN - Enable for stat counter 4 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_4_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_SHIFT (5U)
/*! STAT_CNT_5_EN - Enable for stat counter 5 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_5_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_SHIFT (6U)
/*! STAT_CNT_6_EN - Enable for stat counter 6 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CNT_6_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_RESERVED_8_7_MASK (0x180U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_RESERVED_8_7_SHIFT (7U)
/*! RESERVED_8_7 - Reserved bits */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_RESERVED_8_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_RESERVED_8_7_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_RESERVED_8_7_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_SHIFT (9U)
/*! SC_PAUSE - Pause the sample counter and stat counters */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_SC_PAUSE_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_SHIFT (10U)
/*! STAT_CLK_EN - Clock gate enable for stat clock */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_STAT_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_MASK (0x1800U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_SHIFT (11U)
/*! DATA_DLY_SEL - # of clock cycle delays on rx_data[19:0] An additional MSB is added in DATA_DLY_SEL_2 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_DATA_DLY_SEL_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_SHIFT (13U)
/*! VLD_LOSS_CLR - Clearing of stats collection upon loss of valid */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_LOSS_CLR_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_SHIFT (14U)
/*! VLD_CTL - Gating configuration of stats collection */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL1_VLD_CTL_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_SMPL_CNT1 - Sample Counter #1 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_SHIFT (0U)
/*! SMPL_CNT1 - Current value of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_SMPL_CNT1_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_0 - Stat Counter 0 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_SHIFT (0U)
/*! STAT_CNT_0 - Current value of stat counter #0 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_STAT_CNT_0_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_0_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_1 - Stat Counter 1 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_SHIFT (0U)
/*! STAT_CNT_1 - Current value of stat counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_STAT_CNT_1_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_1_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_2 - Stat Counter 2 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_SHIFT (0U)
/*! STAT_CNT_2 - Current value of stat counter #2 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_STAT_CNT_2_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_2_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_3 - Stat Counter 3 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_SHIFT (0U)
/*! STAT_CNT_3 - Current value of stat counter #3 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_STAT_CNT_3_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_3_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_4 - Stat Counter 4 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_SHIFT (0U)
/*! STAT_CNT_4 - Current value of stat counter #4 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_STAT_CNT_4_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_4_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_5 - Stat Counter 5 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_SHIFT (0U)
/*! STAT_CNT_5 - Current value of stat counter #5 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_STAT_CNT_5_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_5_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CNT_6 - Stat Counter 6 Status */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_SHIFT (0U)
/*! STAT_CNT_6 - Current value of stat counter #6 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_STAT_CNT_6_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_SHIFT (15U)
/*! SMPL_CNT1_DONE - Status of sample counter #1 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CNT_6_SMPL_CNT1_DONE_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL - Calibration Comparator Control */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_SHIFT (0U)
/*! PRECHRGE_CNT - Precharge Count (e. */
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_PRECHRGE_CNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_MASK (0x38U)
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_SHIFT (3U)
/*! REF_DIV_CNT - Ref range clock count (e. */
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_REF_DIV_CNT_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_RESERVED_15_6_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_CAL_COMP_CLK_CTL_RESERVED_15_6_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL2 - Stat match controls register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_SHIFT (0U)
/*! PTTRN_CR1A_19_5 - Value of pattern A for 1st correlator (bits 19:5) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_PTTRN_CR1A_19_5_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL2_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL3 - Stat match controls register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_SHIFT (0U)
/*! PTTRN_MSK_CR1A_19_5 - Value of pattern A mask for 1st correlator (bits 19:5) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_PTTRN_MSK_CR1A_19_5_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL3_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL4 - Stat match controls register #4 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_SHIFT (0U)
/*! PTTRN_CR1B_19_5 - Value of pattern B for 1st correlator (bits 19:5) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_PTTRN_CR1B_19_5_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL4_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_MATCH_CTL5 - Stat match controls register #5 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_MASK (0x7FFFU)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_SHIFT (0U)
/*! PTTRN_MSK_CR1B_19_5 - Value of pattern B mask for 1st correlator (bits 19:5) */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_PTTRN_MSK_CR1B_19_5_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_RESERVED_15_15_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_MATCH_CTL5_RESERVED_15_15_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_CTL2 - Stat controls register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_SHIFT (0U)
/*! DATA_DLY_SEL_2 - Additional MSB bit for DATA_DLY_SEL to extend the delay range to 0->7 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_DATA_DLY_SEL_2_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_SHIFT (1U)
/*! SCOPE_DLY_2 - Additional MSB bit for SCOPE_DLY to extend the delay range to 0->7 */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_SCOPE_DLY_2_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_CTL2_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_RX_STAT_STAT_STOP - Stat stop register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_SHIFT (0U)
/*! SC1_STOP - Stop sample counters #1 and associated stat counters. */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_SC1_STOP_MASK)

#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_RESERVED_15_1_SHIFT)) & PHY_ENET_LANE0_DIG_RX_STAT_STAT_STOP_RESERVED_15_1_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_OVRD_OUT - Override values for TX signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_SHIFT (0U)
/*! TX_ANA_CLK_SHIFT - Override value for tx_ana_clk_shift */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_SHIFT_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_SHIFT (1U)
/*! TX_ANA_DATA_EN - Override value for tx_ana_data_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_SHIFT (2U)
/*! TX_ANA_REFGEN_EN - Override value for tx_ana_refgen_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_REFGEN_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_SHIFT (3U)
/*! TX_ANA_VCM_HOLD - Override value for tx_ana_vcm_hold */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_VCM_HOLD_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_SHIFT (4U)
/*! TX_ANA_CLK_EN - Override value for tx_ana_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_SHIFT (5U)
/*! TX_ANA_WORD_CLK_EN - Override value for tx_ana_word_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_SHIFT (6U)
/*! TX_ANA_MPLLA_CLK_EN - Override value for tx_ana_mplla_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_SHIFT (7U)
/*! TX_ANA_MPLLB_CLK_EN - Override value for tx_ana_mpllb_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_MPLLB_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_SHIFT (8U)
/*! TX_ANA_RESET - Override value for tx_ana_reset */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_RESET_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_MASK (0x200U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_SHIFT (9U)
/*! TX_ANA_SERIAL_EN - Override value for tx_ana_serial_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_SERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_MASK (0xC00U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_SHIFT (10U)
/*! TX_ANA_DATA_RATE - Override value for tx_ana_data_rate */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_ANA_DATA_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_RESERVED_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_RESERVED_SHIFT (12U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_SHIFT (13U)
/*! TX_DIV4_EN - Override value for tx_ana_div4_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_DIV4_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_SHIFT (14U)
/*! TX_RXDET_EN - Override value for tx_ana_rxdet_en */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_RXDET_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_SHIFT (15U)
/*! TX_OVRD_EN - Enable override values for all outputs controlled by this register */
#define PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_OVRD_OUT_TX_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT - Override value for TX termination code going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_CODE_MASK (0x3FFU)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_CODE_SHIFT (0U)
/*! TX_TERM_CODE - Overrides the tx_ana_term_code[9:0] signal */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_CODE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_OVRD_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_OVRD_EN_SHIFT (10U)
/*! TX_TERM_OVRD_EN - Override enable for the tx_ana_term_code[9:0] signal */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_TERM_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_CLK_LB_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_CLK_LB_EN_SHIFT (11U)
/*! TX_CLK_LB_EN - Override value for tx_ana_clk_lb_en (override enabled by TX_OVRD_EN). */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_CLK_LB_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_CLK_LB_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_TX_CLK_LB_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_OVRD_OUT_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT - Override value for TX termination code clocks going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_DN_CLK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_DN_CLK_SHIFT (0U)
/*! TX_TERM_DN_CLK - Override for TX term DN clock - This bit is self_clearing (4 cr_clks later). */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_DN_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_DN_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_DN_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_UP_CLK_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_UP_CLK_SHIFT (1U)
/*! TX_TERM_UP_CLK - Override for TX term UP clock This bit is self-clearing (4 cr_clks later). */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_UP_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_UP_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_UP_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_CLK_SELF_CLEAR_DISABLE_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_CLK_SELF_CLEAR_DISABLE_SHIFT (2U)
/*! TX_TERM_CLK_SELF_CLEAR_DISABLE - Disable self-clearing for the tx_ana_term_up/dn_clk register */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_CLK_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_CLK_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_TX_TERM_CLK_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_3_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_3_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0 - Override values for TX EQ signals going to ANA register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_SHIFT (0U)
/*! TX_ANA_LOAD_CLK - Override value for tx_ana_load_clk */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_LOAD_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_MASK (0x7FFEU)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_SHIFT (1U)
/*! TX_ANA_CTRL_ATTEN_13_0 - Override value for tx_ana_ctrl_atten[13:0] */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_ANA_CTRL_ATTEN_13_0_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_SHIFT (15U)
/*! TX_EQ_OVRD_EN - Override enable for tx eq signals */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_0_TX_EQ_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1 - Override values for TX EQ signals going to ANA register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_19_14_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_19_14_SHIFT (0U)
/*! TX_ANA_CTRL_ATTEN_19_14 - Override value for tx_ana_ctrl_atten[19:14] */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_19_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_19_14_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_TX_ANA_CTRL_ATTEN_19_14_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_RESERVED_15_6_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_1_RESERVED_15_6_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2 - Override values for TX EQ signals going to ANA register #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_SHIFT (0U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_MASK (0x1F80U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_SHIFT (7U)
/*! TX_ANA_CTRL_PRE - Override value for tx_ana_ctrl_pre[5:0] */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_TX_ANA_CTRL_PRE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_2_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3 - Override values for TX EQ signals going to ANA register #3 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_SHIFT (0U)
/*! TX_ANA_CTRL_POST - Override value for tx_ana_ctrl_post[7:0] */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_TX_ANA_CTRL_POST_MASK)

#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_TX_EQ_OVRD_OUT_3_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_CTL_OVRD_OUT - Override values for RX control signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_SHIFT (0U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_MASK (0x6U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_SHIFT (1U)
/*! RX_ANA_DATA_RATE - Override value for rx_ana_data_rate */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DATA_RATE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_SHIFT (3U)
/*! RX_ANA_WORD_CLK_EN - Override value for rx_ana_word_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_WORD_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_SHIFT (4U)
/*! RX_ANA_DIV4_EN - Override value for rx_ana_div4_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DIV4_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_SHIFT (5U)
/*! RX_ANA_DFE_TAPS_EN - Override value for rx_ana_dfe_taps_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_DFE_TAPS_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_ADAPTATION_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_ADAPTATION_EN_SHIFT (6U)
/*! RX_ANA_ADAPTATION_EN - Override value for rx_ana_adaptation_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_ADAPTATION_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_ADAPTATION_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_ANA_ADAPTATION_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_SHIFT (7U)
/*! RX_LBK_CLK_EN - Override value for rx_ana_loopback_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_LBK_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_SHIFT (8U)
/*! RX_CTL_OVRD_EN - Enable override values for outputs [8-0] below */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RX_CTL_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CTL_OVRD_OUT_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_PWR_OVRD_OUT - Override values for RX PWR UP/DN signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_SHIFT (0U)
/*! RX_ANA_LOS_EN - Override value for rx_ana_los_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_LOS_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_SHIFT (1U)
/*! RX_ANA_AFE_EN - Override value for rx_ana_afe_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_AFE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_SHIFT (2U)
/*! RX_ANA_CLK_VREG_EN - Override value for rx_ana_clk_vreg_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_VREG_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_SHIFT (3U)
/*! RX_ANA_CLK_DCC_EN - Override value for rx_ana_clk_dcc_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_DCC_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_SHIFT (4U)
/*! RX_ANA_CLK_EN - Override value for rx_ana_clk_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_SHIFT (5U)
/*! RX_ANA_CDR_EN - Override value for rx_ana_cdr_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_CDR_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_SHIFT (6U)
/*! RX_ANA_DESERIAL_EN - Override value for rx_ana_deserial_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_ANA_DESERIAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_SHIFT (7U)
/*! RX_PWR_OVRD_EN - Enable override values for all outputs controlled by this register */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RX_PWR_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_PWR_OVRD_OUT_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0 - RX VCO Outgoing Signals Override ANA #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_SHIFT (0U)
/*! RX_ANA_CDR_VCO_EN - RX_ANA_CDR_VCO_EN Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_VCO_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_SHIFT (1U)
/*! RX_ANA_CDR_STARTUP - RX_ANA_CDR_STARTUP Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_STARTUP_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_SHIFT (2U)
/*! RX_VCO_CDR_OVRD_EN - RX_VCO_CDR Override Enable */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_VCO_CDR_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_MASK (0x1FF8U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT (3U)
/*! RX_ANA_CDR_FREQ_TUNE - RX_ANA_CDR_FREQ_TUNE Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_CDR_FREQ_TUNE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_SHIFT (13U)
/*! RX_ANA_VCO_CNTR_EN - RX_ANA_VCO_CNTR_EN Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_MASK (0x4000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_SHIFT (14U)
/*! RX_ANA_VCO_CNTR_CLK - RX_ANA_VCO_CNTR_CLK Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_ANA_VCO_CNTR_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_SHIFT (15U)
/*! RX_CDR_FREQ_TUNE_OVRD_EN - RX_CDR_FREQ_TUNE Override Enable */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_0_RX_CDR_FREQ_TUNE_OVRD_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1 - Override values for RX VCO signals going to ANA #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_LOWFREQ_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_LOWFREQ_SHIFT (0U)
/*! RX_ANA_CDR_VCO_LOWFREQ - Override value for rx_ana_cdr_vco_lowfreq */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_LOWFREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_LOWFREQ_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_CDR_VCO_LOWFREQ_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_SHIFT (1U)
/*! RX_ANA_VCO_CNTR_PD - Override value for rx_ana_vco_cntr_pd */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RX_ANA_VCO_CNTR_PD_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_1_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2 - RX VCO Outgoing Signals Override ANA #2 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_SHIFT (0U)
/*! RX_ANA_CDR_FREQ_TUNE_CLK - RX_ANA_CDR_FREQ_TUNE_CLK Override Value */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_RX_ANA_CDR_FREQ_TUNE_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE - CDR_FREQ_TUNE_CLK Self-Clear Disable */
#define PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_VCO_OVRD_OUT_2_CDR_FREQ_TUNE_CLK_SELF_CLEAR_DISABLE_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_CAL - Sets values for RX CAL signals going to ANA register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_SHIFT (0U)
/*! RX_ANA_CAL_MUXA_SEL - Value for rx_ana_cal_muxa_sel[4:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXA_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_MASK (0x3E0U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_SHIFT (5U)
/*! RX_ANA_CAL_MUXB_SEL - Value for rx_ana_cal_muxb_sel[4:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MUXB_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_MASK (0x400U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_SHIFT (10U)
/*! RX_ANA_CAL_LPFBYP_EN - Value for rx_ana_cal_lpfbyp_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_LPFBYP_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RESERVED_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RESERVED_SHIFT (11U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_SHIFT (12U)
/*! RX_ANA_SLICER_CAL_EN - Value for rx_ana_slicer_cal_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_SLICER_CAL_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_MASK (0x6000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_SHIFT (13U)
/*! RX_ANA_CAL_MODE - Value for rx_ana_cal_mode[1:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_MODE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_MASK (0x8000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_SHIFT (15U)
/*! RX_ANA_CAL_COMP_EN - Value for rx_ana_cal_comp_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_CAL_RX_ANA_CAL_COMP_EN_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL - Sets values for RX DAC CTRL value going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_MASK (0xFFU)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL - Value for rx_ana_cal_dac_ctrl[7:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RX_ANA_CAL_DAC_CTRL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL_OVRD - Overrides RX DAC CTRL bus (en/val/sel) going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_SHIFT (0U)
/*! RX_CAL_DAC_CTRL_OVRD - Override enable for Cal DAC control */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RX_CAL_DAC_CTRL_OVRD_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RESERVED_15_1_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_OVRD_RESERVED_15_1_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_DAC_CTRL_SEL - Sets values for RX DAC CTRL Select signal going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_MASK (0x1FU)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL_SEL - Value for rx_ana_cal_dac_ctrl_sel[4:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RX_ANA_CAL_DAC_CTRL_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RESERVED_15_5_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_DAC_CTRL_SEL_RESERVED_15_5_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_AFE_ATT_VGA - Value for RX AFE ATT & VGA signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_SHIFT (0U)
/*! RX_ANA_AFE_ATT_LVL - Value for rx_ana_afe_att_lvl[2:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_ATT_LVL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_GAIN_MASK (0x78U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_GAIN_SHIFT (3U)
/*! RX_ANA_AFE_GAIN - Value for rx_ana_afe_gain[3:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_GAIN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_ANA_AFE_GAIN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_MASK (0x780U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_SHIFT (7U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_MASK (0x800U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_SHIFT (11U)
/*! RX_AFE_OVRD_EN - Override enable for AFE control */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RX_AFE_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_15_12_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_ATT_VGA_RESERVED_15_12_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_AFE_CTLE - Values for RX AFE CTLE signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_MASK (0x7U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_SHIFT (0U)
/*! RESERVED - RESERVED */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_MASK (0xF8U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_SHIFT (3U)
/*! RX_ANA_AFE_CTLE_BOOST - Value for rx_ana_afe_ctle_boost[4:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RX_ANA_AFE_CTLE_BOOST_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_AFE_CTLE_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_SCOPE - Values for RX SCOPE signals going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_SHIFT (0U)
/*! RX_ANA_SCOPE_EN - Sets value for rx_ana_scope_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_MASK (0x6U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_SHIFT (1U)
/*! RX_ANA_SCOPE_SEL - Sets value for rx_ana_scope_sel */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_SEL_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_SHIFT (3U)
/*! RX_ANA_SCOPE_PH_CLK - Sets value for rx_ana_scope_ph_clk - This bit is self-clearing (i. */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PH_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_MASK (0xFF0U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_SHIFT (4U)
/*! RX_ANA_SCOPE_PHASE - Sets value for rx_ana_scope_phase[7:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_PHASE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_MASK (0x1000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_SHIFT (12U)
/*! RX_ANA_SCOPE_CLK_EN - Enable the scope clocks going to the scope slicer and the lane digital part */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_ANA_SCOPE_CLK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_SCOPE_SELF_CLEAR_DISABLE_MASK (0x2000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_SCOPE_SELF_CLEAR_DISABLE_SHIFT (13U)
/*! RX_SCOPE_SELF_CLEAR_DISABLE - Disable the self-clearing for rx_ana_scope_ph_clk register */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_SCOPE_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_SCOPE_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RX_SCOPE_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RESERVED_15_14_MASK (0xC000U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RESERVED_15_14_SHIFT (14U)
/*! RESERVED_15_14 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RESERVED_15_14(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RESERVED_15_14_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SCOPE_RESERVED_15_14_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_SLICER_CTRL - Sets values for RX Slicer Ctrl signals going to ANA register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_MASK (0xFU)
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_E - Value for rx_ana_slicer_ctrl_e[3:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_E_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_MASK (0xF0U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_SHIFT (4U)
/*! RX_ANA_SLICER_CTRL_O - Value for rx_ana_slicer_ctrl_o[3:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_O_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_MASK (0x100U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_SHIFT (8U)
/*! RX_ANA_SLICER_CTRL_OVRD_EN - Override enable for Rx ANA Slicer Ctrl */
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RX_ANA_SLICER_CTRL_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RESERVED_15_9_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_SLICER_CTRL_RESERVED_15_9_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST - Sets values for RX ANA IQ PHASE Adjust signal going to ANA register */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_MASK (0x7FU)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_SHIFT (0U)
/*! RX_ANA_IQ_PHASE_ADJUST - Value for rx_ana_iq_phase_adjust[6:0] */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RX_ANA_IQ_PHASE_ADJUST_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RESERVED_15_7_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_PHASE_ADJUST_RESERVED_15_7_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN - Sets values for RX ANA IQ SENSE signal */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_SHIFT (0U)
/*! RX_ANA_IQ_SENSE_EN - Value for rx_ana_iq_sense_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RX_ANA_IQ_SENSE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RESERVED_15_1_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_IQ_SENSE_EN_RESERVED_15_1_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN - DAC CTRL enable signal */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_SHIFT (0U)
/*! RX_ANA_CAL_DAC_CTRL_EN - Value for rx_ana_cal_dac_ctrl_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RX_ANA_CAL_DAC_CTRL_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! DAC_CTRL_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_cal_dac_ctrl_en register */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_DAC_CTRL_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_CAL_DAC_CTRL_EN_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE - Afe update enable signal */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_SHIFT (0U)
/*! RX_ANA_AFE_UPDATE_EN - Value for rx_ana_afe_update_en */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RX_ANA_AFE_UPDATE_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! AFE_UPDATE_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_afe_update_en register */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_AFE_UPDATE_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_SIGNALS_CHANGES_ENABLE_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK - Phase adjust clock signal */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_SHIFT (0U)
/*! RX_ANA_IQ_PHASE_ADJUST_CLK - Value for rx_ana_iq_phase_adjust_clk */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RX_ANA_IQ_PHASE_ADJUST_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! PHASE_ADJUST_SELF_CLEAR_DISABLE - Disable self-clearing for the rx_ana_iq_phase_adjust_clk register */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_PHASE_ADJUST_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_ANA_PHASE_ADJUST_CLK_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_STATUS_0 - Lane input status register #0 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_SHIFT (0U)
/*! TX_ANA_CLK_SHIFT_ACK - Value from ANA for tx_ana_clk_shift_ack */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_SHIFT_ACK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_SHIFT (1U)
/*! TX_ANA_RXDETP_RESULT - Value from ANA for tx_ana_rxdetp_result */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETP_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_MASK (0x4U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_SHIFT (2U)
/*! TX_ANA_RXDETM_RESULT - Value from ANA for tx_ana_rxdetm_result */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_RXDETM_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_MASK (0x8U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_SHIFT (3U)
/*! TX_ANA_LOOPBACK_EN - Value of tx_ana_loopback_en */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_LOOPBACK_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_MASK (0x10U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_SHIFT (4U)
/*! TX_ANA_CLK_LB_EN - Value of tx_ana_clk_lb_en */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_TX_ANA_CLK_LB_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_MASK (0x20U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_SHIFT (5U)
/*! RX_ANA_LOS - Value from ANA for rx_ana_los */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_LOS_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_SHIFT (6U)
/*! RX_ANA_CAL_RESULT - Value from ANA for rx_ana_cal_result */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_CAL_RESULT_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_MASK (0x80U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_SHIFT (7U)
/*! RX_ANA_SCOPE_DATA - Value from ANA for rx_ana_scope_data */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_RX_ANA_SCOPE_DATA_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_0_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_0_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_0_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_STATUS_1 - Lane input status register #1 */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_MASK (0x1FFFU)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_SHIFT (0U)
/*! RX_ANA_VCO_CNTR - Value from ANA for rx_ana_vco_cntr */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_1_RX_ANA_VCO_CNTR_MASK)

#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_STATUS_1_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_STATUS_1_RESERVED_15_13_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_STATUS_1_RESERVED_15_13_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT - Override value for RX termination code going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_CODE_MASK (0x3FU)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_CODE_SHIFT (0U)
/*! RX_TERM_CODE - Overrides the rx_ana_term_code[5:0] signal */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_CODE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_CODE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_OVRD_EN_MASK (0x40U)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_OVRD_EN_SHIFT (6U)
/*! RX_TERM_OVRD_EN - Override enable for the rx_ana_term_code[5:0] signal */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_OVRD_EN_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RX_TERM_OVRD_EN_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RESERVED_15_7_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_OVRD_OUT_RESERVED_15_7_MASK)
/*! @} */

/*! @name LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT - Override value for RX termination code clock going to ANA */
/*! @{ */

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_MASK (0x1U)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SHIFT (0U)
/*! RX_TERM_CLK - Override for TX term DN clock - This bit is self_clearing (4 cr_clks later). */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SELF_CLEAR_DISABLE_MASK (0x2U)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SELF_CLEAR_DISABLE_SHIFT (1U)
/*! RX_TERM_CLK_SELF_CLEAR_DISABLE - Disable the self-clearing of rx_ana_term_clk register */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SELF_CLEAR_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SELF_CLEAR_DISABLE_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RX_TERM_CLK_SELF_CLEAR_DISABLE_MASK)

#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_2_SHIFT)) & PHY_ENET_LANE0_DIG_ANA_RX_TERM_CODE_CLK_OVRD_OUT_RESERVED_15_2_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_OVRD_MEAS - TX_OVRD_MEAS */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_SHIFT (0U)
/*! ovrd_clk_shift - If asserted, allow analog register to control clock shift function */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_clk_shift_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_SHIFT (1U)
/*! clk_shift_reg - Controls clock shift if asserted with bit 0 */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_clk_shift_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_m_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_m_SHIFT (2U)
/*! meas_samp_m - Measure clock m DCD through atb_s_p on clock m sample */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_m(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_m_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_m_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_p_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_p_SHIFT (3U)
/*! meas_samp_p - Measure clock p DCD through atb_s_p on clock psample */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_p(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_p_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_meas_samp_p_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_SHIFT (4U)
/*! ovrd_vcm_hold - If asserted, bit 5 take effect on control Tx common mode */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_ovrd_vcm_hold_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_SHIFT (5U)
/*! vcm_hold_reg - Set Tx in common mode if asserted together with bit 4 */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_vcm_hold_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_SHIFT (6U)
/*! pull_up_reg - Pull up TX output if asserted */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_up_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_SHIFT (7U)
/*! pull_dn_reg - Pull down TX output if asserted */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_pull_dn_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_MEAS_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_PWR_OVRD - TX_PWR_OVRD */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_SHIFT (0U)
/*! ovrd_tx_loopback - Enable Tx loopback mode over ridden by analog register if asserted */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_tx_loopback_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_SHIFT (1U)
/*! loopback_en_reg - Enable TX loopback path to RX if asserted along with bit 0 */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_loopback_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_SHIFT (2U)
/*! refgen_en_reg - Enable TX biasing if asserted with bit 7 */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_refgen_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_SHIFT (3U)
/*! clk_div_en_reg - Enable TX divider if asserted with bit 7, overrides !tx_reset */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_div_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_data_en_reg_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_data_en_reg_SHIFT (4U)
/*! data_en_reg - Enable TX driver data path if asserted with bit 7 */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_data_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_data_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_data_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_SHIFT (5U)
/*! clk_en_reg - Enable TX clock if asserted with bit 7 */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_SHIFT (6U)
/*! serial_en_reg - Enable TX serializer if assered with bit 7 */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_serial_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_serial_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_en_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_en_SHIFT (7U)
/*! ovrd_en - Enable analog register to take control TX power state if asserted */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_ovrd_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_PWR_OVRD_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_PWR_OVRD_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_PWR_OVRD_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_ALT_BUS - TX_ALT_BUS */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_drv_source_reg_MASK (0x3U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_drv_source_reg_SHIFT (0U)
/*! drv_source_reg - When bit 2 is asserted, drv_source_reg[1:0] takes control of TX function, overrides tx_data_source[1:0] */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_drv_source_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_drv_source_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_drv_source_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_SHIFT (2U)
/*! ovrd_alt_bus - If asserted jtag data and TX data source selection are controlled by bits [1:0] and bit 7 */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_ovrd_alt_bus_MASK)

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_NC3_MASK   (0x8U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_NC3_SHIFT  (3U)
/*! NC3 - Reserved */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_NC3(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_NC3_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_NC3_MASK)

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_tx_alt_ringo_MASK (0x70U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_tx_alt_ringo_SHIFT (4U)
/*! tx_alt_ringo - Three bit select of the ALT path test oscillators */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_tx_alt_ringo(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_tx_alt_ringo_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_tx_alt_ringo_MASK)

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_SHIFT (7U)
/*! jtag_data_reg - When bit 2 is asserted, it replace jtag data */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_jtag_data_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_jtag_data_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_ALT_BUS_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ALT_BUS_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ALT_BUS_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_ATB1 - TX_ATB1 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_gd_MASK   (0x1U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_gd_SHIFT  (0U)
/*! atb_gd - Put tx local gd on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_gd(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_gd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_gd_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccm_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccm_SHIFT (1U)
/*! atb_vdccm - Put DCC control voltage m on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccm(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccm_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccm_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccp_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccp_SHIFT (2U)
/*! atb_vdccp - Put DCC control voltage p on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccp(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccp_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_vdccp_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vptx_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vptx_SHIFT (3U)
/*! atb_vptx - Put TX driver local vptx on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vptx(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_vptx_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_vptx_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_override_regref_0_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_override_regref_0_SHIFT (4U)
/*! override_regref_0 - Use atb_s_m as TX regulator 0 reference voltage when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_override_regref_0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_override_regref_0_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_override_regref_0_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg0_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg0_SHIFT (5U)
/*! atb_vreg0 - Put TX regulator 0 output on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg0(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg0_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg0_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg1_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg1_SHIFT (6U)
/*! atb_vreg1 - Put TX regulator 1 output on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg1(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg1_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_atb_vreg1_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_NC7_MASK      (0x80U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_NC7_SHIFT     (7U)
/*! NC7 - Reserved */
#define PHY_ENET_LANE0_ANA_TX_ATB1_NC7(x)        (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_NC7_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_NC7_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_ATB1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_ATB1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB1_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB1_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_ATB2 - TX_ATB2 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_vcm_MASK  (0x1U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_vcm_SHIFT (0U)
/*! atb_vcm - Measure Tx vcm through atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_vcm(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_vcm_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_vcm_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsm_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsm_SHIFT (1U)
/*! atb_txsm - Measure tx_m through atb_s_m when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsm(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsm_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsm_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsp_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsp_SHIFT (2U)
/*! atb_txsp - Measure tx_p through atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsp(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsp_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_txsp_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfm_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfm_SHIFT (3U)
/*! atb_txfm - Overdrive tx_m through atb_f_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfm(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfm_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfm_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfp_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfp_SHIFT (4U)
/*! atb_txfp - Overdrive tx_p through atb_f_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfp(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfp_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_txfp_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_rxdetref_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_rxdetref_SHIFT (5U)
/*! atb_rxdetref - Put TX RX detection reference voltage on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_rxdetref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_rxdetref_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_rxdetref_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_nbias_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_nbias_SHIFT (6U)
/*! atb_nbias - Put TX nbias on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_nbias(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_nbias_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_nbias_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_pbias_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_pbias_SHIFT (7U)
/*! atb_pbias - Put TX pbias on atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_ATB2_atb_pbias(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_atb_pbias_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_atb_pbias_MASK)

#define PHY_ENET_LANE0_ANA_TX_ATB2_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_ATB2_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_ATB2_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_ATB2_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_ATB2_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_VBOOST - TX_VBOOST */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_VBOOST_meas_atb_vph_half_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_meas_atb_vph_half_SHIFT (0U)
/*! meas_atb_vph_half - Measure vph/2 on atb_s_p */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_meas_atb_vph_half(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_meas_atb_vph_half_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_meas_atb_vph_half_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_s_enable_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_s_enable_SHIFT (1U)
/*! atb_s_enable - Enables TX atb function if asserted */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_s_enable(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_atb_s_enable_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_atb_s_enable_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_override_vref_boost_ref_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_override_vref_boost_ref_SHIFT (2U)
/*! override_vref_boost_ref - If enabled, atb_s_m is used to provide Tx boost reference voltage instead of bandgap voltage tx_vboost_vref */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_override_vref_boost_ref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_override_vref_boost_ref_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_override_vref_boost_ref_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_vref_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_vref_SHIFT (3U)
/*! atb_vboost_vref - Measure tx boost reference voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_vref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_vref_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_vref_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_SHIFT (4U)
/*! atb_vboost - Measure vptx/2 through atb_s_p when TX boost is enabled */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_atb_vboost_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_SHIFT (5U)
/*! boost_vptx_mode_n - If asserted, TX boost mode becomes a direct boost mode. */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_boost_vptx_mode_n_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_vboost_en_reg_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_vboost_en_reg_SHIFT (6U)
/*! vboost_en_reg - If bit 7 is set to 1, analog register takes control of Tx vboost enable/disable */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_vboost_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_vboost_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_vboost_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_SHIFT (7U)
/*! ovrd_vboost_en - Enable TX boost mode to be override by bit 6 */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_ovrd_vboost_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_ovrd_vboost_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_VBOOST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_VBOOST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_VBOOST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_VBOOST_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_VBOOST_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_TERM_CODE - TX_TERM_CODE */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_ovrd_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_ovrd_SHIFT (0U)
/*! term_code_ovrd - Enable analog register to overdrive TX leg biasing */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_reg_MASK (0xFEU)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_reg_SHIFT (1U)
/*! term_code_reg - TX leg biasing register (7 MSBs),this is Term_code_reg[9:3] */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_term_code_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_TERM_CODE_CTRL - TX_TERM_CODE_CTRL */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_ovrd_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_ovrd_SHIFT (0U)
/*! tx_pwr_en_ovrd - Enables analog register control over the power gating of blocks within the TX */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_reg_SHIFT (1U)
/*! tx_pwr_en_reg - Register control over the power gating of blocks within the TX */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_tx_pwr_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_ovrd_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_ovrd_SHIFT (2U)
/*! update_term_dn_ovrd - Enables analog register control to update the pulldown TX terminations */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_reg_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_reg_SHIFT (3U)
/*! update_term_dn_reg - Register control to update the pulldown TX terminations */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_dn_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_ovrd_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_ovrd_SHIFT (4U)
/*! update_term_up_ovrd - Enables analog register control to update the pullup TX terminations */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_reg_SHIFT (5U)
/*! update_term_up_reg - Register control to update the pullup TX terminations */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_update_term_up_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_ovrd_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_ovrd_SHIFT (6U)
/*! reset_term_ovrd - Enable analog register to reset termination code DACs */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_reg_SHIFT (7U)
/*! reset_term_reg - Resets the tx termination code DACs */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_reset_term_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_TERM_CODE_CTRL_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_IBOOST_CODE - TX_IBOOST_CODE */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_SHIFT (0U)
/*! lfps_high_priority - If asserted, lfps/beacon enable has higher priority than data enable */
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_SHIFT)) & PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_lfps_high_priority_MASK)

#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_term_code_reg_MASK (0x6U)
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_term_code_reg_SHIFT (1U)
/*! term_code_reg - TX leg biasing register bit 2 & 1, this is term_code_reg[2:1] */
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_term_code_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_term_code_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_term_code_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_SHIFT (3U)
/*! iboost_code_ovrd - Enable analog register overdrive for TX boost */
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_SHIFT)) & PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_ovrd_MASK)

#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_MASK (0xF0U)
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_SHIFT (4U)
/*! iboost_code_reg - When TX boost is enabled and bit 3 is asserted, these 4 bits take control of TX boost. */
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_iboost_code_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_IBOOST_CODE_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_OVRD_CLK - TX_OVRD_CLK */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_override_regref_1_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_override_regref_1_SHIFT (0U)
/*! override_regref_1 - Use atb_s_m to over ride TX regulator reference voltage when asserted */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_override_regref_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_override_regref_1_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_override_regref_1_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_SHIFT (1U)
/*! clk_lb_en_reg - When asserted with bit 2, selects RX clock for TX data output clock */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_clk_lb_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_SHIFT (2U)
/*! ovrd_lb_en - If asserted, it allows bit 1 takes control of RX clock loopback to TX */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_lb_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_SHIFT (3U)
/*! mpllb_clk_en_reg - When asserted with bit 5, selects MPLLB clock as TX data output clock */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mpllb_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_SHIFT (4U)
/*! mplla_clk_en_reg - When asserted with bit 5, selects MPLLA clock as TX data output clock */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_mplla_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_SHIFT (5U)
/*! ovrd_mpllab_en - If asserted, it allows bit 3 or 4 to take control of selecting MPLL clocks */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_mpllab_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_SHIFT (6U)
/*! word_clk_en_reg - Tx word clock enable/disable when bit 7 is asserted */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_word_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_SHIFT (7U)
/*! ovrd_word_clk_en - If asserted, it allows bit 6 to override tx word clock enable */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_ovrd_word_clk_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_OVRD_CLK_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_OVRD_CLK_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_OVRD_CLK_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_TX_MISC - TX_MISC */
/*! @{ */

#define PHY_ENET_LANE0_ANA_TX_MISC_NC4_0_MASK    (0x1FU)
#define PHY_ENET_LANE0_ANA_TX_MISC_NC4_0_SHIFT   (0U)
/*! NC4_0 - Reserved */
#define PHY_ENET_LANE0_ANA_TX_MISC_NC4_0(x)      (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_MISC_NC4_0_SHIFT)) & PHY_ENET_LANE0_ANA_TX_MISC_NC4_0_MASK)

#define PHY_ENET_LANE0_ANA_TX_MISC_osc_div4_en_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_TX_MISC_osc_div4_en_SHIFT (5U)
/*! osc_div4_en - If asserted, divides tx_alt oscillator output frequency by 4 */
#define PHY_ENET_LANE0_ANA_TX_MISC_osc_div4_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_MISC_osc_div4_en_SHIFT)) & PHY_ENET_LANE0_ANA_TX_MISC_osc_div4_en_MASK)

#define PHY_ENET_LANE0_ANA_TX_MISC_meas_atb_bias_vptx_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_TX_MISC_meas_atb_bias_vptx_SHIFT (6U)
/*! meas_atb_bias_vptx - Measure TX bias local vptx through atb_s_p when asserted */
#define PHY_ENET_LANE0_ANA_TX_MISC_meas_atb_bias_vptx(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_MISC_meas_atb_bias_vptx_SHIFT)) & PHY_ENET_LANE0_ANA_TX_MISC_meas_atb_bias_vptx_MASK)

#define PHY_ENET_LANE0_ANA_TX_MISC_override_rxdetref_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_TX_MISC_override_rxdetref_SHIFT (7U)
/*! override_rxdetref - If asserted, atb_s_m is used to override RX detection reference voltage */
#define PHY_ENET_LANE0_ANA_TX_MISC_override_rxdetref(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_MISC_override_rxdetref_SHIFT)) & PHY_ENET_LANE0_ANA_TX_MISC_override_rxdetref_MASK)

#define PHY_ENET_LANE0_ANA_TX_MISC_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_TX_MISC_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_TX_MISC_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_TX_MISC_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_TX_MISC_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_ATB_IQSKEW - RX_ATB_IQSKEW */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_iq_phase_adjust_reg_MASK (0x1FU)
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_iq_phase_adjust_reg_SHIFT (0U)
/*! iq_phase_adjust_reg - If ovrd_iq_phase_adjust is enabled, these bits control the main PMIX */
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_iq_phase_adjust_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_iq_phase_adjust_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_iq_phase_adjust_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_vp_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_vp_SHIFT (5U)
/*! meas_atb_vp - If asserted, vp is measured through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_vp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_vp_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_vp_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_rx_scope_reg_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_rx_scope_reg_SHIFT (6U)
/*! meas_atb_rx_scope_reg - If asserted, enable scope linearity characterization through atb_s_p/m */
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_rx_scope_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_rx_scope_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_meas_atb_rx_scope_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_master_atb_en_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_master_atb_en_SHIFT (7U)
/*! master_atb_en - If asserted, enable RX ATB sensing bus atb_s_p/m visible externally. */
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_master_atb_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_master_atb_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_master_atb_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_IQSKEW_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_DCC_OVRD - RX_DCC_OVRD */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_NC1_0_MASK (0x3U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_NC1_0_SHIFT (0U)
/*! NC1_0 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_NC1_0(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_NC1_0_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_NC1_0_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_meas_atb_vdcc_MASK (0xCU)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_meas_atb_vdcc_SHIFT (2U)
/*! meas_atb_vdcc - meas_atb_vdcc[1:0] */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_meas_atb_vdcc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_meas_atb_vdcc_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_meas_atb_vdcc_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_rx_loopback_clk_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_rx_loopback_clk_SHIFT (4U)
/*! ovrd_rx_loopback_clk - When asserted, override rx clock loopback by analog register */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_rx_loopback_clk(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_rx_loopback_clk_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_rx_loopback_clk_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_rx_loopback_clk_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_rx_loopback_clk_reg_SHIFT (5U)
/*! rx_loopback_clk_reg - When bit 4 asserted, this bit takes control of RX clock loopback enable/disable */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_rx_loopback_clk_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_rx_loopback_clk_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_rx_loopback_clk_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_SHIFT (6U)
/*! ovrd_dccandafe_en - When asserted, override RX DCC enable by analog register */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_ovrd_dccandafe_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_SHIFT (7U)
/*! dcc_en_reg - When bit 6 is asserted, this bit takes control of RX DCC enable */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_dcc_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_DCC_OVRD_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_DCC_OVRD_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_DCC_OVRD_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_PWR_CTRL1 - RX_PWR_CTRL1 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_SHIFT (0U)
/*! ovrd_acjt_en - If asserted, bit 1 take control of ACJTAG enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_acjt_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_SHIFT (1U)
/*! acjt_en_reg - When asserted with bit 0, enables ACJTAG */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_acjt_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_SHIFT (2U)
/*! ovrd_clk_en - If asserted, bit 3 take control of RX clock enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_clk_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_SHIFT (3U)
/*! clk_en_reg - When asserted with bit 2, enables RX clock */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_SHIFT (4U)
/*! ovrd_los_en - If asserted, bit 5 take control of LOS enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_los_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_SHIFT (5U)
/*! los_en_reg - When asserted with bit 4, enables LOS */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_los_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_los_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_afe_en_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_afe_en_SHIFT (6U)
/*! ovrd_afe_en - If asserted, bit 7 take control of AFE enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_afe_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_afe_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_ovrd_afe_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_afe_en_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_afe_en_reg_SHIFT (7U)
/*! afe_en_reg - When asserted with bit 6, enables AFE */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_afe_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_afe_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_afe_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL1_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_ATB_REGREF - RX_ATB_REGREF */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_samp_MASK (0x3U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_samp_SHIFT (0U)
/*! meas_atb_samp - meas_atb_samp[1:0] */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_samp(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_samp_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_samp_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_NC2_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_NC2_SHIFT (2U)
/*! NC2 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_NC2(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_NC2_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_NC2_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_scope_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_scope_SHIFT (3U)
/*! override_regref_scope - If asserted, RX scope regulator reference is overridden through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_scope(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_scope_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_scope_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_clk_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_clk_SHIFT (4U)
/*! override_regref_clk - If asserted, RX clock regulator reference is overridden through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_clk(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_clk_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_override_regref_clk_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_cal_mux_MASK (0xE0U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_cal_mux_SHIFT (5U)
/*! meas_atb_cal_mux - Meas_atb_cal_mux is 3 bit signal Meas_atb_cal_mux[2:0] */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_cal_mux(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_cal_mux_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_meas_atb_cal_mux_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_ATB_REGREF_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_REGREF_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_REGREF_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CDR_AFE - RX_CDR_AFE */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_meas_atb_rx_MASK (0xFU)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_meas_atb_rx_SHIFT (0U)
/*! meas_atb_rx - This is meas_atb_rx[9:6] bit, each bit correspond to ==> */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_meas_atb_rx(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_meas_atb_rx_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_meas_atb_rx_MASK)

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_SHIFT (4U)
/*! phdet_odd_reg - If asserted, CDR phase detector uses odd data path */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_odd_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_SHIFT (5U)
/*! phdet_even_reg - If asserted, CDR phase detector uses even data path */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_even_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_phdet_even_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_NC6_MASK   (0x40U)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_NC6_SHIFT  (6U)
/*! NC6 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_NC6(x)     (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_NC6_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_NC6_MASK)

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_rxterm_pull_dn_cont_ovrd_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_rxterm_pull_dn_cont_ovrd_reg_SHIFT (7U)
/*! rxterm_pull_dn_cont_ovrd_reg - If asserted RX Termination pulldown resister can be controlled via CREG */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_rxterm_pull_dn_cont_ovrd_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_rxterm_pull_dn_cont_ovrd_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_rxterm_pull_dn_cont_ovrd_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_CDR_AFE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CDR_AFE_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CDR_AFE_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_PWR_CTRL2 - RX_PWR_CTRL2 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_rx_pwr_en_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_rx_pwr_en_SHIFT (0U)
/*! ovrd_rx_pwr_en - If asserted, bit 1 overrides the lane_pwr_en input signal (power gating) */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_rx_pwr_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_rx_pwr_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_rx_pwr_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_rx_pwr_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_rx_pwr_en_reg_SHIFT (1U)
/*! rx_pwr_en_reg - If asserted via bit 0, bit 1 overrides the lane_pwr_en input signal (power gating) */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_rx_pwr_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_rx_pwr_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_rx_pwr_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_SHIFT (2U)
/*! ovrd_dfe_en - If asserted, bit 3 takes control of RX DFE error path enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_dfe_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_SHIFT (3U)
/*! dfe_en_reg - If asserted with bit 2, enables RX DFE error path */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_dfe_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_deserial_en_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_deserial_en_SHIFT (4U)
/*! ovrd_deserial_en - If asserted, bit 5 takes control of RX deserializer enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_deserial_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_deserial_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_deserial_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_SHIFT (5U)
/*! deserial_en_reg - If asserted with bit 4, enables RX deserializer */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_deserial_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_SHIFT (6U)
/*! ovrd_loopback_en - If asserted, bit 7 takes control of TX to RX data loopback enable/disable */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_ovrd_loopback_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_SHIFT (7U)
/*! loopback_en_reg - If asserted with bit 6, enables TX to RX data loopback */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_loopback_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_PWR_CTRL2_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_MISC_OVRD - RX_MISC_OVRD */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_word_clk_en_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_word_clk_en_SHIFT (0U)
/*! ovrd_word_clk_en - If asserted, bit 1 takes control of word clock enable/disable */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_word_clk_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_word_clk_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_word_clk_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_word_clk_en_reg_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_word_clk_en_reg_SHIFT (1U)
/*! word_clk_en_reg - If asserted with bit 0, enables rx word clock */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_word_clk_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_word_clk_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_word_clk_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rxterm_pull_dn_cnt_reg_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rxterm_pull_dn_cnt_reg_SHIFT (2U)
/*! rxterm_pull_dn_cnt_reg - This is to control RX_TERM pull down resister for Each both RX
 *    Terminations, if rxterm_pull_dn_cont_ovrd_reg is asserted.
 */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rxterm_pull_dn_cnt_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rxterm_pull_dn_cnt_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rxterm_pull_dn_cnt_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_NC3_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_NC3_SHIFT (3U)
/*! NC3 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_NC3(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_NC3_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_NC3_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_SHIFT (4U)
/*! rx_los_lfps_en_reg - If asserted with bit 5, enables true LFPS detection */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_rx_los_lfps_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_SHIFT (5U)
/*! ovrd_rx_los_lfps_en - If asserted, bit 4 enable/disables RX true LFPS detection */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ovrd_rx_los_lfps_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ctle_offset_cal_enb_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ctle_offset_cal_enb_SHIFT (6U)
/*! ctle_offset_cal_enb - If asserted, the offset calibration currents in the CTLE are disabled */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ctle_offset_cal_enb(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ctle_offset_cal_enb_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_ctle_offset_cal_enb_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_override_vreg_prechg_reg_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_override_vreg_prechg_reg_SHIFT (7U)
/*! override_vreg_prechg_reg - If asserted, the overvoltage compensation circuit in rx_vregs disabled */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_override_vreg_prechg_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_override_vreg_prechg_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_override_vreg_prechg_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_MISC_OVRD_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_MISC_OVRD_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_MISC_OVRD_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CAL_MUXA - RX_CAL_MUXA */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vco_200u_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vco_200u_SHIFT (0U)
/*! meas_atb_vco_200u - If asserted, measure CDR VCO bias current through atb_s_m (200uA) */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vco_200u(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vco_200u_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vco_200u_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vibias_vco_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vibias_vco_SHIFT (1U)
/*! meas_atb_vibias_vco - If asserted, measure CDR VCO bias current through atb_s_p (25uA) */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vibias_vco(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vibias_vco_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXA_meas_atb_vibias_vco_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_MASK (0x7CU)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_SHIFT (2U)
/*! cal_muxa_sel_reg - Analog registers to control RX calibration path A if bit 7 is asserted , this is cal_muxa_sel_reg[4:0] */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXA_cal_muxa_sel_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_SHIFT (7U)
/*! ovrd_cal_muxa_sel - If asserted, selects analog register setting to control RX calibration path A */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXA_ovrd_cal_muxa_sel_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXA_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXA_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXA_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_ATB_MEAS1 - RX_ATB_MEAS1 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_NC0_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_NC0_SHIFT (0U)
/*! NC0 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_NC0(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_NC0_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_NC0_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_meas_atb_rx_MASK (0x7EU)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_meas_atb_rx_SHIFT (1U)
/*! meas_atb_rx - This is meas_atb_rx[5:0] bits , where each bit correspond to */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_meas_atb_rx(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_meas_atb_rx_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_meas_atb_rx_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_atb_frc_vlos_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_atb_frc_vlos_SHIFT (7U)
/*! atb_frc_vlos - If asserted, force los detection reference voltage through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_atb_frc_vlos(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_atb_frc_vlos_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_atb_frc_vlos_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS1_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_ATB_MEAS2 - RX_ATB_MEAS2 */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_vosc_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_vosc_SHIFT (0U)
/*! meas_atb_vco_vosc - If asserted, measure CDR VCO oscillation bias current through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_vosc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_vosc_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_vosc_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_gd_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_gd_SHIFT (1U)
/*! meas_atb_vco_gd - If asserted, measure CDR VCO local gd through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_gd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_gd_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_vco_gd_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_ovrd_cdr_en_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_ovrd_cdr_en_SHIFT (2U)
/*! meas_atb_ovrd_cdr_en - If asserted, enables CDR regardless of the digital control */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_ovrd_cdr_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_ovrd_cdr_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_atb_ovrd_cdr_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_scope_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_scope_SHIFT (3U)
/*! meas_vreg_scope - If asserted, measure RX scope regulator output voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_scope(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_scope_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_scope_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC4_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC4_SHIFT (4U)
/*! NC4 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC4(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC4_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC4_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_clk_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_clk_SHIFT (5U)
/*! meas_vreg_clk - If asserted, measure RX clock regulator output voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_clk(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_clk_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_vreg_clk_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC6_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC6_SHIFT (6U)
/*! NC6 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC6(x)   (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC6_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_NC6_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_gd_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_gd_SHIFT (7U)
/*! meas_gd - If asserted, measure RX regulator local gd through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_gd(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_gd_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_meas_gd_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_MEAS2_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_CAL_MUXB - RX_CAL_MUXB */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_SHIFT (0U)
/*! dfe_taps_en_reg - If bit 1 is asserted, controls DFE tap 1 and 2 */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXB_dfe_taps_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_dfe_taps_en_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_dfe_taps_en_SHIFT (1U)
/*! ovrd_dfe_taps_en - If asserted, allows bit 0 to enable/disable dfe taps 1 and 2 */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_dfe_taps_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_dfe_taps_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_dfe_taps_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_MASK (0x7CU)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_SHIFT (2U)
/*! cal_muxb_sel_reg - Analog registers to control RX calibration path B if bit 7 is asserted, this is cal_muxb_sel_reg[4:0] */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXB_cal_muxb_sel_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_SHIFT (7U)
/*! ovrd_cal_muxb_sel - If asserted, selects analog register setting to control RX calibration path B */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXB_ovrd_cal_muxb_sel_MASK)

#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_CAL_MUXB_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_CAL_MUXB_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_CAL_MUXB_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_TERM - RX_TERM */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_TERM_cdr_vco_startup_code_reg_MASK (0x3U)
#define PHY_ENET_LANE0_ANA_RX_TERM_cdr_vco_startup_code_reg_SHIFT (0U)
/*! cdr_vco_startup_code_reg - RX_VCO startup current over-ride */
#define PHY_ENET_LANE0_ANA_RX_TERM_cdr_vco_startup_code_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_cdr_vco_startup_code_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_cdr_vco_startup_code_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_vco_temp_comp_en_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_TERM_vco_temp_comp_en_SHIFT (2U)
/*! vco_temp_comp_en - If asserted the RX-VCO temperature compensation circuit is enabled */
#define PHY_ENET_LANE0_ANA_RX_TERM_vco_temp_comp_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_vco_temp_comp_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_vco_temp_comp_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_SHIFT (3U)
/*! ovrd_iq_phase_adjust - If asserted the iq_phase_adjust value is controlled via registers */
#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_ovrd_iq_phase_adjust_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_MASK (0x10U)
#define PHY_ENET_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_SHIFT (4U)
/*! rx_term_gd_en_reg - If termination override is asserted, controls the ground termination enable */
#define PHY_ENET_LANE0_ANA_RX_TERM_rx_term_gd_en_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_rx_term_gd_en_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_SHIFT (5U)
/*! ovrd_rx_term_gd_en - If asserted the ground termination enable value is controlled via registers */
#define PHY_ENET_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_ovrd_rx_term_gd_en_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_afe_cm_sel_MASK (0xC0U)
#define PHY_ENET_LANE0_ANA_RX_TERM_afe_cm_sel_SHIFT (6U)
/*! afe_cm_sel - Added to make AFE CM voltage controllable (below values are for TT vp=0. */
#define PHY_ENET_LANE0_ANA_RX_TERM_afe_cm_sel(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_afe_cm_sel_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_afe_cm_sel_MASK)

#define PHY_ENET_LANE0_ANA_RX_TERM_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_TERM_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_TERM_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_TERM_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_TERM_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_SLC_CTRL - RX_SLC_CTRL */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_MASK (0xFU)
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_SHIFT (0U)
/*! rx_slicer_ctrl_o_reg - If ovrd_rx_slicer_ctrl_reg is asserted, controls the odd slicer configuration */
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_o_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_MASK (0xF0U)
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_SHIFT (4U)
/*! rx_slicer_ctrl_e_reg - If ovrd_rx_slicer_ctrl_reg is asserted, controls the even slicer configuration */
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_SLC_CTRL_rx_slicer_ctrl_e_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_SLC_CTRL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_SLC_CTRL_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_SLC_CTRL_RESERVED_15_8_MASK)
/*! @} */

/*! @name LANE0_ANA_RX_ATB_VREG - RX_ATB_VREG */
/*! @{ */

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_rx_slicer_ctrl_reg_MASK (0x1U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_rx_slicer_ctrl_reg_SHIFT (0U)
/*! ovrd_rx_slicer_ctrl_reg - If asserted the slicer configuration value is controlled via registers (LANE. */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_rx_slicer_ctrl_reg(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_rx_slicer_ctrl_reg_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_rx_slicer_ctrl_reg_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_iqc_vref_sel_MASK (0x2U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_iqc_vref_sel_SHIFT (1U)
/*! ovrd_iqc_vref_sel - If asserted the vref on the iqc regulator is controlled via vbg_vref, which can be controlled via registers */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_iqc_vref_sel(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_iqc_vref_sel_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_iqc_vref_sel_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_scope_MASK (0x4U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_scope_SHIFT (2U)
/*! meas_atb_vreg_iqc_scope - If asserted, measure RX scope PMIX regulator output voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_scope(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_scope_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_scope_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_MASK (0x8U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_SHIFT (3U)
/*! meas_atb_vreg_iqc - If asserted, measure RX main PMIX regulator output voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_iqc_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_NC4_MASK  (0x10U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_NC4_SHIFT (4U)
/*! NC4 - Reserved */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_NC4(x)    (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_NC4_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_NC4_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_dfe_MASK (0x20U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_dfe_SHIFT (5U)
/*! meas_atb_vreg_dfe - If asserted, measure RX DFE regulator output voltage through atb_s_p */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_dfe(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_dfe_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_meas_atb_vreg_dfe_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_scope_MASK (0x40U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_scope_SHIFT (6U)
/*! ovrd_regref_iqc_scope - If asserted, scope PMIX regulator reference is overridden through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_scope(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_scope_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_scope_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_MASK (0x80U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_SHIFT (7U)
/*! ovrd_regref_iqc - If asserted, main PMIX regulator reference is overridden through atb_s_m */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_ovrd_regref_iqc_MASK)

#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_LANE0_ANA_RX_ATB_VREG_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_LANE0_ANA_RX_ATB_VREG_RESERVED_15_8_SHIFT)) & PHY_ENET_LANE0_ANA_RX_ATB_VREG_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_IN - Override values for incoming TX controls from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_SHIFT (0U)
/*! PSTATE - Override value for tx_pstate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_PSTATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_SHIFT (2U)
/*! LPD - Override value for tx_lpd */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_LPD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_MASK (0x18U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_SHIFT (3U)
/*! WIDTH - Override value for tx_width */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_WIDTH_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_MASK (0xE0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_SHIFT (5U)
/*! RATE - Override value for tx_rate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_SHIFT (8U)
/*! MPLLB_SEL - Override value for tx_mpllb_sel */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLLB_SEL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_SHIFT (9U)
/*! MPLL_EN - Override value for tx_mpll_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MPLL_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_SHIFT (10U)
/*! MSTR_MPLLA_STATE - Override value for tx_master_mplla_state */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLA_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_SHIFT (11U)
/*! MSTR_MPLLB_STATE - Override value for tx_master_mpllb_state */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_MSTR_MPLLB_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_SHIFT (12U)
/*! OVRD_EN - Override enable for all input signals below */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1 - Override values for incoming TX controls from PCS, register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT (0U)
/*! RESET_OVRD_VAL - Override value for tx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Override enable for tx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESET_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT (2U)
/*! REQ_OVRD_VAL - Override value for tx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_SHIFT (3U)
/*! REQ_OVRD_EN - Override enable for tx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_SHIFT (4U)
/*! DETRX_REQ_OVRD_VAL - Override value for tx_detrx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_SHIFT (5U)
/*! DETRX_REQ_OVRD_EN - Override enable for tx_detrx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_DETRX_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_SHIFT (6U)
/*! VBOOST_EN_OVRD_VAL - Override value for tx_vboost_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_SHIFT (7U)
/*! VBOOST_EN_OVRD_EN - Override enable for tx_vboost_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_VBOOST_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_MASK (0xF00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_SHIFT (8U)
/*! IBOOST_LVL_OVRD_VAL - Override value for tx_iboost_lvl[3:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_SHIFT (12U)
/*! IBOOST_LVL_OVRD_EN - Override enable for tx_iboost_lvl[3:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_IBOOST_LVL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_IN_1_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_PCS_IN - Current values for incoming TX controls from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_SHIFT (0U)
/*! RESET - Value from PCS for tx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESET_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_SHIFT (1U)
/*! REQ - Value from PCS for tx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_MASK (0xCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_SHIFT (2U)
/*! PSTATE - Value from PCS for tx_pstate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_PSTATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_SHIFT (4U)
/*! LPD - Value from PCS for tx_lpd */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_LPD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_MASK (0x60U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_SHIFT (5U)
/*! WIDTH - Value from PCS for tx_width */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_WIDTH_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_MASK (0x380U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_SHIFT (7U)
/*! RATE - Value from PCS for tx_rate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_SHIFT (10U)
/*! MPLLB_SEL - Value from PCS for tx_mpllb_sel */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLLB_SEL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_SHIFT (11U)
/*! MPLL_EN - Value from PCS for tx_mpll_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MPLL_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_SHIFT (12U)
/*! MSTR_MPLLB_STATE - Value from PCS for tx_master_mpllb_state */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLB_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_SHIFT (13U)
/*! MSTR_MPLLA_STATE - Value from PCS for tx_master_mplla_state */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_MSTR_MPLLA_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_SHIFT (14U)
/*! DETRX_REQ - Value from PCS for tx_detrx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_DETRX_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_IN_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT - Override values for outgoing TX controls to PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_SHIFT (0U)
/*! ACK - Override value for tx_ack */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_SHIFT (1U)
/*! DETRX_RESULT - Override value for tx_detrx_result */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_DETRX_RESULT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_SHIFT (2U)
/*! EN_CTL - Enable override values for all control outputs of this register */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_EN_CTL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_RESERVED_15_3_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_OVRD_OUT_RESERVED_15_3_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TX_PCS_OUT - Current values for outgoing TX status controls from Raw PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_SHIFT (0U)
/*! ACK - Value from Raw PCS for tx_ack */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TX_PCS_OUT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN - Override values for incoming RX controls from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_SHIFT (0U)
/*! RATE - Override value for rx_rate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_MASK (0xCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_SHIFT (2U)
/*! WIDTH - Override value for rx_width */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_WIDTH_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_MASK (0x30U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_SHIFT (4U)
/*! PSTATE - Override value for rx_pstate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_PSTATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_SHIFT (6U)
/*! LPD - Override value for rx_lpd */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_LPD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_SHIFT (7U)
/*! OVRD_EN - Enable override values for all fields in this register */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_AFE_EN_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_AFE_EN_SHIFT (8U)
/*! ADAPT_AFE_EN - Override value for rx_adapt_afe_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_AFE_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_AFE_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_DFE_EN_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_DFE_EN_SHIFT (9U)
/*! ADAPT_DFE_EN - Override value for rx_adapt_dfe_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_DFE_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_ADAPT_DFE_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1 - Override values for incoming RX controls from PCS, register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT (0U)
/*! RESET_OVRD_VAL - Override value for rx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_SHIFT (1U)
/*! RESET_OVRD_EN - Override enable for rx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESET_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT (2U)
/*! REQ_OVRD_VAL - Override value for rx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_SHIFT (3U)
/*! REQ_OVRD_EN - Override enable for rx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_1_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2 - Override values for incoming RX controls from PCS, register #2 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_MASK (0x1FFFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_SHIFT (0U)
/*! VCO_LD_VAL_OVRD - Override value for rx_vco_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_SHIFT (13U)
/*! VCO_LD_VAL_OVRD_EN - Enable override for rx_vco_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LD_VAL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_SHIFT (14U)
/*! VCO_LOWFREQ_VAL_OVRD - Override value for rx_cdr_vco_lowfreq */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_EN_SHIFT (15U)
/*! VCO_LOWFREQ_VAL_OVRD_EN - Enable override for rx_cdr_vco_lowfreq */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_2_VCO_LOWFREQ_VAL_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3 - Override values for incoming RX controls from PCS, register #3 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_VAL_MASK (0x7U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_VAL_SHIFT (0U)
/*! RX_LOS_THRSHLD_OVRD_VAL - Override value for rx_los_threshold */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_EN_SHIFT (3U)
/*! RX_LOS_THRSHLD_OVRD_EN - Enable override for rx_los_threshold */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_RX_LOS_THRSHLD_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_MASK (0x3F0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_SHIFT (4U)
/*! REF_LD_VAL_OVRD - Override value for rx_ref_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_EN_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_EN_SHIFT (10U)
/*! REF_LD_VAL_OVRD_EN - Enable override for rx_ref_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_REF_LD_VAL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_SHIFT (11U)
/*! ADAPT_REQ - Override value for rx_adapt_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_OVRD_EN_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_OVRD_EN_SHIFT (12U)
/*! ADAPT_REQ_OVRD_EN - Enable override values for rx_adapt_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_CONT_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_CONT_SHIFT (13U)
/*! ADAPT_CONT - Override value for rx_adapt_cont */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_CONT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_ADAPT_CONT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_OFFCAN_CONT_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_OFFCAN_CONT_SHIFT (14U)
/*! OFFCAN_CONT - Override value for rx_offcan_cont */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_OFFCAN_CONT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_OFFCAN_CONT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_OFFCAN_CONT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_CONT_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_CONT_OVRD_EN_SHIFT (15U)
/*! CONT_OVRD_EN - Enable override values for rx_adapt_cont and rx_offcan_cont */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_CONT_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_CONT_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_IN_3_CONT_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN - Current values for incoming RX controls from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_SHIFT (0U)
/*! REQ - Value from PCS for rx_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_MASK (0x6U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_SHIFT (1U)
/*! RATE - Value from PCS for rx_rate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_MASK (0x18U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_SHIFT (3U)
/*! WIDTH - Value from PCS for rx_width */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_WIDTH_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_MASK (0x60U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_SHIFT (5U)
/*! PSTATE - Value from PCS for rx_pstate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_PSTATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_SHIFT (7U)
/*! LPD - Value from PCS for rx_lpd */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_LPD_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_LOWFREQ_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_LOWFREQ_SHIFT (8U)
/*! CDR_VCO_LOWFREQ - Value from PCS for rx_cdr_vco_lowfreq */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_LOWFREQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_LOWFREQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_CDR_VCO_LOWFREQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_AFE_EN_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_AFE_EN_SHIFT (9U)
/*! ADAPT_AFE_EN - Value from PCS for rx_adapt_afe_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_AFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_AFE_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_AFE_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_DFE_EN_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_DFE_EN_SHIFT (10U)
/*! ADAPT_DFE_EN - Value from PCS for rx_adapt_dfe_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_DFE_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_DFE_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_DFE_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_SHIFT (11U)
/*! ADAPT_REQ - Value from PCS for rx_adapt_req */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_SHIFT (12U)
/*! ADAPT_CONT - Value from PCS for rx_adapt_cont */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_ADAPT_CONT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_SHIFT (13U)
/*! OFFCAN_CONT - Value from PCS for rx_offcan_cont */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_OFFCAN_CONT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_SHIFT (14U)
/*! RESET - Value from PCS for rx_reset */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESET_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1 - Current values for incoming RX controls from PCS, register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_MASK (0x3FU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_SHIFT (0U)
/*! REF_LD_VAL - Value from PCS for rx_ref_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_REF_LD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_1_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2 - Current values for incoming RX controls from PCS, register #2 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_MASK (0x1FFFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_SHIFT (0U)
/*! VCO_LD_VAL - Value from PCS for rx_vco_ld_val */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_VCO_LD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_2_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3 - Current values for incoming RX controls from PCS, register #3 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_MASK (0x7U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_SHIFT (0U)
/*! EQ_ATT_LVL - Value from ASIC for rx_eq_att_lvl */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_ATT_LVL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_MASK (0x78U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_SHIFT (3U)
/*! EQ_VGA1_GAIN - Value from ASIC for rx_eq_vga1_gain */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA1_GAIN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_MASK (0x780U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_SHIFT (7U)
/*! EQ_VGA2_GAIN - Value from ASIC for rx_eq_vga2_gain */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_VGA2_GAIN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_MASK (0xF800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_SHIFT (11U)
/*! EQ_CTLE_BOOST - Value from ASIC for rx_eq_ctle_boost */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_3_EQ_CTLE_BOOST_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4 - Current values for incoming RX controls from PCS, register #4 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_MASK (0x7U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_SHIFT (0U)
/*! EQ_CTLE_POLE - Value from ASIC for rx_eq_ctle_pole */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_CTLE_POLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_MASK (0x7F8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_SHIFT (3U)
/*! EQ_DFE_TAP1 - Value from ASIC for rx_eq_dfe_tap1 */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_EQ_DFE_TAP1_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_RESERVED_15_11_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_IN_4_RESERVED_15_11_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT - Override values for outgoing RX controls to PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_SHIFT (0U)
/*! ACK - Override value for rx_ack */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_SHIFT (1U)
/*! EN_CTL - Enable override values for all control outputs of this register */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_EN_CTL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_PCS_OUT - Current values for outgoing RX status controls from Raw PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_SHIFT (0U)
/*! ACK - Value from Raw PCS for rx_ack */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_PCS_OUT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK - RX Adaptation Acknowledge */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_SHIFT (0U)
/*! RX_ADAPT_ACK - RX Adaptation Acknowledge */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RX_ADAPT_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_ACK_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM - RX Adaptation Figure of Merit */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT (0U)
/*! RX_ADAPT_FOM - RX Adaptation Figure of Merit */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_ADAPT_FOM_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR - RX calculated direction for TX-pre */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_SHIFT (0U)
/*! RX_TXPRE_DIR - RX calculated direction for TX-pre */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RX_TXPRE_DIR_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPRE_DIR_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR - RX calculated direction for TX-Main */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_SHIFT (0U)
/*! RX_TXMAIN_DIR - RX calculated direction for TX-Main */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RX_TXMAIN_DIR_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXMAIN_DIR_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR - RX calculated direction for TX-Post */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_SHIFT (0U)
/*! RX_TXPOST_DIR - RX calculated direction for TX-Post */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RX_TXPOST_DIR_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_TXPOST_DIR_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_LANE_NUMBER - Current lane number */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_SHIFT (0U)
/*! LANE_NUMBER - Current lane number */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_LANE_NUMBER_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_NUMBER_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN - Override incoming values for lane_xcvr_mode */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_VAL_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_VAL_SHIFT (0U)
/*! LANE_XCVR_MODE_OVRD_VAL - Override value for lane_xcvr_mode */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_EN_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_EN_SHIFT (2U)
/*! LANE_XCVR_MODE_OVRD_EN - Enable override value for lane_xcvr_mode */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_LANE_XCVR_MODE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_RESERVED_15_3_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_OVRD_IN_RESERVED_15_3_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN - Lane transceiver mode status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_LANE_XCVR_MODE_MASK (0x3U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_LANE_XCVR_MODE_SHIFT (0U)
/*! LANE_XCVR_MODE - Lane transceiver mode Determines whether this lane is being used as Tx, Rx, or Tx/Rx */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_LANE_XCVR_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_LANE_XCVR_MODE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_LANE_XCVR_MODE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_LANE_XCVR_MODE_IN_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN - ATE Override input to control top-level inputs */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_SHIFT (0U)
/*! RX_RESET_ATE_OVRD_VAL - Override value for top-level rx_reset input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_SHIFT (1U)
/*! RX_RESET_ATE_OVRD_EN - Enable override value for rx_reset input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_RESET_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_SHIFT (2U)
/*! TX_RESET_ATE_OVRD_VAL - Override value for top-level tx_reset input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_SHIFT (3U)
/*! TX_RESET_ATE_OVRD_EN - Enable override value for tx_reset input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_RESET_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_SHIFT (4U)
/*! RX_REQ_ATE_OVRD_VAL - Override value for top-level rx_req input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_SHIFT (5U)
/*! RX_REQ_ATE_OVRD_EN - Enable override value for rx_req input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_REQ_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_SHIFT (6U)
/*! TX_REQ_ATE_OVRD_VAL - Override value for top-level tx_req input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_SHIFT (7U)
/*! TX_REQ_ATE_OVRD_EN - Enable override value for tx_req input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_TX_REQ_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_VAL_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_VAL_SHIFT (8U)
/*! RX_ADAPT_AFE_EN_OVRD_VAL - Override value for rx_adapt_afe_en input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_EN_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_EN_SHIFT (9U)
/*! RX_ADAPT_AFE_EN_OVRD_EN - Enable override value for rx_adapt_afe_en input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_AFE_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_VAL_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_VAL_SHIFT (10U)
/*! RX_ADAPT_DFE_EN_OVRD_VAL - Override value for rx_adapt_dfe_en input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_EN_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_EN_SHIFT (11U)
/*! RX_ADAPT_DFE_EN_OVRD_EN - Enable override value for rx_adapt_dfe_en input */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_RX_ADAPT_DFE_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_VALUE_MASK (0x7000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_VALUE_SHIFT (12U)
/*! REF_RANGE_ATE_OVRD_VALUE - Override value for ref_range */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_VALUE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_VALUE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_VALUE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_EN_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_EN_SHIFT (15U)
/*! REF_RANGE_ATE_OVRD_EN - Override enable for ref_range */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_ATE_OVRD_IN_REF_RANGE_ATE_OVRD_EN_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN - Override incoming values for rx_eq_delta_iq */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_VAL_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_VAL_SHIFT (0U)
/*! RX_EQ_DELTA_IQ_OVRD_VAL - Override value for rx_eq_delta_iq */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_EN_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_EN_SHIFT (4U)
/*! RX_EQ_DELTA_IQ_OVRD_EN - Enable override value for rx_eq_delta_iq */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RX_EQ_DELTA_IQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RESERVED_15_5_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_DELTA_IQ_OVRD_IN_RESERVED_15_5_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN - Override incoming values for tx/rx_term_ctrl */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_VAL_MASK (0x7U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_VAL_SHIFT (0U)
/*! RX_TERM_CTRL_OVRD_VAL - Override value for rx_term_ctrl */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_EN_SHIFT (3U)
/*! RX_TERM_CTRL_OVRD_EN - Enable override value for rx_term_ctrl */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RX_TERM_CTRL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_VAL_MASK (0x70U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_VAL_SHIFT (4U)
/*! TX_TERM_CTRL_OVRD_VAL - Override value for tx_term_ctrl */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_EN_SHIFT (7U)
/*! TX_TERM_CTRL_OVRD_EN - Enable override value for tx_term_ctrl */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_TX_TERM_CTRL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_OVRD_IN_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN - tx/rx_term_ctrl status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RX_TERM_CTRL_MASK (0x7U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RX_TERM_CTRL_SHIFT (0U)
/*! RX_TERM_CTRL - tx_term_ctrl value */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RX_TERM_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RX_TERM_CTRL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RX_TERM_CTRL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_TX_TERM_CTRL_MASK (0x38U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_TX_TERM_CTRL_SHIFT (3U)
/*! TX_TERM_CTRL - tx_term_ctrl value */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_TX_TERM_CTRL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_TX_TERM_CTRL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_TX_TERM_CTRL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RESERVED_15_6_MASK (0xFFC0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RESERVED_15_6_SHIFT (6U)
/*! RESERVED_15_6 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RESERVED_15_6(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RESERVED_15_6_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_TXRX_TERM_CTRL_IN_RESERVED_15_6_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1 - Override values for outgoing RX controls to PCS, register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_SHIFT (0U)
/*! RX_CLK_EN - Enable the outging rx_clk */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_CLK_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_VAL_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_VAL_SHIFT (1U)
/*! RX_125MHZ_CLK_OVRD_VAL - Overide value for rx_125mhz_clk_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_EN_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_EN_SHIFT (2U)
/*! RX_125MHZ_CLK_OVRD_EN - Overide enable for rx_125mhz_clk_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RX_125MHZ_CLK_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_VAL_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_VAL_SHIFT (3U)
/*! DIV16P5RX_CLK_OVRD_VAL - Overide value for div16p5_clk_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_EN_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_EN_SHIFT (4U)
/*! DIV16P5RX_CLK_OVRD_EN - Overide enable for div16p5_clk_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_DIV16P5RX_CLK_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_BYPASS_RX_ETH_CLKGEN_FSM_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_BYPASS_RX_ETH_CLKGEN_FSM_SHIFT (5U)
/*! BYPASS_RX_ETH_CLKGEN_FSM - Bypass the rx_eth_clkgen_fsm */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_BYPASS_RX_ETH_CLKGEN_FSM(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_BYPASS_RX_ETH_CLKGEN_FSM_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_BYPASS_RX_ETH_CLKGEN_FSM_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RESERVED_MASK (0xFFC0U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RESERVED_SHIFT (6U)
/*! RESERVED - Reserved */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_1_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1 - Override values for incoming RX EQ controls from PCS, register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_AFE_GAIN_OVRD_VAL_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_AFE_GAIN_OVRD_VAL_SHIFT (0U)
/*! RX_EQ_AFE_GAIN_OVRD_VAL - Override value for rx_eq_afe_gain[3:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_AFE_GAIN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_AFE_GAIN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_AFE_GAIN_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_MASK (0x70U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_SHIFT (4U)
/*! RX_EQ_ATT_LVL_OVRD_VAL - Override value for rx_eq_att_lvl[2:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_ATT_LVL_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_SHIFT (7U)
/*! RX_EQ_OVRD_EN - Enable override values for all RX EQ settings */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RX_EQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_1_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2 - Override values for incoming RX EQ controls from PCS, register #2 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_SHIFT (0U)
/*! RX_EQ_DFE_TAP1_OVRD_VAL - Override value for rx_eq_dfe_tap1[7:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_DFE_TAP1_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_MASK (0x1F00U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_SHIFT (8U)
/*! RX_EQ_CTLE_BOOST_OVRD_VAL - Override value for rx_eq_ctle_boost[4:0] */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RX_EQ_CTLE_BOOST_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_EQ_OVRD_IN_2_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2 - Override value for RX VALID/DATA_EN/DATA_EN/LANE_TX2RX_SER_LB_EN/LANE_RX2TX_PAR_LB_EN signal from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_VAL_SHIFT (0U)
/*! RX_VALID_OVRD_VAL - Override value for rx_valid */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_EN_SHIFT (1U)
/*! RX_VALID_OVRD_EN - Override enable for rx_valid */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_VALID_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_VAL_SHIFT (2U)
/*! RX_DATA_EN_OVRD_VAL - Override value for rx_data_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_EN_SHIFT (3U)
/*! RX_DATA_EN_OVRD_EN - Override enable for rx_data_en */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_VAL_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_VAL_SHIFT (4U)
/*! RX_DATA_EN_ATE_OVRD_VAL - Override value for rx_data_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_EN_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_EN_SHIFT (5U)
/*! RX_DATA_EN_ATE_OVRD_EN - Override enable for rx_data_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_DATA_EN_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_VAL_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_VAL_SHIFT (6U)
/*! RX_CDR_TRACK_EN_ATE_OVRD_VAL - Override value for rx_cdr_track_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_EN_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_EN_SHIFT (7U)
/*! RX_CDR_TRACK_EN_ATE_OVRD_EN - Override enable for rx_cdr_track_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_CDR_TRACK_EN_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_VAL_MASK (0x300U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_VAL_SHIFT (8U)
/*! RX_RATE_ATE_OVRD_VAL - Override value for rx_rate_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_EN_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_EN_SHIFT (10U)
/*! RX_RATE_ATE_OVRD_EN - Override enable for rx_rate_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RX_RATE_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL_SHIFT (11U)
/*! LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL - Override value for lane_tx2rx_ser_lb_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN_SHIFT (12U)
/*! LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN - Override enable for lane_tx2rx_ser_lb_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_TX2RX_SER_LB_EN_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL_SHIFT (13U)
/*! LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL - Override value for lane_rx2tx_par_lb_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN_SHIFT (14U)
/*! LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN - Override enable for lane_rx2tx_par_lb_en_ate */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_LANE_RX2TX_PAR_LB_EN_ATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PCS_XF_RX_OVRD_OUT_2_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FSM_OVRD_CTL - FSM override control register */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_MASK (0xFFFU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_SHIFT (0U)
/*! FSM_JMP_ADDR - The jump address used when FSM_JUMP_EN=1 The address is encoded as follows: [11:8] mem_lane, [7:5] bank, [4:0] register */
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_ADDR_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_SHIFT (12U)
/*! FSM_JMP_EN - Force the FSM to jump to FSM_JMP_ADDR in the program memory Is applied when FSM_CMD_START is pulsed. */
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_JMP_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_SHIFT (13U)
/*! FSM_CMD_START - Start executing the new command This is a self-clearing bit */
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_CMD_START_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_SHIFT (14U)
/*! FSM_OVRD_EN - Enable overriding the FSM execution of commands Must be asserted to use FSM_CMD_START and FSM_JMP_EN features */
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_FSM_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FSM_OVRD_CTL_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_MEM_ADDR_MON - Memory Address Monitor */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_SHIFT (0U)
/*! MEM_ADDR - Current value of memory address used in Lane FSM */
#define PHY_ENET_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_MEM_ADDR_MON_MEM_ADDR_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_STATUS_MON - FSM Status Monitor */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_STATE_MASK (0x1FU)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_STATE_SHIFT (0U)
/*! STATE - Current state of Lane FSM */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_SHIFT (5U)
/*! CMD_RDY - New command is ready for execution (applicable when FSM_OVRD_EN=1) */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_CMD_RDY_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_SHIFT (6U)
/*! ALU_OVFLW - Current value of ALU overflow bit */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_OVFLW_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_SHIFT (7U)
/*! ALU_RES_EQ0 - Check if ALU result register currently equals zero */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_ALU_RES_EQ0_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_SHIFT (8U)
/*! WAIT_CNT_EQ0 - Check if wait counter currently equals zero */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WAIT_CNT_EQ0_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_SHIFT (9U)
/*! WRMSK_DISABLED - Check if write mask is currently disabled (i. */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_WRMSK_DISABLED_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_SHIFT (10U)
/*! RDMSK_DISABLED - Check if read mask is currently disabled (i. */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RDMSK_DISABLED_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RESERVED_15_11_MASK (0xF800U)
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RESERVED_15_11_SHIFT (11U)
/*! RESERVED_15_11 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RESERVED_15_11(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RESERVED_15_11_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_STATUS_MON_RESERVED_15_11_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL - Status of Fast RX Start Up Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_SHIFT (0U)
/*! FAST_RX_STARTUP_CAL - Status of fast RX start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_FAST_RX_STARTUP_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_STARTUP_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_ADAPT - Status of Fast RX Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_SHIFT (0U)
/*! FAST_RX_ADAPT - Status of fast RX adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_FAST_RX_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL - Status of Fast RX AFE Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_FAST_RX_AFE_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_FAST_RX_AFE_CAL_SHIFT (0U)
/*! FAST_RX_AFE_CAL - Status of fast RX AFE DAC start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_FAST_RX_AFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_FAST_RX_AFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_FAST_RX_AFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL - Status of Fast RX DFE Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_FAST_RX_DFE_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_FAST_RX_DFE_CAL_SHIFT (0U)
/*! FAST_RX_DFE_CAL - Status of fast RX DFE slicer start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_FAST_RX_DFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_FAST_RX_DFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_FAST_RX_DFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT - Enables fast RX DFE re -adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_FAST_RX_DFE_RE_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_FAST_RX_DFE_RE_ADAPT_SHIFT (0U)
/*! FAST_RX_DFE_RE_ADAPT - Enables fast RX DFE re -adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_FAST_RX_DFE_RE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_FAST_RX_DFE_RE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_FAST_RX_DFE_RE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_RE_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL - Status of Fast RX Reference Level Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_FAST_RX_REFLVL_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_FAST_RX_REFLVL_CAL_SHIFT (0U)
/*! FAST_RX_REFLVL_CAL - Status of fast RX reference level (100mv, 125mv, 150mv) start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_FAST_RX_REFLVL_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_FAST_RX_REFLVL_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_FAST_RX_REFLVL_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_REFLVL_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL - Status of Fast RX IQ Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_FAST_RX_IQ_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_FAST_RX_IQ_CAL_SHIFT (0U)
/*! FAST_RX_IQ_CAL - Status of fast RX IQ start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_FAST_RX_IQ_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_FAST_RX_IQ_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_FAST_RX_IQ_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT - Status of Fast RX AFE Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_FAST_RX_AFE_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_FAST_RX_AFE_ADAPT_SHIFT (0U)
/*! FAST_RX_AFE_ADAPT - Status of fast RX AFE DAC start-up adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_FAST_RX_AFE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_FAST_RX_AFE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_FAST_RX_AFE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_AFE_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT - Status of Fast RX DFE Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_FAST_RX_DFE_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_FAST_RX_DFE_ADAPT_SHIFT (0U)
/*! FAST_RX_DFE_ADAPT - Status of fast RX DFE DAC start-up adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_FAST_RX_DFE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_FAST_RX_DFE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_FAST_RX_DFE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_DFE_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_SUP - Status of Fast Support block */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_SHIFT (0U)
/*! FAST_SUP - Status of fast Support block (MPLL and Rtune) */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_FAST_SUP_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_SUP_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE - Status of Fast TX Common-mode Charge-up */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_SHIFT (0U)
/*! FAST_TX_CMN_MODE - Status of fast TX Common-mode Charge-up */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_FAST_TX_CMN_MODE_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_CMN_MODE_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_TX_RXDET - Status of Fast TX detect RX */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_SHIFT (0U)
/*! FAST_TX_RXDET - Status of fast TX detect RX */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_FAST_TX_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_TX_RXDET_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_PWRUP - Status of Fast RX Power-up */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_SHIFT (0U)
/*! FAST_RX_PWRUP - Status of fast RX Power-up (LOS, VREG/AFE and DCC) */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_FAST_RX_PWRUP_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_PWRUP_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT - Status of Fast RX VCO Wait Times */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_SHIFT (0U)
/*! FAST_RX_VCO_WAIT - Status of fast RX VCO wait times */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_FAST_RX_VCO_WAIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_WAIT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL - Status of Fast RX VCO Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_SHIFT (0U)
/*! FAST_RX_VCO_CAL - Status of fast RX VCO Calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_FAST_RX_VCO_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_VCO_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS - Status of MPLL common calibration initiation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_INIT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_INIT_SHIFT (0U)
/*! CMNCAL_MPLL_INIT - Indicates whether MPLL common calibration has been started by any lane or not. */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_INIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_INIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_DONE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_DONE_SHIFT (1U)
/*! CMNCAL_MPLL_DONE - Indicates whether MPLL common calibration has been completed by any lane or not. */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_CMNCAL_MPLL_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_MPLL_STATUS_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT - Status of Fast RX Continuous Calibration/Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_SHIFT (0U)
/*! FAST_RX_CONT_CAL_ADAPT - Status of fast RX continuous calibration/adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_FAST_RX_CONT_CAL_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_CAL_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT - Status of Fast RX Continuous Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_SHIFT (0U)
/*! FAST_RX_CONT_ADAPT - Status of fast RX continuous adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_FAST_RX_CONT_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL - Status of Fast RX Continuous Data Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_FAST_RX_CONT_DATA_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_FAST_RX_CONT_DATA_CAL_SHIFT (0U)
/*! FAST_RX_CONT_DATA_CAL - Status of fast RX continuous data calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_FAST_RX_CONT_DATA_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_FAST_RX_CONT_DATA_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_FAST_RX_CONT_DATA_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_DATA_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL - Status of Fast RX Continuous Phase Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_FAST_RX_CONT_PHASE_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_FAST_RX_CONT_PHASE_CAL_SHIFT (0U)
/*! FAST_RX_CONT_PHASE_CAL - Status of fast RX continuous phase calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_FAST_RX_CONT_PHASE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_FAST_RX_CONT_PHASE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_FAST_RX_CONT_PHASE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_PHASE_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL - Status of Fast RX Continuous AFE Calibration */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_FAST_RX_CONT_AFE_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_FAST_RX_CONT_AFE_CAL_SHIFT (0U)
/*! FAST_RX_CONT_AFE_CAL - Status of fast RX continuous AFE calibration */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_FAST_RX_CONT_AFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_FAST_RX_CONT_AFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_FAST_RX_CONT_AFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CONT_AFE_CAL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT - Status of Fast RX IQ_ADAPT */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_FAST_RX_IQ_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_FAST_RX_IQ_ADAPT_SHIFT (0U)
/*! FAST_RX_IQ_ADAPT - Status of Fast RX IQ_ADAPT */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_FAST_RX_IQ_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_FAST_RX_IQ_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_FAST_RX_IQ_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_IQ_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD - Status of RX Delta addition */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RX_IQ_DELTA_ADD_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RX_IQ_DELTA_ADD_SHIFT (0U)
/*! RX_IQ_DELTA_ADD - Reserved */
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RX_IQ_DELTA_ADD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RX_IQ_DELTA_ADD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RX_IQ_DELTA_ADD_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_DELTA_ADD_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT - Enables fast RX ATT adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_FAST_RX_ATT_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_FAST_RX_ATT_ADAPT_SHIFT (0U)
/*! FAST_RX_ATT_ADAPT - Enables fast RX ATT adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_FAST_RX_ATT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_FAST_RX_ATT_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_FAST_RX_ATT_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_ATT_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT - Enables fast RX CTLE adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_FAST_RX_CTLE_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_FAST_RX_CTLE_ADAPT_SHIFT (0U)
/*! FAST_RX_CTLE_ADAPT - Enables fast RX CTLE adaptation */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_FAST_RX_CTLE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_FAST_RX_CTLE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_FAST_RX_CTLE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_FAST_RX_CTLE_ADAPT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN - CR interface timing extension enable */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_CR_REG_OP_XTND_EN_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_CR_REG_OP_XTND_EN_SHIFT (0U)
/*! CR_REG_OP_XTND_EN - CR interface timing extension enable */
#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_CR_REG_OP_XTND_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_CR_REG_OP_XTND_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_CR_REG_OP_XTND_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CR_REG_OP_XTND_EN_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG - TX Eq update flag */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_TX_EQ_UPDATE_FLAG_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_TX_EQ_UPDATE_FLAG_SHIFT (0U)
/*! TX_EQ_UPDATE_FLAG - Tx Eq update flag */
#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_TX_EQ_UPDATE_FLAG(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_TX_EQ_UPDATE_FLAG_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_TX_EQ_UPDATE_FLAG_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_TX_EQ_UPDATE_FLAG_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS - Status of RTUNE common calibration initiation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_INIT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_INIT_SHIFT (0U)
/*! CMNCAL_RCAL_INIT - Indicates whether RTUNE common calibration has been started by any lane or not. */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_INIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_INIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_DONE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_DONE_SHIFT (1U)
/*! CMNCAL_RCAL_DONE - Indicates whether RTUNE common calibration has been completed by any lane or not. */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_CMNCAL_RCAL_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_CMNCAL_RCAL_STATUS_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET - Offset value for IQ Phase Calculation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RX_IQ_PHASE_OFFSET_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RX_IQ_PHASE_OFFSET_SHIFT (0U)
/*! RX_IQ_PHASE_OFFSET - Offset value for IQ Phase Calculation */
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RX_IQ_PHASE_OFFSET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RX_IQ_PHASE_OFFSET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RX_IQ_PHASE_OFFSET_MASK)

#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_FSM_RX_IQ_PHASE_OFFSET_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST - Offset value for RX AFE ATT iDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_SHIFT (0U)
/*! AFE_ATT_IDAC_OFST - Offset value for AFE ATT iDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_AFE_ATT_IDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_IDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST - Offset value for RX AFE CTLE iDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_SHIFT (0U)
/*! AFE_CTLE_IDAC_OFST - Offset value for AFE CTLE iDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_AFE_CTLE_IDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_IDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE - Reference level for RX AFE Adaptation */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_ADAPT_REF_LVL_DAC_CODE_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_ADAPT_REF_LVL_DAC_CODE_SHIFT (0U)
/*! ADAPT_REF_LVL_DAC_CODE - Reference level for RX AFE Adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_ADAPT_REF_LVL_DAC_CODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_ADAPT_REF_LVL_DAC_CODE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_ADAPT_REF_LVL_DAC_CODE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADAPT_REF_LVL_DAC_CODE_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADAPT_FOM - Adaptation Figure of Merit (FOM) */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT (0U)
/*! RX_ADAPT_FOM - Adaptation Figure of Merit (FOM) */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RX_ADAPT_FOM(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RX_ADAPT_FOM_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RX_ADAPT_FOM_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_FOM_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST - Offset values for RX CTLE Loopback path iDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_AFE_CTLE_LBK_IDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_AFE_CTLE_LBK_IDAC_OFST_SHIFT (0U)
/*! AFE_CTLE_LBK_IDAC_OFST - Offset value for RX CTLE Loopback path iDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_AFE_CTLE_LBK_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_AFE_CTLE_LBK_IDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_AFE_CTLE_LBK_IDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_CTLE_LBK_IDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST - Offset values for RX DFE Phase Even vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_EVEN_VDAC_OFST - Offset value for DFE Phase Even vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_DFE_PHASE_EVEN_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_EVEN_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST - Offset values for RX DFE Phase Odd vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_PHASE_ODD_VDAC_OFST - Offset value for DFE Phase Odd vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_DFE_PHASE_ODD_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_PHASE_ODD_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL - DFE Even reference level */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_DFE_EVEN_REF_LVL_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_DFE_EVEN_REF_LVL_SHIFT (0U)
/*! DFE_EVEN_REF_LVL - DFE Even reference level */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_DFE_EVEN_REF_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_DFE_EVEN_REF_LVL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_DFE_EVEN_REF_LVL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_EVEN_REF_LVL_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_ODD_REF_LVL - DFE Odd reference level */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_DFE_ODD_REF_LVL_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_DFE_ODD_REF_LVL_SHIFT (0U)
/*! DFE_ODD_REF_LVL - DFE Odd reference level */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_DFE_ODD_REF_LVL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_DFE_ODD_REF_LVL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_DFE_ODD_REF_LVL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ODD_REF_LVL_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_LIN - RX Phase Adjust Linear Value */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_MASK (0x1FU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_SHIFT (0U)
/*! RX_PHSADJ_LIN - Linear value for RX phase adjust */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RX_PHSADJ_LIN_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RESERVED_15_5_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RESERVED_15_5_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_MAP - RX Phase Adjust Mapped Value */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RX_PHSADJ_MAP_MASK (0x1FU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RX_PHSADJ_MAP_SHIFT (0U)
/*! RX_PHSADJ_MAP - Mapped value for RX phase adjust */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RX_PHSADJ_MAP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RX_PHSADJ_MAP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RX_PHSADJ_MAP_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RESERVED_15_5_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_MAP_RESERVED_15_5_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset values for RX DFE Data Even High vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_EVEN_HIGH_VDAC_OFST - Offset value for DFE Data Even High vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_DFE_DATA_EVEN_HIGH_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_EVEN_HIGH_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL - Custom tx_iboost_lvl values for lfps and ss modes */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_LFPS_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_LFPS_SHIFT (0U)
/*! TX_IBOOST_LVL_LFPS - iboost value for lfps mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_LFPS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_LFPS_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_LFPS_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_SS_MASK (0xF0U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_SS_SHIFT (4U)
/*! TX_IBOOST_LVL_SS - iboost value for ss mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_SS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_SS_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_SS_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_OVRD_EN_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_OVRD_EN_SHIFT (8U)
/*! TX_IBOOST_LVL_OVRD_EN - iboost lvl ovrd en */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_TX_IBOOST_LVL_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_RESERVED_15_9_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_IBOOST_LVL_RESERVED_15_9_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST - Offset values for RX DFE Data Odd High vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT (0U)
/*! DFE_DATA_ODD_HIGH_VDAC_OFST - Offset value for DFE Data Odd High vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_DFE_DATA_ODD_HIGH_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_DATA_ODD_HIGH_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS - Override tx_eq_pre/post/main value in LFPS mode */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_MAIN_LFPS_VAL_MASK (0x3FU)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_MAIN_LFPS_VAL_SHIFT (0U)
/*! TX_EQ_MAIN_LFPS_VAL - tx_eq_main override value in LFPS mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_MAIN_LFPS_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_MAIN_LFPS_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_MAIN_LFPS_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_POST_LFPS_VAL_MASK (0x3C0U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_POST_LFPS_VAL_SHIFT (6U)
/*! TX_EQ_POST_LFPS_VAL - tx_eq_post override value in LFPS mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_POST_LFPS_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_POST_LFPS_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_POST_LFPS_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_PRE_LFPS_VAL_MASK (0x3C00U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_PRE_LFPS_VAL_SHIFT (10U)
/*! TX_EQ_PRE_LFPS_VAL - tx_eq_pre override value in LFPS mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_PRE_LFPS_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_PRE_LFPS_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_TX_EQ_PRE_LFPS_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_LFPS_OVRD_DISABLE_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_LFPS_OVRD_DISABLE_SHIFT (14U)
/*! LFPS_OVRD_DISABLE - Disable tx_eq_pre/post/main override in LFPS mode */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_LFPS_OVRD_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_LFPS_OVRD_DISABLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_LFPS_OVRD_DISABLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_CUSTOM_TX_EQ_SETTINGS_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST - Offset values for RX DFE By-Pass Even vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_EVEN_VDAC_OFST - Offset value for DFE By-Pass Even vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_DFE_BYPASS_EVEN_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_EVEN_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST - Offset values for RX DFE By-Pass Odd vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_BYPASS_ODD_VDAC_OFST - Offset value for DFE By-Pass Odd vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_DFE_BYPASS_ODD_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_BYPASS_ODD_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST - Offset values for RX DFE Error Even vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_EVEN_VDAC_OFST - Offset value for DFE Error Even vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_DFE_ERROR_EVEN_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_EVEN_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST - Offset values for RX DFE Error Odd vDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT (0U)
/*! DFE_ERROR_ODD_VDAC_OFST - Offset value for DFE Error Odd vDAC */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_DFE_ERROR_ODD_VDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_DFE_ERROR_ODD_VDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST - Value for RX IQ PHASE Adjust */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RX_IQ_PHASE_ADJUST_MASK (0x7FU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RX_IQ_PHASE_ADJUST_SHIFT (0U)
/*! RX_IQ_PHASE_ADJUST - Value for RX IQ PHASE Adjust */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RX_IQ_PHASE_ADJUST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RX_IQ_PHASE_ADJUST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RX_IQ_PHASE_ADJUST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RESERVED_15_7_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_IQ_PHASE_ADJUST_RESERVED_15_7_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE - MPLLA_COARSE_TUNE */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_SHIFT (0U)
/*! MPLLA_COARSE_TUNE - Stored coarse tune value for MPLLA */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_MPLLA_COARSE_TUNE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLLA_COARSE_TUNE_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE - MPLLB_COARSE_TUNE */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_SHIFT (0U)
/*! MPLLB_COARSE_TUNE - Stored coarse tune value for MPLLB */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_MPLLB_COARSE_TUNE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLLB_COARSE_TUNE_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_INIT_PWRUP_DONE - Initial Power-Up Done Status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_SHIFT (0U)
/*! INIT_PWRUP_DONE - Indicates whether initial power-up has completed or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_INIT_PWRUP_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_INIT_PWRUP_DONE_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_ATT - RX Adapted value of ATT */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_SHIFT (0U)
/*! ATT_ADPT_VAL - Stored RX adapted ATT value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_ATT_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_ATT_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_VGA - RX Adapted value of VGA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_MASK (0x3FFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_SHIFT (0U)
/*! VGA_ADPT_VAL - Stored RX adapted VGA value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_VGA_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_VGA_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_CTLE - RX Adapted value of CTLE */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_MASK (0x3FFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_SHIFT (0U)
/*! CTLE_BOOST_ADPT_VAL - Stored RX adapted CTLE boost value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_BOOST_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_MASK (0x1C00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_SHIFT (10U)
/*! CTLE_POLE_ADPT_VAL - Stored RX adapted CTLE pole value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_CTLE_POLE_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_CTLE_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1 - RX Adapted value of DFE TAP1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_MASK (0x1FFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP1_ADPT_VAL - Stored RX adapted DFE TAP1 value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_DFE_TAP1_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_RESERVED_15_13_MASK (0xE000U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_RESERVED_15_13_SHIFT (13U)
/*! RESERVED_15_13 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_RESERVED_15_13(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_RESERVED_15_13_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP1_RESERVED_15_13_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADAPT_DONE - RX Adaptation Done Status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_SHIFT (0U)
/*! RX_ADAPT_DONE - Indicates whether RX adaptation has completed or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RX_ADAPT_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADAPT_DONE_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_FAST_FLAGS - Fast flags for simulation only */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_STARTUP_CAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_STARTUP_CAL_SHIFT (0U)
/*! FAST_RX_STARTUP_CAL - Enables fast RX start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_STARTUP_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_STARTUP_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_STARTUP_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_ADAPT_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_ADAPT_SHIFT (1U)
/*! FAST_RX_ADAPT - Enables fast RX adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_CAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_CAL_SHIFT (2U)
/*! FAST_RX_AFE_CAL - Enables fast RX AFE DAC start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_CAL_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_CAL_SHIFT (3U)
/*! FAST_RX_DFE_CAL - Enables fast RX DFE slicer start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_RE_ADAPT_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_RE_ADAPT_SHIFT (4U)
/*! FAST_RX_DFE_RE_ADAPT - Enables fast RX DFE re -adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_RE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_RE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_RE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_REFLVL_CAL_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_REFLVL_CAL_SHIFT (5U)
/*! FAST_RX_REFLVL_CAL - Enables fast RX reference level (100mv, 125mv, 150mv) start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_REFLVL_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_REFLVL_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_REFLVL_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_IQ_CAL_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_IQ_CAL_SHIFT (6U)
/*! FAST_RX_IQ_CAL - Enables fast RX IQ start-up calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_IQ_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_IQ_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_IQ_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_ADAPT_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_ADAPT_SHIFT (7U)
/*! FAST_RX_AFE_ADAPT - Enables fast RX AFE DAC start-up adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_AFE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_ADAPT_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_ADAPT_SHIFT (8U)
/*! FAST_RX_DFE_ADAPT - Enables fast RX DFE DAC start-up adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_DFE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_SUP_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_SUP_SHIFT (9U)
/*! FAST_SUP - Enable fast Support block (MPLL and Rtune) */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_SUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_SUP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_SUP_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_CMN_MODE_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_CMN_MODE_SHIFT (10U)
/*! FAST_TX_CMN_MODE - Enable fast TX Common Mode Charge-up */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_CMN_MODE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_CMN_MODE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_CMN_MODE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_RXDET_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_RXDET_SHIFT (11U)
/*! FAST_TX_RXDET - Enable fast TX Detect RX */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_TX_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_PWRUP_MASK (0x1000U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_PWRUP_SHIFT (12U)
/*! FAST_RX_PWRUP - Enable fast RX power-up (LOS, VREG/AFE and DCC) */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_PWRUP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_PWRUP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_PWRUP_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_WAIT_MASK (0x2000U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_WAIT_SHIFT (13U)
/*! FAST_RX_VCO_WAIT - Enable fast RX VCO wait times */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_WAIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_WAIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_CAL_MASK (0x4000U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_CAL_SHIFT (14U)
/*! FAST_RX_VCO_CAL - Enable fast RX VCO Calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_FAST_RX_VCO_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_RESERVED_15_15_MASK (0x8000U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_RESERVED_15_15_SHIFT (15U)
/*! RESERVED_15_15 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_RESERVED_15_15(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_RESERVED_15_15_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_RESERVED_15_15_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2 - RX Adapted value of DFE TAP2 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_MASK (0xFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_SHIFT (0U)
/*! DFE_TAP2_ADPT_VAL - Stored RX adapted DFE TAP2 value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_DFE_TAP2_ADPT_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_RESERVED_15_12_MASK (0xF000U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_RESERVED_15_12_SHIFT (12U)
/*! RESERVED_15_12 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_RESERVED_15_12(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_RESERVED_15_12_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_ADPT_DFE_TAP2_RESERVED_15_12_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT - RX last stable iq phase of Right of the eye */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RX_PHSADJ_LIN_RIGHT_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RX_PHSADJ_LIN_RIGHT_SHIFT (0U)
/*! RX_PHSADJ_LIN_RIGHT - Stored RX iq phase right edge */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RX_PHSADJ_LIN_RIGHT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RX_PHSADJ_LIN_RIGHT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RX_PHSADJ_LIN_RIGHT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RESERVED_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RESERVED_SHIFT (8U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_RIGHT_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT - RX last stable iq phase of Left of the eye */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RX_PHSADJ_LIN_LEFT_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RX_PHSADJ_LIN_LEFT_SHIFT (0U)
/*! RX_PHSADJ_LIN_LEFT - Stored RX iq phase left edge */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RX_PHSADJ_LIN_LEFT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RX_PHSADJ_LIN_LEFT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RX_PHSADJ_LIN_LEFT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RESERVED_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RESERVED_SHIFT (8U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_LEFT_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT - RX Adapted value of PHASE IQ */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RX_PHSADJ_LIN_ADAPT_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RX_PHSADJ_LIN_ADAPT_SHIFT (0U)
/*! RX_PHSADJ_LIN_ADAPT - Stored RX adapted IQ value */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RX_PHSADJ_LIN_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RX_PHSADJ_LIN_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RX_PHSADJ_LIN_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RESERVED_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RESERVED_SHIFT (8U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_PHSADJ_LIN_ADAPT_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN - Sets values for RX SLICER CTRL EVEN signals going to ANA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_E - Value for rx_ana_slicer_ctrl_e[3:0] */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RX_ANA_SLICER_CTRL_E_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_EVEN_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD - Sets values for RX SLICER CTRL ODD signals going to ANA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK (0xFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT (0U)
/*! RX_ANA_SLICER_CTRL_O - Value for rx_ana_slicer_ctrl_o[3:0] */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RX_ANA_SLICER_CTRL_O_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RX_SLICER_CTRL_ODD_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS - MPLL Common Calibration Status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_INIT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_INIT_SHIFT (0U)
/*! LANE_CMNCAL_MPLL_INIT - Indicates whether MPLL common calibration has been started by this lane or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_INIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_INIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_DONE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_DONE_SHIFT (1U)
/*! LANE_CMNCAL_MPLL_DONE - Indicates whether MPLL common calibration has been completed by this lane or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_LANE_CMNCAL_MPLL_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_MPLL_STATUS_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_0 - Adaptation Control register #0 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_0_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_1 - Adaptation Control register #1 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_1_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_2 - Adaptation Control register #2 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_2_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_3 - Adaptation Control register #3 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_3_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_4 - Adaptation Control register #4 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_4_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_5 - Adaptation Control register #5 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_5_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_6 - Adaptation Control register #6 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_6_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_ADPT_CTL_7 - Adaptation Control register #7 */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_SHIFT (0U)
/*! VAL - Value of adaptation control */
#define PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_ADPT_CTL_7_VAL_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_MPLL_DISABLE - LANE_MPLLA/B_DISABLE override */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLA_DISABLE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLA_DISABLE_SHIFT (0U)
/*! LANE_MPLLA_DISABLE - Disable MPLLA */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLA_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLA_DISABLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLA_DISABLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLB_DISABLE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLB_DISABLE_SHIFT (1U)
/*! LANE_MPLLB_DISABLE - Disable MPLLB */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLB_DISABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLB_DISABLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_LANE_MPLLB_DISABLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_MPLL_DISABLE_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_FAST_FLAGS_2 - Fast flags for simulation only */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_CAL_ADAPT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_CAL_ADAPT_SHIFT (0U)
/*! FAST_RX_CONT_CAL_ADAPT - Enables fast RX continuous calibration/adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_CAL_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_CAL_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_CAL_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_ADAPT_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_ADAPT_SHIFT (1U)
/*! FAST_RX_CONT_ADAPT - Enables fast RX continuous adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_DATA_CAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_DATA_CAL_SHIFT (2U)
/*! FAST_RX_CONT_DATA_CAL - Enables fast RX continuous data calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_DATA_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_DATA_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_DATA_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_PHASE_CAL_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_PHASE_CAL_SHIFT (3U)
/*! FAST_RX_CONT_PHASE_CAL - Enables fast RX continuous phase calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_PHASE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_PHASE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_PHASE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_AFE_CAL_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_AFE_CAL_SHIFT (4U)
/*! FAST_RX_CONT_AFE_CAL - Enables fast RX continuous AFE calibration */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_AFE_CAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_AFE_CAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CONT_AFE_CAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_IQ_ADAPT_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_IQ_ADAPT_SHIFT (5U)
/*! FAST_RX_IQ_ADAPT - Enables fast RX IQ ADAPT */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_IQ_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_IQ_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_IQ_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RX_IQ_DELTA_ADD_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RX_IQ_DELTA_ADD_SHIFT (6U)
/*! RX_IQ_DELTA_ADD - Enables RX IQ DELTA addition */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RX_IQ_DELTA_ADD(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RX_IQ_DELTA_ADD_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RX_IQ_DELTA_ADD_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_ATT_ADAPT_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_ATT_ADAPT_SHIFT (7U)
/*! FAST_RX_ATT_ADAPT - Enables fast RX ATT adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_ATT_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_ATT_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_ATT_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CTLE_ADAPT_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CTLE_ADAPT_SHIFT (8U)
/*! FAST_RX_CTLE_ADAPT - Enables fast RX CTLE adaptation */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CTLE_ADAPT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CTLE_ADAPT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_FAST_RX_CTLE_ADAPT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_GEN2_250US_WAIT_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_GEN2_250US_WAIT_SHIFT (9U)
/*! SKIP_GEN2_250US_WAIT - Skip 250us wait for USB Gen2. */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_GEN2_250US_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_GEN2_250US_WAIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_GEN2_250US_WAIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_250US_WAIT_MASK (0x400U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_250US_WAIT_SHIFT (10U)
/*! SKIP_250US_WAIT - SKIP_250US_WAIT */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_250US_WAIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_250US_WAIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_250US_WAIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_IQ_STEP_SKIP_MASK (0x800U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_IQ_STEP_SKIP_SHIFT (11U)
/*! SKIP_IQ_STEP_SKIP - Skip the IQ step skip option */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_IQ_STEP_SKIP(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_IQ_STEP_SKIP_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_SKIP_IQ_STEP_SKIP_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RSVD_FAST_FLAGS_MASK (0xF000U)
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RSVD_FAST_FLAGS_SHIFT (12U)
/*! RSVD_FAST_FLAGS - Reserved fast flags */
#define PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RSVD_FAST_FLAGS(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RSVD_FAST_FLAGS_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_FAST_FLAGS_2_RSVD_FAST_FLAGS_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS - RTUNE Common Calibration Status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_INIT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_INIT_SHIFT (0U)
/*! LANE_CMNCAL_RCAL_INIT - Indicates whether RTUNE common calibration has been started by this lane or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_INIT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_INIT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_INIT_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_DONE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_DONE_SHIFT (1U)
/*! LANE_CMNCAL_RCAL_DONE - Indicates whether RTUNE common calibration has been completed by this lane or not. */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_DONE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_DONE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_LANE_CMNCAL_RCAL_DONE_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_LANE_CMNCAL_RCAL_STATUS_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_TXRX_OVRD_IN - Override values for incoming AON TX/RX controls from PCS */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_SHIFT (0U)
/*! RX_DISABLE_OVRD_VAL - Override value for rx_disable */
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_SHIFT (1U)
/*! RX_DISABLE_OVRD_EN - Override enable for rx_disable */
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RX_DISABLE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_SHIFT (2U)
/*! TX_DISABLE_OVRD_VAL - Override value for tx_disable */
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_SHIFT (3U)
/*! TX_DISABLE_OVRD_EN - Override enable for tx_disable */
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_TX_DISABLE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_TXRX_OVRD_IN_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST - Offset value for RX AFE ATT_2 iDAC */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_AFE_ATT_2_IDAC_OFST_MASK (0xFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_AFE_ATT_2_IDAC_OFST_SHIFT (0U)
/*! AFE_ATT_2_IDAC_OFST - Offset value for AFE ATT_2 iDAC when cc is 1 in ana typec projects */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_AFE_ATT_2_IDAC_OFST(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_AFE_ATT_2_IDAC_OFST_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_AFE_ATT_2_IDAC_OFST_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_RESERVED_15_8_MASK (0xFF00U)
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_RESERVED_15_8_SHIFT (8U)
/*! RESERVED_15_8 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_RESERVED_15_8(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_RESERVED_15_8_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_AFE_ATT_2_IDAC_OFST_RESERVED_15_8_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN - Override incoming values for rxtx_cc */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_VAL_SHIFT (0U)
/*! RXTX_CC_OVRD_VAL - Override value for rxtx_cc */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_EN_SHIFT (1U)
/*! RXTX_CC_OVRD_EN - Enable override value for rxtx_cc */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RXTX_CC_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_OVRD_IN_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN - Incoming value of CC status from TCA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_rxtx_cc_in_i_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_rxtx_cc_in_i_SHIFT (0U)
/*! rxtx_cc_in_i - Value from TCA of cc */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_rxtx_cc_in_i(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_rxtx_cc_in_i_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_rxtx_cc_in_i_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_IN_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT - Current values for outgoing CC status to PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_rxtx_cc_out_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_rxtx_cc_out_SHIFT (0U)
/*! rxtx_cc_out - Value to PMA of cc */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_rxtx_cc_out(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_rxtx_cc_out_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_rxtx_cc_out_MASK)

#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RXTX_CC_STATUS_OUT_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RESERVED_REG_1 - Reserved for future use */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_1_RESERVED_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_1_RESERVED_SHIFT (0U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_1_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_1_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_1_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RESERVED_REG_2 - Reserved for future use */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_2_RESERVED_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_2_RESERVED_SHIFT (0U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_2_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_2_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_2_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RESERVED_REG_3 - Reserved for future use */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_3_RESERVED_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_3_RESERVED_SHIFT (0U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_3_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_3_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_3_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_AON_RESERVED_REG_4 - Reserved for future use */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_4_RESERVED_MASK (0xFFFFU)
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_4_RESERVED_SHIFT (0U)
/*! RESERVED - Reserved bits */
#define PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_4_RESERVED(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_4_RESERVED_SHIFT)) & PHY_ENET_RAWLANE0_DIG_AON_RESERVED_REG_4_RESERVED_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ - Reset routine request */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_SHIFT (0U)
/*! RESET_RTN_REQ - Reset routine request */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESET_RTN_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RESET_RTN_REQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ - Rx reset interrupt */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_SHIFT (0U)
/*! RX_RESET - Rx reset interrupt */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RX_RESET_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ - Rx request interrupt */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_SHIFT (0U)
/*! RX_REQ - Rx request interrupt */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RX_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ - Rx rate change interrupt request */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_SHIFT (0U)
/*! RX_RATE_IRQ - Rx rate change interrupt request */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RX_RATE_IRQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ - Rx pstate change interrupt request */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_SHIFT (0U)
/*! RX_PSTATE_IRQ - Rx pstate change interrupt request */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RX_PSTATE_IRQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ - Rx adaptation request interrupt */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_SHIFT (0U)
/*! RX_ADAPT_REQ_IRQ - Rx adaptation request interrupt */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RX_ADAPT_REQ_IRQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ - Rx adaptation disable interrupt */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_SHIFT (0U)
/*! RX_ADAPT_DIS_IRQ - Rx adaptation disable interrupt */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RX_ADAPT_DIS_IRQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR - RX reset interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_SHIFT (0U)
/*! RX_RESET_IRQ_CLR - RX reset interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RX_RESET_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RESET_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR - RX request interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_SHIFT (0U)
/*! RX_REQ_IRQ_CLR - RX request interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RX_REQ_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_REQ_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR - RX rate change interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_SHIFT (0U)
/*! RX_RATE_IRQ_CLR - RX rate change interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RX_RATE_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_RATE_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR - RX pstate change interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_SHIFT (0U)
/*! RX_PSTATE_IRQ_CLR - RX pstate change interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RX_PSTATE_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_PSTATE_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR - RX adaptation request interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_SHIFT (0U)
/*! RX_ADAPT_REQ_IRQ_CLR - RX adaptation request interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RX_ADAPT_REQ_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_REQ_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR - RX adaptation disable interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_SHIFT (0U)
/*! RX_ADAPT_DIS_IRQ_CLR - RX adaptation disable interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RX_ADAPT_DIS_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_RX_ADAPT_DIS_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_IRQ_MASK - Interrupt Mask */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_SHIFT (0U)
/*! RX_REQ_IRQ_MSK - Mask for Rx request interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_REQ_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_SHIFT (1U)
/*! RX_RATE_IRQ_MSK - Mask for Rx rate change interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RATE_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_SHIFT (2U)
/*! RX_PSTATE_IRQ_MSK - Mask for Rx pstate change interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_PSTATE_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_SHIFT (3U)
/*! RX_ADAPT_REQ_IRQ_MSK - Mask for Rx adaptation request interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_REQ_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_MASK (0x10U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_SHIFT (4U)
/*! RX_ADAPT_DIS_IRQ_MSK - Mask for Rx adaptation disable interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_ADAPT_DIS_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_MASK (0x20U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_SHIFT (5U)
/*! RX_RESET_IRQ_MSK - Mask for Rx reset interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RX_RESET_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_LANE_XCVR_MODE_IRQ_MSK_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_LANE_XCVR_MODE_IRQ_MSK_SHIFT (6U)
/*! LANE_XCVR_MODE_IRQ_MSK - Mask for lane_xcvr_mode interrupt (0 = cannot interrupt) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_LANE_XCVR_MODE_IRQ_MSK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_LANE_XCVR_MODE_IRQ_MSK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_LANE_XCVR_MODE_IRQ_MSK_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RESERVED_15_7_MASK (0xFF80U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RESERVED_15_7_SHIFT (7U)
/*! RESERVED_15_7 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RESERVED_15_7(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RESERVED_15_7_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_IRQ_MASK_RESERVED_15_7_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ - Lane transceiver mode interrupt */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_LANE_XCVR_MODE_IRQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_LANE_XCVR_MODE_IRQ_SHIFT (0U)
/*! LANE_XCVR_MODE_IRQ - Lane transceiver mode interrupt */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_LANE_XCVR_MODE_IRQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_LANE_XCVR_MODE_IRQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_LANE_XCVR_MODE_IRQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR - Lane transceiver mode interrupt clear */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_LANE_XCVR_MODE_IRQ_CLR_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_LANE_XCVR_MODE_IRQ_CLR_SHIFT (0U)
/*! LANE_XCVR_MODE_IRQ_CLR - Lane transceiver mode interrupt clear (self-clearing) */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_LANE_XCVR_MODE_IRQ_CLR(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_LANE_XCVR_MODE_IRQ_CLR_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_LANE_XCVR_MODE_IRQ_CLR_MASK)

#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_IRQ_CTL_LANE_XCVR_MODE_IRQ_CLR_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN - Override values for incoming LANE controls */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_SHIFT (0U)
/*! LANE_MPLLA_EN_IN - Override value for lane_mplla_en_in */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLA_EN_IN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_SHIFT (1U)
/*! LANE_MPLLB_EN_IN - Override value for lane_mpllb_en_in */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_MPLLB_EN_IN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_SHIFT (2U)
/*! LANE_OVRD_EN - Override enable for signals in this register */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_LANE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_RESERVED_15_3_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_IN_RESERVED_15_3_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT - Override values for outgoing LANE controls */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_SHIFT (0U)
/*! LANE_MPLLA_EN_OUT - Override value for lane_mplla_en_out */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLA_EN_OUT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_SHIFT (1U)
/*! LANE_MPLLB_EN_OUT - Override value for lane_mpllb_en_out */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_MPLLB_EN_OUT_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_SHIFT (2U)
/*! LANE_OVRD_EN - Override enable for signals in this register */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_LANE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_RESERVED_15_3_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_OVRD_OUT_RESERVED_15_3_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN - Override values for incoming SUP controls from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_SHIFT (0U)
/*! MPLLA_STATE - Override value for mplla_state */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLA_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_SHIFT (1U)
/*! MPLLB_STATE - Override value for mpllb_state */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_MPLLB_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_SHIFT (2U)
/*! SUP_STATE_OVRD_EN - Override enable for signals in this register */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_SUP_STATE_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_RESERVED_15_3_MASK (0xFFF8U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_RESERVED_15_3_SHIFT (3U)
/*! RESERVED_15_3 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_RESERVED_15_3(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_RESERVED_15_3_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_OVRD_IN_RESERVED_15_3_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_PMA_IN - Current values for incoming MPLL status controls from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_SHIFT (0U)
/*! MPLLA_STATE - Value from PMA for mplla_state */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLA_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_SHIFT (1U)
/*! MPLLB_STATE - Value from PMA for mpllb_state */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_MPLLB_STATE_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT - Override values for outgoing TX controls to PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_SHIFT (0U)
/*! TX_REQ_OVRD_VAL - Override value for tx_req */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_SHIFT (1U)
/*! TX_REQ_OVRD_EN - Override enable for tx_req */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_SHIFT (2U)
/*! TX_RESET_OVRD_VAL - Override value for tx_reset */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_SHIFT (3U)
/*! TX_RESET_OVRD_EN - Override enable for tx_reset */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_TX_RESET_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_OVRD_OUT_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_TX_PMA_IN - Current values for coming TX status controls from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_SHIFT (0U)
/*! ACK - Value from PMA for tx_ack */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_TX_PMA_IN_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT - Override values for outgoing RX controls to PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_SHIFT (0U)
/*! RX_REQ_OVRD_VAL - Override value for rx_req */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_SHIFT (1U)
/*! RX_REQ_OVRD_EN - Override enable for rx_req */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_REQ_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_MASK (0x4U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_SHIFT (2U)
/*! RX_RESET_OVRD_VAL - Override value for rx_reset */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_VAL_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_MASK (0x8U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_SHIFT (3U)
/*! RX_RESET_OVRD_EN - Override enable for rx_reset */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RX_RESET_OVRD_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RESERVED_15_4_MASK (0xFFF0U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RESERVED_15_4_SHIFT (4U)
/*! RESERVED_15_4 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RESERVED_15_4(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RESERVED_15_4_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_OVRD_OUT_RESERVED_15_4_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_RX_PMA_IN - Current values for coming RX status controls from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_SHIFT (0U)
/*! ACK - Value from PMA for rx_ack */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_RX_PMA_IN_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL - Lane Rtune Controls */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_SHIFT (0U)
/*! LANE_RTUNE_REQ - Lane value for rtune_req */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_LANE_RTUNE_REQ_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_LANE_RTUNE_CTL_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1 - Current values for incoming RTUNE status controls from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RTUNE_ACK_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RTUNE_ACK_SHIFT (0U)
/*! RTUNE_ACK - Value from PMA for rtune_ack */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RTUNE_ACK(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RTUNE_ACK_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RTUNE_ACK_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_IN_1_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID - Current value of RX valid from PMA */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RX_VALID_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RX_VALID_SHIFT (0U)
/*! RX_VALID - Value of RX_VALID */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RX_VALID(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RX_VALID_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RX_VALID_MASK)

#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_PMA_XF_SUP_PMA_RX_VALID_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_TX_CTL_TX_FSM_CTL - TX FSM Control */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_WAIT_MPLL_OFF_TIME_MASK (0x3FU)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_WAIT_MPLL_OFF_TIME_SHIFT (0U)
/*! TX_WAIT_MPLL_OFF_TIME - Number of ref_range cycles to wait for MPLL to turn off (When entering P2). */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_WAIT_MPLL_OFF_TIME(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_WAIT_MPLL_OFF_TIME_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_WAIT_MPLL_OFF_TIME_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_MASK (0x40U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_SHIFT (6U)
/*! TX_P2_ALLOW_RXDET - If asserted, then rxdet request is allowed in P2 */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P2_ALLOW_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_MASK (0x80U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_SHIFT (7U)
/*! TX_P1_ALLOW_RXDET - If asserted, then rxdet request is allowed in P1 */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P1_ALLOW_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_MASK (0x100U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_SHIFT (8U)
/*! TX_P0S_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0S */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0S_ALLOW_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_MASK (0x200U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_SHIFT (9U)
/*! TX_P0_ALLOW_RXDET - If asserted, then rxdet request is allowed in P0 */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_TX_P0_ALLOW_RXDET_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_RESERVED_15_10_MASK (0xFC00U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_RESERVED_15_10_SHIFT (10U)
/*! RESERVED_15_10 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_RESERVED_15_10(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_RESERVED_15_10_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_FSM_CTL_RESERVED_15_10_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_TX_CTL_TX_CLK_CTL - Select clock to act as TX input clock */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_SHIFT (0U)
/*! TX_CLK_EN - Enable the tx_clk to pma tx lane TX_CLK_EN must be deasserted when switching TX_CLK_SEL */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_EN_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_MASK (0x1EU)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_SHIFT (1U)
/*! TX_CLK_SEL - Select clock source for tx_pma_clk */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_TX_CLK_SEL_MASK)

#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_RESERVED_15_5_MASK (0xFFE0U)
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_RESERVED_15_5_SHIFT (5U)
/*! RESERVED_15_5 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_RESERVED_15_5(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_RESERVED_15_5_SHIFT)) & PHY_ENET_RAWLANE0_DIG_TX_CTL_TX_CLK_CTL_RESERVED_15_5_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_FSM_CTL - RX FSM control register */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_SHIFT (0U)
/*! EN_RX_CTL_FSM - EN_RX_CTL_FSM */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_EN_RX_CTL_FSM_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_MASK (0x2U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_SHIFT (1U)
/*! RATE_CHG_IN_P1 - When asserted, then a rate change in P0/P0s will be sequenced such that the RX
 *    is put in P1, the rate change is applied, and then the RX is returned to P0/P0s
 */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RATE_CHG_IN_P1_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RESERVED_15_2_MASK (0xFFFCU)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RESERVED_15_2_SHIFT (2U)
/*! RESERVED_15_2 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RESERVED_15_2(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RESERVED_15_2_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_FSM_CTL_RESERVED_15_2_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL - RX LOS Mask Control */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_MASK (0x1FFU)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_SHIFT (0U)
/*! RX_LOS_MASK_CNT - Number of cycles (ref_range_clk) to mask out the rx_los output, from the time the los is powered-on. */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RX_LOS_MASK_CNT_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RESERVED_15_9_MASK (0xFE00U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RESERVED_15_9_SHIFT (9U)
/*! RESERVED_15_9 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RESERVED_15_9(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RESERVED_15_9_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_LOS_MASK_CTL_RESERVED_15_9_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL - RX Data Enable Override Control */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_MASK (0x1FU)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_SHIFT (0U)
/*! RX_DATA_EN_OVRD_CNT - Number of ref_range cycles to override rx_data_en to 1. */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_RX_DATA_EN_OVRD_CNT_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_MASK (0xFFE0U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_SHIFT (5U)
/*! INT_REF_TRCK_CNT - Number of ref_range cycles to wait for integral reference tracking to settle. */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_RX_DATA_EN_OVRD_CTL_INT_REF_TRCK_CNT_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS - RX continuous offset cancellation status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_SHIFT (0U)
/*! ENABLE - Enable status for rx continous offset cancellation */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_ENABLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_OFFCAN_CONT_STATUS_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS - RX continuous adaptation status */
/*! @{ */

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_MASK (0x1U)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_SHIFT (0U)
/*! ENABLE - Enable status for rx continous adaptation */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_ENABLE_MASK)

#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_RESERVED_15_1_MASK (0xFFFEU)
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_RESERVED_15_1_SHIFT (1U)
/*! RESERVED_15_1 - Reserved for Future use */
#define PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_RESERVED_15_1(x) (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_RESERVED_15_1_SHIFT)) & PHY_ENET_RAWLANE0_DIG_RX_CTL_ADAPT_CONT_STATUS_RESERVED_15_1_MASK)
/*! @} */

/*! @name RAWMEM_DIG_ROM_CMN_B_R - Common Read Only Memory */
/*! @{ */

#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_DATA_MASK (0xFFFFU)
#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_DATA_SHIFT (0U)
/*! DATA - Memory Data */
#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_DATA(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_DATA_SHIFT)) & PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_DATA_MASK)
/*! @} */

/* The count of PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_COUNT    (16U)

/* The count of PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_COUNT2   (8U)

/* The count of PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_ROM_CMN_B_R_COUNT3   (32U)

/*! @name RAWMEM_DIG_RAM_CMN_B_R - Common Random Access Memory */
/*! @{ */

#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_DATA_MASK (0xFFFFU)
#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_DATA_SHIFT (0U)
/*! DATA - Memory Data */
#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_DATA(x)  (((uint16_t)(((uint16_t)(x)) << PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_DATA_SHIFT)) & PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_DATA_MASK)
/*! @} */

/* The count of PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_COUNT    (16U)

/* The count of PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_COUNT2   (8U)

/* The count of PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R */
#define PHY_ENET_RAWMEM_DIG_RAM_CMN_B_R_COUNT3   (32U)


/*!
 * @}
 */ /* end of group PHY_ENET_Register_Masks */


/*!
 * @}
 */ /* end of group PHY_ENET_Peripheral_Access_Layer */


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


#endif  /* PERI_PHY_ENET_H_ */

